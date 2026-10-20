# leon2s FUN_a0092500 0xa0092500-0xa00925b8 (184 bytes)
a0092500:  9d e3 bf 98  save  %sp, -104, %sp
a0092504:  a2 0e 20 ff  and  %i0, 0xff, %l1
a0092508:  90 10 00 11  mov  %l1, %o0
a009250c:  92 10 20 00  clr  %o1
a0092510:  94 10 21 40  mov  0x140, %o2
a0092514:  40 00 56 d0  call  0xa00a8054
a0092518:  d6 0e 40 00  ldub  [ %i1 ], %o3
a009251c:  90 10 00 11  mov  %l1, %o0
a0092520:  92 10 20 00  clr  %o1
a0092524:  94 10 21 41  mov  0x141, %o2
a0092528:  40 00 56 cb  call  0xa00a8054
a009252c:  d6 0e 60 01  ldub  [ %i1 + 1 ], %o3
a0092530:  90 10 00 11  mov  %l1, %o0
a0092534:  92 10 20 00  clr  %o1
a0092538:  94 10 21 42  mov  0x142, %o2
a009253c:  40 00 56 c6  call  0xa00a8054
a0092540:  d6 0e 60 02  ldub  [ %i1 + 2 ], %o3
a0092544:  c2 0e 60 02  ldub  [ %i1 + 2 ], %g1
a0092548:  80 a0 60 00  cmp  %g1, 0
a009254c:  b6 10 20 00  clr  %i3
a0092550:  02 80 00 13  be  0xa009259c
a0092554:  b4 10 20 00  clr  %i2
a0092558:  94 0e a0 ff  and  %i2, 0xff, %o2
a009255c:  a0 0e a0 ff  and  %i2, 0xff, %l0
a0092560:  94 02 a1 44  add  %o2, 0x144, %o2
a0092564:  a0 06 40 10  add  %i1, %l0, %l0
a0092568:  95 2a a0 10  sll  %o2, 0x10, %o2
a009256c:  95 32 a0 10  srl  %o2, 0x10, %o2
a0092570:  90 10 00 11  mov  %l1, %o0
a0092574:  92 10 20 00  clr  %o1
a0092578:  40 00 56 b7  call  0xa00a8054
a009257c:  d6 0c 20 04  ldub  [ %l0 + 4 ], %o3
a0092580:  b4 06 a0 01  inc  %i2
a0092584:  d8 0c 20 04  ldub  [ %l0 + 4 ], %o4
a0092588:  9a 0e a0 ff  and  %i2, 0xff, %o5
a009258c:  c2 0e 60 02  ldub  [ %i1 + 2 ], %g1
a0092590:  80 a3 40 01  cmp  %o5, %g1
a0092594:  0a bf ff f1  bcs  0xa0092558
a0092598:  b6 06 c0 0c  add  %i3, %o4, %i3
a009259c:  b6 20 00 1b  neg  %i3
a00925a0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00925a4:  b6 0e e0 ff  and  %i3, 0xff, %i3
a00925a8:  b2 10 20 00  clr  %i1
a00925ac:  40 00 56 aa  call  0xa00a8054
a00925b0:  95 e8 21 43  restore  %g0, 0x143, %o2
a00925b4:  01 00 00 00  nop
