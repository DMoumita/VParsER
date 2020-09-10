module m;

wire (strong1, pull0) #1 w1 = 1'b1;
wire (strong1, supply0) #(1:2:3) w2 = 1'b1;
tri1 (strong1, weak0) #3 w3 = 1'b1;
uwire (strong1, strong0) #4 w4 = 1'b1;
trireg (strong0, weak1) #2 w5 = 1'b1;
wire (strong0, supply1) #(1:2:3) w6 = 1'b1;
supply0 (strong0, pull1) #1 w7 = 1'b1;
tri0 (strong0, strong1) #1 w8 = 1'b1;

triand (supply1, pull0) #2 w9 = 1'b1;

trireg ( pull1,highz0) signed  #2 m190kl = 1'b1;
trireg ( supply1,highz0) vectored [3:1] #2 m1kl = 1'b1;
trireg ( weak1,pull0) scalared signed [1:2] #2 m761 = 1'b1;
trireg ( strong1,highz0) [4:0] #2 w87c61 = 1'b1;
trireg ( strong0,pull1) [4:0] #(1:3:6)m13 = 1'b1, m12 = 1'b1;


uwire  #2 wn1;    
wire  signed #2 wn7;   
trireg  #2 wn11[2:0];       
tri0  signed #(2:3:1) wn9[2:0];  
tri1  #5 wmn21,wn211[3:0],wn4;     
supply0  #5 wn281[4:0],wn21[9:3];   
supply1  signed #5 nn1,nn2[3:0],nn3;   
triand  vectored [4:0] #2 nn5[2:0];  
trior  scalared signed [4:0] #2 nnw9[2:0]; 
endmodule
