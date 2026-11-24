// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpage_allocator_tb.h for the primary calling header

#include "Vpage_allocator_tb__pch.h"

void Vpage_allocator_tb___024root___timing_ready(Vpage_allocator_tb___024root* vlSelf);

VL_ATTR_COLD void Vpage_allocator_tb___024root___eval_static(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_static\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_static__TOP
        vlSelfRef.page_allocator_tb__DOT__checks = 0U;
        vlSelfRef.page_allocator_tb__DOT__errors = 0U;
    }
    vlSelfRef.__Vtrigprevexpr___TOP__page_allocator_tb__DOT__clk__0 
        = vlSelfRef.page_allocator_tb__DOT__clk;
    Vpage_allocator_tb___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpage_allocator_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vpage_allocator_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);
VL_ATTR_COLD void Vpage_allocator_tb___024root___stl_sequent__TOP__0(Vpage_allocator_tb___024root* vlSelf);

VL_ATTR_COLD bool Vpage_allocator_tb___024root___eval_stl(Vpage_allocator_tb___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_stl\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vpage_allocator_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vpage_allocator_tb___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vpage_allocator_tb___024root___stl_sequent__TOP__0(vlSelf);
                {
                    // Inlined CFunc: __Vm_traceActivitySetAll
                    vlSelfRef.__Vm_traceActivity[0U] = 1U;
                    vlSelfRef.__Vm_traceActivity[1U] = 1U;
                    vlSelfRef.__Vm_traceActivity[2U] = 1U;
                    vlSelfRef.__Vm_traceActivity[3U] = 1U;
                }
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vpage_allocator_tb___024root___eval_dump_triggers__stl(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_dump_triggers__stl\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vpage_allocator_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpage_allocator_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vpage_allocator_tb___024root___eval_dump_triggers__ico(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_dump_triggers__ico\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vpage_allocator_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpage_allocator_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vpage_allocator_tb___024root___eval_dump_triggers__act(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_dump_triggers__act\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vpage_allocator_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vpage_allocator_tb___024root___eval_dump_triggers__nba(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_dump_triggers__nba\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vpage_allocator_tb___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vpage_allocator_tb___024root___eval_dump_triggers__obs(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_dump_triggers__obs\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vpage_allocator_tb___024root___eval_dump_triggers__react(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_dump_triggers__react\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vpage_allocator_tb___024root___eval_final(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___eval_final\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpage_allocator_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vpage_allocator_tb___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vpage_allocator_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vpage_allocator_tb___024root___stl_sequent__TOP__0(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___stl_sequent__TOP__0\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.page_allocator_tb__DOT__alloc_ok = ((~ 
                                                   (0x0000ffffU 
                                                    == (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map))) 
                                                  & (IData)(vlSelfRef.page_allocator_tb__DOT__alloc_req));
    vlSelfRef.page_allocator_tb__DOT__alloc_error = 
        ((IData)(vlSelfRef.page_allocator_tb__DOT__alloc_req) 
         & (0x0000ffffU == (IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map)));
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
    vlSelfRef.page_allocator_tb__DOT__free_ok = ((~ 
                                                  ((IData)(vlSelfRef.page_allocator_tb__DOT__dut__DOT__used_map) 
                                                   >> (IData)(vlSelfRef.page_allocator_tb__DOT__free_ppage))) 
                                                 & (IData)(vlSelfRef.page_allocator_tb__DOT__free_en));
}

bool Vpage_allocator_tb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpage_allocator_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vpage_allocator_tb___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vpage_allocator_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpage_allocator_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vpage_allocator_tb___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge page_allocator_tb.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(negedge page_allocator_tb.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vpage_allocator_tb___024root___ctor_var_reset(Vpage_allocator_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpage_allocator_tb___024root___ctor_var_reset\n"); );
    Vpage_allocator_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->page_allocator_tb__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9042611994384411337ull);
    vlSelf->page_allocator_tb__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4427930510198408955ull);
    vlSelf->page_allocator_tb__DOT__free_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8199460115274565872ull);
    vlSelf->page_allocator_tb__DOT__free_ppage = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6055873673953287298ull);
    vlSelf->page_allocator_tb__DOT__alloc_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4278666798806348432ull);
    vlSelf->page_allocator_tb__DOT__alloc_page = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13655309637428967147ull);
    vlSelf->page_allocator_tb__DOT__alloc_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16075184679322796688ull);
    vlSelf->page_allocator_tb__DOT__alloc_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15661052311875036391ull);
    vlSelf->page_allocator_tb__DOT__free_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12567063274732505550ull);
    vlSelf->page_allocator_tb__DOT__test_errors = 0;
    vlSelf->page_allocator_tb__DOT__dut__DOT__used_map = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12067140572811998262ull);
    vlSelf->page_allocator_tb__DOT__dut__DOT__found_flag = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11309020594799264949ull);
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
    vlSelf->__Vtrigprevexpr___TOP__page_allocator_tb__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
