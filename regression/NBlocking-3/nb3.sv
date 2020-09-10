module main (i, clock);
input i,clock;
reg [2:0]x;
reg [2:0]b0;

always @ (posedge clock)
  b0 <= x;
endmodule
