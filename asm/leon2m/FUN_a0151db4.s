# leon2m FUN_a0151db4 0xa0151db4-0xa0152010 (392 bytes)
a0151db4:  9d e3 bf 48  save  %sp, -184, %sp
a0151db8:  7f ff 49 11  call  0xa01241fc
a0151dbc:  01 00 00 00  nop
a0151dc0:  19 00 06 9d  sethi  %hi(0x1a7400), %o4
a0151dc4:  a0 10 00 08  mov  %o0, %l0
a0151dc8:  90 13 21 18  or  %o4, 0x118, %o0
a0151dcc:  7f fe 34 e9  call  0xa00df170
a0151dd0:  c0 2f bf d2  clrb  [ %fp + -46 ]
a0151dd4:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0151dd8:  d6 00 61 a0  ld  [ %g1 + 0x1a0 ], %o3	! 0xa802e1a0
a0151ddc:  9e 10 61 a0  or  %g1, 0x1a0, %o7
a0151de0:  d0 03 e0 04  ld  [ %o7 + 4 ], %o0
a0151de4:  94 0a e0 ff  and  %o3, 0xff, %o2
a0151de8:  9b 2a a0 08  sll  %o2, 8, %o5
a0151dec:  93 32 20 18  srl  %o0, 0x18, %o1
a0151df0:  82 12 40 0d  or  %o1, %o5, %g1
a0151df4:  99 32 20 08  srl  %o0, 8, %o4
a0151df8:  97 32 e0 08  srl  %o3, 8, %o3
a0151dfc:  d8 37 bf e2  sth  %o4, [ %fp + -30 ]
a0151e00:  80 a0 60 00  cmp  %g1, 0
a0151e04:  c2 37 bf e0  sth  %g1, [ %fp + -32 ]
a0151e08:  02 80 00 21  be  0xa0151e8c
a0151e0c:  d6 37 bf de  sth  %o3, [ %fp + -34 ]
a0151e10:  96 10 20 01  mov  1, %o3
a0151e14:  d6 2f bf d1  stb  %o3, [ %fp + -47 ]
a0151e18:  d6 2f bf d0  stb  %o3, [ %fp + -48 ]
a0151e1c:  c2 0c 20 07  ldub  [ %l0 + 7 ], %g1
a0151e20:  80 a0 60 08  cmp  %g1, 8
a0151e24:  22 80 00 26  be,a   0xa0151ebc
a0151e28:  de 04 00 00  ld  [ %l0 ], %o7
a0151e2c:  80 a0 60 0a  cmp  %g1, 0xa
a0151e30:  02 80 00 2b  be  0xa0151edc
a0151e34:  82 10 20 02  mov  2, %g1
a0151e38:  7f ff 48 f1  call  0xa01241fc
a0151e3c:  a0 10 20 00  clr  %l0
a0151e40:  d2 0a 20 06  ldub  [ %o0 + 6 ], %o1
a0151e44:  82 0a 60 ff  and  %o1, 0xff, %g1
a0151e48:  82 00 7f f0  add  %g1, -16, %g1
a0151e4c:  80 a0 60 32  cmp  %g1, 0x32
a0151e50:  38 80 00 55  bgu,a   0xa0151fa4
a0151e54:  d8 02 00 00  ld  [ %o0 ], %o4
a0151e58:  1f 00 03 c4  sethi  %hi(0xf1000), %o7
a0151e5c:  97 28 60 02  sll  %g1, 2, %o3
a0151e60:  94 13 e0 d4  or  %o7, 0xd4, %o2
a0151e64:  d8 02 80 0b  ld  [ %o2 + %o3 ], %o4
a0151e68:  81 c3 00 00  jmp  %o4
a0151e6c:  01 00 00 00  nop
a0151e70:  de 02 00 00  ld  [ %o0 ], %o7
a0151e74:  1b 00 03 80  sethi  %hi(0xe0000), %o5
a0151e78:  94 0b c0 0d  and  %o7, %o5, %o2
a0151e7c:  80 a0 00 0a  cmp  %g0, %o2
a0151e80:  96 10 20 06  mov  6, %o3
a0151e84:  10 80 00 47  b  0xa0151fa0
a0151e88:  a0 62 e0 00  subx  %o3, 0, %l0
a0151e8c:  91 2a e0 10  sll  %o3, 0x10, %o0
a0151e90:  80 a2 20 00  cmp  %o0, 0
a0151e94:  22 bf ff e2  be,a   0xa0151e1c
a0151e98:  c0 2f bf d0  clrb  [ %fp + -48 ]
a0151e9c:  92 10 20 01  mov  1, %o1
a0151ea0:  d2 2f bf d0  stb  %o1, [ %fp + -48 ]
a0151ea4:  c0 2f bf d1  clrb  [ %fp + -47 ]
a0151ea8:  c2 0c 20 07  ldub  [ %l0 + 7 ], %g1
a0151eac:  80 a0 60 08  cmp  %g1, 8
a0151eb0:  12 bf ff e0  bne  0xa0151e30
a0151eb4:  80 a0 60 0a  cmp  %g1, 0xa
a0151eb8:  de 04 00 00  ld  [ %l0 ], %o7
a0151ebc:  1b 00 1c 00  sethi  %hi(0x700000), %o5
a0151ec0:  94 0b c0 0d  and  %o7, %o5, %o2
a0151ec4:  21 00 08 00  sethi  %hi(0x200000), %l0
a0151ec8:  80 a2 80 10  cmp  %o2, %l0
a0151ecc:  02 80 00 33  be  0xa0151f98
a0151ed0:  82 10 20 03  mov  3, %g1
a0151ed4:  10 bf ff d9  b  0xa0151e38
a0151ed8:  c0 27 bf d4  clr  [ %fp + -44 ]
a0151edc:  10 bf ff d7  b  0xa0151e38
a0151ee0:  c2 27 bf d4  st  %g1, [ %fp + -44 ]
a0151ee4:  d4 02 00 00  ld  [ %o0 ], %o2
a0151ee8:  1f 00 03 80  sethi  %hi(0xe0000), %o7
a0151eec:  82 0a 80 0f  and  %o2, %o7, %g1
a0151ef0:  17 00 01 00  sethi  %hi(0x40000), %o3
a0151ef4:  80 a0 40 0b  cmp  %g1, %o3
a0151ef8:  02 80 00 2a  be  0xa0151fa0
a0151efc:  a0 10 20 0d  mov  0xd, %l0
a0151f00:  80 a0 00 01  cmp  %g0, %g1
a0151f04:  82 10 20 0c  mov  0xc, %g1
a0151f08:  10 80 00 26  b  0xa0151fa0
a0151f0c:  a0 60 60 00  subx  %g1, 0, %l0
a0151f10:  10 80 00 24  b  0xa0151fa0
a0151f14:  a0 10 20 01  mov  1, %l0
a0151f18:  d6 02 00 00  ld  [ %o0 ], %o3
a0151f1c:  15 00 03 80  sethi  %hi(0xe0000), %o2
a0151f20:  82 0a c0 0a  and  %o3, %o2, %g1
a0151f24:  19 00 00 80  sethi  %hi(0x20000), %o4
a0151f28:  a0 18 40 0c  xor  %g1, %o4, %l0
a0151f2c:  80 a0 00 10  cmp  %g0, %l0
a0151f30:  9a 40 20 00  addx  %g0, 0, %o5
a0151f34:  10 80 00 1b  b  0xa0151fa0
a0151f38:  a0 03 60 03  add  %o5, 3, %l0
a0151f3c:  10 80 00 19  b  0xa0151fa0
a0151f40:  a0 10 20 05  mov  5, %l0
a0151f44:  c2 02 00 00  ld  [ %o0 ], %g1
a0151f48:  19 00 03 80  sethi  %hi(0xe0000), %o4
a0151f4c:  a0 08 40 0c  and  %g1, %o4, %l0
a0151f50:  80 a0 00 10  cmp  %g0, %l0
a0151f54:  9a 60 20 00  subx  %g0, 0, %o5
a0151f58:  9e 0b 7f f7  and  %o5, -9, %o7
a0151f5c:  10 80 00 11  b  0xa0151fa0
a0151f60:  a0 03 e0 11  add  %o7, 0x11, %l0
a0151f64:  10 80 00 0f  b  0xa0151fa0
a0151f68:  a0 10 20 0e  mov  0xe, %l0
a0151f6c:  c2 02 00 00  ld  [ %o0 ], %g1
a0151f70:  19 00 03 80  sethi  %hi(0xe0000), %o4
a0151f74:  21 00 01 00  sethi  %hi(0x40000), %l0
a0151f78:  82 08 40 0c  and  %g1, %o4, %g1
a0151f7c:  80 a0 40 10  cmp  %g1, %l0
a0151f80:  02 80 00 08  be  0xa0151fa0
a0151f84:  a0 10 20 0a  mov  0xa, %l0
a0151f88:  80 a0 00 01  cmp  %g0, %g1
a0151f8c:  82 10 20 09  mov  9, %g1
a0151f90:  10 80 00 04  b  0xa0151fa0
a0151f94:  a0 60 60 00  subx  %g1, 0, %l0
a0151f98:  10 bf ff a8  b  0xa0151e38
a0151f9c:  c2 27 bf d4  st  %g1, [ %fp + -44 ]
a0151fa0:  d8 02 00 00  ld  [ %o0 ], %o4
a0151fa4:  9b 33 20 11  srl  %o4, 0x11, %o5
a0151fa8:  03 00 06 9d  sethi  %hi(0x1a7400), %g1
a0151fac:  94 0b 60 07  and  %o5, 7, %o2
a0151fb0:  92 0a 60 ff  and  %o1, 0xff, %o1
a0151fb4:  96 10 00 10  mov  %l0, %o3
a0151fb8:  7f fe 34 6e  call  0xa00df170
a0151fbc:  90 10 60 f0  or  %g1, 0xf0, %o0
a0151fc0:  92 10 3f 80  mov  -128, %o1
a0151fc4:  e0 27 bf d8  st  %l0, [ %fp + -40 ]
a0151fc8:  d2 2f bf dc  stb  %o1, [ %fp + -36 ]
a0151fcc:  c0 2f bf dd  clrb  [ %fp + -35 ]
a0151fd0:  d8 1f bf d0  ldd  [ %fp + -48 ], %o4
a0151fd4:  d4 1f bf d8  ldd  [ %fp + -40 ], %o2
a0151fd8:  d0 07 bf f0  ld  [ %fp + -16 ], %o0
a0151fdc:  c0 2f bf e4  clrb  [ %fp + -28 ]
a0151fe0:  d8 3f bf a8  std  %o4, [ %fp + -88 ]
a0151fe4:  d4 3f bf b0  std  %o2, [ %fp + -80 ]
a0151fe8:  d8 1f bf e0  ldd  [ %fp + -32 ], %o4
a0151fec:  d4 1f bf e8  ldd  [ %fp + -24 ], %o2
a0151ff0:  d0 27 bf c8  st  %o0, [ %fp + -56 ]
a0151ff4:  d8 3f bf b8  std  %o4, [ %fp + -72 ]
a0151ff8:  d4 3f bf c0  std  %o2, [ %fp + -64 ]
a0151ffc:  7f fe cc 55  call  0xa0105150
a0152000:  90 07 bf a8  add  %fp, -88, %o0
a0152004:  01 00 00 00  nop
a0152008:  81 c7 e0 08  ret
a015200c:  81 e8 00 00  restore
