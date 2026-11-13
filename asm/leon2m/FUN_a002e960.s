# leon2m FUN_a002e960 0xa002e960-0xa002ed14 (948 bytes)
a002e960:  9d e3 bf 98  save  %sp, -104, %sp
a002e964:  9a 0f 20 ff  and  %i4, 0xff, %o5
a002e968:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a002e96c:  ba 03 40 0d  add  %o5, %o5, %i5
a002e970:  82 10 61 ca  or  %g1, 0x1ca, %g1
a002e974:  ac 10 00 19  mov  %i1, %l6
a002e978:  de 10 40 1d  lduh  [ %g1 + %i5 ], %o7
a002e97c:  33 2a 00 b2  sethi  %hi(0xa802c800), %i1
a002e980:  a6 10 00 18  mov  %i0, %l3
a002e984:  a8 10 00 1a  mov  %i2, %l4
a002e988:  82 16 61 c8  or  %i1, 0x1c8, %g1
a002e98c:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a002e990:  aa 10 00 1b  mov  %i3, %l5
a002e994:  35 2a 00 b2  sethi  %hi(0xa802c800), %i2
a002e998:  b6 16 21 c0  or  %i0, 0x1c0, %i3
a002e99c:  ba 16 a1 b8  or  %i2, 0x1b8, %i5
a002e9a0:  d8 08 40 0d  ldub  [ %g1 + %o5 ], %o4
a002e9a4:  a4 10 00 1c  mov  %i4, %l2
a002e9a8:  f0 0e c0 0d  ldub  [ %i3 + %o5 ], %i0
a002e9ac:  d6 0f 40 0d  ldub  [ %i5 + %o5 ], %o3
a002e9b0:  80 a3 60 01  cmp  %o5, 1
a002e9b4:  b2 10 20 00  clr  %i1
a002e9b8:  08 80 00 03  bleu  0xa002e9c4
a002e9bc:  82 10 00 1c  mov  %i4, %g1
a002e9c0:  82 10 20 00  clr  %g1
a002e9c4:  b4 08 60 ff  and  %g1, 0xff, %i2
a002e9c8:  82 06 80 1a  add  %i2, %i2, %g1
a002e9cc:  21 2a 00 9e  sethi  %hi(0xa8027800), %l0
a002e9d0:  b4 14 22 a8  or  %l0, 0x2a8, %i2	! 0xa8027aa8
a002e9d4:  fa 16 80 01  lduh  [ %i2 + %g1 ], %i5
a002e9d8:  b6 07 60 aa  add  %i5, 0xaa, %i3
a002e9dc:  83 2e e0 02  sll  %i3, 2, %g1
a002e9e0:  37 33 c0 00  sethi  %hi(0xcf000000), %i3
a002e9e4:  ba 10 40 1b  or  %g1, %i3, %i5
a002e9e8:  c2 07 40 00  ld  [ %i5 ], %g1
a002e9ec:  80 88 60 80  btst  0x80, %g1
a002e9f0:  12 80 00 44  bne  0xa002eb00
a002e9f4:  80 a3 60 01  cmp  %o5, 1
a002e9f8:  80 a3 60 00  cmp  %o5, 0
a002e9fc:  12 80 00 11  bne  0xa002ea40
a002ea00:  3b 2a 00 b2  sethi  %hi(0xa802c800), %i5
a002ea04:  35 2a 00 b2  sethi  %hi(0xa802c800), %i2
a002ea08:  c2 0e a1 b0  ldub  [ %i2 + 0x1b0 ], %g1	! 0xa802c9b0
a002ea0c:  b6 08 60 0c  and  %g1, 0xc, %i3
a002ea10:  83 3e e0 02  sra  %i3, 2, %g1
a002ea14:  80 a0 60 02  cmp  %g1, 2
a002ea18:  02 80 00 10  be  0xa002ea58
a002ea1c:  ba 5e 00 0f  smul  %i0, %o7, %i5
a002ea20:  80 a0 60 02  cmp  %g1, 2
a002ea24:  04 80 00 24  ble  0xa002eab4
a002ea28:  80 a0 60 01  cmp  %g1, 1
a002ea2c:  80 a0 60 03  cmp  %g1, 3
a002ea30:  12 80 00 53  bne  0xa002eb7c
a002ea34:  80 a3 60 02  cmp  %o5, 2
a002ea38:  10 80 00 41  b  0xa002eb3c
a002ea3c:  b8 10 00 14  mov  %l4, %i4
a002ea40:  f6 0f 61 b0  ldub  [ %i5 + 0x1b0 ], %i3
a002ea44:  b8 0e e0 30  and  %i3, 0x30, %i4
a002ea48:  83 3f 20 04  sra  %i4, 4, %g1
a002ea4c:  80 a0 60 02  cmp  %g1, 2
a002ea50:  12 bf ff f5  bne  0xa002ea24
a002ea54:  ba 5e 00 0f  smul  %i0, %o7, %i5
a002ea58:  a2 27 40 14  sub  %i5, %l4, %l1
a002ea5c:  b8 0e 60 ff  and  %i1, 0xff, %i4
a002ea60:  b1 2c 60 10  sll  %l1, 0x10, %i0
a002ea64:  b2 10 00 13  mov  %l3, %i1
a002ea68:  b5 36 20 10  srl  %i0, 0x10, %i2
a002ea6c:  b6 0f 20 0f  and  %i4, 0xf, %i3
a002ea70:  80 a6 c0 1a  cmp  %i3, %i2
a002ea74:  08 80 00 30  bleu  0xa002eb34
a002ea78:  a6 10 00 11  mov  %l1, %l3
a002ea7c:  b4 5a c0 0c  smul  %o3, %o4, %i2
a002ea80:  96 26 80 15  sub  %i2, %l5, %o3
a002ea84:  ba 27 40 19  sub  %i5, %i1, %i5
a002ea88:  b1 2a e0 10  sll  %o3, 0x10, %i0
a002ea8c:  b2 10 00 16  mov  %l6, %i1
a002ea90:  83 36 20 10  srl  %i0, 0x10, %g1
a002ea94:  80 a6 c0 01  cmp  %i3, %g1
a002ea98:  a8 27 40 1c  sub  %i5, %i4, %l4
a002ea9c:  18 80 00 03  bgu  0xa002eaa8
a002eaa0:  ac 10 00 0b  mov  %o3, %l6
a002eaa4:  ac 22 c0 1c  sub  %o3, %i4, %l6
a002eaa8:  82 26 80 19  sub  %i2, %i1, %g1
a002eaac:  10 80 00 33  b  0xa002eb78
a002eab0:  aa 20 40 1c  sub  %g1, %i4, %l5
a002eab4:  12 80 00 32  bne  0xa002eb7c
a002eab8:  80 a3 60 02  cmp  %o5, 2
a002eabc:  b4 5a c0 0c  smul  %o3, %o4, %i2
a002eac0:  96 26 80 15  sub  %i2, %l5, %o3
a002eac4:  b8 0e 60 ff  and  %i1, 0xff, %i4
a002eac8:  83 2a e0 10  sll  %o3, 0x10, %g1
a002eacc:  b6 0f 20 0f  and  %i4, 0xf, %i3
a002ead0:  b1 30 60 10  srl  %g1, 0x10, %i0
a002ead4:  b2 10 00 13  mov  %l3, %i1
a002ead8:  80 a6 c0 18  cmp  %i3, %i0
a002eadc:  b6 10 00 14  mov  %l4, %i3
a002eae0:  18 80 00 03  bgu  0xa002eaec
a002eae4:  a6 10 00 0b  mov  %o3, %l3
a002eae8:  a6 22 c0 1c  sub  %o3, %i4, %l3
a002eaec:  ba 26 80 16  sub  %i2, %l6, %i5
a002eaf0:  a8 27 40 1c  sub  %i5, %i4, %l4
a002eaf4:  ac 10 00 19  mov  %i1, %l6
a002eaf8:  10 80 00 20  b  0xa002eb78
a002eafc:  aa 10 00 1b  mov  %i3, %l5
a002eb00:  08 80 00 03  bleu  0xa002eb0c
a002eb04:  82 10 00 1c  mov  %i4, %g1
a002eb08:  82 10 20 00  clr  %g1
a002eb0c:  ba 08 60 ff  and  %g1, 0xff, %i5
a002eb10:  b2 07 40 1d  add  %i5, %i5, %i1
a002eb14:  f8 16 80 19  lduh  [ %i2 + %i1 ], %i4
a002eb18:  b4 07 20 ad  add  %i4, 0xad, %i2
a002eb1c:  83 2e a0 02  sll  %i2, 2, %g1
a002eb20:  ba 10 40 1b  or  %g1, %i3, %i5
a002eb24:  f2 07 40 00  ld  [ %i5 ], %i1
a002eb28:  b8 0e 60 07  and  %i1, 7, %i4
a002eb2c:  10 bf ff b3  b  0xa002e9f8
a002eb30:  b2 07 20 01  add  %i4, 1, %i1
a002eb34:  10 bf ff d2  b  0xa002ea7c
a002eb38:  a6 24 40 1c  sub  %l1, %i4, %l3
a002eb3c:  b6 5e 00 0f  smul  %i0, %o7, %i3
a002eb40:  a2 26 c0 1c  sub  %i3, %i4, %l1
a002eb44:  b8 0e 60 ff  and  %i1, 0xff, %i4
a002eb48:  b4 10 00 13  mov  %l3, %i2
a002eb4c:  83 2c 60 10  sll  %l1, 0x10, %g1
a002eb50:  a6 10 00 16  mov  %l6, %l3
a002eb54:  b3 30 60 10  srl  %g1, 0x10, %i1
a002eb58:  ba 0f 20 0f  and  %i4, 0xf, %i5
a002eb5c:  80 a7 40 19  cmp  %i5, %i1
a002eb60:  a8 10 00 15  mov  %l5, %l4
a002eb64:  18 80 00 03  bgu  0xa002eb70
a002eb68:  ac 10 00 11  mov  %l1, %l6
a002eb6c:  ac 24 40 1c  sub  %l1, %i4, %l6
a002eb70:  82 26 c0 1a  sub  %i3, %i2, %g1
a002eb74:  aa 20 40 1c  sub  %g1, %i4, %l5
a002eb78:  80 a3 60 02  cmp  %o5, 2
a002eb7c:  b8 60 20 00  subx  %g0, 0, %i4
a002eb80:  b0 10 00 1c  mov  %i4, %i0
a002eb84:  b6 10 00 1c  mov  %i4, %i3
a002eb88:  b4 10 00 1c  mov  %i4, %i2
a002eb8c:  b2 10 00 1c  mov  %i4, %i1
a002eb90:  ba 0f 00 12  and  %i4, %l2, %i5
a002eb94:  82 0f 60 ff  and  %i5, 0xff, %g1
a002eb98:  b8 0f 00 12  and  %i4, %l2, %i4
a002eb9c:  ba 0f 20 ff  and  %i4, 0xff, %i5
a002eba0:  a0 14 22 a8  or  %l0, 0x2a8, %l0
a002eba4:  82 00 40 01  add  %g1, %g1, %g1
a002eba8:  b8 0e c0 12  and  %i3, %l2, %i4
a002ebac:  f6 14 00 01  lduh  [ %l0 + %g1 ], %i3
a002ebb0:  ba 07 40 1d  add  %i5, %i5, %i5
a002ebb4:  82 0e 80 12  and  %i2, %l2, %g1
a002ebb8:  b8 0f 20 ff  and  %i4, 0xff, %i4
a002ebbc:  b4 08 60 ff  and  %g1, 0xff, %i2
a002ebc0:  de 14 00 1d  lduh  [ %l0 + %i5 ], %o7
a002ebc4:  b8 07 00 1c  add  %i4, %i4, %i4
a002ebc8:  82 0e 40 12  and  %i1, %l2, %g1
a002ebcc:  fa 14 00 1c  lduh  [ %l0 + %i4 ], %i5
a002ebd0:  b6 06 e0 03  add  %i3, 3, %i3
a002ebd4:  11 33 c0 00  sethi  %hi(0xcf000000), %o0
a002ebd8:  b8 06 80 1a  add  %i2, %i2, %i4
a002ebdc:  92 10 00 18  mov  %i0, %o1
a002ebe0:  b7 2e e0 02  sll  %i3, 2, %i3
a002ebe4:  96 08 60 ff  and  %g1, 0xff, %o3
a002ebe8:  94 0e 00 12  and  %i0, %l2, %o2
a002ebec:  b3 2d 20 10  sll  %l4, 0x10, %i1
a002ebf0:  b0 16 c0 08  or  %i3, %o0, %i0
a002ebf4:  da 14 00 1c  lduh  [ %l0 + %i4 ], %o5
a002ebf8:  99 2c e0 10  sll  %l3, 0x10, %o4
a002ebfc:  82 0c e0 ff  and  %l3, 0xff, %g1
a002ec00:  9e 03 e0 04  add  %o7, 4, %o7
a002ec04:  c2 26 00 00  st  %g1, [ %i0 ]
a002ec08:  96 02 c0 0b  add  %o3, %o3, %o3
a002ec0c:  b5 33 20 18  srl  %o4, 0x18, %i2
a002ec10:  b9 36 60 14  srl  %i1, 0x14, %i4
a002ec14:  a3 36 60 18  srl  %i1, 0x18, %l1
a002ec18:  b6 03 60 09  add  %o5, 9, %i3
a002ec1c:  9f 2b e0 02  sll  %o7, 2, %o7
a002ec20:  f2 14 00 0b  lduh  [ %l0 + %o3 ], %i1
a002ec24:  92 0a 40 12  and  %o1, %l2, %o1
a002ec28:  9e 13 c0 08  or  %o7, %o0, %o7
a002ec2c:  b8 0f 20 f0  and  %i4, 0xf0, %i4
a002ec30:  82 0d 20 ff  and  %l4, 0xff, %g1
a002ec34:  9b 2e e0 02  sll  %i3, 2, %o5
a002ec38:  ba 07 60 05  add  %i5, 5, %i5
a002ec3c:  94 0a a0 ff  and  %o2, 0xff, %o2
a002ec40:  b4 0e a0 0f  and  %i2, 0xf, %i2
a002ec44:  c2 23 c0 00  st  %g1, [ %o7 ]
a002ec48:  b0 10 00 09  mov  %o1, %i0
a002ec4c:  b4 16 80 1c  or  %i2, %i4, %i2
a002ec50:  b6 06 60 06  add  %i1, 6, %i3
a002ec54:  bb 2f 60 02  sll  %i5, 2, %i5
a002ec58:  99 33 20 1c  srl  %o4, 0x1c, %o4
a002ec5c:  94 02 80 0a  add  %o2, %o2, %o2
a002ec60:  ba 17 40 08  or  %i5, %o0, %i5
a002ec64:  c2 14 00 0a  lduh  [ %l0 + %o2 ], %g1
a002ec68:  b8 0e 20 ff  and  %i0, 0xff, %i4
a002ec6c:  b3 2e e0 02  sll  %i3, 2, %i1
a002ec70:  92 0a 60 ff  and  %o1, 0xff, %o1
a002ec74:  98 0b 20 03  and  %o4, 3, %o4
a002ec78:  a2 0c 60 30  and  %l1, 0x30, %l1
a002ec7c:  f4 27 40 00  st  %i2, [ %i5 ]
a002ec80:  b6 00 60 07  add  %g1, 7, %i3
a002ec84:  b0 07 00 1c  add  %i4, %i4, %i0
a002ec88:  92 02 40 09  add  %o1, %o1, %o1
a002ec8c:  98 13 00 11  or  %o4, %l1, %o4
a002ec90:  9a 13 40 08  or  %o5, %o0, %o5
a002ec94:  d8 23 40 00  st  %o4, [ %o5 ]
a002ec98:  b5 2d a0 10  sll  %l6, 0x10, %i2
a002ec9c:  97 2d 60 10  sll  %l5, 0x10, %o3
a002eca0:  f8 14 00 18  lduh  [ %l0 + %i0 ], %i4
a002eca4:  b2 16 40 08  or  %i1, %o0, %i1
a002eca8:  82 0d a0 ff  and  %l6, 0xff, %g1
a002ecac:  fa 14 00 09  lduh  [ %l0 + %o1 ], %i5
a002ecb0:  c2 26 40 00  st  %g1, [ %i1 ]
a002ecb4:  ba 07 60 08  add  %i5, 8, %i5
a002ecb8:  9f 36 a0 18  srl  %i2, 0x18, %o7
a002ecbc:  b1 32 e0 14  srl  %o3, 0x14, %i0
a002ecc0:  b0 0e 20 f0  and  %i0, 0xf0, %i0
a002ecc4:  b3 2f 60 02  sll  %i5, 2, %i1
a002ecc8:  b7 2e e0 02  sll  %i3, 2, %i3
a002eccc:  9e 0b e0 0f  and  %o7, 0xf, %o7
a002ecd0:  b6 16 c0 08  or  %i3, %o0, %i3
a002ecd4:  b5 36 a0 1c  srl  %i2, 0x1c, %i2
a002ecd8:  9e 13 c0 18  or  %o7, %i0, %o7
a002ecdc:  ba 16 40 08  or  %i1, %o0, %i5
a002ece0:  97 32 e0 18  srl  %o3, 0x18, %o3
a002ece4:  b8 07 20 0a  add  %i4, 0xa, %i4
a002ece8:  82 0d 60 ff  and  %l5, 0xff, %g1
a002ecec:  c2 26 c0 00  st  %g1, [ %i3 ]
a002ecf0:  b0 0e a0 03  and  %i2, 3, %i0
a002ecf4:  96 0a e0 30  and  %o3, 0x30, %o3
a002ecf8:  b3 2f 20 02  sll  %i4, 2, %i1
a002ecfc:  de 27 40 00  st  %o7, [ %i5 ]
a002ed00:  b6 16 40 08  or  %i1, %o0, %i3
a002ed04:  b4 16 00 0b  or  %i0, %o3, %i2
a002ed08:  f4 26 c0 00  st  %i2, [ %i3 ]
a002ed0c:  81 c7 e0 08  ret
a002ed10:  81 e8 00 00  restore
