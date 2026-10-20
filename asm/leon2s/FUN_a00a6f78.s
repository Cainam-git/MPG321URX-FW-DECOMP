# leon2s FUN_a00a6f78 0xa00a6f78-0xa00a6fc0 (72 bytes)
a00a6f78:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a6f7c:  9a 02 00 08  add  %o0, %o0, %o5
a00a6f80:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a6f84:  80 a2 20 01  cmp  %o0, 1
a00a6f88:  93 32 60 10  srl  %o1, 0x10, %o1
a00a6f8c:  18 80 00 0b  bgu  0xa00a6fb8
a00a6f90:  90 10 20 00  clr  %o0
a00a6f94:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a6f98:  82 10 61 90  or  %g1, 0x190, %g1	! 0xa00b4d90
a00a6f9c:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00a6fa0:  82 00 40 09  add  %g1, %o1, %g1
a00a6fa4:  83 28 60 02  sll  %g1, 2, %g1
a00a6fa8:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a6fac:  82 10 40 0d  or  %g1, %o5, %g1
a00a6fb0:  c2 00 40 00  ld  [ %g1 ], %g1
a00a6fb4:  90 08 60 ff  and  %g1, 0xff, %o0
a00a6fb8:  81 c3 e0 08  retl
a00a6fbc:  01 00 00 00  nop
