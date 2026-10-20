# leon2s LINK_STANDBY_2 0xa006e444-0xa006e820 (988 bytes)  [FUN_a006e818 = unreachable ret/restore tail, merged]
a006e444:  9d e3 bf 98  save  %sp, -104, %sp
a006e448:  a0 0e 60 ff  and  %i1, 0xff, %l0
a006e44c:  40 00 9f 67  call  0xa00961e8
a006e450:  90 10 00 10  mov  %l0, %o0
a006e454:  a2 10 00 18  mov  %i0, %l1
a006e458:  80 a4 20 01  cmp  %l0, 1
a006e45c:  f0 0e 00 00  ldub  [ %i0 ], %i0
a006e460:  e4 0c 60 0d  ldub  [ %l1 + 0xd ], %l2
a006e464:  18 80 00 ec  bgu  0xa006e814
a006e468:  e6 0c 60 0e  ldub  [ %l1 + 0xe ], %l3
a006e46c:  13 2a 01 e2  sethi  %hi(0xa8078800), %o1
a006e470:  c2 0a 60 92  ldub  [ %o1 + 0x92 ], %g1	! 0xa8078892
a006e474:  80 a0 60 00  cmp  %g1, 0
a006e478:  32 80 00 0e  bne,a   0xa006e4b0
a006e47c:  90 0a 20 ff  and  %o0, 0xff, %o0
a006e480:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006e484:  94 10 60 90  or  %g1, 0x90, %o2	! 0xa8078890
a006e488:  98 10 20 00  clr  %o4
a006e48c:  96 10 20 01  mov  1, %o3
a006e490:  9a 0b 20 ff  and  %o4, 0xff, %o5
a006e494:  98 03 20 01  inc  %o4
a006e498:  82 0b 20 ff  and  %o4, 0xff, %g1
a006e49c:  80 a0 60 01  cmp  %g1, 1
a006e4a0:  08 bf ff fc  bleu  0xa006e490
a006e4a4:  d6 2a 80 0d  stb  %o3, [ %o2 + %o5 ]
a006e4a8:  d6 2a 60 92  stb  %o3, [ %o1 + 0x92 ]
a006e4ac:  90 0a 20 ff  and  %o0, 0xff, %o0
a006e4b0:  9a 02 00 08  add  %o0, %o0, %o5
a006e4b4:  d8 14 60 12  lduh  [ %l1 + 0x12 ], %o4
a006e4b8:  9a 03 40 08  add  %o5, %o0, %o5
a006e4bc:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a006e4c0:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa807cc64
a006e4c4:  9b 2b 60 03  sll  %o5, 3, %o5
a006e4c8:  99 33 20 07  srl  %o4, 7, %o4
a006e4cc:  9a 03 40 01  add  %o5, %g1, %o5
a006e4d0:  98 0b 20 01  and  %o4, 1, %o4
a006e4d4:  d8 2b 60 06  stb  %o4, [ %o5 + 6 ]
a006e4d8:  c2 0c 40 00  ldub  [ %l1 ], %g1
a006e4dc:  82 00 7f ff  add  %g1, -1, %g1
a006e4e0:  80 a0 60 04  cmp  %g1, 4
a006e4e4:  38 80 00 a4  bgu,a   0xa006e774
a006e4e8:  d4 0c 40 00  ldub  [ %l1 ], %o2
a006e4ec:  1b 28 01 b9  sethi  %hi(0xa006e400), %o5
a006e4f0:  83 28 60 02  sll  %g1, 2, %g1
a006e4f4:  9a 13 60 30  or  %o5, 0x30, %o5
a006e4f8:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a006e4fc:  81 c0 40 00  jmp  %g1
a006e500:  01 00 00 00  nop
a006e504:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006e508:  b6 10 60 90  or  %g1, 0x90, %i3	! 0xa8078890
a006e50c:  c2 0e c0 10  ldub  [ %i3 + %l0 ], %g1
a006e510:  80 a0 60 01  cmp  %g1, 1
a006e514:  32 80 00 98  bne,a   0xa006e774
a006e518:  d4 0c 40 00  ldub  [ %l1 ], %o2
a006e51c:  40 00 19 f7  call  0xa0074cf8
a006e520:  92 10 20 00  clr  %o1
a006e524:  c0 2e c0 10  clrb  [ %i3 + %l0 ]
a006e528:  40 00 cc 44  call  0xa00a1638
a006e52c:  90 10 00 10  mov  %l0, %o0
a006e530:  10 80 00 91  b  0xa006e774
a006e534:  d4 0c 40 00  ldub  [ %l1 ], %o2
a006e538:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006e53c:  b6 10 60 90  or  %g1, 0x90, %i3	! 0xa8078890
a006e540:  c2 0e c0 10  ldub  [ %i3 + %l0 ], %g1
a006e544:  80 a0 60 00  cmp  %g1, 0
a006e548:  32 80 00 6a  bne,a   0xa006e6f0
a006e54c:  90 10 00 11  mov  %l1, %o0
a006e550:  40 00 19 ca  call  0xa0074c78
a006e554:  01 00 00 00  nop
a006e558:  82 10 20 01  mov  1, %g1	! 0x1
a006e55c:  c2 2e c0 10  stb  %g1, [ %i3 + %l0 ]
a006e560:  40 00 cc 1a  call  0xa00a15c8
a006e564:  90 10 00 10  mov  %l0, %o0
a006e568:  10 80 00 62  b  0xa006e6f0
a006e56c:  90 10 00 11  mov  %l1, %o0
a006e570:  35 2a 01 f5  sethi  %hi(0xa807d400), %i2
a006e574:  82 16 a3 e0  or  %i2, 0x3e0, %g1	! 0xa807d7e0
a006e578:  9a 5c 21 90  smul  %l0, 0x190, %o5
a006e57c:  b6 03 40 01  add  %o5, %g1, %i3
a006e580:  c2 0e e0 04  ldub  [ %i3 + 4 ], %g1
a006e584:  80 a0 60 01  cmp  %g1, 1
a006e588:  32 80 00 7b  bne,a   0xa006e774
a006e58c:  d4 0c 40 00  ldub  [ %l1 ], %o2
a006e590:  c2 0e e0 2d  ldub  [ %i3 + 0x2d ], %g1
a006e594:  80 a0 60 01  cmp  %g1, 1
a006e598:  12 80 00 04  bne  0xa006e5a8
a006e59c:  01 00 00 00  nop
a006e5a0:  10 80 00 16  b  0xa006e5f8
a006e5a4:  c2 16 e0 1a  lduh  [ %i3 + 0x1a ], %g1
a006e5a8:  40 00 ce b6  call  0xa00a2080
a006e5ac:  90 10 00 10  mov  %l0, %o0
a006e5b0:  80 8a 20 ff  btst  0xff, %o0
a006e5b4:  02 80 00 11  be  0xa006e5f8
a006e5b8:  c2 16 e0 1a  lduh  [ %i3 + 0x1a ], %g1
a006e5bc:  82 00 40 01  add  %g1, %g1, %g1
a006e5c0:  c2 34 60 02  sth  %g1, [ %l1 + 2 ]
a006e5c4:  c2 16 e0 1e  lduh  [ %i3 + 0x1e ], %g1
a006e5c8:  82 00 40 01  add  %g1, %g1, %g1
a006e5cc:  c2 34 60 06  sth  %g1, [ %l1 + 6 ]
a006e5d0:  1b 33 33 33  sethi  %hi(0xcccccc00), %o5
a006e5d4:  c2 16 e0 32  lduh  [ %i3 + 0x32 ], %g1
a006e5d8:  9a 13 60 cd  or  %o5, 0xcd, %o5
a006e5dc:  80 50 40 0d  umul  %g1, %o5, %g0
a006e5e0:  83 40 00 00  rd  %y, %g1
a006e5e4:  83 28 60 0d  sll  %g1, 0xd, %g1
a006e5e8:  83 30 60 10  srl  %g1, 0x10, %g1
a006e5ec:  82 00 40 01  add  %g1, %g1, %g1
a006e5f0:  10 80 00 0c  b  0xa006e620
a006e5f4:  c2 34 60 0a  sth  %g1, [ %l1 + 0xa ]
a006e5f8:  c2 34 60 02  sth  %g1, [ %l1 + 2 ]
a006e5fc:  c2 16 e0 1e  lduh  [ %i3 + 0x1e ], %g1
a006e600:  c2 34 60 06  sth  %g1, [ %l1 + 6 ]
a006e604:  03 33 33 33  sethi  %hi(0xcccccc00), %g1
a006e608:  da 16 e0 32  lduh  [ %i3 + 0x32 ], %o5
a006e60c:  82 10 60 cd  or  %g1, 0xcd, %g1
a006e610:  80 53 40 01  umul  %o5, %g1, %g0
a006e614:  9b 40 00 00  rd  %y, %o5
a006e618:  9b 33 60 03  srl  %o5, 3, %o5
a006e61c:  da 34 60 0a  sth  %o5, [ %l1 + 0xa ]
a006e620:  9a 16 a3 e0  or  %i2, 0x3e0, %o5
a006e624:  82 5c 21 90  smul  %l0, 0x190, %g1
a006e628:  82 00 40 0d  add  %g1, %o5, %g1
a006e62c:  da 10 60 1c  lduh  [ %g1 + 0x1c ], %o5
a006e630:  da 34 60 04  sth  %o5, [ %l1 + 4 ]
a006e634:  c2 10 60 20  lduh  [ %g1 + 0x20 ], %g1
a006e638:  40 01 0e 8b  call  0xa00b2064
a006e63c:  c2 34 60 08  sth  %g1, [ %l1 + 8 ]
a006e640:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006e644:  a1 2c 20 02  sll  %l0, 2, %l0
a006e648:  82 10 60 84  or  %g1, 0x84, %g1
a006e64c:  d0 20 40 10  st  %o0, [ %g1 + %l0 ]
a006e650:  90 10 00 11  mov  %l1, %o0
a006e654:  10 80 00 28  b  0xa006e6f4
a006e658:  92 10 20 04  mov  4, %o1
a006e65c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a006e660:  9a 5c 21 90  smul  %l0, 0x190, %o5
a006e664:  82 10 63 e0  or  %g1, 0x3e0, %g1
a006e668:  9a 03 40 01  add  %o5, %g1, %o5
a006e66c:  f6 0b 60 04  ldub  [ %o5 + 4 ], %i3
a006e670:  80 a6 e0 01  cmp  %i3, 1
a006e674:  32 80 00 1f  bne,a   0xa006e6f0
a006e678:  90 10 00 11  mov  %l1, %o0
a006e67c:  40 00 cd eb  call  0xa00a1e28
a006e680:  90 10 00 10  mov  %l0, %o0
a006e684:  d0 2c 60 0c  stb  %o0, [ %l1 + 0xc ]
a006e688:  90 10 00 11  mov  %l1, %o0
a006e68c:  7f ff ff 0e  call  0xa006e2c4
a006e690:  92 10 00 10  mov  %l0, %o1
a006e694:  90 10 00 11  mov  %l1, %o0
a006e698:  7f ff fb a9  call  0xa006d53c
a006e69c:  92 10 20 05  mov  5, %o1
a006e6a0:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006e6a4:  92 10 00 10  mov  %l0, %o1
a006e6a8:  40 00 12 67  call  0xa0073044
a006e6ac:  90 12 23 30  or  %o0, 0x330, %o0
a006e6b0:  f6 2c 60 0f  stb  %i3, [ %l1 + 0xf ]
a006e6b4:  40 00 d0 d4  call  0xa00a2a04
a006e6b8:  90 10 00 10  mov  %l0, %o0
a006e6bc:  10 80 00 2e  b  0xa006e774
a006e6c0:  d4 0c 40 00  ldub  [ %l1 ], %o2
a006e6c4:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a006e6c8:  82 5c 21 90  smul  %l0, 0x190, %g1
a006e6cc:  9a 13 63 e0  or  %o5, 0x3e0, %o5
a006e6d0:  b6 00 40 0d  add  %g1, %o5, %i3
a006e6d4:  c2 0e e0 04  ldub  [ %i3 + 4 ], %g1
a006e6d8:  80 a0 60 01  cmp  %g1, 1
a006e6dc:  02 80 00 0a  be  0xa006e704
a006e6e0:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006e6e4:  40 00 12 58  call  0xa0073044
a006e6e8:  90 12 23 58  or  %o0, 0x358, %o0	! 0xa0065f58
a006e6ec:  90 10 00 11  mov  %l1, %o0
a006e6f0:  92 10 20 03  mov  3, %o1
a006e6f4:  7f ff fb 92  call  0xa006d53c
a006e6f8:  01 00 00 00  nop
a006e6fc:  10 80 00 1e  b  0xa006e774
a006e700:  d4 0c 40 00  ldub  [ %l1 ], %o2
a006e704:  40 00 cd c9  call  0xa00a1e28
a006e708:  90 10 00 10  mov  %l0, %o0
a006e70c:  90 0a 20 ff  and  %o0, 0xff, %o0
a006e710:  c2 0c 60 0c  ldub  [ %l1 + 0xc ], %g1
a006e714:  80 a2 00 01  cmp  %o0, %g1
a006e718:  02 80 00 12  be  0xa006e760
a006e71c:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006e720:  40 00 12 49  call  0xa0073044
a006e724:  90 12 23 58  or  %o0, 0x358, %o0	! 0xa0065f58
a006e728:  40 00 cd c0  call  0xa00a1e28
a006e72c:  90 10 00 10  mov  %l0, %o0
a006e730:  d0 2c 60 0c  stb  %o0, [ %l1 + 0xc ]
a006e734:  90 10 00 11  mov  %l1, %o0
a006e738:  7f ff fb 81  call  0xa006d53c
a006e73c:  92 10 20 03  mov  3, %o1
a006e740:  40 01 0e 49  call  0xa00b2064
a006e744:  01 00 00 00  nop
a006e748:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006e74c:  9b 2c 20 02  sll  %l0, 2, %o5
a006e750:  90 02 3f 38  add  %o0, -200, %o0
a006e754:  82 10 60 84  or  %g1, 0x84, %g1
a006e758:  10 80 00 06  b  0xa006e770
a006e75c:  d0 20 40 0d  st  %o0, [ %g1 + %o5 ]
a006e760:  92 10 00 10  mov  %l0, %o1
a006e764:  94 10 00 1b  mov  %i3, %o2
a006e768:  7f ff fe 5f  call  0xa006e0e4
a006e76c:  90 10 00 11  mov  %l1, %o0
a006e770:  d4 0c 40 00  ldub  [ %l1 ], %o2
a006e774:  82 1a a0 05  xor  %o2, 5, %g1
a006e778:  80 a0 00 01  cmp  %g0, %g1
a006e77c:  82 0e 20 ff  and  %i0, 0xff, %g1
a006e780:  9a 40 20 00  addx  %g0, 0, %o5
a006e784:  82 18 60 05  xor  %g1, 5, %g1
a006e788:  80 a0 00 01  cmp  %g0, %g1
a006e78c:  82 60 3f ff  subx  %g0, -1, %g1
a006e790:  80 8b 40 01  btst  %o5, %g1
a006e794:  02 80 00 09  be  0xa006e7b8
a006e798:  a0 0c a0 ff  and  %l2, 0xff, %l0
a006e79c:  82 10 20 01  mov  1, %g1
a006e7a0:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006e7a4:  c2 2c 60 10  stb  %g1, [ %l1 + 0x10 ]
a006e7a8:  90 12 23 70  or  %o0, 0x370, %o0
a006e7ac:  40 00 12 26  call  0xa0073044
a006e7b0:  92 0e 60 ff  and  %i1, 0xff, %o1
a006e7b4:  a0 0c a0 ff  and  %l2, 0xff, %l0
a006e7b8:  c2 0c 60 0d  ldub  [ %l1 + 0xd ], %g1
a006e7bc:  80 a0 40 10  cmp  %g1, %l0
a006e7c0:  12 80 00 07  bne  0xa006e7dc
a006e7c4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a006e7c8:  9a 0c e0 ff  and  %l3, 0xff, %o5
a006e7cc:  c2 0c 60 0e  ldub  [ %l1 + 0xe ], %g1
a006e7d0:  80 a0 40 0d  cmp  %g1, %o5
a006e7d4:  02 80 00 10  be  0xa006e814
a006e7d8:  01 00 00 00  nop
a006e7dc:  90 10 00 11  mov  %l1, %o0
a006e7e0:  7f ff fe b9  call  0xa006e2c4
a006e7e4:  92 10 00 19  mov  %i1, %o1
a006e7e8:  f4 0c 60 0d  ldub  [ %l1 + 0xd ], %i2
a006e7ec:  9a 0c 20 48  and  %l0, 0x48, %o5
a006e7f0:  82 0e a0 48  and  %i2, 0x48, %g1
a006e7f4:  80 a0 40 0d  cmp  %g1, %o5
a006e7f8:  02 80 00 03  be  0xa006e804
a006e7fc:  82 10 20 01  mov  1, %g1
a006e800:  c2 2c 60 10  stb  %g1, [ %l1 + 0x10 ]
a006e804:  31 28 01 97  sethi  %hi(0xa0065c00), %i0
a006e808:  f6 0c 60 0e  ldub  [ %l1 + 0xe ], %i3
a006e80c:  40 00 12 0e  call  0xa0073044
a006e810:  91 ee 23 90  restore  %i0, 0x390, %o0
a006e814:  01 00 00 00  nop
a006e818:  81 c7 e0 08  ret
a006e81c:  81 e8 00 00  restore
