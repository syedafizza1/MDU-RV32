// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VMULTIPLIER_H_
#define _VMULTIPLIER_H_  // guard

#include "verilated.h"

//==========

class VMultiplier__Syms;
class VMultiplier_VerilatedVcd;


//----------

VL_MODULE(VMultiplier) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_op,4,0);
    VL_IN8(io_valid,0,0);
    VL_OUT8(io_ready,0,0);
    VL_OUT8(io_output_valid,0,0);
    VL_IN(io_src_a,31,0);
    VL_IN(io_src_b,31,0);
    VL_OUT(io_output_bits,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ Multiplier__DOT__r_ready;
    CData/*5:0*/ Multiplier__DOT__r_counter;
    CData/*5:0*/ Multiplier__DOT___T_19;
    CData/*0:0*/ Multiplier__DOT___GEN_13;
    IData/*31:0*/ Multiplier__DOT__r_dividend;
    IData/*31:0*/ Multiplier__DOT__r_quotient;
    WData/*94:0*/ Multiplier__DOT___T_20[3];
    WData/*94:0*/ Multiplier__DOT___GEN_15[3];
    QData/*63:0*/ Multiplier__DOT__out_wire;
    QData/*63:0*/ Multiplier__DOT___GEN_16;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VMultiplier__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VMultiplier);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VMultiplier(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VMultiplier();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VMultiplier__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VMultiplier__Syms* symsp, bool first);
  private:
    static QData _change_request(VMultiplier__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(VMultiplier__Syms* __restrict vlSymsp);
    static void _combo__TOP__4(VMultiplier__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VMultiplier__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VMultiplier__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VMultiplier__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(VMultiplier__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VMultiplier__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(VMultiplier__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VMultiplier__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(VMultiplier__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(VMultiplier__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VMultiplier__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(VMultiplier__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(VMultiplier__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(VMultiplier__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
