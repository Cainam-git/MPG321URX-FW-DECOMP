# leon2m FUN_a002f550 0xa002f550-0xa002f8d8 (904 bytes)
a002f550:  9d e3 bf 98  save  %sp, -104, %sp
a002f554:  58 02 9d f3  call  0xd6d20
a002f558:  90 10 20 00  clr  %o0
a002f55c:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a002f560:  d8 14 21 16  lduh  [ %l0 + 0x116 ], %o4	! 0xa802e116
a002f564:  91 2b 20 10  sll  %o4, 0x10, %o0
a002f568:  83 32 20 1c  srl  %o0, 0x1c, %g1
a002f56c:  80 a0 60 05  cmp  %g1, 5
a002f570:  02 80 00 90  be  0xa002f7b0
a002f574:  15 00 00 3c  sethi  %hi(0xf000), %o2
a002f578:  58 02 9d ea  call  0xd6d20
a002f57c:  90 10 20 01  mov  1, %o0
a002f580:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a002f584:  d8 14 21 28  lduh  [ %l0 + 0x128 ], %o4	! 0xa802e128
a002f588:  a5 2b 20 10  sll  %o4, 0x10, %l2
a002f58c:  a3 34 a0 1c  srl  %l2, 0x1c, %l1
a002f590:  80 a4 60 05  cmp  %l1, 5
a002f594:  02 80 00 80  be  0xa002f794
a002f598:  11 00 00 3c  sethi  %hi(0xf000), %o0
a002f59c:  58 02 9d e1  call  0xd6d20
a002f5a0:  90 10 20 02  mov  2, %o0
a002f5a4:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a002f5a8:  23 00 00 3c  sethi  %hi(0xf000), %l1
a002f5ac:  d8 14 21 3a  lduh  [ %l0 + 0x13a ], %o4
a002f5b0:  9e 0b 00 11  and  %o4, %l1, %o7
a002f5b4:  17 00 00 14  sethi  %hi(0x5000), %o3
a002f5b8:  80 a3 c0 0b  cmp  %o7, %o3
a002f5bc:  02 80 00 06  be  0xa002f5d4
a002f5c0:  a2 14 21 3a  or  %l0, 0x13a, %l1
a002f5c4:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a002f5c8:  c2 0c a0 0b  ldub  [ %l2 + 0xb ], %g1	! 0xa802cc0b
a002f5cc:  a6 08 7f fe  and  %g1, -2, %l3
a002f5d0:  e6 2c a0 0b  stb  %l3, [ %l2 + 0xb ]
a002f5d4:  9b 2b 20 10  sll  %o4, 0x10, %o5
a002f5d8:  99 33 60 1c  srl  %o5, 0x1c, %o4
a002f5dc:  80 a3 20 05  cmp  %o4, 5
a002f5e0:  02 80 00 4b  be  0xa002f70c
a002f5e4:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a002f5e8:  e0 14 40 00  lduh  [ %l1 ], %l0
a002f5ec:  25 00 00 3c  sethi  %hi(0xf000), %l2
a002f5f0:  a2 0c 00 12  and  %l0, %l2, %l1
a002f5f4:  21 00 00 14  sethi  %hi(0x5000), %l0
a002f5f8:  80 a4 40 10  cmp  %l1, %l0
a002f5fc:  02 80 00 05  be  0xa002f610
a002f600:  27 2a 00 b3  sethi  %hi(0xa802cc00), %l3
a002f604:  d8 0c e0 0a  ldub  [ %l3 + 0xa ], %o4	! 0xa802cc0a
a002f608:  82 0b 3f fe  and  %o4, -2, %g1
a002f60c:  c2 2c e0 0a  stb  %g1, [ %l3 + 0xa ]
a002f610:  58 02 9d c4  call  0xd6d20
a002f614:  90 10 20 03  mov  3, %o0
a002f618:  23 2a 00 b8  sethi  %hi(0xa802e000), %l1
a002f61c:  d8 14 61 4c  lduh  [ %l1 + 0x14c ], %o4	! 0xa802e14c
a002f620:  11 00 00 3c  sethi  %hi(0xf000), %o0
a002f624:  9a 0b 00 08  and  %o4, %o0, %o5
a002f628:  80 a3 40 10  cmp  %o5, %l0
a002f62c:  02 80 00 06  be  0xa002f644
a002f630:  a4 14 61 4c  or  %l1, 0x14c, %l2
a002f634:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a002f638:  d6 0a 60 0b  ldub  [ %o1 + 0xb ], %o3	! 0xa802cc0b
a002f63c:  94 0a ff fd  and  %o3, -3, %o2
a002f640:  d4 2a 60 0b  stb  %o2, [ %o1 + 0xb ]
a002f644:  a1 2b 20 10  sll  %o4, 0x10, %l0
a002f648:  9f 34 20 1c  srl  %l0, 0x1c, %o7
a002f64c:  80 a3 e0 05  cmp  %o7, 5
a002f650:  02 80 00 0d  be  0xa002f684
a002f654:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a002f658:  e0 14 80 00  lduh  [ %l2 ], %l0
a002f65c:  17 00 00 3c  sethi  %hi(0xf000), %o3
a002f660:  a4 0c 00 0b  and  %l0, %o3, %l2
a002f664:  23 00 00 14  sethi  %hi(0x5000), %l1
a002f668:  80 a4 80 11  cmp  %l2, %l1
a002f66c:  02 80 00 99  be  0xa002f8d0
a002f670:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a002f674:  d8 0b e0 0a  ldub  [ %o7 + 0xa ], %o4	! 0xa802cc0a
a002f678:  a6 0b 3f fd  and  %o4, -3, %l3
a002f67c:  10 80 00 95  b  0xa002f8d0
a002f680:  e6 2b e0 0a  stb  %l3, [ %o7 + 0xa ]
a002f684:  d8 00 63 d0  ld  [ %g1 + 0x3d0 ], %o4
a002f688:  27 00 02 00  sethi  %hi(0x80000), %l3
a002f68c:  80 8b 00 13  btst  %o4, %l3
a002f690:  22 bf ff f3  be,a   0xa002f65c
a002f694:  e0 14 80 00  lduh  [ %l2 ], %l0
a002f698:  d2 14 a0 02  lduh  [ %l2 + 2 ], %o1
a002f69c:  15 3f ff e0  sethi  %hi(0xffff8000), %o2
a002f6a0:  90 0a 40 0a  and  %o1, %o2, %o0
a002f6a4:  9b 2a 20 10  sll  %o0, 0x10, %o5
a002f6a8:  80 a3 60 00  cmp  %o5, 0
a002f6ac:  22 bf ff ec  be,a   0xa002f65c
a002f6b0:  e0 14 80 00  lduh  [ %l2 ], %l0
a002f6b4:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a002f6b8:  c2 0b 60 0b  ldub  [ %o5 + 0xb ], %g1	! 0xa802cc0b
a002f6bc:  80 88 60 02  btst  2, %g1
a002f6c0:  02 80 00 79  be  0xa002f8a4
a002f6c4:  27 2a 00 b3  sethi  %hi(0xa802cc00), %l3
a002f6c8:  98 14 e0 0c  or  %l3, 0xc, %o4	! 0xa802cc0c
a002f6cc:  7f ff f7 b2  call  0xa002d594
a002f6d0:  d0 13 20 02  lduh  [ %o4 + 2 ], %o0
a002f6d4:  a7 2a 20 10  sll  %o0, 0x10, %l3
a002f6d8:  9f 34 e0 10  srl  %l3, 0x10, %o7
a002f6dc:  80 a3 e3 e7  cmp  %o7, 0x3e7
a002f6e0:  38 bf ff df  bgu,a   0xa002f65c
a002f6e4:  e0 14 80 00  lduh  [ %l2 ], %l0
a002f6e8:  15 00 06 9a  sethi  %hi(0x1a6800), %o2
a002f6ec:  58 01 3e a1  call  0x7f170
a002f6f0:  90 12 a2 c0  or  %o2, 0x2c0, %o0	! 0x1a6ac0
a002f6f4:  d2 14 61 4c  lduh  [ %l1 + 0x14c ], %o1
a002f6f8:  90 0a 6f ff  and  %o1, 0xfff, %o0
a002f6fc:  1b 00 00 08  sethi  %hi(0x2000), %o5
a002f700:  82 12 00 0d  or  %o0, %o5, %g1
a002f704:  10 bf ff d5  b  0xa002f658
a002f708:  c2 34 61 4c  sth  %g1, [ %l1 + 0x14c ]
a002f70c:  d2 02 a3 d0  ld  [ %o2 + 0x3d0 ], %o1
a002f710:  11 00 02 00  sethi  %hi(0x80000), %o0
a002f714:  80 8a 40 08  btst  %o1, %o0
a002f718:  22 bf ff b5  be,a   0xa002f5ec
a002f71c:  e0 14 40 00  lduh  [ %l1 ], %l0
a002f720:  e4 14 60 02  lduh  [ %l1 + 2 ], %l2
a002f724:  27 3f ff e0  sethi  %hi(0xffff8000), %l3
a002f728:  9e 0c 80 13  and  %l2, %l3, %o7
a002f72c:  97 2b e0 10  sll  %o7, 0x10, %o3
a002f730:  80 a2 e0 00  cmp  %o3, 0
a002f734:  22 bf ff ae  be,a   0xa002f5ec
a002f738:  e0 14 40 00  lduh  [ %l1 ], %l0
a002f73c:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a002f740:  c2 0b 60 0b  ldub  [ %o5 + 0xb ], %g1	! 0xa802cc0b
a002f744:  80 88 60 01  btst  1, %g1
a002f748:  02 80 00 5d  be  0xa002f8bc
a002f74c:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a002f750:  7f ff f7 91  call  0xa002d594
a002f754:  d0 14 a0 0c  lduh  [ %l2 + 0xc ], %o0	! 0xa802cc0c
a002f758:  9b 2a 20 10  sll  %o0, 0x10, %o5
a002f75c:  99 33 60 10  srl  %o5, 0x10, %o4
a002f760:  80 a3 23 e7  cmp  %o4, 0x3e7
a002f764:  38 bf ff a2  bgu,a   0xa002f5ec
a002f768:  e0 14 40 00  lduh  [ %l1 ], %l0
a002f76c:  1f 00 06 9a  sethi  %hi(0x1a6800), %o7
a002f770:  90 13 e2 c0  or  %o7, 0x2c0, %o0	! 0x1a6ac0
a002f774:  58 01 3e 7f  call  0x7f170
a002f778:  01 00 00 00  nop
a002f77c:  d6 14 21 3a  lduh  [ %l0 + 0x13a ], %o3
a002f780:  92 0a ef ff  and  %o3, 0xfff, %o1
a002f784:  15 00 00 08  sethi  %hi(0x2000), %o2
a002f788:  90 12 40 0a  or  %o1, %o2, %o0
a002f78c:  10 bf ff 97  b  0xa002f5e8
a002f790:  d0 34 21 3a  sth  %o0, [ %l0 + 0x13a ]
a002f794:  82 0b 00 08  and  %o4, %o0, %g1
a002f798:  27 00 00 14  sethi  %hi(0x5000), %l3
a002f79c:  80 a0 40 13  cmp  %g1, %l3
a002f7a0:  02 80 00 0b  be  0xa002f7cc
a002f7a4:  82 0b 39 ff  and  %o4, -1537, %g1
a002f7a8:  10 bf ff 7d  b  0xa002f59c
a002f7ac:  c2 34 21 28  sth  %g1, [ %l0 + 0x128 ]
a002f7b0:  92 0b 00 0a  and  %o4, %o2, %o1
a002f7b4:  1b 00 00 14  sethi  %hi(0x5000), %o5
a002f7b8:  80 a2 40 0d  cmp  %o1, %o5
a002f7bc:  02 80 00 1f  be  0xa002f838
a002f7c0:  82 0b 39 ff  and  %o4, -1537, %g1
a002f7c4:  10 bf ff 6d  b  0xa002f578
a002f7c8:  c2 34 21 16  sth  %g1, [ %l0 + 0x116 ]
a002f7cc:  58 02 05 e0  call  0xb0f4c
a002f7d0:  90 10 20 03  mov  3, %o0
a002f7d4:  82 0a 20 01  and  %o0, 1, %g1
a002f7d8:  e6 14 21 28  lduh  [ %l0 + 0x128 ], %l3
a002f7dc:  a5 28 60 0a  sll  %g1, 0xa, %l2
a002f7e0:  a2 0c fb ff  and  %l3, -1025, %l1
a002f7e4:  9e 14 40 12  or  %l1, %l2, %o7
a002f7e8:  de 34 21 28  sth  %o7, [ %l0 + 0x128 ]
a002f7ec:  58 02 05 d8  call  0xb0f4c
a002f7f0:  90 10 20 03  mov  3, %o0
a002f7f4:  d6 14 21 28  lduh  [ %l0 + 0x128 ], %o3
a002f7f8:  98 0a 20 01  and  %o0, 1, %o4
a002f7fc:  95 2b 20 09  sll  %o4, 9, %o2
a002f800:  92 0a fd ff  and  %o3, -513, %o1
a002f804:  9a 12 40 0a  or  %o1, %o2, %o5
a002f808:  80 8b 62 00  btst  0x200, %o5
a002f80c:  02 bf ff 64  be  0xa002f59c
a002f810:  da 34 21 28  sth  %o5, [ %l0 + 0x128 ]
a002f814:  58 02 05 d0  call  0xb0f54
a002f818:  90 10 20 03  mov  3, %o0
a002f81c:  d2 14 21 28  lduh  [ %l0 + 0x128 ], %o1
a002f820:  94 0a 20 01  and  %o0, 1, %o2
a002f824:  91 2a a0 08  sll  %o2, 8, %o0
a002f828:  9a 0a 7e ff  and  %o1, -257, %o5
a002f82c:  82 13 40 08  or  %o5, %o0, %g1
a002f830:  10 bf ff 5b  b  0xa002f59c
a002f834:  c2 34 21 28  sth  %g1, [ %l0 + 0x128 ]
a002f838:  58 02 05 c5  call  0xb0f4c
a002f83c:  90 10 20 02  mov  2, %o0
a002f840:  da 14 21 16  lduh  [ %l0 + 0x116 ], %o5
a002f844:  92 0a 20 01  and  %o0, 1, %o1
a002f848:  91 2a 60 0a  sll  %o1, 0xa, %o0
a002f84c:  82 0b 7b ff  and  %o5, -1025, %g1
a002f850:  a6 10 40 08  or  %g1, %o0, %l3
a002f854:  e6 34 21 16  sth  %l3, [ %l0 + 0x116 ]
a002f858:  58 02 05 bd  call  0xb0f4c
a002f85c:  90 10 20 02  mov  2, %o0
a002f860:  e2 14 21 16  lduh  [ %l0 + 0x116 ], %l1
a002f864:  a4 0a 20 01  and  %o0, 1, %l2
a002f868:  9f 2c a0 09  sll  %l2, 9, %o7
a002f86c:  98 0c 7d ff  and  %l1, -513, %o4
a002f870:  96 13 00 0f  or  %o4, %o7, %o3
a002f874:  80 8a e2 00  btst  0x200, %o3
a002f878:  02 bf ff 40  be  0xa002f578
a002f87c:  d6 34 21 16  sth  %o3, [ %l0 + 0x116 ]
a002f880:  58 02 05 b5  call  0xb0f54
a002f884:  90 10 20 02  mov  2, %o0
a002f888:  d8 14 21 16  lduh  [ %l0 + 0x116 ], %o4
a002f88c:  9e 0a 20 01  and  %o0, 1, %o7
a002f890:  97 2b e0 08  sll  %o7, 8, %o3
a002f894:  94 0b 3e ff  and  %o4, -257, %o2
a002f898:  82 12 80 0b  or  %o2, %o3, %g1
a002f89c:  10 bf ff 37  b  0xa002f578
a002f8a0:  c2 34 21 16  sth  %g1, [ %l0 + 0x116 ]
a002f8a4:  96 10 60 02  or  %g1, 2, %o3
a002f8a8:  d6 2b 60 0b  stb  %o3, [ %o5 + 0xb ]
a002f8ac:  7f ff f7 37  call  0xa002d588
a002f8b0:  a0 14 e0 0c  or  %l3, 0xc, %l0
a002f8b4:  10 bf ff 85  b  0xa002f6c8
a002f8b8:  d0 34 20 02  sth  %o0, [ %l0 + 2 ]
a002f8bc:  82 10 60 01  or  %g1, 1, %g1
a002f8c0:  7f ff f7 32  call  0xa002d588
a002f8c4:  c2 2b 60 0b  stb  %g1, [ %o5 + 0xb ]
a002f8c8:  10 bf ff a2  b  0xa002f750
a002f8cc:  d0 34 a0 0c  sth  %o0, [ %l2 + 0xc ]
a002f8d0:  81 c7 e0 08  ret
a002f8d4:  81 e8 00 00  restore
