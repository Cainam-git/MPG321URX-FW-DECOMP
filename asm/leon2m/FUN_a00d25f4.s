# leon2m FUN_a00d25f4 0xa00d25f4-0xa00d27ac (440 bytes)
a00d25f4:  9d e3 bf 98  save  %sp, -104, %sp
a00d25f8:  c2 0e 20 06  ldub  [ %i0 + 6 ], %g1
a00d25fc:  80 a0 60 00  cmp  %g1, 0
a00d2600:  12 80 00 0a  bne  0xa00d2628
a00d2604:  80 a0 60 01  cmp  %g1, 1
a00d2608:  f0 0e 20 07  ldub  [ %i0 + 7 ], %i0
a00d260c:  80 a6 20 01  cmp  %i0, 1
a00d2610:  02 80 00 20  be  0xa00d2690
a00d2614:  80 a6 20 00  cmp  %i0, 0
a00d2618:  32 80 00 63  bne,a   0xa00d27a4
a00d261c:  b0 10 20 e0  mov  0xe0, %i0
a00d2620:  10 80 00 2e  b  0xa00d26d8
a00d2624:  90 10 20 00  clr  %o0
a00d2628:  32 80 00 5f  bne,a   0xa00d27a4
a00d262c:  b0 10 20 e0  mov  0xe0, %i0
a00d2630:  f0 0e 20 07  ldub  [ %i0 + 7 ], %i0
a00d2634:  80 a6 20 00  cmp  %i0, 0
a00d2638:  02 80 00 3a  be  0xa00d2720
a00d263c:  80 a6 20 01  cmp  %i0, 1
a00d2640:  02 80 00 3c  be  0xa00d2730
a00d2644:  80 a6 20 02  cmp  %i0, 2
a00d2648:  02 80 00 40  be  0xa00d2748
a00d264c:  80 a6 20 03  cmp  %i0, 3
a00d2650:  02 80 00 44  be  0xa00d2760
a00d2654:  80 a6 20 04  cmp  %i0, 4
a00d2658:  02 80 00 48  be  0xa00d2778
a00d265c:  80 a6 20 05  cmp  %i0, 5
a00d2660:  02 80 00 2a  be  0xa00d2708
a00d2664:  80 a6 20 06  cmp  %i0, 6
a00d2668:  02 80 00 4a  be  0xa00d2790
a00d266c:  80 a6 20 07  cmp  %i0, 7
a00d2670:  32 80 00 4d  bne,a   0xa00d27a4
a00d2674:  b0 10 20 e0  mov  0xe0, %i0
a00d2678:  40 01 53 ce  call  0xa01275b0
a00d267c:  90 10 20 01  mov  1, %o0
a00d2680:  40 01 54 29  call  0xa0127724
a00d2684:  90 10 20 00  clr  %o0
a00d2688:  10 80 00 47  b  0xa00d27a4
a00d268c:  b0 10 20 e0  mov  0xe0, %i0
a00d2690:  96 10 20 ff  mov  0xff, %o3
a00d2694:  98 10 20 01  mov  1, %o4
a00d2698:  90 10 20 00  clr  %o0
a00d269c:  92 10 20 ff  mov  0xff, %o1
a00d26a0:  40 01 ce 52  call  0xa0145fe8
a00d26a4:  94 10 20 ff  mov  0xff, %o2
a00d26a8:  92 10 21 00  mov  0x100, %o1
a00d26ac:  94 10 21 00  mov  0x100, %o2
a00d26b0:  40 01 ce 44  call  0xa0145fc0
a00d26b4:  90 10 21 00  mov  0x100, %o0
a00d26b8:  40 01 c4 53  call  0xa0143804
a00d26bc:  90 10 23 ff  mov  0x3ff, %o0
a00d26c0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d26c4:  a0 10 62 90  or  %g1, 0x290, %l0	! 0xa802d290
a00d26c8:  40 00 15 c6  call  0xa00d7de0
a00d26cc:  e2 0c 20 0a  ldub  [ %l0 + 0xa ], %l1
a00d26d0:  10 80 00 34  b  0xa00d27a0
a00d26d4:  e2 2c 20 0a  stb  %l1, [ %l0 + 0xa ]
a00d26d8:  40 01 d6 e4  call  0xa0148268
a00d26dc:  92 10 20 01  mov  1, %o1
a00d26e0:  90 10 20 01  mov  1, %o0
a00d26e4:  40 01 d6 e1  call  0xa0148268
a00d26e8:  92 10 20 01  mov  1, %o1
a00d26ec:  40 00 19 7a  call  0xa00d8cd4
a00d26f0:  b0 10 20 e0  mov  0xe0, %i0
a00d26f4:  40 00 15 bb  call  0xa00d7de0
a00d26f8:  01 00 00 00  nop
a00d26fc:  40 00 1c 1a  call  0xa00d9764
a00d2700:  01 00 00 00  nop
a00d2704:  30 80 00 28  b,a   0xa00d27a4
a00d2708:  40 01 53 aa  call  0xa01275b0
a00d270c:  90 10 20 01  mov  1, %o0
a00d2710:  40 01 54 05  call  0xa0127724
a00d2714:  90 10 20 05  mov  5, %o0
a00d2718:  10 80 00 23  b  0xa00d27a4
a00d271c:  b0 10 20 e0  mov  0xe0, %i0
a00d2720:  40 01 53 a4  call  0xa01275b0
a00d2724:  90 10 20 00  clr  %o0
a00d2728:  10 80 00 1f  b  0xa00d27a4
a00d272c:  b0 10 20 e0  mov  0xe0, %i0
a00d2730:  40 01 53 a0  call  0xa01275b0
a00d2734:  90 10 20 01  mov  1, %o0
a00d2738:  40 01 53 fb  call  0xa0127724
a00d273c:  90 10 20 01  mov  1, %o0
a00d2740:  10 80 00 19  b  0xa00d27a4
a00d2744:  b0 10 20 e0  mov  0xe0, %i0
a00d2748:  40 01 53 9a  call  0xa01275b0
a00d274c:  90 10 20 01  mov  1, %o0
a00d2750:  40 01 53 f5  call  0xa0127724
a00d2754:  90 10 20 02  mov  2, %o0
a00d2758:  10 80 00 13  b  0xa00d27a4
a00d275c:  b0 10 20 e0  mov  0xe0, %i0
a00d2760:  40 01 53 94  call  0xa01275b0
a00d2764:  90 10 20 01  mov  1, %o0
a00d2768:  40 01 53 ef  call  0xa0127724
a00d276c:  90 10 20 03  mov  3, %o0
a00d2770:  10 80 00 0d  b  0xa00d27a4
a00d2774:  b0 10 20 e0  mov  0xe0, %i0
a00d2778:  40 01 53 8e  call  0xa01275b0
a00d277c:  90 10 20 01  mov  1, %o0
a00d2780:  40 01 53 e9  call  0xa0127724
a00d2784:  90 10 20 04  mov  4, %o0
a00d2788:  10 80 00 07  b  0xa00d27a4
a00d278c:  b0 10 20 e0  mov  0xe0, %i0
a00d2790:  40 01 53 88  call  0xa01275b0
a00d2794:  90 10 20 01  mov  1, %o0
a00d2798:  40 01 53 e3  call  0xa0127724
a00d279c:  90 10 20 06  mov  6, %o0
a00d27a0:  b0 10 20 e0  mov  0xe0, %i0
a00d27a4:  81 c7 e0 08  ret
a00d27a8:  81 e8 00 00  restore
