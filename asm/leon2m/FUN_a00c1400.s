# leon2m FUN_a00c1400 0xa00c1400-0xa00c1608 (520 bytes)
a00c1400:  9d e3 bf 98  save  %sp, -104, %sp
a00c1404:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c1408:  80 a4 20 02  cmp  %l0, 2
a00c140c:  02 80 00 5d  be  0xa00c1580
a00c1410:  80 a4 20 03  cmp  %l0, 3
a00c1414:  02 80 00 5e  be  0xa00c158c
a00c1418:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c141c:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c1420:  96 08 60 ff  and  %g1, 0xff, %o3
a00c1424:  94 02 ff d0  add  %o3, -48, %o2
a00c1428:  90 0a a0 ff  and  %o2, 0xff, %o0
a00c142c:  80 a2 20 03  cmp  %o0, 3
a00c1430:  18 80 00 74  bgu  0xa00c1600
a00c1434:  b0 10 20 ff  mov  0xff, %i0
a00c1438:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c143c:  a2 13 22 90  or  %o4, 0x290, %l1	! 0xa802d290
a00c1440:  da 0c 60 1f  ldub  [ %l1 + 0x1f ], %o5
a00c1444:  80 a3 60 00  cmp  %o5, 0
a00c1448:  02 80 00 6e  be  0xa00c1600
a00c144c:  01 00 00 00  nop
a00c1450:  40 02 0c 53  call  0xa014459c
a00c1454:  01 00 00 00  nop
a00c1458:  40 00 5f 78  call  0xa00d9238
a00c145c:  d0 2c 60 1e  stb  %o0, [ %l1 + 0x1e ]
a00c1460:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a00c1464:  f0 13 e3 f4  lduh  [ %o7 + 0x3f4 ], %i0	! 0xa802cff4
a00c1468:  a2 16 24 00  or  %i0, 0x400, %l1
a00c146c:  e2 33 e3 f4  sth  %l1, [ %o7 + 0x3f4 ]
a00c1470:  7f ff dd 17  call  0xa00b88cc
a00c1474:  01 00 00 00  nop
a00c1478:  80 a4 20 02  cmp  %l0, 2
a00c147c:  02 80 00 24  be  0xa00c150c
a00c1480:  80 a4 20 03  cmp  %l0, 3
a00c1484:  02 80 00 45  be  0xa00c1598
a00c1488:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c148c:  94 13 e0 78  or  %o7, 0x78, %o2	! 0xa802d078
a00c1490:  92 10 20 30  mov  0x30, %o1
a00c1494:  a2 10 20 35  mov  0x35, %l1
a00c1498:  98 10 20 36  mov  0x36, %o4
a00c149c:  9a 10 20 2b  mov  0x2b, %o5
a00c14a0:  96 10 20 0d  mov  0xd, %o3
a00c14a4:  e2 2b e0 78  stb  %l1, [ %o7 + 0x78 ]
a00c14a8:  d8 2a a0 01  stb  %o4, [ %o2 + 1 ]
a00c14ac:  d2 2a a0 03  stb  %o1, [ %o2 + 3 ]
a00c14b0:  da 2a a0 04  stb  %o5, [ %o2 + 4 ]
a00c14b4:  d6 2a a0 05  stb  %o3, [ %o2 + 5 ]
a00c14b8:  80 a4 20 02  cmp  %l0, 2
a00c14bc:  02 80 00 21  be  0xa00c1540
a00c14c0:  d2 2a a0 02  stb  %o1, [ %o2 + 2 ]
a00c14c4:  80 a4 20 03  cmp  %l0, 3
a00c14c8:  02 80 00 41  be  0xa00c15cc
a00c14cc:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c14d0:  96 13 60 d0  or  %o5, 0xd0, %o3	! 0xa802d0d0
a00c14d4:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00c14d8:  c0 2b 20 9c  clrb  [ %o4 + 0x9c ]	! 0xa802b09c
a00c14dc:  c0 2b 60 d0  clrb  [ %o5 + 0xd0 ]
a00c14e0:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00c14e4:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00c14e8:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00c14ec:  80 a4 20 02  cmp  %l0, 2
a00c14f0:  02 80 00 1d  be  0xa00c1564
a00c14f4:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00c14f8:  80 a4 20 03  cmp  %l0, 3
a00c14fc:  12 80 00 1d  bne  0xa00c1570
a00c1500:  90 10 00 10  mov  %l0, %o0
a00c1504:  10 80 00 3c  b  0xa00c15f4
a00c1508:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c150c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c1510:  a0 12 e1 28  or  %o3, 0x128, %l0	! 0xa802d128
a00c1514:  90 10 20 30  mov  0x30, %o0
a00c1518:  9a 10 20 35  mov  0x35, %o5
a00c151c:  94 10 20 0d  mov  0xd, %o2
a00c1520:  92 10 20 36  mov  0x36, %o1
a00c1524:  82 10 20 2b  mov  0x2b, %g1
a00c1528:  da 2a e1 28  stb  %o5, [ %o3 + 0x128 ]
a00c152c:  d4 2c 20 05  stb  %o2, [ %l0 + 5 ]
a00c1530:  d2 2c 20 01  stb  %o1, [ %l0 + 1 ]
a00c1534:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00c1538:  c2 2c 20 04  stb  %g1, [ %l0 + 4 ]
a00c153c:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00c1540:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c1544:  94 16 20 40  or  %i0, 0x40, %o2	! 0xa802d040
a00c1548:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00c154c:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00c1550:  c0 2e 20 40  clrb  [ %i0 + 0x40 ]
a00c1554:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c1558:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c155c:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c1560:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c1564:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c1568:  94 13 e1 28  or  %o7, 0x128, %o2	! 0xa802d128
a00c156c:  90 10 20 02  mov  2, %o0
a00c1570:  40 02 1c 9e  call  0xa01487e8
a00c1574:  92 10 20 06  mov  6, %o1
a00c1578:  10 80 00 22  b  0xa00c1600
a00c157c:  b0 10 20 00  clr  %i0
a00c1580:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c1584:  10 bf ff a7  b  0xa00c1420
a00c1588:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c158c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c1590:  10 bf ff a4  b  0xa00c1420
a00c1594:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c1598:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c159c:  98 12 21 08  or  %o0, 0x108, %o4	! 0xa802d108
a00c15a0:  9e 10 20 30  mov  0x30, %o7
a00c15a4:  82 10 20 35  mov  0x35, %g1
a00c15a8:  a0 10 20 0d  mov  0xd, %l0
a00c15ac:  b0 10 20 36  mov  0x36, %i0
a00c15b0:  a2 10 20 2b  mov  0x2b, %l1
a00c15b4:  c2 2a 21 08  stb  %g1, [ %o0 + 0x108 ]
a00c15b8:  e0 2b 20 05  stb  %l0, [ %o4 + 5 ]
a00c15bc:  f0 2b 20 01  stb  %i0, [ %o4 + 1 ]
a00c15c0:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a00c15c4:  e2 2b 20 04  stb  %l1, [ %o4 + 4 ]
a00c15c8:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a00c15cc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c15d0:  90 12 60 98  or  %o1, 0x98, %o0	! 0xa802d098
a00c15d4:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c15d8:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c15dc:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]
a00c15e0:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c15e4:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c15e8:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c15ec:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c15f0:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c15f4:  94 14 61 08  or  %l1, 0x108, %o2	! 0xa802d108
a00c15f8:  10 bf ff de  b  0xa00c1570
a00c15fc:  90 10 20 03  mov  3, %o0
a00c1600:  81 c7 e0 08  ret
a00c1604:  81 e8 00 00  restore
