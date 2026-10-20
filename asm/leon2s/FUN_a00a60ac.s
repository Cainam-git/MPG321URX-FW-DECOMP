# leon2s FUN_a00a60ac 0xa00a60ac-0xa00a60d8 (44 bytes)
a00a60ac:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a60b0:  80 a2 20 00  cmp  %o0, 0
a00a60b4:  12 80 00 07  bne  0xa00a60d0
a00a60b8:  82 10 20 02  mov  2, %g1
a00a60bc:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00a60c0:  82 10 60 04  or  %g1, 4, %g1	! 0xa807dc04
a00a60c4:  c2 00 40 08  ld  [ %g1 + %o0 ], %g1
a00a60c8:  c2 00 60 b0  ld  [ %g1 + 0xb0 ], %g1
a00a60cc:  82 08 60 01  and  %g1, 1, %g1
a00a60d0:  81 c3 e0 08  retl
a00a60d4:  90 10 00 01  mov  %g1, %o0
