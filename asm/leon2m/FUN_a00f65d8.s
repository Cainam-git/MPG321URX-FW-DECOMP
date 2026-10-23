# leon2m FUN_a00f65d8 0xa00f65d8-0xa00f66a4 (204 bytes)
a00f65d8:  17 33 c0 3b  sethi  %hi(0xcf00ec00), %o3
a00f65dc:  98 12 e3 30  or  %o3, 0x330, %o4	! 0xcf00ef30
a00f65e0:  d4 03 00 00  ld  [ %o4 ], %o2
a00f65e4:  82 0a bf fd  and  %o2, -3, %g1
a00f65e8:  c2 23 00 00  st  %g1, [ %o4 ]
a00f65ec:  9a 12 e3 34  or  %o3, 0x334, %o5
a00f65f0:  c0 23 40 00  clr  [ %o5 ]
a00f65f4:  94 12 e3 3c  or  %o3, 0x33c, %o2
a00f65f8:  98 10 20 00  clr  %o4
a00f65fc:  9a 10 20 00  clr  %o5
a00f6600:  96 12 e3 38  or  %o3, 0x338, %o3
a00f6604:  80 a2 20 00  cmp  %o0, 0
a00f6608:  02 80 00 12  be  0xa00f6650
a00f660c:  82 10 20 80  mov  0x80, %g1
a00f6610:  c2 02 00 00  ld  [ %o0 ], %g1
a00f6614:  83 30 40 0d  srl  %g1, %o5, %g1
a00f6618:  80 88 60 01  btst  1, %g1
a00f661c:  22 80 00 07  be,a   0xa00f6638
a00f6620:  98 03 20 01  inc  %o4
a00f6624:  da 22 c0 00  st  %o5, [ %o3 ]
a00f6628:  82 02 00 0d  add  %o0, %o5, %g1
a00f662c:  da 08 60 04  ldub  [ %g1 + 4 ], %o5
a00f6630:  da 22 80 00  st  %o5, [ %o2 ]
a00f6634:  98 03 20 01  inc  %o4
a00f6638:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f663c:  80 a3 60 10  cmp  %o5, 0x10
a00f6640:  28 bf ff f5  bleu,a   0xa00f6614
a00f6644:  c2 02 00 00  ld  [ %o0 ], %g1
a00f6648:  10 80 00 11  b  0xa00f668c
a00f664c:  15 33 c0 3b  sethi  %hi(0xcf00ec00), %o2
a00f6650:  da 22 c0 00  st  %o5, [ %o3 ]
a00f6654:  98 03 20 01  inc  %o4
a00f6658:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f665c:  c2 22 80 00  st  %g1, [ %o2 ]
a00f6660:  80 a3 60 10  cmp  %o5, 0x10
a00f6664:  38 80 00 0a  bgu,a   0xa00f668c
a00f6668:  15 33 c0 3b  sethi  %hi(0xcf00ec00), %o2
a00f666c:  da 22 c0 00  st  %o5, [ %o3 ]
a00f6670:  98 03 20 01  inc  %o4
a00f6674:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f6678:  c2 22 80 00  st  %g1, [ %o2 ]
a00f667c:  80 a3 60 10  cmp  %o5, 0x10
a00f6680:  08 bf ff f4  bleu  0xa00f6650
a00f6684:  01 00 00 00  nop
a00f6688:  15 33 c0 3b  sethi  %hi(0xcf00ec00), %o2
a00f668c:  90 12 a3 30  or  %o2, 0x330, %o0	! 0xcf00ef30
a00f6690:  d8 02 00 00  ld  [ %o0 ], %o4
a00f6694:  96 13 20 02  or  %o4, 2, %o3
a00f6698:  d6 22 00 00  st  %o3, [ %o0 ]
a00f669c:  81 c3 e0 08  retl
a00f66a0:  01 00 00 00  nop
