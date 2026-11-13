# leon2m FUN_a00c0de0 0xa00c0de0-0xa00c0ff4 (532 bytes)
a00c0de0:  9d e3 bf 98  save  %sp, -104, %sp
a00c0de4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0de8:  80 a6 20 02  cmp  %i0, 2
a00c0dec:  02 80 00 63  be  0xa00c0f78
a00c0df0:  80 a6 20 03  cmp  %i0, 3
a00c0df4:  02 80 00 64  be  0xa00c0f84
a00c0df8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c0dfc:  e0 0a 60 d9  ldub  [ %o1 + 0xd9 ], %l0	! 0xa802d0d9
a00c0e00:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00c0e04:  90 10 20 00  clr  %o0
a00c0e08:  40 02 0b 83  call  0xa0143c14
a00c0e0c:  a0 04 3f d0  add  %l0, -48, %l0
a00c0e10:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00c0e14:  80 a4 20 00  cmp  %l0, 0
a00c0e18:  02 80 00 2b  be  0xa00c0ec4
a00c0e1c:  80 8a 20 ff  btst  0xff, %o0
a00c0e20:  80 a4 20 01  cmp  %l0, 1
a00c0e24:  12 80 00 2e  bne  0xa00c0edc
a00c0e28:  80 a6 20 02  cmp  %i0, 2
a00c0e2c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a00c0e30:  d6 03 21 a0  ld  [ %o4 + 0x1a0 ], %o3	! 0xa802e1a0
a00c0e34:  80 a2 e0 00  cmp  %o3, 0
a00c0e38:  06 80 00 6d  bl  0xa00c0fec
a00c0e3c:  82 10 20 ff  mov  0xff, %g1
a00c0e40:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00c0e44:  80 a6 20 02  cmp  %i0, 2
a00c0e48:  12 80 00 27  bne  0xa00c0ee4
a00c0e4c:  e0 2b e0 9b  stb  %l0, [ %o7 + 0x9b ]
a00c0e50:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c0e54:  b0 12 a1 28  or  %o2, 0x128, %i0	! 0xa802d128
a00c0e58:  90 10 20 30  mov  0x30, %o0
a00c0e5c:  9a 10 20 35  mov  0x35, %o5
a00c0e60:  a0 10 20 0d  mov  0xd, %l0
a00c0e64:  92 10 20 36  mov  0x36, %o1
a00c0e68:  82 10 20 2b  mov  0x2b, %g1
a00c0e6c:  da 2a a1 28  stb  %o5, [ %o2 + 0x128 ]
a00c0e70:  e0 2e 20 05  stb  %l0, [ %i0 + 5 ]
a00c0e74:  d2 2e 20 01  stb  %o1, [ %i0 + 1 ]
a00c0e78:  d0 2e 20 03  stb  %o0, [ %i0 + 3 ]
a00c0e7c:  c2 2e 20 04  stb  %g1, [ %i0 + 4 ]
a00c0e80:  d0 2e 20 02  stb  %o0, [ %i0 + 2 ]
a00c0e84:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c0e88:  94 16 20 40  or  %i0, 0x40, %o2	! 0xa802d040
a00c0e8c:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00c0e90:  c0 2a 60 9a  clrb  [ %o1 + 0x9a ]	! 0xa802b09a
a00c0e94:  c0 2e 20 40  clrb  [ %i0 + 0x40 ]
a00c0e98:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c0e9c:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c0ea0:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c0ea4:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c0ea8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c0eac:  94 12 21 28  or  %o0, 0x128, %o2	! 0xa802d128
a00c0eb0:  90 10 20 02  mov  2, %o0
a00c0eb4:  40 02 1e 4d  call  0xa01487e8
a00c0eb8:  92 10 20 06  mov  6, %o1
a00c0ebc:  10 80 00 4c  b  0xa00c0fec
a00c0ec0:  82 10 20 00  clr  %g1
a00c0ec4:  02 80 00 4a  be  0xa00c0fec
a00c0ec8:  82 10 20 ff  mov  0xff, %g1
a00c0ecc:  9a 10 20 01  mov  1, %o5
a00c0ed0:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00c0ed4:  da 2a a0 9b  stb  %o5, [ %o2 + 0x9b ]	! 0xa802b09b
a00c0ed8:  80 a6 20 02  cmp  %i0, 2
a00c0edc:  02 bf ff de  be  0xa00c0e54
a00c0ee0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c0ee4:  80 a6 20 03  cmp  %i0, 3
a00c0ee8:  02 80 00 2a  be  0xa00c0f90
a00c0eec:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c0ef0:  94 12 e0 78  or  %o3, 0x78, %o2	! 0xa802d078
a00c0ef4:  a0 10 20 30  mov  0x30, %l0
a00c0ef8:  90 10 20 35  mov  0x35, %o0
a00c0efc:  9e 10 20 36  mov  0x36, %o7
a00c0f00:  98 10 20 2b  mov  0x2b, %o4
a00c0f04:  9a 10 20 0d  mov  0xd, %o5
a00c0f08:  d0 2a e0 78  stb  %o0, [ %o3 + 0x78 ]
a00c0f0c:  de 2a a0 01  stb  %o7, [ %o2 + 1 ]
a00c0f10:  e0 2a a0 03  stb  %l0, [ %o2 + 3 ]
a00c0f14:  d8 2a a0 04  stb  %o4, [ %o2 + 4 ]
a00c0f18:  da 2a a0 05  stb  %o5, [ %o2 + 5 ]
a00c0f1c:  80 a6 20 02  cmp  %i0, 2
a00c0f20:  02 bf ff d9  be  0xa00c0e84
a00c0f24:  e0 2a a0 02  stb  %l0, [ %o2 + 2 ]
a00c0f28:  80 a6 20 03  cmp  %i0, 3
a00c0f2c:  02 80 00 26  be  0xa00c0fc4
a00c0f30:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c0f34:  9e 13 20 d0  or  %o4, 0xd0, %o7	! 0xa802d0d0
a00c0f38:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c0f3c:  c0 2a e0 9c  clrb  [ %o3 + 0x9c ]	! 0xa802b09c
a00c0f40:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00c0f44:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00c0f48:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00c0f4c:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00c0f50:  80 a6 20 02  cmp  %i0, 2
a00c0f54:  02 bf ff d5  be  0xa00c0ea8
a00c0f58:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00c0f5c:  80 a6 20 03  cmp  %i0, 3
a00c0f60:  12 bf ff d5  bne  0xa00c0eb4
a00c0f64:  90 10 00 18  mov  %i0, %o0
a00c0f68:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c0f6c:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c0f70:  10 bf ff d1  b  0xa00c0eb4
a00c0f74:  90 10 20 03  mov  3, %o0
a00c0f78:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c0f7c:  10 bf ff a1  b  0xa00c0e00
a00c0f80:  e0 08 60 49  ldub  [ %g1 + 0x49 ], %l0	! 0xa802d049
a00c0f84:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c0f88:  10 bf ff 9e  b  0xa00c0e00
a00c0f8c:  e0 0a 20 a1  ldub  [ %o0 + 0xa1 ], %l0	! 0xa802d0a1
a00c0f90:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c0f94:  98 12 61 08  or  %o1, 0x108, %o4	! 0xa802d108
a00c0f98:  9e 10 20 30  mov  0x30, %o7
a00c0f9c:  82 10 20 35  mov  0x35, %g1
a00c0fa0:  90 10 20 0d  mov  0xd, %o0
a00c0fa4:  b0 10 20 36  mov  0x36, %i0
a00c0fa8:  96 10 20 2b  mov  0x2b, %o3
a00c0fac:  c2 2a 61 08  stb  %g1, [ %o1 + 0x108 ]
a00c0fb0:  d0 2b 20 05  stb  %o0, [ %o4 + 5 ]
a00c0fb4:  f0 2b 20 01  stb  %i0, [ %o4 + 1 ]
a00c0fb8:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a00c0fbc:  d6 2b 20 04  stb  %o3, [ %o4 + 4 ]
a00c0fc0:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a00c0fc4:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c0fc8:  a0 13 60 98  or  %o5, 0x98, %l0	! 0xa802d098
a00c0fcc:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c0fd0:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c0fd4:  c0 2b 60 98  clrb  [ %o5 + 0x98 ]
a00c0fd8:  c0 2c 20 19  clrb  [ %l0 + 0x19 ]
a00c0fdc:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a00c0fe0:  c0 2c 20 07  clrb  [ %l0 + 7 ]
a00c0fe4:  10 bf ff e1  b  0xa00c0f68
a00c0fe8:  c0 2c 20 0a  clrb  [ %l0 + 0xa ]
a00c0fec:  81 c7 e0 08  ret
a00c0ff0:  91 e8 00 01  restore  %g0, %g1, %o0
