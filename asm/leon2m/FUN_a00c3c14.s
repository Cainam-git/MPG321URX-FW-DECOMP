# leon2m FUN_a00c3c14 0xa00c3c14-0xa00c3e3c (552 bytes)
a00c3c14:  9d e3 bf 98  save  %sp, -104, %sp
a00c3c18:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c3c1c:  80 a6 20 02  cmp  %i0, 2
a00c3c20:  02 80 00 48  be  0xa00c3d40
a00c3c24:  80 a6 20 03  cmp  %i0, 3
a00c3c28:  02 80 00 49  be  0xa00c3d4c
a00c3c2c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c3c30:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c3c34:  94 08 60 ff  and  %g1, 0xff, %o2
a00c3c38:  a0 02 bf d0  add  %o2, -48, %l0
a00c3c3c:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00c3c40:  80 a3 60 02  cmp  %o5, 2
a00c3c44:  38 80 00 7c  bgu,a   0xa00c3e34
a00c3c48:  b0 10 20 ff  mov  0xff, %i0
a00c3c4c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c3c50:  9a 14 62 90  or  %l1, 0x290, %o5	! 0xa802d290
a00c3c54:  d6 0b 60 1f  ldub  [ %o5 + 0x1f ], %o3
a00c3c58:  80 a2 e0 00  cmp  %o3, 0
a00c3c5c:  32 80 00 76  bne,a   0xa00c3e34
a00c3c60:  b0 10 20 ff  mov  0xff, %i0
a00c3c64:  d8 03 60 b0  ld  [ %o5 + 0xb0 ], %o4
a00c3c68:  80 a3 20 00  cmp  %o4, 0
a00c3c6c:  02 80 00 09  be  0xa00c3c90
a00c3c70:  9e 14 62 90  or  %l1, 0x290, %o7
a00c3c74:  40 00 50 35  call  0xa00d7d48
a00c3c78:  01 00 00 00  nop
a00c3c7c:  80 a2 20 00  cmp  %o0, 0
a00c3c80:  12 80 00 04  bne  0xa00c3c90
a00c3c84:  9e 14 62 90  or  %l1, 0x290, %o7
a00c3c88:  10 80 00 6b  b  0xa00c3e34
a00c3c8c:  b0 10 20 ff  mov  0xff, %i0
a00c3c90:  e0 2b e0 19  stb  %l0, [ %o7 + 0x19 ]
a00c3c94:  40 00 53 e2  call  0xa00d8c1c
a00c3c98:  01 00 00 00  nop
a00c3c9c:  40 00 43 3f  call  0xa00d4998
a00c3ca0:  01 00 00 00  nop
a00c3ca4:  7f ff d3 0a  call  0xa00b88cc
a00c3ca8:  01 00 00 00  nop
a00c3cac:  80 a6 20 02  cmp  %i0, 2
a00c3cb0:  02 80 00 47  be  0xa00c3dcc
a00c3cb4:  80 a6 20 03  cmp  %i0, 3
a00c3cb8:  02 80 00 28  be  0xa00c3d58
a00c3cbc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c3cc0:  94 13 20 78  or  %o4, 0x78, %o2	! 0xa802d078
a00c3cc4:  90 10 20 30  mov  0x30, %o0
a00c3cc8:  96 10 20 35  mov  0x35, %o3
a00c3ccc:  9a 10 20 36  mov  0x36, %o5
a00c3cd0:  92 10 20 2b  mov  0x2b, %o1
a00c3cd4:  82 10 20 0d  mov  0xd, %g1
a00c3cd8:  d6 2b 20 78  stb  %o3, [ %o4 + 0x78 ]
a00c3cdc:  da 2a a0 01  stb  %o5, [ %o2 + 1 ]
a00c3ce0:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00c3ce4:  d2 2a a0 04  stb  %o1, [ %o2 + 4 ]
a00c3ce8:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00c3cec:  80 a6 20 02  cmp  %i0, 2
a00c3cf0:  02 80 00 44  be  0xa00c3e00
a00c3cf4:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00c3cf8:  80 a6 20 03  cmp  %i0, 3
a00c3cfc:  02 80 00 24  be  0xa00c3d8c
a00c3d00:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c3d04:  92 13 60 d0  or  %o5, 0xd0, %o1	! 0xa802d0d0
a00c3d08:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c3d0c:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]	! 0xa802b09c
a00c3d10:  c0 2b 60 d0  clrb  [ %o5 + 0xd0 ]
a00c3d14:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00c3d18:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00c3d1c:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00c3d20:  80 a6 20 02  cmp  %i0, 2
a00c3d24:  02 80 00 40  be  0xa00c3e24
a00c3d28:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00c3d2c:  80 a6 20 03  cmp  %i0, 3
a00c3d30:  12 80 00 23  bne  0xa00c3dbc
a00c3d34:  90 10 00 18  mov  %i0, %o0
a00c3d38:  10 80 00 1f  b  0xa00c3db4
a00c3d3c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c3d40:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c3d44:  10 bf ff bc  b  0xa00c3c34
a00c3d48:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c3d4c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c3d50:  10 bf ff b9  b  0xa00c3c34
a00c3d54:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c3d58:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c3d5c:  98 14 61 08  or  %l1, 0x108, %o4	! 0xa802d108
a00c3d60:  94 10 20 30  mov  0x30, %o2
a00c3d64:  b0 10 20 35  mov  0x35, %i0
a00c3d68:  a0 10 20 0d  mov  0xd, %l0
a00c3d6c:  9e 10 20 36  mov  0x36, %o7
a00c3d70:  96 10 20 2b  mov  0x2b, %o3
a00c3d74:  f0 2c 61 08  stb  %i0, [ %l1 + 0x108 ]
a00c3d78:  e0 2b 20 05  stb  %l0, [ %o4 + 5 ]
a00c3d7c:  de 2b 20 01  stb  %o7, [ %o4 + 1 ]
a00c3d80:  d4 2b 20 03  stb  %o2, [ %o4 + 3 ]
a00c3d84:  d6 2b 20 04  stb  %o3, [ %o4 + 4 ]
a00c3d88:  d4 2b 20 02  stb  %o2, [ %o4 + 2 ]
a00c3d8c:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c3d90:  a2 16 20 98  or  %i0, 0x98, %l1	! 0xa802d098
a00c3d94:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00c3d98:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]	! 0xa802b098
a00c3d9c:  c0 2e 20 98  clrb  [ %i0 + 0x98 ]
a00c3da0:  c0 2c 60 19  clrb  [ %l1 + 0x19 ]
a00c3da4:  c0 2c 60 01  clrb  [ %l1 + 1 ]
a00c3da8:  c0 2c 60 07  clrb  [ %l1 + 7 ]
a00c3dac:  c0 2c 60 0a  clrb  [ %l1 + 0xa ]
a00c3db0:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c3db4:  94 12 e1 08  or  %o3, 0x108, %o2	! 0xa802d108
a00c3db8:  90 10 20 03  mov  3, %o0
a00c3dbc:  40 02 12 8b  call  0xa01487e8
a00c3dc0:  92 10 20 06  mov  6, %o1
a00c3dc4:  10 80 00 1c  b  0xa00c3e34
a00c3dc8:  b0 10 20 00  clr  %i0
a00c3dcc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c3dd0:  a0 12 61 28  or  %o1, 0x128, %l0	! 0xa802d128
a00c3dd4:  a2 10 20 30  mov  0x30, %l1
a00c3dd8:  9a 10 20 35  mov  0x35, %o5
a00c3ddc:  90 10 20 0d  mov  0xd, %o0
a00c3de0:  82 10 20 36  mov  0x36, %g1
a00c3de4:  b0 10 20 2b  mov  0x2b, %i0
a00c3de8:  da 2a 61 28  stb  %o5, [ %o1 + 0x128 ]
a00c3dec:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00c3df0:  c2 2c 20 01  stb  %g1, [ %l0 + 1 ]
a00c3df4:  e2 2c 20 03  stb  %l1, [ %l0 + 3 ]
a00c3df8:  f0 2c 20 04  stb  %i0, [ %l0 + 4 ]
a00c3dfc:  e2 2c 20 02  stb  %l1, [ %l0 + 2 ]
a00c3e00:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c3e04:  94 13 e0 40  or  %o7, 0x40, %o2	! 0xa802d040
a00c3e08:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00c3e0c:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00c3e10:  c0 2b e0 40  clrb  [ %o7 + 0x40 ]
a00c3e14:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c3e18:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c3e1c:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c3e20:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c3e24:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c3e28:  94 13 21 28  or  %o4, 0x128, %o2	! 0xa802d128
a00c3e2c:  10 bf ff e4  b  0xa00c3dbc
a00c3e30:  90 10 20 02  mov  2, %o0
a00c3e34:  81 c7 e0 08  ret
a00c3e38:  81 e8 00 00  restore
