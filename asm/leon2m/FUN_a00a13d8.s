# leon2m FUN_a00a13d8 0xa00a13d8-0xa00a14bc (228 bytes)
a00a13d8:  9d e3 bf 98  save  %sp, -104, %sp
a00a13dc:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a00a13e0:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1	! 0xa802afec
a00a13e4:  90 00 7f cc  add  %g1, -52, %o0
a00a13e8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a13ec:  40 00 1f 08  call  0xa00a900c
a00a13f0:  92 10 20 02  mov  2, %o1
a00a13f4:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1
a00a13f8:  80 a0 60 39  cmp  %g1, 0x39
a00a13fc:  02 80 00 1d  be  0xa00a1470
a00a1400:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a00a1404:  80 a0 60 39  cmp  %g1, 0x39
a00a1408:  08 80 00 0b  bleu  0xa00a1434
a00a140c:  80 a0 60 38  cmp  %g1, 0x38
a00a1410:  80 a0 60 3a  cmp  %g1, 0x3a
a00a1414:  02 80 00 23  be  0xa00a14a0
a00a1418:  d0 0e 60 56  ldub  [ %i1 + 0x56 ], %o0
a00a141c:  40 00 20 8d  call  0xa00a9650
a00a1420:  92 10 20 01  mov  1, %o1
a00a1424:  f2 0e 60 56  ldub  [ %i1 + 0x56 ], %i1
a00a1428:  b0 10 20 01  mov  1, %i0
a00a142c:  40 00 1b 44  call  0xa00a813c
a00a1430:  95 e8 20 00  restore  %g0, 0, %o2
a00a1434:  12 bf ff fa  bne  0xa00a141c
a00a1438:  d0 0e 60 56  ldub  [ %i1 + 0x56 ], %o0
a00a143c:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00a1440:  da 0a 60 78  ldub  [ %o1 + 0x78 ], %o5	! 0xa802d478
a00a1444:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a00a1448:  82 10 20 c0  mov  0xc0, %g1
a00a144c:  c2 26 a3 ec  st  %g1, [ %i2 + 0x3ec ]
a00a1450:  da 2e 60 56  stb  %o5, [ %i1 + 0x56 ]
a00a1454:  d0 0e 60 56  ldub  [ %i1 + 0x56 ], %o0
a00a1458:  40 00 20 7e  call  0xa00a9650
a00a145c:  92 10 20 01  mov  1, %o1
a00a1460:  f2 0e 60 56  ldub  [ %i1 + 0x56 ], %i1
a00a1464:  b0 10 20 01  mov  1, %i0
a00a1468:  40 00 1b 35  call  0xa00a813c
a00a146c:  95 e8 20 00  restore  %g0, 0, %o2
a00a1470:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00a1474:  d8 0a a0 7a  ldub  [ %o2 + 0x7a ], %o4	! 0xa802d47a
a00a1478:  d8 2e 60 56  stb  %o4, [ %i1 + 0x56 ]
a00a147c:  9a 10 20 c1  mov  0xc1, %o5
a00a1480:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a00a1484:  d0 0e 60 56  ldub  [ %i1 + 0x56 ], %o0
a00a1488:  40 00 20 72  call  0xa00a9650
a00a148c:  92 10 20 01  mov  1, %o1
a00a1490:  f2 0e 60 56  ldub  [ %i1 + 0x56 ], %i1
a00a1494:  b0 10 20 01  mov  1, %i0
a00a1498:  40 00 1b 29  call  0xa00a813c
a00a149c:  95 e8 20 00  restore  %g0, 0, %o2
a00a14a0:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00a14a4:  da 0a e0 7c  ldub  [ %o3 + 0x7c ], %o5	! 0xa802d47c
a00a14a8:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a00a14ac:  82 10 20 c2  mov  0xc2, %g1
a00a14b0:  c2 26 a3 ec  st  %g1, [ %i2 + 0x3ec ]
a00a14b4:  10 bf ff e8  b  0xa00a1454
a00a14b8:  da 2e 60 56  stb  %o5, [ %i1 + 0x56 ]
