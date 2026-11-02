verilator --binary --trace -j 0 kv_block_ram.sv --top-module kv_block_ram_tb
./obj_dir/Vkv_block_ram_tb
surfer dump.vcd