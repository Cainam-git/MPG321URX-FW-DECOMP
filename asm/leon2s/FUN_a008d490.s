# leon2s FUN_a008d490 0xa008d490-0xa008d690 (512 bytes)
a008d490:  9d e3 bf 98  save  %sp, -104, %sp
a008d494:  b2 0e 60 ff  and  %i1, 0xff, %i1
a008d498:  b4 0e a0 ff  and  %i2, 0xff, %i2
a008d49c:  80 a6 80 19  cmp  %i2, %i1
a008d4a0:  08 80 00 7a  bleu  0xa008d688
a008d4a4:  a8 10 20 00  clr  %l4
a008d4a8:  a3 2d 20 10  sll  %l4, 0x10, %l1
a008d4ac:  83 34 60 10  srl  %l1, 0x10, %g1
a008d4b0:  da 0e 00 01  ldub  [ %i0 + %g1 ], %o5
a008d4b4:  82 0b 60 e0  and  %o5, 0xe0, %g1
a008d4b8:  80 a0 60 e0  cmp  %g1, 0xe0
a008d4bc:  02 80 00 04  be  0xa008d4cc
a008d4c0:  80 a3 60 a0  cmp  %o5, 0xa0
a008d4c4:  12 80 00 64  bne  0xa008d654
a008d4c8:  83 2e 60 10  sll  %i1, 0x10, %g1
a008d4cc:  9b 34 60 10  srl  %l1, 0x10, %o5
a008d4d0:  d6 0e 00 0d  ldub  [ %i0 + %o5 ], %o3
a008d4d4:  82 06 00 0d  add  %i0, %o5, %g1
a008d4d8:  98 0a e0 ff  and  %o3, 0xff, %o4
a008d4dc:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a008d4e0:  80 a3 20 a0  cmp  %o4, 0xa0
a008d4e4:  aa 10 20 00  clr  %l5
a008d4e8:  12 80 00 18  bne  0xa008d548
a008d4ec:  a6 10 20 00  clr  %l3
a008d4f0:  96 08 60 ff  and  %g1, 0xff, %o3
a008d4f4:  80 a2 e0 00  cmp  %o3, 0
a008d4f8:  02 80 00 4a  be  0xa008d620
a008d4fc:  98 10 20 00  clr  %o4
a008d500:  94 10 00 0d  mov  %o5, %o2
a008d504:  83 2b 20 10  sll  %o4, 0x10, %g1
a008d508:  83 30 60 10  srl  %g1, 0x10, %g1
a008d50c:  98 03 20 01  inc  %o4
a008d510:  82 00 40 0a  add  %g1, %o2, %g1
a008d514:  82 00 40 18  add  %g1, %i0, %g1
a008d518:  9b 2b 20 10  sll  %o4, 0x10, %o5
a008d51c:  c2 08 60 02  ldub  [ %g1 + 2 ], %g1
a008d520:  9b 33 60 10  srl  %o5, 0x10, %o5
a008d524:  80 a3 40 0b  cmp  %o5, %o3
a008d528:  0a bf ff f7  bcs  0xa008d504
a008d52c:  aa 1d 40 01  xor  %l5, %g1, %l5
a008d530:  10 80 00 3d  b  0xa008d624
a008d534:  83 2d 20 10  sll  %l4, 0x10, %g1
a008d538:  83 2d 20 10  sll  %l4, 0x10, %g1
a008d53c:  83 30 60 10  srl  %g1, 0x10, %g1
a008d540:  10 80 00 38  b  0xa008d620
a008d544:  c0 2e 00 01  clrb  [ %i0 + %g1 ]
a008d548:  82 0b 20 e0  and  %o4, 0xe0, %g1
a008d54c:  80 a0 60 e0  cmp  %g1, 0xe0
a008d550:  12 80 00 35  bne  0xa008d624
a008d554:  83 2d 20 10  sll  %l4, 0x10, %g1
a008d558:  90 0a e0 1f  and  %o3, 0x1f, %o0
a008d55c:  80 a2 20 17  cmp  %o0, 0x17
a008d560:  18 80 00 30  bgu  0xa008d620
a008d564:  9b 2e 60 10  sll  %i1, 0x10, %o5
a008d568:  03 28 02 d0  sethi  %hi(0xa00b4000), %g1
a008d56c:  82 10 60 36  or  %g1, 0x36, %g1	! 0xa00b4036
a008d570:  9b 33 60 0e  srl  %o5, 0xe, %o5
a008d574:  90 0a 20 ff  and  %o0, 0xff, %o0
a008d578:  a1 34 60 10  srl  %l1, 0x10, %l0
a008d57c:  9a 03 40 01  add  %o5, %g1, %o5
a008d580:  82 0c e0 ff  and  %l3, 0xff, %g1
a008d584:  91 2a 20 03  sll  %o0, 3, %o0
a008d588:  a4 06 00 10  add  %i0, %l0, %l2
a008d58c:  90 02 2d a0  add  %o0, 0xda0, %o0
a008d590:  94 10 00 12  mov  %l2, %o2
a008d594:  80 a0 60 03  cmp  %g1, 3
a008d598:  18 bf ff e8  bgu  0xa008d538
a008d59c:  a6 04 e0 01  inc  %l3
a008d5a0:  7f ff ff 50  call  0xa008d2e0
a008d5a4:  d2 13 60 02  lduh  [ %o5 + 2 ], %o1
a008d5a8:  c2 0e 00 10  ldub  [ %i0 + %l0 ], %g1
a008d5ac:  90 08 60 1f  and  %g1, 0x1f, %o0
a008d5b0:  9a 08 60 ff  and  %g1, 0xff, %o5
a008d5b4:  82 0b 60 e0  and  %o5, 0xe0, %g1
a008d5b8:  80 a0 60 e0  cmp  %g1, 0xe0
a008d5bc:  02 80 00 06  be  0xa008d5d4
a008d5c0:  80 a3 60 a0  cmp  %o5, 0xa0
a008d5c4:  12 80 00 18  bne  0xa008d624
a008d5c8:  83 2d 20 10  sll  %l4, 0x10, %g1
a008d5cc:  10 80 00 05  b  0xa008d5e0
a008d5d0:  d4 0c a0 01  ldub  [ %l2 + 1 ], %o2
a008d5d4:  12 bf ff e3  bne  0xa008d560
a008d5d8:  80 a2 20 17  cmp  %o0, 0x17
a008d5dc:  d4 0c a0 01  ldub  [ %l2 + 1 ], %o2
a008d5e0:  80 a2 a0 00  cmp  %o2, 0
a008d5e4:  aa 10 20 00  clr  %l5
a008d5e8:  02 80 00 0e  be  0xa008d620
a008d5ec:  98 10 20 00  clr  %o4
a008d5f0:  97 34 60 10  srl  %l1, 0x10, %o3
a008d5f4:  83 2b 20 10  sll  %o4, 0x10, %g1
a008d5f8:  83 30 60 10  srl  %g1, 0x10, %g1
a008d5fc:  98 03 20 01  inc  %o4
a008d600:  82 00 40 0b  add  %g1, %o3, %g1
a008d604:  82 00 40 18  add  %g1, %i0, %g1
a008d608:  9b 2b 20 10  sll  %o4, 0x10, %o5
a008d60c:  c2 08 60 02  ldub  [ %g1 + 2 ], %g1
a008d610:  9b 33 60 10  srl  %o5, 0x10, %o5
a008d614:  80 a3 40 0a  cmp  %o5, %o2
a008d618:  0a bf ff f7  bcs  0xa008d5f4
a008d61c:  aa 1d 40 01  xor  %l5, %g1, %l5
a008d620:  83 2d 20 10  sll  %l4, 0x10, %g1
a008d624:  99 30 60 10  srl  %g1, 0x10, %o4
a008d628:  c2 0e 00 0c  ldub  [ %i0 + %o4 ], %g1
a008d62c:  82 18 60 a0  xor  %g1, 0xa0, %g1
a008d630:  80 a0 00 01  cmp  %g0, %g1
a008d634:  9a 60 3f ff  subx  %g0, -1, %o5
a008d638:  82 0d 60 ff  and  %l5, 0xff, %g1
a008d63c:  80 a0 00 01  cmp  %g0, %g1
a008d640:  82 40 20 00  addx  %g0, 0, %g1
a008d644:  80 8b 40 01  btst  %o5, %g1
a008d648:  32 80 00 02  bne,a   0xa008d650
a008d64c:  c0 2e 00 0c  clrb  [ %i0 + %o4 ]
a008d650:  83 2e 60 10  sll  %i1, 0x10, %g1
a008d654:  1b 28 02 d0  sethi  %hi(0xa00b4000), %o5
a008d658:  9a 13 60 36  or  %o5, 0x36, %o5	! 0xa00b4036
a008d65c:  83 30 60 0e  srl  %g1, 0xe, %g1
a008d660:  82 00 40 0d  add  %g1, %o5, %g1
a008d664:  c2 10 60 02  lduh  [ %g1 + 2 ], %g1
a008d668:  a8 05 00 01  add  %l4, %g1, %l4
a008d66c:  82 06 60 01  add  %i1, 1, %g1
a008d670:  9b 28 60 10  sll  %g1, 0x10, %o5
a008d674:  9b 33 60 10  srl  %o5, 0x10, %o5
a008d678:  98 0e a0 ff  and  %i2, 0xff, %o4
a008d67c:  80 a3 40 0c  cmp  %o5, %o4
a008d680:  0a bf ff 8a  bcs  0xa008d4a8
a008d684:  b2 10 00 01  mov  %g1, %i1
a008d688:  81 c7 e0 08  ret
a008d68c:  81 e8 00 00  restore
