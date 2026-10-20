# leon2m FUN_a0131518 0xa0131518-0xa0132768 (4688 bytes)
a0131518:  9d e3 bf 88  save  %sp, -120, %sp
a013151c:  39 2a 00 b7  sethi  %hi(0xa802dc00), %i4
a0131520:  96 10 20 00  clr  %o3
a0131524:  98 10 20 00  clr  %o4
a0131528:  94 17 23 30  or  %i4, 0x330, %o2
a013152c:  9f 2b 20 04  sll  %o4, 4, %o7
a0131530:  92 23 c0 0c  sub  %o7, %o4, %o1
a0131534:  83 2a 60 03  sll  %o1, 3, %g1
a0131538:  d0 00 40 0a  ld  [ %g1 + %o2 ], %o0
a013153c:  96 02 e0 01  inc  %o3
a0131540:  9b 32 20 1c  srl  %o0, 0x1c, %o5
a0131544:  80 a3 60 08  cmp  %o5, 8
a0131548:  18 80 00 05  bgu  0xa013155c
a013154c:  98 0a e0 ff  and  %o3, 0xff, %o4
a0131550:  80 a3 20 03  cmp  %o4, 3
a0131554:  08 bf ff f7  bleu  0xa0131530
a0131558:  9f 2b 20 04  sll  %o4, 4, %o7
a013155c:  17 2a 00 b7  sethi  %hi(0xa802dc00), %o3
a0131560:  aa 12 e3 30  or  %o3, 0x330, %l5	! 0xa802df30
a0131564:  15 03 ff ff  sethi  %hi(0xffffc00), %o2
a0131568:  3b 2a 00 b8  sethi  %hi(0xa802e000), %i5
a013156c:  b2 12 a3 ff  or  %o2, 0x3ff, %i1
a0131570:  ae 10 20 00  clr  %l7
a0131574:  a4 10 20 00  clr  %l2
a0131578:  37 2a 00 b8  sethi  %hi(0xa802e000), %i3
a013157c:  2d 3c 00 00  sethi  %hi(0xf0000000), %l6
a0131580:  10 80 00 50  b  0xa01316c0
a0131584:  b4 10 00 15  mov  %l5, %i2
a0131588:  02 80 00 65  be  0xa013171c
a013158c:  83 2c a0 04  sll  %l2, 4, %g1
a0131590:  a7 2c a0 04  sll  %l2, 4, %l3
a0131594:  96 24 c0 12  sub  %l3, %l2, %o3
a0131598:  9f 2a e0 03  sll  %o3, 3, %o7
a013159c:  a1 33 20 18  srl  %o4, 0x18, %l0
a01315a0:  d6 03 c0 15  ld  [ %o7 + %l5 ], %o3
a01315a4:  9a 0c 20 0f  and  %l0, 0xf, %o5
a01315a8:  99 32 e0 1c  srl  %o3, 0x1c, %o4
a01315ac:  80 a3 40 0c  cmp  %o5, %o4
a01315b0:  02 80 00 8e  be  0xa01317e8
a01315b4:  a0 03 c0 15  add  %o7, %l5, %l0
a01315b8:  94 0a c0 16  and  %o3, %l6, %o2
a01315bc:  13 24 00 00  sethi  %hi(0x90000000), %o1
a01315c0:  80 a2 80 09  cmp  %o2, %o1
a01315c4:  02 80 01 cb  be  0xa0131cf0
a01315c8:  b0 17 63 d0  or  %i5, 0x3d0, %i0
a01315cc:  9b 2c a0 04  sll  %l2, 4, %o5
a01315d0:  98 23 40 12  sub  %o5, %l2, %o4
a01315d4:  a3 2b 20 03  sll  %o4, 3, %l1
a01315d8:  d0 04 40 1a  ld  [ %l1 + %i2 ], %o0
a01315dc:  9e 0a 00 16  and  %o0, %l6, %o7
a01315e0:  21 24 00 00  sethi  %hi(0x90000000), %l0
a01315e4:  80 a3 c0 10  cmp  %o7, %l0
a01315e8:  02 80 01 d8  be  0xa0131d48
a01315ec:  a6 10 00 1a  mov  %i2, %l3
a01315f0:  b1 2c a0 04  sll  %l2, 4, %i0
a01315f4:  a0 26 00 12  sub  %i0, %l2, %l0
a01315f8:  b1 2c 20 03  sll  %l0, 3, %i0
a01315fc:  c2 06 00 15  ld  [ %i0 + %l5 ], %g1
a0131600:  9f 30 60 0c  srl  %g1, 0xc, %o7
a0131604:  90 0b e0 0f  and  %o7, 0xf, %o0
a0131608:  92 5a 20 2a  smul  %o0, 0x2a, %o1
a013160c:  94 16 e2 24  or  %i3, 0x224, %o2
a0131610:  a6 02 40 0a  add  %o1, %o2, %l3
a0131614:  d6 0d 00 00  ldub  [ %l4 ], %o3
a0131618:  a2 0a e0 0f  and  %o3, 0xf, %l1
a013161c:  40 00 42 d3  call  0xa0142168
a0131620:  d0 0c e0 0a  ldub  [ %l3 + 0xa ], %o0
a0131624:  40 00 43 4f  call  0xa0142360
a0131628:  90 0a 20 ff  and  %o0, 0xff, %o0
a013162c:  a6 10 00 08  mov  %o0, %l3
a0131630:  d0 06 00 15  ld  [ %i0 + %l5 ], %o0
a0131634:  9a 0c 60 ff  and  %l1, 0xff, %o5
a0131638:  99 32 20 1c  srl  %o0, 0x1c, %o4
a013163c:  80 a3 40 0c  cmp  %o5, %o4
a0131640:  02 80 00 08  be  0xa0131660
a0131644:  a0 06 00 15  add  %i0, %l5, %l0
a0131648:  23 3c 3c 00  sethi  %hi(0xf0f00000), %l1
a013164c:  9a 0a 00 11  and  %o0, %l1, %o5
a0131650:  19 1c 00 00  sethi  %hi(0x70000000), %o4
a0131654:  80 a3 40 0c  cmp  %o5, %o4
a0131658:  02 80 02 b9  be  0xa013213c
a013165c:  93 32 20 0c  srl  %o0, 0xc, %o1
a0131660:  99 2c a0 04  sll  %l2, 4, %o4
a0131664:  82 23 00 12  sub  %o4, %l2, %g1
a0131668:  99 28 60 03  sll  %g1, 3, %o4
a013166c:  f0 0d 00 00  ldub  [ %l4 ], %i0
a0131670:  96 17 23 30  or  %i4, 0x330, %o3
a0131674:  80 a4 a0 00  cmp  %l2, 0
a0131678:  9a 0e 20 0f  and  %i0, 0xf, %o5
a013167c:  94 10 20 00  clr  %o2
a0131680:  02 80 00 ac  be  0xa0131930
a0131684:  a2 03 00 0b  add  %o4, %o3, %l1
a0131688:  da 03 00 0b  ld  [ %o4 + %o3 ], %o5
a013168c:  a4 0b 7f fe  and  %o5, -2, %l2
a0131690:  e4 23 00 0b  st  %l2, [ %o4 + %o3 ]
a0131694:  e6 05 00 00  ld  [ %l4 ], %l3
a0131698:  93 34 e0 1c  srl  %l3, 0x1c, %o1
a013169c:  17 03 c0 00  sethi  %hi(0xf000000), %o3
a01316a0:  82 2c c0 0b  andn  %l3, %o3, %g1
a01316a4:  95 2a 60 18  sll  %o1, 0x18, %o2
a01316a8:  ae 05 e0 01  inc  %l7
a01316ac:  a2 10 40 0a  or  %g1, %o2, %l1
a01316b0:  a4 0d e0 ff  and  %l7, 0xff, %l2
a01316b4:  80 a4 a0 03  cmp  %l2, 3
a01316b8:  18 80 00 fc  bgu  0xa0131aa8
a01316bc:  e2 25 00 00  st  %l1, [ %l4 ]
a01316c0:  99 2c a0 04  sll  %l2, 4, %o4
a01316c4:  a0 17 63 d0  or  %i5, 0x3d0, %l0
a01316c8:  a6 23 00 12  sub  %o4, %l2, %l3
a01316cc:  d8 0c 20 2e  ldub  [ %l0 + 0x2e ], %o4
a01316d0:  a1 2c e0 03  sll  %l3, 3, %l0
a01316d4:  a2 13 00 17  or  %o4, %l7, %l1
a01316d8:  80 8c 60 ff  btst  0xff, %l1
a01316dc:  02 80 00 62  be  0xa0131864
a01316e0:  a8 04 00 15  add  %l0, %l5, %l4
a01316e4:  80 a3 20 01  cmp  %o4, 1
a01316e8:  02 80 00 5f  be  0xa0131864
a01316ec:  17 01 00 00  sethi  %hi(0x4000000), %o3
a01316f0:  d4 05 20 70  ld  [ %l4 + 0x70 ], %o2
a01316f4:  9e 12 80 0b  or  %o2, %o3, %o7
a01316f8:  de 25 20 70  st  %o7, [ %l4 + 0x70 ]
a01316fc:  d8 04 00 15  ld  [ %l0 + %l5 ], %o4
a0131700:  a6 17 63 d0  or  %i5, 0x3d0, %l3
a0131704:  c2 0c e0 2f  ldub  [ %l3 + 0x2f ], %g1
a0131708:  a2 10 40 17  or  %g1, %l7, %l1
a013170c:  80 8c 60 ff  btst  0xff, %l1
a0131710:  12 bf ff 9e  bne  0xa0131588
a0131714:  80 a0 60 01  cmp  %g1, 1
a0131718:  83 2c a0 04  sll  %l2, 4, %g1
a013171c:  90 20 40 12  sub  %g1, %l2, %o0
a0131720:  83 2a 20 03  sll  %o0, 3, %g1
a0131724:  b1 33 20 18  srl  %o4, 0x18, %i0
a0131728:  96 17 23 30  or  %i4, 0x330, %o3
a013172c:  9a 0e 20 0f  and  %i0, 0xf, %o5
a0131730:  80 a4 a0 ff  cmp  %l2, 0xff
a0131734:  02 bf ff 97  be  0xa0131590
a0131738:  a6 00 40 0b  add  %g1, %o3, %l3
a013173c:  d6 00 40 0b  ld  [ %g1 + %o3 ], %o3
a0131740:  9a 0b 60 ff  and  %o5, 0xff, %o5
a0131744:  a1 32 e0 1c  srl  %o3, 0x1c, %l0
a0131748:  80 a3 40 10  cmp  %o5, %l0
a013174c:  02 bf ff 91  be  0xa0131590
a0131750:  80 a3 60 05  cmp  %o5, 5
a0131754:  02 80 02 0a  be  0xa0131f7c
a0131758:  9a 0a c0 16  and  %o3, %l6, %o5
a013175c:  d2 04 c0 00  ld  [ %l3 ], %o1
a0131760:  23 3c 00 00  sethi  %hi(0xf0000000), %l1
a0131764:  9e 0a 40 11  and  %o1, %l1, %o7
a0131768:  21 28 00 00  sethi  %hi(0xa0000000), %l0
a013176c:  80 a3 c0 10  cmp  %o7, %l0
a0131770:  02 80 02 10  be  0xa0131fb0
a0131774:  01 00 00 00  nop
a0131778:  9a 0a 40 16  and  %o1, %l6, %o5
a013177c:  1f 2c 00 00  sethi  %hi(0xb0000000), %o7
a0131780:  80 a3 40 0f  cmp  %o5, %o7
a0131784:  22 80 01 a1  be,a   0xa0131e08
a0131788:  d6 07 63 d0  ld  [ %i5 + 0x3d0 ], %o3
a013178c:  23 3c 00 00  sethi  %hi(0xf0000000), %l1
a0131790:  9e 0a 40 11  and  %o1, %l1, %o7
a0131794:  21 30 00 00  sethi  %hi(0xc0000000), %l0
a0131798:  80 a3 c0 10  cmp  %o7, %l0
a013179c:  02 80 01 c7  be  0xa0131eb8
a01317a0:  01 00 00 00  nop
a01317a4:  23 3c 00 00  sethi  %hi(0xf0000000), %l1
a01317a8:  9e 0a 40 11  and  %o1, %l1, %o7
a01317ac:  21 14 00 00  sethi  %hi(0x50000000), %l0
a01317b0:  80 a3 c0 10  cmp  %o7, %l0
a01317b4:  02 80 02 38  be  0xa0132094
a01317b8:  01 00 00 00  nop
a01317bc:  d8 05 00 00  ld  [ %l4 ], %o4
a01317c0:  a7 2c a0 04  sll  %l2, 4, %l3
a01317c4:  96 24 c0 12  sub  %l3, %l2, %o3
a01317c8:  9f 2a e0 03  sll  %o3, 3, %o7
a01317cc:  a1 33 20 18  srl  %o4, 0x18, %l0
a01317d0:  d6 03 c0 15  ld  [ %o7 + %l5 ], %o3
a01317d4:  9a 0c 20 0f  and  %l0, 0xf, %o5
a01317d8:  99 32 e0 1c  srl  %o3, 0x1c, %o4
a01317dc:  80 a3 40 0c  cmp  %o5, %o4
a01317e0:  12 bf ff 76  bne  0xa01315b8
a01317e4:  a0 03 c0 15  add  %o7, %l5, %l0
a01317e8:  90 0a c0 16  and  %o3, %l6, %o0
a01317ec:  15 24 00 00  sethi  %hi(0x90000000), %o2
a01317f0:  80 a2 00 0a  cmp  %o0, %o2
a01317f4:  12 bf ff 77  bne  0xa01315d0
a01317f8:  9b 2c a0 04  sll  %l2, 4, %o5
a01317fc:  a2 17 63 d0  or  %i5, 0x3d0, %l1
a0131800:  f0 0c 60 34  ldub  [ %l1 + 0x34 ], %i0
a0131804:  80 a6 20 00  cmp  %i0, 0
a0131808:  02 bf ff 73  be  0xa01315d4
a013180c:  98 23 40 12  sub  %o5, %l2, %o4
a0131810:  27 2a 00 b2  sethi  %hi(0xa802c800), %l3
a0131814:  9a 04 80 12  add  %l2, %l2, %o5
a0131818:  96 14 e3 82  or  %l3, 0x382, %o3
a013181c:  67 fd 6f 5e  call  0x4008d594
a0131820:  d0 12 c0 0d  lduh  [ %o3 + %o5 ], %o0
a0131824:  99 2a 20 10  sll  %o0, 0x10, %o4
a0131828:  9f 33 20 10  srl  %o4, 0x10, %o7
a013182c:  c2 14 60 36  lduh  [ %l1 + 0x36 ], %g1
a0131830:  80 a3 c0 01  cmp  %o7, %g1
a0131834:  08 bf ff 67  bleu  0xa01315d0
a0131838:  9b 2c a0 04  sll  %l2, 4, %o5
a013183c:  d8 0c 60 34  ldub  [ %l1 + 0x34 ], %o4
a0131840:  9a 0b 20 0f  and  %o4, 0xf, %o5
a0131844:  80 a3 60 01  cmp  %o5, 1
a0131848:  32 80 01 34  bne,a   0xa0131d18
a013184c:  f0 04 20 70  ld  [ %l0 + 0x70 ], %i0
a0131850:  90 04 a0 04  add  %l2, 4, %o0
a0131854:  95 2b 40 08  sll  %o5, %o0, %o2
a0131858:  92 2b 00 0a  andn  %o4, %o2, %o1
a013185c:  10 80 01 2e  b  0xa0131d14
a0131860:  d2 2c 60 34  stb  %o1, [ %l1 + 0x34 ]
a0131864:  d2 0c 00 15  ldub  [ %l0 + %l5 ], %o1
a0131868:  7f ff ca 65  call  0xa01241fc
a013186c:  a2 0a 60 0f  and  %o1, 0xf, %l1
a0131870:  c2 02 00 00  ld  [ %o0 ], %g1
a0131874:  1b 00 1c 00  sethi  %hi(0x700000), %o5
a0131878:  90 08 40 0d  and  %g1, %o5, %o0
a013187c:  31 00 08 00  sethi  %hi(0x200000), %i0
a0131880:  80 a2 00 18  cmp  %o0, %i0
a0131884:  02 80 01 47  be  0xa0131da0
a0131888:  da 04 00 15  ld  [ %l0 + %l5 ], %o5
a013188c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a0131890:  9f 33 60 1c  srl  %o5, 0x1c, %o7
a0131894:  80 a4 00 0f  cmp  %l0, %o7
a0131898:  02 80 00 06  be  0xa01318b0
a013189c:  96 0b 40 16  and  %o5, %l6, %o3
a01318a0:  15 28 00 00  sethi  %hi(0xa0000000), %o2
a01318a4:  80 a2 c0 0a  cmp  %o3, %o2
a01318a8:  02 80 02 9d  be  0xa013231c
a01318ac:  01 00 00 00  nop
a01318b0:  da 05 00 00  ld  [ %l4 ], %o5
a01318b4:  82 0b 40 16  and  %o5, %l6, %g1
a01318b8:  11 2c 00 00  sethi  %hi(0xb0000000), %o0
a01318bc:  80 a0 40 08  cmp  %g1, %o0
a01318c0:  02 80 02 57  be  0xa013221c
a01318c4:  01 00 00 00  nop
a01318c8:  40 00 40 74  call  0xa0141a98
a01318cc:  01 00 00 00  nop
a01318d0:  a2 0a 20 ff  and  %o0, 0xff, %l1
a01318d4:  80 a4 60 01  cmp  %l1, 1
a01318d8:  02 80 01 44  be  0xa0131de8
a01318dc:  31 01 00 00  sethi  %hi(0x4000000), %i0
a01318e0:  d0 05 20 70  ld  [ %l4 + 0x70 ], %o0
a01318e4:  82 2a 00 18  andn  %o0, %i0, %g1
a01318e8:  c2 25 20 70  st  %g1, [ %l4 + 0x70 ]
a01318ec:  d8 05 00 00  ld  [ %l4 ], %o4
a01318f0:  83 33 20 1c  srl  %o4, 0x1c, %g1
a01318f4:  80 a4 00 01  cmp  %l0, %g1
a01318f8:  02 bf ff 82  be  0xa0131700
a01318fc:  9a 0b 00 16  and  %o4, %l6, %o5
a0131900:  21 30 00 00  sethi  %hi(0xc0000000), %l0
a0131904:  80 a3 40 10  cmp  %o5, %l0
a0131908:  12 bf ff 7f  bne  0xa0131704
a013190c:  a6 17 63 d0  or  %i5, 0x3d0, %l3
a0131910:  40 00 40 62  call  0xa0141a98
a0131914:  01 00 00 00  nop
a0131918:  92 0a 20 ff  and  %o0, 0xff, %o1
a013191c:  80 a2 60 01  cmp  %o1, 1
a0131920:  02 80 01 fe  be  0xa0132118
a0131924:  01 00 00 00  nop
a0131928:  10 bf ff 77  b  0xa0131704
a013192c:  d8 05 00 00  ld  [ %l4 ], %o4
a0131930:  d8 03 00 0b  ld  [ %o4 + %o3 ], %o4
a0131934:  a0 0b 60 ff  and  %o5, 0xff, %l0
a0131938:  9f 33 20 1c  srl  %o4, 0x1c, %o7
a013193c:  80 a4 00 0f  cmp  %l0, %o7
a0131940:  02 80 00 06  be  0xa0131958
a0131944:  92 0b 00 16  and  %o4, %l6, %o1
a0131948:  17 20 00 00  sethi  %hi(0x80000000), %o3
a013194c:  80 a2 40 0b  cmp  %o1, %o3
a0131950:  22 80 01 2a  be,a   0xa0131df8
a0131954:  f0 04 60 70  ld  [ %l1 + 0x70 ], %i0
a0131958:  d6 04 40 00  ld  [ %l1 ], %o3
a013195c:  9f 32 e0 0c  srl  %o3, 0xc, %o7
a0131960:  9a 0b e0 0f  and  %o7, 0xf, %o5
a0131964:  82 5b 60 2a  smul  %o5, 0x2a, %g1
a0131968:  a4 16 e2 24  or  %i3, 0x224, %l2
a013196c:  d8 14 80 01  lduh  [ %l2 + %g1 ], %o4
a0131970:  80 8b 20 80  btst  0x80, %o4
a0131974:  12 80 00 41  bne  0xa0131a78
a0131978:  82 0a ff fe  and  %o3, -2, %g1
a013197c:  25 3c 00 00  sethi  %hi(0xf0000000), %l2
a0131980:  92 0a c0 12  and  %o3, %l2, %o1
a0131984:  21 20 00 00  sethi  %hi(0x80000000), %l0
a0131988:  80 a2 40 10  cmp  %o1, %l0
a013198c:  32 bf ff 43  bne,a   0xa0131698
a0131990:  e6 05 00 00  ld  [ %l4 ], %l3
a0131994:  d0 04 60 70  ld  [ %l1 + 0x70 ], %o0
a0131998:  27 00 02 00  sethi  %hi(0x80000), %l3
a013199c:  80 8a 00 13  btst  %o0, %l3
a01319a0:  32 bf ff 3e  bne,a   0xa0131698
a01319a4:  e6 05 00 00  ld  [ %l4 ], %l3
a01319a8:  19 00 3c 00  sethi  %hi(0xf00000), %o4
a01319ac:  82 0a c0 0c  and  %o3, %o4, %g1
a01319b0:  31 00 04 00  sethi  %hi(0x100000), %i0
a01319b4:  80 a0 40 18  cmp  %g1, %i0
a01319b8:  02 80 03 17  be  0xa0132614
a01319bc:  9a 13 20 01  or  %o4, 1, %o5
a01319c0:  25 00 14 00  sethi  %hi(0x500000), %l2
a01319c4:  98 0a c0 0d  and  %o3, %o5, %o4
a01319c8:  b0 14 a0 01  or  %l2, 1, %i0
a01319cc:  80 a3 00 18  cmp  %o4, %i0
a01319d0:  32 bf ff 32  bne,a   0xa0131698
a01319d4:  e6 05 00 00  ld  [ %l4 ], %l3
a01319d8:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a01319dc:  96 12 63 78  or  %o1, 0x378, %o3	! 0xa802e378
a01319e0:  c2 02 e0 10  ld  [ %o3 + 0x10 ], %g1
a01319e4:  d8 04 60 60  ld  [ %l1 + 0x60 ], %o4
a01319e8:  80 a0 40 0c  cmp  %g1, %o4
a01319ec:  38 80 02 fe  bgu,a   0xa01325e4
a01319f0:  94 12 63 78  or  %o1, 0x378, %o2
a01319f4:  22 80 02 f7  be,a   0xa01325d0
a01319f8:  de 02 e0 14  ld  [ %o3 + 0x14 ], %o7
a01319fc:  c2 02 e0 18  ld  [ %o3 + 0x18 ], %g1
a0131a00:  80 a3 00 01  cmp  %o4, %g1
a0131a04:  38 80 02 f8  bgu,a   0xa01325e4
a0131a08:  94 12 63 78  or  %o1, 0x378, %o2
a0131a0c:  80 a3 00 01  cmp  %o4, %g1
a0131a10:  22 80 03 37  be,a   0xa01326ec
a0131a14:  d0 02 e0 1c  ld  [ %o3 + 0x1c ], %o0
a0131a18:  80 8a a0 ff  btst  0xff, %o2
a0131a1c:  22 bf ff 1f  be,a   0xa0131698
a0131a20:  e6 05 00 00  ld  [ %l4 ], %l3
a0131a24:  d0 04 40 00  ld  [ %l1 ], %o0
a0131a28:  21 3f c3 ff  sethi  %hi(0xff0ffc00), %l0
a0131a2c:  d8 04 60 70  ld  [ %l1 + 0x70 ], %o4
a0131a30:  a4 0a 3f fe  and  %o0, -2, %l2
a0131a34:  1f 00 02 00  sethi  %hi(0x80000), %o7
a0131a38:  9a 14 23 ff  or  %l0, 0x3ff, %o5
a0131a3c:  a6 13 00 0f  or  %o4, %o7, %l3
a0131a40:  b0 0c 80 0d  and  %l2, %o5, %i0
a0131a44:  f0 24 40 00  st  %i0, [ %l1 ]
a0131a48:  10 bf ff 13  b  0xa0131694
a0131a4c:  e6 24 60 70  st  %l3, [ %l1 + 0x70 ]
a0131a50:  7f fe b5 c8  call  0xa00df170
a0131a54:  90 12 62 60  or  %o1, 0x260, %o0
a0131a58:  c2 04 40 00  ld  [ %l1 ], %g1
a0131a5c:  80 88 60 01  btst  1, %g1
a0131a60:  32 80 00 06  bne,a   0xa0131a78
a0131a64:  82 10 60 01  or  %g1, 1, %g1
a0131a68:  15 3f c3 ff  sethi  %hi(0xff0ffc00), %o2
a0131a6c:  90 12 a3 ff  or  %o2, 0x3ff, %o0	! 0xff0fffff
a0131a70:  82 08 40 08  and  %g1, %o0, %g1
a0131a74:  82 10 60 01  or  %g1, 1, %g1
a0131a78:  c2 24 40 00  st  %g1, [ %l1 ]
a0131a7c:  e6 05 00 00  ld  [ %l4 ], %l3
a0131a80:  93 34 e0 1c  srl  %l3, 0x1c, %o1
a0131a84:  17 03 c0 00  sethi  %hi(0xf000000), %o3
a0131a88:  82 2c c0 0b  andn  %l3, %o3, %g1
a0131a8c:  95 2a 60 18  sll  %o1, 0x18, %o2
a0131a90:  ae 05 e0 01  inc  %l7
a0131a94:  a2 10 40 0a  or  %g1, %o2, %l1
a0131a98:  a4 0d e0 ff  and  %l7, 0xff, %l2
a0131a9c:  80 a4 a0 03  cmp  %l2, 3
a0131aa0:  08 bf ff 08  bleu  0xa01316c0
a0131aa4:  e2 25 00 00  st  %l1, [ %l4 ]
a0131aa8:  a6 10 20 00  clr  %l3
a0131aac:  a0 10 20 00  clr  %l0
a0131ab0:  10 80 00 0d  b  0xa0131ae4
a0131ab4:  29 2a 00 b8  sethi  %hi(0xa802e000), %l4
a0131ab8:  7f ff df d6  call  0xa0129a10
a0131abc:  90 10 00 10  mov  %l0, %o0
a0131ac0:  e0 14 40 00  lduh  [ %l1 ], %l0
a0131ac4:  98 0a 20 01  and  %o0, 1, %o4
a0131ac8:  a4 0c 37 ff  and  %l0, -2049, %l2
a0131acc:  9b 2b 20 0b  sll  %o4, 0xb, %o5
a0131ad0:  b0 14 80 0d  or  %l2, %o5, %i0
a0131ad4:  a0 0c e0 ff  and  %l3, 0xff, %l0
a0131ad8:  80 a4 20 06  cmp  %l0, 6
a0131adc:  18 80 00 2a  bgu  0xa0131b84
a0131ae0:  f0 34 40 00  sth  %i0, [ %l1 ]
a0131ae4:  b5 2c 20 03  sll  %l0, 3, %i2
a0131ae8:  b2 06 80 10  add  %i2, %l0, %i1
a0131aec:  ac 06 40 19  add  %i1, %i1, %l6
a0131af0:  aa 15 21 16  or  %l4, 0x116, %l5
a0131af4:  a4 0c 20 ff  and  %l0, 0xff, %l2
a0131af8:  ee 15 80 15  lduh  [ %l6 + %l5 ], %l7
a0131afc:  a6 04 e0 01  inc  %l3
a0131b00:  90 10 00 12  mov  %l2, %o0
a0131b04:  80 8d e8 00  btst  0x800, %l7
a0131b08:  02 bf ff ec  be  0xa0131ab8
a0131b0c:  a2 05 80 15  add  %l6, %l5, %l1
a0131b10:  7f ff df c0  call  0xa0129a10
a0131b14:  01 00 00 00  nop
a0131b18:  80 8a 20 ff  btst  0xff, %o0
a0131b1c:  12 bf ff e7  bne  0xa0131ab8
a0131b20:  90 10 00 10  mov  %l0, %o0
a0131b24:  40 00 41 f4  call  0xa01422f4
a0131b28:  01 00 00 00  nop
a0131b2c:  ba 0a 20 ff  and  %o0, 0xff, %i5
a0131b30:  80 a7 60 01  cmp  %i5, 1
a0131b34:  02 80 02 96  be  0xa013258c
a0131b38:  90 10 00 10  mov  %l0, %o0
a0131b3c:  40 00 42 09  call  0xa0142360
a0131b40:  90 10 00 12  mov  %l2, %o0
a0131b44:  80 8a 20 ff  btst  0xff, %o0
a0131b48:  02 bf ff dc  be  0xa0131ab8
a0131b4c:  90 10 00 10  mov  %l0, %o0
a0131b50:  40 00 18 3f  call  0xa0137c4c
a0131b54:  01 00 00 00  nop
a0131b58:  7f ff df ae  call  0xa0129a10
a0131b5c:  90 10 00 10  mov  %l0, %o0
a0131b60:  e0 14 40 00  lduh  [ %l1 ], %l0
a0131b64:  98 0a 20 01  and  %o0, 1, %o4
a0131b68:  a4 0c 37 ff  and  %l0, -2049, %l2
a0131b6c:  9b 2b 20 0b  sll  %o4, 0xb, %o5
a0131b70:  b0 14 80 0d  or  %l2, %o5, %i0
a0131b74:  a0 0c e0 ff  and  %l3, 0xff, %l0
a0131b78:  80 a4 20 06  cmp  %l0, 6
a0131b7c:  08 bf ff da  bleu  0xa0131ae4
a0131b80:  f0 34 40 00  sth  %i0, [ %l1 ]
a0131b84:  7f ff f7 09  call  0xa012f7a8
a0131b88:  aa 10 20 00  clr  %l5
a0131b8c:  d6 07 23 30  ld  [ %i4 + 0x330 ], %o3
a0131b90:  93 32 e0 0c  srl  %o3, 0xc, %o1
a0131b94:  82 0a 60 0f  and  %o1, 0xf, %g1
a0131b98:  94 16 e2 24  or  %i3, 0x224, %o2
a0131b9c:  a2 58 60 2a  smul  %g1, 0x2a, %l1
a0131ba0:  90 10 3f ff  mov  -1, %o0
a0131ba4:  9e 04 40 0a  add  %l1, %o2, %o7
a0131ba8:  d0 2f bf f7  stb  %o0, [ %fp + -9 ]
a0131bac:  d0 0b e0 0a  ldub  [ %o7 + 0xa ], %o0
a0131bb0:  40 00 41 6e  call  0xa0142168
a0131bb4:  2d 2a 00 a9  sethi  %hi(0xa802a400), %l6
a0131bb8:  96 0a 20 ff  and  %o0, 0xff, %o3
a0131bbc:  80 a2 e0 ff  cmp  %o3, 0xff
a0131bc0:  02 80 00 11  be  0xa0131c04
a0131bc4:  94 10 20 00  clr  %o2
a0131bc8:  bb 2a e0 03  sll  %o3, 3, %i5
a0131bcc:  b4 07 40 0b  add  %i5, %o3, %i2
a0131bd0:  ae 06 80 1a  add  %i2, %i2, %l7
a0131bd4:  b2 15 21 16  or  %l4, 0x116, %i1
a0131bd8:  ea 16 40 17  lduh  [ %i1 + %l7 ], %l5
a0131bdc:  a7 35 60 0c  srl  %l5, 0xc, %l3
a0131be0:  80 a4 e0 05  cmp  %l3, 5
a0131be4:  02 80 02 2f  be  0xa01324a0
a0131be8:  da 0d a0 4c  ldub  [ %l6 + 0x4c ], %o5
a0131bec:  a4 1b 60 ff  xor  %o5, 0xff, %l2
a0131bf0:  80 a0 00 12  cmp  %g0, %l2
a0131bf4:  b0 40 3f ff  addx  %g0, -1, %i0
a0131bf8:  a8 0e 3f fd  and  %i0, -3, %l4
a0131bfc:  94 05 20 03  add  %l4, 3, %o2
a0131c00:  aa 10 00 0a  mov  %o2, %l5
a0131c04:  90 05 7f fe  add  %l5, -2, %o0
a0131c08:  80 a2 20 01  cmp  %o0, 1
a0131c0c:  08 80 01 cb  bleu  0xa0132338
a0131c10:  d0 0d a0 4c  ldub  [ %l6 + 0x4c ], %o0
a0131c14:  a0 05 7f ff  add  %l5, -1, %l0
a0131c18:  80 a4 20 01  cmp  %l0, 1
a0131c1c:  08 80 02 09  bleu  0xa0132440
a0131c20:  d0 0f bf f7  ldub  [ %fp + -9 ], %o0
a0131c24:  80 a5 60 00  cmp  %l5, 0
a0131c28:  12 80 00 12  bne  0xa0131c70
a0131c2c:  de 0d a0 4c  ldub  [ %l6 + 0x4c ], %o7
a0131c30:  d0 0d a0 4c  ldub  [ %l6 + 0x4c ], %o0
a0131c34:  80 a2 20 ff  cmp  %o0, 0xff
a0131c38:  02 80 02 ca  be  0xa0132760
a0131c3c:  01 00 00 00  nop
a0131c40:  7f ff 2e f8  call  0xa00fd820
a0131c44:  01 00 00 00  nop
a0131c48:  aa 0a 20 ff  and  %o0, 0xff, %l5
a0131c4c:  80 a5 60 b1  cmp  %l5, 0xb1
a0131c50:  02 80 00 07  be  0xa0131c6c
a0131c54:  d0 0d a0 4c  ldub  [ %l6 + 0x4c ], %o0
a0131c58:  7f ff 2e 4f  call  0xa00fd594
a0131c5c:  92 10 20 b1  mov  0xb1, %o1
a0131c60:  d0 0d a0 4c  ldub  [ %l6 + 0x4c ], %o0
a0131c64:  7f ff 2f 4f  call  0xa00fd9a0
a0131c68:  92 10 20 b1  mov  0xb1, %o1
a0131c6c:  de 0d a0 4c  ldub  [ %l6 + 0x4c ], %o7
a0131c70:  80 a3 e0 ff  cmp  %o7, 0xff
a0131c74:  02 80 02 bb  be  0xa0132760
a0131c78:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a0131c7c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0131c80:  a4 10 63 30  or  %g1, 0x330, %l2
a0131c84:  a6 13 22 24  or  %o4, 0x224, %l3
a0131c88:  a2 10 20 01  mov  1, %l1
a0131c8c:  9a 10 20 01  mov  1, %o5
a0131c90:  a1 2b 60 04  sll  %o5, 4, %l0
a0131c94:  b6 24 00 0d  sub  %l0, %o5, %i3
a0131c98:  a1 2e e0 03  sll  %i3, 3, %l0
a0131c9c:  d2 04 80 10  ld  [ %l2 + %l0 ], %o1
a0131ca0:  91 32 60 0c  srl  %o1, 0xc, %o0
a0131ca4:  7f ff 2e df  call  0xa00fd820
a0131ca8:  90 0a 20 0f  and  %o0, 0xf, %o0
a0131cac:  94 0a 20 ff  and  %o0, 0xff, %o2
a0131cb0:  80 a2 a0 b1  cmp  %o2, 0xb1
a0131cb4:  02 80 00 0a  be  0xa0131cdc
a0131cb8:  a2 04 60 01  inc  %l1
a0131cbc:  f2 07 23 30  ld  [ %i4 + 0x330 ], %i1
a0131cc0:  af 36 60 0c  srl  %i1, 0xc, %l7
a0131cc4:  7f ff 2e d7  call  0xa00fd820
a0131cc8:  90 0d e0 0f  and  %l7, 0xf, %o0
a0131ccc:  96 0a 20 ff  and  %o0, 0xff, %o3
a0131cd0:  80 a2 e0 b1  cmp  %o3, 0xb1
a0131cd4:  22 80 01 5c  be,a   0xa0132244
a0131cd8:  f6 04 80 10  ld  [ %l2 + %l0 ], %i3
a0131cdc:  9a 0c 60 ff  and  %l1, 0xff, %o5
a0131ce0:  80 a3 60 03  cmp  %o5, 3
a0131ce4:  28 bf ff ec  bleu,a   0xa0131c94
a0131ce8:  a1 2b 60 04  sll  %o5, 4, %l0
a0131cec:  30 80 02 9d  b,a   0xa0132760
a0131cf0:  da 0e 20 34  ldub  [ %i0 + 0x34 ], %o5
a0131cf4:  a2 04 a0 04  add  %l2, 4, %l1
a0131cf8:  91 3b 40 11  sra  %o5, %l1, %o0
a0131cfc:  80 8a 20 01  btst  1, %o0
a0131d00:  22 80 00 06  be,a   0xa0131d18
a0131d04:  f0 04 20 70  ld  [ %l0 + 0x70 ], %i0
a0131d08:  80 8b 60 0f  btst  0xf, %o5
a0131d0c:  12 80 00 d3  bne  0xa0132058
a0131d10:  01 00 00 00  nop
a0131d14:  f0 04 20 70  ld  [ %l0 + 0x70 ], %i0
a0131d18:  03 02 00 00  sethi  %hi(0x8000000), %g1
a0131d1c:  a2 16 00 01  or  %i0, %g1, %l1
a0131d20:  9b 2c a0 04  sll  %l2, 4, %o5
a0131d24:  e2 24 20 70  st  %l1, [ %l0 + 0x70 ]
a0131d28:  98 23 40 12  sub  %o5, %l2, %o4
a0131d2c:  a3 2b 20 03  sll  %o4, 3, %l1
a0131d30:  d0 04 40 1a  ld  [ %l1 + %i2 ], %o0
a0131d34:  9e 0a 00 16  and  %o0, %l6, %o7
a0131d38:  21 24 00 00  sethi  %hi(0x90000000), %l0
a0131d3c:  80 a3 c0 10  cmp  %o7, %l0
a0131d40:  12 bf fe 2c  bne  0xa01315f0
a0131d44:  a6 10 00 1a  mov  %i2, %l3
a0131d48:  83 32 20 0c  srl  %o0, 0xc, %g1
a0131d4c:  40 00 35 26  call  0xa013f1e4
a0131d50:  90 08 60 0f  and  %g1, 0xf, %o0
a0131d54:  b0 10 00 08  mov  %o0, %i0
a0131d58:  d0 04 40 1a  ld  [ %l1 + %i2 ], %o0
a0131d5c:  95 32 20 0c  srl  %o0, 0xc, %o2
a0131d60:  40 00 38 ce  call  0xa0140098
a0131d64:  90 0a a0 0f  and  %o2, 0xf, %o0
a0131d68:  92 0e 20 ff  and  %i0, 0xff, %o1
a0131d6c:  96 0a 20 ff  and  %o0, 0xff, %o3
a0131d70:  80 a2 40 0b  cmp  %o1, %o3
a0131d74:  22 80 01 d6  be,a   0xa01324cc
a0131d78:  d2 04 40 1a  ld  [ %l1 + %i2 ], %o1
a0131d7c:  d8 04 40 13  ld  [ %l1 + %l3 ], %o4
a0131d80:  82 0b 00 19  and  %o4, %i1, %g1
a0131d84:  31 18 00 00  sethi  %hi(0x60000000), %i0
a0131d88:  21 3f c3 ff  sethi  %hi(0xff0ffc00), %l0
a0131d8c:  90 10 40 18  or  %g1, %i0, %o0
a0131d90:  9e 14 23 ff  or  %l0, 0x3ff, %o7
a0131d94:  94 0a 00 0f  and  %o0, %o7, %o2
a0131d98:  10 bf fe 16  b  0xa01315f0
a0131d9c:  d4 24 40 13  st  %o2, [ %l1 + %l3 ]
a0131da0:  a0 0c 60 ff  and  %l1, 0xff, %l0
a0131da4:  a7 33 60 1c  srl  %o5, 0x1c, %l3
a0131da8:  80 a4 00 13  cmp  %l0, %l3
a0131dac:  02 bf fe c1  be  0xa01318b0
a0131db0:  b0 0b 40 16  and  %o5, %l6, %i0
a0131db4:  19 28 00 00  sethi  %hi(0xa0000000), %o4
a0131db8:  80 a6 00 0c  cmp  %i0, %o4
a0131dbc:  32 bf fe be  bne,a   0xa01318b4
a0131dc0:  da 05 00 00  ld  [ %l4 ], %o5
a0131dc4:  40 00 3f 35  call  0xa0141a98
a0131dc8:  01 00 00 00  nop
a0131dcc:  80 8a 20 ff  btst  0xff, %o0
a0131dd0:  32 bf fe b9  bne,a   0xa01318b4
a0131dd4:  da 05 00 00  ld  [ %l4 ], %o5
a0131dd8:  40 00 3d 38  call  0xa01412b8
a0131ddc:  90 10 20 01  mov  1, %o0
a0131de0:  10 bf fe b5  b  0xa01318b4
a0131de4:  da 05 00 00  ld  [ %l4 ], %o5
a0131de8:  e6 05 20 70  ld  [ %l4 + 0x70 ], %l3
a0131dec:  19 01 00 00  sethi  %hi(0x4000000), %o4
a0131df0:  10 bf fe be  b  0xa01318e8
a0131df4:  82 14 c0 0c  or  %l3, %o4, %g1
a0131df8:  11 00 02 00  sethi  %hi(0x80000), %o0
a0131dfc:  a6 2e 00 08  andn  %i0, %o0, %l3
a0131e00:  10 bf fe d6  b  0xa0131958
a0131e04:  e6 24 60 70  st  %l3, [ %l1 + 0x70 ]
a0131e08:  03 00 08 00  sethi  %hi(0x200000), %g1
a0131e0c:  9a 0a c0 01  and  %o3, %g1, %o5
a0131e10:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0131e14:  96 10 20 00  clr  %o3
a0131e18:  98 10 20 00  clr  %o4
a0131e1c:  9e 12 23 d0  or  %o0, 0x3d0, %o7
a0131e20:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a0131e24:  10 80 00 0a  b  0xa0131e4c
a0131e28:  90 12 a3 30  or  %o2, 0x330, %o0	! 0xa802df30
a0131e2c:  f0 0b e0 2f  ldub  [ %o7 + 0x2f ], %i0
a0131e30:  80 a6 20 00  cmp  %i0, 0
a0131e34:  12 80 00 0f  bne  0xa0131e70
a0131e38:  80 a3 20 03  cmp  %o4, 3
a0131e3c:  98 0a e0 ff  and  %o3, 0xff, %o4
a0131e40:  80 a3 20 03  cmp  %o4, 3
a0131e44:  18 80 00 13  bgu  0xa0131e90
a0131e48:  82 10 20 00  clr  %g1
a0131e4c:  80 a4 80 0c  cmp  %l2, %o4
a0131e50:  02 bf ff fb  be  0xa0131e3c
a0131e54:  96 02 e0 01  inc  %o3
a0131e58:  a3 2b 20 04  sll  %o4, 4, %l1
a0131e5c:  a0 24 40 0c  sub  %l1, %o4, %l0
a0131e60:  80 a3 20 00  cmp  %o4, 0
a0131e64:  12 bf ff f2  bne  0xa0131e2c
a0131e68:  95 2c 20 03  sll  %l0, 3, %o2
a0131e6c:  80 a3 20 03  cmp  %o4, 3
a0131e70:  02 80 00 3c  be  0xa0131f60
a0131e74:  80 a3 60 00  cmp  %o5, 0
a0131e78:  c2 02 80 08  ld  [ %o2 + %o0 ], %g1
a0131e7c:  99 30 60 1c  srl  %g1, 0x1c, %o4
a0131e80:  80 a3 20 09  cmp  %o4, 9
a0131e84:  08 bf ff ef  bleu  0xa0131e40
a0131e88:  98 0a e0 ff  and  %o3, 0xff, %o4
a0131e8c:  82 10 20 01  mov  1, %g1
a0131e90:  80 a0 60 00  cmp  %g1, 0
a0131e94:  12 bf fe 3f  bne  0xa0131790
a0131e98:  23 3c 00 00  sethi  %hi(0xf0000000), %l1
a0131e9c:  40 00 7d f6  call  0xa0151674
a0131ea0:  21 30 00 00  sethi  %hi(0xc0000000), %l0
a0131ea4:  d2 04 c0 00  ld  [ %l3 ], %o1
a0131ea8:  9e 0a 40 11  and  %o1, %l1, %o7
a0131eac:  80 a3 c0 10  cmp  %o7, %l0
a0131eb0:  32 bf fe 40  bne,a   0xa01317b0
a0131eb4:  21 14 00 00  sethi  %hi(0x50000000), %l0
a0131eb8:  40 00 7e 58  call  0xa0151818
a0131ebc:  90 10 00 12  mov  %l2, %o0
a0131ec0:  d2 04 c0 00  ld  [ %l3 ], %o1
a0131ec4:  9a 0a 40 11  and  %o1, %l1, %o5
a0131ec8:  80 a3 40 10  cmp  %o5, %l0
a0131ecc:  12 bf fe 36  bne  0xa01317a4
a0131ed0:  d6 07 63 d0  ld  [ %i5 + 0x3d0 ], %o3
a0131ed4:  21 00 08 00  sethi  %hi(0x200000), %l0
a0131ed8:  9a 0a c0 10  and  %o3, %l0, %o5
a0131edc:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0131ee0:  96 10 20 00  clr  %o3
a0131ee4:  98 10 20 00  clr  %o4
a0131ee8:  9e 12 23 d0  or  %o0, 0x3d0, %o7
a0131eec:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a0131ef0:  10 80 00 0a  b  0xa0131f18
a0131ef4:  90 12 a3 30  or  %o2, 0x330, %o0	! 0xa802df30
a0131ef8:  c2 0b e0 2f  ldub  [ %o7 + 0x2f ], %g1
a0131efc:  80 a0 60 00  cmp  %g1, 0
a0131f00:  12 80 00 0f  bne  0xa0131f3c
a0131f04:  80 a3 20 03  cmp  %o4, 3
a0131f08:  98 0a e0 ff  and  %o3, 0xff, %o4
a0131f0c:  80 a3 20 03  cmp  %o4, 3
a0131f10:  18 80 00 ef  bgu  0xa01322cc
a0131f14:  82 10 20 00  clr  %g1
a0131f18:  80 a4 80 0c  cmp  %l2, %o4
a0131f1c:  02 bf ff fb  be  0xa0131f08
a0131f20:  96 02 e0 01  inc  %o3
a0131f24:  b1 2b 20 04  sll  %o4, 4, %i0
a0131f28:  a2 26 00 0c  sub  %i0, %o4, %l1
a0131f2c:  80 a3 20 00  cmp  %o4, 0
a0131f30:  12 bf ff f2  bne  0xa0131ef8
a0131f34:  95 2c 60 03  sll  %l1, 3, %o2
a0131f38:  80 a3 20 03  cmp  %o4, 3
a0131f3c:  02 80 00 de  be  0xa01322b4
a0131f40:  80 a3 60 00  cmp  %o5, 0
a0131f44:  e0 02 80 08  ld  [ %o2 + %o0 ], %l0
a0131f48:  99 34 20 1c  srl  %l0, 0x1c, %o4
a0131f4c:  80 a3 20 0b  cmp  %o4, 0xb
a0131f50:  28 bf ff ef  bleu,a   0xa0131f0c
a0131f54:  98 0a e0 ff  and  %o3, 0xff, %o4
a0131f58:  10 80 00 dd  b  0xa01322cc
a0131f5c:  82 10 20 01  mov  1, %g1
a0131f60:  02 bf ff c6  be  0xa0131e78
a0131f64:  98 0a e0 ff  and  %o3, 0xff, %o4
a0131f68:  80 a3 20 03  cmp  %o4, 3
a0131f6c:  08 bf ff b9  bleu  0xa0131e50
a0131f70:  80 a4 80 0c  cmp  %l2, %o4
a0131f74:  10 bf ff c7  b  0xa0131e90
a0131f78:  82 10 20 00  clr  %g1
a0131f7c:  19 18 00 00  sethi  %hi(0x60000000), %o4
a0131f80:  80 a3 40 0c  cmp  %o5, %o4
a0131f84:  32 bf fd f7  bne,a   0xa0131760
a0131f88:  d2 04 c0 00  ld  [ %l3 ], %o1
a0131f8c:  40 00 7d 42  call  0xa0151494
a0131f90:  90 10 00 12  mov  %l2, %o0
a0131f94:  d2 04 c0 00  ld  [ %l3 ], %o1
a0131f98:  23 3c 00 00  sethi  %hi(0xf0000000), %l1
a0131f9c:  9e 0a 40 11  and  %o1, %l1, %o7
a0131fa0:  21 28 00 00  sethi  %hi(0xa0000000), %l0
a0131fa4:  80 a3 c0 10  cmp  %o7, %l0
a0131fa8:  12 bf fd f5  bne  0xa013177c
a0131fac:  9a 0a 40 16  and  %o1, %l6, %o5
a0131fb0:  40 00 7d c0  call  0xa01516b0
a0131fb4:  90 10 00 12  mov  %l2, %o0
a0131fb8:  d2 04 c0 00  ld  [ %l3 ], %o1
a0131fbc:  94 0a 40 11  and  %o1, %l1, %o2
a0131fc0:  80 a2 80 10  cmp  %o2, %l0
a0131fc4:  12 bf fd ed  bne  0xa0131778
a0131fc8:  11 00 08 00  sethi  %hi(0x200000), %o0
a0131fcc:  d6 07 63 d0  ld  [ %i5 + 0x3d0 ], %o3
a0131fd0:  9a 0a c0 08  and  %o3, %o0, %o5
a0131fd4:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a0131fd8:  96 10 20 00  clr  %o3
a0131fdc:  98 10 20 00  clr  %o4
a0131fe0:  9e 16 23 d0  or  %i0, 0x3d0, %o7
a0131fe4:  23 2a 00 b7  sethi  %hi(0xa802dc00), %l1
a0131fe8:  10 80 00 0a  b  0xa0132010
a0131fec:  90 14 63 30  or  %l1, 0x330, %o0	! 0xa802df30
a0131ff0:  e2 0b e0 2f  ldub  [ %o7 + 0x2f ], %l1
a0131ff4:  80 a4 60 00  cmp  %l1, 0
a0131ff8:  12 80 00 0f  bne  0xa0132034
a0131ffc:  80 a3 20 03  cmp  %o4, 3
a0132000:  98 0a e0 ff  and  %o3, 0xff, %o4
a0132004:  80 a3 20 03  cmp  %o4, 3
a0132008:  18 80 00 be  bgu  0xa0132300
a013200c:  82 10 20 00  clr  %g1
a0132010:  80 a4 80 0c  cmp  %l2, %o4
a0132014:  02 bf ff fb  be  0xa0132000
a0132018:  96 02 e0 01  inc  %o3
a013201c:  a1 2b 20 04  sll  %o4, 4, %l0
a0132020:  82 24 00 0c  sub  %l0, %o4, %g1
a0132024:  80 a3 20 00  cmp  %o4, 0
a0132028:  12 bf ff f2  bne  0xa0131ff0
a013202c:  95 28 60 03  sll  %g1, 3, %o2
a0132030:  80 a3 20 03  cmp  %o4, 3
a0132034:  02 80 00 ad  be  0xa01322e8
a0132038:  80 a3 60 00  cmp  %o5, 0
a013203c:  f0 02 80 08  ld  [ %o2 + %o0 ], %i0
a0132040:  99 36 20 1c  srl  %i0, 0x1c, %o4
a0132044:  80 a3 20 09  cmp  %o4, 9
a0132048:  28 bf ff ef  bleu,a   0xa0132004
a013204c:  98 0a e0 ff  and  %o3, 0xff, %o4
a0132050:  10 80 00 ac  b  0xa0132300
a0132054:  82 10 20 01  mov  1, %g1
a0132058:  67 fd 6d 4c  call  0x4008d588
a013205c:  01 00 00 00  nop
a0132060:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a0132064:  da 04 20 70  ld  [ %l0 + 0x70 ], %o5
a0132068:  96 04 80 12  add  %l2, %l2, %o3
a013206c:  a6 12 63 82  or  %o1, 0x382, %l3
a0132070:  19 02 00 00  sethi  %hi(0x8000000), %o4
a0132074:  d0 34 c0 0b  sth  %o0, [ %l3 + %o3 ]
a0132078:  9e 2b 40 0c  andn  %o5, %o4, %o7
a013207c:  03 00 06 94  sethi  %hi(0x1a5000), %g1
a0132080:  de 24 20 70  st  %o7, [ %l0 + 0x70 ]
a0132084:  7f fe b4 3b  call  0xa00df170
a0132088:  90 10 62 78  or  %g1, 0x278, %o0
a013208c:  10 bf fd 51  b  0xa01315d0
a0132090:  9b 2c a0 04  sll  %l2, 4, %o5
a0132094:  40 00 7e 0d  call  0xa01518c8
a0132098:  90 10 00 12  mov  %l2, %o0
a013209c:  d2 04 c0 00  ld  [ %l3 ], %o1
a01320a0:  a6 0a 40 11  and  %o1, %l1, %l3
a01320a4:  80 a4 c0 10  cmp  %l3, %l0
a01320a8:  12 bf fd c5  bne  0xa01317bc
a01320ac:  98 10 20 00  clr  %o4
a01320b0:  9a 10 20 00  clr  %o5
a01320b4:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a01320b8:  96 12 a3 30  or  %o2, 0x330, %o3	! 0xa802df30
a01320bc:  a3 2b 60 04  sll  %o5, 4, %l1
a01320c0:  90 24 40 0d  sub  %l1, %o5, %o0
a01320c4:  98 03 20 01  inc  %o4
a01320c8:  80 a4 80 0d  cmp  %l2, %o5
a01320cc:  83 2a 20 03  sll  %o0, 3, %g1
a01320d0:  02 80 00 07  be  0xa01320ec
a01320d4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a01320d8:  c2 00 40 0b  ld  [ %g1 + %o3 ], %g1
a01320dc:  b1 30 60 1c  srl  %g1, 0x1c, %i0
a01320e0:  80 a6 20 05  cmp  %i0, 5
a01320e4:  18 80 00 06  bgu  0xa01320fc
a01320e8:  82 10 20 00  clr  %g1
a01320ec:  80 a3 60 03  cmp  %o5, 3
a01320f0:  08 bf ff f4  bleu  0xa01320c0
a01320f4:  a3 2b 60 04  sll  %o5, 4, %l1
a01320f8:  82 10 20 01  mov  1, %g1
a01320fc:  80 a0 60 00  cmp  %g1, 0
a0132100:  22 bf fd b0  be,a   0xa01317c0
a0132104:  d8 05 00 00  ld  [ %l4 ], %o4
a0132108:  40 00 7e 2b  call  0xa01519b4
a013210c:  a7 2c a0 04  sll  %l2, 4, %l3
a0132110:  10 bf fd ad  b  0xa01317c4
a0132114:  d8 05 00 00  ld  [ %l4 ], %o4
a0132118:  7f ff ca 4a  call  0xa0124a40
a013211c:  01 00 00 00  nop
a0132120:  80 8a 20 ff  btst  0xff, %o0
a0132124:  32 bf fd 77  bne,a   0xa0131700
a0132128:  d8 05 00 00  ld  [ %l4 ], %o4
a013212c:  7f ff ca 30  call  0xa01249ec
a0132130:  a6 17 63 d0  or  %i5, 0x3d0, %l3
a0132134:  10 bf fd 74  b  0xa0131704
a0132138:  d8 05 00 00  ld  [ %l4 ], %o4
a013213c:  7f ff bc 47  call  0xa0121258
a0132140:  90 0a 60 0f  and  %o1, 0xf, %o0
a0132144:  96 0a 20 ff  and  %o0, 0xff, %o3
a0132148:  80 a2 e0 01  cmp  %o3, 1
a013214c:  12 bf fd 46  bne  0xa0131664
a0132150:  99 2c a0 04  sll  %l2, 4, %o4
a0132154:  80 8c e0 ff  btst  0xff, %l3
a0132158:  12 bf fd 44  bne  0xa0131668
a013215c:  82 23 00 12  sub  %o4, %l2, %g1
a0132160:  d0 14 20 12  lduh  [ %l0 + 0x12 ], %o0
a0132164:  d2 14 20 14  lduh  [ %l0 + 0x14 ], %o1
a0132168:  7f ff 4e fc  call  0xa0105d58
a013216c:  d4 14 20 08  lduh  [ %l0 + 8 ], %o2
a0132170:  a6 0a 20 ff  and  %o0, 0xff, %l3
a0132174:  80 a4 e0 01  cmp  %l3, 1
a0132178:  12 bf fd 3b  bne  0xa0131664
a013217c:  99 2c a0 04  sll  %l2, 4, %o4
a0132180:  80 a4 a0 02  cmp  %l2, 2
a0132184:  02 bf fd 38  be  0xa0131664
a0132188:  80 a4 a0 03  cmp  %l2, 3
a013218c:  02 bf fd 36  be  0xa0131664
a0132190:  92 10 20 00  clr  %o1
a0132194:  11 2a 00 b7  sethi  %hi(0xa802dc00), %o0
a0132198:  9a 10 20 00  clr  %o5
a013219c:  9e 12 23 30  or  %o0, 0x330, %o7
a01321a0:  15 00 06 94  sethi  %hi(0x1a5000), %o2
a01321a4:  d0 02 a3 1c  ld  [ %o2 + 0x31c ], %o0	! 0x1a531c
a01321a8:  b1 2b 60 04  sll  %o5, 4, %i0
a01321ac:  82 26 00 0d  sub  %i0, %o5, %g1
a01321b0:  97 28 60 03  sll  %g1, 3, %o3
a01321b4:  92 02 60 01  inc  %o1
a01321b8:  80 a3 40 12  cmp  %o5, %l2
a01321bc:  02 80 00 06  be  0xa01321d4
a01321c0:  94 02 c0 0f  add  %o3, %o7, %o2
a01321c4:  d8 02 a0 70  ld  [ %o2 + 0x70 ], %o4
a01321c8:  80 a3 20 00  cmp  %o4, 0
a01321cc:  06 80 01 4e  bl  0xa0132704
a01321d0:  80 a3 40 12  cmp  %o5, %l2
a01321d4:  9a 0a 60 ff  and  %o1, 0xff, %o5
a01321d8:  80 a3 60 03  cmp  %o5, 3
a01321dc:  08 bf ff f4  bleu  0xa01321ac
a01321e0:  b1 2b 60 04  sll  %o5, 4, %i0
a01321e4:  d4 04 20 70  ld  [ %l0 + 0x70 ], %o2
a01321e8:  a7 2c a0 04  sll  %l2, 4, %l3
a01321ec:  11 20 00 00  sethi  %hi(0x80000000), %o0
a01321f0:  92 12 80 08  or  %o2, %o0, %o1
a01321f4:  a2 24 c0 12  sub  %l3, %l2, %l1
a01321f8:  d2 24 20 70  st  %o1, [ %l0 + 0x70 ]
a01321fc:  97 2c 60 03  sll  %l1, 3, %o3
a0132200:  e0 05 40 0b  ld  [ %l5 + %o3 ], %l0
a0132204:  9f 34 20 0c  srl  %l0, 0xc, %o7
a0132208:  90 0b e0 0f  and  %o7, 0xf, %o0
a013220c:  7f ff 88 4c  call  0xa011433c
a0132210:  01 00 00 00  nop
a0132214:  10 bf fd 14  b  0xa0131664
a0132218:  99 2c a0 04  sll  %l2, 4, %o4
a013221c:  40 00 3e 2d  call  0xa0141ad0
a0132220:  01 00 00 00  nop
a0132224:  80 8a 20 ff  btst  0xff, %o0
a0132228:  02 bf fd a8  be  0xa01318c8
a013222c:  15 24 00 00  sethi  %hi(0x90000000), %o2
a0132230:  d6 05 00 00  ld  [ %l4 ], %o3
a0132234:  9e 0a c0 19  and  %o3, %i1, %o7
a0132238:  92 13 c0 0a  or  %o7, %o2, %o1
a013223c:  10 bf fd a3  b  0xa01318c8
a0132240:  d2 25 00 00  st  %o1, [ %l4 ]
a0132244:  91 36 e0 0c  srl  %i3, 0xc, %o0
a0132248:  7f ff 2d 76  call  0xa00fd820
a013224c:  90 0a 20 0f  and  %o0, 0xf, %o0
a0132250:  c2 0d a0 4c  ldub  [ %l6 + 0x4c ], %g1
a0132254:  93 28 60 04  sll  %g1, 4, %o1
a0132258:  94 22 40 01  sub  %o1, %g1, %o2
a013225c:  99 2a a0 03  sll  %o2, 3, %o4
a0132260:  de 04 80 0c  ld  [ %l2 + %o4 ], %o7
a0132264:  ab 33 e0 0c  srl  %o7, 0xc, %l5
a0132268:  9a 0d 60 0f  and  %l5, 0xf, %o5
a013226c:  b0 5b 60 2a  smul  %o5, 0x2a, %i0
a0132270:  a8 06 00 13  add  %i0, %l3, %l4
a0132274:  ba 0a 20 ff  and  %o0, 0xff, %i5
a0132278:  f4 0d 20 0a  ldub  [ %l4 + 0xa ], %i2
a013227c:  80 a7 40 1a  cmp  %i5, %i2
a0132280:  12 bf fe 97  bne  0xa0131cdc
a0132284:  92 10 20 b1  mov  0xb1, %o1
a0132288:  f2 04 80 10  ld  [ %l2 + %l0 ], %i1
a013228c:  af 36 60 0c  srl  %i1, 0xc, %l7
a0132290:  7f ff 2c c1  call  0xa00fd594
a0132294:  90 0d e0 0f  and  %l7, 0xf, %o0
a0132298:  d6 04 80 10  ld  [ %l2 + %l0 ], %o3
a013229c:  a1 32 e0 0c  srl  %o3, 0xc, %l0
a01322a0:  90 0c 20 0f  and  %l0, 0xf, %o0
a01322a4:  7f ff 2d bf  call  0xa00fd9a0
a01322a8:  92 10 20 b1  mov  0xb1, %o1
a01322ac:  10 bf fe 8d  b  0xa0131ce0
a01322b0:  9a 0c 60 ff  and  %l1, 0xff, %o5
a01322b4:  02 bf ff 24  be  0xa0131f44
a01322b8:  98 0a e0 ff  and  %o3, 0xff, %o4
a01322bc:  80 a3 20 03  cmp  %o4, 3
a01322c0:  08 bf ff 17  bleu  0xa0131f1c
a01322c4:  80 a4 80 0c  cmp  %l2, %o4
a01322c8:  82 10 20 00  clr  %g1
a01322cc:  80 a0 60 00  cmp  %g1, 0
a01322d0:  12 bf fd 36  bne  0xa01317a8
a01322d4:  23 3c 00 00  sethi  %hi(0xf0000000), %l1
a01322d8:  40 00 7d 47  call  0xa01517f4
a01322dc:  01 00 00 00  nop
a01322e0:  10 bf fd 32  b  0xa01317a8
a01322e4:  d2 04 c0 00  ld  [ %l3 ], %o1
a01322e8:  02 bf ff 55  be  0xa013203c
a01322ec:  98 0a e0 ff  and  %o3, 0xff, %o4
a01322f0:  80 a3 20 03  cmp  %o4, 3
a01322f4:  08 bf ff 48  bleu  0xa0132014
a01322f8:  80 a4 80 0c  cmp  %l2, %o4
a01322fc:  82 10 20 00  clr  %g1
a0132300:  80 a0 60 00  cmp  %g1, 0
a0132304:  12 bf fd 1e  bne  0xa013177c
a0132308:  9a 0a 40 16  and  %o1, %l6, %o5
a013230c:  40 00 7c 64  call  0xa015149c
a0132310:  01 00 00 00  nop
a0132314:  10 bf fd 19  b  0xa0131778
a0132318:  d2 04 c0 00  ld  [ %l3 ], %o1
a013231c:  40 00 3b e7  call  0xa01412b8
a0132320:  90 10 20 01  mov  1, %o0
a0132324:  23 00 06 94  sethi  %hi(0x1a5000), %l1
a0132328:  7f fe b3 92  call  0xa00df170
a013232c:  90 14 62 88  or  %l1, 0x288, %o0	! 0x1a5288
a0132330:  10 bf fd 61  b  0xa01318b4
a0132334:  da 05 00 00  ld  [ %l4 ], %o5
a0132338:  95 2a 20 04  sll  %o0, 4, %o2
a013233c:  a2 22 80 08  sub  %o2, %o0, %l1
a0132340:  a7 2c 60 03  sll  %l1, 3, %l3
a0132344:  a2 17 23 30  or  %i4, 0x330, %l1
a0132348:  c2 04 40 13  ld  [ %l1 + %l3 ], %g1
a013234c:  99 30 60 0c  srl  %g1, 0xc, %o4
a0132350:  a0 0b 20 0f  and  %o4, 0xf, %l0
a0132354:  9e 5c 20 2a  smul  %l0, 0x2a, %o7
a0132358:  a0 16 e2 24  or  %i3, 0x224, %l0
a013235c:  9a 03 c0 10  add  %o7, %l0, %o5
a0132360:  7f ff 2c 8d  call  0xa00fd594
a0132364:  d2 0b 60 0a  ldub  [ %o5 + 0xa ], %o1
a0132368:  d0 0d a0 4c  ldub  [ %l6 + 0x4c ], %o0
a013236c:  a5 2a 20 04  sll  %o0, 4, %l2
a0132370:  b0 24 80 08  sub  %l2, %o0, %i0
a0132374:  a9 2e 20 03  sll  %i0, 3, %l4
a0132378:  fa 04 40 14  ld  [ %l1 + %l4 ], %i5
a013237c:  b5 37 60 0c  srl  %i5, 0xc, %i2
a0132380:  b2 0e a0 0f  and  %i2, 0xf, %i1
a0132384:  ae 5e 60 2a  smul  %i1, 0x2a, %l7
a0132388:  96 05 c0 10  add  %l7, %l0, %o3
a013238c:  7f ff 2d 85  call  0xa00fd9a0
a0132390:  d2 0a e0 0a  ldub  [ %o3 + 0xa ], %o1
a0132394:  92 10 3f ff  mov  -1, %o1
a0132398:  d2 2d a0 4c  stb  %o1, [ %l6 + 0x4c ]
a013239c:  a6 10 20 01  mov  1, %l3
a01323a0:  10 80 00 06  b  0xa01323b8
a01323a4:  9a 10 20 01  mov  1, %o5
a01323a8:  9a 0c e0 ff  and  %l3, 0xff, %o5
a01323ac:  80 a3 60 03  cmp  %o5, 3
a01323b0:  38 bf fe 1a  bgu,a   0xa0131c18
a01323b4:  a0 05 7f ff  add  %l5, -1, %l0
a01323b8:  b3 2b 60 04  sll  %o5, 4, %i1
a01323bc:  ae 26 40 0d  sub  %i1, %o5, %l7
a01323c0:  a5 2d e0 03  sll  %l7, 3, %l2
a01323c4:  d6 04 40 12  ld  [ %l1 + %l2 ], %o3
a01323c8:  93 32 e0 0c  srl  %o3, 0xc, %o1
a01323cc:  7f ff 2d 15  call  0xa00fd820
a01323d0:  90 0a 60 0f  and  %o1, 0xf, %o0
a01323d4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01323d8:  80 a2 20 b1  cmp  %o0, 0xb1
a01323dc:  12 bf ff f3  bne  0xa01323a8
a01323e0:  a6 04 e0 01  inc  %l3
a01323e4:  fa 04 40 12  ld  [ %l1 + %l2 ], %i5
a01323e8:  b5 37 60 0c  srl  %i5, 0xc, %i2
a01323ec:  7f ff 4a 12  call  0xa0104c34
a01323f0:  90 0e a0 0f  and  %i2, 0xf, %o0
a01323f4:  80 8a 20 ff  btst  0xff, %o0
a01323f8:  22 80 00 60  be,a   0xa0132578
a01323fc:  f0 04 40 12  ld  [ %l1 + %l2 ], %i0
a0132400:  d2 04 40 12  ld  [ %l1 + %l2 ], %o1
a0132404:  91 32 60 0c  srl  %o1, 0xc, %o0
a0132408:  90 0a 20 0f  and  %o0, 0xf, %o0
a013240c:  94 5a 20 2a  smul  %o0, 0x2a, %o2
a0132410:  82 02 80 10  add  %o2, %l0, %g1
a0132414:  7f ff 2c 60  call  0xa00fd594
a0132418:  d2 08 60 0a  ldub  [ %g1 + 0xa ], %o1
a013241c:  d8 04 40 12  ld  [ %l1 + %l2 ], %o4
a0132420:  9f 33 20 0c  srl  %o4, 0xc, %o7
a0132424:  90 0b e0 0f  and  %o7, 0xf, %o0
a0132428:  9a 5a 20 2a  smul  %o0, 0x2a, %o5
a013242c:  a4 03 40 10  add  %o5, %l0, %l2
a0132430:  7f ff 2d 5c  call  0xa00fd9a0
a0132434:  d2 0c a0 0a  ldub  [ %l2 + 0xa ], %o1
a0132438:  10 bf ff dd  b  0xa01323ac
a013243c:  9a 0c e0 ff  and  %l3, 0xff, %o5
a0132440:  9b 2a 20 04  sll  %o0, 4, %o5
a0132444:  a4 23 40 08  sub  %o5, %o0, %l2
a0132448:  a9 2c a0 03  sll  %l2, 3, %l4
a013244c:  b0 17 23 30  or  %i4, 0x330, %i0
a0132450:  fa 06 00 14  ld  [ %i0 + %l4 ], %i5
a0132454:  b5 37 60 0c  srl  %i5, 0xc, %i2
a0132458:  b2 0e a0 0f  and  %i2, 0xf, %i1
a013245c:  96 5e 60 2a  smul  %i1, 0x2a, %o3
a0132460:  ae 16 e2 24  or  %i3, 0x224, %l7
a0132464:  a2 02 c0 17  add  %o3, %l7, %l1
a0132468:  e6 0c 60 0a  ldub  [ %l1 + 0xa ], %l3
a013246c:  7f ff 30 0e  call  0xa00fe4a4
a0132470:  92 10 00 13  mov  %l3, %o1
a0132474:  d0 0f bf f7  ldub  [ %fp + -9 ], %o0
a0132478:  7f ff 2c 47  call  0xa00fd594
a013247c:  92 10 20 b1  mov  0xb1, %o1
a0132480:  d0 0f bf f7  ldub  [ %fp + -9 ], %o0
a0132484:  7f ff 2d 47  call  0xa00fd9a0
a0132488:  92 10 20 b1  mov  0xb1, %o1
a013248c:  40 00 16 38  call  0xa0137d6c
a0132490:  90 10 00 13  mov  %l3, %o0
a0132494:  f6 0f bf f7  ldub  [ %fp + -9 ], %i3
a0132498:  10 bf fd e3  b  0xa0131c24
a013249c:  f6 2d a0 4c  stb  %i3, [ %l6 + 0x4c ]
a01324a0:  13 2a 00 a9  sethi  %hi(0xa802a400), %o1
a01324a4:  ec 0a 60 4d  ldub  [ %o1 + 0x4d ], %l6	! 0xa802a44d
a01324a8:  80 a5 80 0b  cmp  %l6, %o3
a01324ac:  02 80 00 3b  be  0xa0132598
a01324b0:  2d 2a 00 a9  sethi  %hi(0xa802a400), %l6
a01324b4:  e0 0d a0 4c  ldub  [ %l6 + 0x4c ], %l0	! 0xa802a44c
a01324b8:  80 a4 20 ff  cmp  %l0, 0xff
a01324bc:  02 80 00 38  be  0xa013259c
a01324c0:  a7 2a e0 03  sll  %o3, 3, %l3
a01324c4:  10 bf fd cf  b  0xa0131c00
a01324c8:  94 10 20 03  mov  3, %o2
a01324cc:  97 32 60 0c  srl  %o1, 0xc, %o3
a01324d0:  40 00 33 4d  call  0xa013f204
a01324d4:  90 0a e0 0f  and  %o3, 0xf, %o0
a01324d8:  da 04 40 1a  ld  [ %l1 + %i2 ], %o5
a01324dc:  b0 10 00 08  mov  %o0, %i0
a01324e0:  99 33 60 0c  srl  %o5, 0xc, %o4
a01324e4:  40 00 36 f6  call  0xa01400bc
a01324e8:  90 0b 20 0f  and  %o4, 0xf, %o0
a01324ec:  a0 0e 20 ff  and  %i0, 0xff, %l0
a01324f0:  9e 0a 20 ff  and  %o0, 0xff, %o7
a01324f4:  80 a4 00 0f  cmp  %l0, %o7
a01324f8:  32 bf fe 22  bne,a   0xa0131d80
a01324fc:  d8 04 40 13  ld  [ %l1 + %l3 ], %o4
a0132500:  da 04 40 1a  ld  [ %l1 + %i2 ], %o5
a0132504:  a7 33 60 0c  srl  %o5, 0xc, %l3
a0132508:  40 00 36 e4  call  0xa0140098
a013250c:  90 0c e0 0f  and  %l3, 0xf, %o0
a0132510:  80 8a 20 ff  btst  0xff, %o0
a0132514:  12 80 00 14  bne  0xa0132564
a0132518:  90 10 00 12  mov  %l2, %o0
a013251c:  d2 04 40 1a  ld  [ %l1 + %i2 ], %o1
a0132520:  97 32 60 0c  srl  %o1, 0xc, %o3
a0132524:  40 00 36 e6  call  0xa01400bc
a0132528:  90 0a e0 0f  and  %o3, 0xf, %o0
a013252c:  80 8a 20 ff  btst  0xff, %o0
a0132530:  12 80 00 0d  bne  0xa0132564
a0132534:  90 10 00 12  mov  %l2, %o0
a0132538:  c2 04 40 1a  ld  [ %l1 + %i2 ], %g1
a013253c:  a1 30 60 0c  srl  %g1, 0xc, %l0
a0132540:  9e 0c 20 0f  and  %l0, 0xf, %o7
a0132544:  90 16 e2 24  or  %i3, 0x224, %o0
a0132548:  94 5b e0 2a  smul  %o7, 0x2a, %o2
a013254c:  e2 12 00 0a  lduh  [ %o0 + %o2 ], %l1
a0132550:  90 10 00 12  mov  %l2, %o0
a0132554:  80 8c 60 10  btst  0x10, %l1
a0132558:  02 80 00 04  be  0xa0132568
a013255c:  92 10 20 00  clr  %o1
a0132560:  90 10 00 12  mov  %l2, %o0
a0132564:  92 10 20 01  mov  1, %o1
a0132568:  7f ff fb 5b  call  0xa01312d4
a013256c:  b1 2c a0 04  sll  %l2, 4, %i0
a0132570:  10 bf fc 22  b  0xa01315f8
a0132574:  a0 26 00 12  sub  %i0, %l2, %l0
a0132578:  a9 36 20 0c  srl  %i0, 0xc, %l4
a013257c:  7f ff 51 8b  call  0xa0106ba8
a0132580:  90 0d 20 0f  and  %l4, 0xf, %o0
a0132584:  10 bf ff a0  b  0xa0132404
a0132588:  d2 04 40 12  ld  [ %l1 + %l2 ], %o1
a013258c:  40 00 14 e5  call  0xa0137920
a0132590:  01 00 00 00  nop
a0132594:  30 bf fd 6a  b,a   0xa0131b3c
a0132598:  a7 2a e0 03  sll  %o3, 3, %l3
a013259c:  82 04 c0 0b  add  %l3, %o3, %g1
a01325a0:  98 15 21 16  or  %l4, 0x116, %o4
a01325a4:  a2 00 40 01  add  %g1, %g1, %l1
a01325a8:  de 13 00 11  lduh  [ %o4 + %l1 ], %o7
a01325ac:  80 8b e0 20  btst  0x20, %o7
a01325b0:  02 bf fd 95  be  0xa0131c04
a01325b4:  aa 10 00 0a  mov  %o2, %l5
a01325b8:  d4 0d a0 4c  ldub  [ %l6 + 0x4c ], %o2
a01325bc:  80 a0 00 0a  cmp  %g0, %o2
a01325c0:  d0 2a 60 4d  stb  %o0, [ %o1 + 0x4d ]
a01325c4:  c0 2f bf f7  clrb  [ %fp + -9 ]
a01325c8:  10 bf fd 8e  b  0xa0131c00
a01325cc:  94 40 20 00  addx  %g0, 0, %o2
a01325d0:  e0 04 60 64  ld  [ %l1 + 0x64 ], %l0
a01325d4:  80 a3 c0 10  cmp  %o7, %l0
a01325d8:  28 bf fd 0a  bleu,a   0xa0131a00
a01325dc:  c2 02 e0 18  ld  [ %o3 + 0x18 ], %g1
a01325e0:  94 12 63 78  or  %o1, 0x378, %o2
a01325e4:  d6 02 a0 1c  ld  [ %o2 + 0x1c ], %o3
a01325e8:  d6 23 a0 5c  st  %o3, [ %sp + 0x5c ]
a01325ec:  13 00 06 94  sethi  %hi(0x1a5000), %o1
a01325f0:  90 12 62 b8  or  %o1, 0x2b8, %o0	! 0x1a52b8
a01325f4:  d6 02 a0 10  ld  [ %o2 + 0x10 ], %o3
a01325f8:  d8 02 a0 14  ld  [ %o2 + 0x14 ], %o4
a01325fc:  da 02 a0 18  ld  [ %o2 + 0x18 ], %o5
a0132600:  d4 04 60 64  ld  [ %l1 + 0x64 ], %o2
a0132604:  7f fe b2 db  call  0xa00df170
a0132608:  d2 04 60 60  ld  [ %l1 + 0x60 ], %o1
a013260c:  10 bf fd 03  b  0xa0131a18
a0132610:  94 10 20 01  mov  1, %o2
a0132614:  e6 07 63 d0  ld  [ %i5 + 0x3d0 ], %l3
a0132618:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a013261c:  a0 16 21 a0  or  %i0, 0x1a0, %l0	! 0xa802e1a0
a0132620:  95 34 e0 1b  srl  %l3, 0x1b, %o2
a0132624:  17 00 06 8c  sethi  %hi(0x1a3000), %o3
a0132628:  e6 12 e0 da  lduh  [ %o3 + 0xda ], %l3	! 0x1a30da
a013262c:  90 0a a0 01  and  %o2, 1, %o0
a0132630:  b0 17 63 d0  or  %i5, 0x3d0, %i0
a0132634:  d4 0c 20 07  ldub  [ %l0 + 7 ], %o2
a0132638:  d6 14 60 54  lduh  [ %l1 + 0x54 ], %o3
a013263c:  de 06 20 04  ld  [ %i0 + 4 ], %o7
a0132640:  c2 0e 20 03  ldub  [ %i0 + 3 ], %g1
a0132644:  d0 23 a0 60  st  %o0, [ %sp + 0x60 ]
a0132648:  13 00 06 94  sethi  %hi(0x1a5000), %o1
a013264c:  90 12 62 e8  or  %o1, 0x2e8, %o0	! 0x1a52e8
a0132650:  9b 33 e0 1c  srl  %o7, 0x1c, %o5
a0132654:  98 10 00 13  mov  %l3, %o4
a0132658:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a013265c:  7f fe b2 c5  call  0xa00df170
a0132660:  92 10 20 00  clr  %o1
a0132664:  da 0c 20 07  ldub  [ %l0 + 7 ], %o5
a0132668:  80 a0 00 0d  cmp  %g0, %o5
a013266c:  96 60 3f ff  subx  %g0, -1, %o3
a0132670:  98 1b 60 02  xor  %o5, 2, %o4
a0132674:  80 a0 00 0c  cmp  %g0, %o4
a0132678:  94 60 3f ff  subx  %g0, -1, %o2
a013267c:  80 92 c0 0a  orcc  %o3, %o2, %g0
a0132680:  02 80 00 0f  be  0xa01326bc
a0132684:  03 00 06 94  sethi  %hi(0x1a5000), %g1
a0132688:  d8 14 60 54  lduh  [ %l1 + 0x54 ], %o4
a013268c:  80 a3 00 13  cmp  %o4, %l3
a0132690:  0a 80 00 0b  bcs  0xa01326bc
a0132694:  01 00 00 00  nop
a0132698:  da 06 20 04  ld  [ %i0 + 4 ], %o5
a013269c:  80 8b 40 12  btst  %o5, %l2
a01326a0:  12 80 00 07  bne  0xa01326bc
a01326a4:  1f 02 00 00  sethi  %hi(0x8000000), %o7
a01326a8:  e0 07 63 d0  ld  [ %i5 + 0x3d0 ], %l0
a01326ac:  a4 13 e0 ff  or  %o7, 0xff, %l2
a01326b0:  80 8c 00 12  btst  %l0, %l2
a01326b4:  02 bf fc e7  be  0xa0131a50
a01326b8:  13 00 06 94  sethi  %hi(0x1a5000), %o1
a01326bc:  7f fe b2 ad  call  0xa00df170
a01326c0:  90 10 63 08  or  %g1, 0x308, %o0
a01326c4:  c2 04 40 00  ld  [ %l1 ], %g1
a01326c8:  80 88 60 01  btst  1, %g1
a01326cc:  22 80 00 06  be,a   0xa01326e4
a01326d0:  82 08 7f fe  and  %g1, -2, %g1
a01326d4:  27 3f c3 ff  sethi  %hi(0xff0ffc00), %l3
a01326d8:  96 14 e3 ff  or  %l3, 0x3ff, %o3	! 0xff0fffff
a01326dc:  82 08 40 0b  and  %g1, %o3, %g1
a01326e0:  82 08 7f fe  and  %g1, -2, %g1
a01326e4:  10 bf fc e6  b  0xa0131a7c
a01326e8:  c2 24 40 00  st  %g1, [ %l1 ]
a01326ec:  c2 04 60 64  ld  [ %l1 + 0x64 ], %g1
a01326f0:  80 a0 40 08  cmp  %g1, %o0
a01326f4:  08 bf fc ca  bleu  0xa0131a1c
a01326f8:  80 8a a0 ff  btst  0xff, %o2
a01326fc:  10 bf ff ba  b  0xa01325e4
a0132700:  94 12 63 78  or  %o1, 0x378, %o2
a0132704:  2a bf fb d8  bcs,a   0xa0131664
a0132708:  99 2c a0 04  sll  %l2, 4, %o4
a013270c:  13 1f ff ff  sethi  %hi(0x7ffffc00), %o1
a0132710:  a2 12 63 ff  or  %o1, 0x3ff, %l1	! 0x7fffffff
a0132714:  9a 0b 00 11  and  %o4, %l1, %o5
a0132718:  da 22 a0 70  st  %o5, [ %o2 + 0x70 ]
a013271c:  da 03 c0 0b  ld  [ %o7 + %o3 ], %o5
a0132720:  99 33 60 1c  srl  %o5, 0x1c, %o4
a0132724:  80 a3 20 05  cmp  %o4, 5
a0132728:  28 bf fe b0  bleu,a   0xa01321e8
a013272c:  d4 04 20 70  ld  [ %l0 + 0x70 ], %o2
a0132730:  82 0b 40 08  and  %o5, %o0, %g1
a0132734:  1b 18 00 00  sethi  %hi(0x60000000), %o5
a0132738:  19 3f c3 ff  sethi  %hi(0xff0ffc00), %o4
a013273c:  90 10 40 0d  or  %g1, %o5, %o0
a0132740:  b0 13 23 ff  or  %o4, 0x3ff, %i0
a0132744:  94 0a 00 18  and  %o0, %i0, %o2
a0132748:  a7 32 a0 0c  srl  %o2, 0xc, %l3
a013274c:  d4 23 c0 0b  st  %o2, [ %o7 + %o3 ]
a0132750:  7f ff 51 16  call  0xa0106ba8
a0132754:  90 0c e0 0f  and  %l3, 0xf, %o0
a0132758:  10 bf fe a4  b  0xa01321e8
a013275c:  d4 04 20 70  ld  [ %l0 + 0x70 ], %o2
a0132760:  81 c7 e0 08  ret
a0132764:  81 e8 00 00  restore
