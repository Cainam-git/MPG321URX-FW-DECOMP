# leon2m FUN_a00fa560 0xa00fa560-0xa00fa5b4 (84 bytes)
a00fa560:  17 34 01 00  sethi  %hi(0xd0040000), %o3
a00fa564:  94 12 e0 14  or  %o3, 0x14, %o2	! 0xd0040014
a00fa568:  d8 02 80 00  ld  [ %o2 ], %o4
a00fa56c:  83 2b 20 06  sll  %o4, 6, %g1
a00fa570:  97 33 20 1e  srl  %o4, 0x1e, %o3
a00fa574:  9b 30 60 16  srl  %g1, 0x16, %o5
a00fa578:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a00fa57c:  d8 0a a0 5e  ldub  [ %o2 + 0x5e ], %o4	! 0xa802c85e
a00fa580:  03 2a 00 af  sethi  %hi(0xa802bc00), %g1
a00fa584:  80 a2 c0 0c  cmp  %o3, %o4
a00fa588:  02 80 00 07  be  0xa00fa5a4
a00fa58c:  da 30 62 c0  sth  %o5, [ %g1 + 0x2c0 ]
a00fa590:  9a 10 20 01  mov  1, %o5
a00fa594:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00fa598:  d6 2a a0 5e  stb  %o3, [ %o2 + 0x5e ]
a00fa59c:  10 80 00 04  b  0xa00fa5ac
a00fa5a0:  da 28 63 fe  stb  %o5, [ %g1 + 0x3fe ]
a00fa5a4:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00fa5a8:  c0 2b 23 fe  clrb  [ %o4 + 0x3fe ]	! 0xa802b7fe
a00fa5ac:  81 c3 e0 08  retl
a00fa5b0:  01 00 00 00  nop
