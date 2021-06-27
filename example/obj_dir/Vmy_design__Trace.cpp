// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmy_design__Syms.h"


void Vmy_design::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vmy_design__Syms* __restrict vlSymsp = static_cast<Vmy_design__Syms*>(userp);
    Vmy_design* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
