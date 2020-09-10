module main (clock);
input clock;
reg x;
reg b0;

always @ (posedge clock)
  b0 <= x;
endmodule
