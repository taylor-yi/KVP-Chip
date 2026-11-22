# KVP-1 Hardware Design Project
## Paged KV Cache and FlashAttention Accelerator
## Assignment #2: KV Address Generator and KV Cache Reference Model

Milestone M2 (KV cache) | Track A | Target: Friday, Dec 4, 11:59 PM PST

---

### Contents

1. Introduction
2. Setting Up Your Environment
3. Address Translation in the KV Cache
   - 3.1 The Memory Layout
   - 3.2 The Address Generator
   - 3.3 The Python Reference Model
   - 3.4 Python-to-SystemVerilog Test Flow
4. Assignment #2
   - 4.1 Files
   - 4.2 Your Task
   - 4.3 Testing Your Implementation
   - 4.4 Submission

---

## 1 Introduction

So far the KV cache has storage (`kv_block_ram`, `kv_mem_interface`) and bookkeeping (`page_table`, `page_allocator`), but nothing that turns "token 37 of this sequence" into "RAM address 0x55". This assignment builds that translation in RTL and builds the Python golden model that every remaining KV cache assignment will be checked against.

The assignment has two halves that are deliberately paired. The address generator is small and almost entirely combinational, which makes it a good place to set up the Python-generates-vectors, SystemVerilog-checks-them flow you will reuse for the rest of the project.

## 2 Setting Up Your Environment

Pull the `a1-page-allocator` tag. You need Python 3.10 or newer with `numpy` and `pytest`:

```
$ python3 -m venv .venv
$ source .venv/bin/activate
$ pip install numpy pytest
$ pip freeze > requirements.txt
```

Commit `requirements.txt`. Activate the venv in every new terminal.

## 3 Address Translation in the KV Cache

### 3.1 The Memory Layout

The layout is fixed by the frozen design point (see `00_Project_Overview_and_Status`):

- One token's key vector is 16 BF16 elements = one 256-bit word. Same for the value vector.
- Keys and values live in separate RAMs at the **same address**, so the K/V selector is not an address bit.
- A page holds 16 tokens. Physical page `p` occupies RAM words `16p` through `16p + 15`.
- For logical token `t`:

```
logical_page   = t / PAGE_SIZE   = t[7:4]
offset_in_page = t % PAGE_SIZE   = t[3:0]
physical_page  = page_table[logical_page]
address        = physical_page * PAGE_SIZE + offset = {physical_page, offset}
```

- Element `i` of a vector sits at bits `[16*i +: 16]`.

Because the head count is 1 and K/V are banked, the spec's general address (page base + offset + head + K/V bank + element) collapses to `{ppage, offset}`. Write the general form in the doc anyway and show which fields are zero-width today, so adding heads later is a documented change, not a redesign.

### 3.2 The Address Generator

`kv_address_gen` is combinational. It splits a token index, asks the page table for the physical page, and assembles the address.

| Port | Dir | Width | Description |
|---|---|---|---|
| `token_idx` | in | `TOK_W` | Logical token position |
| `lpage` | out | `PAGE_W` | Logical page, drives `page_table.lookup_l_page` |
| `ppage` | in | `PAGE_W` | From `page_table.lookup_p_page` |
| `ppage_valid` | in | 1 | From `page_table.lookup_valid` |
| `addr` | out | `ADDR_W` | `{ppage, offset}` |
| `addr_valid` | out | 1 | `ppage_valid`. When 0, `addr` must not be used. |
| `page_first` | out | 1 | `offset == 0`. Append controller uses this to know a new page is needed. |
| `page_last` | out | 1 | `offset == PAGE_SIZE - 1` |

Parameters: `NUM_PAGES = 16`, `PAGE_SIZE = 16`, derived `PAGE_W`, `OFF_W = $clog2(PAGE_SIZE)`, `TOK_W = PAGE_W + OFF_W`, `ADDR_W = PAGE_W + OFF_W`.

Add an elaboration-time check that `PAGE_SIZE` is a power of two (a generate-if with `$error`), since the bit-slicing depends on it.

The address generator has no clock. It does not check `token_idx < seq_len`; range checking belongs to the append and read controllers, which know the sequence length. Write that boundary into the doc so nobody assumes otherwise.

### 3.3 The Python Reference Model

`model/kv_cache_model.py` defines a class that behaves like the whole KV cache subsystem at the transaction level. It must mirror the RTL policies exactly, including lowest-index-first allocation.

```python
class KVCacheModel:
    def __init__(self, num_pages=16, page_size=16): ...
    # allocator
    def alloc(self) -> int | None        # lowest free page, None if full
    def free(self, ppage) -> bool        # False on double free
    # page table
    def map(self, lpage, ppage): ...
    def lookup(self, lpage) -> int | None  # None if invalid
    # cache operations
    def append(self, k: int, v: int) -> bool   # k, v are 256-bit ints
    def read(self, start: int, count: int) -> list[tuple[int, int]] | None
    def address(self, token) -> int | None
    @property
    def seq_len(self) -> int
```

Rules the model must enforce, matching REQ-KV-01 to REQ-KV-07:

- `append` allocates a new page only when `seq_len % page_size == 0`. On allocation failure it returns `False` and changes nothing (REQ-KV-04).
- `seq_len` increments only after both K and V are stored (REQ-KV-02).
- `read` returns `None` if `start + count > seq_len` or any page in range is unmapped (REQ-KV-05). `count == 0` returns an empty list.
- Storage is a dict or array keyed by physical address, so a bad mapping in a test produces visibly wrong data instead of silently working.

Add a `reserve(ppage)` helper that marks a physical page used without mapping it. Assignment 4 uses this to force non-contiguous physical layouts.

### 3.4 Python-to-SystemVerilog Test Flow

This is the pattern for the rest of the project:

1. A script in `scripts/` builds a scenario using the model and writes hex files to `tb/vectors/<test_name>/`, one value per line.
2. The SV testbench loads them with `$readmemh` and drives / checks the DUT.
3. A small `scripts/run_test.sh <tb> <gen_script>` runs the generator, then `build.sh`.

Use a fixed default seed and accept `--seed` on the command line. Print the seed in both Python and SV output.

## 4 Assignment #2

### 4.1 Files

**rtl/kv_address_gen.sv**: The module in Section 3.2.

**tb/kv_address_gen_tb.sv**: Self-checking testbench. Instantiates `page_table` and `kv_address_gen` together, programs the page table, then sweeps tokens.

**model/kv_cache_model.py**: The class in Section 3.3.

**model/test_kv_cache_model.py**: pytest tests for the model itself.

**scripts/gen_addr_vectors.py**: Writes a random permutation page table and the expected `(token, lpage, addr, page_first, page_last)` for all 256 tokens.

**scripts/run_test.sh**: Generator + build + run in one command.

**docs/kv_layout.md**: Address formula, lane order, K/V banking, address units (words, not bytes), read latency of `kv_mem_interface` (1 cycle after accept), read-during-write behavior, and the "address gen does not range check" boundary. This doc satisfies REQ-KV-06.

### 4.2 Your Task

Write the address generator, the model and the vector flow. The model is the more important half: the next two assignments are graded against it.

Test the model before trusting it. A model with a bug produces vectors that agree with RTL that has the same bug.

### 4.3 Testing Your Implementation

**Model tests (pytest), at minimum:**

| Test | Description |
|---|---|
| append_first | First append allocates page 0, `seq_len == 1` |
| append_same_page | 16 appends use one page |
| append_cross_page | 17th append allocates a second page |
| fill_to_capacity | 256 appends succeed, 257th returns `False`, data unchanged |
| read_roundtrip | Random appends, `read(0, seq_len)` returns them in order |
| read_cross_boundary | `read(10, 12)` spans pages 0 and 1, correct order |
| read_out_of_range | `read(start, count)` past `seq_len` returns `None` |
| reserve_scatter | Reserve pages 0, 2, 4, then append 48 tokens: physical pages are 1, 3, 5 |
| double_free | `free` on a free page returns `False` |

**RTL tests:**

| Test | Description | Must check |
|---|---|---|
| 1 | Identity page table | `addr == token` for all 256 tokens |
| 2 | Reversed table (lpage i to ppage 15-i) | All 256 tokens against Python vectors |
| 3 | Random permutation | All 256 tokens against Python vectors, seed printed |
| 4 | Unmapped page | After reset with only page 0 mapped, tokens 16 to 255 give `addr_valid = 0` |
| 5 | Flags | `page_first` exactly at offsets 0, `page_last` exactly at offsets 15 |

Address checks are bit-exact. Any mismatch is an error.

### 4.4 Submission

To receive full credit you must:

1. Pass every pytest and all five RTL tests via `scripts/run_test.sh`.
2. Commit `docs/kv_layout.md`. Your partner should be able to compute the RAM address of token 200 given a page table, from the doc alone.
3. Run Test 3 with three different seeds and paste the passing output in the PR description.

Tag the commit `a2-addr-gen`.
