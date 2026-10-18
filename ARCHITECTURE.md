# Agent Inference Chip — System Architecture Proposal

*Working name: **KVP-1** ("KV-cache Paged, 1st gen"). Status: digital-design /
architecture exploration. The `rtl/` PoC implements the shaded blocks.*

---

## 1. Design targets

- **Primary workload**: autoregressive decode for agentic loops (many
  concurrent agents, long growing contexts, frequent tool-call stalls).
- **Primary metric**: tokens/sec/agent at fixed power; secondary: agents/chip
  (context-switch cost ≈ 0).
- **Non-goals for gen-1**: training, prefill throughput records (GPUs keep
  that), non-transformer architectures.

## 2. Top-level block diagram

```
                         +-------------------------+
                         |   RISC-V control core   |  <-- driver, scheduler,
                         |  (scheduler + paging)   |      block allocator
                         +------------+------------+
                                      | config / page tables
     +--------------------------------+----------------------------------+
     |                                 TILE (x N tiles)                  |
     |  +----------------+  +------------------+  +------------------+   |
  HBM|  | Context-switch |  |  Attention tile  |  |  FFN / vector    |   |
<--->|  | engine         |  |  (QK^T + softmax |  |  tile (systolic  |   |
     |  | - 64 page      |  |   + AV, streaming)|  |   MAC array)     |   |
     |  |   tables       |  +--------+---------+  +--------+---------+   |
     |  | - block alloc  |           |                   |              |
     |  | - prefetcher   |  +--------v-------------------+              |
     |  +-------+--------+  |  Banked KV SRAM            |              |
     |          |           |  (hot blocks, paged)       |              |
     |          +---------->|  + HBM spill (cold blocks) |              |
     |                      +----------------------------+              |
     +-----------------------------------------------------------------+
```

Data path per decode step: control core selects agent → **context-switch
engine swaps the active page table (1 cycle)** → attention tile streams the
agent's K/V blocks from SRAM (spilling to HBM on miss, prefetched on switch)
→ FFN tile → next token.

## 3. Memory hierarchy (the actual product)

| Level | Tech | Capacity | Bandwidth | Role |
|---|---|---|---|---|
| L0 | Register files / lane buffers | ~100s KB | — | Q vectors, partial sums |
| L1 | Banked on-die SRAM | 256–512 MB | ~100 TB/s class | Hot KV blocks, weights working set |
| L2 | HBM3E stacks | 96–192 GB | ~4–8 TB/s | Full KV pool, cold blocks, weights |
| L3 | Host DRAM via CXL | TBs | ~100s GB/s | Evicted contexts (slow path) |

Key mechanisms:

- **Paged everything**: KV cache lives in fixed-size blocks at every level;
  a hardware block allocator (free list + refcounts) owns L1/L2 placement.
  The page table is two-level: agent → logical blocks → {level, physical}.
- **Switch-triggered prefetch**: on context switch, the engine walks the new
  table and prefetches missing blocks L2→L1 while the first attention passes
  run on resident blocks. Switch latency is hidden, not just short.
- **Prefix sharing**: refcounted physical blocks; copy-on-write on divergence.
  System prompts and tool schemas are stored once per chip, not once per agent.
- **Read-path dequant**: KV stored INT8/FP8 in L2, expanded at the L1 fill —
  effective bandwidth multiplier of 2–4× for free.

## 4. The attention tile (implemented in `rtl/`)

Per tile, per decode step: `out = softmax(q·Kᵀ)·V` over the agent's paged
sequence.

- **Address generation**: logical block counter → page table → physical
  block → SRAM row `{phys_block, token_offset}`. Combinational; 1 read/cycle.
- **Datapath**: D-lane fixed-point MAC array (PoC: D=16, Q8.8; production:
  BF16/FP8), two-pass softmax (max-reduce, then exp-LUT + accumulate — the
  re-read is ~free from SRAM, so the simpler two-pass control wins over
  single-pass online softmax), shared sequential divider for normalization.
- **Throughput**: 2 cycles/token + D×~42 cycles normalize. At 1 GHz, a
  4k-token context decodes in ~9 µs of attention time — the SRAM bandwidth,
  not the pipeline, is the limit, which is exactly the design intent.
- **Multi-head**: replicate lanes or time-multiplex heads; GQA means only
  KV-heads touch the SRAM (8× fewer than query heads on Llama-class models).

## 5. Context-switch engine (implemented: `block_table.sv`)

- 64 resident page tables (PoC: 4), each ≤ 256 logical blocks.
- `switch_ctx`: single register write; the attention tile's address stream
  redirects the next cycle. **Zero KV bytes move.**
- Table-miss / block-fault → allocator interrupt to the RISC-V core (slow
  path); steady-state never faults because the prefetcher runs ahead.

## 6. What the PoC proves vs. what it doesn't

Proves (simulated in `tb/`):
- paged logical→physical KV addressing in hardware,
- single-cycle agent context switch with zero data movement,
- shared-prefix blocks referenced by two agents simultaneously,
- a complete streaming QKᵀ+softmax+AV datapath, bit-checked vs. a reference.

Does not (yet): HBM controller, block allocator HW, prefetch engine,
multi-tile NoC, BF16 MACs, power/area closure. Those are the documented
next steps, in that order.

## 7. Roadmap to tapeout (realistic student/hobby scale)

1. **Now**: PoC tile simulates clean (this repo). FPGA port (block RAMs map
   1:1; the page table is just registers) — demo on real hardware.
2. **Next RTL**: BF16 MAC array (reuse the systolic-array know-how), hardware
   block allocator, HBM-controller shim (AXI), 4-tile NoC ring.
3. **Physical**: OpenROAD / TinyTapeout shuttle for a single tile —
   a fabricated attention tile is a *killer* resume artifact.
4. **System**: cycle-accurate performance model (timing, not just function)
   to size SRAM vs. HBM for a 128k-context target.

## 8. Fermi estimates (order-of-magnitude, for intuition)

- One attention tile at 7nm-class: MAC array + SRAM banks ≈ low tens of mm²;
  a 16-tile chip with 512 MB SRAM ≈ reticle-sized but buildable (cf. Groq's
  500 MB LP30 on Samsung 4nm-class).
- Power is dominated by SRAM reads: tokens/sec/W ≈ SRAM_bandwidth / (bytes
  read per token). At 100 TB/s and ~0.5 MB/token-step (8B-GQA, 4k ctx),
  that's ~200k tok/s per chip-class — before batching.

---

*The resume version of this project: "Designed a paged KV-cache attention
accelerator tile in SystemVerilog with single-cycle multi-agent context
switching; verified with a self-checking testbench against a bit-accurate
reference model." The RTL is the proof.*
