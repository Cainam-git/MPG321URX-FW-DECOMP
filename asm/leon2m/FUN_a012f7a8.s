# leon2m FUN_a012f7a8 0xa012f7a8-0xa012fc04 (1116 bytes)
a012f7a8:  9d e3 bf 98  save  %sp, -104, %sp
a012f7ac:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a012f7b0:  33 00 06 94  sethi  %hi(0x1a5000), %i1
a012f7b4:  b4 12 22 24  or  %o0, 0x224, %i2
a012f7b8:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a012f7bc:  b2 16 62 38  or  %i1, 0x238, %i1
a012f7c0:  ba 10 63 30  or  %g1, 0x330, %i5
a012f7c4:  aa 10 20 00  clr  %l5
a012f7c8:  a4 10 20 00  clr  %l2
a012f7cc:  10 80 00 08  b  0xa012f7ec
a012f7d0:  b0 10 00 1a  mov  %i2, %i0
a012f7d4:  80 a0 60 00  cmp  %g1, 0
a012f7d8:  02 80 00 20  be  0xa012f858
a012f7dc:  01 00 00 00  nop
a012f7e0:  a0 00 7f ff  add  %g1, -1, %l0
a012f7e4:  10 80 01 01  b  0xa012fbe8
a012f7e8:  e0 2c 60 0e  stb  %l0, [ %l1 + 0xe ]
a012f7ec:  97 2c a0 04  sll  %l2, 4, %o3
a012f7f0:  94 22 c0 12  sub  %o3, %l2, %o2
a012f7f4:  a1 2a a0 03  sll  %o2, 3, %l0
a012f7f8:  a8 04 00 1d  add  %l0, %i5, %l4
a012f7fc:  d2 0d 20 70  ldub  [ %l4 + 0x70 ], %o1
a012f800:  80 8a 60 01  btst  1, %o1
a012f804:  22 80 00 fa  be,a   0xa012fbec
a012f808:  aa 05 60 01  inc  %l5
a012f80c:  f8 04 00 1d  ld  [ %l0 + %i5 ], %i4
a012f810:  a7 37 20 0c  srl  %i4, 0xc, %l3
a012f814:  a2 0c e0 0f  and  %l3, 0xf, %l1
a012f818:  b6 5c 60 2a  smul  %l1, 0x2a, %i3
a012f81c:  a2 06 c0 1a  add  %i3, %i2, %l1
a012f820:  ec 0c 60 02  ldub  [ %l1 + 2 ], %l6
a012f824:  ae 1d a0 02  xor  %l6, 2, %l7
a012f828:  80 a0 00 17  cmp  %g0, %l7
a012f82c:  98 60 3f ff  subx  %g0, -1, %o4
a012f830:  9e 1d a0 05  xor  %l6, 5, %o7
a012f834:  80 a0 00 0f  cmp  %g0, %o7
a012f838:  9a 60 3f ff  subx  %g0, -1, %o5
a012f83c:  80 93 00 0d  orcc  %o4, %o5, %g0
a012f840:  32 bf ff e5  bne,a   0xa012f7d4
a012f844:  c2 0c 60 0e  ldub  [ %l1 + 0xe ], %g1
a012f848:  67 fd 77 50  call  0x4008d588
a012f84c:  aa 05 60 01  inc  %l5
a012f850:  10 80 00 e7  b  0xa012fbec
a012f854:  d0 34 60 12  sth  %o0, [ %l1 + 0x12 ]
a012f858:  67 fd 77 4f  call  0x4008d594
a012f85c:  d0 14 60 12  lduh  [ %l1 + 0x12 ], %o0
a012f860:  d8 04 00 1d  ld  [ %l0 + %i5 ], %o4
a012f864:  9b 33 20 0c  srl  %o4, 0xc, %o5
a012f868:  96 0b 60 0f  and  %o5, 0xf, %o3
a012f86c:  94 5a e0 2a  smul  %o3, 0x2a, %o2
a012f870:  a6 02 80 1a  add  %o2, %i2, %l3
a012f874:  93 2a 20 10  sll  %o0, 0x10, %o1
a012f878:  91 32 60 10  srl  %o1, 0x10, %o0
a012f87c:  c2 14 e0 10  lduh  [ %l3 + 0x10 ], %g1
a012f880:  80 a2 00 01  cmp  %o0, %g1
a012f884:  0a 80 00 7c  bcs  0xa012fa74
a012f888:  01 00 00 00  nop
a012f88c:  ec 05 20 70  ld  [ %l4 + 0x70 ], %l6
a012f890:  9f 35 a0 17  srl  %l6, 0x17, %o7
a012f894:  80 8b e0 01  btst  1, %o7
a012f898:  12 80 00 77  bne  0xa012fa74
a012f89c:  98 10 20 00  clr  %o4
a012f8a0:  9a 10 20 00  clr  %o5
a012f8a4:  d6 0c e0 0a  ldub  [ %l3 + 0xa ], %o3
a012f8a8:  13 00 06 94  sethi  %hi(0x1a5000), %o1
a012f8ac:  94 12 62 38  or  %o1, 0x238, %o2	! 0x1a5238
a012f8b0:  de 0a 80 0d  ldub  [ %o2 + %o5 ], %o7
a012f8b4:  80 a2 c0 0f  cmp  %o3, %o7
a012f8b8:  02 80 00 bd  be  0xa012fbac
a012f8bc:  98 03 20 01  inc  %o4
a012f8c0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a012f8c4:  80 a3 60 03  cmp  %o5, 3
a012f8c8:  28 bf ff fb  bleu,a   0xa012f8b4
a012f8cc:  de 0a 80 0d  ldub  [ %o2 + %o5 ], %o7
a012f8d0:  82 10 20 ff  mov  0xff, %g1
a012f8d4:  ac 08 60 ff  and  %g1, 0xff, %l6
a012f8d8:  da 0e 40 16  ldub  [ %i1 + %l6 ], %o5
a012f8dc:  b8 10 00 19  mov  %i1, %i4
a012f8e0:  ae 0b 60 fc  and  %o5, 0xfc, %l7
a012f8e4:  a0 10 20 01  mov  1, %l0
a012f8e8:  82 10 20 01  mov  1, %g1
a012f8ec:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a012f8f0:  b6 12 e1 16  or  %o3, 0x116, %i3	! 0xa802e116
a012f8f4:  90 05 80 01  add  %l6, %g1, %o0
a012f8f8:  a2 0a 20 03  and  %o0, 3, %l1
a012f8fc:  d8 0f 00 11  ldub  [ %i4 + %l1 ], %o4
a012f900:  94 0b 20 fc  and  %o4, 0xfc, %o2
a012f904:  a0 04 20 01  inc  %l0
a012f908:  80 a2 80 17  cmp  %o2, %l7
a012f90c:  02 80 00 0b  be  0xa012f938
a012f910:  90 10 00 0c  mov  %o4, %o0
a012f914:  40 00 4a 15  call  0xa0142168
a012f918:  01 00 00 00  nop
a012f91c:  92 0a 20 ff  and  %o0, 0xff, %o1
a012f920:  97 2a 60 03  sll  %o1, 3, %o3
a012f924:  9e 02 c0 09  add  %o3, %o1, %o7
a012f928:  82 03 c0 0f  add  %o7, %o7, %g1
a012f92c:  80 a2 60 ff  cmp  %o1, 0xff
a012f930:  12 80 00 97  bne  0xa012fb8c
a012f934:  82 00 40 1b  add  %g1, %i3, %g1
a012f938:  82 0c 20 ff  and  %l0, 0xff, %g1
a012f93c:  80 a0 60 04  cmp  %g1, 4
a012f940:  08 bf ff ee  bleu  0xa012f8f8
a012f944:  90 05 80 01  add  %l6, %g1, %o0
a012f948:  d6 0c e0 0a  ldub  [ %l3 + 0xa ], %o3
a012f94c:  98 10 20 00  clr  %o4
a012f950:  9a 10 20 00  clr  %o5
a012f954:  2d 00 06 94  sethi  %hi(0x1a5000), %l6
a012f958:  94 15 a2 38  or  %l6, 0x238, %o2	! 0x1a5238
a012f95c:  ee 0a 80 0d  ldub  [ %o2 + %o5 ], %l7
a012f960:  80 a2 c0 17  cmp  %o3, %l7
a012f964:  02 80 00 9d  be  0xa012fbd8
a012f968:  98 03 20 01  inc  %o4
a012f96c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a012f970:  80 a3 60 03  cmp  %o5, 3
a012f974:  28 bf ff fb  bleu,a   0xa012f960
a012f978:  ee 0a 80 0d  ldub  [ %o2 + %o5 ], %l7
a012f97c:  82 10 20 ff  mov  0xff, %g1
a012f980:  27 00 06 94  sethi  %hi(0x1a5000), %l3
a012f984:  94 08 60 ff  and  %g1, 0xff, %o2
a012f988:  90 14 e2 38  or  %l3, 0x238, %o0
a012f98c:  f6 0a 00 0a  ldub  [ %o0 + %o2 ], %i3
a012f990:  92 0e e0 fc  and  %i3, 0xfc, %o1
a012f994:  96 10 20 01  mov  1, %o3
a012f998:  9a 10 20 01  mov  1, %o5
a012f99c:  a2 02 80 0d  add  %o2, %o5, %l1
a012f9a0:  98 0c 60 03  and  %l1, 3, %o4
a012f9a4:  e0 0a 00 0c  ldub  [ %o0 + %o4 ], %l0
a012f9a8:  96 02 e0 01  inc  %o3
a012f9ac:  b8 0c 20 fc  and  %l0, 0xfc, %i4
a012f9b0:  80 a7 00 09  cmp  %i4, %o1
a012f9b4:  02 80 00 8b  be  0xa012fbe0
a012f9b8:  9a 0a e0 ff  and  %o3, 0xff, %o5
a012f9bc:  80 a3 60 04  cmp  %o5, 4
a012f9c0:  08 bf ff f8  bleu  0xa012f9a0
a012f9c4:  a2 02 80 0d  add  %o2, %o5, %l1
a012f9c8:  82 10 00 0a  mov  %o2, %g1
a012f9cc:  82 08 60 ff  and  %g1, 0xff, %g1
a012f9d0:  27 00 06 94  sethi  %hi(0x1a5000), %l3
a012f9d4:  b6 08 60 ff  and  %g1, 0xff, %i3
a012f9d8:  b8 14 e2 38  or  %l3, 0x238, %i4
a012f9dc:  e6 0f 00 1b  ldub  [ %i4 + %i3 ], %l3
a012f9e0:  94 10 20 00  clr  %o2
a012f9e4:  92 10 00 13  mov  %l3, %o1
a012f9e8:  7f ff fe 95  call  0xa012f43c
a012f9ec:  90 10 00 12  mov  %l2, %o0
a012f9f0:  ee 05 00 00  ld  [ %l4 ], %l7
a012f9f4:  9b 35 e0 0c  srl  %l7, 0xc, %o5
a012f9f8:  96 0b 60 0f  and  %o5, 0xf, %o3
a012f9fc:  90 5a e0 2a  smul  %o3, 0x2a, %o0
a012fa00:  67 fd 76 e2  call  0x4008d588
a012fa04:  ac 02 00 18  add  %o0, %i0, %l6
a012fa08:  de 05 00 00  ld  [ %l4 ], %o7
a012fa0c:  83 33 e0 0c  srl  %o7, 0xc, %g1
a012fa10:  92 08 60 0f  and  %g1, 0xf, %o1
a012fa14:  98 5a 60 2a  smul  %o1, 0x2a, %o4
a012fa18:  a8 03 00 18  add  %o4, %i0, %l4
a012fa1c:  67 fd 76 db  call  0x4008d588
a012fa20:  d0 35 a0 12  sth  %o0, [ %l6 + 0x12 ]
a012fa24:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a012fa28:  c2 02 a0 38  ld  [ %o2 + 0x38 ], %g1	! 0xa802cc38
a012fa2c:  80 a0 60 00  cmp  %g1, 0
a012fa30:  12 80 00 61  bne  0xa012fbb4
a012fa34:  d0 35 20 14  sth  %o0, [ %l4 + 0x14 ]
a012fa38:  80 a4 a0 00  cmp  %l2, 0
a012fa3c:  32 80 00 6c  bne,a   0xa012fbec
a012fa40:  aa 05 60 01  inc  %l5
a012fa44:  23 2a 00 b8  sethi  %hi(0xa802e000), %l1
a012fa48:  e0 04 63 d0  ld  [ %l1 + 0x3d0 ], %l0	! 0xa802e3d0
a012fa4c:  25 00 08 00  sethi  %hi(0x200000), %l2
a012fa50:  80 8c 00 12  btst  %l0, %l2
a012fa54:  22 80 00 66  be,a   0xa012fbec
a012fa58:  aa 05 60 01  inc  %l5
a012fa5c:  92 10 00 13  mov  %l3, %o1
a012fa60:  90 10 20 03  mov  3, %o0
a012fa64:  7f ff fe 76  call  0xa012f43c
a012fa68:  94 10 20 00  clr  %o2
a012fa6c:  10 80 00 60  b  0xa012fbec
a012fa70:  aa 05 60 01  inc  %l5
a012fa74:  67 fd 76 c8  call  0x4008d594
a012fa78:  d0 14 e0 14  lduh  [ %l3 + 0x14 ], %o0
a012fa7c:  b7 2a 20 10  sll  %o0, 0x10, %i3
a012fa80:  af 36 e0 10  srl  %i3, 0x10, %l7
a012fa84:  80 a5 e0 50  cmp  %l7, 0x50
a012fa88:  28 80 00 59  bleu,a   0xa012fbec
a012fa8c:  aa 05 60 01  inc  %l5
a012fa90:  d0 04 00 1d  ld  [ %l0 + %i5 ], %o0
a012fa94:  83 32 20 0c  srl  %o0, 0xc, %g1
a012fa98:  a0 08 60 0f  and  %g1, 0xf, %l0
a012fa9c:  b8 5c 20 2a  smul  %l0, 0x2a, %i4
a012faa0:  a6 07 00 1a  add  %i4, %i2, %l3
a012faa4:  d6 0c e0 0a  ldub  [ %l3 + 0xa ], %o3
a012faa8:  98 10 20 00  clr  %o4
a012faac:  9a 10 20 00  clr  %o5
a012fab0:  23 00 06 94  sethi  %hi(0x1a5000), %l1
a012fab4:  94 14 62 38  or  %l1, 0x238, %o2	! 0x1a5238
a012fab8:  d2 0a 80 0d  ldub  [ %o2 + %o5 ], %o1
a012fabc:  80 a2 c0 09  cmp  %o3, %o1
a012fac0:  02 80 00 42  be  0xa012fbc8
a012fac4:  98 03 20 01  inc  %o4
a012fac8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a012facc:  80 a3 60 03  cmp  %o5, 3
a012fad0:  28 bf ff fb  bleu,a   0xa012fabc
a012fad4:  d2 0a 80 0d  ldub  [ %o2 + %o5 ], %o1
a012fad8:  82 10 20 ff  mov  0xff, %g1
a012fadc:  1b 00 06 94  sethi  %hi(0x1a5000), %o5
a012fae0:  94 08 60 ff  and  %g1, 0xff, %o2
a012fae4:  90 13 62 38  or  %o5, 0x238, %o0
a012fae8:  d6 0a 00 0a  ldub  [ %o0 + %o2 ], %o3
a012faec:  92 0a e0 fc  and  %o3, 0xfc, %o1
a012faf0:  96 10 20 01  mov  1, %o3
a012faf4:  98 10 20 01  mov  1, %o4
a012faf8:  ae 02 80 0c  add  %o2, %o4, %l7
a012fafc:  9a 0d e0 03  and  %l7, 3, %o5
a012fb00:  ec 0a 00 0d  ldub  [ %o0 + %o5 ], %l6
a012fb04:  96 02 e0 01  inc  %o3
a012fb08:  9e 0d a0 fc  and  %l6, 0xfc, %o7
a012fb0c:  80 a3 c0 09  cmp  %o7, %o1
a012fb10:  02 80 00 30  be  0xa012fbd0
a012fb14:  98 0a e0 ff  and  %o3, 0xff, %o4
a012fb18:  80 a3 20 04  cmp  %o4, 4
a012fb1c:  08 bf ff f8  bleu  0xa012fafc
a012fb20:  ae 02 80 0c  add  %o2, %o4, %l7
a012fb24:  82 10 00 0a  mov  %o2, %g1
a012fb28:  23 00 06 94  sethi  %hi(0x1a5000), %l1
a012fb2c:  b8 08 60 ff  and  %g1, 0xff, %i4
a012fb30:  a0 14 62 38  or  %l1, 0x238, %l0
a012fb34:  e2 0c 00 1c  ldub  [ %l0 + %i4 ], %l1
a012fb38:  90 10 00 12  mov  %l2, %o0
a012fb3c:  92 10 00 11  mov  %l1, %o1
a012fb40:  7f ff fe 3f  call  0xa012f43c
a012fb44:  94 10 20 00  clr  %o2
a012fb48:  e6 05 00 00  ld  [ %l4 ], %l3
a012fb4c:  b7 34 e0 0c  srl  %l3, 0xc, %i3
a012fb50:  98 0e e0 0f  and  %i3, 0xf, %o4
a012fb54:  94 5b 20 2a  smul  %o4, 0x2a, %o2
a012fb58:  67 fd 76 8c  call  0x4008d588
a012fb5c:  a8 02 80 18  add  %o2, %i0, %l4
a012fb60:  80 a4 a0 00  cmp  %l2, 0
a012fb64:  12 80 00 21  bne  0xa012fbe8
a012fb68:  d0 35 20 14  sth  %o0, [ %l4 + 0x14 ]
a012fb6c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a012fb70:  d0 00 63 d0  ld  [ %g1 + 0x3d0 ], %o0	! 0xa802e3d0
a012fb74:  25 00 08 00  sethi  %hi(0x200000), %l2
a012fb78:  80 8a 00 12  btst  %o0, %l2
a012fb7c:  02 80 00 1b  be  0xa012fbe8
a012fb80:  92 10 00 11  mov  %l1, %o1
a012fb84:  10 bf ff b8  b  0xa012fa64
a012fb88:  90 10 20 03  mov  3, %o0
a012fb8c:  7f ff d5 6d  call  0xa0125140
a012fb90:  d0 08 60 10  ldub  [ %g1 + 0x10 ], %o0
a012fb94:  9a 0a 20 ff  and  %o0, 0xff, %o5
a012fb98:  80 a3 60 ff  cmp  %o5, 0xff
a012fb9c:  02 bf ff 67  be  0xa012f938
a012fba0:  82 10 00 11  mov  %l1, %g1
a012fba4:  10 bf ff 8c  b  0xa012f9d4
a012fba8:  27 00 06 94  sethi  %hi(0x1a5000), %l3
a012fbac:  10 bf ff 4a  b  0xa012f8d4
a012fbb0:  82 10 00 0d  mov  %o5, %g1
a012fbb4:  90 10 20 00  clr  %o0
a012fbb8:  9f c0 40 00  call  %g1
a012fbbc:  92 10 20 00  clr  %o1
a012fbc0:  10 bf ff 9f  b  0xa012fa3c
a012fbc4:  80 a4 a0 00  cmp  %l2, 0
a012fbc8:  10 bf ff c5  b  0xa012fadc
a012fbcc:  82 10 00 0d  mov  %o5, %g1
a012fbd0:  10 bf ff d6  b  0xa012fb28
a012fbd4:  82 10 00 0d  mov  %o5, %g1
a012fbd8:  10 bf ff 6a  b  0xa012f980
a012fbdc:  82 10 00 0d  mov  %o5, %g1
a012fbe0:  10 bf ff 7b  b  0xa012f9cc
a012fbe4:  82 10 00 0c  mov  %o4, %g1
a012fbe8:  aa 05 60 01  inc  %l5
a012fbec:  a4 0d 60 ff  and  %l5, 0xff, %l2
a012fbf0:  80 a4 a0 03  cmp  %l2, 3
a012fbf4:  08 bf fe ff  bleu  0xa012f7f0
a012fbf8:  97 2c a0 04  sll  %l2, 4, %o3
a012fbfc:  81 c7 e0 08  ret
a012fc00:  81 e8 00 00  restore
