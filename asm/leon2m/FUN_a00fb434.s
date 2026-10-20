# leon2m FUN_a00fb434 0xa00fb434-0xa00fb9ec (1088 bytes)
a00fb434:  9d e3 bf 98  save  %sp, -104, %sp
a00fb438:  9a 10 00 1a  mov  %i2, %o5
a00fb43c:  98 10 00 1b  mov  %i3, %o4
a00fb440:  80 a6 20 11  cmp  %i0, 0x11
a00fb444:  9e 10 20 00  clr  %o7
a00fb448:  18 80 00 11  bgu  0xa00fb48c
a00fb44c:  f4 06 40 00  ld  [ %i1 ], %i2
a00fb450:  83 2e 20 02  sll  %i0, 2, %g1
a00fb454:  31 00 02 66  sethi  %hi(0x99800), %i0
a00fb458:  ba 16 21 40  or  %i0, 0x140, %i5	! 0x99940
a00fb45c:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a00fb460:  81 c7 00 00  jmp  %i4
a00fb464:  01 00 00 00  nop
a00fb468:  3b 34 01 00  sethi  %hi(0xd0040000), %i5
a00fb46c:  b8 17 60 98  or  %i5, 0x98, %i4	! 0xd0040098
a00fb470:  f6 07 00 00  ld  [ %i4 ], %i3
a00fb474:  03 00 03 c0  sethi  %hi(0xf0000), %g1
a00fb478:  bb 2e a0 10  sll  %i2, 0x10, %i5
a00fb47c:  ba 0f 40 01  and  %i5, %g1, %i5
a00fb480:  b0 2e c0 01  andn  %i3, %g1, %i0
a00fb484:  b6 16 00 1d  or  %i0, %i5, %i3
a00fb488:  f6 27 00 00  st  %i3, [ %i4 ]
a00fb48c:  82 0b e0 ff  and  %o7, 0xff, %g1
a00fb490:  80 a0 60 01  cmp  %g1, 1
a00fb494:  02 80 00 0a  be  0xa00fb4bc
a00fb498:  80 a0 60 02  cmp  %g1, 2
a00fb49c:  02 80 00 0e  be  0xa00fb4d4
a00fb4a0:  80 a0 60 03  cmp  %g1, 3
a00fb4a4:  02 80 00 11  be  0xa00fb4e8
a00fb4a8:  80 a0 60 04  cmp  %g1, 4
a00fb4ac:  12 80 01 4e  bne  0xa00fb9e4
a00fb4b0:  01 00 00 00  nop
a00fb4b4:  10 80 00 8d  b  0xa00fb6e8
a00fb4b8:  b1 2b 60 10  sll  %o5, 0x10, %i0
a00fb4bc:  37 2a 00 ad  sethi  %hi(0xa802b400), %i3
a00fb4c0:  f8 0e e3 fd  ldub  [ %i3 + 0x3fd ], %i4	! 0xa802b7fd
a00fb4c4:  03 34 01 00  sethi  %hi(0xd0040000), %g1
a00fb4c8:  f4 07 00 01  ld  [ %i4 + %g1 ], %i2
a00fb4cc:  10 80 01 46  b  0xa00fb9e4
a00fb4d0:  f4 26 40 00  st  %i2, [ %i1 ]
a00fb4d4:  3b 2a 00 ad  sethi  %hi(0xa802b400), %i5
a00fb4d8:  f0 0f 63 fd  ldub  [ %i5 + 0x3fd ], %i0	! 0xa802b7fd
a00fb4dc:  33 34 01 00  sethi  %hi(0xd0040000), %i1
a00fb4e0:  f4 26 00 19  st  %i2, [ %i0 + %i1 ]
a00fb4e4:  30 80 01 40  b,a   0xa00fb9e4
a00fb4e8:  03 01 e0 09  sethi  %hi(0x7802400), %g1
a00fb4ec:  31 34 01 00  sethi  %hi(0xd0040000), %i0
a00fb4f0:  b6 10 60 38  or  %g1, 0x38, %i3
a00fb4f4:  3b 01 40 5a  sethi  %hi(0x5016800), %i5
a00fb4f8:  f6 26 00 00  st  %i3, [ %i0 ]
a00fb4fc:  b4 17 61 8c  or  %i5, 0x18c, %i2
a00fb500:  b2 16 20 04  or  %i0, 4, %i1
a00fb504:  f4 26 40 00  st  %i2, [ %i1 ]
a00fb508:  ba 16 20 08  or  %i0, 8, %i5
a00fb50c:  33 20 00 00  sethi  %hi(0x80000000), %i1
a00fb510:  f2 27 40 00  st  %i1, [ %i5 ]
a00fb514:  f8 07 40 00  ld  [ %i5 ], %i4
a00fb518:  82 0f 3f fc  and  %i4, -4, %g1
a00fb51c:  b6 10 60 02  or  %g1, 2, %i3
a00fb520:  f6 27 40 00  st  %i3, [ %i5 ]
a00fb524:  b6 16 22 08  or  %i0, 0x208, %i3
a00fb528:  f4 06 c0 00  ld  [ %i3 ], %i2
a00fb52c:  b8 0e bf fc  and  %i2, -4, %i4
a00fb530:  82 17 20 01  or  %i4, 1, %g1
a00fb534:  c2 26 c0 00  st  %g1, [ %i3 ]
a00fb538:  ba 16 20 0c  or  %i0, 0xc, %i5
a00fb53c:  35 30 a0 00  sethi  %hi(0xc2800000), %i2
a00fb540:  c0 27 40 00  clr  [ %i5 ]
a00fb544:  b8 16 a1 00  or  %i2, 0x100, %i4
a00fb548:  b6 16 20 20  or  %i0, 0x20, %i3
a00fb54c:  f8 26 c0 00  st  %i4, [ %i3 ]
a00fb550:  82 16 20 24  or  %i0, 0x24, %g1
a00fb554:  3b 00 80 00  sethi  %hi(0x2000000), %i5
a00fb558:  c0 20 40 00  clr  [ %g1 ]
a00fb55c:  b4 17 62 00  or  %i5, 0x200, %i2
a00fb560:  b8 16 20 28  or  %i0, 0x28, %i4
a00fb564:  37 00 00 40  sethi  %hi(0x10000), %i3
a00fb568:  f4 27 00 00  st  %i2, [ %i4 ]
a00fb56c:  82 16 e2 00  or  %i3, 0x200, %g1
a00fb570:  ba 16 20 2c  or  %i0, 0x2c, %i5
a00fb574:  c2 27 40 00  st  %g1, [ %i5 ]
a00fb578:  35 0b ff c1  sethi  %hi(0x2fff0400), %i2
a00fb57c:  b8 16 a0 b0  or  %i2, 0xb0, %i4	! 0x2fff04b0
a00fb580:  b6 16 20 30  or  %i0, 0x30, %i3
a00fb584:  3b 00 20 23  sethi  %hi(0x808c00), %i5
a00fb588:  f8 26 c0 00  st  %i4, [ %i3 ]
a00fb58c:  82 17 61 63  or  %i5, 0x163, %g1
a00fb590:  b4 16 20 34  or  %i0, 0x34, %i2
a00fb594:  c2 26 80 00  st  %g1, [ %i2 ]
a00fb598:  b8 16 20 c0  or  %i0, 0xc0, %i4
a00fb59c:  f2 27 00 00  st  %i1, [ %i4 ]
a00fb5a0:  ba 16 20 c4  or  %i0, 0xc4, %i5
a00fb5a4:  37 0b 09 80  sethi  %hi(0x2c260000), %i3
a00fb5a8:  35 20 04 4a  sethi  %hi(0x80112800), %i2
a00fb5ac:  f6 27 40 00  st  %i3, [ %i5 ]
a00fb5b0:  82 16 a0 30  or  %i2, 0x30, %g1
a00fb5b4:  b2 16 20 80  or  %i0, 0x80, %i1
a00fb5b8:  39 02 04 08  sethi  %hi(0x8102000), %i4
a00fb5bc:  c2 26 40 00  st  %g1, [ %i1 ]
a00fb5c0:  b6 17 20 80  or  %i4, 0x80, %i3
a00fb5c4:  ba 16 20 90  or  %i0, 0x90, %i5
a00fb5c8:  35 3c 04 04  sethi  %hi(0xf0101000), %i2
a00fb5cc:  f6 27 40 00  st  %i3, [ %i5 ]
a00fb5d0:  82 16 a0 10  or  %i2, 0x10, %g1
a00fb5d4:  b2 16 20 98  or  %i0, 0x98, %i1
a00fb5d8:  39 10 01 c5  sethi  %hi(0x40071400), %i4
a00fb5dc:  c2 26 40 00  st  %g1, [ %i1 ]
a00fb5e0:  b6 17 23 e0  or  %i4, 0x3e0, %i3
a00fb5e4:  ba 16 20 94  or  %i0, 0x94, %i5
a00fb5e8:  f6 27 40 00  st  %i3, [ %i5 ]
a00fb5ec:  b2 16 20 9c  or  %i0, 0x9c, %i1
a00fb5f0:  35 14 14 18  sethi  %hi(0x50506000), %i2
a00fb5f4:  03 1c f0 00  sethi  %hi(0x73c00000), %g1
a00fb5f8:  f4 26 40 00  st  %i2, [ %i1 ]
a00fb5fc:  b8 10 63 80  or  %g1, 0x380, %i4
a00fb600:  b6 16 20 ac  or  %i0, 0xac, %i3
a00fb604:  3b 00 fc 00  sethi  %hi(0x3f00000), %i5
a00fb608:  f8 26 c0 00  st  %i4, [ %i3 ]
a00fb60c:  b4 17 60 04  or  %i5, 4, %i2
a00fb610:  b2 16 20 d4  or  %i0, 0xd4, %i1
a00fb614:  03 00 44 40  sethi  %hi(0x1110000), %g1
a00fb618:  f4 26 40 00  st  %i2, [ %i1 ]
a00fb61c:  b8 10 61 13  or  %g1, 0x113, %i4
a00fb620:  b6 16 20 d8  or  %i0, 0xd8, %i3
a00fb624:  3b 12 cc 86  sethi  %hi(0x4b321800), %i5
a00fb628:  f8 26 c0 00  st  %i4, [ %i3 ]
a00fb62c:  b4 17 61 00  or  %i5, 0x100, %i2
a00fb630:  b2 16 20 e0  or  %i0, 0xe0, %i1
a00fb634:  03 20 20 20  sethi  %hi(0x80808000), %g1
a00fb638:  f4 26 40 00  st  %i2, [ %i1 ]
a00fb63c:  b8 10 60 64  or  %g1, 0x64, %i4
a00fb640:  b6 16 20 e4  or  %i0, 0xe4, %i3
a00fb644:  3b 3f c0 40  sethi  %hi(0xff010000), %i5
a00fb648:  f8 26 c0 00  st  %i4, [ %i3 ]
a00fb64c:  b4 17 60 64  or  %i5, 0x64, %i2
a00fb650:  b2 16 20 e8  or  %i0, 0xe8, %i1
a00fb654:  f4 26 40 00  st  %i2, [ %i1 ]
a00fb658:  b8 16 20 f0  or  %i0, 0xf0, %i4
a00fb65c:  82 10 30 f0  mov  -3856, %g1
a00fb660:  c2 27 00 00  st  %g1, [ %i4 ]
a00fb664:  ba 16 20 f4  or  %i0, 0xf4, %i5
a00fb668:  37 08 00 00  sethi  %hi(0x20000000), %i3
a00fb66c:  f6 27 40 00  st  %i3, [ %i5 ]
a00fb670:  b5 2b 60 10  sll  %o5, 0x10, %i2
a00fb674:  33 00 30 3f  sethi  %hi(0xc0fc00), %i1
a00fb678:  bb 36 a0 10  srl  %i2, 0x10, %i5
a00fb67c:  37 2a 00 b5  sethi  %hi(0xa802d400), %i3
a00fb680:  82 16 62 c0  or  %i1, 0x2c0, %g1
a00fb684:  b8 16 20 f8  or  %i0, 0xf8, %i4
a00fb688:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a00fb68c:  c2 27 00 00  st  %g1, [ %i4 ]
a00fb690:  da 36 e2 7a  sth  %o5, [ %i3 + 0x27a ]
a00fb694:  d8 36 a2 78  sth  %o4, [ %i2 + 0x278 ]
a00fb698:  b6 16 e2 7a  or  %i3, 0x27a, %i3
a00fb69c:  80 a7 62 cf  cmp  %i5, 0x2cf
a00fb6a0:  08 80 00 06  bleu  0xa00fb6b8
a00fb6a4:  82 10 22 d0  mov  0x2d0, %g1
a00fb6a8:  39 00 00 05  sethi  %hi(0x1400), %i4
a00fb6ac:  80 a7 40 1c  cmp  %i5, %i4
a00fb6b0:  18 80 00 74  bgu  0xa00fb880
a00fb6b4:  82 10 00 0d  mov  %o5, %g1
a00fb6b8:  c2 36 c0 00  sth  %g1, [ %i3 ]
a00fb6bc:  fa 16 a2 78  lduh  [ %i2 + 0x278 ], %i5
a00fb6c0:  80 a7 61 df  cmp  %i5, 0x1df
a00fb6c4:  b6 16 a2 78  or  %i2, 0x278, %i3
a00fb6c8:  08 80 00 06  bleu  0xa00fb6e0
a00fb6cc:  82 10 21 e0  mov  0x1e0, %g1
a00fb6d0:  80 a7 6b 40  cmp  %i5, 0xb40
a00fb6d4:  08 80 00 03  bleu  0xa00fb6e0
a00fb6d8:  82 10 00 1d  mov  %i5, %g1
a00fb6dc:  82 10 2b 40  mov  0xb40, %g1
a00fb6e0:  10 80 00 c1  b  0xa00fb9e4
a00fb6e4:  c2 36 c0 00  sth  %g1, [ %i3 ]
a00fb6e8:  33 2a 00 b5  sethi  %hi(0xa802d400), %i1
a00fb6ec:  83 36 20 10  srl  %i0, 0x10, %g1
a00fb6f0:  37 2a 00 b5  sethi  %hi(0xa802d400), %i3
a00fb6f4:  d8 36 e2 78  sth  %o4, [ %i3 + 0x278 ]	! 0xa802d678
a00fb6f8:  da 36 62 7a  sth  %o5, [ %i1 + 0x27a ]
a00fb6fc:  80 a0 62 cf  cmp  %g1, 0x2cf
a00fb700:  b4 16 62 7a  or  %i1, 0x27a, %i2
a00fb704:  08 80 00 06  bleu  0xa00fb71c
a00fb708:  ba 10 22 d0  mov  0x2d0, %i5
a00fb70c:  39 00 00 05  sethi  %hi(0x1400), %i4
a00fb710:  80 a0 40 1c  cmp  %g1, %i4
a00fb714:  18 80 00 b2  bgu  0xa00fb9dc
a00fb718:  ba 10 00 0d  mov  %o5, %i5
a00fb71c:  f8 16 e2 78  lduh  [ %i3 + 0x278 ], %i4
a00fb720:  fa 36 80 00  sth  %i5, [ %i2 ]
a00fb724:  80 a7 21 df  cmp  %i4, 0x1df
a00fb728:  b4 16 e2 78  or  %i3, 0x278, %i2
a00fb72c:  08 80 00 06  bleu  0xa00fb744
a00fb730:  82 10 21 e0  mov  0x1e0, %g1
a00fb734:  80 a7 2b 40  cmp  %i4, 0xb40
a00fb738:  08 80 00 03  bleu  0xa00fb744
a00fb73c:  82 10 00 1c  mov  %i4, %g1
a00fb740:  82 10 2b 40  mov  0xb40, %g1
a00fb744:  c2 36 80 00  sth  %g1, [ %i2 ]
a00fb748:  f0 16 e2 78  lduh  [ %i3 + 0x278 ], %i0
a00fb74c:  1b 34 01 00  sethi  %hi(0xd0040000), %o5
a00fb750:  3b 2a aa aa  sethi  %hi(0xaaaaa800), %i5
a00fb754:  f6 03 40 00  ld  [ %o5 ], %i3
a00fb758:  b8 17 62 ab  or  %i5, 0x2ab, %i4
a00fb75c:  03 3f ff f8  sethi  %hi(0xffffe000), %g1
a00fb760:  ba 2e 00 01  andn  %i0, %g1, %i5
a00fb764:  80 56 00 1c  umul  %i0, %i4, %g0
a00fb768:  b5 40 00 00  rd  %y, %i2
a00fb76c:  b6 0e c0 01  and  %i3, %g1, %i3
a00fb770:  de 16 62 7a  lduh  [ %i1 + 0x27a ], %o7
a00fb774:  b5 36 a0 03  srl  %i2, 3, %i2
a00fb778:  b6 16 c0 1d  or  %i3, %i5, %i3
a00fb77c:  b2 06 80 1a  add  %i2, %i2, %i1
a00fb780:  3b 07 ff c0  sethi  %hi(0x1fff0000), %i5
a00fb784:  83 2b e0 10  sll  %o7, 0x10, %g1
a00fb788:  82 08 40 1d  and  %g1, %i5, %g1
a00fb78c:  80 53 c0 1c  umul  %o7, %i4, %g0
a00fb790:  b9 40 00 00  rd  %y, %i4
a00fb794:  b2 06 40 1a  add  %i1, %i2, %i1
a00fb798:  b9 37 20 04  srl  %i4, 4, %i4
a00fb79c:  ba 2e c0 1d  andn  %i3, %i5, %i5
a00fb7a0:  b3 2e 60 02  sll  %i1, 2, %i1
a00fb7a4:  b6 07 00 1c  add  %i4, %i4, %i3
a00fb7a8:  ba 17 40 01  or  %i5, %g1, %i5
a00fb7ac:  b0 26 00 19  sub  %i0, %i1, %i0
a00fb7b0:  fa 23 40 00  st  %i5, [ %o5 ]
a00fb7b4:  b2 06 c0 1c  add  %i3, %i4, %i1
a00fb7b8:  bb 2e 20 10  sll  %i0, 0x10, %i5
a00fb7bc:  b7 2e 60 03  sll  %i1, 3, %i3
a00fb7c0:  b2 13 60 04  or  %o5, 4, %i1
a00fb7c4:  80 a0 00 1d  cmp  %g0, %i5
a00fb7c8:  b0 23 c0 1b  sub  %o7, %i3, %i0
a00fb7cc:  83 2e a0 10  sll  %i2, 0x10, %g1
a00fb7d0:  fa 06 40 00  ld  [ %i1 ], %i5
a00fb7d4:  b5 30 60 10  srl  %g1, 0x10, %i2
a00fb7d8:  b7 2f 20 10  sll  %i4, 0x10, %i3
a00fb7dc:  b4 40 00 1a  addx  %g0, %i2, %i2
a00fb7e0:  9f 2e 20 10  sll  %i0, 0x10, %o7
a00fb7e4:  82 0f 7f 8c  and  %i5, -116, %g1
a00fb7e8:  b9 36 e0 10  srl  %i3, 0x10, %i4
a00fb7ec:  ba 10 61 8c  or  %g1, 0x18c, %i5
a00fb7f0:  37 00 01 ff  sethi  %hi(0x7fc00), %i3
a00fb7f4:  b1 2e a0 0a  sll  %i2, 0xa, %i0
a00fb7f8:  82 0e 00 1b  and  %i0, %i3, %g1
a00fb7fc:  b0 2f 40 1b  andn  %i5, %i3, %i0
a00fb800:  80 a0 00 0f  cmp  %g0, %o7
a00fb804:  b6 16 00 01  or  %i0, %g1, %i3
a00fb808:  b8 40 00 1c  addx  %g0, %i4, %i4
a00fb80c:  31 07 fc 00  sethi  %hi(0x1ff00000), %i0
a00fb810:  bb 2f 20 14  sll  %i4, 0x14, %i5
a00fb814:  82 0f 40 18  and  %i5, %i0, %g1
a00fb818:  ba 2e c0 18  andn  %i3, %i0, %i5
a00fb81c:  b0 17 40 01  or  %i5, %g1, %i0
a00fb820:  b7 37 20 01  srl  %i4, 1, %i3
a00fb824:  f0 26 40 00  st  %i0, [ %i1 ]
a00fb828:  b8 06 ff ff  add  %i3, -1, %i4
a00fb82c:  b1 37 20 01  srl  %i4, 1, %i0
a00fb830:  9a 13 60 c4  or  %o5, 0xc4, %o5
a00fb834:  f6 03 40 00  ld  [ %o5 ], %i3
a00fb838:  83 36 20 02  srl  %i0, 2, %g1
a00fb83c:  ba 08 60 0f  and  %g1, 0xf, %i5
a00fb840:  b2 0e f0 00  and  %i3, -4096, %i1
a00fb844:  b6 16 40 1d  or  %i1, %i5, %i3
a00fb848:  83 2e 20 11  sll  %i0, 0x11, %g1
a00fb84c:  3b 00 3f c0  sethi  %hi(0xff0000), %i5
a00fb850:  b5 36 a0 01  srl  %i2, 1, %i2
a00fb854:  b8 08 40 1d  and  %g1, %i5, %i4
a00fb858:  b2 2e c0 1d  andn  %i3, %i5, %i1
a00fb85c:  b0 06 bf ff  add  %i2, -1, %i0
a00fb860:  ba 16 40 1c  or  %i1, %i4, %i5
a00fb864:  37 3f c0 00  sethi  %hi(0xff000000), %i3
a00fb868:  83 2e 20 18  sll  %i0, 0x18, %g1
a00fb86c:  b4 08 40 1b  and  %g1, %i3, %i2
a00fb870:  b2 2f 40 1b  andn  %i5, %i3, %i1
a00fb874:  b8 16 40 1a  or  %i1, %i2, %i4
a00fb878:  f8 23 40 00  st  %i4, [ %o5 ]
a00fb87c:  30 80 00 5a  b,a   0xa00fb9e4
a00fb880:  10 bf ff 8e  b  0xa00fb6b8
a00fb884:  82 10 00 1c  mov  %i4, %g1
a00fb888:  39 34 01 00  sethi  %hi(0xd0040000), %i4
a00fb88c:  b8 17 21 38  or  %i4, 0x138, %i4	! 0xd0040138
a00fb890:  f6 07 00 00  ld  [ %i4 ], %i3
a00fb894:  10 bf fe f9  b  0xa00fb478
a00fb898:  03 00 7f c0  sethi  %hi(0x1ff0000), %g1
a00fb89c:  03 34 01 00  sethi  %hi(0xd0040000), %g1
a00fb8a0:  b8 10 61 60  or  %g1, 0x160, %i4	! 0xd0040160
a00fb8a4:  f6 07 00 00  ld  [ %i4 ], %i3
a00fb8a8:  10 bf fe f4  b  0xa00fb478
a00fb8ac:  03 00 3f c0  sethi  %hi(0xff0000), %g1
a00fb8b0:  31 34 01 00  sethi  %hi(0xd0040000), %i0
a00fb8b4:  b8 16 21 30  or  %i0, 0x130, %i4	! 0xd0040130
a00fb8b8:  f6 07 00 00  ld  [ %i4 ], %i3
a00fb8bc:  10 bf fe ef  b  0xa00fb478
a00fb8c0:  03 00 3f c0  sethi  %hi(0xff0000), %g1
a00fb8c4:  37 34 01 00  sethi  %hi(0xd0040000), %i3
a00fb8c8:  b8 16 e1 38  or  %i3, 0x138, %i4	! 0xd0040138
a00fb8cc:  f6 07 00 00  ld  [ %i4 ], %i3
a00fb8d0:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00fb8d4:  10 bf fe ea  b  0xa00fb47c
a00fb8d8:  bb 2e a0 1f  sll  %i2, 0x1f, %i5
a00fb8dc:  3b 34 01 00  sethi  %hi(0xd0040000), %i5
a00fb8e0:  10 bf ff fb  b  0xa00fb8cc
a00fb8e4:  b8 17 61 40  or  %i5, 0x140, %i4	! 0xd0040140
a00fb8e8:  39 34 01 00  sethi  %hi(0xd0040000), %i4
a00fb8ec:  10 bf ff f8  b  0xa00fb8cc
a00fb8f0:  b8 17 21 10  or  %i4, 0x110, %i4	! 0xd0040110
a00fb8f4:  03 34 01 00  sethi  %hi(0xd0040000), %g1
a00fb8f8:  b8 10 60 e4  or  %g1, 0xe4, %i4	! 0xd00400e4
a00fb8fc:  f6 07 00 00  ld  [ %i4 ], %i3
a00fb900:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a00fb904:  10 bf fe de  b  0xa00fb47c
a00fb908:  bb 2e a0 18  sll  %i2, 0x18, %i5
a00fb90c:  37 00 00 04  sethi  %hi(0x1000), %i3
a00fb910:  31 34 01 00  sethi  %hi(0xd0040000), %i0
a00fb914:  b8 16 20 0c  or  %i0, 0xc, %i4	! 0xd004000c
a00fb918:  82 16 ef 00  or  %i3, 0xf00, %g1
a00fb91c:  f6 07 00 00  ld  [ %i4 ], %i3
a00fb920:  10 bf fe d7  b  0xa00fb47c
a00fb924:  bb 2e a0 08  sll  %i2, 8, %i5
a00fb928:  37 34 01 00  sethi  %hi(0xd0040000), %i3
a00fb92c:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00fb930:  bb 2e a0 1f  sll  %i2, 0x1f, %i5
a00fb934:  f8 06 c0 00  ld  [ %i3 ], %i4
a00fb938:  b0 0f 40 01  and  %i5, %g1, %i0
a00fb93c:  82 2f 00 01  andn  %i4, %g1, %g1
a00fb940:  b8 10 40 18  or  %g1, %i0, %i4
a00fb944:  f8 26 c0 00  st  %i4, [ %i3 ]
a00fb948:  10 bf fe d2  b  0xa00fb490
a00fb94c:  82 0b e0 ff  and  %o7, 0xff, %g1
a00fb950:  10 bf fe cf  b  0xa00fb48c
a00fb954:  9e 10 20 04  mov  4, %o7
a00fb958:  80 a6 a1 df  cmp  %i2, 0x1df
a00fb95c:  08 80 00 08  bleu  0xa00fb97c
a00fb960:  ba 10 21 e0  mov  0x1e0, %i5
a00fb964:  03 00 00 04  sethi  %hi(0x1000), %g1
a00fb968:  82 10 60 e0  or  %g1, 0xe0, %g1	! 0x10e0
a00fb96c:  80 a6 80 01  cmp  %i2, %g1
a00fb970:  08 80 00 03  bleu  0xa00fb97c
a00fb974:  ba 10 00 1a  mov  %i2, %i5
a00fb978:  ba 10 00 01  mov  %g1, %i5
a00fb97c:  31 2a 00 b5  sethi  %hi(0xa802d400), %i0
a00fb980:  10 bf fe c3  b  0xa00fb48c
a00fb984:  fa 36 22 78  sth  %i5, [ %i0 + 0x278 ]	! 0xa802d678
a00fb988:  80 a6 a2 cf  cmp  %i2, 0x2cf
a00fb98c:  08 80 00 08  bleu  0xa00fb9ac
a00fb990:  ba 10 22 d0  mov  0x2d0, %i5
a00fb994:  3b 00 00 08  sethi  %hi(0x2000), %i5
a00fb998:  80 a6 80 1d  cmp  %i2, %i5
a00fb99c:  08 80 00 03  bleu  0xa00fb9a8
a00fb9a0:  82 10 00 1a  mov  %i2, %g1
a00fb9a4:  82 10 00 1d  mov  %i5, %g1
a00fb9a8:  ba 10 00 01  mov  %g1, %i5
a00fb9ac:  39 2a 00 b5  sethi  %hi(0xa802d400), %i4
a00fb9b0:  10 bf fe b7  b  0xa00fb48c
a00fb9b4:  fa 37 22 7a  sth  %i5, [ %i4 + 0x27a ]	! 0xa802d67a
a00fb9b8:  10 bf fe b5  b  0xa00fb48c
a00fb9bc:  9e 10 20 03  mov  3, %o7
a00fb9c0:  10 bf fe b3  b  0xa00fb48c
a00fb9c4:  9e 10 20 02  mov  2, %o7
a00fb9c8:  10 bf fe b1  b  0xa00fb48c
a00fb9cc:  9e 10 20 01  mov  1, %o7
a00fb9d0:  37 2a 00 ad  sethi  %hi(0xa802b400), %i3
a00fb9d4:  10 bf fe ae  b  0xa00fb48c
a00fb9d8:  f4 2e e3 fd  stb  %i2, [ %i3 + 0x3fd ]	! 0xa802b7fd
a00fb9dc:  10 bf ff 50  b  0xa00fb71c
a00fb9e0:  ba 10 00 1c  mov  %i4, %i5
a00fb9e4:  81 c7 e0 08  ret
a00fb9e8:  91 e8 20 01  restore  %g0, 1, %o0
