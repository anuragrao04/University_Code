module circuit1_tb;
  reg A, B, C;
  wire D;

  circuit1 UUT (.A(A), .B(B), .C(C), .D(D));

  initial begin
    A = 0; B = 0; C = 0; #20
    A = 1; B = 0; C = 0; #20
    A = 0; B = 1; C = 0; #20
    A = 1; B = 1; C = 0; #20
    A = 0; B = 0; C = 1; #20
    A = 1; B = 0; C = 1; #20
    A = 0; B = 1; C = 1; #20
    A = 1; B = 1; C = 1; 
  end

  initial begin
    $monitor("Time: %d, A = %b, B = %b, C = %b, D = %b", $time, A, B, C, D);
  end

  initial begin
    $dumpfile("circuit1.vcd");
    $dumpvars(0, circuit1_tb);
  end
endmodule
