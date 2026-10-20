# leon2s FUN_a00d76f4 0xa00d76f4-0xa00d7734 (64 bytes)
a00d76f4:  c2 12 00 00  lduh  [ %o0 ], %g1
a00d76f8:  83 30 60 08  srl  %g1, 8, %g1
a00d76fc:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d7700:  c2 2a 40 00  stb  %g1, [ %o1 ]
a00d7704:  c2 12 00 00  lduh  [ %o0 ], %g1
a00d7708:  82 08 60 f0  and  %g1, 0xf0, %g1
a00d770c:  c2 2a 60 01  stb  %g1, [ %o1 + 1 ]
a00d7710:  c2 12 20 02  lduh  [ %o0 + 2 ], %g1
a00d7714:  83 30 60 09  srl  %g1, 9, %g1
a00d7718:  c2 2a 60 02  stb  %g1, [ %o1 + 2 ]
a00d771c:  c2 12 20 04  lduh  [ %o0 + 4 ], %g1
a00d7720:  83 30 60 08  srl  %g1, 8, %g1
a00d7724:  c2 2a 60 03  stb  %g1, [ %o1 + 3 ]
a00d7728:  c2 12 20 04  lduh  [ %o0 + 4 ], %g1
a00d772c:  81 c3 e0 08  retl
a00d7730:  c2 2a 60 04  stb  %g1, [ %o1 + 4 ]
