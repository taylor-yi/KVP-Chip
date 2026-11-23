`timescale 1ns/1ps
module page_table import kvp_pkg::*; (
    input logic clk, rst_n,

    input logic [PAGE_W - 1:0] lookup_l_page,
    output logic [PAGE_W - 1:0] lookup_p_page,
    output logic lookup_valid,

    input logic wr_en,
    input logic [PAGE_W - 1:0] wr_lpage,
    input logic [PAGE_W - 1:0] wr_ppage
);

    logic [PAGE_W - 1:0] ppage_table [NUM_PAGES - 1:0];
    logic [NUM_PAGES - 1:0] valid_bits;

    assign lookup_p_page = ppage_table[lookup_l_page];
    assign lookup_valid = valid_bits[lookup_l_page];

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            valid_bits <= '0;
        end else if (wr_en) begin
            ppage_table[wr_lpage] <= wr_ppage;
            valid_bits[wr_lpage] <= 1'b1;
        end
    end
endmodule