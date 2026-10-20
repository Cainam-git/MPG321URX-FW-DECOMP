# leon2m FUN_a00fd298 0xa00fd298-0xa00fd4d0 (568 bytes)
a00fd298:  9d e3 bf 98  save  %sp, -104, %sp
a00fd29c:  15 33 c0 48  sethi  %hi(0xcf012000), %o2
a00fd2a0:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a00fd2a4:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a00fd2a8:  d0 0a 61 7d  ldub  [ %o1 + 0x17d ], %o0
a00fd2ac:  98 12 a0 84  or  %o2, 0x84, %o4
a00fd2b0:  82 10 20 46  mov  0x46, %g1
a00fd2b4:  c2 23 00 00  st  %g1, [ %o4 ]
a00fd2b8:  9a 12 e1 68  or  %o3, 0x168, %o5
a00fd2bc:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00fd2c0:  c0 2a e1 68  clrb  [ %o3 + 0x168 ]
a00fd2c4:  c0 2b 60 04  clrb  [ %o5 + 4 ]
a00fd2c8:  c0 2b 60 03  clrb  [ %o5 + 3 ]
a00fd2cc:  80 a2 20 0f  cmp  %o0, 0xf
a00fd2d0:  02 80 00 28  be  0xa00fd370
a00fd2d4:  c0 2b 60 02  clrb  [ %o5 + 2 ]
a00fd2d8:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a00fd2dc:  d8 04 a1 70  ld  [ %l2 + 0x170 ], %o4	! 0xa802c970
a00fd2e0:  9e 12 a0 34  or  %o2, 0x34, %o7
a00fd2e4:  a0 10 20 2e  mov  0x2e, %l0
a00fd2e8:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fd2ec:  80 a3 20 00  cmp  %o4, 0
a00fd2f0:  12 80 00 1d  bne  0xa00fd364
a00fd2f4:  9a 12 a0 80  or  %o2, 0x80, %o5
a00fd2f8:  a2 12 a0 40  or  %o2, 0x40, %l1
a00fd2fc:  d0 23 40 00  st  %o0, [ %o5 ]
a00fd300:  94 10 20 01  mov  1, %o2
a00fd304:  d4 24 40 00  st  %o2, [ %l1 ]
a00fd308:  67 fe 40 a0  call  0x4008d588
a00fd30c:  01 00 00 00  nop
a00fd310:  19 33 c0 48  sethi  %hi(0xcf012000), %o4
a00fd314:  82 13 20 34  or  %o4, 0x34, %g1	! 0xcf012034
a00fd318:  d6 00 40 00  ld  [ %g1 ], %o3
a00fd31c:  80 8a e0 2e  btst  0x2e, %o3
a00fd320:  12 80 00 65  bne  0xa00fd4b4
a00fd324:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00fd328:  a2 10 00 01  mov  %g1, %l1
a00fd32c:  67 fe 3e eb  call  0x4008ced8
a00fd330:  01 00 00 00  nop
a00fd334:  67 fe 40 98  call  0x4008d594
a00fd338:  91 34 20 10  srl  %l0, 0x10, %o0
a00fd33c:  93 2a 20 10  sll  %o0, 0x10, %o1
a00fd340:  83 32 60 10  srl  %o1, 0x10, %g1
a00fd344:  80 a0 63 e8  cmp  %g1, 0x3e8
a00fd348:  18 80 00 5c  bgu  0xa00fd4b8
a00fd34c:  25 33 c0 48  sethi  %hi(0xcf012000), %l2
a00fd350:  d0 04 40 00  ld  [ %l1 ], %o0
a00fd354:  80 8a 20 2e  btst  0x2e, %o0
a00fd358:  02 bf ff f5  be  0xa00fd32c
a00fd35c:  9e 14 a0 34  or  %l2, 0x34, %o7
a00fd360:  30 80 00 57  b,a   0xa00fd4bc
a00fd364:  9f c3 00 00  call  %o4
a00fd368:  92 10 20 01  mov  1, %o1
a00fd36c:  30 bf ff e7  b,a   0xa00fd308
a00fd370:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a00fd374:  90 12 a0 34  or  %o2, 0x34, %o0
a00fd378:  d8 04 a1 70  ld  [ %l2 + 0x170 ], %o4
a00fd37c:  9e 10 20 2e  mov  0x2e, %o7
a00fd380:  de 22 00 00  st  %o7, [ %o0 ]
a00fd384:  80 a3 20 00  cmp  %o4, 0
a00fd388:  12 80 00 43  bne  0xa00fd494
a00fd38c:  a2 12 a0 80  or  %o2, 0x80, %l1
a00fd390:  a0 12 a0 40  or  %o2, 0x40, %l0
a00fd394:  9a 10 20 08  mov  8, %o5
a00fd398:  da 24 40 00  st  %o5, [ %l1 ]
a00fd39c:  94 10 20 01  mov  1, %o2
a00fd3a0:  d4 24 00 00  st  %o2, [ %l0 ]
a00fd3a4:  67 fe 40 79  call  0x4008d588
a00fd3a8:  01 00 00 00  nop
a00fd3ac:  19 33 c0 48  sethi  %hi(0xcf012000), %o4
a00fd3b0:  82 13 20 34  or  %o4, 0x34, %g1	! 0xcf012034
a00fd3b4:  d6 00 40 00  ld  [ %g1 ], %o3
a00fd3b8:  80 8a e0 2e  btst  0x2e, %o3
a00fd3bc:  12 80 00 10  bne  0xa00fd3fc
a00fd3c0:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00fd3c4:  a2 10 00 01  mov  %g1, %l1
a00fd3c8:  67 fe 3e c4  call  0x4008ced8
a00fd3cc:  01 00 00 00  nop
a00fd3d0:  67 fe 40 71  call  0x4008d594
a00fd3d4:  91 34 20 10  srl  %l0, 0x10, %o0
a00fd3d8:  93 2a 20 10  sll  %o0, 0x10, %o1
a00fd3dc:  83 32 60 10  srl  %o1, 0x10, %g1
a00fd3e0:  80 a0 63 e8  cmp  %g1, 0x3e8
a00fd3e4:  18 80 00 07  bgu  0xa00fd400
a00fd3e8:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fd3ec:  d0 04 40 00  ld  [ %l1 ], %o0
a00fd3f0:  80 8a 20 2e  btst  0x2e, %o0
a00fd3f4:  02 bf ff f5  be  0xa00fd3c8
a00fd3f8:  01 00 00 00  nop
a00fd3fc:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fd400:  9e 12 e0 34  or  %o3, 0x34, %o7	! 0xcf012034
a00fd404:  d8 03 c0 00  ld  [ %o7 ], %o4
a00fd408:  a0 10 20 2e  mov  0x2e, %l0
a00fd40c:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fd410:  d8 04 a1 70  ld  [ %l2 + 0x170 ], %o4
a00fd414:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fd418:  80 a3 20 00  cmp  %o4, 0
a00fd41c:  12 80 00 22  bne  0xa00fd4a4
a00fd420:  a2 12 e0 80  or  %o3, 0x80, %l1
a00fd424:  9a 10 20 04  mov  4, %o5
a00fd428:  da 24 40 00  st  %o5, [ %l1 ]
a00fd42c:  a4 12 e0 40  or  %o3, 0x40, %l2
a00fd430:  94 10 20 01  mov  1, %o2
a00fd434:  d4 24 80 00  st  %o2, [ %l2 ]
a00fd438:  67 fe 40 54  call  0x4008d588
a00fd43c:  01 00 00 00  nop
a00fd440:  19 33 c0 48  sethi  %hi(0xcf012000), %o4
a00fd444:  82 13 20 34  or  %o4, 0x34, %g1	! 0xcf012034
a00fd448:  d6 00 40 00  ld  [ %g1 ], %o3
a00fd44c:  80 8a e0 2e  btst  0x2e, %o3
a00fd450:  12 80 00 19  bne  0xa00fd4b4
a00fd454:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00fd458:  a2 10 00 01  mov  %g1, %l1
a00fd45c:  67 fe 3e 9f  call  0x4008ced8
a00fd460:  01 00 00 00  nop
a00fd464:  67 fe 40 4c  call  0x4008d594
a00fd468:  91 34 20 10  srl  %l0, 0x10, %o0
a00fd46c:  93 2a 20 10  sll  %o0, 0x10, %o1
a00fd470:  83 32 60 10  srl  %o1, 0x10, %g1
a00fd474:  80 a0 63 e8  cmp  %g1, 0x3e8
a00fd478:  18 80 00 10  bgu  0xa00fd4b8
a00fd47c:  25 33 c0 48  sethi  %hi(0xcf012000), %l2
a00fd480:  d0 04 40 00  ld  [ %l1 ], %o0
a00fd484:  80 8a 20 2e  btst  0x2e, %o0
a00fd488:  02 bf ff f5  be  0xa00fd45c
a00fd48c:  9e 14 a0 34  or  %l2, 0x34, %o7
a00fd490:  30 80 00 0b  b,a   0xa00fd4bc
a00fd494:  90 10 20 08  mov  8, %o0
a00fd498:  9f c3 00 00  call  %o4
a00fd49c:  92 10 20 01  mov  1, %o1
a00fd4a0:  30 bf ff c1  b,a   0xa00fd3a4
a00fd4a4:  90 10 20 04  mov  4, %o0
a00fd4a8:  9f c3 00 00  call  %o4
a00fd4ac:  92 10 20 01  mov  1, %o1
a00fd4b0:  30 bf ff e2  b,a   0xa00fd438
a00fd4b4:  25 33 c0 48  sethi  %hi(0xcf012000), %l2
a00fd4b8:  9e 14 a0 34  or  %l2, 0x34, %o7	! 0xcf012034
a00fd4bc:  d8 03 c0 00  ld  [ %o7 ], %o4
a00fd4c0:  a0 10 20 2e  mov  0x2e, %l0
a00fd4c4:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fd4c8:  81 c7 e0 08  ret
a00fd4cc:  81 e8 00 00  restore
