# leon2m FUN_a011cd10 0xa011cd10-0xa011cd80 (112 bytes)
a011cd10:  82 0a 20 ff  and  %o0, 0xff, %g1
a011cd14:  9a 00 40 01  add  %g1, %g1, %o5
a011cd18:  80 8a 60 ff  btst  0xff, %o1
a011cd1c:  02 80 00 0d  be  0xa011cd50
a011cd20:  90 10 00 0d  mov  %o5, %o0
a011cd24:  19 2a 00 9e  sethi  %hi(0xa8027800), %o4
a011cd28:  92 13 22 a8  or  %o4, 0x2a8, %o1	! 0xa8027aa8
a011cd2c:  d0 12 40 0d  lduh  [ %o1 + %o5 ], %o0
a011cd30:  82 02 20 a5  add  %o0, 0xa5, %g1
a011cd34:  9b 28 60 02  sll  %g1, 2, %o5
a011cd38:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a011cd3c:  9a 13 40 0c  or  %o5, %o4, %o5
a011cd40:  d2 03 40 00  ld  [ %o5 ], %o1
a011cd44:  90 12 60 08  or  %o1, 8, %o0
a011cd48:  10 80 00 0b  b  0xa011cd74
a011cd4c:  82 0a 20 ff  and  %o0, 0xff, %g1
a011cd50:  1b 2a 00 9e  sethi  %hi(0xa8027800), %o5
a011cd54:  82 13 62 a8  or  %o5, 0x2a8, %g1	! 0xa8027aa8
a011cd58:  d8 10 40 08  lduh  [ %g1 + %o0 ], %o4
a011cd5c:  92 03 20 a5  add  %o4, 0xa5, %o1
a011cd60:  9b 2a 60 02  sll  %o1, 2, %o5
a011cd64:  11 33 c0 00  sethi  %hi(0xcf000000), %o0
a011cd68:  9a 13 40 08  or  %o5, %o0, %o5
a011cd6c:  c2 03 40 00  ld  [ %o5 ], %g1
a011cd70:  82 08 60 f7  and  %g1, 0xf7, %g1
a011cd74:  c2 23 40 00  st  %g1, [ %o5 ]
a011cd78:  81 c3 e0 08  retl
a011cd7c:  01 00 00 00  nop
