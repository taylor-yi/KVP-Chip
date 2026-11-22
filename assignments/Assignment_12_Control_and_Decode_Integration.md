# KVP-1 Hardware Design Project
## Paged KV Cache and FlashAttention Accelerator
## Assignment #12: Control Path and Decode Integration

Milestone M5 (decode integration) | Tracks A+B | Target: Friday, Feb 26, 11:59 PM PST

---

### Contents

1. Introduction
2. Setting Up Your Environment
3. Controlling a Decode Step
   - 3.1 The Decode Sequence
   - 3.2 config_regs
   - 3.3 decode_scheduler
   - 3.4 attention_controller
   - 3.5 kvp1_top
4. Assignment #12
   - 4.1 Files
   - 4.2 Your Task
   - 4.3 Testing Your Implementation
   - 4.4 Submission

---

## 1 Introduction

You now have a verified paged KV cache (Assignment 4), a tile loader (Assignment 7) and a verified attention core (Assignment 11). This assignment connects them with the control path so that one command performs a full decode step: append the new token's K and V to the cache, then run one query against the entire cached context, tile by tile, and return the normalized output.

This is the first point where both partners' halves run together. Expect the bugs to be at the boundaries. The contracts you wrote in `docs/kv_cache.md` and `docs/tile_buffers.md` are what you debug against.

## 2 Setting Up Your Environment

Pull `a11-attention-core`. Both partners should review the top-level port list in Section 3.5 before either writes RTL. Write a Python end-to-end decode driver, `model/kvp1_model.py`, that combines `KVCacheModel` and the hardware-emulating attention model: `decode(q, k_new, v_new) -> output`, keeping cache state between calls.

## 3 Controlling a Decode Step

### 3.1 The Decode Sequence

From spec Section 11, specialized to this design:

1. Host writes config (mode = DECODE, mask mode), stages `q`, `k_new`, `v_new`, and asserts `start`.
2. Controller latches config and validates it. Invalid config: `error`, no state changes.
3. Append `k_new`, `v_new` through `kv_cache_top`. If the append fails (cache full), `error`.
4. Load `q` into `q_tile_buffer` with `q_rows = 1`, `q_pos_base = seq_len - 1` (the new token's position). Assert `core_start`.
5. For each KV tile from `decode_scheduler`: issue a cache read for `(start, count)`, start the tile loader with `(count, first, last)`. The core consumes the tile and releases it.
6. After the core's `core_done`, assert `done`. Output is in `output_buffer` for the host.

Mask mode for decode is `CAUSAL`. Since the query is the newest token, every cached token is at or before it, so causal masking masks nothing; it is still the right mode, and the testbench should confirm padding of the final partial tile does the work.

### 3.2 config_regs

Simple register file, written by the host interface, latched into a shadow copy on `start` so the host can change registers during an operation without affecting it (REQ-CTRL-01).

| Register | Width | Legal values | Notes |
|---|---|---|---|
| `MODE` | 2 | DECODE, PREFILL, SEQ_RESET | PREFILL used in Assignment 13; SEQ_RESET drives `seq_clear` |
| `MASK_MODE` | 2 | NONE, CAUSAL, PADDING | |
| `HEAD_DIM` | 8 | 16 only | Anything else: error. Present so the check exists (REQ-CTRL-05) |
| `Q_LEN` | 9 | 1 (decode), 1..256 (prefill) | |
| `TILE_BR`, `TILE_BC`, `PAGE_SIZE` | 8 | 4, 16, 16 | Read-only, report the compile-time values |
| `STATUS` | | busy, done, error, error code | Read-only |
| `SEQ_LEN` | 9 | | Read-only, from the cache |
| `CYCLES` | 32 | | Read-only, cycles from accepted start to done |

Define an error code enumeration (`ERR_NONE`, `ERR_BAD_MODE`, `ERR_BAD_DIM`, `ERR_CACHE_FULL`, `ERR_CACHE_READ`, `ERR_TILE`, `ERR_CORE`, `ERR_BUSY`) and document it.

### 3.3 decode_scheduler

Given context length `L` (the cache's `seq_len` after the append), generate KV ranges in order:

```
for t in 0 .. ceil(L / Bc) - 1:
    start = t * Bc
    count = min(Bc, L - start)
    first = (t == 0), last = (start + count == L)
```

Interface: `sched_start` with `L`, then a valid/ready handshake producing `(start, count, first, last)` one tile at a time, and `sched_done`. `L = 0` produces no tiles and an immediate `sched_done` with an `empty` flag (cannot happen in decode after a successful append, but the scheduler must handle it, REQ-CTRL-04 / spec Section 14).

### 3.4 attention_controller

The global FSM. Suggested states:

```
IDLE -> LATCH -> CHECK -> APPEND -> LOAD_Q -> TILE_ISSUE -> TILE_WAIT -> (loop) -> WAIT_CORE -> DONE
                    \-> ERROR                \-> ERROR (cache, tile or core error)
```

Requirements:

- REQ-CTRL-01: a legal `start` launches exactly one operation and raises `busy`. `start` while busy is ignored and sets `ERR_BUSY` in a sticky status bit (without disturbing the running operation).
- REQ-CTRL-02: `done` only after the output buffer is written.
- REQ-CTRL-03: synchronous `rst_n` during an operation returns every module to idle. The cache contents and `seq_len` reset too. Document this: reset means "start over," not "abort the step."
- Error from any submodule ends the operation with `error` and the right code. After an error mid-traversal, the cache is still consistent (the append either committed or did not) and the next `start` works. Test that.

### 3.5 kvp1_top

Top level for simulation. The FPGA wrapper in Assignment 14 sits on top of this.

| Port group | Signals |
|---|---|
| Clock/reset | `clk`, `rst_n` |
| Register access | `reg_wr_en`, `reg_addr`, `reg_wdata[31:0]`, `reg_rd_addr`, `reg_rdata[31:0]` |
| Command | `start`, `busy`, `done`, `error` |
| Q staging | `q_in_valid`, `q_in_ready`, `q_in_row`, `q_in_data[255:0]` |
| K/V staging | `kv_in_valid`, `kv_in_ready`, `k_in[255:0]`, `v_in[255:0]` (decode: one token; prefill: a stream) |
| Output | `out_rd_row`, `out_rd_elem`, `out_rdata[31:0]`, `out_row_invalid`, `out_valid`, `out_ack` |

## 4 Assignment #12

### 4.1 Files

**rtl/config_regs.sv**, **rtl/decode_scheduler.sv**, **rtl/attention_controller.sv**, **rtl/kvp1_top.sv**.

**model/kvp1_model.py**: End-to-end model.

**tb/decode_scheduler_tb.sv**, **tb/kvp1_decode_tb.sv**.

**scripts/gen_decode_vectors.py**: A decode run of N steps: per-step `q`, `k_new`, `v_new`, expected output.

**docs/top_level.md**: Register map, error codes, port list, FSM, reset semantics.

### 4.2 Your Task

Build the control path and run multi-step decode end to end. The testbench acts as the host: it writes registers, stages tensors, pulses `start`, waits for `done`, reads the output, compares it bit-exactly to `kvp1_model.py`, and logs `CYCLES` for each step.

### 4.3 Testing Your Implementation

| Test | Description | Must check |
|---|---|---|
| 1 | Scheduler | `L` = 0, 1, 15, 16, 17, 40, 255, 256: correct ranges and flags |
| 2 | First decode step | Context 1, single partial tile |
| 3 | 40 decode steps | Context grows 1 to 40, crossing pages at 16 and 32 (spec M5 exit: context crossing multiple pages) |
| 4 | Fill the cache | 256 steps; all outputs match |
| 5 | Cache full | 257th step: `error`, `ERR_CACHE_FULL`, no output change, `seq_len = 256` |
| 6 | Bad config | `HEAD_DIM = 32`, bad `MODE`: `error`, nothing appended |
| 7 | Start while busy | Second `start` mid-step: ignored, `ERR_BUSY` sticky, first step completes correctly |
| 8 | Error recovery | Force a cache read error (bad page via reservation trick or a test hook), then run a good step |
| 9 | Reset mid-step | Reset during tile traversal, then a fresh 5-step run matches a fresh model |
| 10 | SEQ_RESET | Run 20 steps, SEQ_RESET, run 10 more; matches model with `clear()` |
| 11 | Config shadowing | Change `MASK_MODE` register mid-step; the running step is unaffected |
| 12 | Latency log | `CYCLES` per step recorded to a CSV for Test 4 |

### 4.4 Submission

To receive full credit you must:

1. Pass all twelve tests, with every output bit-exact against `kvp1_model.py`.
2. Commit the CSV from Test 12 and a one-paragraph explanation in `docs/top_level.md` of how cycles grow with context length (it should be roughly linear, about one tile's worth of cycles per 16 tokens).
3. Both partners sign off on `docs/top_level.md`.

Tag the commit `a12-decode`. This closes milestone M5.
