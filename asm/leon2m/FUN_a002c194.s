# leon2m FUN_a002c194 0xa002c194-0xa002c204 (112 bytes)
a002c194:  90 0a 20 ff  and  %o0, 0xff, %o0
a002c198:  80 a2 20 02  cmp  %o0, 2
a002c19c:  02 80 00 11  be  0xa002c1e0
a002c1a0:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a002c1a4:  04 80 00 09  ble  0xa002c1c8
a002c1a8:  80 a2 20 01  cmp  %o0, 1
a002c1ac:  80 a2 20 03  cmp  %o0, 3
a002c1b0:  02 80 00 10  be  0xa002c1f0
a002c1b4:  80 a2 20 04  cmp  %o0, 4
a002c1b8:  02 80 00 0c  be  0xa002c1e8
a002c1bc:  1b 33 c0 f2  sethi  %hi(0xcf03c800), %o5
a002c1c0:  10 80 00 0f  b  0xa002c1fc
a002c1c4:  90 10 20 00  clr  %o0
a002c1c8:  32 80 00 0d  bne,a   0xa002c1fc
a002c1cc:  90 10 20 00  clr  %o0
a002c1d0:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a002c1d4:  da 00 40 00  ld  [ %g1 ], %o5
a002c1d8:  10 80 00 09  b  0xa002c1fc
a002c1dc:  90 0b 60 ff  and  %o5, 0xff, %o0
a002c1e0:  10 bf ff fd  b  0xa002c1d4
a002c1e4:  82 10 60 04  or  %g1, 4, %g1
a002c1e8:  10 bf ff fb  b  0xa002c1d4
a002c1ec:  82 13 60 0c  or  %o5, 0xc, %g1
a002c1f0:  11 33 c0 f2  sethi  %hi(0xcf03c800), %o0
a002c1f4:  10 bf ff f8  b  0xa002c1d4
a002c1f8:  82 12 20 08  or  %o0, 8, %g1	! 0xcf03c808
a002c1fc:  81 c3 e0 08  retl
a002c200:  01 00 00 00  nop
