module adder (
  out,
  in
);

output  out;
input  in;

reg out;

always @(in)
	out = in;
endmodule
