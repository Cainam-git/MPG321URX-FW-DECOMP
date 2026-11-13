# leon2m FUN_a0140098 0xa0140098-0xa01400bc (36 bytes)
a0140098:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a014009c:  c2 0b 63 d4  ldub  [ %o5 + 0x3d4 ], %g1	! 0xa802cbd4
a01400a0:  83 38 40 08  sra  %g1, %o0, %g1
a01400a4:  80 88 60 01  btst  1, %g1
a01400a8:  02 80 00 03  be  0xa01400b4
a01400ac:  90 10 20 00  clr  %o0
a01400b0:  90 10 20 01  mov  1, %o0
a01400b4:  81 c3 e0 08  retl
a01400b8:  90 0a 20 01  and  %o0, 1, %o0
