# leon2s FUN_a00cb56c 0xa00cb56c-0xa00cb7a0 (564 bytes)
a00cb56c:  9d e3 bf 98  save  %sp, -104, %sp
a00cb570:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cb574:  82 06 00 18  add  %i0, %i0, %g1
a00cb578:  82 00 40 18  add  %g1, %i0, %g1
a00cb57c:  a1 28 60 03  sll  %g1, 3, %l0
a00cb580:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00cb584:  29 2a 01 e2  sethi  %hi(0xa8078800), %l4
a00cb588:  a2 15 23 b0  or  %l4, 0x3b0, %l1	! 0xa8078bb0
a00cb58c:  a6 10 63 ff  or  %g1, 0x3ff, %l3
a00cb590:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cb594:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cb598:  82 08 40 13  and  %g1, %l3, %g1
a00cb59c:  82 10 40 0d  or  %g1, %o5, %g1
a00cb5a0:  25 2a 01 f4  sethi  %hi(0xa807d000), %l2
a00cb5a4:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cb5a8:  90 10 00 18  mov  %i0, %o0
a00cb5ac:  7f ff f8 7b  call  0xa00c9798
a00cb5b0:  92 14 a2 50  or  %l2, 0x250, %o1
a00cb5b4:  80 8a 20 ff  btst  0xff, %o0
a00cb5b8:  32 80 00 0b  bne,a   0xa00cb5e4
a00cb5bc:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cb5c0:  82 14 a2 50  or  %l2, 0x250, %g1
a00cb5c4:  d8 08 60 01  ldub  [ %g1 + 1 ], %o4
a00cb5c8:  82 0b 20 03  and  %o4, 3, %g1
a00cb5cc:  83 28 60 08  sll  %g1, 8, %g1
a00cb5d0:  da 0c a2 50  ldub  [ %l2 + 0x250 ], %o5
a00cb5d4:  80 8b 20 0c  btst  0xc, %o4
a00cb5d8:  02 80 00 05  be  0xa00cb5ec
a00cb5dc:  82 00 40 0d  add  %g1, %o5, %g1
a00cb5e0:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cb5e4:  10 80 00 08  b  0xa00cb604
a00cb5e8:  82 08 40 13  and  %g1, %l3, %g1
a00cb5ec:  83 28 60 10  sll  %g1, 0x10, %g1
a00cb5f0:  80 a0 60 00  cmp  %g1, 0
a00cb5f4:  12 80 00 06  bne  0xa00cb60c
a00cb5f8:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00cb5fc:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cb600:  82 10 40 0d  or  %g1, %o5, %g1
a00cb604:  10 80 00 65  b  0xa00cb798
a00cb608:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cb60c:  90 10 00 18  mov  %i0, %o0
a00cb610:  92 10 20 09  mov  9, %o1
a00cb614:  7f ff f4 75  call  0xa00c87e8
a00cb618:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cb61c:  a2 10 20 00  clr  %l1
a00cb620:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00cb624:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00cb628:  a2 04 60 01  inc  %l1
a00cb62c:  80 8c 20 0f  btst  0xf, %l0
a00cb630:  12 80 00 04  bne  0xa00cb640
a00cb634:  90 12 22 88  or  %o0, 0x288, %o0
a00cb638:  40 3a de 83  call  0xa0f83044
a00cb63c:  01 00 00 00  nop
a00cb640:  90 10 00 18  mov  %i0, %o0
a00cb644:  7f ff f0 4b  call  0xa00c7770
a00cb648:  92 10 20 01  mov  1, %o1
a00cb64c:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00cb650:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00cb654:  82 10 60 88  or  %g1, 0x88, %g1
a00cb658:  80 a3 60 1f  cmp  %o5, 0x1f
a00cb65c:  08 bf ff f1  bleu  0xa00cb620
a00cb660:  d0 28 40 10  stb  %o0, [ %g1 + %l0 ]
a00cb664:  90 10 00 18  mov  %i0, %o0
a00cb668:  92 10 20 74  mov  0x74, %o1
a00cb66c:  94 10 20 80  mov  0x80, %o2
a00cb670:  7f ff f2 76  call  0xa00c8048
a00cb674:  96 10 20 21  mov  0x21, %o3
a00cb678:  80 8a 20 ff  btst  0xff, %o0
a00cb67c:  12 80 00 0b  bne  0xa00cb6a8
a00cb680:  9a 06 00 18  add  %i0, %i0, %o5
a00cb684:  25 2a 01 f3  sethi  %hi(0xa807cc00), %l2
a00cb688:  90 10 00 18  mov  %i0, %o0
a00cb68c:  92 14 a2 50  or  %l2, 0x250, %o1
a00cb690:  7f ff f2 da  call  0xa00c81f8
a00cb694:  94 10 20 21  mov  0x21, %o2
a00cb698:  80 8a 20 ff  btst  0xff, %o0
a00cb69c:  02 80 00 16  be  0xa00cb6f4
a00cb6a0:  a2 10 20 00  clr  %l1
a00cb6a4:  9a 06 00 18  add  %i0, %i0, %o5
a00cb6a8:  9a 03 40 18  add  %o5, %i0, %o5
a00cb6ac:  96 15 23 b0  or  %l4, 0x3b0, %o3
a00cb6b0:  9b 2b 60 03  sll  %o5, 3, %o5
a00cb6b4:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00cb6b8:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cb6bc:  82 2b 00 01  andn  %o4, %g1, %g1
a00cb6c0:  10 80 00 36  b  0xa00cb798
a00cb6c4:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cb6c8:  98 06 00 18  add  %i0, %i0, %o4
a00cb6cc:  98 03 00 18  add  %o4, %i0, %o4
a00cb6d0:  96 15 23 b0  or  %l4, 0x3b0, %o3
a00cb6d4:  99 2b 20 03  sll  %o4, 3, %o4
a00cb6d8:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cb6dc:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cb6e0:  82 2b 40 01  andn  %o5, %g1, %g1
a00cb6e4:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00cb6e8:  82 10 40 0d  or  %g1, %o5, %g1
a00cb6ec:  10 80 00 2b  b  0xa00cb798
a00cb6f0:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cb6f4:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00cb6f8:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00cb6fc:  a2 04 60 01  inc  %l1
a00cb700:  80 8c 20 0f  btst  0xf, %l0
a00cb704:  12 80 00 04  bne  0xa00cb714
a00cb708:  90 12 22 88  or  %o0, 0x288, %o0
a00cb70c:  40 3a de 4e  call  0xa0f83044
a00cb710:  01 00 00 00  nop
a00cb714:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a00cb718:  82 14 a2 50  or  %l2, 0x250, %g1
a00cb71c:  92 13 61 88  or  %o5, 0x188, %o1
a00cb720:  82 04 00 01  add  %l0, %g1, %g1
a00cb724:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a00cb728:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00cb72c:  80 a3 60 1f  cmp  %o5, 0x1f
a00cb730:  08 bf ff f1  bleu  0xa00cb6f4
a00cb734:  c2 2a 40 10  stb  %g1, [ %o1 + %l0 ]
a00cb738:  98 06 00 18  add  %i0, %i0, %o4
a00cb73c:  98 03 00 18  add  %o4, %i0, %o4
a00cb740:  96 15 23 b0  or  %l4, 0x3b0, %o3
a00cb744:  99 2b 20 03  sll  %o4, 3, %o4
a00cb748:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cb74c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cb750:  82 2b 40 01  andn  %o5, %g1, %g1
a00cb754:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cb758:  82 10 40 0d  or  %g1, %o5, %g1
a00cb75c:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cb760:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00cb764:  94 10 60 88  or  %g1, 0x88, %o2	! 0xa807d088
a00cb768:  96 10 00 09  mov  %o1, %o3
a00cb76c:  a2 10 20 00  clr  %l1
a00cb770:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cb774:  da 0a c0 01  ldub  [ %o3 + %g1 ], %o5
a00cb778:  a2 04 60 01  inc  %l1
a00cb77c:  c2 0a 80 01  ldub  [ %o2 + %g1 ], %g1
a00cb780:  80 a0 40 0d  cmp  %g1, %o5
a00cb784:  12 bf ff d1  bne  0xa00cb6c8
a00cb788:  98 0c 60 ff  and  %l1, 0xff, %o4
a00cb78c:  80 a3 20 1f  cmp  %o4, 0x1f
a00cb790:  08 bf ff f9  bleu  0xa00cb774
a00cb794:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cb798:  81 c7 e0 08  ret
a00cb79c:  81 e8 00 00  restore
