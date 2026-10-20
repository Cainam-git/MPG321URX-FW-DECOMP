# leon2s FUN_a00c2758 0xa00c2758-0xa00c2de4 (1676 bytes)
a00c2758:  9d e3 bf 98  save  %sp, -104, %sp
a00c275c:  ac 0e 20 ff  and  %i0, 0xff, %l6
a00c2760:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c2764:  9b 2d a0 04  sll  %l6, 4, %o5
a00c2768:  82 10 61 c8  or  %g1, 0x1c8, %g1
a00c276c:  a8 03 40 01  add  %o5, %g1, %l4
a00c2770:  80 a5 a0 01  cmp  %l6, 1
a00c2774:  18 80 00 08  bgu  0xa00c2794
a00c2778:  ae 10 20 00  clr  %l7
a00c277c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c2780:  f0 28 61 c6  stb  %i0, [ %g1 + 0x1c6 ]	! 0xa807d5c6
a00c2784:  a6 0e 20 ff  and  %i0, 0xff, %l3
a00c2788:  a0 10 20 20  mov  0x20, %l0
a00c278c:  10 80 00 10  b  0xa00c27cc
a00c2790:  aa 10 20 00  clr  %l5
a00c2794:  80 a5 a0 03  cmp  %l6, 3
a00c2798:  18 80 00 08  bgu  0xa00c27b8
a00c279c:  90 0e 20 ff  and  %i0, 0xff, %o0
a00c27a0:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c27a4:  f0 28 62 29  stb  %i0, [ %g1 + 0x229 ]	! 0xa807d629
a00c27a8:  a6 02 3f fe  add  %o0, -2, %l3
a00c27ac:  a0 10 20 21  mov  0x21, %l0
a00c27b0:  10 80 00 07  b  0xa00c27cc
a00c27b4:  aa 10 20 01  mov  1, %l5
a00c27b8:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c27bc:  f0 28 62 2b  stb  %i0, [ %g1 + 0x22b ]	! 0xa807d62b
a00c27c0:  a6 02 3f fc  add  %o0, -4, %l3
a00c27c4:  a0 10 20 00  clr  %l0
a00c27c8:  aa 10 20 02  mov  2, %l5
a00c27cc:  c2 0d 20 0c  ldub  [ %l4 + 0xc ], %g1
a00c27d0:  80 a0 60 01  cmp  %g1, 1
a00c27d4:  22 80 00 67  be,a   0xa00c2970
a00c27d8:  c2 05 00 00  ld  [ %l4 ], %g1
a00c27dc:  14 80 00 07  bg  0xa00c27f8
a00c27e0:  80 a0 60 02  cmp  %g1, 2
a00c27e4:  80 a0 60 00  cmp  %g1, 0
a00c27e8:  02 80 00 07  be  0xa00c2804
a00c27ec:  82 0c 20 ff  and  %l0, 0xff, %g1
a00c27f0:  10 80 01 7b  b  0xa00c2ddc
a00c27f4:  b0 0d e0 01  and  %l7, 1, %i0
a00c27f8:  02 80 00 76  be  0xa00c29d0
a00c27fc:  b0 0d e0 01  and  %l7, 1, %i0
a00c2800:  30 80 01 77  b,a   0xa00c2ddc
a00c2804:  80 a0 60 20  cmp  %g1, 0x20
a00c2808:  12 80 00 19  bne  0xa00c286c
a00c280c:  80 a0 60 21  cmp  %g1, 0x21
a00c2810:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00c2814:  90 10 00 11  mov  %l1, %o0
a00c2818:  92 10 23 10  mov  0x310, %o1
a00c281c:  40 3b cf 6a  call  0xa0fb65c4
a00c2820:  94 10 20 24  mov  0x24, %o2
a00c2824:  a4 10 20 00  clr  %l2
a00c2828:  83 2c a0 10  sll  %l2, 0x10, %g1
a00c282c:  83 30 60 10  srl  %g1, 0x10, %g1
a00c2830:  a0 10 20 7f  mov  0x7f, %l0
a00c2834:  a0 24 00 01  sub  %l0, %g1, %l0
a00c2838:  90 10 00 11  mov  %l1, %o0
a00c283c:  40 3b cf 50  call  0xa0fb657c
a00c2840:  92 10 23 12  mov  0x312, %o1
a00c2844:  98 04 a0 01  add  %l2, 1, %o4
a00c2848:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00c284c:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c2850:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c2854:  82 10 61 38  or  %g1, 0x138, %g1
a00c2858:  d0 28 40 10  stb  %o0, [ %g1 + %l0 ]
a00c285c:  80 a3 60 7f  cmp  %o5, 0x7f
a00c2860:  08 bf ff f2  bleu  0xa00c2828
a00c2864:  a4 10 00 0c  mov  %o4, %l2
a00c2868:  30 80 00 3d  b,a   0xa00c295c
a00c286c:  12 80 00 20  bne  0xa00c28ec
a00c2870:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00c2874:  90 10 00 11  mov  %l1, %o0
a00c2878:  92 10 20 a6  mov  0xa6, %o1
a00c287c:  40 3b d0 60  call  0xa0fb69fc
a00c2880:  94 10 20 03  mov  3, %o2
a00c2884:  90 10 00 11  mov  %l1, %o0
a00c2888:  92 10 20 a4  mov  0xa4, %o1
a00c288c:  40 3b d0 5c  call  0xa0fb69fc
a00c2890:  94 10 20 20  mov  0x20, %o2
a00c2894:  a4 10 20 00  clr  %l2
a00c2898:  94 0c a0 ff  and  %l2, 0xff, %o2
a00c289c:  90 10 00 11  mov  %l1, %o0
a00c28a0:  40 3b d0 57  call  0xa0fb69fc
a00c28a4:  92 10 20 a5  mov  0xa5, %o1
a00c28a8:  83 2c a0 10  sll  %l2, 0x10, %g1
a00c28ac:  83 30 60 10  srl  %g1, 0x10, %g1
a00c28b0:  a0 10 20 7f  mov  0x7f, %l0
a00c28b4:  a0 24 00 01  sub  %l0, %g1, %l0
a00c28b8:  90 10 00 11  mov  %l1, %o0
a00c28bc:  40 3b d0 3e  call  0xa0fb69b4
a00c28c0:  92 10 20 a7  mov  0xa7, %o1
a00c28c4:  98 04 a0 01  add  %l2, 1, %o4
a00c28c8:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00c28cc:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c28d0:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c28d4:  82 10 61 38  or  %g1, 0x138, %g1
a00c28d8:  d0 28 40 10  stb  %o0, [ %g1 + %l0 ]
a00c28dc:  80 a3 60 7f  cmp  %o5, 0x7f
a00c28e0:  08 bf ff ee  bleu  0xa00c2898
a00c28e4:  a4 10 00 0c  mov  %o4, %l2
a00c28e8:  30 80 00 1d  b,a   0xa00c295c
a00c28ec:  90 10 00 11  mov  %l1, %o0
a00c28f0:  92 10 24 03  mov  0x403, %o1
a00c28f4:  40 3b d0 c3  call  0xa0fb6c00
a00c28f8:  94 10 20 00  clr  %o2
a00c28fc:  90 10 00 11  mov  %l1, %o0
a00c2900:  92 10 24 02  mov  0x402, %o1
a00c2904:  94 10 20 80  mov  0x80, %o2
a00c2908:  40 3b d0 e4  call  0xa0fb6c98
a00c290c:  96 10 20 01  mov  1, %o3
a00c2910:  90 10 00 11  mov  %l1, %o0
a00c2914:  92 10 24 00  mov  0x400, %o1
a00c2918:  40 3b d0 ba  call  0xa0fb6c00
a00c291c:  94 10 20 04  mov  4, %o2
a00c2920:  a4 10 20 00  clr  %l2
a00c2924:  90 10 00 11  mov  %l1, %o0
a00c2928:  40 3b d0 a4  call  0xa0fb6bb8
a00c292c:  92 10 24 01  mov  0x401, %o1
a00c2930:  98 04 a0 01  add  %l2, 1, %o4
a00c2934:  a1 2c a0 10  sll  %l2, 0x10, %l0
a00c2938:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00c293c:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c2940:  a1 34 20 10  srl  %l0, 0x10, %l0
a00c2944:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c2948:  82 10 61 38  or  %g1, 0x138, %g1
a00c294c:  d0 28 40 10  stb  %o0, [ %g1 + %l0 ]
a00c2950:  80 a3 60 7f  cmp  %o5, 0x7f
a00c2954:  08 bf ff f4  bleu  0xa00c2924
a00c2958:  a4 10 00 0c  mov  %o4, %l2
a00c295c:  7f ff fe 51  call  0xa00c22a0
a00c2960:  90 0d 60 03  and  %l5, 3, %o0
a00c2964:  82 10 20 01  mov  1, %g1
a00c2968:  10 80 01 1c  b  0xa00c2dd8
a00c296c:  c2 2d 20 0c  stb  %g1, [ %l4 + 0xc ]
a00c2970:  21 02 00 00  sethi  %hi(0x8000000), %l0
a00c2974:  80 88 40 10  btst  %g1, %l0
a00c2978:  32 80 00 0d  bne,a   0xa00c29ac
a00c297c:  da 05 00 00  ld  [ %l4 ], %o5
a00c2980:  13 2a 01 e3  sethi  %hi(0xa8078c00), %o1
a00c2984:  90 0d 60 03  and  %l5, 3, %o0
a00c2988:  7f ff fe c0  call  0xa00c2488
a00c298c:  92 12 62 b8  or  %o1, 0x2b8, %o1
a00c2990:  da 05 00 00  ld  [ %l4 ], %o5
a00c2994:  90 0a 20 01  and  %o0, 1, %o0
a00c2998:  82 2b 40 10  andn  %o5, %l0, %g1
a00c299c:  91 2a 20 1b  sll  %o0, 0x1b, %o0
a00c29a0:  82 10 40 08  or  %g1, %o0, %g1
a00c29a4:  c2 25 00 00  st  %g1, [ %l4 ]
a00c29a8:  da 05 00 00  ld  [ %l4 ], %o5
a00c29ac:  80 8b 40 10  btst  %o5, %l0
a00c29b0:  02 80 01 0b  be  0xa00c2ddc
a00c29b4:  b0 0d e0 01  and  %l7, 1, %i0
a00c29b8:  03 02 00 00  sethi  %hi(0x8000000), %g1
a00c29bc:  82 2b 40 01  andn  %o5, %g1, %g1
a00c29c0:  9a 10 20 02  mov  2, %o5
a00c29c4:  da 2d 20 0c  stb  %o5, [ %l4 + 0xc ]
a00c29c8:  10 80 01 05  b  0xa00c2ddc
a00c29cc:  c2 25 00 00  st  %g1, [ %l4 ]
a00c29d0:  7f ff fe e3  call  0xa00c255c
a00c29d4:  90 0d 60 03  and  %l5, 3, %o0
a00c29d8:  82 0c 20 ff  and  %l0, 0xff, %g1
a00c29dc:  80 a0 60 20  cmp  %g1, 0x20
a00c29e0:  12 80 00 1b  bne  0xa00c2a4c
a00c29e4:  80 a0 60 21  cmp  %g1, 0x21
a00c29e8:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00c29ec:  90 10 00 10  mov  %l0, %o0
a00c29f0:  92 10 23 10  mov  0x310, %o1
a00c29f4:  40 3b ce f4  call  0xa0fb65c4
a00c29f8:  94 10 20 34  mov  0x34, %o2
a00c29fc:  a4 10 20 10  mov  0x10, %l2
a00c2a00:  9b 2c a0 10  sll  %l2, 0x10, %o5
a00c2a04:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c2a08:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c2a0c:  82 10 60 b8  or  %g1, 0xb8, %g1
a00c2a10:  d4 08 40 0d  ldub  [ %g1 + %o5 ], %o2
a00c2a14:  90 10 00 10  mov  %l0, %o0
a00c2a18:  40 3b ce eb  call  0xa0fb65c4
a00c2a1c:  92 10 23 12  mov  0x312, %o1
a00c2a20:  9a 04 bf ff  add  %l2, -1, %o5
a00c2a24:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c2a28:  80 a0 60 00  cmp  %g1, 0
a00c2a2c:  12 bf ff f5  bne  0xa00c2a00
a00c2a30:  a4 10 00 0d  mov  %o5, %l2
a00c2a34:  90 10 00 10  mov  %l0, %o0
a00c2a38:  92 10 23 12  mov  0x312, %o1
a00c2a3c:  40 3b ce e2  call  0xa0fb65c4
a00c2a40:  94 10 20 01  mov  1, %o2
a00c2a44:  10 80 00 cf  b  0xa00c2d80
a00c2a48:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c2a4c:  12 80 00 28  bne  0xa00c2aec
a00c2a50:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00c2a54:  90 10 00 11  mov  %l1, %o0
a00c2a58:  92 10 20 a6  mov  0xa6, %o1
a00c2a5c:  40 3b cf e8  call  0xa0fb69fc
a00c2a60:  94 10 20 21  mov  0x21, %o2
a00c2a64:  90 10 00 11  mov  %l1, %o0
a00c2a68:  92 10 20 a4  mov  0xa4, %o1
a00c2a6c:  40 3b cf e4  call  0xa0fb69fc
a00c2a70:  94 10 20 00  clr  %o2
a00c2a74:  a4 10 20 10  mov  0x10, %l2
a00c2a78:  94 10 20 10  mov  0x10, %o2
a00c2a7c:  94 22 80 12  sub  %o2, %l2, %o2
a00c2a80:  94 0a a0 ff  and  %o2, 0xff, %o2
a00c2a84:  90 10 00 11  mov  %l1, %o0
a00c2a88:  40 3b cf dd  call  0xa0fb69fc
a00c2a8c:  92 10 20 a5  mov  0xa5, %o1
a00c2a90:  9b 2c a0 10  sll  %l2, 0x10, %o5
a00c2a94:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c2a98:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c2a9c:  82 10 60 b8  or  %g1, 0xb8, %g1
a00c2aa0:  d4 08 40 0d  ldub  [ %g1 + %o5 ], %o2
a00c2aa4:  90 10 00 11  mov  %l1, %o0
a00c2aa8:  40 3b cf d5  call  0xa0fb69fc
a00c2aac:  92 10 20 a7  mov  0xa7, %o1
a00c2ab0:  9a 04 bf ff  add  %l2, -1, %o5
a00c2ab4:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c2ab8:  80 a0 60 00  cmp  %g1, 0
a00c2abc:  12 bf ff ef  bne  0xa00c2a78
a00c2ac0:  a4 10 00 0d  mov  %o5, %l2
a00c2ac4:  90 10 00 11  mov  %l1, %o0
a00c2ac8:  92 10 20 a5  mov  0xa5, %o1
a00c2acc:  40 3b cf cc  call  0xa0fb69fc
a00c2ad0:  94 10 20 10  mov  0x10, %o2
a00c2ad4:  90 10 00 11  mov  %l1, %o0
a00c2ad8:  92 10 20 a7  mov  0xa7, %o1
a00c2adc:  40 3b cf c8  call  0xa0fb69fc
a00c2ae0:  94 10 20 01  mov  1, %o2
a00c2ae4:  10 80 00 a7  b  0xa00c2d80
a00c2ae8:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c2aec:  90 10 00 11  mov  %l1, %o0
a00c2af0:  92 10 24 00  mov  0x400, %o1
a00c2af4:  40 3b d0 43  call  0xa0fb6c00
a00c2af8:  94 10 20 0f  mov  0xf, %o2
a00c2afc:  90 10 00 11  mov  %l1, %o0
a00c2b00:  92 10 24 02  mov  0x402, %o1
a00c2b04:  94 10 20 80  mov  0x80, %o2
a00c2b08:  40 3b d0 64  call  0xa0fb6c98
a00c2b0c:  96 10 20 01  mov  1, %o3
a00c2b10:  90 10 00 11  mov  %l1, %o0
a00c2b14:  92 10 24 03  mov  0x403, %o1
a00c2b18:  40 3b d0 3a  call  0xa0fb6c00
a00c2b1c:  94 10 20 00  clr  %o2
a00c2b20:  a4 10 20 00  clr  %l2
a00c2b24:  9b 2c a0 10  sll  %l2, 0x10, %o5
a00c2b28:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c2b2c:  82 10 60 b8  or  %g1, 0xb8, %g1	! 0xa8078cb8
a00c2b30:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c2b34:  9a 03 40 01  add  %o5, %g1, %o5
a00c2b38:  d4 0b 60 01  ldub  [ %o5 + 1 ], %o2
a00c2b3c:  90 10 00 11  mov  %l1, %o0
a00c2b40:  40 3b d0 30  call  0xa0fb6c00
a00c2b44:  92 10 24 01  mov  0x401, %o1
a00c2b48:  9a 04 a0 01  add  %l2, 1, %o5
a00c2b4c:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c2b50:  83 30 60 10  srl  %g1, 0x10, %g1
a00c2b54:  80 a0 60 0f  cmp  %g1, 0xf
a00c2b58:  08 bf ff f3  bleu  0xa00c2b24
a00c2b5c:  a4 10 00 0d  mov  %o5, %l2
a00c2b60:  90 10 00 11  mov  %l1, %o0
a00c2b64:  92 10 20 00  clr  %o1
a00c2b68:  94 10 20 20  mov  0x20, %o2
a00c2b6c:  40 3b d0 4b  call  0xa0fb6c98
a00c2b70:  96 10 20 00  clr  %o3
a00c2b74:  90 10 00 11  mov  %l1, %o0
a00c2b78:  92 10 24 05  mov  0x405, %o1
a00c2b7c:  94 10 20 01  mov  1, %o2
a00c2b80:  40 3b d0 46  call  0xa0fb6c98
a00c2b84:  96 10 20 00  clr  %o3
a00c2b88:  90 10 00 11  mov  %l1, %o0
a00c2b8c:  92 10 24 06  mov  0x406, %o1
a00c2b90:  40 3b d0 1c  call  0xa0fb6c00
a00c2b94:  94 10 20 08  mov  8, %o2
a00c2b98:  10 80 00 04  b  0xa00c2ba8
a00c2b9c:  a0 10 20 ff  mov  0xff, %l0
a00c2ba0:  40 3b fa 9b  call  0xa0fc160c
a00c2ba4:  01 00 00 00  nop
a00c2ba8:  92 10 24 06  mov  0x406, %o1	! 0x406
a00c2bac:  40 3b d0 03  call  0xa0fb6bb8
a00c2bb0:  90 10 00 11  mov  %l1, %o0
a00c2bb4:  9a 04 3f ff  add  %l0, -1, %o5
a00c2bb8:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c2bbc:  80 8a 20 08  btst  8, %o0
a00c2bc0:  99 30 60 10  srl  %g1, 0x10, %o4
a00c2bc4:  90 10 20 01  mov  1, %o0
a00c2bc8:  02 80 00 07  be  0xa00c2be4
a00c2bcc:  a0 10 00 0d  mov  %o5, %l0
a00c2bd0:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00c2bd4:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a00c2bd8:  80 a3 00 01  cmp  %o4, %g1
a00c2bdc:  12 bf ff f1  bne  0xa00c2ba0
a00c2be0:  01 00 00 00  nop
a00c2be4:  90 10 00 11  mov  %l1, %o0
a00c2be8:  92 10 24 06  mov  0x406, %o1
a00c2bec:  40 3b d0 05  call  0xa0fb6c00
a00c2bf0:  94 10 20 09  mov  9, %o2
a00c2bf4:  10 80 00 04  b  0xa00c2c04
a00c2bf8:  a0 10 20 ff  mov  0xff, %l0
a00c2bfc:  40 3b fa 84  call  0xa0fc160c
a00c2c00:  01 00 00 00  nop
a00c2c04:  92 10 24 06  mov  0x406, %o1	! 0x406
a00c2c08:  40 3b cf ec  call  0xa0fb6bb8
a00c2c0c:  90 10 00 11  mov  %l1, %o0
a00c2c10:  9a 04 3f ff  add  %l0, -1, %o5
a00c2c14:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c2c18:  80 8a 20 08  btst  8, %o0
a00c2c1c:  99 30 60 10  srl  %g1, 0x10, %o4
a00c2c20:  90 10 20 01  mov  1, %o0
a00c2c24:  02 80 00 07  be  0xa00c2c40
a00c2c28:  a0 10 00 0d  mov  %o5, %l0
a00c2c2c:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00c2c30:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a00c2c34:  80 a3 00 01  cmp  %o4, %g1
a00c2c38:  12 bf ff f1  bne  0xa00c2bfc
a00c2c3c:  01 00 00 00  nop
a00c2c40:  90 10 00 11  mov  %l1, %o0
a00c2c44:  92 10 24 06  mov  0x406, %o1
a00c2c48:  40 3b cf ee  call  0xa0fb6c00
a00c2c4c:  94 10 20 c0  mov  0xc0, %o2
a00c2c50:  10 80 00 04  b  0xa00c2c60
a00c2c54:  a0 10 20 ff  mov  0xff, %l0
a00c2c58:  40 3b fa 6d  call  0xa0fc160c
a00c2c5c:  01 00 00 00  nop
a00c2c60:  92 10 24 06  mov  0x406, %o1	! 0x406
a00c2c64:  40 3b cf d5  call  0xa0fb6bb8
a00c2c68:  90 10 00 11  mov  %l1, %o0
a00c2c6c:  9a 04 3f ff  add  %l0, -1, %o5
a00c2c70:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c2c74:  80 8a 20 80  btst  0x80, %o0
a00c2c78:  99 30 60 10  srl  %g1, 0x10, %o4
a00c2c7c:  90 10 20 01  mov  1, %o0
a00c2c80:  02 80 00 07  be  0xa00c2c9c
a00c2c84:  a0 10 00 0d  mov  %o5, %l0
a00c2c88:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00c2c8c:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a00c2c90:  80 a3 00 01  cmp  %o4, %g1
a00c2c94:  12 bf ff f1  bne  0xa00c2c58
a00c2c98:  01 00 00 00  nop
a00c2c9c:  90 10 00 11  mov  %l1, %o0
a00c2ca0:  92 10 20 30  mov  0x30, %o1
a00c2ca4:  94 10 20 40  mov  0x40, %o2
a00c2ca8:  40 3b cf fc  call  0xa0fb6c98
a00c2cac:  96 10 20 01  mov  1, %o3
a00c2cb0:  10 80 00 04  b  0xa00c2cc0
a00c2cb4:  a0 10 23 e8  mov  0x3e8, %l0
a00c2cb8:  40 3b fa b7  call  0xa0fc1794
a00c2cbc:  01 00 00 00  nop
a00c2cc0:  92 10 24 08  mov  0x408, %o1	! 0x408
a00c2cc4:  40 3b cf bd  call  0xa0fb6bb8
a00c2cc8:  90 10 00 11  mov  %l1, %o0
a00c2ccc:  98 04 3f ff  add  %l0, -1, %o4
a00c2cd0:  83 2b 20 10  sll  %o4, 0x10, %g1
a00c2cd4:  80 8a 20 10  btst  0x10, %o0
a00c2cd8:  9b 30 60 10  srl  %g1, 0x10, %o5
a00c2cdc:  12 80 00 07  bne  0xa00c2cf8
a00c2ce0:  90 10 20 01  mov  1, %o0
a00c2ce4:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00c2ce8:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a00c2cec:  80 a3 40 01  cmp  %o5, %g1
a00c2cf0:  12 bf ff f2  bne  0xa00c2cb8
a00c2cf4:  a0 10 00 0c  mov  %o4, %l0
a00c2cf8:  83 2c 20 10  sll  %l0, 0x10, %g1
a00c2cfc:  80 a0 60 00  cmp  %g1, 0
a00c2d00:  02 80 00 1b  be  0xa00c2d6c
a00c2d04:  90 0c e0 ff  and  %l3, 0xff, %o0
a00c2d08:  90 10 00 11  mov  %l1, %o0
a00c2d0c:  92 10 24 06  mov  0x406, %o1
a00c2d10:  40 3b cf bc  call  0xa0fb6c00
a00c2d14:  94 10 20 0b  mov  0xb, %o2
a00c2d18:  a0 10 20 ff  mov  0xff, %l0
a00c2d1c:  90 10 00 11  mov  %l1, %o0
a00c2d20:  40 3b cf a6  call  0xa0fb6bb8
a00c2d24:  92 10 24 06  mov  0x406, %o1
a00c2d28:  9a 04 3f ff  add  %l0, -1, %o5
a00c2d2c:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c2d30:  99 30 60 10  srl  %g1, 0x10, %o4
a00c2d34:  80 8a 20 08  btst  8, %o0
a00c2d38:  02 80 00 07  be  0xa00c2d54
a00c2d3c:  a0 10 00 0d  mov  %o5, %l0
a00c2d40:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00c2d44:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a00c2d48:  80 a3 00 01  cmp  %o4, %g1
a00c2d4c:  12 bf ff f5  bne  0xa00c2d20
a00c2d50:  90 10 00 11  mov  %l1, %o0
a00c2d54:  90 10 00 11  mov  %l1, %o0
a00c2d58:  92 10 20 30  mov  0x30, %o1
a00c2d5c:  94 10 20 40  mov  0x40, %o2
a00c2d60:  40 3b cf ce  call  0xa0fb6c98
a00c2d64:  96 10 20 01  mov  1, %o3
a00c2d68:  90 0c e0 ff  and  %l3, 0xff, %o0
a00c2d6c:  92 10 24 05  mov  0x405, %o1
a00c2d70:  94 10 20 01  mov  1, %o2
a00c2d74:  40 3b cf c9  call  0xa0fb6c98
a00c2d78:  96 10 20 01  mov  1, %o3
a00c2d7c:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c2d80:  c2 0b 61 c6  ldub  [ %o5 + 0x1c6 ], %g1	! 0xa807d5c6
a00c2d84:  c0 2d 20 0c  clrb  [ %l4 + 0xc ]
a00c2d88:  80 a0 40 16  cmp  %g1, %l6
a00c2d8c:  12 80 00 05  bne  0xa00c2da0
a00c2d90:  ae 10 20 01  mov  1, %l7
a00c2d94:  82 10 3f ff  mov  -1, %g1
a00c2d98:  10 80 00 10  b  0xa00c2dd8
a00c2d9c:  c2 2b 61 c6  stb  %g1, [ %o5 + 0x1c6 ]
a00c2da0:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c2da4:  c2 0b 62 29  ldub  [ %o5 + 0x229 ], %g1	! 0xa807d629
a00c2da8:  80 a0 40 16  cmp  %g1, %l6
a00c2dac:  32 80 00 05  bne,a   0xa00c2dc0
a00c2db0:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c2db4:  82 10 3f ff  mov  -1, %g1
a00c2db8:  10 80 00 08  b  0xa00c2dd8
a00c2dbc:  c2 2b 62 29  stb  %g1, [ %o5 + 0x229 ]
a00c2dc0:  c2 0b 62 2b  ldub  [ %o5 + 0x22b ], %g1
a00c2dc4:  80 a0 40 16  cmp  %g1, %l6
a00c2dc8:  12 80 00 05  bne  0xa00c2ddc
a00c2dcc:  b0 0d e0 01  and  %l7, 1, %i0
a00c2dd0:  82 10 3f ff  mov  -1, %g1
a00c2dd4:  c2 2b 62 2b  stb  %g1, [ %o5 + 0x22b ]
a00c2dd8:  b0 0d e0 01  and  %l7, 1, %i0
a00c2ddc:  81 c7 e0 08  ret
a00c2de0:  81 e8 00 00  restore
