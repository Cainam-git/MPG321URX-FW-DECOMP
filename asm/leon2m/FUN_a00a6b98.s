# leon2m FUN_a00a6b98 0xa00a6b98-0xa00a788c (3316 bytes)
a00a6b98:  9d e3 bf 88  save  %sp, -120, %sp
a00a6b9c:  40 02 85 f8  call  0xa014837c
a00a6ba0:  90 10 20 00  clr  %o0
a00a6ba4:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00a6ba8:  17 2a aa aa  sethi  %hi(0xaaaaa800), %o3
a00a6bac:  95 33 60 10  srl  %o5, 0x10, %o2
a00a6bb0:  82 12 e2 ab  or  %o3, 0x2ab, %g1
a00a6bb4:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a00a6bb8:  80 52 80 01  umul  %o2, %g1, %g0
a00a6bbc:  93 40 00 00  rd  %y, %o1
a00a6bc0:  9a 16 e2 90  or  %i3, 0x290, %o5
a00a6bc4:  91 32 60 04  srl  %o1, 4, %o0
a00a6bc8:  c2 0b 61 3e  ldub  [ %o5 + 0x13e ], %g1
a00a6bcc:  98 10 20 02  mov  2, %o4
a00a6bd0:  a2 02 20 01  add  %o0, 1, %l1
a00a6bd4:  80 a0 60 00  cmp  %g1, 0
a00a6bd8:  ae 10 20 02  mov  2, %l7
a00a6bdc:  02 80 00 13  be  0xa00a6c28
a00a6be0:  d8 2f bf f7  stb  %o4, [ %fp + -9 ]
a00a6be4:  80 a0 60 01  cmp  %g1, 1
a00a6be8:  02 80 02 a2  be  0xa00a7670
a00a6bec:  80 a0 60 02  cmp  %g1, 2
a00a6bf0:  b8 10 20 35  mov  0x35, %i4
a00a6bf4:  ae 10 20 02  mov  2, %l7
a00a6bf8:  02 80 00 0c  be  0xa00a6c28
a00a6bfc:  f8 2f bf f7  stb  %i4, [ %fp + -9 ]
a00a6c00:  80 a0 60 03  cmp  %g1, 3
a00a6c04:  02 80 03 03  be  0xa00a7810
a00a6c08:  01 00 00 00  nop
a00a6c0c:  e4 0b 61 a5  ldub  [ %o5 + 0x1a5 ], %l2
a00a6c10:  e0 0b 61 a6  ldub  [ %o5 + 0x1a6 ], %l0
a00a6c14:  a6 04 80 12  add  %l2, %l2, %l3
a00a6c18:  9e 04 00 10  add  %l0, %l0, %o7
a00a6c1c:  ae 04 c0 12  add  %l3, %l2, %l7
a00a6c20:  de 2f bf f7  stb  %o7, [ %fp + -9 ]
a00a6c24:  9a 16 e2 90  or  %i3, 0x290, %o5
a00a6c28:  c2 0b 61 3f  ldub  [ %o5 + 0x13f ], %g1
a00a6c2c:  80 a0 60 00  cmp  %g1, 0
a00a6c30:  aa 10 20 02  mov  2, %l5
a00a6c34:  02 80 00 10  be  0xa00a6c74
a00a6c38:  ba 10 20 06  mov  6, %i5
a00a6c3c:  80 a0 60 01  cmp  %g1, 1
a00a6c40:  02 80 02 7f  be  0xa00a763c
a00a6c44:  80 a0 60 02  cmp  %g1, 2
a00a6c48:  aa 10 20 02  mov  2, %l5
a00a6c4c:  02 80 00 0a  be  0xa00a6c74
a00a6c50:  ba 10 20 31  mov  0x31, %i5
a00a6c54:  80 a0 60 03  cmp  %g1, 3
a00a6c58:  02 80 02 79  be  0xa00a763c
a00a6c5c:  01 00 00 00  nop
a00a6c60:  fa 0b 61 a7  ldub  [ %o5 + 0x1a7 ], %i5
a00a6c64:  82 07 40 1d  add  %i5, %i5, %g1
a00a6c68:  d6 0b 61 a8  ldub  [ %o5 + 0x1a8 ], %o3
a00a6c6c:  aa 00 40 1d  add  %g1, %i5, %l5
a00a6c70:  ba 02 c0 0b  add  %o3, %o3, %i5
a00a6c74:  40 02 85 c2  call  0xa014837c
a00a6c78:  90 10 20 00  clr  %o0
a00a6c7c:  b9 2a 20 10  sll  %o0, 0x10, %i4
a00a6c80:  ad 37 20 10  srl  %i4, 0x10, %l6
a00a6c84:  29 0a aa aa  sethi  %hi(0x2aaaa800), %l4
a00a6c88:  a0 05 bd c8  add  %l6, -568, %l0
a00a6c8c:  a6 15 22 ab  or  %l4, 0x2ab, %l3
a00a6c90:  80 5c 00 13  smul  %l0, %l3, %g0
a00a6c94:  a5 40 00 00  rd  %y, %l2
a00a6c98:  9f 3c a0 02  sra  %l2, 2, %o7
a00a6c9c:  9b 3c 20 1f  sra  %l0, 0x1f, %o5
a00a6ca0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a6ca4:  80 a6 60 01  cmp  %i1, 1
a00a6ca8:  02 80 00 e6  be  0xa00a7040
a00a6cac:  a0 23 c0 0d  sub  %o7, %o5, %l0
a00a6cb0:  80 a6 60 00  cmp  %i1, 0
a00a6cb4:  02 80 02 2f  be  0xa00a7570
a00a6cb8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a6cbc:  80 a6 20 02  cmp  %i0, 2
a00a6cc0:  02 80 00 f6  be  0xa00a7098
a00a6cc4:  90 10 20 00  clr  %o0
a00a6cc8:  80 a6 20 01  cmp  %i0, 1
a00a6ccc:  02 80 00 0d  be  0xa00a6d00
a00a6cd0:  80 a6 20 02  cmp  %i0, 2
a00a6cd4:  02 80 00 13  be  0xa00a6d20
a00a6cd8:  80 a6 20 00  cmp  %i0, 0
a00a6cdc:  12 80 00 07  bne  0xa00a6cf8
a00a6ce0:  b0 10 20 01  mov  1, %i0
a00a6ce4:  aa 16 e2 90  or  %i3, 0x290, %l5
a00a6ce8:  f0 0d 61 3e  ldub  [ %l5 + 0x13e ], %i0
a00a6cec:  80 a6 20 04  cmp  %i0, 4
a00a6cf0:  02 80 00 0c  be  0xa00a6d20
a00a6cf4:  b0 10 20 01  mov  1, %i0
a00a6cf8:  40 02 80 32  call  0xa0146dc0
a00a6cfc:  93 e8 20 00  restore  %g0, 0, %o1
a00a6d00:  94 16 e2 90  or  %i3, 0x290, %o2
a00a6d04:  e6 0a a1 3f  ldub  [ %o2 + 0x13f ], %l3
a00a6d08:  80 a4 e0 04  cmp  %l3, 4
a00a6d0c:  02 80 01 57  be  0xa00a7268
a00a6d10:  82 0e a0 ff  and  %i2, 0xff, %g1
a00a6d14:  b0 10 20 01  mov  1, %i0
a00a6d18:  40 02 80 2a  call  0xa0146dc0
a00a6d1c:  93 e8 20 00  restore  %g0, 0, %o1
a00a6d20:  b6 0e a0 ff  and  %i2, 0xff, %i3
a00a6d24:  80 a6 e0 01  cmp  %i3, 1
a00a6d28:  02 80 02 17  be  0xa00a7584
a00a6d2c:  b5 2d e0 10  sll  %l7, 0x10, %i2
a00a6d30:  40 00 c7 82  call  0xa00d8b38
a00a6d34:  39 14 7a e1  sethi  %hi(0x51eb8400), %i4
a00a6d38:  ad 2a 20 10  sll  %o0, 0x10, %l6
a00a6d3c:  93 35 a0 10  srl  %l6, 0x10, %o1
a00a6d40:  a8 17 21 1f  or  %i4, 0x11f, %l4
a00a6d44:  80 52 40 14  umul  %o1, %l4, %g0
a00a6d48:  97 40 00 00  rd  %y, %o3
a00a6d4c:  3b 33 33 33  sethi  %hi(0xcccccc00), %i5
a00a6d50:  94 17 60 cd  or  %i5, 0xcd, %o2	! 0xcccccccd
a00a6d54:  a3 32 e0 05  srl  %o3, 5, %l1
a00a6d58:  b6 5c 60 64  smul  %l1, 0x64, %i3
a00a6d5c:  80 52 40 0a  umul  %o1, %o2, %g0
a00a6d60:  b5 40 00 00  rd  %y, %i2
a00a6d64:  ab 36 a0 03  srl  %i2, 3, %l5
a00a6d68:  82 22 40 1b  sub  %o1, %i3, %g1
a00a6d6c:  b1 2d 60 02  sll  %l5, 2, %i0
a00a6d70:  a0 05 e0 07  add  %l7, 7, %l0
a00a6d74:  9f 28 60 10  sll  %g1, 0x10, %o7
a00a6d78:  a7 2c 20 10  sll  %l0, 0x10, %l3
a00a6d7c:  90 06 00 15  add  %i0, %l5, %o0
a00a6d80:  a5 2d e0 10  sll  %l7, 0x10, %l2
a00a6d84:  9b 33 e0 10  srl  %o7, 0x10, %o5
a00a6d88:  80 53 40 0a  umul  %o5, %o2, %g0
a00a6d8c:  b3 40 00 00  rd  %y, %i1
a00a6d90:  98 02 00 08  add  %o0, %o0, %o4
a00a6d94:  a9 34 a0 10  srl  %l2, 0x10, %l4
a00a6d98:  ab 34 e0 10  srl  %l3, 0x10, %l5
a00a6d9c:  b6 22 40 0c  sub  %o1, %o4, %i3
a00a6da0:  b9 36 60 03  srl  %i1, 3, %i4
a00a6da4:  ba 10 00 11  mov  %l1, %i5
a00a6da8:  a4 10 20 00  clr  %l2
a00a6dac:  a0 10 20 00  clr  %l0
a00a6db0:  27 00 00 2e  sethi  %hi(0xb800), %l3
a00a6db4:  a0 04 00 10  add  %l0, %l0, %l0
a00a6db8:  d4 0f bf f7  ldub  [ %fp + -9 ], %o2
a00a6dbc:  90 04 20 07  add  %l0, 7, %o0
a00a6dc0:  9a 04 00 0a  add  %l0, %o2, %o5
a00a6dc4:  92 0a 20 ff  and  %o0, 0xff, %o1
a00a6dc8:  a2 0b 60 ff  and  %o5, 0xff, %l1
a00a6dcc:  d2 23 a0 5c  st  %o1, [ %sp + 0x5c ]
a00a6dd0:  90 10 20 00  clr  %o0
a00a6dd4:  92 10 20 00  clr  %o1
a00a6dd8:  94 14 e0 0a  or  %l3, 0xa, %o2
a00a6ddc:  96 10 00 14  mov  %l4, %o3
a00a6de0:  98 10 00 11  mov  %l1, %o4
a00a6de4:  40 00 31 40  call  0xa00b32e4
a00a6de8:  9a 10 20 01  mov  1, %o5
a00a6dec:  98 04 20 08  add  %l0, 8, %o4
a00a6df0:  b2 0b 20 ff  and  %o4, 0xff, %i1
a00a6df4:  f2 23 a0 5c  st  %i1, [ %sp + 0x5c ]
a00a6df8:  98 10 00 11  mov  %l1, %o4
a00a6dfc:  90 10 20 00  clr  %o0
a00a6e00:  92 10 20 00  clr  %o1
a00a6e04:  94 14 e0 0a  or  %l3, 0xa, %o2
a00a6e08:  96 10 00 15  mov  %l5, %o3
a00a6e0c:  9a 10 20 01  mov  1, %o5
a00a6e10:  40 00 31 35  call  0xa00b32e4
a00a6e14:  a4 04 a0 01  inc  %l2
a00a6e18:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00a6e1c:  80 a4 20 01  cmp  %l0, 1
a00a6e20:  08 bf ff e6  bleu  0xa00a6db8
a00a6e24:  a0 04 00 10  add  %l0, %l0, %l0
a00a6e28:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00a6e2c:  b4 00 60 01  add  %g1, 1, %i2
a00a6e30:  a4 0e a0 ff  and  %i2, 0xff, %l2
a00a6e34:  b0 10 20 07  mov  7, %i0
a00a6e38:  96 10 00 14  mov  %l4, %o3
a00a6e3c:  90 10 20 00  clr  %o0
a00a6e40:  92 10 20 00  clr  %o1
a00a6e44:  94 10 28 a2  mov  0x8a2, %o2
a00a6e48:  98 10 00 12  mov  %l2, %o4
a00a6e4c:  9a 10 20 01  mov  1, %o5
a00a6e50:  40 00 31 25  call  0xa00b32e4
a00a6e54:  f0 23 a0 5c  st  %i0, [ %sp + 0x5c ]
a00a6e58:  9e 10 20 08  mov  8, %o7
a00a6e5c:  de 23 a0 5c  st  %o7, [ %sp + 0x5c ]
a00a6e60:  96 10 00 15  mov  %l5, %o3
a00a6e64:  98 10 00 12  mov  %l2, %o4
a00a6e68:  90 10 20 00  clr  %o0
a00a6e6c:  92 10 20 00  clr  %o1
a00a6e70:  94 10 28 a2  mov  0x8a2, %o2
a00a6e74:  40 00 31 1c  call  0xa00b32e4
a00a6e78:  9a 10 20 01  mov  1, %o5
a00a6e7c:  a7 35 a0 10  srl  %l6, 0x10, %l3
a00a6e80:  80 a4 e0 63  cmp  %l3, 0x63
a00a6e84:  08 80 02 35  bleu  0xa00a7758
a00a6e88:  ac 05 e0 01  add  %l7, 1, %l6
a00a6e8c:  aa 0f 60 ff  and  %i5, 0xff, %l5
a00a6e90:  96 05 40 15  add  %l5, %l5, %o3
a00a6e94:  ba 05 e0 01  add  %l7, 1, %i5
a00a6e98:  ac 02 c0 15  add  %o3, %l5, %l6
a00a6e9c:  ea 0f bf f7  ldub  [ %fp + -9 ], %l5
a00a6ea0:  a9 2f 60 10  sll  %i5, 0x10, %l4
a00a6ea4:  a6 10 20 00  clr  %l3
a00a6ea8:  a2 10 20 00  clr  %l1
a00a6eac:  90 0c e0 ff  and  %l3, 0xff, %o0
a00a6eb0:  a0 05 40 08  add  %l5, %o0, %l0
a00a6eb4:  19 00 00 2e  sethi  %hi(0xb800), %o4
a00a6eb8:  93 2c 20 10  sll  %l0, 0x10, %o1
a00a6ebc:  96 13 20 0a  or  %o4, 0xa, %o3
a00a6ec0:  b2 05 80 11  add  %l6, %l1, %i1
a00a6ec4:  93 32 60 10  srl  %o1, 0x10, %o1
a00a6ec8:  91 35 20 10  srl  %l4, 0x10, %o0
a00a6ecc:  94 10 20 02  mov  2, %o2
a00a6ed0:  40 02 7e ec  call  0xa0146a80
a00a6ed4:  98 10 20 00  clr  %o4
a00a6ed8:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00a6edc:  a4 06 40 19  add  %i1, %i1, %l2
a00a6ee0:  a2 10 20 00  clr  %l1
a00a6ee4:  ba 0c 60 ff  and  %l1, 0xff, %i5
a00a6ee8:  82 07 40 17  add  %i5, %l7, %g1
a00a6eec:  b0 04 80 11  add  %l2, %l1, %i0
a00a6ef0:  b4 00 60 01  add  %g1, 1, %i2
a00a6ef4:  94 06 20 30  add  %i0, 0x30, %o2
a00a6ef8:  9f 2e a0 10  sll  %i2, 0x10, %o7
a00a6efc:  98 0a a0 ff  and  %o2, 0xff, %o4
a00a6f00:  9a 10 20 00  clr  %o5
a00a6f04:  93 33 e0 10  srl  %o7, 0x10, %o1
a00a6f08:  90 10 20 00  clr  %o0
a00a6f0c:  95 34 20 10  srl  %l0, 0x10, %o2
a00a6f10:  40 02 7f 04  call  0xa0146b20
a00a6f14:  96 10 20 01  mov  1, %o3
a00a6f18:  a2 04 60 01  inc  %l1
a00a6f1c:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00a6f20:  80 a3 60 01  cmp  %o5, 1
a00a6f24:  08 bf ff f1  bleu  0xa00a6ee8
a00a6f28:  ba 0c 60 ff  and  %l1, 0xff, %i5
a00a6f2c:  a6 04 e0 01  inc  %l3
a00a6f30:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00a6f34:  80 a4 60 02  cmp  %l1, 2
a00a6f38:  08 bf ff de  bleu  0xa00a6eb0
a00a6f3c:  90 0c e0 ff  and  %l3, 0xff, %o0
a00a6f40:  a2 0f 20 ff  and  %i4, 0xff, %l1
a00a6f44:  a8 0e e0 ff  and  %i3, 0xff, %l4
a00a6f48:  a6 04 40 11  add  %l1, %l1, %l3
a00a6f4c:  b6 05 e0 03  add  %l7, 3, %i3
a00a6f50:  b8 05 00 14  add  %l4, %l4, %i4
a00a6f54:  b2 04 c0 11  add  %l3, %l1, %i1
a00a6f58:  b0 07 00 14  add  %i4, %l4, %i0
a00a6f5c:  ad 2e e0 10  sll  %i3, 0x10, %l6
a00a6f60:  b4 10 20 00  clr  %i2
a00a6f64:  a2 10 20 00  clr  %l1
a00a6f68:  90 0e a0 ff  and  %i2, 0xff, %o0
a00a6f6c:  98 05 40 08  add  %l5, %o0, %o4
a00a6f70:  97 2b 20 10  sll  %o4, 0x10, %o3
a00a6f74:  a1 32 e0 10  srl  %o3, 0x10, %l0
a00a6f78:  25 00 00 2e  sethi  %hi(0xb800), %l2
a00a6f7c:  96 14 a0 0a  or  %l2, 0xa, %o3	! 0xb80a
a00a6f80:  91 35 a0 10  srl  %l6, 0x10, %o0
a00a6f84:  92 10 00 10  mov  %l0, %o1
a00a6f88:  94 10 20 04  mov  4, %o2
a00a6f8c:  40 02 7e bd  call  0xa0146a80
a00a6f90:  98 10 20 00  clr  %o4
a00a6f94:  ba 06 00 11  add  %i0, %l1, %i5
a00a6f98:  82 06 40 11  add  %i1, %l1, %g1
a00a6f9c:  a4 10 00 10  mov  %l0, %l2
a00a6fa0:  a8 00 40 01  add  %g1, %g1, %l4
a00a6fa4:  a6 07 40 1d  add  %i5, %i5, %l3
a00a6fa8:  a2 10 20 00  clr  %l1
a00a6fac:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a6fb0:  b8 04 00 17  add  %l0, %l7, %i4
a00a6fb4:  96 05 00 11  add  %l4, %l1, %o3
a00a6fb8:  98 07 20 03  add  %i4, 3, %o4
a00a6fbc:  83 2b 20 10  sll  %o4, 0x10, %g1
a00a6fc0:  ba 02 e0 30  add  %o3, 0x30, %i5
a00a6fc4:  93 30 60 10  srl  %g1, 0x10, %o1
a00a6fc8:  98 0f 60 ff  and  %i5, 0xff, %o4
a00a6fcc:  90 10 20 00  clr  %o0
a00a6fd0:  94 10 00 12  mov  %l2, %o2
a00a6fd4:  96 10 20 01  mov  1, %o3
a00a6fd8:  40 02 7e d2  call  0xa0146b20
a00a6fdc:  9a 10 20 00  clr  %o5
a00a6fe0:  9e 04 c0 11  add  %l3, %l1, %o7
a00a6fe4:  b6 07 20 05  add  %i4, 5, %i3
a00a6fe8:  9a 03 e0 30  add  %o7, 0x30, %o5
a00a6fec:  95 2e e0 10  sll  %i3, 0x10, %o2
a00a6ff0:  93 32 a0 10  srl  %o2, 0x10, %o1
a00a6ff4:  98 0b 60 ff  and  %o5, 0xff, %o4
a00a6ff8:  90 10 20 00  clr  %o0
a00a6ffc:  94 10 00 12  mov  %l2, %o2
a00a7000:  96 10 20 01  mov  1, %o3
a00a7004:  40 02 7e c7  call  0xa0146b20
a00a7008:  9a 10 20 00  clr  %o5
a00a700c:  a2 04 60 01  inc  %l1
a00a7010:  92 0c 60 ff  and  %l1, 0xff, %o1
a00a7014:  80 a2 60 01  cmp  %o1, 1
a00a7018:  28 bf ff e6  bleu,a   0xa00a6fb0
a00a701c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a7020:  b4 06 a0 01  inc  %i2
a00a7024:  a2 0e a0 ff  and  %i2, 0xff, %l1
a00a7028:  80 a4 60 02  cmp  %l1, 2
a00a702c:  08 bf ff d0  bleu  0xa00a6f6c
a00a7030:  90 0e a0 ff  and  %i2, 0xff, %o0
a00a7034:  b0 10 20 01  mov  1, %i0
a00a7038:  40 02 7f 62  call  0xa0146dc0
a00a703c:  93 e8 20 00  restore  %g0, 0, %o1
a00a7040:  40 00 38 10  call  0xa00b5080
a00a7044:  b3 2c 60 10  sll  %l1, 0x10, %i1
a00a7048:  40 00 38 24  call  0xa00b50d8
a00a704c:  90 10 20 03  mov  3, %o0
a00a7050:  91 36 60 10  srl  %i1, 0x10, %o0
a00a7054:  92 10 20 3d  mov  0x3d, %o1
a00a7058:  40 00 38 a8  call  0xa00b52f8
a00a705c:  94 10 28 02  mov  0x802, %o2
a00a7060:  90 10 20 00  clr  %o0
a00a7064:  92 10 20 00  clr  %o1
a00a7068:  40 02 7d 39  call  0xa014654c
a00a706c:  94 10 20 00  clr  %o2
a00a7070:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a7074:  80 a6 20 02  cmp  %i0, 2
a00a7078:  12 bf ff 15  bne  0xa00a6ccc
a00a707c:  80 a6 20 01  cmp  %i0, 1
a00a7080:  a3 2c 20 10  sll  %l0, 0x10, %l1
a00a7084:  91 34 60 10  srl  %l1, 0x10, %o0
a00a7088:  92 10 20 13  mov  0x13, %o1
a00a708c:  7f ff fa 1f  call  0xa00a5908
a00a7090:  94 10 20 01  mov  1, %o2
a00a7094:  90 10 20 00  clr  %o0
a00a7098:  40 02 7f 4a  call  0xa0146dc0
a00a709c:  92 10 20 01  mov  1, %o1
a00a70a0:  90 10 20 04  mov  4, %o0
a00a70a4:  40 02 7c 7d  call  0xa0146298
a00a70a8:  92 10 20 01  mov  1, %o1
a00a70ac:  90 10 20 18  mov  0x18, %o0
a00a70b0:  92 10 20 24  mov  0x24, %o1
a00a70b4:  40 02 7c a8  call  0xa0146354
a00a70b8:  94 10 20 01  mov  1, %o2
a00a70bc:  90 10 20 08  mov  8, %o0
a00a70c0:  92 10 20 00  clr  %o1
a00a70c4:  40 02 7e df  call  0xa0146c40
a00a70c8:  94 10 20 01  mov  1, %o2
a00a70cc:  96 10 20 00  clr  %o3
a00a70d0:  98 10 20 01  mov  1, %o4
a00a70d4:  90 10 20 00  clr  %o0
a00a70d8:  92 10 20 00  clr  %o1
a00a70dc:  40 02 7d 5b  call  0xa0146648
a00a70e0:  94 10 20 00  clr  %o2
a00a70e4:  90 10 20 04  mov  4, %o0
a00a70e8:  92 10 20 03  mov  3, %o1
a00a70ec:  40 02 7c 14  call  0xa014613c
a00a70f0:  94 10 20 01  mov  1, %o2
a00a70f4:  a0 16 e2 90  or  %i3, 0x290, %l0
a00a70f8:  94 10 20 01  mov  1, %o2
a00a70fc:  d0 0c 20 0d  ldub  [ %l0 + 0xd ], %o0
a00a7100:  40 02 7d 06  call  0xa0146518
a00a7104:  d2 0c 20 0e  ldub  [ %l0 + 0xe ], %o1
a00a7108:  92 10 20 01  mov  1, %o1
a00a710c:  40 02 7e 69  call  0xa0146ab0
a00a7110:  90 10 27 92  mov  0x792, %o0
a00a7114:  40 02 7b fd  call  0xa0146108
a00a7118:  90 10 20 01  mov  1, %o0
a00a711c:  d0 14 21 ac  lduh  [ %l0 + 0x1ac ], %o0
a00a7120:  d2 14 21 ae  lduh  [ %l0 + 0x1ae ], %o1
a00a7124:  40 02 7d 0a  call  0xa014654c
a00a7128:  94 10 20 01  mov  1, %o2
a00a712c:  e6 0c 21 90  ldub  [ %l0 + 0x190 ], %l3
a00a7130:  80 a4 e0 00  cmp  %l3, 0
a00a7134:  02 80 01 30  be  0xa00a75f4
a00a7138:  96 10 00 13  mov  %l3, %o3
a00a713c:  96 0a e0 ff  and  %o3, 0xff, %o3
a00a7140:  25 0a aa aa  sethi  %hi(0x2aaaa800), %l2
a00a7144:  92 02 ff ff  add  %o3, -1, %o1
a00a7148:  a0 14 a2 ab  or  %l2, 0x2ab, %l0
a00a714c:  80 5a 40 10  smul  %o1, %l0, %g0
a00a7150:  9b 40 00 00  rd  %y, %o5
a00a7154:  9f 3a 60 1f  sra  %o1, 0x1f, %o7
a00a7158:  82 23 40 0f  sub  %o5, %o7, %g1
a00a715c:  94 00 40 01  add  %g1, %g1, %o2
a00a7160:  90 02 80 01  add  %o2, %g1, %o0
a00a7164:  98 02 00 08  add  %o0, %o0, %o4
a00a7168:  96 a2 40 0c  subcc  %o1, %o4, %o3
a00a716c:  02 80 00 0c  be  0xa00a719c
a00a7170:  80 a2 e0 01  cmp  %o3, 1
a00a7174:  02 80 01 b6  be  0xa00a784c
a00a7178:  80 a2 e0 02  cmp  %o3, 2
a00a717c:  02 80 01 b8  be  0xa00a785c
a00a7180:  80 a2 e0 03  cmp  %o3, 3
a00a7184:  02 80 01 ba  be  0xa00a786c
a00a7188:  80 a2 e0 04  cmp  %o3, 4
a00a718c:  02 80 01 bc  be  0xa00a787c
a00a7190:  80 a2 e0 05  cmp  %o3, 5
a00a7194:  02 80 01 9b  be  0xa00a7800
a00a7198:  01 00 00 00  nop
a00a719c:  7f ff ee 60  call  0xa00a2b1c
a00a71a0:  a8 16 e2 90  or  %i3, 0x290, %l4
a00a71a4:  c2 0d 21 7b  ldub  [ %l4 + 0x17b ], %g1
a00a71a8:  80 a0 60 01  cmp  %g1, 1
a00a71ac:  02 80 01 5c  be  0xa00a771c
a00a71b0:  80 a0 60 00  cmp  %g1, 0
a00a71b4:  a0 10 20 00  clr  %l0
a00a71b8:  12 80 01 12  bne  0xa00a7600
a00a71bc:  23 00 00 05  sethi  %hi(0x1400), %l1
a00a71c0:  a2 04 64 00  add  %l1, 0x400, %l1	! 0x1800
a00a71c4:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a71c8:  90 10 20 00  clr  %o0
a00a71cc:  94 10 20 04  mov  4, %o2
a00a71d0:  96 14 60 02  or  %l1, 2, %o3
a00a71d4:  98 10 20 01  mov  1, %o4
a00a71d8:  40 02 7e 2a  call  0xa0146a80
a00a71dc:  a0 04 20 01  inc  %l0
a00a71e0:  b8 0c 20 ff  and  %l0, 0xff, %i4
a00a71e4:  80 a7 20 02  cmp  %i4, 2
a00a71e8:  08 bf ff f8  bleu  0xa00a71c8
a00a71ec:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a71f0:  a4 10 20 00  clr  %l2
a00a71f4:  98 10 20 00  clr  %o4
a00a71f8:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00a71fc:  b3 2c 60 10  sll  %l1, 0x10, %i1
a00a7200:  a3 2b 20 02  sll  %o4, 2, %l1
a00a7204:  a0 10 20 00  clr  %l0
a00a7208:  98 04 40 10  add  %l1, %l0, %o4
a00a720c:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a7210:  98 0b 20 ff  and  %o4, 0xff, %o4
a00a7214:  90 10 20 00  clr  %o0
a00a7218:  95 36 60 10  srl  %i1, 0x10, %o2
a00a721c:  96 10 20 01  mov  1, %o3
a00a7220:  40 02 7e 40  call  0xa0146b20
a00a7224:  9a 10 20 01  mov  1, %o5
a00a7228:  a0 04 20 01  inc  %l0
a00a722c:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a7230:  80 a2 60 03  cmp  %o1, 3
a00a7234:  08 bf ff f7  bleu  0xa00a7210
a00a7238:  98 04 40 10  add  %l1, %l0, %o4
a00a723c:  a4 04 a0 01  inc  %l2
a00a7240:  98 0c a0 ff  and  %l2, 0xff, %o4
a00a7244:  80 a3 20 02  cmp  %o4, 2
a00a7248:  28 bf ff ed  bleu,a   0xa00a71fc
a00a724c:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00a7250:  90 16 e2 90  or  %i3, 0x290, %o0
a00a7254:  e6 2a 21 90  stb  %l3, [ %o0 + 0x190 ]
a00a7258:  90 10 20 01  mov  1, %o0
a00a725c:  40 02 7e d9  call  0xa0146dc0
a00a7260:  92 10 20 01  mov  1, %o1
a00a7264:  82 0e a0 ff  and  %i2, 0xff, %g1
a00a7268:  80 a0 60 01  cmp  %g1, 1
a00a726c:  02 80 01 10  be  0xa00a76ac
a00a7270:  a8 05 60 0b  add  %l5, 0xb, %l4
a00a7274:  a5 2d 20 10  sll  %l4, 0x10, %l2
a00a7278:  ad 2d 60 10  sll  %l5, 0x10, %l6
a00a727c:  a9 35 a0 10  srl  %l6, 0x10, %l4
a00a7280:  ad 34 a0 10  srl  %l2, 0x10, %l6
a00a7284:  a4 10 20 00  clr  %l2
a00a7288:  a0 10 20 00  clr  %l0
a00a728c:  27 00 00 2e  sethi  %hi(0xb800), %l3
a00a7290:  a0 04 00 10  add  %l0, %l0, %l0
a00a7294:  90 04 20 07  add  %l0, 7, %o0
a00a7298:  98 0a 20 ff  and  %o0, 0xff, %o4
a00a729c:  a2 04 00 1d  add  %l0, %i5, %l1
a00a72a0:  b8 0c 60 ff  and  %l1, 0xff, %i4
a00a72a4:  d8 23 a0 5c  st  %o4, [ %sp + 0x5c ]
a00a72a8:  90 10 20 00  clr  %o0
a00a72ac:  92 10 20 00  clr  %o1
a00a72b0:  94 14 e0 0a  or  %l3, 0xa, %o2
a00a72b4:  96 10 00 14  mov  %l4, %o3
a00a72b8:  98 10 00 1c  mov  %i4, %o4
a00a72bc:  40 00 30 0a  call  0xa00b32e4
a00a72c0:  9a 10 20 01  mov  1, %o5
a00a72c4:  92 04 20 08  add  %l0, 8, %o1
a00a72c8:  b2 0a 60 ff  and  %o1, 0xff, %i1
a00a72cc:  f2 23 a0 5c  st  %i1, [ %sp + 0x5c ]
a00a72d0:  98 10 00 1c  mov  %i4, %o4
a00a72d4:  90 10 20 00  clr  %o0
a00a72d8:  92 10 20 00  clr  %o1
a00a72dc:  94 14 e0 0a  or  %l3, 0xa, %o2
a00a72e0:  96 10 00 16  mov  %l6, %o3
a00a72e4:  9a 10 20 01  mov  1, %o5
a00a72e8:  40 00 2f ff  call  0xa00b32e4
a00a72ec:  a4 04 a0 01  inc  %l2
a00a72f0:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00a72f4:  80 a4 20 01  cmp  %l0, 1
a00a72f8:  08 bf ff e7  bleu  0xa00a7294
a00a72fc:  a0 04 00 10  add  %l0, %l0, %l0
a00a7300:  9e 07 60 01  add  %i5, 1, %o7
a00a7304:  9a 10 20 07  mov  7, %o5
a00a7308:  a4 0b e0 ff  and  %o7, 0xff, %l2
a00a730c:  da 23 a0 5c  st  %o5, [ %sp + 0x5c ]
a00a7310:  96 10 00 14  mov  %l4, %o3
a00a7314:  98 10 00 12  mov  %l2, %o4
a00a7318:  90 10 20 00  clr  %o0
a00a731c:  92 10 20 00  clr  %o1
a00a7320:  94 10 28 a2  mov  0x8a2, %o2
a00a7324:  40 00 2f f0  call  0xa00b32e4
a00a7328:  9a 10 20 01  mov  1, %o5
a00a732c:  82 10 20 08  mov  8, %g1
a00a7330:  96 10 00 16  mov  %l6, %o3
a00a7334:  98 10 00 12  mov  %l2, %o4
a00a7338:  94 10 28 a2  mov  0x8a2, %o2
a00a733c:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a00a7340:  90 10 20 00  clr  %o0
a00a7344:  92 10 20 00  clr  %o1
a00a7348:  9a 10 20 01  mov  1, %o5
a00a734c:  40 00 2f e6  call  0xa00b32e4
a00a7350:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00a7354:  b8 0f 60 ff  and  %i5, 0xff, %i4
a00a7358:  a8 14 e2 90  or  %l3, 0x290, %l4
a00a735c:  15 33 33 33  sethi  %hi(0xcccccc00), %o2
a00a7360:  a6 12 a0 cd  or  %o2, 0xcd, %l3	! 0xcccccccd
a00a7364:  ac 10 20 00  clr  %l6
a00a7368:  a4 10 20 00  clr  %l2
a00a736c:  ba 05 60 01  add  %l5, 1, %i5
a00a7370:  90 0d a0 ff  and  %l6, 0xff, %o0
a00a7374:  98 07 00 08  add  %i4, %o0, %o4
a00a7378:  93 2b 20 10  sll  %o4, 0x10, %o1
a00a737c:  a1 32 60 10  srl  %o1, 0x10, %l0
a00a7380:  b3 2f 60 10  sll  %i5, 0x10, %i1
a00a7384:  17 00 00 2e  sethi  %hi(0xb800), %o3
a00a7388:  91 36 60 10  srl  %i1, 0x10, %o0
a00a738c:  96 12 e0 0a  or  %o3, 0xa, %o3
a00a7390:  92 10 00 10  mov  %l0, %o1
a00a7394:  94 10 20 0a  mov  0xa, %o2
a00a7398:  40 02 7d ba  call  0xa0146a80
a00a739c:  98 10 20 00  clr  %o4
a00a73a0:  b2 10 00 10  mov  %l0, %i1
a00a73a4:  a2 10 20 00  clr  %l1
a00a73a8:  c2 0d 21 a1  ldub  [ %l4 + 0x1a1 ], %g1
a00a73ac:  80 50 40 13  umul  %g1, %l3, %g0
a00a73b0:  97 40 00 00  rd  %y, %o3
a00a73b4:  9f 32 e0 03  srl  %o3, 3, %o7
a00a73b8:  9a 0b e0 ff  and  %o7, 0xff, %o5
a00a73bc:  94 03 40 0d  add  %o5, %o5, %o2
a00a73c0:  90 02 80 0d  add  %o2, %o5, %o0
a00a73c4:  98 02 00 12  add  %o0, %l2, %o4
a00a73c8:  92 03 00 0c  add  %o4, %o4, %o1
a00a73cc:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a73d0:  a0 04 00 15  add  %l0, %l5, %l0
a00a73d4:  96 02 40 11  add  %o1, %l1, %o3
a00a73d8:  82 04 20 01  add  %l0, 1, %g1
a00a73dc:  9a 02 e0 30  add  %o3, 0x30, %o5
a00a73e0:  9f 28 60 10  sll  %g1, 0x10, %o7
a00a73e4:  98 0b 60 ff  and  %o5, 0xff, %o4
a00a73e8:  93 33 e0 10  srl  %o7, 0x10, %o1
a00a73ec:  90 10 20 00  clr  %o0
a00a73f0:  94 10 00 19  mov  %i1, %o2
a00a73f4:  96 10 20 01  mov  1, %o3
a00a73f8:  40 02 7d ca  call  0xa0146b20
a00a73fc:  9a 10 20 00  clr  %o5
a00a7400:  d6 0d 21 a1  ldub  [ %l4 + 0x1a1 ], %o3
a00a7404:  80 52 c0 13  umul  %o3, %l3, %g0
a00a7408:  95 40 00 00  rd  %y, %o2
a00a740c:  91 32 a0 03  srl  %o2, 3, %o0
a00a7410:  99 2a 20 02  sll  %o0, 2, %o4
a00a7414:  92 03 00 08  add  %o4, %o0, %o1
a00a7418:  82 02 40 09  add  %o1, %o1, %g1
a00a741c:  9e 22 c0 01  sub  %o3, %g1, %o7
a00a7420:  9a 0b e0 ff  and  %o7, 0xff, %o5
a00a7424:  94 03 40 0d  add  %o5, %o5, %o2
a00a7428:  90 02 80 0d  add  %o2, %o5, %o0
a00a742c:  98 02 00 12  add  %o0, %l2, %o4
a00a7430:  92 03 00 0c  add  %o4, %o4, %o1
a00a7434:  82 02 40 11  add  %o1, %l1, %g1
a00a7438:  9a 00 60 30  add  %g1, 0x30, %o5
a00a743c:  96 04 20 03  add  %l0, 3, %o3
a00a7440:  9f 2a e0 10  sll  %o3, 0x10, %o7
a00a7444:  98 0b 60 ff  and  %o5, 0xff, %o4
a00a7448:  93 33 e0 10  srl  %o7, 0x10, %o1
a00a744c:  90 10 20 00  clr  %o0
a00a7450:  94 10 00 19  mov  %i1, %o2
a00a7454:  96 10 20 01  mov  1, %o3
a00a7458:  40 02 7d b2  call  0xa0146b20
a00a745c:  9a 10 20 00  clr  %o5
a00a7460:  94 04 80 12  add  %l2, %l2, %o2
a00a7464:  98 02 80 11  add  %o2, %l1, %o4
a00a7468:  90 04 20 05  add  %l0, 5, %o0
a00a746c:  96 03 20 6c  add  %o4, 0x6c, %o3
a00a7470:  98 0a e0 ff  and  %o3, 0xff, %o4
a00a7474:  93 2a 20 10  sll  %o0, 0x10, %o1
a00a7478:  93 32 60 10  srl  %o1, 0x10, %o1
a00a747c:  90 10 20 00  clr  %o0
a00a7480:  94 10 00 19  mov  %i1, %o2
a00a7484:  96 10 20 01  mov  1, %o3
a00a7488:  40 02 7d a6  call  0xa0146b20
a00a748c:  9a 10 20 00  clr  %o5
a00a7490:  c2 0d 21 a2  ldub  [ %l4 + 0x1a2 ], %g1
a00a7494:  80 50 40 13  umul  %g1, %l3, %g0
a00a7498:  9f 40 00 00  rd  %y, %o7
a00a749c:  9b 33 e0 03  srl  %o7, 3, %o5
a00a74a0:  94 0b 60 ff  and  %o5, 0xff, %o2
a00a74a4:  90 02 80 0a  add  %o2, %o2, %o0
a00a74a8:  98 02 00 0a  add  %o0, %o2, %o4
a00a74ac:  92 03 00 12  add  %o4, %l2, %o1
a00a74b0:  96 02 40 09  add  %o1, %o1, %o3
a00a74b4:  9e 02 c0 11  add  %o3, %l1, %o7
a00a74b8:  82 04 20 07  add  %l0, 7, %g1
a00a74bc:  9b 28 60 10  sll  %g1, 0x10, %o5
a00a74c0:  94 03 e0 30  add  %o7, 0x30, %o2
a00a74c4:  93 33 60 10  srl  %o5, 0x10, %o1
a00a74c8:  98 0a a0 ff  and  %o2, 0xff, %o4
a00a74cc:  90 10 20 00  clr  %o0
a00a74d0:  94 10 00 19  mov  %i1, %o2
a00a74d4:  96 10 20 01  mov  1, %o3
a00a74d8:  40 02 7d 92  call  0xa0146b20
a00a74dc:  9a 10 20 00  clr  %o5
a00a74e0:  de 0d 21 a2  ldub  [ %l4 + 0x1a2 ], %o7
a00a74e4:  80 53 c0 13  umul  %o7, %l3, %g0
a00a74e8:  91 40 00 00  rd  %y, %o0
a00a74ec:  99 32 20 03  srl  %o0, 3, %o4
a00a74f0:  93 2b 20 02  sll  %o4, 2, %o1
a00a74f4:  96 02 40 0c  add  %o1, %o4, %o3
a00a74f8:  82 02 c0 0b  add  %o3, %o3, %g1
a00a74fc:  9a 23 c0 01  sub  %o7, %g1, %o5
a00a7500:  94 0b 60 ff  and  %o5, 0xff, %o2
a00a7504:  90 02 80 0a  add  %o2, %o2, %o0
a00a7508:  98 02 00 0a  add  %o0, %o2, %o4
a00a750c:  92 03 00 12  add  %o4, %l2, %o1
a00a7510:  96 02 40 09  add  %o1, %o1, %o3
a00a7514:  a0 04 20 09  add  %l0, 9, %l0
a00a7518:  9e 02 c0 11  add  %o3, %l1, %o7
a00a751c:  9b 2c 20 10  sll  %l0, 0x10, %o5
a00a7520:  82 03 e0 30  add  %o7, 0x30, %g1
a00a7524:  93 33 60 10  srl  %o5, 0x10, %o1
a00a7528:  94 10 00 19  mov  %i1, %o2
a00a752c:  98 08 60 ff  and  %g1, 0xff, %o4
a00a7530:  90 10 20 00  clr  %o0
a00a7534:  96 10 20 01  mov  1, %o3
a00a7538:  40 02 7d 7a  call  0xa0146b20
a00a753c:  9a 10 20 00  clr  %o5
a00a7540:  a2 04 60 01  inc  %l1
a00a7544:  94 0c 60 ff  and  %l1, 0xff, %o2
a00a7548:  80 a2 a0 01  cmp  %o2, 1
a00a754c:  28 bf ff 98  bleu,a   0xa00a73ac
a00a7550:  c2 0d 21 a1  ldub  [ %l4 + 0x1a1 ], %g1
a00a7554:  ac 05 a0 01  inc  %l6
a00a7558:  a4 0d a0 ff  and  %l6, 0xff, %l2
a00a755c:  80 a4 a0 02  cmp  %l2, 2
a00a7560:  08 bf ff 85  bleu  0xa00a7374
a00a7564:  90 0d a0 ff  and  %l6, 0xff, %o0
a00a7568:  10 bf fd db  b  0xa00a6cd4
a00a756c:  80 a6 20 02  cmp  %i0, 2
a00a7570:  90 10 20 00  clr  %o0
a00a7574:  40 02 7e 13  call  0xa0146dc0
a00a7578:  92 10 20 00  clr  %o1
a00a757c:  10 bf fd d1  b  0xa00a6cc0
a00a7580:  80 a6 20 02  cmp  %i0, 2
a00a7584:  e6 0f bf f7  ldub  [ %fp + -9 ], %l3
a00a7588:  a5 36 a0 10  srl  %i2, 0x10, %l2
a00a758c:  a2 10 20 00  clr  %l1
a00a7590:  b8 0c 60 ff  and  %l1, 0xff, %i4
a00a7594:  a8 04 c0 1c  add  %l3, %i4, %l4
a00a7598:  ad 2d 20 10  sll  %l4, 0x10, %l6
a00a759c:  bb 35 a0 10  srl  %l6, 0x10, %i5
a00a75a0:  90 10 00 12  mov  %l2, %o0
a00a75a4:  92 10 00 1d  mov  %i5, %o1
a00a75a8:  94 10 20 08  mov  8, %o2
a00a75ac:  96 10 28 02  mov  0x802, %o3
a00a75b0:  40 02 7d 34  call  0xa0146a80
a00a75b4:  98 10 20 00  clr  %o4
a00a75b8:  94 10 00 1d  mov  %i5, %o2
a00a75bc:  90 10 20 00  clr  %o0
a00a75c0:  92 10 00 12  mov  %l2, %o1
a00a75c4:  96 10 20 08  mov  8, %o3
a00a75c8:  98 10 20 00  clr  %o4
a00a75cc:  9a 10 20 00  clr  %o5
a00a75d0:  40 02 7d 54  call  0xa0146b20
a00a75d4:  a2 04 60 01  inc  %l1
a00a75d8:  ae 0c 60 ff  and  %l1, 0xff, %l7
a00a75dc:  80 a5 e0 02  cmp  %l7, 2
a00a75e0:  08 bf ff ed  bleu  0xa00a7594
a00a75e4:  b8 0c 60 ff  and  %l1, 0xff, %i4
a00a75e8:  b0 10 20 01  mov  1, %i0
a00a75ec:  40 02 7d f5  call  0xa0146dc0
a00a75f0:  93 e8 20 00  restore  %g0, 0, %o1
a00a75f4:  96 10 20 01  mov  1, %o3
a00a75f8:  10 bf fe d1  b  0xa00a713c
a00a75fc:  d6 2c 21 90  stb  %o3, [ %l0 + 0x190 ]
a00a7600:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a7604:  90 10 20 00  clr  %o0
a00a7608:  94 10 20 04  mov  4, %o2
a00a760c:  96 14 63 02  or  %l1, 0x302, %o3
a00a7610:  98 10 20 01  mov  1, %o4
a00a7614:  40 02 7d 1b  call  0xa0146a80
a00a7618:  a0 04 20 01  inc  %l0
a00a761c:  b2 0c 20 ff  and  %l0, 0xff, %i1
a00a7620:  80 a6 60 02  cmp  %i1, 2
a00a7624:  08 bf ff f8  bleu  0xa00a7604
a00a7628:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a762c:  40 00 4a d6  call  0xa00ba184
a00a7630:  90 10 20 01  mov  1, %o0
a00a7634:  10 bf fe f0  b  0xa00a71f4
a00a7638:  a4 10 20 00  clr  %l2
a00a763c:  40 02 83 50  call  0xa014837c
a00a7640:  90 10 20 00  clr  %o0
a00a7644:  95 2a 20 10  sll  %o0, 0x10, %o2
a00a7648:  91 32 a0 10  srl  %o2, 0x10, %o0
a00a764c:  13 0a aa aa  sethi  %hi(0x2aaaa800), %o1
a00a7650:  aa 02 3e b0  add  %o0, -336, %l5
a00a7654:  98 12 62 ab  or  %o1, 0x2ab, %o4
a00a7658:  80 5d 40 0c  smul  %l5, %o4, %g0
a00a765c:  b9 40 00 00  rd  %y, %i4
a00a7660:  ad 3f 20 02  sra  %i4, 2, %l6
a00a7664:  a9 3d 60 1f  sra  %l5, 0x1f, %l4
a00a7668:  10 bf fd 83  b  0xa00a6c74
a00a766c:  aa 25 80 14  sub  %l6, %l4, %l5
a00a7670:  40 02 83 43  call  0xa014837c
a00a7674:  90 10 20 00  clr  %o0
a00a7678:  af 2a 20 10  sll  %o0, 0x10, %l7
a00a767c:  ad 35 e0 10  srl  %l7, 0x10, %l6
a00a7680:  2b 0a aa aa  sethi  %hi(0x2aaaa800), %l5
a00a7684:  a4 05 bf 10  add  %l6, -240, %l2
a00a7688:  a8 15 62 ab  or  %l5, 0x2ab, %l4
a00a768c:  80 5c 80 14  smul  %l2, %l4, %g0
a00a7690:  a7 40 00 00  rd  %y, %l3
a00a7694:  a1 3c e0 02  sra  %l3, 2, %l0
a00a7698:  9f 3c a0 1f  sra  %l2, 0x1f, %o7
a00a769c:  82 10 20 02  mov  2, %g1
a00a76a0:  ae 24 00 0f  sub  %l0, %o7, %l7
a00a76a4:  10 bf fd 60  b  0xa00a6c24
a00a76a8:  c2 2f bf f7  stb  %g1, [ %fp + -9 ]
a00a76ac:  9b 2d 60 10  sll  %l5, 0x10, %o5
a00a76b0:  a6 0f 60 ff  and  %i5, 0xff, %l3
a00a76b4:  a5 33 60 10  srl  %o5, 0x10, %l2
a00a76b8:  a2 10 20 00  clr  %l1
a00a76bc:  96 0c 60 ff  and  %l1, 0xff, %o3
a00a76c0:  a0 04 c0 0b  add  %l3, %o3, %l0
a00a76c4:  9f 2c 20 10  sll  %l0, 0x10, %o7
a00a76c8:  bb 33 e0 10  srl  %o7, 0x10, %i5
a00a76cc:  90 10 00 12  mov  %l2, %o0
a00a76d0:  92 10 00 1d  mov  %i5, %o1
a00a76d4:  94 10 20 0c  mov  0xc, %o2
a00a76d8:  96 10 28 02  mov  0x802, %o3
a00a76dc:  40 02 7c e9  call  0xa0146a80
a00a76e0:  98 10 20 00  clr  %o4
a00a76e4:  94 10 00 1d  mov  %i5, %o2
a00a76e8:  90 10 20 00  clr  %o0
a00a76ec:  92 10 00 12  mov  %l2, %o1
a00a76f0:  96 10 20 0c  mov  0xc, %o3
a00a76f4:  98 10 20 00  clr  %o4
a00a76f8:  9a 10 20 00  clr  %o5
a00a76fc:  40 02 7d 09  call  0xa0146b20
a00a7700:  a2 04 60 01  inc  %l1
a00a7704:  aa 0c 60 ff  and  %l1, 0xff, %l5
a00a7708:  80 a5 60 02  cmp  %l5, 2
a00a770c:  08 bf ff ed  bleu  0xa00a76c0
a00a7710:  96 0c 60 ff  and  %l1, 0xff, %o3
a00a7714:  10 bf fd 70  b  0xa00a6cd4
a00a7718:  80 a6 20 02  cmp  %i0, 2
a00a771c:  a0 10 20 00  clr  %l0
a00a7720:  23 00 00 05  sethi  %hi(0x1400), %l1
a00a7724:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a7728:  90 10 20 00  clr  %o0
a00a772c:  94 10 20 04  mov  4, %o2
a00a7730:  96 14 63 02  or  %l1, 0x302, %o3
a00a7734:  98 10 20 01  mov  1, %o4
a00a7738:  40 02 7c d2  call  0xa0146a80
a00a773c:  a0 04 20 01  inc  %l0
a00a7740:  ac 0c 20 ff  and  %l0, 0xff, %l6
a00a7744:  80 a5 a0 02  cmp  %l6, 2
a00a7748:  08 bf ff f8  bleu  0xa00a7728
a00a774c:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a7750:  10 bf fe a9  b  0xa00a71f4
a00a7754:  a4 10 20 00  clr  %l2
a00a7758:  ea 0f bf f7  ldub  [ %fp + -9 ], %l5
a00a775c:  a9 2d a0 10  sll  %l6, 0x10, %l4
a00a7760:  a6 10 20 00  clr  %l3
a00a7764:  a2 10 20 00  clr  %l1
a00a7768:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00a776c:  a4 05 40 10  add  %l5, %l0, %l2
a00a7770:  b3 2c a0 10  sll  %l2, 0x10, %i1
a00a7774:  17 00 00 2e  sethi  %hi(0xb800), %o3
a00a7778:  a1 2c a0 10  sll  %l2, 0x10, %l0
a00a777c:  93 36 60 10  srl  %i1, 0x10, %o1
a00a7780:  96 12 e3 0a  or  %o3, 0x30a, %o3
a00a7784:  91 35 20 10  srl  %l4, 0x10, %o0
a00a7788:  94 10 20 03  mov  3, %o2
a00a778c:  98 10 20 00  clr  %o4
a00a7790:  40 02 7c bc  call  0xa0146a80
a00a7794:  a4 04 40 11  add  %l1, %l1, %l2
a00a7798:  a2 10 20 00  clr  %l1
a00a779c:  b0 0c 60 ff  and  %l1, 0xff, %i0
a00a77a0:  9a 04 80 11  add  %l2, %l1, %o5
a00a77a4:  9e 06 00 17  add  %i0, %l7, %o7
a00a77a8:  94 03 e0 01  add  %o7, 1, %o2
a00a77ac:  90 03 60 30  add  %o5, 0x30, %o0
a00a77b0:  98 0a 20 ff  and  %o0, 0xff, %o4
a00a77b4:  93 2a a0 10  sll  %o2, 0x10, %o1
a00a77b8:  93 32 60 10  srl  %o1, 0x10, %o1
a00a77bc:  90 10 20 00  clr  %o0
a00a77c0:  95 34 20 10  srl  %l0, 0x10, %o2
a00a77c4:  96 10 20 01  mov  1, %o3
a00a77c8:  40 02 7c d6  call  0xa0146b20
a00a77cc:  9a 10 20 00  clr  %o5
a00a77d0:  a2 04 60 01  inc  %l1
a00a77d4:  98 0c 60 ff  and  %l1, 0xff, %o4
a00a77d8:  80 a3 20 01  cmp  %o4, 1
a00a77dc:  08 bf ff f1  bleu  0xa00a77a0
a00a77e0:  b0 0c 60 ff  and  %l1, 0xff, %i0
a00a77e4:  a6 04 e0 01  inc  %l3
a00a77e8:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00a77ec:  80 a4 60 02  cmp  %l1, 2
a00a77f0:  08 bf ff df  bleu  0xa00a776c
a00a77f4:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00a77f8:  10 bf fd d3  b  0xa00a6f44
a00a77fc:  a2 0f 20 ff  and  %i4, 0xff, %l1
a00a7800:  7f ff ec ef  call  0xa00a2bbc
a00a7804:  a8 16 e2 90  or  %i3, 0x290, %l4
a00a7808:  10 bf fe 68  b  0xa00a71a8
a00a780c:  c2 0d 21 7b  ldub  [ %l4 + 0x17b ], %g1
a00a7810:  40 02 82 db  call  0xa014837c
a00a7814:  90 10 20 00  clr  %o0
a00a7818:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00a781c:  03 0a aa aa  sethi  %hi(0x2aaaa800), %g1
a00a7820:  97 33 60 10  srl  %o5, 0x10, %o3
a00a7824:  90 02 ff 10  add  %o3, -240, %o0
a00a7828:  94 10 62 ab  or  %g1, 0x2ab, %o2
a00a782c:  80 5a 00 0a  smul  %o0, %o2, %g0
a00a7830:  93 40 00 00  rd  %y, %o1
a00a7834:  99 3a 60 02  sra  %o1, 2, %o4
a00a7838:  bb 3a 20 1f  sra  %o0, 0x1f, %i5
a00a783c:  82 10 20 35  mov  0x35, %g1
a00a7840:  ae 23 00 1d  sub  %o4, %i5, %l7
a00a7844:  10 bf fc f8  b  0xa00a6c24
a00a7848:  c2 2f bf f7  stb  %g1, [ %fp + -9 ]
a00a784c:  7f ff ec bc  call  0xa00a2b3c
a00a7850:  a8 16 e2 90  or  %i3, 0x290, %l4
a00a7854:  10 bf fe 55  b  0xa00a71a8
a00a7858:  c2 0d 21 7b  ldub  [ %l4 + 0x17b ], %g1
a00a785c:  7f ff ec c0  call  0xa00a2b5c
a00a7860:  a8 16 e2 90  or  %i3, 0x290, %l4
a00a7864:  10 bf fe 51  b  0xa00a71a8
a00a7868:  c2 0d 21 7b  ldub  [ %l4 + 0x17b ], %g1
a00a786c:  7f ff ec c4  call  0xa00a2b7c
a00a7870:  a8 16 e2 90  or  %i3, 0x290, %l4
a00a7874:  10 bf fe 4d  b  0xa00a71a8
a00a7878:  c2 0d 21 7b  ldub  [ %l4 + 0x17b ], %g1
a00a787c:  7f ff ec c8  call  0xa00a2b9c
a00a7880:  a8 16 e2 90  or  %i3, 0x290, %l4
a00a7884:  10 bf fe 49  b  0xa00a71a8
a00a7888:  c2 0d 21 7b  ldub  [ %l4 + 0x17b ], %g1
