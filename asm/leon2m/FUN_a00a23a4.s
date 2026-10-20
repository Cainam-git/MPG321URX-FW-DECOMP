# leon2m FUN_a00a23a4 0xa00a23a4-0xa00a2548 (312 bytes)
a00a23a4:  9d e3 bf 98  save  %sp, -104, %sp
a00a23a8:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00a23ac:  c2 0c 20 56  ldub  [ %l0 + 0x56 ], %g1	! 0xa8025c56
a00a23b0:  80 a0 60 01  cmp  %g1, 1
a00a23b4:  04 80 00 07  ble  0xa00a23d0
a00a23b8:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00a23bc:  80 a0 60 02  cmp  %g1, 2
a00a23c0:  12 80 00 60  bne  0xa00a2540
a00a23c4:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00a23c8:  10 80 00 23  b  0xa00a2454
a00a23cc:  e4 08 60 7b  ldub  [ %g1 + 0x7b ], %l2	! 0xa802d47b
a00a23d0:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1
a00a23d4:  82 00 7f 40  add  %g1, -192, %g1
a00a23d8:  80 a0 60 39  cmp  %g1, 0x39
a00a23dc:  08 80 00 18  bleu  0xa00a243c
a00a23e0:  92 10 20 00  clr  %o1
a00a23e4:  92 10 20 00  clr  %o1
a00a23e8:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00a23ec:  94 10 20 00  clr  %o2
a00a23f0:  40 00 17 53  call  0xa00a813c
a00a23f4:  90 10 20 01  mov  1, %o0
a00a23f8:  98 14 a2 90  or  %l2, 0x290, %o4
a00a23fc:  e4 0c 20 56  ldub  [ %l0 + 0x56 ], %l2
a00a2400:  e4 2b 21 ea  stb  %l2, [ %o4 + 0x1ea ]
a00a2404:  40 00 1b ee  call  0xa00a93bc
a00a2408:  90 0c a0 ff  and  %l2, 0xff, %o0
a00a240c:  d2 04 63 ec  ld  [ %l1 + 0x3ec ], %o1
a00a2410:  82 02 7f 40  add  %o1, -192, %g1
a00a2414:  80 a0 60 39  cmp  %g1, 0x39
a00a2418:  94 14 63 ec  or  %l1, 0x3ec, %o2
a00a241c:  18 80 00 18  bgu  0xa00a247c
a00a2420:  96 10 20 00  clr  %o3
a00a2424:  13 00 00 c3  sethi  %hi(0x30c00), %o1
a00a2428:  9f 28 60 02  sll  %g1, 2, %o7
a00a242c:  9a 12 60 78  or  %o1, 0x78, %o5
a00a2430:  d0 03 40 0f  ld  [ %o5 + %o7 ], %o0
a00a2434:  81 c2 00 00  jmp  %o0
a00a2438:  01 00 00 00  nop
a00a243c:  15 00 00 c2  sethi  %hi(0x30800), %o2
a00a2440:  91 28 60 02  sll  %g1, 2, %o0
a00a2444:  9a 12 a3 90  or  %o2, 0x390, %o5
a00a2448:  d8 03 40 08  ld  [ %o5 + %o0 ], %o4
a00a244c:  81 c3 00 00  jmp  %o4
a00a2450:  01 00 00 00  nop
a00a2454:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a00a2458:  7f ff fd 84  call  0xa00a1a68
a00a245c:  e4 2c 60 55  stb  %l2, [ %l1 + 0x55 ]	! 0xa8025c55
a00a2460:  40 00 e1 da  call  0xa00dabc8
a00a2464:  01 00 00 00  nop
a00a2468:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00a246c:  de 0b 20 8e  ldub  [ %o4 + 0x8e ], %o7	! 0xa802b08e
a00a2470:  90 13 e0 02  or  %o7, 2, %o0
a00a2474:  10 80 00 33  b  0xa00a2540
a00a2478:  d0 2b 20 8e  stb  %o0, [ %o4 + 0x8e ]
a00a247c:  82 10 20 00  clr  %g1
a00a2480:  96 00 60 34  add  %g1, 0x34, %o3
a00a2484:  d6 22 80 00  st  %o3, [ %o2 ]
a00a2488:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0
a00a248c:  40 00 1c 71  call  0xa00a9650
a00a2490:  92 10 20 00  clr  %o1
a00a2494:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a00a2498:  94 10 20 01  mov  1, %o2
a00a249c:  40 00 17 28  call  0xa00a813c
a00a24a0:  90 10 20 01  mov  1, %o0
a00a24a4:  d4 04 63 ec  ld  [ %l1 + 0x3ec ], %o2
a00a24a8:  a0 02 bf cc  add  %o2, -52, %l0
a00a24ac:  90 0c 20 ff  and  %l0, 0xff, %o0
a00a24b0:  40 00 1a d7  call  0xa00a900c
a00a24b4:  92 10 20 01  mov  1, %o1
a00a24b8:  90 10 20 01  mov  1, %o0
a00a24bc:  40 00 1b eb  call  0xa00a9468
a00a24c0:  92 10 20 02  mov  2, %o1
a00a24c4:  90 10 20 00  clr  %o0
a00a24c8:  40 00 44 03  call  0xa00b34d4
a00a24cc:  92 10 20 01  mov  1, %o1
a00a24d0:  30 bf ff e4  b,a   0xa00a2460
a00a24d4:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00a24d8:  10 bf ff c5  b  0xa00a23ec
a00a24dc:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a24e0:  96 10 20 06  mov  6, %o3
a00a24e4:  10 bf ff e7  b  0xa00a2480
a00a24e8:  82 0a e0 ff  and  %o3, 0xff, %g1
a00a24ec:  96 10 20 05  mov  5, %o3
a00a24f0:  10 bf ff e4  b  0xa00a2480
a00a24f4:  82 0a e0 ff  and  %o3, 0xff, %g1
a00a24f8:  96 10 20 04  mov  4, %o3
a00a24fc:  10 bf ff e1  b  0xa00a2480
a00a2500:  82 0a e0 ff  and  %o3, 0xff, %g1
a00a2504:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00a2508:  82 14 a2 90  or  %l2, 0x290, %g1	! 0xa802d290
a00a250c:  d2 08 61 ec  ldub  [ %g1 + 0x1ec ], %o1
a00a2510:  10 bf ff b7  b  0xa00a23ec
a00a2514:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a2518:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00a251c:  9e 14 a2 90  or  %l2, 0x290, %o7	! 0xa802d290
a00a2520:  d2 0b e1 ea  ldub  [ %o7 + 0x1ea ], %o1
a00a2524:  10 bf ff b2  b  0xa00a23ec
a00a2528:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a252c:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00a2530:  96 14 a2 90  or  %l2, 0x290, %o3	! 0xa802d290
a00a2534:  d2 0a e1 e8  ldub  [ %o3 + 0x1e8 ], %o1
a00a2538:  10 bf ff ad  b  0xa00a23ec
a00a253c:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a2540:  81 c7 e0 08  ret
a00a2544:  81 e8 00 00  restore
