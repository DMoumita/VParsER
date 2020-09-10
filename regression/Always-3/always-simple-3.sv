module adder (
  out,
  in1,
  in2
);

output  out;
input  in1,in2;

reg out;

always @(in1 or in2)
begin
	out = in1;
end
endmodule
