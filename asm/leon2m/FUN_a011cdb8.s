# leon2m FUN_a011cdb8 0xa011cdb8-0xa011ce6c (180 bytes)
a011cdb8:  9d e3 bf 98  save  %sp, -104, %sp
a011cdbc:  39 2a 00 9e  sethi  %hi(0xa8027800), %i4
a011cdc0:  9e 17 22 a8  or  %i4, 0x2a8, %o7	! 0xa8027aa8
a011cdc4:  b3 2e 60 02  sll  %i1, 2, %i1
a011cdc8:  b2 16 40 1a  or  %i1, %i2, %i1
a011cdcc:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011cdd0:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a011cdd4:  80 8e 20 ff  btst  0xff, %i0
a011cdd8:  b4 10 00 1b  mov  %i3, %i2
a011cddc:  12 80 00 0a  bne  0xa011ce04
a011cde0:  ba 07 00 1c  add  %i4, %i4, %i5
a011cde4:  f8 13 c0 1d  lduh  [ %o7 + %i5 ], %i4
a011cde8:  b2 07 20 a0  add  %i4, 0xa0, %i1
a011cdec:  83 2e 60 02  sll  %i1, 2, %g1
a011cdf0:  ba 10 40 0d  or  %g1, %o5, %i5
a011cdf4:  f6 07 40 00  ld  [ %i5 ], %i3
a011cdf8:  b4 0e e0 bf  and  %i3, 0xbf, %i2
a011cdfc:  f4 27 40 00  st  %i2, [ %i5 ]
a011ce00:  30 80 00 19  b,a   0xa011ce64
a011ce04:  80 a7 20 02  cmp  %i4, 2
a011ce08:  b0 60 20 00  subx  %g0, 0, %i0
a011ce0c:  82 0e c0 18  and  %i3, %i0, %g1
a011ce10:  b6 08 60 ff  and  %g1, 0xff, %i3
a011ce14:  ba 06 c0 1b  add  %i3, %i3, %i5
a011ce18:  f0 13 c0 1d  lduh  [ %o7 + %i5 ], %i0
a011ce1c:  82 06 20 a0  add  %i0, 0xa0, %g1
a011ce20:  b7 28 60 02  sll  %g1, 2, %i3
a011ce24:  ba 16 c0 0d  or  %i3, %o5, %i5
a011ce28:  f0 07 40 00  ld  [ %i5 ], %i0
a011ce2c:  82 0e 20 e0  and  %i0, 0xe0, %g1
a011ce30:  b6 10 40 19  or  %g1, %i1, %i3
a011ce34:  80 a7 20 01  cmp  %i4, 1
a011ce38:  ba 16 e0 40  or  %i3, 0x40, %i5
a011ce3c:  08 80 00 03  bleu  0xa011ce48
a011ce40:  b8 0f 60 ff  and  %i5, 0xff, %i4
a011ce44:  b4 10 20 00  clr  %i2
a011ce48:  b0 0e a0 ff  and  %i2, 0xff, %i0
a011ce4c:  82 06 00 18  add  %i0, %i0, %g1
a011ce50:  f6 13 c0 01  lduh  [ %o7 + %g1 ], %i3
a011ce54:  ba 06 e0 a0  add  %i3, 0xa0, %i5
a011ce58:  b5 2f 60 02  sll  %i5, 2, %i2
a011ce5c:  b2 16 80 0d  or  %i2, %o5, %i1
a011ce60:  f8 26 40 00  st  %i4, [ %i1 ]
a011ce64:  81 c7 e0 08  ret
a011ce68:  81 e8 00 00  restore
