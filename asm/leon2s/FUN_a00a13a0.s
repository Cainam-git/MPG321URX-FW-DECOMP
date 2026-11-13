# leon2s FUN_a00a13a0 0xa00a13a0-0xa00a146c (204 bytes)
a00a13a0:  9d e3 bf 98  save  %sp, -104, %sp
a00a13a4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a13a8:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a13ac:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00a13b0:  9a 5e 20 34  smul  %i0, 0x34, %o5
a00a13b4:  9a 03 40 01  add  %o5, %g1, %o5
a00a13b8:  d8 03 60 04  ld  [ %o5 + 4 ], %o4
a00a13bc:  d2 03 20 60  ld  [ %o4 + 0x60 ], %o1
a00a13c0:  da 03 20 64  ld  [ %o4 + 0x64 ], %o5
a00a13c4:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a00a13c8:  82 2b 40 01  andn  %o5, %g1, %g1
a00a13cc:  80 a0 60 1a  cmp  %g1, 0x1a
a00a13d0:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a13d4:  9a 5e 21 90  smul  %i0, 0x190, %o5
a00a13d8:  92 10 63 e0  or  %g1, 0x3e0, %o1
a00a13dc:  96 10 20 01  mov  1, %o3
a00a13e0:  12 80 00 14  bne  0xa00a1430
a00a13e4:  b4 03 40 09  add  %o5, %o1, %i2
a00a13e8:  d2 03 20 68  ld  [ %o4 + 0x68 ], %o1
a00a13ec:  99 32 60 08  srl  %o1, 8, %o4
a00a13f0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00a13f4:  97 33 60 02  srl  %o5, 2, %o3
a00a13f8:  95 32 60 10  srl  %o1, 0x10, %o2
a00a13fc:  9b 33 60 01  srl  %o5, 1, %o5
a00a1400:  9a 0b 60 01  and  %o5, 1, %o5
a00a1404:  96 0a e0 01  and  %o3, 1, %o3
a00a1408:  93 32 60 18  srl  %o1, 0x18, %o1
a00a140c:  98 0b 20 01  and  %o4, 1, %o4
a00a1410:  82 10 20 01  mov  1, %g1
a00a1414:  c2 2e a1 5c  stb  %g1, [ %i2 + 0x15c ]
a00a1418:  d4 2e a1 60  stb  %o2, [ %i2 + 0x160 ]
a00a141c:  d2 2e a1 61  stb  %o1, [ %i2 + 0x161 ]
a00a1420:  d8 2e a1 5d  stb  %o4, [ %i2 + 0x15d ]
a00a1424:  da 2e a1 5e  stb  %o5, [ %i2 + 0x15e ]
a00a1428:  10 80 00 0d  b  0xa00a145c
a00a142c:  d6 2e a1 5f  stb  %o3, [ %i2 + 0x15f ]
a00a1430:  92 02 60 ec  add  %o1, 0xec, %o1
a00a1434:  c2 0e a1 0e  ldub  [ %i2 + 0x10e ], %g1
a00a1438:  d6 2e a1 0d  stb  %o3, [ %i2 + 0x10d ]
a00a143c:  80 a0 60 00  cmp  %g1, 0
a00a1440:  92 03 40 09  add  %o5, %o1, %o1
a00a1444:  d6 2e a1 0c  stb  %o3, [ %i2 + 0x10c ]
a00a1448:  12 80 00 04  bne  0xa00a1458
a00a144c:  90 10 00 18  mov  %i0, %o0
a00a1450:  7f ff fa 1a  call  0xa009fcb8
a00a1454:  01 00 00 00  nop
a00a1458:  c0 2e a1 5c  clrb  [ %i2 + 0x15c ]
a00a145c:  b2 10 20 11  mov  0x11, %i1
a00a1460:  7f ff fd ce  call  0xa00a0b98
a00a1464:  95 e8 20 00  restore  %g0, 0, %o2
a00a1468:  01 00 00 00  nop
