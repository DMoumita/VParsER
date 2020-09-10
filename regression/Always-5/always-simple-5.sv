module adder (
  out,
  in,
  clk
);

output  out;
input  in,clk;

reg out;

always @(posedge clk or negedge in)
begin
	out = in;
end
endmodule
