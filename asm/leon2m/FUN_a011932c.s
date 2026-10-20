# leon2m FUN_a011932c 0xa011932c-0xa0119578 (588 bytes)
a011932c:  9d e3 bf 98  save  %sp, -104, %sp
a0119330:  9a 10 00 19  mov  %i1, %o5
a0119334:  80 a6 20 b0  cmp  %i0, 0xb0
a0119338:  02 80 00 3d  be  0xa011942c
a011933c:  b2 10 00 1a  mov  %i2, %i1
a0119340:  80 a6 20 b0  cmp  %i0, 0xb0
a0119344:  18 80 00 07  bgu  0xa0119360
a0119348:  80 a6 20 c0  cmp  %i0, 0xc0
a011934c:  80 a6 20 a0  cmp  %i0, 0xa0
a0119350:  12 80 00 88  bne  0xa0119570
a0119354:  82 0e a0 ff  and  %i2, 0xff, %g1
a0119358:  10 80 00 71  b  0xa011951c
a011935c:  80 a0 60 02  cmp  %g1, 2
a0119360:  02 80 00 55  be  0xa01194b4
a0119364:  80 a6 20 c1  cmp  %i0, 0xc1
a0119368:  12 80 00 82  bne  0xa0119570
a011936c:  82 0e a0 ff  and  %i2, 0xff, %g1
a0119370:  31 2a 00 9e  sethi  %hi(0xa8027800), %i0
a0119374:  b0 16 22 a8  or  %i0, 0x2a8, %i0	! 0xa8027aa8
a0119378:  80 a0 60 02  cmp  %g1, 2
a011937c:  b6 00 40 01  add  %g1, %g1, %i3
a0119380:  ba 60 20 00  subx  %g0, 0, %i5
a0119384:  f8 16 00 1b  lduh  [ %i0 + %i3 ], %i4
a0119388:  b6 0f 40 19  and  %i5, %i1, %i3
a011938c:  80 a0 60 02  cmp  %g1, 2
a0119390:  b8 07 20 9f  add  %i4, 0x9f, %i4
a0119394:  ba 0e e0 ff  and  %i3, 0xff, %i5
a0119398:  b4 0e a0 ff  and  %i2, 0xff, %i2
a011939c:  82 60 20 00  subx  %g0, 0, %g1
a01193a0:  82 08 40 19  and  %g1, %i1, %g1
a01193a4:  b4 06 80 1a  add  %i2, %i2, %i2
a01193a8:  b7 2f 20 02  sll  %i4, 2, %i3
a01193ac:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a01193b0:  f2 16 00 1a  lduh  [ %i0 + %i2 ], %i1
a01193b4:  b8 16 c0 0f  or  %i3, %o7, %i4
a01193b8:  ba 07 40 1d  add  %i5, %i5, %i5
a01193bc:  b6 06 60 9f  add  %i1, 0x9f, %i3
a01193c0:  f4 16 00 1d  lduh  [ %i0 + %i5 ], %i2
a01193c4:  b2 08 60 ff  and  %g1, 0xff, %i1
a01193c8:  fa 07 00 00  ld  [ %i4 ], %i5
a01193cc:  82 06 40 19  add  %i1, %i1, %g1
a01193d0:  b7 2e e0 02  sll  %i3, 2, %i3
a01193d4:  b2 06 a0 8c  add  %i2, 0x8c, %i1
a01193d8:  f8 16 00 01  lduh  [ %i0 + %g1 ], %i4
a01193dc:  b6 16 c0 0f  or  %i3, %o7, %i3
a01193e0:  ba 0f 60 7f  and  %i5, 0x7f, %i5
a01193e4:  fa 26 c0 00  st  %i5, [ %i3 ]
a01193e8:  b0 06 a0 8d  add  %i2, 0x8d, %i0
a01193ec:  b3 2e 60 02  sll  %i1, 2, %i1
a01193f0:  b5 2e 20 02  sll  %i0, 2, %i2
a01193f4:  b2 16 40 0f  or  %i1, %o7, %i1
a01193f8:  82 0b 60 ff  and  %o5, 0xff, %g1
a01193fc:  b7 2b 60 10  sll  %o5, 0x10, %i3
a0119400:  c2 26 40 00  st  %g1, [ %i1 ]
a0119404:  bb 36 e0 18  srl  %i3, 0x18, %i5
a0119408:  b0 07 20 f2  add  %i4, 0xf2, %i0
a011940c:  82 16 80 0f  or  %i2, %o7, %g1
a0119410:  b7 33 60 10  srl  %o5, 0x10, %i3
a0119414:  b9 2e 20 02  sll  %i0, 2, %i4
a0119418:  fa 20 40 00  st  %i5, [ %g1 ]
a011941c:  b2 17 00 0f  or  %i4, %o7, %i1
a0119420:  b4 0e e0 ff  and  %i3, 0xff, %i2
a0119424:  f4 26 40 00  st  %i2, [ %i1 ]
a0119428:  30 80 00 52  b,a   0xa0119570
a011942c:  b8 0e a0 ff  and  %i2, 0xff, %i4
a0119430:  80 a7 20 02  cmp  %i4, 2
a0119434:  b0 60 20 00  subx  %g0, 0, %i0
a0119438:  82 0e 80 18  and  %i2, %i0, %g1
a011943c:  80 a7 20 02  cmp  %i4, 2
a0119440:  b2 08 60 ff  and  %g1, 0xff, %i1
a0119444:  ba 60 20 00  subx  %g0, 0, %i5
a0119448:  37 2a 00 9e  sethi  %hi(0xa8027800), %i3
a011944c:  b0 0e 80 1d  and  %i2, %i5, %i0
a0119450:  b6 16 e2 a8  or  %i3, 0x2a8, %i3
a0119454:  b8 06 40 19  add  %i1, %i1, %i4
a0119458:  f2 16 c0 1c  lduh  [ %i3 + %i4 ], %i1
a011945c:  b4 0e 20 ff  and  %i0, 0xff, %i2
a0119460:  b8 06 60 8a  add  %i1, 0x8a, %i4
a0119464:  82 06 80 1a  add  %i2, %i2, %g1
a0119468:  b0 06 60 8b  add  %i1, 0x8b, %i0
a011946c:  f4 16 c0 01  lduh  [ %i3 + %g1 ], %i2
a0119470:  bb 2f 20 02  sll  %i4, 2, %i5
a0119474:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a0119478:  82 17 40 19  or  %i5, %i1, %g1
a011947c:  b9 2e 20 02  sll  %i0, 2, %i4
a0119480:  b4 06 a0 f1  add  %i2, 0xf1, %i2
a0119484:  b6 0b 60 ff  and  %o5, 0xff, %i3
a0119488:  f6 20 40 00  st  %i3, [ %g1 ]
a011948c:  bb 2b 60 10  sll  %o5, 0x10, %i5
a0119490:  83 2e a0 02  sll  %i2, 2, %g1
a0119494:  b0 17 00 19  or  %i4, %i1, %i0
a0119498:  b4 10 40 19  or  %g1, %i1, %i2
a011949c:  bb 37 60 18  srl  %i5, 0x18, %i5
a01194a0:  b7 33 60 10  srl  %o5, 0x10, %i3
a01194a4:  fa 26 00 00  st  %i5, [ %i0 ]
a01194a8:  b2 0e e0 ff  and  %i3, 0xff, %i1
a01194ac:  f2 26 80 00  st  %i1, [ %i2 ]
a01194b0:  30 80 00 30  b,a   0xa0119570
a01194b4:  82 0e a0 ff  and  %i2, 0xff, %g1
a01194b8:  31 2a 00 9e  sethi  %hi(0xa8027800), %i0
a01194bc:  b0 16 22 a8  or  %i0, 0x2a8, %i0	! 0xa8027aa8
a01194c0:  80 a0 60 02  cmp  %g1, 2
a01194c4:  b2 00 40 01  add  %g1, %g1, %i1
a01194c8:  ba 60 20 00  subx  %g0, 0, %i5
a01194cc:  f6 16 00 19  lduh  [ %i0 + %i1 ], %i3
a01194d0:  80 a0 60 02  cmp  %g1, 2
a01194d4:  b8 06 e0 9f  add  %i3, 0x9f, %i4
a01194d8:  82 0e 80 1d  and  %i2, %i5, %g1
a01194dc:  b7 2f 20 02  sll  %i4, 2, %i3
a01194e0:  b8 08 60 ff  and  %g1, 0xff, %i4
a01194e4:  b2 60 20 00  subx  %g0, 0, %i1
a01194e8:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a01194ec:  82 0e 80 19  and  %i2, %i1, %g1
a01194f0:  ba 07 00 1c  add  %i4, %i4, %i5
a01194f4:  b6 16 c0 0f  or  %i3, %o7, %i3
a01194f8:  f4 16 00 1d  lduh  [ %i0 + %i5 ], %i2
a01194fc:  b8 08 60 ff  and  %g1, 0xff, %i4
a0119500:  f2 06 c0 00  ld  [ %i3 ], %i1
a0119504:  ba 16 7f 80  or  %i1, -128, %i5
a0119508:  82 07 00 1c  add  %i4, %i4, %g1
a011950c:  b2 06 a0 8c  add  %i2, 0x8c, %i1
a0119510:  f8 16 00 01  lduh  [ %i0 + %g1 ], %i4
a0119514:  10 bf ff b4  b  0xa01193e4
a0119518:  ba 0f 60 ff  and  %i5, 0xff, %i5
a011951c:  b8 60 20 00  subx  %g0, 0, %i4
a0119520:  b6 0e 80 1c  and  %i2, %i4, %i3
a0119524:  b0 0e e0 ff  and  %i3, 0xff, %i0
a0119528:  80 a0 60 02  cmp  %g1, 2
a011952c:  33 2a 00 9e  sethi  %hi(0xa8027800), %i1
a0119530:  b6 16 62 a8  or  %i1, 0x2a8, %i3	! 0xa8027aa8
a0119534:  ba 60 20 00  subx  %g0, 0, %i5
a0119538:  82 06 00 18  add  %i0, %i0, %g1
a011953c:  b8 0e 80 1d  and  %i2, %i5, %i4
a0119540:  f0 16 c0 01  lduh  [ %i3 + %g1 ], %i0
a0119544:  b4 0f 20 ff  and  %i4, 0xff, %i2
a0119548:  b2 06 20 88  add  %i0, 0x88, %i1
a011954c:  83 2e 60 02  sll  %i1, 2, %g1
a0119550:  ba 06 80 1a  add  %i2, %i2, %i5
a0119554:  f4 16 c0 1d  lduh  [ %i3 + %i5 ], %i2
a0119558:  b8 06 20 89  add  %i0, 0x89, %i4
a011955c:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a0119560:  82 10 40 19  or  %g1, %i1, %g1
a0119564:  b9 2f 20 02  sll  %i4, 2, %i4
a0119568:  10 bf ff c7  b  0xa0119484
a011956c:  b4 06 a0 f0  add  %i2, 0xf0, %i2
a0119570:  81 c7 e0 08  ret
a0119574:  81 e8 00 00  restore
