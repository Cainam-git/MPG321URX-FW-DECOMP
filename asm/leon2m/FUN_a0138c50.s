# leon2m FUN_a0138c50 0xa0138c50-0xa0138e28 (472 bytes)
a0138c50:  9d e3 bf 80  save  %sp, -128, %sp
a0138c54:  e6 16 60 08  lduh  [ %i1 + 8 ], %l3
a0138c58:  e8 16 60 0a  lduh  [ %i1 + 0xa ], %l4
a0138c5c:  ea 16 60 0c  lduh  [ %i1 + 0xc ], %l5
a0138c60:  ec 16 60 0e  lduh  [ %i1 + 0xe ], %l6
a0138c64:  ee 16 60 10  lduh  [ %i1 + 0x10 ], %l7
a0138c68:  fa 16 60 12  lduh  [ %i1 + 0x12 ], %i5
a0138c6c:  f8 16 60 14  lduh  [ %i1 + 0x14 ], %i4
a0138c70:  98 10 20 00  clr  %o4
a0138c74:  9a 10 20 00  clr  %o5
a0138c78:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a0138c7c:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0138c80:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a0138c84:  d6 16 60 16  lduh  [ %i1 + 0x16 ], %o3
a0138c88:  e4 0e 60 05  ldub  [ %i1 + 5 ], %l2
a0138c8c:  c2 0e 60 07  ldub  [ %i1 + 7 ], %g1
a0138c90:  da 0e 60 04  ldub  [ %i1 + 4 ], %o5
a0138c94:  d6 2f bf f2  stb  %o3, [ %fp + -14 ]
a0138c98:  99 34 e0 08  srl  %l3, 8, %o4
a0138c9c:  95 35 20 08  srl  %l4, 8, %o2
a0138ca0:  93 35 60 08  srl  %l5, 8, %o1
a0138ca4:  91 35 a0 08  srl  %l6, 8, %o0
a0138ca8:  9f 35 e0 08  srl  %l7, 8, %o7
a0138cac:  a1 37 60 08  srl  %i5, 8, %l0
a0138cb0:  a3 37 20 08  srl  %i4, 8, %l1
a0138cb4:  f0 2f bf e0  stb  %i0, [ %fp + -32 ]
a0138cb8:  c2 2f bf e2  stb  %g1, [ %fp + -30 ]
a0138cbc:  da 2f bf e3  stb  %o5, [ %fp + -29 ]
a0138cc0:  d8 2f bf e5  stb  %o4, [ %fp + -27 ]
a0138cc4:  d4 2f bf e7  stb  %o2, [ %fp + -25 ]
a0138cc8:  d2 2f bf e9  stb  %o1, [ %fp + -23 ]
a0138ccc:  d0 2f bf eb  stb  %o0, [ %fp + -21 ]
a0138cd0:  de 2f bf ed  stb  %o7, [ %fp + -19 ]
a0138cd4:  e0 2f bf ef  stb  %l0, [ %fp + -17 ]
a0138cd8:  e2 2f bf f1  stb  %l1, [ %fp + -15 ]
a0138cdc:  e4 2f bf e1  stb  %l2, [ %fp + -31 ]
a0138ce0:  e6 2f bf e4  stb  %l3, [ %fp + -28 ]
a0138ce4:  e8 2f bf e6  stb  %l4, [ %fp + -26 ]
a0138ce8:  ea 2f bf e8  stb  %l5, [ %fp + -24 ]
a0138cec:  ec 2f bf ea  stb  %l6, [ %fp + -22 ]
a0138cf0:  ee 2f bf ec  stb  %l7, [ %fp + -20 ]
a0138cf4:  fa 2f bf ee  stb  %i5, [ %fp + -18 ]
a0138cf8:  f8 2f bf f0  stb  %i4, [ %fp + -16 ]
a0138cfc:  97 32 e0 08  srl  %o3, 8, %o3
a0138d00:  80 a4 a0 00  cmp  %l2, 0
a0138d04:  12 80 00 17  bne  0xa0138d60
a0138d08:  d6 2f bf f3  stb  %o3, [ %fp + -13 ]
a0138d0c:  21 33 c0 51  sethi  %hi(0xcf014400), %l0
a0138d10:  a2 14 23 40  or  %l0, 0x340, %l1	! 0xcf014740
a0138d14:  e6 04 40 00  ld  [ %l1 ], %l3
a0138d18:  a9 34 e0 06  srl  %l3, 6, %l4
a0138d1c:  25 33 c0 4a  sethi  %hi(0xcf012800), %l2
a0138d20:  ae 0d 20 03  and  %l4, 3, %l7
a0138d24:  ee 2f bf f4  stb  %l7, [ %fp + -12 ]
a0138d28:  aa 14 a0 94  or  %l2, 0x94, %l5
a0138d2c:  ec 05 40 00  ld  [ %l5 ], %l6
a0138d30:  ba 15 c0 16  or  %l7, %l6, %i5
a0138d34:  fa 2f bf f4  stb  %i5, [ %fp + -12 ]
a0138d38:  b8 14 a0 84  or  %l2, 0x84, %i4
a0138d3c:  d6 07 00 00  ld  [ %i4 ], %o3
a0138d40:  d6 2f bf f5  stb  %o3, [ %fp + -11 ]
a0138d44:  b2 14 a0 88  or  %l2, 0x88, %i1
a0138d48:  f0 06 40 00  ld  [ %i1 ], %i0
a0138d4c:  f0 2f bf f6  stb  %i0, [ %fp + -10 ]
a0138d50:  96 14 a0 8c  or  %l2, 0x8c, %o3
a0138d54:  da 02 c0 00  ld  [ %o3 ], %o5
a0138d58:  10 80 00 2c  b  0xa0138e08
a0138d5c:  da 2f bf f7  stb  %o5, [ %fp + -9 ]
a0138d60:  80 a4 a0 02  cmp  %l2, 2
a0138d64:  02 80 00 16  be  0xa0138dbc
a0138d68:  80 a4 a0 03  cmp  %l2, 3
a0138d6c:  12 80 00 28  bne  0xa0138e0c
a0138d70:  90 10 20 a5  mov  0xa5, %o0
a0138d74:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a0138d78:  94 13 23 40  or  %o4, 0x340, %o2	! 0xcf014740
a0138d7c:  d2 02 80 00  ld  [ %o2 ], %o1
a0138d80:  2f 33 c0 4a  sethi  %hi(0xcf012800), %l7
a0138d84:  a0 0a 60 03  and  %o1, 3, %l0
a0138d88:  e0 2f bf f4  stb  %l0, [ %fp + -12 ]
a0138d8c:  90 15 e1 54  or  %l7, 0x154, %o0
a0138d90:  de 02 00 00  ld  [ %o0 ], %o7
a0138d94:  a2 14 00 0f  or  %l0, %o7, %l1
a0138d98:  e2 2f bf f4  stb  %l1, [ %fp + -12 ]
a0138d9c:  a6 15 e1 44  or  %l7, 0x144, %l3
a0138da0:  e8 04 c0 00  ld  [ %l3 ], %l4
a0138da4:  e8 2f bf f5  stb  %l4, [ %fp + -11 ]
a0138da8:  aa 15 e1 48  or  %l7, 0x148, %l5
a0138dac:  ec 05 40 00  ld  [ %l5 ], %l6
a0138db0:  ec 2f bf f6  stb  %l6, [ %fp + -10 ]
a0138db4:  10 bf ff e8  b  0xa0138d54
a0138db8:  96 15 e1 4c  or  %l7, 0x14c, %o3
a0138dbc:  3b 33 c0 51  sethi  %hi(0xcf014400), %i5
a0138dc0:  b8 17 63 40  or  %i5, 0x340, %i4	! 0xcf014740
a0138dc4:  d6 07 00 00  ld  [ %i4 ], %o3
a0138dc8:  b3 32 e0 02  srl  %o3, 2, %i1
a0138dcc:  1f 33 c0 4a  sethi  %hi(0xcf012800), %o7
a0138dd0:  a4 0e 60 03  and  %i1, 3, %l2
a0138dd4:  e4 2f bf f4  stb  %l2, [ %fp + -12 ]
a0138dd8:  82 13 e1 14  or  %o7, 0x114, %g1
a0138ddc:  f0 00 40 00  ld  [ %g1 ], %i0
a0138de0:  9a 14 80 18  or  %l2, %i0, %o5
a0138de4:  da 2f bf f4  stb  %o5, [ %fp + -12 ]
a0138de8:  98 13 e1 04  or  %o7, 0x104, %o4
a0138dec:  d4 03 00 00  ld  [ %o4 ], %o2
a0138df0:  d4 2f bf f5  stb  %o2, [ %fp + -11 ]
a0138df4:  92 13 e1 08  or  %o7, 0x108, %o1
a0138df8:  d0 02 40 00  ld  [ %o1 ], %o0
a0138dfc:  d0 2f bf f6  stb  %o0, [ %fp + -10 ]
a0138e00:  10 bf ff d5  b  0xa0138d54
a0138e04:  96 13 e1 0c  or  %o7, 0x10c, %o3
a0138e08:  90 10 20 a5  mov  0xa5, %o0
a0138e0c:  92 10 20 18  mov  0x18, %o1
a0138e10:  94 07 bf e0  add  %fp, -32, %o2
a0138e14:  7f ff f8 b2  call  0xa01370dc
a0138e18:  96 10 20 00  clr  %o3
a0138e1c:  01 00 00 00  nop
a0138e20:  81 c7 e0 08  ret
a0138e24:  81 e8 00 00  restore
