# KVP-1 Hardware Design Project
## Paged KV Cache and FlashAttention Accelerator
## Assignment #14: FPGA Deployment

Milestone M7 (FPGA deployment) | Tracks A+B | Target: Friday, Mar 12, 11:59 PM PST

---

### Contents

1. Introduction
2. Setting Up Your Environment
   - 2.1 Board Selection
   - 2.2 Toolchain
3. From Simulation to Hardware
   - 3.1 Memory Mapping
   - 3.2 memory_arbiter
   - 3.3 Host Interface
   - 3.4 Timing Closure
4. Assignment #14
   - 4.1 Files
   - 4.2 Your Task
   - 4.3 Testing Your Implementation
   - 4.4 Submission

---

## 1 Introduction

The design works in simulation. This assignment puts it on a board: map the memories onto block RAM, add a way for a laptop to send tensors and read results, close timing at a stated clock, and run the same prefill and decode scenarios on hardware with outputs checked against the Python model.

The spec's minimum viable demonstration (Section 32) is this assignment plus the evaluation in Assignment 15: the FPGA accepts a small Q/K/V workload, computes tiled attention with online softmax through the paged cache, and returns outputs matching the reference within a documented tolerance, for one prefill and one decode case, with resource, timing and memory-traffic reports.

## 2 Setting Up Your Environment

### 2.1 Board Selection

Resolve spec Appendix C item 1 now if you have not already. Record in `docs/decisions.md`: board name, exact device part number, BRAM and DSP counts, on-board clock, and host connectivity (USB-UART at minimum).

Rough budget to check the board against before committing:

| Item | Estimate | Notes |
|---|---|---|
| K and V RAMs | 2 x 64 Kbit | 256 deep x 256 wide each. On Xilinx 7-series about 4 BRAM36 per RAM because of width. Check your device's widest BRAM configuration |
| Tile buffers, score buffer, O accumulator | ~14 Kbit of registers | Q 1 Kb, KV tile 8 Kb, scores 2 Kb, P up to 2 Kb, O 2 Kb |
| BF16 array | 16 PEs | BF16 multiplier + FP32 adder per PE |
| FP primitives outside the array | a handful of FP32 add/mul, one exp, one reciprocal | |
| exp LUT | small ROM | |

### 2.2 Toolchain

Use the vendor tool for the board (Vivado for Xilinx, Quartus for Intel/Altera) or an open flow (Yosys + nextpnr) if the device is supported. Keep Verilator for regression; add a script that runs the full Verilator suite so you can confirm nothing broke after any FPGA-motivated RTL change.

Check that every RTL file synthesizes before touching anything else. Common Verilator-passes, synthesis-fails issues: `initial` blocks other than ROM init, `$clog2` on non-constant values, unsupported SystemVerilog constructs in the vendor tool, simulation-only assertions not guarded by `` `ifndef SYNTHESIS ``.

## 3 From Simulation to Hardware

### 3.1 Memory Mapping

Confirm from the synthesis report that `kv_block_ram` infers block RAM, not LUTs or flip-flops. Its style (registered read, no reset on the array) is correct for inference. If the tool splits it unexpectedly or warns about read-during-write, compare against the behavior in `docs/kv_layout.md` and fix the doc or the RTL so they agree (REQ-MEM-01, REQ-MEM-02).

### 3.2 memory_arbiter

Inside `kv_cache_top` the append and read controllers already take turns through a mux. On the board, add a third client: a host debug port that can read any K/V RAM word directly. This makes on-board debugging possible without a logic analyzer.

| Requirement | |
|---|---|
| Clients | Append controller, read controller, host debug read |
| Policy | Fixed priority: append, then read, then debug. Debug only granted while the controller is idle |
| REQ-MEM-03 | Simultaneous requests resolved deterministically; an assertion checks that append and read are never both requesting |
| Interface | Each client keeps the `kv_mem_interface` request/response shape, so the controllers do not change |

### 3.3 Host Interface

Pick one, based on the board:

- **UART bridge (works on any board).** A small command protocol: write register, read register, write Q row, write K/V token, read output word, read debug word. Each command is an opcode byte plus fixed-length payload. 256-bit words are 32 bytes. At 921,600 baud a decode step's tensors take well under a millisecond to send, which is fine for a correctness demo.
- **AXI4-Lite (Zynq or similar).** Map `kvp1_top`'s register and staging ports into an AXI-Lite slave and drive it from the ARM core.

Either way, `kvp1_top` stays unchanged; the bridge is a wrapper, `kvp1_fpga_top`. Write `scripts/host/kvp1_host.py`, which talks to the board, runs scenarios from the same vector generators used in simulation, and compares results against `kvp1_model.py`.

Synchronize the reset button and any asynchronous input (UART RX) with a two-flop synchronizer. The rest of the design is single-clock.

### 3.4 Timing Closure

Pick a target clock (100 MHz is a reasonable first target). The combinational FP32 adders and the 4-level `row_max_reduce` tree are the likely critical paths. Fix timing by inserting pipeline registers in the slowest blocks and updating their latency in the docs and controllers.

Every pipelining change must be followed by the full Verilator regression. If a pipelining change alters accumulation order, the Python model must change with it, or bit-exactness is lost.

Record: achieved clock, worst negative slack, and the critical path (start point, end point, logic levels) from the timing report.

## 4 Assignment #14

### 4.1 Files

**rtl/memory_arbiter.sv**, **rtl/fpga/kvp1_fpga_top.sv**, **rtl/fpga/uart_rx.sv**, **rtl/fpga/uart_tx.sv**, **rtl/fpga/host_bridge.sv** (or the AXI-Lite equivalents), **rtl/fpga/sync_2ff.sv**.

**constraints/<board>.xdc** (or `.sdc` / `.pcf`): clock, pins, I/O standards.

**scripts/host/kvp1_host.py**: Board driver and checker.

**scripts/run_regression.sh**: Every Verilator testbench, one summary line.

**reports/**: Synthesis utilization, implementation utilization, timing summary. Archive them (spec M7 exit: reports archived).

**docs/fpga.md**: Board, part, clock, resource table, critical path, host protocol, how to rebuild and rerun the demo from a clean checkout.

### 4.2 Your Task

Get the design onto the board and run the same scenarios as simulation. Add a simulation testbench for `kvp1_fpga_top` that drives the UART RX pin with a bit-level model and decodes TX, so the bridge is verified before it ever touches hardware.

### 4.3 Testing Your Implementation

| Test | Where | Description |
|---|---|---|
| 1 | Sim | Bridge register write/read through bit-level UART |
| 2 | Sim | One decode step through the bridge |
| 3 | Sim | Arbiter: debug read only while idle; append and read never overlap |
| 4 | Sim | Full regression still passes after all pipelining changes |
| 5 | Board | Register read-back (scratch register) |
| 6 | Board | Debug read of K/V RAM after appending known tokens |
| 7 | Board | 40-step decode, outputs bit-exact vs `kvp1_model.py` |
| 8 | Board | 37-token prefill then 20 decode steps, bit-exact |
| 9 | Board | Error path: cache full error reported correctly over the bridge |
| 10 | Board | `CYCLES` register read for each step, compared with simulation |

On-board results should be bit-identical to simulation. If they are not, the likely causes are an unsynchronized input, a timing violation the report did not flag (check constraints cover every clock), or a simulation/synthesis mismatch in RTL (latch inference, incomplete sensitivity, `initial` values on registers).

### 4.4 Submission

To receive full credit you must:

1. Pass all simulation tests and all board tests.
2. Archive synthesis, implementation and timing reports in `reports/`.
3. Record a short video of the board running Test 8 with the host script printing PASS.
4. Have the partner who did not build the bridge follow `docs/fpga.md` from a clean checkout and reproduce Test 7.

Tag the commit `a14-fpga`. This closes milestone M7.
