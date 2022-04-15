circuit Multiplier :
  module Multiplier :
    input clock : Clock
    input reset : UInt<1>
    input io_src_a : UInt<32>
    input io_src_b : UInt<32>
    input io_op : UInt<5>
    input io_valid : UInt<1>
    output io_ready : UInt<1>
    output io_output_valid : UInt<1>
    output io_output_bits : UInt<32>

    node _T = eq(io_op, UInt<1>("h0")) @[Multiplier.scala 17:30]
    node _T_1 = eq(io_op, UInt<1>("h1")) @[Multiplier.scala 17:47]
    node _T_2 = or(_T, _T_1) @[Multiplier.scala 17:38]
    node _T_3 = mul(io_src_a, io_src_b) @[Multiplier.scala 17:79]
    node _T_4 = eq(io_op, UInt<2>("h2")) @[Multiplier.scala 18:28]
    node _T_5 = asSInt(io_src_b) @[Multiplier.scala 18:90]
    node _T_6 = asUInt(_T_5) @[Multiplier.scala 18:98]
    node _T_7 = mul(io_src_a, _T_6) @[Multiplier.scala 18:78]
    node _T_8 = eq(io_op, UInt<2>("h3")) @[Multiplier.scala 19:28]
    node _T_9 = asSInt(io_src_a) @[Multiplier.scala 19:79]
    node _T_10 = asSInt(io_src_b) @[Multiplier.scala 19:97]
    node _T_11 = mul(_T_9, _T_10) @[Multiplier.scala 19:86]
    node _T_12 = asUInt(_T_11) @[Multiplier.scala 19:105]
    node _out_wire_T = mux(_T_8, _T_12, UInt<1>("h0")) @[Mux.scala 98:16]
    node _out_wire_T_1 = mux(_T_4, _T_7, _out_wire_T) @[Mux.scala 98:16]
    node _out_wire_T_2 = mux(_T_2, _T_3, _out_wire_T_1) @[Mux.scala 98:16]
    reg r_ready : UInt<1>, clock with :
      reset => (UInt<1>("h0"), r_ready) @[Multiplier.scala 25:29]
    reg r_counter : UInt<6>, clock with :
      reset => (UInt<1>("h0"), r_counter) @[Multiplier.scala 26:29]
    reg r_dividend : UInt<32>, clock with :
      reset => (UInt<1>("h0"), r_dividend) @[Multiplier.scala 27:29]
    reg r_quotient : UInt<32>, clock with :
      reset => (UInt<1>("h0"), r_quotient) @[Multiplier.scala 28:29]
    node _T_13 = eq(io_op, UInt<3>("h5")) @[Multiplier.scala 33:16]
    node _T_14 = eq(io_op, UInt<3>("h7")) @[Multiplier.scala 33:33]
    node _T_15 = or(_T_13, _T_14) @[Multiplier.scala 33:24]
    node _T_16 = eq(io_valid, UInt<1>("h1")) @[Multiplier.scala 36:23]
    node _T_17 = neq(r_counter, UInt<1>("h0")) @[Multiplier.scala 41:30]
    node _T_18 = sub(r_counter, UInt<1>("h1")) @[Multiplier.scala 42:52]
    node _T_19 = tail(_T_18, 1) @[Multiplier.scala 42:52]
    node divisor = io_src_b
    node _T_20 = dshl(divisor, _T_19) @[Multiplier.scala 42:40]
    node _T_21 = geq(r_dividend, _T_20) @[Multiplier.scala 42:29]
    node _r_dividend_T = sub(r_counter, UInt<1>("h1")) @[Multiplier.scala 43:63]
    node _r_dividend_T_1 = tail(_r_dividend_T, 1) @[Multiplier.scala 43:63]
    node _r_dividend_T_2 = dshl(divisor, _r_dividend_T_1) @[Multiplier.scala 43:51]
    node _r_dividend_T_3 = sub(r_dividend, _r_dividend_T_2) @[Multiplier.scala 43:41]
    node _r_dividend_T_4 = tail(_r_dividend_T_3, 1) @[Multiplier.scala 43:41]
    node _r_quotient_T = sub(r_counter, UInt<1>("h1")) @[Multiplier.scala 44:59]
    node _r_quotient_T_1 = tail(_r_quotient_T, 1) @[Multiplier.scala 44:59]
    node _r_quotient_T_2 = dshl(UInt<1>("h1"), _r_quotient_T_1) @[Multiplier.scala 44:47]
    node _r_quotient_T_3 = add(r_quotient, _r_quotient_T_2) @[Multiplier.scala 44:41]
    node _r_quotient_T_4 = tail(_r_quotient_T_3, 1) @[Multiplier.scala 44:41]
    node _GEN_0 = mux(_T_21, _r_dividend_T_4, r_dividend) @[Multiplier.scala 42:59 Multiplier.scala 43:27 Multiplier.scala 27:29]
    node _GEN_1 = mux(_T_21, _r_quotient_T_4, r_quotient) @[Multiplier.scala 42:59 Multiplier.scala 44:27 Multiplier.scala 28:29]
    node _GEN_2 = mux(_T_21, r_ready, UInt<1>("h1")) @[Multiplier.scala 42:59 Multiplier.scala 25:29 Multiplier.scala 45:34]
    node _r_counter_T = sub(r_counter, UInt<1>("h1")) @[Multiplier.scala 46:37]
    node _r_counter_T_1 = tail(_r_counter_T, 1) @[Multiplier.scala 46:37]
    node _r_ready_T = eq(r_counter, UInt<1>("h1")) @[Multiplier.scala 47:38]
    node _GEN_3 = mux(_T_17, _GEN_0, r_dividend) @[Multiplier.scala 41:38 Multiplier.scala 27:29]
    node _GEN_4 = mux(_T_17, _GEN_1, r_quotient) @[Multiplier.scala 41:38 Multiplier.scala 28:29]
    node _GEN_5 = mux(_T_17, _r_ready_T, r_ready) @[Multiplier.scala 41:38 Multiplier.scala 47:24 Multiplier.scala 25:29]
    node _GEN_6 = mux(_T_17, _r_counter_T_1, r_counter) @[Multiplier.scala 41:38 Multiplier.scala 46:24 Multiplier.scala 26:29]
    node _GEN_7 = mux(_T_17, UInt<1>("h0"), UInt<1>("h1")) @[Multiplier.scala 41:38 Multiplier.scala 30:21 Multiplier.scala 48:37]
    node _GEN_8 = mux(_T_16, UInt<1>("h0"), _GEN_5) @[Multiplier.scala 36:32 Multiplier.scala 37:24]
    node _GEN_9 = mux(_T_16, UInt<6>("h20"), _GEN_6) @[Multiplier.scala 36:32 Multiplier.scala 38:24]
    node dividend = io_src_a
    node _GEN_10 = mux(_T_16, dividend, _GEN_3) @[Multiplier.scala 36:32 Multiplier.scala 39:24]
    node _GEN_11 = mux(_T_16, UInt<1>("h0"), _GEN_4) @[Multiplier.scala 36:32 Multiplier.scala 40:24]
    node _GEN_12 = mux(_T_16, UInt<1>("h0"), _GEN_7) @[Multiplier.scala 36:32 Multiplier.scala 30:21]
    node _GEN_13 = mux(_T_15, _GEN_8, r_ready) @[Multiplier.scala 33:41 Multiplier.scala 25:29]
    node _GEN_14 = mux(_T_15, _GEN_9, r_counter) @[Multiplier.scala 33:41 Multiplier.scala 26:29]
    node _GEN_15 = mux(_T_15, _GEN_10, r_dividend) @[Multiplier.scala 33:41 Multiplier.scala 27:29]
    node _GEN_16 = mux(_T_15, _GEN_11, r_quotient) @[Multiplier.scala 33:41 Multiplier.scala 28:29]
    node _GEN_17 = mux(_T_15, _GEN_12, UInt<1>("h0")) @[Multiplier.scala 33:41 Multiplier.scala 30:21]
    node _T_22 = eq(io_op, UInt<1>("h0")) @[Multiplier.scala 54:16]
    node out_wire = _out_wire_T_2 @[Multiplier.scala 21:24 Multiplier.scala 22:14]
    node _io_output_bits_T = bits(out_wire, 31, 0) @[Multiplier.scala 55:35]
    node _T_23 = eq(io_op, UInt<1>("h1")) @[Multiplier.scala 57:22]
    node _T_24 = eq(io_op, UInt<1>("h1")) @[Multiplier.scala 57:39]
    node _T_25 = or(_T_23, _T_24) @[Multiplier.scala 57:30]
    node _T_26 = eq(io_op, UInt<2>("h2")) @[Multiplier.scala 57:56]
    node _T_27 = or(_T_25, _T_26) @[Multiplier.scala 57:47]
    node _T_28 = eq(io_op, UInt<2>("h3")) @[Multiplier.scala 57:73]
    node _T_29 = or(_T_27, _T_28) @[Multiplier.scala 57:64]
    node _io_output_bits_T_1 = bits(out_wire, 63, 32) @[Multiplier.scala 58:35]
    node _T_30 = eq(io_op, UInt<3>("h5")) @[Multiplier.scala 60:22]
    node _T_31 = eq(io_op, UInt<3>("h7")) @[Multiplier.scala 62:22]
    node _GEN_18 = mux(_T_31, r_dividend, UInt<1>("h0")) @[Multiplier.scala 62:30 Multiplier.scala 63:24 Multiplier.scala 65:24]
    node _GEN_19 = mux(_T_30, r_quotient, _GEN_18) @[Multiplier.scala 60:30 Multiplier.scala 61:24]
    node _GEN_20 = mux(_T_29, _io_output_bits_T_1, _GEN_19) @[Multiplier.scala 57:81 Multiplier.scala 58:24]
    node _GEN_21 = mux(_T_29, UInt<1>("h1"), _GEN_17) @[Multiplier.scala 57:81 Multiplier.scala 59:25]
    node _GEN_22 = mux(_T_22, _io_output_bits_T, _GEN_20) @[Multiplier.scala 54:24 Multiplier.scala 55:24]
    node _GEN_23 = mux(_T_22, UInt<1>("h1"), _GEN_21) @[Multiplier.scala 54:24 Multiplier.scala 56:25]
    io_ready <= r_ready @[Multiplier.scala 53:18]
    io_output_valid <= _GEN_23
    io_output_bits <= _GEN_22
    r_ready <= mux(reset, UInt<1>("h1"), _GEN_13) @[Multiplier.scala 25:29 Multiplier.scala 25:29]
    r_counter <= mux(reset, UInt<6>("h20"), _GEN_14) @[Multiplier.scala 26:29 Multiplier.scala 26:29]
    r_dividend <= mux(reset, UInt<32>("h0"), bits(_GEN_15, 31, 0)) @[Multiplier.scala 27:29 Multiplier.scala 27:29]
    r_quotient <= mux(reset, UInt<32>("h0"), bits(_GEN_16, 31, 0)) @[Multiplier.scala 28:29 Multiplier.scala 28:29]
