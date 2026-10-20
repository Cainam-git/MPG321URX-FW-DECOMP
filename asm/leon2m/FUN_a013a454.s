# leon2m FUN_a013a454 0xa013a454-0xa013a500 (172 bytes)
a013a454:  9d e3 bf 90  save  %sp, -112, %sp
a013a458:  90 10 3f ff  mov  -1, %o0
a013a45c:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a013a460:  90 10 20 02  mov  2, %o0
a013a464:  92 10 20 20  mov  0x20, %o1
a013a468:  94 07 bf f4  add  %fp, -12, %o2
a013a46c:  67 fd 48 19  call  0x4008c4d0
a013a470:  96 10 20 01  mov  1, %o3
a013a474:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013a478:  80 a0 60 00  cmp  %g1, 0
a013a47c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013a480:  02 80 00 10  be  0xa013a4c0
a013a484:  a0 10 20 64  mov  0x64, %l0
a013a488:  67 fd 4b 46  call  0x4008d1a0
a013a48c:  90 10 20 01  mov  1, %o0
a013a490:  90 10 20 02  mov  2, %o0
a013a494:  92 10 20 20  mov  0x20, %o1
a013a498:  94 07 bf f4  add  %fp, -12, %o2
a013a49c:  67 fd 48 0d  call  0x4008c4d0
a013a4a0:  96 10 20 01  mov  1, %o3
a013a4a4:  a0 04 3f ff  add  %l0, -1, %l0
a013a4a8:  80 a4 20 00  cmp  %l0, 0
a013a4ac:  02 80 00 0f  be  0xa013a4e8
a013a4b0:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a013a4b4:  80 a2 60 00  cmp  %o1, 0
a013a4b8:  12 bf ff f4  bne  0xa013a488
a013a4bc:  01 00 00 00  nop
a013a4c0:  98 0e 20 ff  and  %i0, 0xff, %o4
a013a4c4:  1b 14 00 00  sethi  %hi(0x50000000), %o5
a013a4c8:  96 13 00 0d  or  %o4, %o5, %o3
a013a4cc:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a013a4d0:  90 10 20 02  mov  2, %o0
a013a4d4:  92 10 20 20  mov  0x20, %o1
a013a4d8:  94 07 bf f4  add  %fp, -12, %o2
a013a4dc:  67 fd 48 47  call  0x4008c5f8
a013a4e0:  96 10 20 01  mov  1, %o3
a013a4e4:  30 80 00 05  b,a   0xa013a4f8
a013a4e8:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a013a4ec:  80 a2 a0 00  cmp  %o2, 0
a013a4f0:  02 bf ff f5  be  0xa013a4c4
a013a4f4:  98 0e 20 ff  and  %i0, 0xff, %o4
a013a4f8:  81 c7 e0 08  ret
a013a4fc:  81 e8 00 00  restore
