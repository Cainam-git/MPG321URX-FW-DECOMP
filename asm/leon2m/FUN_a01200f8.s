# leon2m FUN_a01200f8 0xa01200f8-0xa01202c0 (456 bytes)
a01200f8:  9d e3 bf 98  save  %sp, -104, %sp
a01200fc:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a0120100:  ba 17 20 28  or  %i4, 0x28, %i5	! 0xcf011428
a0120104:  f6 07 40 00  ld  [ %i5 ], %i3
a0120108:  82 16 e0 03  or  %i3, 3, %g1
a012010c:  9e 10 00 18  mov  %i0, %o7
a0120110:  c2 27 40 00  st  %g1, [ %i5 ]
a0120114:  80 a6 20 02  cmp  %i0, 2
a0120118:  02 80 00 4f  be  0xa0120254
a012011c:  98 10 00 1a  mov  %i2, %o4
a0120120:  80 a3 e0 01  cmp  %o7, 1
a0120124:  08 80 00 1d  bleu  0xa0120198
a0120128:  39 00 06 8b  sethi  %hi(0x1a2c00), %i4
a012012c:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a0120130:  b2 17 60 28  or  %i5, 0x28, %i1	! 0xcf011428
a0120134:  f4 06 40 00  ld  [ %i1 ], %i2
a0120138:  b0 16 a0 03  or  %i2, 3, %i0
a012013c:  f0 26 40 00  st  %i0, [ %i1 ]
a0120140:  80 a3 e0 02  cmp  %o7, 2
a0120144:  02 80 00 2d  be  0xa01201f8
a0120148:  b7 2b 20 10  sll  %o4, 0x10, %i3
a012014c:  80 a3 e0 01  cmp  %o7, 1
a0120150:  18 80 00 5a  bgu  0xa01202b8
a0120154:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a0120158:  b6 10 63 b0  or  %g1, 0x3b0, %i3	! 0x1a2fb0
a012015c:  b4 03 c0 0f  add  %o7, %o7, %i2
a0120160:  fa 16 c0 1a  lduh  [ %i3 + %i2 ], %i5
a0120164:  b8 07 60 44  add  %i5, 0x44, %i4
a0120168:  b1 2f 20 02  sll  %i4, 2, %i0
a012016c:  b2 07 60 45  add  %i5, 0x45, %i1
a0120170:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a0120174:  b6 16 00 1a  or  %i0, %i2, %i3
a0120178:  bb 2e 60 02  sll  %i1, 2, %i5
a012017c:  b9 2b 20 10  sll  %o4, 0x10, %i4
a0120180:  82 0b 20 ff  and  %o4, 0xff, %g1
a0120184:  c2 26 c0 00  st  %g1, [ %i3 ]
a0120188:  b2 17 40 1a  or  %i5, %i2, %i1
a012018c:  b1 37 20 18  srl  %i4, 0x18, %i0
a0120190:  f0 26 40 00  st  %i0, [ %i1 ]
a0120194:  30 80 00 49  b,a   0xa01202b8
a0120198:  82 17 23 b0  or  %i4, 0x3b0, %g1
a012019c:  b6 03 c0 0f  add  %o7, %o7, %i3
a01201a0:  fa 10 40 1b  lduh  [ %g1 + %i3 ], %i5
a01201a4:  b4 07 60 42  add  %i5, 0x42, %i2
a01201a8:  b9 2e a0 02  sll  %i2, 2, %i4
a01201ac:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a01201b0:  82 07 60 43  add  %i5, 0x43, %g1
a01201b4:  b6 0e 60 ff  and  %i1, 0xff, %i3
a01201b8:  bb 28 60 02  sll  %g1, 2, %i5
a01201bc:  b8 17 00 1a  or  %i4, %i2, %i4
a01201c0:  f6 27 00 00  st  %i3, [ %i4 ]
a01201c4:  b0 17 40 1a  or  %i5, %i2, %i0
a01201c8:  83 2e 60 10  sll  %i1, 0x10, %g1
a01201cc:  b7 30 60 18  srl  %g1, 0x18, %i3
a01201d0:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a01201d4:  f6 26 00 00  st  %i3, [ %i0 ]
a01201d8:  b2 17 60 28  or  %i5, 0x28, %i1
a01201dc:  f4 06 40 00  ld  [ %i1 ], %i2
a01201e0:  b0 16 a0 03  or  %i2, 3, %i0
a01201e4:  f0 26 40 00  st  %i0, [ %i1 ]
a01201e8:  80 a3 e0 02  cmp  %o7, 2
a01201ec:  12 bf ff d9  bne  0xa0120150
a01201f0:  80 a3 e0 01  cmp  %o7, 1
a01201f4:  b7 2b 20 10  sll  %o4, 0x10, %i3
a01201f8:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a01201fc:  9e 10 63 b0  or  %g1, 0x3b0, %o7	! 0x1a2fb0
a0120200:  b1 36 e0 18  srl  %i3, 0x18, %i0
a0120204:  b6 10 20 00  clr  %i3
a0120208:  82 10 20 00  clr  %g1
a012020c:  b4 0b 20 ff  and  %o4, 0xff, %i2
a0120210:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a0120214:  b8 00 40 01  add  %g1, %g1, %i4
a0120218:  fa 13 c0 1c  lduh  [ %o7 + %i4 ], %i5
a012021c:  82 07 60 44  add  %i5, 0x44, %g1
a0120220:  b9 28 60 02  sll  %g1, 2, %i4
a0120224:  82 17 00 19  or  %i4, %i1, %g1
a0120228:  ba 07 60 45  add  %i5, 0x45, %i5
a012022c:  f4 20 40 00  st  %i2, [ %g1 ]
a0120230:  bb 2f 60 02  sll  %i5, 2, %i5
a0120234:  b6 06 e0 01  inc  %i3
a0120238:  b8 17 40 19  or  %i5, %i1, %i4
a012023c:  82 0e e0 ff  and  %i3, 0xff, %g1
a0120240:  f0 27 00 00  st  %i0, [ %i4 ]
a0120244:  80 a0 60 01  cmp  %g1, 1
a0120248:  08 bf ff f4  bleu  0xa0120218
a012024c:  b8 00 40 01  add  %g1, %g1, %i4
a0120250:  30 80 00 1a  b,a   0xa01202b8
a0120254:  b5 2e 60 10  sll  %i1, 0x10, %i2
a0120258:  b0 0e 60 ff  and  %i1, 0xff, %i0
a012025c:  33 00 06 8b  sethi  %hi(0x1a2c00), %i1
a0120260:  9a 16 63 b0  or  %i1, 0x3b0, %o5	! 0x1a2fb0
a0120264:  b3 36 a0 18  srl  %i2, 0x18, %i1
a0120268:  b4 10 20 00  clr  %i2
a012026c:  82 10 20 00  clr  %g1
a0120270:  37 33 c0 00  sethi  %hi(0xcf000000), %i3
a0120274:  82 00 40 01  add  %g1, %g1, %g1
a0120278:  fa 13 40 01  lduh  [ %o5 + %g1 ], %i5
a012027c:  b8 07 60 42  add  %i5, 0x42, %i4
a0120280:  83 2f 20 02  sll  %i4, 2, %g1
a0120284:  ba 07 60 43  add  %i5, 0x43, %i5
a0120288:  b8 10 40 1b  or  %g1, %i3, %i4
a012028c:  83 2f 60 02  sll  %i5, 2, %g1
a0120290:  ba 10 40 1b  or  %g1, %i3, %i5
a0120294:  b4 06 a0 01  inc  %i2
a0120298:  f0 27 00 00  st  %i0, [ %i4 ]
a012029c:  82 0e a0 ff  and  %i2, 0xff, %g1
a01202a0:  f2 27 40 00  st  %i1, [ %i5 ]
a01202a4:  80 a0 60 01  cmp  %g1, 1
a01202a8:  28 bf ff f4  bleu,a   0xa0120278
a01202ac:  82 00 40 01  add  %g1, %g1, %g1
a01202b0:  10 bf ff a0  b  0xa0120130
a01202b4:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a01202b8:  81 c7 e0 08  ret
a01202bc:  81 e8 00 00  restore
