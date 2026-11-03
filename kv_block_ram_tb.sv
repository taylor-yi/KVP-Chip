`timescale 1ns/1ps
module kv_block_ram_tb();
    logic clk, wr_en;
    logic [7:0] wr_addr, rd_addr;
    logic [255:0] wr_data, rd_data;

    kv_block_ram dut(.*);

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        $dumpfile("dump.vcd");     // the output file's name
        $dumpvars(0, kv_block_ram_tb);    // depth 0 = this scope AND everything under it
    end

    initial begin
        //WRITE TB IN HERE
        wr_en = 0;
        wr_addr = '0;
        rd_addr = '0;
        wr_data = '0;
        rd_data = '0;
        #20;
        wr_en = 1;
        wr_addr = 8'h55;
        wr_data = '1;
        #10;
        rd_addr = 8'h55;
        wr_data = 0;
        #10;
        $finish;
    end
        
endmodule