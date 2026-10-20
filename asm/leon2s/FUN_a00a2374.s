# leon2s FUN_a00a2374 0xa00a2374-0xa00a2418 (164 bytes)
a00a2374:  9d e3 bf 98  save  %sp, -104, %sp
a00a2378:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00a237c:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a2380:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00a2384:  9a 5b 60 34  smul  %o5, 0x34, %o5
a00a2388:  98 10 00 18  mov  %i0, %o4
a00a238c:  a0 03 40 01  add  %o5, %g1, %l0
a00a2390:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a2394:  82 0b 20 ff  and  %o4, 0xff, %g1
a00a2398:  90 10 20 10  mov  0x10, %o0
a00a239c:  b0 10 20 12  mov  0x12, %i0
a00a23a0:  80 a6 60 00  cmp  %i1, 0
a00a23a4:  12 80 00 07  bne  0xa00a23c0
a00a23a8:  19 2a 01 f6  sethi  %hi(0xa807d800), %o4
a00a23ac:  d2 04 20 04  ld  [ %l0 + 4 ], %o1
a00a23b0:  40 00 14 09  call  0xa00a73d4
a00a23b4:  92 02 60 24  add  %o1, 0x24, %o1
a00a23b8:  10 80 00 0d  b  0xa00a23ec
a00a23bc:  f2 04 20 04  ld  [ %l0 + 4 ], %i1
a00a23c0:  96 13 23 00  or  %o4, 0x300, %o3
a00a23c4:  9a 58 60 34  smul  %g1, 0x34, %o5
a00a23c8:  a0 03 40 0b  add  %o5, %o3, %l0
a00a23cc:  90 10 20 10  mov  0x10, %o0
a00a23d0:  80 a6 60 02  cmp  %i1, 2
a00a23d4:  12 80 00 08  bne  0xa00a23f4
a00a23d8:  b0 10 20 12  mov  0x12, %i0
a00a23dc:  d2 04 20 04  ld  [ %l0 + 4 ], %o1
a00a23e0:  40 00 13 f3  call  0xa00a73ac
a00a23e4:  92 02 60 24  add  %o1, 0x24, %o1
a00a23e8:  f2 04 20 04  ld  [ %l0 + 4 ], %i1
a00a23ec:  40 00 13 fa  call  0xa00a73d4
a00a23f0:  93 ee 60 24  restore  %i1, 0x24, %o1
a00a23f4:  d2 04 20 04  ld  [ %l0 + 4 ], %o1
a00a23f8:  92 02 60 24  add  %o1, 0x24, %o1
a00a23fc:  40 00 13 ec  call  0xa00a73ac
a00a2400:  90 10 20 10  mov  0x10, %o0
a00a2404:  f2 04 20 04  ld  [ %l0 + 4 ], %i1
a00a2408:  b2 06 60 24  add  %i1, 0x24, %i1
a00a240c:  40 00 13 e8  call  0xa00a73ac
a00a2410:  91 e8 20 12  restore  %g0, 0x12, %o0
a00a2414:  01 00 00 00  nop
