# leon2m FUN_a00f232c 0xa00f232c-0xa00f2488 (348 bytes)
a00f232c:  9d e3 bf 98  save  %sp, -104, %sp
a00f2330:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f2334:  9e 10 00 19  mov  %i1, %o7
a00f2338:  80 a6 20 08  cmp  %i0, 8
a00f233c:  02 80 00 1d  be  0xa00f23b0
a00f2340:  b2 10 00 1a  mov  %i2, %i1
a00f2344:  80 a6 20 07  cmp  %i0, 7
a00f2348:  18 80 00 4e  bgu  0xa00f2480
a00f234c:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f2350:  b8 13 62 ec  or  %o5, 0x2ec, %i4	! 0x19a2ec
a00f2354:  b2 06 00 18  add  %i0, %i0, %i1
a00f2358:  c2 17 00 19  lduh  [ %i4 + %i1 ], %g1
a00f235c:  b2 0b e0 ff  and  %o7, 0xff, %i1
a00f2360:  82 00 40 19  add  %g1, %i1, %g1
a00f2364:  b9 28 60 02  sll  %g1, 2, %i4
a00f2368:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00f236c:  82 17 00 1d  or  %i4, %i5, %g1
a00f2370:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f2374:  c2 00 40 00  ld  [ %g1 ], %g1
a00f2378:  80 a7 20 01  cmp  %i4, 1
a00f237c:  02 80 00 03  be  0xa00f2388
a00f2380:  b6 10 40 1a  or  %g1, %i2, %i3
a00f2384:  b6 28 40 1a  andn  %g1, %i2, %i3
a00f2388:  82 13 62 ec  or  %o5, 0x2ec, %g1
a00f238c:  b4 06 00 18  add  %i0, %i0, %i2
a00f2390:  f0 10 40 1a  lduh  [ %g1 + %i2 ], %i0
a00f2394:  b8 06 00 19  add  %i0, %i1, %i4
a00f2398:  83 2f 20 02  sll  %i4, 2, %g1
a00f239c:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00f23a0:  b0 10 40 1d  or  %g1, %i5, %i0
a00f23a4:  b4 0e e0 ff  and  %i3, 0xff, %i2
a00f23a8:  f4 26 00 00  st  %i2, [ %i0 ]
a00f23ac:  30 80 00 35  b,a   0xa00f2480
a00f23b0:  b4 0e e0 ff  and  %i3, 0xff, %i2
a00f23b4:  37 00 06 68  sethi  %hi(0x19a000), %i3
a00f23b8:  80 a6 a0 01  cmp  %i2, 1
a00f23bc:  b4 0b e0 ff  and  %o7, 0xff, %i2
a00f23c0:  9a 16 e2 ec  or  %i3, 0x2ec, %o5
a00f23c4:  b6 10 20 00  clr  %i3
a00f23c8:  b8 10 20 00  clr  %i4
a00f23cc:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a00f23d0:  02 80 00 11  be  0xa00f2414
a00f23d4:  b0 38 00 19  xnor  %g0, %i1, %i0
a00f23d8:  ba 07 00 1c  add  %i4, %i4, %i5
a00f23dc:  f2 13 40 1d  lduh  [ %o5 + %i5 ], %i1
a00f23e0:  82 06 40 1a  add  %i1, %i2, %g1
a00f23e4:  bb 28 60 02  sll  %g1, 2, %i5
a00f23e8:  ba 17 40 0f  or  %i5, %o7, %i5
a00f23ec:  f8 07 40 00  ld  [ %i5 ], %i4
a00f23f0:  b2 0f 00 18  and  %i4, %i0, %i1
a00f23f4:  b6 06 e0 01  inc  %i3
a00f23f8:  82 0e 60 ff  and  %i1, 0xff, %g1
a00f23fc:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f2400:  c2 27 40 00  st  %g1, [ %i5 ]
a00f2404:  80 a7 20 07  cmp  %i4, 7
a00f2408:  08 bf ff f5  bleu  0xa00f23dc
a00f240c:  ba 07 00 1c  add  %i4, %i4, %i5
a00f2410:  30 80 00 1c  b,a   0xa00f2480
a00f2414:  82 07 00 1c  add  %i4, %i4, %g1
a00f2418:  f8 13 40 01  lduh  [ %o5 + %g1 ], %i4
a00f241c:  b0 07 00 1a  add  %i4, %i2, %i0
a00f2420:  bb 2e 20 02  sll  %i0, 2, %i5
a00f2424:  ba 17 40 0f  or  %i5, %o7, %i5
a00f2428:  c2 07 40 00  ld  [ %i5 ], %g1
a00f242c:  b8 10 40 19  or  %g1, %i1, %i4
a00f2430:  b0 0f 20 ff  and  %i4, 0xff, %i0
a00f2434:  b6 06 e0 01  inc  %i3
a00f2438:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f243c:  f0 27 40 00  st  %i0, [ %i5 ]
a00f2440:  80 a7 20 07  cmp  %i4, 7
a00f2444:  18 80 00 0f  bgu  0xa00f2480
a00f2448:  82 07 00 1c  add  %i4, %i4, %g1
a00f244c:  f8 13 40 01  lduh  [ %o5 + %g1 ], %i4
a00f2450:  b0 07 00 1a  add  %i4, %i2, %i0
a00f2454:  bb 2e 20 02  sll  %i0, 2, %i5
a00f2458:  ba 17 40 0f  or  %i5, %o7, %i5
a00f245c:  c2 07 40 00  ld  [ %i5 ], %g1
a00f2460:  b8 10 40 19  or  %g1, %i1, %i4
a00f2464:  b0 0f 20 ff  and  %i4, 0xff, %i0
a00f2468:  b6 06 e0 01  inc  %i3
a00f246c:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f2470:  f0 27 40 00  st  %i0, [ %i5 ]
a00f2474:  80 a7 20 07  cmp  %i4, 7
a00f2478:  08 bf ff e8  bleu  0xa00f2418
a00f247c:  82 07 00 1c  add  %i4, %i4, %g1
a00f2480:  81 c7 e0 08  ret
a00f2484:  81 e8 00 00  restore
