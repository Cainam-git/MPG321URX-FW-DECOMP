# leon2m FUN_a0101bb0 0xa0101bb0-0xa0101c64 (180 bytes)
a0101bb0:  9d e3 bf 98  save  %sp, -104, %sp
a0101bb4:  03 33 c0 58  sethi  %hi(0xcf016000), %g1
a0101bb8:  80 8e 20 ff  btst  0xff, %i0
a0101bbc:  b4 10 61 18  or  %g1, 0x118, %i2
a0101bc0:  b8 10 60 c4  or  %g1, 0xc4, %i4
a0101bc4:  b2 10 60 d8  or  %g1, 0xd8, %i1
a0101bc8:  9a 10 61 04  or  %g1, 0x104, %o5
a0101bcc:  9e 10 61 0c  or  %g1, 0x10c, %o7
a0101bd0:  98 10 61 10  or  %g1, 0x110, %o4
a0101bd4:  96 10 61 14  or  %g1, 0x114, %o3
a0101bd8:  37 2a 00 b2  sethi  %hi(0xa802c800), %i3
a0101bdc:  02 80 00 11  be  0xa0101c20
a0101be0:  b0 10 20 01  mov  1, %i0
a0101be4:  c2 06 80 00  ld  [ %i2 ], %g1
a0101be8:  ba 08 7f bf  and  %g1, -65, %i5
a0101bec:  fa 26 80 00  st  %i5, [ %i2 ]
a0101bf0:  c0 27 00 00  clr  [ %i4 ]
a0101bf4:  f4 07 00 00  ld  [ %i4 ], %i2
a0101bf8:  82 16 a0 02  or  %i2, 2, %g1
a0101bfc:  c2 27 00 00  st  %g1, [ %i4 ]
a0101c00:  fa 06 40 00  ld  [ %i1 ], %i5
a0101c04:  b8 0f 60 f0  and  %i5, 0xf0, %i4
a0101c08:  f8 26 40 00  st  %i4, [ %i1 ]
a0101c0c:  c0 23 40 00  clr  [ %o5 ]
a0101c10:  f4 03 c0 00  ld  [ %o7 ], %i2
a0101c14:  b2 0e bf fe  and  %i2, -2, %i1
a0101c18:  f2 23 c0 00  st  %i1, [ %o7 ]
a0101c1c:  c0 2e e1 81  clrb  [ %i3 + 0x181 ]
a0101c20:  f8 0e e1 81  ldub  [ %i3 + 0x181 ], %i4
a0101c24:  ba 07 20 01  add  %i4, 1, %i5
a0101c28:  b2 0f 60 ff  and  %i5, 0xff, %i1
a0101c2c:  f2 23 00 00  st  %i1, [ %o4 ]
a0101c30:  80 a6 60 ff  cmp  %i1, 0xff
a0101c34:  f2 22 c0 00  st  %i1, [ %o3 ]
a0101c38:  02 80 00 04  be  0xa0101c48
a0101c3c:  01 00 00 00  nop
a0101c40:  10 80 00 06  b  0xa0101c58
a0101c44:  fa 2e e1 81  stb  %i5, [ %i3 + 0x181 ]
a0101c48:  c0 23 00 00  clr  [ %o4 ]
a0101c4c:  c0 2e e1 81  clrb  [ %i3 + 0x181 ]
a0101c50:  c0 22 c0 00  clr  [ %o3 ]
a0101c54:  b0 10 20 00  clr  %i0
a0101c58:  b0 0e 20 01  and  %i0, 1, %i0
a0101c5c:  81 c7 e0 08  ret
a0101c60:  81 e8 00 00  restore
