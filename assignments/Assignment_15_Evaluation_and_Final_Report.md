# KVP-1 Hardware Design Project
## Paged KV Cache and FlashAttention Accelerator
## Assignment #15: Evaluation and Final Report

Milestone M8 (evaluation) | Tracks A+B | Target: Friday, Mar 19, 11:59 PM PST

---

### Contents

1. Introduction
2. Setting Up Your Environment
3. What to Measure
   - 3.1 Performance Counters
   - 3.2 Metrics
   - 3.3 Comparison Experiments
4. Assignment #15
   - 4.1 Files
   - 4.2 Your Task
   - 4.3 Checking Your Results
   - 4.4 Submission

---

## 1 Introduction

A working demo shows the design is correct. This assignment shows what it costs and what it buys: latency, throughput, memory traffic, resources, timing and numerical quality, plus the controlled comparisons the spec asks for. It ends with the final technical report and demo.

The spec's tone applies here more than anywhere: report measured numbers, state limitations plainly, and do not claim GPU-class performance or general speedups. A clear account of where the bottleneck is (it should be KV read bandwidth during decode, about one token per two cycles through `kv_mem_interface`) is a better result than an inflated number.

## 2 Setting Up Your Environment

Pull `a14-fpga`. All experiments must be reproducible from scripts: one command per experiment, raw results written to `results/<experiment>/` as CSV, plots generated from the CSV by a separate script. Never hand-edit a results file.

## 3 What to Measure

### 3.1 Performance Counters

Add `rtl/perf_counters.sv`, readable through `config_regs`, cleared on `start`:

| Counter | Counts |
|---|---|
| `CYC_TOTAL` | Cycles from accepted start to done (already exists as `CYCLES`) |
| `CYC_APPEND`, `CYC_KV_READ`, `CYC_QK`, `CYC_STATS`, `CYC_PV`, `CYC_NORM`, `CYC_HOST_WAIT` | Cycles the controller spends in each phase |
| `KV_WORDS_WR` | 256-bit words written to K/V RAMs (each append writes 2: one K, one V) |
| `KV_WORDS_RD` | Words read from K/V RAMs |
| `TILES` | KV tiles processed |
| `PAGES_TOUCHED` | Distinct physical pages read |

These cost a few hundred flip-flops. Guard them with a parameter so they can be removed for a resource comparison.

### 3.2 Metrics

From spec Section 29. Report each for decode and prefill.

| Metric | How |
|---|---|
| Latency | `CYC_TOTAL` vs context length (decode) and prompt length (prefill), converted to time at the achieved clock |
| Throughput | Decode tokens per second; prefill query rows per second |
| Memory traffic | Bytes read and written per operation from the counters |
| Score traffic avoided | Bytes a conventional implementation would write and read to materialize the score matrix (`Lq x Lk x 4` bytes each way in FP32), compared with the tiled design's zero off-chip score traffic and its fixed on-chip score buffer |
| Cache efficiency | Useful K/V bytes (tokens actually in range x 64 bytes) over physical bytes read. Should be 100% in this design; explain why (word-per-token layout, no partial bursts) |
| Resources | LUT, FF, DSP, BRAM from the implementation report, broken down by subsystem where the tool allows |
| Timing | Achieved clock, WNS, critical path |
| Numerical quality | Max abs, max rel, RMS error vs FP64 over a fixed suite of 1,000 random cases, and the breakdown of error sources |

### 3.3 Comparison Experiments

From spec Section 30. Do at least the first four.

1. **Conventional vs tiled online-softmax.** Using the Python models: show identical outputs within tolerance, and tabulate intermediate storage and traffic for both as a function of sequence length.
2. **Contiguous vs paged layout.** Run decode with no reservations (pages land contiguous) and with scattered reservations. Compare cycles, address-generation logic cost (from synthesis of `kv_address_gen` + `page_table` vs a plain counter), and read efficiency. Expected result: identical cycles in this design, small logic cost. Say what would change with burst-based external memory, where non-contiguous pages break bursts.
3. **KV tile size.** Rebuild with `Bc` = 8 and 32 (if the buffers parameterize cleanly; if not, report what blocked it). Compare buffer footprint, cycles per decode step, and tiles per context.
4. **Causal skip.** Prefill cycles with `CAUSAL_SKIP` = 1 vs 0 from Assignment 13, across prompt lengths. Should approach a 2x saving for long prompts.
5. **Sequence length scaling.** Decode latency from context 1 to 256. Identify the per-token slope and which phase dominates. Estimate the slope with a pipelined read controller (Extension) from the counters.
6. **BF16 vs INT4 (optional).** Only if the INT4 array was characterized in Assignment 6. Define the quantization scheme first; compare resources, latency and output error.

## 4 Assignment #15

### 4.1 Files

**rtl/perf_counters.sv**, updated **rtl/config_regs.sv**.

**scripts/experiments/*.py**: One script per experiment, writing CSV.

**scripts/plots/*.py**: One script per figure.

**results/**: Raw CSVs.

**docs/final_report.md** (or LaTeX): The final technical report.

### 4.2 Your Task

Run the experiments and write the report. Suggested report structure:

1. Introduction and goals
2. Background: attention, KV caching, paged storage, online softmax (short; cite the FlashAttention and PagedAttention papers)
3. Architecture: block diagram, subsystem descriptions, interfaces
4. Numerics: formats, exponential and reciprocal design, tolerance study
5. Verification: methodology, Python models, test matrix with pass status for every assignment
6. Implementation: board, resources, timing
7. Results: every metric and experiment above, with plots
8. Limitations: single head, single sequence, 256-token context, BRAM-only storage, one read in flight, decode under-uses the 4x4 array. State them plainly
9. Future work: multi-sequence with page reclamation and prefix sharing, external DDR with burst-aware paging, pipelined cache reads, double-buffered tiles, dedicated decode dot-product engine, multi-head
10. Individual contributions

Also deliver the spec's final items (Section 33): a short live or recorded demo showing both prefill and decode, and a README at the repo root explaining how to rebuild everything. (The current README is a placeholder.)

### 4.3 Checking Your Results

Before writing conclusions, check each number:

- Recompute a few counter values by hand from the design (for example, `KV_WORDS_RD` for a 40-token decode should be 80: 40 K words + 40 V words).
- Confirm latency scales the way the architecture predicts. If decode cycles per 16 tokens differ from (KV read cycles per tile + compute cycles per tile) by more than a few percent, find out why.
- Re-derive the score-traffic-avoided numbers from the formula, not from a spreadsheet you typed.
- Every plot is regenerated from CSV by script on a clean checkout.

### 4.4 Submission

To receive full credit you must:

1. Commit all experiment scripts, raw CSVs, plot scripts and the final report.
2. Reproduce one experiment end to end from a clean clone in front of your partner.
3. Record the demo.
4. Replace the README with real build and run instructions.

Tag the commit `v1.0`. This closes milestone M8 and the project.
