// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmy_design.h for the primary calling header

#ifndef _VMY_DESIGN___024UNIT_H_
#define _VMY_DESIGN___024UNIT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vmy_design__Syms;
class Vmy_design_VerilatedVcd;


//----------

VL_MODULE(Vmy_design___024unit) {
  public:
    
    // INTERNAL VARIABLES
  private:
    Vmy_design__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmy_design___024unit);  ///< Copying not allowed
  public:
    Vmy_design___024unit(const char* name = "TOP");
    ~Vmy_design___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(Vmy_design__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
