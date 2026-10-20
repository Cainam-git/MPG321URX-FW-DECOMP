# leon2m FUN_a01019b4 0xa01019b4-0xa01019e4 (48 bytes)
a01019b4:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a01019b8:  9a 13 60 f4  or  %o5, 0xf4, %o5	! 0xcf0160f4
a01019bc:  c2 03 40 00  ld  [ %o5 ], %g1
a01019c0:  82 08 60 ef  and  %g1, 0xef, %g1
a01019c4:  c2 23 40 00  st  %g1, [ %o5 ]
a01019c8:  82 0a 20 ff  and  %o0, 0xff, %g1
a01019cc:  91 28 60 04  sll  %g1, 4, %o0
a01019d0:  c2 03 40 00  ld  [ %o5 ], %g1
a01019d4:  82 10 40 08  or  %g1, %o0, %g1
a01019d8:  c2 23 40 00  st  %g1, [ %o5 ]
a01019dc:  81 c3 e0 08  retl
a01019e0:  01 00 00 00  nop
