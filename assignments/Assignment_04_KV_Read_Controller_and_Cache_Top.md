# KVP-1 Hardware Design Project
## Paged KV Cache and FlashAttention Accelerator
## Assignment #4: KV Read Controller and KV Cache Integration

Milestone M2 exit (KV cache complete) | Track A | Target: Friday, Dec 18, 11:59 PM PST

---

### Contents

1. Introduction
2. Setting Up Your Environment
3. Reading Logical Ranges
   - 3.1 The Read Transaction
   - 3.2 kv_read_ctrl Interface
   - 3.3 kv_cache_top
   - 3.4 Forcing Non-Contiguous Pages
4. Assignment #4
   - 4.1 Files
   - 4.2 Your Task
   - 4.3 Testing Your Implementation
   - 4.4 Submission

---

## 1 Introduction

The attention engine never sees physical addresses. It asks the cache for "tokens 16 through 31" and expects K/V vectors back in logical order, one per beat, with a marker on the last one. The read controller makes that happen by walking the logical range, translating each token through the page table and issuing reads to the memory interface.

This assignment also wraps everything built so far into `kv_cache_top`, the subsystem the rest of the accelerator will talk to. Passing this assignment is the M2 exit criterion from the spec: the paged cache matches the Python model, including page crossing and exhaustion.

## 2 Setting Up Your Environment

Pull `a3-append`. Reuse `tb/kv_append_harness.sv` as a starting point, but `kv_cache_top` replaces it as the DUT in this assignment's testbench.

## 3 Reading Logical Ranges

### 3.1 The Read Transaction

Given `start`, `count` and the current `seq_len`:

1. If `count == 0`: pulse `rd_done` with no data beats. This is the defined behavior for an empty context (spec Section 18, REQ-SM-06 starts here).
2. If `start + count > seq_len`: pulse `rd_error`, emit no beats.
3. For `t = start` to `start + count - 1`, in order:
   - Translate `t` through address gen and page table.
   - If the page is not valid: pulse `rd_error`, stop, emit no further beats (REQ-KV-05). Beats already sent stay sent; the error tells the consumer to discard the transaction.
   - Issue a read to `kv_mem_interface`, wait for `resp_valid`, forward K and V on the output stream.
4. Assert `kv_last` on the beat for `start + count - 1`, then pulse `rd_done`.

Ordering across page boundaries (REQ-KV-03) falls out of walking logical tokens in order. The test in Section 4.3 must use scattered physical pages so a bug here cannot hide.

### 3.2 kv_read_ctrl Interface

| Port | Dir | Width | Description |
|---|---|---|---|
| **Command** | | | |
| `rd_cmd_valid` | in | 1 | |
| `rd_cmd_ready` | out | 1 | High only in IDLE |
| `rd_start` | in | `TOK_W` | First logical token |
| `rd_count` | in | `TOK_W+1` | Number of tokens, 0 to 256 |
| `seq_len` | in | `TOK_W+1` | From the append controller |
| `rd_done`, `rd_error` | out | 1 | One-cycle pulses, exactly one per command |
| **Translation** | | | |
| `ag_token_idx` | out | `TOK_W` | |
| `ag_addr`, `ag_addr_valid` | in | | |
| **Memory** | | | |
| `mem_req_valid` | out | 1 | `mem_req_write` tied 0 |
| `mem_req_addr` | out | `ADDR_W` | |
| `mem_req_ready` | in | 1 | |
| `mem_resp_valid` | in | 1 | |
| `mem_resp_data_k`, `mem_resp_data_v` | in | `WORD_W` | |
| `mem_resp_ready` | out | 1 | Driven from `kv_ready` |
| **Output stream** | | | |
| `kv_valid` | out | 1 | |
| `kv_ready` | in | 1 | Consumer backpressure |
| `kv_k`, `kv_v` | out | `WORD_W` | |
| `kv_token` | out | `TOK_W` | Logical index of this beat. Downstream uses it for masking. |
| `kv_last` | out | 1 | Last beat of the command |

The simplest correct design passes `mem_resp_valid` straight through as `kv_valid` and `kv_ready` straight back as `mem_resp_ready`. `kv_mem_interface` already holds its response data stable while stalled, so no skid buffer is needed. One read in flight at a time means one token per two cycles. That is fine for the core demo. Pipelining is an Extension.

Watch the timing of `kv_token` and `kv_last`: they describe the response currently on the bus, not the request you are about to issue. Keep a separate "response token" register.

### 3.3 kv_cache_top

`kv_cache_top` instantiates `page_allocator`, `page_table`, `kv_address_gen`, `kv_append_ctrl`, `kv_read_ctrl` and `kv_mem_interface`. Only one operation runs at a time, so a simple mux selects which controller drives the address gen and memory request ports.

| Port group | Description |
|---|---|
| `clk`, `rst_n` | |
| Append command | `append_valid/ready`, `append_k/v`, passes through to `kv_append_ctrl` |
| Read command | `rd_cmd_valid/ready`, `rd_start`, `rd_count`, passes through to `kv_read_ctrl` |
| Output stream | `kv_valid/ready`, `kv_k/v`, `kv_token`, `kv_last` |
| Status | `busy`, `done` (OR of the two done pulses), `error` (OR of the two error pulses), `seq_len` |
| Control | `seq_clear` |
| Test hooks | `reserve_en`, `reserve_page` (Section 3.4) |

Arbitration rule: an append command and a read command are never accepted in the same cycle. If both are valid in IDLE, append wins. Document this. Both `*_ready` signals go low while either controller is busy.

### 3.4 Forcing Non-Contiguous Pages

With one sequence and lowest-first allocation, pages come out 0, 1, 2, ... and logical page `i` maps to physical page `i`. A broken page table could pass every test. To prevent that, add a reservation port to the allocator:

- `reserve_en`, `reserve_page`: mark a page used without returning it. A reservation of an already-used page is ignored (no error).

The testbench reserves a pattern of pages after reset, for example 0, 2, 5, 6, 11, before any append. The cache then lands logical pages on physical 1, 3, 4, 7, 8, ... The model's `reserve()` helper from Assignment 2 produces matching expectations. Reserved pages also let you test allocator exhaustion before `seq_len` hits 256.

Rerun the Assignment 1 testbench after adding the port.

## 4 Assignment #4

### 4.1 Files

**rtl/kv_read_ctrl.sv**, **rtl/kv_cache_top.sv**, updated **rtl/page_allocator.sv** (reserve port).

**tb/kv_cache_top_tb.sv**: Self-checking testbench, all reads checked through the output stream (no back-door memory reads).

**scripts/gen_kv_cache_vectors.py**: Scenario generator. Writes the reservation pattern, append data, read commands and expected beats.

**docs/kv_cache.md**: Subsystem contract. Command semantics, stream semantics, error table, arbitration rule, cycle counts per token for append and read. This is the doc the attention-side partner will integrate against, so write it for them.

### 4.2 Your Task

Implement the read controller and the top. Build a testbench with a stream monitor that collects every beat into a queue, then compares the queue to the model's `read()` result when `rd_done` or `rd_error` fires.

Drive `kv_ready` with a random pattern (for example 70% high) in every read test, and assert that `kv_k`, `kv_v`, `kv_token` and `kv_last` stay stable while `kv_valid && !kv_ready`.

### 4.3 Testing Your Implementation

These map to the spec's minimum KV cache test matrix (Section 27).

| Test | Description | Must check |
|---|---|---|
| 1 | Append first token, read one token | 1 beat, `kv_last`, data matches |
| 2 | Append to same page, read full range | 10 tokens in order |
| 3 | Append across page boundary, read full range | 40 tokens, scattered physical pages via reservations |
| 4 | Read subrange crossing a boundary | `rd_start = 13, rd_count = 7` |
| 5 | Read count 0 | `rd_done`, zero beats, no error |
| 6 | Read past length | `rd_error`, zero beats |
| 7 | Exhaustion | Reserve 13 pages, append until failure at token 48; `append_error`; read 0 to 47 still correct (REQ-KV-04) |
| 8 | Full capacity | No reservations, 256 appends, read all 256 |
| 9 | Interleaved | Append 5, read all, append 20, read all, repeat to 100 tokens (prefill-then-decode access pattern) |
| 10 | Backpressure | Every read test runs with random `kv_ready`; stability assertion never fires |
| 11 | Random scenario | 500 random append/read commands vs model, seed printed |

All data comparisons are bit-exact (REQ-KV-07).

### 4.4 Submission

To receive full credit you must:

1. Pass all eleven tests with three different seeds.
2. Have the attention-side partner read `docs/kv_cache.md` and write two questions it did not answer. Answer them in the doc.
3. Record in the doc: cycles per token for read (expected about 2), cycles for a same-page append and a new-page append.

Tag the commit `a4-kv-cache`. This closes milestone M2.
