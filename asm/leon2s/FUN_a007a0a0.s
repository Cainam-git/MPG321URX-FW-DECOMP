# leon2s FUN_a007a0a0 0xa007a0a0-0xa007a630 (1424 bytes)
a007a0a0:  9d e3 bf 90  save  %sp, -112, %sp
a007a0a4:  98 10 20 00  clr  %o4
a007a0a8:  9a 10 20 00  clr  %o5
a007a0ac:  17 00 00 08  sethi  %hi(0x2000), %o3
a007a0b0:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a007a0b4:  96 12 e0 34  or  %o3, 0x34, %o3
a007a0b8:  90 10 20 01  mov  1, %o0
a007a0bc:  92 10 20 12  mov  0x12, %o1
a007a0c0:  40 00 b4 d9  call  0xa00a7424
a007a0c4:  94 0e 20 ff  and  %i0, 0xff, %o2
a007a0c8:  a6 10 20 00  clr  %l3
a007a0cc:  a2 10 20 00  clr  %l1
a007a0d0:  83 2c 60 10  sll  %l1, 0x10, %g1
a007a0d4:  99 30 60 10  srl  %g1, 0x10, %o4
a007a0d8:  9a 10 00 13  mov  %l3, %o5
a007a0dc:  9b 2b 60 10  sll  %o5, 0x10, %o5
a007a0e0:  82 0e 60 ff  and  %i1, 0xff, %g1
a007a0e4:  9b 33 60 0f  srl  %o5, 0xf, %o5
a007a0e8:  83 38 40 0c  sra  %g1, %o4, %g1
a007a0ec:  80 88 60 01  btst  1, %g1
a007a0f0:  02 80 00 24  be  0xa007a180
a007a0f4:  9a 07 80 0d  add  %fp, %o5, %o5
a007a0f8:  a0 03 00 0c  add  %o4, %o4, %l0
a007a0fc:  90 10 20 01  mov  1, %o0
a007a100:  92 10 20 12  mov  0x12, %o1
a007a104:  94 0e 20 ff  and  %i0, 0xff, %o2
a007a108:  25 3f ff c0  sethi  %hi(0xffff0000), %l2
a007a10c:  e2 33 7f f0  sth  %l1, [ %o5 + -16 ]
a007a110:  80 a3 20 03  cmp  %o4, 3
a007a114:  18 80 00 1b  bgu  0xa007a180
a007a118:  a6 04 e0 01  inc  %l3
a007a11c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a120:  82 10 63 60  or  %g1, 0x360, %g1	! 0xa00b3b60
a007a124:  40 00 b4 c0  call  0xa00a7424
a007a128:  d6 10 40 10  lduh  [ %g1 + %l0 ], %o3
a007a12c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a130:  82 10 63 58  or  %g1, 0x358, %g1	! 0xa00b3b58
a007a134:  d6 10 40 10  lduh  [ %g1 + %l0 ], %o3
a007a138:  90 10 20 01  mov  1, %o0
a007a13c:  92 10 20 12  mov  0x12, %o1
a007a140:  40 00 b4 b9  call  0xa00a7424
a007a144:  94 0e 20 ff  and  %i0, 0xff, %o2
a007a148:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a14c:  82 10 63 50  or  %g1, 0x350, %g1	! 0xa00b3b50
a007a150:  d2 10 40 10  lduh  [ %g1 + %l0 ], %o1
a007a154:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a158:  94 14 a0 ff  or  %l2, 0xff, %o2
a007a15c:  40 00 b4 cb  call  0xa00a7488
a007a160:  17 00 00 32  sethi  %hi(0xc800), %o3
a007a164:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a168:  82 10 63 48  or  %g1, 0x348, %g1	! 0xa00b3b48
a007a16c:  d2 10 40 10  lduh  [ %g1 + %l0 ], %o1
a007a170:  94 14 a0 ff  or  %l2, 0xff, %o2
a007a174:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a178:  40 00 b4 c4  call  0xa00a7488
a007a17c:  17 00 00 32  sethi  %hi(0xc800), %o3
a007a180:  9a 04 60 01  add  %l1, 1, %o5
a007a184:  83 2b 60 10  sll  %o5, 0x10, %g1
a007a188:  83 30 60 10  srl  %g1, 0x10, %g1
a007a18c:  80 a0 60 03  cmp  %g1, 3
a007a190:  08 bf ff d0  bleu  0xa007a0d0
a007a194:  a2 10 00 0d  mov  %o5, %l1
a007a198:  a3 2c e0 10  sll  %l3, 0x10, %l1
a007a19c:  80 a4 60 00  cmp  %l1, 0
a007a1a0:  02 80 00 bd  be  0xa007a494
a007a1a4:  a4 10 20 00  clr  %l2
a007a1a8:  83 2c a0 10  sll  %l2, 0x10, %g1
a007a1ac:  83 30 60 0f  srl  %g1, 0xf, %g1
a007a1b0:  9a 07 bf f8  add  %fp, -8, %o5
a007a1b4:  a0 00 40 0d  add  %g1, %o5, %l0
a007a1b8:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a1bc:  80 a0 60 03  cmp  %g1, 3
a007a1c0:  38 80 00 0c  bgu,a   0xa007a1f0
a007a1c4:  da 14 3f f8  lduh  [ %l0 + -8 ], %o5
a007a1c8:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a007a1cc:  82 00 40 01  add  %g1, %g1, %g1
a007a1d0:  9a 13 63 40  or  %o5, 0x340, %o5
a007a1d4:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a007a1d8:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a007a1dc:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007a1e0:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a1e4:  40 00 b4 a9  call  0xa00a7488
a007a1e8:  17 22 00 00  sethi  %hi(0x88000000), %o3
a007a1ec:  da 14 3f f8  lduh  [ %l0 + -8 ], %o5
a007a1f0:  80 a3 60 03  cmp  %o5, 3
a007a1f4:  38 80 00 0b  bgu,a   0xa007a220
a007a1f8:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a1fc:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a200:  9a 03 40 0d  add  %o5, %o5, %o5
a007a204:  82 10 63 50  or  %g1, 0x350, %g1
a007a208:  d2 10 40 0d  lduh  [ %g1 + %o5 ], %o1
a007a20c:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a210:  94 10 3f 00  mov  -256, %o2
a007a214:  40 00 b4 9d  call  0xa00a7488
a007a218:  96 10 20 88  mov  0x88, %o3
a007a21c:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a220:  80 a0 60 03  cmp  %g1, 3
a007a224:  38 80 00 0c  bgu,a   0xa007a254
a007a228:  da 14 3f f8  lduh  [ %l0 + -8 ], %o5
a007a22c:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a007a230:  82 00 40 01  add  %g1, %g1, %g1
a007a234:  9a 13 63 38  or  %o5, 0x338, %o5
a007a238:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a007a23c:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a007a240:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007a244:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a248:  40 00 b4 90  call  0xa00a7488
a007a24c:  17 22 00 00  sethi  %hi(0x88000000), %o3
a007a250:  da 14 3f f8  lduh  [ %l0 + -8 ], %o5
a007a254:  80 a3 60 03  cmp  %o5, 3
a007a258:  38 80 00 0b  bgu,a   0xa007a284
a007a25c:  da 14 3f f8  lduh  [ %l0 + -8 ], %o5
a007a260:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a264:  9a 03 40 0d  add  %o5, %o5, %o5
a007a268:  82 10 63 48  or  %g1, 0x348, %g1
a007a26c:  d2 10 40 0d  lduh  [ %g1 + %o5 ], %o1
a007a270:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a274:  94 10 3f 00  mov  -256, %o2
a007a278:  40 00 b4 84  call  0xa00a7488
a007a27c:  96 10 20 88  mov  0x88, %o3
a007a280:  da 14 3f f8  lduh  [ %l0 + -8 ], %o5
a007a284:  80 a3 60 03  cmp  %o5, 3
a007a288:  38 80 00 0b  bgu,a   0xa007a2b4
a007a28c:  da 14 3f f8  lduh  [ %l0 + -8 ], %o5
a007a290:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a294:  9a 03 40 0d  add  %o5, %o5, %o5
a007a298:  82 10 63 30  or  %g1, 0x330, %g1
a007a29c:  d2 10 40 0d  lduh  [ %g1 + %o5 ], %o1
a007a2a0:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a2a4:  94 10 3f 00  mov  -256, %o2
a007a2a8:  40 00 b4 78  call  0xa00a7488
a007a2ac:  96 10 20 03  mov  3, %o3
a007a2b0:  da 14 3f f8  lduh  [ %l0 + -8 ], %o5
a007a2b4:  80 a3 60 03  cmp  %o5, 3
a007a2b8:  38 80 00 0b  bgu,a   0xa007a2e4
a007a2bc:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a2c0:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a2c4:  9a 03 40 0d  add  %o5, %o5, %o5
a007a2c8:  82 10 63 28  or  %g1, 0x328, %g1
a007a2cc:  d2 10 40 0d  lduh  [ %g1 + %o5 ], %o1
a007a2d0:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a2d4:  94 10 3f 00  mov  -256, %o2
a007a2d8:  40 00 b4 6c  call  0xa00a7488
a007a2dc:  96 10 20 03  mov  3, %o3
a007a2e0:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a2e4:  80 a0 60 03  cmp  %g1, 3
a007a2e8:  38 80 00 0c  bgu,a   0xa007a318
a007a2ec:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a2f0:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a007a2f4:  82 00 40 01  add  %g1, %g1, %g1
a007a2f8:  9a 13 63 30  or  %o5, 0x330, %o5
a007a2fc:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a007a300:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a007a304:  94 12 a0 ff  or  %o2, 0xff, %o2
a007a308:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a30c:  40 00 b4 5f  call  0xa00a7488
a007a310:  96 10 20 00  clr  %o3
a007a314:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a318:  80 a0 60 03  cmp  %g1, 3
a007a31c:  38 80 00 0c  bgu,a   0xa007a34c
a007a320:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a324:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a007a328:  82 00 40 01  add  %g1, %g1, %g1
a007a32c:  9a 13 63 28  or  %o5, 0x328, %o5
a007a330:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a007a334:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a007a338:  94 12 a0 ff  or  %o2, 0xff, %o2
a007a33c:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a340:  40 00 b4 52  call  0xa00a7488
a007a344:  96 10 20 00  clr  %o3
a007a348:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a34c:  80 a0 60 03  cmp  %g1, 3
a007a350:  38 80 00 0c  bgu,a   0xa007a380
a007a354:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a358:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a007a35c:  82 00 40 01  add  %g1, %g1, %g1
a007a360:  9a 13 63 30  or  %o5, 0x330, %o5
a007a364:  15 3f c0 3f  sethi  %hi(0xff00fc00), %o2
a007a368:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a007a36c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007a370:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a374:  40 00 b4 45  call  0xa00a7488
a007a378:  96 10 20 00  clr  %o3
a007a37c:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a380:  80 a0 60 03  cmp  %g1, 3
a007a384:  38 80 00 0c  bgu,a   0xa007a3b4
a007a388:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a38c:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a007a390:  82 00 40 01  add  %g1, %g1, %g1
a007a394:  9a 13 63 28  or  %o5, 0x328, %o5
a007a398:  15 3f c0 3f  sethi  %hi(0xff00fc00), %o2
a007a39c:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a007a3a0:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007a3a4:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a3a8:  40 00 b4 38  call  0xa00a7488
a007a3ac:  96 10 20 00  clr  %o3
a007a3b0:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a3b4:  80 a0 60 03  cmp  %g1, 3
a007a3b8:  38 80 00 0c  bgu,a   0xa007a3e8
a007a3bc:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a3c0:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a007a3c4:  82 00 40 01  add  %g1, %g1, %g1
a007a3c8:  9a 13 63 30  or  %o5, 0x330, %o5
a007a3cc:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a007a3d0:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a007a3d4:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007a3d8:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a3dc:  40 00 b4 2b  call  0xa00a7488
a007a3e0:  17 2e 00 00  sethi  %hi(0xb8000000), %o3
a007a3e4:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a3e8:  80 a0 60 03  cmp  %g1, 3
a007a3ec:  38 80 00 0c  bgu,a   0xa007a41c
a007a3f0:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a3f4:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a007a3f8:  82 00 40 01  add  %g1, %g1, %g1
a007a3fc:  9a 13 63 28  or  %o5, 0x328, %o5
a007a400:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a007a404:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a007a408:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007a40c:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a410:  40 00 b4 1e  call  0xa00a7488
a007a414:  17 3e 00 00  sethi  %hi(0xf8000000), %o3
a007a418:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a41c:  80 a0 60 03  cmp  %g1, 3
a007a420:  38 80 00 0c  bgu,a   0xa007a450
a007a424:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a428:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a007a42c:  82 00 40 01  add  %g1, %g1, %g1
a007a430:  9a 13 63 50  or  %o5, 0x350, %o5
a007a434:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a007a438:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a007a43c:  94 12 a0 ff  or  %o2, 0xff, %o2
a007a440:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a444:  40 00 b4 11  call  0xa00a7488
a007a448:  17 00 00 22  sethi  %hi(0x8800), %o3
a007a44c:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a450:  80 a0 60 03  cmp  %g1, 3
a007a454:  18 80 00 0c  bgu  0xa007a484
a007a458:  9a 04 a0 01  add  %l2, 1, %o5
a007a45c:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a007a460:  82 00 40 01  add  %g1, %g1, %g1
a007a464:  9a 13 63 48  or  %o5, 0x348, %o5
a007a468:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a007a46c:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a007a470:  94 12 a0 ff  or  %o2, 0xff, %o2
a007a474:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a478:  40 00 b4 04  call  0xa00a7488
a007a47c:  17 00 00 22  sethi  %hi(0x8800), %o3
a007a480:  9a 04 a0 01  add  %l2, 1, %o5
a007a484:  83 2b 60 10  sll  %o5, 0x10, %g1
a007a488:  80 a4 40 01  cmp  %l1, %g1
a007a48c:  18 bf ff 47  bgu  0xa007a1a8
a007a490:  a4 10 00 0d  mov  %o5, %l2
a007a494:  a7 2c e0 10  sll  %l3, 0x10, %l3
a007a498:  80 a4 e0 00  cmp  %l3, 0
a007a49c:  02 80 00 63  be  0xa007a628
a007a4a0:  a4 10 20 00  clr  %l2
a007a4a4:  83 2c a0 10  sll  %l2, 0x10, %g1
a007a4a8:  83 30 60 0f  srl  %g1, 0xf, %g1
a007a4ac:  9a 07 bf f8  add  %fp, -8, %o5
a007a4b0:  a0 00 40 0d  add  %g1, %o5, %l0
a007a4b4:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a4b8:  80 a0 60 03  cmp  %g1, 3
a007a4bc:  38 80 00 0c  bgu,a   0xa007a4ec
a007a4c0:  da 14 3f f8  lduh  [ %l0 + -8 ], %o5
a007a4c4:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a007a4c8:  82 00 40 01  add  %g1, %g1, %g1
a007a4cc:  9a 13 63 40  or  %o5, 0x340, %o5
a007a4d0:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a007a4d4:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a007a4d8:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007a4dc:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a4e0:  40 00 b3 ea  call  0xa00a7488
a007a4e4:  17 02 00 00  sethi  %hi(0x8000000), %o3
a007a4e8:  da 14 3f f8  lduh  [ %l0 + -8 ], %o5
a007a4ec:  80 a3 60 03  cmp  %o5, 3
a007a4f0:  38 80 00 0b  bgu,a   0xa007a51c
a007a4f4:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a4f8:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a4fc:  9a 03 40 0d  add  %o5, %o5, %o5
a007a500:  82 10 63 50  or  %g1, 0x350, %g1
a007a504:  d2 10 40 0d  lduh  [ %g1 + %o5 ], %o1
a007a508:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a50c:  94 10 3f 00  mov  -256, %o2
a007a510:  40 00 b3 de  call  0xa00a7488
a007a514:  96 10 20 08  mov  8, %o3
a007a518:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a51c:  80 a0 60 03  cmp  %g1, 3
a007a520:  38 80 00 0c  bgu,a   0xa007a550
a007a524:  da 14 3f f8  lduh  [ %l0 + -8 ], %o5
a007a528:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a007a52c:  82 00 40 01  add  %g1, %g1, %g1
a007a530:  9a 13 63 38  or  %o5, 0x338, %o5
a007a534:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a007a538:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a007a53c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007a540:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a544:  40 00 b3 d1  call  0xa00a7488
a007a548:  17 02 00 00  sethi  %hi(0x8000000), %o3
a007a54c:  da 14 3f f8  lduh  [ %l0 + -8 ], %o5
a007a550:  80 a3 60 03  cmp  %o5, 3
a007a554:  38 80 00 0b  bgu,a   0xa007a580
a007a558:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a55c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a560:  9a 03 40 0d  add  %o5, %o5, %o5
a007a564:  82 10 63 48  or  %g1, 0x348, %g1
a007a568:  d2 10 40 0d  lduh  [ %g1 + %o5 ], %o1
a007a56c:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a570:  94 10 3f 00  mov  -256, %o2
a007a574:  40 00 b3 c5  call  0xa00a7488
a007a578:  96 10 20 08  mov  8, %o3
a007a57c:  c2 14 3f f8  lduh  [ %l0 + -8 ], %g1
a007a580:  a0 0e 20 ff  and  %i0, 0xff, %l0
a007a584:  80 a0 60 00  cmp  %g1, 0
a007a588:  02 80 00 07  be  0xa007a5a4
a007a58c:  23 00 00 08  sethi  %hi(0x2000), %l1
a007a590:  80 a0 60 01  cmp  %g1, 1
a007a594:  12 80 00 0c  bne  0xa007a5c4
a007a598:  80 a0 60 02  cmp  %g1, 2
a007a59c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a007a5a0:  23 00 00 09  sethi  %hi(0x2400), %l1
a007a5a4:  94 10 00 10  mov  %l0, %o2
a007a5a8:  96 14 63 10  or  %l1, 0x310, %o3
a007a5ac:  90 10 20 01  mov  1, %o0
a007a5b0:  40 00 b3 9d  call  0xa00a7424
a007a5b4:  92 10 20 0c  mov  0xc, %o1
a007a5b8:  94 10 00 10  mov  %l0, %o2
a007a5bc:  10 80 00 13  b  0xa007a608
a007a5c0:  96 14 63 30  or  %l1, 0x330, %o3
a007a5c4:  12 80 00 08  bne  0xa007a5e4
a007a5c8:  a2 0e 20 ff  and  %i0, 0xff, %l1
a007a5cc:  21 00 00 0a  sethi  %hi(0x2800), %l0
a007a5d0:  94 10 00 11  mov  %l1, %o2
a007a5d4:  96 14 23 10  or  %l0, 0x310, %o3
a007a5d8:  90 10 20 01  mov  1, %o0
a007a5dc:  10 80 00 07  b  0xa007a5f8
a007a5e0:  92 10 20 0c  mov  0xc, %o1
a007a5e4:  21 00 00 0c  sethi  %hi(0x3000), %l0
a007a5e8:  90 10 20 01  mov  1, %o0
a007a5ec:  92 10 20 0c  mov  0xc, %o1
a007a5f0:  94 10 00 11  mov  %l1, %o2
a007a5f4:  96 14 23 10  or  %l0, 0x310, %o3
a007a5f8:  40 00 b3 8b  call  0xa00a7424
a007a5fc:  01 00 00 00  nop
a007a600:  94 10 00 11  mov  %l1, %o2
a007a604:  96 14 23 30  or  %l0, 0x330, %o3
a007a608:  90 10 20 00  clr  %o0
a007a60c:  40 00 b3 86  call  0xa00a7424
a007a610:  92 10 20 0c  mov  0xc, %o1
a007a614:  9a 04 a0 01  add  %l2, 1, %o5
a007a618:  83 2b 60 10  sll  %o5, 0x10, %g1
a007a61c:  80 a4 c0 01  cmp  %l3, %g1
a007a620:  18 bf ff a1  bgu  0xa007a4a4
a007a624:  a4 10 00 0d  mov  %o5, %l2
a007a628:  81 c7 e0 08  ret
a007a62c:  81 e8 00 00  restore
