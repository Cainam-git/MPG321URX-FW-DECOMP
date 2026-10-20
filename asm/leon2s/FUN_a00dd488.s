# leon2s FUN_a00dd488 0xa00dd488-0xa00de8a8 (5152 bytes)
a00dd488:  9d e3 bd 90  save  %sp, -624, %sp
a00dd48c:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00dd490:  82 10 61 38  or  %g1, 0x138, %g1	! 0xa8079538
a00dd494:  d2 08 60 07  ldub  [ %g1 + 7 ], %o1
a00dd498:  e2 08 60 1a  ldub  [ %g1 + 0x1a ], %l1
a00dd49c:  e4 08 60 04  ldub  [ %g1 + 4 ], %l2
a00dd4a0:  ea 10 60 12  lduh  [ %g1 + 0x12 ], %l5
a00dd4a4:  e0 10 60 0a  lduh  [ %g1 + 0xa ], %l0
a00dd4a8:  c2 08 60 19  ldub  [ %g1 + 0x19 ], %g1
a00dd4ac:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00dd4b0:  c2 2f bf b7  stb  %g1, [ %fp + -73 ]
a00dd4b4:  90 12 22 78  or  %o0, 0x278, %o0
a00dd4b8:  40 3a 98 03  call  0xa0f834c4
a00dd4bc:  d2 2f bf b8  stb  %o1, [ %fp + -72 ]
a00dd4c0:  e6 0f bf b8  ldub  [ %fp + -72 ], %l3
a00dd4c4:  80 a0 00 13  cmp  %g0, %l3
a00dd4c8:  9a 60 3f ff  subx  %g0, -1, %o5
a00dd4cc:  82 1c e0 03  xor  %l3, 3, %g1
a00dd4d0:  80 a0 00 01  cmp  %g0, %g1
a00dd4d4:  a8 10 20 00  clr  %l4
a00dd4d8:  82 60 3f ff  subx  %g0, -1, %g1
a00dd4dc:  b4 10 00 14  mov  %l4, %i2
a00dd4e0:  80 93 40 01  orcc  %o5, %g1, %g0
a00dd4e4:  ba 10 20 00  clr  %i5
a00dd4e8:  ac 10 20 00  clr  %l6
a00dd4ec:  b8 10 20 00  clr  %i4
a00dd4f0:  c0 2f bf ba  clrb  [ %fp + -70 ]
a00dd4f4:  c0 2f bf b9  clrb  [ %fp + -71 ]
a00dd4f8:  12 80 00 05  bne  0xa00dd50c
a00dd4fc:  e8 2f bf c3  stb  %l4, [ %fp + -61 ]
a00dd500:  80 a4 e0 04  cmp  %l3, 4
a00dd504:  12 80 00 1b  bne  0xa00dd570
a00dd508:  80 a4 e0 01  cmp  %l3, 1
a00dd50c:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00dd510:  82 10 20 18  mov  0x18, %g1
a00dd514:  95 38 60 1f  sra  %g1, 0x1f, %o2
a00dd518:  81 82 a0 00  mov  %o2, %y
a00dd51c:  01 00 00 00  nop
a00dd520:  01 00 00 00  nop
a00dd524:  01 00 00 00  nop
a00dd528:  ba 78 40 0d  sdiv  %g1, %o5, %i5
a00dd52c:  80 a4 e0 00  cmp  %l3, 0
a00dd530:  a8 10 20 00  clr  %l4
a00dd534:  12 80 00 06  bne  0xa00dd54c
a00dd538:  b8 10 20 00  clr  %i4
a00dd53c:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00dd540:  90 12 21 30  or  %o0, 0x130, %o0	! 0x9f1ced30
a00dd544:  10 80 00 28  b  0xa00dd5e4
a00dd548:  b4 10 20 01  mov  1, %i2
a00dd54c:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00dd550:  80 a4 e0 03  cmp  %l3, 3
a00dd554:  02 80 00 24  be  0xa00dd5e4
a00dd558:  90 12 21 48  or  %o0, 0x148, %o0
a00dd55c:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00dd560:  96 10 20 01  mov  1, %o3
a00dd564:  90 12 21 60  or  %o0, 0x160, %o0
a00dd568:  10 80 00 1f  b  0xa00dd5e4
a00dd56c:  d6 2f bf c3  stb  %o3, [ %fp + -61 ]
a00dd570:  12 80 00 0f  bne  0xa00dd5ac
a00dd574:  80 a4 e0 02  cmp  %l3, 2
a00dd578:  82 0c 60 ff  and  %l1, 0xff, %g1
a00dd57c:  9a 10 20 10  mov  0x10, %o5
a00dd580:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00dd584:  99 3b 60 1f  sra  %o5, 0x1f, %o4
a00dd588:  81 83 20 00  mov  %o4, %y
a00dd58c:  01 00 00 00  nop
a00dd590:  01 00 00 00  nop
a00dd594:  01 00 00 00  nop
a00dd598:  ba 7b 40 01  sdiv  %o5, %g1, %i5
a00dd59c:  90 12 21 80  or  %o0, 0x180, %o0
a00dd5a0:  a8 10 20 00  clr  %l4
a00dd5a4:  10 80 00 10  b  0xa00dd5e4
a00dd5a8:  b8 10 20 01  mov  1, %i4
a00dd5ac:  32 80 00 10  bne,a   0xa00dd5ec
a00dd5b0:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00dd5b4:  82 0c 60 ff  and  %l1, 0xff, %g1
a00dd5b8:  9a 10 20 0c  mov  0xc, %o5
a00dd5bc:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00dd5c0:  a3 3b 60 1f  sra  %o5, 0x1f, %l1
a00dd5c4:  81 84 60 00  mov  %l1, %y
a00dd5c8:  01 00 00 00  nop
a00dd5cc:  01 00 00 00  nop
a00dd5d0:  01 00 00 00  nop
a00dd5d4:  ba 7b 40 01  sdiv  %o5, %g1, %i5
a00dd5d8:  90 12 21 98  or  %o0, 0x198, %o0
a00dd5dc:  a8 10 20 01  mov  1, %l4
a00dd5e0:  b8 10 20 00  clr  %i4
a00dd5e4:  40 3a 96 98  call  0xa0f83044
a00dd5e8:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00dd5ec:  ab 2d 60 10  sll  %l5, 0x10, %l5
a00dd5f0:  e0 27 bf b0  st  %l0, [ %fp + -80 ]
a00dd5f4:  a1 34 20 10  srl  %l0, 0x10, %l0
a00dd5f8:  a3 35 60 10  srl  %l5, 0x10, %l1
a00dd5fc:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00dd600:  ea 27 bf ac  st  %l5, [ %fp + -84 ]
a00dd604:  92 10 00 10  mov  %l0, %o1
a00dd608:  94 10 00 11  mov  %l1, %o2
a00dd60c:  40 3a 96 8e  call  0xa0f83044
a00dd610:  90 12 21 b0  or  %o0, 0x1b0, %o0
a00dd614:  c2 0f bf b7  ldub  [ %fp + -73 ], %g1
a00dd618:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00dd61c:  92 10 00 01  mov  %g1, %o1
a00dd620:  c2 27 bf a8  st  %g1, [ %fp + -88 ]
a00dd624:  40 3a 96 88  call  0xa0f83044
a00dd628:  90 12 21 d8  or  %o0, 0x1d8, %o0
a00dd62c:  91 3c 20 1f  sra  %l0, 0x1f, %o0
a00dd630:  81 82 20 00  mov  %o0, %y
a00dd634:  d0 07 bf a8  ld  [ %fp + -88 ], %o0
a00dd638:  01 00 00 00  nop
a00dd63c:  01 00 00 00  nop
a00dd640:  9a 7c 00 08  sdiv  %l0, %o0, %o5
a00dd644:  d2 07 bf a8  ld  [ %fp + -88 ], %o1
a00dd648:  82 5b 40 09  smul  %o5, %o1, %g1
a00dd64c:  80 a4 00 01  cmp  %l0, %g1
a00dd650:  02 80 00 03  be  0xa00dd65c
a00dd654:  aa 10 00 0d  mov  %o5, %l5
a00dd658:  aa 03 60 01  add  %o5, 1, %l5
a00dd65c:  03 33 33 33  sethi  %hi(0xcccccc00), %g1
a00dd660:  82 10 60 cd  or  %g1, 0xcd, %g1	! 0xcccccccd
a00dd664:  80 54 40 01  umul  %l1, %g1, %g0
a00dd668:  83 40 00 00  rd  %y, %g1
a00dd66c:  9a 15 00 1c  or  %l4, %i4, %o5
a00dd670:  af 30 60 03  srl  %g1, 3, %l7
a00dd674:  a8 0b 60 ff  and  %o5, 0xff, %l4
a00dd678:  83 2f 60 10  sll  %i5, 0x10, %g1
a00dd67c:  9b 30 60 10  srl  %g1, 0x10, %o5
a00dd680:  80 a5 20 00  cmp  %l4, 0
a00dd684:  02 80 00 03  be  0xa00dd690
a00dd688:  b2 10 00 17  mov  %l7, %i1
a00dd68c:  9a 03 40 0d  add  %o5, %o5, %o5
a00dd690:  83 2b 60 10  sll  %o5, 0x10, %g1
a00dd694:  ba 10 00 0d  mov  %o5, %i5
a00dd698:  a1 30 60 10  srl  %g1, 0x10, %l0
a00dd69c:  9b 2b 60 04  sll  %o5, 4, %o5
a00dd6a0:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00dd6a4:  90 12 21 f0  or  %o0, 0x1f0, %o0	! 0x9f1cedf0
a00dd6a8:  da 37 bf f6  sth  %o5, [ %fp + -10 ]
a00dd6ac:  40 3a 96 66  call  0xa0f83044
a00dd6b0:  92 10 00 10  mov  %l0, %o1
a00dd6b4:  ab 2d 60 10  sll  %l5, 0x10, %l5
a00dd6b8:  ea 27 bf a4  st  %l5, [ %fp + -92 ]
a00dd6bc:  80 a5 20 00  cmp  %l4, 0
a00dd6c0:  02 80 00 03  be  0xa00dd6cc
a00dd6c4:  97 35 60 10  srl  %l5, 0x10, %o3
a00dd6c8:  97 3a e0 01  sra  %o3, 1, %o3
a00dd6cc:  98 5c 00 0b  smul  %l0, %o3, %o4
a00dd6d0:  83 3b 20 1f  sra  %o4, 0x1f, %g1
a00dd6d4:  83 30 60 1d  srl  %g1, 0x1d, %g1
a00dd6d8:  82 03 00 01  add  %o4, %g1, %g1
a00dd6dc:  95 38 60 03  sra  %g1, 3, %o2
a00dd6e0:  03 15 55 55  sethi  %hi(0x55555400), %g1
a00dd6e4:  9a 02 e0 02  add  %o3, 2, %o5
a00dd6e8:  82 10 61 56  or  %g1, 0x156, %g1
a00dd6ec:  80 5b 40 01  smul  %o5, %g1, %g0
a00dd6f0:  9b 40 00 00  rd  %y, %o5
a00dd6f4:  da 27 bf bc  st  %o5, [ %fp + -68 ]
a00dd6f8:  80 8b 20 07  btst  7, %o4
a00dd6fc:  d6 37 bf ee  sth  %o3, [ %fp + -18 ]
a00dd700:  02 80 00 03  be  0xa00dd70c
a00dd704:  a8 10 00 0a  mov  %o2, %l4
a00dd708:  a8 02 a0 01  add  %o2, 1, %l4
a00dd70c:  83 2d e0 10  sll  %l7, 0x10, %g1
a00dd710:  83 30 60 10  srl  %g1, 0x10, %g1
a00dd714:  80 a0 60 07  cmp  %g1, 7
a00dd718:  a0 10 20 00  clr  %l0
a00dd71c:  08 80 00 09  bleu  0xa00dd740
a00dd720:  c0 2f bf e7  clrb  [ %fp + -25 ]
a00dd724:  82 1c e0 02  xor  %l3, 2, %g1
a00dd728:  80 a0 00 01  cmp  %g0, %g1
a00dd72c:  82 60 20 00  subx  %g0, 0, %g1
a00dd730:  82 08 7f f4  and  %g1, -12, %g1
a00dd734:  82 00 60 0c  add  %g1, 0xc, %g1
a00dd738:  c2 2f bf e7  stb  %g1, [ %fp + -25 ]
a00dd73c:  a0 10 20 0f  mov  0xf, %l0
a00dd740:  aa 0c a0 ff  and  %l2, 0xff, %l5
a00dd744:  80 a5 60 08  cmp  %l5, 8
a00dd748:  12 80 00 0f  bne  0xa00dd784
a00dd74c:  80 a5 60 0a  cmp  %l5, 0xa
a00dd750:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00dd754:  94 10 20 03  mov  3, %o2
a00dd758:  96 10 20 0c  mov  0xc, %o3
a00dd75c:  98 10 20 02  mov  2, %o4
a00dd760:  90 12 22 08  or  %o0, 0x208, %o0
a00dd764:  d4 2f bf df  stb  %o2, [ %fp + -33 ]
a00dd768:  d6 2f bf d7  stb  %o3, [ %fp + -41 ]
a00dd76c:  d8 37 bf ce  sth  %o4, [ %fp + -50 ]
a00dd770:  a2 10 20 0b  mov  0xb, %l1
a00dd774:  a6 10 20 0b  mov  0xb, %l3
a00dd778:  b6 10 20 30  mov  0x30, %i3
a00dd77c:  10 80 00 21  b  0xa00dd800
a00dd780:  c0 2f bf bb  clrb  [ %fp + -69 ]
a00dd784:  12 80 00 10  bne  0xa00dd7c4
a00dd788:  80 a5 60 0c  cmp  %l5, 0xc
a00dd78c:  a2 10 20 10  mov  0x10, %l1
a00dd790:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00dd794:  9a 10 20 07  mov  7, %o5
a00dd798:  e2 2f bf d7  stb  %l1, [ %fp + -41 ]
a00dd79c:  82 10 20 08  mov  8, %g1
a00dd7a0:  92 10 20 01  mov  1, %o1
a00dd7a4:  90 12 22 20  or  %o0, 0x220, %o0
a00dd7a8:  da 2f bf df  stb  %o5, [ %fp + -33 ]
a00dd7ac:  c2 37 bf ce  sth  %g1, [ %fp + -50 ]
a00dd7b0:  a2 10 20 0f  mov  0xf, %l1
a00dd7b4:  a6 10 20 0f  mov  0xf, %l3
a00dd7b8:  b6 10 20 30  mov  0x30, %i3
a00dd7bc:  10 80 00 11  b  0xa00dd800
a00dd7c0:  d2 2f bf bb  stb  %o1, [ %fp + -69 ]
a00dd7c4:  32 80 00 13  bne,a   0xa00dd810
a00dd7c8:  a2 10 20 03  mov  3, %l1
a00dd7cc:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00dd7d0:  94 10 20 0b  mov  0xb, %o2
a00dd7d4:  96 10 20 14  mov  0x14, %o3
a00dd7d8:  98 10 20 20  mov  0x20, %o4
a00dd7dc:  9a 10 20 02  mov  2, %o5
a00dd7e0:  90 12 22 40  or  %o0, 0x240, %o0
a00dd7e4:  d4 2f bf df  stb  %o2, [ %fp + -33 ]
a00dd7e8:  d6 2f bf d7  stb  %o3, [ %fp + -41 ]
a00dd7ec:  d8 37 bf ce  sth  %o4, [ %fp + -50 ]
a00dd7f0:  a2 10 20 13  mov  0x13, %l1
a00dd7f4:  a6 10 20 13  mov  0x13, %l3
a00dd7f8:  b6 10 20 40  mov  0x40, %i3
a00dd7fc:  da 2f bf bb  stb  %o5, [ %fp + -69 ]
a00dd800:  40 3a 96 11  call  0xa0f83044
a00dd804:  ae 0f 20 ff  and  %i4, 0xff, %l7
a00dd808:  10 80 00 0d  b  0xa00dd83c
a00dd80c:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00dd810:  e2 2f bf df  stb  %l1, [ %fp + -33 ]
a00dd814:  82 10 20 0c  mov  0xc, %g1
a00dd818:  90 10 20 02  mov  2, %o0
a00dd81c:  c2 2f bf d7  stb  %g1, [ %fp + -41 ]
a00dd820:  d0 37 bf ce  sth  %o0, [ %fp + -50 ]
a00dd824:  a2 10 20 0b  mov  0xb, %l1
a00dd828:  a6 10 20 0b  mov  0xb, %l3
a00dd82c:  b6 10 20 30  mov  0x30, %i3
a00dd830:  c0 2f bf bb  clrb  [ %fp + -69 ]
a00dd834:  ae 0f 20 ff  and  %i4, 0xff, %l7
a00dd838:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00dd83c:  80 a5 e0 00  cmp  %l7, 0
a00dd840:  e0 27 bd f8  st  %l0, [ %fp + -520 ]
a00dd844:  02 80 00 13  be  0xa00dd890
a00dd848:  83 2f 60 10  sll  %i5, 0x10, %g1
a00dd84c:  9b 30 60 10  srl  %g1, 0x10, %o5
a00dd850:  80 a3 60 0f  cmp  %o5, 0xf
a00dd854:  38 80 00 25  bgu,a   0xa00dd8e8
a00dd858:  ac 10 28 00  mov  0x800, %l6
a00dd85c:  80 a3 60 0d  cmp  %o5, 0xd
a00dd860:  08 80 00 07  bleu  0xa00dd87c
a00dd864:  80 a3 60 0b  cmp  %o5, 0xb
a00dd868:  83 2b 60 03  sll  %o5, 3, %g1
a00dd86c:  82 23 40 01  sub  %o5, %g1, %g1
a00dd870:  83 28 60 08  sll  %g1, 8, %g1
a00dd874:  10 80 00 13  b  0xa00dd8c0
a00dd878:  1b 00 00 1e  sethi  %hi(0x7800), %o5
a00dd87c:  08 80 00 1c  bleu  0xa00dd8ec
a00dd880:  a1 2f 60 10  sll  %i5, 0x10, %l0
a00dd884:  03 00 00 05  sethi  %hi(0x1400), %g1
a00dd888:  10 80 00 19  b  0xa00dd8ec
a00dd88c:  ac 10 62 00  or  %g1, 0x200, %l6	! 0x1600
a00dd890:  9b 30 60 10  srl  %g1, 0x10, %o5
a00dd894:  80 a3 60 0b  cmp  %o5, 0xb
a00dd898:  08 80 00 04  bleu  0xa00dd8a8
a00dd89c:  80 a3 60 09  cmp  %o5, 9
a00dd8a0:  10 80 00 12  b  0xa00dd8e8
a00dd8a4:  ac 10 28 00  mov  0x800, %l6
a00dd8a8:  08 80 00 08  bleu  0xa00dd8c8
a00dd8ac:  80 a3 60 07  cmp  %o5, 7
a00dd8b0:  83 2b 60 03  sll  %o5, 3, %g1
a00dd8b4:  82 23 40 01  sub  %o5, %g1, %g1
a00dd8b8:  83 28 60 08  sll  %g1, 8, %g1
a00dd8bc:  1b 00 00 17  sethi  %hi(0x5c00), %o5
a00dd8c0:  10 80 00 0a  b  0xa00dd8e8
a00dd8c4:  ac 00 40 0d  add  %g1, %o5, %l6
a00dd8c8:  08 80 00 06  bleu  0xa00dd8e0
a00dd8cc:  80 a3 60 05  cmp  %o5, 5
a00dd8d0:  9b 2b 60 08  sll  %o5, 8, %o5
a00dd8d4:  03 00 00 08  sethi  %hi(0x2000), %g1
a00dd8d8:  10 80 00 04  b  0xa00dd8e8
a00dd8dc:  ac 20 40 0d  sub  %g1, %o5, %l6
a00dd8e0:  38 80 00 02  bgu,a   0xa00dd8e8
a00dd8e4:  2d 00 00 06  sethi  %hi(0x1800), %l6
a00dd8e8:  a1 2f 60 10  sll  %i5, 0x10, %l0
a00dd8ec:  99 34 20 10  srl  %l0, 0x10, %o4
a00dd8f0:  13 00 00 08  sethi  %hi(0x2000), %o1
a00dd8f4:  97 3a 60 1f  sra  %o1, 0x1f, %o3
a00dd8f8:  81 82 e0 00  mov  %o3, %y
a00dd8fc:  01 00 00 00  nop
a00dd900:  01 00 00 00  nop
a00dd904:  01 00 00 00  nop
a00dd908:  94 7a 40 0c  sdiv  %o1, %o4, %o2
a00dd90c:  f8 07 bf bc  ld  [ %fp + -68 ], %i4
a00dd910:  c2 07 bd f8  ld  [ %fp + -520 ], %g1
a00dd914:  94 02 a0 01  inc  %o2
a00dd918:  96 5f 00 01  smul  %i4, %g1, %o3
a00dd91c:  95 32 a0 01  srl  %o2, 1, %o2
a00dd920:  ad 2d a0 10  sll  %l6, 0x10, %l6
a00dd924:  9a 5a 80 0c  smul  %o2, %o4, %o5
a00dd928:  83 35 a0 10  srl  %l6, 0x10, %g1
a00dd92c:  92 22 40 01  sub  %o1, %g1, %o1
a00dd930:  9a 03 40 0b  add  %o5, %o3, %o5
a00dd934:  9a 03 40 09  add  %o5, %o1, %o5
a00dd938:  b3 2e 60 10  sll  %i1, 0x10, %i1
a00dd93c:  91 36 60 10  srl  %i1, 0x10, %o0
a00dd940:  81 80 00 00  mov  %g0, %y
a00dd944:  01 00 00 00  nop
a00dd948:  01 00 00 00  nop
a00dd94c:  01 00 00 00  nop
a00dd950:  96 73 40 0c  udiv  %o5, %o4, %o3
a00dd954:  f8 07 bd f8  ld  [ %fp + -520 ], %i4
a00dd958:  98 5a c0 0c  smul  %o3, %o4, %o4
a00dd95c:  82 02 3f ff  add  %o0, -1, %g1
a00dd960:  bb 2f 20 0b  sll  %i4, 0xb, %i5
a00dd964:  9a 23 40 0c  sub  %o5, %o4, %o5
a00dd968:  81 80 00 00  mov  %g0, %y
a00dd96c:  01 00 00 00  nop
a00dd970:  01 00 00 00  nop
a00dd974:  01 00 00 00  nop
a00dd978:  b8 77 40 01  udiv  %i5, %g1, %i4
a00dd97c:  80 a0 00 0d  cmp  %g0, %o5
a00dd980:  82 5f 00 01  smul  %i4, %g1, %g1
a00dd984:  96 40 00 0b  addx  %g0, %o3, %o3
a00dd988:  82 27 40 01  sub  %i5, %g1, %g1
a00dd98c:  a9 2d 20 10  sll  %l4, 0x10, %l4
a00dd990:  80 a0 00 01  cmp  %g0, %g1
a00dd994:  9b 35 20 10  srl  %l4, 0x10, %o5
a00dd998:  e8 27 bf a0  st  %l4, [ %fp + -96 ]
a00dd99c:  03 00 00 40  sethi  %hi(0x10000), %g1
a00dd9a0:  9a 5b 40 08  smul  %o5, %o0, %o5
a00dd9a4:  99 38 60 1f  sra  %g1, 0x1f, %o4
a00dd9a8:  81 83 20 00  mov  %o4, %y
a00dd9ac:  01 00 00 00  nop
a00dd9b0:  01 00 00 00  nop
a00dd9b4:  01 00 00 00  nop
a00dd9b8:  a8 78 40 09  sdiv  %g1, %o1, %l4
a00dd9bc:  96 22 c0 0a  sub  %o3, %o2, %o3
a00dd9c0:  93 2b 60 03  sll  %o5, 3, %o1
a00dd9c4:  b8 40 00 1c  addx  %g0, %i4, %i4
a00dd9c8:  b0 0e a0 ff  and  %i2, 0xff, %i0
a00dd9cc:  d6 27 bf c4  st  %o3, [ %fp + -60 ]
a00dd9d0:  da 07 bf bc  ld  [ %fp + -68 ], %o5
a00dd9d4:  f2 27 bf 9c  st  %i1, [ %fp + -100 ]
a00dd9d8:  80 a6 20 00  cmp  %i0, 0
a00dd9dc:  02 80 00 09  be  0xa00dda00
a00dd9e0:  96 5b 40 08  smul  %o5, %o0, %o3
a00dd9e4:  83 2d 60 02  sll  %l5, 2, %g1
a00dd9e8:  9a 0e e0 ff  and  %i3, 0xff, %o5
a00dd9ec:  9a 03 40 01  add  %o5, %g1, %o5
a00dd9f0:  82 03 40 0d  add  %o5, %o5, %g1
a00dd9f4:  82 00 40 0d  add  %g1, %o5, %g1
a00dd9f8:  10 80 00 13  b  0xa00dda44
a00dd9fc:  98 00 60 06  add  %g1, 6, %o4
a00dda00:  80 a5 e0 00  cmp  %l7, 0
a00dda04:  12 80 00 0a  bne  0xa00dda2c
a00dda08:  9a 0e e0 ff  and  %i3, 0xff, %o5
a00dda0c:  82 03 40 0d  add  %o5, %o5, %g1
a00dda10:  82 00 40 0d  add  %g1, %o5, %g1
a00dda14:  9b 2d 60 02  sll  %l5, 2, %o5
a00dda18:  9a 03 40 01  add  %o5, %g1, %o5
a00dda1c:  83 2d 60 03  sll  %l5, 3, %g1
a00dda20:  9a 03 40 01  add  %o5, %g1, %o5
a00dda24:  10 80 00 08  b  0xa00dda44
a00dda28:  98 03 60 02  add  %o5, 2, %o4
a00dda2c:  82 05 40 15  add  %l5, %l5, %g1
a00dda30:  9a 05 40 0d  add  %l5, %o5, %o5
a00dda34:  82 00 40 15  add  %g1, %l5, %g1
a00dda38:  82 00 40 0d  add  %g1, %o5, %g1
a00dda3c:  83 28 60 02  sll  %g1, 2, %g1
a00dda40:  98 00 60 02  add  %g1, 2, %o4
a00dda44:  b6 0e e0 ff  and  %i3, 0xff, %i3
a00dda48:  9a 22 40 0c  sub  %o1, %o4, %o5
a00dda4c:  81 80 00 00  mov  %g0, %y
a00dda50:  01 00 00 00  nop
a00dda54:  01 00 00 00  nop
a00dda58:  01 00 00 00  nop
a00dda5c:  82 73 40 1b  udiv  %o5, %i3, %g1
a00dda60:  82 58 40 1b  smul  %g1, %i3, %g1
a00dda64:  9a 23 40 01  sub  %o5, %g1, %o5
a00dda68:  35 00 00 08  sethi  %hi(0x2000), %i2
a00dda6c:  b3 35 a0 10  srl  %l6, 0x10, %i1
a00dda70:  9a 26 c0 0d  sub  %i3, %o5, %o5
a00dda74:  9a 23 00 0d  sub  %o4, %o5, %o5
a00dda78:  82 26 80 19  sub  %i2, %i1, %g1
a00dda7c:  82 00 40 0d  add  %g1, %o5, %g1
a00dda80:  bb 28 60 0b  sll  %g1, 0xb, %i5
a00dda84:  81 80 00 00  mov  %g0, %y
a00dda88:  01 00 00 00  nop
a00dda8c:  01 00 00 00  nop
a00dda90:  01 00 00 00  nop
a00dda94:  aa 77 40 0b  udiv  %i5, %o3, %l5
a00dda98:  f6 27 bf 98  st  %i3, [ %fp + -104 ]
a00dda9c:  98 5d 40 0b  smul  %l5, %o3, %o4
a00ddaa0:  b7 34 20 10  srl  %l0, 0x10, %i3
a00ddaa4:  98 27 40 0c  sub  %i5, %o4, %o4
a00ddaa8:  a1 2a a0 10  sll  %o2, 0x10, %l0
a00ddaac:  a1 34 20 10  srl  %l0, 0x10, %l0
a00ddab0:  bb 2e e0 04  sll  %i3, 4, %i5
a00ddab4:  82 5c 00 1d  smul  %l0, %i5, %g1
a00ddab8:  bb 30 60 04  srl  %g1, 4, %i5
a00ddabc:  96 26 80 1d  sub  %i2, %i5, %o3
a00ddac0:  96 02 c0 0d  add  %o3, %o5, %o3
a00ddac4:  80 a0 00 0c  cmp  %g0, %o4
a00ddac8:  98 26 80 0b  sub  %i2, %o3, %o4
a00ddacc:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00ddad0:  81 80 00 00  mov  %g0, %y
a00ddad4:  01 00 00 00  nop
a00ddad8:  01 00 00 00  nop
a00ddadc:  01 00 00 00  nop
a00ddae0:  9a 73 40 0c  udiv  %o5, %o4, %o5
a00ddae4:  c2 0f bf c3  ldub  [ %fp + -61 ], %g1
a00ddae8:  83 28 60 1b  sll  %g1, 0x1b, %g1
a00ddaec:  99 2e 20 1c  sll  %i0, 0x1c, %o4
a00ddaf0:  aa 40 00 15  addx  %g0, %l5, %l5
a00ddaf4:  98 03 00 01  add  %o4, %g1, %o4
a00ddaf8:  a4 0c a0 ff  and  %l2, 0xff, %l2
a00ddafc:  82 07 00 15  add  %i4, %l5, %g1
a00ddb00:  e4 27 bf 94  st  %l2, [ %fp + -108 ]
a00ddb04:  9a 03 7f f7  add  %o5, -9, %o5
a00ddb08:  ba 5b 40 01  smul  %o5, %g1, %i5
a00ddb0c:  92 0c 60 ff  and  %l1, 0xff, %o1
a00ddb10:  e4 17 bf f6  lduh  [ %fp + -10 ], %l2
a00ddb14:  a3 2c a0 10  sll  %l2, 0x10, %l1
a00ddb18:  03 01 80 00  sethi  %hi(0x6000000), %g1
a00ddb1c:  93 2a 60 10  sll  %o1, 0x10, %o1
a00ddb20:  98 03 00 11  add  %o4, %l1, %o4
a00ddb24:  92 02 40 01  add  %o1, %g1, %o1
a00ddb28:  da 07 bf ac  ld  [ %fp + -84 ], %o5
a00ddb2c:  83 33 60 10  srl  %o5, 0x10, %g1
a00ddb30:  90 0c e0 ff  and  %l3, 0xff, %o0
a00ddb34:  e2 0f bf df  ldub  [ %fp + -33 ], %l1
a00ddb38:  de 0f bf d7  ldub  [ %fp + -41 ], %o7
a00ddb3c:  a7 2c 60 18  sll  %l1, 0x18, %l3
a00ddb40:  9f 2b e0 10  sll  %o7, 0x10, %o7
a00ddb44:  98 03 00 01  add  %o4, %g1, %o4
a00ddb48:  a6 04 c0 0f  add  %l3, %o7, %l3
a00ddb4c:  c2 07 bf a0  ld  [ %fp + -96 ], %g1
a00ddb50:  e4 07 bf 94  ld  [ %fp + -108 ], %l2
a00ddb54:  9f 30 60 10  srl  %g1, 0x10, %o7
a00ddb58:  a8 0d 20 ff  and  %l4, 0xff, %l4
a00ddb5c:  9b 2c a0 04  sll  %l2, 4, %o5
a00ddb60:  03 04 80 00  sethi  %hi(0x12000000), %g1
a00ddb64:  94 05 3f f8  add  %l4, -8, %o2
a00ddb68:  ec 07 bf bc  ld  [ %fp + -68 ], %l6
a00ddb6c:  9a 03 40 12  add  %o5, %l2, %o5
a00ddb70:  82 10 60 01  or  %g1, 1, %g1
a00ddb74:  81 80 00 00  mov  %g0, %y
a00ddb78:  01 00 00 00  nop
a00ddb7c:  01 00 00 00  nop
a00ddb80:  01 00 00 00  nop
a00ddb84:  94 75 80 0a  udiv  %l6, %o2, %o2
a00ddb88:  91 2a 20 08  sll  %o0, 8, %o0
a00ddb8c:  9a 03 40 01  add  %o5, %g1, %o5
a00ddb90:  97 2a e0 10  sll  %o3, 0x10, %o3
a00ddb94:  97 32 e0 10  srl  %o3, 0x10, %o3
a00ddb98:  92 02 40 08  add  %o1, %o0, %o1
a00ddb9c:  ec 07 bf 9c  ld  [ %fp + -100 ], %l6
a00ddba0:  03 08 00 00  sethi  %hi(0x20000000), %g1
a00ddba4:  a3 2a e0 0b  sll  %o3, 0xb, %l1
a00ddba8:  91 35 a0 10  srl  %l6, 0x10, %o0
a00ddbac:  98 03 00 01  add  %o4, %g1, %o4
a00ddbb0:  e4 07 bf b0  ld  [ %fp + -80 ], %l2
a00ddbb4:  81 80 00 00  mov  %g0, %y
a00ddbb8:  01 00 00 00  nop
a00ddbbc:  01 00 00 00  nop
a00ddbc0:  01 00 00 00  nop
a00ddbc4:  a2 74 40 1d  udiv  %l1, %i5, %l1
a00ddbc8:  90 04 80 08  add  %l2, %o0, %o0
a00ddbcc:  ec 07 bf a4  ld  [ %fp + -92 ], %l6
a00ddbd0:  c2 07 bf c4  ld  [ %fp + -60 ], %g1
a00ddbd4:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00ddbd8:  bb 2f 20 10  sll  %i4, 0x10, %i5
a00ddbdc:  9e 05 80 0f  add  %l6, %o7, %o7
a00ddbe0:  a0 04 00 01  add  %l0, %g1, %l0
a00ddbe4:  25 2a 01 e5  sethi  %hi(0xa8079400), %l2
a00ddbe8:  ac 14 a1 5c  or  %l2, 0x15c, %l6	! 0xa807955c
a00ddbec:  82 07 40 15  add  %i5, %l5, %g1
a00ddbf0:  c2 25 a0 1c  st  %g1, [ %l6 + 0x1c ]
a00ddbf4:  03 03 87 0a  sethi  %hi(0xe1c2800), %g1
a00ddbf8:  82 10 62 38  or  %g1, 0x238, %g1	! 0xe1c2a38
a00ddbfc:  c2 25 a0 2c  st  %g1, [ %l6 + 0x2c ]
a00ddc00:  03 11 95 18  sethi  %hi(0x46546000), %g1
a00ddc04:  82 10 62 69  or  %g1, 0x269, %g1	! 0x46546269
a00ddc08:  a9 2d 20 10  sll  %l4, 0x10, %l4
a00ddc0c:  b9 2e 60 10  sll  %i1, 0x10, %i4
a00ddc10:  a8 05 00 11  add  %l4, %l1, %l4
a00ddc14:  c2 25 a0 30  st  %g1, [ %l6 + 0x30 ]
a00ddc18:  aa 07 00 0b  add  %i4, %o3, %l5
a00ddc1c:  95 2a a0 10  sll  %o2, 0x10, %o2
a00ddc20:  e2 07 bd f8  ld  [ %fp + -520 ], %l1
a00ddc24:  03 1c 1d de  sethi  %hi(0x70777800), %g1
a00ddc28:  94 02 80 11  add  %o2, %l1, %o2
a00ddc2c:  a6 04 c0 1a  add  %l3, %i2, %l3
a00ddc30:  92 02 60 33  add  %o1, 0x33, %o1
a00ddc34:  d6 0f bf b8  ldub  [ %fp + -72 ], %o3
a00ddc38:  82 10 61 7b  or  %g1, 0x17b, %g1
a00ddc3c:  39 1f 5f 80  sethi  %hi(0x7d7e0000), %i4
a00ddc40:  da 24 a1 5c  st  %o5, [ %l2 + 0x15c ]
a00ddc44:  d8 25 a0 04  st  %o4, [ %l6 + 4 ]
a00ddc48:  d0 25 a0 08  st  %o0, [ %l6 + 8 ]
a00ddc4c:  de 25 a0 0c  st  %o7, [ %l6 + 0xc ]
a00ddc50:  e0 25 a0 10  st  %l0, [ %l6 + 0x10 ]
a00ddc54:  e8 25 a0 14  st  %l4, [ %l6 + 0x14 ]
a00ddc58:  d4 25 a0 18  st  %o2, [ %l6 + 0x18 ]
a00ddc5c:  ea 25 a0 20  st  %l5, [ %l6 + 0x20 ]
a00ddc60:  e6 25 a0 24  st  %l3, [ %l6 + 0x24 ]
a00ddc64:  d2 25 a0 28  st  %o1, [ %l6 + 0x28 ]
a00ddc68:  c2 25 a0 34  st  %g1, [ %l6 + 0x34 ]
a00ddc6c:  80 a2 e0 02  cmp  %o3, 2
a00ddc70:  12 80 00 ae  bne  0xa00ddf28
a00ddc74:  f8 25 a0 38  st  %i4, [ %l6 + 0x38 ]
a00ddc78:  c2 0f bf bb  ldub  [ %fp + -69 ], %g1
a00ddc7c:  99 28 60 04  sll  %g1, 4, %o4
a00ddc80:  98 23 00 01  sub  %o4, %g1, %o4
a00ddc84:  1b 27 c7 3b  sethi  %hi(0x9f1cec00), %o5
a00ddc88:  03 27 c7 3a  sethi  %hi(0x9f1ce800), %g1
a00ddc8c:  9a 13 60 08  or  %o5, 8, %o5
a00ddc90:  82 10 63 45  or  %g1, 0x345, %g1
a00ddc94:  96 03 00 0d  add  %o4, %o5, %o3
a00ddc98:  94 03 00 01  add  %o4, %g1, %o2
a00ddc9c:  da 0b 40 0c  ldub  [ %o5 + %o4 ], %o5
a00ddca0:  c2 08 40 0c  ldub  [ %g1 + %o4 ], %g1
a00ddca4:  d8 0a a0 06  ldub  [ %o2 + 6 ], %o4
a00ddca8:  e4 0a a0 07  ldub  [ %o2 + 7 ], %l2
a00ddcac:  ec 0a e0 08  ldub  [ %o3 + 8 ], %l6
a00ddcb0:  d8 27 bf 60  st  %o4, [ %fp + -160 ]
a00ddcb4:  d0 0a a0 05  ldub  [ %o2 + 5 ], %o0
a00ddcb8:  d2 0a e0 06  ldub  [ %o3 + 6 ], %o1
a00ddcbc:  f8 0a a0 08  ldub  [ %o2 + 8 ], %i4
a00ddcc0:  d8 0a e0 0a  ldub  [ %o3 + 0xa ], %o4
a00ddcc4:  e4 27 bf 54  st  %l2, [ %fp + -172 ]
a00ddcc8:  ec 27 bf 4c  st  %l6, [ %fp + -180 ]
a00ddccc:  e4 0a a0 0b  ldub  [ %o2 + 0xb ], %l2
a00ddcd0:  ec 0a e0 0e  ldub  [ %o3 + 0xe ], %l6
a00ddcd4:  d0 27 bf 70  st  %o0, [ %fp + -144 ]
a00ddcd8:  d2 27 bf 68  st  %o1, [ %fp + -152 ]
a00ddcdc:  f8 27 bf 44  st  %i4, [ %fp + -188 ]
a00ddce0:  d8 27 bf 38  st  %o4, [ %fp + -200 ]
a00ddce4:  e6 0a e0 03  ldub  [ %o3 + 3 ], %l3
a00ddce8:  de 0a a0 03  ldub  [ %o2 + 3 ], %o7
a00ddcec:  e2 0a e0 04  ldub  [ %o3 + 4 ], %l1
a00ddcf0:  e8 0a a0 04  ldub  [ %o2 + 4 ], %l4
a00ddcf4:  e0 0a e0 05  ldub  [ %o3 + 5 ], %l0
a00ddcf8:  d0 0a e0 07  ldub  [ %o3 + 7 ], %o0
a00ddcfc:  d2 0a e0 09  ldub  [ %o3 + 9 ], %o1
a00ddd00:  f0 0a a0 09  ldub  [ %o2 + 9 ], %i0
a00ddd04:  f4 0a a0 0a  ldub  [ %o2 + 0xa ], %i2
a00ddd08:  d8 0a e0 0b  ldub  [ %o3 + 0xb ], %o4
a00ddd0c:  ea 0a e0 0c  ldub  [ %o3 + 0xc ], %l5
a00ddd10:  fa 0a a0 0c  ldub  [ %o2 + 0xc ], %i5
a00ddd14:  f8 0a a0 0e  ldub  [ %o2 + 0xe ], %i4
a00ddd18:  e4 27 bf 30  st  %l2, [ %fp + -208 ]
a00ddd1c:  ec 27 bf 28  st  %l6, [ %fp + -216 ]
a00ddd20:  f8 27 bf 20  st  %i4, [ %fp + -224 ]
a00ddd24:  9b 2b 60 0b  sll  %o5, 0xb, %o5
a00ddd28:  83 28 60 06  sll  %g1, 6, %g1
a00ddd2c:  da 27 bf 90  st  %o5, [ %fp + -112 ]
a00ddd30:  c2 27 bf 8c  st  %g1, [ %fp + -116 ]
a00ddd34:  c2 07 bf 70  ld  [ %fp + -144 ], %g1
a00ddd38:  da 07 bf 68  ld  [ %fp + -152 ], %o5
a00ddd3c:  83 28 60 06  sll  %g1, 6, %g1
a00ddd40:  9b 2b 60 0b  sll  %o5, 0xb, %o5
a00ddd44:  a3 2c 60 0b  sll  %l1, 0xb, %l1
a00ddd48:  c2 27 bf 6c  st  %g1, [ %fp + -148 ]
a00ddd4c:  da 27 bf 64  st  %o5, [ %fp + -156 ]
a00ddd50:  e4 07 bf 54  ld  [ %fp + -172 ], %l2
a00ddd54:  ec 07 bf 4c  ld  [ %fp + -180 ], %l6
a00ddd58:  e2 27 bf 7c  st  %l1, [ %fp + -132 ]
a00ddd5c:  a5 2c a0 06  sll  %l2, 6, %l2
a00ddd60:  ad 2d a0 0b  sll  %l6, 0xb, %l6
a00ddd64:  c2 07 bf 38  ld  [ %fp + -200 ], %g1
a00ddd68:  da 07 bf 30  ld  [ %fp + -208 ], %o5
a00ddd6c:  9f 2b e0 06  sll  %o7, 6, %o7
a00ddd70:  e2 07 bf 60  ld  [ %fp + -160 ], %l1
a00ddd74:  e4 27 bf 50  st  %l2, [ %fp + -176 ]
a00ddd78:  ec 27 bf 48  st  %l6, [ %fp + -184 ]
a00ddd7c:  83 28 60 0b  sll  %g1, 0xb, %g1
a00ddd80:  9b 2b 60 06  sll  %o5, 6, %o5
a00ddd84:  de 27 bf 80  st  %o7, [ %fp + -128 ]
a00ddd88:  ec 07 bf 8c  ld  [ %fp + -116 ], %l6
a00ddd8c:  a9 2d 20 06  sll  %l4, 6, %l4
a00ddd90:  a3 2c 60 06  sll  %l1, 6, %l1
a00ddd94:  c2 27 bf 34  st  %g1, [ %fp + -204 ]
a00ddd98:  da 27 bf 2c  st  %o5, [ %fp + -212 ]
a00ddd9c:  e4 07 bf 90  ld  [ %fp + -112 ], %l2
a00ddda0:  e8 27 bf 78  st  %l4, [ %fp + -136 ]
a00ddda4:  da 0a e0 01  ldub  [ %o3 + 1 ], %o5
a00ddda8:  de 0a e0 02  ldub  [ %o3 + 2 ], %o7
a00dddac:  c2 0a e0 0d  ldub  [ %o3 + 0xd ], %g1
a00dddb0:  a4 04 80 16  add  %l2, %l6, %l2
a00dddb4:  e2 27 bf 5c  st  %l1, [ %fp + -164 ]
a00dddb8:  f8 07 bf 44  ld  [ %fp + -188 ], %i4
a00dddbc:  e8 0a a0 01  ldub  [ %o2 + 1 ], %l4
a00dddc0:  e2 0a a0 02  ldub  [ %o2 + 2 ], %l1
a00dddc4:  d6 0a a0 0d  ldub  [ %o2 + 0xd ], %o3
a00dddc8:  b9 2f 20 06  sll  %i4, 6, %i4
a00dddcc:  e4 27 bf 88  st  %l2, [ %fp + -120 ]
a00dddd0:  e4 07 bf 78  ld  [ %fp + -136 ], %l2
a00dddd4:  f8 27 bf 40  st  %i4, [ %fp + -192 ]
a00dddd8:  d4 07 bf 7c  ld  [ %fp + -132 ], %o2
a00ddddc:  f8 07 bf 80  ld  [ %fp + -128 ], %i4
a00ddde0:  94 02 80 12  add  %o2, %l2, %o2
a00ddde4:  a7 2c e0 0b  sll  %l3, 0xb, %l3
a00ddde8:  d4 27 bf 74  st  %o2, [ %fp + -140 ]
a00dddec:  a6 04 c0 1c  add  %l3, %i4, %l3
a00dddf0:  d4 07 bf 5c  ld  [ %fp + -164 ], %o2
a00dddf4:  f8 07 bf 64  ld  [ %fp + -156 ], %i4
a00dddf8:  b8 07 00 0a  add  %i4, %o2, %i4
a00dddfc:  ec 07 bf 6c  ld  [ %fp + -148 ], %l6
a00dde00:  a1 2c 20 0b  sll  %l0, 0xb, %l0
a00dde04:  a0 04 00 16  add  %l0, %l6, %l0
a00dde08:  f8 27 bf 58  st  %i4, [ %fp + -168 ]
a00dde0c:  f8 07 bf 40  ld  [ %fp + -192 ], %i4
a00dde10:  ec 07 bf 48  ld  [ %fp + -184 ], %l6
a00dde14:  ac 05 80 1c  add  %l6, %i4, %l6
a00dde18:  ec 27 bf 3c  st  %l6, [ %fp + -196 ]
a00dde1c:  d4 07 bf 34  ld  [ %fp + -204 ], %o2
a00dde20:  b5 2e a0 06  sll  %i2, 6, %i2
a00dde24:  ec 07 bf 28  ld  [ %fp + -216 ], %l6
a00dde28:  e4 07 bf 50  ld  [ %fp + -176 ], %l2
a00dde2c:  b4 02 80 1a  add  %o2, %i2, %i2
a00dde30:  ad 2d a0 0b  sll  %l6, 0xb, %l6
a00dde34:  f8 07 bf 20  ld  [ %fp + -224 ], %i4
a00dde38:  91 2a 20 0b  sll  %o0, 0xb, %o0
a00dde3c:  90 02 00 12  add  %o0, %l2, %o0
a00dde40:  a3 2c 60 06  sll  %l1, 6, %l1
a00dde44:  ec 27 bf 24  st  %l6, [ %fp + -220 ]
a00dde48:  95 2f 20 06  sll  %i4, 6, %o2
a00dde4c:  9f 2b e0 0b  sll  %o7, 0xb, %o7
a00dde50:  e4 07 bf 2c  ld  [ %fp + -212 ], %l2
a00dde54:  9e 03 c0 11  add  %o7, %l1, %o7
a00dde58:  99 2b 20 0b  sll  %o4, 0xb, %o4
a00dde5c:  f8 07 bf 24  ld  [ %fp + -220 ], %i4
a00dde60:  98 03 00 12  add  %o4, %l2, %o4
a00dde64:  e2 07 bf 74  ld  [ %fp + -140 ], %l1
a00dde68:  94 07 00 0a  add  %i4, %o2, %o2
a00dde6c:  97 2a e0 06  sll  %o3, 6, %o3
a00dde70:  a6 04 c0 11  add  %l3, %l1, %l3
a00dde74:  e4 07 bf 58  ld  [ %fp + -168 ], %l2
a00dde78:  d4 27 bf 1c  st  %o2, [ %fp + -228 ]
a00dde7c:  93 2a 60 0b  sll  %o1, 0xb, %o1
a00dde80:  b1 2e 20 06  sll  %i0, 6, %i0
a00dde84:  ab 2d 60 0b  sll  %l5, 0xb, %l5
a00dde88:  bb 2f 60 06  sll  %i5, 6, %i5
a00dde8c:  83 28 60 0b  sll  %g1, 0xb, %g1
a00dde90:  a9 2d 20 06  sll  %l4, 6, %l4
a00dde94:  a0 04 00 12  add  %l0, %l2, %l0
a00dde98:  82 00 40 0b  add  %g1, %o3, %g1
a00dde9c:  92 02 40 18  add  %o1, %i0, %o1
a00ddea0:  aa 05 40 1d  add  %l5, %i5, %l5
a00ddea4:  9b 2b 60 0b  sll  %o5, 0xb, %o5
a00ddea8:  ec 07 bf 3c  ld  [ %fp + -196 ], %l6
a00ddeac:  d4 07 bf 88  ld  [ %fp + -120 ], %o2
a00ddeb0:  e2 07 bf 1c  ld  [ %fp + -228 ], %l1
a00ddeb4:  9a 03 40 14  add  %o5, %l4, %o5
a00ddeb8:  94 02 a0 02  add  %o2, 2, %o2
a00ddebc:  90 02 00 16  add  %o0, %l6, %o0
a00ddec0:  92 02 40 1a  add  %o1, %i2, %o1
a00ddec4:  98 03 00 15  add  %o4, %l5, %o4
a00ddec8:  17 1f 5f 80  sethi  %hi(0x7d7e0000), %o3
a00ddecc:  82 00 40 11  add  %g1, %l1, %g1
a00dded0:  25 2a 01 e5  sethi  %hi(0xa8079400), %l2
a00dded4:  a4 14 a1 5c  or  %l2, 0x15c, %l2	! 0xa807955c
a00dded8:  96 02 80 0b  add  %o2, %o3, %o3
a00ddedc:  9a 03 40 0f  add  %o5, %o7, %o5
a00ddee0:  a6 04 e0 7a  add  %l3, 0x7a, %l3
a00ddee4:  a0 04 20 72  add  %l0, 0x72, %l0
a00ddee8:  90 02 20 70  add  %o0, 0x70, %o0
a00ddeec:  92 02 60 6c  add  %o1, 0x6c, %o1
a00ddef0:  98 03 20 6a  add  %o4, 0x6a, %o4
a00ddef4:  82 00 60 68  add  %g1, 0x68, %g1
a00ddef8:  d4 27 bf 84  st  %o2, [ %fp + -124 ]
a00ddefc:  d6 27 bd f4  st  %o3, [ %fp + -524 ]
a00ddf00:  d6 24 a0 38  st  %o3, [ %l2 + 0x38 ]
a00ddf04:  da 24 a0 3c  st  %o5, [ %l2 + 0x3c ]
a00ddf08:  e6 24 a0 40  st  %l3, [ %l2 + 0x40 ]
a00ddf0c:  e0 24 a0 44  st  %l0, [ %l2 + 0x44 ]
a00ddf10:  d0 24 a0 48  st  %o0, [ %l2 + 0x48 ]
a00ddf14:  d2 24 a0 4c  st  %o1, [ %l2 + 0x4c ]
a00ddf18:  d8 24 a0 50  st  %o4, [ %l2 + 0x50 ]
a00ddf1c:  c2 24 a0 54  st  %g1, [ %l2 + 0x54 ]
a00ddf20:  10 80 01 d1  b  0xa00de664
a00ddf24:  a8 10 20 01  mov  1, %l4
a00ddf28:  80 a2 e0 01  cmp  %o3, 1
a00ddf2c:  12 80 01 1a  bne  0xa00de394
a00ddf30:  c2 0f bf bb  ldub  [ %fp + -69 ], %g1
a00ddf34:  80 a0 60 00  cmp  %g1, 0
a00ddf38:  12 80 00 0f  bne  0xa00ddf74
a00ddf3c:  80 a0 60 01  cmp  %g1, 1
a00ddf40:  80 a6 e0 08  cmp  %i3, 8
a00ddf44:  c0 2f bf b9  clrb  [ %fp + -71 ]
a00ddf48:  02 80 00 22  be  0xa00ddfd0
a00ddf4c:  c0 2f bf ba  clrb  [ %fp + -70 ]
a00ddf50:  ac 10 20 01  mov  1, %l6
a00ddf54:  80 a6 e0 09  cmp  %i3, 9
a00ddf58:  ec 2f bf b9  stb  %l6, [ %fp + -71 ]
a00ddf5c:  02 80 00 1d  be  0xa00ddfd0
a00ddf60:  ec 2f bf ba  stb  %l6, [ %fp + -70 ]
a00ddf64:  b8 10 20 02  mov  2, %i4
a00ddf68:  f8 2f bf b9  stb  %i4, [ %fp + -71 ]
a00ddf6c:  10 80 00 19  b  0xa00ddfd0
a00ddf70:  f8 2f bf ba  stb  %i4, [ %fp + -70 ]
a00ddf74:  12 80 00 12  bne  0xa00ddfbc
a00ddf78:  80 a0 60 02  cmp  %g1, 2
a00ddf7c:  82 10 20 03  mov  3, %g1
a00ddf80:  80 a6 e0 08  cmp  %i3, 8
a00ddf84:  c2 2f bf b9  stb  %g1, [ %fp + -71 ]
a00ddf88:  02 80 00 12  be  0xa00ddfd0
a00ddf8c:  c0 2f bf ba  clrb  [ %fp + -70 ]
a00ddf90:  90 10 20 04  mov  4, %o0
a00ddf94:  92 10 20 01  mov  1, %o1
a00ddf98:  80 a6 e0 09  cmp  %i3, 9
a00ddf9c:  d0 2f bf b9  stb  %o0, [ %fp + -71 ]
a00ddfa0:  02 80 00 0c  be  0xa00ddfd0
a00ddfa4:  d2 2f bf ba  stb  %o1, [ %fp + -70 ]
a00ddfa8:  94 10 20 05  mov  5, %o2
a00ddfac:  96 10 20 02  mov  2, %o3
a00ddfb0:  d4 2f bf b9  stb  %o2, [ %fp + -71 ]
a00ddfb4:  10 80 00 07  b  0xa00ddfd0
a00ddfb8:  d6 2f bf ba  stb  %o3, [ %fp + -70 ]
a00ddfbc:  32 80 00 06  bne,a   0xa00ddfd4
a00ddfc0:  e0 0f bf b9  ldub  [ %fp + -71 ], %l0
a00ddfc4:  98 10 20 06  mov  6, %o4
a00ddfc8:  d8 2f bf b9  stb  %o4, [ %fp + -71 ]
a00ddfcc:  c0 2f bf ba  clrb  [ %fp + -70 ]
a00ddfd0:  e0 0f bf b9  ldub  [ %fp + -71 ], %l0
a00ddfd4:  e2 0f bf ba  ldub  [ %fp + -70 ], %l1
a00ddfd8:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00ddfdc:  92 10 00 10  mov  %l0, %o1
a00ddfe0:  94 10 00 11  mov  %l1, %o2
a00ddfe4:  40 3a 94 18  call  0xa0f83044
a00ddfe8:  90 12 22 60  or  %o0, 0x260, %o0
a00ddfec:  9b 2c 60 04  sll  %l1, 4, %o5
a00ddff0:  a2 23 40 11  sub  %o5, %l1, %l1
a00ddff4:  15 27 c7 3a  sethi  %hi(0x9f1ce800), %o2
a00ddff8:  94 12 a2 6f  or  %o2, 0x26f, %o2	! 0x9f1cea6f
a00ddffc:  99 2c 20 04  sll  %l0, 4, %o4
a00de000:  1b 27 c7 3a  sethi  %hi(0x9f1ce800), %o5
a00de004:  03 27 c7 3a  sethi  %hi(0x9f1ce800), %g1
a00de008:  a8 04 40 0a  add  %l1, %o2, %l4
a00de00c:  98 23 00 10  sub  %o4, %l0, %o4
a00de010:  9a 13 63 9f  or  %o5, 0x39f, %o5
a00de014:  e2 27 bf 10  st  %l1, [ %fp + -240 ]
a00de018:  82 10 62 dc  or  %g1, 0x2dc, %g1
a00de01c:  92 03 00 01  add  %o4, %g1, %o1
a00de020:  96 03 00 0d  add  %o4, %o5, %o3
a00de024:  e2 0d 20 03  ldub  [ %l4 + 3 ], %l1
a00de028:  fa 0b 40 0c  ldub  [ %o5 + %o4 ], %i5
a00de02c:  e4 0a e0 04  ldub  [ %o3 + 4 ], %l2
a00de030:  ec 0a 60 04  ldub  [ %o1 + 4 ], %l6
a00de034:  e2 27 be e4  st  %l1, [ %fp + -284 ]
a00de038:  d0 0d 20 05  ldub  [ %l4 + 5 ], %o0
a00de03c:  e2 0a 60 06  ldub  [ %o1 + 6 ], %l1
a00de040:  c2 08 40 0c  ldub  [ %g1 + %o4 ], %g1
a00de044:  da 0a e0 01  ldub  [ %o3 + 1 ], %o5
a00de048:  e4 27 be dc  st  %l2, [ %fp + -292 ]
a00de04c:  ec 27 be d4  st  %l6, [ %fp + -300 ]
a00de050:  f8 0a 60 05  ldub  [ %o1 + 5 ], %i4
a00de054:  e4 0a 60 07  ldub  [ %o1 + 7 ], %l2
a00de058:  ec 0d 20 07  ldub  [ %l4 + 7 ], %l6
a00de05c:  d8 0a 60 01  ldub  [ %o1 + 1 ], %o4
a00de060:  d0 27 be b8  st  %o0, [ %fp + -328 ]
a00de064:  e2 27 be b0  st  %l1, [ %fp + -336 ]
a00de068:  83 28 60 06  sll  %g1, 6, %g1
a00de06c:  9b 2b 60 1b  sll  %o5, 0x1b, %o5
a00de070:  f6 0d 20 01  ldub  [ %l4 + 1 ], %i3
a00de074:  f4 0a e0 02  ldub  [ %o3 + 2 ], %i2
a00de078:  f2 0a 60 02  ldub  [ %o1 + 2 ], %i1
a00de07c:  e0 0a e0 03  ldub  [ %o3 + 3 ], %l0
a00de080:  f0 0a 60 03  ldub  [ %o1 + 3 ], %i0
a00de084:  de 0a e0 05  ldub  [ %o3 + 5 ], %o7
a00de088:  ea 0a e0 06  ldub  [ %o3 + 6 ], %l5
a00de08c:  d0 0a e0 07  ldub  [ %o3 + 7 ], %o0
a00de090:  e2 0a e0 08  ldub  [ %o3 + 8 ], %l1
a00de094:  e6 0a 60 08  ldub  [ %o1 + 8 ], %l3
a00de098:  f8 27 be c0  st  %i4, [ %fp + -320 ]
a00de09c:  e4 27 be a8  st  %l2, [ %fp + -344 ]
a00de0a0:  ec 27 be a0  st  %l6, [ %fp + -352 ]
a00de0a4:  c2 27 bf 18  st  %g1, [ %fp + -232 ]
a00de0a8:  da 27 bf 0c  st  %o5, [ %fp + -244 ]
a00de0ac:  99 2b 20 16  sll  %o4, 0x16, %o4
a00de0b0:  d8 27 bf 08  st  %o4, [ %fp + -248 ]
a00de0b4:  f8 07 be e4  ld  [ %fp + -284 ], %i4
a00de0b8:  b8 0f 20 3f  and  %i4, 0x3f, %i4
a00de0bc:  f8 27 be e0  st  %i4, [ %fp + -288 ]
a00de0c0:  c2 07 be dc  ld  [ %fp + -292 ], %g1
a00de0c4:  83 28 60 0b  sll  %g1, 0xb, %g1
a00de0c8:  ec 07 be b0  ld  [ %fp + -336 ], %l6
a00de0cc:  f8 07 be a8  ld  [ %fp + -344 ], %i4
a00de0d0:  c2 27 be d8  st  %g1, [ %fp + -296 ]
a00de0d4:  d8 07 be d4  ld  [ %fp + -300 ], %o4
a00de0d8:  da 07 be c0  ld  [ %fp + -320 ], %o5
a00de0dc:  e4 07 be b8  ld  [ %fp + -328 ], %l2
a00de0e0:  ad 2d a0 06  sll  %l6, 6, %l6
a00de0e4:  b9 2f 20 16  sll  %i4, 0x16, %i4
a00de0e8:  99 2b 20 06  sll  %o4, 6, %o4
a00de0ec:  9b 2b 60 16  sll  %o5, 0x16, %o5
a00de0f0:  a4 0c a0 3f  and  %l2, 0x3f, %l2
a00de0f4:  ec 27 be ac  st  %l6, [ %fp + -340 ]
a00de0f8:  f8 27 be a4  st  %i4, [ %fp + -348 ]
a00de0fc:  c2 07 be a0  ld  [ %fp + -352 ], %g1
a00de100:  ec 0a 60 09  ldub  [ %o1 + 9 ], %l6
a00de104:  f8 0d 20 09  ldub  [ %l4 + 9 ], %i4
a00de108:  d8 27 be d0  st  %o4, [ %fp + -304 ]
a00de10c:  da 27 be bc  st  %o5, [ %fp + -324 ]
a00de110:  e4 27 be b4  st  %l2, [ %fp + -332 ]
a00de114:  82 08 60 3f  and  %g1, 0x3f, %g1
a00de118:  da 0d 20 04  ldub  [ %l4 + 4 ], %o5
a00de11c:  e4 0d 20 08  ldub  [ %l4 + 8 ], %l2
a00de120:  d8 07 bf 10  ld  [ %fp + -240 ], %o4
a00de124:  b5 2e a0 0b  sll  %i2, 0xb, %i2
a00de128:  b1 2e 20 16  sll  %i0, 0x16, %i0
a00de12c:  c2 27 be 9c  st  %g1, [ %fp + -356 ]
a00de130:  ec 27 be 8c  st  %l6, [ %fp + -372 ]
a00de134:  f8 27 be 88  st  %i4, [ %fp + -376 ]
a00de138:  c2 0a 80 0c  ldub  [ %o2 + %o4 ], %g1
a00de13c:  b3 2e 60 06  sll  %i1, 6, %i1
a00de140:  f8 07 bf 08  ld  [ %fp + -248 ], %i4
a00de144:  b6 0e e0 3f  and  %i3, 0x3f, %i3
a00de148:  f4 27 be f8  st  %i2, [ %fp + -264 ]
a00de14c:  f0 27 be e8  st  %i0, [ %fp + -280 ]
a00de150:  da 27 be c8  st  %o5, [ %fp + -312 ]
a00de154:  e4 27 be 94  st  %l2, [ %fp + -364 ]
a00de158:  ec 07 bf 0c  ld  [ %fp + -244 ], %l6
a00de15c:  d4 0d 20 02  ldub  [ %l4 + 2 ], %o2
a00de160:  f0 0d 20 06  ldub  [ %l4 + 6 ], %i0
a00de164:  da 0a e0 09  ldub  [ %o3 + 9 ], %o5
a00de168:  d8 0a e0 0a  ldub  [ %o3 + 0xa ], %o4
a00de16c:  f4 0a 60 0a  ldub  [ %o1 + 0xa ], %i2
a00de170:  e4 07 bf 18  ld  [ %fp + -232 ], %l2
a00de174:  ac 05 80 1c  add  %l6, %i4, %l6
a00de178:  f6 27 bf 00  st  %i3, [ %fp + -256 ]
a00de17c:  f2 27 be f4  st  %i1, [ %fp + -268 ]
a00de180:  bb 2f 60 0b  sll  %i5, 0xb, %i5
a00de184:  ec 27 bf 04  st  %l6, [ %fp + -252 ]
a00de188:  ba 07 40 12  add  %i5, %l2, %i5
a00de18c:  e4 07 be f8  ld  [ %fp + -264 ], %l2
a00de190:  a4 04 80 19  add  %l2, %i1, %l2
a00de194:  e4 27 be f0  st  %l2, [ %fp + -272 ]
a00de198:  e4 07 be d0  ld  [ %fp + -304 ], %l2
a00de19c:  f8 07 be d8  ld  [ %fp + -296 ], %i4
a00de1a0:  b8 07 00 12  add  %i4, %l2, %i4
a00de1a4:  ec 07 be e8  ld  [ %fp + -280 ], %l6
a00de1a8:  f8 27 be cc  st  %i4, [ %fp + -308 ]
a00de1ac:  a1 2c 20 1b  sll  %l0, 0x1b, %l0
a00de1b0:  f8 07 be ac  ld  [ %fp + -340 ], %i4
a00de1b4:  a0 04 00 16  add  %l0, %l6, %l0
a00de1b8:  ab 2d 60 0b  sll  %l5, 0xb, %l5
a00de1bc:  ec 07 be bc  ld  [ %fp + -324 ], %l6
a00de1c0:  aa 05 40 1c  add  %l5, %i4, %l5
a00de1c4:  9f 2b e0 1b  sll  %o7, 0x1b, %o7
a00de1c8:  e4 07 be a4  ld  [ %fp + -348 ], %l2
a00de1cc:  a7 2c e0 06  sll  %l3, 6, %l3
a00de1d0:  9e 03 c0 16  add  %o7, %l6, %o7
a00de1d4:  b8 0a a0 3f  and  %o2, 0x3f, %i4
a00de1d8:  91 2a 20 1b  sll  %o0, 0x1b, %o0
a00de1dc:  a3 2c 60 0b  sll  %l1, 0xb, %l1
a00de1e0:  d4 07 be e0  ld  [ %fp + -288 ], %o2
a00de1e4:  90 02 00 12  add  %o0, %l2, %o0
a00de1e8:  a2 04 40 13  add  %l1, %l3, %l1
a00de1ec:  2d 2a 01 e5  sethi  %hi(0xa8079400), %l6
a00de1f0:  a6 15 a1 5c  or  %l6, 0x15c, %l3	! 0xa807955c
a00de1f4:  e4 07 be c8  ld  [ %fp + -312 ], %l2
a00de1f8:  af 2a a0 10  sll  %o2, 0x10, %l7
a00de1fc:  d4 07 be b4  ld  [ %fp + -332 ], %o2
a00de200:  ac 0c a0 3f  and  %l2, 0x3f, %l6
a00de204:  a5 2a a0 10  sll  %o2, 0x10, %l2
a00de208:  d4 07 be 9c  ld  [ %fp + -356 ], %o2
a00de20c:  82 08 60 3f  and  %g1, 0x3f, %g1
a00de210:  95 2a a0 10  sll  %o2, 0x10, %o2
a00de214:  d4 27 be 98  st  %o2, [ %fp + -360 ]
a00de218:  ba 07 40 01  add  %i5, %g1, %i5
a00de21c:  c2 07 bf 04  ld  [ %fp + -252 ], %g1
a00de220:  d4 07 be 94  ld  [ %fp + -364 ], %o2
a00de224:  b7 2e e0 10  sll  %i3, 0x10, %i3
a00de228:  b6 00 40 1b  add  %g1, %i3, %i3
a00de22c:  94 0a a0 3f  and  %o2, 0x3f, %o2
a00de230:  d4 27 be 90  st  %o2, [ %fp + -368 ]
a00de234:  c2 07 be f0  ld  [ %fp + -272 ], %g1
a00de238:  d4 07 be 8c  ld  [ %fp + -372 ], %o2
a00de23c:  b8 00 40 1c  add  %g1, %i4, %i4
a00de240:  f8 27 be ec  st  %i4, [ %fp + -276 ]
a00de244:  b3 2a a0 16  sll  %o2, 0x16, %i1
a00de248:  f8 07 be cc  ld  [ %fp + -308 ], %i4
a00de24c:  d4 07 be 88  ld  [ %fp + -376 ], %o2
a00de250:  ac 07 00 16  add  %i4, %l6, %l6
a00de254:  94 0a a0 3f  and  %o2, 0x3f, %o2
a00de258:  d4 27 be 84  st  %o2, [ %fp + -380 ]
a00de25c:  ec 27 be c4  st  %l6, [ %fp + -316 ]
a00de260:  c2 07 be 98  ld  [ %fp + -360 ], %g1
a00de264:  9e 03 c0 12  add  %o7, %l2, %o7
a00de268:  d4 0d 20 0a  ldub  [ %l4 + 0xa ], %o2
a00de26c:  e4 07 be 90  ld  [ %fp + -368 ], %l2
a00de270:  90 02 00 01  add  %o0, %g1, %o0
a00de274:  ec 07 be 84  ld  [ %fp + -380 ], %l6
a00de278:  f8 07 be ec  ld  [ %fp + -276 ], %i4
a00de27c:  9b 2b 60 1b  sll  %o5, 0x1b, %o5
a00de280:  99 2b 20 0b  sll  %o4, 0xb, %o4
a00de284:  b5 2e a0 06  sll  %i2, 6, %i2
a00de288:  a2 04 40 12  add  %l1, %l2, %l1
a00de28c:  ad 2d a0 10  sll  %l6, 0x10, %l6
a00de290:  94 0a a0 3f  and  %o2, 0x3f, %o2
a00de294:  c2 04 e0 38  ld  [ %l3 + 0x38 ], %g1
a00de298:  b8 06 c0 1c  add  %i3, %i4, %i4
a00de29c:  b0 0e 20 3f  and  %i0, 0x3f, %i0
a00de2a0:  9a 03 40 19  add  %o5, %i1, %o5
a00de2a4:  98 03 00 1a  add  %o4, %i2, %o4
a00de2a8:  98 03 00 0a  add  %o4, %o2, %o4
a00de2ac:  aa 05 40 18  add  %l5, %i0, %l5
a00de2b0:  ec 27 be 80  st  %l6, [ %fp + -384 ]
a00de2b4:  82 00 40 1d  add  %g1, %i5, %g1
a00de2b8:  f8 24 e0 3c  st  %i4, [ %l3 + 0x3c ]
a00de2bc:  e4 07 be c4  ld  [ %fp + -316 ], %l2
a00de2c0:  9a 03 40 16  add  %o5, %l6, %o5
a00de2c4:  f6 27 be fc  st  %i3, [ %fp + -260 ]
a00de2c8:  a0 04 00 17  add  %l0, %l7, %l0
a00de2cc:  c2 24 e0 38  st  %g1, [ %l3 + 0x38 ]
a00de2d0:  9e 03 c0 15  add  %o7, %l5, %o7
a00de2d4:  90 02 00 11  add  %o0, %l1, %o0
a00de2d8:  9a 03 40 0c  add  %o5, %o4, %o5
a00de2dc:  a0 04 00 12  add  %l0, %l2, %l0
a00de2e0:  e0 24 e0 40  st  %l0, [ %l3 + 0x40 ]
a00de2e4:  de 24 e0 44  st  %o7, [ %l3 + 0x44 ]
a00de2e8:  d0 24 e0 48  st  %o0, [ %l3 + 0x48 ]
a00de2ec:  da 24 e0 4c  st  %o5, [ %l3 + 0x4c ]
a00de2f0:  d4 0a e0 0e  ldub  [ %o3 + 0xe ], %o2
a00de2f4:  ea 0a 60 0e  ldub  [ %o1 + 0xe ], %l5
a00de2f8:  da 0a e0 0b  ldub  [ %o3 + 0xb ], %o5
a00de2fc:  ec 0a 60 0b  ldub  [ %o1 + 0xb ], %l6
a00de300:  e2 0d 20 0b  ldub  [ %l4 + 0xb ], %l1
a00de304:  d8 0a e0 0c  ldub  [ %o3 + 0xc ], %o4
a00de308:  e0 0a 60 0c  ldub  [ %o1 + 0xc ], %l0
a00de30c:  c2 0a e0 0d  ldub  [ %o3 + 0xd ], %g1
a00de310:  de 0a 60 0d  ldub  [ %o1 + 0xd ], %o7
a00de314:  d0 0d 20 0d  ldub  [ %l4 + 0xd ], %o0
a00de318:  b9 2d a0 16  sll  %l6, 0x16, %i4
a00de31c:  d2 0d 20 0e  ldub  [ %l4 + 0xe ], %o1
a00de320:  d6 0d 20 0c  ldub  [ %l4 + 0xc ], %o3
a00de324:  9b 2b 60 1b  sll  %o5, 0x1b, %o5
a00de328:  a2 0c 60 3f  and  %l1, 0x3f, %l1
a00de32c:  99 2b 20 0b  sll  %o4, 0xb, %o4
a00de330:  a1 2c 20 06  sll  %l0, 6, %l0
a00de334:  83 28 60 1b  sll  %g1, 0x1b, %g1
a00de338:  9f 2b e0 16  sll  %o7, 0x16, %o7
a00de33c:  90 0a 20 3f  and  %o0, 0x3f, %o0
a00de340:  95 2a a0 0b  sll  %o2, 0xb, %o2
a00de344:  ab 2d 60 06  sll  %l5, 6, %l5
a00de348:  9a 03 40 1c  add  %o5, %i4, %o5
a00de34c:  98 03 00 10  add  %o4, %l0, %o4
a00de350:  82 00 40 0f  add  %g1, %o7, %g1
a00de354:  94 02 80 15  add  %o2, %l5, %o2
a00de358:  a3 2c 60 10  sll  %l1, 0x10, %l1
a00de35c:  96 0a e0 3f  and  %o3, 0x3f, %o3
a00de360:  91 2a 20 10  sll  %o0, 0x10, %o0
a00de364:  92 0a 60 3f  and  %o1, 0x3f, %o1
a00de368:  9a 03 40 11  add  %o5, %l1, %o5
a00de36c:  98 03 00 0b  add  %o4, %o3, %o4
a00de370:  82 00 40 08  add  %g1, %o0, %g1
a00de374:  94 02 80 09  add  %o2, %o1, %o2
a00de378:  9a 03 40 0c  add  %o5, %o4, %o5
a00de37c:  82 00 40 0a  add  %g1, %o2, %g1
a00de380:  c2 24 e0 54  st  %g1, [ %l3 + 0x54 ]
a00de384:  da 24 e0 50  st  %o5, [ %l3 + 0x50 ]
a00de388:  a8 10 20 00  clr  %l4
a00de38c:  10 80 00 b7  b  0xa00de668
a00de390:  b8 10 20 01  mov  1, %i4
a00de394:  99 28 60 04  sll  %g1, 4, %o4
a00de398:  98 23 00 01  sub  %o4, %g1, %o4
a00de39c:  1b 27 c7 3a  sethi  %hi(0x9f1ce800), %o5
a00de3a0:  03 27 c7 3a  sethi  %hi(0x9f1ce800), %g1
a00de3a4:  9a 13 63 72  or  %o5, 0x372, %o5
a00de3a8:  82 10 62 af  or  %g1, 0x2af, %g1
a00de3ac:  94 03 00 01  add  %o4, %g1, %o2
a00de3b0:  96 03 00 0d  add  %o4, %o5, %o3
a00de3b4:  d0 0a a0 05  ldub  [ %o2 + 5 ], %o0
a00de3b8:  d2 0a e0 06  ldub  [ %o3 + 6 ], %o1
a00de3bc:  e2 0a a0 06  ldub  [ %o2 + 6 ], %l1
a00de3c0:  e4 0a a0 07  ldub  [ %o2 + 7 ], %l2
a00de3c4:  d0 27 be 50  st  %o0, [ %fp + -432 ]
a00de3c8:  d2 27 be 44  st  %o1, [ %fp + -444 ]
a00de3cc:  e2 27 be 3c  st  %l1, [ %fp + -452 ]
a00de3d0:  d0 0a a0 08  ldub  [ %o2 + 8 ], %o0
a00de3d4:  d2 0a a0 09  ldub  [ %o2 + 9 ], %o1
a00de3d8:  e2 0a a0 0b  ldub  [ %o2 + 0xb ], %l1
a00de3dc:  e4 27 be 2c  st  %l2, [ %fp + -468 ]
a00de3e0:  e8 0b 40 0c  ldub  [ %o5 + %o4 ], %l4
a00de3e4:  ec 0a e0 08  ldub  [ %o3 + 8 ], %l6
a00de3e8:  e4 0a a0 0e  ldub  [ %o2 + 0xe ], %l2
a00de3ec:  c2 08 40 0c  ldub  [ %g1 + %o4 ], %g1
a00de3f0:  d0 27 be 1c  st  %o0, [ %fp + -484 ]
a00de3f4:  d2 27 be 0c  st  %o1, [ %fp + -500 ]
a00de3f8:  e2 27 be 04  st  %l1, [ %fp + -508 ]
a00de3fc:  ea 0a e0 03  ldub  [ %o3 + 3 ], %l5
a00de400:  da 0a a0 03  ldub  [ %o2 + 3 ], %o5
a00de404:  d8 0a e0 04  ldub  [ %o3 + 4 ], %o4
a00de408:  de 0a a0 04  ldub  [ %o2 + 4 ], %o7
a00de40c:  f8 0a e0 05  ldub  [ %o3 + 5 ], %i4
a00de410:  e0 0a e0 07  ldub  [ %o3 + 7 ], %l0
a00de414:  d0 0a e0 09  ldub  [ %o3 + 9 ], %o0
a00de418:  e6 0a e0 0a  ldub  [ %o3 + 0xa ], %l3
a00de41c:  f0 0a a0 0a  ldub  [ %o2 + 0xa ], %i0
a00de420:  d2 0a e0 0b  ldub  [ %o3 + 0xb ], %o1
a00de424:  e2 0a e0 0c  ldub  [ %o3 + 0xc ], %l1
a00de428:  f4 0a a0 0c  ldub  [ %o2 + 0xc ], %i2
a00de42c:  fa 0a e0 0e  ldub  [ %o3 + 0xe ], %i5
a00de430:  ec 27 be 24  st  %l6, [ %fp + -476 ]
a00de434:  e4 27 bd fc  st  %l2, [ %fp + -516 ]
a00de438:  83 28 60 06  sll  %g1, 6, %g1
a00de43c:  c2 27 be 74  st  %g1, [ %fp + -396 ]
a00de440:  9b 2b 60 16  sll  %o5, 0x16, %o5
a00de444:  99 2b 20 0b  sll  %o4, 0xb, %o4
a00de448:  b9 2f 20 1b  sll  %i4, 0x1b, %i4
a00de44c:  da 27 be 68  st  %o5, [ %fp + -408 ]
a00de450:  d8 27 be 64  st  %o4, [ %fp + -412 ]
a00de454:  f8 27 be 54  st  %i4, [ %fp + -428 ]
a00de458:  c2 07 be 3c  ld  [ %fp + -452 ], %g1
a00de45c:  ec 07 be 50  ld  [ %fp + -432 ], %l6
a00de460:  f8 07 be 44  ld  [ %fp + -444 ], %i4
a00de464:  83 28 60 06  sll  %g1, 6, %g1
a00de468:  d8 07 be 2c  ld  [ %fp + -468 ], %o4
a00de46c:  da 07 be 24  ld  [ %fp + -476 ], %o5
a00de470:  ad 2d a0 16  sll  %l6, 0x16, %l6
a00de474:  b9 2f 20 0b  sll  %i4, 0xb, %i4
a00de478:  c2 27 be 38  st  %g1, [ %fp + -456 ]
a00de47c:  99 2b 20 16  sll  %o4, 0x16, %o4
a00de480:  9b 2b 60 0b  sll  %o5, 0xb, %o5
a00de484:  c2 0a e0 02  ldub  [ %o3 + 2 ], %g1
a00de488:  ec 27 be 4c  st  %l6, [ %fp + -436 ]
a00de48c:  9f 2b e0 06  sll  %o7, 6, %o7
a00de490:  f8 27 be 40  st  %i4, [ %fp + -448 ]
a00de494:  d8 27 be 28  st  %o4, [ %fp + -472 ]
a00de498:  da 27 be 20  st  %o5, [ %fp + -480 ]
a00de49c:  e4 07 be 1c  ld  [ %fp + -484 ], %l2
a00de4a0:  de 27 be 60  st  %o7, [ %fp + -416 ]
a00de4a4:  d8 0a e0 01  ldub  [ %o3 + 1 ], %o4
a00de4a8:  da 0a e0 0d  ldub  [ %o3 + 0xd ], %o5
a00de4ac:  a5 2c a0 06  sll  %l2, 6, %l2
a00de4b0:  ec 07 be 0c  ld  [ %fp + -500 ], %l6
a00de4b4:  f8 07 be 04  ld  [ %fp + -508 ], %i4
a00de4b8:  c2 27 be 70  st  %g1, [ %fp + -400 ]
a00de4bc:  de 0a a0 01  ldub  [ %o2 + 1 ], %o7
a00de4c0:  c2 0a a0 02  ldub  [ %o2 + 2 ], %g1
a00de4c4:  d6 0a a0 0d  ldub  [ %o2 + 0xd ], %o3
a00de4c8:  e4 27 be 18  st  %l2, [ %fp + -488 ]
a00de4cc:  ad 2d a0 16  sll  %l6, 0x16, %l6
a00de4d0:  b9 2f 20 16  sll  %i4, 0x16, %i4
a00de4d4:  d4 07 be 74  ld  [ %fp + -396 ], %o2
a00de4d8:  e4 07 be 68  ld  [ %fp + -408 ], %l2
a00de4dc:  ec 27 be 08  st  %l6, [ %fp + -504 ]
a00de4e0:  f8 27 be 00  st  %i4, [ %fp + -512 ]
a00de4e4:  a9 2d 20 0b  sll  %l4, 0xb, %l4
a00de4e8:  ab 2d 60 1b  sll  %l5, 0x1b, %l5
a00de4ec:  f8 07 be 60  ld  [ %fp + -416 ], %i4
a00de4f0:  a8 05 00 0a  add  %l4, %o2, %l4
a00de4f4:  aa 05 40 12  add  %l5, %l2, %l5
a00de4f8:  ec 07 be 64  ld  [ %fp + -412 ], %l6
a00de4fc:  ac 05 80 1c  add  %l6, %i4, %l6
a00de500:  e4 07 be 4c  ld  [ %fp + -436 ], %l2
a00de504:  d4 07 be 54  ld  [ %fp + -428 ], %o2
a00de508:  94 02 80 12  add  %o2, %l2, %o2
a00de50c:  ec 27 be 5c  st  %l6, [ %fp + -420 ]
a00de510:  d4 27 be 48  st  %o2, [ %fp + -440 ]
a00de514:  f8 07 be 38  ld  [ %fp + -456 ], %i4
a00de518:  ec 07 be 40  ld  [ %fp + -448 ], %l6
a00de51c:  ac 05 80 1c  add  %l6, %i4, %l6
a00de520:  ec 27 be 34  st  %l6, [ %fp + -460 ]
a00de524:  ec 07 be 18  ld  [ %fp + -488 ], %l6
a00de528:  e4 07 be 20  ld  [ %fp + -480 ], %l2
a00de52c:  a4 04 80 16  add  %l2, %l6, %l2
a00de530:  e4 27 be 14  st  %l2, [ %fp + -492 ]
a00de534:  9f 2b e0 16  sll  %o7, 0x16, %o7
a00de538:  99 2b 20 1b  sll  %o4, 0x1b, %o4
a00de53c:  e4 07 be 70  ld  [ %fp + -400 ], %l2
a00de540:  a5 2c a0 0b  sll  %l2, 0xb, %l2
a00de544:  83 28 60 06  sll  %g1, 6, %g1
a00de548:  98 03 00 0f  add  %o4, %o7, %o4
a00de54c:  9e 04 80 01  add  %l2, %g1, %o7
a00de550:  f8 07 be 08  ld  [ %fp + -504 ], %i4
a00de554:  03 00 0f 80  sethi  %hi(0x3e0000), %g1
a00de558:  91 2a 20 1b  sll  %o0, 0x1b, %o0
a00de55c:  90 02 00 1c  add  %o0, %i4, %o0
a00de560:  aa 05 40 01  add  %l5, %g1, %l5
a00de564:  03 00 0e 80  sethi  %hi(0x3a0000), %g1
a00de568:  f8 07 be 48  ld  [ %fp + -440 ], %i4
a00de56c:  b2 07 00 01  add  %i4, %g1, %i1
a00de570:  d4 07 be 28  ld  [ %fp + -472 ], %o2
a00de574:  a1 2c 20 1b  sll  %l0, 0x1b, %l0
a00de578:  a0 04 00 0a  add  %l0, %o2, %l0
a00de57c:  03 00 0e 00  sethi  %hi(0x380000), %g1
a00de580:  a0 04 00 01  add  %l0, %g1, %l0
a00de584:  b5 2e a0 06  sll  %i2, 6, %i2
a00de588:  a3 2c 60 0b  sll  %l1, 0xb, %l1
a00de58c:  c2 07 be 5c  ld  [ %fp + -420 ], %g1
a00de590:  82 00 60 3c  add  %g1, 0x3c, %g1
a00de594:  d4 07 be 00  ld  [ %fp + -512 ], %o2
a00de598:  a2 04 40 1a  add  %l1, %i2, %l1
a00de59c:  97 2a e0 16  sll  %o3, 0x16, %o3
a00de5a0:  ec 07 bd fc  ld  [ %fp + -516 ], %l6
a00de5a4:  93 2a 60 1b  sll  %o1, 0x1b, %o1
a00de5a8:  9b 2b 60 1b  sll  %o5, 0x1b, %o5
a00de5ac:  92 02 40 0a  add  %o1, %o2, %o1
a00de5b0:  b5 2d a0 06  sll  %l6, 6, %i2
a00de5b4:  9a 03 40 0b  add  %o5, %o3, %o5
a00de5b8:  aa 05 40 01  add  %l5, %g1, %l5
a00de5bc:  a7 2c e0 0b  sll  %l3, 0xb, %l3
a00de5c0:  b1 2e 20 06  sll  %i0, 6, %i0
a00de5c4:  e4 27 be 6c  st  %l2, [ %fp + -404 ]
a00de5c8:  bb 2f 60 0b  sll  %i5, 0xb, %i5
a00de5cc:  c2 27 be 58  st  %g1, [ %fp + -424 ]
a00de5d0:  15 00 0d 80  sethi  %hi(0x360000), %o2
a00de5d4:  a6 04 c0 18  add  %l3, %i0, %l3
a00de5d8:  ba 07 40 1a  add  %i5, %i2, %i5
a00de5dc:  a8 05 20 02  add  %l4, 2, %l4
a00de5e0:  d6 07 be 34  ld  [ %fp + -460 ], %o3
a00de5e4:  e4 07 be 14  ld  [ %fp + -492 ], %l2
a00de5e8:  2d 1f 5f 80  sethi  %hi(0x7d7e0000), %l6
a00de5ec:  03 00 0d 00  sethi  %hi(0x340000), %g1
a00de5f0:  39 2a 01 e5  sethi  %hi(0xa8079400), %i4
a00de5f4:  b8 17 21 5c  or  %i4, 0x15c, %i4	! 0xa807955c
a00de5f8:  96 02 e0 38  add  %o3, 0x38, %o3
a00de5fc:  a4 04 a0 38  add  %l2, 0x38, %l2
a00de600:  a8 05 00 16  add  %l4, %l6, %l4
a00de604:  92 02 40 0a  add  %o1, %o2, %o1
a00de608:  90 02 00 0a  add  %o0, %o2, %o0
a00de60c:  a6 04 e0 36  add  %l3, 0x36, %l3
a00de610:  a2 04 60 34  add  %l1, 0x34, %l1
a00de614:  9a 03 40 01  add  %o5, %g1, %o5
a00de618:  ba 07 60 34  add  %i5, 0x34, %i5
a00de61c:  b2 06 40 0b  add  %i1, %o3, %i1
a00de620:  98 03 00 0f  add  %o4, %o7, %o4
a00de624:  a0 04 00 12  add  %l0, %l2, %l0
a00de628:  90 02 00 13  add  %o0, %l3, %o0
a00de62c:  92 02 40 11  add  %o1, %l1, %o1
a00de630:  e8 27 20 38  st  %l4, [ %i4 + 0x38 ]
a00de634:  9a 03 40 1d  add  %o5, %i5, %o5
a00de638:  d6 27 be 30  st  %o3, [ %fp + -464 ]
a00de63c:  e4 27 be 10  st  %l2, [ %fp + -496 ]
a00de640:  f2 27 bd f0  st  %i1, [ %fp + -528 ]
a00de644:  d8 27 20 3c  st  %o4, [ %i4 + 0x3c ]
a00de648:  ea 27 20 40  st  %l5, [ %i4 + 0x40 ]
a00de64c:  f2 27 20 44  st  %i1, [ %i4 + 0x44 ]
a00de650:  e0 27 20 48  st  %l0, [ %i4 + 0x48 ]
a00de654:  d0 27 20 4c  st  %o0, [ %i4 + 0x4c ]
a00de658:  d2 27 20 50  st  %o1, [ %i4 + 0x50 ]
a00de65c:  da 27 20 54  st  %o5, [ %i4 + 0x54 ]
a00de660:  a8 10 20 00  clr  %l4
a00de664:  b8 10 20 00  clr  %i4
a00de668:  9a 0d 20 ff  and  %l4, 0xff, %o5
a00de66c:  82 0f 20 ff  and  %i4, 0xff, %g1
a00de670:  83 28 60 18  sll  %g1, 0x18, %g1
a00de674:  9b 2b 60 19  sll  %o5, 0x19, %o5
a00de678:  d8 0f bf e7  ldub  [ %fp + -25 ], %o4
a00de67c:  d0 17 bf ce  lduh  [ %fp + -50 ], %o0
a00de680:  9a 03 40 01  add  %o5, %g1, %o5
a00de684:  99 2b 20 10  sll  %o4, 0x10, %o4
a00de688:  96 0a 20 2a  and  %o0, 0x2a, %o3
a00de68c:  25 2a 01 e5  sethi  %hi(0xa8079400), %l2
a00de690:  82 14 a1 5c  or  %l2, 0x15c, %g1	! 0xa807955c
a00de694:  9a 03 40 0c  add  %o5, %o4, %o5
a00de698:  96 02 e8 00  add  %o3, 0x800, %o3
a00de69c:  d2 07 bf a8  ld  [ %fp + -88 ], %o1
a00de6a0:  d6 20 60 60  st  %o3, [ %g1 + 0x60 ]
a00de6a4:  da 20 60 58  st  %o5, [ %g1 + 0x58 ]
a00de6a8:  80 a2 60 10  cmp  %o1, 0x10
a00de6ac:  c0 20 60 5c  clr  [ %g1 + 0x5c ]
a00de6b0:  12 80 00 03  bne  0xa00de6bc
a00de6b4:  e0 0f bf b7  ldub  [ %fp + -73 ], %l0
a00de6b8:  a0 10 20 0f  mov  0xf, %l0
a00de6bc:  d4 17 bf ee  lduh  [ %fp + -18 ], %o2
a00de6c0:  83 2a a0 10  sll  %o2, 0x10, %g1
a00de6c4:  1b 2a aa aa  sethi  %hi(0xaaaaa800), %o5
a00de6c8:  83 30 60 10  srl  %g1, 0x10, %g1
a00de6cc:  9a 13 62 ab  or  %o5, 0x2ab, %o5
a00de6d0:  80 50 40 0d  umul  %g1, %o5, %g0
a00de6d4:  9b 40 00 00  rd  %y, %o5
a00de6d8:  99 33 60 01  srl  %o5, 1, %o4
a00de6dc:  9a 03 00 0c  add  %o4, %o4, %o5
a00de6e0:  9a 03 40 0c  add  %o5, %o4, %o5
a00de6e4:  82 20 40 0d  sub  %g1, %o5, %g1
a00de6e8:  90 08 60 ff  and  %g1, 0xff, %o0
a00de6ec:  80 a2 20 00  cmp  %o0, 0
a00de6f0:  02 80 00 03  be  0xa00de6fc
a00de6f4:  9e 10 00 0c  mov  %o4, %o7
a00de6f8:  9e 03 20 01  add  %o4, 1, %o7
a00de6fc:  d6 07 bf a0  ld  [ %fp + -96 ], %o3
a00de700:  da 07 bf 9c  ld  [ %fp + -100 ], %o5
a00de704:  83 33 60 10  srl  %o5, 0x10, %g1
a00de708:  99 32 e0 10  srl  %o3, 0x10, %o4
a00de70c:  98 5b 00 01  smul  %o4, %g1, %o4
a00de710:  17 0a aa aa  sethi  %hi(0x2aaaa800), %o3
a00de714:  95 2b 20 03  sll  %o4, 3, %o2
a00de718:  96 12 e2 ab  or  %o3, 0x2ab, %o3
a00de71c:  80 5a 80 0b  smul  %o2, %o3, %g0
a00de720:  9b 40 00 00  rd  %y, %o5
a00de724:  83 3a a0 1f  sra  %o2, 0x1f, %g1
a00de728:  9b 3b 60 05  sra  %o5, 5, %o5
a00de72c:  9a 23 40 01  sub  %o5, %g1, %o5
a00de730:  82 03 40 0d  add  %o5, %o5, %g1
a00de734:  82 00 40 0d  add  %g1, %o5, %g1
a00de738:  83 28 60 06  sll  %g1, 6, %g1
a00de73c:  82 22 80 01  sub  %o2, %g1, %g1
a00de740:  80 5b 00 0b  smul  %o4, %o3, %g0
a00de744:  97 40 00 00  rd  %y, %o3
a00de748:  a3 3a a0 1f  sra  %o2, 0x1f, %l1
a00de74c:  81 84 60 00  mov  %l1, %y
a00de750:  e2 07 bf 98  ld  [ %fp + -104 ], %l1
a00de754:  01 00 00 00  nop
a00de758:  01 00 00 00  nop
a00de75c:  92 7a 80 11  sdiv  %o2, %l1, %o1
a00de760:  80 a0 00 01  cmp  %g0, %g1
a00de764:  99 3b 20 1f  sra  %o4, 0x1f, %o4
a00de768:  97 3a e0 02  sra  %o3, 2, %o3
a00de76c:  ec 07 bf 98  ld  [ %fp + -104 ], %l6
a00de770:  82 5a 40 16  smul  %o1, %l6, %g1
a00de774:  96 22 c0 0c  sub  %o3, %o4, %o3
a00de778:  96 40 00 0b  addx  %g0, %o3, %o3
a00de77c:  94 22 80 01  sub  %o2, %g1, %o2
a00de780:  9a 0a 20 03  and  %o0, 3, %o5
a00de784:  80 a0 00 0a  cmp  %g0, %o2
a00de788:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00de78c:  9b 2b 60 1c  sll  %o5, 0x1c, %o5
a00de790:  99 2a e0 02  sll  %o3, 2, %o4
a00de794:  9a 03 40 01  add  %o5, %g1, %o5
a00de798:  92 40 00 09  addx  %g0, %o1, %o1
a00de79c:  94 0b e7 ff  and  %o7, 0x7ff, %o2
a00de7a0:  98 23 00 09  sub  %o4, %o1, %o4
a00de7a4:  03 38 00 00  sethi  %hi(0xe0000000), %g1
a00de7a8:  82 2a c0 01  andn  %o3, %g1, %g1
a00de7ac:  95 2a a0 10  sll  %o2, 0x10, %o2
a00de7b0:  99 2b 20 1d  sll  %o4, 0x1d, %o4
a00de7b4:  9a 03 40 0a  add  %o5, %o2, %o5
a00de7b8:  96 0c 20 0f  and  %l0, 0xf, %o3
a00de7bc:  98 03 00 01  add  %o4, %g1, %o4
a00de7c0:  82 14 a1 5c  or  %l2, 0x15c, %g1
a00de7c4:  9a 03 40 0b  add  %o5, %o3, %o5
a00de7c8:  da 20 60 64  st  %o5, [ %g1 + 0x64 ]
a00de7cc:  d8 20 60 68  st  %o4, [ %g1 + 0x68 ]
a00de7d0:  a2 10 00 01  mov  %g1, %l1
a00de7d4:  96 10 20 00  clr  %o3
a00de7d8:  15 30 04 40  sethi  %hi(0xc0110000), %o2
a00de7dc:  82 0a e0 ff  and  %o3, 0xff, %g1
a00de7e0:  83 28 60 02  sll  %g1, 2, %g1
a00de7e4:  d8 04 40 01  ld  [ %l1 + %g1 ], %o4
a00de7e8:  96 02 e0 01  inc  %o3
a00de7ec:  82 10 40 0a  or  %g1, %o2, %g1
a00de7f0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00de7f4:  d8 20 40 00  st  %o4, [ %g1 ]
a00de7f8:  80 a3 60 17  cmp  %o5, 0x17
a00de7fc:  08 bf ff f9  bleu  0xa00de7e0
a00de800:  82 0a e0 ff  and  %o3, 0xff, %g1
a00de804:  c2 04 60 60  ld  [ %l1 + 0x60 ], %g1
a00de808:  9a 12 a0 60  or  %o2, 0x60, %o5
a00de80c:  c2 23 40 00  st  %g1, [ %o5 ]
a00de810:  a0 12 a0 64  or  %o2, 0x64, %l0
a00de814:  c2 04 60 64  ld  [ %l1 + 0x64 ], %g1
a00de818:  c2 24 00 00  st  %g1, [ %l0 ]
a00de81c:  40 3a fb f9  call  0xa0f9d800
a00de820:  01 00 00 00  nop
a00de824:  90 0a 20 ff  and  %o0, 0xff, %o0
a00de828:  80 a2 20 83  cmp  %o0, 0x83
a00de82c:  08 80 00 06  bleu  0xa00de844
a00de830:  03 30 04 40  sethi  %hi(0xc0110000), %g1
a00de834:  c2 04 00 00  ld  [ %l0 ], %g1
a00de838:  82 10 62 00  or  %g1, 0x200, %g1
a00de83c:  c2 24 00 00  st  %g1, [ %l0 ]
a00de840:  03 30 04 40  sethi  %hi(0xc0110000), %g1
a00de844:  da 04 60 68  ld  [ %l1 + 0x68 ], %o5
a00de848:  82 10 60 9c  or  %g1, 0x9c, %g1
a00de84c:  da 20 40 00  st  %o5, [ %g1 ]
a00de850:  a8 10 20 00  clr  %l4
a00de854:  a0 0d 20 ff  and  %l4, 0xff, %l0
a00de858:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00de85c:  a8 05 20 01  inc  %l4
a00de860:  80 8c 20 03  btst  3, %l0
a00de864:  12 80 00 04  bne  0xa00de874
a00de868:  90 12 22 88  or  %o0, 0x288, %o0
a00de86c:  40 3a 91 f6  call  0xa0f83044
a00de870:  01 00 00 00  nop
a00de874:  82 14 a1 5c  or  %l2, 0x15c, %g1
a00de878:  9b 2c 20 02  sll  %l0, 2, %o5
a00de87c:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00de880:  d2 00 40 0d  ld  [ %g1 + %o5 ], %o1
a00de884:  40 3a 91 f0  call  0xa0f83044
a00de888:  90 12 22 90  or  %o0, 0x290, %o0
a00de88c:  82 0d 20 ff  and  %l4, 0xff, %g1
a00de890:  80 a0 60 1a  cmp  %g1, 0x1a
a00de894:  28 bf ff f1  bleu,a   0xa00de858
a00de898:  a0 0d 20 ff  and  %l4, 0xff, %l0
a00de89c:  31 27 c7 3b  sethi  %hi(0x9f1cec00), %i0
a00de8a0:  40 3a 91 e9  call  0xa0f83044
a00de8a4:  91 ee 22 98  restore  %i0, 0x298, %o0
