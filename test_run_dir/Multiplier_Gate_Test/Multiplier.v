module Multiplier(
  input         clock,
  input         reset,
  input  [31:0] io_src_a,
  input  [31:0] io_src_b,
  input  [4:0]  io_op,
  input         io_valid,
  output        io_ready,
  output        io_output_valid,
  output [31:0] io_output_bits
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
`endif // RANDOMIZE_REG_INIT
  wire  _T = io_op == 5'h0; // @[Multiplier.scala 17:30]
  wire  _T_1 = io_op == 5'h1; // @[Multiplier.scala 17:47]
  wire  _T_2 = io_op == 5'h0 | io_op == 5'h1; // @[Multiplier.scala 17:38]
  wire [63:0] _T_3 = $signed(io_src_a) * $signed(io_src_b); // @[Multiplier.scala 17:78]
  wire  _T_4 = io_op == 5'h2; // @[Multiplier.scala 18:28]
  wire [31:0] _T_5 = io_src_b; // @[Multiplier.scala 18:90]
  wire [63:0] _T_7 = $signed(io_src_a) * $signed(io_src_b); // @[Multiplier.scala 18:78]
  wire  _T_8 = io_op == 5'h3; // @[Multiplier.scala 19:28]
  wire [31:0] _T_9 = io_src_a; // @[Multiplier.scala 19:79]
  wire [63:0] _T_12 = io_src_a * io_src_b; // @[Multiplier.scala 19:105]
  wire [63:0] _out_wire_T = _T_8 ? $signed(_T_12) : $signed(64'sh0); // @[Mux.scala 98:16]
  wire [63:0] _out_wire_T_1 = _T_4 ? $signed(_T_7) : $signed(_out_wire_T); // @[Mux.scala 98:16]
  wire [63:0] out_wire = _T_2 ? $signed(_T_3) : $signed(_out_wire_T_1); // @[Mux.scala 98:16]
  reg  r_ready; // @[Multiplier.scala 25:29]
  reg [5:0] r_counter; // @[Multiplier.scala 26:29]
  reg [31:0] r_dividend; // @[Multiplier.scala 27:29]
  reg [31:0] r_quotient; // @[Multiplier.scala 28:29]
  wire  _T_13 = io_op == 5'h5; // @[Multiplier.scala 33:16]
  wire  _T_14 = io_op == 5'h7; // @[Multiplier.scala 33:33]
  wire [5:0] _T_19 = r_counter - 6'h1; // @[Multiplier.scala 42:52]
  wire [94:0] _GEN_24 = {{63'd0}, _T_5}; // @[Multiplier.scala 42:40]
  wire [94:0] _T_20 = _GEN_24 << _T_19; // @[Multiplier.scala 42:40]
  wire [94:0] _GEN_25 = {{63'd0}, r_dividend}; // @[Multiplier.scala 42:29]
  wire [94:0] _r_dividend_T_4 = _GEN_25 - _T_20; // @[Multiplier.scala 43:41]
  wire [63:0] _r_quotient_T_2 = 64'h1 << _T_19; // @[Multiplier.scala 44:47]
  wire [63:0] _GEN_28 = {{32'd0}, r_quotient}; // @[Multiplier.scala 44:41]
  wire [63:0] _r_quotient_T_4 = _GEN_28 + _r_quotient_T_2; // @[Multiplier.scala 44:41]
  wire [94:0] _GEN_0 = _GEN_25 >= _T_20 ? _r_dividend_T_4 : {{63'd0}, r_dividend}; // @[Multiplier.scala 42:59 Multiplier.scala 43:27 Multiplier.scala 27:29]
  wire [63:0] _GEN_1 = _GEN_25 >= _T_20 ? _r_quotient_T_4 : {{32'd0}, r_quotient}; // @[Multiplier.scala 42:59 Multiplier.scala 44:27 Multiplier.scala 28:29]
  wire [94:0] _GEN_3 = r_counter != 6'h0 ? _GEN_0 : {{63'd0}, r_dividend}; // @[Multiplier.scala 41:38 Multiplier.scala 27:29]
  wire [63:0] _GEN_4 = r_counter != 6'h0 ? _GEN_1 : {{32'd0}, r_quotient}; // @[Multiplier.scala 41:38 Multiplier.scala 28:29]
  wire  _GEN_5 = r_counter != 6'h0 ? r_counter == 6'h1 : r_ready; // @[Multiplier.scala 41:38 Multiplier.scala 47:24 Multiplier.scala 25:29]
  wire  _GEN_7 = r_counter != 6'h0 ? 1'h0 : 1'h1; // @[Multiplier.scala 41:38 Multiplier.scala 30:21 Multiplier.scala 48:37]
  wire  _GEN_8 = io_valid ? 1'h0 : _GEN_5; // @[Multiplier.scala 36:32 Multiplier.scala 37:24]
  wire [94:0] _GEN_10 = io_valid ? {{63'd0}, _T_9} : _GEN_3; // @[Multiplier.scala 36:32 Multiplier.scala 39:24]
  wire [63:0] _GEN_11 = io_valid ? 64'h0 : _GEN_4; // @[Multiplier.scala 36:32 Multiplier.scala 40:24]
  wire  _GEN_12 = io_valid ? 1'h0 : _GEN_7; // @[Multiplier.scala 36:32 Multiplier.scala 30:21]
  wire  _GEN_13 = io_op == 5'h5 | io_op == 5'h7 ? _GEN_8 : r_ready; // @[Multiplier.scala 33:41 Multiplier.scala 25:29]
  wire [94:0] _GEN_15 = io_op == 5'h5 | io_op == 5'h7 ? _GEN_10 : {{63'd0}, r_dividend}; // @[Multiplier.scala 33:41 Multiplier.scala 27:29]
  wire [63:0] _GEN_16 = io_op == 5'h5 | io_op == 5'h7 ? _GEN_11 : {{32'd0}, r_quotient}; // @[Multiplier.scala 33:41 Multiplier.scala 28:29]
  wire  _GEN_17 = (io_op == 5'h5 | io_op == 5'h7) & _GEN_12; // @[Multiplier.scala 33:41 Multiplier.scala 30:21]
  wire [31:0] _io_output_bits_T_1 = out_wire[31:0]; // @[Multiplier.scala 53:42]
  wire [31:0] _io_output_bits_T_3 = out_wire[63:32]; // @[Multiplier.scala 56:43]
  wire [31:0] _GEN_18 = _T_14 ? $signed(r_dividend) : $signed(32'sh0); // @[Multiplier.scala 60:30 Multiplier.scala 61:24 Multiplier.scala 63:24]
  wire [31:0] _GEN_19 = _T_13 ? $signed(r_quotient) : $signed(_GEN_18); // @[Multiplier.scala 58:30 Multiplier.scala 59:24]
  wire [31:0] _GEN_20 = _T_1 & _T_1 & _T_4 & _T_8 ? $signed(_io_output_bits_T_3) : $signed(_GEN_19); // @[Multiplier.scala 55:81 Multiplier.scala 56:24]
  wire  _GEN_21 = _T_1 & _T_1 & _T_4 & _T_8 | _GEN_17; // @[Multiplier.scala 55:81 Multiplier.scala 57:25]
  assign io_ready = r_ready; // @[Multiplier.scala 51:18]
  assign io_output_valid = _T | _GEN_21; // @[Multiplier.scala 52:24 Multiplier.scala 54:25]
  assign io_output_bits = _T ? $signed(_io_output_bits_T_1) : $signed(_GEN_20); // @[Multiplier.scala 52:24 Multiplier.scala 53:24]
  always @(posedge clock) begin
    r_ready <= reset | _GEN_13; // @[Multiplier.scala 25:29 Multiplier.scala 25:29]
    if (reset) begin // @[Multiplier.scala 26:29]
      r_counter <= 6'h20; // @[Multiplier.scala 26:29]
    end else if (io_op == 5'h5 | io_op == 5'h7) begin // @[Multiplier.scala 33:41]
      if (io_valid) begin // @[Multiplier.scala 36:32]
        r_counter <= 6'h20; // @[Multiplier.scala 38:24]
      end else if (r_counter != 6'h0) begin // @[Multiplier.scala 41:38]
        r_counter <= _T_19; // @[Multiplier.scala 46:24]
      end
    end
    if (reset) begin // @[Multiplier.scala 27:29]
      r_dividend <= 32'h0; // @[Multiplier.scala 27:29]
    end else begin
      r_dividend <= _GEN_15[31:0];
    end
    if (reset) begin // @[Multiplier.scala 28:29]
      r_quotient <= 32'h0; // @[Multiplier.scala 28:29]
    end else begin
      r_quotient <= _GEN_16[31:0];
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  r_ready = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  r_counter = _RAND_1[5:0];
  _RAND_2 = {1{`RANDOM}};
  r_dividend = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  r_quotient = _RAND_3[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
