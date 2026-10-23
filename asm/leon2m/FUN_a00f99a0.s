# leon2m FUN_a00f99a0 0xa00f99a0-0xa00f99e8 (72 bytes)
a00f99a0:  80 a0 00 08  cmp  %g0, %o0
a00f99a4:  82 40 20 00  addx  %g0, 0, %g1
a00f99a8:  9b 28 60 1f  sll  %g1, 0x1f, %o5
a00f99ac:  19 34 01 00  sethi  %hi(0xd0040000), %o4
a00f99b0:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00f99b4:  d6 03 00 00  ld  [ %o4 ], %o3
a00f99b8:  9a 0b 40 01  and  %o5, %g1, %o5
a00f99bc:  82 2a c0 01  andn  %o3, %g1, %g1
a00f99c0:  82 10 40 0d  or  %g1, %o5, %g1
a00f99c4:  c2 23 00 00  st  %g1, [ %o4 ]
a00f99c8:  98 13 20 d8  or  %o4, 0xd8, %o4
a00f99cc:  da 03 00 00  ld  [ %o4 ], %o5
a00f99d0:  90 0a 20 0f  and  %o0, 0xf, %o0
a00f99d4:  96 0b 7f f0  and  %o5, -16, %o3
a00f99d8:  82 12 c0 08  or  %o3, %o0, %g1
a00f99dc:  c2 23 00 00  st  %g1, [ %o4 ]
a00f99e0:  81 c3 e0 08  retl
a00f99e4:  90 10 20 00  clr  %o0
