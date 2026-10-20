# leon2s FUN_a00d12e4 0xa00d12e4-0xa00d17a8 (1220 bytes)
a00d12e4:  9d e3 bf 88  save  %sp, -120, %sp
a00d12e8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00d12ec:  c0 37 bf f0  clrh  [ %fp + -16 ]
a00d12f0:  c0 2f bf f2  clrb  [ %fp + -14 ]
a00d12f4:  c0 37 bf e8  clrh  [ %fp + -24 ]
a00d12f8:  80 a4 20 02  cmp  %l0, 2
a00d12fc:  02 80 00 06  be  0xa00d1314
a00d1300:  c0 2f bf ea  clrb  [ %fp + -22 ]
a00d1304:  40 3b 42 2a  call  0xa0fa1bac
a00d1308:  90 10 00 10  mov  %l0, %o0
a00d130c:  10 80 00 0b  b  0xa00d1338
a00d1310:  80 8a 20 ff  btst  0xff, %o0
a00d1314:  40 3b 1e e3  call  0xa0f98ea0
a00d1318:  90 10 20 00  clr  %o0
a00d131c:  80 8a 20 ff  btst  0xff, %o0
a00d1320:  22 80 00 3c  be,a   0xa00d1410
a00d1324:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00d1328:  40 3b 1f 00  call  0xa0f98f28
a00d132c:  90 10 20 00  clr  %o0
a00d1330:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d1334:  80 a2 20 01  cmp  %o0, 1
a00d1338:  32 80 00 36  bne,a   0xa00d1410
a00d133c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00d1340:  82 04 00 10  add  %l0, %l0, %g1
a00d1344:  82 00 40 10  add  %g1, %l0, %g1
a00d1348:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00d134c:  83 28 60 03  sll  %g1, 3, %g1
a00d1350:  9a 12 e3 b0  or  %o3, 0x3b0, %o5
a00d1354:  82 00 40 0d  add  %g1, %o5, %g1
a00d1358:  d8 08 60 02  ldub  [ %g1 + 2 ], %o4
a00d135c:  80 8b 20 10  btst  0x10, %o4
a00d1360:  22 80 00 19  be,a   0xa00d13c4
a00d1364:  82 04 00 10  add  %l0, %l0, %g1
a00d1368:  80 a3 20 11  cmp  %o4, 0x11
a00d136c:  08 80 01 0c  bleu  0xa00d179c
a00d1370:  80 a3 20 14  cmp  %o4, 0x14
a00d1374:  08 80 00 05  bleu  0xa00d1388
a00d1378:  80 a3 20 18  cmp  %o4, 0x18
a00d137c:  9a 07 80 10  add  %fp, %l0, %o5
a00d1380:  82 10 20 01  mov  1, %g1
a00d1384:  c2 2b 7f e8  stb  %g1, [ %o5 + -24 ]
a00d1388:  12 80 00 0f  bne  0xa00d13c4
a00d138c:  82 04 00 10  add  %l0, %l0, %g1
a00d1390:  82 07 bf f8  add  %fp, -8, %g1
a00d1394:  9a 00 40 10  add  %g1, %l0, %o5
a00d1398:  c2 0b 7f f0  ldub  [ %o5 + -16 ], %g1
a00d139c:  80 a0 60 01  cmp  %g1, 1
a00d13a0:  12 80 00 09  bne  0xa00d13c4
a00d13a4:  82 04 00 10  add  %l0, %l0, %g1
a00d13a8:  90 10 00 10  mov  %l0, %o0
a00d13ac:  7f ff ed ca  call  0xa00ccad4
a00d13b0:  c0 2b 7f f0  clrb  [ %o5 + -16 ]
a00d13b4:  90 10 00 10  mov  %l0, %o0
a00d13b8:  7f ff d9 a5  call  0xa00c7a4c
a00d13bc:  92 10 20 00  clr  %o1
a00d13c0:  30 80 00 f7  b,a   0xa00d179c
a00d13c4:  82 00 40 10  add  %g1, %l0, %g1
a00d13c8:  9a 12 e3 b0  or  %o3, 0x3b0, %o5
a00d13cc:  83 28 60 03  sll  %g1, 3, %g1
a00d13d0:  82 00 40 0d  add  %g1, %o5, %g1
a00d13d4:  da 08 60 02  ldub  [ %g1 + 2 ], %o5
a00d13d8:  80 8b 60 40  btst  0x40, %o5
a00d13dc:  22 80 00 0d  be,a   0xa00d1410
a00d13e0:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00d13e4:  80 a3 60 4e  cmp  %o5, 0x4e
a00d13e8:  08 80 00 ed  bleu  0xa00d179c
a00d13ec:  80 a3 60 4f  cmp  %o5, 0x4f
a00d13f0:  32 80 00 08  bne,a   0xa00d1410
a00d13f4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00d13f8:  7f ff ed b7  call  0xa00ccad4
a00d13fc:  90 10 00 10  mov  %l0, %o0
a00d1400:  90 10 00 10  mov  %l0, %o0
a00d1404:  7f ff d9 92  call  0xa00c7a4c
a00d1408:  92 10 20 00  clr  %o1
a00d140c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00d1410:  82 04 00 10  add  %l0, %l0, %g1
a00d1414:  82 00 40 10  add  %g1, %l0, %g1
a00d1418:  29 2a 01 e2  sethi  %hi(0xa8078800), %l4
a00d141c:  a3 28 60 03  sll  %g1, 3, %l1
a00d1420:  a4 15 23 b0  or  %l4, 0x3b0, %l2
a00d1424:  da 04 80 11  ld  [ %l2 + %l1 ], %o5
a00d1428:  80 a3 60 00  cmp  %o5, 0
a00d142c:  16 80 00 dc  bge  0xa00d179c
a00d1430:  80 a4 20 01  cmp  %l0, 1
a00d1434:  18 80 00 39  bgu  0xa00d1518
a00d1438:  82 0e 20 ff  and  %i0, 0xff, %g1
a00d143c:  83 33 60 1e  srl  %o5, 0x1e, %g1
a00d1440:  80 88 60 01  btst  1, %g1
a00d1444:  12 80 00 35  bne  0xa00d1518
a00d1448:  82 0e 20 ff  and  %i0, 0xff, %g1
a00d144c:  a6 04 40 12  add  %l1, %l2, %l3
a00d1450:  d8 0c e0 02  ldub  [ %l3 + 2 ], %o4
a00d1454:  80 a3 20 43  cmp  %o4, 0x43
a00d1458:  08 80 00 31  bleu  0xa00d151c
a00d145c:  80 a0 60 02  cmp  %g1, 2
a00d1460:  83 33 60 1c  srl  %o5, 0x1c, %g1
a00d1464:  80 88 60 01  btst  1, %g1
a00d1468:  02 80 00 20  be  0xa00d14e8
a00d146c:  80 a3 20 4f  cmp  %o4, 0x4f
a00d1470:  12 80 00 1e  bne  0xa00d14e8
a00d1474:  01 00 00 00  nop
a00d1478:  7f ff e9 b6  call  0xa00cbb50
a00d147c:  90 10 00 10  mov  %l0, %o0
a00d1480:  d8 04 80 11  ld  [ %l2 + %l1 ], %o4
a00d1484:  83 33 20 10  srl  %o4, 0x10, %g1
a00d1488:  82 08 60 03  and  %g1, 3, %g1
a00d148c:  9a 08 60 ff  and  %g1, 0xff, %o5
a00d1490:  80 a3 60 03  cmp  %o5, 3
a00d1494:  12 80 00 08  bne  0xa00d14b4
a00d1498:  80 a3 60 01  cmp  %o5, 1
a00d149c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00d14a0:  82 2b 00 01  andn  %o4, %g1, %g1
a00d14a4:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00d14a8:  82 10 40 0d  or  %g1, %o5, %g1
a00d14ac:  10 80 00 0b  b  0xa00d14d8
a00d14b0:  c2 24 80 11  st  %g1, [ %l2 + %l1 ]
a00d14b4:  12 80 00 05  bne  0xa00d14c8
a00d14b8:  80 a0 60 00  cmp  %g1, 0
a00d14bc:  82 10 20 4a  mov  0x4a, %g1
a00d14c0:  10 80 00 06  b  0xa00d14d8
a00d14c4:  c2 2c e0 02  stb  %g1, [ %l3 + 2 ]
a00d14c8:  12 80 00 04  bne  0xa00d14d8
a00d14cc:  90 10 00 10  mov  %l0, %o0
a00d14d0:  7f ff d9 5f  call  0xa00c7a4c
a00d14d4:  92 10 20 00  clr  %o1
a00d14d8:  7f ff fe 28  call  0xa00d0d78
a00d14dc:  90 10 00 10  mov  %l0, %o0
a00d14e0:  10 80 00 0e  b  0xa00d1518
a00d14e4:  82 0e 20 ff  and  %i0, 0xff, %g1
a00d14e8:  7f ff ed 44  call  0xa00cc9f8
a00d14ec:  90 10 00 10  mov  %l0, %o0
a00d14f0:  80 8a 20 ff  btst  0xff, %o0
a00d14f4:  02 80 00 09  be  0xa00d1518
a00d14f8:  82 0e 20 ff  and  %i0, 0xff, %g1
a00d14fc:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00d1500:  40 3a c6 d1  call  0xa0f83044
a00d1504:  90 12 21 a8  or  %o0, 0x1a8, %o0	! 0x9f1c21a8
a00d1508:  90 10 00 10  mov  %l0, %o0
a00d150c:  7f ff d9 50  call  0xa00c7a4c
a00d1510:  92 10 20 00  clr  %o1
a00d1514:  82 0e 20 ff  and  %i0, 0xff, %g1
a00d1518:  80 a0 60 02  cmp  %g1, 2
a00d151c:  12 80 00 3e  bne  0xa00d1614
a00d1520:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00d1524:  40 3b 08 7b  call  0xa0f93710
a00d1528:  90 10 20 00  clr  %o0
a00d152c:  80 8a 20 04  btst  4, %o0
a00d1530:  02 80 00 39  be  0xa00d1614
a00d1534:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00d1538:  a0 15 23 b0  or  %l4, 0x3b0, %l0
a00d153c:  da 04 20 30  ld  [ %l0 + 0x30 ], %o5
a00d1540:  83 33 60 1e  srl  %o5, 0x1e, %g1
a00d1544:  80 88 60 01  btst  1, %g1
a00d1548:  02 80 00 07  be  0xa00d1564
a00d154c:  83 33 60 1c  srl  %o5, 0x1c, %g1
a00d1550:  c2 0c 20 32  ldub  [ %l0 + 0x32 ], %g1
a00d1554:  80 a0 60 4a  cmp  %g1, 0x4a
a00d1558:  28 80 00 2f  bleu,a   0xa00d1614
a00d155c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00d1560:  83 33 60 1c  srl  %o5, 0x1c, %g1
a00d1564:  80 88 60 01  btst  1, %g1
a00d1568:  02 80 00 22  be  0xa00d15f0
a00d156c:  a2 04 20 30  add  %l0, 0x30, %l1
a00d1570:  c2 0c 60 02  ldub  [ %l1 + 2 ], %g1
a00d1574:  80 a0 60 4a  cmp  %g1, 0x4a
a00d1578:  08 80 00 1e  bleu  0xa00d15f0
a00d157c:  01 00 00 00  nop
a00d1580:  7f ff f6 7b  call  0xa00cef6c
a00d1584:  90 10 20 02  mov  2, %o0	! 0x2
a00d1588:  d8 04 20 30  ld  [ %l0 + 0x30 ], %o4
a00d158c:  83 33 20 10  srl  %o4, 0x10, %g1
a00d1590:  82 08 60 03  and  %g1, 3, %g1
a00d1594:  9a 08 60 ff  and  %g1, 0xff, %o5
a00d1598:  80 a3 60 03  cmp  %o5, 3
a00d159c:  12 80 00 08  bne  0xa00d15bc
a00d15a0:  80 a3 60 01  cmp  %o5, 1
a00d15a4:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00d15a8:  82 2b 00 01  andn  %o4, %g1, %g1
a00d15ac:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00d15b0:  82 10 40 0d  or  %g1, %o5, %g1
a00d15b4:  10 80 00 0b  b  0xa00d15e0
a00d15b8:  c2 24 20 30  st  %g1, [ %l0 + 0x30 ]
a00d15bc:  12 80 00 05  bne  0xa00d15d0
a00d15c0:  80 a0 60 00  cmp  %g1, 0
a00d15c4:  82 10 20 4a  mov  0x4a, %g1
a00d15c8:  10 80 00 06  b  0xa00d15e0
a00d15cc:  c2 2c 60 02  stb  %g1, [ %l1 + 2 ]
a00d15d0:  12 80 00 04  bne  0xa00d15e0
a00d15d4:  90 10 20 02  mov  2, %o0
a00d15d8:  7f ff d9 1d  call  0xa00c7a4c
a00d15dc:  92 10 20 00  clr  %o1
a00d15e0:  7f ff fd e6  call  0xa00d0d78
a00d15e4:  90 10 20 02  mov  2, %o0
a00d15e8:  10 80 00 0b  b  0xa00d1614
a00d15ec:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00d15f0:  7f ff f8 fe  call  0xa00cf9e8
a00d15f4:  90 10 20 00  clr  %o0
a00d15f8:  80 8a 20 ff  btst  0xff, %o0
a00d15fc:  02 80 00 06  be  0xa00d1614
a00d1600:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00d1604:  90 10 20 02  mov  2, %o0
a00d1608:  7f ff d9 11  call  0xa00c7a4c
a00d160c:  92 10 20 00  clr  %o1
a00d1610:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00d1614:  82 04 00 10  add  %l0, %l0, %g1
a00d1618:  82 00 40 10  add  %g1, %l0, %g1
a00d161c:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a00d1620:  9a 14 e3 b0  or  %l3, 0x3b0, %o5	! 0xa8078bb0
a00d1624:  83 28 60 03  sll  %g1, 3, %g1
a00d1628:  82 00 40 0d  add  %g1, %o5, %g1
a00d162c:  9a 07 bf f8  add  %fp, -8, %o5
a00d1630:  96 03 40 10  add  %o5, %l0, %o3
a00d1634:  d8 08 60 02  ldub  [ %g1 + 2 ], %o4
a00d1638:  da 0a ff f8  ldub  [ %o3 + -8 ], %o5
a00d163c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00d1640:  80 a3 40 01  cmp  %o5, %g1
a00d1644:  32 80 00 02  bne,a   0xa00d164c
a00d1648:  d8 2a ff f8  stb  %o4, [ %o3 + -8 ]
a00d164c:  80 a4 20 02  cmp  %l0, 2
a00d1650:  12 80 00 0b  bne  0xa00d167c
a00d1654:  80 a4 20 01  cmp  %l0, 1
a00d1658:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d165c:  c2 08 60 5a  ldub  [ %g1 + 0x5a ], %g1	! 0xa8078c5a
a00d1660:  80 a0 60 00  cmp  %g1, 0
a00d1664:  22 80 00 0b  be,a   0xa00d1690
a00d1668:  82 04 00 10  add  %l0, %l0, %g1
a00d166c:  7f ff fc bf  call  0xa00d0968
a00d1670:  90 10 20 02  mov  2, %o0
a00d1674:  10 80 00 07  b  0xa00d1690
a00d1678:  82 04 00 10  add  %l0, %l0, %g1
a00d167c:  18 80 00 05  bgu  0xa00d1690
a00d1680:  82 04 00 10  add  %l0, %l0, %g1
a00d1684:  7f ff fb 47  call  0xa00d03a0
a00d1688:  90 10 00 10  mov  %l0, %o0
a00d168c:  82 04 00 10  add  %l0, %l0, %g1
a00d1690:  82 00 40 10  add  %g1, %l0, %g1
a00d1694:  a3 28 60 03  sll  %g1, 3, %l1
a00d1698:  a4 14 e3 b0  or  %l3, 0x3b0, %l2
a00d169c:  da 04 80 11  ld  [ %l2 + %l1 ], %o5
a00d16a0:  83 33 60 1e  srl  %o5, 0x1e, %g1
a00d16a4:  80 88 60 01  btst  1, %g1
a00d16a8:  22 80 00 28  be,a   0xa00d1748
a00d16ac:  90 0e 20 ff  and  %i0, 0xff, %o0
a00d16b0:  83 33 60 10  srl  %o5, 0x10, %g1
a00d16b4:  82 08 60 03  and  %g1, 3, %g1
a00d16b8:  80 a0 60 03  cmp  %g1, 3
a00d16bc:  32 80 00 08  bne,a   0xa00d16dc
a00d16c0:  c2 0c 80 11  ldub  [ %l2 + %l1 ], %g1
a00d16c4:  7f ff f9 17  call  0xa00cfb20
a00d16c8:  90 04 20 0b  add  %l0, 0xb, %o0
a00d16cc:  80 a2 20 00  cmp  %o0, 0
a00d16d0:  02 80 00 07  be  0xa00d16ec
a00d16d4:  82 04 00 10  add  %l0, %l0, %g1
a00d16d8:  c2 0c 80 11  ldub  [ %l2 + %l1 ], %g1
a00d16dc:  80 88 60 0f  btst  0xf, %g1
a00d16e0:  12 80 00 1a  bne  0xa00d1748
a00d16e4:  90 0e 20 ff  and  %i0, 0xff, %o0
a00d16e8:  82 04 00 10  add  %l0, %l0, %g1
a00d16ec:  82 00 40 10  add  %g1, %l0, %g1
a00d16f0:  91 28 60 03  sll  %g1, 3, %o0
a00d16f4:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00d16f8:  98 14 e3 b0  or  %l3, 0x3b0, %o4
a00d16fc:  94 10 63 ff  or  %g1, 0x3ff, %o2
a00d1700:  c2 03 00 08  ld  [ %o4 + %o0 ], %g1
a00d1704:  96 08 40 0a  and  %g1, %o2, %o3
a00d1708:  d6 23 00 08  st  %o3, [ %o4 + %o0 ]
a00d170c:  9a 02 00 0c  add  %o0, %o4, %o5
a00d1710:  c2 0b 60 02  ldub  [ %o5 + 2 ], %g1
a00d1714:  80 a0 60 4d  cmp  %g1, 0x4d
a00d1718:  32 80 00 0c  bne,a   0xa00d1748
a00d171c:  90 0e 20 ff  and  %i0, 0xff, %o0
a00d1720:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a00d1724:  da 03 60 10  ld  [ %o5 + 0x10 ], %o5
a00d1728:  82 10 63 ff  or  %g1, 0x3ff, %g1
a00d172c:  80 a3 40 01  cmp  %o5, %g1
a00d1730:  02 80 00 05  be  0xa00d1744
a00d1734:  82 0a c0 0a  and  %o3, %o2, %g1
a00d1738:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00d173c:  82 10 40 0d  or  %g1, %o5, %g1
a00d1740:  c2 23 00 08  st  %g1, [ %o4 + %o0 ]
a00d1744:  90 0e 20 ff  and  %i0, 0xff, %o0
a00d1748:  82 02 00 08  add  %o0, %o0, %g1
a00d174c:  82 00 40 08  add  %g1, %o0, %g1
a00d1750:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00d1754:  99 28 60 03  sll  %g1, 3, %o4
a00d1758:  96 13 63 b0  or  %o5, 0x3b0, %o3
a00d175c:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00d1760:  83 33 60 1e  srl  %o5, 0x1e, %g1
a00d1764:  80 88 60 01  btst  1, %g1
a00d1768:  12 80 00 0b  bne  0xa00d1794
a00d176c:  83 33 60 18  srl  %o5, 0x18, %g1
a00d1770:  80 88 60 0f  btst  0xf, %g1
a00d1774:  12 80 00 08  bne  0xa00d1794
a00d1778:  03 03 c0 00  sethi  %hi(0xf000000), %g1
a00d177c:  82 2b 40 01  andn  %o5, %g1, %g1
a00d1780:  1b 02 80 00  sethi  %hi(0xa000000), %o5
a00d1784:  82 10 40 0d  or  %g1, %o5, %g1
a00d1788:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00d178c:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d1790:  da 22 c0 0c  st  %o5, [ %o3 + %o4 ]
a00d1794:  7f ff fd 79  call  0xa00d0d78
a00d1798:  01 00 00 00  nop
a00d179c:  01 00 00 00  nop
a00d17a0:  81 c7 e0 08  ret
a00d17a4:  81 e8 00 00  restore
