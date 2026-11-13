# leon2m FUN_a01019e4 0xa01019e4-0xa0101a00 (28 bytes)
a01019e4:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a01019e8:  9a 13 60 c0  or  %o5, 0xc0, %o5	! 0xcf0160c0
a01019ec:  c2 03 40 00  ld  [ %o5 ], %g1
a01019f0:  82 08 7f f7  and  %g1, -9, %g1
a01019f4:  c2 23 40 00  st  %g1, [ %o5 ]
a01019f8:  81 c3 e0 08  retl
a01019fc:  01 00 00 00  nop
