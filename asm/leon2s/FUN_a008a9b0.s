# leon2s FUN_a008a9b0 0xa008a9b0-0xa008a9ec (60 bytes)
a008a9b0:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a9b4:  92 10 60 48  or  %g1, 0x48, %o1	! 0xcf011048
a008a9b8:  9a 10 60 14  or  %g1, 0x14, %o5
a008a9bc:  96 10 60 58  or  %g1, 0x58, %o3
a008a9c0:  94 10 60 5c  or  %g1, 0x5c, %o2
a008a9c4:  c2 03 40 00  ld  [ %o5 ], %g1
a008a9c8:  80 a0 60 00  cmp  %g1, 0
a008a9cc:  02 80 00 06  be  0xa008a9e4
a008a9d0:  98 10 20 c6  mov  0xc6, %o4
a008a9d4:  c0 23 40 00  clr  [ %o5 ]
a008a9d8:  c0 22 40 00  clr  [ %o1 ]
a008a9dc:  d8 22 c0 00  st  %o4, [ %o3 ]
a008a9e0:  d8 22 80 00  st  %o4, [ %o2 ]
a008a9e4:  81 c3 e0 08  retl
a008a9e8:  01 00 00 00  nop
