# leon2s FUN_a00b1e70 0xa00b1e70-0xa00b1fe0 (368 bytes)
a00b1e70:  9d e3 bf 98  save  %sp, -104, %sp
a00b1e74:  27 2a 01 e4  sethi  %hi(0xa8079000), %l3
a00b1e78:  c2 0c e3 a4  ldub  [ %l3 + 0x3a4 ], %g1	! 0xa80793a4
a00b1e7c:  80 a0 60 00  cmp  %g1, 0
a00b1e80:  12 80 00 56  bne  0xa00b1fd8
a00b1e84:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b1e88:  c0 20 62 98  clr  [ %g1 + 0x298 ]	! 0xa807de98
a00b1e8c:  96 10 20 00  clr  %o3
a00b1e90:  98 14 e3 a4  or  %l3, 0x3a4, %o4
a00b1e94:  82 03 20 0c  add  %o4, 0xc, %g1
a00b1e98:  9a 10 20 01  mov  1, %o5
a00b1e9c:  c0 20 40 00  clr  [ %g1 ]
a00b1ea0:  9a 83 7f ff  addcc  %o5, -1, %o5
a00b1ea4:  1c bf ff fe  bpos  0xa00b1e9c
a00b1ea8:  82 00 60 04  add  %g1, 4, %g1
a00b1eac:  96 02 e0 01  inc  %o3
a00b1eb0:  80 a2 e0 00  cmp  %o3, 0
a00b1eb4:  04 bf ff f8  ble  0xa00b1e94
a00b1eb8:  98 03 20 08  add  %o4, 8, %o4
a00b1ebc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00b1ec0:  da 00 63 dc  ld  [ %g1 + 0x3dc ], %o5	! 0xa80787dc
a00b1ec4:  03 01 6e 36  sethi  %hi(0x5b8d800), %g1
a00b1ec8:  80 a3 40 01  cmp  %o5, %g1
a00b1ecc:  03 00 00 0b  sethi  %hi(0x2c00), %g1
a00b1ed0:  02 80 00 08  be  0xa00b1ef0
a00b1ed4:  a4 10 62 e0  or  %g1, 0x2e0, %l2	! 0x2ee0
a00b1ed8:  03 01 31 2d  sethi  %hi(0x4c4b400), %g1
a00b1edc:  80 a3 40 01  cmp  %o5, %g1
a00b1ee0:  03 00 00 09  sethi  %hi(0x2400), %g1
a00b1ee4:  02 80 00 03  be  0xa00b1ef0
a00b1ee8:  a4 10 63 10  or  %g1, 0x310, %l2	! 0x2710
a00b1eec:  a4 10 2b b8  mov  0xbb8, %l2
a00b1ef0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b1ef4:  82 10 63 b8  or  %g1, 0x3b8, %g1	! 0xa80793b8
a00b1ef8:  96 10 20 0f  mov  0xf, %o3
a00b1efc:  c0 28 60 04  clrb  [ %g1 + 4 ]
a00b1f00:  c0 28 60 05  clrb  [ %g1 + 5 ]
a00b1f04:  c0 20 60 14  clr  [ %g1 + 0x14 ]
a00b1f08:  96 82 ff ff  addcc  %o3, -1, %o3
a00b1f0c:  1c bf ff fc  bpos  0xa00b1efc
a00b1f10:  82 00 60 18  add  %g1, 0x18, %g1
a00b1f14:  21 30 00 00  sethi  %hi(0xc0000000), %l0
a00b1f18:  c2 04 00 00  ld  [ %l0 ], %g1
a00b1f1c:  82 10 60 02  or  %g1, 2, %g1
a00b1f20:  c2 24 00 00  st  %g1, [ %l0 ]
a00b1f24:  7f ff fe 1c  call  0xa00b1794
a00b1f28:  90 10 20 01  mov  1, %o0
a00b1f2c:  c2 04 00 00  ld  [ %l0 ], %g1
a00b1f30:  82 08 7f fd  and  %g1, -3, %g1
a00b1f34:  23 30 02 80  sethi  %hi(0xc00a0000), %l1
a00b1f38:  c2 24 00 00  st  %g1, [ %l0 ]
a00b1f3c:  92 10 00 12  mov  %l2, %o1
a00b1f40:  7f fe bd 7d  call  0xa0061534
a00b1f44:  90 14 60 10  or  %l1, 0x10, %o0
a00b1f48:  90 14 60 14  or  %l1, 0x14, %o0
a00b1f4c:  7f fe bd 7a  call  0xa0061534
a00b1f50:  92 10 20 83  mov  0x83, %o1
a00b1f54:  90 14 60 18  or  %l1, 0x18, %o0
a00b1f58:  7f fe bd 77  call  0xa0061534
a00b1f5c:  92 10 20 00  clr  %o1
a00b1f60:  19 27 c4 80  sethi  %hi(0x9f120000), %o4
a00b1f64:  9a 13 20 30  or  %o4, 0x30, %o5	! 0x9f120030
a00b1f68:  c2 03 40 00  ld  [ %o5 ], %g1
a00b1f6c:  82 10 60 10  or  %g1, 0x10, %g1
a00b1f70:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1f74:  1b 27 c4 00  sethi  %hi(0x9f100000), %o5
a00b1f78:  9a 13 60 90  or  %o5, 0x90, %o5	! 0x9f100090
a00b1f7c:  c2 03 40 00  ld  [ %o5 ], %g1
a00b1f80:  82 10 60 10  or  %g1, 0x10, %g1
a00b1f84:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1f88:  9a 13 20 28  or  %o4, 0x28, %o5
a00b1f8c:  c2 03 40 00  ld  [ %o5 ], %g1
a00b1f90:  82 08 7f ef  and  %g1, -17, %g1
a00b1f94:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1f98:  9a 13 20 44  or  %o4, 0x44, %o5
a00b1f9c:  c2 03 40 00  ld  [ %o5 ], %g1
a00b1fa0:  82 08 7f fd  and  %g1, -3, %g1
a00b1fa4:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1fa8:  9a 13 20 7c  or  %o4, 0x7c, %o5
a00b1fac:  82 10 20 02  mov  2, %g1
a00b1fb0:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1fb4:  9a 13 20 38  or  %o4, 0x38, %o5
a00b1fb8:  c2 03 40 00  ld  [ %o5 ], %g1
a00b1fbc:  82 08 7f f0  and  %g1, -16, %g1
a00b1fc0:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1fc4:  98 13 20 34  or  %o4, 0x34, %o4
a00b1fc8:  96 10 20 10  mov  0x10, %o3
a00b1fcc:  d6 23 00 00  st  %o3, [ %o4 ]
a00b1fd0:  82 10 20 01  mov  1, %g1
a00b1fd4:  c2 2c e3 a4  stb  %g1, [ %l3 + 0x3a4 ]
a00b1fd8:  81 c7 e0 08  ret
a00b1fdc:  81 e8 00 00  restore
