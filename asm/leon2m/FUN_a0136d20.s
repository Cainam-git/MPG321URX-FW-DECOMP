# leon2m FUN_a0136d20 0xa0136d20-0xa0136e9c (380 bytes)
a0136d20:  9d e3 bf 98  save  %sp, -104, %sp
a0136d24:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0136d28:  80 a6 20 01  cmp  %i0, 1
a0136d2c:  02 80 00 0b  be  0xa0136d58
a0136d30:  b2 10 20 00  clr  %i1
a0136d34:  80 a6 20 01  cmp  %i0, 1
a0136d38:  04 80 00 0c  ble  0xa0136d68
a0136d3c:  80 a6 20 02  cmp  %i0, 2
a0136d40:  02 80 00 08  be  0xa0136d60
a0136d44:  80 a6 20 03  cmp  %i0, 3
a0136d48:  12 80 00 0e  bne  0xa0136d80
a0136d4c:  b7 2e 20 03  sll  %i0, 3, %i3
a0136d50:  10 80 00 0c  b  0xa0136d80
a0136d54:  b2 10 20 05  mov  5, %i1
a0136d58:  10 80 00 09  b  0xa0136d7c
a0136d5c:  b2 10 20 03  mov  3, %i1
a0136d60:  10 80 00 07  b  0xa0136d7c
a0136d64:  b2 10 20 04  mov  4, %i1
a0136d68:  80 a6 20 00  cmp  %i0, 0
a0136d6c:  22 80 00 04  be,a   0xa0136d7c
a0136d70:  b2 10 20 02  mov  2, %i1
a0136d74:  10 80 00 03  b  0xa0136d80
a0136d78:  b7 2e 20 03  sll  %i0, 3, %i3
a0136d7c:  b7 2e 20 03  sll  %i0, 3, %i3
a0136d80:  9e 06 c0 18  add  %i3, %i0, %o7
a0136d84:  b0 0e 60 ff  and  %i1, 0xff, %i0
a0136d88:  35 2a 00 b7  sethi  %hi(0xa802dc00), %i2
a0136d8c:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a0136d90:  9a 13 61 16  or  %o5, 0x116, %o5	! 0xa802e116
a0136d94:  9e 03 c0 0f  add  %o7, %o7, %o7
a0136d98:  b8 16 a2 c0  or  %i2, 0x2c0, %i4
a0136d9c:  b3 2e 20 04  sll  %i0, 4, %i1
a0136da0:  fa 0f 00 19  ldub  [ %i4 + %i1 ], %i5
a0136da4:  c2 13 40 0f  lduh  [ %o5 + %o7 ], %g1
a0136da8:  b7 2f 60 0c  sll  %i5, 0xc, %i3
a0136dac:  b4 08 6f ff  and  %g1, 0xfff, %i2
a0136db0:  b0 16 80 1b  or  %i2, %i3, %i0
a0136db4:  f0 33 40 0f  sth  %i0, [ %o5 + %o7 ]
a0136db8:  b2 06 40 1c  add  %i1, %i4, %i1
a0136dbc:  c2 0e 60 01  ldub  [ %i1 + 1 ], %g1
a0136dc0:  fa 16 60 02  lduh  [ %i1 + 2 ], %i5
a0136dc4:  f8 16 60 04  lduh  [ %i1 + 4 ], %i4
a0136dc8:  f6 16 60 06  lduh  [ %i1 + 6 ], %i3
a0136dcc:  f4 16 60 08  lduh  [ %i1 + 8 ], %i2
a0136dd0:  d8 16 60 0a  lduh  [ %i1 + 0xa ], %o4
a0136dd4:  d6 0e 60 0e  ldub  [ %i1 + 0xe ], %o3
a0136dd8:  b0 03 c0 0d  add  %o7, %o5, %i0
a0136ddc:  fa 36 20 06  sth  %i5, [ %i0 + 6 ]
a0136de0:  f8 36 20 08  sth  %i4, [ %i0 + 8 ]
a0136de4:  f4 36 20 0c  sth  %i2, [ %i0 + 0xc ]
a0136de8:  c2 2e 20 04  stb  %g1, [ %i0 + 4 ]
a0136dec:  f6 36 20 0a  sth  %i3, [ %i0 + 0xa ]
a0136df0:  d8 36 20 0e  sth  %o4, [ %i0 + 0xe ]
a0136df4:  d6 2e 20 05  stb  %o3, [ %i0 + 5 ]
a0136df8:  c2 0e 60 0c  ldub  [ %i1 + 0xc ], %g1
a0136dfc:  b4 10 00 01  mov  %g1, %i2
a0136e00:  f6 13 40 0f  lduh  [ %o5 + %o7 ], %i3
a0136e04:  ba 08 60 01  and  %g1, 1, %i5
a0136e08:  b9 2f 60 06  sll  %i5, 6, %i4
a0136e0c:  82 0e ff 9f  and  %i3, -97, %g1
a0136e10:  bb 2e a0 04  sll  %i2, 4, %i5
a0136e14:  b6 10 40 1c  or  %g1, %i4, %i3
a0136e18:  b8 0f 60 20  and  %i5, 0x20, %i4
a0136e1c:  82 16 c0 1c  or  %i3, %i4, %g1
a0136e20:  bb 2e a0 02  sll  %i2, 2, %i5
a0136e24:  b8 0f 60 10  and  %i5, 0x10, %i4
a0136e28:  b6 08 7f e7  and  %g1, -25, %i3
a0136e2c:  82 16 c0 1c  or  %i3, %i4, %g1
a0136e30:  ba 0e a0 08  and  %i2, 8, %i5
a0136e34:  b8 10 40 1d  or  %g1, %i5, %i4
a0136e38:  b7 36 a0 02  srl  %i2, 2, %i3
a0136e3c:  ba 0e e0 04  and  %i3, 4, %i5
a0136e40:  82 0f 3f fb  and  %i4, -5, %g1
a0136e44:  b8 10 40 1d  or  %g1, %i5, %i4
a0136e48:  f8 33 40 0f  sth  %i4, [ %o5 + %o7 ]
a0136e4c:  b7 36 a0 05  srl  %i2, 5, %i3
a0136e50:  c2 16 20 02  lduh  [ %i0 + 2 ], %g1
a0136e54:  b8 0e e0 01  and  %i3, 1, %i4
a0136e58:  3b 3f ff e0  sethi  %hi(0xffff8000), %i5
a0136e5c:  b6 28 40 1d  andn  %g1, %i5, %i3
a0136e60:  b9 2f 20 0f  sll  %i4, 0xf, %i4
a0136e64:  ba 16 c0 1c  or  %i3, %i4, %i5
a0136e68:  fa 36 20 02  sth  %i5, [ %i0 + 2 ]
a0136e6c:  c2 13 40 0f  lduh  [ %o5 + %o7 ], %g1
a0136e70:  b7 36 a0 05  srl  %i2, 5, %i3
a0136e74:  ba 0e e0 02  and  %i3, 2, %i5
a0136e78:  b8 08 7f fc  and  %g1, -4, %i4
a0136e7c:  b6 17 00 1d  or  %i4, %i5, %i3
a0136e80:  b5 36 a0 07  srl  %i2, 7, %i2
a0136e84:  82 16 c0 1a  or  %i3, %i2, %g1
a0136e88:  c2 33 40 0f  sth  %g1, [ %o5 + %o7 ]
a0136e8c:  fa 0e 60 0d  ldub  [ %i1 + 0xd ], %i5
a0136e90:  fa 2e 20 03  stb  %i5, [ %i0 + 3 ]
a0136e94:  81 c7 e0 08  ret
a0136e98:  81 e8 00 00  restore
