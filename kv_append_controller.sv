`timescale 1ns/1ps
module kv_append_controller import kvp_pkg::*; (
            input logic clk, rst_n,
            input logic append_valid,
            input logic agent_id,
            input logic k_data,
            input logic v_data,
            input logic alloc_valid,
            input logic alloc_page,
            input logic num_tokens_stores,
            input logic page_full,

            
            output logic append_ready,
            output logic append_done,
            output logic append_error,
            output logic alloc_req,
            output logic metadata_req,
            output logic mem_write_en,
            output logic mem_write_addr,
            output logic mem_write_k,
            output logic mem_write_v,
            output logic append_done
        );

        
endmodule
