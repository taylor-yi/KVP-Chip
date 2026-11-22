# KVP-1 Hardware Design Project
## Paged KV Cache and FlashAttention Accelerator
## Assignment #7: Attention Tile Buffers and Tile Loader

Milestone M4 (RTL attention core) | Track A | Target: Friday, Jan 22, 11:59 PM PST

---

### Contents

1. Introduction
2. Setting Up Your Environment
3. Tiles and Buffers
   - 3.1 Where Tiles Come From
   - 3.2 q_tile_buffer
   - 3.3 kv_tile_buffer
   - 3.4 tile_loader
4. Assignment #7
   - 4.1 Files
   - 4.2 Your Task
   - 4.3 Testing Your Implementation
   - 4.4 Submission

---

## 1 Introduction

The attention datapath works on tiles: up to `Br = 4` query rows against `Bc = 16` K/V rows at a time. The KV cache produces a stream, one token per beat. Something has to collect that stream into a tile, remember how many rows are real (the final tile is usually partial), hold the tile still while the compute engine reads it in whatever order it likes, and only then accept the next one.

This assignment builds that boundary. It sits between the two halves of the project, so treat the interfaces as a contract between partners: the KV-side partner owns this module, and the attention-side partner signs off on the read ports.

## 2 Setting Up Your Environment

Pull `a6-ip-char`. The tile loader's input port is the same stream that `kv_cache_top` produces (`kv_valid/ready`, `kv_k`, `kv_v`, `kv_token`, `kv_last`). Your testbench can drive it directly from vectors or instantiate `kv_cache_top` upstream. Do both: unit tests with a direct driver, one integration test through the real cache.

## 3 Tiles and Buffers

### 3.1 Where Tiles Come From

Decision for this project: **all K/V tiles come from the KV cache**, in both modes. In prefill, the prompt's K/V are appended to the cache first and then read back tile by tile. This costs extra read cycles but means the tile loader has one source and the cache is exercised on every run. The spec allows either approach; record this one in `docs/decisions.md` (create it now and keep adding to it). A direct prefill path is an Extension.

Queries come from the host (or the testbench) and are loaded into the query buffer once per query tile.

### 3.2 q_tile_buffer

Holds up to `Br` query rows of `d` BF16 elements (one 256-bit word per row), plus the absolute position of the first row so the mask logic can compute each row's position.

| Port | Dir | Width | Description |
|---|---|---|---|
| `q_clear` | in | 1 | Invalidate the tile |
| `q_wr_en`, `q_wr_row`, `q_wr_data` | in | 1, 2, 256 | Write one row |
| `q_commit` | in | 1 | Mark the tile valid |
| `q_rows` | in | 3 | Number of real rows, 1 to 4, captured on commit |
| `q_pos_base` | in | `TOK_W` | Absolute position of row 0, captured on commit |
| `q_valid` | out | 1 | Tile committed and not cleared |
| `q_rd_row` | in | 2 | Read address |
| `q_rd_data` | out | 256 | Row data. Combinational read (registers, not BRAM) |
| `q_rd_row_valid` | out | 1 | `q_valid && q_rd_row < q_rows` |
| `q_num_rows`, `q_base` | out | | Captured values |

Committing with `q_rows = 0` or `q_rows > Br` is an error: assert `q_err` and do not set `q_valid`.

### 3.3 kv_tile_buffer

Holds up to `Bc` tokens: K word, V word and logical token index for each.

| Port | Dir | Width | Description |
|---|---|---|---|
| `wr_en`, `wr_idx`, `wr_k`, `wr_v`, `wr_token` | in | | Write one slot |
| `commit`, `commit_count` | in | 1, 5 | Mark valid with 1 to 16 real tokens |
| `commit_first`, `commit_last` | in | 1 | Tile is the first / last of this query's pass, passed through for the softmax state logic |
| `release` | in | 1 | Compute is done with this tile; buffer becomes writable |
| `tile_valid` | out | 1 | |
| `tile_count`, `tile_first`, `tile_last` | out | | |
| `rd_idx` | in | 4 | Read address |
| `rd_k`, `rd_v`, `rd_token` | out | | Combinational |
| `rd_slot_valid` | out | 1 | `tile_valid && rd_idx < tile_count` (REQ-BUF-01: unwritten slots are never reported valid) |

32 words of 256 bits is 8 Kbit. Registers are fine at this size and give you a combinational read port, which the matmul adapters will appreciate. If you choose distributed RAM or BRAM instead, document the read latency.

Writes while `tile_valid` is high are a protocol error. Assert in simulation and ignore the write.

### 3.4 tile_loader

Fills `kv_tile_buffer` from the cache stream.

| Port | Dir | Description |
|---|---|---|
| `load_start` | in | Begin a tile. Captures `exp_count` (1 to 16), `is_first`, `is_last` |
| `exp_count`, `is_first`, `is_last` | in | From the scheduler |
| `kv_valid`, `kv_k`, `kv_v`, `kv_token`, `kv_last` | in | Cache stream |
| `kv_ready` | out | High while loading and the buffer is not holding a valid tile |
| `cache_error` | in | Cache's `rd_error`; aborts the load |
| buffer write ports | out | To `kv_tile_buffer` |
| `load_done` | out | Pulse after commit |
| `load_error` | out | Pulse on any error below |

Errors (REQ-BUF-02, REQ-BUF-03):

- **Short tile**: `kv_last` arrives before `exp_count` beats. Commit nothing, `load_error`.
- **Overflow**: more than `exp_count` beats without `kv_last`. Stop accepting (`kv_ready` low), `load_error`.
- **Last mismatch**: beat `exp_count` arrives without `kv_last`. Treat as overflow.
- **Cache error**: abort, `load_error`.

Who issues the cache read command? The scheduler (Assignment 12). The tile loader only consumes the stream. Keep it that way so the loader has no knowledge of logical ranges beyond the count.

Extension (REQ-BUF-05): a second `kv_tile_buffer` and `double_buffer_ctrl` so the next tile loads while the current one is in compute.

## 4 Assignment #7

### 4.1 Files

**rtl/q_tile_buffer.sv**, **rtl/kv_tile_buffer.sv**, **rtl/tile_loader.sv**.

**tb/tile_buffers_tb.sv**: Unit tests with a direct stream driver.

**tb/tile_loader_cache_tb.sv**: Integration test, `kv_cache_top` feeding `tile_loader`.

**docs/tile_buffers.md**: Port tables, read latency, error table, the backpressure rule.

**docs/decisions.md**: New file. First entry: "all K/V tiles come from the cache."

### 4.2 Your Task

Implement the three modules and test them. In the stream tests, the driver must randomly deassert `kv_valid`, and the testbench checks that no beat is dropped, duplicated or reordered: every slot `i` of a committed tile holds the beat for logical token `start + i`.

### 4.3 Testing Your Implementation

Covers the spec's tiling test matrix where it applies to buffers.

| Test | Description | Must check |
|---|---|---|
| 1 | Q tile, 4 rows | All rows readable, `q_rd_row_valid` for 0..3 |
| 2 | Q tile, 1 row (decode shape) | Rows 1..3 report invalid |
| 3 | Q commit with 0 rows | `q_err`, not valid |
| 4 | Full KV tile | 16 beats, all slots match, `tile_count = 16` |
| 5 | Partial KV tile | 5 beats with `kv_last`; slots 5..15 report invalid even if stale data from Test 4 is still in the registers |
| 6 | Short tile error | `kv_last` on beat 3 of an expected 8 |
| 7 | Overflow error | 9 beats for an expected 8 |
| 8 | Write while valid | Assertion fires, data unchanged |
| 9 | Release and reload | Load, release, load a different tile; no mixing |
| 10 | Bursty stream | Random `kv_valid` gaps, 50 tiles, no drops or reorders |
| 11 | From the cache | Append 40 tokens, load tiles [0..15], [16..31], [32..39] through `kv_cache_top`; tokens and data match |

### 4.4 Submission

To receive full credit you must:

1. Pass all eleven tests.
2. Have the attention-side partner approve the read-port tables in `docs/tile_buffers.md` (note the approval in the PR).
3. Start `docs/decisions.md`.

Tag the commit `a7-tile-buffers`.
