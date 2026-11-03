/*
===============================================================================
 TESTBENCH CHECKLIST:

    1. [ ] Write known K/V vectors to the same address.
    2. [ ] Read them back and compare against expected values.
    3. [ ] Verify K and V are accessed simultaneously.
    4. [ ] Verify read-after-write behavior.
    5. [ ] Write different values to multiple addresses.
    6. [ ] Read multiple addresses back-to-back.
    7. [ ] Hold rsp_ready LOW and verify rsp_valid/data remain stable.
    8. [ ] Verify no request is accepted while the response is stalled.
    9. [ ] Verify reset clears control state.
    10. [ ] Verify no read response is generated for a write.
    11. [ ] Verify no data is lost during request/response handshakes.

===============================================================================
*/

`timescale 1ns/1ps
module kv_mem_interface_tb ();
    localparam int WORD_W = 256;
    localparam int DEPTH = 256;
    localparam int ADDR_W = 8;
    logic rst_n, clk;
    logic req_valid, req_write;
    logic [ADDR_W - 1: 0] req_addr;
    logic [WORD_W - 1: 0] req_data_k;
    logic [WORD_W - 1: 0] req_data_v;
    logic resp_ready;
    
    logic [WORD_W - 1: 0] resp_data_k;
    logic [WORD_W - 1: 0] resp_data_v;
    logic resp_valid;
    logic req_ready;

    kv_mem_interface #(.*) dut (.*);

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(0, kv_mem_interface_tb);
    end

    int checks = 0, errors = 0, test_errors;

    initial begin
        // Test 1, write KV vectors to the same address
        rst_n = 0;
        repeat (1) @(negedge clk);
        
        rst_n = 1;
        

    end
endmodule