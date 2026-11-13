# leon2m FUN_a0091784 0xa0091784-0xa009183c (184 bytes)
a0091784:  9d e3 bf 98  save  %sp, -104, %sp
a0091788:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a009178c:  d6 06 63 ec  ld  [ %i1 + 0x3ec ], %o3	! 0xa802afec
a0091790:  94 02 ff f5  add  %o3, -11, %o2
a0091794:  40 00 5d d5  call  0xa00a8ee8
a0091798:  90 0a a0 ff  and  %o2, 0xff, %o0
a009179c:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a00917a0:  90 02 7f f5  add  %o1, -11, %o0
a00917a4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00917a8:  40 00 63 46  call  0xa00aa4c0
a00917ac:  92 10 20 00  clr  %o1
a00917b0:  03 15 55 55  sethi  %hi(0x55555400), %g1
a00917b4:  b0 10 61 56  or  %g1, 0x156, %i0	! 0x55555556
a00917b8:  de 16 63 ee  lduh  [ %i1 + 0x3ee ], %o7
a00917bc:  90 03 ff f7  add  %o7, -9, %o0
a00917c0:  99 3a 20 1f  sra  %o0, 0x1f, %o4
a00917c4:  80 5a 00 18  smul  %o0, %i0, %g0
a00917c8:  97 40 00 00  rd  %y, %o3
a00917cc:  94 22 c0 0c  sub  %o3, %o4, %o2
a00917d0:  92 02 80 0a  add  %o2, %o2, %o1
a00917d4:  82 02 40 0a  add  %o1, %o2, %g1
a00917d8:  9e 22 00 01  sub  %o0, %g1, %o7
a00917dc:  9a 03 e0 0b  add  %o7, 0xb, %o5
a00917e0:  90 0b e0 ff  and  %o7, 0xff, %o0
a00917e4:  40 00 63 4f  call  0xa00aa520
a00917e8:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a00917ec:  98 0a 20 ff  and  %o0, 0xff, %o4
a00917f0:  80 a3 20 01  cmp  %o4, 1
a00917f4:  12 bf ff f2  bne  0xa00917bc
a00917f8:  de 16 63 ee  lduh  [ %i1 + 0x3ee ], %o7
a00917fc:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a0091800:  82 02 7f f5  add  %o1, -11, %g1
a0091804:  90 08 60 ff  and  %g1, 0xff, %o0
a0091808:  40 00 5e 01  call  0xa00a900c
a009180c:  92 10 20 01  mov  1, %o1
a0091810:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0
a0091814:  9a 02 3f f5  add  %o0, -11, %o5
a0091818:  90 0b 60 ff  and  %o5, 0xff, %o0
a009181c:  40 00 63 29  call  0xa00aa4c0
a0091820:  92 10 20 01  mov  1, %o1
a0091824:  f0 06 63 ec  ld  [ %i1 + 0x3ec ], %i0
a0091828:  b2 06 3f f5  add  %i0, -11, %i1
a009182c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0091830:  40 00 77 07  call  0xa00af44c
a0091834:  91 e8 20 0b  restore  %g0, 0xb, %o0
a0091838:  01 00 00 00  nop
