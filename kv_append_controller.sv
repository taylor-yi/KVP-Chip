`timescale 1ns/1ps
module kv_append_controller import kvp_pkg::*; (
            input logic clk, rst_n,
            // From top
            input logic append_valid,
            input logic [WORD_W-1:0] k_data,
            input logic [WORD_W-1:0] v_data,

            // Allocator
            output logic free_en,
            output logic [PAGE_W - 1:0] free_ppage,
            output logic alloc_req,

            input logic alloc_ok,
            input logic alloc_error,
            input logic [PAGE_W - 1:0] alloc_ppage,


            // Kv_metadata_manager
            output token_req,

            input logic token_ready,
            input logic token_commited,
            input [PAGE_W - 1:0] logical_page
            input [OFFSET - 1:0] offset,

            // KV_address_generator
            

            // KV_memory_interface
            output logic req_valid,
            output logic req_write,
            output logic [ADDR_W - 1: 0] req_addr,
            output logic [WORD_W - 1: 0] req_data_k,
            output logic [WORD_W - 1: 0] req_data_v,
            output logic resp_ready,

            input logic [WORD_W - 1: 0] resp_data_k,
            input logic [WORD_W - 1: 0] resp_data_v,
            input logic resp_valid,
            input logic req_ready
        );

        
endmodule
