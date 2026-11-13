# leon2m FUN_a0083d80 0xa0083d80-0xa0083ff0 (624 bytes)
a0083d80:  9d e3 bf 78  save  %sp, -136, %sp
a0083d84:  1f 2a 00 90  sethi  %hi(0xa8024000), %o7
a0083d88:  96 10 20 46  mov  0x46, %o3
a0083d8c:  94 10 20 09  mov  9, %o2
a0083d90:  92 10 20 03  mov  3, %o1
a0083d94:  b0 13 e0 10  or  %o7, 0x10, %i0
a0083d98:  9a 10 3f bf  mov  -65, %o5
a0083d9c:  98 10 20 08  mov  8, %o4
a0083da0:  d6 2f bf ea  stb  %o3, [ %fp + -22 ]
a0083da4:  d4 2f bf ec  stb  %o2, [ %fp + -20 ]
a0083da8:  d2 2f bf ef  stb  %o1, [ %fp + -17 ]
a0083dac:  a0 10 3f ff  mov  -1, %l0
a0083db0:  11 00 03 fb  sethi  %hi(0xfec00), %o0
a0083db4:  da 2f bf ed  stb  %o5, [ %fp + -19 ]
a0083db8:  d2 0e 20 01  ldub  [ %i0 + 1 ], %o1
a0083dbc:  d8 2f bf e8  stb  %o4, [ %fp + -24 ]
a0083dc0:  c0 2f bf e9  clrb  [ %fp + -23 ]
a0083dc4:  c0 2f bf eb  clrb  [ %fp + -21 ]
a0083dc8:  c0 2f bf ee  clrb  [ %fp + -18 ]
a0083dcc:  e0 2f bf f0  stb  %l0, [ %fp + -16 ]
a0083dd0:  90 12 23 18  or  %o0, 0x318, %o0
a0083dd4:  d4 0e 20 02  ldub  [ %i0 + 2 ], %o2
a0083dd8:  40 01 6c e6  call  0xa00df170
a0083ddc:  d6 0e 20 03  ldub  [ %i0 + 3 ], %o3
a0083de0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0083de4:  da 08 62 af  ldub  [ %g1 + 0x2af ], %o5	! 0xa802d2af
a0083de8:  80 a3 60 00  cmp  %o5, 0
a0083dec:  12 80 00 7f  bne  0xa0083fe8
a0083df0:  92 10 20 ff  mov  0xff, %o1
a0083df4:  92 10 00 18  mov  %i0, %o1
a0083df8:  96 10 20 00  clr  %o3
a0083dfc:  90 07 bf f8  add  %fp, -8, %o0
a0083e00:  10 80 00 06  b  0xa0083e18
a0083e04:  d4 0e 20 01  ldub  [ %i0 + 1 ], %o2
a0083e08:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0083e0c:  80 a3 60 02  cmp  %o5, 2
a0083e10:  18 80 00 1a  bgu  0xa0083e78
a0083e14:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0083e18:  98 03 40 0d  add  %o5, %o5, %o4
a0083e1c:  82 03 00 0d  add  %o4, %o5, %g1
a0083e20:  98 00 40 08  add  %g1, %o0, %o4
a0083e24:  f0 0b 3f f0  ldub  [ %o4 + -16 ], %i0
a0083e28:  80 a6 00 0a  cmp  %i0, %o2
a0083e2c:  32 bf ff f7  bne,a   0xa0083e08
a0083e30:  96 02 e0 01  inc  %o3
a0083e34:  da 0b 3f f1  ldub  [ %o4 + -15 ], %o5
a0083e38:  de 0a 60 02  ldub  [ %o1 + 2 ], %o7
a0083e3c:  80 a3 40 0f  cmp  %o5, %o7
a0083e40:  32 bf ff f2  bne,a   0xa0083e08
a0083e44:  96 02 e0 01  inc  %o3
a0083e48:  c2 0b 3f f2  ldub  [ %o4 + -14 ], %g1
a0083e4c:  f0 0a 60 03  ldub  [ %o1 + 3 ], %i0
a0083e50:  80 a0 40 18  cmp  %g1, %i0
a0083e54:  32 bf ff ed  bne,a   0xa0083e08
a0083e58:  96 02 e0 01  inc  %o3
a0083e5c:  a0 10 00 0b  mov  %o3, %l0
a0083e60:  96 02 e0 01  inc  %o3
a0083e64:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0083e68:  80 a3 60 02  cmp  %o5, 2
a0083e6c:  08 bf ff ec  bleu  0xa0083e1c
a0083e70:  98 03 40 0d  add  %o5, %o5, %o4
a0083e74:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0083e78:  80 a6 20 00  cmp  %i0, 0
a0083e7c:  12 80 00 12  bne  0xa0083ec4
a0083e80:  80 a6 20 ff  cmp  %i0, 0xff
a0083e84:  13 2a 00 90  sethi  %hi(0xa8024000), %o1
a0083e88:  98 12 60 18  or  %o1, 0x18, %o4	! 0xa8024018
a0083e8c:  e0 0b 20 01  ldub  [ %o4 + 1 ], %l0
a0083e90:  80 a4 20 50  cmp  %l0, 0x50
a0083e94:  22 80 00 48  be,a   0xa0083fb4
a0083e98:  d4 0b 20 02  ldub  [ %o4 + 2 ], %o2
a0083e9c:  82 10 20 00  clr  %g1
a0083ea0:  80 a0 60 00  cmp  %g1, 0
a0083ea4:  02 80 00 0a  be  0xa0083ecc
a0083ea8:  b0 10 20 00  clr  %i0
a0083eac:  11 00 03 fb  sethi  %hi(0xfec00), %o0
a0083eb0:  92 10 00 18  mov  %i0, %o1
a0083eb4:  40 01 6c af  call  0xa00df170
a0083eb8:  90 12 23 28  or  %o0, 0x328, %o0
a0083ebc:  10 80 00 4b  b  0xa0083fe8
a0083ec0:  92 10 00 18  mov  %i0, %o1
a0083ec4:  32 bf ff fb  bne,a   0xa0083eb0
a0083ec8:  11 00 03 fb  sethi  %hi(0xfec00), %o0
a0083ecc:  82 10 20 50  mov  0x50, %g1
a0083ed0:  19 2a 00 90  sethi  %hi(0xa8024000), %o4
a0083ed4:  b0 10 20 6c  mov  0x6c, %i0
a0083ed8:  9a 10 20 61  mov  0x61, %o5
a0083edc:  c2 2f bf d8  stb  %g1, [ %fp + -40 ]
a0083ee0:  9e 13 20 18  or  %o4, 0x18, %o7
a0083ee4:  96 10 20 79  mov  0x79, %o3
a0083ee8:  94 10 20 4e  mov  0x4e, %o2
a0083eec:  92 10 20 69  mov  0x69, %o1
a0083ef0:  82 10 20 74  mov  0x74, %g1
a0083ef4:  f0 2f bf d9  stb  %i0, [ %fp + -39 ]
a0083ef8:  da 2f bf da  stb  %o5, [ %fp + -38 ]
a0083efc:  98 10 20 58  mov  0x58, %o4
a0083f00:  d6 2f bf db  stb  %o3, [ %fp + -37 ]
a0083f04:  d4 2f bf dc  stb  %o2, [ %fp + -36 ]
a0083f08:  d2 2f bf dd  stb  %o1, [ %fp + -35 ]
a0083f0c:  a0 10 20 6e  mov  0x6e, %l0
a0083f10:  c2 2f bf df  stb  %g1, [ %fp + -33 ]
a0083f14:  b0 10 20 42  mov  0x42, %i0
a0083f18:  9a 10 20 4f  mov  0x4f, %o5
a0083f1c:  e0 2f bf de  stb  %l0, [ %fp + -34 ]
a0083f20:  f0 2f bf e1  stb  %i0, [ %fp + -31 ]
a0083f24:  da 2f bf e2  stb  %o5, [ %fp + -30 ]
a0083f28:  d8 2f bf e3  stb  %o4, [ %fp + -29 ]
a0083f2c:  d8 2f bf e0  stb  %o4, [ %fp + -32 ]
a0083f30:  92 10 3f ff  mov  -1, %o1
a0083f34:  96 10 20 00  clr  %o3
a0083f38:  82 10 20 00  clr  %g1
a0083f3c:  10 80 00 07  b  0xa0083f58
a0083f40:  d4 0b e0 01  ldub  [ %o7 + 1 ], %o2
a0083f44:  96 02 e0 01  inc  %o3
a0083f48:  82 0a e0 ff  and  %o3, 0xff, %g1
a0083f4c:  80 a0 60 02  cmp  %g1, 2
a0083f50:  18 bf ff d7  bgu  0xa0083eac
a0083f54:  b0 0a 60 ff  and  %o1, 0xff, %i0
a0083f58:  9b 28 60 02  sll  %g1, 2, %o5
a0083f5c:  98 03 40 08  add  %o5, %o0, %o4
a0083f60:  e0 0b 3f e0  ldub  [ %o4 + -32 ], %l0
a0083f64:  80 a4 00 0a  cmp  %l0, %o2
a0083f68:  32 bf ff f8  bne,a   0xa0083f48
a0083f6c:  96 02 e0 01  inc  %o3
a0083f70:  c2 0b 3f e1  ldub  [ %o4 + -31 ], %g1
a0083f74:  f0 0b e0 02  ldub  [ %o7 + 2 ], %i0
a0083f78:  80 a0 40 18  cmp  %g1, %i0
a0083f7c:  32 bf ff f3  bne,a   0xa0083f48
a0083f80:  96 02 e0 01  inc  %o3
a0083f84:  da 0b 3f e2  ldub  [ %o4 + -30 ], %o5
a0083f88:  e0 0b e0 03  ldub  [ %o7 + 3 ], %l0
a0083f8c:  80 a3 40 10  cmp  %o5, %l0
a0083f90:  32 bf ff ee  bne,a   0xa0083f48
a0083f94:  96 02 e0 01  inc  %o3
a0083f98:  f0 0b 3f e3  ldub  [ %o4 + -29 ], %i0
a0083f9c:  d8 0b e0 04  ldub  [ %o7 + 4 ], %o4
a0083fa0:  80 a6 00 0c  cmp  %i0, %o4
a0083fa4:  22 bf ff e8  be,a   0xa0083f44
a0083fa8:  92 10 00 0b  mov  %o3, %o1
a0083fac:  10 bf ff e7  b  0xa0083f48
a0083fb0:  96 02 e0 01  inc  %o3
a0083fb4:  80 a2 a0 6c  cmp  %o2, 0x6c
a0083fb8:  12 bf ff ba  bne  0xa0083ea0
a0083fbc:  82 10 20 00  clr  %g1
a0083fc0:  d6 0b 20 03  ldub  [ %o4 + 3 ], %o3
a0083fc4:  80 a2 e0 61  cmp  %o3, 0x61
a0083fc8:  12 bf ff b7  bne  0xa0083ea4
a0083fcc:  80 a0 60 00  cmp  %g1, 0
a0083fd0:  de 0b 20 04  ldub  [ %o4 + 4 ], %o7
a0083fd4:  80 a3 e0 79  cmp  %o7, 0x79
a0083fd8:  02 bf ff b2  be  0xa0083ea0
a0083fdc:  82 10 20 01  mov  1, %g1
a0083fe0:  10 bf ff b0  b  0xa0083ea0
a0083fe4:  82 10 20 00  clr  %g1
a0083fe8:  81 c7 e0 08  ret
a0083fec:  91 e8 00 09  restore  %g0, %o1, %o0
