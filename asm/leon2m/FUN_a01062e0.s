# leon2m FUN_a01062e0 0xa01062e0-0xa0106860 (1408 bytes)
a01062e0:  9d e3 bf 98  save  %sp, -104, %sp
a01062e4:  80 8e 60 ff  btst  0xff, %i1
a01062e8:  02 80 00 a0  be  0xa0106568
a01062ec:  01 00 00 00  nop
a01062f0:  40 00 11 5d  call  0xa010a864
a01062f4:  01 00 00 00  nop
a01062f8:  80 8a 20 ff  btst  0xff, %o0
a01062fc:  12 80 01 45  bne  0xa0106810
a0106300:  01 00 00 00  nop
a0106304:  92 10 20 64  mov  0x64, %o1	! 0x64
a0106308:  7f ff b0 bc  call  0xa00f25f8
a010630c:  90 10 20 00  clr  %o0
a0106310:  83 2a 20 10  sll  %o0, 0x10, %g1
a0106314:  af 30 60 10  srl  %g1, 0x10, %l7
a0106318:  90 10 20 00  clr  %o0
a010631c:  7f ff b0 b7  call  0xa00f25f8
a0106320:  92 10 20 64  mov  0x64, %o1
a0106324:  91 2a 20 10  sll  %o0, 0x10, %o0
a0106328:  91 32 20 10  srl  %o0, 0x10, %o0
a010632c:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a0106330:  d6 02 a2 a4  ld  [ %o2 + 0x2a4 ], %o3	! 0xa802d6a4
a0106334:  a7 2a 20 10  sll  %o0, 0x10, %l3
a0106338:  95 34 e0 10  srl  %l3, 0x10, %o2
a010633c:  e4 12 e0 26  lduh  [ %o3 + 0x26 ], %l2
a0106340:  f2 12 e0 30  lduh  [ %o3 + 0x30 ], %i1
a0106344:  ec 12 e0 32  lduh  [ %o3 + 0x32 ], %l6
a0106348:  ea 12 e0 22  lduh  [ %o3 + 0x22 ], %l5
a010634c:  e0 12 e0 2c  lduh  [ %o3 + 0x2c ], %l0
a0106350:  fa 12 e0 28  lduh  [ %o3 + 0x28 ], %i5
a0106354:  e8 12 e0 0a  lduh  [ %o3 + 0xa ], %l4
a0106358:  e6 12 e0 08  lduh  [ %o3 + 8 ], %l3
a010635c:  90 10 20 04  mov  4, %o0
a0106360:  7f ff b0 4a  call  0xa00f2488
a0106364:  92 10 20 18  mov  0x18, %o1
a0106368:  93 2d e0 10  sll  %l7, 0x10, %o1
a010636c:  95 32 60 10  srl  %o1, 0x10, %o2
a0106370:  90 10 20 04  mov  4, %o0
a0106374:  7f ff b0 45  call  0xa00f2488
a0106378:  92 10 20 1a  mov  0x1a, %o1
a010637c:  90 10 20 04  mov  4, %o0
a0106380:  92 10 20 61  mov  0x61, %o1
a0106384:  7f ff af c5  call  0xa00f2298
a0106388:  94 10 20 12  mov  0x12, %o2
a010638c:  90 10 20 04  mov  4, %o0
a0106390:  92 10 20 54  mov  0x54, %o1
a0106394:  7f ff af c1  call  0xa00f2298
a0106398:  94 10 20 00  clr  %o2
a010639c:  99 2c 20 10  sll  %l0, 0x10, %o4
a01063a0:  95 33 20 10  srl  %o4, 0x10, %o2
a01063a4:  90 10 20 04  mov  4, %o0
a01063a8:  7f ff b0 38  call  0xa00f2488
a01063ac:  92 10 20 5b  mov  0x5b, %o1
a01063b0:  83 2e 60 10  sll  %i1, 0x10, %g1
a01063b4:  af 30 60 10  srl  %g1, 0x10, %l7
a01063b8:  94 10 00 17  mov  %l7, %o2
a01063bc:  90 10 20 04  mov  4, %o0
a01063c0:  92 10 20 be  mov  0xbe, %o1
a01063c4:  7f ff b0 31  call  0xa00f2488
a01063c8:  a3 2d 60 10  sll  %l5, 0x10, %l1
a01063cc:  ab 34 60 10  srl  %l1, 0x10, %l5
a01063d0:  94 10 00 15  mov  %l5, %o2
a01063d4:  90 10 20 04  mov  4, %o0
a01063d8:  7f ff b0 2c  call  0xa00f2488
a01063dc:  92 10 20 5e  mov  0x5e, %o1
a01063e0:  91 2c a0 10  sll  %l2, 0x10, %o0
a01063e4:  95 32 20 10  srl  %o0, 0x10, %o2
a01063e8:  90 10 20 04  mov  4, %o0
a01063ec:  7f ff b0 27  call  0xa00f2488
a01063f0:  92 10 20 a0  mov  0xa0, %o1
a01063f4:  9e 06 40 16  add  %i1, %l6, %o7
a01063f8:  97 2b e0 10  sll  %o7, 0x10, %o3
a01063fc:  a1 32 e0 10  srl  %o3, 0x10, %l0
a0106400:  b3 2d 20 10  sll  %l4, 0x10, %i1
a0106404:  94 10 00 10  mov  %l0, %o2
a0106408:  90 10 20 04  mov  4, %o0
a010640c:  7f ff b0 1f  call  0xa00f2488
a0106410:  92 10 20 62  mov  0x62, %o1
a0106414:  ad 36 60 10  srl  %i1, 0x10, %l6
a0106418:  94 10 00 16  mov  %l6, %o2
a010641c:  90 10 20 04  mov  4, %o0
a0106420:  7f ff b0 1a  call  0xa00f2488
a0106424:  92 10 20 64  mov  0x64, %o1
a0106428:  9a 04 80 1d  add  %l2, %i5, %o5
a010642c:  95 2b 60 10  sll  %o5, 0x10, %o2
a0106430:  a5 32 a0 10  srl  %o2, 0x10, %l2
a0106434:  a7 2c e0 10  sll  %l3, 0x10, %l3
a0106438:  94 10 00 12  mov  %l2, %o2
a010643c:  90 10 20 04  mov  4, %o0
a0106440:  7f ff b0 12  call  0xa00f2488
a0106444:  92 10 20 66  mov  0x66, %o1
a0106448:  a3 34 e0 10  srl  %l3, 0x10, %l1
a010644c:  94 10 00 11  mov  %l1, %o2
a0106450:  90 10 20 04  mov  4, %o0
a0106454:  7f ff b0 0d  call  0xa00f2488
a0106458:  92 10 20 68  mov  0x68, %o1
a010645c:  94 10 00 10  mov  %l0, %o2
a0106460:  90 10 20 04  mov  4, %o0
a0106464:  7f ff b0 09  call  0xa00f2488
a0106468:  92 10 20 6f  mov  0x6f, %o1
a010646c:  94 10 00 16  mov  %l6, %o2
a0106470:  90 10 20 04  mov  4, %o0
a0106474:  7f ff b0 05  call  0xa00f2488
a0106478:  92 10 20 71  mov  0x71, %o1
a010647c:  94 10 00 12  mov  %l2, %o2
a0106480:  90 10 20 04  mov  4, %o0
a0106484:  7f ff b0 01  call  0xa00f2488
a0106488:  92 10 20 73  mov  0x73, %o1
a010648c:  94 10 00 11  mov  %l1, %o2
a0106490:  90 10 20 04  mov  4, %o0
a0106494:  7f ff af fd  call  0xa00f2488
a0106498:  92 10 20 75  mov  0x75, %o1
a010649c:  94 10 00 15  mov  %l5, %o2
a01064a0:  90 10 20 04  mov  4, %o0
a01064a4:  7f ff af f9  call  0xa00f2488
a01064a8:  92 10 20 79  mov  0x79, %o1
a01064ac:  94 10 00 17  mov  %l7, %o2
a01064b0:  90 10 20 04  mov  4, %o0
a01064b4:  7f ff af f5  call  0xa00f2488
a01064b8:  92 10 20 be  mov  0xbe, %o1
a01064bc:  90 10 20 04  mov  4, %o0
a01064c0:  92 10 20 6e  mov  0x6e, %o1
a01064c4:  7f ff af 75  call  0xa00f2298
a01064c8:  94 10 20 01  mov  1, %o2
a01064cc:  90 10 20 04  mov  4, %o0
a01064d0:  92 10 20 88  mov  0x88, %o1
a01064d4:  7f ff af 71  call  0xa00f2298
a01064d8:  94 10 20 11  mov  0x11, %o2
a01064dc:  90 10 20 04  mov  4, %o0
a01064e0:  92 10 20 86  mov  0x86, %o1
a01064e4:  7f ff af 6d  call  0xa00f2298
a01064e8:  94 10 20 18  mov  0x18, %o2
a01064ec:  15 33 c0 3b  sethi  %hi(0xcf00ec00), %o2
a01064f0:  92 12 a0 04  or  %o2, 4, %o1	! 0xcf00ec04
a01064f4:  c0 22 40 00  clr  [ %o1 ]
a01064f8:  98 12 a0 08  or  %o2, 8, %o4
a01064fc:  c0 23 00 00  clr  [ %o4 ]
a0106500:  82 12 a0 0c  or  %o2, 0xc, %g1
a0106504:  c0 20 40 00  clr  [ %g1 ]
a0106508:  90 0c 60 ff  and  %l1, 0xff, %o0
a010650c:  af 34 e0 18  srl  %l3, 0x18, %l7
a0106510:  ba 12 a0 10  or  %o2, 0x10, %i5
a0106514:  d0 27 40 00  st  %o0, [ %i5 ]
a0106518:  a6 0d e0 1f  and  %l7, 0x1f, %l3
a010651c:  aa 12 a0 14  or  %o2, 0x14, %l5
a0106520:  e6 25 40 00  st  %l3, [ %l5 ]
a0106524:  a4 12 a0 18  or  %o2, 0x18, %l2
a0106528:  c0 24 80 00  clr  [ %l2 ]
a010652c:  a2 12 a0 1c  or  %o2, 0x1c, %l1
a0106530:  c0 24 40 00  clr  [ %l1 ]
a0106534:  ac 0d a0 ff  and  %l6, 0xff, %l6
a0106538:  9f 36 60 18  srl  %i1, 0x18, %o7
a010653c:  a0 12 a0 20  or  %o2, 0x20, %l0
a0106540:  ec 24 00 00  st  %l6, [ %l0 ]
a0106544:  a8 0b e0 1f  and  %o7, 0x1f, %l4
a0106548:  96 12 a0 24  or  %o2, 0x24, %o3
a010654c:  e8 22 c0 00  st  %l4, [ %o3 ]
a0106550:  9a 10 20 09  mov  9, %o5
a0106554:  da 22 80 00  st  %o5, [ %o2 ]
a0106558:  98 12 a1 80  or  %o2, 0x180, %o4
a010655c:  92 10 20 10  mov  0x10, %o1
a0106560:  d2 23 00 00  st  %o1, [ %o4 ]
a0106564:  30 80 00 bd  b,a   0xa0106858
a0106568:  40 00 10 bf  call  0xa010a864
a010656c:  01 00 00 00  nop
a0106570:  80 8a 20 ff  btst  0xff, %o0
a0106574:  12 80 00 a1  bne  0xa01067f8
a0106578:  01 00 00 00  nop
a010657c:  92 10 20 68  mov  0x68, %o1	! 0x68
a0106580:  7f ff b0 1e  call  0xa00f25f8
a0106584:  90 10 20 00  clr  %o0
a0106588:  9b 2a 20 10  sll  %o0, 0x10, %o5
a010658c:  ab 33 60 10  srl  %o5, 0x10, %l5
a0106590:  90 10 20 00  clr  %o0
a0106594:  7f ff b0 19  call  0xa00f25f8
a0106598:  92 10 20 64  mov  0x64, %o1
a010659c:  af 2a 20 10  sll  %o0, 0x10, %l7
a01065a0:  91 35 e0 10  srl  %l7, 0x10, %o0
a01065a4:  33 2a 00 b5  sethi  %hi(0xa802d400), %i1
a01065a8:  de 06 62 a4  ld  [ %i1 + 0x2a4 ], %o7	! 0xa802d6a4
a01065ac:  99 2a 20 10  sll  %o0, 0x10, %o4
a01065b0:  fa 13 e0 26  lduh  [ %o7 + 0x26 ], %i5
a01065b4:  e8 13 e0 20  lduh  [ %o7 + 0x20 ], %l4
a01065b8:  e2 13 e0 2a  lduh  [ %o7 + 0x2a ], %l1
a01065bc:  e4 13 e0 08  lduh  [ %o7 + 8 ], %l2
a01065c0:  ec 13 e0 28  lduh  [ %o7 + 0x28 ], %l6
a01065c4:  e6 13 e0 0a  lduh  [ %o7 + 0xa ], %l3
a01065c8:  95 33 20 10  srl  %o4, 0x10, %o2
a01065cc:  90 10 20 04  mov  4, %o0
a01065d0:  7f ff af ae  call  0xa00f2488
a01065d4:  92 10 20 18  mov  0x18, %o1
a01065d8:  95 2d 60 10  sll  %l5, 0x10, %o2
a01065dc:  95 32 a0 10  srl  %o2, 0x10, %o2
a01065e0:  90 10 20 04  mov  4, %o0
a01065e4:  7f ff af a9  call  0xa00f2488
a01065e8:  92 10 20 1a  mov  0x1a, %o1
a01065ec:  90 10 20 04  mov  4, %o0
a01065f0:  92 10 20 61  mov  0x61, %o1
a01065f4:  7f ff af 29  call  0xa00f2298
a01065f8:  94 10 20 12  mov  0x12, %o2
a01065fc:  90 10 20 04  mov  4, %o0
a0106600:  92 10 20 54  mov  0x54, %o1
a0106604:  7f ff af 25  call  0xa00f2298
a0106608:  94 10 20 00  clr  %o2
a010660c:  9b 2c 60 10  sll  %l1, 0x10, %o5
a0106610:  95 33 60 10  srl  %o5, 0x10, %o2
a0106614:  90 10 20 04  mov  4, %o0
a0106618:  7f ff af 9c  call  0xa00f2488
a010661c:  92 10 20 5b  mov  0x5b, %o1
a0106620:  90 10 20 04  mov  4, %o0
a0106624:  92 10 20 be  mov  0xbe, %o1
a0106628:  7f ff af 98  call  0xa00f2488
a010662c:  94 10 20 01  mov  1, %o2
a0106630:  97 2d 20 10  sll  %l4, 0x10, %o3
a0106634:  ab 32 e0 10  srl  %o3, 0x10, %l5
a0106638:  94 10 00 15  mov  %l5, %o2
a010663c:  90 10 20 04  mov  4, %o0
a0106640:  7f ff af 92  call  0xa00f2488
a0106644:  92 10 20 5e  mov  0x5e, %o1
a0106648:  af 2f 60 10  sll  %i5, 0x10, %l7
a010664c:  95 35 e0 10  srl  %l7, 0x10, %o2
a0106650:  90 10 20 04  mov  4, %o0
a0106654:  7f ff af 8d  call  0xa00f2488
a0106658:  92 10 20 a0  mov  0xa0, %o1
a010665c:  a7 2c e0 10  sll  %l3, 0x10, %l3
a0106660:  90 10 20 04  mov  4, %o0
a0106664:  92 10 20 62  mov  0x62, %o1
a0106668:  7f ff af 88  call  0xa00f2488
a010666c:  94 10 20 02  mov  2, %o2
a0106670:  af 34 e0 10  srl  %l3, 0x10, %l7
a0106674:  90 10 20 04  mov  4, %o0
a0106678:  92 10 20 64  mov  0x64, %o1
a010667c:  7f ff af 83  call  0xa00f2488
a0106680:  94 10 00 17  mov  %l7, %o2
a0106684:  92 07 40 16  add  %i5, %l6, %o1
a0106688:  83 2a 60 10  sll  %o1, 0x10, %g1
a010668c:  a1 30 60 10  srl  %g1, 0x10, %l0
a0106690:  ad 2c a0 10  sll  %l2, 0x10, %l6
a0106694:  94 10 00 10  mov  %l0, %o2
a0106698:  90 10 20 04  mov  4, %o0
a010669c:  7f ff af 7b  call  0xa00f2488
a01066a0:  92 10 20 66  mov  0x66, %o1
a01066a4:  a3 35 a0 10  srl  %l6, 0x10, %l1
a01066a8:  94 10 00 11  mov  %l1, %o2
a01066ac:  90 10 20 04  mov  4, %o0
a01066b0:  7f ff af 76  call  0xa00f2488
a01066b4:  92 10 20 68  mov  0x68, %o1
a01066b8:  90 10 20 04  mov  4, %o0
a01066bc:  92 10 20 6f  mov  0x6f, %o1
a01066c0:  7f ff af 72  call  0xa00f2488
a01066c4:  94 10 20 02  mov  2, %o2
a01066c8:  90 10 20 04  mov  4, %o0
a01066cc:  92 10 20 71  mov  0x71, %o1
a01066d0:  7f ff af 6e  call  0xa00f2488
a01066d4:  94 10 00 17  mov  %l7, %o2
a01066d8:  94 10 00 10  mov  %l0, %o2
a01066dc:  90 10 20 04  mov  4, %o0
a01066e0:  7f ff af 6a  call  0xa00f2488
a01066e4:  92 10 20 73  mov  0x73, %o1
a01066e8:  94 10 00 11  mov  %l1, %o2
a01066ec:  90 10 20 04  mov  4, %o0
a01066f0:  7f ff af 66  call  0xa00f2488
a01066f4:  92 10 20 75  mov  0x75, %o1
a01066f8:  94 10 00 15  mov  %l5, %o2
a01066fc:  90 10 20 04  mov  4, %o0
a0106700:  7f ff af 62  call  0xa00f2488
a0106704:  92 10 20 79  mov  0x79, %o1
a0106708:  90 10 20 04  mov  4, %o0
a010670c:  92 10 20 be  mov  0xbe, %o1
a0106710:  7f ff af 5e  call  0xa00f2488
a0106714:  94 10 20 01  mov  1, %o2
a0106718:  96 10 20 00  clr  %o3
a010671c:  90 10 20 04  mov  4, %o0
a0106720:  92 10 20 50  mov  0x50, %o1
a0106724:  7f ff af 02  call  0xa00f232c
a0106728:  94 10 20 20  mov  0x20, %o2
a010672c:  90 10 20 04  mov  4, %o0
a0106730:  92 10 20 6e  mov  0x6e, %o1
a0106734:  7f ff ae d9  call  0xa00f2298
a0106738:  94 10 20 01  mov  1, %o2
a010673c:  90 10 20 04  mov  4, %o0
a0106740:  92 10 20 88  mov  0x88, %o1
a0106744:  7f ff ae d5  call  0xa00f2298
a0106748:  94 10 20 11  mov  0x11, %o2
a010674c:  90 10 20 04  mov  4, %o0
a0106750:  92 10 20 86  mov  0x86, %o1
a0106754:  7f ff ae d1  call  0xa00f2298
a0106758:  94 10 20 18  mov  0x18, %o2
a010675c:  21 33 c0 3b  sethi  %hi(0xcf00ec00), %l0
a0106760:  98 14 20 04  or  %l0, 4, %o4	! 0xcf00ec04
a0106764:  c0 23 00 00  clr  [ %o4 ]
a0106768:  90 14 20 08  or  %l0, 8, %o0
a010676c:  c0 22 00 00  clr  [ %o0 ]
a0106770:  9e 14 20 0c  or  %l0, 0xc, %o7
a0106774:  c0 23 c0 00  clr  [ %o7 ]
a0106778:  a8 0c 60 ff  and  %l1, 0xff, %l4
a010677c:  a5 35 a0 18  srl  %l6, 0x18, %l2
a0106780:  ba 14 20 10  or  %l0, 0x10, %i5
a0106784:  e8 27 40 00  st  %l4, [ %i5 ]
a0106788:  9a 0c a0 1f  and  %l2, 0x1f, %o5
a010678c:  94 14 20 14  or  %l0, 0x14, %o2
a0106790:  da 22 80 00  st  %o5, [ %o2 ]
a0106794:  96 14 20 18  or  %l0, 0x18, %o3
a0106798:  c0 22 c0 00  clr  [ %o3 ]
a010679c:  92 14 20 1c  or  %l0, 0x1c, %o1
a01067a0:  c0 22 40 00  clr  [ %o1 ]
a01067a4:  aa 0d e0 ff  and  %l7, 0xff, %l5
a01067a8:  99 34 e0 18  srl  %l3, 0x18, %o4
a01067ac:  82 14 20 20  or  %l0, 0x20, %g1
a01067b0:  ea 20 40 00  st  %l5, [ %g1 ]
a01067b4:  a2 0b 20 1f  and  %o4, 0x1f, %l1
a01067b8:  90 14 20 24  or  %l0, 0x24, %o0
a01067bc:  e2 22 00 00  st  %l1, [ %o0 ]
a01067c0:  ac 10 20 09  mov  9, %l6
a01067c4:  ec 24 00 00  st  %l6, [ %l0 ]
a01067c8:  d6 06 62 a4  ld  [ %i1 + 0x2a4 ], %o3
a01067cc:  e8 02 c0 00  ld  [ %o3 ], %l4
a01067d0:  1f 00 1c 00  sethi  %hi(0x700000), %o7
a01067d4:  ba 0d 00 0f  and  %l4, %o7, %i5
a01067d8:  25 00 08 00  sethi  %hi(0x200000), %l2
a01067dc:  80 a7 40 12  cmp  %i5, %l2
a01067e0:  22 80 00 12  be,a   0xa0106828
a01067e4:  ea 0a e0 06  ldub  [ %o3 + 6 ], %l5
a01067e8:  13 33 c0 3b  sethi  %hi(0xcf00ec00), %o1
a01067ec:  82 12 61 80  or  %o1, 0x180, %g1	! 0xcf00ed80
a01067f0:  c0 20 40 00  clr  [ %g1 ]
a01067f4:  30 80 00 19  b,a   0xa0106858
a01067f8:  40 00 0f 27  call  0xa010a494
a01067fc:  33 2a 00 b5  sethi  %hi(0xa802d400), %i1
a0106800:  40 00 10 3c  call  0xa010a8f0
a0106804:  aa 10 00 08  mov  %o0, %l5
a0106808:  10 bf ff 69  b  0xa01065ac
a010680c:  de 06 62 a4  ld  [ %i1 + 0x2a4 ], %o7
a0106810:  40 00 10 38  call  0xa010a8f0
a0106814:  01 00 00 00  nop
a0106818:  40 00 10 36  call  0xa010a8f0
a010681c:  ae 10 00 08  mov  %o0, %l7
a0106820:  10 bf fe c4  b  0xa0106330
a0106824:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a0106828:  90 05 7f f8  add  %l5, -8, %o0
a010682c:  b2 0a 20 ff  and  %o0, 0xff, %i1
a0106830:  80 a6 60 02  cmp  %i1, 2
a0106834:  18 bf ff ee  bgu  0xa01067ec
a0106838:  13 33 c0 3b  sethi  %hi(0xcf00ec00), %o1
a010683c:  a4 14 21 80  or  %l0, 0x180, %l2
a0106840:  90 10 20 04  mov  4, %o0
a0106844:  92 10 20 8d  mov  0x8d, %o1
a0106848:  7f ff ae 94  call  0xa00f2298
a010684c:  94 10 20 08  mov  8, %o2
a0106850:  a0 10 20 10  mov  0x10, %l0
a0106854:  e0 24 80 00  st  %l0, [ %l2 ]
a0106858:  81 c7 e0 08  ret
a010685c:  81 e8 00 00  restore
