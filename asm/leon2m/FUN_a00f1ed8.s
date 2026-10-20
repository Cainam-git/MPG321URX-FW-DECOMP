# leon2m FUN_a00f1ed8 0xa00f1ed8-0xa00f1f9c (196 bytes)
a00f1ed8:  9d e3 bf 98  save  %sp, -104, %sp
a00f1edc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f1ee0:  80 a6 20 07  cmp  %i0, 7
a00f1ee4:  08 80 00 1b  bleu  0xa00f1f50
a00f1ee8:  9e 10 00 1a  mov  %i2, %o7
a00f1eec:  bb 2e a0 10  sll  %i2, 0x10, %i5
a00f1ef0:  b8 0e a0 ff  and  %i2, 0xff, %i4
a00f1ef4:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f1ef8:  b5 37 60 18  srl  %i5, 0x18, %i2
a00f1efc:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00f1f00:  9e 10 63 0c  or  %g1, 0x30c, %o7
a00f1f04:  b6 10 20 00  clr  %i3
a00f1f08:  ba 10 20 00  clr  %i5
a00f1f0c:  31 33 c0 00  sethi  %hi(0xcf000000), %i0
a00f1f10:  82 07 40 1d  add  %i5, %i5, %g1
a00f1f14:  fa 13 c0 01  lduh  [ %o7 + %g1 ], %i5
a00f1f18:  ba 07 40 19  add  %i5, %i1, %i5
a00f1f1c:  82 07 60 01  add  %i5, 1, %g1
a00f1f20:  bb 2f 60 02  sll  %i5, 2, %i5
a00f1f24:  ba 17 40 18  or  %i5, %i0, %i5
a00f1f28:  f8 27 40 00  st  %i4, [ %i5 ]
a00f1f2c:  83 28 60 02  sll  %g1, 2, %g1
a00f1f30:  b6 06 e0 01  inc  %i3
a00f1f34:  82 10 40 18  or  %g1, %i0, %g1
a00f1f38:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00f1f3c:  f4 20 40 00  st  %i2, [ %g1 ]
a00f1f40:  80 a7 60 07  cmp  %i5, 7
a00f1f44:  08 bf ff f4  bleu  0xa00f1f14
a00f1f48:  82 07 40 1d  add  %i5, %i5, %g1
a00f1f4c:  30 80 00 12  b,a   0xa00f1f94
a00f1f50:  37 00 06 68  sethi  %hi(0x19a000), %i3
a00f1f54:  ba 06 00 18  add  %i0, %i0, %i5
a00f1f58:  b8 16 e3 0c  or  %i3, 0x30c, %i4
a00f1f5c:  f4 17 00 1d  lduh  [ %i4 + %i5 ], %i2
a00f1f60:  82 0e 60 ff  and  %i1, 0xff, %g1
a00f1f64:  b2 06 80 01  add  %i2, %g1, %i1
a00f1f68:  b6 06 60 01  add  %i1, 1, %i3
a00f1f6c:  b1 2e 60 02  sll  %i1, 2, %i0
a00f1f70:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a00f1f74:  ba 16 00 1a  or  %i0, %i2, %i5
a00f1f78:  b8 0b e0 ff  and  %o7, 0xff, %i4
a00f1f7c:  83 2e e0 02  sll  %i3, 2, %g1
a00f1f80:  b3 2b e0 10  sll  %o7, 0x10, %i1
a00f1f84:  f8 27 40 00  st  %i4, [ %i5 ]
a00f1f88:  b6 10 40 1a  or  %g1, %i2, %i3
a00f1f8c:  b1 36 60 18  srl  %i1, 0x18, %i0
a00f1f90:  f0 26 c0 00  st  %i0, [ %i3 ]
a00f1f94:  81 c7 e0 08  ret
a00f1f98:  81 e8 00 00  restore
