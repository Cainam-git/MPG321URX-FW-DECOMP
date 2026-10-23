# leon2m FUN_a010a2b0 0xa010a2b0-0xa010a2cc (28 bytes)
a010a2b0:  1b 33 c0 7a  sethi  %hi(0xcf01e800), %o5
a010a2b4:  82 13 62 40  or  %o5, 0x240, %g1	! 0xcf01ea40
a010a2b8:  d0 00 40 00  ld  [ %g1 ], %o0
a010a2bc:  9a 0a 20 80  and  %o0, 0x80, %o5
a010a2c0:  80 a0 00 0d  cmp  %g0, %o5
a010a2c4:  81 c3 e0 08  retl
a010a2c8:  90 40 20 00  addx  %g0, 0, %o0
