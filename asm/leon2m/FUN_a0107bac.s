# leon2m FUN_a0107bac 0xa0107bac-0xa0107e44 (664 bytes)
a0107bac:  92 0a 60 ff  and  %o1, 0xff, %o1
a0107bb0:  80 a2 60 0f  cmp  %o1, 0xf
a0107bb4:  02 80 00 a2  be  0xa0107e3c
a0107bb8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0107bbc:  19 33 c0 f0  sethi  %hi(0xcf03c000), %o4
a0107bc0:  80 a2 20 00  cmp  %o0, 0
a0107bc4:  12 80 00 44  bne  0xa0107cd4
a0107bc8:  98 13 23 48  or  %o4, 0x348, %o4
a0107bcc:  da 03 00 00  ld  [ %o4 ], %o5
a0107bd0:  83 2a 60 02  sll  %o1, 2, %g1
a0107bd4:  82 08 60 1c  and  %g1, 0x1c, %g1
a0107bd8:  9a 0b 7f e3  and  %o5, -29, %o5
a0107bdc:  9a 13 40 01  or  %o5, %g1, %o5
a0107be0:  da 23 00 00  st  %o5, [ %o4 ]
a0107be4:  94 0a a0 ff  and  %o2, 0xff, %o2
a0107be8:  da 03 00 00  ld  [ %o4 ], %o5
a0107bec:  82 02 80 0a  add  %o2, %o2, %g1
a0107bf0:  82 08 60 02  and  %g1, 2, %g1
a0107bf4:  9a 0b 7f fd  and  %o5, -3, %o5
a0107bf8:  9a 13 40 01  or  %o5, %g1, %o5
a0107bfc:  da 23 00 00  st  %o5, [ %o4 ]
a0107c00:  c2 03 00 00  ld  [ %o4 ], %g1
a0107c04:  9a 0a e0 01  and  %o3, 1, %o5
a0107c08:  82 08 7f fe  and  %g1, -2, %g1
a0107c0c:  96 10 40 0d  or  %g1, %o5, %o3
a0107c10:  d6 23 00 00  st  %o3, [ %o4 ]
a0107c14:  17 33 c0 f0  sethi  %hi(0xcf03c000), %o3
a0107c18:  98 12 e2 94  or  %o3, 0x294, %o4	! 0xcf03c294
a0107c1c:  80 a2 20 00  cmp  %o0, 0
a0107c20:  da 03 00 00  ld  [ %o4 ], %o5
a0107c24:  12 80 00 04  bne  0xa0107c34
a0107c28:  82 10 20 01  mov  1, %g1
a0107c2c:  83 28 40 09  sll  %g1, %o1, %g1
a0107c30:  9a 2b 40 01  andn  %o5, %g1, %o5
a0107c34:  da 23 00 00  st  %o5, [ %o4 ]
a0107c38:  80 a2 20 01  cmp  %o0, 1
a0107c3c:  da 03 00 00  ld  [ %o4 ], %o5
a0107c40:  02 80 00 47  be  0xa0107d5c
a0107c44:  83 2a 00 09  sll  %o0, %o1, %g1
a0107c48:  da 23 00 00  st  %o5, [ %o4 ]
a0107c4c:  80 a2 a0 00  cmp  %o2, 0
a0107c50:  02 80 00 39  be  0xa0107d34
a0107c54:  11 2a 00 9e  sethi  %hi(0xa8027800), %o0
a0107c58:  9a 10 20 01  mov  1, %o5
a0107c5c:  83 2b 40 09  sll  %o5, %o1, %g1
a0107c60:  96 12 e3 f8  or  %o3, 0x3f8, %o3
a0107c64:  da 02 c0 00  ld  [ %o3 ], %o5
a0107c68:  11 2a 00 9e  sethi  %hi(0xa8027800), %o0
a0107c6c:  d8 0a 22 87  ldub  [ %o0 + 0x287 ], %o4	! 0xa8027a87
a0107c70:  9a 13 40 01  or  %o5, %g1, %o5
a0107c74:  98 2b 00 01  andn  %o4, %g1, %o4
a0107c78:  da 22 c0 00  st  %o5, [ %o3 ]
a0107c7c:  d8 2a 22 87  stb  %o4, [ %o0 + 0x287 ]
a0107c80:  80 a2 60 00  cmp  %o1, 0
a0107c84:  12 80 00 17  bne  0xa0107ce0
a0107c88:  80 a2 60 01  cmp  %o1, 1
a0107c8c:  13 33 c0 f0  sethi  %hi(0xcf03c000), %o1
a0107c90:  80 a2 a0 00  cmp  %o2, 0
a0107c94:  12 80 00 3a  bne  0xa0107d7c
a0107c98:  9a 12 63 48  or  %o1, 0x348, %o5
a0107c9c:  15 33 c0 f0  sethi  %hi(0xcf03c000), %o2
a0107ca0:  9a 12 a3 48  or  %o2, 0x348, %o5	! 0xcf03c348
a0107ca4:  d4 03 40 00  ld  [ %o5 ], %o2
a0107ca8:  82 0a bf bf  and  %o2, -65, %g1
a0107cac:  c2 23 40 00  st  %g1, [ %o5 ]
a0107cb0:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a0107cb4:  d8 0a 22 87  ldub  [ %o0 + 0x287 ], %o4
a0107cb8:  82 13 61 a8  or  %o5, 0x1a8, %g1
a0107cbc:  d8 20 40 00  st  %o4, [ %g1 ]
a0107cc0:  90 13 63 54  or  %o5, 0x354, %o0
a0107cc4:  d6 02 00 00  ld  [ %o0 ], %o3
a0107cc8:  94 12 e0 80  or  %o3, 0x80, %o2
a0107ccc:  d4 22 00 00  st  %o2, [ %o0 ]
a0107cd0:  30 80 00 5b  b,a   0xa0107e3c
a0107cd4:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a0107cd8:  10 bf ff bd  b  0xa0107bcc
a0107cdc:  98 10 62 b8  or  %g1, 0x2b8, %o4	! 0xcf03c2b8
a0107ce0:  02 80 00 32  be  0xa0107da8
a0107ce4:  80 a2 60 02  cmp  %o1, 2
a0107ce8:  02 80 00 28  be  0xa0107d88
a0107cec:  80 a2 60 03  cmp  %o1, 3
a0107cf0:  02 80 00 37  be  0xa0107dcc
a0107cf4:  80 a2 60 04  cmp  %o1, 4
a0107cf8:  02 80 00 45  be  0xa0107e0c
a0107cfc:  80 a2 60 05  cmp  %o1, 5
a0107d00:  02 80 00 19  be  0xa0107d64
a0107d04:  80 a2 60 06  cmp  %o1, 6
a0107d08:  12 bf ff eb  bne  0xa0107cb4
a0107d0c:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a0107d10:  17 33 c0 f0  sethi  %hi(0xcf03c000), %o3
a0107d14:  80 a2 a0 00  cmp  %o2, 0
a0107d18:  02 80 00 2a  be  0xa0107dc0
a0107d1c:  9a 12 e3 4c  or  %o3, 0x34c, %o5
a0107d20:  19 33 c0 f0  sethi  %hi(0xcf03c000), %o4
a0107d24:  9a 13 23 4c  or  %o4, 0x34c, %o5	! 0xcf03c34c
a0107d28:  c2 03 40 00  ld  [ %o5 ], %g1
a0107d2c:  10 bf ff e0  b  0xa0107cac
a0107d30:  82 10 60 80  or  %g1, 0x80, %g1
a0107d34:  82 10 20 01  mov  1, %g1
a0107d38:  da 0a 22 87  ldub  [ %o0 + 0x287 ], %o5
a0107d3c:  96 12 e3 f8  or  %o3, 0x3f8, %o3
a0107d40:  83 28 40 09  sll  %g1, %o1, %g1
a0107d44:  d8 02 c0 00  ld  [ %o3 ], %o4
a0107d48:  9a 10 40 0d  or  %g1, %o5, %o5
a0107d4c:  82 2b 00 01  andn  %o4, %g1, %g1
a0107d50:  c2 22 c0 00  st  %g1, [ %o3 ]
a0107d54:  10 bf ff cb  b  0xa0107c80
a0107d58:  da 2a 22 87  stb  %o5, [ %o0 + 0x287 ]
a0107d5c:  10 bf ff bb  b  0xa0107c48
a0107d60:  9a 13 40 01  or  %o5, %g1, %o5
a0107d64:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a0107d68:  80 a2 a0 00  cmp  %o2, 0
a0107d6c:  02 bf ff ce  be  0xa0107ca4
a0107d70:  9a 10 63 4c  or  %g1, 0x34c, %o5
a0107d74:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a0107d78:  9a 13 63 4c  or  %o5, 0x34c, %o5	! 0xcf03c34c
a0107d7c:  d2 03 40 00  ld  [ %o5 ], %o1
a0107d80:  10 bf ff cb  b  0xa0107cac
a0107d84:  82 12 60 40  or  %o1, 0x40, %g1
a0107d88:  80 a2 a0 00  cmp  %o2, 0
a0107d8c:  02 80 00 18  be  0xa0107dec
a0107d90:  15 33 c0 f0  sethi  %hi(0xcf03c000), %o2
a0107d94:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a0107d98:  9a 13 63 4c  or  %o5, 0x34c, %o5	! 0xcf03c34c
a0107d9c:  c2 03 40 00  ld  [ %o5 ], %g1
a0107da0:  10 bf ff c3  b  0xa0107cac
a0107da4:  82 10 60 08  or  %g1, 8, %g1
a0107da8:  17 33 c0 f0  sethi  %hi(0xcf03c000), %o3
a0107dac:  80 a2 a0 00  cmp  %o2, 0
a0107db0:  12 bf ff de  bne  0xa0107d28
a0107db4:  9a 12 e3 48  or  %o3, 0x348, %o5
a0107db8:  19 33 c0 f0  sethi  %hi(0xcf03c000), %o4
a0107dbc:  9a 13 23 48  or  %o4, 0x348, %o5	! 0xcf03c348
a0107dc0:  d2 03 40 00  ld  [ %o5 ], %o1
a0107dc4:  10 bf ff ba  b  0xa0107cac
a0107dc8:  82 0a 7f 7f  and  %o1, -129, %g1
a0107dcc:  80 a2 a0 00  cmp  %o2, 0
a0107dd0:  22 80 00 0b  be,a   0xa0107dfc
a0107dd4:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a0107dd8:  19 33 c0 f0  sethi  %hi(0xcf03c000), %o4
a0107ddc:  9a 13 23 4c  or  %o4, 0x34c, %o5	! 0xcf03c34c
a0107de0:  d6 03 40 00  ld  [ %o5 ], %o3
a0107de4:  10 bf ff b2  b  0xa0107cac
a0107de8:  82 12 e0 10  or  %o3, 0x10, %g1
a0107dec:  9a 12 a3 4c  or  %o2, 0x34c, %o5
a0107df0:  d2 03 40 00  ld  [ %o5 ], %o1
a0107df4:  10 bf ff ae  b  0xa0107cac
a0107df8:  82 0a 7f f7  and  %o1, -9, %g1
a0107dfc:  9a 13 63 4c  or  %o5, 0x34c, %o5
a0107e00:  c2 03 40 00  ld  [ %o5 ], %g1
a0107e04:  10 bf ff aa  b  0xa0107cac
a0107e08:  82 08 7f ef  and  %g1, -17, %g1
a0107e0c:  80 a2 a0 00  cmp  %o2, 0
a0107e10:  02 80 00 07  be  0xa0107e2c
a0107e14:  19 33 c0 f0  sethi  %hi(0xcf03c000), %o4
a0107e18:  15 33 c0 f0  sethi  %hi(0xcf03c000), %o2
a0107e1c:  9a 12 a3 4c  or  %o2, 0x34c, %o5	! 0xcf03c34c
a0107e20:  d2 03 40 00  ld  [ %o5 ], %o1
a0107e24:  10 bf ff a2  b  0xa0107cac
a0107e28:  82 12 60 20  or  %o1, 0x20, %g1
a0107e2c:  9a 13 23 4c  or  %o4, 0x34c, %o5
a0107e30:  d6 03 40 00  ld  [ %o5 ], %o3
a0107e34:  10 bf ff 9e  b  0xa0107cac
a0107e38:  82 0a ff df  and  %o3, -33, %g1
a0107e3c:  81 c3 e0 08  retl
a0107e40:  01 00 00 00  nop
