// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vkv_block_ram_tb__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vkv_block_ram_tb::Vkv_block_ram_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vkv_block_ram_tb__Syms(contextp(), _vcname__, this)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vkv_block_ram_tb::Vkv_block_ram_tb(const char* _vcname__)
    : Vkv_block_ram_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vkv_block_ram_tb::~Vkv_block_ram_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vkv_block_ram_tb___024root___eval_debug_assertions(Vkv_block_ram_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vkv_block_ram_tb___024root___eval_static(Vkv_block_ram_tb___024root* vlSelf);
void Vkv_block_ram_tb___024root___eval_initial(Vkv_block_ram_tb___024root* vlSelf);
VL_ATTR_COLD bool Vkv_block_ram_tb___024root___eval_stl(Vkv_block_ram_tb___024root* vlSelf, CData/*0:0*/ firstIteration);
void Vkv_block_ram_tb___024root___eval_sample(Vkv_block_ram_tb___024root* vlSelf);
bool Vkv_block_ram_tb___024root___eval_ico(Vkv_block_ram_tb___024root* vlSelf, CData/*0:0*/ firstIteration);
bool Vkv_block_ram_tb___024root___eval_act(Vkv_block_ram_tb___024root* vlSelf);
bool Vkv_block_ram_tb___024root___eval_inact(Vkv_block_ram_tb___024root* vlSelf);
bool Vkv_block_ram_tb___024root___eval_nba(Vkv_block_ram_tb___024root* vlSelf);
bool Vkv_block_ram_tb___024root___eval_obs(Vkv_block_ram_tb___024root* vlSelf);
bool Vkv_block_ram_tb___024root___eval_react(Vkv_block_ram_tb___024root* vlSelf);
void Vkv_block_ram_tb___024root___eval_postponed(Vkv_block_ram_tb___024root* vlSelf);
VL_ATTR_COLD void Vkv_block_ram_tb___024root___eval_final(Vkv_block_ram_tb___024root* vlSelf);
VL_ATTR_COLD void Vkv_block_ram_tb___024root___eval_dump_triggers__stl(Vkv_block_ram_tb___024root* vlSelf);
VL_ATTR_COLD void Vkv_block_ram_tb___024root___eval_dump_triggers__ico(Vkv_block_ram_tb___024root* vlSelf);
VL_ATTR_COLD void Vkv_block_ram_tb___024root___eval_dump_triggers__act(Vkv_block_ram_tb___024root* vlSelf);
VL_ATTR_COLD void Vkv_block_ram_tb___024root___eval_dump_triggers__nba(Vkv_block_ram_tb___024root* vlSelf);
VL_ATTR_COLD void Vkv_block_ram_tb___024root___eval_dump_triggers__obs(Vkv_block_ram_tb___024root* vlSelf);
VL_ATTR_COLD void Vkv_block_ram_tb___024root___eval_dump_triggers__react(Vkv_block_ram_tb___024root* vlSelf);

void Vkv_block_ram_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vkv_block_ram_tb::eval_step\n"); );
    m_evalLoop.eval();
}

void Vkv_block_ram_tb::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vkv_block_ram_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vkv_block_ram_tb::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
    vlSymsp->TOP.__VdlySched.cleanupForevered();
}

void Vkv_block_ram_tb::evalStatic() {
    Vkv_block_ram_tb___024root___eval_static(&(vlSymsp->TOP));
}

void Vkv_block_ram_tb::evalInitial() {
    Vkv_block_ram_tb___024root___eval_initial(&(vlSymsp->TOP));
}

bool Vkv_block_ram_tb::evalStl(bool firstIteration) {
    return Vkv_block_ram_tb___024root___eval_stl(&(vlSymsp->TOP), firstIteration);
}

void Vkv_block_ram_tb::evalSample() {
    Vkv_block_ram_tb___024root___eval_sample(&(vlSymsp->TOP));
}

bool Vkv_block_ram_tb::evalIco(bool firstIteration) {
    return Vkv_block_ram_tb___024root___eval_ico(&(vlSymsp->TOP), firstIteration);
}

bool Vkv_block_ram_tb::evalAct() {
    return Vkv_block_ram_tb___024root___eval_act(&(vlSymsp->TOP));
}

bool Vkv_block_ram_tb::evalInact() {
    return Vkv_block_ram_tb___024root___eval_inact(&(vlSymsp->TOP));
}

bool Vkv_block_ram_tb::evalNba() {
    return Vkv_block_ram_tb___024root___eval_nba(&(vlSymsp->TOP));
}

bool Vkv_block_ram_tb::evalObs() {
    return Vkv_block_ram_tb___024root___eval_obs(&(vlSymsp->TOP));
}

bool Vkv_block_ram_tb::evalReact() {
    return Vkv_block_ram_tb___024root___eval_react(&(vlSymsp->TOP));
}

void Vkv_block_ram_tb::evalPostponed() {
    Vkv_block_ram_tb___024root___eval_postponed(&(vlSymsp->TOP));
}

void Vkv_block_ram_tb::evalFinal() {
    Vkv_block_ram_tb___024root___eval_final(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vkv_block_ram_tb::dumpTriggersStl() {
    Vkv_block_ram_tb___024root___eval_dump_triggers__stl(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vkv_block_ram_tb::dumpTriggersIco() {
    Vkv_block_ram_tb___024root___eval_dump_triggers__ico(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vkv_block_ram_tb::dumpTriggersAct() {
    Vkv_block_ram_tb___024root___eval_dump_triggers__act(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vkv_block_ram_tb::dumpTriggersNba() {
    Vkv_block_ram_tb___024root___eval_dump_triggers__nba(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vkv_block_ram_tb::dumpTriggersObs() {
    Vkv_block_ram_tb___024root___eval_dump_triggers__obs(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vkv_block_ram_tb::dumpTriggersReact() {
    Vkv_block_ram_tb___024root___eval_dump_triggers__react(&(vlSymsp->TOP));
}

//============================================================
// Events and timing
bool Vkv_block_ram_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vkv_block_ram_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vkv_block_ram_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vkv_block_ram_tb::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vkv_block_ram_tb::hierName() const { return vlSymsp->name(); }
const char* Vkv_block_ram_tb::modelName() const { return "Vkv_block_ram_tb"; }
unsigned Vkv_block_ram_tb::threads() const { return 1; }
void Vkv_block_ram_tb::prepareClone() const { contextp()->prepareClone(); }
void Vkv_block_ram_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vkv_block_ram_tb::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vkv_block_ram_tb___024root__trace_decl_types(VerilatedVcd* tracep);

void Vkv_block_ram_tb___024root__trace_init_top(Vkv_block_ram_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vkv_block_ram_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkv_block_ram_tb___024root*>(voidSelf);
    Vkv_block_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vkv_block_ram_tb___024root__trace_decl_types(tracep);
    Vkv_block_ram_tb___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vkv_block_ram_tb___024root__trace_register(Vkv_block_ram_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vkv_block_ram_tb::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vkv_block_ram_tb::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 22);
    Vkv_block_ram_tb___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
