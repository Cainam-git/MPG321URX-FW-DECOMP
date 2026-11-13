# leon2m FUN_a00a2600 0xa00a2600-0xa00a27a4 (312 bytes)
a00a2600:  9d e3 bf 98  save  %sp, -104, %sp
a00a2604:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00a2608:  c2 0c 20 56  ldub  [ %l0 + 0x56 ], %g1	! 0xa8025c56
a00a260c:  80 a0 60 01  cmp  %g1, 1
a00a2610:  04 80 00 07  ble  0xa00a262c
a00a2614:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00a2618:  80 a0 60 02  cmp  %g1, 2
a00a261c:  12 80 00 60  bne  0xa00a279c
a00a2620:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00a2624:  10 80 00 23  b  0xa00a26b0
a00a2628:  e4 08 60 7d  ldub  [ %g1 + 0x7d ], %l2	! 0xa802d47d
a00a262c:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1
a00a2630:  82 00 7f 40  add  %g1, -192, %g1
a00a2634:  80 a0 60 39  cmp  %g1, 0x39
a00a2638:  08 80 00 18  bleu  0xa00a2698
a00a263c:  92 10 20 00  clr  %o1
a00a2640:  92 10 20 00  clr  %o1
a00a2644:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00a2648:  94 10 20 00  clr  %o2
a00a264c:  40 00 16 bc  call  0xa00a813c
a00a2650:  90 10 20 01  mov  1, %o0
a00a2654:  98 14 a2 90  or  %l2, 0x290, %o4
a00a2658:  e4 0c 20 56  ldub  [ %l0 + 0x56 ], %l2
a00a265c:  e4 2b 21 ec  stb  %l2, [ %o4 + 0x1ec ]
a00a2660:  40 00 1b 57  call  0xa00a93bc
a00a2664:  90 0c a0 ff  and  %l2, 0xff, %o0
a00a2668:  d2 04 63 ec  ld  [ %l1 + 0x3ec ], %o1
a00a266c:  82 02 7f 40  add  %o1, -192, %g1
a00a2670:  80 a0 60 39  cmp  %g1, 0x39
a00a2674:  94 14 63 ec  or  %l1, 0x3ec, %o2
a00a2678:  18 80 00 18  bgu  0xa00a26d8
a00a267c:  96 10 20 00  clr  %o3
a00a2680:  13 00 00 c3  sethi  %hi(0x30c00), %o1
a00a2684:  9f 28 60 02  sll  %g1, 2, %o7
a00a2688:  9a 12 62 48  or  %o1, 0x248, %o5
a00a268c:  d0 03 40 0f  ld  [ %o5 + %o7 ], %o0
a00a2690:  81 c2 00 00  jmp  %o0
a00a2694:  01 00 00 00  nop
a00a2698:  15 00 00 c3  sethi  %hi(0x30c00), %o2
a00a269c:  91 28 60 02  sll  %g1, 2, %o0
a00a26a0:  9a 12 a1 60  or  %o2, 0x160, %o5
a00a26a4:  d8 03 40 08  ld  [ %o5 + %o0 ], %o4
a00a26a8:  81 c3 00 00  jmp  %o4
a00a26ac:  01 00 00 00  nop
a00a26b0:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a00a26b4:  7f ff fc ed  call  0xa00a1a68
a00a26b8:  e4 2c 60 55  stb  %l2, [ %l1 + 0x55 ]	! 0xa8025c55
a00a26bc:  40 00 e1 35  call  0xa00dab90
a00a26c0:  01 00 00 00  nop
a00a26c4:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00a26c8:  de 0b 20 8e  ldub  [ %o4 + 0x8e ], %o7	! 0xa802b08e
a00a26cc:  90 13 e0 02  or  %o7, 2, %o0
a00a26d0:  10 80 00 33  b  0xa00a279c
a00a26d4:  d0 2b 20 8e  stb  %o0, [ %o4 + 0x8e ]
a00a26d8:  82 10 20 00  clr  %g1
a00a26dc:  96 00 60 34  add  %g1, 0x34, %o3
a00a26e0:  d6 22 80 00  st  %o3, [ %o2 ]
a00a26e4:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0
a00a26e8:  40 00 1b da  call  0xa00a9650
a00a26ec:  92 10 20 00  clr  %o1
a00a26f0:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a00a26f4:  94 10 20 01  mov  1, %o2
a00a26f8:  40 00 16 91  call  0xa00a813c
a00a26fc:  90 10 20 01  mov  1, %o0
a00a2700:  d4 04 63 ec  ld  [ %l1 + 0x3ec ], %o2
a00a2704:  a0 02 bf cc  add  %o2, -52, %l0
a00a2708:  90 0c 20 ff  and  %l0, 0xff, %o0
a00a270c:  40 00 1a 40  call  0xa00a900c
a00a2710:  92 10 20 01  mov  1, %o1
a00a2714:  90 10 20 01  mov  1, %o0
a00a2718:  40 00 1b 54  call  0xa00a9468
a00a271c:  92 10 20 02  mov  2, %o1
a00a2720:  90 10 20 00  clr  %o0
a00a2724:  40 00 43 6c  call  0xa00b34d4
a00a2728:  92 10 20 01  mov  1, %o1
a00a272c:  30 bf ff e4  b,a   0xa00a26bc
a00a2730:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00a2734:  10 bf ff c5  b  0xa00a2648
a00a2738:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a273c:  96 10 20 06  mov  6, %o3
a00a2740:  10 bf ff e7  b  0xa00a26dc
a00a2744:  82 0a e0 ff  and  %o3, 0xff, %g1
a00a2748:  96 10 20 05  mov  5, %o3
a00a274c:  10 bf ff e4  b  0xa00a26dc
a00a2750:  82 0a e0 ff  and  %o3, 0xff, %g1
a00a2754:  96 10 20 04  mov  4, %o3
a00a2758:  10 bf ff e1  b  0xa00a26dc
a00a275c:  82 0a e0 ff  and  %o3, 0xff, %g1
a00a2760:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00a2764:  82 14 a2 90  or  %l2, 0x290, %g1	! 0xa802d290
a00a2768:  d2 08 61 ec  ldub  [ %g1 + 0x1ec ], %o1
a00a276c:  10 bf ff b7  b  0xa00a2648
a00a2770:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a2774:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00a2778:  9e 14 a2 90  or  %l2, 0x290, %o7	! 0xa802d290
a00a277c:  d2 0b e1 ea  ldub  [ %o7 + 0x1ea ], %o1
a00a2780:  10 bf ff b2  b  0xa00a2648
a00a2784:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a2788:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00a278c:  96 14 a2 90  or  %l2, 0x290, %o3	! 0xa802d290
a00a2790:  d2 0a e1 e8  ldub  [ %o3 + 0x1e8 ], %o1
a00a2794:  10 bf ff ad  b  0xa00a2648
a00a2798:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a279c:  81 c7 e0 08  ret
a00a27a0:  81 e8 00 00  restore
