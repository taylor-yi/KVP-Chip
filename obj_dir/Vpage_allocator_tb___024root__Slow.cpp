// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpage_allocator_tb.h for the primary calling header

#include "Vpage_allocator_tb__pch.h"

void Vpage_allocator_tb___024root___ctor_var_reset(Vpage_allocator_tb___024root* vlSelf);

Vpage_allocator_tb___024root::Vpage_allocator_tb___024root(Vpage_allocator_tb__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vpage_allocator_tb___024root___ctor_var_reset(this);
}

void Vpage_allocator_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vpage_allocator_tb___024root::~Vpage_allocator_tb___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
