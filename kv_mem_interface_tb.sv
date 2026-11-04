/*
 TESTBENCH CHECKLIST:

    1. [ ] Write known K/V vectors to the same address. Done
    2. [ ] Read them back and compare against expected values. Done
    3. [ ] Verify K and V are accessed simultaneously. Done
    4. [ ] Verify read-after-write behavior. Done
    5. [ ] Write different values to multiple addresses. Done
    6. [ ] Read multiple addresses back-to-back. Done
    7. [ ] Hold rsp_ready LOW and verify rsp_valid/data remain stable.
    8. [ ] Verify no request is accepted while the response is stalled.
    9. [ ] Verify reset clears control state.
    10. [ ] Verify no read response is generated for a write.
    11. [ ] Verify no data is lost during request/response handshakes.
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

    

    //logic [7:0] address_store;
    logic [WORD_W-1:0] exp_k, exp_v;
    logic [ADDR_W-1:0] addr;

    localparam INDICES = 3;
    logic [INDICES - 1:0][ADDR_W - 1:0] addresses;
    logic [INDICES - 1:0][WORD_W - 1:0] exp_k_array, exp_v_array; //array of 3 items for test 2.

    // useful to generate random KV data, 255 bits long generated in 32 bit chunks
    function automatic logic [255:0] rand256();
        logic [255:0] r;
        for(int i = 0; i < 8; i++) begin
            r[i*32+:32] = $urandom;
        end
        return r;
    endfunction

    // helper funciton to fill arrays with random data
    function automatic void fill_arrays();
        for(int i = 0; i < INDICES; i++) begin
            exp_k_array[i] = rand256();
            exp_v_array[i] = rand256();
        end
    endfunction

    //reset everything
    task automatic reset_dut();
        rst_n = 0; req_valid = 0; req_write = 0; resp_ready = 0;
        req_addr = '0; req_data_k = '0; req_data_v = '0;
        @(negedge clk);
        rst_n = 1;
    endtask

    // One write
    task automatic do_write(
    input logic [ADDR_W-1:0] a,
    input logic [WORD_W-1:0] k, v);

        @(negedge clk);
        req_valid = 1; req_write = 1;
        req_addr = a; req_data_k = k; req_data_v = v;

        while (!req_ready) @(negedge clk); // wait for the interface to be free
        @(negedge clk); // accepted on the posedge in between
        req_valid = 0;
    endtask

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
        
        if (!resp_valid) begin
            errors++; $error("[%0t] resp_valid not high after read", $time);
        end

        if(exp_k !== resp_data_k) begin
            errors++;
            $error("[%0t]: full write/read cycle failed on Key data. Expected = %0d, got = %0d", $time, req_data_k, resp_data_k);
        end

        if(exp_v !== resp_data_v) begin
            errors++;
            $error("[%0t]: full write/read cycle failed on Value data. Expected = %0d, got = %0d", $time, req_data_v, resp_data_v);
        end

        if (test_errors == errors) begin
            $display("Test 1 passed, successful read and write to both K and V on one piece of data");
        end else begin 
            $display("Test 1 failed, read or write to KV failed.");
        end

        // Test 2, multiple writes, back to back
        rst_n = 0; req_valid = 0; req_write = 0; resp_ready = 0;
        req_addr = '0; req_data_k = '0; req_data_v = '0;

        @(negedge clk);
        rst_n = 1;
        test_errors = errors;
        fill_arrays();
        addresses = '{8'h22, 8'h23, 8'h24};
        
        @(negedge clk);
        for(int i = 0; i < INDICES; i++) begin
            req_valid = 1; req_write = 1;
            req_addr = addresses[i]; 
            req_data_k = exp_k_array[i]; req_data_v = exp_v_array[i];
            @(negedge clk);

            req_valid = 0;
            @(negedge clk);
        end

        for(int i = 0; i < INDICES; i++) begin
            req_valid = 1; req_write = 0;
            req_addr = addresses[i]; 
            resp_ready = 1;
            @(negedge clk);
            req_valid = 0;
            if(resp_data_k !== exp_k_array[i]) begin
                errors++;
                $error("[%0t] K data mismatch. Expected = %0d, got = %0d, on iteration %0d", $time, exp_k_array[i], resp_data_k, i);
            end
            if(resp_data_v !== exp_v_array[i]) begin
                errors++;
                $error("[%0t] V data mismatch. Expected = %0d, got = %0d, on iteration %0d", $time, exp_v_array[i], resp_data_v, i);
            end
            @(negedge clk);
        end

        if(test_errors == errors) begin
            $display("Test 2 passed. Multiple read after write cycles.");
        end else begin
            $display("Test 2 failed.");
        end

        // Test 3: stall the response
        reset_dut();
        test_errors = errors;
        addr  = 8'h40;
        exp_k = rand256();
        exp_v = rand256();
        do_write(addr, exp_k, exp_v);

        @(negedge clk);
        req_valid = 1; req_write = 0; req_addr = addr; resp_ready = 0;
        @(negedge clk);
        req_valid = 0;

        repeat (5) begin
        @(negedge clk);
        if (!resp_valid) begin
            errors++; $error("[%0t] Test 3: resp_valid dropped while stalled", $time);
        end
        if (resp_data_k !== exp_k || resp_data_v !== exp_v) begin
            errors++; $error("[%0t] Test 3: response data changed while stalled", $time);
        end
        end
 
        resp_ready = 1; // finally take it
        @(negedge clk); // consumed on the posedge in between
        resp_ready = 0;
        if (resp_valid) begin
            errors++; $error("[%0t] Test 3: resp_valid still high after being consumed", $time);
        end
        if(test_errors == errors) begin
            $display("Test 3 passed (stalled response holds)");
        end else begin
            $display("Test 3 failed.");
        end

        // Test 4, reset clears the state, without wiping the memory cells
        reset_dut();
        test_errors = errors;
        addr  = 8'h42;
        exp_k = rand256();
        exp_v = rand256();
        do_write(addr, exp_k, exp_v);
 
        @(negedge clk); // stalled read
        req_valid = 1; req_write = 0; req_addr = addr; resp_ready = 0;
        @(negedge clk);
        req_valid = 0;
        if (!resp_valid) begin
            errors++; $error("[%0t] Test 4: setup failed, not in RESPONSE", $time);
        end
 
        rst_n = 0; // synchronous reset, applied on the next posedge
        @(negedge clk);
        rst_n = 1;
        if (resp_valid) begin
            errors++; $error("[%0t] Test 4: resp_valid still high after reset", $time);
        end
        if (!req_ready) begin
            errors++; $error("[%0t] Test 4: req_ready low after reset", $time);
        end
 
        // memory should survive the reset
        @(negedge clk);
        req_valid = 1; req_write = 0; req_addr = addr; resp_ready = 1;
        @(negedge clk);
        req_valid = 0;
        if (resp_data_k !== exp_k || resp_data_v !== exp_v) begin
            errors++; $error("[%0t] Test 4: RAM contents were wiped by reset", $time);
        end
        @(negedge clk);
        resp_ready = 0;
        if(test_errors == errors) begin
            $display("Test 4 (reset clears control, keeps RAM)");
        end else begin
            $display("Test 4 failed.");
        end
        
        $finish;
    end
endmodule