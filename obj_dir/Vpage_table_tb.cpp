// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpage_table_tb__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vpage_table_tb::Vpage_table_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vpage_table_tb__Syms(contextp(), _vcname__, this)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vpage_table_tb::Vpage_table_tb(const char* _vcname__)
    : Vpage_table_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vpage_table_tb::~Vpage_table_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vpage_table_tb___024root___eval_debug_assertions(Vpage_table_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vpage_table_tb___024root___eval_static(Vpage_table_tb___024root* vlSelf);
void Vpage_table_tb___024root___eval_initial(Vpage_table_tb___024root* vlSelf);
VL_ATTR_COLD bool Vpage_table_tb___024root___eval_stl(Vpage_table_tb___024root* vlSelf, CData/*0:0*/ firstIteration);
void Vpage_table_tb___024root___eval_sample(Vpage_table_tb___024root* vlSelf);
bool Vpage_table_tb___024root___eval_ico(Vpage_table_tb___024root* vlSelf, CData/*0:0*/ firstIteration);
bool Vpage_table_tb___024root___eval_act(Vpage_table_tb___024root* vlSelf);
bool Vpage_table_tb___024root___eval_inact(Vpage_table_tb___024root* vlSelf);
bool Vpage_table_tb___024root___eval_nba(Vpage_table_tb___024root* vlSelf);
bool Vpage_table_tb___024root___eval_obs(Vpage_table_tb___024root* vlSelf);
bool Vpage_table_tb___024root___eval_react(Vpage_table_tb___024root* vlSelf);
void Vpage_table_tb___024root___eval_postponed(Vpage_table_tb___024root* vlSelf);
VL_ATTR_COLD void Vpage_table_tb___024root___eval_final(Vpage_table_tb___024root* vlSelf);
VL_ATTR_COLD void Vpage_table_tb___024root___eval_dump_triggers__stl(Vpage_table_tb___024root* vlSelf);
VL_ATTR_COLD void Vpage_table_tb___024root___eval_dump_triggers__ico(Vpage_table_tb___024root* vlSelf);
VL_ATTR_COLD void Vpage_table_tb___024root___eval_dump_triggers__act(Vpage_table_tb___024root* vlSelf);
VL_ATTR_COLD void Vpage_table_tb___024root___eval_dump_triggers__nba(Vpage_table_tb___024root* vlSelf);
VL_ATTR_COLD void Vpage_table_tb___024root___eval_dump_triggers__obs(Vpage_table_tb___024root* vlSelf);
VL_ATTR_COLD void Vpage_table_tb___024root___eval_dump_triggers__react(Vpage_table_tb___024root* vlSelf);

void Vpage_table_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpage_table_tb::eval_step\n"); );
    m_evalLoop.eval();
}

void Vpage_table_tb::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vpage_table_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vpage_table_tb::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
    vlSymsp->TOP.__VdlySched.cleanupForevered();
}

void Vpage_table_tb::evalStatic() {
    Vpage_table_tb___024root___eval_static(&(vlSymsp->TOP));
}

void Vpage_table_tb::evalInitial() {
    Vpage_table_tb___024root___eval_initial(&(vlSymsp->TOP));
}

bool Vpage_table_tb::evalStl(bool firstIteration) {
    return Vpage_table_tb___024root___eval_stl(&(vlSymsp->TOP), firstIteration);
}

void Vpage_table_tb::evalSample() {
    Vpage_table_tb___024root___eval_sample(&(vlSymsp->TOP));
}

bool Vpage_table_tb::evalIco(bool firstIteration) {
    return Vpage_table_tb___024root___eval_ico(&(vlSymsp->TOP), firstIteration);
}

bool Vpage_table_tb::evalAct() {
    return Vpage_table_tb___024root___eval_act(&(vlSymsp->TOP));
}

bool Vpage_table_tb::evalInact() {
    return Vpage_table_tb___024root___eval_inact(&(vlSymsp->TOP));
}

bool Vpage_table_tb::evalNba() {
    return Vpage_table_tb___024root___eval_nba(&(vlSymsp->TOP));
}

bool Vpage_table_tb::evalObs() {
    return Vpage_table_tb___024root___eval_obs(&(vlSymsp->TOP));
}

bool Vpage_table_tb::evalReact() {
    return Vpage_table_tb___024root___eval_react(&(vlSymsp->TOP));
}

void Vpage_table_tb::evalPostponed() {
    Vpage_table_tb___024root___eval_postponed(&(vlSymsp->TOP));
}

void Vpage_table_tb::evalFinal() {
    Vpage_table_tb___024root___eval_final(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vpage_table_tb::dumpTriggersStl() {
    Vpage_table_tb___024root___eval_dump_triggers__stl(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vpage_table_tb::dumpTriggersIco() {
    Vpage_table_tb___024root___eval_dump_triggers__ico(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vpage_table_tb::dumpTriggersAct() {
    Vpage_table_tb___024root___eval_dump_triggers__act(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vpage_table_tb::dumpTriggersNba() {
    Vpage_table_tb___024root___eval_dump_triggers__nba(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vpage_table_tb::dumpTriggersObs() {
    Vpage_table_tb___024root___eval_dump_triggers__obs(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vpage_table_tb::dumpTriggersReact() {
    Vpage_table_tb___024root___eval_dump_triggers__react(&(vlSymsp->TOP));
}

void Vpage_table_tb::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vpage_table_tb::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vpage_table_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vpage_table_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vpage_table_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vpage_table_tb::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpage_table_tb::hierName() const { return vlSymsp->name(); }
const char* Vpage_table_tb::modelName() const { return "Vpage_table_tb"; }
unsigned Vpage_table_tb::threads() const { return 1; }
void Vpage_table_tb::prepareClone() const { contextp()->prepareClone(); }
void Vpage_table_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vpage_table_tb::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vpage_table_tb___024root__trace_decl_types(VerilatedVcd* tracep);

void Vpage_table_tb___024root__trace_init_top(Vpage_table_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vpage_table_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpage_table_tb___024root*>(voidSelf);
    Vpage_table_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vpage_table_tb___024root__trace_decl_types(tracep);
    Vpage_table_tb___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpage_table_tb___024root__trace_register(Vpage_table_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vpage_table_tb::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vpage_table_tb::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 46);
    Vpage_table_tb___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
