# leon2m FUN_a012c320 0xa012c320-0xa012c80c (1260 bytes)
a012c320:  9d e3 bf 48  save  %sp, -184, %sp
a012c324:  98 10 20 00  clr  %o4
a012c328:  9a 10 20 00  clr  %o5
a012c32c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012c330:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a012c334:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a012c338:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a012c33c:  c0 37 bf e0  clrh  [ %fp + -32 ]
a012c340:  7f ff e4 0b  call  0xa012536c
a012c344:  90 10 00 18  mov  %i0, %o0
a012c348:  80 8a 20 ff  btst  0xff, %o0
a012c34c:  a2 10 00 19  mov  %i1, %l1
a012c350:  aa 10 20 00  clr  %l5
a012c354:  02 80 00 30  be  0xa012c414
a012c358:  a4 10 20 00  clr  %l2
a012c35c:  7f ff e4 09  call  0xa0125380
a012c360:  90 10 00 18  mov  %i0, %o0
a012c364:  80 8f 20 ff  btst  0xff, %i4
a012c368:  02 80 00 c5  be  0xa012c67c
a012c36c:  a4 10 00 08  mov  %o0, %l2
a012c370:  80 8e 60 0f  btst  0xf, %i1
a012c374:  12 80 00 f9  bne  0xa012c758
a012c378:  e0 16 c0 00  lduh  [ %i3 ], %l0
a012c37c:  9f 2c 20 10  sll  %l0, 0x10, %o7
a012c380:  9b 33 e0 10  srl  %o7, 0x10, %o5
a012c384:  80 a3 60 00  cmp  %o5, 0
a012c388:  02 80 01 1f  be  0xa012c804
a012c38c:  a6 10 20 00  clr  %l3
a012c390:  af 2d 60 10  sll  %l5, 0x10, %l7
a012c394:  98 10 00 0d  mov  %o5, %o4
a012c398:  10 80 00 0a  b  0xa012c3c0
a012c39c:  a9 35 e0 10  srl  %l7, 0x10, %l4
a012c3a0:  40 00 24 a3  call  0xa013562c
a012c3a4:  a0 04 3f 80  add  %l0, -128, %l0
a012c3a8:  83 2c 20 10  sll  %l0, 0x10, %g1
a012c3ac:  99 30 60 10  srl  %g1, 0x10, %o4
a012c3b0:  a4 04 a0 80  add  %l2, 0x80, %l2
a012c3b4:  80 a3 20 00  cmp  %o4, 0
a012c3b8:  02 80 01 13  be  0xa012c804
a012c3bc:  a6 04 e0 80  add  %l3, 0x80, %l3
a012c3c0:  b9 2c e0 10  sll  %l3, 0x10, %i4
a012c3c4:  b3 37 20 10  srl  %i4, 0x10, %i1
a012c3c8:  b6 04 80 11  add  %l2, %l1, %i3
a012c3cc:  b1 2e e0 10  sll  %i3, 0x10, %i0
a012c3d0:  aa 06 40 14  add  %i1, %l4, %l5
a012c3d4:  91 36 20 10  srl  %i0, 0x10, %o0
a012c3d8:  94 05 40 1a  add  %l5, %i2, %o2
a012c3dc:  80 a3 20 80  cmp  %o4, 0x80
a012c3e0:  18 bf ff f0  bgu  0xa012c3a0
a012c3e4:  92 10 20 80  mov  0x80, %o1
a012c3e8:  92 0c 20 ff  and  %l0, 0xff, %o1
a012c3ec:  91 36 20 10  srl  %i0, 0x10, %o0
a012c3f0:  40 00 24 8f  call  0xa013562c
a012c3f4:  94 05 40 1a  add  %l5, %i2, %o2
a012c3f8:  a0 10 20 00  clr  %l0
a012c3fc:  83 2c 20 10  sll  %l0, 0x10, %g1
a012c400:  99 30 60 10  srl  %g1, 0x10, %o4
a012c404:  80 a3 20 00  cmp  %o4, 0
a012c408:  12 bf ff ef  bne  0xa012c3c4
a012c40c:  b9 2c e0 10  sll  %l3, 0x10, %i4
a012c410:  30 80 00 fd  b,a   0xa012c804
a012c414:  a8 10 20 01  mov  1, %l4
a012c418:  93 2d 00 18  sll  %l4, %i0, %o1
a012c41c:  40 00 1e 8f  call  0xa0133e58
a012c420:  90 0a 60 ff  and  %o1, 0xff, %o0
a012c424:  7f ff e2 d0  call  0xa0124f64
a012c428:  90 10 00 18  mov  %i0, %o0
a012c42c:  d0 2f bf d8  stb  %o0, [ %fp + -40 ]
a012c430:  7f ff e2 d3  call  0xa0124f7c
a012c434:  90 10 00 18  mov  %i0, %o0
a012c438:  d0 2f bf d9  stb  %o0, [ %fp + -39 ]
a012c43c:  7f ff e2 d7  call  0xa0124f98
a012c440:  90 10 00 18  mov  %i0, %o0
a012c444:  d0 2f bf da  stb  %o0, [ %fp + -38 ]
a012c448:  7f ff e2 db  call  0xa0124fb4
a012c44c:  90 10 00 18  mov  %i0, %o0
a012c450:  c2 07 bf e0  ld  [ %fp + -32 ], %g1
a012c454:  23 10 00 00  sethi  %hi(0x40000000), %l1
a012c458:  9e 28 40 11  andn  %g1, %l1, %o7
a012c45c:  2f 20 00 00  sethi  %hi(0x80000000), %l7
a012c460:  d0 2f bf db  stb  %o0, [ %fp + -37 ]
a012c464:  ac 13 c0 17  or  %o7, %l7, %l6
a012c468:  9a 10 3f a0  mov  -96, %o5
a012c46c:  a6 10 20 04  mov  4, %l3
a012c470:  da 2f bf de  stb  %o5, [ %fp + -34 ]
a012c474:  ec 27 bf e0  st  %l6, [ %fp + -32 ]
a012c478:  e8 2f bf df  stb  %l4, [ %fp + -33 ]
a012c47c:  e6 37 bf dc  sth  %l3, [ %fp + -36 ]
a012c480:  7f ff e4 48  call  0xa01255a0
a012c484:  90 10 00 18  mov  %i0, %o0
a012c488:  99 2a 20 10  sll  %o0, 0x10, %o4
a012c48c:  a1 33 20 10  srl  %o4, 0x10, %l0
a012c490:  80 a4 21 00  cmp  %l0, 0x100
a012c494:  18 80 00 3d  bgu  0xa012c588
a012c498:  80 8f 20 ff  btst  0xff, %i4
a012c49c:  02 80 00 3d  be  0xa012c590
a012c4a0:  01 00 00 00  nop
a012c4a4:  f6 16 c0 00  lduh  [ %i3 ], %i3
a012c4a8:  a9 2e e0 10  sll  %i3, 0x10, %l4
a012c4ac:  ac 0c a0 ff  and  %l2, 0xff, %l6
a012c4b0:  80 a5 20 00  cmp  %l4, 0
a012c4b4:  12 80 00 22  bne  0xa012c53c
a012c4b8:  ae 07 bf b8  add  %fp, -72, %l7
a012c4bc:  30 80 00 9f  b,a   0xa012c738
a012c4c0:  97 2d 60 10  sll  %l5, 0x10, %o3
a012c4c4:  83 37 20 10  srl  %i4, 0x10, %g1
a012c4c8:  91 32 e0 10  srl  %o3, 0x10, %o0
a012c4cc:  93 37 20 10  srl  %i4, 0x10, %o1
a012c4d0:  9a 08 60 ff  and  %g1, 0xff, %o5
a012c4d4:  a3 35 20 10  srl  %l4, 0x10, %l1
a012c4d8:  96 02 00 1a  add  %o0, %i2, %o3
a012c4dc:  b8 03 40 11  add  %o5, %l1, %i4
a012c4e0:  94 0e 60 ff  and  %i1, 0xff, %o2
a012c4e4:  98 10 21 00  mov  0x100, %o4
a012c4e8:  e4 1f bf d8  ldd  [ %fp + -40 ], %l2
a012c4ec:  de 17 bf e0  lduh  [ %fp + -32 ], %o7
a012c4f0:  92 0a 60 ff  and  %o1, 0xff, %o1
a012c4f4:  90 10 00 17  mov  %l7, %o0
a012c4f8:  80 a7 21 00  cmp  %i4, 0x100
a012c4fc:  14 80 00 03  bg  0xa012c508
a012c500:  a0 23 00 0a  sub  %o4, %o2, %l0
a012c504:  a0 10 00 1b  mov  %i3, %l0
a012c508:  b9 2c 20 10  sll  %l0, 0x10, %i4
a012c50c:  e4 3f bf b8  std  %l2, [ %fp + -72 ]
a012c510:  de 37 bf c0  sth  %o7, [ %fp + -64 ]
a012c514:  67 fd 7d 85  call  0x4008bb28
a012c518:  95 37 20 10  srl  %i4, 0x10, %o2
a012c51c:  a8 26 c0 10  sub  %i3, %l0, %l4
a012c520:  9b 2d 20 10  sll  %l4, 0x10, %o5
a012c524:  80 a3 60 00  cmp  %o5, 0
a012c528:  b2 06 40 10  add  %i1, %l0, %i1
a012c52c:  aa 05 40 10  add  %l5, %l0, %l5
a012c530:  02 80 00 82  be  0xa012c738
a012c534:  b6 10 00 14  mov  %l4, %i3
a012c538:  a8 10 00 0d  mov  %o5, %l4
a012c53c:  94 10 20 00  clr  %o2
a012c540:  96 10 20 00  clr  %o3
a012c544:  98 10 20 01  mov  1, %o4
a012c548:  9a 10 20 00  clr  %o5
a012c54c:  90 07 bf c8  add  %fp, -56, %o0
a012c550:  80 a5 a0 00  cmp  %l6, 0
a012c554:  02 bf ff db  be  0xa012c4c0
a012c558:  b9 2e 60 10  sll  %i1, 0x10, %i4
a012c55c:  a6 10 20 60  mov  0x60, %l3
a012c560:  e6 2f bf de  stb  %l3, [ %fp + -34 ]
a012c564:  e0 1f bf d8  ldd  [ %fp + -40 ], %l0
a012c568:  e0 3f bf c8  std  %l0, [ %fp + -56 ]
a012c56c:  e0 17 bf e0  lduh  [ %fp + -32 ], %l0
a012c570:  e0 37 bf d0  sth  %l0, [ %fp + -48 ]
a012c574:  67 fd 7b 9c  call  0x4008b3e4
a012c578:  93 37 20 18  srl  %i4, 0x18, %o1
a012c57c:  a4 10 3f a0  mov  -96, %l2
a012c580:  10 bf ff d0  b  0xa012c4c0
a012c584:  e4 2f bf de  stb  %l2, [ %fp + -34 ]
a012c588:  12 bf ff c7  bne  0xa012c4a4
a012c58c:  a4 10 20 01  mov  1, %l2
a012c590:  7f ff e4 04  call  0xa01255a0
a012c594:  90 10 00 18  mov  %i0, %o0
a012c598:  80 8c a0 ff  btst  0xff, %l2
a012c59c:  02 80 00 5c  be  0xa012c70c
a012c5a0:  d0 36 c0 00  sth  %o0, [ %i3 ]
a012c5a4:  a2 10 00 08  mov  %o0, %l1
a012c5a8:  83 2c 60 10  sll  %l1, 0x10, %g1
a012c5ac:  80 a0 60 00  cmp  %g1, 0
a012c5b0:  02 80 00 62  be  0xa012c738
a012c5b4:  a4 10 00 01  mov  %g1, %l2
a012c5b8:  10 80 00 0d  b  0xa012c5ec
a012c5bc:  a6 07 bf b8  add  %fp, -72, %l3
a012c5c0:  d8 1f bf d8  ldd  [ %fp + -40 ], %o4
a012c5c4:  ee 17 bf e0  lduh  [ %fp + -32 ], %l7
a012c5c8:  d8 3f bf c8  std  %o4, [ %fp + -56 ]
a012c5cc:  67 fd 7d 57  call  0x4008bb28
a012c5d0:  ee 37 bf d0  sth  %l7, [ %fp + -48 ]
a012c5d4:  b2 06 61 00  add  %i1, 0x100, %i1
a012c5d8:  a2 04 7f 00  add  %l1, -256, %l1
a012c5dc:  a5 2c 60 10  sll  %l1, 0x10, %l2
a012c5e0:  80 a4 a0 00  cmp  %l2, 0
a012c5e4:  02 80 00 55  be  0xa012c738
a012c5e8:  01 00 00 00  nop
a012c5ec:  9e 10 20 60  mov  0x60, %o7	! 0x60
a012c5f0:  de 2f bf de  stb  %o7, [ %fp + -34 ]
a012c5f4:  d8 1f bf d8  ldd  [ %fp + -40 ], %o4
a012c5f8:  d8 3f bf b8  std  %o4, [ %fp + -72 ]
a012c5fc:  b7 2e 60 10  sll  %i1, 0x10, %i3
a012c600:  ec 17 bf e0  lduh  [ %fp + -32 ], %l6
a012c604:  93 36 e0 18  srl  %i3, 0x18, %o1
a012c608:  94 10 20 00  clr  %o2
a012c60c:  96 10 20 00  clr  %o3
a012c610:  ec 37 bf c0  sth  %l6, [ %fp + -64 ]
a012c614:  98 10 20 01  mov  1, %o4
a012c618:  9a 10 20 00  clr  %o5
a012c61c:  67 fd 7b 72  call  0x4008b3e4
a012c620:  90 10 00 13  mov  %l3, %o0
a012c624:  a1 36 e0 10  srl  %i3, 0x10, %l0
a012c628:  9f 34 a0 10  srl  %l2, 0x10, %o7
a012c62c:  aa 10 3f a0  mov  -96, %l5
a012c630:  96 04 00 1a  add  %l0, %i2, %o3
a012c634:  90 07 bf c8  add  %fp, -56, %o0
a012c638:  92 0c 20 ff  and  %l0, 0xff, %o1
a012c63c:  94 10 21 00  mov  0x100, %o2
a012c640:  80 a3 e1 00  cmp  %o7, 0x100
a012c644:  18 bf ff df  bgu  0xa012c5c0
a012c648:  ea 2f bf de  stb  %l5, [ %fp + -34 ]
a012c64c:  d8 1f bf d8  ldd  [ %fp + -40 ], %o4
a012c650:  e4 17 bf e0  lduh  [ %fp + -32 ], %l2
a012c654:  d8 3f bf a8  std  %o4, [ %fp + -88 ]
a012c658:  e4 37 bf b0  sth  %l2, [ %fp + -80 ]
a012c65c:  94 10 00 0f  mov  %o7, %o2
a012c660:  96 04 00 1a  add  %l0, %i2, %o3
a012c664:  b2 06 40 11  add  %i1, %l1, %i1
a012c668:  90 07 bf a8  add  %fp, -88, %o0
a012c66c:  67 fd 7d 2f  call  0x4008bb28
a012c670:  92 0c 20 ff  and  %l0, 0xff, %o1
a012c674:  10 bf ff da  b  0xa012c5dc
a012c678:  a2 10 20 00  clr  %l1
a012c67c:  7f ff e3 c9  call  0xa01255a0
a012c680:  90 10 00 18  mov  %i0, %o0
a012c684:  a0 10 00 08  mov  %o0, %l0
a012c688:  a3 2c 20 10  sll  %l0, 0x10, %l1
a012c68c:  83 34 60 10  srl  %l1, 0x10, %g1
a012c690:  d0 36 c0 00  sth  %o0, [ %i3 ]
a012c694:  80 a0 60 00  cmp  %g1, 0
a012c698:  02 80 00 5b  be  0xa012c804
a012c69c:  a2 10 20 00  clr  %l1
a012c6a0:  10 80 00 0b  b  0xa012c6cc
a012c6a4:  9a 10 00 01  mov  %g1, %o5
a012c6a8:  40 00 23 e1  call  0xa013562c
a012c6ac:  a4 04 a0 80  add  %l2, 0x80, %l2
a012c6b0:  a2 04 60 80  add  %l1, 0x80, %l1
a012c6b4:  a0 04 3f 80  add  %l0, -128, %l0
a012c6b8:  97 2c 20 10  sll  %l0, 0x10, %o3
a012c6bc:  9b 32 e0 10  srl  %o3, 0x10, %o5
a012c6c0:  80 a3 60 00  cmp  %o5, 0
a012c6c4:  02 80 00 50  be  0xa012c804
a012c6c8:  01 00 00 00  nop
a012c6cc:  95 2c 60 10  sll  %l1, 0x10, %o2
a012c6d0:  93 32 a0 10  srl  %o2, 0x10, %o1
a012c6d4:  91 2c a0 10  sll  %l2, 0x10, %o0
a012c6d8:  82 10 00 09  mov  %o1, %g1
a012c6dc:  94 02 40 1a  add  %o1, %i2, %o2
a012c6e0:  91 32 20 10  srl  %o0, 0x10, %o0
a012c6e4:  92 10 20 80  mov  0x80, %o1
a012c6e8:  80 a3 60 80  cmp  %o5, 0x80
a012c6ec:  18 bf ff ef  bgu  0xa012c6a8
a012c6f0:  99 2c a0 10  sll  %l2, 0x10, %o4
a012c6f4:  92 0c 20 ff  and  %l0, 0xff, %o1
a012c6f8:  91 33 20 10  srl  %o4, 0x10, %o0
a012c6fc:  40 00 23 cc  call  0xa013562c
a012c700:  94 00 40 1a  add  %g1, %i2, %o2
a012c704:  10 bf ff ed  b  0xa012c6b8
a012c708:  a0 10 20 00  clr  %l0
a012c70c:  a1 2e 60 10  sll  %i1, 0x10, %l0
a012c710:  b3 2a 20 10  sll  %o0, 0x10, %i1
a012c714:  d8 1f bf d8  ldd  [ %fp + -40 ], %o4
a012c718:  e6 17 bf e0  lduh  [ %fp + -32 ], %l3
a012c71c:  d8 3f bf a8  std  %o4, [ %fp + -88 ]
a012c720:  e6 37 bf b0  sth  %l3, [ %fp + -80 ]
a012c724:  93 34 20 10  srl  %l0, 0x10, %o1
a012c728:  95 36 60 10  srl  %i1, 0x10, %o2
a012c72c:  96 10 00 1a  mov  %i2, %o3
a012c730:  67 fd 7c fe  call  0x4008bb28
a012c734:  90 07 bf a8  add  %fp, -88, %o0
a012c738:  7f ff df 24  call  0xa01243c8
a012c73c:  90 10 00 18  mov  %i0, %o0
a012c740:  94 10 20 01  mov  1, %o2
a012c744:  b5 2a 80 18  sll  %o2, %i0, %i2
a012c748:  92 0a 20 ff  and  %o0, 0xff, %o1
a012c74c:  40 00 1d cc  call  0xa0133e7c
a012c750:  90 0e a0 ff  and  %i2, 0xff, %o0
a012c754:  30 80 00 2c  b,a   0xa012c804
a012c758:  92 0e 7f f0  and  %i1, -16, %o1
a012c75c:  94 02 40 12  add  %o1, %l2, %o2
a012c760:  91 2a a0 10  sll  %o2, 0x10, %o0
a012c764:  b2 10 00 09  mov  %o1, %i1
a012c768:  92 10 20 10  mov  0x10, %o1
a012c76c:  91 32 20 10  srl  %o0, 0x10, %o0
a012c770:  40 00 23 af  call  0xa013562c
a012c774:  94 07 bf e8  add  %fp, -24, %o2
a012c778:  82 10 20 10  mov  0x10, %g1
a012c77c:  92 0c 60 0f  and  %l1, 0xf, %o1
a012c780:  9a 20 40 09  sub  %g1, %o1, %o5
a012c784:  c2 16 c0 00  lduh  [ %i3 ], %g1
a012c788:  80 a0 40 0d  cmp  %g1, %o5
a012c78c:  04 80 00 03  ble  0xa012c798
a012c790:  96 10 00 01  mov  %g1, %o3
a012c794:  82 10 00 0d  mov  %o5, %g1
a012c798:  99 28 60 10  sll  %g1, 0x10, %o4
a012c79c:  aa 10 00 01  mov  %g1, %l5
a012c7a0:  9b 33 20 10  srl  %o4, 0x10, %o5
a012c7a4:  80 a3 60 00  cmp  %o5, 0
a012c7a8:  94 10 20 00  clr  %o2
a012c7ac:  02 80 00 0f  be  0xa012c7e8
a012c7b0:  9f 2d 60 10  sll  %l5, 0x10, %o7
a012c7b4:  96 07 bf f8  add  %fp, -8, %o3
a012c7b8:  90 02 c0 09  add  %o3, %o1, %o0
a012c7bc:  9e 10 00 0c  mov  %o4, %o7
a012c7c0:  92 10 00 0d  mov  %o5, %o1
a012c7c4:  a6 0a a0 ff  and  %o2, 0xff, %l3
a012c7c8:  a8 02 00 13  add  %o0, %l3, %l4
a012c7cc:  94 02 a0 01  inc  %o2
a012c7d0:  da 0d 3f f0  ldub  [ %l4 + -16 ], %o5
a012c7d4:  98 0a a0 ff  and  %o2, 0xff, %o4
a012c7d8:  80 a3 00 09  cmp  %o4, %o1
a012c7dc:  0a bf ff fa  bcs  0xa012c7c4
a012c7e0:  da 2c c0 1a  stb  %o5, [ %l3 + %i2 ]
a012c7e4:  d6 16 c0 00  lduh  [ %i3 ], %o3
a012c7e8:  ad 2a e0 10  sll  %o3, 0x10, %l6
a012c7ec:  80 a3 c0 16  cmp  %o7, %l6
a012c7f0:  3a bf fe e3  bcc,a   0xa012c37c
a012c7f4:  a0 10 20 00  clr  %l0
a012c7f8:  a2 06 60 10  add  %i1, 0x10, %l1
a012c7fc:  10 bf fe e0  b  0xa012c37c
a012c800:  a0 24 00 15  sub  %l0, %l5, %l0
a012c804:  81 c7 e0 08  ret
a012c808:  81 e8 00 00  restore
