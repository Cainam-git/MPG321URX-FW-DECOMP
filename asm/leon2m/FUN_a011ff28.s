# leon2m FUN_a011ff28 0xa011ff28-0xa01200f8 (464 bytes)
a011ff28:  9d e3 bf 98  save  %sp, -104, %sp
a011ff2c:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011ff30:  ba 16 e0 28  or  %i3, 0x28, %i5	! 0xcf011428
a011ff34:  f4 07 40 00  ld  [ %i5 ], %i2
a011ff38:  82 16 a0 03  or  %i2, 3, %g1
a011ff3c:  9a 10 00 18  mov  %i0, %o5
a011ff40:  c2 27 40 00  st  %g1, [ %i5 ]
a011ff44:  80 a6 20 02  cmp  %i0, 2
a011ff48:  02 80 00 51  be  0xa012008c
a011ff4c:  9e 10 00 19  mov  %i1, %o7
a011ff50:  80 a6 20 01  cmp  %i0, 1
a011ff54:  08 80 00 1e  bleu  0xa011ffcc
a011ff58:  35 00 06 8b  sethi  %hi(0x1a2c00), %i2
a011ff5c:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011ff60:  b2 16 e0 28  or  %i3, 0x28, %i1	! 0xcf011428
a011ff64:  fa 06 40 00  ld  [ %i1 ], %i5
a011ff68:  b9 2b e0 10  sll  %o7, 0x10, %i4
a011ff6c:  b0 17 60 03  or  %i5, 3, %i0
a011ff70:  b5 37 20 12  srl  %i4, 0x12, %i2
a011ff74:  f0 26 40 00  st  %i0, [ %i1 ]
a011ff78:  80 a3 60 02  cmp  %o5, 2
a011ff7c:  02 80 00 2e  be  0xa0120034
a011ff80:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a011ff84:  80 a3 60 01  cmp  %o5, 1
a011ff88:  18 80 00 5a  bgu  0xa01200f0
a011ff8c:  39 00 06 8b  sethi  %hi(0x1a2c00), %i4
a011ff90:  82 17 23 b0  or  %i4, 0x3b0, %g1	! 0x1a2fb0
a011ff94:  b0 03 40 0d  add  %o5, %o5, %i0
a011ff98:  fa 10 40 18  lduh  [ %g1 + %i0 ], %i5
a011ff9c:  b6 07 60 53  add  %i5, 0x53, %i3
a011ffa0:  b9 2e e0 02  sll  %i3, 2, %i4
a011ffa4:  b0 07 60 54  add  %i5, 0x54, %i0
a011ffa8:  37 33 c0 00  sethi  %hi(0xcf000000), %i3
a011ffac:  bb 2e 20 02  sll  %i0, 2, %i5
a011ffb0:  b8 17 00 1b  or  %i4, %i3, %i4
a011ffb4:  82 0e a0 ff  and  %i2, 0xff, %g1
a011ffb8:  c2 27 00 00  st  %g1, [ %i4 ]
a011ffbc:  b2 17 40 1b  or  %i5, %i3, %i1
a011ffc0:  b1 36 a0 08  srl  %i2, 8, %i0
a011ffc4:  f0 26 40 00  st  %i0, [ %i1 ]
a011ffc8:  30 80 00 4a  b,a   0xa01200f0
a011ffcc:  b6 06 00 18  add  %i0, %i0, %i3
a011ffd0:  82 16 a3 b0  or  %i2, 0x3b0, %g1
a011ffd4:  fa 10 40 1b  lduh  [ %g1 + %i3 ], %i5
a011ffd8:  b8 07 60 40  add  %i5, 0x40, %i4
a011ffdc:  b1 2f 20 02  sll  %i4, 2, %i0
a011ffe0:  39 33 c0 00  sethi  %hi(0xcf000000), %i4
a011ffe4:  b6 16 00 1c  or  %i0, %i4, %i3
a011ffe8:  b4 07 60 41  add  %i5, 0x41, %i2
a011ffec:  bb 2e a0 02  sll  %i2, 2, %i5
a011fff0:  b1 2e 60 10  sll  %i1, 0x10, %i0
a011fff4:  82 0e 60 ff  and  %i1, 0xff, %g1
a011fff8:  c2 26 c0 00  st  %g1, [ %i3 ]
a011fffc:  b2 17 40 1c  or  %i5, %i4, %i1
a0120000:  b5 36 20 18  srl  %i0, 0x18, %i2
a0120004:  f4 26 40 00  st  %i2, [ %i1 ]
a0120008:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a012000c:  b2 16 e0 28  or  %i3, 0x28, %i1	! 0xcf011428
a0120010:  fa 06 40 00  ld  [ %i1 ], %i5
a0120014:  b9 2b e0 10  sll  %o7, 0x10, %i4
a0120018:  b0 17 60 03  or  %i5, 3, %i0
a012001c:  b5 37 20 12  srl  %i4, 0x12, %i2
a0120020:  f0 26 40 00  st  %i0, [ %i1 ]
a0120024:  80 a3 60 02  cmp  %o5, 2
a0120028:  12 bf ff d8  bne  0xa011ff88
a012002c:  80 a3 60 01  cmp  %o5, 1
a0120030:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a0120034:  b0 0e a0 ff  and  %i2, 0xff, %i0
a0120038:  9e 10 63 b0  or  %g1, 0x3b0, %o7
a012003c:  b3 36 a0 08  srl  %i2, 8, %i1
a0120040:  b6 10 20 00  clr  %i3
a0120044:  82 10 20 00  clr  %g1
a0120048:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a012004c:  82 00 40 01  add  %g1, %g1, %g1
a0120050:  fa 13 c0 01  lduh  [ %o7 + %g1 ], %i5
a0120054:  b8 07 60 53  add  %i5, 0x53, %i4
a0120058:  83 2f 20 02  sll  %i4, 2, %g1
a012005c:  ba 07 60 54  add  %i5, 0x54, %i5
a0120060:  b8 10 40 1a  or  %g1, %i2, %i4
a0120064:  83 2f 60 02  sll  %i5, 2, %g1
a0120068:  ba 10 40 1a  or  %g1, %i2, %i5
a012006c:  b6 06 e0 01  inc  %i3
a0120070:  f0 27 00 00  st  %i0, [ %i4 ]
a0120074:  82 0e e0 ff  and  %i3, 0xff, %g1
a0120078:  f2 27 40 00  st  %i1, [ %i5 ]
a012007c:  80 a0 60 01  cmp  %g1, 1
a0120080:  28 bf ff f4  bleu,a   0xa0120050
a0120084:  82 00 40 01  add  %g1, %g1, %g1
a0120088:  30 80 00 1a  b,a   0xa01200f0
a012008c:  31 00 06 8b  sethi  %hi(0x1a2c00), %i0
a0120090:  b9 2e 60 10  sll  %i1, 0x10, %i4
a0120094:  98 16 23 b0  or  %i0, 0x3b0, %o4
a0120098:  b1 37 20 18  srl  %i4, 0x18, %i0
a012009c:  b6 10 20 00  clr  %i3
a01200a0:  82 10 20 00  clr  %g1
a01200a4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a01200a8:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a01200ac:  82 00 40 01  add  %g1, %g1, %g1
a01200b0:  fa 13 00 01  lduh  [ %o4 + %g1 ], %i5
a01200b4:  b8 07 60 40  add  %i5, 0x40, %i4
a01200b8:  83 2f 20 02  sll  %i4, 2, %g1
a01200bc:  ba 07 60 41  add  %i5, 0x41, %i5
a01200c0:  b8 10 40 1a  or  %g1, %i2, %i4
a01200c4:  83 2f 60 02  sll  %i5, 2, %g1
a01200c8:  ba 10 40 1a  or  %g1, %i2, %i5
a01200cc:  b6 06 e0 01  inc  %i3
a01200d0:  f2 27 00 00  st  %i1, [ %i4 ]
a01200d4:  82 0e e0 ff  and  %i3, 0xff, %g1
a01200d8:  f0 27 40 00  st  %i0, [ %i5 ]
a01200dc:  80 a0 60 01  cmp  %g1, 1
a01200e0:  08 bf ff f4  bleu  0xa01200b0
a01200e4:  82 00 40 01  add  %g1, %g1, %g1
a01200e8:  10 bf ff 9e  b  0xa011ff60
a01200ec:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a01200f0:  81 c7 e0 08  ret
a01200f4:  81 e8 00 00  restore
