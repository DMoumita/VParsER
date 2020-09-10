module m;

uwire (strong1, pull0) w1 = 1'b1;
uwire (strong1, supply0) w2 = 1'b1;
uwire (strong1, weak0) w3 = 1'b1;
uwire (strong1, strong0) w4 = 1'b1;
uwire (strong0, weak1) w5 = 1'b1;
uwire (strong0, supply1) w6 = 1'b1;
uwire (strong0, pull1) w7 = 1'b1;
uwire (strong0, strong1) w8 = 1'b1;

uwire (supply1, pull0) w9 = 1'b1;
uwire (supply1, strong0) w10 = 1'b1;
uwire (supply1, weak0) w11 = 1'b1;
uwire (supply0, weak1) w12 = 1'b1;
uwire (supply0, strong1) w13 = 1'b1;
uwire (supply0, pull1) w14 = 1'b1;
uwire (supply0, supply1) w15 = 1'b1;

uwire (pull1, pull0) w16 = 1'b1;
uwire (pull1, strong0) w17 = 1'b1;
uwire (pull1, weak0) w18 = 1'b1;
uwire (pull0, weak1) w19 = 1'b1;
uwire (pull0, strong1) w20 = 1'b1;
uwire (pull0, pull1) w221 = 1'b1;

uwire (weak1, pull0) w22 = 1'b1;
uwire (weak1, strong0) wx231 = 1'b1;
uwire (weak1, weak0) wcw1 = 1'b1;
uwire (weak0, weak1) wj1 = 1'b1;
uwire (weak0, strong1) w91 = 1'b1;
uwire (weak0, pull1) wml1 = 1'b1;
uwire (weak0, weak1) wkl1 = 1'b1;

uwire (highz1, pull0) w901 = 1'b1;
uwire (highz1, supply0) w81 = 1'b1;
uwire (highz1, weak0) w100 = 1'b1;
uwire (highz1, strong0) w1k = 1'b1;

uwire (pull0,highz1) w129 = 1'b1;
uwire (supply0,highz1) w01 = 1'b1;
uwire (weak0,highz1) w111 = 1'b1;
uwire (strong0,highz1) w1o11 = 1'b1;

uwire (highz0, pull1) w1900 = 1'b1;
uwire (highz0, supply1) w178h = 1'b1;
uwire (highz0, weak1) w1789h = 1'b1;
uwire (highz0, strong1) w1hj9 = 1'b1;

uwire ( pull1,highz0) w190kl = 1'b1;
uwire ( supply1,highz0) w1kl = 1'b1;
uwire ( weak1,highz0) w8761 = 1'b1;
uwire ( strong1,highz0) w87c61 = 1'b1;

uwire ( pull1,highz0) signed  m190kl = 1'b1;
uwire ( supply1,highz0) vectored [3:1] m1kl = 1'b1;
uwire ( weak1,pull0) scalared signed [1:2]m761 = 1'b1;
uwire ( strong1,highz0) [4:0] v87c61 = 1'b1;
uwire ( strong0,pull1) [4:0]m13 = 1'b1, m12 = 1'b1;

endmodule
