# leon2m FUN_a00927e8 0xa00927e8-0xa0092908 (288 bytes)
a00927e8:  9d e3 bf 98  save  %sp, -104, %sp
a00927ec:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a00927f0:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a00927f4:  90 02 7f dd  add  %o1, -35, %o0
a00927f8:  40 00 59 bc  call  0xa00a8ee8
a00927fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0092800:  03 15 55 55  sethi  %hi(0x55555400), %g1
a0092804:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a0092808:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009280c:  9e 02 3f de  add  %o0, -34, %o7
a0092810:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a0092814:  80 5b c0 19  smul  %o7, %i1, %g0
a0092818:  93 40 00 00  rd  %y, %o1
a009281c:  82 22 40 0a  sub  %o1, %o2, %g1
a0092820:  b0 00 40 01  add  %g1, %g1, %i0
a0092824:  98 06 00 01  add  %i0, %g1, %o4
a0092828:  96 23 c0 0c  sub  %o7, %o4, %o3
a009282c:  9a 02 e0 23  add  %o3, 0x23, %o5
a0092830:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a0092834:  40 00 5f 3b  call  0xa00aa520
a0092838:  90 0a e0 ff  and  %o3, 0xff, %o0
a009283c:  94 0a 20 ff  and  %o0, 0xff, %o2
a0092840:  80 a2 a0 01  cmp  %o2, 1
a0092844:  12 bf ff f2  bne  0xa009280c
a0092848:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009284c:  d8 06 a3 ec  ld  [ %i2 + 0x3ec ], %o4
a0092850:  b2 03 3f dd  add  %o4, -35, %i1
a0092854:  90 0e 60 ff  and  %i1, 0xff, %o0
a0092858:  40 00 59 ed  call  0xa00a900c
a009285c:  92 10 20 01  mov  1, %o1
a0092860:  de 06 a3 ec  ld  [ %i2 + 0x3ec ], %o7
a0092864:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a0092868:  9a 03 ff dd  add  %o7, -35, %o5
a009286c:  d6 0e 60 56  ldub  [ %i1 + 0x56 ], %o3
a0092870:  90 10 20 06  mov  6, %o0
a0092874:  80 a3 40 0b  cmp  %o5, %o3
a0092878:  02 80 00 04  be  0xa0092888
a009287c:  92 10 20 00  clr  %o1
a0092880:  90 10 20 06  mov  6, %o0
a0092884:  92 10 20 01  mov  1, %o1
a0092888:  40 02 d0 ee  call  0xa0146c40
a009288c:  94 10 20 00  clr  %o2
a0092890:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1
a0092894:  82 02 7f dd  add  %o1, -35, %g1
a0092898:  92 08 60 ff  and  %g1, 0xff, %o1
a009289c:  40 00 72 ec  call  0xa00af44c
a00928a0:  90 10 20 23  mov  0x23, %o0
a00928a4:  f0 06 a3 ec  ld  [ %i2 + 0x3ec ], %i0
a00928a8:  80 a6 20 23  cmp  %i0, 0x23
a00928ac:  02 80 00 12  be  0xa00928f4
a00928b0:  90 10 20 01  mov  1, %o0
a00928b4:  40 00 5a ed  call  0xa00a9468
a00928b8:  92 10 20 02  mov  2, %o1
a00928bc:  90 10 20 00  clr  %o0
a00928c0:  92 10 20 01  mov  1, %o1
a00928c4:  40 00 83 04  call  0xa00b34d4
a00928c8:  b0 10 20 00  clr  %i0
a00928cc:  d0 06 a3 ec  ld  [ %i2 + 0x3ec ], %o0
a00928d0:  94 02 3f dd  add  %o0, -35, %o2
a00928d4:  f2 0e 60 56  ldub  [ %i1 + 0x56 ], %i1
a00928d8:  80 a2 80 19  cmp  %o2, %i1
a00928dc:  02 80 00 04  be  0xa00928ec
a00928e0:  b4 10 20 00  clr  %i2
a00928e4:  b0 10 20 00  clr  %i0
a00928e8:  b4 10 20 01  mov  1, %i2
a00928ec:  40 00 56 14  call  0xa00a813c
a00928f0:  81 e8 00 00  restore
a00928f4:  40 00 5a dd  call  0xa00a9468
a00928f8:  92 10 20 03  mov  3, %o1
a00928fc:  90 10 20 00  clr  %o0
a0092900:  10 bf ff f1  b  0xa00928c4
a0092904:  92 10 20 04  mov  4, %o1
