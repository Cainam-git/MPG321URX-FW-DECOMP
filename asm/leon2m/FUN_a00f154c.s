# leon2m FUN_a00f154c 0xa00f154c-0xa00f1690 (324 bytes)
a00f154c:  9d e3 bf 98  save  %sp, -104, %sp
a00f1550:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00f1554:  80 a3 60 04  cmp  %o5, 4
a00f1558:  b8 60 20 00  subx  %g0, 0, %i4
a00f155c:  ba 0e 00 1c  and  %i0, %i4, %i5
a00f1560:  b6 0f 60 ff  and  %i5, 0xff, %i3
a00f1564:  9e 10 00 18  mov  %i0, %o7
a00f1568:  35 2a 00 9a  sethi  %hi(0xa8026800), %i2
a00f156c:  b0 06 c0 1b  add  %i3, %i3, %i0
a00f1570:  b4 16 a2 7e  or  %i2, 0x27e, %i2
a00f1574:  b3 2e 60 10  sll  %i1, 0x10, %i1
a00f1578:  c2 16 80 18  lduh  [ %i2 + %i0 ], %g1
a00f157c:  b3 36 60 10  srl  %i1, 0x10, %i1
a00f1580:  b8 00 40 19  add  %g1, %i1, %i4
a00f1584:  b6 07 20 01  add  %i4, 1, %i3
a00f1588:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00f158c:  bb 2f 20 02  sll  %i4, 2, %i5
a00f1590:  b1 2e e0 02  sll  %i3, 2, %i0
a00f1594:  b8 17 40 01  or  %i5, %g1, %i4
a00f1598:  b6 16 00 01  or  %i0, %g1, %i3
a00f159c:  f0 07 00 00  ld  [ %i4 ], %i0
a00f15a0:  fa 06 c0 00  ld  [ %i3 ], %i5
a00f15a4:  b7 2f 60 08  sll  %i5, 8, %i3
a00f15a8:  b8 0e 20 ff  and  %i0, 0xff, %i4
a00f15ac:  b0 16 c0 1c  or  %i3, %i4, %i0
a00f15b0:  83 2e 20 10  sll  %i0, 0x10, %g1
a00f15b4:  83 30 60 10  srl  %g1, 0x10, %g1
a00f15b8:  92 10 00 1a  mov  %i2, %o1
a00f15bc:  94 10 00 19  mov  %i1, %o2
a00f15c0:  10 80 00 16  b  0xa00f1618
a00f15c4:  b0 10 20 00  clr  %i0
a00f15c8:  18 80 00 30  bgu  0xa00f1688
a00f15cc:  80 a3 60 03  cmp  %o5, 3
a00f15d0:  38 80 00 02  bgu,a   0xa00f15d8
a00f15d4:  96 10 20 00  clr  %o3
a00f15d8:  b2 0a e0 ff  and  %o3, 0xff, %i1
a00f15dc:  82 06 40 19  add  %i1, %i1, %g1
a00f15e0:  f6 12 40 01  lduh  [ %o1 + %g1 ], %i3
a00f15e4:  b8 06 c0 0a  add  %i3, %o2, %i4
a00f15e8:  b2 07 20 01  add  %i4, 1, %i1
a00f15ec:  bb 2f 20 02  sll  %i4, 2, %i5
a00f15f0:  82 17 40 1a  or  %i5, %i2, %g1
a00f15f4:  b7 2e 60 02  sll  %i1, 2, %i3
a00f15f8:  f2 00 40 00  ld  [ %g1 ], %i1
a00f15fc:  b8 16 c0 1a  or  %i3, %i2, %i4
a00f1600:  fa 07 00 00  ld  [ %i4 ], %i5
a00f1604:  b5 2f 60 08  sll  %i5, 8, %i2
a00f1608:  b6 0e 60 ff  and  %i1, 0xff, %i3
a00f160c:  b2 16 80 1b  or  %i2, %i3, %i1
a00f1610:  83 2e 60 10  sll  %i1, 0x10, %g1
a00f1614:  83 30 60 10  srl  %g1, 0x10, %g1
a00f1618:  b7 28 60 10  sll  %g1, 0x10, %i3
a00f161c:  b2 0e 20 ff  and  %i0, 0xff, %i1
a00f1620:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a00f1624:  80 a3 60 03  cmp  %o5, 3
a00f1628:  ba 10 00 0f  mov  %o7, %i5
a00f162c:  99 36 e0 10  srl  %i3, 0x10, %o4
a00f1630:  96 10 00 0f  mov  %o7, %o3
a00f1634:  08 80 00 03  bleu  0xa00f1640
a00f1638:  b0 06 20 01  inc  %i0
a00f163c:  ba 10 20 00  clr  %i5
a00f1640:  82 0f 60 ff  and  %i5, 0xff, %g1
a00f1644:  ba 00 40 01  add  %g1, %g1, %i5
a00f1648:  f8 12 40 1d  lduh  [ %o1 + %i5 ], %i4
a00f164c:  82 07 00 0a  add  %i4, %o2, %g1
a00f1650:  b8 00 60 01  add  %g1, 1, %i4
a00f1654:  bb 28 60 02  sll  %g1, 2, %i5
a00f1658:  82 17 40 1a  or  %i5, %i2, %g1
a00f165c:  bb 2f 20 02  sll  %i4, 2, %i5
a00f1660:  f8 00 40 00  ld  [ %g1 ], %i4
a00f1664:  ba 17 40 1a  or  %i5, %i2, %i5
a00f1668:  c2 07 40 00  ld  [ %i5 ], %g1
a00f166c:  bb 28 60 08  sll  %g1, 8, %i5
a00f1670:  b8 0f 20 ff  and  %i4, 0xff, %i4
a00f1674:  82 17 40 1c  or  %i5, %i4, %g1
a00f1678:  bb 28 60 10  sll  %g1, 0x10, %i5
a00f167c:  80 a7 40 1b  cmp  %i5, %i3
a00f1680:  12 bf ff d2  bne  0xa00f15c8
a00f1684:  80 a6 60 04  cmp  %i1, 4
a00f1688:  81 c7 e0 08  ret
a00f168c:  91 e8 00 0c  restore  %g0, %o4, %o0
