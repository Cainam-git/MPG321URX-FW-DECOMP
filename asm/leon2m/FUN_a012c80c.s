# leon2m FUN_a012c80c 0xa012c80c-0xa012ccf0 (1252 bytes)
a012c80c:  9d e3 bf 48  save  %sp, -184, %sp
a012c810:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a012c814:  92 14 21 a0  or  %l0, 0x1a0, %o1	! 0xa802e1a0
a012c818:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012c81c:  90 06 00 09  add  %i0, %o1, %o0
a012c820:  d2 0a 20 1b  ldub  [ %o0 + 0x1b ], %o1
a012c824:  9a 1a 60 ff  xor  %o1, 0xff, %o5
a012c828:  80 a0 00 0d  cmp  %g0, %o5
a012c82c:  96 60 3f ff  subx  %g0, -1, %o3
a012c830:  b8 0f 20 ff  and  %i4, 0xff, %i4
a012c834:  80 a0 00 1c  cmp  %g0, %i4
a012c838:  82 40 20 00  addx  %g0, 0, %g1
a012c83c:  98 10 20 00  clr  %o4
a012c840:  9a 10 20 00  clr  %o5
a012c844:  80 92 c0 01  orcc  %o3, %g1, %g0
a012c848:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a012c84c:  a6 10 00 1b  mov  %i3, %l3
a012c850:  c0 37 bf e0  clrh  [ %fp + -32 ]
a012c854:  a8 10 20 00  clr  %l4
a012c858:  a2 10 20 00  clr  %l1
a012c85c:  12 80 00 0a  bne  0xa012c884
a012c860:  aa 10 20 00  clr  %l5
a012c864:  35 2a 00 b3  sethi  %hi(0xa802cc00), %i2
a012c868:  a6 16 a0 10  or  %i2, 0x10, %l3	! 0xa802cc10
a012c86c:  a5 2a 60 02  sll  %o1, 2, %l2
a012c870:  1f 00 06 9a  sethi  %hi(0x1a6800), %o7
a012c874:  94 02 40 09  add  %o1, %o1, %o2
a012c878:  f4 04 c0 12  ld  [ %l3 + %l2 ], %i2
a012c87c:  98 13 e2 d8  or  %o7, 0x2d8, %o4
a012c880:  e6 13 00 0a  lduh  [ %o4 + %o2 ], %l3
a012c884:  7f ff e3 47  call  0xa01255a0
a012c888:  90 10 00 18  mov  %i0, %o0
a012c88c:  b7 2c e0 10  sll  %l3, 0x10, %i3
a012c890:  83 2a 20 10  sll  %o0, 0x10, %g1
a012c894:  80 a6 c0 01  cmp  %i3, %g1
a012c898:  08 80 00 11  bleu  0xa012c8dc
a012c89c:  a5 36 e0 10  srl  %i3, 0x10, %l2
a012c8a0:  7f ff e3 40  call  0xa01255a0
a012c8a4:  90 10 00 18  mov  %i0, %o0
a012c8a8:  aa 14 21 a0  or  %l0, 0x1a0, %l5
a012c8ac:  a3 2a 20 10  sll  %o0, 0x10, %l1
a012c8b0:  a0 06 00 15  add  %i0, %l5, %l0
a012c8b4:  29 00 06 93  sethi  %hi(0x1a4c00), %l4
a012c8b8:  90 15 23 08  or  %l4, 0x308, %o0	! 0x1a4f08
a012c8bc:  92 10 00 18  mov  %i0, %o1
a012c8c0:  95 34 60 10  srl  %l1, 0x10, %o2
a012c8c4:  d6 0c 20 1b  ldub  [ %l0 + 0x1b ], %o3
a012c8c8:  7f fe ca 2a  call  0xa00df170
a012c8cc:  98 10 00 12  mov  %l2, %o4
a012c8d0:  01 00 00 00  nop
a012c8d4:  01 00 00 00  nop
a012c8d8:  30 bf ff fe  b,a   0xa012c8d0
a012c8dc:  7f ff e2 a4  call  0xa012536c
a012c8e0:  90 10 00 18  mov  %i0, %o0
a012c8e4:  80 8a 20 ff  btst  0xff, %o0
a012c8e8:  22 80 00 4b  be,a   0xa012ca14
a012c8ec:  b8 10 20 01  mov  1, %i4
a012c8f0:  7f ff e2 a4  call  0xa0125380
a012c8f4:  90 10 00 18  mov  %i0, %o0
a012c8f8:  80 a7 20 00  cmp  %i4, 0
a012c8fc:  02 80 00 d8  be  0xa012cc5c
a012c900:  a0 10 00 08  mov  %o0, %l0
a012c904:  80 8e 60 0f  btst  0xf, %i1
a012c908:  12 80 00 11  bne  0xa012c94c
a012c90c:  96 0e 7f f0  and  %i1, -16, %o3
a012c910:  b7 36 e0 10  srl  %i3, 0x10, %i3
a012c914:  80 a6 e0 00  cmp  %i3, 0
a012c918:  02 80 00 f3  be  0xa012cce4
a012c91c:  a8 04 00 19  add  %l0, %i1, %l4
a012c920:  92 10 00 1b  mov  %i3, %o1
a012c924:  90 10 20 01  mov  1, %o0
a012c928:  40 00 23 75  call  0xa01356fc
a012c92c:  a1 2d 60 10  sll  %l5, 0x10, %l0
a012c930:  b3 2d 20 10  sll  %l4, 0x10, %i1
a012c934:  a7 34 20 10  srl  %l0, 0x10, %l3
a012c938:  94 04 c0 1a  add  %l3, %i2, %o2
a012c93c:  91 36 60 10  srl  %i1, 0x10, %o0
a012c940:  40 00 28 34  call  0xa0136a10
a012c944:  92 10 00 1b  mov  %i3, %o1
a012c948:  30 80 00 e7  b,a   0xa012cce4
a012c94c:  b8 02 c0 10  add  %o3, %l0, %i4
a012c950:  9b 2f 20 10  sll  %i4, 0x10, %o5
a012c954:  b8 07 bf e8  add  %fp, -24, %i4
a012c958:  92 10 20 10  mov  0x10, %o1
a012c95c:  94 10 00 1c  mov  %i4, %o2
a012c960:  91 33 60 10  srl  %o5, 0x10, %o0
a012c964:  40 00 23 32  call  0xa013562c
a012c968:  a8 10 00 0b  mov  %o3, %l4
a012c96c:  94 0e 60 0f  and  %i1, 0xf, %o2
a012c970:  b0 10 20 10  mov  0x10, %i0
a012c974:  82 26 00 0a  sub  %i0, %o2, %g1
a012c978:  80 a4 80 01  cmp  %l2, %g1
a012c97c:  04 80 00 03  ble  0xa012c988
a012c980:  92 10 00 12  mov  %l2, %o1
a012c984:  92 10 00 01  mov  %g1, %o1
a012c988:  9b 2a 60 10  sll  %o1, 0x10, %o5
a012c98c:  aa 10 00 09  mov  %o1, %l5
a012c990:  99 33 60 10  srl  %o5, 0x10, %o4
a012c994:  80 a3 20 00  cmp  %o4, 0
a012c998:  96 10 20 00  clr  %o3
a012c99c:  02 80 00 0e  be  0xa012c9d4
a012c9a0:  a3 2d 60 10  sll  %l5, 0x10, %l1
a012c9a4:  90 07 bf f8  add  %fp, -8, %o0
a012c9a8:  92 02 00 0a  add  %o0, %o2, %o1
a012c9ac:  a2 10 00 0d  mov  %o5, %l1
a012c9b0:  94 10 00 0c  mov  %o4, %o2
a012c9b4:  82 0a e0 ff  and  %o3, 0xff, %g1
a012c9b8:  96 02 e0 01  inc  %o3
a012c9bc:  d8 08 40 1a  ldub  [ %g1 + %i2 ], %o4
a012c9c0:  a4 02 40 01  add  %o1, %g1, %l2
a012c9c4:  9e 0a e0 ff  and  %o3, 0xff, %o7
a012c9c8:  80 a3 c0 0a  cmp  %o7, %o2
a012c9cc:  0a bf ff fa  bcs  0xa012c9b4
a012c9d0:  d8 2c bf f0  stb  %o4, [ %l2 + -16 ]
a012c9d4:  90 10 20 01  mov  1, %o0
a012c9d8:  40 00 23 49  call  0xa01356fc
a012c9dc:  92 10 20 10  mov  0x10, %o1
a012c9e0:  94 04 00 14  add  %l0, %l4, %o2
a012c9e4:  93 2a a0 10  sll  %o2, 0x10, %o1
a012c9e8:  91 32 60 10  srl  %o1, 0x10, %o0
a012c9ec:  94 10 00 1c  mov  %i4, %o2
a012c9f0:  40 00 28 08  call  0xa0136a10
a012c9f4:  92 10 20 10  mov  0x10, %o1
a012c9f8:  80 a6 c0 11  cmp  %i3, %l1
a012c9fc:  28 bf ff c5  bleu,a   0xa012c910
a012ca00:  b6 10 20 00  clr  %i3
a012ca04:  a2 24 c0 15  sub  %l3, %l5, %l1
a012ca08:  b2 05 20 10  add  %l4, 0x10, %i1
a012ca0c:  10 bf ff c1  b  0xa012c910
a012ca10:  b7 2c 60 10  sll  %l1, 0x10, %i3
a012ca14:  83 2f 00 18  sll  %i4, %i0, %g1
a012ca18:  40 00 1d 10  call  0xa0133e58
a012ca1c:  90 08 60 ff  and  %g1, 0xff, %o0
a012ca20:  7f ff e1 51  call  0xa0124f64
a012ca24:  90 10 00 18  mov  %i0, %o0
a012ca28:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a012ca2c:  7f ff e1 54  call  0xa0124f7c
a012ca30:  90 10 00 18  mov  %i0, %o0
a012ca34:  d0 2f bf d9  stb  %o0, [ %fp + -39 ]
a012ca38:  7f ff e1 58  call  0xa0124f98
a012ca3c:  90 10 00 18  mov  %i0, %o0
a012ca40:  d0 2f bf da  stb  %o0, [ %fp + -38 ]
a012ca44:  7f ff e1 5c  call  0xa0124fb4
a012ca48:  90 10 00 18  mov  %i0, %o0
a012ca4c:  d4 07 bf e0  ld  [ %fp + -32 ], %o2
a012ca50:  1f 10 00 00  sethi  %hi(0x40000000), %o7
a012ca54:  d0 2f bf db  stb  %o0, [ %fp + -37 ]
a012ca58:  96 2a 80 0f  andn  %o2, %o7, %o3
a012ca5c:  11 20 00 00  sethi  %hi(0x80000000), %o0
a012ca60:  b6 12 c0 08  or  %o3, %o0, %i3
a012ca64:  9a 10 3f a0  mov  -96, %o5
a012ca68:  aa 10 20 04  mov  4, %l5
a012ca6c:  da 2f bf de  stb  %o5, [ %fp + -34 ]
a012ca70:  f6 27 bf e0  st  %i3, [ %fp + -32 ]
a012ca74:  f8 2f bf df  stb  %i4, [ %fp + -33 ]
a012ca78:  ea 37 bf dc  sth  %l5, [ %fp + -36 ]
a012ca7c:  7f ff e2 c9  call  0xa01255a0
a012ca80:  90 10 00 18  mov  %i0, %o0
a012ca84:  a1 2a 20 10  sll  %o0, 0x10, %l0
a012ca88:  a3 34 20 10  srl  %l0, 0x10, %l1
a012ca8c:  80 a4 61 00  cmp  %l1, 0x100
a012ca90:  38 80 00 02  bgu,a   0xa012ca98
a012ca94:  a8 10 20 01  mov  1, %l4
a012ca98:  7f ff e2 98  call  0xa01254f8
a012ca9c:  90 10 00 18  mov  %i0, %o0
a012caa0:  a2 0a 20 ff  and  %o0, 0xff, %l1
a012caa4:  7f ff e2 a3  call  0xa0125530
a012caa8:  90 10 00 18  mov  %i0, %o0
a012caac:  a0 0a 20 ff  and  %o0, 0xff, %l0
a012cab0:  7f ff e2 ae  call  0xa0125568
a012cab4:  90 10 00 18  mov  %i0, %o0
a012cab8:  98 38 00 08  xnor  %g0, %o0, %o4
a012cabc:  90 10 00 11  mov  %l1, %o0
a012cac0:  92 10 00 10  mov  %l0, %o1
a012cac4:  67 fd 7f 6a  call  0x4008c86c
a012cac8:  94 0b 20 ff  and  %o4, 0xff, %o2
a012cacc:  b6 10 00 13  mov  %l3, %i3
a012cad0:  80 a4 a0 00  cmp  %l2, 0
a012cad4:  02 80 00 40  be  0xa012cbd4
a012cad8:  a6 10 20 00  clr  %l3
a012cadc:  a4 0d 20 ff  and  %l4, 0xff, %l2
a012cae0:  a3 2e e0 10  sll  %i3, 0x10, %l1
a012cae4:  80 a4 a0 00  cmp  %l2, 0
a012cae8:  02 80 00 11  be  0xa012cb2c
a012caec:  a1 2e 60 10  sll  %i1, 0x10, %l0
a012caf0:  aa 10 20 60  mov  0x60, %l5
a012caf4:  ea 2f bf de  stb  %l5, [ %fp + -34 ]
a012caf8:  d8 1f bf d8  ldd  [ %fp + -40 ], %o4
a012cafc:  d2 17 bf e0  lduh  [ %fp + -32 ], %o1
a012cb00:  d8 3f bf c8  std  %o4, [ %fp + -56 ]
a012cb04:  d2 37 bf d0  sth  %o1, [ %fp + -48 ]
a012cb08:  90 07 bf c8  add  %fp, -56, %o0
a012cb0c:  93 34 20 18  srl  %l0, 0x18, %o1
a012cb10:  94 10 20 00  clr  %o2
a012cb14:  96 10 20 00  clr  %o3
a012cb18:  98 10 20 01  mov  1, %o4
a012cb1c:  67 fd 7a 32  call  0x4008b3e4
a012cb20:  9a 10 20 00  clr  %o5
a012cb24:  a8 10 3f a0  mov  -96, %l4
a012cb28:  e8 2f bf de  stb  %l4, [ %fp + -34 ]
a012cb2c:  95 34 60 10  srl  %l1, 0x10, %o2
a012cb30:  80 a2 a0 08  cmp  %o2, 8
a012cb34:  08 80 00 3c  bleu  0xa012cc24
a012cb38:  99 2c e0 10  sll  %l3, 0x10, %o4
a012cb3c:  d8 1f bf d8  ldd  [ %fp + -40 ], %o4
a012cb40:  d8 3f bf b8  std  %o4, [ %fp + -72 ]
a012cb44:  97 2c e0 10  sll  %l3, 0x10, %o3
a012cb48:  da 17 bf e0  lduh  [ %fp + -32 ], %o5
a012cb4c:  91 34 20 10  srl  %l0, 0x10, %o0
a012cb50:  da 37 bf c0  sth  %o5, [ %fp + -64 ]
a012cb54:  92 0a 20 ff  and  %o0, 0xff, %o1
a012cb58:  b9 32 e0 10  srl  %o3, 0x10, %i4
a012cb5c:  96 07 00 1a  add  %i4, %i2, %o3
a012cb60:  90 07 bf b8  add  %fp, -72, %o0
a012cb64:  94 10 20 08  mov  8, %o2
a012cb68:  98 10 20 01  mov  1, %o4
a012cb6c:  67 fd 7a 1e  call  0x4008b3e4
a012cb70:  9a 10 20 01  mov  1, %o5
a012cb74:  b6 06 ff f8  add  %i3, -8, %i3
a012cb78:  b2 06 60 08  add  %i1, 8, %i1
a012cb7c:  a6 04 e0 08  add  %l3, 8, %l3
a012cb80:  67 fd 82 82  call  0x4008d588
a012cb84:  01 00 00 00  nop
a012cb88:  a1 2a 20 10  sll  %o0, 0x10, %l0
a012cb8c:  67 fd 81 85  call  0x4008d1a0
a012cb90:  90 10 20 02  mov  2, %o0
a012cb94:  67 fd 7c ba  call  0x4008be7c
a012cb98:  d0 0f bf de  ldub  [ %fp + -34 ], %o0
a012cb9c:  80 8a 20 ff  btst  0xff, %o0
a012cba0:  12 80 00 09  bne  0xa012cbc4
a012cba4:  91 34 20 10  srl  %l0, 0x10, %o0
a012cba8:  67 fd 82 7b  call  0x4008d594
a012cbac:  01 00 00 00  nop
a012cbb0:  a3 2a 20 10  sll  %o0, 0x10, %l1
a012cbb4:  95 34 60 10  srl  %l1, 0x10, %o2
a012cbb8:  80 a2 a0 13  cmp  %o2, 0x13
a012cbbc:  08 bf ff f4  bleu  0xa012cb8c
a012cbc0:  01 00 00 00  nop
a012cbc4:  a3 2e e0 10  sll  %i3, 0x10, %l1
a012cbc8:  80 a4 60 00  cmp  %l1, 0
a012cbcc:  12 bf ff c7  bne  0xa012cae8
a012cbd0:  80 a4 a0 00  cmp  %l2, 0
a012cbd4:  7f ff e2 49  call  0xa01254f8
a012cbd8:  90 10 00 18  mov  %i0, %o0
a012cbdc:  a6 0a 20 ff  and  %o0, 0xff, %l3
a012cbe0:  7f ff e2 54  call  0xa0125530
a012cbe4:  90 10 00 18  mov  %i0, %o0
a012cbe8:  b4 0a 20 ff  and  %o0, 0xff, %i2
a012cbec:  7f ff e2 5f  call  0xa0125568
a012cbf0:  90 10 00 18  mov  %i0, %o0
a012cbf4:  94 0a 20 ff  and  %o0, 0xff, %o2
a012cbf8:  92 10 00 1a  mov  %i2, %o1
a012cbfc:  67 fd 7f 1c  call  0x4008c86c
a012cc00:  90 10 00 13  mov  %l3, %o0
a012cc04:  7f ff dd f1  call  0xa01243c8
a012cc08:  90 10 00 18  mov  %i0, %o0
a012cc0c:  b2 10 20 01  mov  1, %i1
a012cc10:  a5 2e 40 18  sll  %i1, %i0, %l2
a012cc14:  92 0a 20 ff  and  %o0, 0xff, %o1
a012cc18:  40 00 1c 99  call  0xa0133e7c
a012cc1c:  90 0c a0 ff  and  %l2, 0xff, %o0
a012cc20:  30 80 00 31  b,a   0xa012cce4
a012cc24:  b7 33 20 10  srl  %o4, 0x10, %i3
a012cc28:  d8 1f bf d8  ldd  [ %fp + -40 ], %o4
a012cc2c:  d8 3f bf a8  std  %o4, [ %fp + -88 ]
a012cc30:  9f 34 20 10  srl  %l0, 0x10, %o7
a012cc34:  c2 17 bf e0  lduh  [ %fp + -32 ], %g1
a012cc38:  96 06 c0 1a  add  %i3, %i2, %o3
a012cc3c:  c2 37 bf b0  sth  %g1, [ %fp + -80 ]
a012cc40:  92 0b e0 ff  and  %o7, 0xff, %o1
a012cc44:  90 07 bf a8  add  %fp, -88, %o0
a012cc48:  98 10 20 01  mov  1, %o4
a012cc4c:  67 fd 79 e6  call  0x4008b3e4
a012cc50:  9a 10 20 01  mov  1, %o5
a012cc54:  10 bf ff cb  b  0xa012cb80
a012cc58:  b6 10 20 00  clr  %i3
a012cc5c:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a012cc60:  93 2e 20 02  sll  %i0, 2, %o1
a012cc64:  d8 02 e3 08  ld  [ %o3 + 0x308 ], %o4
a012cc68:  b9 33 00 09  srl  %o4, %o1, %i4
a012cc6c:  9a 0f 20 0f  and  %i4, 0xf, %o5
a012cc70:  ab 2b 60 07  sll  %o5, 7, %l5
a012cc74:  80 a4 80 15  cmp  %l2, %l5
a012cc78:  32 80 00 02  bne,a   0xa012cc80
a012cc7c:  a2 10 20 01  mov  1, %l1
a012cc80:  a8 10 20 0f  mov  0xf, %l4
a012cc84:  83 36 e0 17  srl  %i3, 0x17, %g1
a012cc88:  a7 2d 00 09  sll  %l4, %o1, %l3
a012cc8c:  94 2b 00 13  andn  %o4, %l3, %o2
a012cc90:  9f 28 40 09  sll  %g1, %o1, %o7
a012cc94:  90 13 c0 0a  or  %o7, %o2, %o0
a012cc98:  d0 22 e3 08  st  %o0, [ %o3 + 0x308 ]
a012cc9c:  90 10 20 01  mov  1, %o0
a012cca0:  40 00 22 97  call  0xa01356fc
a012cca4:  92 10 00 12  mov  %l2, %o1
a012cca8:  96 04 00 19  add  %l0, %i1, %o3
a012ccac:  b7 2a e0 10  sll  %o3, 0x10, %i3
a012ccb0:  91 36 e0 10  srl  %i3, 0x10, %o0
a012ccb4:  94 10 00 1a  mov  %i2, %o2
a012ccb8:  40 00 27 56  call  0xa0136a10
a012ccbc:  92 10 00 12  mov  %l2, %o1
a012ccc0:  80 8c 60 ff  btst  0xff, %l1
a012ccc4:  02 80 00 08  be  0xa012cce4
a012ccc8:  92 10 20 01  mov  1, %o1
a012cccc:  99 2a 40 18  sll  %o1, %i0, %o4
a012ccd0:  b5 34 20 07  srl  %l0, 7, %i2
a012ccd4:  90 0b 20 ff  and  %o4, 0xff, %o0
a012ccd8:  92 10 00 12  mov  %l2, %o1
a012ccdc:  40 00 1c b8  call  0xa0133fbc
a012cce0:  94 0e a0 ff  and  %i2, 0xff, %o2
a012cce4:  01 00 00 00  nop
a012cce8:  81 c7 e0 08  ret
a012ccec:  81 e8 00 00  restore
