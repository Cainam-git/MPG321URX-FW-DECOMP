# leon2m FUN_a0101e70 0xa0101e70-0xa0101e9c (44 bytes)
a0101e70:  1b 33 c0 4a  sethi  %hi(0xcf012800), %o5
a0101e74:  98 13 60 90  or  %o5, 0x90, %o4	! 0xcf012890
a0101e78:  c2 03 00 00  ld  [ %o4 ], %g1
a0101e7c:  82 08 7f fe  and  %g1, -2, %g1
a0101e80:  c2 23 00 00  st  %g1, [ %o4 ]
a0101e84:  9a 13 61 90  or  %o5, 0x190, %o5
a0101e88:  d8 03 40 00  ld  [ %o5 ], %o4
a0101e8c:  82 0b 3f fe  and  %o4, -2, %g1
a0101e90:  c2 23 40 00  st  %g1, [ %o5 ]
a0101e94:  81 c3 e0 08  retl
a0101e98:  01 00 00 00  nop
