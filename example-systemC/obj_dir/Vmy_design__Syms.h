// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMY_DESIGN__SYMS_H_
#define VERILATED_VMY_DESIGN__SYMS_H_  // guard

#include "systemc.h"
#include "verilated_sc.h"
#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vmy_design.h"

// SYMS CLASS
class Vmy_design__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vmy_design*                    TOPp;
    
    // CREATORS
    Vmy_design__Syms(VerilatedContext* contextp, Vmy_design* topp, const char* namep);
    ~Vmy_design__Syms();
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
