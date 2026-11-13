# leon2m FUN_a010de54 0xa010de54-0xa010e0f4 (672 bytes)
a010de54:  9d e3 bf 98  save  %sp, -104, %sp
a010de58:  b0 0e 20 ff  and  %i0, 0xff, %i0
a010de5c:  9e 10 00 1b  mov  %i3, %o7
a010de60:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010de64:  80 a6 20 01  cmp  %i0, 1
a010de68:  02 80 00 7c  be  0xa010e058
a010de6c:  b6 10 63 04  or  %g1, 0x304, %i3
a010de70:  b2 0e 60 ff  and  %i1, 0xff, %i1
a010de74:  80 a6 60 00  cmp  %i1, 0
a010de78:  12 80 00 46  bne  0xa010df90
a010de7c:  bb 2b e0 10  sll  %o7, 0x10, %i5
a010de80:  f4 36 e0 1c  sth  %i2, [ %i3 + 0x1c ]
a010de84:  b5 2e a0 10  sll  %i2, 0x10, %i2
a010de88:  83 37 60 10  srl  %i5, 0x10, %g1
a010de8c:  da 16 e0 10  lduh  [ %i3 + 0x10 ], %o5
a010de90:  de 36 e0 22  sth  %o7, [ %i3 + 0x22 ]
a010de94:  80 a6 20 00  cmp  %i0, 0
a010de98:  12 80 00 46  bne  0xa010dfb0
a010de9c:  ba 16 80 01  or  %i2, %g1, %i5
a010dea0:  80 a6 60 00  cmp  %i1, 0
a010dea4:  02 80 00 03  be  0xa010deb0
a010dea8:  03 34 00 c8  sethi  %hi(0xd0032000), %g1
a010deac:  03 34 00 e8  sethi  %hi(0xd003a000), %g1
a010deb0:  82 10 60 30  or  %g1, 0x30, %g1	! 0xd003a030
a010deb4:  fa 20 40 00  st  %i5, [ %g1 ]
a010deb8:  fa 16 e0 0c  lduh  [ %i3 + 0xc ], %i5
a010debc:  82 07 7f ff  add  %i5, -1, %g1
a010dec0:  f8 16 e0 16  lduh  [ %i3 + 0x16 ], %i4
a010dec4:  bb 28 60 10  sll  %g1, 0x10, %i5
a010dec8:  82 07 3f ff  add  %i4, -1, %g1
a010decc:  81 80 00 00  mov  %g0, %y
a010ded0:  01 00 00 00  nop
a010ded4:  01 00 00 00  nop
a010ded8:  01 00 00 00  nop
a010dedc:  b8 77 40 01  udiv  %i5, %g1, %i4
a010dee0:  80 a6 20 00  cmp  %i0, 0
a010dee4:  02 80 00 45  be  0xa010dff8
a010dee8:  80 a6 60 00  cmp  %i1, 0
a010deec:  12 80 00 67  bne  0xa010e088
a010def0:  33 34 00 e8  sethi  %hi(0xd003a000), %i1
a010def4:  33 34 00 c8  sethi  %hi(0xd0032000), %i1
a010def8:  bb 36 a0 10  srl  %i2, 0x10, %i5
a010defc:  82 16 60 a4  or  %i1, 0xa4, %g1
a010df00:  f8 20 40 00  st  %i4, [ %g1 ]
a010df04:  80 a7 40 0d  cmp  %i5, %o5
a010df08:  02 80 00 66  be  0xa010e0a0
a010df0c:  ba 16 60 08  or  %i1, 8, %i5
a010df10:  f8 07 40 00  ld  [ %i5 ], %i4
a010df14:  82 17 20 04  or  %i4, 4, %g1
a010df18:  f2 16 e0 0e  lduh  [ %i3 + 0xe ], %i1
a010df1c:  b9 2b e0 10  sll  %o7, 0x10, %i4
a010df20:  c2 27 40 00  st  %g1, [ %i5 ]
a010df24:  b4 06 7f ff  add  %i1, -1, %i2
a010df28:  b7 37 20 10  srl  %i4, 0x10, %i3
a010df2c:  bb 2e a0 10  sll  %i2, 0x10, %i5
a010df30:  82 06 ff ff  add  %i3, -1, %g1
a010df34:  81 80 00 00  mov  %g0, %y
a010df38:  01 00 00 00  nop
a010df3c:  01 00 00 00  nop
a010df40:  01 00 00 00  nop
a010df44:  b4 77 40 01  udiv  %i5, %g1, %i2
a010df48:  80 a6 20 00  cmp  %i0, 0
a010df4c:  12 80 00 36  bne  0xa010e024
a010df50:  31 34 00 c8  sethi  %hi(0xd0032000), %i0
a010df54:  ba 16 20 38  or  %i0, 0x38, %i5	! 0xd0032038
a010df58:  39 34 00 e8  sethi  %hi(0xd003a000), %i4
a010df5c:  f4 27 40 00  st  %i2, [ %i5 ]
a010df60:  82 17 20 38  or  %i4, 0x38, %g1
a010df64:  f4 20 40 00  st  %i2, [ %g1 ]
a010df68:  80 a6 40 1b  cmp  %i1, %i3
a010df6c:  02 80 00 58  be  0xa010e0cc
a010df70:  b4 16 20 04  or  %i0, 4, %i2
a010df74:  fa 06 80 00  ld  [ %i2 ], %i5
a010df78:  82 17 60 02  or  %i5, 2, %g1
a010df7c:  c2 26 80 00  st  %g1, [ %i2 ]
a010df80:  b8 17 20 04  or  %i4, 4, %i4
a010df84:  f0 07 00 00  ld  [ %i4 ], %i0
a010df88:  10 80 00 58  b  0xa010e0e8
a010df8c:  82 16 20 02  or  %i0, 2, %g1
a010df90:  f4 36 e0 1e  sth  %i2, [ %i3 + 0x1e ]
a010df94:  b5 2e a0 10  sll  %i2, 0x10, %i2
a010df98:  83 37 60 10  srl  %i5, 0x10, %g1
a010df9c:  da 16 e0 12  lduh  [ %i3 + 0x12 ], %o5
a010dfa0:  de 36 e0 22  sth  %o7, [ %i3 + 0x22 ]
a010dfa4:  80 a6 20 00  cmp  %i0, 0
a010dfa8:  02 bf ff be  be  0xa010dea0
a010dfac:  ba 16 80 01  or  %i2, %g1, %i5
a010dfb0:  80 a6 60 00  cmp  %i1, 0
a010dfb4:  12 80 00 1a  bne  0xa010e01c
a010dfb8:  03 34 00 c8  sethi  %hi(0xd0032000), %g1
a010dfbc:  82 10 60 a0  or  %g1, 0xa0, %g1	! 0xd00320a0
a010dfc0:  fa 20 40 00  st  %i5, [ %g1 ]
a010dfc4:  fa 16 e0 0c  lduh  [ %i3 + 0xc ], %i5
a010dfc8:  82 07 7f ff  add  %i5, -1, %g1
a010dfcc:  f8 16 e0 16  lduh  [ %i3 + 0x16 ], %i4
a010dfd0:  bb 28 60 10  sll  %g1, 0x10, %i5
a010dfd4:  82 07 3f ff  add  %i4, -1, %g1
a010dfd8:  81 80 00 00  mov  %g0, %y
a010dfdc:  01 00 00 00  nop
a010dfe0:  01 00 00 00  nop
a010dfe4:  01 00 00 00  nop
a010dfe8:  b8 77 40 01  udiv  %i5, %g1, %i4
a010dfec:  80 a6 20 00  cmp  %i0, 0
a010dff0:  12 bf ff bf  bne  0xa010deec
a010dff4:  80 a6 60 00  cmp  %i1, 0
a010dff8:  12 80 00 1b  bne  0xa010e064
a010dffc:  bb 36 a0 10  srl  %i2, 0x10, %i5
a010e000:  33 34 00 c8  sethi  %hi(0xd0032000), %i1
a010e004:  b4 16 60 34  or  %i1, 0x34, %i2	! 0xd0032034
a010e008:  f8 26 80 00  st  %i4, [ %i2 ]
a010e00c:  80 a7 40 0d  cmp  %i5, %o5
a010e010:  02 80 00 1b  be  0xa010e07c
a010e014:  ba 16 60 04  or  %i1, 4, %i5
a010e018:  30 bf ff be  b,a   0xa010df10
a010e01c:  10 bf ff e8  b  0xa010dfbc
a010e020:  03 34 00 e8  sethi  %hi(0xd003a000), %g1
a010e024:  ba 16 20 a8  or  %i0, 0xa8, %i5
a010e028:  39 34 00 e8  sethi  %hi(0xd003a000), %i4
a010e02c:  f4 27 40 00  st  %i2, [ %i5 ]
a010e030:  82 17 20 a8  or  %i4, 0xa8, %g1
a010e034:  f4 20 40 00  st  %i2, [ %g1 ]
a010e038:  80 a6 40 1b  cmp  %i1, %i3
a010e03c:  02 80 00 1c  be  0xa010e0ac
a010e040:  ba 16 20 08  or  %i0, 8, %i5
a010e044:  f6 07 40 00  ld  [ %i5 ], %i3
a010e048:  82 16 e0 02  or  %i3, 2, %g1
a010e04c:  c2 27 40 00  st  %g1, [ %i5 ]
a010e050:  10 bf ff cd  b  0xa010df84
a010e054:  b8 17 20 08  or  %i4, 8, %i4
a010e058:  39 2a 00 b6  sethi  %hi(0xa802d800), %i4
a010e05c:  10 bf ff 85  b  0xa010de70
a010e060:  b6 17 20 04  or  %i4, 4, %i3	! 0xa802d804
a010e064:  33 34 00 e8  sethi  %hi(0xd003a000), %i1
a010e068:  b4 16 60 34  or  %i1, 0x34, %i2	! 0xd003a034
a010e06c:  f8 26 80 00  st  %i4, [ %i2 ]
a010e070:  80 a7 40 0d  cmp  %i5, %o5
a010e074:  12 bf ff a7  bne  0xa010df10
a010e078:  ba 16 60 04  or  %i1, 4, %i5
a010e07c:  f2 07 40 00  ld  [ %i5 ], %i1
a010e080:  10 bf ff a6  b  0xa010df18
a010e084:  82 0e 7f fb  and  %i1, -5, %g1
a010e088:  bb 36 a0 10  srl  %i2, 0x10, %i5
a010e08c:  82 16 60 a4  or  %i1, 0xa4, %g1
a010e090:  f8 20 40 00  st  %i4, [ %g1 ]
a010e094:  80 a7 40 0d  cmp  %i5, %o5
a010e098:  12 bf ff 9e  bne  0xa010df10
a010e09c:  ba 16 60 08  or  %i1, 8, %i5
a010e0a0:  f2 07 40 00  ld  [ %i5 ], %i1
a010e0a4:  10 bf ff 9d  b  0xa010df18
a010e0a8:  82 0e 7f fb  and  %i1, -5, %g1
a010e0ac:  b6 16 20 08  or  %i0, 8, %i3
a010e0b0:  f2 06 c0 00  ld  [ %i3 ], %i1
a010e0b4:  b0 0e 7f fd  and  %i1, -3, %i0
a010e0b8:  f0 26 c0 00  st  %i0, [ %i3 ]
a010e0bc:  b8 17 20 08  or  %i4, 8, %i4
a010e0c0:  f4 07 00 00  ld  [ %i4 ], %i2
a010e0c4:  10 80 00 09  b  0xa010e0e8
a010e0c8:  82 0e bf fd  and  %i2, -3, %g1
a010e0cc:  b6 16 20 04  or  %i0, 4, %i3
a010e0d0:  f2 06 c0 00  ld  [ %i3 ], %i1
a010e0d4:  b0 0e 7f fd  and  %i1, -3, %i0
a010e0d8:  f0 26 c0 00  st  %i0, [ %i3 ]
a010e0dc:  b8 17 20 04  or  %i4, 4, %i4
a010e0e0:  f4 07 00 00  ld  [ %i4 ], %i2
a010e0e4:  82 0e bf fd  and  %i2, -3, %g1
a010e0e8:  c2 27 00 00  st  %g1, [ %i4 ]
a010e0ec:  81 c7 e0 08  ret
a010e0f0:  81 e8 00 00  restore
