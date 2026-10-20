# leon2s FUN_a00d7cd0 0xa00d7cd0-0xa00d7e6c (412 bytes)
a00d7cd0:  9d e3 bf 98  save  %sp, -104, %sp
a00d7cd4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d7cd8:  fa 08 60 32  ldub  [ %g1 + 0x32 ], %i5	! 0xa8078832
a00d7cdc:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d7ce0:  82 10 60 28  or  %g1, 0x28, %g1	! 0xa8078828
a00d7ce4:  f6 08 40 1d  ldub  [ %g1 + %i5 ], %i3
a00d7ce8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d7cec:  82 10 60 30  or  %g1, 0x30, %g1	! 0xa8078830
a00d7cf0:  f8 08 40 1d  ldub  [ %g1 + %i5 ], %i4
a00d7cf4:  ba 26 c0 1c  sub  %i3, %i4, %i5
a00d7cf8:  82 10 20 10  mov  0x10, %g1
a00d7cfc:  9e 20 40 1d  sub  %g1, %i5, %o7
a00d7d00:  80 a6 c0 1c  cmp  %i3, %i4
a00d7d04:  9a 10 20 00  clr  %o5
a00d7d08:  18 80 00 03  bgu  0xa00d7d14
a00d7d0c:  94 10 20 00  clr  %o2
a00d7d10:  9e 27 00 1b  sub  %i4, %i3, %o7
a00d7d14:  98 0b e0 ff  and  %o7, 0xff, %o4
a00d7d18:  80 a3 20 00  cmp  %o4, 0
a00d7d1c:  02 80 00 3d  be  0xa00d7e10
a00d7d20:  b6 10 20 00  clr  %i3
a00d7d24:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d7d28:  f8 08 60 32  ldub  [ %g1 + 0x32 ], %i4	! 0xa8078832
a00d7d2c:  ba 07 00 1c  add  %i4, %i4, %i5
a00d7d30:  ba 07 40 1c  add  %i5, %i4, %i5
a00d7d34:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00d7d38:  82 10 62 3d  or  %g1, 0x23d, %g1	! 0xa807963d
a00d7d3c:  bb 2f 60 08  sll  %i5, 8, %i5
a00d7d40:  b2 07 40 01  add  %i5, %g1, %i1
a00d7d44:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d7d48:  82 10 60 28  or  %g1, 0x28, %g1	! 0xa8078828
a00d7d4c:  d6 08 40 1c  ldub  [ %g1 + %i4 ], %o3
a00d7d50:  b4 0e e0 ff  and  %i3, 0xff, %i2
a00d7d54:  82 02 c0 1a  add  %o3, %i2, %g1
a00d7d58:  82 08 60 0f  and  %g1, 0xf, %g1
a00d7d5c:  b8 00 40 01  add  %g1, %g1, %i4
a00d7d60:  b8 07 00 01  add  %i4, %g1, %i4
a00d7d64:  83 2f 20 04  sll  %i4, 4, %g1
a00d7d68:  fa 0e 40 01  ldub  [ %i1 + %g1 ], %i5
a00d7d6c:  bb 37 60 04  srl  %i5, 4, %i5
a00d7d70:  ba 07 7f ff  add  %i5, -1, %i5
a00d7d74:  b0 06 40 01  add  %i1, %g1, %i0
a00d7d78:  83 37 60 1f  srl  %i5, 0x1f, %g1
a00d7d7c:  82 07 40 01  add  %i5, %g1, %g1
a00d7d80:  b9 2f 20 04  sll  %i4, 4, %i4
a00d7d84:  83 38 60 01  sra  %g1, 1, %g1
a00d7d88:  80 8f 60 01  btst  1, %i5
a00d7d8c:  b8 0f 23 f0  and  %i4, 0x3f0, %i4
a00d7d90:  ba 10 00 01  mov  %g1, %i5
a00d7d94:  02 80 00 03  be  0xa00d7da0
a00d7d98:  b8 06 40 1c  add  %i1, %i4, %i4
a00d7d9c:  ba 00 60 01  add  %g1, 1, %i5
a00d7da0:  82 0f 60 ff  and  %i5, 0xff, %g1
a00d7da4:  b8 07 00 01  add  %i4, %g1, %i4
a00d7da8:  80 a6 a0 00  cmp  %i2, 0
a00d7dac:  12 80 00 06  bne  0xa00d7dc4
a00d7db0:  82 06 00 01  add  %i0, %g1, %g1
a00d7db4:  c2 48 60 02  ldsb  [ %g1 + 2 ], %g1
a00d7db8:  80 a0 60 00  cmp  %g1, 0
a00d7dbc:  26 80 00 02  bl,a   0xa00d7dc4
a00d7dc0:  94 10 20 01  mov  1, %o2
a00d7dc4:  c2 0f 20 02  ldub  [ %i4 + 2 ], %g1
a00d7dc8:  80 88 60 40  btst  0x40, %g1
a00d7dcc:  02 80 00 07  be  0xa00d7de8
a00d7dd0:  bb 30 60 07  srl  %g1, 7, %i5
a00d7dd4:  80 8a a0 ff  btst  0xff, %o2
a00d7dd8:  12 80 00 0f  bne  0xa00d7e14
a00d7ddc:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00d7de0:  10 80 00 0c  b  0xa00d7e10
a00d7de4:  9a 10 20 01  mov  1, %o5
a00d7de8:  80 a0 00 1a  cmp  %g0, %i2
a00d7dec:  82 40 20 00  addx  %g0, 0, %g1
a00d7df0:  80 8f 40 01  btst  %i5, %g1
a00d7df4:  32 bf ff fb  bne,a   0xa00d7de0
a00d7df8:  b6 06 ff ff  add  %i3, -1, %i3
a00d7dfc:  b6 06 e0 01  inc  %i3
a00d7e00:  82 0e e0 ff  and  %i3, 0xff, %g1
a00d7e04:  80 a0 40 0c  cmp  %g1, %o4
a00d7e08:  0a bf ff d3  bcs  0xa00d7d54
a00d7e0c:  b4 0e e0 ff  and  %i3, 0xff, %i2
a00d7e10:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00d7e14:  82 0b e0 ff  and  %o7, 0xff, %g1
a00d7e18:  80 a7 00 01  cmp  %i4, %g1
a00d7e1c:  1a 80 00 12  bcc  0xa00d7e64
a00d7e20:  b0 10 20 80  mov  0x80, %i0
a00d7e24:  80 8b 60 ff  btst  0xff, %o5
a00d7e28:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d7e2c:  02 80 00 09  be  0xa00d7e50
a00d7e30:  3b 2a 01 e2  sethi  %hi(0xa8078800), %i5
a00d7e34:  ba 17 60 28  or  %i5, 0x28, %i5	! 0xa8078828
a00d7e38:  c2 08 60 32  ldub  [ %g1 + 0x32 ], %g1
a00d7e3c:  c2 0f 40 01  ldub  [ %i5 + %g1 ], %g1
a00d7e40:  82 00 40 1c  add  %g1, %i4, %g1
a00d7e44:  82 08 60 0f  and  %g1, 0xf, %g1
a00d7e48:  10 80 00 07  b  0xa00d7e64
a00d7e4c:  b0 10 60 40  or  %g1, 0x40, %i0
a00d7e50:  ba 17 60 28  or  %i5, 0x28, %i5
a00d7e54:  c2 08 60 32  ldub  [ %g1 + 0x32 ], %g1
a00d7e58:  c2 0f 40 01  ldub  [ %i5 + %g1 ], %g1
a00d7e5c:  82 00 40 1c  add  %g1, %i4, %g1
a00d7e60:  b0 08 60 0f  and  %g1, 0xf, %i0
a00d7e64:  81 c7 e0 08  ret
a00d7e68:  81 e8 00 00  restore
