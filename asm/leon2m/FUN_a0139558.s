# leon2m FUN_a0139558 0xa0139558-0xa0139604 (172 bytes)
a0139558:  9d e3 bf 90  save  %sp, -112, %sp
a013955c:  90 10 3f ff  mov  -1, %o0
a0139560:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a0139564:  90 10 20 02  mov  2, %o0
a0139568:  92 10 20 20  mov  0x20, %o1
a013956c:  94 07 bf f4  add  %fp, -12, %o2
a0139570:  67 fd 4b d8  call  0x4008c4d0
a0139574:  96 10 20 01  mov  1, %o3
a0139578:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013957c:  80 a0 60 00  cmp  %g1, 0
a0139580:  02 80 00 10  be  0xa01395c0
a0139584:  a0 10 20 64  mov  0x64, %l0
a0139588:  67 fd 4f 06  call  0x4008d1a0
a013958c:  90 10 20 01  mov  1, %o0
a0139590:  90 10 20 02  mov  2, %o0
a0139594:  92 10 20 20  mov  0x20, %o1
a0139598:  94 07 bf f4  add  %fp, -12, %o2
a013959c:  67 fd 4b cd  call  0x4008c4d0
a01395a0:  96 10 20 01  mov  1, %o3
a01395a4:  a0 04 3f ff  add  %l0, -1, %l0
a01395a8:  80 a4 20 00  cmp  %l0, 0
a01395ac:  02 80 00 10  be  0xa01395ec
a01395b0:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a01395b4:  80 a2 60 00  cmp  %o1, 0
a01395b8:  12 bf ff f4  bne  0xa0139588
a01395bc:  01 00 00 00  nop
a01395c0:  9f 2e 20 10  sll  %i0, 0x10, %o7
a01395c4:  99 33 e0 10  srl  %o7, 0x10, %o4
a01395c8:  1b 0c 40 40  sethi  %hi(0x31010000), %o5
a01395cc:  96 13 00 0d  or  %o4, %o5, %o3
a01395d0:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a01395d4:  90 10 20 02  mov  2, %o0
a01395d8:  92 10 20 20  mov  0x20, %o1
a01395dc:  94 07 bf f4  add  %fp, -12, %o2
a01395e0:  67 fd 4c 06  call  0x4008c5f8
a01395e4:  96 10 20 01  mov  1, %o3
a01395e8:  30 80 00 05  b,a   0xa01395fc
a01395ec:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a01395f0:  80 a2 a0 00  cmp  %o2, 0
a01395f4:  02 bf ff f4  be  0xa01395c4
a01395f8:  9f 2e 20 10  sll  %i0, 0x10, %o7
a01395fc:  81 c7 e0 08  ret
a0139600:  81 e8 00 00  restore
