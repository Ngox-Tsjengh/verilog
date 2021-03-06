// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmy_design__Syms.h"


void Vmy_design::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vmy_design__Syms* __restrict vlSymsp = static_cast<Vmy_design__Syms*>(userp);
    Vmy_design* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vmy_design::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vmy_design__Syms* __restrict vlSymsp = static_cast<Vmy_design__Syms*>(userp);
    Vmy_design* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->i_clk));
        tracep->chgBit(oldp+1,(vlTOPp->o_led));
        tracep->chgSData(oldp+2,(vlTOPp->my_design__DOT__counter),12);
    }
}

void Vmy_design::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vmy_design__Syms* __restrict vlSymsp = static_cast<Vmy_design__Syms*>(userp);
    Vmy_design* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
