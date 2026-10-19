// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkv_block_ram_tb.h for the primary calling header

#include "Vkv_block_ram_tb__pch.h"

VlCoroutine Vkv_block_ram_tb___024root___eval_initial__TOP__Vtiming__0(Vkv_block_ram_tb___024root* vlSelf);
VlCoroutine Vkv_block_ram_tb___024root___eval_initial__TOP__Vtiming__1(Vkv_block_ram_tb___024root* vlSelf);

void Vkv_block_ram_tb___024root___eval_initial(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_initial\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        vlSymsp->_vm_contextp__->dumpfile("dump.vcd"s);
        vlSymsp->_traceDumpOpen();
    }
    Vkv_block_ram_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vkv_block_ram_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vkv_block_ram_tb___024root___eval_sample(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_sample\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkv_block_ram_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vkv_block_ram_tb___024root___eval_ico(Vkv_block_ram_tb___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_ico\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vkv_block_ram_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

void Vkv_block_ram_tb___024root___timing_ready(Vkv_block_ram_tb___024root* vlSelf);
void Vkv_block_ram_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vkv_block_ram_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vkv_block_ram_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vkv_block_ram_tb___024root___timing_resume(Vkv_block_ram_tb___024root* vlSelf);

bool Vkv_block_ram_tb___024root___eval_act(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_act\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                          << 1U) 
                                                         | ((IData)(vlSelfRef.kv_block_ram_tb__DOT__clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__kv_block_ram_tb__DOT__clk__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__kv_block_ram_tb__DOT__clk__0 
            = vlSelfRef.kv_block_ram_tb__DOT__clk;
    }
    Vkv_block_ram_tb___024root___timing_ready(vlSelf);
    Vkv_block_ram_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vkv_block_ram_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vkv_block_ram_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vkv_block_ram_tb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vkv_block_ram_tb___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vkv_block_ram_tb___024root___eval_inact(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_inact\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("kv_block_ram.sv", 26, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vkv_block_ram_tb___024root___nba_sequent__TOP__0(Vkv_block_ram_tb___024root* vlSelf);
void Vkv_block_ram_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vkv_block_ram_tb___024root___eval_nba(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_nba\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vkv_block_ram_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vkv_block_ram_tb___024root___nba_sequent__TOP__0(vlSelf);
                vlSelfRef.__Vm_traceActivity[1U] = 1U;
            }
        }
        Vkv_block_ram_tb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vkv_block_ram_tb___024root___eval_obs(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_obs\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vkv_block_ram_tb___024root___eval_react(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_react\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vkv_block_ram_tb___024root___eval_postponed(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_postponed\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VlCoroutine Vkv_block_ram_tb___024root___eval_initial__TOP__Vtiming__0(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.kv_block_ram_tb__DOT__clk = 0U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "kv_block_ram.sv", 
                                             35);
        vlSelfRef.kv_block_ram_tb__DOT__clk = (1U & 
                                               (~ (IData)(vlSelfRef.kv_block_ram_tb__DOT__clk)));
    }
    co_return;
}

void Vkv_block_ram_tb___024root____VbeforeTrig_hb691101e__0(Vkv_block_ram_tb___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vkv_block_ram_tb___024root___eval_initial__TOP__Vtiming__1(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ kv_block_ram_tb__DOT__unnamedblk1_1__DOT____Vrepeat0;
    kv_block_ram_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    // Body
    kv_block_ram_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0x00000064U;
    while (VL_LTS_III(32, 0U, kv_block_ram_tb__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vkv_block_ram_tb___024root____VbeforeTrig_hb691101e__0(vlSelf, 
                                                               "@(posedge kv_block_ram_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hb691101e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge kv_block_ram_tb.clk)", 
                                                             "kv_block_ram.sv", 
                                                             45);
        kv_block_ram_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (kv_block_ram_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    VL_FINISH_MT("kv_block_ram.sv", 46, "");
    co_return;
}

bool Vkv_block_ram_tb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___trigger_anySet__ico\n"); );
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

bool Vkv_block_ram_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___trigger_anySet__act\n"); );
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

void Vkv_block_ram_tb___024root___nba_sequent__TOP__0(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___nba_sequent__TOP__0\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<8>/*255:0*/ __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0;
    VL_ZERO_W(256, __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0);
    CData/*7:0*/ __VdlyDim0__kv_block_ram_tb__DOT__dut__DOT__mem__v0;
    __VdlyDim0__kv_block_ram_tb__DOT__dut__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__kv_block_ram_tb__DOT__dut__DOT__mem__v0;
    __VdlySet__kv_block_ram_tb__DOT__dut__DOT__mem__v0 = 0;
    // Body
    __VdlySet__kv_block_ram_tb__DOT__dut__DOT__mem__v0 = 0U;
    if (vlSelfRef.kv_block_ram_tb__DOT__wr_en) {
        __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0[0U] 
            = vlSelfRef.kv_block_ram_tb__DOT__wr_data[0U];
        __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0[1U] 
            = vlSelfRef.kv_block_ram_tb__DOT__wr_data[1U];
        __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0[2U] 
            = vlSelfRef.kv_block_ram_tb__DOT__wr_data[2U];
        __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0[3U] 
            = vlSelfRef.kv_block_ram_tb__DOT__wr_data[3U];
        __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0[4U] 
            = vlSelfRef.kv_block_ram_tb__DOT__wr_data[4U];
        __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0[5U] 
            = vlSelfRef.kv_block_ram_tb__DOT__wr_data[5U];
        __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0[6U] 
            = vlSelfRef.kv_block_ram_tb__DOT__wr_data[6U];
        __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0[7U] 
            = vlSelfRef.kv_block_ram_tb__DOT__wr_data[7U];
        __VdlyDim0__kv_block_ram_tb__DOT__dut__DOT__mem__v0 
            = vlSelfRef.kv_block_ram_tb__DOT__wr_addr;
        __VdlySet__kv_block_ram_tb__DOT__dut__DOT__mem__v0 = 1U;
        vlSelfRef.kv_block_ram_tb__DOT__rd_data[0U] 
            = vlSelfRef.kv_block_ram_tb__DOT__dut__DOT__mem
            [vlSelfRef.kv_block_ram_tb__DOT__rd_addr][0U];
        vlSelfRef.kv_block_ram_tb__DOT__rd_data[1U] 
            = vlSelfRef.kv_block_ram_tb__DOT__dut__DOT__mem
            [vlSelfRef.kv_block_ram_tb__DOT__rd_addr][1U];
        vlSelfRef.kv_block_ram_tb__DOT__rd_data[2U] 
            = vlSelfRef.kv_block_ram_tb__DOT__dut__DOT__mem
            [vlSelfRef.kv_block_ram_tb__DOT__rd_addr][2U];
        vlSelfRef.kv_block_ram_tb__DOT__rd_data[3U] 
            = vlSelfRef.kv_block_ram_tb__DOT__dut__DOT__mem
            [vlSelfRef.kv_block_ram_tb__DOT__rd_addr][3U];
        vlSelfRef.kv_block_ram_tb__DOT__rd_data[4U] 
            = vlSelfRef.kv_block_ram_tb__DOT__dut__DOT__mem
            [vlSelfRef.kv_block_ram_tb__DOT__rd_addr][4U];
        vlSelfRef.kv_block_ram_tb__DOT__rd_data[5U] 
            = vlSelfRef.kv_block_ram_tb__DOT__dut__DOT__mem
            [vlSelfRef.kv_block_ram_tb__DOT__rd_addr][5U];
        vlSelfRef.kv_block_ram_tb__DOT__rd_data[6U] 
            = vlSelfRef.kv_block_ram_tb__DOT__dut__DOT__mem
            [vlSelfRef.kv_block_ram_tb__DOT__rd_addr][6U];
        vlSelfRef.kv_block_ram_tb__DOT__rd_data[7U] 
            = vlSelfRef.kv_block_ram_tb__DOT__dut__DOT__mem
            [vlSelfRef.kv_block_ram_tb__DOT__rd_addr][7U];
    }
    if (__VdlySet__kv_block_ram_tb__DOT__dut__DOT__mem__v0) {
        vlSelfRef.kv_block_ram_tb__DOT__dut__DOT__mem[__VdlyDim0__kv_block_ram_tb__DOT__dut__DOT__mem__v0][0U] 
            = __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0[0U];
        vlSelfRef.kv_block_ram_tb__DOT__dut__DOT__mem[__VdlyDim0__kv_block_ram_tb__DOT__dut__DOT__mem__v0][1U] 
            = __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0[1U];
        vlSelfRef.kv_block_ram_tb__DOT__dut__DOT__mem[__VdlyDim0__kv_block_ram_tb__DOT__dut__DOT__mem__v0][2U] 
            = __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0[2U];
        vlSelfRef.kv_block_ram_tb__DOT__dut__DOT__mem[__VdlyDim0__kv_block_ram_tb__DOT__dut__DOT__mem__v0][3U] 
            = __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0[3U];
        vlSelfRef.kv_block_ram_tb__DOT__dut__DOT__mem[__VdlyDim0__kv_block_ram_tb__DOT__dut__DOT__mem__v0][4U] 
            = __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0[4U];
        vlSelfRef.kv_block_ram_tb__DOT__dut__DOT__mem[__VdlyDim0__kv_block_ram_tb__DOT__dut__DOT__mem__v0][5U] 
            = __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0[5U];
        vlSelfRef.kv_block_ram_tb__DOT__dut__DOT__mem[__VdlyDim0__kv_block_ram_tb__DOT__dut__DOT__mem__v0][6U] 
            = __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0[6U];
        vlSelfRef.kv_block_ram_tb__DOT__dut__DOT__mem[__VdlyDim0__kv_block_ram_tb__DOT__dut__DOT__mem__v0][7U] 
            = __VdlyVal__kv_block_ram_tb__DOT__dut__DOT__mem__v0[7U];
    }
}

void Vkv_block_ram_tb___024root___timing_ready(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___timing_ready\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_hb691101e__0.ready("@(posedge kv_block_ram_tb.clk)");
    }
}

void Vkv_block_ram_tb___024root___timing_resume(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___timing_resume\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_hb691101e__0.moveToResumeQueue(
                                                          "@(posedge kv_block_ram_tb.clk)");
    vlSelfRef.__VtrigSched_hb691101e__0.resume("@(posedge kv_block_ram_tb.clk)");
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vkv_block_ram_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vkv_block_ram_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vkv_block_ram_tb___024root____VbeforeTrig_hb691101e__0(Vkv_block_ram_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root____VbeforeTrig_hb691101e__0\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((IData)(vlSelfRef.kv_block_ram_tb__DOT__clk) 
                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__kv_block_ram_tb__DOT__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__kv_block_ram_tb__DOT__clk__0 
        = vlSelfRef.kv_block_ram_tb__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_hb691101e__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vkv_block_ram_tb___024root___eval_debug_assertions(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_debug_assertions\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
