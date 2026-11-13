# leon2m FUN_a008e270 0xa008e270-0xa008e520 (688 bytes)
a008e270:  9d e3 bf 98  save  %sp, -104, %sp
a008e274:  37 2a 00 ab  sethi  %hi(0xa802ac00), %i3
a008e278:  d8 0e e3 bd  ldub  [ %i3 + 0x3bd ], %o4	! 0xa802afbd
a008e27c:  82 0b 20 ff  and  %o4, 0xff, %g1
a008e280:  80 a0 60 12  cmp  %g1, 0x12
a008e284:  02 80 00 3d  be  0xa008e378
a008e288:  80 a0 60 1c  cmp  %g1, 0x1c
a008e28c:  02 80 00 9e  be  0xa008e504
a008e290:  80 a0 60 14  cmp  %g1, 0x14
a008e294:  02 80 00 68  be  0xa008e434
a008e298:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a008e29c:  98 0b 20 ff  and  %o4, 0xff, %o4
a008e2a0:  9e 03 00 0c  add  %o4, %o4, %o7
a008e2a4:  15 00 04 00  sethi  %hi(0x100000), %o2
a008e2a8:  92 03 c0 0c  add  %o7, %o4, %o1
a008e2ac:  b8 12 a2 42  or  %o2, 0x242, %i4
a008e2b0:  96 02 40 1c  add  %o1, %i4, %o3
a008e2b4:  d0 0f 00 09  ldub  [ %i4 + %o1 ], %o0
a008e2b8:  d4 0a e0 02  ldub  [ %o3 + 2 ], %o2
a008e2bc:  d2 0a e0 01  ldub  [ %o3 + 1 ], %o1
a008e2c0:  96 10 27 90  mov  0x790, %o3
a008e2c4:  40 02 e1 ef  call  0xa0146a80
a008e2c8:  98 10 20 00  clr  %o4
a008e2cc:  da 0e e3 bd  ldub  [ %i3 + 0x3bd ], %o5
a008e2d0:  90 03 7f ff  add  %o5, -1, %o0
a008e2d4:  b6 0a 20 ff  and  %o0, 0xff, %i3
a008e2d8:  80 a6 e0 0b  cmp  %i3, 0xb
a008e2dc:  08 80 00 1a  bleu  0xa008e344
a008e2e0:  9a 0b 60 ff  and  %o5, 0xff, %o5
a008e2e4:  80 a3 60 11  cmp  %o5, 0x11
a008e2e8:  02 80 00 65  be  0xa008e47c
a008e2ec:  80 a3 60 13  cmp  %o5, 0x13
a008e2f0:  02 80 00 46  be  0xa008e408
a008e2f4:  80 a3 60 18  cmp  %o5, 0x18
a008e2f8:  02 80 00 6c  be  0xa008e4a8
a008e2fc:  80 a3 60 10  cmp  %o5, 0x10
a008e300:  02 80 00 6d  be  0xa008e4b4
a008e304:  80 a3 60 0f  cmp  %o5, 0xf
a008e308:  02 80 00 74  be  0xa008e4d8
a008e30c:  80 a3 60 14  cmp  %o5, 0x14
a008e310:  22 80 00 7b  be,a   0xa008e4fc
a008e314:  82 07 20 3c  add  %i4, 0x3c, %g1
a008e318:  82 03 40 0d  add  %o5, %o5, %g1
a008e31c:  b6 00 40 0d  add  %g1, %o5, %i3
a008e320:  9e 06 c0 1c  add  %i3, %i4, %o7
a008e324:  f0 0f 00 1b  ldub  [ %i4 + %i3 ], %i0
a008e328:  f2 0b e0 02  ldub  [ %o7 + 2 ], %i1
a008e32c:  b4 06 00 19  add  %i0, %i1, %i2
a008e330:  99 2e a0 10  sll  %i2, 0x10, %o4
a008e334:  b1 33 20 10  srl  %o4, 0x10, %i0
a008e338:  f2 0b e0 01  ldub  [ %o7 + 1 ], %i1
a008e33c:  10 80 00 0c  b  0xa008e36c
a008e340:  b4 10 20 04  mov  4, %i2
a008e344:  90 03 40 0d  add  %o5, %o5, %o0
a008e348:  82 02 00 0d  add  %o0, %o5, %g1
a008e34c:  b4 00 40 1c  add  %g1, %i4, %i2
a008e350:  f6 0f 00 01  ldub  [ %i4 + %g1 ], %i3
a008e354:  f8 0e a0 02  ldub  [ %i2 + 2 ], %i4
a008e358:  b2 06 c0 1c  add  %i3, %i4, %i1
a008e35c:  b1 2e 60 10  sll  %i1, 0x10, %i0
a008e360:  f2 0e a0 01  ldub  [ %i2 + 1 ], %i1
a008e364:  b1 36 20 10  srl  %i0, 0x10, %i0
a008e368:  b4 10 20 03  mov  3, %i2
a008e36c:  b6 10 20 90  mov  0x90, %i3
a008e370:  40 02 e1 c4  call  0xa0146a80
a008e374:  99 e8 20 00  restore  %g0, 0, %o4
a008e378:  40 00 0b 0a  call  0xa0090fa0
a008e37c:  90 10 21 11  mov  0x111, %o0
a008e380:  90 10 20 00  clr  %o0
a008e384:  40 02 e2 8f  call  0xa0146dc0
a008e388:  92 10 20 00  clr  %o1
a008e38c:  40 01 38 14  call  0xa00dc3dc
a008e390:  01 00 00 00  nop
a008e394:  90 10 20 0b  mov  0xb, %o0	! 0xb
a008e398:  40 02 de 31  call  0xa0145c5c
a008e39c:  92 10 20 00  clr  %o1
a008e3a0:  90 10 20 0a  mov  0xa, %o0
a008e3a4:  40 02 de 2e  call  0xa0145c5c
a008e3a8:  92 10 20 00  clr  %o1
a008e3ac:  90 10 20 0d  mov  0xd, %o0
a008e3b0:  40 02 de 2b  call  0xa0145c5c
a008e3b4:  92 10 20 00  clr  %o1
a008e3b8:  90 10 20 0c  mov  0xc, %o0
a008e3bc:  40 02 de 28  call  0xa0145c5c
a008e3c0:  92 10 20 00  clr  %o1
a008e3c4:  90 10 20 10  mov  0x10, %o0
a008e3c8:  40 02 de 25  call  0xa0145c5c
a008e3cc:  92 10 20 00  clr  %o1
a008e3d0:  90 10 20 0e  mov  0xe, %o0
a008e3d4:  40 02 de 22  call  0xa0145c5c
a008e3d8:  92 10 20 00  clr  %o1
a008e3dc:  90 10 20 0f  mov  0xf, %o0
a008e3e0:  40 02 de 1f  call  0xa0145c5c
a008e3e4:  92 10 20 00  clr  %o1
a008e3e8:  40 02 db de  call  0xa0145360
a008e3ec:  90 10 20 01  mov  1, %o0
a008e3f0:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a008e3f4:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a008e3f8:  82 12 20 04  or  %o0, 4, %g1
a008e3fc:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a008e400:  7f ff fb be  call  0xa008d2f8
a008e404:  81 e8 00 00  restore
a008e408:  82 07 20 39  add  %i4, 0x39, %g1
a008e40c:  f0 0f 20 39  ldub  [ %i4 + 0x39 ], %i0
a008e410:  d4 08 60 02  ldub  [ %g1 + 2 ], %o2
a008e414:  92 06 00 0a  add  %i0, %o2, %o1
a008e418:  97 2a 60 10  sll  %o1, 0x10, %o3
a008e41c:  b1 32 e0 10  srl  %o3, 0x10, %i0
a008e420:  f2 08 60 01  ldub  [ %g1 + 1 ], %i1
a008e424:  b4 10 20 0a  mov  0xa, %i2
a008e428:  b6 10 20 90  mov  0x90, %i3
a008e42c:  40 02 e1 95  call  0xa0146a80
a008e430:  99 e8 20 00  restore  %g0, 0, %o4
a008e434:  98 10 62 90  or  %g1, 0x290, %o4
a008e438:  f8 03 21 d4  ld  [ %o4 + 0x1d4 ], %i4
a008e43c:  9b 37 20 06  srl  %i4, 6, %o5
a008e440:  b4 0b 60 01  and  %o5, 1, %i2
a008e444:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a008e448:  f0 0b 21 d8  ldub  [ %o4 + 0x1d8 ], %i0
a008e44c:  9e 17 20 40  or  %i4, 0x40, %o7
a008e450:  f4 2e 63 be  stb  %i2, [ %i1 + 0x3be ]
a008e454:  f0 2b 20 09  stb  %i0, [ %o4 + 9 ]
a008e458:  de 23 21 d4  st  %o7, [ %o4 + 0x1d4 ]
a008e45c:  40 01 2a 1e  call  0xa00d8cd4
a008e460:  01 00 00 00  nop
a008e464:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a008e468:  d6 0a 60 8e  ldub  [ %o1 + 0x8e ], %o3	! 0xa802b08e
a008e46c:  94 12 e0 08  or  %o3, 8, %o2
a008e470:  d4 2a 60 8e  stb  %o2, [ %o1 + 0x8e ]
a008e474:  10 bf ff 8a  b  0xa008e29c
a008e478:  d8 0e e3 bd  ldub  [ %i3 + 0x3bd ], %o4
a008e47c:  82 07 20 33  add  %i4, 0x33, %g1
a008e480:  f0 0f 20 33  ldub  [ %i4 + 0x33 ], %i0
a008e484:  d4 08 60 02  ldub  [ %g1 + 2 ], %o2
a008e488:  92 06 00 0a  add  %i0, %o2, %o1
a008e48c:  97 2a 60 10  sll  %o1, 0x10, %o3
a008e490:  b1 32 e0 10  srl  %o3, 0x10, %i0
a008e494:  f2 08 60 01  ldub  [ %g1 + 1 ], %i1
a008e498:  b4 10 20 05  mov  5, %i2
a008e49c:  b6 10 20 90  mov  0x90, %i3
a008e4a0:  40 02 e1 78  call  0xa0146a80
a008e4a4:  99 e8 20 00  restore  %g0, 0, %o4
a008e4a8:  82 07 20 48  add  %i4, 0x48, %g1
a008e4ac:  10 bf ff d9  b  0xa008e410
a008e4b0:  f0 0f 20 48  ldub  [ %i4 + 0x48 ], %i0
a008e4b4:  9e 07 20 30  add  %i4, 0x30, %o7
a008e4b8:  f0 0f 20 30  ldub  [ %i4 + 0x30 ], %i0
a008e4bc:  f2 0b e0 02  ldub  [ %o7 + 2 ], %i1
a008e4c0:  b4 06 00 19  add  %i0, %i1, %i2
a008e4c4:  99 2e a0 10  sll  %i2, 0x10, %o4
a008e4c8:  b1 33 20 10  srl  %o4, 0x10, %i0
a008e4cc:  f2 0b e0 01  ldub  [ %o7 + 1 ], %i1
a008e4d0:  10 bf ff a7  b  0xa008e36c
a008e4d4:  b4 10 20 01  mov  1, %i2
a008e4d8:  b6 07 20 2d  add  %i4, 0x2d, %i3
a008e4dc:  d0 0f 20 2d  ldub  [ %i4 + 0x2d ], %o0
a008e4e0:  da 0e e0 02  ldub  [ %i3 + 2 ], %o5
a008e4e4:  82 02 00 0d  add  %o0, %o5, %g1
a008e4e8:  b9 28 60 10  sll  %g1, 0x10, %i4
a008e4ec:  b1 37 20 10  srl  %i4, 0x10, %i0
a008e4f0:  f2 0e e0 01  ldub  [ %i3 + 1 ], %i1
a008e4f4:  10 bf ff 9e  b  0xa008e36c
a008e4f8:  b4 10 20 06  mov  6, %i2
a008e4fc:  10 bf ff e2  b  0xa008e484
a008e500:  f0 0f 20 3c  ldub  [ %i4 + 0x3c ], %i0
a008e504:  40 00 0a b5  call  0xa0090fd8
a008e508:  39 2a 00 ab  sethi  %hi(0xa802ac00), %i4
a008e50c:  40 00 9a f3  call  0xa00b50d8
a008e510:  90 10 20 00  clr  %o0
a008e514:  c0 2f 23 bb  clrb  [ %i4 + 0x3bb ]
a008e518:  81 c7 e0 08  ret
a008e51c:  81 e8 00 00  restore
