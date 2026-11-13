# leon2m FUN_a015e4c4 0xa015e4c4-0xa015e774 (688 bytes)
a015e4c4:  10 80 00 0b  b  0xa015e4f0
a015e4c8:  86 10 20 00  clr  %g3
a015e4cc:  80 92 40 08  orcc  %o1, %o0, %g0
a015e4d0:  16 80 00 08  bge  0xa015e4f0
a015e4d4:  86 10 00 08  mov  %o0, %g3
a015e4d8:  80 92 40 00  tst  %o1
a015e4dc:  16 80 00 04  bge  0xa015e4ec
a015e4e0:  80 92 00 00  tst  %o0
a015e4e4:  16 80 00 03  bge  0xa015e4f0
a015e4e8:  92 20 00 09  neg  %o1
a015e4ec:  90 20 00 08  neg  %o0
a015e4f0:  9a 92 40 00  orcc  %o1, %g0, %o5
a015e4f4:  12 80 00 05  bne  0xa015e508
a015e4f8:  96 10 00 08  mov  %o0, %o3
a015e4fc:  91 d0 20 02  ta  2
a015e500:  81 c3 e0 08  retl
a015e504:  90 10 00 00  mov  %g0, %o0
a015e508:  80 a2 c0 0d  cmp  %o3, %o5
a015e50c:  0a 80 00 95  bcs  0xa015e760
a015e510:  94 10 00 00  mov  %g0, %o2
a015e514:  03 02 00 00  sethi  %hi(0x8000000), %g1
a015e518:  80 a2 c0 01  cmp  %o3, %g1
a015e51c:  0a 80 00 28  bcs  0xa015e5bc
a015e520:  98 10 00 00  mov  %g0, %o4
a015e524:  80 a3 40 01  cmp  %o5, %g1
a015e528:  1a 80 00 0d  bcc  0xa015e55c
a015e52c:  84 10 20 01  mov  1, %g2
a015e530:  9b 2b 60 04  sll  %o5, 4, %o5
a015e534:  10 bf ff fc  b  0xa015e524
a015e538:  98 03 20 01  inc  %o4
a015e53c:  9a 83 40 0d  addcc  %o5, %o5, %o5
a015e540:  1a 80 00 07  bcc  0xa015e55c
a015e544:  84 00 a0 01  inc  %g2
a015e548:  83 28 60 04  sll  %g1, 4, %g1
a015e54c:  9b 33 60 01  srl  %o5, 1, %o5
a015e550:  9a 03 40 01  add  %o5, %g1, %o5
a015e554:  10 80 00 07  b  0xa015e570
a015e558:  84 20 a0 01  dec  %g2
a015e55c:  80 a3 40 0b  cmp  %o5, %o3
a015e560:  0a bf ff f7  bcs  0xa015e53c
a015e564:  01 00 00 00  nop
a015e568:  02 80 00 02  be  0xa015e570
a015e56c:  01 00 00 00  nop
a015e570:  84 a0 a0 01  deccc  %g2
a015e574:  06 80 00 76  bl  0xa015e74c
a015e578:  01 00 00 00  nop
a015e57c:  96 22 c0 0d  sub  %o3, %o5, %o3
a015e580:  94 10 20 01  mov  1, %o2
a015e584:  10 80 00 0a  b  0xa015e5ac
a015e588:  01 00 00 00  nop
a015e58c:  95 2a a0 01  sll  %o2, 1, %o2
a015e590:  06 80 00 05  bl  0xa015e5a4
a015e594:  9b 33 60 01  srl  %o5, 1, %o5
a015e598:  96 22 c0 0d  sub  %o3, %o5, %o3
a015e59c:  10 80 00 04  b  0xa015e5ac
a015e5a0:  94 02 a0 01  inc  %o2
a015e5a4:  96 02 c0 0d  add  %o3, %o5, %o3
a015e5a8:  94 22 a0 01  dec  %o2
a015e5ac:  84 a0 a0 01  deccc  %g2
a015e5b0:  16 bf ff f7  bge  0xa015e58c
a015e5b4:  80 92 c0 00  tst  %o3
a015e5b8:  30 80 00 65  b,a   0xa015e74c
a015e5bc:  9b 2b 60 04  sll  %o5, 4, %o5
a015e5c0:  80 a3 40 0b  cmp  %o5, %o3
a015e5c4:  08 bf ff fe  bleu  0xa015e5bc
a015e5c8:  98 83 20 01  inccc  %o4
a015e5cc:  02 80 00 65  be  0xa015e760
a015e5d0:  98 23 20 01  dec  %o4
a015e5d4:  80 92 c0 00  tst  %o3
a015e5d8:  95 2a a0 04  sll  %o2, 4, %o2
a015e5dc:  06 80 00 2f  bl  0xa015e698
a015e5e0:  9b 33 60 01  srl  %o5, 1, %o5
a015e5e4:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a015e5e8:  06 80 00 17  bl  0xa015e644
a015e5ec:  9b 33 60 01  srl  %o5, 1, %o5
a015e5f0:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a015e5f4:  06 80 00 0b  bl  0xa015e620
a015e5f8:  9b 33 60 01  srl  %o5, 1, %o5
a015e5fc:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a015e600:  06 80 00 05  bl  0xa015e614
a015e604:  9b 33 60 01  srl  %o5, 1, %o5
a015e608:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a015e60c:  10 80 00 50  b  0xa015e74c
a015e610:  94 02 a0 0f  add  %o2, 0xf, %o2
a015e614:  96 82 c0 0d  addcc  %o3, %o5, %o3
a015e618:  10 80 00 4d  b  0xa015e74c
a015e61c:  94 02 a0 0d  add  %o2, 0xd, %o2
a015e620:  96 82 c0 0d  addcc  %o3, %o5, %o3
a015e624:  06 80 00 05  bl  0xa015e638
a015e628:  9b 33 60 01  srl  %o5, 1, %o5
a015e62c:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a015e630:  10 80 00 47  b  0xa015e74c
a015e634:  94 02 a0 0b  add  %o2, 0xb, %o2
a015e638:  96 82 c0 0d  addcc  %o3, %o5, %o3
a015e63c:  10 80 00 44  b  0xa015e74c
a015e640:  94 02 a0 09  add  %o2, 9, %o2
a015e644:  96 82 c0 0d  addcc  %o3, %o5, %o3
a015e648:  06 80 00 0b  bl  0xa015e674
a015e64c:  9b 33 60 01  srl  %o5, 1, %o5
a015e650:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a015e654:  06 80 00 05  bl  0xa015e668
a015e658:  9b 33 60 01  srl  %o5, 1, %o5
a015e65c:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a015e660:  10 80 00 3b  b  0xa015e74c
a015e664:  94 02 a0 07  add  %o2, 7, %o2
a015e668:  96 82 c0 0d  addcc  %o3, %o5, %o3
a015e66c:  10 80 00 38  b  0xa015e74c
a015e670:  94 02 a0 05  add  %o2, 5, %o2
a015e674:  96 82 c0 0d  addcc  %o3, %o5, %o3
a015e678:  06 80 00 05  bl  0xa015e68c
a015e67c:  9b 33 60 01  srl  %o5, 1, %o5
a015e680:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a015e684:  10 80 00 32  b  0xa015e74c
a015e688:  94 02 a0 03  add  %o2, 3, %o2
a015e68c:  96 82 c0 0d  addcc  %o3, %o5, %o3
a015e690:  10 80 00 2f  b  0xa015e74c
a015e694:  94 02 a0 01  inc  %o2
a015e698:  96 82 c0 0d  addcc  %o3, %o5, %o3
a015e69c:  06 80 00 17  bl  0xa015e6f8
a015e6a0:  9b 33 60 01  srl  %o5, 1, %o5
a015e6a4:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a015e6a8:  06 80 00 0b  bl  0xa015e6d4
a015e6ac:  9b 33 60 01  srl  %o5, 1, %o5
a015e6b0:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a015e6b4:  06 80 00 05  bl  0xa015e6c8
a015e6b8:  9b 33 60 01  srl  %o5, 1, %o5
a015e6bc:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a015e6c0:  10 80 00 23  b  0xa015e74c
a015e6c4:  94 02 bf ff  add  %o2, -1, %o2
a015e6c8:  96 82 c0 0d  addcc  %o3, %o5, %o3
a015e6cc:  10 80 00 20  b  0xa015e74c
a015e6d0:  94 02 bf fd  add  %o2, -3, %o2
a015e6d4:  96 82 c0 0d  addcc  %o3, %o5, %o3
a015e6d8:  06 80 00 05  bl  0xa015e6ec
a015e6dc:  9b 33 60 01  srl  %o5, 1, %o5
a015e6e0:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a015e6e4:  10 80 00 1a  b  0xa015e74c
a015e6e8:  94 02 bf fb  add  %o2, -5, %o2
a015e6ec:  96 82 c0 0d  addcc  %o3, %o5, %o3
a015e6f0:  10 80 00 17  b  0xa015e74c
a015e6f4:  94 02 bf f9  add  %o2, -7, %o2
a015e6f8:  96 82 c0 0d  addcc  %o3, %o5, %o3
a015e6fc:  06 80 00 0b  bl  0xa015e728
a015e700:  9b 33 60 01  srl  %o5, 1, %o5
a015e704:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a015e708:  06 80 00 05  bl  0xa015e71c
a015e70c:  9b 33 60 01  srl  %o5, 1, %o5
a015e710:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a015e714:  10 80 00 0e  b  0xa015e74c
a015e718:  94 02 bf f7  add  %o2, -9, %o2
a015e71c:  96 82 c0 0d  addcc  %o3, %o5, %o3
a015e720:  10 80 00 0b  b  0xa015e74c
a015e724:  94 02 bf f5  add  %o2, -11, %o2
a015e728:  96 82 c0 0d  addcc  %o3, %o5, %o3
a015e72c:  06 80 00 05  bl  0xa015e740
a015e730:  9b 33 60 01  srl  %o5, 1, %o5
a015e734:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a015e738:  10 80 00 05  b  0xa015e74c
a015e73c:  94 02 bf f3  add  %o2, -13, %o2
a015e740:  96 82 c0 0d  addcc  %o3, %o5, %o3
a015e744:  10 80 00 02  b  0xa015e74c
a015e748:  94 02 bf f1  add  %o2, -15, %o2
a015e74c:  98 a3 20 01  deccc  %o4
a015e750:  16 bf ff a2  bge  0xa015e5d8
a015e754:  80 92 c0 00  tst  %o3
a015e758:  26 80 00 02  bl,a   0xa015e760
a015e75c:  96 02 c0 09  add  %o3, %o1, %o3
a015e760:  80 90 c0 00  tst  %g3
a015e764:  26 80 00 02  bl,a   0xa015e76c
a015e768:  96 20 00 0b  neg  %o3
a015e76c:  81 c3 e0 08  retl
a015e770:  90 10 00 0b  mov  %o3, %o0
