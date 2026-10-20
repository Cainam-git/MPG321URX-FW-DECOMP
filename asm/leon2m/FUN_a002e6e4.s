# leon2m FUN_a002e6e4 0xa002e6e4-0xa002e764 (128 bytes)
a002e6e4:  9d e3 bf 98  save  %sp, -104, %sp
a002e6e8:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a002e6ec:  b4 10 62 a8  or  %g1, 0x2a8, %i2	! 0xa8027aa8
a002e6f0:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a002e6f4:  80 a6 20 07  cmp  %i0, 7
a002e6f8:  18 80 00 19  bgu  0xa002e75c
a002e6fc:  b6 0e 60 ff  and  %i1, 0xff, %i3
a002e700:  80 a6 e0 02  cmp  %i3, 2
a002e704:  b8 60 20 00  subx  %g0, 0, %i4
a002e708:  82 0e 40 1c  and  %i1, %i4, %g1
a002e70c:  ba 08 60 ff  and  %g1, 0xff, %i5
a002e710:  b2 07 40 1d  add  %i5, %i5, %i1
a002e714:  80 a6 e0 02  cmp  %i3, 2
a002e718:  f8 16 80 19  lduh  [ %i2 + %i1 ], %i4
a002e71c:  82 40 20 00  addx  %g0, 0, %g1
a002e720:  b2 07 20 a5  add  %i4, 0xa5, %i1
a002e724:  ba 20 00 01  neg  %g1, %i5
a002e728:  82 0e c0 1d  and  %i3, %i5, %g1
a002e72c:  b9 2e 60 02  sll  %i1, 2, %i4
a002e730:  b2 17 00 0f  or  %i4, %o7, %i1
a002e734:  b6 00 40 01  add  %g1, %g1, %i3
a002e738:  fa 16 80 1b  lduh  [ %i2 + %i3 ], %i5
a002e73c:  c2 06 40 00  ld  [ %i1 ], %g1
a002e740:  b6 07 60 a5  add  %i5, 0xa5, %i3
a002e744:  b8 08 60 f8  and  %g1, 0xf8, %i4
a002e748:  b2 17 00 18  or  %i4, %i0, %i1
a002e74c:  b5 2e e0 02  sll  %i3, 2, %i2
a002e750:  ba 16 80 0f  or  %i2, %o7, %i5
a002e754:  b0 0e 60 ff  and  %i1, 0xff, %i0
a002e758:  f0 27 40 00  st  %i0, [ %i5 ]
a002e75c:  81 c7 e0 08  ret
a002e760:  81 e8 00 00  restore
