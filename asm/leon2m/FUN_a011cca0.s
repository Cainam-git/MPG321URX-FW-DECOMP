# leon2m FUN_a011cca0 0xa011cca0-0xa011cd10 (112 bytes)
a011cca0:  82 0a 20 ff  and  %o0, 0xff, %g1
a011cca4:  9a 00 40 01  add  %g1, %g1, %o5
a011cca8:  80 8a 60 ff  btst  0xff, %o1
a011ccac:  02 80 00 0d  be  0xa011cce0
a011ccb0:  90 10 00 0d  mov  %o5, %o0
a011ccb4:  19 2a 00 9e  sethi  %hi(0xa8027800), %o4
a011ccb8:  92 13 22 a8  or  %o4, 0x2a8, %o1	! 0xa8027aa8
a011ccbc:  d0 12 40 0d  lduh  [ %o1 + %o5 ], %o0
a011ccc0:  82 02 20 80  add  %o0, 0x80, %g1
a011ccc4:  9b 28 60 02  sll  %g1, 2, %o5
a011ccc8:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a011cccc:  9a 13 40 0c  or  %o5, %o4, %o5
a011ccd0:  d2 03 40 00  ld  [ %o5 ], %o1
a011ccd4:  90 12 60 01  or  %o1, 1, %o0
a011ccd8:  10 80 00 0b  b  0xa011cd04
a011ccdc:  82 0a 20 ff  and  %o0, 0xff, %g1
a011cce0:  1b 2a 00 9e  sethi  %hi(0xa8027800), %o5
a011cce4:  82 13 62 a8  or  %o5, 0x2a8, %g1	! 0xa8027aa8
a011cce8:  d8 10 40 08  lduh  [ %g1 + %o0 ], %o4
a011ccec:  92 03 20 80  add  %o4, 0x80, %o1
a011ccf0:  9b 2a 60 02  sll  %o1, 2, %o5
a011ccf4:  11 33 c0 00  sethi  %hi(0xcf000000), %o0
a011ccf8:  9a 13 40 08  or  %o5, %o0, %o5
a011ccfc:  c2 03 40 00  ld  [ %o5 ], %g1
a011cd00:  82 08 60 fe  and  %g1, 0xfe, %g1
a011cd04:  c2 23 40 00  st  %g1, [ %o5 ]
a011cd08:  81 c3 e0 08  retl
a011cd0c:  01 00 00 00  nop
