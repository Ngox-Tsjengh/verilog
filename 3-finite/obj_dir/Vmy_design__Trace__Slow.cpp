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
    if (!Verilated::calcUnusedSigs()) {
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
    // Body
    {
        tracep->declBit(c+1,"i_clk", false,-1);
        tracep->declBus(c+2,"o_led", false,-1, 7,0);
        tracep->declBit(c+1,"my_design i_clk", false,-1);
        tracep->declBus(c+2,"my_design o_led", false,-1, 7,0);
        tracep->declBus(c+3,"my_design led_index", false,-1, 3,0);
    }
}

void Vmy_design::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vmy_design::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vmy_design__Syms* __restrict vlSymsp = static_cast<Vmy_design__Syms*>(userp);
    Vmy_design* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vmy_design::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vmy_design__Syms* __restrict vlSymsp = static_cast<Vmy_design__Syms*>(userp);
    Vmy_design* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->i_clk));
        tracep->fullCData(oldp+2,(vlTOPp->o_led),8);
        tracep->fullCData(oldp+3,(vlTOPp->my_design__DOT__led_index),4);
    }
}
