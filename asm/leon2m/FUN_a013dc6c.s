# leon2m FUN_a013dc6c 0xa013dc6c-0xa013f1e4 (312 bytes)
a013dc6c:  9d e3 be a8  save  %sp, -344, %sp
a013dc70:  33 2a 00 b2  sethi  %hi(0xa802c800), %i1
a013dc74:  c2 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %g1	! 0xa802cbd2
a013dc78:  80 a0 60 ff  cmp  %g1, 0xff
a013dc7c:  02 80 05 58  be  0xa013f1dc
a013dc80:  ab 28 60 04  sll  %g1, 4, %l5
a013dc84:  a8 25 40 01  sub  %l5, %g1, %l4
a013dc88:  37 2a 00 b7  sethi  %hi(0xa802dc00), %i3
a013dc8c:  a1 2d 20 03  sll  %l4, 3, %l0
a013dc90:  a2 16 e3 30  or  %i3, 0x330, %l1
a013dc94:  e6 04 00 11  ld  [ %l0 + %l1 ], %l3
a013dc98:  a5 34 e0 0c  srl  %l3, 0xc, %l2
a013dc9c:  9e 0c a0 0f  and  %l2, 0xf, %o7
a013dca0:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a013dca4:  94 5b e0 2a  smul  %o7, 0x2a, %o2
a013dca8:  96 16 22 24  or  %i0, 0x224, %o3
a013dcac:  92 02 80 0b  add  %o2, %o3, %o1
a013dcb0:  40 00 11 6f  call  0xa014226c
a013dcb4:  d0 0a 60 0a  ldub  [ %o1 + 0xa ], %o0
a013dcb8:  b8 10 00 08  mov  %o0, %i4
a013dcbc:  d0 04 00 11  ld  [ %l0 + %l1 ], %o0
a013dcc0:  1b 00 00 3c  sethi  %hi(0xf000), %o5
a013dcc4:  82 0a 00 0d  and  %o0, %o5, %g1
a013dcc8:  19 00 00 08  sethi  %hi(0x2000), %o4
a013dccc:  80 a0 40 0c  cmp  %g1, %o4
a013dcd0:  02 80 00 58  be  0xa013de30
a013dcd4:  b4 04 00 11  add  %l0, %l1, %i2
a013dcd8:  e0 06 80 00  ld  [ %i2 ], %l0
a013dcdc:  19 00 00 3c  sethi  %hi(0xf000), %o4
a013dce0:  a2 0c 00 0c  and  %l0, %o4, %l1
a013dce4:  3b 00 00 0c  sethi  %hi(0x3000), %i5
a013dce8:  80 a4 40 1d  cmp  %l1, %i5
a013dcec:  02 80 00 5d  be  0xa013de60
a013dcf0:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a013dcf4:  da 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o5
a013dcf8:  80 a3 60 ff  cmp  %o5, 0xff
a013dcfc:  22 80 00 49  be,a   0xa013de20
a013dd00:  f6 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %i3
a013dd04:  d0 06 80 00  ld  [ %i2 ], %o0
a013dd08:  83 32 20 1c  srl  %o0, 0x1c, %g1
a013dd0c:  80 a0 60 0c  cmp  %g1, 0xc
a013dd10:  38 80 00 3f  bgu,a   0xa013de0c
a013dd14:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013dd18:  1f 00 03 72  sethi  %hi(0xdc800), %o7
a013dd1c:  95 28 60 02  sll  %g1, 2, %o2
a013dd20:  96 13 e0 dc  or  %o7, 0xdc, %o3
a013dd24:  d2 02 c0 0a  ld  [ %o3 + %o2 ], %o1
a013dd28:  81 c2 40 00  jmp  %o1
a013dd2c:  01 00 00 00  nop
a013dd30:  7f fe 7e 39  call  0xa00dd614
a013dd34:  90 10 20 04  mov  4, %o0	! 0x4
a013dd38:  80 8a 20 ff  btst  0xff, %o0
a013dd3c:  12 80 04 54  bne  0xa013ee8c
a013dd40:  1f 00 06 95  sethi  %hi(0x1a5400), %o7
a013dd44:  fa 06 80 00  ld  [ %i2 ], %i5
a013dd48:  af 37 60 0c  srl  %i5, 0xc, %l7
a013dd4c:  90 0d e0 0f  and  %l7, 0xf, %o0
a013dd50:  ac 5a 20 2a  smul  %o0, 0x2a, %l6
a013dd54:  aa 05 80 10  add  %l6, %l0, %l5
a013dd58:  e4 0d 60 24  ldub  [ %l5 + 0x24 ], %l2
a013dd5c:  e8 15 60 1e  lduh  [ %l5 + 0x1e ], %l4
a013dd60:  e6 15 60 20  lduh  [ %l5 + 0x20 ], %l3
a013dd64:  d6 0d 60 22  ldub  [ %l5 + 0x22 ], %o3
a013dd68:  d4 0d 60 23  ldub  [ %l5 + 0x23 ], %o2
a013dd6c:  e8 36 a0 06  sth  %l4, [ %i2 + 6 ]
a013dd70:  e6 36 a0 08  sth  %l3, [ %i2 + 8 ]
a013dd74:  d6 2e a0 0b  stb  %o3, [ %i2 + 0xb ]
a013dd78:  d4 2e a0 0c  stb  %o2, [ %i2 + 0xc ]
a013dd7c:  40 00 14 44  call  0xa0142e8c
a013dd80:  e4 2e a0 0a  stb  %l2, [ %i2 + 0xa ]
a013dd84:  92 0a 20 ff  and  %o0, 0xff, %o1
a013dd88:  80 a2 60 05  cmp  %o1, 5
a013dd8c:  02 80 04 2b  be  0xa013ee38
a013dd90:  d2 06 80 00  ld  [ %i2 ], %o1
a013dd94:  99 32 60 0c  srl  %o1, 0xc, %o4
a013dd98:  a2 0b 20 0f  and  %o4, 0xf, %l1
a013dd9c:  ba 5c 60 2a  smul  %l1, 0x2a, %i5
a013dda0:  ae 07 40 10  add  %i5, %l0, %l7
a013dda4:  ec 15 e0 26  lduh  [ %l7 + 0x26 ], %l6
a013dda8:  ec 36 a0 10  sth  %l6, [ %i2 + 0x10 ]
a013ddac:  ea 06 80 00  ld  [ %i2 ], %l5
a013ddb0:  a1 32 60 0c  srl  %o1, 0xc, %l0
a013ddb4:  91 35 60 14  srl  %l5, 0x14, %o0
a013ddb8:  92 0a 20 0f  and  %o0, 0xf, %o1
a013ddbc:  98 0c 20 0f  and  %l0, 0xf, %o4
a013ddc0:  a2 02 60 01  add  %o1, 1, %l1
a013ddc4:  ee 06 a0 40  ld  [ %i2 + 0x40 ], %l7
a013ddc8:  96 5b 20 2a  smul  %o4, 0x2a, %o3
a013ddcc:  9a 0c 60 0f  and  %l1, 0xf, %o5
a013ddd0:  ba 16 22 24  or  %i0, 0x224, %i5
a013ddd4:  2d 20 00 00  sethi  %hi(0x80000000), %l6
a013ddd8:  29 00 3c 00  sethi  %hi(0xf00000), %l4
a013dddc:  9e 02 c0 1d  add  %o3, %i5, %o7
a013dde0:  94 2d c0 16  andn  %l7, %l6, %o2
a013dde4:  82 2d 40 14  andn  %l5, %l4, %g1
a013dde8:  a5 2b 60 14  sll  %o5, 0x14, %l2
a013ddec:  27 10 00 00  sethi  %hi(0x40000000), %l3
a013ddf0:  d0 0b e0 09  ldub  [ %o7 + 9 ], %o0
a013ddf4:  a0 2a 80 13  andn  %o2, %l3, %l0
a013ddf8:  92 10 40 12  or  %g1, %l2, %o1
a013ddfc:  d0 2e a0 3f  stb  %o0, [ %i2 + 0x3f ]
a013de00:  e0 26 a0 40  st  %l0, [ %i2 + 0x40 ]
a013de04:  d2 26 80 00  st  %o1, [ %i2 ]
a013de08:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013de0c:  17 00 10 00  sethi  %hi(0x400000), %o3
a013de10:  80 8b c0 0b  btst  %o7, %o3
a013de14:  32 bf ff bd  bne,a   0xa013dd08
a013de18:  d0 06 80 00  ld  [ %i2 ], %o0
a013de1c:  f6 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %i3
a013de20:  b4 06 e0 01  add  %i3, 1, %i2
a013de24:  b0 0e a0 03  and  %i2, 3, %i0
a013de28:  10 80 04 ed  b  0xa013f1dc
a013de2c:  f0 2e 63 d2  stb  %i0, [ %i1 + 0x3d2 ]
a013de30:  2f 2a 00 b8  sethi  %hi(0xa802e000), %l7
a013de34:  ec 0d e3 f2  ldub  [ %l7 + 0x3f2 ], %l6	! 0xa802e3f2
a013de38:  80 a5 a0 01  cmp  %l6, 1
a013de3c:  02 bf ff f8  be  0xa013de1c
a013de40:  19 00 00 3c  sethi  %hi(0xf000), %o4
a013de44:  e0 06 80 00  ld  [ %i2 ], %l0
a013de48:  a2 0c 00 0c  and  %l0, %o4, %l1
a013de4c:  3b 00 00 0c  sethi  %hi(0x3000), %i5
a013de50:  80 a4 40 1d  cmp  %l1, %i5
a013de54:  12 bf ff a9  bne  0xa013dcf8
a013de58:  da 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o5
a013de5c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a013de60:  d0 08 63 f3  ldub  [ %g1 + 0x3f3 ], %o0	! 0xa802e3f3
a013de64:  80 a2 20 01  cmp  %o0, 1
a013de68:  02 bf ff ed  be  0xa013de1c
a013de6c:  da 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o5
a013de70:  10 bf ff a3  b  0xa013dcfc
a013de74:  80 a3 60 ff  cmp  %o5, 0xff
a013de78:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013de7c:  25 00 08 00  sethi  %hi(0x200000), %l2
a013de80:  80 8b c0 12  btst  %o7, %l2
a013de84:  02 80 00 1d  be  0xa013def8
a013de88:  3b 00 40 00  sethi  %hi(0x1000000), %i5
a013de8c:  bb 32 20 0c  srl  %o0, 0xc, %i5
a013de90:  ae 0f 60 0f  and  %i5, 0xf, %l7
a013de94:  aa 5d e0 2a  smul  %l7, 0x2a, %l5
a013de98:  ac 16 22 24  or  %i0, 0x224, %l6
a013de9c:  a8 05 40 16  add  %l5, %l6, %l4
a013dea0:  e6 0d 20 02  ldub  [ %l4 + 2 ], %l3
a013dea4:  80 a4 e0 04  cmp  %l3, 4
a013dea8:  12 bf ff da  bne  0xa013de10
a013deac:  17 00 10 00  sethi  %hi(0x400000), %o3
a013deb0:  2f 3c 00 00  sethi  %hi(0xf0000000), %l7
a013deb4:  82 2a 00 17  andn  %o0, %l7, %g1
a013deb8:  11 0c 00 00  sethi  %hi(0x30000000), %o0
a013debc:  82 10 40 08  or  %g1, %o0, %g1
a013dec0:  c2 26 80 00  st  %g1, [ %i2 ]
a013dec4:  17 00 10 00  sethi  %hi(0x400000), %o3
a013dec8:  10 bf ff d3  b  0xa013de14
a013decc:  80 8b c0 0b  btst  %o7, %o3
a013ded0:  e0 06 80 00  ld  [ %i2 ], %l0
a013ded4:  23 3c 00 00  sethi  %hi(0xf0000000), %l1
a013ded8:  9a 2c 00 11  andn  %l0, %l1, %o5
a013dedc:  19 14 00 00  sethi  %hi(0x50000000), %o4
a013dee0:  9a 13 40 0c  or  %o5, %o4, %o5
a013dee4:  da 26 80 00  st  %o5, [ %i2 ]
a013dee8:  10 bf ff c9  b  0xa013de0c
a013deec:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013def0:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013def4:  3b 00 40 00  sethi  %hi(0x1000000), %i5
a013def8:  80 8b c0 1d  btst  %o7, %i5
a013defc:  02 bf ff c5  be  0xa013de10
a013df00:  17 00 10 00  sethi  %hi(0x400000), %o3
a013df04:  ab 32 20 0c  srl  %o0, 0xc, %l5
a013df08:  ac 0d 60 0f  and  %l5, 0xf, %l6
a013df0c:  a0 5d a0 2a  smul  %l6, 0x2a, %l0
a013df10:  a8 16 22 24  or  %i0, 0x224, %l4
a013df14:  94 04 00 14  add  %l0, %l4, %o2
a013df18:  e4 0a a0 02  ldub  [ %o2 + 2 ], %l2
a013df1c:  80 a4 a0 06  cmp  %l2, 6
a013df20:  32 bf ff bd  bne,a   0xa013de14
a013df24:  80 8b c0 0b  btst  %o7, %o3
a013df28:  10 bf ff e3  b  0xa013deb4
a013df2c:  2f 3c 00 00  sethi  %hi(0xf0000000), %l7
a013df30:  99 32 20 0c  srl  %o0, 0xc, %o4
a013df34:  96 0b 20 0f  and  %o4, 0xf, %o3
a013df38:  94 16 22 24  or  %i0, 0x224, %o2
a013df3c:  98 5a e0 2a  smul  %o3, 0x2a, %o4
a013df40:  82 03 00 0a  add  %o4, %o2, %g1
a013df44:  ec 08 60 02  ldub  [ %g1 + 2 ], %l6
a013df48:  80 a5 a0 04  cmp  %l6, 4
a013df4c:  12 80 01 10  bne  0xa013e38c
a013df50:  25 3c 00 00  sethi  %hi(0xf0000000), %l2
a013df54:  ee 12 80 0c  lduh  [ %o2 + %o4 ], %l7
a013df58:  ab 35 e0 0c  srl  %l7, 0xc, %l5
a013df5c:  80 8d 60 01  btst  1, %l5
a013df60:  32 80 01 0c  bne,a   0xa013e390
a013df64:  fa 06 a0 70  ld  [ %i2 + 0x70 ], %i5
a013df68:  90 10 00 0b  mov  %o3, %o0
a013df6c:  7f ff d2 7e  call  0xa0132964
a013df70:  92 0f 20 ff  and  %i4, 0xff, %o1
a013df74:  94 0a 20 ff  and  %o0, 0xff, %o2
a013df78:  80 a2 a0 01  cmp  %o2, 1
a013df7c:  22 80 02 bd  be,a   0xa013ea70
a013df80:  d6 06 a0 70  ld  [ %i2 + 0x70 ], %o3
a013df84:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013df88:  27 00 00 80  sethi  %hi(0x20000), %l3
a013df8c:  80 8b c0 13  btst  %o7, %l3
a013df90:  02 bf ff a0  be  0xa013de10
a013df94:  17 00 10 00  sethi  %hi(0x400000), %o3
a013df98:  e2 06 80 00  ld  [ %i2 ], %l1
a013df9c:  9b 34 60 0c  srl  %l1, 0xc, %o5
a013dfa0:  7f fe ca ee  call  0xa00f0b58
a013dfa4:  90 0b 60 0f  and  %o5, 0xf, %o0
a013dfa8:  10 bf ff 99  b  0xa013de0c
a013dfac:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013dfb0:  a3 32 20 0c  srl  %o0, 0xc, %l1
a013dfb4:  a6 0c 60 0f  and  %l1, 0xf, %l3
a013dfb8:  90 5c e0 2a  smul  %l3, 0x2a, %o0
a013dfbc:  98 16 22 24  or  %i0, 0x224, %o4
a013dfc0:  92 02 00 0c  add  %o0, %o4, %o1
a013dfc4:  da 0a 60 02  ldub  [ %o1 + 2 ], %o5
a013dfc8:  80 a3 60 04  cmp  %o5, 4
a013dfcc:  22 80 02 56  be,a   0xa013e924
a013dfd0:  e4 13 00 08  lduh  [ %o4 + %o0 ], %l2
a013dfd4:  e8 06 80 00  ld  [ %i2 ], %l4
a013dfd8:  1f 3c 00 00  sethi  %hi(0xf0000000), %o7
a013dfdc:  a4 2d 00 0f  andn  %l4, %o7, %l2
a013dfe0:  11 14 00 00  sethi  %hi(0x50000000), %o0
a013dfe4:  d4 06 a0 70  ld  [ %i2 + 0x70 ], %o2
a013dfe8:  21 00 10 00  sethi  %hi(0x400000), %l0
a013dfec:  98 14 80 08  or  %l2, %o0, %o4
a013dff0:  9e 2a 80 10  andn  %o2, %l0, %o7
a013dff4:  d8 26 80 00  st  %o4, [ %i2 ]
a013dff8:  de 26 a0 70  st  %o7, [ %i2 + 0x70 ]
a013dffc:  17 00 10 00  sethi  %hi(0x400000), %o3
a013e000:  10 bf ff 85  b  0xa013de14
a013e004:  80 8b c0 0b  btst  %o7, %o3
a013e008:  bb 32 20 0c  srl  %o0, 0xc, %i5
a013e00c:  9a 0f 60 0f  and  %i5, 0xf, %o5
a013e010:  90 5b 60 2a  smul  %o5, 0x2a, %o0
a013e014:  98 16 22 24  or  %i0, 0x224, %o4
a013e018:  96 02 00 0c  add  %o0, %o4, %o3
a013e01c:  de 0a e0 02  ldub  [ %o3 + 2 ], %o7
a013e020:  80 a3 e0 04  cmp  %o7, 4
a013e024:  32 bf ff ed  bne,a   0xa013dfd8
a013e028:  e8 06 80 00  ld  [ %i2 ], %l4
a013e02c:  d2 13 00 08  lduh  [ %o4 + %o0 ], %o1
a013e030:  a9 32 60 0c  srl  %o1, 0xc, %l4
a013e034:  80 8d 20 01  btst  1, %l4
a013e038:  32 bf ff e8  bne,a   0xa013dfd8
a013e03c:  e8 06 80 00  ld  [ %i2 ], %l4
a013e040:  7f fe 7d 75  call  0xa00dd614
a013e044:  90 10 20 04  mov  4, %o0
a013e048:  80 8a 20 ff  btst  0xff, %o0
a013e04c:  12 80 02 b2  bne  0xa013eb14
a013e050:  2b 00 06 95  sethi  %hi(0x1a5400), %l5
a013e054:  d8 06 80 00  ld  [ %i2 ], %o4
a013e058:  ad 33 20 14  srl  %o4, 0x14, %l6
a013e05c:  82 0d a0 0f  and  %l6, 0xf, %g1
a013e060:  80 a0 60 01  cmp  %g1, 1
a013e064:  22 80 02 90  be,a   0xa013eaa4
a013e068:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e06c:  04 80 02 ce  ble  0xa013eba4
a013e070:  80 a0 60 02  cmp  %g1, 2
a013e074:  32 bf ff 66  bne,a   0xa013de0c
a013e078:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e07c:  2f 00 3c 00  sethi  %hi(0xf00000), %l7
a013e080:  aa 2b 00 17  andn  %o4, %l7, %l5
a013e084:  2d 3c 00 00  sethi  %hi(0xf0000000), %l6
a013e088:  9a 2d 40 16  andn  %l5, %l6, %o5
a013e08c:  19 2c 00 00  sethi  %hi(0xb0000000), %o4
a013e090:  10 bf ff 95  b  0xa013dee4
a013e094:  9a 13 40 0c  or  %o5, %o4, %o5
a013e098:  95 32 20 0c  srl  %o0, 0xc, %o2
a013e09c:  98 0a a0 0f  and  %o2, 0xf, %o4
a013e0a0:  90 5b 20 2a  smul  %o4, 0x2a, %o0
a013e0a4:  98 16 22 24  or  %i0, 0x224, %o4
a013e0a8:  9e 02 00 0c  add  %o0, %o4, %o7
a013e0ac:  e6 0b e0 02  ldub  [ %o7 + 2 ], %l3
a013e0b0:  80 a4 e0 04  cmp  %l3, 4
a013e0b4:  32 bf ff c9  bne,a   0xa013dfd8
a013e0b8:  e8 06 80 00  ld  [ %i2 ], %l4
a013e0bc:  d6 13 00 08  lduh  [ %o4 + %o0 ], %o3
a013e0c0:  83 32 e0 0c  srl  %o3, 0xc, %g1
a013e0c4:  80 88 60 01  btst  1, %g1
a013e0c8:  32 bf ff c4  bne,a   0xa013dfd8
a013e0cc:  e8 06 80 00  ld  [ %i2 ], %l4
a013e0d0:  7f fe 7d 51  call  0xa00dd614
a013e0d4:  90 10 20 04  mov  4, %o0
a013e0d8:  80 8a 20 ff  btst  0xff, %o0
a013e0dc:  32 80 02 9d  bne,a   0xa013eb50
a013e0e0:  d2 06 a0 70  ld  [ %i2 + 0x70 ], %o1
a013e0e4:  ee 06 80 00  ld  [ %i2 ], %l7
a013e0e8:  ad 35 e0 0c  srl  %l7, 0xc, %l6
a013e0ec:  90 0d a0 0f  and  %l6, 0xf, %o0
a013e0f0:  7f ff d2 1d  call  0xa0132964
a013e0f4:  92 0f 20 ff  and  %i4, 0xff, %o1
a013e0f8:  aa 0a 20 ff  and  %o0, 0xff, %l5
a013e0fc:  80 a5 60 01  cmp  %l5, 1
a013e100:  02 bf ff 42  be  0xa013de08
a013e104:  21 02 40 00  sethi  %hi(0x9000000), %l0
a013e108:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e10c:  90 0b c0 10  and  %o7, %l0, %o0
a013e110:  80 a2 00 10  cmp  %o0, %l0
a013e114:  12 bf ff 3f  bne  0xa013de10
a013e118:  17 00 10 00  sethi  %hi(0x400000), %o3
a013e11c:  d8 06 80 00  ld  [ %i2 ], %o4
a013e120:  03 00 3c 00  sethi  %hi(0xf00000), %g1
a013e124:  94 2b 00 01  andn  %o4, %g1, %o2
a013e128:  27 3c 00 00  sethi  %hi(0xf0000000), %l3
a013e12c:  a4 2a 80 13  andn  %o2, %l3, %l2
a013e130:  23 28 00 00  sethi  %hi(0xa0000000), %l1
a013e134:  82 14 80 11  or  %l2, %l1, %g1
a013e138:  10 bf ff 64  b  0xa013dec8
a013e13c:  c2 26 80 00  st  %g1, [ %i2 ]
a013e140:  95 32 20 0c  srl  %o0, 0xc, %o2
a013e144:  a6 0a a0 0f  and  %o2, 0xf, %l3
a013e148:  98 5c e0 2a  smul  %l3, 0x2a, %o4
a013e14c:  96 16 22 24  or  %i0, 0x224, %o3
a013e150:  9e 03 00 0b  add  %o4, %o3, %o7
a013e154:  e2 0b e0 02  ldub  [ %o7 + 2 ], %l1
a013e158:  80 a4 60 04  cmp  %l1, 4
a013e15c:  32 bf ff 9f  bne,a   0xa013dfd8
a013e160:  e8 06 80 00  ld  [ %i2 ], %l4
a013e164:  e8 12 c0 0c  lduh  [ %o3 + %o4 ], %l4
a013e168:  83 35 20 0c  srl  %l4, 0xc, %g1
a013e16c:  80 88 60 01  btst  1, %g1
a013e170:  32 bf ff 9a  bne,a   0xa013dfd8
a013e174:  e8 06 80 00  ld  [ %i2 ], %l4
a013e178:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e17c:  1b 00 80 00  sethi  %hi(0x2000000), %o5
a013e180:  80 8b c0 0d  btst  %o7, %o5
a013e184:  12 bf ff 23  bne  0xa013de10
a013e188:  17 00 10 00  sethi  %hi(0x400000), %o3
a013e18c:  ab 32 20 14  srl  %o0, 0x14, %l5
a013e190:  82 0d 60 0f  and  %l5, 0xf, %g1
a013e194:  80 a0 60 07  cmp  %g1, 7
a013e198:  38 bf ff 1f  bgu,a   0xa013de14
a013e19c:  80 8b c0 0b  btst  %o7, %o3
a013e1a0:  3b 00 03 72  sethi  %hi(0xdc800), %i5
a013e1a4:  af 28 60 02  sll  %g1, 2, %l7
a013e1a8:  96 17 60 bc  or  %i5, 0xbc, %o3
a013e1ac:  ec 02 c0 17  ld  [ %o3 + %l7 ], %l6
a013e1b0:  81 c5 80 00  jmp  %l6
a013e1b4:  01 00 00 00  nop
a013e1b8:  ab 32 20 0c  srl  %o0, 0xc, %l5
a013e1bc:  9a 0d 60 0f  and  %l5, 0xf, %o5
a013e1c0:  90 5b 60 2a  smul  %o5, 0x2a, %o0
a013e1c4:  a2 16 22 24  or  %i0, 0x224, %l1
a013e1c8:  a8 02 00 11  add  %o0, %l1, %l4
a013e1cc:  d4 0d 20 02  ldub  [ %l4 + 2 ], %o2
a013e1d0:  80 a2 a0 04  cmp  %o2, 4
a013e1d4:  32 bf ff 81  bne,a   0xa013dfd8
a013e1d8:  e8 06 80 00  ld  [ %i2 ], %l4
a013e1dc:  ee 14 40 08  lduh  [ %l1 + %o0 ], %l7
a013e1e0:  ad 35 e0 0c  srl  %l7, 0xc, %l6
a013e1e4:  80 8d a0 01  btst  1, %l6
a013e1e8:  32 bf ff 7c  bne,a   0xa013dfd8
a013e1ec:  e8 06 80 00  ld  [ %i2 ], %l4
a013e1f0:  7f fe 7d 09  call  0xa00dd614
a013e1f4:  90 10 20 04  mov  4, %o0
a013e1f8:  80 8a 20 ff  btst  0xff, %o0
a013e1fc:  32 80 02 4b  bne,a   0xa013eb28
a013e200:  17 00 06 96  sethi  %hi(0x1a5800), %o3
a013e204:  e4 06 80 00  ld  [ %i2 ], %l2
a013e208:  91 34 a0 0c  srl  %l2, 0xc, %o0
a013e20c:  a0 0a 20 0f  and  %o0, 0xf, %l0
a013e210:  98 5c 20 2a  smul  %l0, 0x2a, %o4
a013e214:  92 03 00 11  add  %o4, %l1, %o1
a013e218:  7f ff 0b 84  call  0xa0101028
a013e21c:  d0 0a 60 28  ldub  [ %o1 + 0x28 ], %o0
a013e220:  d6 06 a0 70  ld  [ %i2 + 0x70 ], %o3
a013e224:  3b 00 00 30  sethi  %hi(0xc000), %i5
a013e228:  ae 0a c0 1d  and  %o3, %i5, %l7
a013e22c:  ec 06 80 00  ld  [ %i2 ], %l6
a013e230:  80 a0 00 17  cmp  %g0, %l7
a013e234:  d0 2e a0 3e  stb  %o0, [ %i2 + 0x3e ]
a013e238:  a6 0f 20 ff  and  %i4, 0xff, %l3
a013e23c:  ab 35 a0 0c  srl  %l6, 0xc, %l5
a013e240:  94 60 3f ff  subx  %g0, -1, %o2
a013e244:  92 0d 60 0f  and  %l5, 0xf, %o1
a013e248:  7f ff f7 bf  call  0xa013c144
a013e24c:  90 10 00 13  mov  %l3, %o0
a013e250:  da 06 80 00  ld  [ %i2 ], %o5
a013e254:  a9 33 60 0c  srl  %o5, 0xc, %l4
a013e258:  92 0d 20 0f  and  %l4, 0xf, %o1
a013e25c:  82 5a 60 2a  smul  %o1, 0x2a, %g1
a013e260:  d4 06 a0 70  ld  [ %i2 + 0x70 ], %o2
a013e264:  a4 00 40 11  add  %g1, %l1, %l2
a013e268:  9f 32 a0 0c  srl  %o2, 0xc, %o7
a013e26c:  90 10 00 13  mov  %l3, %o0
a013e270:  d8 0c a0 28  ldub  [ %l2 + 0x28 ], %o4
a013e274:  94 0b e0 03  and  %o7, 3, %o2
a013e278:  7f ff 0d 0b  call  0xa01016a4
a013e27c:  96 10 20 01  mov  1, %o3
a013e280:  d0 06 80 00  ld  [ %i2 ], %o0
a013e284:  21 3c 00 00  sethi  %hi(0xf0000000), %l0
a013e288:  92 2a 00 10  andn  %o0, %l0, %o1
a013e28c:  19 20 00 00  sethi  %hi(0x80000000), %o4
a013e290:  a2 12 40 0c  or  %o1, %o4, %l1
a013e294:  3b 00 3c 00  sethi  %hi(0xf00000), %i5
a013e298:  82 2c 40 1d  andn  %l1, %i5, %g1
a013e29c:  c2 26 80 00  st  %g1, [ %i2 ]
a013e2a0:  10 bf fe db  b  0xa013de0c
a013e2a4:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e2a8:  a1 32 20 0c  srl  %o0, 0xc, %l0
a013e2ac:  96 0c 20 0f  and  %l0, 0xf, %o3
a013e2b0:  a0 16 22 24  or  %i0, 0x224, %l0
a013e2b4:  98 5a e0 2a  smul  %o3, 0x2a, %o4
a013e2b8:  ac 03 00 10  add  %o4, %l0, %l6
a013e2bc:  ea 0d a0 02  ldub  [ %l6 + 2 ], %l5
a013e2c0:  80 a5 60 04  cmp  %l5, 4
a013e2c4:  22 80 01 5a  be,a   0xa013e82c
a013e2c8:  fa 14 00 0c  lduh  [ %l0 + %o4 ], %i5
a013e2cc:  e6 06 80 00  ld  [ %i2 ], %l3
a013e2d0:  1f 3c 00 00  sethi  %hi(0xf0000000), %o7
a013e2d4:  98 2c c0 0f  andn  %l3, %o7, %o4
a013e2d8:  d6 06 a0 70  ld  [ %i2 + 0x70 ], %o3
a013e2dc:  03 14 00 00  sethi  %hi(0x50000000), %g1
a013e2e0:  98 13 00 01  or  %o4, %g1, %o4
a013e2e4:  23 00 10 00  sethi  %hi(0x400000), %l1
a013e2e8:  9e 2a c0 11  andn  %o3, %l1, %o7
a013e2ec:  10 bf ff 43  b  0xa013dff8
a013e2f0:  d8 26 80 00  st  %o4, [ %i2 ]
a013e2f4:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e2f8:  19 00 00 80  sethi  %hi(0x20000), %o4
a013e2fc:  80 8b c0 0c  btst  %o7, %o4
a013e300:  12 80 01 42  bne  0xa013e808
a013e304:  9b 32 20 0c  srl  %o0, 0xc, %o5
a013e308:  a7 32 20 0c  srl  %o0, 0xc, %l3
a013e30c:  a4 0c e0 0f  and  %l3, 0xf, %l2
a013e310:  96 5c a0 2a  smul  %l2, 0x2a, %o3
a013e314:  a0 16 22 24  or  %i0, 0x224, %l0
a013e318:  94 02 c0 10  add  %o3, %l0, %o2
a013e31c:  d2 0a a0 02  ldub  [ %o2 + 2 ], %o1
a013e320:  80 a2 60 04  cmp  %o1, 4
a013e324:  12 bf fe bb  bne  0xa013de10
a013e328:  17 00 10 00  sethi  %hi(0x400000), %o3
a013e32c:  29 3c 00 00  sethi  %hi(0xf0000000), %l4
a013e330:  a4 2a 00 14  andn  %o0, %l4, %l2
a013e334:  27 18 00 00  sethi  %hi(0x60000000), %l3
a013e338:  96 14 80 13  or  %l2, %l3, %o3
a013e33c:  15 00 3c 00  sethi  %hi(0xf00000), %o2
a013e340:  a8 2a c0 0a  andn  %o3, %o2, %l4
a013e344:  93 35 20 0c  srl  %l4, 0xc, %o1
a013e348:  9a 0a 60 0f  and  %o1, 0xf, %o5
a013e34c:  03 00 00 30  sethi  %hi(0xc000), %g1
a013e350:  90 2b c0 01  andn  %o7, %g1, %o0
a013e354:  aa 5b 60 2a  smul  %o5, 0x2a, %l5
a013e358:  fa 14 00 15  lduh  [ %l0 + %l5 ], %i5
a013e35c:  1f 20 00 00  sethi  %hi(0x80000000), %o7
a013e360:  2f 00 00 04  sethi  %hi(0x1000), %l7
a013e364:  a2 2a 00 0f  andn  %o0, %o7, %l1
a013e368:  19 02 00 00  sethi  %hi(0x8000000), %o4
a013e36c:  ac 2f 40 17  andn  %i5, %l7, %l6
a013e370:  9e 2c 40 0c  andn  %l1, %o4, %o7
a013e374:  ec 34 00 15  sth  %l6, [ %l0 + %l5 ]
a013e378:  17 00 10 00  sethi  %hi(0x400000), %o3
a013e37c:  de 26 a0 70  st  %o7, [ %i2 + 0x70 ]
a013e380:  e8 26 80 00  st  %l4, [ %i2 ]
a013e384:  10 bf fe a4  b  0xa013de14
a013e388:  80 8b c0 0b  btst  %o7, %o3
a013e38c:  fa 06 a0 70  ld  [ %i2 + 0x70 ], %i5
a013e390:  a6 2a 00 12  andn  %o0, %l2, %l3
a013e394:  1b 14 00 00  sethi  %hi(0x50000000), %o5
a013e398:  23 00 10 00  sethi  %hi(0x400000), %l1
a013e39c:  92 2f 40 11  andn  %i5, %l1, %o1
a013e3a0:  96 14 c0 0d  or  %l3, %o5, %o3
a013e3a4:  d2 26 a0 70  st  %o1, [ %i2 + 0x70 ]
a013e3a8:  d6 26 80 00  st  %o3, [ %i2 ]
a013e3ac:  7f fe 7c 9a  call  0xa00dd614
a013e3b0:  90 10 20 04  mov  4, %o0
a013e3b4:  80 8a 20 ff  btst  0xff, %o0
a013e3b8:  22 bf fe 95  be,a   0xa013de0c
a013e3bc:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e3c0:  11 00 06 96  sethi  %hi(0x1a5800), %o0
a013e3c4:  90 12 20 20  or  %o0, 0x20, %o0	! 0x1a5820
a013e3c8:  7f fe 83 6a  call  0xa00df170
a013e3cc:  d2 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o1
a013e3d0:  10 bf fe 8f  b  0xa013de0c
a013e3d4:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e3d8:  ad 32 20 0c  srl  %o0, 0xc, %l6
a013e3dc:  90 0d a0 0f  and  %l6, 0xf, %o0
a013e3e0:  7f fe c8 46  call  0xa00f04f8
a013e3e4:  92 10 20 00  clr  %o1
a013e3e8:  80 8a 20 ff  btst  0xff, %o0
a013e3ec:  22 bf fe 88  be,a   0xa013de0c
a013e3f0:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e3f4:  e4 06 80 00  ld  [ %i2 ], %l2
a013e3f8:  11 00 3c 00  sethi  %hi(0xf00000), %o0
a013e3fc:  a0 2c 80 08  andn  %l2, %o0, %l0
a013e400:  2f 3c 00 00  sethi  %hi(0xf0000000), %l7
a013e404:  98 2c 00 17  andn  %l0, %l7, %o4
a013e408:  d6 06 a0 70  ld  [ %i2 + 0x70 ], %o3
a013e40c:  10 bf ff b5  b  0xa013e2e0
a013e410:  03 30 00 00  sethi  %hi(0xc0000000), %g1
a013e414:  67 fd 3c 60  call  0x4008d594
a013e418:  d0 16 a0 04  lduh  [ %i2 + 4 ], %o0
a013e41c:  83 2a 20 10  sll  %o0, 0x10, %g1
a013e420:  95 30 60 10  srl  %g1, 0x10, %o2
a013e424:  80 a2 a0 32  cmp  %o2, 0x32
a013e428:  28 bf fe 79  bleu,a   0xa013de0c
a013e42c:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e430:  ea 06 80 00  ld  [ %i2 ], %l5
a013e434:  93 35 60 0c  srl  %l5, 0xc, %o1
a013e438:  90 0a 60 0f  and  %o1, 0xf, %o0
a013e43c:  7f fe c8 2f  call  0xa00f04f8
a013e440:  92 10 20 01  mov  1, %o1
a013e444:  e8 06 80 00  ld  [ %i2 ], %l4
a013e448:  3b 00 3c 00  sethi  %hi(0xf00000), %i5
a013e44c:  96 2d 00 1d  andn  %l4, %i5, %o3
a013e450:  1b 00 1c 00  sethi  %hi(0x700000), %o5
a013e454:  82 12 c0 0d  or  %o3, %o5, %g1
a013e458:  10 bf ff 92  b  0xa013e2a0
a013e45c:  c2 26 80 00  st  %g1, [ %i2 ]
a013e460:  7f fe 7c 6d  call  0xa00dd614
a013e464:  90 10 20 04  mov  4, %o0
a013e468:  80 8a 20 ff  btst  0xff, %o0
a013e46c:  02 80 00 05  be  0xa013e480
a013e470:  3b 00 06 96  sethi  %hi(0x1a5800), %i5
a013e474:  90 17 60 40  or  %i5, 0x40, %o0	! 0x1a5840
a013e478:  7f fe 83 3e  call  0xa00df170
a013e47c:  d2 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o1
a013e480:  67 fd 3c 45  call  0x4008d594
a013e484:  d0 16 a0 04  lduh  [ %i2 + 4 ], %o0
a013e488:  a9 2a 20 10  sll  %o0, 0x10, %l4
a013e48c:  93 35 20 10  srl  %l4, 0x10, %o1
a013e490:  80 a2 60 28  cmp  %o1, 0x28
a013e494:  28 bf fe 5e  bleu,a   0xa013de0c
a013e498:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e49c:  ec 06 a0 70  ld  [ %i2 + 0x70 ], %l6
a013e4a0:  2b 00 00 80  sethi  %hi(0x20000), %l5
a013e4a4:  80 8d 80 15  btst  %l6, %l5
a013e4a8:  22 80 02 8e  be,a   0xa013eee0
a013e4ac:  d2 06 80 00  ld  [ %i2 ], %o1
a013e4b0:  c2 06 80 00  ld  [ %i2 ], %g1
a013e4b4:  95 30 60 0c  srl  %g1, 0xc, %o2
a013e4b8:  7f fe c2 b1  call  0xa00eef7c
a013e4bc:  90 0a a0 0f  and  %o2, 0xf, %o0
a013e4c0:  a2 07 bf 20  add  %fp, -224, %l1
a013e4c4:  92 06 a0 06  add  %i2, 6, %o1
a013e4c8:  94 10 20 3c  mov  0x3c, %o2
a013e4cc:  7f ff f9 11  call  0xa013c910
a013e4d0:  90 10 00 11  mov  %l1, %o0
a013e4d4:  de 06 80 00  ld  [ %i2 ], %o7
a013e4d8:  a7 33 e0 0c  srl  %o7, 0xc, %l3
a013e4dc:  90 0c e0 0f  and  %l3, 0xf, %o0
a013e4e0:  92 10 00 11  mov  %l1, %o1
a013e4e4:  7f ff fd ba  call  0xa013dbcc
a013e4e8:  94 07 bf d8  add  %fp, -40, %o2
a013e4ec:  d4 1f bf e0  ldd  [ %fp + -32 ], %o2
a013e4f0:  d8 1f bf d8  ldd  [ %fp + -40 ], %o4
a013e4f4:  d4 3f bf 18  std  %o2, [ %fp + -232 ]
a013e4f8:  d8 3f bf 10  std  %o4, [ %fp + -240 ]
a013e4fc:  90 10 20 01  mov  1, %o0
a013e500:  92 10 20 01  mov  1, %o1
a013e504:  7f fe c3 2b  call  0xa00ef1b0
a013e508:  94 07 bf 10  add  %fp, -240, %o2
a013e50c:  e4 06 80 00  ld  [ %i2 ], %l2
a013e510:  11 00 3c 00  sethi  %hi(0xf00000), %o0
a013e514:  a0 2c 80 08  andn  %l2, %o0, %l0
a013e518:  19 00 18 00  sethi  %hi(0x600000), %o4
a013e51c:  ae 14 00 0c  or  %l0, %o4, %l7
a013e520:  67 fd 3c 1a  call  0x4008d588
a013e524:  ee 26 80 00  st  %l7, [ %i2 ]
a013e528:  c2 06 a0 70  ld  [ %i2 + 0x70 ], %g1
a013e52c:  d0 36 a0 04  sth  %o0, [ %i2 + 4 ]
a013e530:  9e 08 77 ff  and  %g1, -2049, %o7
a013e534:  10 bf fe b2  b  0xa013dffc
a013e538:  de 26 a0 70  st  %o7, [ %i2 + 0x70 ]
a013e53c:  7f fe 7c 36  call  0xa00dd614
a013e540:  90 10 20 04  mov  4, %o0
a013e544:  80 8a 20 ff  btst  0xff, %o0
a013e548:  22 80 00 07  be,a   0xa013e564
a013e54c:  d6 06 80 00  ld  [ %i2 ], %o3
a013e550:  2f 00 06 96  sethi  %hi(0x1a5800), %l7
a013e554:  90 15 e0 58  or  %l7, 0x58, %o0	! 0x1a5858
a013e558:  7f fe 83 06  call  0xa00df170
a013e55c:  d2 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o1
a013e560:  d6 06 80 00  ld  [ %i2 ], %o3
a013e564:  9b 32 e0 0c  srl  %o3, 0xc, %o5
a013e568:  90 0b 60 0f  and  %o5, 0xf, %o0
a013e56c:  d4 16 a0 08  lduh  [ %i2 + 8 ], %o2
a013e570:  7f ff 18 0c  call  0xa01045a0
a013e574:  92 06 a0 60  add  %i2, 0x60, %o1
a013e578:  e6 06 80 00  ld  [ %i2 ], %l3
a013e57c:  83 34 e0 14  srl  %l3, 0x14, %g1
a013e580:  94 08 60 0f  and  %g1, 0xf, %o2
a013e584:  9e 02 a0 01  add  %o2, 1, %o7
a013e588:  a4 0b e0 0f  and  %o7, 0xf, %l2
a013e58c:  23 00 3c 00  sethi  %hi(0xf00000), %l1
a013e590:  a0 2c c0 11  andn  %l3, %l1, %l0
a013e594:  91 2c a0 14  sll  %l2, 0x14, %o0
a013e598:  98 14 00 08  or  %l0, %o0, %o4
a013e59c:  d8 26 80 00  st  %o4, [ %i2 ]
a013e5a0:  67 fd 3b fa  call  0x4008d588
a013e5a4:  01 00 00 00  nop
a013e5a8:  d0 36 a0 04  sth  %o0, [ %i2 + 4 ]
a013e5ac:  10 bf fe 18  b  0xa013de0c
a013e5b0:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e5b4:  7f fe 7c 18  call  0xa00dd614
a013e5b8:  90 10 20 04  mov  4, %o0
a013e5bc:  80 8a 20 ff  btst  0xff, %o0
a013e5c0:  22 80 00 07  be,a   0xa013e5dc
a013e5c4:  ec 06 80 00  ld  [ %i2 ], %l6
a013e5c8:  27 00 06 96  sethi  %hi(0x1a5800), %l3
a013e5cc:  90 14 e0 70  or  %l3, 0x70, %o0	! 0x1a5870
a013e5d0:  7f fe 82 e8  call  0xa00df170
a013e5d4:  d2 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o1
a013e5d8:  ec 06 80 00  ld  [ %i2 ], %l6
a013e5dc:  ab 35 a0 0c  srl  %l6, 0xc, %l5
a013e5e0:  92 06 a0 60  add  %i2, 0x60, %o1
a013e5e4:  7f ff 17 67  call  0xa0104380
a013e5e8:  90 0d 60 0f  and  %l5, 0xf, %o0
a013e5ec:  d6 06 80 00  ld  [ %i2 ], %o3
a013e5f0:  a9 32 e0 14  srl  %o3, 0x14, %l4
a013e5f4:  92 0d 20 0f  and  %l4, 0xf, %o1
a013e5f8:  ba 02 60 01  add  %o1, 1, %i5
a013e5fc:  1b 00 3c 00  sethi  %hi(0xf00000), %o5
a013e600:  82 0f 60 0f  and  %i5, 0xf, %g1
a013e604:  9e 2a c0 0d  andn  %o3, %o5, %o7
a013e608:  95 28 60 14  sll  %g1, 0x14, %o2
a013e60c:  9a 13 c0 0a  or  %o7, %o2, %o5
a013e610:  10 bf fe 36  b  0xa013dee8
a013e614:  da 26 80 00  st  %o5, [ %i2 ]
a013e618:  67 fd 3b df  call  0x4008d594
a013e61c:  d0 16 a0 04  lduh  [ %i2 + 4 ], %o0
a013e620:  a7 2a 20 10  sll  %o0, 0x10, %l3
a013e624:  a3 34 e0 10  srl  %l3, 0x10, %l1
a013e628:  80 a4 60 50  cmp  %l1, 0x50
a013e62c:  28 bf fd f8  bleu,a   0xa013de0c
a013e630:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e634:  7f fe 7b f8  call  0xa00dd614
a013e638:  90 10 20 04  mov  4, %o0
a013e63c:  80 8a 20 ff  btst  0xff, %o0
a013e640:  32 80 02 88  bne,a   0xa013f060
a013e644:  1f 00 06 96  sethi  %hi(0x1a5800), %o7
a013e648:  92 06 a0 06  add  %i2, 6, %o1
a013e64c:  94 10 20 3c  mov  0x3c, %o2
a013e650:  7f ff f8 b0  call  0xa013c910
a013e654:  90 07 bf 88  add  %fp, -120, %o0
a013e658:  2f 2a 00 b8  sethi  %hi(0xa802e000), %l7
a013e65c:  d2 06 a0 70  ld  [ %i2 + 0x70 ], %o1
a013e660:  ec 05 e3 d0  ld  [ %l7 + 0x3d0 ], %l6
a013e664:  a9 35 a0 19  srl  %l6, 0x19, %l4
a013e668:  ab 32 60 1f  srl  %o1, 0x1f, %l5
a013e66c:  ba 0d 00 15  and  %l4, %l5, %i5
a013e670:  d4 06 80 00  ld  [ %i2 ], %o2
a013e674:  e0 1e a0 48  ldd  [ %i2 + 0x48 ], %l0
a013e678:  e4 1e a0 50  ldd  [ %i2 + 0x50 ], %l2
a013e67c:  e8 1e a0 58  ldd  [ %i2 + 0x58 ], %l4
a013e680:  ec 1e a0 60  ldd  [ %i2 + 0x60 ], %l6
a013e684:  97 32 a0 0c  srl  %o2, 0xc, %o3
a013e688:  e0 3f bf 60  std  %l0, [ %fp + -160 ]
a013e68c:  e4 3f bf 68  std  %l2, [ %fp + -152 ]
a013e690:  e8 3f bf 70  std  %l4, [ %fp + -144 ]
a013e694:  ec 3f bf 78  std  %l6, [ %fp + -136 ]
a013e698:  83 32 a0 08  srl  %o2, 8, %g1
a013e69c:  9b 32 60 14  srl  %o1, 0x14, %o5
a013e6a0:  e0 1e a0 68  ldd  [ %i2 + 0x68 ], %l0
a013e6a4:  90 0a e0 0f  and  %o3, 0xf, %o0
a013e6a8:  e0 3f bf 80  std  %l0, [ %fp + -128 ]
a013e6ac:  fa 23 a0 5c  st  %i5, [ %sp + 0x5c ]
a013e6b0:  92 08 60 0f  and  %g1, 0xf, %o1
a013e6b4:  94 0a a0 01  and  %o2, 1, %o2
a013e6b8:  96 07 bf 88  add  %fp, -120, %o3
a013e6bc:  9a 0b 60 01  and  %o5, 1, %o5
a013e6c0:  7f ff 14 80  call  0xa01038c0
a013e6c4:  98 07 bf 60  add  %fp, -160, %o4
a013e6c8:  e2 06 80 00  ld  [ %i2 ], %l1
a013e6cc:  25 00 3c 00  sethi  %hi(0xf00000), %l2
a013e6d0:  a0 2c 40 12  andn  %l1, %l2, %l0
a013e6d4:  11 00 14 00  sethi  %hi(0x500000), %o0
a013e6d8:  98 14 00 08  or  %l0, %o0, %o4
a013e6dc:  10 bf ff b1  b  0xa013e5a0
a013e6e0:  d8 26 80 00  st  %o4, [ %i2 ]
a013e6e4:  7f fe 7b cc  call  0xa00dd614
a013e6e8:  90 10 20 04  mov  4, %o0
a013e6ec:  80 8a 20 ff  btst  0xff, %o0
a013e6f0:  02 80 00 05  be  0xa013e704
a013e6f4:  1f 00 06 96  sethi  %hi(0x1a5800), %o7
a013e6f8:  90 13 e0 a0  or  %o7, 0xa0, %o0	! 0x1a58a0
a013e6fc:  7f fe 82 9d  call  0xa00df170
a013e700:  d2 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o1
a013e704:  7f ff fb e0  call  0xa013d684
a013e708:  d0 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o0
a013e70c:  7f ff fc 83  call  0xa013d918
a013e710:  d0 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o0
a013e714:  d0 06 80 00  ld  [ %i2 ], %o0
a013e718:  92 0a 20 01  and  %o0, 1, %o1
a013e71c:  e4 06 a0 70  ld  [ %i2 + 0x70 ], %l2
a013e720:  99 32 20 0c  srl  %o0, 0xc, %o4
a013e724:  90 0b 20 0f  and  %o4, 0xf, %o0
a013e728:  a1 34 a0 14  srl  %l2, 0x14, %l0
a013e72c:  94 0c 20 01  and  %l0, 1, %o2
a013e730:  96 06 a0 06  add  %i2, 6, %o3
a013e734:  7f ff 12 ca  call  0xa010325c
a013e738:  98 06 a0 48  add  %i2, 0x48, %o4
a013e73c:  ee 06 80 00  ld  [ %i2 ], %l7
a013e740:  93 35 e0 14  srl  %l7, 0x14, %o1
a013e744:  ba 0a 60 0f  and  %o1, 0xf, %i5
a013e748:  96 07 60 01  add  %i5, 1, %o3
a013e74c:  aa 0a e0 0f  and  %o3, 0xf, %l5
a013e750:  2d 00 3c 00  sethi  %hi(0xf00000), %l6
a013e754:  9a 2d c0 16  andn  %l7, %l6, %o5
a013e758:  83 2d 60 14  sll  %l5, 0x14, %g1
a013e75c:  a8 13 40 01  or  %o5, %g1, %l4
a013e760:  67 fd 3b 8a  call  0x4008d588
a013e764:  e8 26 80 00  st  %l4, [ %i2 ]
a013e768:  d4 06 a0 40  ld  [ %i2 + 0x40 ], %o2
a013e76c:  80 a2 a0 00  cmp  %o2, 0
a013e770:  16 bf fd a6  bge  0xa013de08
a013e774:  d0 36 a0 04  sth  %o0, [ %i2 + 4 ]
a013e778:  da 06 a0 70  ld  [ %i2 + 0x70 ], %o5
a013e77c:  03 00 10 00  sethi  %hi(0x400000), %g1
a013e780:  9e 2b 40 01  andn  %o5, %g1, %o7
a013e784:  10 bf fe 1e  b  0xa013dffc
a013e788:  de 26 a0 70  st  %o7, [ %i2 + 0x70 ]
a013e78c:  7f fe 7b a2  call  0xa00dd614
a013e790:  90 10 20 04  mov  4, %o0
a013e794:  80 8a 20 ff  btst  0xff, %o0
a013e798:  22 80 00 07  be,a   0xa013e7b4
a013e79c:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e7a0:  13 00 06 96  sethi  %hi(0x1a5800), %o1
a013e7a4:  90 12 60 b8  or  %o1, 0xb8, %o0	! 0x1a58b8
a013e7a8:  7f fe 82 72  call  0xa00df170
a013e7ac:  d2 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o1
a013e7b0:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e7b4:  19 00 00 80  sethi  %hi(0x20000), %o4
a013e7b8:  80 8b c0 0c  btst  %o7, %o4
a013e7bc:  12 80 01 bf  bne  0xa013eeb8
a013e7c0:  27 2a 00 b3  sethi  %hi(0xa802cc00), %l3
a013e7c4:  c2 04 e0 28  ld  [ %l3 + 0x28 ], %g1	! 0xa802cc28
a013e7c8:  80 a0 60 00  cmp  %g1, 0
a013e7cc:  12 80 02 13  bne  0xa013f018
a013e7d0:  d0 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o0
a013e7d4:  c2 06 80 00  ld  [ %i2 ], %g1
a013e7d8:  ab 30 60 14  srl  %g1, 0x14, %l5
a013e7dc:  ac 0d 60 0f  and  %l5, 0xf, %l6
a013e7e0:  98 05 a0 01  add  %l6, 1, %o4
a013e7e4:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a013e7e8:  a8 0b 20 0f  and  %o4, 0xf, %l4
a013e7ec:  94 28 40 0b  andn  %g1, %o3, %o2
a013e7f0:  a1 2d 20 14  sll  %l4, 0x14, %l0
a013e7f4:  90 12 80 10  or  %o2, %l0, %o0
a013e7f8:  17 00 10 00  sethi  %hi(0x400000), %o3
a013e7fc:  d0 26 80 00  st  %o0, [ %i2 ]
a013e800:  10 bf fd 85  b  0xa013de14
a013e804:  80 8b c0 0b  btst  %o7, %o3
a013e808:  7f fe c2 10  call  0xa00ef048
a013e80c:  90 0b 60 0f  and  %o5, 0xf, %o0
a013e810:  c2 06 80 00  ld  [ %i2 ], %g1
a013e814:  91 30 60 0c  srl  %g1, 0xc, %o0
a013e818:  7f fe ca 4e  call  0xa00f1150
a013e81c:  90 0a 20 0f  and  %o0, 0xf, %o0
a013e820:  d0 06 80 00  ld  [ %i2 ], %o0
a013e824:  10 bf fe b9  b  0xa013e308
a013e828:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e82c:  af 37 60 0c  srl  %i5, 0xc, %l7
a013e830:  80 8d e0 01  btst  1, %l7
a013e834:  32 bf fe a7  bne,a   0xa013e2d0
a013e838:  e6 06 80 00  ld  [ %i2 ], %l3
a013e83c:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e840:  23 00 80 00  sethi  %hi(0x2000000), %l1
a013e844:  80 8b c0 11  btst  %o7, %l1
a013e848:  32 bf fd 72  bne,a   0xa013de10
a013e84c:  17 00 10 00  sethi  %hi(0x400000), %o3
a013e850:  19 00 00 80  sethi  %hi(0x20000), %o4
a013e854:  80 8b c0 0c  btst  %o7, %o4
a013e858:  12 80 00 c8  bne  0xa013eb78
a013e85c:  01 00 00 00  nop
a013e860:  83 32 20 14  srl  %o0, 0x14, %g1
a013e864:  82 88 60 0f  andcc  %g1, 0xf, %g1
a013e868:  02 bf fd 32  be  0xa013dd30
a013e86c:  80 a0 60 01  cmp  %g1, 1
a013e870:  12 bf fd 68  bne  0xa013de10
a013e874:  17 00 10 00  sethi  %hi(0x400000), %o3
a013e878:  7f fe 7b 67  call  0xa00dd614
a013e87c:  90 10 20 04  mov  4, %o0
a013e880:  80 8a 20 ff  btst  0xff, %o0
a013e884:  22 80 00 07  be,a   0xa013e8a0
a013e888:  d6 06 80 00  ld  [ %i2 ], %o3
a013e88c:  1f 00 06 96  sethi  %hi(0x1a5800), %o7
a013e890:  90 13 e0 d0  or  %o7, 0xd0, %o0	! 0x1a58d0
a013e894:  7f fe 82 37  call  0xa00df170
a013e898:  d2 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o1
a013e89c:  d6 06 80 00  ld  [ %i2 ], %o3
a013e8a0:  af 32 e0 0c  srl  %o3, 0xc, %l7
a013e8a4:  40 00 02 b3  call  0xa013f370
a013e8a8:  90 0d e0 0f  and  %l7, 0xf, %o0
a013e8ac:  ec 06 80 00  ld  [ %i2 ], %l6
a013e8b0:  2b 00 3c 00  sethi  %hi(0xf00000), %l5
a013e8b4:  9a 2d 80 15  andn  %l6, %l5, %o5
a013e8b8:  29 3c 00 00  sethi  %hi(0xf0000000), %l4
a013e8bc:  a6 2b 40 14  andn  %o5, %l4, %l3
a013e8c0:  15 1c 00 00  sethi  %hi(0x70000000), %o2
a013e8c4:  82 14 c0 0a  or  %l3, %o2, %g1
a013e8c8:  a5 30 60 0c  srl  %g1, 0xc, %l2
a013e8cc:  c2 26 80 00  st  %g1, [ %i2 ]
a013e8d0:  7f ff f4 51  call  0xa013ba14
a013e8d4:  90 0c a0 0f  and  %l2, 0xf, %o0
a013e8d8:  80 8a 20 ff  btst  0xff, %o0
a013e8dc:  22 80 01 74  be,a   0xa013eeac
a013e8e0:  d2 06 a0 70  ld  [ %i2 + 0x70 ], %o1
a013e8e4:  fa 06 a0 70  ld  [ %i2 + 0x70 ], %i5
a013e8e8:  23 08 00 00  sethi  %hi(0x20000000), %l1
a013e8ec:  82 17 40 11  or  %i5, %l1, %g1
a013e8f0:  d0 06 80 00  ld  [ %i2 ], %o0
a013e8f4:  a1 32 20 0c  srl  %o0, 0xc, %l0
a013e8f8:  c2 26 a0 70  st  %g1, [ %i2 + 0x70 ]
a013e8fc:  7f ff f4 95  call  0xa013bb50
a013e900:  90 0c 20 0f  and  %l0, 0xf, %o0
a013e904:  80 8a 20 ff  btst  0xff, %o0
a013e908:  22 80 01 66  be,a   0xa013eea0
a013e90c:  da 06 a0 70  ld  [ %i2 + 0x70 ], %o5
a013e910:  c2 06 a0 70  ld  [ %i2 + 0x70 ], %g1
a013e914:  25 04 00 00  sethi  %hi(0x10000000), %l2
a013e918:  9e 10 40 12  or  %g1, %l2, %o7
a013e91c:  10 bf fd b8  b  0xa013dffc
a013e920:  de 26 a0 70  st  %o7, [ %i2 + 0x70 ]
a013e924:  bb 34 a0 0c  srl  %l2, 0xc, %i5
a013e928:  80 8f 60 01  btst  1, %i5
a013e92c:  32 bf fd ab  bne,a   0xa013dfd8
a013e930:  e8 06 80 00  ld  [ %i2 ], %l4
a013e934:  7f fe 7b 38  call  0xa00dd614
a013e938:  90 10 20 04  mov  4, %o0
a013e93c:  80 8a 20 ff  btst  0xff, %o0
a013e940:  12 80 00 7f  bne  0xa013eb3c
a013e944:  11 00 06 96  sethi  %hi(0x1a5800), %o0
a013e948:  da 06 80 00  ld  [ %i2 ], %o5
a013e94c:  95 33 60 14  srl  %o5, 0x14, %o2
a013e950:  82 8a a0 0f  andcc  %o2, 0xf, %g1
a013e954:  22 80 00 13  be,a   0xa013e9a0
a013e958:  e8 06 a0 70  ld  [ %i2 + 0x70 ], %l4
a013e95c:  80 a0 60 01  cmp  %g1, 1
a013e960:  12 bf fd 2b  bne  0xa013de0c
a013e964:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e968:  2f 01 00 00  sethi  %hi(0x4000000), %l7
a013e96c:  80 8b c0 17  btst  %o7, %l7
a013e970:  02 bf fd 28  be  0xa013de10
a013e974:  17 00 10 00  sethi  %hi(0x400000), %o3
a013e978:  3b 00 3c 00  sethi  %hi(0xf00000), %i5
a013e97c:  a2 2b 40 1d  andn  %o5, %i5, %l1
a013e980:  27 3c 00 00  sethi  %hi(0xf0000000), %l3
a013e984:  9a 2c 40 13  andn  %l1, %l3, %o5
a013e988:  13 30 00 00  sethi  %hi(0xc0000000), %o1
a013e98c:  9a 13 40 09  or  %o5, %o1, %o5
a013e990:  da 26 80 00  st  %o5, [ %i2 ]
a013e994:  17 00 10 00  sethi  %hi(0x400000), %o3
a013e998:  10 bf fd 1f  b  0xa013de14
a013e99c:  80 8b c0 0b  btst  %o7, %o3
a013e9a0:  21 00 00 40  sethi  %hi(0x10000), %l0
a013e9a4:  80 8d 00 10  btst  %l4, %l0
a013e9a8:  02 80 00 0a  be  0xa013e9d0
a013e9ac:  01 00 00 00  nop
a013e9b0:  67 fd 3a f9  call  0x4008d594
a013e9b4:  d0 16 a0 04  lduh  [ %i2 + 4 ], %o0
a013e9b8:  97 2a 20 10  sll  %o0, 0x10, %o3
a013e9bc:  9f 32 e0 10  srl  %o3, 0x10, %o7
a013e9c0:  c2 16 a0 74  lduh  [ %i2 + 0x74 ], %g1
a013e9c4:  80 a3 c0 01  cmp  %o7, %g1
a013e9c8:  2a bf fd 11  bcs,a   0xa013de0c
a013e9cc:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e9d0:  40 00 0c 32  call  0xa0141a98
a013e9d4:  01 00 00 00  nop
a013e9d8:  80 8a 20 ff  btst  0xff, %o0
a013e9dc:  02 bf fd 0c  be  0xa013de0c
a013e9e0:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013e9e4:  19 0c 00 00  sethi  %hi(0x30000000), %o4
a013e9e8:  80 8b c0 0c  btst  %o7, %o4
a013e9ec:  32 bf ff 7b  bne,a   0xa013e7d8
a013e9f0:  c2 06 80 00  ld  [ %i2 ], %g1
a013e9f4:  2b 2a 00 b3  sethi  %hi(0xa802cc00), %l5
a013e9f8:  a0 15 60 1c  or  %l5, 0x1c, %l0	! 0xa802cc1c
a013e9fc:  ec 04 20 38  ld  [ %l0 + 0x38 ], %l6
a013ea00:  80 a5 a0 00  cmp  %l6, 0
a013ea04:  22 80 00 0a  be,a   0xa013ea2c
a013ea08:  e4 06 80 00  ld  [ %i2 ], %l2
a013ea0c:  d2 06 80 00  ld  [ %i2 ], %o1
a013ea10:  9b 32 60 0c  srl  %o1, 0xc, %o5
a013ea14:  7f ff f3 96  call  0xa013b86c
a013ea18:  90 0b 60 0f  and  %o5, 0xf, %o0
a013ea1c:  ee 04 20 38  ld  [ %l0 + 0x38 ], %l7
a013ea20:  9f c5 c0 00  call  %l7
a013ea24:  90 0a 20 ff  and  %o0, 0xff, %o0
a013ea28:  e4 06 80 00  ld  [ %i2 ], %l2
a013ea2c:  bb 34 a0 0c  srl  %l2, 0xc, %i5
a013ea30:  90 0f 60 0f  and  %i5, 0xf, %o0
a013ea34:  7f ff 67 fd  call  0xa0118a28
a013ea38:  92 10 20 00  clr  %o1
a013ea3c:  67 fd 3e 1a  call  0x4008e2a4
a013ea40:  01 00 00 00  nop
a013ea44:  67 fd 3e 18  call  0x4008e2a4
a013ea48:  01 00 00 00  nop
a013ea4c:  67 fd 3e 16  call  0x4008e2a4
a013ea50:  01 00 00 00  nop
a013ea54:  e2 06 80 00  ld  [ %i2 ], %l1
a013ea58:  a7 34 60 0c  srl  %l1, 0xc, %l3
a013ea5c:  90 0c e0 0f  and  %l3, 0xf, %o0
a013ea60:  67 fd 3e 59  call  0x4008e3c4
a013ea64:  92 10 20 00  clr  %o1
a013ea68:  10 bf ff 5b  b  0xa013e7d4
a013ea6c:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013ea70:  d2 06 80 00  ld  [ %i2 ], %o1
a013ea74:  19 3c 00 00  sethi  %hi(0xf0000000), %o4
a013ea78:  ac 2a 40 0c  andn  %o1, %o4, %l6
a013ea7c:  ae 12 e8 00  or  %o3, 0x800, %l7
a013ea80:  03 00 10 00  sethi  %hi(0x400000), %g1
a013ea84:  2b 14 00 00  sethi  %hi(0x50000000), %l5
a013ea88:  a8 2d c0 01  andn  %l7, %g1, %l4
a013ea8c:  9e 15 80 15  or  %l6, %l5, %o7
a013ea90:  21 00 06 96  sethi  %hi(0x1a5800), %l0
a013ea94:  e8 26 a0 70  st  %l4, [ %i2 + 0x70 ]
a013ea98:  de 26 80 00  st  %o7, [ %i2 ]
a013ea9c:  10 bf fe 4b  b  0xa013e3c8
a013eaa0:  90 14 21 10  or  %l0, 0x110, %o0
a013eaa4:  27 01 00 00  sethi  %hi(0x4000000), %l3
a013eaa8:  80 8b c0 13  btst  %o7, %l3
a013eaac:  02 bf fc d9  be  0xa013de10
a013eab0:  17 00 10 00  sethi  %hi(0x400000), %o3
a013eab4:  40 00 0c 0d  call  0xa0141ae8
a013eab8:  01 00 00 00  nop
a013eabc:  a2 0a 20 ff  and  %o0, 0xff, %l1
a013eac0:  80 a4 60 04  cmp  %l1, 4
a013eac4:  28 bf fc d2  bleu,a   0xa013de0c
a013eac8:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013eacc:  40 00 0c 07  call  0xa0141ae8
a013ead0:  01 00 00 00  nop
a013ead4:  ba 0a 20 ff  and  %o0, 0xff, %i5
a013ead8:  80 a7 60 06  cmp  %i5, 6
a013eadc:  38 bf fc cc  bgu,a   0xa013de0c
a013eae0:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013eae4:  c2 06 80 00  ld  [ %i2 ], %g1
a013eae8:  99 30 60 14  srl  %g1, 0x14, %o4
a013eaec:  96 0b 20 0f  and  %o4, 0xf, %o3
a013eaf0:  9e 02 e0 01  add  %o3, 1, %o7
a013eaf4:  a0 0b e0 0f  and  %o7, 0xf, %l0
a013eaf8:  29 00 3c 00  sethi  %hi(0xf00000), %l4
a013eafc:  a4 28 40 14  andn  %g1, %l4, %l2
a013eb00:  95 2c 20 14  sll  %l0, 0x14, %o2
a013eb04:  90 14 80 0a  or  %l2, %o2, %o0
a013eb08:  d0 26 80 00  st  %o0, [ %i2 ]
a013eb0c:  10 bf fc c0  b  0xa013de0c
a013eb10:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013eb14:  90 15 63 e8  or  %l5, 0x3e8, %o0
a013eb18:  7f fe 81 96  call  0xa00df170
a013eb1c:  d2 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o1
a013eb20:  10 bf fd 4e  b  0xa013e058
a013eb24:  d8 06 80 00  ld  [ %i2 ], %o4
a013eb28:  90 12 e0 08  or  %o3, 8, %o0
a013eb2c:  7f fe 81 91  call  0xa00df170
a013eb30:  d2 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o1
a013eb34:  10 bf fd b5  b  0xa013e208
a013eb38:  e4 06 80 00  ld  [ %i2 ], %l2
a013eb3c:  d2 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o1
a013eb40:  7f fe 81 8c  call  0xa00df170
a013eb44:  90 12 20 f0  or  %o0, 0xf0, %o0
a013eb48:  10 bf ff 81  b  0xa013e94c
a013eb4c:  da 06 80 00  ld  [ %i2 ], %o5
a013eb50:  9b 32 60 18  srl  %o1, 0x18, %o5
a013eb54:  bb 32 60 1b  srl  %o1, 0x1b, %i5
a013eb58:  29 00 06 96  sethi  %hi(0x1a5800), %l4
a013eb5c:  90 15 21 28  or  %l4, 0x128, %o0	! 0x1a5928
a013eb60:  94 0f 60 01  and  %i5, 1, %o2
a013eb64:  96 0b 60 01  and  %o5, 1, %o3
a013eb68:  7f fe 81 82  call  0xa00df170
a013eb6c:  d2 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o1
a013eb70:  10 bf fd 5e  b  0xa013e0e8
a013eb74:  ee 06 80 00  ld  [ %i2 ], %l7
a013eb78:  7f ff 89 97  call  0xa01211d4
a013eb7c:  90 10 00 0b  mov  %o3, %o0
a013eb80:  80 8a 20 ff  btst  0xff, %o0
a013eb84:  32 bf fc a2  bne,a   0xa013de0c
a013eb88:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013eb8c:  d0 06 a0 70  ld  [ %i2 + 0x70 ], %o0
a013eb90:  1b 00 10 00  sethi  %hi(0x400000), %o5
a013eb94:  9e 2a 00 0d  andn  %o0, %o5, %o7
a013eb98:  de 26 a0 70  st  %o7, [ %i2 + 0x70 ]
a013eb9c:  10 bf ff 31  b  0xa013e860
a013eba0:  d0 06 80 00  ld  [ %i2 ], %o0
a013eba4:  80 a0 60 00  cmp  %g1, 0
a013eba8:  12 bf fc 99  bne  0xa013de0c
a013ebac:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013ebb0:  2f 0c 00 00  sethi  %hi(0x30000000), %l7
a013ebb4:  80 8b c0 17  btst  %o7, %l7
a013ebb8:  12 80 00 97  bne  0xa013ee14
a013ebbc:  93 33 20 14  srl  %o4, 0x14, %o1
a013ebc0:  80 8b e8 00  btst  0x800, %o7
a013ebc4:  12 80 00 81  bne  0xa013edc8
a013ebc8:  d0 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o0
a013ebcc:  3b 2a 00 b8  sethi  %hi(0xa802e000), %i5
a013ebd0:  90 17 63 78  or  %i5, 0x378, %o0	! 0xa802e378
a013ebd4:  e0 12 20 48  lduh  [ %o0 + 0x48 ], %l0
a013ebd8:  80 a4 22 8a  cmp  %l0, 0x28a
a013ebdc:  d0 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o0
a013ebe0:  aa 10 20 01  mov  1, %l5
a013ebe4:  1a 80 00 03  bcc  0xa013ebf0
a013ebe8:  ac 10 00 10  mov  %l0, %l6
a013ebec:  ac 10 22 8a  mov  0x28a, %l6
a013ebf0:  82 16 e3 30  or  %i3, 0x330, %g1
a013ebf4:  a8 0a 20 ff  and  %o0, 0xff, %l4
a013ebf8:  e4 18 60 68  ldd  [ %g1 + 0x68 ], %l2
a013ebfc:  e0 18 60 60  ldd  [ %g1 + 0x60 ], %l0
a013ec00:  d4 18 60 50  ldd  [ %g1 + 0x50 ], %o2
a013ec04:  d0 18 60 58  ldd  [ %g1 + 0x58 ], %o0
a013ec08:  d8 18 60 48  ldd  [ %g1 + 0x48 ], %o4
a013ec0c:  d0 3f bf 70  std  %o0, [ %fp + -144 ]
a013ec10:  d4 3f bf 68  std  %o2, [ %fp + -152 ]
a013ec14:  e0 3f bf 78  std  %l0, [ %fp + -136 ]
a013ec18:  e4 3f bf 80  std  %l2, [ %fp + -128 ]
a013ec1c:  d8 3f bf 60  std  %o4, [ %fp + -160 ]
a013ec20:  7f ff 1c 21  call  0xa0105ca4
a013ec24:  90 10 00 14  mov  %l4, %o0
a013ec28:  21 2a 00 b5  sethi  %hi(0xa802d400), %l0
a013ec2c:  d4 04 22 a4  ld  [ %l0 + 0x2a4 ], %o2	! 0xa802d6a4
a013ec30:  a2 10 00 08  mov  %o0, %l1
a013ec34:  7f ff 78 d5  call  0xa011cf88
a013ec38:  e6 12 a0 0a  lduh  [ %o2 + 0xa ], %l3
a013ec3c:  a4 0a 20 ff  and  %o0, 0xff, %l2
a013ec40:  80 a4 a0 82  cmp  %l2, 0x82
a013ec44:  38 80 00 09  bgu,a   0xa013ec68
a013ec48:  ac 10 20 00  clr  %l6
a013ec4c:  d6 04 22 a4  ld  [ %l0 + 0x2a4 ], %o3
a013ec50:  9b 2d a0 10  sll  %l6, 0x10, %o5
a013ec54:  9f 33 60 10  srl  %o5, 0x10, %o7
a013ec58:  d8 12 e0 50  lduh  [ %o3 + 0x50 ], %o4
a013ec5c:  80 a3 c0 0c  cmp  %o7, %o4
a013ec60:  38 80 00 02  bgu,a   0xa013ec68
a013ec64:  ac 10 00 0c  mov  %o4, %l6
a013ec68:  af 2d 20 04  sll  %l4, 4, %l7
a013ec6c:  a0 25 c0 14  sub  %l7, %l4, %l0
a013ec70:  95 2c 20 03  sll  %l0, 3, %o2
a013ec74:  ba 17 63 78  or  %i5, 0x378, %i5
a013ec78:  a0 16 e3 30  or  %i3, 0x330, %l0
a013ec7c:  a4 02 80 10  add  %o2, %l0, %l2
a013ec80:  d0 17 60 52  lduh  [ %i5 + 0x52 ], %o0
a013ec84:  d4 14 a0 08  lduh  [ %l2 + 8 ], %o2
a013ec88:  92 02 20 14  add  %o0, 0x14, %o1
a013ec8c:  80 a2 80 09  cmp  %o2, %o1
a013ec90:  34 80 00 02  bg,a   0xa013ec98
a013ec94:  aa 10 20 00  clr  %l5
a013ec98:  03 00 06 96  sethi  %hi(0x1a5800), %g1
a013ec9c:  90 10 61 50  or  %g1, 0x150, %o0	! 0x1a5950
a013eca0:  7f fe 81 34  call  0xa00df170
a013eca4:  92 10 00 14  mov  %l4, %o1
a013eca8:  80 a5 20 00  cmp  %l4, 0
a013ecac:  12 80 01 05  bne  0xa013f0c0
a013ecb0:  80 a5 20 03  cmp  %l4, 3
a013ecb4:  19 2a 00 b7  sethi  %hi(0xa802dc00), %o4
a013ecb8:  e8 03 23 30  ld  [ %o4 + 0x330 ], %l4	! 0xa802df30
a013ecbc:  80 8d 20 01  btst  1, %l4
a013ecc0:  32 80 00 41  bne,a   0xa013edc4
a013ecc4:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013ecc8:  29 2a 00 b8  sethi  %hi(0xa802e000), %l4
a013eccc:  d6 05 23 d0  ld  [ %l4 + 0x3d0 ], %o3	! 0xa802e3d0
a013ecd0:  1f 02 00 00  sethi  %hi(0x8000000), %o7
a013ecd4:  80 8a c0 0f  btst  %o3, %o7
a013ecd8:  02 80 00 ea  be  0xa013f080
a013ecdc:  a4 15 23 d0  or  %l4, 0x3d0, %l2
a013ece0:  1b 00 06 96  sethi  %hi(0x1a5800), %o5
a013ece4:  7f fe 81 23  call  0xa00df170
a013ece8:  90 13 61 88  or  %o5, 0x188, %o0	! 0x1a5988
a013ecec:  af 2d a0 10  sll  %l6, 0x10, %l7
a013ecf0:  ec 14 20 08  lduh  [ %l0 + 8 ], %l6
a013ecf4:  93 35 e0 10  srl  %l7, 0x10, %o1
a013ecf8:  80 a5 80 09  cmp  %l6, %o1
a013ecfc:  28 80 00 de  bleu,a   0xa013f074
a013ed00:  fa 0c a0 03  ldub  [ %l2 + 3 ], %i5
a013ed04:  d2 0c a0 03  ldub  [ %l2 + 3 ], %o1
a013ed08:  80 a0 00 09  cmp  %g0, %o1
a013ed0c:  90 40 20 00  addx  %g0, 0, %o0
a013ed10:  d2 17 60 52  lduh  [ %i5 + 0x52 ], %o1
a013ed14:  7f ff 24 4c  call  0xa0107e44
a013ed18:  94 10 20 01  mov  1, %o2
a013ed1c:  ac 15 23 d0  or  %l4, 0x3d0, %l6
a013ed20:  d2 05 a0 38  ld  [ %l6 + 0x38 ], %o1
a013ed24:  9a 1a 60 03  xor  %o1, 3, %o5
a013ed28:  80 a0 00 0d  cmp  %g0, %o5
a013ed2c:  ae 16 e3 30  or  %i3, 0x330, %l7
a013ed30:  92 60 3f ff  subx  %g0, -1, %o1
a013ed34:  d6 15 e0 08  lduh  [ %l7 + 8 ], %o3
a013ed38:  90 10 20 01  mov  1, %o0
a013ed3c:  7f ff 2b a0  call  0xa0109bbc
a013ed40:  d4 17 bf 6c  lduh  [ %fp + -148 ], %o2
a013ed44:  d8 05 a0 04  ld  [ %l6 + 4 ], %o4
a013ed48:  17 3c 00 00  sethi  %hi(0xf0000000), %o3
a013ed4c:  a0 0b 00 0b  and  %o4, %o3, %l0
a013ed50:  1f 0c 00 00  sethi  %hi(0x30000000), %o7
a013ed54:  a8 1c 00 0f  xor  %l0, %o7, %l4
a013ed58:  80 a0 00 14  cmp  %g0, %l4
a013ed5c:  03 08 00 00  sethi  %hi(0x20000000), %g1
a013ed60:  a4 60 3f ff  subx  %g0, -1, %l2
a013ed64:  94 1c 00 01  xor  %l0, %g1, %o2
a013ed68:  80 a0 00 0a  cmp  %g0, %o2
a013ed6c:  90 60 3f ff  subx  %g0, -1, %o0
a013ed70:  80 94 80 08  orcc  %l2, %o0, %g0
a013ed74:  02 80 00 f9  be  0xa013f158
a013ed78:  c2 06 e3 30  ld  [ %i3 + 0x330 ], %g1
a013ed7c:  9f 30 60 0c  srl  %g1, 0xc, %o7
a013ed80:  82 0b e0 0f  and  %o7, 0xf, %g1
a013ed84:  80 a0 60 01  cmp  %g1, 1
a013ed88:  02 80 00 f2  be  0xa013f150
a013ed8c:  90 10 20 00  clr  %o0
a013ed90:  80 a0 60 01  cmp  %g1, 1
a013ed94:  04 80 00 06  ble  0xa013edac
a013ed98:  80 a0 60 02  cmp  %g1, 2
a013ed9c:  02 80 00 aa  be  0xa013f044
a013eda0:  80 a0 60 03  cmp  %g1, 3
a013eda4:  22 80 00 02  be,a   0xa013edac
a013eda8:  90 10 20 03  mov  3, %o0
a013edac:  90 0a 20 03  and  %o0, 3, %o0
a013edb0:  94 0d 60 01  and  %l5, 1, %o2
a013edb4:  92 10 20 02  mov  2, %o1
a013edb8:  7f ff 26 10  call  0xa01085f8
a013edbc:  01 00 00 00  nop
a013edc0:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013edc4:  d0 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o0
a013edc8:  a4 0b f7 ff  and  %o7, -2049, %l2
a013edcc:  80 a2 20 00  cmp  %o0, 0
a013edd0:  12 80 00 07  bne  0xa013edec
a013edd4:  e4 26 a0 70  st  %l2, [ %i2 + 0x70 ]
a013edd8:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a013eddc:  d4 0c 23 d3  ldub  [ %l0 + 0x3d3 ], %o2	! 0xa802e3d3
a013ede0:  80 a2 a0 00  cmp  %o2, 0
a013ede4:  02 80 00 9a  be  0xa013f04c
a013ede8:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a013edec:  de 06 80 00  ld  [ %i2 ], %o7
a013edf0:  a9 33 e0 0c  srl  %o7, 0xc, %l4
a013edf4:  7f ff 1f 45  call  0xa0106b08
a013edf8:  90 0d 20 0f  and  %l4, 0xf, %o0
a013edfc:  67 fd 39 e3  call  0x4008d588
a013ee00:  01 00 00 00  nop
a013ee04:  d0 36 a0 04  sth  %o0, [ %i2 + 4 ]
a013ee08:  d8 06 80 00  ld  [ %i2 ], %o4
a013ee0c:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013ee10:  93 33 20 14  srl  %o4, 0x14, %o1
a013ee14:  9a 0a 60 0f  and  %o1, 0xf, %o5
a013ee18:  ae 03 60 01  add  %o5, 1, %l7
a013ee1c:  2b 00 3c 00  sethi  %hi(0xf00000), %l5
a013ee20:  96 2b 00 15  andn  %o4, %l5, %o3
a013ee24:  ac 0d e0 0f  and  %l7, 0xf, %l6
a013ee28:  99 2d a0 14  sll  %l6, 0x14, %o4
a013ee2c:  9a 12 c0 0c  or  %o3, %o4, %o5
a013ee30:  10 bf fe d9  b  0xa013e994
a013ee34:  da 26 80 00  st  %o5, [ %i2 ]
a013ee38:  ab 32 60 0c  srl  %o1, 0xc, %l5
a013ee3c:  a8 0d 60 0f  and  %l5, 0xf, %l4
a013ee40:  9a 5d 20 2a  smul  %l4, 0x2a, %o5
a013ee44:  90 03 40 10  add  %o5, %l0, %o0
a013ee48:  e0 12 20 1c  lduh  [ %o0 + 0x1c ], %l0
a013ee4c:  a5 2c 20 10  sll  %l0, 0x10, %l2
a013ee50:  e6 16 a0 06  lduh  [ %i2 + 6 ], %l3
a013ee54:  94 5c e3 e8  smul  %l3, 0x3e8, %o2
a013ee58:  97 34 a0 11  srl  %l2, 0x11, %o3
a013ee5c:  82 02 80 0b  add  %o2, %o3, %g1
a013ee60:  9f 34 a0 10  srl  %l2, 0x10, %o7
a013ee64:  d8 12 20 1a  lduh  [ %o0 + 0x1a ], %o4
a013ee68:  81 80 00 00  mov  %g0, %y
a013ee6c:  01 00 00 00  nop
a013ee70:  01 00 00 00  nop
a013ee74:  01 00 00 00  nop
a013ee78:  a2 70 40 0f  udiv  %g1, %o7, %l1
a013ee7c:  d8 36 a0 0e  sth  %o4, [ %i2 + 0xe ]
a013ee80:  e2 36 a0 08  sth  %l1, [ %i2 + 8 ]
a013ee84:  10 bf fb ca  b  0xa013ddac
a013ee88:  e0 36 a0 10  sth  %l0, [ %i2 + 0x10 ]
a013ee8c:  90 13 e3 c8  or  %o7, 0x3c8, %o0
a013ee90:  7f fe 80 b8  call  0xa00df170
a013ee94:  d2 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o1
a013ee98:  10 bf fb ac  b  0xa013dd48
a013ee9c:  fa 06 80 00  ld  [ %i2 ], %i5
a013eea0:  03 04 00 00  sethi  %hi(0x10000000), %g1
a013eea4:  10 bf fe 38  b  0xa013e784
a013eea8:  9e 2b 40 01  andn  %o5, %g1, %o7
a013eeac:  19 08 00 00  sethi  %hi(0x20000000), %o4
a013eeb0:  10 bf fe 90  b  0xa013e8f0
a013eeb4:  82 2a 40 0c  andn  %o1, %o4, %g1
a013eeb8:  e2 06 80 00  ld  [ %i2 ], %l1
a013eebc:  a5 34 60 0c  srl  %l1, 0xc, %l2
a013eec0:  7f fe c0 62  call  0xa00ef048
a013eec4:  90 0c a0 0f  and  %l2, 0xf, %o0
a013eec8:  d0 06 80 00  ld  [ %i2 ], %o0
a013eecc:  a1 32 20 0c  srl  %o0, 0xc, %l0
a013eed0:  7f fe c8 a0  call  0xa00f1150
a013eed4:  90 0c 20 0f  and  %l0, 0xf, %o0
a013eed8:  10 bf fd fd  b  0xa013e6cc
a013eedc:  e2 06 80 00  ld  [ %i2 ], %l1
a013eee0:  97 32 60 04  srl  %o1, 4, %o3
a013eee4:  a9 32 60 0c  srl  %o1, 0xc, %l4
a013eee8:  bb 32 60 08  srl  %o1, 8, %i5
a013eeec:  90 0d 20 0f  and  %l4, 0xf, %o0
a013eef0:  92 0f 60 0f  and  %i5, 0xf, %o1
a013eef4:  96 0a e0 0f  and  %o3, 0xf, %o3
a013eef8:  7f ff 16 cf  call  0xa0104a34
a013eefc:  d4 16 a0 06  lduh  [ %i2 + 6 ], %o2
a013ef00:  7f ff 78 22  call  0xa011cf88
a013ef04:  01 00 00 00  nop
a013ef08:  9a 0a 20 ff  and  %o0, 0xff, %o5
a013ef0c:  80 a3 60 82  cmp  %o5, 0x82
a013ef10:  28 80 00 12  bleu,a   0xa013ef58
a013ef14:  c2 06 80 00  ld  [ %i2 ], %g1
a013ef18:  e6 06 80 00  ld  [ %i2 ], %l3
a013ef1c:  a3 34 e0 0c  srl  %l3, 0xc, %l1
a013ef20:  a4 0c 60 0f  and  %l1, 0xf, %l2
a013ef24:  98 5c a0 2a  smul  %l2, 0x2a, %o4
a013ef28:  90 16 22 24  or  %i0, 0x224, %o0
a013ef2c:  a0 03 00 08  add  %o4, %o0, %l0
a013ef30:  40 00 0c 8e  call  0xa0142168
a013ef34:  d0 0c 20 0a  ldub  [ %l0 + 0xa ], %o0
a013ef38:  ee 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %l7
a013ef3c:  ac 10 20 01  mov  1, %l6
a013ef40:  ab 2d 80 17  sll  %l6, %l7, %l5
a013ef44:  90 0a 20 ff  and  %o0, 0xff, %o0
a013ef48:  94 0d 60 ff  and  %l5, 0xff, %o2
a013ef4c:  7f ff e3 04  call  0xa0137b5c
a013ef50:  92 10 20 01  mov  1, %o1
a013ef54:  c2 06 80 00  ld  [ %i2 ], %g1
a013ef58:  95 30 60 0c  srl  %g1, 0xc, %o2
a013ef5c:  7f fe fa 31  call  0xa00fd820
a013ef60:  90 0a a0 0f  and  %o2, 0xf, %o0
a013ef64:  9e 0a 20 ff  and  %o0, 0xff, %o7
a013ef68:  80 a3 e0 71  cmp  %o7, 0x71
a013ef6c:  02 80 00 27  be  0xa013f008
a013ef70:  01 00 00 00  nop
a013ef74:  fa 06 80 00  ld  [ %i2 ], %i5
a013ef78:  97 37 60 0c  srl  %i5, 0xc, %o3
a013ef7c:  7f fe fa 29  call  0xa00fd820
a013ef80:  90 0a e0 0f  and  %o3, 0xf, %o0
a013ef84:  9a 0a 20 ff  and  %o0, 0xff, %o5
a013ef88:  80 a3 60 81  cmp  %o5, 0x81
a013ef8c:  02 80 00 1f  be  0xa013f008
a013ef90:  01 00 00 00  nop
a013ef94:  d0 06 80 00  ld  [ %i2 ], %o0
a013ef98:  a8 0a 20 f0  and  %o0, 0xf0, %l4
a013ef9c:  80 a5 20 40  cmp  %l4, 0x40
a013efa0:  22 80 00 0d  be,a   0xa013efd4
a013efa4:  1f 00 3c 00  sethi  %hi(0xf00000), %o7
a013efa8:  ad 32 20 04  srl  %o0, 4, %l6
a013efac:  7f fe de 3b  call  0xa00f6898
a013efb0:  90 0d a0 0f  and  %l6, 0xf, %o0
a013efb4:  ea 06 80 00  ld  [ %i2 ], %l5
a013efb8:  93 35 60 04  srl  %l5, 4, %o1
a013efbc:  7f fe dd 00  call  0xa00f63bc
a013efc0:  90 0a 60 0f  and  %o1, 0xf, %o0
a013efc4:  7f fe de dc  call  0xa00f6b34
a013efc8:  90 10 20 ff  mov  0xff, %o0
a013efcc:  d0 06 80 00  ld  [ %i2 ], %o0
a013efd0:  1f 00 3c 00  sethi  %hi(0xf00000), %o7
a013efd4:  a6 2a 00 0f  andn  %o0, %o7, %l3
a013efd8:  23 3c 00 00  sethi  %hi(0xf0000000), %l1
a013efdc:  19 24 00 00  sethi  %hi(0x90000000), %o4
a013efe0:  a4 2c c0 11  andn  %l3, %l1, %l2
a013efe4:  90 14 80 0c  or  %l2, %o4, %o0
a013efe8:  67 fd 39 68  call  0x4008d588
a013efec:  d0 26 80 00  st  %o0, [ %i2 ]
a013eff0:  e0 06 a0 70  ld  [ %i2 + 0x70 ], %l0
a013eff4:  2f 00 10 00  sethi  %hi(0x400000), %l7
a013eff8:  82 2c 00 17  andn  %l0, %l7, %g1
a013effc:  d0 36 a0 04  sth  %o0, [ %i2 + 4 ]
a013f000:  10 bf fd 4d  b  0xa013e534
a013f004:  9e 08 77 ff  and  %g1, -2049, %o7
a013f008:  7f ff b0 ff  call  0xa012b404
a013f00c:  90 0f 20 ff  and  %i4, 0xff, %o0
a013f010:  10 bf ff e2  b  0xa013ef98
a013f014:  d0 06 80 00  ld  [ %i2 ], %o0
a013f018:  9f c0 40 00  call  %g1
a013f01c:  92 07 bf e8  add  %fp, -24, %o1
a013f020:  d8 1f bf e8  ldd  [ %fp + -24 ], %o4
a013f024:  d4 1f bf f0  ldd  [ %fp + -16 ], %o2
a013f028:  d8 3f bf c8  std  %o4, [ %fp + -56 ]
a013f02c:  d4 3f bf d0  std  %o2, [ %fp + -48 ]
a013f030:  d0 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o0
a013f034:  7f ff f8 60  call  0xa013d1b4
a013f038:  92 07 bf c8  add  %fp, -56, %o1
a013f03c:  10 bf fd e6  b  0xa013e7d4
a013f040:  de 06 a0 70  ld  [ %i2 + 0x70 ], %o7
a013f044:  10 bf ff 5a  b  0xa013edac
a013f048:  90 10 20 02  mov  2, %o0
a013f04c:  d0 10 63 ca  lduh  [ %g1 + 0x3ca ], %o0
a013f050:  7f ff 1c a4  call  0xa01062e0
a013f054:  92 10 20 00  clr  %o1
a013f058:  10 bf ff 66  b  0xa013edf0
a013f05c:  de 06 80 00  ld  [ %i2 ], %o7
a013f060:  90 13 e0 88  or  %o7, 0x88, %o0
a013f064:  7f fe 80 43  call  0xa00df170
a013f068:  d2 0e 63 d2  ldub  [ %i1 + 0x3d2 ], %o1
a013f06c:  10 bf fd 78  b  0xa013e64c
a013f070:  92 06 a0 06  add  %i2, 6, %o1
a013f074:  80 a0 00 1d  cmp  %g0, %i5
a013f078:  10 bf ff 27  b  0xa013ed14
a013f07c:  90 40 20 00  addx  %g0, 0, %o0
a013f080:  29 00 06 96  sethi  %hi(0x1a5800), %l4
a013f084:  7f fe 80 3b  call  0xa00df170
a013f088:  90 15 21 a8  or  %l4, 0x1a8, %o0	! 0x1a59a8
a013f08c:  c2 0c a0 03  ldub  [ %l2 + 3 ], %g1
a013f090:  80 a0 00 01  cmp  %g0, %g1
a013f094:  90 40 20 00  addx  %g0, 0, %o0
a013f098:  d2 17 60 52  lduh  [ %i5 + 0x52 ], %o1
a013f09c:  7f ff 23 6a  call  0xa0107e44
a013f0a0:  94 10 20 01  mov  1, %o2
a013f0a4:  90 10 20 00  clr  %o0
a013f0a8:  92 10 20 00  clr  %o1
a013f0ac:  94 10 20 00  clr  %o2
a013f0b0:  7f ff 2a c3  call  0xa0109bbc
a013f0b4:  d6 14 20 08  lduh  [ %l0 + 8 ], %o3
a013f0b8:  10 bf ff 31  b  0xa013ed7c
a013f0bc:  c2 04 00 17  ld  [ %l0 + %l7 ], %g1
a013f0c0:  02 80 00 0a  be  0xa013f0e8
a013f0c4:  2d 2a 00 b8  sethi  %hi(0xa802e000), %l6
a013f0c8:  bb 2d 20 04  sll  %l4, 4, %i5
a013f0cc:  a2 27 40 14  sub  %i5, %l4, %l1
a013f0d0:  93 2c 60 03  sll  %l1, 3, %o1
a013f0d4:  a6 16 e3 30  or  %i3, 0x330, %l3
a013f0d8:  da 04 c0 09  ld  [ %l3 + %o1 ], %o5
a013f0dc:  af 33 60 0c  srl  %o5, 0xc, %l7
a013f0e0:  10 bf ff 29  b  0xa013ed84
a013f0e4:  82 0d e0 0f  and  %l7, 0xf, %g1
a013f0e8:  d8 05 a3 d0  ld  [ %l6 + 0x3d0 ], %o4
a013f0ec:  17 00 08 00  sethi  %hi(0x200000), %o3
a013f0f0:  80 8b 00 0b  btst  %o4, %o3
a013f0f4:  02 bf ff f6  be  0xa013f0cc
a013f0f8:  bb 2d 20 04  sll  %l4, 4, %i5
a013f0fc:  c2 04 21 68  ld  [ %l0 + 0x168 ], %g1
a013f100:  ab 30 60 0c  srl  %g1, 0xc, %l5
a013f104:  82 0d 60 0f  and  %l5, 0xf, %g1
a013f108:  80 a0 60 01  cmp  %g1, 1
a013f10c:  02 80 00 0f  be  0xa013f148
a013f110:  90 10 20 00  clr  %o0
a013f114:  80 a0 60 01  cmp  %g1, 1
a013f118:  04 80 00 06  ble  0xa013f130
a013f11c:  80 a0 60 02  cmp  %g1, 2
a013f120:  02 80 00 08  be  0xa013f140
a013f124:  80 a0 60 03  cmp  %g1, 3
a013f128:  22 80 00 02  be,a   0xa013f130
a013f12c:  90 10 20 03  mov  3, %o0
a013f130:  90 0a 20 03  and  %o0, 3, %o0
a013f134:  92 10 20 00  clr  %o1
a013f138:  10 bf ff 20  b  0xa013edb8
a013f13c:  94 10 20 00  clr  %o2
a013f140:  10 bf ff fc  b  0xa013f130
a013f144:  90 10 20 02  mov  2, %o0
a013f148:  10 bf ff fa  b  0xa013f130
a013f14c:  90 10 20 01  mov  1, %o0
a013f150:  10 bf ff 17  b  0xa013edac
a013f154:  90 10 20 01  mov  1, %o0
a013f158:  a5 2c 60 10  sll  %l1, 0x10, %l2
a013f15c:  a3 34 a0 10  srl  %l2, 0x10, %l1
a013f160:  bb 2c e0 10  sll  %l3, 0x10, %i5
a013f164:  11 00 06 96  sethi  %hi(0x1a5800), %o0
a013f168:  90 12 21 d0  or  %o0, 0x1d0, %o0	! 0x1a59d0
a013f16c:  92 10 00 11  mov  %l1, %o1
a013f170:  7f fe 80 00  call  0xa00df170
a013f174:  95 37 60 10  srl  %i5, 0x10, %o2
a013f178:  a7 37 60 11  srl  %i5, 0x11, %l3
a013f17c:  80 a4 40 13  cmp  %l1, %l3
a013f180:  1a bf ff e0  bcc  0xa013f100
a013f184:  c2 06 e3 30  ld  [ %i3 + 0x330 ], %g1
a013f188:  e0 06 e3 30  ld  [ %i3 + 0x330 ], %l0
a013f18c:  95 34 20 0c  srl  %l0, 0xc, %o2
a013f190:  82 0a a0 0f  and  %o2, 0xf, %g1
a013f194:  80 a0 60 01  cmp  %g1, 1
a013f198:  02 80 00 0f  be  0xa013f1d4
a013f19c:  90 10 20 00  clr  %o0
a013f1a0:  80 a0 60 01  cmp  %g1, 1
a013f1a4:  04 80 00 06  ble  0xa013f1bc
a013f1a8:  80 a0 60 02  cmp  %g1, 2
a013f1ac:  02 80 00 08  be  0xa013f1cc
a013f1b0:  80 a0 60 03  cmp  %g1, 3
a013f1b4:  22 80 00 02  be,a   0xa013f1bc
a013f1b8:  90 10 20 03  mov  3, %o0
a013f1bc:  90 0a 20 03  and  %o0, 3, %o0
a013f1c0:  94 0d 60 01  and  %l5, 1, %o2
a013f1c4:  10 bf fe fd  b  0xa013edb8
a013f1c8:  92 10 20 01  mov  1, %o1
a013f1cc:  10 bf ff fc  b  0xa013f1bc
a013f1d0:  90 10 20 02  mov  2, %o0
a013f1d4:  10 bf ff fa  b  0xa013f1bc
a013f1d8:  90 10 20 01  mov  1, %o0
a013f1dc:  81 c7 e0 08  ret
a013f1e0:  81 e8 00 00  restore
