#!/bin/bash
set -e

if [ -z "$1" ]; then
	echo "Fail. Usage is ./build.sh <testbench_name>"
	exit 1
fi

TB=testbenches/"$1".sv
if [ ! -f "$TB" ]; then
	echo "Fail. $TB not found"
	exit 1
fi

verilator --binary --trace -j 0 -Wno-fatal \
	kvp_pkg.sv "$TB" \
	-y . \
	--top-module "$1"

./obj_dir/V"$1"
