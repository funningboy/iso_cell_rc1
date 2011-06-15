module BUF(out, in);
  input in;
  output out;
  SC_BUF x1(.A(in), .Y(out));
endmodule
 
module SC_UNIT(A, B, Y1, Y2);
input  A, B;
output Y1, Y2;
wire  Y2, Y1, B, A;
  SC_AND x1(.A(A), .B(B), .Y(Y1));
  SC_NOR x2(.A(A), .B(B), .Y(Y2));
endmodule

module SC_UNIT_2X2(A, Y);
input   [3:0] A;
output  [3:0] Y;
wire  x3_net, x2_net;
wire   [1:0] x1_net;
wire   [3:0] Y;
wire   [3:0] A;
  SC_UNIT x1(.A(A[0]), .B(A[1]), .Y1(x1_net[0]), .Y2(x1_net[1]));
  SC_UNIT x2(.A(A[2]), .B(x1_net[0]), .Y1(x2_net), .Y2(Y[0]));
  SC_UNIT x3(.A(A[3]), .B(x1_net[1]), .Y1(x3_net), .Y2(Y[1]));
  SC_UNIT x4(.A(x2_net), .B(x3_net), .Y1(Y[2]), .Y2(Y[3]));
endmodule

module SC_UNIT17(ISO_CONTROL_0, A, B, Y1, Y2);
input  ISO_CONTROL_0, A, B;
output Y1, Y2;
wire  A_iso_net0, B_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A_iso_net0), .B(B_iso_net0), .Y(Y1));
  SC_NOR x2(.A(A_iso_net0), .B(B_iso_net0), .Y(Y2));
  Iso_FL_1P CPF_ISO__cell_0(.A(B), .Ib(ISO_CONTROL_0), .Y(
    B_iso_net0));
  Iso_FL_1P CPF_ISO__cell_1(.A(A), .Ib(~ISO_CONTROL_0), .Y(
    A_iso_net0));
endmodule

module SC_UNIT15(ISO_CONTROL_4, A, B, Y1, Y2);
input  ISO_CONTROL_4, A, B;
output Y1, Y2;
wire   A_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A_iso_net0), .B(B), .Y(Y1));
  SC_NOR x2(.A(A_iso_net0), .B(B), .Y(Y2));
  Iso_FL_1P CPF_ISO__cell_3(.A(A), .Ib(A), .Y(
    A_iso_net0));
endmodule

module SC_UNIT16(ISO_CONTROL_3, A, B, Y1, Y2);
input  ISO_CONTROL_3, A, B;
output Y1, Y2;
wire   A_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A_iso_net0), .B(B), .Y(Y1));
  SC_NOR x2(.A(A_iso_net0), .B(B), .Y(Y2));
  Iso_FL_1P CPF_ISO__cell_2(.A(A), .Ib(~ISO_CONTROL_3), .Y(
    A_iso_net0));
endmodule

module SC_UNIT_2X27(ISO_CONTROL_1, A, Y);
input  ISO_CONTROL_1;
input   [3:0] A;
output  [3:0] Y;
wire   x3_net, x2_net;
wire   [1:0] x1_net;
wire   [3:0] Y;
wire   [3:0] A;
  SC_UNIT17 x1(.ISO_CONTROL_0(ISO_CONTROL_1), .A(A[0]), .B(A[1]),
     .Y1(x1_net[0]), .Y2(x1_net[1]));
  SC_UNIT15 x2(.ISO_CONTROL_4(ISO_CONTROL_1), .A(A[2]), .B(
    x1_net[0]), .Y1(x2_net), .Y2(Y[0]));
  SC_UNIT16 x3(.ISO_CONTROL_3(ISO_CONTROL_1), .A(A[3]), .B(
    x1_net[1]), .Y1(x3_net), .Y2(Y[1]));
  SC_UNIT x4(.A(x2_net), .B(x3_net), .Y1(Y[2]), .Y2(Y[3]));
endmodule

module SC_UNIT_4X4(ISO_CONTROL_2, A, Y);
input  ISO_CONTROL_2;
input   [7:0] A;
output  [7:0] Y;
wire   [1:0] x3_net;
wire   [1:0] x2_net;
wire   [3:0] x1_net;
wire   [7:0] Y;
wire   [7:0] A;
  SC_UNIT_2X2 u1(.A({ A[3:0] }), .Y({ x1_net[3:0] }));
  SC_UNIT_2X2 u2(.A({ A[5:4] ,  x1_net[1:0] }), .Y({ Y[1:0] ,  x2_net[1:0] }));
  SC_UNIT_2X2 u3(.A({ A[7:6] ,  x1_net[3:2] }), .Y({ Y[3:2] ,  x3_net[1:0] }));
  SC_UNIT_2X27 u4(.ISO_CONTROL_1(ISO_CONTROL_2), .A({ x2_net[1:0] ,  x3_net[1:0] }), .Y({ Y[7:4] }));
endmodule

module SC_UNIT13(ISO_CONTROL_8, A, B, Y1, Y2);
input  ISO_CONTROL_8, A, B;
output Y1, Y2;
wire  A_iso_net0, B_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A_iso_net0), .B(B_iso_net0), .Y(Y1));
  SC_NOR x2(.A(A_iso_net0), .B(B_iso_net0), .Y(Y2));
  Iso_FL_1P CPF_ISO__cell_6(.A(B), .Ib(ISO_CONTROL_8), .Y(
    B_iso_net0));
  Iso_FL_1P CPF_ISO__cell_7(.A(A), .Ib(Y1), .Y(
    A_iso_net0));
endmodule

module SC_UNIT1(ISO_CONTROL_27, A, B, Y1, Y2);
input  ISO_CONTROL_27, A, B;
output Y1, Y2;
wire   A_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A_iso_net0), .B(B), .Y(Y1));
  SC_NOR x2(.A(A_iso_net0), .B(B), .Y(Y2));
  Iso_FL_1P CPF_ISO__cell_23(.A(A), .Ib(ISO_CONTROL_27), .Y(
    A_iso_net0));
endmodule

module SC_UNIT2(ISO_CONTROL_26, A, B, Y1, Y2);
input  ISO_CONTROL_26, A, B;
output Y1, Y2;
wire   A_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A_iso_net0), .B(B), .Y(Y1));
  SC_NOR x2(.A(A_iso_net0), .B(B), .Y(Y2));
  Iso_FL_1P CPF_ISO__cell_22(.A(A), .Ib(ISO_CONTROL_26), .Y(
    A_iso_net0));
endmodule

module SC_UNIT_2X21(ISO_CONTROL_9, A, Y);
input  ISO_CONTROL_9;
input   [3:0] A;
output  [3:0] Y;
wire   x3_net, x2_net;
wire   [1:0] x1_net;
wire   [3:0] Y;
wire   [3:0] A;
  SC_UNIT13 x1(.ISO_CONTROL_8(ISO_CONTROL_9), .A(A[0]), .B(A[1]),
     .Y1(x1_net[0]), .Y2(x1_net[1]));
  SC_UNIT1 x2(.ISO_CONTROL_27(ISO_CONTROL_9), .A(A[2]), .B(
    x1_net[0]), .Y1(x2_net), .Y2(Y[0]));
  SC_UNIT2 x3(.ISO_CONTROL_26(ISO_CONTROL_9), .A(A[3]), .B(
    x1_net[1]), .Y1(x3_net), .Y2(Y[1]));
  SC_UNIT x4(.A(x2_net), .B(x3_net), .Y1(Y[2]), .Y2(Y[3]));
endmodule

module SC_UNIT14(ISO_CONTROL_5, A, B, Y1, Y2);
input  ISO_CONTROL_5, A, B;
output Y1, Y2;
wire  A_iso_net0, B_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A), .B(B_iso_net0), .Y(Y1));
  SC_NOR x2(.A(A), .B(B_iso_net0), .Y(Y2));
  Iso_TH_1P CPF_ISO__cell_4(.A(B), .Ib(ISO_CONTROL_5), .Y(
    B_iso_net0));
endmodule

module SC_UNIT_2X26(ISO_CONTROL_6, A, Y);
input  ISO_CONTROL_6;
input   [3:0] A;
output  [3:0] Y;
wire   x3_net, x2_net;
wire   [1:0] x1_net;
wire   [3:0] Y;
wire   [3:0] A;
  SC_UNIT14 x1(.ISO_CONTROL_5(ISO_CONTROL_6), .A(A[0]), .B(A[1]),
     .Y1(x1_net[0]), .Y2(x1_net[1]));
  SC_UNIT x2(.A(A[2]), .B(x1_net[0]), .Y1(x2_net), .Y2(Y[0]));
  SC_UNIT x3(.A(A[3]), .B(x1_net[1]), .Y1(x3_net), .Y2(Y[1]));
  SC_UNIT x4(.A(x2_net), .B(x3_net), .Y1(Y[2]), .Y2(Y[3]));
endmodule

module SC_UNIT_4X41(ISO_CONTROL_7, A, Y);
input  ISO_CONTROL_7;
input   [7:0] A;
output  [7:0] Y;
wire  CPF_ISO__cell_4_enable_net0;
wire   [1:0] x3_net;
wire   [1:0] x2_net;
wire   [3:0] x1_net;
wire   [7:0] Y;
wire   [7:0] A;
  SC_UNIT_2X2 u1(.A({ A[3:0] }), .Y({ x1_net[3:0] }));
  SC_UNIT_2X2 u2(.A({ A[5:4] ,  x1_net[1:0] }), .Y({ Y[1:0] ,  x2_net[1:0] }));
  SC_UNIT_2X21 u3(.ISO_CONTROL_9(CPF_ISO__cell_4_enable_net0), .A({ A[7:6] ,  x1_net[3:2] }), .Y({ Y[3:2] ,  x3_net[1:0] }));
  SC_UNIT_2X26 u4(.ISO_CONTROL_6(CPF_ISO__cell_4_enable_net0), .A({ x2_net[1:0] ,  x3_net[1:0] }), .Y({ Y[7:4] }));
   not u5(CPF_ISO__cell_4_enable_net0, ISO_CONTROL_7);
endmodule

module SC_UNIT3(ISO_CONTROL_25, A, B, Y1, Y2);
input  ISO_CONTROL_25, A, B;
output Y1, Y2;
wire  A_iso_net0, B_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A_iso_net0), .B(B), .Y(Y1));
  SC_NOR x2(.A(A_iso_net0), .B(B), .Y(Y2));
  Iso_TH_1P CPF_ISO__cell_21(.A(A), .Ib(ISO_CONTROL_25), .Y(
    A_iso_net0));
endmodule

module SC_UNIT4(ISO_CONTROL_24, A, B, Y1, Y2);
input  ISO_CONTROL_24, A, B;
output Y1, Y2;
wire  A_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A_iso_net0), .B(B), .Y(Y1));
  SC_NOR x2(.A(A_iso_net0), .B(B), .Y(Y2));
  Iso_TH_1P CPF_ISO__cell_19(.A(A), .Ib(ISO_CONTROL_24), .Y(
    A_iso_net0));
endmodule

module SC_UNIT5(ISO_CONTROL_21, A, B, Y1, Y2);
input  ISO_CONTROL_21, A, B;
output Y1, Y2;
wire   A_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A_iso_net0), .B(B), .Y(Y1));
  SC_NOR x2(.A(A_iso_net0), .B(B), .Y(Y2));
  Iso_TH_1P CPF_ISO__cell_18(.A(A), .Ib(ISO_CONTROL_21), .Y(
    A_iso_net0));
endmodule

module SC_UNIT_2X22(ISO_CONTROL_22, A, Y);
input  ISO_CONTROL_22;
input   [3:0] A;
output  [3:0] Y;
wire   x3_net, x2_net;
wire   [1:0] x1_net;
wire   [3:0] Y;
wire   [3:0] A;
  SC_UNIT3 x1(.ISO_CONTROL_25(ISO_CONTROL_22), .A(A[0]), .B(A[1]),
     .Y1(x1_net[0]), .Y2(x1_net[1]));
  SC_UNIT4 x2(.ISO_CONTROL_24(ISO_CONTROL_22), .A(A[2]), .B(
    x1_net[0]), .Y1(x2_net), .Y2(Y[0]));
  SC_UNIT5 x3(.ISO_CONTROL_21(ISO_CONTROL_22), .A(A[3]), .B(
    x1_net[1]), .Y1(x3_net), .Y2(Y[1]));
  SC_UNIT x4(.A(x2_net), .B(x3_net), .Y1(Y[2]), .Y2(Y[3]));
endmodule

module SC_UNIT_4X42(ISO_CONTROL_23, A, Y);
input  ISO_CONTROL_23;
input   [7:0] A;
output  [7:0] Y;
wire   [1:0] x3_net;
wire   [1:0] x2_net;
wire   [3:0] x1_net;
wire   [7:0] Y;
wire   [7:0] A;
  SC_UNIT_2X22 u1(.ISO_CONTROL_22(ISO_CONTROL_23), .A({ A[3:0] }), .Y({ x1_net[3:0] }));
  SC_UNIT_2X2 u2(.A({ A[5:4] ,  x1_net[1:0] }), .Y({ Y[1:0] ,  x2_net[1:0] }));
  SC_UNIT_2X2 u3(.A({ A[7:6] ,  x1_net[3:2] }), .Y({ Y[3:2] ,  x3_net[1:0] }));
  SC_UNIT_2X2 u4(.A({ x2_net[1:0] ,  x3_net[1:0] }), .Y({ Y[7:4] }));
endmodule

module SC_UNIT8(ISO_CONTROL_18, A, B, Y1, Y2);
input  ISO_CONTROL_18, A, B;
output Y1, Y2;
wire  A_iso_net0, B_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A_iso_net0), .B(B_iso_net0), .Y(Y1));
  SC_NOR x2(.A(A_iso_net0), .B(B_iso_net0), .Y(Y2));
  Iso_FL_1P CPF_ISO__cell_14(.A(B), .Ib(ISO_CONTROL_18), .Y(
    B_iso_net0));
  Iso_FL_1P CPF_ISO__cell_15(.A(A), .Ib(ISO_CONTROL_18), .Y(
    A_iso_net0));
endmodule

module SC_UNIT9(ISO_CONTROL_17, A, B, Y1, Y2);
input  ISO_CONTROL_17, A, B;
output Y1, Y2;
wire   A_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A_iso_net0), .B(B), .Y(Y1));
  SC_NOR x2(.A(A_iso_net0), .B(B), .Y(Y2));
  Iso_FL_1P CPF_ISO__cell_13(.A(A), .Ib(ISO_CONTROL_17), .Y(
    A_iso_net0));
endmodule

module SC_UNIT10(ISO_CONTROL_15, A, B, Y1, Y2);
input  ISO_CONTROL_15, A, B;
output Y1, Y2;
wire   A_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A_iso_net0), .B(B), .Y(Y1));
  SC_NOR x2(.A(A_iso_net0), .B(B), .Y(Y2));
  Iso_FL_1P CPF_ISO__cell_12(.A(A), .Ib(ISO_CONTROL_15), .Y(
    A_iso_net0));
endmodule

module SC_UNIT_2X24(ISO_CONTROL_16, A, Y);
input  ISO_CONTROL_16;
input   [3:0] A;
output  [3:0] Y;
wire   x3_net, x2_net;
wire   [1:0] x1_net;
wire   [3:0] Y;
wire   [3:0] A;
  SC_UNIT8 x1(.ISO_CONTROL_18(ISO_CONTROL_16), .A(A[0]), .B(A[1]),
     .Y1(x1_net[0]), .Y2(x1_net[1]));
  SC_UNIT9 x2(.ISO_CONTROL_17(ISO_CONTROL_16), .A(A[2]), .B(
    x1_net[0]), .Y1(x2_net), .Y2(Y[0]));
  SC_UNIT10 x3(.ISO_CONTROL_15(ISO_CONTROL_16), .A(A[3]), .B(
    x1_net[1]), .Y1(x3_net), .Y2(Y[1]));
  SC_UNIT x4(.A(x2_net), .B(x3_net), .Y1(Y[2]), .Y2(Y[3]));
endmodule

module SC_UNIT11(ISO_CONTROL_13, A, B, Y1, Y2);
input  ISO_CONTROL_13, A, B;
output Y1, Y2;
wire  A_iso_net0, B_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A_iso_net0), .B(B_iso_net0), .Y(Y1));
  SC_NOR x2(.A(A_iso_net0), .B(B_iso_net0), .Y(Y2));
  Iso_TH_1P CPF_ISO__cell_10(.A(B), .Ib(ISO_CONTROL_13), .Y(
    B_iso_net0));
  Iso_TH_1P CPF_ISO__cell_11(.A(A), .Ib(ISO_CONTROL_13), .Y(
    A_iso_net0));
endmodule

module SC_UNIT_2X25(ISO_CONTROL_14, A, Y);
input  ISO_CONTROL_14;
input   [3:0] A;
output  [3:0] Y;
wire  x3_net, x2_net;
wire   [1:0] x1_net;
wire   [3:0] Y;
wire   [3:0] A;
  SC_UNIT11 x1(.ISO_CONTROL_13(ISO_CONTROL_14), .A(A[0]), .B(A[1]),
     .Y1(x1_net[0]), .Y2(x1_net[1]));
  SC_UNIT x2(.A(A[2]), .B(x1_net[0]), .Y1(x2_net), .Y2(Y[0]));
  SC_UNIT x3(.A(A[3]), .B(x1_net[1]), .Y1(x3_net), .Y2(Y[1]));
  SC_UNIT x4(.A(x2_net), .B(x3_net), .Y1(Y[2]), .Y2(Y[3]));
endmodule

module SC_UNIT12(ISO_CONTROL_10, A, B, Y1, Y2);
input  ISO_CONTROL_10, A, B;
output Y1, Y2;
wire  A_iso_net0, B_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A_iso_net0), .B(B_iso_net0), .Y(Y1));
  SC_NOR x2(.A(A_iso_net0), .B(B_iso_net0), .Y(Y2));
  Iso_TH_1P CPF_ISO__cell_8(.A(B), .Ib(ISO_CONTROL_10), .Y(
    B_iso_net0));
  Iso_TH_1P CPF_ISO__cell_9(.A(A), .Ib(ISO_CONTROL_10), .Y(
    A_iso_net0));
endmodule

module SC_UNIT6(ISO_CONTROL_20, A, B, Y1, Y2);
input  ISO_CONTROL_20, A, B;
output Y1, Y2;
wire   A_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A_iso_net0), .B(B), .Y(Y1));
  SC_NOR x2(.A(A_iso_net0), .B(B), .Y(Y2));
  Iso_TH_1P CPF_ISO__cell_17(.A(A), .Ib(ISO_CONTROL_20), .Y(
    A_iso_net0));
endmodule

module SC_UNIT7(ISO_CONTROL_19, A, B, Y1, Y2);
input  ISO_CONTROL_19, A, B;
output Y1, Y2;
wire   A_iso_net0, Y2, Y1, B, A;
  SC_AND x1(.A(A_iso_net0), .B(B), .Y(Y1));
  SC_NOR x2(.A(A_iso_net0), .B(B), .Y(Y2));
  Iso_TH_1P CPF_ISO__cell_16(.A(A), .Ib(ISO_CONTROL_19), .Y(
    A_iso_net0));
endmodule

module SC_UNIT_2X23(ISO_CONTROL_11, A, Y);
input  ISO_CONTROL_11;
input   [3:0] A;
output  [3:0] Y;
wire   x3_net, x2_net;
wire   [1:0] x1_net;
wire   [3:0] Y;
wire   [3:0] A;
  SC_UNIT12 x1(.ISO_CONTROL_10(ISO_CONTROL_11), .A(A[0]), .B(A[1]),
     .Y1(x1_net[0]), .Y2(x1_net[1]));
  SC_UNIT6 x2(.ISO_CONTROL_20(ISO_CONTROL_11), .A(A[2]), .B(
    x1_net[0]), .Y1(x2_net), .Y2(Y[0]));
  SC_UNIT7 x3(.ISO_CONTROL_19(ISO_CONTROL_11), .A(A[3]), .B(
    x1_net[1]), .Y1(x3_net), .Y2(Y[1]));
  SC_UNIT x4(.A(x2_net), .B(x3_net), .Y1(Y[2]), .Y2(Y[3]));
endmodule

module SC_UNIT_4X43(ISO_CONTROL_12, A, Y);
input  ISO_CONTROL_12;
input   [7:0] A;
output  [7:0] Y;
wire  CPF_ISO__cell_8_enable_net1;
wire   [1:0] x3_net;
wire   [1:0] x2_net;
wire   [3:0] x1_net;
wire   [7:0] Y;
wire   [7:0] A;
  SC_UNIT_2X24 u1(.ISO_CONTROL_16(ISO_CONTROL_12), .A({ A[3:0] }), .Y({ x1_net[3:0] }));
  SC_UNIT_2X25 u2(.ISO_CONTROL_14(CPF_ISO__cell_8_enable_net1), .A({ A[5:4] ,  x1_net[1:0] }), .Y({ Y[1:0] ,  x2_net[1:0] }));
  SC_UNIT_2X23 u3(.ISO_CONTROL_11(ISO_CONTROL_12), .A({ A[7:6] ,  x1_net[3:2] }), .Y({ Y[3:2] ,  x3_net[1:0] }));
  SC_UNIT_2X2 u4(.A({ x2_net[1:0] ,  x3_net[1:0] }), .Y({ Y[7:4] }));
  BUF u5(CPF_ISO__cell_8_enable_net1, ISO_CONTROL_12);
endmodule

module Big1(A, Y, iso);
input  iso;
input   [15:0] A;
output  [15:0] Y;
wire  ISO_CONTROL_2_inv0, iso;
wire   [3:0] x3_net;
wire   [3:0] x2_net;
wire   [7:0] x1_net;
wire   [15:0] Y;
wire   [15:0] A;
  SC_UNIT_4X4 u1(.ISO_CONTROL_2(ISO_CONTROL_2_inv0), .A({ A[7:0] }), .Y({ x1_net[7:0] }));
  SC_UNIT_4X41 u2(.ISO_CONTROL_7(ISO_CONTROL_2_inv0), .A({ A[11:8] ,  x1_net[3:0] }), .Y({ Y[3:0] ,  x2_net[3:0] }));
  SC_UNIT_4X42 u3(.ISO_CONTROL_23(ISO_CONTROL_2_inv0), .A({ A[15:12] ,  x1_net[7:4] }), .Y({ Y[7:4] ,  x3_net[3:0] }));
  SC_UNIT_4X43 u4(.ISO_CONTROL_12(ISO_CONTROL_2_inv0), .A({ x2_net[3:0] ,  x3_net[3:0] }), .Y({ Y[15:8] }));
  not ISO_CONTROL_2ins_0(ISO_CONTROL_2_inv0, iso);
endmodule

