# KVP-1 Hardware Design Project
## Paged KV Cache and FlashAttention Accelerator
## Assignment #8: QK^T Score Engine, Scale and Mask

Milestone M4 (RTL attention core) | Track B | Target: Friday, Jan 29, 11:59 PM PST

---

### Contents

1. Introduction
2. Setting Up Your Environment
3. Computing a Score Tile
   - 3.1 Shapes and Mapping
   - 3.2 qk_matmul_adapter and qk_accum_ctrl
   - 3.3 score_scale
   - 3.4 score_mask
   - 3.5 score_buffer
4. Assignment #8
   - 4.1 Files
   - 4.2 Your Task
   - 4.3 Testing Your Implementation
   - 4.4 Submission

---

## 1 Introduction

The first stage of attention compares every query row in the tile with every key row: `S = Q K^T`, scaled by `1/sqrt(d)`, with masked positions flagged so they contribute zero probability later. This assignment builds that stage on top of the BF16 array you characterized in Assignment 6 and the tile buffers from Assignment 7.

The output is a score tile: up to 4 x 16 FP32 scores plus a valid bit for each, sitting in a small buffer where the softmax blocks (Assignment 9) can read it.

## 2 Setting Up Your Environment

Pull `a7-tile-buffers`. Read `docs/ip_bf16_sa.md` again before starting; the dataflow answer decides half of this design. Generate vectors with `scripts/gen_attention_vectors.py` from Assignment 5, extended to also dump the intermediate scaled, masked score tile from the hardware-emulating model.

## 3 Computing a Score Tile

### 3.1 Shapes and Mapping

| Operand | Shape | Source |
|---|---|---|
| Q tile | `Br x d` = up to 4 x 16, BF16 | `q_tile_buffer` |
| K tile | `Bc x d` = up to 16 x 16, BF16 | `kv_tile_buffer.rd_k` |
| S tile | `Br x Bc` = up to 4 x 16, FP32 | `score_buffer` |

With a 4x4 array, the 4 x 16 score tile is four 4x4 output blocks, one per group of four keys. Each output element is a 16-term dot product.

- If the array is **output-stationary** with a streamed reduction: for each key group `g = 0..3`, stream the 16 reduction steps (`Q[:, k]` against `K[4g..4g+3, k]` for `k = 0..15`) and drain one 4x4 block. Four passes total.
- If the array is **weight-stationary** with a fixed reduction of 4: each pass computes a partial sum over 4 elements of `d`. Four partial passes per key group, summed in FP32 by `qk_accum_ctrl`. Sixteen passes total.

Either is acceptable. Write which one you built in `docs/qk_engine.md` and update the Python model's accumulation order so the hardware-emulating scores are bit-exact.

Decode has `Br = 1`, so 3 of 4 array rows do nothing. That is fine for correctness. Note it; Assignment 15 will compare against a dedicated 16-lane dot-product engine (Extension).

### 3.2 qk_matmul_adapter and qk_accum_ctrl

`qk_matmul_adapter` reads the buffers, feeds the array in the order its protocol expects, and writes results into `score_buffer`. `qk_accum_ctrl` (weight-stationary case only) holds partial sums and clears them between independent tiles. You may merge them into one module if the array is output-stationary; keep the name `qk_matmul_adapter`.

| Port | Dir | Description |
|---|---|---|
| `qk_start` | in | Both tiles valid; begin |
| `qk_busy`, `qk_done` | out | `qk_done` pulses after the last score is written |
| Q buffer read port | out/in | `q_rd_row`, `q_rd_data` |
| KV buffer read port | out/in | `rd_idx`, `rd_k`, `rd_token`, `rd_slot_valid` |
| Array ports | out/in | Whatever the array needs |
| `score_buffer` write port | out | `sb_wr_en`, `sb_wr_row`, `sb_wr_col`, `sb_wr_data`, `sb_wr_valid` |

Rows and columns beyond `q_rows` and `tile_count` still get computed (the array does not care) but must be marked invalid by the mask logic. Feed zeros instead of stale buffer contents for those slots so a NaN left over in a stale register can never leak.

REQ-QK-02: no stale accumulator state between tiles. Test it by running two different tiles back-to-back without reset.

### 3.3 score_scale

Multiply each score by `1/sqrt(d)`. For `d = 16` the factor is 0.25 = 2^-2, which is exact in floating point: subtract 2 from the exponent field.

- Exponent field 0 (zero or subnormal): output zero with the same sign (flush policy).
- Exponent field 1 or 2: the result is subnormal; flush to zero.
- Exponent field 255 (inf/NaN): pass through.
- Otherwise: exponent minus 2.

Parameterize it: if `HEAD_DIM` is not 16, fall back to `fp32_mul` by a constant computed at elaboration. Only the `d = 16` path needs to be tested now. Scale is applied before the row max (spec numerical rules).

### 3.4 score_mask

Combinational. For score `(r, c)`:

```
pad_ok    = (r < q_rows) && (c < tile_count)
causal_ok = (k_token[c] <= q_pos_base + r)
valid     = pad_ok && (mask_mode == CAUSAL ? causal_ok : 1)
```

Masked scores keep their value in the buffer but carry `valid = 0`. Do not overwrite them with -inf: the downstream blocks ignore invalid entries by construction, which avoids every -inf arithmetic hazard the spec warns about. Record this choice in `docs/decisions.md` (REQ-QK-04: mask metadata travels with the score).

### 3.5 score_buffer

`Br x Bc` FP32 entries plus `Br x Bc` valid bits, in registers. One write port from the adapter (after scale and mask), and a read interface wide enough for the softmax blocks: read a whole row (16 scores + 16 valid bits) in one cycle. Also expose `row_any_valid[r]`, the OR of a row's valid bits, which the softmax state logic needs.

## 4 Assignment #8

### 4.1 Files

**rtl/qk_matmul_adapter.sv** (and **rtl/qk_accum_ctrl.sv** if separate), **rtl/score_scale.sv**, **rtl/score_mask.sv**, **rtl/score_buffer.sv**, **rtl/qk_engine.sv** (wrapper wiring the four together with the array).

**tb/score_scale_tb.sv**: Exhaustive over exponent field values with random mantissas.

**tb/qk_engine_tb.sv**: Engine-level test with the real tile buffers.

**docs/qk_engine.md**: Dataflow chosen, pass count, cycle count per tile, row/column ordering, accumulation order.

### 4.2 Your Task

Build the score path and verify it against the hardware-emulating model's intermediate score tile. Every comparison is bit-exact for the score values (they are deterministic FP32 sums in a known order) and exact for the valid bits.

### 4.3 Testing Your Implementation

| Test | Description | Must check |
|---|---|---|
| 1 | Identity-like Q | Q row r = one-hot in element r; scores equal 0.25 x K[c][r] |
| 2 | Non-symmetric data (REQ-QK-03) | Q and K chosen so S and S^T differ everywhere; a transposed mapping fails loudly |
| 3 | Random full tile | 4 x 16, bit-exact vs model |
| 4 | Decode shape | 1 query row; rows 1..3 invalid |
| 5 | Partial KV tile | `tile_count = 7`; columns 7..15 invalid |
| 6 | Causal mask | `q_pos_base = 20`, tokens 16..31: valid exactly where `token <= 20 + r` |
| 7 | Fully masked row | Causal row with all tokens in the future: `row_any_valid = 0` |
| 8 | Back-to-back tiles (REQ-QK-02) | Two random tiles, no reset between; both bit-exact |
| 9 | Stale NaN | Preload a NaN into an unused KV slot from an earlier tile; it never appears in a valid score and never affects a valid score |
| 10 | Scale edge cases | Zero, -0, small exponents (flush), inf, NaN |
| 11 | 200 random tiles | Random `q_rows`, `tile_count`, mask mode, seed printed |

### 4.4 Submission

To receive full credit you must:

1. Pass all eleven tests bit-exact.
2. Record the cycle count for one score tile in `docs/qk_engine.md`.
3. Add the "masked scores carry a valid bit, never -inf" decision to `docs/decisions.md`.

Tag the commit `a8-qk-engine`.
