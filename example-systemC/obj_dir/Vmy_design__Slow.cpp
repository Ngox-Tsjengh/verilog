// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmy_design.h for the primary calling header

#include "Vmy_design.h"
#include "Vmy_design__Syms.h"

//==========

Vmy_design::Vmy_design(sc_module_name)
    : clk("clk")
 {
    Vmy_design__Syms* __restrict vlSymsp = __VlSymsp = new Vmy_design__Syms(nullptr, this, name());
    Vmy_design* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Sensitivities on all clocks and combo inputs
    SC_METHOD(eval);
    sensitive << clk;
    
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmy_design::__Vconfigure(Vmy_design__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

Vmy_design::~Vmy_design() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vmy_design::_eval_initial(Vmy_design__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_design::_eval_initial\n"); );
    Vmy_design* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP____Vcellinp__my_design__clk 
        = vlTOPp->__Vcellinp__my_design__clk;
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
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vmy_design::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_design::_ctor_var_reset\n"); );
    // Body
    __Vcellinp__my_design__clk = VL_RAND_RESET_I(1);
}
