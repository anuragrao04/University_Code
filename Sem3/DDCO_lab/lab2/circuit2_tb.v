module circuit2_tb;
  reg A2, B2, C2;
  wire Y;

  circuit2 UUT (.A2(A2), .B2(B2), .C2(C2), .Y(Y));

  initial begin
    A2 = 0; B2 = 0; C2 = 0; #20;
    A2 = 1; B2 = 0; C2 = 0; #20;
    A2 = 0; B2 = 1; C2 = 0; #20;
    A2 = 1; B2 = 1; C2 = 0; #20;
    A2 = 0; B2 = 0; C2 = 1; #20;
    A2 = 1; B2 = 0; C2 = 1; #20;
    A2 = 0; B2 = 1; C2 = 1; #20;
    A2 = 1; B2 = 1; C2 = 1; 
  end

  initial begin
    $monitor("Time: %0t, A2 = %b, B2 = %b, C2 = %b, Y = %b", $time, A2, B2, C2, Y);
  end

  initial begin
    $dumpfile("circuit2.vcd");
    $dumpvars(0, circuit2_tb);
  end
endmodule
