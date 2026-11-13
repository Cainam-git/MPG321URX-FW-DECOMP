# leon2m FUN_a010e8ec 0xa010e8ec-0xa010ebd0 (740 bytes)
a010e8ec:  9d e3 bf 98  save  %sp, -104, %sp
a010e8f0:  9e 10 00 18  mov  %i0, %o7
a010e8f4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a010e8f8:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010e8fc:  98 10 00 1b  mov  %i3, %o4
a010e900:  80 a6 20 01  cmp  %i0, 1
a010e904:  02 80 00 ae  be  0xa010ebbc
a010e908:  82 10 63 04  or  %g1, 0x304, %g1
a010e90c:  d8 28 60 3d  stb  %o4, [ %g1 + 0x3d ]
a010e910:  f2 28 60 3b  stb  %i1, [ %g1 + 0x3b ]
a010e914:  f4 28 60 3c  stb  %i2, [ %g1 + 0x3c ]
a010e918:  80 a6 20 01  cmp  %i0, 1
a010e91c:  08 80 00 03  bleu  0xa010e928
a010e920:  b8 10 00 0f  mov  %o7, %i4
a010e924:  b8 10 20 00  clr  %i4
a010e928:  82 0e 60 ff  and  %i1, 0xff, %g1
a010e92c:  b7 28 60 08  sll  %g1, 8, %i3
a010e930:  ba 26 c0 01  sub  %i3, %g1, %i5
a010e934:  03 14 7a e1  sethi  %hi(0x51eb8400), %g1
a010e938:  b2 07 60 32  add  %i5, 0x32, %i1
a010e93c:  82 10 61 1f  or  %g1, 0x11f, %g1
a010e940:  b6 0f 20 ff  and  %i4, 0xff, %i3
a010e944:  80 56 40 01  umul  %i1, %g1, %g0
a010e948:  bb 40 00 00  rd  %y, %i5
a010e94c:  83 2e e0 02  sll  %i3, 2, %g1
a010e950:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010e954:  b6 13 62 c4  or  %o5, 0x2c4, %i3	! 0x19aec4
a010e958:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010e95c:  bb 37 60 05  srl  %i5, 5, %i5
a010e960:  f8 06 60 24  ld  [ %i1 + 0x24 ], %i4
a010e964:  b2 07 7f 80  add  %i5, -128, %i1
a010e968:  03 00 3f c0  sethi  %hi(0xff0000), %g1
a010e96c:  82 2f 00 01  andn  %i4, %g1, %g1
a010e970:  bb 2e 60 10  sll  %i1, 0x10, %i5
a010e974:  80 a6 20 01  cmp  %i0, 1
a010e978:  08 80 00 83  bleu  0xa010eb84
a010e97c:  b2 10 40 1d  or  %g1, %i5, %i1
a010e980:  b8 10 20 00  clr  %i4
a010e984:  83 2f 20 02  sll  %i4, 2, %g1
a010e988:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010e98c:  b8 07 20 01  inc  %i4
a010e990:  f2 27 60 24  st  %i1, [ %i5 + 0x24 ]
a010e994:  80 a7 20 01  cmp  %i4, 1
a010e998:  08 bf ff fc  bleu  0xa010e988
a010e99c:  83 2f 20 02  sll  %i4, 2, %g1
a010e9a0:  80 a6 20 01  cmp  %i0, 1
a010e9a4:  08 80 00 72  bleu  0xa010eb6c
a010e9a8:  17 00 06 6b  sethi  %hi(0x19ac00), %o3
a010e9ac:  b8 10 20 00  clr  %i4
a010e9b0:  b6 12 e2 bc  or  %o3, 0x2bc, %i3
a010e9b4:  83 2f 20 02  sll  %i4, 2, %g1
a010e9b8:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010e9bc:  b8 07 20 01  inc  %i4
a010e9c0:  f2 27 60 24  st  %i1, [ %i5 + 0x24 ]
a010e9c4:  80 a7 20 01  cmp  %i4, 1
a010e9c8:  08 bf ff fc  bleu  0xa010e9b8
a010e9cc:  83 2f 20 02  sll  %i4, 2, %g1
a010e9d0:  80 a6 20 01  cmp  %i0, 1
a010e9d4:  08 80 00 03  bleu  0xa010e9e0
a010e9d8:  b8 10 00 0f  mov  %o7, %i4
a010e9dc:  b8 10 20 00  clr  %i4
a010e9e0:  ba 0e a0 ff  and  %i2, 0xff, %i5
a010e9e4:  b3 2f 60 08  sll  %i5, 8, %i1
a010e9e8:  b6 26 40 1d  sub  %i1, %i5, %i3
a010e9ec:  b2 0f 20 ff  and  %i4, 0xff, %i1
a010e9f0:  ba 06 e0 32  add  %i3, 0x32, %i5
a010e9f4:  35 14 7a e1  sethi  %hi(0x51eb8400), %i2
a010e9f8:  b7 2e 60 02  sll  %i1, 2, %i3
a010e9fc:  82 16 a1 1f  or  %i2, 0x11f, %g1
a010ea00:  80 57 40 01  umul  %i5, %g1, %g0
a010ea04:  b5 40 00 00  rd  %y, %i2
a010ea08:  b2 13 62 c4  or  %o5, 0x2c4, %i1
a010ea0c:  c2 06 40 1b  ld  [ %i1 + %i3 ], %g1
a010ea10:  37 00 3f c0  sethi  %hi(0xff0000), %i3
a010ea14:  bb 36 a0 05  srl  %i2, 5, %i5
a010ea18:  f8 00 60 28  ld  [ %g1 + 0x28 ], %i4
a010ea1c:  b4 07 7f 80  add  %i5, -128, %i2
a010ea20:  82 2f 00 1b  andn  %i4, %i3, %g1
a010ea24:  b7 2e a0 10  sll  %i2, 0x10, %i3
a010ea28:  80 a6 20 01  cmp  %i0, 1
a010ea2c:  08 80 00 4b  bleu  0xa010eb58
a010ea30:  b4 10 40 1b  or  %g1, %i3, %i2
a010ea34:  b8 10 20 00  clr  %i4
a010ea38:  83 2f 20 02  sll  %i4, 2, %g1
a010ea3c:  f6 06 40 01  ld  [ %i1 + %g1 ], %i3
a010ea40:  b8 07 20 01  inc  %i4
a010ea44:  f4 26 e0 28  st  %i2, [ %i3 + 0x28 ]
a010ea48:  80 a7 20 01  cmp  %i4, 1
a010ea4c:  08 bf ff fc  bleu  0xa010ea3c
a010ea50:  83 2f 20 02  sll  %i4, 2, %g1
a010ea54:  80 a6 20 01  cmp  %i0, 1
a010ea58:  08 80 00 3b  bleu  0xa010eb44
a010ea5c:  b6 12 e2 bc  or  %o3, 0x2bc, %i3
a010ea60:  37 00 06 6b  sethi  %hi(0x19ac00), %i3
a010ea64:  b2 16 e2 bc  or  %i3, 0x2bc, %i1	! 0x19aebc
a010ea68:  b8 10 20 00  clr  %i4
a010ea6c:  83 2f 20 02  sll  %i4, 2, %g1
a010ea70:  fa 06 40 01  ld  [ %i1 + %g1 ], %i5
a010ea74:  b8 07 20 01  inc  %i4
a010ea78:  f4 27 60 28  st  %i2, [ %i5 + 0x28 ]
a010ea7c:  80 a7 20 01  cmp  %i4, 1
a010ea80:  08 bf ff fc  bleu  0xa010ea70
a010ea84:  83 2f 20 02  sll  %i4, 2, %g1
a010ea88:  80 a6 20 01  cmp  %i0, 1
a010ea8c:  08 80 00 03  bleu  0xa010ea98
a010ea90:  b8 10 00 0f  mov  %o7, %i4
a010ea94:  b8 10 20 00  clr  %i4
a010ea98:  b4 0b 20 ff  and  %o4, 0xff, %i2
a010ea9c:  b7 2e a0 08  sll  %i2, 8, %i3
a010eaa0:  ba 26 c0 1a  sub  %i3, %i2, %i5
a010eaa4:  33 14 7a e1  sethi  %hi(0x51eb8400), %i1
a010eaa8:  b4 07 60 32  add  %i5, 0x32, %i2
a010eaac:  82 16 61 1f  or  %i1, 0x11f, %g1
a010eab0:  80 56 80 01  umul  %i2, %g1, %g0
a010eab4:  b3 40 00 00  rd  %y, %i1
a010eab8:  b8 0f 20 ff  and  %i4, 0xff, %i4
a010eabc:  b7 2f 20 02  sll  %i4, 2, %i3
a010eac0:  b4 13 62 c4  or  %o5, 0x2c4, %i2
a010eac4:  c2 06 80 1b  ld  [ %i2 + %i3 ], %g1
a010eac8:  bb 36 60 05  srl  %i1, 5, %i5
a010eacc:  37 00 3f c0  sethi  %hi(0xff0000), %i3
a010ead0:  f8 00 60 2c  ld  [ %g1 + 0x2c ], %i4
a010ead4:  b2 07 7f 80  add  %i5, -128, %i1
a010ead8:  82 2f 00 1b  andn  %i4, %i3, %g1
a010eadc:  bb 2e 60 10  sll  %i1, 0x10, %i5
a010eae0:  80 a6 20 01  cmp  %i0, 1
a010eae4:  08 80 00 31  bleu  0xa010eba8
a010eae8:  b6 10 40 1d  or  %g1, %i5, %i3
a010eaec:  b8 10 20 00  clr  %i4
a010eaf0:  83 2f 20 02  sll  %i4, 2, %g1
a010eaf4:  f2 06 80 01  ld  [ %i2 + %g1 ], %i1
a010eaf8:  b8 07 20 01  inc  %i4
a010eafc:  f6 26 60 2c  st  %i3, [ %i1 + 0x2c ]
a010eb00:  80 a7 20 01  cmp  %i4, 1
a010eb04:  08 bf ff fc  bleu  0xa010eaf4
a010eb08:  83 2f 20 02  sll  %i4, 2, %g1
a010eb0c:  80 a6 20 01  cmp  %i0, 1
a010eb10:  28 80 00 22  bleu,a   0xa010eb98
a010eb14:  ba 12 e2 bc  or  %o3, 0x2bc, %i5
a010eb18:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010eb1c:  b4 16 22 bc  or  %i0, 0x2bc, %i2	! 0x19aebc
a010eb20:  b8 10 20 00  clr  %i4
a010eb24:  83 2f 20 02  sll  %i4, 2, %g1
a010eb28:  f2 06 80 01  ld  [ %i2 + %g1 ], %i1
a010eb2c:  b8 07 20 01  inc  %i4
a010eb30:  f6 26 60 2c  st  %i3, [ %i1 + 0x2c ]
a010eb34:  80 a7 20 01  cmp  %i4, 1
a010eb38:  08 bf ff fc  bleu  0xa010eb28
a010eb3c:  83 2f 20 02  sll  %i4, 2, %g1
a010eb40:  30 80 00 22  b,a   0xa010ebc8
a010eb44:  b9 2e 20 02  sll  %i0, 2, %i4
a010eb48:  f2 06 c0 1c  ld  [ %i3 + %i4 ], %i1
a010eb4c:  f4 26 60 28  st  %i2, [ %i1 + 0x28 ]
a010eb50:  10 bf ff cf  b  0xa010ea8c
a010eb54:  80 a6 20 01  cmp  %i0, 1
a010eb58:  bb 2e 20 02  sll  %i0, 2, %i5
a010eb5c:  f8 06 40 1d  ld  [ %i1 + %i5 ], %i4
a010eb60:  f4 27 20 28  st  %i2, [ %i4 + 0x28 ]
a010eb64:  10 bf ff bd  b  0xa010ea58
a010eb68:  80 a6 20 01  cmp  %i0, 1
a010eb6c:  ba 12 e2 bc  or  %o3, 0x2bc, %i5
a010eb70:  b9 2e 20 02  sll  %i0, 2, %i4
a010eb74:  f6 07 40 1c  ld  [ %i5 + %i4 ], %i3
a010eb78:  f2 26 e0 24  st  %i1, [ %i3 + 0x24 ]
a010eb7c:  10 bf ff 96  b  0xa010e9d4
a010eb80:  80 a6 20 01  cmp  %i0, 1
a010eb84:  bb 2e 20 02  sll  %i0, 2, %i5
a010eb88:  f8 06 c0 1d  ld  [ %i3 + %i5 ], %i4
a010eb8c:  f2 27 20 24  st  %i1, [ %i4 + 0x24 ]
a010eb90:  10 bf ff 85  b  0xa010e9a4
a010eb94:  80 a6 20 01  cmp  %i0, 1
a010eb98:  b9 2e 20 02  sll  %i0, 2, %i4
a010eb9c:  f4 07 40 1c  ld  [ %i5 + %i4 ], %i2
a010eba0:  f6 26 a0 2c  st  %i3, [ %i2 + 0x2c ]
a010eba4:  30 80 00 09  b,a   0xa010ebc8
a010eba8:  bb 2e 20 02  sll  %i0, 2, %i5
a010ebac:  f8 06 80 1d  ld  [ %i2 + %i5 ], %i4
a010ebb0:  f6 27 20 2c  st  %i3, [ %i4 + 0x2c ]
a010ebb4:  10 bf ff d7  b  0xa010eb10
a010ebb8:  80 a6 20 01  cmp  %i0, 1
a010ebbc:  37 2a 00 b6  sethi  %hi(0xa802d800), %i3
a010ebc0:  10 bf ff 53  b  0xa010e90c
a010ebc4:  82 16 e0 04  or  %i3, 4, %g1	! 0xa802d804
a010ebc8:  81 c7 e0 08  ret
a010ebcc:  81 e8 00 00  restore
