# leon2m FUN_a002f088 0xa002f088-0xa002f0b4 (44 bytes)
a002f088:  19 33 c0 1e  sethi  %hi(0xcf007800), %o4
a002f08c:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a002f090:  da 02 e1 e4  ld  [ %o3 + 0x1e4 ], %o5	! 0xa802c9e4
a002f094:  82 13 23 30  or  %o4, 0x330, %g1
a002f098:  c0 20 40 00  clr  [ %g1 ]
a002f09c:  9a 13 60 10  or  %o5, 0x10, %o5
a002f0a0:  98 13 23 34  or  %o4, 0x334, %o4
a002f0a4:  da 22 e1 e4  st  %o5, [ %o3 + 0x1e4 ]
a002f0a8:  c0 23 00 00  clr  [ %o4 ]
a002f0ac:  81 c3 e0 08  retl
a002f0b0:  01 00 00 00  nop
