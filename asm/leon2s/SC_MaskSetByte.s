# leon2s SC_MaskSetByte 0xa00a6440-0xa00a6544 (260 bytes)  [FUN_a00a653c = unreachable ret/restore tail, merged]
a00a6440:  9d e3 bf 98  save  %sp, -104, %sp
a00a6444:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a6448:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a644c:  82 10 61 c0  or  %g1, 0x1c0, %g1
a00a6450:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a6454:  c2 08 40 18  ldub  [ %g1 + %i0 ], %g1
a00a6458:  9e 10 00 1c  mov  %i4, %o7
a00a645c:  9a 10 00 1b  mov  %i3, %o5
a00a6460:  80 a6 40 01  cmp  %i1, %g1
a00a6464:  12 80 00 1e  bne  0xa00a64dc
a00a6468:  98 10 00 1c  mov  %i4, %o4
a00a646c:  80 a6 60 00  cmp  %i1, 0
a00a6470:  02 80 00 32  be  0xa00a6538
a00a6474:  b6 10 20 00  clr  %i3
a00a6478:  3b 28 02 d3  sethi  %hi(0xa00b4c00), %i5
a00a647c:  83 2e 20 02  sll  %i0, 2, %g1
a00a6480:  b9 2e a0 10  sll  %i2, 0x10, %i4
a00a6484:  ba 17 61 a0  or  %i5, 0x1a0, %i5
a00a6488:  9e 38 00 0d  xnor  %g0, %o5, %o7
a00a648c:  f0 07 40 01  ld  [ %i5 + %g1 ], %i0
a00a6490:  b5 37 20 10  srl  %i4, 0x10, %i2
a00a6494:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a6498:  82 0e e0 ff  and  %i3, 0xff, %g1
a00a649c:  82 00 40 01  add  %g1, %g1, %g1
a00a64a0:  fa 16 00 01  lduh  [ %i0 + %g1 ], %i5
a00a64a4:  ba 07 40 1a  add  %i5, %i2, %i5
a00a64a8:  bb 2f 60 02  sll  %i5, 2, %i5
a00a64ac:  ba 17 40 0d  or  %i5, %o5, %i5
a00a64b0:  c2 07 40 00  ld  [ %i5 ], %g1
a00a64b4:  82 08 40 0f  and  %g1, %o7, %g1
a00a64b8:  82 10 40 0c  or  %g1, %o4, %g1
a00a64bc:  b6 06 e0 01  inc  %i3
a00a64c0:  82 08 60 ff  and  %g1, 0xff, %g1
a00a64c4:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00a64c8:  c2 27 40 00  st  %g1, [ %i5 ]
a00a64cc:  80 a7 00 19  cmp  %i4, %i1
a00a64d0:  0a bf ff f3  bcs  0xa00a649c
a00a64d4:  82 0e e0 ff  and  %i3, 0xff, %g1
a00a64d8:  30 80 00 18  b,a   0xa00a6538
a00a64dc:  1a 80 00 13  bcc  0xa00a6528
a00a64e0:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a64e4:  bb 2e 20 02  sll  %i0, 2, %i5
a00a64e8:  82 10 61 a0  or  %g1, 0x1a0, %g1
a00a64ec:  f8 00 40 1d  ld  [ %g1 + %i5 ], %i4
a00a64f0:  ba 06 40 19  add  %i1, %i1, %i5
a00a64f4:  83 2e a0 10  sll  %i2, 0x10, %g1
a00a64f8:  83 30 60 10  srl  %g1, 0x10, %g1
a00a64fc:  fa 17 00 1d  lduh  [ %i4 + %i5 ], %i5
a00a6500:  ba 07 40 01  add  %i5, %g1, %i5
a00a6504:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00a6508:  bb 2f 60 02  sll  %i5, 2, %i5
a00a650c:  ba 17 40 01  or  %i5, %g1, %i5
a00a6510:  c2 07 40 00  ld  [ %i5 ], %g1
a00a6514:  82 28 40 1b  andn  %g1, %i3, %g1
a00a6518:  82 13 c0 01  or  %o7, %g1, %g1
a00a651c:  82 08 60 ff  and  %g1, 0xff, %g1
a00a6520:  c2 27 40 00  st  %g1, [ %i5 ]
a00a6524:  30 80 00 05  b,a   0xa00a6538
a00a6528:  31 28 01 b0  sethi  %hi(0xa006c000), %i0
a00a652c:  b0 16 21 58  or  %i0, 0x158, %i0	! 0xa006c158
a00a6530:  7f ff 32 c5  call  0xa0073044
a00a6534:  93 e8 20 63  restore  %g0, 0x63, %o1
a00a6538:  01 00 00 00  nop
a00a653c:  81 c7 e0 08  ret
a00a6540:  81 e8 00 00  restore
