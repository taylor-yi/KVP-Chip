`timescale 1ns/1ps
module page_table #(
    parameter int WORD_W = 256,
    parameter int DEPTH = 256,
    parameter int ADDR_W = 8
)(
    input logic clk, rst_n,

    input logic [3:0] lookup_l_page,
    output logic [3:0] lookup_p_page,
    output logic lookup_valid,

    input logic wr_en,
    input logic [3:0] wr_lpage,
    input logic [3:0] wr_ppage
);

// Decoding engine
// Lookup: give it a logical page, and it returns the physical page and the valid bit. 
// Make this combinational (an array read), so the answer comes back the same cycle.
// Update: when the append controller gets a new page from the allocator, 
// it writes table[lpage] = ppage and sets valid = 1.
// Reset: clears every valid bit. You don’t need to clear the page numbers, 
// because valid = 0 already means “ignore this entry.” That’s REQ-KV-05, so a lookup never silently hands back garbage.

endmodule