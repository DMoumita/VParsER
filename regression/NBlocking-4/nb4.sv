module main (i, clock);
input i,clock;
reg [2:0]x;
reg [2:0]b0, b1;

always @ (posedge clock)
	begin
       b0 <= x;
       b1 <= b0;
	end
endmodule
