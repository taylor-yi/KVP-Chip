// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vpage_allocator_tb__Syms.h"


VL_ATTR_COLD void Vpage_allocator_tb___024root__trace_init_sub__TOP__kvp_pkg__0(Vpage_allocator_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vpage_allocator_tb___024root__trace_init_sub__TOP__0(Vpage_allocator_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root__trace_init_sub__TOP__0\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "kvp_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vpage_allocator_tb___024root__trace_init_sub__TOP__kvp_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "page_allocator_tb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+15,0,"NUM_PAGES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"PAGE_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+9,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"free_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+2,0,"free_ppage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+3,0,"alloc_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"alloc_page",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+10,0,"alloc_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+11,0,"alloc_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+12,0,"free_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+13,0,"checks",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+14,0,"errors",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"test_errors",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "dut", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+9,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"free_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+2,0,"free_ppage",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+3,0,"alloc_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"alloc_page",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+10,0,"alloc_ok",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+11,0,"alloc_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+12,0,"free_ok",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"used_map",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+8,0,"found_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vpage_allocator_tb___024root__trace_init_sub__TOP__kvp_pkg__0(Vpage_allocator_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root__trace_init_sub__TOP__kvp_pkg__0\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+15,0,"ELEM_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+15,0,"HEAD_DIM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+15,0,"PAGE_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+15,0,"NUM_PAGES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+17,0,"WORD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+17,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+18,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"PAGE_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"OFFSET_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+17,0,"MAX_TOKENS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+19,0,"TOKEN_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
}

VL_ATTR_COLD void Vpage_allocator_tb___024root__trace_init_top(Vpage_allocator_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root__trace_init_top\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vpage_allocator_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vpage_allocator_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vpage_allocator_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpage_allocator_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpage_allocator_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vpage_allocator_tb___024root__trace_register(Vpage_allocator_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root__trace_register\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vpage_allocator_tb___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vpage_allocator_tb___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vpage_allocator_tb___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vpage_allocator_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vpage_allocator_tb___024root__trace_const_0_sub_0(Vpage_allocator_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vpage_allocator_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root__trace_const_0\n"); );
    // Body
    Vpage_allocator_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpage_allocator_tb___024root*>(voidSelf);
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vpage_allocator_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vpage_allocator_tb___024root__trace_const_0_sub_0(Vpage_allocator_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root__trace_const_0_sub_0\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+15,(0x00000010U),32);
    bufp->fullIData(oldp+16,(4U),32);
    bufp->fullIData(oldp+17,(0x00000100U),32);
    bufp->fullIData(oldp+18,(8U),32);
    bufp->fullIData(oldp+19,(9U),32);
}

VL_ATTR_COLD void Vpage_allocator_tb___024root__trace_full_0_sub_0(Vpage_allocator_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vpage_allocator_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root__trace_full_0\n"); );
    // Body
    Vpage_allocator_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpage_allocator_tb___024root*>(voidSelf);
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vpage_allocator_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vpage_allocator_tb___024root__trace_full_0_sub_0(Vpage_allocator_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root__trace_full_0_sub_0\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+0,(vlSelfRef.page_allocator_tb__DOT__rst_n));
    bufp->fullBit(oldp+1,(vlSelfRef.page_allocator_tb__DOT__free_en));
    bufp->fullCData(oldp+2,(vlSelfRef.page_allocator_tb__DOT__free_ppage),4);
    bufp->fullBit(oldp+3,(vlSelfRef.page_allocator_tb__DOT__alloc_req));
    bufp->fullIData(oldp+4,(vlSelfRef.page_allocator_tb__DOT__test_errors),32);
    bufp->fullCData(oldp+5,(vlSelfRef.page_allocator_tb__DOT__alloc_page),4);
    bufp->fullSData(oldp+6,(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map),16);
    bufp->fullBit(oldp+7,((0x0000ffffU == (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map))));
    bufp->fullBit(oldp+8,(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag));
    bufp->fullBit(oldp+9,(vlSelfRef.page_allocator_tb__DOT__clk));
    bufp->fullBit(oldp+10,(((~ (0x0000ffffU == (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map))) 
                            & (IData)(vlSelfRef.page_allocator_tb__DOT__alloc_req))));
    bufp->fullBit(oldp+11,(((IData)(vlSelfRef.page_allocator_tb__DOT__alloc_req) 
                            & (0x0000ffffU == (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map)))));
    bufp->fullBit(oldp+12,(((~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                                >> (IData)(vlSelfRef.page_allocator_tb__DOT__free_ppage))) 
                            & (IData)(vlSelfRef.page_allocator_tb__DOT__free_en))));
    bufp->fullIData(oldp+13,(vlSelfRef.page_allocator_tb__DOT__checks),32);
    bufp->fullIData(oldp+14,(vlSelfRef.page_allocator_tb__DOT__errors),32);
}
