# leon2m FUN_a012e928 0xa012e928-0xa012eb4c (496 bytes)
a012e928:  9d e3 bf 90  save  %sp, -112, %sp
a012e92c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012e930:  82 06 3f f0  add  %i0, -16, %g1
a012e934:  80 a0 60 06  cmp  %g1, 6
a012e938:  38 80 00 09  bgu,a   0xa012e95c
a012e93c:  82 10 20 01  mov  1, %g1
a012e940:  11 00 03 33  sethi  %hi(0xccc00), %o0
a012e944:  83 28 60 02  sll  %g1, 2, %g1
a012e948:  9a 12 22 bc  or  %o0, 0x2bc, %o5
a012e94c:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a012e950:  81 c3 00 00  jmp  %o4
a012e954:  01 00 00 00  nop
a012e958:  82 10 20 01  mov  1, %g1	! 0x1
a012e95c:  b4 0e a0 ff  and  %i2, 0xff, %i2
a012e960:  80 8e a0 01  btst  1, %i2
a012e964:  02 80 00 16  be  0xa012e9bc
a012e968:  a0 10 00 01  mov  %g1, %l0
a012e96c:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a012e970:  9e 12 e1 a0  or  %o3, 0x1a0, %o7	! 0xa802e1a0
a012e974:  d2 03 e0 34  ld  [ %o7 + 0x34 ], %o1
a012e978:  d4 0b e0 37  ldub  [ %o7 + 0x37 ], %o2
a012e97c:  99 32 60 08  srl  %o1, 8, %o4
a012e980:  80 a2 a0 01  cmp  %o2, 1
a012e984:  08 80 00 03  bleu  0xa012e990
a012e988:  92 10 21 20  mov  0x120, %o1
a012e98c:  92 10 22 40  mov  0x240, %o1
a012e990:  90 0a 63 60  and  %o1, 0x360, %o0
a012e994:  9a 02 20 30  add  %o0, 0x30, %o5
a012e998:  82 03 00 0d  add  %o4, %o5, %g1
a012e99c:  98 12 e1 a0  or  %o3, 0x1a0, %o4
a012e9a0:  b1 28 60 10  sll  %g1, 0x10, %i0
a012e9a4:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a012e9a8:  d0 0b 20 34  ldub  [ %o4 + 0x34 ], %o0
a012e9ac:  93 36 20 10  srl  %i0, 0x10, %o1
a012e9b0:  96 12 e3 40  or  %o3, 0x340, %o3
a012e9b4:  40 00 46 6b  call  0xa0140360
a012e9b8:  94 10 20 36  mov  0x36, %o2
a012e9bc:  94 0c 20 ff  and  %l0, 0xff, %o2
a012e9c0:  80 8a a0 07  btst  7, %o2
a012e9c4:  12 80 00 43  bne  0xa012ead0
a012e9c8:  9a 10 20 00  clr  %o5
a012e9cc:  9a 10 3f ff  mov  -1, %o5
a012e9d0:  82 0b 60 ff  and  %o5, 0xff, %g1
a012e9d4:  80 a0 60 ff  cmp  %g1, 0xff
a012e9d8:  02 80 00 12  be  0xa012ea20
a012e9dc:  80 8e a0 04  btst  4, %i2
a012e9e0:  99 28 60 03  sll  %g1, 3, %o4
a012e9e4:  b0 03 00 01  add  %o4, %g1, %i0
a012e9e8:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a012e9ec:  94 12 e3 40  or  %o3, 0x340, %o2	! 0xa802cb40
a012e9f0:  92 06 00 18  add  %i0, %i0, %o1
a012e9f4:  9a 02 40 0a  add  %o1, %o2, %o5
a012e9f8:  96 10 20 00  clr  %o3
a012e9fc:  98 10 20 00  clr  %o4
a012ea00:  c2 0b 00 19  ldub  [ %o4 + %i1 ], %g1
a012ea04:  c2 2b 40 0c  stb  %g1, [ %o5 + %o4 ]
a012ea08:  96 02 e0 01  inc  %o3
a012ea0c:  98 0a e0 ff  and  %o3, 0xff, %o4
a012ea10:  80 a3 20 11  cmp  %o4, 0x11
a012ea14:  28 bf ff fc  bleu,a   0xa012ea04
a012ea18:  c2 0b 00 19  ldub  [ %o4 + %i1 ], %g1
a012ea1c:  80 8e a0 04  btst  4, %i2
a012ea20:  02 80 00 49  be  0xa012eb44
a012ea24:  35 2a 00 b8  sethi  %hi(0xa802e000), %i2
a012ea28:  a0 16 a1 a0  or  %i2, 0x1a0, %l0	! 0xa802e1a0
a012ea2c:  d0 0c 20 37  ldub  [ %l0 + 0x37 ], %o0
a012ea30:  f2 04 20 34  ld  [ %l0 + 0x34 ], %i1
a012ea34:  9a 10 20 79  mov  0x79, %o5
a012ea38:  da 2f bf f7  stb  %o5, [ %fp + -9 ]
a012ea3c:  80 a2 20 01  cmp  %o0, 1
a012ea40:  97 36 60 08  srl  %i1, 8, %o3
a012ea44:  08 80 00 03  bleu  0xa012ea50
a012ea48:  92 10 21 20  mov  0x120, %o1
a012ea4c:  92 10 22 40  mov  0x240, %o1
a012ea50:  b2 0a 63 60  and  %o1, 0x360, %i1
a012ea54:  82 06 60 30  add  %i1, 0x30, %g1
a012ea58:  98 02 c0 01  add  %o3, %g1, %o4
a012ea5c:  97 2b 20 10  sll  %o4, 0x10, %o3
a012ea60:  93 32 e0 10  srl  %o3, 0x10, %o1
a012ea64:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a012ea68:  b0 16 a1 a0  or  %i2, 0x1a0, %i0
a012ea6c:  96 12 a3 40  or  %o2, 0x340, %o3
a012ea70:  d0 0e 20 34  ldub  [ %i0 + 0x34 ], %o0
a012ea74:  94 10 20 36  mov  0x36, %o2
a012ea78:  40 00 48 ff  call  0xa0140e74
a012ea7c:  98 10 20 01  mov  1, %o4
a012ea80:  d2 0e 20 37  ldub  [ %i0 + 0x37 ], %o1
a012ea84:  de 06 20 34  ld  [ %i0 + 0x34 ], %o7
a012ea88:  80 a2 60 01  cmp  %o1, 1
a012ea8c:  9b 33 e0 08  srl  %o7, 8, %o5
a012ea90:  08 80 00 03  bleu  0xa012ea9c
a012ea94:  92 10 21 20  mov  0x120, %o1
a012ea98:  92 10 22 40  mov  0x240, %o1
a012ea9c:  92 0a 63 60  and  %o1, 0x360, %o1
a012eaa0:  9e 03 40 09  add  %o5, %o1, %o7
a012eaa4:  91 2b e0 10  sll  %o7, 0x10, %o0
a012eaa8:  a0 16 a1 a0  or  %i2, 0x1a0, %l0
a012eaac:  93 32 20 10  srl  %o0, 0x10, %o1
a012eab0:  d0 0c 20 34  ldub  [ %l0 + 0x34 ], %o0
a012eab4:  94 10 20 01  mov  1, %o2
a012eab8:  96 07 bf f7  add  %fp, -9, %o3
a012eabc:  40 00 48 ee  call  0xa0140e74
a012eac0:  98 10 20 00  clr  %o4
a012eac4:  40 00 46 c3  call  0xa01405d0
a012eac8:  d0 0c 20 34  ldub  [ %l0 + 0x34 ], %o0
a012eacc:  30 80 00 1e  b,a   0xa012eb44
a012ead0:  80 a2 a0 01  cmp  %o2, 1
a012ead4:  02 bf ff bf  be  0xa012e9d0
a012ead8:  96 10 20 00  clr  %o3
a012eadc:  98 10 20 00  clr  %o4
a012eae0:  92 10 20 07  mov  7, %o1
a012eae4:  a1 3a 40 0c  sra  %o1, %o4, %l0
a012eae8:  80 8c 20 01  btst  1, %l0
a012eaec:  32 80 00 02  bne,a   0xa012eaf4
a012eaf0:  9a 03 60 01  inc  %o5
a012eaf4:  96 02 e0 01  inc  %o3
a012eaf8:  98 0a e0 ff  and  %o3, 0xff, %o4
a012eafc:  9f 3a 80 0c  sra  %o2, %o4, %o7
a012eb00:  80 a3 e0 01  cmp  %o7, 1
a012eb04:  12 bf ff f9  bne  0xa012eae8
a012eb08:  a1 3a 40 0c  sra  %o1, %o4, %l0
a012eb0c:  10 bf ff b2  b  0xa012e9d4
a012eb10:  82 0b 60 ff  and  %o5, 0xff, %g1
a012eb14:  10 bf ff 92  b  0xa012e95c
a012eb18:  82 10 20 10  mov  0x10, %g1
a012eb1c:  10 bf ff 90  b  0xa012e95c
a012eb20:  82 10 20 20  mov  0x20, %g1
a012eb24:  10 bf ff 8e  b  0xa012e95c
a012eb28:  82 10 20 40  mov  0x40, %g1
a012eb2c:  10 bf ff 8c  b  0xa012e95c
a012eb30:  82 10 3f 80  mov  -128, %g1
a012eb34:  10 bf ff 8a  b  0xa012e95c
a012eb38:  82 10 20 02  mov  2, %g1
a012eb3c:  10 bf ff 88  b  0xa012e95c
a012eb40:  82 10 20 04  mov  4, %g1
a012eb44:  81 c7 e0 08  ret
a012eb48:  81 e8 00 00  restore
