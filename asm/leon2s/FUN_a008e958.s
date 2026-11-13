# leon2s FUN_a008e958 0xa008e958-0xa008ecb8 (864 bytes)
a008e958:  9d e3 bf 98  save  %sp, -104, %sp
a008e95c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008e960:  80 a6 20 00  cmp  %i0, 0
a008e964:  12 80 00 1c  bne  0xa008e9d4
a008e968:  80 a6 20 01  cmp  %i0, 1
a008e96c:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a008e970:  9a 13 63 54  or  %o5, 0x354, %o5	! 0xcf014754
a008e974:  c2 03 40 00  ld  [ %o5 ], %g1
a008e978:  82 10 60 03  or  %g1, 3, %g1
a008e97c:  c2 23 40 00  st  %g1, [ %o5 ]
a008e980:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008e984:  98 10 60 40  or  %g1, 0x40, %o4	! 0xcf03c840
a008e988:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008e98c:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xffff
a008e990:  9a 10 3f ff  mov  -1, %o5
a008e994:  96 10 20 02  mov  2, %o3
a008e998:  c2 03 00 00  ld  [ %o4 ], %g1
a008e99c:  80 a0 60 01  cmp  %g1, 1
a008e9a0:  32 80 00 02  bne,a   0xa008e9a8
a008e9a4:  d6 23 00 00  st  %o3, [ %o4 ]
a008e9a8:  c2 03 00 00  ld  [ %o4 ], %g1
a008e9ac:  80 a0 60 02  cmp  %g1, 2
a008e9b0:  02 80 00 40  be  0xa008eab0
a008e9b4:  9a 03 7f ff  add  %o5, -1, %o5
a008e9b8:  83 2b 60 10  sll  %o5, 0x10, %g1
a008e9bc:  83 30 60 10  srl  %g1, 0x10, %g1
a008e9c0:  80 a0 40 0a  cmp  %g1, %o2
a008e9c4:  12 bf ff f5  bne  0xa008e998
a008e9c8:  82 10 20 02  mov  2, %g1
a008e9cc:  10 80 00 3b  b  0xa008eab8
a008e9d0:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a008e9d4:  12 80 00 20  bne  0xa008ea54
a008e9d8:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a008e9dc:  9a 13 63 54  or  %o5, 0x354, %o5	! 0xcf014754
a008e9e0:  c2 03 40 00  ld  [ %o5 ], %g1
a008e9e4:  82 10 60 0c  or  %g1, 0xc, %g1
a008e9e8:  c2 23 40 00  st  %g1, [ %o5 ]
a008e9ec:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008e9f0:  98 10 60 40  or  %g1, 0x40, %o4	! 0xcf03c840
a008e9f4:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008e9f8:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xffff
a008e9fc:  9a 10 3f ff  mov  -1, %o5
a008ea00:  96 10 20 02  mov  2, %o3
a008ea04:  c2 03 00 00  ld  [ %o4 ], %g1
a008ea08:  80 a0 60 01  cmp  %g1, 1
a008ea0c:  32 80 00 02  bne,a   0xa008ea14
a008ea10:  d6 23 00 00  st  %o3, [ %o4 ]
a008ea14:  c2 03 00 00  ld  [ %o4 ], %g1
a008ea18:  80 a0 60 02  cmp  %g1, 2
a008ea1c:  02 80 00 08  be  0xa008ea3c
a008ea20:  82 10 20 02  mov  2, %g1
a008ea24:  9a 03 7f ff  add  %o5, -1, %o5
a008ea28:  83 2b 60 10  sll  %o5, 0x10, %g1
a008ea2c:  83 30 60 10  srl  %g1, 0x10, %g1
a008ea30:  80 a0 40 0a  cmp  %g1, %o2
a008ea34:  12 bf ff f4  bne  0xa008ea04
a008ea38:  82 10 20 02  mov  2, %g1
a008ea3c:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a008ea40:  c2 23 00 00  st  %g1, [ %o4 ]
a008ea44:  9a 13 63 7c  or  %o5, 0x37c, %o5
a008ea48:  c2 03 40 00  ld  [ %o5 ], %g1
a008ea4c:  10 80 00 1f  b  0xa008eac8
a008ea50:  82 08 7f bf  and  %g1, -65, %g1
a008ea54:  9a 13 63 54  or  %o5, 0x354, %o5
a008ea58:  c2 03 40 00  ld  [ %o5 ], %g1
a008ea5c:  82 10 60 03  or  %g1, 3, %g1
a008ea60:  c2 23 40 00  st  %g1, [ %o5 ]
a008ea64:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008ea68:  98 10 60 40  or  %g1, 0x40, %o4	! 0xcf03c840
a008ea6c:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008ea70:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xffff
a008ea74:  9a 10 3f ff  mov  -1, %o5
a008ea78:  96 10 20 02  mov  2, %o3
a008ea7c:  c2 03 00 00  ld  [ %o4 ], %g1
a008ea80:  80 a0 60 01  cmp  %g1, 1
a008ea84:  32 80 00 02  bne,a   0xa008ea8c
a008ea88:  d6 23 00 00  st  %o3, [ %o4 ]
a008ea8c:  c2 03 00 00  ld  [ %o4 ], %g1
a008ea90:  80 a0 60 02  cmp  %g1, 2
a008ea94:  02 80 00 07  be  0xa008eab0
a008ea98:  9a 03 7f ff  add  %o5, -1, %o5
a008ea9c:  83 2b 60 10  sll  %o5, 0x10, %g1
a008eaa0:  83 30 60 10  srl  %g1, 0x10, %g1
a008eaa4:  80 a0 40 0a  cmp  %g1, %o2
a008eaa8:  12 bf ff f5  bne  0xa008ea7c
a008eaac:  01 00 00 00  nop
a008eab0:  82 10 20 02  mov  2, %g1	! 0x2
a008eab4:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a008eab8:  c2 23 00 00  st  %g1, [ %o4 ]
a008eabc:  9a 13 63 7c  or  %o5, 0x37c, %o5
a008eac0:  c2 03 40 00  ld  [ %o5 ], %g1
a008eac4:  82 08 7f df  and  %g1, -33, %g1
a008eac8:  c2 23 40 00  st  %g1, [ %o5 ]
a008eacc:  82 0e 60 ff  and  %i1, 0xff, %g1
a008ead0:  82 00 7f ff  add  %g1, -1, %g1
a008ead4:  c0 23 00 00  clr  [ %o4 ]
a008ead8:  80 a0 60 05  cmp  %g1, 5
a008eadc:  18 80 00 75  bgu  0xa008ecb0
a008eae0:  1b 28 02 3a  sethi  %hi(0xa008e800), %o5
a008eae4:  83 28 60 02  sll  %g1, 2, %g1
a008eae8:  9a 13 61 40  or  %o5, 0x140, %o5
a008eaec:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a008eaf0:  81 c0 40 00  jmp  %g1
a008eaf4:  01 00 00 00  nop
a008eaf8:  11 28 01 a3  sethi  %hi(0xa0068c00), %o0
a008eafc:  7f ff 92 72  call  0xa00734c4
a008eb00:  90 12 21 70  or  %o0, 0x170, %o0	! 0xa0068d70
a008eb04:  80 a6 20 00  cmp  %i0, 0
a008eb08:  12 80 00 07  bne  0xa008eb24
a008eb0c:  80 a6 20 01  cmp  %i0, 1
a008eb10:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a008eb14:  9a 13 63 48  or  %o5, 0x348, %o5	! 0xcf014748
a008eb18:  c2 03 40 00  ld  [ %o5 ], %g1
a008eb1c:  10 80 00 07  b  0xa008eb38
a008eb20:  82 08 60 f0  and  %g1, 0xf0, %g1
a008eb24:  12 80 00 63  bne  0xa008ecb0
a008eb28:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a008eb2c:  9a 13 63 48  or  %o5, 0x348, %o5	! 0xcf014748
a008eb30:  c2 03 40 00  ld  [ %o5 ], %g1
a008eb34:  82 08 60 0f  and  %g1, 0xf, %g1
a008eb38:  c2 23 40 00  st  %g1, [ %o5 ]
a008eb3c:  30 80 00 5d  b,a   0xa008ecb0
a008eb40:  11 28 01 a3  sethi  %hi(0xa0068c00), %o0
a008eb44:  7f ff 92 60  call  0xa00734c4
a008eb48:  90 12 21 88  or  %o0, 0x188, %o0	! 0xa0068d88
a008eb4c:  80 a6 20 00  cmp  %i0, 0
a008eb50:  12 80 00 0a  bne  0xa008eb78
a008eb54:  80 a6 20 01  cmp  %i0, 1
a008eb58:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a008eb5c:  82 10 63 48  or  %g1, 0x348, %g1	! 0xcf014748
a008eb60:  da 00 40 00  ld  [ %g1 ], %o5
a008eb64:  9a 0b 60 f0  and  %o5, 0xf0, %o5
a008eb68:  da 20 40 00  st  %o5, [ %g1 ]
a008eb6c:  da 00 40 00  ld  [ %g1 ], %o5
a008eb70:  10 80 00 4f  b  0xa008ecac
a008eb74:  9a 13 60 01  or  %o5, 1, %o5
a008eb78:  12 80 00 4e  bne  0xa008ecb0
a008eb7c:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a008eb80:  82 10 63 48  or  %g1, 0x348, %g1	! 0xcf014748
a008eb84:  da 00 40 00  ld  [ %g1 ], %o5
a008eb88:  9a 0b 60 0f  and  %o5, 0xf, %o5
a008eb8c:  da 20 40 00  st  %o5, [ %g1 ]
a008eb90:  da 00 40 00  ld  [ %g1 ], %o5
a008eb94:  10 80 00 46  b  0xa008ecac
a008eb98:  9a 13 60 10  or  %o5, 0x10, %o5
a008eb9c:  11 28 01 a3  sethi  %hi(0xa0068c00), %o0
a008eba0:  7f ff 92 49  call  0xa00734c4
a008eba4:  90 12 21 a0  or  %o0, 0x1a0, %o0	! 0xa0068da0
a008eba8:  80 a6 20 00  cmp  %i0, 0
a008ebac:  12 80 00 0a  bne  0xa008ebd4
a008ebb0:  80 a6 20 01  cmp  %i0, 1
a008ebb4:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a008ebb8:  82 10 63 48  or  %g1, 0x348, %g1	! 0xcf014748
a008ebbc:  da 00 40 00  ld  [ %g1 ], %o5
a008ebc0:  9a 0b 60 f0  and  %o5, 0xf0, %o5
a008ebc4:  da 20 40 00  st  %o5, [ %g1 ]
a008ebc8:  da 00 40 00  ld  [ %g1 ], %o5
a008ebcc:  10 80 00 38  b  0xa008ecac
a008ebd0:  9a 13 60 02  or  %o5, 2, %o5
a008ebd4:  12 80 00 37  bne  0xa008ecb0
a008ebd8:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a008ebdc:  82 10 63 48  or  %g1, 0x348, %g1	! 0xcf014748
a008ebe0:  da 00 40 00  ld  [ %g1 ], %o5
a008ebe4:  9a 0b 60 0f  and  %o5, 0xf, %o5
a008ebe8:  da 20 40 00  st  %o5, [ %g1 ]
a008ebec:  da 00 40 00  ld  [ %g1 ], %o5
a008ebf0:  10 80 00 2f  b  0xa008ecac
a008ebf4:  9a 13 60 20  or  %o5, 0x20, %o5
a008ebf8:  11 28 01 a3  sethi  %hi(0xa0068c00), %o0
a008ebfc:  7f ff 92 32  call  0xa00734c4
a008ec00:  90 12 21 b8  or  %o0, 0x1b8, %o0	! 0xa0068db8
a008ec04:  80 a6 20 00  cmp  %i0, 0
a008ec08:  12 80 00 0a  bne  0xa008ec30
a008ec0c:  80 a6 20 01  cmp  %i0, 1
a008ec10:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a008ec14:  82 10 63 48  or  %g1, 0x348, %g1	! 0xcf014748
a008ec18:  da 00 40 00  ld  [ %g1 ], %o5
a008ec1c:  9a 0b 60 f0  and  %o5, 0xf0, %o5
a008ec20:  da 20 40 00  st  %o5, [ %g1 ]
a008ec24:  da 00 40 00  ld  [ %g1 ], %o5
a008ec28:  10 80 00 21  b  0xa008ecac
a008ec2c:  9a 13 60 03  or  %o5, 3, %o5
a008ec30:  12 80 00 20  bne  0xa008ecb0
a008ec34:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a008ec38:  82 10 63 48  or  %g1, 0x348, %g1	! 0xcf014748
a008ec3c:  da 00 40 00  ld  [ %g1 ], %o5
a008ec40:  9a 0b 60 0f  and  %o5, 0xf, %o5
a008ec44:  da 20 40 00  st  %o5, [ %g1 ]
a008ec48:  da 00 40 00  ld  [ %g1 ], %o5
a008ec4c:  10 80 00 18  b  0xa008ecac
a008ec50:  9a 13 60 30  or  %o5, 0x30, %o5
a008ec54:  11 28 01 a3  sethi  %hi(0xa0068c00), %o0
a008ec58:  7f ff 92 1b  call  0xa00734c4
a008ec5c:  90 12 21 d0  or  %o0, 0x1d0, %o0	! 0xa0068dd0
a008ec60:  80 a6 20 00  cmp  %i0, 0
a008ec64:  12 80 00 0a  bne  0xa008ec8c
a008ec68:  80 a6 20 01  cmp  %i0, 1
a008ec6c:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a008ec70:  82 10 63 48  or  %g1, 0x348, %g1	! 0xcf014748
a008ec74:  da 00 40 00  ld  [ %g1 ], %o5
a008ec78:  9a 0b 60 f0  and  %o5, 0xf0, %o5
a008ec7c:  da 20 40 00  st  %o5, [ %g1 ]
a008ec80:  da 00 40 00  ld  [ %g1 ], %o5
a008ec84:  10 80 00 0a  b  0xa008ecac
a008ec88:  9a 13 60 04  or  %o5, 4, %o5
a008ec8c:  12 80 00 09  bne  0xa008ecb0
a008ec90:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a008ec94:  82 10 63 48  or  %g1, 0x348, %g1	! 0xcf014748
a008ec98:  da 00 40 00  ld  [ %g1 ], %o5
a008ec9c:  9a 0b 60 0f  and  %o5, 0xf, %o5
a008eca0:  da 20 40 00  st  %o5, [ %g1 ]
a008eca4:  da 00 40 00  ld  [ %g1 ], %o5
a008eca8:  9a 13 60 40  or  %o5, 0x40, %o5
a008ecac:  da 20 40 00  st  %o5, [ %g1 ]
a008ecb0:  81 c7 e0 08  ret
a008ecb4:  81 e8 00 00  restore
