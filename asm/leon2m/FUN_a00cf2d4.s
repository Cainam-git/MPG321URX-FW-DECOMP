# leon2m FUN_a00cf2d4 0xa00cf2d4-0xa00cfa14 (1660 bytes)
a00cf2d4:  9d e3 bf 90  save  %sp, -112, %sp
a00cf2d8:  c2 0e 20 04  ldub  [ %i0 + 4 ], %g1
a00cf2dc:  80 a0 60 6c  cmp  %g1, 0x6c
a00cf2e0:  02 80 00 4b  be  0xa00cf40c
a00cf2e4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00cf2e8:  14 80 00 11  bg  0xa00cf32c
a00cf2ec:  80 a0 60 e1  cmp  %g1, 0xe1
a00cf2f0:  80 a0 60 16  cmp  %g1, 0x16
a00cf2f4:  22 80 00 4b  be,a   0xa00cf420
a00cf2f8:  d6 0e 20 05  ldub  [ %i0 + 5 ], %o3
a00cf2fc:  04 80 00 20  ble  0xa00cf37c
a00cf300:  80 a0 60 10  cmp  %g1, 0x10
a00cf304:  80 a0 60 1a  cmp  %g1, 0x1a
a00cf308:  02 80 01 41  be  0xa00cf80c
a00cf30c:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00cf310:  14 80 00 8e  bg  0xa00cf548
a00cf314:  80 a0 60 60  cmp  %g1, 0x60
a00cf318:  80 a0 60 18  cmp  %g1, 0x18
a00cf31c:  12 80 01 bc  bne  0xa00cfa0c
a00cf320:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00cf324:  10 80 01 49  b  0xa00cf848
a00cf328:  90 10 00 19  mov  %i1, %o0
a00cf32c:  02 80 00 48  be  0xa00cf44c
a00cf330:  80 a0 60 e1  cmp  %g1, 0xe1
a00cf334:  14 80 00 1d  bg  0xa00cf3a8
a00cf338:  80 a0 60 e9  cmp  %g1, 0xe9
a00cf33c:  80 a0 60 70  cmp  %g1, 0x70
a00cf340:  22 80 01 3d  be,a   0xa00cf834
a00cf344:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00cf348:  14 80 00 65  bg  0xa00cf4dc
a00cf34c:  80 a0 60 cc  cmp  %g1, 0xcc
a00cf350:  80 a0 60 6e  cmp  %g1, 0x6e
a00cf354:  12 80 01 ae  bne  0xa00cfa0c
a00cf358:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00cf35c:  90 10 00 19  mov  %i1, %o0
a00cf360:  d8 0c 62 a6  ldub  [ %l1 + 0x2a6 ], %o4
a00cf364:  92 10 20 ff  mov  0xff, %o1
a00cf368:  94 10 20 00  clr  %o2
a00cf36c:  96 10 20 00  clr  %o3
a00cf370:  7f ff fd d9  call  0xa00cead4
a00cf374:  01 00 00 00  nop
a00cf378:  30 80 01 a5  b,a   0xa00cfa0c
a00cf37c:  02 80 01 29  be  0xa00cf820
a00cf380:  80 a0 60 12  cmp  %g1, 0x12
a00cf384:  12 80 01 a2  bne  0xa00cfa0c
a00cf388:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cf38c:  d4 0a 62 9a  ldub  [ %o1 + 0x29a ], %o2	! 0xa802d29a
a00cf390:  90 10 00 19  mov  %i1, %o0
a00cf394:  92 10 20 00  clr  %o1
a00cf398:  96 10 20 00  clr  %o3
a00cf39c:  7f ff fd ce  call  0xa00cead4
a00cf3a0:  98 10 20 00  clr  %o4
a00cf3a4:  30 80 01 9a  b,a   0xa00cfa0c
a00cf3a8:  02 80 00 d1  be  0xa00cf6ec
a00cf3ac:  80 a0 60 e9  cmp  %g1, 0xe9
a00cf3b0:  14 80 00 85  bg  0xa00cf5c4
a00cf3b4:  80 a0 60 ef  cmp  %g1, 0xef
a00cf3b8:  80 a0 60 e2  cmp  %g1, 0xe2
a00cf3bc:  12 80 01 94  bne  0xa00cfa0c
a00cf3c0:  01 00 00 00  nop
a00cf3c4:  f0 0e 20 05  ldub  [ %i0 + 5 ], %i0
a00cf3c8:  80 a6 20 01  cmp  %i0, 1
a00cf3cc:  02 80 01 6b  be  0xa00cf978
a00cf3d0:  80 a6 20 02  cmp  %i0, 2
a00cf3d4:  02 80 01 6e  be  0xa00cf98c
a00cf3d8:  80 a6 20 03  cmp  %i0, 3
a00cf3dc:  02 80 01 71  be  0xa00cf9a0
a00cf3e0:  80 a6 20 04  cmp  %i0, 4
a00cf3e4:  02 80 01 74  be  0xa00cf9b4
a00cf3e8:  80 a6 20 05  cmp  %i0, 5
a00cf3ec:  02 80 01 83  be  0xa00cf9f8
a00cf3f0:  80 a6 20 06  cmp  %i0, 6
a00cf3f4:  12 80 01 86  bne  0xa00cfa0c
a00cf3f8:  23 2a 00 b8  sethi  %hi(0xa802e000), %l1
a00cf3fc:  90 10 00 19  mov  %i1, %o0
a00cf400:  d4 0c 61 f5  ldub  [ %l1 + 0x1f5 ], %o2
a00cf404:  10 bf ff e5  b  0xa00cf398
a00cf408:  92 10 20 00  clr  %o1
a00cf40c:  90 10 00 19  mov  %i1, %o0
a00cf410:  d8 0c 22 a5  ldub  [ %l0 + 0x2a5 ], %o4
a00cf414:  92 10 20 ff  mov  0xff, %o1
a00cf418:  10 bf ff d5  b  0xa00cf36c
a00cf41c:  94 10 20 00  clr  %o2
a00cf420:  90 10 00 19  mov  %i1, %o0
a00cf424:  92 10 20 00  clr  %o1
a00cf428:  80 a2 e0 02  cmp  %o3, 2
a00cf42c:  02 bf ff db  be  0xa00cf398
a00cf430:  94 10 20 ff  mov  0xff, %o2
a00cf434:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00cf438:  d8 0a a0 a2  ldub  [ %o2 + 0xa2 ], %o4	! 0xa802b0a2
a00cf43c:  90 10 00 19  mov  %i1, %o0
a00cf440:  92 10 20 ff  mov  0xff, %o1
a00cf444:  10 bf ff ca  b  0xa00cf36c
a00cf448:  94 10 20 00  clr  %o2
a00cf44c:  da 0e 20 05  ldub  [ %i0 + 5 ], %o5
a00cf450:  80 a3 60 a5  cmp  %o5, 0xa5
a00cf454:  22 80 00 c0  be,a   0xa00cf754
a00cf458:  d4 0e 20 06  ldub  [ %i0 + 6 ], %o2
a00cf45c:  80 a3 60 a7  cmp  %o5, 0xa7
a00cf460:  22 80 00 d1  be,a   0xa00cf7a4
a00cf464:  de 0e 20 06  ldub  [ %i0 + 6 ], %o7
a00cf468:  80 a3 60 e6  cmp  %o5, 0xe6
a00cf46c:  12 80 01 68  bne  0xa00cfa0c
a00cf470:  01 00 00 00  nop
a00cf474:  d2 0e 20 06  ldub  [ %i0 + 6 ], %o1
a00cf478:  80 a2 60 06  cmp  %o1, 6
a00cf47c:  12 80 01 64  bne  0xa00cfa0c
a00cf480:  01 00 00 00  nop
a00cf484:  d6 0e 20 07  ldub  [ %i0 + 7 ], %o3
a00cf488:  80 a2 e0 00  cmp  %o3, 0
a00cf48c:  12 80 01 60  bne  0xa00cfa0c
a00cf490:  9e 10 3f 89  mov  -119, %o7
a00cf494:  a0 10 20 6e  mov  0x6e, %l0
a00cf498:  e0 2e 40 00  stb  %l0, [ %i1 ]
a00cf49c:  de 2e 60 01  stb  %o7, [ %i1 + 1 ]
a00cf4a0:  7f fe ea b0  call  0xa0089f60
a00cf4a4:  90 10 20 50  mov  0x50, %o0
a00cf4a8:  03 00 06 60  sethi  %hi(0x198000), %g1
a00cf4ac:  92 10 63 38  or  %g1, 0x338, %o1	! 0x198338
a00cf4b0:  94 10 20 00  clr  %o2
a00cf4b4:  96 10 20 00  clr  %o3
a00cf4b8:  90 02 c0 09  add  %o3, %o1, %o0
a00cf4bc:  a2 02 c0 19  add  %o3, %i1, %l1
a00cf4c0:  94 02 a0 01  inc  %o2
a00cf4c4:  da 0a 20 01  ldub  [ %o0 + 1 ], %o5
a00cf4c8:  96 0a a0 ff  and  %o2, 0xff, %o3
a00cf4cc:  80 a2 e0 06  cmp  %o3, 6
a00cf4d0:  0a bf ff fa  bcs  0xa00cf4b8
a00cf4d4:  da 2c 60 05  stb  %o5, [ %l1 + 5 ]
a00cf4d8:  30 80 01 4d  b,a   0xa00cfa0c
a00cf4dc:  12 80 01 4c  bne  0xa00cfa0c
a00cf4e0:  b0 10 20 6e  mov  0x6e, %i0
a00cf4e4:  a2 10 3f 88  mov  -120, %l1
a00cf4e8:  a0 10 20 02  mov  2, %l0
a00cf4ec:  9e 10 3f fe  mov  -2, %o7
a00cf4f0:  9a 10 20 01  mov  1, %o5
a00cf4f4:  94 10 3f ff  mov  -1, %o2
a00cf4f8:  f0 2e 40 00  stb  %i0, [ %i1 ]
a00cf4fc:  e2 2e 60 01  stb  %l1, [ %i1 + 1 ]
a00cf500:  e0 2e 60 02  stb  %l0, [ %i1 + 2 ]
a00cf504:  de 2e 60 04  stb  %o7, [ %i1 + 4 ]
a00cf508:  da 2e 60 05  stb  %o5, [ %i1 + 5 ]
a00cf50c:  d4 2e 60 07  stb  %o2, [ %i1 + 7 ]
a00cf510:  c0 2e 60 03  clrb  [ %i1 + 3 ]
a00cf514:  c0 2e 60 06  clrb  [ %i1 + 6 ]
a00cf518:  c0 2e 60 08  clrb  [ %i1 + 8 ]
a00cf51c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cf520:  c2 0a e2 98  ldub  [ %o3 + 0x298 ], %g1	! 0xa802d298
a00cf524:  80 a0 60 13  cmp  %g1, 0x13
a00cf528:  38 80 00 3f  bgu,a   0xa00cf624
a00cf52c:  82 10 20 02  mov  2, %g1
a00cf530:  17 00 01 ba  sethi  %hi(0x6e800), %o3
a00cf534:  99 28 60 02  sll  %g1, 2, %o4
a00cf538:  92 12 e3 24  or  %o3, 0x324, %o1
a00cf53c:  d0 02 40 0c  ld  [ %o1 + %o4 ], %o0
a00cf540:  81 c2 00 00  jmp  %o0
a00cf544:  01 00 00 00  nop
a00cf548:  12 80 01 31  bne  0xa00cfa0c
a00cf54c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cf550:  da 0a 22 ae  ldub  [ %o0 + 0x2ae ], %o5	! 0xa802d2ae
a00cf554:  80 a3 60 04  cmp  %o5, 4
a00cf558:  02 80 00 15  be  0xa00cf5ac
a00cf55c:  82 10 20 11  mov  0x11, %g1
a00cf560:  80 a3 60 06  cmp  %o5, 6
a00cf564:  02 80 00 12  be  0xa00cf5ac
a00cf568:  82 10 20 12  mov  0x12, %g1
a00cf56c:  80 a3 60 07  cmp  %o5, 7
a00cf570:  02 80 00 0f  be  0xa00cf5ac
a00cf574:  82 10 20 11  mov  0x11, %g1
a00cf578:  80 a3 60 0b  cmp  %o5, 0xb
a00cf57c:  02 80 00 0c  be  0xa00cf5ac
a00cf580:  82 10 20 0f  mov  0xf, %g1
a00cf584:  80 a3 60 0c  cmp  %o5, 0xc
a00cf588:  02 80 00 09  be  0xa00cf5ac
a00cf58c:  80 a3 60 0d  cmp  %o5, 0xd
a00cf590:  02 80 00 07  be  0xa00cf5ac
a00cf594:  82 10 20 10  mov  0x10, %g1
a00cf598:  92 1b 60 02  xor  %o5, 2, %o1
a00cf59c:  80 a0 00 09  cmp  %g0, %o1
a00cf5a0:  82 60 20 00  subx  %g0, 0, %g1
a00cf5a4:  98 08 7f fe  and  %g1, -2, %o4
a00cf5a8:  82 03 20 03  add  %o4, 3, %g1
a00cf5ac:  90 10 00 19  mov  %i1, %o0
a00cf5b0:  98 08 60 ff  and  %g1, 0xff, %o4
a00cf5b4:  92 10 20 03  mov  3, %o1
a00cf5b8:  94 10 20 01  mov  1, %o2
a00cf5bc:  10 bf ff 6d  b  0xa00cf370
a00cf5c0:  96 10 20 00  clr  %o3
a00cf5c4:  12 80 01 12  bne  0xa00cfa0c
a00cf5c8:  9a 10 21 00  mov  0x100, %o5
a00cf5cc:  e2 0e 20 05  ldub  [ %i0 + 5 ], %l1
a00cf5d0:  80 a4 60 13  cmp  %l1, 0x13
a00cf5d4:  02 80 00 ca  be  0xa00cf8fc
a00cf5d8:  da 37 bf f6  sth  %o5, [ %fp + -10 ]
a00cf5dc:  e0 0e 20 06  ldub  [ %i0 + 6 ], %l0
a00cf5e0:  e2 0e 20 07  ldub  [ %i0 + 7 ], %l1
a00cf5e4:  9a 10 20 6e  mov  0x6e, %o5
a00cf5e8:  96 10 3f 88  mov  -120, %o3
a00cf5ec:  da 2e 40 00  stb  %o5, [ %i1 ]
a00cf5f0:  d6 2e 60 01  stb  %o3, [ %i1 + 1 ]
a00cf5f4:  c2 0e 20 05  ldub  [ %i0 + 5 ], %g1
a00cf5f8:  80 a0 60 42  cmp  %g1, 0x42
a00cf5fc:  02 80 00 ab  be  0xa00cf8a8
a00cf600:  90 14 00 11  or  %l0, %l1, %o0
a00cf604:  b0 08 60 ff  and  %g1, 0xff, %i0
a00cf608:  80 a6 20 43  cmp  %i0, 0x43
a00cf60c:  02 80 00 93  be  0xa00cf858
a00cf610:  94 14 00 11  or  %l0, %l1, %o2
a00cf614:  7f fe ea 53  call  0xa0089f60
a00cf618:  90 10 20 50  mov  0x50, %o0
a00cf61c:  30 80 00 fc  b,a   0xa00cfa0c
a00cf620:  82 10 20 02  mov  2, %g1
a00cf624:  10 bf ff fc  b  0xa00cf614
a00cf628:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf62c:  82 10 20 01  mov  1, %g1
a00cf630:  10 bf ff f9  b  0xa00cf614
a00cf634:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf638:  82 10 20 04  mov  4, %g1
a00cf63c:  10 bf ff f6  b  0xa00cf614
a00cf640:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf644:  82 10 20 03  mov  3, %g1
a00cf648:  10 bf ff f3  b  0xa00cf614
a00cf64c:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf650:  82 10 20 06  mov  6, %g1
a00cf654:  10 bf ff f0  b  0xa00cf614
a00cf658:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf65c:  82 10 20 07  mov  7, %g1
a00cf660:  10 bf ff ed  b  0xa00cf614
a00cf664:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf668:  82 10 20 0a  mov  0xa, %g1
a00cf66c:  10 bf ff ea  b  0xa00cf614
a00cf670:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf674:  82 10 20 05  mov  5, %g1
a00cf678:  10 bf ff e7  b  0xa00cf614
a00cf67c:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf680:  82 10 20 0f  mov  0xf, %g1
a00cf684:  10 bf ff e4  b  0xa00cf614
a00cf688:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf68c:  82 10 20 18  mov  0x18, %g1
a00cf690:  10 bf ff e1  b  0xa00cf614
a00cf694:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf698:  82 10 20 25  mov  0x25, %g1
a00cf69c:  10 bf ff de  b  0xa00cf614
a00cf6a0:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf6a4:  82 10 20 0c  mov  0xc, %g1
a00cf6a8:  10 bf ff db  b  0xa00cf614
a00cf6ac:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf6b0:  82 10 20 19  mov  0x19, %g1
a00cf6b4:  10 bf ff d8  b  0xa00cf614
a00cf6b8:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf6bc:  82 10 20 23  mov  0x23, %g1
a00cf6c0:  10 bf ff d5  b  0xa00cf614
a00cf6c4:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf6c8:  82 10 20 0d  mov  0xd, %g1
a00cf6cc:  10 bf ff d2  b  0xa00cf614
a00cf6d0:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf6d4:  82 10 20 08  mov  8, %g1
a00cf6d8:  10 bf ff cf  b  0xa00cf614
a00cf6dc:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf6e0:  82 10 20 09  mov  9, %g1
a00cf6e4:  10 bf ff cc  b  0xa00cf614
a00cf6e8:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00cf6ec:  d4 0e 20 06  ldub  [ %i0 + 6 ], %o2
a00cf6f0:  80 a2 a0 00  cmp  %o2, 0
a00cf6f4:  12 80 00 c6  bne  0xa00cfa0c
a00cf6f8:  01 00 00 00  nop
a00cf6fc:  d8 0e 20 07  ldub  [ %i0 + 7 ], %o4
a00cf700:  80 a3 20 00  cmp  %o4, 0
a00cf704:  12 80 00 c2  bne  0xa00cfa0c
a00cf708:  96 10 20 6e  mov  0x6e, %o3
a00cf70c:  92 10 3f 91  mov  -111, %o1
a00cf710:  d6 2e 40 00  stb  %o3, [ %i1 ]
a00cf714:  d2 2e 60 01  stb  %o1, [ %i1 + 1 ]
a00cf718:  7f fe ea 12  call  0xa0089f60
a00cf71c:  90 10 20 50  mov  0x50, %o0
a00cf720:  31 00 06 60  sethi  %hi(0x198000), %i0
a00cf724:  92 16 23 28  or  %i0, 0x328, %o1	! 0x198328
a00cf728:  94 10 20 00  clr  %o2
a00cf72c:  96 10 20 00  clr  %o3
a00cf730:  82 02 c0 09  add  %o3, %o1, %g1
a00cf734:  9e 02 c0 19  add  %o3, %i1, %o7
a00cf738:  94 02 a0 01  inc  %o2
a00cf73c:  e0 08 60 01  ldub  [ %g1 + 1 ], %l0
a00cf740:  96 0a a0 ff  and  %o2, 0xff, %o3
a00cf744:  80 a2 e0 0e  cmp  %o3, 0xe
a00cf748:  0a bf ff fa  bcs  0xa00cf730
a00cf74c:  e0 2b e0 05  stb  %l0, [ %o7 + 5 ]
a00cf750:  30 80 00 af  b,a   0xa00cfa0c
a00cf754:  80 a2 a0 03  cmp  %o2, 3
a00cf758:  12 bf ff 42  bne  0xa00cf460
a00cf75c:  80 a3 60 a7  cmp  %o5, 0xa7
a00cf760:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a00cf764:  80 a2 20 00  cmp  %o0, 0
a00cf768:  12 bf ff 3e  bne  0xa00cf460
a00cf76c:  80 a3 60 a7  cmp  %o5, 0xa7
a00cf770:  b0 10 20 02  mov  2, %i0
a00cf774:  82 10 3f b0  mov  -80, %g1
a00cf778:  96 10 20 6e  mov  0x6e, %o3
a00cf77c:  92 10 3f 88  mov  -120, %o1
a00cf780:  98 10 3f fe  mov  -2, %o4
a00cf784:  c2 2e 60 06  stb  %g1, [ %i1 + 6 ]
a00cf788:  d6 2e 40 00  stb  %o3, [ %i1 ]
a00cf78c:  d2 2e 60 01  stb  %o1, [ %i1 + 1 ]
a00cf790:  d8 2e 60 04  stb  %o4, [ %i1 + 4 ]
a00cf794:  f0 2e 60 05  stb  %i0, [ %i1 + 5 ]
a00cf798:  f0 2e 60 02  stb  %i0, [ %i1 + 2 ]
a00cf79c:  10 bf ff 9e  b  0xa00cf614
a00cf7a0:  c0 2e 60 03  clrb  [ %i1 + 3 ]
a00cf7a4:  80 a3 e0 07  cmp  %o7, 7
a00cf7a8:  12 bf ff 31  bne  0xa00cf46c
a00cf7ac:  80 a3 60 e6  cmp  %o5, 0xe6
a00cf7b0:  e0 0e 20 07  ldub  [ %i0 + 7 ], %l0
a00cf7b4:  80 a4 20 00  cmp  %l0, 0
a00cf7b8:  12 bf ff 2d  bne  0xa00cf46c
a00cf7bc:  80 a3 60 e6  cmp  %o5, 0xe6
a00cf7c0:  94 10 20 6e  mov  0x6e, %o2
a00cf7c4:  a2 10 3f 95  mov  -107, %l1
a00cf7c8:  d4 2e 40 00  stb  %o2, [ %i1 ]
a00cf7cc:  e2 2e 60 01  stb  %l1, [ %i1 + 1 ]
a00cf7d0:  7f fe e9 e4  call  0xa0089f60
a00cf7d4:  90 10 20 50  mov  0x50, %o0
a00cf7d8:  1b 00 06 60  sethi  %hi(0x198000), %o5
a00cf7dc:  92 13 63 40  or  %o5, 0x340, %o1	! 0x198340
a00cf7e0:  94 10 20 00  clr  %o2
a00cf7e4:  96 10 20 00  clr  %o3
a00cf7e8:  98 02 c0 09  add  %o3, %o1, %o4
a00cf7ec:  90 02 c0 19  add  %o3, %i1, %o0
a00cf7f0:  94 02 a0 01  inc  %o2
a00cf7f4:  f0 0b 20 01  ldub  [ %o4 + 1 ], %i0
a00cf7f8:  96 0a a0 ff  and  %o2, 0xff, %o3
a00cf7fc:  80 a2 e0 12  cmp  %o3, 0x12
a00cf800:  0a bf ff fa  bcs  0xa00cf7e8
a00cf804:  f0 2a 20 05  stb  %i0, [ %o0 + 5 ]
a00cf808:  30 80 00 81  b,a   0xa00cfa0c
a00cf80c:  90 10 00 19  mov  %i1, %o0
a00cf810:  d8 0b e0 a0  ldub  [ %o7 + 0xa0 ], %o4
a00cf814:  92 10 20 ff  mov  0xff, %o1
a00cf818:  10 bf fe d5  b  0xa00cf36c
a00cf81c:  94 10 20 00  clr  %o2
a00cf820:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cf824:  90 10 00 19  mov  %i1, %o0
a00cf828:  d4 08 62 99  ldub  [ %g1 + 0x299 ], %o2
a00cf82c:  10 bf fe db  b  0xa00cf398
a00cf830:  92 10 20 00  clr  %o1
a00cf834:  90 10 00 19  mov  %i1, %o0
a00cf838:  d8 0e 22 a7  ldub  [ %i0 + 0x2a7 ], %o4
a00cf83c:  92 10 20 ff  mov  0xff, %o1
a00cf840:  10 bf fe cb  b  0xa00cf36c
a00cf844:  94 10 20 00  clr  %o2
a00cf848:  d8 0b 60 a1  ldub  [ %o5 + 0xa1 ], %o4
a00cf84c:  92 10 20 ff  mov  0xff, %o1
a00cf850:  10 bf fe c7  b  0xa00cf36c
a00cf854:  94 10 20 00  clr  %o2
a00cf858:  80 8a a0 ff  btst  0xff, %o2
a00cf85c:  02 80 00 5b  be  0xa00cf9c8
a00cf860:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cf864:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cf868:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cf86c:  97 28 60 08  sll  %g1, 8, %o3
a00cf870:  9a 12 21 48  or  %o0, 0x148, %o5
a00cf874:  9e 02 c0 0d  add  %o3, %o5, %o7
a00cf878:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00cf87c:  98 03 c0 10  add  %o7, %l0, %o4
a00cf880:  94 10 20 00  clr  %o2
a00cf884:  96 10 20 00  clr  %o3
a00cf888:  d2 0b 00 0b  ldub  [ %o4 + %o3 ], %o1
a00cf88c:  a2 02 c0 19  add  %o3, %i1, %l1
a00cf890:  94 02 a0 01  inc  %o2
a00cf894:  96 0a a0 ff  and  %o2, 0xff, %o3
a00cf898:  80 a2 e0 1f  cmp  %o3, 0x1f
a00cf89c:  08 bf ff fb  bleu  0xa00cf888
a00cf8a0:  d2 2c 60 02  stb  %o1, [ %l1 + 2 ]
a00cf8a4:  30 bf ff 5c  b,a   0xa00cf614
a00cf8a8:  80 8a 20 ff  btst  0xff, %o0
a00cf8ac:  02 80 00 4d  be  0xa00cf9e0
a00cf8b0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cf8b4:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cf8b8:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00cf8bc:  96 13 61 48  or  %o5, 0x148, %o3	! 0xa802d148
a00cf8c0:  9f 28 60 08  sll  %g1, 8, %o7
a00cf8c4:  92 03 c0 0b  add  %o7, %o3, %o1
a00cf8c8:  98 0c 60 ff  and  %l1, 0xff, %o4
a00cf8cc:  94 02 40 0c  add  %o1, %o4, %o2
a00cf8d0:  96 10 20 00  clr  %o3
a00cf8d4:  98 10 20 00  clr  %o4
a00cf8d8:  d2 0a 80 0c  ldub  [ %o2 + %o4 ], %o1
a00cf8dc:  90 03 00 19  add  %o4, %i1, %o0
a00cf8e0:  96 02 e0 01  inc  %o3
a00cf8e4:  98 0a e0 ff  and  %o3, 0xff, %o4
a00cf8e8:  80 a3 20 1f  cmp  %o4, 0x1f
a00cf8ec:  08 bf ff fb  bleu  0xa00cf8d8
a00cf8f0:  d2 2a 20 02  stb  %o1, [ %o0 + 2 ]
a00cf8f4:  10 bf ff 44  b  0xa00cf604
a00cf8f8:  c2 0e 20 05  ldub  [ %i0 + 5 ], %g1
a00cf8fc:  92 10 20 6e  mov  0x6e, %o1
a00cf900:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00cf904:  d2 2e 40 00  stb  %o1, [ %i1 ]
a00cf908:  a0 16 22 74  or  %i0, 0x274, %l0
a00cf90c:  d8 0c 20 02  ldub  [ %l0 + 2 ], %o4
a00cf910:  94 03 3f 80  add  %o4, -128, %o2
a00cf914:  d4 2e 60 01  stb  %o2, [ %i1 + 1 ]
a00cf918:  7f fe e9 92  call  0xa0089f60
a00cf91c:  90 10 20 50  mov  0x50, %o0
a00cf920:  96 10 20 1c  mov  0x1c, %o3
a00cf924:  90 10 20 30  mov  0x30, %o0
a00cf928:  92 10 00 10  mov  %l0, %o1
a00cf92c:  40 01 ed 3c  call  0xa014ae1c
a00cf930:  94 10 22 e0  mov  0x2e0, %o2
a00cf934:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a00cf938:  80 a2 20 00  cmp  %o0, 0
a00cf93c:  08 80 00 34  bleu  0xa00cfa0c
a00cf940:  96 10 20 00  clr  %o3
a00cf944:  92 10 00 10  mov  %l0, %o1
a00cf948:  9a 10 20 00  clr  %o5
a00cf94c:  82 03 40 09  add  %o5, %o1, %g1
a00cf950:  a0 03 40 19  add  %o5, %i1, %l0
a00cf954:  e2 08 60 03  ldub  [ %g1 + 3 ], %l1
a00cf958:  e2 2c 20 02  stb  %l1, [ %l0 + 2 ]
a00cf95c:  96 02 e0 01  inc  %o3
a00cf960:  de 0a 60 02  ldub  [ %o1 + 2 ], %o7
a00cf964:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00cf968:  80 a3 c0 0d  cmp  %o7, %o5
a00cf96c:  18 bf ff f9  bgu  0xa00cf950
a00cf970:  82 03 40 09  add  %o5, %o1, %g1
a00cf974:  30 80 00 26  b,a   0xa00cfa0c
a00cf978:  90 10 00 19  mov  %i1, %o0
a00cf97c:  33 2a 00 b8  sethi  %hi(0xa802e000), %i1
a00cf980:  d4 0e 61 f0  ldub  [ %i1 + 0x1f0 ], %o2	! 0xa802e1f0
a00cf984:  10 bf fe 85  b  0xa00cf398
a00cf988:  92 10 20 00  clr  %o1
a00cf98c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a00cf990:  90 10 00 19  mov  %i1, %o0
a00cf994:  d4 08 61 f1  ldub  [ %g1 + 0x1f1 ], %o2
a00cf998:  10 bf fe 80  b  0xa00cf398
a00cf99c:  92 10 20 00  clr  %o1
a00cf9a0:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a00cf9a4:  90 10 00 19  mov  %i1, %o0
a00cf9a8:  d4 0b 61 f2  ldub  [ %o5 + 0x1f2 ], %o2
a00cf9ac:  10 bf fe 7b  b  0xa00cf398
a00cf9b0:  92 10 20 00  clr  %o1
a00cf9b4:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a00cf9b8:  90 10 00 19  mov  %i1, %o0
a00cf9bc:  d4 0b e1 f3  ldub  [ %o7 + 0x1f3 ], %o2
a00cf9c0:  10 bf fe 76  b  0xa00cf398
a00cf9c4:  92 10 20 00  clr  %o1
a00cf9c8:  92 13 21 48  or  %o4, 0x148, %o1
a00cf9cc:  90 10 20 ff  mov  0xff, %o0
a00cf9d0:  40 01 ed bd  call  0xa014b0c4
a00cf9d4:  94 07 bf f6  add  %fp, -10, %o2
a00cf9d8:  10 bf ff a4  b  0xa00cf868
a00cf9dc:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cf9e0:  92 12 a1 48  or  %o2, 0x148, %o1
a00cf9e4:  90 10 20 ff  mov  0xff, %o0
a00cf9e8:  40 01 ed b7  call  0xa014b0c4
a00cf9ec:  94 07 bf f6  add  %fp, -10, %o2
a00cf9f0:  10 bf ff b2  b  0xa00cf8b8
a00cf9f4:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cf9f8:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a00cf9fc:  90 10 00 19  mov  %i1, %o0
a00cfa00:  d4 0c 21 f4  ldub  [ %l0 + 0x1f4 ], %o2
a00cfa04:  10 bf fe 65  b  0xa00cf398
a00cfa08:  92 10 20 00  clr  %o1
a00cfa0c:  81 c7 e0 08  ret
a00cfa10:  81 e8 00 00  restore
