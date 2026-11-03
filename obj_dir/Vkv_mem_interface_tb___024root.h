// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vkv_mem_interface_tb.h for the primary calling header

#ifndef VERILATED_VKV_MEM_INTERFACE_TB___024ROOT_H_
#define VERILATED_VKV_MEM_INTERFACE_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vkv_mem_interface_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vkv_mem_interface_tb___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ kv_mem_interface_tb__DOT__rst_n;
    CData/*0:0*/ kv_mem_interface_tb__DOT__clk;
    CData/*0:0*/ kv_mem_interface_tb__DOT__req_valid;
    CData/*0:0*/ kv_mem_interface_tb__DOT__req_write;
    CData/*7:0*/ kv_mem_interface_tb__DOT__req_addr;
    CData/*0:0*/ kv_mem_interface_tb__DOT__resp_ready;
    CData/*0:0*/ kv_mem_interface_tb__DOT__dut__DOT__read_state;
    CData/*0:0*/ kv_mem_interface_tb__DOT__dut__DOT__accept;
    CData/*0:0*/ kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__wr_en;
    CData/*0:0*/ kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__rd_en;
    CData/*0:0*/ __Vtrigprevexpr___TOP__kv_mem_interface_tb__DOT__clk__0;
    VlWide<8>/*255:0*/ kv_mem_interface_tb__DOT__req_data_k;
    VlWide<8>/*255:0*/ kv_mem_interface_tb__DOT__req_data_v;
    VlWide<8>/*255:0*/ kv_mem_interface_tb__DOT__resp_data_k;
    VlWide<8>/*255:0*/ kv_mem_interface_tb__DOT__resp_data_v;
    IData/*31:0*/ kv_mem_interface_tb__DOT__errors;
    IData/*31:0*/ kv_mem_interface_tb__DOT__test_errors;
    IData/*31:0*/ __Vi;
    VlUnpacked<VlWide<8>/*255:0*/, 256> kv_mem_interface_tb__DOT__dut__DOT__v_ram__DOT__mem;
    VlUnpacked<VlWide<8>/*255:0*/, 256> kv_mem_interface_tb__DOT__dut__DOT__k_ram__DOT__mem;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hc199cafc__0;

    // INTERNAL VARIABLES
    Vkv_mem_interface_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vkv_mem_interface_tb___024root(Vkv_mem_interface_tb__Syms* symsp, const char* namep);
    ~Vkv_mem_interface_tb___024root();
    VL_UNCOPYABLE(Vkv_mem_interface_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
