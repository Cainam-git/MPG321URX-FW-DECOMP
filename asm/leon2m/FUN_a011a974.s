# leon2m FUN_a011a974 0xa011a974-0xa011a9e4 (112 bytes)
a011a974:  82 0a 60 ff  and  %o1, 0xff, %g1
a011a978:  9a 00 40 01  add  %g1, %g1, %o5
a011a97c:  80 8a 20 ff  btst  0xff, %o0
a011a980:  02 80 00 0d  be  0xa011a9b4
a011a984:  92 10 00 0d  mov  %o5, %o1
a011a988:  19 2a 00 9e  sethi  %hi(0xa8027800), %o4
a011a98c:  92 13 22 a8  or  %o4, 0x2a8, %o1	! 0xa8027aa8
a011a990:  d0 12 40 0d  lduh  [ %o1 + %o5 ], %o0
a011a994:  82 02 20 30  add  %o0, 0x30, %g1
a011a998:  9b 28 60 02  sll  %g1, 2, %o5
a011a99c:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a011a9a0:  9a 13 40 0c  or  %o5, %o4, %o5
a011a9a4:  d2 03 40 00  ld  [ %o5 ], %o1
a011a9a8:  90 12 60 2f  or  %o1, 0x2f, %o0
a011a9ac:  10 80 00 0b  b  0xa011a9d8
a011a9b0:  82 0a 20 ff  and  %o0, 0xff, %g1
a011a9b4:  1b 2a 00 9e  sethi  %hi(0xa8027800), %o5
a011a9b8:  82 13 62 a8  or  %o5, 0x2a8, %g1	! 0xa8027aa8
a011a9bc:  d8 10 40 09  lduh  [ %g1 + %o1 ], %o4
a011a9c0:  92 03 20 30  add  %o4, 0x30, %o1
a011a9c4:  9b 2a 60 02  sll  %o1, 2, %o5
a011a9c8:  11 33 c0 00  sethi  %hi(0xcf000000), %o0
a011a9cc:  9a 13 40 08  or  %o5, %o0, %o5
a011a9d0:  c2 03 40 00  ld  [ %o5 ], %g1
a011a9d4:  82 08 60 d0  and  %g1, 0xd0, %g1
a011a9d8:  c2 23 40 00  st  %g1, [ %o5 ]
a011a9dc:  81 c3 e0 08  retl
a011a9e0:  01 00 00 00  nop
