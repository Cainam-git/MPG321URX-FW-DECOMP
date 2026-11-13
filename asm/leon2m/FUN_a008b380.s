# leon2m FUN_a008b380 0xa008b380-0xa008b58c (524 bytes)
a008b380:  9d e3 bf 78  save  %sp, -136, %sp
a008b384:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a008b388:  94 10 20 ea  mov  0xea, %o2
a008b38c:  92 10 23 a9  mov  0x3a9, %o1
a008b390:  e0 0a e3 b8  ldub  [ %o3 + 0x3b8 ], %l0
a008b394:  d4 37 bf e8  sth  %o2, [ %fp + -24 ]
a008b398:  9a 10 21 d4  mov  0x1d4, %o5
a008b39c:  d2 37 bf ec  sth  %o1, [ %fp + -20 ]
a008b3a0:  82 10 27 53  mov  0x753, %g1
a008b3a4:  90 04 00 10  add  %l0, %l0, %o0
a008b3a8:  da 37 bf ea  sth  %o5, [ %fp + -22 ]
a008b3ac:  c2 37 bf ee  sth  %g1, [ %fp + -18 ]
a008b3b0:  1f 00 00 07  sethi  %hi(0x1c00), %o7
a008b3b4:  15 00 00 0e  sethi  %hi(0x3800), %o2
a008b3b8:  13 00 00 1d  sethi  %hi(0x7400), %o1
a008b3bc:  98 13 e1 4c  or  %o7, 0x14c, %o4
a008b3c0:  9a 12 a2 98  or  %o2, 0x298, %o5
a008b3c4:  a0 07 bf f8  add  %fp, -8, %l0
a008b3c8:  a2 10 2e a6  mov  0xea6, %l1
a008b3cc:  82 12 61 30  or  %o1, 0x130, %g1
a008b3d0:  d8 37 bf f2  sth  %o4, [ %fp + -14 ]
a008b3d4:  da 37 bf f4  sth  %o5, [ %fp + -12 ]
a008b3d8:  e2 37 bf f0  sth  %l1, [ %fp + -16 ]
a008b3dc:  c2 37 bf f6  sth  %g1, [ %fp + -10 ]
a008b3e0:  96 02 00 10  add  %o0, %l0, %o3
a008b3e4:  d6 12 ff f0  lduh  [ %o3 + -16 ], %o3
a008b3e8:  98 10 20 00  clr  %o4
a008b3ec:  9a 10 20 00  clr  %o5
a008b3f0:  90 04 00 0d  add  %l0, %o5, %o0
a008b3f4:  98 03 20 01  inc  %o4
a008b3f8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008b3fc:  80 a3 60 08  cmp  %o5, 8
a008b400:  08 bf ff fc  bleu  0xa008b3f0
a008b404:  c0 2a 3f e0  clrb  [ %o0 + -32 ]
a008b408:  99 2a e0 10  sll  %o3, 0x10, %o4
a008b40c:  9b 33 20 10  srl  %o4, 0x10, %o5
a008b410:  80 a3 63 e7  cmp  %o5, 0x3e7
a008b414:  08 80 00 38  bleu  0xa008b4f4
a008b418:  03 00 00 09  sethi  %hi(0x2400), %g1
a008b41c:  82 10 63 10  or  %g1, 0x310, %g1	! 0x2710
a008b420:  80 a3 40 01  cmp  %o5, %g1
a008b424:  08 80 00 26  bleu  0xa008b4bc
a008b428:  17 33 33 33  sethi  %hi(0xcccccc00), %o3
a008b42c:  17 34 6d c5  sethi  %hi(0xd1b71400), %o3
a008b430:  92 12 e3 59  or  %o3, 0x359, %o1	! 0xd1b71759
a008b434:  80 53 40 09  umul  %o5, %o1, %g0
a008b438:  95 40 00 00  rd  %y, %o2
a008b43c:  93 32 a0 0d  srl  %o2, 0xd, %o1
a008b440:  a2 5a 40 01  smul  %o1, %g1, %l1
a008b444:  82 23 40 11  sub  %o5, %l1, %g1
a008b448:  9f 28 60 10  sll  %g1, 0x10, %o7
a008b44c:  19 04 18 93  sethi  %hi(0x10624c00), %o4
a008b450:  97 33 e0 10  srl  %o7, 0x10, %o3
a008b454:  90 13 21 d3  or  %o4, 0x1d3, %o0
a008b458:  80 52 c0 08  umul  %o3, %o0, %g0
a008b45c:  a3 40 00 00  rd  %y, %l1
a008b460:  97 2c 60 0a  sll  %l1, 0xa, %o3
a008b464:  95 2a 60 10  sll  %o1, 0x10, %o2
a008b468:  1b 00 04 01  sethi  %hi(0x100400), %o5
a008b46c:  a2 07 bf d8  add  %fp, -40, %l1
a008b470:  92 13 60 88  or  %o5, 0x88, %o1
a008b474:  95 32 a0 10  srl  %o2, 0x10, %o2
a008b478:  97 32 e0 10  srl  %o3, 0x10, %o3
a008b47c:  40 03 30 de  call  0xa01577f4
a008b480:  90 10 00 11  mov  %l1, %o0
a008b484:  98 10 20 00  clr  %o4
a008b488:  82 10 20 00  clr  %g1
a008b48c:  90 04 00 01  add  %l0, %g1, %o0
a008b490:  da 0a 3f e0  ldub  [ %o0 + -32 ], %o5
a008b494:  80 a3 60 00  cmp  %o5, 0
a008b498:  02 80 00 26  be  0xa008b530
a008b49c:  96 03 3f ff  add  %o4, -1, %o3
a008b4a0:  98 03 20 01  inc  %o4
a008b4a4:  82 0b 20 ff  and  %o4, 0xff, %g1
a008b4a8:  80 a0 60 08  cmp  %g1, 8
a008b4ac:  08 bf ff f9  bleu  0xa008b490
a008b4b0:  90 04 00 01  add  %l0, %g1, %o0
a008b4b4:  10 80 00 1f  b  0xa008b530
a008b4b8:  96 03 3f ff  add  %o4, -1, %o3
a008b4bc:  92 12 e0 cd  or  %o3, 0xcd, %o1
a008b4c0:  80 53 40 09  umul  %o5, %o1, %g0
a008b4c4:  95 40 00 00  rd  %y, %o2
a008b4c8:  91 32 a0 03  srl  %o2, 3, %o0
a008b4cc:  a3 2a 20 02  sll  %o0, 2, %l1
a008b4d0:  82 04 40 08  add  %l1, %o0, %g1
a008b4d4:  9e 00 40 01  add  %g1, %g1, %o7
a008b4d8:  98 23 40 0f  sub  %o5, %o7, %o4
a008b4dc:  1b 00 04 01  sethi  %hi(0x100400), %o5
a008b4e0:  97 2b 20 10  sll  %o4, 0x10, %o3
a008b4e4:  a2 07 bf d8  add  %fp, -40, %l1
a008b4e8:  95 2a 20 10  sll  %o0, 0x10, %o2
a008b4ec:  10 bf ff e2  b  0xa008b474
a008b4f0:  92 13 60 98  or  %o5, 0x98, %o1
a008b4f4:  1f 33 33 33  sethi  %hi(0xcccccc00), %o7
a008b4f8:  98 13 e0 cd  or  %o7, 0xcd, %o4	! 0xcccccccd
a008b4fc:  80 53 40 0c  umul  %o5, %o4, %g0
a008b500:  95 40 00 00  rd  %y, %o2
a008b504:  83 32 a0 03  srl  %o2, 3, %g1
a008b508:  91 28 60 02  sll  %g1, 2, %o0
a008b50c:  96 02 00 01  add  %o0, %g1, %o3
a008b510:  92 02 c0 0b  add  %o3, %o3, %o1
a008b514:  a2 23 40 09  sub  %o5, %o1, %l1
a008b518:  97 2c 60 10  sll  %l1, 0x10, %o3
a008b51c:  1f 00 04 01  sethi  %hi(0x100400), %o7
a008b520:  a2 07 bf d8  add  %fp, -40, %l1
a008b524:  95 28 60 10  sll  %g1, 0x10, %o2
a008b528:  10 bf ff d3  b  0xa008b474
a008b52c:  92 13 e0 a8  or  %o7, 0xa8, %o1
a008b530:  d6 2f bf d8  stb  %o3, [ %fp + -40 ]
a008b534:  90 10 20 00  clr  %o0
a008b538:  40 02 ed 8d  call  0xa0146b6c
a008b53c:  92 10 20 00  clr  %o1
a008b540:  90 10 20 d9  mov  0xd9, %o0
a008b544:  40 02 ed 83  call  0xa0146b50
a008b548:  92 10 20 00  clr  %o1
a008b54c:  13 00 04 00  sethi  %hi(0x100000), %o1
a008b550:  a0 12 62 42  or  %o1, 0x242, %l0	! 0x100242
a008b554:  d4 0c 20 2d  ldub  [ %l0 + 0x2d ], %o2
a008b558:  c2 0c 20 2f  ldub  [ %l0 + 0x2f ], %g1
a008b55c:  9e 02 80 01  add  %o2, %g1, %o7
a008b560:  99 2b e0 10  sll  %o7, 0x10, %o4
a008b564:  93 33 20 10  srl  %o4, 0x10, %o1
a008b568:  d4 0c 20 2e  ldub  [ %l0 + 0x2e ], %o2
a008b56c:  98 10 00 11  mov  %l1, %o4
a008b570:  90 10 20 00  clr  %o0
a008b574:  d6 0f bf d8  ldub  [ %fp + -40 ], %o3
a008b578:  40 00 5f 0b  call  0xa00a31a4
a008b57c:  9a 10 20 00  clr  %o5
a008b580:  01 00 00 00  nop
a008b584:  81 c7 e0 08  ret
a008b588:  81 e8 00 00  restore
