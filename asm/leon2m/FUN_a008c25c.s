# leon2m FUN_a008c25c 0xa008c25c-0xa008cc28 (180 bytes)
a008c25c:  9d e3 bf 98  save  %sp, -104, %sp
a008c260:  27 2a 00 ab  sethi  %hi(0xa802ac00), %l3
a008c264:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1	! 0xa802afbd
a008c268:  80 a0 60 1a  cmp  %g1, 0x1a
a008c26c:  38 80 00 1e  bgu,a   0xa008c2e4
a008c270:  80 a0 60 13  cmp  %g1, 0x13
a008c274:  11 00 00 a8  sethi  %hi(0x2a000), %o0
a008c278:  83 28 60 02  sll  %g1, 2, %g1
a008c27c:  9a 12 23 c8  or  %o0, 0x3c8, %o5
a008c280:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a008c284:  81 c3 00 00  jmp  %o4
a008c288:  01 00 00 00  nop
a008c28c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a008c290:  a0 12 62 90  or  %o1, 0x290, %l0	! 0xa802d290
a008c294:  d0 14 21 da  lduh  [ %l0 + 0x1da ], %o0
a008c298:  9a 02 20 01  add  %o0, 1, %o5
a008c29c:  95 2b 60 10  sll  %o5, 0x10, %o2
a008c2a0:  99 32 a0 10  srl  %o2, 0x10, %o4
a008c2a4:  80 a3 23 ff  cmp  %o4, 0x3ff
a008c2a8:  28 80 00 04  bleu,a   0xa008c2b8
a008c2ac:  da 34 21 da  sth  %o5, [ %l0 + 0x1da ]
a008c2b0:  a2 10 23 ff  mov  0x3ff, %l1
a008c2b4:  e2 34 21 da  sth  %l1, [ %l0 + 0x1da ]
a008c2b8:  40 01 32 87  call  0xa00d8cd4
a008c2bc:  01 00 00 00  nop
a008c2c0:  d2 14 21 da  lduh  [ %l0 + 0x1da ], %o1
a008c2c4:  7f ff f8 a9  call  0xa008a568
a008c2c8:  90 10 20 14  mov  0x14, %o0
a008c2cc:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a008c2d0:  e4 0c 20 8e  ldub  [ %l0 + 0x8e ], %l2	! 0xa802b08e
a008c2d4:  9a 14 a0 02  or  %l2, 2, %o5
a008c2d8:  da 2c 20 8e  stb  %o5, [ %l0 + 0x8e ]
a008c2dc:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008c2e0:  80 a0 60 13  cmp  %g1, 0x13
a008c2e4:  18 80 02 4f  bgu  0xa008cc20
a008c2e8:  94 10 20 01  mov  1, %o2
a008c2ec:  11 00 00 07  sethi  %hi(0x1c00), %o0
a008c2f0:  9b 2a 80 01  sll  %o2, %g1, %o5
a008c2f4:  a6 12 20 7e  or  %o0, 0x7e, %l3
a008c2f8:  80 8b 40 13  btst  %o5, %l3
a008c2fc:  12 80 00 0b  bne  0xa008c328
a008c300:  80 8b 63 80  btst  0x380, %o5
a008c304:  12 80 00 10  bne  0xa008c344
a008c308:  13 00 02 00  sethi  %hi(0x80000), %o1
a008c30c:  80 8b 40 09  btst  %o5, %o1
a008c310:  02 80 02 44  be  0xa008cc20
a008c314:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a008c318:  e0 0b 60 8e  ldub  [ %o5 + 0x8e ], %l0	! 0xa802b08e
a008c31c:  82 14 20 02  or  %l0, 2, %g1
a008c320:  10 80 02 40  b  0xa008cc20
a008c324:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a008c328:  40 01 35 0f  call  0xa00d9764
a008c32c:  01 00 00 00  nop
a008c330:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a008c334:  d6 0b 60 8e  ldub  [ %o5 + 0x8e ], %o3	! 0xa802b08e
a008c338:  82 12 e0 04  or  %o3, 4, %g1
a008c33c:  10 80 02 39  b  0xa008cc20
a008c340:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a008c344:  40 01 35 08  call  0xa00d9764
a008c348:  01 00 00 00  nop
a008c34c:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a008c350:  e4 0b 60 8e  ldub  [ %o5 + 0x8e ], %l2	! 0xa802b08e
a008c354:  82 14 a0 06  or  %l2, 6, %g1
a008c358:  10 80 02 32  b  0xa008cc20
a008c35c:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a008c360:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a008c364:  98 14 22 90  or  %l0, 0x290, %o4	! 0xa802d290
a008c368:  da 0b 20 13  ldub  [ %o4 + 0x13 ], %o5
a008c36c:  9a 03 60 01  inc  %o5
a008c370:  82 0b 60 ff  and  %o5, 0xff, %g1
a008c374:  80 a0 60 64  cmp  %g1, 0x64
a008c378:  08 80 01 d9  bleu  0xa008cadc
a008c37c:  a2 10 20 64  mov  0x64, %l1
a008c380:  10 bf ff d7  b  0xa008c2dc
a008c384:  e2 2b 20 13  stb  %l1, [ %o4 + 0x13 ]
a008c388:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a008c38c:  d2 0b 61 f6  ldub  [ %o5 + 0x1f6 ], %o1	! 0xa802e1f6
a008c390:  82 02 60 01  add  %o1, 1, %g1
a008c394:  80 88 60 ff  btst  0xff, %g1
a008c398:  12 80 00 03  bne  0xa008c3a4
a008c39c:  a0 13 61 f6  or  %o5, 0x1f6, %l0
a008c3a0:  82 10 3f ff  mov  -1, %g1
a008c3a4:  c2 2b 61 f6  stb  %g1, [ %o5 + 0x1f6 ]
a008c3a8:  10 80 01 62  b  0xa008c930
a008c3ac:  a0 04 3f fa  add  %l0, -6, %l0
a008c3b0:  40 02 68 c0  call  0xa01266b0
a008c3b4:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a008c3b8:  94 0a 20 ff  and  %o0, 0xff, %o2
a008c3bc:  80 a2 a0 02  cmp  %o2, 2
a008c3c0:  22 80 01 f8  be,a   0xa008cba0
a008c3c4:  c0 2c 23 bc  clrb  [ %l0 + 0x3bc ]
a008c3c8:  90 02 20 01  inc  %o0
a008c3cc:  d0 2c 23 bc  stb  %o0, [ %l0 + 0x3bc ]
a008c3d0:  90 0a 20 ff  and  %o0, 0xff, %o0
a008c3d4:  40 02 68 5a  call  0xa012653c
a008c3d8:  01 00 00 00  nop
a008c3dc:  d2 0c 23 bc  ldub  [ %l0 + 0x3bc ], %o1
a008c3e0:  7f ff f8 62  call  0xa008a568
a008c3e4:  90 10 20 15  mov  0x15, %o0
a008c3e8:  10 bf ff be  b  0xa008c2e0
a008c3ec:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008c3f0:  40 02 e5 c2  call  0xa0145af8
a008c3f4:  90 10 20 10  mov  0x10, %o0
a008c3f8:  99 2a 20 10  sll  %o0, 0x10, %o4
a008c3fc:  9f 33 20 10  srl  %o4, 0x10, %o7
a008c400:  80 a3 e0 01  cmp  %o7, 1
a008c404:  02 80 01 f6  be  0xa008cbdc
a008c408:  90 10 20 10  mov  0x10, %o0
a008c40c:  92 10 20 01  mov  1, %o1
a008c410:  40 02 e6 13  call  0xa0145c5c
a008c414:  01 00 00 00  nop
a008c418:  90 10 20 f7  mov  0xf7, %o0	! 0xf7
a008c41c:  40 02 e9 cd  call  0xa0146b50
a008c420:  92 10 20 00  clr  %o1
a008c424:  40 02 e5 b5  call  0xa0145af8
a008c428:  90 10 20 10  mov  0x10, %o0
a008c42c:  a1 2a 20 10  sll  %o0, 0x10, %l0
a008c430:  80 a4 20 00  cmp  %l0, 0
a008c434:  02 80 01 95  be  0xa008ca88
a008c438:  19 00 04 00  sethi  %hi(0x100000), %o4
a008c43c:  13 00 04 00  sethi  %hi(0x100000), %o1
a008c440:  d0 0a 62 87  ldub  [ %o1 + 0x287 ], %o0	! 0x100287
a008c444:  94 02 20 0b  add  %o0, 0xb, %o2
a008c448:  a5 2a a0 10  sll  %o2, 0x10, %l2
a008c44c:  23 00 04 00  sethi  %hi(0x100000), %l1
a008c450:  93 34 a0 10  srl  %l2, 0x10, %o1
a008c454:  98 14 62 a8  or  %l1, 0x2a8, %o4
a008c458:  90 10 20 00  clr  %o0
a008c45c:  94 10 20 13  mov  0x13, %o2
a008c460:  96 10 20 03  mov  3, %o3
a008c464:  40 00 5b 50  call  0xa00a31a4
a008c468:  9a 10 20 00  clr  %o5
a008c46c:  40 02 e3 bd  call  0xa0145360
a008c470:  90 10 20 01  mov  1, %o0
a008c474:  10 bf ff 9b  b  0xa008c2e0
a008c478:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008c47c:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a008c480:  c2 0c 23 ba  ldub  [ %l0 + 0x3ba ], %g1	! 0xa802afba
a008c484:  9a 08 60 ff  and  %g1, 0xff, %o5
a008c488:  80 a3 60 07  cmp  %o5, 7
a008c48c:  02 80 01 e2  be  0xa008cc14
a008c490:  80 a3 60 06  cmp  %o5, 6
a008c494:  02 80 01 d9  be  0xa008cbf8
a008c498:  9a 00 60 01  add  %g1, 1, %o5
a008c49c:  90 10 20 01  mov  1, %o0
a008c4a0:  40 02 6c 44  call  0xa01275b0
a008c4a4:  da 2c 23 ba  stb  %o5, [ %l0 + 0x3ba ]
a008c4a8:  d0 0c 23 ba  ldub  [ %l0 + 0x3ba ], %o0
a008c4ac:  40 02 6c 9e  call  0xa0127724
a008c4b0:  01 00 00 00  nop
a008c4b4:  d2 0c 23 ba  ldub  [ %l0 + 0x3ba ], %o1
a008c4b8:  7f ff f8 2c  call  0xa008a568
a008c4bc:  90 10 20 16  mov  0x16, %o0
a008c4c0:  10 bf ff 88  b  0xa008c2e0
a008c4c4:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008c4c8:  40 02 e5 8c  call  0xa0145af8
a008c4cc:  90 10 20 02  mov  2, %o0
a008c4d0:  83 2a 20 10  sll  %o0, 0x10, %g1
a008c4d4:  97 30 60 10  srl  %g1, 0x10, %o3
a008c4d8:  80 a2 e0 01  cmp  %o3, 1
a008c4dc:  02 80 01 be  be  0xa008cbd4
a008c4e0:  90 10 20 02  mov  2, %o0
a008c4e4:  92 10 20 01  mov  1, %o1
a008c4e8:  40 02 e5 dd  call  0xa0145c5c
a008c4ec:  01 00 00 00  nop
a008c4f0:  90 10 20 d3  mov  0xd3, %o0	! 0xd3
a008c4f4:  40 02 e9 97  call  0xa0146b50
a008c4f8:  92 10 20 00  clr  %o1
a008c4fc:  40 02 e5 7f  call  0xa0145af8
a008c500:  90 10 20 02  mov  2, %o0
a008c504:  9f 2a 20 10  sll  %o0, 0x10, %o7
a008c508:  80 a3 e0 00  cmp  %o7, 0
a008c50c:  22 80 01 56  be,a   0xa008ca64
a008c510:  03 00 04 00  sethi  %hi(0x100000), %g1
a008c514:  15 00 04 00  sethi  %hi(0x100000), %o2
a008c518:  e4 0a a2 8a  ldub  [ %o2 + 0x28a ], %l2	! 0x10028a
a008c51c:  a2 04 a0 0b  add  %l2, 0xb, %l1
a008c520:  a1 2c 60 10  sll  %l1, 0x10, %l0
a008c524:  19 00 04 00  sethi  %hi(0x100000), %o4
a008c528:  93 34 20 10  srl  %l0, 0x10, %o1
a008c52c:  98 13 22 a8  or  %o4, 0x2a8, %o4
a008c530:  90 10 20 00  clr  %o0
a008c534:  10 bf ff cb  b  0xa008c460
a008c538:  94 10 20 14  mov  0x14, %o2
a008c53c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a008c540:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a008c544:  e4 0c 21 d5  ldub  [ %l0 + 0x1d5 ], %l2
a008c548:  a2 1c a0 01  xor  %l2, 1, %l1
a008c54c:  90 10 20 ca  mov  0xca, %o0
a008c550:  92 10 20 00  clr  %o1
a008c554:  40 02 e9 7f  call  0xa0146b50
a008c558:  e2 2c 21 d5  stb  %l1, [ %l0 + 0x1d5 ]
a008c55c:  90 10 20 00  clr  %o0
a008c560:  40 02 e9 83  call  0xa0146b6c
a008c564:  92 10 20 00  clr  %o1
a008c568:  d8 0c 21 d5  ldub  [ %l0 + 0x1d5 ], %o4
a008c56c:  80 a3 20 01  cmp  %o4, 1
a008c570:  02 80 01 84  be  0xa008cb80
a008c574:  25 00 04 00  sethi  %hi(0x100000), %l2
a008c578:  e2 0c a2 7b  ldub  [ %l2 + 0x27b ], %l1	! 0x10027b
a008c57c:  a0 04 60 08  add  %l1, 8, %l0
a008c580:  99 2c 20 10  sll  %l0, 0x10, %o4
a008c584:  93 33 20 10  srl  %o4, 0x10, %o1
a008c588:  1f 00 04 00  sethi  %hi(0x100000), %o7
a008c58c:  98 13 e2 a0  or  %o7, 0x2a0, %o4	! 0x1002a0
a008c590:  90 10 20 00  clr  %o0
a008c594:  94 10 20 0f  mov  0xf, %o2
a008c598:  96 10 20 03  mov  3, %o3
a008c59c:  40 00 5b 02  call  0xa00a31a4
a008c5a0:  9a 10 20 00  clr  %o5
a008c5a4:  10 bf ff 4f  b  0xa008c2e0
a008c5a8:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008c5ac:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a008c5b0:  98 14 22 90  or  %l0, 0x290, %o4	! 0xa802d290
a008c5b4:  25 00 00 15  sethi  %hi(0x5400), %l2
a008c5b8:  82 14 a1 aa  or  %l2, 0x1aa, %g1	! 0x55aa
a008c5bc:  e2 13 21 f6  lduh  [ %o4 + 0x1f6 ], %l1
a008c5c0:  80 a4 40 01  cmp  %l1, %g1
a008c5c4:  02 80 01 8b  be  0xa008cbf0
a008c5c8:  11 3f ff ee  sethi  %hi(0xffffb800), %o0
a008c5cc:  c2 33 21 f6  sth  %g1, [ %o4 + 0x1f6 ]
a008c5d0:  92 10 20 00  clr  %o1
a008c5d4:  40 02 e9 5f  call  0xa0146b50
a008c5d8:  90 10 20 d6  mov  0xd6, %o0
a008c5dc:  82 14 22 90  or  %l0, 0x290, %g1
a008c5e0:  1b 00 00 15  sethi  %hi(0x5400), %o5
a008c5e4:  d4 10 61 f6  lduh  [ %g1 + 0x1f6 ], %o2
a008c5e8:  92 13 61 aa  or  %o5, 0x1aa, %o1
a008c5ec:  80 a2 80 09  cmp  %o2, %o1
a008c5f0:  02 80 01 7d  be  0xa008cbe4
a008c5f4:  1f 00 04 00  sethi  %hi(0x100000), %o7
a008c5f8:  98 13 e2 a0  or  %o7, 0x2a0, %o4	! 0x1002a0
a008c5fc:  90 10 20 00  clr  %o0
a008c600:  92 10 20 09  mov  9, %o1
a008c604:  94 10 20 0d  mov  0xd, %o2
a008c608:  96 10 20 03  mov  3, %o3
a008c60c:  40 00 5a e6  call  0xa00a31a4
a008c610:  9a 10 20 00  clr  %o5
a008c614:  92 14 22 90  or  %l0, 0x290, %o1
a008c618:  94 10 20 00  clr  %o2
a008c61c:  96 10 21 fc  mov  0x1fc, %o3
a008c620:  40 02 fa 2c  call  0xa014aed0
a008c624:  90 10 20 30  mov  0x30, %o0
a008c628:  10 bf ff 2e  b  0xa008c2e0
a008c62c:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008c630:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a008c634:  d8 0b 63 b9  ldub  [ %o5 + 0x3b9 ], %o4	! 0xa802afb9
a008c638:  82 03 20 01  add  %o4, 1, %g1
a008c63c:  92 08 60 ff  and  %g1, 0xff, %o1
a008c640:  80 a2 60 08  cmp  %o1, 8
a008c644:  08 80 01 34  bleu  0xa008cb14
a008c648:  a0 10 20 08  mov  8, %l0
a008c64c:  10 bf ff 24  b  0xa008c2dc
a008c650:  e0 2b 63 b9  stb  %l0, [ %o5 + 0x3b9 ]
a008c654:  23 2a 00 90  sethi  %hi(0xa8024000), %l1
a008c658:  c2 0c 60 40  ldub  [ %l1 + 0x40 ], %g1	! 0xa8024040
a008c65c:  9e 18 60 01  xor  %g1, 1, %o7
a008c660:  92 0b e0 ff  and  %o7, 0xff, %o1
a008c664:  de 2c 60 40  stb  %o7, [ %l1 + 0x40 ]
a008c668:  40 03 06 40  call  0xa014df68
a008c66c:  90 10 20 0d  mov  0xd, %o0
a008c670:  90 10 20 0c  mov  0xc, %o0
a008c674:  40 03 06 3d  call  0xa014df68
a008c678:  d2 0c 60 40  ldub  [ %l1 + 0x40 ], %o1
a008c67c:  90 10 20 f4  mov  0xf4, %o0
a008c680:  40 02 e9 34  call  0xa0146b50
a008c684:  92 10 20 00  clr  %o1
a008c688:  90 10 20 00  clr  %o0
a008c68c:  40 02 e9 38  call  0xa0146b6c
a008c690:  92 10 20 00  clr  %o1
a008c694:  d6 0c 60 40  ldub  [ %l1 + 0x40 ], %o3
a008c698:  80 a2 e0 01  cmp  %o3, 1
a008c69c:  02 80 01 43  be  0xa008cba8
a008c6a0:  25 00 04 00  sethi  %hi(0x100000), %l2
a008c6a4:  03 00 04 00  sethi  %hi(0x100000), %g1
a008c6a8:  96 10 62 42  or  %g1, 0x242, %o3	! 0x100242
a008c6ac:  d8 0a e0 4e  ldub  [ %o3 + 0x4e ], %o4
a008c6b0:  9e 03 20 08  add  %o4, 8, %o7
a008c6b4:  a3 2b e0 10  sll  %o7, 0x10, %l1
a008c6b8:  93 34 60 10  srl  %l1, 0x10, %o1
a008c6bc:  d4 0a e0 4f  ldub  [ %o3 + 0x4f ], %o2
a008c6c0:  98 14 a2 a0  or  %l2, 0x2a0, %o4
a008c6c4:  10 bf ff b5  b  0xa008c598
a008c6c8:  90 10 20 00  clr  %o0
a008c6cc:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a008c6d0:  e4 0b 62 02  ldub  [ %o5 + 0x202 ], %l2	! 0xa802e202
a008c6d4:  82 04 a0 01  add  %l2, 1, %g1
a008c6d8:  80 88 60 ff  btst  0xff, %g1
a008c6dc:  12 80 00 03  bne  0xa008c6e8
a008c6e0:  a0 13 62 02  or  %o5, 0x202, %l0
a008c6e4:  82 10 3f ff  mov  -1, %g1
a008c6e8:  c2 2b 62 02  stb  %g1, [ %o5 + 0x202 ]
a008c6ec:  10 80 00 69  b  0xa008c890
a008c6f0:  a0 04 3f ee  add  %l0, -18, %l0
a008c6f4:  19 2a 00 ab  sethi  %hi(0xa802ac00), %o4
a008c6f8:  d6 0b 23 b8  ldub  [ %o4 + 0x3b8 ], %o3	! 0xa802afb8
a008c6fc:  82 02 e0 01  add  %o3, 1, %g1
a008c700:  94 08 60 ff  and  %g1, 0xff, %o2
a008c704:  80 a2 a0 07  cmp  %o2, 7
a008c708:  08 80 01 0a  bleu  0xa008cb30
a008c70c:  9e 10 20 07  mov  7, %o7
a008c710:  10 bf fe f3  b  0xa008c2dc
a008c714:  de 2b 23 b8  stb  %o7, [ %o4 + 0x3b8 ]
a008c718:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a008c71c:  d4 0b 61 f7  ldub  [ %o5 + 0x1f7 ], %o2	! 0xa802e1f7
a008c720:  82 02 a0 01  add  %o2, 1, %g1
a008c724:  80 88 60 ff  btst  0xff, %g1
a008c728:  12 80 00 03  bne  0xa008c734
a008c72c:  a0 13 61 f7  or  %o5, 0x1f7, %l0
a008c730:  82 10 3f ff  mov  -1, %g1
a008c734:  c2 2b 61 f7  stb  %g1, [ %o5 + 0x1f7 ]
a008c738:  10 80 00 7e  b  0xa008c930
a008c73c:  a0 04 3f f9  add  %l0, -7, %l0
a008c740:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a008c744:  e2 0b 61 fb  ldub  [ %o5 + 0x1fb ], %l1	! 0xa802e1fb
a008c748:  82 04 60 01  add  %l1, 1, %g1
a008c74c:  80 88 60 ff  btst  0xff, %g1
a008c750:  12 80 00 03  bne  0xa008c75c
a008c754:  a0 13 61 fb  or  %o5, 0x1fb, %l0
a008c758:  82 10 3f ff  mov  -1, %g1
a008c75c:  c2 2b 61 fb  stb  %g1, [ %o5 + 0x1fb ]
a008c760:  10 80 00 a5  b  0xa008c9f4
a008c764:  a0 04 3f f5  add  %l0, -11, %l0
a008c768:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a008c76c:  a0 14 22 90  or  %l0, 0x290, %l0	! 0xa802d290
a008c770:  de 04 21 d4  ld  [ %l0 + 0x1d4 ], %o7
a008c774:  95 33 e0 07  srl  %o7, 7, %o2
a008c778:  98 0a a0 01  and  %o2, 1, %o4
a008c77c:  82 1b 20 01  xor  %o4, 1, %g1
a008c780:  97 28 60 07  sll  %g1, 7, %o3
a008c784:  9a 0b ff 7f  and  %o7, -129, %o5
a008c788:  a4 13 40 0b  or  %o5, %o3, %l2
a008c78c:  40 01 24 63  call  0xa00d5918
a008c790:  e4 24 21 d4  st  %l2, [ %l0 + 0x1d4 ]
a008c794:  90 10 20 ea  mov  0xea, %o0
a008c798:  40 02 e8 ee  call  0xa0146b50
a008c79c:  92 10 20 00  clr  %o1
a008c7a0:  90 10 20 00  clr  %o0
a008c7a4:  40 02 e8 f2  call  0xa0146b6c
a008c7a8:  92 10 20 00  clr  %o1
a008c7ac:  23 00 04 00  sethi  %hi(0x100000), %l1
a008c7b0:  92 14 62 42  or  %l1, 0x242, %o1	! 0x100242
a008c7b4:  11 00 04 00  sethi  %hi(0x100000), %o0
a008c7b8:  e4 0a 60 4c  ldub  [ %o1 + 0x4c ], %l2
a008c7bc:  e2 0a 60 4b  ldub  [ %o1 + 0x4b ], %l1
a008c7c0:  98 12 23 30  or  %o0, 0x330, %o4
a008c7c4:  94 10 00 12  mov  %l2, %o2
a008c7c8:  90 10 20 00  clr  %o0
a008c7cc:  92 0c 60 ff  and  %l1, 0xff, %o1
a008c7d0:  96 10 20 08  mov  8, %o3
a008c7d4:  40 00 5a 74  call  0xa00a31a4
a008c7d8:  9a 10 20 00  clr  %o5
a008c7dc:  d4 04 21 d4  ld  [ %l0 + 0x1d4 ], %o2
a008c7e0:  80 8a a0 80  btst  0x80, %o2
a008c7e4:  02 80 00 99  be  0xa008ca48
a008c7e8:  82 0c 60 ff  and  %l1, 0xff, %g1
a008c7ec:  9a 0c 60 ff  and  %l1, 0xff, %o5
a008c7f0:  a2 03 60 0c  add  %o5, 0xc, %l1
a008c7f4:  93 2c 60 10  sll  %l1, 0x10, %o1
a008c7f8:  11 00 04 00  sethi  %hi(0x100000), %o0
a008c7fc:  93 32 60 10  srl  %o1, 0x10, %o1
a008c800:  94 10 00 12  mov  %l2, %o2
a008c804:  98 12 22 a8  or  %o0, 0x2a8, %o4
a008c808:  90 10 20 00  clr  %o0
a008c80c:  96 10 20 03  mov  3, %o3
a008c810:  40 00 5a 65  call  0xa00a31a4
a008c814:  9a 10 20 00  clr  %o5
a008c818:  10 bf fe ae  b  0xa008c2d0
a008c81c:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a008c820:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a008c824:  9a 13 22 90  or  %o4, 0x290, %o5	! 0xa802d290
a008c828:  c2 0b 60 0a  ldub  [ %o5 + 0xa ], %g1
a008c82c:  80 a0 60 63  cmp  %g1, 0x63
a008c830:  38 80 00 08  bgu,a   0xa008c850
a008c834:  82 13 22 90  or  %o4, 0x290, %g1
a008c838:  82 00 60 01  inc  %g1
a008c83c:  80 88 60 ff  btst  0xff, %g1
a008c840:  22 80 00 02  be,a   0xa008c848
a008c844:  82 10 3f ff  mov  -1, %g1
a008c848:  c2 2b 60 0a  stb  %g1, [ %o5 + 0xa ]
a008c84c:  82 13 22 90  or  %o4, 0x290, %g1
a008c850:  d2 08 60 0a  ldub  [ %g1 + 0xa ], %o1
a008c854:  7f ff f7 45  call  0xa008a568
a008c858:  90 10 20 0e  mov  0xe, %o0
a008c85c:  40 01 2d 61  call  0xa00d7de0
a008c860:  01 00 00 00  nop
a008c864:  10 bf fe 9f  b  0xa008c2e0
a008c868:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008c86c:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a008c870:  d2 0b 62 04  ldub  [ %o5 + 0x204 ], %o1	! 0xa802e204
a008c874:  82 02 60 01  add  %o1, 1, %g1
a008c878:  80 88 60 ff  btst  0xff, %g1
a008c87c:  12 80 00 03  bne  0xa008c888
a008c880:  a0 13 62 04  or  %o5, 0x204, %l0
a008c884:  82 10 3f ff  mov  -1, %g1
a008c888:  c2 2b 62 04  stb  %g1, [ %o5 + 0x204 ]
a008c88c:  a0 04 3f ec  add  %l0, -20, %l0
a008c890:  d2 0c 20 12  ldub  [ %l0 + 0x12 ], %o1
a008c894:  7f ff f7 35  call  0xa008a568
a008c898:  90 10 20 04  mov  4, %o0
a008c89c:  d2 0c 20 13  ldub  [ %l0 + 0x13 ], %o1
a008c8a0:  7f ff f7 32  call  0xa008a568
a008c8a4:  90 10 20 05  mov  5, %o0
a008c8a8:  d2 0c 20 14  ldub  [ %l0 + 0x14 ], %o1
a008c8ac:  7f ff f7 2f  call  0xa008a568
a008c8b0:  90 10 20 06  mov  6, %o0
a008c8b4:  10 bf fe 8b  b  0xa008c2e0
a008c8b8:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008c8bc:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a008c8c0:  d0 0b 62 03  ldub  [ %o5 + 0x203 ], %o0	! 0xa802e203
a008c8c4:  82 02 20 01  add  %o0, 1, %g1
a008c8c8:  80 88 60 ff  btst  0xff, %g1
a008c8cc:  12 80 00 03  bne  0xa008c8d8
a008c8d0:  a0 13 62 03  or  %o5, 0x203, %l0
a008c8d4:  82 10 3f ff  mov  -1, %g1
a008c8d8:  c2 2b 62 03  stb  %g1, [ %o5 + 0x203 ]
a008c8dc:  10 bf ff ed  b  0xa008c890
a008c8e0:  a0 04 3f ed  add  %l0, -19, %l0
a008c8e4:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a008c8e8:  d8 0b 61 f9  ldub  [ %o5 + 0x1f9 ], %o4	! 0xa802e1f9
a008c8ec:  82 03 20 01  add  %o4, 1, %g1
a008c8f0:  80 88 60 ff  btst  0xff, %g1
a008c8f4:  12 80 00 03  bne  0xa008c900
a008c8f8:  a0 13 61 f9  or  %o5, 0x1f9, %l0
a008c8fc:  82 10 3f ff  mov  -1, %g1
a008c900:  c2 2b 61 f9  stb  %g1, [ %o5 + 0x1f9 ]
a008c904:  10 80 00 3c  b  0xa008c9f4
a008c908:  a0 04 3f f7  add  %l0, -9, %l0
a008c90c:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a008c910:  d6 0b 61 f8  ldub  [ %o5 + 0x1f8 ], %o3	! 0xa802e1f8
a008c914:  82 02 e0 01  add  %o3, 1, %g1
a008c918:  80 88 60 ff  btst  0xff, %g1
a008c91c:  12 80 00 03  bne  0xa008c928
a008c920:  a0 13 61 f8  or  %o5, 0x1f8, %l0
a008c924:  82 10 3f ff  mov  -1, %g1
a008c928:  c2 2b 61 f8  stb  %g1, [ %o5 + 0x1f8 ]
a008c92c:  a0 04 3f f8  add  %l0, -8, %l0
a008c930:  d2 0c 20 06  ldub  [ %l0 + 6 ], %o1
a008c934:  7f ff f7 0d  call  0xa008a568
a008c938:  90 10 20 01  mov  1, %o0
a008c93c:  d2 0c 20 07  ldub  [ %l0 + 7 ], %o1
a008c940:  7f ff f7 0a  call  0xa008a568
a008c944:  90 10 20 02  mov  2, %o0
a008c948:  d2 0c 20 08  ldub  [ %l0 + 8 ], %o1
a008c94c:  7f ff f7 07  call  0xa008a568
a008c950:  90 10 20 03  mov  3, %o0
a008c954:  10 bf fe 63  b  0xa008c2e0
a008c958:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008c95c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a008c960:  9a 13 22 90  or  %o4, 0x290, %o5	! 0xa802d290
a008c964:  c2 0b 60 09  ldub  [ %o5 + 9 ], %g1
a008c968:  80 a0 60 63  cmp  %g1, 0x63
a008c96c:  38 80 00 09  bgu,a   0xa008c990
a008c970:  d2 0b 60 09  ldub  [ %o5 + 9 ], %o1
a008c974:  82 00 60 01  inc  %g1
a008c978:  80 88 60 ff  btst  0xff, %g1
a008c97c:  22 80 00 02  be,a   0xa008c984
a008c980:  82 10 3f ff  mov  -1, %g1
a008c984:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a008c988:  9a 13 22 90  or  %o4, 0x290, %o5
a008c98c:  d2 0b 60 09  ldub  [ %o5 + 9 ], %o1
a008c990:  7f ff f6 f6  call  0xa008a568
a008c994:  90 10 20 0d  mov  0xd, %o0
a008c998:  40 01 30 cf  call  0xa00d8cd4
a008c99c:  01 00 00 00  nop
a008c9a0:  10 bf fe 50  b  0xa008c2e0
a008c9a4:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008c9a8:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a008c9ac:  98 14 22 90  or  %l0, 0x290, %o4	! 0xa802d290
a008c9b0:  de 0b 20 12  ldub  [ %o4 + 0x12 ], %o7
a008c9b4:  9a 03 e0 01  add  %o7, 1, %o5
a008c9b8:  82 0b 60 ff  and  %o5, 0xff, %g1
a008c9bc:  80 a0 60 64  cmp  %g1, 0x64
a008c9c0:  08 80 00 39  bleu  0xa008caa4
a008c9c4:  a2 10 20 64  mov  0x64, %l1
a008c9c8:  10 bf fe 45  b  0xa008c2dc
a008c9cc:  e2 2b 20 12  stb  %l1, [ %o4 + 0x12 ]
a008c9d0:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a008c9d4:  e0 0b 61 fa  ldub  [ %o5 + 0x1fa ], %l0	! 0xa802e1fa
a008c9d8:  82 04 20 01  add  %l0, 1, %g1
a008c9dc:  80 88 60 ff  btst  0xff, %g1
a008c9e0:  12 80 00 03  bne  0xa008c9ec
a008c9e4:  a0 13 61 fa  or  %o5, 0x1fa, %l0
a008c9e8:  82 10 3f ff  mov  -1, %g1
a008c9ec:  c2 2b 61 fa  stb  %g1, [ %o5 + 0x1fa ]
a008c9f0:  a0 04 3f f6  add  %l0, -10, %l0
a008c9f4:  d2 0c 20 09  ldub  [ %l0 + 9 ], %o1
a008c9f8:  7f ff f6 dc  call  0xa008a568
a008c9fc:  90 10 20 0a  mov  0xa, %o0
a008ca00:  d2 0c 20 0a  ldub  [ %l0 + 0xa ], %o1
a008ca04:  7f ff f6 d9  call  0xa008a568
a008ca08:  90 10 20 0b  mov  0xb, %o0
a008ca0c:  d2 0c 20 0b  ldub  [ %l0 + 0xb ], %o1
a008ca10:  7f ff f6 d6  call  0xa008a568
a008ca14:  90 10 20 0c  mov  0xc, %o0
a008ca18:  10 bf fe 32  b  0xa008c2e0
a008ca1c:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008ca20:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a008ca24:  98 14 22 90  or  %l0, 0x290, %o4	! 0xa802d290
a008ca28:  da 0b 20 14  ldub  [ %o4 + 0x14 ], %o5
a008ca2c:  9a 03 60 01  inc  %o5
a008ca30:  82 0b 60 ff  and  %o5, 0xff, %g1
a008ca34:  80 a0 60 64  cmp  %g1, 0x64
a008ca38:  08 80 00 44  bleu  0xa008cb48
a008ca3c:  a2 10 20 64  mov  0x64, %l1
a008ca40:  10 bf fe 27  b  0xa008c2dc
a008ca44:  e2 2b 20 14  stb  %l1, [ %o4 + 0x14 ]
a008ca48:  9e 00 60 0c  add  %g1, 0xc, %o7
a008ca4c:  94 10 00 12  mov  %l2, %o2
a008ca50:  97 2b e0 10  sll  %o7, 0x10, %o3
a008ca54:  25 00 04 00  sethi  %hi(0x100000), %l2
a008ca58:  93 32 e0 10  srl  %o3, 0x10, %o1
a008ca5c:  10 bf ff 6b  b  0xa008c808
a008ca60:  98 14 a2 a0  or  %l2, 0x2a0, %o4
a008ca64:  d6 08 62 8a  ldub  [ %g1 + 0x28a ], %o3
a008ca68:  11 00 04 00  sethi  %hi(0x100000), %o0
a008ca6c:  9a 02 e0 0b  add  %o3, 0xb, %o5
a008ca70:  93 2b 60 10  sll  %o5, 0x10, %o1
a008ca74:  98 12 22 a0  or  %o0, 0x2a0, %o4
a008ca78:  93 32 60 10  srl  %o1, 0x10, %o1
a008ca7c:  90 10 20 00  clr  %o0
a008ca80:  10 bf fe 78  b  0xa008c460
a008ca84:  94 10 20 14  mov  0x14, %o2
a008ca88:  de 0b 22 87  ldub  [ %o4 + 0x287 ], %o7
a008ca8c:  82 03 e0 0b  add  %o7, 0xb, %g1
a008ca90:  97 28 60 10  sll  %g1, 0x10, %o3
a008ca94:  1b 00 04 00  sethi  %hi(0x100000), %o5
a008ca98:  93 32 e0 10  srl  %o3, 0x10, %o1
a008ca9c:  10 bf fe 6f  b  0xa008c458
a008caa0:  98 13 62 a0  or  %o5, 0x2a0, %o4
a008caa4:  9f 28 60 08  sll  %g1, 8, %o7
a008caa8:  96 23 c0 01  sub  %o7, %g1, %o3
a008caac:  15 14 7a e1  sethi  %hi(0x51eb8400), %o2
a008cab0:  92 02 e0 32  add  %o3, 0x32, %o1
a008cab4:  82 12 a1 1f  or  %o2, 0x11f, %g1
a008cab8:  80 52 40 01  umul  %o1, %g1, %g0
a008cabc:  91 40 00 00  rd  %y, %o0
a008cac0:  a5 2a 20 0b  sll  %o0, 0xb, %l2
a008cac4:  da 2b 20 12  stb  %o5, [ %o4 + 0x12 ]
a008cac8:  93 34 a0 10  srl  %l2, 0x10, %o1
a008cacc:  7f ff f6 a7  call  0xa008a568
a008cad0:  90 10 20 07  mov  7, %o0
a008cad4:  10 bf fe 03  b  0xa008c2e0
a008cad8:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008cadc:  9f 28 60 08  sll  %g1, 8, %o7
a008cae0:  96 23 c0 01  sub  %o7, %g1, %o3
a008cae4:  15 14 7a e1  sethi  %hi(0x51eb8400), %o2
a008cae8:  92 02 e0 32  add  %o3, 0x32, %o1
a008caec:  82 12 a1 1f  or  %o2, 0x11f, %g1
a008caf0:  80 52 40 01  umul  %o1, %g1, %g0
a008caf4:  91 40 00 00  rd  %y, %o0
a008caf8:  a5 2a 20 0b  sll  %o0, 0xb, %l2
a008cafc:  da 2b 20 13  stb  %o5, [ %o4 + 0x13 ]
a008cb00:  93 34 a0 10  srl  %l2, 0x10, %o1
a008cb04:  7f ff f6 99  call  0xa008a568
a008cb08:  90 10 20 08  mov  8, %o0
a008cb0c:  10 bf fd f5  b  0xa008c2e0
a008cb10:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008cb14:  c2 2b 63 b9  stb  %g1, [ %o5 + 0x3b9 ]
a008cb18:  7f ff f6 94  call  0xa008a568
a008cb1c:  90 10 20 10  mov  0x10, %o0
a008cb20:  7f ff fa b0  call  0xa008b5e0
a008cb24:  01 00 00 00  nop
a008cb28:  10 bf fd ee  b  0xa008c2e0
a008cb2c:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008cb30:  7f ff fa 14  call  0xa008b380
a008cb34:  c2 2b 23 b8  stb  %g1, [ %o4 + 0x3b8 ]
a008cb38:  7f ff fa aa  call  0xa008b5e0
a008cb3c:  01 00 00 00  nop
a008cb40:  10 bf fd e8  b  0xa008c2e0
a008cb44:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008cb48:  9f 28 60 08  sll  %g1, 8, %o7
a008cb4c:  96 23 c0 01  sub  %o7, %g1, %o3
a008cb50:  15 14 7a e1  sethi  %hi(0x51eb8400), %o2
a008cb54:  92 02 e0 32  add  %o3, 0x32, %o1
a008cb58:  82 12 a1 1f  or  %o2, 0x11f, %g1
a008cb5c:  80 52 40 01  umul  %o1, %g1, %g0
a008cb60:  91 40 00 00  rd  %y, %o0
a008cb64:  a5 2a 20 0b  sll  %o0, 0xb, %l2
a008cb68:  da 2b 20 14  stb  %o5, [ %o4 + 0x14 ]
a008cb6c:  93 34 a0 10  srl  %l2, 0x10, %o1
a008cb70:  7f ff f6 7e  call  0xa008a568
a008cb74:  90 10 20 09  mov  9, %o0
a008cb78:  10 bf fd da  b  0xa008c2e0
a008cb7c:  c2 0c e3 bd  ldub  [ %l3 + 0x3bd ], %g1
a008cb80:  03 00 04 00  sethi  %hi(0x100000), %g1
a008cb84:  d6 08 62 7b  ldub  [ %g1 + 0x27b ], %o3	! 0x10027b
a008cb88:  9a 02 e0 08  add  %o3, 8, %o5
a008cb8c:  93 2b 60 10  sll  %o5, 0x10, %o1
a008cb90:  15 00 04 00  sethi  %hi(0x100000), %o2
a008cb94:  93 32 60 10  srl  %o1, 0x10, %o1
a008cb98:  10 bf fe 7e  b  0xa008c590
a008cb9c:  98 12 a2 a8  or  %o2, 0x2a8, %o4
a008cba0:  10 bf fe 0d  b  0xa008c3d4
a008cba4:  90 10 20 00  clr  %o0
a008cba8:  1b 00 04 00  sethi  %hi(0x100000), %o5
a008cbac:  90 13 62 42  or  %o5, 0x242, %o0	! 0x100242
a008cbb0:  e0 0a 20 4e  ldub  [ %o0 + 0x4e ], %l0
a008cbb4:  92 04 20 08  add  %l0, 8, %o1
a008cbb8:  95 2a 60 10  sll  %o1, 0x10, %o2
a008cbbc:  93 32 a0 10  srl  %o2, 0x10, %o1
a008cbc0:  d4 0a 20 4f  ldub  [ %o0 + 0x4f ], %o2
a008cbc4:  19 00 04 00  sethi  %hi(0x100000), %o4
a008cbc8:  98 13 22 a8  or  %o4, 0x2a8, %o4	! 0x1002a8
a008cbcc:  10 bf fe 73  b  0xa008c598
a008cbd0:  90 10 20 00  clr  %o0
a008cbd4:  10 bf fe 45  b  0xa008c4e8
a008cbd8:  92 10 20 00  clr  %o1
a008cbdc:  10 bf fe 0d  b  0xa008c410
a008cbe0:  92 10 20 00  clr  %o1
a008cbe4:  17 00 04 00  sethi  %hi(0x100000), %o3
a008cbe8:  10 bf fe 85  b  0xa008c5fc
a008cbec:  98 12 e2 a8  or  %o3, 0x2a8, %o4	! 0x1002a8
a008cbf0:  10 bf fe 77  b  0xa008c5cc
a008cbf4:  82 12 23 99  or  %o0, 0x399, %g1
a008cbf8:  92 00 60 01  add  %g1, 1, %o1
a008cbfc:  d2 2c 23 ba  stb  %o1, [ %l0 + 0x3ba ]
a008cc00:  90 10 20 01  mov  1, %o0
a008cc04:  40 02 6a 6b  call  0xa01275b0
a008cc08:  01 00 00 00  nop
a008cc0c:  10 bf fe 28  b  0xa008c4ac
a008cc10:  90 10 20 00  clr  %o0	! 0x0
a008cc14:  c0 2c 23 ba  clrb  [ %l0 + 0x3ba ]
a008cc18:  10 bf ff fb  b  0xa008cc04
a008cc1c:  90 10 20 00  clr  %o0
a008cc20:  81 c7 e0 08  ret
a008cc24:  81 e8 00 00  restore
