# leon2m FUN_a011fd84 0xa011fd84-0xa011ff28 (420 bytes)
a011fd84:  9d e3 bf 98  save  %sp, -104, %sp
a011fd88:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011fd8c:  ba 17 60 28  or  %i5, 0x28, %i5	! 0xcf011428
a011fd90:  f8 07 40 00  ld  [ %i5 ], %i4
a011fd94:  b2 0e 7f fe  and  %i1, -2, %i1
a011fd98:  b4 06 80 1a  add  %i2, %i2, %i2
a011fd9c:  b2 16 40 1a  or  %i1, %i2, %i1
a011fda0:  82 17 20 03  or  %i4, 3, %g1
a011fda4:  c2 27 40 00  st  %g1, [ %i5 ]
a011fda8:  9e 10 00 1b  mov  %i3, %o7
a011fdac:  80 a6 20 02  cmp  %i0, 2
a011fdb0:  02 80 00 49  be  0xa011fed4
a011fdb4:  b2 16 60 04  or  %i1, 4, %i1
a011fdb8:  80 a6 20 01  cmp  %i0, 1
a011fdbc:  08 80 00 1d  bleu  0xa011fe30
a011fdc0:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a011fdc4:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011fdc8:  b2 17 60 28  or  %i5, 0x28, %i1	! 0xcf011428
a011fdcc:  f8 06 40 00  ld  [ %i1 ], %i4
a011fdd0:  b6 17 20 03  or  %i4, 3, %i3
a011fdd4:  b4 0b ef ff  and  %o7, 0xfff, %i2
a011fdd8:  f6 26 40 00  st  %i3, [ %i1 ]
a011fddc:  80 a6 20 02  cmp  %i0, 2
a011fde0:  02 80 00 27  be  0xa011fe7c
a011fde4:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a011fde8:  80 a6 20 01  cmp  %i0, 1
a011fdec:  18 80 00 4d  bgu  0xa011ff20
a011fdf0:  b8 06 00 18  add  %i0, %i0, %i4
a011fdf4:  31 00 06 8b  sethi  %hi(0x1a2c00), %i0
a011fdf8:  82 16 23 b0  or  %i0, 0x3b0, %g1	! 0x1a2fb0
a011fdfc:  fa 10 40 1c  lduh  [ %g1 + %i4 ], %i5
a011fe00:  b6 07 60 25  add  %i5, 0x25, %i3
a011fe04:  b9 2e e0 02  sll  %i3, 2, %i4
a011fe08:  b0 07 60 26  add  %i5, 0x26, %i0
a011fe0c:  37 33 c0 00  sethi  %hi(0xcf000000), %i3
a011fe10:  b8 17 00 1b  or  %i4, %i3, %i4
a011fe14:  82 0e a0 ff  and  %i2, 0xff, %g1
a011fe18:  bb 2e 20 02  sll  %i0, 2, %i5
a011fe1c:  c2 27 00 00  st  %g1, [ %i4 ]
a011fe20:  b0 17 40 1b  or  %i5, %i3, %i0
a011fe24:  b3 36 a0 08  srl  %i2, 8, %i1
a011fe28:  f2 26 00 00  st  %i1, [ %i0 ]
a011fe2c:  30 80 00 3d  b,a   0xa011ff20
a011fe30:  b4 10 63 b0  or  %g1, 0x3b0, %i2
a011fe34:  b8 06 00 18  add  %i0, %i0, %i4
a011fe38:  f6 16 80 1c  lduh  [ %i2 + %i4 ], %i3
a011fe3c:  ba 06 e0 24  add  %i3, 0x24, %i5
a011fe40:  b5 2f 60 02  sll  %i5, 2, %i2
a011fe44:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a011fe48:  b6 16 80 01  or  %i2, %g1, %i3
a011fe4c:  b8 0e 60 ff  and  %i1, 0xff, %i4
a011fe50:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011fe54:  f8 26 c0 00  st  %i4, [ %i3 ]
a011fe58:  b2 17 60 28  or  %i5, 0x28, %i1
a011fe5c:  f8 06 40 00  ld  [ %i1 ], %i4
a011fe60:  b6 17 20 03  or  %i4, 3, %i3
a011fe64:  b4 0b ef ff  and  %o7, 0xfff, %i2
a011fe68:  f6 26 40 00  st  %i3, [ %i1 ]
a011fe6c:  80 a6 20 02  cmp  %i0, 2
a011fe70:  12 bf ff df  bne  0xa011fdec
a011fe74:  80 a6 20 01  cmp  %i0, 1
a011fe78:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a011fe7c:  b0 0e a0 ff  and  %i2, 0xff, %i0
a011fe80:  9e 10 63 b0  or  %g1, 0x3b0, %o7
a011fe84:  b7 36 a0 08  srl  %i2, 8, %i3
a011fe88:  b4 10 20 00  clr  %i2
a011fe8c:  82 10 20 00  clr  %g1
a011fe90:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a011fe94:  b8 00 40 01  add  %g1, %g1, %i4
a011fe98:  fa 13 c0 1c  lduh  [ %o7 + %i4 ], %i5
a011fe9c:  82 07 60 25  add  %i5, 0x25, %g1
a011fea0:  b9 28 60 02  sll  %g1, 2, %i4
a011fea4:  82 17 00 19  or  %i4, %i1, %g1
a011fea8:  ba 07 60 26  add  %i5, 0x26, %i5
a011feac:  f0 20 40 00  st  %i0, [ %g1 ]
a011feb0:  bb 2f 60 02  sll  %i5, 2, %i5
a011feb4:  b4 06 a0 01  inc  %i2
a011feb8:  b8 17 40 19  or  %i5, %i1, %i4
a011febc:  82 0e a0 ff  and  %i2, 0xff, %g1
a011fec0:  f6 27 00 00  st  %i3, [ %i4 ]
a011fec4:  80 a0 60 01  cmp  %g1, 1
a011fec8:  08 bf ff f4  bleu  0xa011fe98
a011fecc:  b8 00 40 01  add  %g1, %g1, %i4
a011fed0:  30 80 00 14  b,a   0xa011ff20
a011fed4:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a011fed8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a011fedc:  b6 10 63 b0  or  %g1, 0x3b0, %i3
a011fee0:  b4 10 20 00  clr  %i2
a011fee4:  ba 10 20 00  clr  %i5
a011fee8:  39 33 c0 00  sethi  %hi(0xcf000000), %i4
a011feec:  ba 07 40 1d  add  %i5, %i5, %i5
a011fef0:  c2 16 c0 1d  lduh  [ %i3 + %i5 ], %g1
a011fef4:  82 00 60 24  add  %g1, 0x24, %g1
a011fef8:  bb 28 60 02  sll  %g1, 2, %i5
a011fefc:  82 17 40 1c  or  %i5, %i4, %g1
a011ff00:  b4 06 a0 01  inc  %i2
a011ff04:  ba 0e a0 ff  and  %i2, 0xff, %i5
a011ff08:  f2 20 40 00  st  %i1, [ %g1 ]
a011ff0c:  80 a7 60 01  cmp  %i5, 1
a011ff10:  28 bf ff f8  bleu,a   0xa011fef0
a011ff14:  ba 07 40 1d  add  %i5, %i5, %i5
a011ff18:  10 bf ff ac  b  0xa011fdc8
a011ff1c:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011ff20:  81 c7 e0 08  ret
a011ff24:  81 e8 00 00  restore
