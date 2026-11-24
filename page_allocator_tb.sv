`timescale 1ns/1ps
module page_allocator_tb import kvp_pkg::*; ();
            localparam int NUM_PAGES = 16;
            localparam int PAGE_W = $clog2(NUM_PAGES);
            logic clk, rst_n;
            logic free_en;
            logic [PAGE_W - 1:0] free_ppage;
            logic alloc_req;
            
            logic [PAGE_W - 1:0] alloc_page;
            logic alloc_ok;
            logic alloc_error;
            logic free_ok;

            page_allocator dut (.*);

            int checks = 0, errors = 0, test_errors;

            initial begin
                $dumpfile("dump.vcd");
                $dumpvars(0, page_allocator_tb);
            end

            initial begin
               clk = 0;
               forever #5 clk = ~clk; 
            end

            task automatic reset_everything();
                rst_n = 0;
                free_en = 0;
                free_ppage = '0;
                alloc_req = 0;

                @(negedge clk);
                rst_n = 1;
            endtask

            task automatic allocate_pages();
                alloc_req = 1;
                @(negedge clk);
                alloc_req = 0;
                @(negedge clk);
            endtask

            task automatic allocate_all();
                for(int i = 0; i < NUM_PAGES; i++)begin
                    allocate_pages();
                end
            endtask

            task automatic free_page(int page);
                if (page > NUM_PAGES - 1 || page < 0) begin
                    $error("[%0t] ERROR: Not within the bounds", $time);
                end
                free_en = 1;
                free_ppage = PAGE_W'(page);

                @(negedge clk);
                
                if(free_ok !== 1'b1) begin
                    errors++;
                    $error("[%0t] ERROR: free_ok not high after freeing page %0d.", $time, page);
                end

                free_en = 0;
                free_ppage = '0;
            endtask

            task automatic free_all();
                for(int i = 0; i < NUM_PAGES; i++) begin
                    free_page(i);
                end
            endtask

            initial begin
                // Test 1, test reset
                reset_everything();
                test_errors = errors;
                checks = 0;

                rst_n = 0;
                @(negedge clk);
                rst_n = 1;
                @(negedge clk);

                if(alloc_page !== '0)begin
                    errors++;
                    $error("[%0t] ERROR: Alloc page is not 0. Reset failed.", $time);
                end

                if(alloc_ok !== 0)begin
                    errors++;
                    $error("[%0t] ERROR: Alloc_ok is not 0. Reset failed.", $time);
                end

                if(alloc_error !== 0)begin
                    errors++;
                    $error("[%0t] ERROR: Alloc_error is not 0. Reset failed.", $time);
                end

                if(dut.full !== 0)begin
                    errors++;
                    $error("[%0t] ERROR: Full is not 0. Reset failed.", $time);
                end

                if(test_errors == errors) begin
                    $display("Test 1 Passed: Reset behavior as expected", $time);
                end else begin
                    $display("Test 1 Failed: Reset is not correct.", $time);
                end

                // Test 2, Allocate 16 times in a row
                checks++;
                reset_everything();
                test_errors = errors;

                allocate_all();

                // check full
                if(dut.full !== 1)begin
                    errors++;
                    $error("[%0t] ERROR: Full is not 1.", $time);
                end

                // check used_map
                for(int i = 0; i < NUM_PAGES; i++) begin
                    if(!dut.used_map[i]) begin
                        errors++;
                        $error("[%0t] ERROR: Used_map not funcitoning correctly.", $time);
                    end
                end

                // ping allocate request one additional time, it should throw an error
                alloc_req = 1;
                @(negedge clk)
                
                if(!alloc_error) begin
                    errors++;
                    $error("[%0t] ERROR: Alloc error not asserted, page allocator should be full.", $time);
                end

                if(alloc_ok) begin
                    errors++;
                    $error("[%0t] ERROR: Alloc ok asserted when it should not be.", $time);
                end

                if(test_errors == errors) begin
                    $display("Test 2 Passed: 16 pages filled, signals verified", $time);
                end else begin
                    $display("Test 2 Failed: 16 Pages not filled, or signal error.", $time);
                end

                // Test 3, allocate until full in order, checking the page number will be correct
                checks++;
                reset_everything();
                test_errors = errors;

                for(int i = 0; i < NUM_PAGES; i++) begin
                    alloc_req = 1'b1;
                    #1;  // alloc_page is combinational: check it before the edge takes the page
                    if(alloc_page !== PAGE_W'(i)) begin
                        errors++;
                        $error("[%0t] ERROR: Incorrect page allocated. Expected: %0d, got %0d.", $time, i, alloc_page);
                    end
                    @(negedge clk);
                    alloc_req = 1'b0;

                    if(!dut.used_map[i]) begin
                        errors++;
                        $error("[%0t] ERROR: Used map not filled.", $time);
                    end
                    @(negedge clk);
                end

                if(test_errors == errors) begin
                    $display("Test 3 Passed: 16 Consecutive page requests, correct pages identified.");
                end else begin
                    $display("Test 3 Failed: Either fail on allocation or incorrect page allocated");
                end
                
                // Test 4, Free behavior
                reset_everything();
                test_errors = errors;
                checks++;

                allocate_all();

                // Free page 7. free_page() returns at the negedge right after the
                // clock edge that did the free, so check here, with no extra wait.
                // free_ok is registered: it is high for exactly this one cycle.
                free_page(7);

                if(dut.used_map[7] !== 1'b0) begin
                    errors++;
                    $error("[%0t] ERROR: used_map[7] still set after freeing page 7.", $time);
                end

                // Free a higher page
                free_page(10);

                if(dut.used_map[10] !== 1'b0) begin
                    errors++;
                    $error("[%0t] ERROR: used_map[10] still set after freeing page 10.", $time);
                end

                @(negedge clk);

                // Request a page. alloc_page and alloc_ok are combinational, so check
                // them BEFORE the clock edge that takes the page. After that edge,
                // alloc_page already points at the next free page.
                alloc_req = 1'b1;
                #1;
                if(alloc_page !== 4'd7) begin
                    errors++;
                    $error("[%0t] ERROR: Incorrect page offered. Expected: 7, got %0d.", $time, alloc_page);
                end

                if(alloc_ok !== 1'b1) begin
                    errors++;
                    $error("[%0t] ERROR: alloc_ok not high while a page is free.", $time);
                end

                @(negedge clk);
                alloc_req = 1'b0;

                if(dut.used_map[7] !== 1'b1) begin
                    errors++;
                    $error("[%0t] ERROR: used_map[7] not set after reallocating it.", $time);
                end

                // Page 10 is now the only free page, so it should be offered next
                if(alloc_page !== 4'd10) begin
                    errors++;
                    $error("[%0t] ERROR: Next free page should be 10, got %0d.", $time, alloc_page);
                end

                if(test_errors == errors) begin
                    $display("Test 4 Passed: Freed page successfully and refilled correctly.");
                end else begin
                    $display("Test 4 Failed: Page not freed properly.");
                end

                $finish;
            end
endmodule