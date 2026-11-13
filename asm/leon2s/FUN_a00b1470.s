# leon2s FUN_a00b1470 0xa00b1470-0xa00b1494 (36 bytes)
a00b1470:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a00b1474:  98 13 20 94  or  %o4, 0x94, %o4	! 0xcf03c894
a00b1478:  9a 10 20 01  mov  1, %o5
a00b147c:  c2 03 00 00  ld  [ %o4 ], %g1
a00b1480:  9b 2b 40 08  sll  %o5, %o0, %o5
a00b1484:  82 10 40 0d  or  %g1, %o5, %g1
a00b1488:  c2 23 00 00  st  %g1, [ %o4 ]
a00b148c:  81 c3 e0 08  retl
a00b1490:  01 00 00 00  nop
