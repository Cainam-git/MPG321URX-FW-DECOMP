# leon2m FUN_a00c3f54 0xa00c3f54-0xa00c4144 (496 bytes)
a00c3f54:  9d e3 bf 98  save  %sp, -104, %sp
a00c3f58:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c3f5c:  80 a4 20 02  cmp  %l0, 2
a00c3f60:  02 80 00 57  be  0xa00c40bc
a00c3f64:  80 a4 20 03  cmp  %l0, 3
a00c3f68:  02 80 00 58  be  0xa00c40c8
a00c3f6c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c3f70:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c3f74:  94 08 60 ff  and  %g1, 0xff, %o2
a00c3f78:  98 02 bf d0  add  %o2, -48, %o4
a00c3f7c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c3f80:  80 a3 60 02  cmp  %o5, 2
a00c3f84:  18 80 00 6e  bgu  0xa00c413c
a00c3f88:  b0 10 20 ff  mov  0xff, %i0
a00c3f8c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c3f90:  82 13 e2 90  or  %o7, 0x290, %g1	! 0xa802d290
a00c3f94:  d6 08 60 1f  ldub  [ %g1 + 0x1f ], %o3
a00c3f98:  80 a2 e0 00  cmp  %o3, 0
a00c3f9c:  02 80 00 68  be  0xa00c413c
a00c3fa0:  01 00 00 00  nop
a00c3fa4:  40 00 58 ac  call  0xa00da254
a00c3fa8:  d8 28 60 2f  stb  %o4, [ %g1 + 0x2f ]
a00c3fac:  7f ff d2 48  call  0xa00b88cc
a00c3fb0:  01 00 00 00  nop
a00c3fb4:  80 a4 20 02  cmp  %l0, 2
a00c3fb8:  02 80 00 24  be  0xa00c4048
a00c3fbc:  80 a4 20 03  cmp  %l0, 3
a00c3fc0:  02 80 00 45  be  0xa00c40d4
a00c3fc4:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c3fc8:  94 12 e0 78  or  %o3, 0x78, %o2	! 0xa802d078
a00c3fcc:  90 10 20 30  mov  0x30, %o0
a00c3fd0:  98 10 20 35  mov  0x35, %o4
a00c3fd4:  9e 10 20 36  mov  0x36, %o7
a00c3fd8:  9a 10 20 2b  mov  0x2b, %o5
a00c3fdc:  92 10 20 0d  mov  0xd, %o1
a00c3fe0:  d8 2a e0 78  stb  %o4, [ %o3 + 0x78 ]
a00c3fe4:  de 2a a0 01  stb  %o7, [ %o2 + 1 ]
a00c3fe8:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00c3fec:  da 2a a0 04  stb  %o5, [ %o2 + 4 ]
a00c3ff0:  d2 2a a0 05  stb  %o1, [ %o2 + 5 ]
a00c3ff4:  80 a4 20 02  cmp  %l0, 2
a00c3ff8:  02 80 00 21  be  0xa00c407c
a00c3ffc:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00c4000:  80 a4 20 03  cmp  %l0, 3
a00c4004:  02 80 00 41  be  0xa00c4108
a00c4008:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c400c:  9a 13 e0 d0  or  %o7, 0xd0, %o5	! 0xa802d0d0
a00c4010:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c4014:  c0 2a e0 9c  clrb  [ %o3 + 0x9c ]	! 0xa802b09c
a00c4018:  c0 2b e0 d0  clrb  [ %o7 + 0xd0 ]
a00c401c:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00c4020:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00c4024:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00c4028:  80 a4 20 02  cmp  %l0, 2
a00c402c:  02 80 00 1d  be  0xa00c40a0
a00c4030:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00c4034:  80 a4 20 03  cmp  %l0, 3
a00c4038:  12 80 00 1d  bne  0xa00c40ac
a00c403c:  90 10 00 10  mov  %l0, %o0
a00c4040:  10 80 00 3c  b  0xa00c4130
a00c4044:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c4048:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c404c:  98 12 61 28  or  %o1, 0x128, %o4	! 0xa802d128
a00c4050:  a0 10 20 30  mov  0x30, %l0
a00c4054:  9a 10 20 35  mov  0x35, %o5
a00c4058:  90 10 20 0d  mov  0xd, %o0
a00c405c:  82 10 20 36  mov  0x36, %g1
a00c4060:  b0 10 20 2b  mov  0x2b, %i0
a00c4064:  da 2a 61 28  stb  %o5, [ %o1 + 0x128 ]
a00c4068:  d0 2b 20 05  stb  %o0, [ %o4 + 5 ]
a00c406c:  c2 2b 20 01  stb  %g1, [ %o4 + 1 ]
a00c4070:  e0 2b 20 03  stb  %l0, [ %o4 + 3 ]
a00c4074:  f0 2b 20 04  stb  %i0, [ %o4 + 4 ]
a00c4078:  e0 2b 20 02  stb  %l0, [ %o4 + 2 ]
a00c407c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c4080:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c4084:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00c4088:  c0 2e 20 9a  clrb  [ %i0 + 0x9a ]	! 0xa802b09a
a00c408c:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c4090:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c4094:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c4098:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c409c:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c40a0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c40a4:  94 13 21 28  or  %o4, 0x128, %o2	! 0xa802d128
a00c40a8:  90 10 20 02  mov  2, %o0
a00c40ac:  40 02 11 cf  call  0xa01487e8
a00c40b0:  92 10 20 06  mov  6, %o1
a00c40b4:  10 80 00 22  b  0xa00c413c
a00c40b8:  b0 10 20 00  clr  %i0
a00c40bc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c40c0:  10 bf ff ad  b  0xa00c3f74
a00c40c4:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c40c8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c40cc:  10 bf ff aa  b  0xa00c3f74
a00c40d0:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c40d4:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c40d8:  9e 16 21 08  or  %i0, 0x108, %o7	! 0xa802d108
a00c40dc:  94 10 20 30  mov  0x30, %o2
a00c40e0:  82 10 20 35  mov  0x35, %g1
a00c40e4:  a0 10 20 0d  mov  0xd, %l0
a00c40e8:  98 10 20 36  mov  0x36, %o4
a00c40ec:  96 10 20 2b  mov  0x2b, %o3
a00c40f0:  c2 2e 21 08  stb  %g1, [ %i0 + 0x108 ]
a00c40f4:  e0 2b e0 05  stb  %l0, [ %o7 + 5 ]
a00c40f8:  d8 2b e0 01  stb  %o4, [ %o7 + 1 ]
a00c40fc:  d4 2b e0 03  stb  %o2, [ %o7 + 3 ]
a00c4100:  d6 2b e0 04  stb  %o3, [ %o7 + 4 ]
a00c4104:  d4 2b e0 02  stb  %o2, [ %o7 + 2 ]
a00c4108:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c410c:  90 12 60 98  or  %o1, 0x98, %o0	! 0xa802d098
a00c4110:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c4114:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c4118:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]
a00c411c:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c4120:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c4124:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c4128:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c412c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c4130:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c4134:  10 bf ff de  b  0xa00c40ac
a00c4138:  90 10 20 03  mov  3, %o0
a00c413c:  81 c7 e0 08  ret
a00c4140:  81 e8 00 00  restore
