# leon2m FUN_a002d5ac 0xa002d5ac-0xa002e238 (3212 bytes)
a002d5ac:  9d e3 bf 88  save  %sp, -120, %sp
a002d5b0:  1b 00 06 64  sethi  %hi(0x199000), %o5
a002d5b4:  c2 4b 61 f0  ldsb  [ %o5 + 0x1f0 ], %g1	! 0x1991f0
a002d5b8:  80 a0 60 00  cmp  %g1, 0
a002d5bc:  02 80 00 1d  be  0xa002d630
a002d5c0:  a6 13 61 f0  or  %o5, 0x1f0, %l3
a002d5c4:  11 00 03 ff  sethi  %hi(0xffc00), %o0
a002d5c8:  ac 12 23 fe  or  %o0, 0x3fe, %l6	! 0xffffe
a002d5cc:  29 30 02 c0  sethi  %hi(0xc00b0000), %l4
a002d5d0:  aa 10 00 16  mov  %l6, %l5
a002d5d4:  a0 10 20 00  clr  %l0
a002d5d8:  7f ff fb 1e  call  0xa002c250
a002d5dc:  90 15 20 14  or  %l4, 0x14, %o0
a002d5e0:  80 8a 20 20  btst  0x20, %o0
a002d5e4:  12 80 00 05  bne  0xa002d5f8
a002d5e8:  a0 04 20 01  inc  %l0
a002d5ec:  80 a4 00 15  cmp  %l0, %l5
a002d5f0:  08 bf ff fa  bleu  0xa002d5d8
a002d5f4:  01 00 00 00  nop
a002d5f8:  d2 4c c0 00  ldsb  [ %l3 ], %o1
a002d5fc:  7f ff fb 18  call  0xa002c25c
a002d600:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002d604:  d2 4c c0 00  ldsb  [ %l3 ], %o1
a002d608:  80 a2 60 0a  cmp  %o1, 0xa
a002d60c:  a0 10 20 00  clr  %l0
a002d610:  23 30 02 c0  sethi  %hi(0xc00b0000), %l1
a002d614:  02 80 01 c2  be  0xa002dd1c
a002d618:  a4 10 00 16  mov  %l6, %l2
a002d61c:  a6 04 e0 01  inc  %l3
a002d620:  d4 4c c0 00  ldsb  [ %l3 ], %o2
a002d624:  80 a2 a0 00  cmp  %o2, 0
a002d628:  32 bf ff ec  bne,a   0xa002d5d8
a002d62c:  a0 10 20 00  clr  %l0
a002d630:  21 2a 00 ff  sethi  %hi(0xa803fc00), %l0
a002d634:  9e 14 23 84  or  %l0, 0x384, %o7	! 0xa803ff84
a002d638:  19 00 06 63  sethi  %hi(0x198c00), %o4
a002d63c:  17 00 03 ff  sethi  %hi(0xffc00), %o3
a002d640:  f4 03 c0 00  ld  [ %o7 ], %i2
a002d644:  ac 13 23 a0  or  %o4, 0x3a0, %l6
a002d648:  a8 12 e3 fe  or  %o3, 0x3fe, %l4
a002d64c:  a2 10 20 00  clr  %l1
a002d650:  27 30 02 c0  sethi  %hi(0xc00b0000), %l3
a002d654:  aa 10 20 1c  mov  0x1c, %l5
a002d658:  a5 36 80 15  srl  %i2, %l5, %l2
a002d65c:  ae 0c a0 0f  and  %l2, 0xf, %l7
a002d660:  e4 0d 80 17  ldub  [ %l6 + %l7 ], %l2
a002d664:  a0 10 20 00  clr  %l0
a002d668:  7f ff fa fa  call  0xa002c250
a002d66c:  90 14 e0 14  or  %l3, 0x14, %o0
a002d670:  80 8a 20 20  btst  0x20, %o0
a002d674:  12 80 00 05  bne  0xa002d688
a002d678:  a0 04 20 01  inc  %l0
a002d67c:  80 a4 00 14  cmp  %l0, %l4
a002d680:  08 bf ff fa  bleu  0xa002d668
a002d684:  01 00 00 00  nop
a002d688:  b1 2c a0 18  sll  %l2, 0x18, %i0
a002d68c:  93 3e 20 18  sra  %i0, 0x18, %o1
a002d690:  7f ff fa f3  call  0xa002c25c
a002d694:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002d698:  a2 04 60 01  inc  %l1
a002d69c:  80 a4 60 07  cmp  %l1, 7
a002d6a0:  04 bf ff ee  ble  0xa002d658
a002d6a4:  aa 05 7f fc  add  %l5, -4, %l5
a002d6a8:  23 00 06 64  sethi  %hi(0x199000), %l1
a002d6ac:  e6 4c 62 08  ldsb  [ %l1 + 0x208 ], %l3	! 0x199208
a002d6b0:  80 a4 e0 00  cmp  %l3, 0
a002d6b4:  02 80 00 1d  be  0xa002d728
a002d6b8:  a6 14 62 08  or  %l1, 0x208, %l3
a002d6bc:  29 00 03 ff  sethi  %hi(0xffc00), %l4
a002d6c0:  ac 15 23 fe  or  %l4, 0x3fe, %l6	! 0xffffe
a002d6c4:  29 30 02 c0  sethi  %hi(0xc00b0000), %l4
a002d6c8:  aa 10 00 16  mov  %l6, %l5
a002d6cc:  a0 10 20 00  clr  %l0
a002d6d0:  7f ff fa e0  call  0xa002c250
a002d6d4:  90 15 20 14  or  %l4, 0x14, %o0
a002d6d8:  80 8a 20 20  btst  0x20, %o0
a002d6dc:  12 80 00 05  bne  0xa002d6f0
a002d6e0:  a0 04 20 01  inc  %l0
a002d6e4:  80 a4 00 15  cmp  %l0, %l5
a002d6e8:  08 bf ff fa  bleu  0xa002d6d0
a002d6ec:  01 00 00 00  nop
a002d6f0:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002d6f4:  7f ff fa da  call  0xa002c25c
a002d6f8:  d2 4c c0 00  ldsb  [ %l3 ], %o1
a002d6fc:  f2 4c c0 00  ldsb  [ %l3 ], %i1
a002d700:  80 a6 60 0a  cmp  %i1, 0xa
a002d704:  a0 10 20 00  clr  %l0
a002d708:  23 30 02 c0  sethi  %hi(0xc00b0000), %l1
a002d70c:  02 80 01 91  be  0xa002dd50
a002d710:  a4 10 00 16  mov  %l6, %l2
a002d714:  a6 04 e0 01  inc  %l3
a002d718:  f6 4c c0 00  ldsb  [ %l3 ], %i3
a002d71c:  80 a6 e0 00  cmp  %i3, 0
a002d720:  32 bf ff ec  bne,a   0xa002d6d0
a002d724:  a0 10 20 00  clr  %l0
a002d728:  03 2a 00 ff  sethi  %hi(0xa803fc00), %g1
a002d72c:  9a 10 63 8c  or  %g1, 0x38c, %o5	! 0xa803ff8c
a002d730:  2b 00 03 ff  sethi  %hi(0xffc00), %l5
a002d734:  fa 03 40 00  ld  [ %o5 ], %i5
a002d738:  94 15 63 fe  or  %l5, 0x3fe, %o2
a002d73c:  b8 0f 6f f0  and  %i5, 0xff0, %i4
a002d740:  2d 2a 00 97  sethi  %hi(0xa8025c00), %l6
a002d744:  ab 37 20 04  srl  %i4, 4, %l5
a002d748:  98 15 a0 78  or  %l6, 0x78, %o4
a002d74c:  a4 10 20 00  clr  %l2
a002d750:  96 10 00 0a  mov  %o2, %o3
a002d754:  9b 2c a0 03  sll  %l2, 3, %o5
a002d758:  d0 03 00 0d  ld  [ %o4 + %o5 ], %o0
a002d75c:  80 a2 00 15  cmp  %o0, %l5
a002d760:  02 80 02 89  be  0xa002e184
a002d764:  9e 03 40 0c  add  %o5, %o4, %o7
a002d768:  a4 04 a0 01  inc  %l2
a002d76c:  80 a4 a0 10  cmp  %l2, 0x10
a002d770:  24 bf ff fa  ble,a   0xa002d758
a002d774:  9b 2c a0 03  sll  %l2, 3, %o5
a002d778:  80 a4 a0 11  cmp  %l2, 0x11
a002d77c:  02 80 02 64  be  0xa002e10c
a002d780:  ae 10 00 15  mov  %l5, %l7
a002d784:  2f 00 06 64  sethi  %hi(0x199000), %l7
a002d788:  e2 4d e2 18  ldsb  [ %l7 + 0x218 ], %l1	! 0x199218
a002d78c:  80 a4 60 00  cmp  %l1, 0
a002d790:  02 80 00 1d  be  0xa002d804
a002d794:  a6 15 e2 18  or  %l7, 0x218, %l3
a002d798:  29 00 03 ff  sethi  %hi(0xffc00), %l4
a002d79c:  ac 15 23 fe  or  %l4, 0x3fe, %l6	! 0xffffe
a002d7a0:  29 30 02 c0  sethi  %hi(0xc00b0000), %l4
a002d7a4:  aa 10 00 16  mov  %l6, %l5
a002d7a8:  a0 10 20 00  clr  %l0
a002d7ac:  7f ff fa a9  call  0xa002c250
a002d7b0:  90 15 20 14  or  %l4, 0x14, %o0
a002d7b4:  80 8a 20 20  btst  0x20, %o0
a002d7b8:  12 80 00 05  bne  0xa002d7cc
a002d7bc:  a0 04 20 01  inc  %l0
a002d7c0:  80 a4 00 15  cmp  %l0, %l5
a002d7c4:  08 bf ff fa  bleu  0xa002d7ac
a002d7c8:  01 00 00 00  nop
a002d7cc:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002d7d0:  7f ff fa a3  call  0xa002c25c
a002d7d4:  d2 4c c0 00  ldsb  [ %l3 ], %o1
a002d7d8:  f6 4c c0 00  ldsb  [ %l3 ], %i3
a002d7dc:  80 a6 e0 0a  cmp  %i3, 0xa
a002d7e0:  a0 10 20 00  clr  %l0
a002d7e4:  23 30 02 c0  sethi  %hi(0xc00b0000), %l1
a002d7e8:  02 80 01 74  be  0xa002ddb8
a002d7ec:  a4 10 00 16  mov  %l6, %l2
a002d7f0:  a6 04 e0 01  inc  %l3
a002d7f4:  f8 4c c0 00  ldsb  [ %l3 ], %i4
a002d7f8:  80 a7 20 00  cmp  %i4, 0
a002d7fc:  12 bf ff ec  bne  0xa002d7ac
a002d800:  a0 10 20 00  clr  %l0
a002d804:  2d 00 06 63  sethi  %hi(0x198c00), %l6
a002d808:  2b 2a 00 ff  sethi  %hi(0xa803fc00), %l5
a002d80c:  b8 15 a3 a0  or  %l6, 0x3a0, %i4
a002d810:  27 00 06 64  sethi  %hi(0x199000), %l3
a002d814:  b2 15 63 60  or  %l5, 0x360, %i1
a002d818:  b6 10 20 00  clr  %i3
a002d81c:  31 00 06 62  sethi  %hi(0x198800), %i0
a002d820:  2d 30 02 c0  sethi  %hi(0xc00b0000), %l6
a002d824:  ee 04 e2 70  ld  [ %l3 + 0x270 ], %l7
a002d828:  bb 2e e0 02  sll  %i3, 2, %i5
a002d82c:  e8 07 40 19  ld  [ %i5 + %i1 ], %l4
a002d830:  a6 10 20 00  clr  %l3
a002d834:  a4 10 20 1c  mov  0x1c, %l2
a002d838:  83 35 00 12  srl  %l4, %l2, %g1
a002d83c:  9a 08 60 0f  and  %g1, 0xf, %o5
a002d840:  e2 0f 00 0d  ldub  [ %i4 + %o5 ], %l1
a002d844:  a0 10 20 00  clr  %l0
a002d848:  7f ff fa 82  call  0xa002c250
a002d84c:  90 15 a0 14  or  %l6, 0x14, %o0
a002d850:  80 8a 20 20  btst  0x20, %o0
a002d854:  12 80 00 05  bne  0xa002d868
a002d858:  a0 04 20 01  inc  %l0
a002d85c:  80 a4 00 17  cmp  %l0, %l7
a002d860:  08 bf ff fa  bleu  0xa002d848
a002d864:  01 00 00 00  nop
a002d868:  91 2c 60 18  sll  %l1, 0x18, %o0
a002d86c:  93 3a 20 18  sra  %o0, 0x18, %o1
a002d870:  7f ff fa 7b  call  0xa002c25c
a002d874:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002d878:  a6 04 e0 01  inc  %l3
a002d87c:  80 a4 e0 07  cmp  %l3, 7
a002d880:  04 bf ff ee  ble  0xa002d838
a002d884:  a4 04 bf fc  add  %l2, -4, %l2
a002d888:  d2 4e 23 b0  ldsb  [ %i0 + 0x3b0 ], %o1
a002d88c:  80 a2 60 00  cmp  %o1, 0
a002d890:  02 80 00 1d  be  0xa002d904
a002d894:  a6 16 23 b0  or  %i0, 0x3b0, %l3
a002d898:  1f 00 06 64  sethi  %hi(0x199000), %o7
a002d89c:  29 30 02 c0  sethi  %hi(0xc00b0000), %l4
a002d8a0:  ea 03 e2 70  ld  [ %o7 + 0x270 ], %l5
a002d8a4:  ba 10 00 15  mov  %l5, %i5
a002d8a8:  a0 10 20 00  clr  %l0
a002d8ac:  7f ff fa 69  call  0xa002c250
a002d8b0:  90 15 20 14  or  %l4, 0x14, %o0
a002d8b4:  80 8a 20 20  btst  0x20, %o0
a002d8b8:  12 80 00 05  bne  0xa002d8cc
a002d8bc:  a0 04 20 01  inc  %l0
a002d8c0:  80 a4 00 15  cmp  %l0, %l5
a002d8c4:  08 bf ff fa  bleu  0xa002d8ac
a002d8c8:  01 00 00 00  nop
a002d8cc:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002d8d0:  7f ff fa 63  call  0xa002c25c
a002d8d4:  d2 4c c0 00  ldsb  [ %l3 ], %o1
a002d8d8:  d4 4c c0 00  ldsb  [ %l3 ], %o2
a002d8dc:  80 a2 a0 0a  cmp  %o2, 0xa
a002d8e0:  a0 10 20 00  clr  %l0
a002d8e4:  25 30 02 c0  sethi  %hi(0xc00b0000), %l2
a002d8e8:  02 80 01 27  be  0xa002dd84
a002d8ec:  a2 10 00 1d  mov  %i5, %l1
a002d8f0:  a6 04 e0 01  inc  %l3
a002d8f4:  d6 4c c0 00  ldsb  [ %l3 ], %o3
a002d8f8:  80 a2 e0 00  cmp  %o3, 0
a002d8fc:  32 bf ff ec  bne,a   0xa002d8ac
a002d900:  a0 10 20 00  clr  %l0
a002d904:  98 0e e0 07  and  %i3, 7, %o4
a002d908:  80 a3 20 07  cmp  %o4, 7
a002d90c:  22 80 01 76  be,a   0xa002dee4
a002d910:  21 00 03 fb  sethi  %hi(0xfec00), %l0
a002d914:  b6 06 e0 01  inc  %i3
a002d918:  80 a6 e0 27  cmp  %i3, 0x27
a002d91c:  24 bf ff c4  ble,a   0xa002d82c
a002d920:  bb 2e e0 02  sll  %i3, 2, %i5
a002d924:  33 00 06 64  sethi  %hi(0x199000), %i1
a002d928:  ee 4e 62 30  ldsb  [ %i1 + 0x230 ], %l7	! 0x199230
a002d92c:  80 a5 e0 00  cmp  %l7, 0
a002d930:  02 80 00 1d  be  0xa002d9a4
a002d934:  a6 16 62 30  or  %i1, 0x230, %l3
a002d938:  29 00 03 ff  sethi  %hi(0xffc00), %l4
a002d93c:  ac 15 23 fe  or  %l4, 0x3fe, %l6	! 0xffffe
a002d940:  29 30 02 c0  sethi  %hi(0xc00b0000), %l4
a002d944:  aa 10 00 16  mov  %l6, %l5
a002d948:  a0 10 20 00  clr  %l0
a002d94c:  7f ff fa 41  call  0xa002c250
a002d950:  90 15 20 14  or  %l4, 0x14, %o0
a002d954:  80 8a 20 20  btst  0x20, %o0
a002d958:  12 80 00 05  bne  0xa002d96c
a002d95c:  a0 04 20 01  inc  %l0
a002d960:  80 a4 00 15  cmp  %l0, %l5
a002d964:  08 bf ff fa  bleu  0xa002d94c
a002d968:  01 00 00 00  nop
a002d96c:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002d970:  7f ff fa 3b  call  0xa002c25c
a002d974:  d2 4c c0 00  ldsb  [ %l3 ], %o1
a002d978:  f6 4c c0 00  ldsb  [ %l3 ], %i3
a002d97c:  80 a6 e0 0a  cmp  %i3, 0xa
a002d980:  a0 10 20 00  clr  %l0
a002d984:  23 30 02 c0  sethi  %hi(0xc00b0000), %l1
a002d988:  02 80 01 26  be  0xa002de20
a002d98c:  a4 10 00 16  mov  %l6, %l2
a002d990:  a6 04 e0 01  inc  %l3
a002d994:  f8 4c c0 00  ldsb  [ %l3 ], %i4
a002d998:  80 a7 20 00  cmp  %i4, 0
a002d99c:  12 bf ff ec  bne  0xa002d94c
a002d9a0:  a0 10 20 00  clr  %l0
a002d9a4:  3b 2a 00 ff  sethi  %hi(0xa803fc00), %i5
a002d9a8:  aa 17 63 94  or  %i5, 0x394, %l5	! 0xa803ff94
a002d9ac:  ec 05 40 00  ld  [ %l5 ], %l6
a002d9b0:  11 00 03 ff  sethi  %hi(0xffc00), %o0
a002d9b4:  b6 12 23 fe  or  %o0, 0x3fe, %i3	! 0xffffe
a002d9b8:  ec 27 bf f0  st  %l6, [ %fp + -16 ]
a002d9bc:  27 00 06 63  sethi  %hi(0x198c00), %l3
a002d9c0:  b2 10 00 1b  mov  %i3, %i1
a002d9c4:  b8 14 e3 a0  or  %l3, 0x3a0, %i4
a002d9c8:  c0 27 bf f4  clr  [ %fp + -12 ]
a002d9cc:  2d 30 02 c0  sethi  %hi(0xc00b0000), %l6
a002d9d0:  ae 10 00 1b  mov  %i3, %l7
a002d9d4:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a002d9d8:  9f 2a a0 02  sll  %o2, 2, %o7
a002d9dc:  d2 07 bf f0  ld  [ %fp + -16 ], %o1
a002d9e0:  e8 03 c0 09  ld  [ %o7 + %o1 ], %l4
a002d9e4:  a4 10 20 00  clr  %l2
a002d9e8:  a6 10 20 1c  mov  0x1c, %l3
a002d9ec:  99 35 00 13  srl  %l4, %l3, %o4
a002d9f0:  96 0b 20 0f  and  %o4, 0xf, %o3
a002d9f4:  e2 0f 00 0b  ldub  [ %i4 + %o3 ], %l1
a002d9f8:  a0 10 20 00  clr  %l0
a002d9fc:  7f ff fa 15  call  0xa002c250
a002da00:  90 15 a0 14  or  %l6, 0x14, %o0
a002da04:  80 8a 20 20  btst  0x20, %o0
a002da08:  12 80 00 05  bne  0xa002da1c
a002da0c:  a0 04 20 01  inc  %l0
a002da10:  80 a4 00 17  cmp  %l0, %l7
a002da14:  08 bf ff fa  bleu  0xa002d9fc
a002da18:  01 00 00 00  nop
a002da1c:  a1 2c 60 18  sll  %l1, 0x18, %l0
a002da20:  93 3c 20 18  sra  %l0, 0x18, %o1
a002da24:  7f ff fa 0e  call  0xa002c25c
a002da28:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002da2c:  a4 04 a0 01  inc  %l2
a002da30:  80 a4 a0 07  cmp  %l2, 7
a002da34:  04 bf ff ee  ble  0xa002d9ec
a002da38:  a6 04 ff fc  add  %l3, -4, %l3
a002da3c:  e4 4e 23 b0  ldsb  [ %i0 + 0x3b0 ], %l2
a002da40:  80 a4 a0 00  cmp  %l2, 0
a002da44:  02 80 00 1d  be  0xa002dab8
a002da48:  a6 16 23 b0  or  %i0, 0x3b0, %l3
a002da4c:  29 30 02 c0  sethi  %hi(0xc00b0000), %l4
a002da50:  aa 10 00 1b  mov  %i3, %l5
a002da54:  23 00 06 64  sethi  %hi(0x199000), %l1
a002da58:  fa 04 62 70  ld  [ %l1 + 0x270 ], %i5	! 0x199270
a002da5c:  a0 10 20 00  clr  %l0
a002da60:  7f ff f9 fc  call  0xa002c250
a002da64:  90 15 20 14  or  %l4, 0x14, %o0
a002da68:  80 8a 20 20  btst  0x20, %o0
a002da6c:  12 80 00 05  bne  0xa002da80
a002da70:  a0 04 20 01  inc  %l0
a002da74:  80 a4 00 15  cmp  %l0, %l5
a002da78:  08 bf ff fa  bleu  0xa002da60
a002da7c:  01 00 00 00  nop
a002da80:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002da84:  7f ff f9 f6  call  0xa002c25c
a002da88:  d2 4c c0 00  ldsb  [ %l3 ], %o1
a002da8c:  da 4c c0 00  ldsb  [ %l3 ], %o5
a002da90:  80 a3 60 0a  cmp  %o5, 0xa
a002da94:  a0 10 20 00  clr  %l0
a002da98:  25 30 02 c0  sethi  %hi(0xc00b0000), %l2
a002da9c:  02 80 00 d4  be  0xa002ddec
a002daa0:  a2 10 00 1d  mov  %i5, %l1
a002daa4:  a6 04 e0 01  inc  %l3
a002daa8:  c2 4c c0 00  ldsb  [ %l3 ], %g1
a002daac:  80 a0 60 00  cmp  %g1, 0
a002dab0:  32 bf ff ec  bne,a   0xa002da60
a002dab4:  a0 10 20 00  clr  %l0
a002dab8:  e6 07 bf f4  ld  [ %fp + -12 ], %l3
a002dabc:  a8 0c e0 07  and  %l3, 7, %l4
a002dac0:  80 a5 20 07  cmp  %l4, 7
a002dac4:  22 80 01 64  be,a   0xa002e054
a002dac8:  2b 00 03 fb  sethi  %hi(0xfec00), %l5
a002dacc:  d6 07 bf f4  ld  [ %fp + -12 ], %o3
a002dad0:  94 02 e0 01  add  %o3, 1, %o2
a002dad4:  80 a2 a0 0f  cmp  %o2, 0xf
a002dad8:  04 bf ff bf  ble  0xa002d9d4
a002dadc:  d4 27 bf f4  st  %o2, [ %fp + -12 ]
a002dae0:  33 00 06 64  sethi  %hi(0x199000), %i1
a002dae4:  ee 4e 62 48  ldsb  [ %i1 + 0x248 ], %l7	! 0x199248
a002dae8:  80 a5 e0 00  cmp  %l7, 0
a002daec:  02 80 00 1d  be  0xa002db60
a002daf0:  a6 16 62 48  or  %i1, 0x248, %l3
a002daf4:  37 00 03 ff  sethi  %hi(0xffc00), %i3
a002daf8:  ac 16 e3 fe  or  %i3, 0x3fe, %l6	! 0xffffe
a002dafc:  29 30 02 c0  sethi  %hi(0xc00b0000), %l4
a002db00:  aa 10 00 16  mov  %l6, %l5
a002db04:  a0 10 20 00  clr  %l0
a002db08:  7f ff f9 d2  call  0xa002c250
a002db0c:  90 15 20 14  or  %l4, 0x14, %o0
a002db10:  80 8a 20 20  btst  0x20, %o0
a002db14:  12 80 00 05  bne  0xa002db28
a002db18:  a0 04 20 01  inc  %l0
a002db1c:  80 a4 00 15  cmp  %l0, %l5
a002db20:  08 bf ff fa  bleu  0xa002db08
a002db24:  01 00 00 00  nop
a002db28:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002db2c:  7f ff f9 cc  call  0xa002c25c
a002db30:  d2 4c c0 00  ldsb  [ %l3 ], %o1
a002db34:  f8 4c c0 00  ldsb  [ %l3 ], %i4
a002db38:  80 a7 20 0a  cmp  %i4, 0xa
a002db3c:  a0 10 20 00  clr  %l0
a002db40:  23 30 02 c0  sethi  %hi(0xc00b0000), %l1
a002db44:  02 80 00 d1  be  0xa002de88
a002db48:  a4 10 00 16  mov  %l6, %l2
a002db4c:  a6 04 e0 01  inc  %l3
a002db50:  d8 4c c0 00  ldsb  [ %l3 ], %o4
a002db54:  80 a3 20 00  cmp  %o4, 0
a002db58:  32 bf ff ec  bne,a   0xa002db08
a002db5c:  a0 10 20 00  clr  %l0
a002db60:  ac 06 bf f0  add  %i2, -16, %l6
a002db64:  35 00 06 63  sethi  %hi(0x198c00), %i2
a002db68:  25 00 03 ff  sethi  %hi(0xffc00), %l2
a002db6c:  b2 14 a3 fe  or  %l2, 0x3fe, %i1	! 0xffffe
a002db70:  ec 27 bf ec  st  %l6, [ %fp + -20 ]
a002db74:  b8 16 a3 a0  or  %i2, 0x3a0, %i4
a002db78:  21 00 06 64  sethi  %hi(0x199000), %l0
a002db7c:  b6 10 20 00  clr  %i3
a002db80:  2d 30 02 c0  sethi  %hi(0xc00b0000), %l6
a002db84:  ae 10 00 19  mov  %i1, %l7
a002db88:  f4 04 22 70  ld  [ %l0 + 0x270 ], %i2
a002db8c:  9b 2e e0 02  sll  %i3, 2, %o5
a002db90:  e2 07 bf ec  ld  [ %fp + -20 ], %l1
a002db94:  e8 03 40 11  ld  [ %o5 + %l1 ], %l4
a002db98:  a6 10 20 00  clr  %l3
a002db9c:  a4 10 20 1c  mov  0x1c, %l2
a002dba0:  ab 35 00 12  srl  %l4, %l2, %l5
a002dba4:  82 0d 60 0f  and  %l5, 0xf, %g1
a002dba8:  e2 0f 00 01  ldub  [ %i4 + %g1 ], %l1
a002dbac:  a0 10 20 00  clr  %l0
a002dbb0:  7f ff f9 a8  call  0xa002c250
a002dbb4:  90 15 a0 14  or  %l6, 0x14, %o0
a002dbb8:  80 8a 20 20  btst  0x20, %o0
a002dbbc:  12 80 00 05  bne  0xa002dbd0
a002dbc0:  a0 04 20 01  inc  %l0
a002dbc4:  80 a4 00 17  cmp  %l0, %l7
a002dbc8:  08 bf ff fa  bleu  0xa002dbb0
a002dbcc:  01 00 00 00  nop
a002dbd0:  bb 2c 60 18  sll  %l1, 0x18, %i5
a002dbd4:  93 3f 60 18  sra  %i5, 0x18, %o1
a002dbd8:  7f ff f9 a1  call  0xa002c25c
a002dbdc:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002dbe0:  a6 04 e0 01  inc  %l3
a002dbe4:  80 a4 e0 07  cmp  %l3, 7
a002dbe8:  04 bf ff ee  ble  0xa002dba0
a002dbec:  a4 04 bf fc  add  %l2, -4, %l2
a002dbf0:  e8 4e 23 b0  ldsb  [ %i0 + 0x3b0 ], %l4
a002dbf4:  80 a5 20 00  cmp  %l4, 0
a002dbf8:  02 80 00 1c  be  0xa002dc68
a002dbfc:  a6 16 23 b0  or  %i0, 0x3b0, %l3
a002dc00:  29 30 02 c0  sethi  %hi(0xc00b0000), %l4
a002dc04:  aa 10 00 19  mov  %i1, %l5
a002dc08:  ba 10 00 1a  mov  %i2, %i5
a002dc0c:  a0 10 20 00  clr  %l0
a002dc10:  7f ff f9 90  call  0xa002c250
a002dc14:  90 15 20 14  or  %l4, 0x14, %o0
a002dc18:  80 8a 20 20  btst  0x20, %o0
a002dc1c:  12 80 00 05  bne  0xa002dc30
a002dc20:  a0 04 20 01  inc  %l0
a002dc24:  80 a4 00 15  cmp  %l0, %l5
a002dc28:  08 bf ff fa  bleu  0xa002dc10
a002dc2c:  01 00 00 00  nop
a002dc30:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002dc34:  7f ff f9 8a  call  0xa002c25c
a002dc38:  d2 4c c0 00  ldsb  [ %l3 ], %o1
a002dc3c:  d0 4c c0 00  ldsb  [ %l3 ], %o0
a002dc40:  80 a2 20 0a  cmp  %o0, 0xa
a002dc44:  a0 10 20 00  clr  %l0
a002dc48:  25 30 02 c0  sethi  %hi(0xc00b0000), %l2
a002dc4c:  02 80 00 82  be  0xa002de54
a002dc50:  a2 10 00 1d  mov  %i5, %l1
a002dc54:  a6 04 e0 01  inc  %l3
a002dc58:  d2 4c c0 00  ldsb  [ %l3 ], %o1
a002dc5c:  80 a2 60 00  cmp  %o1, 0
a002dc60:  32 bf ff ec  bne,a   0xa002dc10
a002dc64:  a0 10 20 00  clr  %l0
a002dc68:  a6 0e e0 07  and  %i3, 7, %l3
a002dc6c:  80 a4 e0 07  cmp  %l3, 7
a002dc70:  22 80 00 cb  be,a   0xa002df9c
a002dc74:  1f 00 03 fb  sethi  %hi(0xfec00), %o7
a002dc78:  b6 06 e0 01  inc  %i3
a002dc7c:  80 a6 e0 1f  cmp  %i3, 0x1f
a002dc80:  24 bf ff c4  ble,a   0xa002db90
a002dc84:  9b 2e e0 02  sll  %i3, 2, %o5
a002dc88:  31 00 06 64  sethi  %hi(0x199000), %i0
a002dc8c:  f2 4e 22 60  ldsb  [ %i0 + 0x260 ], %i1	! 0x199260
a002dc90:  80 a6 60 00  cmp  %i1, 0
a002dc94:  02 80 00 1d  be  0xa002dd08
a002dc98:  a6 16 22 60  or  %i0, 0x260, %l3
a002dc9c:  2f 00 03 ff  sethi  %hi(0xffc00), %l7
a002dca0:  ac 15 e3 fe  or  %l7, 0x3fe, %l6	! 0xffffe
a002dca4:  29 30 02 c0  sethi  %hi(0xc00b0000), %l4
a002dca8:  aa 10 00 16  mov  %l6, %l5
a002dcac:  a0 10 20 00  clr  %l0
a002dcb0:  7f ff f9 68  call  0xa002c250
a002dcb4:  90 15 20 14  or  %l4, 0x14, %o0
a002dcb8:  80 8a 20 20  btst  0x20, %o0
a002dcbc:  12 80 00 05  bne  0xa002dcd0
a002dcc0:  a0 04 20 01  inc  %l0
a002dcc4:  80 a4 00 15  cmp  %l0, %l5
a002dcc8:  08 bf ff fa  bleu  0xa002dcb0
a002dccc:  01 00 00 00  nop
a002dcd0:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002dcd4:  7f ff f9 62  call  0xa002c25c
a002dcd8:  d2 4c c0 00  ldsb  [ %l3 ], %o1
a002dcdc:  f6 4c c0 00  ldsb  [ %l3 ], %i3
a002dce0:  80 a6 e0 0a  cmp  %i3, 0xa
a002dce4:  a0 10 20 00  clr  %l0
a002dce8:  23 30 02 c0  sethi  %hi(0xc00b0000), %l1
a002dcec:  02 80 00 74  be  0xa002debc
a002dcf0:  a4 10 00 16  mov  %l6, %l2
a002dcf4:  a6 04 e0 01  inc  %l3
a002dcf8:  f8 4c c0 00  ldsb  [ %l3 ], %i4
a002dcfc:  80 a7 20 00  cmp  %i4, 0
a002dd00:  32 bf ff ec  bne,a   0xa002dcb0
a002dd04:  a0 10 20 00  clr  %l0
a002dd08:  10 80 00 00  b  0xa002dd08
a002dd0c:  01 00 00 00  nop
a002dd10:  80 a4 00 12  cmp  %l0, %l2
a002dd14:  18 80 00 08  bgu  0xa002dd34
a002dd18:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002dd1c:  7f ff f9 4d  call  0xa002c250
a002dd20:  90 14 60 14  or  %l1, 0x14, %o0
a002dd24:  80 8a 20 20  btst  0x20, %o0
a002dd28:  02 bf ff fa  be  0xa002dd10
a002dd2c:  a0 04 20 01  inc  %l0
a002dd30:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002dd34:  7f ff f9 4a  call  0xa002c25c
a002dd38:  92 10 20 0d  mov  0xd, %o1
a002dd3c:  10 bf fe 39  b  0xa002d620
a002dd40:  a6 04 e0 01  inc  %l3
a002dd44:  80 a4 00 12  cmp  %l0, %l2
a002dd48:  18 80 00 08  bgu  0xa002dd68
a002dd4c:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002dd50:  7f ff f9 40  call  0xa002c250
a002dd54:  90 14 60 14  or  %l1, 0x14, %o0
a002dd58:  80 8a 20 20  btst  0x20, %o0
a002dd5c:  02 bf ff fa  be  0xa002dd44
a002dd60:  a0 04 20 01  inc  %l0
a002dd64:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002dd68:  7f ff f9 3d  call  0xa002c25c
a002dd6c:  92 10 20 0d  mov  0xd, %o1
a002dd70:  10 bf fe 6a  b  0xa002d718
a002dd74:  a6 04 e0 01  inc  %l3
a002dd78:  80 a4 00 11  cmp  %l0, %l1
a002dd7c:  18 80 00 08  bgu  0xa002dd9c
a002dd80:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002dd84:  7f ff f9 33  call  0xa002c250
a002dd88:  90 14 a0 14  or  %l2, 0x14, %o0
a002dd8c:  80 8a 20 20  btst  0x20, %o0
a002dd90:  02 bf ff fa  be  0xa002dd78
a002dd94:  a0 04 20 01  inc  %l0
a002dd98:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002dd9c:  7f ff f9 30  call  0xa002c25c
a002dda0:  92 10 20 0d  mov  0xd, %o1
a002dda4:  10 bf fe d4  b  0xa002d8f4
a002dda8:  a6 04 e0 01  inc  %l3
a002ddac:  80 a4 00 12  cmp  %l0, %l2
a002ddb0:  18 80 00 08  bgu  0xa002ddd0
a002ddb4:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002ddb8:  7f ff f9 26  call  0xa002c250
a002ddbc:  90 14 60 14  or  %l1, 0x14, %o0
a002ddc0:  80 8a 20 20  btst  0x20, %o0
a002ddc4:  02 bf ff fa  be  0xa002ddac
a002ddc8:  a0 04 20 01  inc  %l0
a002ddcc:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002ddd0:  7f ff f9 23  call  0xa002c25c
a002ddd4:  92 10 20 0d  mov  0xd, %o1
a002ddd8:  10 bf fe 87  b  0xa002d7f4
a002dddc:  a6 04 e0 01  inc  %l3
a002dde0:  80 a4 00 11  cmp  %l0, %l1
a002dde4:  18 80 00 08  bgu  0xa002de04
a002dde8:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002ddec:  7f ff f9 19  call  0xa002c250
a002ddf0:  90 14 a0 14  or  %l2, 0x14, %o0
a002ddf4:  80 8a 20 20  btst  0x20, %o0
a002ddf8:  02 bf ff fa  be  0xa002dde0
a002ddfc:  a0 04 20 01  inc  %l0
a002de00:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002de04:  7f ff f9 16  call  0xa002c25c
a002de08:  92 10 20 0d  mov  0xd, %o1
a002de0c:  10 bf ff 27  b  0xa002daa8
a002de10:  a6 04 e0 01  inc  %l3
a002de14:  80 a4 00 12  cmp  %l0, %l2
a002de18:  18 80 00 08  bgu  0xa002de38
a002de1c:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002de20:  7f ff f9 0c  call  0xa002c250
a002de24:  90 14 60 14  or  %l1, 0x14, %o0
a002de28:  80 8a 20 20  btst  0x20, %o0
a002de2c:  02 bf ff fa  be  0xa002de14
a002de30:  a0 04 20 01  inc  %l0
a002de34:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002de38:  7f ff f9 09  call  0xa002c25c
a002de3c:  92 10 20 0d  mov  0xd, %o1
a002de40:  10 bf fe d5  b  0xa002d994
a002de44:  a6 04 e0 01  inc  %l3
a002de48:  80 a4 00 11  cmp  %l0, %l1
a002de4c:  18 80 00 08  bgu  0xa002de6c
a002de50:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002de54:  7f ff f8 ff  call  0xa002c250
a002de58:  90 14 a0 14  or  %l2, 0x14, %o0
a002de5c:  80 8a 20 20  btst  0x20, %o0
a002de60:  02 bf ff fa  be  0xa002de48
a002de64:  a0 04 20 01  inc  %l0
a002de68:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002de6c:  7f ff f8 fc  call  0xa002c25c
a002de70:  92 10 20 0d  mov  0xd, %o1
a002de74:  10 bf ff 79  b  0xa002dc58
a002de78:  a6 04 e0 01  inc  %l3
a002de7c:  80 a4 00 12  cmp  %l0, %l2
a002de80:  18 80 00 08  bgu  0xa002dea0
a002de84:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002de88:  7f ff f8 f2  call  0xa002c250
a002de8c:  90 14 60 14  or  %l1, 0x14, %o0
a002de90:  80 8a 20 20  btst  0x20, %o0
a002de94:  02 bf ff fa  be  0xa002de7c
a002de98:  a0 04 20 01  inc  %l0
a002de9c:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002dea0:  7f ff f8 ef  call  0xa002c25c
a002dea4:  92 10 20 0d  mov  0xd, %o1
a002dea8:  10 bf ff 2a  b  0xa002db50
a002deac:  a6 04 e0 01  inc  %l3
a002deb0:  80 a4 00 12  cmp  %l0, %l2
a002deb4:  18 80 00 08  bgu  0xa002ded4
a002deb8:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002debc:  7f ff f8 e5  call  0xa002c250
a002dec0:  90 14 60 14  or  %l1, 0x14, %o0
a002dec4:  80 8a 20 20  btst  0x20, %o0
a002dec8:  02 bf ff fa  be  0xa002deb0
a002decc:  a0 04 20 01  inc  %l0
a002ded0:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002ded4:  7f ff f8 e2  call  0xa002c25c
a002ded8:  92 10 20 0d  mov  0xd, %o1
a002dedc:  10 bf ff 87  b  0xa002dcf8
a002dee0:  a6 04 e0 01  inc  %l3
a002dee4:  e4 4c 23 90  ldsb  [ %l0 + 0x390 ], %l2
a002dee8:  80 a4 a0 00  cmp  %l2, 0
a002deec:  02 bf fe 8a  be  0xa002d914
a002def0:  a6 14 23 90  or  %l0, 0x390, %l3
a002def4:  23 00 06 64  sethi  %hi(0x199000), %l1
a002def8:  29 30 02 c0  sethi  %hi(0xc00b0000), %l4
a002defc:  ea 04 62 70  ld  [ %l1 + 0x270 ], %l5
a002df00:  ba 10 00 15  mov  %l5, %i5
a002df04:  a0 10 20 00  clr  %l0
a002df08:  7f ff f8 d2  call  0xa002c250
a002df0c:  90 15 20 14  or  %l4, 0x14, %o0
a002df10:  80 8a 20 20  btst  0x20, %o0
a002df14:  12 80 00 05  bne  0xa002df28
a002df18:  a0 04 20 01  inc  %l0
a002df1c:  80 a4 00 15  cmp  %l0, %l5
a002df20:  08 bf ff fa  bleu  0xa002df08
a002df24:  01 00 00 00  nop
a002df28:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002df2c:  7f ff f8 cc  call  0xa002c25c
a002df30:  d2 4c c0 00  ldsb  [ %l3 ], %o1
a002df34:  da 4c c0 00  ldsb  [ %l3 ], %o5
a002df38:  80 a3 60 0a  cmp  %o5, 0xa
a002df3c:  a0 10 20 00  clr  %l0
a002df40:  25 30 02 c0  sethi  %hi(0xc00b0000), %l2
a002df44:  02 80 00 0c  be  0xa002df74
a002df48:  a2 10 00 1d  mov  %i5, %l1
a002df4c:  a6 04 e0 01  inc  %l3
a002df50:  c2 4c c0 00  ldsb  [ %l3 ], %g1
a002df54:  80 a0 60 00  cmp  %g1, 0
a002df58:  32 bf ff ec  bne,a   0xa002df08
a002df5c:  a0 10 20 00  clr  %l0
a002df60:  10 bf fe 6e  b  0xa002d918
a002df64:  b6 06 e0 01  inc  %i3
a002df68:  80 a4 00 11  cmp  %l0, %l1
a002df6c:  18 80 00 08  bgu  0xa002df8c
a002df70:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002df74:  7f ff f8 b7  call  0xa002c250
a002df78:  90 14 a0 14  or  %l2, 0x14, %o0
a002df7c:  80 8a 20 20  btst  0x20, %o0
a002df80:  02 bf ff fa  be  0xa002df68
a002df84:  a0 04 20 01  inc  %l0
a002df88:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002df8c:  7f ff f8 b4  call  0xa002c25c
a002df90:  92 10 20 0d  mov  0xd, %o1
a002df94:  10 bf ff ef  b  0xa002df50
a002df98:  a6 04 e0 01  inc  %l3
a002df9c:  d4 4b e3 90  ldsb  [ %o7 + 0x390 ], %o2
a002dfa0:  80 a2 a0 00  cmp  %o2, 0
a002dfa4:  02 bf ff 35  be  0xa002dc78
a002dfa8:  a6 13 e3 90  or  %o7, 0x390, %l3
a002dfac:  17 00 06 64  sethi  %hi(0x199000), %o3
a002dfb0:  29 30 02 c0  sethi  %hi(0xc00b0000), %l4
a002dfb4:  ea 02 e2 70  ld  [ %o3 + 0x270 ], %l5
a002dfb8:  ba 10 00 15  mov  %l5, %i5
a002dfbc:  a0 10 20 00  clr  %l0
a002dfc0:  7f ff f8 a4  call  0xa002c250
a002dfc4:  90 15 20 14  or  %l4, 0x14, %o0
a002dfc8:  80 8a 20 20  btst  0x20, %o0
a002dfcc:  12 80 00 05  bne  0xa002dfe0
a002dfd0:  a0 04 20 01  inc  %l0
a002dfd4:  80 a4 00 15  cmp  %l0, %l5
a002dfd8:  08 bf ff fa  bleu  0xa002dfc0
a002dfdc:  01 00 00 00  nop
a002dfe0:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002dfe4:  7f ff f8 9e  call  0xa002c25c
a002dfe8:  d2 4c c0 00  ldsb  [ %l3 ], %o1
a002dfec:  d8 4c c0 00  ldsb  [ %l3 ], %o4
a002dff0:  80 a3 20 0a  cmp  %o4, 0xa
a002dff4:  a0 10 20 00  clr  %l0
a002dff8:  23 30 02 c0  sethi  %hi(0xc00b0000), %l1
a002dffc:  02 80 00 0c  be  0xa002e02c
a002e000:  a4 10 00 1d  mov  %i5, %l2
a002e004:  a6 04 e0 01  inc  %l3
a002e008:  e0 4c c0 00  ldsb  [ %l3 ], %l0
a002e00c:  80 a4 20 00  cmp  %l0, 0
a002e010:  32 bf ff ec  bne,a   0xa002dfc0
a002e014:  a0 10 20 00  clr  %l0
a002e018:  10 bf ff 19  b  0xa002dc7c
a002e01c:  b6 06 e0 01  inc  %i3
a002e020:  80 a4 00 12  cmp  %l0, %l2
a002e024:  18 80 00 08  bgu  0xa002e044
a002e028:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002e02c:  7f ff f8 89  call  0xa002c250
a002e030:  90 14 60 14  or  %l1, 0x14, %o0
a002e034:  80 8a 20 20  btst  0x20, %o0
a002e038:  02 bf ff fa  be  0xa002e020
a002e03c:  a0 04 20 01  inc  %l0
a002e040:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002e044:  7f ff f8 86  call  0xa002c25c
a002e048:  92 10 20 0d  mov  0xd, %o1
a002e04c:  10 bf ff ef  b  0xa002e008
a002e050:  a6 04 e0 01  inc  %l3
a002e054:  fa 4d 63 90  ldsb  [ %l5 + 0x390 ], %i5
a002e058:  80 a7 60 00  cmp  %i5, 0
a002e05c:  02 bf fe 9c  be  0xa002dacc
a002e060:  a6 15 63 90  or  %l5, 0x390, %l3
a002e064:  29 30 02 c0  sethi  %hi(0xc00b0000), %l4
a002e068:  aa 10 00 19  mov  %i1, %l5
a002e06c:  11 00 06 64  sethi  %hi(0x199000), %o0
a002e070:  fa 02 22 70  ld  [ %o0 + 0x270 ], %i5	! 0x199270
a002e074:  a0 10 20 00  clr  %l0
a002e078:  7f ff f8 76  call  0xa002c250
a002e07c:  90 15 20 14  or  %l4, 0x14, %o0
a002e080:  80 8a 20 20  btst  0x20, %o0
a002e084:  12 80 00 05  bne  0xa002e098
a002e088:  a0 04 20 01  inc  %l0
a002e08c:  80 a4 00 15  cmp  %l0, %l5
a002e090:  08 bf ff fa  bleu  0xa002e078
a002e094:  01 00 00 00  nop
a002e098:  d2 4c c0 00  ldsb  [ %l3 ], %o1
a002e09c:  7f ff f8 70  call  0xa002c25c
a002e0a0:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002e0a4:  d2 4c c0 00  ldsb  [ %l3 ], %o1
a002e0a8:  80 a2 60 0a  cmp  %o1, 0xa
a002e0ac:  a0 10 20 00  clr  %l0
a002e0b0:  23 30 02 c0  sethi  %hi(0xc00b0000), %l1
a002e0b4:  02 80 00 0c  be  0xa002e0e4
a002e0b8:  a4 10 00 1d  mov  %i5, %l2
a002e0bc:  a6 04 e0 01  inc  %l3
a002e0c0:  de 4c c0 00  ldsb  [ %l3 ], %o7
a002e0c4:  80 a3 e0 00  cmp  %o7, 0
a002e0c8:  32 bf ff ec  bne,a   0xa002e078
a002e0cc:  a0 10 20 00  clr  %l0
a002e0d0:  10 bf fe 80  b  0xa002dad0
a002e0d4:  d6 07 bf f4  ld  [ %fp + -12 ], %o3
a002e0d8:  80 a4 00 12  cmp  %l0, %l2
a002e0dc:  18 80 00 08  bgu  0xa002e0fc
a002e0e0:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002e0e4:  7f ff f8 5b  call  0xa002c250
a002e0e8:  90 14 60 14  or  %l1, 0x14, %o0
a002e0ec:  80 8a 20 20  btst  0x20, %o0
a002e0f0:  02 bf ff fa  be  0xa002e0d8
a002e0f4:  a0 04 20 01  inc  %l0
a002e0f8:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002e0fc:  7f ff f8 58  call  0xa002c25c
a002e100:  92 10 20 0d  mov  0xd, %o1
a002e104:  10 bf ff ef  b  0xa002e0c0
a002e108:  a6 04 e0 01  inc  %l3
a002e10c:  21 00 06 63  sethi  %hi(0x198c00), %l0
a002e110:  19 00 03 ff  sethi  %hi(0xffc00), %o4
a002e114:  a8 14 23 a0  or  %l0, 0x3a0, %l4
a002e118:  ac 13 23 fe  or  %o4, 0x3fe, %l6
a002e11c:  a2 10 20 00  clr  %l1
a002e120:  2b 30 02 c0  sethi  %hi(0xc00b0000), %l5
a002e124:  a6 10 20 04  mov  4, %l3
a002e128:  a5 3d c0 13  sra  %l7, %l3, %l2
a002e12c:  b0 0c a0 0f  and  %l2, 0xf, %i0
a002e130:  e4 0d 00 18  ldub  [ %l4 + %i0 ], %l2
a002e134:  10 80 00 05  b  0xa002e148
a002e138:  a0 10 20 00  clr  %l0
a002e13c:  80 a4 00 16  cmp  %l0, %l6
a002e140:  18 80 00 08  bgu  0xa002e160
a002e144:  b3 2c a0 18  sll  %l2, 0x18, %i1
a002e148:  7f ff f8 42  call  0xa002c250
a002e14c:  90 15 60 14  or  %l5, 0x14, %o0
a002e150:  80 8a 20 20  btst  0x20, %o0
a002e154:  02 bf ff fa  be  0xa002e13c
a002e158:  a0 04 20 01  inc  %l0
a002e15c:  b3 2c a0 18  sll  %l2, 0x18, %i1
a002e160:  93 3e 60 18  sra  %i1, 0x18, %o1
a002e164:  7f ff f8 3e  call  0xa002c25c
a002e168:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002e16c:  a2 04 60 01  inc  %l1
a002e170:  80 a4 60 01  cmp  %l1, 1
a002e174:  04 bf ff ed  ble  0xa002e128
a002e178:  a6 04 ff fc  add  %l3, -4, %l3
a002e17c:  10 bf fd 83  b  0xa002d788
a002e180:  2f 00 06 64  sethi  %hi(0x199000), %l7
a002e184:  e2 03 e0 04  ld  [ %o7 + 4 ], %l1
a002e188:  d2 4c 40 00  ldsb  [ %l1 ], %o1
a002e18c:  80 a2 60 00  cmp  %o1, 0
a002e190:  02 bf fd 7a  be  0xa002d778
a002e194:  ae 10 00 0b  mov  %o3, %l7
a002e198:  2d 30 02 c0  sethi  %hi(0xc00b0000), %l6
a002e19c:  ba 10 00 0a  mov  %o2, %i5
a002e1a0:  a0 10 20 00  clr  %l0
a002e1a4:  7f ff f8 2b  call  0xa002c250
a002e1a8:  90 15 a0 14  or  %l6, 0x14, %o0
a002e1ac:  80 8a 20 20  btst  0x20, %o0
a002e1b0:  12 80 00 05  bne  0xa002e1c4
a002e1b4:  a0 04 20 01  inc  %l0
a002e1b8:  80 a4 00 17  cmp  %l0, %l7
a002e1bc:  08 bf ff fa  bleu  0xa002e1a4
a002e1c0:  01 00 00 00  nop
a002e1c4:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002e1c8:  7f ff f8 25  call  0xa002c25c
a002e1cc:  d2 4c 40 00  ldsb  [ %l1 ], %o1
a002e1d0:  d4 4c 40 00  ldsb  [ %l1 ], %o2
a002e1d4:  80 a2 a0 0a  cmp  %o2, 0xa
a002e1d8:  a0 10 20 00  clr  %l0
a002e1dc:  27 30 02 c0  sethi  %hi(0xc00b0000), %l3
a002e1e0:  02 80 00 0c  be  0xa002e210
a002e1e4:  a8 10 00 1d  mov  %i5, %l4
a002e1e8:  a2 04 60 01  inc  %l1
a002e1ec:  d6 4c 40 00  ldsb  [ %l1 ], %o3
a002e1f0:  80 a2 e0 00  cmp  %o3, 0
a002e1f4:  32 bf ff ec  bne,a   0xa002e1a4
a002e1f8:  a0 10 20 00  clr  %l0
a002e1fc:  10 bf fd 60  b  0xa002d77c
a002e200:  80 a4 a0 11  cmp  %l2, 0x11
a002e204:  80 a4 00 14  cmp  %l0, %l4
a002e208:  18 80 00 08  bgu  0xa002e228
a002e20c:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002e210:  7f ff f8 10  call  0xa002c250
a002e214:  90 14 e0 14  or  %l3, 0x14, %o0
a002e218:  80 8a 20 20  btst  0x20, %o0
a002e21c:  02 bf ff fa  be  0xa002e204
a002e220:  a0 04 20 01  inc  %l0
a002e224:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a002e228:  7f ff f8 0d  call  0xa002c25c
a002e22c:  92 10 20 0d  mov  0xd, %o1
a002e230:  10 bf ff ef  b  0xa002e1ec
a002e234:  a2 04 60 01  inc  %l1
