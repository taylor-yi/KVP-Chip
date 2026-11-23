`timescale 1ns/1ps
module kv_address_generator import kvp_pkg::*; (
    input clk, rst_n,
    // input logic [PAGE_W - 1:0] logical_page,
    input logic [PAGE_W - 1:0] physical_page,
    input logic [OFFSET_W - 1:0] offset,

    output logic [ADDR_W - 1:0] addr
    // output logic [ADDR_W - 1:0] v_addr,
);

    assign addr = {physical_page, offset};

    // logic [ADDR_W - 1:0] physical_slot;

    // assign physical_slot = physical_page * PAGE_SIZE + offset;
    // assign addr = physical_slot * HEAD_DIM;
    // assign v_addr = physical_slot * HEAD_DIM;

endmodule