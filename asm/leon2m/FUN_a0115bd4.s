# leon2m FUN_a0115bd4 0xa0115bd4-0xa01166d8 (2820 bytes)
a0115bd4:  9d e3 bf 98  save  %sp, -104, %sp
a0115bd8:  83 2e 60 10  sll  %i1, 0x10, %g1
a0115bdc:  83 30 60 10  srl  %g1, 0x10, %g1
a0115be0:  96 10 00 18  mov  %i0, %o3
a0115be4:  80 a0 60 01  cmp  %g1, 1
a0115be8:  92 10 00 18  mov  %i0, %o1
a0115bec:  94 10 00 19  mov  %i1, %o2
a0115bf0:  90 10 20 00  clr  %o0
a0115bf4:  a0 10 20 00  clr  %l0
a0115bf8:  98 10 20 00  clr  %o4
a0115bfc:  04 80 01 57  ble  0xa0116158
a0115c00:  9a 10 20 00  clr  %o5
a0115c04:  80 a0 60 03  cmp  %g1, 3
a0115c08:  24 80 00 02  ble,a   0xa0115c10
a0115c0c:  9a 10 20 c7  mov  0xc7, %o5
a0115c10:  b0 0a e0 ff  and  %o3, 0xff, %i0
a0115c14:  80 a6 20 01  cmp  %i0, 1
a0115c18:  22 80 01 55  be,a   0xa011616c
a0115c1c:  b0 0b 60 ff  and  %o5, 0xff, %i0
a0115c20:  80 a6 20 01  cmp  %i0, 1
a0115c24:  04 80 02 28  ble  0xa01164c4
a0115c28:  80 a6 20 02  cmp  %i0, 2
a0115c2c:  02 80 01 eb  be  0xa01163d8
a0115c30:  29 00 00 22  sethi  %hi(0x8800), %l4
a0115c34:  a3 2e 60 10  sll  %i1, 0x10, %l1
a0115c38:  83 34 60 10  srl  %l1, 0x10, %g1
a0115c3c:  80 a0 60 01  cmp  %g1, 1
a0115c40:  22 80 00 e0  be,a   0xa0115fc0
a0115c44:  b2 0b 20 ff  and  %o4, 0xff, %i1
a0115c48:  04 80 01 df  ble  0xa01163c4
a0115c4c:  80 a0 60 02  cmp  %g1, 2
a0115c50:  02 80 01 e0  be  0xa01163d0
a0115c54:  80 a0 60 03  cmp  %g1, 3
a0115c58:  02 80 00 da  be  0xa0115fc0
a0115c5c:  b2 0b 20 ff  and  %o4, 0xff, %i1
a0115c60:  b3 2a a0 10  sll  %o2, 0x10, %i1
a0115c64:  83 36 60 10  srl  %i1, 0x10, %g1
a0115c68:  a6 10 00 0c  mov  %o4, %l3
a0115c6c:  80 a0 60 01  cmp  %g1, 1
a0115c70:  98 10 20 00  clr  %o4
a0115c74:  04 80 00 db  ble  0xa0115fe0
a0115c78:  9a 10 20 00  clr  %o5
a0115c7c:  80 a0 60 03  cmp  %g1, 3
a0115c80:  14 80 00 da  bg  0xa0115fe8
a0115c84:  b0 0a 60 ff  and  %o1, 0xff, %i0
a0115c88:  80 a6 20 01  cmp  %i0, 1
a0115c8c:  12 80 00 db  bne  0xa0115ff8
a0115c90:  9a 10 20 c9  mov  0xc9, %o5
a0115c94:  9e 0b 60 ff  and  %o5, 0xff, %o7
a0115c98:  23 00 00 23  sethi  %hi(0x8c00), %l1
a0115c9c:  9a 03 c0 11  add  %o7, %l1, %o5
a0115ca0:  9b 2b 60 02  sll  %o5, 2, %o5
a0115ca4:  03 33 c0 8c  sethi  %hi(0xcf023000), %g1
a0115ca8:  a8 10 63 f8  or  %g1, 0x3f8, %l4	! 0xcf0233f8
a0115cac:  25 33 c0 00  sethi  %hi(0xcf000000), %l2
a0115cb0:  c0 25 00 00  clr  [ %l4 ]
a0115cb4:  94 13 40 12  or  %o5, %l2, %o2
a0115cb8:  d2 02 80 00  ld  [ %o2 ], %o1
a0115cbc:  83 36 60 10  srl  %i1, 0x10, %g1
a0115cc0:  80 a0 60 01  cmp  %g1, 1
a0115cc4:  12 80 00 d6  bne  0xa011601c
a0115cc8:  98 10 00 09  mov  %o1, %o4
a0115ccc:  1f 33 c0 4b  sethi  %hi(0xcf012c00), %o7
a0115cd0:  aa 0b 20 ff  and  %o4, 0xff, %l5
a0115cd4:  96 13 e2 00  or  %o7, 0x200, %o3
a0115cd8:  da 02 c0 00  ld  [ %o3 ], %o5
a0115cdc:  99 35 60 04  srl  %l5, 4, %o4
a0115ce0:  94 0b 20 ff  and  %o4, 0xff, %o2
a0115ce4:  96 0e a0 ff  and  %i2, 0xff, %o3
a0115ce8:  03 33 c0 4e  sethi  %hi(0xcf013800), %g1
a0115cec:  c0 20 40 00  clr  [ %g1 ]
a0115cf0:  a8 10 00 0d  mov  %o5, %l4
a0115cf4:  80 a2 e0 07  cmp  %o3, 7
a0115cf8:  12 80 00 da  bne  0xa0116060
a0115cfc:  aa 10 00 0a  mov  %o2, %l5
a0115d00:  21 33 c0 4b  sethi  %hi(0xcf012c00), %l0
a0115d04:  82 10 20 71  mov  0x71, %g1
a0115d08:  a2 14 22 40  or  %l0, 0x240, %l1
a0115d0c:  c2 24 40 00  st  %g1, [ %l1 ]
a0115d10:  40 00 0a 31  call  0xa01185d4
a0115d14:  b4 14 22 00  or  %l0, 0x200, %i2
a0115d18:  92 10 20 00  clr  %o1
a0115d1c:  40 00 0b 43  call  0xa0118a28
a0115d20:  90 10 20 00  clr  %o0
a0115d24:  a4 10 20 11  mov  0x11, %l2
a0115d28:  e4 26 80 00  st  %l2, [ %i2 ]
a0115d2c:  67 fd dd 1d  call  0x4008d1a0
a0115d30:  90 10 20 28  mov  0x28, %o0
a0115d34:  92 10 20 01  mov  1, %o1
a0115d38:  d2 26 80 00  st  %o1, [ %i2 ]
a0115d3c:  67 fd dd 19  call  0x4008d1a0
a0115d40:  90 10 20 28  mov  0x28, %o0
a0115d44:  9e 10 20 81  mov  0x81, %o7
a0115d48:  de 26 80 00  st  %o7, [ %i2 ]
a0115d4c:  67 fd dd 15  call  0x4008d1a0
a0115d50:  90 10 20 14  mov  0x14, %o0
a0115d54:  96 10 20 02  mov  2, %o3
a0115d58:  a2 14 23 2c  or  %l0, 0x32c, %l1
a0115d5c:  d6 24 40 00  st  %o3, [ %l1 ]
a0115d60:  67 fd dd 10  call  0x4008d1a0
a0115d64:  90 10 20 14  mov  0x14, %o0
a0115d68:  94 10 20 05  mov  5, %o2
a0115d6c:  d4 24 40 00  st  %o2, [ %l1 ]
a0115d70:  67 fd dd 0c  call  0x4008d1a0
a0115d74:  90 10 20 14  mov  0x14, %o0
a0115d78:  98 14 23 30  or  %l0, 0x330, %o4
a0115d7c:  d4 03 00 00  ld  [ %o4 ], %o2
a0115d80:  9a 14 23 34  or  %l0, 0x334, %o5
a0115d84:  d8 03 40 00  ld  [ %o5 ], %o4
a0115d88:  90 14 23 38  or  %l0, 0x338, %o0
a0115d8c:  de 02 00 00  ld  [ %o0 ], %o7
a0115d90:  82 14 23 3c  or  %l0, 0x33c, %g1
a0115d94:  d2 00 40 00  ld  [ %g1 ], %o1
a0115d98:  e4 04 40 00  ld  [ %l1 ], %l2
a0115d9c:  b4 10 00 09  mov  %o1, %i2
a0115da0:  80 8c a0 80  btst  0x80, %l2
a0115da4:  90 10 00 0a  mov  %o2, %o0
a0115da8:  92 10 00 0c  mov  %o4, %o1
a0115dac:  12 80 00 11  bne  0xa0115df0
a0115db0:  96 10 00 0f  mov  %o7, %o3
a0115db4:  a2 12 80 0c  or  %o2, %o4, %l1
a0115db8:  a4 0c 60 ff  and  %l1, 0xff, %l2
a0115dbc:  80 a0 00 12  cmp  %g0, %l2
a0115dc0:  94 0b e0 ff  and  %o7, 0xff, %o2
a0115dc4:  98 60 3f ff  subx  %g0, -1, %o4
a0115dc8:  9a 1a a0 10  xor  %o2, 0x10, %o5
a0115dcc:  80 a0 00 0d  cmp  %g0, %o5
a0115dd0:  a0 60 3f ff  subx  %g0, -1, %l0
a0115dd4:  80 8b 00 10  btst  %o4, %l0
a0115dd8:  02 80 00 07  be  0xa0115df4
a0115ddc:  98 10 20 30  mov  0x30, %o4
a0115de0:  96 0e a0 ff  and  %i2, 0xff, %o3
a0115de4:  80 a0 00 0b  cmp  %g0, %o3
a0115de8:  82 60 20 00  subx  %g0, 0, %g1
a0115dec:  96 0b c0 01  and  %o7, %g1, %o3
a0115df0:  98 10 20 30  mov  0x30, %o4
a0115df4:  1b 33 c0 4e  sethi  %hi(0xcf013800), %o5
a0115df8:  21 33 c0 4b  sethi  %hi(0xcf012c00), %l0
a0115dfc:  a4 02 00 09  add  %o0, %o1, %l2
a0115e00:  d8 23 40 00  st  %o4, [ %o5 ]
a0115e04:  92 04 80 0b  add  %l2, %o3, %o1
a0115e08:  9e 10 20 11  mov  0x11, %o7
a0115e0c:  a2 14 22 00  or  %l0, 0x200, %l1
a0115e10:  a4 02 40 1a  add  %o1, %i2, %l2
a0115e14:  de 24 40 00  st  %o7, [ %l1 ]
a0115e18:  67 fd dc e2  call  0x4008d1a0
a0115e1c:  90 10 20 28  mov  0x28, %o0
a0115e20:  90 10 20 01  mov  1, %o0
a0115e24:  d0 24 40 00  st  %o0, [ %l1 ]
a0115e28:  67 fd dc de  call  0x4008d1a0
a0115e2c:  90 10 20 28  mov  0x28, %o0
a0115e30:  96 10 20 81  mov  0x81, %o3
a0115e34:  d6 24 40 00  st  %o3, [ %l1 ]
a0115e38:  67 fd dc da  call  0x4008d1a0
a0115e3c:  90 10 20 14  mov  0x14, %o0
a0115e40:  a2 14 23 2c  or  %l0, 0x32c, %l1
a0115e44:  82 10 20 02  mov  2, %g1
a0115e48:  c2 24 40 00  st  %g1, [ %l1 ]
a0115e4c:  67 fd dc d5  call  0x4008d1a0
a0115e50:  90 10 20 14  mov  0x14, %o0
a0115e54:  94 10 20 05  mov  5, %o2
a0115e58:  d4 24 40 00  st  %o2, [ %l1 ]
a0115e5c:  67 fd dc d1  call  0x4008d1a0
a0115e60:  90 10 20 14  mov  0x14, %o0
a0115e64:  98 14 23 30  or  %l0, 0x330, %o4
a0115e68:  d4 03 00 00  ld  [ %o4 ], %o2
a0115e6c:  b4 14 23 34  or  %l0, 0x334, %i2
a0115e70:  d8 06 80 00  ld  [ %i2 ], %o4
a0115e74:  9a 14 23 38  or  %l0, 0x338, %o5
a0115e78:  f4 03 40 00  ld  [ %o5 ], %i2
a0115e7c:  92 14 23 3c  or  %l0, 0x33c, %o1
a0115e80:  d0 02 40 00  ld  [ %o1 ], %o0
a0115e84:  de 04 40 00  ld  [ %l1 ], %o7
a0115e88:  80 8b e0 80  btst  0x80, %o7
a0115e8c:  9e 10 00 08  mov  %o0, %o7
a0115e90:  90 10 00 0a  mov  %o2, %o0
a0115e94:  92 10 00 0c  mov  %o4, %o1
a0115e98:  12 80 00 11  bne  0xa0115edc
a0115e9c:  96 10 00 1a  mov  %i2, %o3
a0115ea0:  a0 12 80 0c  or  %o2, %o4, %l0
a0115ea4:  9a 0c 20 ff  and  %l0, 0xff, %o5
a0115ea8:  80 a0 00 0d  cmp  %g0, %o5
a0115eac:  a2 0e a0 ff  and  %i2, 0xff, %l1
a0115eb0:  94 60 3f ff  subx  %g0, -1, %o2
a0115eb4:  82 1c 60 10  xor  %l1, 0x10, %g1
a0115eb8:  80 a0 00 01  cmp  %g0, %g1
a0115ebc:  a0 60 3f ff  subx  %g0, -1, %l0
a0115ec0:  80 8a 80 10  btst  %o2, %l0
a0115ec4:  02 80 00 07  be  0xa0115ee0
a0115ec8:  94 02 00 09  add  %o0, %o1, %o2
a0115ecc:  96 0b e0 ff  and  %o7, 0xff, %o3
a0115ed0:  80 a0 00 0b  cmp  %g0, %o3
a0115ed4:  98 60 20 00  subx  %g0, 0, %o4
a0115ed8:  96 0e 80 0c  and  %i2, %o4, %o3
a0115edc:  94 02 00 09  add  %o0, %o1, %o2
a0115ee0:  92 02 80 0b  add  %o2, %o3, %o1
a0115ee4:  b4 02 40 0f  add  %o1, %o7, %i2
a0115ee8:  90 0d 20 ff  and  %l4, 0xff, %o0
a0115eec:  1f 33 c0 4b  sethi  %hi(0xcf012c00), %o7
a0115ef0:  a8 13 e2 00  or  %o7, 0x200, %l4	! 0xcf012e00
a0115ef4:  d0 25 00 00  st  %o0, [ %l4 ]
a0115ef8:  40 00 09 99  call  0xa011855c
a0115efc:  a0 16 80 12  or  %i2, %l2, %l0
a0115f00:  83 36 60 10  srl  %i1, 0x10, %g1
a0115f04:  80 a0 60 01  cmp  %g1, 1
a0115f08:  04 80 00 a4  ble  0xa0116198
a0115f0c:  96 10 20 00  clr  %o3
a0115f10:  80 a0 60 03  cmp  %g1, 3
a0115f14:  14 80 00 a3  bg  0xa01161a0
a0115f18:  80 a6 20 01  cmp  %i0, 1
a0115f1c:  12 80 00 a4  bne  0xa01161ac
a0115f20:  96 10 20 c7  mov  0xc7, %o3
a0115f24:  a3 36 60 10  srl  %i1, 0x10, %l1
a0115f28:  80 a0 00 11  cmp  %g0, %l1
a0115f2c:  9e 60 3f ff  subx  %g0, -1, %o7
a0115f30:  a4 1c 60 02  xor  %l1, 2, %l2
a0115f34:  80 a0 00 12  cmp  %g0, %l2
a0115f38:  15 33 c0 8c  sethi  %hi(0xcf023000), %o2
a0115f3c:  90 60 3f ff  subx  %g0, -1, %o0
a0115f40:  92 12 a3 f8  or  %o2, 0x3f8, %o1
a0115f44:  c0 22 40 00  clr  [ %o1 ]
a0115f48:  80 93 c0 08  orcc  %o7, %o0, %g0
a0115f4c:  02 80 00 e9  be  0xa01162f0
a0115f50:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0115f54:  03 00 00 23  sethi  %hi(0x8c00), %g1
a0115f58:  96 03 40 01  add  %o5, %g1, %o3
a0115f5c:  9b 2a e0 02  sll  %o3, 2, %o5
a0115f60:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a0115f64:  9a 13 40 1a  or  %o5, %i2, %o5
a0115f68:  d8 03 40 00  ld  [ %o5 ], %o4
a0115f6c:  82 0b 20 f0  and  %o4, 0xf0, %g1
a0115f70:  98 0c e0 0f  and  %l3, 0xf, %o4
a0115f74:  96 10 40 0c  or  %g1, %o4, %o3
a0115f78:  d6 23 40 00  st  %o3, [ %o5 ]
a0115f7c:  67 fd dc 89  call  0x4008d1a0
a0115f80:  90 10 20 01  mov  1, %o0
a0115f84:  83 36 60 10  srl  %i1, 0x10, %g1
a0115f88:  80 a0 60 01  cmp  %g1, 1
a0115f8c:  14 80 00 92  bg  0xa01161d4
a0115f90:  96 10 20 00  clr  %o3
a0115f94:  96 10 20 c8  mov  0xc8, %o3
a0115f98:  80 a6 20 01  cmp  %i0, 1
a0115f9c:  02 80 00 94  be  0xa01161ec
a0115fa0:  a7 36 60 10  srl  %i1, 0x10, %l3
a0115fa4:  80 a6 20 01  cmp  %i0, 1
a0115fa8:  04 80 01 35  ble  0xa011647c
a0115fac:  80 a6 20 02  cmp  %i0, 2
a0115fb0:  12 80 01 c5  bne  0xa01166c4
a0115fb4:  b5 36 60 10  srl  %i1, 0x10, %i2
a0115fb8:  10 80 01 23  b  0xa0116444
a0115fbc:  80 a0 00 1a  cmp  %g0, %i2
a0115fc0:  99 36 60 04  srl  %i1, 4, %o4
a0115fc4:  b3 2a a0 10  sll  %o2, 0x10, %i1
a0115fc8:  83 36 60 10  srl  %i1, 0x10, %g1
a0115fcc:  a6 10 00 0c  mov  %o4, %l3
a0115fd0:  80 a0 60 01  cmp  %g1, 1
a0115fd4:  98 10 20 00  clr  %o4
a0115fd8:  14 bf ff 29  bg  0xa0115c7c
a0115fdc:  9a 10 20 00  clr  %o5
a0115fe0:  9a 10 20 c8  mov  0xc8, %o5
a0115fe4:  b0 0a 60 ff  and  %o1, 0xff, %i0
a0115fe8:  80 a6 20 01  cmp  %i0, 1
a0115fec:  02 bf ff 2b  be  0xa0115c98
a0115ff0:  9e 0b 60 ff  and  %o5, 0xff, %o7
a0115ff4:  80 a6 20 01  cmp  %i0, 1
a0115ff8:  04 80 01 4f  ble  0xa0116534
a0115ffc:  80 a6 20 02  cmp  %i0, 2
a0116000:  22 80 01 0b  be,a   0xa011642c
a0116004:  19 00 00 22  sethi  %hi(0x8800), %o4
a0116008:  83 36 60 10  srl  %i1, 0x10, %g1
a011600c:  80 a0 60 01  cmp  %g1, 1
a0116010:  02 bf ff 30  be  0xa0115cd0
a0116014:  1f 33 c0 4b  sethi  %hi(0xcf012c00), %o7
a0116018:  80 a0 60 01  cmp  %g1, 1
a011601c:  04 80 00 e5  ble  0xa01163b0
a0116020:  80 a0 60 02  cmp  %g1, 2
a0116024:  02 80 00 e6  be  0xa01163bc
a0116028:  80 a0 60 03  cmp  %g1, 3
a011602c:  02 bf ff 29  be  0xa0115cd0
a0116030:  1f 33 c0 4b  sethi  %hi(0xcf012c00), %o7
a0116034:  1f 33 c0 4b  sethi  %hi(0xcf012c00), %o7
a0116038:  96 13 e2 00  or  %o7, 0x200, %o3	! 0xcf012e00
a011603c:  da 02 c0 00  ld  [ %o3 ], %o5
a0116040:  94 0b 20 ff  and  %o4, 0xff, %o2
a0116044:  96 0e a0 ff  and  %i2, 0xff, %o3
a0116048:  03 33 c0 4e  sethi  %hi(0xcf013800), %g1
a011604c:  c0 20 40 00  clr  [ %g1 ]
a0116050:  a8 10 00 0d  mov  %o5, %l4
a0116054:  80 a2 e0 07  cmp  %o3, 7
a0116058:  02 bf ff 2a  be  0xa0115d00
a011605c:  aa 10 00 0a  mov  %o2, %l5
a0116060:  80 a2 e0 06  cmp  %o3, 6
a0116064:  28 80 00 06  bleu,a   0xa011607c
a0116068:  90 02 80 1a  add  %o2, %i2, %o0
a011606c:  80 a2 e0 07  cmp  %o3, 7
a0116070:  08 80 00 09  bleu  0xa0116094
a0116074:  83 36 60 10  srl  %i1, 0x10, %g1
a0116078:  90 02 80 1a  add  %o2, %i2, %o0
a011607c:  98 04 c0 1a  add  %l3, %i2, %o4
a0116080:  a0 03 3f f9  add  %o4, -7, %l0
a0116084:  b4 02 3f f9  add  %o0, -7, %i2
a0116088:  90 0c 20 0f  and  %l0, 0xf, %o0
a011608c:  a0 0e a0 0f  and  %i2, 0xf, %l0
a0116090:  83 36 60 10  srl  %i1, 0x10, %g1
a0116094:  80 a0 60 01  cmp  %g1, 1
a0116098:  04 80 00 6b  ble  0xa0116244
a011609c:  96 10 20 00  clr  %o3
a01160a0:  80 a0 60 03  cmp  %g1, 3
a01160a4:  14 80 00 6a  bg  0xa011624c
a01160a8:  80 a6 20 01  cmp  %i0, 1
a01160ac:  12 80 00 6b  bne  0xa0116258
a01160b0:  96 10 20 c7  mov  0xc7, %o3
a01160b4:  9b 36 60 10  srl  %i1, 0x10, %o5
a01160b8:  80 a0 00 0d  cmp  %g0, %o5
a01160bc:  92 60 3f ff  subx  %g0, -1, %o1
a01160c0:  82 1b 60 02  xor  %o5, 2, %g1
a01160c4:  80 a0 00 01  cmp  %g0, %g1
a01160c8:  25 33 c0 8c  sethi  %hi(0xcf023000), %l2
a01160cc:  a2 60 3f ff  subx  %g0, -1, %l1
a01160d0:  94 14 a3 f8  or  %l2, 0x3f8, %o2
a01160d4:  c0 22 80 00  clr  [ %o2 ]
a01160d8:  80 92 40 11  orcc  %o1, %l1, %g0
a01160dc:  02 80 00 a9  be  0xa0116380
a01160e0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a01160e4:  03 00 00 23  sethi  %hi(0x8c00), %g1
a01160e8:  b4 03 40 01  add  %o5, %g1, %i2
a01160ec:  9b 2e a0 02  sll  %i2, 2, %o5
a01160f0:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a01160f4:  9a 13 40 0f  or  %o5, %o7, %o5
a01160f8:  d6 03 40 00  ld  [ %o5 ], %o3
a01160fc:  82 0a e0 f0  and  %o3, 0xf0, %g1
a0116100:  98 0a 20 0f  and  %o0, 0xf, %o4
a0116104:  a2 10 40 0c  or  %g1, %o4, %l1
a0116108:  e2 23 40 00  st  %l1, [ %o5 ]
a011610c:  67 fd dc 25  call  0x4008d1a0
a0116110:  90 10 20 01  mov  1, %o0
a0116114:  83 36 60 10  srl  %i1, 0x10, %g1
a0116118:  80 a0 60 01  cmp  %g1, 1
a011611c:  14 80 00 59  bg  0xa0116280
a0116120:  96 10 20 00  clr  %o3
a0116124:  96 10 20 c8  mov  0xc8, %o3
a0116128:  80 a6 20 01  cmp  %i0, 1
a011612c:  22 80 00 5b  be,a   0xa0116298
a0116130:  83 36 60 10  srl  %i1, 0x10, %g1
a0116134:  80 a6 20 01  cmp  %i0, 1
a0116138:  04 80 01 39  ble  0xa011661c
a011613c:  80 a6 20 02  cmp  %i0, 2
a0116140:  02 80 01 16  be  0xa0116598
a0116144:  a5 36 60 10  srl  %i1, 0x10, %l2
a0116148:  67 fd dc 16  call  0x4008d1a0
a011614c:  90 10 20 01  mov  1, %o0
a0116150:  10 bf fe ed  b  0xa0115d04
a0116154:  21 33 c0 4b  sethi  %hi(0xcf012c00), %l0
a0116158:  b0 0a e0 ff  and  %o3, 0xff, %i0
a011615c:  80 a6 20 01  cmp  %i0, 1
a0116160:  12 bf fe b1  bne  0xa0115c24
a0116164:  9a 10 20 c6  mov  0xc6, %o5
a0116168:  b0 0b 60 ff  and  %o5, 0xff, %i0
a011616c:  03 00 00 23  sethi  %hi(0x8c00), %g1
a0116170:  aa 06 00 01  add  %i0, %g1, %l5
a0116174:  9b 2d 60 02  sll  %l5, 2, %o5
a0116178:  03 33 c0 8c  sethi  %hi(0xcf023000), %g1
a011617c:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a0116180:  9e 10 63 f8  or  %g1, 0x3f8, %o7
a0116184:  9a 13 40 0c  or  %o5, %o4, %o5
a0116188:  c0 23 c0 00  clr  [ %o7 ]
a011618c:  d6 03 40 00  ld  [ %o5 ], %o3
a0116190:  10 bf fe a9  b  0xa0115c34
a0116194:  98 10 00 0b  mov  %o3, %o4
a0116198:  96 10 20 c6  mov  0xc6, %o3
a011619c:  80 a6 20 01  cmp  %i0, 1
a01161a0:  02 bf ff 62  be  0xa0115f28
a01161a4:  a3 36 60 10  srl  %i1, 0x10, %l1
a01161a8:  80 a6 20 01  cmp  %i0, 1
a01161ac:  04 80 00 d0  ble  0xa01164ec
a01161b0:  80 a6 20 02  cmp  %i0, 2
a01161b4:  02 80 00 8f  be  0xa01163f0
a01161b8:  a3 36 60 10  srl  %i1, 0x10, %l1
a01161bc:  67 fd db f9  call  0x4008d1a0
a01161c0:  90 10 20 01  mov  1, %o0
a01161c4:  83 36 60 10  srl  %i1, 0x10, %g1
a01161c8:  80 a0 60 01  cmp  %g1, 1
a01161cc:  04 bf ff 72  ble  0xa0115f94
a01161d0:  96 10 20 00  clr  %o3
a01161d4:  80 a0 60 03  cmp  %g1, 3
a01161d8:  14 bf ff 71  bg  0xa0115f9c
a01161dc:  80 a6 20 01  cmp  %i0, 1
a01161e0:  12 bf ff 72  bne  0xa0115fa8
a01161e4:  96 10 20 c9  mov  0xc9, %o3
a01161e8:  a7 36 60 10  srl  %i1, 0x10, %l3
a01161ec:  80 a0 00 13  cmp  %g0, %l3
a01161f0:  94 60 3f ff  subx  %g0, -1, %o2
a01161f4:  98 1c e0 02  xor  %l3, 2, %o4
a01161f8:  80 a0 00 0c  cmp  %g0, %o4
a01161fc:  23 33 c0 8c  sethi  %hi(0xcf023000), %l1
a0116200:  92 60 3f ff  subx  %g0, -1, %o1
a0116204:  a4 14 63 f8  or  %l1, 0x3f8, %l2
a0116208:  c0 24 80 00  clr  [ %l2 ]
a011620c:  80 92 80 09  orcc  %o2, %o1, %g0
a0116210:  02 80 00 44  be  0xa0116320
a0116214:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0116218:  03 00 00 23  sethi  %hi(0x8c00), %g1
a011621c:  90 03 40 01  add  %o5, %g1, %o0
a0116220:  b3 2a 20 02  sll  %o0, 2, %i1
a0116224:  29 33 c0 00  sethi  %hi(0xcf000000), %l4
a0116228:  9a 16 40 14  or  %i1, %l4, %o5
a011622c:  f0 03 40 00  ld  [ %o5 ], %i0
a0116230:  82 0e 20 f0  and  %i0, 0xf0, %g1
a0116234:  98 0d 60 0f  and  %l5, 0xf, %o4
a0116238:  b0 10 40 0c  or  %g1, %o4, %i0
a011623c:  f0 23 40 00  st  %i0, [ %o5 ]
a0116240:  30 80 01 21  b,a   0xa01166c4
a0116244:  96 10 20 c6  mov  0xc6, %o3
a0116248:  80 a6 20 01  cmp  %i0, 1
a011624c:  02 bf ff 9b  be  0xa01160b8
a0116250:  9b 36 60 10  srl  %i1, 0x10, %o5
a0116254:  80 a6 20 01  cmp  %i0, 1
a0116258:  04 80 00 df  ble  0xa01165d4
a011625c:  80 a6 20 02  cmp  %i0, 2
a0116260:  02 80 00 bf  be  0xa011655c
a0116264:  a5 36 60 10  srl  %i1, 0x10, %l2
a0116268:  67 fd db ce  call  0x4008d1a0
a011626c:  90 10 20 01  mov  1, %o0
a0116270:  83 36 60 10  srl  %i1, 0x10, %g1
a0116274:  80 a0 60 01  cmp  %g1, 1
a0116278:  04 bf ff ab  ble  0xa0116124
a011627c:  96 10 20 00  clr  %o3
a0116280:  80 a0 60 03  cmp  %g1, 3
a0116284:  14 bf ff aa  bg  0xa011612c
a0116288:  80 a6 20 01  cmp  %i0, 1
a011628c:  12 bf ff ab  bne  0xa0116138
a0116290:  96 10 20 c9  mov  0xc9, %o3
a0116294:  83 36 60 10  srl  %i1, 0x10, %g1
a0116298:  80 a0 00 01  cmp  %g0, %g1
a011629c:  98 60 3f ff  subx  %g0, -1, %o4
a01162a0:  a4 18 60 02  xor  %g1, 2, %l2
a01162a4:  80 a0 00 12  cmp  %g0, %l2
a01162a8:  15 33 c0 8c  sethi  %hi(0xcf023000), %o2
a01162ac:  a2 60 3f ff  subx  %g0, -1, %l1
a01162b0:  92 12 a3 f8  or  %o2, 0x3f8, %o1
a01162b4:  c0 22 40 00  clr  [ %o1 ]
a01162b8:  80 93 00 11  orcc  %o4, %l1, %g0
a01162bc:  02 80 00 25  be  0xa0116350
a01162c0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a01162c4:  03 00 00 23  sethi  %hi(0x8c00), %g1
a01162c8:  9e 03 40 01  add  %o5, %g1, %o7
a01162cc:  9b 2b e0 02  sll  %o7, 2, %o5
a01162d0:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a01162d4:  9a 13 40 0b  or  %o5, %o3, %o5
a01162d8:  d0 03 40 00  ld  [ %o5 ], %o0
a01162dc:  82 0a 20 f0  and  %o0, 0xf0, %g1
a01162e0:  98 0c 20 0f  and  %l0, 0xf, %o4
a01162e4:  b4 10 40 0c  or  %g1, %o4, %i2
a01162e8:  f4 23 40 00  st  %i2, [ %o5 ]
a01162ec:  30 bf ff 97  b,a   0xa0116148
a01162f0:  03 00 00 23  sethi  %hi(0x8c00), %g1
a01162f4:  b4 03 40 01  add  %o5, %g1, %i2
a01162f8:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a01162fc:  9b 2e a0 02  sll  %i2, 2, %o5
a0116300:  9a 13 40 01  or  %o5, %g1, %o5
a0116304:  98 0c e0 ff  and  %l3, 0xff, %o4
a0116308:  e6 03 40 00  ld  [ %o5 ], %l3
a011630c:  82 0c e0 0f  and  %l3, 0xf, %g1
a0116310:  99 2b 20 04  sll  %o4, 4, %o4
a0116314:  96 10 40 0c  or  %g1, %o4, %o3
a0116318:  d6 23 40 00  st  %o3, [ %o5 ]
a011631c:  30 bf ff 18  b,a   0xa0115f7c
a0116320:  03 00 00 23  sethi  %hi(0x8c00), %g1
a0116324:  96 03 40 01  add  %o5, %g1, %o3
a0116328:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a011632c:  9b 2a e0 02  sll  %o3, 2, %o5
a0116330:  9a 13 40 01  or  %o5, %g1, %o5
a0116334:  b4 0d 60 ff  and  %l5, 0xff, %i2
a0116338:  ea 03 40 00  ld  [ %o5 ], %l5
a011633c:  82 0d 60 0f  and  %l5, 0xf, %g1
a0116340:  99 2e a0 04  sll  %i2, 4, %o4
a0116344:  b0 10 40 0c  or  %g1, %o4, %i0
a0116348:  f0 23 40 00  st  %i0, [ %o5 ]
a011634c:  30 80 00 de  b,a   0xa01166c4
a0116350:  03 00 00 23  sethi  %hi(0x8c00), %g1
a0116354:  9e 03 40 01  add  %o5, %g1, %o7
a0116358:  9b 2b e0 02  sll  %o7, 2, %o5
a011635c:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a0116360:  9a 13 40 0b  or  %o5, %o3, %o5
a0116364:  90 0c 20 ff  and  %l0, 0xff, %o0
a0116368:  e0 03 40 00  ld  [ %o5 ], %l0
a011636c:  82 0c 20 0f  and  %l0, 0xf, %g1
a0116370:  99 2a 20 04  sll  %o0, 4, %o4
a0116374:  b4 10 40 0c  or  %g1, %o4, %i2
a0116378:  f4 23 40 00  st  %i2, [ %o5 ]
a011637c:  30 bf ff 73  b,a   0xa0116148
a0116380:  03 00 00 23  sethi  %hi(0x8c00), %g1
a0116384:  98 03 40 01  add  %o5, %g1, %o4
a0116388:  9f 2b 20 02  sll  %o4, 2, %o7
a011638c:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a0116390:  9a 13 c0 1a  or  %o7, %i2, %o5
a0116394:  96 0a 20 ff  and  %o0, 0xff, %o3
a0116398:  d0 03 40 00  ld  [ %o5 ], %o0
a011639c:  82 0a 20 0f  and  %o0, 0xf, %g1
a01163a0:  99 2a e0 04  sll  %o3, 4, %o4
a01163a4:  a2 10 40 0c  or  %g1, %o4, %l1
a01163a8:  e2 23 40 00  st  %l1, [ %o5 ]
a01163ac:  30 bf ff 58  b,a   0xa011610c
a01163b0:  80 a0 60 00  cmp  %g1, 0
a01163b4:  12 bf ff 21  bne  0xa0116038
a01163b8:  1f 33 c0 4b  sethi  %hi(0xcf012c00), %o7
a01163bc:  10 bf ff 1e  b  0xa0116034
a01163c0:  98 0b 20 0f  and  %o4, 0xf, %o4
a01163c4:  80 a0 60 00  cmp  %g1, 0
a01163c8:  12 bf fe 27  bne  0xa0115c64
a01163cc:  b3 2a a0 10  sll  %o2, 0x10, %i1
a01163d0:  10 bf fe 24  b  0xa0115c60
a01163d4:  98 0b 20 0f  and  %o4, 0xf, %o4
a01163d8:  a4 0b 60 ff  and  %o5, 0xff, %l2
a01163dc:  a6 15 23 00  or  %l4, 0x300, %l3
a01163e0:  a2 04 80 13  add  %l2, %l3, %l1
a01163e4:  9b 2c 60 02  sll  %l1, 2, %o5
a01163e8:  10 bf ff 65  b  0xa011617c
a01163ec:  03 33 c0 8b  sethi  %hi(0xcf022c00), %g1
a01163f0:  80 a0 00 11  cmp  %g0, %l1
a01163f4:  9e 60 3f ff  subx  %g0, -1, %o7
a01163f8:  a4 1c 60 02  xor  %l1, 2, %l2
a01163fc:  80 a0 00 12  cmp  %g0, %l2
a0116400:  15 33 c0 8b  sethi  %hi(0xcf022c00), %o2
a0116404:  90 60 3f ff  subx  %g0, -1, %o0
a0116408:  92 12 a3 f8  or  %o2, 0x3f8, %o1
a011640c:  c0 22 40 00  clr  [ %o1 ]
a0116410:  80 93 c0 08  orcc  %o7, %o0, %g0
a0116414:  02 80 00 97  be  0xa0116670
a0116418:  29 00 00 22  sethi  %hi(0x8800), %l4
a011641c:  03 00 00 22  sethi  %hi(0x8800), %g1
a0116420:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0116424:  10 bf fe cd  b  0xa0115f58
a0116428:  82 10 63 00  or  %g1, 0x300, %g1
a011642c:  96 0b 60 ff  and  %o5, 0xff, %o3
a0116430:  82 13 23 00  or  %o4, 0x300, %g1
a0116434:  aa 02 c0 01  add  %o3, %g1, %l5
a0116438:  9b 2d 60 02  sll  %l5, 2, %o5
a011643c:  10 bf fe 1b  b  0xa0115ca8
a0116440:  03 33 c0 8b  sethi  %hi(0xcf022c00), %g1
a0116444:  98 60 3f ff  subx  %g0, -1, %o4
a0116448:  82 1e a0 02  xor  %i2, 2, %g1
a011644c:  80 a0 00 01  cmp  %g0, %g1
a0116450:  1b 33 c0 8b  sethi  %hi(0xcf022c00), %o5
a0116454:  a2 60 3f ff  subx  %g0, -1, %l1
a0116458:  a6 13 63 f8  or  %o5, 0x3f8, %l3
a011645c:  c0 24 c0 00  clr  [ %l3 ]
a0116460:  80 93 00 11  orcc  %o4, %l1, %g0
a0116464:  02 80 00 80  be  0xa0116664
a0116468:  1f 00 00 22  sethi  %hi(0x8800), %o7
a011646c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0116470:  17 00 00 22  sethi  %hi(0x8800), %o3
a0116474:  10 bf ff 6a  b  0xa011621c
a0116478:  82 12 e3 00  or  %o3, 0x300, %g1	! 0x8b00
a011647c:  80 a6 20 00  cmp  %i0, 0
a0116480:  12 80 00 91  bne  0xa01166c4
a0116484:  93 36 60 10  srl  %i1, 0x10, %o1
a0116488:  80 a0 00 09  cmp  %g0, %o1
a011648c:  b2 60 3f ff  subx  %g0, -1, %i1
a0116490:  9e 1a 60 02  xor  %o1, 2, %o7
a0116494:  80 a0 00 0f  cmp  %g0, %o7
a0116498:  11 33 c0 8a  sethi  %hi(0xcf022800), %o0
a011649c:  b0 60 3f ff  subx  %g0, -1, %i0
a01164a0:  a8 12 23 f8  or  %o0, 0x3f8, %l4
a01164a4:  c0 25 00 00  clr  [ %l4 ]
a01164a8:  80 96 40 18  orcc  %i1, %i0, %g0
a01164ac:  02 80 00 7d  be  0xa01166a0
a01164b0:  25 00 00 22  sethi  %hi(0x8800), %l2
a01164b4:  15 00 00 22  sethi  %hi(0x8800), %o2
a01164b8:  9a 0a e0 ff  and  %o3, 0xff, %o5
a01164bc:  10 bf ff 58  b  0xa011621c
a01164c0:  82 12 a2 00  or  %o2, 0x200, %g1
a01164c4:  80 a6 20 00  cmp  %i0, 0
a01164c8:  12 bf fd dc  bne  0xa0115c38
a01164cc:  a3 2e 60 10  sll  %i1, 0x10, %l1
a01164d0:  1f 00 00 22  sethi  %hi(0x8800), %o7
a01164d4:  96 0b 60 ff  and  %o5, 0xff, %o3
a01164d8:  98 13 e2 00  or  %o7, 0x200, %o4
a01164dc:  9a 02 c0 0c  add  %o3, %o4, %o5
a01164e0:  9b 2b 60 02  sll  %o5, 2, %o5
a01164e4:  10 bf ff 26  b  0xa011617c
a01164e8:  03 33 c0 8a  sethi  %hi(0xcf022800), %g1
a01164ec:  80 a6 20 00  cmp  %i0, 0
a01164f0:  12 bf ff 33  bne  0xa01161bc
a01164f4:  b5 36 60 10  srl  %i1, 0x10, %i2
a01164f8:  80 a0 00 1a  cmp  %g0, %i2
a01164fc:  a2 60 3f ff  subx  %g0, -1, %l1
a0116500:  98 1e a0 02  xor  %i2, 2, %o4
a0116504:  80 a0 00 0c  cmp  %g0, %o4
a0116508:  1b 33 c0 8a  sethi  %hi(0xcf022800), %o5
a011650c:  a4 60 3f ff  subx  %g0, -1, %l2
a0116510:  82 13 63 f8  or  %o5, 0x3f8, %g1
a0116514:  c0 20 40 00  clr  [ %g1 ]
a0116518:  80 94 40 12  orcc  %l1, %l2, %g0
a011651c:  02 80 00 5e  be  0xa0116694
a0116520:  29 00 00 22  sethi  %hi(0x8800), %l4
a0116524:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0116528:  17 00 00 22  sethi  %hi(0x8800), %o3
a011652c:  10 bf fe 8b  b  0xa0115f58
a0116530:  82 12 e2 00  or  %o3, 0x200, %g1	! 0x8a00
a0116534:  80 a6 20 00  cmp  %i0, 0
a0116538:  32 bf fe b5  bne,a   0xa011600c
a011653c:  83 36 60 10  srl  %i1, 0x10, %g1
a0116540:  29 00 00 22  sethi  %hi(0x8800), %l4
a0116544:  94 0b 60 ff  and  %o5, 0xff, %o2
a0116548:  a4 15 22 00  or  %l4, 0x200, %l2
a011654c:  92 02 80 12  add  %o2, %l2, %o1
a0116550:  9b 2a 60 02  sll  %o1, 2, %o5
a0116554:  10 bf fd d5  b  0xa0115ca8
a0116558:  03 33 c0 8a  sethi  %hi(0xcf022800), %g1
a011655c:  80 a0 00 12  cmp  %g0, %l2
a0116560:  98 60 3f ff  subx  %g0, -1, %o4
a0116564:  94 1c a0 02  xor  %l2, 2, %o2
a0116568:  80 a0 00 0a  cmp  %g0, %o2
a011656c:  13 33 c0 8b  sethi  %hi(0xcf022c00), %o1
a0116570:  b4 60 3f ff  subx  %g0, -1, %i2
a0116574:  a2 12 63 f8  or  %o1, 0x3f8, %l1
a0116578:  c0 24 40 00  clr  [ %l1 ]
a011657c:  80 93 00 1a  orcc  %o4, %i2, %g0
a0116580:  02 80 00 3f  be  0xa011667c
a0116584:  19 00 00 22  sethi  %hi(0x8800), %o4
a0116588:  03 00 00 22  sethi  %hi(0x8800), %g1
a011658c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0116590:  10 bf fe d6  b  0xa01160e8
a0116594:  82 10 63 00  or  %g1, 0x300, %g1
a0116598:  80 a0 00 12  cmp  %g0, %l2
a011659c:  98 60 3f ff  subx  %g0, -1, %o4
a01165a0:  94 1c a0 02  xor  %l2, 2, %o2
a01165a4:  80 a0 00 0a  cmp  %g0, %o2
a01165a8:  13 33 c0 8b  sethi  %hi(0xcf022c00), %o1
a01165ac:  b4 60 3f ff  subx  %g0, -1, %i2
a01165b0:  a2 12 63 f8  or  %o1, 0x3f8, %l1
a01165b4:  c0 24 40 00  clr  [ %l1 ]
a01165b8:  80 93 00 1a  orcc  %o4, %i2, %g0
a01165bc:  02 80 00 33  be  0xa0116688
a01165c0:  35 00 00 22  sethi  %hi(0x8800), %i2
a01165c4:  03 00 00 22  sethi  %hi(0x8800), %g1
a01165c8:  9a 0a e0 ff  and  %o3, 0xff, %o5
a01165cc:  10 bf ff 3f  b  0xa01162c8
a01165d0:  82 10 63 00  or  %g1, 0x300, %g1
a01165d4:  80 a6 20 00  cmp  %i0, 0
a01165d8:  12 bf ff 24  bne  0xa0116268
a01165dc:  83 36 60 10  srl  %i1, 0x10, %g1
a01165e0:  80 a0 00 01  cmp  %g0, %g1
a01165e4:  92 60 3f ff  subx  %g0, -1, %o1
a01165e8:  9a 18 60 02  xor  %g1, 2, %o5
a01165ec:  80 a0 00 0d  cmp  %g0, %o5
a01165f0:  25 33 c0 8a  sethi  %hi(0xcf022800), %l2
a01165f4:  a2 60 3f ff  subx  %g0, -1, %l1
a01165f8:  94 14 a3 f8  or  %l2, 0x3f8, %o2
a01165fc:  c0 22 80 00  clr  [ %o2 ]
a0116600:  80 92 40 11  orcc  %o1, %l1, %g0
a0116604:  02 80 00 2d  be  0xa01166b8
a0116608:  1f 00 00 22  sethi  %hi(0x8800), %o7
a011660c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0116610:  17 00 00 22  sethi  %hi(0x8800), %o3
a0116614:  10 bf fe b5  b  0xa01160e8
a0116618:  82 12 e2 00  or  %o3, 0x200, %g1	! 0x8a00
a011661c:  80 a6 20 00  cmp  %i0, 0
a0116620:  12 bf fe ca  bne  0xa0116148
a0116624:  91 36 60 10  srl  %i1, 0x10, %o0
a0116628:  80 a0 00 08  cmp  %g0, %o0
a011662c:  94 60 3f ff  subx  %g0, -1, %o2
a0116630:  9a 1a 20 02  xor  %o0, 2, %o5
a0116634:  80 a0 00 0d  cmp  %g0, %o5
a0116638:  03 33 c0 8a  sethi  %hi(0xcf022800), %g1
a011663c:  92 60 3f ff  subx  %g0, -1, %o1
a0116640:  a4 10 63 f8  or  %g1, 0x3f8, %l2
a0116644:  c0 24 80 00  clr  [ %l2 ]
a0116648:  80 92 80 09  orcc  %o2, %o1, %g0
a011664c:  02 80 00 18  be  0xa01166ac
a0116650:  1f 00 00 22  sethi  %hi(0x8800), %o7
a0116654:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0116658:  17 00 00 22  sethi  %hi(0x8800), %o3
a011665c:  10 bf ff 1b  b  0xa01162c8
a0116660:  82 12 e2 00  or  %o3, 0x200, %g1	! 0x8a00
a0116664:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0116668:  10 bf ff 2f  b  0xa0116324
a011666c:  82 13 e3 00  or  %o7, 0x300, %g1
a0116670:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0116674:  10 bf ff 20  b  0xa01162f4
a0116678:  82 15 23 00  or  %l4, 0x300, %g1
a011667c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0116680:  10 bf ff 41  b  0xa0116384
a0116684:  82 13 23 00  or  %o4, 0x300, %g1
a0116688:  9a 0a e0 ff  and  %o3, 0xff, %o5
a011668c:  10 bf ff 32  b  0xa0116354
a0116690:  82 16 a3 00  or  %i2, 0x300, %g1
a0116694:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0116698:  10 bf ff 17  b  0xa01162f4
a011669c:  82 15 22 00  or  %l4, 0x200, %g1
a01166a0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a01166a4:  10 bf ff 20  b  0xa0116324
a01166a8:  82 14 a2 00  or  %l2, 0x200, %g1
a01166ac:  9a 0a e0 ff  and  %o3, 0xff, %o5
a01166b0:  10 bf ff 29  b  0xa0116354
a01166b4:  82 13 e2 00  or  %o7, 0x200, %g1
a01166b8:  9a 0a e0 ff  and  %o3, 0xff, %o5
a01166bc:  10 bf ff 32  b  0xa0116384
a01166c0:  82 13 e2 00  or  %o7, 0x200, %g1
a01166c4:  67 fd da b7  call  0x4008d1a0
a01166c8:  90 10 20 01  mov  1, %o0
a01166cc:  b0 0c 20 ff  and  %l0, 0xff, %i0
a01166d0:  81 c7 e0 08  ret
a01166d4:  81 e8 00 00  restore
