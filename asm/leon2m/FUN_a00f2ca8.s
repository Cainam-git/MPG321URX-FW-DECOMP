# leon2m FUN_a00f2ca8 0xa00f2ca8-0xa00f2e30 (392 bytes)
a00f2ca8:  9d e3 bf 98  save  %sp, -104, %sp
a00f2cac:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f2cb0:  9e 10 00 19  mov  %i1, %o7
a00f2cb4:  80 a6 20 01  cmp  %i0, 1
a00f2cb8:  08 80 00 28  bleu  0xa00f2d58
a00f2cbc:  b2 10 00 1a  mov  %i2, %i1
a00f2cc0:  b4 0e e0 ff  and  %i3, 0xff, %i2
a00f2cc4:  37 00 06 68  sethi  %hi(0x19a000), %i3
a00f2cc8:  80 a6 a0 01  cmp  %i2, 1
a00f2ccc:  b4 0b e0 ff  and  %o7, 0xff, %i2
a00f2cd0:  9a 16 e2 e0  or  %i3, 0x2e0, %o5
a00f2cd4:  b6 10 20 00  clr  %i3
a00f2cd8:  b8 10 20 00  clr  %i4
a00f2cdc:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a00f2ce0:  02 80 00 37  be  0xa00f2dbc
a00f2ce4:  b0 38 00 19  xnor  %g0, %i1, %i0
a00f2ce8:  ba 07 00 1c  add  %i4, %i4, %i5
a00f2cec:  f2 13 40 1d  lduh  [ %o5 + %i5 ], %i1
a00f2cf0:  82 06 40 1a  add  %i1, %i2, %g1
a00f2cf4:  bb 28 60 02  sll  %g1, 2, %i5
a00f2cf8:  ba 17 40 0f  or  %i5, %o7, %i5
a00f2cfc:  f8 07 40 00  ld  [ %i5 ], %i4
a00f2d00:  b2 0f 00 18  and  %i4, %i0, %i1
a00f2d04:  b6 06 e0 01  inc  %i3
a00f2d08:  82 0e 60 ff  and  %i1, 0xff, %g1
a00f2d0c:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f2d10:  c2 27 40 00  st  %g1, [ %i5 ]
a00f2d14:  80 a7 20 01  cmp  %i4, 1
a00f2d18:  18 80 00 44  bgu  0xa00f2e28
a00f2d1c:  ba 07 00 1c  add  %i4, %i4, %i5
a00f2d20:  f2 13 40 1d  lduh  [ %o5 + %i5 ], %i1
a00f2d24:  82 06 40 1a  add  %i1, %i2, %g1
a00f2d28:  bb 28 60 02  sll  %g1, 2, %i5
a00f2d2c:  ba 17 40 0f  or  %i5, %o7, %i5
a00f2d30:  f8 07 40 00  ld  [ %i5 ], %i4
a00f2d34:  b2 0f 00 18  and  %i4, %i0, %i1
a00f2d38:  b6 06 e0 01  inc  %i3
a00f2d3c:  82 0e 60 ff  and  %i1, 0xff, %g1
a00f2d40:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f2d44:  c2 27 40 00  st  %g1, [ %i5 ]
a00f2d48:  80 a7 20 01  cmp  %i4, 1
a00f2d4c:  08 bf ff e8  bleu  0xa00f2cec
a00f2d50:  ba 07 00 1c  add  %i4, %i4, %i5
a00f2d54:  30 80 00 35  b,a   0xa00f2e28
a00f2d58:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f2d5c:  b8 13 62 e0  or  %o5, 0x2e0, %i4	! 0x19a2e0
a00f2d60:  b2 06 00 18  add  %i0, %i0, %i1
a00f2d64:  c2 17 00 19  lduh  [ %i4 + %i1 ], %g1
a00f2d68:  b2 0b e0 ff  and  %o7, 0xff, %i1
a00f2d6c:  82 00 40 19  add  %g1, %i1, %g1
a00f2d70:  b9 28 60 02  sll  %g1, 2, %i4
a00f2d74:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00f2d78:  82 17 00 1d  or  %i4, %i5, %g1
a00f2d7c:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f2d80:  c2 00 40 00  ld  [ %g1 ], %g1
a00f2d84:  80 a7 20 01  cmp  %i4, 1
a00f2d88:  02 80 00 03  be  0xa00f2d94
a00f2d8c:  b6 10 40 1a  or  %g1, %i2, %i3
a00f2d90:  b6 28 40 1a  andn  %g1, %i2, %i3
a00f2d94:  82 13 62 e0  or  %o5, 0x2e0, %g1
a00f2d98:  b4 06 00 18  add  %i0, %i0, %i2
a00f2d9c:  f0 10 40 1a  lduh  [ %g1 + %i2 ], %i0
a00f2da0:  b8 06 00 19  add  %i0, %i1, %i4
a00f2da4:  83 2f 20 02  sll  %i4, 2, %g1
a00f2da8:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00f2dac:  b0 10 40 1d  or  %g1, %i5, %i0
a00f2db0:  b4 0e e0 ff  and  %i3, 0xff, %i2
a00f2db4:  f4 26 00 00  st  %i2, [ %i0 ]
a00f2db8:  30 80 00 1c  b,a   0xa00f2e28
a00f2dbc:  82 07 00 1c  add  %i4, %i4, %g1
a00f2dc0:  f8 13 40 01  lduh  [ %o5 + %g1 ], %i4
a00f2dc4:  b0 07 00 1a  add  %i4, %i2, %i0
a00f2dc8:  bb 2e 20 02  sll  %i0, 2, %i5
a00f2dcc:  ba 17 40 0f  or  %i5, %o7, %i5
a00f2dd0:  c2 07 40 00  ld  [ %i5 ], %g1
a00f2dd4:  b8 10 40 19  or  %g1, %i1, %i4
a00f2dd8:  b0 0f 20 ff  and  %i4, 0xff, %i0
a00f2ddc:  b6 06 e0 01  inc  %i3
a00f2de0:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f2de4:  f0 27 40 00  st  %i0, [ %i5 ]
a00f2de8:  80 a7 20 01  cmp  %i4, 1
a00f2dec:  18 80 00 0f  bgu  0xa00f2e28
a00f2df0:  82 07 00 1c  add  %i4, %i4, %g1
a00f2df4:  f8 13 40 01  lduh  [ %o5 + %g1 ], %i4
a00f2df8:  b0 07 00 1a  add  %i4, %i2, %i0
a00f2dfc:  bb 2e 20 02  sll  %i0, 2, %i5
a00f2e00:  ba 17 40 0f  or  %i5, %o7, %i5
a00f2e04:  c2 07 40 00  ld  [ %i5 ], %g1
a00f2e08:  b8 10 40 19  or  %g1, %i1, %i4
a00f2e0c:  b0 0f 20 ff  and  %i4, 0xff, %i0
a00f2e10:  b6 06 e0 01  inc  %i3
a00f2e14:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f2e18:  f0 27 40 00  st  %i0, [ %i5 ]
a00f2e1c:  80 a7 20 01  cmp  %i4, 1
a00f2e20:  08 bf ff e8  bleu  0xa00f2dc0
a00f2e24:  82 07 00 1c  add  %i4, %i4, %g1
a00f2e28:  81 c7 e0 08  ret
a00f2e2c:  81 e8 00 00  restore
