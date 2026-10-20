// 3 parameters
// Word width = 256
// Depth
// Addrress width
`timescale 1ns/1ps
module kv_block_ram #(
    parameter int WORD_W = 256,
    parameter int DEPTH = 256, 
    parameter int ADDR_W = 8)(
    input logic clk, wr_en,
    input logic [ADDR_W - 1: 0] wr_addr, rd_addr,
    input logic [WORD_W - 1: 0] wr_data,
    output logic [WORD_W - 1: 0] rd_data
);

    logic [WORD_W - 1: 0] mem [DEPTH - 1: 0];

    always_ff @(posedge  clk) begin
        if(wr_en) begin
            mem[wr_addr] <= wr_data;
            rd_data <= mem[rd_addr];
        end
    end
endmodule

module kv_block_ram_tb();
    logic clk, wr_en;
    logic [7:0] wr_addr, rd_addr;
    logic [255:0] wr_data, rd_data;

    kv_block_ram dut(.*);

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        $dumpfile("dump.vcd");     // the output file's name
        $dumpvars(0, kv_block_ram_tb);    // depth 0 = this scope AND everything under it
    end

    initial begin
        //WRITE TB IN HERE
        wr_en = 0;
        wr_addr = '0;
        rd_addr = '0;
        wr_data = '0;
        rd_data = '0;
        #20;
        wr_en = 1;
        wr_addr = 8'h55;
        wr_data = '1;
        #10;
        rd_addr = 8'h55;
        wr_data = 0;
        #10;
        $finish;
    end
        
endmodule