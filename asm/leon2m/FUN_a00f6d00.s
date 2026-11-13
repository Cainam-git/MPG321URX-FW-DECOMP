# leon2m FUN_a00f6d00 0xa00f6d00-0xa00f6d80 (128 bytes)
a00f6d00:  9d e3 bf 98  save  %sp, -104, %sp
a00f6d04:  1f 33 c0 3b  sethi  %hi(0xcf00ec00), %o7
a00f6d08:  bb 2e 20 10  sll  %i0, 0x10, %i5
a00f6d0c:  82 13 e0 88  or  %o7, 0x88, %g1
a00f6d10:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f6d14:  f0 20 40 00  st  %i0, [ %g1 ]
a00f6d18:  b9 37 60 18  srl  %i5, 0x18, %i4
a00f6d1c:  82 13 e0 8c  or  %o7, 0x8c, %g1
a00f6d20:  f8 20 40 00  st  %i4, [ %g1 ]
a00f6d24:  ba 13 e0 90  or  %o7, 0x90, %i5
a00f6d28:  b0 0e a0 ff  and  %i2, 0xff, %i0
a00f6d2c:  b9 2e a0 10  sll  %i2, 0x10, %i4
a00f6d30:  f0 27 40 00  st  %i0, [ %i5 ]
a00f6d34:  b5 37 20 18  srl  %i4, 0x18, %i2
a00f6d38:  82 13 e0 94  or  %o7, 0x94, %g1
a00f6d3c:  f4 20 40 00  st  %i2, [ %g1 ]
a00f6d40:  ba 13 e0 98  or  %o7, 0x98, %i5
a00f6d44:  b0 0e 60 ff  and  %i1, 0xff, %i0
a00f6d48:  f0 27 40 00  st  %i0, [ %i5 ]
a00f6d4c:  b9 2e 60 10  sll  %i1, 0x10, %i4
a00f6d50:  b2 13 e0 9c  or  %o7, 0x9c, %i1
a00f6d54:  b1 2e e0 10  sll  %i3, 0x10, %i0
a00f6d58:  b5 37 20 18  srl  %i4, 0x18, %i2
a00f6d5c:  f4 26 40 00  st  %i2, [ %i1 ]
a00f6d60:  82 13 e0 a0  or  %o7, 0xa0, %g1
a00f6d64:  b6 0e e0 ff  and  %i3, 0xff, %i3
a00f6d68:  f6 20 40 00  st  %i3, [ %g1 ]
a00f6d6c:  9e 13 e0 a4  or  %o7, 0xa4, %o7
a00f6d70:  bb 36 20 18  srl  %i0, 0x18, %i5
a00f6d74:  fa 23 c0 00  st  %i5, [ %o7 ]
a00f6d78:  81 c7 e0 08  ret
a00f6d7c:  81 e8 00 00  restore
