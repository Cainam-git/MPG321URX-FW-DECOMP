# leon2m FUN_a0101d9c 0xa0101d9c-0xa0101e24 (136 bytes)
a0101d9c:  9d e3 bf 98  save  %sp, -104, %sp
a0101da0:  1f 33 c0 3b  sethi  %hi(0xcf00ec00), %o7
a0101da4:  ba 13 e0 04  or  %o7, 4, %i5	! 0xcf00ec04
a0101da8:  b9 36 20 08  srl  %i0, 8, %i4
a0101dac:  c0 27 40 00  clr  [ %i5 ]
a0101db0:  82 13 e0 08  or  %o7, 8, %g1
a0101db4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0101db8:  f0 20 40 00  st  %i0, [ %g1 ]
a0101dbc:  ba 0f 20 1f  and  %i4, 0x1f, %i5
a0101dc0:  82 13 e0 0c  or  %o7, 0xc, %g1
a0101dc4:  fa 20 40 00  st  %i5, [ %g1 ]
a0101dc8:  b8 13 e0 10  or  %o7, 0x10, %i4
a0101dcc:  b0 0e 60 ff  and  %i1, 0xff, %i0
a0101dd0:  f0 27 00 00  st  %i0, [ %i4 ]
a0101dd4:  bb 36 60 08  srl  %i1, 8, %i5
a0101dd8:  b2 0f 60 1f  and  %i5, 0x1f, %i1
a0101ddc:  82 13 e0 14  or  %o7, 0x14, %g1
a0101de0:  b9 36 a0 08  srl  %i2, 8, %i4
a0101de4:  f2 20 40 00  st  %i1, [ %g1 ]
a0101de8:  b0 13 e0 18  or  %o7, 0x18, %i0
a0101dec:  b4 0e a0 ff  and  %i2, 0xff, %i2
a0101df0:  f4 26 00 00  st  %i2, [ %i0 ]
a0101df4:  ba 0f 20 1f  and  %i4, 0x1f, %i5
a0101df8:  b2 13 e0 1c  or  %o7, 0x1c, %i1
a0101dfc:  b1 36 e0 08  srl  %i3, 8, %i0
a0101e00:  fa 26 40 00  st  %i5, [ %i1 ]
a0101e04:  82 13 e0 20  or  %o7, 0x20, %g1
a0101e08:  b6 0e e0 ff  and  %i3, 0xff, %i3
a0101e0c:  f6 20 40 00  st  %i3, [ %g1 ]
a0101e10:  9e 13 e0 24  or  %o7, 0x24, %o7
a0101e14:  b8 0e 20 1f  and  %i0, 0x1f, %i4
a0101e18:  f8 23 c0 00  st  %i4, [ %o7 ]
a0101e1c:  81 c7 e0 08  ret
a0101e20:  81 e8 00 00  restore
