// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpage_allocator_tb.h for the primary calling header

#include "Vpage_allocator_tb__pch.h"

VlCoroutine Vpage_allocator_tb___024root___eval_initial__TOP__Vtiming__0(Vpage_allocator_tb___024root* vlSelf);
VlCoroutine Vpage_allocator_tb___024root___eval_initial__TOP__Vtiming__1(Vpage_allocator_tb___024root* vlSelf);

void Vpage_allocator_tb___024root___eval_initial(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_initial\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        vlSymsp->_vm_contextp__->dumpfile("dump.vcd"s);
        vlSymsp->_traceDumpOpen();
    }
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vpage_allocator_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vpage_allocator_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vpage_allocator_tb___024root___eval_sample(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_sample\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpage_allocator_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vpage_allocator_tb___024root___eval_ico(Vpage_allocator_tb___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_ico\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vpage_allocator_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

void Vpage_allocator_tb___024root___timing_ready(Vpage_allocator_tb___024root* vlSelf);
void Vpage_allocator_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpage_allocator_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vpage_allocator_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vpage_allocator_tb___024root___timing_resume(Vpage_allocator_tb___024root* vlSelf);

bool Vpage_allocator_tb___024root___eval_act(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_act\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((((~ (IData)(vlSelfRef.page_allocator_tb__DOT__clk)) 
                                                           & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__page_allocator_tb__DOT__clk__0)) 
                                                          << 2U) 
                                                         | ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.page_allocator_tb__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__page_allocator_tb__DOT__clk__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__page_allocator_tb__DOT__clk__0 
            = vlSelfRef.page_allocator_tb__DOT__clk;
    }
    Vpage_allocator_tb___024root___timing_ready(vlSelf);
    Vpage_allocator_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vpage_allocator_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vpage_allocator_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vpage_allocator_tb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vpage_allocator_tb___024root___timing_resume(vlSelf);
        {
            // Inlined CFunc: _eval_body__act
            if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
                {
                    // Inlined CFunc: _act_sequent__TOP__0
                    vlSelfRef.page_allocator_tb__DOT__alloc_ok 
                        = ((~ (0x0000ffffU == (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map))) 
                           & (IData)(vlSelfRef.page_allocator_tb__DOT__alloc_req));
                    vlSelfRef.page_allocator_tb__DOT__alloc_error 
                        = ((IData)(vlSelfRef.page_allocator_tb__DOT__alloc_req) 
                           & (0x0000ffffU == (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map)));
                }
            }
        }
    }
    return (__VactExecute);
}

bool Vpage_allocator_tb___024root___eval_inact(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_inact\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("page_allocator_tb.sv", 2, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vpage_allocator_tb___024root___nba_sequent__TOP__0(Vpage_allocator_tb___024root* vlSelf);
void Vpage_allocator_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vpage_allocator_tb___024root___eval_nba(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_nba\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vpage_allocator_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vpage_allocator_tb___024root___nba_sequent__TOP__0(vlSelf);
                vlSelfRef.__Vm_traceActivity[3U] = 1U;
            }
            if ((5ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _act_sequent__TOP__0
                    vlSelfRef.page_allocator_tb__DOT__alloc_ok 
                        = ((~ (0x0000ffffU == (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map))) 
                           & (IData)(vlSelfRef.page_allocator_tb__DOT__alloc_req));
                    vlSelfRef.page_allocator_tb__DOT__alloc_error 
                        = ((IData)(vlSelfRef.page_allocator_tb__DOT__alloc_req) 
                           & (0x0000ffffU == (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map)));
                }
            }
        }
        Vpage_allocator_tb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vpage_allocator_tb___024root___eval_obs(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_obs\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vpage_allocator_tb___024root___eval_react(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_react\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vpage_allocator_tb___024root___eval_postponed(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_postponed\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VlCoroutine Vpage_allocator_tb___024root___eval_initial__TOP__Vtiming__0(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.page_allocator_tb__DOT__clk = 0U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "page_allocator_tb.sv", 
                                             26);
        vlSelfRef.page_allocator_tb__DOT__clk = (1U 
                                                 & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__clk)));
    }
    co_return;
}

void Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(Vpage_allocator_tb___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vpage_allocator_tb___024root___eval_initial__TOP__Vtiming__1(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ page_allocator_tb__DOT__unnamedblk4__DOT__i;
    page_allocator_tb__DOT__unnamedblk4__DOT__i = 0;
    IData/*31:0*/ __Vtask_page_allocator_tb__DOT__allocate_all__2__unnamedblk1__DOT__i;
    __Vtask_page_allocator_tb__DOT__allocate_all__2__unnamedblk1__DOT__i = 0;
    IData/*31:0*/ __Vtask_page_allocator_tb__DOT__allocate_all__6__unnamedblk1__DOT__i;
    __Vtask_page_allocator_tb__DOT__allocate_all__6__unnamedblk1__DOT__i = 0;
    IData/*31:0*/ __Vtask_page_allocator_tb__DOT__free_page__8__page;
    __Vtask_page_allocator_tb__DOT__free_page__8__page = 0;
    IData/*31:0*/ __Vtask_page_allocator_tb__DOT__free_page__9__page;
    __Vtask_page_allocator_tb__DOT__free_page__9__page = 0;
    // Body
    vlSelfRef.page_allocator_tb__DOT__rst_n = 0U;
    vlSelfRef.page_allocator_tb__DOT__free_en = 0U;
    vlSelfRef.page_allocator_tb__DOT__free_ppage = 0U;
    vlSelfRef.page_allocator_tb__DOT__alloc_req = 0U;
    vlSelfRef.page_allocator_tb__DOT__alloc_page = 0U;
    vlSelfRef.page_allocator_tb__DOT__alloc_ok = 0U;
    vlSelfRef.page_allocator_tb__DOT__alloc_error = 0U;
    Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                             "@(negedge page_allocator_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_allocator_tb.clk)", 
                                                         "page_allocator_tb.sv", 
                                                         38);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.page_allocator_tb__DOT__rst_n = 1U;
    vlSelfRef.page_allocator_tb__DOT__test_errors = vlSelfRef.page_allocator_tb__DOT__errors;
    vlSelfRef.page_allocator_tb__DOT__checks = 0U;
    vlSelfRef.page_allocator_tb__DOT__rst_n = 0U;
    Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                             "@(negedge page_allocator_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_allocator_tb.clk)", 
                                                         "page_allocator_tb.sv", 
                                                         79);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.page_allocator_tb__DOT__rst_n = 1U;
    Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                             "@(negedge page_allocator_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_allocator_tb.clk)", 
                                                         "page_allocator_tb.sv", 
                                                         81);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.page_allocator_tb__DOT__alloc_page))))) {
        vlSelfRef.page_allocator_tb__DOT__errors = 
            ((IData)(1U) + vlSelfRef.page_allocator_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:85: Assertion failed in %m: [%0t] ERROR: Alloc page is not 0. Reset failed.\n",4, 'M',vlSymsp->name(),"page_allocator_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 85, "");
    }
    if (VL_UNLIKELY((vlSelfRef.page_allocator_tb__DOT__alloc_ok))) {
        vlSelfRef.page_allocator_tb__DOT__errors = 
            ((IData)(1U) + vlSelfRef.page_allocator_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:90: Assertion failed in %m: [%0t] ERROR: Alloc_ok is not 0. Reset failed.\n",4, 'M',vlSymsp->name(),"page_allocator_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 90, "");
    }
    if (VL_UNLIKELY((vlSelfRef.page_allocator_tb__DOT__alloc_error))) {
        vlSelfRef.page_allocator_tb__DOT__errors = 
            ((IData)(1U) + vlSelfRef.page_allocator_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:95: Assertion failed in %m: [%0t] ERROR: Alloc_error is not 0. Reset failed.\n",4, 'M',vlSymsp->name(),"page_allocator_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 95, "");
    }
    if (VL_UNLIKELY(((0x0000ffffU == (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map))))) {
        vlSelfRef.page_allocator_tb__DOT__errors = 
            ((IData)(1U) + vlSelfRef.page_allocator_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:100: Assertion failed in %m: [%0t] ERROR: Full is not 0. Reset failed.\n",4, 'M',vlSymsp->name(),"page_allocator_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 100, "");
    }
    vlSelfRef.page_allocator_tb__DOT__checks = ((IData)(1U) 
                                                + vlSelfRef.page_allocator_tb__DOT__checks);
    vlSelfRef.page_allocator_tb__DOT__rst_n = 0U;
    vlSelfRef.page_allocator_tb__DOT__free_en = 0U;
    vlSelfRef.page_allocator_tb__DOT__free_ppage = 0U;
    vlSelfRef.page_allocator_tb__DOT__alloc_req = 0U;
    vlSelfRef.page_allocator_tb__DOT__alloc_page = 0U;
    vlSelfRef.page_allocator_tb__DOT__alloc_ok = 0U;
    vlSelfRef.page_allocator_tb__DOT__alloc_error = 0U;
    if ((vlSelfRef.page_allocator_tb__DOT__test_errors 
         == vlSelfRef.page_allocator_tb__DOT__errors)) {
        VL_WRITEF_NX("Test 1 Passed: Reset behavior as expected%d\n",1
                     , '#',64,VL_TIME_UNITED_Q(1000));
    } else {
        VL_WRITEF_NX("Test 1 Failed: Reset is not correct.%d\n",1
                     , '#',64,VL_TIME_UNITED_Q(1000));
    }
    Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                             "@(negedge page_allocator_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_allocator_tb.clk)", 
                                                         "page_allocator_tb.sv", 
                                                         38);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.page_allocator_tb__DOT__rst_n = 1U;
    vlSelfRef.page_allocator_tb__DOT__test_errors = vlSelfRef.page_allocator_tb__DOT__errors;
    __Vtask_page_allocator_tb__DOT__allocate_all__2__unnamedblk1__DOT__i = 0U;
    __Vtask_page_allocator_tb__DOT__allocate_all__2__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000010U, __Vtask_page_allocator_tb__DOT__allocate_all__2__unnamedblk1__DOT__i)) {
        vlSelfRef.page_allocator_tb__DOT__alloc_req = 1U;
        Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                                 "@(negedge page_allocator_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge page_allocator_tb.clk)", 
                                                             "page_allocator_tb.sv", 
                                                             44);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.page_allocator_tb__DOT__alloc_req = 0U;
        Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                                 "@(negedge page_allocator_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge page_allocator_tb.clk)", 
                                                             "page_allocator_tb.sv", 
                                                             46);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_page_allocator_tb__DOT__allocate_all__2__unnamedblk1__DOT__i 
            = ((IData)(1U) + __Vtask_page_allocator_tb__DOT__allocate_all__2__unnamedblk1__DOT__i);
    }
    if (VL_UNLIKELY(((1U & (~ (0x0000ffffU == (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map))))))) {
        vlSelfRef.page_allocator_tb__DOT__errors = 
            ((IData)(1U) + vlSelfRef.page_allocator_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:119: Assertion failed in %m: [%0t] ERROR: Full is not 1.\n",4, 'M',vlSymsp->name(),"page_allocator_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 119, "");
    }
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:125: Assertion failed in %m: [%0t] ERROR: Used_map not funcitoning correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk3", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 125, "");
    }
    if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                               >> 1U)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:125: Assertion failed in %m: [%0t] ERROR: Used_map not funcitoning correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk3", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 125, "");
    }
    if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                               >> 2U)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:125: Assertion failed in %m: [%0t] ERROR: Used_map not funcitoning correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk3", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 125, "");
    }
    if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                               >> 3U)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:125: Assertion failed in %m: [%0t] ERROR: Used_map not funcitoning correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk3", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 125, "");
    }
    if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                               >> 4U)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:125: Assertion failed in %m: [%0t] ERROR: Used_map not funcitoning correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk3", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 125, "");
    }
    if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                               >> 5U)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:125: Assertion failed in %m: [%0t] ERROR: Used_map not funcitoning correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk3", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 125, "");
    }
    if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                               >> 6U)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:125: Assertion failed in %m: [%0t] ERROR: Used_map not funcitoning correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk3", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 125, "");
    }
    if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                               >> 7U)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:125: Assertion failed in %m: [%0t] ERROR: Used_map not funcitoning correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk3", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 125, "");
    }
    if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                               >> 8U)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:125: Assertion failed in %m: [%0t] ERROR: Used_map not funcitoning correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk3", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 125, "");
    }
    if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                               >> 9U)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:125: Assertion failed in %m: [%0t] ERROR: Used_map not funcitoning correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk3", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 125, "");
    }
    if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                               >> 0x0aU)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:125: Assertion failed in %m: [%0t] ERROR: Used_map not funcitoning correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk3", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 125, "");
    }
    if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                               >> 0x0bU)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:125: Assertion failed in %m: [%0t] ERROR: Used_map not funcitoning correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk3", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 125, "");
    }
    if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                               >> 0x0cU)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:125: Assertion failed in %m: [%0t] ERROR: Used_map not funcitoning correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk3", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 125, "");
    }
    if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                               >> 0x0dU)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:125: Assertion failed in %m: [%0t] ERROR: Used_map not funcitoning correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk3", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 125, "");
    }
    if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                               >> 0x0eU)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:125: Assertion failed in %m: [%0t] ERROR: Used_map not funcitoning correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk3", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 125, "");
    }
    if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                               >> 0x0fU)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:125: Assertion failed in %m: [%0t] ERROR: Used_map not funcitoning correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk3", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 125, "");
    }
    vlSelfRef.page_allocator_tb__DOT__alloc_req = 1U;
    Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                             "@(negedge page_allocator_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_allocator_tb.clk)", 
                                                         "page_allocator_tb.sv", 
                                                         131);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__alloc_error)))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:134: Assertion failed in %m: [%0t] ERROR: Alloc error not asserted, page allocator should be full.\n",4, 'M',vlSymsp->name(),"page_allocator_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 134, "");
    }
    if (VL_UNLIKELY((vlSelfRef.page_allocator_tb__DOT__alloc_ok))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:138: Assertion failed in %m: [%0t] ERROR: Alloc ok asserted when it should not be.\n",4, 'M',vlSymsp->name(),"page_allocator_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 138, "");
    }
    vlSelfRef.page_allocator_tb__DOT__checks = ((IData)(1U) 
                                                + vlSelfRef.page_allocator_tb__DOT__checks);
    vlSelfRef.page_allocator_tb__DOT__rst_n = 0U;
    vlSelfRef.page_allocator_tb__DOT__free_en = 0U;
    vlSelfRef.page_allocator_tb__DOT__free_ppage = 0U;
    vlSelfRef.page_allocator_tb__DOT__alloc_req = 0U;
    vlSelfRef.page_allocator_tb__DOT__alloc_page = 0U;
    vlSelfRef.page_allocator_tb__DOT__alloc_ok = 0U;
    vlSelfRef.page_allocator_tb__DOT__alloc_error = 0U;
    if ((vlSelfRef.page_allocator_tb__DOT__test_errors 
         == vlSelfRef.page_allocator_tb__DOT__errors)) {
        VL_WRITEF_NX("Test 2 Passed: 16 pages filled, signals verified%d\n",1
                     , '#',64,VL_TIME_UNITED_Q(1000));
    } else {
        VL_WRITEF_NX("Test 2 Failed: 16 Pages not filled, or signal error.%d\n",1
                     , '#',64,VL_TIME_UNITED_Q(1000));
    }
    Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                             "@(negedge page_allocator_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_allocator_tb.clk)", 
                                                         "page_allocator_tb.sv", 
                                                         38);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.page_allocator_tb__DOT__rst_n = 1U;
    vlSelfRef.page_allocator_tb__DOT__test_errors = vlSelfRef.page_allocator_tb__DOT__errors;
    page_allocator_tb__DOT__unnamedblk4__DOT__i = 0U;
    while (VL_GTS_III(32, 0x0000000fU, page_allocator_tb__DOT__unnamedblk4__DOT__i)) {
        vlSelfRef.page_allocator_tb__DOT__alloc_req = 1U;
        Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                                 "@(negedge page_allocator_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge page_allocator_tb.clk)", 
                                                             "page_allocator_tb.sv", 
                                                             154);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.page_allocator_tb__DOT__alloc_req = 0U;
        if (VL_UNLIKELY((((IData)(vlSelfRef.page_allocator_tb__DOT__alloc_page) 
                          != ((IData)(1U) + (0x0000000fU 
                                             & page_allocator_tb__DOT__unnamedblk4__DOT__i)))))) {
            VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:158: Assertion failed in %m: [%0t] ERROR: Incorrect page allocated. Expected: %0d, got %0d.\n",6, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk4", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '~',4,page_allocator_tb__DOT__unnamedblk4__DOT__i
                         , '#',4,(IData)(vlSelfRef.page_allocator_tb__DOT__alloc_page));
            VL_STOP_MT("page_allocator_tb.sv", 158, "");
        }
        if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                                   >> (0x0000000fU 
                                       & page_allocator_tb__DOT__unnamedblk4__DOT__i))))))) {
            VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:162: Assertion failed in %m: [%0t] ERROR: Used map not filled.\n",4, 'M',vlSymsp->name(),"page_allocator_tb.unnamedblk4", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("page_allocator_tb.sv", 162, "");
        }
        Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                                 "@(negedge page_allocator_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge page_allocator_tb.clk)", 
                                                             "page_allocator_tb.sv", 
                                                             164);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        page_allocator_tb__DOT__unnamedblk4__DOT__i 
            = ((IData)(1U) + page_allocator_tb__DOT__unnamedblk4__DOT__i);
    }
    vlSelfRef.page_allocator_tb__DOT__rst_n = 0U;
    vlSelfRef.page_allocator_tb__DOT__free_en = 0U;
    vlSelfRef.page_allocator_tb__DOT__free_ppage = 0U;
    vlSelfRef.page_allocator_tb__DOT__alloc_req = 0U;
    vlSelfRef.page_allocator_tb__DOT__alloc_page = 0U;
    vlSelfRef.page_allocator_tb__DOT__alloc_ok = 0U;
    vlSelfRef.page_allocator_tb__DOT__alloc_error = 0U;
    if ((vlSelfRef.page_allocator_tb__DOT__test_errors 
         == vlSelfRef.page_allocator_tb__DOT__errors)) {
        VL_WRITEF_NX("Test 3 Passed: 16 Consecutive page requests, correct pages identified.\n",0);
    } else {
        VL_WRITEF_NX("Test 3 Failed: Either fail on allocation or incorrect page allocated\n",0);
    }
    Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                             "@(negedge page_allocator_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_allocator_tb.clk)", 
                                                         "page_allocator_tb.sv", 
                                                         38);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.page_allocator_tb__DOT__rst_n = 1U;
    vlSelfRef.page_allocator_tb__DOT__test_errors = vlSelfRef.page_allocator_tb__DOT__errors;
    vlSelfRef.page_allocator_tb__DOT__checks = ((IData)(1U) 
                                                + vlSelfRef.page_allocator_tb__DOT__checks);
    __Vtask_page_allocator_tb__DOT__allocate_all__6__unnamedblk1__DOT__i = 0U;
    __Vtask_page_allocator_tb__DOT__allocate_all__6__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000010U, __Vtask_page_allocator_tb__DOT__allocate_all__6__unnamedblk1__DOT__i)) {
        vlSelfRef.page_allocator_tb__DOT__alloc_req = 1U;
        Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                                 "@(negedge page_allocator_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge page_allocator_tb.clk)", 
                                                             "page_allocator_tb.sv", 
                                                             44);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.page_allocator_tb__DOT__alloc_req = 0U;
        Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                                 "@(negedge page_allocator_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge page_allocator_tb.clk)", 
                                                             "page_allocator_tb.sv", 
                                                             46);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_page_allocator_tb__DOT__allocate_all__6__unnamedblk1__DOT__i 
            = ((IData)(1U) + __Vtask_page_allocator_tb__DOT__allocate_all__6__unnamedblk1__DOT__i);
    }
    __Vtask_page_allocator_tb__DOT__free_page__8__page = 7U;
    if (VL_UNLIKELY(((VL_LTS_III(32, 0x0000000fU, __Vtask_page_allocator_tb__DOT__free_page__8__page) 
                      | VL_GTS_III(32, 0U, __Vtask_page_allocator_tb__DOT__free_page__8__page))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:57: Assertion failed in %m: [%0t] ERROR: Not within the bounds\n",4, 'M',vlSymsp->name(),"page_allocator_tb.free_page", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 57, "");
    }
    vlSelfRef.page_allocator_tb__DOT__free_en = 1U;
    vlSelfRef.page_allocator_tb__DOT__free_ppage = 
        (0x0000000fU & __Vtask_page_allocator_tb__DOT__free_page__8__page);
    Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                             "@(negedge page_allocator_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_allocator_tb.clk)", 
                                                         "page_allocator_tb.sv", 
                                                         61);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.page_allocator_tb__DOT__free_en = 0U;
    vlSelfRef.page_allocator_tb__DOT__free_ppage = 0U;
    Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                             "@(negedge page_allocator_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_allocator_tb.clk)", 
                                                         "page_allocator_tb.sv", 
                                                         181);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((0x00000040U & (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map))))) {
        vlSelfRef.page_allocator_tb__DOT__errors = 
            ((IData)(1U) + vlSelfRef.page_allocator_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:185: Assertion failed in %m: [%0t] ERROR: Used map not updated on free 1. Index 8.\n",4, 'M',vlSymsp->name(),"page_allocator_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 185, "");
    }
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__free_ok)))))) {
        vlSelfRef.page_allocator_tb__DOT__errors = 
            ((IData)(1U) + vlSelfRef.page_allocator_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:190: Assertion failed in %m: [%0t] ERROR: Free_ok not driven correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 190, "");
    }
    Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                             "@(negedge page_allocator_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_allocator_tb.clk)", 
                                                         "page_allocator_tb.sv", 
                                                         193);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_page_allocator_tb__DOT__free_page__9__page = 0x0000000aU;
    if (VL_UNLIKELY(((VL_LTS_III(32, 0x0000000fU, __Vtask_page_allocator_tb__DOT__free_page__9__page) 
                      | VL_GTS_III(32, 0U, __Vtask_page_allocator_tb__DOT__free_page__9__page))))) {
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:57: Assertion failed in %m: [%0t] ERROR: Not within the bounds\n",4, 'M',vlSymsp->name(),"page_allocator_tb.free_page", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 57, "");
    }
    vlSelfRef.page_allocator_tb__DOT__free_en = 1U;
    vlSelfRef.page_allocator_tb__DOT__free_ppage = 
        (0x0000000fU & __Vtask_page_allocator_tb__DOT__free_page__9__page);
    Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                             "@(negedge page_allocator_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_allocator_tb.clk)", 
                                                         "page_allocator_tb.sv", 
                                                         61);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.page_allocator_tb__DOT__free_en = 0U;
    vlSelfRef.page_allocator_tb__DOT__free_ppage = 0U;
    Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                             "@(negedge page_allocator_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_allocator_tb.clk)", 
                                                         "page_allocator_tb.sv", 
                                                         196);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((0x00000200U & (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map))))) {
        vlSelfRef.page_allocator_tb__DOT__errors = 
            ((IData)(1U) + vlSelfRef.page_allocator_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:199: Assertion failed in %m: [%0t] ERROR: Used map not updated on free 1. Index 8.\n",4, 'M',vlSymsp->name(),"page_allocator_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 199, "");
    }
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__free_ok)))))) {
        vlSelfRef.page_allocator_tb__DOT__errors = 
            ((IData)(1U) + vlSelfRef.page_allocator_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:204: Assertion failed in %m: [%0t] ERROR: Free_ok not driven correctly.\n",4, 'M',vlSymsp->name(),"page_allocator_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 204, "");
    }
    Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                             "@(negedge page_allocator_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_allocator_tb.clk)", 
                                                         "page_allocator_tb.sv", 
                                                         207);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.page_allocator_tb__DOT__alloc_req = 1U;
    Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                             "@(negedge page_allocator_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_allocator_tb.clk)", 
                                                         "page_allocator_tb.sv", 
                                                         211);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.page_allocator_tb__DOT__alloc_req = 0U;
    if (VL_UNLIKELY(((7U != (IData)(vlSelfRef.page_allocator_tb__DOT__alloc_page))))) {
        vlSelfRef.page_allocator_tb__DOT__errors = 
            ((IData)(1U) + vlSelfRef.page_allocator_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:216: Assertion failed in %m: [%0t] ERROR: Incorrect page allocated. Expected: 7, got %0d.\n",5, 'M',vlSymsp->name(),"page_allocator_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',4,(IData)(vlSelfRef.page_allocator_tb__DOT__alloc_page));
        VL_STOP_MT("page_allocator_tb.sv", 216, "");
    }
    if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                               >> 6U)))))) {
        vlSelfRef.page_allocator_tb__DOT__errors = 
            ((IData)(1U) + vlSelfRef.page_allocator_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: page_allocator_tb.sv:221: Assertion failed in %m: [%0t] ERROR: Used map not filled.\n",4, 'M',vlSymsp->name(),"page_allocator_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("page_allocator_tb.sv", 221, "");
    }
    Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(vlSelf, 
                                                             "@(negedge page_allocator_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hb34f2848__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge page_allocator_tb.clk)", 
                                                         "page_allocator_tb.sv", 
                                                         223);
    if ((vlSelfRef.page_allocator_tb__DOT__test_errors 
         == vlSelfRef.page_allocator_tb__DOT__errors)) {
        VL_WRITEF_NX("Test 4 Passed: Freed page successfully and refilled correctly.\n",0);
    } else {
        VL_WRITEF_NX("Test 4 Failed: Page not freed properly.\n",0);
    }
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("page_allocator_tb.sv", 231, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_return;
}

bool Vpage_allocator_tb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___trigger_anySet__ico\n"); );
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

bool Vpage_allocator_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___trigger_anySet__act\n"); );
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

void Vpage_allocator_tb___024root___nba_sequent__TOP__0(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___nba_sequent__TOP__0\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*15:0*/ __Vdly__page_allocator_tb__DOT__dut__DOT__used_map;
    __Vdly__page_allocator_tb__DOT__dut__DOT__used_map = 0;
    // Body
    __Vdly__page_allocator_tb__DOT__dut__DOT__used_map 
        = vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map;
    if (vlSelfRef.page_allocator_tb__DOT__rst_n) {
        if (vlSelfRef.page_allocator_tb__DOT__alloc_ok) {
            __Vdly__page_allocator_tb__DOT__dut__DOT__used_map 
                = ((IData)(__Vdly__page_allocator_tb__DOT__dut__DOT__used_map) 
                   | (0x0000ffffU & ((IData)(1U) << (IData)(vlSelfRef.page_allocator_tb__DOT__alloc_page))));
        }
        if (((IData)(vlSelfRef.page_allocator_tb__DOT__free_en) 
             & ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                >> (IData)(vlSelfRef.page_allocator_tb__DOT__free_ppage)))) {
            __Vdly__page_allocator_tb__DOT__dut__DOT__used_map 
                = ((~ ((IData)(1U) << (IData)(vlSelfRef.page_allocator_tb__DOT__free_ppage))) 
                   & (IData)(__Vdly__page_allocator_tb__DOT__dut__DOT__used_map));
            vlSelfRef.page_allocator_tb__DOT__free_ok = 1U;
        } else {
            vlSelfRef.page_allocator_tb__DOT__free_ok = 0U;
        }
    } else {
        __Vdly__page_allocator_tb__DOT__dut__DOT__used_map = 0U;
    }
    vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map 
        = __Vdly__page_allocator_tb__DOT__dut__DOT__used_map;
    vlSelfRef.page_allocator_tb__DOT__alloc_page = 0U;
    vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 0U;
    if ((1U & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map)))) {
        vlSelfRef.page_allocator_tb__DOT__alloc_page = 0U;
        vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 1U;
    }
    if ((1U & ((~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                   >> 1U)) & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag))))) {
        vlSelfRef.page_allocator_tb__DOT__alloc_page = 1U;
        vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 1U;
    }
    if ((1U & ((~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                   >> 2U)) & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag))))) {
        vlSelfRef.page_allocator_tb__DOT__alloc_page = 2U;
        vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 1U;
    }
    if ((1U & ((~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                   >> 3U)) & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag))))) {
        vlSelfRef.page_allocator_tb__DOT__alloc_page = 3U;
        vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 1U;
    }
    if ((1U & ((~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                   >> 4U)) & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag))))) {
        vlSelfRef.page_allocator_tb__DOT__alloc_page = 4U;
        vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 1U;
    }
    if ((1U & ((~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                   >> 5U)) & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag))))) {
        vlSelfRef.page_allocator_tb__DOT__alloc_page = 5U;
        vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 1U;
    }
    if ((1U & ((~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                   >> 6U)) & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag))))) {
        vlSelfRef.page_allocator_tb__DOT__alloc_page = 6U;
        vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 1U;
    }
    if ((1U & ((~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                   >> 7U)) & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag))))) {
        vlSelfRef.page_allocator_tb__DOT__alloc_page = 7U;
        vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 1U;
    }
    if ((1U & ((~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                   >> 8U)) & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag))))) {
        vlSelfRef.page_allocator_tb__DOT__alloc_page = 8U;
        vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 1U;
    }
    if ((1U & ((~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                   >> 9U)) & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag))))) {
        vlSelfRef.page_allocator_tb__DOT__alloc_page = 9U;
        vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 1U;
    }
    if ((1U & ((~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                   >> 0x0aU)) & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag))))) {
        vlSelfRef.page_allocator_tb__DOT__alloc_page = 0x0aU;
        vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 1U;
    }
    if ((1U & ((~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                   >> 0x0bU)) & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag))))) {
        vlSelfRef.page_allocator_tb__DOT__alloc_page = 0x0bU;
        vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 1U;
    }
    if ((1U & ((~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                   >> 0x0cU)) & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag))))) {
        vlSelfRef.page_allocator_tb__DOT__alloc_page = 0x0cU;
        vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 1U;
    }
    if ((1U & ((~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                   >> 0x0dU)) & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag))))) {
        vlSelfRef.page_allocator_tb__DOT__alloc_page = 0x0dU;
        vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 1U;
    }
    if ((1U & ((~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                   >> 0x0eU)) & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag))))) {
        vlSelfRef.page_allocator_tb__DOT__alloc_page = 0x0eU;
        vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 1U;
    }
    if ((1U & ((~ ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                   >> 0x0fU)) & (~ (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag))))) {
        vlSelfRef.page_allocator_tb__DOT__alloc_page = 0x0fU;
        vlSelfRef.page_allocator_tb__DOT__dut__DOT__found_flag = 1U;
    }
}

void Vpage_allocator_tb___024root___timing_ready(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___timing_ready\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_hb34f2848__0.ready("@(negedge page_allocator_tb.clk)");
    }
}

void Vpage_allocator_tb___024root___timing_resume(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___timing_resume\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_hb34f2848__0.moveToResumeQueue(
                                                          "@(negedge page_allocator_tb.clk)");
    vlSelfRef.__VtrigSched_hb34f2848__0.resume("@(negedge page_allocator_tb.clk)");
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vpage_allocator_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vpage_allocator_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0(Vpage_allocator_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root____VbeforeTrig_hb34f2848__0\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)((((~ (IData)(vlSelfRef.page_allocator_tb__DOT__clk)) 
                                   & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__page_allocator_tb__DOT__clk__0)) 
                                  << 2U)));
    vlSelfRef.__Vtrigprevexpr___TOP__page_allocator_tb__DOT__clk__0 
        = vlSelfRef.page_allocator_tb__DOT__clk;
    if ((4ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb34f2848__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vpage_allocator_tb___024root___eval_debug_assertions(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_debug_assertions\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
