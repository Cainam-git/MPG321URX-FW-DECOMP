# leon2s FUN_a00ab584 0xa00ab584-0xa00ab674 (240 bytes)
a00ab584:  03 33 c0 4c  sethi  %hi(0xcf013000), %g1
a00ab588:  1b 2a 01 f4  sethi  %hi(0xa807d000), %o5
a00ab58c:  94 10 62 80  or  %g1, 0x280, %o2
a00ab590:  96 10 62 84  or  %g1, 0x284, %o3
a00ab594:  c2 0b 62 89  ldub  [ %o5 + 0x289 ], %g1
a00ab598:  80 a0 60 a0  cmp  %g1, 0xa0
a00ab59c:  12 80 00 2d  bne  0xa00ab650
a00ab5a0:  92 13 62 89  or  %o5, 0x289, %o1
a00ab5a4:  d8 02 80 00  ld  [ %o2 ], %o4
a00ab5a8:  98 0b 3f e0  and  %o4, -32, %o4
a00ab5ac:  82 13 20 01  or  %o4, 1, %g1
a00ab5b0:  82 08 60 ff  and  %g1, 0xff, %g1
a00ab5b4:  c2 22 80 00  st  %g1, [ %o2 ]
a00ab5b8:  da 02 c0 00  ld  [ %o3 ], %o5
a00ab5bc:  c2 0a 60 03  ldub  [ %o1 + 3 ], %g1
a00ab5c0:  9a 0b 60 1f  and  %o5, 0x1f, %o5
a00ab5c4:  9a 13 40 01  or  %o5, %g1, %o5
a00ab5c8:  82 13 20 02  or  %o4, 2, %g1
a00ab5cc:  da 22 c0 00  st  %o5, [ %o3 ]
a00ab5d0:  82 08 60 ff  and  %g1, 0xff, %g1
a00ab5d4:  c2 22 80 00  st  %g1, [ %o2 ]
a00ab5d8:  da 02 c0 00  ld  [ %o3 ], %o5
a00ab5dc:  c2 0a 60 04  ldub  [ %o1 + 4 ], %g1
a00ab5e0:  9a 0b 60 1f  and  %o5, 0x1f, %o5
a00ab5e4:  9a 13 40 01  or  %o5, %g1, %o5
a00ab5e8:  82 13 20 04  or  %o4, 4, %g1
a00ab5ec:  da 22 c0 00  st  %o5, [ %o3 ]
a00ab5f0:  82 08 60 ff  and  %g1, 0xff, %g1
a00ab5f4:  c2 22 80 00  st  %g1, [ %o2 ]
a00ab5f8:  da 02 c0 00  ld  [ %o3 ], %o5
a00ab5fc:  c2 0a 60 05  ldub  [ %o1 + 5 ], %g1
a00ab600:  9a 0b 60 1f  and  %o5, 0x1f, %o5
a00ab604:  9a 13 40 01  or  %o5, %g1, %o5
a00ab608:  82 13 20 08  or  %o4, 8, %g1
a00ab60c:  da 22 c0 00  st  %o5, [ %o3 ]
a00ab610:  82 08 60 ff  and  %g1, 0xff, %g1
a00ab614:  c2 22 80 00  st  %g1, [ %o2 ]
a00ab618:  c2 02 c0 00  ld  [ %o3 ], %g1
a00ab61c:  da 0a 60 06  ldub  [ %o1 + 6 ], %o5
a00ab620:  82 08 60 1f  and  %g1, 0x1f, %g1
a00ab624:  82 10 40 0d  or  %g1, %o5, %g1
a00ab628:  98 13 20 10  or  %o4, 0x10, %o4
a00ab62c:  c2 22 c0 00  st  %g1, [ %o3 ]
a00ab630:  98 0b 20 ff  and  %o4, 0xff, %o4
a00ab634:  d8 22 80 00  st  %o4, [ %o2 ]
a00ab638:  c2 02 c0 00  ld  [ %o3 ], %g1
a00ab63c:  da 0a 60 07  ldub  [ %o1 + 7 ], %o5
a00ab640:  82 08 60 1f  and  %g1, 0x1f, %g1
a00ab644:  82 10 40 0d  or  %g1, %o5, %g1
a00ab648:  c2 22 c0 00  st  %g1, [ %o3 ]
a00ab64c:  30 80 00 08  b,a   0xa00ab66c
a00ab650:  c2 02 80 00  ld  [ %o2 ], %g1
a00ab654:  82 10 60 1f  or  %g1, 0x1f, %g1
a00ab658:  c2 22 80 00  st  %g1, [ %o2 ]
a00ab65c:  c2 02 c0 00  ld  [ %o3 ], %g1
a00ab660:  82 08 60 1f  and  %g1, 0x1f, %g1
a00ab664:  82 10 60 80  or  %g1, 0x80, %g1
a00ab668:  c2 22 c0 00  st  %g1, [ %o3 ]
a00ab66c:  81 c3 e0 08  retl
a00ab670:  01 00 00 00  nop
