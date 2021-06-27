// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VMY_DESIGN_H_
#define VERILATED_VMY_DESIGN_H_  // guard

#include "systemc.h"
#include "verilated_sc.h"
#include "verilated_heavy.h"

//==========

class Vmy_design__Syms;

//----------

SC_MODULE(Vmy_design) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    sc_in<bool> clk;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vcellinp__my_design__clk;
    CData/*0:0*/ __Vclklast__TOP____Vcellinp__my_design__clk;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmy_design__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmy_design);  ///< Copying not allowed
  public:
    SC_CTOR(Vmy_design);
    virtual ~Vmy_design();
    
    // API METHODS
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp();
  private:
    void eval() { eval_step(); }
    void eval_step();
  public:
    void final();
    
    // INTERNAL METHODS
    static void _eval_initial_loop(Vmy_design__Syms* __restrict vlSymsp);
    void __Vconfigure(Vmy_design__Syms* symsp, bool first);
  private:
    static QData _change_request(Vmy_design__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vmy_design__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vmy_design__Syms* __restrict vlSymsp);
  private:
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
    static void _sequent__TOP__3(Vmy_design__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
