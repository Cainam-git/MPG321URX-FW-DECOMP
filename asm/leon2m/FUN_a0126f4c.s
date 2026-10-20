# leon2m FUN_a0126f4c 0xa0126f4c-0xa0127154 (520 bytes)
a0126f4c:  9d e3 bf 90  save  %sp, -112, %sp
a0126f50:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a0126f54:  98 14 22 90  or  %l0, 0x290, %o4	! 0xa802d290
a0126f58:  da 03 21 dc  ld  [ %o4 + 0x1dc ], %o5
a0126f5c:  03 00 00 20  sethi  %hi(0x8000), %g1
a0126f60:  80 8b 40 01  btst  %o5, %g1
a0126f64:  32 80 00 0c  bne,a   0xa0126f94
a0126f68:  ea 0b 21 e1  ldub  [ %o4 + 0x1e1 ], %l5
a0126f6c:  2f 2a 00 b6  sethi  %hi(0xa802d800), %l7
a0126f70:  90 15 e0 90  or  %l7, 0x90, %o0	! 0xa802d890
a0126f74:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a0126f78:  7f ff f6 54  call  0xa01248c8
a0126f7c:  c0 2d e0 90  clrb  [ %l7 + 0x90 ]
a0126f80:  80 8a 20 ff  btst  0xff, %o0
a0126f84:  02 80 00 72  be  0xa012714c
a0126f88:  a2 15 e0 90  or  %l7, 0x90, %l1
a0126f8c:  10 80 00 13  b  0xa0126fd8
a0126f90:  19 00 06 91  sethi  %hi(0x1a4400), %o4
a0126f94:  a6 10 20 01  mov  1, %l3
a0126f98:  e8 0b 21 e0  ldub  [ %o4 + 0x1e0 ], %l4
a0126f9c:  a4 24 c0 15  sub  %l3, %l5, %l2
a0126fa0:  9e 24 c0 14  sub  %l3, %l4, %o7
a0126fa4:  d4 0b 21 df  ldub  [ %o4 + 0x1df ], %o2
a0126fa8:  2f 2a 00 b6  sethi  %hi(0xa802d800), %l7
a0126fac:  a3 2c a0 04  sll  %l2, 4, %l1
a0126fb0:  96 13 c0 11  or  %o7, %l1, %o3
a0126fb4:  98 02 a0 01  add  %o2, 1, %o4
a0126fb8:  92 15 e0 90  or  %l7, 0x90, %o1
a0126fbc:  d8 2a 60 01  stb  %o4, [ %o1 + 1 ]
a0126fc0:  7f ff f6 42  call  0xa01248c8
a0126fc4:  d6 2d e0 90  stb  %o3, [ %l7 + 0x90 ]
a0126fc8:  80 8a 20 ff  btst  0xff, %o0
a0126fcc:  02 80 00 60  be  0xa012714c
a0126fd0:  a2 15 e0 90  or  %l7, 0x90, %l1
a0126fd4:  19 00 06 91  sethi  %hi(0x1a4400), %o4
a0126fd8:  d4 0c 60 01  ldub  [ %l1 + 1 ], %o2
a0126fdc:  90 13 23 80  or  %o4, 0x380, %o0
a0126fe0:  7f fe e0 64  call  0xa00df170
a0126fe4:  d2 0d e0 90  ldub  [ %l7 + 0x90 ], %o1
a0126fe8:  9a 14 22 90  or  %l0, 0x290, %o5
a0126fec:  d2 03 61 dc  ld  [ %o5 + 0x1dc ], %o1
a0126ff0:  97 32 60 0f  srl  %o1, 0xf, %o3
a0126ff4:  92 0a e0 01  and  %o3, 1, %o1
a0126ff8:  11 00 06 91  sethi  %hi(0x1a4400), %o0
a0126ffc:  d8 0b 61 e1  ldub  [ %o5 + 0x1e1 ], %o4
a0127000:  d4 0b 61 e0  ldub  [ %o5 + 0x1e0 ], %o2
a0127004:  d6 0b 61 df  ldub  [ %o5 + 0x1df ], %o3
a0127008:  7f fe e0 5a  call  0xa00df170
a012700c:  90 12 23 b0  or  %o0, 0x3b0, %o0
a0127010:  a4 10 20 02  mov  2, %l2
a0127014:  ac 10 20 01  mov  1, %l6
a0127018:  9a 10 00 11  mov  %l1, %o5
a012701c:  92 10 20 02  mov  2, %o1
a0127020:  94 10 20 60  mov  0x60, %o2
a0127024:  96 10 20 05  mov  5, %o3
a0127028:  98 10 20 00  clr  %o4
a012702c:  ec 23 a0 60  st  %l6, [ %sp + 0x60 ]
a0127030:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a0127034:  40 00 82 9b  call  0xa0147aa0
a0127038:  90 10 20 60  mov  0x60, %o0
a012703c:  67 fd 98 59  call  0x4008d1a0
a0127040:  90 10 20 32  mov  0x32, %o0
a0127044:  2d 2a 00 b6  sethi  %hi(0xa802d800), %l6
a0127048:  96 10 20 05  mov  5, %o3
a012704c:  98 10 20 00  clr  %o4
a0127050:  9a 15 a0 88  or  %l6, 0x88, %o5
a0127054:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a0127058:  92 10 20 02  mov  2, %o1
a012705c:  94 10 20 60  mov  0x60, %o2
a0127060:  40 00 82 a2  call  0xa0147ae8
a0127064:  90 10 20 60  mov  0x60, %o0
a0127068:  03 00 06 91  sethi  %hi(0x1a4400), %g1
a012706c:  a0 15 a0 88  or  %l6, 0x88, %l0
a0127070:  90 10 63 c0  or  %g1, 0x3c0, %o0
a0127074:  d2 0d a0 88  ldub  [ %l6 + 0x88 ], %o1
a0127078:  7f fe e0 3e  call  0xa00df170
a012707c:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a0127080:  90 10 20 32  mov  0x32, %o0
a0127084:  67 fd 98 47  call  0x4008d1a0
a0127088:  a6 10 00 11  mov  %l1, %l3
a012708c:  a4 10 00 10  mov  %l0, %l2
a0127090:  2b 2a 00 b6  sethi  %hi(0xa802d800), %l5
a0127094:  a8 10 00 16  mov  %l6, %l4
a0127098:  10 80 00 1f  b  0xa0127114
a012709c:  a2 10 20 02  mov  2, %l1
a01270a0:  c2 0c 21 fd  ldub  [ %l0 + 0x1fd ], %g1
a01270a4:  80 a0 60 09  cmp  %g1, 9
a01270a8:  18 80 00 29  bgu  0xa012714c
a01270ac:  d2 0d 60 90  ldub  [ %l5 + 0x90 ], %o1
a01270b0:  7f fe e0 30  call  0xa00df170
a01270b4:  d6 0d 20 88  ldub  [ %l4 + 0x88 ], %o3
a01270b8:  82 10 20 01  mov  1, %g1
a01270bc:  c2 23 a0 60  st  %g1, [ %sp + 0x60 ]
a01270c0:  92 10 20 02  mov  2, %o1
a01270c4:  94 10 20 60  mov  0x60, %o2
a01270c8:  96 10 20 05  mov  5, %o3
a01270cc:  98 10 20 00  clr  %o4
a01270d0:  9a 10 00 13  mov  %l3, %o5
a01270d4:  e2 23 a0 5c  st  %l1, [ %sp + 0x5c ]
a01270d8:  40 00 82 72  call  0xa0147aa0
a01270dc:  90 10 20 60  mov  0x60, %o0
a01270e0:  67 fd 98 30  call  0x4008d1a0
a01270e4:  90 10 20 32  mov  0x32, %o0
a01270e8:  94 10 20 60  mov  0x60, %o2
a01270ec:  e2 23 a0 5c  st  %l1, [ %sp + 0x5c ]
a01270f0:  90 10 20 60  mov  0x60, %o0
a01270f4:  92 10 20 02  mov  2, %o1
a01270f8:  96 10 20 05  mov  5, %o3
a01270fc:  98 10 20 00  clr  %o4
a0127100:  40 00 82 7a  call  0xa0147ae8
a0127104:  9a 10 00 12  mov  %l2, %o5
a0127108:  de 0c 21 fd  ldub  [ %l0 + 0x1fd ], %o7
a012710c:  94 03 e0 01  add  %o7, 1, %o2
a0127110:  d4 2c 21 fd  stb  %o2, [ %l0 + 0x1fd ]
a0127114:  21 00 06 91  sethi  %hi(0x1a4400), %l0
a0127118:  da 0c e0 01  ldub  [ %l3 + 1 ], %o5
a012711c:  d6 0c a0 01  ldub  [ %l2 + 1 ], %o3
a0127120:  90 14 22 d0  or  %l0, 0x2d0, %o0
a0127124:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a0127128:  94 10 00 0d  mov  %o5, %o2
a012712c:  80 a3 40 0b  cmp  %o5, %o3
a0127130:  12 bf ff dc  bne  0xa01270a0
a0127134:  98 10 00 0b  mov  %o3, %o4
a0127138:  de 0d e0 90  ldub  [ %l7 + 0x90 ], %o7
a012713c:  d2 0d a0 88  ldub  [ %l6 + 0x88 ], %o1
a0127140:  80 a3 c0 09  cmp  %o7, %o1
a0127144:  12 bf ff d8  bne  0xa01270a4
a0127148:  c2 0c 21 fd  ldub  [ %l0 + 0x1fd ], %g1
a012714c:  81 c7 e0 08  ret
a0127150:  81 e8 00 00  restore
