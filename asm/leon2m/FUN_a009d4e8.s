# leon2m FUN_a009d4e8 0xa009d4e8-0xa009d79c (692 bytes)
a009d4e8:  9d e3 bf 98  save  %sp, -104, %sp
a009d4ec:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009d4f0:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0	! 0xa802afec
a009d4f4:  1b 09 24 92  sethi  %hi(0x24924800), %o5
a009d4f8:  92 02 3f 6e  add  %o0, -146, %o1
a009d4fc:  82 13 61 25  or  %o5, 0x125, %g1
a009d500:  80 52 40 01  umul  %o1, %g1, %g0
a009d504:  9f 40 00 00  rd  %y, %o7
a009d508:  a4 22 40 0f  sub  %o1, %o7, %l2
a009d50c:  a1 34 a0 01  srl  %l2, 1, %l0
a009d510:  98 03 c0 10  add  %o7, %l0, %o4
a009d514:  97 33 20 02  srl  %o4, 2, %o3
a009d518:  95 2a e0 03  sll  %o3, 3, %o2
a009d51c:  9a 22 80 0b  sub  %o2, %o3, %o5
a009d520:  90 22 40 0d  sub  %o1, %o5, %o0
a009d524:  40 00 2f a6  call  0xa00a93bc
a009d528:  90 0a 20 ff  and  %o0, 0xff, %o0
a009d52c:  03 23 4f 72  sethi  %hi(0x8d3dc800), %g1
a009d530:  a0 10 63 09  or  %g1, 0x309, %l0	! 0x8d3dcb09
a009d534:  a4 10 20 00  clr  %l2
a009d538:  d0 14 63 ee  lduh  [ %l1 + 0x3ee ], %o0
a009d53c:  9e 02 3f 6f  add  %o0, -145, %o7
a009d540:  80 5b c0 10  smul  %o7, %l0, %g0
a009d544:  9b 40 00 00  rd  %y, %o5
a009d548:  82 03 40 0f  add  %o5, %o7, %g1
a009d54c:  97 38 60 04  sra  %g1, 4, %o3
a009d550:  99 3b e0 1f  sra  %o7, 0x1f, %o4
a009d554:  9a 22 c0 0c  sub  %o3, %o4, %o5
a009d558:  95 2b 60 03  sll  %o5, 3, %o2
a009d55c:  92 22 80 0d  sub  %o2, %o5, %o1
a009d560:  83 2a 60 02  sll  %o1, 2, %g1
a009d564:  98 00 40 0d  add  %g1, %o5, %o4
a009d568:  94 23 c0 0c  sub  %o7, %o4, %o2
a009d56c:  96 02 a0 92  add  %o2, 0x92, %o3
a009d570:  d6 24 63 ec  st  %o3, [ %l1 + 0x3ec ]
a009d574:  40 00 35 ef  call  0xa00aad30
a009d578:  90 0a a0 ff  and  %o2, 0xff, %o0
a009d57c:  92 0a 20 ff  and  %o0, 0xff, %o1
a009d580:  80 a2 60 01  cmp  %o1, 1
a009d584:  32 bf ff ee  bne,a   0xa009d53c
a009d588:  d0 14 63 ee  lduh  [ %l1 + 0x3ee ], %o0
a009d58c:  d8 04 63 ec  ld  [ %l1 + 0x3ec ], %o4
a009d590:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009d594:  9e 14 22 90  or  %l0, 0x290, %o7	! 0xa802d290
a009d598:  92 03 20 6e  add  %o4, 0x6e, %o1
a009d59c:  80 a3 20 ae  cmp  %o4, 0xae
a009d5a0:  02 80 00 60  be  0xa009d720
a009d5a4:  d2 2b e0 08  stb  %o1, [ %o7 + 8 ]
a009d5a8:  80 a3 20 a7  cmp  %o4, 0xa7
a009d5ac:  02 80 00 64  be  0xa009d73c
a009d5b0:  01 00 00 00  nop
a009d5b4:  80 a3 20 a0  cmp  %o4, 0xa0
a009d5b8:  02 80 00 65  be  0xa009d74c
a009d5bc:  01 00 00 00  nop
a009d5c0:  80 a3 20 99  cmp  %o4, 0x99
a009d5c4:  02 80 00 66  be  0xa009d75c
a009d5c8:  01 00 00 00  nop
a009d5cc:  80 a3 20 92  cmp  %o4, 0x92
a009d5d0:  02 80 00 6f  be  0xa009d78c
a009d5d4:  01 00 00 00  nop
a009d5d8:  80 8c a0 ff  btst  0xff, %l2
a009d5dc:  12 80 00 33  bne  0xa009d6a8
a009d5e0:  25 2a 00 97  sethi  %hi(0xa8025c00), %l2
a009d5e4:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a009d5e8:  21 09 24 92  sethi  %hi(0x24924800), %l0
a009d5ec:  94 02 3f 6e  add  %o0, -146, %o2
a009d5f0:  a0 14 21 25  or  %l0, 0x125, %l0
a009d5f4:  80 52 80 10  umul  %o2, %l0, %g0
a009d5f8:  97 40 00 00  rd  %y, %o3
a009d5fc:  98 22 80 0b  sub  %o2, %o3, %o4
a009d600:  9b 33 20 01  srl  %o4, 1, %o5
a009d604:  92 02 c0 0d  add  %o3, %o5, %o1
a009d608:  83 32 60 02  srl  %o1, 2, %g1
a009d60c:  9f 28 60 03  sll  %g1, 3, %o7
a009d610:  98 23 c0 01  sub  %o7, %g1, %o4
a009d614:  96 22 80 0c  sub  %o2, %o4, %o3
a009d618:  90 0a e0 ff  and  %o3, 0xff, %o0
a009d61c:  40 00 30 0d  call  0xa00a9650
a009d620:  92 10 20 01  mov  1, %o1
a009d624:  40 00 3f 8f  call  0xa00ad460
a009d628:  01 00 00 00  nop
a009d62c:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a009d630:  d4 0c a0 56  ldub  [ %l2 + 0x56 ], %o2
a009d634:  96 02 3f 6e  add  %o0, -146, %o3
a009d638:  80 52 80 10  umul  %o2, %l0, %g0
a009d63c:  93 40 00 00  rd  %y, %o1
a009d640:  80 52 c0 10  umul  %o3, %l0, %g0
a009d644:  9f 40 00 00  rd  %y, %o7
a009d648:  a4 22 80 09  sub  %o2, %o1, %l2
a009d64c:  a3 34 a0 01  srl  %l2, 1, %l1
a009d650:  9a 22 c0 0f  sub  %o3, %o7, %o5
a009d654:  98 02 40 11  add  %o1, %l1, %o4
a009d658:  83 33 60 01  srl  %o5, 1, %g1
a009d65c:  90 03 c0 01  add  %o7, %g1, %o0
a009d660:  99 33 20 02  srl  %o4, 2, %o4
a009d664:  a5 32 20 02  srl  %o0, 2, %l2
a009d668:  a2 0b 20 ff  and  %o4, 0xff, %l1
a009d66c:  80 a4 80 11  cmp  %l2, %l1
a009d670:  02 80 00 04  be  0xa009d680
a009d674:  80 a2 c0 0a  cmp  %o3, %o2
a009d678:  40 00 6c 90  call  0xa00b88b8
a009d67c:  81 e8 00 00  restore
a009d680:  02 80 00 3b  be  0xa009d76c
a009d684:  97 2b 20 03  sll  %o4, 3, %o3
a009d688:  92 22 c0 0c  sub  %o3, %o4, %o1
a009d68c:  82 22 80 09  sub  %o2, %o1, %g1
a009d690:  92 08 60 ff  and  %g1, 0xff, %o1
a009d694:  90 10 20 01  mov  1, %o0
a009d698:  40 00 2a a9  call  0xa00a813c
a009d69c:  94 10 20 01  mov  1, %o2
a009d6a0:  40 00 6c 86  call  0xa00b88b8
a009d6a4:  81 e8 00 00  restore
a009d6a8:  15 09 24 92  sethi  %hi(0x24924800), %o2
a009d6ac:  82 12 a1 25  or  %o2, 0x125, %g1	! 0x24924925
a009d6b0:  9e 14 22 90  or  %l0, 0x290, %o7
a009d6b4:  d0 0b e0 08  ldub  [ %o7 + 8 ], %o0
a009d6b8:  d4 0c a0 56  ldub  [ %l2 + 0x56 ], %o2
a009d6bc:  80 52 80 01  umul  %o2, %g1, %g0
a009d6c0:  9f 40 00 00  rd  %y, %o7
a009d6c4:  80 52 00 01  umul  %o0, %g1, %g0
a009d6c8:  93 40 00 00  rd  %y, %o1
a009d6cc:  98 22 00 09  sub  %o0, %o1, %o4
a009d6d0:  96 22 80 0f  sub  %o2, %o7, %o3
a009d6d4:  a1 33 20 01  srl  %o4, 1, %l0
a009d6d8:  9b 32 e0 01  srl  %o3, 1, %o5
a009d6dc:  90 02 40 10  add  %o1, %l0, %o0
a009d6e0:  96 03 c0 0d  add  %o7, %o5, %o3
a009d6e4:  83 32 20 02  srl  %o0, 2, %g1
a009d6e8:  97 32 e0 02  srl  %o3, 2, %o3
a009d6ec:  98 08 60 ff  and  %g1, 0xff, %o4
a009d6f0:  a0 0a e0 ff  and  %o3, 0xff, %l0
a009d6f4:  80 a3 00 10  cmp  %o4, %l0
a009d6f8:  32 bf ff bc  bne,a   0xa009d5e8
a009d6fc:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a009d700:  a1 2a e0 03  sll  %o3, 3, %l0
a009d704:  92 24 00 0b  sub  %l0, %o3, %o1
a009d708:  9a 22 80 09  sub  %o2, %o1, %o5
a009d70c:  90 0b 60 ff  and  %o5, 0xff, %o0
a009d710:  40 00 2f d0  call  0xa00a9650
a009d714:  92 10 20 00  clr  %o1
a009d718:  10 bf ff b4  b  0xa009d5e8
a009d71c:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a009d720:  40 00 2d 5a  call  0xa00a8c88
a009d724:  01 00 00 00  nop
a009d728:  90 10 20 04  mov  4, %o0	! 0x4
a009d72c:  40 00 2c 28  call  0xa00a87cc
a009d730:  a4 10 20 01  mov  1, %l2
a009d734:  10 bf ff aa  b  0xa009d5dc
a009d738:  80 8c a0 ff  btst  0xff, %l2
a009d73c:  40 00 2d 53  call  0xa00a8c88
a009d740:  01 00 00 00  nop
a009d744:  10 bf ff fa  b  0xa009d72c
a009d748:  90 10 20 03  mov  3, %o0	! 0x3
a009d74c:  40 00 2d 4f  call  0xa00a8c88
a009d750:  01 00 00 00  nop
a009d754:  10 bf ff f6  b  0xa009d72c
a009d758:  90 10 20 02  mov  2, %o0	! 0x2
a009d75c:  40 00 2d 4b  call  0xa00a8c88
a009d760:  01 00 00 00  nop
a009d764:  10 bf ff f2  b  0xa009d72c
a009d768:  90 10 20 01  mov  1, %o0	! 0x1
a009d76c:  9f 2b 20 03  sll  %o4, 3, %o7
a009d770:  a4 23 c0 0c  sub  %o7, %o4, %l2
a009d774:  a2 22 80 12  sub  %o2, %l2, %l1
a009d778:  92 0c 60 ff  and  %l1, 0xff, %o1
a009d77c:  90 10 20 01  mov  1, %o0
a009d780:  40 00 2a 6f  call  0xa00a813c
a009d784:  94 10 20 00  clr  %o2
a009d788:  30 bf ff c6  b,a   0xa009d6a0
a009d78c:  40 00 2d 3f  call  0xa00a8c88
a009d790:  01 00 00 00  nop
a009d794:  10 bf ff e6  b  0xa009d72c
a009d798:  90 10 20 00  clr  %o0	! 0x0
