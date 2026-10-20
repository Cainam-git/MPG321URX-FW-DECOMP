# leon2s FUN_a00a8ec4 0xa00a8ec4-0xa00a8f28 (100 bytes)
a00a8ec4:  c2 0a 20 01  ldub  [ %o0 + 1 ], %g1
a00a8ec8:  c2 2a 40 00  stb  %g1, [ %o1 ]
a00a8ecc:  da 0a 20 04  ldub  [ %o0 + 4 ], %o5
a00a8ed0:  82 00 40 0d  add  %g1, %o5, %g1
a00a8ed4:  da 2a 60 01  stb  %o5, [ %o1 + 1 ]
a00a8ed8:  da 0a 20 05  ldub  [ %o0 + 5 ], %o5
a00a8edc:  82 00 40 0d  add  %g1, %o5, %g1
a00a8ee0:  c2 2a 60 03  stb  %g1, [ %o1 + 3 ]
a00a8ee4:  da 2a 60 02  stb  %o5, [ %o1 + 2 ]
a00a8ee8:  94 10 20 00  clr  %o2
a00a8eec:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00a8ef0:  82 02 00 0d  add  %o0, %o5, %g1
a00a8ef4:  d8 08 60 06  ldub  [ %g1 + 6 ], %o4
a00a8ef8:  c2 0a 60 03  ldub  [ %o1 + 3 ], %g1
a00a8efc:  96 00 40 0c  add  %g1, %o4, %o3
a00a8f00:  94 02 a0 01  inc  %o2
a00a8f04:  9a 02 40 0d  add  %o1, %o5, %o5
a00a8f08:  82 0a a0 ff  and  %o2, 0xff, %g1
a00a8f0c:  d8 2b 60 04  stb  %o4, [ %o5 + 4 ]
a00a8f10:  80 a0 60 1a  cmp  %g1, 0x1a
a00a8f14:  08 bf ff f6  bleu  0xa00a8eec
a00a8f18:  d6 2a 60 03  stb  %o3, [ %o1 + 3 ]
a00a8f1c:  82 20 00 0b  neg  %o3, %g1
a00a8f20:  81 c3 e0 08  retl
a00a8f24:  c2 2a 60 03  stb  %g1, [ %o1 + 3 ]
