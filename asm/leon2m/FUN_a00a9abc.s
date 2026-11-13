# leon2m FUN_a00a9abc 0xa00a9abc-0xa00a9cc8 (524 bytes)
a00a9abc:  9d e3 bf 98  save  %sp, -104, %sp
a00a9ac0:  90 10 21 11  mov  0x111, %o0
a00a9ac4:  40 02 74 23  call  0xa0146b50
a00a9ac8:  92 10 20 00  clr  %o1
a00a9acc:  90 10 20 00  clr  %o0
a00a9ad0:  40 02 74 27  call  0xa0146b6c
a00a9ad4:  92 10 20 00  clr  %o1
a00a9ad8:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00a9adc:  82 16 a2 90  or  %i2, 0x290, %g1	! 0xa802d290
a00a9ae0:  d8 08 60 20  ldub  [ %g1 + 0x20 ], %o4
a00a9ae4:  da 08 60 1e  ldub  [ %g1 + 0x1e ], %o5
a00a9ae8:  80 a3 40 0c  cmp  %o5, %o4
a00a9aec:  22 80 00 6a  be,a   0xa00a9c94
a00a9af0:  90 10 20 2a  mov  0x2a, %o0
a00a9af4:  b8 10 20 00  clr  %i4
a00a9af8:  ba 10 20 00  clr  %i5
a00a9afc:  37 00 06 3a  sethi  %hi(0x18e800), %i3
a00a9b00:  9b 2f 60 03  sll  %i5, 3, %o5
a00a9b04:  98 23 40 1d  sub  %o5, %i5, %o4
a00a9b08:  b3 2b 20 02  sll  %o4, 2, %i1
a00a9b0c:  b0 16 a2 90  or  %i2, 0x290, %i0
a00a9b10:  96 06 40 1d  add  %i1, %i5, %o3
a00a9b14:  de 0e 20 08  ldub  [ %i0 + 8 ], %o7
a00a9b18:  90 02 c0 0f  add  %o3, %o7, %o0
a00a9b1c:  93 2a 20 10  sll  %o0, 0x10, %o1
a00a9b20:  93 32 60 10  srl  %o1, 0x10, %o1
a00a9b24:  7f ff e7 48  call  0xa00a3844
a00a9b28:  90 16 e0 9c  or  %i3, 0x9c, %o0
a00a9b2c:  98 10 00 08  mov  %o0, %o4
a00a9b30:  94 07 40 1d  add  %i5, %i5, %o2
a00a9b34:  94 02 a0 06  add  %o2, 6, %o2
a00a9b38:  90 10 20 00  clr  %o0
a00a9b3c:  92 10 20 2a  mov  0x2a, %o1
a00a9b40:  96 10 20 01  mov  1, %o3
a00a9b44:  9a 10 20 00  clr  %o5
a00a9b48:  7f ff e5 97  call  0xa00a31a4
a00a9b4c:  b8 07 20 01  inc  %i4
a00a9b50:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00a9b54:  80 a7 60 02  cmp  %i5, 2
a00a9b58:  08 bf ff eb  bleu  0xa00a9b04
a00a9b5c:  9b 2f 60 03  sll  %i5, 3, %o5
a00a9b60:  b8 10 20 00  clr  %i4
a00a9b64:  ba 10 20 00  clr  %i5
a00a9b68:  33 00 06 09  sethi  %hi(0x182400), %i1
a00a9b6c:  b1 2f 60 03  sll  %i5, 3, %i0
a00a9b70:  b6 26 00 1d  sub  %i0, %i5, %i3
a00a9b74:  9f 2e e0 02  sll  %i3, 2, %o7
a00a9b78:  b6 16 a2 90  or  %i2, 0x290, %i3
a00a9b7c:  90 03 c0 1d  add  %o7, %i5, %o0
a00a9b80:  d6 0e e0 08  ldub  [ %i3 + 8 ], %o3
a00a9b84:  92 02 00 0b  add  %o0, %o3, %o1
a00a9b88:  95 2a 60 10  sll  %o1, 0x10, %o2
a00a9b8c:  93 32 a0 10  srl  %o2, 0x10, %o1
a00a9b90:  7f ff e7 2d  call  0xa00a3844
a00a9b94:  90 16 61 34  or  %i1, 0x134, %o0
a00a9b98:  82 07 40 1d  add  %i5, %i5, %g1
a00a9b9c:  98 10 00 08  mov  %o0, %o4
a00a9ba0:  94 00 60 0c  add  %g1, 0xc, %o2
a00a9ba4:  90 10 20 00  clr  %o0
a00a9ba8:  92 10 20 2a  mov  0x2a, %o1
a00a9bac:  96 10 20 01  mov  1, %o3
a00a9bb0:  9a 10 20 00  clr  %o5
a00a9bb4:  7f ff e5 7c  call  0xa00a31a4
a00a9bb8:  b8 07 20 01  inc  %i4
a00a9bbc:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00a9bc0:  80 a7 60 01  cmp  %i5, 1
a00a9bc4:  08 bf ff eb  bleu  0xa00a9b70
a00a9bc8:  b1 2f 60 03  sll  %i5, 3, %i0
a00a9bcc:  b8 10 20 03  mov  3, %i4
a00a9bd0:  ba 10 20 03  mov  3, %i5
a00a9bd4:  35 00 06 0a  sethi  %hi(0x182800), %i2
a00a9bd8:  97 2f 60 03  sll  %i5, 3, %o3
a00a9bdc:  90 22 c0 1d  sub  %o3, %i5, %o0
a00a9be0:  93 2a 20 02  sll  %o0, 2, %o1
a00a9be4:  94 02 40 1d  add  %o1, %i5, %o2
a00a9be8:  c2 0e e0 08  ldub  [ %i3 + 8 ], %g1
a00a9bec:  9a 02 80 01  add  %o2, %g1, %o5
a00a9bf0:  99 2b 60 10  sll  %o5, 0x10, %o4
a00a9bf4:  93 33 20 10  srl  %o4, 0x10, %o1
a00a9bf8:  7f ff e7 13  call  0xa00a3844
a00a9bfc:  90 16 a0 c0  or  %i2, 0xc0, %o0
a00a9c00:  98 10 00 08  mov  %o0, %o4
a00a9c04:  b2 07 40 1d  add  %i5, %i5, %i1
a00a9c08:  94 06 60 0a  add  %i1, 0xa, %o2
a00a9c0c:  90 10 20 00  clr  %o0
a00a9c10:  92 10 20 2a  mov  0x2a, %o1
a00a9c14:  96 10 20 01  mov  1, %o3
a00a9c18:  9a 10 20 00  clr  %o5
a00a9c1c:  7f ff e5 62  call  0xa00a31a4
a00a9c20:  b8 07 20 01  inc  %i4
a00a9c24:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00a9c28:  80 a7 60 04  cmp  %i5, 4
a00a9c2c:  08 bf ff ec  bleu  0xa00a9bdc
a00a9c30:  97 2f 60 03  sll  %i5, 3, %o3
a00a9c34:  d0 0e e0 2f  ldub  [ %i3 + 0x2f ], %o0
a00a9c38:  7f ff fe 86  call  0xa00a9650
a00a9c3c:  92 10 20 00  clr  %o1
a00a9c40:  da 0e e0 2f  ldub  [ %i3 + 0x2f ], %o5
a00a9c44:  b4 03 40 0d  add  %o5, %o5, %i2
a00a9c48:  80 a3 60 06  cmp  %o5, 6
a00a9c4c:  08 80 00 04  bleu  0xa00a9c5c
a00a9c50:  82 06 a0 06  add  %i2, 6, %g1
a00a9c54:  b8 03 40 0d  add  %o5, %o5, %i4
a00a9c58:  82 07 3f f8  add  %i4, -8, %g1
a00a9c5c:  b4 08 60 ff  and  %g1, 0xff, %i2
a00a9c60:  90 10 20 00  clr  %o0
a00a9c64:  92 10 20 28  mov  0x28, %o1
a00a9c68:  94 10 00 1a  mov  %i2, %o2
a00a9c6c:  96 10 20 01  mov  1, %o3
a00a9c70:  98 10 20 0f  mov  0xf, %o4
a00a9c74:  40 02 73 ab  call  0xa0146b20
a00a9c78:  9a 10 20 00  clr  %o5
a00a9c7c:  b0 10 20 00  clr  %i0
a00a9c80:  b2 10 20 29  mov  0x29, %i1
a00a9c84:  b6 10 20 01  mov  1, %i3
a00a9c88:  b8 10 20 10  mov  0x10, %i4
a00a9c8c:  40 02 73 a5  call  0xa0146b20
a00a9c90:  9b e8 20 00  restore  %g0, 0, %o5
a00a9c94:  92 10 20 10  mov  0x10, %o1
a00a9c98:  94 10 20 0b  mov  0xb, %o2
a00a9c9c:  96 10 22 96  mov  0x296, %o3
a00a9ca0:  40 02 73 78  call  0xa0146a80
a00a9ca4:  98 10 20 00  clr  %o4
a00a9ca8:  90 10 20 2a  mov  0x2a, %o0
a00a9cac:  92 10 20 12  mov  0x12, %o1
a00a9cb0:  94 10 20 0b  mov  0xb, %o2
a00a9cb4:  96 10 22 96  mov  0x296, %o3
a00a9cb8:  40 02 73 72  call  0xa0146a80
a00a9cbc:  98 10 20 00  clr  %o4
a00a9cc0:  10 bf ff 8e  b  0xa00a9af8
a00a9cc4:  b8 10 20 00  clr  %i4
