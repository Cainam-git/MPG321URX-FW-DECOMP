# leon2s FUN_a00b1508 0xa00b1508-0xa00b1538 (48 bytes)
a00b1508:  98 10 20 00  clr  %o4	! 0x0
a00b150c:  80 a3 00 0a  cmp  %o4, %o2
a00b1510:  1a 80 00 08  bcc  0xa00b1530
a00b1514:  01 00 00 00  nop
a00b1518:  9b 2b 20 02  sll  %o4, 2, %o5
a00b151c:  98 03 20 01  inc  %o4
a00b1520:  c2 02 40 0d  ld  [ %o1 + %o5 ], %g1
a00b1524:  80 a3 00 0a  cmp  %o4, %o2
a00b1528:  0a bf ff fc  bcs  0xa00b1518
a00b152c:  c2 22 00 0d  st  %g1, [ %o0 + %o5 ]
a00b1530:  81 c3 e0 08  retl
a00b1534:  01 00 00 00  nop
