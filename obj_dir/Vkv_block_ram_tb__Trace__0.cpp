// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vkv_block_ram_tb__Syms.h"


void Vkv_block_ram_tb___024root__trace_chg_0_sub_0(Vkv_block_ram_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vkv_block_ram_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root__trace_chg_0\n"); );
    // Body
    Vkv_block_ram_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkv_block_ram_tb___024root*>(voidSelf);
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vkv_block_ram_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vkv_block_ram_tb___024root__trace_chg_0_sub_0(Vkv_block_ram_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root__trace_chg_0_sub_0\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.kv_block_ram_tb__DOT__wr_en));
        bufp->chgCData(oldp+1,(vlSelfRef.kv_block_ram_tb__DOT__wr_addr),8);
        bufp->chgCData(oldp+2,(vlSelfRef.kv_block_ram_tb__DOT__rd_addr),8);
        bufp->chgWData(oldp+3,(vlSelfRef.kv_block_ram_tb__DOT__wr_data),256);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity[1U] 
                       | vlSelfRef.__Vm_traceActivity[2U]) 
                      | vlSelfRef.__Vm_traceActivity[3U])))) {
        bufp->chgWData(oldp+11,(vlSelfRef.kv_block_ram_tb__DOT__rd_data),256);
    }
    bufp->chgBit(oldp+19,(vlSelfRef.kv_block_ram_tb__DOT__clk));
}

void Vkv_block_ram_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root__trace_cleanup\n"); );
    // Body
    Vkv_block_ram_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkv_block_ram_tb___024root*>(voidSelf);
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
