# leon2s FUN_a00db53c 0xa00db53c-0xa00db784 (584 bytes)
a00db53c:  9d e3 bf 98  save  %sp, -104, %sp
a00db540:  29 2a 01 e1  sethi  %hi(0xa8078400), %l4
a00db544:  d4 0d 23 fe  ldub  [ %l4 + 0x3fe ], %o2	! 0xa80787fe
a00db548:  82 0a a0 0f  and  %o2, 0xf, %g1
a00db54c:  98 00 40 01  add  %g1, %g1, %o4
a00db550:  98 03 00 01  add  %o4, %g1, %o4
a00db554:  17 2a 01 e9  sethi  %hi(0xa807a400), %o3
a00db558:  99 2b 20 04  sll  %o4, 4, %o4
a00db55c:  96 12 e1 20  or  %o3, 0x120, %o3
a00db560:  da 0b 00 0b  ldub  [ %o4 + %o3 ], %o5
a00db564:  9b 33 60 04  srl  %o5, 4, %o5
a00db568:  9a 03 7f ff  add  %o5, -1, %o5
a00db56c:  83 33 60 1f  srl  %o5, 0x1f, %g1
a00db570:  82 03 40 01  add  %o5, %g1, %g1
a00db574:  93 38 60 01  sra  %g1, 1, %o1
a00db578:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00db57c:  82 10 60 88  or  %g1, 0x88, %g1	! 0xa8079c88
a00db580:  ea 08 40 0a  ldub  [ %g1 + %o2 ], %l5
a00db584:  80 8b 60 01  btst  1, %o5
a00db588:  a0 10 20 00  clr  %l0
a00db58c:  a2 10 20 00  clr  %l1
a00db590:  a6 10 20 00  clr  %l3
a00db594:  a4 03 00 0b  add  %o4, %o3, %l2
a00db598:  02 80 00 03  be  0xa00db5a4
a00db59c:  82 10 00 09  mov  %o1, %g1
a00db5a0:  82 02 60 01  add  %o1, 1, %g1
a00db5a4:  98 08 60 ff  and  %g1, 0xff, %o4
a00db5a8:  9a 04 80 0c  add  %l2, %o4, %o5
a00db5ac:  c2 0b 60 03  ldub  [ %o5 + 3 ], %g1
a00db5b0:  80 a0 60 11  cmp  %g1, 0x11
a00db5b4:  12 80 00 22  bne  0xa00db63c
a00db5b8:  80 a0 60 14  cmp  %g1, 0x14
a00db5bc:  c2 0b 60 06  ldub  [ %o5 + 6 ], %g1
a00db5c0:  80 a0 60 00  cmp  %g1, 0
a00db5c4:  32 80 00 07  bne,a   0xa00db5e0
a00db5c8:  82 04 80 0c  add  %l2, %o4, %g1
a00db5cc:  c2 0b 60 07  ldub  [ %o5 + 7 ], %g1
a00db5d0:  80 a0 60 00  cmp  %g1, 0
a00db5d4:  02 80 00 05  be  0xa00db5e8
a00db5d8:  82 10 20 01  mov  1, %g1
a00db5dc:  82 04 80 0c  add  %l2, %o4, %g1
a00db5e0:  e0 08 60 05  ldub  [ %g1 + 5 ], %l0
a00db5e4:  82 10 20 00  clr  %g1
a00db5e8:  80 88 60 ff  btst  0xff, %g1
a00db5ec:  32 80 00 3a  bne,a   0xa00db6d4
a00db5f0:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00db5f4:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db5f8:  92 0c 20 ff  and  %l0, 0xff, %o1
a00db5fc:  94 10 20 00  clr  %o2
a00db600:  40 3a 9e 91  call  0xa0f83044
a00db604:  90 12 22 e8  or  %o0, 0x2e8, %o0
a00db608:  92 10 20 00  clr  %o1
a00db60c:  94 10 20 00  clr  %o2
a00db610:  7f ff fe 20  call  0xa00dae90
a00db614:  90 0c 20 ff  and  %l0, 0xff, %o0
a00db618:  7f ff eb b5  call  0xa00d64ec
a00db61c:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00db620:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db624:  13 27 c7 32  sethi  %hi(0x9f1cc800), %o1
a00db628:  92 12 63 30  or  %o1, 0x330, %o1	! 0x9f1ccb30
a00db62c:  40 3a 9e 86  call  0xa0f83044
a00db630:  90 12 23 08  or  %o0, 0x308, %o0
a00db634:  10 80 00 29  b  0xa00db6d8
a00db638:  80 a4 20 00  cmp  %l0, 0
a00db63c:  12 80 00 26  bne  0xa00db6d4
a00db640:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00db644:  90 10 20 00  clr  %o0
a00db648:  92 10 20 01  mov  1, %o1
a00db64c:  7f ff fe 11  call  0xa00dae90
a00db650:  94 10 20 01  mov  1, %o2
a00db654:  21 2a 01 e2  sethi  %hi(0xa8078800), %l0
a00db658:  c2 0c 20 54  ldub  [ %l0 + 0x54 ], %g1	! 0xa8078854
a00db65c:  80 a0 60 01  cmp  %g1, 1
a00db660:  12 80 00 0e  bne  0xa00db698
a00db664:  19 33 c0 4c  sethi  %hi(0xcf013000), %o4
a00db668:  1b 33 c0 62  sethi  %hi(0xcf018800), %o5
a00db66c:  d6 03 00 00  ld  [ %o4 ], %o3
a00db670:  9a 13 61 e0  or  %o5, 0x1e0, %o5
a00db674:  d4 03 40 00  ld  [ %o5 ], %o2
a00db678:  c2 03 00 00  ld  [ %o4 ], %g1
a00db67c:  82 10 60 80  or  %g1, 0x80, %g1
a00db680:  c2 23 00 00  st  %g1, [ %o4 ]
a00db684:  c2 03 40 00  ld  [ %o5 ], %g1
a00db688:  82 10 60 01  or  %g1, 1, %g1
a00db68c:  c2 23 40 00  st  %g1, [ %o5 ]
a00db690:  a2 10 00 0b  mov  %o3, %l1
a00db694:  a6 10 00 0a  mov  %o2, %l3
a00db698:  7f ff eb 95  call  0xa00d64ec
a00db69c:  01 00 00 00  nop
a00db6a0:  c2 0c 20 54  ldub  [ %l0 + 0x54 ], %g1
a00db6a4:  80 a0 60 01  cmp  %g1, 1
a00db6a8:  32 80 00 0b  bne,a   0xa00db6d4
a00db6ac:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00db6b0:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00db6b4:  03 33 c0 4c  sethi  %hi(0xcf013000), %g1
a00db6b8:  da 20 40 00  st  %o5, [ %g1 ]
a00db6bc:  03 33 c0 62  sethi  %hi(0xcf018800), %g1
a00db6c0:  9a 0c e0 ff  and  %l3, 0xff, %o5
a00db6c4:  82 10 61 e0  or  %g1, 0x1e0, %g1
a00db6c8:  da 20 40 00  st  %o5, [ %g1 ]
a00db6cc:  c0 2c 20 54  clrb  [ %l0 + 0x54 ]
a00db6d0:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00db6d4:  80 a4 20 00  cmp  %l0, 0
a00db6d8:  02 80 00 25  be  0xa00db76c
a00db6dc:  98 10 20 00  clr  %o4
a00db6e0:  82 0b 20 ff  and  %o4, 0xff, %g1
a00db6e4:  83 28 60 04  sll  %g1, 4, %g1
a00db6e8:  9a 00 60 10  add  %g1, 0x10, %o5
a00db6ec:  96 25 40 01  sub  %l5, %g1, %o3
a00db6f0:  80 a3 40 10  cmp  %o5, %l0
a00db6f4:  9a 20 70 00  sub  %g1, -4096, %o5
a00db6f8:  96 02 ff ff  add  %o3, -1, %o3
a00db6fc:  97 2a e0 18  sll  %o3, 0x18, %o3
a00db700:  a2 03 20 01  add  %o4, 1, %l1
a00db704:  82 04 80 01  add  %l2, %g1, %g1
a00db708:  97 3a e0 18  sra  %o3, 0x18, %o3
a00db70c:  92 10 20 80  mov  0x80, %o1
a00db710:  90 10 20 00  clr  %o0
a00db714:  94 10 00 0d  mov  %o5, %o2
a00db718:  14 80 00 07  bg  0xa00db734
a00db71c:  98 10 00 01  mov  %g1, %o4
a00db720:  94 10 00 0d  mov  %o5, %o2
a00db724:  98 10 00 01  mov  %g1, %o4
a00db728:  92 10 20 80  mov  0x80, %o1
a00db72c:  96 10 20 0f  mov  0xf, %o3
a00db730:  90 10 20 00  clr  %o0
a00db734:  40 3a eb 28  call  0xa0f963d4
a00db738:  01 00 00 00  nop
a00db73c:  80 8a 20 ff  btst  0xff, %o0
a00db740:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db744:  12 80 00 05  bne  0xa00db758
a00db748:  90 12 23 38  or  %o0, 0x338, %o0	! 0x9f1ccb38
a00db74c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00db750:  40 3a 9e 3d  call  0xa0f83044
a00db754:  d2 08 60 32  ldub  [ %g1 + 0x32 ], %o1	! 0xa8078832
a00db758:  82 0c 60 ff  and  %l1, 0xff, %g1
a00db75c:  83 28 60 04  sll  %g1, 4, %g1
a00db760:  80 a0 40 10  cmp  %g1, %l0
a00db764:  06 bf ff df  bl  0xa00db6e0
a00db768:  98 10 00 11  mov  %l1, %o4
a00db76c:  c2 0d 23 fe  ldub  [ %l4 + 0x3fe ], %g1
a00db770:  82 00 60 01  inc  %g1
a00db774:  82 08 60 0f  and  %g1, 0xf, %g1
a00db778:  c2 2d 23 fe  stb  %g1, [ %l4 + 0x3fe ]
a00db77c:  81 c7 e0 08  ret
a00db780:  81 e8 00 00  restore
