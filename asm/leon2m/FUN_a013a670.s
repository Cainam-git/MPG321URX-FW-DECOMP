# leon2m FUN_a013a670 0xa013a670-0xa013a728 (184 bytes)
a013a670:  9d e3 bf 90  save  %sp, -112, %sp
a013a674:  90 10 3f ff  mov  -1, %o0
a013a678:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a013a67c:  90 10 20 02  mov  2, %o0
a013a680:  92 10 20 20  mov  0x20, %o1
a013a684:  94 07 bf f4  add  %fp, -12, %o2
a013a688:  67 fd 47 92  call  0x4008c4d0
a013a68c:  96 10 20 01  mov  1, %o3
a013a690:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013a694:  80 a0 60 00  cmp  %g1, 0
a013a698:  02 80 00 10  be  0xa013a6d8
a013a69c:  a0 10 20 64  mov  0x64, %l0
a013a6a0:  67 fd 4a c0  call  0x4008d1a0
a013a6a4:  90 10 20 01  mov  1, %o0
a013a6a8:  90 10 20 02  mov  2, %o0
a013a6ac:  92 10 20 20  mov  0x20, %o1
a013a6b0:  94 07 bf f4  add  %fp, -12, %o2
a013a6b4:  67 fd 47 87  call  0x4008c4d0
a013a6b8:  96 10 20 01  mov  1, %o3
a013a6bc:  a0 04 3f ff  add  %l0, -1, %l0
a013a6c0:  80 a4 20 00  cmp  %l0, 0
a013a6c4:  02 80 00 13  be  0xa013a710
a013a6c8:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a013a6cc:  80 a2 60 00  cmp  %o1, 0
a013a6d0:  12 bf ff f4  bne  0xa013a6a0
a013a6d4:  01 00 00 00  nop
a013a6d8:  82 0e 20 ff  and  %i0, 0xff, %g1
a013a6dc:  b1 28 60 10  sll  %g1, 0x10, %i0
a013a6e0:  a1 2e 60 10  sll  %i1, 0x10, %l0
a013a6e4:  19 14 c0 00  sethi  %hi(0x53000000), %o4
a013a6e8:  9e 16 00 0c  or  %i0, %o4, %o7
a013a6ec:  9b 34 20 10  srl  %l0, 0x10, %o5
a013a6f0:  96 13 c0 0d  or  %o7, %o5, %o3
a013a6f4:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a013a6f8:  90 10 20 02  mov  2, %o0
a013a6fc:  92 10 20 20  mov  0x20, %o1
a013a700:  94 07 bf f4  add  %fp, -12, %o2
a013a704:  67 fd 47 bd  call  0x4008c5f8
a013a708:  96 10 20 01  mov  1, %o3
a013a70c:  30 80 00 05  b,a   0xa013a720
a013a710:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a013a714:  80 a2 a0 00  cmp  %o2, 0
a013a718:  02 bf ff f1  be  0xa013a6dc
a013a71c:  82 0e 20 ff  and  %i0, 0xff, %g1
a013a720:  81 c7 e0 08  ret
a013a724:  81 e8 00 00  restore
