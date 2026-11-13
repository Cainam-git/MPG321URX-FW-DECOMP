# leon2m FUN_a010f7a4 0xa010f7a4-0xa010f864 (192 bytes)
a010f7a4:  9d e3 bf 98  save  %sp, -104, %sp
a010f7a8:  33 34 00 c8  sethi  %hi(0xd0032000), %i1
a010f7ac:  1f 34 00 e8  sethi  %hi(0xd003a000), %o7
a010f7b0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a010f7b4:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010f7b8:  b6 10 00 19  mov  %i1, %i3
a010f7bc:  90 16 60 18  or  %i1, 0x18, %o0
a010f7c0:  b4 10 00 0f  mov  %o7, %i2
a010f7c4:  92 13 e0 18  or  %o7, 0x18, %o1
a010f7c8:  96 16 60 1c  or  %i1, 0x1c, %o3
a010f7cc:  94 13 e0 1c  or  %o7, 0x1c, %o2
a010f7d0:  19 00 04 00  sethi  %hi(0x100000), %o4
a010f7d4:  1b 00 08 00  sethi  %hi(0x200000), %o5
a010f7d8:  80 a6 20 01  cmp  %i0, 1
a010f7dc:  02 80 00 1d  be  0xa010f850
a010f7e0:  ba 10 63 04  or  %g1, 0x304, %i5
a010f7e4:  f8 0f 60 3e  ldub  [ %i5 + 0x3e ], %i4
a010f7e8:  82 17 20 01  or  %i4, 1, %g1
a010f7ec:  c2 2f 60 3e  stb  %g1, [ %i5 + 0x3e ]
a010f7f0:  39 2a 00 b5  sethi  %hi(0xa802d400), %i4
a010f7f4:  c2 07 22 a4  ld  [ %i4 + 0x2a4 ], %g1	! 0xa802d6a4
a010f7f8:  fa 10 60 08  lduh  [ %g1 + 8 ], %i5
a010f7fc:  80 a6 20 00  cmp  %i0, 0
a010f800:  12 80 00 0b  bne  0xa010f82c
a010f804:  b9 37 60 01  srl  %i5, 1, %i4
a010f808:  f8 22 00 00  st  %i4, [ %o0 ]
a010f80c:  f8 22 40 00  st  %i4, [ %o1 ]
a010f810:  f6 06 40 00  ld  [ %i1 ], %i3
a010f814:  b4 16 c0 0c  or  %i3, %o4, %i2
a010f818:  f4 26 40 00  st  %i2, [ %i1 ]
a010f81c:  f2 03 c0 00  ld  [ %o7 ], %i1
a010f820:  b0 16 40 0c  or  %i1, %o4, %i0
a010f824:  f0 23 c0 00  st  %i0, [ %o7 ]
a010f828:  30 80 00 0d  b,a   0xa010f85c
a010f82c:  f8 22 c0 00  st  %i4, [ %o3 ]
a010f830:  f8 22 80 00  st  %i4, [ %o2 ]
a010f834:  f0 06 c0 00  ld  [ %i3 ], %i0
a010f838:  b8 16 00 0d  or  %i0, %o5, %i4
a010f83c:  f8 26 c0 00  st  %i4, [ %i3 ]
a010f840:  c2 06 80 00  ld  [ %i2 ], %g1
a010f844:  ba 10 40 0d  or  %g1, %o5, %i5
a010f848:  fa 26 80 00  st  %i5, [ %i2 ]
a010f84c:  30 80 00 04  b,a   0xa010f85c
a010f850:  39 2a 00 b6  sethi  %hi(0xa802d800), %i4
a010f854:  10 bf ff e4  b  0xa010f7e4
a010f858:  ba 17 20 04  or  %i4, 4, %i5	! 0xa802d804
a010f85c:  81 c7 e0 08  ret
a010f860:  81 e8 00 00  restore
