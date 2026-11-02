// The requesting module asserts req_valid when it has a request. The receiving module asserts req_ready when it can accept one.

// Important: While req_valid = 1 and req_ready = 0, the requesting module 
// must keep its request information (req_addr, req_write, data, etc.) stable.
// We use the same concept for read responses
// The memory interface asserts rsp_valid when K/V data is available.

// The receiving controller asserts rsp_ready when it can consume that data.

// The response is consumed when:
// \[
// rsp\_valid \land rsp\_ready = 1
// \]

// If the receiver isn't ready, the interface holds the response data stable.

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