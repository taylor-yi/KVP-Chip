`ifndef KVP_PKG_SV
`define KVP_PKG_SV

`timescale 1ns/1ps

package kvp_pkg;

    parameter int ELEM_W    = 16;   // bits per element (BF16)
    parameter int HEAD_DIM  = 16;   // elements per K or V vector (d)
    parameter int PAGE_SIZE = 16;   // tokens per page
    parameter int NUM_PAGES = 16;   // physical pages in the cache

    parameter int WORD_W     = ELEM_W * HEAD_DIM;          // 256: one K or V vector per RAM row
    parameter int DEPTH      = NUM_PAGES * PAGE_SIZE;      // 256: RAM rows = max tokens stored
    parameter int ADDR_W     = $clog2(DEPTH);              // 8:   bits to address a RAM row
    parameter int PAGE_W     = $clog2(NUM_PAGES);          // 4:   bits to name a page
    parameter int OFFSET_W   = $clog2(PAGE_SIZE);          // 4:   bits to name a slot inside a page
    parameter int MAX_TOKENS = DEPTH;                      // 256: longest sequence that fits
    parameter int TOKEN_W    = $clog2(MAX_TOKENS + 1);     // 9:   bits to COUNT 0..256 tokens

    typedef logic [ELEM_W-1:0]   elem_t;      // one BF16 element
    typedef logic [WORD_W-1:0]   kv_word_t;   // one K or V vector
    typedef logic [ADDR_W-1:0]   addr_t;      // RAM row address
    typedef logic [PAGE_W-1:0]   page_t;      // logical or physical page number
    typedef logic [OFFSET_W-1:0] offset_t;    // slot within a page
    typedef logic [TOKEN_W-1:0]  token_cnt_t; // number of tokens in the sequence

endpackage

`endif