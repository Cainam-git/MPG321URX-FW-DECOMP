# leon2m FUN_a013f370 0xa013f370-0xa013faa0 (1840 bytes)  [FUN_a013fa98 = unreachable ret/restore tail, merged]
a013f370:  9d e3 bf 90  save  %sp, -112, %sp
a013f374:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013f378:  7f ff f6 75  call  0xa013cd4c
a013f37c:  90 10 00 18  mov  %i0, %o0
a013f380:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a013f384:  82 14 22 24  or  %l0, 0x224, %g1	! 0xa802e224
a013f388:  9a 5e 20 2a  smul  %i0, 0x2a, %o5
a013f38c:  d8 10 40 0d  lduh  [ %g1 + %o5 ], %o4
a013f390:  80 8b 24 00  btst  0x400, %o4
a013f394:  02 80 00 ba  be  0xa013f67c
a013f398:  a6 10 00 08  mov  %o0, %l3
a013f39c:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a013f3a0:  94 10 20 01  mov  1, %o2
a013f3a4:  d2 08 63 d4  ldub  [ %g1 + 0x3d4 ], %o1
a013f3a8:  91 2a 80 18  sll  %o2, %i0, %o0
a013f3ac:  aa 14 22 24  or  %l0, 0x224, %l5
a013f3b0:  a8 5e 20 2a  smul  %i0, 0x2a, %l4
a013f3b4:  9a 12 00 09  or  %o0, %o1, %o5
a013f3b8:  e4 15 40 14  lduh  [ %l5 + %l4 ], %l2
a013f3bc:  80 8c a0 80  btst  0x80, %l2
a013f3c0:  02 80 00 ba  be  0xa013f6a8
a013f3c4:  da 28 63 d4  stb  %o5, [ %g1 + 0x3d4 ]
a013f3c8:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a013f3cc:  b2 10 20 01  mov  1, %i1
a013f3d0:  ee 08 63 d3  ldub  [ %g1 + 0x3d3 ], %l7
a013f3d4:  ad 2e 40 18  sll  %i1, %i0, %l6
a013f3d8:  9a 15 80 17  or  %l6, %l7, %o5
a013f3dc:  da 28 63 d3  stb  %o5, [ %g1 + 0x3d3 ]
a013f3e0:  7f ff 88 82  call  0xa01215e8
a013f3e4:  90 10 00 18  mov  %i0, %o0
a013f3e8:  40 00 0e a9  call  0xa0142e8c
a013f3ec:  90 10 00 18  mov  %i0, %o0
a013f3f0:  ba 0a 20 ff  and  %o0, 0xff, %i5
a013f3f4:  80 a7 60 05  cmp  %i5, 5
a013f3f8:  02 80 00 bb  be  0xa013f6e4
a013f3fc:  aa 14 22 24  or  %l0, 0x224, %l5
a013f400:  2d 00 06 96  sethi  %hi(0x1a5800), %l6
a013f404:  98 15 a2 16  or  %l6, 0x216, %o4	! 0x1a5a16
a013f408:  11 00 00 3f  sethi  %hi(0xfc00), %o0
a013f40c:  a0 10 3f ff  mov  -1, %l0
a013f410:  da 13 20 02  lduh  [ %o4 + 2 ], %o5
a013f414:  82 12 23 ff  or  %o0, 0x3ff, %g1
a013f418:  e0 27 bf f4  st  %l0, [ %fp + -12 ]
a013f41c:  80 a3 40 01  cmp  %o5, %g1
a013f420:  b6 10 20 00  clr  %i3
a013f424:  b4 10 20 00  clr  %i2
a013f428:  b2 10 3f ff  mov  -1, %i1
a013f42c:  fa 0c e0 0c  ldub  [ %l3 + 0xc ], %i5
a013f430:  ae 10 20 00  clr  %l7
a013f434:  02 80 01 12  be  0xa013f87c
a013f438:  a4 10 20 00  clr  %l2
a013f43c:  9a 10 00 0c  mov  %o4, %o5
a013f440:  19 00 06 96  sethi  %hi(0x1a5800), %o4
a013f444:  a2 13 21 e2  or  %o4, 0x1e2, %l1	! 0x1a59e2
a013f448:  a0 10 20 00  clr  %l0
a013f44c:  b8 10 00 0d  mov  %o5, %i4
a013f450:  a8 10 00 0d  mov  %o5, %l4
a013f454:  9f 2c 20 03  sll  %l0, 3, %o7
a013f458:  96 03 c0 10  add  %o7, %l0, %o3
a013f45c:  93 2a e0 02  sll  %o3, 2, %o1
a013f460:  94 02 40 0d  add  %o1, %o5, %o2
a013f464:  d2 12 a0 22  lduh  [ %o2 + 0x22 ], %o1
a013f468:  94 10 20 00  clr  %o2
a013f46c:  10 80 00 05  b  0xa013f480
a013f470:  98 10 20 00  clr  %o4
a013f474:  80 a3 20 0c  cmp  %o4, 0xc
a013f478:  18 80 00 f2  bgu  0xa013f840
a013f47c:  82 10 20 00  clr  %g1
a013f480:  83 2b 20 02  sll  %o4, 2, %g1
a013f484:  94 02 a0 01  inc  %o2
a013f488:  ea 0c 40 01  ldub  [ %l1 + %g1 ], %l5
a013f48c:  96 00 40 11  add  %g1, %l1, %o3
a013f490:  80 a5 60 0c  cmp  %l5, 0xc
a013f494:  12 bf ff f8  bne  0xa013f474
a013f498:  98 0a a0 ff  and  %o2, 0xff, %o4
a013f49c:  da 12 e0 02  lduh  [ %o3 + 2 ], %o5
a013f4a0:  80 a3 40 09  cmp  %o5, %o1
a013f4a4:  12 bf ff f5  bne  0xa013f478
a013f4a8:  80 a3 20 0c  cmp  %o4, 0xc
a013f4ac:  82 10 20 01  mov  1, %g1
a013f4b0:  80 a0 60 00  cmp  %g1, 0
a013f4b4:  32 80 00 e7  bne,a   0xa013f850
a013f4b8:  a4 04 a0 01  inc  %l2
a013f4bc:  7f ff 87 67  call  0xa0121258
a013f4c0:  90 10 00 18  mov  %i0, %o0
a013f4c4:  9f 2c 20 03  sll  %l0, 3, %o7
a013f4c8:  98 03 c0 10  add  %o7, %l0, %o4
a013f4cc:  97 2b 20 02  sll  %o4, 2, %o3
a013f4d0:  98 02 c0 1c  add  %o3, %i4, %o4
a013f4d4:  d2 13 20 22  lduh  [ %o4 + 0x22 ], %o1
a013f4d8:  90 0a 20 ff  and  %o0, 0xff, %o0
a013f4dc:  94 0a 60 01  and  %o1, 1, %o2
a013f4e0:  80 a2 00 0a  cmp  %o0, %o2
a013f4e4:  32 80 00 db  bne,a   0xa013f850
a013f4e8:  a4 04 a0 01  inc  %l2
a013f4ec:  da 14 e0 10  lduh  [ %l3 + 0x10 ], %o5
a013f4f0:  ea 13 20 10  lduh  [ %o4 + 0x10 ], %l5
a013f4f4:  80 a3 40 15  cmp  %o5, %l5
a013f4f8:  28 80 00 0e  bleu,a   0xa013f530
a013f4fc:  99 2c 20 03  sll  %l0, 3, %o4
a013f500:  d6 13 20 0c  lduh  [ %o4 + 0xc ], %o3
a013f504:  92 23 40 0b  sub  %o5, %o3, %o1
a013f508:  91 3a 60 1f  sra  %o1, 0x1f, %o0
a013f50c:  82 1a 00 09  xor  %o0, %o1, %g1
a013f510:  95 2e 60 10  sll  %i1, 0x10, %o2
a013f514:  82 20 40 08  sub  %g1, %o0, %g1
a013f518:  9b 32 a0 10  srl  %o2, 0x10, %o5
a013f51c:  80 a0 40 0d  cmp  %g1, %o5
a013f520:  16 80 00 04  bge  0xa013f530
a013f524:  99 2c 20 03  sll  %l0, 3, %o4
a013f528:  b2 10 00 01  mov  %g1, %i1
a013f52c:  b6 10 00 12  mov  %l2, %i3
a013f530:  96 03 00 10  add  %o4, %l0, %o3
a013f534:  93 2a e0 02  sll  %o3, 2, %o1
a013f538:  a0 02 40 1c  add  %o1, %i4, %l0
a013f53c:  d0 14 e0 06  lduh  [ %l3 + 6 ], %o0
a013f540:  c2 14 20 02  lduh  [ %l0 + 2 ], %g1
a013f544:  9a 22 00 01  sub  %o0, %g1, %o5
a013f548:  95 3b 60 1f  sra  %o5, 0x1f, %o2
a013f54c:  aa 1a 80 0d  xor  %o2, %o5, %l5
a013f550:  9e 25 40 0a  sub  %l5, %o2, %o7
a013f554:  d8 0c 20 1e  ldub  [ %l0 + 0x1e ], %o4
a013f558:  80 a3 c0 0c  cmp  %o7, %o4
a013f55c:  34 80 00 bd  bg,a   0xa013f850
a013f560:  a4 04 a0 01  inc  %l2
a013f564:  c2 14 e0 08  lduh  [ %l3 + 8 ], %g1
a013f568:  d2 14 20 04  lduh  [ %l0 + 4 ], %o1
a013f56c:  90 20 40 09  sub  %g1, %o1, %o0
a013f570:  9b 3a 20 1f  sra  %o0, 0x1f, %o5
a013f574:  94 1b 40 08  xor  %o5, %o0, %o2
a013f578:  aa 22 80 0d  sub  %o2, %o5, %l5
a013f57c:  de 0c 20 1f  ldub  [ %l0 + 0x1f ], %o7
a013f580:  80 a5 40 0f  cmp  %l5, %o7
a013f584:  34 80 00 b3  bg,a   0xa013f850
a013f588:  a4 04 a0 01  inc  %l2
a013f58c:  40 00 0e 40  call  0xa0142e8c
a013f590:  90 10 00 18  mov  %i0, %o0
a013f594:  96 0a 20 ff  and  %o0, 0xff, %o3
a013f598:  80 a2 e0 02  cmp  %o3, 2
a013f59c:  32 80 00 08  bne,a   0xa013f5bc
a013f5a0:  ea 14 e0 10  lduh  [ %l3 + 0x10 ], %l5
a013f5a4:  d8 0c e0 0a  ldub  [ %l3 + 0xa ], %o4
a013f5a8:  de 0c 20 06  ldub  [ %l0 + 6 ], %o7
a013f5ac:  80 8b c0 0c  btst  %o7, %o4
a013f5b0:  22 80 00 a8  be,a   0xa013f850
a013f5b4:  a4 04 a0 01  inc  %l2
a013f5b8:  ea 14 e0 10  lduh  [ %l3 + 0x10 ], %l5
a013f5bc:  7f ff 87 27  call  0xa0121258
a013f5c0:  90 10 00 18  mov  %i0, %o0
a013f5c4:  94 0a 20 ff  and  %o0, 0xff, %o2
a013f5c8:  80 a2 a0 01  cmp  %o2, 1
a013f5cc:  22 80 00 02  be,a   0xa013f5d4
a013f5d0:  aa 05 40 15  add  %l5, %l5, %l5
a013f5d4:  91 2d 60 10  sll  %l5, 0x10, %o0
a013f5d8:  ab 32 20 10  srl  %o0, 0x10, %l5
a013f5dc:  da 14 20 10  lduh  [ %l0 + 0x10 ], %o5
a013f5e0:  80 a3 40 15  cmp  %o5, %l5
a013f5e4:  3a 80 00 9b  bcc,a   0xa013f850
a013f5e8:  a4 04 a0 01  inc  %l2
a013f5ec:  d2 14 20 02  lduh  [ %l0 + 2 ], %o1
a013f5f0:  d0 14 20 04  lduh  [ %l0 + 4 ], %o0
a013f5f4:  da 14 e0 06  lduh  [ %l3 + 6 ], %o5
a013f5f8:  d6 14 e0 08  lduh  [ %l3 + 8 ], %o3
a013f5fc:  de 14 20 0c  lduh  [ %l0 + 0xc ], %o7
a013f600:  ae 23 40 09  sub  %o5, %o1, %l7
a013f604:  94 22 c0 08  sub  %o3, %o0, %o2
a013f608:  d8 14 e0 10  lduh  [ %l3 + 0x10 ], %o4
a013f60c:  93 3d e0 1f  sra  %l7, 0x1f, %o1
a013f610:  91 3a a0 1f  sra  %o2, 0x1f, %o0
a013f614:  aa 23 00 0f  sub  %o4, %o7, %l5
a013f618:  9f 3d 60 1f  sra  %l5, 0x1f, %o7
a013f61c:  96 1a 00 0a  xor  %o0, %o2, %o3
a013f620:  9a 1a 40 17  xor  %o1, %l7, %o5
a013f624:  c2 0c 20 08  ldub  [ %l0 + 8 ], %g1
a013f628:  98 1b c0 15  xor  %o7, %l5, %o4
a013f62c:  ae 22 c0 08  sub  %o3, %o0, %l7
a013f630:  a0 0f 60 ff  and  %i5, 0xff, %l0
a013f634:  aa 24 00 01  sub  %l0, %g1, %l5
a013f638:  9a 23 40 09  sub  %o5, %o1, %o5
a013f63c:  90 23 00 0f  sub  %o4, %o7, %o0
a013f640:  94 03 40 17  add  %o5, %l7, %o2
a013f644:  97 3d 60 1f  sra  %l5, 0x1f, %o3
a013f648:  99 2a 20 02  sll  %o0, 2, %o4
a013f64c:  82 1a c0 15  xor  %o3, %l5, %g1
a013f650:  9e 02 80 0c  add  %o2, %o4, %o7
a013f654:  a0 20 40 0b  sub  %g1, %o3, %l0
a013f658:  92 5b e0 64  smul  %o7, 0x64, %o1
a013f65c:  ee 07 bf f4  ld  [ %fp + -12 ], %l7
a013f660:  82 02 40 10  add  %o1, %l0, %g1
a013f664:  80 a0 40 17  cmp  %g1, %l7
a013f668:  1a 80 00 79  bcc  0xa013f84c
a013f66c:  ae 10 20 01  mov  1, %l7
a013f670:  c2 27 bf f4  st  %g1, [ %fp + -12 ]
a013f674:  10 80 00 76  b  0xa013f84c
a013f678:  b4 10 00 12  mov  %l2, %i2
a013f67c:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a013f680:  a2 10 20 01  mov  1, %l1
a013f684:  de 08 63 d4  ldub  [ %g1 + 0x3d4 ], %o7
a013f688:  97 2c 40 18  sll  %l1, %i0, %o3
a013f68c:  aa 14 22 24  or  %l0, 0x224, %l5
a013f690:  a8 5e 20 2a  smul  %i0, 0x2a, %l4
a013f694:  9a 2b c0 0b  andn  %o7, %o3, %o5
a013f698:  e4 15 40 14  lduh  [ %l5 + %l4 ], %l2
a013f69c:  80 8c a0 80  btst  0x80, %l2
a013f6a0:  12 bf ff 4a  bne  0xa013f3c8
a013f6a4:  da 28 63 d4  stb  %o5, [ %g1 + 0x3d4 ]
a013f6a8:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a013f6ac:  b8 10 20 01  mov  1, %i4
a013f6b0:  f6 08 63 d3  ldub  [ %g1 + 0x3d3 ], %i3
a013f6b4:  b5 2f 00 18  sll  %i4, %i0, %i2
a013f6b8:  9a 2e c0 1a  andn  %i3, %i2, %o5
a013f6bc:  da 28 63 d3  stb  %o5, [ %g1 + 0x3d3 ]
a013f6c0:  7f ff 87 ca  call  0xa01215e8
a013f6c4:  90 10 00 18  mov  %i0, %o0
a013f6c8:  40 00 0d f1  call  0xa0142e8c
a013f6cc:  90 10 00 18  mov  %i0, %o0
a013f6d0:  ba 0a 20 ff  and  %o0, 0xff, %i5
a013f6d4:  80 a7 60 05  cmp  %i5, 5
a013f6d8:  12 bf ff 4b  bne  0xa013f404
a013f6dc:  2d 00 06 96  sethi  %hi(0x1a5800), %l6
a013f6e0:  aa 14 22 24  or  %l0, 0x224, %l5
a013f6e4:  a0 5e 20 2a  smul  %i0, 0x2a, %l0
a013f6e8:  a2 04 00 15  add  %l0, %l5, %l1
a013f6ec:  90 10 00 18  mov  %i0, %o0
a013f6f0:  7f ff 86 da  call  0xa0121258
a013f6f4:  e0 14 60 18  lduh  [ %l1 + 0x18 ], %l0
a013f6f8:  80 8a 20 ff  btst  0xff, %o0
a013f6fc:  02 80 00 04  be  0xa013f70c
a013f700:  d8 14 60 16  lduh  [ %l1 + 0x16 ], %o4
a013f704:  95 2c 20 10  sll  %l0, 0x10, %o2
a013f708:  a1 32 a0 0f  srl  %o2, 0xf, %l0
a013f70c:  96 10 21 e0  mov  0x1e0, %o3
a013f710:  d6 34 e0 2c  sth  %o3, [ %l3 + 0x2c ]
a013f714:  d6 34 e0 1c  sth  %o3, [ %l3 + 0x1c ]
a013f718:  d6 34 e0 20  sth  %o3, [ %l3 + 0x20 ]
a013f71c:  ac 10 3f 00  mov  -256, %l6
a013f720:  29 00 06 96  sethi  %hi(0x1a5800), %l4
a013f724:  ec 34 e0 3c  sth  %l6, [ %l3 + 0x3c ]
a013f728:  d8 34 e0 16  sth  %o4, [ %l3 + 0x16 ]
a013f72c:  e0 34 e0 14  sth  %l0, [ %l3 + 0x14 ]
a013f730:  d8 34 e0 12  sth  %o4, [ %l3 + 0x12 ]
a013f734:  e0 34 e0 18  sth  %l0, [ %l3 + 0x18 ]
a013f738:  c0 34 e0 1a  clrh  [ %l3 + 0x1a ]
a013f73c:  c0 34 e0 1e  clrh  [ %l3 + 0x1e ]
a013f740:  c0 34 e0 2a  clrh  [ %l3 + 0x2a ]
a013f744:  96 15 22 16  or  %l4, 0x216, %o3
a013f748:  31 00 00 3f  sethi  %hi(0xfc00), %i0
a013f74c:  94 16 23 ff  or  %i0, 0x3ff, %o2	! 0xffff
a013f750:  e2 12 e0 02  lduh  [ %o3 + 2 ], %l1
a013f754:  80 a4 40 0a  cmp  %l1, %o2
a013f758:  02 80 00 cf  be  0xa013fa94
a013f75c:  92 10 20 00  clr  %o1
a013f760:  b3 2b 20 10  sll  %o4, 0x10, %i1
a013f764:  9e 10 00 0b  mov  %o3, %o7
a013f768:  99 2c 20 10  sll  %l0, 0x10, %o4
a013f76c:  91 36 60 10  srl  %i1, 0x10, %o0
a013f770:  a3 33 20 10  srl  %o4, 0x10, %l1
a013f774:  a4 10 00 0a  mov  %o2, %l2
a013f778:  96 10 20 00  clr  %o3
a013f77c:  10 80 00 06  b  0xa013f794
a013f780:  a0 10 00 0f  mov  %o7, %l0
a013f784:  d8 12 a0 02  lduh  [ %o2 + 2 ], %o4
a013f788:  80 a3 00 12  cmp  %o4, %l2
a013f78c:  02 80 00 c2  be  0xa013fa94
a013f790:  01 00 00 00  nop
a013f794:  95 2a e0 03  sll  %o3, 3, %o2
a013f798:  aa 02 80 0b  add  %o2, %o3, %l5
a013f79c:  92 02 60 01  inc  %o1
a013f7a0:  83 2d 60 02  sll  %l5, 2, %g1
a013f7a4:  96 0a 60 ff  and  %o1, 0xff, %o3
a013f7a8:  98 00 40 0f  add  %g1, %o7, %o4
a013f7ac:  9b 2a e0 03  sll  %o3, 3, %o5
a013f7b0:  f8 13 20 12  lduh  [ %o4 + 0x12 ], %i4
a013f7b4:  ae 03 40 0b  add  %o5, %o3, %l7
a013f7b8:  b6 22 00 1c  sub  %o0, %i4, %i3
a013f7bc:  bb 2d e0 02  sll  %l7, 2, %i5
a013f7c0:  b4 06 e0 05  add  %i3, 5, %i2
a013f7c4:  94 07 40 10  add  %i5, %l0, %o2
a013f7c8:  80 a6 a0 0a  cmp  %i2, 0xa
a013f7cc:  18 bf ff ee  bgu  0xa013f784
a013f7d0:  9e 10 00 10  mov  %l0, %o7
a013f7d4:  ec 13 20 14  lduh  [ %o4 + 0x14 ], %l6
a013f7d8:  a8 24 40 16  sub  %l1, %l6, %l4
a013f7dc:  b0 05 20 06  add  %l4, 6, %i0
a013f7e0:  80 a6 20 0c  cmp  %i0, 0xc
a013f7e4:  38 bf ff e9  bgu,a   0xa013f788
a013f7e8:  d8 12 a0 02  lduh  [ %o2 + 2 ], %o4
a013f7ec:  f6 14 e0 06  lduh  [ %l3 + 6 ], %i3
a013f7f0:  f8 13 20 02  lduh  [ %o4 + 2 ], %i4
a013f7f4:  b4 26 c0 1c  sub  %i3, %i4, %i2
a013f7f8:  b2 06 a0 09  add  %i2, 9, %i1
a013f7fc:  80 a6 60 12  cmp  %i1, 0x12
a013f800:  38 bf ff e2  bgu,a   0xa013f788
a013f804:  d8 12 a0 02  lduh  [ %o2 + 2 ], %o4
a013f808:  c2 14 e0 08  lduh  [ %l3 + 8 ], %g1
a013f80c:  da 13 20 04  lduh  [ %o4 + 4 ], %o5
a013f810:  ae 20 40 0d  sub  %g1, %o5, %l7
a013f814:  ba 05 e0 09  add  %l7, 9, %i5
a013f818:  80 a7 60 12  cmp  %i5, 0x12
a013f81c:  38 bf ff db  bgu,a   0xa013f788
a013f820:  d8 12 a0 02  lduh  [ %o2 + 2 ], %o4
a013f824:  e4 13 20 0e  lduh  [ %o4 + 0xe ], %l2
a013f828:  e4 34 e0 12  sth  %l2, [ %l3 + 0x12 ]
a013f82c:  c2 13 20 10  lduh  [ %o4 + 0x10 ], %g1
a013f830:  c2 34 e0 14  sth  %g1, [ %l3 + 0x14 ]
a013f834:  d2 13 20 22  lduh  [ %o4 + 0x22 ], %o1
a013f838:  10 80 00 97  b  0xa013fa94
a013f83c:  d2 34 e0 3c  sth  %o1, [ %l3 + 0x3c ]
a013f840:  80 a0 60 00  cmp  %g1, 0
a013f844:  02 bf ff 1e  be  0xa013f4bc
a013f848:  01 00 00 00  nop
a013f84c:  a4 04 a0 01  inc  %l2
a013f850:  a0 0c a0 ff  and  %l2, 0xff, %l0
a013f854:  91 2c 20 03  sll  %l0, 3, %o0
a013f858:  96 02 00 10  add  %o0, %l0, %o3
a013f85c:  9f 2a e0 02  sll  %o3, 2, %o7
a013f860:  98 03 c0 14  add  %o7, %l4, %o4
a013f864:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a013f868:  ea 13 20 02  lduh  [ %o4 + 2 ], %l5
a013f86c:  82 12 a3 ff  or  %o2, 0x3ff, %g1
a013f870:  80 a5 40 01  cmp  %l5, %g1
a013f874:  12 bf fe f8  bne  0xa013f454
a013f878:  9a 10 00 14  mov  %l4, %o5
a013f87c:  80 8d e0 ff  btst  0xff, %l7
a013f880:  12 80 00 45  bne  0xa013f994
a013f884:  01 00 00 00  nop
a013f888:  7f ff f5 31  call  0xa013cd4c
a013f88c:  90 10 00 18  mov  %i0, %o0
a013f890:  96 0e e0 ff  and  %i3, 0xff, %o3
a013f894:  95 2a e0 03  sll  %o3, 3, %o2
a013f898:  aa 02 80 0b  add  %o2, %o3, %l5
a013f89c:  94 15 a2 16  or  %l6, 0x216, %o2
a013f8a0:  97 2d 60 02  sll  %l5, 2, %o3
a013f8a4:  b8 02 c0 0a  add  %o3, %o2, %i4
a013f8a8:  e0 17 20 0e  lduh  [ %i4 + 0xe ], %l0
a013f8ac:  e0 32 20 12  sth  %l0, [ %o0 + 0x12 ]
a013f8b0:  e2 17 20 10  lduh  [ %i4 + 0x10 ], %l1
a013f8b4:  e2 32 20 14  sth  %l1, [ %o0 + 0x14 ]
a013f8b8:  e0 17 20 12  lduh  [ %i4 + 0x12 ], %l0
a013f8bc:  e0 32 20 16  sth  %l0, [ %o0 + 0x16 ]
a013f8c0:  e4 17 20 14  lduh  [ %i4 + 0x14 ], %l2
a013f8c4:  e4 32 20 18  sth  %l2, [ %o0 + 0x18 ]
a013f8c8:  e2 17 20 0a  lduh  [ %i4 + 0xa ], %l1
a013f8cc:  e2 32 20 0e  sth  %l1, [ %o0 + 0xe ]
a013f8d0:  e4 17 20 1a  lduh  [ %i4 + 0x1a ], %l2
a013f8d4:  e4 32 20 1e  sth  %l2, [ %o0 + 0x1e ]
a013f8d8:  c2 17 20 1c  lduh  [ %i4 + 0x1c ], %g1
a013f8dc:  c2 32 20 20  sth  %g1, [ %o0 + 0x20 ]
a013f8e0:  d2 17 20 16  lduh  [ %i4 + 0x16 ], %o1
a013f8e4:  d2 32 20 1a  sth  %o1, [ %o0 + 0x1a ]
a013f8e8:  da 17 20 18  lduh  [ %i4 + 0x18 ], %o5
a013f8ec:  da 32 20 1c  sth  %o5, [ %o0 + 0x1c ]
a013f8f0:  d2 17 20 0a  lduh  [ %i4 + 0xa ], %o1
a013f8f4:  d2 32 20 28  sth  %o1, [ %o0 + 0x28 ]
a013f8f8:  de 17 20 16  lduh  [ %i4 + 0x16 ], %o7
a013f8fc:  de 32 20 2a  sth  %o7, [ %o0 + 0x2a ]
a013f900:  ee 17 20 18  lduh  [ %i4 + 0x18 ], %l7
a013f904:  ba 10 20 20  mov  0x20, %i5
a013f908:  ee 32 20 2c  sth  %l7, [ %o0 + 0x2c ]
a013f90c:  fa 2a 20 26  stb  %i5, [ %o0 + 0x26 ]
a013f910:  c0 2a 20 3a  clrb  [ %o0 + 0x3a ]
a013f914:  f6 17 20 22  lduh  [ %i4 + 0x22 ], %i3
a013f918:  f6 32 20 3c  sth  %i3, [ %o0 + 0x3c ]
a013f91c:  c2 0a 80 0b  ldub  [ %o2 + %o3 ], %g1
a013f920:  80 a0 60 00  cmp  %g1, 0
a013f924:  22 80 00 12  be,a   0xa013f96c
a013f928:  da 14 e0 3c  lduh  [ %l3 + 0x3c ], %o5
a013f92c:  ae 08 60 ff  and  %g1, 0xff, %l7
a013f930:  ba 5c 00 17  smul  %l0, %l7, %i5
a013f934:  fa 32 20 16  sth  %i5, [ %o0 + 0x16 ]
a013f938:  f8 0a 80 0b  ldub  [ %o2 + %o3 ], %i4
a013f93c:  b6 5c 40 1c  smul  %l1, %i4, %i3
a013f940:  f6 32 20 0e  sth  %i3, [ %o0 + 0xe ]
a013f944:  f4 0a 80 0b  ldub  [ %o2 + %o3 ], %i2
a013f948:  b2 5c 80 1a  smul  %l2, %i2, %i1
a013f94c:  f2 32 20 1e  sth  %i1, [ %o0 + 0x1e ]
a013f950:  ec 0a 80 0b  ldub  [ %o2 + %o3 ], %l6
a013f954:  a8 5a 40 16  smul  %o1, %l6, %l4
a013f958:  e8 32 20 28  sth  %l4, [ %o0 + 0x28 ]
a013f95c:  f0 0a 80 0b  ldub  [ %o2 + %o3 ], %i0
a013f960:  98 5b c0 18  smul  %o7, %i0, %o4
a013f964:  d8 32 20 2a  sth  %o4, [ %o0 + 0x2a ]
a013f968:  da 14 e0 3c  lduh  [ %l3 + 0x3c ], %o5
a013f96c:  9f 33 60 08  srl  %o5, 8, %o7
a013f970:  90 13 ff 00  or  %o7, -256, %o0
a013f974:  d0 34 e0 3c  sth  %o0, [ %l3 + 0x3c ]
a013f978:  b0 04 e0 06  add  %l3, 6, %i0
a013f97c:  40 00 52 1c  call  0xa01541ec
a013f980:  90 10 00 18  mov  %i0, %o0
a013f984:  80 8a 20 ff  btst  0xff, %o0
a013f988:  12 80 00 43  bne  0xa013fa94
a013f98c:  01 00 00 00  nop
a013f990:  30 80 00 3f  b,a   0xa013fa8c
a013f994:  7f ff f4 ee  call  0xa013cd4c
a013f998:  90 10 00 18  mov  %i0, %o0
a013f99c:  9a 0e a0 ff  and  %i2, 0xff, %o5
a013f9a0:  af 2b 60 03  sll  %o5, 3, %l7
a013f9a4:  a0 05 c0 0d  add  %l7, %o5, %l0
a013f9a8:  94 15 a2 16  or  %l6, 0x216, %o2
a013f9ac:  97 2c 20 02  sll  %l0, 2, %o3
a013f9b0:  a8 02 c0 0a  add  %o3, %o2, %l4
a013f9b4:  fa 15 20 0e  lduh  [ %l4 + 0xe ], %i5
a013f9b8:  fa 32 20 12  sth  %i5, [ %o0 + 0x12 ]
a013f9bc:  f8 15 20 10  lduh  [ %l4 + 0x10 ], %i4
a013f9c0:  f8 32 20 14  sth  %i4, [ %o0 + 0x14 ]
a013f9c4:  de 15 20 12  lduh  [ %l4 + 0x12 ], %o7
a013f9c8:  de 32 20 16  sth  %o7, [ %o0 + 0x16 ]
a013f9cc:  e2 15 20 14  lduh  [ %l4 + 0x14 ], %l1
a013f9d0:  e2 32 20 18  sth  %l1, [ %o0 + 0x18 ]
a013f9d4:  e0 15 20 0a  lduh  [ %l4 + 0xa ], %l0
a013f9d8:  e0 32 20 0e  sth  %l0, [ %o0 + 0xe ]
a013f9dc:  e2 15 20 1a  lduh  [ %l4 + 0x1a ], %l1
a013f9e0:  e2 32 20 1e  sth  %l1, [ %o0 + 0x1e ]
a013f9e4:  f6 15 20 1c  lduh  [ %l4 + 0x1c ], %i3
a013f9e8:  f6 32 20 20  sth  %i3, [ %o0 + 0x20 ]
a013f9ec:  f4 15 20 16  lduh  [ %l4 + 0x16 ], %i2
a013f9f0:  f4 32 20 1a  sth  %i2, [ %o0 + 0x1a ]
a013f9f4:  e4 15 20 18  lduh  [ %l4 + 0x18 ], %l2
a013f9f8:  e4 32 20 1c  sth  %l2, [ %o0 + 0x1c ]
a013f9fc:  d2 15 20 0a  lduh  [ %l4 + 0xa ], %o1
a013fa00:  d2 32 20 28  sth  %o1, [ %o0 + 0x28 ]
a013fa04:  e4 15 20 16  lduh  [ %l4 + 0x16 ], %l2
a013fa08:  e4 32 20 2a  sth  %l2, [ %o0 + 0x2a ]
a013fa0c:  f2 15 20 18  lduh  [ %l4 + 0x18 ], %i1
a013fa10:  ac 10 20 20  mov  0x20, %l6
a013fa14:  f2 32 20 2c  sth  %i1, [ %o0 + 0x2c ]
a013fa18:  ec 2a 20 26  stb  %l6, [ %o0 + 0x26 ]
a013fa1c:  c0 2a 20 3a  clrb  [ %o0 + 0x3a ]
a013fa20:  f0 15 20 22  lduh  [ %l4 + 0x22 ], %i0
a013fa24:  f0 32 20 3c  sth  %i0, [ %o0 + 0x3c ]
a013fa28:  c2 0a 80 0b  ldub  [ %o2 + %o3 ], %g1
a013fa2c:  80 a0 60 00  cmp  %g1, 0
a013fa30:  02 80 00 12  be  0xa013fa78
a013fa34:  b0 04 e0 06  add  %l3, 6, %i0
a013fa38:  b4 08 60 ff  and  %g1, 0xff, %i2
a013fa3c:  b2 5b c0 1a  smul  %o7, %i2, %i1
a013fa40:  f2 32 20 16  sth  %i1, [ %o0 + 0x16 ]
a013fa44:  ec 0a 80 0b  ldub  [ %o2 + %o3 ], %l6
a013fa48:  a8 5c 00 16  smul  %l0, %l6, %l4
a013fa4c:  e8 32 20 0e  sth  %l4, [ %o0 + 0xe ]
a013fa50:  f0 0a 80 0b  ldub  [ %o2 + %o3 ], %i0
a013fa54:  9e 5c 40 18  smul  %l1, %i0, %o7
a013fa58:  de 32 20 1e  sth  %o7, [ %o0 + 0x1e ]
a013fa5c:  d8 0a 80 0b  ldub  [ %o2 + %o3 ], %o4
a013fa60:  aa 5a 40 0c  smul  %o1, %o4, %l5
a013fa64:  ea 32 20 28  sth  %l5, [ %o0 + 0x28 ]
a013fa68:  c2 0a 80 0b  ldub  [ %o2 + %o3 ], %g1
a013fa6c:  92 5c 80 01  smul  %l2, %g1, %o1
a013fa70:  d2 32 20 2a  sth  %o1, [ %o0 + 0x2a ]
a013fa74:  b0 04 e0 06  add  %l3, 6, %i0
a013fa78:  40 00 51 dd  call  0xa01541ec
a013fa7c:  90 10 00 18  mov  %i0, %o0
a013fa80:  80 8a 20 ff  btst  0xff, %o0
a013fa84:  12 80 00 04  bne  0xa013fa94
a013fa88:  01 00 00 00  nop
a013fa8c:  40 00 52 0e  call  0xa01542c4
a013fa90:  81 e8 00 00  restore
a013fa94:  01 00 00 00  nop
a013fa98:  81 c7 e0 08  ret
a013fa9c:  81 e8 00 00  restore
