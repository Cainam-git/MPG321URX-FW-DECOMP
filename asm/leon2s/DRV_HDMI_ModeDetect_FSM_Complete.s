# leon2s DRV_HDMI_ModeDetect_FSM_Complete 0xa009e368-0xa009e9a4 (1596 bytes)
a009e368:  9d e3 bf 90  save  %sp, -112, %sp
a009e36c:  2f 2a 01 e1  sethi  %hi(0xa8078400), %l7
a009e370:  c2 05 e2 34  ld  [ %l7 + 0x234 ], %g1	! 0xa8078634
a009e374:  80 88 60 04  btst  4, %g1
a009e378:  c0 27 bf f4  clr  [ %fp + -12 ]
a009e37c:  c0 27 bf f0  clr  [ %fp + -16 ]
a009e380:  ac 10 00 18  mov  %i0, %l6
a009e384:  02 80 00 08  be  0xa009e3a4
a009e388:  a0 10 20 00  clr  %l0
a009e38c:  92 06 20 41  add  %i0, 0x41, %o1
a009e390:  93 2a 60 18  sll  %o1, 0x18, %o1
a009e394:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009e398:  90 12 20 98  or  %o0, 0x98, %o0	! 0xa006ac98
a009e39c:  7f ff 53 2a  call  0xa0073044
a009e3a0:  93 3a 60 18  sra  %o1, 0x18, %o1
a009e3a4:  a6 0d a0 ff  and  %l6, 0xff, %l3
a009e3a8:  40 00 08 08  call  0xa00a03c8
a009e3ac:  90 10 00 13  mov  %l3, %o0
a009e3b0:  80 8a 20 ff  btst  0xff, %o0
a009e3b4:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009e3b8:  02 80 00 0f  be  0xa009e3f4
a009e3bc:  96 5c e1 90  smul  %l3, 0x190, %o3
a009e3c0:  9a 10 63 e0  or  %g1, 0x3e0, %o5
a009e3c4:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009e3c8:  98 5c e0 34  smul  %l3, 0x34, %o4
a009e3cc:  82 10 63 00  or  %g1, 0x300, %g1
a009e3d0:  d2 00 40 0c  ld  [ %g1 + %o4 ], %o1
a009e3d4:  9a 02 c0 0d  add  %o3, %o5, %o5
a009e3d8:  82 10 20 01  mov  1, %g1
a009e3dc:  c2 2b 60 2d  stb  %g1, [ %o5 + 0x2d ]
a009e3e0:  92 02 60 b4  add  %o1, 0xb4, %o1
a009e3e4:  40 00 23 fc  call  0xa00a73d4
a009e3e8:  90 10 20 02  mov  2, %o0
a009e3ec:  10 80 00 05  b  0xa009e400
a009e3f0:  a0 10 20 01  mov  1, %l0
a009e3f4:  82 10 63 e0  or  %g1, 0x3e0, %g1
a009e3f8:  82 02 c0 01  add  %o3, %g1, %g1
a009e3fc:  c0 28 60 2d  clrb  [ %g1 + 0x2d ]
a009e400:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009e404:  aa 10 63 f8  or  %g1, 0x3f8, %l5	! 0xa807d7f8
a009e408:  a8 5c e1 90  smul  %l3, 0x190, %l4
a009e40c:  94 10 00 10  mov  %l0, %o2
a009e410:  90 10 00 13  mov  %l3, %o0
a009e414:  7f ff fe fe  call  0xa009e00c
a009e418:  92 05 00 15  add  %l4, %l5, %o1
a009e41c:  80 8a 20 ff  btst  0xff, %o0
a009e420:  19 2a 01 f5  sethi  %hi(0xa807d400), %o4
a009e424:  12 80 00 09  bne  0xa009e448
a009e428:  a0 04 c0 13  add  %l3, %l3, %l0
a009e42c:  82 04 00 13  add  %l0, %l3, %g1
a009e430:  98 13 22 50  or  %o4, 0x250, %o4
a009e434:  83 28 60 03  sll  %g1, 3, %g1
a009e438:  9a 10 20 05  mov  5, %o5
a009e43c:  da 23 00 01  st  %o5, [ %o4 + %g1 ]
a009e440:  10 80 01 57  b  0xa009e99c
a009e444:  b0 10 20 00  clr  %i0
a009e448:  82 05 7f e8  add  %l5, -24, %g1
a009e44c:  b0 05 00 01  add  %l4, %g1, %i0
a009e450:  c2 0e 20 06  ldub  [ %i0 + 6 ], %g1
a009e454:  80 a0 00 01  cmp  %g0, %g1
a009e458:  a0 04 00 13  add  %l0, %l3, %l0
a009e45c:  82 13 22 50  or  %o4, 0x250, %g1
a009e460:  3b 2a 01 f6  sethi  %hi(0xa807d800), %i5
a009e464:  a1 2c 20 03  sll  %l0, 3, %l0
a009e468:  a0 04 00 01  add  %l0, %g1, %l0
a009e46c:  9a 17 63 00  or  %i5, 0x300, %o5
a009e470:  a2 5c e0 34  smul  %l3, 0x34, %l1
a009e474:  a2 04 40 0d  add  %l1, %o5, %l1
a009e478:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009e47c:  d2 04 60 04  ld  [ %l1 + 4 ], %o1
a009e480:  9a 40 20 00  addx  %g0, 0, %o5
a009e484:  82 10 60 b0  or  %g1, 0xb0, %g1
a009e488:  da 28 40 13  stb  %o5, [ %g1 + %l3 ]
a009e48c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009e490:  82 10 60 50  or  %g1, 0x50, %g1	! 0xa8079050
a009e494:  c0 28 40 13  clrb  [ %g1 + %l3 ]
a009e498:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009e49c:  82 10 60 b8  or  %g1, 0xb8, %g1	! 0xa80790b8
a009e4a0:  c0 28 40 13  clrb  [ %g1 + %l3 ]
a009e4a4:  a4 10 20 01  mov  1, %l2
a009e4a8:  e4 2e 20 04  stb  %l2, [ %i0 + 4 ]
a009e4ac:  e4 2e 20 05  stb  %l2, [ %i0 + 5 ]
a009e4b0:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a009e4b4:  b8 10 00 0c  mov  %o4, %i4
a009e4b8:  92 02 60 34  add  %o1, 0x34, %o1
a009e4bc:  c0 2c 20 0b  clrb  [ %l0 + 0xb ]
a009e4c0:  40 00 23 bb  call  0xa00a73ac
a009e4c4:  90 10 20 1c  mov  0x1c, %o0
a009e4c8:  d2 04 60 04  ld  [ %l1 + 4 ], %o1
a009e4cc:  92 02 60 34  add  %o1, 0x34, %o1
a009e4d0:  40 00 23 c1  call  0xa00a73d4
a009e4d4:  90 10 20 1c  mov  0x1c, %o0
a009e4d8:  e4 2e 20 01  stb  %l2, [ %i0 + 1 ]
a009e4dc:  c0 2c 20 14  clrb  [ %l0 + 0x14 ]
a009e4e0:  7f ff e1 71  call  0xa0096aa4
a009e4e4:  90 10 00 13  mov  %l3, %o0
a009e4e8:  7f ff e1 7c  call  0xa0096ad8
a009e4ec:  90 10 00 13  mov  %l3, %o0
a009e4f0:  e0 0e 20 18  ldub  [ %i0 + 0x18 ], %l0
a009e4f4:  80 a4 20 01  cmp  %l0, 1
a009e4f8:  12 80 00 ad  bne  0xa009e7ac
a009e4fc:  c0 2e 21 5c  clrb  [ %i0 + 0x15c ]
a009e500:  c2 0e 20 a3  ldub  [ %i0 + 0xa3 ], %g1
a009e504:  80 a0 60 00  cmp  %g1, 0
a009e508:  32 80 00 17  bne,a   0xa009e564
a009e50c:  23 2a 01 f5  sethi  %hi(0xa807d400), %l1
a009e510:  92 05 60 34  add  %l5, 0x34, %o1
a009e514:  92 05 00 09  add  %l4, %o1, %o1
a009e518:  40 00 04 88  call  0xa009f738
a009e51c:  90 10 00 13  mov  %l3, %o0
a009e520:  80 8a 20 ff  btst  0xff, %o0
a009e524:  22 80 00 0e  be,a   0xa009e55c
a009e528:  e0 2e 20 a2  stb  %l0, [ %i0 + 0xa2 ]
a009e52c:  c2 05 e2 34  ld  [ %l7 + 0x234 ], %g1
a009e530:  80 88 60 04  btst  4, %g1
a009e534:  22 80 00 0c  be,a   0xa009e564
a009e538:  23 2a 01 f5  sethi  %hi(0xa807d400), %l1
a009e53c:  92 05 a0 41  add  %l6, 0x41, %o1
a009e540:  93 2a 60 18  sll  %o1, 0x18, %o1
a009e544:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009e548:  93 3a 60 18  sra  %o1, 0x18, %o1
a009e54c:  7f ff 52 be  call  0xa0073044
a009e550:  90 12 20 d0  or  %o0, 0xd0, %o0
a009e554:  10 80 00 04  b  0xa009e564
a009e558:  23 2a 01 f5  sethi  %hi(0xa807d400), %l1
a009e55c:  e0 2e 20 a1  stb  %l0, [ %i0 + 0xa1 ]
a009e560:  23 2a 01 f5  sethi  %hi(0xa807d400), %l1
a009e564:  92 14 63 e0  or  %l1, 0x3e0, %o1	! 0xa807d7e0
a009e568:  9a 5c e1 90  smul  %l3, 0x190, %o5
a009e56c:  a0 03 40 09  add  %o5, %o1, %l0
a009e570:  c2 0c 20 e8  ldub  [ %l0 + 0xe8 ], %g1
a009e574:  80 a0 60 00  cmp  %g1, 0
a009e578:  32 80 00 1c  bne,a   0xa009e5e8
a009e57c:  c2 0c 21 0e  ldub  [ %l0 + 0x10e ], %g1
a009e580:  92 02 60 bc  add  %o1, 0xbc, %o1
a009e584:  92 03 40 09  add  %o5, %o1, %o1
a009e588:  40 00 05 5a  call  0xa009faf0
a009e58c:  90 10 00 13  mov  %l3, %o0
a009e590:  80 8a 20 ff  btst  0xff, %o0
a009e594:  02 80 00 0f  be  0xa009e5d0
a009e598:  82 10 20 01  mov  1, %g1
a009e59c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009e5a0:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009e5a4:  80 88 60 04  btst  4, %g1
a009e5a8:  22 80 00 0d  be,a   0xa009e5dc
a009e5ac:  92 14 63 e0  or  %l1, 0x3e0, %o1
a009e5b0:  92 05 a0 41  add  %l6, 0x41, %o1
a009e5b4:  93 2a 60 18  sll  %o1, 0x18, %o1
a009e5b8:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009e5bc:  93 3a 60 18  sra  %o1, 0x18, %o1
a009e5c0:  7f ff 52 a1  call  0xa0073044
a009e5c4:  90 12 20 f8  or  %o0, 0xf8, %o0
a009e5c8:  10 80 00 05  b  0xa009e5dc
a009e5cc:  92 14 63 e0  or  %l1, 0x3e0, %o1
a009e5d0:  c2 2c 20 e7  stb  %g1, [ %l0 + 0xe7 ]
a009e5d4:  c2 2c 20 e6  stb  %g1, [ %l0 + 0xe6 ]
a009e5d8:  92 14 63 e0  or  %l1, 0x3e0, %o1
a009e5dc:  9a 5c e1 90  smul  %l3, 0x190, %o5
a009e5e0:  a0 03 40 09  add  %o5, %o1, %l0
a009e5e4:  c2 0c 21 0e  ldub  [ %l0 + 0x10e ], %g1
a009e5e8:  80 a0 60 00  cmp  %g1, 0
a009e5ec:  32 80 00 19  bne,a   0xa009e650
a009e5f0:  92 14 63 e0  or  %l1, 0x3e0, %o1
a009e5f4:  92 02 60 ec  add  %o1, 0xec, %o1
a009e5f8:  92 03 40 09  add  %o5, %o1, %o1
a009e5fc:  40 00 05 af  call  0xa009fcb8
a009e600:  90 10 00 13  mov  %l3, %o0
a009e604:  80 8a 20 ff  btst  0xff, %o0
a009e608:  02 80 00 0f  be  0xa009e644
a009e60c:  82 10 20 01  mov  1, %g1
a009e610:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009e614:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009e618:  80 88 60 04  btst  4, %g1
a009e61c:  22 80 00 0d  be,a   0xa009e650
a009e620:  92 14 63 e0  or  %l1, 0x3e0, %o1
a009e624:  92 05 a0 41  add  %l6, 0x41, %o1
a009e628:  93 2a 60 18  sll  %o1, 0x18, %o1
a009e62c:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009e630:  93 3a 60 18  sra  %o1, 0x18, %o1
a009e634:  7f ff 52 84  call  0xa0073044
a009e638:  90 12 21 20  or  %o0, 0x120, %o0
a009e63c:  10 80 00 05  b  0xa009e650
a009e640:  92 14 63 e0  or  %l1, 0x3e0, %o1
a009e644:  c2 2c 21 0d  stb  %g1, [ %l0 + 0x10d ]
a009e648:  c2 2c 21 0c  stb  %g1, [ %l0 + 0x10c ]
a009e64c:  92 14 63 e0  or  %l1, 0x3e0, %o1
a009e650:  9a 5c e1 90  smul  %l3, 0x190, %o5
a009e654:  a0 03 40 09  add  %o5, %o1, %l0
a009e658:  c2 0c 21 59  ldub  [ %l0 + 0x159 ], %g1
a009e65c:  80 a0 60 00  cmp  %g1, 0
a009e660:  32 80 00 1a  bne,a   0xa009e6c8
a009e664:  92 14 63 e0  or  %l1, 0x3e0, %o1
a009e668:  92 02 61 14  add  %o1, 0x114, %o1
a009e66c:  92 03 40 09  add  %o5, %o1, %o1
a009e670:  40 00 06 18  call  0xa009fed0
a009e674:  90 10 00 13  mov  %l3, %o0
a009e678:  80 8a 20 ff  btst  0xff, %o0
a009e67c:  02 80 00 0f  be  0xa009e6b8
a009e680:  82 10 20 01  mov  1, %g1
a009e684:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009e688:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009e68c:  80 88 60 04  btst  4, %g1
a009e690:  22 80 00 0d  be,a   0xa009e6c4
a009e694:  92 14 63 e0  or  %l1, 0x3e0, %o1
a009e698:  92 05 a0 41  add  %l6, 0x41, %o1
a009e69c:  93 2a 60 18  sll  %o1, 0x18, %o1
a009e6a0:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009e6a4:  93 3a 60 18  sra  %o1, 0x18, %o1
a009e6a8:  7f ff 52 67  call  0xa0073044
a009e6ac:  90 12 21 48  or  %o0, 0x148, %o0
a009e6b0:  10 80 00 05  b  0xa009e6c4
a009e6b4:  92 14 63 e0  or  %l1, 0x3e0, %o1
a009e6b8:  c2 2c 21 58  stb  %g1, [ %l0 + 0x158 ]
a009e6bc:  c2 2c 21 57  stb  %g1, [ %l0 + 0x157 ]
a009e6c0:  92 14 63 e0  or  %l1, 0x3e0, %o1
a009e6c4:  9a 5c e1 90  smul  %l3, 0x190, %o5
a009e6c8:  a0 03 40 09  add  %o5, %o1, %l0
a009e6cc:  c2 0c 21 83  ldub  [ %l0 + 0x183 ], %g1
a009e6d0:  80 a0 60 00  cmp  %g1, 0
a009e6d4:  32 80 00 19  bne,a   0xa009e738
a009e6d8:  92 14 63 e0  or  %l1, 0x3e0, %o1
a009e6dc:  92 02 61 62  add  %o1, 0x162, %o1
a009e6e0:  92 03 40 09  add  %o5, %o1, %o1
a009e6e4:  40 00 06 e1  call  0xa00a0268
a009e6e8:  90 10 00 13  mov  %l3, %o0
a009e6ec:  80 8a 20 ff  btst  0xff, %o0
a009e6f0:  02 80 00 0f  be  0xa009e72c
a009e6f4:  82 10 20 01  mov  1, %g1
a009e6f8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009e6fc:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009e700:  80 88 60 04  btst  4, %g1
a009e704:  22 80 00 0d  be,a   0xa009e738
a009e708:  92 14 63 e0  or  %l1, 0x3e0, %o1
a009e70c:  92 05 a0 41  add  %l6, 0x41, %o1
a009e710:  93 2a 60 18  sll  %o1, 0x18, %o1
a009e714:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009e718:  93 3a 60 18  sra  %o1, 0x18, %o1
a009e71c:  7f ff 52 4a  call  0xa0073044
a009e720:  90 12 21 70  or  %o0, 0x170, %o0
a009e724:  10 80 00 05  b  0xa009e738
a009e728:  92 14 63 e0  or  %l1, 0x3e0, %o1
a009e72c:  c2 2c 21 82  stb  %g1, [ %l0 + 0x182 ]
a009e730:  c2 2c 21 81  stb  %g1, [ %l0 + 0x181 ]
a009e734:  92 14 63 e0  or  %l1, 0x3e0, %o1
a009e738:  9a 5c e1 90  smul  %l3, 0x190, %o5
a009e73c:  a0 03 40 09  add  %o5, %o1, %l0
a009e740:  c2 0c 21 88  ldub  [ %l0 + 0x188 ], %g1
a009e744:  80 a0 60 00  cmp  %g1, 0
a009e748:  12 80 00 3d  bne  0xa009e83c
a009e74c:  b0 0d a0 ff  and  %l6, 0xff, %i0
a009e750:  92 02 61 84  add  %o1, 0x184, %o1
a009e754:  92 03 40 09  add  %o5, %o1, %o1
a009e758:  40 00 07 48  call  0xa00a0478
a009e75c:  90 10 00 13  mov  %l3, %o0
a009e760:  80 8a 20 ff  btst  0xff, %o0
a009e764:  02 80 00 0f  be  0xa009e7a0
a009e768:  82 10 20 01  mov  1, %g1
a009e76c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009e770:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009e774:  80 88 60 04  btst  4, %g1
a009e778:  22 80 00 31  be,a   0xa009e83c
a009e77c:  b0 0d a0 ff  and  %l6, 0xff, %i0
a009e780:  92 05 a0 41  add  %l6, 0x41, %o1
a009e784:  93 2a 60 18  sll  %o1, 0x18, %o1
a009e788:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009e78c:  93 3a 60 18  sra  %o1, 0x18, %o1
a009e790:  7f ff 52 2d  call  0xa0073044
a009e794:  90 12 21 98  or  %o0, 0x198, %o0
a009e798:  10 80 00 29  b  0xa009e83c
a009e79c:  b0 0d a0 ff  and  %l6, 0xff, %i0
a009e7a0:  c2 2c 21 87  stb  %g1, [ %l0 + 0x187 ]
a009e7a4:  10 80 00 25  b  0xa009e838
a009e7a8:  c2 2c 21 86  stb  %g1, [ %l0 + 0x186 ]
a009e7ac:  90 05 60 34  add  %l5, 0x34, %o0
a009e7b0:  92 10 20 00  clr  %o1
a009e7b4:  94 10 20 58  mov  0x58, %o2
a009e7b8:  40 00 4b 7d  call  0xa00b15ac
a009e7bc:  90 05 00 08  add  %l4, %o0, %o0
a009e7c0:  90 05 60 a4  add  %l5, 0xa4, %o0
a009e7c4:  92 10 20 00  clr  %o1
a009e7c8:  94 10 20 30  mov  0x30, %o2
a009e7cc:  40 00 4b 78  call  0xa00b15ac
a009e7d0:  90 05 00 08  add  %l4, %o0, %o0
a009e7d4:  90 05 60 8c  add  %l5, 0x8c, %o0
a009e7d8:  92 10 20 00  clr  %o1
a009e7dc:  94 10 20 18  mov  0x18, %o2
a009e7e0:  40 00 4b 73  call  0xa00b15ac
a009e7e4:  90 05 00 08  add  %l4, %o0, %o0
a009e7e8:  90 05 60 d4  add  %l5, 0xd4, %o0
a009e7ec:  92 10 20 00  clr  %o1
a009e7f0:  94 10 20 24  mov  0x24, %o2
a009e7f4:  40 00 4b 6e  call  0xa00b15ac
a009e7f8:  90 05 00 08  add  %l4, %o0, %o0
a009e7fc:  90 05 60 fc  add  %l5, 0xfc, %o0
a009e800:  92 10 20 00  clr  %o1
a009e804:  94 10 20 48  mov  0x48, %o2
a009e808:  40 00 4b 69  call  0xa00b15ac
a009e80c:  90 05 00 08  add  %l4, %o0, %o0
a009e810:  90 05 61 4a  add  %l5, 0x14a, %o0
a009e814:  92 10 20 00  clr  %o1
a009e818:  94 10 20 22  mov  0x22, %o2
a009e81c:  40 00 4b 64  call  0xa00b15ac
a009e820:  90 05 00 08  add  %l4, %o0, %o0
a009e824:  90 05 61 6c  add  %l5, 0x16c, %o0
a009e828:  90 05 00 08  add  %l4, %o0, %o0
a009e82c:  92 10 20 00  clr  %o1
a009e830:  40 00 4b 5f  call  0xa00b15ac
a009e834:  94 10 20 05  mov  5, %o2
a009e838:  b0 0d a0 ff  and  %l6, 0xff, %i0
a009e83c:  a4 17 63 00  or  %i5, 0x300, %l2
a009e840:  a2 5e 20 34  smul  %i0, 0x34, %l1
a009e844:  82 04 40 12  add  %l1, %l2, %g1
a009e848:  c2 00 60 18  ld  [ %g1 + 0x18 ], %g1
a009e84c:  d2 00 60 90  ld  [ %g1 + 0x90 ], %o1
a009e850:  93 32 60 18  srl  %o1, 0x18, %o1
a009e854:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009e858:  92 0a 60 0f  and  %o1, 0xf, %o1
a009e85c:  7f ff 51 fa  call  0xa0073044
a009e860:  90 12 21 b8  or  %o0, 0x1b8, %o0
a009e864:  40 00 0e 18  call  0xa00a20c4
a009e868:  90 10 00 18  mov  %i0, %o0
a009e86c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009e870:  82 10 63 e0  or  %g1, 0x3e0, %g1	! 0xa807d7e0
a009e874:  95 2a 20 10  sll  %o0, 0x10, %o2
a009e878:  a0 5e 21 90  smul  %i0, 0x190, %l0
a009e87c:  a0 04 00 01  add  %l0, %g1, %l0
a009e880:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009e884:  95 32 a0 10  srl  %o2, 0x10, %o2
a009e888:  d2 14 20 32  lduh  [ %l0 + 0x32 ], %o1
a009e88c:  7f ff 51 ee  call  0xa0073044
a009e890:  90 12 21 f8  or  %o0, 0x1f8, %o0
a009e894:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009e898:  d2 04 20 50  ld  [ %l0 + 0x50 ], %o1
a009e89c:  7f ff 51 ea  call  0xa0073044
a009e8a0:  90 12 22 28  or  %o0, 0x228, %o0
a009e8a4:  d2 04 80 11  ld  [ %l2 + %l1 ], %o1
a009e8a8:  92 02 60 b8  add  %o1, 0xb8, %o1
a009e8ac:  40 00 22 c0  call  0xa00a73ac
a009e8b0:  90 10 20 18  mov  0x18, %o0
a009e8b4:  40 00 08 d2  call  0xa00a0bfc
a009e8b8:  90 10 00 18  mov  %i0, %o0
a009e8bc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009e8c0:  9a 10 62 48  or  %g1, 0x248, %o5	! 0xa8078648
a009e8c4:  c2 0b 40 18  ldub  [ %o5 + %i0 ], %g1
a009e8c8:  80 a0 60 0a  cmp  %g1, 0xa
a009e8cc:  08 80 00 05  bleu  0xa009e8e0
a009e8d0:  82 06 00 18  add  %i0, %i0, %g1
a009e8d4:  82 10 20 0a  mov  0xa, %g1
a009e8d8:  c2 2b 40 18  stb  %g1, [ %o5 + %i0 ]
a009e8dc:  82 06 00 18  add  %i0, %i0, %g1
a009e8e0:  82 00 40 18  add  %g1, %i0, %g1
a009e8e4:  a1 28 60 03  sll  %g1, 3, %l0
a009e8e8:  a4 17 22 50  or  %i4, 0x250, %l2
a009e8ec:  82 04 00 12  add  %l0, %l2, %g1
a009e8f0:  c0 28 60 0a  clrb  [ %g1 + 0xa ]
a009e8f4:  90 10 00 18  mov  %i0, %o0
a009e8f8:  7f ff de 93  call  0xa0096344
a009e8fc:  92 10 20 01  mov  1, %o1
a009e900:  90 10 00 18  mov  %i0, %o0
a009e904:  40 00 08 83  call  0xa00a0b10
a009e908:  92 10 20 01  mov  1, %o1
a009e90c:  90 10 00 18  mov  %i0, %o0
a009e910:  7f ff e5 b9  call  0xa0097ff4
a009e914:  92 10 20 00  clr  %o1
a009e918:  23 2a 01 e1  sethi  %hi(0xa8078400), %l1
a009e91c:  c2 04 62 34  ld  [ %l1 + 0x234 ], %g1	! 0xa8078634
a009e920:  80 88 60 04  btst  4, %g1
a009e924:  22 80 00 09  be,a   0xa009e948
a009e928:  92 07 bf f4  add  %fp, -12, %o1
a009e92c:  92 05 a0 41  add  %l6, 0x41, %o1
a009e930:  93 2a 60 18  sll  %o1, 0x18, %o1
a009e934:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009e938:  90 12 22 60  or  %o0, 0x260, %o0	! 0xa006ae60
a009e93c:  7f ff 51 c2  call  0xa0073044
a009e940:  93 3a 60 18  sra  %o1, 0x18, %o1
a009e944:  92 07 bf f4  add  %fp, -12, %o1
a009e948:  94 07 bf f0  add  %fp, -16, %o2
a009e94c:  40 00 10 ea  call  0xa00a2cf4
a009e950:  90 10 00 18  mov  %i0, %o0
a009e954:  90 10 00 18  mov  %i0, %o0
a009e958:  7f ff f7 a4  call  0xa009c7e8
a009e95c:  92 10 20 01  mov  1, %o1
a009e960:  da 04 62 34  ld  [ %l1 + 0x234 ], %o5
a009e964:  82 10 20 08  mov  8, %g1
a009e968:  80 8b 60 01  btst  1, %o5
a009e96c:  02 80 00 0b  be  0xa009e998
a009e970:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a009e974:  40 00 4d bc  call  0xa00b2064
a009e978:  01 00 00 00  nop
a009e97c:  94 10 00 08  mov  %o0, %o2
a009e980:  92 05 a0 41  add  %l6, 0x41, %o1
a009e984:  93 2a 60 18  sll  %o1, 0x18, %o1
a009e988:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009e98c:  90 12 22 88  or  %o0, 0x288, %o0	! 0xa006ae88
a009e990:  7f ff 51 ad  call  0xa0073044
a009e994:  93 3a 60 18  sra  %o1, 0x18, %o1
a009e998:  b0 10 20 01  mov  1, %i0
a009e99c:  81 c7 e0 08  ret
a009e9a0:  81 e8 00 00  restore
