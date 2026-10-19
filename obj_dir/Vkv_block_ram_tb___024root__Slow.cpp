// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkv_block_ram_tb.h for the primary calling header

#include "Vkv_block_ram_tb__pch.h"

void Vkv_block_ram_tb___024root___ctor_var_reset(Vkv_block_ram_tb___024root* vlSelf);

Vkv_block_ram_tb___024root::Vkv_block_ram_tb___024root(Vkv_block_ram_tb__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vkv_block_ram_tb___024root___ctor_var_reset(this);
}

void Vkv_block_ram_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vkv_block_ram_tb___024root::~Vkv_block_ram_tb___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
