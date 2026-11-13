# leon2s FUN_a00b1394 0xa00b1394-0xa00b1418 (132 bytes)
a00b1394:  03 33 c0 df  sethi  %hi(0xcf037c00), %g1
a00b1398:  96 10 60 80  or  %g1, 0x80, %o3	! 0xcf037c80
a00b139c:  9a 10 20 01  mov  1, %o5
a00b13a0:  da 22 c0 00  st  %o5, [ %o3 ]
a00b13a4:  96 10 60 84  or  %g1, 0x84, %o3
a00b13a8:  c2 02 c0 00  ld  [ %o3 ], %g1
a00b13ac:  80 a0 60 01  cmp  %g1, 1
a00b13b0:  02 80 00 0a  be  0xa00b13d8
a00b13b4:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a00b13b8:  98 10 60 20  or  %g1, 0x20, %o4	! 0xcf03c820
a00b13bc:  9a 10 60 30  or  %g1, 0x30, %o5
a00b13c0:  c2 03 00 00  ld  [ %o4 ], %g1
a00b13c4:  c2 23 40 00  st  %g1, [ %o5 ]
a00b13c8:  c2 02 c0 00  ld  [ %o3 ], %g1
a00b13cc:  80 a0 60 01  cmp  %g1, 1
a00b13d0:  12 bf ff fc  bne  0xa00b13c0
a00b13d4:  01 00 00 00  nop
a00b13d8:  03 33 c0 df  sethi  %hi(0xcf037c00), %g1
a00b13dc:  96 10 60 88  or  %g1, 0x88, %o3	! 0xcf037c88
a00b13e0:  94 10 20 00  clr  %o2
a00b13e4:  82 0a a0 ff  and  %o2, 0xff, %g1
a00b13e8:  94 02 a0 01  inc  %o2
a00b13ec:  da 02 c0 00  ld  [ %o3 ], %o5
a00b13f0:  98 0a a0 ff  and  %o2, 0xff, %o4
a00b13f4:  da 2a 40 01  stb  %o5, [ %o1 + %g1 ]
a00b13f8:  80 a3 20 3e  cmp  %o4, 0x3e
a00b13fc:  08 bf ff fa  bleu  0xa00b13e4
a00b1400:  96 02 e0 04  add  %o3, 4, %o3
a00b1404:  03 33 c0 df  sethi  %hi(0xcf037c00), %g1
a00b1408:  96 10 60 80  or  %g1, 0x80, %o3	! 0xcf037c80
a00b140c:  c0 22 c0 00  clr  [ %o3 ]
a00b1410:  81 c3 e0 08  retl
a00b1414:  01 00 00 00  nop
