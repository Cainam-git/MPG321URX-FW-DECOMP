# leon2s FUN_a00c2488 0xa00c2488-0xa00c255c (212 bytes)
a00c2488:  9d e3 bf 98  save  %sp, -104, %sp
a00c248c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c2490:  90 10 00 18  mov  %i0, %o0
a00c2494:  40 3b d6 c3  call  0xa0fb7fa0
a00c2498:  92 10 20 02  mov  2, %o1
a00c249c:  80 8a 20 20  btst  0x20, %o0
a00c24a0:  02 80 00 2c  be  0xa00c2550
a00c24a4:  a0 10 20 00  clr  %l0
a00c24a8:  90 10 00 18  mov  %i0, %o0
a00c24ac:  92 10 20 02  mov  2, %o1
a00c24b0:  40 3b d6 8c  call  0xa0fb7ee0
a00c24b4:  94 10 20 40  mov  0x40, %o2
a00c24b8:  90 10 00 18  mov  %i0, %o0
a00c24bc:  92 10 20 03  mov  3, %o1
a00c24c0:  40 3b d6 88  call  0xa0fb7ee0
a00c24c4:  94 10 20 00  clr  %o2
a00c24c8:  90 10 00 18  mov  %i0, %o0
a00c24cc:  92 10 20 04  mov  4, %o1
a00c24d0:  40 3b d6 84  call  0xa0fb7ee0
a00c24d4:  94 10 20 66  mov  0x66, %o2
a00c24d8:  90 10 00 18  mov  %i0, %o0
a00c24dc:  92 10 20 05  mov  5, %o1
a00c24e0:  40 3b d6 80  call  0xa0fb7ee0
a00c24e4:  94 10 20 80  mov  0x80, %o2
a00c24e8:  90 10 00 18  mov  %i0, %o0
a00c24ec:  92 10 20 05  mov  5, %o1
a00c24f0:  40 3b d6 7c  call  0xa0fb7ee0
a00c24f4:  94 10 20 00  clr  %o2
a00c24f8:  90 10 00 18  mov  %i0, %o0
a00c24fc:  40 3b d6 a9  call  0xa0fb7fa0
a00c2500:  92 10 20 07  mov  7, %o1
a00c2504:  a2 10 00 10  mov  %l0, %l1
a00c2508:  92 10 20 06  mov  6, %o1
a00c250c:  40 3b d6 a5  call  0xa0fb7fa0
a00c2510:  90 10 00 18  mov  %i0, %o0
a00c2514:  82 0c 60 ff  and  %l1, 0xff, %g1
a00c2518:  a0 10 20 3f  mov  0x3f, %l0
a00c251c:  a0 24 00 01  sub  %l0, %g1, %l0
a00c2520:  a0 04 00 10  add  %l0, %l0, %l0
a00c2524:  82 04 00 19  add  %l0, %i1, %g1
a00c2528:  d0 28 60 01  stb  %o0, [ %g1 + 1 ]
a00c252c:  90 10 00 18  mov  %i0, %o0
a00c2530:  40 3b d6 9c  call  0xa0fb7fa0
a00c2534:  92 10 20 07  mov  7, %o1
a00c2538:  a2 04 60 01  inc  %l1
a00c253c:  82 0c 60 ff  and  %l1, 0xff, %g1
a00c2540:  80 a0 60 3f  cmp  %g1, 0x3f
a00c2544:  08 bf ff f1  bleu  0xa00c2508
a00c2548:  d0 2e 40 10  stb  %o0, [ %i1 + %l0 ]
a00c254c:  a0 10 20 01  mov  1, %l0
a00c2550:  b0 0c 20 01  and  %l0, 1, %i0
a00c2554:  81 c7 e0 08  ret
a00c2558:  81 e8 00 00  restore
