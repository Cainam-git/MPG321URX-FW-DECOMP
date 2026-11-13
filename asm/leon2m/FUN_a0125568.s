# leon2m FUN_a0125568 0xa0125568-0xa01255a0 (56 bytes)
a0125568:  19 2a 00 b6  sethi  %hi(0xa802d800), %o4
a012556c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0125570:  82 13 20 80  or  %o4, 0x80, %g1
a0125574:  d8 08 40 0d  ldub  [ %g1 + %o5 ], %o4
a0125578:  11 00 06 90  sethi  %hi(0x1a4000), %o0
a012557c:  82 12 22 a8  or  %o0, 0x2a8, %g1	! 0x1a42a8
a0125580:  9a 5b 20 16  smul  %o4, 0x16, %o5
a0125584:  9a 03 40 01  add  %o5, %g1, %o5
a0125588:  80 a3 20 ff  cmp  %o4, 0xff
a012558c:  02 80 00 03  be  0xa0125598
a0125590:  90 10 3f ff  mov  -1, %o0
a0125594:  d0 0b 60 0a  ldub  [ %o5 + 0xa ], %o0
a0125598:  81 c3 e0 08  retl
a012559c:  90 0a 20 ff  and  %o0, 0xff, %o0
