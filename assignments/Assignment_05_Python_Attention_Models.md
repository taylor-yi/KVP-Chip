# KVP-1 Hardware Design Project
## Paged KV Cache and FlashAttention Accelerator
## Assignment #5: Python Attention Reference Models

Milestone M3 (Python attention) | Track B | Target: Friday, Jan 8, 11:59 PM PST

---

### Contents

1. Introduction
2. Setting Up Your Environment
3. The Three Models
   - 3.1 Conventional Attention (FP64)
   - 3.2 Tiled Online-Softmax Attention (FP64)
   - 3.3 Hardware-Emulating Model (BF16 / FP32)
   - 3.4 Masks and Edge Cases
   - 3.5 Error Metrics and Tolerances
4. Assignment #5
   - 4.1 Files
   - 4.2 Your Task
   - 4.3 Testing Your Implementation
   - 4.4 Submission

---

## 1 Introduction

Every RTL block from Assignment 8 onward is checked against Python. Before any attention RTL exists, you need three models that agree with each other and that you trust:

1. A plain, obviously-correct attention in double precision.
2. The FlashAttention-style tiled version with running `m`, `l`, `O` state, also in double precision. It must match model 1 to within floating-point noise. If it does not, the algorithm is wrong, not the numerics.
3. A hardware-emulating version that rounds to BF16 and FP32 exactly where the RTL will, and calls the same exponential approximation the RTL uses. RTL is compared bit-for-bit (or within a few ULP) against this one.

This is the same idea as the EE271-style Python simulator: get the behavior right in software where debugging is cheap, then build hardware that matches it.

## 2 Setting Up Your Environment

Use the venv from Assignment 2. `numpy` is the only dependency. Put all code in `model/`. Do not use PyTorch for the reference; you want every rounding step visible.

## 3 The Three Models

All models take one head: `Q` is `(Lq, d)`, `K` and `V` are `(Lk, d)`, with `d = 16`. Each query row also carries an absolute position `q_pos[i]` and each key row `k_pos[j]`, used by the causal mask. In decode, `Lq = 1` and `q_pos = [Lk - 1]`.

### 3.1 Conventional Attention (FP64)

```
S = (Q @ K.T) * scale          # scale = 1/sqrt(d) = 0.25
S[mask] = -inf
P = softmax(S, axis=1)
O = P @ V
```

Write it in the most literal way possible. This is the ground truth.

### 3.2 Tiled Online-Softmax Attention (FP64)

Process query tiles of `Br = 4` rows and KV tiles of `Bc = 16` rows. For each query row keep `m`, `l`, `O[d]`. For each KV block, using the equations from spec Section 8:

```
S_b    = (Q_tile @ K_b.T) * scale, masked entries flagged
m_b    = rowmax over valid entries of S_b
P_b    = exp(S_b - m_b) for valid entries, 0 for masked
l_b    = rowsum(P_b)
O_b    = P_b @ V_b
m'     = max(m, m_b)
alpha  = exp(m - m'),  beta = exp(m_b - m')
l'     = alpha*l + beta*l_b
O'     = alpha*O + beta*O_b
```

After the last block: `out = O / l`.

Handle the first block without computing `exp(-inf - -inf)`. Use an explicit `row_started` flag: the first block with at least one valid entry copies `m = m_b, l = l_b, O = O_b`. Blocks with no valid entries for a row leave that row's state untouched.

Notice that one of `alpha` or `beta` is always exactly 1, because `m'` equals either `m` or `m_b`. The RTL in Assignment 10 can use this to compute one exponential per row per block instead of two. Make the model compute it that way too (and assert the equivalence in a test).

### 3.3 Hardware-Emulating Model (BF16 / FP32)

Same structure as 3.2, with these numeric rules. They become the numeric contract in `docs/numerics.md`, which the RTL must follow.

| Quantity | Format | Rounding |
|---|---|---|
| Q, K, V inputs | BF16 | Round-to-nearest-even from FP32 when generating test data |
| Products `q*k`, `p*v` | BF16 x BF16, exact in FP32 | none (product of two 8-bit mantissas fits in FP32) |
| Dot-product accumulation | FP32 | RNE after every add, **in a fixed order**: element 0 first, left to right |
| Score scale | FP32 multiply by 0.25 | exact except underflow; define flush-to-zero |
| `m`, `l`, `O`, `alpha`, `beta` | FP32 | RNE |
| `exp` | calls `exp_approx(x)` | must be bit-identical to RTL (Assignment 9) |
| `P` into the PV product | BF16 or FP32 | your decision; record it. BF16 lets PV reuse the BF16 array |
| Final `O / l` | FP32 reciprocal then multiply, or FP32 divide | match Assignment 10 |
| Output | FP32 (and optionally BF16) | |

Implement the FP32 steps with `numpy.float32` scalars so every operation rounds. Write `bf16_from_f32(x)`, `f32_from_bf16(b)` and helpers to pack 16 BF16 values into a 256-bit int in the lane order from `docs/kv_layout.md`.

For now, `exp_approx` is a placeholder that returns `np.float32(np.exp(x))`. Assignment 9 replaces it with the bit-exact LUT version. Keep it pluggable.

Accumulation order matters for bit-exactness. The RTL adder tree or systolic array may sum in a different order. When you get to Assignment 6, update the model to match the hardware's actual order, or switch the RTL comparison to a ULP tolerance and say why.

### 3.4 Masks and Edge Cases

Support three mask modes: `none`, `causal` (mask where `k_pos[j] > q_pos[i]`), and `padding` (mask key rows `j >= valid_k` and query rows `i >= valid_q` for partial tiles).

Defined behavior for edge cases (these become the RTL spec):

- **Empty context** (`Lk = 0`): output row is all zeros and a `row_invalid` flag is set.
- **All-masked row**: same as empty context.
- **`l == 0` at normalization**: cannot happen for a row with at least one valid entry (the max entry contributes `exp(0) = 1`), so treat it as the all-masked case.
- **Partial final tiles**: `Lk` not a multiple of 16, `Lq` not a multiple of 4.

### 3.5 Error Metrics and Tolerances

Write `compare(ref, test)` returning max absolute error, max relative error (with a small floor on the denominator), and RMS error. Spec Section 28 asks for all three.

Set tolerances by measurement, not by what passes. Run 1,000 random cases (inputs drawn from N(0, 1) and rounded to BF16) and record the distribution of error between model 3 and model 1. Set the acceptance tolerance at a stated margin above the observed maximum, and write down the main error source (BF16 input quantization will dominate at first). Record it in `docs/numerics.md`.

## 4 Assignment #5

### 4.1 Files

**model/attention_ref.py**: `attention_conventional`, `attention_tiled`, masks.

**model/attention_hw.py**: Hardware-emulating model, BF16/FP32 helpers, pluggable `exp_approx`.

**model/metrics.py**: `compare()`.

**model/test_attention.py**: pytest suite.

**scripts/gen_attention_vectors.py**: Exports Q/K/V (packed BF16 hex), positions, mask mode, and expected outputs from model 3 (FP32 hex) for a named scenario. RTL testbenches from Assignment 8 on consume these.

**docs/numerics.md**: The table from 3.3, edge-case definitions from 3.4, tolerance study from 3.5.

### 4.2 Your Task

Build the three models, prove they agree, write the numeric contract. Keep the code readable; your partner will step through it in a debugger when RTL disagrees with it.

### 4.3 Testing Your Implementation

The spec's softmax and tiling test matrix (Section 27), applied to the models:

| Test | Description | Check |
|---|---|---|
| tiled_vs_conv | Random Q/K/V, `Lq` in 1..9, `Lk` in 1..40 | Model 2 vs model 1, max abs error < 1e-12 |
| shorter_than_tile | `Lk = 5` | Single partial block |
| exact_multiple | `Lk = 32` | Two full blocks |
| non_multiple | `Lk = 33` | Final block of 1 |
| one_query_row | `Lq = 1` (decode shape) | |
| equal_scores | All K rows identical | Uniform weights, output = mean of V |
| separated_scores | One score 30 above the rest | Output approximately that V row |
| negative_scores | All scores large negative | No underflow to all-zero `l` |
| causal | `Lq = Lk = 20`, causal | Matches conventional with -inf mask |
| all_masked_row | Padding row | Zeros + `row_invalid` |
| first_block_masked | Causal row whose first KV block is fully masked | State initialized from second block |
| alpha_beta_one | Random | One of alpha, beta is exactly 1.0 every update |
| hw_vs_conv | 1,000 random cases | Model 3 vs model 1 within the tolerance you set |
| bf16_roundtrip | Packing helpers | 256-bit pack/unpack round-trips; lane 0 in LSBs |

### 4.4 Submission

To receive full credit you must:

1. Pass every pytest.
2. Commit `docs/numerics.md` with the tolerance study (include a histogram or percentile table of observed errors).
3. Have the KV-side partner run `gen_attention_vectors.py` for a decode scenario and confirm the packed K/V format matches what `kv_cache_top` stores.

Tag the commit `a5-py-attention`. This closes milestone M3.
