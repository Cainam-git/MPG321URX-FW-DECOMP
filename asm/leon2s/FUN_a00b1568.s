# leon2s FUN_a00b1568 0xa00b1568-0xa00b15ac (68 bytes)
a00b1568:  da 0a 00 00  ldub  [ %o0 ], %o5
a00b156c:  c2 0a 40 00  ldub  [ %o1 ], %g1
a00b1570:  9b 2b 60 18  sll  %o5, 0x18, %o5
a00b1574:  83 28 60 18  sll  %g1, 0x18, %g1
a00b1578:  9b 3b 60 18  sra  %o5, 0x18, %o5
a00b157c:  83 38 60 18  sra  %g1, 0x18, %g1
a00b1580:  96 23 40 01  sub  %o5, %g1, %o3
a00b1584:  80 a0 00 0b  cmp  %g0, %o3
a00b1588:  98 60 3f ff  subx  %g0, -1, %o4
a00b158c:  80 a0 00 0d  cmp  %g0, %o5
a00b1590:  82 40 20 00  addx  %g0, 0, %g1
a00b1594:  80 8b 00 01  btst  %o4, %g1
a00b1598:  90 02 20 01  inc  %o0
a00b159c:  12 bf ff f3  bne  0xa00b1568
a00b15a0:  92 02 60 01  inc  %o1
a00b15a4:  81 c3 e0 08  retl
a00b15a8:  90 10 00 0b  mov  %o3, %o0
