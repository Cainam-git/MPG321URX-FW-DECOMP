# leon2m FUN_a009183c 0xa009183c-0xa00918f4 (184 bytes)
a009183c:  9d e3 bf 98  save  %sp, -104, %sp
a0091840:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0091844:  d6 06 63 ec  ld  [ %i1 + 0x3ec ], %o3	! 0xa802afec
a0091848:  94 02 ff f5  add  %o3, -11, %o2
a009184c:  40 00 5d a7  call  0xa00a8ee8
a0091850:  90 0a a0 ff  and  %o2, 0xff, %o0
a0091854:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a0091858:  90 02 7f f5  add  %o1, -11, %o0
a009185c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091860:  40 00 63 18  call  0xa00aa4c0
a0091864:  92 10 20 00  clr  %o1
a0091868:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009186c:  b0 10 61 56  or  %g1, 0x156, %i0	! 0x55555556
a0091870:  de 16 63 ee  lduh  [ %i1 + 0x3ee ], %o7
a0091874:  90 03 ff f6  add  %o7, -10, %o0
a0091878:  99 3a 20 1f  sra  %o0, 0x1f, %o4
a009187c:  80 5a 00 18  smul  %o0, %i0, %g0
a0091880:  97 40 00 00  rd  %y, %o3
a0091884:  94 22 c0 0c  sub  %o3, %o4, %o2
a0091888:  92 02 80 0a  add  %o2, %o2, %o1
a009188c:  82 02 40 0a  add  %o1, %o2, %g1
a0091890:  9e 22 00 01  sub  %o0, %g1, %o7
a0091894:  9a 03 e0 0b  add  %o7, 0xb, %o5
a0091898:  90 0b e0 ff  and  %o7, 0xff, %o0
a009189c:  40 00 63 21  call  0xa00aa520
a00918a0:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a00918a4:  98 0a 20 ff  and  %o0, 0xff, %o4
a00918a8:  80 a3 20 01  cmp  %o4, 1
a00918ac:  12 bf ff f2  bne  0xa0091874
a00918b0:  de 16 63 ee  lduh  [ %i1 + 0x3ee ], %o7
a00918b4:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a00918b8:  82 02 7f f5  add  %o1, -11, %g1
a00918bc:  90 08 60 ff  and  %g1, 0xff, %o0
a00918c0:  40 00 5d d3  call  0xa00a900c
a00918c4:  92 10 20 01  mov  1, %o1
a00918c8:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0
a00918cc:  9a 02 3f f5  add  %o0, -11, %o5
a00918d0:  90 0b 60 ff  and  %o5, 0xff, %o0
a00918d4:  40 00 62 fb  call  0xa00aa4c0
a00918d8:  92 10 20 01  mov  1, %o1
a00918dc:  f0 06 63 ec  ld  [ %i1 + 0x3ec ], %i0
a00918e0:  b2 06 3f f5  add  %i0, -11, %i1
a00918e4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00918e8:  40 00 76 d9  call  0xa00af44c
a00918ec:  91 e8 20 0b  restore  %g0, 0xb, %o0
a00918f0:  01 00 00 00  nop
