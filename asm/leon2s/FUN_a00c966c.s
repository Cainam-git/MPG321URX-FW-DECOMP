# leon2s FUN_a00c966c 0xa00c966c-0xa00c972c (192 bytes)
a00c966c:  9d e3 bf 90  save  %sp, -112, %sp
a00c9670:  82 10 20 04  mov  4, %g1
a00c9674:  c2 2f bf f7  stb  %g1, [ %fp + -9 ]
a00c9678:  a2 10 20 0a  mov  0xa, %l1
a00c967c:  a4 0e 20 ff  and  %i0, 0xff, %l2
a00c9680:  7f ff f9 5e  call  0xa00c7bf8
a00c9684:  90 10 00 12  mov  %l2, %o0
a00c9688:  a0 10 00 08  mov  %o0, %l0
a00c968c:  40 3b e0 42  call  0xa0fc1794
a00c9690:  90 10 20 0a  mov  0xa, %o0
a00c9694:  82 0c 20 ff  and  %l0, 0xff, %g1
a00c9698:  80 a0 00 01  cmp  %g0, %g1
a00c969c:  a2 04 7f ff  add  %l1, -1, %l1
a00c96a0:  9a 40 20 00  addx  %g0, 0, %o5
a00c96a4:  82 0c 60 ff  and  %l1, 0xff, %g1
a00c96a8:  80 a0 00 01  cmp  %g0, %g1
a00c96ac:  82 40 20 00  addx  %g0, 0, %g1
a00c96b0:  80 8b 40 01  btst  %o5, %g1
a00c96b4:  32 bf ff f3  bne,a   0xa00c9680
a00c96b8:  a4 0e 20 ff  and  %i0, 0xff, %l2
a00c96bc:  a2 10 20 0a  mov  0xa, %l1
a00c96c0:  92 07 bf f7  add  %fp, -9, %o1
a00c96c4:  7f ff fb 19  call  0xa00c8328
a00c96c8:  90 10 00 12  mov  %l2, %o0
a00c96cc:  a0 10 00 08  mov  %o0, %l0
a00c96d0:  40 3b e0 31  call  0xa0fc1794
a00c96d4:  90 10 20 0a  mov  0xa, %o0
a00c96d8:  90 0c 20 ff  and  %l0, 0xff, %o0
a00c96dc:  80 a0 00 08  cmp  %g0, %o0
a00c96e0:  a2 04 7f ff  add  %l1, -1, %l1
a00c96e4:  82 40 20 00  addx  %g0, 0, %g1
a00c96e8:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00c96ec:  80 a0 00 0d  cmp  %g0, %o5
a00c96f0:  9a 40 20 00  addx  %g0, 0, %o5
a00c96f4:  80 88 40 0d  btst  %g1, %o5
a00c96f8:  12 bf ff f3  bne  0xa00c96c4
a00c96fc:  92 07 bf f7  add  %fp, -9, %o1
a00c9700:  80 a2 20 00  cmp  %o0, 0
a00c9704:  12 80 00 08  bne  0xa00c9724
a00c9708:  b0 10 20 00  clr  %i0
a00c970c:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00c9710:  82 18 60 04  xor  %g1, 4, %g1
a00c9714:  80 a0 00 01  cmp  %g0, %g1
a00c9718:  82 60 20 00  subx  %g0, 0, %g1
a00c971c:  b0 08 7f f2  and  %g1, -14, %i0
a00c9720:  b0 06 20 22  add  %i0, 0x22, %i0
a00c9724:  81 c7 e0 08  ret
a00c9728:  81 e8 00 00  restore
