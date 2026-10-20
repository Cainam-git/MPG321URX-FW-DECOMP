# leon2s FUN_a00cd5e4 0xa00cd5e4-0xa00cdb0c (1320 bytes)
a00cd5e4:  9d e3 bf 78  save  %sp, -136, %sp
a00cd5e8:  aa 0e 20 ff  and  %i0, 0xff, %l5
a00cd5ec:  82 05 40 15  add  %l5, %l5, %g1
a00cd5f0:  82 00 40 15  add  %g1, %l5, %g1
a00cd5f4:  a1 28 60 03  sll  %g1, 3, %l0
a00cd5f8:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00cd5fc:  2d 2a 01 e2  sethi  %hi(0xa8078800), %l6
a00cd600:  a2 15 a3 b0  or  %l6, 0x3b0, %l1	! 0xa8078bb0
a00cd604:  a4 10 63 ff  or  %g1, 0x3ff, %l2
a00cd608:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cd60c:  9a 08 40 12  and  %g1, %l2, %o5
a00cd610:  03 00 00 40  sethi  %hi(0x10000), %g1
a00cd614:  9a 13 40 01  or  %o5, %g1, %o5
a00cd618:  83 33 60 1c  srl  %o5, 0x1c, %g1
a00cd61c:  80 88 60 01  btst  1, %g1
a00cd620:  12 80 00 04  bne  0xa00cd630
a00cd624:  da 24 40 10  st  %o5, [ %l1 + %l0 ]
a00cd628:  10 80 00 1c  b  0xa00cd698
a00cd62c:  82 0b 40 12  and  %o5, %l2, %g1
a00cd630:  15 00 01 a0  sethi  %hi(0x68000), %o2
a00cd634:  94 12 a0 2a  or  %o2, 0x2a, %o2	! 0x6802a
a00cd638:  90 10 20 00  clr  %o0
a00cd63c:  92 10 20 90  mov  0x90, %o1
a00cd640:  96 10 20 01  mov  1, %o3
a00cd644:  40 3b 23 6f  call  0xa0f96400
a00cd648:  98 07 bf f0  add  %fp, -16, %o4
a00cd64c:  c2 4f bf f0  ldsb  [ %fp + -16 ], %g1
a00cd650:  80 a0 60 00  cmp  %g1, 0
a00cd654:  16 80 00 06  bge  0xa00cd66c
a00cd658:  da 0f bf f0  ldub  [ %fp + -16 ], %o5
a00cd65c:  9a 04 00 11  add  %l0, %l1, %o5
a00cd660:  82 10 20 01  mov  1, %g1
a00cd664:  10 80 00 09  b  0xa00cd688
a00cd668:  c2 2b 60 05  stb  %g1, [ %o5 + 5 ]
a00cd66c:  d4 0f bf f1  ldub  [ %fp + -15 ], %o2
a00cd670:  82 0a a0 ff  and  %o2, 0xff, %g1
a00cd674:  80 88 60 08  btst  8, %g1
a00cd678:  02 80 00 1b  be  0xa00cd6e4
a00cd67c:  92 04 00 11  add  %l0, %l1, %o1
a00cd680:  82 10 20 01  mov  1, %g1
a00cd684:  c2 2a 60 06  stb  %g1, [ %o1 + 6 ]
a00cd688:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cd68c:  82 08 40 12  and  %g1, %l2, %g1
a00cd690:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00cd694:  82 10 40 0d  or  %g1, %o5, %g1
a00cd698:  10 80 01 1b  b  0xa00cdb04
a00cd69c:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cd6a0:  96 04 80 12  add  %l2, %l2, %o3
a00cd6a4:  96 02 c0 12  add  %o3, %l2, %o3
a00cd6a8:  94 15 a3 b0  or  %l6, 0x3b0, %o2
a00cd6ac:  97 2a e0 03  sll  %o3, 3, %o3
a00cd6b0:  d8 02 80 0b  ld  [ %o2 + %o3 ], %o4
a00cd6b4:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cd6b8:  98 13 00 01  or  %o4, %g1, %o4
a00cd6bc:  83 33 20 18  srl  %o4, 0x18, %g1
a00cd6c0:  82 08 60 0f  and  %g1, 0xf, %g1
a00cd6c4:  82 00 7f ff  add  %g1, -1, %g1
a00cd6c8:  82 08 60 0f  and  %g1, 0xf, %g1
a00cd6cc:  1b 03 c0 00  sethi  %hi(0xf000000), %o5
a00cd6d0:  9a 2b 00 0d  andn  %o4, %o5, %o5
a00cd6d4:  83 28 60 18  sll  %g1, 0x18, %g1
a00cd6d8:  9a 13 40 01  or  %o5, %g1, %o5
a00cd6dc:  10 80 01 0a  b  0xa00cdb04
a00cd6e0:  da 22 80 0b  st  %o5, [ %o2 + %o3 ]
a00cd6e4:  98 0b 60 ff  and  %o5, 0xff, %o4
a00cd6e8:  83 30 60 03  srl  %g1, 3, %g1
a00cd6ec:  82 08 60 01  and  %g1, 1, %g1
a00cd6f0:  9a 0b 60 7f  and  %o5, 0x7f, %o5
a00cd6f4:  c2 2a 60 06  stb  %g1, [ %o1 + 6 ]
a00cd6f8:  da 2a 60 03  stb  %o5, [ %o1 + 3 ]
a00cd6fc:  99 33 20 07  srl  %o4, 7, %o4
a00cd700:  17 33 c0 63  sethi  %hi(0xcf018c00), %o3
a00cd704:  94 0a a0 07  and  %o2, 7, %o2
a00cd708:  d8 2a 60 05  stb  %o4, [ %o1 + 5 ]
a00cd70c:  d4 2a 60 04  stb  %o2, [ %o1 + 4 ]
a00cd710:  9a 12 e2 10  or  %o3, 0x210, %o5
a00cd714:  82 10 20 1f  mov  0x1f, %g1
a00cd718:  c2 23 40 00  st  %g1, [ %o5 ]
a00cd71c:  9a 12 e2 14  or  %o3, 0x214, %o5
a00cd720:  c2 03 40 00  ld  [ %o5 ], %g1
a00cd724:  82 10 60 80  or  %g1, 0x80, %g1
a00cd728:  c2 23 40 00  st  %g1, [ %o5 ]
a00cd72c:  98 10 00 0d  mov  %o5, %o4
a00cd730:  c2 03 00 00  ld  [ %o4 ], %g1
a00cd734:  80 88 60 80  btst  0x80, %g1
a00cd738:  12 bf ff fe  bne  0xa00cd730
a00cd73c:  9a 12 e2 18  or  %o3, 0x218, %o5
a00cd740:  c2 03 40 00  ld  [ %o5 ], %g1
a00cd744:  82 08 7f fe  and  %g1, -2, %g1
a00cd748:  c2 23 40 00  st  %g1, [ %o5 ]
a00cd74c:  9a 12 e2 00  or  %o3, 0x200, %o5
a00cd750:  82 10 20 11  mov  0x11, %g1
a00cd754:  c2 23 40 00  st  %g1, [ %o5 ]
a00cd758:  9a 12 e2 08  or  %o3, 0x208, %o5
a00cd75c:  82 10 20 10  mov  0x10, %g1
a00cd760:  c2 23 40 00  st  %g1, [ %o5 ]
a00cd764:  9a 12 e2 0c  or  %o3, 0x20c, %o5
a00cd768:  82 10 20 3f  mov  0x3f, %g1
a00cd76c:  c2 23 40 00  st  %g1, [ %o5 ]
a00cd770:  c2 03 00 00  ld  [ %o4 ], %g1
a00cd774:  82 10 60 02  or  %g1, 2, %g1
a00cd778:  c2 23 00 00  st  %g1, [ %o4 ]
a00cd77c:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00cd780:  9a 10 62 14  or  %g1, 0x214, %o5	! 0xcf018e14
a00cd784:  c2 03 40 00  ld  [ %o5 ], %g1
a00cd788:  80 88 60 02  btst  2, %g1
a00cd78c:  12 bf ff fe  bne  0xa00cd784
a00cd790:  c2 0f bf f0  ldub  [ %fp + -16 ], %g1
a00cd794:  82 08 60 7f  and  %g1, 0x7f, %g1
a00cd798:  a1 28 60 02  sll  %g1, 2, %l0
a00cd79c:  15 00 00 10  sethi  %hi(0x4000), %o2
a00cd7a0:  a0 04 00 01  add  %l0, %g1, %l0
a00cd7a4:  94 12 a0 15  or  %o2, 0x15, %o2
a00cd7a8:  90 10 00 15  mov  %l5, %o0
a00cd7ac:  7f ff ec 0f  call  0xa00c87e8
a00cd7b0:  92 10 20 0b  mov  0xb, %o1
a00cd7b4:  80 a4 20 00  cmp  %l0, 0
a00cd7b8:  a8 10 00 10  mov  %l0, %l4
a00cd7bc:  a2 10 20 00  clr  %l1
a00cd7c0:  a4 10 00 10  mov  %l0, %l2
a00cd7c4:  02 80 00 31  be  0xa00cd888
a00cd7c8:  83 2c a0 10  sll  %l2, 0x10, %g1
a00cd7cc:  a6 0c 60 ff  and  %l1, 0xff, %l3
a00cd7d0:  83 30 60 10  srl  %g1, 0x10, %g1
a00cd7d4:  80 a4 e0 00  cmp  %l3, 0
a00cd7d8:  12 80 00 14  bne  0xa00cd828
a00cd7dc:  9a 07 bf d8  add  %fp, -40, %o5
a00cd7e0:  96 04 bf ff  add  %l2, -1, %o3
a00cd7e4:  97 2a e0 18  sll  %o3, 0x18, %o3
a00cd7e8:  15 00 01 a0  sethi  %hi(0x68000), %o2
a00cd7ec:  94 12 a0 2c  or  %o2, 0x2c, %o2	! 0x6802c
a00cd7f0:  97 3a e0 18  sra  %o3, 0x18, %o3
a00cd7f4:  98 10 00 0d  mov  %o5, %o4
a00cd7f8:  92 10 20 90  mov  0x90, %o1
a00cd7fc:  80 a0 60 0e  cmp  %g1, 0xe
a00cd800:  08 80 00 08  bleu  0xa00cd820
a00cd804:  90 10 20 00  clr  %o0
a00cd808:  15 00 01 a0  sethi  %hi(0x68000), %o2
a00cd80c:  94 12 a0 2c  or  %o2, 0x2c, %o2	! 0x6802c
a00cd810:  98 10 00 0d  mov  %o5, %o4
a00cd814:  96 10 20 0e  mov  0xe, %o3
a00cd818:  92 10 20 90  mov  0x90, %o1
a00cd81c:  90 10 20 00  clr  %o0
a00cd820:  40 3b 22 f8  call  0xa0f96400
a00cd824:  01 00 00 00  nop
a00cd828:  a0 07 bf f8  add  %fp, -8, %l0
a00cd82c:  a0 04 00 13  add  %l0, %l3, %l0
a00cd830:  90 10 20 aa  mov  0xaa, %o0
a00cd834:  7f ff f2 10  call  0xa00ca074
a00cd838:  d2 0c 3f e0  ldub  [ %l0 + -32 ], %o1
a00cd83c:  90 10 00 15  mov  %l5, %o0
a00cd840:  d4 0c 3f e0  ldub  [ %l0 + -32 ], %o2
a00cd844:  7f ff e7 84  call  0xa00c7654
a00cd848:  92 10 20 01  mov  1, %o1
a00cd84c:  a2 04 60 01  inc  %l1
a00cd850:  03 22 22 22  sethi  %hi(0x88888800), %g1
a00cd854:  96 0c 60 ff  and  %l1, 0xff, %o3
a00cd858:  82 10 60 89  or  %g1, 0x89, %g1
a00cd85c:  80 52 c0 01  umul  %o3, %g1, %g0
a00cd860:  83 40 00 00  rd  %y, %g1
a00cd864:  83 30 60 03  srl  %g1, 3, %g1
a00cd868:  9b 28 60 04  sll  %g1, 4, %o5
a00cd86c:  98 04 bf ff  add  %l2, -1, %o4
a00cd870:  9a 23 40 01  sub  %o5, %g1, %o5
a00cd874:  83 2b 20 10  sll  %o4, 0x10, %g1
a00cd878:  a2 22 c0 0d  sub  %o3, %o5, %l1
a00cd87c:  80 a0 60 00  cmp  %g1, 0
a00cd880:  10 bf ff d1  b  0xa00cd7c4
a00cd884:  a4 10 00 0c  mov  %o4, %l2
a00cd888:  a2 10 20 00  clr  %l1
a00cd88c:  03 00 00 18  sethi  %hi(0x6000), %g1
a00cd890:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00cd894:  82 10 63 50  or  %g1, 0x350, %g1
a00cd898:  9a 03 40 01  add  %o5, %g1, %o5
a00cd89c:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00cd8a0:  9b 2b 60 02  sll  %o5, 2, %o5
a00cd8a4:  9a 13 40 01  or  %o5, %g1, %o5
a00cd8a8:  d4 03 40 00  ld  [ %o5 ], %o2
a00cd8ac:  a4 0e 20 ff  and  %i0, 0xff, %l2
a00cd8b0:  94 0a a0 ff  and  %o2, 0xff, %o2
a00cd8b4:  90 10 00 12  mov  %l2, %o0
a00cd8b8:  7f ff e7 67  call  0xa00c7654
a00cd8bc:  92 10 20 01  mov  1, %o1
a00cd8c0:  a2 04 60 01  inc  %l1
a00cd8c4:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cd8c8:  80 a0 60 04  cmp  %g1, 4
a00cd8cc:  08 bf ff f1  bleu  0xa00cd890
a00cd8d0:  03 00 00 18  sethi  %hi(0x6000), %g1
a00cd8d4:  90 10 20 aa  mov  0xaa, %o0
a00cd8d8:  7f ff f1 e7  call  0xa00ca074
a00cd8dc:  d2 0f bf f0  ldub  [ %fp + -16 ], %o1
a00cd8e0:  90 10 20 aa  mov  0xaa, %o0
a00cd8e4:  7f ff f1 e4  call  0xa00ca074
a00cd8e8:  d2 0f bf f1  ldub  [ %fp + -15 ], %o1
a00cd8ec:  a2 10 20 00  clr  %l1
a00cd8f0:  03 00 00 18  sethi  %hi(0x6000), %g1
a00cd8f4:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00cd8f8:  82 10 63 7f  or  %g1, 0x37f, %g1
a00cd8fc:  82 20 40 0d  sub  %g1, %o5, %g1
a00cd900:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00cd904:  83 28 60 02  sll  %g1, 2, %g1
a00cd908:  82 10 40 0d  or  %g1, %o5, %g1
a00cd90c:  d2 00 40 00  ld  [ %g1 ], %o1
a00cd910:  92 0a 60 ff  and  %o1, 0xff, %o1
a00cd914:  7f ff f1 d8  call  0xa00ca074
a00cd918:  90 10 20 aa  mov  0xaa, %o0
a00cd91c:  a2 04 60 01  inc  %l1
a00cd920:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cd924:  80 a0 60 07  cmp  %g1, 7
a00cd928:  08 bf ff f3  bleu  0xa00cd8f4
a00cd92c:  03 00 00 18  sethi  %hi(0x6000), %g1
a00cd930:  90 10 20 aa  mov  0xaa, %o0
a00cd934:  7f ff f1 d0  call  0xa00ca074
a00cd938:  92 10 20 80  mov  0x80, %o1
a00cd93c:  9a 05 20 0a  add  %l4, 0xa, %o5
a00cd940:  17 33 c0 63  sethi  %hi(0xcf018c00), %o3
a00cd944:  a8 10 00 0d  mov  %o5, %l4
a00cd948:  82 0d 20 ff  and  %l4, 0xff, %g1
a00cd94c:  98 12 e2 28  or  %o3, 0x228, %o4
a00cd950:  c2 23 00 00  st  %g1, [ %o4 ]
a00cd954:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00cd958:  82 12 e2 24  or  %o3, 0x224, %g1
a00cd95c:  9b 33 60 18  srl  %o5, 0x18, %o5
a00cd960:  da 20 40 00  st  %o5, [ %g1 ]
a00cd964:  82 12 e2 0c  or  %o3, 0x20c, %g1
a00cd968:  c2 00 40 00  ld  [ %g1 ], %g1
a00cd96c:  80 a0 60 06  cmp  %g1, 6
a00cd970:  18 80 00 18  bgu  0xa00cd9d0
a00cd974:  19 33 c0 63  sethi  %hi(0xcf018c00), %o4
a00cd978:  9a 12 e2 14  or  %o3, 0x214, %o5
a00cd97c:  c2 03 40 00  ld  [ %o5 ], %g1
a00cd980:  82 10 60 01  or  %g1, 1, %g1
a00cd984:  98 10 00 0b  mov  %o3, %o4
a00cd988:  c2 23 40 00  st  %g1, [ %o5 ]
a00cd98c:  96 10 00 0d  mov  %o5, %o3
a00cd990:  c2 02 c0 00  ld  [ %o3 ], %g1
a00cd994:  80 88 60 01  btst  1, %g1
a00cd998:  12 bf ff fe  bne  0xa00cd990
a00cd99c:  9a 13 22 10  or  %o4, 0x210, %o5
a00cd9a0:  82 10 20 1f  mov  0x1f, %g1
a00cd9a4:  c2 23 40 00  st  %g1, [ %o5 ]
a00cd9a8:  c2 02 c0 00  ld  [ %o3 ], %g1
a00cd9ac:  82 10 60 80  or  %g1, 0x80, %g1
a00cd9b0:  c2 22 c0 00  st  %g1, [ %o3 ]
a00cd9b4:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00cd9b8:  9a 10 62 14  or  %g1, 0x214, %o5	! 0xcf018e14
a00cd9bc:  c2 03 40 00  ld  [ %o5 ], %g1
a00cd9c0:  80 88 60 80  btst  0x80, %g1
a00cd9c4:  12 bf ff fe  bne  0xa00cd9bc
a00cd9c8:  01 00 00 00  nop
a00cd9cc:  19 33 c0 63  sethi  %hi(0xcf018c00), %o4
a00cd9d0:  83 2d 20 10  sll  %l4, 0x10, %g1
a00cd9d4:  96 13 22 0c  or  %o4, 0x20c, %o3
a00cd9d8:  83 30 60 0d  srl  %g1, 0xd, %g1
a00cd9dc:  c0 22 c0 00  clr  [ %o3 ]
a00cd9e0:  9a 08 60 ff  and  %g1, 0xff, %o5
a00cd9e4:  94 13 22 04  or  %o4, 0x204, %o2
a00cd9e8:  da 22 80 00  st  %o5, [ %o2 ]
a00cd9ec:  9a 10 20 01  mov  1, %o5
a00cd9f0:  83 38 60 08  sra  %g1, 8, %g1
a00cd9f4:  da 22 c0 00  st  %o5, [ %o3 ]
a00cd9f8:  82 08 60 ff  and  %g1, 0xff, %g1
a00cd9fc:  9a 13 22 14  or  %o4, 0x214, %o5
a00cda00:  c2 22 80 00  st  %g1, [ %o2 ]
a00cda04:  c2 03 40 00  ld  [ %o5 ], %g1
a00cda08:  82 10 60 01  or  %g1, 1, %g1
a00cda0c:  c2 23 40 00  st  %g1, [ %o5 ]
a00cda10:  96 10 00 0d  mov  %o5, %o3
a00cda14:  c2 02 c0 00  ld  [ %o3 ], %g1
a00cda18:  80 88 60 01  btst  1, %g1
a00cda1c:  12 bf ff fe  bne  0xa00cda14
a00cda20:  9a 13 22 10  or  %o4, 0x210, %o5
a00cda24:  82 10 20 1f  mov  0x1f, %g1
a00cda28:  c2 23 40 00  st  %g1, [ %o5 ]
a00cda2c:  c2 02 c0 00  ld  [ %o3 ], %g1
a00cda30:  82 10 60 80  or  %g1, 0x80, %g1
a00cda34:  1b 33 c0 63  sethi  %hi(0xcf018c00), %o5
a00cda38:  c2 22 c0 00  st  %g1, [ %o3 ]
a00cda3c:  98 13 62 14  or  %o5, 0x214, %o4
a00cda40:  c2 03 00 00  ld  [ %o4 ], %g1
a00cda44:  80 88 60 80  btst  0x80, %g1
a00cda48:  12 bf ff fe  bne  0xa00cda40
a00cda4c:  a0 13 62 08  or  %o5, 0x208, %l0
a00cda50:  82 10 20 22  mov  0x22, %g1
a00cda54:  9a 13 62 00  or  %o5, 0x200, %o5
a00cda58:  23 00 01 a0  sethi  %hi(0x68000), %l1
a00cda5c:  c0 24 00 00  clr  [ %l0 ]
a00cda60:  c2 23 40 00  st  %g1, [ %o5 ]
a00cda64:  94 14 60 14  or  %l1, 0x14, %o2
a00cda68:  92 10 20 90  mov  0x90, %o1
a00cda6c:  96 10 20 0f  mov  0xf, %o3
a00cda70:  98 07 bf d8  add  %fp, -40, %o4
a00cda74:  40 3b 22 63  call  0xa0f96400
a00cda78:  90 10 20 00  clr  %o0
a00cda7c:  94 14 60 24  or  %l1, 0x24, %o2
a00cda80:  92 10 20 90  mov  0x90, %o1
a00cda84:  90 10 20 00  clr  %o0
a00cda88:  96 10 20 03  mov  3, %o3
a00cda8c:  40 3b 22 5d  call  0xa0f96400
a00cda90:  98 07 bf e8  add  %fp, -24, %o4
a00cda94:  c2 04 00 00  ld  [ %l0 ], %g1
a00cda98:  82 10 60 80  or  %g1, 0x80, %g1
a00cda9c:  c2 24 00 00  st  %g1, [ %l0 ]
a00cdaa0:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00cdaa4:  90 10 62 04  or  %g1, 0x204, %o0	! 0xcf018e04
a00cdaa8:  a2 10 20 00  clr  %l1
a00cdaac:  92 07 bf f8  add  %fp, -8, %o1
a00cdab0:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cdab4:  95 28 60 02  sll  %g1, 2, %o2
a00cdab8:  98 10 20 00  clr  %o4
a00cdabc:  82 0b 20 ff  and  %o4, 0xff, %g1
a00cdac0:  82 22 80 01  sub  %o2, %g1, %g1
a00cdac4:  82 02 40 01  add  %o1, %g1, %g1
a00cdac8:  da 02 00 00  ld  [ %o0 ], %o5
a00cdacc:  98 03 20 01  inc  %o4
a00cdad0:  c2 08 7f e3  ldub  [ %g1 + -29 ], %g1
a00cdad4:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00cdad8:  80 a0 40 0d  cmp  %g1, %o5
a00cdadc:  12 bf fe f1  bne  0xa00cd6a0
a00cdae0:  96 0b 20 ff  and  %o4, 0xff, %o3
a00cdae4:  80 a2 e0 03  cmp  %o3, 3
a00cdae8:  08 bf ff f6  bleu  0xa00cdac0
a00cdaec:  82 0b 20 ff  and  %o4, 0xff, %g1
a00cdaf0:  a2 04 60 01  inc  %l1
a00cdaf4:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cdaf8:  80 a0 60 04  cmp  %g1, 4
a00cdafc:  08 bf ff ef  bleu  0xa00cdab8
a00cdb00:  95 28 60 02  sll  %g1, 2, %o2
a00cdb04:  81 c7 e0 08  ret
a00cdb08:  81 e8 00 00  restore
