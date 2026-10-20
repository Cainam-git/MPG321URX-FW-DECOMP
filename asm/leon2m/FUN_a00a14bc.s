# leon2m FUN_a00a14bc 0xa00a14bc-0xa00a15d0 (88 bytes)
a00a14bc:  9d e3 bf 98  save  %sp, -104, %sp
a00a14c0:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a00a14c4:  fa 00 63 ec  ld  [ %g1 + 0x3ec ], %i5	! 0xa802afec
a00a14c8:  82 07 7f 40  add  %i5, -192, %g1
a00a14cc:  b2 10 00 18  mov  %i0, %i1
a00a14d0:  80 a0 60 39  cmp  %g1, 0x39
a00a14d4:  9a 10 20 00  clr  %o5
a00a14d8:  b4 10 20 00  clr  %i2
a00a14dc:  9e 10 20 00  clr  %o7
a00a14e0:  b6 10 20 00  clr  %i3
a00a14e4:  18 80 00 08  bgu  0xa00a1504
a00a14e8:  b0 10 20 00  clr  %i0
a00a14ec:  39 00 00 bd  sethi  %hi(0x2f400), %i4
a00a14f0:  83 28 60 02  sll  %g1, 2, %g1
a00a14f4:  ba 17 20 00  mov  %i4, %i5
a00a14f8:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a00a14fc:  81 c7 00 00  jmp  %i4
a00a1500:  01 00 00 00  nop
a00a1504:  10 80 00 31  b  0xa00a15c8
a00a1508:  b0 10 20 00  clr  %i0	! 0x0
a00a150c:  39 2a 00 b5  sethi  %hi(0xa802d400), %i4
a00a1510:  f4 0f 20 7d  ldub  [ %i4 + 0x7d ], %i2	! 0xa802d47d
a00a1514:  b6 10 20 01  mov  1, %i3
a00a1518:  b0 10 20 03  mov  3, %i0
a00a151c:  82 0e 60 ff  and  %i1, 0xff, %g1
a00a1520:  80 a0 60 05  cmp  %g1, 5
a00a1524:  38 80 00 29  bgu,a   0xa00a15c8
a00a1528:  b0 10 20 00  clr  %i0
a00a152c:  39 00 00 bc  sethi  %hi(0x2f000), %i4
a00a1530:  83 28 60 02  sll  %g1, 2, %g1
a00a1534:  ba 17 23 e8  or  %i4, 0x3e8, %i5
a00a1538:  f2 07 40 01  ld  [ %i5 + %g1 ], %i1
a00a153c:  81 c6 40 00  jmp  %i1
a00a1540:  01 00 00 00  nop
a00a1544:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00a1548:  da 08 60 78  ldub  [ %g1 + 0x78 ], %o5	! 0xa802d478
a00a154c:  10 bf ff f4  b  0xa00a151c
a00a1550:  9e 10 20 04  mov  4, %o7
a00a1554:  3b 2a 00 b4  sethi  %hi(0xa802d000), %i5
a00a1558:  b4 17 62 90  or  %i5, 0x290, %i2	! 0xa802d290
a00a155c:  da 0e a1 ea  ldub  [ %i2 + 0x1ea ], %o5
a00a1560:  b6 17 62 90  or  %i5, 0x290, %i3
a00a1564:  9e 10 20 05  mov  5, %o7
a00a1568:  10 bf ff eb  b  0xa00a1514
a00a156c:  f4 0e e1 eb  ldub  [ %i3 + 0x1eb ], %i2
a00a1570:  3b 2a 00 b5  sethi  %hi(0xa802d400), %i5
a00a1574:  da 0f 60 7c  ldub  [ %i5 + 0x7c ], %o5	! 0xa802d47c
a00a1578:  10 bf ff e9  b  0xa00a151c
a00a157c:  9e 10 20 06  mov  6, %o7
a00a1580:  31 2a 00 b5  sethi  %hi(0xa802d400), %i0
a00a1584:  f4 0e 20 79  ldub  [ %i0 + 0x79 ], %i2	! 0xa802d479
a00a1588:  b6 10 20 01  mov  1, %i3
a00a158c:  10 bf ff e4  b  0xa00a151c
a00a1590:  b0 10 20 02  mov  2, %i0
a00a1594:  3b 2a 00 b4  sethi  %hi(0xa802d000), %i5
a00a1598:  b6 17 62 90  or  %i5, 0x290, %i3	! 0xa802d290
a00a159c:  10 bf ff de  b  0xa00a1514
a00a15a0:  f4 0e e1 eb  ldub  [ %i3 + 0x1eb ], %i2
a00a15a4:  10 80 00 09  b  0xa00a15c8
a00a15a8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a15ac:  10 80 00 07  b  0xa00a15c8
a00a15b0:  b0 0e e0 ff  and  %i3, 0xff, %i0
a00a15b4:  10 80 00 05  b  0xa00a15c8
a00a15b8:  b0 0b e0 ff  and  %o7, 0xff, %i0
a00a15bc:  10 80 00 03  b  0xa00a15c8
a00a15c0:  b0 0e a0 ff  and  %i2, 0xff, %i0
a00a15c4:  b0 0b 60 ff  and  %o5, 0xff, %i0
a00a15c8:  81 c7 e0 08  ret
a00a15cc:  81 e8 00 00  restore
