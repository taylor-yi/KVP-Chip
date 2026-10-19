// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vkv_block_ram_tb.h for the primary calling header

#ifndef VERILATED_VKV_BLOCK_RAM_TB___024ROOT_H_
#define VERILATED_VKV_BLOCK_RAM_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vkv_block_ram_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vkv_block_ram_tb___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ kv_block_ram_tb__DOT__clk;
    CData/*0:0*/ kv_block_ram_tb__DOT__wr_en;
    CData/*7:0*/ kv_block_ram_tb__DOT__wr_addr;
    CData/*7:0*/ kv_block_ram_tb__DOT__rd_addr;
    CData/*0:0*/ __Vtrigprevexpr___TOP__kv_block_ram_tb__DOT__clk__0;
    VlWide<8>/*255:0*/ kv_block_ram_tb__DOT__wr_data;
    VlWide<8>/*255:0*/ kv_block_ram_tb__DOT__rd_data;
    IData/*31:0*/ __Vi;
    VlUnpacked<VlWide<8>/*255:0*/, 256> kv_block_ram_tb__DOT__dut__DOT__mem;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hb691101e__0;

    // INTERNAL VARIABLES
    Vkv_block_ram_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vkv_block_ram_tb___024root(Vkv_block_ram_tb__Syms* symsp, const char* namep);
    ~Vkv_block_ram_tb___024root();
    VL_UNCOPYABLE(Vkv_block_ram_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
