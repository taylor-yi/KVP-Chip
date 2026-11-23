`timescale 1ns/1ps
module  kv_metadata_manager import kvp_pkg::*; (
            input logic clk, rst_n,
            input logic token_req,
            
            output logic token_ready,
            output logic token_commited,
            output [NUM_PAGES - 1:0] logical_page,
            output integer offset //can change to page_size array I think
        );

        integer num_tokens;
        logic [NUM_PAGES - 1:0] logical_page;

        assign token_ready = ~token_req;

        always_comb begin 
            logical_page = num_tokens / PAGE_SIZE;
            offset = num_tokens % PAGE_SIZE;
        end

        always_ff @(posedge clk, negedge rst_n) begin
            if (!rst_n) begin
                num_tokens <= 0;
                token_commited <= 1'b0;
            end else if (token_req) begin
                num_tokens <= num_tokens + 1;
                token_commited <= 1'b1;
            end else begin
                token_commited <= 1'b0;
            end
        end

endmodule