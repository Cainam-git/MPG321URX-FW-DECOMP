# leon2m FUN_a010d530 0xa010d530-0xa010d838 (776 bytes)
a010d530:  9d e3 bf 98  save  %sp, -104, %sp
a010d534:  9e 10 00 18  mov  %i0, %o7
a010d538:  b0 0e 20 ff  and  %i0, 0xff, %i0
a010d53c:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010d540:  98 10 00 1b  mov  %i3, %o4
a010d544:  80 a6 20 01  cmp  %i0, 1
a010d548:  02 80 00 06  be  0xa010d560
a010d54c:  82 10 63 c4  or  %g1, 0x3c4, %g1
a010d550:  37 2a 00 b5  sethi  %hi(0xa802d400), %i3
a010d554:  80 a6 20 02  cmp  %i0, 2
a010d558:  02 80 00 b3  be  0xa010d824
a010d55c:  82 16 e3 44  or  %i3, 0x344, %g1
a010d560:  d8 28 60 3d  stb  %o4, [ %g1 + 0x3d ]
a010d564:  f2 28 60 3b  stb  %i1, [ %g1 + 0x3b ]
a010d568:  f4 28 60 3c  stb  %i2, [ %g1 + 0x3c ]
a010d56c:  80 a6 20 02  cmp  %i0, 2
a010d570:  08 80 00 03  bleu  0xa010d57c
a010d574:  b8 10 00 0f  mov  %o7, %i4
a010d578:  b8 10 20 00  clr  %i4
a010d57c:  82 0e 60 ff  and  %i1, 0xff, %g1
a010d580:  b7 28 60 08  sll  %g1, 8, %i3
a010d584:  ba 26 c0 01  sub  %i3, %g1, %i5
a010d588:  03 14 7a e1  sethi  %hi(0x51eb8400), %g1
a010d58c:  b2 07 60 32  add  %i5, 0x32, %i1
a010d590:  82 10 61 1f  or  %g1, 0x11f, %g1
a010d594:  b6 0f 20 ff  and  %i4, 0xff, %i3
a010d598:  80 56 40 01  umul  %i1, %g1, %g0
a010d59c:  bb 40 00 00  rd  %y, %i5
a010d5a0:  83 2e e0 02  sll  %i3, 2, %g1
a010d5a4:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010d5a8:  b6 13 62 d8  or  %o5, 0x2d8, %i3	! 0x19aed8
a010d5ac:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010d5b0:  bb 37 60 05  srl  %i5, 5, %i5
a010d5b4:  f8 06 60 f4  ld  [ %i1 + 0xf4 ], %i4
a010d5b8:  b2 07 7f 80  add  %i5, -128, %i1
a010d5bc:  03 00 3f c0  sethi  %hi(0xff0000), %g1
a010d5c0:  82 2f 00 01  andn  %i4, %g1, %g1
a010d5c4:  bb 2e 60 10  sll  %i1, 0x10, %i5
a010d5c8:  80 a6 20 02  cmp  %i0, 2
a010d5cc:  08 80 00 62  bleu  0xa010d754
a010d5d0:  b2 10 40 1d  or  %g1, %i5, %i1
a010d5d4:  b8 10 20 00  clr  %i4
a010d5d8:  83 2f 20 02  sll  %i4, 2, %g1
a010d5dc:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010d5e0:  b8 07 20 01  inc  %i4
a010d5e4:  f2 27 60 f4  st  %i1, [ %i5 + 0xf4 ]
a010d5e8:  80 a7 20 02  cmp  %i4, 2
a010d5ec:  28 bf ff fc  bleu,a   0xa010d5dc
a010d5f0:  83 2f 20 02  sll  %i4, 2, %g1
a010d5f4:  80 a6 20 02  cmp  %i0, 2
a010d5f8:  18 80 00 5d  bgu  0xa010d76c
a010d5fc:  17 00 06 6b  sethi  %hi(0x19ac00), %o3
a010d600:  ba 12 e2 cc  or  %o3, 0x2cc, %i5	! 0x19aecc
a010d604:  b9 2e 20 02  sll  %i0, 2, %i4
a010d608:  f6 07 40 1c  ld  [ %i5 + %i4 ], %i3
a010d60c:  f2 26 e0 f4  st  %i1, [ %i3 + 0xf4 ]
a010d610:  80 a6 20 02  cmp  %i0, 2
a010d614:  08 80 00 03  bleu  0xa010d620
a010d618:  b8 10 00 0f  mov  %o7, %i4
a010d61c:  b8 10 20 00  clr  %i4
a010d620:  ba 0e a0 ff  and  %i2, 0xff, %i5
a010d624:  b3 2f 60 08  sll  %i5, 8, %i1
a010d628:  b6 26 40 1d  sub  %i1, %i5, %i3
a010d62c:  b2 0f 20 ff  and  %i4, 0xff, %i1
a010d630:  ba 06 e0 32  add  %i3, 0x32, %i5
a010d634:  35 14 7a e1  sethi  %hi(0x51eb8400), %i2
a010d638:  b7 2e 60 02  sll  %i1, 2, %i3
a010d63c:  82 16 a1 1f  or  %i2, 0x11f, %g1
a010d640:  80 57 40 01  umul  %i5, %g1, %g0
a010d644:  b5 40 00 00  rd  %y, %i2
a010d648:  b2 13 62 d8  or  %o5, 0x2d8, %i1
a010d64c:  c2 06 40 1b  ld  [ %i1 + %i3 ], %g1
a010d650:  37 00 3f c0  sethi  %hi(0xff0000), %i3
a010d654:  bb 36 a0 05  srl  %i2, 5, %i5
a010d658:  f8 00 60 f8  ld  [ %g1 + 0xf8 ], %i4
a010d65c:  b4 07 7f 80  add  %i5, -128, %i2
a010d660:  82 2f 00 1b  andn  %i4, %i3, %g1
a010d664:  b7 2e a0 10  sll  %i2, 0x10, %i3
a010d668:  80 a6 20 02  cmp  %i0, 2
a010d66c:  08 80 00 4b  bleu  0xa010d798
a010d670:  b4 10 40 1b  or  %g1, %i3, %i2
a010d674:  b8 10 20 00  clr  %i4
a010d678:  83 2f 20 02  sll  %i4, 2, %g1
a010d67c:  f6 06 40 01  ld  [ %i1 + %g1 ], %i3
a010d680:  b8 07 20 01  inc  %i4
a010d684:  f4 26 e0 f8  st  %i2, [ %i3 + 0xf8 ]
a010d688:  80 a7 20 02  cmp  %i4, 2
a010d68c:  28 bf ff fc  bleu,a   0xa010d67c
a010d690:  83 2f 20 02  sll  %i4, 2, %g1
a010d694:  80 a6 20 02  cmp  %i0, 2
a010d698:  18 80 00 47  bgu  0xa010d7b4
a010d69c:  37 00 06 6b  sethi  %hi(0x19ac00), %i3
a010d6a0:  b6 12 e2 cc  or  %o3, 0x2cc, %i3
a010d6a4:  b9 2e 20 02  sll  %i0, 2, %i4
a010d6a8:  f2 06 c0 1c  ld  [ %i3 + %i4 ], %i1
a010d6ac:  f4 26 60 f8  st  %i2, [ %i1 + 0xf8 ]
a010d6b0:  80 a6 20 02  cmp  %i0, 2
a010d6b4:  08 80 00 03  bleu  0xa010d6c0
a010d6b8:  b8 10 00 0f  mov  %o7, %i4
a010d6bc:  b8 10 20 00  clr  %i4
a010d6c0:  b4 0b 20 ff  and  %o4, 0xff, %i2
a010d6c4:  b7 2e a0 08  sll  %i2, 8, %i3
a010d6c8:  ba 26 c0 1a  sub  %i3, %i2, %i5
a010d6cc:  33 14 7a e1  sethi  %hi(0x51eb8400), %i1
a010d6d0:  b4 07 60 32  add  %i5, 0x32, %i2
a010d6d4:  82 16 61 1f  or  %i1, 0x11f, %g1
a010d6d8:  80 56 80 01  umul  %i2, %g1, %g0
a010d6dc:  b3 40 00 00  rd  %y, %i1
a010d6e0:  b8 0f 20 ff  and  %i4, 0xff, %i4
a010d6e4:  b7 2f 20 02  sll  %i4, 2, %i3
a010d6e8:  b4 13 62 d8  or  %o5, 0x2d8, %i2
a010d6ec:  c2 06 80 1b  ld  [ %i2 + %i3 ], %g1
a010d6f0:  bb 36 60 05  srl  %i1, 5, %i5
a010d6f4:  37 00 3f c0  sethi  %hi(0xff0000), %i3
a010d6f8:  f8 00 60 fc  ld  [ %g1 + 0xfc ], %i4
a010d6fc:  b2 07 7f 80  add  %i5, -128, %i1
a010d700:  82 2f 00 1b  andn  %i4, %i3, %g1
a010d704:  bb 2e 60 10  sll  %i1, 0x10, %i5
a010d708:  80 a6 20 02  cmp  %i0, 2
a010d70c:  08 80 00 35  bleu  0xa010d7e0
a010d710:  b6 10 40 1d  or  %g1, %i5, %i3
a010d714:  b8 10 20 00  clr  %i4
a010d718:  83 2f 20 02  sll  %i4, 2, %g1
a010d71c:  f2 06 80 01  ld  [ %i2 + %g1 ], %i1
a010d720:  b8 07 20 01  inc  %i4
a010d724:  f6 26 60 fc  st  %i3, [ %i1 + 0xfc ]
a010d728:  80 a7 20 02  cmp  %i4, 2
a010d72c:  28 bf ff fc  bleu,a   0xa010d71c
a010d730:  83 2f 20 02  sll  %i4, 2, %g1
a010d734:  80 a6 20 02  cmp  %i0, 2
a010d738:  38 80 00 31  bgu,a   0xa010d7fc
a010d73c:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010d740:  ba 12 e2 cc  or  %o3, 0x2cc, %i5
a010d744:  b9 2e 20 02  sll  %i0, 2, %i4
a010d748:  f4 07 40 1c  ld  [ %i5 + %i4 ], %i2
a010d74c:  f6 26 a0 fc  st  %i3, [ %i2 + 0xfc ]
a010d750:  30 80 00 38  b,a   0xa010d830
a010d754:  bb 2e 20 02  sll  %i0, 2, %i5
a010d758:  f8 06 c0 1d  ld  [ %i3 + %i5 ], %i4
a010d75c:  f2 27 20 f4  st  %i1, [ %i4 + 0xf4 ]
a010d760:  80 a6 20 02  cmp  %i0, 2
a010d764:  08 bf ff a7  bleu  0xa010d600
a010d768:  17 00 06 6b  sethi  %hi(0x19ac00), %o3
a010d76c:  b8 10 20 00  clr  %i4
a010d770:  b6 12 e2 cc  or  %o3, 0x2cc, %i3
a010d774:  83 2f 20 02  sll  %i4, 2, %g1
a010d778:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010d77c:  b8 07 20 01  inc  %i4
a010d780:  f2 27 60 f4  st  %i1, [ %i5 + 0xf4 ]
a010d784:  80 a7 20 02  cmp  %i4, 2
a010d788:  08 bf ff fc  bleu  0xa010d778
a010d78c:  83 2f 20 02  sll  %i4, 2, %g1
a010d790:  10 bf ff a1  b  0xa010d614
a010d794:  80 a6 20 02  cmp  %i0, 2
a010d798:  bb 2e 20 02  sll  %i0, 2, %i5
a010d79c:  f8 06 40 1d  ld  [ %i1 + %i5 ], %i4
a010d7a0:  f4 27 20 f8  st  %i2, [ %i4 + 0xf8 ]
a010d7a4:  80 a6 20 02  cmp  %i0, 2
a010d7a8:  08 bf ff bf  bleu  0xa010d6a4
a010d7ac:  b6 12 e2 cc  or  %o3, 0x2cc, %i3
a010d7b0:  37 00 06 6b  sethi  %hi(0x19ac00), %i3
a010d7b4:  b2 16 e2 cc  or  %i3, 0x2cc, %i1	! 0x19aecc
a010d7b8:  b8 10 20 00  clr  %i4
a010d7bc:  83 2f 20 02  sll  %i4, 2, %g1
a010d7c0:  fa 06 40 01  ld  [ %i1 + %g1 ], %i5
a010d7c4:  b8 07 20 01  inc  %i4
a010d7c8:  f4 27 60 f8  st  %i2, [ %i5 + 0xf8 ]
a010d7cc:  80 a7 20 02  cmp  %i4, 2
a010d7d0:  08 bf ff fc  bleu  0xa010d7c0
a010d7d4:  83 2f 20 02  sll  %i4, 2, %g1
a010d7d8:  10 bf ff b7  b  0xa010d6b4
a010d7dc:  80 a6 20 02  cmp  %i0, 2
a010d7e0:  bb 2e 20 02  sll  %i0, 2, %i5
a010d7e4:  f8 06 80 1d  ld  [ %i2 + %i5 ], %i4
a010d7e8:  f6 27 20 fc  st  %i3, [ %i4 + 0xfc ]
a010d7ec:  80 a6 20 02  cmp  %i0, 2
a010d7f0:  08 bf ff d5  bleu  0xa010d744
a010d7f4:  ba 12 e2 cc  or  %o3, 0x2cc, %i5
a010d7f8:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010d7fc:  b4 16 22 cc  or  %i0, 0x2cc, %i2	! 0x19aecc
a010d800:  b8 10 20 00  clr  %i4
a010d804:  83 2f 20 02  sll  %i4, 2, %g1
a010d808:  f2 06 80 01  ld  [ %i2 + %g1 ], %i1
a010d80c:  b8 07 20 01  inc  %i4
a010d810:  f6 26 60 fc  st  %i3, [ %i1 + 0xfc ]
a010d814:  80 a7 20 02  cmp  %i4, 2
a010d818:  08 bf ff fc  bleu  0xa010d808
a010d81c:  83 2f 20 02  sll  %i4, 2, %g1
a010d820:  30 80 00 04  b,a   0xa010d830
a010d824:  39 2a 00 b5  sethi  %hi(0xa802d400), %i4
a010d828:  10 bf ff 4e  b  0xa010d560
a010d82c:  82 17 23 84  or  %i4, 0x384, %g1	! 0xa802d784
a010d830:  81 c7 e0 08  ret
a010d834:  81 e8 00 00  restore
