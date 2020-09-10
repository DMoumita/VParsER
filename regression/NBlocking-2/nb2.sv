module main (clock);
input clock;
reg x, y;
reg b0, b1;

always @ (posedge clock) 
	begin
  	    b0 <= x;
        b1 <= y;
	end
endmodule
