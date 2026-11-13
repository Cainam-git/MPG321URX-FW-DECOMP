# leon2m FUN_a010a558 0xa010a558-0xa010a824 (716 bytes)
a010a558:  9d e3 bf 98  save  %sp, -104, %sp
a010a55c:  80 8e 20 ff  btst  0xff, %i0
a010a560:  02 80 00 af  be  0xa010a81c
a010a564:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010a568:  7f ff 53 02  call  0xa00df170
a010a56c:  90 16 20 b0  or  %i0, 0xb0, %o0	! 0x19acb0
a010a570:  29 2a 00 b5  sethi  %hi(0xa802d400), %l4
a010a574:  d2 05 22 a4  ld  [ %l4 + 0x2a4 ], %o1	! 0xa802d6a4
a010a578:  27 33 c0 79  sethi  %hi(0xcf01e400), %l3
a010a57c:  2b 33 c0 7a  sethi  %hi(0xcf01e800), %l5
a010a580:  f0 12 60 0a  lduh  [ %o1 + 0xa ], %i0
a010a584:  9e 14 e0 04  or  %l3, 4, %o7
a010a588:  a2 10 20 10  mov  0x10, %l1
a010a58c:  e2 23 c0 00  st  %l1, [ %o7 ]
a010a590:  a0 15 62 44  or  %l5, 0x244, %l0
a010a594:  a6 0e 20 ff  and  %i0, 0xff, %l3
a010a598:  e6 24 00 00  st  %l3, [ %l0 ]
a010a59c:  de 12 60 2c  lduh  [ %o1 + 0x2c ], %o7
a010a5a0:  a3 2e 20 10  sll  %i0, 0x10, %l1
a010a5a4:  96 15 62 48  or  %l5, 0x248, %o3
a010a5a8:  e8 12 60 32  lduh  [ %o1 + 0x32 ], %l4
a010a5ac:  91 34 60 18  srl  %l1, 0x18, %o0
a010a5b0:  a4 23 c0 18  sub  %o7, %i0, %l2
a010a5b4:  a1 2b e0 10  sll  %o7, 0x10, %l0
a010a5b8:  d0 22 c0 00  st  %o0, [ %o3 ]
a010a5bc:  82 15 62 4c  or  %l5, 0x24c, %g1
a010a5c0:  98 24 80 14  sub  %l2, %l4, %o4
a010a5c4:  95 34 60 10  srl  %l1, 0x10, %o2
a010a5c8:  9b 34 20 10  srl  %l0, 0x10, %o5
a010a5cc:  e4 12 60 30  lduh  [ %o1 + 0x30 ], %l2
a010a5d0:  e6 20 40 00  st  %l3, [ %g1 ]
a010a5d4:  9a 23 40 0a  sub  %o5, %o2, %o5
a010a5d8:  96 15 62 50  or  %l5, 0x250, %o3
a010a5dc:  98 23 00 12  sub  %o4, %l2, %o4
a010a5e0:  03 3f ff f8  sethi  %hi(0xffffe000), %g1
a010a5e4:  d4 12 60 22  lduh  [ %o1 + 0x22 ], %o2
a010a5e8:  d0 22 c0 00  st  %o0, [ %o3 ]
a010a5ec:  aa 2b 00 01  andn  %o4, %g1, %l5
a010a5f0:  80 a3 60 11  cmp  %o5, 0x11
a010a5f4:  14 80 00 7c  bg  0xa010a7e4
a010a5f8:  92 06 20 12  add  %i0, 0x12, %o1
a010a5fc:  17 33 c0 79  sethi  %hi(0xcf01e400), %o3
a010a600:  98 12 e2 84  or  %o3, 0x284, %o4	! 0xcf01e684
a010a604:  de 03 00 00  ld  [ %o4 ], %o7
a010a608:  90 13 e0 10  or  %o7, 0x10, %o0
a010a60c:  d0 23 00 00  st  %o0, [ %o4 ]
a010a610:  9e 12 e2 88  or  %o3, 0x288, %o7
a010a614:  c2 03 c0 00  ld  [ %o7 ], %g1
a010a618:  9a 10 60 10  or  %g1, 0x10, %o5
a010a61c:  da 23 c0 00  st  %o5, [ %o7 ]
a010a620:  91 2a a0 10  sll  %o2, 0x10, %o0
a010a624:  9e 12 e2 8c  or  %o3, 0x28c, %o7
a010a628:  95 32 20 10  srl  %o0, 0x10, %o2
a010a62c:  83 2a 60 10  sll  %o1, 0x10, %g1
a010a630:  99 34 20 10  srl  %l0, 0x10, %o4
a010a634:  d0 03 c0 00  ld  [ %o7 ], %o0
a010a638:  a0 5b 00 0a  smul  %o4, %o2, %l0
a010a63c:  9b 30 60 10  srl  %g1, 0x10, %o5
a010a640:  81 80 00 00  mov  %g0, %y
a010a644:  01 00 00 00  nop
a010a648:  01 00 00 00  nop
a010a64c:  01 00 00 00  nop
a010a650:  94 74 00 0d  udiv  %l0, %o5, %o2
a010a654:  92 0a 3f ef  and  %o0, -17, %o1
a010a658:  98 0a bf fe  and  %o2, -2, %o4
a010a65c:  11 33 c0 46  sethi  %hi(0xcf011800), %o0
a010a660:  d2 23 c0 00  st  %o1, [ %o7 ]
a010a664:  a1 34 60 10  srl  %l1, 0x10, %l0
a010a668:  94 12 22 80  or  %o0, 0x280, %o2
a010a66c:  92 23 00 18  sub  %o4, %i0, %o1
a010a670:  9a 0c 20 1f  and  %l0, 0x1f, %o5
a010a674:  d6 02 80 00  ld  [ %o2 ], %o3
a010a678:  82 10 20 20  mov  0x20, %g1
a010a67c:  b0 20 40 0d  sub  %g1, %o5, %i0
a010a680:  80 8a e0 01  btst  1, %o3
a010a684:  12 80 00 62  bne  0xa010a80c
a010a688:  a0 02 7f c0  add  %o1, -64, %l0
a010a68c:  d2 02 80 00  ld  [ %o2 ], %o1
a010a690:  80 8a 60 80  btst  0x80, %o1
a010a694:  12 80 00 04  bne  0xa010a6a4
a010a698:  90 12 22 d8  or  %o0, 0x2d8, %o0
a010a69c:  15 33 c0 47  sethi  %hi(0xcf011c00), %o2
a010a6a0:  90 12 a0 18  or  %o2, 0x18, %o0	! 0xcf011c18
a010a6a4:  7f ff a2 75  call  0xa00f3078
a010a6a8:  01 00 00 00  nop
a010a6ac:  9b 2a 20 10  sll  %o0, 0x10, %o5
a010a6b0:  97 33 60 10  srl  %o5, 0x10, %o3
a010a6b4:  90 10 00 0b  mov  %o3, %o0
a010a6b8:  93 2a 20 10  sll  %o0, 0x10, %o1
a010a6bc:  83 32 60 12  srl  %o1, 0x12, %g1
a010a6c0:  13 33 c0 7a  sethi  %hi(0xcf01e800), %o1
a010a6c4:  91 30 60 08  srl  %g1, 8, %o0
a010a6c8:  9a 08 60 ff  and  %g1, 0xff, %o5
a010a6cc:  9e 12 20 80  or  %o0, 0x80, %o7
a010a6d0:  98 12 62 c4  or  %o1, 0x2c4, %o4
a010a6d4:  da 23 00 00  st  %o5, [ %o4 ]
a010a6d8:  90 12 62 c0  or  %o1, 0x2c0, %o0
a010a6dc:  de 22 00 00  st  %o7, [ %o0 ]
a010a6e0:  9e 10 20 20  mov  0x20, %o7
a010a6e4:  96 12 62 80  or  %o1, 0x280, %o3
a010a6e8:  de 22 c0 00  st  %o7, [ %o3 ]
a010a6ec:  94 12 62 84  or  %o1, 0x284, %o2
a010a6f0:  c0 22 80 00  clr  [ %o2 ]
a010a6f4:  99 2c 20 10  sll  %l0, 0x10, %o4
a010a6f8:  82 0c 20 ff  and  %l0, 0xff, %g1
a010a6fc:  9a 12 62 88  or  %o1, 0x288, %o5
a010a700:  c2 23 40 00  st  %g1, [ %o5 ]
a010a704:  97 33 20 18  srl  %o4, 0x18, %o3
a010a708:  94 12 62 8c  or  %o1, 0x28c, %o2
a010a70c:  d6 22 80 00  st  %o3, [ %o2 ]
a010a710:  98 12 62 90  or  %o1, 0x290, %o4
a010a714:  de 23 00 00  st  %o7, [ %o4 ]
a010a718:  82 12 62 94  or  %o1, 0x294, %g1
a010a71c:  c0 20 40 00  clr  [ %g1 ]
a010a720:  a0 12 62 98  or  %o1, 0x298, %l0
a010a724:  e6 24 00 00  st  %l3, [ %l0 ]
a010a728:  96 12 62 9c  or  %o1, 0x29c, %o3
a010a72c:  9b 34 60 18  srl  %l1, 0x18, %o5
a010a730:  da 22 c0 00  st  %o5, [ %o3 ]
a010a734:  99 2c a0 10  sll  %l2, 0x10, %o4
a010a738:  94 0c a0 ff  and  %l2, 0xff, %o2
a010a73c:  9e 12 62 a0  or  %o1, 0x2a0, %o7
a010a740:  d4 23 c0 00  st  %o2, [ %o7 ]
a010a744:  83 33 20 18  srl  %o4, 0x18, %g1
a010a748:  a0 12 62 a4  or  %o1, 0x2a4, %l0
a010a74c:  c2 24 00 00  st  %g1, [ %l0 ]
a010a750:  e4 02 00 00  ld  [ %o0 ], %l2
a010a754:  80 8c a0 80  btst  0x80, %l2
a010a758:  02 80 00 25  be  0xa010a7ec
a010a75c:  91 2d 60 10  sll  %l5, 0x10, %o0
a010a760:  a0 12 62 a8  or  %o1, 0x2a8, %l0
a010a764:  94 10 20 ff  mov  0xff, %o2
a010a768:  d4 24 00 00  st  %o2, [ %l0 ]
a010a76c:  aa 12 62 ac  or  %o1, 0x2ac, %l5
a010a770:  a4 10 20 1f  mov  0x1f, %l2
a010a774:  e4 25 40 00  st  %l2, [ %l5 ]
a010a778:  2b 33 c0 7a  sethi  %hi(0xcf01e800), %l5
a010a77c:  93 2d 20 10  sll  %l4, 0x10, %o1
a010a780:  82 0d 20 ff  and  %l4, 0xff, %g1
a010a784:  a4 15 62 b0  or  %l5, 0x2b0, %l2
a010a788:  c2 24 80 00  st  %g1, [ %l2 ]
a010a78c:  9b 32 60 18  srl  %o1, 0x18, %o5
a010a790:  98 15 62 b4  or  %l5, 0x2b4, %o4
a010a794:  da 23 00 00  st  %o5, [ %o4 ]
a010a798:  90 15 62 b8  or  %l5, 0x2b8, %o0
a010a79c:  e6 22 00 00  st  %l3, [ %o0 ]
a010a7a0:  97 34 60 18  srl  %l1, 0x18, %o3
a010a7a4:  9e 15 62 bc  or  %l5, 0x2bc, %o7
a010a7a8:  d6 23 c0 00  st  %o3, [ %o7 ]
a010a7ac:  a4 15 61 c8  or  %l5, 0x1c8, %l2
a010a7b0:  d4 04 80 00  ld  [ %l2 ], %o2
a010a7b4:  a0 12 a0 10  or  %o2, 0x10, %l0
a010a7b8:  e0 24 80 00  st  %l0, [ %l2 ]
a010a7bc:  82 0e 20 ff  and  %i0, 0xff, %g1
a010a7c0:  29 33 c0 79  sethi  %hi(0xcf01e400), %l4
a010a7c4:  92 15 61 dc  or  %l5, 0x1dc, %o1
a010a7c8:  c2 22 40 00  st  %g1, [ %o1 ]
a010a7cc:  a6 10 20 c0  mov  0xc0, %l3
a010a7d0:  b0 15 22 60  or  %l4, 0x260, %i0
a010a7d4:  e6 26 00 00  st  %l3, [ %i0 ]
a010a7d8:  a2 15 22 64  or  %l4, 0x264, %l1
a010a7dc:  e6 24 40 00  st  %l3, [ %l1 ]
a010a7e0:  30 80 00 0f  b,a   0xa010a81c
a010a7e4:  10 bf ff 86  b  0xa010a5fc
a010a7e8:  92 10 00 0f  mov  %o7, %o1
a010a7ec:  98 12 62 a8  or  %o1, 0x2a8, %o4
a010a7f0:  9a 0d 60 ff  and  %l5, 0xff, %o5
a010a7f4:  da 23 00 00  st  %o5, [ %o4 ]
a010a7f8:  96 12 62 ac  or  %o1, 0x2ac, %o3
a010a7fc:  9f 32 20 18  srl  %o0, 0x18, %o7
a010a800:  de 22 c0 00  st  %o7, [ %o3 ]
a010a804:  10 bf ff de  b  0xa010a77c
a010a808:  2b 33 c0 7a  sethi  %hi(0xcf01e800), %l5
a010a80c:  7f ff ee 9a  call  0xa0106274
a010a810:  90 10 20 00  clr  %o0
a010a814:  10 bf ff aa  b  0xa010a6bc
a010a818:  93 2a 20 10  sll  %o0, 0x10, %o1
a010a81c:  81 c7 e0 08  ret
a010a820:  81 e8 00 00  restore
