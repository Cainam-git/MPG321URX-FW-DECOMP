# leon2s FUN_a00a6da8 0xa00a6da8-0xa00a6e10 (104 bytes)
a00a6da8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a6dac:  9a 02 00 08  add  %o0, %o0, %o5
a00a6db0:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a6db4:  80 a2 20 01  cmp  %o0, 1
a00a6db8:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a00a6dbc:  93 32 60 10  srl  %o1, 0x10, %o1
a00a6dc0:  18 80 00 12  bgu  0xa00a6e08
a00a6dc4:  90 10 20 00  clr  %o0
a00a6dc8:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a6dcc:  82 10 61 94  or  %g1, 0x194, %g1	! 0xa00b4d94
a00a6dd0:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00a6dd4:  82 00 40 09  add  %g1, %o1, %g1
a00a6dd8:  9a 00 60 01  add  %g1, 1, %o5
a00a6ddc:  83 28 60 02  sll  %g1, 2, %g1
a00a6de0:  9b 2b 60 02  sll  %o5, 2, %o5
a00a6de4:  82 10 40 0c  or  %g1, %o4, %g1
a00a6de8:  9a 13 40 0c  or  %o5, %o4, %o5
a00a6dec:  d8 00 40 00  ld  [ %g1 ], %o4
a00a6df0:  c2 03 40 00  ld  [ %o5 ], %g1
a00a6df4:  83 28 60 08  sll  %g1, 8, %g1
a00a6df8:  98 0b 20 ff  and  %o4, 0xff, %o4
a00a6dfc:  82 10 40 0c  or  %g1, %o4, %g1
a00a6e00:  83 28 60 10  sll  %g1, 0x10, %g1
a00a6e04:  91 30 60 10  srl  %g1, 0x10, %o0
a00a6e08:  81 c3 e0 08  retl
a00a6e0c:  01 00 00 00  nop
