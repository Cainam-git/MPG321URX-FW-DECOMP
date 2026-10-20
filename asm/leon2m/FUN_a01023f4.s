# leon2m FUN_a01023f4 0xa01023f4-0xa0102680 (652 bytes)
a01023f4:  9d e3 bf 98  save  %sp, -104, %sp
a01023f8:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a01023fc:  c2 06 a2 a4  ld  [ %i2 + 0x2a4 ], %g1	! 0xa802d6a4
a0102400:  1b 00 20 00  sethi  %hi(0x800000), %o5
a0102404:  d6 00 40 00  ld  [ %g1 ], %o3
a0102408:  80 8a c0 0d  btst  %o3, %o5
a010240c:  02 80 00 03  be  0xa0102418
a0102410:  9a 10 20 61  mov  0x61, %o5
a0102414:  9a 10 3f e1  mov  -31, %o5
a0102418:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a010241c:  94 12 62 80  or  %o1, 0x280, %o2	! 0xa802d680
a0102420:  d8 02 a0 04  ld  [ %o2 + 4 ], %o4
a0102424:  b3 2b 20 03  sll  %o4, 3, %i1
a0102428:  21 00 1c 00  sethi  %hi(0x700000), %l0
a010242c:  98 16 40 0d  or  %i1, %o5, %o4
a0102430:  9e 0a c0 10  and  %o3, %l0, %o7
a0102434:  11 00 04 00  sethi  %hi(0x100000), %o0
a0102438:  80 a3 c0 08  cmp  %o7, %o0
a010243c:  02 80 00 8f  be  0xa0102678
a0102440:  9a 10 00 0c  mov  %o4, %o5
a0102444:  d6 02 a0 08  ld  [ %o2 + 8 ], %o3
a0102448:  80 a2 e0 00  cmp  %o3, 0
a010244c:  12 80 00 03  bne  0xa0102458
a0102450:  96 0b 60 fb  and  %o5, 0xfb, %o3
a0102454:  96 13 60 04  or  %o5, 4, %o3
a0102458:  c2 06 a2 a4  ld  [ %i2 + 0x2a4 ], %g1
a010245c:  da 00 40 00  ld  [ %g1 ], %o5
a0102460:  15 00 80 00  sethi  %hi(0x2000000), %o2
a0102464:  80 8b 40 0a  btst  %o5, %o2
a0102468:  02 80 00 08  be  0xa0102488
a010246c:  9a 0a e0 fd  and  %o3, 0xfd, %o5
a0102470:  9e 12 62 80  or  %o1, 0x280, %o7
a0102474:  d0 0b e0 02  ldub  [ %o7 + 2 ], %o0
a0102478:  80 a2 20 00  cmp  %o0, 0
a010247c:  12 80 00 03  bne  0xa0102488
a0102480:  9a 12 e0 02  or  %o3, 2, %o5
a0102484:  9a 0a e0 fd  and  %o3, 0xfd, %o5
a0102488:  96 12 62 80  or  %o1, 0x280, %o3
a010248c:  19 33 c0 3b  sethi  %hi(0xcf00ec00), %o4
a0102490:  a0 0b 60 ff  and  %o5, 0xff, %l0
a0102494:  92 13 21 40  or  %o4, 0x140, %o1
a0102498:  d0 02 e0 08  ld  [ %o3 + 8 ], %o0
a010249c:  e0 22 40 00  st  %l0, [ %o1 ]
a01024a0:  80 a2 20 02  cmp  %o0, 2
a01024a4:  08 80 00 05  bleu  0xa01024b8
a01024a8:  01 00 00 00  nop
a01024ac:  b2 13 21 e4  or  %o4, 0x1e4, %i1
a01024b0:  d8 0a e0 0d  ldub  [ %o3 + 0xd ], %o4
a01024b4:  d8 26 40 00  st  %o4, [ %i1 ]
a01024b8:  7f ff fe 79  call  0xa0101e9c
a01024bc:  90 0a 20 ff  and  %o0, 0xff, %o0
a01024c0:  a0 0e 20 ff  and  %i0, 0xff, %l0
a01024c4:  f2 06 a2 a4  ld  [ %i2 + 0x2a4 ], %i1
a01024c8:  d4 16 60 2c  lduh  [ %i1 + 0x2c ], %o2
a01024cc:  90 10 00 10  mov  %l0, %o0
a01024d0:  7f ff bf ee  call  0xa00f2488
a01024d4:  92 10 20 5b  mov  0x5b, %o1
a01024d8:  d2 06 a2 a4  ld  [ %i2 + 0x2a4 ], %o1
a01024dc:  d4 0a 60 31  ldub  [ %o1 + 0x31 ], %o2
a01024e0:  90 10 00 10  mov  %l0, %o0
a01024e4:  7f ff bf e9  call  0xa00f2488
a01024e8:  92 10 20 be  mov  0xbe, %o1
a01024ec:  de 06 a2 a4  ld  [ %i2 + 0x2a4 ], %o7
a01024f0:  da 13 e0 32  lduh  [ %o7 + 0x32 ], %o5
a01024f4:  d0 13 e0 30  lduh  [ %o7 + 0x30 ], %o0
a01024f8:  82 02 00 0d  add  %o0, %o5, %g1
a01024fc:  95 28 60 10  sll  %g1, 0x10, %o2
a0102500:  90 10 00 10  mov  %l0, %o0
a0102504:  95 32 a0 10  srl  %o2, 0x10, %o2
a0102508:  7f ff bf e0  call  0xa00f2488
a010250c:  92 10 20 62  mov  0x62, %o1
a0102510:  d6 06 a2 a4  ld  [ %i2 + 0x2a4 ], %o3
a0102514:  d4 12 e0 0a  lduh  [ %o3 + 0xa ], %o2
a0102518:  90 10 00 10  mov  %l0, %o0
a010251c:  7f ff bf db  call  0xa00f2488
a0102520:  92 10 20 64  mov  0x64, %o1
a0102524:  f0 06 a2 a4  ld  [ %i2 + 0x2a4 ], %i0
a0102528:  d8 16 20 32  lduh  [ %i0 + 0x32 ], %o4
a010252c:  f2 16 20 30  lduh  [ %i0 + 0x30 ], %i1
a0102530:  92 06 40 0c  add  %i1, %o4, %o1
a0102534:  9f 2a 60 10  sll  %o1, 0x10, %o7
a0102538:  95 33 e0 10  srl  %o7, 0x10, %o2
a010253c:  90 10 00 10  mov  %l0, %o0
a0102540:  7f ff bf d2  call  0xa00f2488
a0102544:  92 10 20 6f  mov  0x6f, %o1
a0102548:  da 06 a2 a4  ld  [ %i2 + 0x2a4 ], %o5
a010254c:  d4 13 60 0a  lduh  [ %o5 + 0xa ], %o2
a0102550:  90 10 00 10  mov  %l0, %o0
a0102554:  7f ff bf cd  call  0xa00f2488
a0102558:  92 10 20 71  mov  0x71, %o1
a010255c:  d0 06 a2 a4  ld  [ %i2 + 0x2a4 ], %o0
a0102560:  d4 12 20 22  lduh  [ %o0 + 0x22 ], %o2
a0102564:  90 10 00 10  mov  %l0, %o0
a0102568:  7f ff bf c8  call  0xa00f2488
a010256c:  92 10 20 5e  mov  0x5e, %o1
a0102570:  c2 06 a2 a4  ld  [ %i2 + 0x2a4 ], %g1
a0102574:  d4 10 60 26  lduh  [ %g1 + 0x26 ], %o2
a0102578:  90 10 00 10  mov  %l0, %o0
a010257c:  7f ff bf c3  call  0xa00f2488
a0102580:  92 10 20 a0  mov  0xa0, %o1
a0102584:  d4 06 a2 a4  ld  [ %i2 + 0x2a4 ], %o2
a0102588:  d6 12 a0 28  lduh  [ %o2 + 0x28 ], %o3
a010258c:  f0 12 a0 26  lduh  [ %o2 + 0x26 ], %i0
a0102590:  98 06 00 0b  add  %i0, %o3, %o4
a0102594:  b3 2b 20 10  sll  %o4, 0x10, %i1
a0102598:  95 36 60 10  srl  %i1, 0x10, %o2
a010259c:  90 10 00 10  mov  %l0, %o0
a01025a0:  7f ff bf ba  call  0xa00f2488
a01025a4:  92 10 20 66  mov  0x66, %o1
a01025a8:  d2 06 a2 a4  ld  [ %i2 + 0x2a4 ], %o1
a01025ac:  d4 12 60 08  lduh  [ %o1 + 8 ], %o2
a01025b0:  90 10 00 10  mov  %l0, %o0
a01025b4:  7f ff bf b5  call  0xa00f2488
a01025b8:  92 10 20 68  mov  0x68, %o1
a01025bc:  de 06 a2 a4  ld  [ %i2 + 0x2a4 ], %o7
a01025c0:  da 13 e0 28  lduh  [ %o7 + 0x28 ], %o5
a01025c4:  d0 13 e0 26  lduh  [ %o7 + 0x26 ], %o0
a01025c8:  82 02 00 0d  add  %o0, %o5, %g1
a01025cc:  95 28 60 10  sll  %g1, 0x10, %o2
a01025d0:  90 10 00 10  mov  %l0, %o0
a01025d4:  95 32 a0 10  srl  %o2, 0x10, %o2
a01025d8:  7f ff bf ac  call  0xa00f2488
a01025dc:  92 10 20 73  mov  0x73, %o1
a01025e0:  d6 06 a2 a4  ld  [ %i2 + 0x2a4 ], %o3
a01025e4:  d4 12 e0 08  lduh  [ %o3 + 8 ], %o2
a01025e8:  90 10 00 10  mov  %l0, %o0
a01025ec:  7f ff bf a7  call  0xa00f2488
a01025f0:  92 10 20 75  mov  0x75, %o1
a01025f4:  f0 06 a2 a4  ld  [ %i2 + 0x2a4 ], %i0
a01025f8:  90 10 00 10  mov  %l0, %o0
a01025fc:  d4 16 20 22  lduh  [ %i0 + 0x22 ], %o2
a0102600:  7f ff bf a2  call  0xa00f2488
a0102604:  92 10 20 79  mov  0x79, %o1
a0102608:  d8 06 a2 a4  ld  [ %i2 + 0x2a4 ], %o4
a010260c:  d4 0b 20 31  ldub  [ %o4 + 0x31 ], %o2
a0102610:  90 10 20 00  clr  %o0
a0102614:  67 fe 30 22  call  0x4008e69c
a0102618:  92 10 20 5d  mov  0x5d, %o1
a010261c:  f2 06 a2 a4  ld  [ %i2 + 0x2a4 ], %i1
a0102620:  d2 16 60 30  lduh  [ %i1 + 0x30 ], %o1
a0102624:  e0 16 60 32  lduh  [ %i1 + 0x32 ], %l0
a0102628:  9e 02 40 10  add  %o1, %l0, %o7
a010262c:  91 2b e0 10  sll  %o7, 0x10, %o0
a0102630:  95 32 20 10  srl  %o0, 0x10, %o2
a0102634:  90 10 20 00  clr  %o0
a0102638:  40 00 5a d9  call  0xa011919c
a010263c:  92 10 20 62  mov  0x62, %o1
a0102640:  c2 06 a2 a4  ld  [ %i2 + 0x2a4 ], %g1
a0102644:  d4 08 60 31  ldub  [ %g1 + 0x31 ], %o2
a0102648:  90 10 20 01  mov  1, %o0
a010264c:  67 fe 30 14  call  0x4008e69c
a0102650:  92 10 20 5d  mov  0x5d, %o1
a0102654:  da 06 a2 a4  ld  [ %i2 + 0x2a4 ], %o5
a0102658:  d4 13 60 32  lduh  [ %o5 + 0x32 ], %o2
a010265c:  d6 13 60 30  lduh  [ %o5 + 0x30 ], %o3
a0102660:  b0 02 c0 0a  add  %o3, %o2, %i0
a0102664:  b5 2e 20 10  sll  %i0, 0x10, %i2
a0102668:  b5 36 a0 10  srl  %i2, 0x10, %i2
a010266c:  b0 10 20 01  mov  1, %i0
a0102670:  40 00 5a cb  call  0xa011919c
a0102674:  93 e8 20 62  restore  %g0, 0x62, %o1
a0102678:  10 bf ff 73  b  0xa0102444
a010267c:  9a 13 20 10  or  %o4, 0x10, %o5
