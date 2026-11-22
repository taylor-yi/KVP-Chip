# KVP-1 Hardware Design Project
## Paged KV Cache and FlashAttention Accelerator
## Assignment #13: Prefill Scheduler and Prefill Integration

Milestone M6 (prefill integration) | Tracks A+B | Target: Friday, Mar 5, 11:59 PM PST

---

### Contents

1. Introduction
2. Setting Up Your Environment
3. Prefill
   - 3.1 The Prefill Sequence
   - 3.2 prefill_scheduler
   - 3.3 Controller Changes
   - 3.4 Host Handshakes
4. Assignment #13
   - 4.1 Files
   - 4.2 Your Task
   - 4.3 Testing Your Implementation
   - 4.4 Submission

---

## 1 Introduction

Decode processes one query against the cache. Prefill processes the whole prompt: every prompt token is a query, every prompt token's K/V goes into the cache, and causal masking makes each query attend only to tokens at or before its own position. In this design prefill is a two-level loop: query tiles of up to 4 rows on the outside, KV tiles of up to 16 tokens on the inside, with the online softmax state reset at the start of each query tile.

When this works, the design can do the full sequence the spec asks for: a prefill followed by decode steps that continue from the cache the prefill populated.

## 2 Setting Up Your Environment

Pull `a12-decode`. Add `prefill(Q, K, V)` to `model/kvp1_model.py`. It appends all prompt K/V to the model cache, then computes causal attention with the tiled hardware-emulating model, returning `Lp` output rows.

## 3 Prefill

### 3.1 The Prefill Sequence

With prompt length `Lp` (`Q_LEN` register, 1 to 256), and the sequence starting empty or continuing from earlier tokens (`base = seq_len` before the prefill):

1. **Ingest.** Host streams `Lp` K/V pairs on the `kv_in` port. The controller appends each one to the cache. Per the decision in Assignment 7, all attention K/V then comes back out of the cache.
2. **Query tiles.** For `qt = 0 .. ceil(Lp / 4) - 1`:
   - `q_start = qt * 4`, `q_rows = min(4, Lp - q_start)`, `q_pos_base = base + q_start`.
   - Host streams `q_rows` query rows into `q_tile_buffer`.
   - `core_start` (clears softmax state).
   - KV tiles over the causal bound: context `L_eff = q_pos_base + q_rows` (the last query's position plus one). Tiles past `L_eff` would be fully masked for every row, so skip them.
   - After `core_done`, the host reads the 4 (or fewer) output rows and acknowledges.
3. `done` after the last query tile's output is acknowledged.

Two things to check in your head before coding: the final query tile is partial when `Lp % 4 != 0` (padding mask on rows), and the last KV tile of a query tile is usually partial and also partially causal-masked (both masks at once). Both are tested below.

### 3.2 prefill_scheduler

Generates the outer loop and, for each query tile, drives the inner KV loop. Reuse `decode_scheduler` as the inner loop with `L = L_eff`. Do not copy its logic.

| Port | Dir | Description |
|---|---|---|
| `ps_start`, `Lp`, `base` | in | |
| `qtile_valid`, `qtile_ready` | out/in | Handshake per query tile |
| `q_start`, `q_rows`, `q_pos_base`, `L_eff`, `qtile_last` | out | Per query tile |
| `ps_done` | out | |

Add a compile-time parameter `CAUSAL_SKIP` (default 1). With 0, `L_eff` is the full context and every query tile visits every KV tile. Outputs must be identical either way (the extra tiles SKIP every row); only the cycle count changes. You will use this in Assignment 15 to show how much the causal bound saves.

### 3.3 Controller Changes

Add a PREFILL path to `attention_controller`:

```
IDLE -> LATCH -> CHECK -> INGEST (loop Lp appends)
     -> QTILE_NEXT -> LOAD_Q -> TILE_ISSUE/TILE_WAIT (inner loop) -> WAIT_CORE
     -> WAIT_HOST_ACK -> QTILE_NEXT ... -> DONE
```

New checks for `CHECK`:

- `Q_LEN = 0` or `Q_LEN > 256`: `ERR_BAD_DIM`.
- `base + Q_LEN > 256`: `ERR_CACHE_FULL`, checked **before** ingesting anything, so a too-long prompt leaves the cache untouched.
- `MASK_MODE` must be CAUSAL for prefill in the core configuration. NONE is allowed as a test mode (bidirectional attention over the prompt); document what it means.

### 3.4 Host Handshakes

- `kv_in_valid/ready`: one beat per prompt token during INGEST.
- `q_in_valid/ready` with `q_in_row`: rows for the current query tile, only while in LOAD_Q.
- `out_valid` / `out_ack`: the controller waits in WAIT_HOST_ACK. The output buffer is not overwritten until acknowledged.

The testbench host must randomly delay each of these to prove the controller tolerates a slow host.

## 4 Assignment #13

### 4.1 Files

**rtl/prefill_scheduler.sv**, updated **rtl/attention_controller.sv** and **rtl/kvp1_top.sv**.

**tb/prefill_scheduler_tb.sv**, **tb/kvp1_prefill_tb.sv**.

**scripts/gen_prefill_vectors.py**: Prompt Q/K/V, expected `Lp` output rows, and optionally decode steps after it.

**docs/top_level.md**: Updated with the PREFILL sequence and handshakes.

### 4.2 Your Task

Add prefill, then run prefill followed by decode. All outputs are compared bit-exactly against `kvp1_model.py` and also against the FP64 conventional model with the documented tolerance.

### 4.3 Testing Your Implementation

Covers the spec's tiling and end-to-end test matrix rows that need multiple queries.

| Test | Description | Must check |
|---|---|---|
| 1 | Scheduler | `Lp` = 1, 3, 4, 5, 16, 17, 40, 256: query tiles, `q_rows`, `L_eff` |
| 2 | Prompt shorter than a tile | `Lp = 3`: one partial query tile, one partial KV tile |
| 3 | Exact multiples | `Lp = 16` |
| 4 | Non-multiples | `Lp = 37`: partial final query tile (1 row) and partial KV tiles |
| 5 | Mixed masks | Query tile at positions 16..19 against KV tile 16..31: padding and causal together |
| 6 | Long prompt | `Lp = 200`, crosses many pages |
| 7 | Prefill then decode | `Lp = 30`, then 20 decode steps: every output matches (spec M6 exit plus the spec's "prefill then decode" end-to-end case) |
| 8 | Decode then prefill | 10 decode steps, then a 12-token prefill continuing at `base = 10` |
| 9 | Too long | `base = 250`, `Lp = 10`: `ERR_CACHE_FULL`, cache unchanged |
| 10 | Slow host | Random delays on all three handshakes |
| 11 | CAUSAL_SKIP = 0 | Rerun Tests 4 and 6; identical outputs, more cycles (log both) |
| 12 | Random | 30 random prompts with random lengths, seed printed |

### 4.4 Submission

To receive full credit you must:

1. Pass all twelve tests bit-exact.
2. Log cycles for Tests 4 and 6 with `CAUSAL_SKIP` = 1 and 0.
3. Update `docs/top_level.md`.

Tag the commit `a13-prefill`. This closes milestone M6 and completes the functional design.
