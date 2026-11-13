# leon2s FUN_a00a74b8 0xa00a74b8-0xa00a7614 (348 bytes)
a00a74b8:  9d e3 bf 98  save  %sp, -104, %sp
a00a74bc:  03 33 c0 f4  sethi  %hi(0xcf03d000), %g1
a00a74c0:  94 10 60 14  or  %g1, 0x14, %o2	! 0xcf03d014
a00a74c4:  da 02 80 00  ld  [ %o2 ], %o5
a00a74c8:  92 10 60 18  or  %g1, 0x18, %o1
a00a74cc:  de 02 40 00  ld  [ %o1 ], %o7
a00a74d0:  98 10 60 1c  or  %g1, 0x1c, %o4
a00a74d4:  f4 03 00 00  ld  [ %o4 ], %i2
a00a74d8:  96 10 60 20  or  %g1, 0x20, %o3
a00a74dc:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a00a74e0:  f6 02 c0 00  ld  [ %o3 ], %i3
a00a74e4:  82 17 60 2c  or  %i5, 0x2c, %g1
a00a74e8:  f8 00 40 00  ld  [ %g1 ], %i4
a00a74ec:  ba 17 60 30  or  %i5, 0x30, %i5
a00a74f0:  90 10 00 0d  mov  %o5, %o0
a00a74f4:  c2 07 40 00  ld  [ %i5 ], %g1
a00a74f8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a74fc:  a0 10 00 0f  mov  %o7, %l0
a00a7500:  a2 10 00 1a  mov  %i2, %l1
a00a7504:  9a 10 00 1c  mov  %i4, %o5
a00a7508:  a4 10 00 1b  mov  %i3, %l2
a00a750c:  9e 10 00 01  mov  %g1, %o7
a00a7510:  80 a6 20 01  cmp  %i0, 1
a00a7514:  b8 10 00 19  mov  %i1, %i4
a00a7518:  18 80 00 3d  bgu  0xa00a760c
a00a751c:  b4 10 20 00  clr  %i2
a00a7520:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00a7524:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00
a00a7528:  82 0e 40 01  and  %i1, %g1, %g1
a00a752c:  83 38 60 08  sra  %g1, 8, %g1
a00a7530:  ba 10 20 01  mov  1, %i5
a00a7534:  80 a6 20 00  cmp  %i0, 0
a00a7538:  02 80 00 06  be  0xa00a7550
a00a753c:  83 2f 40 01  sll  %i5, %g1, %g1
a00a7540:  80 a6 20 01  cmp  %i0, 1
a00a7544:  02 80 00 0a  be  0xa00a756c
a00a7548:  80 a6 20 00  cmp  %i0, 0
a00a754c:  30 80 00 0f  b,a   0xa00a7588
a00a7550:  ba 08 60 ff  and  %g1, 0xff, %i5
a00a7554:  83 30 60 08  srl  %g1, 8, %g1
a00a7558:  fa 22 80 00  st  %i5, [ %o2 ]
a00a755c:  82 08 60 01  and  %g1, 1, %g1
a00a7560:  c2 22 40 00  st  %g1, [ %o1 ]
a00a7564:  10 80 00 0c  b  0xa00a7594
a00a7568:  ba 10 20 85  mov  0x85, %i5
a00a756c:  ba 08 60 ff  and  %g1, 0xff, %i5
a00a7570:  83 30 60 08  srl  %g1, 8, %g1
a00a7574:  fa 23 00 00  st  %i5, [ %o4 ]
a00a7578:  82 08 60 01  and  %g1, 1, %g1
a00a757c:  c2 22 c0 00  st  %g1, [ %o3 ]
a00a7580:  10 80 00 05  b  0xa00a7594
a00a7584:  ba 10 20 86  mov  0x86, %i5
a00a7588:  32 80 00 03  bne,a   0xa00a7594
a00a758c:  ba 10 20 86  mov  0x86, %i5
a00a7590:  ba 10 20 85  mov  0x85, %i5
a00a7594:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00a7598:  82 10 60 2c  or  %g1, 0x2c, %g1	! 0xcf01142c
a00a759c:  fa 20 40 00  st  %i5, [ %g1 ]
a00a75a0:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00a75a4:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00a75a8:  b8 10 60 30  or  %g1, 0x30, %i4
a00a75ac:  fa 27 00 00  st  %i5, [ %i4 ]
a00a75b0:  b6 10 60 34  or  %g1, 0x34, %i3
a00a75b4:  fa 06 c0 00  ld  [ %i3 ], %i5
a00a75b8:  f4 06 c0 00  ld  [ %i3 ], %i2
a00a75bc:  ba 0b e0 ff  and  %o7, 0xff, %i5
a00a75c0:  fa 27 00 00  st  %i5, [ %i4 ]
a00a75c4:  82 10 60 2c  or  %g1, 0x2c, %g1
a00a75c8:  b8 0b 60 ff  and  %o5, 0xff, %i4
a00a75cc:  f8 20 40 00  st  %i4, [ %g1 ]
a00a75d0:  3b 33 c0 f4  sethi  %hi(0xcf03d000), %i5
a00a75d4:  82 17 60 14  or  %i5, 0x14, %g1	! 0xcf03d014
a00a75d8:  b8 0a 20 ff  and  %o0, 0xff, %i4
a00a75dc:  f8 20 40 00  st  %i4, [ %g1 ]
a00a75e0:  82 17 60 18  or  %i5, 0x18, %g1
a00a75e4:  b8 0c 20 ff  and  %l0, 0xff, %i4
a00a75e8:  f8 20 40 00  st  %i4, [ %g1 ]
a00a75ec:  82 17 60 1c  or  %i5, 0x1c, %g1
a00a75f0:  b8 0c 60 ff  and  %l1, 0xff, %i4
a00a75f4:  f8 20 40 00  st  %i4, [ %g1 ]
a00a75f8:  82 0c a0 ff  and  %l2, 0xff, %g1
a00a75fc:  ba 17 60 20  or  %i5, 0x20, %i5
a00a7600:  c2 27 40 00  st  %g1, [ %i5 ]
a00a7604:  c2 06 c0 00  ld  [ %i3 ], %g1
a00a7608:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00a760c:  81 c7 e0 08  ret
a00a7610:  91 e8 00 1a  restore  %g0, %i2, %o0
