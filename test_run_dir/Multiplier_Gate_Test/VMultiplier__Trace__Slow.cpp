// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMultiplier__Syms.h"


//======================

void VMultiplier::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VMultiplier::traceInit, &VMultiplier::traceFull, &VMultiplier::traceChg, this);
}
void VMultiplier::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VMultiplier* t = (VMultiplier*)userthis;
    VMultiplier__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VMultiplier::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VMultiplier* t = (VMultiplier*)userthis;
    VMultiplier__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VMultiplier::traceInitThis(VMultiplier__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VMultiplier::traceFullThis(VMultiplier__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VMultiplier::traceInitThis__1(VMultiplier__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+49,"clock", false,-1);
        vcdp->declBit(c+57,"reset", false,-1);
        vcdp->declBus(c+65,"io_src_a", false,-1, 31,0);
        vcdp->declBus(c+73,"io_src_b", false,-1, 31,0);
        vcdp->declBus(c+81,"io_op", false,-1, 4,0);
        vcdp->declBit(c+89,"io_valid", false,-1);
        vcdp->declBit(c+97,"io_ready", false,-1);
        vcdp->declBit(c+105,"io_output_valid", false,-1);
        vcdp->declBus(c+113,"io_output_bits", false,-1, 31,0);
        vcdp->declBit(c+49,"Multiplier clock", false,-1);
        vcdp->declBit(c+57,"Multiplier reset", false,-1);
        vcdp->declBus(c+65,"Multiplier io_src_a", false,-1, 31,0);
        vcdp->declBus(c+73,"Multiplier io_src_b", false,-1, 31,0);
        vcdp->declBus(c+81,"Multiplier io_op", false,-1, 4,0);
        vcdp->declBit(c+89,"Multiplier io_valid", false,-1);
        vcdp->declBit(c+97,"Multiplier io_ready", false,-1);
        vcdp->declBit(c+105,"Multiplier io_output_valid", false,-1);
        vcdp->declBus(c+113,"Multiplier io_output_bits", false,-1, 31,0);
        vcdp->declQuad(c+1,"Multiplier out_wire", false,-1, 63,0);
        vcdp->declBit(c+17,"Multiplier r_ready", false,-1);
        vcdp->declBus(c+25,"Multiplier r_counter", false,-1, 5,0);
        vcdp->declBus(c+33,"Multiplier r_dividend", false,-1, 31,0);
        vcdp->declBus(c+41,"Multiplier r_quotient", false,-1, 31,0);
    }
}

void VMultiplier::traceFullThis__1(VMultiplier__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullQuad(c+1,(vlTOPp->Multiplier__DOT__out_wire),64);
        vcdp->fullBit(c+17,(vlTOPp->Multiplier__DOT__r_ready));
        vcdp->fullBus(c+25,(vlTOPp->Multiplier__DOT__r_counter),6);
        vcdp->fullBus(c+33,(vlTOPp->Multiplier__DOT__r_dividend),32);
        vcdp->fullBus(c+41,(vlTOPp->Multiplier__DOT__r_quotient),32);
        vcdp->fullBit(c+49,(vlTOPp->clock));
        vcdp->fullBit(c+57,(vlTOPp->reset));
        vcdp->fullBus(c+65,(vlTOPp->io_src_a),32);
        vcdp->fullBus(c+73,(vlTOPp->io_src_b),32);
        vcdp->fullBus(c+81,(vlTOPp->io_op),5);
        vcdp->fullBit(c+89,(vlTOPp->io_valid));
        vcdp->fullBit(c+97,(vlTOPp->io_ready));
        vcdp->fullBit(c+105,(vlTOPp->io_output_valid));
        vcdp->fullBus(c+113,(vlTOPp->io_output_bits),32);
    }
}
