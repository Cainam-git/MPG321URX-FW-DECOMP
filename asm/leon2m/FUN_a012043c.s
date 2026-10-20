# leon2m FUN_a012043c 0xa012043c-0xa01205c0 (388 bytes)
a012043c:  9d e3 bf 98  save  %sp, -104, %sp
a0120440:  80 a6 20 02  cmp  %i0, 2
a0120444:  b6 60 20 00  subx  %g0, 0, %i3
a0120448:  b8 0e 00 1b  and  %i0, %i3, %i4
a012044c:  35 00 06 8b  sethi  %hi(0x1a2c00), %i2
a0120450:  9a 16 a3 b0  or  %i2, 0x3b0, %o5	! 0x1a2fb0
a0120454:  b8 07 00 1c  add  %i4, %i4, %i4
a0120458:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a012045c:  9e 10 60 28  or  %g1, 0x28, %o7	! 0xcf011428
a0120460:  fa 13 40 1c  lduh  [ %o5 + %i4 ], %i5
a0120464:  f6 03 c0 00  ld  [ %o7 ], %i3
a0120468:  b4 07 60 50  add  %i5, 0x50, %i2
a012046c:  82 16 e0 03  or  %i3, 3, %g1
a0120470:  bb 2e a0 02  sll  %i2, 2, %i5
a0120474:  c2 23 c0 00  st  %g1, [ %o7 ]
a0120478:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a012047c:  b6 17 40 1a  or  %i5, %i2, %i3
a0120480:  82 10 00 1c  mov  %i4, %g1
a0120484:  f8 06 c0 00  ld  [ %i3 ], %i4
a0120488:  fa 13 40 01  lduh  [ %o5 + %g1 ], %i5
a012048c:  f6 03 c0 00  ld  [ %o7 ], %i3
a0120490:  82 07 60 51  add  %i5, 0x51, %g1
a0120494:  ba 16 e0 03  or  %i3, 3, %i5
a0120498:  b7 28 60 02  sll  %g1, 2, %i3
a012049c:  82 16 c0 1a  or  %i3, %i2, %g1
a01204a0:  fa 23 c0 00  st  %i5, [ %o7 ]
a01204a4:  b4 0f 20 ff  and  %i4, 0xff, %i2
a01204a8:  f6 00 40 00  ld  [ %g1 ], %i3
a01204ac:  b9 36 a0 06  srl  %i2, 6, %i4
a01204b0:  ba 10 20 04  mov  4, %i5
a01204b4:  b5 2f 40 1c  sll  %i5, %i4, %i2
a01204b8:  92 10 00 19  mov  %i1, %o1
a01204bc:  b6 8e e0 01  andcc  %i3, 1, %i3
a01204c0:  12 80 00 3e  bne  0xa01205b8
a01204c4:  82 10 20 00  clr  %g1
a01204c8:  39 2a 00 b6  sethi  %hi(0xa802d800), %i4
a01204cc:  82 17 20 44  or  %i4, 0x44, %g1	! 0xa802d844
a01204d0:  bb 2e 20 02  sll  %i0, 2, %i5
a01204d4:  b2 07 40 01  add  %i5, %g1, %i1
a01204d8:  c0 30 40 1d  clrh  [ %g1 + %i5 ]
a01204dc:  94 0e a0 ff  and  %i2, 0xff, %o2
a01204e0:  c0 36 60 02  clrh  [ %i1 + 2 ]
a01204e4:  80 a6 c0 0a  cmp  %i3, %o2
a01204e8:  1a 80 00 33  bcc  0xa01205b4
a01204ec:  96 10 20 00  clr  %o3
a01204f0:  98 10 00 0d  mov  %o5, %o4
a01204f4:  9a 10 20 00  clr  %o5
a01204f8:  80 a6 20 02  cmp  %i0, 2
a01204fc:  b4 60 20 00  subx  %g0, 0, %i2
a0120500:  82 0e 00 1a  and  %i0, %i2, %g1
a0120504:  ba 00 40 01  add  %g1, %g1, %i5
a0120508:  f2 13 00 1d  lduh  [ %o4 + %i5 ], %i1
a012050c:  80 a6 20 02  cmp  %i0, 2
a0120510:  b4 60 20 00  subx  %g0, 0, %i2
a0120514:  b6 06 60 57  add  %i1, 0x57, %i3
a0120518:  f8 03 c0 00  ld  [ %o7 ], %i4
a012051c:  b2 0e 00 1a  and  %i0, %i2, %i1
a0120520:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a0120524:  82 17 20 03  or  %i4, 3, %g1
a0120528:  bb 2e e0 02  sll  %i3, 2, %i5
a012052c:  c2 23 c0 00  st  %g1, [ %o7 ]
a0120530:  b8 17 40 1a  or  %i5, %i2, %i4
a0120534:  b6 06 40 19  add  %i1, %i1, %i3
a0120538:  f2 07 00 00  ld  [ %i4 ], %i1
a012053c:  c2 03 c0 00  ld  [ %o7 ], %g1
a0120540:  fa 13 00 1b  lduh  [ %o4 + %i3 ], %i5
a0120544:  b8 07 60 57  add  %i5, 0x57, %i4
a0120548:  82 10 60 03  or  %g1, 3, %g1
a012054c:  c2 23 c0 00  st  %g1, [ %o7 ]
a0120550:  bb 2f 20 02  sll  %i4, 2, %i5
a0120554:  b8 17 40 1a  or  %i5, %i2, %i4
a0120558:  82 10 00 1b  mov  %i3, %g1
a012055c:  f6 07 00 00  ld  [ %i4 ], %i3
a0120560:  fa 13 00 01  lduh  [ %o4 + %g1 ], %i5
a0120564:  f8 03 c0 00  ld  [ %o7 ], %i4
a0120568:  82 07 60 57  add  %i5, 0x57, %g1
a012056c:  ba 17 20 03  or  %i4, 3, %i5
a0120570:  b9 28 60 02  sll  %g1, 2, %i4
a0120574:  fa 23 c0 00  st  %i5, [ %o7 ]
a0120578:  82 17 00 1a  or  %i4, %i2, %g1
a012057c:  f8 00 40 00  ld  [ %g1 ], %i4
a0120580:  ba 0f 20 ff  and  %i4, 0xff, %i5
a0120584:  b4 0e e0 ff  and  %i3, 0xff, %i2
a0120588:  b9 2e a0 08  sll  %i2, 8, %i4
a012058c:  83 2f 60 10  sll  %i5, 0x10, %g1
a0120590:  b5 2b 60 02  sll  %o5, 2, %i2
a0120594:  ba 10 40 1c  or  %g1, %i4, %i5
a0120598:  b2 0e 60 ff  and  %i1, 0xff, %i1
a012059c:  96 02 e0 01  inc  %o3
a01205a0:  b6 17 40 19  or  %i5, %i1, %i3
a01205a4:  9a 0a e0 ff  and  %o3, 0xff, %o5
a01205a8:  80 a3 40 0a  cmp  %o5, %o2
a01205ac:  0a bf ff d3  bcs  0xa01204f8
a01205b0:  f6 22 40 1a  st  %i3, [ %o1 + %i2 ]
a01205b4:  82 10 20 01  mov  1, %g1
a01205b8:  81 c7 e0 08  ret
a01205bc:  91 e8 00 01  restore  %g0, %g1, %o0
