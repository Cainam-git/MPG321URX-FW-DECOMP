# leon2m FUN_a014c7bc 0xa014c7bc-0xa014ce84 (72 bytes)
a014c7bc:  9d e3 bf 98  save  %sp, -104, %sp
a014c7c0:  f2 27 a0 48  st  %i1, [ %fp + 0x48 ]
a014c7c4:  f4 27 a0 4c  st  %i2, [ %fp + 0x4c ]
a014c7c8:  f6 27 a0 50  st  %i3, [ %fp + 0x50 ]
a014c7cc:  f8 27 a0 54  st  %i4, [ %fp + 0x54 ]
a014c7d0:  fa 27 a0 58  st  %i5, [ %fp + 0x58 ]
a014c7d4:  80 a6 20 20  cmp  %i0, 0x20
a014c7d8:  18 80 01 a8  bgu  0xa014ce78
a014c7dc:  90 07 a0 48  add  %fp, 0x48, %o0
a014c7e0:  13 00 03 8d  sethi  %hi(0xe3400), %o1
a014c7e4:  83 2e 20 02  sll  %i0, 2, %g1
a014c7e8:  9a 12 61 a4  or  %o1, 0x1a4, %o5
a014c7ec:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a014c7f0:  81 c3 00 00  jmp  %o4
a014c7f4:  01 00 00 00  nop
a014c7f8:  c2 0a 20 03  ldub  [ %o0 + 3 ], %g1
a014c7fc:  80 a0 60 01  cmp  %g1, 1
a014c800:  02 80 01 91  be  0xa014ce44
a014c804:  d8 02 20 04  ld  [ %o0 + 4 ], %o4
a014c808:  80 a0 60 01  cmp  %g1, 1
a014c80c:  04 80 01 6f  ble  0xa014cdc8
a014c810:  80 a0 60 02  cmp  %g1, 2
a014c814:  12 80 01 99  bne  0xa014ce78
a014c818:  b8 0b 20 ff  and  %o4, 0xff, %i4
a014c81c:  b6 5f 20 c8  smul  %i4, 0xc8, %i3
a014c820:  35 14 7a e1  sethi  %hi(0x51eb8400), %i2
a014c824:  90 06 e0 32  add  %i3, 0x32, %o0
a014c828:  b2 16 a1 1f  or  %i2, 0x11f, %i1
a014c82c:  80 52 00 19  umul  %o0, %i1, %g0
a014c830:  b1 40 00 00  rd  %y, %i0
a014c834:  97 36 20 05  srl  %i0, 5, %o3
a014c838:  9e 02 e0 1c  add  %o3, 0x1c, %o7
a014c83c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014c840:  90 0b e0 ff  and  %o7, 0xff, %o0
a014c844:  7f ff bb 40  call  0xa013b544
a014c848:  d8 28 63 e1  stb  %o4, [ %g1 + 0x3e1 ]
a014c84c:  30 80 01 8b  b,a   0xa014ce78
a014c850:  d0 02 00 00  ld  [ %o0 ], %o0
a014c854:  17 2a 00 b9  sethi  %hi(0xa802e400), %o3
a014c858:  80 a2 20 00  cmp  %o0, 0
a014c85c:  02 80 01 41  be  0xa014cd60
a014c860:  d0 22 e0 08  st  %o0, [ %o3 + 8 ]
a014c864:  80 a2 20 01  cmp  %o0, 1
a014c868:  02 80 01 3e  be  0xa014cd60
a014c86c:  80 a2 20 02  cmp  %o0, 2
a014c870:  02 80 00 04  be  0xa014c880
a014c874:  80 a2 20 03  cmp  %o0, 3
a014c878:  12 80 01 80  bne  0xa014ce78
a014c87c:  01 00 00 00  nop
a014c880:  90 10 20 01  mov  1, %o0	! 0x1
a014c884:  40 00 0e 27  call  0xa0150120
a014c888:  92 10 20 01  mov  1, %o1
a014c88c:  30 80 01 7b  b,a   0xa014ce78
a014c890:  c2 02 00 00  ld  [ %o0 ], %g1
a014c894:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a014c898:  10 80 01 78  b  0xa014ce78
a014c89c:  c2 2b e3 fe  stb  %g1, [ %o7 + 0x3fe ]	! 0xa802e3fe
a014c8a0:  d2 02 00 00  ld  [ %o0 ], %o1
a014c8a4:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a014c8a8:  a0 13 63 d0  or  %o5, 0x3d0, %l0	! 0xa802e3d0
a014c8ac:  94 0a 60 ff  and  %o1, 0xff, %o2
a014c8b0:  80 a2 a0 05  cmp  %o2, 5
a014c8b4:  02 80 01 31  be  0xa014cd78
a014c8b8:  d2 2c 20 1c  stb  %o1, [ %l0 + 0x1c ]
a014c8bc:  7f ff 2f 28  call  0xa011855c
a014c8c0:  01 00 00 00  nop
a014c8c4:  7f ff d2 12  call  0xa014110c
a014c8c8:  d0 0c 20 1c  ldub  [ %l0 + 0x1c ], %o0
a014c8cc:  30 80 01 6b  b,a   0xa014ce78
a014c8d0:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a014c8d4:  d8 02 00 00  ld  [ %o0 ], %o4
a014c8d8:  ba 14 23 d0  or  %l0, 0x3d0, %i5
a014c8dc:  90 0b 20 ff  and  %o4, 0xff, %o0
a014c8e0:  7f ff 89 74  call  0xa012eeb0
a014c8e4:  d8 2f 60 18  stb  %o4, [ %i5 + 0x18 ]
a014c8e8:  7f ff fe 0c  call  0xa014c118
a014c8ec:  d0 0f 60 0b  ldub  [ %i5 + 0xb ], %o0
a014c8f0:  30 80 01 62  b,a   0xa014ce78
a014c8f4:  c2 0a 20 03  ldub  [ %o0 + 3 ], %g1
a014c8f8:  80 a0 60 01  cmp  %g1, 1
a014c8fc:  02 80 01 43  be  0xa014ce08
a014c900:  d8 02 20 04  ld  [ %o0 + 4 ], %o4
a014c904:  80 a0 60 01  cmp  %g1, 1
a014c908:  04 80 01 1f  ble  0xa014cd84
a014c90c:  80 a0 60 02  cmp  %g1, 2
a014c910:  12 80 01 5a  bne  0xa014ce78
a014c914:  ba 0b 20 ff  and  %o4, 0xff, %i5
a014c918:  b8 5f 60 c8  smul  %i5, 0xc8, %i4
a014c91c:  37 14 7a e1  sethi  %hi(0x51eb8400), %i3
a014c920:  b2 07 20 32  add  %i4, 0x32, %i1
a014c924:  b4 16 e1 1f  or  %i3, 0x11f, %i2
a014c928:  80 56 40 1a  umul  %i1, %i2, %g0
a014c92c:  91 40 00 00  rd  %y, %o0
a014c930:  b1 32 20 05  srl  %o0, 5, %i0
a014c934:  96 06 20 38  add  %i0, 0x38, %o3
a014c938:  9f 2a e0 10  sll  %o3, 0x10, %o7
a014c93c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014c940:  91 33 e0 10  srl  %o7, 0x10, %o0
a014c944:  7f ff ba ca  call  0xa013b46c
a014c948:  d8 28 63 de  stb  %o4, [ %g1 + 0x3de ]
a014c94c:  30 80 01 4b  b,a   0xa014ce78
a014c950:  f4 02 00 00  ld  [ %o0 ], %i2
a014c954:  37 2a 00 b8  sethi  %hi(0xa802e000), %i3
a014c958:  f4 2e e3 db  stb  %i2, [ %i3 + 0x3db ]	! 0xa802e3db
a014c95c:  7f ff fd ef  call  0xa014c118
a014c960:  90 0e a0 ff  and  %i2, 0xff, %o0
a014c964:  30 80 01 45  b,a   0xa014ce78
a014c968:  d0 02 00 00  ld  [ %o0 ], %o0
a014c96c:  33 2a 00 b8  sethi  %hi(0xa802e000), %i1
a014c970:  d0 2e 63 da  stb  %o0, [ %i1 + 0x3da ]	! 0xa802e3da
a014c974:  7f ff bb 44  call  0xa013b684
a014c978:  90 0a 20 ff  and  %o0, 0xff, %o0
a014c97c:  30 80 01 3f  b,a   0xa014ce78
a014c980:  3b 2a 00 b8  sethi  %hi(0xa802e000), %i5
a014c984:  e0 0a 20 03  ldub  [ %o0 + 3 ], %l0
a014c988:  b6 17 63 d0  or  %i5, 0x3d0, %i3
a014c98c:  c2 0e e0 03  ldub  [ %i3 + 3 ], %g1
a014c990:  98 0c 20 ff  and  %l0, 0xff, %o4
a014c994:  80 a0 40 0c  cmp  %g1, %o4
a014c998:  02 80 01 38  be  0xa014ce78
a014c99c:  80 a0 00 01  cmp  %g0, %g1
a014c9a0:  9a 40 20 00  addx  %g0, 0, %o5
a014c9a4:  80 a0 00 0c  cmp  %g0, %o4
a014c9a8:  b8 40 20 00  addx  %g0, 0, %i4
a014c9ac:  90 10 20 00  clr  %o0
a014c9b0:  80 8b 40 1c  btst  %o5, %i4
a014c9b4:  12 80 00 08  bne  0xa014c9d4
a014c9b8:  92 10 20 04  mov  4, %o1
a014c9bc:  90 10 20 00  clr  %o0
a014c9c0:  92 10 29 60  mov  0x960, %o1
a014c9c4:  7f fe ed 20  call  0xa0107e44
a014c9c8:  94 10 20 01  mov  1, %o2
a014c9cc:  90 10 20 00  clr  %o0
a014c9d0:  92 10 20 02  mov  2, %o1
a014c9d4:  7f ff 8a 06  call  0xa012f1ec
a014c9d8:  01 00 00 00  nop
a014c9dc:  92 17 63 d0  or  %i5, 0x3d0, %o1
a014c9e0:  10 80 01 26  b  0xa014ce78
a014c9e4:  e0 2a 60 03  stb  %l0, [ %o1 + 3 ]
a014c9e8:  d2 0a 20 07  ldub  [ %o0 + 7 ], %o1
a014c9ec:  7f ff f2 4c  call  0xa014931c
a014c9f0:  d0 0a 20 03  ldub  [ %o0 + 3 ], %o0
a014c9f4:  30 80 01 21  b,a   0xa014ce78
a014c9f8:  7f ff f2 e4  call  0xa0149588
a014c9fc:  d0 0a 20 03  ldub  [ %o0 + 3 ], %o0
a014ca00:  30 80 01 1e  b,a   0xa014ce78
a014ca04:  f4 0a 20 03  ldub  [ %o0 + 3 ], %i2
a014ca08:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a014ca0c:  f2 04 23 d0  ld  [ %l0 + 0x3d0 ], %i1	! 0xa802e3d0
a014ca10:  90 0e a0 01  and  %i2, 1, %o0
a014ca14:  31 00 40 00  sethi  %hi(0x1000000), %i0
a014ca18:  9f 2a 20 18  sll  %o0, 0x18, %o7
a014ca1c:  96 2e 40 18  andn  %i1, %i0, %o3
a014ca20:  94 12 c0 0f  or  %o3, %o7, %o2
a014ca24:  d4 24 23 d0  st  %o2, [ %l0 + 0x3d0 ]
a014ca28:  90 10 20 10  mov  0x10, %o0
a014ca2c:  40 00 14 1e  call  0xa0151aa4
a014ca30:  92 10 20 01  mov  1, %o1
a014ca34:  c2 0c 23 d0  ldub  [ %l0 + 0x3d0 ], %g1
a014ca38:  92 08 60 01  and  %g1, 1, %o1
a014ca3c:  7f ff 7a 3b  call  0xa012b328
a014ca40:  90 10 20 00  clr  %o0
a014ca44:  30 80 01 0d  b,a   0xa014ce78
a014ca48:  da 0a 20 03  ldub  [ %o0 + 3 ], %o5
a014ca4c:  33 2a 00 b8  sethi  %hi(0xa802e000), %i1
a014ca50:  d8 06 63 d0  ld  [ %i1 + 0x3d0 ], %o4	! 0xa802e3d0
a014ca54:  ba 0b 60 01  and  %o5, 1, %i5
a014ca58:  13 00 80 00  sethi  %hi(0x2000000), %o1
a014ca5c:  b6 2b 00 09  andn  %o4, %o1, %i3
a014ca60:  b9 2f 60 19  sll  %i5, 0x19, %i4
a014ca64:  b4 16 c0 1c  or  %i3, %i4, %i2
a014ca68:  f4 26 63 d0  st  %i2, [ %i1 + 0x3d0 ]
a014ca6c:  90 10 20 00  clr  %o0
a014ca70:  7f ff 89 df  call  0xa012f1ec
a014ca74:  92 10 20 01  mov  1, %o1
a014ca78:  90 10 20 01  mov  1, %o0
a014ca7c:  7f ff 89 dc  call  0xa012f1ec
a014ca80:  92 10 20 01  mov  1, %o1
a014ca84:  90 10 20 02  mov  2, %o0
a014ca88:  7f ff 89 d9  call  0xa012f1ec
a014ca8c:  92 10 20 01  mov  1, %o1
a014ca90:  90 10 20 03  mov  3, %o0
a014ca94:  7f ff 89 d6  call  0xa012f1ec
a014ca98:  92 10 20 01  mov  1, %o1
a014ca9c:  30 80 00 f7  b,a   0xa014ce78
a014caa0:  e0 0a 20 03  ldub  [ %o0 + 3 ], %l0
a014caa4:  31 00 06 9b  sethi  %hi(0x1a6c00), %i0
a014caa8:  90 16 23 78  or  %i0, 0x378, %o0	! 0x1a6f78
a014caac:  7f fe 49 b1  call  0xa00df170
a014cab0:  92 10 00 10  mov  %l0, %o1
a014cab4:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014cab8:  d0 03 23 d0  ld  [ %o4 + 0x3d0 ], %o0	! 0xa802e3d0
a014cabc:  96 0c 20 01  and  %l0, 1, %o3
a014cac0:  1f 01 00 00  sethi  %hi(0x4000000), %o7
a014cac4:  82 2a 00 0f  andn  %o0, %o7, %g1
a014cac8:  95 2a e0 1a  sll  %o3, 0x1a, %o2
a014cacc:  82 10 40 0a  or  %g1, %o2, %g1
a014cad0:  10 80 00 ea  b  0xa014ce78
a014cad4:  c2 23 23 d0  st  %g1, [ %o4 + 0x3d0 ]
a014cad8:  e0 0a 20 03  ldub  [ %o0 + 3 ], %l0
a014cadc:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a014cae0:  90 12 23 48  or  %o0, 0x348, %o0	! 0x1a6f48
a014cae4:  7f fe 49 a3  call  0xa00df170
a014cae8:  92 10 00 10  mov  %l0, %o1
a014caec:  80 a4 20 00  cmp  %l0, 0
a014caf0:  02 80 00 7f  be  0xa014ccec
a014caf4:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014caf8:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a014cafc:  f2 06 a2 a4  ld  [ %i2 + 0x2a4 ], %i1	! 0xa802d6a4
a014cb00:  f0 16 60 0a  lduh  [ %i1 + 0xa ], %i0
a014cb04:  80 a6 2f ff  cmp  %i0, 0xfff
a014cb08:  18 80 00 7a  bgu  0xa014ccf0
a014cb0c:  da 03 23 d0  ld  [ %o4 + 0x3d0 ], %o5
a014cb10:  37 2a 00 b8  sethi  %hi(0xa802e000), %i3
a014cb14:  fa 06 e3 d0  ld  [ %i3 + 0x3d0 ], %i5	! 0xa802e3d0
a014cb18:  19 02 00 00  sethi  %hi(0x8000000), %o4
a014cb1c:  b8 17 40 0c  or  %i5, %o4, %i4
a014cb20:  10 80 00 d6  b  0xa014ce78
a014cb24:  f8 26 e3 d0  st  %i4, [ %i3 + 0x3d0 ]
a014cb28:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a014cb2c:  d6 03 e1 a0  ld  [ %o7 + 0x1a0 ], %o3	! 0xa802e1a0
a014cb30:  15 02 00 00  sethi  %hi(0x8000000), %o2
a014cb34:  80 8a c0 0a  btst  %o3, %o2
a014cb38:  02 80 00 78  be  0xa014cd18
a014cb3c:  d0 0a 20 03  ldub  [ %o0 + 3 ], %o0
a014cb40:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a014cb44:  f0 02 e3 d0  ld  [ %o3 + 0x3d0 ], %i0	! 0xa802e3d0
a014cb48:  21 20 00 00  sethi  %hi(0x80000000), %l0
a014cb4c:  90 2e 00 10  andn  %i0, %l0, %o0
a014cb50:  d0 22 e3 d0  st  %o0, [ %o3 + 0x3d0 ]
a014cb54:  d8 02 e3 d0  ld  [ %o3 + 0x3d0 ], %o4
a014cb58:  80 a3 20 00  cmp  %o4, 0
a014cb5c:  16 80 00 69  bge  0xa014cd00
a014cb60:  1f 2a 00 b7  sethi  %hi(0xa802dc00), %o7
a014cb64:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a014cb68:  82 10 63 30  or  %g1, 0x330, %g1	! 0xa802df30
a014cb6c:  d2 00 60 70  ld  [ %g1 + 0x70 ], %o1
a014cb70:  1b 00 20 00  sethi  %hi(0x800000), %o5
a014cb74:  9a 2a 40 0d  andn  %o1, %o5, %o5
a014cb78:  10 80 00 c0  b  0xa014ce78
a014cb7c:  da 20 60 70  st  %o5, [ %g1 + 0x70 ]
a014cb80:  de 02 00 00  ld  [ %o0 ], %o7
a014cb84:  94 0b e0 ff  and  %o7, 0xff, %o2
a014cb88:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a014cb8c:  80 a2 a0 01  cmp  %o2, 1
a014cb90:  02 80 00 77  be  0xa014cd6c
a014cb94:  de 2b 63 d7  stb  %o7, [ %o5 + 0x3d7 ]
a014cb98:  7f ff 78 73  call  0xa012ad64
a014cb9c:  01 00 00 00  nop
a014cba0:  30 80 00 b6  b,a   0xa014ce78
a014cba4:  d2 0a 20 07  ldub  [ %o0 + 7 ], %o1
a014cba8:  80 a2 60 04  cmp  %o1, 4
a014cbac:  18 80 00 33  bgu  0xa014cc78
a014cbb0:  d0 0a 20 03  ldub  [ %o0 + 3 ], %o0
a014cbb4:  37 00 03 8d  sethi  %hi(0xe3400), %i3
a014cbb8:  b3 2a 60 02  sll  %o1, 2, %i1
a014cbbc:  b4 16 e1 90  or  %i3, 0x190, %i2
a014cbc0:  f0 06 80 19  ld  [ %i2 + %i1 ], %i0
a014cbc4:  81 c6 00 00  jmp  %i0
a014cbc8:  01 00 00 00  nop
a014cbcc:  d6 02 00 00  ld  [ %o0 ], %o3
a014cbd0:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a014cbd4:  d6 2e 23 d9  stb  %o3, [ %i0 + 0x3d9 ]	! 0xa802e3d9
a014cbd8:  7f ff b8 8a  call  0xa013ae00
a014cbdc:  90 0a e0 ff  and  %o3, 0xff, %o0
a014cbe0:  30 80 00 a6  b,a   0xa014ce78
a014cbe4:  7f ff fc e0  call  0xa014bf64
a014cbe8:  d0 0a 20 03  ldub  [ %o0 + 3 ], %o0
a014cbec:  30 80 00 a3  b,a   0xa014ce78
a014cbf0:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014cbf4:  d2 02 00 00  ld  [ %o0 ], %o1
a014cbf8:  a0 10 63 d0  or  %g1, 0x3d0, %l0
a014cbfc:  90 0a 60 ff  and  %o1, 0xff, %o0
a014cc00:  d2 2c 20 06  stb  %o1, [ %l0 + 6 ]
a014cc04:  7f ff 33 31  call  0xa01198c8
a014cc08:  92 10 20 00  clr  %o1
a014cc0c:  d0 0c 20 06  ldub  [ %l0 + 6 ], %o0
a014cc10:  7f ff 33 2e  call  0xa01198c8
a014cc14:  92 10 20 01  mov  1, %o1
a014cc18:  30 80 00 98  b,a   0xa014ce78
a014cc1c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014cc20:  de 0a 20 03  ldub  [ %o0 + 3 ], %o7
a014cc24:  ba 13 23 d0  or  %o4, 0x3d0, %i5
a014cc28:  d6 07 60 04  ld  [ %i5 + 4 ], %o3
a014cc2c:  11 3c 00 00  sethi  %hi(0xf0000000), %o0
a014cc30:  a0 2a c0 08  andn  %o3, %o0, %l0
a014cc34:  95 2b e0 1c  sll  %o7, 0x1c, %o2
a014cc38:  82 14 00 0a  or  %l0, %o2, %g1
a014cc3c:  c2 27 60 04  st  %g1, [ %i5 + 4 ]
a014cc40:  90 10 20 00  clr  %o0
a014cc44:  7f ff 89 6a  call  0xa012f1ec
a014cc48:  92 10 20 02  mov  2, %o1
a014cc4c:  90 10 20 01  mov  1, %o0
a014cc50:  7f ff 89 67  call  0xa012f1ec
a014cc54:  92 10 20 02  mov  2, %o1
a014cc58:  90 10 20 02  mov  2, %o0
a014cc5c:  7f ff 89 64  call  0xa012f1ec
a014cc60:  92 10 20 02  mov  2, %o1
a014cc64:  90 10 20 03  mov  3, %o0
a014cc68:  7f ff 89 61  call  0xa012f1ec
a014cc6c:  92 10 20 02  mov  2, %o1
a014cc70:  30 80 00 82  b,a   0xa014ce78
a014cc74:  92 10 20 04  mov  4, %o1
a014cc78:  90 0a 20 ff  and  %o0, 0xff, %o0
a014cc7c:  80 a2 20 00  cmp  %o0, 0
a014cc80:  02 80 00 2e  be  0xa014cd38
a014cc84:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a014cc88:  80 a2 20 01  cmp  %o0, 1
a014cc8c:  02 80 00 05  be  0xa014cca0
a014cc90:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014cc94:  7f ff d5 e1  call  0xa0142418
a014cc98:  01 00 00 00  nop
a014cc9c:  30 80 00 77  b,a   0xa014ce78
a014cca0:  90 13 23 d0  or  %o4, 0x3d0, %o0
a014cca4:  fa 02 20 04  ld  [ %o0 + 4 ], %i5
a014cca8:  b6 0a 60 0f  and  %o1, 0xf, %i3
a014ccac:  39 00 3c 00  sethi  %hi(0xf00000), %i4
a014ccb0:  b2 2f 40 1c  andn  %i5, %i4, %i1
a014ccb4:  b5 2e e0 14  sll  %i3, 0x14, %i2
a014ccb8:  b0 16 40 1a  or  %i1, %i2, %i0
a014ccbc:  f0 22 20 04  st  %i0, [ %o0 + 4 ]
a014ccc0:  7f ff d5 d6  call  0xa0142418
a014ccc4:  90 10 20 01  mov  1, %o0
a014ccc8:  30 80 00 6c  b,a   0xa014ce78
a014cccc:  10 bf ff eb  b  0xa014cc78
a014ccd0:  92 10 20 03  mov  3, %o1
a014ccd4:  10 bf ff e9  b  0xa014cc78
a014ccd8:  92 10 20 02  mov  2, %o1
a014ccdc:  10 bf ff e7  b  0xa014cc78
a014cce0:  92 10 20 00  clr  %o1
a014cce4:  10 bf ff e5  b  0xa014cc78
a014cce8:  92 10 20 01  mov  1, %o1
a014ccec:  da 03 23 d0  ld  [ %o4 + 0x3d0 ], %o5
a014ccf0:  13 02 00 00  sethi  %hi(0x8000000), %o1
a014ccf4:  82 2b 40 09  andn  %o5, %o1, %g1
a014ccf8:  10 80 00 60  b  0xa014ce78
a014ccfc:  c2 23 23 d0  st  %g1, [ %o4 + 0x3d0 ]
a014cd00:  82 13 e3 30  or  %o7, 0x330, %g1
a014cd04:  d4 00 60 70  ld  [ %g1 + 0x70 ], %o2
a014cd08:  17 00 20 00  sethi  %hi(0x800000), %o3
a014cd0c:  9a 12 80 0b  or  %o2, %o3, %o5
a014cd10:  10 80 00 5a  b  0xa014ce78
a014cd14:  da 20 60 70  st  %o5, [ %g1 + 0x70 ]
a014cd18:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a014cd1c:  fa 02 e3 d0  ld  [ %o3 + 0x3d0 ], %i5	! 0xa802e3d0
a014cd20:  39 20 00 00  sethi  %hi(0x80000000), %i4
a014cd24:  b4 2f 40 1c  andn  %i5, %i4, %i2
a014cd28:  b7 2a 20 1f  sll  %o0, 0x1f, %i3
a014cd2c:  b2 16 80 1b  or  %i2, %i3, %i1
a014cd30:  10 bf ff 89  b  0xa014cb54
a014cd34:  f2 22 e3 d0  st  %i1, [ %o3 + 0x3d0 ]
a014cd38:  b8 12 e3 d0  or  %o3, 0x3d0, %i4
a014cd3c:  de 07 20 04  ld  [ %i4 + 4 ], %o7
a014cd40:  a0 0a 60 0f  and  %o1, 0xf, %l0
a014cd44:  15 03 c0 00  sethi  %hi(0xf000000), %o2
a014cd48:  82 2b c0 0a  andn  %o7, %o2, %g1
a014cd4c:  9b 2c 20 18  sll  %l0, 0x18, %o5
a014cd50:  ba 10 40 0d  or  %g1, %o5, %i5
a014cd54:  7f ff d5 b1  call  0xa0142418
a014cd58:  fa 27 20 04  st  %i5, [ %i4 + 4 ]
a014cd5c:  30 80 00 47  b,a   0xa014ce78
a014cd60:  40 00 0c f0  call  0xa0150120
a014cd64:  92 10 20 00  clr  %o1
a014cd68:  30 80 00 44  b,a   0xa014ce78
a014cd6c:  7f ff 76 82  call  0xa012a774
a014cd70:  90 10 20 01  mov  1, %o0
a014cd74:  30 80 00 41  b,a   0xa014ce78
a014cd78:  7f ff 2d f9  call  0xa011855c
a014cd7c:  01 00 00 00  nop
a014cd80:  30 80 00 3e  b,a   0xa014ce78
a014cd84:  80 a0 60 00  cmp  %g1, 0
a014cd88:  12 80 00 3c  bne  0xa014ce78
a014cd8c:  b0 0b 20 ff  and  %o4, 0xff, %i0
a014cd90:  96 5e 20 c8  smul  %i0, 0xc8, %o3
a014cd94:  1f 14 7a e1  sethi  %hi(0x51eb8400), %o7
a014cd98:  9a 02 e0 32  add  %o3, 0x32, %o5
a014cd9c:  82 13 e1 1f  or  %o7, 0x11f, %g1
a014cda0:  80 53 40 01  umul  %o5, %g1, %g0
a014cda4:  95 40 00 00  rd  %y, %o2
a014cda8:  93 32 a0 05  srl  %o2, 5, %o1
a014cdac:  a0 02 60 38  add  %o1, 0x38, %l0
a014cdb0:  b9 2c 20 10  sll  %l0, 0x10, %i4
a014cdb4:  3b 2a 00 b8  sethi  %hi(0xa802e000), %i5
a014cdb8:  d8 2f 63 dc  stb  %o4, [ %i5 + 0x3dc ]	! 0xa802e3dc
a014cdbc:  7f ff b9 9c  call  0xa013b42c
a014cdc0:  91 37 20 10  srl  %i4, 0x10, %o0
a014cdc4:  30 80 00 2d  b,a   0xa014ce78
a014cdc8:  80 a0 60 00  cmp  %g1, 0
a014cdcc:  12 80 00 2b  bne  0xa014ce78
a014cdd0:  90 0b 20 ff  and  %o4, 0xff, %o0
a014cdd4:  b0 5a 20 c8  smul  %o0, 0xc8, %i0
a014cdd8:  17 14 7a e1  sethi  %hi(0x51eb8400), %o3
a014cddc:  9e 06 20 32  add  %i0, 0x32, %o7
a014cde0:  82 12 e1 1f  or  %o3, 0x11f, %g1
a014cde4:  80 53 c0 01  umul  %o7, %g1, %g0
a014cde8:  9b 40 00 00  rd  %y, %o5
a014cdec:  95 33 60 05  srl  %o5, 5, %o2
a014cdf0:  a0 02 a0 1c  add  %o2, 0x1c, %l0
a014cdf4:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a014cdf8:  d8 2a 63 df  stb  %o4, [ %o1 + 0x3df ]	! 0xa802e3df
a014cdfc:  7f ff ba 00  call  0xa013b5fc
a014ce00:  90 0c 20 ff  and  %l0, 0xff, %o0
a014ce04:  30 80 00 1d  b,a   0xa014ce78
a014ce08:  9a 0b 20 ff  and  %o4, 0xff, %o5
a014ce0c:  94 5b 60 c8  smul  %o5, 0xc8, %o2
a014ce10:  13 14 7a e1  sethi  %hi(0x51eb8400), %o1
a014ce14:  ba 02 a0 32  add  %o2, 0x32, %i5
a014ce18:  a0 12 61 1f  or  %o1, 0x11f, %l0
a014ce1c:  80 57 40 10  umul  %i5, %l0, %g0
a014ce20:  b9 40 00 00  rd  %y, %i4
a014ce24:  b7 37 20 05  srl  %i4, 5, %i3
a014ce28:  b4 06 e0 38  add  %i3, 0x38, %i2
a014ce2c:  91 2e a0 10  sll  %i2, 0x10, %o0
a014ce30:  33 2a 00 b8  sethi  %hi(0xa802e000), %i1
a014ce34:  d8 2e 63 dd  stb  %o4, [ %i1 + 0x3dd ]	! 0xa802e3dd
a014ce38:  7f ff b9 85  call  0xa013b44c
a014ce3c:  91 32 20 10  srl  %o0, 0x10, %o0
a014ce40:  30 80 00 0e  b,a   0xa014ce78
a014ce44:  9a 0b 20 ff  and  %o4, 0xff, %o5
a014ce48:  94 5b 60 c8  smul  %o5, 0xc8, %o2
a014ce4c:  13 14 7a e1  sethi  %hi(0x51eb8400), %o1
a014ce50:  ba 02 a0 32  add  %o2, 0x32, %i5
a014ce54:  a0 12 61 1f  or  %o1, 0x11f, %l0
a014ce58:  80 57 40 10  umul  %i5, %l0, %g0
a014ce5c:  b9 40 00 00  rd  %y, %i4
a014ce60:  b7 37 20 05  srl  %i4, 5, %i3
a014ce64:  b2 06 e0 1c  add  %i3, 0x1c, %i1
a014ce68:  35 2a 00 b8  sethi  %hi(0xa802e000), %i2
a014ce6c:  d8 2e a3 e0  stb  %o4, [ %i2 + 0x3e0 ]	! 0xa802e3e0
a014ce70:  7f ff b9 cc  call  0xa013b5a0
a014ce74:  90 0e 60 ff  and  %i1, 0xff, %o0
a014ce78:  01 00 00 00  nop
a014ce7c:  81 c7 e0 08  ret
a014ce80:  81 e8 00 00  restore
