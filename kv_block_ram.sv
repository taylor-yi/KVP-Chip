// 3 parameters
// Word width = 256
// Depth
// Addrress width
`timescale 1ns/1ps
module kv_block_ram #(
    parameter int WORD_W = 256, //Stems from using BF16 x 16 dimension attention head
    parameter int DEPTH = 256, 
    parameter int ADDR_W = 8)(
    input logic clk, rst_n, wr_en, rd_en,
    input logic [ADDR_W - 1: 0] wr_addr, rd_addr,
    input logic [WORD_W - 1: 0] wr_data,
    output logic [WORD_W - 1: 0] rd_data
);

    logic [WORD_W - 1: 0] mem [DEPTH - 1: 0];

    always_ff @(posedge  clk) begin
        if(!rst_n) begin
            mem = '{default: '{default:0}};
            rd_data = '0;
            // wr_addr = '0;
            // rd_addr = '0;
            // wr_data = '0;
        end else begin
            if(wr_en) begin
                mem[wr_addr] <= wr_data;
            end 
            
            if(rd_en) begin
                rd_data <= mem[rd_addr];
            end
        end

        
    end
endmodule