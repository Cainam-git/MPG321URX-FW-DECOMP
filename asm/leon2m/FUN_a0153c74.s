# leon2m FUN_a0153c74 0xa0153c74-0xa01541ec (1400 bytes)
a0153c74:  9d e3 be 68  save  %sp, -408, %sp
a0153c78:  7f ff b1 a3  call  0xa0140304
a0153c7c:  90 10 20 00  clr  %o0
a0153c80:  80 8a 20 ff  btst  0xff, %o0
a0153c84:  02 80 00 99  be  0xa0153ee8
a0153c88:  9a 10 20 00  clr  %o5
a0153c8c:  98 10 20 00  clr  %o4
a0153c90:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a0153c94:  d8 3f bf a8  std  %o4, [ %fp + -88 ]
a0153c98:  d8 3f bf b0  std  %o4, [ %fp + -80 ]
a0153c9c:  d8 3f bf b8  std  %o4, [ %fp + -72 ]
a0153ca0:  d8 3f bf c0  std  %o4, [ %fp + -64 ]
a0153ca4:  d8 3f bf c8  std  %o4, [ %fp + -56 ]
a0153ca8:  d8 3f bf d0  std  %o4, [ %fp + -48 ]
a0153cac:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a0153cb0:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a0153cb4:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0153cb8:  a8 07 bf a8  add  %fp, -88, %l4
a0153cbc:  90 10 20 00  clr  %o0
a0153cc0:  92 10 24 70  mov  0x470, %o1
a0153cc4:  94 10 20 50  mov  0x50, %o2
a0153cc8:  7f ff b1 a6  call  0xa0140360
a0153ccc:  96 10 00 14  mov  %l4, %o3
a0153cd0:  e2 17 bf e2  lduh  [ %fp + -30 ], %l1
a0153cd4:  92 10 24 70  mov  0x470, %o1
a0153cd8:  90 10 20 00  clr  %o0
a0153cdc:  94 10 20 50  mov  0x50, %o2
a0153ce0:  7f ff b1 a0  call  0xa0140360
a0153ce4:  96 10 00 14  mov  %l4, %o3
a0153ce8:  93 2c 60 10  sll  %l1, 0x10, %o1
a0153cec:  a1 32 60 10  srl  %o1, 0x10, %l0
a0153cf0:  e4 17 bf e2  lduh  [ %fp + -30 ], %l2
a0153cf4:  80 a4 80 10  cmp  %l2, %l0
a0153cf8:  12 bf ff f2  bne  0xa0153cc0
a0153cfc:  90 10 20 00  clr  %o0
a0153d00:  1b 00 00 80  sethi  %hi(0x20000), %o5
a0153d04:  a8 13 60 00  mov  %o5, %l4	! 0x20000
a0153d08:  e6 15 21 aa  lduh  [ %l4 + 0x1aa ], %l3
a0153d0c:  2d 00 06 9d  sethi  %hi(0x1a7400), %l6
a0153d10:  90 15 a1 f8  or  %l6, 0x1f8, %o0	! 0x1a75f8
a0153d14:  92 10 00 12  mov  %l2, %o1
a0153d18:  7f fe 2d 16  call  0xa00df170
a0153d1c:  94 10 00 13  mov  %l3, %o2
a0153d20:  80 a4 c0 12  cmp  %l3, %l2
a0153d24:  02 80 00 cd  be  0xa0154058
a0153d28:  9a 10 20 01  mov  1, %o5
a0153d2c:  80 a3 60 01  cmp  %o5, 1
a0153d30:  02 80 00 e3  be  0xa01540bc
a0153d34:  9a 10 20 00  clr  %o5
a0153d38:  98 10 20 00  clr  %o4
a0153d3c:  d8 3f bf 70  std  %o4, [ %fp + -144 ]
a0153d40:  d8 3f bf 28  std  %o4, [ %fp + -216 ]
a0153d44:  d8 3f bf 30  std  %o4, [ %fp + -208 ]
a0153d48:  d8 3f bf 38  std  %o4, [ %fp + -200 ]
a0153d4c:  d8 3f bf 40  std  %o4, [ %fp + -192 ]
a0153d50:  d8 3f bf 48  std  %o4, [ %fp + -184 ]
a0153d54:  d8 3f bf 50  std  %o4, [ %fp + -176 ]
a0153d58:  d8 3f bf 58  std  %o4, [ %fp + -168 ]
a0153d5c:  d8 3f bf 60  std  %o4, [ %fp + -160 ]
a0153d60:  d8 3f bf 68  std  %o4, [ %fp + -152 ]
a0153d64:  a8 07 bf 28  add  %fp, -216, %l4
a0153d68:  90 10 20 00  clr  %o0
a0153d6c:  92 10 24 70  mov  0x470, %o1
a0153d70:  94 10 20 50  mov  0x50, %o2
a0153d74:  7f ff b1 7b  call  0xa0140360
a0153d78:  96 10 00 14  mov  %l4, %o3
a0153d7c:  e0 17 bf 62  lduh  [ %fp + -158 ], %l0
a0153d80:  90 10 20 00  clr  %o0
a0153d84:  92 10 24 70  mov  0x470, %o1
a0153d88:  94 10 20 50  mov  0x50, %o2
a0153d8c:  7f ff b1 75  call  0xa0140360
a0153d90:  96 10 00 14  mov  %l4, %o3
a0153d94:  99 2c 20 10  sll  %l0, 0x10, %o4
a0153d98:  bb 33 20 10  srl  %o4, 0x10, %i5
a0153d9c:  e4 17 bf 62  lduh  [ %fp + -158 ], %l2
a0153da0:  80 a4 80 1d  cmp  %l2, %i5
a0153da4:  12 bf ff f2  bne  0xa0153d6c
a0153da8:  90 10 20 00  clr  %o0
a0153dac:  11 00 00 80  sethi  %hi(0x20000), %o0
a0153db0:  a8 12 20 00  mov  %o0, %l4	! 0x20000
a0153db4:  e2 15 21 aa  lduh  [ %l4 + 0x1aa ], %l1
a0153db8:  90 15 a1 f8  or  %l6, 0x1f8, %o0
a0153dbc:  92 10 00 12  mov  %l2, %o1
a0153dc0:  7f fe 2c ec  call  0xa00df170
a0153dc4:  94 10 00 11  mov  %l1, %o2
a0153dc8:  80 a4 40 12  cmp  %l1, %l2
a0153dcc:  02 80 00 ed  be  0xa0154180
a0153dd0:  9a 10 20 01  mov  1, %o5
a0153dd4:  80 a3 60 02  cmp  %o5, 2
a0153dd8:  12 80 00 77  bne  0xa0153fb4
a0153ddc:  37 2a 00 b8  sethi  %hi(0xa802e000), %i3
a0153de0:  35 00 06 9d  sethi  %hi(0x1a7400), %i2
a0153de4:  92 10 20 02  mov  2, %o1
a0153de8:  7f fe 2c e2  call  0xa00df170
a0153dec:  90 16 a2 08  or  %i2, 0x208, %o0
a0153df0:  a4 07 bf 18  add  %fp, -232, %l2
a0153df4:  33 00 06 9d  sethi  %hi(0x1a7400), %i1
a0153df8:  92 16 61 e6  or  %i1, 0x1e6, %o1	! 0x1a75e6
a0153dfc:  90 10 00 12  mov  %l2, %o0
a0153e00:  7f ff a2 c4  call  0xa013c910
a0153e04:  94 10 20 10  mov  0x10, %o2
a0153e08:  a0 10 20 00  clr  %l0
a0153e0c:  99 2c 20 10  sll  %l0, 0x10, %o4
a0153e10:  bb 33 20 0c  srl  %o4, 0xc, %i5
a0153e14:  b8 07 63 00  add  %i5, 0x300, %i4
a0153e18:  ad 2f 20 10  sll  %i4, 0x10, %l6
a0153e1c:  93 35 a0 10  srl  %l6, 0x10, %o1
a0153e20:  90 10 20 00  clr  %o0
a0153e24:  94 10 20 10  mov  0x10, %o2
a0153e28:  96 10 00 12  mov  %l2, %o3
a0153e2c:  7f ff b4 12  call  0xa0140e74
a0153e30:  98 10 20 00  clr  %o4
a0153e34:  b6 04 20 01  add  %l0, 1, %i3
a0153e38:  83 2e e0 10  sll  %i3, 0x10, %g1
a0153e3c:  83 30 60 10  srl  %g1, 0x10, %g1
a0153e40:  80 a0 60 14  cmp  %g1, 0x14
a0153e44:  0a bf ff f2  bcs  0xa0153e0c
a0153e48:  a0 10 00 1b  mov  %i3, %l0
a0153e4c:  93 28 60 04  sll  %g1, 4, %o1
a0153e50:  90 10 21 40  mov  0x140, %o0
a0153e54:  a2 22 00 09  sub  %o0, %o1, %l1
a0153e58:  a1 2c 60 10  sll  %l1, 0x10, %l0
a0153e5c:  95 34 20 10  srl  %l0, 0x10, %o2
a0153e60:  80 a2 a0 00  cmp  %o2, 0
a0153e64:  22 80 00 0a  be,a   0xa0153e8c
a0153e68:  a4 07 be c8  add  %fp, -312, %l2
a0153e6c:  a6 02 63 00  add  %o1, 0x300, %l3
a0153e70:  93 2c e0 10  sll  %l3, 0x10, %o1
a0153e74:  93 32 60 10  srl  %o1, 0x10, %o1
a0153e78:  96 10 00 12  mov  %l2, %o3
a0153e7c:  90 10 20 00  clr  %o0
a0153e80:  7f ff b3 fd  call  0xa0140e74
a0153e84:  98 10 20 00  clr  %o4
a0153e88:  a4 07 be c8  add  %fp, -312, %l2
a0153e8c:  92 10 24 70  mov  0x470, %o1
a0153e90:  94 10 20 50  mov  0x50, %o2
a0153e94:  96 10 00 12  mov  %l2, %o3
a0153e98:  90 10 20 00  clr  %o0
a0153e9c:  7f ff b1 31  call  0xa0140360
a0153ea0:  29 00 00 80  sethi  %hi(0x20000), %l4
a0153ea4:  aa 15 20 00  mov  %l4, %l5	! 0x20000
a0153ea8:  d4 15 61 b0  lduh  [ %l5 + 0x1b0 ], %o2
a0153eac:  d6 15 61 ae  lduh  [ %l5 + 0x1ae ], %o3
a0153eb0:  da 15 61 a8  lduh  [ %l5 + 0x1a8 ], %o5
a0153eb4:  de 0d 61 8a  ldub  [ %l5 + 0x18a ], %o7
a0153eb8:  d6 37 bf 06  sth  %o3, [ %fp + -250 ]
a0153ebc:  d4 37 bf 08  sth  %o2, [ %fp + -248 ]
a0153ec0:  da 37 bf 00  sth  %o5, [ %fp + -256 ]
a0153ec4:  de 2f be e2  stb  %o7, [ %fp + -286 ]
a0153ec8:  7f ff 63 d4  call  0xa012ce18
a0153ecc:  01 00 00 00  nop
a0153ed0:  d0 37 bf 04  sth  %o0, [ %fp + -252 ]
a0153ed4:  96 10 00 12  mov  %l2, %o3
a0153ed8:  90 10 20 00  clr  %o0
a0153edc:  92 10 24 70  mov  0x470, %o1
a0153ee0:  10 80 00 32  b  0xa0153fa8
a0153ee4:  94 10 20 50  mov  0x50, %o2
a0153ee8:  11 00 06 9d  sethi  %hi(0x1a7400), %o0
a0153eec:  92 10 20 01  mov  1, %o1
a0153ef0:  7f fe 2c a0  call  0xa00df170
a0153ef4:  90 12 22 20  or  %o0, 0x220, %o0
a0153ef8:  19 00 00 80  sethi  %hi(0x20000), %o4
a0153efc:  82 13 20 00  mov  %o4, %g1	! 0x20000
a0153f00:  d8 18 61 b8  ldd  [ %g1 + 0x1b8 ], %o4
a0153f04:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a0153f08:  d8 18 61 40  ldd  [ %g1 + 0x140 ], %o4
a0153f0c:  d8 3f bf 78  std  %o4, [ %fp + -136 ]
a0153f10:  d8 18 61 90  ldd  [ %g1 + 0x190 ], %o4
a0153f14:  d8 3f bf c8  std  %o4, [ %fp + -56 ]
a0153f18:  d8 18 61 98  ldd  [ %g1 + 0x198 ], %o4
a0153f1c:  d8 3f bf d0  std  %o4, [ %fp + -48 ]
a0153f20:  d8 18 61 a0  ldd  [ %g1 + 0x1a0 ], %o4
a0153f24:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a0153f28:  d8 18 61 a8  ldd  [ %g1 + 0x1a8 ], %o4
a0153f2c:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a0153f30:  d4 18 61 48  ldd  [ %g1 + 0x148 ], %o2
a0153f34:  d0 18 61 50  ldd  [ %g1 + 0x150 ], %o0
a0153f38:  d8 18 61 b0  ldd  [ %g1 + 0x1b0 ], %o4
a0153f3c:  d4 3f bf 80  std  %o2, [ %fp + -128 ]
a0153f40:  d0 3f bf 88  std  %o0, [ %fp + -120 ]
a0153f44:  e0 18 61 58  ldd  [ %g1 + 0x158 ], %l0
a0153f48:  e4 18 61 60  ldd  [ %g1 + 0x160 ], %l2
a0153f4c:  e8 18 61 68  ldd  [ %g1 + 0x168 ], %l4
a0153f50:  ec 18 61 70  ldd  [ %g1 + 0x170 ], %l6
a0153f54:  f8 18 61 78  ldd  [ %g1 + 0x178 ], %i4
a0153f58:  f4 18 61 80  ldd  [ %g1 + 0x180 ], %i2
a0153f5c:  f0 18 61 88  ldd  [ %g1 + 0x188 ], %i0
a0153f60:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0153f64:  96 07 bf 78  add  %fp, -136, %o3
a0153f68:  90 10 20 00  clr  %o0
a0153f6c:  92 10 24 40  mov  0x440, %o1
a0153f70:  94 10 20 30  mov  0x30, %o2
a0153f74:  e0 3f bf 90  std  %l0, [ %fp + -112 ]
a0153f78:  e4 3f bf 98  std  %l2, [ %fp + -104 ]
a0153f7c:  e8 3f bf a0  std  %l4, [ %fp + -96 ]
a0153f80:  ec 3f bf a8  std  %l6, [ %fp + -88 ]
a0153f84:  f8 3f bf b0  std  %i4, [ %fp + -80 ]
a0153f88:  f4 3f bf b8  std  %i2, [ %fp + -72 ]
a0153f8c:  f0 3f bf c0  std  %i0, [ %fp + -64 ]
a0153f90:  7f ff b3 b9  call  0xa0140e74
a0153f94:  98 10 20 00  clr  %o4
a0153f98:  90 10 20 00  clr  %o0
a0153f9c:  92 10 24 70  mov  0x470, %o1
a0153fa0:  94 10 20 50  mov  0x50, %o2
a0153fa4:  96 07 bf a8  add  %fp, -88, %o3
a0153fa8:  7f ff b3 b3  call  0xa0140e74
a0153fac:  98 10 20 01  mov  1, %o4
a0153fb0:  37 2a 00 b8  sethi  %hi(0xa802e000), %i3
a0153fb4:  96 16 e1 f0  or  %i3, 0x1f0, %o3	! 0xa802e1f0
a0153fb8:  90 10 20 00  clr  %o0
a0153fbc:  92 10 24 40  mov  0x440, %o1
a0153fc0:  7f ff b0 e8  call  0xa0140360
a0153fc4:  94 10 20 30  mov  0x30, %o2
a0153fc8:  35 2a 00 b8  sethi  %hi(0xa802e000), %i2
a0153fcc:  96 16 a1 a0  or  %i2, 0x1a0, %o3	! 0xa802e1a0
a0153fd0:  90 10 20 00  clr  %o0
a0153fd4:  92 10 24 70  mov  0x470, %o1
a0153fd8:  7f ff b0 e2  call  0xa0140360
a0153fdc:  94 10 20 50  mov  0x50, %o2
a0153fe0:  33 00 00 80  sethi  %hi(0x20000), %i1
a0153fe4:  98 16 60 00  mov  %i1, %o4	! 0x20000
a0153fe8:  31 00 00 29  sethi  %hi(0xa400), %i0
a0153fec:  da 13 21 68  lduh  [ %o4 + 0x168 ], %o5
a0153ff0:  ae 16 21 a5  or  %i0, 0x1a5, %l7
a0153ff4:  80 a3 40 17  cmp  %o5, %l7
a0153ff8:  02 80 00 07  be  0xa0154014
a0153ffc:  03 00 06 9d  sethi  %hi(0x1a7400), %g1
a0154000:  90 10 62 48  or  %g1, 0x248, %o0	! 0x1a7648
a0154004:  7f fe 2c 5b  call  0xa00df170
a0154008:  92 10 20 03  mov  3, %o1
a015400c:  10 80 00 00  b  0xa015400c
a0154010:  01 00 00 00  nop
a0154014:  ec 13 21 b2  lduh  [ %o4 + 0x1b2 ], %l6
a0154018:  80 a5 80 0d  cmp  %l6, %o5
a015401c:  12 80 00 0a  bne  0xa0154044
a0154020:  39 00 06 9d  sethi  %hi(0x1a7400), %i4
a0154024:  3b 2a 00 b3  sethi  %hi(0xa802cc00), %i5
a0154028:  c2 07 60 4c  ld  [ %i5 + 0x4c ], %g1	! 0xa802cc4c
a015402c:  80 a0 60 00  cmp  %g1, 0
a0154030:  02 80 00 6d  be  0xa01541e4
a0154034:  01 00 00 00  nop
a0154038:  9f c0 40 00  call  %g1
a015403c:  01 00 00 00  nop
a0154040:  30 80 00 69  b,a   0xa01541e4
a0154044:  90 17 22 48  or  %i4, 0x248, %o0
a0154048:  7f fe 2c 4a  call  0xa00df170
a015404c:  92 10 20 04  mov  4, %o1
a0154050:  10 80 00 00  b  0xa0154050
a0154054:  01 00 00 00  nop
a0154058:  d6 17 bf e8  lduh  [ %fp + -24 ], %o3
a015405c:  d4 15 21 b0  lduh  [ %l4 + 0x1b0 ], %o2
a0154060:  80 a2 c0 0a  cmp  %o3, %o2
a0154064:  12 bf ff 33  bne  0xa0153d30
a0154068:  80 a3 60 01  cmp  %o5, 1
a015406c:  e4 17 bf e6  lduh  [ %fp + -26 ], %l2
a0154070:  de 15 21 ae  lduh  [ %l4 + 0x1ae ], %o7
a0154074:  80 a4 80 0f  cmp  %l2, %o7
a0154078:  12 bf ff 2d  bne  0xa0153d2c
a015407c:  9a 10 20 01  mov  1, %o5
a0154080:  ea 15 21 a8  lduh  [ %l4 + 0x1a8 ], %l5
a0154084:  e8 17 bf e0  lduh  [ %fp + -32 ], %l4
a0154088:  80 a5 00 15  cmp  %l4, %l5
a015408c:  12 bf ff 28  bne  0xa0153d2c
a0154090:  9a 10 20 02  mov  2, %o5
a0154094:  7f ff 63 61  call  0xa012ce18
a0154098:  01 00 00 00  nop
a015409c:  b7 2a 20 10  sll  %o0, 0x10, %i3
a01540a0:  b5 36 e0 10  srl  %i3, 0x10, %i2
a01540a4:  f2 17 bf e4  lduh  [ %fp + -28 ], %i1
a01540a8:  b0 1e 40 1a  xor  %i1, %i2, %i0
a01540ac:  80 a0 00 18  cmp  %g0, %i0
a01540b0:  ae 40 20 00  addx  %g0, 0, %l7
a01540b4:  10 bf ff 1e  b  0xa0153d2c
a01540b8:  9a 05 c0 17  add  %l7, %l7, %o5
a01540bc:  39 00 06 9d  sethi  %hi(0x1a7400), %i4
a01540c0:  90 17 22 08  or  %i4, 0x208, %o0	! 0x1a7608
a01540c4:  7f fe 2c 2b  call  0xa00df170
a01540c8:  92 10 20 01  mov  1, %o1
a01540cc:  2d 00 00 80  sethi  %hi(0x20000), %l6
a01540d0:  82 15 a0 00  mov  %l6, %g1	! 0x20000
a01540d4:  d8 18 61 b8  ldd  [ %g1 + 0x1b8 ], %o4
a01540d8:  d8 3f bf 70  std  %o4, [ %fp + -144 ]
a01540dc:  d8 18 61 40  ldd  [ %g1 + 0x140 ], %o4
a01540e0:  d8 3f bf 78  std  %o4, [ %fp + -136 ]
a01540e4:  d8 18 61 90  ldd  [ %g1 + 0x190 ], %o4
a01540e8:  d8 3f bf 48  std  %o4, [ %fp + -184 ]
a01540ec:  d8 18 61 98  ldd  [ %g1 + 0x198 ], %o4
a01540f0:  d8 3f bf 50  std  %o4, [ %fp + -176 ]
a01540f4:  d8 18 61 a0  ldd  [ %g1 + 0x1a0 ], %o4
a01540f8:  d8 3f bf 58  std  %o4, [ %fp + -168 ]
a01540fc:  d8 18 61 a8  ldd  [ %g1 + 0x1a8 ], %o4
a0154100:  d8 3f bf 60  std  %o4, [ %fp + -160 ]
a0154104:  d4 18 61 48  ldd  [ %g1 + 0x148 ], %o2
a0154108:  d0 18 61 50  ldd  [ %g1 + 0x150 ], %o0
a015410c:  d8 18 61 b0  ldd  [ %g1 + 0x1b0 ], %o4
a0154110:  d4 3f bf 80  std  %o2, [ %fp + -128 ]
a0154114:  d0 3f bf 88  std  %o0, [ %fp + -120 ]
a0154118:  e0 18 61 58  ldd  [ %g1 + 0x158 ], %l0
a015411c:  e4 18 61 60  ldd  [ %g1 + 0x160 ], %l2
a0154120:  e8 18 61 68  ldd  [ %g1 + 0x168 ], %l4
a0154124:  ec 18 61 70  ldd  [ %g1 + 0x170 ], %l6
a0154128:  f8 18 61 78  ldd  [ %g1 + 0x178 ], %i4
a015412c:  f4 18 61 80  ldd  [ %g1 + 0x180 ], %i2
a0154130:  f0 18 61 88  ldd  [ %g1 + 0x188 ], %i0
a0154134:  d8 3f bf 68  std  %o4, [ %fp + -152 ]
a0154138:  96 07 bf 78  add  %fp, -136, %o3
a015413c:  90 10 20 00  clr  %o0
a0154140:  92 10 24 40  mov  0x440, %o1
a0154144:  94 10 20 30  mov  0x30, %o2
a0154148:  e0 3f bf 90  std  %l0, [ %fp + -112 ]
a015414c:  e4 3f bf 98  std  %l2, [ %fp + -104 ]
a0154150:  e8 3f bf a0  std  %l4, [ %fp + -96 ]
a0154154:  ec 3f bf 28  std  %l6, [ %fp + -216 ]
a0154158:  f8 3f bf 30  std  %i4, [ %fp + -208 ]
a015415c:  f4 3f bf 38  std  %i2, [ %fp + -200 ]
a0154160:  f0 3f bf 40  std  %i0, [ %fp + -192 ]
a0154164:  7f ff b3 44  call  0xa0140e74
a0154168:  98 10 20 00  clr  %o4
a015416c:  90 10 20 00  clr  %o0
a0154170:  92 10 24 70  mov  0x470, %o1
a0154174:  94 10 20 50  mov  0x50, %o2
a0154178:  10 bf ff 8c  b  0xa0153fa8
a015417c:  96 07 bf 28  add  %fp, -216, %o3
a0154180:  e6 17 bf 68  lduh  [ %fp + -152 ], %l3
a0154184:  d2 15 21 b0  lduh  [ %l4 + 0x1b0 ], %o1
a0154188:  80 a4 c0 09  cmp  %l3, %o1
a015418c:  12 bf ff 13  bne  0xa0153dd8
a0154190:  80 a3 60 02  cmp  %o5, 2
a0154194:  da 17 bf 66  lduh  [ %fp + -154 ], %o5
a0154198:  d4 15 21 ae  lduh  [ %l4 + 0x1ae ], %o2
a015419c:  80 a3 40 0a  cmp  %o5, %o2
a01541a0:  12 bf ff 0d  bne  0xa0153dd4
a01541a4:  9a 10 20 01  mov  1, %o5
a01541a8:  d6 15 21 a8  lduh  [ %l4 + 0x1a8 ], %o3
a01541ac:  de 17 bf 60  lduh  [ %fp + -160 ], %o7
a01541b0:  80 a3 c0 0b  cmp  %o7, %o3
a01541b4:  12 bf ff 08  bne  0xa0153dd4
a01541b8:  9a 10 20 02  mov  2, %o5
a01541bc:  7f ff 63 17  call  0xa012ce18
a01541c0:  01 00 00 00  nop
a01541c4:  b1 2a 20 10  sll  %o0, 0x10, %i0
a01541c8:  af 36 20 10  srl  %i0, 0x10, %l7
a01541cc:  e8 17 bf 64  lduh  [ %fp + -156 ], %l4
a01541d0:  aa 1d 00 17  xor  %l4, %l7, %l5
a01541d4:  80 a0 00 15  cmp  %g0, %l5
a01541d8:  a4 40 20 00  addx  %g0, 0, %l2
a01541dc:  10 bf fe fe  b  0xa0153dd4
a01541e0:  9a 04 80 12  add  %l2, %l2, %o5
a01541e4:  81 c7 e0 08  ret
a01541e8:  81 e8 00 00  restore
