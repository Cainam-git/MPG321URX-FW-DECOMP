# leon2m FUN_a01295e4 0xa01295e4-0xa0129810 (556 bytes)
a01295e4:  9d e3 bf 98  save  %sp, -104, %sp
a01295e8:  31 2a 00 b6  sethi  %hi(0xa802d800), %i0
a01295ec:  c2 16 20 92  lduh  [ %i0 + 0x92 ], %g1	! 0xa802d892
a01295f0:  83 30 60 0c  srl  %g1, 0xc, %g1
a01295f4:  80 a0 60 02  cmp  %g1, 2
a01295f8:  a0 10 00 18  mov  %i0, %l0
a01295fc:  02 80 00 1a  be  0xa0129664
a0129600:  a2 16 20 92  or  %i0, 0x92, %l1
a0129604:  80 a0 60 02  cmp  %g1, 2
a0129608:  04 80 00 0d  ble  0xa012963c
a012960c:  80 a0 60 01  cmp  %g1, 1
a0129610:  80 a0 60 03  cmp  %g1, 3
a0129614:  02 80 00 38  be  0xa01296f4
a0129618:  01 00 00 00  nop
a012961c:  7f ff ec 83  call  0xa0124828
a0129620:  01 00 00 00  nop
a0129624:  90 0a 20 ff  and  %o0, 0xff, %o0
a0129628:  80 a2 20 01  cmp  %o0, 1
a012962c:  12 80 00 77  bne  0xa0129808
a0129630:  de 14 20 92  lduh  [ %l0 + 0x92 ], %o7
a0129634:  10 80 00 22  b  0xa01296bc
a0129638:  98 0b e3 ff  and  %o7, 0x3ff, %o4
a012963c:  12 bf ff f8  bne  0xa012961c
a0129640:  01 00 00 00  nop
a0129644:  7f ff ec 79  call  0xa0124828
a0129648:  01 00 00 00  nop
a012964c:  80 8a 20 ff  btst  0xff, %o0
a0129650:  12 80 00 38  bne  0xa0129730
a0129654:  d8 16 20 92  lduh  [ %i0 + 0x92 ], %o4
a0129658:  96 0b 2f ff  and  %o4, 0xfff, %o3
a012965c:  10 80 00 6b  b  0xa0129808
a0129660:  d6 36 20 92  sth  %o3, [ %i0 + 0x92 ]
a0129664:  7f ff ec 71  call  0xa0124828
a0129668:  01 00 00 00  nop
a012966c:  80 8a 20 ff  btst  0xff, %o0
a0129670:  02 bf ff fa  be  0xa0129658
a0129674:  d8 16 20 92  lduh  [ %i0 + 0x92 ], %o4
a0129678:  d4 16 20 92  lduh  [ %i0 + 0x92 ], %o2
a012967c:  92 0a ac 00  and  %o2, 0xc00, %o1
a0129680:  80 a2 68 00  cmp  %o1, 0x800
a0129684:  02 80 00 4a  be  0xa01297ac
a0129688:  1f 00 06 93  sethi  %hi(0x1a4c00), %o7
a012968c:  90 13 e2 20  or  %o7, 0x220, %o0	! 0x1a4e20
a0129690:  7f fe d6 b8  call  0xa00df170
a0129694:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a0129698:  7f ff f4 1b  call  0xa0126704
a012969c:  d0 0c 60 01  ldub  [ %l1 + 1 ], %o0
a01296a0:  da 16 20 92  lduh  [ %i0 + 0x92 ], %o5
a01296a4:  98 13 68 00  or  %o5, 0x800, %o4
a01296a8:  96 0b 3b ff  and  %o4, -1025, %o3
a01296ac:  67 fd 8f b7  call  0x4008d588
a01296b0:  d6 36 20 92  sth  %o3, [ %i0 + 0x92 ]
a01296b4:  10 80 00 55  b  0xa0129808
a01296b8:  d0 34 60 02  sth  %o0, [ %l1 + 2 ]
a01296bc:  1b 00 00 04  sethi  %hi(0x1000), %o5
a01296c0:  96 13 00 0d  or  %o4, %o5, %o3
a01296c4:  67 fd 8f b1  call  0x4008d588
a01296c8:  d6 34 20 92  sth  %o3, [ %l0 + 0x92 ]
a01296cc:  94 14 20 92  or  %l0, 0x92, %o2
a01296d0:  7f fd 5b 35  call  0xa00803a4
a01296d4:  d0 32 a0 02  sth  %o0, [ %o2 + 2 ]
a01296d8:  92 0a 20 ff  and  %o0, 0xff, %o1
a01296dc:  80 a2 60 01  cmp  %o1, 1
a01296e0:  02 80 00 23  be  0xa012976c
a01296e4:  31 00 06 93  sethi  %hi(0x1a4c00), %i0
a01296e8:  b0 16 22 40  or  %i0, 0x240, %i0	! 0x1a4e40
a01296ec:  7f fe d6 a1  call  0xa00df170
a01296f0:  81 e8 00 00  restore
a01296f4:  7f ff ec 4d  call  0xa0124828
a01296f8:  01 00 00 00  nop
a01296fc:  80 8a 20 ff  btst  0xff, %o0
a0129700:  02 bf ff d6  be  0xa0129658
a0129704:  d8 16 20 92  lduh  [ %i0 + 0x92 ], %o4
a0129708:  c2 16 20 92  lduh  [ %i0 + 0x92 ], %g1
a012970c:  80 88 64 00  btst  0x400, %g1
a0129710:  02 80 00 3e  be  0xa0129808
a0129714:  a0 08 6f ff  and  %g1, 0xfff, %l0
a0129718:  23 00 00 08  sethi  %hi(0x2000), %l1
a012971c:  9e 14 00 11  or  %l0, %l1, %o7
a0129720:  de 36 20 92  sth  %o7, [ %i0 + 0x92 ]
a0129724:  1b 00 06 93  sethi  %hi(0x1a4c00), %o5
a0129728:  7f fe d6 92  call  0xa00df170
a012972c:  91 eb 62 60  restore  %o5, 0x260, %o0
a0129730:  67 fd 8f 99  call  0x4008d594
a0129734:  d0 14 60 02  lduh  [ %l1 + 2 ], %o0
a0129738:  83 2a 20 10  sll  %o0, 0x10, %g1
a012973c:  a3 30 60 10  srl  %g1, 0x10, %l1
a0129740:  80 a4 61 f4  cmp  %l1, 0x1f4
a0129744:  08 80 00 31  bleu  0xa0129808
a0129748:  01 00 00 00  nop
a012974c:  7f ff ec 5f  call  0xa01248c8
a0129750:  01 00 00 00  nop
a0129754:  90 0a 20 ff  and  %o0, 0xff, %o0
a0129758:  80 a2 20 01  cmp  %o0, 1
a012975c:  12 80 00 2b  bne  0xa0129808
a0129760:  c2 16 20 92  lduh  [ %i0 + 0x92 ], %g1
a0129764:  10 bf ff ed  b  0xa0129718
a0129768:  a0 08 6f ff  and  %g1, 0xfff, %l0
a012976c:  7f ff 7d ba  call  0xa0108e54
a0129770:  01 00 00 00  nop
a0129774:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0129778:  80 a4 20 01  cmp  %l0, 1
a012977c:  02 80 00 1a  be  0xa01297e4
a0129780:  01 00 00 00  nop
a0129784:  92 10 20 01  mov  1, %o1	! 0x1
a0129788:  94 10 20 01  mov  1, %o2
a012978c:  7f fe c5 2b  call  0xa00dac38
a0129790:  90 10 20 01  mov  1, %o0
a0129794:  7f ff 63 18  call  0xa01023f4
a0129798:  90 10 20 00  clr  %o0
a012979c:  7f ff 65 f4  call  0xa0102f6c
a01297a0:  31 00 06 93  sethi  %hi(0x1a4c00), %i0
a01297a4:  10 bf ff d2  b  0xa01296ec
a01297a8:  b0 16 22 40  or  %i0, 0x240, %i0	! 0x1a4e40
a01297ac:  67 fd 8f 7a  call  0x4008d594
a01297b0:  d0 14 60 02  lduh  [ %l1 + 2 ], %o0
a01297b4:  a3 2a 20 10  sll  %o0, 0x10, %l1
a01297b8:  a1 34 60 10  srl  %l1, 0x10, %l0
a01297bc:  80 a4 21 f4  cmp  %l0, 0x1f4
a01297c0:  08 80 00 12  bleu  0xa0129808
a01297c4:  d4 16 20 92  lduh  [ %i0 + 0x92 ], %o2
a01297c8:  90 0a af ff  and  %o2, 0xfff, %o0
a01297cc:  13 00 00 0c  sethi  %hi(0x3000), %o1
a01297d0:  82 12 00 09  or  %o0, %o1, %g1
a01297d4:  c2 36 20 92  sth  %g1, [ %i0 + 0x92 ]
a01297d8:  31 00 06 93  sethi  %hi(0x1a4c00), %i0
a01297dc:  7f fe d6 65  call  0xa00df170
a01297e0:  91 ee 22 80  restore  %i0, 0x280, %o0
a01297e4:  40 00 4d 71  call  0xa013cda8
a01297e8:  90 10 20 00  clr  %o0
a01297ec:  90 0a 20 ff  and  %o0, 0xff, %o0
a01297f0:  7f ff 7b 2e  call  0xa01084a8
a01297f4:  92 10 20 00  clr  %o1
a01297f8:  7f ff 7e 46  call  0xa0109110
a01297fc:  90 10 20 00  clr  %o0
a0129800:  10 bf ff e2  b  0xa0129788
a0129804:  92 10 20 01  mov  1, %o1
a0129808:  81 c7 e0 08  ret
a012980c:  81 e8 00 00  restore
