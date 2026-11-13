# leon2m FUN_a013a500 0xa013a500-0xa013a5b8 (184 bytes)
a013a500:  9d e3 bf 90  save  %sp, -112, %sp
a013a504:  90 10 3f ff  mov  -1, %o0
a013a508:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a013a50c:  90 10 20 02  mov  2, %o0
a013a510:  92 10 20 20  mov  0x20, %o1
a013a514:  94 07 bf f4  add  %fp, -12, %o2
a013a518:  67 fd 47 ee  call  0x4008c4d0
a013a51c:  96 10 20 01  mov  1, %o3
a013a520:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013a524:  80 a0 60 00  cmp  %g1, 0
a013a528:  02 80 00 10  be  0xa013a568
a013a52c:  a0 10 20 64  mov  0x64, %l0
a013a530:  67 fd 4b 1c  call  0x4008d1a0
a013a534:  90 10 20 01  mov  1, %o0
a013a538:  90 10 20 02  mov  2, %o0
a013a53c:  92 10 20 20  mov  0x20, %o1
a013a540:  94 07 bf f4  add  %fp, -12, %o2
a013a544:  67 fd 47 e3  call  0x4008c4d0
a013a548:  96 10 20 01  mov  1, %o3
a013a54c:  a0 04 3f ff  add  %l0, -1, %l0
a013a550:  80 a4 20 00  cmp  %l0, 0
a013a554:  02 80 00 13  be  0xa013a5a0
a013a558:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a013a55c:  80 a2 60 00  cmp  %o1, 0
a013a560:  12 bf ff f4  bne  0xa013a530
a013a564:  01 00 00 00  nop
a013a568:  82 0e 20 ff  and  %i0, 0xff, %g1
a013a56c:  b1 28 60 10  sll  %g1, 0x10, %i0
a013a570:  a1 2e 60 10  sll  %i1, 0x10, %l0
a013a574:  19 14 40 00  sethi  %hi(0x51000000), %o4
a013a578:  9e 16 00 0c  or  %i0, %o4, %o7
a013a57c:  9b 34 20 10  srl  %l0, 0x10, %o5
a013a580:  96 13 c0 0d  or  %o7, %o5, %o3
a013a584:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a013a588:  90 10 20 02  mov  2, %o0
a013a58c:  92 10 20 20  mov  0x20, %o1
a013a590:  94 07 bf f4  add  %fp, -12, %o2
a013a594:  67 fd 48 19  call  0x4008c5f8
a013a598:  96 10 20 01  mov  1, %o3
a013a59c:  30 80 00 05  b,a   0xa013a5b0
a013a5a0:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a013a5a4:  80 a2 a0 00  cmp  %o2, 0
a013a5a8:  02 bf ff f1  be  0xa013a56c
a013a5ac:  82 0e 20 ff  and  %i0, 0xff, %g1
a013a5b0:  81 c7 e0 08  ret
a013a5b4:  81 e8 00 00  restore
