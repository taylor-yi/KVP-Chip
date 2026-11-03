module kv_mem_interface #(
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
    output logic req_ready
    // output logic status
);

    typedef enum logic {IDLE, RESPONSE} state_t;
    state_t read_state;

    logic wr_en, rd_en, accept ;

    kv_block_ram #(.WORD_W(WORD_W), .DEPTH(DEPTH), .ADDR_W(ADDR_W)) k_ram (
        .clk(clk), .rst_n(rst_n), .wr_en(wr_en), .rd_en(rd_en),
        .wr_addr(req_addr),
        .rd_addr(req_addr),
        .wr_data(req_data_k),
        .rd_data(resp_data_k));

    kv_block_ram #(.WORD_W(WORD_W), .DEPTH(DEPTH), .ADDR_W(ADDR_W)) v_ram (
        .clk(clk), .rst_n(rst_n), .wr_en(wr_en), .rd_en(rd_en),
        .wr_addr(req_addr),
        .rd_addr(req_addr),
        .wr_data(req_data_v),
        .rd_data(resp_data_v));

    // Establish handshake
    assign req_ready = (read_state == IDLE);
    assign accept = req_valid && req_ready;

    // Decode req_write, 1 is a write request 0 is a read request
    always_comb begin
        if (accept) begin
            wr_en = req_write;
            rd_en = !req_write;
        end else begin
            wr_en = 1'b0;
            rd_en = 1'b0;
        end
    end

    always_ff @(posedge clk) begin
        if (!rst_n)
            read_state <= IDLE;
        else 
            case(read_state)
                IDLE: begin
                    if(rd_en) begin
                        read_state <= RESPONSE;
                    end
                end
                RESPONSE: begin
                    if (resp_ready) begin
                        read_state <= IDLE;
                    end
                end
                default: begin
                    read_state <= IDLE;
                end
            endcase
    end

    assign resp_valid = (read_state == RESPONSE);
 
endmodule