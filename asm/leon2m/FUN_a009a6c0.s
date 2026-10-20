# leon2m FUN_a009a6c0 0xa009a6c0-0xa009a784 (196 bytes)
a009a6c0:  9d e3 bf 98  save  %sp, -104, %sp
a009a6c4:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009a6c8:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009a6cc:  90 02 7f b8  add  %o1, -72, %o0
a009a6d0:  40 00 3b 3b  call  0xa00a93bc
a009a6d4:  90 0a 20 ff  and  %o0, 0xff, %o0
a009a6d8:  03 0a aa aa  sethi  %hi(0x2aaaa800), %g1
a009a6dc:  b2 10 62 ab  or  %g1, 0x2ab, %i1	! 0x2aaaaaab
a009a6e0:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009a6e4:  9e 02 3f b9  add  %o0, -71, %o7
a009a6e8:  80 5b c0 19  smul  %o7, %i1, %g0
a009a6ec:  95 40 00 00  rd  %y, %o2
a009a6f0:  97 3b e0 1f  sra  %o7, 0x1f, %o3
a009a6f4:  92 22 80 0b  sub  %o2, %o3, %o1
a009a6f8:  82 02 40 09  add  %o1, %o1, %g1
a009a6fc:  b0 00 40 09  add  %g1, %o1, %i0
a009a700:  98 06 00 18  add  %i0, %i0, %o4
a009a704:  96 23 c0 0c  sub  %o7, %o4, %o3
a009a708:  9a 02 e0 48  add  %o3, 0x48, %o5
a009a70c:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009a710:  40 00 41 88  call  0xa00aad30
a009a714:  90 0a e0 ff  and  %o3, 0xff, %o0
a009a718:  94 0a 20 ff  and  %o0, 0xff, %o2
a009a71c:  80 a2 a0 01  cmp  %o2, 1
a009a720:  12 bf ff f1  bne  0xa009a6e4
a009a724:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009a728:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1
a009a72c:  82 02 7f b8  add  %o1, -72, %g1
a009a730:  31 2a 00 b5  sethi  %hi(0xa802d400), %i0
a009a734:  40 01 05 6f  call  0xa00dbcf0
a009a738:  c2 2e 20 12  stb  %g1, [ %i0 + 0x12 ]	! 0xa802d412
a009a73c:  d8 06 a3 ec  ld  [ %i2 + 0x3ec ], %o4
a009a740:  9a 03 3f b8  add  %o4, -72, %o5
a009a744:  90 0b 60 ff  and  %o5, 0xff, %o0
a009a748:  40 00 3b c2  call  0xa00a9650
a009a74c:  92 10 20 01  mov  1, %o1
a009a750:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009a754:  9e 06 7f b8  add  %i1, -72, %o7
a009a758:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009a75c:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009a760:  b0 10 20 01  mov  1, %i0
a009a764:  80 a3 c0 19  cmp  %o7, %i1
a009a768:  02 80 00 04  be  0xa009a778
a009a76c:  b4 10 20 00  clr  %i2
a009a770:  b0 10 20 01  mov  1, %i0
a009a774:  b4 10 20 01  mov  1, %i2
a009a778:  40 00 36 71  call  0xa00a813c
a009a77c:  81 e8 00 00  restore
a009a780:  01 00 00 00  nop
