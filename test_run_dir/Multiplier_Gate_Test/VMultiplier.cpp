// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMultiplier.h for the primary calling header

#include "VMultiplier.h"
#include "VMultiplier__Syms.h"

//==========

VL_CTOR_IMP(VMultiplier) {
    VMultiplier__Syms* __restrict vlSymsp = __VlSymsp = new VMultiplier__Syms(this, name());
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VMultiplier::__Vconfigure(VMultiplier__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMultiplier::~VMultiplier() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VMultiplier::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VMultiplier::eval\n"); );
    VMultiplier__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("Multiplier.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VMultiplier::_eval_initial_loop(VMultiplier__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("Multiplier.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VMultiplier::_combo__TOP__1(VMultiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiplier::_combo__TOP__1\n"); );
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Multiplier__DOT__out_wire = (((0U == (IData)(vlTOPp->io_op)) 
                                          | (1U == (IData)(vlTOPp->io_op)))
                                          ? VL_MULS_QQQ(64,64,64, 
                                                        VL_EXTENDS_QI(64,32, vlTOPp->io_src_a), 
                                                        VL_EXTENDS_QI(64,32, vlTOPp->io_src_b))
                                          : ((2U == (IData)(vlTOPp->io_op))
                                              ? VL_MULS_QQQ(64,64,64, 
                                                            VL_EXTENDS_QI(64,32, vlTOPp->io_src_a), 
                                                            VL_EXTENDS_QI(64,32, vlTOPp->io_src_b))
                                              : ((3U 
                                                  == (IData)(vlTOPp->io_op))
                                                  ? 
                                                 ((QData)((IData)(vlTOPp->io_src_a)) 
                                                  * (QData)((IData)(vlTOPp->io_src_b)))
                                                  : VL_ULL(0))));
}

void VMultiplier::_settle__TOP__2(VMultiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiplier::_settle__TOP__2\n"); );
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*95:0*/ __Vtemp2[3];
    WData/*95:0*/ __Vtemp3[3];
    WData/*95:0*/ __Vtemp6[3];
    WData/*95:0*/ __Vtemp7[3];
    WData/*95:0*/ __Vtemp8[3];
    WData/*95:0*/ __Vtemp9[3];
    WData/*95:0*/ __Vtemp10[3];
    WData/*95:0*/ __Vtemp13[3];
    WData/*95:0*/ __Vtemp17[3];
    WData/*95:0*/ __Vtemp21[3];
    // Body
    vlTOPp->Multiplier__DOT__out_wire = (((0U == (IData)(vlTOPp->io_op)) 
                                          | (1U == (IData)(vlTOPp->io_op)))
                                          ? VL_MULS_QQQ(64,64,64, 
                                                        VL_EXTENDS_QI(64,32, vlTOPp->io_src_a), 
                                                        VL_EXTENDS_QI(64,32, vlTOPp->io_src_b))
                                          : ((2U == (IData)(vlTOPp->io_op))
                                              ? VL_MULS_QQQ(64,64,64, 
                                                            VL_EXTENDS_QI(64,32, vlTOPp->io_src_a), 
                                                            VL_EXTENDS_QI(64,32, vlTOPp->io_src_b))
                                              : ((3U 
                                                  == (IData)(vlTOPp->io_op))
                                                  ? 
                                                 ((QData)((IData)(vlTOPp->io_src_a)) 
                                                  * (QData)((IData)(vlTOPp->io_src_b)))
                                                  : VL_ULL(0))));
    vlTOPp->Multiplier__DOT___T_19 = (0x3fU & ((IData)(vlTOPp->Multiplier__DOT__r_counter) 
                                               - (IData)(1U)));
    vlTOPp->io_ready = vlTOPp->Multiplier__DOT__r_ready;
    vlTOPp->io_output_valid = ((0U == (IData)(vlTOPp->io_op)) 
                               | ((((1U == (IData)(vlTOPp->io_op)) 
                                    & (2U == (IData)(vlTOPp->io_op))) 
                                   & (3U == (IData)(vlTOPp->io_op))) 
                                  | (((5U == (IData)(vlTOPp->io_op)) 
                                      | (7U == (IData)(vlTOPp->io_op))) 
                                     & ((~ (IData)(vlTOPp->io_valid)) 
                                        & (0U == (IData)(vlTOPp->Multiplier__DOT__r_counter))))));
    vlTOPp->Multiplier__DOT___GEN_13 = (((5U == (IData)(vlTOPp->io_op)) 
                                         | (7U == (IData)(vlTOPp->io_op)))
                                         ? ((~ (IData)(vlTOPp->io_valid)) 
                                            & ((0U 
                                                != (IData)(vlTOPp->Multiplier__DOT__r_counter))
                                                ? (1U 
                                                   == (IData)(vlTOPp->Multiplier__DOT__r_counter))
                                                : (IData)(vlTOPp->Multiplier__DOT__r_ready)))
                                         : (IData)(vlTOPp->Multiplier__DOT__r_ready));
    VL_EXTEND_WI(95,32, __Vtemp2, vlTOPp->io_src_b);
    VL_SHIFTL_WWI(95,95,6, __Vtemp3, __Vtemp2, (0x3fU 
                                                & ((IData)(vlTOPp->Multiplier__DOT__r_counter) 
                                                   - (IData)(1U))));
    vlTOPp->Multiplier__DOT___T_20[0U] = __Vtemp3[0U];
    vlTOPp->Multiplier__DOT___T_20[1U] = __Vtemp3[1U];
    vlTOPp->Multiplier__DOT___T_20[2U] = (0x7fffffffU 
                                          & __Vtemp3[2U]);
    vlTOPp->io_output_bits = ((0U == (IData)(vlTOPp->io_op))
                               ? (IData)(vlTOPp->Multiplier__DOT__out_wire)
                               : ((((1U == (IData)(vlTOPp->io_op)) 
                                    & (2U == (IData)(vlTOPp->io_op))) 
                                   & (3U == (IData)(vlTOPp->io_op)))
                                   ? (IData)((vlTOPp->Multiplier__DOT__out_wire 
                                              >> 0x20U))
                                   : ((5U == (IData)(vlTOPp->io_op))
                                       ? vlTOPp->Multiplier__DOT__r_quotient
                                       : ((7U == (IData)(vlTOPp->io_op))
                                           ? vlTOPp->Multiplier__DOT__r_dividend
                                           : 0U))));
    VL_EXTEND_WI(95,32, __Vtemp6, vlTOPp->io_src_a);
    VL_EXTEND_WI(95,32, __Vtemp7, vlTOPp->Multiplier__DOT__r_dividend);
    VL_EXTEND_WI(95,32, __Vtemp8, vlTOPp->Multiplier__DOT__r_dividend);
    VL_SUB_W(3, __Vtemp9, __Vtemp8, vlTOPp->Multiplier__DOT___T_20);
    VL_EXTEND_WI(95,32, __Vtemp10, vlTOPp->Multiplier__DOT__r_dividend);
    VL_EXTEND_WI(95,32, __Vtemp13, vlTOPp->Multiplier__DOT__r_dividend);
    VL_EXTEND_WI(95,32, __Vtemp17, vlTOPp->Multiplier__DOT__r_dividend);
    vlTOPp->Multiplier__DOT___GEN_15[0U] = (((5U == (IData)(vlTOPp->io_op)) 
                                             | (7U 
                                                == (IData)(vlTOPp->io_op)))
                                             ? ((IData)(vlTOPp->io_valid)
                                                 ? 
                                                __Vtemp6[0U]
                                                 : 
                                                ((0U 
                                                  != (IData)(vlTOPp->Multiplier__DOT__r_counter))
                                                  ? 
                                                 (VL_GTE_W(3, __Vtemp7, vlTOPp->Multiplier__DOT___T_20)
                                                   ? 
                                                  __Vtemp9[0U]
                                                   : 
                                                  __Vtemp10[0U])
                                                  : 
                                                 __Vtemp13[0U]))
                                             : __Vtemp17[0U]);
    vlTOPp->Multiplier__DOT___GEN_15[1U] = (((5U == (IData)(vlTOPp->io_op)) 
                                             | (7U 
                                                == (IData)(vlTOPp->io_op)))
                                             ? ((IData)(vlTOPp->io_valid)
                                                 ? 
                                                __Vtemp6[1U]
                                                 : 
                                                ((0U 
                                                  != (IData)(vlTOPp->Multiplier__DOT__r_counter))
                                                  ? 
                                                 (VL_GTE_W(3, __Vtemp7, vlTOPp->Multiplier__DOT___T_20)
                                                   ? 
                                                  __Vtemp9[1U]
                                                   : 
                                                  __Vtemp10[1U])
                                                  : 
                                                 __Vtemp13[1U]))
                                             : __Vtemp17[1U]);
    vlTOPp->Multiplier__DOT___GEN_15[2U] = (0x7fffffffU 
                                            & (((5U 
                                                 == (IData)(vlTOPp->io_op)) 
                                                | (7U 
                                                   == (IData)(vlTOPp->io_op)))
                                                ? ((IData)(vlTOPp->io_valid)
                                                    ? 
                                                   __Vtemp6[2U]
                                                    : 
                                                   ((0U 
                                                     != (IData)(vlTOPp->Multiplier__DOT__r_counter))
                                                     ? 
                                                    (VL_GTE_W(3, __Vtemp7, vlTOPp->Multiplier__DOT___T_20)
                                                      ? 
                                                     __Vtemp9[2U]
                                                      : 
                                                     __Vtemp10[2U])
                                                     : 
                                                    __Vtemp13[2U]))
                                                : __Vtemp17[2U]));
    VL_EXTEND_WI(95,32, __Vtemp21, vlTOPp->Multiplier__DOT__r_dividend);
    vlTOPp->Multiplier__DOT___GEN_16 = (((5U == (IData)(vlTOPp->io_op)) 
                                         | (7U == (IData)(vlTOPp->io_op)))
                                         ? ((IData)(vlTOPp->io_valid)
                                             ? VL_ULL(0)
                                             : ((0U 
                                                 != (IData)(vlTOPp->Multiplier__DOT__r_counter))
                                                 ? 
                                                (VL_GTE_W(3, __Vtemp21, vlTOPp->Multiplier__DOT___T_20)
                                                  ? 
                                                 ((QData)((IData)(vlTOPp->Multiplier__DOT__r_quotient)) 
                                                  + 
                                                  (VL_ULL(1) 
                                                   << 
                                                   (0x3fU 
                                                    & ((IData)(vlTOPp->Multiplier__DOT__r_counter) 
                                                       - (IData)(1U)))))
                                                  : (QData)((IData)(vlTOPp->Multiplier__DOT__r_quotient)))
                                                 : (QData)((IData)(vlTOPp->Multiplier__DOT__r_quotient))))
                                         : (QData)((IData)(vlTOPp->Multiplier__DOT__r_quotient)));
}

VL_INLINE_OPT void VMultiplier::_sequent__TOP__3(VMultiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiplier::_sequent__TOP__3\n"); );
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*5:0*/ __Vdly__Multiplier__DOT__r_counter;
    // Body
    __Vdly__Multiplier__DOT__r_counter = vlTOPp->Multiplier__DOT__r_counter;
    vlTOPp->Multiplier__DOT__r_ready = ((IData)(vlTOPp->reset) 
                                        | (IData)(vlTOPp->Multiplier__DOT___GEN_13));
    vlTOPp->Multiplier__DOT__r_quotient = ((IData)(vlTOPp->reset)
                                            ? 0U : (IData)(vlTOPp->Multiplier__DOT___GEN_16));
    vlTOPp->Multiplier__DOT__r_dividend = ((IData)(vlTOPp->reset)
                                            ? 0U : 
                                           vlTOPp->Multiplier__DOT___GEN_15[0U]);
    if (vlTOPp->reset) {
        __Vdly__Multiplier__DOT__r_counter = 0x20U;
    } else {
        if (((5U == (IData)(vlTOPp->io_op)) | (7U == (IData)(vlTOPp->io_op)))) {
            if (vlTOPp->io_valid) {
                __Vdly__Multiplier__DOT__r_counter = 0x20U;
            } else {
                if ((0U != (IData)(vlTOPp->Multiplier__DOT__r_counter))) {
                    __Vdly__Multiplier__DOT__r_counter 
                        = vlTOPp->Multiplier__DOT___T_19;
                }
            }
        }
    }
    vlTOPp->Multiplier__DOT__r_counter = __Vdly__Multiplier__DOT__r_counter;
    vlTOPp->io_ready = vlTOPp->Multiplier__DOT__r_ready;
    vlTOPp->Multiplier__DOT___T_19 = (0x3fU & ((IData)(vlTOPp->Multiplier__DOT__r_counter) 
                                               - (IData)(1U)));
}

VL_INLINE_OPT void VMultiplier::_combo__TOP__4(VMultiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiplier::_combo__TOP__4\n"); );
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*95:0*/ __Vtemp23[3];
    WData/*95:0*/ __Vtemp24[3];
    WData/*95:0*/ __Vtemp27[3];
    WData/*95:0*/ __Vtemp28[3];
    WData/*95:0*/ __Vtemp29[3];
    WData/*95:0*/ __Vtemp30[3];
    WData/*95:0*/ __Vtemp31[3];
    WData/*95:0*/ __Vtemp34[3];
    WData/*95:0*/ __Vtemp38[3];
    WData/*95:0*/ __Vtemp42[3];
    // Body
    vlTOPp->io_output_bits = ((0U == (IData)(vlTOPp->io_op))
                               ? (IData)(vlTOPp->Multiplier__DOT__out_wire)
                               : ((((1U == (IData)(vlTOPp->io_op)) 
                                    & (2U == (IData)(vlTOPp->io_op))) 
                                   & (3U == (IData)(vlTOPp->io_op)))
                                   ? (IData)((vlTOPp->Multiplier__DOT__out_wire 
                                              >> 0x20U))
                                   : ((5U == (IData)(vlTOPp->io_op))
                                       ? vlTOPp->Multiplier__DOT__r_quotient
                                       : ((7U == (IData)(vlTOPp->io_op))
                                           ? vlTOPp->Multiplier__DOT__r_dividend
                                           : 0U))));
    vlTOPp->io_output_valid = ((0U == (IData)(vlTOPp->io_op)) 
                               | ((((1U == (IData)(vlTOPp->io_op)) 
                                    & (2U == (IData)(vlTOPp->io_op))) 
                                   & (3U == (IData)(vlTOPp->io_op))) 
                                  | (((5U == (IData)(vlTOPp->io_op)) 
                                      | (7U == (IData)(vlTOPp->io_op))) 
                                     & ((~ (IData)(vlTOPp->io_valid)) 
                                        & (0U == (IData)(vlTOPp->Multiplier__DOT__r_counter))))));
    vlTOPp->Multiplier__DOT___GEN_13 = (((5U == (IData)(vlTOPp->io_op)) 
                                         | (7U == (IData)(vlTOPp->io_op)))
                                         ? ((~ (IData)(vlTOPp->io_valid)) 
                                            & ((0U 
                                                != (IData)(vlTOPp->Multiplier__DOT__r_counter))
                                                ? (1U 
                                                   == (IData)(vlTOPp->Multiplier__DOT__r_counter))
                                                : (IData)(vlTOPp->Multiplier__DOT__r_ready)))
                                         : (IData)(vlTOPp->Multiplier__DOT__r_ready));
    VL_EXTEND_WI(95,32, __Vtemp23, vlTOPp->io_src_b);
    VL_SHIFTL_WWI(95,95,6, __Vtemp24, __Vtemp23, (0x3fU 
                                                  & ((IData)(vlTOPp->Multiplier__DOT__r_counter) 
                                                     - (IData)(1U))));
    vlTOPp->Multiplier__DOT___T_20[0U] = __Vtemp24[0U];
    vlTOPp->Multiplier__DOT___T_20[1U] = __Vtemp24[1U];
    vlTOPp->Multiplier__DOT___T_20[2U] = (0x7fffffffU 
                                          & __Vtemp24[2U]);
    VL_EXTEND_WI(95,32, __Vtemp27, vlTOPp->io_src_a);
    VL_EXTEND_WI(95,32, __Vtemp28, vlTOPp->Multiplier__DOT__r_dividend);
    VL_EXTEND_WI(95,32, __Vtemp29, vlTOPp->Multiplier__DOT__r_dividend);
    VL_SUB_W(3, __Vtemp30, __Vtemp29, vlTOPp->Multiplier__DOT___T_20);
    VL_EXTEND_WI(95,32, __Vtemp31, vlTOPp->Multiplier__DOT__r_dividend);
    VL_EXTEND_WI(95,32, __Vtemp34, vlTOPp->Multiplier__DOT__r_dividend);
    VL_EXTEND_WI(95,32, __Vtemp38, vlTOPp->Multiplier__DOT__r_dividend);
    vlTOPp->Multiplier__DOT___GEN_15[0U] = (((5U == (IData)(vlTOPp->io_op)) 
                                             | (7U 
                                                == (IData)(vlTOPp->io_op)))
                                             ? ((IData)(vlTOPp->io_valid)
                                                 ? 
                                                __Vtemp27[0U]
                                                 : 
                                                ((0U 
                                                  != (IData)(vlTOPp->Multiplier__DOT__r_counter))
                                                  ? 
                                                 (VL_GTE_W(3, __Vtemp28, vlTOPp->Multiplier__DOT___T_20)
                                                   ? 
                                                  __Vtemp30[0U]
                                                   : 
                                                  __Vtemp31[0U])
                                                  : 
                                                 __Vtemp34[0U]))
                                             : __Vtemp38[0U]);
    vlTOPp->Multiplier__DOT___GEN_15[1U] = (((5U == (IData)(vlTOPp->io_op)) 
                                             | (7U 
                                                == (IData)(vlTOPp->io_op)))
                                             ? ((IData)(vlTOPp->io_valid)
                                                 ? 
                                                __Vtemp27[1U]
                                                 : 
                                                ((0U 
                                                  != (IData)(vlTOPp->Multiplier__DOT__r_counter))
                                                  ? 
                                                 (VL_GTE_W(3, __Vtemp28, vlTOPp->Multiplier__DOT___T_20)
                                                   ? 
                                                  __Vtemp30[1U]
                                                   : 
                                                  __Vtemp31[1U])
                                                  : 
                                                 __Vtemp34[1U]))
                                             : __Vtemp38[1U]);
    vlTOPp->Multiplier__DOT___GEN_15[2U] = (0x7fffffffU 
                                            & (((5U 
                                                 == (IData)(vlTOPp->io_op)) 
                                                | (7U 
                                                   == (IData)(vlTOPp->io_op)))
                                                ? ((IData)(vlTOPp->io_valid)
                                                    ? 
                                                   __Vtemp27[2U]
                                                    : 
                                                   ((0U 
                                                     != (IData)(vlTOPp->Multiplier__DOT__r_counter))
                                                     ? 
                                                    (VL_GTE_W(3, __Vtemp28, vlTOPp->Multiplier__DOT___T_20)
                                                      ? 
                                                     __Vtemp30[2U]
                                                      : 
                                                     __Vtemp31[2U])
                                                     : 
                                                    __Vtemp34[2U]))
                                                : __Vtemp38[2U]));
    VL_EXTEND_WI(95,32, __Vtemp42, vlTOPp->Multiplier__DOT__r_dividend);
    vlTOPp->Multiplier__DOT___GEN_16 = (((5U == (IData)(vlTOPp->io_op)) 
                                         | (7U == (IData)(vlTOPp->io_op)))
                                         ? ((IData)(vlTOPp->io_valid)
                                             ? VL_ULL(0)
                                             : ((0U 
                                                 != (IData)(vlTOPp->Multiplier__DOT__r_counter))
                                                 ? 
                                                (VL_GTE_W(3, __Vtemp42, vlTOPp->Multiplier__DOT___T_20)
                                                  ? 
                                                 ((QData)((IData)(vlTOPp->Multiplier__DOT__r_quotient)) 
                                                  + 
                                                  (VL_ULL(1) 
                                                   << 
                                                   (0x3fU 
                                                    & ((IData)(vlTOPp->Multiplier__DOT__r_counter) 
                                                       - (IData)(1U)))))
                                                  : (QData)((IData)(vlTOPp->Multiplier__DOT__r_quotient)))
                                                 : (QData)((IData)(vlTOPp->Multiplier__DOT__r_quotient))))
                                         : (QData)((IData)(vlTOPp->Multiplier__DOT__r_quotient)));
}

void VMultiplier::_eval(VMultiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiplier::_eval\n"); );
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VMultiplier::_eval_initial(VMultiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiplier::_eval_initial\n"); );
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VMultiplier::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiplier::final\n"); );
    // Variables
    VMultiplier__Syms* __restrict vlSymsp = this->__VlSymsp;
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VMultiplier::_eval_settle(VMultiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiplier::_eval_settle\n"); );
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData VMultiplier::_change_request(VMultiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiplier::_change_request\n"); );
    VMultiplier* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VMultiplier::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiplier::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_op & 0xe0U))) {
        Verilated::overWidthError("io_op");}
    if (VL_UNLIKELY((io_valid & 0xfeU))) {
        Verilated::overWidthError("io_valid");}
}
#endif  // VL_DEBUG

void VMultiplier::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiplier::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_src_a = VL_RAND_RESET_I(32);
    io_src_b = VL_RAND_RESET_I(32);
    io_op = VL_RAND_RESET_I(5);
    io_valid = VL_RAND_RESET_I(1);
    io_ready = VL_RAND_RESET_I(1);
    io_output_valid = VL_RAND_RESET_I(1);
    io_output_bits = VL_RAND_RESET_I(32);
    Multiplier__DOT__out_wire = VL_RAND_RESET_Q(64);
    Multiplier__DOT__r_ready = VL_RAND_RESET_I(1);
    Multiplier__DOT__r_counter = VL_RAND_RESET_I(6);
    Multiplier__DOT__r_dividend = VL_RAND_RESET_I(32);
    Multiplier__DOT__r_quotient = VL_RAND_RESET_I(32);
    Multiplier__DOT___T_19 = VL_RAND_RESET_I(6);
    VL_RAND_RESET_W(95, Multiplier__DOT___T_20);
    Multiplier__DOT___GEN_13 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(95, Multiplier__DOT___GEN_15);
    Multiplier__DOT___GEN_16 = VL_RAND_RESET_Q(64);
    __Vm_traceActivity = 0;
}
