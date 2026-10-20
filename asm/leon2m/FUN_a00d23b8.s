# leon2m FUN_a00d23b8 0xa00d23b8-0xa00d24d8 (288 bytes)
a00d23b8:  9d e3 bf 98  save  %sp, -104, %sp
a00d23bc:  c2 0e 20 06  ldub  [ %i0 + 6 ], %g1
a00d23c0:  80 a0 60 02  cmp  %g1, 2
a00d23c4:  02 80 00 13  be  0xa00d2410
a00d23c8:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a00d23cc:  04 80 00 09  ble  0xa00d23f0
a00d23d0:  80 a0 60 01  cmp  %g1, 1
a00d23d4:  80 a0 60 03  cmp  %g1, 3
a00d23d8:  02 80 00 35  be  0xa00d24ac
a00d23dc:  80 a0 60 05  cmp  %g1, 5
a00d23e0:  02 80 00 2f  be  0xa00d249c
a00d23e4:  9e 12 a1 f0  or  %o2, 0x1f0, %o7
a00d23e8:  10 80 00 3a  b  0xa00d24d0
a00d23ec:  b0 10 20 e3  mov  0xe3, %i0
a00d23f0:  32 80 00 38  bne,a   0xa00d24d0
a00d23f4:  b0 10 20 e3  mov  0xe3, %i0
a00d23f8:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a00d23fc:  82 12 a1 f0  or  %o2, 0x1f0, %g1	! 0xa802e1f0
a00d2400:  d6 08 60 08  ldub  [ %g1 + 8 ], %o3
a00d2404:  da 08 60 06  ldub  [ %g1 + 6 ], %o5
a00d2408:  10 80 00 06  b  0xa00d2420
a00d240c:  d8 08 60 07  ldub  [ %g1 + 7 ], %o4
a00d2410:  92 12 a1 f0  or  %o2, 0x1f0, %o1
a00d2414:  d6 0a 60 14  ldub  [ %o1 + 0x14 ], %o3
a00d2418:  da 0a 60 12  ldub  [ %o1 + 0x12 ], %o5
a00d241c:  d8 0a 60 13  ldub  [ %o1 + 0x13 ], %o4
a00d2420:  f0 0e 20 07  ldub  [ %i0 + 7 ], %i0
a00d2424:  80 a6 20 02  cmp  %i0, 2
a00d2428:  02 80 00 26  be  0xa00d24c0
a00d242c:  90 12 a1 f0  or  %o2, 0x1f0, %o0
a00d2430:  14 80 00 0a  bg  0xa00d2458
a00d2434:  80 a6 20 03  cmp  %i0, 3
a00d2438:  80 a6 20 01  cmp  %i0, 1
a00d243c:  32 80 00 25  bne,a   0xa00d24d0
a00d2440:  b0 10 20 e3  mov  0xe3, %i0
a00d2444:  b0 12 a1 f0  or  %o2, 0x1f0, %i0
a00d2448:  d6 2e 20 08  stb  %o3, [ %i0 + 8 ]
a00d244c:  da 2e 20 06  stb  %o5, [ %i0 + 6 ]
a00d2450:  10 80 00 0a  b  0xa00d2478
a00d2454:  d8 2e 20 07  stb  %o4, [ %i0 + 7 ]
a00d2458:  02 80 00 0c  be  0xa00d2488
a00d245c:  80 a6 20 05  cmp  %i0, 5
a00d2460:  32 80 00 1c  bne,a   0xa00d24d0
a00d2464:  b0 10 20 e3  mov  0xe3, %i0
a00d2468:  92 12 a1 f0  or  %o2, 0x1f0, %o1
a00d246c:  d6 2a 60 23  stb  %o3, [ %o1 + 0x23 ]
a00d2470:  da 2a 60 21  stb  %o5, [ %o1 + 0x21 ]
a00d2474:  d8 2a 60 22  stb  %o4, [ %o1 + 0x22 ]
a00d2478:  40 01 cb ba  call  0xa0145360
a00d247c:  90 10 20 00  clr  %o0
a00d2480:  10 80 00 14  b  0xa00d24d0
a00d2484:  b0 10 20 e0  mov  0xe0, %i0
a00d2488:  82 12 a1 f0  or  %o2, 0x1f0, %g1
a00d248c:  d6 28 60 0b  stb  %o3, [ %g1 + 0xb ]
a00d2490:  da 28 60 09  stb  %o5, [ %g1 + 9 ]
a00d2494:  10 bf ff f9  b  0xa00d2478
a00d2498:  d8 28 60 0a  stb  %o4, [ %g1 + 0xa ]
a00d249c:  d6 0b e0 23  ldub  [ %o7 + 0x23 ], %o3
a00d24a0:  da 0b e0 21  ldub  [ %o7 + 0x21 ], %o5
a00d24a4:  10 bf ff df  b  0xa00d2420
a00d24a8:  d8 0b e0 22  ldub  [ %o7 + 0x22 ], %o4
a00d24ac:  90 12 a1 f0  or  %o2, 0x1f0, %o0
a00d24b0:  d6 0a 20 0b  ldub  [ %o0 + 0xb ], %o3
a00d24b4:  da 0a 20 09  ldub  [ %o0 + 9 ], %o5
a00d24b8:  10 bf ff da  b  0xa00d2420
a00d24bc:  d8 0a 20 0a  ldub  [ %o0 + 0xa ], %o4
a00d24c0:  d6 2a 20 14  stb  %o3, [ %o0 + 0x14 ]
a00d24c4:  da 2a 20 12  stb  %o5, [ %o0 + 0x12 ]
a00d24c8:  10 bf ff ec  b  0xa00d2478
a00d24cc:  d8 2a 20 13  stb  %o4, [ %o0 + 0x13 ]
a00d24d0:  81 c7 e0 08  ret
a00d24d4:  81 e8 00 00  restore
