# leon2s FUN_a00a151c 0xa00a151c-0xa00a1574 (88 bytes)
a00a151c:  9d e3 bf 98  save  %sp, -104, %sp
a00a1520:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a1524:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a00a1528:  a0 14 23 00  or  %l0, 0x300, %l0	! 0xa807db00
a00a152c:  b0 5e 20 34  smul  %i0, 0x34, %i0
a00a1530:  d2 04 00 18  ld  [ %l0 + %i0 ], %o1
a00a1534:  92 02 60 04  add  %o1, 4, %o1
a00a1538:  40 00 17 9d  call  0xa00a73ac
a00a153c:  90 10 20 09  mov  9, %o0
a00a1540:  40 00 40 33  call  0xa00b160c
a00a1544:  90 10 20 01  mov  1, %o0
a00a1548:  d2 04 00 18  ld  [ %l0 + %i0 ], %o1
a00a154c:  92 02 60 04  add  %o1, 4, %o1
a00a1550:  40 00 17 a1  call  0xa00a73d4
a00a1554:  90 10 20 09  mov  9, %o0
a00a1558:  40 00 40 8f  call  0xa00b1794
a00a155c:  90 10 20 01  mov  1, %o0
a00a1560:  9a 10 20 01  mov  1, %o5
a00a1564:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a1568:  da 28 61 8e  stb  %o5, [ %g1 + 0x18e ]	! 0xa807918e
a00a156c:  81 c7 e0 08  ret
a00a1570:  81 e8 00 00  restore
