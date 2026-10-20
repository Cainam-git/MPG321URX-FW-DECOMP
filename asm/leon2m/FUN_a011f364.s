# leon2m FUN_a011f364 0xa011f364-0xa011f6a4 (832 bytes)
a011f364:  9d e3 bf 98  save  %sp, -104, %sp
a011f368:  35 33 c0 45  sethi  %hi(0xcf011400), %i2
a011f36c:  ba 16 a0 28  or  %i2, 0x28, %i5	! 0xcf011428
a011f370:  9e 10 00 19  mov  %i1, %o7
a011f374:  f2 07 40 00  ld  [ %i5 ], %i1
a011f378:  82 16 60 03  or  %i1, 3, %g1
a011f37c:  f6 0b c0 00  ldub  [ %o7 ], %i3
a011f380:  c2 27 40 00  st  %g1, [ %i5 ]
a011f384:  80 a6 20 02  cmp  %i0, 2
a011f388:  02 80 00 b2  be  0xa011f650
a011f38c:  80 a6 20 01  cmp  %i0, 1
a011f390:  08 80 00 4e  bleu  0xa011f4c8
a011f394:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a011f398:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011f39c:  ba 17 20 28  or  %i4, 0x28, %i5	! 0xcf011428
a011f3a0:  f6 07 40 00  ld  [ %i5 ], %i3
a011f3a4:  b2 16 e0 03  or  %i3, 3, %i1
a011f3a8:  f6 0b e0 01  ldub  [ %o7 + 1 ], %i3
a011f3ac:  f2 27 40 00  st  %i1, [ %i5 ]
a011f3b0:  80 a6 20 02  cmp  %i0, 2
a011f3b4:  02 80 00 58  be  0xa011f514
a011f3b8:  35 00 06 8b  sethi  %hi(0x1a2c00), %i2
a011f3bc:  80 a6 20 01  cmp  %i0, 1
a011f3c0:  38 80 00 0d  bgu,a   0xa011f3f4
a011f3c4:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011f3c8:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a011f3cc:  b4 10 63 b0  or  %g1, 0x3b0, %i2	! 0x1a2fb0
a011f3d0:  b8 06 00 18  add  %i0, %i0, %i4
a011f3d4:  f2 16 80 1c  lduh  [ %i2 + %i4 ], %i1
a011f3d8:  ba 06 60 05  add  %i1, 5, %i5
a011f3dc:  b5 2f 60 02  sll  %i5, 2, %i2
a011f3e0:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a011f3e4:  b2 16 80 01  or  %i2, %g1, %i1
a011f3e8:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011f3ec:  f8 26 40 00  st  %i4, [ %i1 ]
a011f3f0:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011f3f4:  b6 16 e0 28  or  %i3, 0x28, %i3	! 0xcf011428
a011f3f8:  fa 0b e0 04  ldub  [ %o7 + 4 ], %i5
a011f3fc:  c2 06 c0 00  ld  [ %i3 ], %g1
a011f400:  b2 0f 60 0f  and  %i5, 0xf, %i1
a011f404:  f8 0b e0 05  ldub  [ %o7 + 5 ], %i4
a011f408:  bb 2e 60 04  sll  %i1, 4, %i5
a011f40c:  b4 10 60 03  or  %g1, 3, %i2
a011f410:  b2 0f 20 0f  and  %i4, 0xf, %i1
a011f414:  f4 26 c0 00  st  %i2, [ %i3 ]
a011f418:  80 a6 20 02  cmp  %i0, 2
a011f41c:  02 80 00 5b  be  0xa011f588
a011f420:  b6 17 40 19  or  %i5, %i1, %i3
a011f424:  80 a6 20 01  cmp  %i0, 1
a011f428:  18 80 00 0d  bgu  0xa011f45c
a011f42c:  33 33 c0 45  sethi  %hi(0xcf011400), %i1
a011f430:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a011f434:  b4 10 63 b0  or  %g1, 0x3b0, %i2	! 0x1a2fb0
a011f438:  b8 06 00 18  add  %i0, %i0, %i4
a011f43c:  f2 16 80 1c  lduh  [ %i2 + %i4 ], %i1
a011f440:  ba 06 60 06  add  %i1, 6, %i5
a011f444:  b5 2f 60 02  sll  %i5, 2, %i2
a011f448:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a011f44c:  b2 16 80 01  or  %i2, %g1, %i1
a011f450:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011f454:  f8 26 40 00  st  %i4, [ %i1 ]
a011f458:  33 33 c0 45  sethi  %hi(0xcf011400), %i1
a011f45c:  b6 16 60 28  or  %i1, 0x28, %i3	! 0xcf011428
a011f460:  f4 06 c0 00  ld  [ %i3 ], %i2
a011f464:  f8 13 e0 02  lduh  [ %o7 + 2 ], %i4
a011f468:  ba 16 a0 03  or  %i2, 3, %i5
a011f46c:  b2 0f 2f ff  and  %i4, 0xfff, %i1
a011f470:  fa 26 c0 00  st  %i5, [ %i3 ]
a011f474:  80 a6 20 02  cmp  %i0, 2
a011f478:  02 80 00 60  be  0xa011f5f8
a011f47c:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a011f480:  80 a6 20 01  cmp  %i0, 1
a011f484:  18 80 00 86  bgu  0xa011f69c
a011f488:  b8 06 00 18  add  %i0, %i0, %i4
a011f48c:  31 00 06 8b  sethi  %hi(0x1a2c00), %i0
a011f490:  82 16 23 b0  or  %i0, 0x3b0, %g1	! 0x1a2fb0
a011f494:  fa 10 40 1c  lduh  [ %g1 + %i4 ], %i5
a011f498:  b6 07 60 07  add  %i5, 7, %i3
a011f49c:  b1 2e e0 02  sll  %i3, 2, %i0
a011f4a0:  37 33 c0 00  sethi  %hi(0xcf000000), %i3
a011f4a4:  ba 07 60 08  add  %i5, 8, %i5
a011f4a8:  b8 16 00 1b  or  %i0, %i3, %i4
a011f4ac:  b5 2f 60 02  sll  %i5, 2, %i2
a011f4b0:  b0 16 80 1b  or  %i2, %i3, %i0
a011f4b4:  82 0e 60 ff  and  %i1, 0xff, %g1
a011f4b8:  c2 27 00 00  st  %g1, [ %i4 ]
a011f4bc:  b7 36 60 08  srl  %i1, 8, %i3
a011f4c0:  f6 26 00 00  st  %i3, [ %i0 ]
a011f4c4:  30 80 00 76  b,a   0xa011f69c
a011f4c8:  b4 10 63 b0  or  %g1, 0x3b0, %i2
a011f4cc:  b8 06 00 18  add  %i0, %i0, %i4
a011f4d0:  f2 16 80 1c  lduh  [ %i2 + %i4 ], %i1
a011f4d4:  ba 06 60 04  add  %i1, 4, %i5
a011f4d8:  b5 2f 60 02  sll  %i5, 2, %i2
a011f4dc:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a011f4e0:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011f4e4:  b2 16 80 01  or  %i2, %g1, %i1
a011f4e8:  f8 26 40 00  st  %i4, [ %i1 ]
a011f4ec:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011f4f0:  ba 17 20 28  or  %i4, 0x28, %i5	! 0xcf011428
a011f4f4:  f6 07 40 00  ld  [ %i5 ], %i3
a011f4f8:  b2 16 e0 03  or  %i3, 3, %i1
a011f4fc:  f6 0b e0 01  ldub  [ %o7 + 1 ], %i3
a011f500:  f2 27 40 00  st  %i1, [ %i5 ]
a011f504:  80 a6 20 02  cmp  %i0, 2
a011f508:  12 bf ff ae  bne  0xa011f3c0
a011f50c:  80 a6 20 01  cmp  %i0, 1
a011f510:  35 00 06 8b  sethi  %hi(0x1a2c00), %i2
a011f514:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011f518:  b2 16 a3 b0  or  %i2, 0x3b0, %i1
a011f51c:  b6 10 20 00  clr  %i3
a011f520:  ba 10 20 00  clr  %i5
a011f524:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011f528:  ba 07 40 1d  add  %i5, %i5, %i5
a011f52c:  c2 16 40 1d  lduh  [ %i1 + %i5 ], %g1
a011f530:  82 00 60 05  add  %g1, 5, %g1
a011f534:  bb 28 60 02  sll  %g1, 2, %i5
a011f538:  82 17 40 1a  or  %i5, %i2, %g1
a011f53c:  b6 06 e0 01  inc  %i3
a011f540:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011f544:  f8 20 40 00  st  %i4, [ %g1 ]
a011f548:  80 a7 60 01  cmp  %i5, 1
a011f54c:  08 bf ff f8  bleu  0xa011f52c
a011f550:  ba 07 40 1d  add  %i5, %i5, %i5
a011f554:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011f558:  b6 16 e0 28  or  %i3, 0x28, %i3	! 0xcf011428
a011f55c:  fa 0b e0 04  ldub  [ %o7 + 4 ], %i5
a011f560:  c2 06 c0 00  ld  [ %i3 ], %g1
a011f564:  b2 0f 60 0f  and  %i5, 0xf, %i1
a011f568:  f8 0b e0 05  ldub  [ %o7 + 5 ], %i4
a011f56c:  bb 2e 60 04  sll  %i1, 4, %i5
a011f570:  b4 10 60 03  or  %g1, 3, %i2
a011f574:  b2 0f 20 0f  and  %i4, 0xf, %i1
a011f578:  f4 26 c0 00  st  %i2, [ %i3 ]
a011f57c:  80 a6 20 02  cmp  %i0, 2
a011f580:  12 bf ff a9  bne  0xa011f424
a011f584:  b6 17 40 19  or  %i5, %i1, %i3
a011f588:  35 00 06 8b  sethi  %hi(0x1a2c00), %i2
a011f58c:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011f590:  b2 16 a3 b0  or  %i2, 0x3b0, %i1
a011f594:  b6 10 20 00  clr  %i3
a011f598:  ba 10 20 00  clr  %i5
a011f59c:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011f5a0:  ba 07 40 1d  add  %i5, %i5, %i5
a011f5a4:  c2 16 40 1d  lduh  [ %i1 + %i5 ], %g1
a011f5a8:  82 00 60 06  add  %g1, 6, %g1
a011f5ac:  bb 28 60 02  sll  %g1, 2, %i5
a011f5b0:  82 17 40 1a  or  %i5, %i2, %g1
a011f5b4:  b6 06 e0 01  inc  %i3
a011f5b8:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011f5bc:  f8 20 40 00  st  %i4, [ %g1 ]
a011f5c0:  80 a7 60 01  cmp  %i5, 1
a011f5c4:  08 bf ff f8  bleu  0xa011f5a4
a011f5c8:  ba 07 40 1d  add  %i5, %i5, %i5
a011f5cc:  33 33 c0 45  sethi  %hi(0xcf011400), %i1
a011f5d0:  b6 16 60 28  or  %i1, 0x28, %i3	! 0xcf011428
a011f5d4:  f4 06 c0 00  ld  [ %i3 ], %i2
a011f5d8:  f8 13 e0 02  lduh  [ %o7 + 2 ], %i4
a011f5dc:  ba 16 a0 03  or  %i2, 3, %i5
a011f5e0:  b2 0f 2f ff  and  %i4, 0xfff, %i1
a011f5e4:  fa 26 c0 00  st  %i5, [ %i3 ]
a011f5e8:  80 a6 20 02  cmp  %i0, 2
a011f5ec:  12 bf ff a6  bne  0xa011f484
a011f5f0:  80 a6 20 01  cmp  %i0, 1
a011f5f4:  03 00 06 8b  sethi  %hi(0x1a2c00), %g1
a011f5f8:  b0 0e 60 ff  and  %i1, 0xff, %i0
a011f5fc:  9e 10 63 b0  or  %g1, 0x3b0, %o7
a011f600:  b3 36 60 08  srl  %i1, 8, %i1
a011f604:  b6 10 20 00  clr  %i3
a011f608:  82 10 20 00  clr  %g1
a011f60c:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011f610:  82 00 40 01  add  %g1, %g1, %g1
a011f614:  fa 13 c0 01  lduh  [ %o7 + %g1 ], %i5
a011f618:  b8 07 60 07  add  %i5, 7, %i4
a011f61c:  83 2f 20 02  sll  %i4, 2, %g1
a011f620:  ba 07 60 08  add  %i5, 8, %i5
a011f624:  b8 10 40 1a  or  %g1, %i2, %i4
a011f628:  83 2f 60 02  sll  %i5, 2, %g1
a011f62c:  ba 10 40 1a  or  %g1, %i2, %i5
a011f630:  b6 06 e0 01  inc  %i3
a011f634:  f0 27 00 00  st  %i0, [ %i4 ]
a011f638:  82 0e e0 ff  and  %i3, 0xff, %g1
a011f63c:  f2 27 40 00  st  %i1, [ %i5 ]
a011f640:  80 a0 60 01  cmp  %g1, 1
a011f644:  28 bf ff f4  bleu,a   0xa011f614
a011f648:  82 00 40 01  add  %g1, %g1, %g1
a011f64c:  30 80 00 14  b,a   0xa011f69c
a011f650:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011f654:  37 00 06 8b  sethi  %hi(0x1a2c00), %i3
a011f658:  b2 16 e3 b0  or  %i3, 0x3b0, %i1	! 0x1a2fb0
a011f65c:  b6 10 20 00  clr  %i3
a011f660:  ba 10 20 00  clr  %i5
a011f664:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011f668:  ba 07 40 1d  add  %i5, %i5, %i5
a011f66c:  c2 16 40 1d  lduh  [ %i1 + %i5 ], %g1
a011f670:  82 00 60 04  add  %g1, 4, %g1
a011f674:  bb 28 60 02  sll  %g1, 2, %i5
a011f678:  82 17 40 1a  or  %i5, %i2, %g1
a011f67c:  b6 06 e0 01  inc  %i3
a011f680:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011f684:  f8 20 40 00  st  %i4, [ %g1 ]
a011f688:  80 a7 60 01  cmp  %i5, 1
a011f68c:  08 bf ff f8  bleu  0xa011f66c
a011f690:  ba 07 40 1d  add  %i5, %i5, %i5
a011f694:  10 bf ff 42  b  0xa011f39c
a011f698:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011f69c:  81 c7 e0 08  ret
a011f6a0:  81 e8 00 00  restore
