# leon2s FUN_a00916a8 0xa00916a8-0xa00918ec (580 bytes)
a00916a8:  9d e3 bf 98  save  %sp, -104, %sp
a00916ac:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00916b0:  83 2e 20 03  sll  %i0, 3, %g1
a00916b4:  82 20 40 18  sub  %g1, %i0, %g1
a00916b8:  3b 2a 01 f5  sethi  %hi(0xa807d400), %i5
a00916bc:  96 17 61 80  or  %i5, 0x180, %o3	! 0xa807d580
a00916c0:  99 28 60 02  sll  %g1, 2, %o4
a00916c4:  9a 03 00 0b  add  %o4, %o3, %o5
a00916c8:  f8 03 60 10  ld  [ %o5 + 0x10 ], %i4
a00916cc:  80 8f 20 04  btst  4, %i4
a00916d0:  02 80 00 85  be  0xa00918e4
a00916d4:  bb 2e 20 02  sll  %i0, 2, %i5
a00916d8:  ba 07 40 18  add  %i5, %i0, %i5
a00916dc:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00916e0:  82 10 60 fc  or  %g1, 0xfc, %g1	! 0xa807a8fc
a00916e4:  bb 2f 60 02  sll  %i5, 2, %i5
a00916e8:  de 10 40 1d  lduh  [ %g1 + %i5 ], %o7
a00916ec:  b0 07 40 01  add  %i5, %g1, %i0
a00916f0:  fa 0e 20 03  ldub  [ %i0 + 3 ], %i5
a00916f4:  82 0f 3f fb  and  %i4, -5, %g1
a00916f8:  c2 23 60 10  st  %g1, [ %o5 + 0x10 ]
a00916fc:  fa 2b 60 01  stb  %i5, [ %o5 + 1 ]
a0091700:  b5 2b e0 10  sll  %o7, 0x10, %i2
a0091704:  33 1f ff ff  sethi  %hi(0x7ffffc00), %i1
a0091708:  fa 02 c0 0c  ld  [ %o3 + %o4 ], %i5
a009170c:  b2 16 63 ff  or  %i1, 0x3ff, %i1
a0091710:  83 36 a0 1e  srl  %i2, 0x1e, %g1
a0091714:  83 28 60 1f  sll  %g1, 0x1f, %g1
a0091718:  ba 0f 40 19  and  %i5, %i1, %i5
a009171c:  ba 17 40 01  or  %i5, %g1, %i5
a0091720:  fa 22 c0 0c  st  %i5, [ %o3 + %o4 ]
a0091724:  c2 16 20 04  lduh  [ %i0 + 4 ], %g1
a0091728:  c2 23 60 08  st  %g1, [ %o5 + 8 ]
a009172c:  bb 36 a0 1c  srl  %i2, 0x1c, %i5
a0091730:  f8 02 c0 0c  ld  [ %o3 + %o4 ], %i4
a0091734:  ba 0f 60 01  and  %i5, 1, %i5
a0091738:  03 10 00 00  sethi  %hi(0x40000000), %g1
a009173c:  82 2f 00 01  andn  %i4, %g1, %g1
a0091740:  bb 2f 60 1e  sll  %i5, 0x1e, %i5
a0091744:  82 10 40 1d  or  %g1, %i5, %g1
a0091748:  b9 36 a0 14  srl  %i2, 0x14, %i4
a009174c:  b8 0f 20 80  and  %i4, 0x80, %i4
a0091750:  bb 36 a0 14  srl  %i2, 0x14, %i5
a0091754:  82 08 7f 3f  and  %g1, -193, %g1
a0091758:  82 10 40 1c  or  %g1, %i4, %g1
a009175c:  ba 0f 60 40  and  %i5, 0x40, %i5
a0091760:  82 10 40 1d  or  %g1, %i5, %g1
a0091764:  bb 36 a0 14  srl  %i2, 0x14, %i5
a0091768:  ba 0f 60 20  and  %i5, 0x20, %i5
a009176c:  82 08 7f df  and  %g1, -33, %g1
a0091770:  82 10 40 1d  or  %g1, %i5, %g1
a0091774:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a0091778:  c2 0e 20 09  ldub  [ %i0 + 9 ], %g1
a009177c:  c2 2b 60 11  stb  %g1, [ %o5 + 0x11 ]
a0091780:  f8 03 60 0c  ld  [ %o5 + 0xc ], %i4
a0091784:  f6 03 60 10  ld  [ %o5 + 0x10 ], %i3
a0091788:  83 36 a0 1d  srl  %i2, 0x1d, %g1
a009178c:  bb 36 a0 18  srl  %i2, 0x18, %i5
a0091790:  b6 0e c0 19  and  %i3, %i1, %i3
a0091794:  83 28 60 1f  sll  %g1, 0x1f, %g1
a0091798:  b8 0f 00 19  and  %i4, %i1, %i4
a009179c:  bb 2f 60 1f  sll  %i5, 0x1f, %i5
a00917a0:  b8 17 00 01  or  %i4, %g1, %i4
a00917a4:  b6 16 c0 1d  or  %i3, %i5, %i3
a00917a8:  f8 23 60 0c  st  %i4, [ %o5 + 0xc ]
a00917ac:  f6 23 60 10  st  %i3, [ %o5 + 0x10 ]
a00917b0:  fa 0e 20 06  ldub  [ %i0 + 6 ], %i5
a00917b4:  f8 0e 20 0a  ldub  [ %i0 + 0xa ], %i4
a00917b8:  f6 0e 20 07  ldub  [ %i0 + 7 ], %i3
a00917bc:  c2 0e 20 08  ldub  [ %i0 + 8 ], %g1
a00917c0:  c2 2b 60 12  stb  %g1, [ %o5 + 0x12 ]
a00917c4:  fa 2b 60 0d  stb  %i5, [ %o5 + 0xd ]
a00917c8:  f8 2b 60 0f  stb  %i4, [ %o5 + 0xf ]
a00917cc:  f6 2b 60 0e  stb  %i3, [ %o5 + 0xe ]
a00917d0:  c2 02 c0 0c  ld  [ %o3 + %o4 ], %g1
a00917d4:  3b 08 00 00  sethi  %hi(0x20000000), %i5
a00917d8:  f6 16 20 02  lduh  [ %i0 + 2 ], %i3
a00917dc:  ba 28 40 1d  andn  %g1, %i5, %i5
a00917e0:  b7 2e e0 10  sll  %i3, 0x10, %i3
a00917e4:  03 08 00 00  sethi  %hi(0x20000000), %g1
a00917e8:  82 0e c0 01  and  %i3, %g1, %g1
a00917ec:  ba 17 40 01  or  %i5, %g1, %i5
a00917f0:  83 36 a0 13  srl  %i2, 0x13, %g1
a00917f4:  b9 36 a0 13  srl  %i2, 0x13, %i4
a00917f8:  82 08 60 02  and  %g1, 2, %g1
a00917fc:  ba 0f 7f ed  and  %i5, -19, %i5
a0091800:  ba 17 40 01  or  %i5, %g1, %i5
a0091804:  b2 0f 20 10  and  %i4, 0x10, %i1
a0091808:  82 10 00 1c  mov  %i4, %g1
a009180c:  ba 17 40 19  or  %i5, %i1, %i5
a0091810:  b9 36 a0 15  srl  %i2, 0x15, %i4
a0091814:  82 08 60 08  and  %g1, 8, %g1
a0091818:  ba 0f 7f f3  and  %i5, -13, %i5
a009181c:  b8 0f 20 01  and  %i4, 1, %i4
a0091820:  ba 17 40 01  or  %i5, %g1, %i5
a0091824:  83 2f 20 02  sll  %i4, 2, %g1
a0091828:  ba 17 40 01  or  %i5, %g1, %i5
a009182c:  fa 22 c0 0c  st  %i5, [ %o3 + %o4 ]
a0091830:  fa 03 60 14  ld  [ %o5 + 0x14 ], %i5
a0091834:  03 00 00 20  sethi  %hi(0x8000), %g1
a0091838:  82 2f 40 01  andn  %i5, %g1, %g1
a009183c:  b9 2f 20 0f  sll  %i4, 0xf, %i4
a0091840:  82 10 40 1c  or  %g1, %i4, %g1
a0091844:  c2 23 60 14  st  %g1, [ %o5 + 0x14 ]
a0091848:  fa 02 c0 0c  ld  [ %o3 + %o4 ], %i5
a009184c:  83 36 a0 13  srl  %i2, 0x13, %g1
a0091850:  82 08 60 01  and  %g1, 1, %g1
a0091854:  ba 0f 7f fe  and  %i5, -2, %i5
a0091858:  ba 17 40 01  or  %i5, %g1, %i5
a009185c:  fa 22 c0 0c  st  %i5, [ %o3 + %o4 ]
a0091860:  c2 03 60 10  ld  [ %o5 + 0x10 ], %g1
a0091864:  bb 36 a0 0b  srl  %i2, 0xb, %i5
a0091868:  ba 0f 60 80  and  %i5, 0x80, %i5
a009186c:  82 08 7f 3f  and  %g1, -193, %g1
a0091870:  82 10 40 1d  or  %g1, %i5, %g1
a0091874:  b5 36 a0 0b  srl  %i2, 0xb, %i2
a0091878:  bb 36 e0 1f  srl  %i3, 0x1f, %i5
a009187c:  b4 0e a0 40  and  %i2, 0x40, %i2
a0091880:  80 a0 00 1d  cmp  %g0, %i5
a0091884:  82 10 40 1a  or  %g1, %i2, %g1
a0091888:  9e 0b e0 01  and  %o7, 1, %o7
a009188c:  ba 40 20 00  addx  %g0, 0, %i5
a0091890:  9f 2b e0 05  sll  %o7, 5, %o7
a0091894:  82 08 7f cf  and  %g1, -49, %g1
a0091898:  82 10 40 0f  or  %g1, %o7, %g1
a009189c:  bb 2f 60 04  sll  %i5, 4, %i5
a00918a0:  82 10 40 1d  or  %g1, %i5, %g1
a00918a4:  b7 36 e0 1b  srl  %i3, 0x1b, %i3
a00918a8:  b6 0e e0 08  and  %i3, 8, %i3
a00918ac:  82 08 7f f7  and  %g1, -9, %g1
a00918b0:  82 10 40 1b  or  %g1, %i3, %g1
a00918b4:  c2 23 60 10  st  %g1, [ %o5 + 0x10 ]
a00918b8:  c2 0e 20 0c  ldub  [ %i0 + 0xc ], %g1
a00918bc:  c2 2b 60 17  stb  %g1, [ %o5 + 0x17 ]
a00918c0:  c2 03 60 14  ld  [ %o5 + 0x14 ], %g1
a00918c4:  83 30 60 0d  srl  %g1, 0xd, %g1
a00918c8:  80 88 60 01  btst  1, %g1
a00918cc:  12 80 00 06  bne  0xa00918e4
a00918d0:  01 00 00 00  nop
a00918d4:  c2 02 c0 0c  ld  [ %o3 + %o4 ], %g1
a00918d8:  82 08 7f ef  and  %g1, -17, %g1
a00918dc:  82 10 40 19  or  %g1, %i1, %g1
a00918e0:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00918e4:  81 c7 e0 08  ret
a00918e8:  81 e8 00 00  restore
