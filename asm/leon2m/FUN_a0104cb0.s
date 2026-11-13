# leon2m FUN_a0104cb0 0xa0104cb0-0xa0104d18 (104 bytes)
a0104cb0:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a0104cb4:  15 33 c0 4a  sethi  %hi(0xcf012800), %o2
a0104cb8:  da 00 62 a4  ld  [ %g1 + 0x2a4 ], %o5
a0104cbc:  92 12 a0 90  or  %o2, 0x90, %o1
a0104cc0:  90 12 a1 90  or  %o2, 0x190, %o0
a0104cc4:  d8 03 40 00  ld  [ %o5 ], %o4
a0104cc8:  03 01 00 00  sethi  %hi(0x4000000), %g1
a0104ccc:  96 10 00 09  mov  %o1, %o3
a0104cd0:  80 8b 00 01  btst  %o4, %g1
a0104cd4:  02 80 00 09  be  0xa0104cf8
a0104cd8:  94 10 00 08  mov  %o0, %o2
a0104cdc:  da 02 40 00  ld  [ %o1 ], %o5
a0104ce0:  98 13 60 01  or  %o5, 1, %o4
a0104ce4:  d8 22 40 00  st  %o4, [ %o1 ]
a0104ce8:  d6 02 00 00  ld  [ %o0 ], %o3
a0104cec:  92 12 e0 01  or  %o3, 1, %o1
a0104cf0:  d2 22 00 00  st  %o1, [ %o0 ]
a0104cf4:  30 80 00 07  b,a   0xa0104d10
a0104cf8:  d8 02 40 00  ld  [ %o1 ], %o4
a0104cfc:  92 0b 3f fe  and  %o4, -2, %o1
a0104d00:  d2 22 c0 00  st  %o1, [ %o3 ]
a0104d04:  c2 02 00 00  ld  [ %o0 ], %g1
a0104d08:  90 08 7f fe  and  %g1, -2, %o0
a0104d0c:  d0 22 80 00  st  %o0, [ %o2 ]
a0104d10:  81 c3 e0 08  retl
a0104d14:  01 00 00 00  nop
