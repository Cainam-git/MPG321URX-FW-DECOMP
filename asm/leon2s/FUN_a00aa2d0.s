# leon2s FUN_a00aa2d0 0xa00aa2d0-0xa00aa304 (52 bytes)
a00aa2d0:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00aa2d4:  c2 08 63 b9  ldub  [ %g1 + 0x3b9 ], %g1	! 0xa807d3b9
a00aa2d8:  90 10 20 00  clr  %o0
a00aa2dc:  92 10 20 37  mov  0x37, %o1
a00aa2e0:  80 a0 60 a0  cmp  %g1, 0xa0
a00aa2e4:  02 80 00 05  be  0xa00aa2f8
a00aa2e8:  94 10 20 a0  mov  0xa0, %o2
a00aa2ec:  90 10 20 00  clr  %o0
a00aa2f0:  92 10 20 37  mov  0x37, %o1
a00aa2f4:  94 10 20 10  mov  0x10, %o2
a00aa2f8:  82 13 c0 00  mov  %o7, %g1
a00aa2fc:  7f ff f6 71  call  0xa00a7cc0
a00aa300:  9e 10 40 00  mov  %g1, %o7
