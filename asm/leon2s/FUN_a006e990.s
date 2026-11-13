# leon2s FUN_a006e990 0xa006e990-0xa006ed40 (944 bytes)
a006e990:  9d e3 bf 78  save  %sp, -136, %sp
a006e994:  c2 16 20 02  lduh  [ %i0 + 2 ], %g1
a006e998:  da 16 20 04  lduh  [ %i0 + 4 ], %o5
a006e99c:  d8 16 20 06  lduh  [ %i0 + 6 ], %o4
a006e9a0:  d6 16 20 08  lduh  [ %i0 + 8 ], %o3
a006e9a4:  d4 16 20 0a  lduh  [ %i0 + 0xa ], %o2
a006e9a8:  d2 0e 20 0d  ldub  [ %i0 + 0xd ], %o1
a006e9ac:  b2 0e 60 ff  and  %i1, 0xff, %i1
a006e9b0:  c2 37 bf e4  sth  %g1, [ %fp + -28 ]
a006e9b4:  da 37 bf e6  sth  %o5, [ %fp + -26 ]
a006e9b8:  d8 37 bf e0  sth  %o4, [ %fp + -32 ]
a006e9bc:  d6 37 bf e2  sth  %o3, [ %fp + -30 ]
a006e9c0:  d4 37 bf e8  sth  %o2, [ %fp + -24 ]
a006e9c4:  d2 2f bf ea  stb  %o1, [ %fp + -22 ]
a006e9c8:  c0 37 bf f0  clrh  [ %fp + -16 ]
a006e9cc:  40 00 f8 3d  call  0xa00acac0
a006e9d0:  90 10 00 19  mov  %i1, %o0
a006e9d4:  d0 37 bf de  sth  %o0, [ %fp + -34 ]
a006e9d8:  40 00 f8 4a  call  0xa00acb00
a006e9dc:  90 10 00 19  mov  %i1, %o0
a006e9e0:  b4 10 00 08  mov  %o0, %i2
a006e9e4:  40 00 f8 57  call  0xa00acb40
a006e9e8:  90 10 00 19  mov  %i1, %o0
a006e9ec:  b6 10 00 08  mov  %o0, %i3
a006e9f0:  40 00 f8 5c  call  0xa00acb60
a006e9f4:  90 10 00 19  mov  %i1, %o0
a006e9f8:  b8 10 00 08  mov  %o0, %i4
a006e9fc:  40 00 f8 66  call  0xa00acb94
a006ea00:  90 10 00 19  mov  %i1, %o0
a006ea04:  ae 10 00 08  mov  %o0, %l7
a006ea08:  40 00 f8 93  call  0xa00acc54
a006ea0c:  90 10 00 19  mov  %i1, %o0
a006ea10:  ac 10 00 08  mov  %o0, %l6
a006ea14:  92 10 00 19  mov  %i1, %o1
a006ea18:  7f ff ff 82  call  0xa006e820
a006ea1c:  90 10 00 18  mov  %i0, %o0
a006ea20:  d2 16 20 12  lduh  [ %i0 + 0x12 ], %o1
a006ea24:  80 8a 60 10  btst  0x10, %o1
a006ea28:  a8 10 20 00  clr  %l4
a006ea2c:  02 80 00 0b  be  0xa006ea58
a006ea30:  ba 07 bf e0  add  %fp, -32, %i5
a006ea34:  93 32 60 04  srl  %o1, 4, %o1
a006ea38:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006ea3c:  90 12 23 b8  or  %o0, 0x3b8, %o0	! 0xa0065fb8
a006ea40:  40 00 11 81  call  0xa0073044
a006ea44:  92 0a 60 01  and  %o1, 1, %o1
a006ea48:  c2 16 20 12  lduh  [ %i0 + 0x12 ], %g1
a006ea4c:  82 08 7f ef  and  %g1, -17, %g1
a006ea50:  10 80 00 40  b  0xa006eb50
a006ea54:  c2 36 20 12  sth  %g1, [ %i0 + 0x12 ]
a006ea58:  da 17 bf de  lduh  [ %fp + -34 ], %o5
a006ea5c:  83 2b 60 10  sll  %o5, 0x10, %g1
a006ea60:  a1 30 60 10  srl  %g1, 0x10, %l0
a006ea64:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006ea68:  90 12 23 d0  or  %o0, 0x3d0, %o0	! 0xa0065fd0
a006ea6c:  80 a4 20 09  cmp  %l0, 9
a006ea70:  08 80 00 0a  bleu  0xa006ea98
a006ea74:  92 10 00 10  mov  %l0, %o1
a006ea78:  83 2e a0 10  sll  %i2, 0x10, %g1
a006ea7c:  a5 30 60 10  srl  %g1, 0x10, %l2
a006ea80:  80 a4 a0 09  cmp  %l2, 9
a006ea84:  18 80 00 08  bgu  0xa006eaa4
a006ea88:  83 2e e0 10  sll  %i3, 0x10, %g1
a006ea8c:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006ea90:  90 12 23 e8  or  %o0, 0x3e8, %o0	! 0xa0065fe8
a006ea94:  92 10 00 12  mov  %l2, %o1
a006ea98:  40 00 11 6b  call  0xa0073044
a006ea9c:  b0 10 20 01  mov  1, %i0
a006eaa0:  30 80 00 a6  b,a   0xa006ed38
a006eaa4:  a7 30 60 10  srl  %g1, 0x10, %l3
a006eaa8:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006eaac:  90 12 20 00  mov  %o0, %o0	! 0xa0066000
a006eab0:  80 a4 e0 09  cmp  %l3, 9
a006eab4:  08 bf ff f9  bleu  0xa006ea98
a006eab8:  92 10 00 13  mov  %l3, %o1
a006eabc:  83 2f 20 10  sll  %i4, 0x10, %g1
a006eac0:  93 30 60 10  srl  %g1, 0x10, %o1
a006eac4:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006eac8:  80 a2 60 09  cmp  %o1, 9
a006eacc:  08 bf ff f3  bleu  0xa006ea98
a006ead0:  90 12 20 18  or  %o0, 0x18, %o0
a006ead4:  82 05 bf ec  add  %l6, -20, %g1
a006ead8:  83 28 60 10  sll  %g1, 0x10, %g1
a006eadc:  83 30 60 10  srl  %g1, 0x10, %g1
a006eae0:  80 a0 6d 34  cmp  %g1, 0xd34
a006eae4:  08 80 00 0b  bleu  0xa006eb10
a006eae8:  82 07 bf f8  add  %fp, -8, %g1
a006eaec:  93 2d a0 10  sll  %l6, 0x10, %o1
a006eaf0:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006eaf4:  93 32 60 10  srl  %o1, 0x10, %o1
a006eaf8:  94 10 20 14  mov  0x14, %o2
a006eafc:  96 10 2d 48  mov  0xd48, %o3
a006eb00:  40 00 11 51  call  0xa0073044
a006eb04:  90 12 20 30  or  %o0, 0x30, %o0
a006eb08:  10 80 00 8c  b  0xa006ed38
a006eb0c:  b0 10 20 01  mov  1, %i0
a006eb10:  a2 00 40 19  add  %g1, %i1, %l1
a006eb14:  40 01 01 b5  call  0xa00af1e8
a006eb18:  90 10 00 19  mov  %i1, %o0
a006eb1c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006eb20:  aa 10 60 98  or  %g1, 0x98, %l5	! 0xa8078898
a006eb24:  96 0a 20 ff  and  %o0, 0xff, %o3
a006eb28:  d4 0d 40 19  ldub  [ %l5 + %i1 ], %o2
a006eb2c:  80 a2 c0 0a  cmp  %o3, %o2
a006eb30:  02 80 00 0a  be  0xa006eb58
a006eb34:  d0 2c 7f f8  stb  %o0, [ %l1 + -8 ]
a006eb38:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006eb3c:  90 12 20 48  or  %o0, 0x48, %o0	! 0xa0066048
a006eb40:  40 00 11 41  call  0xa0073044
a006eb44:  92 10 00 19  mov  %i1, %o1
a006eb48:  c2 0c 7f f8  ldub  [ %l1 + -8 ], %g1
a006eb4c:  c2 2d 40 19  stb  %g1, [ %l5 + %i1 ]
a006eb50:  10 80 00 7a  b  0xa006ed38
a006eb54:  b0 10 20 01  mov  1, %i0
a006eb58:  94 0d e0 ff  and  %l7, 0xff, %o2
a006eb5c:  d2 0e 20 12  ldub  [ %i0 + 0x12 ], %o1
a006eb60:  80 a2 80 09  cmp  %o2, %o1
a006eb64:  22 80 00 08  be,a   0xa006eb84
a006eb68:  d4 17 bf e0  lduh  [ %fp + -32 ], %o2
a006eb6c:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006eb70:  40 00 11 35  call  0xa0073044
a006eb74:  90 12 20 78  or  %o0, 0x78, %o0	! 0xa0066078
a006eb78:  ee 2e 20 12  stb  %l7, [ %i0 + 0x12 ]
a006eb7c:  a8 10 20 01  mov  1, %l4
a006eb80:  d4 17 bf e0  lduh  [ %fp + -32 ], %o2
a006eb84:  82 24 00 0a  sub  %l0, %o2, %g1
a006eb88:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a006eb8c:  82 1b 40 01  xor  %o5, %g1, %g1
a006eb90:  82 20 40 0d  sub  %g1, %o5, %g1
a006eb94:  80 a0 60 02  cmp  %g1, 2
a006eb98:  24 80 00 08  ble,a   0xa006ebb8
a006eb9c:  d4 17 bf e2  lduh  [ %fp + -30 ], %o2
a006eba0:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006eba4:  90 12 20 a0  or  %o0, 0xa0, %o0	! 0xa00660a0
a006eba8:  40 00 11 27  call  0xa0073044
a006ebac:  92 10 00 10  mov  %l0, %o1
a006ebb0:  a8 10 20 01  mov  1, %l4
a006ebb4:  d4 17 bf e2  lduh  [ %fp + -30 ], %o2
a006ebb8:  82 24 80 0a  sub  %l2, %o2, %g1
a006ebbc:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a006ebc0:  82 1b 40 01  xor  %o5, %g1, %g1
a006ebc4:  82 20 40 0d  sub  %g1, %o5, %g1
a006ebc8:  80 a0 60 01  cmp  %g1, 1
a006ebcc:  24 80 00 08  ble,a   0xa006ebec
a006ebd0:  d4 17 60 04  lduh  [ %i5 + 4 ], %o2
a006ebd4:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006ebd8:  90 12 20 b8  or  %o0, 0xb8, %o0	! 0xa00660b8
a006ebdc:  40 00 11 1a  call  0xa0073044
a006ebe0:  92 10 00 12  mov  %l2, %o1
a006ebe4:  a8 10 20 01  mov  1, %l4
a006ebe8:  d4 17 60 04  lduh  [ %i5 + 4 ], %o2
a006ebec:  82 24 c0 0a  sub  %l3, %o2, %g1
a006ebf0:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a006ebf4:  82 1b 40 01  xor  %o5, %g1, %g1
a006ebf8:  82 20 40 0d  sub  %g1, %o5, %g1
a006ebfc:  80 a0 60 04  cmp  %g1, 4
a006ec00:  24 80 00 08  ble,a   0xa006ec20
a006ec04:  da 17 60 08  lduh  [ %i5 + 8 ], %o5
a006ec08:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006ec0c:  90 12 20 d0  or  %o0, 0xd0, %o0	! 0xa00660d0
a006ec10:  40 00 11 0d  call  0xa0073044
a006ec14:  92 10 00 13  mov  %l3, %o1
a006ec18:  a8 10 20 01  mov  1, %l4
a006ec1c:  da 17 60 08  lduh  [ %i5 + 8 ], %o5
a006ec20:  80 a3 60 32  cmp  %o5, 0x32
a006ec24:  d4 0f 60 0a  ldub  [ %i5 + 0xa ], %o2
a006ec28:  d2 0e 20 0d  ldub  [ %i0 + 0xd ], %o1
a006ec2c:  08 80 00 09  bleu  0xa006ec50
a006ec30:  83 2d a0 10  sll  %l6, 0x10, %g1
a006ec34:  83 30 60 10  srl  %g1, 0x10, %g1
a006ec38:  82 20 40 0d  sub  %g1, %o5, %g1
a006ec3c:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a006ec40:  82 1b 40 01  xor  %o5, %g1, %g1
a006ec44:  82 20 40 0d  sub  %g1, %o5, %g1
a006ec48:  10 80 00 08  b  0xa006ec68
a006ec4c:  80 a0 60 0f  cmp  %g1, 0xf
a006ec50:  83 30 60 10  srl  %g1, 0x10, %g1
a006ec54:  82 20 40 0d  sub  %g1, %o5, %g1
a006ec58:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a006ec5c:  82 1b 40 01  xor  %o5, %g1, %g1
a006ec60:  82 20 40 0d  sub  %g1, %o5, %g1
a006ec64:  80 a0 60 05  cmp  %g1, 5
a006ec68:  34 80 00 02  bg,a   0xa006ec70
a006ec6c:  a8 10 20 01  mov  1, %l4
a006ec70:  92 0a 60 ff  and  %o1, 0xff, %o1
a006ec74:  94 0a a0 ff  and  %o2, 0xff, %o2
a006ec78:  82 0a a0 02  and  %o2, 2, %g1
a006ec7c:  9a 0a 60 02  and  %o1, 2, %o5
a006ec80:  80 a3 40 01  cmp  %o5, %g1
a006ec84:  c2 17 bf de  lduh  [ %fp + -34 ], %g1
a006ec88:  c2 36 20 06  sth  %g1, [ %i0 + 6 ]
a006ec8c:  f4 36 20 08  sth  %i2, [ %i0 + 8 ]
a006ec90:  f6 36 20 02  sth  %i3, [ %i0 + 2 ]
a006ec94:  f8 36 20 04  sth  %i4, [ %i0 + 4 ]
a006ec98:  02 80 00 06  be  0xa006ecb0
a006ec9c:  ec 36 20 0a  sth  %l6, [ %i0 + 0xa ]
a006eca0:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006eca4:  40 00 10 e8  call  0xa0073044
a006eca8:  90 12 20 e8  or  %o0, 0xe8, %o0	! 0xa00660e8
a006ecac:  a8 10 20 01  mov  1, %l4
a006ecb0:  a0 0d 20 ff  and  %l4, 0xff, %l0
a006ecb4:  80 a4 20 01  cmp  %l0, 1
a006ecb8:  32 80 00 20  bne,a   0xa006ed38
a006ecbc:  b0 10 00 10  mov  %l0, %i0
a006ecc0:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006ecc4:  92 10 00 19  mov  %i1, %o1
a006ecc8:  40 00 10 df  call  0xa0073044
a006eccc:  90 12 21 10  or  %o0, 0x110, %o0
a006ecd0:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006ecd4:  92 10 00 19  mov  %i1, %o1
a006ecd8:  d4 16 20 02  lduh  [ %i0 + 2 ], %o2
a006ecdc:  40 00 10 da  call  0xa0073044
a006ece0:  90 12 21 38  or  %o0, 0x138, %o0
a006ece4:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006ece8:  92 10 00 19  mov  %i1, %o1
a006ecec:  d4 16 20 04  lduh  [ %i0 + 4 ], %o2
a006ecf0:  40 00 10 d5  call  0xa0073044
a006ecf4:  90 12 21 58  or  %o0, 0x158, %o0
a006ecf8:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006ecfc:  92 10 00 19  mov  %i1, %o1
a006ed00:  d4 16 20 06  lduh  [ %i0 + 6 ], %o2
a006ed04:  40 00 10 d0  call  0xa0073044
a006ed08:  90 12 21 78  or  %o0, 0x178, %o0
a006ed0c:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006ed10:  92 10 00 19  mov  %i1, %o1
a006ed14:  d4 16 20 08  lduh  [ %i0 + 8 ], %o2
a006ed18:  40 00 10 cb  call  0xa0073044
a006ed1c:  90 12 21 98  or  %o0, 0x198, %o0
a006ed20:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006ed24:  90 12 21 b8  or  %o0, 0x1b8, %o0	! 0xa00661b8
a006ed28:  92 10 00 19  mov  %i1, %o1
a006ed2c:  40 00 10 c6  call  0xa0073044
a006ed30:  d4 16 20 0a  lduh  [ %i0 + 0xa ], %o2
a006ed34:  b0 10 00 10  mov  %l0, %i0
a006ed38:  81 c7 e0 08  ret
a006ed3c:  81 e8 00 00  restore
