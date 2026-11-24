`timescale 1ns/1ps
module kv_read_controller import kvp_pkg::*; (
            input logic clk, rst_n,
            input logic read_valid,
            input logic [TOKEN_W - 1:0] num_tokens,
            input logic [TOKEN_W - 1:0] start_token,

            output logic read_ready,
            output logic read_done,
            output logic read_error,
            output logic [WORD_W - 1:0] k_data,
            output logic [WORD_W - 1:0] v_data,
            output logic data_valid
);

typedef enum logic [2:0] {
    IDLE, CHECK, LOOKUP, ADDRESS, READ, RETURN, DONE} state_t;
state_t state;


output metadata_req;
input [:0] num_tokens_stored;
output page_lookup_valid;
output logical_page;
// think later 

always_ff @(posedge clk, negedge rst_n) begin
    if(!rst_n) begin
        state <= IDLE;
        
    end else begin
        case(state)

        IDLE: begin
            if (read_valid) begin
                
            end 
        end
        CHECK: begin 
        end
        LOOKUP: begin
        end
        ADDRESS: begin
        end
        RETURN: begin
        end
        DONE: begin
        end

        default: begin
        end
        endcase







endmodule