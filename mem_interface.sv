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

/*
===============================================================================
 MODULE: kv_memory_interface
 PURPOSE:
    Interface between the KV cache controllers and the physical K/V RAM banks.

    The module instantiates two independent kv_block_ram memories:
        1. K memory: stores 256-bit BF16 key vectors.
        2. V memory: stores 256-bit BF16 value vectors.

    Both memories use the same physical address and operate in parallel.

===============================================================================
 DESIGN CONFIGURATION:
    WORD_W = 256 bits
    DEPTH  = 256 words
    ADDR_W = 8 bits

    One memory word stores one complete BF16 vector:
        16 elements x 16 bits = 256 bits.

===============================================================================
 IMPLEMENTATION CLUES / REQUIREMENTS:

 STEP 1: INSTANTIATE THE MEMORIES
    - Instantiate two kv_block_ram modules.
    - One instance represents K memory.
    - The other instance represents V memory.
    - Connect both to the same clock.
    - Both instances must receive the same physical address.
    - Each instance must receive its own write data.

 STEP 2: IMPLEMENT THE REQUEST HANDSHAKE
    - Use req_valid and req_ready to determine when a request is accepted.
    - A request is accepted only on a rising clock edge where BOTH are high.
    - The interface should only assert req_ready when it can accept a new request.
    - Initially, support only ONE outstanding transaction.
    - While a request is stalled, the requesting controller must keep its
      request signals stable.

 STEP 3: DECODE THE REQUEST
    - req_write determines the operation.
    - req_write = 1 means WRITE.
    - req_write = 0 means READ.
    - Only execute an operation when the request handshake succeeds.
    - Never accidentally issue a memory operation for an unaccepted request.

 STEP 4: HANDLE WRITE REQUESTS
    - Enable writing on BOTH K and V memories simultaneously.
    - Send req_k_data to the K memory.
    - Send req_v_data to the V memory.
    - Use req_addr for BOTH memory addresses.
    - A write request does NOT generate a read response.
    - A write is complete once the RAM accepts the write at the clock edge.

 STEP 5: HANDLE READ REQUESTS
    - Enable reading on BOTH K and V memories simultaneously.
    - Disable writes to both memories.
    - Use req_addr for BOTH read addresses.
    - Your RAM has SYNCHRONOUS read behavior.
    - Therefore, account for the clock cycle between issuing the read
      and presenting the returned data.
    - Do not assert rsp_valid before the read data is available.

 STEP 6: TRACK READ RESPONSES
    - After a read request is accepted, track that a read response is pending.
    - Once the RAM outputs contain the requested K/V data, assert rsp_valid.
    - Connect the RAM outputs to rsp_k_data and rsp_v_data.
    - Keep rsp_valid asserted until rsp_ready is also asserted.
    - Do NOT issue another request while the current response is stalled.
    - Ensure both K and V response data remain aligned.

 STEP 7: IMPLEMENT RESPONSE HANDSHAKING
    - A response is consumed on a rising clock edge when BOTH rsp_valid
      and rsp_ready are high.
    - Once consumed, deassert rsp_valid.
    - The interface can then accept another request.
    - A response must never be lost just because the receiver is not ready.

 STEP 8: IMPLEMENT RESET
    - rst_n is active-low.
    - Reset all internal control registers.
    - Clear pending-read state.
    - Clear rsp_valid.
    - Return the interface to its idle/ready condition.
    - Do NOT reset the contents of the RAM arrays.

 STEP 9: IMPLEMENT STATUS
    - mem_busy should indicate that the interface is processing a transaction
      or holding an unconsumed response.
    - mem_busy should be low when the interface is idle.

===============================================================================
 IMPORTANT DESIGN CONSTRAINTS:

    - K and V operations must always happen in parallel.
    - K and V must always use the same physical address.
    - Never allow K and V data to become mismatched.
    - Only one request may be outstanding at a time.
    - Do not implement page translation or allocation here.
    - Do not implement arbitration here.
    - Do not add unnecessary pipeline stages.
    - Keep the design synchronous to clk.

===============================================================================
 TESTBENCH CHECKLIST:

    [ ] Write known K/V vectors to the same address.
    [ ] Read them back and compare against expected values.
    [ ] Verify K and V are accessed simultaneously.
    [ ] Verify read-after-write behavior.
    [ ] Write different values to multiple addresses.
    [ ] Read multiple addresses back-to-back.
    [ ] Hold rsp_ready LOW and verify rsp_valid/data remain stable.
    [ ] Verify no request is accepted while the response is stalled.
    [ ] Verify reset clears control state.
    [ ] Verify no read response is generated for a write.
    [ ] Verify no data is lost during request/response handshakes.

===============================================================================
*/

module mem_interface #(
    parameter int WORD_W = 256,
    parameter int DEPTH = 256,
    parameter int ADDR_W = 8
)(
    input logic rst_n, clk,

    input logic req_valid, req_write,
    input logic [ADDR_W - 1: 0] req_addr,
    input logic [WORD_W - 1: 0] req_data_k,
    input logic [WORD_W - 1: 0] req_data_v,
    input logic resp_ready,
    
    output logic [WORD_W - 1: 0] resp_data_k,
    output logic [WORD_W - 1: 0] resp_data_v,
    output logic resp_valid,
    output logic req_ready,
    output logic status
);

    logic wr_en, rd_en; 

    kv_block_ram k_ram(
        .clk(clk), .rst_n(rst_n), .wr_en(wr_en), rd_en(rd_en),
        .wr_addr(req_addr),
        .rd_addr(req_addr),
        .wr_data(req_data_k),
        .rd_data(resp_data_k));

    kv_block_ram v_ram(
        .clk(clk), .rst_n(rst_n), .wr_en(wr_en), rd_en(rd_en),
        .wr_addr(req_addr),
        .rd_addr(req_addr),
        .wr_data(req_data_v),
        .rd_data(resp_data_v));

    always_comb begin
        if (req_valid && req_ready) begin
<<<<<<< HEAD
            // wr_en <= req_write_k || req_write_v;
=======
>>>>>>> c75dc6b2354d9ef6b8f8a8375b127e7a5b404588
            case(req_write)
                1'b1: wr_en = 1'b1;
                1'b0: rd_en = 1'b1;
                default: begin
                    wr_en = 1'b0;
                    rd_en = 1'b0;
                end
            endcase
        end 
        
    end

    always_ff @(posedge clk) begin

    end
 

 - Enable writing on BOTH K and V memories simultaneously.
    - Send req_k_data to the K memory.
    - Send req_v_data to the V memory.
    - Use req_addr for BOTH memory addresses.
    - A write request does NOT generate a read response.
    - A write is complete once the RAM accepts the write at the clock edge.


    


endmodule