# leon2m FUN_a01387a4 0xa01387a4-0xa0138ae8 (836 bytes)
a01387a4:  9d e3 bf 40  save  %sp, -192, %sp
a01387a8:  7f ff f2 4d  call  0xa01350dc
a01387ac:  ba 10 20 00  clr  %i5
a01387b0:  7f ff f1 8c  call  0xa0134de0
a01387b4:  01 00 00 00  nop
a01387b8:  98 10 20 01  mov  1, %o4	! 0x1
a01387bc:  9a 10 20 06  mov  6, %o5
a01387c0:  d8 37 bf e8  sth  %o4, [ %fp + -24 ]
a01387c4:  96 10 20 02  mov  2, %o3
a01387c8:  94 10 20 03  mov  3, %o2
a01387cc:  92 10 20 04  mov  4, %o1
a01387d0:  90 10 20 05  mov  5, %o0
a01387d4:  da 37 bf f2  sth  %o5, [ %fp + -14 ]
a01387d8:  82 10 20 07  mov  7, %g1
a01387dc:  d6 37 bf ea  sth  %o3, [ %fp + -22 ]
a01387e0:  d4 37 bf ec  sth  %o2, [ %fp + -20 ]
a01387e4:  d2 37 bf ee  sth  %o1, [ %fp + -18 ]
a01387e8:  d0 37 bf f0  sth  %o0, [ %fp + -16 ]
a01387ec:  c2 37 bf f4  sth  %g1, [ %fp + -12 ]
a01387f0:  98 10 20 00  clr  %o4
a01387f4:  9a 10 20 00  clr  %o5
a01387f8:  a8 07 bf f8  add  %fp, -8, %l4
a01387fc:  a1 2b 60 02  sll  %o5, 2, %l0
a0138800:  98 03 20 01  inc  %o4
a0138804:  9e 04 00 14  add  %l0, %l4, %o7
a0138808:  9a 0b 20 ff  and  %o4, 0xff, %o5
a013880c:  c0 23 ff d0  clr  [ %o7 + -48 ]
a0138810:  80 a3 60 03  cmp  %o5, 3
a0138814:  08 bf ff fa  bleu  0xa01387fc
a0138818:  c0 23 ff e0  clr  [ %o7 + -32 ]
a013881c:  92 10 20 00  clr  %o1
a0138820:  94 07 bf b8  add  %fp, -72, %o2
a0138824:  96 10 20 04  mov  4, %o3
a0138828:  67 fd 4f 2a  call  0x4008c4d0
a013882c:  90 10 20 01  mov  1, %o0
a0138830:  25 2a 00 b7  sethi  %hi(0xa802dc00), %l2
a0138834:  e2 07 bf b8  ld  [ %fp + -72 ], %l1
a0138838:  92 14 a2 c0  or  %l2, 0x2c0, %o1
a013883c:  95 34 60 04  srl  %l1, 4, %o2
a0138840:  96 10 20 00  clr  %o3
a0138844:  98 10 20 00  clr  %o4
a0138848:  af 2b 20 02  sll  %o4, 2, %l7
a013884c:  a7 2b 20 04  sll  %o4, 4, %l3
a0138850:  ad 32 80 17  srl  %o2, %l7, %l6
a0138854:  96 02 e0 01  inc  %o3
a0138858:  aa 0d a0 0f  and  %l6, 0xf, %l5
a013885c:  98 0a e0 ff  and  %o3, 0xff, %o4
a0138860:  80 a3 20 07  cmp  %o4, 7
a0138864:  0a bf ff f9  bcs  0xa0138848
a0138868:  ea 2a 40 13  stb  %l5, [ %o1 + %l3 ]
a013886c:  90 10 20 01  mov  1, %o0
a0138870:  92 10 20 0c  mov  0xc, %o1
a0138874:  94 07 bf a4  add  %fp, -92, %o2
a0138878:  96 10 20 01  mov  1, %o3
a013887c:  67 fd 4f 15  call  0x4008c4d0
a0138880:  35 2a 00 b7  sethi  %hi(0xa802dc00), %i2
a0138884:  f6 0f bf a5  ldub  [ %fp + -91 ], %i3
a0138888:  ae 16 a2 c0  or  %i2, 0x2c0, %l7
a013888c:  b9 2e e0 10  sll  %i3, 0x10, %i4
a0138890:  b4 10 00 1b  mov  %i3, %i2
a0138894:  a4 10 20 00  clr  %l2
a0138898:  a0 10 20 00  clr  %l0
a013889c:  ac 07 bf c8  add  %fp, -56, %l6
a01388a0:  2b 2a 00 a9  sethi  %hi(0xa802a400), %l5
a01388a4:  10 80 00 06  b  0xa01388bc
a01388a8:  b6 10 20 01  mov  1, %i3
a01388ac:  a0 0c a0 ff  and  %l2, 0xff, %l0
a01388b0:  80 a4 20 06  cmp  %l0, 6
a01388b4:  18 80 00 28  bgu  0xa0138954
a01388b8:  80 a7 20 00  cmp  %i4, 0
a01388bc:  96 04 00 10  add  %l0, %l0, %o3
a01388c0:  94 02 c0 14  add  %o3, %l4, %o2
a01388c4:  d2 0a bf f1  ldub  [ %o2 + -15 ], %o1
a01388c8:  91 2a 60 04  sll  %o1, 4, %o0
a01388cc:  92 0a 20 f0  and  %o0, 0xf0, %o1
a01388d0:  96 10 20 04  mov  4, %o3
a01388d4:  90 10 20 01  mov  1, %o0
a01388d8:  67 fd 4e fe  call  0x4008c4d0
a01388dc:  94 10 00 16  mov  %l6, %o2
a01388e0:  d6 07 bf c8  ld  [ %fp + -56 ], %o3
a01388e4:  82 15 60 50  or  %l5, 0x50, %g1
a01388e8:  c2 08 40 10  ldub  [ %g1 + %l0 ], %g1
a01388ec:  9a 0a e0 ff  and  %o3, 0xff, %o5
a01388f0:  80 a0 40 0d  cmp  %g1, %o5
a01388f4:  32 bf ff ee  bne,a   0xa01388ac
a01388f8:  a4 04 a0 01  inc  %l2
a01388fc:  98 00 7f ff  add  %g1, -1, %o4
a0138900:  80 a3 20 08  cmp  %o4, 8
a0138904:  38 bf ff ea  bgu,a   0xa01388ac
a0138908:  a4 04 a0 01  inc  %l2
a013890c:  a6 02 ff ff  add  %o3, -1, %l3
a0138910:  a2 0c e0 ff  and  %l3, 0xff, %l1
a0138914:  a7 2c 60 04  sll  %l1, 4, %l3
a0138918:  a2 04 c0 17  add  %l3, %l7, %l1
a013891c:  9b 32 e0 10  srl  %o3, 0x10, %o5
a0138920:  83 32 e0 08  srl  %o3, 8, %g1
a0138924:  de 0d c0 13  ldub  [ %l7 + %l3 ], %o7
a0138928:  c2 2c 60 0c  stb  %g1, [ %l1 + 0xc ]
a013892c:  80 a3 e0 05  cmp  %o7, 5
a0138930:  02 80 00 13  be  0xa013897c
a0138934:  da 2c 60 0d  stb  %o5, [ %l1 + 0xd ]
a0138938:  9b 2e c0 10  sll  %i3, %l0, %o5
a013893c:  a4 04 a0 01  inc  %l2
a0138940:  a0 0c a0 ff  and  %l2, 0xff, %l0
a0138944:  80 a4 20 06  cmp  %l0, 6
a0138948:  08 bf ff dd  bleu  0xa01388bc
a013894c:  ba 13 40 1d  or  %o5, %i5, %i5
a0138950:  80 a7 20 00  cmp  %i4, 0
a0138954:  02 80 00 63  be  0xa0138ae0
a0138958:  a9 2f 60 10  sll  %i5, 0x10, %l4
a013895c:  80 a5 20 00  cmp  %l4, 0
a0138960:  02 80 00 60  be  0xa0138ae0
a0138964:  b8 0f 40 1a  and  %i5, %i2, %i4
a0138968:  a0 0f 20 ff  and  %i4, 0xff, %l0
a013896c:  80 a4 20 00  cmp  %l0, 0
a0138970:  02 80 00 5c  be  0xa0138ae0
a0138974:  a2 10 00 1c  mov  %i4, %l1
a0138978:  30 80 00 45  b,a   0xa0138a8c
a013897c:  d6 07 bf cc  ld  [ %fp + -52 ], %o3
a0138980:  93 32 e0 08  srl  %o3, 8, %o1
a0138984:  d0 07 bf d0  ld  [ %fp + -48 ], %o0
a0138988:  de 07 bf d4  ld  [ %fp + -44 ], %o7
a013898c:  82 0a 60 1f  and  %o1, 0x1f, %g1
a0138990:  99 37 20 10  srl  %i4, 0x10, %o4
a0138994:  95 32 e0 10  srl  %o3, 0x10, %o2
a0138998:  93 32 20 10  srl  %o0, 0x10, %o1
a013899c:  9b 33 e0 10  srl  %o7, 0x10, %o5
a01389a0:  99 3b 00 10  sra  %o4, %l0, %o4
a01389a4:  da 34 60 0a  sth  %o5, [ %l1 + 0xa ]
a01389a8:  c2 2c 60 0e  stb  %g1, [ %l1 + 0xe ]
a01389ac:  d4 34 60 02  sth  %o2, [ %l1 + 2 ]
a01389b0:  d2 34 60 06  sth  %o1, [ %l1 + 6 ]
a01389b4:  80 8b 20 01  btst  1, %o4
a01389b8:  d6 2c 60 01  stb  %o3, [ %l1 + 1 ]
a01389bc:  d0 34 60 04  sth  %o0, [ %l1 + 4 ]
a01389c0:  02 80 00 06  be  0xa01389d8
a01389c4:  de 34 60 08  sth  %o7, [ %l1 + 8 ]
a01389c8:  a3 2e c0 10  sll  %i3, %l0, %l1
a01389cc:  a0 10 20 02  mov  2, %l0
a01389d0:  e0 2d c0 13  stb  %l0, [ %l7 + %l3 ]
a01389d4:  ba 14 40 1d  or  %l1, %i5, %i5
a01389d8:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a01389dc:  e6 0b 63 98  ldub  [ %o5 + 0x398 ], %l3	! 0xa802cb98
a01389e0:  80 a4 e0 00  cmp  %l3, 0
a01389e4:  32 bf ff b2  bne,a   0xa01388ac
a01389e8:  a4 04 a0 01  inc  %l2
a01389ec:  f6 2b 63 98  stb  %i3, [ %o5 + 0x398 ]
a01389f0:  10 80 00 10  b  0xa0138a30
a01389f4:  a0 10 20 00  clr  %l0
a01389f8:  7f fe 93 07  call  0xa00dd614
a01389fc:  90 10 20 20  mov  0x20, %o0
a0138a00:  94 0c 20 ff  and  %l0, 0xff, %o2
a0138a04:  80 8a 20 ff  btst  0xff, %o0
a0138a08:  97 2a a0 02  sll  %o2, 2, %o3
a0138a0c:  11 00 06 95  sethi  %hi(0x1a5400), %o0
a0138a10:  a0 04 20 01  inc  %l0
a0138a14:  82 02 c0 14  add  %o3, %l4, %g1
a0138a18:  12 80 00 19  bne  0xa0138a7c
a0138a1c:  90 12 22 30  or  %o0, 0x230, %o0
a0138a20:  82 0c 20 ff  and  %l0, 0xff, %g1
a0138a24:  80 a0 60 03  cmp  %g1, 3
a0138a28:  38 bf ff a1  bgu,a   0xa01388ac
a0138a2c:  a4 04 a0 01  inc  %l2
a0138a30:  7f fe 92 f9  call  0xa00dd614
a0138a34:  90 10 20 20  mov  0x20, %o0
a0138a38:  80 8a 20 ff  btst  0xff, %o0
a0138a3c:  1f 00 06 95  sethi  %hi(0x1a5400), %o7
a0138a40:  90 13 e2 40  or  %o7, 0x240, %o0	! 0x1a5640
a0138a44:  02 bf ff ed  be  0xa01389f8
a0138a48:  92 0c 20 ff  and  %l0, 0xff, %o1
a0138a4c:  7f fe 99 c9  call  0xa00df170
a0138a50:  01 00 00 00  nop
a0138a54:  7f fe 92 f0  call  0xa00dd614
a0138a58:  90 10 20 20  mov  0x20, %o0	! 0x20
a0138a5c:  94 0c 20 ff  and  %l0, 0xff, %o2
a0138a60:  80 8a 20 ff  btst  0xff, %o0
a0138a64:  97 2a a0 02  sll  %o2, 2, %o3
a0138a68:  11 00 06 95  sethi  %hi(0x1a5400), %o0
a0138a6c:  a0 04 20 01  inc  %l0
a0138a70:  82 02 c0 14  add  %o3, %l4, %g1
a0138a74:  02 bf ff eb  be  0xa0138a20
a0138a78:  90 12 22 30  or  %o0, 0x230, %o0
a0138a7c:  7f fe 99 bd  call  0xa00df170
a0138a80:  d2 00 7f d0  ld  [ %g1 + -48 ], %o1
a0138a84:  10 bf ff e8  b  0xa0138a24
a0138a88:  82 0c 20 ff  and  %l0, 0xff, %g1
a0138a8c:  7f fe 92 e2  call  0xa00dd614
a0138a90:  90 10 20 20  mov  0x20, %o0
a0138a94:  80 8a 20 ff  btst  0xff, %o0
a0138a98:  12 80 00 0d  bne  0xa0138acc
a0138a9c:  3b 00 06 95  sethi  %hi(0x1a5400), %i5
a0138aa0:  98 10 20 00  clr  %o4
a0138aa4:  9a 10 20 00  clr  %o5
a0138aa8:  d8 3f bf a8  std  %o4, [ %fp + -88 ]
a0138aac:  e2 2f bf a8  stb  %l1, [ %fp + -88 ]
a0138ab0:  c0 27 bf b0  clr  [ %fp + -80 ]
a0138ab4:  90 10 20 81  mov  0x81, %o0
a0138ab8:  92 10 20 0c  mov  0xc, %o1
a0138abc:  94 07 bf a8  add  %fp, -88, %o2
a0138ac0:  7f ff f9 87  call  0xa01370dc
a0138ac4:  96 10 20 00  clr  %o3
a0138ac8:  30 80 00 06  b,a   0xa0138ae0
a0138acc:  90 17 62 58  or  %i5, 0x258, %o0
a0138ad0:  7f fe 99 a8  call  0xa00df170
a0138ad4:  92 10 00 10  mov  %l0, %o1
a0138ad8:  10 bf ff f3  b  0xa0138aa4
a0138adc:  98 10 20 00  clr  %o4
a0138ae0:  81 c7 e0 08  ret
a0138ae4:  81 e8 00 00  restore
