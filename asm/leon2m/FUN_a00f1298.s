# leon2m FUN_a00f1298 0xa00f1298-0xa00f1374 (220 bytes)
a00f1298:  9d e3 bf 98  save  %sp, -104, %sp
a00f129c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f12a0:  80 a6 20 04  cmp  %i0, 4
a00f12a4:  02 80 00 17  be  0xa00f1300
a00f12a8:  9e 10 00 1a  mov  %i2, %o7
a00f12ac:  80 a6 20 03  cmp  %i0, 3
a00f12b0:  18 80 00 2f  bgu  0xa00f136c
a00f12b4:  b8 06 00 18  add  %i0, %i0, %i4
a00f12b8:  31 2a 00 9a  sethi  %hi(0xa8026800), %i0
a00f12bc:  bb 2e 60 10  sll  %i1, 0x10, %i5
a00f12c0:  b6 16 22 7e  or  %i0, 0x27e, %i3
a00f12c4:  f4 16 c0 1c  lduh  [ %i3 + %i4 ], %i2
a00f12c8:  83 37 60 10  srl  %i5, 0x10, %g1
a00f12cc:  b2 06 80 01  add  %i2, %g1, %i1
a00f12d0:  b6 06 60 01  add  %i1, 1, %i3
a00f12d4:  b1 2e 60 02  sll  %i1, 2, %i0
a00f12d8:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a00f12dc:  ba 16 00 1a  or  %i0, %i2, %i5
a00f12e0:  b8 0b e0 ff  and  %o7, 0xff, %i4
a00f12e4:  83 2e e0 02  sll  %i3, 2, %g1
a00f12e8:  b3 2b e0 10  sll  %o7, 0x10, %i1
a00f12ec:  f8 27 40 00  st  %i4, [ %i5 ]
a00f12f0:  b6 10 40 1a  or  %g1, %i2, %i3
a00f12f4:  b1 36 60 18  srl  %i1, 0x18, %i0
a00f12f8:  f0 26 c0 00  st  %i0, [ %i3 ]
a00f12fc:  30 80 00 1c  b,a   0xa00f136c
a00f1300:  83 2e 60 10  sll  %i1, 0x10, %g1
a00f1304:  b9 2e a0 10  sll  %i2, 0x10, %i4
a00f1308:  3b 2a 00 9a  sethi  %hi(0xa8026800), %i5
a00f130c:  b2 0e a0 ff  and  %i2, 0xff, %i1
a00f1310:  96 17 62 7e  or  %i5, 0x27e, %o3
a00f1314:  9b 30 60 10  srl  %g1, 0x10, %o5
a00f1318:  b5 37 20 18  srl  %i4, 0x18, %i2
a00f131c:  b0 10 20 00  clr  %i0
a00f1320:  b6 10 20 00  clr  %i3
a00f1324:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a00f1328:  82 06 c0 1b  add  %i3, %i3, %g1
a00f132c:  b0 06 20 01  inc  %i0
a00f1330:  80 a6 e0 03  cmp  %i3, 3
a00f1334:  02 80 00 0b  be  0xa00f1360
a00f1338:  b6 0e 20 ff  and  %i0, 0xff, %i3
a00f133c:  f8 12 c0 01  lduh  [ %o3 + %g1 ], %i4
a00f1340:  82 07 00 0d  add  %i4, %o5, %g1
a00f1344:  b8 00 60 01  add  %g1, 1, %i4
a00f1348:  bb 28 60 02  sll  %g1, 2, %i5
a00f134c:  82 17 40 0f  or  %i5, %o7, %g1
a00f1350:  bb 2f 20 02  sll  %i4, 2, %i5
a00f1354:  f2 20 40 00  st  %i1, [ %g1 ]
a00f1358:  b8 17 40 0f  or  %i5, %o7, %i4
a00f135c:  f4 27 00 00  st  %i2, [ %i4 ]
a00f1360:  80 a6 e0 03  cmp  %i3, 3
a00f1364:  08 bf ff f2  bleu  0xa00f132c
a00f1368:  82 06 c0 1b  add  %i3, %i3, %g1
a00f136c:  81 c7 e0 08  ret
a00f1370:  81 e8 00 00  restore
