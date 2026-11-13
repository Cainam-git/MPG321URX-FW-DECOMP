# leon2s FUN_a00a65c4 0xa00a65c4-0xa00a6668 (164 bytes)
a00a65c4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a65c8:  80 a2 20 02  cmp  %o0, 2
a00a65cc:  18 80 00 25  bgu  0xa00a6660
a00a65d0:  01 00 00 00  nop
a00a65d4:  12 80 00 16  bne  0xa00a662c
a00a65d8:  80 a2 20 01  cmp  %o0, 1
a00a65dc:  9b 2a 60 10  sll  %o1, 0x10, %o5
a00a65e0:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a65e4:  90 10 61 9c  or  %g1, 0x19c, %o0	! 0xa00b4d9c
a00a65e8:  93 33 60 10  srl  %o5, 0x10, %o1
a00a65ec:  94 0a a0 ff  and  %o2, 0xff, %o2
a00a65f0:  98 10 20 00  clr  %o4
a00a65f4:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00a65f8:  82 0b 20 ff  and  %o4, 0xff, %g1
a00a65fc:  82 00 40 01  add  %g1, %g1, %g1
a00a6600:  c2 12 00 01  lduh  [ %o0 + %g1 ], %g1
a00a6604:  82 00 40 09  add  %g1, %o1, %g1
a00a6608:  83 28 60 02  sll  %g1, 2, %g1
a00a660c:  98 03 20 01  inc  %o4
a00a6610:  82 10 40 0b  or  %g1, %o3, %g1
a00a6614:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00a6618:  d4 20 40 00  st  %o2, [ %g1 ]
a00a661c:  80 a3 60 01  cmp  %o5, 1
a00a6620:  08 bf ff f7  bleu  0xa00a65fc
a00a6624:  82 0b 20 ff  and  %o4, 0xff, %g1
a00a6628:  30 80 00 0e  b,a   0xa00a6660
a00a662c:  18 80 00 0d  bgu  0xa00a6660
a00a6630:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a6634:  98 02 00 08  add  %o0, %o0, %o4
a00a6638:  9b 2a 60 10  sll  %o1, 0x10, %o5
a00a663c:  82 10 61 9c  or  %g1, 0x19c, %g1
a00a6640:  9b 33 60 10  srl  %o5, 0x10, %o5
a00a6644:  c2 10 40 0c  lduh  [ %g1 + %o4 ], %g1
a00a6648:  82 00 40 0d  add  %g1, %o5, %g1
a00a664c:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a6650:  83 28 60 02  sll  %g1, 2, %g1
a00a6654:  82 10 40 0d  or  %g1, %o5, %g1
a00a6658:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00a665c:  da 20 40 00  st  %o5, [ %g1 ]
a00a6660:  81 c3 e0 08  retl
a00a6664:  01 00 00 00  nop
