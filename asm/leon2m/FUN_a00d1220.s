# leon2m FUN_a00d1220 0xa00d1220-0xa00d1a34 (1836 bytes)
a00d1220:  9d e3 bf 98  save  %sp, -104, %sp
a00d1224:  82 0e a0 ff  and  %i2, 0xff, %g1
a00d1228:  80 a0 60 99  cmp  %g1, 0x99
a00d122c:  02 80 00 40  be  0xa00d132c
a00d1230:  80 a0 60 98  cmp  %g1, 0x98
a00d1234:  02 80 01 fe  be  0xa00d1a2c
a00d1238:  80 a0 60 97  cmp  %g1, 0x97
a00d123c:  02 80 00 4f  be  0xa00d1378
a00d1240:  80 a0 60 96  cmp  %g1, 0x96
a00d1244:  02 80 00 74  be  0xa00d1414
a00d1248:  80 a0 60 93  cmp  %g1, 0x93
a00d124c:  02 80 00 5d  be  0xa00d13c0
a00d1250:  80 a0 60 92  cmp  %g1, 0x92
a00d1254:  02 80 00 8d  be  0xa00d1488
a00d1258:  80 a0 60 69  cmp  %g1, 0x69
a00d125c:  02 80 01 07  be  0xa00d1678
a00d1260:  80 a0 60 6e  cmp  %g1, 0x6e
a00d1264:  02 80 01 1d  be  0xa00d16d8
a00d1268:  90 10 20 01  mov  1, %o0
a00d126c:  80 a0 60 6f  cmp  %g1, 0x6f
a00d1270:  02 80 01 19  be  0xa00d16d4
a00d1274:  80 a0 60 6a  cmp  %g1, 0x6a
a00d1278:  02 80 00 a4  be  0xa00d1508
a00d127c:  80 a0 60 6b  cmp  %g1, 0x6b
a00d1280:  02 80 01 1f  be  0xa00d16fc
a00d1284:  80 a0 60 1f  cmp  %g1, 0x1f
a00d1288:  02 80 01 42  be  0xa00d1790
a00d128c:  80 a0 60 02  cmp  %g1, 2
a00d1290:  02 80 01 4f  be  0xa00d17cc
a00d1294:  80 a0 60 08  cmp  %g1, 8
a00d1298:  02 80 01 61  be  0xa00d181c
a00d129c:  80 a0 60 aa  cmp  %g1, 0xaa
a00d12a0:  02 80 01 71  be  0xa00d1864
a00d12a4:  80 a0 60 c2  cmp  %g1, 0xc2
a00d12a8:  02 80 01 87  be  0xa00d18c4
a00d12ac:  80 a0 60 d0  cmp  %g1, 0xd0
a00d12b0:  02 80 01 95  be  0xa00d1904
a00d12b4:  80 a0 60 0a  cmp  %g1, 0xa
a00d12b8:  02 80 01 ac  be  0xa00d1968
a00d12bc:  80 a0 60 e0  cmp  %g1, 0xe0
a00d12c0:  22 80 00 0b  be,a   0xa00d12ec
a00d12c4:  82 10 3f e0  mov  -32, %g1
a00d12c8:  14 80 01 9d  bg  0xa00d193c
a00d12cc:  80 a0 60 e2  cmp  %g1, 0xe2
a00d12d0:  80 a0 60 02  cmp  %g1, 2
a00d12d4:  24 80 00 07  ble,a   0xa00d12f0
a00d12d8:  f4 2e 60 07  stb  %i2, [ %i1 + 7 ]
a00d12dc:  80 a0 60 88  cmp  %g1, 0x88
a00d12e0:  02 80 00 03  be  0xa00d12ec
a00d12e4:  82 10 20 02  mov  2, %g1
a00d12e8:  82 10 3f e2  mov  -30, %g1
a00d12ec:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00d12f0:  d0 0e 60 01  ldub  [ %i1 + 1 ], %o0
a00d12f4:  96 0a 20 7f  and  %o0, 0x7f, %o3
a00d12f8:  94 82 e0 02  addcc  %o3, 2, %o2
a00d12fc:  96 10 20 50  mov  0x50, %o3
a00d1300:  02 80 00 09  be  0xa00d1324
a00d1304:  98 10 20 00  clr  %o4
a00d1308:  9a 10 20 00  clr  %o5
a00d130c:  c2 0b 40 19  ldub  [ %o5 + %i1 ], %g1
a00d1310:  98 03 20 01  inc  %o4
a00d1314:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d1318:  80 a3 40 0a  cmp  %o5, %o2
a00d131c:  0a bf ff fc  bcs  0xa00d130c
a00d1320:  96 1a c0 01  xor  %o3, %g1, %o3
a00d1324:  10 80 01 c2  b  0xa00d1a2c
a00d1328:  d6 2e 60 08  stb  %o3, [ %i1 + 8 ]
a00d132c:  c2 0e 20 06  ldub  [ %i0 + 6 ], %g1
a00d1330:  80 a0 60 40  cmp  %g1, 0x40
a00d1334:  22 80 00 47  be,a   0xa00d1450
a00d1338:  d2 0e 60 01  ldub  [ %i1 + 1 ], %o1
a00d133c:  d4 0e 60 01  ldub  [ %i1 + 1 ], %o2
a00d1340:  96 0a a0 7f  and  %o2, 0x7f, %o3
a00d1344:  94 82 e0 02  addcc  %o3, 2, %o2
a00d1348:  96 10 20 50  mov  0x50, %o3
a00d134c:  02 80 00 09  be  0xa00d1370
a00d1350:  98 10 20 00  clr  %o4
a00d1354:  9a 10 20 00  clr  %o5
a00d1358:  f0 0b 40 19  ldub  [ %o5 + %i1 ], %i0
a00d135c:  98 03 20 01  inc  %o4
a00d1360:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d1364:  80 a3 40 0a  cmp  %o5, %o2
a00d1368:  0a bf ff fc  bcs  0xa00d1358
a00d136c:  96 1a c0 18  xor  %o3, %i0, %o3
a00d1370:  10 80 01 af  b  0xa00d1a2c
a00d1374:  d6 2e 60 17  stb  %o3, [ %i1 + 0x17 ]
a00d1378:  9a 10 20 02  mov  2, %o5
a00d137c:  98 10 20 01  mov  1, %o4
a00d1380:  b4 10 3f 88  mov  -120, %i2
a00d1384:  da 2e 60 08  stb  %o5, [ %i1 + 8 ]
a00d1388:  d8 2e 60 09  stb  %o4, [ %i1 + 9 ]
a00d138c:  f4 2e 60 01  stb  %i2, [ %i1 + 1 ]
a00d1390:  c0 2e 60 07  clrb  [ %i1 + 7 ]
a00d1394:  96 10 20 50  mov  0x50, %o3
a00d1398:  98 10 20 00  clr  %o4
a00d139c:  9a 10 20 00  clr  %o5
a00d13a0:  c2 0b 40 19  ldub  [ %o5 + %i1 ], %g1
a00d13a4:  98 03 20 01  inc  %o4
a00d13a8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d13ac:  80 a3 60 0a  cmp  %o5, 0xa
a00d13b0:  0a bf ff fc  bcs  0xa00d13a0
a00d13b4:  96 1a c0 01  xor  %o3, %g1, %o3
a00d13b8:  10 80 01 9d  b  0xa00d1a2c
a00d13bc:  d6 2e 60 0a  stb  %o3, [ %i1 + 0xa ]
a00d13c0:  96 10 3f e0  mov  -32, %o3
a00d13c4:  94 10 3f 8c  mov  -116, %o2
a00d13c8:  d6 2e 60 07  stb  %o3, [ %i1 + 7 ]
a00d13cc:  d4 2e 60 01  stb  %o2, [ %i1 + 1 ]
a00d13d0:  c0 2e 60 08  clrb  [ %i1 + 8 ]
a00d13d4:  c0 2e 60 09  clrb  [ %i1 + 9 ]
a00d13d8:  c0 2e 60 0a  clrb  [ %i1 + 0xa ]
a00d13dc:  c0 2e 60 0b  clrb  [ %i1 + 0xb ]
a00d13e0:  c0 2e 60 0c  clrb  [ %i1 + 0xc ]
a00d13e4:  c0 2e 60 0d  clrb  [ %i1 + 0xd ]
a00d13e8:  96 10 20 50  mov  0x50, %o3
a00d13ec:  98 10 20 00  clr  %o4
a00d13f0:  9a 10 20 00  clr  %o5
a00d13f4:  f0 0b 40 19  ldub  [ %o5 + %i1 ], %i0
a00d13f8:  98 03 20 01  inc  %o4
a00d13fc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d1400:  80 a3 60 0e  cmp  %o5, 0xe
a00d1404:  0a bf ff fc  bcs  0xa00d13f4
a00d1408:  96 1a c0 18  xor  %o3, %i0, %o3
a00d140c:  10 80 01 88  b  0xa00d1a2c
a00d1410:  d6 2e 60 0e  stb  %o3, [ %i1 + 0xe ]
a00d1414:  d2 0e 60 01  ldub  [ %i1 + 1 ], %o1
a00d1418:  90 0a 60 7f  and  %o1, 0x7f, %o0
a00d141c:  94 82 20 02  addcc  %o0, 2, %o2
a00d1420:  96 10 20 50  mov  0x50, %o3
a00d1424:  02 bf ff c0  be  0xa00d1324
a00d1428:  98 10 20 00  clr  %o4
a00d142c:  9a 10 20 00  clr  %o5
a00d1430:  de 0b 40 19  ldub  [ %o5 + %i1 ], %o7
a00d1434:  98 03 20 01  inc  %o4
a00d1438:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d143c:  80 a3 40 0a  cmp  %o5, %o2
a00d1440:  0a bf ff fc  bcs  0xa00d1430
a00d1444:  96 1a c0 0f  xor  %o3, %o7, %o3
a00d1448:  10 80 01 79  b  0xa00d1a2c
a00d144c:  d6 2e 60 08  stb  %o3, [ %i1 + 8 ]
a00d1450:  90 0a 60 7f  and  %o1, 0x7f, %o0
a00d1454:  94 82 20 02  addcc  %o0, 2, %o2
a00d1458:  96 10 20 50  mov  0x50, %o3
a00d145c:  02 80 00 09  be  0xa00d1480
a00d1460:  98 10 20 00  clr  %o4
a00d1464:  9a 10 20 00  clr  %o5
a00d1468:  de 0b 40 19  ldub  [ %o5 + %i1 ], %o7
a00d146c:  98 03 20 01  inc  %o4
a00d1470:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d1474:  80 a3 40 0a  cmp  %o5, %o2
a00d1478:  0a bf ff fc  bcs  0xa00d1468
a00d147c:  96 1a c0 0f  xor  %o3, %o7, %o3
a00d1480:  10 80 01 6b  b  0xa00d1a2c
a00d1484:  d6 2e 60 47  stb  %o3, [ %i1 + 0x47 ]
a00d1488:  b4 10 3f 89  mov  -119, %i2
a00d148c:  9a 10 3f e0  mov  -32, %o5
a00d1490:  f4 2e 60 01  stb  %i2, [ %i1 + 1 ]
a00d1494:  da 2e 60 07  stb  %o5, [ %i1 + 7 ]
a00d1498:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00d149c:  c2 0b 22 a1  ldub  [ %o4 + 0x2a1 ], %g1	! 0xa802d2a1
a00d14a0:  80 a0 60 02  cmp  %g1, 2
a00d14a4:  02 80 00 26  be  0xa00d153c
a00d14a8:  80 a0 60 01  cmp  %g1, 1
a00d14ac:  02 80 00 b1  be  0xa00d1770
a00d14b0:  80 a0 60 00  cmp  %g1, 0
a00d14b4:  12 80 00 0b  bne  0xa00d14e0
a00d14b8:  96 10 20 50  mov  0x50, %o3
a00d14bc:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a00d14c0:  b4 10 61 f0  or  %g1, 0x1f0, %i2	! 0xa802e1f0
a00d14c4:  d0 0e a0 12  ldub  [ %i2 + 0x12 ], %o0
a00d14c8:  d0 2e 60 08  stb  %o0, [ %i1 + 8 ]
a00d14cc:  da 0e a0 13  ldub  [ %i2 + 0x13 ], %o5
a00d14d0:  da 2e 60 09  stb  %o5, [ %i1 + 9 ]
a00d14d4:  da 0e a0 14  ldub  [ %i2 + 0x14 ], %o5
a00d14d8:  da 2e 60 0a  stb  %o5, [ %i1 + 0xa ]
a00d14dc:  96 10 20 50  mov  0x50, %o3
a00d14e0:  98 10 20 00  clr  %o4
a00d14e4:  9a 10 20 00  clr  %o5
a00d14e8:  d2 0b 40 19  ldub  [ %o5 + %i1 ], %o1
a00d14ec:  98 03 20 01  inc  %o4
a00d14f0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d14f4:  80 a3 60 0b  cmp  %o5, 0xb
a00d14f8:  0a bf ff fc  bcs  0xa00d14e8
a00d14fc:  96 1a c0 09  xor  %o3, %o1, %o3
a00d1500:  10 80 01 4b  b  0xa00d1a2c
a00d1504:  d6 2e 60 0b  stb  %o3, [ %i1 + 0xb ]
a00d1508:  96 10 3f e0  mov  -32, %o3
a00d150c:  d6 2e 60 08  stb  %o3, [ %i1 + 8 ]
a00d1510:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00d1514:  c2 0b e2 98  ldub  [ %o7 + 0x298 ], %g1	! 0xa802d298
a00d1518:  80 a0 60 1c  cmp  %g1, 0x1c
a00d151c:  18 80 00 aa  bgu  0xa00d17c4
a00d1520:  90 10 3f e4  mov  -28, %o0
a00d1524:  35 00 01 bb  sethi  %hi(0x6ec00), %i2
a00d1528:  b1 28 60 02  sll  %g1, 2, %i0
a00d152c:  98 16 a0 3c  or  %i2, 0x3c, %o4
a00d1530:  d4 03 00 18  ld  [ %o4 + %i0 ], %o2
a00d1534:  81 c2 80 00  jmp  %o2
a00d1538:  01 00 00 00  nop
a00d153c:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a00d1540:  82 13 e1 f0  or  %o7, 0x1f0, %g1	! 0xa802e1f0
a00d1544:  d2 08 60 06  ldub  [ %g1 + 6 ], %o1
a00d1548:  d2 2e 60 08  stb  %o1, [ %i1 + 8 ]
a00d154c:  d0 08 60 07  ldub  [ %g1 + 7 ], %o0
a00d1550:  d0 2e 60 09  stb  %o0, [ %i1 + 9 ]
a00d1554:  10 bf ff e1  b  0xa00d14d8
a00d1558:  da 08 60 08  ldub  [ %g1 + 8 ], %o5
a00d155c:  82 10 20 1f  mov  0x1f, %g1
a00d1560:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00d1564:  9a 10 3f 87  mov  -121, %o5
a00d1568:  da 2e 60 01  stb  %o5, [ %i1 + 1 ]
a00d156c:  96 10 20 50  mov  0x50, %o3
a00d1570:  98 10 20 00  clr  %o4
a00d1574:  9a 10 20 00  clr  %o5
a00d1578:  c2 0b 40 19  ldub  [ %o5 + %i1 ], %g1
a00d157c:  98 03 20 01  inc  %o4
a00d1580:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d1584:  80 a3 60 09  cmp  %o5, 9
a00d1588:  0a bf ff fc  bcs  0xa00d1578
a00d158c:  96 1a c0 01  xor  %o3, %g1, %o3
a00d1590:  10 80 01 27  b  0xa00d1a2c
a00d1594:  d6 2e 60 09  stb  %o3, [ %i1 + 9 ]
a00d1598:  10 bf ff f2  b  0xa00d1560
a00d159c:  82 10 20 1e  mov  0x1e, %g1
a00d15a0:  10 bf ff f0  b  0xa00d1560
a00d15a4:  82 10 20 1d  mov  0x1d, %g1
a00d15a8:  10 bf ff ee  b  0xa00d1560
a00d15ac:  82 10 20 05  mov  5, %g1
a00d15b0:  10 bf ff ec  b  0xa00d1560
a00d15b4:  82 10 20 08  mov  8, %g1
a00d15b8:  10 bf ff ea  b  0xa00d1560
a00d15bc:  82 10 20 1c  mov  0x1c, %g1
a00d15c0:  10 bf ff e8  b  0xa00d1560
a00d15c4:  82 10 20 06  mov  6, %g1
a00d15c8:  10 bf ff e6  b  0xa00d1560
a00d15cc:  82 10 20 1b  mov  0x1b, %g1
a00d15d0:  10 bf ff e4  b  0xa00d1560
a00d15d4:  82 10 20 1a  mov  0x1a, %g1
a00d15d8:  10 bf ff e2  b  0xa00d1560
a00d15dc:  82 10 20 19  mov  0x19, %g1
a00d15e0:  10 bf ff e0  b  0xa00d1560
a00d15e4:  82 10 20 18  mov  0x18, %g1
a00d15e8:  10 bf ff de  b  0xa00d1560
a00d15ec:  82 10 20 17  mov  0x17, %g1
a00d15f0:  10 bf ff dc  b  0xa00d1560
a00d15f4:  82 10 20 16  mov  0x16, %g1
a00d15f8:  10 bf ff da  b  0xa00d1560
a00d15fc:  82 10 20 15  mov  0x15, %g1
a00d1600:  10 bf ff d8  b  0xa00d1560
a00d1604:  82 10 20 14  mov  0x14, %g1
a00d1608:  10 bf ff d6  b  0xa00d1560
a00d160c:  82 10 20 10  mov  0x10, %g1
a00d1610:  10 bf ff d4  b  0xa00d1560
a00d1614:  82 10 20 13  mov  0x13, %g1
a00d1618:  10 bf ff d2  b  0xa00d1560
a00d161c:  82 10 20 12  mov  0x12, %g1
a00d1620:  10 bf ff d0  b  0xa00d1560
a00d1624:  82 10 20 11  mov  0x11, %g1
a00d1628:  10 bf ff ce  b  0xa00d1560
a00d162c:  82 10 20 07  mov  7, %g1
a00d1630:  10 bf ff cc  b  0xa00d1560
a00d1634:  82 10 20 09  mov  9, %g1
a00d1638:  10 bf ff ca  b  0xa00d1560
a00d163c:  82 10 20 0d  mov  0xd, %g1
a00d1640:  10 bf ff c8  b  0xa00d1560
a00d1644:  82 10 20 0e  mov  0xe, %g1
a00d1648:  10 bf ff c6  b  0xa00d1560
a00d164c:  82 10 20 03  mov  3, %g1
a00d1650:  10 bf ff c4  b  0xa00d1560
a00d1654:  82 10 20 04  mov  4, %g1
a00d1658:  10 bf ff c2  b  0xa00d1560
a00d165c:  82 10 20 01  mov  1, %g1
a00d1660:  10 bf ff c0  b  0xa00d1560
a00d1664:  82 10 20 02  mov  2, %g1
a00d1668:  10 bf ff bf  b  0xa00d1564
a00d166c:  c0 2e 60 07  clrb  [ %i1 + 7 ]
a00d1670:  10 bf ff bc  b  0xa00d1560
a00d1674:  82 10 20 0c  mov  0xc, %g1
a00d1678:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00d167c:  98 13 62 74  or  %o5, 0x274, %o4	! 0xa802d274
a00d1680:  d0 0b 20 10  ldub  [ %o4 + 0x10 ], %o0
a00d1684:  b4 0a 20 01  and  %o0, 1, %i2
a00d1688:  f4 2e 60 06  stb  %i2, [ %i1 + 6 ]
a00d168c:  f0 0b 20 10  ldub  [ %o4 + 0x10 ], %i0
a00d1690:  d4 0e 60 01  ldub  [ %i1 + 1 ], %o2
a00d1694:  96 0e 20 3e  and  %i0, 0x3e, %o3
a00d1698:  9e 0a a0 7f  and  %o2, 0x7f, %o7
a00d169c:  d6 2e 60 07  stb  %o3, [ %i1 + 7 ]
a00d16a0:  94 83 e0 02  addcc  %o7, 2, %o2
a00d16a4:  96 10 20 50  mov  0x50, %o3
a00d16a8:  02 bf ff 1f  be  0xa00d1324
a00d16ac:  98 10 20 00  clr  %o4
a00d16b0:  9a 10 20 00  clr  %o5
a00d16b4:  c2 0b 40 19  ldub  [ %o5 + %i1 ], %g1
a00d16b8:  98 03 20 01  inc  %o4
a00d16bc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d16c0:  80 a3 40 0a  cmp  %o5, %o2
a00d16c4:  0a bf ff fc  bcs  0xa00d16b4
a00d16c8:  96 1a c0 01  xor  %o3, %g1, %o3
a00d16cc:  10 80 00 d8  b  0xa00d1a2c
a00d16d0:  d6 2e 60 08  stb  %o3, [ %i1 + 8 ]
a00d16d4:  90 10 20 02  mov  2, %o0
a00d16d8:  40 01 9b 91  call  0xa013851c
a00d16dc:  01 00 00 00  nop
a00d16e0:  92 0a 20 ff  and  %o0, 0xff, %o1
a00d16e4:  80 a2 60 01  cmp  %o1, 1
a00d16e8:  02 80 00 03  be  0xa00d16f4
a00d16ec:  82 10 3f e0  mov  -32, %g1
a00d16f0:  82 10 3f e1  mov  -31, %g1
a00d16f4:  10 80 00 ce  b  0xa00d1a2c
a00d16f8:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00d16fc:  96 10 3f 93  mov  -109, %o3
a00d1700:  d6 2e 60 01  stb  %o3, [ %i1 + 1 ]
a00d1704:  9e 10 3f e0  mov  -32, %o7
a00d1708:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d170c:  de 2e 60 07  stb  %o7, [ %i1 + 7 ]
a00d1710:  94 12 62 74  or  %o1, 0x274, %o2
a00d1714:  96 10 20 00  clr  %o3
a00d1718:  b0 06 40 0b  add  %i1, %o3, %i0
a00d171c:  b4 02 c0 0a  add  %o3, %o2, %i2
a00d1720:  d8 0e a0 03  ldub  [ %i2 + 3 ], %o4
a00d1724:  96 02 e0 01  inc  %o3
a00d1728:  80 a2 e0 0c  cmp  %o3, 0xc
a00d172c:  04 bf ff fb  ble  0xa00d1718
a00d1730:  d8 2e 20 08  stb  %o4, [ %i0 + 8 ]
a00d1734:  d4 0e 60 01  ldub  [ %i1 + 1 ], %o2
a00d1738:  90 0a a0 7f  and  %o2, 0x7f, %o0
a00d173c:  94 82 20 02  addcc  %o0, 2, %o2
a00d1740:  96 10 20 50  mov  0x50, %o3
a00d1744:  02 80 00 09  be  0xa00d1768
a00d1748:  98 10 20 00  clr  %o4
a00d174c:  9a 10 20 00  clr  %o5
a00d1750:  c2 0b 40 19  ldub  [ %o5 + %i1 ], %g1
a00d1754:  98 03 20 01  inc  %o4
a00d1758:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d175c:  80 a3 40 0a  cmp  %o5, %o2
a00d1760:  0a bf ff fc  bcs  0xa00d1750
a00d1764:  96 1a c0 01  xor  %o3, %g1, %o3
a00d1768:  10 80 00 b1  b  0xa00d1a2c
a00d176c:  d6 2e 60 15  stb  %o3, [ %i1 + 0x15 ]
a00d1770:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a00d1774:  96 13 21 f0  or  %o4, 0x1f0, %o3	! 0xa802e1f0
a00d1778:  f0 0a e0 09  ldub  [ %o3 + 9 ], %i0
a00d177c:  f0 2e 60 08  stb  %i0, [ %i1 + 8 ]
a00d1780:  d4 0a e0 0a  ldub  [ %o3 + 0xa ], %o2
a00d1784:  d4 2e 60 09  stb  %o2, [ %i1 + 9 ]
a00d1788:  10 bf ff 54  b  0xa00d14d8
a00d178c:  da 0a e0 0b  ldub  [ %o3 + 0xb ], %o5
a00d1790:  9a 10 3f 89  mov  -119, %o5
a00d1794:  da 2e 60 01  stb  %o5, [ %i1 + 1 ]
a00d1798:  96 10 20 50  mov  0x50, %o3
a00d179c:  98 10 20 00  clr  %o4
a00d17a0:  9a 10 20 00  clr  %o5
a00d17a4:  d2 0b 40 19  ldub  [ %o5 + %i1 ], %o1
a00d17a8:  98 03 20 01  inc  %o4
a00d17ac:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d17b0:  80 a3 60 0b  cmp  %o5, 0xb
a00d17b4:  0a bf ff fc  bcs  0xa00d17a4
a00d17b8:  96 1a c0 09  xor  %o3, %o1, %o3
a00d17bc:  10 80 00 9c  b  0xa00d1a2c
a00d17c0:  d6 2e 60 0b  stb  %o3, [ %i1 + 0xb ]
a00d17c4:  10 bf ff 68  b  0xa00d1564
a00d17c8:  d0 2e 60 08  stb  %o0, [ %i1 + 8 ]
a00d17cc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d17d0:  f4 02 22 90  ld  [ %o0 + 0x290 ], %i2	! 0xa802d290
a00d17d4:  99 36 a0 0e  srl  %i2, 0xe, %o4
a00d17d8:  96 0b 20 01  and  %o4, 1, %o3
a00d17dc:  f0 0e 60 01  ldub  [ %i1 + 1 ], %i0
a00d17e0:  9e 0e 20 7f  and  %i0, 0x7f, %o7
a00d17e4:  d6 2e 60 07  stb  %o3, [ %i1 + 7 ]
a00d17e8:  94 83 e0 02  addcc  %o7, 2, %o2
a00d17ec:  96 10 20 50  mov  0x50, %o3
a00d17f0:  02 bf fe cd  be  0xa00d1324
a00d17f4:  98 10 20 00  clr  %o4
a00d17f8:  9a 10 20 00  clr  %o5
a00d17fc:  c2 0b 40 19  ldub  [ %o5 + %i1 ], %g1
a00d1800:  98 03 20 01  inc  %o4
a00d1804:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d1808:  80 a3 40 0a  cmp  %o5, %o2
a00d180c:  0a bf ff fc  bcs  0xa00d17fc
a00d1810:  96 1a c0 01  xor  %o3, %g1, %o3
a00d1814:  10 80 00 86  b  0xa00d1a2c
a00d1818:  d6 2e 60 08  stb  %o3, [ %i1 + 8 ]
a00d181c:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a00d1820:  d4 0b e0 65  ldub  [ %o7 + 0x65 ], %o2	! 0xa802d465
a00d1824:  d2 0e 60 01  ldub  [ %i1 + 1 ], %o1
a00d1828:  9a 0a 60 7f  and  %o1, 0x7f, %o5
a00d182c:  d4 2e 60 07  stb  %o2, [ %i1 + 7 ]
a00d1830:  94 83 60 02  addcc  %o5, 2, %o2
a00d1834:  96 10 20 50  mov  0x50, %o3
a00d1838:  02 bf fe bb  be  0xa00d1324
a00d183c:  98 10 20 00  clr  %o4
a00d1840:  9a 10 20 00  clr  %o5
a00d1844:  f0 0b 40 19  ldub  [ %o5 + %i1 ], %i0
a00d1848:  98 03 20 01  inc  %o4
a00d184c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d1850:  80 a3 40 0a  cmp  %o5, %o2
a00d1854:  0a bf ff fc  bcs  0xa00d1844
a00d1858:  96 1a c0 18  xor  %o3, %i0, %o3
a00d185c:  10 80 00 74  b  0xa00d1a2c
a00d1860:  d6 2e 60 08  stb  %o3, [ %i1 + 8 ]
a00d1864:  f0 0e 20 07  ldub  [ %i0 + 7 ], %i0
a00d1868:  80 a6 20 00  cmp  %i0, 0
a00d186c:  12 80 00 1e  bne  0xa00d18e4
a00d1870:  80 a6 20 01  cmp  %i0, 1
a00d1874:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00d1878:  d8 06 a2 90  ld  [ %i2 + 0x290 ], %o4	! 0xa802d290
a00d187c:  97 33 20 0e  srl  %o4, 0xe, %o3
a00d1880:  82 0a e0 01  and  %o3, 1, %g1
a00d1884:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00d1888:  d4 0e 60 01  ldub  [ %i1 + 1 ], %o2
a00d188c:  9a 0a a0 7f  and  %o2, 0x7f, %o5
a00d1890:  94 83 60 02  addcc  %o5, 2, %o2
a00d1894:  96 10 20 50  mov  0x50, %o3
a00d1898:  02 bf fe a3  be  0xa00d1324
a00d189c:  98 10 20 00  clr  %o4
a00d18a0:  9a 10 20 00  clr  %o5
a00d18a4:  d2 0b 40 19  ldub  [ %o5 + %i1 ], %o1
a00d18a8:  98 03 20 01  inc  %o4
a00d18ac:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d18b0:  80 a3 40 0a  cmp  %o5, %o2
a00d18b4:  0a bf ff fc  bcs  0xa00d18a4
a00d18b8:  96 1a c0 09  xor  %o3, %o1, %o3
a00d18bc:  10 80 00 5c  b  0xa00d1a2c
a00d18c0:  d6 2e 60 08  stb  %o3, [ %i1 + 8 ]
a00d18c4:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00d18c8:  b0 16 a2 74  or  %i2, 0x274, %i0	! 0xa802d274
a00d18cc:  d8 16 20 16  lduh  [ %i0 + 0x16 ], %o4
a00d18d0:  97 33 20 08  srl  %o4, 8, %o3
a00d18d4:  d6 2e 60 06  stb  %o3, [ %i1 + 6 ]
a00d18d8:  de 16 20 16  lduh  [ %i0 + 0x16 ], %o7
a00d18dc:  10 80 00 54  b  0xa00d1a2c
a00d18e0:  de 2e 60 07  stb  %o7, [ %i1 + 7 ]
a00d18e4:  02 80 00 38  be  0xa00d19c4
a00d18e8:  80 a6 20 02  cmp  %i0, 2
a00d18ec:  12 bf ff e6  bne  0xa00d1884
a00d18f0:  82 10 3f e4  mov  -28, %g1
a00d18f4:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00d18f8:  da 08 60 66  ldub  [ %g1 + 0x66 ], %o5	! 0xa802d466
a00d18fc:  10 bf ff e3  b  0xa00d1888
a00d1900:  da 2e 60 07  stb  %o5, [ %i1 + 7 ]
a00d1904:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a00d1908:  9e 13 21 a0  or  %o4, 0x1a0, %o7	! 0xa802e1a0
a00d190c:  d0 03 e0 08  ld  [ %o7 + 8 ], %o0
a00d1910:  b5 2a 20 08  sll  %o0, 8, %i2
a00d1914:  97 36 a0 10  srl  %i2, 0x10, %o3
a00d1918:  b1 2a e0 04  sll  %o3, 4, %i0
a00d191c:  92 26 00 0b  sub  %i0, %o3, %o1
a00d1920:  d4 0b e0 08  ldub  [ %o7 + 8 ], %o2
a00d1924:  9b 2a 60 02  sll  %o1, 2, %o5
a00d1928:  82 03 40 0a  add  %o5, %o2, %g1
a00d192c:  91 30 60 08  srl  %g1, 8, %o0
a00d1930:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00d1934:  10 80 00 3e  b  0xa00d1a2c
a00d1938:  d0 2e 60 06  stb  %o0, [ %i1 + 6 ]
a00d193c:  02 bf fe 6b  be  0xa00d12e8
a00d1940:  80 a0 60 e2  cmp  %g1, 0xe2
a00d1944:  26 bf fe 6a  bl,a   0xa00d12ec
a00d1948:  82 10 3f e1  mov  -31, %g1
a00d194c:  80 a0 60 e3  cmp  %g1, 0xe3
a00d1950:  02 80 00 35  be  0xa00d1a24
a00d1954:  80 a0 60 e4  cmp  %g1, 0xe4
a00d1958:  32 bf fe 65  bne,a   0xa00d12ec
a00d195c:  82 10 3f e2  mov  -30, %g1
a00d1960:  10 bf fe 63  b  0xa00d12ec
a00d1964:  82 10 3f e4  mov  -28, %g1
a00d1968:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d196c:  b4 10 62 90  or  %g1, 0x290, %i2	! 0xa802d290
a00d1970:  40 01 cb 23  call  0xa01445fc
a00d1974:  d0 0e a0 1e  ldub  [ %i2 + 0x1e ], %o0
a00d1978:  80 8a 20 ff  btst  0xff, %o0
a00d197c:  12 80 00 16  bne  0xa00d19d4
a00d1980:  82 10 20 08  mov  8, %g1
a00d1984:  f0 0e 60 01  ldub  [ %i1 + 1 ], %i0
a00d1988:  9e 0e 20 7f  and  %i0, 0x7f, %o7
a00d198c:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00d1990:  94 83 e0 02  addcc  %o7, 2, %o2
a00d1994:  96 10 20 50  mov  0x50, %o3
a00d1998:  02 bf fe 63  be  0xa00d1324
a00d199c:  98 10 20 00  clr  %o4
a00d19a0:  9a 10 20 00  clr  %o5
a00d19a4:  f4 0b 40 19  ldub  [ %o5 + %i1 ], %i2
a00d19a8:  98 03 20 01  inc  %o4
a00d19ac:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d19b0:  80 a3 40 0a  cmp  %o5, %o2
a00d19b4:  0a bf ff fc  bcs  0xa00d19a4
a00d19b8:  96 1a c0 1a  xor  %o3, %i2, %o3
a00d19bc:  10 80 00 1c  b  0xa00d1a2c
a00d19c0:  d6 2e 60 08  stb  %o3, [ %i1 + 8 ]
a00d19c4:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a00d19c8:  da 0a 20 65  ldub  [ %o0 + 0x65 ], %o5	! 0xa802d465
a00d19cc:  10 bf ff af  b  0xa00d1888
a00d19d0:  da 2e 60 07  stb  %o5, [ %i1 + 7 ]
a00d19d4:  40 01 cb 0a  call  0xa01445fc
a00d19d8:  d0 0e a0 1e  ldub  [ %i2 + 0x1e ], %o0
a00d19dc:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00d19e0:  80 a3 60 01  cmp  %o5, 1
a00d19e4:  02 bf ff e8  be  0xa00d1984
a00d19e8:  82 10 20 09  mov  9, %g1
a00d19ec:  40 01 cb 04  call  0xa01445fc
a00d19f0:  d0 0e a0 1e  ldub  [ %i2 + 0x1e ], %o0
a00d19f4:  94 0a 20 ff  and  %o0, 0xff, %o2
a00d19f8:  80 a2 a0 02  cmp  %o2, 2
a00d19fc:  02 bf ff e2  be  0xa00d1984
a00d1a00:  82 10 20 0d  mov  0xd, %g1
a00d1a04:  40 01 ca fe  call  0xa01445fc
a00d1a08:  d0 0e a0 1e  ldub  [ %i2 + 0x1e ], %o0
a00d1a0c:  92 0a 20 ff  and  %o0, 0xff, %o1
a00d1a10:  80 a2 60 03  cmp  %o1, 3
a00d1a14:  02 bf ff dc  be  0xa00d1984
a00d1a18:  82 10 20 0f  mov  0xf, %g1
a00d1a1c:  10 bf ff da  b  0xa00d1984
a00d1a20:  82 10 3f e1  mov  -31, %g1
a00d1a24:  10 bf fe 32  b  0xa00d12ec
a00d1a28:  82 10 3f e3  mov  -29, %g1
a00d1a2c:  81 c7 e0 08  ret
a00d1a30:  81 e8 00 00  restore
