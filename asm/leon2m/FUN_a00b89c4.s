# leon2m FUN_a00b89c4 0xa00b89c4-0xa00b8ca8 (740 bytes)
a00b89c4:  9d e3 bf 88  save  %sp, -120, %sp
a00b89c8:  90 10 20 02  mov  2, %o0
a00b89cc:  40 02 38 68  call  0xa0146b6c
a00b89d0:  92 10 20 00  clr  %o1
a00b89d4:  90 10 20 6f  mov  0x6f, %o0
a00b89d8:  40 02 38 5e  call  0xa0146b50
a00b89dc:  92 10 20 00  clr  %o1
a00b89e0:  7f ff bc aa  call  0xa00a7c88
a00b89e4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b89e8:  80 a6 20 00  cmp  %i0, 0
a00b89ec:  02 80 00 40  be  0xa00b8aec
a00b89f0:  2d 2a 00 b4  sethi  %hi(0xa802d000), %l6
a00b89f4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00b89f8:  98 12 a2 90  or  %o2, 0x290, %o4	! 0xa802d290
a00b89fc:  17 33 33 33  sethi  %hi(0xcccccc00), %o3
a00b8a00:  e0 0b 21 9b  ldub  [ %o4 + 0x19b ], %l0
a00b8a04:  9a 12 e0 cd  or  %o3, 0xcd, %o5
a00b8a08:  d0 0b 21 9f  ldub  [ %o4 + 0x19f ], %o0
a00b8a0c:  80 54 00 0d  umul  %l0, %o5, %g0
a00b8a10:  ad 40 00 00  rd  %y, %l6
a00b8a14:  80 52 00 0d  umul  %o0, %o5, %g0
a00b8a18:  ab 40 00 00  rd  %y, %l5
a00b8a1c:  95 35 a0 03  srl  %l6, 3, %o2
a00b8a20:  99 35 60 03  srl  %l5, 3, %o4
a00b8a24:  a9 2a a0 02  sll  %o2, 2, %l4
a00b8a28:  a7 2b 20 02  sll  %o4, 2, %l3
a00b8a2c:  a4 05 00 0a  add  %l4, %o2, %l2
a00b8a30:  82 04 80 12  add  %l2, %l2, %g1
a00b8a34:  a2 04 c0 0c  add  %l3, %o4, %l1
a00b8a38:  96 24 00 01  sub  %l0, %g1, %o3
a00b8a3c:  9e 04 40 11  add  %l1, %l1, %o7
a00b8a40:  9a 22 00 0f  sub  %o0, %o7, %o5
a00b8a44:  a0 07 bf e8  add  %fp, -24, %l0
a00b8a48:  13 00 06 60  sethi  %hi(0x198000), %o1
a00b8a4c:  96 0a e0 ff  and  %o3, 0xff, %o3
a00b8a50:  98 0b 20 ff  and  %o4, 0xff, %o4
a00b8a54:  92 12 61 b0  or  %o1, 0x1b0, %o1
a00b8a58:  94 0a a0 ff  and  %o2, 0xff, %o2
a00b8a5c:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00b8a60:  40 02 7b 65  call  0xa01577f4
a00b8a64:  90 10 00 10  mov  %l0, %o0
a00b8a68:  98 10 20 00  clr  %o4
a00b8a6c:  82 10 20 00  clr  %g1
a00b8a70:  96 07 bf f8  add  %fp, -8, %o3
a00b8a74:  90 02 c0 01  add  %o3, %g1, %o0
a00b8a78:  d2 0a 3f f0  ldub  [ %o0 + -16 ], %o1
a00b8a7c:  80 a2 60 00  cmp  %o1, 0
a00b8a80:  02 80 00 08  be  0xa00b8aa0
a00b8a84:  9e 03 3f ff  add  %o4, -1, %o7
a00b8a88:  98 03 20 01  inc  %o4
a00b8a8c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b8a90:  80 a0 60 0e  cmp  %g1, 0xe
a00b8a94:  08 bf ff f9  bleu  0xa00b8a78
a00b8a98:  90 02 c0 01  add  %o3, %g1, %o0
a00b8a9c:  9e 03 3f ff  add  %o4, -1, %o7
a00b8aa0:  98 10 00 10  mov  %l0, %o4
a00b8aa4:  90 10 20 00  clr  %o0
a00b8aa8:  de 2f bf e8  stb  %o7, [ %fp + -24 ]
a00b8aac:  92 10 20 06  mov  6, %o1
a00b8ab0:  94 10 20 05  mov  5, %o2
a00b8ab4:  96 10 20 0a  mov  0xa, %o3
a00b8ab8:  7f ff a9 bb  call  0xa00a31a4
a00b8abc:  9a 10 20 00  clr  %o5
a00b8ac0:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00b8ac4:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0	! 0xa8025c56
a00b8ac8:  a5 32 20 02  srl  %o0, 2, %l2
a00b8acc:  80 a6 00 12  cmp  %i0, %l2
a00b8ad0:  02 80 00 55  be  0xa00b8c24
a00b8ad4:  90 0a 20 03  and  %o0, 3, %o0
a00b8ad8:  90 10 20 04  mov  4, %o0
a00b8adc:  92 10 20 00  clr  %o1
a00b8ae0:  40 02 38 58  call  0xa0146c40
a00b8ae4:  94 10 20 00  clr  %o2
a00b8ae8:  30 80 00 6e  b,a   0xa00b8ca0
a00b8aec:  03 00 06 4c  sethi  %hi(0x193000), %g1
a00b8af0:  a2 15 a2 90  or  %l6, 0x290, %l1
a00b8af4:  d2 0c 60 08  ldub  [ %l1 + 8 ], %o1
a00b8af8:  7f ff ab 53  call  0xa00a3844
a00b8afc:  90 10 62 48  or  %g1, 0x248, %o0
a00b8b00:  98 10 00 08  mov  %o0, %o4
a00b8b04:  21 33 33 33  sethi  %hi(0xcccccc00), %l0
a00b8b08:  90 10 20 00  clr  %o0
a00b8b0c:  92 10 20 06  mov  6, %o1
a00b8b10:  94 10 20 05  mov  5, %o2
a00b8b14:  96 10 20 0a  mov  0xa, %o3
a00b8b18:  9a 10 20 00  clr  %o5
a00b8b1c:  7f ff a9 a2  call  0xa00a31a4
a00b8b20:  a8 14 20 cd  or  %l0, 0xcd, %l4
a00b8b24:  a4 10 20 00  clr  %l2
a00b8b28:  a6 07 bf e8  add  %fp, -24, %l3
a00b8b2c:  2b 00 06 60  sethi  %hi(0x198000), %l5
a00b8b30:  a0 10 20 00  clr  %l0
a00b8b34:  a2 07 bf f8  add  %fp, -8, %l1
a00b8b38:  90 15 a2 90  or  %l6, 0x290, %o0
a00b8b3c:  9a 04 00 08  add  %l0, %o0, %o5
a00b8b40:  d0 0b 61 9c  ldub  [ %o5 + 0x19c ], %o0
a00b8b44:  de 0b 61 98  ldub  [ %o5 + 0x198 ], %o7
a00b8b48:  80 53 c0 14  umul  %o7, %l4, %g0
a00b8b4c:  95 40 00 00  rd  %y, %o2
a00b8b50:  80 52 00 14  umul  %o0, %l4, %g0
a00b8b54:  99 40 00 00  rd  %y, %o4
a00b8b58:  95 32 a0 03  srl  %o2, 3, %o2
a00b8b5c:  99 33 20 03  srl  %o4, 3, %o4
a00b8b60:  83 2a a0 02  sll  %o2, 2, %g1
a00b8b64:  93 2b 20 02  sll  %o4, 2, %o1
a00b8b68:  96 00 40 0a  add  %g1, %o2, %o3
a00b8b6c:  9a 02 40 0c  add  %o1, %o4, %o5
a00b8b70:  82 02 c0 0b  add  %o3, %o3, %g1
a00b8b74:  92 03 40 0d  add  %o5, %o5, %o1
a00b8b78:  96 23 c0 01  sub  %o7, %g1, %o3
a00b8b7c:  9a 22 00 09  sub  %o0, %o1, %o5
a00b8b80:  98 0b 20 ff  and  %o4, 0xff, %o4
a00b8b84:  94 0a a0 ff  and  %o2, 0xff, %o2
a00b8b88:  96 0a e0 ff  and  %o3, 0xff, %o3
a00b8b8c:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00b8b90:  90 10 00 13  mov  %l3, %o0
a00b8b94:  40 02 7b 18  call  0xa01577f4
a00b8b98:  92 15 61 b0  or  %l5, 0x1b0, %o1
a00b8b9c:  98 10 20 00  clr  %o4
a00b8ba0:  82 10 20 00  clr  %g1
a00b8ba4:  96 04 40 01  add  %l1, %g1, %o3
a00b8ba8:  de 0a ff f0  ldub  [ %o3 + -16 ], %o7
a00b8bac:  80 a3 e0 00  cmp  %o7, 0
a00b8bb0:  22 80 00 08  be,a   0xa00b8bd0
a00b8bb4:  92 04 00 10  add  %l0, %l0, %o1
a00b8bb8:  98 03 20 01  inc  %o4
a00b8bbc:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b8bc0:  80 a0 60 0e  cmp  %g1, 0xe
a00b8bc4:  08 bf ff f9  bleu  0xa00b8ba8
a00b8bc8:  96 04 40 01  add  %l1, %g1, %o3
a00b8bcc:  92 04 00 10  add  %l0, %l0, %o1
a00b8bd0:  82 03 3f ff  add  %o4, -1, %g1
a00b8bd4:  94 02 60 07  add  %o1, 7, %o2
a00b8bd8:  c2 2f bf e8  stb  %g1, [ %fp + -24 ]
a00b8bdc:  90 10 20 00  clr  %o0
a00b8be0:  92 10 20 06  mov  6, %o1
a00b8be4:  96 10 20 0a  mov  0xa, %o3
a00b8be8:  98 10 00 13  mov  %l3, %o4
a00b8bec:  9a 10 20 00  clr  %o5
a00b8bf0:  7f ff a9 6d  call  0xa00a31a4
a00b8bf4:  a4 04 a0 01  inc  %l2
a00b8bf8:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00b8bfc:  80 a4 20 02  cmp  %l0, 2
a00b8c00:  08 bf ff cf  bleu  0xa00b8b3c
a00b8c04:  90 15 a2 90  or  %l6, 0x290, %o0
a00b8c08:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00b8c0c:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0	! 0xa8025c56
a00b8c10:  a5 32 20 02  srl  %o0, 2, %l2
a00b8c14:  80 a6 00 12  cmp  %i0, %l2
a00b8c18:  32 bf ff b1  bne,a   0xa00b8adc
a00b8c1c:  90 10 20 04  mov  4, %o0
a00b8c20:  90 0a 20 03  and  %o0, 3, %o0
a00b8c24:  7f ff d3 12  call  0xa00ad86c
a00b8c28:  92 10 20 00  clr  %o1
a00b8c2c:  f0 0c 20 56  ldub  [ %l0 + 0x56 ], %i0
a00b8c30:  9a 0e 20 03  and  %i0, 3, %o5
a00b8c34:  80 a3 60 03  cmp  %o5, 3
a00b8c38:  18 80 00 17  bgu  0xa00b8c94
a00b8c3c:  82 10 00 0d  mov  %o5, %g1
a00b8c40:  aa 00 40 01  add  %g1, %g1, %l5
a00b8c44:  a8 05 60 05  add  %l5, 5, %l4
a00b8c48:  a1 2d 20 10  sll  %l4, 0x10, %l0
a00b8c4c:  b0 10 20 00  clr  %i0
a00b8c50:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00b8c54:  94 03 60 04  add  %o5, 4, %o2
a00b8c58:  99 2a a0 10  sll  %o2, 0x10, %o4
a00b8c5c:  a2 06 20 1c  add  %i0, 0x1c, %l1
a00b8c60:  93 33 20 10  srl  %o4, 0x10, %o1
a00b8c64:  98 0c 60 ff  and  %l1, 0xff, %o4
a00b8c68:  90 10 20 00  clr  %o0
a00b8c6c:  95 34 20 10  srl  %l0, 0x10, %o2
a00b8c70:  96 10 20 01  mov  1, %o3
a00b8c74:  9a 10 20 00  clr  %o5
a00b8c78:  40 02 37 aa  call  0xa0146b20
a00b8c7c:  b0 06 20 01  inc  %i0
a00b8c80:  ac 0e 20 ff  and  %i0, 0xff, %l6
a00b8c84:  80 a5 a0 01  cmp  %l6, 1
a00b8c88:  08 bf ff f3  bleu  0xa00b8c54
a00b8c8c:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00b8c90:  30 80 00 04  b,a   0xa00b8ca0
a00b8c94:  a6 03 7f fc  add  %o5, -4, %l3
a00b8c98:  10 bf ff ea  b  0xa00b8c40
a00b8c9c:  82 0c e0 ff  and  %l3, 0xff, %g1
a00b8ca0:  81 c7 e0 08  ret
a00b8ca4:  81 e8 00 00  restore
