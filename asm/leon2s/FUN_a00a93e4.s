# leon2s FUN_a00a93e4 0xa00a93e4-0xa00a94f4 (272 bytes)
a00a93e4:  9d e3 bf 98  save  %sp, -104, %sp
a00a93e8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a93ec:  80 a6 20 00  cmp  %i0, 0
a00a93f0:  02 80 00 05  be  0xa00a9404
a00a93f4:  80 a6 20 01  cmp  %i0, 1
a00a93f8:  02 80 00 1d  be  0xa00a946c
a00a93fc:  01 00 00 00  nop
a00a9400:  30 80 00 3b  b,a   0xa00a94ec
a00a9404:  7f ff a2 0d  call  0xa0091c38
a00a9408:  90 10 20 00  clr  %o0
a00a940c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a9410:  80 a2 20 51  cmp  %o0, 0x51
a00a9414:  12 80 00 07  bne  0xa00a9430
a00a9418:  01 00 00 00  nop
a00a941c:  7f ff a2 10  call  0xa0091c5c
a00a9420:  90 10 20 00  clr  %o0	! 0x0
a00a9424:  80 8a 20 ff  btst  0xff, %o0
a00a9428:  02 80 00 0d  be  0xa00a945c
a00a942c:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a9430:  7f ff a2 02  call  0xa0091c38
a00a9434:  90 10 20 01  mov  1, %o0
a00a9438:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a943c:  80 a2 20 51  cmp  %o0, 0x51
a00a9440:  12 80 00 09  bne  0xa00a9464
a00a9444:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a9448:  7f ff a2 05  call  0xa0091c5c
a00a944c:  90 10 20 01  mov  1, %o0
a00a9450:  80 8a 20 ff  btst  0xff, %o0
a00a9454:  12 80 00 04  bne  0xa00a9464
a00a9458:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a945c:  10 80 00 1b  b  0xa00a94c8
a00a9460:  d8 00 63 30  ld  [ %g1 + 0x330 ], %o4	! 0xa807db30
a00a9464:  10 80 00 1e  b  0xa00a94dc
a00a9468:  d8 00 63 30  ld  [ %g1 + 0x330 ], %o4
a00a946c:  7f ff a1 f3  call  0xa0091c38
a00a9470:  90 10 20 00  clr  %o0
a00a9474:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a9478:  80 a2 20 51  cmp  %o0, 0x51
a00a947c:  12 80 00 07  bne  0xa00a9498
a00a9480:  01 00 00 00  nop
a00a9484:  7f ff a1 f6  call  0xa0091c5c
a00a9488:  90 10 20 00  clr  %o0	! 0x0
a00a948c:  80 8a 20 ff  btst  0xff, %o0
a00a9490:  02 80 00 0d  be  0xa00a94c4
a00a9494:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a9498:  7f ff a1 e8  call  0xa0091c38
a00a949c:  90 10 20 01  mov  1, %o0
a00a94a0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a94a4:  80 a2 20 51  cmp  %o0, 0x51
a00a94a8:  12 80 00 0c  bne  0xa00a94d8
a00a94ac:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a94b0:  7f ff a1 eb  call  0xa0091c5c
a00a94b4:  90 10 20 01  mov  1, %o0
a00a94b8:  80 8a 20 ff  btst  0xff, %o0
a00a94bc:  12 80 00 07  bne  0xa00a94d8
a00a94c0:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a94c4:  d8 00 63 64  ld  [ %g1 + 0x364 ], %o4	! 0xa807db64
a00a94c8:  da 03 20 e8  ld  [ %o4 + 0xe8 ], %o5
a00a94cc:  03 00 20 00  sethi  %hi(0x800000), %g1
a00a94d0:  10 80 00 06  b  0xa00a94e8
a00a94d4:  82 2b 40 01  andn  %o5, %g1, %g1
a00a94d8:  d8 00 63 64  ld  [ %g1 + 0x364 ], %o4
a00a94dc:  c2 03 20 e8  ld  [ %o4 + 0xe8 ], %g1
a00a94e0:  1b 00 20 00  sethi  %hi(0x800000), %o5
a00a94e4:  82 10 40 0d  or  %g1, %o5, %g1
a00a94e8:  c2 23 20 e8  st  %g1, [ %o4 + 0xe8 ]
a00a94ec:  81 c7 e0 08  ret
a00a94f0:  81 e8 00 00  restore
