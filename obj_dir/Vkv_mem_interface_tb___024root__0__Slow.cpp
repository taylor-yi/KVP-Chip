// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkv_mem_interface_tb.h for the primary calling header

#include "Vkv_mem_interface_tb__pch.h"

void Vkv_mem_interface_tb___024root___timing_ready(Vkv_mem_interface_tb___024root* vlSelf);

VL_ATTR_COLD void Vkv_mem_interface_tb___024root___eval_static(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_static\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_static__TOP
        vlSelfRef.kv_mem_interface_tb__DOT__errors = 0U;
    }
    vlSelfRef.__Vtrigprevexpr___TOP__kv_mem_interface_tb__DOT__clk__0 
        = vlSelfRef.kv_mem_interface_tb__DOT__clk;
    Vkv_mem_interface_tb___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkv_mem_interface_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vkv_mem_interface_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

VL_ATTR_COLD bool Vkv_mem_interface_tb___024root___eval_stl(Vkv_mem_interface_tb___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_stl\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vkv_mem_interface_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vkv_mem_interface_tb___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
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
    return (__VstlExecute);
}

VL_ATTR_COLD void Vkv_mem_interface_tb___024root___eval_dump_triggers__stl(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_dump_triggers__stl\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vkv_mem_interface_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkv_mem_interface_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vkv_mem_interface_tb___024root___eval_dump_triggers__ico(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_dump_triggers__ico\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vkv_mem_interface_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkv_mem_interface_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vkv_mem_interface_tb___024root___eval_dump_triggers__act(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_dump_triggers__act\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vkv_mem_interface_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vkv_mem_interface_tb___024root___eval_dump_triggers__nba(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_dump_triggers__nba\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vkv_mem_interface_tb___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vkv_mem_interface_tb___024root___eval_dump_triggers__obs(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_dump_triggers__obs\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vkv_mem_interface_tb___024root___eval_dump_triggers__react(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_dump_triggers__react\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vkv_mem_interface_tb___024root___eval_final(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___eval_final\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkv_mem_interface_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vkv_mem_interface_tb___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vkv_mem_interface_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___trigger_anySet__stl\n"); );
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

bool Vkv_mem_interface_tb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkv_mem_interface_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vkv_mem_interface_tb___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vkv_mem_interface_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkv_mem_interface_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vkv_mem_interface_tb___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge kv_mem_interface_tb.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(negedge kv_mem_interface_tb.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vkv_mem_interface_tb___024root___ctor_var_reset(Vkv_mem_interface_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root___ctor_var_reset\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->kv_mem_interface_tb__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8684243253785761780ull);
    vlSelf->kv_mem_interface_tb__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4380592259369114576ull);
    vlSelf->kv_mem_interface_tb__DOT__req_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9149228941607643079ull);
    vlSelf->kv_mem_interface_tb__DOT__req_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9760646350670189399ull);
    vlSelf->kv_mem_interface_tb__DOT__req_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11579916480341227131ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->kv_mem_interface_tb__DOT__req_data_k, __VscopeHash, 2648368350492650500ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->kv_mem_interface_tb__DOT__req_data_v, __VscopeHash, 3191989413332769243ull);
    vlSelf->kv_mem_interface_tb__DOT__resp_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17273209386739189610ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->kv_mem_interface_tb__DOT__resp_data_k, __VscopeHash, 8212432846406311901ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->kv_mem_interface_tb__DOT__resp_data_v, __VscopeHash, 7640361632824823143ull);
    vlSelf->kv_mem_interface_tb__DOT__test_errors = 0;
    VL_SCOPED_RAND_RESET_W(256, vlSelf->kv_mem_interface_tb__DOT__exp_k, __VscopeHash, 7934583087904091413ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->kv_mem_interface_tb__DOT__exp_v, __VscopeHash, 12950087589720664232ull);
    vlSelf->kv_mem_interface_tb__DOT__addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6897274330746289822ull);
    vlSelf->kv_mem_interface_tb__DOT__addresses = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 1008297962344938659ull);
    VL_SCOPED_RAND_RESET_W(768, vlSelf->kv_mem_interface_tb__DOT__exp_k_array, __VscopeHash, 10902717652176659033ull);
    VL_SCOPED_RAND_RESET_W(768, vlSelf->kv_mem_interface_tb__DOT__exp_v_array, __VscopeHash, 15987646295757823459ull);
    vlSelf->kv_mem_interface_tb__DOT__dut__DOT__read_state = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4567396765519871659ull);
    vlSelf->kv_mem_interface_tb__DOT__dut__DOT__accept = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8109268569330666348ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(256, vlSelf->kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem[__Vi0], __VscopeHash, 17591735668180095443ull);
    }
    vlSelf->kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10670656705406250155ull);
    vlSelf->kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__rd_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9894448865033354083ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(256, vlSelf->kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem[__Vi0], __VscopeHash, 12431998832173657647ull);
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
    vlSelf->__Vtrigprevexpr___TOP__kv_mem_interface_tb__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
