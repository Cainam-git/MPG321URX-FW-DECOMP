# leon2m FUN_a01183c0 0xa01183c0-0xa0118400 (64 bytes)
a01183c0:  19 33 c0 4a  sethi  %hi(0xcf012800), %o4
a01183c4:  9a 13 21 d0  or  %o4, 0x1d0, %o5	! 0xcf0129d0
a01183c8:  c2 03 40 00  ld  [ %o5 ], %g1
a01183cc:  82 08 7f fe  and  %g1, -2, %g1
a01183d0:  c2 23 40 00  st  %g1, [ %o5 ]
a01183d4:  98 13 23 10  or  %o4, 0x310, %o4
a01183d8:  da 03 00 00  ld  [ %o4 ], %o5
a01183dc:  82 0b 7f fe  and  %o5, -2, %g1
a01183e0:  1b 33 c0 50  sethi  %hi(0xcf014000), %o5
a01183e4:  c2 23 00 00  st  %g1, [ %o4 ]
a01183e8:  9a 13 60 90  or  %o5, 0x90, %o5
a01183ec:  d8 03 40 00  ld  [ %o5 ], %o4
a01183f0:  82 0b 3f fe  and  %o4, -2, %g1
a01183f4:  c2 23 40 00  st  %g1, [ %o5 ]
a01183f8:  81 c3 e0 08  retl
a01183fc:  01 00 00 00  nop
