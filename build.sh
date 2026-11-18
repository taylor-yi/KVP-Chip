#!/bin/bash
set -e

if [ -z "$1" ]; then
	echo "Fail. Usage is ./build.sh <top_module>"
	exit 1
fi

verilator --binary --trace -j 0 *.sv --top-module "$1"
./obj_dir/V"$1"
