# leon2m FUN_a00c1d54 0xa00c1d54-0xa00c2180 (1068 bytes)
a00c1d54:  9d e3 bf 98  save  %sp, -104, %sp
a00c1d58:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c1d5c:  80 a6 20 02  cmp  %i0, 2
a00c1d60:  02 80 00 d0  be  0xa00c20a0
a00c1d64:  80 a6 20 03  cmp  %i0, 3
a00c1d68:  02 80 00 d1  be  0xa00c20ac
a00c1d6c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c1d70:  c2 0a 60 d6  ldub  [ %o1 + 0xd6 ], %g1	! 0xa802d0d6
a00c1d74:  94 08 60 ff  and  %g1, 0xff, %o2
a00c1d78:  80 a6 20 02  cmp  %i0, 2
a00c1d7c:  02 80 00 c6  be  0xa00c2094
a00c1d80:  9a 5a a3 e8  smul  %o2, 0x3e8, %o5
a00c1d84:  80 a6 20 03  cmp  %i0, 3
a00c1d88:  02 80 00 d4  be  0xa00c20d8
a00c1d8c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c1d90:  c2 0b e0 d7  ldub  [ %o7 + 0xd7 ], %g1	! 0xa802d0d7
a00c1d94:  82 08 60 ff  and  %g1, 0xff, %g1
a00c1d98:  a0 58 60 64  smul  %g1, 0x64, %l0
a00c1d9c:  80 a6 20 02  cmp  %i0, 2
a00c1da0:  02 80 00 ba  be  0xa00c2088
a00c1da4:  98 03 40 10  add  %o5, %l0, %o4
a00c1da8:  80 a6 20 03  cmp  %i0, 3
a00c1dac:  02 80 00 c8  be  0xa00c20cc
a00c1db0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c1db4:  da 0a a0 d8  ldub  [ %o2 + 0xd8 ], %o5	! 0xa802d0d8
a00c1db8:  a0 0b 60 ff  and  %o5, 0xff, %l0
a00c1dbc:  9f 2c 20 02  sll  %l0, 2, %o7
a00c1dc0:  96 03 c0 10  add  %o7, %l0, %o3
a00c1dc4:  9a 02 c0 0b  add  %o3, %o3, %o5
a00c1dc8:  80 a6 20 02  cmp  %i0, 2
a00c1dcc:  02 80 00 ac  be  0xa00c207c
a00c1dd0:  98 03 00 0d  add  %o4, %o5, %o4
a00c1dd4:  80 a6 20 03  cmp  %i0, 3
a00c1dd8:  02 80 00 ba  be  0xa00c20c0
a00c1ddc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c1de0:  da 0a 60 d9  ldub  [ %o1 + 0xd9 ], %o5	! 0xa802d0d9
a00c1de4:  96 0b 60 ff  and  %o5, 0xff, %o3
a00c1de8:  9a 03 00 0b  add  %o4, %o3, %o5
a00c1dec:  15 3f ff f4  sethi  %hi(0xffffd000), %o2
a00c1df0:  98 12 a0 50  or  %o2, 0x50, %o4	! 0xffffd050
a00c1df4:  80 a6 20 02  cmp  %i0, 2
a00c1df8:  02 80 00 9e  be  0xa00c2070
a00c1dfc:  94 23 40 0c  sub  %o5, %o4, %o2
a00c1e00:  80 a6 20 03  cmp  %i0, 3
a00c1e04:  02 80 00 ad  be  0xa00c20b8
a00c1e08:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c1e0c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c1e10:  c2 08 60 da  ldub  [ %g1 + 0xda ], %g1	! 0xa802d0da
a00c1e14:  90 08 60 ff  and  %g1, 0xff, %o0
a00c1e18:  80 a6 20 02  cmp  %i0, 2
a00c1e1c:  02 80 00 92  be  0xa00c2064
a00c1e20:  9a 5a 23 e8  smul  %o0, 0x3e8, %o5
a00c1e24:  80 a6 20 03  cmp  %i0, 3
a00c1e28:  02 80 00 cf  be  0xa00c2164
a00c1e2c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c1e30:  c2 0a e0 db  ldub  [ %o3 + 0xdb ], %g1	! 0xa802d0db
a00c1e34:  a0 08 60 ff  and  %g1, 0xff, %l0
a00c1e38:  9e 5c 20 64  smul  %l0, 0x64, %o7
a00c1e3c:  80 a6 20 02  cmp  %i0, 2
a00c1e40:  02 80 00 86  be  0xa00c2058
a00c1e44:  98 03 40 0f  add  %o5, %o7, %o4
a00c1e48:  80 a6 20 03  cmp  %i0, 3
a00c1e4c:  02 80 00 c3  be  0xa00c2158
a00c1e50:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c1e54:  da 0a 60 dc  ldub  [ %o1 + 0xdc ], %o5	! 0xa802d0dc
a00c1e58:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00c1e5c:  a1 2b 60 02  sll  %o5, 2, %l0
a00c1e60:  9e 04 00 0d  add  %l0, %o5, %o7
a00c1e64:  96 03 c0 0f  add  %o7, %o7, %o3
a00c1e68:  80 a6 20 02  cmp  %i0, 2
a00c1e6c:  02 80 00 78  be  0xa00c204c
a00c1e70:  9a 03 00 0b  add  %o4, %o3, %o5
a00c1e74:  80 a6 20 03  cmp  %i0, 3
a00c1e78:  02 80 00 b5  be  0xa00c214c
a00c1e7c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c1e80:  c2 0a 20 dd  ldub  [ %o0 + 0xdd ], %g1	! 0xa802d0dd
a00c1e84:  98 08 60 ff  and  %g1, 0xff, %o4
a00c1e88:  9e 03 40 0c  add  %o5, %o4, %o7
a00c1e8c:  1b 3f ff f4  sethi  %hi(0xffffd000), %o5
a00c1e90:  97 2a a0 10  sll  %o2, 0x10, %o3
a00c1e94:  a0 13 60 50  or  %o5, 0x50, %l0
a00c1e98:  93 32 e0 10  srl  %o3, 0x10, %o1
a00c1e9c:  82 23 c0 10  sub  %o7, %l0, %g1
a00c1ea0:  80 a2 60 32  cmp  %o1, 0x32
a00c1ea4:  08 80 00 03  bleu  0xa00c1eb0
a00c1ea8:  96 10 00 01  mov  %g1, %o3
a00c1eac:  94 10 20 32  mov  0x32, %o2
a00c1eb0:  91 28 60 10  sll  %g1, 0x10, %o0
a00c1eb4:  83 32 20 10  srl  %o0, 0x10, %g1
a00c1eb8:  80 a0 60 1d  cmp  %g1, 0x1d
a00c1ebc:  38 80 00 02  bgu,a   0xa00c1ec4
a00c1ec0:  96 10 20 1d  mov  0x1d, %o3
a00c1ec4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c1ec8:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a00c1ecc:  a0 13 22 90  or  %o4, 0x290, %l0
a00c1ed0:  d2 13 63 f8  lduh  [ %o5 + 0x3f8 ], %o1
a00c1ed4:  1f 00 00 18  sethi  %hi(0x6000), %o7
a00c1ed8:  80 8b c0 09  btst  %o7, %o1
a00c1edc:  d4 2c 21 a5  stb  %o2, [ %l0 + 0x1a5 ]
a00c1ee0:  02 80 00 43  be  0xa00c1fec
a00c1ee4:  d6 2c 21 a6  stb  %o3, [ %l0 + 0x1a6 ]
a00c1ee8:  7f ff da 79  call  0xa00b88cc
a00c1eec:  01 00 00 00  nop
a00c1ef0:  80 a6 20 02  cmp  %i0, 2
a00c1ef4:  02 80 00 24  be  0xa00c1f84
a00c1ef8:  80 a6 20 03  cmp  %i0, 3
a00c1efc:  02 80 00 7a  be  0xa00c20e4
a00c1f00:  96 10 20 30  mov  0x30, %o3
a00c1f04:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c1f08:  94 12 60 78  or  %o1, 0x78, %o2	! 0xa802d078
a00c1f0c:  9e 10 20 35  mov  0x35, %o7
a00c1f10:  a0 10 20 36  mov  0x36, %l0
a00c1f14:  90 10 20 2b  mov  0x2b, %o0
a00c1f18:  82 10 20 0d  mov  0xd, %g1
a00c1f1c:  de 2a 60 78  stb  %o7, [ %o1 + 0x78 ]
a00c1f20:  e0 2a a0 01  stb  %l0, [ %o2 + 1 ]
a00c1f24:  d6 2a a0 03  stb  %o3, [ %o2 + 3 ]
a00c1f28:  d0 2a a0 04  stb  %o0, [ %o2 + 4 ]
a00c1f2c:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00c1f30:  80 a6 20 02  cmp  %i0, 2
a00c1f34:  02 80 00 21  be  0xa00c1fb8
a00c1f38:  d6 2a a0 02  stb  %o3, [ %o2 + 2 ]
a00c1f3c:  80 a6 20 03  cmp  %i0, 3
a00c1f40:  02 80 00 76  be  0xa00c2118
a00c1f44:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c1f48:  90 14 20 d0  or  %l0, 0xd0, %o0	! 0xa802d0d0
a00c1f4c:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00c1f50:  c0 2a 60 9c  clrb  [ %o1 + 0x9c ]	! 0xa802b09c
a00c1f54:  c0 2c 20 d0  clrb  [ %l0 + 0xd0 ]
a00c1f58:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c1f5c:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c1f60:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c1f64:  80 a6 20 02  cmp  %i0, 2
a00c1f68:  02 80 00 1d  be  0xa00c1fdc
a00c1f6c:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c1f70:  80 a6 20 03  cmp  %i0, 3
a00c1f74:  12 80 00 7f  bne  0xa00c2170
a00c1f78:  90 10 00 18  mov  %i0, %o0
a00c1f7c:  10 80 00 71  b  0xa00c2140
a00c1f80:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c1f84:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c1f88:  b0 12 e1 28  or  %o3, 0x128, %i0	! 0xa802d128
a00c1f8c:  9e 10 20 30  mov  0x30, %o7
a00c1f90:  82 10 20 35  mov  0x35, %g1
a00c1f94:  94 10 20 0d  mov  0xd, %o2
a00c1f98:  98 10 20 36  mov  0x36, %o4
a00c1f9c:  9a 10 20 2b  mov  0x2b, %o5
a00c1fa0:  c2 2a e1 28  stb  %g1, [ %o3 + 0x128 ]
a00c1fa4:  d4 2e 20 05  stb  %o2, [ %i0 + 5 ]
a00c1fa8:  d8 2e 20 01  stb  %o4, [ %i0 + 1 ]
a00c1fac:  de 2e 20 03  stb  %o7, [ %i0 + 3 ]
a00c1fb0:  da 2e 20 04  stb  %o5, [ %i0 + 4 ]
a00c1fb4:  de 2e 20 02  stb  %o7, [ %i0 + 2 ]
a00c1fb8:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c1fbc:  94 16 20 40  or  %i0, 0x40, %o2	! 0xa802d040
a00c1fc0:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00c1fc4:  c0 2b 60 9a  clrb  [ %o5 + 0x9a ]	! 0xa802b09a
a00c1fc8:  c0 2e 20 40  clrb  [ %i0 + 0x40 ]
a00c1fcc:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c1fd0:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c1fd4:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c1fd8:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c1fdc:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c1fe0:  94 13 e1 28  or  %o7, 0x128, %o2	! 0xa802d128
a00c1fe4:  10 80 00 63  b  0xa00c2170
a00c1fe8:  90 10 20 02  mov  2, %o0
a00c1fec:  7f ff 3b fb  call  0xa0090fd8
a00c1ff0:  01 00 00 00  nop
a00c1ff4:  7f ff 3b ee  call  0xa0090fac
a00c1ff8:  01 00 00 00  nop
a00c1ffc:  d4 0c 21 90  ldub  [ %l0 + 0x190 ], %o2
a00c2000:  80 a2 a0 00  cmp  %o2, 0
a00c2004:  12 bf ff b9  bne  0xa00c1ee8
a00c2008:  17 00 00 04  sethi  %hi(0x1000), %o3
a00c200c:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a00c2010:  80 88 40 0b  btst  %g1, %o3
a00c2014:  12 bf ff b5  bne  0xa00c1ee8
a00c2018:  01 00 00 00  nop
a00c201c:  d0 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o0
a00c2020:  80 a2 20 00  cmp  %o0, 0
a00c2024:  12 bf ff b1  bne  0xa00c1ee8
a00c2028:  01 00 00 00  nop
a00c202c:  d2 04 20 ac  ld  [ %l0 + 0xac ], %o1
a00c2030:  21 00 10 00  sethi  %hi(0x400000), %l0
a00c2034:  80 8a 40 10  btst  %o1, %l0
a00c2038:  12 bf ff ac  bne  0xa00c1ee8
a00c203c:  01 00 00 00  nop
a00c2040:  7f ff 3b e6  call  0xa0090fd8
a00c2044:  01 00 00 00  nop
a00c2048:  30 bf ff a8  b,a   0xa00c1ee8
a00c204c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c2050:  10 bf ff 8d  b  0xa00c1e84
a00c2054:  c2 0b 20 4d  ldub  [ %o4 + 0x4d ], %g1	! 0xa802d04d
a00c2058:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c205c:  10 bf ff 7f  b  0xa00c1e58
a00c2060:  da 08 60 4c  ldub  [ %g1 + 0x4c ], %o5	! 0xa802d04c
a00c2064:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c2068:  10 bf ff 73  b  0xa00c1e34
a00c206c:  c2 0a 60 4b  ldub  [ %o1 + 0x4b ], %g1	! 0xa802d04b
a00c2070:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c2074:  10 bf ff 68  b  0xa00c1e14
a00c2078:  c2 0b e0 4a  ldub  [ %o7 + 0x4a ], %g1	! 0xa802d04a
a00c207c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c2080:  10 bf ff 59  b  0xa00c1de4
a00c2084:  da 08 60 49  ldub  [ %g1 + 0x49 ], %o5	! 0xa802d049
a00c2088:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c208c:  10 bf ff 4b  b  0xa00c1db8
a00c2090:  da 0a 20 48  ldub  [ %o0 + 0x48 ], %o5	! 0xa802d048
a00c2094:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c2098:  10 bf ff 3f  b  0xa00c1d94
a00c209c:  c2 0a e0 47  ldub  [ %o3 + 0x47 ], %g1	! 0xa802d047
a00c20a0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c20a4:  10 bf ff 34  b  0xa00c1d74
a00c20a8:  c2 08 60 46  ldub  [ %g1 + 0x46 ], %g1	! 0xa802d046
a00c20ac:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c20b0:  10 bf ff 31  b  0xa00c1d74
a00c20b4:  c2 0a 20 9e  ldub  [ %o0 + 0x9e ], %g1	! 0xa802d09e
a00c20b8:  10 bf ff 57  b  0xa00c1e14
a00c20bc:  c2 0c 20 a2  ldub  [ %l0 + 0xa2 ], %g1
a00c20c0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c20c4:  10 bf ff 48  b  0xa00c1de4
a00c20c8:  da 0a 20 a1  ldub  [ %o0 + 0xa1 ], %o5	! 0xa802d0a1
a00c20cc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c20d0:  10 bf ff 3a  b  0xa00c1db8
a00c20d4:  da 0a 60 a0  ldub  [ %o1 + 0xa0 ], %o5	! 0xa802d0a0
a00c20d8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c20dc:  10 bf ff 2e  b  0xa00c1d94
a00c20e0:  c2 0b 20 9f  ldub  [ %o4 + 0x9f ], %g1	! 0xa802d09f
a00c20e4:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c20e8:  90 13 61 08  or  %o5, 0x108, %o0	! 0xa802d108
a00c20ec:  a0 10 20 30  mov  0x30, %l0
a00c20f0:  98 10 20 35  mov  0x35, %o4
a00c20f4:  9e 10 20 0d  mov  0xd, %o7
a00c20f8:  b0 10 20 36  mov  0x36, %i0
a00c20fc:  92 10 20 2b  mov  0x2b, %o1
a00c2100:  d8 2b 61 08  stb  %o4, [ %o5 + 0x108 ]
a00c2104:  de 2a 20 05  stb  %o7, [ %o0 + 5 ]
a00c2108:  f0 2a 20 01  stb  %i0, [ %o0 + 1 ]
a00c210c:  e0 2a 20 03  stb  %l0, [ %o0 + 3 ]
a00c2110:  d2 2a 20 04  stb  %o1, [ %o0 + 4 ]
a00c2114:  e0 2a 20 02  stb  %l0, [ %o0 + 2 ]
a00c2118:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c211c:  96 13 20 98  or  %o4, 0x98, %o3	! 0xa802d098
a00c2120:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c2124:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c2128:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]
a00c212c:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00c2130:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00c2134:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00c2138:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00c213c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c2140:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c2144:  10 80 00 0b  b  0xa00c2170
a00c2148:  90 10 20 03  mov  3, %o0
a00c214c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c2150:  10 bf ff 4d  b  0xa00c1e84
a00c2154:  c2 08 60 a5  ldub  [ %g1 + 0xa5 ], %g1	! 0xa802d0a5
a00c2158:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c215c:  10 bf ff 3f  b  0xa00c1e58
a00c2160:  da 0a 20 a4  ldub  [ %o0 + 0xa4 ], %o5	! 0xa802d0a4
a00c2164:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c2168:  10 bf ff 33  b  0xa00c1e34
a00c216c:  c2 0b 20 a3  ldub  [ %o4 + 0xa3 ], %g1	! 0xa802d0a3
a00c2170:  40 02 19 9e  call  0xa01487e8
a00c2174:  92 10 20 06  mov  6, %o1
a00c2178:  81 c7 e0 08  ret
a00c217c:  91 e8 20 00  restore  %g0, 0, %o0
