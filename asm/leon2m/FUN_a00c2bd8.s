# leon2m FUN_a00c2bd8 0xa00c2bd8-0xa00c2f08 (816 bytes)
a00c2bd8:  9d e3 bf 98  save  %sp, -104, %sp
a00c2bdc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c2be0:  80 a6 20 02  cmp  %i0, 2
a00c2be4:  02 80 00 a7  be  0xa00c2e80
a00c2be8:  80 a6 20 03  cmp  %i0, 3
a00c2bec:  02 80 00 a8  be  0xa00c2e8c
a00c2bf0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c2bf4:  c2 0a 60 d8  ldub  [ %o1 + 0xd8 ], %g1	! 0xa802d0d8
a00c2bf8:  80 a6 20 02  cmp  %i0, 2
a00c2bfc:  02 80 00 9e  be  0xa00c2e74
a00c2c00:  9a 10 00 01  mov  %g1, %o5
a00c2c04:  80 a6 20 03  cmp  %i0, 3
a00c2c08:  02 80 00 a4  be  0xa00c2e98
a00c2c0c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c2c10:  c2 0b 20 d9  ldub  [ %o4 + 0xd9 ], %g1	! 0xa802d0d9
a00c2c14:  92 03 7f d0  add  %o5, -48, %o1
a00c2c18:  9a 08 60 ff  and  %g1, 0xff, %o5
a00c2c1c:  9e 0a 60 ff  and  %o1, 0xff, %o7
a00c2c20:  80 a3 e0 63  cmp  %o7, 0x63
a00c2c24:  a0 10 00 0d  mov  %o5, %l0
a00c2c28:  18 80 00 b6  bgu  0xa00c2f00
a00c2c2c:  98 10 20 ff  mov  0xff, %o4
a00c2c30:  a2 03 7f d0  add  %o5, -48, %l1
a00c2c34:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00c2c38:  80 a3 60 63  cmp  %o5, 0x63
a00c2c3c:  18 80 00 b1  bgu  0xa00c2f00
a00c2c40:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c2c44:  82 12 22 90  or  %o0, 0x290, %g1	! 0xa802d290
a00c2c48:  c2 08 61 a0  ldub  [ %g1 + 0x1a0 ], %g1
a00c2c4c:  80 a0 60 04  cmp  %g1, 4
a00c2c50:  18 80 00 ac  bgu  0xa00c2f00
a00c2c54:  80 a0 60 00  cmp  %g1, 0
a00c2c58:  02 80 00 41  be  0xa00c2d5c
a00c2c5c:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a00c2c60:  9e 14 63 f4  or  %l1, 0x3f4, %o7	! 0xa802cff4
a00c2c64:  94 12 22 90  or  %o0, 0x290, %o2
a00c2c68:  d8 0b e0 09  ldub  [ %o7 + 9 ], %o4
a00c2c6c:  d6 0a a1 a0  ldub  [ %o2 + 0x1a0 ], %o3
a00c2c70:  80 a2 c0 0c  cmp  %o3, %o4
a00c2c74:  82 03 3f ff  add  %o4, -1, %g1
a00c2c78:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a00c2c7c:  02 80 00 47  be  0xa00c2d98
a00c2c80:  98 04 3f d0  add  %l0, -48, %o4
a00c2c84:  a0 12 22 90  or  %o0, 0x290, %l0
a00c2c88:  9e 08 60 ff  and  %g1, 0xff, %o7
a00c2c8c:  96 03 c0 10  add  %o7, %l0, %o3
a00c2c90:  d2 2a e1 98  stb  %o1, [ %o3 + 0x198 ]
a00c2c94:  7f ff d7 0e  call  0xa00b88cc
a00c2c98:  d8 2a e1 9c  stb  %o4, [ %o3 + 0x19c ]
a00c2c9c:  94 14 63 f4  or  %l1, 0x3f4, %o2
a00c2ca0:  d0 12 a0 04  lduh  [ %o2 + 4 ], %o0
a00c2ca4:  13 00 00 18  sethi  %hi(0x6000), %o1
a00c2ca8:  80 8a 40 08  btst  %o1, %o0
a00c2cac:  02 80 00 4e  be  0xa00c2de4
a00c2cb0:  80 a6 20 02  cmp  %i0, 2
a00c2cb4:  02 80 00 54  be  0xa00c2e04
a00c2cb8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c2cbc:  80 a6 20 03  cmp  %i0, 3
a00c2cc0:  02 80 00 79  be  0xa00c2ea4
a00c2cc4:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c2cc8:  94 13 e0 78  or  %o7, 0x78, %o2	! 0xa802d078
a00c2ccc:  90 10 20 30  mov  0x30, %o0
a00c2cd0:  96 10 20 35  mov  0x35, %o3
a00c2cd4:  92 10 20 36  mov  0x36, %o1
a00c2cd8:  9a 10 20 2b  mov  0x2b, %o5
a00c2cdc:  82 10 20 0d  mov  0xd, %g1
a00c2ce0:  d6 2b e0 78  stb  %o3, [ %o7 + 0x78 ]
a00c2ce4:  d2 2a a0 01  stb  %o1, [ %o2 + 1 ]
a00c2ce8:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00c2cec:  da 2a a0 04  stb  %o5, [ %o2 + 4 ]
a00c2cf0:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00c2cf4:  80 a6 20 02  cmp  %i0, 2
a00c2cf8:  02 80 00 4f  be  0xa00c2e34
a00c2cfc:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00c2d00:  80 a6 20 03  cmp  %i0, 3
a00c2d04:  02 80 00 75  be  0xa00c2ed8
a00c2d08:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c2d0c:  9a 12 60 d0  or  %o1, 0xd0, %o5	! 0xa802d0d0
a00c2d10:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c2d14:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]	! 0xa802b09c
a00c2d18:  c0 2a 60 d0  clrb  [ %o1 + 0xd0 ]
a00c2d1c:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00c2d20:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00c2d24:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00c2d28:  80 a6 20 02  cmp  %i0, 2
a00c2d2c:  02 80 00 4b  be  0xa00c2e58
a00c2d30:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00c2d34:  80 a6 20 03  cmp  %i0, 3
a00c2d38:  12 80 00 4b  bne  0xa00c2e64
a00c2d3c:  90 10 00 18  mov  %i0, %o0
a00c2d40:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c2d44:  94 12 e1 08  or  %o3, 0x108, %o2	! 0xa802d108
a00c2d48:  90 10 20 03  mov  3, %o0
a00c2d4c:  40 02 16 a7  call  0xa01487e8
a00c2d50:  92 10 20 06  mov  6, %o1
a00c2d54:  10 80 00 6b  b  0xa00c2f00
a00c2d58:  98 10 20 00  clr  %o4
a00c2d5c:  9a 14 63 f4  or  %l1, 0x3f4, %o5
a00c2d60:  d4 0b 60 09  ldub  [ %o5 + 9 ], %o2
a00c2d64:  80 a2 a0 00  cmp  %o2, 0
a00c2d68:  12 bf ff bf  bne  0xa00c2c64
a00c2d6c:  9e 14 63 f4  or  %l1, 0x3f4, %o7
a00c2d70:  96 10 20 01  mov  1, %o3
a00c2d74:  d6 2b 60 09  stb  %o3, [ %o5 + 9 ]
a00c2d78:  94 12 22 90  or  %o0, 0x290, %o2
a00c2d7c:  d8 0b e0 09  ldub  [ %o7 + 9 ], %o4
a00c2d80:  d6 0a a1 a0  ldub  [ %o2 + 0x1a0 ], %o3
a00c2d84:  80 a2 c0 0c  cmp  %o3, %o4
a00c2d88:  82 03 3f ff  add  %o4, -1, %g1
a00c2d8c:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a00c2d90:  12 bf ff bd  bne  0xa00c2c84
a00c2d94:  98 04 3f d0  add  %l0, -48, %o4
a00c2d98:  c2 13 e3 f4  lduh  [ %o7 + 0x3f4 ], %g1
a00c2d9c:  1b 00 00 10  sethi  %hi(0x4000), %o5
a00c2da0:  a0 10 40 0d  or  %g1, %o5, %l0
a00c2da4:  e0 33 e3 f4  sth  %l0, [ %o7 + 0x3f4 ]
a00c2da8:  82 02 ff ff  add  %o3, -1, %g1
a00c2dac:  a0 12 22 90  or  %o0, 0x290, %l0
a00c2db0:  9e 08 60 ff  and  %g1, 0xff, %o7
a00c2db4:  96 03 c0 10  add  %o7, %l0, %o3
a00c2db8:  d2 2a a1 a1  stb  %o1, [ %o2 + 0x1a1 ]
a00c2dbc:  d8 2a a1 a2  stb  %o4, [ %o2 + 0x1a2 ]
a00c2dc0:  d2 2a e1 98  stb  %o1, [ %o3 + 0x198 ]
a00c2dc4:  7f ff d6 c2  call  0xa00b88cc
a00c2dc8:  d8 2a e1 9c  stb  %o4, [ %o3 + 0x19c ]
a00c2dcc:  94 14 63 f4  or  %l1, 0x3f4, %o2
a00c2dd0:  d0 12 a0 04  lduh  [ %o2 + 4 ], %o0
a00c2dd4:  13 00 00 18  sethi  %hi(0x6000), %o1
a00c2dd8:  80 8a 40 08  btst  %o1, %o0
a00c2ddc:  12 bf ff b6  bne  0xa00c2cb4
a00c2de0:  80 a6 20 02  cmp  %i0, 2
a00c2de4:  7f ff 38 7d  call  0xa0090fd8
a00c2de8:  01 00 00 00  nop
a00c2dec:  7f ff 38 70  call  0xa0090fac
a00c2df0:  01 00 00 00  nop
a00c2df4:  80 a6 20 02  cmp  %i0, 2
a00c2df8:  12 bf ff b2  bne  0xa00c2cc0
a00c2dfc:  80 a6 20 03  cmp  %i0, 3
a00c2e00:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c2e04:  b0 12 21 28  or  %o0, 0x128, %i0	! 0xa802d128
a00c2e08:  a2 10 20 30  mov  0x30, %l1
a00c2e0c:  92 10 20 35  mov  0x35, %o1
a00c2e10:  9a 10 20 0d  mov  0xd, %o5
a00c2e14:  82 10 20 36  mov  0x36, %g1
a00c2e18:  98 10 20 2b  mov  0x2b, %o4
a00c2e1c:  d2 2a 21 28  stb  %o1, [ %o0 + 0x128 ]
a00c2e20:  da 2e 20 05  stb  %o5, [ %i0 + 5 ]
a00c2e24:  c2 2e 20 01  stb  %g1, [ %i0 + 1 ]
a00c2e28:  e2 2e 20 03  stb  %l1, [ %i0 + 3 ]
a00c2e2c:  d8 2e 20 04  stb  %o4, [ %i0 + 4 ]
a00c2e30:  e2 2e 20 02  stb  %l1, [ %i0 + 2 ]
a00c2e34:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c2e38:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c2e3c:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00c2e40:  c0 2e 20 9a  clrb  [ %i0 + 0x9a ]	! 0xa802b09a
a00c2e44:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c2e48:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c2e4c:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c2e50:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c2e54:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c2e58:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c2e5c:  94 13 e1 28  or  %o7, 0x128, %o2	! 0xa802d128
a00c2e60:  90 10 20 02  mov  2, %o0
a00c2e64:  40 02 16 61  call  0xa01487e8
a00c2e68:  92 10 20 06  mov  6, %o1
a00c2e6c:  10 80 00 25  b  0xa00c2f00
a00c2e70:  98 10 20 00  clr  %o4
a00c2e74:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c2e78:  10 bf ff 67  b  0xa00c2c14
a00c2e7c:  c2 0a a0 49  ldub  [ %o2 + 0x49 ], %g1	! 0xa802d049
a00c2e80:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c2e84:  10 bf ff 5d  b  0xa00c2bf8
a00c2e88:  c2 08 60 48  ldub  [ %g1 + 0x48 ], %g1	! 0xa802d048
a00c2e8c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c2e90:  10 bf ff 5a  b  0xa00c2bf8
a00c2e94:  c2 0a 20 a0  ldub  [ %o0 + 0xa0 ], %g1	! 0xa802d0a0
a00c2e98:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c2e9c:  10 bf ff 5e  b  0xa00c2c14
a00c2ea0:  c2 0a e0 a1  ldub  [ %o3 + 0xa1 ], %g1	! 0xa802d0a1
a00c2ea4:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c2ea8:  9e 14 61 08  or  %l1, 0x108, %o7	! 0xa802d108
a00c2eac:  94 10 20 30  mov  0x30, %o2
a00c2eb0:  98 10 20 35  mov  0x35, %o4
a00c2eb4:  b0 10 20 0d  mov  0xd, %i0
a00c2eb8:  a0 10 20 36  mov  0x36, %l0
a00c2ebc:  96 10 20 2b  mov  0x2b, %o3
a00c2ec0:  d8 2c 61 08  stb  %o4, [ %l1 + 0x108 ]
a00c2ec4:  f0 2b e0 05  stb  %i0, [ %o7 + 5 ]
a00c2ec8:  e0 2b e0 01  stb  %l0, [ %o7 + 1 ]
a00c2ecc:  d4 2b e0 03  stb  %o2, [ %o7 + 3 ]
a00c2ed0:  d6 2b e0 04  stb  %o3, [ %o7 + 4 ]
a00c2ed4:  d4 2b e0 02  stb  %o2, [ %o7 + 2 ]
a00c2ed8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c2edc:  a2 13 20 98  or  %o4, 0x98, %l1	! 0xa802d098
a00c2ee0:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00c2ee4:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]	! 0xa802b098
a00c2ee8:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]
a00c2eec:  c0 2c 60 19  clrb  [ %l1 + 0x19 ]
a00c2ef0:  c0 2c 60 01  clrb  [ %l1 + 1 ]
a00c2ef4:  c0 2c 60 07  clrb  [ %l1 + 7 ]
a00c2ef8:  10 bf ff 92  b  0xa00c2d40
a00c2efc:  c0 2c 60 0a  clrb  [ %l1 + 0xa ]
a00c2f00:  81 c7 e0 08  ret
a00c2f04:  91 e8 00 0c  restore  %g0, %o4, %o0
