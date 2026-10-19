// 3 parameters
// Word width = 256
// Depth
// Addrress width

module kv_block_ram #(
    parameter int WORD_W = 256,
    parameter int DEPTH = 256, 
    parameter int ADDR_W = 8)(
    input logic clk, wr_en,
    input logic [ADDR_W - 1: 0] wr_addr, rd_addr,
    input logic [WORD_W - 1: 0] wr_data,
    output logic [WORD_W - 1: 0] rd_data
);


    always_ff @(posedge  clk) begin
        if(wr_en)
            mem[wr_addr] <= wr_data;
            rd_data <= mem[rd_addr];
    end
endmodule