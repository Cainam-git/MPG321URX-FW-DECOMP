# leon2s FUN_a00a657c 0xa00a657c-0xa00a65c4 (72 bytes)
a00a657c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a6580:  9a 02 00 08  add  %o0, %o0, %o5
a00a6584:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a6588:  80 a2 20 01  cmp  %o0, 1
a00a658c:  93 32 60 10  srl  %o1, 0x10, %o1
a00a6590:  18 80 00 0b  bgu  0xa00a65bc
a00a6594:  90 10 20 00  clr  %o0
a00a6598:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a659c:  82 10 61 9c  or  %g1, 0x19c, %g1	! 0xa00b4d9c
a00a65a0:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00a65a4:  82 00 40 09  add  %g1, %o1, %g1
a00a65a8:  83 28 60 02  sll  %g1, 2, %g1
a00a65ac:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a65b0:  82 10 40 0d  or  %g1, %o5, %g1
a00a65b4:  c2 00 40 00  ld  [ %g1 ], %g1
a00a65b8:  90 08 60 ff  and  %g1, 0xff, %o0
a00a65bc:  81 c3 e0 08  retl
a00a65c0:  01 00 00 00  nop
