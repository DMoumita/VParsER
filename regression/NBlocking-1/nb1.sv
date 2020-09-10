module main (clock);
input clock;
reg x;
reg b0, b1;

always @ (posedge clock) 
	begin
  	    b0 <= x;
        b1 <= ~b0;
	end
endmodule
