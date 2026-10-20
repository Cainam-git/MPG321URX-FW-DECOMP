# leon2m FUN_a013a98c 0xa013a98c-0xa013aa38 (172 bytes)
a013a98c:  9d e3 bf 90  save  %sp, -112, %sp
a013a990:  90 10 3f ff  mov  -1, %o0
a013a994:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a013a998:  90 10 20 02  mov  2, %o0
a013a99c:  92 10 20 20  mov  0x20, %o1
a013a9a0:  94 07 bf f4  add  %fp, -12, %o2
a013a9a4:  67 fd 46 cb  call  0x4008c4d0
a013a9a8:  96 10 20 01  mov  1, %o3
a013a9ac:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013a9b0:  80 a0 60 00  cmp  %g1, 0
a013a9b4:  02 80 00 10  be  0xa013a9f4
a013a9b8:  a0 10 20 64  mov  0x64, %l0
a013a9bc:  67 fd 49 f9  call  0x4008d1a0
a013a9c0:  90 10 20 01  mov  1, %o0
a013a9c4:  90 10 20 02  mov  2, %o0
a013a9c8:  92 10 20 20  mov  0x20, %o1
a013a9cc:  94 07 bf f4  add  %fp, -12, %o2
a013a9d0:  67 fd 46 c0  call  0x4008c4d0
a013a9d4:  96 10 20 01  mov  1, %o3
a013a9d8:  a0 04 3f ff  add  %l0, -1, %l0
a013a9dc:  80 a4 20 00  cmp  %l0, 0
a013a9e0:  02 80 00 10  be  0xa013aa20
a013a9e4:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a013a9e8:  80 a2 60 00  cmp  %o1, 0
a013a9ec:  12 bf ff f4  bne  0xa013a9bc
a013a9f0:  01 00 00 00  nop
a013a9f4:  9f 2e 20 10  sll  %i0, 0x10, %o7
a013a9f8:  99 33 e0 10  srl  %o7, 0x10, %o4
a013a9fc:  1b 25 c0 00  sethi  %hi(0x97000000), %o5
a013aa00:  96 13 00 0d  or  %o4, %o5, %o3
a013aa04:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a013aa08:  90 10 20 02  mov  2, %o0
a013aa0c:  92 10 20 20  mov  0x20, %o1
a013aa10:  94 07 bf f4  add  %fp, -12, %o2
a013aa14:  67 fd 46 f9  call  0x4008c5f8
a013aa18:  96 10 20 01  mov  1, %o3
a013aa1c:  30 80 00 05  b,a   0xa013aa30
a013aa20:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a013aa24:  80 a2 a0 00  cmp  %o2, 0
a013aa28:  02 bf ff f4  be  0xa013a9f8
a013aa2c:  9f 2e 20 10  sll  %i0, 0x10, %o7
a013aa30:  81 c7 e0 08  ret
a013aa34:  81 e8 00 00  restore
