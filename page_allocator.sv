`timescale 1ns/1ps
module  page_allocator #(parameter int NUM_PAGES = 16,
    parameter int PAGE_W = $clog2(NUM_PAGES))(
            input logic clk, rst_n,
            input logic free_en,
            input logic free_ppage,
            input logic alloc_req,
            
            output logic [3:0] alloc_page,
            output logic alloc_ok,
            output logic alloc_error
        );

        logic [15:0] used_map;
        logic full;

        //full logic
        assign full = (used_map == 16'hFFFF);

        assign alloc_ok = alloc_req & !full;
        assign alloc_error = alloc_req & full;

        always_comb begin
            
        end

endmodule
