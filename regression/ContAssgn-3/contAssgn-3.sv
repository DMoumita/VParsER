module M;
  wire w1 = 1'b1;
  wire (strong1, pull0) w2 = w1;
endmodule
