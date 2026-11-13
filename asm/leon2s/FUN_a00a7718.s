# leon2s FUN_a00a7718 0xa00a7718-0xa00a78b4 (412 bytes)
a00a7718:  9d e3 bf 98  save  %sp, -104, %sp
a00a771c:  03 33 c0 f4  sethi  %hi(0xcf03d000), %g1
a00a7720:  a0 10 60 14  or  %g1, 0x14, %l0	! 0xcf03d014
a00a7724:  d6 04 00 00  ld  [ %l0 ], %o3
a00a7728:  a2 10 60 18  or  %g1, 0x18, %l1
a00a772c:  d8 04 40 00  ld  [ %l1 ], %o4
a00a7730:  92 10 60 1c  or  %g1, 0x1c, %o1
a00a7734:  da 02 40 00  ld  [ %o1 ], %o5
a00a7738:  90 10 60 20  or  %g1, 0x20, %o0
a00a773c:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a00a7740:  82 17 60 2c  or  %i5, 0x2c, %g1	! 0xcf01142c
a00a7744:  de 02 00 00  ld  [ %o0 ], %o7
a00a7748:  f8 00 40 00  ld  [ %g1 ], %i4
a00a774c:  ba 17 60 30  or  %i5, 0x30, %i5
a00a7750:  c2 07 40 00  ld  [ %i5 ], %g1
a00a7754:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a7758:  94 10 00 1a  mov  %i2, %o2
a00a775c:  a4 10 00 1c  mov  %i4, %l2
a00a7760:  a6 10 00 01  mov  %g1, %l3
a00a7764:  80 a6 20 01  cmp  %i0, 1
a00a7768:  18 80 00 51  bgu  0xa00a78ac
a00a776c:  b4 10 00 19  mov  %i1, %i2
a00a7770:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00a7774:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00
a00a7778:  82 0e 40 01  and  %i1, %g1, %g1
a00a777c:  83 38 60 08  sra  %g1, 8, %g1
a00a7780:  ba 10 20 01  mov  1, %i5
a00a7784:  80 a6 20 00  cmp  %i0, 0
a00a7788:  02 80 00 06  be  0xa00a77a0
a00a778c:  83 2f 40 01  sll  %i5, %g1, %g1
a00a7790:  80 a6 20 01  cmp  %i0, 1
a00a7794:  02 80 00 0a  be  0xa00a77bc
a00a7798:  80 a6 20 00  cmp  %i0, 0
a00a779c:  30 80 00 0f  b,a   0xa00a77d8
a00a77a0:  ba 08 60 ff  and  %g1, 0xff, %i5
a00a77a4:  83 30 60 08  srl  %g1, 8, %g1
a00a77a8:  fa 24 00 00  st  %i5, [ %l0 ]
a00a77ac:  82 08 60 01  and  %g1, 1, %g1
a00a77b0:  c2 24 40 00  st  %g1, [ %l1 ]
a00a77b4:  10 80 00 0c  b  0xa00a77e4
a00a77b8:  ba 10 20 85  mov  0x85, %i5
a00a77bc:  ba 08 60 ff  and  %g1, 0xff, %i5
a00a77c0:  83 30 60 08  srl  %g1, 8, %g1
a00a77c4:  fa 22 40 00  st  %i5, [ %o1 ]
a00a77c8:  82 08 60 01  and  %g1, 1, %g1
a00a77cc:  c2 22 00 00  st  %g1, [ %o0 ]
a00a77d0:  10 80 00 05  b  0xa00a77e4
a00a77d4:  ba 10 20 86  mov  0x86, %i5
a00a77d8:  32 80 00 03  bne,a   0xa00a77e4
a00a77dc:  ba 10 20 86  mov  0x86, %i5
a00a77e0:  ba 10 20 85  mov  0x85, %i5
a00a77e4:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00a77e8:  82 10 60 2c  or  %g1, 0x2c, %g1	! 0xcf01142c
a00a77ec:  fa 20 40 00  st  %i5, [ %g1 ]
a00a77f0:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a00a77f4:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00a77f8:  b8 17 60 30  or  %i5, 0x30, %i4
a00a77fc:  82 0e a0 ff  and  %i2, 0xff, %g1
a00a7800:  c2 27 00 00  st  %g1, [ %i4 ]
a00a7804:  ba 17 60 34  or  %i5, 0x34, %i5
a00a7808:  c2 07 40 00  ld  [ %i5 ], %g1
a00a780c:  82 0e e0 ff  and  %i3, 0xff, %g1
a00a7810:  fa 07 40 00  ld  [ %i5 ], %i5
a00a7814:  80 a0 60 01  cmp  %g1, 1
a00a7818:  02 80 00 03  be  0xa00a7824
a00a781c:  b6 17 40 0a  or  %i5, %o2, %i3
a00a7820:  b6 2f 40 0a  andn  %i5, %o2, %i3
a00a7824:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7828:  b8 06 00 18  add  %i0, %i0, %i4
a00a782c:  bb 2e a0 10  sll  %i2, 0x10, %i5
a00a7830:  82 10 61 84  or  %g1, 0x184, %g1
a00a7834:  c2 10 40 1c  lduh  [ %g1 + %i4 ], %g1
a00a7838:  bb 37 60 10  srl  %i5, 0x10, %i5
a00a783c:  82 00 40 1d  add  %g1, %i5, %g1
a00a7840:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a7844:  83 28 60 02  sll  %g1, 2, %g1
a00a7848:  82 10 40 1d  or  %g1, %i5, %g1
a00a784c:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00a7850:  fa 20 40 00  st  %i5, [ %g1 ]
a00a7854:  39 33 c0 f4  sethi  %hi(0xcf03d000), %i4
a00a7858:  82 17 20 14  or  %i4, 0x14, %g1	! 0xcf03d014
a00a785c:  ba 0a e0 ff  and  %o3, 0xff, %i5
a00a7860:  fa 20 40 00  st  %i5, [ %g1 ]
a00a7864:  82 17 20 18  or  %i4, 0x18, %g1
a00a7868:  ba 0b 20 ff  and  %o4, 0xff, %i5
a00a786c:  fa 20 40 00  st  %i5, [ %g1 ]
a00a7870:  82 17 20 1c  or  %i4, 0x1c, %g1
a00a7874:  ba 0b 60 ff  and  %o5, 0xff, %i5
a00a7878:  fa 20 40 00  st  %i5, [ %g1 ]
a00a787c:  b8 17 20 20  or  %i4, 0x20, %i4
a00a7880:  82 0b e0 ff  and  %o7, 0xff, %g1
a00a7884:  c2 27 00 00  st  %g1, [ %i4 ]
a00a7888:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a00a788c:  82 17 60 2c  or  %i5, 0x2c, %g1	! 0xcf01142c
a00a7890:  b8 0c a0 ff  and  %l2, 0xff, %i4
a00a7894:  f8 20 40 00  st  %i4, [ %g1 ]
a00a7898:  82 17 60 30  or  %i5, 0x30, %g1
a00a789c:  b8 0c e0 ff  and  %l3, 0xff, %i4
a00a78a0:  f8 20 40 00  st  %i4, [ %g1 ]
a00a78a4:  ba 17 60 34  or  %i5, 0x34, %i5
a00a78a8:  c2 07 40 00  ld  [ %i5 ], %g1
a00a78ac:  81 c7 e0 08  ret
a00a78b0:  81 e8 00 00  restore
