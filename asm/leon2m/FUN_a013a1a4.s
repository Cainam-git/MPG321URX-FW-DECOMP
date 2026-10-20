# leon2m FUN_a013a1a4 0xa013a1a4-0xa013a250 (172 bytes)
a013a1a4:  9d e3 bf 90  save  %sp, -112, %sp
a013a1a8:  90 10 3f ff  mov  -1, %o0
a013a1ac:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a013a1b0:  90 10 20 02  mov  2, %o0
a013a1b4:  92 10 20 20  mov  0x20, %o1
a013a1b8:  94 07 bf f4  add  %fp, -12, %o2
a013a1bc:  67 fd 48 c5  call  0x4008c4d0
a013a1c0:  96 10 20 01  mov  1, %o3
a013a1c4:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013a1c8:  80 a0 60 00  cmp  %g1, 0
a013a1cc:  02 80 00 10  be  0xa013a20c
a013a1d0:  a0 10 20 64  mov  0x64, %l0
a013a1d4:  67 fd 4b f3  call  0x4008d1a0
a013a1d8:  90 10 20 01  mov  1, %o0
a013a1dc:  90 10 20 02  mov  2, %o0
a013a1e0:  92 10 20 20  mov  0x20, %o1
a013a1e4:  94 07 bf f4  add  %fp, -12, %o2
a013a1e8:  67 fd 48 ba  call  0x4008c4d0
a013a1ec:  96 10 20 01  mov  1, %o3
a013a1f0:  a0 04 3f ff  add  %l0, -1, %l0
a013a1f4:  80 a4 20 00  cmp  %l0, 0
a013a1f8:  02 80 00 10  be  0xa013a238
a013a1fc:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a013a200:  80 a2 60 00  cmp  %o1, 0
a013a204:  12 bf ff f4  bne  0xa013a1d4
a013a208:  01 00 00 00  nop
a013a20c:  9f 2e 20 10  sll  %i0, 0x10, %o7
a013a210:  99 33 e0 10  srl  %o7, 0x10, %o4
a013a214:  1b 0f 00 00  sethi  %hi(0x3c000000), %o5
a013a218:  96 13 00 0d  or  %o4, %o5, %o3
a013a21c:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a013a220:  90 10 20 02  mov  2, %o0
a013a224:  92 10 20 20  mov  0x20, %o1
a013a228:  94 07 bf f4  add  %fp, -12, %o2
a013a22c:  67 fd 48 f3  call  0x4008c5f8
a013a230:  96 10 20 01  mov  1, %o3
a013a234:  30 80 00 05  b,a   0xa013a248
a013a238:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a013a23c:  80 a2 a0 00  cmp  %o2, 0
a013a240:  02 bf ff f4  be  0xa013a210
a013a244:  9f 2e 20 10  sll  %i0, 0x10, %o7
a013a248:  81 c7 e0 08  ret
a013a24c:  81 e8 00 00  restore
