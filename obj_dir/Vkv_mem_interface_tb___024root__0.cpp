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
                                                         81);
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
                                                         88);
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
                                                         92);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 0U;
    Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                               "@(negedge kv_mem_interface_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge kv_mem_interface_tb.clk)", 
                                                         "kv_mem_interface_tb.sv", 
                                                         95);
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
                                                         98);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 0U;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state)))))) {
        vlSelfRef.kv_mem_interface_tb__DOT__errors 
            = ((IData)(1U) + vlSelfRef.kv_mem_interface_tb__DOT__errors);
        VL_WRITEF_NX("[%0t] %%Error: kv_mem_interface_tb.sv:102: Assertion failed in %m: [%0t] resp_valid not high after read\n",4, 'M',vlSymsp->name(),"kv_mem_interface_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("kv_mem_interface_tb.sv", 102, "");
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
        VL_WRITEF_NX("[%0t] %%Error: kv_mem_interface_tb.sv:107: Assertion failed in %m: [%0t]: full write/read cycle failed on Key data. Expected = %0d, got = %0d\n",6, 'M',vlSymsp->name(),"kv_mem_interface_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',256,vlSelfRef.kv_mem_interface_tb__DOT__req_data_k.data()
                     , '#',256,vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k.data());
        VL_STOP_MT("kv_mem_interface_tb.sv", 107, "");
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
        VL_WRITEF_NX("[%0t] %%Error: kv_mem_interface_tb.sv:112: Assertion failed in %m: [%0t]: full write/read cycle failed on Value data. Expected = %0d, got = %0d\n",6, 'M',vlSymsp->name(),"kv_mem_interface_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',256,vlSelfRef.kv_mem_interface_tb__DOT__req_data_v.data()
                     , '#',256,vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v.data());
        VL_STOP_MT("kv_mem_interface_tb.sv", 112, "");
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
                                                         125);
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
                                                         131);
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
                                                             136);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.kv_mem_interface_tb__DOT__req_valid = 0U;
        Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                                   "@(negedge kv_mem_interface_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge kv_mem_interface_tb.clk)", 
                                                             "kv_mem_interface_tb.sv", 
                                                             139);
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
                                                             146);
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
            VL_WRITEF_NX("[%0t] K data mismatch. Expected = %0d, got = %0d, on iteration %0d\n",5, 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',256,__Vtemp_2.data()
                         , '#',256,vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k.data()
                         , '~',32,kv_mem_interface_tb__DOT__unnamedblk4__DOT__i);
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
            VL_WRITEF_NX("[%0t] V data mismatch. Expected = %0d, got = %0d, on iteration %0d\n",5, 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',256,__Vtemp_4.data()
                         , '#',256,vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v.data()
                         , '~',32,kv_mem_interface_tb__DOT__unnamedblk4__DOT__i);
        }
        Vkv_mem_interface_tb___024root____VbeforeTrig_hc199cafc__0(vlSelf, 
                                                                   "@(negedge kv_mem_interface_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hc199cafc__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge kv_mem_interface_tb.clk)", 
                                                             "kv_mem_interface_tb.sv", 
                                                             156);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        kv_mem_interface_tb__DOT__unnamedblk4__DOT__i 
            = ((IData)(1U) + kv_mem_interface_tb__DOT__unnamedblk4__DOT__i);
    }
    if ((vlSelfRef.kv_mem_interface_tb__DOT__test_errors 
         == vlSelfRef.kv_mem_interface_tb__DOT__errors)) {
        VL_WRITEF_NX("Test 2 passed. Multiple read after write cycles.\n",0);
    } else {
        VL_WRITEF_NX("Test 2 failed.\n",0);
    }
    VL_FINISH_MT("kv_mem_interface_tb.sv", 165, "");
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

extern const VlWide<8>/*255:0*/ Vkv_mem_interface_tb__ConstPool__CONST_h5b979007_0;

void Vkv_mem_interface_tb___024root___nba_sequent__TOP__0(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___nba_sequent__TOP__0\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<8>/*255:0*/ __Vdly__kv_mem_interface_tb__DOT__resp_data_v;
    VL_ZERO_W(256, __Vdly__kv_mem_interface_tb__DOT__resp_data_v);
    VlWide<8>/*255:0*/ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v;
    VL_ZERO_W(256, __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v);
    VlWide<8>/*255:0*/ __Vdly__kv_mem_interface_tb__DOT__resp_data_k;
    VL_ZERO_W(256, __Vdly__kv_mem_interface_tb__DOT__resp_data_k);
    VlWide<8>/*255:0*/ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k;
    VL_ZERO_W(256, __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k);
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
    if ((1U & (~ (IData)(vlSelfRef.kv_mem_interface_tb__DOT__rst_n)))) {
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
    }
    if (vlSelfRef.kv_mem_interface_tb__DOT__rst_n) {
        if (vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__rd_en) {
            __Vdly__kv_mem_interface_tb__DOT__resp_data_v[0U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem
                [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][0U];
            __Vdly__kv_mem_interface_tb__DOT__resp_data_v[1U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem
                [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][1U];
            __Vdly__kv_mem_interface_tb__DOT__resp_data_v[2U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem
                [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][2U];
            __Vdly__kv_mem_interface_tb__DOT__resp_data_v[3U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem
                [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][3U];
            __Vdly__kv_mem_interface_tb__DOT__resp_data_v[4U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem
                [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][4U];
            __Vdly__kv_mem_interface_tb__DOT__resp_data_v[5U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem
                [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][5U];
            __Vdly__kv_mem_interface_tb__DOT__resp_data_v[6U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem
                [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][6U];
            __Vdly__kv_mem_interface_tb__DOT__resp_data_v[7U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem
                [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][7U];
            VL_ASSIGN_W(256, __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v, Vkv_mem_interface_tb__ConstPool__CONST_h5b979007_0);
            __Vdly__kv_mem_interface_tb__DOT__resp_data_k[0U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem
                [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][0U];
            __Vdly__kv_mem_interface_tb__DOT__resp_data_k[1U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem
                [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][1U];
            __Vdly__kv_mem_interface_tb__DOT__resp_data_k[2U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem
                [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][2U];
            __Vdly__kv_mem_interface_tb__DOT__resp_data_k[3U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem
                [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][3U];
            __Vdly__kv_mem_interface_tb__DOT__resp_data_k[4U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem
                [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][4U];
            __Vdly__kv_mem_interface_tb__DOT__resp_data_k[5U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem
                [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][5U];
            __Vdly__kv_mem_interface_tb__DOT__resp_data_k[6U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem
                [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][6U];
            __Vdly__kv_mem_interface_tb__DOT__resp_data_k[7U] 
                = vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem
                [vlSelfRef.kv_mem_interface_tb__DOT__req_addr][7U];
            VL_ASSIGN_W(256, __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k, Vkv_mem_interface_tb__ConstPool__CONST_h5b979007_0);
        }
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
        if (vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state) {
            if (vlSelfRef.kv_mem_interface_tb__DOT__resp_ready) {
                vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state = 0U;
            }
        } else if (vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__rd_en) {
            vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state = 1U;
        }
    } else {
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[255U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[254U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[253U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[252U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[251U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[250U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[249U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[248U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[247U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[246U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[245U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[244U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[243U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[242U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[241U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[240U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[239U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[238U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[237U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[236U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[235U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[234U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[233U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[232U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[231U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[230U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[229U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[228U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[227U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[226U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[225U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[224U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[223U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[222U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[221U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[220U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[219U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[218U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[217U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[216U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[215U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[214U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[213U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[212U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[211U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[210U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[209U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[208U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[207U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[206U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[205U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[204U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[203U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[202U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[201U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[200U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[199U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[198U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[197U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[196U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[195U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[194U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[193U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[192U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[191U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[190U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[189U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[188U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[187U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[186U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[185U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[184U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[183U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[182U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[181U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[180U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[179U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[178U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[177U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[176U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[175U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[174U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[173U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[172U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[171U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[170U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[169U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[168U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[167U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[166U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[165U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[164U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[163U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[162U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[161U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[160U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[159U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[158U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[157U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[156U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[155U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[154U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[153U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[152U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[151U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[150U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[149U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[148U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[147U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[146U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[145U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[144U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[143U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[142U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[141U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[140U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[139U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[138U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[137U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[136U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[135U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[134U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[133U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[132U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[131U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[130U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[129U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[128U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[127U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[126U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[125U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[124U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[123U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[122U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[121U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[120U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[119U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[118U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[117U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[116U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[115U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[114U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[113U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[112U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[111U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[110U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[109U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[108U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[107U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[106U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[105U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[104U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[103U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[102U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[101U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[100U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[99U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[98U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[97U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[96U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[95U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[94U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[93U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[92U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[91U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[90U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[89U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[88U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[87U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[86U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[85U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[84U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[83U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[82U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[81U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[80U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[79U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[78U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[77U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[76U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[75U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[74U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[73U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[72U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[71U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[70U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[69U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[68U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[67U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[66U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[65U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[64U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[63U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[62U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[61U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[60U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[59U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[58U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[57U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[56U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[55U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[54U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[53U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[52U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[51U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[50U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[49U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[48U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[47U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[46U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[45U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[44U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[43U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[42U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[41U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[40U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[39U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[38U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[37U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[36U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[35U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[34U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[33U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[32U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[31U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[30U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[29U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[28U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[27U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[26U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[25U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[24U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[23U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[22U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[21U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[20U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[19U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[18U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[17U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[16U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[15U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[14U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[13U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[12U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[11U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[10U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[9U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[8U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[7U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[6U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[5U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[4U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[3U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[2U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[1U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[0U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[255U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[254U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[253U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[252U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[251U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[250U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[249U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[248U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[247U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[246U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[245U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[244U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[243U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[242U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[241U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[240U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[239U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[238U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[237U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[236U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[235U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[234U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[233U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[232U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[231U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[230U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[229U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[228U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[227U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[226U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[225U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[224U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[223U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[222U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[221U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[220U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[219U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[218U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[217U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[216U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[215U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[214U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[213U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[212U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[211U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[210U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[209U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[208U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[207U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[206U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[205U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[204U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[203U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[202U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[201U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[200U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[199U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[198U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[197U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[196U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[195U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[194U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[193U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[192U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[191U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[190U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[189U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[188U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[187U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[186U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[185U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[184U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[183U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[182U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[181U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[180U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[179U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[178U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[177U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[176U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[175U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[174U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[173U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[172U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[171U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[170U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[169U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[168U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[167U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[166U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[165U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[164U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[163U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[162U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[161U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[160U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[159U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[158U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[157U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[156U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[155U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[154U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[153U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[152U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[151U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[150U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[149U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[148U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[147U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[146U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[145U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[144U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[143U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[142U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[141U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[140U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[139U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[138U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[137U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[136U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[135U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[134U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[133U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[132U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[131U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[130U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[129U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[128U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[127U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[126U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[125U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[124U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[123U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[122U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[121U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[120U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[119U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[118U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[117U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[116U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[115U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[114U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[113U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[112U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[111U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[110U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[109U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[108U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[107U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[106U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[105U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[104U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[103U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[102U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[101U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[100U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[99U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[98U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[97U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[96U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[95U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[94U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[93U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[92U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[91U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[90U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[89U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[88U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[87U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[86U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[85U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[84U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[83U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[82U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[81U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[80U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[79U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[78U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[77U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[76U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[75U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[74U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[73U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[72U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[71U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[70U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[69U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[68U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[67U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[66U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[65U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[64U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[63U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[62U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[61U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[60U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[59U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[58U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[57U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[56U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[55U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[54U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[53U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[52U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[51U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[50U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[49U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[48U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[47U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[46U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[45U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[44U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[43U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[42U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[41U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[40U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[39U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[38U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[37U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[36U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[35U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[34U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[33U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[32U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[31U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[30U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[29U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[28U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[27U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[26U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[25U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[24U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[23U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[22U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[21U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[20U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[19U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[18U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[17U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[16U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[15U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[14U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[13U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[12U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[11U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[10U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[9U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[8U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[7U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[6U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[5U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[4U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[3U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[2U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[1U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        VL_ASSIGN_W(256, vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[0U], Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
        vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state = 0U;
    }
    vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[0U] 
        = ((__Vdly__kv_mem_interface_tb__DOT__resp_data_v[0U] 
            & __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v[0U]) 
           | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[0U] 
              & (~ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v[0U])));
    vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[1U] 
        = ((__Vdly__kv_mem_interface_tb__DOT__resp_data_v[1U] 
            & __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v[1U]) 
           | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[1U] 
              & (~ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v[1U])));
    vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[2U] 
        = ((__Vdly__kv_mem_interface_tb__DOT__resp_data_v[2U] 
            & __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v[2U]) 
           | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[2U] 
              & (~ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v[2U])));
    vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[3U] 
        = ((__Vdly__kv_mem_interface_tb__DOT__resp_data_v[3U] 
            & __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v[3U]) 
           | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[3U] 
              & (~ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v[3U])));
    vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[4U] 
        = ((__Vdly__kv_mem_interface_tb__DOT__resp_data_v[4U] 
            & __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v[4U]) 
           | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[4U] 
              & (~ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v[4U])));
    vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[5U] 
        = ((__Vdly__kv_mem_interface_tb__DOT__resp_data_v[5U] 
            & __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v[5U]) 
           | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[5U] 
              & (~ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v[5U])));
    vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[6U] 
        = ((__Vdly__kv_mem_interface_tb__DOT__resp_data_v[6U] 
            & __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v[6U]) 
           | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[6U] 
              & (~ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v[6U])));
    vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[7U] 
        = ((__Vdly__kv_mem_interface_tb__DOT__resp_data_v[7U] 
            & __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v[7U]) 
           | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v[7U] 
              & (~ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v[7U])));
    VL_ASSIGN_W(256, __VdlyMask__kv_mem_interface_tb__DOT__resp_data_v, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
    vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[0U] 
        = ((__Vdly__kv_mem_interface_tb__DOT__resp_data_k[0U] 
            & __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k[0U]) 
           | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[0U] 
              & (~ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k[0U])));
    vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[1U] 
        = ((__Vdly__kv_mem_interface_tb__DOT__resp_data_k[1U] 
            & __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k[1U]) 
           | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[1U] 
              & (~ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k[1U])));
    vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[2U] 
        = ((__Vdly__kv_mem_interface_tb__DOT__resp_data_k[2U] 
            & __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k[2U]) 
           | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[2U] 
              & (~ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k[2U])));
    vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[3U] 
        = ((__Vdly__kv_mem_interface_tb__DOT__resp_data_k[3U] 
            & __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k[3U]) 
           | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[3U] 
              & (~ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k[3U])));
    vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[4U] 
        = ((__Vdly__kv_mem_interface_tb__DOT__resp_data_k[4U] 
            & __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k[4U]) 
           | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[4U] 
              & (~ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k[4U])));
    vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[5U] 
        = ((__Vdly__kv_mem_interface_tb__DOT__resp_data_k[5U] 
            & __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k[5U]) 
           | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[5U] 
              & (~ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k[5U])));
    vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[6U] 
        = ((__Vdly__kv_mem_interface_tb__DOT__resp_data_k[6U] 
            & __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k[6U]) 
           | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[6U] 
              & (~ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k[6U])));
    vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[7U] 
        = ((__Vdly__kv_mem_interface_tb__DOT__resp_data_k[7U] 
            & __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k[7U]) 
           | (vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k[7U] 
              & (~ __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k[7U])));
    VL_ASSIGN_W(256, __VdlyMask__kv_mem_interface_tb__DOT__resp_data_k, Vkv_mem_interface_tb__ConstPool__CONST_h9e67c271_0);
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
