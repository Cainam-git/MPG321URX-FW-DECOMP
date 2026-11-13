# leon2m FUN_a00b27fc 0xa00b27fc-0xa00b2a1c (544 bytes)
a00b27fc:  9d e3 bf 98  save  %sp, -104, %sp
a00b2800:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a00b2804:  96 14 23 f4  or  %l0, 0x3f4, %o3	! 0xa802cff4
a00b2808:  c2 12 e0 12  lduh  [ %o3 + 0x12 ], %g1
a00b280c:  80 a0 60 05  cmp  %g1, 5
a00b2810:  02 80 00 39  be  0xa00b28f4
a00b2814:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00b2818:  98 14 23 f4  or  %l0, 0x3f4, %o4
a00b281c:  d6 13 20 10  lduh  [ %o4 + 0x10 ], %o3
a00b2820:  80 a2 e0 04  cmp  %o3, 4
a00b2824:  02 80 00 40  be  0xa00b2924
a00b2828:  a2 12 a2 90  or  %o2, 0x290, %l1
a00b282c:  9a 12 a2 90  or  %o2, 0x290, %o5
a00b2830:  d8 0b 61 e4  ldub  [ %o5 + 0x1e4 ], %o4
a00b2834:  80 a3 20 01  cmp  %o4, 1
a00b2838:  02 80 00 77  be  0xa00b2a14
a00b283c:  01 00 00 00  nop
a00b2840:  d0 0b 61 e5  ldub  [ %o5 + 0x1e5 ], %o0
a00b2844:  80 a2 20 01  cmp  %o0, 1
a00b2848:  02 80 00 73  be  0xa00b2a14
a00b284c:  9a 14 23 f4  or  %l0, 0x3f4, %o5
a00b2850:  d2 0b 60 3f  ldub  [ %o5 + 0x3f ], %o1
a00b2854:  80 a2 60 00  cmp  %o1, 0
a00b2858:  22 80 00 3d  be,a   0xa00b294c
a00b285c:  d0 13 60 18  lduh  [ %o5 + 0x18 ], %o0
a00b2860:  de 13 60 18  lduh  [ %o5 + 0x18 ], %o7
a00b2864:  23 3f ff e0  sethi  %hi(0xffff8000), %l1
a00b2868:  96 0b c0 11  and  %o7, %l1, %o3
a00b286c:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00b2870:  80 a3 60 00  cmp  %o5, 0
a00b2874:  12 80 00 58  bne  0xa00b29d4
a00b2878:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a00b287c:  d8 0c 60 55  ldub  [ %l1 + 0x55 ], %o4	! 0xa8025c55
a00b2880:  13 15 55 55  sethi  %hi(0x55555400), %o1
a00b2884:  96 03 20 01  add  %o4, 1, %o3
a00b2888:  90 12 61 56  or  %o1, 0x156, %o0
a00b288c:  80 5a c0 08  smul  %o3, %o0, %g0
a00b2890:  9b 40 00 00  rd  %y, %o5
a00b2894:  82 03 40 0d  add  %o5, %o5, %g1
a00b2898:  9e 00 40 0d  add  %g1, %o5, %o7
a00b289c:  92 22 c0 0f  sub  %o3, %o7, %o1
a00b28a0:  d2 2c 60 55  stb  %o1, [ %l1 + 0x55 ]
a00b28a4:  96 12 a2 90  or  %o2, 0x290, %o3
a00b28a8:  d4 0a e1 e2  ldub  [ %o3 + 0x1e2 ], %o2
a00b28ac:  80 a2 a0 02  cmp  %o2, 2
a00b28b0:  08 80 00 06  bleu  0xa00b28c8
a00b28b4:  90 10 20 03  mov  3, %o0
a00b28b8:  c2 0c 60 55  ldub  [ %l1 + 0x55 ], %g1
a00b28bc:  80 a0 60 01  cmp  %g1, 1
a00b28c0:  02 80 00 51  be  0xa00b2a04
a00b28c4:  9e 00 60 01  add  %g1, 1, %o7
a00b28c8:  d2 0c 60 55  ldub  [ %l1 + 0x55 ], %o1
a00b28cc:  7f ff f7 91  call  0xa00b0710
a00b28d0:  01 00 00 00  nop
a00b28d4:  da 0c 60 55  ldub  [ %l1 + 0x55 ], %o5
a00b28d8:  96 03 7f fe  add  %o5, -2, %o3
a00b28dc:  a2 0a e0 ff  and  %o3, 0xff, %l1
a00b28e0:  80 a4 60 01  cmp  %l1, 1
a00b28e4:  08 80 00 4c  bleu  0xa00b2a14
a00b28e8:  9e 14 23 f4  or  %l0, 0x3f4, %o7
a00b28ec:  10 80 00 33  b  0xa00b29b8
a00b28f0:  d8 13 e0 0e  lduh  [ %o7 + 0xe ], %o4
a00b28f4:  90 12 a2 90  or  %o2, 0x290, %o0
a00b28f8:  d8 02 21 dc  ld  [ %o0 + 0x1dc ], %o4
a00b28fc:  1b 10 00 00  sethi  %hi(0x40000000), %o5
a00b2900:  80 8b 00 0d  btst  %o4, %o5
a00b2904:  02 bf ff c6  be  0xa00b281c
a00b2908:  98 14 23 f4  or  %l0, 0x3f4, %o4
a00b290c:  d2 0a e0 3f  ldub  [ %o3 + 0x3f ], %o1
a00b2910:  80 a2 60 00  cmp  %o1, 0
a00b2914:  02 80 00 40  be  0xa00b2a14
a00b2918:  01 00 00 00  nop
a00b291c:  10 bf ff c1  b  0xa00b2820
a00b2920:  d6 13 20 10  lduh  [ %o4 + 0x10 ], %o3
a00b2924:  de 04 61 dc  ld  [ %l1 + 0x1dc ], %o7
a00b2928:  80 a3 e0 00  cmp  %o7, 0
a00b292c:  16 bf ff c1  bge  0xa00b2830
a00b2930:  9a 12 a2 90  or  %o2, 0x290, %o5
a00b2934:  c2 0b 20 3f  ldub  [ %o4 + 0x3f ], %g1
a00b2938:  80 a0 60 00  cmp  %g1, 0
a00b293c:  02 80 00 36  be  0xa00b2a14
a00b2940:  01 00 00 00  nop
a00b2944:  10 bf ff bc  b  0xa00b2834
a00b2948:  d8 0b 61 e4  ldub  [ %o5 + 0x1e4 ], %o4
a00b294c:  1b 3f ff e0  sethi  %hi(0xffff8000), %o5
a00b2950:  82 0a 00 0d  and  %o0, %o5, %g1
a00b2954:  a3 28 60 10  sll  %g1, 0x10, %l1
a00b2958:  80 a4 60 00  cmp  %l1, 0
a00b295c:  02 80 00 23  be  0xa00b29e8
a00b2960:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a00b2964:  da 0c 60 55  ldub  [ %l1 + 0x55 ], %o5	! 0xa8025c55
a00b2968:  11 15 55 55  sethi  %hi(0x55555400), %o0
a00b296c:  98 03 60 02  add  %o5, 2, %o4
a00b2970:  82 12 21 56  or  %o0, 0x156, %g1
a00b2974:  80 5b 00 01  smul  %o4, %g1, %g0
a00b2978:  9f 40 00 00  rd  %y, %o7
a00b297c:  96 03 c0 0f  add  %o7, %o7, %o3
a00b2980:  94 02 c0 0f  add  %o3, %o7, %o2
a00b2984:  92 23 00 0a  sub  %o4, %o2, %o1
a00b2988:  d2 2c 60 55  stb  %o1, [ %l1 + 0x55 ]
a00b298c:  92 0a 60 ff  and  %o1, 0xff, %o1
a00b2990:  90 10 20 02  mov  2, %o0
a00b2994:  7f ff f7 5f  call  0xa00b0710
a00b2998:  01 00 00 00  nop
a00b299c:  da 0c 60 55  ldub  [ %l1 + 0x55 ], %o5
a00b29a0:  96 03 7f fe  add  %o5, -2, %o3
a00b29a4:  a2 0a e0 ff  and  %o3, 0xff, %l1
a00b29a8:  80 a4 60 01  cmp  %l1, 1
a00b29ac:  08 80 00 1a  bleu  0xa00b2a14
a00b29b0:  9e 14 23 f4  or  %l0, 0x3f4, %o7
a00b29b4:  d8 13 e0 0e  lduh  [ %o7 + 0xe ], %o4
a00b29b8:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00b29bc:  13 3f ff e0  sethi  %hi(0xffff8000), %o1
a00b29c0:  82 2b 00 09  andn  %o4, %o1, %g1
a00b29c4:  91 2b 60 0f  sll  %o5, 0xf, %o0
a00b29c8:  a0 10 40 08  or  %g1, %o0, %l0
a00b29cc:  10 80 00 12  b  0xa00b2a14
a00b29d0:  e0 33 e0 0e  sth  %l0, [ %o7 + 0xe ]
a00b29d4:  d0 0c 60 55  ldub  [ %l1 + 0x55 ], %o0
a00b29d8:  98 02 20 01  add  %o0, 1, %o4
a00b29dc:  82 0b 20 03  and  %o4, 3, %g1
a00b29e0:  10 bf ff b1  b  0xa00b28a4
a00b29e4:  c2 2c 60 55  stb  %g1, [ %l1 + 0x55 ]
a00b29e8:  d4 0c 60 55  ldub  [ %l1 + 0x55 ], %o2
a00b29ec:  98 10 20 01  mov  1, %o4
a00b29f0:  92 23 00 0a  sub  %o4, %o2, %o1
a00b29f4:  d2 2c 60 55  stb  %o1, [ %l1 + 0x55 ]
a00b29f8:  92 0a 60 ff  and  %o1, 0xff, %o1
a00b29fc:  10 bf ff e6  b  0xa00b2994
a00b2a00:  90 10 20 01  mov  1, %o0
a00b2a04:  de 2c 60 55  stb  %o7, [ %l1 + 0x55 ]
a00b2a08:  90 10 20 03  mov  3, %o0
a00b2a0c:  10 bf ff b0  b  0xa00b28cc
a00b2a10:  d2 0c 60 55  ldub  [ %l1 + 0x55 ], %o1
a00b2a14:  81 c7 e0 08  ret
a00b2a18:  81 e8 00 00  restore
