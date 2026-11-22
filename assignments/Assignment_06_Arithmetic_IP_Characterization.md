# KVP-1 Hardware Design Project
## Paged KV Cache and FlashAttention Accelerator
## Assignment #6: Arithmetic IP Characterization

Milestone M1 (IP characterization) | Track B | Target: Friday, Jan 15, 11:59 PM PST

---

### Contents

1. Introduction
2. Setting Up Your Environment
3. The Reused Arithmetic
   - 3.1 The BF16 Systolic Array
   - 3.2 Floating-Point Primitives
   - 3.3 The INT4 Array (Optional)
4. Assignment #6
   - 4.1 Files
   - 4.2 Your Task
   - 4.3 Testing Your Implementation
   - 4.4 Submission

---

## 1 Introduction

The spec treats the existing systolic arrays as "reusable starting assets, not fully verified project subsystems." Before the QK^T and PV engines are built on top of the BF16 array, you need to know exactly what it does: its dimensions, dataflow, cycle-level protocol, accumulator format, rounding and special-value behavior.

You also need a small library of floating-point building blocks (BF16 multiply, FP32 add, FP32 multiply, FP32 compare) that the softmax and normalization blocks in Assignments 8 to 11 will share. Most of these already exist inside the TPU project's processing element. This assignment pulls them out, gives each a contract and a bit-exact Python model, and tests them hard.

This is spec milestone M1. It comes after the KV cache in this schedule because the KV cache needed no arithmetic. It must be done before Assignment 8.

## 2 Setting Up Your Environment

Copy the BF16 systolic array RTL from the TPU project into `ip/bf16_sa/`, unmodified, with a note in `ip/bf16_sa/README.md` saying where it came from and at which commit. Do not edit the array during this assignment. If you find bugs, record them; fix them in a separate commit after characterization so the bug and the fix are both on record.

Add `ip/**/*.sv` to the `build.sh` glob.

## 3 The Reused Arithmetic

### 3.1 The BF16 Systolic Array

Settle the open question from the overview first. Your earlier TPU was a 4x4 output-stationary array with FP32 accumulation. The spec PDF describes it as weight-stationary. Read the RTL and write down which it actually is. This matters a lot for Assignment 8:

- **Output-stationary**: each PE owns one output element and accumulates over a streamed reduction dimension of any length. A 4x16 score tile with `d = 16` is four passes of a 4x4 output block, each streaming 16 reduction steps. No external accumulation needed.
- **Weight-stationary**: each PE holds one weight; the reduction dimension is fixed by array height (4). `d = 16` needs four partial sums added externally in FP32.

Write a one-page spec, `docs/ip_bf16_sa.md`, answering every item below. The spec Section 23 list is the minimum.

| Item | Question |
|---|---|
| Dimensions | Rows, columns, parameterized? Legal parameter range? |
| Dataflow | Output- or weight-stationary? Which operand is preloaded or streamed? |
| Operand format | BF16 encoding, lane packing on the input bus |
| Products | Exact BF16 x BF16 into FP32? |
| Accumulator | FP32? Rounding mode? Order of accumulation per PE? |
| Output format | FP32 or BF16 at the port? (Recall the drain-chain FP32 to BF16 to FP32 bug you fixed earlier. Confirm the fix is in this copy.) |
| Special values | +0, -0, subnormals (supported or flushed?), +inf, -inf, NaN (quiet/signaling distinguished?) |
| Protocol | Start/valid/ready? Can input be stalled mid-stream? What happens on a gap? |
| Latency | Cycles from first operand to first output and last output, as a formula of size |
| Reset | What does reset mid-operation do? |
| Known issues | Anything the original testbench never covered |

### 3.2 Floating-Point Primitives

Extract or write these as standalone modules in `rtl/fp/`. Each is combinational unless noted; pipeline them later if timing needs it.

| Module | Function | Notes |
|---|---|---|
| `bf16_mul` | BF16 x BF16 to FP32 | Exact for normal inputs |
| `fp32_add` | FP32 + FP32 to FP32 | RNE. Used for dot products, `l` accumulation, output accumulation |
| `fp32_mul` | FP32 x FP32 to FP32 | RNE. Used for `alpha*O`, `beta*l_b`, normalization |
| `fp32_max` | max(a, b), plus `a_gt_b` | Integer compare after sign fix-up. Used by row max and `m' = max(m, m_b)` |
| `f32_to_bf16` | FP32 to BF16 | RNE. Needed if P is fed to the BF16 array as BF16 |

Pick one subnormal policy for the whole project (flush-to-zero on inputs and outputs is the common choice) and apply it everywhere, including the Python model. Write it into `docs/numerics.md`.

Each primitive gets a Python twin in `model/fp_models.py` that is bit-exact, built from integer bit manipulation rather than `numpy` arithmetic, so the subnormal policy and rounding are explicit. Then cross-check the twin against `numpy.float32` on normal inputs to make sure your bit-level model is right.

Update `model/attention_hw.py` from Assignment 5 to call these twins.

### 3.3 The INT4 Array (Optional)

The INT4 double-buffered 3x3 array is not on the core path. If you want to run the BF16-vs-INT4 comparison in Assignment 15, characterize it now using the same table, with these extra questions from the spec: is the 10-bit output signed or unsigned, where is the binary point, does it saturate or wrap, and does the double-buffer swap work for any gap other than back-to-back? Exhaustive tests over all 16 x 16 input pairs per PE are cheap; do them.

## 4 Assignment #6

### 4.1 Files

**ip/bf16_sa/**: Array RTL, unmodified, plus README.

**rtl/fp/*.sv**: The five primitives.

**model/fp_models.py**: Bit-exact Python twins.

**model/sa_model.py**: Cycle-agnostic model of the array's arithmetic: given operand matrices, returns the exact FP32 outputs in the array's own accumulation order.

**tb/fp_primitives_tb.sv**, **tb/bf16_sa_char_tb.sv**: Self-checking testbenches.

**scripts/gen_fp_vectors.py**, **scripts/gen_sa_vectors.py**.

**docs/ip_bf16_sa.md**: The table from 3.1, answered. **docs/numerics.md**: Updated with subnormal policy and accumulation order.

### 4.2 Your Task

Characterize, do not redesign. A good outcome is a doc that says "works for X, fails for Y, untested for Z" with evidence for each. Every claim in the doc should point to a test.

### 4.3 Testing Your Implementation

**Primitives** (bit-exact vs Python twins):

| Test | Description |
|---|---|
| Random normals | 100,000 random pairs per primitive |
| Signed zeros | +0 + -0, -0 + -0, x * -0 |
| Infinities and NaN | inf - inf = NaN, inf * 0 = NaN, NaN propagation |
| Subnormals | Inputs and results near the subnormal boundary follow your policy |
| Rounding ties | Constructed cases that land exactly on a tie |
| Cancellation | `fp32_add(a, -a + tiny)` |
| Overflow | Results above max finite go to inf |
| `fp32_max` ordering | -0 vs +0, negative vs positive, NaN handling defined |

**Array** (spec Section 23 list):

| Test | Description |
|---|---|
| Single transaction | One matrix multiply from reset |
| Idle gap | Two multiplies with gaps of 1 to 10 cycles |
| Back-to-back | Continuous multiplies |
| Reset mid-operation | Behavior matches the doc |
| Valid deassertion | Inputs stall mid-stream (if the protocol allows) |
| Operand changes | Different weights each job; no stale data |
| Special values | Each special value in each operand position |
| Non-symmetric data | A and B chosen so a transposition bug changes the answer |
| Attention shape | 4x16 by 16x4 (or the four 4x4 passes it decomposes into), random BF16 |

### 4.4 Submission

To receive full credit you must:

1. Pass all primitive tests bit-exact and all array tests that the doc claims are supported.
2. Commit `docs/ip_bf16_sa.md` with every row filled in and a "Known issues" list (an empty list needs a sentence explaining why you believe it).
3. Commit the updated `docs/numerics.md`.

Tag the commit `a6-ip-char`. This closes milestone M1.
