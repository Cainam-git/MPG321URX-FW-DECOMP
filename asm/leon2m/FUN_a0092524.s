# leon2m FUN_a0092524 0xa0092524-0xa0092648 (292 bytes)
a0092524:  9d e3 bf 98  save  %sp, -104, %sp
a0092528:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a009252c:  b0 14 62 90  or  %l1, 0x290, %i0	! 0xa802d290
a0092530:  d6 0e 20 1f  ldub  [ %i0 + 0x1f ], %o3
a0092534:  d8 0e 21 a4  ldub  [ %i0 + 0x1a4 ], %o4
a0092538:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a009253c:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a0092540:  d8 28 60 55  stb  %o4, [ %g1 + 0x55 ]
a0092544:  80 a2 e0 00  cmp  %o3, 0
a0092548:  12 80 00 04  bne  0xa0092558
a009254c:  d6 2b 60 56  stb  %o3, [ %o5 + 0x56 ]
a0092550:  d0 0e 20 19  ldub  [ %i0 + 0x19 ], %o0
a0092554:  d0 2e 20 8f  stb  %o0, [ %i0 + 0x8f ]
a0092558:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a009255c:  d6 06 63 ec  ld  [ %i1 + 0x3ec ], %o3	! 0xa802afec
a0092560:  a0 02 ff fe  add  %o3, -2, %l0
a0092564:  90 0c 20 ff  and  %l0, 0xff, %o0
a0092568:  40 00 86 f7  call  0xa00b4144
a009256c:  92 10 20 02  mov  2, %o1
a0092570:  de 0e 20 1f  ldub  [ %i0 + 0x1f ], %o7
a0092574:  94 03 e0 23  add  %o7, 0x23, %o2
a0092578:  13 15 55 55  sethi  %hi(0x55555400), %o1
a009257c:  d4 26 63 ec  st  %o2, [ %i1 + 0x3ec ]
a0092580:  b0 12 61 56  or  %o1, 0x156, %i0
a0092584:  10 80 00 0c  b  0xa00925b4
a0092588:  a0 10 00 19  mov  %i1, %l0
a009258c:  94 03 7f de  add  %o5, -34, %o2
a0092590:  91 3a a0 1f  sra  %o2, 0x1f, %o0
a0092594:  80 5a 80 18  smul  %o2, %i0, %g0
a0092598:  99 40 00 00  rd  %y, %o4
a009259c:  82 23 00 08  sub  %o4, %o0, %g1
a00925a0:  96 00 40 01  add  %g1, %g1, %o3
a00925a4:  9e 02 c0 01  add  %o3, %g1, %o7
a00925a8:  92 22 80 0f  sub  %o2, %o7, %o1
a00925ac:  90 02 60 23  add  %o1, 0x23, %o0
a00925b0:  d0 26 63 ec  st  %o0, [ %i1 + 0x3ec ]
a00925b4:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a00925b8:  82 03 3f dd  add  %o4, -35, %g1
a00925bc:  40 00 5f d9  call  0xa00aa520
a00925c0:  90 08 60 ff  and  %g1, 0xff, %o0
a00925c4:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00925c8:  80 a3 60 01  cmp  %o5, 1
a00925cc:  12 bf ff f0  bne  0xa009258c
a00925d0:  da 16 63 ee  lduh  [ %i1 + 0x3ee ], %o5
a00925d4:  94 14 62 90  or  %l1, 0x290, %o2
a00925d8:  d2 0a a0 1f  ldub  [ %o2 + 0x1f ], %o1
a00925dc:  94 10 20 00  clr  %o2
a00925e0:  40 00 56 d7  call  0xa00a813c
a00925e4:  90 10 20 00  clr  %o0
a00925e8:  f2 04 23 ec  ld  [ %l0 + 0x3ec ], %i1
a00925ec:  b0 06 7f dd  add  %i1, -35, %i0
a00925f0:  90 0e 20 ff  and  %i0, 0xff, %o0
a00925f4:  40 00 5a 86  call  0xa00a900c
a00925f8:  92 10 20 01  mov  1, %o1
a00925fc:  90 10 20 06  mov  6, %o0
a0092600:  92 10 20 00  clr  %o1
a0092604:  40 02 d1 8f  call  0xa0146c40
a0092608:  94 10 20 00  clr  %o2
a009260c:  e2 04 23 ec  ld  [ %l0 + 0x3ec ], %l1
a0092610:  80 a4 60 23  cmp  %l1, 0x23
a0092614:  02 80 00 07  be  0xa0092630
a0092618:  90 10 20 01  mov  1, %o0
a009261c:  40 00 5b 93  call  0xa00a9468
a0092620:  92 10 20 02  mov  2, %o1
a0092624:  b0 10 20 00  clr  %i0
a0092628:  40 00 83 ab  call  0xa00b34d4
a009262c:  93 e8 20 01  restore  %g0, 1, %o1
a0092630:  40 00 5b 8e  call  0xa00a9468
a0092634:  92 10 20 03  mov  3, %o1
a0092638:  b0 10 20 00  clr  %i0
a009263c:  40 00 83 a6  call  0xa00b34d4
a0092640:  93 e8 20 04  restore  %g0, 4, %o1
a0092644:  01 00 00 00  nop
