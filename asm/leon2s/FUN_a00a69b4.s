# leon2s FUN_a00a69b4 0xa00a69b4-0xa00a69fc (72 bytes)
a00a69b4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a69b8:  9a 02 00 08  add  %o0, %o0, %o5
a00a69bc:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a69c0:  80 a2 20 01  cmp  %o0, 1
a00a69c4:  93 32 60 10  srl  %o1, 0x10, %o1
a00a69c8:  18 80 00 0b  bgu  0xa00a69f4
a00a69cc:  90 10 20 00  clr  %o0
a00a69d0:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a69d4:  82 10 61 98  or  %g1, 0x198, %g1	! 0xa00b4d98
a00a69d8:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00a69dc:  82 00 40 09  add  %g1, %o1, %g1
a00a69e0:  83 28 60 02  sll  %g1, 2, %g1
a00a69e4:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a69e8:  82 10 40 0d  or  %g1, %o5, %g1
a00a69ec:  c2 00 40 00  ld  [ %g1 ], %g1
a00a69f0:  90 08 60 ff  and  %g1, 0xff, %o0
a00a69f4:  81 c3 e0 08  retl
a00a69f8:  01 00 00 00  nop
