# leon2m FUN_a0122dbc 0xa0122dbc-0xa0122e24 (104 bytes)
a0122dbc:  19 00 00 1d  sethi  %hi(0x7400), %o4
a0122dc0:  1b 33 c0 f4  sethi  %hi(0xcf03d000), %o5
a0122dc4:  92 0a 60 ff  and  %o1, 0xff, %o1
a0122dc8:  82 13 22 00  or  %o4, 0x200, %g1
a0122dcc:  98 02 40 01  add  %o1, %g1, %o4
a0122dd0:  96 13 60 24  or  %o5, 0x24, %o3
a0122dd4:  93 2b 20 02  sll  %o4, 2, %o1
a0122dd8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0122ddc:  da 02 c0 00  ld  [ %o3 ], %o5
a0122de0:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a0122de4:  92 12 40 01  or  %o1, %g1, %o1
a0122de8:  94 0a a0 ff  and  %o2, 0xff, %o2
a0122dec:  80 a2 20 0f  cmp  %o0, 0xf
a0122df0:  12 80 00 08  bne  0xa0122e10
a0122df4:  98 0b 60 ff  and  %o5, 0xff, %o4
a0122df8:  9a 10 20 0c  mov  0xc, %o5
a0122dfc:  da 22 c0 00  st  %o5, [ %o3 ]
a0122e00:  03 33 c0 76  sethi  %hi(0xcf01d800), %g1
a0122e04:  9a 10 20 ff  mov  0xff, %o5
a0122e08:  82 10 60 58  or  %g1, 0x58, %g1
a0122e0c:  da 20 40 00  st  %o5, [ %g1 ]
a0122e10:  d0 22 c0 00  st  %o0, [ %o3 ]
a0122e14:  d4 22 40 00  st  %o2, [ %o1 ]
a0122e18:  d8 22 c0 00  st  %o4, [ %o3 ]
a0122e1c:  81 c3 e0 08  retl
a0122e20:  01 00 00 00  nop
