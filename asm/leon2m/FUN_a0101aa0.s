# leon2m FUN_a0101aa0 0xa0101aa0-0xa0101abc (28 bytes)
a0101aa0:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a0101aa4:  9a 13 61 0c  or  %o5, 0x10c, %o5	! 0xcf01610c
a0101aa8:  c2 03 40 00  ld  [ %o5 ], %g1
a0101aac:  82 08 7f fe  and  %g1, -2, %g1
a0101ab0:  c2 23 40 00  st  %g1, [ %o5 ]
a0101ab4:  81 c3 e0 08  retl
a0101ab8:  01 00 00 00  nop
