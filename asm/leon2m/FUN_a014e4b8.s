# leon2m FUN_a014e4b8 0xa014e4b8-0xa014e758 (672 bytes)
a014e4b8:  9d e3 bf 98  save  %sp, -104, %sp
a014e4bc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014e4c0:  80 a6 20 01  cmp  %i0, 1
a014e4c4:  a0 10 20 01  mov  1, %l0
a014e4c8:  02 80 00 0b  be  0xa014e4f4
a014e4cc:  98 10 20 01  mov  1, %o4
a014e4d0:  80 a6 20 01  cmp  %i0, 1
a014e4d4:  04 80 00 99  ble  0xa014e738
a014e4d8:  80 a6 20 02  cmp  %i0, 2
a014e4dc:  02 80 00 06  be  0xa014e4f4
a014e4e0:  98 10 20 02  mov  2, %o4
a014e4e4:  80 a6 20 03  cmp  %i0, 3
a014e4e8:  02 80 00 03  be  0xa014e4f4
a014e4ec:  98 10 20 03  mov  3, %o4
a014e4f0:  98 10 3f ff  mov  -1, %o4
a014e4f4:  82 0b 20 ff  and  %o4, 0xff, %g1
a014e4f8:  80 a0 60 03  cmp  %g1, 3
a014e4fc:  18 80 00 4d  bgu  0xa014e630
a014e500:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a014e504:  99 28 60 04  sll  %g1, 4, %o4
a014e508:  90 23 00 01  sub  %o4, %g1, %o0
a014e50c:  31 2a 00 b7  sethi  %hi(0xa802dc00), %i0
a014e510:  a2 16 23 30  or  %i0, 0x330, %l1	! 0xa802df30
a014e514:  9f 2a 20 03  sll  %o0, 3, %o7
a014e518:  d6 04 40 0f  ld  [ %l1 + %o7 ], %o3
a014e51c:  9b 32 e0 0c  srl  %o3, 0xc, %o5
a014e520:  a2 0b 60 0f  and  %o5, 0xf, %l1
a014e524:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014e528:  92 5c 60 2a  smul  %l1, 0x2a, %o1
a014e52c:  82 12 a2 24  or  %o2, 0x224, %g1
a014e530:  98 02 40 01  add  %o1, %g1, %o4
a014e534:  d8 0b 20 28  ldub  [ %o4 + 0x28 ], %o4
a014e538:  80 a3 20 01  cmp  %o4, 1
a014e53c:  18 80 00 03  bgu  0xa014e548
a014e540:  96 10 20 01  mov  1, %o3
a014e544:  96 10 20 00  clr  %o3
a014e548:  82 1b 20 1a  xor  %o4, 0x1a, %g1
a014e54c:  80 a0 00 01  cmp  %g0, %g1
a014e550:  92 40 20 00  addx  %g0, 0, %o1
a014e554:  80 8a c0 09  btst  %o3, %o1
a014e558:  02 80 00 06  be  0xa014e570
a014e55c:  90 10 00 11  mov  %l1, %o0
a014e560:  9a 1b 20 1b  xor  %o4, 0x1b, %o5
a014e564:  80 a0 00 0d  cmp  %g0, %o5
a014e568:  94 40 3f ff  addx  %g0, -1, %o2
a014e56c:  a0 0a 80 10  and  %o2, %l0, %l0
a014e570:  92 10 20 37  mov  0x37, %o1
a014e574:  7f fe 8d 58  call  0xa00f1ad4
a014e578:  94 10 20 16  mov  0x16, %o2
a014e57c:  80 8c 20 ff  btst  0xff, %l0
a014e580:  02 80 00 28  be  0xa014e620
a014e584:  90 10 00 11  mov  %l1, %o0
a014e588:  92 10 20 4a  mov  0x4a, %o1
a014e58c:  94 10 20 80  mov  0x80, %o2
a014e590:  96 10 20 00  clr  %o3
a014e594:  7f fe 8d 72  call  0xa00f1b5c
a014e598:  b0 10 20 00  clr  %i0
a014e59c:  90 10 00 11  mov  %l1, %o0
a014e5a0:  92 10 20 36  mov  0x36, %o1
a014e5a4:  7f fe 8d 4c  call  0xa00f1ad4
a014e5a8:  94 10 20 00  clr  %o2
a014e5ac:  92 10 20 36  mov  0x36, %o1
a014e5b0:  94 10 20 01  mov  1, %o2
a014e5b4:  7f fe 8d 48  call  0xa00f1ad4
a014e5b8:  90 10 00 11  mov  %l1, %o0
a014e5bc:  67 fc fa f9  call  0x4008d1a0
a014e5c0:  90 10 20 14  mov  0x14, %o0
a014e5c4:  67 fc fb f1  call  0x4008d588
a014e5c8:  01 00 00 00  nop
a014e5cc:  97 2a 20 10  sll  %o0, 0x10, %o3
a014e5d0:  a1 32 e0 10  srl  %o3, 0x10, %l0
a014e5d4:  92 10 20 36  mov  0x36, %o1
a014e5d8:  7f fe 8d 2e  call  0xa00f1a90
a014e5dc:  90 10 00 11  mov  %l1, %o0
a014e5e0:  80 8a 20 01  btst  1, %o0
a014e5e4:  22 80 00 17  be,a   0xa014e640
a014e5e8:  b0 10 20 01  mov  1, %i0
a014e5ec:  67 fc fb e7  call  0x4008d588
a014e5f0:  01 00 00 00  nop
a014e5f4:  99 2a 20 10  sll  %o0, 0x10, %o4
a014e5f8:  91 33 20 10  srl  %o4, 0x10, %o0
a014e5fc:  9e 22 00 10  sub  %o0, %l0, %o7
a014e600:  80 a3 e0 63  cmp  %o7, 0x63
a014e604:  04 bf ff f5  ble  0xa014e5d8
a014e608:  92 10 20 36  mov  0x36, %o1
a014e60c:  80 8e 20 ff  btst  0xff, %i0
a014e610:  02 80 00 4f  be  0xa014e74c
a014e614:  b0 10 20 00  clr  %i0
a014e618:  10 80 00 0e  b  0xa014e650
a014e61c:  92 10 20 41  mov  0x41, %o1
a014e620:  92 10 20 4a  mov  0x4a, %o1
a014e624:  94 10 20 80  mov  0x80, %o2
a014e628:  10 bf ff db  b  0xa014e594
a014e62c:  96 10 20 01  mov  1, %o3
a014e630:  7f fe 42 d0  call  0xa00df170
a014e634:  90 12 21 d8  or  %o0, 0x1d8, %o0
a014e638:  10 bf ff b3  b  0xa014e504
a014e63c:  82 10 20 00  clr  %g1
a014e640:  80 8e 20 ff  btst  0xff, %i0
a014e644:  02 80 00 42  be  0xa014e74c
a014e648:  b0 10 20 00  clr  %i0
a014e64c:  92 10 20 41  mov  0x41, %o1
a014e650:  7f fe 8d 10  call  0xa00f1a90
a014e654:  90 10 00 11  mov  %l1, %o0
a014e658:  96 0a 20 ff  and  %o0, 0xff, %o3
a014e65c:  a1 2a e0 08  sll  %o3, 8, %l0
a014e660:  92 10 20 40  mov  0x40, %o1
a014e664:  7f fe 8d 0b  call  0xa00f1a90
a014e668:  90 10 00 11  mov  %l1, %o0
a014e66c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a014e670:  94 13 40 10  or  %o5, %l0, %o2
a014e674:  83 2a a0 03  sll  %o2, 3, %g1
a014e678:  c2 36 40 00  sth  %g1, [ %i1 ]
a014e67c:  92 10 20 3d  mov  0x3d, %o1
a014e680:  7f fe 8d 04  call  0xa00f1a90
a014e684:  90 10 00 11  mov  %l1, %o0
a014e688:  92 0a 20 ff  and  %o0, 0xff, %o1
a014e68c:  b1 2a 60 08  sll  %o1, 8, %i0
a014e690:  92 10 20 3c  mov  0x3c, %o1
a014e694:  7f fe 8c ff  call  0xa00f1a90
a014e698:  90 10 00 11  mov  %l1, %o0
a014e69c:  90 0a 20 ff  and  %o0, 0xff, %o0
a014e6a0:  98 16 00 08  or  %i0, %o0, %o4
a014e6a4:  d8 36 80 00  sth  %o4, [ %i2 ]
a014e6a8:  92 10 20 3f  mov  0x3f, %o1
a014e6ac:  7f fe 8c f9  call  0xa00f1a90
a014e6b0:  90 10 00 11  mov  %l1, %o0
a014e6b4:  9e 0a 20 ff  and  %o0, 0xff, %o7
a014e6b8:  a1 2b e0 08  sll  %o7, 8, %l0
a014e6bc:  92 10 20 3e  mov  0x3e, %o1
a014e6c0:  7f fe 8c f4  call  0xa00f1a90
a014e6c4:  90 10 00 11  mov  %l1, %o0
a014e6c8:  96 0a 20 ff  and  %o0, 0xff, %o3
a014e6cc:  9a 12 c0 10  or  %o3, %l0, %o5
a014e6d0:  95 2b 60 03  sll  %o5, 3, %o2
a014e6d4:  d4 36 c0 00  sth  %o2, [ %i3 ]
a014e6d8:  92 10 20 39  mov  0x39, %o1
a014e6dc:  7f fe 8c ed  call  0xa00f1a90
a014e6e0:  90 10 00 11  mov  %l1, %o0
a014e6e4:  82 0a 20 ff  and  %o0, 0xff, %g1
a014e6e8:  b1 28 60 08  sll  %g1, 8, %i0
a014e6ec:  92 10 20 38  mov  0x38, %o1
a014e6f0:  7f fe 8c e8  call  0xa00f1a90
a014e6f4:  90 10 00 11  mov  %l1, %o0
a014e6f8:  92 0a 20 ff  and  %o0, 0xff, %o1
a014e6fc:  b6 16 00 09  or  %i0, %o1, %i3
a014e700:  f6 37 00 00  sth  %i3, [ %i4 ]
a014e704:  90 10 00 11  mov  %l1, %o0
a014e708:  7f fe 8f bc  call  0xa00f25f8
a014e70c:  92 10 20 4c  mov  0x4c, %o1
a014e710:  e0 16 40 00  lduh  [ %i1 ], %l0
a014e714:  80 a4 21 2b  cmp  %l0, 0x12b
a014e718:  08 80 00 06  bleu  0xa014e730
a014e71c:  b0 10 20 01  mov  1, %i0
a014e720:  f2 16 80 00  lduh  [ %i2 ], %i1
a014e724:  80 a6 60 c7  cmp  %i1, 0xc7
a014e728:  38 80 00 0a  bgu,a   0xa014e750
a014e72c:  b0 0e 20 01  and  %i0, 1, %i0
a014e730:  10 80 00 07  b  0xa014e74c
a014e734:  b0 10 20 00  clr  %i0
a014e738:  80 a6 20 00  cmp  %i0, 0
a014e73c:  02 bf ff 6e  be  0xa014e4f4
a014e740:  98 10 20 00  clr  %o4
a014e744:  10 bf ff 6c  b  0xa014e4f4
a014e748:  98 10 3f ff  mov  -1, %o4
a014e74c:  b0 0e 20 01  and  %i0, 1, %i0
a014e750:  81 c7 e0 08  ret
a014e754:  81 e8 00 00  restore
