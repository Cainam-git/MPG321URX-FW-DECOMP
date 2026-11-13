# leon2m FUN_a00a1cf0 0xa00a1cf0-0xa00a1eec (508 bytes)
a00a1cf0:  9d e3 bf 98  save  %sp, -104, %sp
a00a1cf4:  31 2a 00 97  sethi  %hi(0xa8025c00), %i0
a00a1cf8:  1f 2a 00 ab  sethi  %hi(0xa802ac00), %o7
a00a1cfc:  f2 0e 20 55  ldub  [ %i0 + 0x55 ], %i1
a00a1d00:  fa 03 e3 ec  ld  [ %o7 + 0x3ec ], %i5
a00a1d04:  82 06 60 01  add  %i1, 1, %g1
a00a1d08:  ba 07 7f 40  add  %i5, -192, %i5
a00a1d0c:  c2 2e 20 55  stb  %g1, [ %i0 + 0x55 ]
a00a1d10:  80 a7 60 39  cmp  %i5, 0x39
a00a1d14:  18 80 00 08  bgu  0xa00a1d34
a00a1d18:  b6 10 20 00  clr  %i3
a00a1d1c:  b5 2f 60 02  sll  %i5, 2, %i2
a00a1d20:  3b 00 00 c1  sethi  %hi(0x30400), %i5
a00a1d24:  82 17 60 50  or  %i5, 0x50, %g1	! 0x30450
a00a1d28:  f8 00 40 1a  ld  [ %g1 + %i2 ], %i4
a00a1d2c:  81 c7 00 00  jmp  %i4
a00a1d30:  01 00 00 00  nop
a00a1d34:  ba 10 20 00  clr  %i5	! 0x0
a00a1d38:  f6 0e 20 55  ldub  [ %i0 + 0x55 ], %i3
a00a1d3c:  80 a6 c0 1d  cmp  %i3, %i5
a00a1d40:  08 80 00 10  bleu  0xa00a1d80
a00a1d44:  ba 16 20 55  or  %i0, 0x55, %i5
a00a1d48:  f2 03 e3 ec  ld  [ %o7 + 0x3ec ], %i1
a00a1d4c:  82 06 7f 40  add  %i1, -192, %g1
a00a1d50:  b4 10 00 1d  mov  %i5, %i2
a00a1d54:  80 a0 60 39  cmp  %g1, 0x39
a00a1d58:  18 80 00 08  bgu  0xa00a1d78
a00a1d5c:  b6 10 20 00  clr  %i3
a00a1d60:  33 00 00 c0  sethi  %hi(0x30000), %i1
a00a1d64:  83 28 60 02  sll  %g1, 2, %g1
a00a1d68:  ba 16 63 68  or  %i1, 0x368, %i5
a00a1d6c:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a00a1d70:  81 c7 00 00  jmp  %i4
a00a1d74:  01 00 00 00  nop
a00a1d78:  82 10 20 00  clr  %g1	! 0x0
a00a1d7c:  c2 2e 80 00  stb  %g1, [ %i2 ]
a00a1d80:  f4 03 e3 ec  ld  [ %o7 + 0x3ec ], %i2
a00a1d84:  82 06 bf 40  add  %i2, -192, %g1
a00a1d88:  80 a0 60 39  cmp  %g1, 0x39
a00a1d8c:  f4 0e 20 55  ldub  [ %i0 + 0x55 ], %i2
a00a1d90:  18 80 00 08  bgu  0xa00a1db0
a00a1d94:  b6 10 20 00  clr  %i3
a00a1d98:  33 00 00 c0  sethi  %hi(0x30000), %i1
a00a1d9c:  83 28 60 02  sll  %g1, 2, %g1
a00a1da0:  ba 16 62 80  or  %i1, 0x280, %i5
a00a1da4:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a00a1da8:  81 c7 00 00  jmp  %i4
a00a1dac:  01 00 00 00  nop
a00a1db0:  b8 10 20 00  clr  %i4	! 0x0
a00a1db4:  ba 26 80 1c  sub  %i2, %i4, %i5
a00a1db8:  82 07 40 1d  add  %i5, %i5, %g1
a00a1dbc:  b4 00 40 1d  add  %g1, %i5, %i2
a00a1dc0:  b7 2e a0 05  sll  %i2, 5, %i3
a00a1dc4:  f8 03 e3 ec  ld  [ %o7 + 0x3ec ], %i4
a00a1dc8:  ba 07 3f 40  add  %i4, -192, %i5
a00a1dcc:  9a 06 80 1b  add  %i2, %i3, %o5
a00a1dd0:  80 a7 60 39  cmp  %i5, 0x39
a00a1dd4:  18 80 00 08  bgu  0xa00a1df4
a00a1dd8:  b6 10 20 00  clr  %i3
a00a1ddc:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00a1de0:  b5 2f 60 02  sll  %i5, 2, %i2
a00a1de4:  b8 10 61 98  or  %g1, 0x198, %i4
a00a1de8:  f2 07 00 1a  ld  [ %i4 + %i2 ], %i1
a00a1dec:  81 c6 40 00  jmp  %i1
a00a1df0:  01 00 00 00  nop
a00a1df4:  b2 10 20 00  clr  %i1	! 0x0
a00a1df8:  f6 03 e3 ec  ld  [ %o7 + 0x3ec ], %i3
a00a1dfc:  82 06 ff 40  add  %i3, -192, %g1
a00a1e00:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00a1e04:  80 a0 60 39  cmp  %g1, 0x39
a00a1e08:  18 80 00 08  bgu  0xa00a1e28
a00a1e0c:  b6 10 20 00  clr  %i3
a00a1e10:  33 00 00 c0  sethi  %hi(0x30000), %i1
a00a1e14:  b9 28 60 02  sll  %g1, 2, %i4
a00a1e18:  ba 16 60 b0  or  %i1, 0xb0, %i5
a00a1e1c:  f2 07 40 1c  ld  [ %i5 + %i4 ], %i1
a00a1e20:  81 c6 40 00  jmp  %i1
a00a1e24:  01 00 00 00  nop
a00a1e28:  b2 10 20 00  clr  %i1	! 0x0
a00a1e2c:  b8 26 80 19  sub  %i2, %i1, %i4
a00a1e30:  83 3b 60 1f  sra  %o5, 0x1f, %g1
a00a1e34:  81 80 60 00  mov  %g1, %y
a00a1e38:  01 00 00 00  nop
a00a1e3c:  01 00 00 00  nop
a00a1e40:  01 00 00 00  nop
a00a1e44:  b6 7b 40 1c  sdiv  %o5, %i4, %i3
a00a1e48:  b4 06 e0 01  add  %i3, 1, %i2
a00a1e4c:  b2 0e a0 ff  and  %i2, 0xff, %i1
a00a1e50:  f4 0e 20 55  ldub  [ %i0 + 0x55 ], %i2
a00a1e54:  40 00 58 05  call  0xa00b7e68
a00a1e58:  91 e8 20 01  restore  %g0, 1, %o0
a00a1e5c:  b6 10 20 01  mov  1, %i3
a00a1e60:  b2 0e e0 ff  and  %i3, 0xff, %i1
a00a1e64:  b8 26 80 19  sub  %i2, %i1, %i4
a00a1e68:  83 3b 60 1f  sra  %o5, 0x1f, %g1
a00a1e6c:  81 80 60 00  mov  %g1, %y
a00a1e70:  01 00 00 00  nop
a00a1e74:  01 00 00 00  nop
a00a1e78:  01 00 00 00  nop
a00a1e7c:  b6 7b 40 1c  sdiv  %o5, %i4, %i3
a00a1e80:  b4 06 e0 01  add  %i3, 1, %i2
a00a1e84:  b2 0e a0 ff  and  %i2, 0xff, %i1
a00a1e88:  f4 0e 20 55  ldub  [ %i0 + 0x55 ], %i2
a00a1e8c:  40 00 57 f7  call  0xa00b7e68
a00a1e90:  91 e8 20 01  restore  %g0, 1, %o0
a00a1e94:  b6 10 20 01  mov  1, %i3
a00a1e98:  10 bf ff c7  b  0xa00a1db4
a00a1e9c:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00a1ea0:  b6 10 20 03  mov  3, %i3
a00a1ea4:  10 bf ff d5  b  0xa00a1df8
a00a1ea8:  b2 0e e0 ff  and  %i3, 0xff, %i1
a00a1eac:  b6 10 20 03  mov  3, %i3
a00a1eb0:  10 bf ff a2  b  0xa00a1d38
a00a1eb4:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00a1eb8:  b6 10 20 03  mov  3, %i3
a00a1ebc:  82 0e e0 ff  and  %i3, 0xff, %g1
a00a1ec0:  10 bf ff b0  b  0xa00a1d80
a00a1ec4:  c2 2e 80 00  stb  %g1, [ %i2 ]
a00a1ec8:  b6 10 20 02  mov  2, %i3
a00a1ecc:  10 bf ff 9b  b  0xa00a1d38
a00a1ed0:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00a1ed4:  b6 10 20 02  mov  2, %i3
a00a1ed8:  10 bf ff c8  b  0xa00a1df8
a00a1edc:  b2 0e e0 ff  and  %i3, 0xff, %i1
a00a1ee0:  b6 10 20 02  mov  2, %i3
a00a1ee4:  10 bf ff f7  b  0xa00a1ec0
a00a1ee8:  82 0e e0 ff  and  %i3, 0xff, %g1
