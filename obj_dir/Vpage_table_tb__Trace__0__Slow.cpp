// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vpage_table_tb__Syms.h"


VL_ATTR_COLD void Vpage_table_tb___024root__trace_init_dtype____1(Vpage_table_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vpage_table_tb___024root__trace_init_sub__TOP__0(Vpage_table_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root__trace_init_sub__TOP__0\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "page_table_tb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+43,0,"NUM_PAGES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+44,0,"PAGE_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+22,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"lookup_l_page",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"wr_lpage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"wr_ppage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+23,0,"lookup_p_page",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+24,0,"lookup_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+45,0,"checks",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+25,0,"errors",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"test_errors",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "exp_page", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 15);
    for (int i = 0; i < 16; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+6+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 3,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "dut", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+43,0,"NUM_PAGES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+44,0,"PAGE_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+22,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"lookup_l_page",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+23,0,"lookup_p_page",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+24,0,"lookup_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"wr_lpage",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"wr_ppage",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);

    Vpage_table_tb___024root__trace_init_dtype____1(vlSelf, tracep, "ppage_table", 0, c+26, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+42,0,"valid_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vpage_table_tb___024root__trace_init_dtype_sub____1(Vpage_table_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vpage_table_tb___024root__trace_init_dtype____1(Vpage_table_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root__trace_init_dtype____1\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vpage_table_tb___024root__trace_init_dtype_sub____1(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vpage_table_tb___024root__trace_init_dtype_sub____1(Vpage_table_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root__trace_init_dtype_sub____1\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 15, 0);
    for (int i = 0; i < 16; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (15 - i), 3,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vpage_table_tb___024root__trace_init_top(Vpage_table_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root__trace_init_top\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vpage_table_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vpage_table_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vpage_table_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpage_table_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpage_table_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vpage_table_tb___024root__trace_register(Vpage_table_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root__trace_register\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vpage_table_tb___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vpage_table_tb___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vpage_table_tb___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vpage_table_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vpage_table_tb___024root__trace_const_0_sub_0(Vpage_table_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vpage_table_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root__trace_const_0\n"); );
    // Body
    Vpage_table_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpage_table_tb___024root*>(voidSelf);
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vpage_table_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vpage_table_tb___024root__trace_const_0_sub_0(Vpage_table_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root__trace_const_0_sub_0\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+43,(0x00000010U),32);
    bufp->fullIData(oldp+44,(4U),32);
    bufp->fullIData(oldp+45,(0U),32);
}

VL_ATTR_COLD void Vpage_table_tb___024root__trace_full_0_sub_0(Vpage_table_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vpage_table_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root__trace_full_0\n"); );
    // Body
    Vpage_table_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpage_table_tb___024root*>(voidSelf);
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vpage_table_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vpage_table_tb___024root__trace_full_dtype____0(Vpage_table_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 16>& __VdtypeVar);

VL_ATTR_COLD void Vpage_table_tb___024root__trace_full_0_sub_0(Vpage_table_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root__trace_full_0_sub_0\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+0,(vlSelfRef.page_table_tb__DOT__rst_n));
    bufp->fullCData(oldp+1,(vlSelfRef.page_table_tb__DOT__lookup_l_page),4);
    bufp->fullBit(oldp+2,(vlSelfRef.page_table_tb__DOT__wr_en));
    bufp->fullCData(oldp+3,(vlSelfRef.page_table_tb__DOT__wr_lpage),4);
    bufp->fullCData(oldp+4,(vlSelfRef.page_table_tb__DOT__wr_ppage),4);
    bufp->fullIData(oldp+5,(vlSelfRef.page_table_tb__DOT__test_errors),32);
    bufp->fullCData(oldp+6,(vlSelfRef.page_table_tb__DOT__exp_page[0]),4);
    bufp->fullCData(oldp+7,(vlSelfRef.page_table_tb__DOT__exp_page[1]),4);
    bufp->fullCData(oldp+8,(vlSelfRef.page_table_tb__DOT__exp_page[2]),4);
    bufp->fullCData(oldp+9,(vlSelfRef.page_table_tb__DOT__exp_page[3]),4);
    bufp->fullCData(oldp+10,(vlSelfRef.page_table_tb__DOT__exp_page[4]),4);
    bufp->fullCData(oldp+11,(vlSelfRef.page_table_tb__DOT__exp_page[5]),4);
    bufp->fullCData(oldp+12,(vlSelfRef.page_table_tb__DOT__exp_page[6]),4);
    bufp->fullCData(oldp+13,(vlSelfRef.page_table_tb__DOT__exp_page[7]),4);
    bufp->fullCData(oldp+14,(vlSelfRef.page_table_tb__DOT__exp_page[8]),4);
    bufp->fullCData(oldp+15,(vlSelfRef.page_table_tb__DOT__exp_page[9]),4);
    bufp->fullCData(oldp+16,(vlSelfRef.page_table_tb__DOT__exp_page[10]),4);
    bufp->fullCData(oldp+17,(vlSelfRef.page_table_tb__DOT__exp_page[11]),4);
    bufp->fullCData(oldp+18,(vlSelfRef.page_table_tb__DOT__exp_page[12]),4);
    bufp->fullCData(oldp+19,(vlSelfRef.page_table_tb__DOT__exp_page[13]),4);
    bufp->fullCData(oldp+20,(vlSelfRef.page_table_tb__DOT__exp_page[14]),4);
    bufp->fullCData(oldp+21,(vlSelfRef.page_table_tb__DOT__exp_page[15]),4);
    bufp->fullBit(oldp+22,(vlSelfRef.page_table_tb__DOT__clk));
    bufp->fullCData(oldp+23,(vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table
                             [vlSelfRef.page_table_tb__DOT__lookup_l_page]),4);
    bufp->fullBit(oldp+24,((1U & ((IData)(vlSelfRef.page_table_tb__DOT__dut__DOT__valid_bits) 
                                  >> (IData)(vlSelfRef.page_table_tb__DOT__lookup_l_page)))));
    bufp->fullIData(oldp+25,(vlSelfRef.page_table_tb__DOT__errors),32);
    Vpage_table_tb___024root__trace_full_dtype____0(vlSelf, bufp, 26, vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table);
    bufp->fullSData(oldp+42,(vlSelfRef.page_table_tb__DOT__dut__DOT__valid_bits),16);
}

VL_ATTR_COLD void Vpage_table_tb___024root__trace_full_dtype____0(Vpage_table_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root__trace_full_dtype____0\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullCData(oldp+0,(__VdtypeVar[15]),4);
    bufp->fullCData(oldp+1,(__VdtypeVar[14]),4);
    bufp->fullCData(oldp+2,(__VdtypeVar[13]),4);
    bufp->fullCData(oldp+3,(__VdtypeVar[12]),4);
    bufp->fullCData(oldp+4,(__VdtypeVar[11]),4);
    bufp->fullCData(oldp+5,(__VdtypeVar[10]),4);
    bufp->fullCData(oldp+6,(__VdtypeVar[9]),4);
    bufp->fullCData(oldp+7,(__VdtypeVar[8]),4);
    bufp->fullCData(oldp+8,(__VdtypeVar[7]),4);
    bufp->fullCData(oldp+9,(__VdtypeVar[6]),4);
    bufp->fullCData(oldp+10,(__VdtypeVar[5]),4);
    bufp->fullCData(oldp+11,(__VdtypeVar[4]),4);
    bufp->fullCData(oldp+12,(__VdtypeVar[3]),4);
    bufp->fullCData(oldp+13,(__VdtypeVar[2]),4);
    bufp->fullCData(oldp+14,(__VdtypeVar[1]),4);
    bufp->fullCData(oldp+15,(__VdtypeVar[0]),4);
}
