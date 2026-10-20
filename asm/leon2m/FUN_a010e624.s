# leon2m FUN_a010e624 0xa010e624-0xa010e8ec (712 bytes)
a010e624:  9d e3 bf 98  save  %sp, -104, %sp
a010e628:  9e 0e 20 ff  and  %i0, 0xff, %o7
a010e62c:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010e630:  9a 10 00 1a  mov  %i2, %o5
a010e634:  96 10 00 1b  mov  %i3, %o3
a010e638:  80 a3 e0 01  cmp  %o7, 1
a010e63c:  02 80 00 a7  be  0xa010e8d8
a010e640:  82 10 63 04  or  %g1, 0x304, %g1
a010e644:  d6 28 60 3a  stb  %o3, [ %g1 + 0x3a ]
a010e648:  f2 28 60 38  stb  %i1, [ %g1 + 0x38 ]
a010e64c:  da 28 60 39  stb  %o5, [ %g1 + 0x39 ]
a010e650:  80 a3 e0 01  cmp  %o7, 1
a010e654:  08 80 00 03  bleu  0xa010e660
a010e658:  82 10 00 18  mov  %i0, %g1
a010e65c:  82 10 20 00  clr  %g1
a010e660:  ba 0e 60 ff  and  %i1, 0xff, %i5
a010e664:  b4 08 60 ff  and  %g1, 0xff, %i2
a010e668:  b7 2f 60 0a  sll  %i5, 0xa, %i3
a010e66c:  83 2e a0 02  sll  %i2, 2, %g1
a010e670:  19 00 06 6b  sethi  %hi(0x19ac00), %o4
a010e674:  b8 26 c0 1d  sub  %i3, %i5, %i4
a010e678:  33 14 7a e1  sethi  %hi(0x51eb8400), %i1
a010e67c:  b4 13 22 c4  or  %o4, 0x2c4, %i2
a010e680:  b8 07 20 32  add  %i4, 0x32, %i4
a010e684:  ba 16 61 1f  or  %i1, 0x11f, %i5
a010e688:  f6 06 80 01  ld  [ %i2 + %g1 ], %i3
a010e68c:  80 57 00 1d  umul  %i4, %i5, %g0
a010e690:  b3 40 00 00  rd  %y, %i1
a010e694:  c2 06 e0 24  ld  [ %i3 + 0x24 ], %g1
a010e698:  ba 08 7c 00  and  %g1, -1024, %i5
a010e69c:  b9 36 60 05  srl  %i1, 5, %i4
a010e6a0:  80 a3 e0 01  cmp  %o7, 1
a010e6a4:  08 80 00 7f  bleu  0xa010e8a0
a010e6a8:  b2 17 40 1c  or  %i5, %i4, %i1
a010e6ac:  b6 10 00 1a  mov  %i2, %i3
a010e6b0:  b8 10 20 00  clr  %i4
a010e6b4:  83 2f 20 02  sll  %i4, 2, %g1
a010e6b8:  f4 06 c0 01  ld  [ %i3 + %g1 ], %i2
a010e6bc:  b8 07 20 01  inc  %i4
a010e6c0:  f2 26 a0 24  st  %i1, [ %i2 + 0x24 ]
a010e6c4:  80 a7 20 01  cmp  %i4, 1
a010e6c8:  08 bf ff fc  bleu  0xa010e6b8
a010e6cc:  83 2f 20 02  sll  %i4, 2, %g1
a010e6d0:  80 a3 e0 01  cmp  %o7, 1
a010e6d4:  08 80 00 6d  bleu  0xa010e888
a010e6d8:  15 00 06 6b  sethi  %hi(0x19ac00), %o2
a010e6dc:  b8 10 20 00  clr  %i4
a010e6e0:  b6 12 a2 bc  or  %o2, 0x2bc, %i3
a010e6e4:  b5 2f 20 02  sll  %i4, 2, %i2
a010e6e8:  fa 06 c0 1a  ld  [ %i3 + %i2 ], %i5
a010e6ec:  b8 07 20 01  inc  %i4
a010e6f0:  f2 27 60 24  st  %i1, [ %i5 + 0x24 ]
a010e6f4:  80 a7 20 01  cmp  %i4, 1
a010e6f8:  08 bf ff fc  bleu  0xa010e6e8
a010e6fc:  b5 2f 20 02  sll  %i4, 2, %i2
a010e700:  80 a3 e0 01  cmp  %o7, 1
a010e704:  08 80 00 03  bleu  0xa010e710
a010e708:  82 10 00 18  mov  %i0, %g1
a010e70c:  82 10 20 00  clr  %g1
a010e710:  ba 0b 60 ff  and  %o5, 0xff, %i5
a010e714:  b2 08 60 ff  and  %g1, 0xff, %i1
a010e718:  b7 2f 60 0a  sll  %i5, 0xa, %i3
a010e71c:  83 2e 60 02  sll  %i1, 2, %g1
a010e720:  b8 26 c0 1d  sub  %i3, %i5, %i4
a010e724:  35 14 7a e1  sethi  %hi(0x51eb8400), %i2
a010e728:  b2 13 22 c4  or  %o4, 0x2c4, %i1
a010e72c:  b8 07 20 32  add  %i4, 0x32, %i4
a010e730:  ba 16 a1 1f  or  %i2, 0x11f, %i5
a010e734:  f6 06 40 01  ld  [ %i1 + %g1 ], %i3
a010e738:  80 57 00 1d  umul  %i4, %i5, %g0
a010e73c:  b5 40 00 00  rd  %y, %i2
a010e740:  c2 06 e0 28  ld  [ %i3 + 0x28 ], %g1
a010e744:  ba 08 7c 00  and  %g1, -1024, %i5
a010e748:  b9 36 a0 05  srl  %i2, 5, %i4
a010e74c:  80 a3 e0 01  cmp  %o7, 1
a010e750:  08 80 00 49  bleu  0xa010e874
a010e754:  b4 17 40 1c  or  %i5, %i4, %i2
a010e758:  b6 10 00 19  mov  %i1, %i3
a010e75c:  b8 10 20 00  clr  %i4
a010e760:  83 2f 20 02  sll  %i4, 2, %g1
a010e764:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010e768:  b8 07 20 01  inc  %i4
a010e76c:  f4 26 60 28  st  %i2, [ %i1 + 0x28 ]
a010e770:  80 a7 20 01  cmp  %i4, 1
a010e774:  08 bf ff fc  bleu  0xa010e764
a010e778:  83 2f 20 02  sll  %i4, 2, %g1
a010e77c:  80 a3 e0 01  cmp  %o7, 1
a010e780:  08 80 00 38  bleu  0xa010e860
a010e784:  ba 12 a2 bc  or  %o2, 0x2bc, %i5
a010e788:  3b 00 06 6b  sethi  %hi(0x19ac00), %i5
a010e78c:  b6 17 62 bc  or  %i5, 0x2bc, %i3	! 0x19aebc
a010e790:  b8 10 20 00  clr  %i4
a010e794:  83 2f 20 02  sll  %i4, 2, %g1
a010e798:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010e79c:  b8 07 20 01  inc  %i4
a010e7a0:  f4 26 60 28  st  %i2, [ %i1 + 0x28 ]
a010e7a4:  80 a7 20 01  cmp  %i4, 1
a010e7a8:  08 bf ff fc  bleu  0xa010e798
a010e7ac:  83 2f 20 02  sll  %i4, 2, %g1
a010e7b0:  80 a3 e0 01  cmp  %o7, 1
a010e7b4:  38 80 00 02  bgu,a   0xa010e7bc
a010e7b8:  b0 10 20 00  clr  %i0
a010e7bc:  b8 0a e0 ff  and  %o3, 0xff, %i4
a010e7c0:  b6 0e 20 ff  and  %i0, 0xff, %i3
a010e7c4:  b5 2f 20 0a  sll  %i4, 0xa, %i2
a010e7c8:  b0 26 80 1c  sub  %i2, %i4, %i0
a010e7cc:  bb 2e e0 02  sll  %i3, 2, %i5
a010e7d0:  03 14 7a e1  sethi  %hi(0x51eb8400), %g1
a010e7d4:  b4 13 22 c4  or  %o4, 0x2c4, %i2
a010e7d8:  b2 10 61 1f  or  %g1, 0x11f, %i1
a010e7dc:  f6 06 80 1d  ld  [ %i2 + %i5 ], %i3
a010e7e0:  b8 06 20 32  add  %i0, 0x32, %i4
a010e7e4:  80 57 00 19  umul  %i4, %i1, %g0
a010e7e8:  b1 40 00 00  rd  %y, %i0
a010e7ec:  fa 06 e0 2c  ld  [ %i3 + 0x2c ], %i5
a010e7f0:  82 0f 7c 00  and  %i5, -1024, %g1
a010e7f4:  b3 36 20 05  srl  %i0, 5, %i1
a010e7f8:  80 a3 e0 01  cmp  %o7, 1
a010e7fc:  08 80 00 32  bleu  0xa010e8c4
a010e800:  b0 10 40 19  or  %g1, %i1, %i0
a010e804:  b6 10 00 1a  mov  %i2, %i3
a010e808:  b8 10 20 00  clr  %i4
a010e80c:  83 2f 20 02  sll  %i4, 2, %g1
a010e810:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010e814:  b8 07 20 01  inc  %i4
a010e818:  f0 26 60 2c  st  %i0, [ %i1 + 0x2c ]
a010e81c:  80 a7 20 01  cmp  %i4, 1
a010e820:  08 bf ff fc  bleu  0xa010e810
a010e824:  83 2f 20 02  sll  %i4, 2, %g1
a010e828:  80 a3 e0 01  cmp  %o7, 1
a010e82c:  08 80 00 22  bleu  0xa010e8b4
a010e830:  b6 12 a2 bc  or  %o2, 0x2bc, %i3
a010e834:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a010e838:  b6 16 a2 bc  or  %i2, 0x2bc, %i3	! 0x19aebc
a010e83c:  b8 10 20 00  clr  %i4
a010e840:  83 2f 20 02  sll  %i4, 2, %g1
a010e844:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010e848:  b8 07 20 01  inc  %i4
a010e84c:  f0 26 60 2c  st  %i0, [ %i1 + 0x2c ]
a010e850:  80 a7 20 01  cmp  %i4, 1
a010e854:  08 bf ff fc  bleu  0xa010e844
a010e858:  83 2f 20 02  sll  %i4, 2, %g1
a010e85c:  30 80 00 22  b,a   0xa010e8e4
a010e860:  b7 2b e0 02  sll  %o7, 2, %i3
a010e864:  f8 07 40 1b  ld  [ %i5 + %i3 ], %i4
a010e868:  f4 27 20 28  st  %i2, [ %i4 + 0x28 ]
a010e86c:  10 bf ff d2  b  0xa010e7b4
a010e870:  80 a3 e0 01  cmp  %o7, 1
a010e874:  b7 2b e0 02  sll  %o7, 2, %i3
a010e878:  f8 06 40 1b  ld  [ %i1 + %i3 ], %i4
a010e87c:  f4 27 20 28  st  %i2, [ %i4 + 0x28 ]
a010e880:  10 bf ff c0  b  0xa010e780
a010e884:  80 a3 e0 01  cmp  %o7, 1
a010e888:  82 12 a2 bc  or  %o2, 0x2bc, %g1
a010e88c:  b7 2b e0 02  sll  %o7, 2, %i3
a010e890:  f8 00 40 1b  ld  [ %g1 + %i3 ], %i4
a010e894:  f2 27 20 24  st  %i1, [ %i4 + 0x24 ]
a010e898:  10 bf ff 9b  b  0xa010e704
a010e89c:  80 a3 e0 01  cmp  %o7, 1
a010e8a0:  b7 2b e0 02  sll  %o7, 2, %i3
a010e8a4:  f8 06 80 1b  ld  [ %i2 + %i3 ], %i4
a010e8a8:  f2 27 20 24  st  %i1, [ %i4 + 0x24 ]
a010e8ac:  10 bf ff 8a  b  0xa010e6d4
a010e8b0:  80 a3 e0 01  cmp  %o7, 1
a010e8b4:  bb 2b e0 02  sll  %o7, 2, %i5
a010e8b8:  f8 06 c0 1d  ld  [ %i3 + %i5 ], %i4
a010e8bc:  f0 27 20 2c  st  %i0, [ %i4 + 0x2c ]
a010e8c0:  30 80 00 09  b,a   0xa010e8e4
a010e8c4:  b7 2b e0 02  sll  %o7, 2, %i3
a010e8c8:  fa 06 80 1b  ld  [ %i2 + %i3 ], %i5
a010e8cc:  f0 27 60 2c  st  %i0, [ %i5 + 0x2c ]
a010e8d0:  10 bf ff d7  b  0xa010e82c
a010e8d4:  80 a3 e0 01  cmp  %o7, 1
a010e8d8:  35 2a 00 b6  sethi  %hi(0xa802d800), %i2
a010e8dc:  10 bf ff 5a  b  0xa010e644
a010e8e0:  82 16 a0 04  or  %i2, 4, %g1	! 0xa802d804
a010e8e4:  81 c7 e0 08  ret
a010e8e8:  81 e8 00 00  restore
