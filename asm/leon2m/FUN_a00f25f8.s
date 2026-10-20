# leon2m FUN_a00f25f8 0xa00f25f8-0xa00f2708 (272 bytes)
a00f25f8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f25fc:  80 a2 20 07  cmp  %o0, 7
a00f2600:  08 80 00 15  bleu  0xa00f2654
a00f2604:  80 a2 20 05  cmp  %o0, 5
a00f2608:  90 10 20 00  clr  %o0
a00f260c:  96 02 00 08  add  %o0, %o0, %o3
a00f2610:  11 00 06 68  sethi  %hi(0x19a000), %o0
a00f2614:  82 12 22 ec  or  %o0, 0x2ec, %g1	! 0x19a2ec
a00f2618:  da 10 40 0b  lduh  [ %g1 + %o3 ], %o5
a00f261c:  98 0a 60 ff  and  %o1, 0xff, %o4
a00f2620:  96 03 40 0c  add  %o5, %o4, %o3
a00f2624:  90 02 e0 01  add  %o3, 1, %o0
a00f2628:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00f262c:  93 2a e0 02  sll  %o3, 2, %o1
a00f2630:  9a 12 40 01  or  %o1, %g1, %o5
a00f2634:  99 2a 20 02  sll  %o0, 2, %o4
a00f2638:  96 13 00 01  or  %o4, %g1, %o3
a00f263c:  d0 03 40 00  ld  [ %o5 ], %o0
a00f2640:  d2 02 c0 00  ld  [ %o3 ], %o1
a00f2644:  83 2a 60 08  sll  %o1, 8, %g1
a00f2648:  98 0a 20 ff  and  %o0, 0xff, %o4
a00f264c:  10 80 00 2c  b  0xa00f26fc
a00f2650:  82 10 40 0c  or  %g1, %o4, %g1
a00f2654:  08 bf ff ee  bleu  0xa00f260c
a00f2658:  98 0a 60 ff  and  %o1, 0xff, %o4
a00f265c:  80 a3 20 a0  cmp  %o4, 0xa0
a00f2660:  02 80 00 16  be  0xa00f26b8
a00f2664:  9a 02 00 08  add  %o0, %o0, %o5
a00f2668:  9a 02 00 08  add  %o0, %o0, %o5
a00f266c:  90 10 00 0d  mov  %o5, %o0
a00f2670:  80 a3 20 be  cmp  %o4, 0xbe
a00f2674:  02 80 00 1b  be  0xa00f26e0
a00f2678:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00f267c:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f2680:  90 10 62 ec  or  %g1, 0x2ec, %o0	! 0x19a2ec
a00f2684:  d2 12 00 0d  lduh  [ %o0 + %o5 ], %o1
a00f2688:  82 02 40 0c  add  %o1, %o4, %g1
a00f268c:  90 00 60 01  add  %g1, 1, %o0
a00f2690:  9b 28 60 02  sll  %g1, 2, %o5
a00f2694:  82 13 40 0b  or  %o5, %o3, %g1
a00f2698:  93 2a 20 02  sll  %o0, 2, %o1
a00f269c:  d0 00 40 00  ld  [ %g1 ], %o0
a00f26a0:  98 12 40 0b  or  %o1, %o3, %o4
a00f26a4:  da 03 00 00  ld  [ %o4 ], %o5
a00f26a8:  83 2b 60 08  sll  %o5, 8, %g1
a00f26ac:  92 0a 20 ff  and  %o0, 0xff, %o1
a00f26b0:  10 80 00 13  b  0xa00f26fc
a00f26b4:  82 10 40 09  or  %g1, %o1, %g1
a00f26b8:  17 00 06 68  sethi  %hi(0x19a000), %o3
a00f26bc:  98 12 e2 ec  or  %o3, 0x2ec, %o4	! 0x19a2ec
a00f26c0:  da 13 00 0d  lduh  [ %o4 + %o5 ], %o5
a00f26c4:  92 03 60 60  add  %o5, 0x60, %o1
a00f26c8:  9b 2a 60 02  sll  %o1, 2, %o5
a00f26cc:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00f26d0:  96 13 40 01  or  %o5, %g1, %o3
a00f26d4:  d0 02 c0 00  ld  [ %o3 ], %o0
a00f26d8:  10 80 00 09  b  0xa00f26fc
a00f26dc:  82 10 00 08  mov  %o0, %g1
a00f26e0:  19 00 06 68  sethi  %hi(0x19a000), %o4
a00f26e4:  9a 13 22 ec  or  %o4, 0x2ec, %o5	! 0x19a2ec
a00f26e8:  d2 13 40 08  lduh  [ %o5 + %o0 ], %o1
a00f26ec:  82 02 60 5d  add  %o1, 0x5d, %g1
a00f26f0:  9b 28 60 02  sll  %g1, 2, %o5
a00f26f4:  10 bf ff f7  b  0xa00f26d0
a00f26f8:  82 10 00 0b  mov  %o3, %g1
a00f26fc:  97 28 60 10  sll  %g1, 0x10, %o3
a00f2700:  81 c3 e0 08  retl
a00f2704:  91 32 e0 10  srl  %o3, 0x10, %o0
