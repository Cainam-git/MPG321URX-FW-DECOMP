# leon2m FUN_a00c5478 0xa00c5478-0xa00c573c (584 bytes)
a00c5478:  9d e3 bf 98  save  %sp, -104, %sp
a00c547c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c5480:  80 a6 20 02  cmp  %i0, 2
a00c5484:  02 80 00 53  be  0xa00c55d0
a00c5488:  80 a6 20 03  cmp  %i0, 3
a00c548c:  02 80 00 71  be  0xa00c5650
a00c5490:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c5494:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c5498:  96 08 60 ff  and  %g1, 0xff, %o3
a00c549c:  94 02 ff d0  add  %o3, -48, %o2
a00c54a0:  a0 0a a0 ff  and  %o2, 0xff, %l0
a00c54a4:  80 a4 20 08  cmp  %l0, 8
a00c54a8:  18 80 00 a3  bgu  0xa00c5734
a00c54ac:  82 10 20 ff  mov  0xff, %g1
a00c54b0:  80 a4 20 04  cmp  %l0, 4
a00c54b4:  02 80 00 41  be  0xa00c55b8
a00c54b8:  80 a4 20 05  cmp  %l0, 5
a00c54bc:  02 80 00 3f  be  0xa00c55b8
a00c54c0:  80 a4 20 06  cmp  %l0, 6
a00c54c4:  02 80 00 3d  be  0xa00c55b8
a00c54c8:  01 00 00 00  nop
a00c54cc:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c54d0:  9a 12 e2 90  or  %o3, 0x290, %o5	! 0xa802d290
a00c54d4:  de 03 60 a8  ld  [ %o5 + 0xa8 ], %o7
a00c54d8:  98 13 e8 00  or  %o7, 0x800, %o4
a00c54dc:  80 a4 20 07  cmp  %l0, 7
a00c54e0:  08 80 00 30  bleu  0xa00c55a0
a00c54e4:  d8 23 60 a8  st  %o4, [ %o5 + 0xa8 ]
a00c54e8:  40 00 58 94  call  0xa00db738
a00c54ec:  01 00 00 00  nop
a00c54f0:  7f ff cc f7  call  0xa00b88cc
a00c54f4:  01 00 00 00  nop
a00c54f8:  80 a6 20 02  cmp  %i0, 2
a00c54fc:  02 80 00 38  be  0xa00c55dc
a00c5500:  80 a6 20 03  cmp  %i0, 3
a00c5504:  02 80 00 75  be  0xa00c56d8
a00c5508:  9e 10 20 30  mov  0x30, %o7
a00c550c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c5510:  94 12 60 78  or  %o1, 0x78, %o2	! 0xa802d078
a00c5514:  98 10 20 35  mov  0x35, %o4
a00c5518:  90 10 20 36  mov  0x36, %o0
a00c551c:  82 10 20 2b  mov  0x2b, %g1
a00c5520:  a0 10 20 0d  mov  0xd, %l0
a00c5524:  d8 2a 60 78  stb  %o4, [ %o1 + 0x78 ]
a00c5528:  d0 2a a0 01  stb  %o0, [ %o2 + 1 ]
a00c552c:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00c5530:  c2 2a a0 04  stb  %g1, [ %o2 + 4 ]
a00c5534:  e0 2a a0 05  stb  %l0, [ %o2 + 5 ]
a00c5538:  80 a6 20 02  cmp  %i0, 2
a00c553c:  02 80 00 35  be  0xa00c5610
a00c5540:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00c5544:  80 a6 20 03  cmp  %i0, 3
a00c5548:  02 80 00 71  be  0xa00c570c
a00c554c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c5550:  90 12 60 d0  or  %o1, 0xd0, %o0	! 0xa802d0d0
a00c5554:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c5558:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]	! 0xa802b09c
a00c555c:  c0 2a 60 d0  clrb  [ %o1 + 0xd0 ]
a00c5560:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c5564:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c5568:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c556c:  80 a6 20 02  cmp  %i0, 2
a00c5570:  02 80 00 31  be  0xa00c5634
a00c5574:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c5578:  80 a6 20 03  cmp  %i0, 3
a00c557c:  12 80 00 31  bne  0xa00c5640
a00c5580:  90 10 00 18  mov  %i0, %o0
a00c5584:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c5588:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c558c:  90 10 20 03  mov  3, %o0
a00c5590:  40 02 0c 96  call  0xa01487e8
a00c5594:  92 10 20 06  mov  6, %o1
a00c5598:  10 80 00 67  b  0xa00c5734
a00c559c:  82 10 20 00  clr  %g1
a00c55a0:  13 00 01 69  sethi  %hi(0x5a400), %o1
a00c55a4:  83 2c 20 02  sll  %l0, 2, %g1
a00c55a8:  90 12 62 34  or  %o1, 0x234, %o0
a00c55ac:  e0 02 00 01  ld  [ %o0 + %g1 ], %l0
a00c55b0:  81 c4 00 00  jmp  %l0
a00c55b4:  01 00 00 00  nop
a00c55b8:  40 00 49 e4  call  0xa00d7d48
a00c55bc:  01 00 00 00  nop
a00c55c0:  80 a2 20 00  cmp  %o0, 0
a00c55c4:  02 bf ff c2  be  0xa00c54cc
a00c55c8:  82 10 20 ff  mov  0xff, %g1
a00c55cc:  30 80 00 5a  b,a   0xa00c5734
a00c55d0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c55d4:  10 bf ff b1  b  0xa00c5498
a00c55d8:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c55dc:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c55e0:  b0 14 21 28  or  %l0, 0x128, %i0	! 0xa802d128
a00c55e4:  98 10 20 30  mov  0x30, %o4
a00c55e8:  82 10 20 35  mov  0x35, %g1
a00c55ec:  9e 10 20 0d  mov  0xd, %o7
a00c55f0:  9a 10 20 36  mov  0x36, %o5
a00c55f4:  96 10 20 2b  mov  0x2b, %o3
a00c55f8:  c2 2c 21 28  stb  %g1, [ %l0 + 0x128 ]
a00c55fc:  de 2e 20 05  stb  %o7, [ %i0 + 5 ]
a00c5600:  da 2e 20 01  stb  %o5, [ %i0 + 1 ]
a00c5604:  d8 2e 20 03  stb  %o4, [ %i0 + 3 ]
a00c5608:  d6 2e 20 04  stb  %o3, [ %i0 + 4 ]
a00c560c:  d8 2e 20 02  stb  %o4, [ %i0 + 2 ]
a00c5610:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c5614:  94 16 20 40  or  %i0, 0x40, %o2	! 0xa802d040
a00c5618:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c561c:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]	! 0xa802b09a
a00c5620:  c0 2e 20 40  clrb  [ %i0 + 0x40 ]
a00c5624:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c5628:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c562c:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c5630:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c5634:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c5638:  94 13 21 28  or  %o4, 0x128, %o2	! 0xa802d128
a00c563c:  90 10 20 02  mov  2, %o0
a00c5640:  40 02 0c 6a  call  0xa01487e8
a00c5644:  92 10 20 06  mov  6, %o1
a00c5648:  10 80 00 3b  b  0xa00c5734
a00c564c:  82 10 20 00  clr  %g1
a00c5650:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c5654:  10 bf ff 91  b  0xa00c5498
a00c5658:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c565c:  94 12 e2 90  or  %o3, 0x290, %o2
a00c5660:  10 bf ff a2  b  0xa00c54e8
a00c5664:  c0 2a a1 81  clrb  [ %o2 + 0x181 ]
a00c5668:  9a 12 e2 90  or  %o3, 0x290, %o5
a00c566c:  82 10 20 07  mov  7, %g1
a00c5670:  10 bf ff 9e  b  0xa00c54e8
a00c5674:  c2 2b 61 81  stb  %g1, [ %o5 + 0x181 ]
a00c5678:  9a 12 e2 90  or  %o3, 0x290, %o5
a00c567c:  82 10 20 06  mov  6, %g1
a00c5680:  10 bf ff 9a  b  0xa00c54e8
a00c5684:  c2 2b 61 81  stb  %g1, [ %o5 + 0x181 ]
a00c5688:  9a 12 e2 90  or  %o3, 0x290, %o5
a00c568c:  82 10 20 05  mov  5, %g1
a00c5690:  10 bf ff 96  b  0xa00c54e8
a00c5694:  c2 2b 61 81  stb  %g1, [ %o5 + 0x181 ]
a00c5698:  9a 12 e2 90  or  %o3, 0x290, %o5
a00c569c:  82 10 20 04  mov  4, %g1
a00c56a0:  10 bf ff 92  b  0xa00c54e8
a00c56a4:  c2 2b 61 81  stb  %g1, [ %o5 + 0x181 ]
a00c56a8:  9a 12 e2 90  or  %o3, 0x290, %o5
a00c56ac:  82 10 20 03  mov  3, %g1
a00c56b0:  10 bf ff 8e  b  0xa00c54e8
a00c56b4:  c2 2b 61 81  stb  %g1, [ %o5 + 0x181 ]
a00c56b8:  9a 12 e2 90  or  %o3, 0x290, %o5
a00c56bc:  82 10 20 02  mov  2, %g1
a00c56c0:  10 bf ff 8a  b  0xa00c54e8
a00c56c4:  c2 2b 61 81  stb  %g1, [ %o5 + 0x181 ]
a00c56c8:  9a 12 e2 90  or  %o3, 0x290, %o5
a00c56cc:  82 10 20 01  mov  1, %g1
a00c56d0:  10 bf ff 86  b  0xa00c54e8
a00c56d4:  c2 2b 61 81  stb  %g1, [ %o5 + 0x181 ]
a00c56d8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c56dc:  90 12 e1 08  or  %o3, 0x108, %o0	! 0xa802d108
a00c56e0:  92 10 20 30  mov  0x30, %o1
a00c56e4:  9a 10 20 35  mov  0x35, %o5
a00c56e8:  98 10 20 0d  mov  0xd, %o4
a00c56ec:  b0 10 20 36  mov  0x36, %i0
a00c56f0:  94 10 20 2b  mov  0x2b, %o2
a00c56f4:  da 2a e1 08  stb  %o5, [ %o3 + 0x108 ]
a00c56f8:  d8 2a 20 05  stb  %o4, [ %o0 + 5 ]
a00c56fc:  f0 2a 20 01  stb  %i0, [ %o0 + 1 ]
a00c5700:  d2 2a 20 03  stb  %o1, [ %o0 + 3 ]
a00c5704:  d4 2a 20 04  stb  %o2, [ %o0 + 4 ]
a00c5708:  d2 2a 20 02  stb  %o1, [ %o0 + 2 ]
a00c570c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c5710:  9a 13 e0 98  or  %o7, 0x98, %o5	! 0xa802d098
a00c5714:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00c5718:  c0 2c 20 98  clrb  [ %l0 + 0x98 ]	! 0xa802b098
a00c571c:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]
a00c5720:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00c5724:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00c5728:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00c572c:  10 bf ff 96  b  0xa00c5584
a00c5730:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00c5734:  81 c7 e0 08  ret
a00c5738:  91 e8 00 01  restore  %g0, %g1, %o0
