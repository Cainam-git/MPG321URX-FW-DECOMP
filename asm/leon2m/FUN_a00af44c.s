# leon2m FUN_a00af44c 0xa00af44c-0xa00b0034 (64 bytes)
a00af44c:  9d e3 bf 98  save  %sp, -104, %sp
a00af450:  7f ff e6 0e  call  0xa00a8c88
a00af454:  01 00 00 00  nop
a00af458:  91 2e 20 10  sll  %i0, 0x10, %o0
a00af45c:  83 32 20 10  srl  %o0, 0x10, %g1
a00af460:  82 00 7f f5  add  %g1, -11, %g1
a00af464:  80 a0 60 29  cmp  %g1, 0x29
a00af468:  18 80 02 f1  bgu  0xa00b002c
a00af46c:  15 00 01 10  sethi  %hi(0x44000), %o2
a00af470:  93 28 60 02  sll  %g1, 2, %o1
a00af474:  9a 12 a1 54  or  %o2, 0x154, %o5
a00af478:  d8 03 40 09  ld  [ %o5 + %o1 ], %o4
a00af47c:  81 c3 00 00  jmp  %o4
a00af480:  01 00 00 00  nop
a00af484:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00af488:  80 a6 60 00  cmp  %i1, 0
a00af48c:  02 80 00 f5  be  0xa00af860
a00af490:  80 a6 60 01  cmp  %i1, 1
a00af494:  02 80 01 b7  be  0xa00afb70
a00af498:  80 a6 60 02  cmp  %i1, 2
a00af49c:  02 80 00 7e  be  0xa00af694
a00af4a0:  80 a6 60 03  cmp  %i1, 3
a00af4a4:  02 80 01 fb  be  0xa00afc90
a00af4a8:  80 a6 60 04  cmp  %i1, 4
a00af4ac:  02 80 01 ec  be  0xa00afc5c
a00af4b0:  80 a6 60 05  cmp  %i1, 5
a00af4b4:  02 80 00 78  be  0xa00af694
a00af4b8:  80 a6 60 06  cmp  %i1, 6
a00af4bc:  12 80 02 dc  bne  0xa00b002c
a00af4c0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00af4c4:  30 80 00 75  b,a   0xa00af698
a00af4c8:  b6 0e 60 ff  and  %i1, 0xff, %i3
a00af4cc:  a2 06 e0 34  add  %i3, 0x34, %l1
a00af4d0:  a1 2c 60 10  sll  %l1, 0x10, %l0
a00af4d4:  b1 34 20 10  srl  %l0, 0x10, %i0
a00af4d8:  7f ff f4 90  call  0xa00ac718
a00af4dc:  81 e8 00 00  restore
a00af4e0:  b0 0e 60 ff  and  %i1, 0xff, %i0
a00af4e4:  80 a6 20 00  cmp  %i0, 0
a00af4e8:  02 80 00 e2  be  0xa00af870
a00af4ec:  80 a6 20 01  cmp  %i0, 1
a00af4f0:  02 80 01 7c  be  0xa00afae0
a00af4f4:  80 a6 20 02  cmp  %i0, 2
a00af4f8:  12 80 02 cd  bne  0xa00b002c
a00af4fc:  01 00 00 00  nop
a00af500:  40 00 21 79  call  0xa00b7ae4
a00af504:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00af508:  e0 0c 62 da  ldub  [ %l1 + 0x2da ], %l0	! 0xa802d2da
a00af50c:  b0 04 20 02  add  %l0, 2, %i0
a00af510:  10 80 00 0d  b  0xa00af544
a00af514:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00af518:  b0 0e 60 ff  and  %i1, 0xff, %i0
a00af51c:  80 a6 20 00  cmp  %i0, 0
a00af520:  02 80 00 d9  be  0xa00af884
a00af524:  80 a6 20 02  cmp  %i0, 2
a00af528:  12 80 02 c1  bne  0xa00b002c
a00af52c:  01 00 00 00  nop
a00af530:  40 00 1e 3b  call  0xa00b6e1c
a00af534:  01 00 00 00  nop
a00af538:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00af53c:  d0 12 62 c4  lduh  [ %o1 + 0x2c4 ], %o0	! 0xa802d2c4
a00af540:  b0 0a 20 0f  and  %o0, 0xf, %i0
a00af544:  7f ff e8 43  call  0xa00a9650
a00af548:  93 e8 20 02  restore  %g0, 2, %o1
a00af54c:  b0 0e 60 ff  and  %i1, 0xff, %i0
a00af550:  80 a6 20 00  cmp  %i0, 0
a00af554:  02 80 00 c1  be  0xa00af858
a00af558:  80 a6 20 01  cmp  %i0, 1
a00af55c:  02 80 01 59  be  0xa00afac0
a00af560:  80 a6 20 02  cmp  %i0, 2
a00af564:  02 80 01 5b  be  0xa00afad0
a00af568:  80 a6 20 03  cmp  %i0, 3
a00af56c:  02 80 02 1a  be  0xa00afdd4
a00af570:  80 a6 20 04  cmp  %i0, 4
a00af574:  02 80 02 53  be  0xa00afec0
a00af578:  80 a6 20 05  cmp  %i0, 5
a00af57c:  12 80 02 ac  bne  0xa00b002c
a00af580:  90 10 21 11  mov  0x111, %o0
a00af584:  40 02 5d 73  call  0xa0146b50
a00af588:  92 10 20 00  clr  %o1
a00af58c:  90 10 20 00  clr  %o0
a00af590:  92 10 20 00  clr  %o1
a00af594:  40 02 5d 76  call  0xa0146b6c
a00af598:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a00af59c:  a2 10 20 00  clr  %l1
a00af5a0:  a0 10 20 00  clr  %l0
a00af5a4:  3b 00 06 43  sethi  %hi(0x190c00), %i5
a00af5a8:  b8 16 e2 90  or  %i3, 0x290, %i4
a00af5ac:  97 2c 20 03  sll  %l0, 3, %o3
a00af5b0:  94 22 c0 10  sub  %o3, %l0, %o2
a00af5b4:  93 2a a0 02  sll  %o2, 2, %o1
a00af5b8:  90 02 40 10  add  %o1, %l0, %o0
a00af5bc:  da 0f 20 08  ldub  [ %i4 + 8 ], %o5
a00af5c0:  b4 02 00 0d  add  %o0, %o5, %i2
a00af5c4:  b3 2e a0 10  sll  %i2, 0x10, %i1
a00af5c8:  93 36 60 10  srl  %i1, 0x10, %o1
a00af5cc:  7f ff d0 9e  call  0xa00a3844
a00af5d0:  90 17 60 ec  or  %i5, 0xec, %o0
a00af5d4:  98 10 00 08  mov  %o0, %o4
a00af5d8:  b0 04 00 10  add  %l0, %l0, %i0
a00af5dc:  94 06 20 06  add  %i0, 6, %o2
a00af5e0:  90 10 20 00  clr  %o0
a00af5e4:  92 10 20 2a  mov  0x2a, %o1
a00af5e8:  96 10 20 01  mov  1, %o3
a00af5ec:  9a 10 20 00  clr  %o5
a00af5f0:  7f ff ce ed  call  0xa00a31a4
a00af5f4:  a2 04 60 01  inc  %l1
a00af5f8:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00af5fc:  80 a4 20 02  cmp  %l0, 2
a00af600:  08 bf ff ec  bleu  0xa00af5b0
a00af604:  97 2c 20 03  sll  %l0, 3, %o3
a00af608:  c2 07 20 ac  ld  [ %i4 + 0xac ], %g1
a00af60c:  99 30 60 12  srl  %g1, 0x12, %o4
a00af610:  82 0b 20 03  and  %o4, 3, %g1
a00af614:  9e 00 40 01  add  %g1, %g1, %o7
a00af618:  80 a0 60 06  cmp  %g1, 6
a00af61c:  08 80 00 04  bleu  0xa00af62c
a00af620:  9a 03 e0 06  add  %o7, 6, %o5
a00af624:  ba 00 40 01  add  %g1, %g1, %i5
a00af628:  9a 07 7f f8  add  %i5, -8, %o5
a00af62c:  a2 0b 60 ff  and  %o5, 0xff, %l1
a00af630:  90 10 20 00  clr  %o0
a00af634:  92 10 20 28  mov  0x28, %o1
a00af638:  94 10 00 11  mov  %l1, %o2
a00af63c:  96 10 20 01  mov  1, %o3
a00af640:  98 10 20 0f  mov  0xf, %o4
a00af644:  40 02 5d 37  call  0xa0146b20
a00af648:  9a 10 20 00  clr  %o5
a00af64c:  94 10 00 11  mov  %l1, %o2
a00af650:  90 10 20 00  clr  %o0
a00af654:  92 10 20 29  mov  0x29, %o1
a00af658:  96 10 20 01  mov  1, %o3
a00af65c:  98 10 20 10  mov  0x10, %o4
a00af660:  9a 10 20 00  clr  %o5
a00af664:  40 02 5d 2f  call  0xa0146b20
a00af668:  b8 16 e2 90  or  %i3, 0x290, %i4
a00af66c:  e0 07 20 ac  ld  [ %i4 + 0xac ], %l0
a00af670:  b7 34 20 12  srl  %l0, 0x12, %i3
a00af674:  10 bf ff b4  b  0xa00af544
a00af678:  b0 0e e0 03  and  %i3, 3, %i0
a00af67c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00af680:  80 a6 60 01  cmp  %i1, 1
a00af684:  02 80 00 e2  be  0xa00afa0c
a00af688:  80 a6 60 02  cmp  %i1, 2
a00af68c:  02 80 01 09  be  0xa00afab0
a00af690:  01 00 00 00  nop
a00af694:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00af698:  7f ff fd eb  call  0xa00aee44
a00af69c:  81 e8 00 00  restore
a00af6a0:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00af6a4:  b0 14 62 90  or  %l1, 0x290, %i0	! 0xa802d290
a00af6a8:  f8 0e 21 a3  ldub  [ %i0 + 0x1a3 ], %i4
a00af6ac:  a0 07 00 18  add  %i4, %i0, %l0
a00af6b0:  fa 0c 21 8a  ldub  [ %l0 + 0x18a ], %i5
a00af6b4:  80 a7 60 06  cmp  %i5, 6
a00af6b8:  08 80 00 66  bleu  0xa00af850
a00af6bc:  90 10 20 01  mov  1, %o0
a00af6c0:  40 00 21 33  call  0xa00b7b8c
a00af6c4:  a2 14 62 90  or  %l1, 0x290, %l1
a00af6c8:  f8 0c 61 a3  ldub  [ %l1 + 0x1a3 ], %i4
a00af6cc:  a0 07 00 11  add  %i4, %l1, %l0
a00af6d0:  d2 0c 21 8a  ldub  [ %l0 + 0x18a ], %o1
a00af6d4:  3b 09 24 92  sethi  %hi(0x24924800), %i5
a00af6d8:  a0 17 61 25  or  %i5, 0x125, %l0	! 0x24924925
a00af6dc:  80 52 40 10  umul  %o1, %l0, %g0
a00af6e0:  99 40 00 00  rd  %y, %o4
a00af6e4:  b6 22 40 0c  sub  %o1, %o4, %i3
a00af6e8:  83 36 e0 01  srl  %i3, 1, %g1
a00af6ec:  9e 03 00 01  add  %o4, %g1, %o7
a00af6f0:  97 33 e0 02  srl  %o7, 2, %o3
a00af6f4:  95 2a e0 03  sll  %o3, 3, %o2
a00af6f8:  9a 22 80 0b  sub  %o2, %o3, %o5
a00af6fc:  90 22 40 0d  sub  %o1, %o5, %o0
a00af700:  90 0a 20 ff  and  %o0, 0xff, %o0
a00af704:  7f ff e7 d3  call  0xa00a9650
a00af708:  92 10 20 02  mov  2, %o1
a00af70c:  f4 0c 61 a3  ldub  [ %l1 + 0x1a3 ], %i2
a00af710:  b2 06 80 11  add  %i2, %l1, %i1
a00af714:  da 0e 61 8a  ldub  [ %i1 + 0x18a ], %o5
a00af718:  80 53 40 10  umul  %o5, %l0, %g0
a00af71c:  99 40 00 00  rd  %y, %o4
a00af720:  b6 23 40 0c  sub  %o5, %o4, %i3
a00af724:  83 36 e0 01  srl  %i3, 1, %g1
a00af728:  9e 03 00 01  add  %o4, %g1, %o7
a00af72c:  97 33 e0 02  srl  %o7, 2, %o3
a00af730:  95 2a e0 03  sll  %o3, 3, %o2
a00af734:  92 22 80 0b  sub  %o2, %o3, %o1
a00af738:  90 23 40 09  sub  %o5, %o1, %o0
a00af73c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00af740:  b0 03 40 0d  add  %o5, %o5, %i0
a00af744:  80 a3 60 06  cmp  %o5, 6
a00af748:  08 80 00 04  bleu  0xa00af758
a00af74c:  82 06 20 06  add  %i0, 6, %g1
a00af750:  ba 03 40 0d  add  %o5, %o5, %i5
a00af754:  82 07 7f f8  add  %i5, -8, %g1
a00af758:  b4 08 60 ff  and  %g1, 0xff, %i2
a00af75c:  90 10 20 00  clr  %o0
a00af760:  92 10 20 28  mov  0x28, %o1
a00af764:  94 10 00 1a  mov  %i2, %o2
a00af768:  96 10 20 01  mov  1, %o3
a00af76c:  98 10 20 0f  mov  0xf, %o4
a00af770:  40 02 5c ec  call  0xa0146b20
a00af774:  9a 10 20 00  clr  %o5
a00af778:  b0 10 20 00  clr  %i0
a00af77c:  b2 10 20 29  mov  0x29, %i1
a00af780:  b6 10 20 01  mov  1, %i3
a00af784:  b8 10 20 10  mov  0x10, %i4
a00af788:  40 02 5c e6  call  0xa0146b20
a00af78c:  9b e8 20 00  restore  %g0, 0, %o5
a00af790:  b0 0e 60 ff  and  %i1, 0xff, %i0
a00af794:  80 a6 20 00  cmp  %i0, 0
a00af798:  02 80 00 81  be  0xa00af99c
a00af79c:  80 a6 20 01  cmp  %i0, 1
a00af7a0:  02 80 00 c6  be  0xa00afab8
a00af7a4:  80 a6 20 02  cmp  %i0, 2
a00af7a8:  02 80 00 c8  be  0xa00afac8
a00af7ac:  80 a6 20 03  cmp  %i0, 3
a00af7b0:  02 80 00 ca  be  0xa00afad8
a00af7b4:  80 a6 20 04  cmp  %i0, 4
a00af7b8:  02 80 01 30  be  0xa00afc78
a00af7bc:  80 a6 20 09  cmp  %i0, 9
a00af7c0:  12 80 02 1b  bne  0xa00b002c
a00af7c4:  90 10 21 11  mov  0x111, %o0
a00af7c8:  40 02 5c e2  call  0xa0146b50
a00af7cc:  92 10 20 00  clr  %o1
a00af7d0:  90 10 20 00  clr  %o0
a00af7d4:  40 02 5c e6  call  0xa0146b6c
a00af7d8:  92 10 20 00  clr  %o1
a00af7dc:  a2 10 20 00  clr  %l1
a00af7e0:  39 2a 00 b4  sethi  %hi(0xa802d000), %i4
a00af7e4:  a0 10 20 00  clr  %l0
a00af7e8:  3b 00 06 41  sethi  %hi(0x190400), %i5
a00af7ec:  83 2c 20 03  sll  %l0, 3, %g1
a00af7f0:  98 20 40 10  sub  %g1, %l0, %o4
a00af7f4:  9f 2b 20 02  sll  %o4, 2, %o7
a00af7f8:  96 17 22 90  or  %i4, 0x290, %o3
a00af7fc:  92 03 c0 10  add  %o7, %l0, %o1
a00af800:  d4 0a e0 08  ldub  [ %o3 + 8 ], %o2
a00af804:  90 02 40 0a  add  %o1, %o2, %o0
a00af808:  b1 2a 20 10  sll  %o0, 0x10, %i0
a00af80c:  93 36 20 10  srl  %i0, 0x10, %o1
a00af810:  7f ff d0 0d  call  0xa00a3844
a00af814:  90 17 63 48  or  %i5, 0x348, %o0
a00af818:  98 10 00 08  mov  %o0, %o4
a00af81c:  b4 04 00 10  add  %l0, %l0, %i2
a00af820:  94 06 a0 06  add  %i2, 6, %o2
a00af824:  90 10 20 00  clr  %o0
a00af828:  92 10 20 2a  mov  0x2a, %o1
a00af82c:  96 10 20 01  mov  1, %o3
a00af830:  9a 10 20 00  clr  %o5
a00af834:  7f ff ce 5c  call  0xa00a31a4
a00af838:  a2 04 60 01  inc  %l1
a00af83c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00af840:  80 a4 20 01  cmp  %l0, 1
a00af844:  08 bf ff eb  bleu  0xa00af7f0
a00af848:  83 2c 20 03  sll  %l0, 3, %g1
a00af84c:  30 80 01 f8  b,a   0xa00b002c
a00af850:  10 bf ff 9c  b  0xa00af6c0
a00af854:  90 10 20 00  clr  %o0
a00af858:  40 00 1d ff  call  0xa00b7054
a00af85c:  81 e8 00 00  restore
a00af860:  40 00 1a 47  call  0xa00b617c
a00af864:  39 2a 00 b5  sethi  %hi(0xa802d400), %i4
a00af868:  10 bf ff 37  b  0xa00af544
a00af86c:  f0 0f 20 12  ldub  [ %i4 + 0x12 ], %i0	! 0xa802d412
a00af870:  40 00 20 75  call  0xa00b7a44
a00af874:  01 00 00 00  nop
a00af878:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00af87c:  10 bf ff 32  b  0xa00af544
a00af880:  f0 0a e0 0c  ldub  [ %o3 + 0xc ], %i0	! 0xa802d40c
a00af884:  3b 2a 00 b4  sethi  %hi(0xa802d000), %i5
a00af888:  b2 17 62 90  or  %i5, 0x290, %i1	! 0xa802d290
a00af88c:  92 10 20 00  clr  %o1
a00af890:  40 00 1c be  call  0xa00b6b88
a00af894:  d0 0e 61 81  ldub  [ %i1 + 0x181 ], %o0
a00af898:  1b 09 24 92  sethi  %hi(0x24924800), %o5
a00af89c:  b0 13 61 25  or  %o5, 0x125, %i0	! 0x24924925
a00af8a0:  92 0a 20 ff  and  %o0, 0xff, %o1
a00af8a4:  80 52 40 18  umul  %o1, %i0, %g0
a00af8a8:  99 40 00 00  rd  %y, %o4
a00af8ac:  90 22 40 0c  sub  %o1, %o4, %o0
a00af8b0:  83 32 20 01  srl  %o0, 1, %g1
a00af8b4:  b4 03 00 01  add  %o4, %g1, %i2
a00af8b8:  9f 36 a0 02  srl  %i2, 2, %o7
a00af8bc:  90 0b e0 ff  and  %o7, 0xff, %o0
a00af8c0:  40 00 1c cb  call  0xa00b6bec
a00af8c4:  01 00 00 00  nop
a00af8c8:  92 10 20 00  clr  %o1	! 0x0
a00af8cc:  40 00 1c af  call  0xa00b6b88
a00af8d0:  d0 0e 61 81  ldub  [ %i1 + 0x181 ], %o0
a00af8d4:  92 0a 20 ff  and  %o0, 0xff, %o1
a00af8d8:  80 52 40 18  umul  %o1, %i0, %g0
a00af8dc:  95 40 00 00  rd  %y, %o2
a00af8e0:  96 22 40 0a  sub  %o1, %o2, %o3
a00af8e4:  b7 32 e0 01  srl  %o3, 1, %i3
a00af8e8:  b8 02 80 1b  add  %o2, %i3, %i4
a00af8ec:  a1 37 20 02  srl  %i4, 2, %l0
a00af8f0:  a3 2c 20 03  sll  %l0, 3, %l1
a00af8f4:  9a 24 40 10  sub  %l1, %l0, %o5
a00af8f8:  90 22 40 0d  sub  %o1, %o5, %o0
a00af8fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00af900:  98 02 00 08  add  %o0, %o0, %o4
a00af904:  80 a2 20 06  cmp  %o0, 6
a00af908:  08 80 00 04  bleu  0xa00af918
a00af90c:  82 03 20 06  add  %o4, 6, %g1
a00af910:  a2 02 00 08  add  %o0, %o0, %l1
a00af914:  82 04 7f f8  add  %l1, -8, %g1
a00af918:  a2 08 60 ff  and  %g1, 0xff, %l1
a00af91c:  90 10 20 00  clr  %o0
a00af920:  92 10 20 28  mov  0x28, %o1
a00af924:  94 10 00 11  mov  %l1, %o2
a00af928:  96 10 20 01  mov  1, %o3
a00af92c:  98 10 20 0f  mov  0xf, %o4
a00af930:  40 02 5c 7c  call  0xa0146b20
a00af934:  9a 10 20 00  clr  %o5
a00af938:  94 10 00 11  mov  %l1, %o2
a00af93c:  96 10 20 01  mov  1, %o3
a00af940:  98 10 20 10  mov  0x10, %o4
a00af944:  90 10 20 00  clr  %o0
a00af948:  92 10 20 29  mov  0x29, %o1
a00af94c:  40 02 5c 75  call  0xa0146b20
a00af950:  9a 10 20 00  clr  %o5
a00af954:  82 17 62 90  or  %i5, 0x290, %g1
a00af958:  d0 08 61 81  ldub  [ %g1 + 0x181 ], %o0
a00af95c:  40 00 1c 8b  call  0xa00b6b88
a00af960:  92 10 20 00  clr  %o1
a00af964:  19 09 24 92  sethi  %hi(0x24924800), %o4
a00af968:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00af96c:  b4 13 21 25  or  %o4, 0x125, %i2
a00af970:  80 54 00 1a  umul  %l0, %i2, %g0
a00af974:  b1 40 00 00  rd  %y, %i0
a00af978:  9e 24 00 18  sub  %l0, %i0, %o7
a00af97c:  b3 33 e0 01  srl  %o7, 1, %i1
a00af980:  96 06 00 19  add  %i0, %i1, %o3
a00af984:  b7 32 e0 02  srl  %o3, 2, %i3
a00af988:  95 2e e0 03  sll  %i3, 3, %o2
a00af98c:  b8 22 80 1b  sub  %o2, %i3, %i4
a00af990:  ba 24 00 1c  sub  %l0, %i4, %i5
a00af994:  10 bf fe ec  b  0xa00af544
a00af998:  b0 0f 60 ff  and  %i5, 0xff, %i0
a00af99c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00af9a0:  b0 14 62 90  or  %l1, 0x290, %i0	! 0xa802d290
a00af9a4:  21 09 24 92  sethi  %hi(0x24924800), %l0
a00af9a8:  f4 0e 20 08  ldub  [ %i0 + 8 ], %i2
a00af9ac:  a0 14 21 25  or  %l0, 0x125, %l0
a00af9b0:  80 56 80 10  umul  %i2, %l0, %g0
a00af9b4:  bb 40 00 00  rd  %y, %i5
a00af9b8:  b2 26 80 1d  sub  %i2, %i5, %i1
a00af9bc:  b9 36 60 01  srl  %i1, 1, %i4
a00af9c0:  b6 07 40 1c  add  %i5, %i4, %i3
a00af9c4:  83 36 e0 02  srl  %i3, 2, %g1
a00af9c8:  7f ff e3 81  call  0xa00a87cc
a00af9cc:  90 08 60 ff  and  %g1, 0xff, %o0
a00af9d0:  f4 0e 20 08  ldub  [ %i0 + 8 ], %i2
a00af9d4:  80 56 80 10  umul  %i2, %l0, %g0
a00af9d8:  97 40 00 00  rd  %y, %o3
a00af9dc:  98 26 80 0b  sub  %i2, %o3, %o4
a00af9e0:  9f 33 20 01  srl  %o4, 1, %o7
a00af9e4:  94 02 c0 0f  add  %o3, %o7, %o2
a00af9e8:  9b 32 a0 02  srl  %o2, 2, %o5
a00af9ec:  93 2b 60 03  sll  %o5, 3, %o1
a00af9f0:  90 22 40 0d  sub  %o1, %o5, %o0
a00af9f4:  b2 26 80 08  sub  %i2, %o0, %i1
a00af9f8:  90 0e 60 ff  and  %i1, 0xff, %o0
a00af9fc:  7f ff e7 15  call  0xa00a9650
a00afa00:  92 10 20 02  mov  2, %o1
a00afa04:  10 bf ff 45  b  0xa00af718
a00afa08:  da 0e 20 08  ldub  [ %i0 + 8 ], %o5
a00afa0c:  90 10 21 11  mov  0x111, %o0
a00afa10:  40 02 5c 50  call  0xa0146b50
a00afa14:  92 10 20 00  clr  %o1
a00afa18:  90 10 20 00  clr  %o0
a00afa1c:  92 10 20 00  clr  %o1
a00afa20:  40 02 5c 53  call  0xa0146b6c
a00afa24:  39 2a 00 b4  sethi  %hi(0xa802d000), %i4
a00afa28:  b4 17 22 90  or  %i4, 0x290, %i2	! 0xa802d290
a00afa2c:  f0 0e a0 20  ldub  [ %i2 + 0x20 ], %i0
a00afa30:  f2 0e a0 1e  ldub  [ %i2 + 0x1e ], %i1
a00afa34:  80 a6 40 18  cmp  %i1, %i0
a00afa38:  02 80 01 70  be  0xa00afff8
a00afa3c:  90 10 20 2a  mov  0x2a, %o0
a00afa40:  a2 10 20 00  clr  %l1
a00afa44:  a0 10 20 00  clr  %l0
a00afa48:  3b 00 06 0a  sethi  %hi(0x182800), %i5
a00afa4c:  b7 2c 20 03  sll  %l0, 3, %i3
a00afa50:  82 26 c0 10  sub  %i3, %l0, %g1
a00afa54:  99 28 60 02  sll  %g1, 2, %o4
a00afa58:  9e 17 22 90  or  %i4, 0x290, %o7
a00afa5c:  94 03 00 10  add  %o4, %l0, %o2
a00afa60:  d6 0b e0 08  ldub  [ %o7 + 8 ], %o3
a00afa64:  92 02 80 0b  add  %o2, %o3, %o1
a00afa68:  9b 2a 60 10  sll  %o1, 0x10, %o5
a00afa6c:  93 33 60 10  srl  %o5, 0x10, %o1
a00afa70:  7f ff cf 75  call  0xa00a3844
a00afa74:  90 17 60 c0  or  %i5, 0xc0, %o0
a00afa78:  98 10 00 08  mov  %o0, %o4
a00afa7c:  90 04 00 10  add  %l0, %l0, %o0
a00afa80:  94 02 20 06  add  %o0, 6, %o2
a00afa84:  90 10 20 00  clr  %o0
a00afa88:  92 10 20 2a  mov  0x2a, %o1
a00afa8c:  96 10 20 01  mov  1, %o3
a00afa90:  9a 10 20 00  clr  %o5
a00afa94:  7f ff cd c4  call  0xa00a31a4
a00afa98:  a2 04 60 01  inc  %l1
a00afa9c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00afaa0:  80 a4 20 04  cmp  %l0, 4
a00afaa4:  08 bf ff eb  bleu  0xa00afa50
a00afaa8:  b7 2c 20 03  sll  %l0, 3, %i3
a00afaac:  30 80 01 60  b,a   0xa00b002c
a00afab0:  7f ff e8 03  call  0xa00a9abc
a00afab4:  81 e8 00 00  restore
a00afab8:  40 00 1e 9e  call  0xa00b7530
a00afabc:  91 e8 20 00  restore  %g0, 0, %o0
a00afac0:  40 00 1d 18  call  0xa00b6f20
a00afac4:  91 e8 20 00  restore  %g0, 0, %o0
a00afac8:  40 00 1e eb  call  0xa00b7674
a00afacc:  91 e8 20 00  restore  %g0, 0, %o0
a00afad0:  40 00 1d ae  call  0xa00b7188
a00afad4:  91 e8 20 00  restore  %g0, 0, %o0
a00afad8:  40 00 1f 37  call  0xa00b77b4
a00afadc:  81 e8 00 00  restore
a00afae0:  90 10 21 11  mov  0x111, %o0
a00afae4:  40 02 5c 1b  call  0xa0146b50
a00afae8:  92 10 20 00  clr  %o1
a00afaec:  90 10 20 00  clr  %o0
a00afaf0:  40 02 5c 1f  call  0xa0146b6c
a00afaf4:  92 10 20 00  clr  %o1
a00afaf8:  a2 10 20 00  clr  %l1
a00afafc:  39 2a 00 b4  sethi  %hi(0xa802d000), %i4
a00afb00:  a0 10 20 00  clr  %l0
a00afb04:  3b 00 06 3e  sethi  %hi(0x18f800), %i5
a00afb08:  9b 2c 20 03  sll  %l0, 3, %o5
a00afb0c:  92 23 40 10  sub  %o5, %l0, %o1
a00afb10:  99 2a 60 02  sll  %o1, 2, %o4
a00afb14:  90 17 22 90  or  %i4, 0x290, %o0
a00afb18:  b6 03 00 10  add  %o4, %l0, %i3
a00afb1c:  c2 0a 20 08  ldub  [ %o0 + 8 ], %g1
a00afb20:  b4 06 c0 01  add  %i3, %g1, %i2
a00afb24:  b2 06 a0 1d  add  %i2, 0x1d, %i1
a00afb28:  b1 2e 60 10  sll  %i1, 0x10, %i0
a00afb2c:  93 36 20 10  srl  %i0, 0x10, %o1
a00afb30:  7f ff cf 45  call  0xa00a3844
a00afb34:  90 17 61 84  or  %i5, 0x184, %o0
a00afb38:  9e 04 00 10  add  %l0, %l0, %o7
a00afb3c:  98 10 00 08  mov  %o0, %o4
a00afb40:  94 03 e0 06  add  %o7, 6, %o2
a00afb44:  90 10 20 00  clr  %o0
a00afb48:  92 10 20 2a  mov  0x2a, %o1
a00afb4c:  96 10 20 01  mov  1, %o3
a00afb50:  9a 10 20 00  clr  %o5
a00afb54:  7f ff cd 94  call  0xa00a31a4
a00afb58:  a2 04 60 01  inc  %l1
a00afb5c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00afb60:  80 a4 20 03  cmp  %l0, 3
a00afb64:  08 bf ff ea  bleu  0xa00afb0c
a00afb68:  9b 2c 20 03  sll  %l0, 3, %o5
a00afb6c:  30 80 01 30  b,a   0xa00b002c
a00afb70:  90 10 21 11  mov  0x111, %o0
a00afb74:  40 02 5b f7  call  0xa0146b50
a00afb78:  92 10 20 00  clr  %o1
a00afb7c:  90 10 20 00  clr  %o0
a00afb80:  92 10 20 00  clr  %o1
a00afb84:  40 02 5b fa  call  0xa0146b6c
a00afb88:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a00afb8c:  a2 10 20 00  clr  %l1
a00afb90:  a0 10 20 00  clr  %l0
a00afb94:  39 00 06 24  sethi  %hi(0x189000), %i4
a00afb98:  ba 16 e2 90  or  %i3, 0x290, %i5
a00afb9c:  91 2c 20 03  sll  %l0, 3, %o0
a00afba0:  82 22 00 10  sub  %o0, %l0, %g1
a00afba4:  b5 28 60 02  sll  %g1, 2, %i2
a00afba8:  b0 06 80 10  add  %i2, %l0, %i0
a00afbac:  f2 0f 60 08  ldub  [ %i5 + 8 ], %i1
a00afbb0:  9e 06 00 19  add  %i0, %i1, %o7
a00afbb4:  97 2b e0 10  sll  %o7, 0x10, %o3
a00afbb8:  93 32 e0 10  srl  %o3, 0x10, %o1
a00afbbc:  7f ff cf 22  call  0xa00a3844
a00afbc0:  90 17 20 d4  or  %i4, 0xd4, %o0
a00afbc4:  98 10 00 08  mov  %o0, %o4
a00afbc8:  94 04 00 10  add  %l0, %l0, %o2
a00afbcc:  94 02 a0 06  add  %o2, 6, %o2
a00afbd0:  90 10 20 00  clr  %o0
a00afbd4:  92 10 20 2a  mov  0x2a, %o1
a00afbd8:  96 10 20 01  mov  1, %o3
a00afbdc:  9a 10 20 00  clr  %o5
a00afbe0:  7f ff cd 71  call  0xa00a31a4
a00afbe4:  a2 04 60 01  inc  %l1
a00afbe8:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00afbec:  80 a4 20 04  cmp  %l0, 4
a00afbf0:  08 bf ff ec  bleu  0xa00afba0
a00afbf4:  91 2c 20 03  sll  %l0, 3, %o0
a00afbf8:  da 0f 61 5b  ldub  [ %i5 + 0x15b ], %o5
a00afbfc:  ba 03 40 0d  add  %o5, %o5, %i5
a00afc00:  80 a3 60 06  cmp  %o5, 6
a00afc04:  08 80 00 04  bleu  0xa00afc14
a00afc08:  82 07 60 06  add  %i5, 6, %g1
a00afc0c:  98 03 40 0d  add  %o5, %o5, %o4
a00afc10:  82 03 3f f8  add  %o4, -8, %g1
a00afc14:  a0 08 60 ff  and  %g1, 0xff, %l0
a00afc18:  90 10 20 00  clr  %o0
a00afc1c:  92 10 20 28  mov  0x28, %o1
a00afc20:  94 10 00 10  mov  %l0, %o2
a00afc24:  96 10 20 01  mov  1, %o3
a00afc28:  98 10 20 0f  mov  0xf, %o4
a00afc2c:  40 02 5b bd  call  0xa0146b20
a00afc30:  9a 10 20 00  clr  %o5
a00afc34:  92 10 20 29  mov  0x29, %o1
a00afc38:  94 10 00 10  mov  %l0, %o2
a00afc3c:  90 10 20 00  clr  %o0
a00afc40:  96 10 20 01  mov  1, %o3
a00afc44:  98 10 20 10  mov  0x10, %o4
a00afc48:  40 02 5b b6  call  0xa0146b20
a00afc4c:  9a 10 20 00  clr  %o5
a00afc50:  92 16 e2 90  or  %i3, 0x290, %o1
a00afc54:  10 bf fe 3c  b  0xa00af544
a00afc58:  f0 0a 61 5b  ldub  [ %o1 + 0x15b ], %i0
a00afc5c:  7f ff f1 cb  call  0xa00ac388
a00afc60:  90 10 20 01  mov  1, %o0
a00afc64:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00afc68:  f4 08 60 30  ldub  [ %g1 + 0x30 ], %i2	! 0xa802d430
a00afc6c:  b0 06 a0 01  add  %i2, 1, %i0
a00afc70:  10 bf fe 35  b  0xa00af544
a00afc74:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00afc78:  40 00 1f 09  call  0xa00b789c
a00afc7c:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a00afc80:  f8 06 63 38  ld  [ %i1 + 0x338 ], %i4	! 0xa802d338
a00afc84:  9b 37 20 0f  srl  %i4, 0xf, %o5
a00afc88:  10 bf fe 2f  b  0xa00af544
a00afc8c:  b0 0b 60 01  and  %o5, 1, %i0
a00afc90:  90 10 21 11  mov  0x111, %o0
a00afc94:  40 02 5b af  call  0xa0146b50
a00afc98:  92 10 20 00  clr  %o1
a00afc9c:  90 10 20 00  clr  %o0
a00afca0:  92 10 20 00  clr  %o1
a00afca4:  40 02 5b b2  call  0xa0146b6c
a00afca8:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a00afcac:  a0 16 e2 90  or  %i3, 0x290, %l0	! 0xa802d290
a00afcb0:  d4 0c 20 08  ldub  [ %l0 + 8 ], %o2
a00afcb4:  b8 02 a0 91  add  %o2, 0x91, %i4
a00afcb8:  a3 2f 20 10  sll  %i4, 0x10, %l1
a00afcbc:  1b 00 06 3a  sethi  %hi(0x18e800), %o5
a00afcc0:  93 34 60 10  srl  %l1, 0x10, %o1
a00afcc4:  7f ff ce e0  call  0xa00a3844
a00afcc8:  90 13 61 f8  or  %o5, 0x1f8, %o0
a00afccc:  98 10 00 08  mov  %o0, %o4
a00afcd0:  90 10 20 00  clr  %o0
a00afcd4:  92 10 20 2a  mov  0x2a, %o1
a00afcd8:  94 10 20 06  mov  6, %o2
a00afcdc:  96 10 20 01  mov  1, %o3
a00afce0:  7f ff cd 31  call  0xa00a31a4
a00afce4:  9a 10 20 00  clr  %o5
a00afce8:  ba 10 20 01  mov  1, %i5
a00afcec:  a2 10 20 01  mov  1, %l1
a00afcf0:  39 00 06 4c  sethi  %hi(0x193000), %i4
a00afcf4:  93 2c 60 03  sll  %l1, 3, %o1
a00afcf8:  98 22 40 11  sub  %o1, %l1, %o4
a00afcfc:  91 2b 20 02  sll  %o4, 2, %o0
a00afd00:  b4 02 00 11  add  %o0, %l1, %i2
a00afd04:  c2 0c 20 08  ldub  [ %l0 + 8 ], %g1
a00afd08:  b2 06 80 01  add  %i2, %g1, %i1
a00afd0c:  b0 06 7f e3  add  %i1, -29, %i0
a00afd10:  9f 2e 20 10  sll  %i0, 0x10, %o7
a00afd14:  93 33 e0 10  srl  %o7, 0x10, %o1
a00afd18:  7f ff ce cb  call  0xa00a3844
a00afd1c:  90 17 22 48  or  %i4, 0x248, %o0
a00afd20:  96 04 40 11  add  %l1, %l1, %o3
a00afd24:  98 10 00 08  mov  %o0, %o4
a00afd28:  94 02 e0 06  add  %o3, 6, %o2
a00afd2c:  90 10 20 00  clr  %o0
a00afd30:  92 10 20 2a  mov  0x2a, %o1
a00afd34:  96 10 20 01  mov  1, %o3
a00afd38:  9a 10 20 00  clr  %o5
a00afd3c:  7f ff cd 1a  call  0xa00a31a4
a00afd40:  ba 07 60 01  inc  %i5
a00afd44:  a2 0f 60 ff  and  %i5, 0xff, %l1
a00afd48:  80 a4 60 02  cmp  %l1, 2
a00afd4c:  08 bf ff eb  bleu  0xa00afcf8
a00afd50:  93 2c 60 03  sll  %l1, 3, %o1
a00afd54:  f8 04 20 a8  ld  [ %l0 + 0xa8 ], %i4
a00afd58:  a3 37 20 0c  srl  %i4, 0xc, %l1
a00afd5c:  9a 0c 60 01  and  %l1, 1, %o5
a00afd60:  a0 03 60 01  add  %o5, 1, %l0
a00afd64:  82 0c 20 ff  and  %l0, 0xff, %g1
a00afd68:  ba 00 40 01  add  %g1, %g1, %i5
a00afd6c:  80 a0 60 06  cmp  %g1, 6
a00afd70:  08 80 00 04  bleu  0xa00afd80
a00afd74:  9a 07 60 06  add  %i5, 6, %o5
a00afd78:  94 00 40 01  add  %g1, %g1, %o2
a00afd7c:  9a 02 bf f8  add  %o2, -8, %o5
a00afd80:  b2 0b 60 ff  and  %o5, 0xff, %i1
a00afd84:  90 10 20 00  clr  %o0
a00afd88:  92 10 20 28  mov  0x28, %o1
a00afd8c:  94 10 00 19  mov  %i1, %o2
a00afd90:  96 10 20 01  mov  1, %o3
a00afd94:  98 10 20 0f  mov  0xf, %o4
a00afd98:  40 02 5b 62  call  0xa0146b20
a00afd9c:  9a 10 20 00  clr  %o5
a00afda0:  96 10 20 01  mov  1, %o3
a00afda4:  94 10 00 19  mov  %i1, %o2
a00afda8:  90 10 20 00  clr  %o0
a00afdac:  92 10 20 29  mov  0x29, %o1
a00afdb0:  98 10 20 10  mov  0x10, %o4
a00afdb4:  9a 10 20 00  clr  %o5
a00afdb8:  40 02 5b 5a  call  0xa0146b20
a00afdbc:  b0 16 e2 90  or  %i3, 0x290, %i0
a00afdc0:  de 06 20 a8  ld  [ %i0 + 0xa8 ], %o7
a00afdc4:  97 33 e0 0c  srl  %o7, 0xc, %o3
a00afdc8:  b6 0a e0 01  and  %o3, 1, %i3
a00afdcc:  10 bf fd de  b  0xa00af544
a00afdd0:  b0 06 e0 01  add  %i3, 1, %i0
a00afdd4:  90 10 21 11  mov  0x111, %o0
a00afdd8:  40 02 5b 5e  call  0xa0146b50
a00afddc:  92 10 20 00  clr  %o1
a00afde0:  90 10 20 00  clr  %o0
a00afde4:  92 10 20 00  clr  %o1
a00afde8:  40 02 5b 61  call  0xa0146b6c
a00afdec:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a00afdf0:  a2 10 20 00  clr  %l1
a00afdf4:  a0 10 20 00  clr  %l0
a00afdf8:  39 00 06 36  sethi  %hi(0x18d800), %i4
a00afdfc:  ba 16 e2 90  or  %i3, 0x290, %i5
a00afe00:  99 2c 20 03  sll  %l0, 3, %o4
a00afe04:  b4 23 00 10  sub  %o4, %l0, %i2
a00afe08:  9f 2e a0 02  sll  %i2, 2, %o7
a00afe0c:  b0 03 c0 10  add  %o7, %l0, %i0
a00afe10:  f2 0f 60 08  ldub  [ %i5 + 8 ], %i1
a00afe14:  96 06 00 19  add  %i0, %i1, %o3
a00afe18:  95 2a e0 10  sll  %o3, 0x10, %o2
a00afe1c:  93 32 a0 10  srl  %o2, 0x10, %o1
a00afe20:  7f ff ce 89  call  0xa00a3844
a00afe24:  90 17 23 28  or  %i4, 0x328, %o0
a00afe28:  9a 04 00 10  add  %l0, %l0, %o5
a00afe2c:  98 10 00 08  mov  %o0, %o4
a00afe30:  94 03 60 06  add  %o5, 6, %o2
a00afe34:  90 10 20 00  clr  %o0
a00afe38:  92 10 20 2a  mov  0x2a, %o1
a00afe3c:  96 10 20 01  mov  1, %o3
a00afe40:  9a 10 20 00  clr  %o5
a00afe44:  7f ff cc d8  call  0xa00a31a4
a00afe48:  a2 04 60 01  inc  %l1
a00afe4c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00afe50:  80 a4 20 03  cmp  %l0, 3
a00afe54:  08 bf ff ec  bleu  0xa00afe04
a00afe58:  99 2c 20 03  sll  %l0, 3, %o4
a00afe5c:  da 0f 60 11  ldub  [ %i5 + 0x11 ], %o5
a00afe60:  ba 03 40 0d  add  %o5, %o5, %i5
a00afe64:  80 a3 60 06  cmp  %o5, 6
a00afe68:  08 80 00 04  bleu  0xa00afe78
a00afe6c:  82 07 60 06  add  %i5, 6, %g1
a00afe70:  a0 03 40 0d  add  %o5, %o5, %l0
a00afe74:  82 04 3f f8  add  %l0, -8, %g1
a00afe78:  a2 08 60 ff  and  %g1, 0xff, %l1
a00afe7c:  90 10 20 00  clr  %o0
a00afe80:  92 10 20 28  mov  0x28, %o1
a00afe84:  94 10 00 11  mov  %l1, %o2
a00afe88:  96 10 20 01  mov  1, %o3
a00afe8c:  98 10 20 0f  mov  0xf, %o4
a00afe90:  40 02 5b 24  call  0xa0146b20
a00afe94:  9a 10 20 00  clr  %o5
a00afe98:  94 10 00 11  mov  %l1, %o2
a00afe9c:  90 10 20 00  clr  %o0
a00afea0:  92 10 20 29  mov  0x29, %o1
a00afea4:  96 10 20 01  mov  1, %o3
a00afea8:  98 10 20 10  mov  0x10, %o4
a00afeac:  40 02 5b 1d  call  0xa0146b20
a00afeb0:  9a 10 20 00  clr  %o5
a00afeb4:  b8 16 e2 90  or  %i3, 0x290, %i4
a00afeb8:  10 bf fd a3  b  0xa00af544
a00afebc:  f0 0f 20 11  ldub  [ %i4 + 0x11 ], %i0
a00afec0:  90 10 21 11  mov  0x111, %o0
a00afec4:  40 02 5b 23  call  0xa0146b50
a00afec8:  92 10 20 00  clr  %o1
a00afecc:  90 10 20 00  clr  %o0
a00afed0:  40 02 5b 27  call  0xa0146b6c
a00afed4:  92 10 20 00  clr  %o1
a00afed8:  35 2a 00 ac  sethi  %hi(0xa802b000), %i2
a00afedc:  b6 10 20 0e  mov  0xe, %i3
a00afee0:  f2 0e a0 8f  ldub  [ %i2 + 0x8f ], %i1
a00afee4:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00afee8:  f6 2e a0 8f  stb  %i3, [ %i2 + 0x8f ]
a00afeec:  ba 10 20 00  clr  %i5
a00afef0:  a0 10 20 00  clr  %l0
a00afef4:  39 00 06 44  sethi  %hi(0x191000), %i4
a00afef8:  10 80 00 1a  b  0xa00aff60
a00afefc:  b6 16 22 90  or  %i0, 0x290, %i3
a00aff00:  83 2c 20 03  sll  %l0, 3, %g1
a00aff04:  98 20 40 10  sub  %g1, %l0, %o4
a00aff08:  9f 2b 20 02  sll  %o4, 2, %o7
a00aff0c:  94 03 c0 10  add  %o7, %l0, %o2
a00aff10:  d6 0e e0 08  ldub  [ %i3 + 8 ], %o3
a00aff14:  9a 02 80 0b  add  %o2, %o3, %o5
a00aff18:  93 2b 60 10  sll  %o5, 0x10, %o1
a00aff1c:  93 32 60 10  srl  %o1, 0x10, %o1
a00aff20:  7f ff ce 49  call  0xa00a3844
a00aff24:  90 17 20 b0  or  %i4, 0xb0, %o0
a00aff28:  98 10 00 08  mov  %o0, %o4
a00aff2c:  90 04 60 06  add  %l1, 6, %o0
a00aff30:  83 2a 20 10  sll  %o0, 0x10, %g1
a00aff34:  95 30 60 10  srl  %g1, 0x10, %o2
a00aff38:  90 10 20 00  clr  %o0
a00aff3c:  92 10 20 2a  mov  0x2a, %o1
a00aff40:  96 10 20 01  mov  1, %o3
a00aff44:  9a 10 20 00  clr  %o5
a00aff48:  7f ff cc 97  call  0xa00a31a4
a00aff4c:  ba 07 60 01  inc  %i5
a00aff50:  a0 0f 60 ff  and  %i5, 0xff, %l0
a00aff54:  80 a4 20 07  cmp  %l0, 7
a00aff58:  3a 80 00 0f  bcc,a   0xa00aff94
a00aff5c:  da 0e e1 a4  ldub  [ %i3 + 0x1a4 ], %o5
a00aff60:  7f ff eb 74  call  0xa00aad30
a00aff64:  90 10 00 10  mov  %l0, %o0
a00aff68:  80 8a 20 ff  btst  0xff, %o0
a00aff6c:  12 bf ff e5  bne  0xa00aff00
a00aff70:  a2 04 00 10  add  %l0, %l0, %l1
a00aff74:  90 10 20 2a  mov  0x2a, %o0
a00aff78:  92 04 60 06  add  %l1, 6, %o1
a00aff7c:  94 10 20 0a  mov  0xa, %o2
a00aff80:  96 10 22 96  mov  0x296, %o3
a00aff84:  40 02 5a bf  call  0xa0146a80
a00aff88:  98 10 20 00  clr  %o4
a00aff8c:  10 bf ff de  b  0xa00aff04
a00aff90:  83 2c 20 03  sll  %l0, 3, %g1
a00aff94:  ba 03 40 0d  add  %o5, %o5, %i5
a00aff98:  80 a3 60 06  cmp  %o5, 6
a00aff9c:  08 80 00 04  bleu  0xa00affac
a00affa0:  82 07 60 06  add  %i5, 6, %g1
a00affa4:  a0 03 40 0d  add  %o5, %o5, %l0
a00affa8:  82 04 3f f8  add  %l0, -8, %g1
a00affac:  a2 08 60 ff  and  %g1, 0xff, %l1
a00affb0:  90 10 20 00  clr  %o0
a00affb4:  92 10 20 28  mov  0x28, %o1
a00affb8:  94 10 00 11  mov  %l1, %o2
a00affbc:  96 10 20 01  mov  1, %o3
a00affc0:  98 10 20 0f  mov  0xf, %o4
a00affc4:  40 02 5a d7  call  0xa0146b20
a00affc8:  9a 10 20 00  clr  %o5
a00affcc:  94 10 00 11  mov  %l1, %o2
a00affd0:  90 10 20 00  clr  %o0
a00affd4:  92 10 20 29  mov  0x29, %o1
a00affd8:  96 10 20 01  mov  1, %o3
a00affdc:  98 10 20 10  mov  0x10, %o4
a00affe0:  40 02 5a d0  call  0xa0146b20
a00affe4:  9a 10 20 00  clr  %o5
a00affe8:  b8 16 22 90  or  %i0, 0x290, %i4
a00affec:  f2 2e a0 8f  stb  %i1, [ %i2 + 0x8f ]
a00afff0:  10 bf fd 55  b  0xa00af544
a00afff4:  f0 0f 21 a4  ldub  [ %i4 + 0x1a4 ], %i0
a00afff8:  92 10 20 0c  mov  0xc, %o1
a00afffc:  94 10 20 0b  mov  0xb, %o2
a00b0000:  96 10 22 96  mov  0x296, %o3
a00b0004:  40 02 5a 9f  call  0xa0146a80
a00b0008:  98 10 20 00  clr  %o4
a00b000c:  90 10 20 2a  mov  0x2a, %o0
a00b0010:  92 10 20 0e  mov  0xe, %o1
a00b0014:  94 10 20 0b  mov  0xb, %o2
a00b0018:  96 10 22 96  mov  0x296, %o3
a00b001c:  40 02 5a 99  call  0xa0146a80
a00b0020:  98 10 20 00  clr  %o4
a00b0024:  10 bf fe 88  b  0xa00afa44
a00b0028:  a2 10 20 00  clr  %l1
a00b002c:  81 c7 e0 08  ret
a00b0030:  81 e8 00 00  restore
