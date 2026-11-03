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

    // useful to generate random KV data, 255 bits long generated in 32 bit chunks
    function automatic logic [255:0] rand256();
        logic [255:0] r;
        for(int i = 0; i < 8; i++) begin
            r[i*32+:32] = $urandom;
        end
        return r;
    endfunction

    //logic [7:0] address_store;
    logic [WORD_W-1:0] exp_k, exp_v;
    logic [ADDR_W-1:0] addr;

    initial begin
        rst_n = 0; req_valid = 0; req_write = 0; resp_ready = 0;
        req_addr = '0; req_data_k = '0; req_data_v = '0;

        // Test 1, write KV vectors to the same address
        @(negedge clk);
        rst_n = 1;
        test_errors = errors;
        addr  = ADDR_W'($urandom); //set the random variables
        exp_k = rand256();
        exp_v = rand256();

        @(negedge clk); // Write
        req_valid = 1; req_write = 1;
        req_addr = addr; req_data_k = exp_k; req_data_v = exp_v;
        
        @(negedge clk); // accepted on the posedge in between
        req_valid = 0;
        
        @(negedge clk); // Read
        req_valid = 1; req_write = 0; req_addr = addr; resp_ready = 1;
        
        @(negedge clk); // accepted, RAM loads data
        req_valid = 0;
        
        @(negedge clk);
        if(req_data_k !== resp_data_k) begin
            errors++;
            $error("[%0t]: full write/read cycle failed on Key data. Expected = %0d, got = %0d", $time, req_data_k, resp_data_k);
        end

        if(req_data_v !== resp_data_v) begin
            errors++;
            $error("[%0t]: full write/read cycle failed on Value data. Expected = %0d, got = %0d", $time, req_data_v, resp_data_v);
        end

        if (test_errors == errors) begin
            $display("Test 1 passed, successful read and write to both K and V");
        end else begin 
            $display("Test 1 failed, read or write to KV failed.");
        end

        $finish;
    end
endmodule