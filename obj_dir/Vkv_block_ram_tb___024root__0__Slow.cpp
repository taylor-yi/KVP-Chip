// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkv_block_ram_tb.h for the primary calling header

#include "Vkv_block_ram_tb__pch.h"

void Vkv_block_ram_tb___024root___timing_ready(Vkv_block_ram_tb___024root* vlSelf);

VL_ATTR_COLD void Vkv_block_ram_tb___024root___eval_static(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_static\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__kv_block_ram_tb__DOT__clk__0 
        = vlSelfRef.kv_block_ram_tb__DOT__clk;
    Vkv_block_ram_tb___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkv_block_ram_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vkv_block_ram_tb___024root___eval_stl(Vkv_block_ram_tb___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_stl\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vkv_block_ram_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    return (0U);
}

VL_ATTR_COLD void Vkv_block_ram_tb___024root___eval_dump_triggers__stl(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_dump_triggers__stl\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vkv_block_ram_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkv_block_ram_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vkv_block_ram_tb___024root___eval_dump_triggers__ico(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_dump_triggers__ico\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vkv_block_ram_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkv_block_ram_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vkv_block_ram_tb___024root___eval_dump_triggers__act(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_dump_triggers__act\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vkv_block_ram_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vkv_block_ram_tb___024root___eval_dump_triggers__nba(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_dump_triggers__nba\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vkv_block_ram_tb___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vkv_block_ram_tb___024root___eval_dump_triggers__obs(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_dump_triggers__obs\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vkv_block_ram_tb___024root___eval_dump_triggers__react(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_dump_triggers__react\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vkv_block_ram_tb___024root___eval_final(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___eval_final\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD bool Vkv_block_ram_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkv_block_ram_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vkv_block_ram_tb___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vkv_block_ram_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___trigger_anySet__stl\n"); );
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

bool Vkv_block_ram_tb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkv_block_ram_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vkv_block_ram_tb___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vkv_block_ram_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkv_block_ram_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vkv_block_ram_tb___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge kv_block_ram_tb.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vkv_block_ram_tb___024root___ctor_var_reset(Vkv_block_ram_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_block_ram_tb___024root___ctor_var_reset\n"); );
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->kv_block_ram_tb__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16673473349287793779ull);
    vlSelf->kv_block_ram_tb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5162035551612220722ull);
    vlSelf->kv_block_ram_tb__DOT__wr_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13971091244414063685ull);
    vlSelf->kv_block_ram_tb__DOT__rd_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11677964417386057534ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->kv_block_ram_tb__DOT__wr_data, __VscopeHash, 10628698921685325590ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->kv_block_ram_tb__DOT__rd_data, __VscopeHash, 3953116101300033930ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(256, vlSelf->kv_block_ram_tb__DOT__dut__DOT__mem[__Vi0], __VscopeHash, 8721679731891651861ull);
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__kv_block_ram_tb__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
