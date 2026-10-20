# leon2m FUN_a00ec6b8 0xa00ec6b8-0xa00ed528 (3696 bytes)
a00ec6b8:  9d e3 bf 88  save  %sp, -120, %sp
a00ec6bc:  fa 27 a0 58  st  %i5, [ %fp + 0x58 ]
a00ec6c0:  f2 27 a0 48  st  %i1, [ %fp + 0x48 ]
a00ec6c4:  f8 27 a0 54  st  %i4, [ %fp + 0x54 ]
a00ec6c8:  80 a6 a0 03  cmp  %i2, 3
a00ec6cc:  02 80 01 4c  be  0xa00ecbfc
a00ec6d0:  fa 07 a0 40  ld  [ %fp + 0x40 ], %i5
a00ec6d4:  90 10 00 18  mov  %i0, %o0
a00ec6d8:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a00ec6dc:  7f ff cd 5d  call  0xa00dfc50
a00ec6e0:  94 10 00 1a  mov  %i2, %o2
a00ec6e4:  80 a6 ff ff  cmp  %i3, -1
a00ec6e8:  02 80 01 23  be  0xa00ecb74
a00ec6ec:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00ec6f0:  33 2a 00 ad  sethi  %hi(0xa802b400), %i1
a00ec6f4:  39 2a 00 99  sethi  %hi(0xa8026400), %i4
a00ec6f8:  a1 2e e0 02  sll  %i3, 2, %l0
a00ec6fc:  ae 13 23 68  or  %o4, 0x368, %l7
a00ec700:  aa 16 62 e8  or  %i1, 0x2e8, %l5
a00ec704:  ac 17 23 58  or  %i4, 0x358, %l6
a00ec708:  d2 05 c0 10  ld  [ %l7 + %l0 ], %o1
a00ec70c:  d4 05 80 10  ld  [ %l6 + %l0 ], %o2
a00ec710:  d6 05 40 10  ld  [ %l5 + %l0 ], %o3
a00ec714:  7f ff d0 10  call  0xa00e0754
a00ec718:  90 10 00 18  mov  %i0, %o0
a00ec71c:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00ec720:  92 14 a3 78  or  %l2, 0x378, %o1	! 0xa8026778
a00ec724:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00ec728:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00ec72c:  b2 10 00 08  mov  %o0, %i1
a00ec730:  a2 15 23 98  or  %l4, 0x398, %l1
a00ec734:  9e 14 e3 88  or  %l3, 0x388, %o7
a00ec738:  d6 02 40 10  ld  [ %o1 + %l0 ], %o3
a00ec73c:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a00ec740:  d4 03 c0 10  ld  [ %o7 + %l0 ], %o2
a00ec744:  90 10 00 18  mov  %i0, %o0
a00ec748:  7f ff d0 03  call  0xa00e0754
a00ec74c:  01 00 00 00  nop
a00ec750:  80 a6 ff ff  cmp  %i3, -1
a00ec754:  02 80 01 01  be  0xa00ecb58
a00ec758:  b8 10 00 08  mov  %o0, %i4
a00ec75c:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ec760:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ec764:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ec768:  a1 2e e0 02  sll  %i3, 2, %l0
a00ec76c:  a4 12 e0 f8  or  %o3, 0xf8, %l2
a00ec770:  a2 12 61 18  or  %o1, 0x118, %l1
a00ec774:  9e 12 a1 08  or  %o2, 0x108, %o7
a00ec778:  d6 04 80 10  ld  [ %l2 + %l0 ], %o3
a00ec77c:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a00ec780:  d4 03 c0 10  ld  [ %o7 + %l0 ], %o2
a00ec784:  7f ff cf f4  call  0xa00e0754
a00ec788:  90 10 00 18  mov  %i0, %o0
a00ec78c:  27 2a 00 b5  sethi  %hi(0xa802d400), %l3
a00ec790:  80 a6 ff ff  cmp  %i3, -1
a00ec794:  02 80 00 e9  be  0xa00ecb38
a00ec798:  d0 24 e2 6c  st  %o0, [ %l3 + 0x26c ]
a00ec79c:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00ec7a0:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ec7a4:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00ec7a8:  af 2e e0 02  sll  %i3, 2, %l7
a00ec7ac:  82 12 20 c8  or  %o0, 0xc8, %g1
a00ec7b0:  98 13 e0 e8  or  %o7, 0xe8, %o4
a00ec7b4:  9a 14 20 d8  or  %l0, 0xd8, %o5
a00ec7b8:  d6 00 40 17  ld  [ %g1 + %l7 ], %o3
a00ec7bc:  d2 03 00 17  ld  [ %o4 + %l7 ], %o1
a00ec7c0:  d4 03 40 17  ld  [ %o5 + %l7 ], %o2
a00ec7c4:  90 10 00 18  mov  %i0, %o0
a00ec7c8:  7f ff cf e3  call  0xa00e0754
a00ec7cc:  01 00 00 00  nop
a00ec7d0:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00ec7d4:  80 a6 ff ff  cmp  %i3, -1
a00ec7d8:  02 80 00 d0  be  0xa00ecb18
a00ec7dc:  d0 22 a2 70  st  %o0, [ %o2 + 0x270 ]
a00ec7e0:  2d 2a 00 9a  sethi  %hi(0xa8026800), %l6
a00ec7e4:  a7 2e e0 02  sll  %i3, 2, %l3
a00ec7e8:  92 15 a0 98  or  %l6, 0x98, %o1
a00ec7ec:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00ec7f0:  2f 2a 00 9a  sethi  %hi(0xa8026800), %l7
a00ec7f4:  aa 13 60 b8  or  %o5, 0xb8, %l5
a00ec7f8:  a8 15 e0 a8  or  %l7, 0xa8, %l4
a00ec7fc:  d6 02 40 13  ld  [ %o1 + %l3 ], %o3
a00ec800:  d2 05 40 13  ld  [ %l5 + %l3 ], %o1
a00ec804:  d4 05 00 13  ld  [ %l4 + %l3 ], %o2
a00ec808:  90 10 00 18  mov  %i0, %o0
a00ec80c:  7f ff cf d2  call  0xa00e0754
a00ec810:  a2 10 3f ff  mov  -1, %l1
a00ec814:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a00ec818:  d0 23 22 74  st  %o0, [ %o4 + 0x274 ]	! 0xa802d674
a00ec81c:  90 10 00 18  mov  %i0, %o0
a00ec820:  92 10 00 1b  mov  %i3, %o1
a00ec824:  d4 07 a0 54  ld  [ %fp + 0x54 ], %o2
a00ec828:  96 10 00 19  mov  %i1, %o3
a00ec82c:  7f ff fb b7  call  0xa00eb708
a00ec830:  98 10 00 1c  mov  %i4, %o4
a00ec834:  90 10 00 18  mov  %i0, %o0
a00ec838:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a00ec83c:  94 10 00 1a  mov  %i2, %o2
a00ec840:  7f ff de 8e  call  0xa00e4278
a00ec844:  d6 07 a0 58  ld  [ %fp + 0x58 ], %o3
a00ec848:  80 a2 20 00  cmp  %o0, 0
a00ec84c:  12 80 00 4d  bne  0xa00ec980
a00ec850:  e8 07 a0 54  ld  [ %fp + 0x54 ], %l4
a00ec854:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00ec858:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00ec85c:  ac 14 60 e8  or  %l1, 0xe8, %l6
a00ec860:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ec864:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ec868:  a6 14 20 b8  or  %l0, 0xb8, %l3
a00ec86c:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00ec870:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00ec874:  ae 12 a0 d8  or  %o2, 0xd8, %l7
a00ec878:  aa 13 e0 c8  or  %o7, 0xc8, %l5
a00ec87c:  a2 12 20 a8  or  %o0, 0xa8, %l1
a00ec880:  a4 10 60 98  or  %g1, 0x98, %l2
a00ec884:  a1 2e e0 02  sll  %i3, 2, %l0
a00ec888:  80 a5 20 0c  cmp  %l4, 0xc
a00ec88c:  02 80 00 e9  be  0xa00ecc30
a00ec890:  80 a6 ff ff  cmp  %i3, -1
a00ec894:  02 80 00 7f  be  0xa00eca90
a00ec898:  a8 05 20 01  inc  %l4
a00ec89c:  d2 05 80 10  ld  [ %l6 + %l0 ], %o1
a00ec8a0:  d4 05 c0 10  ld  [ %l7 + %l0 ], %o2
a00ec8a4:  d6 05 40 10  ld  [ %l5 + %l0 ], %o3
a00ec8a8:  7f ff cf ab  call  0xa00e0754
a00ec8ac:  90 10 00 18  mov  %i0, %o0
a00ec8b0:  98 02 20 01  add  %o0, 1, %o4
a00ec8b4:  90 10 00 18  mov  %i0, %o0
a00ec8b8:  d2 05 80 10  ld  [ %l6 + %l0 ], %o1
a00ec8bc:  d4 05 c0 10  ld  [ %l7 + %l0 ], %o2
a00ec8c0:  7f ff cf ad  call  0xa00e0774
a00ec8c4:  d6 05 40 10  ld  [ %l5 + %l0 ], %o3
a00ec8c8:  d2 04 c0 10  ld  [ %l3 + %l0 ], %o1
a00ec8cc:  d4 04 40 10  ld  [ %l1 + %l0 ], %o2
a00ec8d0:  d6 04 80 10  ld  [ %l2 + %l0 ], %o3
a00ec8d4:  7f ff cf a0  call  0xa00e0754
a00ec8d8:  90 10 00 18  mov  %i0, %o0
a00ec8dc:  98 02 20 01  add  %o0, 1, %o4
a00ec8e0:  90 10 00 18  mov  %i0, %o0
a00ec8e4:  d2 04 c0 10  ld  [ %l3 + %l0 ], %o1
a00ec8e8:  d4 04 40 10  ld  [ %l1 + %l0 ], %o2
a00ec8ec:  d6 04 80 10  ld  [ %l2 + %l0 ], %o3
a00ec8f0:  7f ff cf a1  call  0xa00e0774
a00ec8f4:  01 00 00 00  nop
a00ec8f8:  80 a5 20 08  cmp  %l4, 8
a00ec8fc:  04 80 00 53  ble  0xa00eca48
a00ec900:  80 a6 ff ff  cmp  %i3, -1
a00ec904:  02 80 00 ad  be  0xa00ecbb8
a00ec908:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00ec90c:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ec910:  96 12 61 48  or  %o1, 0x148, %o3	! 0xa8026948
a00ec914:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00ec918:  d2 02 c0 10  ld  [ %o3 + %l0 ], %o1
a00ec91c:  9e 13 61 38  or  %o5, 0x138, %o7
a00ec920:  82 13 21 28  or  %o4, 0x128, %g1
a00ec924:  90 10 00 18  mov  %i0, %o0
a00ec928:  d4 03 c0 10  ld  [ %o7 + %l0 ], %o2
a00ec92c:  d6 00 40 10  ld  [ %g1 + %l0 ], %o3
a00ec930:  98 10 20 03  mov  3, %o4
a00ec934:  7f ff cf 90  call  0xa00e0774
a00ec938:  01 00 00 00  nop
a00ec93c:  90 10 00 18  mov  %i0, %o0
a00ec940:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a00ec944:  94 10 00 1a  mov  %i2, %o2
a00ec948:  7f ff de 4c  call  0xa00e4278
a00ec94c:  d6 07 a0 58  ld  [ %fp + 0x58 ], %o3
a00ec950:  80 a2 20 01  cmp  %o0, 1
a00ec954:  02 80 00 b9  be  0xa00ecc38
a00ec958:  80 a2 20 00  cmp  %o0, 0
a00ec95c:  02 bf ff cc  be  0xa00ec88c
a00ec960:  80 a5 20 0c  cmp  %l4, 0xc
a00ec964:  7f ff cb aa  call  0xa00df80c
a00ec968:  29 00 06 67  sethi  %hi(0x199c00), %l4
a00ec96c:  7f ff d0 95  call  0xa00e0bc0
a00ec970:  01 00 00 00  nop
a00ec974:  90 15 20 20  or  %l4, 0x20, %o0
a00ec978:  7f ff c9 fe  call  0xa00df170
a00ec97c:  a2 10 3f ff  mov  -1, %l1
a00ec980:  e0 07 a0 58  ld  [ %fp + 0x58 ], %l0
a00ec984:  f8 23 a0 5c  st  %i4, [ %sp + 0x5c ]
a00ec988:  e0 23 a0 60  st  %l0, [ %sp + 0x60 ]
a00ec98c:  94 10 00 1a  mov  %i2, %o2
a00ec990:  9a 10 00 19  mov  %i1, %o5
a00ec994:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a00ec998:  d8 07 a0 54  ld  [ %fp + 0x54 ], %o4
a00ec99c:  90 10 00 18  mov  %i0, %o0
a00ec9a0:  7f ff fc 31  call  0xa00eba64
a00ec9a4:  96 10 00 1b  mov  %i3, %o3
a00ec9a8:  a0 10 00 08  mov  %o0, %l0
a00ec9ac:  90 38 00 11  xnor  %g0, %l1, %o0
a00ec9b0:  80 a0 00 08  cmp  %g0, %o0
a00ec9b4:  b2 60 3f ff  subx  %g0, -1, %i1
a00ec9b8:  b8 38 00 10  xnor  %g0, %l0, %i4
a00ec9bc:  80 a0 00 1c  cmp  %g0, %i4
a00ec9c0:  b4 60 3f ff  subx  %g0, -1, %i2
a00ec9c4:  80 96 40 1a  orcc  %i1, %i2, %g0
a00ec9c8:  32 80 00 2d  bne,a   0xa00eca7c
a00ec9cc:  b0 10 3f ff  mov  -1, %i0
a00ec9d0:  80 a6 ff ff  cmp  %i3, -1
a00ec9d4:  02 80 00 90  be  0xa00ecc14
a00ec9d8:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00ec9dc:  13 2a 00 98  sethi  %hi(0xa8026000), %o1
a00ec9e0:  27 2a 00 98  sethi  %hi(0xa8026000), %l3
a00ec9e4:  ad 2e e0 02  sll  %i3, 2, %l6
a00ec9e8:  aa 13 22 38  or  %o4, 0x238, %l5
a00ec9ec:  a4 12 63 08  or  %o1, 0x308, %l2
a00ec9f0:  ae 14 e2 f8  or  %l3, 0x2f8, %l7
a00ec9f4:  d6 05 40 16  ld  [ %l5 + %l6 ], %o3
a00ec9f8:  d2 04 80 16  ld  [ %l2 + %l6 ], %o1
a00ec9fc:  d4 05 c0 16  ld  [ %l7 + %l6 ], %o2
a00eca00:  7f ff cf 55  call  0xa00e0754
a00eca04:  90 10 00 18  mov  %i0, %o0
a00eca08:  b9 34 20 08  srl  %l0, 8, %i4
a00eca0c:  b3 34 60 08  srl  %l1, 8, %i1
a00eca10:  98 10 00 08  mov  %o0, %o4
a00eca14:  94 5f 00 08  smul  %i4, %o0, %o2
a00eca18:  a8 5e 40 08  smul  %i1, %o0, %l4
a00eca1c:  82 0c 20 ff  and  %l0, 0xff, %g1
a00eca20:  b4 0c 60 ff  and  %l1, 0xff, %i2
a00eca24:  94 02 80 01  add  %o2, %g1, %o2
a00eca28:  96 05 00 1a  add  %l4, %i2, %o3
a00eca2c:  90 10 00 18  mov  %i0, %o0
a00eca30:  7f ff fe 44  call  0xa00ec340
a00eca34:  92 10 00 1b  mov  %i3, %o1
a00eca38:  e0 27 40 00  st  %l0, [ %i5 ]
a00eca3c:  e2 27 60 04  st  %l1, [ %i5 + 4 ]
a00eca40:  10 80 02 b8  b  0xa00ed520
a00eca44:  e0 3f bf f0  std  %l0, [ %fp + -16 ]
a00eca48:  02 80 00 64  be  0xa00ecbd8
a00eca4c:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00eca50:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00eca54:  98 12 61 48  or  %o1, 0x148, %o4	! 0xa8026948
a00eca58:  96 10 61 38  or  %g1, 0x138, %o3
a00eca5c:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00eca60:  d2 03 00 10  ld  [ %o4 + %l0 ], %o1
a00eca64:  d4 02 c0 10  ld  [ %o3 + %l0 ], %o2
a00eca68:  9e 13 61 28  or  %o5, 0x128, %o7
a00eca6c:  90 10 00 18  mov  %i0, %o0
a00eca70:  d6 03 c0 10  ld  [ %o7 + %l0 ], %o3
a00eca74:  10 bf ff b0  b  0xa00ec934
a00eca78:  98 10 20 00  clr  %o4
a00eca7c:  f0 27 60 04  st  %i0, [ %i5 + 4 ]
a00eca80:  f0 27 bf f0  st  %i0, [ %fp + -16 ]
a00eca84:  f0 27 bf f4  st  %i0, [ %fp + -12 ]
a00eca88:  10 80 02 a6  b  0xa00ed520
a00eca8c:  f0 27 40 00  st  %i0, [ %i5 ]
a00eca90:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00eca94:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00eca98:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00eca9c:  96 12 20 c8  or  %o0, 0xc8, %o3
a00ecaa0:  92 13 e0 e8  or  %o7, 0xe8, %o1
a00ecaa4:  94 13 20 d8  or  %o4, 0xd8, %o2
a00ecaa8:  7f ff cf 2b  call  0xa00e0754
a00ecaac:  90 10 00 18  mov  %i0, %o0
a00ecab0:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ecab4:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00ecab8:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00ecabc:  98 02 20 01  add  %o0, 1, %o4
a00ecac0:  94 12 e0 d8  or  %o3, 0xd8, %o2
a00ecac4:  92 10 60 e8  or  %g1, 0xe8, %o1
a00ecac8:  96 13 60 c8  or  %o5, 0xc8, %o3
a00ecacc:  7f ff cf 2a  call  0xa00e0774
a00ecad0:  90 10 00 18  mov  %i0, %o0
a00ecad4:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ecad8:  92 12 a0 b8  or  %o2, 0xb8, %o1	! 0xa80268b8
a00ecadc:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00ecae0:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ecae4:  96 13 20 98  or  %o4, 0x98, %o3
a00ecae8:  94 13 e0 a8  or  %o7, 0xa8, %o2
a00ecaec:  7f ff cf 1a  call  0xa00e0754
a00ecaf0:  90 10 00 18  mov  %i0, %o0
a00ecaf4:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ecaf8:  98 02 20 01  add  %o0, 1, %o4
a00ecafc:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00ecb00:  94 12 e0 a8  or  %o3, 0xa8, %o2
a00ecb04:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00ecb08:  90 10 00 18  mov  %i0, %o0
a00ecb0c:  92 10 60 b8  or  %g1, 0xb8, %o1
a00ecb10:  10 bf ff 78  b  0xa00ec8f0
a00ecb14:  96 13 60 98  or  %o5, 0x98, %o3
a00ecb18:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ecb1c:  92 12 e0 b8  or  %o3, 0xb8, %o1	! 0xa80268b8
a00ecb20:  25 2a 00 9a  sethi  %hi(0xa8026800), %l2
a00ecb24:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00ecb28:  90 10 00 18  mov  %i0, %o0
a00ecb2c:  94 14 a0 a8  or  %l2, 0xa8, %o2
a00ecb30:  10 bf ff 37  b  0xa00ec80c
a00ecb34:  96 14 60 98  or  %l1, 0x98, %o3
a00ecb38:  2d 2a 00 9a  sethi  %hi(0xa8026800), %l6
a00ecb3c:  2b 2a 00 9a  sethi  %hi(0xa8026800), %l5
a00ecb40:  29 2a 00 9a  sethi  %hi(0xa8026800), %l4
a00ecb44:  90 10 00 18  mov  %i0, %o0
a00ecb48:  92 15 a0 e8  or  %l6, 0xe8, %o1
a00ecb4c:  94 15 60 d8  or  %l5, 0xd8, %o2
a00ecb50:  10 bf ff 1e  b  0xa00ec7c8
a00ecb54:  96 15 20 c8  or  %l4, 0xc8, %o3
a00ecb58:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00ecb5c:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00ecb60:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00ecb64:  92 12 21 18  or  %o0, 0x118, %o1
a00ecb68:  94 13 61 08  or  %o5, 0x108, %o2
a00ecb6c:  10 bf ff 06  b  0xa00ec784
a00ecb70:  96 10 60 f8  or  %g1, 0xf8, %o3
a00ecb74:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ecb78:  92 12 a3 68  or  %o2, 0x368, %o1	! 0xa8026768
a00ecb7c:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ecb80:  94 12 e3 58  or  %o3, 0x358, %o2	! 0xa8026758
a00ecb84:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00ecb88:  96 12 22 e8  or  %o0, 0x2e8, %o3	! 0xa802b6e8
a00ecb8c:  7f ff ce f2  call  0xa00e0754
a00ecb90:  90 10 00 18  mov  %i0, %o0
a00ecb94:  b2 10 00 08  mov  %o0, %i1
a00ecb98:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00ecb9c:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ecba0:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00ecba4:  90 10 00 18  mov  %i0, %o0
a00ecba8:  92 13 63 98  or  %o5, 0x398, %o1
a00ecbac:  94 10 63 88  or  %g1, 0x388, %o2
a00ecbb0:  10 bf fe e6  b  0xa00ec748
a00ecbb4:  96 13 23 78  or  %o4, 0x378, %o3
a00ecbb8:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ecbbc:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ecbc0:  92 12 a1 48  or  %o2, 0x148, %o1
a00ecbc4:  94 12 e1 38  or  %o3, 0x138, %o2
a00ecbc8:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00ecbcc:  90 10 00 18  mov  %i0, %o0
a00ecbd0:  10 bf ff 58  b  0xa00ec930
a00ecbd4:  96 13 61 28  or  %o5, 0x128, %o3
a00ecbd8:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ecbdc:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00ecbe0:  92 12 a1 48  or  %o2, 0x148, %o1
a00ecbe4:  94 13 21 38  or  %o4, 0x138, %o2
a00ecbe8:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00ecbec:  90 10 00 18  mov  %i0, %o0
a00ecbf0:  96 10 61 28  or  %g1, 0x128, %o3
a00ecbf4:  10 bf ff 50  b  0xa00ec934
a00ecbf8:  98 10 20 00  clr  %o4
a00ecbfc:  90 10 20 0b  mov  0xb, %o0
a00ecc00:  92 10 00 18  mov  %i0, %o1
a00ecc04:  7f ff cc ec  call  0xa00dffb4
a00ecc08:  94 10 00 1b  mov  %i3, %o2
a00ecc0c:  10 bf fe b3  b  0xa00ec6d8
a00ecc10:  90 10 00 18  mov  %i0, %o0
a00ecc14:  17 2a 00 98  sethi  %hi(0xa8026000), %o3
a00ecc18:  92 12 e3 08  or  %o3, 0x308, %o1	! 0xa8026308
a00ecc1c:  1b 2a 00 98  sethi  %hi(0xa8026000), %o5
a00ecc20:  1f 2a 00 ad  sethi  %hi(0xa802b400), %o7
a00ecc24:  94 13 62 f8  or  %o5, 0x2f8, %o2
a00ecc28:  10 bf ff 76  b  0xa00eca00
a00ecc2c:  96 13 e2 38  or  %o7, 0x238, %o3
a00ecc30:  10 bf ff 54  b  0xa00ec980
a00ecc34:  a2 10 2c 00  mov  0xc00, %l1
a00ecc38:  80 a5 20 00  cmp  %l4, 0
a00ecc3c:  04 80 00 3a  ble  0xa00ecd24
a00ecc40:  80 a6 ff ff  cmp  %i3, -1
a00ecc44:  02 80 00 b1  be  0xa00ecf08
a00ecc48:  a8 05 3f ff  add  %l4, -1, %l4
a00ecc4c:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ecc50:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00ecc54:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ecc58:  ab 2e e0 02  sll  %i3, 2, %l5
a00ecc5c:  ae 13 e0 c8  or  %o7, 0xc8, %l7
a00ecc60:  a2 12 20 e8  or  %o0, 0xe8, %l1
a00ecc64:  a0 12 a0 d8  or  %o2, 0xd8, %l0
a00ecc68:  d2 04 40 15  ld  [ %l1 + %l5 ], %o1
a00ecc6c:  d4 04 00 15  ld  [ %l0 + %l5 ], %o2
a00ecc70:  d6 05 c0 15  ld  [ %l7 + %l5 ], %o3
a00ecc74:  7f ff ce b8  call  0xa00e0754
a00ecc78:  90 10 00 18  mov  %i0, %o0
a00ecc7c:  98 02 3f ff  add  %o0, -1, %o4
a00ecc80:  d2 04 40 15  ld  [ %l1 + %l5 ], %o1
a00ecc84:  d4 04 00 15  ld  [ %l0 + %l5 ], %o2
a00ecc88:  d6 05 c0 15  ld  [ %l7 + %l5 ], %o3
a00ecc8c:  7f ff ce ba  call  0xa00e0774
a00ecc90:  90 10 00 18  mov  %i0, %o0
a00ecc94:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00ecc98:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ecc9c:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00ecca0:  a6 13 20 a8  or  %o4, 0xa8, %l3
a00ecca4:  ac 10 60 98  or  %g1, 0x98, %l6
a00ecca8:  a4 12 60 b8  or  %o1, 0xb8, %l2
a00eccac:  d2 04 80 15  ld  [ %l2 + %l5 ], %o1
a00eccb0:  d4 04 c0 15  ld  [ %l3 + %l5 ], %o2
a00eccb4:  d6 05 80 15  ld  [ %l6 + %l5 ], %o3
a00eccb8:  7f ff ce a7  call  0xa00e0754
a00eccbc:  90 10 00 18  mov  %i0, %o0
a00eccc0:  98 02 3f ff  add  %o0, -1, %o4
a00eccc4:  d6 05 80 15  ld  [ %l6 + %l5 ], %o3
a00eccc8:  d2 04 80 15  ld  [ %l2 + %l5 ], %o1
a00ecccc:  d4 04 c0 15  ld  [ %l3 + %l5 ], %o2
a00eccd0:  90 10 00 18  mov  %i0, %o0
a00eccd4:  7f ff ce a8  call  0xa00e0774
a00eccd8:  01 00 00 00  nop
a00eccdc:  80 a5 20 08  cmp  %l4, 8
a00ecce0:  04 80 00 7c  ble  0xa00eced0
a00ecce4:  80 a6 ff ff  cmp  %i3, -1
a00ecce8:  02 80 00 b3  be  0xa00ecfb4
a00eccec:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00eccf0:  a7 2e e0 02  sll  %i3, 2, %l3
a00eccf4:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00eccf8:  98 10 61 28  or  %g1, 0x128, %o4
a00eccfc:  2f 2a 00 9a  sethi  %hi(0xa8026800), %l7
a00ecd00:  a4 12 61 38  or  %o1, 0x138, %l2
a00ecd04:  ac 15 e1 48  or  %l7, 0x148, %l6
a00ecd08:  d6 03 00 13  ld  [ %o4 + %l3 ], %o3
a00ecd0c:  d2 05 80 13  ld  [ %l6 + %l3 ], %o1
a00ecd10:  d4 04 80 13  ld  [ %l2 + %l3 ], %o2
a00ecd14:  90 10 00 18  mov  %i0, %o0
a00ecd18:  98 10 20 03  mov  3, %o4
a00ecd1c:  7f ff ce 96  call  0xa00e0774
a00ecd20:  01 00 00 00  nop
a00ecd24:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00ecd28:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00ecd2c:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00ecd30:  a4 14 23 98  or  %l0, 0x398, %l2
a00ecd34:  a6 15 e3 88  or  %l7, 0x388, %l3
a00ecd38:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00ecd3c:  aa 15 a3 48  or  %l6, 0x348, %l5
a00ecd40:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ecd44:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00ecd48:  a2 12 63 78  or  %o1, 0x378, %l1
a00ecd4c:  a1 2e e0 02  sll  %i3, 2, %l0
a00ecd50:  ac 10 63 38  or  %g1, 0x338, %l6
a00ecd54:  ae 13 23 28  or  %o4, 0x328, %l7
a00ecd58:  80 a6 ff ff  cmp  %i3, -1
a00ecd5c:  22 80 00 3c  be,a   0xa00ece4c
a00ecd60:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ecd64:  d2 04 80 10  ld  [ %l2 + %l0 ], %o1
a00ecd68:  d4 04 c0 10  ld  [ %l3 + %l0 ], %o2
a00ecd6c:  d6 04 40 10  ld  [ %l1 + %l0 ], %o3
a00ecd70:  7f ff ce 79  call  0xa00e0754
a00ecd74:  90 10 00 18  mov  %i0, %o0
a00ecd78:  98 02 20 01  add  %o0, 1, %o4
a00ecd7c:  90 10 00 18  mov  %i0, %o0
a00ecd80:  d2 04 80 10  ld  [ %l2 + %l0 ], %o1
a00ecd84:  d4 04 c0 10  ld  [ %l3 + %l0 ], %o2
a00ecd88:  7f ff ce 7b  call  0xa00e0774
a00ecd8c:  d6 04 40 10  ld  [ %l1 + %l0 ], %o3
a00ecd90:  d2 05 40 10  ld  [ %l5 + %l0 ], %o1
a00ecd94:  d4 05 80 10  ld  [ %l6 + %l0 ], %o2
a00ecd98:  d6 05 c0 10  ld  [ %l7 + %l0 ], %o3
a00ecd9c:  7f ff ce 6e  call  0xa00e0754
a00ecda0:  90 10 00 18  mov  %i0, %o0
a00ecda4:  98 02 20 01  add  %o0, 1, %o4
a00ecda8:  90 10 00 18  mov  %i0, %o0
a00ecdac:  d2 05 40 10  ld  [ %l5 + %l0 ], %o1
a00ecdb0:  d4 05 80 10  ld  [ %l6 + %l0 ], %o2
a00ecdb4:  d6 05 c0 10  ld  [ %l7 + %l0 ], %o3
a00ecdb8:  7f ff ce 6f  call  0xa00e0774
a00ecdbc:  01 00 00 00  nop
a00ecdc0:  90 10 00 18  mov  %i0, %o0
a00ecdc4:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a00ecdc8:  94 10 00 1a  mov  %i2, %o2
a00ecdcc:  7f ff dd 2b  call  0xa00e4278
a00ecdd0:  d6 07 a0 58  ld  [ %fp + 0x58 ], %o3
a00ecdd4:  80 a2 20 01  cmp  %o0, 1
a00ecdd8:  02 80 00 80  be  0xa00ecfd8
a00ecddc:  80 a2 20 00  cmp  %o0, 0
a00ecde0:  12 bf fe e1  bne  0xa00ec964
a00ecde4:  80 a6 ff ff  cmp  %i3, -1
a00ecde8:  02 80 00 0f  be  0xa00ece24
a00ecdec:  90 10 00 18  mov  %i0, %o0
a00ecdf0:  d2 04 80 10  ld  [ %l2 + %l0 ], %o1
a00ecdf4:  d4 04 c0 10  ld  [ %l3 + %l0 ], %o2
a00ecdf8:  7f ff ce 57  call  0xa00e0754
a00ecdfc:  d6 04 40 10  ld  [ %l1 + %l0 ], %o3
a00ece00:  80 a2 20 0f  cmp  %o0, 0xf
a00ece04:  12 bf ff d6  bne  0xa00ecd5c
a00ece08:  80 a6 ff ff  cmp  %i3, -1
a00ece0c:  7f ff ca 80  call  0xa00df80c
a00ece10:  29 00 06 67  sethi  %hi(0x199c00), %l4
a00ece14:  7f ff cf 6b  call  0xa00e0bc0
a00ece18:  01 00 00 00  nop
a00ece1c:  10 bf fe d7  b  0xa00ec978
a00ece20:  90 15 22 70  or  %l4, 0x270, %o0
a00ece24:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00ece28:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00ece2c:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ece30:  92 13 63 98  or  %o5, 0x398, %o1
a00ece34:  94 13 e3 88  or  %o7, 0x388, %o2
a00ece38:  7f ff ce 47  call  0xa00e0754
a00ece3c:  96 10 63 78  or  %g1, 0x378, %o3
a00ece40:  80 a2 20 0f  cmp  %o0, 0xf
a00ece44:  02 bf ff f2  be  0xa00ece0c
a00ece48:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ece4c:  92 12 e3 98  or  %o3, 0x398, %o1	! 0xa8026798
a00ece50:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00ece54:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00ece58:  96 12 23 78  or  %o0, 0x378, %o3
a00ece5c:  94 13 23 88  or  %o4, 0x388, %o2
a00ece60:  7f ff ce 3d  call  0xa00e0754
a00ece64:  90 10 00 18  mov  %i0, %o0
a00ece68:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ece6c:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00ece70:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00ece74:  98 02 20 01  add  %o0, 1, %o4
a00ece78:  92 12 a3 98  or  %o2, 0x398, %o1
a00ece7c:  94 13 63 88  or  %o5, 0x388, %o2
a00ece80:  96 13 e3 78  or  %o7, 0x378, %o3
a00ece84:  7f ff ce 3c  call  0xa00e0774
a00ece88:  90 10 00 18  mov  %i0, %o0
a00ece8c:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ece90:  94 12 e3 38  or  %o3, 0x338, %o2	! 0xa8026738
a00ece94:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00ece98:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ece9c:  96 13 23 28  or  %o4, 0x328, %o3
a00ecea0:  92 10 63 48  or  %g1, 0x348, %o1
a00ecea4:  7f ff ce 2c  call  0xa00e0754
a00ecea8:  90 10 00 18  mov  %i0, %o0
a00eceac:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00eceb0:  98 02 20 01  add  %o0, 1, %o4
a00eceb4:  92 12 a3 48  or  %o2, 0x348, %o1
a00eceb8:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00ecebc:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00ecec0:  90 10 00 18  mov  %i0, %o0
a00ecec4:  94 13 63 38  or  %o5, 0x338, %o2
a00ecec8:  10 bf ff bc  b  0xa00ecdb8
a00ececc:  96 13 e3 28  or  %o7, 0x328, %o3
a00eced0:  02 80 00 30  be  0xa00ecf90
a00eced4:  25 2a 00 9a  sethi  %hi(0xa8026800), %l2
a00eced8:  ab 2e e0 02  sll  %i3, 2, %l5
a00ecedc:  94 14 a1 48  or  %l2, 0x148, %o2
a00ecee0:  27 2a 00 9a  sethi  %hi(0xa8026800), %l3
a00ecee4:  90 14 e1 38  or  %l3, 0x138, %o0	! 0xa8026938
a00ecee8:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00eceec:  d2 02 80 15  ld  [ %o2 + %l5 ], %o1
a00ecef0:  9a 12 e1 28  or  %o3, 0x128, %o5
a00ecef4:  d4 02 00 15  ld  [ %o0 + %l5 ], %o2
a00ecef8:  d6 03 40 15  ld  [ %o5 + %l5 ], %o3
a00ecefc:  90 10 00 18  mov  %i0, %o0
a00ecf00:  10 bf ff 87  b  0xa00ecd1c
a00ecf04:  98 10 20 00  clr  %o4
a00ecf08:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ecf0c:  92 12 e0 e8  or  %o3, 0xe8, %o1	! 0xa80268e8
a00ecf10:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00ecf14:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00ecf18:  96 12 20 c8  or  %o0, 0xc8, %o3
a00ecf1c:  94 13 60 d8  or  %o5, 0xd8, %o2
a00ecf20:  7f ff ce 0d  call  0xa00e0754
a00ecf24:  90 10 00 18  mov  %i0, %o0
a00ecf28:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ecf2c:  98 02 3f ff  add  %o0, -1, %o4
a00ecf30:  92 12 a0 e8  or  %o2, 0xe8, %o1
a00ecf34:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ecf38:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00ecf3c:  94 13 e0 d8  or  %o7, 0xd8, %o2
a00ecf40:  90 10 00 18  mov  %i0, %o0
a00ecf44:  7f ff ce 0c  call  0xa00e0774
a00ecf48:  96 14 60 c8  or  %l1, 0xc8, %o3
a00ecf4c:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00ecf50:  2f 2a 00 9a  sethi  %hi(0xa8026800), %l7
a00ecf54:  2d 2a 00 9a  sethi  %hi(0xa8026800), %l6
a00ecf58:  92 14 20 b8  or  %l0, 0xb8, %o1
a00ecf5c:  94 15 e0 a8  or  %l7, 0xa8, %o2
a00ecf60:  96 15 a0 98  or  %l6, 0x98, %o3
a00ecf64:  7f ff cd fc  call  0xa00e0754
a00ecf68:  90 10 00 18  mov  %i0, %o0
a00ecf6c:  98 02 3f ff  add  %o0, -1, %o4
a00ecf70:  2b 2a 00 9a  sethi  %hi(0xa8026800), %l5
a00ecf74:  27 2a 00 9a  sethi  %hi(0xa8026800), %l3
a00ecf78:  25 2a 00 9a  sethi  %hi(0xa8026800), %l2
a00ecf7c:  90 10 00 18  mov  %i0, %o0
a00ecf80:  92 15 60 b8  or  %l5, 0xb8, %o1
a00ecf84:  94 14 e0 a8  or  %l3, 0xa8, %o2
a00ecf88:  10 bf ff 53  b  0xa00eccd4
a00ecf8c:  96 14 a0 98  or  %l2, 0x98, %o3
a00ecf90:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ecf94:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00ecf98:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00ecf9c:  92 13 e1 48  or  %o7, 0x148, %o1
a00ecfa0:  94 14 61 38  or  %l1, 0x138, %o2
a00ecfa4:  96 14 21 28  or  %l0, 0x128, %o3
a00ecfa8:  90 10 00 18  mov  %i0, %o0
a00ecfac:  10 bf ff 5c  b  0xa00ecd1c
a00ecfb0:  98 10 20 00  clr  %o4
a00ecfb4:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ecfb8:  2b 2a 00 9a  sethi  %hi(0xa8026800), %l5
a00ecfbc:  94 12 e1 38  or  %o3, 0x138, %o2
a00ecfc0:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00ecfc4:  92 15 61 48  or  %l5, 0x148, %o1
a00ecfc8:  96 13 61 28  or  %o5, 0x128, %o3
a00ecfcc:  90 10 00 18  mov  %i0, %o0
a00ecfd0:  10 bf ff 53  b  0xa00ecd1c
a00ecfd4:  98 10 20 03  mov  3, %o4
a00ecfd8:  80 a6 ff ff  cmp  %i3, -1
a00ecfdc:  02 80 00 d8  be  0xa00ed33c
a00ecfe0:  ab 2e e0 02  sll  %i3, 2, %l5
a00ecfe4:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00ecfe8:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ecfec:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ecff0:  a0 12 23 98  or  %o0, 0x398, %l0
a00ecff4:  ae 12 a3 88  or  %o2, 0x388, %l7
a00ecff8:  ac 12 e3 78  or  %o3, 0x378, %l6
a00ecffc:  d2 04 00 15  ld  [ %l0 + %l5 ], %o1
a00ed000:  d4 05 c0 15  ld  [ %l7 + %l5 ], %o2
a00ed004:  d6 05 80 15  ld  [ %l6 + %l5 ], %o3
a00ed008:  7f ff cd d3  call  0xa00e0754
a00ed00c:  90 10 00 18  mov  %i0, %o0
a00ed010:  98 02 3f ff  add  %o0, -1, %o4
a00ed014:  d2 04 00 15  ld  [ %l0 + %l5 ], %o1
a00ed018:  d4 05 c0 15  ld  [ %l7 + %l5 ], %o2
a00ed01c:  d6 05 80 15  ld  [ %l6 + %l5 ], %o3
a00ed020:  7f ff cd d5  call  0xa00e0774
a00ed024:  90 10 00 18  mov  %i0, %o0
a00ed028:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00ed02c:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00ed030:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00ed034:  a4 13 63 48  or  %o5, 0x348, %l2
a00ed038:  a6 13 e3 38  or  %o7, 0x338, %l3
a00ed03c:  a2 12 63 28  or  %o1, 0x328, %l1
a00ed040:  d2 04 80 15  ld  [ %l2 + %l5 ], %o1
a00ed044:  d4 04 c0 15  ld  [ %l3 + %l5 ], %o2
a00ed048:  d6 04 40 15  ld  [ %l1 + %l5 ], %o3
a00ed04c:  7f ff cd c2  call  0xa00e0754
a00ed050:  90 10 00 18  mov  %i0, %o0
a00ed054:  98 02 3f ff  add  %o0, -1, %o4
a00ed058:  d6 04 40 15  ld  [ %l1 + %l5 ], %o3
a00ed05c:  d2 04 80 15  ld  [ %l2 + %l5 ], %o1
a00ed060:  d4 04 c0 15  ld  [ %l3 + %l5 ], %o2
a00ed064:  90 10 00 18  mov  %i0, %o0
a00ed068:  7f ff cd c3  call  0xa00e0774
a00ed06c:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00ed070:  aa 14 e3 68  or  %l3, 0x368, %l5	! 0xa8026768
a00ed074:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ed078:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00ed07c:  ac 10 63 58  or  %g1, 0x358, %l6
a00ed080:  ae 13 22 e8  or  %o4, 0x2e8, %l7
a00ed084:  a7 2e e0 02  sll  %i3, 2, %l3
a00ed088:  80 a6 ff ff  cmp  %i3, -1
a00ed08c:  22 80 00 8b  be,a   0xa00ed2b8
a00ed090:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00ed094:  d2 05 40 13  ld  [ %l5 + %l3 ], %o1
a00ed098:  d4 05 80 13  ld  [ %l6 + %l3 ], %o2
a00ed09c:  d6 05 c0 13  ld  [ %l7 + %l3 ], %o3
a00ed0a0:  7f ff cd ad  call  0xa00e0754
a00ed0a4:  90 10 00 18  mov  %i0, %o0
a00ed0a8:  98 02 20 01  add  %o0, 1, %o4
a00ed0ac:  90 10 00 18  mov  %i0, %o0
a00ed0b0:  d2 05 40 13  ld  [ %l5 + %l3 ], %o1
a00ed0b4:  d4 05 80 13  ld  [ %l6 + %l3 ], %o2
a00ed0b8:  7f ff cd af  call  0xa00e0774
a00ed0bc:  d6 05 c0 13  ld  [ %l7 + %l3 ], %o3
a00ed0c0:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00ed0c4:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00ed0c8:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ed0cc:  9e 13 63 18  or  %o5, 0x318, %o7
a00ed0d0:  a4 13 22 d8  or  %o4, 0x2d8, %l2
a00ed0d4:  a2 12 a3 08  or  %o2, 0x308, %l1
a00ed0d8:  d2 03 c0 13  ld  [ %o7 + %l3 ], %o1
a00ed0dc:  d4 04 40 13  ld  [ %l1 + %l3 ], %o2
a00ed0e0:  d6 04 80 13  ld  [ %l2 + %l3 ], %o3
a00ed0e4:  7f ff cd 9c  call  0xa00e0754
a00ed0e8:  90 10 00 18  mov  %i0, %o0
a00ed0ec:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00ed0f0:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ed0f4:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00ed0f8:  a0 12 e3 08  or  %o3, 0x308, %l0
a00ed0fc:  98 02 20 01  add  %o0, 1, %o4
a00ed100:  82 12 63 18  or  %o1, 0x318, %g1
a00ed104:  9e 13 62 d8  or  %o5, 0x2d8, %o7
a00ed108:  90 10 00 18  mov  %i0, %o0
a00ed10c:  d2 00 40 13  ld  [ %g1 + %l3 ], %o1
a00ed110:  d4 04 00 13  ld  [ %l0 + %l3 ], %o2
a00ed114:  d6 03 c0 13  ld  [ %o7 + %l3 ], %o3
a00ed118:  7f ff cd 97  call  0xa00e0774
a00ed11c:  01 00 00 00  nop
a00ed120:  90 10 00 18  mov  %i0, %o0
a00ed124:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a00ed128:  94 10 00 1a  mov  %i2, %o2
a00ed12c:  7f ff dc 53  call  0xa00e4278
a00ed130:  d6 07 a0 58  ld  [ %fp + 0x58 ], %o3
a00ed134:  80 a2 20 01  cmp  %o0, 1
a00ed138:  02 80 00 a3  be  0xa00ed3c4
a00ed13c:  80 a2 20 00  cmp  %o0, 0
a00ed140:  12 bf fe 09  bne  0xa00ec964
a00ed144:  80 a6 ff ff  cmp  %i3, -1
a00ed148:  02 80 00 2f  be  0xa00ed204
a00ed14c:  90 10 00 18  mov  %i0, %o0
a00ed150:  d2 05 40 13  ld  [ %l5 + %l3 ], %o1
a00ed154:  d4 05 80 13  ld  [ %l6 + %l3 ], %o2
a00ed158:  7f ff cd 7f  call  0xa00e0754
a00ed15c:  d6 05 c0 13  ld  [ %l7 + %l3 ], %o3
a00ed160:  80 a2 20 07  cmp  %o0, 7
a00ed164:  32 bf ff ca  bne,a   0xa00ed08c
a00ed168:  80 a6 ff ff  cmp  %i3, -1
a00ed16c:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ed170:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ed174:  94 12 e3 98  or  %o3, 0x398, %o2
a00ed178:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00ed17c:  a4 10 63 78  or  %g1, 0x378, %l2
a00ed180:  a2 14 23 88  or  %l0, 0x388, %l1
a00ed184:  d2 02 80 13  ld  [ %o2 + %l3 ], %o1
a00ed188:  d4 04 40 13  ld  [ %l1 + %l3 ], %o2
a00ed18c:  d6 04 80 13  ld  [ %l2 + %l3 ], %o3
a00ed190:  7f ff cd 71  call  0xa00e0754
a00ed194:  90 10 00 18  mov  %i0, %o0
a00ed198:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00ed19c:  9e 13 63 98  or  %o5, 0x398, %o7	! 0xa8026798
a00ed1a0:  98 02 20 01  add  %o0, 1, %o4
a00ed1a4:  d4 04 40 13  ld  [ %l1 + %l3 ], %o2
a00ed1a8:  d6 04 80 13  ld  [ %l2 + %l3 ], %o3
a00ed1ac:  d2 03 c0 13  ld  [ %o7 + %l3 ], %o1
a00ed1b0:  7f ff cd 71  call  0xa00e0774
a00ed1b4:  90 10 00 18  mov  %i0, %o0
a00ed1b8:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00ed1bc:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00ed1c0:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00ed1c4:  a0 13 23 48  or  %o4, 0x348, %l0
a00ed1c8:  a2 12 63 38  or  %o1, 0x338, %l1
a00ed1cc:  a4 12 23 28  or  %o0, 0x328, %l2
a00ed1d0:  d2 04 00 13  ld  [ %l0 + %l3 ], %o1
a00ed1d4:  d4 04 40 13  ld  [ %l1 + %l3 ], %o2
a00ed1d8:  d6 04 80 13  ld  [ %l2 + %l3 ], %o3
a00ed1dc:  7f ff cd 5e  call  0xa00e0754
a00ed1e0:  90 10 00 18  mov  %i0, %o0
a00ed1e4:  98 02 20 01  add  %o0, 1, %o4
a00ed1e8:  d2 04 00 13  ld  [ %l0 + %l3 ], %o1
a00ed1ec:  d4 04 40 13  ld  [ %l1 + %l3 ], %o2
a00ed1f0:  d6 04 80 13  ld  [ %l2 + %l3 ], %o3
a00ed1f4:  7f ff cd 60  call  0xa00e0774
a00ed1f8:  90 10 00 18  mov  %i0, %o0
a00ed1fc:  10 bf ff a4  b  0xa00ed08c
a00ed200:  80 a6 ff ff  cmp  %i3, -1
a00ed204:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ed208:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ed20c:  94 12 e3 58  or  %o3, 0x358, %o2
a00ed210:  21 2a 00 ad  sethi  %hi(0xa802b400), %l0
a00ed214:  92 10 63 68  or  %g1, 0x368, %o1
a00ed218:  7f ff cd 4f  call  0xa00e0754
a00ed21c:  96 14 22 e8  or  %l0, 0x2e8, %o3
a00ed220:  80 a2 20 07  cmp  %o0, 7
a00ed224:  32 80 00 25  bne,a   0xa00ed2b8
a00ed228:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00ed22c:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00ed230:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00ed234:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00ed238:  96 12 23 78  or  %o0, 0x378, %o3
a00ed23c:  92 13 63 98  or  %o5, 0x398, %o1
a00ed240:  94 13 e3 88  or  %o7, 0x388, %o2
a00ed244:  7f ff cd 44  call  0xa00e0754
a00ed248:  90 10 00 18  mov  %i0, %o0
a00ed24c:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ed250:  98 02 20 01  add  %o0, 1, %o4
a00ed254:  94 12 e3 88  or  %o3, 0x388, %o2
a00ed258:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ed25c:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00ed260:  96 10 63 78  or  %g1, 0x378, %o3
a00ed264:  90 10 00 18  mov  %i0, %o0
a00ed268:  7f ff cd 43  call  0xa00e0774
a00ed26c:  92 14 23 98  or  %l0, 0x398, %o1
a00ed270:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ed274:  92 12 a3 48  or  %o2, 0x348, %o1	! 0xa8026748
a00ed278:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00ed27c:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00ed280:  96 13 23 28  or  %o4, 0x328, %o3
a00ed284:  94 14 63 38  or  %l1, 0x338, %o2
a00ed288:  7f ff cd 33  call  0xa00e0754
a00ed28c:  90 10 00 18  mov  %i0, %o0
a00ed290:  98 02 20 01  add  %o0, 1, %o4
a00ed294:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00ed298:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00ed29c:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00ed2a0:  90 10 00 18  mov  %i0, %o0
a00ed2a4:  92 14 a3 48  or  %l2, 0x348, %o1
a00ed2a8:  96 13 e3 28  or  %o7, 0x328, %o3
a00ed2ac:  7f ff cd 32  call  0xa00e0774
a00ed2b0:  94 13 63 38  or  %o5, 0x338, %o2
a00ed2b4:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00ed2b8:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00ed2bc:  96 12 22 e8  or  %o0, 0x2e8, %o3
a00ed2c0:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00ed2c4:  92 14 63 68  or  %l1, 0x368, %o1	! 0xa8026768
a00ed2c8:  94 13 23 58  or  %o4, 0x358, %o2
a00ed2cc:  7f ff cd 22  call  0xa00e0754
a00ed2d0:  90 10 00 18  mov  %i0, %o0
a00ed2d4:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ed2d8:  98 02 20 01  add  %o0, 1, %o4
a00ed2dc:  92 12 a3 68  or  %o2, 0x368, %o1
a00ed2e0:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00ed2e4:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00ed2e8:  94 14 a3 58  or  %l2, 0x358, %o2	! 0xa8026758
a00ed2ec:  96 10 62 e8  or  %g1, 0x2e8, %o3
a00ed2f0:  7f ff cd 21  call  0xa00e0774
a00ed2f4:  90 10 00 18  mov  %i0, %o0
a00ed2f8:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ed2fc:  92 12 e3 18  or  %o3, 0x318, %o1	! 0xa8026718
a00ed300:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00ed304:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00ed308:  94 14 23 08  or  %l0, 0x308, %o2	! 0xa8026708
a00ed30c:  96 13 62 d8  or  %o5, 0x2d8, %o3
a00ed310:  7f ff cd 11  call  0xa00e0754
a00ed314:  90 10 00 18  mov  %i0, %o0
a00ed318:  98 02 20 01  add  %o0, 1, %o4
a00ed31c:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00ed320:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00ed324:  25 2a 00 ad  sethi  %hi(0xa802b400), %l2
a00ed328:  90 10 00 18  mov  %i0, %o0
a00ed32c:  92 13 e3 18  or  %o7, 0x318, %o1
a00ed330:  94 14 63 08  or  %l1, 0x308, %o2
a00ed334:  10 bf ff 79  b  0xa00ed118
a00ed338:  96 14 a2 d8  or  %l2, 0x2d8, %o3
a00ed33c:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00ed340:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ed344:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00ed348:  96 12 23 78  or  %o0, 0x378, %o3
a00ed34c:  92 10 63 98  or  %g1, 0x398, %o1
a00ed350:  94 13 23 88  or  %o4, 0x388, %o2
a00ed354:  7f ff cd 00  call  0xa00e0754
a00ed358:  90 10 00 18  mov  %i0, %o0
a00ed35c:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ed360:  92 12 a3 98  or  %o2, 0x398, %o1	! 0xa8026798
a00ed364:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ed368:  98 02 3f ff  add  %o0, -1, %o4
a00ed36c:  94 12 e3 88  or  %o3, 0x388, %o2
a00ed370:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00ed374:  90 10 00 18  mov  %i0, %o0
a00ed378:  7f ff cc ff  call  0xa00e0774
a00ed37c:  96 14 23 78  or  %l0, 0x378, %o3
a00ed380:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00ed384:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00ed388:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00ed38c:  92 15 e3 48  or  %l7, 0x348, %o1
a00ed390:  94 15 a3 38  or  %l6, 0x338, %o2
a00ed394:  96 14 a3 28  or  %l2, 0x328, %o3
a00ed398:  7f ff cc ef  call  0xa00e0754
a00ed39c:  90 10 00 18  mov  %i0, %o0
a00ed3a0:  98 02 3f ff  add  %o0, -1, %o4
a00ed3a4:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00ed3a8:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00ed3ac:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00ed3b0:  90 10 00 18  mov  %i0, %o0
a00ed3b4:  92 14 e3 48  or  %l3, 0x348, %o1
a00ed3b8:  94 15 63 38  or  %l5, 0x338, %o2
a00ed3bc:  10 bf ff 2b  b  0xa00ed068
a00ed3c0:  96 14 63 28  or  %l1, 0x328, %o3
a00ed3c4:  80 a6 ff ff  cmp  %i3, -1
a00ed3c8:  02 80 00 35  be  0xa00ed49c
a00ed3cc:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00ed3d0:  2b 2a 00 9a  sethi  %hi(0xa8026800), %l5
a00ed3d4:  ae 15 60 c8  or  %l5, 0xc8, %l7	! 0xa80268c8
a00ed3d8:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00ed3dc:  ab 2e e0 02  sll  %i3, 2, %l5
a00ed3e0:  a6 13 20 d8  or  %o4, 0xd8, %l3
a00ed3e4:  a4 14 60 e8  or  %l1, 0xe8, %l2
a00ed3e8:  d2 04 80 15  ld  [ %l2 + %l5 ], %o1
a00ed3ec:  d4 04 c0 15  ld  [ %l3 + %l5 ], %o2
a00ed3f0:  d6 05 c0 15  ld  [ %l7 + %l5 ], %o3
a00ed3f4:  7f ff cc d8  call  0xa00e0754
a00ed3f8:  90 10 00 18  mov  %i0, %o0
a00ed3fc:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ed400:  2d 2a 00 9a  sethi  %hi(0xa8026800), %l6
a00ed404:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ed408:  90 12 e0 98  or  %o3, 0x98, %o0
a00ed40c:  9a 15 a0 b8  or  %l6, 0xb8, %o5
a00ed410:  9e 12 60 a8  or  %o1, 0xa8, %o7
a00ed414:  d6 02 00 15  ld  [ %o0 + %l5 ], %o3
a00ed418:  d2 03 40 15  ld  [ %o5 + %l5 ], %o1
a00ed41c:  d4 03 c0 15  ld  [ %o7 + %l5 ], %o2
a00ed420:  7f ff cc cd  call  0xa00e0754
a00ed424:  90 10 00 18  mov  %i0, %o0
a00ed428:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ed42c:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ed430:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00ed434:  a2 14 23 98  or  %l0, 0x398, %l1	! 0xa8026798
a00ed438:  98 12 a3 88  or  %o2, 0x388, %o4
a00ed43c:  a4 10 63 78  or  %g1, 0x378, %l2
a00ed440:  d2 04 40 15  ld  [ %l1 + %l5 ], %o1
a00ed444:  d4 03 00 15  ld  [ %o4 + %l5 ], %o2
a00ed448:  d6 04 80 15  ld  [ %l2 + %l5 ], %o3
a00ed44c:  7f ff cc c2  call  0xa00e0754
a00ed450:  90 10 00 18  mov  %i0, %o0
a00ed454:  2d 2a 00 ad  sethi  %hi(0xa802b400), %l6
a00ed458:  92 15 a2 e8  or  %l6, 0x2e8, %o1	! 0xa802b6e8
a00ed45c:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00ed460:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00ed464:  a2 10 00 08  mov  %o0, %l1
a00ed468:  9a 14 e3 68  or  %l3, 0x368, %o5
a00ed46c:  9e 15 e3 58  or  %l7, 0x358, %o7
a00ed470:  d6 02 40 15  ld  [ %o1 + %l5 ], %o3
a00ed474:  d2 03 40 15  ld  [ %o5 + %l5 ], %o1
a00ed478:  d4 03 c0 15  ld  [ %o7 + %l5 ], %o2
a00ed47c:  90 10 00 18  mov  %i0, %o0
a00ed480:  7f ff cc b5  call  0xa00e0754
a00ed484:  01 00 00 00  nop
a00ed488:  95 2c 60 03  sll  %l1, 3, %o2
a00ed48c:  83 2d 20 08  sll  %l4, 8, %g1
a00ed490:  a8 10 40 0a  or  %g1, %o2, %l4
a00ed494:  10 bf fd 3b  b  0xa00ec980
a00ed498:  a2 15 00 08  or  %l4, %o0, %l1
a00ed49c:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00ed4a0:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ed4a4:  92 12 20 e8  or  %o0, 0xe8, %o1
a00ed4a8:  94 12 e0 d8  or  %o3, 0xd8, %o2
a00ed4ac:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00ed4b0:  96 14 20 c8  or  %l0, 0xc8, %o3	! 0xa80268c8
a00ed4b4:  7f ff cc a8  call  0xa00e0754
a00ed4b8:  90 10 00 18  mov  %i0, %o0
a00ed4bc:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ed4c0:  92 12 a0 b8  or  %o2, 0xb8, %o1	! 0xa80268b8
a00ed4c4:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00ed4c8:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00ed4cc:  94 10 60 a8  or  %g1, 0xa8, %o2
a00ed4d0:  96 14 60 98  or  %l1, 0x98, %o3
a00ed4d4:  7f ff cc a0  call  0xa00e0754
a00ed4d8:  90 10 00 18  mov  %i0, %o0
a00ed4dc:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00ed4e0:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00ed4e4:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00ed4e8:  92 13 23 98  or  %o4, 0x398, %o1
a00ed4ec:  94 14 a3 88  or  %l2, 0x388, %o2
a00ed4f0:  96 14 e3 78  or  %l3, 0x378, %o3
a00ed4f4:  7f ff cc 98  call  0xa00e0754
a00ed4f8:  90 10 00 18  mov  %i0, %o0
a00ed4fc:  a2 10 00 08  mov  %o0, %l1
a00ed500:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00ed504:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00ed508:  2b 2a 00 ad  sethi  %hi(0xa802b400), %l5
a00ed50c:  90 10 00 18  mov  %i0, %o0
a00ed510:  92 15 e3 68  or  %l7, 0x368, %o1
a00ed514:  94 15 a3 58  or  %l6, 0x358, %o2
a00ed518:  10 bf ff da  b  0xa00ed480
a00ed51c:  96 15 62 e8  or  %l5, 0x2e8, %o3
a00ed520:  81 c7 e0 0c  jmp  %i7 + 0xc
a00ed524:  91 e8 00 1d  restore  %g0, %i5, %o0
