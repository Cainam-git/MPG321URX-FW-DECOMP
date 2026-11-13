# leon2s FUN_a00ca130 0xa00ca130-0xa00ca4e8 (952 bytes)
a00ca130:  9d e3 bf 98  save  %sp, -104, %sp
a00ca134:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00ca138:  40 3a e3 c3  call  0xa0f83044
a00ca13c:  90 12 21 10  or  %o0, 0x110, %o0	! 0x9f1c2110
a00ca140:  b6 0e 20 ff  and  %i0, 0xff, %i3
a00ca144:  96 10 20 01  mov  1, %o3
a00ca148:  90 10 00 1b  mov  %i3, %o0
a00ca14c:  92 10 20 30  mov  0x30, %o1
a00ca150:  40 3b b2 d2  call  0xa0fb6c98
a00ca154:  94 10 20 80  mov  0x80, %o2
a00ca158:  1b 33 c0 63  sethi  %hi(0xcf018c00), %o5
a00ca15c:  98 13 62 10  or  %o5, 0x210, %o4	! 0xcf018e10
a00ca160:  82 10 20 1f  mov  0x1f, %g1
a00ca164:  c2 23 00 00  st  %g1, [ %o4 ]
a00ca168:  98 13 62 14  or  %o5, 0x214, %o4
a00ca16c:  82 10 20 80  mov  0x80, %g1
a00ca170:  c2 23 00 00  st  %g1, [ %o4 ]
a00ca174:  96 10 00 0d  mov  %o5, %o3
a00ca178:  c2 03 00 00  ld  [ %o4 ], %g1
a00ca17c:  80 88 60 80  btst  0x80, %g1
a00ca180:  12 bf ff fe  bne  0xa00ca178
a00ca184:  9a 12 e2 18  or  %o3, 0x218, %o5
a00ca188:  c2 03 40 00  ld  [ %o5 ], %g1
a00ca18c:  82 08 7f fe  and  %g1, -2, %g1
a00ca190:  c2 23 40 00  st  %g1, [ %o5 ]
a00ca194:  9a 12 e2 00  or  %o3, 0x200, %o5
a00ca198:  82 10 20 11  mov  0x11, %g1
a00ca19c:  c2 23 40 00  st  %g1, [ %o5 ]
a00ca1a0:  90 10 00 1b  mov  %i3, %o0
a00ca1a4:  92 10 20 e9  mov  0xe9, %o1
a00ca1a8:  40 3b b2 96  call  0xa0fb6c00
a00ca1ac:  94 10 20 0f  mov  0xf, %o2
a00ca1b0:  90 10 00 1b  mov  %i3, %o0
a00ca1b4:  40 3b b2 81  call  0xa0fb6bb8
a00ca1b8:  92 10 20 e9  mov  0xe9, %o1
a00ca1bc:  80 8a 20 0f  btst  0xf, %o0
a00ca1c0:  12 bf ff fd  bne  0xa00ca1b4
a00ca1c4:  90 10 00 1b  mov  %i3, %o0
a00ca1c8:  21 33 c0 63  sethi  %hi(0xcf018c00), %l0
a00ca1cc:  9a 14 22 08  or  %l0, 0x208, %o5	! 0xcf018e08
a00ca1d0:  82 10 20 10  mov  0x10, %g1
a00ca1d4:  c2 23 40 00  st  %g1, [ %o5 ]
a00ca1d8:  9a 14 22 0c  or  %l0, 0x20c, %o5
a00ca1dc:  82 10 20 3f  mov  0x3f, %g1
a00ca1e0:  c2 23 40 00  st  %g1, [ %o5 ]
a00ca1e4:  92 10 22 aa  mov  0x2aa, %o1
a00ca1e8:  40 3b b2 74  call  0xa0fb6bb8
a00ca1ec:  90 10 00 1b  mov  %i3, %o0
a00ca1f0:  b2 0a 20 ff  and  %o0, 0xff, %i1
a00ca1f4:  90 10 00 1b  mov  %i3, %o0
a00ca1f8:  40 3b b2 70  call  0xa0fb6bb8
a00ca1fc:  92 10 20 e8  mov  0xe8, %o1
a00ca200:  a0 14 22 14  or  %l0, 0x214, %l0
a00ca204:  82 10 20 02  mov  2, %g1
a00ca208:  c2 24 00 00  st  %g1, [ %l0 ]
a00ca20c:  c2 04 00 00  ld  [ %l0 ], %g1
a00ca210:  a2 88 60 02  andcc  %g1, 2, %l1
a00ca214:  12 bf ff fe  bne  0xa00ca20c
a00ca218:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00ca21c:  40 3a e3 8a  call  0xa0f83044
a00ca220:  90 12 21 20  or  %o0, 0x120, %o0	! 0x9f1c2120
a00ca224:  b5 2e 60 10  sll  %i1, 0x10, %i2
a00ca228:  9b 36 a0 10  srl  %i2, 0x10, %o5
a00ca22c:  83 2b 60 02  sll  %o5, 2, %g1
a00ca230:  82 00 40 0d  add  %g1, %o5, %g1
a00ca234:  80 a4 40 01  cmp  %l1, %g1
a00ca238:  a2 10 20 00  clr  %l1
a00ca23c:  16 80 00 15  bge  0xa00ca290
a00ca240:  92 10 20 e8  mov  0xe8, %o1
a00ca244:  40 3b b2 5d  call  0xa0fb6bb8
a00ca248:  90 10 00 1b  mov  %i3, %o0
a00ca24c:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00ca250:  11 27 c6 dd  sethi  %hi(0x9f1b7400), %o0
a00ca254:  92 10 00 10  mov  %l0, %o1
a00ca258:  40 3a e3 7b  call  0xa0f83044
a00ca25c:  90 12 21 78  or  %o0, 0x178, %o0
a00ca260:  92 10 00 10  mov  %l0, %o1
a00ca264:  7f ff ff 84  call  0xa00ca074
a00ca268:  90 10 20 aa  mov  0xaa, %o0
a00ca26c:  96 04 60 01  add  %l1, 1, %o3
a00ca270:  99 36 a0 10  srl  %i2, 0x10, %o4
a00ca274:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ca278:  83 2b 20 02  sll  %o4, 2, %g1
a00ca27c:  82 00 40 0c  add  %g1, %o4, %g1
a00ca280:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ca284:  80 a3 40 01  cmp  %o5, %g1
a00ca288:  10 bf ff ed  b  0xa00ca23c
a00ca28c:  a2 10 00 0b  mov  %o3, %l1
a00ca290:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00ca294:  83 2b 60 02  sll  %o5, 2, %g1
a00ca298:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ca29c:  a2 00 40 0d  add  %g1, %o5, %l1
a00ca2a0:  92 10 22 aa  mov  0x2aa, %o1
a00ca2a4:  40 3b b2 45  call  0xa0fb6bb8
a00ca2a8:  90 10 00 18  mov  %i0, %o0
a00ca2ac:  92 0a 20 ff  and  %o0, 0xff, %o1
a00ca2b0:  7f ff ff 71  call  0xa00ca074
a00ca2b4:  90 10 20 aa  mov  0xaa, %o0
a00ca2b8:  92 10 22 ab  mov  0x2ab, %o1
a00ca2bc:  40 3b b2 3f  call  0xa0fb6bb8
a00ca2c0:  90 10 00 18  mov  %i0, %o0
a00ca2c4:  92 0a 20 ff  and  %o0, 0xff, %o1
a00ca2c8:  7f ff ff 6b  call  0xa00ca074
a00ca2cc:  90 10 20 aa  mov  0xaa, %o0
a00ca2d0:  92 10 22 aa  mov  0x2aa, %o1
a00ca2d4:  40 3b b2 39  call  0xa0fb6bb8
a00ca2d8:  90 10 00 18  mov  %i0, %o0
a00ca2dc:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00ca2e0:  92 10 22 ab  mov  0x2ab, %o1
a00ca2e4:  40 3b b2 35  call  0xa0fb6bb8
a00ca2e8:  90 10 00 18  mov  %i0, %o0
a00ca2ec:  94 0a 20 ff  and  %o0, 0xff, %o2
a00ca2f0:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00ca2f4:  92 10 00 10  mov  %l0, %o1
a00ca2f8:  40 3a e3 53  call  0xa0f83044
a00ca2fc:  90 12 21 28  or  %o0, 0x128, %o0
a00ca300:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00ca304:  40 3a e3 50  call  0xa0f83044
a00ca308:  90 12 21 40  or  %o0, 0x140, %o0	! 0x9f1c2140
a00ca30c:  b6 10 20 00  clr  %i3
a00ca310:  a0 0e e0 ff  and  %i3, 0xff, %l0
a00ca314:  11 27 c6 dd  sethi  %hi(0x9f1b7400), %o0
a00ca318:  92 10 00 10  mov  %l0, %o1
a00ca31c:  40 3a e3 4a  call  0xa0f83044
a00ca320:  90 12 21 78  or  %o0, 0x178, %o0
a00ca324:  92 10 00 10  mov  %l0, %o1
a00ca328:  7f ff ff 53  call  0xa00ca074
a00ca32c:  90 10 20 aa  mov  0xaa, %o0
a00ca330:  9a 06 e0 01  add  %i3, 1, %o5
a00ca334:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ca338:  83 30 60 10  srl  %g1, 0x10, %g1
a00ca33c:  80 a0 60 07  cmp  %g1, 7
a00ca340:  08 bf ff f4  bleu  0xa00ca310
a00ca344:  b6 10 00 0d  mov  %o5, %i3
a00ca348:  90 10 20 aa  mov  0xaa, %o0
a00ca34c:  7f ff ff 4a  call  0xa00ca074
a00ca350:  92 10 20 80  mov  0x80, %o1
a00ca354:  9a 04 60 0a  add  %l1, 0xa, %o5
a00ca358:  17 33 c0 63  sethi  %hi(0xcf018c00), %o3
a00ca35c:  a2 10 00 0d  mov  %o5, %l1
a00ca360:  82 0c 60 ff  and  %l1, 0xff, %g1
a00ca364:  98 12 e2 28  or  %o3, 0x228, %o4
a00ca368:  c2 23 00 00  st  %g1, [ %o4 ]
a00ca36c:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00ca370:  82 12 e2 24  or  %o3, 0x224, %g1
a00ca374:  9b 33 60 18  srl  %o5, 0x18, %o5
a00ca378:  da 20 40 00  st  %o5, [ %g1 ]
a00ca37c:  82 12 e2 0c  or  %o3, 0x20c, %g1
a00ca380:  c2 00 40 00  ld  [ %g1 ], %g1
a00ca384:  80 a0 60 06  cmp  %g1, 6
a00ca388:  18 80 00 18  bgu  0xa00ca3e8
a00ca38c:  19 33 c0 63  sethi  %hi(0xcf018c00), %o4
a00ca390:  9a 12 e2 14  or  %o3, 0x214, %o5
a00ca394:  c2 03 40 00  ld  [ %o5 ], %g1
a00ca398:  82 10 60 01  or  %g1, 1, %g1
a00ca39c:  98 10 00 0b  mov  %o3, %o4
a00ca3a0:  c2 23 40 00  st  %g1, [ %o5 ]
a00ca3a4:  96 10 00 0d  mov  %o5, %o3
a00ca3a8:  c2 02 c0 00  ld  [ %o3 ], %g1
a00ca3ac:  80 88 60 01  btst  1, %g1
a00ca3b0:  12 bf ff fe  bne  0xa00ca3a8
a00ca3b4:  9a 13 22 10  or  %o4, 0x210, %o5
a00ca3b8:  82 10 20 1f  mov  0x1f, %g1
a00ca3bc:  c2 23 40 00  st  %g1, [ %o5 ]
a00ca3c0:  c2 02 c0 00  ld  [ %o3 ], %g1
a00ca3c4:  82 10 60 80  or  %g1, 0x80, %g1
a00ca3c8:  c2 22 c0 00  st  %g1, [ %o3 ]
a00ca3cc:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00ca3d0:  9a 10 62 14  or  %g1, 0x214, %o5	! 0xcf018e14
a00ca3d4:  c2 03 40 00  ld  [ %o5 ], %g1
a00ca3d8:  80 88 60 80  btst  0x80, %g1
a00ca3dc:  12 bf ff fe  bne  0xa00ca3d4
a00ca3e0:  01 00 00 00  nop
a00ca3e4:  19 33 c0 63  sethi  %hi(0xcf018c00), %o4
a00ca3e8:  83 2c 60 10  sll  %l1, 0x10, %g1
a00ca3ec:  83 30 60 0d  srl  %g1, 0xd, %g1
a00ca3f0:  96 13 22 0c  or  %o4, 0x20c, %o3
a00ca3f4:  c0 22 c0 00  clr  [ %o3 ]
a00ca3f8:  9a 08 60 ff  and  %g1, 0xff, %o5
a00ca3fc:  94 13 22 04  or  %o4, 0x204, %o2
a00ca400:  da 22 80 00  st  %o5, [ %o2 ]
a00ca404:  9a 10 20 01  mov  1, %o5
a00ca408:  83 38 60 08  sra  %g1, 8, %g1
a00ca40c:  da 22 c0 00  st  %o5, [ %o3 ]
a00ca410:  82 08 60 ff  and  %g1, 0xff, %g1
a00ca414:  c2 22 80 00  st  %g1, [ %o2 ]
a00ca418:  9a 13 22 14  or  %o4, 0x214, %o5
a00ca41c:  c2 03 40 00  ld  [ %o5 ], %g1
a00ca420:  82 10 60 01  or  %g1, 1, %g1
a00ca424:  c2 23 40 00  st  %g1, [ %o5 ]
a00ca428:  c2 03 40 00  ld  [ %o5 ], %g1
a00ca42c:  80 88 60 01  btst  1, %g1
a00ca430:  12 bf ff fe  bne  0xa00ca428
a00ca434:  82 10 20 22  mov  0x22, %g1
a00ca438:  9a 13 22 00  or  %o4, 0x200, %o5
a00ca43c:  c2 23 40 00  st  %g1, [ %o5 ]
a00ca440:  82 13 22 08  or  %o4, 0x208, %g1
a00ca444:  c0 20 40 00  clr  [ %g1 ]
a00ca448:  9a 13 22 10  or  %o4, 0x210, %o5
a00ca44c:  c2 03 40 00  ld  [ %o5 ], %g1
a00ca450:  82 10 60 10  or  %g1, 0x10, %g1
a00ca454:  c2 23 40 00  st  %g1, [ %o5 ]
a00ca458:  c2 03 40 00  ld  [ %o5 ], %g1
a00ca45c:  80 88 60 10  btst  0x10, %g1
a00ca460:  12 bf ff fe  bne  0xa00ca458
a00ca464:  01 00 00 00  nop
a00ca468:  b6 10 20 00  clr  %i3	! 0x0
a00ca46c:  a3 2e e0 10  sll  %i3, 0x10, %l1
a00ca470:  93 34 60 12  srl  %l1, 0x12, %o1
a00ca474:  93 2a 60 03  sll  %o1, 3, %o1
a00ca478:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00ca47c:  82 10 62 04  or  %g1, 0x204, %g1	! 0xcf018e04
a00ca480:  92 22 40 1b  sub  %o1, %i3, %o1
a00ca484:  e0 00 40 00  ld  [ %g1 ], %l0
a00ca488:  92 02 62 97  add  %o1, 0x297, %o1
a00ca48c:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00ca490:  93 2a 60 10  sll  %o1, 0x10, %o1
a00ca494:  93 32 60 10  srl  %o1, 0x10, %o1
a00ca498:  90 10 00 18  mov  %i0, %o0
a00ca49c:  40 3b b1 d9  call  0xa0fb6c00
a00ca4a0:  94 10 00 10  mov  %l0, %o2
a00ca4a4:  a3 34 60 10  srl  %l1, 0x10, %l1
a00ca4a8:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00ca4ac:  90 12 21 48  or  %o0, 0x148, %o0	! 0x9f1c2148
a00ca4b0:  92 10 00 11  mov  %l1, %o1
a00ca4b4:  40 3a e2 e4  call  0xa0f83044
a00ca4b8:  94 10 00 10  mov  %l0, %o2
a00ca4bc:  9a 06 e0 01  add  %i3, 1, %o5
a00ca4c0:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ca4c4:  83 30 60 10  srl  %g1, 0x10, %g1
a00ca4c8:  80 a0 60 13  cmp  %g1, 0x13
a00ca4cc:  08 bf ff e8  bleu  0xa00ca46c
a00ca4d0:  b6 10 00 0d  mov  %o5, %i3
a00ca4d4:  b2 10 20 30  mov  0x30, %i1
a00ca4d8:  b4 10 20 80  mov  0x80, %i2
a00ca4dc:  40 3b b1 ef  call  0xa0fb6c98
a00ca4e0:  97 e8 20 00  restore  %g0, 0, %o3
a00ca4e4:  01 00 00 00  nop
