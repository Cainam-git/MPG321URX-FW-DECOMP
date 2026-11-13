# leon2m FUN_a00ca410 0xa00ca410-0xa00ca644 (564 bytes)
a00ca410:  9d e3 bf 98  save  %sp, -104, %sp
a00ca414:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ca418:  80 a6 20 02  cmp  %i0, 2
a00ca41c:  02 80 00 3a  be  0xa00ca504
a00ca420:  80 a6 20 03  cmp  %i0, 3
a00ca424:  02 80 00 58  be  0xa00ca584
a00ca428:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ca42c:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00ca430:  96 08 60 ff  and  %g1, 0xff, %o3
a00ca434:  94 02 ff d0  add  %o3, -48, %o2
a00ca438:  a0 0a a0 ff  and  %o2, 0xff, %l0
a00ca43c:  80 a4 20 01  cmp  %l0, 1
a00ca440:  38 80 00 7f  bgu,a   0xa00ca63c
a00ca444:  b0 10 20 ff  mov  0xff, %i0
a00ca448:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ca44c:  98 14 62 90  or  %l1, 0x290, %o4	! 0xa802d290
a00ca450:  da 0b 21 e5  ldub  [ %o4 + 0x1e5 ], %o5
a00ca454:  80 a3 60 01  cmp  %o5, 1
a00ca458:  02 80 00 68  be  0xa00ca5f8
a00ca45c:  80 a4 20 01  cmp  %l0, 1
a00ca460:  02 80 00 6f  be  0xa00ca61c
a00ca464:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a00ca468:  7f ff b9 19  call  0xa00b88cc
a00ca46c:  01 00 00 00  nop
a00ca470:  80 a6 20 02  cmp  %i0, 2
a00ca474:  02 80 00 27  be  0xa00ca510
a00ca478:  80 a6 20 03  cmp  %i0, 3
a00ca47c:  02 80 00 45  be  0xa00ca590
a00ca480:  9e 10 20 30  mov  0x30, %o7
a00ca484:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ca488:  94 12 20 78  or  %o0, 0x78, %o2	! 0xa802d078
a00ca48c:  a2 10 20 35  mov  0x35, %l1
a00ca490:  82 10 20 36  mov  0x36, %g1
a00ca494:  98 10 20 2b  mov  0x2b, %o4
a00ca498:  9a 10 20 0d  mov  0xd, %o5
a00ca49c:  e2 2a 20 78  stb  %l1, [ %o0 + 0x78 ]
a00ca4a0:  c2 2a a0 01  stb  %g1, [ %o2 + 1 ]
a00ca4a4:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00ca4a8:  d8 2a a0 04  stb  %o4, [ %o2 + 4 ]
a00ca4ac:  da 2a a0 05  stb  %o5, [ %o2 + 5 ]
a00ca4b0:  80 a6 20 02  cmp  %i0, 2
a00ca4b4:  02 80 00 24  be  0xa00ca544
a00ca4b8:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00ca4bc:  80 a6 20 03  cmp  %i0, 3
a00ca4c0:  02 80 00 41  be  0xa00ca5c4
a00ca4c4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00ca4c8:  9a 13 20 d0  or  %o4, 0xd0, %o5	! 0xa802d0d0
a00ca4cc:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00ca4d0:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]	! 0xa802b09c
a00ca4d4:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00ca4d8:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00ca4dc:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00ca4e0:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00ca4e4:  80 a6 20 02  cmp  %i0, 2
a00ca4e8:  02 80 00 20  be  0xa00ca568
a00ca4ec:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00ca4f0:  80 a6 20 03  cmp  %i0, 3
a00ca4f4:  12 80 00 20  bne  0xa00ca574
a00ca4f8:  90 10 00 18  mov  %i0, %o0
a00ca4fc:  10 80 00 3c  b  0xa00ca5ec
a00ca500:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ca504:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ca508:  10 bf ff ca  b  0xa00ca430
a00ca50c:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00ca510:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00ca514:  a0 13 e1 28  or  %o7, 0x128, %l0	! 0xa802d128
a00ca518:  b0 10 20 30  mov  0x30, %i0
a00ca51c:  82 10 20 35  mov  0x35, %g1
a00ca520:  98 10 20 0d  mov  0xd, %o4
a00ca524:  9a 10 20 36  mov  0x36, %o5
a00ca528:  96 10 20 2b  mov  0x2b, %o3
a00ca52c:  c2 2b e1 28  stb  %g1, [ %o7 + 0x128 ]
a00ca530:  d8 2c 20 05  stb  %o4, [ %l0 + 5 ]
a00ca534:  da 2c 20 01  stb  %o5, [ %l0 + 1 ]
a00ca538:  f0 2c 20 03  stb  %i0, [ %l0 + 3 ]
a00ca53c:  d6 2c 20 04  stb  %o3, [ %l0 + 4 ]
a00ca540:  f0 2c 20 02  stb  %i0, [ %l0 + 2 ]
a00ca544:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ca548:  92 12 a0 40  or  %o2, 0x40, %o1	! 0xa802d040
a00ca54c:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00ca550:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00ca554:  c0 2a a0 40  clrb  [ %o2 + 0x40 ]
a00ca558:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00ca55c:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00ca560:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00ca564:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00ca568:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ca56c:  94 12 21 28  or  %o0, 0x128, %o2	! 0xa802d128
a00ca570:  90 10 20 02  mov  2, %o0
a00ca574:  40 01 f8 9d  call  0xa01487e8
a00ca578:  92 10 20 06  mov  6, %o1
a00ca57c:  10 80 00 30  b  0xa00ca63c
a00ca580:  b0 10 20 00  clr  %i0
a00ca584:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ca588:  10 bf ff aa  b  0xa00ca430
a00ca58c:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00ca590:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00ca594:  90 16 21 08  or  %i0, 0x108, %o0	! 0xa802d108
a00ca598:  a2 10 20 30  mov  0x30, %l1
a00ca59c:  96 10 20 35  mov  0x35, %o3
a00ca5a0:  a0 10 20 0d  mov  0xd, %l0
a00ca5a4:  94 10 20 36  mov  0x36, %o2
a00ca5a8:  92 10 20 2b  mov  0x2b, %o1
a00ca5ac:  d6 2e 21 08  stb  %o3, [ %i0 + 0x108 ]
a00ca5b0:  e0 2a 20 05  stb  %l0, [ %o0 + 5 ]
a00ca5b4:  d4 2a 20 01  stb  %o2, [ %o0 + 1 ]
a00ca5b8:  e2 2a 20 03  stb  %l1, [ %o0 + 3 ]
a00ca5bc:  d2 2a 20 04  stb  %o1, [ %o0 + 4 ]
a00ca5c0:  e2 2a 20 02  stb  %l1, [ %o0 + 2 ]
a00ca5c4:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ca5c8:  b0 12 e0 98  or  %o3, 0x98, %i0	! 0xa802d098
a00ca5cc:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00ca5d0:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]	! 0xa802b098
a00ca5d4:  c0 2a e0 98  clrb  [ %o3 + 0x98 ]
a00ca5d8:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00ca5dc:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00ca5e0:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00ca5e4:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00ca5e8:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ca5ec:  94 14 61 08  or  %l1, 0x108, %o2	! 0xa802d108
a00ca5f0:  10 bf ff e1  b  0xa00ca574
a00ca5f4:  90 10 20 03  mov  3, %o0
a00ca5f8:  7f ff 1a 75  call  0xa0090fcc
a00ca5fc:  01 00 00 00  nop
a00ca600:  83 2a 20 10  sll  %o0, 0x10, %g1
a00ca604:  9f 30 60 10  srl  %g1, 0x10, %o7
a00ca608:  80 a3 e1 0a  cmp  %o7, 0x10a
a00ca60c:  12 bf ff 95  bne  0xa00ca460
a00ca610:  80 a4 20 01  cmp  %l0, 1
a00ca614:  10 80 00 0a  b  0xa00ca63c
a00ca618:  b0 10 20 ff  mov  0xff, %i0
a00ca61c:  d4 12 23 f4  lduh  [ %o0 + 0x3f4 ], %o2
a00ca620:  92 14 62 90  or  %l1, 0x290, %o1
a00ca624:  a2 0a be ff  and  %o2, -257, %l1
a00ca628:  e0 2a 61 e5  stb  %l0, [ %o1 + 0x1e5 ]
a00ca62c:  e2 32 23 f4  sth  %l1, [ %o0 + 0x3f4 ]
a00ca630:  40 00 41 47  call  0xa00dab4c
a00ca634:  90 10 20 01  mov  1, %o0
a00ca638:  30 bf ff 8c  b,a   0xa00ca468
a00ca63c:  81 c7 e0 08  ret
a00ca640:  81 e8 00 00  restore
