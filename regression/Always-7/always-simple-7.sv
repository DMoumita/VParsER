module adder (
  out,
  in,
  clk
);

output  out;
input  in,clk;

reg out;

always @( clk, in)
begin
	out = in;
end
endmodule
