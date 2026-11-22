# KVP-1 Hardware Design Project
## Paged KV Cache and FlashAttention Accelerator
## Assignment #9: Row Max, Exponential and Block Statistics

Milestone M4 (RTL attention core) | Track B | Target: Friday, Feb 5, 11:59 PM PST

---

### Contents

1. Introduction
2. Setting Up Your Environment
3. Block Statistics
   - 3.1 What This Stage Computes
   - 3.2 row_max_reduce
   - 3.3 exp_approx
   - 3.4 softmax_block_stats and p_buffer
4. Assignment #9
   - 4.1 Files
   - 4.2 Your Task
   - 4.3 Testing Your Implementation
   - 4.4 Submission

---

## 1 Introduction

Given a score tile, the online softmax needs three things per query row before it can update its running state: the block maximum `m_b`, the unnormalized probabilities `P_b = exp(S_b - m_b)`, and their sum `l_b`. This assignment builds the blocks that produce them, including the exponential, which is the one genuinely approximate operation in the datapath.

The spec is explicit that you should not optimize the exponential before the online state machine works. So the goal here is an exponential that is simple, fully specified, bit-exact against Python, and accurate enough. Making it small is Assignment 15's problem.

## 2 Setting Up Your Environment

Pull `a8-qk-engine`. You will replace the placeholder `exp_approx` in `model/attention_hw.py` with a bit-exact model of your hardware exponential, then regenerate the tolerance study from Assignment 5 with it.

## 3 Block Statistics

### 3.1 What This Stage Computes

For each query row `r` with at least one valid score:

```
m_b[r]    = max over valid c of S[r][c]
P[r][c]   = valid ? exp(S[r][c] - m_b[r]) : 0
l_b[r]    = sum over c of P[r][c]     (fixed order: c = 0, 1, ..., 15)
```

Rows with no valid score produce `row_any_valid = 0` and their outputs are don't-care; the state logic in Assignment 10 skips them.

Every exponential argument here is `<= 0` (a score minus its row max). The rescale factors in Assignment 10 are also exponentials of non-positive numbers. So `exp_approx` only needs to handle `x <= 0`, and its output is always in `[0, 1]`.

### 3.2 row_max_reduce

Input: one score row (16 FP32 values + 16 valid bits) from `score_buffer`. Output: `m_b` and `any_valid`.

Build it as a tree of `fp32_max` from Assignment 6 with invalid inputs replaced by a "loses every compare" token (a separate valid bit traveling with each tree node is cleaner than substituting -inf). Four levels for 16 inputs. Combinational is fine at first; if it becomes the critical path, add a register between levels and document the latency.

Define the NaN behavior: a valid NaN score should not happen if inputs are finite, but if it does, say what `row_max_reduce` returns and test it.

### 3.3 exp_approx

Suggested algorithm (you may choose another if you specify it equally precisely):

1. Input `x` FP32, `x <= 0`. Assert in simulation if `x > 0`.
2. `y = x * log2(e)` using `fp32_mul` with a fixed constant.
3. If `y < -126`, return `+0.0` (result would be subnormal under the flush policy).
4. Convert `y` to two's complement fixed point with 8 integer bits and `F` fraction bits. `n` = the integer part (arithmetic shift gives floor for negatives), `f` = the fraction bits, so `y = n + f/2^F` with `0 <= f < 2^F`.
5. `2^(f/2^F)` from a lookup table indexed by the top `T` bits of `f`, with linear interpolation on the remaining bits (or no interpolation if `T` is large enough). Table entries are mantissas for values in `[1, 2)`.
6. Assemble FP32: sign 0, exponent `127 + n`, mantissa from step 5.

Requirements:

- `exp_approx(0.0)` must return exactly `1.0`. The row maximum always produces `P = 1`, and the alpha/beta trick in Assignment 10 depends on an exact 1.
- Monotonic non-increasing as `x` decreases.
- Choose `F`, `T` and interpolation so the maximum relative error over `[-87, 0]` is below a target you state (for example `2^-12`), and measure it in Python by sweeping every FP32 value in a dense sample of the range.
- Generate the LUT contents from Python into a `.hex` file loaded with `$readmemh` in an `initial` block (fine for FPGA ROM inference), so the RTL and model cannot drift apart.

Write `docs/exp_approx.md`: algorithm, parameters, input range, output format, measured max and RMS relative error, LUT size, latency.

### 3.4 softmax_block_stats and p_buffer

Processes one score tile row by row:

1. Read row `r` from `score_buffer`.
2. Get `m_b[r]` from `row_max_reduce`.
3. For `c = 0..15`: compute `d = fp32_add(S[r][c], -m_b[r])`, `p = valid ? exp_approx(d) : 0`, write `p` into `p_buffer[r][c]`, accumulate `l = fp32_add(l, p)` starting from `l = 0`.
4. Output `m_b[r]`, `l_b[r]`, `row_any_valid[r]`.

One `exp_approx` instance, time-multiplexed across the 16 columns, is the expected first design: about 16 cycles per row, 64 per full tile. Parallel exponentials are an Extension.

The accumulation order of `l` must match the Python model (sequential, `c = 0` first). If you build an adder tree instead, change the model to match and note it in `docs/numerics.md`.

`p_buffer` stores `Br x Bc` probabilities. Store them in the format decided in Assignment 5 (BF16 if PV reuses the BF16 array, FP32 if PV uses a dedicated FP32 datapath). If BF16, convert with `f32_to_bf16` and keep `l_b` computed from the **same rounded values** that go into PV, or record that it is computed from the FP32 values. REQ-PV-01 requires the PV product and the denominator to use the same probabilities; pick the rounded version unless you have a reason not to.

| Port (softmax_block_stats) | Dir | Description |
|---|---|---|
| `bs_start`, `bs_busy`, `bs_done` | in/out/out | Process the whole tile |
| `num_rows` | in | `q_rows` |
| `score_buffer` read port | out/in | Row read |
| `p_buffer` write port | out | |
| `m_b[Br]`, `l_b[Br]`, `blk_row_valid[Br]` | out | Held stable from `bs_done` until next `bs_start` |

## 4 Assignment #9

### 4.1 Files

**rtl/row_max_reduce.sv**, **rtl/exp_approx.sv**, **rtl/softmax_block_stats.sv**, **rtl/p_buffer.sv**.

**model/exp_model.py**: Bit-exact model of `exp_approx`, LUT generator, error sweep.

**scripts/gen_exp_lut.py**: Writes `rtl/data/exp_lut.hex`.

**tb/exp_approx_tb.sv**, **tb/row_max_reduce_tb.sv**, **tb/softmax_block_stats_tb.sv**.

**docs/exp_approx.md**, updated **docs/numerics.md**, rerun tolerance study.

### 4.2 Your Task

Build and verify the three blocks. All comparisons against the hardware-emulating model are bit-exact. Then swap the real `exp_approx` into the end-to-end Python model, rerun the Assignment 5 tolerance study, and update the agreed tolerance with a sentence on how much error the exponential added on top of BF16 quantization.

### 4.3 Testing Your Implementation

| Test | Block | Description |
|---|---|---|
| 1 | exp | `x = 0` returns exactly `0x3F800000` |
| 2 | exp | 1,000,000 random `x` in `[-90, 0]`, bit-exact vs model |
| 3 | exp | Every LUT boundary and interpolation midpoint |
| 4 | exp | Cutoff: values just above and below the zero threshold |
| 5 | exp | Monotonicity over a dense sweep |
| 6 | exp | `-0.0` input returns 1.0; positive input fires the assertion |
| 7 | max | Random rows with random valid masks |
| 8 | max | Single valid entry at each position |
| 9 | max | All equal scores; -0 vs +0; all negative |
| 10 | max | No valid entries: `any_valid = 0` |
| 11 | stats | Equal scores: every valid P = 1.0, `l_b` = count of valid |
| 12 | stats | Highly separated scores: one P = 1, rest near 0 |
| 13 | stats | Masked entries: P = 0 exactly, not counted in `l_b` |
| 14 | stats | Partial tile, decode shape, 200 random tiles, bit-exact |

### 4.4 Submission

To receive full credit you must:

1. Pass all fourteen tests bit-exact.
2. Commit `docs/exp_approx.md` with measured error and LUT size.
3. Commit the rerun tolerance study.

Tag the commit `a9-block-stats`.
