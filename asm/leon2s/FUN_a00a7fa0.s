# leon2s FUN_a00a7fa0 0xa00a7fa0-0xa00a7fd8 (56 bytes)
a00a7fa0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a7fa4:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7fa8:  90 02 00 08  add  %o0, %o0, %o0
a00a7fac:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a7fb0:  82 10 61 5c  or  %g1, 0x15c, %g1
a00a7fb4:  c2 10 40 08  lduh  [ %g1 + %o0 ], %g1
a00a7fb8:  93 32 60 10  srl  %o1, 0x10, %o1
a00a7fbc:  82 00 40 09  add  %g1, %o1, %g1
a00a7fc0:  83 28 60 02  sll  %g1, 2, %g1
a00a7fc4:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a7fc8:  82 10 40 0d  or  %g1, %o5, %g1
a00a7fcc:  d0 00 40 00  ld  [ %g1 ], %o0
a00a7fd0:  81 c3 e0 08  retl
a00a7fd4:  90 0a 20 ff  and  %o0, 0xff, %o0
