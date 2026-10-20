# leon2m FUN_a011f6a4 0xa011f6a4-0xa011fbd8 (1332 bytes)
a011f6a4:  9d e3 bf 98  save  %sp, -104, %sp
a011f6a8:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011f6ac:  ba 17 20 28  or  %i4, 0x28, %i5	! 0xcf011428
a011f6b0:  f6 07 40 00  ld  [ %i5 ], %i3
a011f6b4:  82 16 e0 03  or  %i3, 3, %g1
a011f6b8:  f6 0e 40 00  ldub  [ %i1 ], %i3
a011f6bc:  9e 10 00 18  mov  %i0, %o7
a011f6c0:  c2 27 40 00  st  %g1, [ %i5 ]
a011f6c4:  80 a6 20 02  cmp  %i0, 2
a011f6c8:  02 80 01 2f  be  0xa011fb84
a011f6cc:  98 10 00 1a  mov  %i2, %o4
a011f6d0:  80 a6 20 01  cmp  %i0, 1
a011f6d4:  08 80 00 88  bleu  0xa011f8f4
a011f6d8:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a011f6dc:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011f6e0:  b6 16 e0 28  or  %i3, 0x28, %i3	! 0xcf011428
a011f6e4:  fa 0e 60 04  ldub  [ %i1 + 4 ], %i5
a011f6e8:  c2 06 c0 00  ld  [ %i3 ], %g1
a011f6ec:  b0 0f 60 0f  and  %i5, 0xf, %i0
a011f6f0:  f8 0e 60 05  ldub  [ %i1 + 5 ], %i4
a011f6f4:  bb 2e 20 04  sll  %i0, 4, %i5
a011f6f8:  b4 10 60 03  or  %g1, 3, %i2
a011f6fc:  b0 0f 20 0f  and  %i4, 0xf, %i0
a011f700:  f4 26 c0 00  st  %i2, [ %i3 ]
a011f704:  80 a3 e0 02  cmp  %o7, 2
a011f708:  02 80 00 91  be  0xa011f94c
a011f70c:  b6 17 40 18  or  %i5, %i0, %i3
a011f710:  80 a3 e0 01  cmp  %o7, 1
a011f714:  38 80 00 0d  bgu,a   0xa011f748
a011f718:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011f71c:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a011f720:  b4 10 63 b0  or  %g1, 0x3b0, %i2	! 0x1a2fb0
a011f724:  b8 03 c0 0f  add  %o7, %o7, %i4
a011f728:  f0 16 80 1c  lduh  [ %i2 + %i4 ], %i0
a011f72c:  ba 06 20 30  add  %i0, 0x30, %i5
a011f730:  b5 2f 60 02  sll  %i5, 2, %i2
a011f734:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a011f738:  b0 16 80 01  or  %i2, %g1, %i0
a011f73c:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011f740:  f8 26 00 00  st  %i4, [ %i0 ]
a011f744:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011f748:  b6 16 e0 28  or  %i3, 0x28, %i3	! 0xcf011428
a011f74c:  c2 16 60 02  lduh  [ %i1 + 2 ], %g1
a011f750:  f0 06 c0 00  ld  [ %i3 ], %i0
a011f754:  b4 08 6f ff  and  %g1, 0xfff, %i2
a011f758:  39 00 00 14  sethi  %hi(0x5000), %i4
a011f75c:  ba 16 20 03  or  %i0, 3, %i5
a011f760:  b2 16 80 1c  or  %i2, %i4, %i1
a011f764:  fa 26 c0 00  st  %i5, [ %i3 ]
a011f768:  80 a3 e0 02  cmp  %o7, 2
a011f76c:  02 80 00 96  be  0xa011f9c4
a011f770:  b0 0e 60 ff  and  %i1, 0xff, %i0
a011f774:  80 a3 e0 01  cmp  %o7, 1
a011f778:  18 80 00 12  bgu  0xa011f7c0
a011f77c:  35 33 c0 45  sethi  %hi(0xcf011400), %i2
a011f780:  39 00 06 8b  sethi  %hi(0x1a2c00), %i4
a011f784:  82 17 23 b0  or  %i4, 0x3b0, %g1	! 0x1a2fb0
a011f788:  b4 03 c0 0f  add  %o7, %o7, %i2
a011f78c:  fa 10 40 1a  lduh  [ %g1 + %i2 ], %i5
a011f790:  b6 07 60 31  add  %i5, 0x31, %i3
a011f794:  b9 2e e0 02  sll  %i3, 2, %i4
a011f798:  b4 07 60 32  add  %i5, 0x32, %i2
a011f79c:  37 33 c0 00  sethi  %hi(0xcf000000), %i3
a011f7a0:  bb 2e a0 02  sll  %i2, 2, %i5
a011f7a4:  b8 17 00 1b  or  %i4, %i3, %i4
a011f7a8:  82 0e 60 ff  and  %i1, 0xff, %g1
a011f7ac:  c2 27 00 00  st  %g1, [ %i4 ]
a011f7b0:  b0 17 40 1b  or  %i5, %i3, %i0
a011f7b4:  b5 36 60 08  srl  %i1, 8, %i2
a011f7b8:  f4 26 00 00  st  %i2, [ %i0 ]
a011f7bc:  35 33 c0 45  sethi  %hi(0xcf011400), %i2
a011f7c0:  b0 16 a0 28  or  %i2, 0x28, %i0	! 0xcf011428
a011f7c4:  f6 06 00 00  ld  [ %i0 ], %i3
a011f7c8:  ba 16 e0 03  or  %i3, 3, %i5
a011f7cc:  f2 0b 00 00  ldub  [ %o4 ], %i1
a011f7d0:  fa 26 00 00  st  %i5, [ %i0 ]
a011f7d4:  80 a3 e0 02  cmp  %o7, 2
a011f7d8:  02 80 00 99  be  0xa011fa3c
a011f7dc:  b6 0e 60 3f  and  %i1, 0x3f, %i3
a011f7e0:  80 a3 e0 01  cmp  %o7, 1
a011f7e4:  18 80 00 0d  bgu  0xa011f818
a011f7e8:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011f7ec:  31 00 06 8b  sethi  %hi(0x1a2c00), %i0
a011f7f0:  b8 16 23 b0  or  %i0, 0x3b0, %i4	! 0x1a2fb0
a011f7f4:  b2 03 c0 0f  add  %o7, %o7, %i1
a011f7f8:  fa 17 00 19  lduh  [ %i4 + %i1 ], %i5
a011f7fc:  b4 07 60 11  add  %i5, 0x11, %i2
a011f800:  b1 2e a0 02  sll  %i2, 2, %i0
a011f804:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a011f808:  b2 16 00 01  or  %i0, %g1, %i1
a011f80c:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011f810:  f8 26 40 00  st  %i4, [ %i1 ]
a011f814:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011f818:  b6 17 60 28  or  %i5, 0x28, %i3	! 0xcf011428
a011f81c:  f4 0b 20 04  ldub  [ %o4 + 4 ], %i2
a011f820:  f2 06 c0 00  ld  [ %i3 ], %i1
a011f824:  b0 0e a0 0f  and  %i2, 0xf, %i0
a011f828:  f8 0b 20 05  ldub  [ %o4 + 5 ], %i4
a011f82c:  82 16 60 03  or  %i1, 3, %g1
a011f830:  bb 2e 20 04  sll  %i0, 4, %i5
a011f834:  b4 0f 20 0f  and  %i4, 0xf, %i2
a011f838:  c2 26 c0 00  st  %g1, [ %i3 ]
a011f83c:  80 a3 e0 02  cmp  %o7, 2
a011f840:  02 80 00 9d  be  0xa011fab4
a011f844:  b6 17 40 1a  or  %i5, %i2, %i3
a011f848:  80 a3 e0 01  cmp  %o7, 1
a011f84c:  18 80 00 0d  bgu  0xa011f880
a011f850:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011f854:  31 00 06 8b  sethi  %hi(0x1a2c00), %i0
a011f858:  b8 16 23 b0  or  %i0, 0x3b0, %i4	! 0x1a2fb0
a011f85c:  b2 03 c0 0f  add  %o7, %o7, %i1
a011f860:  f4 17 00 19  lduh  [ %i4 + %i1 ], %i2
a011f864:  ba 06 a0 33  add  %i2, 0x33, %i5
a011f868:  b1 2f 60 02  sll  %i5, 2, %i0
a011f86c:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a011f870:  b2 16 00 01  or  %i0, %g1, %i1
a011f874:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011f878:  f8 26 40 00  st  %i4, [ %i1 ]
a011f87c:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011f880:  b6 16 20 28  or  %i0, 0x28, %i3	! 0xcf011428
a011f884:  f4 13 20 02  lduh  [ %o4 + 2 ], %i2
a011f888:  fa 06 c0 00  ld  [ %i3 ], %i5
a011f88c:  b8 0e af ff  and  %i2, 0xfff, %i4
a011f890:  33 00 00 10  sethi  %hi(0x4000), %i1
a011f894:  82 17 60 03  or  %i5, 3, %g1
a011f898:  b4 17 00 19  or  %i4, %i1, %i2
a011f89c:  c2 26 c0 00  st  %g1, [ %i3 ]
a011f8a0:  80 a3 e0 02  cmp  %o7, 2
a011f8a4:  02 80 00 a2  be  0xa011fb2c
a011f8a8:  37 00 06 8b  sethi  %hi(0x1a2c00), %i3
a011f8ac:  80 a3 e0 01  cmp  %o7, 1
a011f8b0:  18 80 00 c8  bgu  0xa011fbd0
a011f8b4:  39 00 06 8b  sethi  %hi(0x1a2c00), %i4
a011f8b8:  82 17 23 b0  or  %i4, 0x3b0, %g1	! 0x1a2fb0
a011f8bc:  b0 03 c0 0f  add  %o7, %o7, %i0
a011f8c0:  fa 10 40 18  lduh  [ %g1 + %i0 ], %i5
a011f8c4:  b6 07 60 34  add  %i5, 0x34, %i3
a011f8c8:  b9 2e e0 02  sll  %i3, 2, %i4
a011f8cc:  b0 07 60 35  add  %i5, 0x35, %i0
a011f8d0:  37 33 c0 00  sethi  %hi(0xcf000000), %i3
a011f8d4:  bb 2e 20 02  sll  %i0, 2, %i5
a011f8d8:  b8 17 00 1b  or  %i4, %i3, %i4
a011f8dc:  82 0e a0 ff  and  %i2, 0xff, %g1
a011f8e0:  c2 27 00 00  st  %g1, [ %i4 ]
a011f8e4:  b2 17 40 1b  or  %i5, %i3, %i1
a011f8e8:  b1 36 a0 08  srl  %i2, 8, %i0
a011f8ec:  f0 26 40 00  st  %i0, [ %i1 ]
a011f8f0:  30 80 00 b8  b,a   0xa011fbd0
a011f8f4:  b4 10 63 b0  or  %g1, 0x3b0, %i2
a011f8f8:  b8 06 00 18  add  %i0, %i0, %i4
a011f8fc:  f0 16 80 1c  lduh  [ %i2 + %i4 ], %i0
a011f900:  ba 06 20 10  add  %i0, 0x10, %i5
a011f904:  b5 2f 60 02  sll  %i5, 2, %i2
a011f908:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a011f90c:  b0 16 80 01  or  %i2, %g1, %i0
a011f910:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011f914:  f8 26 00 00  st  %i4, [ %i0 ]
a011f918:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011f91c:  b6 16 e0 28  or  %i3, 0x28, %i3	! 0xcf011428
a011f920:  fa 0e 60 04  ldub  [ %i1 + 4 ], %i5
a011f924:  c2 06 c0 00  ld  [ %i3 ], %g1
a011f928:  b0 0f 60 0f  and  %i5, 0xf, %i0
a011f92c:  f8 0e 60 05  ldub  [ %i1 + 5 ], %i4
a011f930:  bb 2e 20 04  sll  %i0, 4, %i5
a011f934:  b4 10 60 03  or  %g1, 3, %i2
a011f938:  b0 0f 20 0f  and  %i4, 0xf, %i0
a011f93c:  f4 26 c0 00  st  %i2, [ %i3 ]
a011f940:  80 a3 e0 02  cmp  %o7, 2
a011f944:  12 bf ff 73  bne  0xa011f710
a011f948:  b6 17 40 18  or  %i5, %i0, %i3
a011f94c:  35 00 06 8b  sethi  %hi(0x1a2c00), %i2
a011f950:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011f954:  b0 16 a3 b0  or  %i2, 0x3b0, %i0
a011f958:  b6 10 20 00  clr  %i3
a011f95c:  ba 10 20 00  clr  %i5
a011f960:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011f964:  ba 07 40 1d  add  %i5, %i5, %i5
a011f968:  c2 16 00 1d  lduh  [ %i0 + %i5 ], %g1
a011f96c:  82 00 60 30  add  %g1, 0x30, %g1
a011f970:  bb 28 60 02  sll  %g1, 2, %i5
a011f974:  82 17 40 1a  or  %i5, %i2, %g1
a011f978:  b6 06 e0 01  inc  %i3
a011f97c:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011f980:  f8 20 40 00  st  %i4, [ %g1 ]
a011f984:  80 a7 60 01  cmp  %i5, 1
a011f988:  08 bf ff f8  bleu  0xa011f968
a011f98c:  ba 07 40 1d  add  %i5, %i5, %i5
a011f990:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011f994:  b6 16 e0 28  or  %i3, 0x28, %i3	! 0xcf011428
a011f998:  c2 16 60 02  lduh  [ %i1 + 2 ], %g1
a011f99c:  f0 06 c0 00  ld  [ %i3 ], %i0
a011f9a0:  b4 08 6f ff  and  %g1, 0xfff, %i2
a011f9a4:  39 00 00 14  sethi  %hi(0x5000), %i4
a011f9a8:  ba 16 20 03  or  %i0, 3, %i5
a011f9ac:  b2 16 80 1c  or  %i2, %i4, %i1
a011f9b0:  fa 26 c0 00  st  %i5, [ %i3 ]
a011f9b4:  80 a3 e0 02  cmp  %o7, 2
a011f9b8:  12 bf ff 70  bne  0xa011f778
a011f9bc:  80 a3 e0 01  cmp  %o7, 1
a011f9c0:  b0 0e 60 ff  and  %i1, 0xff, %i0
a011f9c4:  3b 00 06 8b  sethi  %hi(0x1a2c00), %i5
a011f9c8:  9a 17 63 b0  or  %i5, 0x3b0, %o5	! 0x1a2fb0
a011f9cc:  b3 36 60 08  srl  %i1, 8, %i1
a011f9d0:  b6 10 20 00  clr  %i3
a011f9d4:  82 10 20 00  clr  %g1
a011f9d8:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011f9dc:  82 00 40 01  add  %g1, %g1, %g1
a011f9e0:  fa 13 40 01  lduh  [ %o5 + %g1 ], %i5
a011f9e4:  b8 07 60 31  add  %i5, 0x31, %i4
a011f9e8:  83 2f 20 02  sll  %i4, 2, %g1
a011f9ec:  b8 10 40 1a  or  %g1, %i2, %i4
a011f9f0:  ba 07 60 32  add  %i5, 0x32, %i5
a011f9f4:  83 2f 60 02  sll  %i5, 2, %g1
a011f9f8:  f0 27 00 00  st  %i0, [ %i4 ]
a011f9fc:  b8 10 40 1a  or  %g1, %i2, %i4
a011fa00:  b6 06 e0 01  inc  %i3
a011fa04:  82 0e e0 ff  and  %i3, 0xff, %g1
a011fa08:  f2 27 00 00  st  %i1, [ %i4 ]
a011fa0c:  80 a0 60 01  cmp  %g1, 1
a011fa10:  28 bf ff f4  bleu,a   0xa011f9e0
a011fa14:  82 00 40 01  add  %g1, %g1, %g1
a011fa18:  35 33 c0 45  sethi  %hi(0xcf011400), %i2
a011fa1c:  b0 16 a0 28  or  %i2, 0x28, %i0	! 0xcf011428
a011fa20:  f6 06 00 00  ld  [ %i0 ], %i3
a011fa24:  ba 16 e0 03  or  %i3, 3, %i5
a011fa28:  f2 0b 00 00  ldub  [ %o4 ], %i1
a011fa2c:  fa 26 00 00  st  %i5, [ %i0 ]
a011fa30:  80 a3 e0 02  cmp  %o7, 2
a011fa34:  12 bf ff 6b  bne  0xa011f7e0
a011fa38:  b6 0e 60 3f  and  %i1, 0x3f, %i3
a011fa3c:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011fa40:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a011fa44:  b0 10 63 b0  or  %g1, 0x3b0, %i0	! 0x1a2fb0
a011fa48:  b6 10 20 00  clr  %i3
a011fa4c:  ba 10 20 00  clr  %i5
a011fa50:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011fa54:  ba 07 40 1d  add  %i5, %i5, %i5
a011fa58:  f4 16 00 1d  lduh  [ %i0 + %i5 ], %i2
a011fa5c:  82 06 a0 11  add  %i2, 0x11, %g1
a011fa60:  bb 28 60 02  sll  %g1, 2, %i5
a011fa64:  b4 17 40 19  or  %i5, %i1, %i2
a011fa68:  b6 06 e0 01  inc  %i3
a011fa6c:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011fa70:  f8 26 80 00  st  %i4, [ %i2 ]
a011fa74:  80 a7 60 01  cmp  %i5, 1
a011fa78:  08 bf ff f8  bleu  0xa011fa58
a011fa7c:  ba 07 40 1d  add  %i5, %i5, %i5
a011fa80:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011fa84:  b6 17 60 28  or  %i5, 0x28, %i3	! 0xcf011428
a011fa88:  f4 0b 20 04  ldub  [ %o4 + 4 ], %i2
a011fa8c:  f2 06 c0 00  ld  [ %i3 ], %i1
a011fa90:  b0 0e a0 0f  and  %i2, 0xf, %i0
a011fa94:  f8 0b 20 05  ldub  [ %o4 + 5 ], %i4
a011fa98:  82 16 60 03  or  %i1, 3, %g1
a011fa9c:  bb 2e 20 04  sll  %i0, 4, %i5
a011faa0:  b4 0f 20 0f  and  %i4, 0xf, %i2
a011faa4:  c2 26 c0 00  st  %g1, [ %i3 ]
a011faa8:  80 a3 e0 02  cmp  %o7, 2
a011faac:  12 bf ff 67  bne  0xa011f848
a011fab0:  b6 17 40 1a  or  %i5, %i2, %i3
a011fab4:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011fab8:  37 00 06 8b  sethi  %hi(0x1a2c00), %i3
a011fabc:  b0 16 e3 b0  or  %i3, 0x3b0, %i0	! 0x1a2fb0
a011fac0:  b6 10 20 00  clr  %i3
a011fac4:  ba 10 20 00  clr  %i5
a011fac8:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011facc:  b4 07 40 1d  add  %i5, %i5, %i2
a011fad0:  c2 16 00 1a  lduh  [ %i0 + %i2 ], %g1
a011fad4:  ba 00 60 33  add  %g1, 0x33, %i5
a011fad8:  b5 2f 60 02  sll  %i5, 2, %i2
a011fadc:  b6 06 e0 01  inc  %i3
a011fae0:  82 16 80 19  or  %i2, %i1, %g1
a011fae4:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011fae8:  f8 20 40 00  st  %i4, [ %g1 ]
a011faec:  80 a7 60 01  cmp  %i5, 1
a011faf0:  08 bf ff f8  bleu  0xa011fad0
a011faf4:  b4 07 40 1d  add  %i5, %i5, %i2
a011faf8:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011fafc:  b6 16 20 28  or  %i0, 0x28, %i3	! 0xcf011428
a011fb00:  f4 13 20 02  lduh  [ %o4 + 2 ], %i2
a011fb04:  fa 06 c0 00  ld  [ %i3 ], %i5
a011fb08:  b8 0e af ff  and  %i2, 0xfff, %i4
a011fb0c:  33 00 00 10  sethi  %hi(0x4000), %i1
a011fb10:  82 17 60 03  or  %i5, 3, %g1
a011fb14:  b4 17 00 19  or  %i4, %i1, %i2
a011fb18:  c2 26 c0 00  st  %g1, [ %i3 ]
a011fb1c:  80 a3 e0 02  cmp  %o7, 2
a011fb20:  12 bf ff 64  bne  0xa011f8b0
a011fb24:  80 a3 e0 01  cmp  %o7, 1
a011fb28:  37 00 06 8b  sethi  %hi(0x1a2c00), %i3
a011fb2c:  b0 0e a0 ff  and  %i2, 0xff, %i0
a011fb30:  9e 16 e3 b0  or  %i3, 0x3b0, %o7
a011fb34:  b5 36 a0 08  srl  %i2, 8, %i2
a011fb38:  b6 10 20 00  clr  %i3
a011fb3c:  82 10 20 00  clr  %g1
a011fb40:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011fb44:  82 00 40 01  add  %g1, %g1, %g1
a011fb48:  fa 13 c0 01  lduh  [ %o7 + %g1 ], %i5
a011fb4c:  b8 07 60 34  add  %i5, 0x34, %i4
a011fb50:  83 2f 20 02  sll  %i4, 2, %g1
a011fb54:  ba 07 60 35  add  %i5, 0x35, %i5
a011fb58:  b8 10 40 19  or  %g1, %i1, %i4
a011fb5c:  83 2f 60 02  sll  %i5, 2, %g1
a011fb60:  ba 10 40 19  or  %g1, %i1, %i5
a011fb64:  b6 06 e0 01  inc  %i3
a011fb68:  f0 27 00 00  st  %i0, [ %i4 ]
a011fb6c:  82 0e e0 ff  and  %i3, 0xff, %g1
a011fb70:  f4 27 40 00  st  %i2, [ %i5 ]
a011fb74:  80 a0 60 01  cmp  %g1, 1
a011fb78:  28 bf ff f4  bleu,a   0xa011fb48
a011fb7c:  82 00 40 01  add  %g1, %g1, %g1
a011fb80:  30 80 00 14  b,a   0xa011fbd0
a011fb84:  35 00 06 8b  sethi  %hi(0x1a2c00), %i2
a011fb88:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011fb8c:  b0 16 a3 b0  or  %i2, 0x3b0, %i0
a011fb90:  b6 10 20 00  clr  %i3
a011fb94:  ba 10 20 00  clr  %i5
a011fb98:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011fb9c:  ba 07 40 1d  add  %i5, %i5, %i5
a011fba0:  c2 16 00 1d  lduh  [ %i0 + %i5 ], %g1
a011fba4:  82 00 60 10  add  %g1, 0x10, %g1
a011fba8:  bb 28 60 02  sll  %g1, 2, %i5
a011fbac:  82 17 40 1a  or  %i5, %i2, %g1
a011fbb0:  b6 06 e0 01  inc  %i3
a011fbb4:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011fbb8:  f8 20 40 00  st  %i4, [ %g1 ]
a011fbbc:  80 a7 60 01  cmp  %i5, 1
a011fbc0:  08 bf ff f8  bleu  0xa011fba0
a011fbc4:  ba 07 40 1d  add  %i5, %i5, %i5
a011fbc8:  10 bf fe c6  b  0xa011f6e0
a011fbcc:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011fbd0:  81 c7 e0 08  ret
a011fbd4:  81 e8 00 00  restore
