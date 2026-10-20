# leon2m FUN_a00a8440 0xa00a8440-0xa00a8570 (304 bytes)
a00a8440:  9d e3 bf 98  save  %sp, -104, %sp
a00a8444:  90 10 21 11  mov  0x111, %o0
a00a8448:  40 02 79 c2  call  0xa0146b50
a00a844c:  92 10 20 00  clr  %o1
a00a8450:  90 10 20 00  clr  %o0
a00a8454:  92 10 20 00  clr  %o1
a00a8458:  40 02 79 c5  call  0xa0146b6c
a00a845c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00a8460:  a0 14 22 90  or  %l0, 0x290, %l0	! 0xa802d290
a00a8464:  d4 0c 20 08  ldub  [ %l0 + 8 ], %o2
a00a8468:  82 02 a0 91  add  %o2, 0x91, %g1
a00a846c:  93 28 60 10  sll  %g1, 0x10, %o1
a00a8470:  11 00 06 3a  sethi  %hi(0x18e800), %o0
a00a8474:  93 32 60 10  srl  %o1, 0x10, %o1
a00a8478:  7f ff ec f3  call  0xa00a3844
a00a847c:  90 12 21 f8  or  %o0, 0x1f8, %o0
a00a8480:  98 10 00 08  mov  %o0, %o4
a00a8484:  90 10 20 00  clr  %o0
a00a8488:  92 10 20 2a  mov  0x2a, %o1
a00a848c:  94 10 20 06  mov  6, %o2
a00a8490:  96 10 20 01  mov  1, %o3
a00a8494:  7f ff eb 44  call  0xa00a31a4
a00a8498:  9a 10 20 00  clr  %o5
a00a849c:  b8 10 20 01  mov  1, %i4
a00a84a0:  ba 10 20 01  mov  1, %i5
a00a84a4:  37 00 06 4c  sethi  %hi(0x193000), %i3
a00a84a8:  93 2f 60 03  sll  %i5, 3, %o1
a00a84ac:  90 22 40 1d  sub  %o1, %i5, %o0
a00a84b0:  b5 2a 20 02  sll  %o0, 2, %i2
a00a84b4:  b0 06 80 1d  add  %i2, %i5, %i0
a00a84b8:  f2 0c 20 08  ldub  [ %l0 + 8 ], %i1
a00a84bc:  9e 06 00 19  add  %i0, %i1, %o7
a00a84c0:  9a 03 ff e3  add  %o7, -29, %o5
a00a84c4:  99 2b 60 10  sll  %o5, 0x10, %o4
a00a84c8:  93 33 20 10  srl  %o4, 0x10, %o1
a00a84cc:  7f ff ec de  call  0xa00a3844
a00a84d0:  90 16 e2 48  or  %i3, 0x248, %o0
a00a84d4:  96 07 40 1d  add  %i5, %i5, %o3
a00a84d8:  98 10 00 08  mov  %o0, %o4
a00a84dc:  94 02 e0 06  add  %o3, 6, %o2
a00a84e0:  90 10 20 00  clr  %o0
a00a84e4:  92 10 20 2a  mov  0x2a, %o1
a00a84e8:  96 10 20 01  mov  1, %o3
a00a84ec:  9a 10 20 00  clr  %o5
a00a84f0:  7f ff eb 2d  call  0xa00a31a4
a00a84f4:  b8 07 20 01  inc  %i4
a00a84f8:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00a84fc:  80 a7 60 02  cmp  %i5, 2
a00a8500:  08 bf ff eb  bleu  0xa00a84ac
a00a8504:  93 2f 60 03  sll  %i5, 3, %o1
a00a8508:  d4 04 20 a8  ld  [ %l0 + 0xa8 ], %o2
a00a850c:  83 32 a0 0c  srl  %o2, 0xc, %g1
a00a8510:  ba 08 60 01  and  %g1, 1, %i5
a00a8514:  b8 07 60 01  add  %i5, 1, %i4
a00a8518:  82 0f 20 ff  and  %i4, 0xff, %g1
a00a851c:  b6 00 40 01  add  %g1, %g1, %i3
a00a8520:  80 a0 60 06  cmp  %g1, 6
a00a8524:  08 80 00 04  bleu  0xa00a8534
a00a8528:  9a 06 e0 06  add  %i3, 6, %o5
a00a852c:  a0 00 40 01  add  %g1, %g1, %l0
a00a8530:  9a 04 3f f8  add  %l0, -8, %o5
a00a8534:  b4 0b 60 ff  and  %o5, 0xff, %i2
a00a8538:  90 10 20 00  clr  %o0
a00a853c:  92 10 20 28  mov  0x28, %o1
a00a8540:  94 10 00 1a  mov  %i2, %o2
a00a8544:  96 10 20 01  mov  1, %o3
a00a8548:  98 10 20 0f  mov  0xf, %o4
a00a854c:  40 02 79 75  call  0xa0146b20
a00a8550:  9a 10 20 00  clr  %o5
a00a8554:  b0 10 20 00  clr  %i0
a00a8558:  b2 10 20 29  mov  0x29, %i1
a00a855c:  b6 10 20 01  mov  1, %i3
a00a8560:  b8 10 20 10  mov  0x10, %i4
a00a8564:  40 02 79 6f  call  0xa0146b20
a00a8568:  9b e8 20 00  restore  %g0, 0, %o5
a00a856c:  01 00 00 00  nop
