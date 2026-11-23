`timescale 1ns/1ps
module  kv_metadata_manager #(parameter int NUM_PAGES = 16,
    parameter int PAGE_W = $clog2(NUM_PAGES))(
            input logic clk, rst_n,
            input logic token_req,
            input logic token_req_valid,

            output logic token_commited
        );

        integer num_tokens;
        logic num_alloc_page;
        logic [NUM_PAGES - 1:0] logical_page;
        logic [PAGE_W - 1:0] page_size;
        integer offset;

        always_comb begin 
            logical_page = num_tokens / page_size;
            offset = num_tokens % page_size;
        end

        always_ff @(posegde clk, negedge !rst_n) begin
            if (!rst_n) begin
                current_page <= '0;
                num_tokens <= 0;
            end
            else if (token_req && token_req_valid) begin
                num_tokens ++;
            end
        end