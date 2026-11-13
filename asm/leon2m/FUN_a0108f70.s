# leon2m FUN_a0108f70 0xa0108f70-0xa0109110 (416 bytes)
a0108f70:  9d e3 bf 98  save  %sp, -104, %sp
a0108f74:  03 33 c0 46  sethi  %hi(0xcf011800), %g1
a0108f78:  b0 10 62 ac  or  %g1, 0x2ac, %i0	! 0xcf011aac
a0108f7c:  b6 10 20 00  clr  %i3
a0108f80:  b8 10 20 00  clr  %i4
a0108f84:  9e 10 62 a0  or  %g1, 0x2a0, %o7
a0108f88:  b4 10 62 a4  or  %g1, 0x2a4, %i2
a0108f8c:  10 80 00 0d  b  0xa0108fc0
a0108f90:  b2 10 62 a8  or  %g1, 0x2a8, %i1
a0108f94:  04 80 00 3a  ble  0xa010907c
a0108f98:  80 a7 20 02  cmp  %i4, 2
a0108f9c:  02 80 00 30  be  0xa010905c
a0108fa0:  80 a7 20 03  cmp  %i4, 3
a0108fa4:  02 80 00 40  be  0xa01090a4
a0108fa8:  01 00 00 00  nop
a0108fac:  b6 06 e0 01  inc  %i3
a0108fb0:  b8 0e e0 ff  and  %i3, 0xff, %i4
a0108fb4:  80 a7 20 03  cmp  %i4, 3
a0108fb8:  18 80 00 11  bgu  0xa0108ffc
a0108fbc:  3b 33 c0 46  sethi  %hi(0xcf011800), %i5
a0108fc0:  80 a7 20 01  cmp  %i4, 1
a0108fc4:  12 bf ff f4  bne  0xa0108f94
a0108fc8:  01 00 00 00  nop
a0108fcc:  fa 06 80 00  ld  [ %i2 ], %i5
a0108fd0:  82 0f 7f cf  and  %i5, -49, %g1
a0108fd4:  c2 26 80 00  st  %g1, [ %i2 ]
a0108fd8:  f8 06 80 00  ld  [ %i2 ], %i4
a0108fdc:  ba 17 20 10  or  %i4, 0x10, %i5
a0108fe0:  b6 06 e0 01  inc  %i3
a0108fe4:  b8 0e e0 ff  and  %i3, 0xff, %i4
a0108fe8:  fa 26 80 00  st  %i5, [ %i2 ]
a0108fec:  80 a7 20 03  cmp  %i4, 3
a0108ff0:  08 bf ff f5  bleu  0xa0108fc4
a0108ff4:  80 a7 20 01  cmp  %i4, 1
a0108ff8:  3b 33 c0 46  sethi  %hi(0xcf011800), %i5
a0108ffc:  b0 17 62 ac  or  %i5, 0x2ac, %i0	! 0xcf011aac
a0109000:  b6 10 20 01  mov  1, %i3
a0109004:  b8 10 20 01  mov  1, %i4
a0109008:  b2 17 62 a4  or  %i5, 0x2a4, %i1
a010900c:  10 80 00 05  b  0xa0109020
a0109010:  b4 17 62 a8  or  %i5, 0x2a8, %i2
a0109014:  32 80 00 39  bne,a   0xa01090f8
a0109018:  b6 06 e0 01  inc  %i3
a010901c:  30 80 00 31  b,a   0xa01090e0
a0109020:  80 a7 20 02  cmp  %i4, 2
a0109024:  02 80 00 28  be  0xa01090c4
a0109028:  01 00 00 00  nop
a010902c:  04 bf ff fa  ble  0xa0109014
a0109030:  80 a7 20 01  cmp  %i4, 1
a0109034:  80 a7 20 03  cmp  %i4, 3
a0109038:  32 80 00 30  bne,a   0xa01090f8
a010903c:  b6 06 e0 01  inc  %i3
a0109040:  fa 06 00 00  ld  [ %i0 ], %i5
a0109044:  82 0f 7f f8  and  %i5, -8, %g1
a0109048:  c2 26 00 00  st  %g1, [ %i0 ]
a010904c:  f8 06 00 00  ld  [ %i0 ], %i4
a0109050:  f8 26 00 00  st  %i4, [ %i0 ]
a0109054:  10 80 00 29  b  0xa01090f8
a0109058:  b6 06 e0 01  inc  %i3
a010905c:  f8 06 40 00  ld  [ %i1 ], %i4
a0109060:  ba 0f 3f cf  and  %i4, -49, %i5
a0109064:  fa 26 40 00  st  %i5, [ %i1 ]
a0109068:  c2 06 40 00  ld  [ %i1 ], %g1
a010906c:  b8 10 60 20  or  %g1, 0x20, %i4
a0109070:  f8 26 40 00  st  %i4, [ %i1 ]
a0109074:  10 bf ff cf  b  0xa0108fb0
a0109078:  b6 06 e0 01  inc  %i3
a010907c:  80 a7 20 00  cmp  %i4, 0
a0109080:  32 bf ff cc  bne,a   0xa0108fb0
a0109084:  b6 06 e0 01  inc  %i3
a0109088:  c2 03 c0 00  ld  [ %o7 ], %g1
a010908c:  b8 08 7f cf  and  %g1, -49, %i4
a0109090:  f8 23 c0 00  st  %i4, [ %o7 ]
a0109094:  fa 03 c0 00  ld  [ %o7 ], %i5
a0109098:  fa 23 c0 00  st  %i5, [ %o7 ]
a010909c:  10 bf ff c5  b  0xa0108fb0
a01090a0:  b6 06 e0 01  inc  %i3
a01090a4:  c2 06 00 00  ld  [ %i0 ], %g1
a01090a8:  b8 08 7f cf  and  %g1, -49, %i4
a01090ac:  f8 26 00 00  st  %i4, [ %i0 ]
a01090b0:  fa 06 00 00  ld  [ %i0 ], %i5
a01090b4:  82 17 60 30  or  %i5, 0x30, %g1
a01090b8:  c2 26 00 00  st  %g1, [ %i0 ]
a01090bc:  10 bf ff bd  b  0xa0108fb0
a01090c0:  b6 06 e0 01  inc  %i3
a01090c4:  fa 06 80 00  ld  [ %i2 ], %i5
a01090c8:  82 0f 7f f8  and  %i5, -8, %g1
a01090cc:  c2 26 80 00  st  %g1, [ %i2 ]
a01090d0:  f8 06 80 00  ld  [ %i2 ], %i4
a01090d4:  f8 26 80 00  st  %i4, [ %i2 ]
a01090d8:  10 80 00 08  b  0xa01090f8
a01090dc:  b6 06 e0 01  inc  %i3
a01090e0:  fa 06 40 00  ld  [ %i1 ], %i5
a01090e4:  82 0f 7f f8  and  %i5, -8, %g1
a01090e8:  c2 26 40 00  st  %g1, [ %i1 ]
a01090ec:  f8 06 40 00  ld  [ %i1 ], %i4
a01090f0:  f8 26 40 00  st  %i4, [ %i1 ]
a01090f4:  b6 06 e0 01  inc  %i3
a01090f8:  b8 0e e0 ff  and  %i3, 0xff, %i4
a01090fc:  80 a7 20 03  cmp  %i4, 3
a0109100:  08 bf ff c9  bleu  0xa0109024
a0109104:  80 a7 20 02  cmp  %i4, 2
a0109108:  81 c7 e0 08  ret
a010910c:  81 e8 00 00  restore
