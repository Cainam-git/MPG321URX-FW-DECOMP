# leon2m FUN_a013a5b8 0xa013a5b8-0xa013a670 (184 bytes)
a013a5b8:  9d e3 bf 90  save  %sp, -112, %sp
a013a5bc:  90 10 3f ff  mov  -1, %o0
a013a5c0:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a013a5c4:  90 10 20 02  mov  2, %o0
a013a5c8:  92 10 20 20  mov  0x20, %o1
a013a5cc:  94 07 bf f4  add  %fp, -12, %o2
a013a5d0:  67 fd 47 c0  call  0x4008c4d0
a013a5d4:  96 10 20 01  mov  1, %o3
a013a5d8:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013a5dc:  80 a0 60 00  cmp  %g1, 0
a013a5e0:  02 80 00 10  be  0xa013a620
a013a5e4:  a0 10 20 64  mov  0x64, %l0
a013a5e8:  67 fd 4a ee  call  0x4008d1a0
a013a5ec:  90 10 20 01  mov  1, %o0
a013a5f0:  90 10 20 02  mov  2, %o0
a013a5f4:  92 10 20 20  mov  0x20, %o1
a013a5f8:  94 07 bf f4  add  %fp, -12, %o2
a013a5fc:  67 fd 47 b5  call  0x4008c4d0
a013a600:  96 10 20 01  mov  1, %o3
a013a604:  a0 04 3f ff  add  %l0, -1, %l0
a013a608:  80 a4 20 00  cmp  %l0, 0
a013a60c:  02 80 00 13  be  0xa013a658
a013a610:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a013a614:  80 a2 60 00  cmp  %o1, 0
a013a618:  12 bf ff f4  bne  0xa013a5e8
a013a61c:  01 00 00 00  nop
a013a620:  82 0e 20 ff  and  %i0, 0xff, %g1
a013a624:  b1 28 60 10  sll  %g1, 0x10, %i0
a013a628:  a1 2e 60 10  sll  %i1, 0x10, %l0
a013a62c:  19 14 80 00  sethi  %hi(0x52000000), %o4
a013a630:  9e 16 00 0c  or  %i0, %o4, %o7
a013a634:  9b 34 20 10  srl  %l0, 0x10, %o5
a013a638:  96 13 c0 0d  or  %o7, %o5, %o3
a013a63c:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a013a640:  90 10 20 02  mov  2, %o0
a013a644:  92 10 20 20  mov  0x20, %o1
a013a648:  94 07 bf f4  add  %fp, -12, %o2
a013a64c:  67 fd 47 eb  call  0x4008c5f8
a013a650:  96 10 20 01  mov  1, %o3
a013a654:  30 80 00 05  b,a   0xa013a668
a013a658:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a013a65c:  80 a2 a0 00  cmp  %o2, 0
a013a660:  02 bf ff f1  be  0xa013a624
a013a664:  82 0e 20 ff  and  %i0, 0xff, %g1
a013a668:  81 c7 e0 08  ret
a013a66c:  81 e8 00 00  restore
