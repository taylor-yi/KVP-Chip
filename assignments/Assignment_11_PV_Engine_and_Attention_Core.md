# KVP-1 Hardware Design Project
## Paged KV Cache and FlashAttention Accelerator
## Assignment #11: PV Engine, Output Accumulation and Attention Core Integration

Milestone M4 exit (RTL attention core) | Track B | Target: Friday, Feb 19, 11:59 PM PST

---

### Contents

1. Introduction
2. Setting Up Your Environment
3. The Second Matrix Product and the Core
   - 3.1 pv_matmul_adapter
   - 3.2 output_rescale and output_accumulator
   - 3.3 output_buffer
   - 3.4 attention_core and Its Sequencer
4. Assignment #11
   - 4.1 Files
   - 4.2 Your Task
   - 4.3 Testing Your Implementation
   - 4.4 Submission

---

## 1 Introduction

The last arithmetic piece of attention is the weighted sum of values: `O_b = P_b V_b`, followed by the merge `O' = alpha*O + beta*O_b` using the factors from Assignment 10. Once that exists, every block of the attention datapath is built, and this assignment connects them into one `attention_core` that takes a query tile and a sequence of KV tiles and produces normalized output rows.

Passing this assignment is the spec's M4 exit: the RTL attention core matches the hardware-emulating Python model.

## 2 Setting Up Your Environment

Pull `a10-online-softmax`. The core testbench feeds the tile buffers directly from vectors. The KV cache is not connected until Assignment 12; keeping it out means a failure here is a datapath failure.

## 3 The Second Matrix Product and the Core

### 3.1 pv_matmul_adapter

| Operand | Shape | Source |
|---|---|---|
| P | `Br x Bc` = 4 x 16 | `p_buffer` (format from Assignment 5) |
| V | `Bc x d` = 16 x 16, BF16 | `kv_tile_buffer.rd_v` |
| O_b | `Br x d` = 4 x 16, FP32 | to the accumulator |

This is the same shape as QK^T (4 x 16 times 16 x 16), but the operand access is transposed. For QK^T the reduction runs along `d`, which is inside one 256-bit K word. For PV the reduction runs along `c`, across 16 different V words, picking the same lane `e` from each. The adapter hides this (spec Section 24).

Decide whether QK and PV share one array instance (time-multiplexed, the controller arbitrates) or each get their own. Sharing saves DSPs; separate instances allow overlap later. Start shared unless the FPGA has room to spare, and record the decision.

Invalid columns of P are exactly 0 (Assignment 9), so they contribute nothing. Still feed zeros for V slots beyond `tile_count` so no stale NaN or inf can produce `0 * inf = NaN` (REQ-PV-01: same mask semantics as the denominator).

| Port | Dir | Description |
|---|---|---|
| `pv_start`, `pv_busy`, `pv_done` | | |
| `p_buffer` read, KV buffer read (`rd_idx`, `rd_v`, `rd_slot_valid`) | out/in | |
| Array ports (or array request/grant if shared) | | |
| `ob_wr_en`, `ob_row`, `ob_col`, `ob_data` | out | One O_b element at a time, or a row at a time |

### 3.2 output_rescale and output_accumulator

`output_accumulator` holds `O[Br][d]` in FP32 registers (4 x 16 x 32 = 2 Kbit). `output_rescale` applies the update, per row, using the mode from `online_softmax_state`:

| Mode | Update for every element `e` |
|---|---|
| SKIP | unchanged |
| FIRST | `O[r][e] = O_b[r][e]` |
| MERGE | `O[r][e] = fp32_add(fp32_mul(alpha[r], O[r][e]), fp32_mul(beta[r], O_b[r][e]))` |

Operation order is fixed (REQ-PV-02, REQ-SM-03) and matches the Python model. You can apply it as O_b elements arrive from the adapter or after the whole O_b is ready; the arithmetic is the same either way. Make sure alpha/beta for this tile are ready before the first merge.

`st_clear` (start of a query tile) clears nothing in O; FIRST overwrites it. Still, clear O on `st_clear` in simulation builds (or always, if cheap) so a missing FIRST shows up as zeros rather than stale data from the previous tile (REQ-PV-03).

The read port is used by `output_normalizer`.

### 3.3 output_buffer

Holds the normalized output for the current query tile: `Br` rows of 16 FP32 values, `row_invalid` bits, and `result_valid`. Provide a host-side read port (row, element) and a `result_ack` that clears `result_valid`. Optionally also present each row packed as 16 BF16 values in one 256-bit word, using the same lane order as K/V, which makes the output easy to compare and easy to feed into a next layer someday.

### 3.4 attention_core and Its Sequencer

`attention_core` instantiates `qk_engine`, `score_buffer`, `softmax_block_stats`, `p_buffer`, `online_softmax_state`, `pv_matmul_adapter`, `output_accumulator`, `output_normalizer`, `output_buffer`, the shared array, and a small FSM `attention_core_ctrl`.

Per KV tile:

```
WAIT_TILE -> QK -> BLOCK_STATS -> STATE_UPDATE -> PV_AND_MERGE -> RELEASE
              (if tile_last) -> NORMALIZE -> DONE
```

STATE_UPDATE and PV can overlap (PV needs only P, the state update needs only `m_b`, `l_b`); the merge needs both. Start sequential. Measure cycles per tile; Assignment 15 asks for it.

| Port | Dir | Description |
|---|---|---|
| `core_start` | in | Query tile is loaded in `q_tile_buffer`; clear softmax state |
| `mask_mode` | in | |
| `tile_valid`, `tile_last`, `tile_count`, ... | in | From `kv_tile_buffer` |
| `tile_release` | out | To `kv_tile_buffer` |
| Q / KV buffer read ports | out/in | |
| `core_busy`, `core_done` | out | `core_done` after the output buffer is written |
| `core_error` | out | Protocol violations (tile arrives while not waiting, and so on) |
| Output buffer host read port | | |

Run the spec's REQ-CTRL style checks here in miniature: a second `core_start` while busy is ignored and flagged.

## 4 Assignment #11

### 4.1 Files

**rtl/pv_matmul_adapter.sv**, **rtl/output_rescale.sv**, **rtl/output_accumulator.sv**, **rtl/output_buffer.sv**, **rtl/attention_core_ctrl.sv**, **rtl/attention_core.sv**, and an arbiter for the shared array if you share it.

**tb/pv_matmul_adapter_tb.sv**, **tb/output_accumulator_tb.sv**, **tb/attention_core_tb.sv**.

**scripts/gen_core_vectors.py**: Named scenarios, each a query tile plus its KV tiles plus expected per-step state and final output.

**docs/attention_core.md**: Block diagram, sequencer states, cycle counts per tile and for normalization, array sharing decision.

### 4.2 Your Task

Build the PV path and accumulator, verify them alone, then integrate the core. The core test compares against the hardware-emulating model bit-exactly, and also against the FP64 conventional model with the tolerance from `docs/numerics.md`, reporting max abs, max rel and RMS error for each scenario.

### 4.3 Testing Your Implementation

**Units:**

| Test | Description |
|---|---|
| PV non-symmetric | V chosen so `P V` and `P V^T` differ everywhere |
| PV partial tile | `tile_count = 7`, stale NaN in slots 7..15 does not leak |
| Accumulator modes | SKIP / FIRST / MERGE with constructed alpha, beta |

**Core** (spec Section 27 softmax and end-to-end rows, minus the cache):

| Test | Scenario |
|---|---|
| 1 | Small deterministic tensor: 1 query, 1 tile, hand-checkable values |
| 2 | Decode shape: 1 query, contexts of 1, 15, 16, 17, 40 tokens |
| 3 | Prefill shape: 4 queries, 3 tiles, no mask |
| 4 | Causal: 4 queries at positions 28..31 over 32 tokens |
| 5 | Equal scores, separated scores, negative scores |
| 6 | All-masked row: zeros and `row_invalid` |
| 7 | Leading fully masked tile |
| 8 | Max context: 1 query over 256 tokens (16 tiles) |
| 9 | Back-to-back query tiles without reset |
| 10 | 100 random scenarios, seed printed |

### 4.4 Submission

To receive full credit you must:

1. Pass all unit and core tests, bit-exact against the hardware-emulating model.
2. Report max abs / max rel / RMS error against the FP64 model for every core scenario in `docs/attention_core.md`, all within the documented tolerance.
3. Record cycles per KV tile and per normalization.

Tag the commit `a11-attention-core`. This closes milestone M4.
