# leon2m FUN_a0135344 0xa0135344-0xa013562c (744 bytes)
a0135344:  9d e3 bf 78  save  %sp, -136, %sp
a0135348:  9a 10 20 00  clr  %o5
a013534c:  98 10 20 00  clr  %o4
a0135350:  b0 16 3f 80  or  %i0, -128, %i0
a0135354:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a0135358:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a013535c:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a0135360:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a0135364:  80 8e 20 80  btst  0x80, %i0
a0135368:  9a 10 00 18  mov  %i0, %o5
a013536c:  ae 10 20 02  mov  2, %l7
a0135370:  aa 10 20 10  mov  0x10, %l5
a0135374:  12 80 00 a9  bne  0xa0135618
a0135378:  a4 10 20 00  clr  %l2
a013537c:  83 2f 20 10  sll  %i4, 0x10, %g1
a0135380:  83 30 60 10  srl  %g1, 0x10, %g1
a0135384:  80 a0 7f fe  cmp  %g1, -2
a0135388:  a2 10 20 00  clr  %l1
a013538c:  02 80 00 88  be  0xa01355ac
a0135390:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a0135394:  11 2a 00 b6  sethi  %hi(0xa802d800), %o0
a0135398:  98 10 00 01  mov  %g1, %o4
a013539c:  b0 0b 60 ff  and  %o5, 0xff, %i0
a01353a0:  ac 12 22 6c  or  %o0, 0x26c, %l6
a01353a4:  92 07 bf e8  add  %fp, -24, %o1
a01353a8:  27 2a 00 b2  sethi  %hi(0xa802c800), %l3
a01353ac:  a8 07 bf f8  add  %fp, -8, %l4
a01353b0:  9e 07 bf d8  add  %fp, -40, %o7
a01353b4:  a0 10 00 01  mov  %g1, %l0
a01353b8:  9b 2c 60 10  sll  %l1, 0x10, %o5
a01353bc:  9b 33 60 10  srl  %o5, 0x10, %o5
a01353c0:  96 23 00 0d  sub  %o4, %o5, %o3
a01353c4:  94 02 e0 02  add  %o3, 2, %o2
a01353c8:  80 a2 a0 0f  cmp  %o2, 0xf
a01353cc:  14 80 00 05  bg  0xa01353e0
a01353d0:  80 a3 60 00  cmp  %o5, 0
a01353d4:  98 27 00 11  sub  %i4, %l1, %o4
a01353d8:  aa 03 20 02  add  %o4, 2, %l5
a01353dc:  ae 10 20 01  mov  1, %l7
a01353e0:  12 80 00 29  bne  0xa0135484
a01353e4:  94 03 40 1b  add  %o5, %i3, %o2
a01353e8:  90 0d 60 ff  and  %l5, 0xff, %o0
a01353ec:  94 02 3f fe  add  %o0, -2, %o2
a01353f0:  80 a3 40 0a  cmp  %o5, %o2
a01353f4:  f2 2f bf d8  stb  %i1, [ %fp + -40 ]
a01353f8:  f4 2f bf d9  stb  %i2, [ %fp + -39 ]
a01353fc:  16 80 00 0a  bge  0xa0135424
a0135400:  96 10 20 00  clr  %o3
a0135404:  98 10 20 00  clr  %o4
a0135408:  da 0b 00 1b  ldub  [ %o4 + %i3 ], %o5
a013540c:  82 05 00 0c  add  %l4, %o4, %g1
a0135410:  96 02 e0 01  inc  %o3
a0135414:  98 0a e0 ff  and  %o3, 0xff, %o4
a0135418:  80 a3 00 0a  cmp  %o4, %o2
a013541c:  06 bf ff fb  bl  0xa0135408
a0135420:  da 28 7f e2  stb  %o5, [ %g1 + -30 ]
a0135424:  94 10 20 00  clr  %o2
a0135428:  9a 10 20 00  clr  %o5
a013542c:  97 2b 60 02  sll  %o5, 2, %o3
a0135430:  c2 0b c0 0b  ldub  [ %o7 + %o3 ], %g1
a0135434:  c2 22 40 0b  st  %g1, [ %o1 + %o3 ]
a0135438:  98 02 c0 0f  add  %o3, %o7, %o4
a013543c:  da 0b 20 01  ldub  [ %o4 + 1 ], %o5
a0135440:  83 28 60 08  sll  %g1, 8, %g1
a0135444:  82 00 40 0d  add  %g1, %o5, %g1
a0135448:  c2 22 40 0b  st  %g1, [ %o1 + %o3 ]
a013544c:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a0135450:  83 28 60 08  sll  %g1, 8, %g1
a0135454:  82 00 40 0d  add  %g1, %o5, %g1
a0135458:  c2 22 40 0b  st  %g1, [ %o1 + %o3 ]
a013545c:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a0135460:  83 28 60 08  sll  %g1, 8, %g1
a0135464:  98 00 40 0d  add  %g1, %o5, %o4
a0135468:  94 02 a0 01  inc  %o2
a013546c:  9a 0a a0 ff  and  %o2, 0xff, %o5
a0135470:  80 a3 60 04  cmp  %o5, 4
a0135474:  0a bf ff ee  bcs  0xa013542c
a0135478:  d8 22 40 0b  st  %o4, [ %o1 + %o3 ]
a013547c:  10 80 00 1b  b  0xa01354e8
a0135480:  99 2a 20 10  sll  %o0, 0x10, %o4
a0135484:  90 02 bf fe  add  %o2, -2, %o0
a0135488:  94 10 20 00  clr  %o2
a013548c:  9a 10 20 00  clr  %o5
a0135490:  97 2b 60 02  sll  %o5, 2, %o3
a0135494:  c2 0a 00 0b  ldub  [ %o0 + %o3 ], %g1
a0135498:  c2 22 40 0b  st  %g1, [ %o1 + %o3 ]
a013549c:  98 02 c0 08  add  %o3, %o0, %o4
a01354a0:  da 0b 20 01  ldub  [ %o4 + 1 ], %o5
a01354a4:  83 28 60 08  sll  %g1, 8, %g1
a01354a8:  82 00 40 0d  add  %g1, %o5, %g1
a01354ac:  c2 22 40 0b  st  %g1, [ %o1 + %o3 ]
a01354b0:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a01354b4:  83 28 60 08  sll  %g1, 8, %g1
a01354b8:  82 00 40 0d  add  %g1, %o5, %g1
a01354bc:  c2 22 40 0b  st  %g1, [ %o1 + %o3 ]
a01354c0:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a01354c4:  83 28 60 08  sll  %g1, 8, %g1
a01354c8:  98 00 40 0d  add  %g1, %o5, %o4
a01354cc:  94 02 a0 01  inc  %o2
a01354d0:  9a 0a a0 ff  and  %o2, 0xff, %o5
a01354d4:  80 a3 60 04  cmp  %o5, 4
a01354d8:  0a bf ff ee  bcs  0xa0135490
a01354dc:  d8 22 40 0b  st  %o4, [ %o1 + %o3 ]
a01354e0:  90 0d 60 ff  and  %l5, 0xff, %o0
a01354e4:  99 2a 20 10  sll  %o0, 0x10, %o4
a01354e8:  d4 0c e3 97  ldub  [ %l3 + 0x397 ], %o2
a01354ec:  83 2c a0 18  sll  %l2, 0x18, %g1
a01354f0:  96 0a a0 ff  and  %o2, 0xff, %o3
a01354f4:  90 00 40 0c  add  %g1, %o4, %o0
a01354f8:  9b 2e 20 08  sll  %i0, 8, %o5
a01354fc:  82 02 00 0d  add  %o0, %o5, %g1
a0135500:  99 2a e0 02  sll  %o3, 2, %o4
a0135504:  90 0d e0 ff  and  %l7, 0xff, %o0
a0135508:  98 03 00 0b  add  %o4, %o3, %o4
a013550c:  96 00 60 02  add  %g1, 2, %o3
a0135510:  9b 2a 20 04  sll  %o0, 4, %o5
a0135514:  90 02 c0 0d  add  %o3, %o5, %o0
a0135518:  99 2b 20 02  sll  %o4, 2, %o4
a013551c:  d0 25 80 0c  st  %o0, [ %l6 + %o4 ]
a0135520:  96 03 00 16  add  %o4, %l6, %o3
a0135524:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a0135528:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a013552c:  94 02 a0 01  inc  %o2
a0135530:  c2 22 e0 10  st  %g1, [ %o3 + 0x10 ]
a0135534:  da 22 e0 04  st  %o5, [ %o3 + 4 ]
a0135538:  90 0a a0 ff  and  %o2, 0xff, %o0
a013553c:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a0135540:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a0135544:  c2 22 e0 08  st  %g1, [ %o3 + 8 ]
a0135548:  80 a2 20 24  cmp  %o0, 0x24
a013554c:  08 80 00 31  bleu  0xa0135610
a0135550:  da 22 e0 0c  st  %o5, [ %o3 + 0xc ]
a0135554:  c0 2c e3 97  clrb  [ %l3 + 0x397 ]
a0135558:  94 04 60 10  add  %l1, 0x10, %o2
a013555c:  91 2a a0 10  sll  %o2, 0x10, %o0
a0135560:  a2 04 20 02  add  %l0, 2, %l1
a0135564:  97 32 20 10  srl  %o0, 0x10, %o3
a0135568:  80 a2 c0 11  cmp  %o3, %l1
a013556c:  a4 04 a0 01  inc  %l2
a0135570:  a2 10 00 0a  mov  %o2, %l1
a0135574:  06 bf ff 91  bl  0xa01353b8
a0135578:  98 10 00 10  mov  %l0, %o4
a013557c:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a0135580:  d2 0c 23 93  ldub  [ %l0 + 0x393 ], %o1	! 0xa802cb93
a0135584:  80 a2 60 01  cmp  %o1, 1
a0135588:  02 80 00 0d  be  0xa01355bc
a013558c:  82 10 20 00  clr  %g1
a0135590:  80 88 60 ff  btst  0xff, %g1
a0135594:  12 80 00 24  bne  0xa0135624
a0135598:  01 00 00 00  nop
a013559c:  7f ff fe d0  call  0xa01350dc
a01355a0:  01 00 00 00  nop
a01355a4:  7f ff fe 0f  call  0xa0134de0
a01355a8:  01 00 00 00  nop
a01355ac:  d2 0c 23 93  ldub  [ %l0 + 0x393 ], %o1
a01355b0:  80 a2 60 01  cmp  %o1, 1
a01355b4:  12 bf ff f7  bne  0xa0135590
a01355b8:  82 10 20 00  clr  %g1
a01355bc:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a01355c0:  de 0a a3 92  ldub  [ %o2 + 0x392 ], %o7	! 0xa802cb92
a01355c4:  80 a3 e0 00  cmp  %o7, 0
a01355c8:  02 80 00 0d  be  0xa01355fc
a01355cc:  98 10 20 00  clr  %o4
a01355d0:  25 2a 00 b7  sethi  %hi(0xa802dc00), %l2
a01355d4:  96 14 a2 40  or  %l2, 0x240, %o3	! 0xa802de40
a01355d8:  9a 10 20 00  clr  %o5
a01355dc:  e8 0a c0 0d  ldub  [ %o3 + %o5 ], %l4
a01355e0:  e8 2b 40 1b  stb  %l4, [ %o5 + %i3 ]
a01355e4:  98 03 20 01  inc  %o4
a01355e8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a01355ec:  e6 0a a3 92  ldub  [ %o2 + 0x392 ], %l3
a01355f0:  80 a3 40 13  cmp  %o5, %l3
a01355f4:  2a bf ff fb  bcs,a   0xa01355e0
a01355f8:  e8 0a c0 0d  ldub  [ %o3 + %o5 ], %l4
a01355fc:  82 10 20 01  mov  1, %g1
a0135600:  80 88 60 ff  btst  0xff, %g1
a0135604:  02 bf ff e6  be  0xa013559c
a0135608:  c0 2c 23 93  clrb  [ %l0 + 0x393 ]
a013560c:  30 80 00 06  b,a   0xa0135624
a0135610:  10 bf ff d2  b  0xa0135558
a0135614:  d4 2c e3 97  stb  %o2, [ %l3 + 0x397 ]
a0135618:  a4 10 00 1c  mov  %i4, %l2
a013561c:  10 bf ff 58  b  0xa013537c
a0135620:  b8 10 20 00  clr  %i4
a0135624:  81 c7 e0 08  ret
a0135628:  81 e8 00 00  restore
