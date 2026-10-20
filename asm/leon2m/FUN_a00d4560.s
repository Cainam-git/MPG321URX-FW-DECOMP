# leon2m FUN_a00d4560 0xa00d4560-0xa00d47c8 (232 bytes)
a00d4560:  9d e3 bf 98  save  %sp, -104, %sp
a00d4564:  40 01 c4 ef  call  0xa0145920
a00d4568:  90 10 20 00  clr  %o0
a00d456c:  92 0a 20 ff  and  %o0, 0xff, %o1
a00d4570:  94 10 20 01  mov  1, %o2
a00d4574:  40 01 e2 44  call  0xa014ce84
a00d4578:  90 10 20 00  clr  %o0
a00d457c:  40 01 c4 e9  call  0xa0145920
a00d4580:  90 10 20 01  mov  1, %o0
a00d4584:  92 0a 20 ff  and  %o0, 0xff, %o1
a00d4588:  94 10 20 01  mov  1, %o2
a00d458c:  40 01 e2 3e  call  0xa014ce84
a00d4590:  90 10 20 01  mov  1, %o0
a00d4594:  40 01 c4 e3  call  0xa0145920
a00d4598:  90 10 20 02  mov  2, %o0
a00d459c:  92 0a 20 ff  and  %o0, 0xff, %o1
a00d45a0:  94 10 20 01  mov  1, %o2
a00d45a4:  40 01 e2 38  call  0xa014ce84
a00d45a8:  90 10 20 02  mov  2, %o0
a00d45ac:  40 01 c4 dd  call  0xa0145920
a00d45b0:  90 10 20 03  mov  3, %o0
a00d45b4:  92 0a 20 ff  and  %o0, 0xff, %o1
a00d45b8:  94 10 20 01  mov  1, %o2
a00d45bc:  40 01 e2 32  call  0xa014ce84
a00d45c0:  90 10 20 03  mov  3, %o0
a00d45c4:  40 01 c4 d7  call  0xa0145920
a00d45c8:  90 10 20 04  mov  4, %o0
a00d45cc:  92 0a 20 ff  and  %o0, 0xff, %o1
a00d45d0:  90 10 20 04  mov  4, %o0
a00d45d4:  40 01 e2 2c  call  0xa014ce84
a00d45d8:  94 10 20 01  mov  1, %o2
a00d45dc:  40 01 c4 d1  call  0xa0145920
a00d45e0:  90 10 20 05  mov  5, %o0
a00d45e4:  b2 0a 20 ff  and  %o0, 0xff, %i1
a00d45e8:  b0 10 20 05  mov  5, %i0
a00d45ec:  40 01 e2 26  call  0xa014ce84
a00d45f0:  95 e8 20 01  restore  %g0, 1, %o2
a00d45f4:  01 00 00 00  nop
a00d45f8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d45fc:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d4600:  d2 08 60 12  ldub  [ %g1 + 0x12 ], %o1
a00d4604:  80 a2 60 64  cmp  %o1, 0x64
a00d4608:  08 80 00 03  bleu  0xa00d4614
a00d460c:  90 10 20 00  clr  %o0
a00d4610:  92 10 20 64  mov  0x64, %o1
a00d4614:  d2 28 60 12  stb  %o1, [ %g1 + 0x12 ]
a00d4618:  92 0a 60 ff  and  %o1, 0xff, %o1
a00d461c:  82 13 c0 00  mov  %o7, %g1
a00d4620:  40 01 d6 bf  call  0xa014a11c
a00d4624:  9e 10 40 00  mov  %g1, %o7
a00d4628:  01 00 00 00  nop
a00d462c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d4630:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d4634:  d2 08 60 13  ldub  [ %g1 + 0x13 ], %o1
a00d4638:  80 a2 60 64  cmp  %o1, 0x64
a00d463c:  08 80 00 03  bleu  0xa00d4648
a00d4640:  90 10 20 01  mov  1, %o0
a00d4644:  92 10 20 64  mov  0x64, %o1
a00d4648:  d2 28 60 13  stb  %o1, [ %g1 + 0x13 ]
a00d464c:  92 0a 60 ff  and  %o1, 0xff, %o1
a00d4650:  82 13 c0 00  mov  %o7, %g1
a00d4654:  40 01 d6 b2  call  0xa014a11c
a00d4658:  9e 10 40 00  mov  %g1, %o7
a00d465c:  01 00 00 00  nop
a00d4660:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d4664:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d4668:  d0 08 60 0b  ldub  [ %g1 + 0xb ], %o0
a00d466c:  80 a2 20 64  cmp  %o0, 0x64
a00d4670:  38 80 00 02  bgu,a   0xa00d4678
a00d4674:  90 10 20 64  mov  0x64, %o0
a00d4678:  d0 28 60 0b  stb  %o0, [ %g1 + 0xb ]
a00d467c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d4680:  82 13 c0 00  mov  %o7, %g1
a00d4684:  40 01 d3 06  call  0xa014929c
a00d4688:  9e 10 40 00  mov  %g1, %o7
a00d468c:  01 00 00 00  nop
a00d4690:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d4694:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d4698:  d2 08 60 15  ldub  [ %g1 + 0x15 ], %o1
a00d469c:  80 a2 60 64  cmp  %o1, 0x64
a00d46a0:  08 80 00 03  bleu  0xa00d46ac
a00d46a4:  90 10 20 00  clr  %o0
a00d46a8:  92 10 20 64  mov  0x64, %o1
a00d46ac:  d2 28 60 15  stb  %o1, [ %g1 + 0x15 ]
a00d46b0:  92 0a 60 ff  and  %o1, 0xff, %o1
a00d46b4:  82 13 c0 00  mov  %o7, %g1
a00d46b8:  40 01 d6 fa  call  0xa014a2a0
a00d46bc:  9e 10 40 00  mov  %g1, %o7
a00d46c0:  01 00 00 00  nop
a00d46c4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d46c8:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d46cc:  d2 08 60 16  ldub  [ %g1 + 0x16 ], %o1
a00d46d0:  80 a2 60 64  cmp  %o1, 0x64
a00d46d4:  08 80 00 03  bleu  0xa00d46e0
a00d46d8:  90 10 20 01  mov  1, %o0
a00d46dc:  92 10 20 64  mov  0x64, %o1
a00d46e0:  d2 28 60 16  stb  %o1, [ %g1 + 0x16 ]
a00d46e4:  92 0a 60 ff  and  %o1, 0xff, %o1
a00d46e8:  82 13 c0 00  mov  %o7, %g1
a00d46ec:  40 01 d6 ed  call  0xa014a2a0
a00d46f0:  9e 10 40 00  mov  %g1, %o7
a00d46f4:  01 00 00 00  nop
a00d46f8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d46fc:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d4700:  d2 08 60 17  ldub  [ %g1 + 0x17 ], %o1
a00d4704:  80 a2 60 64  cmp  %o1, 0x64
a00d4708:  08 80 00 03  bleu  0xa00d4714
a00d470c:  90 10 20 02  mov  2, %o0
a00d4710:  92 10 20 64  mov  0x64, %o1
a00d4714:  d2 28 60 17  stb  %o1, [ %g1 + 0x17 ]
a00d4718:  92 0a 60 ff  and  %o1, 0xff, %o1
a00d471c:  82 13 c0 00  mov  %o7, %g1
a00d4720:  40 01 d6 e0  call  0xa014a2a0
a00d4724:  9e 10 40 00  mov  %g1, %o7
a00d4728:  01 00 00 00  nop
a00d472c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d4730:  9a 12 22 90  or  %o0, 0x290, %o5	! 0xa802d290
a00d4734:  d2 0b 60 0d  ldub  [ %o5 + 0xd ], %o1
a00d4738:  c2 0b 60 0e  ldub  [ %o5 + 0xe ], %g1
a00d473c:  91 2a 60 10  sll  %o1, 0x10, %o0
a00d4740:  99 32 20 10  srl  %o0, 0x10, %o4
a00d4744:  83 28 60 10  sll  %g1, 0x10, %g1
a00d4748:  94 10 20 00  clr  %o2
a00d474c:  80 a3 20 64  cmp  %o4, 0x64
a00d4750:  08 80 00 03  bleu  0xa00d475c
a00d4754:  9b 30 60 10  srl  %g1, 0x10, %o5
a00d4758:  11 00 19 00  sethi  %hi(0x640000), %o0
a00d475c:  80 a3 60 64  cmp  %o5, 0x64
a00d4760:  08 80 00 03  bleu  0xa00d476c
a00d4764:  91 32 20 10  srl  %o0, 0x10, %o0
a00d4768:  03 00 19 00  sethi  %hi(0x640000), %g1
a00d476c:  93 30 60 10  srl  %g1, 0x10, %o1
a00d4770:  82 13 c0 00  mov  %o7, %g1
a00d4774:  40 01 c7 69  call  0xa0146518
a00d4778:  9e 10 40 00  mov  %g1, %o7
a00d477c:  01 00 00 00  nop
a00d4780:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d4784:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d4788:  d0 08 60 0f  ldub  [ %g1 + 0xf ], %o0
a00d478c:  80 a2 20 05  cmp  %o0, 5
a00d4790:  38 80 00 02  bgu,a   0xa00d4798
a00d4794:  90 10 20 05  mov  5, %o0
a00d4798:  d0 28 60 0f  stb  %o0, [ %g1 + 0xf ]
a00d479c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d47a0:  82 13 c0 00  mov  %o7, %g1
a00d47a4:  40 01 d6 f9  call  0xa014a388
a00d47a8:  9e 10 40 00  mov  %g1, %o7
a00d47ac:  01 00 00 00  nop
a00d47b0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d47b4:  d0 08 62 9c  ldub  [ %g1 + 0x29c ], %o0	! 0xa802d29c
a00d47b8:  82 13 c0 00  mov  %o7, %g1
a00d47bc:  7f fe f1 f6  call  0xa0090f94
a00d47c0:  9e 10 40 00  mov  %g1, %o7
a00d47c4:  01 00 00 00  nop
