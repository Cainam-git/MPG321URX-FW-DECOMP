# leon2s FUN_a00c83e4 0xa00c83e4-0xa00c8444 (96 bytes)
a00c83e4:  92 10 20 00  clr  %o1
a00c83e8:  96 10 00 09  mov  %o1, %o3
a00c83ec:  94 0a e0 ff  and  %o3, 0xff, %o2
a00c83f0:  da 0a 00 0a  ldub  [ %o0 + %o2 ], %o5
a00c83f4:  80 a3 60 00  cmp  %o5, 0
a00c83f8:  02 80 00 09  be  0xa00c841c
a00c83fc:  98 10 20 00  clr  %o4
a00c8400:  82 03 7f ff  add  %o5, -1, %g1
a00c8404:  82 08 40 0d  and  %g1, %o5, %g1
a00c8408:  80 88 60 ff  btst  0xff, %g1
a00c840c:  98 03 20 01  inc  %o4
a00c8410:  12 bf ff fc  bne  0xa00c8400
a00c8414:  9a 10 00 01  mov  %g1, %o5
a00c8418:  c2 2a 00 0a  stb  %g1, [ %o0 + %o2 ]
a00c841c:  96 02 e0 01  inc  %o3
a00c8420:  82 0a e0 ff  and  %o3, 0xff, %g1
a00c8424:  80 a0 60 04  cmp  %g1, 4
a00c8428:  08 bf ff f1  bleu  0xa00c83ec
a00c842c:  92 02 40 0c  add  %o1, %o4, %o1
a00c8430:  82 0a 60 ff  and  %o1, 0xff, %g1
a00c8434:  82 18 60 14  xor  %g1, 0x14, %g1
a00c8438:  80 a0 00 01  cmp  %g0, %g1
a00c843c:  81 c3 e0 08  retl
a00c8440:  90 60 3f ff  subx  %g0, -1, %o0
