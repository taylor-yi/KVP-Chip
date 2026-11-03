// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vkv_mem_interface_tb__Syms.h"


VL_ATTR_COLD void Vkv_mem_interface_tb___024root__trace_init_sub__TOP__0(Vkv_mem_interface_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root__trace_init_sub__TOP__0\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "kv_mem_interface_tb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+112,0,"WORD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+112,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+113,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+107,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"req_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"req_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"req_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_WIDE(tracep,c+4,0,"req_data_k",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 255,0);
    VL_TRACE_DECL_WIDE(tracep,c+12,0,"req_data_v",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 255,0);
    VL_TRACE_DECL_BIT(tracep,c+20,0,"resp_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+88,0,"resp_data_k",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 255,0);
    VL_TRACE_DECL_WIDE(tracep,c+96,0,"resp_data_v",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 255,0);
    VL_TRACE_DECL_BIT(tracep,c+104,0,"resp_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+105,0,"req_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+114,0,"checks",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+108,0,"errors",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+21,0,"test_errors",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+22,0,"exp_k",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 255,0);
    VL_TRACE_DECL_WIDE(tracep,c+30,0,"exp_v",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 255,0);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+115,0,"INDICES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+39,0,"addresses",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 23,0);
    VL_TRACE_DECL_WIDE(tracep,c+40,0,"exp_k_array",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 767,0);
    VL_TRACE_DECL_WIDE(tracep,c+64,0,"exp_v_array",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 767,0);
    VL_TRACE_PUSH_PREFIX(tracep, "dut", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+112,0,"WORD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+112,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+113,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+107,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"req_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"req_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"req_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_WIDE(tracep,c+4,0,"req_data_k",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 255,0);
    VL_TRACE_DECL_WIDE(tracep,c+12,0,"req_data_v",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 255,0);
    VL_TRACE_DECL_BIT(tracep,c+20,0,"resp_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+88,0,"resp_data_k",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 255,0);
    VL_TRACE_DECL_WIDE(tracep,c+96,0,"resp_data_v",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 255,0);
    VL_TRACE_DECL_BIT(tracep,c+104,0,"resp_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+105,0,"req_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+106,0,"read_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+109,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+110,0,"rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+111,0,"accept",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "k_ram", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+112,0,"WORD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+112,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+113,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+107,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+109,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+110,0,"rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"wr_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_WIDE(tracep,c+4,0,"wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 255,0);
    VL_TRACE_DECL_WIDE(tracep,c+88,0,"rd_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 255,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "v_ram", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+112,0,"WORD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+112,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+113,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+107,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+109,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+110,0,"rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"wr_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_WIDE(tracep,c+12,0,"wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 255,0);
    VL_TRACE_DECL_WIDE(tracep,c+96,0,"rd_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 255,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vkv_mem_interface_tb___024root__trace_init_top(Vkv_mem_interface_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root__trace_init_top\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vkv_mem_interface_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vkv_mem_interface_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vkv_mem_interface_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vkv_mem_interface_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vkv_mem_interface_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vkv_mem_interface_tb___024root__trace_register(Vkv_mem_interface_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root__trace_register\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vkv_mem_interface_tb___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vkv_mem_interface_tb___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vkv_mem_interface_tb___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vkv_mem_interface_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vkv_mem_interface_tb___024root__trace_const_0_sub_0(Vkv_mem_interface_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vkv_mem_interface_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root__trace_const_0\n"); );
    // Body
    Vkv_mem_interface_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkv_mem_interface_tb___024root*>(voidSelf);
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vkv_mem_interface_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vkv_mem_interface_tb___024root__trace_const_0_sub_0(Vkv_mem_interface_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root__trace_const_0_sub_0\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+112,(0x00000100U),32);
    bufp->fullIData(oldp+113,(8U),32);
    bufp->fullIData(oldp+114,(0U),32);
    bufp->fullIData(oldp+115,(3U),32);
}

VL_ATTR_COLD void Vkv_mem_interface_tb___024root__trace_full_0_sub_0(Vkv_mem_interface_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vkv_mem_interface_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root__trace_full_0\n"); );
    // Body
    Vkv_mem_interface_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkv_mem_interface_tb___024root*>(voidSelf);
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vkv_mem_interface_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vkv_mem_interface_tb___024root__trace_full_0_sub_0(Vkv_mem_interface_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkv_mem_interface_tb___024root__trace_full_0_sub_0\n"); );
    Vkv_mem_interface_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+0,(vlSelfRef.kv_mem_interface_tb__DOT__rst_n));
    bufp->fullBit(oldp+1,(vlSelfRef.kv_mem_interface_tb__DOT__req_valid));
    bufp->fullBit(oldp+2,(vlSelfRef.kv_mem_interface_tb__DOT__req_write));
    bufp->fullCData(oldp+3,(vlSelfRef.kv_mem_interface_tb__DOT__req_addr),8);
    bufp->fullWData(oldp+4,(vlSelfRef.kv_mem_interface_tb__DOT__req_data_k),256);
    bufp->fullWData(oldp+12,(vlSelfRef.kv_mem_interface_tb__DOT__req_data_v),256);
    bufp->fullBit(oldp+20,(vlSelfRef.kv_mem_interface_tb__DOT__resp_ready));
    bufp->fullIData(oldp+21,(vlSelfRef.kv_mem_interface_tb__DOT__test_errors),32);
    bufp->fullWData(oldp+22,(vlSelfRef.kv_mem_interface_tb__DOT__exp_k),256);
    bufp->fullWData(oldp+30,(vlSelfRef.kv_mem_interface_tb__DOT__exp_v),256);
    bufp->fullCData(oldp+38,(vlSelfRef.kv_mem_interface_tb__DOT__addr),8);
    bufp->fullIData(oldp+39,(vlSelfRef.kv_mem_interface_tb__DOT__addresses),24);
    bufp->fullWData(oldp+40,(vlSelfRef.kv_mem_interface_tb__DOT__exp_k_array),768);
    bufp->fullWData(oldp+64,(vlSelfRef.kv_mem_interface_tb__DOT__exp_v_array),768);
    bufp->fullWData(oldp+88,(vlSelfRef.kv_mem_interface_tb__DOT__resp_data_k),256);
    bufp->fullWData(oldp+96,(vlSelfRef.kv_mem_interface_tb__DOT__resp_data_v),256);
    bufp->fullBit(oldp+104,(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state));
    bufp->fullBit(oldp+105,((1U & (~ (IData)(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state)))));
    bufp->fullBit(oldp+106,(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__read_state));
    bufp->fullBit(oldp+107,(vlSelfRef.kv_mem_interface_tb__DOT__clk));
    bufp->fullIData(oldp+108,(vlSelfRef.kv_mem_interface_tb__DOT__errors),32);
    bufp->fullBit(oldp+109,(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__wr_en));
    bufp->fullBit(oldp+110,(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__rd_en));
    bufp->fullBit(oldp+111,(vlSelfRef.kv_mem_interface_tb__DOT__dut__DOT__accept));
}
