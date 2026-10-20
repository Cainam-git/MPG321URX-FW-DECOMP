# leon2s FUN_a0061280 0xa0061280-0xa0061348 (200 bytes)
a0061280:  9d e3 bf 98  save  %sp, -104, %sp
a0061284:  c2 0e 00 00  ldub  [ %i0 ], %g1
a0061288:  80 a0 60 00  cmp  %g1, 0
a006128c:  02 80 00 2d  be  0xa0061340
a0061290:  33 30 03 00  sethi  %hi(0xc00c0000), %i1
a0061294:  b4 16 60 14  or  %i1, 0x14, %i2	! 0xc00c0014
a0061298:  1f 00 03 ff  sethi  %hi(0xffc00), %o7
a006129c:  9a 10 00 19  mov  %i1, %o5
a00612a0:  c2 06 80 00  ld  [ %i2 ], %g1
a00612a4:  80 88 60 20  btst  0x20, %g1
a00612a8:  12 80 00 0b  bne  0xa00612d4
a00612ac:  ba 10 20 00  clr  %i5
a00612b0:  b8 13 e3 fe  or  %o7, 0x3fe, %i4
a00612b4:  ba 07 60 01  inc  %i5
a00612b8:  80 a7 40 1c  cmp  %i5, %i4
a00612bc:  38 80 00 07  bgu,a   0xa00612d8
a00612c0:  c2 0e 00 00  ldub  [ %i0 ], %g1
a00612c4:  c2 06 80 00  ld  [ %i2 ], %g1
a00612c8:  80 88 60 20  btst  0x20, %g1
a00612cc:  22 bf ff fb  be,a   0xa00612b8
a00612d0:  ba 07 60 01  inc  %i5
a00612d4:  c2 0e 00 00  ldub  [ %i0 ], %g1
a00612d8:  c2 23 40 00  st  %g1, [ %o5 ]
a00612dc:  c2 0e 00 00  ldub  [ %i0 ], %g1
a00612e0:  80 a0 60 0a  cmp  %g1, 0xa
a00612e4:  32 80 00 13  bne,a   0xa0061330
a00612e8:  b0 06 20 01  inc  %i0
a00612ec:  c2 06 80 00  ld  [ %i2 ], %g1
a00612f0:  b6 10 00 1a  mov  %i2, %i3
a00612f4:  80 88 60 20  btst  0x20, %g1
a00612f8:  12 80 00 0b  bne  0xa0061324
a00612fc:  ba 10 20 00  clr  %i5
a0061300:  b8 13 e3 fe  or  %o7, 0x3fe, %i4
a0061304:  ba 07 60 01  inc  %i5
a0061308:  80 a7 40 1c  cmp  %i5, %i4
a006130c:  18 80 00 07  bgu  0xa0061328
a0061310:  82 10 20 0d  mov  0xd, %g1
a0061314:  c2 06 c0 00  ld  [ %i3 ], %g1
a0061318:  80 88 60 20  btst  0x20, %g1
a006131c:  22 bf ff fb  be,a   0xa0061308
a0061320:  ba 07 60 01  inc  %i5
a0061324:  82 10 20 0d  mov  0xd, %g1
a0061328:  c2 26 40 00  st  %g1, [ %i1 ]
a006132c:  b0 06 20 01  inc  %i0
a0061330:  c2 0e 00 00  ldub  [ %i0 ], %g1
a0061334:  80 a0 60 00  cmp  %g1, 0
a0061338:  12 bf ff da  bne  0xa00612a0
a006133c:  01 00 00 00  nop
a0061340:  81 c7 e0 08  ret
a0061344:  81 e8 00 00  restore
