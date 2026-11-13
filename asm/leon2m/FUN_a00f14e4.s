# leon2m FUN_a00f14e4 0xa00f14e4-0xa00f154c (104 bytes)
a00f14e4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f14e8:  80 a2 20 04  cmp  %o0, 4
a00f14ec:  82 40 20 00  addx  %g0, 0, %g1
a00f14f0:  9a 20 00 01  neg  %g1, %o5
a00f14f4:  96 0a 00 0d  and  %o0, %o5, %o3
a00f14f8:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00f14fc:  82 13 22 7e  or  %o4, 0x27e, %g1	! 0xa8026a7e
a00f1500:  9a 02 c0 0b  add  %o3, %o3, %o5
a00f1504:  93 2a 60 10  sll  %o1, 0x10, %o1
a00f1508:  d6 10 40 0d  lduh  [ %g1 + %o5 ], %o3
a00f150c:  91 32 60 10  srl  %o1, 0x10, %o0
a00f1510:  98 02 c0 08  add  %o3, %o0, %o4
a00f1514:  92 03 20 01  add  %o4, 1, %o1
a00f1518:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00f151c:  9b 2b 20 02  sll  %o4, 2, %o5
a00f1520:  90 13 40 0b  or  %o5, %o3, %o0
a00f1524:  83 2a 60 02  sll  %o1, 2, %g1
a00f1528:  d2 02 00 00  ld  [ %o0 ], %o1
a00f152c:  98 10 40 0b  or  %g1, %o3, %o4
a00f1530:  da 03 00 00  ld  [ %o4 ], %o5
a00f1534:  97 2b 60 08  sll  %o5, 8, %o3
a00f1538:  82 0a 60 ff  and  %o1, 0xff, %g1
a00f153c:  92 12 c0 01  or  %o3, %g1, %o1
a00f1540:  91 2a 60 10  sll  %o1, 0x10, %o0
a00f1544:  81 c3 e0 08  retl
a00f1548:  91 32 20 10  srl  %o0, 0x10, %o0
