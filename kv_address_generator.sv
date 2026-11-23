`timscale 1ns/1ps
module kv_address_generator import kvp.pkg::*; (
    input clk, rst_n,
    input logic [PAGE_W - 1:0] logical_page,
    input logic [PAGE_W - 1:0] physical_page,
    input logic [OFFSET_W - 1:0] offset,
    input logic [HEAD_DIM - 1:0] element_offset,
    input logic request_valid,
    input logic is_write,

    output logic [HEAD_DIM - 1:0] physical_slot,
    output logic [ADDR_W - 1:0] k_addr,
    output logic [ADDR_W - 1:0] v_addr,
    output logic address_valid
);

endmodule