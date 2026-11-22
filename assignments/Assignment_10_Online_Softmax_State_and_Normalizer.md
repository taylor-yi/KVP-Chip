# KVP-1 Hardware Design Project
## Paged KV Cache and FlashAttention Accelerator
## Assignment #10: Online Softmax State and Output Normalizer

Milestone M4 (RTL attention core) | Track B | Target: Friday, Feb 12, 11:59 PM PST

---

### Contents

1. Introduction
2. Setting Up Your Environment
3. Running State Across Tiles
   - 3.1 The Update, Per Row
   - 3.2 online_softmax_state
   - 3.3 output_normalizer
4. Assignment #10
   - 4.1 Files
   - 4.2 Your Task
   - 4.3 Testing Your Implementation
   - 4.4 Submission

---

## 1 Introduction

This is the block that makes the design FlashAttention instead of ordinary attention. Each query row keeps a running maximum `m` and running denominator `l` across every KV tile it sees. When a new tile arrives with a larger maximum, the old sums were computed against the wrong reference and must be scaled down by `alpha = exp(m - m')` before the new tile's contribution (scaled by `beta`) is merged in. Nothing larger than one score tile is ever stored.

This assignment builds the `m`/`l` state and the rescale-factor logic, plus the final normalizer that divides the output by `l`. The running output vector `O` and the PV product live in Assignment 11; this module tells that one how to merge.

## 2 Setting Up Your Environment

Pull `a9-block-stats`. Extend `gen_attention_vectors.py` to dump, for each tile step of each row: `m`, `l`, `alpha`, `beta`, the update mode, and at the end `1/l` and the normalized output, all from the hardware-emulating model.

## 3 Running State Across Tiles

### 3.1 The Update, Per Row

Each row has registers `m` (FP32), `l` (FP32) and `started` (1 bit), cleared at the start of each query tile. When a block's statistics `m_b`, `l_b`, `blk_row_valid` arrive:

| Case | Condition | New state | Emitted to accumulator |
|---|---|---|---|
| SKIP | `!blk_row_valid` | unchanged | mode SKIP (leave O alone) |
| FIRST | `blk_row_valid && !started` | `m = m_b`, `l = l_b`, `started = 1` | mode FIRST: `O = O_b` |
| MERGE, old max wins | `started && m >= m_b` | `m' = m`, `beta = exp(m_b - m)`, `l = l + beta*l_b` | mode MERGE, `alpha = 1.0`, `beta` |
| MERGE, new max wins | `started && m < m_b` | `m' = m_b`, `alpha = exp(m - m_b)`, `l = alpha*l + l_b` | mode MERGE, `alpha`, `beta = 1.0` |

The two MERGE rows are the spec's equations with the observation from Assignment 5 applied: one factor is always exactly 1, so each row needs only one exponential per block. Note that multiplying by 1.0 is exact, so this matches the full two-exponential equations bit for bit as long as `exp_approx(0) = 1.0` exactly (which Assignment 9 required).

FIRST avoids `exp(-inf - -inf)` entirely: there is no -inf anywhere in the design (REQ-SM-02).

The order of operations in MERGE is fixed and documented in `docs/numerics.md` (REQ-SM-03): compute the exponent argument with `fp32_add`, `exp_approx`, then `fp32_mul`, then `fp32_add`. The Python model must do exactly the same sequence.

A useful invariant: for any started row, `l >= 1`. The block maximum always contributes `P = 1` to `l_b`, and whichever of `l` or `l_b` belongs to the winning maximum is multiplied by exactly 1. So `l` is always in `[1, 256]` at normalization. Add an assertion for it; it catches a whole class of ordering bugs.

### 3.2 online_softmax_state

| Port | Dir | Description |
|---|---|---|
| `st_clear` | in | Start of a query tile: clear `started` for all rows |
| `blk_valid` | in | Block statistics ready (from `bs_done`) |
| `m_b[Br]`, `l_b[Br]`, `blk_row_valid[Br]` | in | From `softmax_block_stats` |
| `upd_valid` | out | Pulse when rescale factors are ready for all rows |
| `upd_mode[Br]` | out | SKIP / FIRST / MERGE |
| `alpha[Br]`, `beta[Br]` | out | FP32, held until next `blk_valid` |
| `upd_ack` | in | Accumulator has consumed them |
| `l_out[Br]`, `row_started[Br]` | out | For the normalizer |

One shared `exp_approx` instance time-multiplexed over the 4 rows is fine (4 exponentials per tile). Or share the instance with `softmax_block_stats`, since they never run at the same time. Record which in the doc and the resource difference if you measure it.

Rows beyond `q_rows` stay unstarted and always SKIP (REQ-SM-01: independent state per row).

### 3.3 output_normalizer

After the last KV tile for a query tile, each started row's output is `O / l`. Unstarted rows (empty context or fully masked) produce zeros and `row_invalid = 1` (REQ-SM-06).

Suggested design: compute `inv_l = 1 / l` once per row with a small sequential divider that returns the correctly rounded FP32 reciprocal, then 16 `fp32_mul` operations `out[e] = O[e] * inv_l`.

- Correct rounding makes the Python model trivial: `np.float32(1.0) / np.float32(l)`.
- Because `l` is in `[1, 256]`, the reciprocal never overflows, underflows or hits zero. Special cases reduce to "row not started."
- A restoring divider on the 24-bit mantissa takes about 26 cycles per row. That is negligible next to the KV traversal.
- `O * (1/l)` is not bit-identical to `O / l`. The Python model must use the same form as the hardware.

Alternatives (Newton-Raphson from a LUT seed, a floating-point IP core) are acceptable if specified as precisely; record the choice in `docs/decisions.md`. Spec REQ-SM-07 makes optimizing this an Extension.

| Port | Dir | Description |
|---|---|---|
| `norm_start`, `norm_busy`, `norm_done` | | |
| `l_in[Br]`, `row_started[Br]`, `num_rows` | in | |
| O read port | out/in | From `output_accumulator` (Assignment 11): read row `r` element `e` |
| Output write port | out | To `output_buffer` (Assignment 11): row, element, FP32 value |
| `row_invalid[Br]` | out | |

## 4 Assignment #10

### 4.1 Files

**rtl/online_softmax_state.sv**, **rtl/fp32_recip.sv**, **rtl/output_normalizer.sv**.

**tb/online_softmax_state_tb.sv**: Drives sequences of block statistics directly from vectors (no QK engine needed).

**tb/output_normalizer_tb.sv**: Uses a stub O memory loaded from vectors.

**tb/fp32_recip_tb.sv**: Exhaustive-ish over `[1, 256]`.

**docs/online_softmax.md**: Update table, operation order, invariants, latency per block, normalizer design.

### 4.2 Your Task

Build the state module, the reciprocal and the normalizer, and verify them bit-exact against the hardware-emulating model, one tile step at a time. When a mismatch appears, the per-step dumps from Section 2 tell you which step and which row diverged first; print them in your error messages.

### 4.3 Testing Your Implementation

| Test | Description | Must check |
|---|---|---|
| 1 | Single block | Every valid row takes FIRST; `m`, `l` copied |
| 2 | Increasing maxima | Each block's max larger than the last: always "new max wins", `beta = 1.0` |
| 3 | Decreasing maxima | Always "old max wins", `alpha = 1.0` |
| 4 | Equal maxima | `m == m_b`: old max wins, `beta = exp(0) = 1.0` exactly |
| 5 | Leading masked blocks | Row SKIPs for two blocks, then FIRST on block 3 |
| 6 | Trailing masked blocks | Causal row: valid early, SKIP later; state unchanged by SKIPs |
| 7 | Never started | Row always SKIP: normalizer outputs zeros, `row_invalid = 1` |
| 8 | Mixed rows | 4 rows with different patterns in the same tile; rows independent |
| 9 | `l` invariant | Assertion `l >= 1` holds over 500 random sequences |
| 10 | Reciprocal | 1,000,000 values in `[1, 256]` plus powers of two, bit-exact vs `np.float32` |
| 11 | Normalizer | Random O and l, bit-exact |
| 12 | Clear between tiles | Two query tiles back-to-back; no state leaks |
| 13 | Long context | 16 blocks (256 tokens) for one row, bit-exact at every step |

### 4.4 Submission

To receive full credit you must:

1. Pass all thirteen tests bit-exact.
2. Commit `docs/online_softmax.md`.
3. Show the per-step mismatch report working by deliberately breaking one operation (for example swapping alpha and beta), pasting the report in the PR, then reverting.

Tag the commit `a10-online-softmax`.
