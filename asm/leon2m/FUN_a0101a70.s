# leon2m FUN_a0101a70 0xa0101a70-0xa0101aa0 (48 bytes)
a0101a70:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a0101a74:  9a 13 60 f4  or  %o5, 0xf4, %o5	! 0xcf0160f4
a0101a78:  c2 03 40 00  ld  [ %o5 ], %g1
a0101a7c:  82 08 60 f1  and  %g1, 0xf1, %g1
a0101a80:  c2 23 40 00  st  %g1, [ %o5 ]
a0101a84:  82 0a 20 ff  and  %o0, 0xff, %g1
a0101a88:  90 00 40 01  add  %g1, %g1, %o0
a0101a8c:  c2 03 40 00  ld  [ %o5 ], %g1
a0101a90:  82 10 40 08  or  %g1, %o0, %g1
a0101a94:  c2 23 40 00  st  %g1, [ %o5 ]
a0101a98:  81 c3 e0 08  retl
a0101a9c:  01 00 00 00  nop
