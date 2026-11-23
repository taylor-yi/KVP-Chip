// 3 parameters
// Word width = 256
// Depth
// Addrress width
`timescale 1ns/1ps
module kv_block_ram import kvp_pkg::*; (
    input logic clk, rst_n, wr_en, rd_en,
    input logic [ADDR_W - 1: 0] wr_addr, rd_addr,
    input logic [WORD_W - 1: 0] wr_data,
    output logic [WORD_W - 1: 0] rd_data
);

    logic [WORD_W - 1: 0] mem [DEPTH - 1: 0];

    always_ff @(posedge  clk) begin
            if(wr_en) begin
                mem[wr_addr] <= wr_data;
            end 
            if(rd_en) begin
                rd_data <= mem[rd_addr];
            end
    end
endmodule