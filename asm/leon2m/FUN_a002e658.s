# leon2m FUN_a002e658 0xa002e658-0xa002e69c (68 bytes)
a002e658:  9a 0a 20 ff  and  %o0, 0xff, %o5
a002e65c:  80 a3 60 02  cmp  %o5, 2
a002e660:  82 40 20 00  addx  %g0, 0, %g1
a002e664:  82 20 00 01  neg  %g1
a002e668:  90 0b 40 01  and  %o5, %g1, %o0
a002e66c:  1b 2a 00 9e  sethi  %hi(0xa8027800), %o5
a002e670:  90 02 00 08  add  %o0, %o0, %o0
a002e674:  82 13 62 a8  or  %o5, 0x2a8, %g1
a002e678:  da 10 40 08  lduh  [ %g1 + %o0 ], %o5
a002e67c:  92 0a 60 ff  and  %o1, 0xff, %o1
a002e680:  90 03 40 09  add  %o5, %o1, %o0
a002e684:  93 2a 20 02  sll  %o0, 2, %o1
a002e688:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a002e68c:  9a 12 40 01  or  %o1, %g1, %o5
a002e690:  d0 03 40 00  ld  [ %o5 ], %o0
a002e694:  81 c3 e0 08  retl
a002e698:  90 0a 20 ff  and  %o0, 0xff, %o0
