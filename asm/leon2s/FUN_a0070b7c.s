# leon2s FUN_a0070b7c 0xa0070b7c-0xa0072900 (7556 bytes)
a0070b7c:  9d e3 be d8  save  %sp, -296, %sp
a0070b80:  a0 07 bf d8  add  %fp, -40, %l0
a0070b84:  90 10 00 10  mov  %l0, %o0
a0070b88:  92 10 20 00  clr  %o1
a0070b8c:  40 01 02 88  call  0xa00b15ac
a0070b90:  94 10 20 1c  mov  0x1c, %o2
a0070b94:  1b 33 c0 f4  sethi  %hi(0xcf03d000), %o5
a0070b98:  c0 27 bf d0  clr  [ %fp + -48 ]
a0070b9c:  82 13 60 04  or  %o5, 4, %g1
a0070ba0:  c2 00 40 00  ld  [ %g1 ], %g1
a0070ba4:  c2 2f bf d0  stb  %g1, [ %fp + -48 ]
a0070ba8:  82 13 60 08  or  %o5, 8, %g1
a0070bac:  c2 00 40 00  ld  [ %g1 ], %g1
a0070bb0:  c2 2f bf d1  stb  %g1, [ %fp + -47 ]
a0070bb4:  82 13 60 0c  or  %o5, 0xc, %g1
a0070bb8:  c2 00 40 00  ld  [ %g1 ], %g1
a0070bbc:  c2 2f bf d2  stb  %g1, [ %fp + -46 ]
a0070bc0:  9a 13 60 10  or  %o5, 0x10, %o5
a0070bc4:  c2 03 40 00  ld  [ %o5 ], %g1
a0070bc8:  ea 0e 20 02  ldub  [ %i0 + 2 ], %l5
a0070bcc:  c2 2f bf d3  stb  %g1, [ %fp + -45 ]
a0070bd0:  80 a5 60 ff  cmp  %l5, 0xff
a0070bd4:  18 80 07 2f  bgu  0xa0072890
a0070bd8:  a6 10 20 00  clr  %l3
a0070bdc:  1b 28 01 c1  sethi  %hi(0xa0070400), %o5
a0070be0:  83 2d 60 02  sll  %l5, 2, %g1
a0070be4:  9a 13 63 7c  or  %o5, 0x37c, %o5
a0070be8:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a0070bec:  81 c0 40 00  jmp  %g1
a0070bf0:  01 00 00 00  nop
a0070bf4:  a0 10 20 00  clr  %l0	! 0x0
a0070bf8:  9a 07 bf f8  add  %fp, -8, %o5
a0070bfc:  82 0c 20 ff  and  %l0, 0xff, %g1
a0070c00:  82 03 40 01  add  %o5, %g1, %g1
a0070c04:  e0 28 7f e0  stb  %l0, [ %g1 + -32 ]
a0070c08:  a0 04 20 01  inc  %l0
a0070c0c:  82 0c 20 ff  and  %l0, 0xff, %g1
a0070c10:  80 a0 60 1b  cmp  %g1, 0x1b
a0070c14:  08 bf ff fc  bleu  0xa0070c04
a0070c18:  82 03 40 01  add  %o5, %g1, %g1
a0070c1c:  10 80 07 1d  b  0xa0072890
a0070c20:  a6 10 20 01  mov  1, %l3
a0070c24:  40 00 0a 2d  call  0xa00734d8
a0070c28:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a0070c2c:  10 80 07 1a  b  0xa0072894
a0070c30:  80 8c e0 ff  btst  0xff, %l3
a0070c34:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0070c38:  a5 32 20 08  srl  %o0, 8, %l2
a0070c3c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0070c40:  7f ff f1 f5  call  0xa006d414
a0070c44:  92 0c a0 ff  and  %l2, 0xff, %o1
a0070c48:  10 80 07 13  b  0xa0072894
a0070c4c:  80 8c e0 ff  btst  0xff, %l3
a0070c50:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a0070c54:  9a 08 60 ff  and  %g1, 0xff, %o5
a0070c58:  80 a3 60 08  cmp  %o5, 8
a0070c5c:  90 10 00 01  mov  %g1, %o0
a0070c60:  18 80 00 23  bgu  0xa0070cec
a0070c64:  a0 10 20 00  clr  %l0
a0070c68:  83 2b 60 02  sll  %o5, 2, %g1
a0070c6c:  1b 28 01 c1  sethi  %hi(0xa0070400), %o5
a0070c70:  9a 13 63 58  or  %o5, 0x358, %o5	! 0xa0070758
a0070c74:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a0070c78:  81 c0 40 00  jmp  %g1
a0070c7c:  01 00 00 00  nop
a0070c80:  40 00 81 1b  call  0xa00910ec
a0070c84:  90 0a 20 ff  and  %o0, 0xff, %o0
a0070c88:  10 80 00 19  b  0xa0070cec
a0070c8c:  a0 10 00 08  mov  %o0, %l0
a0070c90:  90 02 3f fe  add  %o0, -2, %o0
a0070c94:  40 00 c5 0c  call  0xa00a20c4
a0070c98:  90 0a 20 ff  and  %o0, 0xff, %o0
a0070c9c:  10 80 00 14  b  0xa0070cec
a0070ca0:  a0 10 00 08  mov  %o0, %l0
a0070ca4:  90 02 3f fc  add  %o0, -4, %o0
a0070ca8:  40 00 ef eb  call  0xa00acc54
a0070cac:  90 0a 20 ff  and  %o0, 0xff, %o0
a0070cb0:  10 80 00 0f  b  0xa0070cec
a0070cb4:  a0 10 00 08  mov  %o0, %l0
a0070cb8:  10 80 00 05  b  0xa0070ccc
a0070cbc:  92 10 20 01  mov  1, %o1
a0070cc0:  10 80 00 03  b  0xa0070ccc
a0070cc4:  92 10 20 02  mov  2, %o1
a0070cc8:  92 10 20 03  mov  3, %o1
a0070ccc:  7f c5 56 35  call  0x9f1c65a0
a0070cd0:  90 10 20 00  clr  %o0
a0070cd4:  40 00 ef e0  call  0xa00acc54
a0070cd8:  90 10 20 00  clr  %o0
a0070cdc:  a0 10 00 08  mov  %o0, %l0
a0070ce0:  90 10 20 00  clr  %o0
a0070ce4:  7f c5 56 2f  call  0x9f1c65a0
a0070ce8:  92 10 20 00  clr  %o1
a0070cec:  83 2c 20 10  sll  %l0, 0x10, %g1
a0070cf0:  83 30 60 10  srl  %g1, 0x10, %g1
a0070cf4:  9b 30 60 08  srl  %g1, 8, %o5
a0070cf8:  da 2f bf d9  stb  %o5, [ %fp + -39 ]
a0070cfc:  c2 2f bf d8  stb  %g1, [ %fp + -40 ]
a0070d00:  10 80 06 e4  b  0xa0072890
a0070d04:  a6 10 20 01  mov  1, %l3
a0070d08:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0070d0c:  a5 32 20 08  srl  %o0, 8, %l2
a0070d10:  90 0a 20 ff  and  %o0, 0xff, %o0
a0070d14:  40 00 28 47  call  0xa007ae30
a0070d18:  92 0c a0 ff  and  %l2, 0xff, %o1
a0070d1c:  10 80 06 de  b  0xa0072894
a0070d20:  80 8c e0 ff  btst  0xff, %l3
a0070d24:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0070d28:  82 0a 20 ff  and  %o0, 0xff, %g1
a0070d2c:  80 a0 60 01  cmp  %g1, 1
a0070d30:  08 80 00 09  bleu  0xa0070d54
a0070d34:  a2 10 00 08  mov  %o0, %l1
a0070d38:  a0 02 3f fe  add  %o0, -2, %l0
a0070d3c:  a0 0c 20 ff  and  %l0, 0xff, %l0
a0070d40:  40 00 c5 65  call  0xa00a22d4
a0070d44:  90 10 00 10  mov  %l0, %o0
a0070d48:  40 00 c7 29  call  0xa00a29ec
a0070d4c:  90 10 00 10  mov  %l0, %o0
a0070d50:  30 80 00 03  b,a   0xa0070d5c
a0070d54:  40 00 7c 94  call  0xa008ffa4
a0070d58:  90 10 00 01  mov  %g1, %o0
a0070d5c:  40 00 09 df  call  0xa00734d8
a0070d60:  90 0c 60 ff  and  %l1, 0xff, %o0
a0070d64:  10 80 06 cc  b  0xa0072894
a0070d68:  80 8c e0 ff  btst  0xff, %l3
a0070d6c:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0070d70:  83 32 20 07  srl  %o0, 7, %g1
a0070d74:  1b 2a 01 d8  sethi  %hi(0xa8076000), %o5
a0070d78:  9a 13 60 f0  or  %o5, 0xf0, %o5	! 0xa80760f0
a0070d7c:  82 08 61 fe  and  %g1, 0x1fe, %g1
a0070d80:  c2 13 40 01  lduh  [ %o5 + %g1 ], %g1
a0070d84:  95 32 20 10  srl  %o0, 0x10, %o2
a0070d88:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0070d8c:  80 a3 60 01  cmp  %o5, 1
a0070d90:  83 28 60 10  sll  %g1, 0x10, %g1
a0070d94:  08 80 00 08  bleu  0xa0070db4
a0070d98:  94 0a a0 ff  and  %o2, 0xff, %o2
a0070d9c:  90 02 3f fe  add  %o0, -2, %o0
a0070da0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0070da4:  40 00 d7 16  call  0xa00a69fc
a0070da8:  93 30 60 10  srl  %g1, 0x10, %o1
a0070dac:  10 80 06 ba  b  0xa0072894
a0070db0:  80 8c e0 ff  btst  0xff, %l3
a0070db4:  90 10 00 0d  mov  %o5, %o0
a0070db8:  40 00 d6 03  call  0xa00a65c4
a0070dbc:  93 30 60 10  srl  %g1, 0x10, %o1
a0070dc0:  10 80 06 b5  b  0xa0072894
a0070dc4:  80 8c e0 ff  btst  0xff, %l3
a0070dc8:  da 06 20 04  ld  [ %i0 + 4 ], %o5
a0070dcc:  90 0b 60 ff  and  %o5, 0xff, %o0
a0070dd0:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a0070dd4:  98 5a 21 2c  smul  %o0, 0x12c, %o4
a0070dd8:  82 10 60 18  or  %g1, 0x18, %g1
a0070ddc:  98 03 00 01  add  %o4, %g1, %o4
a0070de0:  9b 33 60 08  srl  %o5, 8, %o5
a0070de4:  da 2b 21 10  stb  %o5, [ %o4 + 0x110 ]
a0070de8:  c2 16 20 04  lduh  [ %i0 + 4 ], %g1
a0070dec:  c2 2b 21 11  stb  %g1, [ %o4 + 0x111 ]
a0070df0:  c2 0e 20 04  ldub  [ %i0 + 4 ], %g1
a0070df4:  82 08 60 01  and  %g1, 1, %g1
a0070df8:  c2 2b 21 12  stb  %g1, [ %o4 + 0x112 ]
a0070dfc:  c2 0e 20 04  ldub  [ %i0 + 4 ], %g1
a0070e00:  83 30 60 01  srl  %g1, 1, %g1
a0070e04:  82 08 60 01  and  %g1, 1, %g1
a0070e08:  c2 2b 21 13  stb  %g1, [ %o4 + 0x113 ]
a0070e0c:  c2 0e 20 04  ldub  [ %i0 + 4 ], %g1
a0070e10:  83 30 60 02  srl  %g1, 2, %g1
a0070e14:  82 08 60 01  and  %g1, 1, %g1
a0070e18:  c2 2b 21 14  stb  %g1, [ %o4 + 0x114 ]
a0070e1c:  c2 0e 20 04  ldub  [ %i0 + 4 ], %g1
a0070e20:  83 30 60 03  srl  %g1, 3, %g1
a0070e24:  82 08 60 01  and  %g1, 1, %g1
a0070e28:  c2 2b 21 15  stb  %g1, [ %o4 + 0x115 ]
a0070e2c:  c2 0e 20 04  ldub  [ %i0 + 4 ], %g1
a0070e30:  83 30 60 04  srl  %g1, 4, %g1
a0070e34:  82 08 60 01  and  %g1, 1, %g1
a0070e38:  c2 2b 21 16  stb  %g1, [ %o4 + 0x116 ]
a0070e3c:  c2 06 20 08  ld  [ %i0 + 8 ], %g1
a0070e40:  c2 2b 21 18  stb  %g1, [ %o4 + 0x118 ]
a0070e44:  c2 06 20 08  ld  [ %i0 + 8 ], %g1
a0070e48:  83 30 60 08  srl  %g1, 8, %g1
a0070e4c:  82 08 60 01  and  %g1, 1, %g1
a0070e50:  c2 2b 21 19  stb  %g1, [ %o4 + 0x119 ]
a0070e54:  c2 0e 20 0a  ldub  [ %i0 + 0xa ], %g1
a0070e58:  83 30 60 02  srl  %g1, 2, %g1
a0070e5c:  82 08 60 01  and  %g1, 1, %g1
a0070e60:  c2 2b 21 1b  stb  %g1, [ %o4 + 0x11b ]
a0070e64:  c2 0e 20 0a  ldub  [ %i0 + 0xa ], %g1
a0070e68:  83 30 60 03  srl  %g1, 3, %g1
a0070e6c:  82 08 60 01  and  %g1, 1, %g1
a0070e70:  c2 2b 21 1c  stb  %g1, [ %o4 + 0x11c ]
a0070e74:  c2 0e 20 0a  ldub  [ %i0 + 0xa ], %g1
a0070e78:  83 30 60 04  srl  %g1, 4, %g1
a0070e7c:  82 08 60 01  and  %g1, 1, %g1
a0070e80:  c2 2b 21 1d  stb  %g1, [ %o4 + 0x11d ]
a0070e84:  c2 0e 20 0a  ldub  [ %i0 + 0xa ], %g1
a0070e88:  83 30 60 05  srl  %g1, 5, %g1
a0070e8c:  82 08 60 01  and  %g1, 1, %g1
a0070e90:  c2 2b 21 1e  stb  %g1, [ %o4 + 0x11e ]
a0070e94:  c2 0e 20 0a  ldub  [ %i0 + 0xa ], %g1
a0070e98:  83 30 60 06  srl  %g1, 6, %g1
a0070e9c:  82 08 60 01  and  %g1, 1, %g1
a0070ea0:  c2 2b 21 1f  stb  %g1, [ %o4 + 0x11f ]
a0070ea4:  c2 0e 20 0a  ldub  [ %i0 + 0xa ], %g1
a0070ea8:  83 30 60 07  srl  %g1, 7, %g1
a0070eac:  c2 2b 21 26  stb  %g1, [ %o4 + 0x126 ]
a0070eb0:  c2 16 20 08  lduh  [ %i0 + 8 ], %g1
a0070eb4:  c2 33 21 20  sth  %g1, [ %o4 + 0x120 ]
a0070eb8:  c2 06 20 0c  ld  [ %i0 + 0xc ], %g1
a0070ebc:  c2 2b 21 17  stb  %g1, [ %o4 + 0x117 ]
a0070ec0:  82 10 20 01  mov  1, %g1
a0070ec4:  c2 2b 21 22  stb  %g1, [ %o4 + 0x122 ]
a0070ec8:  40 01 00 58  call  0xa00b1028
a0070ecc:  92 10 20 00  clr  %o1
a0070ed0:  10 80 06 71  b  0xa0072894
a0070ed4:  80 8c e0 ff  btst  0xff, %l3
a0070ed8:  da 06 20 04  ld  [ %i0 + 4 ], %o5
a0070edc:  a0 0b 60 ff  and  %o5, 0xff, %l0
a0070ee0:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a0070ee4:  98 5c 21 2c  smul  %l0, 0x12c, %o4
a0070ee8:  82 10 60 18  or  %g1, 0x18, %g1
a0070eec:  98 03 00 01  add  %o4, %g1, %o4
a0070ef0:  9b 33 60 08  srl  %o5, 8, %o5
a0070ef4:  da 2b 21 10  stb  %o5, [ %o4 + 0x110 ]
a0070ef8:  c2 16 20 04  lduh  [ %i0 + 4 ], %g1
a0070efc:  c2 2b 21 11  stb  %g1, [ %o4 + 0x111 ]
a0070f00:  c2 0e 20 04  ldub  [ %i0 + 4 ], %g1
a0070f04:  82 08 60 01  and  %g1, 1, %g1
a0070f08:  c2 2b 21 12  stb  %g1, [ %o4 + 0x112 ]
a0070f0c:  c2 0e 20 04  ldub  [ %i0 + 4 ], %g1
a0070f10:  83 30 60 01  srl  %g1, 1, %g1
a0070f14:  82 08 60 01  and  %g1, 1, %g1
a0070f18:  c2 2b 21 13  stb  %g1, [ %o4 + 0x113 ]
a0070f1c:  c2 0e 20 04  ldub  [ %i0 + 4 ], %g1
a0070f20:  83 30 60 02  srl  %g1, 2, %g1
a0070f24:  82 08 60 01  and  %g1, 1, %g1
a0070f28:  c2 2b 21 14  stb  %g1, [ %o4 + 0x114 ]
a0070f2c:  c2 0e 20 04  ldub  [ %i0 + 4 ], %g1
a0070f30:  83 30 60 03  srl  %g1, 3, %g1
a0070f34:  82 08 60 01  and  %g1, 1, %g1
a0070f38:  c2 2b 21 15  stb  %g1, [ %o4 + 0x115 ]
a0070f3c:  c2 0e 20 04  ldub  [ %i0 + 4 ], %g1
a0070f40:  83 30 60 04  srl  %g1, 4, %g1
a0070f44:  82 08 60 01  and  %g1, 1, %g1
a0070f48:  c2 2b 21 16  stb  %g1, [ %o4 + 0x116 ]
a0070f4c:  da 06 20 0c  ld  [ %i0 + 0xc ], %o5
a0070f50:  82 10 20 01  mov  1, %g1
a0070f54:  c2 2b 21 22  stb  %g1, [ %o4 + 0x122 ]
a0070f58:  da 2b 21 17  stb  %o5, [ %o4 + 0x117 ]
a0070f5c:  40 00 ec 25  call  0xa00abff0
a0070f60:  90 10 00 10  mov  %l0, %o0
a0070f64:  40 00 ed c2  call  0xa00ac66c
a0070f68:  90 10 00 10  mov  %l0, %o0
a0070f6c:  40 00 fa 88  call  0xa00af98c
a0070f70:  90 10 00 10  mov  %l0, %o0
a0070f74:  7f c5 6c bc  call  0x9f1cc264
a0070f78:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a0070f7c:  7f c5 6c 4b  call  0x9f1cc0a8
a0070f80:  01 00 00 00  nop
a0070f84:  10 80 06 44  b  0xa0072894
a0070f88:  80 8c e0 ff  btst  0xff, %l3
a0070f8c:  da 06 20 04  ld  [ %i0 + 4 ], %o5
a0070f90:  93 33 60 08  srl  %o5, 8, %o1
a0070f94:  82 02 7e 00  add  %o1, -512, %g1
a0070f98:  83 28 60 10  sll  %g1, 0x10, %g1
a0070f9c:  83 30 60 10  srl  %g1, 0x10, %g1
a0070fa0:  80 a0 61 ff  cmp  %g1, 0x1ff
a0070fa4:  08 80 00 04  bleu  0xa0070fb4
a0070fa8:  93 2a 60 10  sll  %o1, 0x10, %o1
a0070fac:  10 80 00 06  b  0xa0070fc4
a0070fb0:  c0 2f bf d8  clrb  [ %fp + -40 ]
a0070fb4:  90 0b 60 ff  and  %o5, 0xff, %o0
a0070fb8:  40 00 d7 00  call  0xa00a6bb8
a0070fbc:  93 32 60 10  srl  %o1, 0x10, %o1
a0070fc0:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a0070fc4:  10 80 06 33  b  0xa0072890
a0070fc8:  a6 10 20 01  mov  1, %l3
a0070fcc:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0070fd0:  93 2a 20 08  sll  %o0, 8, %o1
a0070fd4:  95 32 20 18  srl  %o0, 0x18, %o2
a0070fd8:  93 32 60 10  srl  %o1, 0x10, %o1
a0070fdc:  40 00 ed 44  call  0xa00ac4ec
a0070fe0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0070fe4:  10 80 06 2c  b  0xa0072894
a0070fe8:  80 8c e0 ff  btst  0xff, %l3
a0070fec:  e0 06 20 04  ld  [ %i0 + 4 ], %l0
a0070ff0:  95 34 20 08  srl  %l0, 8, %o2
a0070ff4:  a2 0a a0 ff  and  %o2, 0xff, %l1
a0070ff8:  17 2a 01 ea  sethi  %hi(0xa807a800), %o3
a0070ffc:  d8 02 e1 28  ld  [ %o3 + 0x128 ], %o4	! 0xa807a928
a0071000:  82 0c 60 01  and  %l1, 1, %g1
a0071004:  1b 08 00 00  sethi  %hi(0x20000000), %o5
a0071008:  9a 2b 00 0d  andn  %o4, %o5, %o5
a007100c:  83 28 60 1d  sll  %g1, 0x1d, %g1
a0071010:  9a 13 40 01  or  %o5, %g1, %o5
a0071014:  a0 0c 20 ff  and  %l0, 0xff, %l0
a0071018:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a007101c:  82 10 60 18  or  %g1, 0x18, %g1	! 0xa807dc18
a0071020:  98 5c 21 2c  smul  %l0, 0x12c, %o4
a0071024:  98 03 00 01  add  %o4, %g1, %o4
a0071028:  da 22 e1 28  st  %o5, [ %o3 + 0x128 ]
a007102c:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a0071030:  d4 2b 21 12  stb  %o2, [ %o4 + 0x112 ]
a0071034:  92 10 00 11  mov  %l1, %o1
a0071038:  40 00 08 03  call  0xa0073044
a007103c:  90 12 20 d0  or  %o0, 0xd0, %o0
a0071040:  90 10 00 10  mov  %l0, %o0
a0071044:  40 00 fb 4c  call  0xa00afd74
a0071048:  92 10 00 11  mov  %l1, %o1
a007104c:  7f c5 6c 86  call  0x9f1cc264
a0071050:  90 10 00 10  mov  %l0, %o0
a0071054:  7f c5 6c 15  call  0x9f1cc0a8
a0071058:  01 00 00 00  nop
a007105c:  10 80 06 0e  b  0xa0072894
a0071060:  80 8c e0 ff  btst  0xff, %l3
a0071064:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a0071068:  d2 0e 20 07  ldub  [ %i0 + 7 ], %o1
a007106c:  40 00 07 f6  call  0xa0073044
a0071070:  90 12 20 e0  or  %o0, 0xe0, %o0
a0071074:  7f c5 55 8f  call  0x9f1c66b0
a0071078:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a007107c:  10 80 06 06  b  0xa0072894
a0071080:  80 8c e0 ff  btst  0xff, %l3
a0071084:  da 06 20 04  ld  [ %i0 + 4 ], %o5
a0071088:  90 0b 60 ff  and  %o5, 0xff, %o0
a007108c:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a0071090:  98 5a 21 2c  smul  %o0, 0x12c, %o4
a0071094:  82 10 60 18  or  %g1, 0x18, %g1
a0071098:  98 03 00 01  add  %o4, %g1, %o4
a007109c:  83 33 60 08  srl  %o5, 8, %g1
a00710a0:  9b 33 60 10  srl  %o5, 0x10, %o5
a00710a4:  da 2b 21 10  stb  %o5, [ %o4 + 0x110 ]
a00710a8:  40 00 eb 5e  call  0xa00abe20
a00710ac:  c2 2b 21 17  stb  %g1, [ %o4 + 0x117 ]
a00710b0:  10 80 05 f9  b  0xa0072894
a00710b4:  80 8c e0 ff  btst  0xff, %l3
a00710b8:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a00710bc:  a5 32 20 08  srl  %o0, 8, %l2
a00710c0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00710c4:  40 00 fb 10  call  0xa00afd04
a00710c8:  92 0c a0 ff  and  %l2, 0xff, %o1
a00710cc:  10 80 05 f2  b  0xa0072894
a00710d0:  80 8c e0 ff  btst  0xff, %l3
a00710d4:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a00710d8:  a5 32 20 08  srl  %o0, 8, %l2
a00710dc:  95 32 20 10  srl  %o0, 0x10, %o2
a00710e0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00710e4:  92 0c a0 ff  and  %l2, 0xff, %o1
a00710e8:  40 00 f6 55  call  0xa00aea3c
a00710ec:  94 0a a0 ff  and  %o2, 0xff, %o2
a00710f0:  10 80 05 e9  b  0xa0072894
a00710f4:  80 8c e0 ff  btst  0xff, %l3
a00710f8:  40 00 f4 93  call  0xa00ae344
a00710fc:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a0071100:  10 80 05 e5  b  0xa0072894
a0071104:  80 8c e0 ff  btst  0xff, %l3
a0071108:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a007110c:  95 32 20 08  srl  %o0, 8, %o2
a0071110:  90 0a 20 ff  and  %o0, 0xff, %o0
a0071114:  7f c5 55 23  call  0x9f1c65a0
a0071118:  92 0a a0 ff  and  %o2, 0xff, %o1
a007111c:  10 80 05 de  b  0xa0072894
a0071120:  80 8c e0 ff  btst  0xff, %l3
a0071124:  40 00 f4 27  call  0xa00ae1c0
a0071128:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a007112c:  10 80 05 da  b  0xa0072894
a0071130:  80 8c e0 ff  btst  0xff, %l3
a0071134:  e0 0e 20 07  ldub  [ %i0 + 7 ], %l0
a0071138:  40 00 f1 8b  call  0xa00ad764
a007113c:  90 10 00 10  mov  %l0, %o0
a0071140:  40 00 ed 19  call  0xa00ac5a4
a0071144:  90 10 00 10  mov  %l0, %o0
a0071148:  10 80 05 d3  b  0xa0072894
a007114c:  80 8c e0 ff  btst  0xff, %l3
a0071150:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0071154:  a5 32 20 08  srl  %o0, 8, %l2
a0071158:  90 0a 20 ff  and  %o0, 0xff, %o0
a007115c:  40 00 f4 3e  call  0xa00ae254
a0071160:  92 0c a0 ff  and  %l2, 0xff, %o1
a0071164:  10 80 05 cc  b  0xa0072894
a0071168:  80 8c e0 ff  btst  0xff, %l3
a007116c:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0071170:  a5 32 20 08  srl  %o0, 8, %l2
a0071174:  90 0a 20 ff  and  %o0, 0xff, %o0
a0071178:  40 00 fa f1  call  0xa00afd3c
a007117c:  92 0c a0 ff  and  %l2, 0xff, %o1
a0071180:  10 80 05 c5  b  0xa0072894
a0071184:  80 8c e0 ff  btst  0xff, %l3
a0071188:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a007118c:  a0 08 60 ff  and  %g1, 0xff, %l0
a0071190:  a5 30 60 08  srl  %g1, 8, %l2
a0071194:  90 10 00 10  mov  %l0, %o0
a0071198:  40 01 00 d1  call  0xa00b14dc
a007119c:  92 0c a0 ff  and  %l2, 0xff, %o1
a00711a0:  40 00 eb 94  call  0xa00abff0
a00711a4:  90 10 00 10  mov  %l0, %o0
a00711a8:  10 80 05 bb  b  0xa0072894
a00711ac:  80 8c e0 ff  btst  0xff, %l3
a00711b0:  da 06 20 04  ld  [ %i0 + 4 ], %o5
a00711b4:  a2 0b 60 ff  and  %o5, 0xff, %l1
a00711b8:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00711bc:  82 10 60 18  or  %g1, 0x18, %g1	! 0xa807dc18
a00711c0:  98 5c 61 2c  smul  %l1, 0x12c, %o4
a00711c4:  98 03 00 01  add  %o4, %g1, %o4
a00711c8:  83 33 60 08  srl  %o5, 8, %g1
a00711cc:  97 33 60 10  srl  %o5, 0x10, %o3
a00711d0:  d4 0e 20 0b  ldub  [ %i0 + 0xb ], %o2
a00711d4:  9b 33 60 18  srl  %o5, 0x18, %o5
a00711d8:  da 2b 21 1b  stb  %o5, [ %o4 + 0x11b ]
a00711dc:  c2 2b 21 18  stb  %g1, [ %o4 + 0x118 ]
a00711e0:  80 a2 a0 00  cmp  %o2, 0
a00711e4:  12 80 00 0d  bne  0xa0071218
a00711e8:  d6 2b 21 1a  stb  %o3, [ %o4 + 0x11a ]
a00711ec:  90 10 00 11  mov  %l1, %o0
a00711f0:  40 00 51 78  call  0xa00857d0
a00711f4:  92 10 20 00  clr  %o1
a00711f8:  40 00 71 82  call  0xa008d800
a00711fc:  01 00 00 00  nop
a0071200:  90 0a 20 ff  and  %o0, 0xff, %o0
a0071204:  80 a2 20 df  cmp  %o0, 0xdf
a0071208:  08 80 00 10  bleu  0xa0071248
a007120c:  90 10 00 11  mov  %l1, %o0
a0071210:  10 80 00 0c  b  0xa0071240
a0071214:  92 10 20 00  clr  %o1
a0071218:  90 10 00 11  mov  %l1, %o0
a007121c:  40 00 51 6d  call  0xa00857d0
a0071220:  92 10 20 01  mov  1, %o1
a0071224:  40 00 71 77  call  0xa008d800
a0071228:  01 00 00 00  nop
a007122c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0071230:  80 a2 20 df  cmp  %o0, 0xdf
a0071234:  08 80 00 05  bleu  0xa0071248
a0071238:  90 10 00 11  mov  %l1, %o0
a007123c:  92 10 20 01  mov  1, %o1
a0071240:  40 00 4b 31  call  0xa0083f04
a0071244:  94 10 20 01  mov  1, %o2
a0071248:  40 00 f4 56  call  0xa00ae3a0
a007124c:  90 10 00 11  mov  %l1, %o0
a0071250:  10 80 05 91  b  0xa0072894
a0071254:  80 8c e0 ff  btst  0xff, %l3
a0071258:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a007125c:  80 a0 60 01  cmp  %g1, 1
a0071260:  18 80 05 8d  bgu  0xa0072894
a0071264:  80 8c e0 ff  btst  0xff, %l3
a0071268:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a007126c:  9a 13 60 18  or  %o5, 0x18, %o5	! 0xa807dc18
a0071270:  82 58 61 2c  smul  %g1, 0x12c, %g1
a0071274:  82 00 40 0d  add  %g1, %o5, %g1
a0071278:  9a 10 20 01  mov  1, %o5
a007127c:  10 80 05 86  b  0xa0072894
a0071280:  da 28 61 28  stb  %o5, [ %g1 + 0x128 ]
a0071284:  40 00 f0 57  call  0xa00ad3e0
a0071288:  90 10 20 00  clr  %o0
a007128c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0071290:  80 a2 20 01  cmp  %o0, 1
a0071294:  02 80 00 09  be  0xa00712b8
a0071298:  82 10 20 01  mov  1, %g1
a007129c:  40 00 f0 51  call  0xa00ad3e0
a00712a0:  90 10 20 01  mov  1, %o0
a00712a4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00712a8:  80 a2 20 01  cmp  %o0, 1
a00712ac:  32 80 00 07  bne,a   0xa00712c8
a00712b0:  c0 2f bf d8  clrb  [ %fp + -40 ]
a00712b4:  82 10 20 01  mov  1, %g1
a00712b8:  40 00 ef 4f  call  0xa00acff4
a00712bc:  c2 2f bf d8  stb  %g1, [ %fp + -40 ]
a00712c0:  10 80 05 74  b  0xa0072890
a00712c4:  a6 10 20 01  mov  1, %l3
a00712c8:  10 80 05 72  b  0xa0072890
a00712cc:  a6 10 20 01  mov  1, %l3
a00712d0:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a00712d4:  9a 08 60 ff  and  %g1, 0xff, %o5
a00712d8:  80 a3 60 01  cmp  %o5, 1
a00712dc:  18 80 05 6d  bgu  0xa0072890
a00712e0:  91 30 60 08  srl  %g1, 8, %o0
a00712e4:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00712e8:  9a 5b 61 2c  smul  %o5, 0x12c, %o5
a00712ec:  82 10 60 18  or  %g1, 0x18, %g1
a00712f0:  9a 03 40 01  add  %o5, %g1, %o5
a00712f4:  10 80 05 67  b  0xa0072890
a00712f8:  d0 2b 61 29  stb  %o0, [ %o5 + 0x129 ]
a00712fc:  d8 06 20 04  ld  [ %i0 + 4 ], %o4
a0071300:  90 0b 20 ff  and  %o4, 0xff, %o0
a0071304:  9b 2a 20 02  sll  %o0, 2, %o5
a0071308:  9a 03 40 08  add  %o5, %o0, %o5
a007130c:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a0071310:  82 10 60 fc  or  %g1, 0xfc, %g1	! 0xa807a8fc
a0071314:  9b 2b 60 02  sll  %o5, 2, %o5
a0071318:  9a 03 40 01  add  %o5, %g1, %o5
a007131c:  97 33 20 08  srl  %o4, 8, %o3
a0071320:  95 33 20 10  srl  %o4, 0x10, %o2
a0071324:  c2 06 20 08  ld  [ %i0 + 8 ], %g1
a0071328:  99 33 20 18  srl  %o4, 0x18, %o4
a007132c:  c2 2b 60 13  stb  %g1, [ %o5 + 0x13 ]
a0071330:  d6 2b 60 10  stb  %o3, [ %o5 + 0x10 ]
a0071334:  d4 2b 60 11  stb  %o2, [ %o5 + 0x11 ]
a0071338:  80 a2 20 01  cmp  %o0, 1
a007133c:  18 80 05 55  bgu  0xa0072890
a0071340:  d8 2b 60 12  stb  %o4, [ %o5 + 0x12 ]
a0071344:  40 00 8c 94  call  0xa0094594
a0071348:  01 00 00 00  nop
a007134c:  10 80 05 52  b  0xa0072894
a0071350:  80 8c e0 ff  btst  0xff, %l3
a0071354:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a0071358:  90 08 60 ff  and  %g1, 0xff, %o0
a007135c:  99 2a 20 02  sll  %o0, 2, %o4
a0071360:  98 03 00 08  add  %o4, %o0, %o4
a0071364:  17 2a 01 ea  sethi  %hi(0xa807a800), %o3
a0071368:  96 12 e0 fc  or  %o3, 0xfc, %o3	! 0xa807a8fc
a007136c:  99 2b 20 02  sll  %o4, 2, %o4
a0071370:  a5 30 60 08  srl  %g1, 8, %l2
a0071374:  d4 12 c0 0c  lduh  [ %o3 + %o4 ], %o2
a0071378:  9a 0c a0 01  and  %l2, 1, %o5
a007137c:  03 00 00 04  sethi  %hi(0x1000), %g1
a0071380:  82 2a 80 01  andn  %o2, %g1, %g1
a0071384:  9b 2b 60 0c  sll  %o5, 0xc, %o5
a0071388:  82 10 40 0d  or  %g1, %o5, %g1
a007138c:  80 a2 20 01  cmp  %o0, 1
a0071390:  18 80 05 40  bgu  0xa0072890
a0071394:  c2 32 c0 0c  sth  %g1, [ %o3 + %o4 ]
a0071398:  40 00 81 55  call  0xa00918ec
a007139c:  01 00 00 00  nop
a00713a0:  10 80 05 3d  b  0xa0072894
a00713a4:  80 8c e0 ff  btst  0xff, %l3
a00713a8:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a00713ac:  a2 08 60 ff  and  %g1, 0xff, %l1
a00713b0:  80 a4 60 01  cmp  %l1, 1
a00713b4:  18 80 05 37  bgu  0xa0072890
a00713b8:  a4 10 00 01  mov  %g1, %l2
a00713bc:  93 2c 60 02  sll  %l1, 2, %o1
a00713c0:  92 02 40 11  add  %o1, %l1, %o1
a00713c4:  29 2a 01 ea  sethi  %hi(0xa807a800), %l4
a00713c8:  93 2a 60 02  sll  %o1, 2, %o1
a00713cc:  9e 15 20 fc  or  %l4, 0xfc, %o7
a00713d0:  90 02 40 0f  add  %o1, %o7, %o0
a00713d4:  83 30 60 08  srl  %g1, 8, %g1
a00713d8:  c2 2a 20 03  stb  %g1, [ %o0 + 3 ]
a00713dc:  d6 06 20 08  ld  [ %i0 + 8 ], %o3
a00713e0:  c2 16 20 04  lduh  [ %i0 + 4 ], %g1
a00713e4:  c2 32 20 04  sth  %g1, [ %o0 + 4 ]
a00713e8:  98 0a e0 ff  and  %o3, 0xff, %o4
a00713ec:  21 3f ff f7  sethi  %hi(0xffffdc00), %l0
a00713f0:  c2 13 c0 09  lduh  [ %o7 + %o1 ], %g1
a00713f4:  a0 14 23 ff  or  %l0, 0x3ff, %l0
a00713f8:  9b 33 20 07  srl  %o4, 7, %o5
a00713fc:  9b 2b 60 0d  sll  %o5, 0xd, %o5
a0071400:  82 08 40 10  and  %g1, %l0, %g1
a0071404:  82 10 40 0d  or  %g1, %o5, %g1
a0071408:  9b 2b 20 05  sll  %o4, 5, %o5
a007140c:  9a 0b 68 00  and  %o5, 0x800, %o5
a0071410:  82 08 73 ff  and  %g1, -3073, %g1
a0071414:  99 2b 20 05  sll  %o4, 5, %o4
a0071418:  82 10 40 0d  or  %g1, %o5, %g1
a007141c:  98 0b 24 00  and  %o4, 0x400, %o4
a0071420:  82 10 40 0c  or  %g1, %o4, %g1
a0071424:  c2 33 c0 09  sth  %g1, [ %o7 + %o1 ]
a0071428:  96 0a e0 1f  and  %o3, 0x1f, %o3
a007142c:  d6 2a 20 06  stb  %o3, [ %o0 + 6 ]
a0071430:  c2 06 20 08  ld  [ %i0 + 8 ], %g1
a0071434:  83 30 60 08  srl  %g1, 8, %g1
a0071438:  c2 2a 20 07  stb  %g1, [ %o0 + 7 ]
a007143c:  c2 16 20 08  lduh  [ %i0 + 8 ], %g1
a0071440:  9a 08 60 f0  and  %g1, 0xf0, %o5
a0071444:  9b 3b 60 04  sra  %o5, 4, %o5
a0071448:  82 08 60 0f  and  %g1, 0xf, %g1
a007144c:  c2 2a 20 09  stb  %g1, [ %o0 + 9 ]
a0071450:  da 2a 20 0a  stb  %o5, [ %o0 + 0xa ]
a0071454:  d4 0e 20 08  ldub  [ %i0 + 8 ], %o2
a0071458:  d8 13 c0 09  lduh  [ %o7 + %o1 ], %o4
a007145c:  82 0a a0 01  and  %o2, 1, %g1
a0071460:  1b 00 00 04  sethi  %hi(0x1000), %o5
a0071464:  9a 2b 00 0d  andn  %o4, %o5, %o5
a0071468:  83 28 60 0c  sll  %g1, 0xc, %g1
a007146c:  9a 13 40 01  or  %o5, %g1, %o5
a0071470:  83 2a a0 08  sll  %o2, 8, %g1
a0071474:  82 08 62 00  and  %g1, 0x200, %g1
a0071478:  99 2a a0 06  sll  %o2, 6, %o4
a007147c:  9a 0b 7c ff  and  %o5, -769, %o5
a0071480:  9a 13 40 01  or  %o5, %g1, %o5
a0071484:  98 0b 21 00  and  %o4, 0x100, %o4
a0071488:  97 32 a0 03  srl  %o2, 3, %o3
a007148c:  9a 13 40 0c  or  %o5, %o4, %o5
a0071490:  96 0a e0 01  and  %o3, 1, %o3
a0071494:  03 00 00 10  sethi  %hi(0x4000), %g1
a0071498:  82 2b 40 01  andn  %o5, %g1, %g1
a007149c:  97 2a e0 0e  sll  %o3, 0xe, %o3
a00714a0:  98 02 80 0a  add  %o2, %o2, %o4
a00714a4:  82 10 40 0b  or  %g1, %o3, %g1
a00714a8:  9b 32 a0 01  srl  %o2, 1, %o5
a00714ac:  98 0b 20 20  and  %o4, 0x20, %o4
a00714b0:  82 08 7f cf  and  %g1, -49, %g1
a00714b4:  9a 0b 60 10  and  %o5, 0x10, %o5
a00714b8:  82 10 40 0c  or  %g1, %o4, %g1
a00714bc:  82 10 40 0d  or  %g1, %o5, %g1
a00714c0:  9b 32 a0 03  srl  %o2, 3, %o5
a00714c4:  9a 0b 60 08  and  %o5, 8, %o5
a00714c8:  82 08 7f f7  and  %g1, -9, %g1
a00714cc:  82 10 40 0d  or  %g1, %o5, %g1
a00714d0:  c2 33 c0 09  sth  %g1, [ %o7 + %o1 ]
a00714d4:  c2 12 20 02  lduh  [ %o0 + 2 ], %g1
a00714d8:  95 32 a0 07  srl  %o2, 7, %o2
a00714dc:  82 08 40 10  and  %g1, %l0, %g1
a00714e0:  95 2a a0 0d  sll  %o2, 0xd, %o2
a00714e4:  82 10 40 0a  or  %g1, %o2, %g1
a00714e8:  c2 32 20 02  sth  %g1, [ %o0 + 2 ]
a00714ec:  c2 0a 20 03  ldub  [ %o0 + 3 ], %g1
a00714f0:  82 00 60 1f  add  %g1, 0x1f, %g1
a00714f4:  82 08 60 ff  and  %g1, 0xff, %g1
a00714f8:  80 a0 60 01  cmp  %g1, 1
a00714fc:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a0071500:  18 80 00 08  bgu  0xa0071520
a0071504:  83 2c 60 03  sll  %l1, 3, %g1
a0071508:  82 20 40 11  sub  %g1, %l1, %g1
a007150c:  9a 13 61 80  or  %o5, 0x180, %o5
a0071510:  83 28 60 02  sll  %g1, 2, %g1
a0071514:  82 00 40 0d  add  %g1, %o5, %g1
a0071518:  10 80 00 07  b  0xa0071534
a007151c:  c2 08 60 17  ldub  [ %g1 + 0x17 ], %g1
a0071520:  82 20 40 11  sub  %g1, %l1, %g1
a0071524:  9a 13 61 80  or  %o5, 0x180, %o5
a0071528:  83 28 60 02  sll  %g1, 2, %g1
a007152c:  82 00 40 0d  add  %g1, %o5, %g1
a0071530:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a0071534:  82 08 60 ff  and  %g1, 0xff, %g1
a0071538:  80 a0 60 71  cmp  %g1, 0x71
a007153c:  02 80 00 04  be  0xa007154c
a0071540:  80 a0 60 81  cmp  %g1, 0x81
a0071544:  12 80 00 0d  bne  0xa0071578
a0071548:  90 0c a0 ff  and  %l2, 0xff, %o0
a007154c:  83 2c 60 02  sll  %l1, 2, %g1
a0071550:  82 00 40 11  add  %g1, %l1, %g1
a0071554:  83 28 60 02  sll  %g1, 2, %g1
a0071558:  9a 15 20 fc  or  %l4, 0xfc, %o5
a007155c:  92 00 40 0d  add  %g1, %o5, %o1
a0071560:  c2 0a 60 09  ldub  [ %o1 + 9 ], %g1
a0071564:  80 a0 60 07  cmp  %g1, 7
a0071568:  18 80 00 04  bgu  0xa0071578
a007156c:  90 0c a0 ff  and  %l2, 0xff, %o0
a0071570:  82 10 20 08  mov  8, %g1
a0071574:  c2 2a 60 09  stb  %g1, [ %o1 + 9 ]
a0071578:  95 2a 20 02  sll  %o0, 2, %o2
a007157c:  94 02 80 08  add  %o2, %o0, %o2
a0071580:  1f 2a 01 ea  sethi  %hi(0xa807a800), %o7
a0071584:  9e 13 e0 fc  or  %o7, 0xfc, %o7	! 0xa807a8fc
a0071588:  95 2a a0 02  sll  %o2, 2, %o2
a007158c:  c2 06 20 0c  ld  [ %i0 + 0xc ], %g1
a0071590:  92 02 80 0f  add  %o2, %o7, %o1
a0071594:  c2 2a 60 08  stb  %g1, [ %o1 + 8 ]
a0071598:  d8 16 20 0c  lduh  [ %i0 + 0xc ], %o4
a007159c:  96 0b 20 ff  and  %o4, 0xff, %o3
a00715a0:  c2 13 c0 0a  lduh  [ %o7 + %o2 ], %g1
a00715a4:  98 0b 20 01  and  %o4, 1, %o4
a00715a8:  99 2b 20 07  sll  %o4, 7, %o4
a00715ac:  9b 2a e0 05  sll  %o3, 5, %o5
a00715b0:  82 08 7f 3f  and  %g1, -193, %g1
a00715b4:  82 10 40 0c  or  %g1, %o4, %g1
a00715b8:  9a 0b 60 40  and  %o5, 0x40, %o5
a00715bc:  82 10 40 0d  or  %g1, %o5, %g1
a00715c0:  99 32 e0 01  srl  %o3, 1, %o4
a00715c4:  98 0b 20 04  and  %o4, 4, %o4
a00715c8:  9b 32 e0 03  srl  %o3, 3, %o5
a00715cc:  82 08 7f f9  and  %g1, -7, %g1
a00715d0:  82 10 40 0c  or  %g1, %o4, %g1
a00715d4:  9a 0b 60 02  and  %o5, 2, %o5
a00715d8:  82 10 40 0d  or  %g1, %o5, %g1
a00715dc:  9b 32 e0 05  srl  %o3, 5, %o5
a00715e0:  9a 0b 60 01  and  %o5, 1, %o5
a00715e4:  82 08 7f fe  and  %g1, -2, %g1
a00715e8:  82 10 40 0d  or  %g1, %o5, %g1
a00715ec:  c2 33 c0 0a  sth  %g1, [ %o7 + %o2 ]
a00715f0:  83 32 e0 06  srl  %o3, 6, %g1
a00715f4:  d8 12 60 02  lduh  [ %o1 + 2 ], %o4
a00715f8:  82 08 60 01  and  %g1, 1, %g1
a00715fc:  1b 3f ff e0  sethi  %hi(0xffff8000), %o5
a0071600:  9a 2b 00 0d  andn  %o4, %o5, %o5
a0071604:  83 28 60 0f  sll  %g1, 0xf, %g1
a0071608:  9a 13 40 01  or  %o5, %g1, %o5
a007160c:  97 32 e0 07  srl  %o3, 7, %o3
a0071610:  03 00 00 10  sethi  %hi(0x4000), %g1
a0071614:  82 2b 40 01  andn  %o5, %g1, %g1
a0071618:  97 2a e0 0e  sll  %o3, 0xe, %o3
a007161c:  82 10 40 0b  or  %g1, %o3, %g1
a0071620:  c2 32 60 02  sth  %g1, [ %o1 + 2 ]
a0071624:  c2 0e 20 0c  ldub  [ %i0 + 0xc ], %g1
a0071628:  c2 2a 60 0d  stb  %g1, [ %o1 + 0xd ]
a007162c:  c2 06 20 10  ld  [ %i0 + 0x10 ], %g1
a0071630:  c2 2a 60 0e  stb  %g1, [ %o1 + 0xe ]
a0071634:  c2 06 20 10  ld  [ %i0 + 0x10 ], %g1
a0071638:  83 30 60 08  srl  %g1, 8, %g1
a007163c:  c2 2a 60 0f  stb  %g1, [ %o1 + 0xf ]
a0071640:  c2 16 20 14  lduh  [ %i0 + 0x14 ], %g1
a0071644:  40 00 80 aa  call  0xa00918ec
a0071648:  c2 2a 60 0c  stb  %g1, [ %o1 + 0xc ]
a007164c:  10 80 04 92  b  0xa0072894
a0071650:  80 8c e0 ff  btst  0xff, %l3
a0071654:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a0071658:  80 a2 20 01  cmp  %o0, 1
a007165c:  38 80 04 8e  bgu,a   0xa0072894
a0071660:  80 8c e0 ff  btst  0xff, %l3
a0071664:  9b 2a 20 02  sll  %o0, 2, %o5
a0071668:  9a 03 40 08  add  %o5, %o0, %o5
a007166c:  19 2a 01 ea  sethi  %hi(0xa807a800), %o4
a0071670:  98 13 20 fc  or  %o4, 0xfc, %o4	! 0xa807a8fc
a0071674:  9b 2b 60 02  sll  %o5, 2, %o5
a0071678:  d6 13 00 0d  lduh  [ %o4 + %o5 ], %o3
a007167c:  03 00 00 10  sethi  %hi(0x4000), %g1
a0071680:  82 2a c0 01  andn  %o3, %g1, %g1
a0071684:  40 00 80 9a  call  0xa00918ec
a0071688:  c2 33 00 0d  sth  %g1, [ %o4 + %o5 ]
a007168c:  10 80 04 82  b  0xa0072894
a0071690:  80 8c e0 ff  btst  0xff, %l3
a0071694:  d8 06 20 04  ld  [ %i0 + 4 ], %o4
a0071698:  90 0b 20 ff  and  %o4, 0xff, %o0
a007169c:  9b 2a 20 02  sll  %o0, 2, %o5
a00716a0:  9a 03 40 08  add  %o5, %o0, %o5
a00716a4:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00716a8:  82 10 60 fc  or  %g1, 0xfc, %g1	! 0xa807a8fc
a00716ac:  9b 2b 60 02  sll  %o5, 2, %o5
a00716b0:  9a 03 40 01  add  %o5, %g1, %o5
a00716b4:  97 33 20 08  srl  %o4, 8, %o3
a00716b8:  95 33 20 10  srl  %o4, 0x10, %o2
a00716bc:  c2 06 20 08  ld  [ %i0 + 8 ], %g1
a00716c0:  99 33 20 18  srl  %o4, 0x18, %o4
a00716c4:  c2 2b 60 13  stb  %g1, [ %o5 + 0x13 ]
a00716c8:  d6 2b 60 10  stb  %o3, [ %o5 + 0x10 ]
a00716cc:  d4 2b 60 11  stb  %o2, [ %o5 + 0x11 ]
a00716d0:  80 a2 20 01  cmp  %o0, 1
a00716d4:  18 80 04 6f  bgu  0xa0072890
a00716d8:  d8 2b 60 12  stb  %o4, [ %o5 + 0x12 ]
a00716dc:  40 00 80 84  call  0xa00918ec
a00716e0:  01 00 00 00  nop
a00716e4:  10 80 04 6c  b  0xa0072894
a00716e8:  80 8c e0 ff  btst  0xff, %l3
a00716ec:  e0 0e 20 07  ldub  [ %i0 + 7 ], %l0
a00716f0:  80 a4 20 01  cmp  %l0, 1
a00716f4:  38 80 04 67  bgu,a   0xa0072890
a00716f8:  a6 10 20 01  mov  1, %l3
a00716fc:  92 10 20 00  clr  %o1
a0071700:  94 10 20 3a  mov  0x3a, %o2
a0071704:  40 00 da 35  call  0xa00a7fd8
a0071708:  90 10 00 10  mov  %l0, %o0
a007170c:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a0071710:  92 10 20 00  clr  %o1
a0071714:  94 10 20 3b  mov  0x3b, %o2
a0071718:  40 00 da 30  call  0xa00a7fd8
a007171c:  90 10 00 10  mov  %l0, %o0
a0071720:  d0 2f bf d9  stb  %o0, [ %fp + -39 ]
a0071724:  92 10 20 00  clr  %o1
a0071728:  94 10 20 3c  mov  0x3c, %o2
a007172c:  40 00 da 2b  call  0xa00a7fd8
a0071730:  90 10 00 10  mov  %l0, %o0
a0071734:  d0 2f bf da  stb  %o0, [ %fp + -38 ]
a0071738:  92 10 20 00  clr  %o1
a007173c:  94 10 20 3d  mov  0x3d, %o2
a0071740:  40 00 da 26  call  0xa00a7fd8
a0071744:  90 10 00 10  mov  %l0, %o0
a0071748:  d0 2f bf db  stb  %o0, [ %fp + -37 ]
a007174c:  92 10 20 00  clr  %o1
a0071750:  94 10 20 60  mov  0x60, %o2
a0071754:  40 00 da 21  call  0xa00a7fd8
a0071758:  90 10 00 10  mov  %l0, %o0
a007175c:  d0 2f bf dc  stb  %o0, [ %fp + -36 ]
a0071760:  92 10 20 00  clr  %o1
a0071764:  94 10 20 61  mov  0x61, %o2
a0071768:  40 00 da 1c  call  0xa00a7fd8
a007176c:  90 10 00 10  mov  %l0, %o0
a0071770:  d0 2f bf dd  stb  %o0, [ %fp + -35 ]
a0071774:  92 10 20 00  clr  %o1
a0071778:  94 10 20 62  mov  0x62, %o2
a007177c:  40 00 da 17  call  0xa00a7fd8
a0071780:  90 10 00 10  mov  %l0, %o0
a0071784:  d0 2f bf de  stb  %o0, [ %fp + -34 ]
a0071788:  90 10 00 10  mov  %l0, %o0
a007178c:  92 10 20 00  clr  %o1
a0071790:  40 00 da 12  call  0xa00a7fd8
a0071794:  94 10 20 63  mov  0x63, %o2
a0071798:  d0 2f bf df  stb  %o0, [ %fp + -33 ]
a007179c:  10 80 04 3d  b  0xa0072890
a00717a0:  a6 10 20 01  mov  1, %l3
a00717a4:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a00717a8:  a4 08 60 ff  and  %g1, 0xff, %l2
a00717ac:  95 2c a0 02  sll  %l2, 2, %o2
a00717b0:  94 02 80 12  add  %o2, %l2, %o2
a00717b4:  13 2a 01 ea  sethi  %hi(0xa807a800), %o1
a00717b8:  92 12 61 28  or  %o1, 0x128, %o1	! 0xa807a928
a00717bc:  95 2a a0 03  sll  %o2, 3, %o2
a00717c0:  d8 02 40 0a  ld  [ %o1 + %o2 ], %o4
a00717c4:  83 30 60 08  srl  %g1, 8, %g1
a00717c8:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a00717cc:  9a 2b 00 0d  andn  %o4, %o5, %o5
a00717d0:  83 28 60 1f  sll  %g1, 0x1f, %g1
a00717d4:  9a 13 40 01  or  %o5, %g1, %o5
a00717d8:  da 22 40 0a  st  %o5, [ %o1 + %o2 ]
a00717dc:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a00717e0:  83 30 60 09  srl  %g1, 9, %g1
a00717e4:  82 08 60 01  and  %g1, 1, %g1
a00717e8:  19 10 00 00  sethi  %hi(0x40000000), %o4
a00717ec:  98 2b 40 0c  andn  %o5, %o4, %o4
a00717f0:  83 28 60 1e  sll  %g1, 0x1e, %g1
a00717f4:  98 13 00 01  or  %o4, %g1, %o4
a00717f8:  d8 22 40 0a  st  %o4, [ %o1 + %o2 ]
a00717fc:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a0071800:  83 30 60 0a  srl  %g1, 0xa, %g1
a0071804:  82 08 60 01  and  %g1, 1, %g1
a0071808:  1b 08 00 00  sethi  %hi(0x20000000), %o5
a007180c:  9a 2b 00 0d  andn  %o4, %o5, %o5
a0071810:  83 28 60 1d  sll  %g1, 0x1d, %g1
a0071814:  9a 13 40 01  or  %o5, %g1, %o5
a0071818:  da 22 40 0a  st  %o5, [ %o1 + %o2 ]
a007181c:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a0071820:  83 30 60 0b  srl  %g1, 0xb, %g1
a0071824:  82 08 60 01  and  %g1, 1, %g1
a0071828:  19 04 00 00  sethi  %hi(0x10000000), %o4
a007182c:  98 2b 40 0c  andn  %o5, %o4, %o4
a0071830:  83 28 60 1c  sll  %g1, 0x1c, %g1
a0071834:  98 13 00 01  or  %o4, %g1, %o4
a0071838:  d8 22 40 0a  st  %o4, [ %o1 + %o2 ]
a007183c:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a0071840:  83 30 60 0c  srl  %g1, 0xc, %g1
a0071844:  82 08 60 01  and  %g1, 1, %g1
a0071848:  17 02 00 00  sethi  %hi(0x8000000), %o3
a007184c:  96 2b 00 0b  andn  %o4, %o3, %o3
a0071850:  83 28 60 1b  sll  %g1, 0x1b, %g1
a0071854:  96 12 c0 01  or  %o3, %g1, %o3
a0071858:  d6 22 40 0a  st  %o3, [ %o1 + %o2 ]
a007185c:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a0071860:  83 30 60 0d  srl  %g1, 0xd, %g1
a0071864:  82 08 60 01  and  %g1, 1, %g1
a0071868:  1b 00 80 00  sethi  %hi(0x2000000), %o5
a007186c:  9a 2a c0 0d  andn  %o3, %o5, %o5
a0071870:  83 28 60 19  sll  %g1, 0x19, %g1
a0071874:  9a 13 40 01  or  %o5, %g1, %o5
a0071878:  da 22 40 0a  st  %o5, [ %o1 + %o2 ]
a007187c:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a0071880:  1b 00 3f c0  sethi  %hi(0xff0000), %o5
a0071884:  82 08 40 0d  and  %g1, %o5, %g1
a0071888:  94 02 80 09  add  %o2, %o1, %o2
a007188c:  83 30 60 10  srl  %g1, 0x10, %g1
a0071890:  c2 2a a0 01  stb  %g1, [ %o2 + 1 ]
a0071894:  c2 06 20 08  ld  [ %i0 + 8 ], %g1
a0071898:  82 08 40 0d  and  %g1, %o5, %g1
a007189c:  e2 16 20 0a  lduh  [ %i0 + 0xa ], %l1
a00718a0:  83 30 60 10  srl  %g1, 0x10, %g1
a00718a4:  c2 2a a0 14  stb  %g1, [ %o2 + 0x14 ]
a00718a8:  c2 0e 20 08  ldub  [ %i0 + 8 ], %g1
a00718ac:  c2 2a a0 15  stb  %g1, [ %o2 + 0x15 ]
a00718b0:  e0 06 20 18  ld  [ %i0 + 0x18 ], %l0
a00718b4:  d2 06 20 0c  ld  [ %i0 + 0xc ], %o1
a00718b8:  d0 06 20 10  ld  [ %i0 + 0x10 ], %o0
a00718bc:  de 06 20 14  ld  [ %i0 + 0x14 ], %o7
a00718c0:  83 32 60 10  srl  %o1, 0x10, %g1
a00718c4:  9b 32 20 10  srl  %o0, 0x10, %o5
a00718c8:  97 34 20 10  srl  %l0, 0x10, %o3
a00718cc:  99 33 e0 10  srl  %o7, 0x10, %o4
a00718d0:  c2 32 a0 06  sth  %g1, [ %o2 + 6 ]
a00718d4:  da 32 a0 0a  sth  %o5, [ %o2 + 0xa ]
a00718d8:  d8 32 a0 0e  sth  %o4, [ %o2 + 0xe ]
a00718dc:  d6 32 a0 12  sth  %o3, [ %o2 + 0x12 ]
a00718e0:  de 32 a0 0c  sth  %o7, [ %o2 + 0xc ]
a00718e4:  e2 22 a0 18  st  %l1, [ %o2 + 0x18 ]
a00718e8:  d2 32 a0 04  sth  %o1, [ %o2 + 4 ]
a00718ec:  d0 32 a0 08  sth  %o0, [ %o2 + 8 ]
a00718f0:  e0 32 a0 10  sth  %l0, [ %o2 + 0x10 ]
a00718f4:  a0 07 bf b0  add  %fp, -80, %l0
a00718f8:  92 02 a0 04  add  %o2, 4, %o1
a00718fc:  c0 2a a0 25  clrb  [ %o2 + 0x25 ]
a0071900:  90 10 00 10  mov  %l0, %o0
a0071904:  40 00 ff 35  call  0xa00b15d8
a0071908:  94 10 20 1c  mov  0x1c, %o2
a007190c:  90 10 00 12  mov  %l2, %o0
a0071910:  40 00 59 6e  call  0xa0087ec8
a0071914:  92 10 00 10  mov  %l0, %o1
a0071918:  10 80 03 df  b  0xa0072894
a007191c:  80 8c e0 ff  btst  0xff, %l3
a0071920:  da 06 20 04  ld  [ %i0 + 4 ], %o5
a0071924:  a0 0b 60 ff  and  %o5, 0xff, %l0
a0071928:  93 2c 20 02  sll  %l0, 2, %o1
a007192c:  92 02 40 10  add  %o1, %l0, %o1
a0071930:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a0071934:  82 10 61 28  or  %g1, 0x128, %g1	! 0xa807a928
a0071938:  93 2a 60 03  sll  %o1, 3, %o1
a007193c:  92 02 40 01  add  %o1, %g1, %o1
a0071940:  83 33 60 08  srl  %o5, 8, %g1
a0071944:  9b 33 60 10  srl  %o5, 0x10, %o5
a0071948:  a2 07 bf 90  add  %fp, -112, %l1
a007194c:  c2 2a 60 14  stb  %g1, [ %o1 + 0x14 ]
a0071950:  da 2a 60 15  stb  %o5, [ %o1 + 0x15 ]
a0071954:  92 02 60 04  add  %o1, 4, %o1
a0071958:  90 10 00 11  mov  %l1, %o0
a007195c:  40 00 ff 1f  call  0xa00b15d8
a0071960:  94 10 20 1c  mov  0x1c, %o2
a0071964:  90 10 00 10  mov  %l0, %o0
a0071968:  40 00 59 58  call  0xa0087ec8
a007196c:  92 10 00 11  mov  %l1, %o1
a0071970:  10 80 03 c9  b  0xa0072894
a0071974:  80 8c e0 ff  btst  0xff, %l3
a0071978:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a007197c:  a2 08 60 ff  and  %g1, 0xff, %l1
a0071980:  9b 2c 60 02  sll  %l1, 2, %o5
a0071984:  9a 03 40 11  add  %o5, %l1, %o5
a0071988:  17 2a 01 ea  sethi  %hi(0xa807a800), %o3
a007198c:  96 12 e1 28  or  %o3, 0x128, %o3	! 0xa807a928
a0071990:  9b 2b 60 03  sll  %o5, 3, %o5
a0071994:  a5 30 60 08  srl  %g1, 8, %l2
a0071998:  d4 02 c0 0d  ld  [ %o3 + %o5 ], %o2
a007199c:  98 0c a0 01  and  %l2, 1, %o4
a00719a0:  03 02 00 00  sethi  %hi(0x8000000), %g1
a00719a4:  99 2b 20 1b  sll  %o4, 0x1b, %o4
a00719a8:  82 2a 80 01  andn  %o2, %g1, %g1
a00719ac:  82 10 40 0c  or  %g1, %o4, %g1
a00719b0:  92 03 40 0b  add  %o5, %o3, %o1
a00719b4:  a0 07 bf 70  add  %fp, -144, %l0
a00719b8:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00719bc:  92 02 60 04  add  %o1, 4, %o1
a00719c0:  90 10 00 10  mov  %l0, %o0
a00719c4:  40 00 ff 05  call  0xa00b15d8
a00719c8:  94 10 20 1c  mov  0x1c, %o2
a00719cc:  90 10 00 11  mov  %l1, %o0
a00719d0:  40 00 59 3e  call  0xa0087ec8
a00719d4:  92 10 00 10  mov  %l0, %o1
a00719d8:  10 80 03 af  b  0xa0072894
a00719dc:  80 8c e0 ff  btst  0xff, %l3
a00719e0:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a00719e4:  a2 08 60 ff  and  %g1, 0xff, %l1
a00719e8:  9b 2c 60 02  sll  %l1, 2, %o5
a00719ec:  9a 03 40 11  add  %o5, %l1, %o5
a00719f0:  17 2a 01 ea  sethi  %hi(0xa807a800), %o3
a00719f4:  96 12 e1 28  or  %o3, 0x128, %o3	! 0xa807a928
a00719f8:  9b 2b 60 03  sll  %o5, 3, %o5
a00719fc:  a5 30 60 08  srl  %g1, 8, %l2
a0071a00:  d4 02 c0 0d  ld  [ %o3 + %o5 ], %o2
a0071a04:  98 0c a0 01  and  %l2, 1, %o4
a0071a08:  03 04 00 00  sethi  %hi(0x10000000), %g1
a0071a0c:  99 2b 20 1c  sll  %o4, 0x1c, %o4
a0071a10:  82 2a 80 01  andn  %o2, %g1, %g1
a0071a14:  82 10 40 0c  or  %g1, %o4, %g1
a0071a18:  92 03 40 0b  add  %o5, %o3, %o1
a0071a1c:  a0 07 bf 50  add  %fp, -176, %l0
a0071a20:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a0071a24:  92 02 60 04  add  %o1, 4, %o1
a0071a28:  90 10 00 10  mov  %l0, %o0
a0071a2c:  40 00 fe eb  call  0xa00b15d8
a0071a30:  94 10 20 1c  mov  0x1c, %o2
a0071a34:  90 10 00 11  mov  %l1, %o0
a0071a38:  40 00 59 24  call  0xa0087ec8
a0071a3c:  92 10 00 10  mov  %l0, %o1
a0071a40:  10 80 03 95  b  0xa0072894
a0071a44:  80 8c e0 ff  btst  0xff, %l3
a0071a48:  da 06 20 04  ld  [ %i0 + 4 ], %o5
a0071a4c:  82 0b 60 ff  and  %o5, 0xff, %g1
a0071a50:  99 28 60 02  sll  %g1, 2, %o4
a0071a54:  98 03 00 01  add  %o4, %g1, %o4
a0071a58:  17 2a 01 ea  sethi  %hi(0xa807a800), %o3
a0071a5c:  96 12 e1 28  or  %o3, 0x128, %o3	! 0xa807a928
a0071a60:  99 2b 20 03  sll  %o4, 3, %o4
a0071a64:  a5 33 60 08  srl  %o5, 8, %l2
a0071a68:  d4 02 c0 0c  ld  [ %o3 + %o4 ], %o2
a0071a6c:  9a 0c a0 01  and  %l2, 1, %o5
a0071a70:  03 10 00 00  sethi  %hi(0x40000000), %g1
a0071a74:  82 2a 80 01  andn  %o2, %g1, %g1
a0071a78:  9b 2b 60 1e  sll  %o5, 0x1e, %o5
a0071a7c:  82 10 40 0d  or  %g1, %o5, %g1
a0071a80:  10 80 03 84  b  0xa0072890
a0071a84:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a0071a88:  d6 06 20 04  ld  [ %i0 + 4 ], %o3
a0071a8c:  90 0a e0 ff  and  %o3, 0xff, %o0
a0071a90:  9b 2a 20 02  sll  %o0, 2, %o5
a0071a94:  9a 03 40 08  add  %o5, %o0, %o5
a0071a98:  19 2a 01 ea  sethi  %hi(0xa807a800), %o4
a0071a9c:  98 13 21 28  or  %o4, 0x128, %o4	! 0xa807a928
a0071aa0:  9b 2b 60 03  sll  %o5, 3, %o5
a0071aa4:  c2 03 00 0d  ld  [ %o4 + %o5 ], %g1
a0071aa8:  13 20 00 00  sethi  %hi(0x80000000), %o1
a0071aac:  a5 32 e0 08  srl  %o3, 8, %l2
a0071ab0:  92 28 40 09  andn  %g1, %o1, %o1
a0071ab4:  83 2c a0 1f  sll  %l2, 0x1f, %g1
a0071ab8:  92 12 40 01  or  %o1, %g1, %o1
a0071abc:  d2 23 00 0d  st  %o1, [ %o4 + %o5 ]
a0071ac0:  40 00 5f 26  call  0xa0089758
a0071ac4:  93 32 60 1f  srl  %o1, 0x1f, %o1
a0071ac8:  10 80 03 73  b  0xa0072894
a0071acc:  80 8c e0 ff  btst  0xff, %l3
a0071ad0:  40 00 5d 16  call  0xa0088f28
a0071ad4:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a0071ad8:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a0071adc:  10 80 03 6d  b  0xa0072890
a0071ae0:  a6 10 20 01  mov  1, %l3
a0071ae4:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0071ae8:  93 2a 20 08  sll  %o0, 8, %o1
a0071aec:  90 0a 20 ff  and  %o0, 0xff, %o0
a0071af0:  40 00 5d 28  call  0xa0088f90
a0071af4:  93 32 60 10  srl  %o1, 0x10, %o1
a0071af8:  10 80 03 67  b  0xa0072894
a0071afc:  80 8c e0 ff  btst  0xff, %l3
a0071b00:  e4 0e 20 07  ldub  [ %i0 + 7 ], %l2
a0071b04:  a0 10 20 00  clr  %l0
a0071b08:  98 0c 20 ff  and  %l0, 0xff, %o4
a0071b0c:  83 33 20 01  srl  %o4, 1, %g1
a0071b10:  83 28 60 02  sll  %g1, 2, %g1
a0071b14:  9a 0b 20 01  and  %o4, 1, %o5
a0071b18:  82 00 40 18  add  %g1, %i0, %g1
a0071b1c:  d6 00 60 08  ld  [ %g1 + 8 ], %o3
a0071b20:  9b 2b 60 04  sll  %o5, 4, %o5
a0071b24:  82 03 60 08  add  %o5, 8, %g1
a0071b28:  95 32 c0 0d  srl  %o3, %o5, %o2
a0071b2c:  99 2b 20 04  sll  %o4, 4, %o4
a0071b30:  90 0c a0 0f  and  %l2, 0xf, %o0
a0071b34:  9f 32 c0 01  srl  %o3, %g1, %o7
a0071b38:  90 12 00 0c  or  %o0, %o4, %o0
a0071b3c:  92 0a a0 ff  and  %o2, 0xff, %o1
a0071b40:  94 0b e0 ff  and  %o7, 0xff, %o2
a0071b44:  40 00 e6 81  call  0xa00ab548
a0071b48:  90 0a 20 ff  and  %o0, 0xff, %o0
a0071b4c:  a0 04 20 01  inc  %l0
a0071b50:  82 0c 20 ff  and  %l0, 0xff, %g1
a0071b54:  80 a0 60 03  cmp  %g1, 3
a0071b58:  08 bf ff ed  bleu  0xa0071b0c
a0071b5c:  98 0c 20 ff  and  %l0, 0xff, %o4
a0071b60:  10 80 03 4d  b  0xa0072894
a0071b64:  80 8c e0 ff  btst  0xff, %l3
a0071b68:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0071b6c:  93 2a 20 08  sll  %o0, 8, %o1
a0071b70:  90 0a 20 ff  and  %o0, 0xff, %o0
a0071b74:  40 00 5f 32  call  0xa008983c
a0071b78:  93 32 60 10  srl  %o1, 0x10, %o1
a0071b7c:  10 80 03 46  b  0xa0072894
a0071b80:  80 8c e0 ff  btst  0xff, %l3
a0071b84:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a0071b88:  90 08 60 ff  and  %g1, 0xff, %o0
a0071b8c:  99 2a 20 02  sll  %o0, 2, %o4
a0071b90:  a5 30 60 08  srl  %g1, 8, %l2
a0071b94:  98 03 00 08  add  %o4, %o0, %o4
a0071b98:  17 2a 01 ea  sethi  %hi(0xa807a800), %o3
a0071b9c:  96 12 e1 28  or  %o3, 0x128, %o3	! 0xa807a928
a0071ba0:  99 2b 20 03  sll  %o4, 3, %o4
a0071ba4:  92 0c a0 ff  and  %l2, 0xff, %o1
a0071ba8:  d4 02 c0 0c  ld  [ %o3 + %o4 ], %o2
a0071bac:  9a 0a 60 01  and  %o1, 1, %o5
a0071bb0:  03 00 80 00  sethi  %hi(0x2000000), %g1
a0071bb4:  82 2a 80 01  andn  %o2, %g1, %g1
a0071bb8:  9b 2b 60 19  sll  %o5, 0x19, %o5
a0071bbc:  82 10 40 0d  or  %g1, %o5, %g1
a0071bc0:  40 00 58 64  call  0xa0087d50
a0071bc4:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a0071bc8:  10 80 03 33  b  0xa0072894
a0071bcc:  80 8c e0 ff  btst  0xff, %l3
a0071bd0:  7f c5 13 66  call  0x9f1b6968
a0071bd4:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a0071bd8:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a0071bdc:  10 80 03 2d  b  0xa0072890
a0071be0:  a6 10 20 01  mov  1, %l3
a0071be4:  40 00 5c af  call  0xa0088ea0
a0071be8:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a0071bec:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a0071bf0:  10 80 03 28  b  0xa0072890
a0071bf4:  a6 10 20 01  mov  1, %l3
a0071bf8:  7f c5 13 40  call  0x9f1b68f8
a0071bfc:  d0 0e 20 06  ldub  [ %i0 + 6 ], %o0
a0071c00:  10 80 03 24  b  0xa0072890
a0071c04:  a6 10 20 01  mov  1, %l3
a0071c08:  da 06 20 04  ld  [ %i0 + 4 ], %o5
a0071c0c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0071c10:  10 80 03 20  b  0xa0072890
a0071c14:  da 28 60 dd  stb  %o5, [ %g1 + 0xdd ]	! 0xa80788dd
a0071c18:  92 10 20 00  clr  %o1
a0071c1c:  40 00 52 67  call  0xa00865b8
a0071c20:  90 10 20 00  clr  %o0
a0071c24:  40 01 00 ef  call  0xa00b1fe0
a0071c28:  90 10 20 01  mov  1, %o0
a0071c2c:  7f ff ed 76  call  0xa006d204
a0071c30:  01 00 00 00  nop
a0071c34:  9a 10 20 01  mov  1, %o5	! 0x1
a0071c38:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0071c3c:  7f ff f8 a8  call  0xa006fedc
a0071c40:  da 28 60 dc  stb  %o5, [ %g1 + 0xdc ]	! 0xa80788dc
a0071c44:  40 01 00 e7  call  0xa00b1fe0
a0071c48:  90 10 20 00  clr  %o0
a0071c4c:  10 80 00 00  b  0xa0071c4c
a0071c50:  01 00 00 00  nop
a0071c54:  d8 06 20 04  ld  [ %i0 + 4 ], %o4
a0071c58:  90 0b 20 ff  and  %o4, 0xff, %o0
a0071c5c:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a0071c60:  9a 5a 21 2c  smul  %o0, 0x12c, %o5
a0071c64:  82 10 60 18  or  %g1, 0x18, %g1
a0071c68:  9a 03 40 01  add  %o5, %g1, %o5
a0071c6c:  99 33 20 08  srl  %o4, 8, %o4
a0071c70:  d8 2b 61 1f  stb  %o4, [ %o5 + 0x11f ]
a0071c74:  40 00 fc ed  call  0xa00b1028
a0071c78:  92 10 20 00  clr  %o1
a0071c7c:  10 80 03 06  b  0xa0072894
a0071c80:  80 8c e0 ff  btst  0xff, %l3
a0071c84:  e0 06 20 04  ld  [ %i0 + 4 ], %l0
a0071c88:  94 07 bf 3c  add  %fp, -196, %o2
a0071c8c:  c0 27 bf 3c  clr  [ %fp + -196 ]
a0071c90:  90 10 20 00  clr  %o0
a0071c94:  92 10 20 03  mov  3, %o1
a0071c98:  7f ff f7 84  call  0xa006faa8
a0071c9c:  96 10 20 01  mov  1, %o3
a0071ca0:  da 07 bf 3c  ld  [ %fp + -196 ], %o5
a0071ca4:  83 33 60 10  srl  %o5, 0x10, %g1
a0071ca8:  a0 28 40 10  andn  %g1, %l0, %l0
a0071cac:  a0 0c 20 ff  and  %l0, 0xff, %l0
a0071cb0:  03 00 3f c0  sethi  %hi(0xff0000), %g1
a0071cb4:  82 2b 40 01  andn  %o5, %g1, %g1
a0071cb8:  a1 2c 20 10  sll  %l0, 0x10, %l0
a0071cbc:  82 10 40 10  or  %g1, %l0, %g1
a0071cc0:  c2 27 bf 3c  st  %g1, [ %fp + -196 ]
a0071cc4:  90 10 20 00  clr  %o0
a0071cc8:  92 10 20 03  mov  3, %o1
a0071ccc:  94 07 bf 3c  add  %fp, -196, %o2
a0071cd0:  7f ff f7 81  call  0xa006fad4
a0071cd4:  96 10 20 01  mov  1, %o3
a0071cd8:  10 80 02 ef  b  0xa0072894
a0071cdc:  80 8c e0 ff  btst  0xff, %l3
a0071ce0:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a0071ce4:  99 30 60 08  srl  %g1, 8, %o4
a0071ce8:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0071cec:  82 08 60 ff  and  %g1, 0xff, %g1
a0071cf0:  9a 13 60 d0  or  %o5, 0xd0, %o5
a0071cf4:  10 80 02 e7  b  0xa0072890
a0071cf8:  d8 2b 40 01  stb  %o4, [ %o5 + %g1 ]
a0071cfc:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a0071d00:  80 a0 60 05  cmp  %g1, 5
a0071d04:  18 80 02 e3  bgu  0xa0072890
a0071d08:  a6 10 20 01  mov  1, %l3
a0071d0c:  1b 28 01 c1  sethi  %hi(0xa0070400), %o5
a0071d10:  83 28 60 02  sll  %g1, 2, %g1
a0071d14:  9a 13 63 40  or  %o5, 0x340, %o5
a0071d18:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a0071d1c:  81 c0 40 00  jmp  %g1
a0071d20:  01 00 00 00  nop
a0071d24:  10 80 00 0f  b  0xa0071d60
a0071d28:  c0 2f bf d8  clrb  [ %fp + -40 ]
a0071d2c:  10 80 00 03  b  0xa0071d38
a0071d30:  90 10 20 00  clr  %o0
a0071d34:  90 10 20 01  mov  1, %o0
a0071d38:  40 00 c2 63  call  0xa00a26c4
a0071d3c:  01 00 00 00  nop
a0071d40:  10 80 00 08  b  0xa0071d60
a0071d44:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a0071d48:  10 80 00 03  b  0xa0071d54
a0071d4c:  90 10 20 00  clr  %o0
a0071d50:  90 10 20 01  mov  1, %o0
a0071d54:  40 00 ee 9d  call  0xa00ad7c8
a0071d58:  01 00 00 00  nop
a0071d5c:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a0071d60:  10 80 02 cc  b  0xa0072890
a0071d64:  a6 10 20 01  mov  1, %l3
a0071d68:  e4 0e 20 07  ldub  [ %i0 + 7 ], %l2
a0071d6c:  82 0c a0 ff  and  %l2, 0xff, %g1
a0071d70:  80 a0 60 02  cmp  %g1, 2
a0071d74:  02 80 00 07  be  0xa0071d90
a0071d78:  c0 2f bf d8  clrb  [ %fp + -40 ]
a0071d7c:  80 a0 60 03  cmp  %g1, 3
a0071d80:  02 80 00 07  be  0xa0071d9c
a0071d84:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0071d88:  10 80 02 c2  b  0xa0072890
a0071d8c:  a6 10 20 01  mov  1, %l3
a0071d90:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0071d94:  10 80 00 03  b  0xa0071da0
a0071d98:  c2 08 62 81  ldub  [ %g1 + 0x281 ], %g1	! 0xa807d681
a0071d9c:  c2 08 63 31  ldub  [ %g1 + 0x331 ], %g1
a0071da0:  c2 2f bf d8  stb  %g1, [ %fp + -40 ]
a0071da4:  10 80 02 bb  b  0xa0072890
a0071da8:  a6 10 20 01  mov  1, %l3
a0071dac:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a0071db0:  80 a0 60 05  cmp  %g1, 5
a0071db4:  18 80 00 14  bgu  0xa0071e04
a0071db8:  a6 10 20 01  mov  1, %l3
a0071dbc:  1b 28 01 c1  sethi  %hi(0xa0070400), %o5
a0071dc0:  83 28 60 02  sll  %g1, 2, %g1
a0071dc4:  9a 13 63 28  or  %o5, 0x328, %o5
a0071dc8:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a0071dcc:  81 c0 40 00  jmp  %g1
a0071dd0:  01 00 00 00  nop
a0071dd4:  10 80 00 0b  b  0xa0071e00
a0071dd8:  c0 2f bf d8  clrb  [ %fp + -40 ]
a0071ddc:  10 80 00 03  b  0xa0071de8
a0071de0:  90 10 20 00  clr  %o0
a0071de4:  90 10 20 01  mov  1, %o0
a0071de8:  40 00 c2 30  call  0xa00a26a8
a0071dec:  a6 10 20 01  mov  1, %l3
a0071df0:  10 80 00 05  b  0xa0071e04
a0071df4:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a0071df8:  82 10 20 08  mov  8, %g1
a0071dfc:  c2 2f bf d8  stb  %g1, [ %fp + -40 ]
a0071e00:  a6 10 20 01  mov  1, %l3
a0071e04:  10 80 02 a4  b  0xa0072894
a0071e08:  80 8c e0 ff  btst  0xff, %l3
a0071e0c:  a0 10 20 00  clr  %l0
a0071e10:  9a 07 bf f8  add  %fp, -8, %o5
a0071e14:  82 0c 20 ff  and  %l0, 0xff, %g1
a0071e18:  82 03 40 01  add  %o5, %g1, %g1
a0071e1c:  e0 28 7f e0  stb  %l0, [ %g1 + -32 ]
a0071e20:  a0 04 20 01  inc  %l0
a0071e24:  82 0c 20 ff  and  %l0, 0xff, %g1
a0071e28:  80 a0 60 1b  cmp  %g1, 0x1b
a0071e2c:  08 bf ff fc  bleu  0xa0071e1c
a0071e30:  82 03 40 01  add  %o5, %g1, %g1
a0071e34:  10 80 02 97  b  0xa0072890
a0071e38:  a6 10 20 01  mov  1, %l3
a0071e3c:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0071e40:  82 0a 20 ff  and  %o0, 0xff, %g1
a0071e44:  80 a0 60 01  cmp  %g1, 1
a0071e48:  9a 10 00 08  mov  %o0, %o5
a0071e4c:  98 10 20 00  clr  %o4
a0071e50:  08 80 00 04  bleu  0xa0071e60
a0071e54:  83 32 20 08  srl  %o0, 8, %g1
a0071e58:  9a 02 3f fe  add  %o0, -2, %o5
a0071e5c:  98 10 20 01  mov  1, %o4
a0071e60:  82 08 60 ff  and  %g1, 0xff, %g1
a0071e64:  80 a0 60 00  cmp  %g1, 0
a0071e68:  02 80 00 07  be  0xa0071e84
a0071e6c:  80 8b 20 ff  btst  0xff, %o4
a0071e70:  80 a0 60 01  cmp  %g1, 1
a0071e74:  02 80 00 13  be  0xa0071ec0
a0071e78:  a6 10 20 01  mov  1, %l3
a0071e7c:  10 80 02 86  b  0xa0072894
a0071e80:  80 8c e0 ff  btst  0xff, %l3
a0071e84:  02 80 00 06  be  0xa0071e9c
a0071e88:  90 0b 60 ff  and  %o5, 0xff, %o0
a0071e8c:  40 00 c2 86  call  0xa00a28a4
a0071e90:  01 00 00 00  nop
a0071e94:  10 80 00 05  b  0xa0071ea8
a0071e98:  80 8a 20 ff  btst  0xff, %o0
a0071e9c:  40 00 7c 8d  call  0xa00910d0
a0071ea0:  01 00 00 00  nop
a0071ea4:  80 8a 20 ff  btst  0xff, %o0
a0071ea8:  12 80 00 04  bne  0xa0071eb8
a0071eac:  82 10 20 01  mov  1, %g1
a0071eb0:  10 80 00 0f  b  0xa0071eec
a0071eb4:  c0 2c 00 00  clrb  [ %l0 ]
a0071eb8:  10 80 00 0d  b  0xa0071eec
a0071ebc:  c2 2c 00 00  stb  %g1, [ %l0 ]
a0071ec0:  80 8b 20 ff  btst  0xff, %o4
a0071ec4:  22 80 00 05  be,a   0xa0071ed8
a0071ec8:  c0 2c 20 05  clrb  [ %l0 + 5 ]
a0071ecc:  40 00 c2 b9  call  0xa00a29b0
a0071ed0:  90 0b 60 ff  and  %o5, 0xff, %o0
a0071ed4:  c0 2c 20 05  clrb  [ %l0 + 5 ]
a0071ed8:  c0 2c 00 00  clrb  [ %l0 ]
a0071edc:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a0071ee0:  c0 2c 20 02  clrb  [ %l0 + 2 ]
a0071ee4:  c0 2c 20 03  clrb  [ %l0 + 3 ]
a0071ee8:  c0 2c 20 04  clrb  [ %l0 + 4 ]
a0071eec:  10 80 02 69  b  0xa0072890
a0071ef0:  a6 10 20 01  mov  1, %l3
a0071ef4:  a0 10 20 00  clr  %l0
a0071ef8:  9a 07 bf f8  add  %fp, -8, %o5
a0071efc:  82 0c 20 ff  and  %l0, 0xff, %g1
a0071f00:  82 03 40 01  add  %o5, %g1, %g1
a0071f04:  e0 28 7f e0  stb  %l0, [ %g1 + -32 ]
a0071f08:  a0 04 20 01  inc  %l0
a0071f0c:  82 0c 20 ff  and  %l0, 0xff, %g1
a0071f10:  80 a0 60 1b  cmp  %g1, 0x1b
a0071f14:  08 bf ff fc  bleu  0xa0071f04
a0071f18:  82 03 40 01  add  %o5, %g1, %g1
a0071f1c:  10 80 02 5d  b  0xa0072890
a0071f20:  a6 10 20 01  mov  1, %l3
a0071f24:  40 00 6e 6d  call  0xa008d8d8
a0071f28:  a6 10 20 01  mov  1, %l3
a0071f2c:  10 80 02 59  b  0xa0072890
a0071f30:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a0071f34:  a0 10 20 00  clr  %l0
a0071f38:  9a 07 bf f8  add  %fp, -8, %o5
a0071f3c:  82 0c 20 ff  and  %l0, 0xff, %g1
a0071f40:  82 03 40 01  add  %o5, %g1, %g1
a0071f44:  e0 28 7f e0  stb  %l0, [ %g1 + -32 ]
a0071f48:  a0 04 20 01  inc  %l0
a0071f4c:  82 0c 20 ff  and  %l0, 0xff, %g1
a0071f50:  80 a0 60 1b  cmp  %g1, 0x1b
a0071f54:  08 bf ff fc  bleu  0xa0071f44
a0071f58:  82 03 40 01  add  %o5, %g1, %g1
a0071f5c:  10 80 02 4d  b  0xa0072890
a0071f60:  a6 10 20 01  mov  1, %l3
a0071f64:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0071f68:  95 32 20 03  srl  %o0, 3, %o2
a0071f6c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0071f70:  94 0a a0 e0  and  %o2, 0xe0, %o2
a0071f74:  40 00 d3 23  call  0xa00a6c00
a0071f78:  92 10 22 52  mov  0x252, %o1
a0071f7c:  10 80 02 46  b  0xa0072894
a0071f80:  80 8c e0 ff  btst  0xff, %l3
a0071f84:  da 06 20 04  ld  [ %i0 + 4 ], %o5
a0071f88:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a0071f8c:  da 28 62 28  stb  %o5, [ %g1 + 0x228 ]	! 0xa8079228
a0071f90:  9a 10 20 01  mov  1, %o5
a0071f94:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0071f98:  10 80 02 3e  b  0xa0072890
a0071f9c:  da 28 63 48  stb  %o5, [ %g1 + 0x348 ]	! 0xa8078748
a0071fa0:  90 10 00 18  mov  %i0, %o0
a0071fa4:  7f ff f9 24  call  0xa0070434
a0071fa8:  92 10 00 10  mov  %l0, %o1
a0071fac:  10 80 02 39  b  0xa0072890
a0071fb0:  a6 10 20 01  mov  1, %l3
a0071fb4:  d2 0e 20 07  ldub  [ %i0 + 7 ], %o1
a0071fb8:  7f c4 fe 80  call  0x9f1b19b8
a0071fbc:  d0 0e 20 06  ldub  [ %i0 + 6 ], %o0
a0071fc0:  10 80 02 35  b  0xa0072894
a0071fc4:  80 8c e0 ff  btst  0xff, %l3
a0071fc8:  d8 06 20 04  ld  [ %i0 + 4 ], %o4
a0071fcc:  a2 0b 20 ff  and  %o4, 0xff, %l1
a0071fd0:  9b 2c 60 02  sll  %l1, 2, %o5
a0071fd4:  9a 03 40 11  add  %o5, %l1, %o5
a0071fd8:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a0071fdc:  9b 2b 60 03  sll  %o5, 3, %o5
a0071fe0:  82 10 61 28  or  %g1, 0x128, %g1
a0071fe4:  a0 03 40 01  add  %o5, %g1, %l0
a0071fe8:  99 33 20 08  srl  %o4, 8, %o4
a0071fec:  c2 04 20 20  ld  [ %l0 + 0x20 ], %g1
a0071ff0:  98 0b 20 03  and  %o4, 3, %o4
a0071ff4:  17 00 00 18  sethi  %hi(0x6000), %o3
a0071ff8:  96 28 40 0b  andn  %g1, %o3, %o3
a0071ffc:  99 2b 20 0d  sll  %o4, 0xd, %o4
a0072000:  96 12 c0 0c  or  %o3, %o4, %o3
a0072004:  d6 24 20 20  st  %o3, [ %l0 + 0x20 ]
a0072008:  c2 0e 20 06  ldub  [ %i0 + 6 ], %g1
a007200c:  83 30 60 02  srl  %g1, 2, %g1
a0072010:  82 08 60 01  and  %g1, 1, %g1
a0072014:  1b 00 00 04  sethi  %hi(0x1000), %o5
a0072018:  9a 2a c0 0d  andn  %o3, %o5, %o5
a007201c:  83 28 60 0c  sll  %g1, 0xc, %g1
a0072020:  9a 13 40 01  or  %o5, %g1, %o5
a0072024:  80 a4 60 00  cmp  %l1, 0
a0072028:  02 80 00 05  be  0xa007203c
a007202c:  da 24 20 20  st  %o5, [ %l0 + 0x20 ]
a0072030:  da 16 20 04  lduh  [ %i0 + 4 ], %o5
a0072034:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0072038:  da 28 61 2d  stb  %o5, [ %g1 + 0x12d ]	! 0xa807cd2d
a007203c:  c2 06 20 08  ld  [ %i0 + 8 ], %g1
a0072040:  c2 2c 20 23  stb  %g1, [ %l0 + 0x23 ]
a0072044:  c2 06 20 08  ld  [ %i0 + 8 ], %g1
a0072048:  83 30 60 08  srl  %g1, 8, %g1
a007204c:  80 a4 60 00  cmp  %l1, 0
a0072050:  02 80 00 0b  be  0xa007207c
a0072054:  c2 2c 20 24  stb  %g1, [ %l0 + 0x24 ]
a0072058:  da 16 20 08  lduh  [ %i0 + 8 ], %o5
a007205c:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0072060:  da 28 61 c0  stb  %o5, [ %g1 + 0x1c0 ]	! 0xa80761c0
a0072064:  da 0e 20 08  ldub  [ %i0 + 8 ], %o5
a0072068:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a007206c:  da 28 61 bf  stb  %o5, [ %g1 + 0x1bf ]	! 0xa80761bf
a0072070:  da 06 20 0c  ld  [ %i0 + 0xc ], %o5
a0072074:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0072078:  da 28 61 a8  stb  %o5, [ %g1 + 0x1a8 ]	! 0xa80761a8
a007207c:  c2 0e 20 0e  ldub  [ %i0 + 0xe ], %g1
a0072080:  da 04 20 20  ld  [ %l0 + 0x20 ], %o5
a0072084:  82 08 60 01  and  %g1, 1, %g1
a0072088:  83 28 60 0b  sll  %g1, 0xb, %g1
a007208c:  9a 0b 77 ff  and  %o5, -2049, %o5
a0072090:  9a 13 40 01  or  %o5, %g1, %o5
a0072094:  93 33 60 0c  srl  %o5, 0xc, %o1
a0072098:  da 24 20 20  st  %o5, [ %l0 + 0x20 ]
a007209c:  90 10 00 11  mov  %l1, %o0
a00720a0:  40 00 e0 ef  call  0xa00aa45c
a00720a4:  92 0a 60 01  and  %o1, 1, %o1
a00720a8:  d2 04 20 20  ld  [ %l0 + 0x20 ], %o1
a00720ac:  93 32 60 0d  srl  %o1, 0xd, %o1
a00720b0:  90 10 00 11  mov  %l1, %o0
a00720b4:  40 00 e0 fa  call  0xa00aa49c
a00720b8:  92 0a 60 03  and  %o1, 3, %o1
a00720bc:  90 10 00 11  mov  %l1, %o0
a00720c0:  40 00 4d dc  call  0xa0085830
a00720c4:  d2 0c 20 23  ldub  [ %l0 + 0x23 ], %o1
a00720c8:  90 10 00 11  mov  %l1, %o0
a00720cc:  40 00 4d ef  call  0xa0085888
a00720d0:  d2 0c 20 24  ldub  [ %l0 + 0x24 ], %o1
a00720d4:  d2 04 20 20  ld  [ %l0 + 0x20 ], %o1
a00720d8:  93 32 60 0b  srl  %o1, 0xb, %o1
a00720dc:  90 10 00 11  mov  %l1, %o0
a00720e0:  40 00 4d fb  call  0xa00858cc
a00720e4:  92 0a 60 01  and  %o1, 1, %o1
a00720e8:  10 80 01 eb  b  0xa0072894
a00720ec:  80 8c e0 ff  btst  0xff, %l3
a00720f0:  7f c5 71 ef  call  0x9f1ce8ac
a00720f4:  90 10 00 18  mov  %i0, %o0
a00720f8:  10 80 01 e7  b  0xa0072894
a00720fc:  80 8c e0 ff  btst  0xff, %l3
a0072100:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0072104:  a5 32 20 08  srl  %o0, 8, %l2
a0072108:  90 0a 20 ff  and  %o0, 0xff, %o0
a007210c:  40 00 5b 75  call  0xa0088ee0
a0072110:  92 0c a0 ff  and  %l2, 0xff, %o1
a0072114:  10 80 01 e0  b  0xa0072894
a0072118:  80 8c e0 ff  btst  0xff, %l3
a007211c:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a0072120:  80 a2 20 04  cmp  %o0, 4
a0072124:  38 80 01 dc  bgu,a   0xa0072894
a0072128:  80 8c e0 ff  btst  0xff, %l3
a007212c:  40 00 5f 3e  call  0xa0089e24
a0072130:  01 00 00 00  nop
a0072134:  10 80 01 d8  b  0xa0072894
a0072138:  80 8c e0 ff  btst  0xff, %l3
a007213c:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0072140:  a5 32 20 08  srl  %o0, 8, %l2
a0072144:  90 0a 20 ff  and  %o0, 0xff, %o0
a0072148:  40 00 5f 43  call  0xa0089e54
a007214c:  92 0c a0 ff  and  %l2, 0xff, %o1
a0072150:  10 80 01 d1  b  0xa0072894
a0072154:  80 8c e0 ff  btst  0xff, %l3
a0072158:  da 06 20 04  ld  [ %i0 + 4 ], %o5
a007215c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0072160:  80 8b 60 ff  btst  0xff, %o5
a0072164:  12 80 01 cb  bne  0xa0072890
a0072168:  da 28 62 0c  stb  %o5, [ %g1 + 0x20c ]
a007216c:  7f ff f7 92  call  0xa006ffb4
a0072170:  01 00 00 00  nop
a0072174:  80 8a 20 ff  btst  0xff, %o0
a0072178:  02 80 00 04  be  0xa0072188
a007217c:  01 00 00 00  nop
a0072180:  40 00 5b 95  call  0xa0088fd4
a0072184:  90 10 20 01  mov  1, %o0	! 0x1
a0072188:  7f ff f7 8f  call  0xa006ffc4
a007218c:  01 00 00 00  nop
a0072190:  80 8a 20 ff  btst  0xff, %o0
a0072194:  02 80 00 04  be  0xa00721a4
a0072198:  01 00 00 00  nop
a007219c:  40 00 5b 8e  call  0xa0088fd4
a00721a0:  90 10 20 02  mov  2, %o0	! 0x2
a00721a4:  7f ff f7 8c  call  0xa006ffd4
a00721a8:  01 00 00 00  nop
a00721ac:  80 8a 20 ff  btst  0xff, %o0
a00721b0:  02 80 00 04  be  0xa00721c0
a00721b4:  01 00 00 00  nop
a00721b8:  40 00 5b 87  call  0xa0088fd4
a00721bc:  90 10 20 03  mov  3, %o0	! 0x3
a00721c0:  7f ff f7 89  call  0xa006ffe4
a00721c4:  01 00 00 00  nop
a00721c8:  80 8a 20 ff  btst  0xff, %o0
a00721cc:  22 80 01 b2  be,a   0xa0072894
a00721d0:  80 8c e0 ff  btst  0xff, %l3
a00721d4:  40 00 5b 80  call  0xa0088fd4
a00721d8:  90 10 20 04  mov  4, %o0
a00721dc:  10 80 01 ae  b  0xa0072894
a00721e0:  80 8c e0 ff  btst  0xff, %l3
a00721e4:  da 06 20 04  ld  [ %i0 + 4 ], %o5
a00721e8:  91 2b 60 10  sll  %o5, 0x10, %o0
a00721ec:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00721f0:  da 30 60 f6  sth  %o5, [ %g1 + 0xf6 ]	! 0xa807a8f6
a00721f4:  7f c5 47 2f  call  0x9f1c3eb0
a00721f8:  91 32 20 10  srl  %o0, 0x10, %o0
a00721fc:  da 16 20 04  lduh  [ %i0 + 4 ], %o5
a0072200:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a0072204:  10 80 01 a3  b  0xa0072890
a0072208:  da 30 60 f8  sth  %o5, [ %g1 + 0xf8 ]	! 0xa807a8f8
a007220c:  7f ff ec e7  call  0xa006d5a8
a0072210:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a0072214:  7f c5 40 f8  call  0x9f1c25f4
a0072218:  90 0a 20 ff  and  %o0, 0xff, %o0
a007221c:  10 80 01 9e  b  0xa0072894
a0072220:  80 8c e0 ff  btst  0xff, %l3
a0072224:  7f ff ec e1  call  0xa006d5a8
a0072228:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a007222c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0072230:  7f c5 40 fa  call  0x9f1c2618
a0072234:  d2 0e 20 06  ldub  [ %i0 + 6 ], %o1
a0072238:  10 80 01 97  b  0xa0072894
a007223c:  80 8c e0 ff  btst  0xff, %l3
a0072240:  7f c5 47 2f  call  0x9f1c3efc
a0072244:  a6 10 20 01  mov  1, %l3
a0072248:  10 80 01 92  b  0xa0072890
a007224c:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a0072250:  7f c5 47 38  call  0x9f1c3f30
a0072254:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a0072258:  10 80 01 8f  b  0xa0072894
a007225c:  80 8c e0 ff  btst  0xff, %l3
a0072260:  7f c5 47 3d  call  0x9f1c3f54
a0072264:  01 00 00 00  nop
a0072268:  10 80 01 8b  b  0xa0072894
a007226c:  80 8c e0 ff  btst  0xff, %l3
a0072270:  7f c5 47 46  call  0x9f1c3f88
a0072274:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a0072278:  10 80 01 87  b  0xa0072894
a007227c:  80 8c e0 ff  btst  0xff, %l3
a0072280:  7f ff c5 b4  call  0xa0063950
a0072284:  01 00 00 00  nop
a0072288:  7f c5 41 5d  call  0x9f1c27fc
a007228c:  90 10 20 00  clr  %o0	! 0x0
a0072290:  10 80 01 81  b  0xa0072894
a0072294:  80 8c e0 ff  btst  0xff, %l3
a0072298:  7f c5 47 36  call  0x9f1c3f70
a007229c:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a00722a0:  10 80 01 7d  b  0xa0072894
a00722a4:  80 8c e0 ff  btst  0xff, %l3
a00722a8:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00722ac:  80 a0 60 05  cmp  %g1, 5
a00722b0:  02 80 00 10  be  0xa00722f0
a00722b4:  01 00 00 00  nop
a00722b8:  14 80 00 07  bg  0xa00722d4
a00722bc:  21 2a 01 ea  sethi  %hi(0xa807a800), %l0
a00722c0:  80 a0 60 04  cmp  %g1, 4
a00722c4:  02 80 00 07  be  0xa00722e0
a00722c8:  01 00 00 00  nop
a00722cc:  10 80 00 0e  b  0xa0072304
a00722d0:  c0 24 21 24  clr  [ %l0 + 0x124 ]
a00722d4:  80 a0 60 08  cmp  %g1, 8
a00722d8:  34 80 00 0b  bg,a   0xa0072304
a00722dc:  c0 24 21 24  clr  [ %l0 + 0x124 ]
a00722e0:  40 00 e8 d0  call  0xa00ac620
a00722e4:  90 10 20 00  clr  %o0
a00722e8:  10 80 00 07  b  0xa0072304
a00722ec:  d0 24 21 24  st  %o0, [ %l0 + 0x124 ]
a00722f0:  40 00 e8 cc  call  0xa00ac620
a00722f4:  90 10 20 01  mov  1, %o0
a00722f8:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00722fc:  10 80 00 03  b  0xa0072308
a0072300:  d0 20 61 24  st  %o0, [ %g1 + 0x124 ]	! 0xa807a924
a0072304:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a0072308:  da 00 61 24  ld  [ %g1 + 0x124 ], %o5	! 0xa807a924
a007230c:  99 33 60 10  srl  %o5, 0x10, %o4
a0072310:  83 33 60 08  srl  %o5, 8, %g1
a0072314:  c2 2f bf d9  stb  %g1, [ %fp + -39 ]
a0072318:  d8 2f bf da  stb  %o4, [ %fp + -38 ]
a007231c:  da 2f bf d8  stb  %o5, [ %fp + -40 ]
a0072320:  c0 2f bf db  clrb  [ %fp + -37 ]
a0072324:  10 80 01 5b  b  0xa0072890
a0072328:  a6 10 20 01  mov  1, %l3
a007232c:  7f ff f7 32  call  0xa006fff4
a0072330:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a0072334:  10 80 01 58  b  0xa0072894
a0072338:  80 8c e0 ff  btst  0xff, %l3
a007233c:  7f ff ec 4c  call  0xa006d46c
a0072340:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a0072344:  10 80 01 54  b  0xa0072894
a0072348:  80 8c e0 ff  btst  0xff, %l3
a007234c:  7f ff f7 2d  call  0xa0070000
a0072350:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0072354:  10 80 01 50  b  0xa0072894
a0072358:  80 8c e0 ff  btst  0xff, %l3
a007235c:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a0072360:  92 10 23 e7  mov  0x3e7, %o1
a0072364:  40 00 03 38  call  0xa0073044
a0072368:  90 12 21 00  or  %o0, 0x100, %o0
a007236c:  92 10 20 00  clr  %o1
a0072370:  40 00 50 92  call  0xa00865b8
a0072374:  90 10 20 00  clr  %o0
a0072378:  40 00 ff 1a  call  0xa00b1fe0
a007237c:  90 10 20 01  mov  1, %o0
a0072380:  7f ff eb 5f  call  0xa006d0fc
a0072384:  01 00 00 00  nop
a0072388:  9a 10 20 01  mov  1, %o5	! 0x1
a007238c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0072390:  7f ff f6 d3  call  0xa006fedc
a0072394:  da 28 60 dc  stb  %o5, [ %g1 + 0xdc ]	! 0xa80788dc
a0072398:  40 00 ff 12  call  0xa00b1fe0
a007239c:  90 10 20 00  clr  %o0
a00723a0:  10 80 00 00  b  0xa00723a0
a00723a4:  01 00 00 00  nop
a00723a8:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a00723ac:  80 a2 20 01  cmp  %o0, 1
a00723b0:  18 80 01 39  bgu  0xa0072894
a00723b4:  80 8c e0 ff  btst  0xff, %l3
a00723b8:  40 00 8e d0  call  0xa0095ef8
a00723bc:  a6 10 20 01  mov  1, %l3
a00723c0:  90 0a 20 01  and  %o0, 1, %o0
a00723c4:  10 80 01 33  b  0xa0072890
a00723c8:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a00723cc:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a00723d0:  90 08 60 ff  and  %g1, 0xff, %o0
a00723d4:  80 a2 20 01  cmp  %o0, 1
a00723d8:  18 80 01 2e  bgu  0xa0072890
a00723dc:  a5 30 60 08  srl  %g1, 8, %l2
a00723e0:  40 00 87 ca  call  0xa0094308
a00723e4:  92 0c a0 ff  and  %l2, 0xff, %o1
a00723e8:  10 80 01 2b  b  0xa0072894
a00723ec:  80 8c e0 ff  btst  0xff, %l3
a00723f0:  d8 06 20 04  ld  [ %i0 + 4 ], %o4
a00723f4:  82 0b 20 ff  and  %o4, 0xff, %g1
a00723f8:  9a 00 40 01  add  %g1, %g1, %o5
a00723fc:  9a 03 40 01  add  %o5, %g1, %o5
a0072400:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0072404:  9b 2b 60 03  sll  %o5, 3, %o5
a0072408:  82 10 60 64  or  %g1, 0x64, %g1
a007240c:  9a 03 40 01  add  %o5, %g1, %o5
a0072410:  99 33 20 08  srl  %o4, 8, %o4
a0072414:  10 80 01 1f  b  0xa0072890
a0072418:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a007241c:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a0072420:  9a 08 60 ff  and  %g1, 0xff, %o5
a0072424:  80 a3 60 02  cmp  %o5, 2
a0072428:  95 30 60 08  srl  %g1, 8, %o2
a007242c:  9f 30 60 10  srl  %g1, 0x10, %o7
a0072430:  02 80 00 06  be  0xa0072448
a0072434:  90 10 20 00  clr  %o0
a0072438:  82 1b 60 03  xor  %o5, 3, %g1
a007243c:  80 a0 00 01  cmp  %g0, %g1
a0072440:  82 60 20 00  subx  %g0, 0, %g1
a0072444:  90 10 60 01  or  %g1, 1, %o0
a0072448:  82 0a a0 ff  and  %o2, 0xff, %g1
a007244c:  82 18 60 01  xor  %g1, 1, %g1
a0072450:  80 a0 00 01  cmp  %g0, %g1
a0072454:  90 0a 20 ff  and  %o0, 0xff, %o0
a0072458:  9a 60 3f ff  subx  %g0, -1, %o5
a007245c:  82 1a 20 ff  xor  %o0, 0xff, %g1
a0072460:  80 a0 00 01  cmp  %g0, %g1
a0072464:  82 40 20 00  addx  %g0, 0, %g1
a0072468:  80 8b 40 01  btst  %o5, %g1
a007246c:  02 80 00 06  be  0xa0072484
a0072470:  92 0b e0 ff  and  %o7, 0xff, %o1
a0072474:  40 00 bf e9  call  0xa00a2418
a0072478:  01 00 00 00  nop
a007247c:  10 80 01 06  b  0xa0072894
a0072480:  80 8c e0 ff  btst  0xff, %l3
a0072484:  40 00 c0 38  call  0xa00a2564
a0072488:  90 10 00 09  mov  %o1, %o0
a007248c:  10 80 01 02  b  0xa0072894
a0072490:  80 8c e0 ff  btst  0xff, %l3
a0072494:  d2 06 20 04  ld  [ %i0 + 4 ], %o1
a0072498:  c2 07 bf 48  ld  [ %fp + -184 ], %g1
a007249c:  19 20 00 00  sethi  %hi(0x80000000), %o4
a00724a0:  94 0a 60 ff  and  %o1, 0xff, %o2
a00724a4:  9b 2a 60 1f  sll  %o1, 0x1f, %o5
a00724a8:  98 28 40 0c  andn  %g1, %o4, %o4
a00724ac:  98 13 00 0d  or  %o4, %o5, %o4
a00724b0:  83 32 a0 01  srl  %o2, 1, %g1
a00724b4:  82 08 60 01  and  %g1, 1, %g1
a00724b8:  1b 10 00 00  sethi  %hi(0x40000000), %o5
a00724bc:  9a 2b 00 0d  andn  %o4, %o5, %o5
a00724c0:  83 28 60 1e  sll  %g1, 0x1e, %g1
a00724c4:  9a 13 40 01  or  %o5, %g1, %o5
a00724c8:  99 32 a0 02  srl  %o2, 2, %o4
a00724cc:  98 0b 20 01  and  %o4, 1, %o4
a00724d0:  03 08 00 00  sethi  %hi(0x20000000), %g1
a00724d4:  82 2b 40 01  andn  %o5, %g1, %g1
a00724d8:  99 2b 20 1d  sll  %o4, 0x1d, %o4
a00724dc:  82 10 40 0c  or  %g1, %o4, %g1
a00724e0:  9b 32 a0 03  srl  %o2, 3, %o5
a00724e4:  9a 0b 60 01  and  %o5, 1, %o5
a00724e8:  19 04 00 00  sethi  %hi(0x10000000), %o4
a00724ec:  98 28 40 0c  andn  %g1, %o4, %o4
a00724f0:  9b 2b 60 1c  sll  %o5, 0x1c, %o5
a00724f4:  98 13 00 0d  or  %o4, %o5, %o4
a00724f8:  83 32 a0 04  srl  %o2, 4, %g1
a00724fc:  1b 02 00 00  sethi  %hi(0x8000000), %o5
a0072500:  9a 2b 00 0d  andn  %o4, %o5, %o5
a0072504:  82 08 60 01  and  %g1, 1, %g1
a0072508:  83 28 60 1b  sll  %g1, 0x1b, %g1
a007250c:  99 32 a0 05  srl  %o2, 5, %o4
a0072510:  9a 13 40 01  or  %o5, %g1, %o5
a0072514:  98 0b 20 01  and  %o4, 1, %o4
a0072518:  17 01 00 00  sethi  %hi(0x4000000), %o3
a007251c:  96 2b 40 0b  andn  %o5, %o3, %o3
a0072520:  99 2b 20 1a  sll  %o4, 0x1a, %o4
a0072524:  83 32 a0 06  srl  %o2, 6, %g1
a0072528:  96 12 c0 0c  or  %o3, %o4, %o3
a007252c:  82 08 60 01  and  %g1, 1, %g1
a0072530:  1b 00 80 00  sethi  %hi(0x2000000), %o5
a0072534:  9a 2a c0 0d  andn  %o3, %o5, %o5
a0072538:  83 28 60 19  sll  %g1, 0x19, %g1
a007253c:  9a 13 40 01  or  %o5, %g1, %o5
a0072540:  95 32 a0 07  srl  %o2, 7, %o2
a0072544:  03 00 40 00  sethi  %hi(0x1000000), %g1
a0072548:  82 2b 40 01  andn  %o5, %g1, %g1
a007254c:  95 2a a0 18  sll  %o2, 0x18, %o2
a0072550:  82 10 40 0a  or  %g1, %o2, %g1
a0072554:  c2 27 bf 48  st  %g1, [ %fp + -184 ]
a0072558:  83 32 60 08  srl  %o1, 8, %g1
a007255c:  c2 2f bf 4a  stb  %g1, [ %fp + -182 ]
a0072560:  9b 32 60 10  srl  %o1, 0x10, %o5
a0072564:  c2 07 bf 48  ld  [ %fp + -184 ], %g1
a0072568:  9a 0b 60 03  and  %o5, 3, %o5
a007256c:  19 00 30 00  sethi  %hi(0xc00000), %o4
a0072570:  98 28 40 0c  andn  %g1, %o4, %o4
a0072574:  9b 2b 60 16  sll  %o5, 0x16, %o5
a0072578:  93 32 60 18  srl  %o1, 0x18, %o1
a007257c:  98 13 00 0d  or  %o4, %o5, %o4
a0072580:  92 0a 60 03  and  %o1, 3, %o1
a0072584:  03 00 0c 00  sethi  %hi(0x300000), %g1
a0072588:  82 2b 00 01  andn  %o4, %g1, %g1
a007258c:  93 2a 60 14  sll  %o1, 0x14, %o1
a0072590:  82 10 40 09  or  %g1, %o1, %g1
a0072594:  c2 27 bf 48  st  %g1, [ %fp + -184 ]
a0072598:  c2 17 bf 48  lduh  [ %fp + -184 ], %g1
a007259c:  c2 37 bf 40  sth  %g1, [ %fp + -192 ]
a00725a0:  c2 0f bf 4a  ldub  [ %fp + -182 ], %g1
a00725a4:  c2 2f bf 42  stb  %g1, [ %fp + -190 ]
a00725a8:  40 00 69 80  call  0xa008cba8
a00725ac:  90 07 bf 40  add  %fp, -192, %o0
a00725b0:  10 80 00 b9  b  0xa0072894
a00725b4:  80 8c e0 ff  btst  0xff, %l3
a00725b8:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a00725bc:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00725c0:  d0 28 61 80  stb  %o0, [ %g1 + 0x180 ]	! 0xa807cd80
a00725c4:  40 00 60 a9  call  0xa008a868
a00725c8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00725cc:  10 80 00 b2  b  0xa0072894
a00725d0:  80 8c e0 ff  btst  0xff, %l3
a00725d4:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a00725d8:  95 32 20 08  srl  %o0, 8, %o2
a00725dc:  9f 32 20 10  srl  %o0, 0x10, %o7
a00725e0:  92 0a a0 ff  and  %o2, 0xff, %o1
a00725e4:  97 32 20 18  srl  %o0, 0x18, %o3
a00725e8:  94 0b e0 ff  and  %o7, 0xff, %o2
a00725ec:  40 00 68 ef  call  0xa008c9a8
a00725f0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00725f4:  10 80 00 a8  b  0xa0072894
a00725f8:  80 8c e0 ff  btst  0xff, %l3
a00725fc:  d2 0e 20 06  ldub  [ %i0 + 6 ], %o1
a0072600:  40 00 63 cf  call  0xa008b53c
a0072604:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a0072608:  10 80 00 a3  b  0xa0072894
a007260c:  80 8c e0 ff  btst  0xff, %l3
a0072610:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a0072614:  98 08 60 ff  and  %g1, 0xff, %o4
a0072618:  80 a3 20 01  cmp  %o4, 1
a007261c:  12 80 00 08  bne  0xa007263c
a0072620:  83 30 60 08  srl  %g1, 8, %g1
a0072624:  91 28 60 10  sll  %g1, 0x10, %o0
a0072628:  91 32 20 10  srl  %o0, 0x10, %o0
a007262c:  40 00 61 33  call  0xa008aaf8
a0072630:  92 10 20 01  mov  1, %o1
a0072634:  10 80 00 98  b  0xa0072894
a0072638:  80 8c e0 ff  btst  0xff, %l3
a007263c:  80 a3 20 00  cmp  %o4, 0
a0072640:  32 80 00 95  bne,a   0xa0072894
a0072644:  80 8c e0 ff  btst  0xff, %l3
a0072648:  91 28 60 10  sll  %g1, 0x10, %o0
a007264c:  40 00 60 f3  call  0xa008aa18
a0072650:  91 32 20 10  srl  %o0, 0x10, %o0
a0072654:  10 80 00 90  b  0xa0072894
a0072658:  80 8c e0 ff  btst  0xff, %l3
a007265c:  40 00 60 d5  call  0xa008a9b0
a0072660:  01 00 00 00  nop
a0072664:  10 80 00 8c  b  0xa0072894
a0072668:  80 8c e0 ff  btst  0xff, %l3
a007266c:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0072670:  93 2a 20 08  sll  %o0, 8, %o1
a0072674:  95 32 20 18  srl  %o0, 0x18, %o2
a0072678:  93 32 60 10  srl  %o1, 0x10, %o1
a007267c:  40 00 d3 11  call  0xa00a72c0
a0072680:  90 0a 20 ff  and  %o0, 0xff, %o0
a0072684:  10 80 00 84  b  0xa0072894
a0072688:  80 8c e0 ff  btst  0xff, %l3
a007268c:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0072690:  83 32 20 08  srl  %o0, 8, %g1
a0072694:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0072698:  80 a3 60 01  cmp  %o5, 1
a007269c:  83 28 60 10  sll  %g1, 0x10, %g1
a00726a0:  08 80 00 08  bleu  0xa00726c0
a00726a4:  95 32 20 18  srl  %o0, 0x18, %o2
a00726a8:  90 02 3f fe  add  %o0, -2, %o0
a00726ac:  90 0a 20 ff  and  %o0, 0xff, %o0
a00726b0:  40 00 d0 d3  call  0xa00a69fc
a00726b4:  93 30 60 10  srl  %g1, 0x10, %o1
a00726b8:  10 80 00 77  b  0xa0072894
a00726bc:  80 8c e0 ff  btst  0xff, %l3
a00726c0:  90 10 00 0d  mov  %o5, %o0
a00726c4:  40 00 cf c0  call  0xa00a65c4
a00726c8:  93 30 60 10  srl  %g1, 0x10, %o1
a00726cc:  10 80 00 72  b  0xa0072894
a00726d0:  80 8c e0 ff  btst  0xff, %l3
a00726d4:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a00726d8:  83 32 20 08  srl  %o0, 8, %g1
a00726dc:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00726e0:  80 a3 60 01  cmp  %o5, 1
a00726e4:  08 80 00 08  bleu  0xa0072704
a00726e8:  83 28 60 10  sll  %g1, 0x10, %g1
a00726ec:  90 02 3f fe  add  %o0, -2, %o0
a00726f0:  93 30 60 10  srl  %g1, 0x10, %o1
a00726f4:  40 00 d0 b0  call  0xa00a69b4
a00726f8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00726fc:  10 80 00 06  b  0xa0072714
a0072700:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a0072704:  90 10 00 0d  mov  %o5, %o0
a0072708:  40 00 cf 9d  call  0xa00a657c
a007270c:  93 30 60 10  srl  %g1, 0x10, %o1
a0072710:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a0072714:  10 80 00 5f  b  0xa0072890
a0072718:  a6 10 20 01  mov  1, %l3
a007271c:  d2 0e 20 06  ldub  [ %i0 + 6 ], %o1
a0072720:  94 10 00 10  mov  %l0, %o2
a0072724:  40 00 77 17  call  0xa0090380
a0072728:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a007272c:  10 80 00 59  b  0xa0072890
a0072730:  a6 10 20 01  mov  1, %l3
a0072734:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0072738:  95 32 20 08  srl  %o0, 8, %o2
a007273c:  92 0a a0 ff  and  %o2, 0xff, %o1
a0072740:  95 32 20 10  srl  %o0, 0x10, %o2
a0072744:  d6 0e 20 0b  ldub  [ %i0 + 0xb ], %o3
a0072748:  40 00 d6 43  call  0xa00a8054
a007274c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0072750:  10 80 00 51  b  0xa0072894
a0072754:  80 8c e0 ff  btst  0xff, %l3
a0072758:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a007275c:  93 2a 20 08  sll  %o0, 8, %o1
a0072760:  95 32 20 18  srl  %o0, 0x18, %o2
a0072764:  93 32 60 10  srl  %o1, 0x10, %o1
a0072768:  40 00 e7 87  call  0xa00ac584
a007276c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0072770:  10 80 00 49  b  0xa0072894
a0072774:  80 8c e0 ff  btst  0xff, %l3
a0072778:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a007277c:  93 2a 20 08  sll  %o0, 8, %o1
a0072780:  95 32 20 18  srl  %o0, 0x18, %o2
a0072784:  93 32 60 10  srl  %o1, 0x10, %o1
a0072788:  40 00 e7 72  call  0xa00ac550
a007278c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0072790:  10 80 00 41  b  0xa0072894
a0072794:  80 8c e0 ff  btst  0xff, %l3
a0072798:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a007279c:  93 2a 20 08  sll  %o0, 8, %o1
a00727a0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00727a4:  40 00 d1 05  call  0xa00a6bb8
a00727a8:  93 32 60 10  srl  %o1, 0x10, %o1
a00727ac:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a00727b0:  10 80 00 38  b  0xa0072890
a00727b4:  a6 10 20 01  mov  1, %l3
a00727b8:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a00727bc:  93 2a 20 08  sll  %o0, 8, %o1
a00727c0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00727c4:  40 00 d4 3c  call  0xa00a78b4
a00727c8:  93 32 60 10  srl  %o1, 0x10, %o1
a00727cc:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a00727d0:  10 80 00 30  b  0xa0072890
a00727d4:  a6 10 20 01  mov  1, %l3
a00727d8:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a00727dc:  93 2a 20 08  sll  %o0, 8, %o1
a00727e0:  95 32 20 18  srl  %o0, 0x18, %o2
a00727e4:  93 32 60 10  srl  %o1, 0x10, %o1
a00727e8:  40 00 d4 45  call  0xa00a78fc
a00727ec:  90 0a 20 ff  and  %o0, 0xff, %o0
a00727f0:  10 80 00 29  b  0xa0072894
a00727f4:  80 8c e0 ff  btst  0xff, %l3
a00727f8:  d8 0e 20 17  ldub  [ %i0 + 0x17 ], %o4
a00727fc:  d0 06 20 04  ld  [ %i0 + 4 ], %o0
a0072800:  d2 06 20 08  ld  [ %i0 + 8 ], %o1
a0072804:  d4 06 20 0c  ld  [ %i0 + 0xc ], %o2
a0072808:  7f ff e9 e9  call  0xa006cfac
a007280c:  d6 06 20 10  ld  [ %i0 + 0x10 ], %o3
a0072810:  10 80 00 21  b  0xa0072894
a0072814:  80 8c e0 ff  btst  0xff, %l3
a0072818:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a007281c:  80 8a 20 01  btst  1, %o0
a0072820:  02 80 00 04  be  0xa0072830
a0072824:  80 8a 20 02  btst  2, %o0
a0072828:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a007282c:  c0 28 60 48  clrb  [ %g1 + 0x48 ]	! 0xa8078c48
a0072830:  02 80 00 04  be  0xa0072840
a0072834:  80 8a 20 04  btst  4, %o0
a0072838:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a007283c:  c0 28 60 49  clrb  [ %g1 + 0x49 ]	! 0xa8078c49
a0072840:  02 80 00 15  be  0xa0072894
a0072844:  80 8c e0 ff  btst  0xff, %l3
a0072848:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007284c:  10 80 00 12  b  0xa0072894
a0072850:  c0 28 62 0a  clrb  [ %g1 + 0x20a ]	! 0xa8078a0a
a0072854:  7f c5 6a d1  call  0x9f1cd398
a0072858:  90 10 00 18  mov  %i0, %o0
a007285c:  10 80 00 0e  b  0xa0072894
a0072860:  80 8c e0 ff  btst  0xff, %l3
a0072864:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a0072868:  40 00 f5 63  call  0xa00afdf4
a007286c:  92 10 20 00  clr  %o1
a0072870:  10 80 00 09  b  0xa0072894
a0072874:  80 8c e0 ff  btst  0xff, %l3
a0072878:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a007287c:  90 12 21 18  or  %o0, 0x118, %o0	! 0xa0066518
a0072880:  d6 06 20 0c  ld  [ %i0 + 0xc ], %o3
a0072884:  d2 06 20 04  ld  [ %i0 + 4 ], %o1
a0072888:  40 00 01 ef  call  0xa0073044
a007288c:  d4 06 20 08  ld  [ %i0 + 8 ], %o2
a0072890:  80 8c e0 ff  btst  0xff, %l3
a0072894:  22 80 00 07  be,a   0xa00728b0
a0072898:  c0 27 bf 38  clr  [ %fp + -200 ]
a007289c:  90 10 00 15  mov  %l5, %o0
a00728a0:  92 10 20 1c  mov  0x1c, %o1
a00728a4:  7f ff f5 35  call  0xa006fd78
a00728a8:  94 07 bf d8  add  %fp, -40, %o2
a00728ac:  c0 27 bf 38  clr  [ %fp + -200 ]
a00728b0:  90 10 20 08  mov  8, %o0
a00728b4:  92 10 20 00  clr  %o1
a00728b8:  94 07 bf 38  add  %fp, -200, %o2
a00728bc:  7f ff f4 86  call  0xa006fad4
a00728c0:  96 10 20 01  mov  1, %o3
a00728c4:  1b 33 c0 f4  sethi  %hi(0xcf03d000), %o5
a00728c8:  d8 0f bf d0  ldub  [ %fp + -48 ], %o4
a00728cc:  82 13 60 04  or  %o5, 4, %g1
a00728d0:  d8 20 40 00  st  %o4, [ %g1 ]
a00728d4:  d8 0f bf d1  ldub  [ %fp + -47 ], %o4
a00728d8:  82 13 60 08  or  %o5, 8, %g1
a00728dc:  d8 20 40 00  st  %o4, [ %g1 ]
a00728e0:  82 13 60 0c  or  %o5, 0xc, %g1
a00728e4:  d8 0f bf d2  ldub  [ %fp + -46 ], %o4
a00728e8:  d8 20 40 00  st  %o4, [ %g1 ]
a00728ec:  9a 13 60 10  or  %o5, 0x10, %o5
a00728f0:  c2 0f bf d3  ldub  [ %fp + -45 ], %g1
a00728f4:  c2 23 40 00  st  %g1, [ %o5 ]
a00728f8:  81 c7 e0 08  ret
a00728fc:  81 e8 00 00  restore
