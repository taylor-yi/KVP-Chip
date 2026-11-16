// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpage_table_tb.h for the primary calling header

#include "Vpage_table_tb__pch.h"

VlCoroutine Vpage_table_tb___024root___eval_initial__TOP__Vtiming__0(Vpage_table_tb___024root* vlSelf);
VlCoroutine Vpage_table_tb___024root___eval_initial__TOP__Vtiming__1(Vpage_table_tb___024root* vlSelf);

void Vpage_table_tb___024root___eval_initial(Vpage_table_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___eval_initial\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        vlSymsp->_vm_contextp__->dumpfile("dump.vcd"s);
        vlSymsp->_traceDumpOpen();
    }
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vpage_table_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vpage_table_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vpage_table_tb___024root___eval_sample(Vpage_table_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___eval_sample\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpage_table_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vpage_table_tb___024root___eval_ico(Vpage_table_tb___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___eval_ico\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vpage_table_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

void Vpage_table_tb___024root___timing_ready(Vpage_table_tb___024root* vlSelf);
void Vpage_table_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpage_table_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vpage_table_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vpage_table_tb___024root___timing_resume(Vpage_table_tb___024root* vlSelf);

bool Vpage_table_tb___024root___eval_act(Vpage_table_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___eval_act\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((((~ (IData)(vlSelfRef.page_table_tb__DOT__clk)) 
                                                           & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__page_table_tb__DOT__clk__0)) 
                                                          << 2U) 
                                                         | ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.page_table_tb__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__page_table_tb__DOT__clk__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__page_table_tb__DOT__clk__0 
            = vlSelfRef.page_table_tb__DOT__clk;
    }
    Vpage_table_tb___024root___timing_ready(vlSelf);
    Vpage_table_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vpage_table_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vpage_table_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vpage_table_tb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vpage_table_tb___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vpage_table_tb___024root___eval_inact(Vpage_table_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___eval_inact\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("page_table_tb.sv", 2, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vpage_table_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vpage_table_tb___024root___eval_nba(Vpage_table_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___eval_nba\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vpage_table_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__0
                    CData/*3:0*/ __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___VdlyVal__page_table_tb__DOT__dut__DOT__ppage_table__v0;
                    __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___VdlyVal__page_table_tb__DOT__dut__DOT__ppage_table__v0 = 0;
                    CData/*3:0*/ __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___VdlyDim0__page_table_tb__DOT__dut__DOT__ppage_table__v0;
                    __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___VdlyDim0__page_table_tb__DOT__dut__DOT__ppage_table__v0 = 0;
                    CData/*0:0*/ __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___VdlySet__page_table_tb__DOT__dut__DOT__ppage_table__v0;
                    __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___VdlySet__page_table_tb__DOT__dut__DOT__ppage_table__v0 = 0;
                    __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___VdlySet__page_table_tb__DOT__dut__DOT__ppage_table__v0 = 0U;
                    if (vlSelfRef.page_table_tb__DOT__rst_n) {
                        if (vlSelfRef.page_table_tb__DOT__wr_en) {
                            __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___VdlyVal__page_table_tb__DOT__dut__DOT__ppage_table__v0 
                                = vlSelfRef.page_table_tb__DOT__wr_ppage;
                            __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___VdlyDim0__page_table_tb__DOT__dut__DOT__ppage_table__v0 
                                = vlSelfRef.page_table_tb__DOT__wr_lpage;
                            __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___VdlySet__page_table_tb__DOT__dut__DOT__ppage_table__v0 = 1U;
                            vlSelfRef.page_table_tb__DOT__dut__DOT__valid_bits 
                                = ((IData)(vlSelfRef.page_table_tb__DOT__dut__DOT__valid_bits) 
                                   | (0x0000ffffU & 
                                      ((IData)(1U) 
                                       << (IData)(vlSelfRef.page_table_tb__DOT__wr_lpage))));
                        }
                    } else {
                        vlSelfRef.page_table_tb__DOT__dut__DOT__valid_bits = 0U;
                    }
                    if (__Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___VdlySet__page_table_tb__DOT__dut__DOT__ppage_table__v0) {
                        vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table[__Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___VdlyDim0__page_table_tb__DOT__dut__DOT__ppage_table__v0] 
                            = __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___VdlyVal__page_table_tb__DOT__dut__DOT__ppage_table__v0;
                    }
                }
            }
        }
        Vpage_table_tb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vpage_table_tb___024root___eval_obs(Vpage_table_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___eval_obs\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vpage_table_tb___024root___eval_react(Vpage_table_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___eval_react\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vpage_table_tb___024root___eval_postponed(Vpage_table_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___eval_postponed\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VlCoroutine Vpage_table_tb___024root___eval_initial__TOP__Vtiming__0(Vpage_table_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.page_table_tb__DOT__clk = 0U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "page_table_tb.sv", 
                                             27);
        vlSelfRef.page_table_tb__DOT__clk = (1U & (~ (IData)(vlSelfRef.page_table_tb__DOT__clk)));
    }
    co_return;
}

void Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(Vpage_table_tb___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vpage_table_tb___024root___eval_initial__TOP__Vtiming__1(Vpage_table_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ page_table_tb__DOT__unnamedblk3__DOT__i;
    page_table_tb__DOT__unnamedblk3__DOT__i = 0;
    IData/*31:0*/ page_table_tb__DOT__unnamedblk4__DOT__i;
    page_table_tb__DOT__unnamedblk4__DOT__i = 0;
    IData/*31:0*/ page_table_tb__DOT__unnamedblk5__DOT__i;
    page_table_tb__DOT__unnamedblk5__DOT__i = 0;
    IData/*31:0*/ page_table_tb__DOT__unnamedblk6__DOT__i;
    page_table_tb__DOT__unnamedblk6__DOT__i = 0;
    IData/*31:0*/ page_table_tb__DOT__unnamedblk7__DOT__i;
    page_table_tb__DOT__unnamedblk7__DOT__i = 0;
    IData/*31:0*/ __Vtask_page_table_tb__DOT__fill_table__2__unnamedblk1__DOT__i;
    __Vtask_page_table_tb__DOT__fill_table__2__unnamedblk1__DOT__i = 0;
    IData/*31:0*/ __Vtask_page_table_tb__DOT__fill_table_rand__4__unnamedblk2__DOT__i;
    __Vtask_page_table_tb__DOT__fill_table_rand__4__unnamedblk2__DOT__i = 0;
    IData/*31:0*/ __Vtask_page_table_tb__DOT__fill_table_rand__6__unnamedblk2__DOT__i;
    __Vtask_page_table_tb__DOT__fill_table_rand__6__unnamedblk2__DOT__i = 0;
    // Body
    vlSelfRef.page_table_tb__DOT__test_errors = vlSelfRef.page_table_tb__DOT__errors;
    vlSelfRef.page_table_tb__DOT__rst_n = 0U;
    vlSelfRef.page_table_tb__DOT__lookup_l_page = 0U;
    vlSelfRef.page_table_tb__DOT__wr_en = 0U;
    vlSelfRef.page_table_tb__DOT__wr_lpage = 0U;
    vlSelfRef.page_table_tb__DOT__wr_ppage = 0U;
    Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                         "@(negedge page_table_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_table_tb.clk)", 
                                                         "page_table_tb.sv", 
                                                         37);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.page_table_tb__DOT__rst_n = 1U;
    vlSelfRef.page_table_tb__DOT__wr_en = 1U;
    vlSelfRef.page_table_tb__DOT__wr_ppage = 1U;
    vlSelfRef.page_table_tb__DOT__wr_lpage = 0x0fU;
    Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                         "@(negedge page_table_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_table_tb.clk)", 
                                                         "page_table_tb.sv", 
                                                         75);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.page_table_tb__DOT__wr_en = 0U;
    vlSelfRef.page_table_tb__DOT__lookup_l_page = 0x0fU;
    if (VL_UNLIKELY(((1U != vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table
                      [vlSelfRef.page_table_tb__DOT__lookup_l_page])))) {
        vlSelfRef.page_table_tb__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.page_table_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: page_table_tb.sv:80: Assertion failed in %m: [%0t] Error: page mismatch. Expected 0001 got %0d\n",5, 'M',vlSymsp->name(),"page_table_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',4,vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table
                     [vlSelfRef.page_table_tb__DOT__lookup_l_page]);
        VL_STOP_MT("page_table_tb.sv", 80, "");
    }
    if ((vlSelfRef.page_table_tb__DOT__test_errors 
         == vlSelfRef.page_table_tb__DOT__errors)) {
        VL_WRITEF_NX("Test 1 passed, singular page map\n",0);
    } else {
        VL_WRITEF_NX("FAIL on Test 1\n",0);
    }
    vlSelfRef.page_table_tb__DOT__test_errors = vlSelfRef.page_table_tb__DOT__errors;
    vlSelfRef.page_table_tb__DOT__rst_n = 0U;
    vlSelfRef.page_table_tb__DOT__lookup_l_page = 0U;
    vlSelfRef.page_table_tb__DOT__wr_en = 0U;
    vlSelfRef.page_table_tb__DOT__wr_lpage = 0U;
    vlSelfRef.page_table_tb__DOT__wr_ppage = 0U;
    Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                         "@(negedge page_table_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_table_tb.clk)", 
                                                         "page_table_tb.sv", 
                                                         37);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.page_table_tb__DOT__rst_n = 1U;
    Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                         "@(negedge page_table_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_table_tb.clk)", 
                                                         "page_table_tb.sv", 
                                                         42);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_page_table_tb__DOT__fill_table__2__unnamedblk1__DOT__i = 0U;
    __Vtask_page_table_tb__DOT__fill_table__2__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000010U, __Vtask_page_table_tb__DOT__fill_table__2__unnamedblk1__DOT__i)) {
        vlSelfRef.page_table_tb__DOT__wr_en = 1U;
        vlSelfRef.page_table_tb__DOT__wr_ppage = (0x0000000fU 
                                                  & __Vtask_page_table_tb__DOT__fill_table__2__unnamedblk1__DOT__i);
        vlSelfRef.page_table_tb__DOT__wr_lpage = (0x0000000fU 
                                                  & ((IData)(0x0fU) 
                                                     - __Vtask_page_table_tb__DOT__fill_table__2__unnamedblk1__DOT__i));
        Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                             "@(negedge page_table_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge page_table_tb.clk)", 
                                                             "page_table_tb.sv", 
                                                             47);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_page_table_tb__DOT__fill_table__2__unnamedblk1__DOT__i 
            = ((IData)(1U) + __Vtask_page_table_tb__DOT__fill_table__2__unnamedblk1__DOT__i);
    }
    vlSelfRef.page_table_tb__DOT__wr_en = 0U;
    page_table_tb__DOT__unnamedblk3__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000010U, page_table_tb__DOT__unnamedblk3__DOT__i)) {
        vlSelfRef.page_table_tb__DOT__lookup_l_page 
            = (0x0000000fU & ((IData)(0x0fU) - page_table_tb__DOT__unnamedblk3__DOT__i));
        Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                             "@(negedge page_table_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge page_table_tb.clk)", 
                                                             "page_table_tb.sv", 
                                                             96);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY(((vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table
                          [vlSelfRef.page_table_tb__DOT__lookup_l_page] 
                          != (0x0000000fU & page_table_tb__DOT__unnamedblk3__DOT__i))))) {
            vlSelfRef.page_table_tb__DOT__errors = 
                ((IData)(1U) + vlSelfRef.page_table_tb__DOT__errors);
            VL_WRITEF_NX("[%0t] %%Error: page_table_tb.sv:99: Assertion failed in %m: [%0t] Error: page mismatch. Index: %0d. Expected %0d got %0d\n",7, 'M',vlSymsp->name(),"page_table_tb.unnamedblk3", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '~',32,page_table_tb__DOT__unnamedblk3__DOT__i
                         , '~',4,page_table_tb__DOT__unnamedblk3__DOT__i
                         , '#',4,vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table
                         [vlSelfRef.page_table_tb__DOT__lookup_l_page]);
            VL_STOP_MT("page_table_tb.sv", 99, "");
        }
        page_table_tb__DOT__unnamedblk3__DOT__i = ((IData)(1U) 
                                                   + page_table_tb__DOT__unnamedblk3__DOT__i);
    }
    if ((vlSelfRef.page_table_tb__DOT__test_errors 
         == vlSelfRef.page_table_tb__DOT__errors)) {
        VL_WRITEF_NX("Test 2 passed, filled the page map\n",0);
    } else {
        VL_WRITEF_NX("FAIL on Test 2\n",0);
    }
    vlSelfRef.page_table_tb__DOT__test_errors = vlSelfRef.page_table_tb__DOT__errors;
    vlSelfRef.page_table_tb__DOT__rst_n = 0U;
    vlSelfRef.page_table_tb__DOT__lookup_l_page = 0U;
    vlSelfRef.page_table_tb__DOT__wr_en = 0U;
    vlSelfRef.page_table_tb__DOT__wr_lpage = 0U;
    vlSelfRef.page_table_tb__DOT__wr_ppage = 0U;
    Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                         "@(negedge page_table_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_table_tb.clk)", 
                                                         "page_table_tb.sv", 
                                                         37);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.page_table_tb__DOT__rst_n = 1U;
    Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                         "@(negedge page_table_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_table_tb.clk)", 
                                                         "page_table_tb.sv", 
                                                         53);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_page_table_tb__DOT__fill_table_rand__4__unnamedblk2__DOT__i = 0U;
    __Vtask_page_table_tb__DOT__fill_table_rand__4__unnamedblk2__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000010U, __Vtask_page_table_tb__DOT__fill_table_rand__4__unnamedblk2__DOT__i)) {
        vlSelfRef.page_table_tb__DOT__wr_en = 1U;
        vlSelfRef.page_table_tb__DOT__wr_ppage = (0x0000000fU 
                                                  & VL_RANDOM_I());
        vlSelfRef.page_table_tb__DOT__exp_page[(0x0000000fU 
                                                & __Vtask_page_table_tb__DOT__fill_table_rand__4__unnamedblk2__DOT__i)] 
            = vlSelfRef.page_table_tb__DOT__wr_ppage;
        vlSelfRef.page_table_tb__DOT__wr_lpage = (0x0000000fU 
                                                  & __Vtask_page_table_tb__DOT__fill_table_rand__4__unnamedblk2__DOT__i);
        Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                             "@(negedge page_table_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge page_table_tb.clk)", 
                                                             "page_table_tb.sv", 
                                                             59);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_page_table_tb__DOT__fill_table_rand__4__unnamedblk2__DOT__i 
            = ((IData)(1U) + __Vtask_page_table_tb__DOT__fill_table_rand__4__unnamedblk2__DOT__i);
    }
    vlSelfRef.page_table_tb__DOT__wr_en = 0U;
    page_table_tb__DOT__unnamedblk4__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000010U, page_table_tb__DOT__unnamedblk4__DOT__i)) {
        vlSelfRef.page_table_tb__DOT__lookup_l_page 
            = (0x0000000fU & page_table_tb__DOT__unnamedblk4__DOT__i);
        Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                             "@(negedge page_table_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge page_table_tb.clk)", 
                                                             "page_table_tb.sv", 
                                                             116);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY(((vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table
                          [vlSelfRef.page_table_tb__DOT__lookup_l_page] 
                          != vlSelfRef.page_table_tb__DOT__exp_page
                          [(0x0000000fU & page_table_tb__DOT__unnamedblk4__DOT__i)])))) {
            vlSelfRef.page_table_tb__DOT__errors = 
                ((IData)(1U) + vlSelfRef.page_table_tb__DOT__errors);
            VL_WRITEF_NX("[%0t] %%Error: page_table_tb.sv:119: Assertion failed in %m: [%0t] Error: page mismatch. Index: %0d. Expected %0d got %0d\n",7, 'M',vlSymsp->name(),"page_table_tb.unnamedblk4", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '~',32,page_table_tb__DOT__unnamedblk4__DOT__i
                         , '~',4,page_table_tb__DOT__unnamedblk4__DOT__i
                         , '#',4,vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table
                         [vlSelfRef.page_table_tb__DOT__lookup_l_page]);
            VL_STOP_MT("page_table_tb.sv", 119, "");
        }
        page_table_tb__DOT__unnamedblk4__DOT__i = ((IData)(1U) 
                                                   + page_table_tb__DOT__unnamedblk4__DOT__i);
    }
    if ((vlSelfRef.page_table_tb__DOT__test_errors 
         == vlSelfRef.page_table_tb__DOT__errors)) {
        VL_WRITEF_NX("Test 3 passed, filled the page map with random data\n",0);
    } else {
        VL_WRITEF_NX("FAIL on Test 3\n",0);
    }
    vlSelfRef.page_table_tb__DOT__test_errors = vlSelfRef.page_table_tb__DOT__errors;
    vlSelfRef.page_table_tb__DOT__rst_n = 0U;
    vlSelfRef.page_table_tb__DOT__lookup_l_page = 0U;
    vlSelfRef.page_table_tb__DOT__wr_en = 0U;
    vlSelfRef.page_table_tb__DOT__wr_lpage = 0U;
    vlSelfRef.page_table_tb__DOT__wr_ppage = 0U;
    Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                         "@(negedge page_table_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_table_tb.clk)", 
                                                         "page_table_tb.sv", 
                                                         37);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.page_table_tb__DOT__rst_n = 1U;
    Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                         "@(negedge page_table_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_table_tb.clk)", 
                                                         "page_table_tb.sv", 
                                                         53);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_page_table_tb__DOT__fill_table_rand__6__unnamedblk2__DOT__i = 0U;
    __Vtask_page_table_tb__DOT__fill_table_rand__6__unnamedblk2__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000010U, __Vtask_page_table_tb__DOT__fill_table_rand__6__unnamedblk2__DOT__i)) {
        vlSelfRef.page_table_tb__DOT__wr_en = 1U;
        vlSelfRef.page_table_tb__DOT__wr_ppage = (0x0000000fU 
                                                  & VL_RANDOM_I());
        vlSelfRef.page_table_tb__DOT__exp_page[(0x0000000fU 
                                                & __Vtask_page_table_tb__DOT__fill_table_rand__6__unnamedblk2__DOT__i)] 
            = vlSelfRef.page_table_tb__DOT__wr_ppage;
        vlSelfRef.page_table_tb__DOT__wr_lpage = (0x0000000fU 
                                                  & __Vtask_page_table_tb__DOT__fill_table_rand__6__unnamedblk2__DOT__i);
        Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                             "@(negedge page_table_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge page_table_tb.clk)", 
                                                             "page_table_tb.sv", 
                                                             59);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_page_table_tb__DOT__fill_table_rand__6__unnamedblk2__DOT__i 
            = ((IData)(1U) + __Vtask_page_table_tb__DOT__fill_table_rand__6__unnamedblk2__DOT__i);
    }
    vlSelfRef.page_table_tb__DOT__wr_en = 0U;
    page_table_tb__DOT__unnamedblk5__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000010U, page_table_tb__DOT__unnamedblk5__DOT__i)) {
        vlSelfRef.page_table_tb__DOT__lookup_l_page 
            = (0x0000000fU & page_table_tb__DOT__unnamedblk5__DOT__i);
        Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                             "@(negedge page_table_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge page_table_tb.clk)", 
                                                             "page_table_tb.sv", 
                                                             139);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY(((vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table
                          [vlSelfRef.page_table_tb__DOT__lookup_l_page] 
                          != vlSelfRef.page_table_tb__DOT__exp_page
                          [(0x0000000fU & page_table_tb__DOT__unnamedblk5__DOT__i)])))) {
            vlSelfRef.page_table_tb__DOT__errors = 
                ((IData)(1U) + vlSelfRef.page_table_tb__DOT__errors);
            VL_WRITEF_NX("[%0t] %%Error: page_table_tb.sv:142: Assertion failed in %m: [%0t] Error: page mismatch. Index: %0d. Expected %0d got %0d\n",7, 'M',vlSymsp->name(),"page_table_tb.unnamedblk5", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '~',32,page_table_tb__DOT__unnamedblk5__DOT__i
                         , '~',4,page_table_tb__DOT__unnamedblk5__DOT__i
                         , '#',4,vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table
                         [vlSelfRef.page_table_tb__DOT__lookup_l_page]);
            VL_STOP_MT("page_table_tb.sv", 142, "");
        }
        page_table_tb__DOT__unnamedblk5__DOT__i = ((IData)(1U) 
                                                   + page_table_tb__DOT__unnamedblk5__DOT__i);
    }
    page_table_tb__DOT__unnamedblk6__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000010U, page_table_tb__DOT__unnamedblk6__DOT__i)) {
        vlSelfRef.page_table_tb__DOT__wr_en = 1U;
        vlSelfRef.page_table_tb__DOT__wr_lpage = (0x0000000fU 
                                                  & page_table_tb__DOT__unnamedblk6__DOT__i);
        vlSelfRef.page_table_tb__DOT__wr_ppage = (0x0000000fU 
                                                  & VL_RANDOM_I());
        vlSelfRef.page_table_tb__DOT__exp_page[(0x0000000fU 
                                                & page_table_tb__DOT__unnamedblk6__DOT__i)] 
            = vlSelfRef.page_table_tb__DOT__wr_ppage;
        Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                             "@(negedge page_table_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge page_table_tb.clk)", 
                                                             "page_table_tb.sv", 
                                                             152);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.page_table_tb__DOT__wr_en = 0U;
        vlSelfRef.page_table_tb__DOT__lookup_l_page 
            = (0x0000000fU & page_table_tb__DOT__unnamedblk6__DOT__i);
        Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                             "@(negedge page_table_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge page_table_tb.clk)", 
                                                             "page_table_tb.sv", 
                                                             157);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY(((vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table
                          [vlSelfRef.page_table_tb__DOT__lookup_l_page] 
                          != vlSelfRef.page_table_tb__DOT__exp_page
                          [(0x0000000fU & page_table_tb__DOT__unnamedblk6__DOT__i)])))) {
            vlSelfRef.page_table_tb__DOT__errors = 
                ((IData)(1U) + vlSelfRef.page_table_tb__DOT__errors);
            VL_WRITEF_NX("[%0t] %%Error: page_table_tb.sv:160: Assertion failed in %m: [%0t] Error: page mismatch. Index: %0d. Expected %0d got %0d\n",7, 'M',vlSymsp->name(),"page_table_tb.unnamedblk6", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '~',32,page_table_tb__DOT__unnamedblk6__DOT__i
                         , '~',4,page_table_tb__DOT__unnamedblk6__DOT__i
                         , '#',4,vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table
                         [vlSelfRef.page_table_tb__DOT__lookup_l_page]);
            VL_STOP_MT("page_table_tb.sv", 160, "");
        }
        page_table_tb__DOT__unnamedblk6__DOT__i = ((IData)(1U) 
                                                   + page_table_tb__DOT__unnamedblk6__DOT__i);
    }
    page_table_tb__DOT__unnamedblk7__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000010U, page_table_tb__DOT__unnamedblk7__DOT__i)) {
        vlSelfRef.page_table_tb__DOT__wr_en = 1U;
        vlSelfRef.page_table_tb__DOT__wr_lpage = (0x0000000fU 
                                                  & VL_RANDOM_I());
        vlSelfRef.page_table_tb__DOT__wr_ppage = (0x0000000fU 
                                                  & page_table_tb__DOT__unnamedblk7__DOT__i);
        vlSelfRef.page_table_tb__DOT__exp_page[vlSelfRef.page_table_tb__DOT__wr_lpage] 
            = vlSelfRef.page_table_tb__DOT__wr_ppage;
        Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                             "@(negedge page_table_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge page_table_tb.clk)", 
                                                             "page_table_tb.sv", 
                                                             170);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.page_table_tb__DOT__wr_en = 0U;
        vlSelfRef.page_table_tb__DOT__lookup_l_page 
            = vlSelfRef.page_table_tb__DOT__wr_lpage;
        Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(vlSelf, 
                                                             "@(negedge page_table_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h7f3e1276__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge page_table_tb.clk)", 
                                                             "page_table_tb.sv", 
                                                             175);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY(((vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table
                          [vlSelfRef.page_table_tb__DOT__lookup_l_page] 
                          != vlSelfRef.page_table_tb__DOT__exp_page
                          [vlSelfRef.page_table_tb__DOT__wr_lpage])))) {
            vlSelfRef.page_table_tb__DOT__errors = 
                ((IData)(1U) + vlSelfRef.page_table_tb__DOT__errors);
            VL_WRITEF_NX("[%0t] %%Error: page_table_tb.sv:178: Assertion failed in %m: [%0t] Error: page mismatch. Index: %0d. Expected %0d got %0d\n",7, 'M',vlSymsp->name(),"page_table_tb.unnamedblk7", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '~',32,page_table_tb__DOT__unnamedblk7__DOT__i
                         , '~',4,page_table_tb__DOT__unnamedblk7__DOT__i
                         , '#',4,vlSelfRef.page_table_tb__DOT__dut__DOT__ppage_table
                         [vlSelfRef.page_table_tb__DOT__lookup_l_page]);
            VL_STOP_MT("page_table_tb.sv", 178, "");
        }
        page_table_tb__DOT__unnamedblk7__DOT__i = ((IData)(1U) 
                                                   + page_table_tb__DOT__unnamedblk7__DOT__i);
    }
    if ((vlSelfRef.page_table_tb__DOT__test_errors 
         == vlSelfRef.page_table_tb__DOT__errors)) {
        VL_WRITEF_NX("Test 4 passed, filled the page map 3 times\n",0);
    } else {
        VL_WRITEF_NX("FAIL on Test 4\n",0);
    }
    VL_FINISH_MT("page_table_tb.sv", 188, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_return;
}

bool Vpage_table_tb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

bool Vpage_table_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vpage_table_tb___024root___timing_ready(Vpage_table_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___timing_ready\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready("@(negedge page_table_tb.clk)");
    }
}

void Vpage_table_tb___024root___timing_resume(Vpage_table_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___timing_resume\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h7f3e1276__0.moveToResumeQueue(
                                                          "@(negedge page_table_tb.clk)");
    vlSelfRef.__VtrigSched_h7f3e1276__0.resume("@(negedge page_table_tb.clk)");
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vpage_table_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vpage_table_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0(Vpage_table_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root____VbeforeTrig_h7f3e1276__0\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)((((~ (IData)(vlSelfRef.page_table_tb__DOT__clk)) 
                                   & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__page_table_tb__DOT__clk__0)) 
                                  << 2U)));
    vlSelfRef.__Vtrigprevexpr___TOP__page_table_tb__DOT__clk__0 
        = vlSelfRef.page_table_tb__DOT__clk;
    if ((4ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h7f3e1276__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vpage_table_tb___024root___eval_debug_assertions(Vpage_table_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_table_tb___024root___eval_debug_assertions\n"); );
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
