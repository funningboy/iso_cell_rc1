module SC_INV  (A, Y);
  input  A;
  output Y;
     not (Y, A);
endmodule

module SC_BUF  (A, Y);
  input  A;
  output Y;
     buf (Y, A);
endmodule

module SC_AND (A, B, Y);
  input  A, B;
  output Y;
     and (Y, A, B);
endmodule

module SC_NOR (A, B, Y);
  input  A, B;
  output Y;
     nor (Y, A, B);
endmodule

module Iso_TH_1P (A, Ib, Y);
  input  A, Ib;
  output Y;
     nand (Y, Ib, A);
endmodule

module Iso_FL_1P (A, Ib, Y);
  input  A, Ib;
  output Y;
     nor (Y, Ib, A);
endmodule
