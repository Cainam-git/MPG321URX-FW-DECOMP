# leon2m FUN_a011fbd8 0xa011fbd8-0xa011fcac (212 bytes)
a011fbd8:  9d e3 bf 98  save  %sp, -104, %sp
a011fbdc:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011fbe0:  b8 16 e0 28  or  %i3, 0x28, %i4	! 0xcf011428
a011fbe4:  f4 07 00 00  ld  [ %i4 ], %i2
a011fbe8:  b2 0e 6f ff  and  %i1, 0xfff, %i1
a011fbec:  03 00 00 10  sethi  %hi(0x4000), %g1
a011fbf0:  ba 16 a0 03  or  %i2, 3, %i5
a011fbf4:  b2 16 40 01  or  %i1, %g1, %i1
a011fbf8:  fa 27 00 00  st  %i5, [ %i4 ]
a011fbfc:  80 a6 20 02  cmp  %i0, 2
a011fc00:  02 80 00 13  be  0xa011fc4c
a011fc04:  80 a6 20 01  cmp  %i0, 1
a011fc08:  18 80 00 27  bgu  0xa011fca4
a011fc0c:  b8 06 00 18  add  %i0, %i0, %i4
a011fc10:  31 00 06 8b  sethi  %hi(0x1a2c00), %i0
a011fc14:  82 16 23 b0  or  %i0, 0x3b0, %g1	! 0x1a2fb0
a011fc18:  fa 10 40 1c  lduh  [ %g1 + %i4 ], %i5
a011fc1c:  b6 07 60 36  add  %i5, 0x36, %i3
a011fc20:  b9 2e e0 02  sll  %i3, 2, %i4
a011fc24:  b0 07 60 37  add  %i5, 0x37, %i0
a011fc28:  37 33 c0 00  sethi  %hi(0xcf000000), %i3
a011fc2c:  b8 17 00 1b  or  %i4, %i3, %i4
a011fc30:  82 0e 60 ff  and  %i1, 0xff, %g1
a011fc34:  bb 2e 20 02  sll  %i0, 2, %i5
a011fc38:  c2 27 00 00  st  %g1, [ %i4 ]
a011fc3c:  b0 17 40 1b  or  %i5, %i3, %i0
a011fc40:  b5 36 60 08  srl  %i1, 8, %i2
a011fc44:  f4 26 00 00  st  %i2, [ %i0 ]
a011fc48:  30 80 00 17  b,a   0xa011fca4
a011fc4c:  b0 0e 60 ff  and  %i1, 0xff, %i0
a011fc50:  39 00 06 8b  sethi  %hi(0x1a2c00), %i4
a011fc54:  9e 17 23 b0  or  %i4, 0x3b0, %o7	! 0x1a2fb0
a011fc58:  b3 36 60 08  srl  %i1, 8, %i1
a011fc5c:  b6 10 20 00  clr  %i3
a011fc60:  82 10 20 00  clr  %g1
a011fc64:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011fc68:  82 00 40 01  add  %g1, %g1, %g1
a011fc6c:  fa 13 c0 01  lduh  [ %o7 + %g1 ], %i5
a011fc70:  b8 07 60 36  add  %i5, 0x36, %i4
a011fc74:  83 2f 20 02  sll  %i4, 2, %g1
a011fc78:  ba 07 60 37  add  %i5, 0x37, %i5
a011fc7c:  b8 10 40 1a  or  %g1, %i2, %i4
a011fc80:  83 2f 60 02  sll  %i5, 2, %g1
a011fc84:  ba 10 40 1a  or  %g1, %i2, %i5
a011fc88:  b6 06 e0 01  inc  %i3
a011fc8c:  f0 27 00 00  st  %i0, [ %i4 ]
a011fc90:  82 0e e0 ff  and  %i3, 0xff, %g1
a011fc94:  f2 27 40 00  st  %i1, [ %i5 ]
a011fc98:  80 a0 60 01  cmp  %g1, 1
a011fc9c:  08 bf ff f4  bleu  0xa011fc6c
a011fca0:  82 00 40 01  add  %g1, %g1, %g1
a011fca4:  81 c7 e0 08  ret
a011fca8:  81 e8 00 00  restore
