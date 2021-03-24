// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmy_design.h for the primary calling header

#include "Vmy_design.h"
#include "Vmy_design__Syms.h"

//==========

Vmy_design::Vmy_design(const char* __VCname)
    : VerilatedModule(__VCname)
 {
    Vmy_design__Syms* __restrict vlSymsp = __VlSymsp = new Vmy_design__Syms(this, name());
    Vmy_design* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmy_design::__Vconfigure(Vmy_design__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vmy_design::~Vmy_design() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vmy_design::_initial__TOP__2(Vmy_design__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_design::_initial__TOP__2\n"); );
    Vmy_design* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->my_design__DOT__counter = 0U;
}

void Vmy_design::_settle__TOP__3(Vmy_design__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_design::_settle__TOP__3\n"); );
    Vmy_design* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->o_led = (1U & ((IData)(vlTOPp->my_design__DOT__counter) 
                           >> 0xbU));
}

void Vmy_design::_eval_initial(Vmy_design__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_design::_eval_initial\n"); );
    Vmy_design* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
    vlTOPp->_initial__TOP__2(vlSymsp);
}

void Vmy_design::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_design::final\n"); );
    // Variables
    Vmy_design__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmy_design* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmy_design::_eval_settle(Vmy_design__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_design::_eval_settle\n"); );
    Vmy_design* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vmy_design::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_design::_ctor_var_reset\n"); );
    // Body
    i_clk = VL_RAND_RESET_I(1);
    o_led = VL_RAND_RESET_I(1);
    my_design__DOT__counter = VL_RAND_RESET_I(12);
    for (int __Vi0=0; __Vi0<1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
