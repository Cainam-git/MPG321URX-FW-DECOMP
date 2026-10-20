# leon2m FUN_a009a784 0xa009a784-0xa009a8dc (344 bytes)
a009a784:  9d e3 bf 98  save  %sp, -104, %sp
a009a788:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009a78c:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009a790:  90 02 7f ad  add  %o1, -83, %o0
a009a794:  40 00 3b 0a  call  0xa00a93bc
a009a798:  90 0a 20 ff  and  %o0, 0xff, %o0
a009a79c:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009a7a0:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009a7a4:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009a7a8:  9e 02 3f af  add  %o0, -81, %o7
a009a7ac:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009a7b0:  80 5b c0 19  smul  %o7, %i1, %g0
a009a7b4:  93 40 00 00  rd  %y, %o1
a009a7b8:  82 22 40 0a  sub  %o1, %o2, %g1
a009a7bc:  b0 00 40 01  add  %g1, %g1, %i0
a009a7c0:  98 06 00 01  add  %i0, %g1, %o4
a009a7c4:  96 23 c0 0c  sub  %o7, %o4, %o3
a009a7c8:  9a 02 e0 53  add  %o3, 0x53, %o5
a009a7cc:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009a7d0:  40 00 41 58  call  0xa00aad30
a009a7d4:  90 0a e0 ff  and  %o3, 0xff, %o0
a009a7d8:  94 0a 20 ff  and  %o0, 0xff, %o2
a009a7dc:  80 a2 a0 01  cmp  %o2, 1
a009a7e0:  12 bf ff f2  bne  0xa009a7a8
a009a7e4:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009a7e8:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5
a009a7ec:  80 a3 60 53  cmp  %o5, 0x53
a009a7f0:  08 80 00 1e  bleu  0xa009a868
a009a7f4:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a009a7f8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a009a7fc:  b2 13 22 90  or  %o4, 0x290, %i1	! 0xa802d290
a009a800:  d2 06 60 a8  ld  [ %i1 + 0xa8 ], %o1
a009a804:  03 00 00 04  sethi  %hi(0x1000), %g1
a009a808:  b0 0b 60 01  and  %o5, 1, %i0
a009a80c:  9e 2a 40 01  andn  %o1, %g1, %o7
a009a810:  9b 2e 20 0c  sll  %i0, 0xc, %o5
a009a814:  96 13 c0 0d  or  %o7, %o5, %o3
a009a818:  d6 26 60 a8  st  %o3, [ %i1 + 0xa8 ]
a009a81c:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5
a009a820:  96 03 7f ad  add  %o5, -83, %o3
a009a824:  90 0a e0 ff  and  %o3, 0xff, %o0
a009a828:  40 00 3b 8a  call  0xa00a9650
a009a82c:  92 10 20 01  mov  1, %o1
a009a830:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a009a834:  f2 0e 60 56  ldub  [ %i1 + 0x56 ], %i1	! 0xa8025c56
a009a838:  de 06 a3 ec  ld  [ %i2 + 0x3ec ], %o7
a009a83c:  90 0e 60 ff  and  %i1, 0xff, %o0
a009a840:  94 03 ff ad  add  %o7, -83, %o2
a009a844:  b4 02 20 01  add  %o0, 1, %i2
a009a848:  80 a2 80 1a  cmp  %o2, %i2
a009a84c:  22 80 00 1f  be,a   0xa009a8c8
a009a850:  b2 06 60 01  inc  %i1
a009a854:  b0 06 60 01  add  %i1, 1, %i0
a009a858:  b2 0e 20 ff  and  %i0, 0xff, %i1
a009a85c:  b0 10 20 01  mov  1, %i0
a009a860:  40 00 36 37  call  0xa00a813c
a009a864:  95 e8 20 01  restore  %g0, 1, %o2
a009a868:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a009a86c:  d2 0e 60 56  ldub  [ %i1 + 0x56 ], %o1
a009a870:  94 13 22 90  or  %o4, 0x290, %o2
a009a874:  c2 02 a0 a8  ld  [ %o2 + 0xa8 ], %g1
a009a878:  9a 0a 60 01  and  %o1, 1, %o5
a009a87c:  31 00 00 04  sethi  %hi(0x1000), %i0
a009a880:  9e 28 40 18  andn  %g1, %i0, %o7
a009a884:  97 2b 60 0c  sll  %o5, 0xc, %o3
a009a888:  90 13 c0 0b  or  %o7, %o3, %o0
a009a88c:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5
a009a890:  d0 22 a0 a8  st  %o0, [ %o2 + 0xa8 ]
a009a894:  96 03 7f ad  add  %o5, -83, %o3
a009a898:  90 0a e0 ff  and  %o3, 0xff, %o0
a009a89c:  40 00 3b 6d  call  0xa00a9650
a009a8a0:  92 10 20 01  mov  1, %o1
a009a8a4:  f2 0e 60 56  ldub  [ %i1 + 0x56 ], %i1
a009a8a8:  de 06 a3 ec  ld  [ %i2 + 0x3ec ], %o7
a009a8ac:  90 0e 60 ff  and  %i1, 0xff, %o0
a009a8b0:  94 03 ff ad  add  %o7, -83, %o2
a009a8b4:  b4 02 20 01  add  %o0, 1, %i2
a009a8b8:  80 a2 80 1a  cmp  %o2, %i2
a009a8bc:  12 bf ff e7  bne  0xa009a858
a009a8c0:  b0 06 60 01  add  %i1, 1, %i0
a009a8c4:  b2 06 60 01  inc  %i1
a009a8c8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a009a8cc:  b0 10 20 01  mov  1, %i0
a009a8d0:  40 00 36 1b  call  0xa00a813c
a009a8d4:  95 e8 20 00  restore  %g0, 0, %o2
a009a8d8:  01 00 00 00  nop
