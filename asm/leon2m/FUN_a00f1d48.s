# leon2m FUN_a00f1d48 0xa00f1d48-0xa00f1e0c (196 bytes)
a00f1d48:  9d e3 bf 98  save  %sp, -104, %sp
a00f1d4c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f1d50:  80 a6 20 07  cmp  %i0, 7
a00f1d54:  08 80 00 1b  bleu  0xa00f1dc0
a00f1d58:  9e 10 00 1a  mov  %i2, %o7
a00f1d5c:  bb 2e a0 10  sll  %i2, 0x10, %i5
a00f1d60:  b8 0e a0 ff  and  %i2, 0xff, %i4
a00f1d64:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f1d68:  b5 37 60 18  srl  %i5, 0x18, %i2
a00f1d6c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00f1d70:  9e 10 63 1c  or  %g1, 0x31c, %o7
a00f1d74:  b6 10 20 00  clr  %i3
a00f1d78:  ba 10 20 00  clr  %i5
a00f1d7c:  31 33 c0 00  sethi  %hi(0xcf000000), %i0
a00f1d80:  82 07 40 1d  add  %i5, %i5, %g1
a00f1d84:  fa 13 c0 01  lduh  [ %o7 + %g1 ], %i5
a00f1d88:  ba 07 40 19  add  %i5, %i1, %i5
a00f1d8c:  82 07 60 01  add  %i5, 1, %g1
a00f1d90:  bb 2f 60 02  sll  %i5, 2, %i5
a00f1d94:  ba 17 40 18  or  %i5, %i0, %i5
a00f1d98:  f8 27 40 00  st  %i4, [ %i5 ]
a00f1d9c:  83 28 60 02  sll  %g1, 2, %g1
a00f1da0:  b6 06 e0 01  inc  %i3
a00f1da4:  82 10 40 18  or  %g1, %i0, %g1
a00f1da8:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00f1dac:  f4 20 40 00  st  %i2, [ %g1 ]
a00f1db0:  80 a7 60 07  cmp  %i5, 7
a00f1db4:  08 bf ff f4  bleu  0xa00f1d84
a00f1db8:  82 07 40 1d  add  %i5, %i5, %g1
a00f1dbc:  30 80 00 12  b,a   0xa00f1e04
a00f1dc0:  37 00 06 68  sethi  %hi(0x19a000), %i3
a00f1dc4:  ba 06 00 18  add  %i0, %i0, %i5
a00f1dc8:  b8 16 e3 1c  or  %i3, 0x31c, %i4
a00f1dcc:  f4 17 00 1d  lduh  [ %i4 + %i5 ], %i2
a00f1dd0:  82 0e 60 ff  and  %i1, 0xff, %g1
a00f1dd4:  b2 06 80 01  add  %i2, %g1, %i1
a00f1dd8:  b6 06 60 01  add  %i1, 1, %i3
a00f1ddc:  b1 2e 60 02  sll  %i1, 2, %i0
a00f1de0:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a00f1de4:  ba 16 00 1a  or  %i0, %i2, %i5
a00f1de8:  b8 0b e0 ff  and  %o7, 0xff, %i4
a00f1dec:  83 2e e0 02  sll  %i3, 2, %g1
a00f1df0:  b3 2b e0 10  sll  %o7, 0x10, %i1
a00f1df4:  f8 27 40 00  st  %i4, [ %i5 ]
a00f1df8:  b6 10 40 1a  or  %g1, %i2, %i3
a00f1dfc:  b1 36 60 18  srl  %i1, 0x18, %i0
a00f1e00:  f0 26 c0 00  st  %i0, [ %i3 ]
a00f1e04:  81 c7 e0 08  ret
a00f1e08:  81 e8 00 00  restore
