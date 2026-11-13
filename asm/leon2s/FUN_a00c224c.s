# leon2s FUN_a00c224c 0xa00c224c-0xa00c22a0 (84 bytes)
a00c224c:  d4 0a 00 00  ldub  [ %o0 ], %o2
a00c2250:  96 10 20 00  clr  %o3
a00c2254:  98 0a e0 ff  and  %o3, 0xff, %o4
a00c2258:  82 02 00 0c  add  %o0, %o4, %g1
a00c225c:  96 02 e0 01  inc  %o3
a00c2260:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a00c2264:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00c2268:  80 a3 60 06  cmp  %o5, 6
a00c226c:  08 bf ff fa  bleu  0xa00c2254
a00c2270:  c2 2a 00 0c  stb  %g1, [ %o0 + %o4 ]
a00c2274:  80 a2 a0 ff  cmp  %o2, 0xff
a00c2278:  02 80 00 04  be  0xa00c2288
a00c227c:  82 02 a0 01  add  %o2, 1, %g1
a00c2280:  10 80 00 06  b  0xa00c2298
a00c2284:  c2 2a 20 07  stb  %g1, [ %o0 + 7 ]
a00c2288:  c2 0a 20 06  ldub  [ %o0 + 6 ], %g1
a00c228c:  82 00 60 01  inc  %g1
a00c2290:  c2 2a 20 06  stb  %g1, [ %o0 + 6 ]
a00c2294:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c2298:  81 c3 e0 08  retl
a00c229c:  01 00 00 00  nop
