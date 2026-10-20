# leon2m FUN_a012f43c 0xa012f43c-0xa012f7a8 (848 bytes)
a012f43c:  9d e3 bf 98  save  %sp, -104, %sp
a012f440:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012f444:  80 a6 20 03  cmp  %i0, 3
a012f448:  18 80 00 0a  bgu  0xa012f470
a012f44c:  98 10 3f ff  mov  -1, %o4
a012f450:  97 2e 20 04  sll  %i0, 4, %o3
a012f454:  94 22 c0 18  sub  %o3, %i0, %o2
a012f458:  13 2a 00 b7  sethi  %hi(0xa802dc00), %o1
a012f45c:  83 2a a0 03  sll  %o2, 3, %g1
a012f460:  9a 12 63 30  or  %o1, 0x330, %o5
a012f464:  d0 03 40 01  ld  [ %o5 + %g1 ], %o0
a012f468:  99 32 20 0c  srl  %o0, 0xc, %o4
a012f46c:  98 0b 20 0f  and  %o4, 0xf, %o4
a012f470:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a012f474:  c2 0b e1 a7  ldub  [ %o7 + 0x1a7 ], %g1	! 0xa802e1a7
a012f478:  90 10 00 0c  mov  %o4, %o0
a012f47c:  80 a0 60 07  cmp  %g1, 7
a012f480:  18 80 00 09  bgu  0xa012f4a4
a012f484:  94 10 20 01  mov  1, %o2
a012f488:  1b 00 03 3c  sethi  %hi(0xcf000), %o5
a012f48c:  a3 28 60 02  sll  %g1, 2, %l1
a012f490:  98 13 61 6c  or  %o5, 0x16c, %o4
a012f494:  e0 03 00 11  ld  [ %o4 + %l1 ], %l0
a012f498:  81 c4 00 00  jmp  %l0
a012f49c:  01 00 00 00  nop
a012f4a0:  94 10 20 03  mov  3, %o2	! 0x3
a012f4a4:  a0 0a a0 07  and  %o2, 7, %l0
a012f4a8:  80 a4 20 01  cmp  %l0, 1
a012f4ac:  02 80 00 27  be  0xa012f548
a012f4b0:  80 a6 20 00  cmp  %i0, 0
a012f4b4:  a0 0a 20 ff  and  %o0, 0xff, %l0
a012f4b8:  80 a4 20 07  cmp  %l0, 7
a012f4bc:  18 80 00 b9  bgu  0xa012f7a0
a012f4c0:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a012f4c4:  9e 5c 20 2a  smul  %l0, 0x2a, %o7
a012f4c8:  98 13 62 24  or  %o5, 0x224, %o4
a012f4cc:  96 03 c0 0c  add  %o7, %o4, %o3
a012f4d0:  d4 0a e0 0a  ldub  [ %o3 + 0xa ], %o2
a012f4d4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a012f4d8:  92 1a 80 19  xor  %o2, %i1, %o1
a012f4dc:  80 a0 00 09  cmp  %g0, %o1
a012f4e0:  90 40 20 00  addx  %g0, 0, %o0
a012f4e4:  b4 0e a0 ff  and  %i2, 0xff, %i2
a012f4e8:  80 a0 00 1a  cmp  %g0, %i2
a012f4ec:  a2 40 20 00  addx  %g0, 0, %l1
a012f4f0:  80 92 00 11  orcc  %o0, %l1, %g0
a012f4f4:  12 80 00 55  bne  0xa012f648
a012f4f8:  80 a6 20 03  cmp  %i0, 3
a012f4fc:  18 80 00 a9  bgu  0xa012f7a0
a012f500:  80 a6 60 61  cmp  %i1, 0x61
a012f504:  02 80 00 6e  be  0xa012f6bc
a012f508:  80 a6 60 61  cmp  %i1, 0x61
a012f50c:  04 80 00 3e  ble  0xa012f604
a012f510:  80 a6 60 51  cmp  %i1, 0x51
a012f514:  80 a6 60 71  cmp  %i1, 0x71
a012f518:  02 80 00 82  be  0xa012f720
a012f51c:  80 a6 60 81  cmp  %i1, 0x81
a012f520:  02 80 00 89  be  0xa012f744
a012f524:  9b 2e 20 04  sll  %i0, 4, %o5
a012f528:  83 2e 20 04  sll  %i0, 4, %g1
a012f52c:  a2 20 40 18  sub  %g1, %i0, %l1
a012f530:  35 2a 00 b7  sethi  %hi(0xa802dc00), %i2
a012f534:  99 2c 60 03  sll  %l1, 3, %o4
a012f538:  9a 16 a3 30  or  %i2, 0x330, %o5
a012f53c:  9e 03 00 0d  add  %o4, %o5, %o7
a012f540:  10 80 00 98  b  0xa012f7a0
a012f544:  c0 2b e0 76  clrb  [ %o7 + 0x76 ]
a012f548:  32 bf ff dc  bne,a   0xa012f4b8
a012f54c:  a0 0a 20 ff  and  %o0, 0xff, %l0
a012f550:  a2 0a 20 ff  and  %o0, 0xff, %l1
a012f554:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a012f558:  9e 5c 60 2a  smul  %l1, 0x2a, %o7
a012f55c:  98 13 62 24  or  %o5, 0x224, %o4
a012f560:  96 03 c0 0c  add  %o7, %o4, %o3
a012f564:  d4 0a e0 0a  ldub  [ %o3 + 0xa ], %o2
a012f568:  b2 0e 60 ff  and  %i1, 0xff, %i1
a012f56c:  92 1a 80 19  xor  %o2, %i1, %o1
a012f570:  80 a0 00 09  cmp  %g0, %o1
a012f574:  82 40 20 00  addx  %g0, 0, %g1
a012f578:  b4 0e a0 ff  and  %i2, 0xff, %i2
a012f57c:  80 a0 00 1a  cmp  %g0, %i2
a012f580:  90 40 20 00  addx  %g0, 0, %o0
a012f584:  80 90 40 08  orcc  %g1, %o0, %g0
a012f588:  02 bf ff df  be  0xa012f504
a012f58c:  80 a6 60 61  cmp  %i1, 0x61
a012f590:  7f ff 55 a9  call  0xa0104c34
a012f594:  90 10 00 11  mov  %l1, %o0
a012f598:  80 8a 20 ff  btst  0xff, %o0
a012f59c:  02 80 00 75  be  0xa012f770
a012f5a0:  01 00 00 00  nop
a012f5a4:  94 10 00 1a  mov  %i2, %o2
a012f5a8:  90 10 00 11  mov  %l1, %o0
a012f5ac:  40 00 4e 49  call  0xa0142ed0
a012f5b0:  92 10 00 19  mov  %i1, %o1
a012f5b4:  90 10 20 00  clr  %o0
a012f5b8:  92 10 00 11  mov  %l1, %o1
a012f5bc:  40 00 36 97  call  0xa013d018
a012f5c0:  94 10 20 01  mov  1, %o2
a012f5c4:  80 a4 60 00  cmp  %l1, 0
a012f5c8:  02 80 00 67  be  0xa012f764
a012f5cc:  01 00 00 00  nop
a012f5d0:  7f ff b6 6e  call  0xa011cf88
a012f5d4:  01 00 00 00  nop
a012f5d8:  b4 0a 20 ff  and  %o0, 0xff, %i2
a012f5dc:  80 a6 a0 82  cmp  %i2, 0x82
a012f5e0:  08 80 00 05  bleu  0xa012f5f4
a012f5e4:  01 00 00 00  nop
a012f5e8:  80 a4 60 03  cmp  %l1, 3
a012f5ec:  08 80 00 65  bleu  0xa012f780
a012f5f0:  01 00 00 00  nop
a012f5f4:  7f ff c8 41  call  0xa01216f8
a012f5f8:  90 10 00 11  mov  %l1, %o0
a012f5fc:  10 bf ff c2  b  0xa012f504
a012f600:  80 a6 60 61  cmp  %i1, 0x61
a012f604:  12 bf ff ca  bne  0xa012f52c
a012f608:  83 2e 20 04  sll  %i0, 4, %g1
a012f60c:  b3 2e 20 04  sll  %i0, 4, %i1
a012f610:  82 26 40 18  sub  %i1, %i0, %g1
a012f614:  31 2a 00 b7  sethi  %hi(0xa802dc00), %i0
a012f618:  b5 28 60 03  sll  %g1, 3, %i2
a012f61c:  a2 16 23 30  or  %i0, 0x330, %l1
a012f620:  82 06 80 11  add  %i2, %l1, %g1
a012f624:  98 10 20 04  mov  4, %o4
a012f628:  10 80 00 5e  b  0xa012f7a0
a012f62c:  d8 28 60 76  stb  %o4, [ %g1 + 0x76 ]
a012f630:  10 bf ff 9d  b  0xa012f4a4
a012f634:  94 10 20 01  mov  1, %o2
a012f638:  10 bf ff 9b  b  0xa012f4a4
a012f63c:  94 10 20 02  mov  2, %o2
a012f640:  10 bf ff 99  b  0xa012f4a4
a012f644:  94 10 20 04  mov  4, %o2
a012f648:  7f ff 55 7b  call  0xa0104c34
a012f64c:  90 10 00 10  mov  %l0, %o0
a012f650:  80 8a 20 ff  btst  0xff, %o0
a012f654:  02 80 00 2f  be  0xa012f710
a012f658:  01 00 00 00  nop
a012f65c:  94 10 00 1a  mov  %i2, %o2
a012f660:  90 10 00 10  mov  %l0, %o0
a012f664:  40 00 4e 1b  call  0xa0142ed0
a012f668:  92 10 00 19  mov  %i1, %o1
a012f66c:  90 10 00 18  mov  %i0, %o0
a012f670:  92 10 00 10  mov  %l0, %o1
a012f674:  40 00 36 69  call  0xa013d018
a012f678:  94 10 20 01  mov  1, %o2
a012f67c:  80 a4 20 00  cmp  %l0, 0
a012f680:  02 80 00 21  be  0xa012f704
a012f684:  01 00 00 00  nop
a012f688:  7f ff b6 40  call  0xa011cf88
a012f68c:  01 00 00 00  nop
a012f690:  b4 0a 20 ff  and  %o0, 0xff, %i2
a012f694:  80 a6 a0 82  cmp  %i2, 0x82
a012f698:  08 80 00 05  bleu  0xa012f6ac
a012f69c:  01 00 00 00  nop
a012f6a0:  80 a4 20 03  cmp  %l0, 3
a012f6a4:  08 80 00 0f  bleu  0xa012f6e0
a012f6a8:  01 00 00 00  nop
a012f6ac:  7f ff c8 13  call  0xa01216f8
a012f6b0:  90 10 00 10  mov  %l0, %o0
a012f6b4:  10 bf ff 92  b  0xa012f4fc
a012f6b8:  80 a6 20 03  cmp  %i0, 3
a012f6bc:  97 2e 20 04  sll  %i0, 4, %o3
a012f6c0:  94 22 c0 18  sub  %o3, %i0, %o2
a012f6c4:  13 2a 00 b7  sethi  %hi(0xa802dc00), %o1
a012f6c8:  a1 2a a0 03  sll  %o2, 3, %l0
a012f6cc:  90 12 63 30  or  %o1, 0x330, %o0
a012f6d0:  82 04 00 08  add  %l0, %o0, %g1
a012f6d4:  98 10 20 08  mov  8, %o4
a012f6d8:  10 80 00 32  b  0xa012f7a0
a012f6dc:  d8 28 60 76  stb  %o4, [ %g1 + 0x76 ]
a012f6e0:  40 00 4a a2  call  0xa0142168
a012f6e4:  90 10 00 19  mov  %i1, %o0
a012f6e8:  a2 10 20 01  mov  1, %l1
a012f6ec:  83 2c 40 10  sll  %l1, %l0, %g1
a012f6f0:  90 0a 20 ff  and  %o0, 0xff, %o0
a012f6f4:  94 08 60 ff  and  %g1, 0xff, %o2
a012f6f8:  40 00 21 19  call  0xa0137b5c
a012f6fc:  92 10 20 00  clr  %o1
a012f700:  30 bf ff eb  b,a   0xa012f6ac
a012f704:  40 00 25 3d  call  0xa0138bf8
a012f708:  90 10 00 19  mov  %i1, %o0
a012f70c:  30 bf ff df  b,a   0xa012f688
a012f710:  7f ff 5d 26  call  0xa0106ba8
a012f714:  90 10 00 10  mov  %l0, %o0
a012f718:  10 bf ff d2  b  0xa012f660
a012f71c:  94 10 00 1a  mov  %i2, %o2
a012f720:  93 2e 20 04  sll  %i0, 4, %o1
a012f724:  90 22 40 18  sub  %o1, %i0, %o0
a012f728:  21 2a 00 b7  sethi  %hi(0xa802dc00), %l0
a012f72c:  b1 2a 20 03  sll  %o0, 3, %i0
a012f730:  b2 14 23 30  or  %l0, 0x330, %i1
a012f734:  82 06 00 19  add  %i0, %i1, %g1
a012f738:  98 10 20 10  mov  0x10, %o4
a012f73c:  10 80 00 19  b  0xa012f7a0
a012f740:  d8 28 60 76  stb  %o4, [ %g1 + 0x76 ]
a012f744:  98 23 40 18  sub  %o5, %i0, %o4
a012f748:  1f 2a 00 b7  sethi  %hi(0xa802dc00), %o7
a012f74c:  95 2b 20 03  sll  %o4, 3, %o2
a012f750:  96 13 e3 30  or  %o7, 0x330, %o3
a012f754:  82 02 80 0b  add  %o2, %o3, %g1
a012f758:  98 10 20 20  mov  0x20, %o4
a012f75c:  10 80 00 11  b  0xa012f7a0
a012f760:  d8 28 60 76  stb  %o4, [ %g1 + 0x76 ]
a012f764:  40 00 25 25  call  0xa0138bf8
a012f768:  90 10 00 19  mov  %i1, %o0
a012f76c:  30 bf ff 99  b,a   0xa012f5d0
a012f770:  7f ff 5d 0e  call  0xa0106ba8
a012f774:  90 10 00 11  mov  %l1, %o0
a012f778:  10 bf ff 8c  b  0xa012f5a8
a012f77c:  94 10 00 1a  mov  %i2, %o2
a012f780:  40 00 4a 7a  call  0xa0142168
a012f784:  90 10 00 19  mov  %i1, %o0
a012f788:  83 2c 00 11  sll  %l0, %l1, %g1
a012f78c:  90 0a 20 ff  and  %o0, 0xff, %o0
a012f790:  94 08 60 ff  and  %g1, 0xff, %o2
a012f794:  40 00 20 f2  call  0xa0137b5c
a012f798:  92 10 20 00  clr  %o1
a012f79c:  30 bf ff 96  b,a   0xa012f5f4
a012f7a0:  81 c7 e0 08  ret
a012f7a4:  81 e8 00 00  restore
