# leon2m FUN_a00c5e40 0xa00c5e40-0xa00c604c (524 bytes)
a00c5e40:  9d e3 bf 98  save  %sp, -104, %sp
a00c5e44:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c5e48:  80 a4 20 02  cmp  %l0, 2
a00c5e4c:  02 80 00 5e  be  0xa00c5fc4
a00c5e50:  80 a4 20 03  cmp  %l0, 3
a00c5e54:  02 80 00 5f  be  0xa00c5fd0
a00c5e58:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c5e5c:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c5e60:  96 08 60 ff  and  %g1, 0xff, %o3
a00c5e64:  94 02 ff d0  add  %o3, -48, %o2
a00c5e68:  82 0a a0 ff  and  %o2, 0xff, %g1
a00c5e6c:  80 a0 60 04  cmp  %g1, 4
a00c5e70:  18 80 00 75  bgu  0xa00c6044
a00c5e74:  b0 10 20 ff  mov  0xff, %i0
a00c5e78:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c5e7c:  98 12 a2 90  or  %o2, 0x290, %o4	! 0xa802d290
a00c5e80:  90 08 60 0f  and  %g1, 0xf, %o0
a00c5e84:  d2 03 20 34  ld  [ %o4 + 0x34 ], %o1
a00c5e88:  03 00 03 c0  sethi  %hi(0xf0000), %g1
a00c5e8c:  b0 2a 40 01  andn  %o1, %g1, %i0
a00c5e90:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00c5e94:  9e 16 00 0d  or  %i0, %o5, %o7
a00c5e98:  de 23 20 34  st  %o7, [ %o4 + 0x34 ]
a00c5e9c:  40 00 3e 97  call  0xa00d58f8
a00c5ea0:  01 00 00 00  nop
a00c5ea4:  40 00 3e 8d  call  0xa00d58d8
a00c5ea8:  01 00 00 00  nop
a00c5eac:  40 00 3a bb  call  0xa00d4998
a00c5eb0:  01 00 00 00  nop
a00c5eb4:  7f ff ca 86  call  0xa00b88cc
a00c5eb8:  01 00 00 00  nop
a00c5ebc:  80 a4 20 02  cmp  %l0, 2
a00c5ec0:  02 80 00 24  be  0xa00c5f50
a00c5ec4:  80 a4 20 03  cmp  %l0, 3
a00c5ec8:  02 80 00 45  be  0xa00c5fdc
a00c5ecc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c5ed0:  94 13 20 78  or  %o4, 0x78, %o2	! 0xa802d078
a00c5ed4:  b0 10 20 30  mov  0x30, %i0
a00c5ed8:  82 10 20 35  mov  0x35, %g1
a00c5edc:  92 10 20 36  mov  0x36, %o1
a00c5ee0:  90 10 20 2b  mov  0x2b, %o0
a00c5ee4:  9a 10 20 0d  mov  0xd, %o5
a00c5ee8:  c2 2b 20 78  stb  %g1, [ %o4 + 0x78 ]
a00c5eec:  d2 2a a0 01  stb  %o1, [ %o2 + 1 ]
a00c5ef0:  f0 2a a0 03  stb  %i0, [ %o2 + 3 ]
a00c5ef4:  d0 2a a0 04  stb  %o0, [ %o2 + 4 ]
a00c5ef8:  da 2a a0 05  stb  %o5, [ %o2 + 5 ]
a00c5efc:  80 a4 20 02  cmp  %l0, 2
a00c5f00:  02 80 00 21  be  0xa00c5f84
a00c5f04:  f0 2a a0 02  stb  %i0, [ %o2 + 2 ]
a00c5f08:  80 a4 20 03  cmp  %l0, 3
a00c5f0c:  02 80 00 41  be  0xa00c6010
a00c5f10:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c5f14:  90 12 60 d0  or  %o1, 0xd0, %o0	! 0xa802d0d0
a00c5f18:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00c5f1c:  c0 2b 20 9c  clrb  [ %o4 + 0x9c ]	! 0xa802b09c
a00c5f20:  c0 2a 60 d0  clrb  [ %o1 + 0xd0 ]
a00c5f24:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c5f28:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c5f2c:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c5f30:  80 a4 20 02  cmp  %l0, 2
a00c5f34:  02 80 00 1d  be  0xa00c5fa8
a00c5f38:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c5f3c:  80 a4 20 03  cmp  %l0, 3
a00c5f40:  12 80 00 1d  bne  0xa00c5fb4
a00c5f44:  90 10 00 10  mov  %l0, %o0
a00c5f48:  10 80 00 3c  b  0xa00c6038
a00c5f4c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c5f50:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c5f54:  a0 13 61 28  or  %o5, 0x128, %l0	! 0xa802d128
a00c5f58:  98 10 20 30  mov  0x30, %o4
a00c5f5c:  90 10 20 35  mov  0x35, %o0
a00c5f60:  b0 10 20 0d  mov  0xd, %i0
a00c5f64:  9e 10 20 36  mov  0x36, %o7
a00c5f68:  96 10 20 2b  mov  0x2b, %o3
a00c5f6c:  d0 2b 61 28  stb  %o0, [ %o5 + 0x128 ]
a00c5f70:  f0 2c 20 05  stb  %i0, [ %l0 + 5 ]
a00c5f74:  de 2c 20 01  stb  %o7, [ %l0 + 1 ]
a00c5f78:  d8 2c 20 03  stb  %o4, [ %l0 + 3 ]
a00c5f7c:  d6 2c 20 04  stb  %o3, [ %l0 + 4 ]
a00c5f80:  d8 2c 20 02  stb  %o4, [ %l0 + 2 ]
a00c5f84:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c5f88:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c5f8c:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c5f90:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]	! 0xa802b09a
a00c5f94:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c5f98:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c5f9c:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c5fa0:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c5fa4:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c5fa8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c5fac:  94 10 61 28  or  %g1, 0x128, %o2	! 0xa802d128
a00c5fb0:  90 10 20 02  mov  2, %o0
a00c5fb4:  40 02 0a 0d  call  0xa01487e8
a00c5fb8:  92 10 20 06  mov  6, %o1
a00c5fbc:  10 80 00 22  b  0xa00c6044
a00c5fc0:  b0 10 20 00  clr  %i0
a00c5fc4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c5fc8:  10 bf ff a6  b  0xa00c5e60
a00c5fcc:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c5fd0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c5fd4:  10 bf ff a3  b  0xa00c5e60
a00c5fd8:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c5fdc:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c5fe0:  92 12 e1 08  or  %o3, 0x108, %o1	! 0xa802d108
a00c5fe4:  94 10 20 30  mov  0x30, %o2
a00c5fe8:  9e 10 20 35  mov  0x35, %o7
a00c5fec:  98 10 20 0d  mov  0xd, %o4
a00c5ff0:  a0 10 20 36  mov  0x36, %l0
a00c5ff4:  82 10 20 2b  mov  0x2b, %g1
a00c5ff8:  de 2a e1 08  stb  %o7, [ %o3 + 0x108 ]
a00c5ffc:  d8 2a 60 05  stb  %o4, [ %o1 + 5 ]
a00c6000:  e0 2a 60 01  stb  %l0, [ %o1 + 1 ]
a00c6004:  d4 2a 60 03  stb  %o2, [ %o1 + 3 ]
a00c6008:  c2 2a 60 04  stb  %g1, [ %o1 + 4 ]
a00c600c:  d4 2a 60 02  stb  %o2, [ %o1 + 2 ]
a00c6010:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c6014:  9e 16 20 98  or  %i0, 0x98, %o7	! 0xa802d098
a00c6018:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00c601c:  c0 2b 60 98  clrb  [ %o5 + 0x98 ]	! 0xa802b098
a00c6020:  c0 2e 20 98  clrb  [ %i0 + 0x98 ]
a00c6024:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00c6028:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00c602c:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00c6030:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00c6034:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c6038:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c603c:  10 bf ff de  b  0xa00c5fb4
a00c6040:  90 10 20 03  mov  3, %o0
a00c6044:  81 c7 e0 08  ret
a00c6048:  81 e8 00 00  restore
