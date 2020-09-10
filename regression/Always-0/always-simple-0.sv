module adder (
  out,
  in
);

output  out;
input  in;

reg out;

always @(in)
begin
	out = in;
end
endmodule
