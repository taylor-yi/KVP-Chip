// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vkv_mem_interface_tb__Syms.h"


void Vkv_mem_interface_tb___024root__trace_chg_0_sub_0(Vkv_mem_interface_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vkv_mem_interface_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root__trace_chg_0\n"); );
    // Body
    Vkv_mem_interface_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkv_mem_interface_tb___024root*>(voidSelf);
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vkv_mem_interface_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vkv_mem_interface_tb___024root__trace_chg_0_sub_0(Vkv_mem_interface_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root__trace_chg_0_sub_0\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.kv_mem_interface_tb__DOT__rst_n));
        bufp->chgBit(oldp+1,(vlSelfRef.kv_mem_interface_tb__DOT__req_valid));
        bufp->chgBit(oldp+2,(vlSelfRef.kv_mem_interface_tb__DOT__req_write));
        bufp->chgCData(oldp+3,(vlSelfRef.kv_mem_interface_tb__DOT__req_addr),8);
        bufp->chgWData(oldp+4,(vlSelfRef.kv_mem_interface_tb__DOT__req_data_k),256);
        bufp->chgWData(oldp+12,(vlSelfRef.kv_mem_interface_tb__DOT__req_data_v),256);
        bufp->chgBit(oldp+20,(vlSelfRef.kv_mem_interface_tb__DOT__resp_ready));
        bufp->chgIData(oldp+21,(vlSelfRef.kv_mem_interface_tb__DOT__test_errors),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgWData(oldp+22,(vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k),256);
        bufp->chgWData(oldp+30,(vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v),256);
        bufp->chgBit(oldp+38,(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state));
        bufp->chgBit(oldp+39,((1U & (~ (IData)(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state)))));
        bufp->chgBit(oldp+40,(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state));
    }
    bufp->chgBit(oldp+41,(vlSelfRef.kv_mem_interface_tb__DOT__clk));
    bufp->chgIData(oldp+42,(vlSelfRef.kv_mem_interface_tb__DOT__errors),32);
    bufp->chgBit(oldp+43,(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__wr_en));
    bufp->chgBit(oldp+44,(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__rd_en));
    bufp->chgBit(oldp+45,(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__accept));
}

void Vkv_mem_interface_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root__trace_cleanup\n"); );
    // Body
    Vkv_mem_interface_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkv_mem_interface_tb___024root*>(voidSelf);
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
