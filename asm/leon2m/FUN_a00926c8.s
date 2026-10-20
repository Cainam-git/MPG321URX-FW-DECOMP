# leon2m FUN_a00926c8 0xa00926c8-0xa00927e8 (288 bytes)
a00926c8:  9d e3 bf 98  save  %sp, -104, %sp
a00926cc:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a00926d0:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a00926d4:  90 02 7f dd  add  %o1, -35, %o0
a00926d8:  40 00 5a 04  call  0xa00a8ee8
a00926dc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00926e0:  03 15 55 55  sethi  %hi(0x55555400), %g1
a00926e4:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a00926e8:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a00926ec:  9e 02 3f df  add  %o0, -33, %o7
a00926f0:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a00926f4:  80 5b c0 19  smul  %o7, %i1, %g0
a00926f8:  93 40 00 00  rd  %y, %o1
a00926fc:  82 22 40 0a  sub  %o1, %o2, %g1
a0092700:  b0 00 40 01  add  %g1, %g1, %i0
a0092704:  98 06 00 01  add  %i0, %g1, %o4
a0092708:  96 23 c0 0c  sub  %o7, %o4, %o3
a009270c:  9a 02 e0 23  add  %o3, 0x23, %o5
a0092710:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a0092714:  40 00 5f 83  call  0xa00aa520
a0092718:  90 0a e0 ff  and  %o3, 0xff, %o0
a009271c:  94 0a 20 ff  and  %o0, 0xff, %o2
a0092720:  80 a2 a0 01  cmp  %o2, 1
a0092724:  12 bf ff f2  bne  0xa00926ec
a0092728:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009272c:  d8 06 a3 ec  ld  [ %i2 + 0x3ec ], %o4
a0092730:  b2 03 3f dd  add  %o4, -35, %i1
a0092734:  90 0e 60 ff  and  %i1, 0xff, %o0
a0092738:  40 00 5a 35  call  0xa00a900c
a009273c:  92 10 20 01  mov  1, %o1
a0092740:  de 06 a3 ec  ld  [ %i2 + 0x3ec ], %o7
a0092744:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a0092748:  9a 03 ff dd  add  %o7, -35, %o5
a009274c:  d6 0e 60 56  ldub  [ %i1 + 0x56 ], %o3
a0092750:  90 10 20 06  mov  6, %o0
a0092754:  80 a3 40 0b  cmp  %o5, %o3
a0092758:  02 80 00 04  be  0xa0092768
a009275c:  92 10 20 00  clr  %o1
a0092760:  90 10 20 06  mov  6, %o0
a0092764:  92 10 20 01  mov  1, %o1
a0092768:  40 02 d1 36  call  0xa0146c40
a009276c:  94 10 20 00  clr  %o2
a0092770:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1
a0092774:  82 02 7f dd  add  %o1, -35, %g1
a0092778:  92 08 60 ff  and  %g1, 0xff, %o1
a009277c:  40 00 73 34  call  0xa00af44c
a0092780:  90 10 20 23  mov  0x23, %o0
a0092784:  f0 06 a3 ec  ld  [ %i2 + 0x3ec ], %i0
a0092788:  80 a6 20 23  cmp  %i0, 0x23
a009278c:  02 80 00 12  be  0xa00927d4
a0092790:  90 10 20 01  mov  1, %o0
a0092794:  40 00 5b 35  call  0xa00a9468
a0092798:  92 10 20 02  mov  2, %o1
a009279c:  90 10 20 00  clr  %o0
a00927a0:  92 10 20 01  mov  1, %o1
a00927a4:  40 00 83 4c  call  0xa00b34d4
a00927a8:  b0 10 20 00  clr  %i0
a00927ac:  d0 06 a3 ec  ld  [ %i2 + 0x3ec ], %o0
a00927b0:  94 02 3f dd  add  %o0, -35, %o2
a00927b4:  f2 0e 60 56  ldub  [ %i1 + 0x56 ], %i1
a00927b8:  80 a2 80 19  cmp  %o2, %i1
a00927bc:  02 80 00 04  be  0xa00927cc
a00927c0:  b4 10 20 00  clr  %i2
a00927c4:  b0 10 20 00  clr  %i0
a00927c8:  b4 10 20 01  mov  1, %i2
a00927cc:  40 00 56 5c  call  0xa00a813c
a00927d0:  81 e8 00 00  restore
a00927d4:  40 00 5b 25  call  0xa00a9468
a00927d8:  92 10 20 03  mov  3, %o1
a00927dc:  90 10 20 00  clr  %o0
a00927e0:  10 bf ff f1  b  0xa00927a4
a00927e4:  92 10 20 04  mov  4, %o1
