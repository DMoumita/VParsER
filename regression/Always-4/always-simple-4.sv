module adder (
  out,
  in,
  clk
);

output  out;
input  in,clk;

reg out;

always @(posedge clk)
begin
	out = in;
end
endmodule
