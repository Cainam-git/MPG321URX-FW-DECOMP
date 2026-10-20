# leon2m FUN_a002e69c 0xa002e69c-0xa002e6e4 (72 bytes)
a002e69c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a002e6a0:  80 a3 60 02  cmp  %o5, 2
a002e6a4:  82 40 20 00  addx  %g0, 0, %g1
a002e6a8:  82 20 00 01  neg  %g1
a002e6ac:  90 0b 40 01  and  %o5, %g1, %o0
a002e6b0:  1b 2a 00 9e  sethi  %hi(0xa8027800), %o5
a002e6b4:  90 02 00 08  add  %o0, %o0, %o0
a002e6b8:  82 13 62 a8  or  %o5, 0x2a8, %g1
a002e6bc:  da 10 40 08  lduh  [ %g1 + %o0 ], %o5
a002e6c0:  92 0a 60 ff  and  %o1, 0xff, %o1
a002e6c4:  9a 03 40 09  add  %o5, %o1, %o5
a002e6c8:  91 2b 60 02  sll  %o5, 2, %o0
a002e6cc:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a002e6d0:  9a 12 00 01  or  %o0, %g1, %o5
a002e6d4:  94 0a a0 ff  and  %o2, 0xff, %o2
a002e6d8:  d4 23 40 00  st  %o2, [ %o5 ]
a002e6dc:  81 c3 e0 08  retl
a002e6e0:  01 00 00 00  nop
