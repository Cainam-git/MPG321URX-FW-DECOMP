# leon2s FUN_a00a7d88 0xa00a7d88-0xa00a7dd0 (72 bytes)
a00a7d88:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a7d8c:  9a 02 00 08  add  %o0, %o0, %o5
a00a7d90:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a7d94:  80 a2 20 01  cmp  %o0, 1
a00a7d98:  93 32 60 10  srl  %o1, 0x10, %o1
a00a7d9c:  18 80 00 0b  bgu  0xa00a7dc8
a00a7da0:  90 10 20 00  clr  %o0
a00a7da4:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7da8:  82 10 61 6c  or  %g1, 0x16c, %g1	! 0xa00b4d6c
a00a7dac:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00a7db0:  82 00 40 09  add  %g1, %o1, %g1
a00a7db4:  83 28 60 02  sll  %g1, 2, %g1
a00a7db8:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a7dbc:  82 10 40 0d  or  %g1, %o5, %g1
a00a7dc0:  c2 00 40 00  ld  [ %g1 ], %g1
a00a7dc4:  90 08 60 ff  and  %g1, 0xff, %o0
a00a7dc8:  81 c3 e0 08  retl
a00a7dcc:  01 00 00 00  nop
