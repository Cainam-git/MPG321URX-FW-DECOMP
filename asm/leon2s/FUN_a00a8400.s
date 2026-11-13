# leon2s FUN_a00a8400 0xa00a8400-0xa00a8508 (264 bytes)
a00a8400:  9d e3 bf 98  save  %sp, -104, %sp
a00a8404:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a8408:  80 a6 20 07  cmp  %i0, 7
a00a840c:  9e 10 00 19  mov  %i1, %o7
a00a8410:  08 80 00 21  bleu  0xa00a8494
a00a8414:  98 10 00 1a  mov  %i2, %o4
a00a8418:  bb 2e 60 10  sll  %i1, 0x10, %i5
a00a841c:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a8420:  96 10 61 20  or  %g1, 0x120, %o3	! 0xa00b4d20
a00a8424:  b3 37 60 10  srl  %i5, 0x10, %i1
a00a8428:  9e 0e e0 ff  and  %i3, 0xff, %o7
a00a842c:  b4 38 00 1a  xnor  %g0, %i2, %i2
a00a8430:  b8 10 20 00  clr  %i4
a00a8434:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a8438:  82 0f 20 ff  and  %i4, 0xff, %g1
a00a843c:  ba 00 40 01  add  %g1, %g1, %i5
a00a8440:  c2 12 c0 1d  lduh  [ %o3 + %i5 ], %g1
a00a8444:  82 00 40 19  add  %g1, %i1, %g1
a00a8448:  83 28 60 02  sll  %g1, 2, %g1
a00a844c:  82 10 40 0d  or  %g1, %o5, %g1
a00a8450:  b8 07 20 01  inc  %i4
a00a8454:  c2 00 40 00  ld  [ %g1 ], %g1
a00a8458:  b0 0f 20 ff  and  %i4, 0xff, %i0
a00a845c:  80 a3 e0 01  cmp  %o7, 1
a00a8460:  02 80 00 03  be  0xa00a846c
a00a8464:  b6 10 40 0c  or  %g1, %o4, %i3
a00a8468:  b6 08 40 1a  and  %g1, %i2, %i3
a00a846c:  c2 12 c0 1d  lduh  [ %o3 + %i5 ], %g1
a00a8470:  82 00 40 19  add  %g1, %i1, %g1
a00a8474:  83 28 60 02  sll  %g1, 2, %g1
a00a8478:  82 10 40 0d  or  %g1, %o5, %g1
a00a847c:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00a8480:  fa 20 40 00  st  %i5, [ %g1 ]
a00a8484:  80 a6 20 07  cmp  %i0, 7
a00a8488:  08 bf ff ed  bleu  0xa00a843c
a00a848c:  82 0f 20 ff  and  %i4, 0xff, %g1
a00a8490:  30 80 00 1c  b,a   0xa00a8500
a00a8494:  1b 28 02 d3  sethi  %hi(0xa00b4c00), %o5
a00a8498:  bb 2e 60 10  sll  %i1, 0x10, %i5
a00a849c:  b8 13 61 20  or  %o5, 0x120, %i4
a00a84a0:  82 06 00 18  add  %i0, %i0, %g1
a00a84a4:  bb 37 60 10  srl  %i5, 0x10, %i5
a00a84a8:  c2 17 00 01  lduh  [ %i4 + %g1 ], %g1
a00a84ac:  82 00 40 1d  add  %g1, %i5, %g1
a00a84b0:  83 28 60 02  sll  %g1, 2, %g1
a00a84b4:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a84b8:  82 10 40 1d  or  %g1, %i5, %g1
a00a84bc:  f2 00 40 00  ld  [ %g1 ], %i1
a00a84c0:  82 0e e0 ff  and  %i3, 0xff, %g1
a00a84c4:  80 a0 60 01  cmp  %g1, 1
a00a84c8:  02 80 00 04  be  0xa00a84d8
a00a84cc:  b6 16 40 1a  or  %i1, %i2, %i3
a00a84d0:  b6 2e 40 1a  andn  %i1, %i2, %i3
a00a84d4:  b8 13 61 20  or  %o5, 0x120, %i4
a00a84d8:  82 06 00 18  add  %i0, %i0, %g1
a00a84dc:  bb 2b e0 10  sll  %o7, 0x10, %i5
a00a84e0:  bb 37 60 10  srl  %i5, 0x10, %i5
a00a84e4:  c2 17 00 01  lduh  [ %i4 + %g1 ], %g1
a00a84e8:  82 00 40 1d  add  %g1, %i5, %g1
a00a84ec:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a84f0:  83 28 60 02  sll  %g1, 2, %g1
a00a84f4:  82 10 40 1d  or  %g1, %i5, %g1
a00a84f8:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00a84fc:  fa 20 40 00  st  %i5, [ %g1 ]
a00a8500:  81 c7 e0 08  ret
a00a8504:  81 e8 00 00  restore
