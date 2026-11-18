`timescale 1ns/1ps
module  page_allocator #(parameter int NUM_PAGES = 16,
    parameter int PAGE_W = $clog2(NUM_PAGES))(
            input logic clk, rst_n,
            input logic free_en,
            input logic [PAGE_W - 1:0] free_ppage,
            input logic alloc_req,
            
            output logic [PAGE_W - 1:0] alloc_page,
            output logic alloc_ok,
            output logic alloc_error
        );

        logic [NUM_PAGES - 1:0] used_map;
        logic full;
        logic found_flag;

        // full logic
        assign full = (used_map == '1);

        assign alloc_ok = alloc_req & !full;
        assign alloc_error = alloc_req & full;

        // Priority encoder, find the lowest bit thats 0
        always_comb begin
            alloc_page = '0;
            found_flag = '0;
            for(int i = 0; i < NUM_PAGES; i++) begin
                if((used_map[i] == 1'b0) && !found_flag) begin
                    alloc_page = PAGE_W'(i);
                    found_flag = 1'b1;
                end
            end
        end

        always_ff @(posedge clk) begin
            if(!rst_n) begin
                used_map <= '0;
            end else begin
                if(alloc_ok) begin
                    used_map[alloc_page] <= 1'b1;
                end
                
                if(free_en) begin
                    used_map[free_ppage] <= 1'b0;
                end
            end
        end
endmodule
