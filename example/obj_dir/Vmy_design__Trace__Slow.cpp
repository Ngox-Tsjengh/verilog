// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmy_design__Syms.h"


//======================

void Vmy_design::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vmy_design::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmy_design__Syms* __restrict vlSymsp = static_cast<Vmy_design__Syms*>(userp);
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vmy_design::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vmy_design::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vmy_design__Syms* __restrict vlSymsp = static_cast<Vmy_design__Syms*>(userp);
    Vmy_design* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vmy_design::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vmy_design__Syms* __restrict vlSymsp = static_cast<Vmy_design__Syms*>(userp);
    Vmy_design* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
}

void Vmy_design::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}
