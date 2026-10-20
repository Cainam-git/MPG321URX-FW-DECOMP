# leon2m FUN_a0093334 0xa0093334-0xa0093464 (304 bytes)
a0093334:  9d e3 bf 98  save  %sp, -104, %sp
a0093338:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a009333c:  98 12 a2 90  or  %o2, 0x290, %o4	! 0xa802d290
a0093340:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a0093344:  da 0b 21 82  ldub  [ %o4 + 0x182 ], %o5
a0093348:  c2 0a 60 56  ldub  [ %o1 + 0x56 ], %g1
a009334c:  80 a3 40 01  cmp  %o5, %g1
a0093350:  02 80 00 3c  be  0xa0093440
a0093354:  17 2a 00 97  sethi  %hi(0xa8025c00), %o3
a0093358:  11 00 3f ff  sethi  %hi(0xfffc00), %o0
a009335c:  da 03 21 80  ld  [ %o4 + 0x180 ], %o5
a0093360:  82 12 23 00  or  %o0, 0x300, %g1
a0093364:  a4 0b 40 01  and  %o5, %g1, %l2
a0093368:  80 a4 a1 00  cmp  %l2, 0x100
a009336c:  02 80 00 28  be  0xa009340c
a0093370:  a4 10 20 01  mov  1, %l2
a0093374:  a2 12 a2 90  or  %o2, 0x290, %l1
a0093378:  e0 0a e0 55  ldub  [ %o3 + 0x55 ], %l0
a009337c:  94 0c 20 01  and  %l0, 1, %o2
a0093380:  de 04 60 a8  ld  [ %l1 + 0xa8 ], %o7
a0093384:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0093388:  99 2a a0 0b  sll  %o2, 0xb, %o4
a009338c:  9a 0b f7 ff  and  %o7, -2049, %o5
a0093390:  d0 04 23 ec  ld  [ %l0 + 0x3ec ], %o0
a0093394:  c2 0a 60 56  ldub  [ %o1 + 0x56 ], %g1
a0093398:  96 13 40 0c  or  %o5, %o4, %o3
a009339c:  94 02 3f b8  add  %o0, -72, %o2
a00933a0:  c2 2c 61 82  stb  %g1, [ %l1 + 0x182 ]
a00933a4:  d6 24 60 a8  st  %o3, [ %l1 + 0xa8 ]
a00933a8:  40 00 58 05  call  0xa00a93bc
a00933ac:  90 0a a0 ff  and  %o2, 0xff, %o0
a00933b0:  d0 0c 61 82  ldub  [ %l1 + 0x182 ], %o0
a00933b4:  40 00 58 a7  call  0xa00a9650
a00933b8:  92 10 20 00  clr  %o1
a00933bc:  90 10 20 01  mov  1, %o0
a00933c0:  d2 0c 61 82  ldub  [ %l1 + 0x182 ], %o1
a00933c4:  40 00 53 5e  call  0xa00a813c
a00933c8:  94 10 20 01  mov  1, %o2
a00933cc:  92 10 20 0e  mov  0xe, %o1
a00933d0:  d2 24 23 ec  st  %o1, [ %l0 + 0x3ec ]
a00933d4:  90 10 20 00  clr  %o0
a00933d8:  40 00 57 0d  call  0xa00a900c
a00933dc:  92 10 20 01  mov  1, %o1
a00933e0:  80 8c a0 ff  btst  0xff, %l2
a00933e4:  02 80 00 08  be  0xa0093404
a00933e8:  01 00 00 00  nop
a00933ec:  e4 04 60 a8  ld  [ %l1 + 0xa8 ], %l2
a00933f0:  80 8c a8 00  btst  0x800, %l2
a00933f4:  12 80 00 0f  bne  0xa0093430
a00933f8:  01 00 00 00  nop
a00933fc:  40 01 22 3d  call  0xa00dbcf0
a0093400:  01 00 00 00  nop
a0093404:  40 00 66 0f  call  0xa00acc40
a0093408:  81 e8 00 00  restore
a009340c:  e2 03 20 a8  ld  [ %o4 + 0xa8 ], %l1
a0093410:  a1 34 60 0b  srl  %l1, 0xb, %l0
a0093414:  98 0c 20 01  and  %l0, 1, %o4
a0093418:  de 0a e0 55  ldub  [ %o3 + 0x55 ], %o7
a009341c:  80 a3 c0 0c  cmp  %o7, %o4
a0093420:  12 bf ff d5  bne  0xa0093374
a0093424:  a4 10 20 00  clr  %l2
a0093428:  10 bf ff d3  b  0xa0093374
a009342c:  a4 10 20 01  mov  1, %l2
a0093430:  40 01 20 c2  call  0xa00db738
a0093434:  01 00 00 00  nop
a0093438:  40 00 66 02  call  0xa00acc40
a009343c:  81 e8 00 00  restore
a0093440:  e2 03 20 a8  ld  [ %o4 + 0xa8 ], %l1
a0093444:  a1 34 60 0b  srl  %l1, 0xb, %l0
a0093448:  90 0c 20 01  and  %l0, 1, %o0
a009344c:  de 0a e0 55  ldub  [ %o3 + 0x55 ], %o7
a0093450:  80 a3 c0 08  cmp  %o7, %o0
a0093454:  12 bf ff c1  bne  0xa0093358
a0093458:  a4 10 20 00  clr  %l2
a009345c:  10 bf ff c7  b  0xa0093378
a0093460:  a2 12 a2 90  or  %o2, 0x290, %l1
