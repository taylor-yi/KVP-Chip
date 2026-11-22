`timescale 1ns/1ps
module page_allocator_tb();
            localparam int NUM_PAGES = 16;
            localparam int PAGE_W = $clog2(NUM_PAGES);
            logic clk, rst_n;
            logic free_en;
            logic [PAGE_W - 1:0] free_ppage;
            logic alloc_req;
            
            logic [PAGE_W - 1:0] alloc_page;
            logic alloc_ok;
            logic alloc_error;

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
                if (page > NUM_PAGES - 1 || page < 0) begin
                    $error("[%0t] ERROR: Not within the bounds", $time);
                end
                alloc_req = 1;
                @(negedge clk);
                alloc_req = 0;
                @(negedge clk);
            endtask

            initial begin
                // Test 1, test reset
                reset_everything();
                test_errors = errors;

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
                reset_everything();
                test_errors = errors;
                for (i = 0; i < NUM_PAGES ; i++) begin
                    allocate_pages();
                    if (!(alloc_ok && !alloc_error)) begin
                        $error("[%0t] ERROR: Allocation signals failed", $time);
                    end
                end
                if(dut.full !== 1)begin
                    errors++;
                    $error("[%0t] ERROR: Full is 0.", $time);
                end
                for (i = 0; i < NUM_PAGES; i++) begin
                    if (dut.used_map[i] !== 1) begin
                        errors++;
                        $error("[%0t] ERROR: Used map not filled", $time);
                    end
                end

                

                $finish;
            end
endmodule