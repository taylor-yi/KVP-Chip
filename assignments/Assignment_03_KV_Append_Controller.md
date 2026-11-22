# KVP-1 Hardware Design Project
## Paged KV Cache and FlashAttention Accelerator
## Assignment #3: KV Append Controller

Milestone M2 (KV cache) | Track A | Target: Friday, Dec 11, 11:59 PM PST

---

### Contents

1. Introduction
2. Setting Up Your Environment
3. Appending a Token
   - 3.1 The Append Transaction
   - 3.2 Interface
   - 3.3 State Machine
   - 3.4 Error Behavior
4. Assignment #3
   - 4.1 Files
   - 4.2 Your Task
   - 4.3 Testing Your Implementation
   - 4.4 Submission

---

## 1 Introduction

During decode, every generated token produces a new key vector and a new value vector. The append controller writes them to the next logical position in the sequence. When that position is the first slot of a new page, it must allocate a physical page and record the mapping before writing.

This is the first module in the project that coordinates other modules: the allocator, the page table, the address generator and the memory interface. Most of the bugs you will hit are ordering bugs (writing before the mapping exists, bumping the length before the write lands). The spec's requirements here are short but strict, so read Section 3.4 carefully.

## 2 Setting Up Your Environment

Pull `a2-addr-gen`. The append controller does not instantiate the modules it controls; it talks to them through ports. Your testbench instantiates the controller plus `page_allocator`, `page_table`, `kv_address_gen` and `kv_mem_interface`, wired together. This is a preview of `kv_cache_top` in Assignment 4. Put that wiring in a reusable `tb/kv_append_harness.sv` so Assignment 4 can borrow it.

## 3 Appending a Token

### 3.1 The Append Transaction

Given new vectors `k_new`, `v_new` and the current length `L`:

1. If `L == MAX_TOKENS` (256), fail with an error.
2. Let `lpage = L / 16`, `offset = L % 16`.
3. If `offset == 0`: request a page from the allocator. If allocation fails, fail with an error. Otherwise write `page_table[lpage] = new_page`.
4. Look up `ppage = page_table[lpage]` and form `addr = {ppage, offset}`.
5. Issue one write request to `kv_mem_interface` carrying both `k_new` and `v_new`.
6. When the write is accepted (`req_valid && req_ready`), set `L = L + 1` and pulse `append_done`.

Step 6 is the REQ-KV-01 / REQ-KV-02 guarantee: the logical length only covers tokens whose K and V are both in memory.

### 3.2 Interface

| Port | Dir | Width | Description |
|---|---|---|---|
| `clk`, `rst_n` | in | 1 | Reset clears `seq_len` to 0 and the FSM to IDLE |
| **Command** | | | |
| `append_valid` | in | 1 | Request an append |
| `append_ready` | out | 1 | High only in IDLE |
| `append_k`, `append_v` | in | `WORD_W` | Captured on accept |
| `append_done` | out | 1 | One-cycle pulse when the token is committed |
| `append_error` | out | 1 | One-cycle pulse instead of `append_done` on failure |
| `seq_len` | out | `TOK_W+1` | Current committed length, 0 to 256 |
| `seq_clear` | in | 1 | Synchronous: set `seq_len = 0` (does not free pages; see Extension) |
| **Allocator** | | | |
| `alloc_req` | out | 1 | |
| `alloc_page`, `alloc_ok`, `alloc_error` | in | | |
| **Page table** | | | |
| `pt_wr_en`, `pt_wr_lpage`, `pt_wr_ppage` | out | | |
| **Address gen** | | | |
| `ag_token_idx` | out | `TOK_W` | Drive with `seq_len[TOK_W-1:0]` |
| `ag_addr`, `ag_addr_valid`, `ag_page_first` | in | | |
| **Memory** | | | |
| `mem_req_valid`, `mem_req_write` | out | 1 | `mem_req_write` is always 1 from this module |
| `mem_req_addr` | out | `ADDR_W` | |
| `mem_req_data_k`, `mem_req_data_v` | out | `WORD_W` | |
| `mem_req_ready` | in | 1 | |

Capture `append_k` / `append_v` into registers on accept. Do not rely on the requester holding them.

### 3.3 State Machine

A suggested FSM. You may merge states if you can justify it in the doc.

```
IDLE  --append_valid & full------------------> ERR
IDLE  --append_valid & page_first------------> ALLOC
IDLE  --append_valid & !page_first-----------> WRITE
ALLOC --alloc_ok (pt_wr_en this cycle)-------> MAP_WAIT
ALLOC --alloc_error--------------------------> ERR
MAP_WAIT -----------------------------------> WRITE   (page table write now visible)
WRITE --mem_req_ready (write accepted)-------> DONE   (seq_len++)
DONE  -----------------------------------> IDLE   (append_done pulse)
ERR   -----------------------------------> IDLE   (append_error pulse)
```

`MAP_WAIT` exists because `page_table` makes a write visible to lookups on the next cycle (see the overview's review notes). If you can prove the lookup path is not used in the same cycle as the write, you may remove it, but say so in the doc.

Record in the doc how many cycles an append takes in each case (new page vs same page) assuming `mem_req_ready` is high. You will report these numbers in Assignment 15.

### 3.4 Error Behavior

- **Full sequence** (`seq_len == 256`): `append_error`, no allocation, no page table write, no memory write.
- **Allocator exhausted** (possible once Assignment 4 adds reserved pages): `append_error`, no page table write, no memory write, `seq_len` unchanged. Existing mappings untouched (REQ-KV-04).
- **Command while busy**: `append_ready` is low, so the requester must wait. Assert in the testbench that the controller never accepts while not in IDLE.
- **seq_clear while busy**: Prohibited. Add an assertion and document it.

Extension (not required): on `seq_clear`, walk the page table and free every mapped page.

## 4 Assignment #3

### 4.1 Files

**rtl/kv_append_ctrl.sv**: The controller.

**tb/kv_append_harness.sv**: Wires controller + allocator + page table + address gen + memory interface.

**tb/kv_append_ctrl_tb.sv**: Self-checking testbench using the harness.

**scripts/gen_append_vectors.py**: Uses `KVCacheModel` to produce a sequence of random K/V words and, after each append, the expected `seq_len`, expected physical address, and expected allocation event. Add a `clear()` method to `KVCacheModel` that matches `seq_clear` (length to 0, pages stay allocated, old page table entries stay until a new allocation overwrites them; reads are blocked by the length check, not by valid bits).

**docs/kv_append_ctrl.md**: FSM diagram, cycle counts, error table, assumptions about neighbors.

### 4.2 Your Task

Implement the controller and test it in the harness. After each append, the testbench checks the controller's outputs and reads back RAM contents directly through hierarchical references (for example `harness.mem.k_ram.mem[addr]`) to confirm the right data landed at the right address. Reading memory via the back door is fine here; Assignment 4 does it properly through the read path.

Insert random stalls on `mem_req_ready` by wrapping `kv_mem_interface` in the harness with a stall injector, or by adding a `tb_stall` input that forces `req_ready` low. The controller must hold its request stable while stalled.

### 4.3 Testing Your Implementation

| Test | Description | Must check |
|---|---|---|
| 1 | First append | Page 0 allocated, mapping 0 to 0 written, data at address 0, `seq_len == 1` |
| 2 | Same-page appends | Tokens 1 to 15: no further allocations, addresses 1 to 15 |
| 3 | Page crossing | Token 16 allocates page 1, data at address 16 |
| 4 | Fill to 256 | All 256 succeed, every RAM word matches Python vectors |
| 5 | Over capacity | 257th append: `append_error`, `seq_len` stays 256, RAM unchanged (compare full RAM snapshot) |
| 6 | Memory stalls | Random `mem_req_ready` low for 0 to 5 cycles per append; data and length still correct |
| 7 | seq_len timing | `seq_len` does not change until the cycle after the write handshake |
| 8 | Busy rejection | `append_valid` held high back-to-back: each token appended exactly once |
| 9 | Clear and refill | From reset, append 20 tokens, `seq_clear`, append 20 more: writes go to logical page 0 again |

Note on Test 9: without the Extension, the old pages stay allocated, so the refill gets new physical pages (2 and 3, not 0 and 1). That is expected; check that the new pages match what the model predicts after the same clear. Run it from reset, since after Test 5 every page is in use and the refill would fail.

### 4.4 Submission

To receive full credit you must:

1. Pass all nine tests with zero errors.
2. Show that the controller never drives `pt_wr_en` and `mem_req_valid` for a new page in the same cycle (assertion in the testbench).
3. Commit the doc with measured cycle counts for a same-page append and a new-page append.

Tag the commit `a3-append`.
