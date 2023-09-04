module circuit1 (A, B, C, D);
  output D;
  input A, B, C;
  wire bottom_wire;

  and G_bottom(bottom_wire, C, D);
  or G_top(D, bottom_wire, A); 
endmodule
