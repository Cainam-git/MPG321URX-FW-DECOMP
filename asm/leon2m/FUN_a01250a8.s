# leon2m FUN_a01250a8 0xa01250a8-0xa01250c4 (28 bytes)
a01250a8:  90 0a 20 ff  and  %o0, 0xff, %o0
a01250ac:  03 00 06 90  sethi  %hi(0x1a4000), %g1
a01250b0:  90 5a 20 16  smul  %o0, 0x16, %o0
a01250b4:  82 10 62 a8  or  %g1, 0x2a8, %g1
a01250b8:  90 02 00 01  add  %o0, %g1, %o0
a01250bc:  81 c3 e0 08  retl
a01250c0:  d0 0a 20 01  ldub  [ %o0 + 1 ], %o0
