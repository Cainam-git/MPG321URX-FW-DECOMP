# leon2m FUN_a00fc334 0xa00fc334-0xa00fca34 (1792 bytes)
a00fc334:  9d e3 bf 88  save  %sp, -120, %sp
a00fc338:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fc33c:  98 12 e0 34  or  %o3, 0x34, %o4	! 0xcf012034
a00fc340:  c2 03 00 00  ld  [ %o4 ], %g1
a00fc344:  80 88 60 38  btst  0x38, %g1
a00fc348:  02 80 00 0a  be  0xa00fc370
a00fc34c:  b0 10 20 00  clr  %i0
a00fc350:  90 10 20 38  mov  0x38, %o0
a00fc354:  d0 23 00 00  st  %o0, [ %o4 ]
a00fc358:  82 10 20 05  mov  5, %g1
a00fc35c:  80 a0 60 01  cmp  %g1, 1
a00fc360:  12 80 01 b3  bne  0xa00fca2c
a00fc364:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a00fc368:  10 80 00 63  b  0xa00fc4f4
a00fc36c:  c2 0b 61 7c  ldub  [ %o5 + 0x17c ], %g1	! 0xa802c97c
a00fc370:  d2 03 00 00  ld  [ %o4 ], %o1
a00fc374:  80 8a 60 01  btst  1, %o1
a00fc378:  02 bf ff f9  be  0xa00fc35c
a00fc37c:  82 10 20 06  mov  6, %g1
a00fc380:  94 12 e0 3c  or  %o3, 0x3c, %o2
a00fc384:  da 02 80 00  ld  [ %o2 ], %o5
a00fc388:  80 a3 60 00  cmp  %o5, 0
a00fc38c:  22 80 00 65  be,a   0xa00fc520
a00fc390:  96 10 20 01  mov  1, %o3
a00fc394:  a0 12 e0 c4  or  %o3, 0xc4, %l0
a00fc398:  de 04 00 00  ld  [ %l0 ], %o7
a00fc39c:  a0 10 00 0f  mov  %o7, %l0
a00fc3a0:  19 00 00 12  sethi  %hi(0x4800), %o4
a00fc3a4:  9e 13 20 32  or  %o4, 0x32, %o7	! 0x4832
a00fc3a8:  94 10 20 00  clr  %o2
a00fc3ac:  96 10 20 00  clr  %o3
a00fc3b0:  90 07 bf f8  add  %fp, -8, %o0
a00fc3b4:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a00fc3b8:  a2 02 c0 0f  add  %o3, %o7, %l1
a00fc3bc:  99 2c 60 02  sll  %l1, 2, %o4
a00fc3c0:  a2 02 00 0b  add  %o0, %o3, %l1
a00fc3c4:  82 13 00 09  or  %o4, %o1, %g1
a00fc3c8:  94 02 a0 01  inc  %o2
a00fc3cc:  da 00 40 00  ld  [ %g1 ], %o5
a00fc3d0:  96 0a a0 ff  and  %o2, 0xff, %o3
a00fc3d4:  80 a2 e0 0f  cmp  %o3, 0xf
a00fc3d8:  08 bf ff f8  bleu  0xa00fc3b8
a00fc3dc:  da 2c 7f f0  stb  %o5, [ %l1 + -16 ]
a00fc3e0:  94 0c 20 ff  and  %l0, 0xff, %o2
a00fc3e4:  92 0a a0 0f  and  %o2, 0xf, %o1
a00fc3e8:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a00fc3ec:  91 32 a0 04  srl  %o2, 4, %o0
a00fc3f0:  80 a2 60 0f  cmp  %o1, 0xf
a00fc3f4:  02 80 00 67  be  0xa00fc590
a00fc3f8:  d0 2a e1 7d  stb  %o0, [ %o3 + 0x17d ]
a00fc3fc:  d2 0f bf e8  ldub  [ %fp + -24 ], %o1
a00fc400:  82 0a 60 ff  and  %o1, 0xff, %g1
a00fc404:  80 a0 60 83  cmp  %g1, 0x83
a00fc408:  22 80 00 71  be,a   0xa00fc5cc
a00fc40c:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fc410:  14 80 00 51  bg  0xa00fc554
a00fc414:  80 a0 60 93  cmp  %g1, 0x93
a00fc418:  80 a0 60 36  cmp  %g1, 0x36
a00fc41c:  22 80 00 68  be,a   0xa00fc5bc
a00fc420:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a00fc424:  14 80 00 e7  bg  0xa00fc7c0
a00fc428:  80 a0 60 44  cmp  %g1, 0x44
a00fc42c:  80 a0 60 0f  cmp  %g1, 0xf
a00fc430:  32 80 00 53  bne,a   0xa00fc57c
a00fc434:  11 33 c0 48  sethi  %hi(0xcf012000), %o0
a00fc438:  19 33 c0 48  sethi  %hi(0xcf012000), %o4
a00fc43c:  a0 13 20 84  or  %o4, 0x84, %l0	! 0xcf012084
a00fc440:  c0 24 00 00  clr  [ %l0 ]
a00fc444:  96 13 20 88  or  %o4, 0x88, %o3
a00fc448:  94 10 20 02  mov  2, %o2
a00fc44c:  d4 22 c0 00  st  %o2, [ %o3 ]
a00fc450:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a00fc454:  d6 00 61 70  ld  [ %g1 + 0x170 ], %o3	! 0xa802c970
a00fc458:  9e 13 20 34  or  %o4, 0x34, %o7
a00fc45c:  9a 10 20 2e  mov  0x2e, %o5
a00fc460:  da 23 c0 00  st  %o5, [ %o7 ]
a00fc464:  80 a2 e0 00  cmp  %o3, 0
a00fc468:  12 80 01 65  bne  0xa00fc9fc
a00fc46c:  92 0a 20 ff  and  %o0, 0xff, %o1
a00fc470:  a2 13 20 80  or  %o4, 0x80, %l1
a00fc474:  d2 24 40 00  st  %o1, [ %l1 ]
a00fc478:  90 13 20 40  or  %o4, 0x40, %o0
a00fc47c:  d4 22 00 00  st  %o2, [ %o0 ]
a00fc480:  67 fe 44 42  call  0x4008d588
a00fc484:  01 00 00 00  nop
a00fc488:  15 33 c0 48  sethi  %hi(0xcf012000), %o2
a00fc48c:  82 12 a0 34  or  %o2, 0x34, %g1	! 0xcf012034
a00fc490:  d8 00 40 00  ld  [ %g1 ], %o4
a00fc494:  80 8b 20 2e  btst  0x2e, %o4
a00fc498:  12 80 00 11  bne  0xa00fc4dc
a00fc49c:  a2 10 00 01  mov  %g1, %l1
a00fc4a0:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00fc4a4:  67 fe 42 8d  call  0x4008ced8
a00fc4a8:  01 00 00 00  nop
a00fc4ac:  67 fe 44 3a  call  0x4008d594
a00fc4b0:  91 34 20 10  srl  %l0, 0x10, %o0
a00fc4b4:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00fc4b8:  9f 33 60 10  srl  %o5, 0x10, %o7
a00fc4bc:  80 a3 e3 e8  cmp  %o7, 0x3e8
a00fc4c0:  18 80 00 07  bgu  0xa00fc4dc
a00fc4c4:  15 33 c0 48  sethi  %hi(0xcf012000), %o2
a00fc4c8:  c2 04 40 00  ld  [ %l1 ], %g1
a00fc4cc:  80 88 60 2e  btst  0x2e, %g1
a00fc4d0:  02 bf ff f5  be  0xa00fc4a4
a00fc4d4:  01 00 00 00  nop
a00fc4d8:  15 33 c0 48  sethi  %hi(0xcf012000), %o2
a00fc4dc:  9e 12 a0 34  or  %o2, 0x34, %o7	! 0xcf012034
a00fc4e0:  d8 03 c0 00  ld  [ %o7 ], %o4
a00fc4e4:  96 10 20 2e  mov  0x2e, %o3
a00fc4e8:  d6 23 c0 00  st  %o3, [ %o7 ]
a00fc4ec:  10 80 00 24  b  0xa00fc57c
a00fc4f0:  11 33 c0 48  sethi  %hi(0xcf012000), %o0
a00fc4f4:  80 88 60 01  btst  1, %g1
a00fc4f8:  32 80 00 08  bne,a   0xa00fc518
a00fc4fc:  b0 10 20 01  mov  1, %i0
a00fc500:  80 88 60 02  btst  2, %g1
a00fc504:  02 80 00 0a  be  0xa00fc52c
a00fc508:  80 88 60 04  btst  4, %g1
a00fc50c:  b0 10 20 02  mov  2, %i0
a00fc510:  10 80 01 47  b  0xa00fca2c
a00fc514:  c0 2b 61 7c  clrb  [ %o5 + 0x17c ]
a00fc518:  10 80 01 45  b  0xa00fca2c
a00fc51c:  c0 2b 61 7c  clrb  [ %o5 + 0x17c ]
a00fc520:  d6 23 00 00  st  %o3, [ %o4 ]
a00fc524:  10 bf ff 8e  b  0xa00fc35c
a00fc528:  82 10 20 06  mov  6, %g1
a00fc52c:  32 80 00 08  bne,a   0xa00fc54c
a00fc530:  b0 10 20 03  mov  3, %i0
a00fc534:  80 88 60 08  btst  8, %g1
a00fc538:  02 80 00 52  be  0xa00fc680
a00fc53c:  80 88 60 10  btst  0x10, %g1
a00fc540:  b0 10 20 04  mov  4, %i0
a00fc544:  10 80 01 3a  b  0xa00fca2c
a00fc548:  c0 2b 61 7c  clrb  [ %o5 + 0x17c ]
a00fc54c:  10 80 01 38  b  0xa00fca2c
a00fc550:  c0 2b 61 7c  clrb  [ %o5 + 0x17c ]
a00fc554:  02 80 00 70  be  0xa00fc714
a00fc558:  80 a0 60 93  cmp  %g1, 0x93
a00fc55c:  14 80 00 6a  bg  0xa00fc704
a00fc560:  80 a0 60 9d  cmp  %g1, 0x9d
a00fc564:  80 a0 60 8f  cmp  %g1, 0x8f
a00fc568:  02 80 00 c3  be  0xa00fc874
a00fc56c:  80 a0 60 91  cmp  %g1, 0x91
a00fc570:  22 80 00 f3  be,a   0xa00fc93c
a00fc574:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fc578:  11 33 c0 48  sethi  %hi(0xcf012000), %o0
a00fc57c:  9a 10 20 01  mov  1, %o5
a00fc580:  a2 12 20 34  or  %o0, 0x34, %l1
a00fc584:  da 24 40 00  st  %o5, [ %l1 ]
a00fc588:  10 bf ff 75  b  0xa00fc35c
a00fc58c:  82 10 20 01  mov  1, %g1
a00fc590:  d2 0f bf e8  ldub  [ %fp + -24 ], %o1
a00fc594:  82 0a 60 ff  and  %o1, 0xff, %g1
a00fc598:  80 a0 60 82  cmp  %g1, 0x82
a00fc59c:  02 80 00 3f  be  0xa00fc698
a00fc5a0:  d0 0f bf e9  ldub  [ %fp + -23 ], %o0
a00fc5a4:  14 80 00 46  bg  0xa00fc6bc
a00fc5a8:  80 a0 60 84  cmp  %g1, 0x84
a00fc5ac:  80 a0 60 36  cmp  %g1, 0x36
a00fc5b0:  12 bf ff f3  bne  0xa00fc57c
a00fc5b4:  11 33 c0 48  sethi  %hi(0xcf012000), %o0
a00fc5b8:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a00fc5bc:  e0 0b 61 7c  ldub  [ %o5 + 0x17c ], %l0	! 0xa802c97c
a00fc5c0:  82 14 20 02  or  %l0, 2, %g1
a00fc5c4:  10 bf ff ed  b  0xa00fc578
a00fc5c8:  c2 2b 61 7c  stb  %g1, [ %o5 + 0x17c ]
a00fc5cc:  9e 12 e0 84  or  %o3, 0x84, %o7
a00fc5d0:  a0 10 20 84  mov  0x84, %l0
a00fc5d4:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fc5d8:  90 12 e0 88  or  %o3, 0x88, %o0
a00fc5dc:  c0 22 00 00  clr  [ %o0 ]
a00fc5e0:  94 12 e0 8c  or  %o3, 0x8c, %o2
a00fc5e4:  c0 22 80 00  clr  [ %o2 ]
a00fc5e8:  98 12 e0 90  or  %o3, 0x90, %o4
a00fc5ec:  c0 23 00 00  clr  [ %o4 ]
a00fc5f0:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a00fc5f4:  d8 02 61 70  ld  [ %o1 + 0x170 ], %o4	! 0xa802c970
a00fc5f8:  a2 12 e0 34  or  %o3, 0x34, %l1
a00fc5fc:  82 10 20 2e  mov  0x2e, %g1
a00fc600:  c2 24 40 00  st  %g1, [ %l1 ]
a00fc604:  80 a3 20 00  cmp  %o4, 0
a00fc608:  12 80 00 87  bne  0xa00fc824
a00fc60c:  a2 12 e0 80  or  %o3, 0x80, %l1
a00fc610:  9a 12 e0 40  or  %o3, 0x40, %o5
a00fc614:  82 10 20 0f  mov  0xf, %g1
a00fc618:  c2 24 40 00  st  %g1, [ %l1 ]
a00fc61c:  96 10 20 04  mov  4, %o3
a00fc620:  d6 23 40 00  st  %o3, [ %o5 ]
a00fc624:  67 fe 43 d9  call  0x4008d588
a00fc628:  01 00 00 00  nop
a00fc62c:  19 33 c0 48  sethi  %hi(0xcf012000), %o4
a00fc630:  82 13 20 34  or  %o4, 0x34, %g1	! 0xcf012034
a00fc634:  d2 00 40 00  ld  [ %g1 ], %o1
a00fc638:  80 8a 60 2e  btst  0x2e, %o1
a00fc63c:  12 bf ff a7  bne  0xa00fc4d8
a00fc640:  a2 10 00 01  mov  %g1, %l1
a00fc644:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00fc648:  67 fe 42 24  call  0x4008ced8
a00fc64c:  01 00 00 00  nop
a00fc650:  67 fe 43 d1  call  0x4008d594
a00fc654:  91 34 20 10  srl  %l0, 0x10, %o0
a00fc658:  91 2a 20 10  sll  %o0, 0x10, %o0
a00fc65c:  95 32 20 10  srl  %o0, 0x10, %o2
a00fc660:  80 a2 a3 e8  cmp  %o2, 0x3e8
a00fc664:  18 bf ff 9e  bgu  0xa00fc4dc
a00fc668:  15 33 c0 48  sethi  %hi(0xcf012000), %o2
a00fc66c:  de 04 40 00  ld  [ %l1 ], %o7
a00fc670:  80 8b e0 2e  btst  0x2e, %o7
a00fc674:  02 bf ff f5  be  0xa00fc648
a00fc678:  9e 12 a0 34  or  %o2, 0x34, %o7
a00fc67c:  30 bf ff 99  b,a   0xa00fc4e0
a00fc680:  02 80 00 64  be  0xa00fc810
a00fc684:  80 88 60 20  btst  0x20, %g1
a00fc688:  b0 10 20 05  mov  5, %i0
a00fc68c:  10 80 00 e8  b  0xa00fca2c
a00fc690:  c0 2b 61 7c  clrb  [ %o5 + 0x17c ]
a00fc694:  d0 0f bf e9  ldub  [ %fp + -23 ], %o0
a00fc698:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a00fc69c:  80 a2 20 00  cmp  %o0, 0
a00fc6a0:  02 bf ff b6  be  0xa00fc578
a00fc6a4:  d0 2a e1 7e  stb  %o0, [ %o3 + 0x17e ]
a00fc6a8:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a00fc6ac:  de 0b 61 7c  ldub  [ %o5 + 0x17c ], %o7	! 0xa802c97c
a00fc6b0:  82 13 e0 04  or  %o7, 4, %g1
a00fc6b4:  10 bf ff b1  b  0xa00fc578
a00fc6b8:  c2 2b 61 7c  stb  %g1, [ %o5 + 0x17c ]
a00fc6bc:  02 bf ff f6  be  0xa00fc694
a00fc6c0:  80 a0 60 87  cmp  %g1, 0x87
a00fc6c4:  12 bf ff ae  bne  0xa00fc57c
a00fc6c8:  11 33 c0 48  sethi  %hi(0xcf012000), %o0
a00fc6cc:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a00fc6d0:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a00fc6d4:  d0 0b 21 7c  ldub  [ %o4 + 0x17c ], %o0
a00fc6d8:  d2 2a a1 78  stb  %o1, [ %o2 + 0x178 ]
a00fc6dc:  a0 12 a1 78  or  %o2, 0x178, %l0
a00fc6e0:  a2 12 20 20  or  %o0, 0x20, %l1
a00fc6e4:  d2 0f bf eb  ldub  [ %fp + -21 ], %o1
a00fc6e8:  c2 0f bf e9  ldub  [ %fp + -23 ], %g1
a00fc6ec:  da 0f bf ea  ldub  [ %fp + -22 ], %o5
a00fc6f0:  d2 2c 20 03  stb  %o1, [ %l0 + 3 ]
a00fc6f4:  e2 2b 21 7c  stb  %l1, [ %o4 + 0x17c ]
a00fc6f8:  c2 2c 20 01  stb  %g1, [ %l0 + 1 ]
a00fc6fc:  10 bf ff 9f  b  0xa00fc578
a00fc700:  da 2c 20 02  stb  %o5, [ %l0 + 2 ]
a00fc704:  02 80 00 86  be  0xa00fc91c
a00fc708:  80 a0 60 ff  cmp  %g1, 0xff
a00fc70c:  32 bf ff 9c  bne,a   0xa00fc57c
a00fc710:  11 33 c0 48  sethi  %hi(0xcf012000), %o0
a00fc714:  15 33 c0 48  sethi  %hi(0xcf012000), %o2
a00fc718:  9e 12 a0 84  or  %o2, 0x84, %o7	! 0xcf012084
a00fc71c:  c0 23 c0 00  clr  [ %o7 ]
a00fc720:  98 12 a0 88  or  %o2, 0x88, %o4
a00fc724:  c0 23 00 00  clr  [ %o4 ]
a00fc728:  92 12 a0 8c  or  %o2, 0x8c, %o1
a00fc72c:  c0 22 40 00  clr  [ %o1 ]
a00fc730:  90 10 20 2e  mov  0x2e, %o0
a00fc734:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a00fc738:  a0 12 a0 34  or  %o2, 0x34, %l0
a00fc73c:  da 04 61 70  ld  [ %l1 + 0x170 ], %o5
a00fc740:  d0 24 00 00  st  %o0, [ %l0 ]
a00fc744:  80 a3 60 00  cmp  %o5, 0
a00fc748:  12 80 00 3f  bne  0xa00fc844
a00fc74c:  d0 0a e1 7d  ldub  [ %o3 + 0x17d ], %o0
a00fc750:  82 12 a0 80  or  %o2, 0x80, %g1
a00fc754:  96 12 a0 40  or  %o2, 0x40, %o3
a00fc758:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00fc75c:  da 20 40 00  st  %o5, [ %g1 ]
a00fc760:  94 10 20 03  mov  3, %o2
a00fc764:  d4 22 c0 00  st  %o2, [ %o3 ]
a00fc768:  67 fe 43 88  call  0x4008d588
a00fc76c:  23 33 c0 48  sethi  %hi(0xcf012000), %l1
a00fc770:  82 14 60 34  or  %l1, 0x34, %g1	! 0xcf012034
a00fc774:  e0 00 40 00  ld  [ %g1 ], %l0
a00fc778:  80 8c 20 2e  btst  0x2e, %l0
a00fc77c:  12 bf ff 57  bne  0xa00fc4d8
a00fc780:  a2 10 00 01  mov  %g1, %l1
a00fc784:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00fc788:  67 fe 41 d4  call  0x4008ced8
a00fc78c:  01 00 00 00  nop
a00fc790:  67 fe 43 81  call  0x4008d594
a00fc794:  91 34 20 10  srl  %l0, 0x10, %o0
a00fc798:  93 2a 20 10  sll  %o0, 0x10, %o1
a00fc79c:  91 32 60 10  srl  %o1, 0x10, %o0
a00fc7a0:  80 a2 23 e8  cmp  %o0, 0x3e8
a00fc7a4:  18 bf ff 4e  bgu  0xa00fc4dc
a00fc7a8:  15 33 c0 48  sethi  %hi(0xcf012000), %o2
a00fc7ac:  d8 04 40 00  ld  [ %l1 ], %o4
a00fc7b0:  80 8b 20 2e  btst  0x2e, %o4
a00fc7b4:  02 bf ff f5  be  0xa00fc788
a00fc7b8:  9e 12 a0 34  or  %o2, 0x34, %o7
a00fc7bc:  30 bf ff 49  b,a   0xa00fc4e0
a00fc7c0:  02 80 00 25  be  0xa00fc854
a00fc7c4:  80 a0 60 47  cmp  %g1, 0x47
a00fc7c8:  12 bf ff 6d  bne  0xa00fc57c
a00fc7cc:  11 33 c0 48  sethi  %hi(0xcf012000), %o0
a00fc7d0:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a00fc7d4:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a00fc7d8:  e0 0b e1 7c  ldub  [ %o7 + 0x17c ], %l0
a00fc7dc:  d2 28 61 68  stb  %o1, [ %g1 + 0x168 ]
a00fc7e0:  a2 10 61 68  or  %g1, 0x168, %l1
a00fc7e4:  94 14 20 40  or  %l0, 0x40, %o2
a00fc7e8:  d6 0f bf ec  ldub  [ %fp + -20 ], %o3
a00fc7ec:  d8 0f bf e9  ldub  [ %fp + -23 ], %o4
a00fc7f0:  d2 0f bf ea  ldub  [ %fp + -22 ], %o1
a00fc7f4:  d0 0f bf eb  ldub  [ %fp + -21 ], %o0
a00fc7f8:  d6 2c 60 04  stb  %o3, [ %l1 + 4 ]
a00fc7fc:  d4 2b e1 7c  stb  %o2, [ %o7 + 0x17c ]
a00fc800:  d8 2c 60 01  stb  %o4, [ %l1 + 1 ]
a00fc804:  d2 2c 60 02  stb  %o1, [ %l1 + 2 ]
a00fc808:  10 bf ff 5c  b  0xa00fc578
a00fc80c:  d0 2c 60 03  stb  %o0, [ %l1 + 3 ]
a00fc810:  02 80 00 09  be  0xa00fc834
a00fc814:  80 88 60 40  btst  0x40, %g1
a00fc818:  b0 10 20 06  mov  6, %i0
a00fc81c:  10 80 00 84  b  0xa00fca2c
a00fc820:  c0 2b 61 7c  clrb  [ %o5 + 0x17c ]
a00fc824:  90 10 20 0f  mov  0xf, %o0
a00fc828:  9f c3 00 00  call  %o4
a00fc82c:  92 10 20 04  mov  4, %o1
a00fc830:  30 bf ff 7d  b,a   0xa00fc624
a00fc834:  02 80 00 7e  be  0xa00fca2c
a00fc838:  c0 2b 61 7c  clrb  [ %o5 + 0x17c ]
a00fc83c:  10 80 00 7c  b  0xa00fca2c
a00fc840:  b0 10 20 07  mov  7, %i0
a00fc844:  90 0a 20 ff  and  %o0, 0xff, %o0
a00fc848:  9f c3 40 00  call  %o5
a00fc84c:  92 10 20 03  mov  3, %o1
a00fc850:  30 bf ff c6  b,a   0xa00fc768
a00fc854:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a00fc858:  da 0a e1 7c  ldub  [ %o3 + 0x17c ], %o5	! 0xa802c97c
a00fc85c:  9a 13 60 10  or  %o5, 0x10, %o5
a00fc860:  e0 0f bf e9  ldub  [ %fp + -23 ], %l0
a00fc864:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a00fc868:  e0 28 61 7f  stb  %l0, [ %g1 + 0x17f ]	! 0xa802c97f
a00fc86c:  10 bf ff 43  b  0xa00fc578
a00fc870:  da 2a e1 7c  stb  %o5, [ %o3 + 0x17c ]
a00fc874:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fc878:  94 12 e0 84  or  %o3, 0x84, %o2	! 0xcf012084
a00fc87c:  9e 10 20 90  mov  0x90, %o7
a00fc880:  de 22 80 00  st  %o7, [ %o2 ]
a00fc884:  98 12 e0 88  or  %o3, 0x88, %o4
a00fc888:  c0 23 00 00  clr  [ %o4 ]
a00fc88c:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a00fc890:  d8 02 61 70  ld  [ %o1 + 0x170 ], %o4	! 0xa802c970
a00fc894:  a0 12 e0 34  or  %o3, 0x34, %l0
a00fc898:  a2 10 20 2e  mov  0x2e, %l1
a00fc89c:  e2 24 00 00  st  %l1, [ %l0 ]
a00fc8a0:  80 a3 20 00  cmp  %o4, 0
a00fc8a4:  12 80 00 5a  bne  0xa00fca0c
a00fc8a8:  82 12 e0 80  or  %o3, 0x80, %g1
a00fc8ac:  9a 12 e0 40  or  %o3, 0x40, %o5
a00fc8b0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00fc8b4:  d0 20 40 00  st  %o0, [ %g1 ]
a00fc8b8:  96 10 20 02  mov  2, %o3
a00fc8bc:  d6 23 40 00  st  %o3, [ %o5 ]
a00fc8c0:  67 fe 43 32  call  0x4008d588
a00fc8c4:  23 33 c0 48  sethi  %hi(0xcf012000), %l1
a00fc8c8:  82 14 60 34  or  %l1, 0x34, %g1	! 0xcf012034
a00fc8cc:  e0 00 40 00  ld  [ %g1 ], %l0
a00fc8d0:  80 8c 20 2e  btst  0x2e, %l0
a00fc8d4:  12 bf ff 01  bne  0xa00fc4d8
a00fc8d8:  a2 10 00 01  mov  %g1, %l1
a00fc8dc:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00fc8e0:  67 fe 41 7e  call  0x4008ced8
a00fc8e4:  01 00 00 00  nop
a00fc8e8:  67 fe 43 2b  call  0x4008d594
a00fc8ec:  91 34 20 10  srl  %l0, 0x10, %o0
a00fc8f0:  99 2a 20 10  sll  %o0, 0x10, %o4
a00fc8f4:  93 33 20 10  srl  %o4, 0x10, %o1
a00fc8f8:  80 a2 63 e8  cmp  %o1, 0x3e8
a00fc8fc:  18 bf fe f8  bgu  0xa00fc4dc
a00fc900:  15 33 c0 48  sethi  %hi(0xcf012000), %o2
a00fc904:  d4 04 40 00  ld  [ %l1 ], %o2
a00fc908:  80 8a a0 2e  btst  0x2e, %o2
a00fc90c:  02 bf ff f5  be  0xa00fc8e0
a00fc910:  15 33 c0 48  sethi  %hi(0xcf012000), %o2
a00fc914:  10 bf fe f3  b  0xa00fc4e0
a00fc918:  9e 12 a0 34  or  %o2, 0x34, %o7	! 0xcf012034
a00fc91c:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a00fc920:  da 0a e1 7c  ldub  [ %o3 + 0x17c ], %o5	! 0xa802c97c
a00fc924:  9a 13 60 08  or  %o5, 8, %o5
a00fc928:  e0 0f bf e9  ldub  [ %fp + -23 ], %l0
a00fc92c:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a00fc930:  e0 2b e1 7e  stb  %l0, [ %o7 + 0x17e ]	! 0xa802c97e
a00fc934:  10 bf ff 11  b  0xa00fc578
a00fc938:  da 2a e1 7c  stb  %o5, [ %o3 + 0x17c ]
a00fc93c:  9a 12 e0 84  or  %o3, 0x84, %o5
a00fc940:  82 10 20 32  mov  0x32, %g1
a00fc944:  c2 23 40 00  st  %g1, [ %o5 ]
a00fc948:  a2 10 20 65  mov  0x65, %l1
a00fc94c:  a0 12 e0 88  or  %o3, 0x88, %l0
a00fc950:  e2 24 00 00  st  %l1, [ %l0 ]
a00fc954:  94 12 e0 8c  or  %o3, 0x8c, %o2
a00fc958:  9e 10 20 6e  mov  0x6e, %o7
a00fc95c:  de 22 80 00  st  %o7, [ %o2 ]
a00fc960:  92 12 e0 90  or  %o3, 0x90, %o1
a00fc964:  98 10 20 67  mov  0x67, %o4
a00fc968:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a00fc96c:  d8 22 40 00  st  %o4, [ %o1 ]
a00fc970:  da 03 61 70  ld  [ %o5 + 0x170 ], %o5
a00fc974:  a2 12 e0 34  or  %o3, 0x34, %l1
a00fc978:  82 10 20 2e  mov  0x2e, %g1
a00fc97c:  c2 24 40 00  st  %g1, [ %l1 ]
a00fc980:  80 a3 60 00  cmp  %o5, 0
a00fc984:  12 80 00 26  bne  0xa00fca1c
a00fc988:  98 0a 20 ff  and  %o0, 0xff, %o4
a00fc98c:  92 12 e0 80  or  %o3, 0x80, %o1
a00fc990:  90 12 e0 40  or  %o3, 0x40, %o0
a00fc994:  d8 22 40 00  st  %o4, [ %o1 ]
a00fc998:  96 10 20 04  mov  4, %o3
a00fc99c:  d6 22 00 00  st  %o3, [ %o0 ]
a00fc9a0:  67 fe 42 fa  call  0x4008d588
a00fc9a4:  01 00 00 00  nop
a00fc9a8:  1f 33 c0 48  sethi  %hi(0xcf012000), %o7
a00fc9ac:  82 13 e0 34  or  %o7, 0x34, %g1	! 0xcf012034
a00fc9b0:  d4 00 40 00  ld  [ %g1 ], %o2
a00fc9b4:  80 8a a0 2e  btst  0x2e, %o2
a00fc9b8:  12 bf fe c8  bne  0xa00fc4d8
a00fc9bc:  a2 10 00 01  mov  %g1, %l1
a00fc9c0:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00fc9c4:  67 fe 41 45  call  0x4008ced8
a00fc9c8:  01 00 00 00  nop
a00fc9cc:  67 fe 42 f2  call  0x4008d594
a00fc9d0:  91 34 20 10  srl  %l0, 0x10, %o0
a00fc9d4:  83 2a 20 10  sll  %o0, 0x10, %g1
a00fc9d8:  9b 30 60 10  srl  %g1, 0x10, %o5
a00fc9dc:  80 a3 63 e8  cmp  %o5, 0x3e8
a00fc9e0:  18 bf fe bf  bgu  0xa00fc4dc
a00fc9e4:  15 33 c0 48  sethi  %hi(0xcf012000), %o2
a00fc9e8:  d0 04 40 00  ld  [ %l1 ], %o0
a00fc9ec:  80 8a 20 2e  btst  0x2e, %o0
a00fc9f0:  02 bf ff f5  be  0xa00fc9c4
a00fc9f4:  9e 12 a0 34  or  %o2, 0x34, %o7
a00fc9f8:  30 bf fe ba  b,a   0xa00fc4e0
a00fc9fc:  90 0a 20 0f  and  %o0, 0xf, %o0
a00fca00:  9f c2 c0 00  call  %o3
a00fca04:  92 10 20 02  mov  2, %o1
a00fca08:  30 bf fe 9e  b,a   0xa00fc480
a00fca0c:  90 0a 20 0f  and  %o0, 0xf, %o0
a00fca10:  9f c3 00 00  call  %o4
a00fca14:  92 10 20 02  mov  2, %o1
a00fca18:  30 bf ff aa  b,a   0xa00fc8c0
a00fca1c:  90 0a 20 0f  and  %o0, 0xf, %o0
a00fca20:  9f c3 40 00  call  %o5
a00fca24:  92 10 20 04  mov  4, %o1
a00fca28:  30 bf ff de  b,a   0xa00fc9a0
a00fca2c:  81 c7 e0 08  ret
a00fca30:  81 e8 00 00  restore
