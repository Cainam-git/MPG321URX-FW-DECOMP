# leon2m FUN_a002f0b4 0xa002f0b4-0xa002f0e0 (44 bytes)
a002f0b4:  19 33 c0 20  sethi  %hi(0xcf008000), %o4
a002f0b8:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a002f0bc:  da 02 e1 e4  ld  [ %o3 + 0x1e4 ], %o5	! 0xa802c9e4
a002f0c0:  82 13 23 30  or  %o4, 0x330, %g1
a002f0c4:  c0 20 40 00  clr  [ %g1 ]
a002f0c8:  9a 13 60 40  or  %o5, 0x40, %o5
a002f0cc:  98 13 23 34  or  %o4, 0x334, %o4
a002f0d0:  da 22 e1 e4  st  %o5, [ %o3 + 0x1e4 ]
a002f0d4:  c0 23 00 00  clr  [ %o4 ]
a002f0d8:  81 c3 e0 08  retl
a002f0dc:  01 00 00 00  nop
