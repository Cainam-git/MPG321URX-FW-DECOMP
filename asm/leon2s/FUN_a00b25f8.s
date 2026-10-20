# leon2s FUN_a00b25f8 0xa00b25f8-0xa00b2790 (408 bytes)
a00b25f8:  9d e3 bf 98  save  %sp, -104, %sp
a00b25fc:  a0 96 20 00  orcc  %i0, 0, %l0
a00b2600:  02 80 00 62  be  0xa00b2788
a00b2604:  b0 10 20 00  clr  %i0
a00b2608:  96 10 20 00  clr  %o3
a00b260c:  d8 4c 00 0b  ldsb  [ %l0 + %o3 ], %o4
a00b2610:  82 1b 20 0a  xor  %o4, 0xa, %g1
a00b2614:  80 a0 00 01  cmp  %g0, %g1
a00b2618:  9a 60 3f ff  subx  %g0, -1, %o5
a00b261c:  82 1b 20 0d  xor  %o4, 0xd, %g1
a00b2620:  80 a0 00 01  cmp  %g0, %g1
a00b2624:  82 60 3f ff  subx  %g0, -1, %g1
a00b2628:  80 93 40 01  orcc  %o5, %g1, %g0
a00b262c:  12 80 00 08  bne  0xa00b264c
a00b2630:  80 a3 20 00  cmp  %o4, 0
a00b2634:  02 80 00 07  be  0xa00b2650
a00b2638:  80 a2 e0 20  cmp  %o3, 0x20
a00b263c:  96 02 e0 01  inc  %o3
a00b2640:  80 a2 e0 1f  cmp  %o3, 0x1f
a00b2644:  24 bf ff f3  ble,a   0xa00b2610
a00b2648:  d8 4c 00 0b  ldsb  [ %l0 + %o3 ], %o4
a00b264c:  80 a2 e0 20  cmp  %o3, 0x20
a00b2650:  22 80 00 02  be,a   0xa00b2658
a00b2654:  96 10 20 1f  mov  0x1f, %o3
a00b2658:  c0 2c 00 0b  clrb  [ %l0 + %o3 ]
a00b265c:  7f ff fb b7  call  0xa00b1538
a00b2660:  90 10 00 10  mov  %l0, %o0
a00b2664:  c2 4c 00 00  ldsb  [ %l0 ], %g1
a00b2668:  80 a0 60 30  cmp  %g1, 0x30
a00b266c:  12 80 00 31  bne  0xa00b2730
a00b2670:  92 10 20 00  clr  %o1
a00b2674:  c2 4c 20 01  ldsb  [ %l0 + 1 ], %g1
a00b2678:  9a 18 60 58  xor  %g1, 0x58, %o5
a00b267c:  80 a0 00 0d  cmp  %g0, %o5
a00b2680:  9a 60 3f ff  subx  %g0, -1, %o5
a00b2684:  82 18 60 78  xor  %g1, 0x78, %g1
a00b2688:  80 a0 00 01  cmp  %g0, %g1
a00b268c:  82 60 3f ff  subx  %g0, -1, %g1
a00b2690:  80 93 40 01  orcc  %o5, %g1, %g0
a00b2694:  02 80 00 28  be  0xa00b2734
a00b2698:  80 a2 20 08  cmp  %o0, 8
a00b269c:  96 10 20 02  mov  2, %o3
a00b26a0:  80 a2 c0 08  cmp  %o3, %o0
a00b26a4:  36 80 00 39  bge,a   0xa00b2788
a00b26a8:  b0 10 00 09  mov  %o1, %i0
a00b26ac:  d4 4c 00 0b  ldsb  [ %l0 + %o3 ], %o2
a00b26b0:  82 1a a0 20  xor  %o2, 0x20, %g1
a00b26b4:  80 a0 00 01  cmp  %g0, %g1
a00b26b8:  9a 60 3f ff  subx  %g0, -1, %o5
a00b26bc:  82 1a a0 09  xor  %o2, 9, %g1
a00b26c0:  80 a0 00 01  cmp  %g0, %g1
a00b26c4:  82 60 3f ff  subx  %g0, -1, %g1
a00b26c8:  80 93 40 01  orcc  %o5, %g1, %g0
a00b26cc:  d8 0c 00 0b  ldub  [ %l0 + %o3 ], %o4
a00b26d0:  82 03 3f d0  add  %o4, -48, %g1
a00b26d4:  9a 03 3f 9f  add  %o4, -97, %o5
a00b26d8:  82 08 60 ff  and  %g1, 0xff, %g1
a00b26dc:  12 80 00 2a  bne  0xa00b2784
a00b26e0:  9e 0b 60 ff  and  %o5, 0xff, %o7
a00b26e4:  80 a0 60 09  cmp  %g1, 9
a00b26e8:  93 2a 60 04  sll  %o1, 4, %o1
a00b26ec:  18 80 00 04  bgu  0xa00b26fc
a00b26f0:  82 02 40 0a  add  %o1, %o2, %g1
a00b26f4:  10 80 00 0d  b  0xa00b2728
a00b26f8:  92 00 7f d0  add  %g1, -48, %o1
a00b26fc:  82 03 3f bf  add  %o4, -65, %g1
a00b2700:  98 02 40 0a  add  %o1, %o2, %o4
a00b2704:  80 a3 e0 05  cmp  %o7, 5
a00b2708:  18 80 00 04  bgu  0xa00b2718
a00b270c:  9a 08 60 ff  and  %g1, 0xff, %o5
a00b2710:  10 80 00 06  b  0xa00b2728
a00b2714:  92 03 3f a9  add  %o4, -87, %o1
a00b2718:  80 a3 60 05  cmp  %o5, 5
a00b271c:  18 80 00 03  bgu  0xa00b2728
a00b2720:  82 02 40 0a  add  %o1, %o2, %g1
a00b2724:  92 00 7f c9  add  %g1, -55, %o1
a00b2728:  10 bf ff de  b  0xa00b26a0
a00b272c:  96 02 e0 01  inc  %o3
a00b2730:  80 a2 20 08  cmp  %o0, 8
a00b2734:  14 80 00 15  bg  0xa00b2788
a00b2738:  b0 10 3f ff  mov  -1, %i0
a00b273c:  10 80 00 04  b  0xa00b274c
a00b2740:  96 10 20 00  clr  %o3
a00b2744:  10 80 00 11  b  0xa00b2788
a00b2748:  b0 10 3f ff  mov  -1, %i0
a00b274c:  80 a2 c0 08  cmp  %o3, %o0
a00b2750:  16 80 00 0d  bge  0xa00b2784
a00b2754:  83 2a 60 02  sll  %o1, 2, %g1
a00b2758:  82 00 40 09  add  %g1, %o1, %g1
a00b275c:  da 4c 00 0b  ldsb  [ %l0 + %o3 ], %o5
a00b2760:  82 00 40 01  add  %g1, %g1, %g1
a00b2764:  82 00 40 0d  add  %g1, %o5, %g1
a00b2768:  9a 03 7f d0  add  %o5, -48, %o5
a00b276c:  96 02 e0 01  inc  %o3
a00b2770:  80 a3 60 09  cmp  %o5, 9
a00b2774:  14 bf ff f4  bg  0xa00b2744
a00b2778:  92 00 7f d0  add  %g1, -48, %o1
a00b277c:  10 bf ff f5  b  0xa00b2750
a00b2780:  80 a2 c0 08  cmp  %o3, %o0
a00b2784:  b0 10 00 09  mov  %o1, %i0
a00b2788:  81 c7 e0 08  ret
a00b278c:  81 e8 00 00  restore
