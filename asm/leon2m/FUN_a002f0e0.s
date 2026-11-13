# leon2m FUN_a002f0e0 0xa002f0e0-0xa002f10c (44 bytes)
a002f0e0:  19 33 c0 21  sethi  %hi(0xcf008400), %o4
a002f0e4:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a002f0e8:  da 02 e1 e4  ld  [ %o3 + 0x1e4 ], %o5	! 0xa802c9e4
a002f0ec:  82 13 23 30  or  %o4, 0x330, %g1
a002f0f0:  c0 20 40 00  clr  [ %g1 ]
a002f0f4:  9a 13 60 80  or  %o5, 0x80, %o5
a002f0f8:  98 13 23 34  or  %o4, 0x334, %o4
a002f0fc:  da 22 e1 e4  st  %o5, [ %o3 + 0x1e4 ]
a002f100:  c0 23 00 00  clr  [ %o4 ]
a002f104:  81 c3 e0 08  retl
a002f108:  01 00 00 00  nop
