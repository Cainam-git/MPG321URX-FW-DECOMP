# leon2m FUN_a01085a4 0xa01085a4-0xa01085f8 (84 bytes)
a01085a4:  80 8a 20 ff  btst  0xff, %o0
a01085a8:  12 80 00 12  bne  0xa01085f0
a01085ac:  11 33 c0 46  sethi  %hi(0xcf011800), %o0
a01085b0:  82 12 22 00  or  %o0, 0x200, %g1	! 0xcf011a00
a01085b4:  da 00 40 00  ld  [ %g1 ], %o5
a01085b8:  80 8b 60 10  btst  0x10, %o5
a01085bc:  02 80 00 0d  be  0xa01085f0
a01085c0:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a01085c4:  82 12 22 d0  or  %o0, 0x2d0, %g1	! 0xcf0116d0
a01085c8:  da 00 40 00  ld  [ %g1 ], %o5
a01085cc:  90 0b 60 7f  and  %o5, 0x7f, %o0
a01085d0:  9a 02 20 01  add  %o0, 1, %o5
a01085d4:  81 80 00 00  mov  %g0, %y
a01085d8:  c2 02 40 00  ld  [ %o1 ], %g1
a01085dc:  01 00 00 00  nop
a01085e0:  01 00 00 00  nop
a01085e4:  82 70 40 0d  udiv  %g1, %o5, %g1
a01085e8:  9a 00 60 01  add  %g1, 1, %o5
a01085ec:  da 22 40 00  st  %o5, [ %o1 ]
a01085f0:  81 c3 e0 08  retl
a01085f4:  01 00 00 00  nop
