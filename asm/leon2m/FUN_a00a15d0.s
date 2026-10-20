# leon2m FUN_a00a15d0 0xa00a15d0-0xa00a177c (428 bytes)
a00a15d0:  9d e3 bf 98  save  %sp, -104, %sp
a00a15d4:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a00a15d8:  40 00 1f 79  call  0xa00a93bc
a00a15dc:  d0 0e a0 56  ldub  [ %i2 + 0x56 ], %o0	! 0xa8025c56
a00a15e0:  c2 0e a0 56  ldub  [ %i2 + 0x56 ], %g1
a00a15e4:  82 00 7f ff  add  %g1, -1, %g1
a00a15e8:  9a 08 60 ff  and  %g1, 0xff, %o5
a00a15ec:  80 a3 60 03  cmp  %o5, 3
a00a15f0:  08 80 00 03  bleu  0xa00a15fc
a00a15f4:  9a 10 00 1a  mov  %i2, %o5
a00a15f8:  82 10 20 02  mov  2, %g1
a00a15fc:  c2 2e a0 56  stb  %g1, [ %i2 + 0x56 ]
a00a1600:  d0 0b 60 56  ldub  [ %o5 + 0x56 ], %o0
a00a1604:  40 00 20 13  call  0xa00a9650
a00a1608:  92 10 20 01  mov  1, %o1
a00a160c:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a00a1610:  d0 02 a3 ec  ld  [ %o2 + 0x3ec ], %o0	! 0xa802afec
a00a1614:  82 02 3f 40  add  %o0, -192, %g1
a00a1618:  80 a0 60 39  cmp  %g1, 0x39
a00a161c:  18 80 00 08  bgu  0xa00a163c
a00a1620:  96 10 20 00  clr  %o3
a00a1624:  31 00 00 bd  sethi  %hi(0x2f400), %i0
a00a1628:  93 28 60 02  sll  %g1, 2, %o1
a00a162c:  9e 16 22 b8  or  %i0, 0x2b8, %o7
a00a1630:  d8 03 c0 09  ld  [ %o7 + %o1 ], %o4
a00a1634:  81 c3 00 00  jmp  %o4
a00a1638:  01 00 00 00  nop
a00a163c:  9a 10 20 00  clr  %o5	! 0x0
a00a1640:  d6 0e a0 56  ldub  [ %i2 + 0x56 ], %o3
a00a1644:  80 a2 c0 0d  cmp  %o3, %o5
a00a1648:  02 80 00 1a  be  0xa00a16b0
a00a164c:  f4 02 a3 ec  ld  [ %o2 + 0x3ec ], %i2
a00a1650:  f2 02 a3 ec  ld  [ %o2 + 0x3ec ], %i1
a00a1654:  82 06 7f 40  add  %i1, -192, %g1
a00a1658:  80 a0 60 39  cmp  %g1, 0x39
a00a165c:  18 80 00 08  bgu  0xa00a167c
a00a1660:  b2 10 20 00  clr  %i1
a00a1664:  15 00 00 bd  sethi  %hi(0x2f400), %o2
a00a1668:  83 28 60 02  sll  %g1, 2, %g1
a00a166c:  b4 12 a1 d0  or  %o2, 0x1d0, %i2
a00a1670:  d6 06 80 01  ld  [ %i2 + %g1 ], %o3
a00a1674:  81 c2 c0 00  jmp  %o3
a00a1678:  01 00 00 00  nop
a00a167c:  b2 10 20 00  clr  %i1	! 0x0
a00a1680:  b0 10 20 01  mov  1, %i0
a00a1684:  b4 10 20 01  mov  1, %i2
a00a1688:  40 00 1a ad  call  0xa00a813c
a00a168c:  81 e8 00 00  restore
a00a1690:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00a1694:  d6 08 60 7c  ldub  [ %g1 + 0x7c ], %o3	! 0xa802d47c
a00a1698:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00a169c:  d6 0e a0 56  ldub  [ %i2 + 0x56 ], %o3
a00a16a0:  80 a2 c0 0d  cmp  %o3, %o5
a00a16a4:  12 bf ff ec  bne  0xa00a1654
a00a16a8:  f2 02 a3 ec  ld  [ %o2 + 0x3ec ], %i1
a00a16ac:  f4 02 a3 ec  ld  [ %o2 + 0x3ec ], %i2
a00a16b0:  82 06 bf 40  add  %i2, -192, %g1
a00a16b4:  80 a0 60 39  cmp  %g1, 0x39
a00a16b8:  18 80 00 08  bgu  0xa00a16d8
a00a16bc:  b2 10 20 00  clr  %i1
a00a16c0:  13 00 00 bd  sethi  %hi(0x2f400), %o1
a00a16c4:  91 28 60 02  sll  %g1, 2, %o0
a00a16c8:  98 12 60 e8  or  %o1, 0xe8, %o4
a00a16cc:  d4 03 00 08  ld  [ %o4 + %o0 ], %o2
a00a16d0:  81 c2 80 00  jmp  %o2
a00a16d4:  01 00 00 00  nop
a00a16d8:  b2 10 20 00  clr  %i1	! 0x0
a00a16dc:  b0 10 20 01  mov  1, %i0
a00a16e0:  b4 10 20 00  clr  %i2
a00a16e4:  40 00 1a 96  call  0xa00a813c
a00a16e8:  81 e8 00 00  restore
a00a16ec:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00a16f0:  f2 0a 60 7c  ldub  [ %o1 + 0x7c ], %i1	! 0xa802d47c
a00a16f4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a16f8:  b0 10 20 01  mov  1, %i0
a00a16fc:  10 bf ff e3  b  0xa00a1688
a00a1700:  b4 10 20 01  mov  1, %i2
a00a1704:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00a1708:  d6 0b 60 7a  ldub  [ %o5 + 0x7a ], %o3	! 0xa802d47a
a00a170c:  10 bf ff e4  b  0xa00a169c
a00a1710:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00a1714:  33 2a 00 b5  sethi  %hi(0xa802d400), %i1
a00a1718:  d6 0e 60 78  ldub  [ %i1 + 0x78 ], %o3	! 0xa802d478
a00a171c:  10 bf ff e0  b  0xa00a169c
a00a1720:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00a1724:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a00a1728:  f2 0b 20 7a  ldub  [ %o4 + 0x7a ], %i1	! 0xa802d47a
a00a172c:  10 bf ff f3  b  0xa00a16f8
a00a1730:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a1734:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a00a1738:  f2 0a 20 78  ldub  [ %o0 + 0x78 ], %i1	! 0xa802d478
a00a173c:  10 bf ff ef  b  0xa00a16f8
a00a1740:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a1744:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00a1748:  f2 0b 60 7c  ldub  [ %o5 + 0x7c ], %i1	! 0xa802d47c
a00a174c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a1750:  b0 10 20 01  mov  1, %i0
a00a1754:  10 bf ff e4  b  0xa00a16e4
a00a1758:  b4 10 20 00  clr  %i2
a00a175c:  31 2a 00 b5  sethi  %hi(0xa802d400), %i0
a00a1760:  f2 0e 20 7a  ldub  [ %i0 + 0x7a ], %i1	! 0xa802d47a
a00a1764:  10 bf ff fb  b  0xa00a1750
a00a1768:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a176c:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a00a1770:  f2 0b e0 78  ldub  [ %o7 + 0x78 ], %i1	! 0xa802d478
a00a1774:  10 bf ff f7  b  0xa00a1750
a00a1778:  b2 0e 60 ff  and  %i1, 0xff, %i1
