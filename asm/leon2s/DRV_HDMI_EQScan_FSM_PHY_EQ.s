# leon2s DRV_HDMI_EQScan_FSM_PHY_EQ 0xa007b394-0xa007c4b8 (4388 bytes)
a007b394:  9d e3 bf 98  save  %sp, -104, %sp
a007b398:  a2 0e 20 ff  and  %i0, 0xff, %l1
a007b39c:  82 04 40 11  add  %l1, %l1, %g1
a007b3a0:  82 00 40 11  add  %g1, %l1, %g1
a007b3a4:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a007b3a8:  9a 13 60 64  or  %o5, 0x64, %o5	! 0xa807cc64
a007b3ac:  83 28 60 03  sll  %g1, 3, %g1
a007b3b0:  82 00 40 0d  add  %g1, %o5, %g1
a007b3b4:  2d 2a 01 e1  sethi  %hi(0xa8078400), %l6
a007b3b8:  da 05 a2 34  ld  [ %l6 + 0x234 ], %o5	! 0xa8078634
a007b3bc:  b4 10 00 18  mov  %i0, %i2
a007b3c0:  80 8b 60 02  btst  2, %o5
a007b3c4:  02 80 00 0a  be  0xa007b3ec
a007b3c8:  ea 10 60 08  lduh  [ %g1 + 8 ], %l5
a007b3cc:  92 06 20 41  add  %i0, 0x41, %o1
a007b3d0:  93 2a 60 18  sll  %o1, 0x18, %o1
a007b3d4:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a007b3d8:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a007b3dc:  90 12 20 58  or  %o0, 0x58, %o0
a007b3e0:  93 3a 60 18  sra  %o1, 0x18, %o1
a007b3e4:  7f ff df 18  call  0xa0073044
a007b3e8:  94 12 a2 50  or  %o2, 0x250, %o2
a007b3ec:  25 00 00 04  sethi  %hi(0x1000), %l2
a007b3f0:  90 10 20 01  mov  1, %o0
a007b3f4:  92 10 20 0f  mov  0xf, %o1
a007b3f8:  94 10 00 11  mov  %l1, %o2
a007b3fc:  40 00 b0 0a  call  0xa00a7424
a007b400:  96 14 a1 34  or  %l2, 0x134, %o3
a007b404:  27 00 00 05  sethi  %hi(0x1400), %l3
a007b408:  90 10 20 01  mov  1, %o0
a007b40c:  92 10 20 0f  mov  0xf, %o1
a007b410:  94 10 00 11  mov  %l1, %o2
a007b414:  40 00 b0 04  call  0xa00a7424
a007b418:  96 14 e1 34  or  %l3, 0x134, %o3
a007b41c:  29 00 00 06  sethi  %hi(0x1800), %l4
a007b420:  90 10 20 01  mov  1, %o0
a007b424:  92 10 20 0f  mov  0xf, %o1
a007b428:  94 10 00 11  mov  %l1, %o2
a007b42c:  40 00 af fe  call  0xa00a7424
a007b430:  96 15 21 34  or  %l4, 0x134, %o3
a007b434:  7f ff e0 3b  call  0xa0073520
a007b438:  90 10 00 11  mov  %l1, %o0
a007b43c:  80 8a 20 ff  btst  0xff, %o0
a007b440:  02 80 00 11  be  0xa007b484
a007b444:  21 3f c3 ff  sethi  %hi(0xff0ffc00), %l0
a007b448:  92 14 a1 28  or  %l2, 0x128, %o1
a007b44c:  90 10 00 11  mov  %l1, %o0
a007b450:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b454:  40 00 b0 0d  call  0xa00a7488
a007b458:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a007b45c:  90 10 00 11  mov  %l1, %o0
a007b460:  92 14 e1 28  or  %l3, 0x128, %o1
a007b464:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b468:  40 00 b0 08  call  0xa00a7488
a007b46c:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a007b470:  90 10 00 11  mov  %l1, %o0
a007b474:  92 15 21 28  or  %l4, 0x128, %o1
a007b478:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b47c:  10 80 00 10  b  0xa007b4bc
a007b480:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a007b484:  92 14 a1 28  or  %l2, 0x128, %o1
a007b488:  90 10 00 11  mov  %l1, %o0
a007b48c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b490:  40 00 af fe  call  0xa00a7488
a007b494:  17 00 0c 00  sethi  %hi(0x300000), %o3
a007b498:  90 10 00 11  mov  %l1, %o0
a007b49c:  92 14 e1 28  or  %l3, 0x128, %o1
a007b4a0:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b4a4:  40 00 af f9  call  0xa00a7488
a007b4a8:  17 00 0c 00  sethi  %hi(0x300000), %o3
a007b4ac:  90 10 00 11  mov  %l1, %o0
a007b4b0:  92 15 21 28  or  %l4, 0x128, %o1
a007b4b4:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b4b8:  17 00 0c 00  sethi  %hi(0x300000), %o3
a007b4bc:  40 00 af f3  call  0xa00a7488
a007b4c0:  25 00 00 04  sethi  %hi(0x1000), %l2
a007b4c4:  90 10 00 11  mov  %l1, %o0
a007b4c8:  92 14 a1 b0  or  %l2, 0x1b0, %o1
a007b4cc:  94 10 3f 00  mov  -256, %o2
a007b4d0:  40 00 af ee  call  0xa00a7488
a007b4d4:  96 10 20 f8  mov  0xf8, %o3
a007b4d8:  27 00 00 05  sethi  %hi(0x1400), %l3
a007b4dc:  90 10 00 11  mov  %l1, %o0
a007b4e0:  92 14 e1 b0  or  %l3, 0x1b0, %o1
a007b4e4:  94 10 3f 00  mov  -256, %o2
a007b4e8:  40 00 af e8  call  0xa00a7488
a007b4ec:  96 10 20 f8  mov  0xf8, %o3
a007b4f0:  29 00 00 06  sethi  %hi(0x1800), %l4
a007b4f4:  90 10 00 11  mov  %l1, %o0
a007b4f8:  92 15 21 b0  or  %l4, 0x1b0, %o1
a007b4fc:  94 10 3f 00  mov  -256, %o2
a007b500:  40 00 af e2  call  0xa00a7488
a007b504:  96 10 20 f8  mov  0xf8, %o3
a007b508:  7f ff e0 06  call  0xa0073520
a007b50c:  90 10 00 11  mov  %l1, %o0
a007b510:  80 8a 20 ff  btst  0xff, %o0
a007b514:  02 80 00 26  be  0xa007b5ac
a007b518:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a007b51c:  94 12 a3 ff  or  %o2, 0x3ff, %o2	! 0xffffff
a007b520:  90 10 00 11  mov  %l1, %o0
a007b524:  92 14 a0 1c  or  %l2, 0x1c, %o1
a007b528:  40 00 af d8  call  0xa00a7488
a007b52c:  17 2e c0 00  sethi  %hi(0xbb000000), %o3
a007b530:  94 10 00 11  mov  %l1, %o2
a007b534:  96 14 a1 34  or  %l2, 0x134, %o3
a007b538:  90 10 20 01  mov  1, %o0
a007b53c:  40 00 af ba  call  0xa00a7424
a007b540:  92 10 20 0f  mov  0xf, %o1
a007b544:  21 3f c3 ff  sethi  %hi(0xff0ffc00), %l0
a007b548:  90 10 00 11  mov  %l1, %o0
a007b54c:  92 14 a1 28  or  %l2, 0x128, %o1
a007b550:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b554:  40 00 af cd  call  0xa00a7488
a007b558:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a007b55c:  94 10 00 11  mov  %l1, %o2
a007b560:  96 14 e1 34  or  %l3, 0x134, %o3
a007b564:  90 10 20 01  mov  1, %o0
a007b568:  40 00 af af  call  0xa00a7424
a007b56c:  92 10 20 0f  mov  0xf, %o1
a007b570:  90 10 00 11  mov  %l1, %o0
a007b574:  92 14 e1 28  or  %l3, 0x128, %o1
a007b578:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b57c:  40 00 af c3  call  0xa00a7488
a007b580:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a007b584:  94 10 00 11  mov  %l1, %o2
a007b588:  96 15 21 34  or  %l4, 0x134, %o3
a007b58c:  90 10 20 01  mov  1, %o0
a007b590:  40 00 af a5  call  0xa00a7424
a007b594:  92 10 20 0f  mov  0xf, %o1
a007b598:  90 10 00 11  mov  %l1, %o0
a007b59c:  92 15 21 28  or  %l4, 0x128, %o1
a007b5a0:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b5a4:  10 80 00 25  b  0xa007b638
a007b5a8:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a007b5ac:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007b5b0:  90 10 00 11  mov  %l1, %o0
a007b5b4:  92 14 a0 1c  or  %l2, 0x1c, %o1
a007b5b8:  40 00 af b4  call  0xa00a7488
a007b5bc:  17 2e c0 00  sethi  %hi(0xbb000000), %o3
a007b5c0:  90 10 20 01  mov  1, %o0
a007b5c4:  92 10 20 0f  mov  0xf, %o1
a007b5c8:  94 10 00 11  mov  %l1, %o2
a007b5cc:  40 00 af 96  call  0xa00a7424
a007b5d0:  96 14 a1 34  or  %l2, 0x134, %o3
a007b5d4:  21 3f c3 ff  sethi  %hi(0xff0ffc00), %l0
a007b5d8:  90 10 00 11  mov  %l1, %o0
a007b5dc:  92 14 a1 28  or  %l2, 0x128, %o1
a007b5e0:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b5e4:  40 00 af a9  call  0xa00a7488
a007b5e8:  17 00 0c 00  sethi  %hi(0x300000), %o3
a007b5ec:  90 10 20 01  mov  1, %o0
a007b5f0:  92 10 20 0f  mov  0xf, %o1
a007b5f4:  94 10 00 11  mov  %l1, %o2
a007b5f8:  40 00 af 8b  call  0xa00a7424
a007b5fc:  96 14 e1 34  or  %l3, 0x134, %o3
a007b600:  90 10 00 11  mov  %l1, %o0
a007b604:  92 14 e1 28  or  %l3, 0x128, %o1
a007b608:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b60c:  40 00 af 9f  call  0xa00a7488
a007b610:  17 00 0c 00  sethi  %hi(0x300000), %o3
a007b614:  90 10 20 01  mov  1, %o0
a007b618:  92 10 20 0f  mov  0xf, %o1
a007b61c:  94 10 00 11  mov  %l1, %o2
a007b620:  40 00 af 81  call  0xa00a7424
a007b624:  96 15 21 34  or  %l4, 0x134, %o3
a007b628:  90 10 00 11  mov  %l1, %o0
a007b62c:  92 15 21 28  or  %l4, 0x128, %o1
a007b630:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b634:  17 00 0c 00  sethi  %hi(0x300000), %o3
a007b638:  40 00 af 94  call  0xa00a7488
a007b63c:  b3 2d 60 10  sll  %l5, 0x10, %i1
a007b640:  83 36 60 10  srl  %i1, 0x10, %g1
a007b644:  80 a0 61 2c  cmp  %g1, 0x12c
a007b648:  b0 0e a0 ff  and  %i2, 0xff, %i0
a007b64c:  08 80 00 0a  bleu  0xa007b674
a007b650:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a007b654:  82 04 40 11  add  %l1, %l1, %g1
a007b658:  82 00 40 11  add  %g1, %l1, %g1
a007b65c:  9a 13 60 c4  or  %o5, 0xc4, %o5
a007b660:  83 28 60 02  sll  %g1, 2, %g1
a007b664:  82 00 40 0d  add  %g1, %o5, %g1
a007b668:  9a 10 20 01  mov  1, %o5
a007b66c:  10 80 00 08  b  0xa007b68c
a007b670:  da 28 60 08  stb  %o5, [ %g1 + 8 ]
a007b674:  82 04 40 11  add  %l1, %l1, %g1
a007b678:  82 00 40 11  add  %g1, %l1, %g1
a007b67c:  9a 13 60 c4  or  %o5, 0xc4, %o5
a007b680:  83 28 60 02  sll  %g1, 2, %g1
a007b684:  82 00 40 0d  add  %g1, %o5, %g1
a007b688:  c0 28 60 08  clrb  [ %g1 + 8 ]
a007b68c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007b690:  82 10 61 98  or  %g1, 0x198, %g1	! 0xa8078998
a007b694:  c2 08 40 18  ldub  [ %g1 + %i0 ], %g1
a007b698:  80 a0 60 00  cmp  %g1, 0
a007b69c:  12 80 00 06  bne  0xa007b6b4
a007b6a0:  21 2a 01 e2  sethi  %hi(0xa8078800), %l0
a007b6a4:  90 10 00 18  mov  %i0, %o0
a007b6a8:  7f ff e6 ba  call  0xa0075190
a007b6ac:  92 10 20 05  mov  5, %o1
a007b6b0:  21 2a 01 e2  sethi  %hi(0xa8078800), %l0
a007b6b4:  c2 0c 21 8c  ldub  [ %l0 + 0x18c ], %g1	! 0xa807898c
a007b6b8:  80 a0 60 00  cmp  %g1, 0
a007b6bc:  02 80 00 15  be  0xa007b710
a007b6c0:  82 06 00 18  add  %i0, %i0, %g1
a007b6c4:  c2 05 a2 34  ld  [ %l6 + 0x234 ], %g1
a007b6c8:  80 88 60 02  btst  2, %g1
a007b6cc:  02 80 00 09  be  0xa007b6f0
a007b6d0:  82 06 00 18  add  %i0, %i0, %g1
a007b6d4:  92 06 a0 41  add  %i2, 0x41, %o1
a007b6d8:  93 2a 60 18  sll  %o1, 0x18, %o1
a007b6dc:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007b6e0:  90 12 21 88  or  %o0, 0x188, %o0	! 0xa0067988
a007b6e4:  7f ff de 58  call  0xa0073044
a007b6e8:  93 3a 60 18  sra  %o1, 0x18, %o1
a007b6ec:  82 06 00 18  add  %i0, %i0, %g1
a007b6f0:  82 00 40 18  add  %g1, %i0, %g1
a007b6f4:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a007b6f8:  83 28 60 02  sll  %g1, 2, %g1
a007b6fc:  9a 13 60 c4  or  %o5, 0xc4, %o5
a007b700:  82 00 40 0d  add  %g1, %o5, %g1
a007b704:  c0 28 60 08  clrb  [ %g1 + 8 ]
a007b708:  c0 2c 21 8c  clrb  [ %l0 + 0x18c ]
a007b70c:  82 06 00 18  add  %i0, %i0, %g1
a007b710:  82 00 40 18  add  %g1, %i0, %g1
a007b714:  19 2a 01 f3  sethi  %hi(0xa807cc00), %o4
a007b718:  83 28 60 02  sll  %g1, 2, %g1
a007b71c:  9a 13 20 c4  or  %o4, 0xc4, %o5
a007b720:  82 00 40 0d  add  %g1, %o5, %g1
a007b724:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a007b728:  80 a0 60 01  cmp  %g1, 1
a007b72c:  12 80 00 9e  bne  0xa007b9a4
a007b730:  37 2a 01 e1  sethi  %hi(0xa8078400), %i3
a007b734:  c2 06 e2 34  ld  [ %i3 + 0x234 ], %g1	! 0xa8078634
a007b738:  80 88 60 02  btst  2, %g1
a007b73c:  02 80 00 09  be  0xa007b760
a007b740:  21 3f c0 3f  sethi  %hi(0xff00fc00), %l0
a007b744:  92 06 a0 41  add  %i2, 0x41, %o1
a007b748:  93 2a 60 18  sll  %o1, 0x18, %o1
a007b74c:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007b750:  90 12 21 b8  or  %o0, 0x1b8, %o0	! 0xa00679b8
a007b754:  7f ff de 3c  call  0xa0073044
a007b758:  93 3a 60 18  sra  %o1, 0x18, %o1
a007b75c:  21 3f c0 3f  sethi  %hi(0xff00fc00), %l0
a007b760:  27 00 00 04  sethi  %hi(0x1000), %l3
a007b764:  90 10 00 18  mov  %i0, %o0
a007b768:  92 14 e1 70  or  %l3, 0x170, %o1
a007b76c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b770:  40 00 af 46  call  0xa00a7488
a007b774:  17 00 0b 00  sethi  %hi(0x2c0000), %o3
a007b778:  3b 00 00 05  sethi  %hi(0x1400), %i5
a007b77c:  90 10 00 18  mov  %i0, %o0
a007b780:  92 17 61 70  or  %i5, 0x170, %o1
a007b784:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b788:  40 00 af 40  call  0xa00a7488
a007b78c:  17 00 0b 00  sethi  %hi(0x2c0000), %o3
a007b790:  39 00 00 06  sethi  %hi(0x1800), %i4
a007b794:  90 10 00 18  mov  %i0, %o0
a007b798:  92 17 21 70  or  %i4, 0x170, %o1
a007b79c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b7a0:  40 00 af 3a  call  0xa00a7488
a007b7a4:  17 00 0b 00  sethi  %hi(0x2c0000), %o3
a007b7a8:  90 10 00 18  mov  %i0, %o0
a007b7ac:  92 14 e1 7c  or  %l3, 0x17c, %o1
a007b7b0:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b7b4:  40 00 af 35  call  0xa00a7488
a007b7b8:  17 00 3f c0  sethi  %hi(0xff0000), %o3
a007b7bc:  90 10 00 18  mov  %i0, %o0
a007b7c0:  92 17 61 7c  or  %i5, 0x17c, %o1
a007b7c4:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b7c8:  40 00 af 30  call  0xa00a7488
a007b7cc:  17 00 3f c0  sethi  %hi(0xff0000), %o3
a007b7d0:  90 10 00 18  mov  %i0, %o0
a007b7d4:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b7d8:  92 17 21 7c  or  %i4, 0x17c, %o1
a007b7dc:  40 00 af 2b  call  0xa00a7488
a007b7e0:  17 00 3f c0  sethi  %hi(0xff0000), %o3
a007b7e4:  7f ff df 4f  call  0xa0073520
a007b7e8:  90 10 00 18  mov  %i0, %o0
a007b7ec:  80 8a 20 ff  btst  0xff, %o0
a007b7f0:  02 80 00 44  be  0xa007b900
a007b7f4:  23 2a 01 d8  sethi  %hi(0xa8076000), %l1
a007b7f8:  2f 2a 01 f3  sethi  %hi(0xa807cc00), %l7
a007b7fc:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007b800:  aa 10 62 cc  or  %g1, 0x2cc, %l5	! 0xa00b3acc
a007b804:  2d 2a 01 f3  sethi  %hi(0xa807cc00), %l6
a007b808:  d8 0d e0 f8  ldub  [ %l7 + 0xf8 ], %o4
a007b80c:  99 2b 20 02  sll  %o4, 2, %o4
a007b810:  da 0d a0 58  ldub  [ %l6 + 0x58 ], %o5
a007b814:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007b818:  21 00 00 3f  sethi  %hi(0xfc00), %l0
a007b81c:  d6 05 40 0c  ld  [ %l5 + %o4 ], %o3
a007b820:  a8 10 62 d4  or  %g1, 0x2d4, %l4
a007b824:  a0 14 23 ff  or  %l0, 0x3ff, %l0
a007b828:  9b 2b 60 02  sll  %o5, 2, %o5
a007b82c:  c2 05 00 0d  ld  [ %l4 + %o5 ], %g1
a007b830:  96 0a c0 10  and  %o3, %l0, %o3
a007b834:  82 08 60 0f  and  %g1, 0xf, %g1
a007b838:  23 3f c0 00  sethi  %hi(0xff000000), %l1
a007b83c:  97 2a e0 08  sll  %o3, 8, %o3
a007b840:  96 10 40 0b  or  %g1, %o3, %o3
a007b844:  92 14 e1 78  or  %l3, 0x178, %o1
a007b848:  90 10 00 18  mov  %i0, %o0
a007b84c:  40 00 af 0f  call  0xa00a7488
a007b850:  94 14 60 f0  or  %l1, 0xf0, %o2
a007b854:  a4 15 e0 f8  or  %l7, 0xf8, %l2
a007b858:  a6 15 a0 58  or  %l6, 0x58, %l3
a007b85c:  da 0c a0 01  ldub  [ %l2 + 1 ], %o5
a007b860:  9b 2b 60 02  sll  %o5, 2, %o5
a007b864:  c2 0c e0 01  ldub  [ %l3 + 1 ], %g1
a007b868:  d6 05 40 0d  ld  [ %l5 + %o5 ], %o3
a007b86c:  83 28 60 02  sll  %g1, 2, %g1
a007b870:  c2 05 00 01  ld  [ %l4 + %g1 ], %g1
a007b874:  96 0a c0 10  and  %o3, %l0, %o3
a007b878:  82 08 60 0f  and  %g1, 0xf, %g1
a007b87c:  97 2a e0 08  sll  %o3, 8, %o3
a007b880:  96 10 40 0b  or  %g1, %o3, %o3
a007b884:  92 17 61 78  or  %i5, 0x178, %o1
a007b888:  90 10 00 18  mov  %i0, %o0
a007b88c:  40 00 ae ff  call  0xa00a7488
a007b890:  94 14 60 f0  or  %l1, 0xf0, %o2
a007b894:  c2 0c a0 02  ldub  [ %l2 + 2 ], %g1
a007b898:  da 0c e0 02  ldub  [ %l3 + 2 ], %o5
a007b89c:  83 28 60 02  sll  %g1, 2, %g1
a007b8a0:  9b 2b 60 02  sll  %o5, 2, %o5
a007b8a4:  c2 05 40 01  ld  [ %l5 + %g1 ], %g1
a007b8a8:  d6 05 00 0d  ld  [ %l4 + %o5 ], %o3
a007b8ac:  82 08 40 10  and  %g1, %l0, %g1
a007b8b0:  83 28 60 08  sll  %g1, 8, %g1
a007b8b4:  96 0a e0 0f  and  %o3, 0xf, %o3
a007b8b8:  96 12 c0 01  or  %o3, %g1, %o3
a007b8bc:  92 17 21 78  or  %i4, 0x178, %o1
a007b8c0:  94 14 60 f0  or  %l1, 0xf0, %o2
a007b8c4:  40 00 ae f1  call  0xa00a7488
a007b8c8:  90 10 00 18  mov  %i0, %o0
a007b8cc:  c2 06 e2 34  ld  [ %i3 + 0x234 ], %g1
a007b8d0:  80 88 60 02  btst  2, %g1
a007b8d4:  22 80 00 71  be,a   0xa007ba98
a007b8d8:  83 36 60 10  srl  %i1, 0x10, %g1
a007b8dc:  c2 0d a0 58  ldub  [ %l6 + 0x58 ], %g1
a007b8e0:  da 0d e0 f8  ldub  [ %l7 + 0xf8 ], %o5
a007b8e4:  83 28 60 02  sll  %g1, 2, %g1
a007b8e8:  9b 2b 60 02  sll  %o5, 2, %o5
a007b8ec:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007b8f0:  d2 05 00 01  ld  [ %l4 + %g1 ], %o1
a007b8f4:  d4 05 40 0d  ld  [ %l5 + %o5 ], %o2
a007b8f8:  10 80 00 27  b  0xa007b994
a007b8fc:  90 12 21 e0  or  %o0, 0x1e0, %o0
a007b900:  25 2a 01 d8  sethi  %hi(0xa8076000), %l2
a007b904:  c2 0c 61 9e  ldub  [ %l1 + 0x19e ], %g1
a007b908:  d6 14 a1 9c  lduh  [ %l2 + 0x19c ], %o3
a007b90c:  82 08 60 0f  and  %g1, 0xf, %g1
a007b910:  21 3f c0 00  sethi  %hi(0xff000000), %l0
a007b914:  97 2a e0 08  sll  %o3, 8, %o3
a007b918:  96 10 40 0b  or  %g1, %o3, %o3
a007b91c:  92 14 e1 78  or  %l3, 0x178, %o1
a007b920:  90 10 00 18  mov  %i0, %o0
a007b924:  40 00 ae d9  call  0xa00a7488
a007b928:  94 14 20 f0  or  %l0, 0xf0, %o2
a007b92c:  c2 0c 61 9e  ldub  [ %l1 + 0x19e ], %g1
a007b930:  d6 14 a1 9c  lduh  [ %l2 + 0x19c ], %o3
a007b934:  82 08 60 0f  and  %g1, 0xf, %g1
a007b938:  97 2a e0 08  sll  %o3, 8, %o3
a007b93c:  96 10 40 0b  or  %g1, %o3, %o3
a007b940:  92 17 61 78  or  %i5, 0x178, %o1
a007b944:  90 10 00 18  mov  %i0, %o0
a007b948:  40 00 ae d0  call  0xa00a7488
a007b94c:  94 14 20 f0  or  %l0, 0xf0, %o2
a007b950:  c2 0c 61 9e  ldub  [ %l1 + 0x19e ], %g1
a007b954:  d6 14 a1 9c  lduh  [ %l2 + 0x19c ], %o3
a007b958:  82 08 60 0f  and  %g1, 0xf, %g1
a007b95c:  97 2a e0 08  sll  %o3, 8, %o3
a007b960:  96 10 40 0b  or  %g1, %o3, %o3
a007b964:  92 17 21 78  or  %i4, 0x178, %o1
a007b968:  94 14 20 f0  or  %l0, 0xf0, %o2
a007b96c:  40 00 ae c7  call  0xa00a7488
a007b970:  90 10 00 18  mov  %i0, %o0
a007b974:  c2 06 e2 34  ld  [ %i3 + 0x234 ], %g1
a007b978:  80 88 60 02  btst  2, %g1
a007b97c:  22 80 00 47  be,a   0xa007ba98
a007b980:  83 36 60 10  srl  %i1, 0x10, %g1
a007b984:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007b988:  90 12 22 18  or  %o0, 0x218, %o0	! 0xa0067a18
a007b98c:  d2 0c 61 9e  ldub  [ %l1 + 0x19e ], %o1
a007b990:  d4 14 a1 9c  lduh  [ %l2 + 0x19c ], %o2
a007b994:  7f ff dd ac  call  0xa0073044
a007b998:  01 00 00 00  nop
a007b99c:  10 80 00 3f  b  0xa007ba98
a007b9a0:  83 36 60 10  srl  %i1, 0x10, %g1
a007b9a4:  c2 06 e2 34  ld  [ %i3 + 0x234 ], %g1
a007b9a8:  80 88 60 02  btst  2, %g1
a007b9ac:  22 80 00 09  be,a   0xa007b9d0
a007b9b0:  21 3f c0 3f  sethi  %hi(0xff00fc00), %l0
a007b9b4:  92 06 a0 41  add  %i2, 0x41, %o1
a007b9b8:  93 2a 60 18  sll  %o1, 0x18, %o1
a007b9bc:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007b9c0:  90 12 22 50  or  %o0, 0x250, %o0	! 0xa0067a50
a007b9c4:  7f ff dd a0  call  0xa0073044
a007b9c8:  93 3a 60 18  sra  %o1, 0x18, %o1
a007b9cc:  21 3f c0 3f  sethi  %hi(0xff00fc00), %l0
a007b9d0:  27 00 00 04  sethi  %hi(0x1000), %l3
a007b9d4:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b9d8:  90 10 00 18  mov  %i0, %o0
a007b9dc:  92 14 e1 70  or  %l3, 0x170, %o1
a007b9e0:  40 00 ae aa  call  0xa00a7488
a007b9e4:  17 00 0b c0  sethi  %hi(0x2f0000), %o3
a007b9e8:  25 00 00 05  sethi  %hi(0x1400), %l2
a007b9ec:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007b9f0:  90 10 00 18  mov  %i0, %o0
a007b9f4:  92 14 a1 70  or  %l2, 0x170, %o1
a007b9f8:  40 00 ae a4  call  0xa00a7488
a007b9fc:  17 00 0b c0  sethi  %hi(0x2f0000), %o3
a007ba00:  23 00 00 06  sethi  %hi(0x1800), %l1
a007ba04:  92 14 61 70  or  %l1, 0x170, %o1	! 0x1970
a007ba08:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007ba0c:  90 10 00 18  mov  %i0, %o0
a007ba10:  40 00 ae 9e  call  0xa00a7488
a007ba14:  17 00 0b c0  sethi  %hi(0x2f0000), %o3
a007ba18:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007ba1c:  90 10 00 18  mov  %i0, %o0
a007ba20:  92 14 e1 7c  or  %l3, 0x17c, %o1
a007ba24:  40 00 ae 99  call  0xa00a7488
a007ba28:  17 00 13 c0  sethi  %hi(0x4f0000), %o3
a007ba2c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007ba30:  90 10 00 18  mov  %i0, %o0
a007ba34:  92 14 a1 7c  or  %l2, 0x17c, %o1
a007ba38:  40 00 ae 94  call  0xa00a7488
a007ba3c:  17 00 13 c0  sethi  %hi(0x4f0000), %o3
a007ba40:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007ba44:  92 14 61 7c  or  %l1, 0x17c, %o1
a007ba48:  17 00 13 c0  sethi  %hi(0x4f0000), %o3
a007ba4c:  90 10 00 18  mov  %i0, %o0
a007ba50:  40 00 ae 8e  call  0xa00a7488
a007ba54:  21 2a 01 ea  sethi  %hi(0xa807a800), %l0
a007ba58:  a0 14 21 f0  or  %l0, 0x1f0, %l0	! 0xa807a9f0
a007ba5c:  a2 5e 28 98  smul  %i0, 0x898, %l1
a007ba60:  d4 0c 00 11  ldub  [ %l0 + %l1 ], %o2
a007ba64:  90 10 00 18  mov  %i0, %o0
a007ba68:  7f ff e5 23  call  0xa0074ef4
a007ba6c:  92 10 20 00  clr  %o1
a007ba70:  a2 04 40 10  add  %l1, %l0, %l1
a007ba74:  90 10 00 18  mov  %i0, %o0
a007ba78:  92 10 20 01  mov  1, %o1
a007ba7c:  7f ff e5 1e  call  0xa0074ef4
a007ba80:  d4 0c 60 01  ldub  [ %l1 + 1 ], %o2
a007ba84:  90 10 00 18  mov  %i0, %o0
a007ba88:  d4 0c 60 02  ldub  [ %l1 + 2 ], %o2
a007ba8c:  7f ff e5 1a  call  0xa0074ef4
a007ba90:  92 10 20 02  mov  2, %o1
a007ba94:  83 36 60 10  srl  %i1, 0x10, %g1
a007ba98:  80 a0 60 63  cmp  %g1, 0x63
a007ba9c:  18 80 00 6e  bgu  0xa007bc54
a007baa0:  80 a0 60 9f  cmp  %g1, 0x9f
a007baa4:  7f ff de 9f  call  0xa0073520
a007baa8:  90 10 00 18  mov  %i0, %o0
a007baac:  80 8a 20 ff  btst  0xff, %o0
a007bab0:  12 80 00 22  bne  0xa007bb38
a007bab4:  29 00 00 04  sethi  %hi(0x1000), %l4
a007bab8:  94 10 00 18  mov  %i0, %o2
a007babc:  96 15 20 1c  or  %l4, 0x1c, %o3
a007bac0:  90 10 20 01  mov  1, %o0
a007bac4:  40 00 ae 58  call  0xa00a7424
a007bac8:  92 10 20 07  mov  7, %o1
a007bacc:  27 00 00 05  sethi  %hi(0x1400), %l3
a007bad0:  94 10 00 18  mov  %i0, %o2
a007bad4:  96 14 e0 1c  or  %l3, 0x1c, %o3
a007bad8:  90 10 20 01  mov  1, %o0
a007badc:  40 00 ae 52  call  0xa00a7424
a007bae0:  92 10 20 07  mov  7, %o1
a007bae4:  25 00 00 06  sethi  %hi(0x1800), %l2
a007bae8:  94 10 00 18  mov  %i0, %o2
a007baec:  96 14 a0 1c  or  %l2, 0x1c, %o3
a007baf0:  90 10 20 01  mov  1, %o0
a007baf4:  40 00 ae 4c  call  0xa00a7424
a007baf8:  92 10 20 07  mov  7, %o1
a007bafc:  90 10 00 18  mov  %i0, %o0
a007bb00:  92 15 20 1c  or  %l4, 0x1c, %o1
a007bb04:  94 10 3f f9  mov  -7, %o2
a007bb08:  40 00 ae 60  call  0xa00a7488
a007bb0c:  96 10 20 02  mov  2, %o3
a007bb10:  90 10 00 18  mov  %i0, %o0
a007bb14:  92 14 e0 1c  or  %l3, 0x1c, %o1
a007bb18:  94 10 3f f9  mov  -7, %o2
a007bb1c:  40 00 ae 5b  call  0xa00a7488
a007bb20:  96 10 20 02  mov  2, %o3
a007bb24:  90 10 00 18  mov  %i0, %o0
a007bb28:  92 14 a0 1c  or  %l2, 0x1c, %o1
a007bb2c:  94 10 3f f9  mov  -7, %o2
a007bb30:  10 80 00 bf  b  0xa007be2c
a007bb34:  96 10 20 02  mov  2, %o3
a007bb38:  21 3f c0 00  sethi  %hi(0xff000000), %l0
a007bb3c:  23 00 00 3f  sethi  %hi(0xfc00), %l1
a007bb40:  94 14 20 f0  or  %l0, 0xf0, %o2
a007bb44:  90 10 00 18  mov  %i0, %o0
a007bb48:  92 15 21 78  or  %l4, 0x178, %o1
a007bb4c:  40 00 ae 4f  call  0xa00a7488
a007bb50:  96 14 63 08  or  %l1, 0x308, %o3
a007bb54:  27 00 00 05  sethi  %hi(0x1400), %l3
a007bb58:  94 14 20 f0  or  %l0, 0xf0, %o2
a007bb5c:  90 10 00 18  mov  %i0, %o0
a007bb60:  92 14 e1 78  or  %l3, 0x178, %o1
a007bb64:  40 00 ae 49  call  0xa00a7488
a007bb68:  96 14 63 08  or  %l1, 0x308, %o3
a007bb6c:  25 00 00 06  sethi  %hi(0x1800), %l2
a007bb70:  94 14 20 f0  or  %l0, 0xf0, %o2
a007bb74:  90 10 00 18  mov  %i0, %o0
a007bb78:  96 14 63 08  or  %l1, 0x308, %o3
a007bb7c:  40 00 ae 43  call  0xa00a7488
a007bb80:  92 14 a1 78  or  %l2, 0x178, %o1
a007bb84:  94 10 00 18  mov  %i0, %o2
a007bb88:  96 15 20 1c  or  %l4, 0x1c, %o3
a007bb8c:  90 10 20 01  mov  1, %o0
a007bb90:  40 00 ae 25  call  0xa00a7424
a007bb94:  92 10 20 07  mov  7, %o1
a007bb98:  94 10 00 18  mov  %i0, %o2
a007bb9c:  96 14 e0 1c  or  %l3, 0x1c, %o3
a007bba0:  90 10 20 01  mov  1, %o0
a007bba4:  40 00 ae 20  call  0xa00a7424
a007bba8:  92 10 20 07  mov  7, %o1
a007bbac:  94 10 00 18  mov  %i0, %o2
a007bbb0:  96 14 a0 1c  or  %l2, 0x1c, %o3
a007bbb4:  90 10 20 01  mov  1, %o0
a007bbb8:  40 00 ae 1b  call  0xa00a7424
a007bbbc:  92 10 20 07  mov  7, %o1
a007bbc0:  90 10 00 18  mov  %i0, %o0
a007bbc4:  92 15 20 1c  or  %l4, 0x1c, %o1
a007bbc8:  94 10 3f f9  mov  -7, %o2
a007bbcc:  40 00 ae 2f  call  0xa00a7488
a007bbd0:  96 10 20 02  mov  2, %o3
a007bbd4:  90 10 00 18  mov  %i0, %o0
a007bbd8:  92 14 e0 1c  or  %l3, 0x1c, %o1
a007bbdc:  94 10 3f f9  mov  -7, %o2
a007bbe0:  40 00 ae 2a  call  0xa00a7488
a007bbe4:  96 10 20 02  mov  2, %o3
a007bbe8:  90 10 00 18  mov  %i0, %o0
a007bbec:  92 14 a0 1c  or  %l2, 0x1c, %o1
a007bbf0:  94 10 3f f9  mov  -7, %o2
a007bbf4:  40 00 ae 25  call  0xa00a7488
a007bbf8:  96 10 20 02  mov  2, %o3
a007bbfc:  21 3f f3 ff  sethi  %hi(0xffcffc00), %l0
a007bc00:  90 10 00 18  mov  %i0, %o0
a007bc04:  92 15 20 20  or  %l4, 0x20, %o1
a007bc08:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007bc0c:  40 00 ae 1f  call  0xa00a7488
a007bc10:  17 00 04 00  sethi  %hi(0x100000), %o3
a007bc14:  90 10 00 18  mov  %i0, %o0
a007bc18:  92 14 e0 20  or  %l3, 0x20, %o1
a007bc1c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007bc20:  40 00 ae 1a  call  0xa00a7488
a007bc24:  17 00 04 00  sethi  %hi(0x100000), %o3
a007bc28:  90 10 00 18  mov  %i0, %o0
a007bc2c:  92 14 a0 20  or  %l2, 0x20, %o1
a007bc30:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007bc34:  40 00 ae 15  call  0xa00a7488
a007bc38:  17 00 04 00  sethi  %hi(0x100000), %o3
a007bc3c:  13 00 00 0d  sethi  %hi(0x3400), %o1
a007bc40:  90 10 00 18  mov  %i0, %o0
a007bc44:  92 12 62 14  or  %o1, 0x214, %o1
a007bc48:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a007bc4c:  10 80 01 75  b  0xa007c220
a007bc50:  96 10 21 60  mov  0x160, %o3
a007bc54:  18 80 00 4f  bgu  0xa007bd90
a007bc58:  80 a0 61 2b  cmp  %g1, 0x12b
a007bc5c:  7f ff de 31  call  0xa0073520
a007bc60:  90 10 00 18  mov  %i0, %o0
a007bc64:  80 8a 20 ff  btst  0xff, %o0
a007bc68:  02 80 00 52  be  0xa007bdb0
a007bc6c:  29 00 00 04  sethi  %hi(0x1000), %l4
a007bc70:  21 3f c0 00  sethi  %hi(0xff000000), %l0
a007bc74:  23 00 00 3f  sethi  %hi(0xfc00), %l1
a007bc78:  94 14 20 f0  or  %l0, 0xf0, %o2
a007bc7c:  90 10 00 18  mov  %i0, %o0
a007bc80:  92 15 21 78  or  %l4, 0x178, %o1
a007bc84:  40 00 ae 01  call  0xa00a7488
a007bc88:  96 14 63 08  or  %l1, 0x308, %o3
a007bc8c:  27 00 00 05  sethi  %hi(0x1400), %l3
a007bc90:  94 14 20 f0  or  %l0, 0xf0, %o2
a007bc94:  90 10 00 18  mov  %i0, %o0
a007bc98:  92 14 e1 78  or  %l3, 0x178, %o1
a007bc9c:  40 00 ad fb  call  0xa00a7488
a007bca0:  96 14 63 08  or  %l1, 0x308, %o3
a007bca4:  25 00 00 06  sethi  %hi(0x1800), %l2
a007bca8:  94 14 20 f0  or  %l0, 0xf0, %o2
a007bcac:  90 10 00 18  mov  %i0, %o0
a007bcb0:  96 14 63 08  or  %l1, 0x308, %o3
a007bcb4:  40 00 ad f5  call  0xa00a7488
a007bcb8:  92 14 a1 78  or  %l2, 0x178, %o1
a007bcbc:  94 10 00 18  mov  %i0, %o2
a007bcc0:  96 15 20 1c  or  %l4, 0x1c, %o3
a007bcc4:  90 10 20 01  mov  1, %o0
a007bcc8:  40 00 ad d7  call  0xa00a7424
a007bccc:  92 10 20 07  mov  7, %o1
a007bcd0:  94 10 00 18  mov  %i0, %o2
a007bcd4:  96 14 e0 1c  or  %l3, 0x1c, %o3
a007bcd8:  90 10 20 01  mov  1, %o0
a007bcdc:  40 00 ad d2  call  0xa00a7424
a007bce0:  92 10 20 07  mov  7, %o1
a007bce4:  94 10 00 18  mov  %i0, %o2
a007bce8:  96 14 a0 1c  or  %l2, 0x1c, %o3
a007bcec:  90 10 20 01  mov  1, %o0
a007bcf0:  40 00 ad cd  call  0xa00a7424
a007bcf4:  92 10 20 07  mov  7, %o1
a007bcf8:  90 10 00 18  mov  %i0, %o0
a007bcfc:  92 15 20 1c  or  %l4, 0x1c, %o1
a007bd00:  94 10 3f f9  mov  -7, %o2
a007bd04:  40 00 ad e1  call  0xa00a7488
a007bd08:  96 10 20 04  mov  4, %o3
a007bd0c:  90 10 00 18  mov  %i0, %o0
a007bd10:  92 14 e0 1c  or  %l3, 0x1c, %o1
a007bd14:  94 10 3f f9  mov  -7, %o2
a007bd18:  40 00 ad dc  call  0xa00a7488
a007bd1c:  96 10 20 04  mov  4, %o3
a007bd20:  90 10 00 18  mov  %i0, %o0
a007bd24:  92 14 a0 1c  or  %l2, 0x1c, %o1
a007bd28:  94 10 3f f9  mov  -7, %o2
a007bd2c:  40 00 ad d7  call  0xa00a7488
a007bd30:  96 10 20 04  mov  4, %o3
a007bd34:  21 3f f3 ff  sethi  %hi(0xffcffc00), %l0
a007bd38:  90 10 00 18  mov  %i0, %o0
a007bd3c:  92 15 20 20  or  %l4, 0x20, %o1
a007bd40:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007bd44:  40 00 ad d1  call  0xa00a7488
a007bd48:  17 00 04 00  sethi  %hi(0x100000), %o3
a007bd4c:  90 10 00 18  mov  %i0, %o0
a007bd50:  92 14 e0 20  or  %l3, 0x20, %o1
a007bd54:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007bd58:  40 00 ad cc  call  0xa00a7488
a007bd5c:  17 00 04 00  sethi  %hi(0x100000), %o3
a007bd60:  90 10 00 18  mov  %i0, %o0
a007bd64:  92 14 a0 20  or  %l2, 0x20, %o1
a007bd68:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007bd6c:  40 00 ad c7  call  0xa00a7488
a007bd70:  17 00 04 00  sethi  %hi(0x100000), %o3
a007bd74:  13 00 00 0d  sethi  %hi(0x3400), %o1
a007bd78:  17 00 00 11  sethi  %hi(0x4400), %o3
a007bd7c:  90 10 00 18  mov  %i0, %o0
a007bd80:  92 12 62 14  or  %o1, 0x214, %o1
a007bd84:  96 12 e0 44  or  %o3, 0x44, %o3
a007bd88:  10 80 01 26  b  0xa007c220
a007bd8c:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a007bd90:  18 80 00 8e  bgu  0xa007bfc8
a007bd94:  80 a0 62 58  cmp  %g1, 0x258
a007bd98:  b0 0e a0 ff  and  %i2, 0xff, %i0
a007bd9c:  7f ff dd e1  call  0xa0073520
a007bda0:  90 10 00 18  mov  %i0, %o0
a007bda4:  80 8a 20 ff  btst  0xff, %o0
a007bda8:  12 80 00 41  bne  0xa007beac
a007bdac:  29 00 00 04  sethi  %hi(0x1000), %l4
a007bdb0:  94 10 00 18  mov  %i0, %o2
a007bdb4:  96 15 20 1c  or  %l4, 0x1c, %o3
a007bdb8:  90 10 20 01  mov  1, %o0
a007bdbc:  40 00 ad 9a  call  0xa00a7424
a007bdc0:  92 10 20 07  mov  7, %o1
a007bdc4:  27 00 00 05  sethi  %hi(0x1400), %l3
a007bdc8:  94 10 00 18  mov  %i0, %o2
a007bdcc:  96 14 e0 1c  or  %l3, 0x1c, %o3
a007bdd0:  90 10 20 01  mov  1, %o0
a007bdd4:  40 00 ad 94  call  0xa00a7424
a007bdd8:  92 10 20 07  mov  7, %o1
a007bddc:  25 00 00 06  sethi  %hi(0x1800), %l2
a007bde0:  94 10 00 18  mov  %i0, %o2
a007bde4:  96 14 a0 1c  or  %l2, 0x1c, %o3
a007bde8:  90 10 20 01  mov  1, %o0
a007bdec:  40 00 ad 8e  call  0xa00a7424
a007bdf0:  92 10 20 07  mov  7, %o1
a007bdf4:  90 10 00 18  mov  %i0, %o0
a007bdf8:  92 15 20 1c  or  %l4, 0x1c, %o1
a007bdfc:  94 10 3f f9  mov  -7, %o2
a007be00:  40 00 ad a2  call  0xa00a7488
a007be04:  96 10 20 06  mov  6, %o3
a007be08:  90 10 00 18  mov  %i0, %o0
a007be0c:  92 14 e0 1c  or  %l3, 0x1c, %o1
a007be10:  94 10 3f f9  mov  -7, %o2
a007be14:  40 00 ad 9d  call  0xa00a7488
a007be18:  96 10 20 06  mov  6, %o3
a007be1c:  90 10 00 18  mov  %i0, %o0
a007be20:  92 14 a0 1c  or  %l2, 0x1c, %o1
a007be24:  94 10 3f f9  mov  -7, %o2
a007be28:  96 10 20 06  mov  6, %o3
a007be2c:  40 00 ad 97  call  0xa00a7488
a007be30:  21 3f c0 00  sethi  %hi(0xff000000), %l0
a007be34:  23 00 00 3f  sethi  %hi(0xfc00), %l1
a007be38:  94 14 20 f0  or  %l0, 0xf0, %o2
a007be3c:  90 10 00 18  mov  %i0, %o0
a007be40:  92 15 21 78  or  %l4, 0x178, %o1
a007be44:  40 00 ad 91  call  0xa00a7488
a007be48:  96 14 63 08  or  %l1, 0x308, %o3
a007be4c:  94 14 20 f0  or  %l0, 0xf0, %o2
a007be50:  90 10 00 18  mov  %i0, %o0
a007be54:  92 14 e1 78  or  %l3, 0x178, %o1
a007be58:  40 00 ad 8c  call  0xa00a7488
a007be5c:  96 14 63 08  or  %l1, 0x308, %o3
a007be60:  94 14 20 f0  or  %l0, 0xf0, %o2
a007be64:  90 10 00 18  mov  %i0, %o0
a007be68:  96 14 63 08  or  %l1, 0x308, %o3
a007be6c:  40 00 ad 87  call  0xa00a7488
a007be70:  92 14 a1 78  or  %l2, 0x178, %o1
a007be74:  21 3f f3 ff  sethi  %hi(0xffcffc00), %l0
a007be78:  90 10 00 18  mov  %i0, %o0
a007be7c:  92 15 20 20  or  %l4, 0x20, %o1
a007be80:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007be84:  40 00 ad 81  call  0xa00a7488
a007be88:  17 00 04 00  sethi  %hi(0x100000), %o3
a007be8c:  90 10 00 18  mov  %i0, %o0
a007be90:  92 14 e0 20  or  %l3, 0x20, %o1
a007be94:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007be98:  40 00 ad 7c  call  0xa00a7488
a007be9c:  17 00 04 00  sethi  %hi(0x100000), %o3
a007bea0:  90 10 00 18  mov  %i0, %o0
a007bea4:  10 80 00 dd  b  0xa007c218
a007bea8:  92 14 a0 20  or  %l2, 0x20, %o1
a007beac:  21 3f c0 00  sethi  %hi(0xff000000), %l0
a007beb0:  23 00 00 3f  sethi  %hi(0xfc00), %l1
a007beb4:  94 14 20 f0  or  %l0, 0xf0, %o2
a007beb8:  90 10 00 18  mov  %i0, %o0
a007bebc:  92 15 21 78  or  %l4, 0x178, %o1
a007bec0:  40 00 ad 72  call  0xa00a7488
a007bec4:  96 14 63 08  or  %l1, 0x308, %o3
a007bec8:  27 00 00 05  sethi  %hi(0x1400), %l3
a007becc:  94 14 20 f0  or  %l0, 0xf0, %o2
a007bed0:  90 10 00 18  mov  %i0, %o0
a007bed4:  92 14 e1 78  or  %l3, 0x178, %o1
a007bed8:  40 00 ad 6c  call  0xa00a7488
a007bedc:  96 14 63 08  or  %l1, 0x308, %o3
a007bee0:  25 00 00 06  sethi  %hi(0x1800), %l2
a007bee4:  94 14 20 f0  or  %l0, 0xf0, %o2
a007bee8:  90 10 00 18  mov  %i0, %o0
a007beec:  96 14 63 08  or  %l1, 0x308, %o3
a007bef0:  40 00 ad 66  call  0xa00a7488
a007bef4:  92 14 a1 78  or  %l2, 0x178, %o1
a007bef8:  94 10 00 18  mov  %i0, %o2
a007befc:  96 15 20 1c  or  %l4, 0x1c, %o3
a007bf00:  90 10 20 01  mov  1, %o0
a007bf04:  40 00 ad 48  call  0xa00a7424
a007bf08:  92 10 20 07  mov  7, %o1
a007bf0c:  94 10 00 18  mov  %i0, %o2
a007bf10:  96 14 e0 1c  or  %l3, 0x1c, %o3
a007bf14:  90 10 20 01  mov  1, %o0
a007bf18:  40 00 ad 43  call  0xa00a7424
a007bf1c:  92 10 20 07  mov  7, %o1
a007bf20:  94 10 00 18  mov  %i0, %o2
a007bf24:  96 14 a0 1c  or  %l2, 0x1c, %o3
a007bf28:  90 10 20 01  mov  1, %o0
a007bf2c:  40 00 ad 3e  call  0xa00a7424
a007bf30:  92 10 20 07  mov  7, %o1
a007bf34:  90 10 00 18  mov  %i0, %o0
a007bf38:  92 15 20 1c  or  %l4, 0x1c, %o1
a007bf3c:  94 10 3f f9  mov  -7, %o2
a007bf40:  40 00 ad 52  call  0xa00a7488
a007bf44:  96 10 20 04  mov  4, %o3
a007bf48:  90 10 00 18  mov  %i0, %o0
a007bf4c:  92 14 e0 1c  or  %l3, 0x1c, %o1
a007bf50:  94 10 3f f9  mov  -7, %o2
a007bf54:  40 00 ad 4d  call  0xa00a7488
a007bf58:  96 10 20 04  mov  4, %o3
a007bf5c:  90 10 00 18  mov  %i0, %o0
a007bf60:  92 14 a0 1c  or  %l2, 0x1c, %o1
a007bf64:  94 10 3f f9  mov  -7, %o2
a007bf68:  40 00 ad 48  call  0xa00a7488
a007bf6c:  96 10 20 04  mov  4, %o3
a007bf70:  21 3f f3 ff  sethi  %hi(0xffcffc00), %l0
a007bf74:  90 10 00 18  mov  %i0, %o0
a007bf78:  92 15 20 20  or  %l4, 0x20, %o1
a007bf7c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007bf80:  40 00 ad 42  call  0xa00a7488
a007bf84:  17 00 04 00  sethi  %hi(0x100000), %o3
a007bf88:  90 10 00 18  mov  %i0, %o0
a007bf8c:  92 14 e0 20  or  %l3, 0x20, %o1
a007bf90:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007bf94:  40 00 ad 3d  call  0xa00a7488
a007bf98:  17 00 04 00  sethi  %hi(0x100000), %o3
a007bf9c:  90 10 00 18  mov  %i0, %o0
a007bfa0:  92 14 a0 20  or  %l2, 0x20, %o1
a007bfa4:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007bfa8:  40 00 ad 38  call  0xa00a7488
a007bfac:  17 00 04 00  sethi  %hi(0x100000), %o3
a007bfb0:  13 00 00 0d  sethi  %hi(0x3400), %o1
a007bfb4:  90 10 00 18  mov  %i0, %o0
a007bfb8:  92 12 62 14  or  %o1, 0x214, %o1
a007bfbc:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a007bfc0:  10 80 00 98  b  0xa007c220
a007bfc4:  96 10 20 60  mov  0x60, %o3
a007bfc8:  18 80 00 99  bgu  0xa007c22c
a007bfcc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007bfd0:  7f ff fc b4  call  0xa007b2a0
a007bfd4:  90 10 00 18  mov  %i0, %o0
a007bfd8:  80 8a 20 ff  btst  0xff, %o0
a007bfdc:  12 80 00 0b  bne  0xa007c008
a007bfe0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007bfe4:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007bfe8:  80 88 60 02  btst  2, %g1
a007bfec:  22 bf ff 6c  be,a   0xa007bd9c
a007bff0:  b0 0e a0 ff  and  %i2, 0xff, %i0
a007bff4:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007bff8:  7f ff dd 33  call  0xa00734c4
a007bffc:  90 12 22 78  or  %o0, 0x278, %o0	! 0xa0067a78
a007c000:  10 bf ff 67  b  0xa007bd9c
a007c004:  b0 0e a0 ff  and  %i2, 0xff, %i0
a007c008:  7f ff dd 46  call  0xa0073520
a007c00c:  90 10 00 18  mov  %i0, %o0
a007c010:  80 8a 20 ff  btst  0xff, %o0
a007c014:  12 80 00 44  bne  0xa007c124
a007c018:  27 00 00 04  sethi  %hi(0x1000), %l3
a007c01c:  29 00 00 04  sethi  %hi(0x1000), %l4
a007c020:  94 10 00 18  mov  %i0, %o2
a007c024:  96 15 20 1c  or  %l4, 0x1c, %o3
a007c028:  90 10 20 01  mov  1, %o0
a007c02c:  40 00 ac fe  call  0xa00a7424
a007c030:  92 10 20 07  mov  7, %o1
a007c034:  27 00 00 05  sethi  %hi(0x1400), %l3
a007c038:  94 10 00 18  mov  %i0, %o2
a007c03c:  96 14 e0 1c  or  %l3, 0x1c, %o3
a007c040:  90 10 20 01  mov  1, %o0
a007c044:  40 00 ac f8  call  0xa00a7424
a007c048:  92 10 20 07  mov  7, %o1
a007c04c:  25 00 00 06  sethi  %hi(0x1800), %l2
a007c050:  94 10 00 18  mov  %i0, %o2
a007c054:  96 14 a0 1c  or  %l2, 0x1c, %o3
a007c058:  90 10 20 01  mov  1, %o0
a007c05c:  40 00 ac f2  call  0xa00a7424
a007c060:  92 10 20 07  mov  7, %o1
a007c064:  90 10 00 18  mov  %i0, %o0
a007c068:  92 15 20 1c  or  %l4, 0x1c, %o1
a007c06c:  94 10 3f f9  mov  -7, %o2
a007c070:  40 00 ad 06  call  0xa00a7488
a007c074:  96 10 20 06  mov  6, %o3
a007c078:  90 10 00 18  mov  %i0, %o0
a007c07c:  92 14 e0 1c  or  %l3, 0x1c, %o1
a007c080:  94 10 3f f9  mov  -7, %o2
a007c084:  40 00 ad 01  call  0xa00a7488
a007c088:  96 10 20 06  mov  6, %o3
a007c08c:  90 10 00 18  mov  %i0, %o0
a007c090:  92 14 a0 1c  or  %l2, 0x1c, %o1
a007c094:  94 10 3f f9  mov  -7, %o2
a007c098:  40 00 ac fc  call  0xa00a7488
a007c09c:  96 10 20 06  mov  6, %o3
a007c0a0:  21 3f c0 00  sethi  %hi(0xff000000), %l0
a007c0a4:  23 00 03 ff  sethi  %hi(0xffc00), %l1
a007c0a8:  94 14 20 f0  or  %l0, 0xf0, %o2
a007c0ac:  90 10 00 18  mov  %i0, %o0
a007c0b0:  92 15 21 78  or  %l4, 0x178, %o1
a007c0b4:  40 00 ac f5  call  0xa00a7488
a007c0b8:  96 14 63 08  or  %l1, 0x308, %o3
a007c0bc:  94 14 20 f0  or  %l0, 0xf0, %o2
a007c0c0:  90 10 00 18  mov  %i0, %o0
a007c0c4:  92 14 e1 78  or  %l3, 0x178, %o1
a007c0c8:  40 00 ac f0  call  0xa00a7488
a007c0cc:  96 14 63 08  or  %l1, 0x308, %o3
a007c0d0:  94 14 20 f0  or  %l0, 0xf0, %o2
a007c0d4:  90 10 00 18  mov  %i0, %o0
a007c0d8:  96 14 63 08  or  %l1, 0x308, %o3
a007c0dc:  40 00 ac eb  call  0xa00a7488
a007c0e0:  92 14 a1 78  or  %l2, 0x178, %o1
a007c0e4:  21 3f f3 ff  sethi  %hi(0xffcffc00), %l0
a007c0e8:  90 10 00 18  mov  %i0, %o0
a007c0ec:  92 15 20 20  or  %l4, 0x20, %o1
a007c0f0:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c0f4:  40 00 ac e5  call  0xa00a7488
a007c0f8:  17 00 0c 00  sethi  %hi(0x300000), %o3
a007c0fc:  90 10 00 18  mov  %i0, %o0
a007c100:  92 14 e0 20  or  %l3, 0x20, %o1
a007c104:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c108:  40 00 ac e0  call  0xa00a7488
a007c10c:  17 00 0c 00  sethi  %hi(0x300000), %o3
a007c110:  90 10 00 18  mov  %i0, %o0
a007c114:  92 14 a0 20  or  %l2, 0x20, %o1
a007c118:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c11c:  10 80 00 41  b  0xa007c220
a007c120:  17 00 0c 00  sethi  %hi(0x300000), %o3
a007c124:  21 3f c0 00  sethi  %hi(0xff000000), %l0
a007c128:  94 14 20 f0  or  %l0, 0xf0, %o2	! 0xff0000f0
a007c12c:  90 10 00 18  mov  %i0, %o0
a007c130:  92 14 e1 78  or  %l3, 0x178, %o1
a007c134:  40 00 ac d5  call  0xa00a7488
a007c138:  96 10 23 03  mov  0x303, %o3
a007c13c:  25 00 00 05  sethi  %hi(0x1400), %l2
a007c140:  94 14 20 f0  or  %l0, 0xf0, %o2
a007c144:  90 10 00 18  mov  %i0, %o0
a007c148:  92 14 a1 78  or  %l2, 0x178, %o1
a007c14c:  40 00 ac cf  call  0xa00a7488
a007c150:  96 10 23 03  mov  0x303, %o3
a007c154:  23 00 00 06  sethi  %hi(0x1800), %l1
a007c158:  94 14 20 f0  or  %l0, 0xf0, %o2
a007c15c:  90 10 00 18  mov  %i0, %o0
a007c160:  92 14 61 78  or  %l1, 0x178, %o1
a007c164:  40 00 ac c9  call  0xa00a7488
a007c168:  96 10 23 03  mov  0x303, %o3
a007c16c:  94 10 00 18  mov  %i0, %o2
a007c170:  96 14 e0 1c  or  %l3, 0x1c, %o3
a007c174:  90 10 20 01  mov  1, %o0
a007c178:  40 00 ac ab  call  0xa00a7424
a007c17c:  92 10 20 07  mov  7, %o1
a007c180:  94 10 00 18  mov  %i0, %o2
a007c184:  96 14 a0 1c  or  %l2, 0x1c, %o3
a007c188:  90 10 20 01  mov  1, %o0
a007c18c:  40 00 ac a6  call  0xa00a7424
a007c190:  92 10 20 07  mov  7, %o1
a007c194:  94 10 00 18  mov  %i0, %o2
a007c198:  96 14 60 1c  or  %l1, 0x1c, %o3
a007c19c:  90 10 20 01  mov  1, %o0
a007c1a0:  40 00 ac a1  call  0xa00a7424
a007c1a4:  92 10 20 07  mov  7, %o1
a007c1a8:  90 10 00 18  mov  %i0, %o0
a007c1ac:  92 14 e0 1c  or  %l3, 0x1c, %o1
a007c1b0:  94 10 3f f9  mov  -7, %o2
a007c1b4:  40 00 ac b5  call  0xa00a7488
a007c1b8:  96 10 20 04  mov  4, %o3
a007c1bc:  90 10 00 18  mov  %i0, %o0
a007c1c0:  92 14 a0 1c  or  %l2, 0x1c, %o1
a007c1c4:  94 10 3f f9  mov  -7, %o2
a007c1c8:  40 00 ac b0  call  0xa00a7488
a007c1cc:  96 10 20 04  mov  4, %o3
a007c1d0:  90 10 00 18  mov  %i0, %o0
a007c1d4:  92 14 60 1c  or  %l1, 0x1c, %o1
a007c1d8:  94 10 3f f9  mov  -7, %o2
a007c1dc:  40 00 ac ab  call  0xa00a7488
a007c1e0:  96 10 20 04  mov  4, %o3
a007c1e4:  21 3f f3 ff  sethi  %hi(0xffcffc00), %l0
a007c1e8:  90 10 00 18  mov  %i0, %o0
a007c1ec:  92 14 e0 20  or  %l3, 0x20, %o1
a007c1f0:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c1f4:  40 00 ac a5  call  0xa00a7488
a007c1f8:  17 00 04 00  sethi  %hi(0x100000), %o3
a007c1fc:  90 10 00 18  mov  %i0, %o0
a007c200:  92 14 a0 20  or  %l2, 0x20, %o1
a007c204:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c208:  40 00 ac a0  call  0xa00a7488
a007c20c:  17 00 04 00  sethi  %hi(0x100000), %o3
a007c210:  90 10 00 18  mov  %i0, %o0
a007c214:  92 14 60 20  or  %l1, 0x20, %o1
a007c218:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c21c:  17 00 04 00  sethi  %hi(0x100000), %o3
a007c220:  40 00 ac 9a  call  0xa00a7488
a007c224:  a8 0e a0 ff  and  %i2, 0xff, %l4
a007c228:  30 80 00 09  b,a   0xa007c24c
a007c22c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1
a007c230:  80 88 60 02  btst  2, %g1
a007c234:  02 80 00 06  be  0xa007c24c
a007c238:  a8 0e a0 ff  and  %i2, 0xff, %l4
a007c23c:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007c240:  7f ff dc a1  call  0xa00734c4
a007c244:  90 12 22 98  or  %o0, 0x298, %o0	! 0xa0067a98
a007c248:  a8 0e a0 ff  and  %i2, 0xff, %l4
a007c24c:  7f ff dc b5  call  0xa0073520
a007c250:  90 10 00 14  mov  %l4, %o0
a007c254:  aa 0a 20 ff  and  %o0, 0xff, %l5
a007c258:  80 a5 60 00  cmp  %l5, 0
a007c25c:  02 80 00 63  be  0xa007c3e8
a007c260:  25 00 00 04  sethi  %hi(0x1000), %l2
a007c264:  21 00 00 0d  sethi  %hi(0x3400), %l0
a007c268:  92 14 22 14  or  %l0, 0x214, %o1	! 0x3614
a007c26c:  90 10 00 14  mov  %l4, %o0
a007c270:  94 10 3f 00  mov  -256, %o2
a007c274:  96 10 20 00  clr  %o3
a007c278:  40 00 ac 84  call  0xa00a7488
a007c27c:  23 3f ff c0  sethi  %hi(0xffff0000), %l1
a007c280:  92 14 22 14  or  %l0, 0x214, %o1
a007c284:  90 10 00 14  mov  %l4, %o0
a007c288:  94 14 60 ff  or  %l1, 0xff, %o2
a007c28c:  40 00 ac 7f  call  0xa00a7488
a007c290:  96 10 20 00  clr  %o3
a007c294:  27 00 00 20  sethi  %hi(0x8000), %l3
a007c298:  92 14 22 0c  or  %l0, 0x20c, %o1
a007c29c:  90 10 00 14  mov  %l4, %o0
a007c2a0:  94 10 00 11  mov  %l1, %o2
a007c2a4:  40 00 ac 79  call  0xa00a7488
a007c2a8:  96 14 e3 d0  or  %l3, 0x3d0, %o3
a007c2ac:  25 00 00 3f  sethi  %hi(0xfc00), %l2
a007c2b0:  92 14 22 0c  or  %l0, 0x20c, %o1
a007c2b4:  94 14 a3 ff  or  %l2, 0x3ff, %o2
a007c2b8:  90 10 00 14  mov  %l4, %o0
a007c2bc:  40 00 ac 73  call  0xa00a7488
a007c2c0:  17 20 f4 00  sethi  %hi(0x83d00000), %o3
a007c2c4:  92 14 22 10  or  %l0, 0x210, %o1
a007c2c8:  90 10 00 14  mov  %l4, %o0
a007c2cc:  96 14 e3 d0  or  %l3, 0x3d0, %o3
a007c2d0:  40 00 ac 6e  call  0xa00a7488
a007c2d4:  94 10 00 11  mov  %l1, %o2
a007c2d8:  94 14 a3 ff  or  %l2, 0x3ff, %o2
a007c2dc:  92 14 22 10  or  %l0, 0x210, %o1
a007c2e0:  90 10 00 14  mov  %l4, %o0
a007c2e4:  40 00 ac 69  call  0xa00a7488
a007c2e8:  17 20 f4 00  sethi  %hi(0x83d00000), %o3
a007c2ec:  15 3f c0 3f  sethi  %hi(0xff00fc00), %o2
a007c2f0:  92 14 22 14  or  %l0, 0x214, %o1
a007c2f4:  90 10 00 14  mov  %l4, %o0
a007c2f8:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007c2fc:  40 00 ac 63  call  0xa00a7488
a007c300:  17 00 1f 00  sethi  %hi(0x7c0000), %o3
a007c304:  25 00 3f ff  sethi  %hi(0xfffc00), %l2
a007c308:  92 14 22 14  or  %l0, 0x214, %o1
a007c30c:  90 10 00 14  mov  %l4, %o0
a007c310:  94 14 a3 ff  or  %l2, 0x3ff, %o2
a007c314:  40 00 ac 5d  call  0xa00a7488
a007c318:  17 3f c0 00  sethi  %hi(0xff000000), %o3
a007c31c:  92 14 22 18  or  %l0, 0x218, %o1
a007c320:  90 10 00 14  mov  %l4, %o0
a007c324:  94 10 3f 00  mov  -256, %o2
a007c328:  40 00 ac 58  call  0xa00a7488
a007c32c:  96 10 20 ff  mov  0xff, %o3
a007c330:  92 14 22 20  or  %l0, 0x220, %o1
a007c334:  90 10 00 14  mov  %l4, %o0
a007c338:  94 10 3f 00  mov  -256, %o2
a007c33c:  40 00 ac 53  call  0xa00a7488
a007c340:  96 10 20 00  clr  %o3
a007c344:  92 14 22 20  or  %l0, 0x220, %o1
a007c348:  90 10 00 14  mov  %l4, %o0
a007c34c:  94 14 60 ff  or  %l1, 0xff, %o2
a007c350:  40 00 ac 4e  call  0xa00a7488
a007c354:  96 10 21 00  mov  0x100, %o3
a007c358:  96 14 22 04  or  %l0, 0x204, %o3
a007c35c:  90 10 20 00  clr  %o0
a007c360:  92 10 20 1b  mov  0x1b, %o1
a007c364:  40 00 ac 30  call  0xa00a7424
a007c368:  94 10 00 14  mov  %l4, %o2
a007c36c:  21 00 00 04  sethi  %hi(0x1000), %l0
a007c370:  90 10 00 14  mov  %l4, %o0
a007c374:  94 14 a3 ff  or  %l2, 0x3ff, %o2
a007c378:  92 14 20 20  or  %l0, 0x20, %o1
a007c37c:  40 00 ac 43  call  0xa00a7488
a007c380:  17 28 80 00  sethi  %hi(0xa2000000), %o3
a007c384:  13 00 00 08  sethi  %hi(0x2000), %o1
a007c388:  90 10 00 14  mov  %l4, %o0
a007c38c:  92 12 63 c0  or  %o1, 0x3c0, %o1
a007c390:  94 14 60 ff  or  %l1, 0xff, %o2
a007c394:  40 00 ac 3d  call  0xa00a7488
a007c398:  17 00 00 14  sethi  %hi(0x5000), %o3
a007c39c:  13 00 00 09  sethi  %hi(0x2400), %o1
a007c3a0:  90 10 00 14  mov  %l4, %o0
a007c3a4:  92 12 63 c0  or  %o1, 0x3c0, %o1
a007c3a8:  94 14 60 ff  or  %l1, 0xff, %o2
a007c3ac:  40 00 ac 37  call  0xa00a7488
a007c3b0:  96 10 00 10  mov  %l0, %o3
a007c3b4:  13 00 00 0a  sethi  %hi(0x2800), %o1
a007c3b8:  90 10 00 14  mov  %l4, %o0
a007c3bc:  92 12 63 c0  or  %o1, 0x3c0, %o1
a007c3c0:  94 14 60 ff  or  %l1, 0xff, %o2
a007c3c4:  40 00 ac 31  call  0xa00a7488
a007c3c8:  96 10 00 10  mov  %l0, %o3
a007c3cc:  13 00 00 0c  sethi  %hi(0x3000), %o1
a007c3d0:  90 10 00 14  mov  %l4, %o0
a007c3d4:  92 12 63 c0  or  %o1, 0x3c0, %o1
a007c3d8:  94 14 60 ff  or  %l1, 0xff, %o2
a007c3dc:  40 00 ac 2b  call  0xa00a7488
a007c3e0:  96 10 00 10  mov  %l0, %o3
a007c3e4:  25 00 00 04  sethi  %hi(0x1000), %l2
a007c3e8:  90 10 20 01  mov  1, %o0
a007c3ec:  92 10 20 10  mov  0x10, %o1
a007c3f0:  94 10 00 14  mov  %l4, %o2
a007c3f4:  40 00 ac 0c  call  0xa00a7424
a007c3f8:  96 14 a0 04  or  %l2, 4, %o3
a007c3fc:  23 00 00 05  sethi  %hi(0x1400), %l1
a007c400:  90 10 20 01  mov  1, %o0
a007c404:  92 10 20 10  mov  0x10, %o1
a007c408:  94 10 00 14  mov  %l4, %o2
a007c40c:  40 00 ac 06  call  0xa00a7424
a007c410:  96 14 60 04  or  %l1, 4, %o3
a007c414:  21 00 00 06  sethi  %hi(0x1800), %l0
a007c418:  90 10 20 01  mov  1, %o0
a007c41c:  92 10 20 10  mov  0x10, %o1
a007c420:  94 10 00 14  mov  %l4, %o2
a007c424:  40 00 ac 00  call  0xa00a7424
a007c428:  96 14 20 04  or  %l0, 4, %o3
a007c42c:  7f ff e3 93  call  0xa0075278
a007c430:  90 10 00 14  mov  %l4, %o0
a007c434:  80 a5 60 00  cmp  %l5, 0
a007c438:  02 80 00 04  be  0xa007c448
a007c43c:  01 00 00 00  nop
a007c440:  7f ff e3 c8  call  0xa0075360
a007c444:  90 10 00 14  mov  %l4, %o0
a007c448:  40 00 d4 d3  call  0xa00b1794
a007c44c:  90 10 20 0a  mov  0xa, %o0
a007c450:  96 14 21 00  or  %l0, 0x100, %o3
a007c454:  90 10 20 00  clr  %o0
a007c458:  92 10 20 15  mov  0x15, %o1
a007c45c:  40 00 ab f2  call  0xa00a7424
a007c460:  94 10 00 14  mov  %l4, %o2
a007c464:  96 14 61 00  or  %l1, 0x100, %o3
a007c468:  90 10 20 00  clr  %o0
a007c46c:  92 10 20 15  mov  0x15, %o1
a007c470:  40 00 ab ed  call  0xa00a7424
a007c474:  94 10 00 14  mov  %l4, %o2
a007c478:  96 14 a1 00  or  %l2, 0x100, %o3
a007c47c:  90 10 20 00  clr  %o0
a007c480:  92 10 20 15  mov  0x15, %o1
a007c484:  40 00 ab e8  call  0xa00a7424
a007c488:  94 10 00 14  mov  %l4, %o2
a007c48c:  7f ff e2 6b  call  0xa0074e38
a007c490:  90 10 00 14  mov  %l4, %o0
a007c494:  82 05 00 14  add  %l4, %l4, %g1
a007c498:  82 00 40 14  add  %g1, %l4, %g1
a007c49c:  91 28 60 02  sll  %g1, 2, %o0
a007c4a0:  19 2a 01 f3  sethi  %hi(0xa807cc00), %o4
a007c4a4:  9a 13 20 c4  or  %o4, 0xc4, %o5	! 0xa807ccc4
a007c4a8:  82 10 20 0a  mov  0xa, %g1
a007c4ac:  c2 23 40 08  st  %g1, [ %o5 + %o0 ]
a007c4b0:  81 c7 e0 08  ret
a007c4b4:  91 e8 20 00  restore  %g0, 0, %o0
