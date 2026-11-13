# leon2s FUN_a0061348 0xa0061348-0xa00613cc (132 bytes)
a0061348:  9d e3 bf 98  save  %sp, -104, %sp
a006134c:  1f 30 03 00  sethi  %hi(0xc00c0000), %o7
a0061350:  96 10 00 18  mov  %i0, %o3
a0061354:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0061358:  98 10 62 08  or  %g1, 0x208, %o4	! 0xa00b3a08
a006135c:  b4 10 20 00  clr  %i2
a0061360:  b0 13 e0 14  or  %o7, 0x14, %i0
a0061364:  b6 10 20 1c  mov  0x1c, %i3
a0061368:  1b 00 03 ff  sethi  %hi(0xffc00), %o5
a006136c:  fa 06 00 00  ld  [ %i0 ], %i5
a0061370:  83 32 c0 1b  srl  %o3, %i3, %g1
a0061374:  82 08 60 0f  and  %g1, 0xf, %g1
a0061378:  80 8f 60 20  btst  0x20, %i5
a006137c:  f8 0b 00 01  ldub  [ %o4 + %g1 ], %i4
a0061380:  12 80 00 0b  bne  0xa00613ac
a0061384:  ba 10 20 00  clr  %i5
a0061388:  b2 13 63 fe  or  %o5, 0x3fe, %i1
a006138c:  ba 07 60 01  inc  %i5
a0061390:  80 a7 40 19  cmp  %i5, %i1
a0061394:  18 80 00 07  bgu  0xa00613b0
a0061398:  82 0f 20 ff  and  %i4, 0xff, %g1
a006139c:  c2 06 00 00  ld  [ %i0 ], %g1
a00613a0:  80 88 60 20  btst  0x20, %g1
a00613a4:  22 bf ff fb  be,a   0xa0061390
a00613a8:  ba 07 60 01  inc  %i5
a00613ac:  82 0f 20 ff  and  %i4, 0xff, %g1
a00613b0:  b4 06 a0 01  inc  %i2
a00613b4:  c2 23 c0 00  st  %g1, [ %o7 ]
a00613b8:  80 a6 a0 07  cmp  %i2, 7
a00613bc:  04 bf ff ec  ble  0xa006136c
a00613c0:  b6 06 ff fc  add  %i3, -4, %i3
a00613c4:  81 c7 e0 08  ret
a00613c8:  81 e8 00 00  restore
