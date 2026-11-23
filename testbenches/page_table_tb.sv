`timescale 1ns/1ps
`include "defines.sv"
module page_table_tb ();
    localparam int NUM_PAGES = 16;
    localparam int PAGE_W = $clog2(NUM_PAGES);

    logic clk, rst_n;
    logic [PAGE_W - 1:0] lookup_l_page;
    logic wr_en;
    logic [PAGE_W - 1:0] wr_lpage;
    logic [PAGE_W - 1:0] wr_ppage;

    //outputs 
    logic [PAGE_W - 1:0] lookup_p_page;
    logic lookup_valid;

    page_table #(.*) dut (.*);

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(0, page_table_tb);
    end

    int checks = 0, errors = 0, test_errors;

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    task automatic reset_everything();
        rst_n = 0;
        lookup_l_page = '0;
        wr_en = 0;
        wr_lpage = '0;
        wr_ppage = '0;

        @(negedge clk);
        rst_n = 1;
    endtask

    task automatic fill_table();
        @(negedge clk);
        for(int i = 0; i < 16; i++) begin
            wr_en = 1;
            wr_ppage = PAGE_W'(i);
            wr_lpage = PAGE_W'(15 - i); // map inversely, 15 > 0 etc.
            @(negedge clk);
        end
        wr_en = 0;
    endtask

    task automatic fill_table_rand();
        @(negedge clk);
        for(int i = 0; i < 16; i++) begin
            wr_en = 1;
            wr_ppage = PAGE_W'($urandom);
            exp_page[i] = wr_ppage;
            wr_lpage = PAGE_W'(i);
            @(negedge clk);
        end
        wr_en = 0;
    endtask

    // local vars
    logic [PAGE_W - 1 : 0] exp_page [NUM_PAGES];

    initial begin
        // Test 1, map 1 phys page and 1 log page
        test_errors = errors;
        reset_everything();
        wr_en = 1;
        wr_ppage = 4'h1; // mapping: 16 > 1
        wr_lpage = 4'hF;

        @(negedge clk);
        wr_en = 0;
        lookup_l_page = 4'hF;
        if(lookup_p_page !== 4'h1) begin
            errors++;
            $error("[%0t] Error: page mismatch. Expected 0001 got %0d", $time, lookup_p_page);
        end

        if(test_errors == errors) begin
            $display("Test 1 passed, singular page map");
        end else begin
            $display("FAIL on Test 1");
        end

        // Test 2, fill whole page table once
        test_errors = errors;
        reset_everything();
        fill_table();

        for(int i = 0; i < 16; i++) begin
            lookup_l_page = PAGE_W'(15 - i);
            @(negedge clk);
            if(lookup_p_page !== PAGE_W'(i)) begin
                errors++;
                $error("[%0t] Error: page mismatch. Index: %0d. Expected %0d got %0d", $time, i, PAGE_W'(i), lookup_p_page);
            end
        end

        if(test_errors == errors) begin
            $display("Test 2 passed, filled the page map");
        end else begin
            $display("FAIL on Test 2");
        end

        // Test 3, fill whole page table multiple times with random data
        test_errors = errors;
        reset_everything();
        fill_table_rand();

        for(int i = 0; i < NUM_PAGES; i++) begin
            lookup_l_page = PAGE_W'(i);
            @(negedge clk);
            if(lookup_p_page !== exp_page[i]) begin
                errors++;
                $error("[%0t] Error: page mismatch. Index: %0d. Expected %0d got %0d", $time, i, PAGE_W'(i), lookup_p_page);
            end
        end

        if(test_errors == errors) begin
            $display("Test 3 passed, filled the page map with random data");
        end else begin
            $display("FAIL on Test 3");
        end

        // Test 4, fill multiple times without resetting. 
        // Fill all once. Check.
        // Start filling again, check each time
        // Fill third time and check as you go.
        test_errors = errors;
        reset_everything();
        fill_table_rand();

        for(int i = 0; i < NUM_PAGES; i++) begin
            lookup_l_page = PAGE_W'(i);
            @(negedge clk);
            if(lookup_p_page !== exp_page[i]) begin
                errors++;
                $error("[%0t] Error: page mismatch. Index: %0d. Expected %0d got %0d", $time, i, PAGE_W'(i), lookup_p_page);
            end
        end

        //filled, try overwriting once, checking as you go.
        for(int i = 0; i < NUM_PAGES; i++) begin
            wr_en = 1;
            wr_lpage = PAGE_W'(i);
            wr_ppage = PAGE_W'($urandom);
            exp_page[i] = wr_ppage;
            @(negedge clk);

            wr_en = 0;
            lookup_l_page = PAGE_W'(i);

            @(negedge clk);
            if(lookup_p_page !== exp_page[i]) begin
                errors++;
                $error("[%0t] Error: page mismatch. Index: %0d. Expected %0d got %0d", $time, i, PAGE_W'(i), lookup_p_page);
            end
        end

        // Overwritten once. Now try random logical pages mapped to known physical pages.
        for(int i = 0; i < NUM_PAGES; i++) begin
            wr_en = 1;
            wr_lpage = PAGE_W'($urandom);
            wr_ppage = PAGE_W'(i);
            exp_page[wr_lpage] = wr_ppage;
            @(negedge clk);

            wr_en = 0;
            lookup_l_page = wr_lpage;

            @(negedge clk);
            if(lookup_p_page !== exp_page[wr_lpage]) begin
                errors++;
                $error("[%0t] Error: page mismatch. Index: %0d. Expected %0d got %0d", $time, i, PAGE_W'(i), lookup_p_page);
            end
        end

        if(test_errors == errors) begin
            $display("Test 4 passed, filled the page map 3 times");
        end else begin
            $display("FAIL on Test 4");
        end

        $finish;
    end

endmodule
