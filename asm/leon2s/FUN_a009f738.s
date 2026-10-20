# leon2s FUN_a009f738 0xa009f738-0xa009facc (916 bytes)
a009f738:  9d e3 bf 98  save  %sp, -104, %sp
a009f73c:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a009f740:  90 0e 20 ff  and  %i0, 0xff, %o0
a009f744:  9a 14 23 00  or  %l0, 0x300, %o5
a009f748:  82 5a 20 34  smul  %o0, 0x34, %g1
a009f74c:  98 00 40 0d  add  %g1, %o5, %o4
a009f750:  c2 03 20 04  ld  [ %o4 + 4 ], %g1
a009f754:  d6 00 60 40  ld  [ %g1 + 0x40 ], %o3
a009f758:  9b 32 e0 10  srl  %o3, 0x10, %o5
a009f75c:  82 0a e0 ff  and  %o3, 0xff, %g1
a009f760:  80 a0 60 82  cmp  %g1, 0x82
a009f764:  d6 2e 60 42  stb  %o3, [ %i1 + 0x42 ]
a009f768:  12 80 00 a3  bne  0xa009f9f4
a009f76c:  da 2e 60 44  stb  %o5, [ %i1 + 0x44 ]
a009f770:  80 8b 60 ff  btst  0xff, %o5
a009f774:  22 80 00 a1  be,a   0xa009f9f8
a009f778:  90 10 00 19  mov  %i1, %o0
a009f77c:  c2 03 20 04  ld  [ %o4 + 4 ], %g1
a009f780:  de 00 60 44  ld  [ %g1 + 0x44 ], %o7
a009f784:  82 0b e0 60  and  %o7, 0x60, %g1
a009f788:  95 32 e0 18  srl  %o3, 0x18, %o2
a009f78c:  93 30 60 05  srl  %g1, 5, %o1
a009f790:  97 32 e0 08  srl  %o3, 8, %o3
a009f794:  83 33 e0 08  srl  %o7, 8, %g1
a009f798:  9b 33 e0 10  srl  %o7, 0x10, %o5
a009f79c:  99 33 e0 18  srl  %o7, 0x18, %o4
a009f7a0:  c2 2e 60 47  stb  %g1, [ %i1 + 0x47 ]
a009f7a4:  da 2e 60 48  stb  %o5, [ %i1 + 0x48 ]
a009f7a8:  d8 2e 60 49  stb  %o4, [ %i1 + 0x49 ]
a009f7ac:  d6 2e 60 43  stb  %o3, [ %i1 + 0x43 ]
a009f7b0:  d4 2e 60 45  stb  %o2, [ %i1 + 0x45 ]
a009f7b4:  de 2e 60 46  stb  %o7, [ %i1 + 0x46 ]
a009f7b8:  80 a2 60 03  cmp  %o1, 3
a009f7bc:  08 80 00 03  bleu  0xa009f7c8
a009f7c0:  d6 2e 40 00  stb  %o3, [ %i1 ]
a009f7c4:  92 10 20 04  mov  4, %o1
a009f7c8:  98 0a 60 ff  and  %o1, 0xff, %o4
a009f7cc:  03 28 02 d2  sethi  %hi(0xa00b4800), %g1
a009f7d0:  82 10 61 d8  or  %g1, 0x1d8, %g1	! 0xa00b49d8
a009f7d4:  9a 0b e0 10  and  %o7, 0x10, %o5
a009f7d8:  99 2b 20 03  sll  %o4, 3, %o4
a009f7dc:  d8 00 40 0c  ld  [ %g1 + %o4 ], %o4
a009f7e0:  9b 33 60 04  srl  %o5, 4, %o5
a009f7e4:  9a 0b 60 ff  and  %o5, 0xff, %o5
a009f7e8:  03 28 02 d2  sethi  %hi(0xa00b4800), %g1
a009f7ec:  82 10 61 c0  or  %g1, 0x1c0, %g1	! 0xa00b49c0
a009f7f0:  9b 2b 60 03  sll  %o5, 3, %o5
a009f7f4:  d4 00 40 0d  ld  [ %g1 + %o5 ], %o2
a009f7f8:  96 0b e0 0c  and  %o7, 0xc, %o3
a009f7fc:  83 32 e0 02  srl  %o3, 2, %g1
a009f800:  d8 26 60 04  st  %o4, [ %i1 + 4 ]
a009f804:  80 a0 60 03  cmp  %g1, 3
a009f808:  08 80 00 03  bleu  0xa009f814
a009f80c:  d4 26 60 08  st  %o2, [ %i1 + 8 ]
a009f810:  82 10 20 04  mov  4, %g1
a009f814:  82 08 60 ff  and  %g1, 0xff, %g1
a009f818:  1b 28 02 d2  sethi  %hi(0xa00b4800), %o5
a009f81c:  9a 13 61 98  or  %o5, 0x198, %o5	! 0xa00b4998
a009f820:  83 28 60 03  sll  %g1, 3, %g1
a009f824:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a009f828:  9a 0b e0 03  and  %o7, 3, %o5
a009f82c:  80 a3 60 03  cmp  %o5, 3
a009f830:  08 80 00 03  bleu  0xa009f83c
a009f834:  c2 26 60 0c  st  %g1, [ %i1 + 0xc ]
a009f838:  9a 10 20 04  mov  4, %o5
a009f83c:  9a 0b 60 ff  and  %o5, 0xff, %o5
a009f840:  03 28 02 d2  sethi  %hi(0xa00b4800), %g1
a009f844:  9b 2b 60 03  sll  %o5, 3, %o5
a009f848:  99 33 e0 0e  srl  %o7, 0xe, %o4
a009f84c:  82 10 61 70  or  %g1, 0x170, %g1
a009f850:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a009f854:  98 0b 20 03  and  %o4, 3, %o4
a009f858:  80 a3 20 03  cmp  %o4, 3
a009f85c:  08 80 00 03  bleu  0xa009f868
a009f860:  c2 26 60 10  st  %g1, [ %i1 + 0x10 ]
a009f864:  98 10 20 04  mov  4, %o4
a009f868:  9a 0b 20 ff  and  %o4, 0xff, %o5
a009f86c:  03 28 02 d2  sethi  %hi(0xa00b4800), %g1
a009f870:  9b 2b 60 03  sll  %o5, 3, %o5
a009f874:  99 33 e0 0c  srl  %o7, 0xc, %o4
a009f878:  82 10 61 48  or  %g1, 0x148, %g1
a009f87c:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a009f880:  98 0b 20 03  and  %o4, 3, %o4
a009f884:  80 a3 20 03  cmp  %o4, 3
a009f888:  08 80 00 03  bleu  0xa009f894
a009f88c:  c2 26 60 14  st  %g1, [ %i1 + 0x14 ]
a009f890:  98 10 20 04  mov  4, %o4
a009f894:  82 0b 20 ff  and  %o4, 0xff, %g1
a009f898:  1b 28 02 d2  sethi  %hi(0xa00b4800), %o5
a009f89c:  83 28 60 03  sll  %g1, 3, %g1
a009f8a0:  9a 13 61 20  or  %o5, 0x120, %o5
a009f8a4:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a009f8a8:  80 a2 a0 01  cmp  %o2, 1
a009f8ac:  12 80 00 09  bne  0xa009f8d0
a009f8b0:  c2 26 60 18  st  %g1, [ %i1 + 0x18 ]
a009f8b4:  82 0b ef 00  and  %o7, 0xf00, %g1
a009f8b8:  1b 28 02 d2  sethi  %hi(0xa00b4800), %o5
a009f8bc:  83 30 60 05  srl  %g1, 5, %g1
a009f8c0:  9a 13 60 a0  or  %o5, 0xa0, %o5
a009f8c4:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a009f8c8:  10 80 00 03  b  0xa009f8d4
a009f8cc:  c2 26 60 1c  st  %g1, [ %i1 + 0x1c ]
a009f8d0:  c0 26 60 1c  clr  [ %i1 + 0x1c ]
a009f8d4:  83 33 e0 10  srl  %o7, 0x10, %g1
a009f8d8:  82 08 60 03  and  %g1, 3, %g1
a009f8dc:  80 a0 60 03  cmp  %g1, 3
a009f8e0:  38 80 00 02  bgu,a   0xa009f8e8
a009f8e4:  82 10 20 04  mov  4, %g1
a009f8e8:  9a 08 60 ff  and  %g1, 0xff, %o5
a009f8ec:  03 28 02 d2  sethi  %hi(0xa00b4800), %g1
a009f8f0:  9b 2b 60 03  sll  %o5, 3, %o5
a009f8f4:  82 10 60 78  or  %g1, 0x78, %g1
a009f8f8:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a009f8fc:  da 0e 40 00  ldub  [ %i1 ], %o5
a009f900:  80 a3 60 02  cmp  %o5, 2
a009f904:  12 80 00 42  bne  0xa009fa0c
a009f908:  c2 26 60 2c  st  %g1, [ %i1 + 0x2c ]
a009f90c:  83 33 e0 17  srl  %o7, 0x17, %g1
a009f910:  82 08 60 01  and  %g1, 1, %g1
a009f914:  80 a0 60 01  cmp  %g1, 1
a009f918:  38 80 00 02  bgu,a   0xa009f920
a009f91c:  82 10 20 02  mov  2, %g1
a009f920:  9a 08 60 ff  and  %g1, 0xff, %o5
a009f924:  03 28 02 d2  sethi  %hi(0xa00b4800), %g1
a009f928:  9b 2b 60 03  sll  %o5, 3, %o5
a009f92c:  82 10 60 60  or  %g1, 0x60, %g1
a009f930:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a009f934:  da 06 60 14  ld  [ %i1 + 0x14 ], %o5
a009f938:  80 a3 60 03  cmp  %o5, 3
a009f93c:  12 80 00 0d  bne  0xa009f970
a009f940:  c2 26 60 20  st  %g1, [ %i1 + 0x20 ]
a009f944:  83 33 e0 14  srl  %o7, 0x14, %g1
a009f948:  82 08 60 07  and  %g1, 7, %g1
a009f94c:  80 a0 60 06  cmp  %g1, 6
a009f950:  38 80 00 02  bgu,a   0xa009f958
a009f954:  82 10 20 07  mov  7, %g1
a009f958:  82 08 60 ff  and  %g1, 0xff, %g1
a009f95c:  1b 28 02 d2  sethi  %hi(0xa00b4800), %o5
a009f960:  83 28 60 03  sll  %g1, 3, %g1
a009f964:  9a 13 60 20  or  %o5, 0x20, %o5
a009f968:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a009f96c:  c2 26 60 24  st  %g1, [ %i1 + 0x24 ]
a009f970:  83 33 e0 12  srl  %o7, 0x12, %g1
a009f974:  96 08 60 03  and  %g1, 3, %o3
a009f978:  80 a2 e0 03  cmp  %o3, 3
a009f97c:  38 80 00 02  bgu,a   0xa009f984
a009f980:  96 10 20 04  mov  4, %o3
a009f984:  9b 33 e0 18  srl  %o7, 0x18, %o5
a009f988:  9a 0b 60 7f  and  %o5, 0x7f, %o5
a009f98c:  98 14 23 00  or  %l0, 0x300, %o4
a009f990:  82 5a 20 34  smul  %o0, 0x34, %g1
a009f994:  da 2e 60 30  stb  %o5, [ %i1 + 0x30 ]
a009f998:  82 00 40 0c  add  %g1, %o4, %g1
a009f99c:  c2 00 60 04  ld  [ %g1 + 4 ], %g1
a009f9a0:  de 00 60 48  ld  [ %g1 + 0x48 ], %o7
a009f9a4:  9a 0a e0 ff  and  %o3, 0xff, %o5
a009f9a8:  03 28 02 d1  sethi  %hi(0xa00b4400), %g1
a009f9ac:  9b 2b 60 03  sll  %o5, 3, %o5
a009f9b0:  98 0b e0 c0  and  %o7, 0xc0, %o4
a009f9b4:  82 10 63 f8  or  %g1, 0x3f8, %g1
a009f9b8:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a009f9bc:  99 33 20 06  srl  %o4, 6, %o4
a009f9c0:  80 a3 20 03  cmp  %o4, 3
a009f9c4:  08 80 00 03  bleu  0xa009f9d0
a009f9c8:  c2 26 60 28  st  %g1, [ %i1 + 0x28 ]
a009f9cc:  98 10 20 04  mov  4, %o4
a009f9d0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a009f9d4:  03 28 02 d1  sethi  %hi(0xa00b4400), %g1
a009f9d8:  9b 2b 60 03  sll  %o5, 3, %o5
a009f9dc:  82 10 63 d0  or  %g1, 0x3d0, %g1
a009f9e0:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a009f9e4:  9a 0b e0 0f  and  %o7, 0xf, %o5
a009f9e8:  c2 26 60 34  st  %g1, [ %i1 + 0x34 ]
a009f9ec:  10 80 00 08  b  0xa009fa0c
a009f9f0:  da 2e 60 38  stb  %o5, [ %i1 + 0x38 ]
a009f9f4:  90 10 00 19  mov  %i1, %o0
a009f9f8:  92 10 20 00  clr  %o1
a009f9fc:  40 00 46 ec  call  0xa00b15ac
a009fa00:  94 10 20 58  mov  0x58, %o2
a009fa04:  10 80 00 30  b  0xa009fac4
a009fa08:  b0 10 20 01  mov  1, %i0
a009fa0c:  9a 0e 20 ff  and  %i0, 0xff, %o5
a009fa10:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009fa14:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009fa18:  9a 5b 60 34  smul  %o5, 0x34, %o5
a009fa1c:  9a 03 40 01  add  %o5, %g1, %o5
a009fa20:  c2 03 60 04  ld  [ %o5 + 4 ], %g1
a009fa24:  de 00 60 48  ld  [ %g1 + 0x48 ], %o7
a009fa28:  99 33 e0 10  srl  %o7, 0x10, %o4
a009fa2c:  d8 2e 60 4c  stb  %o4, [ %i1 + 0x4c ]
a009fa30:  97 33 e0 18  srl  %o7, 0x18, %o3
a009fa34:  83 33 e0 08  srl  %o7, 8, %g1
a009fa38:  19 00 3f ff  sethi  %hi(0xfffc00), %o4
a009fa3c:  d6 2e 60 4d  stb  %o3, [ %i1 + 0x4d ]
a009fa40:  c2 2e 60 4b  stb  %g1, [ %i1 + 0x4b ]
a009fa44:  de 2e 60 4a  stb  %o7, [ %i1 + 0x4a ]
a009fa48:  98 13 23 00  or  %o4, 0x300, %o4
a009fa4c:  c2 03 60 04  ld  [ %o5 + 4 ], %g1
a009fa50:  92 0b c0 0c  and  %o7, %o4, %o1
a009fa54:  de 00 60 4c  ld  [ %g1 + 0x4c ], %o7
a009fa58:  90 10 00 0b  mov  %o3, %o0
a009fa5c:  83 33 e0 08  srl  %o7, 8, %g1
a009fa60:  97 33 e0 10  srl  %o7, 0x10, %o3
a009fa64:  95 33 e0 18  srl  %o7, 0x18, %o2
a009fa68:  d6 2e 60 50  stb  %o3, [ %i1 + 0x50 ]
a009fa6c:  c2 2e 60 4f  stb  %g1, [ %i1 + 0x4f ]
a009fa70:  d4 2e 60 51  stb  %o2, [ %i1 + 0x51 ]
a009fa74:  de 2e 60 4e  stb  %o7, [ %i1 + 0x4e ]
a009fa78:  c2 03 60 04  ld  [ %o5 + 4 ], %g1
a009fa7c:  98 0b c0 0c  and  %o7, %o4, %o4
a009fa80:  9a 0b e0 ff  and  %o7, 0xff, %o5
a009fa84:  de 00 60 50  ld  [ %g1 + 0x50 ], %o7
a009fa88:  82 0b e0 ff  and  %o7, 0xff, %g1
a009fa8c:  83 28 60 08  sll  %g1, 8, %g1
a009fa90:  96 12 80 01  or  %o2, %g1, %o3
a009fa94:  9b 2b 60 08  sll  %o5, 8, %o5
a009fa98:  90 12 00 0d  or  %o0, %o5, %o0
a009fa9c:  93 32 60 08  srl  %o1, 8, %o1
a009faa0:  99 33 20 08  srl  %o4, 8, %o4
a009faa4:  83 33 e0 08  srl  %o7, 8, %g1
a009faa8:  d6 36 60 40  sth  %o3, [ %i1 + 0x40 ]
a009faac:  d2 36 60 3a  sth  %o1, [ %i1 + 0x3a ]
a009fab0:  d0 36 60 3c  sth  %o0, [ %i1 + 0x3c ]
a009fab4:  d8 36 60 3e  sth  %o4, [ %i1 + 0x3e ]
a009fab8:  c2 2e 60 53  stb  %g1, [ %i1 + 0x53 ]
a009fabc:  de 2e 60 52  stb  %o7, [ %i1 + 0x52 ]
a009fac0:  b0 10 20 00  clr  %i0
a009fac4:  81 c7 e0 08  ret
a009fac8:  81 e8 00 00  restore
