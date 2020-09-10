module adder (out, in, clk);

output  out;
input  in, clk;

reg out;

always @(clk)
begin
	out = in;
end

always @(in)
begin
	out = in;
end
endmodule
