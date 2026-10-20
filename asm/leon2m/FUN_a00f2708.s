# leon2m FUN_a00f2708 0xa00f2708-0xa00f295c (596 bytes)
a00f2708:  9d e3 bf 98  save  %sp, -104, %sp
a00f270c:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00f2710:  80 a3 60 08  cmp  %o5, 8
a00f2714:  82 60 20 00  subx  %g0, 0, %g1
a00f2718:  98 10 00 18  mov  %i0, %o4
a00f271c:  b0 0e 00 01  and  %i0, %g1, %i0
a00f2720:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f2724:  80 a6 20 05  cmp  %i0, 5
a00f2728:  18 80 00 63  bgu  0xa00f28b4
a00f272c:  96 10 20 00  clr  %o3
a00f2730:  37 00 06 68  sethi  %hi(0x19a000), %i3
a00f2734:  b8 06 00 18  add  %i0, %i0, %i4
a00f2738:  b4 16 e2 ec  or  %i3, 0x2ec, %i2
a00f273c:  fa 16 80 1c  lduh  [ %i2 + %i4 ], %i5
a00f2740:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00f2744:  b6 07 40 19  add  %i5, %i1, %i3
a00f2748:  b8 06 e0 01  add  %i3, 1, %i4
a00f274c:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00f2750:  b1 2e e0 02  sll  %i3, 2, %i0
a00f2754:  ba 16 00 01  or  %i0, %g1, %i5
a00f2758:  b5 2f 20 02  sll  %i4, 2, %i2
a00f275c:  b6 16 80 01  or  %i2, %g1, %i3
a00f2760:  f8 07 40 00  ld  [ %i5 ], %i4
a00f2764:  f0 06 c0 00  ld  [ %i3 ], %i0
a00f2768:  bb 2e 20 08  sll  %i0, 8, %i5
a00f276c:  b4 0f 20 ff  and  %i4, 0xff, %i2
a00f2770:  82 17 40 1a  or  %i5, %i2, %g1
a00f2774:  83 28 60 10  sll  %g1, 0x10, %g1
a00f2778:  3b 00 06 68  sethi  %hi(0x19a000), %i5
a00f277c:  b5 30 60 10  srl  %g1, 0x10, %i2
a00f2780:  9e 17 62 ec  or  %i5, 0x2ec, %o7
a00f2784:  10 80 00 35  b  0xa00f2858
a00f2788:  37 33 c0 00  sethi  %hi(0xcf000000), %i3
a00f278c:  22 80 00 5b  be,a   0xa00f28f8
a00f2790:  82 00 40 01  add  %g1, %g1, %g1
a00f2794:  b0 00 40 01  add  %g1, %g1, %i0
a00f2798:  c2 13 c0 18  lduh  [ %o7 + %i0 ], %g1
a00f279c:  b8 00 40 19  add  %g1, %i1, %i4
a00f27a0:  bb 2f 20 02  sll  %i4, 2, %i5
a00f27a4:  b0 07 20 01  add  %i4, 1, %i0
a00f27a8:  82 17 40 1b  or  %i5, %i3, %g1
a00f27ac:  b9 2e 20 02  sll  %i0, 2, %i4
a00f27b0:  f0 00 40 00  ld  [ %g1 ], %i0
a00f27b4:  ba 17 00 1b  or  %i4, %i3, %i5
a00f27b8:  c2 07 40 00  ld  [ %i5 ], %g1
a00f27bc:  b8 0e 20 ff  and  %i0, 0xff, %i4
a00f27c0:  83 28 60 08  sll  %g1, 8, %g1
a00f27c4:  bb 2e a0 10  sll  %i2, 0x10, %i5
a00f27c8:  82 10 40 1c  or  %g1, %i4, %g1
a00f27cc:  b5 28 60 10  sll  %g1, 0x10, %i2
a00f27d0:  80 a6 80 1d  cmp  %i2, %i5
a00f27d4:  02 80 00 60  be  0xa00f2954
a00f27d8:  b1 37 60 10  srl  %i5, 0x10, %i0
a00f27dc:  b8 0a e0 ff  and  %o3, 0xff, %i4
a00f27e0:  80 a7 20 04  cmp  %i4, 4
a00f27e4:  18 80 00 5c  bgu  0xa00f2954
a00f27e8:  80 a3 60 07  cmp  %o5, 7
a00f27ec:  08 80 00 03  bleu  0xa00f27f8
a00f27f0:  82 10 00 0c  mov  %o4, %g1
a00f27f4:  82 10 20 00  clr  %g1
a00f27f8:  82 08 60 ff  and  %g1, 0xff, %g1
a00f27fc:  80 a0 60 05  cmp  %g1, 5
a00f2800:  08 80 00 07  bleu  0xa00f281c
a00f2804:  b8 00 40 01  add  %g1, %g1, %i4
a00f2808:  80 a6 60 a0  cmp  %i1, 0xa0
a00f280c:  02 80 00 34  be  0xa00f28dc
a00f2810:  80 a6 60 be  cmp  %i1, 0xbe
a00f2814:  02 80 00 3c  be  0xa00f2904
a00f2818:  ba 00 40 01  add  %g1, %g1, %i5
a00f281c:  f0 13 c0 1c  lduh  [ %o7 + %i4 ], %i0
a00f2820:  ba 06 00 19  add  %i0, %i1, %i5
a00f2824:  b4 07 60 01  add  %i5, 1, %i2
a00f2828:  83 2f 60 02  sll  %i5, 2, %g1
a00f282c:  b8 10 40 1b  or  %g1, %i3, %i4
a00f2830:  b1 2e a0 02  sll  %i2, 2, %i0
a00f2834:  f4 07 00 00  ld  [ %i4 ], %i2
a00f2838:  ba 16 00 1b  or  %i0, %i3, %i5
a00f283c:  c2 07 40 00  ld  [ %i5 ], %g1
a00f2840:  b1 28 60 08  sll  %g1, 8, %i0
a00f2844:  b8 0e a0 ff  and  %i2, 0xff, %i4
a00f2848:  82 16 00 1c  or  %i0, %i4, %g1
a00f284c:  83 28 60 10  sll  %g1, 0x10, %g1
a00f2850:  b5 30 60 10  srl  %g1, 0x10, %i2
a00f2854:  96 02 e0 01  inc  %o3
a00f2858:  80 a3 60 07  cmp  %o5, 7
a00f285c:  08 80 00 03  bleu  0xa00f2868
a00f2860:  82 10 00 0c  mov  %o4, %g1
a00f2864:  82 10 20 00  clr  %g1
a00f2868:  82 08 60 ff  and  %g1, 0xff, %g1
a00f286c:  80 a0 60 05  cmp  %g1, 5
a00f2870:  08 bf ff ca  bleu  0xa00f2798
a00f2874:  b0 00 40 01  add  %g1, %g1, %i0
a00f2878:  80 a6 60 a0  cmp  %i1, 0xa0
a00f287c:  12 bf ff c4  bne  0xa00f278c
a00f2880:  80 a6 60 be  cmp  %i1, 0xbe
a00f2884:  b0 00 40 01  add  %g1, %g1, %i0
a00f2888:  fa 13 c0 18  lduh  [ %o7 + %i0 ], %i5
a00f288c:  ba 07 60 60  add  %i5, 0x60, %i5
a00f2890:  b1 2f 60 02  sll  %i5, 2, %i0
a00f2894:  ba 16 00 1b  or  %i0, %i3, %i5
a00f2898:  c2 07 40 00  ld  [ %i5 ], %g1
a00f289c:  bb 2e a0 10  sll  %i2, 0x10, %i5
a00f28a0:  b5 28 60 10  sll  %g1, 0x10, %i2
a00f28a4:  80 a6 80 1d  cmp  %i2, %i5
a00f28a8:  12 bf ff cd  bne  0xa00f27dc
a00f28ac:  b1 37 60 10  srl  %i5, 0x10, %i0
a00f28b0:  30 80 00 29  b,a   0xa00f2954
a00f28b4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00f28b8:  80 a6 60 a0  cmp  %i1, 0xa0
a00f28bc:  02 80 00 15  be  0xa00f2910
a00f28c0:  80 a6 60 be  cmp  %i1, 0xbe
a00f28c4:  02 80 00 1e  be  0xa00f293c
a00f28c8:  b8 06 00 18  add  %i0, %i0, %i4
a00f28cc:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f28d0:  b0 10 62 ec  or  %g1, 0x2ec, %i0	! 0x19a2ec
a00f28d4:  10 bf ff 9c  b  0xa00f2744
a00f28d8:  fa 16 00 1c  lduh  [ %i0 + %i4 ], %i5
a00f28dc:  f4 13 c0 1c  lduh  [ %o7 + %i4 ], %i2
a00f28e0:  ba 06 a0 60  add  %i2, 0x60, %i5
a00f28e4:  83 2f 60 02  sll  %i5, 2, %g1
a00f28e8:  b4 10 40 1b  or  %g1, %i3, %i2
a00f28ec:  c2 06 80 00  ld  [ %i2 ], %g1
a00f28f0:  10 bf ff d8  b  0xa00f2850
a00f28f4:  83 28 60 10  sll  %g1, 0x10, %g1
a00f28f8:  f8 13 c0 01  lduh  [ %o7 + %g1 ], %i4
a00f28fc:  10 bf ff e5  b  0xa00f2890
a00f2900:  ba 07 20 5d  add  %i4, 0x5d, %i5
a00f2904:  f0 13 c0 1d  lduh  [ %o7 + %i5 ], %i0
a00f2908:  10 bf ff f7  b  0xa00f28e4
a00f290c:  ba 06 20 5d  add  %i0, 0x5d, %i5
a00f2910:  39 00 06 68  sethi  %hi(0x19a000), %i4
a00f2914:  82 06 00 18  add  %i0, %i0, %g1
a00f2918:  ba 17 22 ec  or  %i4, 0x2ec, %i5
a00f291c:  f0 17 40 01  lduh  [ %i5 + %g1 ], %i0
a00f2920:  82 06 20 60  add  %i0, 0x60, %g1
a00f2924:  b5 28 60 02  sll  %g1, 2, %i2
a00f2928:  37 33 c0 00  sethi  %hi(0xcf000000), %i3
a00f292c:  b8 16 80 1b  or  %i2, %i3, %i4
a00f2930:  fa 07 00 00  ld  [ %i4 ], %i5
a00f2934:  10 bf ff 90  b  0xa00f2774
a00f2938:  82 10 00 1d  mov  %i5, %g1
a00f293c:  b6 06 00 18  add  %i0, %i0, %i3
a00f2940:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f2944:  b0 10 62 ec  or  %g1, 0x2ec, %i0	! 0x19a2ec
a00f2948:  f4 16 00 1b  lduh  [ %i0 + %i3 ], %i2
a00f294c:  10 bf ff f6  b  0xa00f2924
a00f2950:  82 06 a0 5d  add  %i2, 0x5d, %g1
a00f2954:  81 c7 e0 08  ret
a00f2958:  81 e8 00 00  restore
