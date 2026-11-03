// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkv_mem_interface_tb.h for the primary calling header

#include "Vkv_mem_interface_tb__pch.h"

VlCoroutine Vkv_mem_interface_tb___024root___eval_initial__TOP__Vtiming__0(Vkv_mem_interface_tb___024root* vlSelf);
VlCoroutine Vkv_mem_interface_tb___024root___eval_initial__TOP__Vtiming__1(Vkv_mem_interface_tb___024root* vlSelf);

void Vkv_mem_interface_tb___024root___eval_initial(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_initial\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        vlSymsp->_vm_contextp__->dumpfile("dump.vcd"s);
        vlSymsp->_traceDumpOpen();
    }
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vkv_mem_interface_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vkv_mem_interface_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vkv_mem_interface_tb___024root___eval_sample(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_sample\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkv_mem_interface_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vkv_mem_interface_tb___024root___eval_ico(Vkv_mem_interface_tb___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_ico\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vkv_mem_interface_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

void Vkv_mem_interface_tb___024root___timing_ready(Vkv_mem_interface_tb___024root* vlSelf);
void Vkv_mem_interface_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vkv_mem_interface_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vkv_mem_interface_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vkv_mem_interface_tb___024root___timing_resume(Vkv_mem_interface_tb___024root* vlSelf);

bool Vkv_mem_interface_tb___024root___eval_act(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_act\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((((~ (IData)(vlSelfRef.kv_mem_interface_tb__DOT__clk)) 
                                                           & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__kv_mem_interface_tb__DOT__clk__0)) 
                                                          << 2U) 
                                                         | ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.kv_mem_interface_tb__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__kv_mem_interface_tb__DOT__clk__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__kv_mem_interface_tb__DOT__clk__0 
            = vlSelfRef.kv_mem_interface_tb__DOT__clk;
    }
    Vkv_mem_interface_tb___024root___timing_ready(vlSelf);
    Vkv_mem_interface_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vkv_mem_interface_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vkv_mem_interface_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vkv_mem_interface_tb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vkv_mem_interface_tb___024root___timing_resume(vlSelf);
        {
            // Inlined CFunc: _eval_body__act
            if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
                {
                    // Inlined CFunc: _act_sequent__TOP__0
                    vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__accept 
                        = ((~ (IData)(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state)) 
                           & (IData)(vlSelfRef.kv_mem_interface_tb__DOT__req_valid));
                    vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__wr_en 
                        = ((IData)(vlSelfRef.kv_mem_interface_tb__DOT__req_write) 
                           & (IData)(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__accept));
                    vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__rd_en 
                        = ((~ (IData)(vlSelfRef.kv_mem_interface_tb__DOT__req_write)) 
                           & (IData)(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__accept));
                }
            }
        }
    }
    return (__VactExecute);
}

bool Vkv_mem_interface_tb___024root___eval_inact(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_inact\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("kv_mem_interface_tb.sv", 18, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vkv_mem_interface_tb___024root___nba_sequent__TOP__0(Vkv_mem_interface_tb___024root* vlSelf);
void Vkv_mem_interface_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vkv_mem_interface_tb___024root___eval_nba(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_nba\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vkv_mem_interface_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vkv_mem_interface_tb___024root___nba_sequent__TOP__0(vlSelf);
                vlSelfRef.__Vm_traceActivity[3U] = 1U;
            }
            if ((5ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _act_sequent__TOP__0
                    vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__accept 
                        = ((~ (IData)(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state)) 
                           & (IData)(vlSelfRef.kv_mem_interface_tb__DOT__req_valid));
                    vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__wr_en 
                        = ((IData)(vlSelfRef.kv_mem_interface_tb__DOT__req_write) 
                           & (IData)(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__accept));
                    vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__rd_en 
                        = ((~ (IData)(vlSelfRef.kv_mem_interface_tb__DOT__req_write)) 
                           & (IData)(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__accept));
                }
            }
        }
        Vkv_mem_interface_tb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vkv_mem_interface_tb___024root___eval_obs(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_obs\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vkv_mem_interface_tb___024root___eval_react(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_react\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vkv_mem_interface_tb___024root___eval_postponed(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_postponed\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VlCoroutine Vkv_mem_interface_tb___024root___eval_initial__TOP__Vtiming__0(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.kv_mem_interface_tb__DOT__clk = 0U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "kv_mem_interface_tb.sv", 
                                             38);
        vlSelfRef.kv_mem_interface_tb__DOT__clk = (1U 
                                                   & (~ (IData)(vlSelfRef.kv_mem_interface_tb__DOT__clk)));
    }
    co_return;
}

extern const VlWide<8>/*255:0*/ Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0;
void Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(Vkv_mem_interface_tb___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vkv_mem_interface_tb___024root___eval_initial__TOP__Vtiming__1(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ kv_mem_interface_tb__DOT__unnamedblk3__DOT__i;
    kv_mem_interface_tb__DOT__unnamedblk3__DOT__i = 0;
    IData/*31:0*/ kv_mem_interface_tb__DOT__unnamedblk4__DOT__i;
    kv_mem_interface_tb__DOT__unnamedblk4__DOT__i = 0;
    IData/*31:0*/ kv_mem_interface_tb__DOT__unnamedblk1_1__DOT____Vrepeat0;
    kv_mem_interface_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    VlWide<8>/*255:0*/ __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout);
    VlWide<8>/*255:0*/ __Vfunc_kv_mem_interface_tb__DOT__rand256__0__r;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__0__r);
    VlWide<8>/*255:0*/ __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout);
    VlWide<8>/*255:0*/ __Vfunc_kv_mem_interface_tb__DOT__rand256__1__r;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__1__r);
    VlWide<8>/*255:0*/ __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256;
    VL_ZERO_W(256, __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256);
    VlWide<8>/*255:0*/ __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256;
    VL_ZERO_W(256, __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256);
    VlWide<8>/*255:0*/ __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout);
    VlWide<8>/*255:0*/ __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r);
    VlWide<8>/*255:0*/ __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout);
    VlWide<8>/*255:0*/ __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r);
    VlWide<8>/*255:0*/ __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout);
    VlWide<8>/*255:0*/ __Vfunc_kv_mem_interface_tb__DOT__rand256__6__r;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__6__r);
    VlWide<8>/*255:0*/ __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout);
    VlWide<8>/*255:0*/ __Vfunc_kv_mem_interface_tb__DOT__rand256__7__r;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__7__r);
    CData/*7:0*/ __Vtask_kv_mem_interface_tb__DOT__do_write__8__a;
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__a = 0;
    VlWide<8>/*255:0*/ __Vtask_kv_mem_interface_tb__DOT__do_write__8__k;
    VL_ZERO_W(256, __Vtask_kv_mem_interface_tb__DOT__do_write__8__k);
    VlWide<8>/*255:0*/ __Vtask_kv_mem_interface_tb__DOT__do_write__8__v;
    VL_ZERO_W(256, __Vtask_kv_mem_interface_tb__DOT__do_write__8__v);
    VlWide<8>/*255:0*/ __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout);
    VlWide<8>/*255:0*/ __Vfunc_kv_mem_interface_tb__DOT__rand256__10__r;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__10__r);
    VlWide<8>/*255:0*/ __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout);
    VlWide<8>/*255:0*/ __Vfunc_kv_mem_interface_tb__DOT__rand256__11__r;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__11__r);
    CData/*7:0*/ __Vtask_kv_mem_interface_tb__DOT__do_write__12__a;
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__a = 0;
    VlWide<8>/*255:0*/ __Vtask_kv_mem_interface_tb__DOT__do_write__12__k;
    VL_ZERO_W(256, __Vtask_kv_mem_interface_tb__DOT__do_write__12__k);
    VlWide<8>/*255:0*/ __Vtask_kv_mem_interface_tb__DOT__do_write__12__v;
    VL_ZERO_W(256, __Vtask_kv_mem_interface_tb__DOT__do_write__12__v);
    VlWide<8>/*255:0*/ __Vtemp_1;
    VlWide<8>/*255:0*/ __Vtemp_2;
    VlWide<8>/*255:0*/ __Vtemp_3;
    VlWide<8>/*255:0*/ __Vtemp_4;
    IData/*31:0*/ __VExpandSel_WordIdx_1;
    IData/*31:0*/ __VExpandSel_WordIdx_2;
    IData/*31:0*/ __VExpandSel_WordIdx_3;
    IData/*31:0*/ __VExpandSel_WordIdx_4;
    IData/*31:0*/ __VExpandSel_WordIdx_5;
    IData/*31:0*/ __VExpandSel_WordIdx_6;
    // Body
    vlSelfRef.kv_mem_interface_tb__DOT__rst_n = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_write = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__resp_ready = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_addr = 0U;
    VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__req_data_k, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
    VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__req_data_v, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         102);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__rst_n = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__test_errors 
        = vlSelfRef.kv_mem_interface_tb__DOT__errors;
    vlSelfRef.kv_mem_interface_tb__DOT__addr = (0x000000ffU 
                                                & VL_RANDOM_I());
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout);
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__0__r);
    VL_RANDOM_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__0__r);
    __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__0__r[0U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__0__r[1U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__0__r[2U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__0__r[3U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__0__r[4U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__0__r[5U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__0__r[6U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__0__r[7U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[0U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[1U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[2U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[3U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[4U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[5U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[6U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[7U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__0__Vfuncout[7U];
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout);
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__1__r);
    VL_RANDOM_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__1__r);
    __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__1__r[0U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__1__r[1U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__1__r[2U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__1__r[3U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__1__r[4U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__1__r[5U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__1__r[6U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__1__r[7U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[0U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[1U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[2U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[3U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[4U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[5U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[6U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[7U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__1__Vfuncout[7U];
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         109);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_write = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_addr = vlSelfRef.kv_mem_interface_tb__DOT__addr;
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[0U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[1U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[2U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[3U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[4U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[5U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[6U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[7U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[7U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[0U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[1U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[2U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[3U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[4U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[5U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[6U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[7U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[7U];
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         113);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 0U;
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_write = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_addr = vlSelfRef.kv_mem_interface_tb__DOT__addr;
    vlSelfRef.kv_mem_interface_tb__DOT__resp_ready = 1U;
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         119);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 0U;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state)))))) {
        vlSelfRef.kv_mem_interface_tb__DOT__errors 
            = ((IData)(1U) + vlSelfRef.kv_mem_interface_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: kv_mem_interface_tb.sv:123: Assertion failed in %m: [%0t] resp_valid not high after read\n",4, 'M',vlSymsp->name(),"kv_mem_interface_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("kv_mem_interface_tb.sv", 123, "");
    }
    if (VL_UNLIKELY(((0U != ((((((((vlSelfRef.kv_mem_interface_tb__DOT__exp_k[0U] 
                                    ^ vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[0U]) 
                                   | (vlSelfRef.kv_mem_interface_tb__DOT__exp_k[1U] 
                                      ^ vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[1U])) 
                                  | (vlSelfRef.kv_mem_interface_tb__DOT__exp_k[2U] 
                                     ^ vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[2U])) 
                                 | (vlSelfRef.kv_mem_interface_tb__DOT__exp_k[3U] 
                                    ^ vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[3U])) 
                                | (vlSelfRef.kv_mem_interface_tb__DOT__exp_k[4U] 
                                   ^ vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[4U])) 
                               | (vlSelfRef.kv_mem_interface_tb__DOT__exp_k[5U] 
                                  ^ vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[5U])) 
                              | (vlSelfRef.kv_mem_interface_tb__DOT__exp_k[6U] 
                                 ^ vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[6U])) 
                             | (vlSelfRef.kv_mem_interface_tb__DOT__exp_k[7U] 
                                ^ vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[7U])))))) {
        vlSelfRef.kv_mem_interface_tb__DOT__errors 
            = ((IData)(1U) + vlSelfRef.kv_mem_interface_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: kv_mem_interface_tb.sv:128: Assertion failed in %m: [%0t]: full write/read cycle failed on Key data. Expected = %0d, got = %0d\n",6, 'M',vlSymsp->name(),"kv_mem_interface_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',256,vlSelfRef.kv_mem_interface_tb__DOT__req_data_k.data()
                     , '#',256,vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k.data());
        VL_STOP_MT("kv_mem_interface_tb.sv", 128, "");
    }
    if (VL_UNLIKELY(((0U != ((((((((vlSelfRef.kv_mem_interface_tb__DOT__exp_v[0U] 
                                    ^ vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[0U]) 
                                   | (vlSelfRef.kv_mem_interface_tb__DOT__exp_v[1U] 
                                      ^ vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[1U])) 
                                  | (vlSelfRef.kv_mem_interface_tb__DOT__exp_v[2U] 
                                     ^ vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[2U])) 
                                 | (vlSelfRef.kv_mem_interface_tb__DOT__exp_v[3U] 
                                    ^ vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[3U])) 
                                | (vlSelfRef.kv_mem_interface_tb__DOT__exp_v[4U] 
                                   ^ vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[4U])) 
                               | (vlSelfRef.kv_mem_interface_tb__DOT__exp_v[5U] 
                                  ^ vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[5U])) 
                              | (vlSelfRef.kv_mem_interface_tb__DOT__exp_v[6U] 
                                 ^ vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[6U])) 
                             | (vlSelfRef.kv_mem_interface_tb__DOT__exp_v[7U] 
                                ^ vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[7U])))))) {
        vlSelfRef.kv_mem_interface_tb__DOT__errors 
            = ((IData)(1U) + vlSelfRef.kv_mem_interface_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: kv_mem_interface_tb.sv:133: Assertion failed in %m: [%0t]: full write/read cycle failed on Value data. Expected = %0d, got = %0d\n",6, 'M',vlSymsp->name(),"kv_mem_interface_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',256,vlSelfRef.kv_mem_interface_tb__DOT__req_data_v.data()
                     , '#',256,vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v.data());
        VL_STOP_MT("kv_mem_interface_tb.sv", 133, "");
    }
    vlSelfRef.kv_mem_interface_tb__DOT__rst_n = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_write = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__resp_ready = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_addr = 0U;
    VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__req_data_k, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
    VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__req_data_v, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
    if ((vlSelfRef.kv_mem_interface_tb__DOT__test_errors 
         == vlSelfRef.kv_mem_interface_tb__DOT__errors)) {
        VL_WRITEF_NX("Test 1 passed, successful read and write to both K and V on one piece of data\n",0);
    } else {
        VL_WRITEF_NX("Test 1 failed, read or write to KV failed.\n",0);
    }
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         146);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__rst_n = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__test_errors 
        = vlSelfRef.kv_mem_interface_tb__DOT__errors;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout);
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r);
    VL_RANDOM_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r);
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[0U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[1U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[2U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[3U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[4U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[5U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[6U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[7U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[0U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[1U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[2U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[3U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[4U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[5U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[6U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[7U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[0U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[1U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[2U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[3U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[4U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[5U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[6U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[7U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[7U];
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout);
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r);
    VL_RANDOM_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r);
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[0U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[1U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[2U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[3U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[4U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[5U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[6U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[7U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[0U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[1U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[2U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[3U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[4U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[5U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[6U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[7U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[0U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[1U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[2U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[3U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[4U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[5U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[6U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[7U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[7U];
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout);
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r);
    VL_RANDOM_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r);
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[0U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[1U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[2U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[3U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[4U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[5U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[6U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[7U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[0U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[1U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[2U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[3U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[4U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[5U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[6U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[7U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[8U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[9U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[10U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[11U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[12U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[13U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[14U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[15U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[7U];
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout);
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r);
    VL_RANDOM_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r);
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[0U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[1U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[2U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[3U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[4U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[5U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[6U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[7U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[0U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[1U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[2U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[3U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[4U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[5U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[6U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[7U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[8U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[9U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[10U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[11U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[12U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[13U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[14U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[15U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[7U];
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout);
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r);
    VL_RANDOM_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r);
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[0U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[1U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[2U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[3U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[4U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[5U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[6U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__r[7U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[0U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[1U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[2U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[3U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[4U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[5U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[6U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__3__Vfuncout[7U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[16U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[17U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[18U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[19U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[20U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[21U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[22U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array[23U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_0__rand256[7U];
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout);
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r);
    VL_RANDOM_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r);
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[0U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[1U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[2U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[3U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[4U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[5U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[6U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__r[7U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[0U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[1U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[2U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[3U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[4U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[5U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[6U];
    __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__4__Vfuncout[7U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[16U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[17U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[18U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[19U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[20U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[21U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[22U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array[23U] 
        = __Vtask_kv_mem_interface_tb__DOT__fill_arrays__2____VlefCall_1__rand256[7U];
    vlSelfRef.kv_mem_interface_tb__DOT__addresses = 0x00222324U;
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         152);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    kv_mem_interface_tb__DOT__unnamedblk3__DOT__i = 0U;
    while (VL_GTS_III(32, 3U, kv_mem_interface_tb__DOT__unnamedblk3__DOT__i)) {
        vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 1U;
        vlSelfRef.kv_mem_interface_tb__DOT__req_write = 1U;
        vlSelfRef.kv_mem_interface_tb__DOT__req_addr 
            = ((0x17U >= (0x0000001fU & (kv_mem_interface_tb__DOT__unnamedblk3__DOT__i 
                                         << 3U))) ? 
               (0x000000ffU & (vlSelfRef.kv_mem_interface_tb__DOT__addresses 
                               >> (0x0000001fU & (kv_mem_interface_tb__DOT__unnamedblk3__DOT__i 
                                                  << 3U))))
                : 0U);
        if ((0x02ffU >= (0x000003ffU & (kv_mem_interface_tb__DOT__unnamedblk3__DOT__i 
                                        << 8U)))) {
            __VExpandSel_WordIdx_1 = (0x00000018U & 
                                      (kv_mem_interface_tb__DOT__unnamedblk3__DOT__i 
                                       << 3U));
            vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[0U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                [__VExpandSel_WordIdx_1];
            vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[1U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                [((IData)(1U) + __VExpandSel_WordIdx_1)];
            vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[2U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                [((IData)(2U) + __VExpandSel_WordIdx_1)];
            vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[3U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                [((IData)(3U) + __VExpandSel_WordIdx_1)];
            vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[4U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                [((IData)(4U) + __VExpandSel_WordIdx_1)];
            vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[5U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                [((IData)(5U) + __VExpandSel_WordIdx_1)];
            vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[6U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                [((IData)(6U) + __VExpandSel_WordIdx_1)];
            vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[7U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                [((IData)(7U) + __VExpandSel_WordIdx_1)];
            __VExpandSel_WordIdx_2 = (0x00000018U & 
                                      (kv_mem_interface_tb__DOT__unnamedblk3__DOT__i 
                                       << 3U));
            vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[0U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                [__VExpandSel_WordIdx_2];
            vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[1U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                [((IData)(1U) + __VExpandSel_WordIdx_2)];
            vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[2U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                [((IData)(2U) + __VExpandSel_WordIdx_2)];
            vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[3U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                [((IData)(3U) + __VExpandSel_WordIdx_2)];
            vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[4U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                [((IData)(4U) + __VExpandSel_WordIdx_2)];
            vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[5U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                [((IData)(5U) + __VExpandSel_WordIdx_2)];
            vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[6U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                [((IData)(6U) + __VExpandSel_WordIdx_2)];
            vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[7U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                [((IData)(7U) + __VExpandSel_WordIdx_2)];
        } else {
            VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__req_data_k, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
            VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__req_data_v, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        }
        Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                                   "@(negedge kv_mem_interface_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge kv_mem_interface_tb.clk)", 
                                                             "kv_mem_interface_tb.sv", 
                                                             157);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 0U;
        Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                                   "@(negedge kv_mem_interface_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge kv_mem_interface_tb.clk)", 
                                                             "kv_mem_interface_tb.sv", 
                                                             160);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        kv_mem_interface_tb__DOT__unnamedblk3__DOT__i 
            = ((IData)(1U) + kv_mem_interface_tb__DOT__unnamedblk3__DOT__i);
    }
    kv_mem_interface_tb__DOT__unnamedblk4__DOT__i = 0U;
    while (VL_GTS_III(32, 3U, kv_mem_interface_tb__DOT__unnamedblk4__DOT__i)) {
        vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 1U;
        vlSelfRef.kv_mem_interface_tb__DOT__req_write = 0U;
        vlSelfRef.kv_mem_interface_tb__DOT__req_addr 
            = ((0x17U >= (0x0000001fU & (kv_mem_interface_tb__DOT__unnamedblk4__DOT__i 
                                         << 3U))) ? 
               (0x000000ffU & (vlSelfRef.kv_mem_interface_tb__DOT__addresses 
                               >> (0x0000001fU & (kv_mem_interface_tb__DOT__unnamedblk4__DOT__i 
                                                  << 3U))))
                : 0U);
        vlSelfRef.kv_mem_interface_tb__DOT__resp_ready = 1U;
        Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                                   "@(negedge kv_mem_interface_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge kv_mem_interface_tb.clk)", 
                                                             "kv_mem_interface_tb.sv", 
                                                             167);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 0U;
        if ((0x02ffU >= (0x000003ffU & (kv_mem_interface_tb__DOT__unnamedblk4__DOT__i 
                                        << 8U)))) {
            __VExpandSel_WordIdx_3 = (0x00000018U & 
                                      (kv_mem_interface_tb__DOT__unnamedblk4__DOT__i 
                                       << 3U));
            __Vtemp_1[0U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                [__VExpandSel_WordIdx_3];
            __Vtemp_1[1U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                [((IData)(1U) + __VExpandSel_WordIdx_3)];
            __Vtemp_1[2U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                [((IData)(2U) + __VExpandSel_WordIdx_3)];
            __Vtemp_1[3U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                [((IData)(3U) + __VExpandSel_WordIdx_3)];
            __Vtemp_1[4U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                [((IData)(4U) + __VExpandSel_WordIdx_3)];
            __Vtemp_1[5U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                [((IData)(5U) + __VExpandSel_WordIdx_3)];
            __Vtemp_1[6U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                [((IData)(6U) + __VExpandSel_WordIdx_3)];
            __Vtemp_1[7U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                [((IData)(7U) + __VExpandSel_WordIdx_3)];
            __VExpandSel_WordIdx_5 = (0x00000018U & 
                                      (kv_mem_interface_tb__DOT__unnamedblk4__DOT__i 
                                       << 3U));
            __Vtemp_3[0U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                [__VExpandSel_WordIdx_5];
            __Vtemp_3[1U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                [((IData)(1U) + __VExpandSel_WordIdx_5)];
            __Vtemp_3[2U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                [((IData)(2U) + __VExpandSel_WordIdx_5)];
            __Vtemp_3[3U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                [((IData)(3U) + __VExpandSel_WordIdx_5)];
            __Vtemp_3[4U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                [((IData)(4U) + __VExpandSel_WordIdx_5)];
            __Vtemp_3[5U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                [((IData)(5U) + __VExpandSel_WordIdx_5)];
            __Vtemp_3[6U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                [((IData)(6U) + __VExpandSel_WordIdx_5)];
            __Vtemp_3[7U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                [((IData)(7U) + __VExpandSel_WordIdx_5)];
        } else {
            VL_ASSIGN_W(256, __Vtemp_1, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
            VL_ASSIGN_W(256, __Vtemp_3, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        }
        if (VL_UNLIKELY(((0U != ((((((((vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[0U] 
                                        ^ __Vtemp_1[0U]) 
                                       | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[1U] 
                                          ^ __Vtemp_1[1U])) 
                                      | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[2U] 
                                         ^ __Vtemp_1[2U])) 
                                     | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[3U] 
                                        ^ __Vtemp_1[3U])) 
                                    | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[4U] 
                                       ^ __Vtemp_1[4U])) 
                                   | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[5U] 
                                      ^ __Vtemp_1[5U])) 
                                  | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[6U] 
                                     ^ __Vtemp_1[6U])) 
                                 | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[7U] 
                                    ^ __Vtemp_1[7U])))))) {
            vlSelfRef.kv_mem_interface_tb__DOT__errors 
                = ((IData)(1U) + vlSelfRef.kv_mem_interface_tb__DOT__errors);
            if ((0x02ffU >= (0x000003ffU & (kv_mem_interface_tb__DOT__unnamedblk4__DOT__i 
                                            << 8U)))) {
                __VExpandSel_WordIdx_4 = (0x00000018U 
                                          & (kv_mem_interface_tb__DOT__unnamedblk4__DOT__i 
                                             << 3U));
                __Vtemp_2[0U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                    [__VExpandSel_WordIdx_4];
                __Vtemp_2[1U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                    [((IData)(1U) + __VExpandSel_WordIdx_4)];
                __Vtemp_2[2U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                    [((IData)(2U) + __VExpandSel_WordIdx_4)];
                __Vtemp_2[3U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                    [((IData)(3U) + __VExpandSel_WordIdx_4)];
                __Vtemp_2[4U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                    [((IData)(4U) + __VExpandSel_WordIdx_4)];
                __Vtemp_2[5U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                    [((IData)(5U) + __VExpandSel_WordIdx_4)];
                __Vtemp_2[6U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                    [((IData)(6U) + __VExpandSel_WordIdx_4)];
                __Vtemp_2[7U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array
                    [((IData)(7U) + __VExpandSel_WordIdx_4)];
            } else {
                VL_ASSIGN_W(256, __Vtemp_2, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
            }
            VL_WRITEF_NX("[%0t] %%Error: kv_mem_interface_tb.sv:171: Assertion failed in %m: [%0t] K data mismatch. Expected = %0d, got = %0d, on iteration %0d\n",7, 'M',vlSymsp->name(),"kv_mem_interface_tb.unnamedblk4", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',256,__Vtemp_2.data()
                         , '#',256,vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k.data()
                         , '~',32,kv_mem_interface_tb__DOT__unnamedblk4__DOT__i);
            VL_STOP_MT("kv_mem_interface_tb.sv", 171, "");
        }
        if (VL_UNLIKELY(((0U != ((((((((vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[0U] 
                                        ^ __Vtemp_3[0U]) 
                                       | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[1U] 
                                          ^ __Vtemp_3[1U])) 
                                      | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[2U] 
                                         ^ __Vtemp_3[2U])) 
                                     | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[3U] 
                                        ^ __Vtemp_3[3U])) 
                                    | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[4U] 
                                       ^ __Vtemp_3[4U])) 
                                   | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[5U] 
                                      ^ __Vtemp_3[5U])) 
                                  | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[6U] 
                                     ^ __Vtemp_3[6U])) 
                                 | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[7U] 
                                    ^ __Vtemp_3[7U])))))) {
            vlSelfRef.kv_mem_interface_tb__DOT__errors 
                = ((IData)(1U) + vlSelfRef.kv_mem_interface_tb__DOT__errors);
            if ((0x02ffU >= (0x000003ffU & (kv_mem_interface_tb__DOT__unnamedblk4__DOT__i 
                                            << 8U)))) {
                __VExpandSel_WordIdx_6 = (0x00000018U 
                                          & (kv_mem_interface_tb__DOT__unnamedblk4__DOT__i 
                                             << 3U));
                __Vtemp_4[0U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                    [__VExpandSel_WordIdx_6];
                __Vtemp_4[1U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                    [((IData)(1U) + __VExpandSel_WordIdx_6)];
                __Vtemp_4[2U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                    [((IData)(2U) + __VExpandSel_WordIdx_6)];
                __Vtemp_4[3U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                    [((IData)(3U) + __VExpandSel_WordIdx_6)];
                __Vtemp_4[4U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                    [((IData)(4U) + __VExpandSel_WordIdx_6)];
                __Vtemp_4[5U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                    [((IData)(5U) + __VExpandSel_WordIdx_6)];
                __Vtemp_4[6U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                    [((IData)(6U) + __VExpandSel_WordIdx_6)];
                __Vtemp_4[7U] = vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array
                    [((IData)(7U) + __VExpandSel_WordIdx_6)];
            } else {
                VL_ASSIGN_W(256, __Vtemp_4, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
            }
            VL_WRITEF_NX("[%0t] %%Error: kv_mem_interface_tb.sv:175: Assertion failed in %m: [%0t] V data mismatch. Expected = %0d, got = %0d, on iteration %0d\n",7, 'M',vlSymsp->name(),"kv_mem_interface_tb.unnamedblk4", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',256,__Vtemp_4.data()
                         , '#',256,vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v.data()
                         , '~',32,kv_mem_interface_tb__DOT__unnamedblk4__DOT__i);
            VL_STOP_MT("kv_mem_interface_tb.sv", 175, "");
        }
        Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                                   "@(negedge kv_mem_interface_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge kv_mem_interface_tb.clk)", 
                                                             "kv_mem_interface_tb.sv", 
                                                             177);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        kv_mem_interface_tb__DOT__unnamedblk4__DOT__i 
            = ((IData)(1U) + kv_mem_interface_tb__DOT__unnamedblk4__DOT__i);
    }
    vlSelfRef.kv_mem_interface_tb__DOT__rst_n = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_write = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__resp_ready = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_addr = 0U;
    VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__req_data_k, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
    VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__req_data_v, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
    if ((vlSelfRef.kv_mem_interface_tb__DOT__test_errors 
         == vlSelfRef.kv_mem_interface_tb__DOT__errors)) {
        VL_WRITEF_NX("Test 2 passed. Multiple read after write cycles.\n",0);
    } else {
        VL_WRITEF_NX("Test 2 failed.\n",0);
    }
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         79);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__rst_n = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__test_errors 
        = vlSelfRef.kv_mem_interface_tb__DOT__errors;
    vlSelfRef.kv_mem_interface_tb__DOT__addr = 0x40U;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout);
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__6__r);
    VL_RANDOM_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__6__r);
    __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__6__r[0U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__6__r[1U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__6__r[2U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__6__r[3U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__6__r[4U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__6__r[5U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__6__r[6U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__6__r[7U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[0U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[1U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[2U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[3U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[4U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[5U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[6U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[7U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__6__Vfuncout[7U];
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout);
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__7__r);
    VL_RANDOM_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__7__r);
    __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__7__r[0U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__7__r[1U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__7__r[2U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__7__r[3U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__7__r[4U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__7__r[5U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__7__r[6U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__7__r[7U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[0U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[1U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[2U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[3U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[4U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[5U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[6U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[7U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__7__Vfuncout[7U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__v[0U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[0U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__v[1U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[1U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__v[2U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[2U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__v[3U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[3U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__v[4U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[4U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__v[5U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[5U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__v[6U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[6U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__v[7U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[7U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__k[0U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[0U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__k[1U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[1U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__k[2U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[2U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__k[3U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[3U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__k[4U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[4U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__k[5U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[5U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__k[6U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[6U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__k[7U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[7U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__8__a 
        = vlSelfRef.kv_mem_interface_tb__DOT__addr;
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         88);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_write = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_addr = __Vtask_kv_mem_interface_tb__DOT__do_write__8__a;
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[0U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__8__k[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[1U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__8__k[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[2U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__8__k[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[3U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__8__k[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[4U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__8__k[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[5U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__8__k[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[6U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__8__k[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[7U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__8__k[7U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[0U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__8__v[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[1U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__8__v[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[2U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__8__v[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[3U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__8__v[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[4U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__8__v[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[5U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__8__v[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[6U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__8__v[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[7U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__8__v[7U];
    while (vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state) {
        Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                                   "@(negedge kv_mem_interface_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge kv_mem_interface_tb.clk)", 
                                                             "kv_mem_interface_tb.sv", 
                                                             92);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         93);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 0U;
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         194);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_write = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_addr = vlSelfRef.kv_mem_interface_tb__DOT__addr;
    vlSelfRef.kv_mem_interface_tb__DOT__resp_ready = 0U;
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         196);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 0U;
    kv_mem_interface_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 = 5U;
    while (VL_LTS_III(32, 0U, kv_mem_interface_tb__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                                   "@(negedge kv_mem_interface_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge kv_mem_interface_tb.clk)", 
                                                             "kv_mem_interface_tb.sv", 
                                                             200);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state)))))) {
            vlSelfRef.kv_mem_interface_tb__DOT__errors 
                = ((IData)(1U) + vlSelfRef.kv_mem_interface_tb__DOT__errors);
            VL_WRITEF_NX("[%0t] %%Error: kv_mem_interface_tb.sv:202: Assertion failed in %m: [%0t] Test 3: resp_valid dropped while stalled\n",4, 'M',vlSymsp->name(),"kv_mem_interface_tb.unnamedblk1_1", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("kv_mem_interface_tb.sv", 202, "");
        }
        if (VL_UNLIKELY((((0U != ((((((((vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[0U] 
                                         ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_k[0U]) 
                                        | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[1U] 
                                           ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_k[1U])) 
                                       | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[2U] 
                                          ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_k[2U])) 
                                      | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[3U] 
                                         ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_k[3U])) 
                                     | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[4U] 
                                        ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_k[4U])) 
                                    | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[5U] 
                                       ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_k[5U])) 
                                   | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[6U] 
                                      ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_k[6U])) 
                                  | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[7U] 
                                     ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_k[7U]))) 
                          | (0U != ((((((((vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[0U] 
                                           ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_v[0U]) 
                                          | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[1U] 
                                             ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_v[1U])) 
                                         | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[2U] 
                                            ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_v[2U])) 
                                        | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[3U] 
                                           ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_v[3U])) 
                                       | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[4U] 
                                          ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_v[4U])) 
                                      | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[5U] 
                                         ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_v[5U])) 
                                     | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[6U] 
                                        ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_v[6U])) 
                                    | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[7U] 
                                       ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_v[7U]))))))) {
            vlSelfRef.kv_mem_interface_tb__DOT__errors 
                = ((IData)(1U) + vlSelfRef.kv_mem_interface_tb__DOT__errors);
            VL_WRITEF_NX("[%0t] %%Error: kv_mem_interface_tb.sv:205: Assertion failed in %m: [%0t] Test 3: response data changed while stalled\n",4, 'M',vlSymsp->name(),"kv_mem_interface_tb.unnamedblk1_1", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("kv_mem_interface_tb.sv", 205, "");
        }
        kv_mem_interface_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (kv_mem_interface_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.kv_mem_interface_tb__DOT__resp_ready = 1U;
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         210);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__resp_ready = 0U;
    if (VL_UNLIKELY((vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state))) {
        vlSelfRef.kv_mem_interface_tb__DOT__errors 
            = ((IData)(1U) + vlSelfRef.kv_mem_interface_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: kv_mem_interface_tb.sv:213: Assertion failed in %m: [%0t] Test 3: resp_valid still high after being consumed\n",4, 'M',vlSymsp->name(),"kv_mem_interface_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("kv_mem_interface_tb.sv", 213, "");
    }
    vlSelfRef.kv_mem_interface_tb__DOT__rst_n = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_write = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__resp_ready = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_addr = 0U;
    VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__req_data_k, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
    VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__req_data_v, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
    if ((vlSelfRef.kv_mem_interface_tb__DOT__test_errors 
         == vlSelfRef.kv_mem_interface_tb__DOT__errors)) {
        VL_WRITEF_NX("Test 3 passed (stalled response holds)\n",0);
    } else {
        VL_WRITEF_NX("Test 3 failed.\n",0);
    }
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         79);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__rst_n = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__test_errors 
        = vlSelfRef.kv_mem_interface_tb__DOT__errors;
    vlSelfRef.kv_mem_interface_tb__DOT__addr = 0x42U;
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout);
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__10__r);
    VL_RANDOM_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__10__r);
    __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__10__r[0U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__10__r[1U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__10__r[2U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__10__r[3U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__10__r[4U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__10__r[5U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__10__r[6U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__10__r[7U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[0U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[1U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[2U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[3U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[4U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[5U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[6U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_k[7U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__10__Vfuncout[7U];
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout);
    VL_ZERO_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__11__r);
    VL_RANDOM_W(256, __Vfunc_kv_mem_interface_tb__DOT__rand256__11__r);
    __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout[0U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__11__r[0U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout[1U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__11__r[1U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout[2U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__11__r[2U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout[3U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__11__r[3U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout[4U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__11__r[4U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout[5U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__11__r[5U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout[6U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__11__r[6U];
    __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout[7U] 
        = __Vfunc_kv_mem_interface_tb__DOT__rand256__11__r[7U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[0U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[1U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[2U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[3U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[4U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[5U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[6U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__exp_v[7U] = __Vfunc_kv_mem_interface_tb__DOT__rand256__11__Vfuncout[7U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__v[0U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[0U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__v[1U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[1U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__v[2U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[2U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__v[3U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[3U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__v[4U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[4U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__v[5U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[5U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__v[6U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[6U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__v[7U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_v[7U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__k[0U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[0U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__k[1U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[1U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__k[2U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[2U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__k[3U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[3U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__k[4U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[4U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__k[5U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[5U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__k[6U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[6U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__k[7U] 
        = vlSelfRef.kv_mem_interface_tb__DOT__exp_k[7U];
    __Vtask_kv_mem_interface_tb__DOT__do_write__12__a 
        = vlSelfRef.kv_mem_interface_tb__DOT__addr;
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         88);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_write = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_addr = __Vtask_kv_mem_interface_tb__DOT__do_write__12__a;
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[0U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__12__k[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[1U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__12__k[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[2U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__12__k[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[3U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__12__k[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[4U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__12__k[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[5U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__12__k[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[6U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__12__k[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[7U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__12__k[7U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[0U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__12__v[0U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[1U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__12__v[1U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[2U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__12__v[2U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[3U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__12__v[3U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[4U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__12__v[4U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[5U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__12__v[5U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[6U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__12__v[6U];
    vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[7U] 
        = __Vtask_kv_mem_interface_tb__DOT__do_write__12__v[7U];
    while (vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state) {
        Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                                   "@(negedge kv_mem_interface_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge kv_mem_interface_tb.clk)", 
                                                             "kv_mem_interface_tb.sv", 
                                                             92);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         93);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 0U;
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         229);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_write = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_addr = vlSelfRef.kv_mem_interface_tb__DOT__addr;
    vlSelfRef.kv_mem_interface_tb__DOT__resp_ready = 0U;
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         231);
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state)))))) {
        vlSelfRef.kv_mem_interface_tb__DOT__errors 
            = ((IData)(1U) + vlSelfRef.kv_mem_interface_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: kv_mem_interface_tb.sv:234: Assertion failed in %m: [%0t] Test 4: setup failed, not in RESPONSE\n",4, 'M',vlSymsp->name(),"kv_mem_interface_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("kv_mem_interface_tb.sv", 234, "");
    }
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__rst_n = 0U;
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         238);
    if (VL_UNLIKELY((vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state))) {
        vlSelfRef.kv_mem_interface_tb__DOT__errors 
            = ((IData)(1U) + vlSelfRef.kv_mem_interface_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: kv_mem_interface_tb.sv:241: Assertion failed in %m: [%0t] Test 4: resp_valid still high after reset\n",4, 'M',vlSymsp->name(),"kv_mem_interface_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("kv_mem_interface_tb.sv", 241, "");
        vlSelfRef.kv_mem_interface_tb__DOT__errors 
            = ((IData)(1U) + vlSelfRef.kv_mem_interface_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: kv_mem_interface_tb.sv:244: Assertion failed in %m: [%0t] Test 4: req_ready low after reset\n",4, 'M',vlSymsp->name(),"kv_mem_interface_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("kv_mem_interface_tb.sv", 244, "");
    }
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__rst_n = 1U;
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         248);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_write = 0U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_addr = vlSelfRef.kv_mem_interface_tb__DOT__addr;
    vlSelfRef.kv_mem_interface_tb__DOT__resp_ready = 1U;
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         250);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 0U;
    if (VL_UNLIKELY((((0U != ((((((((vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[0U] 
                                     ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_k[0U]) 
                                    | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[1U] 
                                       ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_k[1U])) 
                                   | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[2U] 
                                      ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_k[2U])) 
                                  | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[3U] 
                                     ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_k[3U])) 
                                 | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[4U] 
                                    ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_k[4U])) 
                                | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[5U] 
                                   ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_k[5U])) 
                               | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[6U] 
                                  ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_k[6U])) 
                              | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[7U] 
                                 ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_k[7U]))) 
                      | (0U != ((((((((vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[0U] 
                                       ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_v[0U]) 
                                      | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[1U] 
                                         ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_v[1U])) 
                                     | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[2U] 
                                        ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_v[2U])) 
                                    | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[3U] 
                                       ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_v[3U])) 
                                   | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[4U] 
                                      ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_v[4U])) 
                                  | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[5U] 
                                     ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_v[5U])) 
                                 | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[6U] 
                                    ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_v[6U])) 
                                | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[7U] 
                                   ^ vlSelfRef.kv_mem_interface_tb__DOT__exp_v[7U]))))))) {
        vlSelfRef.kv_mem_interface_tb__DOT__errors 
            = ((IData)(1U) + vlSelfRef.kv_mem_interface_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: kv_mem_interface_tb.sv:253: Assertion failed in %m: [%0t] Test 4: RAM contents were wiped by reset\n",4, 'M',vlSymsp->name(),"kv_mem_interface_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("kv_mem_interface_tb.sv", 253, "");
    }
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         255);
    if ((vlSelfRef.kv_mem_interface_tb__DOT__test_errors 
         == vlSelfRef.kv_mem_interface_tb__DOT__errors)) {
        VL_WRITEF_NX("Test 4 (reset clears control, keeps RAM)\n",0);
    } else {
        VL_WRITEF_NX("Test 4 failed.\n",0);
    }
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__resp_ready = 0U;
    VL_FINISH_MT("kv_mem_interface_tb.sv", 262, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_return;
}

bool Vkv_mem_interface_tb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___trigger_anySet__ico\n"); );
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

bool Vkv_mem_interface_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___trigger_anySet__act\n"); );
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

void Vkv_mem_interface_tb___024root___nba_sequent__TOP__0(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___nba_sequent__TOP__0\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<8>/*255:0*/ __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0;
    VL_ZERO_W(256, __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0);
    CData/*7:0*/ __VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0;
    __VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0;
    __VdlySet__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0 = 0;
    VlWide<8>/*255:0*/ __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0;
    VL_ZERO_W(256, __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0);
    CData/*7:0*/ __VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0;
    __VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0;
    __VdlySet__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0 = 0;
    // Body
    __VdlySet__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0 = 0U;
    __VdlySet__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0 = 0U;
    if (vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__wr_en) {
        __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0[0U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[0U];
        __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0[1U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[1U];
        __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0[2U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[2U];
        __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0[3U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[3U];
        __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0[4U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[4U];
        __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0[5U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[5U];
        __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0[6U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[6U];
        __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0[7U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_data_v[7U];
        __VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_addr;
        __VdlySet__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0 = 1U;
        __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0[0U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[0U];
        __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0[1U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[1U];
        __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0[2U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[2U];
        __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0[3U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[3U];
        __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0[4U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[4U];
        __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0[5U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[5U];
        __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0[6U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[6U];
        __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0[7U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_data_k[7U];
        __VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0 
            = vlSelfRef.kv_mem_interface_tb__DOT__req_addr;
        __VdlySet__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0 = 1U;
    }
    if (vlSelfRef.kv_mem_interface_tb__DOT__rst_n) {
        if (vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state) {
            if (vlSelfRef.kv_mem_interface_tb__DOT__resp_ready) {
                vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state = 0U;
            }
        } else if (vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__rd_en) {
            vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state = 1U;
        }
    } else {
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state = 0U;
    }
    if (vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__rd_en) {
        vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[0U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem
            [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][0U];
        vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[1U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem
            [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][1U];
        vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[2U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem
            [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][2U];
        vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[3U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem
            [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][3U];
        vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[4U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem
            [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][4U];
        vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[5U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem
            [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][5U];
        vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[6U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem
            [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][6U];
        vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[7U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem
            [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][7U];
        vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[0U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem
            [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][0U];
        vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[1U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem
            [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][1U];
        vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[2U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem
            [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][2U];
        vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[3U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem
            [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][3U];
        vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[4U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem
            [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][4U];
        vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[5U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem
            [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][5U];
        vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[6U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem
            [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][6U];
        vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[7U] 
            = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem
            [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][7U];
    }
    if (__VdlySet__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0) {
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[__VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0][0U] 
            = __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0[0U];
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[__VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0][1U] 
            = __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0[1U];
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[__VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0][2U] 
            = __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0[2U];
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[__VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0][3U] 
            = __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0[3U];
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[__VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0][4U] 
            = __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0[4U];
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[__VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0][5U] 
            = __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0[5U];
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[__VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0][6U] 
            = __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0[6U];
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[__VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0][7U] 
            = __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem__v0[7U];
    }
    if (__VdlySet__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0) {
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[__VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0][0U] 
            = __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0[0U];
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[__VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0][1U] 
            = __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0[1U];
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[__VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0][2U] 
            = __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0[2U];
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[__VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0][3U] 
            = __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0[3U];
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[__VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0][4U] 
            = __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0[4U];
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[__VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0][5U] 
            = __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0[5U];
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[__VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0][6U] 
            = __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0[6U];
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[__VdlyDim0__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0][7U] 
            = __VdlyVal__kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem__v0[7U];
    }
}

void Vkv_mem_interface_tb___024root___timing_ready(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___timing_ready\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_hc199cafc__0.ready("@(negedge kv_mem_interface_tb.clk)");
    }
}

void Vkv_mem_interface_tb___024root___timing_resume(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___timing_resume\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_hc199cafc__0.moveToResumeQueue(
                                                          "@(negedge kv_mem_interface_tb.clk)");
    vlSelfRef.__VtrigSched_hc199cafc__0.resume("@(negedge kv_mem_interface_tb.clk)");
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vkv_mem_interface_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vkv_mem_interface_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(Vkv_mem_interface_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)((((~ (IData)(vlSelfRef.kv_mem_interface_tb__DOT__clk)) 
                                   & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__kv_mem_interface_tb__DOT__clk__0)) 
                                  << 2U)));
    vlSelfRef.__Vtrigprevexpr___TOP__kv_mem_interface_tb__DOT__clk__0 
        = vlSelfRef.kv_mem_interface_tb__DOT__clk;
    if ((4ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc199cafc__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vkv_mem_interface_tb___024root___eval_debug_assertions(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_debug_assertions\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
