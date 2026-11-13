# leon2s FUN_a00d9d50 0xa00d9d50-0xa00d9e44 (244 bytes)
a00d9d50:  9d e3 bf 98  save  %sp, -104, %sp
a00d9d54:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00d9d58:  1f 2a 01 e1  sethi  %hi(0xa8078400), %o7
a00d9d5c:  f6 08 63 fd  ldub  [ %g1 + 0x3fd ], %i3
a00d9d60:  f8 0b e3 fc  ldub  [ %o7 + 0x3fc ], %i4
a00d9d64:  b2 0e e0 ff  and  %i3, 0xff, %i1
a00d9d68:  b4 0f 20 ff  and  %i4, 0xff, %i2
a00d9d6c:  ba 27 00 1b  sub  %i4, %i3, %i5
a00d9d70:  82 10 20 10  mov  0x10, %g1
a00d9d74:  80 a6 40 1a  cmp  %i1, %i2
a00d9d78:  0a 80 00 06  bcs  0xa00d9d90
a00d9d7c:  b0 20 40 1d  sub  %g1, %i5, %i0
a00d9d80:  80 a6 40 1a  cmp  %i1, %i2
a00d9d84:  02 80 00 2e  be  0xa00d9e3c
a00d9d88:  b0 10 20 ff  mov  0xff, %i0
a00d9d8c:  b0 26 c0 1c  sub  %i3, %i4, %i0
a00d9d90:  b2 0e 20 ff  and  %i0, 0xff, %i1
a00d9d94:  80 a6 60 00  cmp  %i1, 0
a00d9d98:  02 80 00 20  be  0xa00d9e18
a00d9d9c:  b4 10 20 00  clr  %i2
a00d9da0:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00d9da4:  de 0b e3 fc  ldub  [ %o7 + 0x3fc ], %o7
a00d9da8:  9a 10 60 98  or  %g1, 0x98, %o5
a00d9dac:  82 03 c0 1a  add  %o7, %i2, %g1
a00d9db0:  82 08 60 0f  and  %g1, 0xf, %g1
a00d9db4:  b8 00 40 01  add  %g1, %g1, %i4
a00d9db8:  b8 07 00 01  add  %i4, %g1, %i4
a00d9dbc:  b9 2f 20 04  sll  %i4, 4, %i4
a00d9dc0:  fa 0b 40 1c  ldub  [ %o5 + %i4 ], %i5
a00d9dc4:  bb 37 60 04  srl  %i5, 4, %i5
a00d9dc8:  ba 07 7f ff  add  %i5, -1, %i5
a00d9dcc:  83 37 60 1f  srl  %i5, 0x1f, %g1
a00d9dd0:  82 07 40 01  add  %i5, %g1, %g1
a00d9dd4:  b7 38 60 01  sra  %g1, 1, %i3
a00d9dd8:  b8 07 00 0d  add  %i4, %o5, %i4
a00d9ddc:  80 8f 60 01  btst  1, %i5
a00d9de0:  02 80 00 03  be  0xa00d9dec
a00d9de4:  82 10 00 1b  mov  %i3, %g1
a00d9de8:  82 06 e0 01  add  %i3, 1, %g1
a00d9dec:  82 08 60 ff  and  %g1, 0xff, %g1
a00d9df0:  82 07 00 01  add  %i4, %g1, %g1
a00d9df4:  c2 08 60 02  ldub  [ %g1 + 2 ], %g1
a00d9df8:  80 88 60 40  btst  0x40, %g1
a00d9dfc:  12 80 00 08  bne  0xa00d9e1c
a00d9e00:  82 0e 20 ff  and  %i0, 0xff, %g1
a00d9e04:  b4 06 a0 01  inc  %i2
a00d9e08:  82 0e a0 ff  and  %i2, 0xff, %g1
a00d9e0c:  80 a0 40 19  cmp  %g1, %i1
a00d9e10:  0a bf ff e8  bcs  0xa00d9db0
a00d9e14:  82 03 c0 1a  add  %o7, %i2, %g1
a00d9e18:  82 0e 20 ff  and  %i0, 0xff, %g1
a00d9e1c:  ba 0e a0 ff  and  %i2, 0xff, %i5
a00d9e20:  80 a7 40 01  cmp  %i5, %g1
a00d9e24:  1a 80 00 06  bcc  0xa00d9e3c
a00d9e28:  b0 10 20 ff  mov  0xff, %i0
a00d9e2c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00d9e30:  c2 08 63 fc  ldub  [ %g1 + 0x3fc ], %g1	! 0xa80787fc
a00d9e34:  82 00 40 1d  add  %g1, %i5, %g1
a00d9e38:  b0 08 60 0f  and  %g1, 0xf, %i0
a00d9e3c:  81 c7 e0 08  ret
a00d9e40:  81 e8 00 00  restore
