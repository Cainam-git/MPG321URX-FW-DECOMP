# leon2m FUN_a0117f48 0xa0117f48-0xa0118174 (556 bytes)
a0117f48:  9d e3 bf 88  save  %sp, -120, %sp
a0117f4c:  1f 33 c0 4b  sethi  %hi(0xcf012c00), %o7
a0117f50:  21 33 c0 46  sethi  %hi(0xcf011800), %l0
a0117f54:  94 13 e2 00  or  %o7, 0x200, %o2
a0117f58:  d6 02 80 00  ld  [ %o2 ], %o3
a0117f5c:  a4 14 23 f8  or  %l0, 0x3f8, %l2
a0117f60:  d8 04 80 00  ld  [ %l2 ], %o4
a0117f64:  a2 14 22 00  or  %l0, 0x200, %l1
a0117f68:  d2 04 40 00  ld  [ %l1 ], %o1
a0117f6c:  da 04 00 00  ld  [ %l0 ], %o5
a0117f70:  ba 10 00 0d  mov  %o5, %i5
a0117f74:  d6 2f bf f7  stb  %o3, [ %fp + -9 ]
a0117f78:  d8 2f bf ef  stb  %o4, [ %fp + -17 ]
a0117f7c:  40 00 01 78  call  0xa011855c
a0117f80:  b8 10 00 09  mov  %o1, %i4
a0117f84:  c0 24 80 00  clr  [ %l2 ]
a0117f88:  c0 24 40 00  clr  [ %l1 ]
a0117f8c:  90 10 20 14  mov  0x14, %o0
a0117f90:  c0 24 00 00  clr  [ %l0 ]
a0117f94:  67 fd d4 83  call  0x4008d1a0
a0117f98:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0117f9c:  11 33 c0 4d  sethi  %hi(0xcf013400), %o0
a0117fa0:  9a 12 20 54  or  %o0, 0x54, %o5	! 0xcf013454
a0117fa4:  c2 03 40 00  ld  [ %o5 ], %g1
a0117fa8:  80 a6 20 01  cmp  %i0, 1
a0117fac:  02 80 00 55  be  0xa0118100
a0117fb0:  ae 10 00 01  mov  %g1, %l7
a0117fb4:  80 a6 20 01  cmp  %i0, 1
a0117fb8:  04 80 00 5e  ble  0xa0118130
a0117fbc:  80 a6 20 02  cmp  %i0, 2
a0117fc0:  02 80 00 56  be  0xa0118118
a0117fc4:  01 00 00 00  nop
a0117fc8:  1f 33 c0 26  sethi  %hi(0xcf009800), %o7
a0117fcc:  a6 13 e3 b8  or  %o7, 0x3b8, %l3	! 0xcf009bb8
a0117fd0:  d4 04 c0 00  ld  [ %l3 ], %o2
a0117fd4:  ac 10 00 0a  mov  %o2, %l6
a0117fd8:  92 10 20 54  mov  0x54, %o1
a0117fdc:  7f ff 68 9e  call  0xa00f2254
a0117fe0:  90 10 20 00  clr  %o0
a0117fe4:  17 33 c0 4b  sethi  %hi(0xcf012c00), %o3
a0117fe8:  a4 12 e2 60  or  %o3, 0x260, %l2	! 0xcf012e60
a0117fec:  da 04 80 00  ld  [ %l2 ], %o5
a0117ff0:  a2 12 e2 64  or  %o3, 0x264, %l1
a0117ff4:  d2 04 40 00  ld  [ %l1 ], %o1
a0117ff8:  98 10 20 59  mov  0x59, %o4
a0117ffc:  d8 24 c0 00  st  %o4, [ %l3 ]
a0118000:  a8 10 00 08  mov  %o0, %l4
a0118004:  aa 10 00 09  mov  %o1, %l5
a0118008:  a6 10 00 0d  mov  %o5, %l3
a011800c:  90 10 20 00  clr  %o0
a0118010:  92 10 20 54  mov  0x54, %o1
a0118014:  7f ff 68 a1  call  0xa00f2298
a0118018:  94 10 20 31  mov  0x31, %o2
a011801c:  67 fd d4 61  call  0x4008d1a0
a0118020:  90 10 20 02  mov  2, %o0
a0118024:  a0 10 20 01  mov  1, %l0
a0118028:  e0 24 80 00  st  %l0, [ %l2 ]
a011802c:  b4 0e a0 ff  and  %i2, 0xff, %i2
a0118030:  c0 24 40 00  clr  [ %l1 ]
a0118034:  80 a6 a0 00  cmp  %i2, 0
a0118038:  02 80 00 2b  be  0xa01180e4
a011803c:  a0 10 20 00  clr  %l0
a0118040:  80 a6 a0 01  cmp  %i2, 1
a0118044:  02 80 00 44  be  0xa0118154
a0118048:  83 2e 60 10  sll  %i1, 0x10, %g1
a011804c:  40 00 01 44  call  0xa011855c
a0118050:  35 33 c0 4d  sethi  %hi(0xcf013400), %i2
a0118054:  67 fd d4 53  call  0x4008d1a0
a0118058:  90 10 20 14  mov  0x14, %o0
a011805c:  9e 0d e0 ff  and  %l7, 0xff, %o7
a0118060:  94 16 a0 54  or  %i2, 0x54, %o2
a0118064:  17 33 c0 26  sethi  %hi(0xcf009800), %o3
a0118068:  de 22 80 00  st  %o7, [ %o2 ]
a011806c:  98 0d a0 ff  and  %l6, 0xff, %o4
a0118070:  9a 12 e3 b8  or  %o3, 0x3b8, %o5
a0118074:  94 0d 20 ff  and  %l4, 0xff, %o2
a0118078:  90 10 20 00  clr  %o0
a011807c:  92 10 20 54  mov  0x54, %o1
a0118080:  d8 23 40 00  st  %o4, [ %o5 ]
a0118084:  7f ff 68 85  call  0xa00f2298
a0118088:  23 33 c0 4b  sethi  %hi(0xcf012c00), %l1
a011808c:  92 0c e0 ff  and  %l3, 0xff, %o1
a0118090:  a4 14 62 60  or  %l1, 0x260, %l2
a0118094:  d2 24 80 00  st  %o1, [ %l2 ]
a0118098:  a8 0f 60 ff  and  %i5, 0xff, %l4
a011809c:  ac 14 62 64  or  %l1, 0x264, %l6
a01180a0:  90 0d 60 ff  and  %l5, 0xff, %o0
a01180a4:  d0 25 80 00  st  %o0, [ %l6 ]
a01180a8:  37 33 c0 46  sethi  %hi(0xcf011800), %i3
a01180ac:  ba 0f 20 ff  and  %i4, 0xff, %i5
a01180b0:  e8 26 c0 00  st  %l4, [ %i3 ]
a01180b4:  b8 16 e2 00  or  %i3, 0x200, %i4
a01180b8:  fa 27 00 00  st  %i5, [ %i4 ]
a01180bc:  b0 16 e3 f8  or  %i3, 0x3f8, %i0
a01180c0:  f2 0f bf ef  ldub  [ %fp + -17 ], %i1
a01180c4:  ee 0f bf f7  ldub  [ %fp + -9 ], %l7
a01180c8:  f2 26 00 00  st  %i1, [ %i0 ]
a01180cc:  80 8d e0 01  btst  1, %l7
a01180d0:  02 80 00 27  be  0xa011816c
a01180d4:  b0 0c 20 ff  and  %l0, 0xff, %i0
a01180d8:  40 00 01 3f  call  0xa01185d4
a01180dc:  01 00 00 00  nop
a01180e0:  30 80 00 23  b,a   0xa011816c
a01180e4:  b5 2e 60 10  sll  %i1, 0x10, %i2
a01180e8:  90 10 00 18  mov  %i0, %o0
a01180ec:  93 36 a0 10  srl  %i2, 0x10, %o1
a01180f0:  7f ff f6 b9  call  0xa0115bd4
a01180f4:  94 0e e0 ff  and  %i3, 0xff, %o2
a01180f8:  10 bf ff d5  b  0xa011804c
a01180fc:  a0 10 00 08  mov  %o0, %l0
a0118100:  d0 03 40 00  ld  [ %o5 ], %o0
a0118104:  82 0a 20 0f  and  %o0, 0xf, %g1
a0118108:  82 10 60 40  or  %g1, 0x40, %g1
a011810c:  c2 23 40 00  st  %g1, [ %o5 ]
a0118110:  10 bf ff af  b  0xa0117fcc
a0118114:  1f 33 c0 26  sethi  %hi(0xcf009800), %o7
a0118118:  ec 03 40 00  ld  [ %o5 ], %l6
a011811c:  aa 0d a0 0f  and  %l6, 0xf, %l5
a0118120:  82 15 60 20  or  %l5, 0x20, %g1
a0118124:  c2 23 40 00  st  %g1, [ %o5 ]
a0118128:  10 bf ff a9  b  0xa0117fcc
a011812c:  1f 33 c0 26  sethi  %hi(0xcf009800), %o7
a0118130:  80 a6 20 00  cmp  %i0, 0
a0118134:  32 bf ff a6  bne,a   0xa0117fcc
a0118138:  1f 33 c0 26  sethi  %hi(0xcf009800), %o7
a011813c:  e8 03 40 00  ld  [ %o5 ], %l4
a0118140:  a6 0d 20 0f  and  %l4, 0xf, %l3
a0118144:  82 14 e0 10  or  %l3, 0x10, %g1
a0118148:  c2 23 40 00  st  %g1, [ %o5 ]
a011814c:  10 bf ff a0  b  0xa0117fcc
a0118150:  1f 33 c0 26  sethi  %hi(0xcf009800), %o7
a0118154:  90 10 00 18  mov  %i0, %o0
a0118158:  93 30 60 10  srl  %g1, 0x10, %o1
a011815c:  7f ff fb a6  call  0xa0116ff4
a0118160:  94 0e e0 ff  and  %i3, 0xff, %o2
a0118164:  10 bf ff ba  b  0xa011804c
a0118168:  a0 10 00 08  mov  %o0, %l0
a011816c:  81 c7 e0 08  ret
a0118170:  81 e8 00 00  restore
