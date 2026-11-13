# leon2m FUN_a01012a8 0xa01012a8-0xa01016a4 (1020 bytes)
a01012a8:  9d e3 bf 20  save  %sp, -224, %sp
a01012ac:  b2 0e 60 ff  and  %i1, 0xff, %i1
a01012b0:  7f ff f1 5c  call  0xa00fd820
a01012b4:  90 10 00 19  mov  %i1, %o0
a01012b8:  82 0a 20 ff  and  %o0, 0xff, %g1
a01012bc:  80 a0 60 b1  cmp  %g1, 0xb1
a01012c0:  02 80 00 b8  be  0xa01015a0
a01012c4:  01 00 00 00  nop
a01012c8:  13 2a 00 9e  sethi  %hi(0xa8027800), %o1
a01012cc:  d6 02 62 78  ld  [ %o1 + 0x278 ], %o3	! 0xa8027a78
a01012d0:  80 a2 e0 01  cmp  %o3, 1
a01012d4:  02 80 00 90  be  0xa0101514
a01012d8:  80 a2 e0 02  cmp  %o3, 2
a01012dc:  02 80 00 aa  be  0xa0101584
a01012e0:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a01012e4:  f6 08 62 74  ldub  [ %g1 + 0x274 ], %i3	! 0xa8027a74
a01012e8:  21 2a 00 9e  sethi  %hi(0xa8027800), %l0
a01012ec:  f6 2c 22 75  stb  %i3, [ %l0 + 0x275 ]	! 0xa8027a75
a01012f0:  80 a6 60 03  cmp  %i1, 3
a01012f4:  08 80 00 84  bleu  0xa0101504
a01012f8:  01 00 00 00  nop
a01012fc:  80 a6 60 04  cmp  %i1, 4
a0101300:  08 80 00 7d  bleu  0xa01014f4
a0101304:  01 00 00 00  nop
a0101308:  90 10 00 19  mov  %i1, %o0
a010130c:  92 10 20 f2  mov  0xf2, %o1
a0101310:  7f ff c1 f1  call  0xa00f1ad4
a0101314:  94 10 20 00  clr  %o2
a0101318:  90 10 00 19  mov  %i1, %o0
a010131c:  92 10 20 f3  mov  0xf3, %o1
a0101320:  7f ff c1 ed  call  0xa00f1ad4
a0101324:  94 10 20 00  clr  %o2
a0101328:  80 a6 60 00  cmp  %i1, 0
a010132c:  12 80 00 dc  bne  0xa010169c
a0101330:  d8 0c 22 75  ldub  [ %l0 + 0x275 ], %o4
a0101334:  90 03 3f de  add  %o4, -34, %o0
a0101338:  a2 0a 20 ff  and  %o0, 0xff, %l1
a010133c:  80 a4 60 06  cmp  %l1, 6
a0101340:  94 60 20 00  subx  %g0, 0, %o2
a0101344:  a0 1b 20 1c  xor  %o4, 0x1c, %l0
a0101348:  80 a0 00 10  cmp  %g0, %l0
a010134c:  92 0a a0 01  and  %o2, 1, %o1
a0101350:  b2 60 3f ff  subx  %g0, -1, %i1
a0101354:  80 92 40 19  orcc  %o1, %i1, %g0
a0101358:  12 80 00 0c  bne  0xa0101388
a010135c:  80 a3 20 1d  cmp  %o4, 0x1d
a0101360:  02 80 00 0a  be  0xa0101388
a0101364:  80 a3 20 1e  cmp  %o4, 0x1e
a0101368:  02 80 00 08  be  0xa0101388
a010136c:  80 a3 20 1f  cmp  %o4, 0x1f
a0101370:  02 80 00 06  be  0xa0101388
a0101374:  80 a3 20 20  cmp  %o4, 0x20
a0101378:  02 80 00 04  be  0xa0101388
a010137c:  80 a3 20 21  cmp  %o4, 0x21
a0101380:  12 80 00 c7  bne  0xa010169c
a0101384:  01 00 00 00  nop
a0101388:  21 00 06 69  sethi  %hi(0x19a400), %l0
a010138c:  92 14 21 da  or  %l0, 0x1da, %o1	! 0x19a5da
a0101390:  94 10 20 1e  mov  0x1e, %o2
a0101394:  40 00 ed 5f  call  0xa013c910
a0101398:  90 07 bf d8  add  %fp, -40, %o0
a010139c:  15 00 06 69  sethi  %hi(0x19a400), %o2
a01013a0:  92 12 a1 f8  or  %o2, 0x1f8, %o1	! 0x19a5f8
a01013a4:  94 10 20 1e  mov  0x1e, %o2
a01013a8:  40 00 ed 5a  call  0xa013c910
a01013ac:  90 07 bf b8  add  %fp, -72, %o0
a01013b0:  13 00 06 69  sethi  %hi(0x19a400), %o1
a01013b4:  92 12 62 16  or  %o1, 0x216, %o1	! 0x19a616
a01013b8:  94 10 20 1e  mov  0x1e, %o2
a01013bc:  40 00 ed 55  call  0xa013c910
a01013c0:  90 07 bf 98  add  %fp, -104, %o0
a01013c4:  33 00 00 11  sethi  %hi(0x4400), %i1
a01013c8:  37 00 00 05  sethi  %hi(0x1400), %i3
a01013cc:  17 00 00 10  sethi  %hi(0x4000), %o3
a01013d0:  19 00 00 04  sethi  %hi(0x1000), %o4
a01013d4:  82 16 62 33  or  %i1, 0x233, %g1
a01013d8:  9e 16 e3 99  or  %i3, 0x399, %o7
a01013dc:  9a 12 e1 66  or  %o3, 0x166, %o5
a01013e0:  c2 37 bf 86  sth  %g1, [ %fp + -122 ]
a01013e4:  de 37 bf 88  sth  %o7, [ %fp + -120 ]
a01013e8:  da 37 bf 8a  sth  %o5, [ %fp + -118 ]
a01013ec:  d8 37 bf 90  sth  %o4, [ %fp + -112 ]
a01013f0:  d8 37 bf 80  sth  %o4, [ %fp + -128 ]
a01013f4:  90 10 20 00  clr  %o0
a01013f8:  92 10 20 f2  mov  0xf2, %o1
a01013fc:  94 10 20 04  mov  4, %o2
a0101400:  96 10 20 00  clr  %o3
a0101404:  c0 37 bf 82  clrh  [ %fp + -126 ]
a0101408:  c0 37 bf 84  clrh  [ %fp + -124 ]
a010140c:  c0 37 bf 8c  clrh  [ %fp + -116 ]
a0101410:  7f ff c1 d3  call  0xa00f1b5c
a0101414:  c0 37 bf 8e  clrh  [ %fp + -114 ]
a0101418:  96 10 20 00  clr  %o3
a010141c:  90 10 20 00  clr  %o0
a0101420:  92 10 20 f2  mov  0xf2, %o1
a0101424:  7f ff c1 ce  call  0xa00f1b5c
a0101428:  94 10 20 08  mov  8, %o2
a010142c:  90 10 20 00  clr  %o0
a0101430:  92 10 20 f2  mov  0xf2, %o1
a0101434:  7f ff c1 a8  call  0xa00f1ad4
a0101438:  94 10 20 01  mov  1, %o2
a010143c:  90 10 20 00  clr  %o0
a0101440:  92 10 20 f3  mov  0xf3, %o1
a0101444:  7f ff c1 a4  call  0xa00f1ad4
a0101448:  94 10 20 01  mov  1, %o2
a010144c:  b2 10 20 00  clr  %i1
a0101450:  b6 10 20 00  clr  %i3
a0101454:  a2 07 bf f8  add  %fp, -8, %l1
a0101458:  94 10 00 1b  mov  %i3, %o2
a010145c:  90 10 20 00  clr  %o0
a0101460:  7f ff c1 9d  call  0xa00f1ad4
a0101464:  92 10 20 f4  mov  0xf4, %o1
a0101468:  9b 2e e0 02  sll  %i3, 2, %o5
a010146c:  98 03 40 1b  add  %o5, %i3, %o4
a0101470:  90 03 00 0c  add  %o4, %o4, %o0
a0101474:  b6 02 00 11  add  %o0, %l1, %i3
a0101478:  d4 16 ff e0  lduh  [ %i3 + -32 ], %o2
a010147c:  90 10 20 00  clr  %o0
a0101480:  7f ff c2 32  call  0xa00f1d48
a0101484:  92 10 20 f5  mov  0xf5, %o1
a0101488:  d4 16 ff e2  lduh  [ %i3 + -30 ], %o2
a010148c:  90 10 20 00  clr  %o0
a0101490:  7f ff c2 2e  call  0xa00f1d48
a0101494:  92 10 20 f7  mov  0xf7, %o1
a0101498:  d4 16 ff e4  lduh  [ %i3 + -28 ], %o2
a010149c:  90 10 20 00  clr  %o0
a01014a0:  7f ff c2 2a  call  0xa00f1d48
a01014a4:  92 10 20 f9  mov  0xf9, %o1
a01014a8:  d4 16 ff e6  lduh  [ %i3 + -26 ], %o2
a01014ac:  90 10 20 00  clr  %o0
a01014b0:  7f ff c2 26  call  0xa00f1d48
a01014b4:  92 10 20 fb  mov  0xfb, %o1
a01014b8:  d4 16 ff e8  lduh  [ %i3 + -24 ], %o2
a01014bc:  90 10 20 00  clr  %o0
a01014c0:  92 10 20 fd  mov  0xfd, %o1
a01014c4:  7f ff c2 21  call  0xa00f1d48
a01014c8:  b2 06 60 01  inc  %i1
a01014cc:  b6 0e 60 ff  and  %i1, 0xff, %i3
a01014d0:  80 a6 e0 02  cmp  %i3, 2
a01014d4:  08 bf ff e2  bleu  0xa010145c
a01014d8:  94 10 00 1b  mov  %i3, %o2
a01014dc:  90 10 20 00  clr  %o0
a01014e0:  92 10 20 f2  mov  0xf2, %o1
a01014e4:  94 10 20 04  mov  4, %o2
a01014e8:  7f ff c1 9d  call  0xa00f1b5c
a01014ec:  96 10 20 01  mov  1, %o3
a01014f0:  30 80 00 6b  b,a   0xa010169c
a01014f4:  7f ff fd 53  call  0xa0100a40
a01014f8:  90 10 00 19  mov  %i1, %o0
a01014fc:  10 bf ff 84  b  0xa010130c
a0101500:  90 10 00 19  mov  %i1, %o0
a0101504:  7f ff fc 78  call  0xa01006e4
a0101508:  90 10 00 19  mov  %i1, %o0
a010150c:  10 bf ff 7d  b  0xa0101300
a0101510:  80 a6 60 04  cmp  %i1, 4
a0101514:  90 0a 20 ff  and  %o0, 0xff, %o0
a0101518:  9e 1a 20 31  xor  %o0, 0x31, %o7
a010151c:  80 a0 00 0f  cmp  %g0, %o7
a0101520:  98 60 3f ff  subx  %g0, -1, %o4
a0101524:  94 1a 20 41  xor  %o0, 0x41, %o2
a0101528:  80 a0 00 0a  cmp  %g0, %o2
a010152c:  9a 60 3f ff  subx  %g0, -1, %o5
a0101530:  80 93 00 0d  orcc  %o4, %o5, %g0
a0101534:  12 80 00 19  bne  0xa0101598
a0101538:  21 2a 00 9e  sethi  %hi(0xa8027800), %l0
a010153c:  92 1a 20 51  xor  %o0, 0x51, %o1
a0101540:  80 a0 00 09  cmp  %g0, %o1
a0101544:  a2 60 3f ff  subx  %g0, -1, %l1
a0101548:  82 1a 20 61  xor  %o0, 0x61, %g1
a010154c:  80 a0 00 01  cmp  %g0, %g1
a0101550:  a0 60 3f ff  subx  %g0, -1, %l0
a0101554:  80 94 40 10  orcc  %l1, %l0, %g0
a0101558:  32 80 00 10  bne,a   0xa0101598
a010155c:  21 2a 00 9e  sethi  %hi(0xa8027800), %l0
a0101560:  80 a2 20 21  cmp  %o0, 0x21
a0101564:  02 80 00 13  be  0xa01015b0
a0101568:  80 a2 20 71  cmp  %o0, 0x71
a010156c:  02 80 00 0a  be  0xa0101594
a0101570:  80 a2 20 81  cmp  %o0, 0x81
a0101574:  02 80 00 09  be  0xa0101598
a0101578:  21 2a 00 9e  sethi  %hi(0xa8027800), %l0
a010157c:  10 bf ff 5d  b  0xa01012f0
a0101580:  d6 2c 22 75  stb  %o3, [ %l0 + 0x275 ]	! 0xa8027a75
a0101584:  21 2a 00 9e  sethi  %hi(0xa8027800), %l0
a0101588:  82 10 20 01  mov  1, %g1
a010158c:  10 bf ff 59  b  0xa01012f0
a0101590:  c2 2c 22 75  stb  %g1, [ %l0 + 0x275 ]
a0101594:  21 2a 00 9e  sethi  %hi(0xa8027800), %l0
a0101598:  10 bf ff 56  b  0xa01012f0
a010159c:  f6 2c 22 75  stb  %i3, [ %l0 + 0x275 ]	! 0xa8027a75
a01015a0:  7f ff f4 4a  call  0xa00fe6c8
a01015a4:  01 00 00 00  nop
a01015a8:  10 bf ff 49  b  0xa01012cc
a01015ac:  13 2a 00 9e  sethi  %hi(0xa8027800), %o1
a01015b0:  7f ff de 09  call  0xa00f8dd4
a01015b4:  90 10 00 19  mov  %i1, %o0
a01015b8:  96 10 00 08  mov  %o0, %o3
a01015bc:  a1 2a e0 10  sll  %o3, 0x10, %l0
a01015c0:  7f ff de 0c  call  0xa00f8df0
a01015c4:  90 10 00 19  mov  %i1, %o0
a01015c8:  97 34 20 10  srl  %l0, 0x10, %o3
a01015cc:  a3 2a 20 10  sll  %o0, 0x10, %l1
a01015d0:  98 1a e7 80  xor  %o3, 0x780, %o4
a01015d4:  80 a0 00 0c  cmp  %g0, %o4
a01015d8:  95 34 60 10  srl  %l1, 0x10, %o2
a01015dc:  b6 60 3f ff  subx  %g0, -1, %i3
a01015e0:  9a 1a a4 38  xor  %o2, 0x438, %o5
a01015e4:  80 a0 00 0d  cmp  %g0, %o5
a01015e8:  90 60 3f ff  subx  %g0, -1, %o0
a01015ec:  80 8e c0 08  btst  %i3, %o0
a01015f0:  12 80 00 0c  bne  0xa0101620
a01015f4:  92 1a e5 00  xor  %o3, 0x500, %o1
a01015f8:  80 a0 00 09  cmp  %g0, %o1
a01015fc:  b6 60 3f ff  subx  %g0, -1, %i3
a0101600:  82 1a a2 d0  xor  %o2, 0x2d0, %g1
a0101604:  80 a0 00 01  cmp  %g0, %g1
a0101608:  9e 60 3f ff  subx  %g0, -1, %o7
a010160c:  90 10 00 19  mov  %i1, %o0
a0101610:  92 10 20 01  mov  1, %o1
a0101614:  80 8e c0 0f  btst  %i3, %o7
a0101618:  02 80 00 05  be  0xa010162c
a010161c:  94 10 20 01  mov  1, %o2
a0101620:  90 10 00 19  mov  %i1, %o0
a0101624:  92 10 20 01  mov  1, %o1
a0101628:  94 10 20 24  mov  0x24, %o2
a010162c:  7f ff c1 2a  call  0xa00f1ad4
a0101630:  01 00 00 00  nop
a0101634:  67 fe 2e db  call  0x4008d1a0
a0101638:  90 10 20 14  mov  0x14, %o0	! 0x14
a010163c:  97 34 20 10  srl  %l0, 0x10, %o3
a0101640:  90 1a e7 80  xor  %o3, 0x780, %o0
a0101644:  80 a0 00 08  cmp  %g0, %o0
a0101648:  91 34 60 10  srl  %l1, 0x10, %o0
a010164c:  a0 60 3f ff  subx  %g0, -1, %l0
a0101650:  a2 1a 24 38  xor  %o0, 0x438, %l1
a0101654:  80 a0 00 11  cmp  %g0, %l1
a0101658:  94 60 3f ff  subx  %g0, -1, %o2
a010165c:  80 8c 00 0a  btst  %l0, %o2
a0101660:  12 80 00 0c  bne  0xa0101690
a0101664:  21 2a 00 9e  sethi  %hi(0xa8027800), %l0
a0101668:  9e 1a e5 00  xor  %o3, 0x500, %o7
a010166c:  80 a0 00 0f  cmp  %g0, %o7
a0101670:  98 60 3f ff  subx  %g0, -1, %o4
a0101674:  96 1a 22 d0  xor  %o0, 0x2d0, %o3
a0101678:  80 a0 00 0b  cmp  %g0, %o3
a010167c:  9a 60 3f ff  subx  %g0, -1, %o5
a0101680:  80 8b 00 0d  btst  %o4, %o5
a0101684:  02 bf ff c2  be  0xa010158c
a0101688:  82 10 20 03  mov  3, %g1
a010168c:  21 2a 00 9e  sethi  %hi(0xa8027800), %l0
a0101690:  82 10 20 09  mov  9, %g1
a0101694:  10 bf ff 17  b  0xa01012f0
a0101698:  c2 2c 22 75  stb  %g1, [ %l0 + 0x275 ]
a010169c:  81 c7 e0 08  ret
a01016a0:  81 e8 00 00  restore
