# leon2m FUN_a008e650 0xa008e650-0xa008e7a8 (344 bytes)
a008e650:  9d e3 bf 98  save  %sp, -104, %sp
a008e654:  40 02 5e f2  call  0xa012621c
a008e658:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a008e65c:  a2 0a 20 ff  and  %o0, 0xff, %l1
a008e660:  80 a4 60 00  cmp  %l1, 0
a008e664:  02 80 00 19  be  0xa008e6c8
a008e668:  9e 10 20 00  clr  %o7
a008e66c:  03 00 04 01  sethi  %hi(0x100400), %g1
a008e670:  94 10 61 3f  or  %g1, 0x13f, %o2	! 0x10053f
a008e674:  96 10 20 00  clr  %o3
a008e678:  9a 10 20 00  clr  %o5
a008e67c:  98 03 40 0d  add  %o5, %o5, %o4
a008e680:  96 02 e0 01  inc  %o3
a008e684:  d2 0a 80 0c  ldub  [ %o2 + %o4 ], %o1
a008e688:  80 8a 40 08  btst  %o1, %o0
a008e68c:  12 80 00 34  bne  0xa008e75c
a008e690:  9a 0a e0 ff  and  %o3, 0xff, %o5
a008e694:  80 a3 60 05  cmp  %o5, 5
a008e698:  08 bf ff fa  bleu  0xa008e680
a008e69c:  98 03 40 0d  add  %o5, %o5, %o4
a008e6a0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a008e6a4:  96 14 22 90  or  %l0, 0x290, %o3	! 0xa802d290
a008e6a8:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a008e6ac:  15 00 00 15  sethi  %hi(0x5400), %o2
a008e6b0:  98 14 23 f4  or  %l0, 0x3f4, %o4
a008e6b4:  da 12 e1 f6  lduh  [ %o3 + 0x1f6 ], %o5
a008e6b8:  90 12 a1 aa  or  %o2, 0x1aa, %o0
a008e6bc:  80 a3 40 08  cmp  %o5, %o0
a008e6c0:  02 80 00 0e  be  0xa008e6f8
a008e6c4:  de 2b 20 06  stb  %o7, [ %o4 + 6 ]
a008e6c8:  de 14 23 f4  lduh  [ %l0 + 0x3f4 ], %o7
a008e6cc:  80 8b e8 00  btst  0x800, %o7
a008e6d0:  22 80 00 32  be,a   0xa008e798
a008e6d4:  e2 14 23 f4  lduh  [ %l0 + 0x3f4 ], %l1
a008e6d8:  80 a4 60 02  cmp  %l1, 2
a008e6dc:  02 80 00 1a  be  0xa008e744
a008e6e0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a008e6e4:  d2 03 22 90  ld  [ %o4 + 0x290 ], %o1	! 0xa802d290
a008e6e8:  17 00 00 10  sethi  %hi(0x4000), %o3
a008e6ec:  90 2a 40 0b  andn  %o1, %o3, %o0
a008e6f0:  10 80 00 29  b  0xa008e794
a008e6f4:  d0 23 22 90  st  %o0, [ %o4 + 0x290 ]
a008e6f8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a008e6fc:  92 13 22 74  or  %o4, 0x274, %o1	! 0xa802d274
a008e700:  da 0a 60 10  ldub  [ %o1 + 0x10 ], %o5
a008e704:  82 0b 40 0f  and  %o5, %o7, %g1
a008e708:  80 88 60 ff  btst  0xff, %g1
a008e70c:  32 bf ff f0  bne,a   0xa008e6cc
a008e710:  de 14 23 f4  lduh  [ %l0 + 0x3f4 ], %o7
a008e714:  d0 0a e1 d5  ldub  [ %o3 + 0x1d5 ], %o0
a008e718:  80 a2 20 00  cmp  %o0, 0
a008e71c:  32 bf ff ec  bne,a   0xa008e6cc
a008e720:  de 14 23 f4  lduh  [ %l0 + 0x3f4 ], %o7
a008e724:  96 13 40 0f  or  %o5, %o7, %o3
a008e728:  d6 2a 60 10  stb  %o3, [ %o1 + 0x10 ]
a008e72c:  94 10 22 e0  mov  0x2e0, %o2
a008e730:  96 10 20 1c  mov  0x1c, %o3
a008e734:  40 02 f1 e7  call  0xa014aed0
a008e738:  90 10 20 30  mov  0x30, %o0
a008e73c:  10 bf ff e4  b  0xa008e6cc
a008e740:  de 14 23 f4  lduh  [ %l0 + 0x3f4 ], %o7
a008e744:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a008e748:  d4 04 62 90  ld  [ %l1 + 0x290 ], %o2	! 0xa802d290
a008e74c:  03 00 00 10  sethi  %hi(0x4000), %g1
a008e750:  9a 12 80 01  or  %o2, %g1, %o5
a008e754:  10 80 00 10  b  0xa008e794
a008e758:  da 24 62 90  st  %o5, [ %l1 + 0x290 ]
a008e75c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a008e760:  92 03 00 0a  add  %o4, %o2, %o1
a008e764:  96 14 22 90  or  %l0, 0x290, %o3
a008e768:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a008e76c:  15 00 00 15  sethi  %hi(0x5400), %o2
a008e770:  de 0a 60 01  ldub  [ %o1 + 1 ], %o7
a008e774:  98 14 23 f4  or  %l0, 0x3f4, %o4
a008e778:  da 12 e1 f6  lduh  [ %o3 + 0x1f6 ], %o5
a008e77c:  90 12 a1 aa  or  %o2, 0x1aa, %o0
a008e780:  80 a3 40 08  cmp  %o5, %o0
a008e784:  12 bf ff d1  bne  0xa008e6c8
a008e788:  de 2b 20 06  stb  %o7, [ %o4 + 6 ]
a008e78c:  10 bf ff dc  b  0xa008e6fc
a008e790:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a008e794:  e2 14 23 f4  lduh  [ %l0 + 0x3f4 ], %l1
a008e798:  9e 0c 77 ff  and  %l1, -2049, %o7
a008e79c:  de 34 23 f4  sth  %o7, [ %l0 + 0x3f4 ]
a008e7a0:  81 c7 e0 08  ret
a008e7a4:  81 e8 00 00  restore
