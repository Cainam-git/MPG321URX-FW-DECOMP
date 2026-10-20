# leon2s FUN_a00d787c 0xa00d787c-0xa00d78d8 (92 bytes)
a00d787c:  c2 0a 00 00  ldub  [ %o0 ], %g1
a00d7880:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d7884:  c2 2a 40 00  stb  %g1, [ %o1 ]
a00d7888:  c2 0a 20 01  ldub  [ %o0 + 1 ], %g1
a00d788c:  82 08 60 f8  and  %g1, 0xf8, %g1
a00d7890:  c2 2a 60 01  stb  %g1, [ %o1 + 1 ]
a00d7894:  c2 0a 20 02  ldub  [ %o0 + 2 ], %g1
a00d7898:  82 08 60 f9  and  %g1, 0xf9, %g1
a00d789c:  c2 2a 60 02  stb  %g1, [ %o1 + 2 ]
a00d78a0:  c2 0a 20 03  ldub  [ %o0 + 3 ], %g1
a00d78a4:  c2 2a 60 03  stb  %g1, [ %o1 + 3 ]
a00d78a8:  96 10 20 00  clr  %o3
a00d78ac:  82 0a e0 ff  and  %o3, 0xff, %g1
a00d78b0:  9a 02 00 01  add  %o0, %g1, %o5
a00d78b4:  d8 0b 60 04  ldub  [ %o5 + 4 ], %o4
a00d78b8:  96 02 e0 01  inc  %o3
a00d78bc:  82 02 40 01  add  %o1, %g1, %g1
a00d78c0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00d78c4:  80 a3 60 13  cmp  %o5, 0x13
a00d78c8:  08 bf ff f9  bleu  0xa00d78ac
a00d78cc:  d8 28 60 04  stb  %o4, [ %g1 + 4 ]
a00d78d0:  81 c3 e0 08  retl
a00d78d4:  01 00 00 00  nop
