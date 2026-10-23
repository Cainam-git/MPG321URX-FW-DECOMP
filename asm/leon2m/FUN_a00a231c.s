# leon2m FUN_a00a231c 0xa00a231c-0xa00a23a4 (136 bytes)
a00a231c:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a00a2320:  da 08 60 56  ldub  [ %g1 + 0x56 ], %o5	! 0xa8025c56
a00a2324:  80 a3 60 02  cmp  %o5, 2
a00a2328:  12 80 00 1d  bne  0xa00a239c
a00a232c:  19 2a 00 ab  sethi  %hi(0xa802ac00), %o4
a00a2330:  c2 03 23 ec  ld  [ %o4 + 0x3ec ], %g1	! 0xa802afec
a00a2334:  80 a0 60 c0  cmp  %g1, 0xc0
a00a2338:  02 80 00 10  be  0xa00a2378
a00a233c:  80 a0 60 c1  cmp  %g1, 0xc1
a00a2340:  02 80 00 07  be  0xa00a235c
a00a2344:  80 a0 60 c2  cmp  %g1, 0xc2
a00a2348:  02 80 00 11  be  0xa00a238c
a00a234c:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00a2350:  82 13 c0 00  mov  %o7, %g1
a00a2354:  7f ff fd c5  call  0xa00a1a68
a00a2358:  9e 10 40 00  mov  %g1, %o7
a00a235c:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00a2360:  d8 08 60 7b  ldub  [ %g1 + 0x7b ], %o4	! 0xa802d47b
a00a2364:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a00a2368:  d8 28 60 55  stb  %o4, [ %g1 + 0x55 ]	! 0xa8025c55
a00a236c:  82 13 c0 00  mov  %o7, %g1
a00a2370:  7f ff fd be  call  0xa00a1a68
a00a2374:  9e 10 40 00  mov  %g1, %o7
a00a2378:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00a237c:  d8 0b 60 79  ldub  [ %o5 + 0x79 ], %o4	! 0xa802d479
a00a2380:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a00a2384:  10 bf ff fa  b  0xa00a236c
a00a2388:  d8 28 60 55  stb  %o4, [ %g1 + 0x55 ]	! 0xa8025c55
a00a238c:  d8 0b 60 7d  ldub  [ %o5 + 0x7d ], %o4
a00a2390:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a00a2394:  10 bf ff f6  b  0xa00a236c
a00a2398:  d8 28 60 55  stb  %o4, [ %g1 + 0x55 ]	! 0xa8025c55
a00a239c:  81 c3 e0 08  retl
a00a23a0:  01 00 00 00  nop
