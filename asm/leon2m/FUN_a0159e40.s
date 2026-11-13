# leon2m FUN_a0159e40 0xa0159e40-0xa015a038 (504 bytes)
a0159e40:  9d e3 bf 98  save  %sp, -104, %sp
a0159e44:  ee 06 60 10  ld  [ %i1 + 0x10 ], %l7
a0159e48:  c2 06 20 10  ld  [ %i0 + 0x10 ], %g1
a0159e4c:  b6 10 00 18  mov  %i0, %i3
a0159e50:  80 a0 40 17  cmp  %g1, %l7
a0159e54:  06 80 00 77  bl  0xa015a030
a0159e58:  90 10 20 00  clr  %o0
a0159e5c:  ae 05 ff ff  add  %l7, -1, %l7
a0159e60:  83 2d e0 02  sll  %l7, 2, %g1
a0159e64:  a6 06 60 14  add  %i1, 0x14, %l3
a0159e68:  ba 06 20 14  add  %i0, 0x14, %i5
a0159e6c:  d2 00 40 13  ld  [ %g1 + %l3 ], %o1
a0159e70:  d0 00 40 1d  ld  [ %g1 + %i5 ], %o0
a0159e74:  92 02 60 01  inc  %o1
a0159e78:  b8 00 40 13  add  %g1, %l3, %i4
a0159e7c:  7f ff f2 fc  call  0xa0156a6c
a0159e80:  aa 00 40 1d  add  %g1, %i5, %l5
a0159e84:  b0 92 20 00  orcc  %o0, 0, %i0
a0159e88:  b4 10 00 13  mov  %l3, %i2
a0159e8c:  12 80 00 39  bne  0xa0159f70
a0159e90:  a4 10 00 1d  mov  %i5, %l2
a0159e94:  92 10 00 19  mov  %i1, %o1
a0159e98:  40 00 0d 8b  call  0xa015d4c4
a0159e9c:  90 10 00 1b  mov  %i3, %o0
a0159ea0:  80 a2 20 00  cmp  %o0, 0
a0159ea4:  06 80 00 31  bl  0xa0159f68
a0159ea8:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a0159eac:  b0 06 20 01  inc  %i0
a0159eb0:  a6 10 00 1a  mov  %i2, %l3
a0159eb4:  92 10 63 ff  or  %g1, 0x3ff, %o1
a0159eb8:  a8 10 20 00  clr  %l4
a0159ebc:  a2 10 20 00  clr  %l1
a0159ec0:  a4 10 00 1d  mov  %i5, %l2
a0159ec4:  da 04 c0 00  ld  [ %l3 ], %o5
a0159ec8:  82 0b 40 09  and  %o5, %o1, %g1
a0159ecc:  a2 00 40 11  add  %g1, %l1, %l1
a0159ed0:  d8 04 80 00  ld  [ %l2 ], %o4
a0159ed4:  97 34 60 10  srl  %l1, 0x10, %o3
a0159ed8:  94 0c 40 09  and  %l1, %o1, %o2
a0159edc:  82 0b 00 09  and  %o4, %o1, %g1
a0159ee0:  9b 33 60 10  srl  %o5, 0x10, %o5
a0159ee4:  90 03 40 0b  add  %o5, %o3, %o0
a0159ee8:  82 20 40 0a  sub  %g1, %o2, %g1
a0159eec:  96 00 40 14  add  %g1, %l4, %o3
a0159ef0:  99 33 20 10  srl  %o4, 0x10, %o4
a0159ef4:  82 0a 00 09  and  %o0, %o1, %g1
a0159ef8:  a9 3a e0 10  sra  %o3, 0x10, %l4
a0159efc:  98 23 00 01  sub  %o4, %g1, %o4
a0159f00:  98 03 00 14  add  %o4, %l4, %o4
a0159f04:  d8 34 80 00  sth  %o4, [ %l2 ]
a0159f08:  d6 34 a0 02  sth  %o3, [ %l2 + 2 ]
a0159f0c:  a6 04 e0 04  add  %l3, 4, %l3
a0159f10:  a4 04 a0 04  add  %l2, 4, %l2
a0159f14:  80 a4 c0 1c  cmp  %l3, %i4
a0159f18:  a3 32 20 10  srl  %o0, 0x10, %l1
a0159f1c:  08 bf ff ea  bleu  0xa0159ec4
a0159f20:  a9 3b 20 10  sra  %o4, 0x10, %l4
a0159f24:  9b 2d e0 02  sll  %l7, 2, %o5
a0159f28:  c2 03 40 1d  ld  [ %o5 + %i5 ], %g1
a0159f2c:  80 a0 60 00  cmp  %g1, 0
a0159f30:  12 80 00 0e  bne  0xa0159f68
a0159f34:  aa 03 40 1d  add  %o5, %i5, %l5
a0159f38:  aa 05 7f fc  add  %l5, -4, %l5
a0159f3c:  80 a5 40 1d  cmp  %l5, %i5
a0159f40:  28 80 00 0a  bleu,a   0xa0159f68
a0159f44:  ee 26 e0 10  st  %l7, [ %i3 + 0x10 ]
a0159f48:  c2 05 40 00  ld  [ %l5 ], %g1
a0159f4c:  80 a0 60 00  cmp  %g1, 0
a0159f50:  12 80 00 05  bne  0xa0159f64
a0159f54:  aa 05 7f fc  add  %l5, -4, %l5
a0159f58:  80 a5 40 1d  cmp  %l5, %i5
a0159f5c:  10 bf ff f9  b  0xa0159f40
a0159f60:  ae 05 ff ff  add  %l7, -1, %l7
a0159f64:  ee 26 e0 10  st  %l7, [ %i3 + 0x10 ]
a0159f68:  10 80 00 32  b  0xa015a030
a0159f6c:  90 10 00 18  mov  %i0, %o0
a0159f70:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a0159f74:  ac 10 63 ff  or  %g1, 0x3ff, %l6	! 0xffff
a0159f78:  a8 10 20 00  clr  %l4
a0159f7c:  a2 10 20 00  clr  %l1
a0159f80:  e0 04 c0 00  ld  [ %l3 ], %l0
a0159f84:  92 10 00 18  mov  %i0, %o1
a0159f88:  7f ff f5 9b  call  0xa01575f4
a0159f8c:  90 0c 00 16  and  %l0, %l6, %o0
a0159f90:  a2 02 00 11  add  %o0, %l1, %l1
a0159f94:  91 34 20 10  srl  %l0, 0x10, %o0
a0159f98:  7f ff f5 97  call  0xa01575f4
a0159f9c:  92 10 00 18  mov  %i0, %o1
a0159fa0:  da 04 80 00  ld  [ %l2 ], %o5
a0159fa4:  96 0c 40 16  and  %l1, %l6, %o3
a0159fa8:  82 0b 40 16  and  %o5, %l6, %g1
a0159fac:  99 34 60 10  srl  %l1, 0x10, %o4
a0159fb0:  82 20 40 0b  sub  %g1, %o3, %g1
a0159fb4:  90 02 00 0c  add  %o0, %o4, %o0
a0159fb8:  96 00 40 14  add  %g1, %l4, %o3
a0159fbc:  9b 33 60 10  srl  %o5, 0x10, %o5
a0159fc0:  82 0a 00 16  and  %o0, %l6, %g1
a0159fc4:  a9 3a e0 10  sra  %o3, 0x10, %l4
a0159fc8:  9a 23 40 01  sub  %o5, %g1, %o5
a0159fcc:  98 03 40 14  add  %o5, %l4, %o4
a0159fd0:  d8 34 80 00  sth  %o4, [ %l2 ]
a0159fd4:  d6 34 a0 02  sth  %o3, [ %l2 + 2 ]
a0159fd8:  a6 04 e0 04  add  %l3, 4, %l3
a0159fdc:  a4 04 a0 04  add  %l2, 4, %l2
a0159fe0:  80 a4 c0 1c  cmp  %l3, %i4
a0159fe4:  a3 32 20 10  srl  %o0, 0x10, %l1
a0159fe8:  08 bf ff e6  bleu  0xa0159f80
a0159fec:  a9 3b 20 10  sra  %o4, 0x10, %l4
a0159ff0:  c2 05 40 00  ld  [ %l5 ], %g1
a0159ff4:  80 a0 60 00  cmp  %g1, 0
a0159ff8:  32 bf ff a8  bne,a   0xa0159e98
a0159ffc:  92 10 00 19  mov  %i1, %o1
a015a000:  aa 05 7f fc  add  %l5, -4, %l5
a015a004:  80 a5 40 1d  cmp  %l5, %i5
a015a008:  28 bf ff a3  bleu,a   0xa0159e94
a015a00c:  ee 26 e0 10  st  %l7, [ %i3 + 0x10 ]
a015a010:  c2 05 40 00  ld  [ %l5 ], %g1
a015a014:  80 a0 60 00  cmp  %g1, 0
a015a018:  32 bf ff 9f  bne,a   0xa0159e94
a015a01c:  ee 26 e0 10  st  %l7, [ %i3 + 0x10 ]
a015a020:  aa 05 7f fc  add  %l5, -4, %l5
a015a024:  80 a5 40 1d  cmp  %l5, %i5
a015a028:  10 bf ff f8  b  0xa015a008
a015a02c:  ae 05 ff ff  add  %l7, -1, %l7
a015a030:  81 c7 e0 08  ret
a015a034:  91 e8 00 08  restore  %g0, %o0, %o0
