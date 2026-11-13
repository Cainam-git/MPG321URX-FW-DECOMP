# leon2m FUN_a01502c4 0xa01502c4-0xa0150768 (1188 bytes)  [FUN_a0150760 = unreachable ret/restore tail, merged]
a01502c4:  9d e3 bf 88  save  %sp, -120, %sp
a01502c8:  e4 0e 00 00  ldub  [ %i0 ], %l2
a01502cc:  a2 0c a0 ff  and  %l2, 0xff, %l1
a01502d0:  80 a4 60 00  cmp  %l1, 0
a01502d4:  22 80 00 c9  be,a   0xa01505f8
a01502d8:  31 00 06 9c  sethi  %hi(0x1a7000), %i0
a01502dc:  d2 0e 20 01  ldub  [ %i0 + 1 ], %o1	! 0x1a7001
a01502e0:  90 02 7f ff  add  %o1, -1, %o0
a01502e4:  82 0a 20 ff  and  %o0, 0xff, %g1
a01502e8:  80 a0 60 63  cmp  %g1, 0x63
a01502ec:  38 80 00 c1  bgu,a   0xa01505f0
a01502f0:  13 00 06 9c  sethi  %hi(0x1a7000), %o1
a01502f4:  e6 0e 20 02  ldub  [ %i0 + 2 ], %l3
a01502f8:  96 04 ff e1  add  %l3, -31, %o3
a01502fc:  94 0a e0 ff  and  %o3, 0xff, %o2
a0150300:  80 a2 a0 d0  cmp  %o2, 0xd0
a0150304:  18 80 00 bf  bgu  0xa0150600
a0150308:  19 00 06 9c  sethi  %hi(0x1a7000), %o4
a015030c:  de 0e 20 03  ldub  [ %i0 + 3 ], %o7
a0150310:  a0 0b e0 ff  and  %o7, 0xff, %l0
a0150314:  80 a4 20 80  cmp  %l0, 0x80
a0150318:  18 80 00 bc  bgu  0xa0150608
a015031c:  1b 00 06 9d  sethi  %hi(0x1a7400), %o5
a0150320:  ea 0e 20 04  ldub  [ %i0 + 4 ], %l5
a0150324:  a8 0d 60 ff  and  %l5, 0xff, %l4
a0150328:  80 a5 20 00  cmp  %l4, 0
a015032c:  22 80 00 b9  be,a   0xa0150610
a0150330:  1f 00 06 9d  sethi  %hi(0x1a7400), %o7
a0150334:  d4 16 20 06  lduh  [ %i0 + 6 ], %o2
a0150338:  b2 02 bf eb  add  %o2, -21, %i1
a015033c:  af 2e 60 10  sll  %i1, 0x10, %l7
a0150340:  ad 35 e0 10  srl  %l7, 0x10, %l6
a0150344:  80 a5 a1 df  cmp  %l6, 0x1df
a0150348:  38 80 00 b7  bgu,a   0xa0150624
a015034c:  21 00 06 9d  sethi  %hi(0x1a7400), %l0
a0150350:  d6 0e 20 08  ldub  [ %i0 + 8 ], %o3
a0150354:  b6 02 ff ff  add  %o3, -1, %i3
a0150358:  b4 0e e0 ff  and  %i3, 0xff, %i2
a015035c:  80 a6 a0 31  cmp  %i2, 0x31
a0150360:  38 80 00 b3  bgu,a   0xa015062c
a0150364:  23 00 06 9d  sethi  %hi(0x1a7400), %l1
a0150368:  d8 16 20 0a  lduh  [ %i0 + 0xa ], %o4
a015036c:  82 03 3f e1  add  %o4, -31, %g1
a0150370:  bb 28 60 10  sll  %g1, 0x10, %i5
a0150374:  b9 37 60 10  srl  %i5, 0x10, %i4
a0150378:  80 a7 21 71  cmp  %i4, 0x171
a015037c:  18 80 00 ae  bgu  0xa0150634
a0150380:  03 0e e6 b2  sethi  %hi(0x3b9ac800), %g1
a0150384:  95 2a a0 10  sll  %o2, 0x10, %o2
a0150388:  ad 32 a0 10  srl  %o2, 0x10, %l6
a015038c:  94 5d a0 64  smul  %l6, 0x64, %o2
a0150390:  91 2a a0 10  sll  %o2, 0x10, %o0
a0150394:  bb 32 20 10  srl  %o0, 0x10, %i5
a0150398:  ac 10 62 00  or  %g1, 0x200, %l6
a015039c:  83 3d a0 1f  sra  %l6, 0x1f, %g1
a01503a0:  81 80 60 00  mov  %g1, %y
a01503a4:  01 00 00 00  nop
a01503a8:  01 00 00 00  nop
a01503ac:  01 00 00 00  nop
a01503b0:  ae 7d 80 1d  sdiv  %l6, %i5, %l7
a01503b4:  b7 2b 20 10  sll  %o4, 0x10, %i3
a01503b8:  96 0a e0 ff  and  %o3, 0xff, %o3
a01503bc:  39 14 7a e1  sethi  %hi(0x51eb8400), %i4
a01503c0:  b5 36 e0 10  srl  %i3, 0x10, %i2
a01503c4:  96 5d c0 0b  smul  %l7, %o3, %o3
a01503c8:  90 0a 60 ff  and  %o1, 0xff, %o0
a01503cc:  9b 3d a0 1f  sra  %l6, 0x1f, %o5
a01503d0:  81 83 60 00  mov  %o5, %y
a01503d4:  01 00 00 00  nop
a01503d8:  01 00 00 00  nop
a01503dc:  01 00 00 00  nop
a01503e0:  ae 7d 80 1a  sdiv  %l6, %i2, %l7
a01503e4:  ba 17 21 1f  or  %i4, 0x11f, %i5
a01503e8:  b3 2a 20 0a  sll  %o0, 0xa, %i1
a01503ec:  80 5e 40 1d  smul  %i1, %i5, %g0
a01503f0:  9b 40 00 00  rd  %y, %o5
a01503f4:  99 33 60 05  srl  %o5, 5, %o4
a01503f8:  b8 10 00 0f  mov  %o7, %i4
a01503fc:  d8 37 bf ee  sth  %o4, [ %fp + -18 ]
a0150400:  80 a5 c0 0b  cmp  %l7, %o3
a0150404:  b4 10 20 00  clr  %i2
a0150408:  0a 80 00 d5  bcs  0xa015075c
a015040c:  d4 37 bf f6  sth  %o2, [ %fp + -10 ]
a0150410:  15 00 00 08  sethi  %hi(0x2000), %o2
a0150414:  9e 12 a1 55  or  %o2, 0x155, %o7	! 0x2155
a0150418:  9a 5c 00 0f  smul  %l0, %o7, %o5
a015041c:  9e 25 c0 0b  sub  %l7, %o3, %o7
a0150420:  a0 10 20 64  mov  0x64, %l0
a0150424:  80 53 40 1d  umul  %o5, %i5, %g0
a0150428:  83 40 00 00  rd  %y, %g1
a015042c:  96 24 00 08  sub  %l0, %o0, %o3
a0150430:  b3 30 60 05  srl  %g1, 5, %i1
a0150434:  94 5a c0 0f  smul  %o3, %o7, %o2
a0150438:  98 5a 00 0f  smul  %o0, %o7, %o4
a015043c:  b6 0c e0 ff  and  %l3, 0xff, %i3
a0150440:  83 3d a0 1f  sra  %l6, 0x1f, %g1
a0150444:  81 80 60 00  mov  %g1, %y
a0150448:  01 00 00 00  nop
a015044c:  01 00 00 00  nop
a0150450:  01 00 00 00  nop
a0150454:  96 7d 80 1b  sdiv  %l6, %i3, %o3
a0150458:  9a 5e 63 e8  smul  %i1, 0x3e8, %o5
a015045c:  11 00 00 50  sethi  %hi(0x14000), %o0
a0150460:  80 53 00 1d  umul  %o4, %i5, %g0
a0150464:  b7 40 00 00  rd  %y, %i3
a0150468:  80 52 80 1d  umul  %o2, %i5, %g0
a015046c:  b3 40 00 00  rd  %y, %i1
a0150470:  82 12 20 50  or  %o0, 0x50, %g1
a0150474:  97 3a e0 0a  sra  %o3, 0xa, %o3
a0150478:  95 36 60 06  srl  %i1, 6, %o2
a015047c:  90 03 40 01  add  %o5, %g1, %o0
a0150480:  99 36 e0 05  srl  %i3, 5, %o4
a0150484:  81 80 00 00  mov  %g0, %y
a0150488:  01 00 00 00  nop
a015048c:  01 00 00 00  nop
a0150490:  01 00 00 00  nop
a0150494:  b6 73 00 0b  udiv  %o4, %o3, %i3
a0150498:  80 a2 80 08  cmp  %o2, %o0
a015049c:  81 80 00 00  mov  %g0, %y
a01504a0:  01 00 00 00  nop
a01504a4:  01 00 00 00  nop
a01504a8:  01 00 00 00  nop
a01504ac:  b2 73 c0 0b  udiv  %o7, %o3, %i1
a01504b0:  1a 80 00 64  bcc  0xa0150640
a01504b4:  ac 24 00 09  sub  %l0, %o1, %l6
a01504b8:  3b 04 18 93  sethi  %hi(0x10624c00), %i5
a01504bc:  a0 22 00 0a  sub  %o0, %o2, %l0
a01504c0:  ae 17 61 d3  or  %i5, 0x1d3, %l7
a01504c4:  80 54 00 17  umul  %l0, %l7, %g0
a01504c8:  93 40 00 00  rd  %y, %o1
a01504cc:  83 32 60 06  srl  %o1, 6, %g1
a01504d0:  80 a0 60 52  cmp  %g1, 0x52
a01504d4:  08 80 00 0b  bleu  0xa0150500
a01504d8:  ac 10 20 00  clr  %l6
a01504dc:  1f 3f ff f7  sethi  %hi(0xffffdc00), %o7
a01504e0:  82 58 60 64  smul  %g1, 0x64, %g1
a01504e4:  9a 13 e3 f8  or  %o7, 0x3f8, %o5
a01504e8:  17 07 ae 28  sethi  %hi(0x1eb8a000), %o3
a01504ec:  ac 00 40 0d  add  %g1, %o5, %l6
a01504f0:  98 12 e0 91  or  %o3, 0x91, %o4
a01504f4:  80 55 80 0c  umul  %l6, %o4, %g0
a01504f8:  91 40 00 00  rd  %y, %o0
a01504fc:  ad 32 20 0a  srl  %o0, 0xa, %l6
a0150500:  d2 0e 20 0c  ldub  [ %i0 + 0xc ], %o1
a0150504:  ee 17 bf ee  lduh  [ %fp + -18 ], %l7
a0150508:  9e 02 40 17  add  %o1, %l7, %o7
a015050c:  a0 03 ff 80  add  %o7, -128, %l0
a0150510:  7f ff 38 73  call  0xa011e6dc
a0150514:  90 10 00 14  mov  %l4, %o0
a0150518:  94 0c e0 ff  and  %l3, 0xff, %o2
a015051c:  1b 2a 00 a9  sethi  %hi(0xa802a400), %o5
a0150520:  27 2a 00 a9  sethi  %hi(0xa802a400), %l3
a0150524:  ea 2b 60 9a  stb  %l5, [ %o5 + 0x9a ]
a0150528:  f6 34 e0 b2  sth  %i3, [ %l3 + 0xb2 ]
a015052c:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a0150530:  19 2a 00 a9  sethi  %hi(0xa802a400), %o4
a0150534:  d6 17 bf f6  lduh  [ %fp + -10 ], %o3
a0150538:  11 2a 00 a9  sethi  %hi(0xa802a400), %o0
a015053c:  37 2a 00 b3  sethi  %hi(0xa802cc00), %i3
a0150540:  31 2a 00 a9  sethi  %hi(0xa802a400), %i0
a0150544:  2b 2a 00 b3  sethi  %hi(0xa802cc00), %l5
a0150548:  29 2a 00 b3  sethi  %hi(0xa802cc00), %l4
a015054c:  e0 30 60 9e  sth  %l0, [ %g1 + 0x9e ]
a0150550:  d6 33 20 a0  sth  %o3, [ %o4 + 0xa0 ]
a0150554:  d4 32 20 9c  sth  %o2, [ %o0 + 0x9c ]
a0150558:  ec 2e e0 85  stb  %l6, [ %i3 + 0x85 ]
a015055c:  f2 36 20 b0  sth  %i1, [ %i0 + 0xb0 ]
a0150560:  e4 2d 60 86  stb  %l2, [ %l5 + 0x86 ]
a0150564:  80 8c 60 01  btst  1, %l1
a0150568:  02 80 00 04  be  0xa0150578
a015056c:  e4 2d 20 87  stb  %l2, [ %l4 + 0x87 ]
a0150570:  33 2a 00 a9  sethi  %hi(0xa802a400), %i1
a0150574:  f8 2e 60 a8  stb  %i4, [ %i1 + 0xa8 ]	! 0xa802a4a8
a0150578:  80 8c 60 02  btst  2, %l1
a015057c:  02 80 00 04  be  0xa015058c
a0150580:  80 8c 60 04  btst  4, %l1
a0150584:  2d 2a 00 a9  sethi  %hi(0xa802a400), %l6
a0150588:  f8 2d a0 a9  stb  %i4, [ %l6 + 0xa9 ]	! 0xa802a4a9
a015058c:  02 80 00 04  be  0xa015059c
a0150590:  80 8c 60 08  btst  8, %l1
a0150594:  3b 2a 00 a9  sethi  %hi(0xa802a400), %i5
a0150598:  f8 2f 60 aa  stb  %i4, [ %i5 + 0xaa ]	! 0xa802a4aa
a015059c:  02 80 00 04  be  0xa01505ac
a01505a0:  80 8c 60 10  btst  0x10, %l1
a01505a4:  29 2a 00 a9  sethi  %hi(0xa802a400), %l4
a01505a8:  f8 2d 20 ab  stb  %i4, [ %l4 + 0xab ]	! 0xa802a4ab
a01505ac:  02 80 00 04  be  0xa01505bc
a01505b0:  80 8c 60 20  btst  0x20, %l1
a01505b4:  2b 2a 00 a9  sethi  %hi(0xa802a400), %l5
a01505b8:  f8 2d 60 ac  stb  %i4, [ %l5 + 0xac ]	! 0xa802a4ac
a01505bc:  02 80 00 04  be  0xa01505cc
a01505c0:  80 8c 60 40  btst  0x40, %l1
a01505c4:  31 2a 00 a9  sethi  %hi(0xa802a400), %i0
a01505c8:  f8 2e 20 ad  stb  %i4, [ %i0 + 0xad ]	! 0xa802a4ad
a01505cc:  02 80 00 04  be  0xa01505dc
a01505d0:  80 8c a0 80  btst  0x80, %l2
a01505d4:  23 2a 00 a9  sethi  %hi(0xa802a400), %l1
a01505d8:  f8 2c 60 ae  stb  %i4, [ %l1 + 0xae ]	! 0xa802a4ae
a01505dc:  12 80 00 10  bne  0xa015061c
a01505e0:  25 2a 00 a9  sethi  %hi(0xa802a400), %l2
a01505e4:  39 2a 00 b3  sethi  %hi(0xa802cc00), %i4
a01505e8:  10 80 00 5d  b  0xa015075c
a01505ec:  f4 2f 20 84  stb  %i2, [ %i4 + 0x84 ]	! 0xa802cc84
a01505f0:  7f fe 3a e0  call  0xa00df170
a01505f4:  91 ea 63 e0  restore  %o1, 0x3e0, %o0
a01505f8:  7f fe 3a de  call  0xa00df170
a01505fc:  91 ee 23 c8  restore  %i0, 0x3c8, %o0
a0150600:  7f fe 3a dc  call  0xa00df170
a0150604:  91 eb 23 f8  restore  %o4, 0x3f8, %o0
a0150608:  7f fe 3a da  call  0xa00df170
a015060c:  91 eb 60 10  restore  %o5, 0x10, %o0
a0150610:  b0 13 e0 28  or  %o7, 0x28, %i0
a0150614:  7f fe 3a d7  call  0xa00df170
a0150618:  81 e8 00 00  restore
a015061c:  10 bf ff f2  b  0xa01505e4
a0150620:  f8 2c a0 af  stb  %i4, [ %l2 + 0xaf ]
a0150624:  7f fe 3a d3  call  0xa00df170
a0150628:  91 ec 20 40  restore  %l0, 0x40, %o0
a015062c:  7f fe 3a d1  call  0xa00df170
a0150630:  91 ec 60 58  restore  %l1, 0x58, %o0
a0150634:  25 00 06 9d  sethi  %hi(0x1a7400), %l2
a0150638:  7f fe 3a ce  call  0xa00df170
a015063c:  91 ec a0 70  restore  %l2, 0x70, %o0
a0150640:  98 0d a0 ff  and  %l6, 0xff, %o4
a0150644:  95 2b 20 0a  sll  %o4, 0xa, %o2
a0150648:  92 5b 00 0f  smul  %o4, %o7, %o1
a015064c:  80 52 40 1d  umul  %o1, %i5, %g0
a0150650:  b7 40 00 00  rd  %y, %i3
a0150654:  80 5a 80 1d  smul  %o2, %i5, %g0
a0150658:  b9 40 00 00  rd  %y, %i4
a015065c:  9b 36 e0 05  srl  %i3, 5, %o5
a0150660:  b5 37 20 05  srl  %i4, 5, %i2
a0150664:  81 80 00 00  mov  %g0, %y
a0150668:  01 00 00 00  nop
a015066c:  01 00 00 00  nop
a0150670:  01 00 00 00  nop
a0150674:  b6 73 40 0b  udiv  %o5, %o3, %i3
a0150678:  f4 37 bf ee  sth  %i2, [ %fp + -18 ]
a015067c:  80 a3 40 08  cmp  %o5, %o0
a0150680:  08 80 00 04  bleu  0xa0150690
a0150684:  94 22 00 0d  sub  %o0, %o5, %o2
a0150688:  a0 05 c0 08  add  %l7, %o0, %l0
a015068c:  94 24 00 0d  sub  %l0, %o5, %o2
a0150690:  82 10 20 64  mov  0x64, %g1
a0150694:  96 20 40 0c  sub  %g1, %o4, %o3
a0150698:  19 14 7a e1  sethi  %hi(0x51eb8400), %o4
a015069c:  ba 5a c0 0f  smul  %o3, %o7, %i5
a01506a0:  90 13 21 1f  or  %o4, 0x11f, %o0
a01506a4:  80 57 40 08  umul  %i5, %o0, %g0
a01506a8:  af 40 00 00  rd  %y, %l7
a01506ac:  97 35 e0 05  srl  %l7, 5, %o3
a01506b0:  80 a2 80 0b  cmp  %o2, %o3
a01506b4:  0a 80 00 27  bcs  0xa0150750
a01506b8:  35 04 18 93  sethi  %hi(0x10624c00), %i2
a01506bc:  9e 16 a1 d3  or  %i2, 0x1d3, %o7	! 0x10624dd3
a01506c0:  80 52 80 0f  umul  %o2, %o7, %g0
a01506c4:  9b 40 00 00  rd  %y, %o5
a01506c8:  83 33 60 06  srl  %o5, 6, %g1
a01506cc:  80 a0 60 52  cmp  %g1, 0x52
a01506d0:  08 80 00 0b  bleu  0xa01506fc
a01506d4:  b8 10 20 00  clr  %i4
a01506d8:  11 3f ff f7  sethi  %hi(0xffffdc00), %o0
a01506dc:  ae 58 60 64  smul  %g1, 0x64, %l7
a01506e0:  ba 12 23 f8  or  %o0, 0x3f8, %i5
a01506e4:  21 07 ae 28  sethi  %hi(0x1eb8a000), %l0
a01506e8:  b8 05 c0 1d  add  %l7, %i5, %i4
a01506ec:  ac 14 20 91  or  %l0, 0x91, %l6
a01506f0:  80 57 00 16  umul  %i4, %l6, %g0
a01506f4:  93 40 00 00  rd  %y, %o1
a01506f8:  b9 32 60 0a  srl  %o1, 0xa, %i4
a01506fc:  9b 32 e0 01  srl  %o3, 1, %o5
a0150700:  03 04 18 93  sethi  %hi(0x10624c00), %g1
a0150704:  96 10 61 d3  or  %g1, 0x1d3, %o3	! 0x10624dd3
a0150708:  98 22 80 0d  sub  %o2, %o5, %o4
a015070c:  80 53 00 0b  umul  %o4, %o3, %g0
a0150710:  95 40 00 00  rd  %y, %o2
a0150714:  83 32 a0 06  srl  %o2, 6, %g1
a0150718:  80 a0 60 52  cmp  %g1, 0x52
a015071c:  08 80 00 0b  bleu  0xa0150748
a0150720:  ac 10 20 00  clr  %l6
a0150724:  3b 3f ff f7  sethi  %hi(0xffffdc00), %i5
a0150728:  2d 07 ae 28  sethi  %hi(0x1eb8a000), %l6
a015072c:  a0 58 60 64  smul  %g1, 0x64, %l0
a0150730:  ae 17 63 f8  or  %i5, 0x3f8, %l7
a0150734:  92 15 a0 91  or  %l6, 0x91, %o1
a0150738:  b4 04 00 17  add  %l0, %l7, %i2
a015073c:  80 56 80 09  umul  %i2, %o1, %g0
a0150740:  9f 40 00 00  rd  %y, %o7
a0150744:  ad 33 e0 0a  srl  %o7, 0xa, %l6
a0150748:  10 bf ff 6e  b  0xa0150500
a015074c:  b4 10 20 01  mov  1, %i2
a0150750:  27 00 06 9d  sethi  %hi(0x1a7400), %l3
a0150754:  7f fe 3a 87  call  0xa00df170
a0150758:  91 ec e0 88  restore  %l3, 0x88, %o0
a015075c:  01 00 00 00  nop
a0150760:  81 c7 e0 08  ret
a0150764:  81 e8 00 00  restore
