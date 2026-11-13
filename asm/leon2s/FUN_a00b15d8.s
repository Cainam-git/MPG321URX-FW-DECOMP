# leon2s FUN_a00b15d8 0xa00b15d8-0xa00b160c (52 bytes)
a00b15d8:  94 02 bf ff  add  %o2, -1, %o2
a00b15dc:  80 a2 bf ff  cmp  %o2, -1
a00b15e0:  02 80 00 09  be  0xa00b1604
a00b15e4:  9a 10 00 08  mov  %o0, %o5
a00b15e8:  c2 0a 40 00  ldub  [ %o1 ], %g1
a00b15ec:  c2 2b 40 00  stb  %g1, [ %o5 ]
a00b15f0:  94 02 bf ff  add  %o2, -1, %o2
a00b15f4:  92 02 60 01  inc  %o1
a00b15f8:  80 a2 bf ff  cmp  %o2, -1
a00b15fc:  12 bf ff fb  bne  0xa00b15e8
a00b1600:  9a 03 60 01  inc  %o5
a00b1604:  81 c3 e0 08  retl
a00b1608:  01 00 00 00  nop
