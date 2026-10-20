# leon2m FUN_a0101c64 0xa0101c64-0xa0101c9c (56 bytes)
a0101c64:  03 33 c0 58  sethi  %hi(0xcf016000), %g1
a0101c68:  98 10 61 18  or  %g1, 0x118, %o4	! 0xcf016118
a0101c6c:  80 8a 20 ff  btst  0xff, %o0
a0101c70:  02 80 00 06  be  0xa0101c88
a0101c74:  9a 10 00 0c  mov  %o4, %o5
a0101c78:  da 03 00 00  ld  [ %o4 ], %o5
a0101c7c:  90 13 60 80  or  %o5, 0x80, %o0
a0101c80:  d0 23 00 00  st  %o0, [ %o4 ]
a0101c84:  30 80 00 04  b,a   0xa0101c94
a0101c88:  c2 03 00 00  ld  [ %o4 ], %g1
a0101c8c:  98 08 7f 7f  and  %g1, -129, %o4
a0101c90:  d8 23 40 00  st  %o4, [ %o5 ]
a0101c94:  81 c3 e0 08  retl
a0101c98:  01 00 00 00  nop
