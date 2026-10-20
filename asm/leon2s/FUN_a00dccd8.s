# leon2s FUN_a00dccd8 0xa00dccd8-0xa00dcdb8 (224 bytes)
a00dccd8:  9d e3 bf 98  save  %sp, -104, %sp
a00dccdc:  31 30 04 82  sethi  %hi(0xc0120800), %i0
a00dcce0:  33 2a 01 e5  sethi  %hi(0xa8079400), %i1
a00dcce4:  03 04 80 00  sethi  %hi(0x12000000), %g1
a00dcce8:  b2 16 61 38  or  %i1, 0x138, %i1
a00dccec:  ba 16 20 14  or  %i0, 0x14, %i5
a00dccf0:  82 10 62 18  or  %g1, 0x218, %g1
a00dccf4:  c2 27 40 00  st  %g1, [ %i5 ]
a00dccf8:  f4 16 60 08  lduh  [ %i1 + 8 ], %i2
a00dccfc:  ba 16 20 18  or  %i0, 0x18, %i5
a00dcd00:  03 3f ff c0  sethi  %hi(0xffff0000), %g1
a00dcd04:  b5 36 a0 03  srl  %i2, 3, %i2
a00dcd08:  c2 27 40 00  st  %g1, [ %i5 ]
a00dcd0c:  b5 2e a0 10  sll  %i2, 0x10, %i2
a00dcd10:  f6 16 60 0c  lduh  [ %i1 + 0xc ], %i3
a00dcd14:  ba 36 80 01  orn  %i2, %g1, %i5
a00dcd18:  b7 2e e0 10  sll  %i3, 0x10, %i3
a00dcd1c:  d6 16 60 14  lduh  [ %i1 + 0x14 ], %o3
a00dcd20:  82 16 20 1c  or  %i0, 0x1c, %g1
a00dcd24:  9f 36 e0 13  srl  %i3, 0x13, %o7
a00dcd28:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00dcd2c:  fa 20 40 00  st  %i5, [ %g1 ]
a00dcd30:  b7 36 e0 10  srl  %i3, 0x10, %i3
a00dcd34:  d8 16 60 16  lduh  [ %i1 + 0x16 ], %o4
a00dcd38:  f8 16 60 0e  lduh  [ %i1 + 0xe ], %i4
a00dcd3c:  9f 2b e0 10  sll  %o7, 0x10, %o7
a00dcd40:  9b 33 60 10  srl  %o5, 0x10, %o5
a00dcd44:  82 16 20 20  or  %i0, 0x20, %g1
a00dcd48:  b8 07 00 1b  add  %i4, %i3, %i4
a00dcd4c:  98 03 00 0b  add  %o4, %o3, %o4
a00dcd50:  9e 13 c0 0d  or  %o7, %o5, %o7
a00dcd54:  de 20 40 00  st  %o7, [ %g1 ]
a00dcd58:  f4 16 60 0a  lduh  [ %i1 + 0xa ], %i2
a00dcd5c:  b9 37 20 03  srl  %i4, 3, %i4
a00dcd60:  99 2b 20 10  sll  %o4, 0x10, %o4
a00dcd64:  82 16 20 24  or  %i0, 0x24, %g1
a00dcd68:  b5 36 a0 03  srl  %i2, 3, %i2
a00dcd6c:  b8 17 00 0c  or  %i4, %o4, %i4
a00dcd70:  f8 20 40 00  st  %i4, [ %g1 ]
a00dcd74:  bb 2e a0 10  sll  %i2, 0x10, %i5
a00dcd78:  82 16 20 28  or  %i0, 0x28, %g1
a00dcd7c:  b4 16 80 1d  or  %i2, %i5, %i2
a00dcd80:  f6 16 60 12  lduh  [ %i1 + 0x12 ], %i3
a00dcd84:  f4 20 40 00  st  %i2, [ %g1 ]
a00dcd88:  b7 2e e0 10  sll  %i3, 0x10, %i3
a00dcd8c:  82 16 20 2c  or  %i0, 0x2c, %g1
a00dcd90:  b7 36 e0 10  srl  %i3, 0x10, %i3
a00dcd94:  f6 20 40 00  st  %i3, [ %g1 ]
a00dcd98:  fa 16 60 10  lduh  [ %i1 + 0x10 ], %i5
a00dcd9c:  bb 37 60 03  srl  %i5, 3, %i5
a00dcda0:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00dcda4:  ba 17 40 01  or  %i5, %g1, %i5
a00dcda8:  b0 16 20 48  or  %i0, 0x48, %i0
a00dcdac:  fa 26 00 00  st  %i5, [ %i0 ]
a00dcdb0:  81 c7 e0 08  ret
a00dcdb4:  81 e8 00 00  restore
