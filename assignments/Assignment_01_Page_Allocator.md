# KVP-1 Hardware Design Project
## Paged KV Cache and FlashAttention Accelerator
## Assignment #1: Page Allocator Verification and Repo Cleanup

Milestone M2 (KV cache) | Track A | Target: Friday, Nov 27, 11:59 PM PST

---

### Contents

1. Introduction
2. Setting Up Your Environment
   - 2.1 Repository Layout
   - 2.2 Build Script
3. The Page Allocator
   - 3.1 What It Does
   - 3.2 Interface
   - 3.3 Corner Cases You Must Define
4. Assignment #1
   - 4.1 Files
   - 4.2 Your Task
   - 4.3 Testing Your Implementation
   - 4.4 Submission

---

## 1 Introduction

The KVP-1 KV cache stores each token's key and value vectors in fixed-size pages. A sequence's logical pages (0, 1, 2, ...) are mapped through the page table to physical pages anywhere in the K/V RAMs. The page allocator is the piece that hands out physical pages and remembers which ones are in use.

You already have RTL for the allocator and a first reset test. This assignment finishes verification, closes two correctness holes found in review, and cleans up the repository so every later assignment has a stable place to put RTL, testbenches and Python models.

Read the whole document before starting. Section 3 defines behavior that your testbench must check. Section 4 lists exactly what to turn in.

## 2 Setting Up Your Environment

### 2.1 Repository Layout

Restructure the repo as the spec's Appendix D suggests:

```
KVP-Chip/
  rtl/          synthesizable SystemVerilog only
  tb/           testbenches (*_tb.sv) and tb/vectors/ (generated, gitignored)
  model/        Python golden models
  scripts/      vector generators, run scripts
  docs/         module contracts, layout docs, decision log
  constraints/  FPGA constraints (empty for now)
  extras/       existing notes and diagrams
```

Move the existing `.sv` files into `rtl/` and `tb/`. Add a `.gitignore` containing at least `obj_dir/`, `*.vcd`, `tb/vectors/`, `__pycache__/`. Remove the tracked `obj_dir/` and `dump.vcd` from git with `git rm -r --cached`.

### 2.2 Build Script

Update `build.sh` so it compiles every RTL file plus the one requested testbench:

```
verilator --binary --trace -j 0 rtl/*.sv tb/"$1".sv --top-module "$1"
./obj_dir/V"$1"
```

Confirm all four existing testbenches still build and pass from the new layout:

```
$ ./build.sh kv_block_ram_tb
$ ./build.sh kv_mem_interface_tb
$ ./build.sh page_table_tb
$ ./build.sh page_allocator_tb
```

## 3 The Page Allocator

### 3.1 What It Does

The allocator owns a `NUM_PAGES`-bit `used_map`. Bit `i` is 1 when physical page `i` is allocated. On an allocation request it returns the lowest-numbered free page (a priority encoder over `~used_map`) and marks it used on the next clock edge. On a free it clears the page's bit.

The lowest-index-first policy is part of the contract, not an accident. The Python KV cache model in Assignment 2 will copy it so RTL and model agree page-for-page.

### 3.2 Interface

Keep the existing ports and add the two marked NEW.

| Port | Dir | Width | Description |
|---|---|---|---|
| `clk`, `rst_n` | in | 1 | Clock, synchronous active-low reset. Reset clears `used_map`. |
| `alloc_req` | in | 1 | Request one page this cycle. |
| `alloc_page` | out | `PAGE_W` | Lowest free page. Combinational. Only meaningful when `alloc_ok` is 1. |
| `alloc_ok` | out | 1 | `alloc_req` and a page is free. The page is marked used at the next edge. |
| `alloc_error` | out | 1 | `alloc_req` and the pool is full. No state changes. |
| `free_en` | in | 1 | Return `free_ppage` to the pool. |
| `free_ppage` | in | `PAGE_W` | Page to free. |
| `free_error` | out | 1 | **NEW.** `free_en` asserted for a page that is not currently allocated. No state changes. |
| `num_free` | out | `PAGE_W+1` | **NEW.** Count of free pages (0 to `NUM_PAGES`). Registered or combinational, your choice; document which. |

### 3.3 Corner Cases You Must Define

Write the answer to each of these in a header comment at the top of `rtl/page_allocator.sv`. Your testbench must check every one.

1. **Double free.** Freeing a page whose bit is already 0 asserts `free_error` and leaves `used_map` unchanged. This closes the hole where a same-cycle free of the page being allocated would undo the allocation.
2. **Alloc and free in the same cycle, different pages.** Both take effect.
3. **Alloc while full, free in the same cycle.** Pick one: (a) the request fails this cycle and the requester retries, or (b) the freed page is bypassed straight to the requester. Option (a) is simpler and is what the current RTL does. Either is acceptable if documented and tested.
4. **Allocation order after frees.** After freeing pages 5 and 2, the next two allocations return 2 then 5.
5. **Reset in the middle of activity.** Reset returns `used_map` to all zeros regardless of pending requests.

## 4 Assignment #1

### 4.1 Files

**rtl/page_allocator.sv**: Add `free_error` and `num_free`, gate the free so it only clears a bit that is set, and add the corner-case header comment.

**tb/page_allocator_tb.sv**: Complete the self-checking testbench. Fix the two issues found in review:
- `reset_everything()` currently assigns `alloc_page`, `alloc_ok` and `alloc_error`. These are DUT outputs. Delete those lines; a testbench only drives inputs.
- The PASS/FAIL `$display` calls pass `$time` without a `%0t` in the format string.

**.gitignore, build.sh**: As described in Section 2.

**docs/page_allocator.md**: One-page contract: ports, timing (when is a page considered allocated), the five corner-case policies, and the error behavior.

### 4.2 Your Task

Implement the RTL changes, then write a testbench with a reference model inside it: a `bit [NUM_PAGES-1:0] model_used` that you update in parallel with every request you drive. Every cycle, compare `alloc_ok`, `alloc_error`, `free_error`, `alloc_page` (when `alloc_ok`), `num_free` and `dut.used_map` against the model.

Write it as tasks so tests stay short: `do_alloc(expected_page)`, `do_free(page)`, `do_alloc_and_free(page)`, `check_state()`.

### 4.3 Testing Your Implementation

Your testbench must contain at least these tests, each printing its own PASS/FAIL line:

| Test | Description | Must check |
|---|---|---|
| 1 | Reset | All outputs idle, `used_map == 0`, `num_free == 16` |
| 2 | Allocate 16 in a row | Pages returned 0, 1, ..., 15 in order; `alloc_ok` every cycle |
| 3 | Exhaustion | 17th request: `alloc_error = 1`, `alloc_ok = 0`, `used_map` unchanged |
| 4 | Free one, reallocate | Free page 7 from a full pool, next alloc returns 7 |
| 5 | Lowest-first ordering | Free 5 then 2, next allocs return 2 then 5 |
| 6 | Double free | Free an unallocated page: `free_error = 1`, state unchanged |
| 7 | Same-cycle alloc and free | Different pages: both happen. Same page as the allocated one: no double allocation |
| 8 | Full plus free plus alloc | Behavior matches your Section 3.3 policy |
| 9 | Random stress | 2,000 cycles of random `alloc_req` / `free_en` (free only pages the model says are used, plus ~5% deliberately bad frees). Model must match every cycle. Seed printed at start. |
| 10 | Uniqueness | Across Test 9, the set of currently allocated pages never contains a duplicate (check that every `alloc_page` returned with `alloc_ok` was free in the model) |

End with a single summary line: `ALL TESTS PASSED` or `FAILED: <n> errors`.

Optional but recommended: add an immediate assertion in the RTL (guarded by `` `ifndef SYNTHESIS ``) that `alloc_ok` never fires for a page whose bit is already set.

### 4.4 Submission

To receive full credit you must:

1. Pass all ten tests above with zero errors and no Verilator warnings you have not explained in a comment.
2. Show all four pre-existing testbenches still pass from the new directory layout.
3. Commit `docs/page_allocator.md` with the corner-case policies filled in.
4. Have your partner review the diff before merging. They should be able to answer "what happens if I free a page twice?" from the doc alone.

Tag the commit `a1-page-allocator` when done.
