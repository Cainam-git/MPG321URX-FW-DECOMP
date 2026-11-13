# leon2m FUN_a009a5fc 0xa009a5fc-0xa009a6c0 (196 bytes)
a009a5fc:  9d e3 bf 98  save  %sp, -104, %sp
a009a600:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009a604:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009a608:  90 02 7f b8  add  %o1, -72, %o0
a009a60c:  40 00 3b 6c  call  0xa00a93bc
a009a610:  90 0a 20 ff  and  %o0, 0xff, %o0
a009a614:  03 0a aa aa  sethi  %hi(0x2aaaa800), %g1
a009a618:  b2 10 62 ab  or  %g1, 0x2ab, %i1	! 0x2aaaaaab
a009a61c:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009a620:  9e 02 3f bd  add  %o0, -67, %o7
a009a624:  80 5b c0 19  smul  %o7, %i1, %g0
a009a628:  95 40 00 00  rd  %y, %o2
a009a62c:  97 3b e0 1f  sra  %o7, 0x1f, %o3
a009a630:  92 22 80 0b  sub  %o2, %o3, %o1
a009a634:  82 02 40 09  add  %o1, %o1, %g1
a009a638:  b0 00 40 09  add  %g1, %o1, %i0
a009a63c:  98 06 00 18  add  %i0, %i0, %o4
a009a640:  96 23 c0 0c  sub  %o7, %o4, %o3
a009a644:  9a 02 e0 48  add  %o3, 0x48, %o5
a009a648:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009a64c:  40 00 41 b9  call  0xa00aad30
a009a650:  90 0a e0 ff  and  %o3, 0xff, %o0
a009a654:  94 0a 20 ff  and  %o0, 0xff, %o2
a009a658:  80 a2 a0 01  cmp  %o2, 1
a009a65c:  12 bf ff f1  bne  0xa009a620
a009a660:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009a664:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1
a009a668:  82 02 7f b8  add  %o1, -72, %g1
a009a66c:  31 2a 00 b5  sethi  %hi(0xa802d400), %i0
a009a670:  40 01 05 a0  call  0xa00dbcf0
a009a674:  c2 2e 20 12  stb  %g1, [ %i0 + 0x12 ]	! 0xa802d412
a009a678:  d8 06 a3 ec  ld  [ %i2 + 0x3ec ], %o4
a009a67c:  9a 03 3f b8  add  %o4, -72, %o5
a009a680:  90 0b 60 ff  and  %o5, 0xff, %o0
a009a684:  40 00 3b f3  call  0xa00a9650
a009a688:  92 10 20 01  mov  1, %o1
a009a68c:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009a690:  9e 06 7f b8  add  %i1, -72, %o7
a009a694:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009a698:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009a69c:  b0 10 20 01  mov  1, %i0
a009a6a0:  80 a3 c0 19  cmp  %o7, %i1
a009a6a4:  02 80 00 04  be  0xa009a6b4
a009a6a8:  b4 10 20 00  clr  %i2
a009a6ac:  b0 10 20 01  mov  1, %i0
a009a6b0:  b4 10 20 01  mov  1, %i2
a009a6b4:  40 00 36 a2  call  0xa00a813c
a009a6b8:  81 e8 00 00  restore
a009a6bc:  01 00 00 00  nop
