# leon2m FUN_a0155de0 0xa0155de0-0xa01560ac (716 bytes)
a0155de0:  9d e3 bf 98  save  %sp, -104, %sp
a0155de4:  c2 06 00 00  ld  [ %i0 ], %g1
a0155de8:  9e 10 00 18  mov  %i0, %o7
a0155dec:  80 a0 60 01  cmp  %g1, 1
a0155df0:  08 80 00 ad  bleu  0xa01560a4
a0155df4:  92 10 00 1a  mov  %i2, %o1
a0155df8:  fa 06 40 00  ld  [ %i1 ], %i5
a0155dfc:  80 a7 60 01  cmp  %i5, 1
a0155e00:  08 80 00 a9  bleu  0xa01560a4
a0155e04:  b0 10 00 19  mov  %i1, %i0
a0155e08:  80 a0 60 04  cmp  %g1, 4
a0155e0c:  12 80 00 0c  bne  0xa0155e3c
a0155e10:  80 a7 60 04  cmp  %i5, 4
a0155e14:  12 80 00 a4  bne  0xa01560a4
a0155e18:  b0 10 00 0f  mov  %o7, %i0
a0155e1c:  c2 06 60 04  ld  [ %i1 + 4 ], %g1
a0155e20:  fa 03 e0 04  ld  [ %o7 + 4 ], %i5
a0155e24:  39 00 06 a0  sethi  %hi(0x1a8000), %i4
a0155e28:  80 a7 40 01  cmp  %i5, %g1
a0155e2c:  12 80 00 9e  bne  0xa01560a4
a0155e30:  b0 17 22 c0  or  %i4, 0x2c0, %i0
a0155e34:  10 80 00 9c  b  0xa01560a4
a0155e38:  b0 10 00 0f  mov  %o7, %i0
a0155e3c:  02 80 00 9a  be  0xa01560a4
a0155e40:  b0 10 00 19  mov  %i1, %i0
a0155e44:  80 a7 60 02  cmp  %i5, 2
a0155e48:  02 80 00 58  be  0xa0155fa8
a0155e4c:  80 a0 60 02  cmp  %g1, 2
a0155e50:  02 80 00 95  be  0xa01560a4
a0155e54:  01 00 00 00  nop
a0155e58:  d0 03 e0 08  ld  [ %o7 + 8 ], %o0
a0155e5c:  f0 06 60 08  ld  [ %i1 + 8 ], %i0
a0155e60:  82 22 00 18  sub  %o0, %i0, %g1
a0155e64:  bb 38 60 1f  sra  %g1, 0x1f, %i5
a0155e68:  82 18 40 1d  xor  %g1, %i5, %g1
a0155e6c:  82 20 40 1d  sub  %g1, %i5, %g1
a0155e70:  80 a0 60 3f  cmp  %g1, 0x3f
a0155e74:  d8 1b e0 10  ldd  [ %o7 + 0x10 ], %o4
a0155e78:  14 80 00 67  bg  0xa0156014
a0155e7c:  d4 1e 60 10  ldd  [ %i1 + 0x10 ], %o2
a0155e80:  80 a2 00 18  cmp  %o0, %i0
a0155e84:  04 80 00 0f  ble  0xa0155ec0
a0155e88:  80 a6 00 08  cmp  %i0, %o0
a0155e8c:  b0 22 00 18  sub  %o0, %i0, %i0
a0155e90:  b7 2a a0 1f  sll  %o2, 0x1f, %i3
a0155e94:  83 32 e0 01  srl  %o3, 1, %g1
a0155e98:  ba 16 c0 01  or  %i3, %g1, %i5
a0155e9c:  b9 32 a0 01  srl  %o2, 1, %i4
a0155ea0:  b4 0a a0 00  and  %o2, 0, %i2
a0155ea4:  b6 0a e0 01  and  %o3, 1, %i3
a0155ea8:  94 16 80 1c  or  %i2, %i4, %o2
a0155eac:  b0 86 3f ff  addcc  %i0, -1, %i0
a0155eb0:  12 bf ff f8  bne  0xa0155e90
a0155eb4:  96 16 c0 1d  or  %i3, %i5, %o3
a0155eb8:  b0 10 00 08  mov  %o0, %i0
a0155ebc:  80 a6 00 08  cmp  %i0, %o0
a0155ec0:  24 80 00 0f  ble,a   0xa0155efc
a0155ec4:  f8 03 e0 04  ld  [ %o7 + 4 ], %i4
a0155ec8:  90 26 00 08  sub  %i0, %o0, %o0
a0155ecc:  b7 2b 20 1f  sll  %o4, 0x1f, %i3
a0155ed0:  83 33 60 01  srl  %o5, 1, %g1
a0155ed4:  ba 16 c0 01  or  %i3, %g1, %i5
a0155ed8:  b9 33 20 01  srl  %o4, 1, %i4
a0155edc:  b4 0b 20 00  and  %o4, 0, %i2
a0155ee0:  b6 0b 60 01  and  %o5, 1, %i3
a0155ee4:  98 16 80 1c  or  %i2, %i4, %o4
a0155ee8:  90 82 3f ff  addcc  %o0, -1, %o0
a0155eec:  12 bf ff f8  bne  0xa0155ecc
a0155ef0:  9a 16 c0 1d  or  %i3, %i5, %o5
a0155ef4:  90 10 00 18  mov  %i0, %o0
a0155ef8:  f8 03 e0 04  ld  [ %o7 + 4 ], %i4
a0155efc:  c2 06 60 04  ld  [ %i1 + 4 ], %g1
a0155f00:  80 a7 00 01  cmp  %i4, %g1
a0155f04:  02 80 00 59  be  0xa0156068
a0155f08:  80 a7 20 00  cmp  %i4, 0
a0155f0c:  02 80 00 55  be  0xa0156060
a0155f10:  ba a3 40 0b  subcc  %o5, %o3, %i5
a0155f14:  ba a2 c0 0d  subcc  %o3, %o5, %i5
a0155f18:  b8 62 80 0c  subx  %o2, %o4, %i4
a0155f1c:  80 a7 20 00  cmp  %i4, 0
a0155f20:  06 80 00 5c  bl  0xa0156090
a0155f24:  b2 a0 00 1d  subcc  %g0, %i5, %i1
a0155f28:  9e 10 00 08  mov  %o0, %o7
a0155f2c:  b0 10 00 1c  mov  %i4, %i0
a0155f30:  b2 10 00 1d  mov  %i5, %i1
a0155f34:  c0 22 60 04  clr  [ %o1 + 4 ]
a0155f38:  ba 86 7f ff  addcc  %i1, -1, %i5
a0155f3c:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a0155f40:  b8 46 3f ff  addx  %i0, -1, %i4
a0155f44:  82 10 63 ff  or  %g1, 0x3ff, %g1
a0155f48:  9a 10 00 0f  mov  %o7, %o5
a0155f4c:  b4 10 00 18  mov  %i0, %i2
a0155f50:  b6 10 00 19  mov  %i1, %i3
a0155f54:  80 a7 00 01  cmp  %i4, %g1
a0155f58:  18 80 00 24  bgu  0xa0155fe8
a0155f5c:  80 a7 00 01  cmp  %i4, %g1
a0155f60:  22 80 00 20  be,a   0xa0155fe0
a0155f64:  80 a7 7f fe  cmp  %i5, -2
a0155f68:  b7 36 60 1f  srl  %i1, 0x1f, %i3
a0155f6c:  82 06 00 18  add  %i0, %i0, %g1
a0155f70:  ba 06 40 19  add  %i1, %i1, %i5
a0155f74:  b8 16 c0 01  or  %i3, %g1, %i4
a0155f78:  b2 10 00 1d  mov  %i5, %i1
a0155f7c:  b0 10 00 1c  mov  %i4, %i0
a0155f80:  ba 87 7f ff  addcc  %i5, -1, %i5
a0155f84:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a0155f88:  b8 47 3f ff  addx  %i4, -1, %i4
a0155f8c:  82 10 63 ff  or  %g1, 0x3ff, %g1
a0155f90:  9e 03 ff ff  add  %o7, -1, %o7
a0155f94:  80 a7 00 01  cmp  %i4, %g1
a0155f98:  b4 10 00 18  mov  %i0, %i2
a0155f9c:  b6 10 00 19  mov  %i1, %i3
a0155fa0:  10 bf ff ee  b  0xa0155f58
a0155fa4:  9a 10 00 0f  mov  %o7, %o5
a0155fa8:  12 80 00 3f  bne  0xa01560a4
a0155fac:  b0 10 00 0f  mov  %o7, %i0
a0155fb0:  f8 1b c0 00  ldd  [ %o7 ], %i4
a0155fb4:  f8 3e 80 00  std  %i4, [ %i2 ]
a0155fb8:  f4 1b e0 08  ldd  [ %o7 + 8 ], %i2
a0155fbc:  f4 3a 60 08  std  %i2, [ %o1 + 8 ]
a0155fc0:  f8 1b e0 10  ldd  [ %o7 + 0x10 ], %i4
a0155fc4:  f8 3a 60 10  std  %i4, [ %o1 + 0x10 ]
a0155fc8:  c2 03 e0 04  ld  [ %o7 + 4 ], %g1
a0155fcc:  fa 06 60 04  ld  [ %i1 + 4 ], %i5
a0155fd0:  82 08 40 1d  and  %g1, %i5, %g1
a0155fd4:  c2 22 60 04  st  %g1, [ %o1 + 4 ]
a0155fd8:  10 80 00 33  b  0xa01560a4
a0155fdc:  b0 10 00 09  mov  %o1, %i0
a0155fe0:  28 bf ff e3  bleu,a   0xa0155f6c
a0155fe4:  b7 36 60 1f  srl  %i1, 0x1f, %i3
a0155fe8:  f4 3a 60 10  std  %i2, [ %o1 + 0x10 ]
a0155fec:  3b 07 ff ff  sethi  %hi(0x1ffffc00), %i5
a0155ff0:  c2 02 60 10  ld  [ %o1 + 0x10 ], %g1
a0155ff4:  ba 17 63 ff  or  %i5, 0x3ff, %i5
a0155ff8:  b8 10 20 03  mov  3, %i4
a0155ffc:  80 a0 40 1d  cmp  %g1, %i5
a0156000:  18 80 00 0b  bgu  0xa015602c
a0156004:  f8 22 40 00  st  %i4, [ %o1 ]
a0156008:  da 22 60 08  st  %o5, [ %o1 + 8 ]
a015600c:  10 80 00 26  b  0xa01560a4
a0156010:  b0 10 00 09  mov  %o1, %i0
a0156014:  80 a2 00 18  cmp  %o0, %i0
a0156018:  24 80 00 1b  ble,a   0xa0156084
a015601c:  90 10 00 18  mov  %i0, %o0
a0156020:  94 10 20 00  clr  %o2
a0156024:  10 bf ff b5  b  0xa0155ef8
a0156028:  96 10 20 00  clr  %o3
a015602c:  b7 2e 20 1f  sll  %i0, 0x1f, %i3
a0156030:  83 36 60 01  srl  %i1, 1, %g1
a0156034:  ba 16 c0 01  or  %i3, %g1, %i5
a0156038:  b9 36 20 01  srl  %i0, 1, %i4
a015603c:  b4 0e 20 00  and  %i0, 0, %i2
a0156040:  b6 0e 60 01  and  %i1, 1, %i3
a0156044:  b4 16 80 1c  or  %i2, %i4, %i2
a0156048:  b6 16 c0 1d  or  %i3, %i5, %i3
a015604c:  82 03 e0 01  add  %o7, 1, %g1
a0156050:  f4 3a 60 10  std  %i2, [ %o1 + 0x10 ]
a0156054:  c2 22 60 08  st  %g1, [ %o1 + 8 ]
a0156058:  10 80 00 13  b  0xa01560a4
a015605c:  b0 10 00 09  mov  %o1, %i0
a0156060:  10 bf ff af  b  0xa0155f1c
a0156064:  b8 63 00 0a  subx  %o4, %o2, %i4
a0156068:  b2 83 40 0b  addcc  %o5, %o3, %i1
a015606c:  b0 43 00 0a  addx  %o4, %o2, %i0
a0156070:  9e 10 00 08  mov  %o0, %o7
a0156074:  f8 22 60 04  st  %i4, [ %o1 + 4 ]
a0156078:  f0 3a 60 10  std  %i0, [ %o1 + 0x10 ]
a015607c:  10 bf ff dc  b  0xa0155fec
a0156080:  9a 10 00 08  mov  %o0, %o5
a0156084:  98 10 20 00  clr  %o4
a0156088:  10 bf ff 9c  b  0xa0155ef8
a015608c:  9a 10 20 00  clr  %o5
a0156090:  82 10 20 01  mov  1, %g1
a0156094:  b0 60 00 1c  subx  %g0, %i4, %i0
a0156098:  9e 10 00 08  mov  %o0, %o7
a015609c:  10 bf ff a7  b  0xa0155f38
a01560a0:  c2 22 60 04  st  %g1, [ %o1 + 4 ]
a01560a4:  81 c7 e0 08  ret
a01560a8:  81 e8 00 00  restore
