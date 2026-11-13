# leon2s FUN_a009262c 0xa009262c-0xa00926e0 (180 bytes)
a009262c:  9d e3 bf 98  save  %sp, -104, %sp
a0092630:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0092634:  90 10 00 10  mov  %l0, %o0
a0092638:  92 10 20 00  clr  %o1
a009263c:  94 10 21 60  mov  0x160, %o2
a0092640:  40 00 56 85  call  0xa00a8054
a0092644:  d6 0e 40 00  ldub  [ %i1 ], %o3
a0092648:  90 10 00 10  mov  %l0, %o0
a009264c:  92 10 20 00  clr  %o1
a0092650:  94 10 21 61  mov  0x161, %o2
a0092654:  40 00 56 80  call  0xa00a8054
a0092658:  d6 0e 60 01  ldub  [ %i1 + 1 ], %o3
a009265c:  d6 0e 60 02  ldub  [ %i1 + 2 ], %o3
a0092660:  90 10 00 10  mov  %l0, %o0
a0092664:  92 10 20 00  clr  %o1
a0092668:  40 00 56 7b  call  0xa00a8054
a009266c:  94 10 21 62  mov  0x162, %o2
a0092670:  d6 0e 60 02  ldub  [ %i1 + 2 ], %o3
a0092674:  80 a2 e0 00  cmp  %o3, 0
a0092678:  b6 10 20 00  clr  %i3
a009267c:  02 80 00 12  be  0xa00926c4
a0092680:  b4 10 20 00  clr  %i2
a0092684:  94 0e a0 ff  and  %i2, 0xff, %o2
a0092688:  94 02 a1 64  add  %o2, 0x164, %o2
a009268c:  95 2a a0 10  sll  %o2, 0x10, %o2
a0092690:  95 32 a0 10  srl  %o2, 0x10, %o2
a0092694:  90 10 00 10  mov  %l0, %o0
a0092698:  40 00 56 6f  call  0xa00a8054
a009269c:  92 10 20 00  clr  %o1
a00926a0:  82 0e a0 ff  and  %i2, 0xff, %g1
a00926a4:  82 06 40 01  add  %i1, %g1, %g1
a00926a8:  da 08 60 04  ldub  [ %g1 + 4 ], %o5
a00926ac:  b4 06 a0 01  inc  %i2
a00926b0:  82 0e a0 ff  and  %i2, 0xff, %g1
a00926b4:  d6 0e 60 02  ldub  [ %i1 + 2 ], %o3
a00926b8:  80 a0 40 0b  cmp  %g1, %o3
a00926bc:  0a bf ff f2  bcs  0xa0092684
a00926c0:  b6 06 c0 0d  add  %i3, %o5, %i3
a00926c4:  b6 20 00 1b  neg  %i3
a00926c8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00926cc:  b6 0e e0 ff  and  %i3, 0xff, %i3
a00926d0:  b2 10 20 00  clr  %i1
a00926d4:  40 00 56 60  call  0xa00a8054
a00926d8:  95 e8 21 63  restore  %g0, 0x163, %o2
a00926dc:  01 00 00 00  nop
