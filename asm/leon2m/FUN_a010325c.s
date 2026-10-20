# leon2m FUN_a010325c 0xa010325c-0xa0103808 (1452 bytes)
a010325c:  9d e3 bf 78  save  %sp, -136, %sp
a0103260:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0103264:  92 10 20 55  mov  0x55, %o1
a0103268:  7f ff bb fb  call  0xa00f2254
a010326c:  90 10 00 18  mov  %i0, %o0
a0103270:  94 0a 20 f0  and  %o0, 0xf0, %o2
a0103274:  90 10 00 18  mov  %i0, %o0
a0103278:  7f ff bc 08  call  0xa00f2298
a010327c:  92 10 20 55  mov  0x55, %o1
a0103280:  90 10 00 18  mov  %i0, %o0
a0103284:  92 10 20 50  mov  0x50, %o1
a0103288:  94 10 20 04  mov  4, %o2
a010328c:  7f ff bc 28  call  0xa00f232c
a0103290:  96 10 20 01  mov  1, %o3
a0103294:  96 10 20 01  mov  1, %o3
a0103298:  90 10 00 18  mov  %i0, %o0
a010329c:  92 10 20 50  mov  0x50, %o1
a01032a0:  7f ff bc 23  call  0xa00f232c
a01032a4:  94 10 20 20  mov  0x20, %o2
a01032a8:  90 10 00 18  mov  %i0, %o0
a01032ac:  92 10 20 6e  mov  0x6e, %o1
a01032b0:  7f ff bb fa  call  0xa00f2298
a01032b4:  94 10 20 07  mov  7, %o2
a01032b8:  c2 16 e0 12  lduh  [ %i3 + 0x12 ], %g1
a01032bc:  c2 37 bf f2  sth  %g1, [ %fp + -14 ]
a01032c0:  40 00 77 e6  call  0xa0121258
a01032c4:  90 10 00 18  mov  %i0, %o0
a01032c8:  80 8a 20 ff  btst  0xff, %o0
a01032cc:  02 80 00 0a  be  0xa01032f4
a01032d0:  a0 10 20 00  clr  %l0
a01032d4:  80 8e a0 ff  btst  0xff, %i2
a01032d8:  02 80 00 07  be  0xa01032f4
a01032dc:  a0 10 20 01  mov  1, %l0
a01032e0:  da 16 e0 3a  lduh  [ %i3 + 0x3a ], %o5
a01032e4:  11 00 00 10  sethi  %hi(0x4000), %o0
a01032e8:  80 8a 00 0d  btst  %o0, %o5
a01032ec:  32 80 00 02  bne,a   0xa01032f4
a01032f0:  a0 10 20 00  clr  %l0
a01032f4:  d6 17 20 0c  lduh  [ %i4 + 0xc ], %o3
a01032f8:  de 0f 20 20  ldub  [ %i4 + 0x20 ], %o7
a01032fc:  94 02 c0 0f  add  %o3, %o7, %o2
a0103300:  d8 17 00 00  lduh  [ %i4 ], %o4
a0103304:  d8 37 bf dc  sth  %o4, [ %fp + -36 ]
a0103308:  d4 37 bf e2  sth  %o2, [ %fp + -30 ]
a010330c:  40 00 76 61  call  0xa0120c90
a0103310:  90 10 00 18  mov  %i0, %o0
a0103314:  2d 2a 00 b5  sethi  %hi(0xa802d400), %l6
a0103318:  d0 37 bf ee  sth  %o0, [ %fp + -18 ]
a010331c:  d6 05 a2 a4  ld  [ %l6 + 0x2a4 ], %o3
a0103320:  d8 12 e0 08  lduh  [ %o3 + 8 ], %o4
a0103324:  da 12 e0 20  lduh  [ %o3 + 0x20 ], %o5
a0103328:  92 03 20 e0  add  %o4, 0xe0, %o1
a010332c:  80 a3 40 09  cmp  %o5, %o1
a0103330:  16 80 00 05  bge  0xa0103344
a0103334:  80 a6 20 00  cmp  %i0, 0
a0103338:  a4 03 20 e4  add  %o4, 0xe4, %l2
a010333c:  a3 3c a0 03  sra  %l2, 3, %l1
a0103340:  9b 2c 60 03  sll  %l1, 3, %o5
a0103344:  12 80 00 06  bne  0xa010335c
a0103348:  a8 0c 20 ff  and  %l0, 0xff, %l4
a010334c:  e6 17 20 02  lduh  [ %i4 + 2 ], %l3
a0103350:  80 a4 c0 0c  cmp  %l3, %o4
a0103354:  22 80 00 93  be,a   0xa01035a0
a0103358:  da 37 bf dc  sth  %o5, [ %fp + -36 ]
a010335c:  e4 17 bf dc  lduh  [ %fp + -36 ], %l2
a0103360:  af 2c a0 10  sll  %l2, 0x10, %l7
a0103364:  27 00 06 69  sethi  %hi(0x19a400), %l3
a0103368:  93 35 e0 10  srl  %l7, 0x10, %o1
a010336c:  7f ff 6f 81  call  0xa00df170
a0103370:  90 14 e3 d8  or  %l3, 0x3d8, %o0
a0103374:  fa 17 bf dc  lduh  [ %fp + -36 ], %i5
a0103378:  90 10 00 18  mov  %i0, %o0
a010337c:  92 10 20 64  mov  0x64, %o1
a0103380:  d4 17 20 0a  lduh  [ %i4 + 0xa ], %o2
a0103384:  7f ff bc 41  call  0xa00f2488
a0103388:  fa 37 00 00  sth  %i5, [ %i4 ]
a010338c:  90 10 00 18  mov  %i0, %o0
a0103390:  92 10 20 71  mov  0x71, %o1
a0103394:  7f ff bc 3d  call  0xa00f2488
a0103398:  d4 17 bf e2  lduh  [ %fp + -30 ], %o2
a010339c:  f2 17 bf dc  lduh  [ %fp + -36 ], %i1
a01033a0:  ac 10 20 00  clr  %l6
a01033a4:  9a 56 60 64  umul  %i1, 0x64, %o5
a01033a8:  99 40 00 00  rd  %y, %o4
a01033ac:  9e 5d a0 64  smul  %l6, 0x64, %o7
a01033b0:  a4 83 7f f6  addcc  %o5, -10, %l2
a01033b4:  92 03 c0 0c  add  %o7, %o4, %o1
a01033b8:  d0 17 bf e2  lduh  [ %fp + -30 ], %o0
a01033bc:  98 42 7f ff  addx  %o1, -1, %o4
a01033c0:  96 10 00 08  mov  %o0, %o3
a01033c4:  a2 10 20 00  clr  %l1
a01033c8:  92 54 80 08  umul  %l2, %o0, %o1
a01033cc:  91 40 00 00  rd  %y, %o0
a01033d0:  82 5c 80 11  smul  %l2, %l1, %g1
a01033d4:  94 5a c0 0c  smul  %o3, %o4, %o2
a01033d8:  9a 00 40 08  add  %g1, %o0, %o5
a01033dc:  90 03 40 0a  add  %o5, %o2, %o0
a01033e0:  ea 17 bf f2  lduh  [ %fp + -14 ], %l5
a01033e4:  94 10 20 00  clr  %o2
a01033e8:  40 01 47 88  call  0xa0155208
a01033ec:  96 10 00 15  mov  %l5, %o3
a01033f0:  94 10 20 00  clr  %o2
a01033f4:  40 01 47 85  call  0xa0155208
a01033f8:  96 10 20 64  mov  0x64, %o3
a01033fc:  80 a2 60 00  cmp  %o1, 0
a0103400:  22 80 00 02  be,a   0xa0103408
a0103404:  92 10 20 01  mov  1, %o1
a0103408:  c2 16 c0 00  lduh  [ %i3 ], %g1
a010340c:  9a 58 40 09  smul  %g1, %o1, %o5
a0103410:  94 5b 60 64  smul  %o5, 0x64, %o2
a0103414:  9a 10 00 0a  mov  %o2, %o5
a0103418:  98 10 20 00  clr  %o4
a010341c:  d8 3f 20 18  std  %o4, [ %i4 + 0x18 ]
a0103420:  2b 00 06 69  sethi  %hi(0x19a400), %l5
a0103424:  90 15 63 f0  or  %l5, 0x3f0, %o0	! 0x19a7f0
a0103428:  92 10 00 18  mov  %i0, %o1
a010342c:  7f ff 6f 51  call  0xa00df170
a0103430:  d4 07 20 1c  ld  [ %i4 + 0x1c ], %o2
a0103434:  80 a5 20 01  cmp  %l4, 1
a0103438:  22 80 00 54  be,a   0xa0103588
a010343c:  d4 1f 20 18  ldd  [ %i4 + 0x18 ], %o2
a0103440:  80 a6 20 00  cmp  %i0, 0
a0103444:  12 80 00 21  bne  0xa01034c8
a0103448:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a010344c:  25 33 c0 46  sethi  %hi(0xcf011800), %l2
a0103450:  96 14 a2 00  or  %l2, 0x200, %o3	! 0xcf011a00
a0103454:  d8 02 c0 00  ld  [ %o3 ], %o4
a0103458:  80 8b 20 10  btst  0x10, %o4
a010345c:  02 80 00 1b  be  0xa01034c8
a0103460:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a0103464:  80 8e a0 ff  btst  0xff, %i2
a0103468:  22 80 00 19  be,a   0xa01034cc
a010346c:  ec 16 e0 08  lduh  [ %i3 + 8 ], %l6
a0103470:  2b 33 c0 47  sethi  %hi(0xcf011c00), %l5
a0103474:  d2 16 e0 08  lduh  [ %i3 + 8 ], %o1
a0103478:  90 15 60 e4  or  %l5, 0xe4, %o0
a010347c:  d8 1f 20 18  ldd  [ %i4 + 0x18 ], %o4
a0103480:  fa 02 00 00  ld  [ %o0 ], %i5
a0103484:  94 10 20 00  clr  %o2
a0103488:  ae 10 00 09  mov  %o1, %l7
a010348c:  a0 15 60 e0  or  %l5, 0xe0, %l0
a0103490:  92 53 40 09  umul  %o5, %o1, %o1
a0103494:  91 40 00 00  rd  %y, %o0
a0103498:  a6 5b 40 0a  smul  %o5, %o2, %l3
a010349c:  9f 2f 60 08  sll  %i5, 8, %o7
a01034a0:  f6 04 00 00  ld  [ %l0 ], %i3
a01034a4:  ac 5d c0 0c  smul  %l7, %o4, %l6
a01034a8:  b4 16 c0 0f  or  %i3, %o7, %i2
a01034ac:  b2 04 c0 08  add  %l3, %o0, %i1
a01034b0:  90 06 40 16  add  %i1, %l6, %o0
a01034b4:  96 10 00 1a  mov  %i2, %o3
a01034b8:  40 01 47 54  call  0xa0155208
a01034bc:  94 10 20 00  clr  %o2
a01034c0:  10 80 00 c8  b  0xa01037e0
a01034c4:  d0 3f 20 18  std  %o0, [ %i4 + 0x18 ]
a01034c8:  ec 16 e0 08  lduh  [ %i3 + 8 ], %l6
a01034cc:  f2 16 e0 0a  lduh  [ %i3 + 0xa ], %i1
a01034d0:  a2 13 20 cd  or  %o4, 0xcd, %l1
a01034d4:  9e 5d 80 19  smul  %l6, %i1, %o7
a01034d8:  80 53 c0 11  umul  %o7, %l1, %g0
a01034dc:  b5 40 00 00  rd  %y, %i2
a01034e0:  97 36 a0 03  srl  %i2, 3, %o3
a01034e4:  e4 16 e0 02  lduh  [ %i3 + 2 ], %l2
a01034e8:  a8 5a c0 12  smul  %o3, %l2, %l4
a01034ec:  80 55 00 11  umul  %l4, %l1, %g0
a01034f0:  83 40 00 00  rd  %y, %g1
a01034f4:  19 00 be bc  sethi  %hi(0x2faf000), %o4
a01034f8:  83 30 60 03  srl  %g1, 3, %g1
a01034fc:  9a 13 20 7f  or  %o4, 0x7f, %o5
a0103500:  80 a0 40 0d  cmp  %g1, %o5
a0103504:  28 80 00 0d  bleu,a   0xa0103538
a0103508:  82 13 20 80  or  %o4, 0x80, %g1
a010350c:  b6 10 00 01  mov  %g1, %i3
a0103510:  b4 10 20 00  clr  %i2
a0103514:  c2 07 20 18  ld  [ %i4 + 0x18 ], %g1
a0103518:  80 a0 40 1a  cmp  %g1, %i2
a010351c:  2a 80 00 0e  bcs,a   0xa0103554
a0103520:  d0 17 00 00  lduh  [ %i4 ], %o0
a0103524:  80 a0 40 1a  cmp  %g1, %i2
a0103528:  32 80 00 af  bne,a   0xa01037e4
a010352c:  37 00 06 6a  sethi  %hi(0x19a800), %i3
a0103530:  10 80 00 a4  b  0xa01037c0
a0103534:  e0 07 20 1c  ld  [ %i4 + 0x1c ], %l0
a0103538:  b6 10 00 01  mov  %g1, %i3
a010353c:  b4 10 20 00  clr  %i2
a0103540:  c2 07 20 18  ld  [ %i4 + 0x18 ], %g1
a0103544:  80 a0 40 1a  cmp  %g1, %i2
a0103548:  1a bf ff f8  bcc  0xa0103528
a010354c:  01 00 00 00  nop
a0103550:  d0 17 00 00  lduh  [ %i4 ], %o0
a0103554:  94 10 00 08  mov  %o0, %o2
a0103558:  92 52 00 1b  umul  %o0, %i3, %o1
a010355c:  91 40 00 00  rd  %y, %o0
a0103560:  aa 5a 80 1a  smul  %o2, %i2, %l5
a0103564:  ae 10 20 00  clr  %l7
a0103568:  a6 05 40 08  add  %l5, %o0, %l3
a010356c:  ba 5e c0 17  smul  %i3, %l7, %i5
a0103570:  d4 1f 20 18  ldd  [ %i4 + 0x18 ], %o2
a0103574:  40 01 47 25  call  0xa0155208
a0103578:  90 04 c0 1d  add  %l3, %i5, %o0
a010357c:  d2 37 00 00  sth  %o1, [ %i4 ]
a0103580:  10 80 00 98  b  0xa01037e0
a0103584:  f4 3f 20 18  std  %i2, [ %i4 + 0x18 ]
a0103588:  a3 32 e0 1f  srl  %o3, 0x1f, %l1
a010358c:  a8 02 80 0a  add  %o2, %o2, %l4
a0103590:  98 14 40 14  or  %l1, %l4, %o4
a0103594:  9a 02 c0 0b  add  %o3, %o3, %o5
a0103598:  10 bf ff aa  b  0xa0103440
a010359c:  d8 3f 20 18  std  %o4, [ %i4 + 0x18 ]
a01035a0:  af 2b 60 10  sll  %o5, 0x10, %l7
a01035a4:  ab 35 e0 10  srl  %l7, 0x10, %l5
a01035a8:  e8 12 e0 24  lduh  [ %o3 + 0x24 ], %l4
a01035ac:  80 a5 40 14  cmp  %l5, %l4
a01035b0:  1a 80 00 89  bcc  0xa01037d4
a01035b4:  3b 33 c0 47  sethi  %hi(0xcf011c00), %i5
a01035b8:  a6 10 00 0b  mov  %o3, %l3
a01035bc:  a8 0c 20 ff  and  %l0, 0xff, %l4
a01035c0:  aa 10 00 0b  mov  %o3, %l5
a01035c4:  b2 17 60 e4  or  %i5, 0xe4, %i1
a01035c8:  d0 04 c0 00  ld  [ %l3 ], %o0
a01035cc:  1b 00 1c 00  sethi  %hi(0x700000), %o5
a01035d0:  82 0a 00 0d  and  %o0, %o5, %g1
a01035d4:  21 00 08 00  sethi  %hi(0x200000), %l0
a01035d8:  80 a0 40 10  cmp  %g1, %l0
a01035dc:  22 80 00 5f  be,a   0xa0103758
a01035e0:  d4 0c e0 06  ldub  [ %l3 + 6 ], %o2
a01035e4:  e4 17 bf dc  lduh  [ %fp + -36 ], %l2
a01035e8:  99 2c a0 10  sll  %l2, 0x10, %o4
a01035ec:  94 10 20 00  clr  %o2
a01035f0:  9b 33 20 10  srl  %o4, 0x10, %o5
a01035f4:  9a 53 60 64  umul  %o5, 0x64, %o5
a01035f8:  99 40 00 00  rd  %y, %o4
a01035fc:  82 5a a0 64  smul  %o2, 0x64, %g1
a0103600:  a0 83 7f f6  addcc  %o5, -10, %l0
a0103604:  92 00 40 0c  add  %g1, %o4, %o1
a0103608:  d0 17 bf e2  lduh  [ %fp + -30 ], %o0
a010360c:  98 42 7f ff  addx  %o1, -1, %o4
a0103610:  96 10 00 08  mov  %o0, %o3
a0103614:  a2 10 20 00  clr  %l1
a0103618:  9e 5c 00 11  smul  %l0, %l1, %o7
a010361c:  92 54 00 08  umul  %l0, %o0, %o1
a0103620:  91 40 00 00  rd  %y, %o0
a0103624:  94 03 c0 08  add  %o7, %o0, %o2
a0103628:  9a 5a c0 0c  smul  %o3, %o4, %o5
a010362c:  90 02 80 0d  add  %o2, %o5, %o0
a0103630:  c2 17 bf f2  lduh  [ %fp + -14 ], %g1
a0103634:  96 10 00 01  mov  %g1, %o3
a0103638:  40 01 46 f4  call  0xa0155208
a010363c:  94 10 20 00  clr  %o2
a0103640:  94 10 20 00  clr  %o2
a0103644:  40 01 46 f1  call  0xa0155208
a0103648:  96 10 20 64  mov  0x64, %o3
a010364c:  e0 16 c0 00  lduh  [ %i3 ], %l0
a0103650:  a2 5c 00 09  smul  %l0, %o1, %l1
a0103654:  9e 5c 60 64  smul  %l1, 0x64, %o7
a0103658:  90 10 20 00  clr  %o0
a010365c:  92 10 00 0f  mov  %o7, %o1
a0103660:  80 a5 20 01  cmp  %l4, 1
a0103664:  a0 10 00 08  mov  %o0, %l0
a0103668:  02 80 00 47  be  0xa0103784
a010366c:  a2 10 00 0f  mov  %o7, %l1
a0103670:  1b 33 c0 46  sethi  %hi(0xcf011800), %o5
a0103674:  94 13 62 00  or  %o5, 0x200, %o2	! 0xcf011a00
a0103678:  de 02 80 00  ld  [ %o2 ], %o7
a010367c:  80 8b e0 10  btst  0x10, %o7
a0103680:  22 80 00 17  be,a   0xa01036dc
a0103684:  d0 3f 20 18  std  %o0, [ %i4 + 0x18 ]
a0103688:  80 8e a0 ff  btst  0xff, %i2
a010368c:  22 80 00 14  be,a   0xa01036dc
a0103690:  d0 3f 20 18  std  %o0, [ %i4 + 0x18 ]
a0103694:  d0 16 e0 08  lduh  [ %i3 + 8 ], %o0
a0103698:  98 10 00 08  mov  %o0, %o4
a010369c:  96 10 20 00  clr  %o3
a01036a0:  92 54 40 08  umul  %l1, %o0, %o1
a01036a4:  91 40 00 00  rd  %y, %o0
a01036a8:  82 5c 40 0b  smul  %l1, %o3, %g1
a01036ac:  da 06 40 00  ld  [ %i1 ], %o5
a01036b0:  94 17 60 e0  or  %i5, 0xe0, %o2
a01036b4:  9e 5b 00 10  smul  %o4, %l0, %o7
a01036b8:  d6 02 80 00  ld  [ %o2 ], %o3
a01036bc:  a3 2b 60 08  sll  %o5, 8, %l1
a01036c0:  a0 00 40 08  add  %g1, %o0, %l0
a01036c4:  98 12 c0 11  or  %o3, %l1, %o4
a01036c8:  90 04 00 0f  add  %l0, %o7, %o0
a01036cc:  96 10 00 0c  mov  %o4, %o3
a01036d0:  40 01 46 ce  call  0xa0155208
a01036d4:  94 10 20 00  clr  %o2
a01036d8:  d0 3f 20 18  std  %o0, [ %i4 + 0x18 ]
a01036dc:  da 07 20 18  ld  [ %i4 + 0x18 ], %o5
a01036e0:  c2 05 60 10  ld  [ %l5 + 0x10 ], %g1
a01036e4:  80 a3 40 01  cmp  %o5, %g1
a01036e8:  38 80 00 0e  bgu,a   0xa0103720
a01036ec:  f2 05 a2 a4  ld  [ %l6 + 0x2a4 ], %i1
a01036f0:  22 80 00 2e  be,a   0xa01037a8
a01036f4:  e2 07 20 1c  ld  [ %i4 + 0x1c ], %l1
a01036f8:  92 04 a0 08  add  %l2, 8, %o1
a01036fc:  d2 37 bf dc  sth  %o1, [ %fp + -36 ]
a0103700:  a1 2a 60 10  sll  %o1, 0x10, %l0
a0103704:  9f 34 20 10  srl  %l0, 0x10, %o7
a0103708:  e4 14 e0 24  lduh  [ %l3 + 0x24 ], %l2
a010370c:  80 a3 c0 12  cmp  %o7, %l2
a0103710:  2a bf ff af  bcs,a   0xa01035cc
a0103714:  d0 04 c0 00  ld  [ %l3 ], %o0
a0103718:  a4 10 00 09  mov  %o1, %l2
a010371c:  f2 05 a2 a4  ld  [ %l6 + 0x2a4 ], %i1
a0103720:  bb 2c a0 10  sll  %l2, 0x10, %i5
a0103724:  9b 37 60 10  srl  %i5, 0x10, %o5
a0103728:  ec 16 60 24  lduh  [ %i1 + 0x24 ], %l6
a010372c:  80 a3 40 16  cmp  %o5, %l6
a0103730:  28 bf ff 0d  bleu,a   0xa0103364
a0103734:  af 2c a0 10  sll  %l2, 0x10, %l7
a0103738:  a7 35 e0 10  srl  %l7, 0x10, %l3
a010373c:  80 a3 40 13  cmp  %o5, %l3
a0103740:  08 bf ff 09  bleu  0xa0103364
a0103744:  af 2c a0 10  sll  %l2, 0x10, %l7
a0103748:  ae 04 bf f8  add  %l2, -8, %l7
a010374c:  ee 37 bf dc  sth  %l7, [ %fp + -36 ]
a0103750:  10 bf ff 04  b  0xa0103360
a0103754:  a4 10 00 17  mov  %l7, %l2
a0103758:  98 02 bf f8  add  %o2, -8, %o4
a010375c:  92 0b 20 ff  and  %o4, 0xff, %o1
a0103760:  80 a2 60 02  cmp  %o1, 2
a0103764:  18 bf ff a1  bgu  0xa01035e8
a0103768:  e4 17 bf dc  lduh  [ %fp + -36 ], %l2
a010376c:  d6 17 bf dc  lduh  [ %fp + -36 ], %o3
a0103770:  80 8a e0 0f  btst  0xf, %o3
a0103774:  12 bf ff e1  bne  0xa01036f8
a0103778:  a4 10 00 0b  mov  %o3, %l2
a010377c:  10 bf ff 9c  b  0xa01035ec
a0103780:  99 2c a0 10  sll  %l2, 0x10, %o4
a0103784:  a0 02 00 08  add  %o0, %o0, %l0
a0103788:  83 33 e0 1f  srl  %o7, 0x1f, %g1
a010378c:  a2 10 40 10  or  %g1, %l0, %l1
a0103790:  96 03 c0 0f  add  %o7, %o7, %o3
a0103794:  a0 10 00 11  mov  %l1, %l0
a0103798:  a2 10 00 0b  mov  %o3, %l1
a010379c:  90 10 00 10  mov  %l0, %o0
a01037a0:  10 bf ff b4  b  0xa0103670
a01037a4:  92 10 00 0b  mov  %o3, %o1
a01037a8:  d2 05 60 14  ld  [ %l5 + 0x14 ], %o1
a01037ac:  80 a4 40 09  cmp  %l1, %o1
a01037b0:  08 bf ff d3  bleu  0xa01036fc
a01037b4:  92 04 a0 08  add  %l2, 8, %o1
a01037b8:  10 bf ff da  b  0xa0103720
a01037bc:  f2 05 a2 a4  ld  [ %l6 + 0x2a4 ], %i1
a01037c0:  80 a4 00 1b  cmp  %l0, %i3
a01037c4:  3a 80 00 08  bcc,a   0xa01037e4
a01037c8:  37 00 06 6a  sethi  %hi(0x19a800), %i3
a01037cc:  10 bf ff 62  b  0xa0103554
a01037d0:  d0 17 00 00  lduh  [ %i4 ], %o0
a01037d4:  a8 0c 20 ff  and  %l0, 0xff, %l4
a01037d8:  10 bf ff d1  b  0xa010371c
a01037dc:  e4 17 bf dc  lduh  [ %fp + -36 ], %l2
a01037e0:  37 00 06 6a  sethi  %hi(0x19a800), %i3
a01037e4:  92 10 00 18  mov  %i0, %o1
a01037e8:  d4 07 20 1c  ld  [ %i4 + 0x1c ], %o2
a01037ec:  7f ff 6e 61  call  0xa00df170
a01037f0:  90 16 e0 28  or  %i3, 0x28, %o0
a01037f4:  90 10 00 18  mov  %i0, %o0
a01037f8:  7f ff fb bc  call  0xa01026e8
a01037fc:  d2 07 20 1c  ld  [ %i4 + 0x1c ], %o1
a0103800:  81 c7 e0 08  ret
a0103804:  91 e8 20 01  restore  %g0, 1, %o0
