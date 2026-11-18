// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpage_allocator_tb.h for the primary calling header

#ifndef VERILATED_VPAGE_ALLOCATOR_TB___024ROOT_H_
#define VERILATED_VPAGE_ALLOCATOR_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vpage_allocator_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vpage_allocator_tb___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ page_allocator_tb__DOT__clk;
    CData/*0:0*/ page_allocator_tb__DOT__rst_n;
    CData/*0:0*/ page_allocator_tb__DOT__free_en;
    CData/*3:0*/ page_allocator_tb__DOT__free_ppage;
    CData/*0:0*/ page_allocator_tb__DOT__alloc_req;
    CData/*3:0*/ page_allocator_tb__DOT__alloc_page;
    CData/*0:0*/ page_allocator_tb__DOT__alloc_ok;
    CData/*0:0*/ page_allocator_tb__DOT__alloc_error;
    CData/*0:0*/ page_allocator_tb__DOT__dut__DOT__found_flag;
    CData/*0:0*/ __Vtrigprevexpr___TOP__page_allocator_tb__DOT__clk__0;
    SData/*15:0*/ page_allocator_tb__DOT__dut__DOT__used_map;
    IData/*31:0*/ page_allocator_tb__DOT__errors;
    IData/*31:0*/ page_allocator_tb__DOT__test_errors;
    IData/*31:0*/ __Vi;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hb34f2848__0;

    // INTERNAL VARIABLES
    Vpage_allocator_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vpage_allocator_tb___024root(Vpage_allocator_tb__Syms* symsp, const char* namep);
    ~Vpage_allocator_tb___024root();
    VL_UNCOPYABLE(Vpage_allocator_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
