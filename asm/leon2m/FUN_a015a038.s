# leon2m FUN_a015a038 0xa015a038-0xa015b300 (4716 bytes)
a015a038:  9d e3 bf 58  save  %sp, -168, %sp
a015a03c:  d2 06 20 40  ld  [ %i0 + 0x40 ], %o1
a015a040:  f0 27 a0 44  st  %i0, [ %fp + 0x44 ]
a015a044:  f8 27 a0 54  st  %i4, [ %fp + 0x54 ]
a015a048:  fa 27 a0 58  st  %i5, [ %fp + 0x58 ]
a015a04c:  a8 10 00 19  mov  %i1, %l4
a015a050:  aa 10 00 1a  mov  %i2, %l5
a015a054:  80 a2 60 00  cmp  %o1, 0
a015a058:  e0 07 a0 5c  ld  [ %fp + 0x5c ], %l0
a015a05c:  12 80 00 95  bne  0xa015a2b0
a015a060:  c0 27 bf c0  clr  [ %fp + -64 ]
a015a064:  80 a5 20 00  cmp  %l4, 0
a015a068:  06 80 00 9f  bl  0xa015a2e4
a015a06c:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a015a070:  1b 1f fc 00  sethi  %hi(0x7ff00000), %o5
a015a074:  82 0d 00 0d  and  %l4, %o5, %g1
a015a078:  80 a0 40 0d  cmp  %g1, %o5
a015a07c:  02 80 00 a2  be  0xa015a304
a015a080:  c0 24 00 00  clr  [ %l0 ]
a015a084:  19 00 06 a0  sethi  %hi(0x1a8000), %o4
a015a088:  90 10 00 14  mov  %l4, %o0
a015a08c:  92 10 00 15  mov  %l5, %o1
a015a090:  7f ff f1 88  call  0xa01566b0
a015a094:  d4 1b 22 08  ldd  [ %o4 + 0x208 ], %o2
a015a098:  80 a2 20 00  cmp  %o0, 0
a015a09c:  12 80 00 0e  bne  0xa015a0d4
a015a0a0:  82 10 20 01  mov  1, %g1
a015a0a4:  da 07 a0 58  ld  [ %fp + 0x58 ], %o5
a015a0a8:  c2 23 40 00  st  %g1, [ %o5 ]
a015a0ac:  1b 00 06 a1  sethi  %hi(0x1a8400), %o5
a015a0b0:  c2 07 a0 60  ld  [ %fp + 0x60 ], %g1
a015a0b4:  80 a0 60 00  cmp  %g1, 0
a015a0b8:  02 80 00 05  be  0xa015a0cc
a015a0bc:  b0 13 60 60  or  %o5, 0x60, %i0
a015a0c0:  82 06 20 01  add  %i0, 1, %g1
a015a0c4:  d6 07 a0 60  ld  [ %fp + 0x60 ], %o3
a015a0c8:  c2 22 c0 00  st  %g1, [ %o3 ]
a015a0cc:  10 80 04 8b  b  0xa015b2f8
a015a0d0:  82 10 00 18  mov  %i0, %g1
a015a0d4:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015a0d8:  92 10 00 14  mov  %l4, %o1
a015a0dc:  94 10 00 15  mov  %l5, %o2
a015a0e0:  96 07 bf f4  add  %fp, -12, %o3
a015a0e4:  40 00 0d c3  call  0xa015d7f0
a015a0e8:  98 07 bf f0  add  %fp, -16, %o4
a015a0ec:  83 35 20 14  srl  %l4, 0x14, %g1
a015a0f0:  b2 88 67 ff  andcc  %g1, 0x7ff, %i1
a015a0f4:  12 80 00 9f  bne  0xa015a370
a015a0f8:  d0 27 bf c4  st  %o0, [ %fp + -60 ]
a015a0fc:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a015a100:  f4 07 bf f0  ld  [ %fp + -16 ], %i2
a015a104:  9a 06 80 01  add  %i2, %g1, %o5
a015a108:  b2 03 64 32  add  %o5, 0x432, %i1
a015a10c:  82 20 00 19  neg  %i1, %g1
a015a110:  80 a6 60 20  cmp  %i1, 0x20
a015a114:  04 80 00 06  ble  0xa015a12c
a015a118:  a1 2d 40 01  sll  %l5, %g1, %l0
a015a11c:  9a 03 64 12  add  %o5, 0x412, %o5
a015a120:  83 2d 00 01  sll  %l4, %g1, %g1
a015a124:  9b 35 40 0d  srl  %l5, %o5, %o5
a015a128:  a0 10 40 0d  or  %g1, %o5, %l0
a015a12c:  7f ff f1 c5  call  0xa0156840
a015a130:  90 10 00 10  mov  %l0, %o0
a015a134:  80 a4 20 00  cmp  %l0, 0
a015a138:  06 80 03 e6  bl  0xa015b0d0
a015a13c:  19 00 06 a1  sethi  %hi(0x1a8400), %o4
a015a140:  03 3f 84 00  sethi  %hi(0xfe100000), %g1
a015a144:  9a 10 20 01  mov  1, %o5
a015a148:  ae 10 00 09  mov  %o1, %l7
a015a14c:  ac 00 40 08  add  %g1, %o0, %l6
a015a150:  b2 06 7b cd  add  %i1, -1075, %i1
a015a154:  da 27 bf c8  st  %o5, [ %fp + -56 ]
a015a158:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015a15c:  d4 18 60 b0  ldd  [ %g1 + 0xb0 ], %o2	! 0x1a84b0
a015a160:  90 10 00 16  mov  %l6, %o0
a015a164:  7f ff ef e6  call  0xa01560fc
a015a168:  92 10 00 17  mov  %l7, %o1
a015a16c:  19 00 06 a1  sethi  %hi(0x1a8400), %o4
a015a170:  7f ff ef fa  call  0xa0156158
a015a174:  d4 1b 20 b8  ldd  [ %o4 + 0xb8 ], %o2	! 0x1a84b8
a015a178:  1b 00 06 a1  sethi  %hi(0x1a8400), %o5
a015a17c:  7f ff ef cc  call  0xa01560ac
a015a180:  d4 1b 60 c0  ldd  [ %o5 + 0xc0 ], %o2	! 0x1a84c0
a015a184:  a0 10 00 08  mov  %o0, %l0
a015a188:  a2 10 00 09  mov  %o1, %l1
a015a18c:  7f ff f1 ad  call  0xa0156840
a015a190:  90 10 00 19  mov  %i1, %o0
a015a194:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015a198:  7f ff ef f0  call  0xa0156158
a015a19c:  d4 18 60 c8  ldd  [ %g1 + 0xc8 ], %o2	! 0x1a84c8
a015a1a0:  94 10 00 08  mov  %o0, %o2
a015a1a4:  96 10 00 09  mov  %o1, %o3
a015a1a8:  90 10 00 10  mov  %l0, %o0
a015a1ac:  7f ff ef c0  call  0xa01560ac
a015a1b0:  92 10 00 11  mov  %l1, %o1
a015a1b4:  a4 10 00 08  mov  %o0, %l2
a015a1b8:  a6 10 00 09  mov  %o1, %l3
a015a1bc:  7f ff f1 e2  call  0xa0156944
a015a1c0:  90 10 00 12  mov  %l2, %o0
a015a1c4:  19 00 06 a0  sethi  %hi(0x1a8000), %o4
a015a1c8:  ba 10 00 08  mov  %o0, %i5
a015a1cc:  90 10 00 12  mov  %l2, %o0
a015a1d0:  92 10 00 13  mov  %l3, %o1
a015a1d4:  40 00 11 68  call  0xa015e774
a015a1d8:  d4 1b 22 08  ldd  [ %o4 + 0x208 ], %o2
a015a1dc:  80 a2 20 00  cmp  %o0, 0
a015a1e0:  06 80 02 a2  bl  0xa015ac68
a015a1e4:  01 00 00 00  nop
a015a1e8:  9a 10 20 01  mov  1, %o5	! 0x1
a015a1ec:  80 a7 60 16  cmp  %i5, 0x16
a015a1f0:  18 80 00 0f  bgu  0xa015a22c
a015a1f4:  da 27 bf d4  st  %o5, [ %fp + -44 ]
a015a1f8:  1b 00 06 a1  sethi  %hi(0x1a8400), %o5
a015a1fc:  83 2f 60 03  sll  %i5, 3, %g1
a015a200:  9a 13 61 78  or  %o5, 0x178, %o5
a015a204:  96 03 40 01  add  %o5, %g1, %o3
a015a208:  d0 1a c0 00  ldd  [ %o3 ], %o0
a015a20c:  94 10 00 14  mov  %l4, %o2
a015a210:  7f ff f1 5a  call  0xa0156778
a015a214:  96 10 00 15  mov  %l5, %o3
a015a218:  83 3a 20 1f  sra  %o0, 0x1f, %g1
a015a21c:  82 20 40 08  sub  %g1, %o0, %g1
a015a220:  83 30 60 1f  srl  %g1, 0x1f, %g1
a015a224:  ba 27 40 01  sub  %i5, %g1, %i5
a015a228:  c0 27 bf d4  clr  [ %fp + -44 ]
a015a22c:  82 26 80 19  sub  %i2, %i1, %g1
a015a230:  a0 80 7f ff  addcc  %g1, -1, %l0
a015a234:  2c 80 02 9b  bneg,a   0xa015aca0
a015a238:  a0 20 00 10  neg  %l0
a015a23c:  b8 10 00 10  mov  %l0, %i4
a015a240:  c0 27 bf ec  clr  [ %fp + -20 ]
a015a244:  80 a7 60 00  cmp  %i5, 0
a015a248:  06 80 02 90  bl  0xa015ac88
a015a24c:  d8 07 bf ec  ld  [ %fp + -20 ], %o4
a015a250:  b8 07 00 1d  add  %i4, %i5, %i4
a015a254:  c0 27 bf e8  clr  [ %fp + -24 ]
a015a258:  fa 27 bf cc  st  %i5, [ %fp + -52 ]
a015a25c:  80 a6 e0 0a  cmp  %i3, 0xa
a015a260:  82 60 20 00  subx  %g0, 0, %g1
a015a264:  b6 0e c0 01  and  %i3, %g1, %i3
a015a268:  80 a6 e0 05  cmp  %i3, 5
a015a26c:  04 80 00 04  ble  0xa015a27c
a015a270:  a2 10 20 01  mov  1, %l1
a015a274:  b6 06 ff fc  add  %i3, -4, %i3
a015a278:  a2 10 20 00  clr  %l1
a015a27c:  96 10 3f ff  mov  -1, %o3
a015a280:  82 10 20 01  mov  1, %g1
a015a284:  80 a6 e0 05  cmp  %i3, 5
a015a288:  c2 27 bf d0  st  %g1, [ %fp + -48 ]
a015a28c:  d6 27 bf dc  st  %o3, [ %fp + -36 ]
a015a290:  18 80 00 4a  bgu  0xa015a3b8
a015a294:  d6 27 bf e4  st  %o3, [ %fp + -28 ]
a015a298:  1b 00 03 e7  sethi  %hi(0xf9c00), %o5
a015a29c:  83 2e e0 02  sll  %i3, 2, %g1
a015a2a0:  9a 13 62 28  or  %o5, 0x228, %o5
a015a2a4:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a015a2a8:  81 c3 00 00  jmp  %o4
a015a2ac:  01 00 00 00  nop
a015a2b0:  c2 06 20 44  ld  [ %i0 + 0x44 ], %g1
a015a2b4:  c2 22 60 04  st  %g1, [ %o1 + 4 ]
a015a2b8:  da 06 20 44  ld  [ %i0 + 0x44 ], %o5
a015a2bc:  82 10 20 01  mov  1, %g1
a015a2c0:  83 28 40 0d  sll  %g1, %o5, %g1
a015a2c4:  c2 22 60 08  st  %g1, [ %o1 + 8 ]
a015a2c8:  40 00 0a 98  call  0xa015cd28
a015a2cc:  90 10 00 18  mov  %i0, %o0
a015a2d0:  d6 07 a0 44  ld  [ %fp + 0x44 ], %o3
a015a2d4:  80 a5 20 00  cmp  %l4, 0
a015a2d8:  16 bf ff 66  bge  0xa015a070
a015a2dc:  c0 22 e0 40  clr  [ %o3 + 0x40 ]
a015a2e0:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a015a2e4:  82 10 20 01  mov  1, %g1
a015a2e8:  a8 2d 00 0d  andn  %l4, %o5, %l4
a015a2ec:  1b 1f fc 00  sethi  %hi(0x7ff00000), %o5
a015a2f0:  c2 24 00 00  st  %g1, [ %l0 ]
a015a2f4:  82 0d 00 0d  and  %l4, %o5, %g1
a015a2f8:  80 a0 40 0d  cmp  %g1, %o5
a015a2fc:  12 bf ff 63  bne  0xa015a088
a015a300:  19 00 06 a0  sethi  %hi(0x1a8000), %o4
a015a304:  03 00 00 09  sethi  %hi(0x2400), %g1
a015a308:  82 10 63 0f  or  %g1, 0x30f, %g1	! 0x270f
a015a30c:  d8 07 a0 58  ld  [ %fp + 0x58 ], %o4
a015a310:  80 a5 60 00  cmp  %l5, 0
a015a314:  02 80 00 10  be  0xa015a354
a015a318:  c2 23 00 00  st  %g1, [ %o4 ]
a015a31c:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015a320:  b0 10 60 68  or  %g1, 0x68, %i0	! 0x1a8468
a015a324:  da 07 a0 60  ld  [ %fp + 0x60 ], %o5
a015a328:  80 a3 60 00  cmp  %o5, 0
a015a32c:  22 80 03 f3  be,a   0xa015b2f8
a015a330:  82 10 00 18  mov  %i0, %g1
a015a334:  c2 4e 20 03  ldsb  [ %i0 + 3 ], %g1
a015a338:  80 a0 60 00  cmp  %g1, 0
a015a33c:  12 bf ff 62  bne  0xa015a0c4
a015a340:  82 06 20 08  add  %i0, 8, %g1
a015a344:  82 06 20 03  add  %i0, 3, %g1
a015a348:  d6 07 a0 60  ld  [ %fp + 0x60 ], %o3
a015a34c:  10 bf ff 60  b  0xa015a0cc
a015a350:  c2 22 c0 00  st  %g1, [ %o3 ]
a015a354:  03 3f fc 00  sethi  %hi(0xfff00000), %g1
a015a358:  1b 00 06 a1  sethi  %hi(0x1a8400), %o5
a015a35c:  80 ad 00 01  andncc  %l4, %g1, %g0
a015a360:  02 bf ff f1  be  0xa015a324
a015a364:  b0 13 60 98  or  %o5, 0x98, %i0
a015a368:  10 bf ff ee  b  0xa015a320
a015a36c:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015a370:  03 3f fc 00  sethi  %hi(0xfff00000), %g1
a015a374:  ac 2d 00 01  andn  %l4, %g1, %l6
a015a378:  1b 0f fc 00  sethi  %hi(0x3ff00000), %o5
a015a37c:  ae 10 00 15  mov  %l5, %l7
a015a380:  ac 13 40 16  or  %o5, %l6, %l6
a015a384:  b2 06 7c 01  add  %i1, -1023, %i1
a015a388:  c0 27 bf c8  clr  [ %fp + -56 ]
a015a38c:  10 bf ff 73  b  0xa015a158
a015a390:  f4 07 bf f0  ld  [ %fp + -16 ], %i2
a015a394:  c0 27 bf d0  clr  [ %fp + -48 ]
a015a398:  d6 07 a0 54  ld  [ %fp + 0x54 ], %o3
a015a39c:  82 02 c0 1d  add  %o3, %i5, %g1
a015a3a0:  b2 00 60 01  add  %g1, 1, %i1
a015a3a4:  c2 27 bf dc  st  %g1, [ %fp + -36 ]
a015a3a8:  80 a6 60 00  cmp  %i1, 0
a015a3ac:  14 80 00 03  bg  0xa015a3b8
a015a3b0:  f2 27 bf e4  st  %i1, [ %fp + -28 ]
a015a3b4:  b2 10 20 01  mov  1, %i1
a015a3b8:  d8 07 a0 44  ld  [ %fp + 0x44 ], %o4
a015a3bc:  c0 23 20 44  clr  [ %o4 + 0x44 ]
a015a3c0:  80 a6 60 17  cmp  %i1, 0x17
a015a3c4:  08 80 00 0a  bleu  0xa015a3ec
a015a3c8:  a0 10 20 04  mov  4, %l0
a015a3cc:  9a 10 20 00  clr  %o5
a015a3d0:  a0 04 00 10  add  %l0, %l0, %l0
a015a3d4:  82 04 20 14  add  %l0, 0x14, %g1
a015a3d8:  80 a0 40 19  cmp  %g1, %i1
a015a3dc:  08 bf ff fd  bleu  0xa015a3d0
a015a3e0:  9a 03 60 01  inc  %o5
a015a3e4:  c2 07 a0 44  ld  [ %fp + 0x44 ], %g1
a015a3e8:  da 20 60 44  st  %o5, [ %g1 + 0x44 ]
a015a3ec:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015a3f0:  40 00 0a 25  call  0xa015cc84
a015a3f4:  d2 02 20 44  ld  [ %o0 + 0x44 ], %o1
a015a3f8:  d6 07 bf e4  ld  [ %fp + -28 ], %o3
a015a3fc:  80 a2 e0 0f  cmp  %o3, 0xf
a015a400:  82 40 20 00  addx  %g0, 0, %g1
a015a404:  d8 07 a0 44  ld  [ %fp + 0x44 ], %o4
a015a408:  d0 27 bf b8  st  %o0, [ %fp + -72 ]
a015a40c:  80 88 40 11  btst  %g1, %l1
a015a410:  d0 23 20 40  st  %o0, [ %o4 + 0x40 ]
a015a414:  02 80 00 a0  be  0xa015a694
a015a418:  b0 10 00 08  mov  %o0, %i0
a015a41c:  80 a7 60 00  cmp  %i5, 0
a015a420:  b2 10 20 00  clr  %i1
a015a424:  ac 10 00 14  mov  %l4, %l6
a015a428:  ae 10 00 15  mov  %l5, %l7
a015a42c:  fa 27 bf d8  st  %i5, [ %fp + -40 ]
a015a430:  d6 27 bf e0  st  %o3, [ %fp + -32 ]
a015a434:  04 80 03 02  ble  0xa015b03c
a015a438:  a2 10 20 02  mov  2, %l1
a015a43c:  9a 0f 60 0f  and  %i5, 0xf, %o5
a015a440:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015a444:  9b 2b 60 03  sll  %o5, 3, %o5
a015a448:  82 10 61 78  or  %g1, 0x178, %g1
a015a44c:  a1 3f 60 04  sra  %i5, 4, %l0
a015a450:  96 00 40 0d  add  %g1, %o5, %o3
a015a454:  80 8c 20 10  btst  0x10, %l0
a015a458:  12 80 01 8a  bne  0xa015aa80
a015a45c:  e4 1a c0 00  ldd  [ %o3 ], %l2
a015a460:  80 a4 20 00  cmp  %l0, 0
a015a464:  02 80 00 13  be  0xa015a4b0
a015a468:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015a46c:  b4 10 61 50  or  %g1, 0x150, %i2	! 0x1a8550
a015a470:  80 8c 20 01  btst  1, %l0
a015a474:  22 80 00 0c  be,a   0xa015a4a4
a015a478:  a1 3c 20 01  sra  %l0, 1, %l0
a015a47c:  83 2e 60 03  sll  %i1, 3, %g1
a015a480:  98 06 80 01  add  %i2, %g1, %o4
a015a484:  90 10 00 12  mov  %l2, %o0
a015a488:  92 10 00 13  mov  %l3, %o1
a015a48c:  7f ff ef 33  call  0xa0156158
a015a490:  d4 1b 00 00  ldd  [ %o4 ], %o2
a015a494:  a4 10 00 08  mov  %o0, %l2
a015a498:  a6 10 00 09  mov  %o1, %l3
a015a49c:  a2 04 60 01  inc  %l1
a015a4a0:  a1 3c 20 01  sra  %l0, 1, %l0
a015a4a4:  80 a4 20 00  cmp  %l0, 0
a015a4a8:  12 bf ff f2  bne  0xa015a470
a015a4ac:  b2 06 60 01  inc  %i1
a015a4b0:  90 10 00 14  mov  %l4, %o0
a015a4b4:  92 10 00 15  mov  %l5, %o1
a015a4b8:  94 10 00 12  mov  %l2, %o2
a015a4bc:  7f ff ef fd  call  0xa01564b0
a015a4c0:  96 10 00 13  mov  %l3, %o3
a015a4c4:  a8 10 00 08  mov  %o0, %l4
a015a4c8:  aa 10 00 09  mov  %o1, %l5
a015a4cc:  da 07 bf d4  ld  [ %fp + -44 ], %o5
a015a4d0:  80 a3 60 00  cmp  %o5, 0
a015a4d4:  02 80 00 1d  be  0xa015a548
a015a4d8:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a015a4dc:  90 10 00 14  mov  %l4, %o0
a015a4e0:  92 10 00 15  mov  %l5, %o1
a015a4e4:  40 00 10 a4  call  0xa015e774
a015a4e8:  d4 18 62 30  ldd  [ %g1 + 0x230 ], %o2
a015a4ec:  80 a2 20 00  cmp  %o0, 0
a015a4f0:  06 80 03 3b  bl  0xa015b1dc
a015a4f4:  9a 10 20 00  clr  %o5
a015a4f8:  d6 07 bf e4  ld  [ %fp + -28 ], %o3
a015a4fc:  83 3a e0 1f  sra  %o3, 0x1f, %g1
a015a500:  82 20 40 0b  sub  %g1, %o3, %g1
a015a504:  83 30 60 1f  srl  %g1, 0x1f, %g1
a015a508:  80 8b 40 01  btst  %o5, %g1
a015a50c:  02 80 00 0f  be  0xa015a548
a015a510:  d8 07 bf dc  ld  [ %fp + -36 ], %o4
a015a514:  80 a3 20 00  cmp  %o4, 0
a015a518:  04 80 00 59  ble  0xa015a67c
a015a51c:  1b 00 06 a1  sethi  %hi(0x1a8400), %o5
a015a520:  94 10 00 14  mov  %l4, %o2
a015a524:  96 10 00 15  mov  %l5, %o3
a015a528:  7f ff ef 0c  call  0xa0156158
a015a52c:  d0 1b 60 d0  ldd  [ %o5 + 0xd0 ], %o0
a015a530:  c2 07 bf dc  ld  [ %fp + -36 ], %g1
a015a534:  a8 10 00 08  mov  %o0, %l4
a015a538:  aa 10 00 09  mov  %o1, %l5
a015a53c:  ba 07 7f ff  add  %i5, -1, %i5
a015a540:  a2 04 60 01  inc  %l1
a015a544:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a015a548:  7f ff f0 be  call  0xa0156840
a015a54c:  90 10 00 11  mov  %l1, %o0
a015a550:  94 10 00 14  mov  %l4, %o2
a015a554:  7f ff ef 01  call  0xa0156158
a015a558:  96 10 00 15  mov  %l5, %o3
a015a55c:  19 00 06 a1  sethi  %hi(0x1a8400), %o4
a015a560:  7f ff ee d3  call  0xa01560ac
a015a564:  d4 1b 20 d8  ldd  [ %o4 + 0xd8 ], %o2	! 0x1a84d8
a015a568:  a4 10 00 08  mov  %o0, %l2
a015a56c:  03 3f 30 00  sethi  %hi(0xfcc00000), %g1
a015a570:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a015a574:  a6 10 00 09  mov  %o1, %l3
a015a578:  80 a3 60 00  cmp  %o5, 0
a015a57c:  12 80 01 73  bne  0xa015ab48
a015a580:  a4 00 40 12  add  %g1, %l2, %l2
a015a584:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015a588:  d4 18 60 e0  ldd  [ %g1 + 0xe0 ], %o2	! 0x1a84e0
a015a58c:  90 10 00 14  mov  %l4, %o0
a015a590:  7f ff ee db  call  0xa01560fc
a015a594:  92 10 00 15  mov  %l5, %o1
a015a598:  a0 10 00 08  mov  %o0, %l0
a015a59c:  a2 10 00 09  mov  %o1, %l1
a015a5a0:  90 10 00 10  mov  %l0, %o0
a015a5a4:  94 10 00 12  mov  %l2, %o2
a015a5a8:  7f ff f0 74  call  0xa0156778
a015a5ac:  96 10 00 13  mov  %l3, %o3
a015a5b0:  80 a2 20 00  cmp  %o0, 0
a015a5b4:  c0 27 bf bc  clr  [ %fp + -68 ]
a015a5b8:  04 80 00 27  ble  0xa015a654
a015a5bc:  b4 10 20 00  clr  %i2
a015a5c0:  d6 07 bf b8  ld  [ %fp + -72 ], %o3
a015a5c4:  82 10 20 31  mov  0x31, %g1
a015a5c8:  c2 2a c0 00  stb  %g1, [ %o3 ]
a015a5cc:  ba 07 60 01  inc  %i5
a015a5d0:  b0 02 e0 01  add  %o3, 1, %i0
a015a5d4:  92 10 00 1a  mov  %i2, %o1
a015a5d8:  40 00 09 d4  call  0xa015cd28
a015a5dc:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015a5e0:  da 07 bf bc  ld  [ %fp + -68 ], %o5
a015a5e4:  80 a3 60 00  cmp  %o5, 0
a015a5e8:  02 80 00 0e  be  0xa015a620
a015a5ec:  c2 07 bf c0  ld  [ %fp + -64 ], %g1
a015a5f0:  80 a0 00 01  cmp  %g0, %g1
a015a5f4:  d6 07 bf c0  ld  [ %fp + -64 ], %o3
a015a5f8:  82 40 20 00  addx  %g0, 0, %g1
a015a5fc:  9a 1a c0 0d  xor  %o3, %o5, %o5
a015a600:  80 a0 00 0d  cmp  %g0, %o5
a015a604:  98 40 20 00  addx  %g0, 0, %o4
a015a608:  80 88 40 0c  btst  %g1, %o4
a015a60c:  32 80 01 a8  bne,a   0xa015acac
a015a610:  92 10 00 0b  mov  %o3, %o1
a015a614:  d2 07 bf bc  ld  [ %fp + -68 ], %o1
a015a618:  40 00 09 c4  call  0xa015cd28
a015a61c:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015a620:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015a624:  40 00 09 c1  call  0xa015cd28
a015a628:  d2 07 bf c4  ld  [ %fp + -60 ], %o1
a015a62c:  c0 2e 00 00  clrb  [ %i0 ]
a015a630:  82 07 60 01  add  %i5, 1, %g1
a015a634:  d8 07 a0 58  ld  [ %fp + 0x58 ], %o4
a015a638:  da 07 a0 60  ld  [ %fp + 0x60 ], %o5
a015a63c:  80 a3 60 00  cmp  %o5, 0
a015a640:  02 80 00 03  be  0xa015a64c
a015a644:  c2 23 00 00  st  %g1, [ %o4 ]
a015a648:  f0 23 40 00  st  %i0, [ %o5 ]
a015a64c:  10 80 03 2b  b  0xa015b2f8
a015a650:  c2 07 bf b8  ld  [ %fp + -72 ], %g1
a015a654:  19 20 00 00  sethi  %hi(0x80000000), %o4
a015a658:  9a 10 20 00  clr  %o5
a015a65c:  90 1c 80 0c  xor  %l2, %o4, %o0
a015a660:  92 1c c0 0d  xor  %l3, %o5, %o1
a015a664:  94 10 00 10  mov  %l0, %o2
a015a668:  7f ff f0 44  call  0xa0156778
a015a66c:  96 10 00 11  mov  %l1, %o3
a015a670:  80 a2 20 00  cmp  %o0, 0
a015a674:  14 80 00 2f  bg  0xa015a730
a015a678:  da 07 a0 54  ld  [ %fp + 0x54 ], %o5
a015a67c:  d6 07 bf e0  ld  [ %fp + -32 ], %o3
a015a680:  a8 10 00 16  mov  %l6, %l4
a015a684:  aa 10 00 17  mov  %l7, %l5
a015a688:  fa 07 bf d8  ld  [ %fp + -40 ], %i5
a015a68c:  d6 27 bf e4  st  %o3, [ %fp + -28 ]
a015a690:  f0 07 bf b8  ld  [ %fp + -72 ], %i0
a015a694:  d0 07 bf f4  ld  [ %fp + -12 ], %o0
a015a698:  82 38 00 08  xnor  %g0, %o0, %g1
a015a69c:  83 30 60 1f  srl  %g1, 0x1f, %g1
a015a6a0:  80 a7 60 0e  cmp  %i5, 0xe
a015a6a4:  04 80 00 03  ble  0xa015a6b0
a015a6a8:  98 10 20 01  mov  1, %o4
a015a6ac:  98 10 20 00  clr  %o4
a015a6b0:  80 88 40 0c  btst  %g1, %o4
a015a6b4:  02 80 00 21  be  0xa015a738
a015a6b8:  da 07 bf d0  ld  [ %fp + -48 ], %o5
a015a6bc:  d8 07 bf e4  ld  [ %fp + -28 ], %o4
a015a6c0:  82 03 3f ff  add  %o4, -1, %g1
a015a6c4:  82 13 00 01  or  %o4, %g1, %g1
a015a6c8:  1b 00 06 a1  sethi  %hi(0x1a8400), %o5
a015a6cc:  99 2f 60 03  sll  %i5, 3, %o4
a015a6d0:  9a 13 61 78  or  %o5, 0x178, %o5
a015a6d4:  96 03 40 0c  add  %o5, %o4, %o3
a015a6d8:  d8 07 a0 54  ld  [ %fp + 0x54 ], %o4
a015a6dc:  e4 1a c0 00  ldd  [ %o3 ], %l2
a015a6e0:  80 88 40 0c  btst  %g1, %o4
a015a6e4:  16 80 00 a8  bge  0xa015a984
a015a6e8:  b2 10 20 01  mov  1, %i1
a015a6ec:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a015a6f0:  80 a3 60 00  cmp  %o5, 0
a015a6f4:  c0 27 bf bc  clr  [ %fp + -68 ]
a015a6f8:  06 80 00 0d  bl  0xa015a72c
a015a6fc:  b4 10 20 00  clr  %i2
a015a700:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015a704:  d4 18 60 e0  ldd  [ %g1 + 0xe0 ], %o2	! 0x1a84e0
a015a708:  90 10 00 12  mov  %l2, %o0
a015a70c:  7f ff ee 93  call  0xa0156158
a015a710:  92 10 00 13  mov  %l3, %o1
a015a714:  94 10 00 14  mov  %l4, %o2
a015a718:  7f ff f0 31  call  0xa01567dc
a015a71c:  96 10 00 15  mov  %l5, %o3
a015a720:  80 a2 20 00  cmp  %o0, 0
a015a724:  06 bf ff a8  bl  0xa015a5c4
a015a728:  d6 07 bf b8  ld  [ %fp + -72 ], %o3
a015a72c:  da 07 a0 54  ld  [ %fp + 0x54 ], %o5
a015a730:  10 bf ff a9  b  0xa015a5d4
a015a734:  ba 38 00 0d  xnor  %g0, %o5, %i5
a015a738:  80 a3 60 00  cmp  %o5, 0
a015a73c:  e4 07 bf ec  ld  [ %fp + -20 ], %l2
a015a740:  e2 07 bf e8  ld  [ %fp + -24 ], %l1
a015a744:  c0 27 bf c0  clr  [ %fp + -64 ]
a015a748:  12 80 00 d8  bne  0xa015aaa8
a015a74c:  c0 27 bf bc  clr  [ %fp + -68 ]
a015a750:  9b 3c a0 1f  sra  %l2, 0x1f, %o5
a015a754:  83 3f 20 1f  sra  %i4, 0x1f, %g1
a015a758:  9a 23 40 12  sub  %o5, %l2, %o5
a015a75c:  82 20 40 1c  sub  %g1, %i4, %g1
a015a760:  80 88 40 0d  btst  %g1, %o5
a015a764:  16 80 00 0c  bge  0xa015a794
a015a768:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a015a76c:  80 a7 00 12  cmp  %i4, %l2
a015a770:  04 80 00 03  ble  0xa015a77c
a015a774:  b2 10 00 1c  mov  %i4, %i1
a015a778:  b2 10 00 12  mov  %l2, %i1
a015a77c:  d8 07 bf ec  ld  [ %fp + -20 ], %o4
a015a780:  98 23 00 19  sub  %o4, %i1, %o4
a015a784:  b8 27 00 19  sub  %i4, %i1, %i4
a015a788:  d8 27 bf ec  st  %o4, [ %fp + -20 ]
a015a78c:  a4 24 80 19  sub  %l2, %i1, %l2
a015a790:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a015a794:  80 a3 60 00  cmp  %o5, 0
a015a798:  04 80 00 18  ble  0xa015a7f8
a015a79c:  c2 07 bf d0  ld  [ %fp + -48 ], %g1
a015a7a0:  80 a0 60 00  cmp  %g1, 0
a015a7a4:  02 80 02 77  be  0xa015b180
a015a7a8:  80 a4 60 00  cmp  %l1, 0
a015a7ac:  04 80 00 0f  ble  0xa015a7e8
a015a7b0:  94 10 00 11  mov  %l1, %o2
a015a7b4:  d2 07 bf bc  ld  [ %fp + -68 ], %o1
a015a7b8:  40 00 0a b4  call  0xa015d288
a015a7bc:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015a7c0:  d0 27 bf bc  st  %o0, [ %fp + -68 ]
a015a7c4:  d2 07 bf bc  ld  [ %fp + -68 ], %o1
a015a7c8:  d4 07 bf c4  ld  [ %fp + -60 ], %o2
a015a7cc:  40 00 0a 28  call  0xa015d06c
a015a7d0:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015a7d4:  a0 10 00 08  mov  %o0, %l0
a015a7d8:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015a7dc:  40 00 09 53  call  0xa015cd28
a015a7e0:  d2 07 bf c4  ld  [ %fp + -60 ], %o1
a015a7e4:  e0 27 bf c4  st  %l0, [ %fp + -60 ]
a015a7e8:  d6 07 bf e8  ld  [ %fp + -24 ], %o3
a015a7ec:  a0 a2 c0 11  subcc  %o3, %l1, %l0
a015a7f0:  12 80 02 7d  bne  0xa015b1e4
a015a7f4:  d2 07 bf c4  ld  [ %fp + -60 ], %o1
a015a7f8:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015a7fc:  40 00 0a 13  call  0xa015d048
a015a800:  92 10 20 01  mov  1, %o1
a015a804:  d8 07 bf cc  ld  [ %fp + -52 ], %o4
a015a808:  80 a3 20 00  cmp  %o4, 0
a015a80c:  04 80 00 07  ble  0xa015a828
a015a810:  b4 10 00 08  mov  %o0, %i2
a015a814:  92 10 00 08  mov  %o0, %o1
a015a818:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015a81c:  40 00 0a 9b  call  0xa015d288
a015a820:  94 10 00 0c  mov  %o4, %o2
a015a824:  b4 10 00 08  mov  %o0, %i2
a015a828:  80 a6 e0 01  cmp  %i3, 1
a015a82c:  04 80 02 5b  ble  0xa015b198
a015a830:  a0 10 20 00  clr  %l0
a015a834:  82 07 20 01  add  %i4, 1, %g1
a015a838:  d6 07 bf cc  ld  [ %fp + -52 ], %o3
a015a83c:  80 a2 e0 00  cmp  %o3, 0
a015a840:  12 80 02 43  bne  0xa015b14c
a015a844:  b2 08 60 1f  and  %g1, 0x1f, %i1
a015a848:  80 a6 60 00  cmp  %i1, 0
a015a84c:  02 80 00 05  be  0xa015a860
a015a850:  80 a6 60 04  cmp  %i1, 4
a015a854:  82 10 20 20  mov  0x20, %g1
a015a858:  b2 20 40 19  sub  %g1, %i1, %i1
a015a85c:  80 a6 60 04  cmp  %i1, 4
a015a860:  04 80 01 17  ble  0xa015acbc
a015a864:  80 a6 60 03  cmp  %i1, 3
a015a868:  b2 06 7f fc  add  %i1, -4, %i1
a015a86c:  d8 07 bf ec  ld  [ %fp + -20 ], %o4
a015a870:  98 03 00 19  add  %o4, %i1, %o4
a015a874:  b8 07 00 19  add  %i4, %i1, %i4
a015a878:  d8 27 bf ec  st  %o4, [ %fp + -20 ]
a015a87c:  a4 04 80 19  add  %l2, %i1, %l2
a015a880:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a015a884:  80 a0 60 00  cmp  %g1, 0
a015a888:  04 80 00 06  ble  0xa015a8a0
a015a88c:  d2 07 bf c4  ld  [ %fp + -60 ], %o1
a015a890:  94 10 00 01  mov  %g1, %o2
a015a894:  40 00 0a c7  call  0xa015d3b0
a015a898:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015a89c:  d0 27 bf c4  st  %o0, [ %fp + -60 ]
a015a8a0:  80 a7 20 00  cmp  %i4, 0
a015a8a4:  04 80 00 06  ble  0xa015a8bc
a015a8a8:  92 10 00 1a  mov  %i2, %o1
a015a8ac:  94 10 00 1c  mov  %i4, %o2
a015a8b0:  40 00 0a c0  call  0xa015d3b0
a015a8b4:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015a8b8:  b4 10 00 08  mov  %o0, %i2
a015a8bc:  d6 07 bf d4  ld  [ %fp + -44 ], %o3
a015a8c0:  80 a2 e0 00  cmp  %o3, 0
a015a8c4:  12 80 02 07  bne  0xa015b0e0
a015a8c8:  d0 07 bf c4  ld  [ %fp + -60 ], %o0
a015a8cc:  d6 07 bf e4  ld  [ %fp + -28 ], %o3
a015a8d0:  82 02 ff ff  add  %o3, -1, %g1
a015a8d4:  82 12 c0 01  or  %o3, %g1, %g1
a015a8d8:  83 30 60 1f  srl  %g1, 0x1f, %g1
a015a8dc:  80 a6 e0 02  cmp  %i3, 2
a015a8e0:  14 80 00 03  bg  0xa015a8ec
a015a8e4:  9a 10 20 01  mov  1, %o5
a015a8e8:  9a 10 20 00  clr  %o5
a015a8ec:  80 88 40 0d  btst  %g1, %o5
a015a8f0:  02 80 00 fb  be  0xa015acdc
a015a8f4:  d8 07 bf d0  ld  [ %fp + -48 ], %o4
a015a8f8:  d8 07 bf e4  ld  [ %fp + -28 ], %o4
a015a8fc:  80 a3 20 00  cmp  %o4, 0
a015a900:  06 bf ff 8b  bl  0xa015a72c
a015a904:  92 10 00 1a  mov  %i2, %o1
a015a908:  94 10 20 05  mov  5, %o2
a015a90c:  96 10 20 00  clr  %o3
a015a910:  40 00 09 11  call  0xa015cd54
a015a914:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015a918:  b4 10 00 08  mov  %o0, %i2
a015a91c:  d0 07 bf c4  ld  [ %fp + -60 ], %o0
a015a920:  40 00 0a e9  call  0xa015d4c4
a015a924:  92 10 00 1a  mov  %i2, %o1
a015a928:  80 a2 20 00  cmp  %o0, 0
a015a92c:  14 bf ff 26  bg  0xa015a5c4
a015a930:  d6 07 bf b8  ld  [ %fp + -72 ], %o3
a015a934:  da 07 a0 54  ld  [ %fp + 0x54 ], %o5
a015a938:  10 bf ff 27  b  0xa015a5d4
a015a93c:  ba 38 00 0d  xnor  %g0, %o5, %i5
a015a940:  94 10 00 08  mov  %o0, %o2
a015a944:  96 10 00 09  mov  %o1, %o3
a015a948:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015a94c:  7f ff ee 03  call  0xa0156158
a015a950:  d0 18 60 d0  ldd  [ %g1 + 0xd0 ], %o0	! 0x1a84d0
a015a954:  98 10 00 08  mov  %o0, %o4
a015a958:  90 10 00 0c  mov  %o4, %o0
a015a95c:  a8 10 00 0c  mov  %o4, %l4
a015a960:  9a 10 00 09  mov  %o1, %o5
a015a964:  19 00 06 a0  sethi  %hi(0x1a8000), %o4
a015a968:  aa 10 00 0d  mov  %o5, %l5
a015a96c:  7f ff ef 51  call  0xa01566b0
a015a970:  d4 1b 22 08  ldd  [ %o4 + 0x208 ], %o2
a015a974:  80 a2 20 00  cmp  %o0, 0
a015a978:  02 bf ff 2b  be  0xa015a624
a015a97c:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015a980:  b2 06 60 01  inc  %i1
a015a984:  94 10 00 12  mov  %l2, %o2
a015a988:  96 10 00 13  mov  %l3, %o3
a015a98c:  90 10 00 14  mov  %l4, %o0
a015a990:  7f ff ee c8  call  0xa01564b0
a015a994:  92 10 00 15  mov  %l5, %o1
a015a998:  7f ff ef eb  call  0xa0156944
a015a99c:  01 00 00 00  nop
a015a9a0:  7f ff ef a8  call  0xa0156840
a015a9a4:  b4 10 00 08  mov  %o0, %i2
a015a9a8:  94 10 00 12  mov  %l2, %o2
a015a9ac:  7f ff ed eb  call  0xa0156158
a015a9b0:  96 10 00 13  mov  %l3, %o3
a015a9b4:  96 10 00 09  mov  %o1, %o3
a015a9b8:  94 10 00 08  mov  %o0, %o2
a015a9bc:  90 10 00 14  mov  %l4, %o0
a015a9c0:  7f ff ed cf  call  0xa01560fc
a015a9c4:  92 10 00 15  mov  %l5, %o1
a015a9c8:  82 06 a0 30  add  %i2, 0x30, %g1
a015a9cc:  c2 2e 00 00  stb  %g1, [ %i0 ]
a015a9d0:  d6 07 bf e4  ld  [ %fp + -28 ], %o3
a015a9d4:  80 a6 40 0b  cmp  %i1, %o3
a015a9d8:  12 bf ff da  bne  0xa015a940
a015a9dc:  b0 06 20 01  inc  %i0
a015a9e0:  94 10 00 08  mov  %o0, %o2
a015a9e4:  7f ff ed b2  call  0xa01560ac
a015a9e8:  96 10 00 09  mov  %o1, %o3
a015a9ec:  a0 10 00 08  mov  %o0, %l0
a015a9f0:  a2 10 00 09  mov  %o1, %l1
a015a9f4:  90 10 00 12  mov  %l2, %o0
a015a9f8:  92 10 00 13  mov  %l3, %o1
a015a9fc:  94 10 00 10  mov  %l0, %o2
a015aa00:  40 00 0f 5d  call  0xa015e774
a015aa04:  96 10 00 11  mov  %l1, %o3
a015aa08:  80 a2 20 00  cmp  %o0, 0
a015aa0c:  06 80 00 0c  bl  0xa015aa3c
a015aa10:  90 10 00 12  mov  %l2, %o0
a015aa14:  92 10 00 13  mov  %l3, %o1
a015aa18:  94 10 00 10  mov  %l0, %o2
a015aa1c:  7f ff ef 25  call  0xa01566b0
a015aa20:  96 10 00 11  mov  %l1, %o3
a015aa24:  80 a2 20 00  cmp  %o0, 0
a015aa28:  12 bf fe ff  bne  0xa015a624
a015aa2c:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015aa30:  80 8e a0 01  btst  1, %i2
a015aa34:  02 bf fe fc  be  0xa015a624
a015aa38:  01 00 00 00  nop
a015aa3c:  b0 06 3f ff  add  %i0, -1, %i0
a015aa40:  c2 4e 00 00  ldsb  [ %i0 ], %g1
a015aa44:  80 a0 60 39  cmp  %g1, 0x39
a015aa48:  12 80 00 09  bne  0xa015aa6c
a015aa4c:  d8 07 bf b8  ld  [ %fp + -72 ], %o4
a015aa50:  80 a6 00 0c  cmp  %i0, %o4
a015aa54:  32 bf ff fb  bne,a   0xa015aa40
a015aa58:  b0 06 3f ff  add  %i0, -1, %i0
a015aa5c:  82 10 20 30  mov  0x30, %g1
a015aa60:  da 07 bf b8  ld  [ %fp + -72 ], %o5
a015aa64:  c2 2b 40 00  stb  %g1, [ %o5 ]
a015aa68:  ba 07 60 01  inc  %i5
a015aa6c:  c2 0e 00 00  ldub  [ %i0 ], %g1
a015aa70:  82 00 60 01  inc  %g1
a015aa74:  c2 2e 00 00  stb  %g1, [ %i0 ]
a015aa78:  10 bf fe ea  b  0xa015a620
a015aa7c:  b0 06 20 01  inc  %i0
a015aa80:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015aa84:  90 10 00 14  mov  %l4, %o0
a015aa88:  92 10 00 15  mov  %l5, %o1
a015aa8c:  7f ff ee 89  call  0xa01564b0
a015aa90:  d4 18 61 70  ldd  [ %g1 + 0x170 ], %o2
a015aa94:  a8 10 00 08  mov  %o0, %l4
a015aa98:  aa 10 00 09  mov  %o1, %l5
a015aa9c:  a0 0c 20 0f  and  %l0, 0xf, %l0
a015aaa0:  10 bf fe 70  b  0xa015a460
a015aaa4:  a2 10 20 03  mov  3, %l1
a015aaa8:  80 a6 e0 01  cmp  %i3, 1
a015aaac:  04 80 01 d2  ble  0xa015b1f4
a015aab0:  d6 07 bf e4  ld  [ %fp + -28 ], %o3
a015aab4:  a0 02 ff ff  add  %o3, -1, %l0
a015aab8:  d8 07 bf e8  ld  [ %fp + -24 ], %o4
a015aabc:  80 a3 00 10  cmp  %o4, %l0
a015aac0:  16 80 00 09  bge  0xa015aae4
a015aac4:  a2 23 00 10  sub  %o4, %l0, %l1
a015aac8:  a0 24 00 0c  sub  %l0, %o4, %l0
a015aacc:  da 07 bf cc  ld  [ %fp + -52 ], %o5
a015aad0:  98 03 00 10  add  %o4, %l0, %o4
a015aad4:  9a 03 40 10  add  %o5, %l0, %o5
a015aad8:  d8 27 bf e8  st  %o4, [ %fp + -24 ]
a015aadc:  da 27 bf cc  st  %o5, [ %fp + -52 ]
a015aae0:  a2 10 20 00  clr  %l1
a015aae4:  f2 07 bf e4  ld  [ %fp + -28 ], %i1
a015aae8:  80 a6 60 00  cmp  %i1, 0
a015aaec:  06 80 01 e1  bl  0xa015b270
a015aaf0:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a015aaf4:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015aaf8:  40 00 09 54  call  0xa015d048
a015aafc:  92 10 20 01  mov  1, %o1
a015ab00:  d6 07 bf ec  ld  [ %fp + -20 ], %o3
a015ab04:  96 02 c0 19  add  %o3, %i1, %o3
a015ab08:  d0 27 bf bc  st  %o0, [ %fp + -68 ]
a015ab0c:  b8 07 00 19  add  %i4, %i1, %i4
a015ab10:  10 bf ff 10  b  0xa015a750
a015ab14:  d6 27 bf ec  st  %o3, [ %fp + -20 ]
a015ab18:  c0 27 bf d0  clr  [ %fp + -48 ]
a015ab1c:  d8 07 a0 54  ld  [ %fp + 0x54 ], %o4
a015ab20:  80 a3 20 00  cmp  %o4, 0
a015ab24:  04 80 01 b2  ble  0xa015b1ec
a015ab28:  9a 10 20 01  mov  1, %o5
a015ab2c:  f2 07 a0 54  ld  [ %fp + 0x54 ], %i1
a015ab30:  f2 27 bf dc  st  %i1, [ %fp + -36 ]
a015ab34:  10 bf fe 21  b  0xa015a3b8
a015ab38:  f2 27 bf e4  st  %i1, [ %fp + -28 ]
a015ab3c:  b2 10 20 12  mov  0x12, %i1
a015ab40:  10 bf fe 1e  b  0xa015a3b8
a015ab44:  c0 27 a0 54  clr  [ %fp + 0x54 ]
a015ab48:  d6 07 bf d0  ld  [ %fp + -48 ], %o3
a015ab4c:  80 a2 e0 00  cmp  %o3, 0
a015ab50:  02 80 00 f9  be  0xa015af34
a015ab54:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a015ab58:  d8 07 bf e4  ld  [ %fp + -28 ], %o4
a015ab5c:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015ab60:  9b 2b 20 03  sll  %o4, 3, %o5
a015ab64:  82 10 61 78  or  %g1, 0x178, %g1
a015ab68:  9a 03 40 01  add  %o5, %g1, %o5
a015ab6c:  d4 1b 7f f8  ldd  [ %o5 + -8 ], %o2
a015ab70:  1b 00 06 69  sethi  %hi(0x19a400), %o5
a015ab74:  7f ff ee 4f  call  0xa01564b0
a015ab78:  d0 1b 62 38  ldd  [ %o5 + 0x238 ], %o0	! 0x19a638
a015ab7c:  94 10 00 12  mov  %l2, %o2
a015ab80:  7f ff ed 5f  call  0xa01560fc
a015ab84:  96 10 00 13  mov  %l3, %o3
a015ab88:  a4 10 00 08  mov  %o0, %l2
a015ab8c:  a6 10 00 09  mov  %o1, %l3
a015ab90:  10 80 00 0f  b  0xa015abcc
a015ab94:  b2 10 20 00  clr  %i1
a015ab98:  94 10 00 12  mov  %l2, %o2
a015ab9c:  96 10 00 13  mov  %l3, %o3
a015aba0:  7f ff ed 6e  call  0xa0156158
a015aba4:  d0 1b 20 d0  ldd  [ %o4 + 0xd0 ], %o0
a015aba8:  1b 00 06 a1  sethi  %hi(0x1a8400), %o5
a015abac:  a4 10 00 08  mov  %o0, %l2
a015abb0:  a6 10 00 09  mov  %o1, %l3
a015abb4:  94 10 00 10  mov  %l0, %o2
a015abb8:  96 10 00 11  mov  %l1, %o3
a015abbc:  7f ff ed 67  call  0xa0156158
a015abc0:  d0 1b 60 d0  ldd  [ %o5 + 0xd0 ], %o0
a015abc4:  a8 10 00 08  mov  %o0, %l4
a015abc8:  aa 10 00 09  mov  %o1, %l5
a015abcc:  92 10 00 15  mov  %l5, %o1
a015abd0:  7f ff ef 5d  call  0xa0156944
a015abd4:  90 10 00 14  mov  %l4, %o0
a015abd8:  7f ff ef 1a  call  0xa0156840
a015abdc:  b4 10 00 08  mov  %o0, %i2
a015abe0:  94 10 00 08  mov  %o0, %o2
a015abe4:  96 10 00 09  mov  %o1, %o3
a015abe8:  90 10 00 14  mov  %l4, %o0
a015abec:  7f ff ed 44  call  0xa01560fc
a015abf0:  92 10 00 15  mov  %l5, %o1
a015abf4:  82 06 a0 30  add  %i2, 0x30, %g1
a015abf8:  a0 10 00 08  mov  %o0, %l0
a015abfc:  c2 2e 00 00  stb  %g1, [ %i0 ]
a015ac00:  a2 10 00 09  mov  %o1, %l1
a015ac04:  90 10 00 10  mov  %l0, %o0
a015ac08:  94 10 00 12  mov  %l2, %o2
a015ac0c:  40 00 0e da  call  0xa015e774
a015ac10:  96 10 00 13  mov  %l3, %o3
a015ac14:  80 a2 20 00  cmp  %o0, 0
a015ac18:  06 bf fe 82  bl  0xa015a620
a015ac1c:  b0 06 20 01  inc  %i0
a015ac20:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a015ac24:  94 10 00 10  mov  %l0, %o2
a015ac28:  96 10 00 11  mov  %l1, %o3
a015ac2c:  7f ff ed 34  call  0xa01560fc
a015ac30:  d0 18 62 30  ldd  [ %g1 + 0x230 ], %o0
a015ac34:  94 10 00 12  mov  %l2, %o2
a015ac38:  40 00 0e cf  call  0xa015e774
a015ac3c:  96 10 00 13  mov  %l3, %o3
a015ac40:  80 a2 20 00  cmp  %o0, 0
a015ac44:  26 bf ff 7f  bl,a   0xa015aa40
a015ac48:  b0 06 3f ff  add  %i0, -1, %i0
a015ac4c:  b2 06 60 01  inc  %i1
a015ac50:  d6 07 bf e4  ld  [ %fp + -28 ], %o3
a015ac54:  80 a6 40 0b  cmp  %i1, %o3
a015ac58:  06 bf ff d0  bl  0xa015ab98
a015ac5c:  19 00 06 a1  sethi  %hi(0x1a8400), %o4
a015ac60:  10 bf fe 88  b  0xa015a680
a015ac64:  d6 07 bf e0  ld  [ %fp + -32 ], %o3
a015ac68:  7f ff ee f6  call  0xa0156840
a015ac6c:  90 10 00 1d  mov  %i5, %o0
a015ac70:  94 10 00 12  mov  %l2, %o2
a015ac74:  7f ff ee a8  call  0xa0156714
a015ac78:  96 10 00 13  mov  %l3, %o3
a015ac7c:  80 a0 00 08  cmp  %g0, %o0
a015ac80:  10 bf fd 5a  b  0xa015a1e8
a015ac84:  ba 67 60 00  subx  %i5, 0, %i5
a015ac88:  98 23 00 1d  sub  %o4, %i5, %o4
a015ac8c:  9a 20 00 1d  neg  %i5, %o5
a015ac90:  d8 27 bf ec  st  %o4, [ %fp + -20 ]
a015ac94:  da 27 bf e8  st  %o5, [ %fp + -24 ]
a015ac98:  10 bf fd 71  b  0xa015a25c
a015ac9c:  c0 27 bf cc  clr  [ %fp + -52 ]
a015aca0:  e0 27 bf ec  st  %l0, [ %fp + -20 ]
a015aca4:  10 bf fd 68  b  0xa015a244
a015aca8:  b8 10 20 00  clr  %i4
a015acac:  40 00 08 1f  call  0xa015cd28
a015acb0:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015acb4:  10 bf fe 59  b  0xa015a618
a015acb8:  d2 07 bf bc  ld  [ %fp + -68 ], %o1
a015acbc:  14 bf fe f2  bg  0xa015a884
a015acc0:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a015acc4:  b2 06 60 1c  add  %i1, 0x1c, %i1
a015acc8:  da 07 bf ec  ld  [ %fp + -20 ], %o5
a015accc:  9a 03 40 19  add  %o5, %i1, %o5
a015acd0:  b8 07 00 19  add  %i4, %i1, %i4
a015acd4:  10 bf fe ea  b  0xa015a87c
a015acd8:  da 27 bf ec  st  %o5, [ %fp + -20 ]
a015acdc:  80 a3 20 00  cmp  %o4, 0
a015ace0:  02 80 00 55  be  0xa015ae34
a015ace4:  b2 10 20 01  mov  1, %i1
a015ace8:  80 a4 a0 00  cmp  %l2, 0
a015acec:  04 80 00 06  ble  0xa015ad04
a015acf0:  d2 07 bf bc  ld  [ %fp + -68 ], %o1
a015acf4:  94 10 00 12  mov  %l2, %o2
a015acf8:  40 00 09 ae  call  0xa015d3b0
a015acfc:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015ad00:  d0 27 bf bc  st  %o0, [ %fp + -68 ]
a015ad04:  da 07 bf bc  ld  [ %fp + -68 ], %o5
a015ad08:  80 a4 20 00  cmp  %l0, 0
a015ad0c:  12 80 00 6b  bne  0xa015aeb8
a015ad10:  da 27 bf c0  st  %o5, [ %fp + -64 ]
a015ad14:  b2 10 20 01  mov  1, %i1
a015ad18:  92 10 00 1a  mov  %i2, %o1
a015ad1c:  7f ff fc 49  call  0xa0159e40
a015ad20:  d0 07 bf c4  ld  [ %fp + -60 ], %o0
a015ad24:  a6 02 20 30  add  %o0, 0x30, %l3
a015ad28:  d2 07 bf c0  ld  [ %fp + -64 ], %o1
a015ad2c:  40 00 09 e6  call  0xa015d4c4
a015ad30:  d0 07 bf c4  ld  [ %fp + -60 ], %o0
a015ad34:  a0 10 00 08  mov  %o0, %l0
a015ad38:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015ad3c:  92 10 00 1a  mov  %i2, %o1
a015ad40:  40 00 09 fb  call  0xa015d52c
a015ad44:  d4 07 bf bc  ld  [ %fp + -68 ], %o2
a015ad48:  c2 02 20 0c  ld  [ %o0 + 0xc ], %g1
a015ad4c:  a2 10 00 08  mov  %o0, %l1
a015ad50:  80 a0 60 00  cmp  %g1, 0
a015ad54:  02 80 00 6a  be  0xa015aefc
a015ad58:  a4 10 20 01  mov  1, %l2
a015ad5c:  92 10 00 11  mov  %l1, %o1
a015ad60:  40 00 07 f2  call  0xa015cd28
a015ad64:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015ad68:  80 94 80 1b  orcc  %l2, %i3, %g0
a015ad6c:  12 80 00 05  bne  0xa015ad80
a015ad70:  80 a4 20 00  cmp  %l0, 0
a015ad74:  80 8d 60 01  btst  1, %l5
a015ad78:  02 80 01 51  be  0xa015b2bc
a015ad7c:  80 a4 20 00  cmp  %l0, 0
a015ad80:  06 80 01 25  bl  0xa015b214
a015ad84:  80 94 00 1b  orcc  %l0, %i3, %g0
a015ad88:  12 80 00 05  bne  0xa015ad9c
a015ad8c:  80 a4 a0 00  cmp  %l2, 0
a015ad90:  80 8d 60 01  btst  1, %l5
a015ad94:  02 80 01 20  be  0xa015b214
a015ad98:  80 a4 a0 00  cmp  %l2, 0
a015ad9c:  14 80 01 43  bg  0xa015b2a8
a015ada0:  80 a4 e0 39  cmp  %l3, 0x39
a015ada4:  e6 2e 00 00  stb  %l3, [ %i0 ]
a015ada8:  d6 07 bf e4  ld  [ %fp + -28 ], %o3
a015adac:  80 a6 40 0b  cmp  %i1, %o3
a015adb0:  02 80 00 2a  be  0xa015ae58
a015adb4:  b0 06 20 01  inc  %i0
a015adb8:  d2 07 bf c4  ld  [ %fp + -60 ], %o1
a015adbc:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015adc0:  94 10 20 0a  mov  0xa, %o2
a015adc4:  40 00 07 e4  call  0xa015cd54
a015adc8:  96 10 20 00  clr  %o3
a015adcc:  d8 07 bf c0  ld  [ %fp + -64 ], %o4
a015add0:  da 07 bf bc  ld  [ %fp + -68 ], %o5
a015add4:  80 a3 00 0d  cmp  %o4, %o5
a015add8:  02 80 00 4e  be  0xa015af10
a015addc:  d0 27 bf c4  st  %o0, [ %fp + -60 ]
a015ade0:  d2 07 bf c0  ld  [ %fp + -64 ], %o1
a015ade4:  94 10 20 0a  mov  0xa, %o2
a015ade8:  96 10 20 00  clr  %o3
a015adec:  40 00 07 da  call  0xa015cd54
a015adf0:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015adf4:  d0 27 bf c0  st  %o0, [ %fp + -64 ]
a015adf8:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015adfc:  d2 07 bf bc  ld  [ %fp + -68 ], %o1
a015ae00:  94 10 20 0a  mov  0xa, %o2
a015ae04:  40 00 07 d4  call  0xa015cd54
a015ae08:  96 10 20 00  clr  %o3
a015ae0c:  d0 27 bf bc  st  %o0, [ %fp + -68 ]
a015ae10:  10 bf ff c2  b  0xa015ad18
a015ae14:  b2 06 60 01  inc  %i1
a015ae18:  d2 07 bf c4  ld  [ %fp + -60 ], %o1
a015ae1c:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015ae20:  94 10 20 0a  mov  0xa, %o2
a015ae24:  40 00 07 cc  call  0xa015cd54
a015ae28:  96 10 20 00  clr  %o3
a015ae2c:  d0 27 bf c4  st  %o0, [ %fp + -60 ]
a015ae30:  b2 06 60 01  inc  %i1
a015ae34:  d0 07 bf c4  ld  [ %fp + -60 ], %o0
a015ae38:  7f ff fc 02  call  0xa0159e40
a015ae3c:  92 10 00 1a  mov  %i2, %o1
a015ae40:  a6 02 20 30  add  %o0, 0x30, %l3
a015ae44:  e6 2e 00 00  stb  %l3, [ %i0 ]
a015ae48:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a015ae4c:  80 a6 40 01  cmp  %i1, %g1
a015ae50:  06 bf ff f2  bl  0xa015ae18
a015ae54:  b0 06 20 01  inc  %i0
a015ae58:  d2 07 bf c4  ld  [ %fp + -60 ], %o1
a015ae5c:  94 10 20 01  mov  1, %o2
a015ae60:  40 00 09 54  call  0xa015d3b0
a015ae64:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015ae68:  d0 27 bf c4  st  %o0, [ %fp + -60 ]
a015ae6c:  40 00 09 96  call  0xa015d4c4
a015ae70:  92 10 00 1a  mov  %i2, %o1
a015ae74:  a0 92 20 00  orcc  %o0, 0, %l0
a015ae78:  04 80 01 01  ble  0xa015b27c
a015ae7c:  80 a4 20 00  cmp  %l0, 0
a015ae80:  b0 06 3f ff  add  %i0, -1, %i0
a015ae84:  c2 4e 00 00  ldsb  [ %i0 ], %g1
a015ae88:  80 a0 60 39  cmp  %g1, 0x39
a015ae8c:  12 80 00 b8  bne  0xa015b16c
a015ae90:  d6 07 bf b8  ld  [ %fp + -72 ], %o3
a015ae94:  80 a6 00 0b  cmp  %i0, %o3
a015ae98:  32 bf ff fb  bne,a   0xa015ae84
a015ae9c:  b0 06 3f ff  add  %i0, -1, %i0
a015aea0:  d8 07 bf b8  ld  [ %fp + -72 ], %o4
a015aea4:  82 10 20 31  mov  0x31, %g1
a015aea8:  c2 2b 00 00  stb  %g1, [ %o4 ]
a015aeac:  ba 07 60 01  inc  %i5
a015aeb0:  10 bf fd c9  b  0xa015a5d4
a015aeb4:  b0 03 20 01  add  %o4, 1, %i0
a015aeb8:  d2 03 60 04  ld  [ %o5 + 4 ], %o1
a015aebc:  40 00 07 72  call  0xa015cc84
a015aec0:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015aec4:  c2 07 bf c0  ld  [ %fp + -64 ], %g1
a015aec8:  d4 00 60 10  ld  [ %g1 + 0x10 ], %o2
a015aecc:  d0 27 bf bc  st  %o0, [ %fp + -68 ]
a015aed0:  95 2a a0 02  sll  %o2, 2, %o2
a015aed4:  92 00 60 0c  add  %g1, 0xc, %o1
a015aed8:  94 02 a0 08  add  %o2, 8, %o2
a015aedc:  7f ff 86 8d  call  0xa013c910
a015aee0:  90 02 20 0c  add  %o0, 0xc, %o0
a015aee4:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015aee8:  d2 07 bf bc  ld  [ %fp + -68 ], %o1
a015aeec:  40 00 09 31  call  0xa015d3b0
a015aef0:  94 10 20 01  mov  1, %o2
a015aef4:  10 bf ff 88  b  0xa015ad14
a015aef8:  d0 27 bf bc  st  %o0, [ %fp + -68 ]
a015aefc:  d0 07 bf c4  ld  [ %fp + -60 ], %o0
a015af00:  40 00 09 71  call  0xa015d4c4
a015af04:  92 10 00 11  mov  %l1, %o1
a015af08:  10 bf ff 95  b  0xa015ad5c
a015af0c:  a4 10 00 08  mov  %o0, %l2
a015af10:  92 10 00 0d  mov  %o5, %o1
a015af14:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015af18:  94 10 20 0a  mov  0xa, %o2
a015af1c:  40 00 07 8e  call  0xa015cd54
a015af20:  96 10 20 00  clr  %o3
a015af24:  d0 27 bf bc  st  %o0, [ %fp + -68 ]
a015af28:  d0 27 bf c0  st  %o0, [ %fp + -64 ]
a015af2c:  10 bf ff 7b  b  0xa015ad18
a015af30:  b2 06 60 01  inc  %i1
a015af34:  9b 28 60 03  sll  %g1, 3, %o5
a015af38:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015af3c:  82 10 61 78  or  %g1, 0x178, %g1	! 0x1a8578
a015af40:  9a 03 40 01  add  %o5, %g1, %o5
a015af44:  96 10 00 09  mov  %o1, %o3
a015af48:  94 10 00 12  mov  %l2, %o2
a015af4c:  7f ff ec 83  call  0xa0156158
a015af50:  d0 1b 7f f8  ldd  [ %o5 + -8 ], %o0
a015af54:  a4 10 00 08  mov  %o0, %l2
a015af58:  a6 10 00 09  mov  %o1, %l3
a015af5c:  10 80 00 0a  b  0xa015af84
a015af60:  b2 10 20 01  mov  1, %i1
a015af64:  96 10 00 09  mov  %o1, %o3
a015af68:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015af6c:  94 10 00 10  mov  %l0, %o2
a015af70:  7f ff ec 7a  call  0xa0156158
a015af74:  d0 18 60 d0  ldd  [ %g1 + 0xd0 ], %o0
a015af78:  a8 10 00 08  mov  %o0, %l4
a015af7c:  aa 10 00 09  mov  %o1, %l5
a015af80:  b2 06 60 01  inc  %i1
a015af84:  92 10 00 15  mov  %l5, %o1
a015af88:  7f ff ee 6f  call  0xa0156944
a015af8c:  90 10 00 14  mov  %l4, %o0
a015af90:  7f ff ee 2c  call  0xa0156840
a015af94:  b4 10 00 08  mov  %o0, %i2
a015af98:  96 10 00 09  mov  %o1, %o3
a015af9c:  94 10 00 08  mov  %o0, %o2
a015afa0:  90 10 00 14  mov  %l4, %o0
a015afa4:  7f ff ec 56  call  0xa01560fc
a015afa8:  92 10 00 15  mov  %l5, %o1
a015afac:  82 06 a0 30  add  %i2, 0x30, %g1
a015afb0:  c2 2e 00 00  stb  %g1, [ %i0 ]
a015afb4:  d6 07 bf e4  ld  [ %fp + -28 ], %o3
a015afb8:  a0 10 00 08  mov  %o0, %l0
a015afbc:  a2 10 00 09  mov  %o1, %l1
a015afc0:  80 a6 40 0b  cmp  %i1, %o3
a015afc4:  12 bf ff e8  bne  0xa015af64
a015afc8:  b0 06 20 01  inc  %i0
a015afcc:  19 00 06 69  sethi  %hi(0x19a400), %o4
a015afd0:  94 10 00 12  mov  %l2, %o2
a015afd4:  96 10 00 13  mov  %l3, %o3
a015afd8:  7f ff ec 35  call  0xa01560ac
a015afdc:  d0 1b 22 38  ldd  [ %o4 + 0x238 ], %o0
a015afe0:  94 10 00 10  mov  %l0, %o2
a015afe4:  40 00 0d e4  call  0xa015e774
a015afe8:  96 10 00 11  mov  %l1, %o3
a015afec:  80 a2 20 00  cmp  %o0, 0
a015aff0:  06 bf fe 93  bl  0xa015aa3c
a015aff4:  1b 00 06 69  sethi  %hi(0x19a400), %o5
a015aff8:  94 10 00 12  mov  %l2, %o2
a015affc:  96 10 00 13  mov  %l3, %o3
a015b000:  7f ff ec 3f  call  0xa01560fc
a015b004:  d0 1b 62 38  ldd  [ %o5 + 0x238 ], %o0
a015b008:  94 10 00 10  mov  %l0, %o2
a015b00c:  7f ff ed db  call  0xa0156778
a015b010:  96 10 00 11  mov  %l1, %o3
a015b014:  80 a2 20 00  cmp  %o0, 0
a015b018:  24 bf fd 9a  ble,a   0xa015a680
a015b01c:  d6 07 bf e0  ld  [ %fp + -32 ], %o3
a015b020:  b0 06 3f ff  add  %i0, -1, %i0
a015b024:  c2 4e 00 00  ldsb  [ %i0 ], %g1
a015b028:  80 a0 60 30  cmp  %g1, 0x30
a015b02c:  22 bf ff fe  be,a   0xa015b024
a015b030:  b0 06 3f ff  add  %i0, -1, %i0
a015b034:  10 bf fd 7b  b  0xa015a620
a015b038:  b0 06 20 01  inc  %i0
a015b03c:  a4 a0 00 1d  subcc  %g0, %i5, %l2
a015b040:  02 bf fd 24  be  0xa015a4d0
a015b044:  da 07 bf d4  ld  [ %fp + -44 ], %o5
a015b048:  9a 0c a0 0f  and  %l2, 0xf, %o5
a015b04c:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015b050:  9b 2b 60 03  sll  %o5, 3, %o5
a015b054:  82 10 61 78  or  %g1, 0x178, %g1
a015b058:  96 00 40 0d  add  %g1, %o5, %o3
a015b05c:  d0 1a c0 00  ldd  [ %o3 ], %o0
a015b060:  94 10 00 14  mov  %l4, %o2
a015b064:  7f ff ec 3d  call  0xa0156158
a015b068:  96 10 00 15  mov  %l5, %o3
a015b06c:  a1 3c a0 04  sra  %l2, 4, %l0
a015b070:  a8 10 00 08  mov  %o0, %l4
a015b074:  80 a4 20 00  cmp  %l0, 0
a015b078:  02 bf fd 15  be  0xa015a4cc
a015b07c:  aa 10 00 09  mov  %o1, %l5
a015b080:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015b084:  a4 10 61 50  or  %g1, 0x150, %l2	! 0x1a8550
a015b088:  80 8c 20 01  btst  1, %l0
a015b08c:  22 80 00 0c  be,a   0xa015b0bc
a015b090:  a1 3c 20 01  sra  %l0, 1, %l0
a015b094:  83 2e 60 03  sll  %i1, 3, %g1
a015b098:  98 04 80 01  add  %l2, %g1, %o4
a015b09c:  94 10 00 14  mov  %l4, %o2
a015b0a0:  96 10 00 15  mov  %l5, %o3
a015b0a4:  7f ff ec 2d  call  0xa0156158
a015b0a8:  d0 1b 00 00  ldd  [ %o4 ], %o0
a015b0ac:  a8 10 00 08  mov  %o0, %l4
a015b0b0:  aa 10 00 09  mov  %o1, %l5
a015b0b4:  a2 04 60 01  inc  %l1
a015b0b8:  a1 3c 20 01  sra  %l0, 1, %l0
a015b0bc:  80 a4 20 00  cmp  %l0, 0
a015b0c0:  12 bf ff f2  bne  0xa015b088
a015b0c4:  b2 06 60 01  inc  %i1
a015b0c8:  10 bf fd 02  b  0xa015a4d0
a015b0cc:  da 07 bf d4  ld  [ %fp + -44 ], %o5
a015b0d0:  7f ff eb f7  call  0xa01560ac
a015b0d4:  d4 1b 20 a8  ldd  [ %o4 + 0xa8 ], %o2
a015b0d8:  10 bf fc 1b  b  0xa015a144
a015b0dc:  03 3f 84 00  sethi  %hi(0xfe100000), %g1
a015b0e0:  40 00 08 f9  call  0xa015d4c4
a015b0e4:  92 10 00 1a  mov  %i2, %o1
a015b0e8:  80 a2 20 00  cmp  %o0, 0
a015b0ec:  16 bf fd f9  bge  0xa015a8d0
a015b0f0:  d6 07 bf e4  ld  [ %fp + -28 ], %o3
a015b0f4:  d2 07 bf c4  ld  [ %fp + -60 ], %o1
a015b0f8:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015b0fc:  94 10 20 0a  mov  0xa, %o2
a015b100:  40 00 07 15  call  0xa015cd54
a015b104:  96 10 20 00  clr  %o3
a015b108:  d8 07 bf d0  ld  [ %fp + -48 ], %o4
a015b10c:  d0 27 bf c4  st  %o0, [ %fp + -60 ]
a015b110:  80 a3 20 00  cmp  %o4, 0
a015b114:  12 80 00 05  bne  0xa015b128
a015b118:  ba 07 7f ff  add  %i5, -1, %i5
a015b11c:  da 07 bf dc  ld  [ %fp + -36 ], %o5
a015b120:  10 bf fd eb  b  0xa015a8cc
a015b124:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a015b128:  d2 07 bf bc  ld  [ %fp + -68 ], %o1
a015b12c:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015b130:  94 10 20 0a  mov  0xa, %o2
a015b134:  40 00 07 08  call  0xa015cd54
a015b138:  96 10 20 00  clr  %o3
a015b13c:  da 07 bf dc  ld  [ %fp + -36 ], %o5
a015b140:  d0 27 bf bc  st  %o0, [ %fp + -68 ]
a015b144:  10 bf fd e2  b  0xa015a8cc
a015b148:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a015b14c:  c2 06 a0 10  ld  [ %i2 + 0x10 ], %g1
a015b150:  83 28 60 02  sll  %g1, 2, %g1
a015b154:  82 00 40 1a  add  %g1, %i2, %g1
a015b158:  40 00 07 68  call  0xa015cef8
a015b15c:  d0 00 60 10  ld  [ %g1 + 0x10 ], %o0
a015b160:  90 27 00 08  sub  %i4, %o0, %o0
a015b164:  10 bf fd b9  b  0xa015a848
a015b168:  b2 0a 20 1f  and  %o0, 0x1f, %i1
a015b16c:  c2 0e 00 00  ldub  [ %i0 ], %g1
a015b170:  82 00 60 01  inc  %g1
a015b174:  c2 2e 00 00  stb  %g1, [ %i0 ]
a015b178:  10 bf fd 17  b  0xa015a5d4
a015b17c:  b0 06 20 01  inc  %i0
a015b180:  d2 07 bf c4  ld  [ %fp + -60 ], %o1
a015b184:  d4 07 bf e8  ld  [ %fp + -24 ], %o2
a015b188:  40 00 08 40  call  0xa015d288
a015b18c:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015b190:  10 bf fd 9a  b  0xa015a7f8
a015b194:  d0 27 bf c4  st  %o0, [ %fp + -60 ]
a015b198:  80 a5 60 00  cmp  %l5, 0
a015b19c:  12 bf fd a7  bne  0xa015a838
a015b1a0:  82 07 20 01  add  %i4, 1, %g1
a015b1a4:  03 3f fc 00  sethi  %hi(0xfff00000), %g1
a015b1a8:  80 ad 00 01  andncc  %l4, %g1, %g0
a015b1ac:  12 bf fd a3  bne  0xa015a838
a015b1b0:  82 07 20 01  add  %i4, 1, %g1
a015b1b4:  03 1f fc 00  sethi  %hi(0x7ff00000), %g1
a015b1b8:  80 88 40 14  btst  %g1, %l4
a015b1bc:  02 bf fd 9f  be  0xa015a838
a015b1c0:  82 07 20 01  add  %i4, 1, %g1
a015b1c4:  da 07 bf ec  ld  [ %fp + -20 ], %o5
a015b1c8:  9a 03 60 01  inc  %o5
a015b1cc:  da 27 bf ec  st  %o5, [ %fp + -20 ]
a015b1d0:  b8 07 20 01  inc  %i4
a015b1d4:  10 bf fd 98  b  0xa015a834
a015b1d8:  a0 10 20 01  mov  1, %l0
a015b1dc:  10 bf fc c7  b  0xa015a4f8
a015b1e0:  9a 10 20 01  mov  1, %o5
a015b1e4:  10 bf ff e9  b  0xa015b188
a015b1e8:  94 10 00 10  mov  %l0, %o2
a015b1ec:  10 bf fe 50  b  0xa015ab2c
a015b1f0:  da 27 a0 54  st  %o5, [ %fp + 0x54 ]
a015b1f4:  c2 07 bf c8  ld  [ %fp + -56 ], %g1
a015b1f8:  80 a0 60 00  cmp  %g1, 0
a015b1fc:  12 bf fe 3e  bne  0xa015aaf4
a015b200:  b2 02 24 33  add  %o0, 0x433, %i1
a015b204:  9a 10 20 36  mov  0x36, %o5
a015b208:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a015b20c:  10 bf fe 3a  b  0xa015aaf4
a015b210:  b2 23 40 01  sub  %o5, %g1, %i1
a015b214:  80 a4 a0 00  cmp  %l2, 0
a015b218:  04 80 00 0f  ble  0xa015b254
a015b21c:  d2 07 bf c4  ld  [ %fp + -60 ], %o1
a015b220:  94 10 20 01  mov  1, %o2
a015b224:  40 00 08 63  call  0xa015d3b0
a015b228:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015b22c:  d0 27 bf c4  st  %o0, [ %fp + -60 ]
a015b230:  40 00 08 a5  call  0xa015d4c4
a015b234:  92 10 00 1a  mov  %i2, %o1
a015b238:  a4 92 20 00  orcc  %o0, 0, %l2
a015b23c:  04 80 00 28  ble  0xa015b2dc
a015b240:  80 a4 a0 00  cmp  %l2, 0
a015b244:  a6 04 e0 01  inc  %l3
a015b248:  80 a4 e0 3a  cmp  %l3, 0x3a
a015b24c:  02 80 00 06  be  0xa015b264
a015b250:  82 10 20 39  mov  0x39, %g1
a015b254:  e6 2e 00 00  stb  %l3, [ %i0 ]
a015b258:  10 bf fc df  b  0xa015a5d4
a015b25c:  b0 06 20 01  inc  %i0
a015b260:  82 10 20 39  mov  0x39, %g1
a015b264:  c2 2e 00 00  stb  %g1, [ %i0 ]
a015b268:  10 bf ff 06  b  0xa015ae80
a015b26c:  b0 06 20 01  inc  %i0
a015b270:  a4 20 40 19  sub  %g1, %i1, %l2
a015b274:  10 bf fe 20  b  0xa015aaf4
a015b278:  b2 10 20 00  clr  %i1
a015b27c:  12 80 00 05  bne  0xa015b290
a015b280:  b0 06 3f ff  add  %i0, -1, %i0
a015b284:  80 8c e0 01  btst  1, %l3
a015b288:  12 bf fe ff  bne  0xa015ae84
a015b28c:  01 00 00 00  nop
a015b290:  c2 4e 00 00  ldsb  [ %i0 ], %g1
a015b294:  80 a0 60 30  cmp  %g1, 0x30
a015b298:  22 bf ff fe  be,a   0xa015b290
a015b29c:  b0 06 3f ff  add  %i0, -1, %i0
a015b2a0:  10 bf fc cd  b  0xa015a5d4
a015b2a4:  b0 06 20 01  inc  %i0
a015b2a8:  02 bf ff ee  be  0xa015b260
a015b2ac:  82 04 e0 01  add  %l3, 1, %g1
a015b2b0:  c2 2e 00 00  stb  %g1, [ %i0 ]
a015b2b4:  10 bf fc c8  b  0xa015a5d4
a015b2b8:  b0 06 20 01  inc  %i0
a015b2bc:  80 a4 e0 39  cmp  %l3, 0x39
a015b2c0:  02 bf ff e8  be  0xa015b260
a015b2c4:  83 3c 20 1f  sra  %l0, 0x1f, %g1
a015b2c8:  82 20 40 10  sub  %g1, %l0, %g1
a015b2cc:  83 30 60 1f  srl  %g1, 0x1f, %g1
a015b2d0:  a6 04 c0 01  add  %l3, %g1, %l3
a015b2d4:  10 bf ff e1  b  0xa015b258
a015b2d8:  e6 2e 00 00  stb  %l3, [ %i0 ]
a015b2dc:  32 bf ff df  bne,a   0xa015b258
a015b2e0:  e6 2e 00 00  stb  %l3, [ %i0 ]
a015b2e4:  80 8c e0 01  btst  1, %l3
a015b2e8:  32 bf ff d8  bne,a   0xa015b248
a015b2ec:  a6 04 e0 01  inc  %l3
a015b2f0:  10 bf ff da  b  0xa015b258
a015b2f4:  e6 2e 00 00  stb  %l3, [ %i0 ]
a015b2f8:  81 c7 e0 08  ret
a015b2fc:  91 e8 00 01  restore  %g0, %g1, %o0
