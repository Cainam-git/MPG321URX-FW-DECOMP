# leon2s FUN_a00613cc 0xa00613cc-0xa0061450 (132 bytes)
a00613cc:  9d e3 bf 98  save  %sp, -104, %sp
a00613d0:  1b 30 03 00  sethi  %hi(0xc00c0000), %o5
a00613d4:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00613d8:  96 10 62 08  or  %g1, 0x208, %o3	! 0xa00b3a08
a00613dc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00613e0:  b4 10 20 00  clr  %i2
a00613e4:  9e 13 60 14  or  %o5, 0x14, %o7
a00613e8:  b6 10 20 04  mov  4, %i3
a00613ec:  19 00 03 ff  sethi  %hi(0xffc00), %o4
a00613f0:  fa 03 c0 00  ld  [ %o7 ], %i5
a00613f4:  83 3e 00 1b  sra  %i0, %i3, %g1
a00613f8:  82 08 60 0f  and  %g1, 0xf, %g1
a00613fc:  80 8f 60 20  btst  0x20, %i5
a0061400:  f8 0a c0 01  ldub  [ %o3 + %g1 ], %i4
a0061404:  12 80 00 0b  bne  0xa0061430
a0061408:  ba 10 20 00  clr  %i5
a006140c:  b2 13 23 fe  or  %o4, 0x3fe, %i1
a0061410:  ba 07 60 01  inc  %i5
a0061414:  80 a7 40 19  cmp  %i5, %i1
a0061418:  18 80 00 07  bgu  0xa0061434
a006141c:  82 0f 20 ff  and  %i4, 0xff, %g1
a0061420:  c2 03 c0 00  ld  [ %o7 ], %g1
a0061424:  80 88 60 20  btst  0x20, %g1
a0061428:  22 bf ff fb  be,a   0xa0061414
a006142c:  ba 07 60 01  inc  %i5
a0061430:  82 0f 20 ff  and  %i4, 0xff, %g1
a0061434:  b4 06 a0 01  inc  %i2
a0061438:  c2 23 40 00  st  %g1, [ %o5 ]
a006143c:  80 a6 a0 01  cmp  %i2, 1
a0061440:  04 bf ff ec  ble  0xa00613f0
a0061444:  b6 06 ff fc  add  %i3, -4, %i3
a0061448:  81 c7 e0 08  ret
a006144c:  81 e8 00 00  restore
