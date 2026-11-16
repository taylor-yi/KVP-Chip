// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vpage_table_tb__Syms.h"


void Vpage_table_tb___024root__trace_chg_0_sub_0(Vpage_table_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vpage_table_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root__trace_chg_0\n"); );
    // Body
    Vpage_table_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpage_table_tb___024root*>(voidSelf);
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vpage_table_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vpage_table_tb___024root__trace_chg_dtype____0(Vpage_table_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 16>& __VdtypeVar);

void Vpage_table_tb___024root__trace_chg_0_sub_0(Vpage_table_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root__trace_chg_0_sub_0\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.page_table_tb__DOT__rst_n));
        bufp->chgCData(oldp+1,(vlSelfRef.page_table_tb__DOT__lookup_l_page),4);
        bufp->chgBit(oldp+2,(vlSelfRef.page_table_tb__DOT__wr_en));
        bufp->chgCData(oldp+3,(vlSelfRef.page_table_tb__DOT__wr_lpage),4);
        bufp->chgCData(oldp+4,(vlSelfRef.page_table_tb__DOT__wr_ppage),4);
        bufp->chgIData(oldp+5,(vlSelfRef.page_table_tb__DOT__test_errors),32);
        bufp->chgCData(oldp+6,(vlSelfRef.page_table_tb__DOT__exp_page[0]),4);
        bufp->chgCData(oldp+7,(vlSelfRef.page_table_tb__DOT__exp_page[1]),4);
        bufp->chgCData(oldp+8,(vlSelfRef.page_table_tb__DOT__exp_page[2]),4);
        bufp->chgCData(oldp+9,(vlSelfRef.page_table_tb__DOT__exp_page[3]),4);
        bufp->chgCData(oldp+10,(vlSelfRef.page_table_tb__DOT__exp_page[4]),4);
        bufp->chgCData(oldp+11,(vlSelfRef.page_table_tb__DOT__exp_page[5]),4);
        bufp->chgCData(oldp+12,(vlSelfRef.page_table_tb__DOT__exp_page[6]),4);
        bufp->chgCData(oldp+13,(vlSelfRef.page_table_tb__DOT__exp_page[7]),4);
        bufp->chgCData(oldp+14,(vlSelfRef.page_table_tb__DOT__exp_page[8]),4);
        bufp->chgCData(oldp+15,(vlSelfRef.page_table_tb__DOT__exp_page[9]),4);
        bufp->chgCData(oldp+16,(vlSelfRef.page_table_tb__DOT__exp_page[10]),4);
        bufp->chgCData(oldp+17,(vlSelfRef.page_table_tb__DOT__exp_page[11]),4);
        bufp->chgCData(oldp+18,(vlSelfRef.page_table_tb__DOT__exp_page[12]),4);
        bufp->chgCData(oldp+19,(vlSelfRef.page_table_tb__DOT__exp_page[13]),4);
        bufp->chgCData(oldp+20,(vlSelfRef.page_table_tb__DOT__exp_page[14]),4);
        bufp->chgCData(oldp+21,(vlSelfRef.page_table_tb__DOT__exp_page[15]),4);
    }
    bufp->chgBit(oldp+22,(vlSelfRef.page_table_tb__DOT__clk));
    bufp->chgCData(oldp+23,(vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table
                            [vlSelfRef.page_table_tb__DOT__lookup_l_page]),4);
    bufp->chgBit(oldp+24,((1U & ((IData)(vlSelfRef.page_table_tb__DOT__dut__DOT__valid_bits) 
                                 >> (IData)(vlSelfRef.page_table_tb__DOT__lookup_l_page)))));
    bufp->chgIData(oldp+25,(vlSelfRef.page_table_tb__DOT__errors),32);
    Vpage_table_tb___024root__trace_chg_dtype____0(vlSelf, bufp, 26, vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table);
    bufp->chgSData(oldp+42,(vlSelfRef.page_table_tb__DOT__dut__DOT__valid_bits),16);
}

void Vpage_table_tb___024root__trace_chg_dtype____0(Vpage_table_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root__trace_chg_dtype____0\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgCData(oldp+0,(__VdtypeVar[15]),4);
    bufp->chgCData(oldp+1,(__VdtypeVar[14]),4);
    bufp->chgCData(oldp+2,(__VdtypeVar[13]),4);
    bufp->chgCData(oldp+3,(__VdtypeVar[12]),4);
    bufp->chgCData(oldp+4,(__VdtypeVar[11]),4);
    bufp->chgCData(oldp+5,(__VdtypeVar[10]),4);
    bufp->chgCData(oldp+6,(__VdtypeVar[9]),4);
    bufp->chgCData(oldp+7,(__VdtypeVar[8]),4);
    bufp->chgCData(oldp+8,(__VdtypeVar[7]),4);
    bufp->chgCData(oldp+9,(__VdtypeVar[6]),4);
    bufp->chgCData(oldp+10,(__VdtypeVar[5]),4);
    bufp->chgCData(oldp+11,(__VdtypeVar[4]),4);
    bufp->chgCData(oldp+12,(__VdtypeVar[3]),4);
    bufp->chgCData(oldp+13,(__VdtypeVar[2]),4);
    bufp->chgCData(oldp+14,(__VdtypeVar[1]),4);
    bufp->chgCData(oldp+15,(__VdtypeVar[0]),4);
}

void Vpage_table_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root__trace_cleanup\n"); );
    // Body
    Vpage_table_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpage_table_tb___024root*>(voidSelf);
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
