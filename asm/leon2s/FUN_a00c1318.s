# leon2s FUN_a00c1318 0xa00c1318-0xa00c1550 (568 bytes)
a00c1318:  9d e3 bf 98  save  %sp, -104, %sp
a00c131c:  21 33 c0 45  sethi  %hi(0xcf011400), %l0
a00c1320:  a2 14 22 74  or  %l0, 0x274, %l1	! 0xcf011674
a00c1324:  da 04 40 00  ld  [ %l1 ], %o5
a00c1328:  a4 14 20 38  or  %l0, 0x38, %l2
a00c132c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c1330:  c2 04 80 00  ld  [ %l2 ], %g1
a00c1334:  a8 10 00 0d  mov  %o5, %l4
a00c1338:  ac 10 00 01  mov  %g1, %l6
a00c133c:  92 10 24 87  mov  0x487, %o1
a00c1340:  40 3b d6 1e  call  0xa0fb6bb8
a00c1344:  90 10 00 18  mov  %i0, %o0
a00c1348:  a0 14 20 3c  or  %l0, 0x3c, %l0
a00c134c:  c2 04 00 00  ld  [ %l0 ], %g1
a00c1350:  aa 10 00 08  mov  %o0, %l5
a00c1354:  ae 10 00 01  mov  %g1, %l7
a00c1358:  92 10 20 32  mov  0x32, %o1
a00c135c:  40 3b d6 17  call  0xa0fb6bb8
a00c1360:  90 10 00 18  mov  %i0, %o0
a00c1364:  1b 33 c0 3c  sethi  %hi(0xcf00f000), %o5
a00c1368:  9a 13 62 1c  or  %o5, 0x21c, %o5	! 0xcf00f21c
a00c136c:  d8 03 40 00  ld  [ %o5 ], %o4
a00c1370:  c2 03 40 00  ld  [ %o5 ], %g1
a00c1374:  82 08 7f e7  and  %g1, -25, %g1
a00c1378:  c2 23 40 00  st  %g1, [ %o5 ]
a00c137c:  c2 04 40 00  ld  [ %l1 ], %g1
a00c1380:  82 10 60 18  or  %g1, 0x18, %g1
a00c1384:  c2 24 40 00  st  %g1, [ %l1 ]
a00c1388:  c2 04 80 00  ld  [ %l2 ], %g1
a00c138c:  82 10 60 04  or  %g1, 4, %g1
a00c1390:  c2 24 80 00  st  %g1, [ %l2 ]
a00c1394:  a6 12 20 08  or  %o0, 8, %l3
a00c1398:  a4 10 00 0c  mov  %o4, %l2
a00c139c:  90 10 00 18  mov  %i0, %o0
a00c13a0:  92 10 24 87  mov  0x487, %o1
a00c13a4:  94 10 20 01  mov  1, %o2
a00c13a8:  40 3b d6 3c  call  0xa0fb6c98
a00c13ac:  96 10 20 01  mov  1, %o3
a00c13b0:  c2 04 00 00  ld  [ %l0 ], %g1
a00c13b4:  82 08 7f fe  and  %g1, -2, %g1
a00c13b8:  c2 24 00 00  st  %g1, [ %l0 ]
a00c13bc:  80 a6 20 00  cmp  %i0, 0
a00c13c0:  32 80 00 07  bne,a   0xa00c13dc
a00c13c4:  90 10 00 18  mov  %i0, %o0
a00c13c8:  90 10 20 00  clr  %o0
a00c13cc:  92 10 20 32  mov  0x32, %o1
a00c13d0:  94 10 20 30  mov  0x30, %o2
a00c13d4:  10 80 00 05  b  0xa00c13e8
a00c13d8:  96 10 20 00  clr  %o3
a00c13dc:  92 10 20 32  mov  0x32, %o1
a00c13e0:  94 10 20 30  mov  0x30, %o2
a00c13e4:  96 10 20 01  mov  1, %o3
a00c13e8:  40 3b d6 2c  call  0xa0fb6c98
a00c13ec:  a0 10 20 00  clr  %l0
a00c13f0:  92 04 22 80  add  %l0, 0x280, %o1
a00c13f4:  83 2c 20 10  sll  %l0, 0x10, %g1
a00c13f8:  83 30 60 10  srl  %g1, 0x10, %g1
a00c13fc:  93 2a 60 10  sll  %o1, 0x10, %o1
a00c1400:  d4 0e 40 01  ldub  [ %i1 + %g1 ], %o2
a00c1404:  93 32 60 10  srl  %o1, 0x10, %o1
a00c1408:  40 3b d5 fe  call  0xa0fb6c00
a00c140c:  90 10 00 18  mov  %i0, %o0
a00c1410:  9a 04 20 01  add  %l0, 1, %o5
a00c1414:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c1418:  83 30 60 10  srl  %g1, 0x10, %g1
a00c141c:  80 a0 60 04  cmp  %g1, 4
a00c1420:  08 bf ff f4  bleu  0xa00c13f0
a00c1424:  a0 10 00 0d  mov  %o5, %l0
a00c1428:  90 10 00 18  mov  %i0, %o0
a00c142c:  92 10 20 e9  mov  0xe9, %o1
a00c1430:  40 3b d5 f4  call  0xa0fb6c00
a00c1434:  94 10 20 0f  mov  0xf, %o2
a00c1438:  90 10 00 18  mov  %i0, %o0
a00c143c:  40 3b d5 df  call  0xa0fb6bb8
a00c1440:  92 10 20 e9  mov  0xe9, %o1
a00c1444:  80 8a 20 0f  btst  0xf, %o0
a00c1448:  12 bf ff fd  bne  0xa00c143c
a00c144c:  90 10 00 18  mov  %i0, %o0
a00c1450:  a0 10 20 00  clr  %l0
a00c1454:  83 2c 20 10  sll  %l0, 0x10, %g1
a00c1458:  83 30 60 10  srl  %g1, 0x10, %g1
a00c145c:  d4 0e 40 01  ldub  [ %i1 + %g1 ], %o2
a00c1460:  90 10 00 18  mov  %i0, %o0
a00c1464:  40 3b d5 e7  call  0xa0fb6c00
a00c1468:  92 10 20 e8  mov  0xe8, %o1
a00c146c:  9a 04 20 01  add  %l0, 1, %o5
a00c1470:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c1474:  83 30 60 10  srl  %g1, 0x10, %g1
a00c1478:  80 a0 60 04  cmp  %g1, 4
a00c147c:  08 bf ff f6  bleu  0xa00c1454
a00c1480:  a0 10 00 0d  mov  %o5, %l0
a00c1484:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00c1488:  98 13 63 80  or  %o5, 0x380, %o4	! 0xcf011780
a00c148c:  d6 03 00 00  ld  [ %o4 ], %o3
a00c1490:  82 10 20 06  mov  6, %g1
a00c1494:  c2 23 00 00  st  %g1, [ %o4 ]
a00c1498:  82 13 63 84  or  %o5, 0x384, %g1
a00c149c:  c0 20 40 00  clr  [ %g1 ]
a00c14a0:  82 13 63 88  or  %o5, 0x388, %g1
a00c14a4:  c0 20 40 00  clr  [ %g1 ]
a00c14a8:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a00c14ac:  82 10 63 cc  or  %g1, 0x3cc, %g1	! 0xcf00bfcc
a00c14b0:  a2 10 00 0d  mov  %o5, %l1
a00c14b4:  c0 20 40 00  clr  [ %g1 ]
a00c14b8:  a0 10 20 00  clr  %l0
a00c14bc:  94 13 63 8c  or  %o5, 0x38c, %o2
a00c14c0:  98 04 20 01  add  %l0, 1, %o4
a00c14c4:  83 2c 20 10  sll  %l0, 0x10, %g1
a00c14c8:  83 30 60 10  srl  %g1, 0x10, %g1
a00c14cc:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00c14d0:  c2 0e 80 01  ldub  [ %i2 + %g1 ], %g1
a00c14d4:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c14d8:  c2 22 80 00  st  %g1, [ %o2 ]
a00c14dc:  80 a3 61 19  cmp  %o5, 0x119
a00c14e0:  08 bf ff f8  bleu  0xa00c14c0
a00c14e4:  a0 10 00 0c  mov  %o4, %l0
a00c14e8:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00c14ec:  82 14 63 80  or  %l1, 0x380, %g1
a00c14f0:  da 20 40 00  st  %o5, [ %g1 ]
a00c14f4:  9a 0d 20 ff  and  %l4, 0xff, %o5
a00c14f8:  82 14 62 74  or  %l1, 0x274, %g1
a00c14fc:  da 20 40 00  st  %o5, [ %g1 ]
a00c1500:  9a 0d a0 ff  and  %l6, 0xff, %o5
a00c1504:  82 14 60 38  or  %l1, 0x38, %g1
a00c1508:  da 20 40 00  st  %o5, [ %g1 ]
a00c150c:  94 0d 60 ff  and  %l5, 0xff, %o2
a00c1510:  90 10 00 18  mov  %i0, %o0
a00c1514:  40 3b d5 bb  call  0xa0fb6c00
a00c1518:  92 10 24 87  mov  0x487, %o1
a00c151c:  9a 14 60 3c  or  %l1, 0x3c, %o5
a00c1520:  82 0d e0 ff  and  %l7, 0xff, %g1
a00c1524:  c2 23 40 00  st  %g1, [ %o5 ]
a00c1528:  90 10 00 18  mov  %i0, %o0
a00c152c:  94 0c e0 ff  and  %l3, 0xff, %o2
a00c1530:  40 3b d5 b4  call  0xa0fb6c00
a00c1534:  92 10 20 32  mov  0x32, %o1
a00c1538:  03 33 c0 3c  sethi  %hi(0xcf00f000), %g1
a00c153c:  9a 0c a0 ff  and  %l2, 0xff, %o5
a00c1540:  82 10 62 1c  or  %g1, 0x21c, %g1
a00c1544:  da 20 40 00  st  %o5, [ %g1 ]
a00c1548:  81 c7 e0 08  ret
a00c154c:  81 e8 00 00  restore
