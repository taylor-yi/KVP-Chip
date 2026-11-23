`timescale 1ns/1ps
module  kv_metadata_manager import kvp_pkg::*; (
            input logic clk, rst_n,
            input logic token_req,
            
            output logic [PAGE_W - 1:0] logical_page,
            output logic [OFFSET_W - 1:0] offset //can change to page_size array I think
        );

        integer num_tokens;
        logic [PAGE_W - 1:0] logical_page;

        always_comb begin 
            logical_page = PAGE_W'(num_tokens / PAGE_SIZE);
            offset = OFFSET_W'(num_tokens % PAGE_SIZE);
        end

        always_ff @(posedge clk, negedge rst_n) begin
            if (!rst_n) begin
                num_tokens <= 0;
            end else if (token_req) begin
                num_tokens <= num_tokens + 1;
            end
        end

endmodule