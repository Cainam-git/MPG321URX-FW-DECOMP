# leon2s FUN_a00b1538 0xa00b1538-0xa00b1568 (48 bytes)
a00b1538:  c2 4a 00 00  ldsb  [ %o0 ], %g1
a00b153c:  80 a0 60 00  cmp  %g1, 0
a00b1540:  9a 10 20 00  clr  %o5
a00b1544:  02 80 00 07  be  0xa00b1560
a00b1548:  01 00 00 00  nop
a00b154c:  90 02 20 01  inc  %o0
a00b1550:  c2 4a 00 00  ldsb  [ %o0 ], %g1
a00b1554:  80 a0 60 00  cmp  %g1, 0
a00b1558:  10 bf ff fb  b  0xa00b1544
a00b155c:  9a 03 60 01  inc  %o5
a00b1560:  81 c3 e0 08  retl
a00b1564:  90 10 00 0d  mov  %o5, %o0
