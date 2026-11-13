# leon2s H1_H2_VTH 0xa007f798-0xa007f7c8 (48 bytes)
a007f798:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007f79c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007f7a0:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a007f7a4:  80 88 68 00  btst  0x800, %g1
a007f7a8:  02 80 00 05  be  0xa007f7bc
a007f7ac:  90 12 21 08  or  %o0, 0x108, %o0
a007f7b0:  82 13 c0 00  mov  %o7, %g1
a007f7b4:  7f ff cf 44  call  0xa00734c4
a007f7b8:  9e 10 40 00  mov  %g1, %o7
a007f7bc:  01 00 00 00  nop
a007f7c0:  81 c3 e0 08  retl
a007f7c4:  01 00 00 00  nop
