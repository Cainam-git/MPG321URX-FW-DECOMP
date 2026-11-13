# leon2m FUN_a00e2340 0xa00e2340-0xa00e2588 (584 bytes)
a00e2340:  9d e3 bf 98  save  %sp, -104, %sp
a00e2344:  90 10 20 01  mov  1, %o0
a00e2348:  92 10 00 18  mov  %i0, %o1
a00e234c:  7f ff f7 1a  call  0xa00dffb4
a00e2350:  94 10 3f ff  mov  -1, %o2
a00e2354:  92 10 00 19  mov  %i1, %o1
a00e2358:  90 10 00 18  mov  %i0, %o0
a00e235c:  7f ff f6 3d  call  0xa00dfc50
a00e2360:  94 10 00 1a  mov  %i2, %o2
a00e2364:  a2 10 20 00  clr  %l1
a00e2368:  a4 10 20 00  clr  %l2
a00e236c:  a6 10 20 00  clr  %l3
a00e2370:  b2 10 20 00  clr  %i1
a00e2374:  a0 10 20 00  clr  %l0
a00e2378:  80 a4 a0 3f  cmp  %l2, 0x3f
a00e237c:  04 80 00 03  ble  0xa00e2388
a00e2380:  9a 10 20 01  mov  1, %o5
a00e2384:  9a 10 20 00  clr  %o5
a00e2388:  80 a4 e0 3f  cmp  %l3, 0x3f
a00e238c:  04 80 00 03  ble  0xa00e2398
a00e2390:  82 10 20 01  mov  1, %g1
a00e2394:  82 10 20 00  clr  %g1
a00e2398:  80 8b 40 01  btst  %o5, %g1
a00e239c:  02 80 00 56  be  0xa00e24f4
a00e23a0:  80 a4 60 3f  cmp  %l1, 0x3f
a00e23a4:  14 80 00 55  bg  0xa00e24f8
a00e23a8:  80 a4 60 40  cmp  %l1, 0x40
a00e23ac:  7f ff f6 fe  call  0xa00dffa4
a00e23b0:  90 10 20 01  mov  1, %o0
a00e23b4:  92 10 20 3e  mov  0x3e, %o1
a00e23b8:  94 10 20 80  mov  0x80, %o2
a00e23bc:  7f ff f8 56  call  0xa00e0514
a00e23c0:  90 10 00 18  mov  %i0, %o0
a00e23c4:  82 1a 20 80  xor  %o0, 0x80, %g1
a00e23c8:  80 a0 00 01  cmp  %g0, %g1
a00e23cc:  b2 60 3f ff  subx  %g0, -1, %i1
a00e23d0:  90 10 00 18  mov  %i0, %o0
a00e23d4:  92 10 20 3e  mov  0x3e, %o1
a00e23d8:  7f ff f8 4f  call  0xa00e0514
a00e23dc:  94 10 20 40  mov  0x40, %o2
a00e23e0:  90 1a 20 40  xor  %o0, 0x40, %o0
a00e23e4:  80 a0 00 08  cmp  %g0, %o0
a00e23e8:  a0 60 3f ff  subx  %g0, -1, %l0
a00e23ec:  80 96 40 10  orcc  %i1, %l0, %g0
a00e23f0:  12 80 00 10  bne  0xa00e2430
a00e23f4:  80 ae 40 10  andncc  %i1, %l0, %g0
a00e23f8:  96 1e a0 03  xor  %i2, 3, %o3
a00e23fc:  80 a0 00 0b  cmp  %g0, %o3
a00e2400:  92 60 20 00  subx  %g0, 0, %o1
a00e2404:  94 0a 60 08  and  %o1, 8, %o2
a00e2408:  94 02 a0 08  add  %o2, 8, %o2
a00e240c:  90 10 00 18  mov  %i0, %o0
a00e2410:  7f ff ff 9e  call  0xa00e2288
a00e2414:  92 10 00 1a  mov  %i2, %o1
a00e2418:  a4 04 a0 01  inc  %l2
a00e241c:  80 a4 a0 3f  cmp  %l2, 0x3f
a00e2420:  04 bf ff da  ble  0xa00e2388
a00e2424:  9a 10 20 01  mov  1, %o5
a00e2428:  10 bf ff d8  b  0xa00e2388
a00e242c:  9a 10 20 00  clr  %o5
a00e2430:  32 80 00 1d  bne,a   0xa00e24a4
a00e2434:  a2 10 20 00  clr  %l1
a00e2438:  80 ac 00 19  andncc  %l0, %i1, %g0
a00e243c:  22 80 00 2a  be,a   0xa00e24e4
a00e2440:  a6 04 e0 01  inc  %l3
a00e2444:  10 80 00 05  b  0xa00e2458
a00e2448:  a2 10 20 00  clr  %l1
a00e244c:  80 a4 60 3f  cmp  %l1, 0x3f
a00e2450:  14 bf ff cb  bg  0xa00e237c
a00e2454:  80 a4 a0 3f  cmp  %l2, 0x3f
a00e2458:  90 10 00 18  mov  %i0, %o0
a00e245c:  92 10 00 1a  mov  %i2, %o1
a00e2460:  7f ff ff 8a  call  0xa00e2288
a00e2464:  94 10 20 01  mov  1, %o2
a00e2468:  90 10 00 18  mov  %i0, %o0
a00e246c:  92 10 20 3e  mov  0x3e, %o1
a00e2470:  7f ff f8 29  call  0xa00e0514
a00e2474:  94 10 20 40  mov  0x40, %o2
a00e2478:  9a 1a 20 40  xor  %o0, 0x40, %o5
a00e247c:  80 a0 00 0d  cmp  %g0, %o5
a00e2480:  a0 60 3f ff  subx  %g0, -1, %l0
a00e2484:  80 a4 20 00  cmp  %l0, 0
a00e2488:  12 bf ff f1  bne  0xa00e244c
a00e248c:  a2 04 60 01  inc  %l1
a00e2490:  10 80 00 3c  b  0xa00e2580
a00e2494:  b0 10 20 00  clr  %i0
a00e2498:  80 a4 60 3f  cmp  %l1, 0x3f
a00e249c:  14 bf ff b8  bg  0xa00e237c
a00e24a0:  80 a4 a0 3f  cmp  %l2, 0x3f
a00e24a4:  90 10 00 18  mov  %i0, %o0
a00e24a8:  92 10 00 1a  mov  %i2, %o1
a00e24ac:  7f ff ff 77  call  0xa00e2288
a00e24b0:  94 10 3f ff  mov  -1, %o2
a00e24b4:  90 10 00 18  mov  %i0, %o0
a00e24b8:  92 10 20 3e  mov  0x3e, %o1
a00e24bc:  7f ff f8 16  call  0xa00e0514
a00e24c0:  94 10 20 80  mov  0x80, %o2
a00e24c4:  98 1a 20 80  xor  %o0, 0x80, %o4
a00e24c8:  80 a0 00 0c  cmp  %g0, %o4
a00e24cc:  b2 60 3f ff  subx  %g0, -1, %i1
a00e24d0:  80 a6 60 00  cmp  %i1, 0
a00e24d4:  12 bf ff f1  bne  0xa00e2498
a00e24d8:  a2 04 60 01  inc  %l1
a00e24dc:  10 80 00 29  b  0xa00e2580
a00e24e0:  b0 10 20 00  clr  %i0
a00e24e4:  7f ff f6 b0  call  0xa00dffa4
a00e24e8:  90 10 20 01  mov  1, %o0
a00e24ec:  10 bf ff a4  b  0xa00e237c
a00e24f0:  80 a4 a0 3f  cmp  %l2, 0x3f
a00e24f4:  80 a4 60 40  cmp  %l1, 0x40
a00e24f8:  14 80 00 0d  bg  0xa00e252c
a00e24fc:  80 ae 40 10  andncc  %i1, %l0, %g0
a00e2500:  80 a4 a0 40  cmp  %l2, 0x40
a00e2504:  04 80 00 13  ble  0xa00e2550
a00e2508:  01 00 00 00  nop
a00e250c:  7f ff f4 c0  call  0xa00df80c
a00e2510:  23 00 06 65  sethi  %hi(0x199400), %l1
a00e2514:  7f ff f9 ab  call  0xa00e0bc0
a00e2518:  01 00 00 00  nop
a00e251c:  90 14 63 08  or  %l1, 0x308, %o0
a00e2520:  7f ff f3 14  call  0xa00df170
a00e2524:  b0 10 3f ff  mov  -1, %i0
a00e2528:  30 80 00 16  b,a   0xa00e2580
a00e252c:  02 80 00 0f  be  0xa00e2568
a00e2530:  01 00 00 00  nop
a00e2534:  7f ff f4 b6  call  0xa00df80c
a00e2538:  01 00 00 00  nop
a00e253c:  7f ff f9 a1  call  0xa00e0bc0
a00e2540:  01 00 00 00  nop
a00e2544:  1f 00 06 65  sethi  %hi(0x199400), %o7
a00e2548:  10 bf ff f6  b  0xa00e2520
a00e254c:  90 13 e3 20  or  %o7, 0x320, %o0	! 0x199720
a00e2550:  7f ff f4 af  call  0xa00df80c
a00e2554:  25 00 06 65  sethi  %hi(0x199400), %l2
a00e2558:  7f ff f9 9a  call  0xa00e0bc0
a00e255c:  01 00 00 00  nop
a00e2560:  10 bf ff f0  b  0xa00e2520
a00e2564:  90 14 a3 38  or  %l2, 0x338, %o0
a00e2568:  7f ff f4 a9  call  0xa00df80c
a00e256c:  21 00 06 65  sethi  %hi(0x199400), %l0
a00e2570:  7f ff f9 94  call  0xa00e0bc0
a00e2574:  01 00 00 00  nop
a00e2578:  10 bf ff ea  b  0xa00e2520
a00e257c:  90 14 23 50  or  %l0, 0x350, %o0
a00e2580:  81 c7 e0 08  ret
a00e2584:  81 e8 00 00  restore
