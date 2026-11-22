// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vpage_allocator_tb__Syms.h"


void Vpage_allocator_tb___024root__trace_chg_0_sub_0(Vpage_allocator_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vpage_allocator_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root__trace_chg_0\n"); );
    // Body
    Vpage_allocator_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpage_allocator_tb___024root*>(voidSelf);
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vpage_allocator_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vpage_allocator_tb___024root__trace_chg_0_sub_0(Vpage_allocator_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root__trace_chg_0_sub_0\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.page_allocator_tb__DOT__rst_n));
        bufp->chgBit(oldp+1,(vlSelfRef.page_allocator_tb__DOT__free_en));
        bufp->chgCData(oldp+2,(vlSelfRef.page_allocator_tb__DOT__free_ppage),4);
        bufp->chgBit(oldp+3,(vlSelfRef.page_allocator_tb__DOT__alloc_req));
        bufp->chgIData(oldp+4,(vlSelfRef.page_allocator_tb__DOT__test_errors),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgSData(oldp+5,(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map),16);
        bufp->chgBit(oldp+6,((0x0000ffffU == (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map))));
        bufp->chgBit(oldp+7,(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag));
    }
    bufp->chgBit(oldp+8,(vlSelfRef.page_allocator_tb__DOT__clk));
    bufp->chgCData(oldp+9,(vlSelfRef.page_allocator_tb__DOT__alloc_page),4);
    bufp->chgBit(oldp+10,(vlSelfRef.page_allocator_tb__DOT__alloc_ok));
    bufp->chgBit(oldp+11,(vlSelfRef.page_allocator_tb__DOT__alloc_error));
    bufp->chgIData(oldp+12,(vlSelfRef.page_allocator_tb__DOT__errors),32);
}

void Vpage_allocator_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root__trace_cleanup\n"); );
    // Body
    Vpage_allocator_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpage_allocator_tb___024root*>(voidSelf);
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
