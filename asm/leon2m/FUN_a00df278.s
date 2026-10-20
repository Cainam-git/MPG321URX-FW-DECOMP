# leon2m FUN_a00df278 0xa00df278-0xa00df368 (240 bytes)
a00df278:  9d e3 bf 98  save  %sp, -104, %sp
a00df27c:  40 01 e1 77  call  0xa0157858
a00df280:  90 10 00 18  mov  %i0, %o0
a00df284:  80 a6 20 00  cmp  %i0, 0
a00df288:  02 80 00 36  be  0xa00df360
a00df28c:  ac 10 00 08  mov  %o0, %l6
a00df290:  80 a2 20 01  cmp  %o0, 1
a00df294:  02 80 00 21  be  0xa00df318
a00df298:  a6 10 20 00  clr  %l3
a00df29c:  80 a4 c0 16  cmp  %l3, %l6
a00df2a0:  16 80 00 30  bge  0xa00df360
a00df2a4:  11 00 03 ff  sethi  %hi(0xffc00), %o0
a00df2a8:  ae 12 23 fe  or  %o0, 0x3fe, %l7	! 0xffffe
a00df2ac:  29 30 02 c0  sethi  %hi(0xc00b0000), %l4
a00df2b0:  aa 10 00 17  mov  %l7, %l5
a00df2b4:  e2 0e 00 13  ldub  [ %i0 + %l3 ], %l1
a00df2b8:  a0 10 20 00  clr  %l0
a00df2bc:  67 fe b3 e5  call  0x4008c250
a00df2c0:  90 15 20 14  or  %l4, 0x14, %o0
a00df2c4:  80 8a 20 20  btst  0x20, %o0
a00df2c8:  12 80 00 05  bne  0xa00df2dc
a00df2cc:  a0 04 20 01  inc  %l0
a00df2d0:  80 a4 00 15  cmp  %l0, %l5
a00df2d4:  08 bf ff fa  bleu  0xa00df2bc
a00df2d8:  01 00 00 00  nop
a00df2dc:  95 2c 60 18  sll  %l1, 0x18, %o2
a00df2e0:  93 3a a0 18  sra  %o2, 0x18, %o1
a00df2e4:  67 fe b3 de  call  0x4008c25c
a00df2e8:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00df2ec:  d2 4e 00 13  ldsb  [ %i0 + %l3 ], %o1
a00df2f0:  80 a2 60 0a  cmp  %o1, 0xa
a00df2f4:  a0 10 20 00  clr  %l0
a00df2f8:  25 30 02 c0  sethi  %hi(0xc00b0000), %l2
a00df2fc:  02 80 00 0f  be  0xa00df338
a00df300:  a2 10 00 17  mov  %l7, %l1
a00df304:  a6 04 e0 01  inc  %l3
a00df308:  80 a4 c0 16  cmp  %l3, %l6
a00df30c:  26 bf ff eb  bl,a   0xa00df2b8
a00df310:  e2 0e 00 13  ldub  [ %i0 + %l3 ], %l1
a00df314:  30 80 00 13  b,a   0xa00df360
a00df318:  c2 4e 00 00  ldsb  [ %i0 ], %g1
a00df31c:  80 a0 60 00  cmp  %g1, 0
a00df320:  02 80 00 10  be  0xa00df360
a00df324:  80 a4 c0 16  cmp  %l3, %l6
a00df328:  30 bf ff de  b,a   0xa00df2a0
a00df32c:  80 a4 00 11  cmp  %l0, %l1
a00df330:  18 80 00 08  bgu  0xa00df350
a00df334:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00df338:  67 fe b3 c6  call  0x4008c250
a00df33c:  90 14 a0 14  or  %l2, 0x14, %o0
a00df340:  80 8a 20 20  btst  0x20, %o0
a00df344:  02 bf ff fa  be  0xa00df32c
a00df348:  a0 04 20 01  inc  %l0
a00df34c:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00df350:  67 fe b3 c3  call  0x4008c25c
a00df354:  92 10 20 0d  mov  0xd, %o1
a00df358:  10 bf ff ec  b  0xa00df308
a00df35c:  a6 04 e0 01  inc  %l3
a00df360:  81 c7 e0 08  ret
a00df364:  91 e8 20 00  restore  %g0, 0, %o0
