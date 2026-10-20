# leon2s FUN_a00ca4e8 0xa00ca4e8-0xa00ca6d4 (492 bytes)
a00ca4e8:  9d e3 bf 90  save  %sp, -112, %sp
a00ca4ec:  39 33 c0 63  sethi  %hi(0xcf018c00), %i4
a00ca4f0:  ba 17 22 10  or  %i4, 0x210, %i5	! 0xcf018e10
a00ca4f4:  82 10 20 1b  mov  0x1b, %g1
a00ca4f8:  c2 27 40 00  st  %g1, [ %i5 ]
a00ca4fc:  b6 17 22 14  or  %i4, 0x214, %i3
a00ca500:  82 10 20 80  mov  0x80, %g1
a00ca504:  c2 26 c0 00  st  %g1, [ %i3 ]
a00ca508:  ba 17 22 18  or  %i4, 0x218, %i5
a00ca50c:  c2 07 40 00  ld  [ %i5 ], %g1
a00ca510:  82 08 7f fe  and  %g1, -2, %g1
a00ca514:  c2 27 40 00  st  %g1, [ %i5 ]
a00ca518:  82 10 20 11  mov  0x11, %g1
a00ca51c:  ba 17 22 00  or  %i4, 0x200, %i5
a00ca520:  c2 27 40 00  st  %g1, [ %i5 ]
a00ca524:  82 10 20 08  mov  8, %g1
a00ca528:  c2 26 c0 00  st  %g1, [ %i3 ]
a00ca52c:  c2 06 c0 00  ld  [ %i3 ], %g1
a00ca530:  80 88 60 08  btst  8, %g1
a00ca534:  12 bf ff fe  bne  0xa00ca52c
a00ca538:  ba 17 22 08  or  %i4, 0x208, %i5
a00ca53c:  82 10 20 10  mov  0x10, %g1
a00ca540:  c2 27 40 00  st  %g1, [ %i5 ]
a00ca544:  82 10 20 3f  mov  0x3f, %g1
a00ca548:  b8 17 22 0c  or  %i4, 0x20c, %i4
a00ca54c:  3b 33 c0 63  sethi  %hi(0xcf018c00), %i5
a00ca550:  c2 27 00 00  st  %g1, [ %i4 ]
a00ca554:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ca558:  96 10 00 1d  mov  %i5, %o3
a00ca55c:  b0 17 62 04  or  %i5, 0x204, %i0
a00ca560:  b2 17 62 14  or  %i5, 0x214, %i1
a00ca564:  98 17 62 10  or  %i5, 0x210, %o4
a00ca568:  9e 10 62 50  or  %g1, 0x250, %o7
a00ca56c:  b4 10 20 01  mov  1, %i2
a00ca570:  9a 10 20 1b  mov  0x1b, %o5
a00ca574:  ba 10 20 3f  mov  0x3f, %i5
a00ca578:  c2 07 00 00  ld  [ %i4 ], %g1
a00ca57c:  80 a0 60 00  cmp  %g1, 0
a00ca580:  12 80 00 10  bne  0xa00ca5c0
a00ca584:  82 0e a0 ff  and  %i2, 0xff, %g1
a00ca588:  c2 0b c0 01  ldub  [ %o7 + %g1 ], %g1
a00ca58c:  c2 26 00 00  st  %g1, [ %i0 ]
a00ca590:  c2 06 40 00  ld  [ %i1 ], %g1
a00ca594:  82 10 60 04  or  %g1, 4, %g1
a00ca598:  c2 26 40 00  st  %g1, [ %i1 ]
a00ca59c:  b6 12 e2 14  or  %o3, 0x214, %i3
a00ca5a0:  c2 06 c0 00  ld  [ %i3 ], %g1
a00ca5a4:  80 88 60 04  btst  4, %g1
a00ca5a8:  12 bf ff fe  bne  0xa00ca5a0
a00ca5ac:  01 00 00 00  nop
a00ca5b0:  da 23 00 00  st  %o5, [ %o4 ]
a00ca5b4:  fa 27 00 00  st  %i5, [ %i4 ]
a00ca5b8:  10 80 00 08  b  0xa00ca5d8
a00ca5bc:  b4 06 a0 01  inc  %i2
a00ca5c0:  c2 0b c0 01  ldub  [ %o7 + %g1 ], %g1
a00ca5c4:  c2 26 00 00  st  %g1, [ %i0 ]
a00ca5c8:  c2 07 00 00  ld  [ %i4 ], %g1
a00ca5cc:  82 00 7f ff  add  %g1, -1, %g1
a00ca5d0:  c2 27 00 00  st  %g1, [ %i4 ]
a00ca5d4:  b4 06 a0 01  inc  %i2
a00ca5d8:  82 0e a0 ff  and  %i2, 0xff, %g1
a00ca5dc:  80 a0 60 8a  cmp  %g1, 0x8a
a00ca5e0:  08 bf ff e6  bleu  0xa00ca578
a00ca5e4:  01 00 00 00  nop
a00ca5e8:  37 33 c0 63  sethi  %hi(0xcf018c00), %i3
a00ca5ec:  b8 16 e2 04  or  %i3, 0x204, %i4	! 0xcf018e04
a00ca5f0:  82 10 20 80  mov  0x80, %g1
a00ca5f4:  c2 27 00 00  st  %g1, [ %i4 ]
a00ca5f8:  82 10 20 50  mov  0x50, %g1
a00ca5fc:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a00ca600:  82 10 20 04  mov  4, %g1
a00ca604:  c2 2f bf f1  stb  %g1, [ %fp + -15 ]
a00ca608:  c0 2f bf f2  clrb  [ %fp + -14 ]
a00ca60c:  c0 2f bf f3  clrb  [ %fp + -13 ]
a00ca610:  ba 16 e2 0c  or  %i3, 0x20c, %i5
a00ca614:  c0 27 40 00  clr  [ %i5 ]
a00ca618:  c2 0f bf f0  ldub  [ %fp + -16 ], %g1
a00ca61c:  c2 27 00 00  st  %g1, [ %i4 ]
a00ca620:  82 10 20 01  mov  1, %g1
a00ca624:  c2 27 40 00  st  %g1, [ %i5 ]
a00ca628:  c2 0f bf f1  ldub  [ %fp + -15 ], %g1
a00ca62c:  c2 27 00 00  st  %g1, [ %i4 ]
a00ca630:  82 10 20 02  mov  2, %g1
a00ca634:  c2 27 40 00  st  %g1, [ %i5 ]
a00ca638:  c2 0f bf f2  ldub  [ %fp + -14 ], %g1
a00ca63c:  c2 27 00 00  st  %g1, [ %i4 ]
a00ca640:  82 10 20 03  mov  3, %g1
a00ca644:  c2 27 40 00  st  %g1, [ %i5 ]
a00ca648:  c2 0f bf f3  ldub  [ %fp + -13 ], %g1
a00ca64c:  c2 27 00 00  st  %g1, [ %i4 ]
a00ca650:  82 16 e2 08  or  %i3, 0x208, %g1
a00ca654:  c0 20 40 00  clr  [ %g1 ]
a00ca658:  ba 16 e2 14  or  %i3, 0x214, %i5
a00ca65c:  c2 07 40 00  ld  [ %i5 ], %g1
a00ca660:  82 10 60 04  or  %g1, 4, %g1
a00ca664:  c2 27 40 00  st  %g1, [ %i5 ]
a00ca668:  c2 07 40 00  ld  [ %i5 ], %g1
a00ca66c:  80 88 60 04  btst  4, %g1
a00ca670:  12 bf ff fe  bne  0xa00ca668
a00ca674:  82 10 20 33  mov  0x33, %g1
a00ca678:  ba 16 e2 00  or  %i3, 0x200, %i5
a00ca67c:  c2 27 40 00  st  %g1, [ %i5 ]
a00ca680:  ba 16 e2 10  or  %i3, 0x210, %i5
a00ca684:  c2 07 40 00  ld  [ %i5 ], %g1
a00ca688:  82 10 60 10  or  %g1, 0x10, %g1
a00ca68c:  c2 27 40 00  st  %g1, [ %i5 ]
a00ca690:  c2 07 40 00  ld  [ %i5 ], %g1
a00ca694:  80 88 60 10  btst  0x10, %g1
a00ca698:  12 bf ff fe  bne  0xa00ca690
a00ca69c:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00ca6a0:  b2 10 60 88  or  %g1, 0x88, %i1	! 0xa807d088
a00ca6a4:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00ca6a8:  b4 10 62 04  or  %g1, 0x204, %i2	! 0xcf018e04
a00ca6ac:  b6 10 20 00  clr  %i3
a00ca6b0:  82 0e e0 ff  and  %i3, 0xff, %g1
a00ca6b4:  b6 06 e0 01  inc  %i3
a00ca6b8:  fa 06 80 00  ld  [ %i2 ], %i5
a00ca6bc:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00ca6c0:  80 a7 20 1f  cmp  %i4, 0x1f
a00ca6c4:  08 bf ff fb  bleu  0xa00ca6b0
a00ca6c8:  fa 2e 40 01  stb  %i5, [ %i1 + %g1 ]
a00ca6cc:  81 c7 e0 08  ret
a00ca6d0:  81 e8 00 00  restore
