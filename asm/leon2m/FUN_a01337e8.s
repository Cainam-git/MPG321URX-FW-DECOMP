# leon2m FUN_a01337e8 0xa01337e8-0xa0133950 (360 bytes)
a01337e8:  9d e3 bf 88  save  %sp, -120, %sp
a01337ec:  83 2e 60 10  sll  %i1, 0x10, %g1
a01337f0:  b8 10 20 00  clr  %i4
a01337f4:  ba 10 20 00  clr  %i5
a01337f8:  83 30 60 10  srl  %g1, 0x10, %g1
a01337fc:  f8 3f bf f0  std  %i4, [ %fp + -16 ]
a0133800:  a4 10 00 1a  mov  %i2, %l2
a0133804:  f8 3f bf e8  std  %i4, [ %fp + -24 ]
a0133808:  80 a0 60 00  cmp  %g1, 0
a013380c:  90 10 20 02  mov  2, %o0
a0133810:  a0 10 20 10  mov  0x10, %l0
a0133814:  9a 10 20 00  clr  %o5
a0133818:  02 80 00 4c  be  0xa0133948
a013381c:  9e 10 20 00  clr  %o7
a0133820:  92 0e 20 ff  and  %i0, 0xff, %o1
a0133824:  31 2a 00 b6  sethi  %hi(0xa802d800), %i0
a0133828:  94 16 22 6c  or  %i0, 0x26c, %o2	! 0xa802da6c
a013382c:  96 10 00 01  mov  %g1, %o3
a0133830:  a2 10 00 19  mov  %i1, %l1
a0133834:  b0 07 bf e8  add  %fp, -24, %i0
a0133838:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a013383c:  b3 2b e0 10  sll  %o7, 0x10, %i1
a0133840:  83 36 60 10  srl  %i1, 0x10, %g1
a0133844:  ba 22 c0 01  sub  %o3, %g1, %i5
a0133848:  80 a7 60 10  cmp  %i5, 0x10
a013384c:  14 80 00 04  bg  0xa013385c
a0133850:  b2 00 40 12  add  %g1, %l2, %i1
a0133854:  a0 24 40 0f  sub  %l1, %o7, %l0
a0133858:  90 10 20 01  mov  1, %o0
a013385c:  b4 10 20 00  clr  %i2
a0133860:  ba 10 20 00  clr  %i5
a0133864:  b7 2f 60 02  sll  %i5, 2, %i3
a0133868:  b8 06 c0 19  add  %i3, %i1, %i4
a013386c:  c2 0e 40 1b  ldub  [ %i1 + %i3 ], %g1
a0133870:  fa 0f 20 01  ldub  [ %i4 + 1 ], %i5
a0133874:  83 28 60 08  sll  %g1, 8, %g1
a0133878:  82 00 40 1d  add  %g1, %i5, %g1
a013387c:  fa 0f 20 02  ldub  [ %i4 + 2 ], %i5
a0133880:  83 28 60 08  sll  %g1, 8, %g1
a0133884:  82 00 40 1d  add  %g1, %i5, %g1
a0133888:  fa 0f 20 03  ldub  [ %i4 + 3 ], %i5
a013388c:  83 28 60 08  sll  %g1, 8, %g1
a0133890:  b8 00 40 1d  add  %g1, %i5, %i4
a0133894:  b4 06 a0 01  inc  %i2
a0133898:  ba 0e a0 ff  and  %i2, 0xff, %i5
a013389c:  80 a7 60 04  cmp  %i5, 4
a01338a0:  0a bf ff f1  bcs  0xa0133864
a01338a4:  f8 26 00 1b  st  %i4, [ %i0 + %i3 ]
a01338a8:  b4 0c 20 ff  and  %l0, 0xff, %i2
a01338ac:  b9 2e a0 10  sll  %i2, 0x10, %i4
a01338b0:  f4 0b 23 97  ldub  [ %o4 + 0x397 ], %i2
a01338b4:  83 2b 60 18  sll  %o5, 0x18, %g1
a01338b8:  b6 0e a0 ff  and  %i2, 0xff, %i3
a01338bc:  b2 00 40 1c  add  %g1, %i4, %i1
a01338c0:  bb 2a 60 08  sll  %o1, 8, %i5
a01338c4:  82 06 40 1d  add  %i1, %i5, %g1
a01338c8:  b9 2e e0 02  sll  %i3, 2, %i4
a01338cc:  b2 0a 20 ff  and  %o0, 0xff, %i1
a01338d0:  b8 07 00 1b  add  %i4, %i3, %i4
a01338d4:  b6 00 60 03  add  %g1, 3, %i3
a01338d8:  bb 2e 60 04  sll  %i1, 4, %i5
a01338dc:  b2 06 c0 1d  add  %i3, %i5, %i1
a01338e0:  b9 2f 20 02  sll  %i4, 2, %i4
a01338e4:  f2 22 80 1c  st  %i1, [ %o2 + %i4 ]
a01338e8:  b6 07 00 0a  add  %i4, %o2, %i3
a01338ec:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a01338f0:  fa 07 bf e8  ld  [ %fp + -24 ], %i5
a01338f4:  b4 06 a0 01  inc  %i2
a01338f8:  c2 26 e0 10  st  %g1, [ %i3 + 0x10 ]
a01338fc:  fa 26 e0 04  st  %i5, [ %i3 + 4 ]
a0133900:  b2 0e a0 ff  and  %i2, 0xff, %i1
a0133904:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a0133908:  fa 07 bf f0  ld  [ %fp + -16 ], %i5
a013390c:  c2 26 e0 08  st  %g1, [ %i3 + 8 ]
a0133910:  80 a6 60 24  cmp  %i1, 0x24
a0133914:  08 80 00 0b  bleu  0xa0133940
a0133918:  fa 26 e0 0c  st  %i5, [ %i3 + 0xc ]
a013391c:  c0 2b 23 97  clrb  [ %o4 + 0x397 ]
a0133920:  b6 03 e0 10  add  %o7, 0x10, %i3
a0133924:  bb 2e e0 10  sll  %i3, 0x10, %i5
a0133928:  b3 37 60 10  srl  %i5, 0x10, %i1
a013392c:  80 a6 40 0b  cmp  %i1, %o3
a0133930:  9a 03 60 01  inc  %o5
a0133934:  0a bf ff c2  bcs  0xa013383c
a0133938:  9e 10 00 1b  mov  %i3, %o7
a013393c:  30 80 00 03  b,a   0xa0133948
a0133940:  10 bf ff f8  b  0xa0133920
a0133944:  f4 2b 23 97  stb  %i2, [ %o4 + 0x397 ]
a0133948:  81 c7 e0 08  ret
a013394c:  81 e8 00 00  restore
