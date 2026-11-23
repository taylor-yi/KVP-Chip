`timescale 1ns/1ps
module  kv_metadata_manager #(parameter int NUM_PAGES = 16,
    parameter int PAGE_W = $clog2(NUM_PAGES))(
            input logic clk, rst_n,
            input logic [PAGE_W - 1:0] free_ppage,
            input logic alloc_req,
            
            output logic [PAGE_W - 1:0] alloc_page,
            output logic alloc_ok,
            output logic alloc_error
        );
