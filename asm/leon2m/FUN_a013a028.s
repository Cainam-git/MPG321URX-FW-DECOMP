# leon2m FUN_a013a028 0xa013a028-0xa013a0d4 (172 bytes)
a013a028:  9d e3 bf 90  save  %sp, -112, %sp
a013a02c:  90 10 3f ff  mov  -1, %o0
a013a030:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a013a034:  90 10 20 02  mov  2, %o0
a013a038:  92 10 20 20  mov  0x20, %o1
a013a03c:  94 07 bf f4  add  %fp, -12, %o2
a013a040:  67 fd 49 24  call  0x4008c4d0
a013a044:  96 10 20 01  mov  1, %o3
a013a048:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013a04c:  80 a0 60 00  cmp  %g1, 0
a013a050:  02 80 00 10  be  0xa013a090
a013a054:  a0 10 20 64  mov  0x64, %l0
a013a058:  67 fd 4c 52  call  0x4008d1a0
a013a05c:  90 10 20 01  mov  1, %o0
a013a060:  90 10 20 02  mov  2, %o0
a013a064:  92 10 20 20  mov  0x20, %o1
a013a068:  94 07 bf f4  add  %fp, -12, %o2
a013a06c:  67 fd 49 19  call  0x4008c4d0
a013a070:  96 10 20 01  mov  1, %o3
a013a074:  a0 04 3f ff  add  %l0, -1, %l0
a013a078:  80 a4 20 00  cmp  %l0, 0
a013a07c:  02 80 00 10  be  0xa013a0bc
a013a080:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a013a084:  80 a2 60 00  cmp  %o1, 0
a013a088:  12 bf ff f4  bne  0xa013a058
a013a08c:  01 00 00 00  nop
a013a090:  9f 2e 20 10  sll  %i0, 0x10, %o7
a013a094:  99 33 e0 10  srl  %o7, 0x10, %o4
a013a098:  1b 0d 00 00  sethi  %hi(0x34000000), %o5
a013a09c:  96 13 00 0d  or  %o4, %o5, %o3
a013a0a0:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a013a0a4:  90 10 20 02  mov  2, %o0
a013a0a8:  92 10 20 20  mov  0x20, %o1
a013a0ac:  94 07 bf f4  add  %fp, -12, %o2
a013a0b0:  67 fd 49 52  call  0x4008c5f8
a013a0b4:  96 10 20 01  mov  1, %o3
a013a0b8:  30 80 00 05  b,a   0xa013a0cc
a013a0bc:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a013a0c0:  80 a2 a0 00  cmp  %o2, 0
a013a0c4:  02 bf ff f4  be  0xa013a094
a013a0c8:  9f 2e 20 10  sll  %i0, 0x10, %o7
a013a0cc:  81 c7 e0 08  ret
a013a0d0:  81 e8 00 00  restore
