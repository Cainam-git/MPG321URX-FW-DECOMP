# leon2m FUN_a00c8c38 0xa00c8c38-0xa00c91dc (1444 bytes)
a00c8c38:  9d e3 bf 98  save  %sp, -104, %sp
a00c8c3c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c8c40:  82 12 e2 90  or  %o3, 0x290, %g1	! 0xa802d290
a00c8c44:  da 08 60 1f  ldub  [ %g1 + 0x1f ], %o5
a00c8c48:  80 a3 60 00  cmp  %o5, 0
a00c8c4c:  02 80 01 62  be  0xa00c91d4
a00c8c50:  82 10 20 ff  mov  0xff, %g1
a00c8c54:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c8c58:  80 a6 20 02  cmp  %i0, 2
a00c8c5c:  02 80 00 d5  be  0xa00c8fb0
a00c8c60:  80 a6 20 03  cmp  %i0, 3
a00c8c64:  02 80 01 02  be  0xa00c906c
a00c8c68:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c8c6c:  c2 0a a0 d6  ldub  [ %o2 + 0xd6 ], %g1	! 0xa802d0d6
a00c8c70:  98 08 60 ff  and  %g1, 0xff, %o4
a00c8c74:  80 a6 20 02  cmp  %i0, 2
a00c8c78:  02 80 00 d4  be  0xa00c8fc8
a00c8c7c:  9a 5b 23 e8  smul  %o4, 0x3e8, %o5
a00c8c80:  80 a6 20 03  cmp  %i0, 3
a00c8c84:  02 80 01 1c  be  0xa00c90f4
a00c8c88:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c8c8c:  c2 0c 60 d7  ldub  [ %l1 + 0xd7 ], %g1	! 0xa802d0d7
a00c8c90:  90 08 60 ff  and  %g1, 0xff, %o0
a00c8c94:  82 5a 20 64  smul  %o0, 0x64, %g1
a00c8c98:  80 a6 20 02  cmp  %i0, 2
a00c8c9c:  02 80 00 d2  be  0xa00c8fe4
a00c8ca0:  98 03 40 01  add  %o5, %g1, %o4
a00c8ca4:  80 a6 20 03  cmp  %i0, 3
a00c8ca8:  02 80 01 10  be  0xa00c90e8
a00c8cac:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c8cb0:  da 0b e0 d8  ldub  [ %o7 + 0xd8 ], %o5	! 0xa802d0d8
a00c8cb4:  82 0b 60 ff  and  %o5, 0xff, %g1
a00c8cb8:  a3 28 60 02  sll  %g1, 2, %l1
a00c8cbc:  a0 04 40 01  add  %l1, %g1, %l0
a00c8cc0:  9a 04 00 10  add  %l0, %l0, %o5
a00c8cc4:  80 a6 20 02  cmp  %i0, 2
a00c8cc8:  02 80 00 d0  be  0xa00c9008
a00c8ccc:  98 03 00 0d  add  %o4, %o5, %o4
a00c8cd0:  80 a6 20 03  cmp  %i0, 3
a00c8cd4:  02 80 01 17  be  0xa00c9130
a00c8cd8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c8cdc:  da 0a a0 d9  ldub  [ %o2 + 0xd9 ], %o5	! 0xa802d0d9
a00c8ce0:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00c8ce4:  9e 03 00 0d  add  %o4, %o5, %o7
a00c8ce8:  21 3f ff f4  sethi  %hi(0xffffd000), %l0
a00c8cec:  98 14 20 50  or  %l0, 0x50, %o4	! 0xffffd050
a00c8cf0:  80 a6 20 02  cmp  %i0, 2
a00c8cf4:  02 80 00 ce  be  0xa00c902c
a00c8cf8:  a0 23 c0 0c  sub  %o7, %o4, %l0
a00c8cfc:  80 a6 20 03  cmp  %i0, 3
a00c8d00:  02 80 01 09  be  0xa00c9124
a00c8d04:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c8d08:  c2 0a 20 da  ldub  [ %o0 + 0xda ], %g1	! 0xa802d0da
a00c8d0c:  92 08 60 ff  and  %g1, 0xff, %o1
a00c8d10:  80 a6 20 02  cmp  %i0, 2
a00c8d14:  02 80 00 cc  be  0xa00c9044
a00c8d18:  9a 5a 63 e8  smul  %o1, 0x3e8, %o5
a00c8d1c:  80 a6 20 03  cmp  %i0, 3
a00c8d20:  02 80 00 fe  be  0xa00c9118
a00c8d24:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c8d28:  c2 0b e0 db  ldub  [ %o7 + 0xdb ], %g1	! 0xa802d0db
a00c8d2c:  82 08 60 ff  and  %g1, 0xff, %g1
a00c8d30:  a2 58 60 64  smul  %g1, 0x64, %l1
a00c8d34:  80 a6 20 02  cmp  %i0, 2
a00c8d38:  02 80 00 ca  be  0xa00c9060
a00c8d3c:  98 03 40 11  add  %o5, %l1, %o4
a00c8d40:  80 a6 20 03  cmp  %i0, 3
a00c8d44:  02 80 00 f2  be  0xa00c910c
a00c8d48:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c8d4c:  da 0a a0 dc  ldub  [ %o2 + 0xdc ], %o5	! 0xa802d0dc
a00c8d50:  82 0b 60 ff  and  %o5, 0xff, %g1
a00c8d54:  a3 28 60 02  sll  %g1, 2, %l1
a00c8d58:  9e 04 40 01  add  %l1, %g1, %o7
a00c8d5c:  9a 03 c0 0f  add  %o7, %o7, %o5
a00c8d60:  80 a6 20 02  cmp  %i0, 2
a00c8d64:  02 80 00 90  be  0xa00c8fa4
a00c8d68:  98 03 00 0d  add  %o4, %o5, %o4
a00c8d6c:  80 a6 20 03  cmp  %i0, 3
a00c8d70:  02 80 00 e4  be  0xa00c9100
a00c8d74:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c8d78:  da 0a a0 dd  ldub  [ %o2 + 0xdd ], %o5	! 0xa802d0dd
a00c8d7c:  a2 0b 60 ff  and  %o5, 0xff, %l1
a00c8d80:  9a 03 00 11  add  %o4, %l1, %o5
a00c8d84:  1f 3f ff f4  sethi  %hi(0xffffd000), %o7
a00c8d88:  a2 12 e2 90  or  %o3, 0x290, %l1
a00c8d8c:  98 13 e0 50  or  %o7, 0x50, %o4
a00c8d90:  96 23 40 0c  sub  %o5, %o4, %o3
a00c8d94:  c2 0c 60 31  ldub  [ %l1 + 0x31 ], %g1
a00c8d98:  d6 34 60 56  sth  %o3, [ %l1 + 0x56 ]
a00c8d9c:  80 a0 60 00  cmp  %g1, 0
a00c8da0:  02 80 00 46  be  0xa00c8eb8
a00c8da4:  e0 34 60 54  sth  %l0, [ %l1 + 0x54 ]
a00c8da8:  80 a0 60 01  cmp  %g1, 1
a00c8dac:  02 80 00 e4  be  0xa00c913c
a00c8db0:  95 2c 20 10  sll  %l0, 0x10, %o2
a00c8db4:  a1 32 a0 10  srl  %o2, 0x10, %l0
a00c8db8:  40 01 fd 71  call  0xa014837c
a00c8dbc:  90 10 20 00  clr  %o0
a00c8dc0:  93 2a 20 10  sll  %o0, 0x10, %o1
a00c8dc4:  91 32 60 10  srl  %o1, 0x10, %o0
a00c8dc8:  82 02 3c 40  add  %o0, -960, %g1
a00c8dcc:  80 a4 00 01  cmp  %l0, %g1
a00c8dd0:  14 80 00 f7  bg  0xa00c91ac
a00c8dd4:  01 00 00 00  nop
a00c8dd8:  e0 14 60 56  lduh  [ %l1 + 0x56 ], %l0
a00c8ddc:  40 01 fd 68  call  0xa014837c
a00c8de0:  90 10 20 01  mov  1, %o0
a00c8de4:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00c8de8:  99 33 e0 10  srl  %o7, 0x10, %o4
a00c8dec:  9a 03 3d e4  add  %o4, -540, %o5
a00c8df0:  80 a4 00 0d  cmp  %l0, %o5
a00c8df4:  14 80 00 e9  bg  0xa00c9198
a00c8df8:  01 00 00 00  nop
a00c8dfc:  40 00 3b 1d  call  0xa00d7a70
a00c8e00:  90 10 20 01  mov  1, %o0	! 0x1
a00c8e04:  7f ff be b2  call  0xa00b88cc
a00c8e08:  01 00 00 00  nop
a00c8e0c:  80 a6 20 02  cmp  %i0, 2
a00c8e10:  02 80 00 49  be  0xa00c8f34
a00c8e14:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c8e18:  80 a6 20 03  cmp  %i0, 3
a00c8e1c:  02 80 00 9c  be  0xa00c908c
a00c8e20:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c8e24:  94 13 20 78  or  %o4, 0x78, %o2	! 0xa802d078
a00c8e28:  90 10 20 30  mov  0x30, %o0
a00c8e2c:  9a 10 20 35  mov  0x35, %o5
a00c8e30:  a0 10 20 36  mov  0x36, %l0
a00c8e34:  96 10 20 2b  mov  0x2b, %o3
a00c8e38:  92 10 20 0d  mov  0xd, %o1
a00c8e3c:  da 2b 20 78  stb  %o5, [ %o4 + 0x78 ]
a00c8e40:  e0 2a a0 01  stb  %l0, [ %o2 + 1 ]
a00c8e44:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00c8e48:  d6 2a a0 04  stb  %o3, [ %o2 + 4 ]
a00c8e4c:  d2 2a a0 05  stb  %o1, [ %o2 + 5 ]
a00c8e50:  80 a6 20 02  cmp  %i0, 2
a00c8e54:  02 80 00 44  be  0xa00c8f64
a00c8e58:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00c8e5c:  80 a6 20 03  cmp  %i0, 3
a00c8e60:  02 80 00 98  be  0xa00c90c0
a00c8e64:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c8e68:  92 12 e0 d0  or  %o3, 0xd0, %o1	! 0xa802d0d0
a00c8e6c:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00c8e70:  c0 2c 20 9c  clrb  [ %l0 + 0x9c ]	! 0xa802b09c
a00c8e74:  c0 2a e0 d0  clrb  [ %o3 + 0xd0 ]
a00c8e78:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00c8e7c:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00c8e80:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00c8e84:  80 a6 20 02  cmp  %i0, 2
a00c8e88:  02 80 00 40  be  0xa00c8f88
a00c8e8c:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00c8e90:  80 a6 20 03  cmp  %i0, 3
a00c8e94:  12 80 00 40  bne  0xa00c8f94
a00c8e98:  90 10 00 18  mov  %i0, %o0
a00c8e9c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c8ea0:  94 13 61 08  or  %o5, 0x108, %o2	! 0xa802d108
a00c8ea4:  90 10 20 03  mov  3, %o0
a00c8ea8:  40 01 fe 50  call  0xa01487e8
a00c8eac:  92 10 20 06  mov  6, %o1
a00c8eb0:  10 80 00 c9  b  0xa00c91d4
a00c8eb4:  82 10 20 00  clr  %g1
a00c8eb8:  95 2c 20 10  sll  %l0, 0x10, %o2
a00c8ebc:  a1 32 a0 10  srl  %o2, 0x10, %l0
a00c8ec0:  40 01 fd 2f  call  0xa014837c
a00c8ec4:  90 10 20 00  clr  %o0
a00c8ec8:  93 2a 20 10  sll  %o0, 0x10, %o1
a00c8ecc:  91 32 60 10  srl  %o1, 0x10, %o0
a00c8ed0:  82 02 39 40  add  %o0, -1728, %g1
a00c8ed4:  80 a4 00 01  cmp  %l0, %g1
a00c8ed8:  14 80 00 68  bg  0xa00c9078
a00c8edc:  01 00 00 00  nop
a00c8ee0:  e0 14 60 56  lduh  [ %l1 + 0x56 ], %l0
a00c8ee4:  40 01 fd 26  call  0xa014837c
a00c8ee8:  90 10 20 01  mov  1, %o0
a00c8eec:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00c8ef0:  99 33 e0 10  srl  %o7, 0x10, %o4
a00c8ef4:  9a 03 3c 34  add  %o4, -972, %o5
a00c8ef8:  80 a4 00 0d  cmp  %l0, %o5
a00c8efc:  04 bf ff c0  ble  0xa00c8dfc
a00c8f00:  01 00 00 00  nop
a00c8f04:  40 01 fd 1e  call  0xa014837c
a00c8f08:  90 10 20 01  mov  1, %o0	! 0x1
a00c8f0c:  90 02 3c 34  add  %o0, -972, %o0
a00c8f10:  d0 34 60 56  sth  %o0, [ %l1 + 0x56 ]
a00c8f14:  40 00 3a d7  call  0xa00d7a70
a00c8f18:  90 10 20 01  mov  1, %o0
a00c8f1c:  7f ff be 6c  call  0xa00b88cc
a00c8f20:  01 00 00 00  nop
a00c8f24:  80 a6 20 02  cmp  %i0, 2
a00c8f28:  12 bf ff bd  bne  0xa00c8e1c
a00c8f2c:  80 a6 20 03  cmp  %i0, 3
a00c8f30:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c8f34:  b0 12 a1 28  or  %o2, 0x128, %i0	! 0xa802d128
a00c8f38:  a2 10 20 30  mov  0x30, %l1
a00c8f3c:  96 10 20 35  mov  0x35, %o3
a00c8f40:  92 10 20 0d  mov  0xd, %o1
a00c8f44:  90 10 20 36  mov  0x36, %o0
a00c8f48:  82 10 20 2b  mov  0x2b, %g1
a00c8f4c:  d6 2a a1 28  stb  %o3, [ %o2 + 0x128 ]
a00c8f50:  d2 2e 20 05  stb  %o1, [ %i0 + 5 ]
a00c8f54:  d0 2e 20 01  stb  %o0, [ %i0 + 1 ]
a00c8f58:  e2 2e 20 03  stb  %l1, [ %i0 + 3 ]
a00c8f5c:  c2 2e 20 04  stb  %g1, [ %i0 + 4 ]
a00c8f60:  e2 2e 20 02  stb  %l1, [ %i0 + 2 ]
a00c8f64:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c8f68:  94 13 e0 40  or  %o7, 0x40, %o2	! 0xa802d040
a00c8f6c:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00c8f70:  c0 2e 20 9a  clrb  [ %i0 + 0x9a ]	! 0xa802b09a
a00c8f74:  c0 2b e0 40  clrb  [ %o7 + 0x40 ]
a00c8f78:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c8f7c:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c8f80:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c8f84:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c8f88:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c8f8c:  94 13 21 28  or  %o4, 0x128, %o2	! 0xa802d128
a00c8f90:  90 10 20 02  mov  2, %o0
a00c8f94:  40 01 fe 15  call  0xa01487e8
a00c8f98:  92 10 20 06  mov  6, %o1
a00c8f9c:  10 80 00 8e  b  0xa00c91d4
a00c8fa0:  82 10 20 00  clr  %g1
a00c8fa4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c8fa8:  10 bf ff 75  b  0xa00c8d7c
a00c8fac:  da 0a 20 4d  ldub  [ %o0 + 0x4d ], %o5	! 0xa802d04d
a00c8fb0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c8fb4:  c2 0a 20 46  ldub  [ %o0 + 0x46 ], %g1	! 0xa802d046
a00c8fb8:  98 08 60 ff  and  %g1, 0xff, %o4
a00c8fbc:  80 a6 20 02  cmp  %i0, 2
a00c8fc0:  12 bf ff 30  bne  0xa00c8c80
a00c8fc4:  9a 5b 23 e8  smul  %o4, 0x3e8, %o5
a00c8fc8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c8fcc:  c2 0b e0 47  ldub  [ %o7 + 0x47 ], %g1	! 0xa802d047
a00c8fd0:  90 08 60 ff  and  %g1, 0xff, %o0
a00c8fd4:  82 5a 20 64  smul  %o0, 0x64, %g1
a00c8fd8:  80 a6 20 02  cmp  %i0, 2
a00c8fdc:  12 bf ff 32  bne  0xa00c8ca4
a00c8fe0:  98 03 40 01  add  %o5, %g1, %o4
a00c8fe4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c8fe8:  da 0a 60 48  ldub  [ %o1 + 0x48 ], %o5	! 0xa802d048
a00c8fec:  82 0b 60 ff  and  %o5, 0xff, %g1
a00c8ff0:  a3 28 60 02  sll  %g1, 2, %l1
a00c8ff4:  a0 04 40 01  add  %l1, %g1, %l0
a00c8ff8:  9a 04 00 10  add  %l0, %l0, %o5
a00c8ffc:  80 a6 20 02  cmp  %i0, 2
a00c9000:  12 bf ff 34  bne  0xa00c8cd0
a00c9004:  98 03 00 0d  add  %o4, %o5, %o4
a00c9008:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c900c:  da 0a 20 49  ldub  [ %o0 + 0x49 ], %o5	! 0xa802d049
a00c9010:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00c9014:  9e 03 00 0d  add  %o4, %o5, %o7
a00c9018:  21 3f ff f4  sethi  %hi(0xffffd000), %l0
a00c901c:  98 14 20 50  or  %l0, 0x50, %o4	! 0xffffd050
a00c9020:  80 a6 20 02  cmp  %i0, 2
a00c9024:  12 bf ff 36  bne  0xa00c8cfc
a00c9028:  a0 23 c0 0c  sub  %o7, %o4, %l0
a00c902c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c9030:  c2 0c 60 4a  ldub  [ %l1 + 0x4a ], %g1	! 0xa802d04a
a00c9034:  92 08 60 ff  and  %g1, 0xff, %o1
a00c9038:  80 a6 20 02  cmp  %i0, 2
a00c903c:  12 bf ff 38  bne  0xa00c8d1c
a00c9040:  9a 5a 63 e8  smul  %o1, 0x3e8, %o5
a00c9044:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c9048:  c2 0a a0 4b  ldub  [ %o2 + 0x4b ], %g1	! 0xa802d04b
a00c904c:  82 08 60 ff  and  %g1, 0xff, %g1
a00c9050:  a2 58 60 64  smul  %g1, 0x64, %l1
a00c9054:  80 a6 20 02  cmp  %i0, 2
a00c9058:  12 bf ff 3a  bne  0xa00c8d40
a00c905c:  98 03 40 11  add  %o5, %l1, %o4
a00c9060:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c9064:  10 bf ff 3b  b  0xa00c8d50
a00c9068:  da 0a 20 4c  ldub  [ %o0 + 0x4c ], %o5	! 0xa802d04c
a00c906c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c9070:  10 bf ff 00  b  0xa00c8c70
a00c9074:  c2 0a 60 9e  ldub  [ %o1 + 0x9e ], %g1	! 0xa802d09e
a00c9078:  40 01 fc c1  call  0xa014837c
a00c907c:  90 10 20 00  clr  %o0
a00c9080:  96 02 39 40  add  %o0, -1728, %o3
a00c9084:  10 bf ff 97  b  0xa00c8ee0
a00c9088:  d6 34 60 54  sth  %o3, [ %l1 + 0x54 ]
a00c908c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c9090:  a0 14 61 08  or  %l1, 0x108, %l0	! 0xa802d108
a00c9094:  98 10 20 30  mov  0x30, %o4
a00c9098:  82 10 20 35  mov  0x35, %g1
a00c909c:  b0 10 20 0d  mov  0xd, %i0
a00c90a0:  9e 10 20 36  mov  0x36, %o7
a00c90a4:  9a 10 20 2b  mov  0x2b, %o5
a00c90a8:  c2 2c 61 08  stb  %g1, [ %l1 + 0x108 ]
a00c90ac:  f0 2c 20 05  stb  %i0, [ %l0 + 5 ]
a00c90b0:  de 2c 20 01  stb  %o7, [ %l0 + 1 ]
a00c90b4:  d8 2c 20 03  stb  %o4, [ %l0 + 3 ]
a00c90b8:  da 2c 20 04  stb  %o5, [ %l0 + 4 ]
a00c90bc:  d8 2c 20 02  stb  %o4, [ %l0 + 2 ]
a00c90c0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c90c4:  a2 12 20 98  or  %o0, 0x98, %l1	! 0xa802d098
a00c90c8:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c90cc:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c90d0:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00c90d4:  c0 2c 60 19  clrb  [ %l1 + 0x19 ]
a00c90d8:  c0 2c 60 01  clrb  [ %l1 + 1 ]
a00c90dc:  c0 2c 60 07  clrb  [ %l1 + 7 ]
a00c90e0:  10 bf ff 6f  b  0xa00c8e9c
a00c90e4:  c0 2c 60 0a  clrb  [ %l1 + 0xa ]
a00c90e8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c90ec:  10 bf fe f2  b  0xa00c8cb4
a00c90f0:  da 0a a0 a0  ldub  [ %o2 + 0xa0 ], %o5	! 0xa802d0a0
a00c90f4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c90f8:  10 bf fe e6  b  0xa00c8c90
a00c90fc:  c2 0c 20 9f  ldub  [ %l0 + 0x9f ], %g1	! 0xa802d09f
a00c9100:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c9104:  10 bf ff 1e  b  0xa00c8d7c
a00c9108:  da 0a 60 a5  ldub  [ %o1 + 0xa5 ], %o5	! 0xa802d0a5
a00c910c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c9110:  10 bf ff 10  b  0xa00c8d50
a00c9114:  da 0a 60 a4  ldub  [ %o1 + 0xa4 ], %o5	! 0xa802d0a4
a00c9118:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c911c:  10 bf ff 04  b  0xa00c8d2c
a00c9120:  c2 0b 20 a3  ldub  [ %o4 + 0xa3 ], %g1	! 0xa802d0a3
a00c9124:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c9128:  10 bf fe f9  b  0xa00c8d0c
a00c912c:  c2 08 60 a2  ldub  [ %g1 + 0xa2 ], %g1	! 0xa802d0a2
a00c9130:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c9134:  10 bf fe eb  b  0xa00c8ce0
a00c9138:  da 0a 60 a1  ldub  [ %o1 + 0xa1 ], %o5	! 0xa802d0a1
a00c913c:  a1 32 a0 10  srl  %o2, 0x10, %l0
a00c9140:  40 01 fc 8f  call  0xa014837c
a00c9144:  90 10 20 00  clr  %o0
a00c9148:  93 2a 20 10  sll  %o0, 0x10, %o1
a00c914c:  91 32 60 10  srl  %o1, 0x10, %o0
a00c9150:  82 02 3a c0  add  %o0, -1344, %g1
a00c9154:  80 a4 00 01  cmp  %l0, %g1
a00c9158:  14 80 00 1a  bg  0xa00c91c0
a00c915c:  01 00 00 00  nop
a00c9160:  e0 14 60 56  lduh  [ %l1 + 0x56 ], %l0
a00c9164:  40 01 fc 86  call  0xa014837c
a00c9168:  90 10 20 01  mov  1, %o0
a00c916c:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00c9170:  99 33 e0 10  srl  %o7, 0x10, %o4
a00c9174:  9a 03 3d 0c  add  %o4, -756, %o5
a00c9178:  80 a4 00 0d  cmp  %l0, %o5
a00c917c:  04 bf ff 20  ble  0xa00c8dfc
a00c9180:  01 00 00 00  nop
a00c9184:  40 01 fc 7e  call  0xa014837c
a00c9188:  90 10 20 01  mov  1, %o0	! 0x1
a00c918c:  90 02 3d 0c  add  %o0, -756, %o0
a00c9190:  10 bf ff 61  b  0xa00c8f14
a00c9194:  d0 34 60 56  sth  %o0, [ %l1 + 0x56 ]
a00c9198:  40 01 fc 79  call  0xa014837c
a00c919c:  90 10 20 01  mov  1, %o0
a00c91a0:  90 02 3d e4  add  %o0, -540, %o0
a00c91a4:  10 bf ff 5c  b  0xa00c8f14
a00c91a8:  d0 34 60 56  sth  %o0, [ %l1 + 0x56 ]
a00c91ac:  40 01 fc 74  call  0xa014837c
a00c91b0:  90 10 20 00  clr  %o0
a00c91b4:  96 02 3c 40  add  %o0, -960, %o3
a00c91b8:  10 bf ff 08  b  0xa00c8dd8
a00c91bc:  d6 34 60 54  sth  %o3, [ %l1 + 0x54 ]
a00c91c0:  40 01 fc 6f  call  0xa014837c
a00c91c4:  90 10 20 00  clr  %o0
a00c91c8:  96 02 3a c0  add  %o0, -1344, %o3
a00c91cc:  10 bf ff e5  b  0xa00c9160
a00c91d0:  d6 34 60 54  sth  %o3, [ %l1 + 0x54 ]
a00c91d4:  81 c7 e0 08  ret
a00c91d8:  91 e8 00 01  restore  %g0, %g1, %o0
