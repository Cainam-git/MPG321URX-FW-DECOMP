# leon2m FUN_a0130438 0xa0130438-0xa013129c (828 bytes)
a0130438:  9d e3 bf 98  save  %sp, -104, %sp
a013043c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0130440:  c2 08 61 a7  ldub  [ %g1 + 0x1a7 ], %g1	! 0xa802e1a7
a0130444:  80 a0 60 07  cmp  %g1, 7
a0130448:  18 80 00 8f  bgu  0xa0130684
a013044c:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a0130450:  13 00 03 3c  sethi  %hi(0xcf000), %o1
a0130454:  91 28 60 02  sll  %g1, 2, %o0
a0130458:  9a 12 61 cc  or  %o1, 0x1cc, %o5
a013045c:  d8 03 40 08  ld  [ %o5 + %o0 ], %o4
a0130460:  81 c3 00 00  jmp  %o4
a0130464:  01 00 00 00  nop
a0130468:  21 2a 00 b7  sethi  %hi(0xa802dc00), %l0
a013046c:  b2 14 23 30  or  %l0, 0x330, %i1	! 0xa802df30
a0130470:  29 3f bf ff  sethi  %hi(0xfefffc00), %l4
a0130474:  d6 06 60 70  ld  [ %i1 + 0x70 ], %o3
a0130478:  a2 15 23 ff  or  %l4, 0x3ff, %l1
a013047c:  a4 0a c0 11  and  %o3, %l1, %l2
a0130480:  d6 04 23 30  ld  [ %l0 + 0x330 ], %o3
a0130484:  27 00 40 00  sethi  %hi(0x1000000), %l3
a0130488:  9e 14 80 13  or  %l2, %l3, %o7
a013048c:  95 32 e0 1c  srl  %o3, 0x1c, %o2
a0130490:  80 a2 a0 00  cmp  %o2, 0
a0130494:  12 80 00 08  bne  0xa01304b4
a0130498:  de 26 60 70  st  %o7, [ %i1 + 0x70 ]
a013049c:  11 3c 00 00  sethi  %hi(0xf0000000), %o0
a01304a0:  82 2a c0 08  andn  %o3, %o0, %g1
a01304a4:  19 14 00 00  sethi  %hi(0x50000000), %o4
a01304a8:  b0 10 40 0c  or  %g1, %o4, %i0
a01304ac:  f0 24 23 30  st  %i0, [ %l0 + 0x330 ]
a01304b0:  96 10 00 18  mov  %i0, %o3
a01304b4:  a5 32 e0 0c  srl  %o3, 0xc, %l2
a01304b8:  94 0c a0 0f  and  %l2, 0xf, %o2
a01304bc:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a01304c0:  b0 13 e2 24  or  %o7, 0x224, %i0	! 0xa802e224
a01304c4:  92 5a a0 2a  smul  %o2, 0x2a, %o1
a01304c8:  98 02 40 18  add  %o1, %i0, %o4
a01304cc:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a01304d0:  80 a3 60 01  cmp  %o5, 1
a01304d4:  12 80 00 03  bne  0xa01304e0
a01304d8:  a6 10 20 02  mov  2, %l3
a01304dc:  e6 2b 20 02  stb  %l3, [ %o4 + 2 ]
a01304e0:  40 00 46 00  call  0xa0141ce0
a01304e4:  d0 0b 20 0a  ldub  [ %o4 + 0xa ], %o0
a01304e8:  96 0a 20 ff  and  %o0, 0xff, %o3
a01304ec:  80 a2 e0 01  cmp  %o3, 1
a01304f0:  02 80 03 2a  be  0xa0131198
a01304f4:  da 04 23 30  ld  [ %l0 + 0x330 ], %o5
a01304f8:  d2 04 23 30  ld  [ %l0 + 0x330 ], %o1
a01304fc:  a1 32 60 04  srl  %o1, 4, %l0
a0130500:  90 0c 20 0f  and  %l0, 0xf, %o0
a0130504:  80 a2 20 04  cmp  %o0, 4
a0130508:  02 80 00 04  be  0xa0130518
a013050c:  01 00 00 00  nop
a0130510:  7f ff 18 b0  call  0xa00f67d0
a0130514:  01 00 00 00  nop
a0130518:  40 00 32 24  call  0xa013cda8
a013051c:  90 10 20 00  clr  %o0	! 0x0
a0130520:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130524:  7f ff 63 d4  call  0xa0109474
a0130528:  92 10 20 00  clr  %o1
a013052c:  da 06 60 78  ld  [ %i1 + 0x78 ], %o5
a0130530:  91 33 60 0c  srl  %o5, 0xc, %o0
a0130534:  a6 06 60 78  add  %i1, 0x78, %l3
a0130538:  82 0a 20 0f  and  %o0, 0xf, %g1
a013053c:  d8 04 e0 70  ld  [ %l3 + 0x70 ], %o4
a0130540:  a8 58 60 2a  smul  %g1, 0x2a, %l4
a0130544:  96 0b 00 11  and  %o4, %l1, %o3
a0130548:  d6 24 e0 70  st  %o3, [ %l3 + 0x70 ]
a013054c:  a4 05 00 18  add  %l4, %i0, %l2
a0130550:  40 00 45 e4  call  0xa0141ce0
a0130554:  d0 0c a0 0a  ldub  [ %l2 + 0xa ], %o0
a0130558:  de 06 60 78  ld  [ %i1 + 0x78 ], %o7
a013055c:  95 33 e0 04  srl  %o7, 4, %o2
a0130560:  90 0a a0 0f  and  %o2, 0xf, %o0
a0130564:  80 a2 20 04  cmp  %o0, 4
a0130568:  02 80 00 05  be  0xa013057c
a013056c:  15 03 ff ff  sethi  %hi(0xffffc00), %o2
a0130570:  7f ff 18 98  call  0xa00f67d0
a0130574:  01 00 00 00  nop
a0130578:  15 03 ff ff  sethi  %hi(0xffffc00), %o2
a013057c:  a0 12 a3 ff  or  %o2, 0x3ff, %l0	! 0xfffffff
a0130580:  d2 06 60 78  ld  [ %i1 + 0x78 ], %o1
a0130584:  9a 0a 40 10  and  %o1, %l0, %o5
a0130588:  da 26 60 78  st  %o5, [ %i1 + 0x78 ]
a013058c:  40 00 32 07  call  0xa013cda8
a0130590:  90 10 20 01  mov  1, %o0
a0130594:  92 10 20 00  clr  %o1
a0130598:  7f ff 63 b7  call  0xa0109474
a013059c:  90 0a 20 ff  and  %o0, 0xff, %o0
a01305a0:  d0 06 60 f0  ld  [ %i1 + 0xf0 ], %o0
a01305a4:  83 32 20 0c  srl  %o0, 0xc, %g1
a01305a8:  a4 06 60 f0  add  %i1, 0xf0, %l2
a01305ac:  e8 04 a0 70  ld  [ %l2 + 0x70 ], %l4
a01305b0:  98 08 60 0f  and  %g1, 0xf, %o4
a01305b4:  96 5b 20 2a  smul  %o4, 0x2a, %o3
a01305b8:  a6 0d 00 11  and  %l4, %l1, %l3
a01305bc:  9e 02 c0 18  add  %o3, %i0, %o7
a01305c0:  e6 24 a0 70  st  %l3, [ %l2 + 0x70 ]
a01305c4:  d0 0b e0 0a  ldub  [ %o7 + 0xa ], %o0
a01305c8:  40 00 45 c6  call  0xa0141ce0
a01305cc:  01 00 00 00  nop
a01305d0:  d4 06 60 f0  ld  [ %i1 + 0xf0 ], %o2
a01305d4:  93 32 a0 04  srl  %o2, 4, %o1
a01305d8:  90 0a 60 0f  and  %o1, 0xf, %o0
a01305dc:  80 a2 20 04  cmp  %o0, 4
a01305e0:  22 80 00 05  be,a   0xa01305f4
a01305e4:  d2 06 60 f0  ld  [ %i1 + 0xf0 ], %o1
a01305e8:  7f ff 18 7a  call  0xa00f67d0
a01305ec:  01 00 00 00  nop
a01305f0:  d2 06 60 f0  ld  [ %i1 + 0xf0 ], %o1
a01305f4:  9a 0a 40 10  and  %o1, %l0, %o5
a01305f8:  da 26 60 f0  st  %o5, [ %i1 + 0xf0 ]
a01305fc:  40 00 31 eb  call  0xa013cda8
a0130600:  90 10 20 02  mov  2, %o0
a0130604:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130608:  7f ff 63 9b  call  0xa0109474
a013060c:  92 10 20 00  clr  %o1
a0130610:  d0 06 61 68  ld  [ %i1 + 0x168 ], %o0
a0130614:  83 32 20 0c  srl  %o0, 0xc, %g1
a0130618:  a4 06 61 68  add  %i1, 0x168, %l2
a013061c:  e8 04 a0 70  ld  [ %l2 + 0x70 ], %l4
a0130620:  98 08 60 0f  and  %g1, 0xf, %o4
a0130624:  96 5b 20 2a  smul  %o4, 0x2a, %o3
a0130628:  a6 0d 00 11  and  %l4, %l1, %l3
a013062c:  9e 02 c0 18  add  %o3, %i0, %o7
a0130630:  e6 24 a0 70  st  %l3, [ %l2 + 0x70 ]
a0130634:  d0 0b e0 0a  ldub  [ %o7 + 0xa ], %o0
a0130638:  40 00 45 aa  call  0xa0141ce0
a013063c:  01 00 00 00  nop
a0130640:  f0 06 61 68  ld  [ %i1 + 0x168 ], %i0
a0130644:  a3 36 20 04  srl  %i0, 4, %l1
a0130648:  90 0c 60 0f  and  %l1, 0xf, %o0
a013064c:  80 a2 20 04  cmp  %o0, 4
a0130650:  22 80 00 05  be,a   0xa0130664
a0130654:  e2 06 61 68  ld  [ %i1 + 0x168 ], %l1
a0130658:  7f ff 18 5e  call  0xa00f67d0
a013065c:  01 00 00 00  nop
a0130660:  e2 06 61 68  ld  [ %i1 + 0x168 ], %l1
a0130664:  94 0c 40 10  and  %l1, %l0, %o2
a0130668:  d4 26 61 68  st  %o2, [ %i1 + 0x168 ]
a013066c:  40 00 31 cf  call  0xa013cda8
a0130670:  90 10 20 03  mov  3, %o0
a0130674:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130678:  7f ff 63 7f  call  0xa0109474
a013067c:  92 10 20 00  clr  %o1
a0130680:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a0130684:  d4 06 23 d0  ld  [ %i0 + 0x3d0 ], %o2	! 0xa802e3d0
a0130688:  11 00 08 00  sethi  %hi(0x200000), %o0
a013068c:  80 8a 80 08  btst  %o2, %o0
a0130690:  02 80 00 2e  be  0xa0130748
a0130694:  a8 16 23 d0  or  %i0, 0x3d0, %l4
a0130698:  1b 2a 00 b7  sethi  %hi(0xa802dc00), %o5
a013069c:  b2 13 63 30  or  %o5, 0x330, %i1	! 0xa802df30
a01306a0:  96 06 61 68  add  %i1, 0x168, %o3
a01306a4:  c2 02 e0 70  ld  [ %o3 + 0x70 ], %g1
a01306a8:  21 00 40 00  sethi  %hi(0x1000000), %l0
a01306ac:  d4 06 61 68  ld  [ %i1 + 0x168 ], %o2
a01306b0:  a4 28 40 10  andn  %g1, %l0, %l2
a01306b4:  27 00 40 00  sethi  %hi(0x1000000), %l3
a01306b8:  9e 14 80 13  or  %l2, %l3, %o7
a01306bc:  a9 32 a0 1c  srl  %o2, 0x1c, %l4
a01306c0:  80 a5 20 00  cmp  %l4, 0
a01306c4:  02 80 00 2b  be  0xa0130770
a01306c8:  de 22 e0 70  st  %o7, [ %o3 + 0x70 ]
a01306cc:  a5 32 a0 0c  srl  %o2, 0xc, %l2
a01306d0:  96 0c a0 0f  and  %l2, 0xf, %o3
a01306d4:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a01306d8:  a0 13 e2 24  or  %o7, 0x224, %l0	! 0xa802e224
a01306dc:  a8 5a e0 2a  smul  %o3, 0x2a, %l4
a01306e0:  98 05 00 10  add  %l4, %l0, %o4
a01306e4:  d4 0b 20 02  ldub  [ %o4 + 2 ], %o2
a01306e8:  80 a2 a0 01  cmp  %o2, 1
a01306ec:  12 80 00 03  bne  0xa01306f8
a01306f0:  a6 10 20 02  mov  2, %l3
a01306f4:  e6 2b 20 02  stb  %l3, [ %o4 + 2 ]
a01306f8:  40 00 45 7a  call  0xa0141ce0
a01306fc:  d0 0b 20 0a  ldub  [ %o4 + 0xa ], %o0
a0130700:  82 0a 20 ff  and  %o0, 0xff, %g1
a0130704:  80 a0 60 01  cmp  %g1, 1
a0130708:  22 80 02 6e  be,a   0xa01310c0
a013070c:  d0 06 61 68  ld  [ %i1 + 0x168 ], %o0
a0130710:  e0 06 61 68  ld  [ %i1 + 0x168 ], %l0
a0130714:  b3 34 20 04  srl  %l0, 4, %i1
a0130718:  90 0e 60 0f  and  %i1, 0xf, %o0
a013071c:  80 a2 20 04  cmp  %o0, 4
a0130720:  02 80 00 04  be  0xa0130730
a0130724:  01 00 00 00  nop
a0130728:  7f ff 18 2a  call  0xa00f67d0
a013072c:  01 00 00 00  nop
a0130730:  40 00 31 9e  call  0xa013cda8
a0130734:  90 10 20 03  mov  3, %o0	! 0x3
a0130738:  90 0a 20 ff  and  %o0, 0xff, %o0
a013073c:  7f ff 63 4e  call  0xa0109474
a0130740:  92 10 20 00  clr  %o1
a0130744:  a8 16 23 d0  or  %i0, 0x3d0, %l4
a0130748:  d4 0d 20 2a  ldub  [ %l4 + 0x2a ], %o2
a013074c:  80 a2 a0 01  cmp  %o2, 1
a0130750:  02 80 00 38  be  0xa0130830
a0130754:  94 16 23 d0  or  %i0, 0x3d0, %o2
a0130758:  f0 0a a0 2c  ldub  [ %o2 + 0x2c ], %i0
a013075c:  80 a6 20 01  cmp  %i0, 1
a0130760:  12 80 02 cd  bne  0xa0131294
a0130764:  19 2a 00 b7  sethi  %hi(0xa802dc00), %o4
a0130768:  10 80 00 09  b  0xa013078c
a013076c:  b2 13 23 30  or  %o4, 0x330, %i1	! 0xa802df30
a0130770:  11 3c 00 00  sethi  %hi(0xf0000000), %o0
a0130774:  98 2a 80 08  andn  %o2, %o0, %o4
a0130778:  23 14 00 00  sethi  %hi(0x50000000), %l1
a013077c:  92 13 00 11  or  %o4, %l1, %o1
a0130780:  d2 26 61 68  st  %o1, [ %i1 + 0x168 ]
a0130784:  10 bf ff d2  b  0xa01306cc
a0130788:  94 10 00 09  mov  %o1, %o2
a013078c:  96 06 61 68  add  %i1, 0x168, %o3
a0130790:  d2 02 e0 70  ld  [ %o3 + 0x70 ], %o1
a0130794:  03 00 40 00  sethi  %hi(0x1000000), %g1
a0130798:  d4 06 61 68  ld  [ %i1 + 0x168 ], %o2
a013079c:  a6 2a 40 01  andn  %o1, %g1, %l3
a01307a0:  1b 00 40 00  sethi  %hi(0x1000000), %o5
a01307a4:  a4 14 c0 0d  or  %l3, %o5, %l2
a01307a8:  9f 32 a0 1c  srl  %o2, 0x1c, %o7
a01307ac:  80 a3 e0 00  cmp  %o7, 0
a01307b0:  02 80 00 54  be  0xa0130900
a01307b4:  e4 22 e0 70  st  %l2, [ %o3 + 0x70 ]
a01307b8:  a5 32 a0 0c  srl  %o2, 0xc, %l2
a01307bc:  9e 0c a0 0f  and  %l2, 0xf, %o7
a01307c0:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a01307c4:  a0 12 e2 24  or  %o3, 0x224, %l0	! 0xa802e224
a01307c8:  94 5b e0 2a  smul  %o7, 0x2a, %o2
a01307cc:  98 02 80 10  add  %o2, %l0, %o4
a01307d0:  f0 0b 20 02  ldub  [ %o4 + 2 ], %i0
a01307d4:  80 a6 20 01  cmp  %i0, 1
a01307d8:  12 80 00 03  bne  0xa01307e4
a01307dc:  a6 10 20 02  mov  2, %l3
a01307e0:  e6 2b 20 02  stb  %l3, [ %o4 + 2 ]
a01307e4:  40 00 45 3f  call  0xa0141ce0
a01307e8:  d0 0b 20 0a  ldub  [ %o4 + 0xa ], %o0
a01307ec:  9a 0a 20 ff  and  %o0, 0xff, %o5
a01307f0:  80 a3 60 01  cmp  %o5, 1
a01307f4:  22 80 02 45  be,a   0xa0131108
a01307f8:  d0 06 61 68  ld  [ %i1 + 0x168 ], %o0
a01307fc:  e8 06 61 68  ld  [ %i1 + 0x168 ], %l4
a0130800:  b3 35 20 04  srl  %l4, 4, %i1
a0130804:  90 0e 60 0f  and  %i1, 0xf, %o0
a0130808:  80 a2 20 04  cmp  %o0, 4
a013080c:  02 80 00 04  be  0xa013081c
a0130810:  01 00 00 00  nop
a0130814:  7f ff 17 ef  call  0xa00f67d0
a0130818:  01 00 00 00  nop
a013081c:  40 00 31 63  call  0xa013cda8
a0130820:  90 10 20 03  mov  3, %o0	! 0x3
a0130824:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0130828:  7f ff 63 13  call  0xa0109474
a013082c:  93 e8 20 00  restore  %g0, 0, %o1
a0130830:  19 2a 00 b7  sethi  %hi(0xa802dc00), %o4
a0130834:  b2 13 23 30  or  %o4, 0x330, %i1	! 0xa802df30
a0130838:  96 06 60 f0  add  %i1, 0xf0, %o3
a013083c:  d2 02 e0 70  ld  [ %o3 + 0x70 ], %o1
a0130840:  03 00 40 00  sethi  %hi(0x1000000), %g1
a0130844:  d4 06 60 f0  ld  [ %i1 + 0xf0 ], %o2
a0130848:  a6 2a 40 01  andn  %o1, %g1, %l3
a013084c:  1b 00 40 00  sethi  %hi(0x1000000), %o5
a0130850:  a4 14 c0 0d  or  %l3, %o5, %l2
a0130854:  9f 32 a0 1c  srl  %o2, 0x1c, %o7
a0130858:  80 a3 e0 00  cmp  %o7, 0
a013085c:  02 80 00 22  be  0xa01308e4
a0130860:  e4 22 e0 70  st  %l2, [ %o3 + 0x70 ]
a0130864:  a7 32 a0 0c  srl  %o2, 0xc, %l3
a0130868:  96 0c e0 0f  and  %l3, 0xf, %o3
a013086c:  25 2a 00 b8  sethi  %hi(0xa802e000), %l2
a0130870:  a0 14 a2 24  or  %l2, 0x224, %l0	! 0xa802e224
a0130874:  9e 5a e0 2a  smul  %o3, 0x2a, %o7
a0130878:  98 03 c0 10  add  %o7, %l0, %o4
a013087c:  d4 0b 20 02  ldub  [ %o4 + 2 ], %o2
a0130880:  80 a2 a0 01  cmp  %o2, 1
a0130884:  12 80 00 03  bne  0xa0130890
a0130888:  9a 10 20 02  mov  2, %o5
a013088c:  da 2b 20 02  stb  %o5, [ %o4 + 2 ]
a0130890:  40 00 45 14  call  0xa0141ce0
a0130894:  d0 0b 20 0a  ldub  [ %o4 + 0xa ], %o0
a0130898:  82 0a 20 ff  and  %o0, 0xff, %g1
a013089c:  80 a0 60 01  cmp  %g1, 1
a01308a0:  22 80 02 11  be,a   0xa01310e4
a01308a4:  e8 06 60 f0  ld  [ %i1 + 0xf0 ], %l4
a01308a8:  e0 06 60 f0  ld  [ %i1 + 0xf0 ], %l0
a01308ac:  b3 34 20 04  srl  %l0, 4, %i1
a01308b0:  90 0e 60 0f  and  %i1, 0xf, %o0
a01308b4:  80 a2 20 04  cmp  %o0, 4
a01308b8:  02 80 00 04  be  0xa01308c8
a01308bc:  01 00 00 00  nop
a01308c0:  7f ff 17 c4  call  0xa00f67d0
a01308c4:  01 00 00 00  nop
a01308c8:  40 00 31 38  call  0xa013cda8
a01308cc:  90 10 20 02  mov  2, %o0	! 0x2
a01308d0:  90 0a 20 ff  and  %o0, 0xff, %o0
a01308d4:  7f ff 62 e8  call  0xa0109474
a01308d8:  92 10 20 00  clr  %o1
a01308dc:  10 bf ff 9f  b  0xa0130758
a01308e0:  94 16 23 d0  or  %i0, 0x3d0, %o2
a01308e4:  29 3c 00 00  sethi  %hi(0xf0000000), %l4
a01308e8:  90 2a 80 14  andn  %o2, %l4, %o0
a01308ec:  21 14 00 00  sethi  %hi(0x50000000), %l0
a01308f0:  a2 12 00 10  or  %o0, %l0, %l1
a01308f4:  e2 26 60 f0  st  %l1, [ %i1 + 0xf0 ]
a01308f8:  10 bf ff db  b  0xa0130864
a01308fc:  94 10 00 11  mov  %l1, %o2
a0130900:  21 3c 00 00  sethi  %hi(0xf0000000), %l0
a0130904:  90 2a 80 10  andn  %o2, %l0, %o0
a0130908:  29 14 00 00  sethi  %hi(0x50000000), %l4
a013090c:  a2 12 00 14  or  %o0, %l4, %l1
a0130910:  e2 26 61 68  st  %l1, [ %i1 + 0x168 ]
a0130914:  10 bf ff a9  b  0xa01307b8
a0130918:  94 10 00 11  mov  %l1, %o2
a013091c:  33 2a 00 b7  sethi  %hi(0xa802dc00), %i1
a0130920:  a0 16 63 30  or  %i1, 0x330, %l0	! 0xa802df30
a0130924:  17 3f bf ff  sethi  %hi(0xfefffc00), %o3
a0130928:  e4 04 20 70  ld  [ %l0 + 0x70 ], %l2
a013092c:  a2 12 e3 ff  or  %o3, 0x3ff, %l1
a0130930:  a6 0c 80 11  and  %l2, %l1, %l3
a0130934:  d8 06 63 30  ld  [ %i1 + 0x330 ], %o4
a0130938:  25 00 40 00  sethi  %hi(0x1000000), %l2
a013093c:  9e 14 c0 12  or  %l3, %l2, %o7
a0130940:  b1 33 20 1c  srl  %o4, 0x1c, %i0
a0130944:  80 a6 20 00  cmp  %i0, 0
a0130948:  12 80 00 08  bne  0xa0130968
a013094c:  de 24 20 70  st  %o7, [ %l0 + 0x70 ]
a0130950:  11 3c 00 00  sethi  %hi(0xf0000000), %o0
a0130954:  82 2b 00 08  andn  %o4, %o0, %g1
a0130958:  19 14 00 00  sethi  %hi(0x50000000), %o4
a013095c:  a8 10 40 0c  or  %g1, %o4, %l4
a0130960:  e8 26 63 30  st  %l4, [ %i1 + 0x330 ]
a0130964:  98 10 00 14  mov  %l4, %o4
a0130968:  b1 33 20 0c  srl  %o4, 0xc, %i0
a013096c:  94 0e 20 0f  and  %i0, 0xf, %o2
a0130970:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a0130974:  b0 13 e2 24  or  %o7, 0x224, %i0	! 0xa802e224
a0130978:  92 5a a0 2a  smul  %o2, 0x2a, %o1
a013097c:  98 02 40 18  add  %o1, %i0, %o4
a0130980:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a0130984:  80 a3 60 01  cmp  %o5, 1
a0130988:  12 80 00 03  bne  0xa0130994
a013098c:  a6 10 20 02  mov  2, %l3
a0130990:  e6 2b 20 02  stb  %l3, [ %o4 + 2 ]
a0130994:  40 00 44 d3  call  0xa0141ce0
a0130998:  d0 0b 20 0a  ldub  [ %o4 + 0xa ], %o0
a013099c:  96 0a 20 ff  and  %o0, 0xff, %o3
a01309a0:  80 a2 e0 01  cmp  %o3, 1
a01309a4:  02 80 02 0f  be  0xa01311e0
a01309a8:  da 06 63 30  ld  [ %i1 + 0x330 ], %o5
a01309ac:  d2 06 63 30  ld  [ %i1 + 0x330 ], %o1
a01309b0:  b3 32 60 04  srl  %o1, 4, %i1
a01309b4:  90 0e 60 0f  and  %i1, 0xf, %o0
a01309b8:  80 a2 20 04  cmp  %o0, 4
a01309bc:  02 80 00 04  be  0xa01309cc
a01309c0:  01 00 00 00  nop
a01309c4:  7f ff 17 83  call  0xa00f67d0
a01309c8:  01 00 00 00  nop
a01309cc:  40 00 30 f7  call  0xa013cda8
a01309d0:  90 10 20 00  clr  %o0	! 0x0
a01309d4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01309d8:  7f ff 62 a7  call  0xa0109474
a01309dc:  92 10 20 00  clr  %o1
a01309e0:  94 04 20 78  add  %l0, 0x78, %o2
a01309e4:  d6 02 a0 70  ld  [ %o2 + 0x70 ], %o3
a01309e8:  a6 0a c0 11  and  %o3, %l1, %l3
a01309ec:  d6 04 20 78  ld  [ %l0 + 0x78 ], %o3
a01309f0:  9e 14 c0 12  or  %l3, %l2, %o7
a01309f4:  a5 32 e0 1c  srl  %o3, 0x1c, %l2
a01309f8:  80 a4 a0 00  cmp  %l2, 0
a01309fc:  12 80 00 08  bne  0xa0130a1c
a0130a00:  de 22 a0 70  st  %o7, [ %o2 + 0x70 ]
a0130a04:  11 3c 00 00  sethi  %hi(0xf0000000), %o0
a0130a08:  82 2a c0 08  andn  %o3, %o0, %g1
a0130a0c:  19 14 00 00  sethi  %hi(0x50000000), %o4
a0130a10:  a8 10 40 0c  or  %g1, %o4, %l4
a0130a14:  e8 24 20 78  st  %l4, [ %l0 + 0x78 ]
a0130a18:  96 10 00 14  mov  %l4, %o3
a0130a1c:  a5 32 e0 0c  srl  %o3, 0xc, %l2
a0130a20:  92 0c a0 0f  and  %l2, 0xf, %o1
a0130a24:  b2 5a 60 2a  smul  %o1, 0x2a, %i1
a0130a28:  98 06 40 18  add  %i1, %i0, %o4
a0130a2c:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a0130a30:  80 a3 60 01  cmp  %o5, 1
a0130a34:  12 80 00 03  bne  0xa0130a40
a0130a38:  94 10 20 02  mov  2, %o2
a0130a3c:  d4 2b 20 02  stb  %o2, [ %o4 + 2 ]
a0130a40:  40 00 44 a8  call  0xa0141ce0
a0130a44:  d0 0b 20 0a  ldub  [ %o4 + 0xa ], %o0
a0130a48:  9e 0a 20 ff  and  %o0, 0xff, %o7
a0130a4c:  80 a3 e0 01  cmp  %o7, 1
a0130a50:  22 80 01 db  be,a   0xa01311bc
a0130a54:  d8 04 20 78  ld  [ %l0 + 0x78 ], %o4
a0130a58:  d0 04 20 78  ld  [ %l0 + 0x78 ], %o0
a0130a5c:  9b 32 20 04  srl  %o0, 4, %o5
a0130a60:  90 0b 60 0f  and  %o5, 0xf, %o0
a0130a64:  80 a2 20 04  cmp  %o0, 4
a0130a68:  02 80 00 04  be  0xa0130a78
a0130a6c:  01 00 00 00  nop
a0130a70:  7f ff 17 58  call  0xa00f67d0
a0130a74:  01 00 00 00  nop
a0130a78:  40 00 30 cc  call  0xa013cda8
a0130a7c:  90 10 20 01  mov  1, %o0	! 0x1
a0130a80:  92 10 20 00  clr  %o1
a0130a84:  7f ff 62 7c  call  0xa0109474
a0130a88:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130a8c:  d8 04 20 f0  ld  [ %l0 + 0xf0 ], %o4
a0130a90:  94 04 20 f0  add  %l0, 0xf0, %o2
a0130a94:  83 33 20 0c  srl  %o4, 0xc, %g1
a0130a98:  d6 02 a0 70  ld  [ %o2 + 0x70 ], %o3
a0130a9c:  a8 08 60 0f  and  %g1, 0xf, %l4
a0130aa0:  9e 0a c0 11  and  %o3, %l1, %o7
a0130aa4:  a6 5d 20 2a  smul  %l4, 0x2a, %l3
a0130aa8:  de 22 a0 70  st  %o7, [ %o2 + 0x70 ]
a0130aac:  a4 04 c0 18  add  %l3, %i0, %l2
a0130ab0:  40 00 44 8c  call  0xa0141ce0
a0130ab4:  d0 0c a0 0a  ldub  [ %l2 + 0xa ], %o0
a0130ab8:  d2 04 20 f0  ld  [ %l0 + 0xf0 ], %o1
a0130abc:  b3 32 60 04  srl  %o1, 4, %i1
a0130ac0:  90 0e 60 0f  and  %i1, 0xf, %o0
a0130ac4:  80 a2 20 04  cmp  %o0, 4
a0130ac8:  02 80 00 05  be  0xa0130adc
a0130acc:  19 03 ff ff  sethi  %hi(0xffffc00), %o4
a0130ad0:  7f ff 17 40  call  0xa00f67d0
a0130ad4:  01 00 00 00  nop
a0130ad8:  19 03 ff ff  sethi  %hi(0xffffc00), %o4
a0130adc:  c2 04 20 f0  ld  [ %l0 + 0xf0 ], %g1
a0130ae0:  b2 13 23 ff  or  %o4, 0x3ff, %i1
a0130ae4:  a8 08 40 19  and  %g1, %i1, %l4
a0130ae8:  e8 24 20 f0  st  %l4, [ %l0 + 0xf0 ]
a0130aec:  40 00 30 af  call  0xa013cda8
a0130af0:  90 10 20 02  mov  2, %o0
a0130af4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130af8:  7f ff 62 5f  call  0xa0109474
a0130afc:  92 10 20 00  clr  %o1
a0130b00:  d6 04 21 68  ld  [ %l0 + 0x168 ], %o3
a0130b04:  90 04 21 68  add  %l0, 0x168, %o0
a0130b08:  a7 32 e0 0c  srl  %o3, 0xc, %l3
a0130b0c:  d4 02 20 70  ld  [ %o0 + 0x70 ], %o2
a0130b10:  9e 0c e0 0f  and  %l3, 0xf, %o7
a0130b14:  9a 0a 80 11  and  %o2, %l1, %o5
a0130b18:  a4 5b e0 2a  smul  %o7, 0x2a, %l2
a0130b1c:  92 04 80 18  add  %l2, %i0, %o1
a0130b20:  da 22 20 70  st  %o5, [ %o0 + 0x70 ]
a0130b24:  40 00 44 6f  call  0xa0141ce0
a0130b28:  d0 0a 60 0a  ldub  [ %o1 + 0xa ], %o0
a0130b2c:  f0 04 21 68  ld  [ %l0 + 0x168 ], %i0
a0130b30:  a3 36 20 04  srl  %i0, 4, %l1
a0130b34:  90 0c 60 0f  and  %l1, 0xf, %o0
a0130b38:  80 a2 20 04  cmp  %o0, 4
a0130b3c:  22 80 00 05  be,a   0xa0130b50
a0130b40:  e2 04 21 68  ld  [ %l0 + 0x168 ], %l1
a0130b44:  7f ff 17 23  call  0xa00f67d0
a0130b48:  01 00 00 00  nop
a0130b4c:  e2 04 21 68  ld  [ %l0 + 0x168 ], %l1
a0130b50:  82 0c 40 19  and  %l1, %i1, %g1
a0130b54:  10 bf fe c6  b  0xa013066c
a0130b58:  c2 24 21 68  st  %g1, [ %l0 + 0x168 ]
a0130b5c:  33 2a 00 b7  sethi  %hi(0xa802dc00), %i1
a0130b60:  a0 16 63 30  or  %i1, 0x330, %l0	! 0xa802df30
a0130b64:  15 3f bf ff  sethi  %hi(0xfefffc00), %o2
a0130b68:  da 04 20 70  ld  [ %l0 + 0x70 ], %o5
a0130b6c:  a4 12 a3 ff  or  %o2, 0x3ff, %l2
a0130b70:  d8 06 63 30  ld  [ %i1 + 0x330 ], %o4
a0130b74:  90 0b 40 12  and  %o5, %l2, %o0
a0130b78:  23 00 40 00  sethi  %hi(0x1000000), %l1
a0130b7c:  92 12 00 11  or  %o0, %l1, %o1
a0130b80:  b1 33 20 1c  srl  %o4, 0x1c, %i0
a0130b84:  80 a6 20 00  cmp  %i0, 0
a0130b88:  12 80 00 08  bne  0xa0130ba8
a0130b8c:  d2 24 20 70  st  %o1, [ %l0 + 0x70 ]
a0130b90:  29 3c 00 00  sethi  %hi(0xf0000000), %l4
a0130b94:  a6 2b 00 14  andn  %o4, %l4, %l3
a0130b98:  17 14 00 00  sethi  %hi(0x50000000), %o3
a0130b9c:  9e 14 c0 0b  or  %l3, %o3, %o7
a0130ba0:  de 26 63 30  st  %o7, [ %i1 + 0x330 ]
a0130ba4:  98 10 00 0f  mov  %o7, %o4
a0130ba8:  b1 33 20 0c  srl  %o4, 0xc, %i0
a0130bac:  98 0e 20 0f  and  %i0, 0xf, %o4
a0130bb0:  27 2a 00 b8  sethi  %hi(0xa802e000), %l3
a0130bb4:  92 5b 20 2a  smul  %o4, 0x2a, %o1
a0130bb8:  b0 14 e2 24  or  %l3, 0x224, %i0
a0130bbc:  98 02 40 18  add  %o1, %i0, %o4
a0130bc0:  c2 0b 20 02  ldub  [ %o4 + 2 ], %g1
a0130bc4:  80 a0 60 01  cmp  %g1, 1
a0130bc8:  12 80 00 03  bne  0xa0130bd4
a0130bcc:  90 10 20 02  mov  2, %o0
a0130bd0:  d0 2b 20 02  stb  %o0, [ %o4 + 2 ]
a0130bd4:  40 00 44 43  call  0xa0141ce0
a0130bd8:  d0 0b 20 0a  ldub  [ %o4 + 0xa ], %o0
a0130bdc:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0130be0:  80 a3 60 01  cmp  %o5, 1
a0130be4:  02 80 01 a3  be  0xa0131270
a0130be8:  c2 06 63 30  ld  [ %i1 + 0x330 ], %g1
a0130bec:  d2 06 63 30  ld  [ %i1 + 0x330 ], %o1
a0130bf0:  b3 32 60 04  srl  %o1, 4, %i1
a0130bf4:  90 0e 60 0f  and  %i1, 0xf, %o0
a0130bf8:  80 a2 20 04  cmp  %o0, 4
a0130bfc:  02 80 00 04  be  0xa0130c0c
a0130c00:  01 00 00 00  nop
a0130c04:  7f ff 16 f3  call  0xa00f67d0
a0130c08:  01 00 00 00  nop
a0130c0c:  40 00 30 67  call  0xa013cda8
a0130c10:  90 10 20 00  clr  %o0	! 0x0
a0130c14:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130c18:  7f ff 62 17  call  0xa0109474
a0130c1c:  92 10 20 00  clr  %o1
a0130c20:  90 04 20 78  add  %l0, 0x78, %o0
a0130c24:  de 02 20 70  ld  [ %o0 + 0x70 ], %o7
a0130c28:  d6 04 20 78  ld  [ %l0 + 0x78 ], %o3
a0130c2c:  94 0b c0 12  and  %o7, %l2, %o2
a0130c30:  9a 12 80 11  or  %o2, %l1, %o5
a0130c34:  99 32 e0 1c  srl  %o3, 0x1c, %o4
a0130c38:  80 a3 20 00  cmp  %o4, 0
a0130c3c:  12 80 00 08  bne  0xa0130c5c
a0130c40:  da 22 20 70  st  %o5, [ %o0 + 0x70 ]
a0130c44:  33 3c 00 00  sethi  %hi(0xf0000000), %i1
a0130c48:  82 2a c0 19  andn  %o3, %i1, %g1
a0130c4c:  17 14 00 00  sethi  %hi(0x50000000), %o3
a0130c50:  a8 10 40 0b  or  %g1, %o3, %l4
a0130c54:  e8 24 20 78  st  %l4, [ %l0 + 0x78 ]
a0130c58:  96 10 00 14  mov  %l4, %o3
a0130c5c:  9b 32 e0 0c  srl  %o3, 0xc, %o5
a0130c60:  98 0b 60 0f  and  %o5, 0xf, %o4
a0130c64:  90 5b 20 2a  smul  %o4, 0x2a, %o0
a0130c68:  98 02 00 18  add  %o0, %i0, %o4
a0130c6c:  d2 0b 20 02  ldub  [ %o4 + 2 ], %o1
a0130c70:  80 a2 60 01  cmp  %o1, 1
a0130c74:  12 80 00 03  bne  0xa0130c80
a0130c78:  94 10 20 02  mov  2, %o2
a0130c7c:  d4 2b 20 02  stb  %o2, [ %o4 + 2 ]
a0130c80:  40 00 44 18  call  0xa0141ce0
a0130c84:  d0 0b 20 0a  ldub  [ %o4 + 0xa ], %o0
a0130c88:  9e 0a 20 ff  and  %o0, 0xff, %o7
a0130c8c:  80 a3 e0 01  cmp  %o7, 1
a0130c90:  22 80 01 6f  be,a   0xa013124c
a0130c94:  d2 04 20 78  ld  [ %l0 + 0x78 ], %o1
a0130c98:  d0 04 20 78  ld  [ %l0 + 0x78 ], %o0
a0130c9c:  99 32 20 04  srl  %o0, 4, %o4
a0130ca0:  90 0b 20 0f  and  %o4, 0xf, %o0
a0130ca4:  80 a2 20 04  cmp  %o0, 4
a0130ca8:  02 80 00 04  be  0xa0130cb8
a0130cac:  01 00 00 00  nop
a0130cb0:  7f ff 16 c8  call  0xa00f67d0
a0130cb4:  01 00 00 00  nop
a0130cb8:  40 00 30 3c  call  0xa013cda8
a0130cbc:  90 10 20 01  mov  1, %o0	! 0x1
a0130cc0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130cc4:  7f ff 61 ec  call  0xa0109474
a0130cc8:  92 10 20 00  clr  %o1
a0130ccc:  94 04 20 f0  add  %l0, 0xf0, %o2
a0130cd0:  e8 02 a0 70  ld  [ %o2 + 0x70 ], %l4
a0130cd4:  9e 0d 00 12  and  %l4, %l2, %o7
a0130cd8:  d6 04 20 f0  ld  [ %l0 + 0xf0 ], %o3
a0130cdc:  9a 13 c0 11  or  %o7, %l1, %o5
a0130ce0:  a3 32 e0 1c  srl  %o3, 0x1c, %l1
a0130ce4:  80 a4 60 00  cmp  %l1, 0
a0130ce8:  12 80 00 08  bne  0xa0130d08
a0130cec:  da 22 a0 70  st  %o5, [ %o2 + 0x70 ]
a0130cf0:  13 3c 00 00  sethi  %hi(0xf0000000), %o1
a0130cf4:  b2 2a c0 09  andn  %o3, %o1, %i1
a0130cf8:  17 14 00 00  sethi  %hi(0x50000000), %o3
a0130cfc:  82 16 40 0b  or  %i1, %o3, %g1
a0130d00:  c2 24 20 f0  st  %g1, [ %l0 + 0xf0 ]
a0130d04:  96 10 00 01  mov  %g1, %o3
a0130d08:  95 32 e0 0c  srl  %o3, 0xc, %o2
a0130d0c:  98 0a a0 0f  and  %o2, 0xf, %o4
a0130d10:  a2 5b 20 2a  smul  %o4, 0x2a, %l1
a0130d14:  98 04 40 18  add  %l1, %i0, %o4
a0130d18:  d0 0b 20 02  ldub  [ %o4 + 2 ], %o0
a0130d1c:  80 a2 20 01  cmp  %o0, 1
a0130d20:  32 80 00 05  bne,a   0xa0130d34
a0130d24:  d2 04 20 f0  ld  [ %l0 + 0xf0 ], %o1
a0130d28:  9a 10 20 02  mov  2, %o5
a0130d2c:  da 2b 20 02  stb  %o5, [ %o4 + 2 ]
a0130d30:  d2 04 20 f0  ld  [ %l0 + 0xf0 ], %o1
a0130d34:  97 32 60 0c  srl  %o1, 0xc, %o3
a0130d38:  b2 0a e0 0f  and  %o3, 0xf, %i1
a0130d3c:  82 5e 60 2a  smul  %i1, 0x2a, %g1
a0130d40:  a8 00 40 18  add  %g1, %i0, %l4
a0130d44:  40 00 43 e7  call  0xa0141ce0
a0130d48:  d0 0d 20 0a  ldub  [ %l4 + 0xa ], %o0
a0130d4c:  9e 0a 20 ff  and  %o0, 0xff, %o7
a0130d50:  80 a3 e0 01  cmp  %o7, 1
a0130d54:  22 80 01 35  be,a   0xa0131228
a0130d58:  da 04 20 f0  ld  [ %l0 + 0xf0 ], %o5
a0130d5c:  de 04 20 f0  ld  [ %l0 + 0xf0 ], %o7
a0130d60:  b1 33 e0 04  srl  %o7, 4, %i0
a0130d64:  90 0e 20 0f  and  %i0, 0xf, %o0
a0130d68:  80 a2 20 04  cmp  %o0, 4
a0130d6c:  02 80 00 04  be  0xa0130d7c
a0130d70:  01 00 00 00  nop
a0130d74:  7f ff 16 97  call  0xa00f67d0
a0130d78:  01 00 00 00  nop
a0130d7c:  40 00 30 0b  call  0xa013cda8
a0130d80:  90 10 20 02  mov  2, %o0	! 0x2
a0130d84:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130d88:  7f ff 61 bb  call  0xa0109474
a0130d8c:  92 10 20 00  clr  %o1
a0130d90:  d4 04 21 68  ld  [ %l0 + 0x168 ], %o2
a0130d94:  99 32 a0 0c  srl  %o2, 0xc, %o4
a0130d98:  b2 04 21 68  add  %l0, 0x168, %i1
a0130d9c:  90 0b 20 0f  and  %o4, 0xf, %o0
a0130da0:  e2 06 60 70  ld  [ %i1 + 0x70 ], %l1
a0130da4:  82 5a 20 2a  smul  %o0, 0x2a, %g1
a0130da8:  92 14 e2 24  or  %l3, 0x224, %o1
a0130dac:  96 0c 40 12  and  %l1, %l2, %o3
a0130db0:  a8 00 40 09  add  %g1, %o1, %l4
a0130db4:  d6 26 60 70  st  %o3, [ %i1 + 0x70 ]
a0130db8:  40 00 43 ca  call  0xa0141ce0
a0130dbc:  d0 0d 20 0a  ldub  [ %l4 + 0xa ], %o0
a0130dc0:  e6 04 21 68  ld  [ %l0 + 0x168 ], %l3
a0130dc4:  a5 34 e0 04  srl  %l3, 4, %l2
a0130dc8:  90 0c a0 0f  and  %l2, 0xf, %o0
a0130dcc:  80 a2 20 04  cmp  %o0, 4
a0130dd0:  22 80 00 05  be,a   0xa0130de4
a0130dd4:  da 04 21 68  ld  [ %l0 + 0x168 ], %o5
a0130dd8:  7f ff 16 7e  call  0xa00f67d0
a0130ddc:  01 00 00 00  nop
a0130de0:  da 04 21 68  ld  [ %l0 + 0x168 ], %o5
a0130de4:  31 3c 00 00  sethi  %hi(0xf0000000), %i0
a0130de8:  82 2b 40 18  andn  %o5, %i0, %g1
a0130dec:  10 bf fe 20  b  0xa013066c
a0130df0:  c2 24 21 68  st  %g1, [ %l0 + 0x168 ]
a0130df4:  21 2a 00 b7  sethi  %hi(0xa802dc00), %l0
a0130df8:  b2 14 23 30  or  %l0, 0x330, %i1	! 0xa802df30
a0130dfc:  03 3f bf ff  sethi  %hi(0xfefffc00), %g1
a0130e00:  d6 06 60 70  ld  [ %i1 + 0x70 ], %o3
a0130e04:  a4 10 63 ff  or  %g1, 0x3ff, %l2
a0130e08:  d8 04 23 30  ld  [ %l0 + 0x330 ], %o4
a0130e0c:  a8 0a c0 12  and  %o3, %l2, %l4
a0130e10:  23 00 40 00  sethi  %hi(0x1000000), %l1
a0130e14:  a6 15 00 11  or  %l4, %l1, %l3
a0130e18:  9f 33 20 1c  srl  %o4, 0x1c, %o7
a0130e1c:  80 a3 e0 00  cmp  %o7, 0
a0130e20:  12 80 00 08  bne  0xa0130e40
a0130e24:  e6 26 60 70  st  %l3, [ %i1 + 0x70 ]
a0130e28:  15 3c 00 00  sethi  %hi(0xf0000000), %o2
a0130e2c:  90 2b 00 0a  andn  %o4, %o2, %o0
a0130e30:  19 14 00 00  sethi  %hi(0x50000000), %o4
a0130e34:  92 12 00 0c  or  %o0, %o4, %o1
a0130e38:  d2 24 23 30  st  %o1, [ %l0 + 0x330 ]
a0130e3c:  98 10 00 09  mov  %o1, %o4
a0130e40:  a7 33 20 0c  srl  %o4, 0xc, %l3
a0130e44:  b0 0c e0 0f  and  %l3, 0xf, %i0
a0130e48:  9e 5e 20 2a  smul  %i0, 0x2a, %o7
a0130e4c:  29 2a 00 b8  sethi  %hi(0xa802e000), %l4
a0130e50:  b0 15 22 24  or  %l4, 0x224, %i0	! 0xa802e224
a0130e54:  98 03 c0 18  add  %o7, %i0, %o4
a0130e58:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a0130e5c:  80 a3 60 01  cmp  %o5, 1
a0130e60:  12 80 00 03  bne  0xa0130e6c
a0130e64:  96 10 20 02  mov  2, %o3
a0130e68:  d6 2b 20 02  stb  %o3, [ %o4 + 2 ]
a0130e6c:  40 00 43 9d  call  0xa0141ce0
a0130e70:  d0 0b 20 0a  ldub  [ %o4 + 0xa ], %o0
a0130e74:  82 0a 20 ff  and  %o0, 0xff, %g1
a0130e78:  80 a0 60 01  cmp  %g1, 1
a0130e7c:  02 80 00 e2  be  0xa0131204
a0130e80:  da 04 23 30  ld  [ %l0 + 0x330 ], %o5
a0130e84:  de 04 23 30  ld  [ %l0 + 0x330 ], %o7
a0130e88:  a1 33 e0 04  srl  %o7, 4, %l0
a0130e8c:  90 0c 20 0f  and  %l0, 0xf, %o0
a0130e90:  80 a2 20 04  cmp  %o0, 4
a0130e94:  02 80 00 04  be  0xa0130ea4
a0130e98:  01 00 00 00  nop
a0130e9c:  7f ff 16 4d  call  0xa00f67d0
a0130ea0:  01 00 00 00  nop
a0130ea4:  40 00 2f c1  call  0xa013cda8
a0130ea8:  90 10 20 00  clr  %o0	! 0x0
a0130eac:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130eb0:  7f ff 61 71  call  0xa0109474
a0130eb4:  92 10 20 00  clr  %o1
a0130eb8:  82 06 60 78  add  %i1, 0x78, %g1
a0130ebc:  d6 00 60 70  ld  [ %g1 + 0x70 ], %o3
a0130ec0:  90 0a c0 12  and  %o3, %l2, %o0
a0130ec4:  d6 06 60 78  ld  [ %i1 + 0x78 ], %o3
a0130ec8:  92 12 00 11  or  %o0, %l1, %o1
a0130ecc:  a7 32 e0 1c  srl  %o3, 0x1c, %l3
a0130ed0:  80 a4 e0 00  cmp  %l3, 0
a0130ed4:  12 80 00 08  bne  0xa0130ef4
a0130ed8:  d2 20 60 70  st  %o1, [ %g1 + 0x70 ]
a0130edc:  21 3c 00 00  sethi  %hi(0xf0000000), %l0
a0130ee0:  94 2a c0 10  andn  %o3, %l0, %o2
a0130ee4:  1b 14 00 00  sethi  %hi(0x50000000), %o5
a0130ee8:  98 12 80 0d  or  %o2, %o5, %o4
a0130eec:  d8 26 60 78  st  %o4, [ %i1 + 0x78 ]
a0130ef0:  96 10 00 0c  mov  %o4, %o3
a0130ef4:  93 32 e0 0c  srl  %o3, 0xc, %o1
a0130ef8:  82 0a 60 0f  and  %o1, 0xf, %g1
a0130efc:  a6 58 60 2a  smul  %g1, 0x2a, %l3
a0130f00:  98 04 c0 18  add  %l3, %i0, %o4
a0130f04:  de 0b 20 02  ldub  [ %o4 + 2 ], %o7
a0130f08:  80 a3 e0 01  cmp  %o7, 1
a0130f0c:  12 80 00 03  bne  0xa0130f18
a0130f10:  90 10 20 02  mov  2, %o0
a0130f14:  d0 2b 20 02  stb  %o0, [ %o4 + 2 ]
a0130f18:  40 00 43 72  call  0xa0141ce0
a0130f1c:  d0 0b 20 0a  ldub  [ %o4 + 0xa ], %o0
a0130f20:  96 0a 20 ff  and  %o0, 0xff, %o3
a0130f24:  80 a2 e0 01  cmp  %o3, 1
a0130f28:  22 80 00 8a  be,a   0xa0131150
a0130f2c:  de 06 60 78  ld  [ %i1 + 0x78 ], %o7
a0130f30:  c2 06 60 78  ld  [ %i1 + 0x78 ], %g1
a0130f34:  a7 30 60 04  srl  %g1, 4, %l3
a0130f38:  90 0c e0 0f  and  %l3, 0xf, %o0
a0130f3c:  80 a2 20 04  cmp  %o0, 4
a0130f40:  02 80 00 04  be  0xa0130f50
a0130f44:  01 00 00 00  nop
a0130f48:  7f ff 16 22  call  0xa00f67d0
a0130f4c:  01 00 00 00  nop
a0130f50:  40 00 2f 96  call  0xa013cda8
a0130f54:  90 10 20 01  mov  1, %o0	! 0x1
a0130f58:  90 0a 20 ff  and  %o0, 0xff, %o0
a0130f5c:  7f ff 61 46  call  0xa0109474
a0130f60:  92 10 20 00  clr  %o1
a0130f64:  90 06 60 f0  add  %i1, 0xf0, %o0
a0130f68:  d6 02 20 70  ld  [ %o0 + 0x70 ], %o3
a0130f6c:  94 0a c0 12  and  %o3, %l2, %o2
a0130f70:  d6 06 60 f0  ld  [ %i1 + 0xf0 ], %o3
a0130f74:  98 12 80 11  or  %o2, %l1, %o4
a0130f78:  93 32 e0 1c  srl  %o3, 0x1c, %o1
a0130f7c:  d8 22 20 70  st  %o4, [ %o0 + 0x70 ]
a0130f80:  80 a2 60 00  cmp  %o1, 0
a0130f84:  12 80 00 08  bne  0xa0130fa4
a0130f88:  a6 10 20 02  mov  2, %l3
a0130f8c:  03 3c 00 00  sethi  %hi(0xf0000000), %g1
a0130f90:  9e 2a c0 01  andn  %o3, %g1, %o7
a0130f94:  1b 14 00 00  sethi  %hi(0x50000000), %o5
a0130f98:  a0 13 c0 0d  or  %o7, %o5, %l0
a0130f9c:  e0 26 60 f0  st  %l0, [ %i1 + 0xf0 ]
a0130fa0:  96 10 00 10  mov  %l0, %o3
a0130fa4:  95 32 e0 0c  srl  %o3, 0xc, %o2
a0130fa8:  98 0a a0 0f  and  %o2, 0xf, %o4
a0130fac:  90 5b 20 2a  smul  %o4, 0x2a, %o0
a0130fb0:  82 02 00 18  add  %o0, %i0, %g1
a0130fb4:  d2 08 60 02  ldub  [ %g1 + 2 ], %o1
a0130fb8:  80 a2 60 01  cmp  %o1, 1
a0130fbc:  22 80 00 02  be,a   0xa0130fc4
a0130fc0:  e6 28 60 02  stb  %l3, [ %g1 + 2 ]
a0130fc4:  d2 06 60 f0  ld  [ %i1 + 0xf0 ], %o1
a0130fc8:  83 32 60 0c  srl  %o1, 0xc, %g1
a0130fcc:  9a 08 60 0f  and  %g1, 0xf, %o5
a0130fd0:  9e 5b 60 2a  smul  %o5, 0x2a, %o7
a0130fd4:  a0 03 c0 18  add  %o7, %i0, %l0
a0130fd8:  40 00 43 42  call  0xa0141ce0
a0130fdc:  d0 0c 20 0a  ldub  [ %l0 + 0xa ], %o0
a0130fe0:  96 0a 20 ff  and  %o0, 0xff, %o3
a0130fe4:  80 a2 e0 01  cmp  %o3, 1
a0130fe8:  22 80 00 51  be,a   0xa013112c
a0130fec:  e0 06 60 f0  ld  [ %i1 + 0xf0 ], %l0
a0130ff0:  de 06 60 f0  ld  [ %i1 + 0xf0 ], %o7
a0130ff4:  b1 33 e0 04  srl  %o7, 4, %i0
a0130ff8:  90 0e 20 0f  and  %i0, 0xf, %o0
a0130ffc:  80 a2 20 04  cmp  %o0, 4
a0131000:  02 80 00 04  be  0xa0131010
a0131004:  a0 10 00 19  mov  %i1, %l0
a0131008:  7f ff 15 f2  call  0xa00f67d0
a013100c:  01 00 00 00  nop
a0131010:  40 00 2f 66  call  0xa013cda8
a0131014:  90 10 20 02  mov  2, %o0	! 0x2
a0131018:  92 10 20 00  clr  %o1
a013101c:  7f ff 61 16  call  0xa0109474
a0131020:  90 0a 20 ff  and  %o0, 0xff, %o0
a0131024:  82 04 21 68  add  %l0, 0x168, %g1
a0131028:  d8 00 60 70  ld  [ %g1 + 0x70 ], %o4
a013102c:  92 0b 00 12  and  %o4, %l2, %o1
a0131030:  d6 04 21 68  ld  [ %l0 + 0x168 ], %o3
a0131034:  9a 12 40 11  or  %o1, %l1, %o5
a0131038:  a5 32 e0 1c  srl  %o3, 0x1c, %l2
a013103c:  80 a4 a0 00  cmp  %l2, 0
a0131040:  12 80 00 08  bne  0xa0131060
a0131044:  da 20 60 70  st  %o5, [ %g1 + 0x70 ]
a0131048:  31 3c 00 00  sethi  %hi(0xf0000000), %i0
a013104c:  90 2a c0 18  andn  %o3, %i0, %o0
a0131050:  15 14 00 00  sethi  %hi(0x50000000), %o2
a0131054:  a2 12 00 0a  or  %o0, %o2, %l1
a0131058:  e2 24 21 68  st  %l1, [ %l0 + 0x168 ]
a013105c:  96 10 00 11  mov  %l1, %o3
a0131060:  a5 32 e0 0c  srl  %o3, 0xc, %l2
a0131064:  9e 0c a0 0f  and  %l2, 0xf, %o7
a0131068:  b0 15 22 24  or  %l4, 0x224, %i0
a013106c:  96 5b e0 2a  smul  %o7, 0x2a, %o3
a0131070:  82 02 c0 18  add  %o3, %i0, %g1
a0131074:  e8 08 60 02  ldub  [ %g1 + 2 ], %l4
a0131078:  80 a5 20 01  cmp  %l4, 1
a013107c:  22 80 00 02  be,a   0xa0131084
a0131080:  e6 28 60 02  stb  %l3, [ %g1 + 2 ]
a0131084:  40 00 43 17  call  0xa0141ce0
a0131088:  d0 08 60 0a  ldub  [ %g1 + 0xa ], %o0
a013108c:  a6 0a 20 ff  and  %o0, 0xff, %l3
a0131090:  80 a4 e0 01  cmp  %l3, 1
a0131094:  22 80 00 38  be,a   0xa0131174
a0131098:  d8 04 21 68  ld  [ %l0 + 0x168 ], %o4
a013109c:  e2 06 61 68  ld  [ %i1 + 0x168 ], %l1
a01310a0:  b3 34 60 04  srl  %l1, 4, %i1
a01310a4:  90 0e 60 0f  and  %i1, 0xf, %o0
a01310a8:  80 a2 20 04  cmp  %o0, 4
a01310ac:  02 bf fd 70  be  0xa013066c
a01310b0:  01 00 00 00  nop
a01310b4:  7f ff 15 c7  call  0xa00f67d0
a01310b8:  01 00 00 00  nop
a01310bc:  30 bf fd 6c  b,a   0xa013066c
a01310c0:  a3 32 20 0c  srl  %o0, 0xc, %l1
a01310c4:  98 0c 60 0f  and  %l1, 0xf, %o4
a01310c8:  92 5b 20 2a  smul  %o4, 0x2a, %o1
a01310cc:  9a 02 40 10  add  %o1, %l0, %o5
a01310d0:  d0 0b 60 0a  ldub  [ %o5 + 0xa ], %o0
a01310d4:  40 00 43 1f  call  0xa0141d50
a01310d8:  92 10 20 02  mov  2, %o1
a01310dc:  10 bf fd 8e  b  0xa0130714
a01310e0:  e0 06 61 68  ld  [ %i1 + 0x168 ], %l0
a01310e4:  91 35 20 0c  srl  %l4, 0xc, %o0
a01310e8:  a2 0a 20 0f  and  %o0, 0xf, %l1
a01310ec:  98 5c 60 2a  smul  %l1, 0x2a, %o4
a01310f0:  92 03 00 10  add  %o4, %l0, %o1
a01310f4:  d0 0a 60 0a  ldub  [ %o1 + 0xa ], %o0
a01310f8:  40 00 43 16  call  0xa0141d50
a01310fc:  92 10 20 02  mov  2, %o1
a0131100:  10 bf fd eb  b  0xa01308ac
a0131104:  e0 06 60 f0  ld  [ %i1 + 0xf0 ], %l0
a0131108:  a3 32 20 0c  srl  %o0, 0xc, %l1
a013110c:  98 0c 60 0f  and  %l1, 0xf, %o4
a0131110:  92 5b 20 2a  smul  %o4, 0x2a, %o1
a0131114:  82 02 40 10  add  %o1, %l0, %g1
a0131118:  d0 08 60 0a  ldub  [ %g1 + 0xa ], %o0
a013111c:  40 00 43 0d  call  0xa0141d50
a0131120:  92 10 20 02  mov  2, %o1
a0131124:  10 bf fd b7  b  0xa0130800
a0131128:  e8 06 61 68  ld  [ %i1 + 0x168 ], %l4
a013112c:  97 34 20 0c  srl  %l0, 0xc, %o3
a0131130:  94 0a e0 0f  and  %o3, 0xf, %o2
a0131134:  90 5a a0 2a  smul  %o2, 0x2a, %o0
a0131138:  98 02 00 18  add  %o0, %i0, %o4
a013113c:  d0 0b 20 0a  ldub  [ %o4 + 0xa ], %o0
a0131140:  40 00 43 04  call  0xa0141d50
a0131144:  92 10 20 02  mov  2, %o1
a0131148:  10 bf ff ab  b  0xa0130ff4
a013114c:  de 06 60 f0  ld  [ %i1 + 0xf0 ], %o7
a0131150:  a1 33 e0 0c  srl  %o7, 0xc, %l0
a0131154:  9a 0c 20 0f  and  %l0, 0xf, %o5
a0131158:  94 5b 60 2a  smul  %o5, 0x2a, %o2
a013115c:  98 02 80 18  add  %o2, %i0, %o4
a0131160:  d0 0b 20 0a  ldub  [ %o4 + 0xa ], %o0
a0131164:  40 00 42 fb  call  0xa0141d50
a0131168:  92 10 20 02  mov  2, %o1
a013116c:  10 bf ff 72  b  0xa0130f34
a0131170:  c2 06 60 78  ld  [ %i1 + 0x78 ], %g1
a0131174:  93 33 20 0c  srl  %o4, 0xc, %o1
a0131178:  9a 0a 60 0f  and  %o1, 0xf, %o5
a013117c:  82 5b 60 2a  smul  %o5, 0x2a, %g1
a0131180:  a0 00 40 18  add  %g1, %i0, %l0
a0131184:  d0 0c 20 0a  ldub  [ %l0 + 0xa ], %o0
a0131188:  40 00 42 f2  call  0xa0141d50
a013118c:  92 10 20 02  mov  2, %o1
a0131190:  10 bf ff c4  b  0xa01310a0
a0131194:  e2 06 61 68  ld  [ %i1 + 0x168 ], %l1
a0131198:  91 33 60 0c  srl  %o5, 0xc, %o0
a013119c:  98 0a 20 0f  and  %o0, 0xf, %o4
a01311a0:  82 5b 20 2a  smul  %o4, 0x2a, %g1
a01311a4:  a8 00 40 18  add  %g1, %i0, %l4
a01311a8:  d0 0d 20 0a  ldub  [ %l4 + 0xa ], %o0
a01311ac:  40 00 42 e9  call  0xa0141d50
a01311b0:  92 10 20 02  mov  2, %o1
a01311b4:  10 bf fc d2  b  0xa01304fc
a01311b8:  d2 04 23 30  ld  [ %l0 + 0x330 ], %o1
a01311bc:  83 33 20 0c  srl  %o4, 0xc, %g1
a01311c0:  a8 08 60 0f  and  %g1, 0xf, %l4
a01311c4:  96 5d 20 2a  smul  %l4, 0x2a, %o3
a01311c8:  a6 02 c0 18  add  %o3, %i0, %l3
a01311cc:  d0 0c e0 0a  ldub  [ %l3 + 0xa ], %o0
a01311d0:  40 00 42 e0  call  0xa0141d50
a01311d4:  92 10 20 02  mov  2, %o1
a01311d8:  10 bf fe 21  b  0xa0130a5c
a01311dc:  d0 04 20 78  ld  [ %l0 + 0x78 ], %o0
a01311e0:  91 33 60 0c  srl  %o5, 0xc, %o0
a01311e4:  98 0a 20 0f  and  %o0, 0xf, %o4
a01311e8:  82 5b 20 2a  smul  %o4, 0x2a, %g1
a01311ec:  a8 00 40 18  add  %g1, %i0, %l4
a01311f0:  d0 0d 20 0a  ldub  [ %l4 + 0xa ], %o0
a01311f4:  40 00 42 d7  call  0xa0141d50
a01311f8:  92 10 20 02  mov  2, %o1
a01311fc:  10 bf fd ed  b  0xa01309b0
a0131200:  d2 06 63 30  ld  [ %i1 + 0x330 ], %o1
a0131204:  95 33 60 0c  srl  %o5, 0xc, %o2
a0131208:  98 0a a0 0f  and  %o2, 0xf, %o4
a013120c:  90 5b 20 2a  smul  %o4, 0x2a, %o0
a0131210:  92 02 00 18  add  %o0, %i0, %o1
a0131214:  d0 0a 60 0a  ldub  [ %o1 + 0xa ], %o0
a0131218:  40 00 42 ce  call  0xa0141d50
a013121c:  92 10 20 02  mov  2, %o1
a0131220:  10 bf ff 1a  b  0xa0130e88
a0131224:  de 04 23 30  ld  [ %l0 + 0x330 ], %o7
a0131228:  95 33 60 0c  srl  %o5, 0xc, %o2
a013122c:  98 0a a0 0f  and  %o2, 0xf, %o4
a0131230:  90 5b 20 2a  smul  %o4, 0x2a, %o0
a0131234:  a2 02 00 18  add  %o0, %i0, %l1
a0131238:  d0 0c 60 0a  ldub  [ %l1 + 0xa ], %o0
a013123c:  40 00 42 c5  call  0xa0141d50
a0131240:  92 10 20 02  mov  2, %o1
a0131244:  10 bf fe c7  b  0xa0130d60
a0131248:  de 04 20 f0  ld  [ %l0 + 0xf0 ], %o7
a013124c:  b3 32 60 0c  srl  %o1, 0xc, %i1
a0131250:  96 0e 60 0f  and  %i1, 0xf, %o3
a0131254:  82 5a e0 2a  smul  %o3, 0x2a, %g1
a0131258:  a8 00 40 18  add  %g1, %i0, %l4
a013125c:  d0 0d 20 0a  ldub  [ %l4 + 0xa ], %o0
a0131260:  40 00 42 bc  call  0xa0141d50
a0131264:  92 10 20 02  mov  2, %o1
a0131268:  10 bf fe 8d  b  0xa0130c9c
a013126c:  d0 04 20 78  ld  [ %l0 + 0x78 ], %o0
a0131270:  a9 30 60 0c  srl  %g1, 0xc, %l4
a0131274:  96 0d 20 0f  and  %l4, 0xf, %o3
a0131278:  9e 5a e0 2a  smul  %o3, 0x2a, %o7
a013127c:  94 03 c0 18  add  %o7, %i0, %o2
a0131280:  d0 0a a0 0a  ldub  [ %o2 + 0xa ], %o0
a0131284:  40 00 42 b3  call  0xa0141d50
a0131288:  92 10 20 02  mov  2, %o1
a013128c:  10 bf fe 59  b  0xa0130bf0
a0131290:  d2 06 63 30  ld  [ %i1 + 0x330 ], %o1
a0131294:  81 c7 e0 08  ret
a0131298:  81 e8 00 00  restore
