# leon2m FUN_a013a3a8 0xa013a3a8-0xa013a454 (172 bytes)
a013a3a8:  9d e3 bf 90  save  %sp, -112, %sp
a013a3ac:  90 10 3f ff  mov  -1, %o0
a013a3b0:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a013a3b4:  90 10 20 02  mov  2, %o0
a013a3b8:  92 10 20 20  mov  0x20, %o1
a013a3bc:  94 07 bf f4  add  %fp, -12, %o2
a013a3c0:  67 fd 48 44  call  0x4008c4d0
a013a3c4:  96 10 20 01  mov  1, %o3
a013a3c8:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013a3cc:  80 a0 60 00  cmp  %g1, 0
a013a3d0:  02 80 00 10  be  0xa013a410
a013a3d4:  a0 10 20 64  mov  0x64, %l0
a013a3d8:  67 fd 4b 72  call  0x4008d1a0
a013a3dc:  90 10 20 01  mov  1, %o0
a013a3e0:  90 10 20 02  mov  2, %o0
a013a3e4:  92 10 20 20  mov  0x20, %o1
a013a3e8:  94 07 bf f4  add  %fp, -12, %o2
a013a3ec:  67 fd 48 39  call  0x4008c4d0
a013a3f0:  96 10 20 01  mov  1, %o3
a013a3f4:  a0 04 3f ff  add  %l0, -1, %l0
a013a3f8:  80 a4 20 00  cmp  %l0, 0
a013a3fc:  02 80 00 10  be  0xa013a43c
a013a400:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a013a404:  80 a2 60 00  cmp  %o1, 0
a013a408:  12 bf ff f4  bne  0xa013a3d8
a013a40c:  01 00 00 00  nop
a013a410:  9f 2e 20 10  sll  %i0, 0x10, %o7
a013a414:  99 33 e0 10  srl  %o7, 0x10, %o4
a013a418:  1b 0f c0 00  sethi  %hi(0x3f000000), %o5
a013a41c:  96 13 00 0d  or  %o4, %o5, %o3
a013a420:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a013a424:  90 10 20 02  mov  2, %o0
a013a428:  92 10 20 20  mov  0x20, %o1
a013a42c:  94 07 bf f4  add  %fp, -12, %o2
a013a430:  67 fd 48 72  call  0x4008c5f8
a013a434:  96 10 20 01  mov  1, %o3
a013a438:  30 80 00 05  b,a   0xa013a44c
a013a43c:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a013a440:  80 a2 a0 00  cmp  %o2, 0
a013a444:  02 bf ff f4  be  0xa013a414
a013a448:  9f 2e 20 10  sll  %i0, 0x10, %o7
a013a44c:  81 c7 e0 08  ret
a013a450:  81 e8 00 00  restore
