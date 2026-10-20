# leon2m FUN_a00c25ac 0xa00c25ac-0xa00c29d8 (1068 bytes)
a00c25ac:  9d e3 bf 98  save  %sp, -104, %sp
a00c25b0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c25b4:  80 a6 20 02  cmp  %i0, 2
a00c25b8:  02 80 00 d0  be  0xa00c28f8
a00c25bc:  80 a6 20 03  cmp  %i0, 3
a00c25c0:  02 80 00 d1  be  0xa00c2904
a00c25c4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c25c8:  c2 0a 60 d6  ldub  [ %o1 + 0xd6 ], %g1	! 0xa802d0d6
a00c25cc:  94 08 60 ff  and  %g1, 0xff, %o2
a00c25d0:  80 a6 20 02  cmp  %i0, 2
a00c25d4:  02 80 00 c6  be  0xa00c28ec
a00c25d8:  9a 5a a3 e8  smul  %o2, 0x3e8, %o5
a00c25dc:  80 a6 20 03  cmp  %i0, 3
a00c25e0:  02 80 00 d4  be  0xa00c2930
a00c25e4:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c25e8:  c2 0b e0 d7  ldub  [ %o7 + 0xd7 ], %g1	! 0xa802d0d7
a00c25ec:  82 08 60 ff  and  %g1, 0xff, %g1
a00c25f0:  a0 58 60 64  smul  %g1, 0x64, %l0
a00c25f4:  80 a6 20 02  cmp  %i0, 2
a00c25f8:  02 80 00 ba  be  0xa00c28e0
a00c25fc:  98 03 40 10  add  %o5, %l0, %o4
a00c2600:  80 a6 20 03  cmp  %i0, 3
a00c2604:  02 80 00 c8  be  0xa00c2924
a00c2608:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c260c:  da 0a a0 d8  ldub  [ %o2 + 0xd8 ], %o5	! 0xa802d0d8
a00c2610:  a0 0b 60 ff  and  %o5, 0xff, %l0
a00c2614:  9f 2c 20 02  sll  %l0, 2, %o7
a00c2618:  96 03 c0 10  add  %o7, %l0, %o3
a00c261c:  9a 02 c0 0b  add  %o3, %o3, %o5
a00c2620:  80 a6 20 02  cmp  %i0, 2
a00c2624:  02 80 00 ac  be  0xa00c28d4
a00c2628:  98 03 00 0d  add  %o4, %o5, %o4
a00c262c:  80 a6 20 03  cmp  %i0, 3
a00c2630:  02 80 00 ba  be  0xa00c2918
a00c2634:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c2638:  da 0a 60 d9  ldub  [ %o1 + 0xd9 ], %o5	! 0xa802d0d9
a00c263c:  96 0b 60 ff  and  %o5, 0xff, %o3
a00c2640:  9a 03 00 0b  add  %o4, %o3, %o5
a00c2644:  15 3f ff f4  sethi  %hi(0xffffd000), %o2
a00c2648:  98 12 a0 50  or  %o2, 0x50, %o4	! 0xffffd050
a00c264c:  80 a6 20 02  cmp  %i0, 2
a00c2650:  02 80 00 9e  be  0xa00c28c8
a00c2654:  94 23 40 0c  sub  %o5, %o4, %o2
a00c2658:  80 a6 20 03  cmp  %i0, 3
a00c265c:  02 80 00 ad  be  0xa00c2910
a00c2660:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c2664:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c2668:  c2 08 60 da  ldub  [ %g1 + 0xda ], %g1	! 0xa802d0da
a00c266c:  90 08 60 ff  and  %g1, 0xff, %o0
a00c2670:  80 a6 20 02  cmp  %i0, 2
a00c2674:  02 80 00 92  be  0xa00c28bc
a00c2678:  9a 5a 23 e8  smul  %o0, 0x3e8, %o5
a00c267c:  80 a6 20 03  cmp  %i0, 3
a00c2680:  02 80 00 cf  be  0xa00c29bc
a00c2684:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c2688:  c2 0a e0 db  ldub  [ %o3 + 0xdb ], %g1	! 0xa802d0db
a00c268c:  a0 08 60 ff  and  %g1, 0xff, %l0
a00c2690:  9e 5c 20 64  smul  %l0, 0x64, %o7
a00c2694:  80 a6 20 02  cmp  %i0, 2
a00c2698:  02 80 00 86  be  0xa00c28b0
a00c269c:  98 03 40 0f  add  %o5, %o7, %o4
a00c26a0:  80 a6 20 03  cmp  %i0, 3
a00c26a4:  02 80 00 c3  be  0xa00c29b0
a00c26a8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c26ac:  da 0a 60 dc  ldub  [ %o1 + 0xdc ], %o5	! 0xa802d0dc
a00c26b0:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00c26b4:  a1 2b 60 02  sll  %o5, 2, %l0
a00c26b8:  9e 04 00 0d  add  %l0, %o5, %o7
a00c26bc:  96 03 c0 0f  add  %o7, %o7, %o3
a00c26c0:  80 a6 20 02  cmp  %i0, 2
a00c26c4:  02 80 00 78  be  0xa00c28a4
a00c26c8:  9a 03 00 0b  add  %o4, %o3, %o5
a00c26cc:  80 a6 20 03  cmp  %i0, 3
a00c26d0:  02 80 00 b5  be  0xa00c29a4
a00c26d4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c26d8:  c2 0a 20 dd  ldub  [ %o0 + 0xdd ], %g1	! 0xa802d0dd
a00c26dc:  98 08 60 ff  and  %g1, 0xff, %o4
a00c26e0:  9e 03 40 0c  add  %o5, %o4, %o7
a00c26e4:  1b 3f ff f4  sethi  %hi(0xffffd000), %o5
a00c26e8:  97 2a a0 10  sll  %o2, 0x10, %o3
a00c26ec:  a0 13 60 50  or  %o5, 0x50, %l0
a00c26f0:  93 32 e0 10  srl  %o3, 0x10, %o1
a00c26f4:  82 23 c0 10  sub  %o7, %l0, %g1
a00c26f8:  80 a2 6e a0  cmp  %o1, 0xea0
a00c26fc:  08 80 00 03  bleu  0xa00c2708
a00c2700:  96 10 00 01  mov  %g1, %o3
a00c2704:  94 10 2e a1  mov  0xea1, %o2
a00c2708:  91 28 60 10  sll  %g1, 0x10, %o0
a00c270c:  83 32 20 10  srl  %o0, 0x10, %g1
a00c2710:  80 a0 68 04  cmp  %g1, 0x804
a00c2714:  38 80 00 02  bgu,a   0xa00c271c
a00c2718:  96 10 28 04  mov  0x804, %o3
a00c271c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c2720:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a00c2724:  a0 13 22 90  or  %o4, 0x290, %l0
a00c2728:  d2 13 63 f8  lduh  [ %o5 + 0x3f8 ], %o1
a00c272c:  1f 00 00 18  sethi  %hi(0x6000), %o7
a00c2730:  80 8b c0 09  btst  %o7, %o1
a00c2734:  d4 34 21 ac  sth  %o2, [ %l0 + 0x1ac ]
a00c2738:  02 80 00 43  be  0xa00c2844
a00c273c:  d6 34 21 ae  sth  %o3, [ %l0 + 0x1ae ]
a00c2740:  7f ff d8 63  call  0xa00b88cc
a00c2744:  01 00 00 00  nop
a00c2748:  80 a6 20 02  cmp  %i0, 2
a00c274c:  02 80 00 24  be  0xa00c27dc
a00c2750:  80 a6 20 03  cmp  %i0, 3
a00c2754:  02 80 00 7a  be  0xa00c293c
a00c2758:  96 10 20 30  mov  0x30, %o3
a00c275c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c2760:  94 12 60 78  or  %o1, 0x78, %o2	! 0xa802d078
a00c2764:  9e 10 20 35  mov  0x35, %o7
a00c2768:  a0 10 20 36  mov  0x36, %l0
a00c276c:  90 10 20 2b  mov  0x2b, %o0
a00c2770:  82 10 20 0d  mov  0xd, %g1
a00c2774:  de 2a 60 78  stb  %o7, [ %o1 + 0x78 ]
a00c2778:  e0 2a a0 01  stb  %l0, [ %o2 + 1 ]
a00c277c:  d6 2a a0 03  stb  %o3, [ %o2 + 3 ]
a00c2780:  d0 2a a0 04  stb  %o0, [ %o2 + 4 ]
a00c2784:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00c2788:  80 a6 20 02  cmp  %i0, 2
a00c278c:  02 80 00 21  be  0xa00c2810
a00c2790:  d6 2a a0 02  stb  %o3, [ %o2 + 2 ]
a00c2794:  80 a6 20 03  cmp  %i0, 3
a00c2798:  02 80 00 76  be  0xa00c2970
a00c279c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c27a0:  90 14 20 d0  or  %l0, 0xd0, %o0	! 0xa802d0d0
a00c27a4:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00c27a8:  c0 2a 60 9c  clrb  [ %o1 + 0x9c ]	! 0xa802b09c
a00c27ac:  c0 2c 20 d0  clrb  [ %l0 + 0xd0 ]
a00c27b0:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c27b4:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c27b8:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c27bc:  80 a6 20 02  cmp  %i0, 2
a00c27c0:  02 80 00 1d  be  0xa00c2834
a00c27c4:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c27c8:  80 a6 20 03  cmp  %i0, 3
a00c27cc:  12 80 00 7f  bne  0xa00c29c8
a00c27d0:  90 10 00 18  mov  %i0, %o0
a00c27d4:  10 80 00 71  b  0xa00c2998
a00c27d8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c27dc:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c27e0:  b0 12 e1 28  or  %o3, 0x128, %i0	! 0xa802d128
a00c27e4:  9e 10 20 30  mov  0x30, %o7
a00c27e8:  82 10 20 35  mov  0x35, %g1
a00c27ec:  94 10 20 0d  mov  0xd, %o2
a00c27f0:  98 10 20 36  mov  0x36, %o4
a00c27f4:  9a 10 20 2b  mov  0x2b, %o5
a00c27f8:  c2 2a e1 28  stb  %g1, [ %o3 + 0x128 ]
a00c27fc:  d4 2e 20 05  stb  %o2, [ %i0 + 5 ]
a00c2800:  d8 2e 20 01  stb  %o4, [ %i0 + 1 ]
a00c2804:  de 2e 20 03  stb  %o7, [ %i0 + 3 ]
a00c2808:  da 2e 20 04  stb  %o5, [ %i0 + 4 ]
a00c280c:  de 2e 20 02  stb  %o7, [ %i0 + 2 ]
a00c2810:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c2814:  94 16 20 40  or  %i0, 0x40, %o2	! 0xa802d040
a00c2818:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00c281c:  c0 2b 60 9a  clrb  [ %o5 + 0x9a ]	! 0xa802b09a
a00c2820:  c0 2e 20 40  clrb  [ %i0 + 0x40 ]
a00c2824:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c2828:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c282c:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c2830:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c2834:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c2838:  94 13 e1 28  or  %o7, 0x128, %o2	! 0xa802d128
a00c283c:  10 80 00 63  b  0xa00c29c8
a00c2840:  90 10 20 02  mov  2, %o0
a00c2844:  7f ff 39 e5  call  0xa0090fd8
a00c2848:  01 00 00 00  nop
a00c284c:  7f ff 39 d8  call  0xa0090fac
a00c2850:  01 00 00 00  nop
a00c2854:  d4 0c 21 90  ldub  [ %l0 + 0x190 ], %o2
a00c2858:  80 a2 a0 00  cmp  %o2, 0
a00c285c:  12 bf ff b9  bne  0xa00c2740
a00c2860:  17 00 00 04  sethi  %hi(0x1000), %o3
a00c2864:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a00c2868:  80 88 40 0b  btst  %g1, %o3
a00c286c:  12 bf ff b5  bne  0xa00c2740
a00c2870:  01 00 00 00  nop
a00c2874:  d0 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o0
a00c2878:  80 a2 20 00  cmp  %o0, 0
a00c287c:  12 bf ff b1  bne  0xa00c2740
a00c2880:  01 00 00 00  nop
a00c2884:  d2 04 20 ac  ld  [ %l0 + 0xac ], %o1
a00c2888:  21 00 10 00  sethi  %hi(0x400000), %l0
a00c288c:  80 8a 40 10  btst  %o1, %l0
a00c2890:  12 bf ff ac  bne  0xa00c2740
a00c2894:  01 00 00 00  nop
a00c2898:  7f ff 39 d0  call  0xa0090fd8
a00c289c:  01 00 00 00  nop
a00c28a0:  30 bf ff a8  b,a   0xa00c2740
a00c28a4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c28a8:  10 bf ff 8d  b  0xa00c26dc
a00c28ac:  c2 0b 20 4d  ldub  [ %o4 + 0x4d ], %g1	! 0xa802d04d
a00c28b0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c28b4:  10 bf ff 7f  b  0xa00c26b0
a00c28b8:  da 08 60 4c  ldub  [ %g1 + 0x4c ], %o5	! 0xa802d04c
a00c28bc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c28c0:  10 bf ff 73  b  0xa00c268c
a00c28c4:  c2 0a 60 4b  ldub  [ %o1 + 0x4b ], %g1	! 0xa802d04b
a00c28c8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c28cc:  10 bf ff 68  b  0xa00c266c
a00c28d0:  c2 0b e0 4a  ldub  [ %o7 + 0x4a ], %g1	! 0xa802d04a
a00c28d4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c28d8:  10 bf ff 59  b  0xa00c263c
a00c28dc:  da 08 60 49  ldub  [ %g1 + 0x49 ], %o5	! 0xa802d049
a00c28e0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c28e4:  10 bf ff 4b  b  0xa00c2610
a00c28e8:  da 0a 20 48  ldub  [ %o0 + 0x48 ], %o5	! 0xa802d048
a00c28ec:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c28f0:  10 bf ff 3f  b  0xa00c25ec
a00c28f4:  c2 0a e0 47  ldub  [ %o3 + 0x47 ], %g1	! 0xa802d047
a00c28f8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c28fc:  10 bf ff 34  b  0xa00c25cc
a00c2900:  c2 08 60 46  ldub  [ %g1 + 0x46 ], %g1	! 0xa802d046
a00c2904:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c2908:  10 bf ff 31  b  0xa00c25cc
a00c290c:  c2 0a 20 9e  ldub  [ %o0 + 0x9e ], %g1	! 0xa802d09e
a00c2910:  10 bf ff 57  b  0xa00c266c
a00c2914:  c2 0c 20 a2  ldub  [ %l0 + 0xa2 ], %g1
a00c2918:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c291c:  10 bf ff 48  b  0xa00c263c
a00c2920:  da 0a 20 a1  ldub  [ %o0 + 0xa1 ], %o5	! 0xa802d0a1
a00c2924:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c2928:  10 bf ff 3a  b  0xa00c2610
a00c292c:  da 0a 60 a0  ldub  [ %o1 + 0xa0 ], %o5	! 0xa802d0a0
a00c2930:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c2934:  10 bf ff 2e  b  0xa00c25ec
a00c2938:  c2 0b 20 9f  ldub  [ %o4 + 0x9f ], %g1	! 0xa802d09f
a00c293c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c2940:  90 13 61 08  or  %o5, 0x108, %o0	! 0xa802d108
a00c2944:  a0 10 20 30  mov  0x30, %l0
a00c2948:  98 10 20 35  mov  0x35, %o4
a00c294c:  9e 10 20 0d  mov  0xd, %o7
a00c2950:  b0 10 20 36  mov  0x36, %i0
a00c2954:  92 10 20 2b  mov  0x2b, %o1
a00c2958:  d8 2b 61 08  stb  %o4, [ %o5 + 0x108 ]
a00c295c:  de 2a 20 05  stb  %o7, [ %o0 + 5 ]
a00c2960:  f0 2a 20 01  stb  %i0, [ %o0 + 1 ]
a00c2964:  e0 2a 20 03  stb  %l0, [ %o0 + 3 ]
a00c2968:  d2 2a 20 04  stb  %o1, [ %o0 + 4 ]
a00c296c:  e0 2a 20 02  stb  %l0, [ %o0 + 2 ]
a00c2970:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c2974:  96 13 20 98  or  %o4, 0x98, %o3	! 0xa802d098
a00c2978:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c297c:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c2980:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]
a00c2984:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00c2988:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00c298c:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00c2990:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00c2994:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c2998:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c299c:  10 80 00 0b  b  0xa00c29c8
a00c29a0:  90 10 20 03  mov  3, %o0
a00c29a4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c29a8:  10 bf ff 4d  b  0xa00c26dc
a00c29ac:  c2 08 60 a5  ldub  [ %g1 + 0xa5 ], %g1	! 0xa802d0a5
a00c29b0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c29b4:  10 bf ff 3f  b  0xa00c26b0
a00c29b8:  da 0a 20 a4  ldub  [ %o0 + 0xa4 ], %o5	! 0xa802d0a4
a00c29bc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c29c0:  10 bf ff 33  b  0xa00c268c
a00c29c4:  c2 0b 20 a3  ldub  [ %o4 + 0xa3 ], %g1	! 0xa802d0a3
a00c29c8:  40 02 17 88  call  0xa01487e8
a00c29cc:  92 10 20 06  mov  6, %o1
a00c29d0:  81 c7 e0 08  ret
a00c29d4:  91 e8 20 00  restore  %g0, 0, %o0
