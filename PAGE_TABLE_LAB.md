# Lab: Build a Page Table in SystemVerilog

**Project:** KVP-1 paged KV cache
**File you'll write:** `page_table.sv`
**File you're given:** `page_table_tb.sv` (the testbench, don't edit it)
**Time:** about 1 to 2 hours

---

## What you're building

The KV cache stores each token's K and V vectors in RAM. We don't store tokens in one long line. We chop them into **pages** of 16 tokens, and each page can sit anywhere in RAM.

So we need a little lookup list that says where each page actually ended up:

```
 logical page  ->  physical page (where it really is in RAM)
      0        ->        7
      1        ->        2
      2        ->        9
      3        ->     (not filled in yet)
```

That list is the **page table**. It's the same idea as a page table in an operating system, just small enough to build out of flip-flops.

Our table has **16 slots**, one per logical page. Each slot holds two things:

| Field | Width | Meaning |
|---|---|---|
| `ppage` | 4 bits | Which physical page this logical page lives in (0 to 15) |
| `valid` | 1 bit | 1 = this slot has been filled in, 0 = ignore it |

### The three jobs

1. **Lookup.** Someone gives us a logical page number. We immediately answer with its physical page and its valid bit. No clock, no waiting.
2. **Write.** When `wr_en` is 1, at the next rising clock edge, we store a physical page number in a slot and mark that slot valid.
3. **Reset.** When `rst_n` is 0, every slot becomes invalid.

That's the whole module. When you're done it'll be about 15 lines of real code.

---

## Part 0: Setup

You need these two files in the same folder:

- `page_table.sv` (already in the repo, it has the ports but no logic)
- `page_table_tb.sv` (the testbench)

To build and run:

```bash
verilator --binary --trace -j 0 page_table.sv page_table_tb.sv --top-module page_table_tb
./obj_dir/Vpage_table_tb
```

To look at waveforms afterward:

```bash
surfer dump.vcd
```

Each test prints `PASS` or `FAIL`. Your goal is `ALL TESTS PASSED`.

---

## Part 1: SystemVerilog crash course

Read this once before starting. It covers only what you need for this lab. The examples here are deliberately about *other* circuits, so you still get to figure out the page table yourself.

### 1.1 Hardware, not a program

SystemVerilog describes **circuits**, not steps that run in order. Every line describes a wire or a register that exists all the time. Keep that in mind when something "runs twice" or "runs at the same time." It's all happening at once.

### 1.2 `logic` and widths

`logic` is a wire or a register. The number in brackets is how many bits wide it is.

```systemverilog
logic        flag;        // 1 bit
logic [3:0]  nibble;      // 4 bits, bit 3 is the top, bit 0 is the bottom
logic [7:0]  byte_val;    // 8 bits
```

`[3:0]` means 4 bits because it counts 3, 2, 1, 0.

### 1.3 Parameters

A parameter is a named constant you can change when the module is used. It saves you from hardcoding numbers everywhere.

```systemverilog
module counter #(
    parameter int WIDTH = 8
)( ... );
    logic [WIDTH-1:0] count;   // 8 bits wide by default
```

`$clog2(N)` gives the number of bits needed to count to N-1. `$clog2(16)` is 4, because 4 bits can hold 0 to 15.

### 1.4 Arrays

You can have many `logic` values in a row. The size after the name says how many.

```systemverilog
logic [7:0] scores [10];      // 10 entries, each 8 bits
logic [9:0] seen;             // also fine: 10 single bits packed together
```

You read and write them with an index, and **the index can be a signal**:

```systemverilog
scores[3]       // entry 3
scores[player]  // whichever entry "player" points at
seen[player]    // one bit
```

### 1.5 `assign`: combinational logic

`assign` is a permanent wire connection. Whenever the right side changes, the left side changes instantly. No clock involved.

```systemverilog
assign is_zero  = (count == 0);
assign my_score = scores[player];   // reads an array, updates instantly
```

### 1.6 `always_ff`: registers

Anything that should **remember** a value and only change on the clock goes in an `always_ff` block.

```systemverilog
always_ff @(posedge clk) begin
    if (!rst_n) begin
        count <= '0;              // reset
    end else if (enable) begin
        count <= count + 1;       // only changes when enable is 1
    end
end
```

Things to notice:

- `@(posedge clk)` means "only on the rising edge of the clock."
- `rst_n` is **active low**: the `_n` means 0 = reset. So `if (!rst_n)` means "if we're in reset."
- Use `<=` (nonblocking) inside `always_ff`. Always. Never `=`.
- `'0` means "all zeros, whatever the width is." `'1` means all ones.
- If nothing in the `if` matches, the register just keeps its old value. You don't have to write an `else` for that.

### 1.7 Writing to one array entry

You can update a single entry of an array in `always_ff`:

```systemverilog
always_ff @(posedge clk) begin
    if (save) begin
        scores[player] <= new_score;   // only that one entry changes
    end
end
```

Every other entry keeps its old value.

---

## Part 2: The lab

Open `page_table.sv`. You'll fill it in step by step. After each step, run the build command. It's fine if tests fail early on. The point of each checkpoint is that it **compiles**.

### Step 1: Fix the parameters

The file currently has `WORD_W`, `DEPTH` and `ADDR_W`. Those belong to the RAM and mean nothing here.

**Your task:**
- Replace them with two parameters:
  - `NUM_PAGES`, default 16
  - `PAGE_W`, default `$clog2(NUM_PAGES)`
- Change every `[3:0]` in the port list to `[PAGE_W-1:0]`.

**Why:** if someone later wants 32 pages, they change one number and everything else still works.

**Checkpoint:** run the build. It should compile. (Tests will fail, that's expected.)

---

### Step 2: Declare the storage

The page table needs to remember two things for every slot.

**Your task:** inside the module, below the port list, declare:
- An array that holds `NUM_PAGES` entries, each `PAGE_W` bits wide. This holds the physical page numbers. Name it something like `ppage_table`.
- A `NUM_PAGES`-bit signal that holds one valid bit per slot. Name it something like `valid_bits`.

Look back at section 1.4 if you're stuck on the syntax.

**Why two separate things:** reset only needs to clear the valid bits. Keeping them separate means reset is one line.

**Checkpoint:** it should still compile.

---

### Step 3: The lookup (combinational)

This is the "answer instantly" part.

**Your task:** write two `assign` statements:
- `lookup_p_page` should be the entry of your ppage array at index `lookup_l_page`.
- `lookup_valid` should be the bit of your valid signal at index `lookup_l_page`.

Look back at section 1.5.

**Checkpoint:** compile and run. Test 1 might pass or fail depending on what the simulator puts in the valid bits at startup. That's fine, you haven't written reset yet.

---

### Step 4: Write and reset (sequential)

This is the only part with a clock.

**Your task:** write one `always_ff @(posedge clk)` block that does this:

- **If in reset** (`rst_n` is 0): set every valid bit to 0.
- **Otherwise, if `wr_en` is 1:**
  - store `wr_ppage` into your ppage array at index `wr_lpage`
  - set the valid bit at index `wr_lpage` to 1

Sections 1.6 and 1.7 have everything you need.

**Things to get right:**
- Use `<=`, not `=`.
- Don't reset the ppage array. Only the valid bits. (Ask yourself why that's safe.)
- When `wr_en` is 0, nothing should change.

**Checkpoint:** compile and run. If you got everything right, you'll see:

```
PASS  Test 1: after reset every page is invalid
PASS  Test 2: write [7, 2, 9] and read it back
PASS  Test 3: unwritten pages stay invalid
PASS  Test 4: overwrite page 1 with 5
PASS  Test 5: no write when wr_en is 0
PASS  Test 6: fill all 16 slots
PASS  Test 7: reset makes every page invalid again
-----------------------------
ALL TESTS PASSED
```

---

### Step 5: Look at the waveform

Passing tests is great, but you should also *see* it working.

```bash
surfer dump.vcd
```

Add these signals: `clk`, `rst_n`, `wr_en`, `wr_lpage`, `wr_ppage`, `lookup_l_page`, `lookup_p_page`, `lookup_valid`. Also expand `dut` and add your `valid_bits`.

**Find and screenshot these moments:**
1. The clock edge where slot 0 gets written with 7. Watch `valid_bits` bit 0 flip from 0 to 1 **on the edge**, not before.
2. A lookup. Change of `lookup_l_page` should change `lookup_p_page` **right away**, not on a clock edge.
3. The reset in Test 7. Every bit of `valid_bits` should drop to 0.

Moment 1 vs moment 2 is the whole difference between `always_ff` and `assign`.

---

## If a test fails

| Failing test | Most likely cause |
|---|---|
| Test 1 or 7 | Reset isn't clearing the valid bits, or you checked `rst_n` instead of `!rst_n` |
| Test 2 | The write isn't storing at `wr_lpage`, or the lookup isn't indexing with `lookup_l_page` |
| Test 2 shows p_page = the logical page number | Your lookup is returning `lookup_l_page` itself instead of reading the array |
| Test 3 | Writing is setting more than one valid bit |
| Test 4 | Overwriting doesn't work, maybe you only write when the slot is invalid |
| Test 5 | You're writing even when `wr_en` is 0 |
| Won't compile, "blocking and nonblocking" | You used `=` somewhere in `always_ff` |
| Won't compile, width warnings | A port still says `[3:0]`, or a size doesn't match `PAGE_W` |

The testbench prints exactly which lookup failed and what it expected, so read the `FAIL:` lines.

---

## Questions to answer when you're done

Write short answers at the bottom of `page_table.sv` as comments.

1. Why is it safe to **not** reset the ppage array?
2. The lookup has no clock. What would change for whoever uses this module if the lookup were inside `always_ff` instead?
3. How many flip-flops does your page table use in total? (Hint: 16 slots, and what's in each one?)
4. The testbench writes physical pages 7, 2, 9 instead of 0, 1, 2. What kind of bug would 0, 1, 2 fail to catch?
5. If we wanted 64 pages instead of 16, what would you change in your code?

---

## How this fits into the project

```
kv_append_ctrl  --asks for a page-->  page_allocator
      |                                    |
      |  <---------- gets ppage -----------
      |
      +--writes {lpage -> ppage}-->  page_table  <--looks up--  kv_read_ctrl
                                                                     |
                                       kv_address_gen  <--- ppage ---+
                                             |
                                    RAM row = {ppage, slot}
                                             |
                                      kv_mem_interface
```

When a sequence fills up a page, the append controller gets a fresh physical page from the allocator and **writes** it into your table. When the read controller wants token 37, it computes logical page 2, **looks it up** in your table, gets physical page 9, and reads from there.

Your module is the translation step in the middle of all of that.

---

<details>
<summary><b>Answer key (only open after you've tried)</b></summary>

```systemverilog
`timescale 1ns/1ps
module page_table #(
    parameter int NUM_PAGES = 16,
    parameter int PAGE_W    = $clog2(NUM_PAGES)
)(
    input  logic              clk, rst_n,

    input  logic [PAGE_W-1:0] lookup_l_page,
    output logic [PAGE_W-1:0] lookup_p_page,
    output logic              lookup_valid,

    input  logic              wr_en,
    input  logic [PAGE_W-1:0] wr_lpage,
    input  logic [PAGE_W-1:0] wr_ppage
);

    // Step 2: storage
    logic [PAGE_W-1:0]    ppage_table [NUM_PAGES];
    logic [NUM_PAGES-1:0] valid_bits;

    // Step 4: write and reset
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            valid_bits <= '0;
        end else if (wr_en) begin
            ppage_table[wr_lpage] <= wr_ppage;
            valid_bits[wr_lpage]  <= 1'b1;
        end
    end

    // Step 3: lookup
    assign lookup_p_page = ppage_table[lookup_l_page];
    assign lookup_valid  = valid_bits[lookup_l_page];

endmodule
```

**Question answers:**
1. Anyone using the table checks `lookup_valid` first. If valid is 0, the ppage value is ignored, so it doesn't matter what junk is in there.
2. The answer would come back one clock cycle later, so every module that does a lookup would have to wait a cycle and track that.
3. 16 × (4 + 1) = 80 flip-flops.
4. A lookup that accidentally returns the logical page number instead of the stored physical page. With 0, 1, 2 those are the same numbers, so the bug would pass.
5. Just change `NUM_PAGES` to 64. `PAGE_W` becomes 6 automatically. (The RAM and address generator would also need to grow, but this module needs no edits.)

</details>
