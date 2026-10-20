# leon2m FUN_a01400bc 0xa01400bc-0xa01400e0 (36 bytes)
a01400bc:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a01400c0:  c2 0b 63 d3  ldub  [ %o5 + 0x3d3 ], %g1	! 0xa802cbd3
a01400c4:  83 38 40 08  sra  %g1, %o0, %g1
a01400c8:  80 88 60 01  btst  1, %g1
a01400cc:  02 80 00 03  be  0xa01400d8
a01400d0:  90 10 20 00  clr  %o0
a01400d4:  90 10 20 01  mov  1, %o0
a01400d8:  81 c3 e0 08  retl
a01400dc:  90 0a 20 01  and  %o0, 1, %o0
