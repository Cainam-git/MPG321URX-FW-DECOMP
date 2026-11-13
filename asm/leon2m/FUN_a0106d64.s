# leon2m FUN_a0106d64 0xa0106d64-0xa01070b4 (848 bytes)
a0106d64:  9d e3 bf 98  save  %sp, -104, %sp
a0106d68:  d2 06 00 00  ld  [ %i0 ], %o1
a0106d6c:  25 2a 00 b5  sethi  %hi(0xa802d400), %l2
a0106d70:  d2 24 a2 80  st  %o1, [ %l2 + 0x280 ]	! 0xa802d680
a0106d74:  da 06 20 04  ld  [ %i0 + 4 ], %o5
a0106d78:  92 14 a2 80  or  %l2, 0x280, %o1
a0106d7c:  da 22 60 04  st  %o5, [ %o1 + 4 ]
a0106d80:  d0 06 20 08  ld  [ %i0 + 8 ], %o0
a0106d84:  d0 22 60 08  st  %o0, [ %o1 + 8 ]
a0106d88:  c2 06 20 0c  ld  [ %i0 + 0xc ], %g1
a0106d8c:  c2 22 60 0c  st  %g1, [ %o1 + 0xc ]
a0106d90:  d8 06 20 10  ld  [ %i0 + 0x10 ], %o4
a0106d94:  d8 22 60 10  st  %o4, [ %o1 + 0x10 ]
a0106d98:  f2 06 20 14  ld  [ %i0 + 0x14 ], %i1
a0106d9c:  f2 22 60 14  st  %i1, [ %o1 + 0x14 ]
a0106da0:  e2 06 20 18  ld  [ %i0 + 0x18 ], %l1
a0106da4:  e2 22 60 18  st  %l1, [ %o1 + 0x18 ]
a0106da8:  d4 06 20 1c  ld  [ %i0 + 0x1c ], %o2
a0106dac:  d4 22 60 1c  st  %o2, [ %o1 + 0x1c ]
a0106db0:  15 33 c0 3b  sethi  %hi(0xcf00ec00), %o2
a0106db4:  d6 06 20 20  ld  [ %i0 + 0x20 ], %o3
a0106db8:  e0 0a 60 0c  ldub  [ %o1 + 0xc ], %l0
a0106dbc:  9e 12 a1 58  or  %o2, 0x158, %o7
a0106dc0:  e0 23 c0 00  st  %l0, [ %o7 ]
a0106dc4:  d6 22 60 20  st  %o3, [ %o1 + 0x20 ]
a0106dc8:  33 2a 00 b5  sethi  %hi(0xa802d400), %i1
a0106dcc:  d6 06 62 a4  ld  [ %i1 + 0x2a4 ], %o3	! 0xa802d6a4
a0106dd0:  d0 02 c0 00  ld  [ %o3 ], %o0
a0106dd4:  1b 00 1c 00  sethi  %hi(0x700000), %o5
a0106dd8:  82 0a 00 0d  and  %o0, %o5, %g1
a0106ddc:  19 00 08 00  sethi  %hi(0x200000), %o4
a0106de0:  80 a0 40 0c  cmp  %g1, %o4
a0106de4:  22 80 00 9f  be,a   0xa0107060
a0106de8:  de 0a e0 06  ldub  [ %o3 + 6 ], %o7
a0106dec:  03 33 c0 3b  sethi  %hi(0xcf00ec00), %g1
a0106df0:  98 10 20 40  mov  0x40, %o4
a0106df4:  a2 10 61 5c  or  %g1, 0x15c, %l1
a0106df8:  d8 24 40 00  st  %o4, [ %l1 ]
a0106dfc:  94 14 a2 80  or  %l2, 0x280, %o2
a0106e00:  21 33 c0 3b  sethi  %hi(0xcf00ec00), %l0
a0106e04:  96 14 21 a8  or  %l0, 0x1a8, %o3	! 0xcf00eda8
a0106e08:  de 0a a0 14  ldub  [ %o2 + 0x14 ], %o7
a0106e0c:  de 22 c0 00  st  %o7, [ %o3 ]
a0106e10:  d6 06 62 a4  ld  [ %i1 + 0x2a4 ], %o3
a0106e14:  f0 02 c0 00  ld  [ %o3 ], %i0
a0106e18:  1b 00 1c 00  sethi  %hi(0x700000), %o5
a0106e1c:  92 0e 00 0d  and  %i0, %o5, %o1
a0106e20:  11 00 08 00  sethi  %hi(0x200000), %o0
a0106e24:  80 a2 40 08  cmp  %o1, %o0
a0106e28:  22 80 00 84  be,a   0xa0107038
a0106e2c:  c2 0a e0 06  ldub  [ %o3 + 6 ], %g1
a0106e30:  7f ff ed 71  call  0xa01023f4
a0106e34:  90 10 20 00  clr  %o0
a0106e38:  da 06 62 a4  ld  [ %i1 + 0x2a4 ], %o5
a0106e3c:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a0106e40:  94 13 20 cd  or  %o4, 0xcd, %o2	! 0xcccccccd
a0106e44:  e0 03 60 34  ld  [ %o5 + 0x34 ], %l0
a0106e48:  80 54 00 0a  umul  %l0, %o2, %g0
a0106e4c:  9f 40 00 00  rd  %y, %o7
a0106e50:  93 33 e0 03  srl  %o7, 3, %o1
a0106e54:  d6 13 60 22  lduh  [ %o5 + 0x22 ], %o3
a0106e58:  b0 5a 40 0b  smul  %o1, %o3, %i0
a0106e5c:  90 10 20 00  clr  %o0
a0106e60:  7f ff ee 22  call  0xa01026e8
a0106e64:  92 10 00 18  mov  %i0, %o1
a0106e68:  a3 36 20 01  srl  %i0, 1, %l1
a0106e6c:  90 10 20 01  mov  1, %o0
a0106e70:  7f ff ee 1e  call  0xa01026e8
a0106e74:  92 10 00 11  mov  %l1, %o1
a0106e78:  92 10 00 11  mov  %l1, %o1
a0106e7c:  7f ff ee 1b  call  0xa01026e8
a0106e80:  90 10 20 02  mov  2, %o0
a0106e84:  90 10 20 03  mov  3, %o0
a0106e88:  7f ff ee 18  call  0xa01026e8
a0106e8c:  93 36 20 02  srl  %i0, 2, %o1
a0106e90:  d0 0c a2 80  ldub  [ %l2 + 0x280 ], %o0
a0106e94:  80 a2 20 00  cmp  %o0, 0
a0106e98:  02 80 00 06  be  0xa0106eb0
a0106e9c:  98 14 a2 80  or  %l2, 0x280, %o4
a0106ea0:  c2 13 20 10  lduh  [ %o4 + 0x10 ], %g1
a0106ea4:  80 a0 60 00  cmp  %g1, 0
a0106ea8:  12 80 00 20  bne  0xa0106f28
a0106eac:  da 13 20 12  lduh  [ %o4 + 0x12 ], %o5
a0106eb0:  1b 33 c0 4a  sethi  %hi(0xcf012800), %o5
a0106eb4:  a4 13 60 90  or  %o5, 0x90, %l2	! 0xcf012890
a0106eb8:  c2 04 80 00  ld  [ %l2 ], %g1
a0106ebc:  b0 08 7f fe  and  %g1, -2, %i0
a0106ec0:  f0 24 80 00  st  %i0, [ %l2 ]
a0106ec4:  a0 13 61 90  or  %o5, 0x190, %l0
a0106ec8:  d8 04 00 00  ld  [ %l0 ], %o4
a0106ecc:  94 0b 3f fe  and  %o4, -2, %o2
a0106ed0:  d4 24 00 00  st  %o2, [ %l0 ]
a0106ed4:  d8 06 62 a4  ld  [ %i1 + 0x2a4 ], %o4
a0106ed8:  23 33 c0 2e  sethi  %hi(0xcf00b800), %l1
a0106edc:  d2 13 20 30  lduh  [ %o4 + 0x30 ], %o1
a0106ee0:  7f ff b0 6b  call  0xa00f308c
a0106ee4:  90 14 60 1c  or  %l1, 0x1c, %o0
a0106ee8:  d4 06 62 a4  ld  [ %i1 + 0x2a4 ], %o2
a0106eec:  d2 12 a0 26  lduh  [ %o2 + 0x26 ], %o1
a0106ef0:  7f ff b0 67  call  0xa00f308c
a0106ef4:  90 14 60 24  or  %l1, 0x24, %o0
a0106ef8:  e0 06 62 a4  ld  [ %i1 + 0x2a4 ], %l0
a0106efc:  d6 14 20 28  lduh  [ %l0 + 0x28 ], %o3
a0106f00:  d2 14 20 26  lduh  [ %l0 + 0x26 ], %o1
a0106f04:  90 14 60 2c  or  %l1, 0x2c, %o0
a0106f08:  7f ff b0 61  call  0xa00f308c
a0106f0c:  92 02 40 0b  add  %o1, %o3, %o1
a0106f10:  de 06 62 a4  ld  [ %i1 + 0x2a4 ], %o7
a0106f14:  d0 13 e0 32  lduh  [ %o7 + 0x32 ], %o0
a0106f18:  f2 13 e0 30  lduh  [ %o7 + 0x30 ], %i1
a0106f1c:  b0 14 60 34  or  %l1, 0x34, %i0
a0106f20:  7f ff b0 5b  call  0xa00f308c
a0106f24:  93 ee 40 08  restore  %i1, %o0, %o1
a0106f28:  96 10 00 01  mov  %g1, %o3
a0106f2c:  90 00 7f e7  add  %g1, -25, %o0
a0106f30:  83 2a 20 10  sll  %o0, 0x10, %g1
a0106f34:  a5 30 60 10  srl  %g1, 0x10, %l2
a0106f38:  80 a4 a1 db  cmp  %l2, 0x1db
a0106f3c:  18 80 00 53  bgu  0xa0107088
a0106f40:  98 10 00 0d  mov  %o5, %o4
a0106f44:  9e 03 3f fb  add  %o4, -5, %o7
a0106f48:  9b 2b e0 10  sll  %o7, 0x10, %o5
a0106f4c:  13 00 00 04  sethi  %hi(0x1000), %o1
a0106f50:  a3 33 60 10  srl  %o5, 0x10, %l1
a0106f54:  b0 12 63 83  or  %o1, 0x383, %i0
a0106f58:  80 a4 40 18  cmp  %l1, %i0
a0106f5c:  38 80 00 02  bgu,a   0xa0106f64
a0106f60:  98 10 20 96  mov  0x96, %o4
a0106f64:  9b 2a e0 10  sll  %o3, 0x10, %o5
a0106f68:  99 2b 20 10  sll  %o4, 0x10, %o4
a0106f6c:  93 33 60 10  srl  %o5, 0x10, %o1
a0106f70:  95 33 20 10  srl  %o4, 0x10, %o2
a0106f74:  a0 5a 80 09  smul  %o2, %o1, %l0
a0106f78:  9e 10 25 dc  mov  0x5dc, %o7
a0106f7c:  83 3b e0 1f  sra  %o7, 0x1f, %g1
a0106f80:  81 80 60 00  mov  %g1, %y
a0106f84:  01 00 00 00  nop
a0106f88:  01 00 00 00  nop
a0106f8c:  01 00 00 00  nop
a0106f90:  b0 7b c0 09  sdiv  %o7, %o1, %i0
a0106f94:  97 2c 20 0f  sll  %l0, 0xf, %o3
a0106f98:  23 00 8f 2a  sethi  %hi(0x23ca800), %l1
a0106f9c:  91 32 e0 06  srl  %o3, 6, %o0
a0106fa0:  82 14 61 8d  or  %l1, 0x18d, %g1
a0106fa4:  80 52 00 01  umul  %o0, %g1, %g0
a0106fa8:  a5 40 00 00  rd  %y, %l2
a0106fac:  11 33 c0 4a  sethi  %hi(0xcf012800), %o0
a0106fb0:  96 12 20 98  or  %o0, 0x98, %o3	! 0xcf012898
a0106fb4:  92 0e 20 ff  and  %i0, 0xff, %o1
a0106fb8:  99 34 a0 0b  srl  %l2, 0xb, %o4
a0106fbc:  d2 22 c0 00  st  %o1, [ %o3 ]
a0106fc0:  9e 0b 20 ff  and  %o4, 0xff, %o7
a0106fc4:  94 12 20 9c  or  %o0, 0x9c, %o2
a0106fc8:  de 22 80 00  st  %o7, [ %o2 ]
a0106fcc:  e0 02 c0 00  ld  [ %o3 ], %l0
a0106fd0:  9a 14 20 80  or  %l0, 0x80, %o5
a0106fd4:  da 22 c0 00  st  %o5, [ %o3 ]
a0106fd8:  a4 12 21 98  or  %o0, 0x198, %l2
a0106fdc:  d2 24 80 00  st  %o1, [ %l2 ]
a0106fe0:  a2 12 21 9c  or  %o0, 0x19c, %l1
a0106fe4:  de 24 40 00  st  %o7, [ %l1 ]
a0106fe8:  f0 04 80 00  ld  [ %l2 ], %i0
a0106fec:  82 16 20 80  or  %i0, 0x80, %g1
a0106ff0:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a0106ff4:  c2 24 80 00  st  %g1, [ %l2 ]
a0106ff8:  d4 03 22 a4  ld  [ %o4 + 0x2a4 ], %o2
a0106ffc:  e0 02 80 00  ld  [ %o2 ], %l0
a0107000:  17 01 00 00  sethi  %hi(0x4000000), %o3
a0107004:  80 8c 00 0b  btst  %l0, %o3
a0107008:  02 80 00 22  be  0xa0107090
a010700c:  9e 12 20 90  or  %o0, 0x90, %o7
a0107010:  b0 12 20 90  or  %o0, 0x90, %i0
a0107014:  e2 06 00 00  ld  [ %i0 ], %l1
a0107018:  82 14 60 01  or  %l1, 1, %g1
a010701c:  c2 26 00 00  st  %g1, [ %i0 ]
a0107020:  98 12 21 90  or  %o0, 0x190, %o4
a0107024:  e4 03 00 00  ld  [ %o4 ], %l2
a0107028:  82 14 a0 01  or  %l2, 1, %g1
a010702c:  c2 23 00 00  st  %g1, [ %o4 ]
a0107030:  10 bf ff aa  b  0xa0106ed8
a0107034:  d8 06 62 a4  ld  [ %i1 + 0x2a4 ], %o4
a0107038:  98 00 7f f8  add  %g1, -8, %o4
a010703c:  a2 0b 20 ff  and  %o4, 0xff, %l1
a0107040:  80 a4 60 02  cmp  %l1, 2
a0107044:  18 bf ff 7b  bgu  0xa0106e30
a0107048:  01 00 00 00  nop
a010704c:  90 10 20 00  clr  %o0	! 0x0
a0107050:  92 10 20 8d  mov  0x8d, %o1
a0107054:  7f ff ac 91  call  0xa00f2298
a0107058:  94 10 20 08  mov  8, %o2
a010705c:  30 bf ff 75  b,a   0xa0106e30
a0107060:  96 03 ff f8  add  %o7, -8, %o3
a0107064:  b0 0a e0 ff  and  %o3, 0xff, %i0
a0107068:  80 a6 20 02  cmp  %i0, 2
a010706c:  18 bf ff 61  bgu  0xa0106df0
a0107070:  03 33 c0 3b  sethi  %hi(0xcf00ec00), %g1
a0107074:  a0 12 a1 5c  or  %o2, 0x15c, %l0
a0107078:  94 10 20 20  mov  0x20, %o2
a010707c:  d4 24 00 00  st  %o2, [ %l0 ]
a0107080:  10 bf ff 60  b  0xa0106e00
a0107084:  94 14 a2 80  or  %l2, 0x280, %o2
a0107088:  10 bf ff af  b  0xa0106f44
a010708c:  96 10 20 64  mov  0x64, %o3
a0107090:  d6 03 c0 00  ld  [ %o7 ], %o3
a0107094:  92 0a ff fe  and  %o3, -2, %o1
a0107098:  d2 23 c0 00  st  %o1, [ %o7 ]
a010709c:  98 12 21 90  or  %o0, 0x190, %o4
a01070a0:  d0 03 00 00  ld  [ %o4 ], %o0
a01070a4:  82 0a 3f fe  and  %o0, -2, %g1
a01070a8:  c2 23 00 00  st  %g1, [ %o4 ]
a01070ac:  10 bf ff 8b  b  0xa0106ed8
a01070b0:  d8 06 62 a4  ld  [ %i1 + 0x2a4 ], %o4
