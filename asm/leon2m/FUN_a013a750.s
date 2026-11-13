# leon2m FUN_a013a750 0xa013a750-0xa013a7f4 (164 bytes)
a013a750:  9d e3 bf 90  save  %sp, -112, %sp
a013a754:  90 10 3f ff  mov  -1, %o0
a013a758:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a013a75c:  90 10 20 02  mov  2, %o0
a013a760:  92 10 20 20  mov  0x20, %o1
a013a764:  94 07 bf f4  add  %fp, -12, %o2
a013a768:  67 fd 47 5a  call  0x4008c4d0
a013a76c:  96 10 20 01  mov  1, %o3
a013a770:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013a774:  80 a0 60 00  cmp  %g1, 0
a013a778:  02 80 00 10  be  0xa013a7b8
a013a77c:  a0 10 20 64  mov  0x64, %l0
a013a780:  67 fd 4a 88  call  0x4008d1a0
a013a784:  90 10 20 01  mov  1, %o0
a013a788:  90 10 20 02  mov  2, %o0
a013a78c:  92 10 20 20  mov  0x20, %o1
a013a790:  94 07 bf f4  add  %fp, -12, %o2
a013a794:  67 fd 47 4f  call  0x4008c4d0
a013a798:  96 10 20 01  mov  1, %o3
a013a79c:  a0 04 3f ff  add  %l0, -1, %l0
a013a7a0:  80 a4 20 00  cmp  %l0, 0
a013a7a4:  02 80 00 0e  be  0xa013a7dc
a013a7a8:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a013a7ac:  80 a2 60 00  cmp  %o1, 0
a013a7b0:  12 bf ff f4  bne  0xa013a780
a013a7b4:  01 00 00 00  nop
a013a7b8:  19 10 00 00  sethi  %hi(0x40000000), %o4
a013a7bc:  96 13 20 01  or  %o4, 1, %o3	! 0x40000001
a013a7c0:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a013a7c4:  90 10 20 02  mov  2, %o0
a013a7c8:  92 10 20 20  mov  0x20, %o1
a013a7cc:  94 07 bf f4  add  %fp, -12, %o2
a013a7d0:  67 fd 47 8a  call  0x4008c5f8
a013a7d4:  96 10 20 01  mov  1, %o3
a013a7d8:  30 80 00 05  b,a   0xa013a7ec
a013a7dc:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a013a7e0:  80 a2 a0 00  cmp  %o2, 0
a013a7e4:  02 bf ff f6  be  0xa013a7bc
a013a7e8:  19 10 00 00  sethi  %hi(0x40000000), %o4
a013a7ec:  81 c7 e0 08  ret
a013a7f0:  81 e8 00 00  restore
