# leon2m FUN_a0122e24 0xa0122e24-0xa0122e80 (92 bytes)
a0122e24:  9d e3 bf 98  save  %sp, -104, %sp
a0122e28:  35 33 c0 f4  sethi  %hi(0xcf03d000), %i2
a0122e2c:  b4 16 a0 24  or  %i2, 0x24, %i2	! 0xcf03d024
a0122e30:  3b 33 c0 46  sethi  %hi(0xcf011800), %i5
a0122e34:  da 06 80 00  ld  [ %i2 ], %o5
a0122e38:  9e 17 60 24  or  %i5, 0x24, %o7
a0122e3c:  f6 03 c0 00  ld  [ %o7 ], %i3
a0122e40:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0122e44:  f0 26 80 00  st  %i0, [ %i2 ]
a0122e48:  b8 17 60 20  or  %i5, 0x20, %i4
a0122e4c:  82 10 20 76  mov  0x76, %g1
a0122e50:  c2 27 00 00  st  %g1, [ %i4 ]
a0122e54:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0122e58:  f2 23 c0 00  st  %i1, [ %o7 ]
a0122e5c:  ba 17 60 28  or  %i5, 0x28, %i5
a0122e60:  f0 07 40 00  ld  [ %i5 ], %i0
a0122e64:  b6 0e e0 ff  and  %i3, 0xff, %i3
a0122e68:  f6 23 c0 00  st  %i3, [ %o7 ]
a0122e6c:  9a 0b 60 ff  and  %o5, 0xff, %o5
a0122e70:  da 26 80 00  st  %o5, [ %i2 ]
a0122e74:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0122e78:  81 c7 e0 08  ret
a0122e7c:  81 e8 00 00  restore
