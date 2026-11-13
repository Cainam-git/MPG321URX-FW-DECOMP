# leon2m FUN_a00c9f44 0xa00c9f44-0xa00ca158 (532 bytes)
a00c9f44:  9d e3 bf 98  save  %sp, -104, %sp
a00c9f48:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c9f4c:  80 a4 20 02  cmp  %l0, 2
a00c9f50:  02 80 00 5c  be  0xa00ca0c0
a00c9f54:  80 a4 20 03  cmp  %l0, 3
a00c9f58:  02 80 00 61  be  0xa00ca0dc
a00c9f5c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c9f60:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c9f64:  96 08 60 ff  and  %g1, 0xff, %o3
a00c9f68:  94 02 ff d0  add  %o3, -48, %o2
a00c9f6c:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00c9f70:  80 a3 60 01  cmp  %o5, 1
a00c9f74:  18 80 00 77  bgu  0xa00ca150
a00c9f78:  b0 10 20 ff  mov  0xff, %i0
a00c9f7c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c9f80:  96 12 22 90  or  %o0, 0x290, %o3	! 0xa802d290
a00c9f84:  c2 02 e1 f4  ld  [ %o3 + 0x1f4 ], %g1
a00c9f88:  31 20 00 00  sethi  %hi(0x80000000), %i0
a00c9f8c:  9e 28 40 18  andn  %g1, %i0, %o7
a00c9f90:  9b 2b 60 1f  sll  %o5, 0x1f, %o5
a00c9f94:  82 13 c0 0d  or  %o7, %o5, %g1
a00c9f98:  d8 0a e1 a4  ldub  [ %o3 + 0x1a4 ], %o4
a00c9f9c:  80 a3 20 03  cmp  %o4, 3
a00c9fa0:  02 80 00 4b  be  0xa00ca0cc
a00c9fa4:  c2 22 e1 f4  st  %g1, [ %o3 + 0x1f4 ]
a00c9fa8:  40 00 40 0d  call  0xa00d9fdc
a00c9fac:  90 10 20 02  mov  2, %o0
a00c9fb0:  7f ff ba 47  call  0xa00b88cc
a00c9fb4:  01 00 00 00  nop
a00c9fb8:  80 a4 20 02  cmp  %l0, 2
a00c9fbc:  02 80 00 24  be  0xa00ca04c
a00c9fc0:  80 a4 20 03  cmp  %l0, 3
a00c9fc4:  02 80 00 49  be  0xa00ca0e8
a00c9fc8:  9e 10 20 30  mov  0x30, %o7
a00c9fcc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c9fd0:  94 12 20 78  or  %o0, 0x78, %o2	! 0xa802d078
a00c9fd4:  82 10 20 35  mov  0x35, %g1
a00c9fd8:  b0 10 20 36  mov  0x36, %i0
a00c9fdc:  9a 10 20 2b  mov  0x2b, %o5
a00c9fe0:  98 10 20 0d  mov  0xd, %o4
a00c9fe4:  c2 2a 20 78  stb  %g1, [ %o0 + 0x78 ]
a00c9fe8:  f0 2a a0 01  stb  %i0, [ %o2 + 1 ]
a00c9fec:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00c9ff0:  da 2a a0 04  stb  %o5, [ %o2 + 4 ]
a00c9ff4:  d8 2a a0 05  stb  %o4, [ %o2 + 5 ]
a00c9ff8:  80 a4 20 02  cmp  %l0, 2
a00c9ffc:  02 80 00 21  be  0xa00ca080
a00ca000:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00ca004:  80 a4 20 03  cmp  %l0, 3
a00ca008:  02 80 00 45  be  0xa00ca11c
a00ca00c:  80 a4 20 02  cmp  %l0, 2
a00ca010:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00ca014:  9a 16 20 d0  or  %i0, 0xd0, %o5	! 0xa802d0d0
a00ca018:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00ca01c:  c0 2a 20 9c  clrb  [ %o0 + 0x9c ]	! 0xa802b09c
a00ca020:  c0 2e 20 d0  clrb  [ %i0 + 0xd0 ]
a00ca024:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00ca028:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00ca02c:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00ca030:  02 80 00 1d  be  0xa00ca0a4
a00ca034:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00ca038:  80 a4 20 03  cmp  %l0, 3
a00ca03c:  12 80 00 1d  bne  0xa00ca0b0
a00ca040:  90 10 00 10  mov  %l0, %o0
a00ca044:  10 80 00 40  b  0xa00ca144
a00ca048:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00ca04c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00ca050:  a0 13 e1 28  or  %o7, 0x128, %l0	! 0xa802d128
a00ca054:  92 10 20 30  mov  0x30, %o1
a00ca058:  9a 10 20 35  mov  0x35, %o5
a00ca05c:  98 10 20 0d  mov  0xd, %o4
a00ca060:  96 10 20 36  mov  0x36, %o3
a00ca064:  94 10 20 2b  mov  0x2b, %o2
a00ca068:  da 2b e1 28  stb  %o5, [ %o7 + 0x128 ]
a00ca06c:  d8 2c 20 05  stb  %o4, [ %l0 + 5 ]
a00ca070:  d6 2c 20 01  stb  %o3, [ %l0 + 1 ]
a00ca074:  d2 2c 20 03  stb  %o1, [ %l0 + 3 ]
a00ca078:  d4 2c 20 04  stb  %o2, [ %l0 + 4 ]
a00ca07c:  d2 2c 20 02  stb  %o1, [ %l0 + 2 ]
a00ca080:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ca084:  a0 12 60 40  or  %o1, 0x40, %l0	! 0xa802d040
a00ca088:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00ca08c:  c0 2a a0 9a  clrb  [ %o2 + 0x9a ]	! 0xa802b09a
a00ca090:  c0 2a 60 40  clrb  [ %o1 + 0x40 ]
a00ca094:  c0 2c 20 19  clrb  [ %l0 + 0x19 ]
a00ca098:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a00ca09c:  c0 2c 20 07  clrb  [ %l0 + 7 ]
a00ca0a0:  c0 2c 20 0a  clrb  [ %l0 + 0xa ]
a00ca0a4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ca0a8:  94 10 61 28  or  %g1, 0x128, %o2	! 0xa802d128
a00ca0ac:  90 10 20 02  mov  2, %o0
a00ca0b0:  40 01 f9 ce  call  0xa01487e8
a00ca0b4:  92 10 20 06  mov  6, %o1
a00ca0b8:  10 80 00 26  b  0xa00ca150
a00ca0bc:  b0 10 20 00  clr  %i0
a00ca0c0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ca0c4:  10 bf ff a8  b  0xa00c9f64
a00ca0c8:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00ca0cc:  80 a0 60 00  cmp  %g1, 0
a00ca0d0:  26 bf ff b6  bl,a   0xa00c9fa8
a00ca0d4:  c0 2a e1 a4  clrb  [ %o3 + 0x1a4 ]
a00ca0d8:  30 bf ff b4  b,a   0xa00c9fa8
a00ca0dc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ca0e0:  10 bf ff a1  b  0xa00c9f64
a00ca0e4:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00ca0e8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ca0ec:  b0 12 a1 08  or  %o2, 0x108, %i0	! 0xa802d108
a00ca0f0:  90 10 20 30  mov  0x30, %o0
a00ca0f4:  96 10 20 35  mov  0x35, %o3
a00ca0f8:  92 10 20 0d  mov  0xd, %o1
a00ca0fc:  a0 10 20 36  mov  0x36, %l0
a00ca100:  82 10 20 2b  mov  0x2b, %g1
a00ca104:  d6 2a a1 08  stb  %o3, [ %o2 + 0x108 ]
a00ca108:  d2 2e 20 05  stb  %o1, [ %i0 + 5 ]
a00ca10c:  e0 2e 20 01  stb  %l0, [ %i0 + 1 ]
a00ca110:  d0 2e 20 03  stb  %o0, [ %i0 + 3 ]
a00ca114:  c2 2e 20 04  stb  %g1, [ %i0 + 4 ]
a00ca118:  d0 2e 20 02  stb  %o0, [ %i0 + 2 ]
a00ca11c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00ca120:  96 13 e0 98  or  %o7, 0x98, %o3	! 0xa802d098
a00ca124:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00ca128:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]	! 0xa802b098
a00ca12c:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]
a00ca130:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00ca134:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00ca138:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00ca13c:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00ca140:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00ca144:  94 14 21 08  or  %l0, 0x108, %o2	! 0xa802d108
a00ca148:  10 bf ff da  b  0xa00ca0b0
a00ca14c:  90 10 20 03  mov  3, %o0
a00ca150:  81 c7 e0 08  ret
a00ca154:  81 e8 00 00  restore
