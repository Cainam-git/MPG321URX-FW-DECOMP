# leon2s FUN_a0073578 0xa0073578-0xa00735c0 (72 bytes)
a0073578:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a007357c:  98 12 e1 d4  or  %o3, 0x1d4, %o4	! 0xa80789d4
a0073580:  80 a2 20 00  cmp  %o0, 0
a0073584:  12 80 00 0c  bne  0xa00735b4
a0073588:  90 10 00 0c  mov  %o4, %o0
a007358c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a0073590:  da 00 60 38  ld  [ %g1 + 0x38 ], %o5	! 0xa8079038
a0073594:  03 28 02 0c  sethi  %hi(0xa0083000), %g1
a0073598:  82 10 63 24  or  %g1, 0x324, %g1	! 0xa0083324
a007359c:  c0 22 e1 d4  clr  [ %o3 + 0x1d4 ]
a00735a0:  c2 23 20 08  st  %g1, [ %o4 + 8 ]
a00735a4:  da 23 20 04  st  %o5, [ %o4 + 4 ]
a00735a8:  82 13 c0 00  mov  %o7, %g1
a00735ac:  40 00 fa cc  call  0xa00b20dc
a00735b0:  9e 10 40 00  mov  %g1, %o7
a00735b4:  01 00 00 00  nop
a00735b8:  81 c3 e0 08  retl
a00735bc:  01 00 00 00  nop
