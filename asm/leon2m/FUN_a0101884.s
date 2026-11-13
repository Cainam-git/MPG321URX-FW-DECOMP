# leon2m FUN_a0101884 0xa0101884-0xa01018b0 (44 bytes)
a0101884:  90 0a 20 0f  and  %o0, 0xf, %o0
a0101888:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a010188c:  9a 13 60 c4  or  %o5, 0xc4, %o5	! 0xcf0160c4
a0101890:  83 2a 20 04  sll  %o0, 4, %g1
a0101894:  c2 23 40 00  st  %g1, [ %o5 ]
a0101898:  d0 03 40 00  ld  [ %o5 ], %o0
a010189c:  92 0a 60 0f  and  %o1, 0xf, %o1
a01018a0:  82 12 00 09  or  %o0, %o1, %g1
a01018a4:  c2 23 40 00  st  %g1, [ %o5 ]
a01018a8:  81 c3 e0 08  retl
a01018ac:  01 00 00 00  nop
