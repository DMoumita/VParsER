module main (clock);
input clock;
reg [2:0]a,b;

always @ (posedge clock) begin
	a[2] <= b[0];
	a[1+:0] <= b [2:1];	
	b[2-:1] <= a[1:0];
	a[1:0] <= b [2-:1];	
	b[2-:1] <= a[1+:0];
	a[2-:1] <= b[1+:0];
	b[0] <= a[2];
end
endmodule
