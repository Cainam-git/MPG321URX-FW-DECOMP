# leon2m FUN_a0113cd8 0xa0113cd8-0xa0113eb4 (476 bytes)
a0113cd8:  9d e3 bf 98  save  %sp, -104, %sp
a0113cdc:  93 2e a0 10  sll  %i2, 0x10, %o1
a0113ce0:  9a 10 00 19  mov  %i1, %o5
a0113ce4:  80 a2 60 00  cmp  %o1, 0
a0113ce8:  02 80 00 71  be  0xa0113eac
a0113cec:  96 10 20 00  clr  %o3
a0113cf0:  19 33 c0 47  sethi  %hi(0xcf011c00), %o4
a0113cf4:  a2 13 23 94  or  %o4, 0x394, %l1	! 0xcf011f94
a0113cf8:  90 0e e0 ff  and  %i3, 0xff, %o0
a0113cfc:  a0 10 20 80  mov  0x80, %l0
a0113d00:  94 13 23 90  or  %o4, 0x390, %o2
a0113d04:  a4 10 00 11  mov  %l1, %l2
a0113d08:  b6 13 23 a0  or  %o4, 0x3a0, %i3
a0113d0c:  da 26 c0 00  st  %o5, [ %i3 ]
a0113d10:  b2 13 23 a4  or  %o4, 0x3a4, %i1
a0113d14:  83 33 60 08  srl  %o5, 8, %g1
a0113d18:  c2 26 40 00  st  %g1, [ %i1 ]
a0113d1c:  bb 33 60 10  srl  %o5, 0x10, %i5
a0113d20:  b8 13 23 a8  or  %o4, 0x3a8, %i4
a0113d24:  fa 27 00 00  st  %i5, [ %i4 ]
a0113d28:  b6 13 23 ac  or  %o4, 0x3ac, %i3
a0113d2c:  b5 33 60 18  srl  %o5, 0x18, %i2
a0113d30:  f4 26 c0 00  st  %i2, [ %i3 ]
a0113d34:  b2 13 23 84  or  %o4, 0x384, %i1
a0113d38:  e0 26 40 00  st  %l0, [ %i1 ]
a0113d3c:  82 13 23 8c  or  %o4, 0x38c, %g1
a0113d40:  e0 20 40 00  st  %l0, [ %g1 ]
a0113d44:  fa 02 80 00  ld  [ %o2 ], %i5
a0113d48:  80 a7 60 80  cmp  %i5, 0x80
a0113d4c:  02 80 00 0b  be  0xa0113d78
a0113d50:  ba 10 3f ff  mov  -1, %i5
a0113d54:  ba 07 7f ff  add  %i5, -1, %i5
a0113d58:  b5 2f 60 10  sll  %i5, 0x10, %i2
a0113d5c:  80 a6 a0 00  cmp  %i2, 0
a0113d60:  02 80 00 07  be  0xa0113d7c
a0113d64:  80 a2 20 01  cmp  %o0, 1
a0113d68:  f8 02 80 00  ld  [ %o2 ], %i4
a0113d6c:  80 a7 20 80  cmp  %i4, 0x80
a0113d70:  12 bf ff fa  bne  0xa0113d58
a0113d74:  ba 07 7f ff  add  %i5, -1, %i5
a0113d78:  80 a2 20 01  cmp  %o0, 1
a0113d7c:  02 80 00 27  be  0xa0113e18
a0113d80:  b9 2a e0 10  sll  %o3, 0x10, %i4
a0113d84:  83 37 20 10  srl  %i4, 0x10, %g1
a0113d88:  b3 28 60 03  sll  %g1, 3, %i1
a0113d8c:  bb 28 60 13  sll  %g1, 0x13, %i5
a0113d90:  b5 37 60 10  srl  %i5, 0x10, %i2
a0113d94:  9e 06 60 08  add  %i1, 8, %o7
a0113d98:  80 a6 80 0f  cmp  %i2, %o7
a0113d9c:  16 80 00 18  bge  0xa0113dfc
a0113da0:  b4 10 00 19  mov  %i1, %i2
a0113da4:  b2 10 00 11  mov  %l1, %i1
a0113da8:  fa 06 40 00  ld  [ %i1 ], %i5
a0113dac:  b7 2e a0 10  sll  %i2, 0x10, %i3
a0113db0:  b7 36 e0 0e  srl  %i3, 0xe, %i3
a0113db4:  bb 2f 60 18  sll  %i5, 0x18, %i5
a0113db8:  fa 26 00 1b  st  %i5, [ %i0 + %i3 ]
a0113dbc:  f8 06 40 00  ld  [ %i1 ], %i4
a0113dc0:  83 2f 20 10  sll  %i4, 0x10, %g1
a0113dc4:  b8 17 40 01  or  %i5, %g1, %i4
a0113dc8:  f8 26 00 1b  st  %i4, [ %i0 + %i3 ]
a0113dcc:  c2 06 40 00  ld  [ %i1 ], %g1
a0113dd0:  83 28 60 08  sll  %g1, 8, %g1
a0113dd4:  ba 17 00 01  or  %i4, %g1, %i5
a0113dd8:  fa 26 00 1b  st  %i5, [ %i0 + %i3 ]
a0113ddc:  c2 06 40 00  ld  [ %i1 ], %g1
a0113de0:  b4 06 a0 01  inc  %i2
a0113de4:  ba 17 40 01  or  %i5, %g1, %i5
a0113de8:  b9 2e a0 10  sll  %i2, 0x10, %i4
a0113dec:  83 37 20 10  srl  %i4, 0x10, %g1
a0113df0:  80 a0 40 0f  cmp  %g1, %o7
a0113df4:  06 bf ff ed  bl  0xa0113da8
a0113df8:  fa 26 00 1b  st  %i5, [ %i0 + %i3 ]
a0113dfc:  b2 02 e0 01  add  %o3, 1, %i1
a0113e00:  b5 2e 60 10  sll  %i1, 0x10, %i2
a0113e04:  80 a2 40 1a  cmp  %o1, %i2
a0113e08:  9a 03 60 01  inc  %o5
a0113e0c:  18 bf ff bf  bgu  0xa0113d08
a0113e10:  96 10 00 19  mov  %i1, %o3
a0113e14:  30 80 00 26  b,a   0xa0113eac
a0113e18:  b5 2a e0 10  sll  %o3, 0x10, %i2
a0113e1c:  83 36 a0 10  srl  %i2, 0x10, %g1
a0113e20:  b3 28 60 03  sll  %g1, 3, %i1
a0113e24:  b7 28 60 13  sll  %g1, 0x13, %i3
a0113e28:  bb 36 e0 10  srl  %i3, 0x10, %i5
a0113e2c:  9e 06 60 08  add  %i1, 8, %o7
a0113e30:  80 a7 40 0f  cmp  %i5, %o7
a0113e34:  16 bf ff f2  bge  0xa0113dfc
a0113e38:  b4 10 00 19  mov  %i1, %i2
a0113e3c:  b2 10 00 12  mov  %l2, %i1
a0113e40:  b7 2e a0 10  sll  %i2, 0x10, %i3
a0113e44:  fa 06 40 00  ld  [ %i1 ], %i5
a0113e48:  b7 36 e0 0e  srl  %i3, 0xe, %i3
a0113e4c:  fa 26 00 1b  st  %i5, [ %i0 + %i3 ]
a0113e50:  f8 06 40 00  ld  [ %i1 ], %i4
a0113e54:  83 2f 20 08  sll  %i4, 8, %g1
a0113e58:  ba 17 40 01  or  %i5, %g1, %i5
a0113e5c:  fa 26 00 1b  st  %i5, [ %i0 + %i3 ]
a0113e60:  f8 06 40 00  ld  [ %i1 ], %i4
a0113e64:  83 2f 20 10  sll  %i4, 0x10, %g1
a0113e68:  ba 17 40 01  or  %i5, %g1, %i5
a0113e6c:  fa 26 00 1b  st  %i5, [ %i0 + %i3 ]
a0113e70:  f8 06 40 00  ld  [ %i1 ], %i4
a0113e74:  83 2f 20 18  sll  %i4, 0x18, %g1
a0113e78:  b4 06 a0 01  inc  %i2
a0113e7c:  b9 2e a0 10  sll  %i2, 0x10, %i4
a0113e80:  ba 17 40 01  or  %i5, %g1, %i5
a0113e84:  b9 37 20 10  srl  %i4, 0x10, %i4
a0113e88:  80 a7 00 0f  cmp  %i4, %o7
a0113e8c:  06 bf ff ed  bl  0xa0113e40
a0113e90:  fa 26 00 1b  st  %i5, [ %i0 + %i3 ]
a0113e94:  b2 02 e0 01  add  %o3, 1, %i1
a0113e98:  b5 2e 60 10  sll  %i1, 0x10, %i2
a0113e9c:  80 a2 40 1a  cmp  %o1, %i2
a0113ea0:  9a 03 60 01  inc  %o5
a0113ea4:  18 bf ff 99  bgu  0xa0113d08
a0113ea8:  96 10 00 19  mov  %i1, %o3
a0113eac:  81 c7 e0 08  ret
a0113eb0:  81 e8 00 00  restore
