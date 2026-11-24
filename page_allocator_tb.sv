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

            page_allocator #(.*) dut (.*);

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
                alloc_page = '0;
                alloc_ok = 0;
                alloc_error = 0;

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
                        $error("[%0t] ERROR: Used_map not funcitoning correctly.", $time);
                    end
                end

                // ping allocate request one additional time, it should throw an error
                alloc_req = 1;
                @(negedge clk)
                
                if(!alloc_error) begin
                    $error("[%0t] ERROR: Alloc error not asserted, page allocator should be full.", $time);
                end

                if(alloc_ok) begin
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

                for(int i = 0; i < NUM_PAGES - 1; i++) begin
                    alloc_req = 1'b1;
                    @(negedge clk);
                    alloc_req = 1'b0;

                    if(alloc_page !== (4'(i) + 1)) begin
                        $error("[%0t] ERROR: Incorrect page allocated. Expected: %0d, got %0d.", $time, 4'(i), alloc_page);
                    end

                    if(!dut.used_map[i]) begin
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
                
                free_page(7);
                @(negedge clk);
                
                if(dut.used_map[6]) begin
                    errors++;
                    $error("[%0t] ERROR: Used map not updated on free 1. Index 8.", $time);
                end

                if(!free_ok) begin
                    errors++;
                    $error("[%0t] ERROR: Free_ok not driven correctly.", $time);
                end
                
                @(negedge clk);
                // Free a higher page
                free_page(10);
                @(negedge clk); 
                if(dut.used_map[9]) begin
                    errors++;
                    $error("[%0t] ERROR: Used map not updated on free 1. Index 8.", $time);
                end

                if(!free_ok) begin
                    errors++;
                    $error("[%0t] ERROR: Free_ok not driven correctly.", $time);
                end
                
                @(negedge clk);

                // Request a page, it should allocate page 7 since now that is the lowest free page
                alloc_req = 1'b1;
                @(negedge clk);
                alloc_req = 1'b0;

                if(alloc_page !== 4'h7) begin
                    errors++;
                    $error("[%0t] ERROR: Incorrect page allocated. Expected: %0d, got %0d.", $time, 4'h7, alloc_page);
                end

                if(!dut.used_map[6]) begin
                    errors++;
                    $error("[%0t] ERROR: Used map not filled.", $time);
                end
                @(negedge clk);

                if(test_errors == errors) begin
                    $display("Test 4 Passed: Freed page successfully and refilled correctly.");
                end else begin
                    $display("Test 4 Failed: Page not freed properly.");
                end

                $finish;
            end
endmodule