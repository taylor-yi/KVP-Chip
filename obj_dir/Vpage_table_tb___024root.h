// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpage_table_tb.h for the primary calling header

#ifndef VERILATED_VPAGE_TABLE_TB___024ROOT_H_
#define VERILATED_VPAGE_TABLE_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vpage_table_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vpage_table_tb___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ page_table_tb__DOT__clk;
    CData/*0:0*/ page_table_tb__DOT__rst_n;
    CData/*3:0*/ page_table_tb__DOT__lookup_l_page;
    CData/*0:0*/ page_table_tb__DOT__wr_en;
    CData/*3:0*/ page_table_tb__DOT__wr_lpage;
    CData/*3:0*/ page_table_tb__DOT__wr_ppage;
    CData/*0:0*/ __Vtrigprevexpr___TOP__page_table_tb__DOT__clk__0;
    SData/*15:0*/ page_table_tb__DOT__dut__DOT__valid_bits;
    IData/*31:0*/ page_table_tb__DOT__errors;
    IData/*31:0*/ page_table_tb__DOT__test_errors;
    IData/*31:0*/ __Vi;
    VlUnpacked<CData/*3:0*/, 16> page_table_tb__DOT__exp_page;
    VlUnpacked<CData/*3:0*/, 16> page_table_tb__DOT__dut__DOT__ppage_table;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h7f3e1276__0;

    // INTERNAL VARIABLES
    Vpage_table_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vpage_table_tb___024root(Vpage_table_tb__Syms* symsp, const char* namep);
    ~Vpage_table_tb___024root();
    VL_UNCOPYABLE(Vpage_table_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
