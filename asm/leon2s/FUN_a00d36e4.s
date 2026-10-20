# leon2s FUN_a00d36e4 0xa00d36e4-0xa00d3704 (32 bytes)
a00d36e4:  82 10 21 00  mov  0x100, %g1	! 0x100
a00d36e8:  82 20 40 0a  sub  %g1, %o2, %g1
a00d36ec:  90 5a 00 0a  smul  %o0, %o2, %o0
a00d36f0:  92 5a 40 01  smul  %o1, %g1, %o1
a00d36f4:  92 02 40 08  add  %o1, %o0, %o1
a00d36f8:  92 02 60 80  add  %o1, 0x80, %o1
a00d36fc:  81 c3 e0 08  retl
a00d3700:  91 32 60 08  srl  %o1, 8, %o0
