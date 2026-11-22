# KVP-1 Project Overview and Status

Working folder for the KVP-1 paged KV cache + FlashAttention accelerator. This doc is the index: what the project is, where the repo stands, the conventions every assignment assumes, and the assignment schedule.

- Repo: https://github.com/taylor-yi/KVP-Chip (reviewed at commit `3ee0deb`, Nov 17 2026)
- Baseline spec: `KVP1_FlashAttention_Hardware_Project_Specification.pdf` (in this project)
- Team: two people. Taylor owns `page_allocator`; partner owns `page_table` and is new to SystemVerilog.
- Goal: one attention head, one sequence, prefill + decode demonstrated on FPGA. Full token prediction is out of scope.

---

## 1. Frozen design point

From `extras/NOTES.md` plus the spec's suggested initial values. Every assignment uses these unless it says otherwise.

| Parameter | Value | Notes |
|---|---|---|
| Heads | 1 | |
| Head dimension d | 16 | |
| K/V element format | BF16 | 16 lanes x 16 bits = one 256-bit word per token vector |
| Memory word | 256 bits | `WORD_W = 256` |
| Page size | 16 tokens | `PAGE_SIZE = 16`, offset = token[3:0] |
| Physical pages | 16 | `NUM_PAGES = 16`, `PAGE_W = 4` |
| Max context | 256 tokens | `TOK_W = 8`, lengths need 9 bits (0..256) |
| K store / V store | 8 KiB each | separate `kv_block_ram` instances, `DEPTH = 256`, `ADDR_W = 8` |
| Physical address | `{ppage, offset}` | 8 bits, word-addressed |
| Query tile Br | 4 | matches the 4x4 BF16 array |
| KV tile Bc | 16 | equal to page size, so one tile = one page in the simple case |
| Score / softmax / output accumulators | FP32 | |
| Score scale | 1/sqrt(16) = 0.25 | exact power of two |

Lane order inside a 256-bit word: element `i` lives at bits `[16*i +: 16]` (element 0 in the LSBs). Write this into `docs/kv_layout.md` in Assignment 2.

## 2. Where the repo stands (Nov 21 2026)

| Module | File | State | Spec name |
|---|---|---|---|
| Single-port-style BRAM | `kv_block_ram.sv` + tb | Done | `kv_bram_store` |
| K/V memory interface (valid/ready, separate K and V RAMs) | `kv_mem_interface.sv` + tb | Done; tb checklist items 7 to 11 still open | `bram_adapter` (partial) |
| Page table | `page_table.sv` + tb | Done, 4 tests pass | `page_table` |
| Page allocator | `page_allocator.sv` + tb | RTL written, **testbench in progress** (Test 1 only) | `page_allocator` |
| Everything else | | Not started | |

### Review notes from reading the code

These are folded into Assignment 1 where they apply.

**page_allocator.sv**
- No protection against freeing a page that is already free. If `free_ppage` equals the page being allocated in the same cycle, the free assignment comes later in the `always_ff` and wins, so the page is handed out but marked free. Next allocation hands it out again: a double allocation, which is exactly what REQ-KV-04 forbids.
- When the pool is full and a free arrives in the same cycle as an allocation request, the request fails (`alloc_error`) even though a page is being returned. That is fine but needs to be a documented policy.
- `alloc_page` reads 0 when the pool is full. Consumers must qualify it with `alloc_ok`.

**page_allocator_tb.sv**
- `reset_everything()` assigns `alloc_page`, `alloc_ok`, `alloc_error`. Those are DUT outputs. The testbench should never drive them; delete those three lines.
- `$display("Test 1 Passed: ...", $time)` passes `$time` with no `%0t` in the format string. Harmless, but either add `[%0t]` or drop the argument.
- `allocate_pages()` is empty and Test 2 is a comment.

**page_table.sv**
- A write and a lookup to the same logical page in the same cycle return the old mapping (the write is visible next cycle). Document it.
- No way to invalidate a single entry. Fine for one sequence; needed later for page reclamation (Extension).

**kv_mem_interface.sv**
- Writes complete on the accept cycle and produce no response. Downstream controllers must treat `req_valid && req_ready` with `req_write = 1` as write completion (REQ-MEM-02).
- One outstanding read at a time, so peak read rate is one token every 2 cycles. Good enough for the core demo; note it for the performance section.

**kv_block_ram.sv**
- `rst_n` is unused (correct for BRAM inference). Read-during-write to the same address returns old data. Document it.

**Repo housekeeping**
- `obj_dir/` binaries and `dump.vcd` are committed. Add a `.gitignore`.
- `extras/ARCHITECTURE.md` describes an earlier concept (Q8.8 fixed point, two-pass softmax, `block_table.sv`, 64 context tables) that does not match the current spec (BF16, online softmax). Either update it or move it to `extras/archive/`.
- No Python golden model is committed yet. If one exists locally, push it in Assignment 2.

## 3. Conventions every assignment assumes

- One clock `clk`, synchronous active-low reset `rst_n`, `` `timescale 1ns/1ps `` in every file.
- `logic` everywhere, `always_ff` / `always_comb`, `typedef enum` FSM states.
- Streaming interfaces are valid/ready. A transfer happens on a rising edge where both are high. A producer holding `valid` must keep data stable until accepted.
- Command interfaces use `*_valid / *_ready` to issue and a one-cycle `*_done` pulse to finish, with a sticky-until-next-command `*_error`.
- Testbenches follow the existing pattern: `errors` / `test_errors` counters, per-test PASS/FAIL line, and a final summary line `ALL TESTS PASSED` or `FAILED: N errors`. Drive inputs on `negedge`, check after `negedge`. Use `!==` for checks.
- Python models live in `model/`, vector generators in `scripts/`, generated vectors in `tb/vectors/` (gitignored). SV testbenches read vectors with `$readmemh` and compare bit-exactly for integer/address data and against tolerance for floating point.

## 4. Assignment schedule

Target dates are suggestions, roughly one per week, skipping the two holiday Fridays. Tracks A (KV cache, memory) and B (math, datapath) can run in parallel, which lines up with the spec's suggested partner split.

| # | Assignment | Track | Milestone | Target |
|---|---|---|---|---|
| 1 | Page Allocator Verification and Repo Cleanup | A | M2 | Fri Nov 27 |
| 2 | KV Address Generator and KV Cache Reference Model | A | M2 | Fri Dec 4 |
| 3 | KV Append Controller | A | M2 | Fri Dec 11 |
| 4 | KV Read Controller and KV Cache Integration | A | M2 exit | Fri Dec 18 |
| 5 | Python Attention Reference Models | B | M3 | Fri Jan 8 |
| 6 | Arithmetic IP Characterization (BF16 array, FP primitives) | B | M1 | Fri Jan 15 |
| 7 | Attention Tile Buffers and Tile Loader | A | M4 | Fri Jan 22 |
| 8 | QK^T Score Engine, Scale and Mask | B | M4 | Fri Jan 29 |
| 9 | Row Max, Exponential, Block Statistics | B | M4 | Fri Feb 5 |
| 10 | Online Softmax State and Output Normalizer | B | M4 | Fri Feb 12 |
| 11 | PV Engine, Output Accumulation, Attention Core Integration | B | M4 exit | Fri Feb 19 |
| 12 | Control Path and Decode Integration | A+B | M5 | Fri Feb 26 |
| 13 | Prefill Scheduler and Prefill Integration | A+B | M6 | Fri Mar 5 |
| 14 | FPGA Deployment | A+B | M7 | Fri Mar 12 |
| 15 | Evaluation and Final Report | A+B | M8 | Fri Mar 19 |

## 5. Open decisions (from spec Appendix C)

1. FPGA board and toolchain (decide by Assignment 14, ideally earlier so BRAM and DSP budgets are known).
2. BF16 array: dimensions, dataflow, accumulator format, handshake (Assignment 6). Note: the earlier TPU project was output-stationary with FP32 accumulation, while the spec PDF says weight-stationary. Settle which one is actually being reused.
3. INT4 array output semantics (optional experiment only).
4. BRAM read-during-write behavior (documented above: old data).
5. K/V layout: decided, see section 1.
6. Page size and page count: decided, 16 and 16.
7. Exponential and reciprocal implementation (Assignments 9 and 10).
8. Numeric tolerances (Assignment 5 sets them, with reasons).
9. Ownership and integration sign-off.

## 6. Note on the earlier chat

The chat "virtual memory and KV Cache" could not be pulled in from here: past-chat search inside a Project only reaches chats that belong to the Project, and that chat lives outside it. To merge it, move that chat into this Project or paste its key parts into a message here.
