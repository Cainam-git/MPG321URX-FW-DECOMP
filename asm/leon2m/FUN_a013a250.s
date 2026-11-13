# leon2m FUN_a013a250 0xa013a250-0xa013a2fc (172 bytes)
a013a250:  9d e3 bf 90  save  %sp, -112, %sp
a013a254:  90 10 3f ff  mov  -1, %o0
a013a258:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a013a25c:  90 10 20 02  mov  2, %o0
a013a260:  92 10 20 20  mov  0x20, %o1
a013a264:  94 07 bf f4  add  %fp, -12, %o2
a013a268:  67 fd 48 9a  call  0x4008c4d0
a013a26c:  96 10 20 01  mov  1, %o3
a013a270:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013a274:  80 a0 60 00  cmp  %g1, 0
a013a278:  02 80 00 10  be  0xa013a2b8
a013a27c:  a0 10 20 64  mov  0x64, %l0
a013a280:  67 fd 4b c8  call  0x4008d1a0
a013a284:  90 10 20 01  mov  1, %o0
a013a288:  90 10 20 02  mov  2, %o0
a013a28c:  92 10 20 20  mov  0x20, %o1
a013a290:  94 07 bf f4  add  %fp, -12, %o2
a013a294:  67 fd 48 8f  call  0x4008c4d0
a013a298:  96 10 20 01  mov  1, %o3
a013a29c:  a0 04 3f ff  add  %l0, -1, %l0
a013a2a0:  80 a4 20 00  cmp  %l0, 0
a013a2a4:  02 80 00 10  be  0xa013a2e4
a013a2a8:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a013a2ac:  80 a2 60 00  cmp  %o1, 0
a013a2b0:  12 bf ff f4  bne  0xa013a280
a013a2b4:  01 00 00 00  nop
a013a2b8:  9f 2e 20 10  sll  %i0, 0x10, %o7
a013a2bc:  99 33 e0 10  srl  %o7, 0x10, %o4
a013a2c0:  1b 0f 40 00  sethi  %hi(0x3d000000), %o5
a013a2c4:  96 13 00 0d  or  %o4, %o5, %o3
a013a2c8:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a013a2cc:  90 10 20 02  mov  2, %o0
a013a2d0:  92 10 20 20  mov  0x20, %o1
a013a2d4:  94 07 bf f4  add  %fp, -12, %o2
a013a2d8:  67 fd 48 c8  call  0x4008c5f8
a013a2dc:  96 10 20 01  mov  1, %o3
a013a2e0:  30 80 00 05  b,a   0xa013a2f4
a013a2e4:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a013a2e8:  80 a2 a0 00  cmp  %o2, 0
a013a2ec:  02 bf ff f4  be  0xa013a2bc
a013a2f0:  9f 2e 20 10  sll  %i0, 0x10, %o7
a013a2f4:  81 c7 e0 08  ret
a013a2f8:  81 e8 00 00  restore
