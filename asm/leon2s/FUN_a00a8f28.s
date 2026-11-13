# leon2s FUN_a00a8f28 0xa00a8f28-0xa00a8f8c (100 bytes)
a00a8f28:  c2 0a 20 01  ldub  [ %o0 + 1 ], %g1
a00a8f2c:  c2 2a 40 00  stb  %g1, [ %o1 ]
a00a8f30:  da 0a 20 04  ldub  [ %o0 + 4 ], %o5
a00a8f34:  82 00 40 0d  add  %g1, %o5, %g1
a00a8f38:  da 2a 60 01  stb  %o5, [ %o1 + 1 ]
a00a8f3c:  da 0a 20 05  ldub  [ %o0 + 5 ], %o5
a00a8f40:  82 00 40 0d  add  %g1, %o5, %g1
a00a8f44:  c2 2a 60 03  stb  %g1, [ %o1 + 3 ]
a00a8f48:  da 2a 60 02  stb  %o5, [ %o1 + 2 ]
a00a8f4c:  94 10 20 00  clr  %o2
a00a8f50:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00a8f54:  82 02 00 0d  add  %o0, %o5, %g1
a00a8f58:  d8 08 60 06  ldub  [ %g1 + 6 ], %o4
a00a8f5c:  c2 0a 60 03  ldub  [ %o1 + 3 ], %g1
a00a8f60:  96 00 40 0c  add  %g1, %o4, %o3
a00a8f64:  94 02 a0 01  inc  %o2
a00a8f68:  9a 02 40 0d  add  %o1, %o5, %o5
a00a8f6c:  82 0a a0 ff  and  %o2, 0xff, %g1
a00a8f70:  d8 2b 60 04  stb  %o4, [ %o5 + 4 ]
a00a8f74:  80 a0 60 09  cmp  %g1, 9
a00a8f78:  08 bf ff f6  bleu  0xa00a8f50
a00a8f7c:  d6 2a 60 03  stb  %o3, [ %o1 + 3 ]
a00a8f80:  82 20 00 0b  neg  %o3, %g1
a00a8f84:  81 c3 e0 08  retl
a00a8f88:  c2 2a 60 03  stb  %g1, [ %o1 + 3 ]
