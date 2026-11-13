# leon2s FUN_a00c1550 0xa00c1550-0xa00c1778 (552 bytes)
a00c1550:  9d e3 bf 98  save  %sp, -104, %sp
a00c1554:  03 33 c0 3c  sethi  %hi(0xcf00f000), %g1
a00c1558:  82 10 62 1c  or  %g1, 0x21c, %g1	! 0xcf00f21c
a00c155c:  d8 00 40 00  ld  [ %g1 ], %o4
a00c1560:  da 00 40 00  ld  [ %g1 ], %o5
a00c1564:  9a 0b 7f e7  and  %o5, -25, %o5
a00c1568:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c156c:  da 20 40 00  st  %o5, [ %g1 ]
a00c1570:  a2 10 00 0c  mov  %o4, %l1
a00c1574:  90 10 00 18  mov  %i0, %o0
a00c1578:  92 10 24 00  mov  0x400, %o1
a00c157c:  40 3b d5 a1  call  0xa0fb6c00
a00c1580:  94 10 20 00  clr  %o2
a00c1584:  90 10 00 18  mov  %i0, %o0
a00c1588:  92 10 24 03  mov  0x403, %o1
a00c158c:  40 3b d5 9d  call  0xa0fb6c00
a00c1590:  94 10 20 00  clr  %o2
a00c1594:  90 10 00 18  mov  %i0, %o0
a00c1598:  92 10 24 02  mov  0x402, %o1
a00c159c:  94 10 20 80  mov  0x80, %o2
a00c15a0:  40 3b d5 be  call  0xa0fb6c98
a00c15a4:  96 10 20 01  mov  1, %o3
a00c15a8:  a0 10 20 00  clr  %l0
a00c15ac:  83 2c 20 10  sll  %l0, 0x10, %g1
a00c15b0:  83 30 60 10  srl  %g1, 0x10, %g1
a00c15b4:  82 27 00 01  sub  %i4, %g1, %g1
a00c15b8:  d4 08 61 3f  ldub  [ %g1 + 0x13f ], %o2
a00c15bc:  90 10 00 18  mov  %i0, %o0
a00c15c0:  40 3b d5 90  call  0xa0fb6c00
a00c15c4:  92 10 24 01  mov  0x401, %o1
a00c15c8:  9a 04 20 01  add  %l0, 1, %o5
a00c15cc:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c15d0:  83 30 60 10  srl  %g1, 0x10, %g1
a00c15d4:  80 a0 61 3f  cmp  %g1, 0x13f
a00c15d8:  08 bf ff f5  bleu  0xa00c15ac
a00c15dc:  a0 10 00 0d  mov  %o5, %l0
a00c15e0:  90 10 00 18  mov  %i0, %o0
a00c15e4:  92 10 24 06  mov  0x406, %o1
a00c15e8:  40 3b d5 86  call  0xa0fb6c00
a00c15ec:  94 10 20 80  mov  0x80, %o2
a00c15f0:  90 10 00 18  mov  %i0, %o0
a00c15f4:  92 10 24 00  mov  0x400, %o1
a00c15f8:  40 3b d5 82  call  0xa0fb6c00
a00c15fc:  94 10 20 02  mov  2, %o2
a00c1600:  90 10 00 18  mov  %i0, %o0
a00c1604:  92 10 24 03  mov  0x403, %o1
a00c1608:  40 3b d5 7e  call  0xa0fb6c00
a00c160c:  94 10 20 00  clr  %o2
a00c1610:  90 10 00 18  mov  %i0, %o0
a00c1614:  92 10 24 02  mov  0x402, %o1
a00c1618:  94 10 20 80  mov  0x80, %o2
a00c161c:  40 3b d5 9f  call  0xa0fb6c98
a00c1620:  96 10 20 01  mov  1, %o3
a00c1624:  a0 10 20 00  clr  %l0
a00c1628:  83 2c 20 10  sll  %l0, 0x10, %g1
a00c162c:  83 30 60 10  srl  %g1, 0x10, %g1
a00c1630:  d4 0e 80 01  ldub  [ %i2 + %g1 ], %o2
a00c1634:  90 10 00 18  mov  %i0, %o0
a00c1638:  40 3b d5 72  call  0xa0fb6c00
a00c163c:  92 10 24 01  mov  0x401, %o1
a00c1640:  9a 04 20 01  add  %l0, 1, %o5
a00c1644:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c1648:  83 30 60 10  srl  %g1, 0x10, %g1
a00c164c:  80 a0 62 09  cmp  %g1, 0x209
a00c1650:  08 bf ff f6  bleu  0xa00c1628
a00c1654:  a0 10 00 0d  mov  %o5, %l0
a00c1658:  90 10 00 18  mov  %i0, %o0
a00c165c:  92 10 24 00  mov  0x400, %o1
a00c1660:  40 3b d5 68  call  0xa0fb6c00
a00c1664:  94 10 20 11  mov  0x11, %o2
a00c1668:  90 10 00 18  mov  %i0, %o0
a00c166c:  92 10 24 03  mov  0x403, %o1
a00c1670:  40 3b d5 64  call  0xa0fb6c00
a00c1674:  94 10 20 00  clr  %o2
a00c1678:  90 10 00 18  mov  %i0, %o0
a00c167c:  92 10 24 02  mov  0x402, %o1
a00c1680:  94 10 20 80  mov  0x80, %o2
a00c1684:  40 3b d5 85  call  0xa0fb6c98
a00c1688:  96 10 20 01  mov  1, %o3
a00c168c:  a0 10 20 00  clr  %l0
a00c1690:  90 10 00 18  mov  %i0, %o0
a00c1694:  92 10 24 01  mov  0x401, %o1
a00c1698:  40 3b d5 5a  call  0xa0fb6c00
a00c169c:  94 10 20 00  clr  %o2
a00c16a0:  9a 04 20 01  add  %l0, 1, %o5
a00c16a4:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c16a8:  83 30 60 10  srl  %g1, 0x10, %g1
a00c16ac:  80 a0 60 17  cmp  %g1, 0x17
a00c16b0:  08 bf ff f8  bleu  0xa00c1690
a00c16b4:  a0 10 00 0d  mov  %o5, %l0
a00c16b8:  a0 10 20 00  clr  %l0
a00c16bc:  83 2c 20 10  sll  %l0, 0x10, %g1
a00c16c0:  83 30 60 10  srl  %g1, 0x10, %g1
a00c16c4:  82 26 40 01  sub  %i1, %g1, %g1
a00c16c8:  d4 08 60 0f  ldub  [ %g1 + 0xf ], %o2
a00c16cc:  90 10 00 18  mov  %i0, %o0
a00c16d0:  40 3b d5 4c  call  0xa0fb6c00
a00c16d4:  92 10 24 01  mov  0x401, %o1
a00c16d8:  9a 04 20 01  add  %l0, 1, %o5
a00c16dc:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c16e0:  83 30 60 10  srl  %g1, 0x10, %g1
a00c16e4:  80 a0 60 0f  cmp  %g1, 0xf
a00c16e8:  08 bf ff f5  bleu  0xa00c16bc
a00c16ec:  a0 10 00 0d  mov  %o5, %l0
a00c16f0:  90 10 00 18  mov  %i0, %o0
a00c16f4:  92 10 24 00  mov  0x400, %o1
a00c16f8:  40 3b d5 42  call  0xa0fb6c00
a00c16fc:  94 10 20 03  mov  3, %o2
a00c1700:  90 10 00 18  mov  %i0, %o0
a00c1704:  92 10 24 03  mov  0x403, %o1
a00c1708:  40 3b d5 3e  call  0xa0fb6c00
a00c170c:  94 10 20 00  clr  %o2
a00c1710:  90 10 00 18  mov  %i0, %o0
a00c1714:  92 10 24 02  mov  0x402, %o1
a00c1718:  94 10 20 80  mov  0x80, %o2
a00c171c:  40 3b d5 5f  call  0xa0fb6c98
a00c1720:  96 10 20 01  mov  1, %o3
a00c1724:  a0 10 20 00  clr  %l0
a00c1728:  9b 2c 20 10  sll  %l0, 0x10, %o5
a00c172c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00c1730:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c1734:  82 10 62 10  or  %g1, 0x210, %g1
a00c1738:  d4 08 40 0d  ldub  [ %g1 + %o5 ], %o2
a00c173c:  90 10 00 18  mov  %i0, %o0
a00c1740:  40 3b d5 30  call  0xa0fb6c00
a00c1744:  92 10 24 01  mov  0x401, %o1
a00c1748:  9a 04 20 01  add  %l0, 1, %o5
a00c174c:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c1750:  83 30 60 10  srl  %g1, 0x10, %g1
a00c1754:  80 a0 60 0a  cmp  %g1, 0xa
a00c1758:  08 bf ff f4  bleu  0xa00c1728
a00c175c:  a0 10 00 0d  mov  %o5, %l0
a00c1760:  03 33 c0 3c  sethi  %hi(0xcf00f000), %g1
a00c1764:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00c1768:  82 10 62 1c  or  %g1, 0x21c, %g1
a00c176c:  da 20 40 00  st  %o5, [ %g1 ]
a00c1770:  81 c7 e0 08  ret
a00c1774:  81 e8 00 00  restore
