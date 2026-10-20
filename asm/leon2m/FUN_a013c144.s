# leon2m FUN_a013c144 0xa013c144-0xa013c894 (1872 bytes)
a013c144:  9d e3 bf 08  save  %sp, -248, %sp
a013c148:  b2 0e 60 ff  and  %i1, 0xff, %i1
a013c14c:  40 00 03 00  call  0xa013cd4c
a013c150:  90 10 00 19  mov  %i1, %o0
a013c154:  a2 10 00 08  mov  %o0, %l1
a013c158:  7f ff 05 b2  call  0xa00fd820
a013c15c:  90 10 00 19  mov  %i1, %o0
a013c160:  82 0a 20 ff  and  %o0, 0xff, %g1
a013c164:  80 a0 60 b1  cmp  %g1, 0xb1
a013c168:  02 80 01 3d  be  0xa013c65c
a013c16c:  a0 10 20 00  clr  %l0
a013c170:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013c174:  80 a6 20 ff  cmp  %i0, 0xff
a013c178:  22 80 00 0e  be,a   0xa013c1b0
a013c17c:  90 10 00 19  mov  %i1, %o0
a013c180:  90 0a 20 ff  and  %o0, 0xff, %o0
a013c184:  94 1a 20 31  xor  %o0, 0x31, %o2
a013c188:  80 a0 00 0a  cmp  %g0, %o2
a013c18c:  98 60 3f ff  subx  %g0, -1, %o4
a013c190:  92 1a 20 41  xor  %o0, 0x41, %o1
a013c194:  80 a0 00 09  cmp  %g0, %o1
a013c198:  9a 60 3f ff  subx  %g0, -1, %o5
a013c19c:  80 93 00 0d  orcc  %o4, %o5, %g0
a013c1a0:  02 80 00 bd  be  0xa013c494
a013c1a4:  a4 1a 20 51  xor  %o0, 0x51, %l2
a013c1a8:  a0 10 20 01  mov  1, %l0
a013c1ac:  90 10 00 19  mov  %i1, %o0
a013c1b0:  7f fe f3 1f  call  0xa00f8e2c
a013c1b4:  92 10 20 00  clr  %o1
a013c1b8:  40 00 1b 35  call  0xa0142e8c
a013c1bc:  90 10 00 19  mov  %i1, %o0
a013c1c0:  82 0a 20 ff  and  %o0, 0xff, %g1
a013c1c4:  80 a0 60 05  cmp  %g1, 5
a013c1c8:  02 80 00 c5  be  0xa013c4dc
a013c1cc:  a0 0c 20 ff  and  %l0, 0xff, %l0
a013c1d0:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a013c1d4:  b0 14 a0 1c  or  %l2, 0x1c, %i0	! 0xa802cc1c
a013c1d8:  e0 06 20 18  ld  [ %i0 + 0x18 ], %l0
a013c1dc:  80 a4 20 00  cmp  %l0, 0
a013c1e0:  02 80 00 1d  be  0xa013c254
a013c1e4:  80 a6 60 03  cmp  %i1, 3
a013c1e8:  a0 10 20 00  clr  %l0
a013c1ec:  18 80 00 13  bgu  0xa013c238
a013c1f0:  b0 10 20 00  clr  %i0
a013c1f4:  35 2a 00 b7  sethi  %hi(0xa802dc00), %i2
a013c1f8:  96 16 a3 30  or  %i2, 0x330, %o3	! 0xa802df30
a013c1fc:  98 10 20 00  clr  %o4
a013c200:  83 2b 20 04  sll  %o4, 4, %g1
a013c204:  9e 20 40 0c  sub  %g1, %o4, %o7
a013c208:  91 2b e0 03  sll  %o7, 3, %o0
a013c20c:  d4 02 c0 08  ld  [ %o3 + %o0 ], %o2
a013c210:  93 32 a0 0c  srl  %o2, 0xc, %o1
a013c214:  9a 0a 60 0f  and  %o1, 0xf, %o5
a013c218:  80 a6 40 0d  cmp  %i1, %o5
a013c21c:  02 80 01 2d  be  0xa013c6d0
a013c220:  80 a3 20 03  cmp  %o4, 3
a013c224:  a0 04 20 01  inc  %l0
a013c228:  98 0c 20 ff  and  %l0, 0xff, %o4
a013c22c:  80 a3 20 03  cmp  %o4, 3
a013c230:  08 bf ff f5  bleu  0xa013c204
a013c234:  83 2b 20 04  sll  %o4, 4, %g1
a013c238:  80 8e 20 ff  btst  0xff, %i0
a013c23c:  22 80 00 02  be,a   0xa013c244
a013c240:  a0 10 3f ff  mov  -1, %l0
a013c244:  b0 14 a0 1c  or  %l2, 0x1c, %i0
a013c248:  e4 06 20 18  ld  [ %i0 + 0x18 ], %l2
a013c24c:  9f c4 80 00  call  %l2
a013c250:  90 0c 20 ff  and  %l0, 0xff, %o0
a013c254:  40 00 02 be  call  0xa013cd4c
a013c258:  90 10 00 19  mov  %i1, %o0
a013c25c:  d8 12 20 10  lduh  [ %o0 + 0x10 ], %o4
a013c260:  c2 12 20 14  lduh  [ %o0 + 0x14 ], %g1
a013c264:  94 23 00 01  sub  %o4, %g1, %o2
a013c268:  de 12 20 0e  lduh  [ %o0 + 0xe ], %o7
a013c26c:  9a 5a 80 0f  smul  %o2, %o7, %o5
a013c270:  13 00 00 07  sethi  %hi(0x1c00), %o1
a013c274:  a0 12 63 ff  or  %o1, 0x3ff, %l0	! 0x1fff
a013c278:  b5 33 60 01  srl  %o5, 1, %i2
a013c27c:  80 a6 80 10  cmp  %i2, %l0
a013c280:  08 80 00 03  bleu  0xa013c28c
a013c284:  a0 10 20 00  clr  %l0
a013c288:  a0 10 20 01  mov  1, %l0
a013c28c:  7f fe f1 a3  call  0xa00f8918
a013c290:  90 10 00 19  mov  %i1, %o0
a013c294:  40 00 02 ae  call  0xa013cd4c
a013c298:  90 10 00 19  mov  %i1, %o0
a013c29c:  e4 12 20 12  lduh  [ %o0 + 0x12 ], %l2
a013c2a0:  d6 12 20 16  lduh  [ %o0 + 0x16 ], %o3
a013c2a4:  80 a4 80 0b  cmp  %l2, %o3
a013c2a8:  22 80 00 c9  be,a   0xa013c5cc
a013c2ac:  f4 12 20 14  lduh  [ %o0 + 0x14 ], %i2
a013c2b0:  80 8c 20 ff  btst  0xff, %l0
a013c2b4:  02 80 00 0c  be  0xa013c2e4
a013c2b8:  01 00 00 00  nop
a013c2bc:  da 12 20 20  lduh  [ %o0 + 0x20 ], %o5
a013c2c0:  e0 12 20 1c  lduh  [ %o0 + 0x1c ], %l0
a013c2c4:  80 a4 00 0d  cmp  %l0, %o5
a013c2c8:  18 80 00 05  bgu  0xa013c2dc
a013c2cc:  92 10 00 0d  mov  %o5, %o1
a013c2d0:  92 23 40 10  sub  %o5, %l0, %o1
a013c2d4:  91 2a 60 10  sll  %o1, 0x10, %o0
a013c2d8:  93 32 20 10  srl  %o0, 0x10, %o1
a013c2dc:  7f fe f1 83  call  0xa00f88e8
a013c2e0:  90 10 00 19  mov  %i1, %o0
a013c2e4:  7f fe f3 04  call  0xa00f8ef4
a013c2e8:  90 10 00 19  mov  %i1, %o0
a013c2ec:  d2 14 60 16  lduh  [ %l1 + 0x16 ], %o1
a013c2f0:  d4 14 60 18  lduh  [ %l1 + 0x18 ], %o2
a013c2f4:  d2 37 bf 76  sth  %o1, [ %fp + -138 ]
a013c2f8:  80 a6 60 00  cmp  %i1, 0
a013c2fc:  02 80 00 97  be  0xa013c558
a013c300:  d4 37 bf 74  sth  %o2, [ %fp + -140 ]
a013c304:  97 2a a0 10  sll  %o2, 0x10, %o3
a013c308:  93 2a 60 10  sll  %o1, 0x10, %o1
a013c30c:  93 32 60 10  srl  %o1, 0x10, %o1
a013c310:  95 32 e0 10  srl  %o3, 0x10, %o2
a013c314:  7f fe f1 89  call  0xa00f8938
a013c318:  90 10 00 19  mov  %i1, %o0
a013c31c:  e0 0c 60 3e  ldub  [ %l1 + 0x3e ], %l0
a013c320:  80 a4 20 01  cmp  %l0, 1
a013c324:  22 80 00 9f  be,a   0xa013c5a0
a013c328:  da 14 40 00  lduh  [ %l1 ], %o5
a013c32c:  90 10 00 19  mov  %i1, %o0
a013c330:  d2 14 60 0e  lduh  [ %l1 + 0xe ], %o1
a013c334:  d4 14 60 12  lduh  [ %l1 + 0x12 ], %o2
a013c338:  7f fe f1 d8  call  0xa00f8a98
a013c33c:  d6 14 60 14  lduh  [ %l1 + 0x14 ], %o3
a013c340:  90 10 00 19  mov  %i1, %o0
a013c344:  7f fe f2 60  call  0xa00f8cc4
a013c348:  d2 14 60 0e  lduh  [ %l1 + 0xe ], %o1
a013c34c:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a013c350:  d4 04 23 d0  ld  [ %l0 + 0x3d0 ], %o2	! 0xa802e3d0
a013c354:  1f 00 80 00  sethi  %hi(0x2000000), %o7
a013c358:  80 8a 80 0f  btst  %o2, %o7
a013c35c:  02 80 00 06  be  0xa013c374
a013c360:  01 00 00 00  nop
a013c364:  d8 04 60 70  ld  [ %l1 + 0x70 ], %o4
a013c368:  80 a3 20 00  cmp  %o4, 0
a013c36c:  06 80 00 a9  bl  0xa013c610
a013c370:  01 00 00 00  nop
a013c374:  7f ff 39 32  call  0xa010a83c
a013c378:  90 10 00 19  mov  %i1, %o0
a013c37c:  7f fe f2 ee  call  0xa00f8f34
a013c380:  90 10 00 19  mov  %i1, %o0
a013c384:  80 8a 20 ff  btst  0xff, %o0
a013c388:  22 80 00 64  be,a   0xa013c518
a013c38c:  90 10 00 19  mov  %i1, %o0
a013c390:  d0 14 60 1e  lduh  [ %l1 + 0x1e ], %o0
a013c394:  c2 14 60 1a  lduh  [ %l1 + 0x1a ], %g1
a013c398:  b0 22 00 01  sub  %o0, %g1, %i0
a013c39c:  b5 2e 20 10  sll  %i0, 0x10, %i2
a013c3a0:  93 36 a0 10  srl  %i2, 0x10, %o1
a013c3a4:  7f fe f2 9a  call  0xa00f8e0c
a013c3a8:  90 10 00 19  mov  %i1, %o0
a013c3ac:  d2 14 60 20  lduh  [ %l1 + 0x20 ], %o1
a013c3b0:  7f fe f2 a5  call  0xa00f8e44
a013c3b4:  90 10 00 19  mov  %i1, %o0
a013c3b8:  d2 04 60 70  ld  [ %l1 + 0x70 ], %o1
a013c3bc:  17 10 00 00  sethi  %hi(0x40000000), %o3
a013c3c0:  80 8a 40 0b  btst  %o1, %o3
a013c3c4:  12 80 00 60  bne  0xa013c544
a013c3c8:  90 10 00 19  mov  %i1, %o0
a013c3cc:  e4 17 bf 76  lduh  [ %fp + -138 ], %l2
a013c3d0:  f0 17 bf 74  lduh  [ %fp + -140 ], %i0
a013c3d4:  40 00 02 5e  call  0xa013cd4c
a013c3d8:  90 10 00 19  mov  %i1, %o0
a013c3dc:  80 a6 60 00  cmp  %i1, 0
a013c3e0:  12 80 00 20  bne  0xa013c460
a013c3e4:  b4 10 00 08  mov  %o0, %i2
a013c3e8:  da 04 23 d0  ld  [ %l0 + 0x3d0 ], %o5
a013c3ec:  21 00 80 00  sethi  %hi(0x2000000), %l0
a013c3f0:  80 8b 40 10  btst  %o5, %l0
a013c3f4:  02 80 00 06  be  0xa013c40c
a013c3f8:  a0 07 bf 78  add  %fp, -136, %l0
a013c3fc:  de 02 20 70  ld  [ %o0 + 0x70 ], %o7
a013c400:  80 a3 e0 00  cmp  %o7, 0
a013c404:  06 80 00 9a  bl  0xa013c66c
a013c408:  01 00 00 00  nop
a013c40c:  92 06 a0 06  add  %i2, 6, %o1
a013c410:  94 10 20 3c  mov  0x3c, %o2
a013c414:  40 00 01 3f  call  0xa013c910
a013c418:  90 10 00 10  mov  %l0, %o0
a013c41c:  91 2c a0 10  sll  %l2, 0x10, %o0
a013c420:  a5 2e 20 10  sll  %i0, 0x10, %l2
a013c424:  95 32 20 10  srl  %o0, 0x10, %o2
a013c428:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a013c42c:  92 10 00 10  mov  %l0, %o1
a013c430:  97 34 a0 10  srl  %l2, 0x10, %o3
a013c434:  90 10 20 00  clr  %o0
a013c438:  98 10 20 00  clr  %o4
a013c43c:  7f ff 30 b0  call  0xa01086fc
a013c440:  9a 10 20 00  clr  %o5
a013c444:  de 06 a0 68  ld  [ %i2 + 0x68 ], %o7
a013c448:  1b 00 10 00  sethi  %hi(0x400000), %o5
a013c44c:  92 2b c0 0d  andn  %o7, %o5, %o1
a013c450:  17 00 08 00  sethi  %hi(0x200000), %o3
a013c454:  82 2a 40 0b  andn  %o1, %o3, %g1
a013c458:  7f fe f5 0a  call  0xa00f9880
a013c45c:  c2 26 a0 68  st  %g1, [ %i2 + 0x68 ]
a013c460:  f4 0c 60 3e  ldub  [ %l1 + 0x3e ], %i2
a013c464:  80 a0 00 1a  cmp  %g0, %i2
a013c468:  82 40 20 00  addx  %g0, 0, %g1
a013c46c:  80 a6 60 03  cmp  %i1, 3
a013c470:  18 80 00 03  bgu  0xa013c47c
a013c474:  9a 10 20 01  mov  1, %o5
a013c478:  9a 10 20 00  clr  %o5
a013c47c:  80 88 40 0d  btst  %g1, %o5
a013c480:  22 80 00 fd  be,a   0xa013c874
a013c484:  d2 14 60 16  lduh  [ %l1 + 0x16 ], %o1
a013c488:  d4 14 60 16  lduh  [ %l1 + 0x16 ], %o2
a013c48c:  10 80 00 fa  b  0xa013c874
a013c490:  93 32 a0 01  srl  %o2, 1, %o1
a013c494:  80 a0 00 12  cmp  %g0, %l2
a013c498:  96 60 3f ff  subx  %g0, -1, %o3
a013c49c:  9e 1a 20 61  xor  %o0, 0x61, %o7
a013c4a0:  80 a0 00 0f  cmp  %g0, %o7
a013c4a4:  90 60 3f ff  subx  %g0, -1, %o0
a013c4a8:  80 92 c0 08  orcc  %o3, %o0, %g0
a013c4ac:  32 bf ff 40  bne,a   0xa013c1ac
a013c4b0:  a0 10 20 01  mov  1, %l0
a013c4b4:  90 10 00 19  mov  %i1, %o0
a013c4b8:  7f fe f2 5d  call  0xa00f8e2c
a013c4bc:  92 10 20 00  clr  %o1
a013c4c0:  40 00 1a 73  call  0xa0142e8c
a013c4c4:  90 10 00 19  mov  %i1, %o0
a013c4c8:  82 0a 20 ff  and  %o0, 0xff, %g1
a013c4cc:  80 a0 60 05  cmp  %g1, 5
a013c4d0:  12 bf ff 41  bne  0xa013c1d4
a013c4d4:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a013c4d8:  a0 0c 20 ff  and  %l0, 0xff, %l0
a013c4dc:  80 a4 20 00  cmp  %l0, 0
a013c4e0:  12 80 00 79  bne  0xa013c6c4
a013c4e4:  90 10 00 18  mov  %i0, %o0
a013c4e8:  7f fe de ff  call  0xa00f40e4
a013c4ec:  90 10 00 19  mov  %i1, %o0
a013c4f0:  90 10 00 19  mov  %i1, %o0
a013c4f4:  7f ff fe ad  call  0xa013bfa8
a013c4f8:  92 0e a0 ff  and  %i2, 0xff, %o1
a013c4fc:  80 a4 20 00  cmp  %l0, 0
a013c500:  22 bf ff 35  be,a   0xa013c1d4
a013c504:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a013c508:  7f ff d9 43  call  0xa0132a14
a013c50c:  90 10 00 18  mov  %i0, %o0
a013c510:  10 bf ff 31  b  0xa013c1d4
a013c514:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a013c518:  7f fe f2 3d  call  0xa00f8e0c
a013c51c:  d2 14 60 1e  lduh  [ %l1 + 0x1e ], %o1
a013c520:  d2 14 60 20  lduh  [ %l1 + 0x20 ], %o1
a013c524:  7f fe f2 48  call  0xa00f8e44
a013c528:  90 10 00 19  mov  %i1, %o0
a013c52c:  d2 04 60 70  ld  [ %l1 + 0x70 ], %o1
a013c530:  17 10 00 00  sethi  %hi(0x40000000), %o3
a013c534:  80 8a 40 0b  btst  %o1, %o3
a013c538:  22 bf ff a6  be,a   0xa013c3d0
a013c53c:  e4 17 bf 76  lduh  [ %fp + -138 ], %l2
a013c540:  90 10 00 19  mov  %i1, %o0
a013c544:  d2 17 bf 76  lduh  [ %fp + -138 ], %o1
a013c548:  40 00 17 f4  call  0xa0142518
a013c54c:  d4 17 bf 74  lduh  [ %fp + -140 ], %o2
a013c550:  10 bf ff a0  b  0xa013c3d0
a013c554:  e4 17 bf 76  lduh  [ %fp + -138 ], %l2
a013c558:  7f fe f2 77  call  0xa00f8f34
a013c55c:  90 10 20 00  clr  %o0
a013c560:  94 0a 20 ff  and  %o0, 0xff, %o2
a013c564:  80 a2 a0 01  cmp  %o2, 1
a013c568:  02 80 00 6b  be  0xa013c714
a013c56c:  d2 17 bf 76  lduh  [ %fp + -138 ], %o1
a013c570:  d4 17 bf 74  lduh  [ %fp + -140 ], %o2
a013c574:  97 2a a0 10  sll  %o2, 0x10, %o3
a013c578:  93 2a 60 10  sll  %o1, 0x10, %o1
a013c57c:  93 32 60 10  srl  %o1, 0x10, %o1
a013c580:  95 32 e0 10  srl  %o3, 0x10, %o2
a013c584:  7f fe f0 ed  call  0xa00f8938
a013c588:  90 10 00 19  mov  %i1, %o0
a013c58c:  e0 0c 60 3e  ldub  [ %l1 + 0x3e ], %l0
a013c590:  80 a4 20 01  cmp  %l0, 1
a013c594:  12 bf ff 67  bne  0xa013c330
a013c598:  90 10 00 19  mov  %i1, %o0
a013c59c:  da 14 40 00  lduh  [ %l1 ], %o5
a013c5a0:  40 00 02 4b  call  0xa013cecc
a013c5a4:  90 0b 60 0f  and  %o5, 0xf, %o0
a013c5a8:  80 8a 20 ff  btst  0xff, %o0
a013c5ac:  02 bf ff 61  be  0xa013c330
a013c5b0:  90 10 00 19  mov  %i1, %o0
a013c5b4:  d2 14 60 0e  lduh  [ %l1 + 0xe ], %o1
a013c5b8:  d4 14 60 12  lduh  [ %l1 + 0x12 ], %o2
a013c5bc:  7f fe f0 ec  call  0xa00f896c
a013c5c0:  d6 14 60 14  lduh  [ %l1 + 0x14 ], %o3
a013c5c4:  10 bf ff 60  b  0xa013c344
a013c5c8:  90 10 00 19  mov  %i1, %o0
a013c5cc:  f0 12 20 18  lduh  [ %o0 + 0x18 ], %i0
a013c5d0:  80 a6 80 18  cmp  %i2, %i0
a013c5d4:  12 bf ff 38  bne  0xa013c2b4
a013c5d8:  80 8c 20 ff  btst  0xff, %l0
a013c5dc:  7f ff 95 dc  call  0xa0121d4c
a013c5e0:  90 10 00 19  mov  %i1, %o0
a013c5e4:  9a 0a 20 ff  and  %o0, 0xff, %o5
a013c5e8:  80 a3 60 01  cmp  %o5, 1
a013c5ec:  02 80 00 9e  be  0xa013c864
a013c5f0:  80 8c 20 ff  btst  0xff, %l0
a013c5f4:  22 bf ff 3f  be,a   0xa013c2f0
a013c5f8:  d2 14 60 16  lduh  [ %l1 + 0x16 ], %o1
a013c5fc:  90 10 00 19  mov  %i1, %o0
a013c600:  7f fe f0 ba  call  0xa00f88e8
a013c604:  92 10 20 00  clr  %o1
a013c608:  10 bf ff 3a  b  0xa013c2f0
a013c60c:  d2 14 60 16  lduh  [ %l1 + 0x16 ], %o1
a013c610:  7f ff 93 12  call  0xa0121258
a013c614:  90 10 00 19  mov  %i1, %o0
a013c618:  a4 0a 20 ff  and  %o0, 0xff, %l2
a013c61c:  80 a4 a0 01  cmp  %l2, 1
a013c620:  12 bf ff 55  bne  0xa013c374
a013c624:  d0 17 bf 76  lduh  [ %fp + -138 ], %o0
a013c628:  7f ff 5f 7e  call  0xa0114420
a013c62c:  d2 17 bf 74  lduh  [ %fp + -140 ], %o1
a013c630:  d2 17 bf 74  lduh  [ %fp + -140 ], %o1
a013c634:  d4 14 60 08  lduh  [ %l1 + 8 ], %o2
a013c638:  7f ff 26 0a  call  0xa0105e60
a013c63c:  d0 17 bf 76  lduh  [ %fp + -138 ], %o0
a013c640:  7f ff 38 79  call  0xa010a824
a013c644:  90 10 00 19  mov  %i1, %o0
a013c648:  67 fd 42 d6  call  0x4008d1a0
a013c64c:  90 10 20 32  mov  0x32, %o0
a013c650:  7f ff 25 b4  call  0xa0105d20
a013c654:  01 00 00 00  nop
a013c658:  30 bf ff 49  b,a   0xa013c37c
a013c65c:  7f ff cd 71  call  0xa012fc20
a013c660:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013c664:  10 bf fe c5  b  0xa013c178
a013c668:  80 a6 20 ff  cmp  %i0, 0xff
a013c66c:  7f ff 92 fb  call  0xa0121258
a013c670:  90 10 20 00  clr  %o0
a013c674:  94 0a 20 ff  and  %o0, 0xff, %o2
a013c678:  80 a2 a0 01  cmp  %o2, 1
a013c67c:  12 bf ff 64  bne  0xa013c40c
a013c680:  a0 07 bf 78  add  %fp, -136, %l0
a013c684:  b0 07 bf b8  add  %fp, -72, %i0
a013c688:  92 06 a0 06  add  %i2, 6, %o1
a013c68c:  94 10 20 3c  mov  0x3c, %o2
a013c690:  40 00 00 a0  call  0xa013c910
a013c694:  90 10 00 18  mov  %i0, %o0
a013c698:  99 2c a0 10  sll  %l2, 0x10, %o4
a013c69c:  d6 16 a0 18  lduh  [ %i2 + 0x18 ], %o3
a013c6a0:  95 33 20 10  srl  %o4, 0x10, %o2
a013c6a4:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a013c6a8:  92 10 00 18  mov  %i0, %o1
a013c6ac:  90 10 20 00  clr  %o0
a013c6b0:  98 10 20 01  mov  1, %o4
a013c6b4:  7f ff 30 12  call  0xa01086fc
a013c6b8:  9a 10 20 00  clr  %o5
a013c6bc:  10 bf ff 62  b  0xa013c444
a013c6c0:  c0 2e a0 68  clrb  [ %i2 + 0x68 ]
a013c6c4:  7f ff 96 17  call  0xa0121f20
a013c6c8:  92 10 00 19  mov  %i1, %o1
a013c6cc:  30 bf ff 87  b,a   0xa013c4e8
a013c6d0:  18 bf fe db  bgu  0xa013c23c
a013c6d4:  80 8e 20 ff  btst  0xff, %i0
a013c6d8:  b4 0c 20 ff  and  %l0, 0xff, %i2
a013c6dc:  a0 10 20 00  clr  %l0
a013c6e0:  90 10 20 00  clr  %o0
a013c6e4:  40 00 1b f4  call  0xa01436b4
a013c6e8:  01 00 00 00  nop
a013c6ec:  96 0a 20 ff  and  %o0, 0xff, %o3
a013c6f0:  80 a2 c0 1a  cmp  %o3, %i2
a013c6f4:  22 bf fe d1  be,a   0xa013c238
a013c6f8:  b0 10 20 01  mov  1, %i0
a013c6fc:  a0 04 20 01  inc  %l0
a013c700:  90 0c 20 ff  and  %l0, 0xff, %o0
a013c704:  80 a2 20 03  cmp  %o0, 3
a013c708:  08 bf ff f7  bleu  0xa013c6e4
a013c70c:  80 8e 20 ff  btst  0xff, %i0
a013c710:  30 bf fe cb  b,a   0xa013c23c
a013c714:  40 00 01 8e  call  0xa013cd4c
a013c718:  90 10 20 00  clr  %o0
a013c71c:  7f ff 38 56  call  0xa010a874
a013c720:  a0 10 00 08  mov  %o0, %l0
a013c724:  80 8a 20 ff  btst  0xff, %o0
a013c728:  b4 10 20 00  clr  %i2
a013c72c:  94 10 20 00  clr  %o2
a013c730:  02 80 00 28  be  0xa013c7d0
a013c734:  96 10 20 00  clr  %o3
a013c738:  f4 14 20 16  lduh  [ %l0 + 0x16 ], %i2
a013c73c:  9a 0e a0 0f  and  %i2, 0xf, %o5
a013c740:  92 10 20 10  mov  0x10, %o1
a013c744:  90 22 40 0d  sub  %o1, %o5, %o0
a013c748:  9e 0a 20 0f  and  %o0, 0xf, %o7
a013c74c:  f0 14 20 1e  lduh  [ %l0 + 0x1e ], %i0
a013c750:  a4 06 00 1a  add  %i0, %i2, %l2
a013c754:  82 0b e0 ff  and  %o7, 0xff, %g1
a013c758:  96 04 80 01  add  %l2, %g1, %o3
a013c75c:  d8 14 20 0e  lduh  [ %l0 + 0xe ], %o4
a013c760:  80 a2 c0 0c  cmp  %o3, %o4
a013c764:  da 14 20 16  lduh  [ %l0 + 0x16 ], %o5
a013c768:  04 80 00 05  ble  0xa013c77c
a013c76c:  b4 0b e0 ff  and  %o7, 0xff, %i2
a013c770:  9e 23 00 0d  sub  %o4, %o5, %o7
a013c774:  94 23 c0 1a  sub  %o7, %i2, %o2
a013c778:  d4 34 20 1e  sth  %o2, [ %l0 + 0x1e ]
a013c77c:  d8 14 20 18  lduh  [ %l0 + 0x18 ], %o4
a013c780:  a4 0b 20 01  and  %o4, 1, %l2
a013c784:  7f ff 92 b5  call  0xa0121258
a013c788:  90 10 20 00  clr  %o0
a013c78c:  80 8a 20 ff  btst  0xff, %o0
a013c790:  22 80 00 29  be,a   0xa013c834
a013c794:  d4 14 20 20  lduh  [ %l0 + 0x20 ], %o2
a013c798:  d0 14 20 20  lduh  [ %l0 + 0x20 ], %o0
a013c79c:  d2 14 20 18  lduh  [ %l0 + 0x18 ], %o1
a013c7a0:  82 02 00 09  add  %o0, %o1, %g1
a013c7a4:  94 0c a0 ff  and  %l2, 0xff, %o2
a013c7a8:  f0 14 20 10  lduh  [ %l0 + 0x10 ], %i0
a013c7ac:  96 00 40 0a  add  %g1, %o2, %o3
a013c7b0:  9a 06 00 18  add  %i0, %i0, %o5
a013c7b4:  80 a2 c0 0d  cmp  %o3, %o5
a013c7b8:  c2 14 20 18  lduh  [ %l0 + 0x18 ], %g1
a013c7bc:  04 80 00 05  ble  0xa013c7d0
a013c7c0:  96 0c a0 ff  and  %l2, 0xff, %o3
a013c7c4:  82 23 40 01  sub  %o5, %g1, %g1
a013c7c8:  a4 20 40 0b  sub  %g1, %o3, %l2
a013c7cc:  e4 34 20 20  sth  %l2, [ %l0 + 0x20 ]
a013c7d0:  c2 14 20 16  lduh  [ %l0 + 0x16 ], %g1
a013c7d4:  b0 00 40 1a  add  %g1, %i2, %i0
a013c7d8:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a013c7dc:  f4 12 23 82  lduh  [ %o0 + 0x382 ], %i2	! 0xa802e382
a013c7e0:  f0 37 bf 76  sth  %i0, [ %fp + -138 ]
a013c7e4:  a4 5e 80 0a  smul  %i2, %o2, %l2
a013c7e8:  d8 14 20 18  lduh  [ %l0 + 0x18 ], %o4
a013c7ec:  15 14 7a e1  sethi  %hi(0x51eb8400), %o2
a013c7f0:  92 03 00 0b  add  %o4, %o3, %o1
a013c7f4:  9e 12 a1 1f  or  %o2, 0x11f, %o7
a013c7f8:  9a 5c a0 6e  smul  %l2, 0x6e, %o5
a013c7fc:  d2 37 bf 74  sth  %o1, [ %fp + -140 ]
a013c800:  80 53 40 0f  umul  %o5, %o7, %g0
a013c804:  91 40 00 00  rd  %y, %o0
a013c808:  b1 32 20 05  srl  %o0, 5, %i0
a013c80c:  c2 14 20 18  lduh  [ %l0 + 0x18 ], %g1
a013c810:  81 80 00 00  mov  %g0, %y
a013c814:  01 00 00 00  nop
a013c818:  01 00 00 00  nop
a013c81c:  01 00 00 00  nop
a013c820:  b4 76 00 01  udiv  %i0, %g1, %i2
a013c824:  f4 2c 20 68  stb  %i2, [ %l0 + 0x68 ]
a013c828:  d2 17 bf 76  lduh  [ %fp + -138 ], %o1
a013c82c:  10 bf ff 52  b  0xa013c574
a013c830:  d4 17 bf 74  lduh  [ %fp + -140 ], %o2
a013c834:  d6 14 20 18  lduh  [ %l0 + 0x18 ], %o3
a013c838:  98 02 80 0b  add  %o2, %o3, %o4
a013c83c:  94 0c a0 ff  and  %l2, 0xff, %o2
a013c840:  da 14 20 10  lduh  [ %l0 + 0x10 ], %o5
a013c844:  9e 03 00 0a  add  %o4, %o2, %o7
a013c848:  80 a3 c0 0d  cmp  %o7, %o5
a013c84c:  da 14 20 18  lduh  [ %l0 + 0x18 ], %o5
a013c850:  c2 14 20 10  lduh  [ %l0 + 0x10 ], %g1
a013c854:  04 bf ff df  ble  0xa013c7d0
a013c858:  96 0c a0 ff  and  %l2, 0xff, %o3
a013c85c:  10 bf ff db  b  0xa013c7c8
a013c860:  82 20 40 0d  sub  %g1, %o5, %g1
a013c864:  7f fe f0 2d  call  0xa00f8918
a013c868:  90 10 00 19  mov  %i1, %o0
a013c86c:  10 bf fe a1  b  0xa013c2f0
a013c870:  d2 14 60 16  lduh  [ %l1 + 0x16 ], %o1
a013c874:  90 10 00 19  mov  %i1, %o0
a013c878:  d4 17 bf 74  lduh  [ %fp + -140 ], %o2
a013c87c:  7f fe f1 1a  call  0xa00f8ce4
a013c880:  96 10 20 00  clr  %o3
a013c884:  7f ff 95 6e  call  0xa0121e3c
a013c888:  90 10 00 19  mov  %i1, %o0
a013c88c:  81 c7 e0 08  ret
a013c890:  91 e8 20 01  restore  %g0, 1, %o0
