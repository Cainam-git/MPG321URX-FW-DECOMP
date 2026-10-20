# leon2s FUN_a00a6668 0xa00a6668-0xa00a66dc (116 bytes)
a00a6668:  82 0a 20 ff  and  %o0, 0xff, %g1
a00a666c:  80 a0 60 02  cmp  %g1, 2
a00a6670:  82 60 20 00  subx  %g0, 0, %g1
a00a6674:  90 0a 00 01  and  %o0, %g1, %o0
a00a6678:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a667c:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a6680:  90 02 00 08  add  %o0, %o0, %o0
a00a6684:  82 10 61 9c  or  %g1, 0x19c, %g1
a00a6688:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a668c:  d8 10 40 08  lduh  [ %g1 + %o0 ], %o4
a00a6690:  93 32 60 10  srl  %o1, 0x10, %o1
a00a6694:  98 03 00 09  add  %o4, %o1, %o4
a00a6698:  9a 03 20 02  add  %o4, 2, %o5
a00a669c:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00a66a0:  82 03 20 01  add  %o4, 1, %g1
a00a66a4:  9b 2b 60 02  sll  %o5, 2, %o5
a00a66a8:  9a 13 40 0b  or  %o5, %o3, %o5
a00a66ac:  83 28 60 02  sll  %g1, 2, %g1
a00a66b0:  d0 03 40 00  ld  [ %o5 ], %o0
a00a66b4:  82 10 40 0b  or  %g1, %o3, %g1
a00a66b8:  c2 00 40 00  ld  [ %g1 ], %g1
a00a66bc:  91 2a 20 08  sll  %o0, 8, %o0
a00a66c0:  99 2b 20 02  sll  %o4, 2, %o4
a00a66c4:  90 12 00 01  or  %o0, %g1, %o0
a00a66c8:  98 13 00 0b  or  %o4, %o3, %o4
a00a66cc:  91 2a 20 08  sll  %o0, 8, %o0
a00a66d0:  c2 03 00 00  ld  [ %o4 ], %g1
a00a66d4:  81 c3 e0 08  retl
a00a66d8:  90 12 00 01  or  %o0, %g1, %o0
