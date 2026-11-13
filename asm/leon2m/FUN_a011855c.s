# leon2m FUN_a011855c 0xa011855c-0xa01185d4 (120 bytes)
a011855c:  9d e3 bf 98  save  %sp, -104, %sp
a0118560:  40 00 12 8a  call  0xa011cf88
a0118564:  01 00 00 00  nop
a0118568:  03 33 c0 4b  sethi  %hi(0xcf012c00), %g1
a011856c:  92 10 62 80  or  %g1, 0x280, %o1	! 0xcf012e80
a0118570:  96 10 62 00  or  %g1, 0x200, %o3
a0118574:  19 33 c0 46  sethi  %hi(0xcf011800), %o4
a0118578:  90 0a 20 ff  and  %o0, 0xff, %o0
a011857c:  94 13 22 00  or  %o4, 0x200, %o2
a0118580:  80 a2 20 83  cmp  %o0, 0x83
a0118584:  08 80 00 06  bleu  0xa011859c
a0118588:  82 10 63 74  or  %g1, 0x374, %g1
a011858c:  de 00 40 00  ld  [ %g1 ], %o7
a0118590:  80 8b e0 02  btst  2, %o7
a0118594:  12 80 00 0d  bne  0xa01185c8
a0118598:  01 00 00 00  nop
a011859c:  c0 22 40 00  clr  [ %o1 ]
a01185a0:  c2 02 c0 00  ld  [ %o3 ], %g1
a01185a4:  9a 08 7f fe  and  %g1, -2, %o5
a01185a8:  da 22 c0 00  st  %o5, [ %o3 ]
a01185ac:  d0 02 80 00  ld  [ %o2 ], %o0
a01185b0:  96 0a 3f df  and  %o0, -33, %o3
a01185b4:  d6 22 80 00  st  %o3, [ %o2 ]
a01185b8:  d4 03 00 00  ld  [ %o4 ], %o2
a01185bc:  92 0a bf df  and  %o2, -33, %o1
a01185c0:  d2 23 00 00  st  %o1, [ %o4 ]
a01185c4:  30 80 00 02  b,a   0xa01185cc
a01185c8:  c0 22 40 00  clr  [ %o1 ]
a01185cc:  81 c7 e0 08  ret
a01185d0:  81 e8 00 00  restore
