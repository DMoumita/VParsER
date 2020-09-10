module M;

reg [1:0] v1;
reg [1:0] v2[2:0];
reg [1:0] a,b;
reg [1:0] a1[3:0],b1[4:0];
reg  x=1,y=3;
reg [1:0] a2=1,b2=0;
reg [2:0]b3=2,c3[1:0],x2,y2=1;

reg signed [1:0] vs1;
reg signed [1:0] vs2[2:0];
reg signed [1:0] as,bs;
reg signed [1:0] as1[3:0],bs1[4:0];
reg  signed xs=1,ys=3;
reg signed [1:0] as2=1,bs2=0;
reg signed [2:0]bs3=2,cs3[1:0],xs2,ys2=1;


reg signed [2:0]n1=2+3;
reg  [8:2]n2=2+3;
reg signed n3=2+3;
reg  n4=2+3;
reg  n5=2+3, n6[1:2], n8=0;
reg  [3:0] n9=7-1, n10=9+1;
reg  signed [3:0] m9=7-1, m10=9*1;
endmodule
