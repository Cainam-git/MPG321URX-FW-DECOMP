# leon2m FUN_a0123cf0 0xa0123cf0-0xa0124168 (1144 bytes)
a0123cf0:  9d e3 bf 88  save  %sp, -120, %sp
a0123cf4:  80 a6 20 00  cmp  %i0, 0
a0123cf8:  02 80 00 07  be  0xa0123d14
a0123cfc:  2b 2a 00 b6  sethi  %hi(0xa802d800), %l5
a0123d00:  80 a6 20 05  cmp  %i0, 5
a0123d04:  12 80 01 17  bne  0xa0124160
a0123d08:  23 33 c0 46  sethi  %hi(0xcf011800), %l1
a0123d0c:  10 80 00 16  b  0xa0123d64
a0123d10:  aa 14 62 84  or  %l1, 0x284, %l5	! 0xcf011a84
a0123d14:  e6 0d 60 7e  ldub  [ %l5 + 0x7e ], %l3
a0123d18:  29 33 c0 45  sethi  %hi(0xcf011400), %l4
a0123d1c:  25 00 00 3c  sethi  %hi(0xf000), %l2
a0123d20:  96 15 22 58  or  %l4, 0x258, %o3
a0123d24:  a0 04 c0 13  add  %l3, %l3, %l0
a0123d28:  a2 14 a1 90  or  %l2, 0x190, %l1
a0123d2c:  de 02 c0 00  ld  [ %o3 ], %o7
a0123d30:  94 04 00 11  add  %l0, %l1, %o2
a0123d34:  92 0b ff 7f  and  %o7, -129, %o1
a0123d38:  91 2a a0 02  sll  %o2, 2, %o0
a0123d3c:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a0123d40:  d2 22 c0 00  st  %o1, [ %o3 ]
a0123d44:  98 12 00 01  or  %o0, %g1, %o4
a0123d48:  da 03 00 00  ld  [ %o4 ], %o5
a0123d4c:  80 a3 60 97  cmp  %o5, 0x97
a0123d50:  12 80 01 04  bne  0xa0124160
a0123d54:  01 00 00 00  nop
a0123d58:  67 fd ac f0  call  0x4008f118
a0123d5c:  01 00 00 00  nop
a0123d60:  30 80 01 00  b,a   0xa0124160
a0123d64:  ec 05 40 00  ld  [ %l5 ], %l6
a0123d68:  ec 2f bf e8  stb  %l6, [ %fp + -24 ]
a0123d6c:  ac 14 62 88  or  %l1, 0x288, %l6
a0123d70:  e8 05 80 00  ld  [ %l6 ], %l4
a0123d74:  e8 2f bf e9  stb  %l4, [ %fp + -23 ]
a0123d78:  a8 14 62 8c  or  %l1, 0x28c, %l4
a0123d7c:  f8 05 00 00  ld  [ %l4 ], %i4
a0123d80:  f8 2f bf ea  stb  %i4, [ %fp + -22 ]
a0123d84:  15 33 c0 4d  sethi  %hi(0xcf013400), %o2
a0123d88:  b8 12 a0 40  or  %o2, 0x40, %i4	! 0xcf013440
a0123d8c:  f6 07 00 00  ld  [ %i4 ], %i3
a0123d90:  f6 2f bf eb  stb  %i3, [ %fp + -21 ]
a0123d94:  b6 12 a0 44  or  %o2, 0x44, %i3
a0123d98:  ee 06 c0 00  ld  [ %i3 ], %l7
a0123d9c:  ee 2f bf ec  stb  %l7, [ %fp + -20 ]
a0123da0:  13 33 c0 47  sethi  %hi(0xcf011c00), %o1
a0123da4:  ae 12 61 8c  or  %o1, 0x18c, %l7	! 0xcf011d8c
a0123da8:  d6 05 c0 00  ld  [ %l7 ], %o3
a0123dac:  d6 2f bf ed  stb  %o3, [ %fp + -19 ]
a0123db0:  fa 04 40 00  ld  [ %l1 ], %i5
a0123db4:  fa 2f bf ee  stb  %i5, [ %fp + -18 ]
a0123db8:  ba 14 62 00  or  %l1, 0x200, %i5
a0123dbc:  f4 07 40 00  ld  [ %i5 ], %i2
a0123dc0:  27 33 c0 4b  sethi  %hi(0xcf012c00), %l3
a0123dc4:  f4 2f bf ef  stb  %i2, [ %fp + -17 ]
a0123dc8:  a6 14 e2 00  or  %l3, 0x200, %l3
a0123dcc:  f0 04 c0 00  ld  [ %l3 ], %i0
a0123dd0:  f0 2f bf f0  stb  %i0, [ %fp + -16 ]
a0123dd4:  b0 14 63 f8  or  %l1, 0x3f8, %i0
a0123dd8:  d0 06 00 00  ld  [ %i0 ], %o0
a0123ddc:  21 33 c0 45  sethi  %hi(0xcf011400), %l0
a0123de0:  d0 2f bf f1  stb  %o0, [ %fp + -15 ]
a0123de4:  a0 14 22 d4  or  %l0, 0x2d4, %l0
a0123de8:  e4 04 00 00  ld  [ %l0 ], %l2
a0123dec:  e4 2f bf f2  stb  %l2, [ %fp + -14 ]
a0123df0:  a4 14 62 80  or  %l1, 0x280, %l2
a0123df4:  f2 04 80 00  ld  [ %l2 ], %i1
a0123df8:  f2 2f bf f3  stb  %i1, [ %fp + -13 ]
a0123dfc:  92 10 20 86  mov  0x86, %o1
a0123e00:  7f ff 39 15  call  0xa00f2254
a0123e04:  90 10 20 00  clr  %o0
a0123e08:  33 2a 00 b6  sethi  %hi(0xa802d800), %i1
a0123e0c:  da 0e 60 7e  ldub  [ %i1 + 0x7e ], %o5	! 0xa802d87e
a0123e10:  03 00 00 3c  sethi  %hi(0xf000), %g1
a0123e14:  9e 03 40 0d  add  %o5, %o5, %o7
a0123e18:  98 10 61 91  or  %g1, 0x191, %o4
a0123e1c:  94 03 c0 0c  add  %o7, %o4, %o2
a0123e20:  97 2a a0 02  sll  %o2, 2, %o3
a0123e24:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a0123e28:  b4 12 c0 09  or  %o3, %o1, %i2
a0123e2c:  d0 2f bf f4  stb  %o0, [ %fp + -12 ]
a0123e30:  c0 26 80 00  clr  [ %i2 ]
a0123e34:  7f ff 9a 8c  call  0xa010a864
a0123e38:  01 00 00 00  nop
a0123e3c:  c2 04 00 00  ld  [ %l0 ], %g1
a0123e40:  b4 10 00 08  mov  %o0, %i2
a0123e44:  90 08 7f fe  and  %g1, -2, %o0
a0123e48:  d0 24 00 00  st  %o0, [ %l0 ]
a0123e4c:  d8 04 80 00  ld  [ %l2 ], %o4
a0123e50:  9a 0b 3f fe  and  %o4, -2, %o5
a0123e54:  da 24 80 00  st  %o5, [ %l2 ]
a0123e58:  90 10 20 00  clr  %o0
a0123e5c:  92 10 20 86  mov  0x86, %o1
a0123e60:  7f ff 39 0e  call  0xa00f2298
a0123e64:  94 10 20 00  clr  %o2
a0123e68:  c0 25 40 00  clr  [ %l5 ]
a0123e6c:  c0 25 80 00  clr  [ %l6 ]
a0123e70:  c0 25 00 00  clr  [ %l4 ]
a0123e74:  c0 24 c0 00  clr  [ %l3 ]
a0123e78:  ec 05 c0 00  ld  [ %l7 ], %l6
a0123e7c:  80 8d a0 03  btst  3, %l6
a0123e80:  12 80 00 af  bne  0xa012413c
a0123e84:  a4 10 00 11  mov  %l1, %l2
a0123e88:  de 07 00 00  ld  [ %i4 ], %o7
a0123e8c:  80 8b e0 01  btst  1, %o7
a0123e90:  aa 10 00 18  mov  %i0, %l5
a0123e94:  02 80 00 97  be  0xa01240f0
a0123e98:  a8 10 00 1d  mov  %i5, %l4
a0123e9c:  a2 10 20 01  mov  1, %l1
a0123ea0:  e2 24 80 00  st  %l1, [ %l2 ]
a0123ea4:  e2 25 00 00  st  %l1, [ %l4 ]
a0123ea8:  e2 25 40 00  st  %l1, [ %l5 ]
a0123eac:  a0 14 a0 08  or  %l2, 8, %l0
a0123eb0:  b0 10 20 ff  mov  0xff, %i0
a0123eb4:  90 10 20 64  mov  0x64, %o0
a0123eb8:  f0 24 00 00  st  %i0, [ %l0 ]
a0123ebc:  67 fd a4 b9  call  0x4008d1a0
a0123ec0:  01 00 00 00  nop
a0123ec4:  d0 04 00 00  ld  [ %l0 ], %o0
a0123ec8:  80 8a 20 03  btst  3, %o0
a0123ecc:  12 80 00 93  bne  0xa0124118
a0123ed0:  01 00 00 00  nop
a0123ed4:  80 8e a0 ff  btst  0xff, %i2
a0123ed8:  12 80 00 06  bne  0xa0123ef0
a0123edc:  23 33 c0 f1  sethi  %hi(0xcf03c400), %l1
a0123ee0:  c0 25 00 00  clr  [ %l4 ]
a0123ee4:  c0 24 80 00  clr  [ %l2 ]
a0123ee8:  c0 25 40 00  clr  [ %l5 ]
a0123eec:  23 33 c0 f1  sethi  %hi(0xcf03c400), %l1
a0123ef0:  a6 14 a0 8c  or  %l2, 0x8c, %l3
a0123ef4:  d8 04 c0 00  ld  [ %l3 ], %o4
a0123ef8:  92 14 62 68  or  %l1, 0x268, %o1
a0123efc:  d8 22 40 00  st  %o4, [ %o1 ]
a0123f00:  ba 14 a0 88  or  %l2, 0x88, %i5
a0123f04:  f0 07 40 00  ld  [ %i5 ], %i0
a0123f08:  a0 14 62 6c  or  %l1, 0x26c, %l0
a0123f0c:  f0 24 00 00  st  %i0, [ %l0 ]
a0123f10:  82 14 a0 84  or  %l2, 0x84, %g1
a0123f14:  d0 00 40 00  ld  [ %g1 ], %o0
a0123f18:  9a 14 62 70  or  %l1, 0x270, %o5
a0123f1c:  d0 23 40 00  st  %o0, [ %o5 ]
a0123f20:  9e 14 a0 80  or  %l2, 0x80, %o7
a0123f24:  d4 03 c0 00  ld  [ %o7 ], %o2
a0123f28:  aa 14 62 74  or  %l1, 0x274, %l5
a0123f2c:  d4 25 40 00  st  %o2, [ %l5 ]
a0123f30:  92 10 20 71  mov  0x71, %o1
a0123f34:  7f ff 39 b1  call  0xa00f25f8
a0123f38:  90 10 20 00  clr  %o0
a0123f3c:  ad 2a 20 10  sll  %o0, 0x10, %l6
a0123f40:  92 10 20 75  mov  0x75, %o1
a0123f44:  7f ff 39 ad  call  0xa00f25f8
a0123f48:  90 10 20 00  clr  %o0
a0123f4c:  a9 2a 20 10  sll  %o0, 0x10, %l4
a0123f50:  b7 35 a0 10  srl  %l6, 0x10, %i3
a0123f54:  b9 35 20 10  srl  %l4, 0x10, %i4
a0123f58:  ae 5e c0 1c  smul  %i3, %i4, %l7
a0123f5c:  96 05 c0 17  add  %l7, %l7, %o3
a0123f60:  35 33 33 33  sethi  %hi(0xcccccc00), %i2
a0123f64:  a4 02 c0 17  add  %o3, %l7, %l2
a0123f68:  a6 16 a0 cd  or  %i2, 0xcd, %l3
a0123f6c:  80 54 80 13  umul  %l2, %l3, %g0
a0123f70:  99 40 00 00  rd  %y, %o4
a0123f74:  93 33 20 0e  srl  %o4, 0xe, %o1
a0123f78:  f0 0e 60 7e  ldub  [ %i1 + 0x7e ], %i0
a0123f7c:  9e 02 60 01  add  %o1, 1, %o7
a0123f80:  3b 00 00 3c  sethi  %hi(0xf000), %i5
a0123f84:  92 17 61 91  or  %i5, 0x191, %o1	! 0xf191
a0123f88:  90 06 00 18  add  %i0, %i0, %o0
a0123f8c:  a1 33 e0 08  srl  %o7, 8, %l0
a0123f90:  94 02 00 09  add  %o0, %o1, %o2
a0123f94:  82 0c 20 ff  and  %l0, 0xff, %g1
a0123f98:  a9 2a a0 02  sll  %o2, 2, %l4
a0123f9c:  9a 14 62 78  or  %l1, 0x278, %o5
a0123fa0:  c2 23 40 00  st  %g1, [ %o5 ]
a0123fa4:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a0123fa8:  ac 14 62 7c  or  %l1, 0x27c, %l6
a0123fac:  aa 0b e0 ff  and  %o7, 0xff, %l5
a0123fb0:  ea 25 80 00  st  %l5, [ %l6 ]
a0123fb4:  b6 15 00 0a  or  %l4, %o2, %i3
a0123fb8:  b8 10 20 13  mov  0x13, %i4
a0123fbc:  f8 26 c0 00  st  %i4, [ %i3 ]
a0123fc0:  21 2a 00 b6  sethi  %hi(0xa802d800), %l0
a0123fc4:  ee 0c 20 7e  ldub  [ %l0 + 0x7e ], %l7	! 0xa802d87e
a0123fc8:  96 05 c0 17  add  %l7, %l7, %o3
a0123fcc:  b4 02 c0 09  add  %o3, %o1, %i2
a0123fd0:  a7 2e a0 02  sll  %i2, 2, %l3
a0123fd4:  a4 14 c0 0a  or  %l3, %o2, %l2
a0123fd8:  f2 04 80 00  ld  [ %l2 ], %i1
a0123fdc:  80 a6 60 ee  cmp  %i1, 0xee
a0123fe0:  02 80 00 0e  be  0xa0124018
a0123fe4:  a4 10 00 09  mov  %o1, %l2
a0123fe8:  a2 10 00 0a  mov  %o2, %l1
a0123fec:  67 fd a3 bb  call  0x4008ced8
a0123ff0:  01 00 00 00  nop
a0123ff4:  f8 0c 20 7e  ldub  [ %l0 + 0x7e ], %i4
a0123ff8:  b6 07 00 1c  add  %i4, %i4, %i3
a0123ffc:  ae 06 c0 12  add  %i3, %l2, %l7
a0124000:  97 2d e0 02  sll  %l7, 2, %o3
a0124004:  b4 12 c0 11  or  %o3, %l1, %i2
a0124008:  f2 06 80 00  ld  [ %i2 ], %i1
a012400c:  80 a6 60 ee  cmp  %i1, 0xee
a0124010:  12 bf ff f7  bne  0xa0123fec
a0124014:  01 00 00 00  nop
a0124018:  d2 0c 20 7e  ldub  [ %l0 + 0x7e ], %o1
a012401c:  3b 00 00 3c  sethi  %hi(0xf000), %i5
a0124020:  b0 02 40 09  add  %o1, %o1, %i0
a0124024:  82 17 61 91  or  %i5, 0x191, %g1
a0124028:  a0 06 00 01  add  %i0, %g1, %l0
a012402c:  9b 2c 20 02  sll  %l0, 2, %o5
a0124030:  11 33 c0 00  sethi  %hi(0xcf000000), %o0
a0124034:  a8 13 40 08  or  %o5, %o0, %l4
a0124038:  c0 25 00 00  clr  [ %l4 ]
a012403c:  29 33 c0 46  sethi  %hi(0xcf011800), %l4
a0124040:  de 0f bf e8  ldub  [ %fp + -24 ], %o7
a0124044:  94 15 22 84  or  %l4, 0x284, %o2
a0124048:  de 22 80 00  st  %o7, [ %o2 ]
a012404c:  ea 0f bf e9  ldub  [ %fp + -23 ], %l5
a0124050:  ac 15 22 88  or  %l4, 0x288, %l6
a0124054:  ea 25 80 00  st  %l5, [ %l6 ]
a0124058:  e4 0f bf ea  ldub  [ %fp + -22 ], %l2
a012405c:  a2 15 22 8c  or  %l4, 0x28c, %l1
a0124060:  e4 24 40 00  st  %l2, [ %l1 ]
a0124064:  2f 33 c0 4d  sethi  %hi(0xcf013400), %l7
a0124068:  f8 0f bf eb  ldub  [ %fp + -21 ], %i4
a012406c:  b6 15 e0 40  or  %l7, 0x40, %i3
a0124070:  f8 26 c0 00  st  %i4, [ %i3 ]
a0124074:  d6 0f bf ec  ldub  [ %fp + -20 ], %o3
a0124078:  b4 15 e0 44  or  %l7, 0x44, %i2
a012407c:  d6 26 80 00  st  %o3, [ %i2 ]
a0124080:  33 33 c0 47  sethi  %hi(0xcf011c00), %i1
a0124084:  d8 0f bf ed  ldub  [ %fp + -19 ], %o4
a0124088:  a6 16 61 8c  or  %i1, 0x18c, %l3
a012408c:  d8 24 c0 00  st  %o4, [ %l3 ]
a0124090:  d2 0f bf ee  ldub  [ %fp + -18 ], %o1
a0124094:  d2 25 00 00  st  %o1, [ %l4 ]
a0124098:  fa 0f bf ef  ldub  [ %fp + -17 ], %i5
a012409c:  b0 15 22 00  or  %l4, 0x200, %i0
a01240a0:  fa 26 00 00  st  %i5, [ %i0 ]
a01240a4:  03 33 c0 4b  sethi  %hi(0xcf012c00), %g1
a01240a8:  e0 0f bf f0  ldub  [ %fp + -16 ], %l0
a01240ac:  90 10 62 00  or  %g1, 0x200, %o0
a01240b0:  e0 22 00 00  st  %l0, [ %o0 ]
a01240b4:  da 0f bf f1  ldub  [ %fp + -15 ], %o5
a01240b8:  9e 15 23 f8  or  %l4, 0x3f8, %o7
a01240bc:  da 23 c0 00  st  %o5, [ %o7 ]
a01240c0:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a01240c4:  ea 0f bf f2  ldub  [ %fp + -14 ], %l5
a01240c8:  ac 12 a2 d4  or  %o2, 0x2d4, %l6
a01240cc:  ea 25 80 00  st  %l5, [ %l6 ]
a01240d0:  a2 15 22 80  or  %l4, 0x280, %l1
a01240d4:  e4 0f bf f3  ldub  [ %fp + -13 ], %l2
a01240d8:  e4 24 40 00  st  %l2, [ %l1 ]
a01240dc:  90 10 20 00  clr  %o0
a01240e0:  92 10 20 86  mov  0x86, %o1
a01240e4:  7f ff 38 6d  call  0xa00f2298
a01240e8:  d4 0f bf f4  ldub  [ %fp + -12 ], %o2
a01240ec:  30 80 00 1d  b,a   0xa0124160
a01240f0:  c0 26 00 00  clr  [ %i0 ]
a01240f4:  c0 27 40 00  clr  [ %i5 ]
a01240f8:  c0 24 80 00  clr  [ %l2 ]
a01240fc:  9a 10 20 01  mov  1, %o5
a0124100:  da 27 00 00  st  %o5, [ %i4 ]
a0124104:  c2 06 c0 00  ld  [ %i3 ], %g1
a0124108:  98 08 7f fb  and  %g1, -5, %o4
a012410c:  d8 26 c0 00  st  %o4, [ %i3 ]
a0124110:  10 bf ff 64  b  0xa0123ea0
a0124114:  a2 10 20 01  mov  1, %l1
a0124118:  c0 25 00 00  clr  [ %l4 ]
a012411c:  67 fd a8 62  call  0x4008e2a4
a0124120:  01 00 00 00  nop
a0124124:  c0 24 80 00  clr  [ %l2 ]
a0124128:  67 fd a8 5f  call  0x4008e2a4
a012412c:  01 00 00 00  nop
a0124130:  e2 25 00 00  st  %l1, [ %l4 ]
a0124134:  10 bf ff 69  b  0xa0123ed8
a0124138:  80 8e a0 ff  btst  0xff, %i2
a012413c:  c0 26 00 00  clr  [ %i0 ]
a0124140:  c0 27 40 00  clr  [ %i5 ]
a0124144:  c0 24 40 00  clr  [ %l1 ]
a0124148:  67 fd a4 16  call  0x4008d1a0
a012414c:  90 10 20 32  mov  0x32, %o0
a0124150:  ea 05 c0 00  ld  [ %l7 ], %l5
a0124154:  a2 0d 7f fc  and  %l5, -4, %l1
a0124158:  e2 25 c0 00  st  %l1, [ %l7 ]
a012415c:  30 bf ff 4b  b,a   0xa0123e88
a0124160:  81 c7 e0 08  ret
a0124164:  81 e8 00 00  restore
