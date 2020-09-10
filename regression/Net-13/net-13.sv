module m;

trireg (strong1, pull0) w1 = 1'b1;
trireg (strong1, supply0) w2 = 1'b1;
trireg (strong1, weak0) w3 = 1'b1;
trireg (strong1, strong0) w4 = 1'b1;
trireg (strong0, weak1) w5 = 1'b1;
trireg (strong0, supply1) w6 = 1'b1;
trireg (strong0, pull1) w7 = 1'b1;
trireg (strong0, strong1) w8 = 1'b1;

trireg (supply1, pull0) w9 = 1'b1;
trireg (supply1, strong0) w10 = 1'b1;
trireg (supply1, weak0) w11 = 1'b1;
trireg (supply0, weak1) w12 = 1'b1;
trireg (supply0, strong1) w13 = 1'b1;
trireg (supply0, pull1) w14 = 1'b1;
trireg (supply0, supply1) w15 = 1'b1;

trireg (pull1, pull0) w16 = 1'b1;
trireg (pull1, strong0) w17 = 1'b1;
trireg (pull1, weak0) w18 = 1'b1;
trireg (pull0, weak1) w19 = 1'b1;
trireg (pull0, strong1) w20 = 1'b1;
trireg (pull0, pull1) w221 = 1'b1;

trireg (weak1, pull0) w22 = 1'b1;
trireg (weak1, strong0) wx231 = 1'b1;
trireg (weak1, weak0) wcw1 = 1'b1;
trireg (weak0, weak1) wj1 = 1'b1;
trireg (weak0, strong1) w91 = 1'b1;
trireg (weak0, pull1) wml1 = 1'b1;
trireg (weak0, weak1) wkl1 = 1'b1;

trireg (highz1, pull0) w901 = 1'b1;
trireg (highz1, supply0) w81 = 1'b1;
trireg (highz1, weak0) w100 = 1'b1;
trireg (highz1, strong0) w1k = 1'b1;

trireg (pull0,highz1) w129 = 1'b1;
trireg (supply0,highz1) w01 = 1'b1;
trireg (weak0,highz1) w111 = 1'b1;
trireg (strong0,highz1) w1o11 = 1'b1;

trireg (highz0, pull1) w1900 = 1'b1;
trireg (highz0, supply1) w178h = 1'b1;
trireg (highz0, weak1) w1789h = 1'b1;
trireg (highz0, strong1) w1hj9 = 1'b1;

trireg ( pull1,highz0) w190kl = 1'b1;
trireg ( supply1,highz0) w1kl = 1'b1;
trireg ( weak1,highz0) w8761 = 1'b1;
trireg ( strong1,highz0) w87c61 = 1'b1;

trireg ( pull1,highz0) signed  m190kl = 1'b1;
trireg ( supply1,highz0) vectored [3:1] m1kl = 1'b1;
trireg ( weak1,pull0) scalared signed [1:2]m761 = 1'b1;
trireg ( strong1,highz0) [4:0]mmoi = 1'b1;
trireg ( strong0,pull1) [4:0]m13 = 1'b1, m12 = 1'b1;

endmodule
