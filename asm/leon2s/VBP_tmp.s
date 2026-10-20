# leon2s VBP_tmp 0xa00a53b0-0xa00a5cb4 (2308 bytes)
a00a53b0:  9d e3 bf 90  save  %sp, -112, %sp
a00a53b4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a53b8:  82 04 00 10  add  %l0, %l0, %g1
a00a53bc:  82 00 40 10  add  %g1, %l0, %g1
a00a53c0:  23 2a 01 f7  sethi  %hi(0xa807dc00), %l1
a00a53c4:  9a 14 60 04  or  %l1, 4, %o5	! 0xa807dc04
a00a53c8:  83 28 60 02  sll  %g1, 2, %g1
a00a53cc:  d2 16 60 14  lduh  [ %i1 + 0x14 ], %o1
a00a53d0:  82 00 40 0d  add  %g1, %o5, %g1
a00a53d4:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a53d8:  17 00 00 0f  sethi  %hi(0x3c00), %o3
a00a53dc:  d4 00 60 08  ld  [ %g1 + 8 ], %o2
a00a53e0:  96 12 e3 ff  or  %o3, 0x3ff, %o3
a00a53e4:  9b 32 60 13  srl  %o1, 0x13, %o5
a00a53e8:  d8 02 a0 1c  ld  [ %o2 + 0x1c ], %o4
a00a53ec:  9a 0b 40 0b  and  %o5, %o3, %o5
a00a53f0:  03 0f ff c0  sethi  %hi(0x3fff0000), %g1
a00a53f4:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00a53f8:  82 2b 00 01  andn  %o4, %g1, %g1
a00a53fc:  82 10 40 0d  or  %g1, %o5, %g1
a00a5400:  c2 22 a0 1c  st  %g1, [ %o2 + 0x1c ]
a00a5404:  c2 02 a0 1c  ld  [ %o2 + 0x1c ], %g1
a00a5408:  1b 3f ff f0  sethi  %hi(0xffffc000), %o5
a00a540c:  82 08 40 0d  and  %g1, %o5, %g1
a00a5410:  82 10 40 0b  or  %g1, %o3, %g1
a00a5414:  c2 22 a0 1c  st  %g1, [ %o2 + 0x1c ]
a00a5418:  80 8e a0 ff  btst  0xff, %i2
a00a541c:  91 32 60 10  srl  %o1, 0x10, %o0
a00a5420:  12 80 00 24  bne  0xa00a54b0
a00a5424:  a4 10 20 05  mov  5, %l2
a00a5428:  d2 16 60 4a  lduh  [ %i1 + 0x4a ], %o1
a00a542c:  7f ff ff cc  call  0xa00a535c
a00a5430:  d4 16 60 48  lduh  [ %i1 + 0x48 ], %o2
a00a5434:  b4 10 00 08  mov  %o0, %i2
a00a5438:  e4 16 60 4c  lduh  [ %i1 + 0x4c ], %l2
a00a543c:  11 28 01 b0  sethi  %hi(0xa006c000), %o0
a00a5440:  92 10 00 12  mov  %l2, %o1
a00a5444:  7f ff 37 00  call  0xa0073044
a00a5448:  90 12 20 90  or  %o0, 0x90, %o0
a00a544c:  c2 16 60 10  lduh  [ %i1 + 0x10 ], %g1
a00a5450:  da 16 60 24  lduh  [ %i1 + 0x24 ], %o5
a00a5454:  82 20 40 0d  sub  %g1, %o5, %g1
a00a5458:  92 20 40 12  sub  %g1, %l2, %o1
a00a545c:  80 a2 60 04  cmp  %o1, 4
a00a5460:  38 80 00 0d  bgu,a   0xa00a5494
a00a5464:  13 04 18 93  sethi  %hi(0x10624c00), %o1
a00a5468:  03 28 01 b0  sethi  %hi(0xa006c000), %g1
a00a546c:  80 a2 60 04  cmp  %o1, 4
a00a5470:  02 80 00 04  be  0xa00a5480
a00a5474:  94 10 60 a8  or  %g1, 0xa8, %o2
a00a5478:  03 28 01 b0  sethi  %hi(0xa006c000), %g1
a00a547c:  94 10 60 b8  or  %g1, 0xb8, %o2	! 0xa006c0b8
a00a5480:  11 28 01 b0  sethi  %hi(0xa006c000), %o0
a00a5484:  90 12 20 c8  or  %o0, 0xc8, %o0	! 0xa006c0c8
a00a5488:  7f ff 36 ef  call  0xa0073044
a00a548c:  96 10 20 04  mov  4, %o3
a00a5490:  13 04 18 93  sethi  %hi(0x10624c00), %o1
a00a5494:  92 12 61 d3  or  %o1, 0x1d3, %o1	! 0x10624dd3
a00a5498:  80 56 80 09  umul  %i2, %o1, %g0
a00a549c:  93 40 00 00  rd  %y, %o1
a00a54a0:  93 2a 60 0a  sll  %o1, 0xa, %o1
a00a54a4:  93 32 60 10  srl  %o1, 0x10, %o1
a00a54a8:  7f ff fe 87  call  0xa00a4ec4
a00a54ac:  90 10 20 00  clr  %o0
a00a54b0:  82 04 00 10  add  %l0, %l0, %g1
a00a54b4:  82 00 40 10  add  %g1, %l0, %g1
a00a54b8:  9a 14 60 04  or  %l1, 4, %o5
a00a54bc:  83 28 60 02  sll  %g1, 2, %g1
a00a54c0:  82 00 40 0d  add  %g1, %o5, %g1
a00a54c4:  17 00 00 0f  sethi  %hi(0x3c00), %o3
a00a54c8:  d4 00 60 08  ld  [ %g1 + 8 ], %o2
a00a54cc:  96 12 e3 ff  or  %o3, 0x3ff, %o3
a00a54d0:  da 16 40 00  lduh  [ %i1 ], %o5
a00a54d4:  d8 02 a0 10  ld  [ %o2 + 0x10 ], %o4
a00a54d8:  9a 0b 40 0b  and  %o5, %o3, %o5
a00a54dc:  03 0f ff c0  sethi  %hi(0x3fff0000), %g1
a00a54e0:  82 2b 00 01  andn  %o4, %g1, %g1
a00a54e4:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00a54e8:  82 10 40 0d  or  %g1, %o5, %g1
a00a54ec:  c2 22 a0 10  st  %g1, [ %o2 + 0x10 ]
a00a54f0:  c2 02 a0 10  ld  [ %o2 + 0x10 ], %g1
a00a54f4:  19 3f ff f0  sethi  %hi(0xffffc000), %o4
a00a54f8:  da 16 60 02  lduh  [ %i1 + 2 ], %o5
a00a54fc:  82 08 40 0c  and  %g1, %o4, %g1
a00a5500:  9a 0b 40 0b  and  %o5, %o3, %o5
a00a5504:  82 10 40 0d  or  %g1, %o5, %g1
a00a5508:  c2 22 a0 10  st  %g1, [ %o2 + 0x10 ]
a00a550c:  da 0e 60 04  ldub  [ %i1 + 4 ], %o5
a00a5510:  d8 02 a0 14  ld  [ %o2 + 0x14 ], %o4
a00a5514:  9a 0b 60 07  and  %o5, 7, %o5
a00a5518:  03 1c 00 00  sethi  %hi(0x70000000), %g1
a00a551c:  82 2b 00 01  andn  %o4, %g1, %g1
a00a5520:  9b 2b 60 1c  sll  %o5, 0x1c, %o5
a00a5524:  82 10 40 0d  or  %g1, %o5, %g1
a00a5528:  c2 22 a0 14  st  %g1, [ %o2 + 0x14 ]
a00a552c:  d8 02 a0 14  ld  [ %o2 + 0x14 ], %o4
a00a5530:  da 0e 60 05  ldub  [ %i1 + 5 ], %o5
a00a5534:  03 01 c0 00  sethi  %hi(0x7000000), %g1
a00a5538:  82 2b 00 01  andn  %o4, %g1, %g1
a00a553c:  9b 2b 60 18  sll  %o5, 0x18, %o5
a00a5540:  82 10 40 0d  or  %g1, %o5, %g1
a00a5544:  c2 22 a0 14  st  %g1, [ %o2 + 0x14 ]
a00a5548:  d8 02 a0 14  ld  [ %o2 + 0x14 ], %o4
a00a554c:  da 0e 60 06  ldub  [ %i1 + 6 ], %o5
a00a5550:  03 00 3f c0  sethi  %hi(0xff0000), %g1
a00a5554:  82 2b 00 01  andn  %o4, %g1, %g1
a00a5558:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00a555c:  82 10 40 0d  or  %g1, %o5, %g1
a00a5560:  c2 22 a0 14  st  %g1, [ %o2 + 0x14 ]
a00a5564:  c2 0e 60 07  ldub  [ %i1 + 7 ], %g1
a00a5568:  80 a0 60 00  cmp  %g1, 0
a00a556c:  22 80 00 05  be,a   0xa00a5580
a00a5570:  82 10 28 00  mov  0x800, %g1
a00a5574:  c2 02 a0 14  ld  [ %o2 + 0x14 ], %g1
a00a5578:  10 80 00 06  b  0xa00a5590
a00a557c:  82 10 68 00  or  %g1, 0x800, %g1
a00a5580:  c2 27 bf f4  st  %g1, [ %fp + -12 ]
a00a5584:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a5588:  da 02 a0 14  ld  [ %o2 + 0x14 ], %o5
a00a558c:  82 2b 40 01  andn  %o5, %g1, %g1
a00a5590:  c2 22 a0 14  st  %g1, [ %o2 + 0x14 ]
a00a5594:  c2 0e 60 08  ldub  [ %i1 + 8 ], %g1
a00a5598:  80 a0 60 00  cmp  %g1, 0
a00a559c:  02 80 00 0c  be  0xa00a55cc
a00a55a0:  82 04 00 10  add  %l0, %l0, %g1
a00a55a4:  82 00 40 10  add  %g1, %l0, %g1
a00a55a8:  9a 14 60 04  or  %l1, 4, %o5
a00a55ac:  83 28 60 02  sll  %g1, 2, %g1
a00a55b0:  82 00 40 0d  add  %g1, %o5, %g1
a00a55b4:  da 00 60 08  ld  [ %g1 + 8 ], %o5
a00a55b8:  c2 03 60 14  ld  [ %o5 + 0x14 ], %g1
a00a55bc:  82 10 64 00  or  %g1, 0x400, %g1
a00a55c0:  c2 23 60 14  st  %g1, [ %o5 + 0x14 ]
a00a55c4:  10 80 00 0e  b  0xa00a55fc
a00a55c8:  c2 0e 60 09  ldub  [ %i1 + 9 ], %g1
a00a55cc:  82 00 40 10  add  %g1, %l0, %g1
a00a55d0:  98 14 60 04  or  %l1, 4, %o4
a00a55d4:  83 28 60 02  sll  %g1, 2, %g1
a00a55d8:  9a 10 24 00  mov  0x400, %o5
a00a55dc:  82 00 40 0c  add  %g1, %o4, %g1
a00a55e0:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a00a55e4:  d8 00 60 08  ld  [ %g1 + 8 ], %o4
a00a55e8:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a55ec:  da 03 20 14  ld  [ %o4 + 0x14 ], %o5
a00a55f0:  82 2b 40 01  andn  %o5, %g1, %g1
a00a55f4:  c2 23 20 14  st  %g1, [ %o4 + 0x14 ]
a00a55f8:  c2 0e 60 09  ldub  [ %i1 + 9 ], %g1
a00a55fc:  80 a0 60 00  cmp  %g1, 0
a00a5600:  19 2a 01 f7  sethi  %hi(0xa807dc00), %o4
a00a5604:  02 80 00 0d  be  0xa00a5638
a00a5608:  96 0e 20 ff  and  %i0, 0xff, %o3
a00a560c:  82 02 c0 0b  add  %o3, %o3, %g1
a00a5610:  82 00 40 0b  add  %g1, %o3, %g1
a00a5614:  9a 13 20 04  or  %o4, 4, %o5
a00a5618:  83 28 60 02  sll  %g1, 2, %g1
a00a561c:  82 00 40 0d  add  %g1, %o5, %g1
a00a5620:  da 00 60 08  ld  [ %g1 + 8 ], %o5
a00a5624:  c2 03 60 14  ld  [ %o5 + 0x14 ], %g1
a00a5628:  82 10 61 00  or  %g1, 0x100, %g1
a00a562c:  c2 23 60 14  st  %g1, [ %o5 + 0x14 ]
a00a5630:  10 80 00 0f  b  0xa00a566c
a00a5634:  c2 0e 60 0a  ldub  [ %i1 + 0xa ], %g1
a00a5638:  82 02 c0 0b  add  %o3, %o3, %g1
a00a563c:  82 00 40 0b  add  %g1, %o3, %g1
a00a5640:  98 13 20 04  or  %o4, 4, %o4
a00a5644:  83 28 60 02  sll  %g1, 2, %g1
a00a5648:  9a 10 21 00  mov  0x100, %o5
a00a564c:  82 00 40 0c  add  %g1, %o4, %g1
a00a5650:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a00a5654:  d8 00 60 08  ld  [ %g1 + 8 ], %o4
a00a5658:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a565c:  da 03 20 14  ld  [ %o4 + 0x14 ], %o5
a00a5660:  82 2b 40 01  andn  %o5, %g1, %g1
a00a5664:  c2 23 20 14  st  %g1, [ %o4 + 0x14 ]
a00a5668:  c2 0e 60 0a  ldub  [ %i1 + 0xa ], %g1
a00a566c:  80 a0 60 00  cmp  %g1, 0
a00a5670:  19 2a 01 f7  sethi  %hi(0xa807dc00), %o4
a00a5674:  02 80 00 0d  be  0xa00a56a8
a00a5678:  96 0e 20 ff  and  %i0, 0xff, %o3
a00a567c:  82 02 c0 0b  add  %o3, %o3, %g1
a00a5680:  82 00 40 0b  add  %g1, %o3, %g1
a00a5684:  9a 13 20 04  or  %o4, 4, %o5
a00a5688:  83 28 60 02  sll  %g1, 2, %g1
a00a568c:  82 00 40 0d  add  %g1, %o5, %g1
a00a5690:  da 00 60 08  ld  [ %g1 + 8 ], %o5
a00a5694:  c2 03 60 14  ld  [ %o5 + 0x14 ], %g1
a00a5698:  82 10 60 80  or  %g1, 0x80, %g1
a00a569c:  c2 23 60 14  st  %g1, [ %o5 + 0x14 ]
a00a56a0:  10 80 00 0f  b  0xa00a56dc
a00a56a4:  c2 0e 60 0b  ldub  [ %i1 + 0xb ], %g1
a00a56a8:  82 02 c0 0b  add  %o3, %o3, %g1
a00a56ac:  82 00 40 0b  add  %g1, %o3, %g1
a00a56b0:  98 13 20 04  or  %o4, 4, %o4
a00a56b4:  83 28 60 02  sll  %g1, 2, %g1
a00a56b8:  9a 10 20 80  mov  0x80, %o5
a00a56bc:  82 00 40 0c  add  %g1, %o4, %g1
a00a56c0:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a00a56c4:  d8 00 60 08  ld  [ %g1 + 8 ], %o4
a00a56c8:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a56cc:  da 03 20 14  ld  [ %o4 + 0x14 ], %o5
a00a56d0:  82 2b 40 01  andn  %o5, %g1, %g1
a00a56d4:  c2 23 20 14  st  %g1, [ %o4 + 0x14 ]
a00a56d8:  c2 0e 60 0b  ldub  [ %i1 + 0xb ], %g1
a00a56dc:  80 a0 60 00  cmp  %g1, 0
a00a56e0:  19 2a 01 f7  sethi  %hi(0xa807dc00), %o4
a00a56e4:  02 80 00 0d  be  0xa00a5718
a00a56e8:  96 0e 20 ff  and  %i0, 0xff, %o3
a00a56ec:  82 02 c0 0b  add  %o3, %o3, %g1
a00a56f0:  82 00 40 0b  add  %g1, %o3, %g1
a00a56f4:  9a 13 20 04  or  %o4, 4, %o5
a00a56f8:  83 28 60 02  sll  %g1, 2, %g1
a00a56fc:  82 00 40 0d  add  %g1, %o5, %g1
a00a5700:  da 00 60 08  ld  [ %g1 + 8 ], %o5
a00a5704:  c2 03 60 14  ld  [ %o5 + 0x14 ], %g1
a00a5708:  82 10 60 40  or  %g1, 0x40, %g1
a00a570c:  c2 23 60 14  st  %g1, [ %o5 + 0x14 ]
a00a5710:  10 80 00 0f  b  0xa00a574c
a00a5714:  c2 0e 60 0c  ldub  [ %i1 + 0xc ], %g1
a00a5718:  82 02 c0 0b  add  %o3, %o3, %g1
a00a571c:  82 00 40 0b  add  %g1, %o3, %g1
a00a5720:  98 13 20 04  or  %o4, 4, %o4
a00a5724:  83 28 60 02  sll  %g1, 2, %g1
a00a5728:  9a 10 20 40  mov  0x40, %o5
a00a572c:  82 00 40 0c  add  %g1, %o4, %g1
a00a5730:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a00a5734:  d8 00 60 08  ld  [ %g1 + 8 ], %o4
a00a5738:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a573c:  da 03 20 14  ld  [ %o4 + 0x14 ], %o5
a00a5740:  82 2b 40 01  andn  %o5, %g1, %g1
a00a5744:  c2 23 20 14  st  %g1, [ %o4 + 0x14 ]
a00a5748:  c2 0e 60 0c  ldub  [ %i1 + 0xc ], %g1
a00a574c:  80 a0 60 00  cmp  %g1, 0
a00a5750:  19 2a 01 f7  sethi  %hi(0xa807dc00), %o4
a00a5754:  02 80 00 10  be  0xa00a5794
a00a5758:  96 0e 20 ff  and  %i0, 0xff, %o3
a00a575c:  82 02 c0 0b  add  %o3, %o3, %g1
a00a5760:  82 00 40 0b  add  %g1, %o3, %g1
a00a5764:  98 13 20 04  or  %o4, 4, %o4
a00a5768:  83 28 60 02  sll  %g1, 2, %g1
a00a576c:  9a 10 20 20  mov  0x20, %o5
a00a5770:  82 00 40 0c  add  %g1, %o4, %g1
a00a5774:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a00a5778:  d8 00 60 08  ld  [ %g1 + 8 ], %o4
a00a577c:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a5780:  da 03 20 14  ld  [ %o4 + 0x14 ], %o5
a00a5784:  82 2b 40 01  andn  %o5, %g1, %g1
a00a5788:  c2 23 20 14  st  %g1, [ %o4 + 0x14 ]
a00a578c:  10 80 00 0c  b  0xa00a57bc
a00a5790:  c2 0e 60 0d  ldub  [ %i1 + 0xd ], %g1
a00a5794:  82 02 c0 0b  add  %o3, %o3, %g1
a00a5798:  82 00 40 0b  add  %g1, %o3, %g1
a00a579c:  9a 13 20 04  or  %o4, 4, %o5
a00a57a0:  83 28 60 02  sll  %g1, 2, %g1
a00a57a4:  82 00 40 0d  add  %g1, %o5, %g1
a00a57a8:  da 00 60 08  ld  [ %g1 + 8 ], %o5
a00a57ac:  c2 03 60 14  ld  [ %o5 + 0x14 ], %g1
a00a57b0:  82 10 60 20  or  %g1, 0x20, %g1
a00a57b4:  c2 23 60 14  st  %g1, [ %o5 + 0x14 ]
a00a57b8:  c2 0e 60 0d  ldub  [ %i1 + 0xd ], %g1
a00a57bc:  80 a0 60 00  cmp  %g1, 0
a00a57c0:  19 2a 01 f7  sethi  %hi(0xa807dc00), %o4
a00a57c4:  02 80 00 0d  be  0xa00a57f8
a00a57c8:  96 0e 20 ff  and  %i0, 0xff, %o3
a00a57cc:  82 02 c0 0b  add  %o3, %o3, %g1
a00a57d0:  82 00 40 0b  add  %g1, %o3, %g1
a00a57d4:  9a 13 20 04  or  %o4, 4, %o5
a00a57d8:  83 28 60 02  sll  %g1, 2, %g1
a00a57dc:  82 00 40 0d  add  %g1, %o5, %g1
a00a57e0:  da 00 60 08  ld  [ %g1 + 8 ], %o5
a00a57e4:  c2 03 60 14  ld  [ %o5 + 0x14 ], %g1
a00a57e8:  82 10 60 10  or  %g1, 0x10, %g1
a00a57ec:  c2 23 60 14  st  %g1, [ %o5 + 0x14 ]
a00a57f0:  10 80 00 0f  b  0xa00a582c
a00a57f4:  c2 0e 60 0e  ldub  [ %i1 + 0xe ], %g1
a00a57f8:  82 02 c0 0b  add  %o3, %o3, %g1
a00a57fc:  82 00 40 0b  add  %g1, %o3, %g1
a00a5800:  98 13 20 04  or  %o4, 4, %o4
a00a5804:  83 28 60 02  sll  %g1, 2, %g1
a00a5808:  9a 10 20 10  mov  0x10, %o5
a00a580c:  82 00 40 0c  add  %g1, %o4, %g1
a00a5810:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a00a5814:  d8 00 60 08  ld  [ %g1 + 8 ], %o4
a00a5818:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a581c:  da 03 20 14  ld  [ %o4 + 0x14 ], %o5
a00a5820:  82 2b 40 01  andn  %o5, %g1, %g1
a00a5824:  c2 23 20 14  st  %g1, [ %o4 + 0x14 ]
a00a5828:  c2 0e 60 0e  ldub  [ %i1 + 0xe ], %g1
a00a582c:  ac 04 a0 04  add  %l2, 4, %l6
a00a5830:  80 a0 60 00  cmp  %g1, 0
a00a5834:  19 2a 01 f7  sethi  %hi(0xa807dc00), %o4
a00a5838:  96 0e 20 ff  and  %i0, 0xff, %o3
a00a583c:  ea 16 60 24  lduh  [ %i1 + 0x24 ], %l5
a00a5840:  d4 16 60 18  lduh  [ %i1 + 0x18 ], %o2
a00a5844:  d0 16 60 1a  lduh  [ %i1 + 0x1a ], %o0
a00a5848:  f4 16 60 38  lduh  [ %i1 + 0x38 ], %i2
a00a584c:  a4 04 a0 03  add  %l2, 3, %l2
a00a5850:  e6 16 60 20  lduh  [ %i1 + 0x20 ], %l3
a00a5854:  02 80 00 0d  be  0xa00a5888
a00a5858:  e8 16 60 22  lduh  [ %i1 + 0x22 ], %l4
a00a585c:  82 02 c0 0b  add  %o3, %o3, %g1
a00a5860:  82 00 40 0b  add  %g1, %o3, %g1
a00a5864:  9a 13 20 04  or  %o4, 4, %o5
a00a5868:  83 28 60 02  sll  %g1, 2, %g1
a00a586c:  82 00 40 0d  add  %g1, %o5, %g1
a00a5870:  da 00 60 08  ld  [ %g1 + 8 ], %o5
a00a5874:  c2 03 60 14  ld  [ %o5 + 0x14 ], %g1
a00a5878:  82 10 60 08  or  %g1, 8, %g1
a00a587c:  c2 23 60 14  st  %g1, [ %o5 + 0x14 ]
a00a5880:  10 80 00 0f  b  0xa00a58bc
a00a5884:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a5888:  82 02 c0 0b  add  %o3, %o3, %g1
a00a588c:  82 00 40 0b  add  %g1, %o3, %g1
a00a5890:  98 13 20 04  or  %o4, 4, %o4
a00a5894:  83 28 60 02  sll  %g1, 2, %g1
a00a5898:  9a 10 20 08  mov  8, %o5
a00a589c:  82 00 40 0c  add  %g1, %o4, %g1
a00a58a0:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a00a58a4:  d8 00 60 08  ld  [ %g1 + 8 ], %o4
a00a58a8:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a58ac:  da 03 20 14  ld  [ %o4 + 0x14 ], %o5
a00a58b0:  82 2b 40 01  andn  %o5, %g1, %g1
a00a58b4:  c2 23 20 14  st  %g1, [ %o4 + 0x14 ]
a00a58b8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a58bc:  82 04 00 10  add  %l0, %l0, %g1
a00a58c0:  82 00 40 10  add  %g1, %l0, %g1
a00a58c4:  23 2a 01 f7  sethi  %hi(0xa807dc00), %l1
a00a58c8:  9a 14 60 04  or  %l1, 4, %o5	! 0xa807dc04
a00a58cc:  83 28 60 02  sll  %g1, 2, %g1
a00a58d0:  82 00 40 0d  add  %g1, %o5, %g1
a00a58d4:  de 00 60 08  ld  [ %g1 + 8 ], %o7
a00a58d8:  da 03 e0 14  ld  [ %o7 + 0x14 ], %o5
a00a58dc:  c2 0e 60 0f  ldub  [ %i1 + 0xf ], %g1
a00a58e0:  82 08 60 03  and  %g1, 3, %g1
a00a58e4:  9a 0b 7f fc  and  %o5, -4, %o5
a00a58e8:  9a 13 40 01  or  %o5, %g1, %o5
a00a58ec:  da 23 e0 14  st  %o5, [ %o7 + 0x14 ]
a00a58f0:  13 30 00 3f  sethi  %hi(0xc000fc00), %o1
a00a58f4:  c2 03 e0 18  ld  [ %o7 + 0x18 ], %g1
a00a58f8:  92 12 63 ff  or  %o1, 0x3ff, %o1
a00a58fc:  1b 0f ff c0  sethi  %hi(0x3fff0000), %o5
a00a5900:  82 08 40 09  and  %g1, %o1, %g1
a00a5904:  82 10 40 0d  or  %g1, %o5, %g1
a00a5908:  c2 23 e0 18  st  %g1, [ %o7 + 0x18 ]
a00a590c:  03 3f ff c0  sethi  %hi(0xffff0000), %g1
a00a5910:  da 03 e0 18  ld  [ %o7 + 0x18 ], %o5
a00a5914:  d8 0e 60 12  ldub  [ %i1 + 0x12 ], %o4
a00a5918:  82 10 60 ff  or  %g1, 0xff, %g1
a00a591c:  9a 0b 40 01  and  %o5, %g1, %o5
a00a5920:  99 2b 20 08  sll  %o4, 8, %o4
a00a5924:  9a 13 40 0c  or  %o5, %o4, %o5
a00a5928:  da 23 e0 18  st  %o5, [ %o7 + 0x18 ]
a00a592c:  c2 0e 60 13  ldub  [ %i1 + 0x13 ], %g1
a00a5930:  d8 03 e0 18  ld  [ %o7 + 0x18 ], %o4
a00a5934:  82 08 60 03  and  %g1, 3, %g1
a00a5938:  83 28 60 04  sll  %g1, 4, %g1
a00a593c:  98 0b 3f cf  and  %o4, -49, %o4
a00a5940:  98 13 00 01  or  %o4, %g1, %o4
a00a5944:  9b 2a a0 10  sll  %o2, 0x10, %o5
a00a5948:  17 00 00 0f  sethi  %hi(0x3c00), %o3
a00a594c:  d8 23 e0 18  st  %o4, [ %o7 + 0x18 ]
a00a5950:  96 12 e3 ff  or  %o3, 0x3ff, %o3
a00a5954:  9b 33 60 13  srl  %o5, 0x13, %o5
a00a5958:  c2 03 e0 20  ld  [ %o7 + 0x20 ], %g1
a00a595c:  9a 0b 40 0b  and  %o5, %o3, %o5
a00a5960:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00a5964:  82 08 40 09  and  %g1, %o1, %g1
a00a5968:  82 10 40 0d  or  %g1, %o5, %g1
a00a596c:  c2 23 e0 20  st  %g1, [ %o7 + 0x20 ]
a00a5970:  c2 03 e0 20  ld  [ %o7 + 0x20 ], %g1
a00a5974:  15 3f ff f0  sethi  %hi(0xffffc000), %o2
a00a5978:  9a 0a c0 08  and  %o3, %o0, %o5
a00a597c:  82 08 40 0a  and  %g1, %o2, %g1
a00a5980:  82 10 40 0d  or  %g1, %o5, %g1
a00a5984:  c2 23 e0 20  st  %g1, [ %o7 + 0x20 ]
a00a5988:  c2 03 e0 24  ld  [ %o7 + 0x24 ], %g1
a00a598c:  90 0a c0 1a  and  %o3, %i2, %o0
a00a5990:  82 08 40 0a  and  %g1, %o2, %g1
a00a5994:  82 10 40 08  or  %g1, %o0, %g1
a00a5998:  c2 23 e0 24  st  %g1, [ %o7 + 0x24 ]
a00a599c:  c2 03 e0 24  ld  [ %o7 + 0x24 ], %g1
a00a59a0:  9a 0c 80 0b  and  %l2, %o3, %o5
a00a59a4:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00a59a8:  82 08 40 09  and  %g1, %o1, %g1
a00a59ac:  82 10 40 0d  or  %g1, %o5, %g1
a00a59b0:  c2 23 e0 24  st  %g1, [ %o7 + 0x24 ]
a00a59b4:  9b 2c e0 10  sll  %l3, 0x10, %o5
a00a59b8:  c2 03 e0 28  ld  [ %o7 + 0x28 ], %g1
a00a59bc:  9b 33 60 13  srl  %o5, 0x13, %o5
a00a59c0:  9a 0b 40 0b  and  %o5, %o3, %o5
a00a59c4:  82 08 40 0a  and  %g1, %o2, %g1
a00a59c8:  82 10 40 0d  or  %g1, %o5, %g1
a00a59cc:  c2 23 e0 28  st  %g1, [ %o7 + 0x28 ]
a00a59d0:  d8 03 e0 2c  ld  [ %o7 + 0x2c ], %o4
a00a59d4:  9a 0d 2f ff  and  %l4, 0xfff, %o5
a00a59d8:  03 03 ff c0  sethi  %hi(0xfff0000), %g1
a00a59dc:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00a59e0:  82 2b 00 01  andn  %o4, %g1, %g1
a00a59e4:  82 10 40 0d  or  %g1, %o5, %g1
a00a59e8:  c2 23 e0 2c  st  %g1, [ %o7 + 0x2c ]
a00a59ec:  c2 03 e0 2c  ld  [ %o7 + 0x2c ], %g1
a00a59f0:  9a 0a c0 15  and  %o3, %l5, %o5
a00a59f4:  82 08 40 0a  and  %g1, %o2, %g1
a00a59f8:  82 10 40 0d  or  %g1, %o5, %g1
a00a59fc:  c2 23 e0 2c  st  %g1, [ %o7 + 0x2c ]
a00a5a00:  c2 03 e0 40  ld  [ %o7 + 0x40 ], %g1
a00a5a04:  82 08 40 0a  and  %g1, %o2, %g1
a00a5a08:  82 10 40 08  or  %g1, %o0, %g1
a00a5a0c:  c2 23 e0 40  st  %g1, [ %o7 + 0x40 ]
a00a5a10:  c2 03 e0 40  ld  [ %o7 + 0x40 ], %g1
a00a5a14:  96 0d 80 0b  and  %l6, %o3, %o3
a00a5a18:  82 08 40 09  and  %g1, %o1, %g1
a00a5a1c:  97 2a e0 10  sll  %o3, 0x10, %o3
a00a5a20:  82 10 40 0b  or  %g1, %o3, %g1
a00a5a24:  c2 23 e0 40  st  %g1, [ %o7 + 0x40 ]
a00a5a28:  c2 0e 60 3a  ldub  [ %i1 + 0x3a ], %g1
a00a5a2c:  80 a0 60 00  cmp  %g1, 0
a00a5a30:  22 80 00 05  be,a   0xa00a5a44
a00a5a34:  82 10 20 40  mov  0x40, %g1
a00a5a38:  c2 03 e0 44  ld  [ %o7 + 0x44 ], %g1
a00a5a3c:  10 80 00 06  b  0xa00a5a54
a00a5a40:  82 10 60 40  or  %g1, 0x40, %g1
a00a5a44:  c2 27 bf f4  st  %g1, [ %fp + -12 ]
a00a5a48:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a5a4c:  da 03 e0 44  ld  [ %o7 + 0x44 ], %o5
a00a5a50:  82 2b 40 01  andn  %o5, %g1, %g1
a00a5a54:  c2 23 e0 44  st  %g1, [ %o7 + 0x44 ]
a00a5a58:  c2 0e 60 3b  ldub  [ %i1 + 0x3b ], %g1
a00a5a5c:  80 a0 60 00  cmp  %g1, 0
a00a5a60:  02 80 00 0c  be  0xa00a5a90
a00a5a64:  82 04 00 10  add  %l0, %l0, %g1
a00a5a68:  82 00 40 10  add  %g1, %l0, %g1
a00a5a6c:  9a 14 60 04  or  %l1, 4, %o5
a00a5a70:  83 28 60 02  sll  %g1, 2, %g1
a00a5a74:  82 00 40 0d  add  %g1, %o5, %g1
a00a5a78:  da 00 60 08  ld  [ %g1 + 8 ], %o5
a00a5a7c:  c2 03 60 44  ld  [ %o5 + 0x44 ], %g1
a00a5a80:  82 10 60 20  or  %g1, 0x20, %g1
a00a5a84:  c2 23 60 44  st  %g1, [ %o5 + 0x44 ]
a00a5a88:  10 80 00 0e  b  0xa00a5ac0
a00a5a8c:  c2 0e 60 3c  ldub  [ %i1 + 0x3c ], %g1
a00a5a90:  82 00 40 10  add  %g1, %l0, %g1
a00a5a94:  98 14 60 04  or  %l1, 4, %o4
a00a5a98:  83 28 60 02  sll  %g1, 2, %g1
a00a5a9c:  9a 10 20 20  mov  0x20, %o5
a00a5aa0:  82 00 40 0c  add  %g1, %o4, %g1
a00a5aa4:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a00a5aa8:  d8 00 60 08  ld  [ %g1 + 8 ], %o4
a00a5aac:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a5ab0:  da 03 20 44  ld  [ %o4 + 0x44 ], %o5
a00a5ab4:  82 2b 40 01  andn  %o5, %g1, %g1
a00a5ab8:  c2 23 20 44  st  %g1, [ %o4 + 0x44 ]
a00a5abc:  c2 0e 60 3c  ldub  [ %i1 + 0x3c ], %g1
a00a5ac0:  80 a0 60 00  cmp  %g1, 0
a00a5ac4:  19 2a 01 f7  sethi  %hi(0xa807dc00), %o4
a00a5ac8:  02 80 00 0d  be  0xa00a5afc
a00a5acc:  96 0e 20 ff  and  %i0, 0xff, %o3
a00a5ad0:  82 02 c0 0b  add  %o3, %o3, %g1
a00a5ad4:  82 00 40 0b  add  %g1, %o3, %g1
a00a5ad8:  9a 13 20 04  or  %o4, 4, %o5
a00a5adc:  83 28 60 02  sll  %g1, 2, %g1
a00a5ae0:  82 00 40 0d  add  %g1, %o5, %g1
a00a5ae4:  da 00 60 08  ld  [ %g1 + 8 ], %o5
a00a5ae8:  c2 03 60 44  ld  [ %o5 + 0x44 ], %g1
a00a5aec:  82 10 60 10  or  %g1, 0x10, %g1
a00a5af0:  c2 23 60 44  st  %g1, [ %o5 + 0x44 ]
a00a5af4:  10 80 00 0f  b  0xa00a5b30
a00a5af8:  c2 0e 60 3d  ldub  [ %i1 + 0x3d ], %g1
a00a5afc:  82 02 c0 0b  add  %o3, %o3, %g1
a00a5b00:  82 00 40 0b  add  %g1, %o3, %g1
a00a5b04:  98 13 20 04  or  %o4, 4, %o4
a00a5b08:  83 28 60 02  sll  %g1, 2, %g1
a00a5b0c:  9a 10 20 10  mov  0x10, %o5
a00a5b10:  82 00 40 0c  add  %g1, %o4, %g1
a00a5b14:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a00a5b18:  d8 00 60 08  ld  [ %g1 + 8 ], %o4
a00a5b1c:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a5b20:  da 03 20 44  ld  [ %o4 + 0x44 ], %o5
a00a5b24:  82 2b 40 01  andn  %o5, %g1, %g1
a00a5b28:  c2 23 20 44  st  %g1, [ %o4 + 0x44 ]
a00a5b2c:  c2 0e 60 3d  ldub  [ %i1 + 0x3d ], %g1
a00a5b30:  80 a0 60 00  cmp  %g1, 0
a00a5b34:  19 2a 01 f7  sethi  %hi(0xa807dc00), %o4
a00a5b38:  02 80 00 0d  be  0xa00a5b6c
a00a5b3c:  96 0e 20 ff  and  %i0, 0xff, %o3
a00a5b40:  82 02 c0 0b  add  %o3, %o3, %g1
a00a5b44:  82 00 40 0b  add  %g1, %o3, %g1
a00a5b48:  9a 13 20 04  or  %o4, 4, %o5
a00a5b4c:  83 28 60 02  sll  %g1, 2, %g1
a00a5b50:  82 00 40 0d  add  %g1, %o5, %g1
a00a5b54:  da 00 60 08  ld  [ %g1 + 8 ], %o5
a00a5b58:  c2 03 60 44  ld  [ %o5 + 0x44 ], %g1
a00a5b5c:  82 10 60 08  or  %g1, 8, %g1
a00a5b60:  c2 23 60 44  st  %g1, [ %o5 + 0x44 ]
a00a5b64:  10 80 00 0f  b  0xa00a5ba0
a00a5b68:  c2 0e 60 3e  ldub  [ %i1 + 0x3e ], %g1
a00a5b6c:  82 02 c0 0b  add  %o3, %o3, %g1
a00a5b70:  82 00 40 0b  add  %g1, %o3, %g1
a00a5b74:  98 13 20 04  or  %o4, 4, %o4
a00a5b78:  83 28 60 02  sll  %g1, 2, %g1
a00a5b7c:  9a 10 20 08  mov  8, %o5
a00a5b80:  82 00 40 0c  add  %g1, %o4, %g1
a00a5b84:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a00a5b88:  d8 00 60 08  ld  [ %g1 + 8 ], %o4
a00a5b8c:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a5b90:  da 03 20 44  ld  [ %o4 + 0x44 ], %o5
a00a5b94:  82 2b 40 01  andn  %o5, %g1, %g1
a00a5b98:  c2 23 20 44  st  %g1, [ %o4 + 0x44 ]
a00a5b9c:  c2 0e 60 3e  ldub  [ %i1 + 0x3e ], %g1
a00a5ba0:  80 a0 60 00  cmp  %g1, 0
a00a5ba4:  19 2a 01 f7  sethi  %hi(0xa807dc00), %o4
a00a5ba8:  02 80 00 0d  be  0xa00a5bdc
a00a5bac:  96 0e 20 ff  and  %i0, 0xff, %o3
a00a5bb0:  82 02 c0 0b  add  %o3, %o3, %g1
a00a5bb4:  82 00 40 0b  add  %g1, %o3, %g1
a00a5bb8:  9a 13 20 04  or  %o4, 4, %o5
a00a5bbc:  83 28 60 02  sll  %g1, 2, %g1
a00a5bc0:  82 00 40 0d  add  %g1, %o5, %g1
a00a5bc4:  da 00 60 08  ld  [ %g1 + 8 ], %o5
a00a5bc8:  c2 03 60 44  ld  [ %o5 + 0x44 ], %g1
a00a5bcc:  82 10 60 04  or  %g1, 4, %g1
a00a5bd0:  c2 23 60 44  st  %g1, [ %o5 + 0x44 ]
a00a5bd4:  10 80 00 0f  b  0xa00a5c10
a00a5bd8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a5bdc:  82 02 c0 0b  add  %o3, %o3, %g1
a00a5be0:  82 00 40 0b  add  %g1, %o3, %g1
a00a5be4:  98 13 20 04  or  %o4, 4, %o4
a00a5be8:  83 28 60 02  sll  %g1, 2, %g1
a00a5bec:  9a 10 20 04  mov  4, %o5
a00a5bf0:  82 00 40 0c  add  %g1, %o4, %g1
a00a5bf4:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a00a5bf8:  d8 00 60 08  ld  [ %g1 + 8 ], %o4
a00a5bfc:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a5c00:  da 03 20 44  ld  [ %o4 + 0x44 ], %o5
a00a5c04:  82 2b 40 01  andn  %o5, %g1, %g1
a00a5c08:  c2 23 20 44  st  %g1, [ %o4 + 0x44 ]
a00a5c0c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a5c10:  82 06 00 18  add  %i0, %i0, %g1
a00a5c14:  82 00 40 18  add  %g1, %i0, %g1
a00a5c18:  17 2a 01 f7  sethi  %hi(0xa807dc00), %o3
a00a5c1c:  9a 12 e0 04  or  %o3, 4, %o5	! 0xa807dc04
a00a5c20:  83 28 60 02  sll  %g1, 2, %g1
a00a5c24:  82 00 40 0d  add  %g1, %o5, %g1
a00a5c28:  d8 00 60 08  ld  [ %g1 + 8 ], %o4
a00a5c2c:  da 03 20 44  ld  [ %o4 + 0x44 ], %o5
a00a5c30:  c2 0e 60 3f  ldub  [ %i1 + 0x3f ], %g1
a00a5c34:  82 08 60 03  and  %g1, 3, %g1
a00a5c38:  9a 0b 7f fc  and  %o5, -4, %o5
a00a5c3c:  9a 13 40 01  or  %o5, %g1, %o5
a00a5c40:  da 23 20 44  st  %o5, [ %o4 + 0x44 ]
a00a5c44:  c2 0e 60 40  ldub  [ %i1 + 0x40 ], %g1
a00a5c48:  80 a0 60 00  cmp  %g1, 0
a00a5c4c:  22 80 00 06  be,a   0xa00a5c64
a00a5c50:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00a5c54:  c2 03 20 48  ld  [ %o4 + 0x48 ], %g1
a00a5c58:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a00a5c5c:  10 80 00 06  b  0xa00a5c74
a00a5c60:  82 10 40 0d  or  %g1, %o5, %g1
a00a5c64:  c2 27 bf f4  st  %g1, [ %fp + -12 ]
a00a5c68:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a5c6c:  da 03 20 48  ld  [ %o4 + 0x48 ], %o5
a00a5c70:  82 2b 40 01  andn  %o5, %g1, %g1
a00a5c74:  c2 23 20 48  st  %g1, [ %o4 + 0x48 ]
a00a5c78:  82 06 00 18  add  %i0, %i0, %g1
a00a5c7c:  82 00 40 18  add  %g1, %i0, %g1
a00a5c80:  9a 12 e0 04  or  %o3, 4, %o5
a00a5c84:  83 28 60 02  sll  %g1, 2, %g1
a00a5c88:  82 00 40 0d  add  %g1, %o5, %g1
a00a5c8c:  d6 00 60 08  ld  [ %g1 + 8 ], %o3
a00a5c90:  da 02 e0 48  ld  [ %o3 + 0x48 ], %o5
a00a5c94:  03 3f 80 00  sethi  %hi(0xfe000000), %g1
a00a5c98:  d8 06 60 44  ld  [ %i1 + 0x44 ], %o4
a00a5c9c:  9a 0b 40 01  and  %o5, %g1, %o5
a00a5ca0:  82 2b 00 01  andn  %o4, %g1, %g1
a00a5ca4:  9a 13 40 01  or  %o5, %g1, %o5
a00a5ca8:  da 22 e0 48  st  %o5, [ %o3 + 0x48 ]
a00a5cac:  81 c7 e0 08  ret
a00a5cb0:  81 e8 00 00  restore
