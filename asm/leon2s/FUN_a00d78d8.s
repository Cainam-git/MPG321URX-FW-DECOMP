# leon2s FUN_a00d78d8 0xa00d78d8-0xa00d791c (68 bytes)
a00d78d8:  c2 0a 00 00  ldub  [ %o0 ], %g1
a00d78dc:  c2 2a 40 00  stb  %g1, [ %o1 ]
a00d78e0:  96 10 20 00  clr  %o3
a00d78e4:  82 0a e0 ff  and  %o3, 0xff, %g1
a00d78e8:  9a 02 00 01  add  %o0, %g1, %o5
a00d78ec:  d8 0b 60 01  ldub  [ %o5 + 1 ], %o4
a00d78f0:  96 02 e0 01  inc  %o3
a00d78f4:  82 02 40 01  add  %o1, %g1, %g1
a00d78f8:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00d78fc:  80 a3 60 0f  cmp  %o5, 0xf
a00d7900:  08 bf ff f9  bleu  0xa00d78e4
a00d7904:  d8 28 60 01  stb  %o4, [ %g1 + 1 ]
a00d7908:  c2 0a 20 11  ldub  [ %o0 + 0x11 ], %g1
a00d790c:  c2 2a 60 11  stb  %g1, [ %o1 + 0x11 ]
a00d7910:  c2 0a 20 12  ldub  [ %o0 + 0x12 ], %g1
a00d7914:  81 c3 e0 08  retl
a00d7918:  c2 2a 60 12  stb  %g1, [ %o1 + 0x12 ]
