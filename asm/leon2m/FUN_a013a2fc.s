# leon2m FUN_a013a2fc 0xa013a2fc-0xa013a3a8 (172 bytes)
a013a2fc:  9d e3 bf 90  save  %sp, -112, %sp
a013a300:  90 10 3f ff  mov  -1, %o0
a013a304:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a013a308:  90 10 20 02  mov  2, %o0
a013a30c:  92 10 20 20  mov  0x20, %o1
a013a310:  94 07 bf f4  add  %fp, -12, %o2
a013a314:  67 fd 48 6f  call  0x4008c4d0
a013a318:  96 10 20 01  mov  1, %o3
a013a31c:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013a320:  80 a0 60 00  cmp  %g1, 0
a013a324:  02 80 00 10  be  0xa013a364
a013a328:  a0 10 20 64  mov  0x64, %l0
a013a32c:  67 fd 4b 9d  call  0x4008d1a0
a013a330:  90 10 20 01  mov  1, %o0
a013a334:  90 10 20 02  mov  2, %o0
a013a338:  92 10 20 20  mov  0x20, %o1
a013a33c:  94 07 bf f4  add  %fp, -12, %o2
a013a340:  67 fd 48 64  call  0x4008c4d0
a013a344:  96 10 20 01  mov  1, %o3
a013a348:  a0 04 3f ff  add  %l0, -1, %l0
a013a34c:  80 a4 20 00  cmp  %l0, 0
a013a350:  02 80 00 10  be  0xa013a390
a013a354:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a013a358:  80 a2 60 00  cmp  %o1, 0
a013a35c:  12 bf ff f4  bne  0xa013a32c
a013a360:  01 00 00 00  nop
a013a364:  9f 2e 20 10  sll  %i0, 0x10, %o7
a013a368:  99 33 e0 10  srl  %o7, 0x10, %o4
a013a36c:  1b 0f 80 00  sethi  %hi(0x3e000000), %o5
a013a370:  96 13 00 0d  or  %o4, %o5, %o3
a013a374:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a013a378:  90 10 20 02  mov  2, %o0
a013a37c:  92 10 20 20  mov  0x20, %o1
a013a380:  94 07 bf f4  add  %fp, -12, %o2
a013a384:  67 fd 48 9d  call  0x4008c5f8
a013a388:  96 10 20 01  mov  1, %o3
a013a38c:  30 80 00 05  b,a   0xa013a3a0
a013a390:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a013a394:  80 a2 a0 00  cmp  %o2, 0
a013a398:  02 bf ff f4  be  0xa013a368
a013a39c:  9f 2e 20 10  sll  %i0, 0x10, %o7
a013a3a0:  81 c7 e0 08  ret
a013a3a4:  81 e8 00 00  restore
