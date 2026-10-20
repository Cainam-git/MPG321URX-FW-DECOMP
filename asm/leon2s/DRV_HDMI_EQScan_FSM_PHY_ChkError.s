# leon2s DRV_HDMI_EQScan_FSM_PHY_ChkError 0xa007d688-0xa007e7c0 (4408 bytes)
a007d688:  9d e3 bf 78  save  %sp, -136, %sp
a007d68c:  90 0e 20 ff  and  %i0, 0xff, %o0
a007d690:  1b 2a 01 ea  sethi  %hi(0xa807a800), %o5
a007d694:  9a 13 61 f0  or  %o5, 0x1f0, %o5	! 0xa807a9f0
a007d698:  82 5a 28 98  smul  %o0, 0x898, %g1
a007d69c:  a0 00 40 0d  add  %g1, %o5, %l0
a007d6a0:  d6 0c 20 30  ldub  [ %l0 + 0x30 ], %o3
a007d6a4:  98 10 20 00  clr  %o4
a007d6a8:  9a 10 20 00  clr  %o5
a007d6ac:  a6 10 00 18  mov  %i0, %l3
a007d6b0:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a007d6b4:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a007d6b8:  c0 27 bf f0  clr  [ %fp + -16 ]
a007d6bc:  c0 27 bf e0  clr  [ %fp + -32 ]
a007d6c0:  80 a2 e0 05  cmp  %o3, 5
a007d6c4:  18 80 00 0b  bgu  0xa007d6f0
a007d6c8:  aa 10 20 00  clr  %l5
a007d6cc:  80 a2 e0 00  cmp  %o3, 0
a007d6d0:  32 80 00 05  bne,a   0xa007d6e4
a007d6d4:  c2 0c 20 30  ldub  [ %l0 + 0x30 ], %g1
a007d6d8:  7f ff dd d8  call  0xa0074e38
a007d6dc:  01 00 00 00  nop
a007d6e0:  c2 0c 20 30  ldub  [ %l0 + 0x30 ], %g1
a007d6e4:  82 00 60 01  inc  %g1
a007d6e8:  10 80 04 05  b  0xa007e6fc
a007d6ec:  c2 2c 20 30  stb  %g1, [ %l0 + 0x30 ]
a007d6f0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007d6f4:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007d6f8:  80 88 60 02  btst  2, %g1
a007d6fc:  02 80 00 0b  be  0xa007d728
a007d700:  a2 0d 60 ff  and  %l5, 0xff, %l1
a007d704:  92 06 20 41  add  %i0, 0x41, %o1
a007d708:  93 2a 60 18  sll  %o1, 0x18, %o1
a007d70c:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a007d710:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a007d714:  90 12 21 f8  or  %o0, 0x1f8, %o0
a007d718:  93 3a 60 18  sra  %o1, 0x18, %o1
a007d71c:  7f ff d6 4a  call  0xa0073044
a007d720:  94 12 a2 d8  or  %o2, 0x2d8, %o2
a007d724:  a2 0d 60 ff  and  %l5, 0xff, %l1
a007d728:  80 a4 60 00  cmp  %l1, 0
a007d72c:  12 80 00 20  bne  0xa007d7ac
a007d730:  80 a4 60 01  cmp  %l1, 1
a007d734:  a4 0c e0 ff  and  %l3, 0xff, %l2
a007d738:  21 00 00 07  sethi  %hi(0x1c00), %l0
a007d73c:  90 10 20 00  clr  %o0
a007d740:  92 10 00 12  mov  %l2, %o1
a007d744:  40 00 a7 49  call  0xa00a7468
a007d748:  94 14 22 a0  or  %l0, 0x2a0, %o2
a007d74c:  80 a2 20 00  cmp  %o0, 0
a007d750:  a8 07 bf f8  add  %fp, -8, %l4
a007d754:  12 80 00 06  bne  0xa007d76c
a007d758:  90 10 20 00  clr  %o0
a007d75c:  92 14 22 94  or  %l0, 0x294, %o1
a007d760:  40 00 a6 ed  call  0xa00a7314
a007d764:  90 10 00 12  mov  %l2, %o0
a007d768:  91 32 20 18  srl  %o0, 0x18, %o0
a007d76c:  23 00 00 07  sethi  %hi(0x1c00), %l1
a007d770:  d0 25 3f f0  st  %o0, [ %l4 + -16 ]
a007d774:  92 14 62 a0  or  %l1, 0x2a0, %o1
a007d778:  40 00 a6 e7  call  0xa00a7314
a007d77c:  90 10 00 12  mov  %l2, %o0
a007d780:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a007d784:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00
a007d788:  a0 0a 00 01  and  %o0, %g1, %l0
a007d78c:  90 10 00 12  mov  %l2, %o0
a007d790:  40 00 a6 e1  call  0xa00a7314
a007d794:  92 14 62 a0  or  %l1, 0x2a0, %o1
a007d798:  91 32 20 10  srl  %o0, 0x10, %o0
a007d79c:  90 0a 20 ff  and  %o0, 0xff, %o0
a007d7a0:  a0 14 00 08  or  %l0, %o0, %l0
a007d7a4:  10 80 00 41  b  0xa007d8a8
a007d7a8:  e0 25 3f e0  st  %l0, [ %l4 + -32 ]
a007d7ac:  b0 0c e0 ff  and  %l3, 0xff, %i0
a007d7b0:  12 80 00 1e  bne  0xa007d828
a007d7b4:  ac 07 bf f8  add  %fp, -8, %l6
a007d7b8:  21 00 00 07  sethi  %hi(0x1c00), %l0
a007d7bc:  90 10 20 01  mov  1, %o0
a007d7c0:  92 10 00 18  mov  %i0, %o1
a007d7c4:  40 00 a7 29  call  0xa00a7468
a007d7c8:  94 14 22 a0  or  %l0, 0x2a0, %o2
a007d7cc:  80 a2 20 00  cmp  %o0, 0
a007d7d0:  12 80 00 06  bne  0xa007d7e8
a007d7d4:  90 10 20 00  clr  %o0
a007d7d8:  92 14 22 98  or  %l0, 0x298, %o1
a007d7dc:  40 00 a6 ce  call  0xa00a7314
a007d7e0:  90 10 00 18  mov  %i0, %o0
a007d7e4:  90 0a 20 ff  and  %o0, 0xff, %o0
a007d7e8:  82 07 bf fc  add  %fp, -4, %g1
a007d7ec:  d0 20 7f f0  st  %o0, [ %g1 + -16 ]
a007d7f0:  23 00 00 07  sethi  %hi(0x1c00), %l1
a007d7f4:  92 14 62 a0  or  %l1, 0x2a0, %o1	! 0x1ea0
a007d7f8:  40 00 a6 c7  call  0xa00a7314
a007d7fc:  90 10 00 18  mov  %i0, %o0
a007d800:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a007d804:  a0 0a 00 01  and  %o0, %g1, %l0
a007d808:  90 10 00 18  mov  %i0, %o0
a007d80c:  40 00 a6 c2  call  0xa00a7314
a007d810:  92 14 62 a4  or  %l1, 0x2a4, %o1
a007d814:  a1 34 20 10  srl  %l0, 0x10, %l0
a007d818:  90 0a 20 ff  and  %o0, 0xff, %o0
a007d81c:  a0 14 00 08  or  %l0, %o0, %l0
a007d820:  10 80 00 22  b  0xa007d8a8
a007d824:  e0 27 bf dc  st  %l0, [ %fp + -36 ]
a007d828:  83 2c 60 02  sll  %l1, 2, %g1
a007d82c:  21 00 00 07  sethi  %hi(0x1c00), %l0
a007d830:  a8 00 40 16  add  %g1, %l6, %l4
a007d834:  90 10 20 02  mov  2, %o0
a007d838:  92 10 00 18  mov  %i0, %o1
a007d83c:  40 00 a7 0b  call  0xa00a7468
a007d840:  94 14 22 a0  or  %l0, 0x2a0, %o2
a007d844:  80 a2 20 00  cmp  %o0, 0
a007d848:  12 80 00 07  bne  0xa007d864
a007d84c:  90 10 20 00  clr  %o0
a007d850:  92 14 22 98  or  %l0, 0x298, %o1
a007d854:  40 00 a6 b0  call  0xa00a7314
a007d858:  90 10 00 18  mov  %i0, %o0
a007d85c:  91 32 20 08  srl  %o0, 8, %o0
a007d860:  90 0a 20 ff  and  %o0, 0xff, %o0
a007d864:  25 00 00 07  sethi  %hi(0x1c00), %l2
a007d868:  d0 25 3f f0  st  %o0, [ %l4 + -16 ]
a007d86c:  92 14 a2 a4  or  %l2, 0x2a4, %o1
a007d870:  40 00 a6 a9  call  0xa00a7314
a007d874:  90 10 00 18  mov  %i0, %o0
a007d878:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a007d87c:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00
a007d880:  a0 0a 00 01  and  %o0, %g1, %l0
a007d884:  90 10 00 18  mov  %i0, %o0
a007d888:  40 00 a6 a3  call  0xa00a7314
a007d88c:  92 14 a2 a4  or  %l2, 0x2a4, %o1
a007d890:  91 32 20 10  srl  %o0, 0x10, %o0
a007d894:  a3 2c 60 02  sll  %l1, 2, %l1
a007d898:  90 0a 20 ff  and  %o0, 0xff, %o0
a007d89c:  a2 04 40 16  add  %l1, %l6, %l1
a007d8a0:  a0 14 00 08  or  %l0, %o0, %l0
a007d8a4:  e0 24 7f e0  st  %l0, [ %l1 + -32 ]
a007d8a8:  a2 0d 60 ff  and  %l5, 0xff, %l1
a007d8ac:  83 2c 60 02  sll  %l1, 2, %g1
a007d8b0:  a4 07 bf f8  add  %fp, -8, %l2
a007d8b4:  a0 00 40 12  add  %g1, %l2, %l0
a007d8b8:  c2 04 3f f0  ld  [ %l0 + -16 ], %g1
a007d8bc:  80 88 60 20  btst  0x20, %g1
a007d8c0:  12 80 00 24  bne  0xa007d950
a007d8c4:  83 2c 60 02  sll  %l1, 2, %g1
a007d8c8:  da 04 3f e0  ld  [ %l0 + -32 ], %o5
a007d8cc:  03 00 00 20  sethi  %hi(0x8000), %g1
a007d8d0:  80 a3 40 01  cmp  %o5, %g1
a007d8d4:  12 80 00 1f  bne  0xa007d950
a007d8d8:  83 2c 60 02  sll  %l1, 2, %g1
a007d8dc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007d8e0:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007d8e4:  80 88 60 02  btst  2, %g1
a007d8e8:  02 80 00 12  be  0xa007d930
a007d8ec:  82 0c e0 ff  and  %l3, 0xff, %g1
a007d8f0:  13 00 00 07  sethi  %hi(0x1c00), %o1
a007d8f4:  92 12 62 a0  or  %o1, 0x2a0, %o1	! 0x1ea0
a007d8f8:  40 00 a6 87  call  0xa00a7314
a007d8fc:  90 0c e0 ff  and  %l3, 0xff, %o0
a007d900:  92 04 e0 41  add  %l3, 0x41, %o1
a007d904:  98 0a 20 ff  and  %o0, 0xff, %o4
a007d908:  93 2a 60 18  sll  %o1, 0x18, %o1
a007d90c:  c2 04 3f e0  ld  [ %l0 + -32 ], %g1
a007d910:  17 3f ff e0  sethi  %hi(0xffff8000), %o3
a007d914:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007d918:  96 28 40 0b  andn  %g1, %o3, %o3
a007d91c:  90 12 20 a8  or  %o0, 0xa8, %o0
a007d920:  93 3a 60 18  sra  %o1, 0x18, %o1
a007d924:  7f ff d5 c8  call  0xa0073044
a007d928:  94 10 00 11  mov  %l1, %o2
a007d92c:  82 0c e0 ff  and  %l3, 0xff, %g1
a007d930:  1b 2a 01 ea  sethi  %hi(0xa807a800), %o5
a007d934:  9a 13 61 f0  or  %o5, 0x1f0, %o5	! 0xa807a9f0
a007d938:  82 58 68 98  smul  %g1, 0x898, %g1
a007d93c:  82 00 40 0d  add  %g1, %o5, %g1
a007d940:  82 00 40 11  add  %g1, %l1, %g1
a007d944:  9a 10 20 01  mov  1, %o5
a007d948:  10 80 00 40  b  0xa007da48
a007d94c:  da 28 60 31  stb  %o5, [ %g1 + 0x31 ]
a007d950:  82 00 40 12  add  %g1, %l2, %g1
a007d954:  da 00 7f e0  ld  [ %g1 + -32 ], %o5
a007d958:  03 00 00 20  sethi  %hi(0x8000), %g1
a007d95c:  80 a3 40 01  cmp  %o5, %g1
a007d960:  02 80 00 3a  be  0xa007da48
a007d964:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007d968:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007d96c:  80 88 60 02  btst  2, %g1
a007d970:  02 80 00 0c  be  0xa007d9a0
a007d974:  92 0c e0 ff  and  %l3, 0xff, %o1
a007d978:  92 04 e0 41  add  %l3, 0x41, %o1
a007d97c:  93 2a 60 18  sll  %o1, 0x18, %o1
a007d980:  17 3f ff e0  sethi  %hi(0xffff8000), %o3
a007d984:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007d988:  96 2b 40 0b  andn  %o5, %o3, %o3
a007d98c:  90 12 20 e0  or  %o0, 0xe0, %o0
a007d990:  93 3a 60 18  sra  %o1, 0x18, %o1
a007d994:  7f ff d5 ac  call  0xa0073044
a007d998:  94 10 00 11  mov  %l1, %o2
a007d99c:  92 0c e0 ff  and  %l3, 0xff, %o1
a007d9a0:  17 2a 01 ea  sethi  %hi(0xa807a800), %o3
a007d9a4:  82 12 e1 f0  or  %o3, 0x1f0, %g1	! 0xa807a9f0
a007d9a8:  98 5a 68 98  smul  %o1, 0x898, %o4
a007d9ac:  98 03 00 01  add  %o4, %g1, %o4
a007d9b0:  9a 02 40 09  add  %o1, %o1, %o5
a007d9b4:  9a 03 40 09  add  %o5, %o1, %o5
a007d9b8:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a007d9bc:  82 10 60 c4  or  %g1, 0xc4, %g1	! 0xa807ccc4
a007d9c0:  9b 2b 60 02  sll  %o5, 2, %o5
a007d9c4:  9a 03 40 01  add  %o5, %g1, %o5
a007d9c8:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a007d9cc:  98 03 00 11  add  %o4, %l1, %o4
a007d9d0:  80 a0 60 00  cmp  %g1, 0
a007d9d4:  c0 2b 20 31  clrb  [ %o4 + 0x31 ]
a007d9d8:  02 80 00 07  be  0xa007d9f4
a007d9dc:  c2 0b 20 09  ldub  [ %o4 + 9 ], %g1
a007d9e0:  80 a0 60 02  cmp  %g1, 2
a007d9e4:  28 80 00 08  bleu,a   0xa007da04
a007d9e8:  96 12 e1 f0  or  %o3, 0x1f0, %o3
a007d9ec:  10 80 00 18  b  0xa007da4c
a007d9f0:  aa 05 60 01  inc  %l5
a007d9f4:  80 a0 60 00  cmp  %g1, 0
a007d9f8:  32 80 00 15  bne,a   0xa007da4c
a007d9fc:  aa 05 60 01  inc  %l5
a007da00:  96 12 e1 f0  or  %o3, 0x1f0, %o3
a007da04:  82 5a 68 98  smul  %o1, 0x898, %g1
a007da08:  82 00 40 0b  add  %g1, %o3, %g1
a007da0c:  82 00 40 11  add  %g1, %l1, %g1
a007da10:  c2 08 60 09  ldub  [ %g1 + 9 ], %g1
a007da14:  9a 00 40 01  add  %g1, %g1, %o5
a007da18:  9a 03 40 01  add  %o5, %g1, %o5
a007da1c:  82 5a 62 26  smul  %o1, 0x226, %g1
a007da20:  9a 03 40 01  add  %o5, %g1, %o5
a007da24:  83 2c 60 02  sll  %l1, 2, %g1
a007da28:  82 00 40 12  add  %g1, %l2, %g1
a007da2c:  d8 00 7f e0  ld  [ %g1 + -32 ], %o4
a007da30:  9a 03 40 11  add  %o5, %l1, %o5
a007da34:  9b 2b 60 02  sll  %o5, 2, %o5
a007da38:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a007da3c:  9a 03 40 0b  add  %o5, %o3, %o5
a007da40:  82 2b 00 01  andn  %o4, %g1, %g1
a007da44:  c2 23 60 38  st  %g1, [ %o5 + 0x38 ]
a007da48:  aa 05 60 01  inc  %l5
a007da4c:  82 0d 60 ff  and  %l5, 0xff, %g1
a007da50:  80 a0 60 02  cmp  %g1, 2
a007da54:  08 bf ff 35  bleu  0xa007d728
a007da58:  a2 0d 60 ff  and  %l5, 0xff, %l1
a007da5c:  b0 0c e0 ff  and  %l3, 0xff, %i0
a007da60:  82 06 00 18  add  %i0, %i0, %g1
a007da64:  82 00 40 18  add  %g1, %i0, %g1
a007da68:  2d 2a 01 f3  sethi  %hi(0xa807cc00), %l6
a007da6c:  83 28 60 02  sll  %g1, 2, %g1
a007da70:  9a 15 a0 c4  or  %l6, 0xc4, %o5
a007da74:  82 00 40 0d  add  %g1, %o5, %g1
a007da78:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a007da7c:  80 a0 60 00  cmp  %g1, 0
a007da80:  02 80 00 3e  be  0xa007db78
a007da84:  2f 2a 01 ea  sethi  %hi(0xa807a800), %l7
a007da88:  13 00 00 04  sethi  %hi(0x1000), %o1
a007da8c:  92 12 61 78  or  %o1, 0x178, %o1	! 0x1178
a007da90:  40 00 a6 21  call  0xa00a7314
a007da94:  90 10 00 18  mov  %i0, %o0
a007da98:  80 8a 20 0f  btst  0xf, %o0
a007da9c:  02 80 00 11  be  0xa007dae0
a007daa0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007daa4:  13 00 00 05  sethi  %hi(0x1400), %o1
a007daa8:  92 12 61 78  or  %o1, 0x178, %o1	! 0x1578
a007daac:  40 00 a6 1a  call  0xa00a7314
a007dab0:  90 10 00 18  mov  %i0, %o0
a007dab4:  80 8a 20 0f  btst  0xf, %o0
a007dab8:  02 80 00 0a  be  0xa007dae0
a007dabc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007dac0:  13 00 00 06  sethi  %hi(0x1800), %o1
a007dac4:  92 12 61 78  or  %o1, 0x178, %o1	! 0x1978
a007dac8:  40 00 a6 13  call  0xa00a7314
a007dacc:  90 10 00 18  mov  %i0, %o0
a007dad0:  80 8a 20 0f  btst  0xf, %o0
a007dad4:  12 80 00 29  bne  0xa007db78
a007dad8:  2f 2a 01 ea  sethi  %hi(0xa807a800), %l7
a007dadc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007dae0:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007dae4:  80 88 60 02  btst  2, %g1
a007dae8:  02 80 00 1a  be  0xa007db50
a007daec:  9a 0c e0 ff  and  %l3, 0xff, %o5
a007daf0:  13 00 00 04  sethi  %hi(0x1000), %o1
a007daf4:  92 12 61 78  or  %o1, 0x178, %o1	! 0x1178
a007daf8:  40 00 a6 07  call  0xa00a7314
a007dafc:  90 10 00 18  mov  %i0, %o0
a007db00:  a2 0a 20 0f  and  %o0, 0xf, %l1
a007db04:  13 00 00 05  sethi  %hi(0x1400), %o1
a007db08:  92 12 61 78  or  %o1, 0x178, %o1	! 0x1578
a007db0c:  40 00 a6 02  call  0xa00a7314
a007db10:  90 10 00 18  mov  %i0, %o0
a007db14:  a0 0a 20 0f  and  %o0, 0xf, %l0
a007db18:  13 00 00 06  sethi  %hi(0x1800), %o1
a007db1c:  92 12 61 78  or  %o1, 0x178, %o1	! 0x1978
a007db20:  40 00 a5 fd  call  0xa00a7314
a007db24:  90 10 00 18  mov  %i0, %o0
a007db28:  92 04 e0 41  add  %l3, 0x41, %o1
a007db2c:  98 0a 20 0f  and  %o0, 0xf, %o4
a007db30:  93 2a 60 18  sll  %o1, 0x18, %o1
a007db34:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007db38:  90 12 21 08  or  %o0, 0x108, %o0	! 0xa0067d08
a007db3c:  93 3a 60 18  sra  %o1, 0x18, %o1
a007db40:  94 10 00 11  mov  %l1, %o2
a007db44:  7f ff d5 40  call  0xa0073044
a007db48:  96 10 00 10  mov  %l0, %o3
a007db4c:  9a 0c e0 ff  and  %l3, 0xff, %o5
a007db50:  82 03 40 0d  add  %o5, %o5, %g1
a007db54:  82 00 40 0d  add  %g1, %o5, %g1
a007db58:  83 28 60 02  sll  %g1, 2, %g1
a007db5c:  9a 10 20 04  mov  4, %o5
a007db60:  98 15 a0 c4  or  %l6, 0xc4, %o4
a007db64:  da 23 00 01  st  %o5, [ %o4 + %g1 ]
a007db68:  9a 10 20 01  mov  1, %o5
a007db6c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007db70:  10 80 03 11  b  0xa007e7b4
a007db74:  da 28 61 8c  stb  %o5, [ %g1 + 0x18c ]	! 0xa807898c
a007db78:  82 15 e1 f0  or  %l7, 0x1f0, %g1
a007db7c:  9a 5e 28 98  smul  %i0, 0x898, %o5
a007db80:  a4 03 40 01  add  %o5, %g1, %l2
a007db84:  c2 0c a0 31  ldub  [ %l2 + 0x31 ], %g1
a007db88:  80 a0 60 01  cmp  %g1, 1
a007db8c:  12 80 00 c2  bne  0xa007de94
a007db90:  29 2a 01 e1  sethi  %hi(0xa8078400), %l4
a007db94:  c2 0c a0 32  ldub  [ %l2 + 0x32 ], %g1
a007db98:  80 a0 60 01  cmp  %g1, 1
a007db9c:  12 80 00 bf  bne  0xa007de98
a007dba0:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007dba4:  ea 0c a0 33  ldub  [ %l2 + 0x33 ], %l5
a007dba8:  80 a5 60 01  cmp  %l5, 1
a007dbac:  12 80 00 bc  bne  0xa007de9c
a007dbb0:  80 88 60 02  btst  2, %g1
a007dbb4:  7f ff fd 63  call  0xa007d140
a007dbb8:  90 10 00 18  mov  %i0, %o0
a007dbbc:  80 8a 20 ff  btst  0xff, %o0
a007dbc0:  32 80 00 59  bne,a   0xa007dd24
a007dbc4:  29 2a 01 e1  sethi  %hi(0xa8078400), %l4
a007dbc8:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007dbcc:  90 12 21 48  or  %o0, 0x148, %o0	! 0xa0067d48
a007dbd0:  7f ff d5 1d  call  0xa0073044
a007dbd4:  92 10 20 63  mov  0x63, %o1
a007dbd8:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a007dbdc:  96 14 61 90  or  %l1, 0x190, %o3	! 0xa8078990
a007dbe0:  c2 0a c0 18  ldub  [ %o3 + %i0 ], %g1
a007dbe4:  82 00 60 01  inc  %g1
a007dbe8:  19 00 00 1f  sethi  %hi(0x7c00), %o4
a007dbec:  c2 2a c0 18  stb  %g1, [ %o3 + %i0 ]
a007dbf0:  94 13 23 ff  or  %o4, 0x3ff, %o2
a007dbf4:  da 07 bf d8  ld  [ %fp + -40 ], %o5
a007dbf8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007dbfc:  9a 0b 40 0a  and  %o5, %o2, %o5
a007dc00:  98 13 23 fe  or  %o4, 0x3fe, %o4
a007dc04:  82 10 61 98  or  %g1, 0x198, %g1
a007dc08:  80 a3 40 0c  cmp  %o5, %o4
a007dc0c:  08 80 00 0c  bleu  0xa007dc3c
a007dc10:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a007dc14:  c2 07 bf dc  ld  [ %fp + -36 ], %g1
a007dc18:  82 08 40 0a  and  %g1, %o2, %g1
a007dc1c:  80 a0 40 0c  cmp  %g1, %o4
a007dc20:  08 80 00 08  bleu  0xa007dc40
a007dc24:  21 00 00 07  sethi  %hi(0x1c00), %l0
a007dc28:  c2 07 bf e0  ld  [ %fp + -32 ], %g1
a007dc2c:  82 08 40 0a  and  %g1, %o2, %g1
a007dc30:  80 a0 40 0c  cmp  %g1, %o4
a007dc34:  38 80 00 26  bgu,a   0xa007dccc
a007dc38:  a4 0c e0 ff  and  %l3, 0xff, %l2
a007dc3c:  21 00 00 07  sethi  %hi(0x1c00), %l0
a007dc40:  90 10 20 10  mov  0x10, %o0
a007dc44:  92 10 00 18  mov  %i0, %o1
a007dc48:  40 00 a6 08  call  0xa00a7468
a007dc4c:  94 14 22 94  or  %l0, 0x294, %o2
a007dc50:  80 a2 20 01  cmp  %o0, 1
a007dc54:  32 80 00 1e  bne,a   0xa007dccc
a007dc58:  a4 0c e0 ff  and  %l3, 0xff, %l2
a007dc5c:  90 10 20 11  mov  0x11, %o0
a007dc60:  92 10 00 18  mov  %i0, %o1
a007dc64:  40 00 a6 01  call  0xa00a7468
a007dc68:  94 14 22 94  or  %l0, 0x294, %o2
a007dc6c:  80 a2 20 01  cmp  %o0, 1
a007dc70:  32 80 00 17  bne,a   0xa007dccc
a007dc74:  a4 0c e0 ff  and  %l3, 0xff, %l2
a007dc78:  94 14 22 94  or  %l0, 0x294, %o2
a007dc7c:  90 10 20 12  mov  0x12, %o0
a007dc80:  40 00 a5 fa  call  0xa00a7468
a007dc84:  92 10 00 18  mov  %i0, %o1
a007dc88:  80 a2 20 01  cmp  %o0, 1
a007dc8c:  12 80 00 10  bne  0xa007dccc
a007dc90:  a4 0c e0 ff  and  %l3, 0xff, %l2
a007dc94:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007dc98:  da 00 62 34  ld  [ %g1 + 0x234 ], %o5	! 0xa8078634
a007dc9c:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a007dca0:  82 10 61 98  or  %g1, 0x198, %g1	! 0xa8076198
a007dca4:  80 8b 60 02  btst  2, %o5
a007dca8:  02 80 00 09  be  0xa007dccc
a007dcac:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a007dcb0:  92 04 e0 41  add  %l3, 0x41, %o1
a007dcb4:  93 2a 60 18  sll  %o1, 0x18, %o1
a007dcb8:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007dcbc:  90 12 20 18  or  %o0, 0x18, %o0	! 0xa0067c18
a007dcc0:  7f ff d4 e1  call  0xa0073044
a007dcc4:  93 3a 60 18  sra  %o1, 0x18, %o1
a007dcc8:  a4 0c e0 ff  and  %l3, 0xff, %l2
a007dccc:  7f ff dd 2c  call  0xa007517c
a007dcd0:  90 10 00 12  mov  %l2, %o0
a007dcd4:  80 8a 20 ff  btst  0xff, %o0
a007dcd8:  02 80 00 06  be  0xa007dcf0
a007dcdc:  a0 14 61 90  or  %l1, 0x190, %l0
a007dce0:  90 10 00 12  mov  %l2, %o0
a007dce4:  7f ff e8 61  call  0xa0077e68
a007dce8:  92 10 20 00  clr  %o1
a007dcec:  a0 14 61 90  or  %l1, 0x190, %l0
a007dcf0:  c2 0c 00 12  ldub  [ %l0 + %l2 ], %g1
a007dcf4:  80 a0 60 0a  cmp  %g1, 0xa
a007dcf8:  08 80 00 06  bleu  0xa007dd10
a007dcfc:  82 04 80 12  add  %l2, %l2, %g1
a007dd00:  7f ff e8 5f  call  0xa0077e7c
a007dd04:  90 10 00 12  mov  %l2, %o0
a007dd08:  c0 2c 00 12  clrb  [ %l0 + %l2 ]
a007dd0c:  82 04 80 12  add  %l2, %l2, %g1
a007dd10:  82 00 40 12  add  %g1, %l2, %g1
a007dd14:  9a 15 a0 c4  or  %l6, 0xc4, %o5
a007dd18:  83 28 60 02  sll  %g1, 2, %g1
a007dd1c:  10 80 02 78  b  0xa007e6fc
a007dd20:  c0 23 40 01  clr  [ %o5 + %g1 ]
a007dd24:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007dd28:  80 88 60 02  btst  2, %g1
a007dd2c:  02 80 00 4b  be  0xa007de58
a007dd30:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a007dd34:  23 00 00 04  sethi  %hi(0x1000), %l1
a007dd38:  92 14 61 78  or  %l1, 0x178, %o1	! 0x1178
a007dd3c:  40 00 a5 76  call  0xa00a7314
a007dd40:  90 10 00 18  mov  %i0, %o0
a007dd44:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a007dd48:  82 10 63 00  or  %g1, 0x300, %g1	! 0xffff00
a007dd4c:  a0 0a 00 01  and  %o0, %g1, %l0
a007dd50:  92 14 61 78  or  %l1, 0x178, %o1
a007dd54:  40 00 a5 70  call  0xa00a7314
a007dd58:  90 10 00 18  mov  %i0, %o0
a007dd5c:  96 0a 20 0f  and  %o0, 0xf, %o3
a007dd60:  92 04 e0 41  add  %l3, 0x41, %o1
a007dd64:  a1 34 20 08  srl  %l0, 8, %l0
a007dd68:  93 2a 60 18  sll  %o1, 0x18, %o1
a007dd6c:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a007dd70:  90 12 21 b8  or  %o0, 0x1b8, %o0	! 0xa00671b8
a007dd74:  93 3a 60 18  sra  %o1, 0x18, %o1
a007dd78:  7f ff d4 b3  call  0xa0073044
a007dd7c:  94 10 00 10  mov  %l0, %o2
a007dd80:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007dd84:  80 88 60 02  btst  2, %g1
a007dd88:  02 80 00 33  be  0xa007de54
a007dd8c:  a2 04 64 00  add  %l1, 0x400, %l1
a007dd90:  92 14 61 78  or  %l1, 0x178, %o1
a007dd94:  40 00 a5 60  call  0xa00a7314
a007dd98:  90 10 00 18  mov  %i0, %o0
a007dd9c:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a007dda0:  82 10 63 00  or  %g1, 0x300, %g1	! 0xffff00
a007dda4:  a0 0a 00 01  and  %o0, %g1, %l0
a007dda8:  92 14 61 78  or  %l1, 0x178, %o1
a007ddac:  40 00 a5 5a  call  0xa00a7314
a007ddb0:  90 10 00 18  mov  %i0, %o0
a007ddb4:  96 0a 20 0f  and  %o0, 0xf, %o3
a007ddb8:  92 04 e0 41  add  %l3, 0x41, %o1
a007ddbc:  a1 34 20 08  srl  %l0, 8, %l0
a007ddc0:  93 2a 60 18  sll  %o1, 0x18, %o1
a007ddc4:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a007ddc8:  90 12 21 f0  or  %o0, 0x1f0, %o0	! 0xa00671f0
a007ddcc:  93 3a 60 18  sra  %o1, 0x18, %o1
a007ddd0:  7f ff d4 9d  call  0xa0073044
a007ddd4:  94 10 00 10  mov  %l0, %o2
a007ddd8:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007dddc:  80 88 60 02  btst  2, %g1
a007dde0:  02 80 00 1d  be  0xa007de54
a007dde4:  a2 04 64 00  add  %l1, 0x400, %l1
a007dde8:  92 14 61 78  or  %l1, 0x178, %o1
a007ddec:  40 00 a5 4a  call  0xa00a7314
a007ddf0:  90 10 00 18  mov  %i0, %o0
a007ddf4:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a007ddf8:  82 10 63 00  or  %g1, 0x300, %g1	! 0xffff00
a007ddfc:  a0 0a 00 01  and  %o0, %g1, %l0
a007de00:  92 14 61 78  or  %l1, 0x178, %o1
a007de04:  40 00 a5 44  call  0xa00a7314
a007de08:  90 10 00 18  mov  %i0, %o0
a007de0c:  96 0a 20 0f  and  %o0, 0xf, %o3
a007de10:  92 04 e0 41  add  %l3, 0x41, %o1
a007de14:  a1 34 20 08  srl  %l0, 8, %l0
a007de18:  93 2a 60 18  sll  %o1, 0x18, %o1
a007de1c:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a007de20:  90 12 22 28  or  %o0, 0x228, %o0	! 0xa0067228
a007de24:  93 3a 60 18  sra  %o1, 0x18, %o1
a007de28:  7f ff d4 87  call  0xa0073044
a007de2c:  94 10 00 10  mov  %l0, %o2
a007de30:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007de34:  80 88 60 02  btst  2, %g1
a007de38:  02 80 00 07  be  0xa007de54
a007de3c:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007de40:  92 04 e0 41  add  %l3, 0x41, %o1
a007de44:  93 2a 60 18  sll  %o1, 0x18, %o1
a007de48:  90 12 21 70  or  %o0, 0x170, %o0
a007de4c:  7f ff d4 7e  call  0xa0073044
a007de50:  93 3a 60 18  sra  %o1, 0x18, %o1
a007de54:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a007de58:  c2 08 61 9f  ldub  [ %g1 + 0x19f ], %g1	! 0xa807619f
a007de5c:  80 a0 60 00  cmp  %g1, 0
a007de60:  02 80 00 06  be  0xa007de78
a007de64:  82 06 00 18  add  %i0, %i0, %g1
a007de68:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007de6c:  82 10 61 98  or  %g1, 0x198, %g1	! 0xa8078998
a007de70:  ea 28 40 18  stb  %l5, [ %g1 + %i0 ]
a007de74:  82 06 00 18  add  %i0, %i0, %g1
a007de78:  82 00 40 18  add  %g1, %i0, %g1
a007de7c:  98 15 a0 c4  or  %l6, 0xc4, %o4
a007de80:  83 28 60 02  sll  %g1, 2, %g1
a007de84:  9a 10 20 10  mov  0x10, %o5
a007de88:  da 23 00 01  st  %o5, [ %o4 + %g1 ]
a007de8c:  10 80 02 4a  b  0xa007e7b4
a007de90:  c0 2c a8 96  clrb  [ %l2 + 0x896 ]
a007de94:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007de98:  80 88 60 02  btst  2, %g1
a007de9c:  02 80 00 f0  be  0xa007e25c
a007dea0:  aa 15 22 34  or  %l4, 0x234, %l5
a007dea4:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007dea8:  7f ff d4 67  call  0xa0073044
a007deac:  90 12 21 98  or  %o0, 0x198, %o0	! 0xa0067d98
a007deb0:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007deb4:  80 88 60 02  btst  2, %g1
a007deb8:  02 80 00 9d  be  0xa007e12c
a007debc:  82 06 00 18  add  %i0, %i0, %g1
a007dec0:  82 00 40 18  add  %g1, %i0, %g1
a007dec4:  9a 15 a0 c4  or  %l6, 0xc4, %o5
a007dec8:  83 28 60 02  sll  %g1, 2, %g1
a007decc:  92 04 e0 41  add  %l3, 0x41, %o1
a007ded0:  82 00 40 0d  add  %g1, %o5, %g1
a007ded4:  93 2a 60 18  sll  %o1, 0x18, %o1
a007ded8:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007dedc:  d4 08 60 07  ldub  [ %g1 + 7 ], %o2
a007dee0:  90 12 21 e8  or  %o0, 0x1e8, %o0
a007dee4:  7f ff d4 58  call  0xa0073044
a007dee8:  93 3a 60 18  sra  %o1, 0x18, %o1
a007deec:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007def0:  80 88 60 02  btst  2, %g1
a007def4:  22 80 00 8f  be,a   0xa007e130
a007def8:  c2 05 40 00  ld  [ %l5 ], %g1
a007defc:  13 00 00 07  sethi  %hi(0x1c00), %o1
a007df00:  92 12 62 a0  or  %o1, 0x2a0, %o1	! 0x1ea0
a007df04:  40 00 a5 04  call  0xa00a7314
a007df08:  90 0c e0 ff  and  %l3, 0xff, %o0
a007df0c:  96 0a 20 ff  and  %o0, 0xff, %o3
a007df10:  92 04 e0 41  add  %l3, 0x41, %o1
a007df14:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a007df18:  d4 07 bf d8  ld  [ %fp + -40 ], %o2
a007df1c:  93 2a 60 18  sll  %o1, 0x18, %o1
a007df20:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007df24:  94 2a 80 01  andn  %o2, %g1, %o2
a007df28:  90 12 22 10  or  %o0, 0x210, %o0
a007df2c:  7f ff d4 46  call  0xa0073044
a007df30:  93 3a 60 18  sra  %o1, 0x18, %o1
a007df34:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007df38:  80 88 60 02  btst  2, %g1
a007df3c:  02 80 00 7c  be  0xa007e12c
a007df40:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a007df44:  92 04 e0 41  add  %l3, 0x41, %o1
a007df48:  d4 07 bf dc  ld  [ %fp + -36 ], %o2
a007df4c:  93 2a 60 18  sll  %o1, 0x18, %o1
a007df50:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007df54:  94 2a 80 01  andn  %o2, %g1, %o2
a007df58:  90 12 22 40  or  %o0, 0x240, %o0
a007df5c:  7f ff d4 3a  call  0xa0073044
a007df60:  93 3a 60 18  sra  %o1, 0x18, %o1
a007df64:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007df68:  80 88 60 02  btst  2, %g1
a007df6c:  02 80 00 70  be  0xa007e12c
a007df70:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a007df74:  92 04 e0 41  add  %l3, 0x41, %o1
a007df78:  d4 07 bf e0  ld  [ %fp + -32 ], %o2
a007df7c:  93 2a 60 18  sll  %o1, 0x18, %o1
a007df80:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007df84:  94 2a 80 01  andn  %o2, %g1, %o2
a007df88:  90 12 22 60  or  %o0, 0x260, %o0
a007df8c:  7f ff d4 2e  call  0xa0073044
a007df90:  93 3a 60 18  sra  %o1, 0x18, %o1
a007df94:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007df98:  80 88 60 02  btst  2, %g1
a007df9c:  22 80 00 65  be,a   0xa007e130
a007dfa0:  c2 05 40 00  ld  [ %l5 ], %g1
a007dfa4:  a4 0c e0 ff  and  %l3, 0xff, %l2
a007dfa8:  23 00 00 04  sethi  %hi(0x1000), %l1
a007dfac:  92 14 61 78  or  %l1, 0x178, %o1	! 0x1178
a007dfb0:  40 00 a4 d9  call  0xa00a7314
a007dfb4:  90 10 00 12  mov  %l2, %o0
a007dfb8:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a007dfbc:  82 10 63 00  or  %g1, 0x300, %g1	! 0xffff00
a007dfc0:  a0 0a 00 01  and  %o0, %g1, %l0
a007dfc4:  92 14 61 78  or  %l1, 0x178, %o1
a007dfc8:  40 00 a4 d3  call  0xa00a7314
a007dfcc:  90 10 00 12  mov  %l2, %o0
a007dfd0:  96 0a 20 0f  and  %o0, 0xf, %o3
a007dfd4:  92 04 e0 41  add  %l3, 0x41, %o1
a007dfd8:  a1 34 20 08  srl  %l0, 8, %l0
a007dfdc:  93 2a 60 18  sll  %o1, 0x18, %o1
a007dfe0:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007dfe4:  90 12 22 88  or  %o0, 0x288, %o0	! 0xa0067e88
a007dfe8:  93 3a 60 18  sra  %o1, 0x18, %o1
a007dfec:  7f ff d4 16  call  0xa0073044
a007dff0:  94 10 00 10  mov  %l0, %o2
a007dff4:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007dff8:  80 88 60 02  btst  2, %g1
a007dffc:  22 80 00 4d  be,a   0xa007e130
a007e000:  c2 05 40 00  ld  [ %l5 ], %g1
a007e004:  a2 04 64 00  add  %l1, 0x400, %l1
a007e008:  92 14 61 78  or  %l1, 0x178, %o1
a007e00c:  40 00 a4 c2  call  0xa00a7314
a007e010:  90 10 00 12  mov  %l2, %o0
a007e014:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a007e018:  82 10 63 00  or  %g1, 0x300, %g1	! 0xffff00
a007e01c:  a0 0a 00 01  and  %o0, %g1, %l0
a007e020:  92 14 61 78  or  %l1, 0x178, %o1
a007e024:  40 00 a4 bc  call  0xa00a7314
a007e028:  90 10 00 12  mov  %l2, %o0
a007e02c:  96 0a 20 0f  and  %o0, 0xf, %o3
a007e030:  92 04 e0 41  add  %l3, 0x41, %o1
a007e034:  a1 34 20 08  srl  %l0, 8, %l0
a007e038:  93 2a 60 18  sll  %o1, 0x18, %o1
a007e03c:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007e040:  90 12 22 b8  or  %o0, 0x2b8, %o0	! 0xa0067eb8
a007e044:  93 3a 60 18  sra  %o1, 0x18, %o1
a007e048:  7f ff d3 ff  call  0xa0073044
a007e04c:  94 10 00 10  mov  %l0, %o2
a007e050:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007e054:  80 88 60 02  btst  2, %g1
a007e058:  22 80 00 36  be,a   0xa007e130
a007e05c:  c2 05 40 00  ld  [ %l5 ], %g1
a007e060:  a2 04 64 00  add  %l1, 0x400, %l1
a007e064:  92 14 61 78  or  %l1, 0x178, %o1
a007e068:  40 00 a4 ab  call  0xa00a7314
a007e06c:  90 10 00 12  mov  %l2, %o0
a007e070:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a007e074:  82 10 63 00  or  %g1, 0x300, %g1	! 0xffff00
a007e078:  a0 0a 00 01  and  %o0, %g1, %l0
a007e07c:  92 14 61 78  or  %l1, 0x178, %o1
a007e080:  40 00 a4 a5  call  0xa00a7314
a007e084:  90 10 00 12  mov  %l2, %o0
a007e088:  96 0a 20 0f  and  %o0, 0xf, %o3
a007e08c:  92 04 e0 41  add  %l3, 0x41, %o1
a007e090:  a1 34 20 08  srl  %l0, 8, %l0
a007e094:  93 2a 60 18  sll  %o1, 0x18, %o1
a007e098:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007e09c:  90 12 22 e8  or  %o0, 0x2e8, %o0	! 0xa0067ee8
a007e0a0:  93 3a 60 18  sra  %o1, 0x18, %o1
a007e0a4:  7f ff d3 e8  call  0xa0073044
a007e0a8:  94 10 00 10  mov  %l0, %o2
a007e0ac:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007e0b0:  80 88 60 02  btst  2, %g1
a007e0b4:  22 80 00 1f  be,a   0xa007e130
a007e0b8:  c2 05 40 00  ld  [ %l5 ], %g1
a007e0bc:  13 00 00 04  sethi  %hi(0x1000), %o1
a007e0c0:  92 12 60 3c  or  %o1, 0x3c, %o1	! 0x103c
a007e0c4:  40 00 a4 94  call  0xa00a7314
a007e0c8:  90 10 00 12  mov  %l2, %o0
a007e0cc:  95 32 20 10  srl  %o0, 0x10, %o2
a007e0d0:  92 04 e0 41  add  %l3, 0x41, %o1
a007e0d4:  93 2a 60 18  sll  %o1, 0x18, %o1
a007e0d8:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007e0dc:  90 12 23 20  or  %o0, 0x320, %o0	! 0xa0067f20
a007e0e0:  93 3a 60 18  sra  %o1, 0x18, %o1
a007e0e4:  7f ff d3 d8  call  0xa0073044
a007e0e8:  94 0a a0 ff  and  %o2, 0xff, %o2
a007e0ec:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007e0f0:  80 88 60 02  btst  2, %g1
a007e0f4:  22 80 00 0f  be,a   0xa007e130
a007e0f8:  c2 05 40 00  ld  [ %l5 ], %g1
a007e0fc:  13 00 00 05  sethi  %hi(0x1400), %o1
a007e100:  92 12 60 3c  or  %o1, 0x3c, %o1	! 0x143c
a007e104:  40 00 a4 84  call  0xa00a7314
a007e108:  90 10 00 12  mov  %l2, %o0
a007e10c:  95 32 20 10  srl  %o0, 0x10, %o2
a007e110:  92 04 e0 41  add  %l3, 0x41, %o1
a007e114:  93 2a 60 18  sll  %o1, 0x18, %o1
a007e118:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007e11c:  90 12 23 48  or  %o0, 0x348, %o0	! 0xa0067f48
a007e120:  93 3a 60 18  sra  %o1, 0x18, %o1
a007e124:  7f ff d3 c8  call  0xa0073044
a007e128:  94 0a a0 ff  and  %o2, 0xff, %o2
a007e12c:  c2 05 40 00  ld  [ %l5 ], %g1
a007e130:  80 88 60 02  btst  2, %g1
a007e134:  02 80 00 4b  be  0xa007e260
a007e138:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a007e13c:  13 00 00 06  sethi  %hi(0x1800), %o1
a007e140:  92 12 60 3c  or  %o1, 0x3c, %o1	! 0x183c
a007e144:  40 00 a4 74  call  0xa00a7314
a007e148:  90 0c e0 ff  and  %l3, 0xff, %o0
a007e14c:  95 32 20 10  srl  %o0, 0x10, %o2
a007e150:  92 04 e0 41  add  %l3, 0x41, %o1
a007e154:  93 2a 60 18  sll  %o1, 0x18, %o1
a007e158:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007e15c:  90 12 23 70  or  %o0, 0x370, %o0	! 0xa0067f70
a007e160:  93 3a 60 18  sra  %o1, 0x18, %o1
a007e164:  7f ff d3 b8  call  0xa0073044
a007e168:  94 0a a0 ff  and  %o2, 0xff, %o2
a007e16c:  c2 05 40 00  ld  [ %l5 ], %g1
a007e170:  80 88 60 02  btst  2, %g1
a007e174:  02 80 00 3a  be  0xa007e25c
a007e178:  82 0c e0 ff  and  %l3, 0xff, %g1
a007e17c:  9a 15 e1 f0  or  %l7, 0x1f0, %o5
a007e180:  82 58 68 98  smul  %g1, 0x898, %g1
a007e184:  82 00 40 0d  add  %g1, %o5, %g1
a007e188:  d4 08 60 09  ldub  [ %g1 + 9 ], %o2
a007e18c:  92 04 e0 41  add  %l3, 0x41, %o1
a007e190:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007e194:  82 10 62 c8  or  %g1, 0x2c8, %g1	! 0xa00b3ac8
a007e198:  93 2a 60 18  sll  %o1, 0x18, %o1
a007e19c:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007e1a0:  d6 08 40 0a  ldub  [ %g1 + %o2 ], %o3
a007e1a4:  90 12 23 98  or  %o0, 0x398, %o0
a007e1a8:  7f ff d3 a7  call  0xa0073044
a007e1ac:  93 3a 60 18  sra  %o1, 0x18, %o1
a007e1b0:  c2 05 40 00  ld  [ %l5 ], %g1
a007e1b4:  80 88 60 02  btst  2, %g1
a007e1b8:  02 80 00 29  be  0xa007e25c
a007e1bc:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a007e1c0:  9a 0c e0 ff  and  %l3, 0xff, %o5
a007e1c4:  82 10 61 f0  or  %g1, 0x1f0, %g1
a007e1c8:  9a 5b 68 98  smul  %o5, 0x898, %o5
a007e1cc:  9a 03 40 01  add  %o5, %g1, %o5
a007e1d0:  92 04 e0 41  add  %l3, 0x41, %o1
a007e1d4:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007e1d8:  82 10 62 c8  or  %g1, 0x2c8, %g1	! 0xa00b3ac8
a007e1dc:  d4 0b 60 0a  ldub  [ %o5 + 0xa ], %o2
a007e1e0:  93 2a 60 18  sll  %o1, 0x18, %o1
a007e1e4:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007e1e8:  d6 08 40 0a  ldub  [ %g1 + %o2 ], %o3
a007e1ec:  90 12 23 d0  or  %o0, 0x3d0, %o0
a007e1f0:  7f ff d3 95  call  0xa0073044
a007e1f4:  93 3a 60 18  sra  %o1, 0x18, %o1
a007e1f8:  c2 05 40 00  ld  [ %l5 ], %g1
a007e1fc:  80 88 60 02  btst  2, %g1
a007e200:  02 80 00 17  be  0xa007e25c
a007e204:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a007e208:  9a 0c e0 ff  and  %l3, 0xff, %o5
a007e20c:  82 10 61 f0  or  %g1, 0x1f0, %g1
a007e210:  9a 5b 68 98  smul  %o5, 0x898, %o5
a007e214:  9a 03 40 01  add  %o5, %g1, %o5
a007e218:  92 04 e0 41  add  %l3, 0x41, %o1
a007e21c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007e220:  82 10 62 c8  or  %g1, 0x2c8, %g1	! 0xa00b3ac8
a007e224:  d4 0b 60 0b  ldub  [ %o5 + 0xb ], %o2
a007e228:  93 2a 60 18  sll  %o1, 0x18, %o1
a007e22c:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007e230:  d6 08 40 0a  ldub  [ %g1 + %o2 ], %o3
a007e234:  90 12 20 08  or  %o0, 8, %o0
a007e238:  7f ff d3 83  call  0xa0073044
a007e23c:  93 3a 60 18  sra  %o1, 0x18, %o1
a007e240:  c2 05 40 00  ld  [ %l5 ], %g1
a007e244:  80 88 60 02  btst  2, %g1
a007e248:  02 80 00 06  be  0xa007e260
a007e24c:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a007e250:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007e254:  7f ff d3 7c  call  0xa0073044
a007e258:  90 12 20 40  or  %o0, 0x40, %o0	! 0xa0068040
a007e25c:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a007e260:  c2 08 61 9f  ldub  [ %g1 + 0x19f ], %g1	! 0xa807619f
a007e264:  80 a0 60 01  cmp  %g1, 1
a007e268:  32 80 01 43  bne,a   0xa007e774
a007e26c:  c2 05 40 00  ld  [ %l5 ], %g1
a007e270:  96 0c e0 ff  and  %l3, 0xff, %o3
a007e274:  82 02 c0 0b  add  %o3, %o3, %g1
a007e278:  82 00 40 0b  add  %g1, %o3, %g1
a007e27c:  13 2a 01 f3  sethi  %hi(0xa807cc00), %o1
a007e280:  9a 12 60 c4  or  %o1, 0xc4, %o5	! 0xa807ccc4
a007e284:  83 28 60 02  sll  %g1, 2, %g1
a007e288:  82 00 40 0d  add  %g1, %o5, %g1
a007e28c:  15 2a 01 ea  sethi  %hi(0xa807a800), %o2
a007e290:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a007e294:  98 12 a1 f0  or  %o2, 0x1f0, %o4
a007e298:  9a 5a e8 98  smul  %o3, 0x898, %o5
a007e29c:  9a 03 40 0c  add  %o5, %o4, %o5
a007e2a0:  80 a0 60 00  cmp  %g1, 0
a007e2a4:  02 80 00 07  be  0xa007e2c0
a007e2a8:  c2 0b 60 09  ldub  [ %o5 + 9 ], %g1
a007e2ac:  80 a0 60 02  cmp  %g1, 2
a007e2b0:  28 80 00 08  bleu,a   0xa007e2d0
a007e2b4:  82 12 a1 f0  or  %o2, 0x1f0, %g1
a007e2b8:  10 80 00 0d  b  0xa007e2ec
a007e2bc:  82 02 c0 0b  add  %o3, %o3, %g1
a007e2c0:  80 a0 60 00  cmp  %g1, 0
a007e2c4:  32 80 00 09  bne,a   0xa007e2e8
a007e2c8:  96 0c e0 ff  and  %l3, 0xff, %o3
a007e2cc:  82 12 a1 f0  or  %o2, 0x1f0, %g1
a007e2d0:  9a 5a e8 98  smul  %o3, 0x898, %o5
a007e2d4:  9a 03 40 01  add  %o5, %g1, %o5
a007e2d8:  c2 0b 60 31  ldub  [ %o5 + 0x31 ], %g1
a007e2dc:  80 a0 60 00  cmp  %g1, 0
a007e2e0:  02 80 00 3b  be  0xa007e3cc
a007e2e4:  96 0c e0 ff  and  %l3, 0xff, %o3
a007e2e8:  82 02 c0 0b  add  %o3, %o3, %g1
a007e2ec:  82 00 40 0b  add  %g1, %o3, %g1
a007e2f0:  9a 12 60 c4  or  %o1, 0xc4, %o5
a007e2f4:  83 28 60 02  sll  %g1, 2, %g1
a007e2f8:  82 00 40 0d  add  %g1, %o5, %g1
a007e2fc:  15 2a 01 ea  sethi  %hi(0xa807a800), %o2
a007e300:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a007e304:  98 12 a1 f0  or  %o2, 0x1f0, %o4
a007e308:  9a 5a e8 98  smul  %o3, 0x898, %o5
a007e30c:  9a 03 40 0c  add  %o5, %o4, %o5
a007e310:  80 a0 60 00  cmp  %g1, 0
a007e314:  02 80 00 07  be  0xa007e330
a007e318:  c2 0b 60 0a  ldub  [ %o5 + 0xa ], %g1
a007e31c:  80 a0 60 02  cmp  %g1, 2
a007e320:  28 80 00 08  bleu,a   0xa007e340
a007e324:  82 12 a1 f0  or  %o2, 0x1f0, %g1
a007e328:  10 80 00 0c  b  0xa007e358
a007e32c:  96 0c e0 ff  and  %l3, 0xff, %o3
a007e330:  80 a0 60 00  cmp  %g1, 0
a007e334:  32 80 00 09  bne,a   0xa007e358
a007e338:  96 0c e0 ff  and  %l3, 0xff, %o3
a007e33c:  82 12 a1 f0  or  %o2, 0x1f0, %g1
a007e340:  9a 5a e8 98  smul  %o3, 0x898, %o5
a007e344:  9a 03 40 01  add  %o5, %g1, %o5
a007e348:  c2 0b 60 32  ldub  [ %o5 + 0x32 ], %g1
a007e34c:  80 a0 60 00  cmp  %g1, 0
a007e350:  02 80 00 1f  be  0xa007e3cc
a007e354:  96 0c e0 ff  and  %l3, 0xff, %o3
a007e358:  82 02 c0 0b  add  %o3, %o3, %g1
a007e35c:  82 00 40 0b  add  %g1, %o3, %g1
a007e360:  9a 12 60 c4  or  %o1, 0xc4, %o5
a007e364:  83 28 60 02  sll  %g1, 2, %g1
a007e368:  82 00 40 0d  add  %g1, %o5, %g1
a007e36c:  15 2a 01 ea  sethi  %hi(0xa807a800), %o2
a007e370:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a007e374:  98 12 a1 f0  or  %o2, 0x1f0, %o4
a007e378:  9a 5a e8 98  smul  %o3, 0x898, %o5
a007e37c:  9a 03 40 0c  add  %o5, %o4, %o5
a007e380:  80 a0 60 00  cmp  %g1, 0
a007e384:  02 80 00 07  be  0xa007e3a0
a007e388:  c2 0b 60 0b  ldub  [ %o5 + 0xb ], %g1
a007e38c:  80 a0 60 02  cmp  %g1, 2
a007e390:  08 80 00 08  bleu  0xa007e3b0
a007e394:  82 12 a1 f0  or  %o2, 0x1f0, %g1
a007e398:  10 80 00 3d  b  0xa007e48c
a007e39c:  2f 2a 01 f3  sethi  %hi(0xa807cc00), %l7
a007e3a0:  80 a0 60 00  cmp  %g1, 0
a007e3a4:  12 80 00 3a  bne  0xa007e48c
a007e3a8:  2f 2a 01 f3  sethi  %hi(0xa807cc00), %l7
a007e3ac:  82 12 a1 f0  or  %o2, 0x1f0, %g1
a007e3b0:  9a 5a e8 98  smul  %o3, 0x898, %o5
a007e3b4:  9a 03 40 01  add  %o5, %g1, %o5
a007e3b8:  c2 0b 60 33  ldub  [ %o5 + 0x33 ], %g1
a007e3bc:  80 a0 60 00  cmp  %g1, 0
a007e3c0:  12 80 00 33  bne  0xa007e48c
a007e3c4:  2f 2a 01 f3  sethi  %hi(0xa807cc00), %l7
a007e3c8:  96 0c e0 ff  and  %l3, 0xff, %o3
a007e3cc:  82 02 c0 0b  add  %o3, %o3, %g1
a007e3d0:  82 00 40 0b  add  %g1, %o3, %g1
a007e3d4:  19 2a 01 f3  sethi  %hi(0xa807cc00), %o4
a007e3d8:  83 28 60 02  sll  %g1, 2, %g1
a007e3dc:  9a 13 20 c4  or  %o4, 0xc4, %o5
a007e3e0:  82 00 40 0d  add  %g1, %o5, %g1
a007e3e4:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a007e3e8:  80 a0 60 01  cmp  %g1, 1
a007e3ec:  12 80 00 28  bne  0xa007e48c
a007e3f0:  2f 2a 01 f3  sethi  %hi(0xa807cc00), %l7
a007e3f4:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a007e3f8:  9a 5a e8 98  smul  %o3, 0x898, %o5
a007e3fc:  82 10 61 f0  or  %g1, 0x1f0, %g1
a007e400:  9a 03 40 01  add  %o5, %g1, %o5
a007e404:  aa 10 20 00  clr  %l5
a007e408:  94 10 20 01  mov  1, %o2
a007e40c:  82 0d 60 ff  and  %l5, 0xff, %g1
a007e410:  96 03 40 01  add  %o5, %g1, %o3
a007e414:  80 a2 a0 00  cmp  %o2, 0
a007e418:  02 80 00 07  be  0xa007e434
a007e41c:  c2 0a e0 09  ldub  [ %o3 + 9 ], %g1
a007e420:  80 a0 60 02  cmp  %g1, 2
a007e424:  28 80 00 08  bleu,a   0xa007e444
a007e428:  c2 0a e0 31  ldub  [ %o3 + 0x31 ], %g1
a007e42c:  10 80 00 0c  b  0xa007e45c
a007e430:  aa 05 60 01  inc  %l5
a007e434:  80 a0 60 00  cmp  %g1, 0
a007e438:  32 80 00 09  bne,a   0xa007e45c
a007e43c:  aa 05 60 01  inc  %l5
a007e440:  c2 0a e0 31  ldub  [ %o3 + 0x31 ], %g1
a007e444:  80 a0 60 00  cmp  %g1, 0
a007e448:  12 80 00 05  bne  0xa007e45c
a007e44c:  aa 05 60 01  inc  %l5
a007e450:  c2 0a e0 09  ldub  [ %o3 + 9 ], %g1
a007e454:  82 00 60 01  inc  %g1
a007e458:  c2 2a e0 09  stb  %g1, [ %o3 + 9 ]
a007e45c:  82 0d 60 ff  and  %l5, 0xff, %g1
a007e460:  80 a0 60 02  cmp  %g1, 2
a007e464:  08 bf ff ec  bleu  0xa007e414
a007e468:  96 03 40 01  add  %o5, %g1, %o3
a007e46c:  9a 0c e0 ff  and  %l3, 0xff, %o5
a007e470:  82 03 40 0d  add  %o5, %o5, %g1
a007e474:  82 00 40 0d  add  %g1, %o5, %g1
a007e478:  98 13 20 c4  or  %o4, 0xc4, %o4
a007e47c:  83 28 60 02  sll  %g1, 2, %g1
a007e480:  9a 10 20 0d  mov  0xd, %o5
a007e484:  10 80 00 cc  b  0xa007e7b4
a007e488:  da 23 00 01  st  %o5, [ %o4 + %g1 ]
a007e48c:  d4 0d e0 58  ldub  [ %l7 + 0x58 ], %o2
a007e490:  80 a2 a0 00  cmp  %o2, 0
a007e494:  12 80 00 6d  bne  0xa007e648
a007e498:  03 00 00 1f  sethi  %hi(0x7c00), %g1
a007e49c:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007e4a0:  80 88 60 02  btst  2, %g1
a007e4a4:  02 80 00 09  be  0xa007e4c8
a007e4a8:  a4 0c e0 ff  and  %l3, 0xff, %l2
a007e4ac:  92 04 e0 41  add  %l3, 0x41, %o1
a007e4b0:  93 2a 60 18  sll  %o1, 0x18, %o1
a007e4b4:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007e4b8:  90 12 20 90  or  %o0, 0x90, %o0	! 0xa0068090
a007e4bc:  7f ff d2 e2  call  0xa0073044
a007e4c0:  93 3a 60 18  sra  %o1, 0x18, %o1
a007e4c4:  a4 0c e0 ff  and  %l3, 0xff, %l2
a007e4c8:  17 00 00 04  sethi  %hi(0x1000), %o3
a007e4cc:  96 12 e1 00  or  %o3, 0x100, %o3	! 0x1100
a007e4d0:  90 10 20 01  mov  1, %o0
a007e4d4:  92 10 20 15  mov  0x15, %o1
a007e4d8:  40 00 a3 d3  call  0xa00a7424
a007e4dc:  94 10 00 12  mov  %l2, %o2
a007e4e0:  17 00 00 05  sethi  %hi(0x1400), %o3
a007e4e4:  96 12 e1 00  or  %o3, 0x100, %o3	! 0x1500
a007e4e8:  90 10 20 01  mov  1, %o0
a007e4ec:  92 10 20 15  mov  0x15, %o1
a007e4f0:  40 00 a3 cd  call  0xa00a7424
a007e4f4:  94 10 00 12  mov  %l2, %o2
a007e4f8:  17 00 00 06  sethi  %hi(0x1800), %o3
a007e4fc:  96 12 e1 00  or  %o3, 0x100, %o3	! 0x1900
a007e500:  90 10 20 01  mov  1, %o0
a007e504:  92 10 20 15  mov  0x15, %o1
a007e508:  40 00 a3 c7  call  0xa00a7424
a007e50c:  94 10 00 12  mov  %l2, %o2
a007e510:  aa 10 20 00  clr  %l5
a007e514:  a2 0d 60 ff  and  %l5, 0xff, %l1
a007e518:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a007e51c:  15 3f c0 00  sethi  %hi(0xff000000), %o2
a007e520:  b0 10 60 f8  or  %g1, 0xf8, %i0
a007e524:  ac 15 e0 58  or  %l7, 0x58, %l6
a007e528:  aa 05 60 01  inc  %l5
a007e52c:  92 04 40 11  add  %l1, %l1, %o1
a007e530:  80 a4 60 02  cmp  %l1, 2
a007e534:  94 12 a0 f0  or  %o2, 0xf0, %o2
a007e538:  18 80 00 1a  bgu  0xa007e5a0
a007e53c:  90 10 00 12  mov  %l2, %o0
a007e540:  e0 0e 00 11  ldub  [ %i0 + %l1 ], %l0
a007e544:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007e548:  9b 2c 20 02  sll  %l0, 2, %o5
a007e54c:  82 10 62 cc  or  %g1, 0x2cc, %g1
a007e550:  d6 00 40 0d  ld  [ %g1 + %o5 ], %o3
a007e554:  de 0d 80 11  ldub  [ %l6 + %l1 ], %o7
a007e558:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007e55c:  99 2b e0 02  sll  %o7, 2, %o4
a007e560:  82 10 62 d4  or  %g1, 0x2d4, %g1
a007e564:  da 00 40 0c  ld  [ %g1 + %o4 ], %o5
a007e568:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a007e56c:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a007e570:  96 0a c0 01  and  %o3, %g1, %o3
a007e574:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007e578:  82 10 63 78  or  %g1, 0x378, %g1	! 0xa00b3b78
a007e57c:  9a 0b 60 0f  and  %o5, 0xf, %o5
a007e580:  97 2a e0 08  sll  %o3, 8, %o3
a007e584:  9e 03 e0 01  inc  %o7
a007e588:  a0 04 20 01  inc  %l0
a007e58c:  d2 10 40 09  lduh  [ %g1 + %o1 ], %o1
a007e590:  e0 2e 00 11  stb  %l0, [ %i0 + %l1 ]
a007e594:  de 2d 80 11  stb  %o7, [ %l6 + %l1 ]
a007e598:  40 00 a3 bc  call  0xa00a7488
a007e59c:  96 13 40 0b  or  %o5, %o3, %o3
a007e5a0:  82 0d 60 ff  and  %l5, 0xff, %g1
a007e5a4:  80 a0 60 02  cmp  %g1, 2
a007e5a8:  08 bf ff dc  bleu  0xa007e518
a007e5ac:  a2 0d 60 ff  and  %l5, 0xff, %l1
a007e5b0:  a0 0c e0 ff  and  %l3, 0xff, %l0
a007e5b4:  17 00 00 04  sethi  %hi(0x1000), %o3
a007e5b8:  96 12 e1 00  or  %o3, 0x100, %o3	! 0x1100
a007e5bc:  90 10 20 00  clr  %o0
a007e5c0:  92 10 20 15  mov  0x15, %o1
a007e5c4:  40 00 a3 98  call  0xa00a7424
a007e5c8:  94 10 00 10  mov  %l0, %o2
a007e5cc:  17 00 00 05  sethi  %hi(0x1400), %o3
a007e5d0:  96 12 e1 00  or  %o3, 0x100, %o3	! 0x1500
a007e5d4:  90 10 20 00  clr  %o0
a007e5d8:  92 10 20 15  mov  0x15, %o1
a007e5dc:  40 00 a3 92  call  0xa00a7424
a007e5e0:  94 10 00 10  mov  %l0, %o2
a007e5e4:  17 00 00 06  sethi  %hi(0x1800), %o3
a007e5e8:  96 12 e1 00  or  %o3, 0x100, %o3	! 0x1900
a007e5ec:  90 10 20 00  clr  %o0
a007e5f0:  92 10 20 15  mov  0x15, %o1
a007e5f4:  40 00 a3 8c  call  0xa00a7424
a007e5f8:  94 10 00 10  mov  %l0, %o2
a007e5fc:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a007e600:  82 10 61 f0  or  %g1, 0x1f0, %g1	! 0xa807a9f0
a007e604:  9a 5c 28 98  smul  %l0, 0x898, %o5
a007e608:  9a 03 40 01  add  %o5, %g1, %o5
a007e60c:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007e610:  80 88 60 02  btst  2, %g1
a007e614:  02 80 00 08  be  0xa007e634
a007e618:  c0 2b 60 30  clrb  [ %o5 + 0x30 ]
a007e61c:  92 04 e0 41  add  %l3, 0x41, %o1
a007e620:  93 2a 60 18  sll  %o1, 0x18, %o1
a007e624:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007e628:  90 12 20 d0  or  %o0, 0xd0, %o0	! 0xa00680d0
a007e62c:  7f ff d2 86  call  0xa0073044
a007e630:  93 3a 60 18  sra  %o1, 0x18, %o1
a007e634:  82 04 00 10  add  %l0, %l0, %g1
a007e638:  82 00 40 10  add  %g1, %l0, %g1
a007e63c:  83 28 60 02  sll  %g1, 2, %g1
a007e640:  10 80 00 49  b  0xa007e764
a007e644:  98 10 20 0b  mov  0xb, %o4
a007e648:  98 10 63 ff  or  %g1, 0x3ff, %o4
a007e64c:  a0 0c e0 ff  and  %l3, 0xff, %l0
a007e650:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a007e654:  82 10 61 f0  or  %g1, 0x1f0, %g1	! 0xa807a9f0
a007e658:  9a 5c 28 98  smul  %l0, 0x898, %o5
a007e65c:  d2 07 bf d8  ld  [ %fp + -40 ], %o1
a007e660:  9a 03 40 01  add  %o5, %g1, %o5
a007e664:  82 0a 40 0c  and  %o1, %o4, %g1
a007e668:  80 a0 40 0c  cmp  %g1, %o4
a007e66c:  02 80 00 14  be  0xa007e6bc
a007e670:  c0 2b 68 96  clrb  [ %o5 + 0x896 ]
a007e674:  d6 07 bf dc  ld  [ %fp + -36 ], %o3
a007e678:  82 0a c0 0c  and  %o3, %o4, %g1
a007e67c:  80 a0 40 0c  cmp  %g1, %o4
a007e680:  02 80 00 0f  be  0xa007e6bc
a007e684:  da 07 bf e0  ld  [ %fp + -32 ], %o5
a007e688:  82 0b 40 0c  and  %o5, %o4, %g1
a007e68c:  80 a0 40 0c  cmp  %g1, %o4
a007e690:  02 80 00 0b  be  0xa007e6bc
a007e694:  03 00 00 20  sethi  %hi(0x8000), %g1
a007e698:  80 8a 40 01  btst  %o1, %g1
a007e69c:  22 80 00 09  be,a   0xa007e6c0
a007e6a0:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007e6a4:  80 8a c0 01  btst  %o3, %g1
a007e6a8:  22 80 00 06  be,a   0xa007e6c0
a007e6ac:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007e6b0:  80 8b 40 01  btst  %o5, %g1
a007e6b4:  12 80 00 14  bne  0xa007e704
a007e6b8:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007e6bc:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a007e6c0:  80 88 60 02  btst  2, %g1
a007e6c4:  02 80 00 09  be  0xa007e6e8
a007e6c8:  9a 04 00 10  add  %l0, %l0, %o5
a007e6cc:  92 04 e0 41  add  %l3, 0x41, %o1
a007e6d0:  93 2a 60 18  sll  %o1, 0x18, %o1
a007e6d4:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007e6d8:  90 12 20 58  or  %o0, 0x58, %o0	! 0xa0067c58
a007e6dc:  7f ff d2 5a  call  0xa0073044
a007e6e0:  93 3a 60 18  sra  %o1, 0x18, %o1
a007e6e4:  9a 04 00 10  add  %l0, %l0, %o5
a007e6e8:  9a 03 40 10  add  %o5, %l0, %o5
a007e6ec:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a007e6f0:  9b 2b 60 02  sll  %o5, 2, %o5
a007e6f4:  82 10 60 c4  or  %g1, 0xc4, %g1
a007e6f8:  c0 20 40 0d  clr  [ %g1 + %o5 ]
a007e6fc:  10 80 00 2f  b  0xa007e7b8
a007e700:  b0 10 20 00  clr  %i0
a007e704:  80 88 60 02  btst  2, %g1
a007e708:  02 80 00 09  be  0xa007e72c
a007e70c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007e710:  92 04 e0 41  add  %l3, 0x41, %o1
a007e714:  93 2a 60 18  sll  %o1, 0x18, %o1
a007e718:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007e71c:  90 12 21 08  or  %o0, 0x108, %o0	! 0xa0068108
a007e720:  7f ff d2 49  call  0xa0073044
a007e724:  93 3a 60 18  sra  %o1, 0x18, %o1
a007e728:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007e72c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007e730:  80 88 60 02  btst  2, %g1
a007e734:  02 80 00 09  be  0xa007e758
a007e738:  82 04 00 10  add  %l0, %l0, %g1
a007e73c:  92 04 e0 41  add  %l3, 0x41, %o1
a007e740:  93 2a 60 18  sll  %o1, 0x18, %o1
a007e744:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007e748:  90 12 21 50  or  %o0, 0x150, %o0	! 0xa0068150
a007e74c:  7f ff d2 3e  call  0xa0073044
a007e750:  93 3a 60 18  sra  %o1, 0x18, %o1
a007e754:  82 04 00 10  add  %l0, %l0, %g1
a007e758:  82 00 40 10  add  %g1, %l0, %g1
a007e75c:  83 28 60 02  sll  %g1, 2, %g1
a007e760:  98 10 20 10  mov  0x10, %o4
a007e764:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a007e768:  9a 13 60 c4  or  %o5, 0xc4, %o5	! 0xa807ccc4
a007e76c:  10 80 00 12  b  0xa007e7b4
a007e770:  d8 23 40 01  st  %o4, [ %o5 + %g1 ]
a007e774:  80 88 60 02  btst  2, %g1
a007e778:  02 80 00 09  be  0xa007e79c
a007e77c:  82 0c e0 ff  and  %l3, 0xff, %g1
a007e780:  92 04 e0 41  add  %l3, 0x41, %o1
a007e784:  93 2a 60 18  sll  %o1, 0x18, %o1
a007e788:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007e78c:  90 12 21 98  or  %o0, 0x198, %o0	! 0xa0068198
a007e790:  7f ff d2 2d  call  0xa0073044
a007e794:  93 3a 60 18  sra  %o1, 0x18, %o1
a007e798:  82 0c e0 ff  and  %l3, 0xff, %g1
a007e79c:  9a 00 40 01  add  %g1, %g1, %o5
a007e7a0:  9a 03 40 01  add  %o5, %g1, %o5
a007e7a4:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a007e7a8:  9b 2b 60 02  sll  %o5, 2, %o5
a007e7ac:  82 10 60 c4  or  %g1, 0xc4, %g1
a007e7b0:  c0 20 40 0d  clr  [ %g1 + %o5 ]
a007e7b4:  b0 10 20 01  mov  1, %i0
a007e7b8:  81 c7 e0 08  ret
a007e7bc:  81 e8 00 00  restore
