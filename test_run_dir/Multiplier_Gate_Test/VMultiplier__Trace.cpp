// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMultiplier__Syms.h"


//======================

void VMultiplier::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VMultiplier* t = (VMultiplier*)userthis;
    VMultiplier__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VMultiplier::traceChgThis(VMultiplier__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VMultiplier::traceChgThis__2(VMultiplier__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgQuad(c+1,(vlTOPp->Multiplier__DOT__out_wire),64);
    }
}

void VMultiplier::traceChgThis__3(VMultiplier__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+17,(vlTOPp->Multiplier__DOT__r_ready));
        vcdp->chgBus(c+25,(vlTOPp->Multiplier__DOT__r_counter),6);
        vcdp->chgBus(c+33,(vlTOPp->Multiplier__DOT__r_dividend),32);
        vcdp->chgBus(c+41,(vlTOPp->Multiplier__DOT__r_quotient),32);
    }
}

void VMultiplier::traceChgThis__4(VMultiplier__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+49,(vlTOPp->clock));
        vcdp->chgBit(c+57,(vlTOPp->reset));
        vcdp->chgBus(c+65,(vlTOPp->io_src_a),32);
        vcdp->chgBus(c+73,(vlTOPp->io_src_b),32);
        vcdp->chgBus(c+81,(vlTOPp->io_op),5);
        vcdp->chgBit(c+89,(vlTOPp->io_valid));
        vcdp->chgBit(c+97,(vlTOPp->io_ready));
        vcdp->chgBit(c+105,(vlTOPp->io_output_valid));
        vcdp->chgBus(c+113,(vlTOPp->io_output_bits),32);
    }
}
