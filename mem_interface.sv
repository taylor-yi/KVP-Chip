// Port list declare parameters the same as in the block ram
// we need a clock and reset negative
// 1st group of signals: request interface
//2nd group of signals: read response interface
// status signal

module mem_interface #(
    parameter int WORD_W = 256,
    parameter int DEPTH = 256,
    parameter int ADDR_W = 8
)(
    input logic rst_n, clk,
    input logic req_valid, req_write,
    input logic [ADDR_W - 1: 0] req_addr,
    input logic [WORD_W - 1: 0] req_k_data,
    input logic [WORD_W - 1: 0] req_v_data,
    input logic resp_ready,
    output logic [WORD_W - 1: 0] resp_data_k,
    output logic [WORD_W - 1: 0] resp_data_v,
    output logic resp_valid,
    output logic req_ready,
    output logic status
);

    

endmodule