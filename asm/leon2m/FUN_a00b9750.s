# leon2m FUN_a00b9750 0xa00b9750-0xa00b9c68 (1304 bytes)
a00b9750:  9d e3 bf 88  save  %sp, -120, %sp
a00b9754:  40 02 2b 4e  call  0xa014448c
a00b9758:  90 10 20 00  clr  %o0
a00b975c:  ae 06 20 04  add  %i0, 4, %l7
a00b9760:  2d 2a 00 b4  sethi  %hi(0xa802d000), %l6
a00b9764:  83 2d e0 10  sll  %l7, 0x10, %g1
a00b9768:  ba 10 00 08  mov  %o0, %i5
a00b976c:  a5 30 60 10  srl  %g1, 0x10, %l2
a00b9770:  a6 10 20 00  clr  %l3
a00b9774:  a2 10 20 00  clr  %l1
a00b9778:  2b 00 06 46  sethi  %hi(0x191800), %l5
a00b977c:  a8 15 a2 90  or  %l6, 0x290, %l4
a00b9780:  94 04 40 11  add  %l1, %l1, %o2
a00b9784:  90 02 80 11  add  %o2, %l1, %o0
a00b9788:  92 02 00 19  add  %o0, %i1, %o1
a00b978c:  a0 02 60 01  add  %o1, 1, %l0
a00b9790:  83 2c 20 10  sll  %l0, 0x10, %g1
a00b9794:  a1 30 60 10  srl  %g1, 0x10, %l0
a00b9798:  94 10 20 0e  mov  0xe, %o2
a00b979c:  96 10 25 96  mov  0x596, %o3
a00b97a0:  98 10 20 00  clr  %o4
a00b97a4:  90 10 00 12  mov  %l2, %o0
a00b97a8:  40 02 34 b6  call  0xa0146a80
a00b97ac:  92 10 00 10  mov  %l0, %o1
a00b97b0:  9f 2c 60 03  sll  %l1, 3, %o7
a00b97b4:  9a 23 c0 11  sub  %o7, %l1, %o5
a00b97b8:  99 2b 60 02  sll  %o5, 2, %o4
a00b97bc:  94 03 00 11  add  %o4, %l1, %o2
a00b97c0:  d6 0d 20 08  ldub  [ %l4 + 8 ], %o3
a00b97c4:  90 02 80 0b  add  %o2, %o3, %o0
a00b97c8:  93 2a 20 10  sll  %o0, 0x10, %o1
a00b97cc:  93 32 60 10  srl  %o1, 0x10, %o1
a00b97d0:  7f ff a8 1d  call  0xa00a3844
a00b97d4:  90 15 63 30  or  %l5, 0x330, %o0
a00b97d8:  98 10 00 08  mov  %o0, %o4
a00b97dc:  94 10 00 10  mov  %l0, %o2
a00b97e0:  90 10 20 00  clr  %o0
a00b97e4:  92 10 00 12  mov  %l2, %o1
a00b97e8:  96 10 20 0e  mov  0xe, %o3
a00b97ec:  9a 10 20 00  clr  %o5
a00b97f0:  7f ff a6 6d  call  0xa00a31a4
a00b97f4:  a6 04 e0 01  inc  %l3
a00b97f8:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00b97fc:  80 a4 60 06  cmp  %l1, 6
a00b9800:  08 bf ff e1  bleu  0xa00b9784
a00b9804:  94 04 40 11  add  %l1, %l1, %o2
a00b9808:  40 02 2b 7d  call  0xa01445fc
a00b980c:  d0 0d 20 1e  ldub  [ %l4 + 0x1e ], %o0
a00b9810:  92 0a 20 ff  and  %o0, 0xff, %o1
a00b9814:  2b 00 06 5a  sethi  %hi(0x196800), %l5
a00b9818:  7f ff a8 0b  call  0xa00a3844
a00b981c:  90 15 63 24  or  %l5, 0x324, %o0	! 0x196b24
a00b9820:  a8 06 60 02  add  %i1, 2, %l4
a00b9824:  98 10 00 08  mov  %o0, %o4
a00b9828:  a7 2d 20 10  sll  %l4, 0x10, %l3
a00b982c:  92 10 00 12  mov  %l2, %o1
a00b9830:  95 34 e0 10  srl  %l3, 0x10, %o2
a00b9834:  96 10 20 0e  mov  0xe, %o3
a00b9838:  9a 10 20 00  clr  %o5
a00b983c:  7f ff a6 5a  call  0xa00a31a4
a00b9840:  90 10 20 00  clr  %o0
a00b9844:  40 02 3a ce  call  0xa014837c
a00b9848:  90 10 20 00  clr  %o0
a00b984c:  a3 2a 20 10  sll  %o0, 0x10, %l1
a00b9850:  a4 07 bf e8  add  %fp, -24, %l2
a00b9854:  27 00 06 60  sethi  %hi(0x198000), %l3
a00b9858:  95 34 60 10  srl  %l1, 0x10, %o2
a00b985c:  90 10 00 12  mov  %l2, %o0
a00b9860:  92 14 e1 e0  or  %l3, 0x1e0, %o1
a00b9864:  40 02 77 e4  call  0xa01577f4
a00b9868:  96 10 28 70  mov  0x870, %o3
a00b986c:  98 10 20 00  clr  %o4
a00b9870:  82 10 20 00  clr  %g1
a00b9874:  a2 07 bf f8  add  %fp, -8, %l1
a00b9878:  9a 04 40 01  add  %l1, %g1, %o5
a00b987c:  d6 0b 7f f0  ldub  [ %o5 + -16 ], %o3
a00b9880:  80 a2 e0 00  cmp  %o3, 0
a00b9884:  02 80 00 08  be  0xa00b98a4
a00b9888:  94 06 60 05  add  %i1, 5, %o2
a00b988c:  98 03 20 01  inc  %o4
a00b9890:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b9894:  80 a0 60 0f  cmp  %g1, 0xf
a00b9898:  08 bf ff f9  bleu  0xa00b987c
a00b989c:  9a 04 40 01  add  %l1, %g1, %o5
a00b98a0:  94 06 60 05  add  %i1, 5, %o2
a00b98a4:  91 2a a0 10  sll  %o2, 0x10, %o0
a00b98a8:  b0 06 20 03  add  %i0, 3, %i0
a00b98ac:  82 03 3f ff  add  %o4, -1, %g1
a00b98b0:  95 32 20 10  srl  %o0, 0x10, %o2
a00b98b4:  93 2e 20 10  sll  %i0, 0x10, %o1
a00b98b8:  c2 2f bf e8  stb  %g1, [ %fp + -24 ]
a00b98bc:  96 10 20 10  mov  0x10, %o3
a00b98c0:  98 10 00 12  mov  %l2, %o4
a00b98c4:  9a 10 20 00  clr  %o5
a00b98c8:  93 32 60 10  srl  %o1, 0x10, %o1
a00b98cc:  7f ff a6 36  call  0xa00a31a4
a00b98d0:  90 10 20 00  clr  %o0
a00b98d4:  92 10 20 07  mov  7, %o1
a00b98d8:  40 02 2f 62  call  0xa0145660
a00b98dc:  90 10 20 00  clr  %o0
a00b98e0:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00b98e4:  a1 33 e0 10  srl  %o7, 0x10, %l0
a00b98e8:  92 10 20 08  mov  8, %o1
a00b98ec:  40 02 2f 5d  call  0xa0145660
a00b98f0:  90 10 20 00  clr  %o0
a00b98f4:  99 2a 20 10  sll  %o0, 0x10, %o4
a00b98f8:  97 33 20 10  srl  %o4, 0x10, %o3
a00b98fc:  92 14 e1 e0  or  %l3, 0x1e0, %o1
a00b9900:  94 10 00 10  mov  %l0, %o2
a00b9904:  40 02 77 bc  call  0xa01577f4
a00b9908:  90 10 00 12  mov  %l2, %o0
a00b990c:  98 10 20 00  clr  %o4
a00b9910:  82 10 20 00  clr  %g1
a00b9914:  a8 04 40 01  add  %l1, %g1, %l4
a00b9918:  e6 0d 3f f0  ldub  [ %l4 + -16 ], %l3
a00b991c:  80 a4 e0 00  cmp  %l3, 0
a00b9920:  02 80 00 08  be  0xa00b9940
a00b9924:  9e 06 60 08  add  %i1, 8, %o7
a00b9928:  98 03 20 01  inc  %o4
a00b992c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b9930:  80 a0 60 0f  cmp  %g1, 0xf
a00b9934:  08 bf ff f9  bleu  0xa00b9918
a00b9938:  a8 04 40 01  add  %l1, %g1, %l4
a00b993c:  9e 06 60 08  add  %i1, 8, %o7
a00b9940:  a0 03 3f ff  add  %o4, -1, %l0
a00b9944:  9b 2b e0 10  sll  %o7, 0x10, %o5
a00b9948:  99 2e 20 10  sll  %i0, 0x10, %o4
a00b994c:  93 33 20 10  srl  %o4, 0x10, %o1
a00b9950:  95 33 60 10  srl  %o5, 0x10, %o2
a00b9954:  98 10 00 12  mov  %l2, %o4
a00b9958:  96 10 20 10  mov  0x10, %o3
a00b995c:  9a 10 20 00  clr  %o5
a00b9960:  90 10 20 00  clr  %o0
a00b9964:  7f ff a6 10  call  0xa00a31a4
a00b9968:  e0 2f bf e8  stb  %l0, [ %fp + -24 ]
a00b996c:  40 00 7c 73  call  0xa00d8b38
a00b9970:  01 00 00 00  nop
a00b9974:  ab 2a 20 10  sll  %o0, 0x10, %l5
a00b9978:  17 00 06 60  sethi  %hi(0x198000), %o3
a00b997c:  92 12 e1 d8  or  %o3, 0x1d8, %o1	! 0x1981d8
a00b9980:  95 35 60 10  srl  %l5, 0x10, %o2
a00b9984:  40 02 77 9c  call  0xa01577f4
a00b9988:  90 10 00 12  mov  %l2, %o0
a00b998c:  98 10 20 00  clr  %o4
a00b9990:  82 10 20 00  clr  %g1
a00b9994:  90 04 40 01  add  %l1, %g1, %o0
a00b9998:  d2 0a 3f f0  ldub  [ %o0 + -16 ], %o1
a00b999c:  80 a2 60 00  cmp  %o1, 0
a00b99a0:  02 80 00 08  be  0xa00b99c0
a00b99a4:  ab 2e 20 10  sll  %i0, 0x10, %l5
a00b99a8:  98 03 20 01  inc  %o4
a00b99ac:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b99b0:  80 a0 60 0f  cmp  %g1, 0xf
a00b99b4:  08 bf ff f9  bleu  0xa00b9998
a00b99b8:  90 04 40 01  add  %l1, %g1, %o0
a00b99bc:  ab 2e 20 10  sll  %i0, 0x10, %l5
a00b99c0:  a8 06 60 0b  add  %i1, 0xb, %l4
a00b99c4:  a6 03 3f ff  add  %o4, -1, %l3
a00b99c8:  a1 35 60 10  srl  %l5, 0x10, %l0
a00b99cc:  95 2d 20 10  sll  %l4, 0x10, %o2
a00b99d0:  9a 10 20 00  clr  %o5
a00b99d4:  e6 2f bf e8  stb  %l3, [ %fp + -24 ]
a00b99d8:  95 32 a0 10  srl  %o2, 0x10, %o2
a00b99dc:  90 10 20 00  clr  %o0
a00b99e0:  92 10 00 10  mov  %l0, %o1
a00b99e4:  96 10 20 10  mov  0x10, %o3
a00b99e8:  7f ff a5 ef  call  0xa00a31a4
a00b99ec:  98 10 00 12  mov  %l2, %o4
a00b99f0:  9a 15 a2 90  or  %l6, 0x290, %o5
a00b99f4:  c2 03 60 a8  ld  [ %o5 + 0xa8 ], %g1
a00b99f8:  80 88 68 00  btst  0x800, %g1
a00b99fc:  22 80 00 7d  be,a   0xa00b9bf0
a00b9a00:  c2 0b 61 82  ldub  [ %o5 + 0x182 ], %g1
a00b9a04:  da 0b 61 81  ldub  [ %o5 + 0x181 ], %o5
a00b9a08:  98 0b 60 ff  and  %o5, 0xff, %o4
a00b9a0c:  80 a3 20 07  cmp  %o4, 7
a00b9a10:  02 80 00 07  be  0xa00b9a2c
a00b9a14:  82 10 20 00  clr  %g1
a00b9a18:  80 a3 20 06  cmp  %o4, 6
a00b9a1c:  18 80 00 04  bgu  0xa00b9a2c
a00b9a20:  82 10 00 0c  mov  %o4, %g1
a00b9a24:  a0 03 60 01  add  %o5, 1, %l0
a00b9a28:  82 0c 20 ff  and  %l0, 0xff, %g1
a00b9a2c:  94 08 60 ff  and  %g1, 0xff, %o2
a00b9a30:  a7 2a a0 03  sll  %o2, 3, %l3
a00b9a34:  82 24 c0 0a  sub  %l3, %o2, %g1
a00b9a38:  98 15 a2 90  or  %l6, 0x290, %o4
a00b9a3c:  93 28 60 02  sll  %g1, 2, %o1
a00b9a40:  9e 02 40 0a  add  %o1, %o2, %o7
a00b9a44:  d0 0b 20 08  ldub  [ %o4 + 8 ], %o0
a00b9a48:  9a 03 c0 08  add  %o7, %o0, %o5
a00b9a4c:  97 2b 60 10  sll  %o5, 0x10, %o3
a00b9a50:  2d 00 06 54  sethi  %hi(0x195000), %l6
a00b9a54:  93 32 e0 10  srl  %o3, 0x10, %o1
a00b9a58:  7f ff a7 7b  call  0xa00a3844
a00b9a5c:  90 15 a1 dc  or  %l6, 0x1dc, %o0
a00b9a60:  aa 06 60 0e  add  %i1, 0xe, %l5
a00b9a64:  a9 2e 20 10  sll  %i0, 0x10, %l4
a00b9a68:  98 10 00 08  mov  %o0, %o4
a00b9a6c:  95 2d 60 10  sll  %l5, 0x10, %o2
a00b9a70:  93 35 20 10  srl  %l4, 0x10, %o1
a00b9a74:  95 32 a0 10  srl  %o2, 0x10, %o2
a00b9a78:  90 10 20 00  clr  %o0
a00b9a7c:  96 10 20 10  mov  0x10, %o3
a00b9a80:  7f ff a5 c9  call  0xa00a31a4
a00b9a84:  9a 10 20 00  clr  %o5
a00b9a88:  40 00 78 b0  call  0xa00d7d48
a00b9a8c:  01 00 00 00  nop
a00b9a90:  80 a2 20 00  cmp  %o0, 0
a00b9a94:  12 80 00 03  bne  0xa00b9aa0
a00b9a98:  03 1b 92 11  sethi  %hi(0x6e484400), %g1
a00b9a9c:  03 1b 94 d1  sethi  %hi(0x6e534400), %g1
a00b9aa0:  a0 10 60 52  or  %g1, 0x52, %l0	! 0x6e534452
a00b9aa4:  e0 27 bf e8  st  %l0, [ %fp + -24 ]
a00b9aa8:  c0 2f bf ec  clrb  [ %fp + -20 ]
a00b9aac:  98 10 20 00  clr  %o4
a00b9ab0:  82 10 20 00  clr  %g1
a00b9ab4:  aa 04 40 01  add  %l1, %g1, %l5
a00b9ab8:  e8 0d 7f f0  ldub  [ %l5 + -16 ], %l4
a00b9abc:  80 a5 20 00  cmp  %l4, 0
a00b9ac0:  02 80 00 08  be  0xa00b9ae0
a00b9ac4:  9e 06 60 11  add  %i1, 0x11, %o7
a00b9ac8:  98 03 20 01  inc  %o4
a00b9acc:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b9ad0:  80 a0 60 0f  cmp  %g1, 0xf
a00b9ad4:  08 bf ff f9  bleu  0xa00b9ab8
a00b9ad8:  aa 04 40 01  add  %l1, %g1, %l5
a00b9adc:  9e 06 60 11  add  %i1, 0x11, %o7
a00b9ae0:  9a 03 3f ff  add  %o4, -1, %o5
a00b9ae4:  97 2d e0 10  sll  %l7, 0x10, %o3
a00b9ae8:  ad 2b e0 10  sll  %o7, 0x10, %l6
a00b9aec:  93 32 e0 10  srl  %o3, 0x10, %o1
a00b9af0:  da 2f bf e8  stb  %o5, [ %fp + -24 ]
a00b9af4:  95 35 a0 10  srl  %l6, 0x10, %o2
a00b9af8:  96 10 20 0e  mov  0xe, %o3
a00b9afc:  98 10 00 12  mov  %l2, %o4
a00b9b00:  9a 10 20 00  clr  %o5
a00b9b04:  7f ff a5 a8  call  0xa00a31a4
a00b9b08:  90 10 20 00  clr  %o0
a00b9b0c:  40 02 2b 2c  call  0xa01447bc
a00b9b10:  90 10 20 00  clr  %o0
a00b9b14:  a0 10 00 08  mov  %o0, %l0
a00b9b18:  40 02 4e 8b  call  0xa014d544
a00b9b1c:  90 10 20 00  clr  %o0
a00b9b20:  80 8a 20 ff  btst  0xff, %o0
a00b9b24:  02 80 00 0a  be  0xa00b9b4c
a00b9b28:  90 0c 20 ff  and  %l0, 0xff, %o0
a00b9b2c:  90 07 7f fb  add  %i5, -5, %o0
a00b9b30:  ae 0a 20 ff  and  %o0, 0xff, %l7
a00b9b34:  80 a5 e0 01  cmp  %l7, 1
a00b9b38:  18 80 00 05  bgu  0xa00b9b4c
a00b9b3c:  90 0c 20 ff  and  %l0, 0xff, %o0
a00b9b40:  3b 2a 00 97  sethi  %hi(0xa8025c00), %i5
a00b9b44:  e0 0f 60 57  ldub  [ %i5 + 0x57 ], %l0	! 0xa8025c57
a00b9b48:  90 0c 20 ff  and  %l0, 0xff, %o0
a00b9b4c:  80 a2 20 08  cmp  %o0, 8
a00b9b50:  02 80 00 1c  be  0xa00b9bc0
a00b9b54:  03 1b 8e 08  sethi  %hi(0x6e382000), %g1
a00b9b58:  19 1b 8c 4c  sethi  %hi(0x6e313000), %o4
a00b9b5c:  80 a2 20 0a  cmp  %o0, 0xa
a00b9b60:  02 80 00 21  be  0xa00b9be4
a00b9b64:  98 13 20 20  or  %o4, 0x20, %o4
a00b9b68:  80 a2 20 0c  cmp  %o0, 0xc
a00b9b6c:  02 80 00 1d  be  0xa00b9be0
a00b9b70:  19 1b 8c 4c  sethi  %hi(0x6e313000), %o4
a00b9b74:  80 a2 20 10  cmp  %o0, 0x10
a00b9b78:  02 80 00 19  be  0xa00b9bdc
a00b9b7c:  80 a2 20 06  cmp  %o0, 6
a00b9b80:  02 80 00 10  be  0xa00b9bc0
a00b9b84:  03 1b 8d 88  sethi  %hi(0x6e362000), %g1
a00b9b88:  98 10 20 00  clr  %o4
a00b9b8c:  82 10 20 00  clr  %g1
a00b9b90:  a0 04 40 01  add  %l1, %g1, %l0
a00b9b94:  e6 0c 3f f0  ldub  [ %l0 + -16 ], %l3
a00b9b98:  80 a4 e0 00  cmp  %l3, 0
a00b9b9c:  02 80 00 25  be  0xa00b9c30
a00b9ba0:  a8 06 60 14  add  %i1, 0x14, %l4
a00b9ba4:  98 03 20 01  inc  %o4
a00b9ba8:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b9bac:  80 a0 60 0f  cmp  %g1, 0xf
a00b9bb0:  08 bf ff f9  bleu  0xa00b9b94
a00b9bb4:  a0 04 40 01  add  %l1, %g1, %l0
a00b9bb8:  10 80 00 1f  b  0xa00b9c34
a00b9bbc:  b3 2e 20 10  sll  %i0, 0x10, %i1
a00b9bc0:  15 00 00 1a  sethi  %hi(0x6800), %o2
a00b9bc4:  82 10 60 42  or  %g1, 0x42, %g1
a00b9bc8:  92 12 a1 74  or  %o2, 0x174, %o1
a00b9bcc:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a00b9bd0:  d2 37 bf ec  sth  %o1, [ %fp + -20 ]
a00b9bd4:  10 bf ff ed  b  0xa00b9b88
a00b9bd8:  c0 2f bf ee  clrb  [ %fp + -18 ]
a00b9bdc:  19 1b 8c 4d  sethi  %hi(0x6e313400), %o4
a00b9be0:  98 13 22 20  or  %o4, 0x220, %o4	! 0x6e313620
a00b9be4:  1b 10 9a 5d  sethi  %hi(0x42697400), %o5
a00b9be8:  10 bf ff e8  b  0xa00b9b88
a00b9bec:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a00b9bf0:  a7 28 60 03  sll  %g1, 3, %l3
a00b9bf4:  94 24 c0 01  sub  %l3, %g1, %o2
a00b9bf8:  93 2a a0 02  sll  %o2, 2, %o1
a00b9bfc:  d0 0b 60 08  ldub  [ %o5 + 8 ], %o0
a00b9c00:  9e 02 40 01  add  %o1, %g1, %o7
a00b9c04:  98 03 c0 08  add  %o7, %o0, %o4
a00b9c08:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00b9c0c:  17 00 06 57  sethi  %hi(0x195c00), %o3
a00b9c10:  93 33 60 10  srl  %o5, 0x10, %o1
a00b9c14:  7f ff a7 0c  call  0xa00a3844
a00b9c18:  90 12 e3 24  or  %o3, 0x324, %o0
a00b9c1c:  ac 06 60 0e  add  %i1, 0xe, %l6
a00b9c20:  98 10 00 08  mov  %o0, %o4
a00b9c24:  95 2d a0 10  sll  %l6, 0x10, %o2
a00b9c28:  10 bf ff 93  b  0xa00b9a74
a00b9c2c:  92 10 00 10  mov  %l0, %o1
a00b9c30:  b3 2e 20 10  sll  %i0, 0x10, %i1
a00b9c34:  a2 03 3f ff  add  %o4, -1, %l1
a00b9c38:  b1 2d 20 10  sll  %l4, 0x10, %i0
a00b9c3c:  e2 2f bf e8  stb  %l1, [ %fp + -24 ]
a00b9c40:  93 36 60 10  srl  %i1, 0x10, %o1
a00b9c44:  95 36 20 10  srl  %i0, 0x10, %o2
a00b9c48:  98 10 00 12  mov  %l2, %o4
a00b9c4c:  90 10 20 00  clr  %o0
a00b9c50:  96 10 20 10  mov  0x10, %o3
a00b9c54:  7f ff a5 54  call  0xa00a31a4
a00b9c58:  9a 10 20 00  clr  %o5
a00b9c5c:  01 00 00 00  nop
a00b9c60:  81 c7 e0 08  ret
a00b9c64:  81 e8 00 00  restore
