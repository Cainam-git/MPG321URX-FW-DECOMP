# leon2m FUN_a01400e0 0xa01400e0-0xa0140304 (548 bytes)
a01400e0:  9d e3 bf 80  save  %sp, -128, %sp
a01400e4:  b8 10 20 00  clr  %i4
a01400e8:  ba 10 20 00  clr  %i5
a01400ec:  9a 07 bf f8  add  %fp, -8, %o5
a01400f0:  b0 07 40 1d  add  %i5, %i5, %i0
a01400f4:  b8 07 20 01  inc  %i4
a01400f8:  82 06 00 0d  add  %i0, %o5, %g1
a01400fc:  ba 0f 20 ff  and  %i4, 0xff, %i5
a0140100:  80 a7 60 03  cmp  %i5, 3
a0140104:  08 bf ff fb  bleu  0xa01400f0
a0140108:  c0 30 7f e8  clrh  [ %g1 + -24 ]
a014010c:  33 2a 00 b2  sethi  %hi(0xa802c800), %i1
a0140110:  96 16 63 dc  or  %i1, 0x3dc, %o3	! 0xa802cbdc
a0140114:  3b 00 06 9a  sethi  %hi(0x1a6800), %i5
a0140118:  98 17 62 24  or  %i5, 0x224, %o4	! 0x1a6a24
a014011c:  b0 10 20 00  clr  %i0
a0140120:  b2 10 20 00  clr  %i1
a0140124:  9e 10 3f ff  mov  -1, %o7
a0140128:  b5 2e 60 03  sll  %i1, 3, %i2
a014012c:  ba 06 80 19  add  %i2, %i1, %i5
a0140130:  bb 2f 60 02  sll  %i5, 2, %i5
a0140134:  b6 07 40 0c  add  %i5, %o4, %i3
a0140138:  f8 0e e0 03  ldub  [ %i3 + 3 ], %i4
a014013c:  82 06 40 19  add  %i1, %i1, %g1
a0140140:  b4 07 00 1c  add  %i4, %i4, %i2
a0140144:  b6 00 40 19  add  %g1, %i1, %i3
a0140148:  b8 06 80 0d  add  %i2, %o5, %i4
a014014c:  f4 17 3f e8  lduh  [ %i4 + -24 ], %i2
a0140150:  f2 13 00 1d  lduh  [ %o4 + %i5 ], %i1
a0140154:  b7 2e e0 02  sll  %i3, 2, %i3
a0140158:  82 06 80 19  add  %i2, %i1, %g1
a014015c:  b0 06 20 01  inc  %i0
a0140160:  ba 06 c0 0b  add  %i3, %o3, %i5
a0140164:  c2 37 3f e8  sth  %g1, [ %i4 + -24 ]
a0140168:  b2 0e 20 ff  and  %i0, 0xff, %i1
a014016c:  de 2f 60 08  stb  %o7, [ %i5 + 8 ]
a0140170:  f4 32 c0 1b  sth  %i2, [ %o3 + %i3 ]
a0140174:  80 a6 60 02  cmp  %i1, 2
a0140178:  08 bf ff ec  bleu  0xa0140128
a014017c:  de 27 60 04  st  %o7, [ %i5 + 4 ]
a0140180:  b8 10 20 00  clr  %i4
a0140184:  ba 10 20 00  clr  %i5
a0140188:  b2 07 40 1d  add  %i5, %i5, %i1
a014018c:  b8 07 20 01  inc  %i4
a0140190:  b0 06 40 0d  add  %i1, %o5, %i0
a0140194:  ba 0f 20 ff  and  %i4, 0xff, %i5
a0140198:  80 a7 60 01  cmp  %i5, 1
a014019c:  08 bf ff fb  bleu  0xa0140188
a01401a0:  c0 36 3f f0  clrh  [ %i0 + -16 ]
a01401a4:  39 00 06 9a  sethi  %hi(0x1a6800), %i4
a01401a8:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a01401ac:  96 17 21 fe  or  %i4, 0x1fe, %o3
a01401b0:  98 10 60 00  mov  %g1, %o4
a01401b4:  9e 10 20 00  clr  %o7
a01401b8:  b0 10 20 00  clr  %i0
a01401bc:  94 10 20 08  mov  8, %o2
a01401c0:  b4 5e 20 26  smul  %i0, 0x26, %i2
a01401c4:  b6 06 80 0b  add  %i2, %o3, %i3
a01401c8:  f2 0a c0 1a  ldub  [ %o3 + %i2 ], %i1
a01401cc:  b8 06 40 19  add  %i1, %i1, %i4
a01401d0:  fa 0e e0 01  ldub  [ %i3 + 1 ], %i5
a01401d4:  82 07 00 1d  add  %i4, %i5, %g1
a01401d8:  b4 08 60 ff  and  %g1, 0xff, %i2
a01401dc:  b2 06 80 1a  add  %i2, %i2, %i1
a01401e0:  82 06 40 0d  add  %i1, %o5, %g1
a01401e4:  f4 10 7f f0  lduh  [ %g1 + -16 ], %i2
a01401e8:  b3 2e 20 02  sll  %i0, 2, %i1
a01401ec:  f8 16 e0 02  lduh  [ %i3 + 2 ], %i4
a01401f0:  f0 0e e0 04  ldub  [ %i3 + 4 ], %i0
a01401f4:  ba 06 80 1c  add  %i2, %i4, %i5
a01401f8:  b9 3a 80 18  sra  %o2, %i0, %i4
a01401fc:  9e 03 e0 01  inc  %o7
a0140200:  fa 30 7f f0  sth  %i5, [ %g1 + -16 ]
a0140204:  b6 06 40 0c  add  %i1, %o4, %i3
a0140208:  b0 0b e0 ff  and  %o7, 0xff, %i0
a014020c:  f8 2e e0 02  stb  %i4, [ %i3 + 2 ]
a0140210:  80 a6 20 00  cmp  %i0, 0
a0140214:  02 bf ff eb  be  0xa01401c0
a0140218:  f4 33 00 19  sth  %i2, [ %o4 + %i1 ]
a014021c:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a0140220:  90 10 63 dc  or  %g1, 0x3dc, %o0	! 0xa802cbdc
a0140224:  37 00 06 9a  sethi  %hi(0x1a6800), %i3
a0140228:  31 00 06 9a  sethi  %hi(0x1a6800), %i0
a014022c:  94 16 e1 fe  or  %i3, 0x1fe, %o2
a0140230:  96 16 22 24  or  %i0, 0x224, %o3
a0140234:  98 10 20 00  clr  %o4
a0140238:  82 10 20 00  clr  %g1
a014023c:  92 10 00 08  mov  %o0, %o1
a0140240:  b4 58 60 26  smul  %g1, 0x26, %i2
a0140244:  f6 0a 80 1a  ldub  [ %o2 + %i2 ], %i3
a0140248:  b9 2e e0 03  sll  %i3, 3, %i4
a014024c:  b2 07 00 1b  add  %i4, %i3, %i1
a0140250:  b9 2e 60 02  sll  %i1, 2, %i4
a0140254:  ba 07 00 0b  add  %i4, %o3, %i5
a0140258:  f2 0f 60 02  ldub  [ %i5 + 2 ], %i1
a014025c:  80 a6 60 00  cmp  %i1, 0
a0140260:  32 80 00 23  bne,a   0xa01402ec
a0140264:  98 03 20 01  inc  %o4
a0140268:  b0 06 80 0a  add  %i2, %o2, %i0
a014026c:  de 0e 20 04  ldub  [ %i0 + 4 ], %o7
a0140270:  ba 06 c0 1b  add  %i3, %i3, %i5
a0140274:  b0 07 40 1b  add  %i5, %i3, %i0
a0140278:  f8 12 c0 1c  lduh  [ %o3 + %i4 ], %i4
a014027c:  b7 37 20 08  srl  %i4, 8, %i3
a0140280:  82 03 ff ff  add  %o7, -1, %g1
a0140284:  b5 3e c0 01  sra  %i3, %g1, %i2
a0140288:  83 2e 20 02  sll  %i0, 2, %g1
a014028c:  b0 0e a0 ff  and  %i2, 0xff, %i0
a0140290:  9a 00 40 09  add  %g1, %o1, %o5
a0140294:  80 a6 40 18  cmp  %i1, %i0
a0140298:  f4 2b 60 09  stb  %i2, [ %o5 + 9 ]
a014029c:  b2 10 3f ff  mov  -1, %i1
a01402a0:  1a 80 00 11  bcc  0xa01402e4
a01402a4:  b8 10 20 00  clr  %i4
a01402a8:  f4 12 00 01  lduh  [ %o0 + %g1 ], %i2
a01402ac:  b7 2b e0 08  sll  %o7, 8, %i3
a01402b0:  82 10 20 00  clr  %g1
a01402b4:  82 00 60 01  inc  %g1
a01402b8:  ba 58 40 1b  smul  %g1, %i3, %i5
a01402bc:  82 06 80 1d  add  %i2, %i5, %g1
a01402c0:  fa 08 7f ff  ldub  [ %g1 + -1 ], %i5
a01402c4:  80 a7 60 55  cmp  %i5, 0x55
a01402c8:  22 80 00 07  be,a   0xa01402e4
a01402cc:  b2 10 00 1c  mov  %i4, %i1
a01402d0:  b8 07 20 01  inc  %i4
a01402d4:  82 0f 20 ff  and  %i4, 0xff, %g1
a01402d8:  80 a0 40 18  cmp  %g1, %i0
a01402dc:  0a bf ff f7  bcs  0xa01402b8
a01402e0:  82 00 60 01  inc  %g1
a01402e4:  f2 2b 60 08  stb  %i1, [ %o5 + 8 ]
a01402e8:  98 03 20 01  inc  %o4
a01402ec:  82 0b 20 ff  and  %o4, 0xff, %g1
a01402f0:  80 a0 60 00  cmp  %g1, 0
a01402f4:  02 bf ff d4  be  0xa0140244
a01402f8:  b4 58 60 26  smul  %g1, 0x26, %i2
a01402fc:  81 c7 e0 08  ret
a0140300:  81 e8 00 00  restore
