`timescale 1ns/1ps
module kv_append_controller import kvp_pkg::*; (
            input logic clk, rst_n,
            // From top
            output logic append_ready,
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

            input [PAGE_W - 1:0] logical_page,
            input [OFFSET_W - 1:0] offset,

            // KV_address_generator, hooked up internally
            // output logic [PAGE_W - 1:0] physical_page,
            // output logic [OFFSET_W - 1:0] offset,
            // input logic [ADDR_W - 1:0] addr;

            // KV_memory_interface
            output logic req_valid,
            output logic req_write,
            output logic [ADDR_W - 1: 0] req_addr,
            output logic [WORD_W - 1: 0] req_data_k,
            output logic [WORD_W - 1: 0] req_data_v
        );

typedef enum logic [2:0] {
    IDLE, CHECK, ALLOCATE, WRITE, COMMIT, FREE, ERROR} state_t;
state_t state;

logic [WORD_W-1:0] current_k, current_v;
logic [PAGE_W-1:0] cur_ppage;
logic [ADDR_W-1:0] cur_addr;

kv_address_generator addr_machine (
    .clk(clk), 
    .rst_n(rst_n), 
    .physical_page(cur_ppage),
    .offset(offset),
    .addr(cur_addr));

always_ff @(posedge clk, negedge rst_n) begin
    if(!rst_n) begin
        state <= IDLE;
        current_k <= '0;
        current_v <= '0;
        cur_ppage <= '0;
    end else begin
        case(state)
            IDLE: begin
                append_ready <= 1'b1;
                if(append_valid) begin
                    state <= CHECK;
                    current_k <= k_data;
                    current_v <= v_data;
                    token_req <= 1'b1;
                end else begin
                    current_k <= '0;
                    current_v <= '0;
                end
            end

            CHECK: begin
                if(offset == 0) begin
                    state <= ALLOCATE;
                end else begin
                    state <= WRITE;
                end
            end

            ALLOCATE: begin
                alloc_req <= 1'b1;
                if(alloc_ok) begin
                    cur_ppage <= alloc_ppage;
                    state <= WRITE;
                end else if(alloc_error) begin
                    state <= ERROR;
                end
            end

            WRITE: begin
                req_valid <= 1'b1;
                req_write <= 1'b1;
                req_addr <= cur_addr;
                req_data_k <= current_k;
                req_data_v <= current_v;
                state <= COMMIT;
            end

            COMMIT: begin
                token_req <= 1'b1;
                state <= IDLE;
            end

            FREE: begin

            end

            ERROR: begin
                $display("ERROR: KV Cache is full. Context window full.");
            end

            default: begin
                state <= IDLE;
                token_req <= 1'b0;
                alloc_req <= 1'b0;
                req_valid <= 1'b0;
                req_write <= 1'b0; // Register of concern, since both append and read touch this one
                req_addr <= '0;
                req_data_k <= '0;
                req_data_v <= '0;
            end
        endcase
    end
end

endmodule
