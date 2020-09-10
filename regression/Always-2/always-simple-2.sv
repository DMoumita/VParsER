module adder (
  out,
  in
);

output  out;
input  in;

reg out;

always @(*)
begin
	out = in;
end
endmodule
