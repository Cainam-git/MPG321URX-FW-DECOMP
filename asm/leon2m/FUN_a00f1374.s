# leon2m FUN_a00f1374 0xa00f1374-0xa00f14e4 (368 bytes)
a00f1374:  9d e3 bf 98  save  %sp, -104, %sp
a00f1378:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f137c:  9a 10 00 1b  mov  %i3, %o5
a00f1380:  80 a6 20 04  cmp  %i0, 4
a00f1384:  98 10 00 19  mov  %i1, %o4
a00f1388:  02 80 00 20  be  0xa00f1408
a00f138c:  9e 10 00 1a  mov  %i2, %o7
a00f1390:  80 a6 20 03  cmp  %i0, 3
a00f1394:  18 80 00 52  bgu  0xa00f14dc
a00f1398:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00f139c:  83 2e 60 10  sll  %i1, 0x10, %g1
a00f13a0:  b6 13 e2 7e  or  %o7, 0x27e, %i3
a00f13a4:  ba 06 00 18  add  %i0, %i0, %i5
a00f13a8:  f2 16 c0 1d  lduh  [ %i3 + %i5 ], %i1
a00f13ac:  b9 30 60 10  srl  %g1, 0x10, %i4
a00f13b0:  82 06 40 1c  add  %i1, %i4, %g1
a00f13b4:  b7 28 60 02  sll  %g1, 2, %i3
a00f13b8:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00f13bc:  b2 0b 60 ff  and  %o5, 0xff, %i1
a00f13c0:  b8 16 c0 1d  or  %i3, %i5, %i4
a00f13c4:  c2 07 00 00  ld  [ %i4 ], %g1
a00f13c8:  80 a6 60 01  cmp  %i1, 1
a00f13cc:  02 80 00 03  be  0xa00f13d8
a00f13d0:  b2 10 40 1a  or  %g1, %i2, %i1
a00f13d4:  b2 28 40 1a  andn  %g1, %i2, %i1
a00f13d8:  ba 13 e2 7e  or  %o7, 0x27e, %i5
a00f13dc:  b8 06 00 18  add  %i0, %i0, %i4
a00f13e0:  b5 2b 20 10  sll  %o4, 0x10, %i2
a00f13e4:  f0 17 40 1c  lduh  [ %i5 + %i4 ], %i0
a00f13e8:  b7 36 a0 10  srl  %i2, 0x10, %i3
a00f13ec:  82 06 00 1b  add  %i0, %i3, %g1
a00f13f0:  b9 28 60 02  sll  %g1, 2, %i4
a00f13f4:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00f13f8:  b0 17 00 1d  or  %i4, %i5, %i0
a00f13fc:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00f1400:  f4 26 00 00  st  %i2, [ %i0 ]
a00f1404:  30 80 00 36  b,a   0xa00f14dc
a00f1408:  b5 2e 60 10  sll  %i1, 0x10, %i2
a00f140c:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f1410:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00f1414:  80 a7 20 01  cmp  %i4, 1
a00f1418:  b8 16 62 7e  or  %i1, 0x27e, %i4
a00f141c:  b3 36 a0 10  srl  %i2, 0x10, %i1
a00f1420:  b4 10 20 00  clr  %i2
a00f1424:  b6 10 20 00  clr  %i3
a00f1428:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00f142c:  02 80 00 11  be  0xa00f1470
a00f1430:  b0 38 00 0f  xnor  %g0, %o7, %i0
a00f1434:  82 06 c0 1b  add  %i3, %i3, %g1
a00f1438:  fa 17 00 01  lduh  [ %i4 + %g1 ], %i5
a00f143c:  b6 07 40 19  add  %i5, %i1, %i3
a00f1440:  bb 2e e0 02  sll  %i3, 2, %i5
a00f1444:  ba 17 40 0d  or  %i5, %o5, %i5
a00f1448:  c2 07 40 00  ld  [ %i5 ], %g1
a00f144c:  b6 08 40 18  and  %g1, %i0, %i3
a00f1450:  82 0e e0 ff  and  %i3, 0xff, %g1
a00f1454:  b4 06 a0 01  inc  %i2
a00f1458:  b6 0e a0 ff  and  %i2, 0xff, %i3
a00f145c:  c2 27 40 00  st  %g1, [ %i5 ]
a00f1460:  80 a6 e0 03  cmp  %i3, 3
a00f1464:  08 bf ff f5  bleu  0xa00f1438
a00f1468:  82 06 c0 1b  add  %i3, %i3, %g1
a00f146c:  30 80 00 1c  b,a   0xa00f14dc
a00f1470:  82 06 c0 1b  add  %i3, %i3, %g1
a00f1474:  f6 17 00 01  lduh  [ %i4 + %g1 ], %i3
a00f1478:  b0 06 c0 19  add  %i3, %i1, %i0
a00f147c:  bb 2e 20 02  sll  %i0, 2, %i5
a00f1480:  b0 17 40 0d  or  %i5, %o5, %i0
a00f1484:  c2 06 00 00  ld  [ %i0 ], %g1
a00f1488:  b6 10 40 0f  or  %g1, %o7, %i3
a00f148c:  82 0e e0 ff  and  %i3, 0xff, %g1
a00f1490:  b4 06 a0 01  inc  %i2
a00f1494:  b6 0e a0 ff  and  %i2, 0xff, %i3
a00f1498:  c2 26 00 00  st  %g1, [ %i0 ]
a00f149c:  80 a6 e0 03  cmp  %i3, 3
a00f14a0:  18 80 00 0f  bgu  0xa00f14dc
a00f14a4:  82 06 c0 1b  add  %i3, %i3, %g1
a00f14a8:  f6 17 00 01  lduh  [ %i4 + %g1 ], %i3
a00f14ac:  b0 06 c0 19  add  %i3, %i1, %i0
a00f14b0:  bb 2e 20 02  sll  %i0, 2, %i5
a00f14b4:  b0 17 40 0d  or  %i5, %o5, %i0
a00f14b8:  c2 06 00 00  ld  [ %i0 ], %g1
a00f14bc:  b6 10 40 0f  or  %g1, %o7, %i3
a00f14c0:  82 0e e0 ff  and  %i3, 0xff, %g1
a00f14c4:  b4 06 a0 01  inc  %i2
a00f14c8:  b6 0e a0 ff  and  %i2, 0xff, %i3
a00f14cc:  c2 26 00 00  st  %g1, [ %i0 ]
a00f14d0:  80 a6 e0 03  cmp  %i3, 3
a00f14d4:  08 bf ff e8  bleu  0xa00f1474
a00f14d8:  82 06 c0 1b  add  %i3, %i3, %g1
a00f14dc:  81 c7 e0 08  ret
a00f14e0:  81 e8 00 00  restore
