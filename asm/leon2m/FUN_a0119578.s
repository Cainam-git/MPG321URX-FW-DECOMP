# leon2m FUN_a0119578 0xa0119578-0xa01195ac (52 bytes)
a0119578:  9a 0a 20 ff  and  %o0, 0xff, %o5
a011957c:  19 2a 00 9e  sethi  %hi(0xa8027800), %o4
a0119580:  82 13 22 a8  or  %o4, 0x2a8, %g1	! 0xa8027aa8
a0119584:  90 03 40 0d  add  %o5, %o5, %o0
a0119588:  da 10 40 08  lduh  [ %g1 + %o0 ], %o5
a011958c:  9b 2b 60 02  sll  %o5, 2, %o5
a0119590:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a0119594:  9a 13 40 0c  or  %o5, %o4, %o5
a0119598:  d0 03 40 00  ld  [ %o5 ], %o0
a011959c:  82 0a 20 7f  and  %o0, 0x7f, %g1
a01195a0:  c2 23 40 00  st  %g1, [ %o5 ]
a01195a4:  81 c3 e0 08  retl
a01195a8:  01 00 00 00  nop
