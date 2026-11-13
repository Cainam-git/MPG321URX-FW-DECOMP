# leon2s FUN_a00d76ac 0xa00d76ac-0xa00d76f4 (72 bytes)
a00d76ac:  c2 12 00 00  lduh  [ %o0 ], %g1
a00d76b0:  83 30 60 08  srl  %g1, 8, %g1
a00d76b4:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d76b8:  c2 2a 40 00  stb  %g1, [ %o1 ]
a00d76bc:  c2 12 00 00  lduh  [ %o0 ], %g1
a00d76c0:  82 08 60 f1  and  %g1, 0xf1, %g1
a00d76c4:  c2 2a 60 01  stb  %g1, [ %o1 + 1 ]
a00d76c8:  c2 12 20 02  lduh  [ %o0 + 2 ], %g1
a00d76cc:  83 30 60 08  srl  %g1, 8, %g1
a00d76d0:  c2 2a 60 02  stb  %g1, [ %o1 + 2 ]
a00d76d4:  c2 12 20 02  lduh  [ %o0 + 2 ], %g1
a00d76d8:  c2 2a 60 03  stb  %g1, [ %o1 + 3 ]
a00d76dc:  c2 12 20 04  lduh  [ %o0 + 4 ], %g1
a00d76e0:  83 30 60 08  srl  %g1, 8, %g1
a00d76e4:  c2 2a 60 04  stb  %g1, [ %o1 + 4 ]
a00d76e8:  c2 12 20 04  lduh  [ %o0 + 4 ], %g1
a00d76ec:  81 c3 e0 08  retl
a00d76f0:  c2 2a 60 05  stb  %g1, [ %o1 + 5 ]
