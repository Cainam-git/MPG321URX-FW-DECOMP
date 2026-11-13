# leon2s FUN_a00a71b4 0xa00a71b4-0xa00a71fc (72 bytes)
a00a71b4:  82 0a 20 ff  and  %o0, 0xff, %g1
a00a71b8:  80 a0 60 04  cmp  %g1, 4
a00a71bc:  82 60 20 00  subx  %g0, 0, %g1
a00a71c0:  90 0a 00 01  and  %o0, %g1, %o0
a00a71c4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a71c8:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a71cc:  90 02 00 08  add  %o0, %o0, %o0
a00a71d0:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a71d4:  82 10 61 88  or  %g1, 0x188, %g1
a00a71d8:  c2 10 40 08  lduh  [ %g1 + %o0 ], %g1
a00a71dc:  93 32 60 10  srl  %o1, 0x10, %o1
a00a71e0:  82 00 40 09  add  %g1, %o1, %g1
a00a71e4:  83 28 60 02  sll  %g1, 2, %g1
a00a71e8:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a71ec:  82 10 40 0d  or  %g1, %o5, %g1
a00a71f0:  d0 00 40 00  ld  [ %g1 ], %o0
a00a71f4:  81 c3 e0 08  retl
a00a71f8:  90 0a 20 ff  and  %o0, 0xff, %o0
