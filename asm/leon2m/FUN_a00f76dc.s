# leon2m FUN_a00f76dc 0xa00f76dc-0xa00f7894 (440 bytes)
a00f76dc:  9d e3 bf 18  save  %sp, -232, %sp
a00f76e0:  39 33 c0 3b  sethi  %hi(0xcf00ec00), %i4
a00f76e4:  b4 17 22 c4  or  %i4, 0x2c4, %i2	! 0xcf00eec4
a00f76e8:  c2 06 80 00  ld  [ %i2 ], %g1
a00f76ec:  80 88 60 01  btst  1, %g1
a00f76f0:  02 80 00 0c  be  0xa00f7720
a00f76f4:  92 10 00 19  mov  %i1, %o1
a00f76f8:  80 8e 20 ff  btst  0xff, %i0
a00f76fc:  02 80 00 64  be  0xa00f788c
a00f7700:  b0 10 20 00  clr  %i0
a00f7704:  3b 33 c0 3b  sethi  %hi(0xcf00ec00), %i5
a00f7708:  b6 17 62 c4  or  %i5, 0x2c4, %i3	! 0xcf00eec4
a00f770c:  c2 06 c0 00  ld  [ %i3 ], %g1
a00f7710:  b8 10 60 01  or  %g1, 1, %i4
a00f7714:  f8 26 c0 00  st  %i4, [ %i3 ]
a00f7718:  10 80 00 5d  b  0xa00f788c
a00f771c:  b0 10 20 01  mov  1, %i0
a00f7720:  80 8e 20 ff  btst  0xff, %i0
a00f7724:  12 bf ff f9  bne  0xa00f7708
a00f7728:  3b 33 c0 3b  sethi  %hi(0xcf00ec00), %i5
a00f772c:  b0 17 20 84  or  %i4, 0x84, %i0
a00f7730:  f2 06 00 00  ld  [ %i0 ], %i1
a00f7734:  b0 17 22 80  or  %i4, 0x280, %i0
a00f7738:  c2 06 00 00  ld  [ %i0 ], %g1
a00f773c:  b6 0e 60 03  and  %i1, 3, %i3
a00f7740:  ba 06 c0 1b  add  %i3, %i3, %i5
a00f7744:  b2 08 60 f9  and  %g1, 0xf9, %i1
a00f7748:  82 16 40 1d  or  %i1, %i5, %g1
a00f774c:  c2 26 00 00  st  %g1, [ %i0 ]
a00f7750:  b8 17 22 c0  or  %i4, 0x2c0, %i4
a00f7754:  f6 07 00 00  ld  [ %i4 ], %i3
a00f7758:  b2 0e ff df  and  %i3, -33, %i1
a00f775c:  f2 27 00 00  st  %i1, [ %i4 ]
a00f7760:  f0 06 80 00  ld  [ %i2 ], %i0
a00f7764:  ba 0e 20 af  and  %i0, 0xaf, %i5
a00f7768:  fa 26 80 00  st  %i5, [ %i2 ]
a00f776c:  b8 10 20 00  clr  %i4
a00f7770:  ba 10 20 00  clr  %i5
a00f7774:  9a 07 bf f8  add  %fp, -8, %o5
a00f7778:  b7 2f 60 02  sll  %i5, 2, %i3
a00f777c:  b8 07 20 01  inc  %i4
a00f7780:  b4 06 c0 0d  add  %i3, %o5, %i2
a00f7784:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00f7788:  80 a7 60 1f  cmp  %i5, 0x1f
a00f778c:  08 bf ff fb  bleu  0xa00f7778
a00f7790:  c0 26 bf 80  clr  [ %i2 + -128 ]
a00f7794:  39 33 c0 3b  sethi  %hi(0xcf00ec00), %i4
a00f7798:  b6 17 22 c0  or  %i4, 0x2c0, %i3	! 0xcf00eec0
a00f779c:  f4 06 c0 00  ld  [ %i3 ], %i2
a00f77a0:  b1 36 a0 02  srl  %i2, 2, %i0
a00f77a4:  b2 10 20 04  mov  4, %i1
a00f77a8:  ba 0e 20 03  and  %i0, 3, %i5
a00f77ac:  83 2e 40 1d  sll  %i1, %i5, %g1
a00f77b0:  9e 08 60 ff  and  %g1, 0xff, %o7
a00f77b4:  b2 17 22 c8  or  %i4, 0x2c8, %i1
a00f77b8:  98 10 20 00  clr  %o4
a00f77bc:  82 10 20 00  clr  %g1
a00f77c0:  94 17 22 84  or  %i4, 0x284, %o2
a00f77c4:  96 10 20 01  mov  1, %o3
a00f77c8:  b9 2a c0 01  sll  %o3, %g1, %i4
a00f77cc:  f8 22 80 00  st  %i4, [ %o2 ]
a00f77d0:  b4 10 20 00  clr  %i2
a00f77d4:  b6 10 20 00  clr  %i3
a00f77d8:  83 2e e0 02  sll  %i3, 2, %g1
a00f77dc:  f8 06 40 00  ld  [ %i1 ], %i4
a00f77e0:  fa 06 40 00  ld  [ %i1 ], %i5
a00f77e4:  b0 00 40 0d  add  %g1, %o5, %i0
a00f77e8:  c2 06 40 00  ld  [ %i1 ], %g1
a00f77ec:  ba 0f 60 ff  and  %i5, 0xff, %i5
a00f77f0:  82 08 60 ff  and  %g1, 0xff, %g1
a00f77f4:  bb 2f 60 08  sll  %i5, 8, %i5
a00f77f8:  83 28 60 10  sll  %g1, 0x10, %g1
a00f77fc:  b4 06 a0 01  inc  %i2
a00f7800:  80 a6 c0 0f  cmp  %i3, %o7
a00f7804:  b8 0f 20 ff  and  %i4, 0xff, %i4
a00f7808:  82 10 40 1d  or  %g1, %i5, %g1
a00f780c:  b6 0e a0 ff  and  %i2, 0xff, %i3
a00f7810:  1a 80 00 05  bcc  0xa00f7824
a00f7814:  ba 10 40 1c  or  %g1, %i4, %i5
a00f7818:  c2 06 3f 80  ld  [ %i0 + -128 ], %g1
a00f781c:  b8 00 40 1d  add  %g1, %i5, %i4
a00f7820:  f8 26 3f 80  st  %i4, [ %i0 + -128 ]
a00f7824:  80 a6 e0 1f  cmp  %i3, 0x1f
a00f7828:  08 bf ff ed  bleu  0xa00f77dc
a00f782c:  83 2e e0 02  sll  %i3, 2, %g1
a00f7830:  98 03 20 01  inc  %o4
a00f7834:  82 0b 20 ff  and  %o4, 0xff, %g1
a00f7838:  80 a0 60 07  cmp  %g1, 7
a00f783c:  08 bf ff e4  bleu  0xa00f77cc
a00f7840:  b9 2a c0 01  sll  %o3, %g1, %i4
a00f7844:  80 a3 e0 00  cmp  %o7, 0
a00f7848:  02 bf ff af  be  0xa00f7704
a00f784c:  b6 10 20 00  clr  %i3
a00f7850:  ba 10 20 00  clr  %i5
a00f7854:  b3 2f 60 02  sll  %i5, 2, %i1
a00f7858:  b4 06 40 0d  add  %i1, %o5, %i2
a00f785c:  b6 06 e0 01  inc  %i3
a00f7860:  f0 06 bf 80  ld  [ %i2 + -128 ], %i0
a00f7864:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00f7868:  80 a7 40 0f  cmp  %i5, %o7
a00f786c:  0a bf ff fa  bcs  0xa00f7854
a00f7870:  f0 22 40 19  st  %i0, [ %o1 + %i1 ]
a00f7874:  3b 33 c0 3b  sethi  %hi(0xcf00ec00), %i5
a00f7878:  b6 17 62 c4  or  %i5, 0x2c4, %i3	! 0xcf00eec4
a00f787c:  c2 06 c0 00  ld  [ %i3 ], %g1
a00f7880:  b8 10 60 01  or  %g1, 1, %i4
a00f7884:  f8 26 c0 00  st  %i4, [ %i3 ]
a00f7888:  b0 10 20 01  mov  1, %i0
a00f788c:  81 c7 e0 08  ret
a00f7890:  81 e8 00 00  restore
