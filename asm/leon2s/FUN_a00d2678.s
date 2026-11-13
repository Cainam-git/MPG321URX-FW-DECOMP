# leon2s FUN_a00d2678 0xa00d2678-0xa00d27fc (388 bytes)
a00d2678:  9d e3 bf 90  save  %sp, -112, %sp
a00d267c:  c0 27 bf f4  clr  [ %fp + -12 ]
a00d2680:  80 a6 20 00  cmp  %i0, 0
a00d2684:  02 80 00 07  be  0xa00d26a0
a00d2688:  a6 10 20 00  clr  %l3
a00d268c:  80 a6 20 01  cmp  %i0, 1
a00d2690:  12 80 00 05  bne  0xa00d26a4
a00d2694:  21 34 00 4f  sethi  %hi(0xd0013c00), %l0
a00d2698:  03 27 c7 0f  sethi  %hi(0x9f1c3c00), %g1
a00d269c:  a6 10 63 a0  or  %g1, 0x3a0, %l3	! 0x9f1c3fa0
a00d26a0:  21 34 00 4f  sethi  %hi(0xd0013c00), %l0
a00d26a4:  40 3a 7b a1  call  0xa0f71528
a00d26a8:  90 14 23 e0  or  %l0, 0x3e0, %o0	! 0xd0013fe0
a00d26ac:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d26b0:  90 07 bf f4  add  %fp, -12, %o0
a00d26b4:  92 10 20 02  mov  2, %o1
a00d26b8:  94 10 20 00  clr  %o2
a00d26bc:  40 3a 7b 7f  call  0xa0f714b8
a00d26c0:  96 10 20 07  mov  7, %o3
a00d26c4:  90 14 23 e0  or  %l0, 0x3e0, %o0
a00d26c8:  40 3a 7b 9b  call  0xa0f71534
a00d26cc:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d26d0:  b0 10 20 00  clr  %i0
a00d26d4:  a0 10 20 00  clr  %l0
a00d26d8:  a2 10 20 00  clr  %l1
a00d26dc:  96 10 00 11  mov  %l1, %o3
a00d26e0:  94 10 20 08  mov  8, %o2
a00d26e4:  90 07 bf f4  add  %fp, -12, %o0
a00d26e8:  40 3a 7b 74  call  0xa0f714b8
a00d26ec:  92 10 20 12  mov  0x12, %o1
a00d26f0:  11 34 00 4f  sethi  %hi(0xd0013c00), %o0
a00d26f4:  90 12 23 e0  or  %o0, 0x3e0, %o0	! 0xd0013fe0
a00d26f8:  40 3a 7b 8f  call  0xa0f71534
a00d26fc:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d2700:  80 a0 00 13  cmp  %g0, %l3
a00d2704:  9a 40 20 00  addx  %g0, 0, %o5
a00d2708:  80 a6 2f ff  cmp  %i0, 0xfff
a00d270c:  82 40 20 00  addx  %g0, 0, %g1
a00d2710:  80 8b 40 01  btst  %o5, %g1
a00d2714:  02 80 00 0f  be  0xa00d2750
a00d2718:  25 34 00 4f  sethi  %hi(0xd0013c00), %l2
a00d271c:  da 0c c0 10  ldub  [ %l3 + %l0 ], %o5
a00d2720:  82 0b 60 0f  and  %o5, 0xf, %g1
a00d2724:  80 a3 60 ef  cmp  %o5, 0xef
a00d2728:  18 80 00 04  bgu  0xa00d2738
a00d272c:  99 28 60 08  sll  %g1, 8, %o4
a00d2730:  10 80 00 06  b  0xa00d2748
a00d2734:  b0 06 00 0d  add  %i0, %o5, %i0
a00d2738:  a0 04 20 01  inc  %l0
a00d273c:  c2 0c c0 10  ldub  [ %l3 + %l0 ], %g1
a00d2740:  82 03 00 01  add  %o4, %g1, %g1
a00d2744:  b0 06 00 01  add  %i0, %g1, %i0
a00d2748:  a0 04 20 01  inc  %l0
a00d274c:  25 34 00 4f  sethi  %hi(0xd0013c00), %l2
a00d2750:  90 14 a3 ec  or  %l2, 0x3ec, %o0	! 0xd0013fec
a00d2754:  80 a4 64 00  cmp  %l1, 0x400
a00d2758:  02 80 00 04  be  0xa00d2768
a00d275c:  92 10 00 18  mov  %i0, %o1
a00d2760:  10 80 00 0c  b  0xa00d2790
a00d2764:  90 14 a3 e8  or  %l2, 0x3e8, %o0
a00d2768:  40 3a 7b 70  call  0xa0f71528
a00d276c:  01 00 00 00  nop
a00d2770:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d2774:  90 07 bf f4  add  %fp, -12, %o0
a00d2778:  92 10 20 0b  mov  0xb, %o1
a00d277c:  94 10 20 00  clr  %o2
a00d2780:  7f ff fe 98  call  0xa00d21e0
a00d2784:  96 10 2f ff  mov  0xfff, %o3
a00d2788:  90 14 a3 ec  or  %l2, 0x3ec, %o0
a00d278c:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d2790:  40 3a 7b 69  call  0xa0f71534
a00d2794:  a2 04 60 01  inc  %l1
a00d2798:  80 a4 64 00  cmp  %l1, 0x400
a00d279c:  28 bf ff d1  bleu,a   0xa00d26e0
a00d27a0:  96 10 00 11  mov  %l1, %o3
a00d27a4:  21 34 00 4f  sethi  %hi(0xd0013c00), %l0
a00d27a8:  40 3a 7b 60  call  0xa0f71528
a00d27ac:  90 14 23 ec  or  %l0, 0x3ec, %o0	! 0xd0013fec
a00d27b0:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d27b4:  94 10 20 1e  mov  0x1e, %o2
a00d27b8:  96 10 20 00  clr  %o3
a00d27bc:  90 07 bf f4  add  %fp, -12, %o0
a00d27c0:  40 3a 7b 3e  call  0xa0f714b8
a00d27c4:  92 10 20 1f  mov  0x1f, %o1
a00d27c8:  90 14 23 ec  or  %l0, 0x3ec, %o0
a00d27cc:  40 3a 7b 5a  call  0xa0f71534
a00d27d0:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d27d4:  90 07 bf f4  add  %fp, -12, %o0
a00d27d8:  92 10 20 1f  mov  0x1f, %o1
a00d27dc:  94 10 20 1e  mov  0x1e, %o2
a00d27e0:  40 3a 7b 36  call  0xa0f714b8
a00d27e4:  96 10 20 03  mov  3, %o3
a00d27e8:  90 14 23 ec  or  %l0, 0x3ec, %o0
a00d27ec:  40 3a 7b 52  call  0xa0f71534
a00d27f0:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d27f4:  81 c7 e0 08  ret
a00d27f8:  91 e8 20 01  restore  %g0, 1, %o0
