// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VMY_DESIGN_H_
#define VERILATED_VMY_DESIGN_H_  // guard

#include "verilated_heavy.h"

//==========

class Vmy_design__Syms;
class Vmy_design_VerilatedVcd;


//----------

VL_MODULE(Vmy_design) {
  public:
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vm_traceActivity[1];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmy_design__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmy_design);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vmy_design(VerilatedContext* contextp, const char* name = "TOP");
    Vmy_design(const char* name = "TOP")
      : Vmy_design(nullptr, name) {}
    /// Destroy the model; called (often implicitly) by application code
    ~Vmy_design();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp();
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
    static void _eval_initial_loop(Vmy_design__Syms* __restrict vlSymsp);
    void __Vconfigure(Vmy_design__Syms* symsp, bool first);
  private:
    static QData _change_request(Vmy_design__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vmy_design__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vmy_design__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vmy_design__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vmy_design__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vmy_design__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
