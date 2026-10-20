# leon2m FUN_a00dc3dc 0xa00dc3dc-0xa00dcd38 (2396 bytes)
a00dc3dc:  9d e3 bf 68  save  %sp, -152, %sp
a00dc3e0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00dc3e4:  ac 14 22 90  or  %l0, 0x290, %l6	! 0xa802d290
a00dc3e8:  40 01 21 88  call  0xa0124a08
a00dc3ec:  f6 15 a1 f6  lduh  [ %l6 + 0x1f6 ], %i3
a00dc3f0:  40 01 21 2f  call  0xa01248ac
a00dc3f4:  ae 10 00 10  mov  %l0, %l7
a00dc3f8:  92 10 20 00  clr  %o1
a00dc3fc:  40 01 a3 4c  call  0xa014512c
a00dc400:  90 10 20 00  clr  %o0
a00dc404:  40 01 ad 7a  call  0xa01479ec
a00dc408:  90 10 20 01  mov  1, %o0
a00dc40c:  e4 05 a0 a8  ld  [ %l6 + 0xa8 ], %l2
a00dc410:  de 05 a1 d4  ld  [ %l6 + 0x1d4 ], %o7
a00dc414:  83 34 a0 07  srl  %l2, 7, %g1
a00dc418:  9b 33 e0 06  srl  %o7, 6, %o5
a00dc41c:  d8 0d a1 e2  ldub  [ %l6 + 0x1e2 ], %o4
a00dc420:  d6 0d a1 e3  ldub  [ %l6 + 0x1e3 ], %o3
a00dc424:  d4 0d a1 e6  ldub  [ %l6 + 0x1e6 ], %o2
a00dc428:  d2 0d a1 e7  ldub  [ %l6 + 0x1e7 ], %o1
a00dc42c:  d0 0d a1 a4  ldub  [ %l6 + 0x1a4 ], %o0
a00dc430:  a2 10 00 16  mov  %l6, %l1
a00dc434:  d8 2f bf f0  stb  %o4, [ %fp + -16 ]
a00dc438:  d6 2f bf f1  stb  %o3, [ %fp + -15 ]
a00dc43c:  d4 2f bf e8  stb  %o2, [ %fp + -24 ]
a00dc440:  d2 2f bf e9  stb  %o1, [ %fp + -23 ]
a00dc444:  80 a2 20 03  cmp  %o0, 3
a00dc448:  b8 08 60 01  and  %g1, 1, %i4
a00dc44c:  a0 0b 60 01  and  %o5, 1, %l0
a00dc450:  ba 10 20 00  clr  %i5
a00dc454:  e6 0d a0 1e  ldub  [ %l6 + 0x1e ], %l3
a00dc458:  e8 0d a0 08  ldub  [ %l6 + 8 ], %l4
a00dc45c:  ea 0d a1 d8  ldub  [ %l6 + 0x1d8 ], %l5
a00dc460:  02 80 02 02  be  0xa00dcc68
a00dc464:  e4 15 a1 da  lduh  [ %l6 + 0x1da ], %l2
a00dc468:  15 00 06 61  sethi  %hi(0x198400), %o2
a00dc46c:  92 12 a1 24  or  %o2, 0x124, %o1	! 0x198524
a00dc470:  90 10 00 11  mov  %l1, %o0
a00dc474:  40 01 81 27  call  0xa013c910
a00dc478:  94 10 21 fc  mov  0x1fc, %o2
a00dc47c:  80 a0 00 10  cmp  %g0, %l0
a00dc480:  92 40 20 00  addx  %g0, 0, %o1
a00dc484:  d0 04 61 d4  ld  [ %l1 + 0x1d4 ], %o0
a00dc488:  83 2a 60 06  sll  %o1, 6, %g1
a00dc48c:  a0 0a 3f bf  and  %o0, -65, %l0
a00dc490:  9a 14 00 01  or  %l0, %g1, %o5
a00dc494:  e6 2c 60 1e  stb  %l3, [ %l1 + 0x1e ]
a00dc498:  e8 2c 60 08  stb  %l4, [ %l1 + 8 ]
a00dc49c:  e4 34 61 da  sth  %l2, [ %l1 + 0x1da ]
a00dc4a0:  80 8b 60 40  btst  0x40, %o5
a00dc4a4:  da 24 61 d4  st  %o5, [ %l1 + 0x1d4 ]
a00dc4a8:  12 80 01 cf  bne  0xa00dcbe4
a00dc4ac:  ea 2c 61 d8  stb  %l5, [ %l1 + 0x1d8 ]
a00dc4b0:  29 2a 00 b3  sethi  %hi(0xa802cc00), %l4
a00dc4b4:  9e 15 23 f4  or  %l4, 0x3f4, %o7	! 0xa802cff4
a00dc4b8:  d8 0f bf f0  ldub  [ %fp + -16 ], %o4
a00dc4bc:  d6 0f bf f1  ldub  [ %fp + -15 ], %o3
a00dc4c0:  e4 0c 61 a0  ldub  [ %l1 + 0x1a0 ], %l2
a00dc4c4:  ea 0f bf e8  ldub  [ %fp + -24 ], %l5
a00dc4c8:  e6 0f bf e9  ldub  [ %fp + -23 ], %l3
a00dc4cc:  e4 2b e0 09  stb  %l2, [ %o7 + 9 ]
a00dc4d0:  d8 2c 61 e2  stb  %o4, [ %l1 + 0x1e2 ]
a00dc4d4:  d6 2c 61 e3  stb  %o3, [ %l1 + 0x1e3 ]
a00dc4d8:  ea 2c 61 e6  stb  %l5, [ %l1 + 0x1e6 ]
a00dc4dc:  7f ff f1 fe  call  0xa00d8cd4
a00dc4e0:  e6 2c 61 e7  stb  %l3, [ %l1 + 0x1e7 ]
a00dc4e4:  7f ff ee 3f  call  0xa00d7de0
a00dc4e8:  01 00 00 00  nop
a00dc4ec:  7f ff ed b5  call  0xa00d7bc0
a00dc4f0:  01 00 00 00  nop
a00dc4f4:  d2 0c 60 12  ldub  [ %l1 + 0x12 ], %o1
a00dc4f8:  80 a2 60 64  cmp  %o1, 0x64
a00dc4fc:  38 80 00 02  bgu,a   0xa00dc504
a00dc500:  92 10 20 64  mov  0x64, %o1
a00dc504:  d2 2c 60 12  stb  %o1, [ %l1 + 0x12 ]
a00dc508:  92 0a 60 ff  and  %o1, 0xff, %o1
a00dc50c:  40 01 b7 04  call  0xa014a11c
a00dc510:  90 10 20 00  clr  %o0
a00dc514:  d2 0c 60 13  ldub  [ %l1 + 0x13 ], %o1
a00dc518:  80 a2 60 64  cmp  %o1, 0x64
a00dc51c:  38 80 00 02  bgu,a   0xa00dc524
a00dc520:  92 10 20 64  mov  0x64, %o1
a00dc524:  d2 2c 60 13  stb  %o1, [ %l1 + 0x13 ]
a00dc528:  92 0a 60 ff  and  %o1, 0xff, %o1
a00dc52c:  40 01 b6 fc  call  0xa014a11c
a00dc530:  90 10 20 01  mov  1, %o0
a00dc534:  c2 0c 60 14  ldub  [ %l1 + 0x14 ], %g1
a00dc538:  80 a0 60 64  cmp  %g1, 0x64
a00dc53c:  38 80 00 02  bgu,a   0xa00dc544
a00dc540:  82 10 20 64  mov  0x64, %g1
a00dc544:  92 08 60 ff  and  %g1, 0xff, %o1
a00dc548:  c2 2c 60 14  stb  %g1, [ %l1 + 0x14 ]
a00dc54c:  40 01 b6 f4  call  0xa014a11c
a00dc550:  90 10 20 02  mov  2, %o0
a00dc554:  7f ff f3 ea  call  0xa00d94fc
a00dc558:  01 00 00 00  nop
a00dc55c:  7f ff f4 82  call  0xa00d9764
a00dc560:  01 00 00 00  nop
a00dc564:  c2 0c 60 0f  ldub  [ %l1 + 0xf ], %g1
a00dc568:  80 a0 60 05  cmp  %g1, 5
a00dc56c:  38 80 00 02  bgu,a   0xa00dc574
a00dc570:  82 10 20 05  mov  5, %g1
a00dc574:  90 08 60 ff  and  %g1, 0xff, %o0
a00dc578:  40 01 b7 84  call  0xa014a388
a00dc57c:  c2 2d a0 0f  stb  %g1, [ %l6 + 0xf ]
a00dc580:  7f fe d2 85  call  0xa0090f94
a00dc584:  d0 0d a0 0c  ldub  [ %l6 + 0xc ], %o0
a00dc588:  7f ff f2 e6  call  0xa00d9120
a00dc58c:  01 00 00 00  nop
a00dc590:  40 01 bd f8  call  0xa014bd70
a00dc594:  90 10 20 00  clr  %o0	! 0x0
a00dc598:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00dc59c:  80 a4 60 01  cmp  %l1, 1
a00dc5a0:  02 80 01 27  be  0xa00dca3c
a00dc5a4:  01 00 00 00  nop
a00dc5a8:  40 01 9c cd  call  0xa01438dc
a00dc5ac:  90 10 20 00  clr  %o0	! 0x0
a00dc5b0:  ac 0a 20 ff  and  %o0, 0xff, %l6
a00dc5b4:  80 a5 a0 01  cmp  %l6, 1
a00dc5b8:  02 80 01 14  be  0xa00dca08
a00dc5bc:  82 15 e2 90  or  %l7, 0x290, %g1
a00dc5c0:  e0 00 61 74  ld  [ %g1 + 0x174 ], %l0
a00dc5c4:  1b 00 00 20  sethi  %hi(0x8000), %o5
a00dc5c8:  80 8c 00 0d  btst  %l0, %o5
a00dc5cc:  02 80 01 1c  be  0xa00dca3c
a00dc5d0:  90 10 20 01  mov  1, %o0
a00dc5d4:  40 01 c8 a9  call  0xa014e878
a00dc5d8:  01 00 00 00  nop
a00dc5dc:  7f ff f2 d1  call  0xa00d9120
a00dc5e0:  01 00 00 00  nop
a00dc5e4:  90 15 e2 90  or  %l7, 0x290, %o0
a00dc5e8:  d8 02 21 1c  ld  [ %o0 + 0x11c ], %o4
a00dc5ec:  a1 33 20 1f  srl  %o4, 0x1f, %l0
a00dc5f0:  94 0c 20 ff  and  %l0, 0xff, %o2
a00dc5f4:  17 20 00 00  sethi  %hi(0x80000000), %o3
a00dc5f8:  a6 2b 00 0b  andn  %o4, %o3, %l3
a00dc5fc:  ab 2a a0 1f  sll  %o2, 0x1f, %l5
a00dc600:  92 14 c0 15  or  %l3, %l5, %o1
a00dc604:  80 a2 a0 01  cmp  %o2, 1
a00dc608:  02 80 01 1c  be  0xa00dca78
a00dc60c:  d2 22 21 1c  st  %o1, [ %o0 + 0x11c ]
a00dc610:  80 a2 a0 01  cmp  %o2, 1
a00dc614:  04 80 01 a3  ble  0xa00dcca0
a00dc618:  80 a2 a0 02  cmp  %o2, 2
a00dc61c:  22 80 00 02  be,a   0xa00dc624
a00dc620:  a0 10 20 02  mov  2, %l0
a00dc624:  40 01 bd d3  call  0xa014bd70
a00dc628:  90 10 20 00  clr  %o0
a00dc62c:  94 0a 20 ff  and  %o0, 0xff, %o2
a00dc630:  80 a2 a0 01  cmp  %o2, 1
a00dc634:  22 80 01 18  be,a   0xa00dca94
a00dc638:  a0 10 20 00  clr  %l0
a00dc63c:  40 01 9c a8  call  0xa01438dc
a00dc640:  90 10 20 00  clr  %o0
a00dc644:  9e 0a 20 ff  and  %o0, 0xff, %o7
a00dc648:  80 a3 e0 01  cmp  %o7, 1
a00dc64c:  02 80 01 99  be  0xa00dccb0
a00dc650:  01 00 00 00  nop
a00dc654:  40 01 b3 19  call  0xa01492b8
a00dc658:  90 0c 20 03  and  %l0, 3, %o0
a00dc65c:  a0 15 e2 90  or  %l7, 0x290, %l0
a00dc660:  e4 04 21 1c  ld  [ %l0 + 0x11c ], %l2
a00dc664:  80 a4 a0 00  cmp  %l2, 0
a00dc668:  16 80 01 12  bge  0xa00dcab0
a00dc66c:  01 00 00 00  nop
a00dc670:  7f fe 9a a1  call  0xa00830f4
a00dc674:  90 10 20 00  clr  %o0	! 0x0
a00dc678:  7f ff f2 f0  call  0xa00d9238
a00dc67c:  23 00 00 10  sethi  %hi(0x4000), %l1
a00dc680:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00dc684:  d0 00 62 90  ld  [ %g1 + 0x290 ], %o0	! 0xa802d290
a00dc688:  9b 32 20 09  srl  %o0, 9, %o5
a00dc68c:  40 01 b1 c3  call  0xa0148d98
a00dc690:  90 0b 60 01  and  %o5, 1, %o0
a00dc694:  ec 04 20 a8  ld  [ %l0 + 0xa8 ], %l6
a00dc698:  80 8d 80 11  btst  %l6, %l1
a00dc69c:  12 80 01 14  bne  0xa00dcaec
a00dc6a0:  01 00 00 00  nop
a00dc6a4:  90 10 20 01  mov  1, %o0	! 0x1
a00dc6a8:  40 01 b4 b4  call  0xa0149978
a00dc6ac:  d2 0c 20 20  ldub  [ %l0 + 0x20 ], %o1
a00dc6b0:  7f ff f6 e9  call  0xa00da254
a00dc6b4:  01 00 00 00  nop
a00dc6b8:  90 10 20 01  mov  1, %o0	! 0x1
a00dc6bc:  7f ff e6 66  call  0xa00d6054
a00dc6c0:  92 07 bf d8  add  %fp, -40, %o1
a00dc6c4:  d8 1f bf d8  ldd  [ %fp + -40 ], %o4
a00dc6c8:  d4 1f bf e0  ldd  [ %fp + -32 ], %o2
a00dc6cc:  d8 3f bf c8  std  %o4, [ %fp + -56 ]
a00dc6d0:  d4 3f bf d0  std  %o2, [ %fp + -48 ]
a00dc6d4:  90 10 20 01  mov  1, %o0
a00dc6d8:  40 01 b5 2d  call  0xa0149b8c
a00dc6dc:  92 07 bf c8  add  %fp, -56, %o1
a00dc6e0:  40 01 b5 eb  call  0xa0149e8c
a00dc6e4:  90 10 20 01  mov  1, %o0
a00dc6e8:  80 8f 60 ff  btst  0xff, %i5
a00dc6ec:  12 80 01 48  bne  0xa00dcc0c
a00dc6f0:  90 10 20 02  mov  2, %o0
a00dc6f4:  7f ff fa 58  call  0xa00db054
a00dc6f8:  01 00 00 00  nop
a00dc6fc:  90 10 20 00  clr  %o0	! 0x0
a00dc700:  40 01 ae da  call  0xa0148268
a00dc704:  92 10 20 01  mov  1, %o1
a00dc708:  fa 04 20 a8  ld  [ %l0 + 0xa8 ], %i5
a00dc70c:  80 8f 60 40  btst  0x40, %i5
a00dc710:  02 80 01 21  be  0xa00dcb94
a00dc714:  01 00 00 00  nop
a00dc718:  40 01 24 e5  call  0xa0125aac
a00dc71c:  01 00 00 00  nop
a00dc720:  40 01 2c 83  call  0xa012792c
a00dc724:  01 00 00 00  nop
a00dc728:  80 8a 20 ff  btst  0xff, %o0
a00dc72c:  12 80 00 0c  bne  0xa00dc75c
a00dc730:  01 00 00 00  nop
a00dc734:  40 01 2c 84  call  0xa0127944
a00dc738:  01 00 00 00  nop
a00dc73c:  80 8a 20 ff  btst  0xff, %o0
a00dc740:  12 80 00 07  bne  0xa00dc75c
a00dc744:  01 00 00 00  nop
a00dc748:  92 15 e2 90  or  %l7, 0x290, %o1
a00dc74c:  e0 02 60 a8  ld  [ %o1 + 0xa8 ], %l0
a00dc750:  80 8c 20 20  btst  0x20, %l0
a00dc754:  02 80 01 47  be  0xa00dcc70
a00dc758:  01 00 00 00  nop
a00dc75c:  40 01 25 36  call  0xa0125c34
a00dc760:  a4 15 e2 90  or  %l7, 0x290, %l2
a00dc764:  d6 0c a0 ac  ldub  [ %l2 + 0xac ], %o3
a00dc768:  95 2a e0 02  sll  %o3, 2, %o2
a00dc76c:  98 02 80 0b  add  %o2, %o3, %o4
a00dc770:  a1 2b 20 02  sll  %o4, 2, %l0
a00dc774:  a6 04 20 14  add  %l0, 0x14, %l3
a00dc778:  ac 0c e0 fc  and  %l3, 0xfc, %l6
a00dc77c:  03 00 06 62  sethi  %hi(0x198800), %g1
a00dc780:  92 10 00 16  mov  %l6, %o1
a00dc784:  40 00 0a 7b  call  0xa00df170
a00dc788:  90 10 61 28  or  %g1, 0x128, %o0
a00dc78c:  11 14 7a e1  sethi  %hi(0x51eb8400), %o0
a00dc790:  9e 12 21 1f  or  %o0, 0x11f, %o7	! 0x51eb851f
a00dc794:  80 55 80 0f  umul  %l6, %o7, %g0
a00dc798:  a3 40 00 00  rd  %y, %l1
a00dc79c:  9f 34 60 05  srl  %l1, 5, %o7
a00dc7a0:  aa 0b e0 ff  and  %o7, 0xff, %l5
a00dc7a4:  92 5d 60 64  smul  %l5, 0x64, %o1
a00dc7a8:  ac 24 c0 09  sub  %l3, %o1, %l6
a00dc7ac:  3b 33 33 33  sethi  %hi(0xcccccc00), %i5
a00dc7b0:  9a 0d a0 fc  and  %l6, 0xfc, %o5
a00dc7b4:  a6 17 60 cd  or  %i5, 0xcd, %l3
a00dc7b8:  80 53 40 13  umul  %o5, %l3, %g0
a00dc7bc:  97 40 00 00  rd  %y, %o3
a00dc7c0:  ab 32 e0 03  srl  %o3, 3, %l5
a00dc7c4:  94 0d 60 ff  and  %l5, 0xff, %o2
a00dc7c8:  99 2a a0 02  sll  %o2, 2, %o4
a00dc7cc:  82 03 00 0a  add  %o4, %o2, %g1
a00dc7d0:  90 00 40 01  add  %g1, %g1, %o0
a00dc7d4:  a0 25 80 08  sub  %l6, %o0, %l0
a00dc7d8:  3b 2a 00 b4  sethi  %hi(0xa802d000), %i5
a00dc7dc:  a2 03 e0 30  add  %o7, 0x30, %l1
a00dc7e0:  9e 17 62 68  or  %i5, 0x268, %o7
a00dc7e4:  90 04 20 30  add  %l0, 0x30, %o0
a00dc7e8:  92 10 20 35  mov  0x35, %o1
a00dc7ec:  94 10 20 37  mov  0x37, %o2
a00dc7f0:  82 05 60 30  add  %l5, 0x30, %g1
a00dc7f4:  ac 10 20 30  mov  0x30, %l6
a00dc7f8:  9a 10 20 62  mov  0x62, %o5
a00dc7fc:  d4 2b e0 04  stb  %o2, [ %o7 + 4 ]
a00dc800:  98 10 20 34  mov  0x34, %o4
a00dc804:  d0 2b e0 09  stb  %o0, [ %o7 + 9 ]
a00dc808:  96 10 20 0d  mov  0xd, %o3
a00dc80c:  d2 2f 62 68  stb  %o1, [ %i5 + 0x268 ]
a00dc810:  da 2b e0 01  stb  %o5, [ %o7 + 1 ]
a00dc814:  d8 2b e0 05  stb  %o4, [ %o7 + 5 ]
a00dc818:  ec 2b e0 06  stb  %l6, [ %o7 + 6 ]
a00dc81c:  e2 2b e0 07  stb  %l1, [ %o7 + 7 ]
a00dc820:  c2 2b e0 08  stb  %g1, [ %o7 + 8 ]
a00dc824:  d6 2b e0 0a  stb  %o3, [ %o7 + 0xa ]
a00dc828:  94 10 00 0f  mov  %o7, %o2
a00dc82c:  ec 2b e0 02  stb  %l6, [ %o7 + 2 ]
a00dc830:  ec 2b e0 03  stb  %l6, [ %o7 + 3 ]
a00dc834:  90 10 20 02  mov  2, %o0
a00dc838:  40 01 af ec  call  0xa01487e8
a00dc83c:  92 10 20 0b  mov  0xb, %o1
a00dc840:  40 01 62 27  call  0xa01350dc
a00dc844:  01 00 00 00  nop
a00dc848:  ea 04 a0 b0  ld  [ %l2 + 0xb0 ], %l5
a00dc84c:  80 a5 60 00  cmp  %l5, 0
a00dc850:  12 80 00 d6  bne  0xa00dcba8
a00dc854:  e0 0c a0 19  ldub  [ %l2 + 0x19 ], %l0
a00dc858:  82 0c 20 ff  and  %l0, 0xff, %g1
a00dc85c:  80 a0 60 03  cmp  %g1, 3
a00dc860:  08 80 00 05  bleu  0xa00dc874
a00dc864:  80 a0 60 00  cmp  %g1, 0
a00dc868:  a0 10 20 03  mov  3, %l0
a00dc86c:  82 10 20 03  mov  3, %g1
a00dc870:  80 a0 60 00  cmp  %g1, 0
a00dc874:  02 80 00 cb  be  0xa00dcba0
a00dc878:  e0 2c a0 8f  stb  %l0, [ %l2 + 0x8f ]
a00dc87c:  c0 2c a0 19  clrb  [ %l2 + 0x19 ]
a00dc880:  40 01 b2 2f  call  0xa014913c
a00dc884:  90 10 20 05  mov  5, %o0
a00dc888:  a4 15 e2 90  or  %l7, 0x290, %l2
a00dc88c:  e6 0c a0 8f  ldub  [ %l2 + 0x8f ], %l3
a00dc890:  e6 2c a0 19  stb  %l3, [ %l2 + 0x19 ]
a00dc894:  a0 15 e2 90  or  %l7, 0x290, %l0
a00dc898:  de 14 20 34  lduh  [ %l0 + 0x34 ], %o7
a00dc89c:  92 0b e0 0f  and  %o7, 0xf, %o1
a00dc8a0:  40 01 b1 f1  call  0xa0149064
a00dc8a4:  90 10 20 00  clr  %o0
a00dc8a8:  ec 14 20 34  lduh  [ %l0 + 0x34 ], %l6
a00dc8ac:  92 0d a0 0f  and  %l6, 0xf, %o1
a00dc8b0:  40 01 b1 ed  call  0xa0149064
a00dc8b4:  90 10 20 01  mov  1, %o0
a00dc8b8:  e2 0c 20 4a  ldub  [ %l0 + 0x4a ], %l1
a00dc8bc:  80 a4 60 00  cmp  %l1, 0
a00dc8c0:  02 80 00 0b  be  0xa00dc8ec
a00dc8c4:  98 15 e2 90  or  %l7, 0x290, %o4
a00dc8c8:  d0 04 20 b0  ld  [ %l0 + 0xb0 ], %o0
a00dc8cc:  80 a2 20 00  cmp  %o0, 0
a00dc8d0:  22 80 00 08  be,a   0xa00dc8f0
a00dc8d4:  e0 03 21 ec  ld  [ %o4 + 0x1ec ], %l0
a00dc8d8:  c2 0c 20 1f  ldub  [ %l0 + 0x1f ], %g1
a00dc8dc:  80 a0 60 00  cmp  %g1, 0
a00dc8e0:  02 80 00 e8  be  0xa00dcc80
a00dc8e4:  c0 2c 20 4a  clrb  [ %l0 + 0x4a ]
a00dc8e8:  98 15 e2 90  or  %l7, 0x290, %o4
a00dc8ec:  e0 03 21 ec  ld  [ %o4 + 0x1ec ], %l0
a00dc8f0:  80 8c 20 80  btst  0x80, %l0
a00dc8f4:  12 80 00 a0  bne  0xa00dcb74
a00dc8f8:  ba 15 e2 90  or  %l7, 0x290, %i5
a00dc8fc:  40 01 23 fc  call  0xa01258ec
a00dc900:  01 00 00 00  nop
a00dc904:  da 07 60 a8  ld  [ %i5 + 0xa8 ], %o5
a00dc908:  94 0f 20 ff  and  %i4, 0xff, %o2
a00dc90c:  97 33 60 07  srl  %o5, 7, %o3
a00dc910:  b8 0a e0 01  and  %o3, 1, %i4
a00dc914:  80 a2 80 1c  cmp  %o2, %i4
a00dc918:  02 80 00 04  be  0xa00dc928
a00dc91c:  01 00 00 00  nop
a00dc920:  7f ff f6 19  call  0xa00da184
a00dc924:  01 00 00 00  nop
a00dc928:  40 01 bd 12  call  0xa014bd70
a00dc92c:  90 10 20 00  clr  %o0	! 0x0
a00dc930:  92 0a 20 ff  and  %o0, 0xff, %o1
a00dc934:  80 a2 60 01  cmp  %o1, 1
a00dc938:  22 80 00 7f  be,a   0xa00dcb34
a00dc93c:  a4 15 23 f4  or  %l4, 0x3f4, %l2
a00dc940:  40 01 9b e7  call  0xa01438dc
a00dc944:  90 10 20 00  clr  %o0
a00dc948:  aa 0a 20 ff  and  %o0, 0xff, %l5
a00dc94c:  80 a5 60 01  cmp  %l5, 1
a00dc950:  02 80 00 6b  be  0xa00dcafc
a00dc954:  96 15 e2 90  or  %l7, 0x290, %o3
a00dc958:  d4 02 e1 f4  ld  [ %o3 + 0x1f4 ], %o2
a00dc95c:  39 10 00 00  sethi  %hi(0x40000000), %i4
a00dc960:  80 8a 80 1c  btst  %o2, %i4
a00dc964:  12 80 00 03  bne  0xa00dc970
a00dc968:  90 10 20 01  mov  1, %o0
a00dc96c:  90 10 20 00  clr  %o0
a00dc970:  40 01 1e 93  call  0xa01243bc
a00dc974:  ba 15 e2 90  or  %l7, 0x290, %i5
a00dc978:  40 01 20 3c  call  0xa0124a68
a00dc97c:  01 00 00 00  nop
a00dc980:  40 01 20 70  call  0xa0124b40
a00dc984:  01 00 00 00  nop
a00dc988:  da 07 60 a8  ld  [ %i5 + 0xa8 ], %o5
a00dc98c:  80 8b 68 00  btst  0x800, %o5
a00dc990:  12 80 00 7d  bne  0xa00dcb84
a00dc994:  01 00 00 00  nop
a00dc998:  7f ff fc d6  call  0xa00dbcf0
a00dc99c:  a0 15 e2 90  or  %l7, 0x290, %l0
a00dc9a0:  ee 0c 21 d5  ldub  [ %l0 + 0x1d5 ], %l7
a00dc9a4:  80 a5 e0 00  cmp  %l7, 0
a00dc9a8:  32 80 00 02  bne,a   0xa00dc9b0
a00dc9ac:  c0 2c 21 d5  clrb  [ %l0 + 0x1d5 ]
a00dc9b0:  2b 00 00 15  sethi  %hi(0x5400), %l5
a00dc9b4:  98 15 61 aa  or  %l5, 0x1aa, %o4	! 0x55aa
a00dc9b8:  d2 14 21 f6  lduh  [ %l0 + 0x1f6 ], %o1
a00dc9bc:  80 a2 40 0c  cmp  %o1, %o4
a00dc9c0:  02 80 00 9a  be  0xa00dcc28
a00dc9c4:  a7 2e e0 10  sll  %i3, 0x10, %l3
a00dc9c8:  b7 34 e0 10  srl  %l3, 0x10, %i3
a00dc9cc:  80 a6 c0 0c  cmp  %i3, %o4
a00dc9d0:  22 80 00 9d  be,a   0xa00dcc44
a00dc9d4:  90 10 20 06  mov  6, %o0
a00dc9d8:  e2 0c 21 d6  ldub  [ %l0 + 0x1d6 ], %l1
a00dc9dc:  80 a4 60 00  cmp  %l1, 0
a00dc9e0:  32 80 00 02  bne,a   0xa00dc9e8
a00dc9e4:  c0 2c 21 d6  clrb  [ %l0 + 0x1d6 ]
a00dc9e8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00dc9ec:  92 13 e2 74  or  %o7, 0x274, %o1	! 0xa802d274
a00dc9f0:  ec 0a 60 14  ldub  [ %o1 + 0x14 ], %l6
a00dc9f4:  80 a5 a0 00  cmp  %l6, 0
a00dc9f8:  22 80 00 c8  be,a   0xa00dcd18
a00dc9fc:  90 10 20 00  clr  %o0
a00dca00:  10 80 00 7d  b  0xa00dcbf4
a00dca04:  c0 2a 60 14  clrb  [ %o1 + 0x14 ]
a00dca08:  40 01 bc 18  call  0xa014ba68
a00dca0c:  01 00 00 00  nop
a00dca10:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dca14:  80 a2 20 02  cmp  %o0, 2
a00dca18:  02 80 00 09  be  0xa00dca3c
a00dca1c:  01 00 00 00  nop
a00dca20:  04 80 00 bb  ble  0xa00dcd0c
a00dca24:  80 a2 20 01  cmp  %o0, 1
a00dca28:  80 a2 20 03  cmp  %o0, 3
a00dca2c:  02 80 00 04  be  0xa00dca3c
a00dca30:  80 a2 20 04  cmp  %o0, 4
a00dca34:  12 bf fe e3  bne  0xa00dc5c0
a00dca38:  82 15 e2 90  or  %l7, 0x290, %g1
a00dca3c:  40 01 c7 8f  call  0xa014e878
a00dca40:  90 10 20 00  clr  %o0
a00dca44:  7f ff f1 b7  call  0xa00d9120
a00dca48:  01 00 00 00  nop
a00dca4c:  90 15 e2 90  or  %l7, 0x290, %o0
a00dca50:  d8 02 21 1c  ld  [ %o0 + 0x11c ], %o4
a00dca54:  a1 33 20 1f  srl  %o4, 0x1f, %l0
a00dca58:  94 0c 20 ff  and  %l0, 0xff, %o2
a00dca5c:  17 20 00 00  sethi  %hi(0x80000000), %o3
a00dca60:  a6 2b 00 0b  andn  %o4, %o3, %l3
a00dca64:  ab 2a a0 1f  sll  %o2, 0x1f, %l5
a00dca68:  92 14 c0 15  or  %l3, %l5, %o1
a00dca6c:  80 a2 a0 01  cmp  %o2, 1
a00dca70:  12 bf fe e9  bne  0xa00dc614
a00dca74:  d2 22 21 1c  st  %o1, [ %o0 + 0x11c ]
a00dca78:  40 01 bc be  call  0xa014bd70
a00dca7c:  90 10 20 00  clr  %o0
a00dca80:  94 0a 20 ff  and  %o0, 0xff, %o2
a00dca84:  80 a2 a0 01  cmp  %o2, 1
a00dca88:  12 bf fe ed  bne  0xa00dc63c
a00dca8c:  a0 10 20 01  mov  1, %l0
a00dca90:  a0 10 20 00  clr  %l0
a00dca94:  40 01 b2 09  call  0xa01492b8
a00dca98:  90 0c 20 03  and  %l0, 3, %o0
a00dca9c:  a0 15 e2 90  or  %l7, 0x290, %l0
a00dcaa0:  e4 04 21 1c  ld  [ %l0 + 0x11c ], %l2
a00dcaa4:  80 a4 a0 00  cmp  %l2, 0
a00dcaa8:  06 bf fe f2  bl  0xa00dc670
a00dcaac:  01 00 00 00  nop
a00dcab0:  7f ff f0 89  call  0xa00d8cd4
a00dcab4:  23 00 00 10  sethi  %hi(0x4000), %l1
a00dcab8:  7f fe 99 8f  call  0xa00830f4
a00dcabc:  90 10 20 00  clr  %o0
a00dcac0:  7f ff f1 de  call  0xa00d9238
a00dcac4:  01 00 00 00  nop
a00dcac8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00dcacc:  d0 00 62 90  ld  [ %g1 + 0x290 ], %o0	! 0xa802d290
a00dcad0:  9b 32 20 09  srl  %o0, 9, %o5
a00dcad4:  40 01 b0 b1  call  0xa0148d98
a00dcad8:  90 0b 60 01  and  %o5, 1, %o0
a00dcadc:  ec 04 20 a8  ld  [ %l0 + 0xa8 ], %l6
a00dcae0:  80 8d 80 11  btst  %l6, %l1
a00dcae4:  22 bf fe f1  be,a   0xa00dc6a8
a00dcae8:  90 10 20 01  mov  1, %o0
a00dcaec:  40 01 ab c0  call  0xa01479ec
a00dcaf0:  90 10 20 01  mov  1, %o0
a00dcaf4:  10 bf fe ed  b  0xa00dc6a8
a00dcaf8:  90 10 20 01  mov  1, %o0
a00dcafc:  40 01 bb db  call  0xa014ba68
a00dcb00:  01 00 00 00  nop
a00dcb04:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dcb08:  80 a2 20 02  cmp  %o0, 2
a00dcb0c:  02 80 00 0a  be  0xa00dcb34
a00dcb10:  a4 15 23 f4  or  %l4, 0x3f4, %l2
a00dcb14:  04 80 00 7a  ble  0xa00dccfc
a00dcb18:  80 a2 20 01  cmp  %o0, 1
a00dcb1c:  80 a2 20 03  cmp  %o0, 3
a00dcb20:  02 80 00 05  be  0xa00dcb34
a00dcb24:  80 a2 20 04  cmp  %o0, 4
a00dcb28:  12 bf ff 8c  bne  0xa00dc958
a00dcb2c:  96 15 e2 90  or  %l7, 0x290, %o3
a00dcb30:  a4 15 23 f4  or  %l4, 0x3f4, %l2
a00dcb34:  e8 14 a0 0a  lduh  [ %l2 + 0xa ], %l4
a00dcb38:  80 8d 20 80  btst  0x80, %l4
a00dcb3c:  12 bf ff 87  bne  0xa00dc958
a00dcb40:  96 15 e2 90  or  %l7, 0x290, %o3
a00dcb44:  a6 15 e2 90  or  %l7, 0x290, %l3
a00dcb48:  e0 04 e0 a8  ld  [ %l3 + 0xa8 ], %l0
a00dcb4c:  99 2c 20 03  sll  %l0, 3, %o4
a00dcb50:  82 0b 28 00  and  %o4, 0x800, %g1
a00dcb54:  90 0c 37 ff  and  %l0, -2049, %o0
a00dcb58:  ac 12 00 01  or  %o0, %g1, %l6
a00dcb5c:  e2 0c e1 88  ldub  [ %l3 + 0x188 ], %l1
a00dcb60:  de 0c e1 87  ldub  [ %l3 + 0x187 ], %o7
a00dcb64:  de 2c e1 81  stb  %o7, [ %l3 + 0x181 ]
a00dcb68:  ec 24 e0 a8  st  %l6, [ %l3 + 0xa8 ]
a00dcb6c:  10 bf ff 7b  b  0xa00dc958
a00dcb70:  e2 2c e1 82  stb  %l1, [ %l3 + 0x182 ]
a00dcb74:  40 01 23 57  call  0xa01258d0
a00dcb78:  01 00 00 00  nop
a00dcb7c:  10 bf ff 63  b  0xa00dc908
a00dcb80:  da 07 60 a8  ld  [ %i5 + 0xa8 ], %o5
a00dcb84:  7f ff fa ed  call  0xa00db738
a00dcb88:  a0 15 e2 90  or  %l7, 0x290, %l0
a00dcb8c:  10 bf ff 86  b  0xa00dc9a4
a00dcb90:  ee 0c 21 d5  ldub  [ %l0 + 0x1d5 ], %l7
a00dcb94:  40 01 23 cd  call  0xa0125ac8
a00dcb98:  01 00 00 00  nop
a00dcb9c:  30 bf fe e1  b,a   0xa00dc720
a00dcba0:  10 bf ff 38  b  0xa00dc880
a00dcba4:  e0 2c a0 19  stb  %l0, [ %l2 + 0x19 ]
a00dcba8:  92 10 20 01  mov  1, %o1
a00dcbac:  40 01 a2 ad  call  0xa0145660
a00dcbb0:  90 10 20 00  clr  %o0
a00dcbb4:  ab 2a 20 10  sll  %o0, 0x10, %l5
a00dcbb8:  93 35 60 10  srl  %l5, 0x10, %o1
a00dcbbc:  80 52 40 13  umul  %o1, %l3, %g0
a00dcbc0:  bb 40 00 00  rd  %y, %i5
a00dcbc4:  9b 2f 60 0d  sll  %i5, 0xd, %o5
a00dcbc8:  7f fe aa 24  call  0xa0087458
a00dcbcc:  91 33 60 10  srl  %o5, 0x10, %o0
a00dcbd0:  80 a2 20 00  cmp  %o0, 0
a00dcbd4:  02 bf ff 22  be  0xa00dc85c
a00dcbd8:  82 0c 20 ff  and  %l0, 0xff, %g1
a00dcbdc:  10 bf ff 2f  b  0xa00dc898
a00dcbe0:  a0 15 e2 90  or  %l7, 0x290, %l0
a00dcbe4:  7f ff df 6d  call  0xa00d4998
a00dcbe8:  ea 2c 60 09  stb  %l5, [ %l1 + 9 ]
a00dcbec:  10 bf fe 32  b  0xa00dc4b4
a00dcbf0:  29 2a 00 b3  sethi  %hi(0xa802cc00), %l4
a00dcbf4:  94 10 22 e0  mov  0x2e0, %o2
a00dcbf8:  96 10 20 1c  mov  0x1c, %o3
a00dcbfc:  40 01 b8 b5  call  0xa014aed0
a00dcc00:  90 10 20 30  mov  0x30, %o0
a00dcc04:  10 80 00 45  b  0xa00dcd18
a00dcc08:  90 10 20 00  clr  %o0
a00dcc0c:  7f ff f3 7b  call  0xa00d99f8
a00dcc10:  92 10 20 00  clr  %o1
a00dcc14:  90 10 20 04  mov  4, %o0
a00dcc18:  92 10 20 01  mov  1, %o1
a00dcc1c:  40 01 b7 2e  call  0xa014a8d4
a00dcc20:  94 10 23 e8  mov  0x3e8, %o2
a00dcc24:  30 bf fe b4  b,a   0xa00dc6f4
a00dcc28:  25 3f ff ee  sethi  %hi(0xffffb800), %l2
a00dcc2c:  a8 14 a3 99  or  %l2, 0x399, %l4	! 0xffffbb99
a00dcc30:  b7 34 e0 10  srl  %l3, 0x10, %i3
a00dcc34:  80 a6 c0 0c  cmp  %i3, %o4
a00dcc38:  12 bf ff 68  bne  0xa00dc9d8
a00dcc3c:  e8 34 21 f6  sth  %l4, [ %l0 + 0x1f6 ]
a00dcc40:  90 10 20 06  mov  6, %o0
a00dcc44:  40 01 a4 06  call  0xa0145c5c
a00dcc48:  92 10 20 00  clr  %o1
a00dcc4c:  90 10 20 07  mov  7, %o0
a00dcc50:  40 01 a4 03  call  0xa0145c5c
a00dcc54:  92 10 20 00  clr  %o1
a00dcc58:  40 01 a1 c2  call  0xa0145360
a00dcc5c:  90 10 20 01  mov  1, %o0
a00dcc60:  10 bf ff 5f  b  0xa00dc9dc
a00dcc64:  e2 0c 21 d6  ldub  [ %l0 + 0x1d6 ], %l1
a00dcc68:  10 bf fe 00  b  0xa00dc468
a00dcc6c:  ba 10 20 01  mov  1, %i5
a00dcc70:  40 01 23 f3  call  0xa0125c3c
a00dcc74:  a4 15 e2 90  or  %l7, 0x290, %l2
a00dcc78:  10 bf fe bc  b  0xa00dc768
a00dcc7c:  d6 0c a0 ac  ldub  [ %l2 + 0xac ], %o3
a00dcc80:  90 10 20 01  mov  1, %o0
a00dcc84:  40 01 c1 fc  call  0xa014d474
a00dcc88:  92 10 20 00  clr  %o1
a00dcc8c:  90 10 20 01  mov  1, %o0
a00dcc90:  40 01 c4 42  call  0xa014dd98
a00dcc94:  92 10 20 00  clr  %o1
a00dcc98:  10 bf ff 15  b  0xa00dc8ec
a00dcc9c:  98 15 e2 90  or  %l7, 0x290, %o4
a00dcca0:  80 a2 a0 00  cmp  %o2, 0
a00dcca4:  22 bf fe 60  be,a   0xa00dc624
a00dcca8:  a0 10 20 00  clr  %l0
a00dccac:  30 bf fe 5e  b,a   0xa00dc624
a00dccb0:  40 01 bb 6e  call  0xa014ba68
a00dccb4:  01 00 00 00  nop
a00dccb8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dccbc:  80 a2 20 02  cmp  %o0, 2
a00dccc0:  22 bf ff 75  be,a   0xa00dca94
a00dccc4:  a0 10 20 00  clr  %l0
a00dccc8:  04 80 00 09  ble  0xa00dccec
a00dcccc:  80 a2 20 01  cmp  %o0, 1
a00dccd0:  80 a2 20 03  cmp  %o0, 3
a00dccd4:  02 bf ff 6f  be  0xa00dca90
a00dccd8:  80 a2 20 04  cmp  %o0, 4
a00dccdc:  12 bf fe 5e  bne  0xa00dc654
a00dcce0:  01 00 00 00  nop
a00dcce4:  10 bf ff 6c  b  0xa00dca94
a00dcce8:  a0 10 20 00  clr  %l0	! 0x0
a00dccec:  12 bf fe 5a  bne  0xa00dc654
a00dccf0:  01 00 00 00  nop
a00dccf4:  10 bf ff 68  b  0xa00dca94
a00dccf8:  a0 10 20 00  clr  %l0	! 0x0
a00dccfc:  12 bf ff 17  bne  0xa00dc958
a00dcd00:  96 15 e2 90  or  %l7, 0x290, %o3
a00dcd04:  10 bf ff 8c  b  0xa00dcb34
a00dcd08:  a4 15 23 f4  or  %l4, 0x3f4, %l2
a00dcd0c:  12 bf fe 2d  bne  0xa00dc5c0
a00dcd10:  82 15 e2 90  or  %l7, 0x290, %g1
a00dcd14:  30 bf ff 4a  b,a   0xa00dca3c
a00dcd18:  40 01 ad 54  call  0xa0148268
a00dcd1c:  92 10 20 01  mov  1, %o1
a00dcd20:  90 10 20 01  mov  1, %o0
a00dcd24:  40 01 ad 51  call  0xa0148268
a00dcd28:  92 10 20 01  mov  1, %o1
a00dcd2c:  01 00 00 00  nop
a00dcd30:  81 c7 e0 08  ret
a00dcd34:  81 e8 00 00  restore
