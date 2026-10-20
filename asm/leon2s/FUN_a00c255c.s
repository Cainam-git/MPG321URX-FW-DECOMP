# leon2s FUN_a00c255c 0xa00c255c-0xa00c2758 (508 bytes)
a00c255c:  9d e3 bf 98  save  %sp, -104, %sp
a00c2560:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c2564:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c2568:  a2 10 62 b9  or  %g1, 0x2b9, %l1	! 0xa8078eb9
a00c256c:  90 10 00 18  mov  %i0, %o0
a00c2570:  92 10 20 0c  mov  0xc, %o1
a00c2574:  40 3b d6 5b  call  0xa0fb7ee0
a00c2578:  94 10 20 18  mov  0x18, %o2
a00c257c:  90 10 00 18  mov  %i0, %o0
a00c2580:  b2 10 20 00  clr  %i1
a00c2584:  a4 04 60 20  add  %l1, 0x20, %l2
a00c2588:  92 10 20 0c  mov  0xc, %o1
a00c258c:  40 3b d6 55  call  0xa0fb7ee0
a00c2590:  94 10 20 10  mov  0x10, %o2
a00c2594:  82 0e 60 ff  and  %i1, 0xff, %g1
a00c2598:  d4 0c 80 01  ldub  [ %l2 + %g1 ], %o2
a00c259c:  90 10 00 18  mov  %i0, %o0
a00c25a0:  40 3b d6 50  call  0xa0fb7ee0
a00c25a4:  92 10 20 0d  mov  0xd, %o1
a00c25a8:  b2 06 60 01  inc  %i1
a00c25ac:  82 0e 60 ff  and  %i1, 0xff, %g1
a00c25b0:  80 a0 60 5e  cmp  %g1, 0x5e
a00c25b4:  28 bf ff fa  bleu,a   0xa00c259c
a00c25b8:  d4 0c 80 01  ldub  [ %l2 + %g1 ], %o2
a00c25bc:  90 10 00 18  mov  %i0, %o0
a00c25c0:  92 10 20 0a  mov  0xa, %o1
a00c25c4:  40 3b d6 47  call  0xa0fb7ee0
a00c25c8:  94 10 20 44  mov  0x44, %o2
a00c25cc:  10 80 00 05  b  0xa00c25e0
a00c25d0:  b2 10 3f ff  mov  -1, %i1
a00c25d4:  80 8e 60 ff  btst  0xff, %i1
a00c25d8:  02 80 00 09  be  0xa00c25fc
a00c25dc:  90 10 00 18  mov  %i0, %o0
a00c25e0:  90 10 00 18  mov  %i0, %o0
a00c25e4:  40 3b d6 6f  call  0xa0fb7fa0
a00c25e8:  92 10 20 0a  mov  0xa, %o1
a00c25ec:  80 8a 20 04  btst  4, %o0
a00c25f0:  12 bf ff f9  bne  0xa00c25d4
a00c25f4:  b2 06 7f ff  add  %i1, -1, %i1
a00c25f8:  90 10 00 18  mov  %i0, %o0
a00c25fc:  92 10 20 0c  mov  0xc, %o1
a00c2600:  40 3b d6 38  call  0xa0fb7ee0
a00c2604:  94 10 20 28  mov  0x28, %o2
a00c2608:  90 10 00 18  mov  %i0, %o0
a00c260c:  92 10 20 0c  mov  0xc, %o1
a00c2610:  40 3b d6 34  call  0xa0fb7ee0
a00c2614:  94 10 20 20  mov  0x20, %o2
a00c2618:  b2 10 20 00  clr  %i1
a00c261c:  90 10 00 18  mov  %i0, %o0
a00c2620:  40 3b d6 60  call  0xa0fb7fa0
a00c2624:  92 10 20 0d  mov  0xd, %o1
a00c2628:  98 0e 60 ff  and  %i1, 0xff, %o4
a00c262c:  c2 0c 40 0c  ldub  [ %l1 + %o4 ], %g1
a00c2630:  90 1a 00 01  xor  %o0, %g1, %o0
a00c2634:  21 2a 01 e3  sethi  %hi(0xa8078c00), %l0
a00c2638:  b2 06 60 01  inc  %i1
a00c263c:  82 14 20 b8  or  %l0, 0xb8, %g1
a00c2640:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00c2644:  80 a3 60 1f  cmp  %o5, 0x1f
a00c2648:  08 bf ff f5  bleu  0xa00c261c
a00c264c:  d0 28 40 0c  stb  %o0, [ %g1 + %o4 ]
a00c2650:  90 10 00 18  mov  %i0, %o0
a00c2654:  92 10 20 0c  mov  0xc, %o1
a00c2658:  40 3b d6 22  call  0xa0fb7ee0
a00c265c:  94 10 20 18  mov  0x18, %o2
a00c2660:  90 10 00 18  mov  %i0, %o0
a00c2664:  92 10 20 0c  mov  0xc, %o1
a00c2668:  40 3b d6 1e  call  0xa0fb7ee0
a00c266c:  94 10 20 10  mov  0x10, %o2
a00c2670:  b2 10 20 00  clr  %i1
a00c2674:  82 0e 60 ff  and  %i1, 0xff, %g1
a00c2678:  9a 14 20 b8  or  %l0, 0xb8, %o5
a00c267c:  d4 0b 40 01  ldub  [ %o5 + %g1 ], %o2
a00c2680:  90 10 00 18  mov  %i0, %o0
a00c2684:  40 3b d6 17  call  0xa0fb7ee0
a00c2688:  92 10 20 0d  mov  0xd, %o1
a00c268c:  b2 06 60 01  inc  %i1
a00c2690:  82 0e 60 ff  and  %i1, 0xff, %g1
a00c2694:  80 a0 60 1f  cmp  %g1, 0x1f
a00c2698:  08 bf ff f9  bleu  0xa00c267c
a00c269c:  9a 14 20 b8  or  %l0, 0xb8, %o5
a00c26a0:  90 10 00 18  mov  %i0, %o0
a00c26a4:  92 10 20 0a  mov  0xa, %o1
a00c26a8:  40 3b d6 0e  call  0xa0fb7ee0
a00c26ac:  94 10 20 42  mov  0x42, %o2
a00c26b0:  10 80 00 05  b  0xa00c26c4
a00c26b4:  b2 10 3f ff  mov  -1, %i1
a00c26b8:  80 8e 60 ff  btst  0xff, %i1
a00c26bc:  02 80 00 09  be  0xa00c26e0
a00c26c0:  90 10 00 18  mov  %i0, %o0
a00c26c4:  90 10 00 18  mov  %i0, %o0
a00c26c8:  40 3b d6 36  call  0xa0fb7fa0
a00c26cc:  92 10 20 0a  mov  0xa, %o1
a00c26d0:  80 8a 20 02  btst  2, %o0
a00c26d4:  12 bf ff f9  bne  0xa00c26b8
a00c26d8:  b2 06 7f ff  add  %i1, -1, %i1
a00c26dc:  90 10 00 18  mov  %i0, %o0
a00c26e0:  92 10 20 0c  mov  0xc, %o1
a00c26e4:  40 3b d5 ff  call  0xa0fb7ee0
a00c26e8:  94 10 20 28  mov  0x28, %o2
a00c26ec:  90 10 00 18  mov  %i0, %o0
a00c26f0:  92 10 20 0c  mov  0xc, %o1
a00c26f4:  40 3b d5 fb  call  0xa0fb7ee0
a00c26f8:  94 10 20 20  mov  0x20, %o2
a00c26fc:  b2 10 20 00  clr  %i1
a00c2700:  90 10 00 18  mov  %i0, %o0
a00c2704:  40 3b d6 27  call  0xa0fb7fa0
a00c2708:  92 10 20 0d  mov  0xd, %o1
a00c270c:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00c2710:  b2 06 60 01  inc  %i1
a00c2714:  82 14 20 b8  or  %l0, 0xb8, %g1
a00c2718:  96 0e 60 ff  and  %i1, 0xff, %o3
a00c271c:  80 a3 60 4d  cmp  %o5, 0x4d
a00c2720:  08 80 00 05  bleu  0xa00c2734
a00c2724:  98 03 40 01  add  %o5, %g1, %o4
a00c2728:  c2 0c 80 0d  ldub  [ %l2 + %o5 ], %g1
a00c272c:  82 18 40 08  xor  %g1, %o0, %g1
a00c2730:  c2 2b 3f b2  stb  %g1, [ %o4 + -78 ]
a00c2734:  80 a2 e0 5e  cmp  %o3, 0x5e
a00c2738:  08 bf ff f3  bleu  0xa00c2704
a00c273c:  90 10 00 18  mov  %i0, %o0
a00c2740:  31 27 c6 dd  sethi  %hi(0x9f1b7400), %i0
a00c2744:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c2748:  f2 08 60 b8  ldub  [ %g1 + 0xb8 ], %i1	! 0xa8078cb8
a00c274c:  40 3b 02 3e  call  0xa0f83044
a00c2750:  91 ee 21 70  restore  %i0, 0x170, %o0
a00c2754:  01 00 00 00  nop
