# leon2m FUN_a00c2180 0xa00c2180-0xa00c25ac (1068 bytes)
a00c2180:  9d e3 bf 98  save  %sp, -104, %sp
a00c2184:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c2188:  80 a6 20 02  cmp  %i0, 2
a00c218c:  02 80 00 d0  be  0xa00c24cc
a00c2190:  80 a6 20 03  cmp  %i0, 3
a00c2194:  02 80 00 d1  be  0xa00c24d8
a00c2198:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c219c:  c2 0a 60 d6  ldub  [ %o1 + 0xd6 ], %g1	! 0xa802d0d6
a00c21a0:  94 08 60 ff  and  %g1, 0xff, %o2
a00c21a4:  80 a6 20 02  cmp  %i0, 2
a00c21a8:  02 80 00 c6  be  0xa00c24c0
a00c21ac:  9a 5a a3 e8  smul  %o2, 0x3e8, %o5
a00c21b0:  80 a6 20 03  cmp  %i0, 3
a00c21b4:  02 80 00 d4  be  0xa00c2504
a00c21b8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c21bc:  c2 0b e0 d7  ldub  [ %o7 + 0xd7 ], %g1	! 0xa802d0d7
a00c21c0:  82 08 60 ff  and  %g1, 0xff, %g1
a00c21c4:  a0 58 60 64  smul  %g1, 0x64, %l0
a00c21c8:  80 a6 20 02  cmp  %i0, 2
a00c21cc:  02 80 00 ba  be  0xa00c24b4
a00c21d0:  98 03 40 10  add  %o5, %l0, %o4
a00c21d4:  80 a6 20 03  cmp  %i0, 3
a00c21d8:  02 80 00 c8  be  0xa00c24f8
a00c21dc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c21e0:  da 0a a0 d8  ldub  [ %o2 + 0xd8 ], %o5	! 0xa802d0d8
a00c21e4:  a0 0b 60 ff  and  %o5, 0xff, %l0
a00c21e8:  9f 2c 20 02  sll  %l0, 2, %o7
a00c21ec:  96 03 c0 10  add  %o7, %l0, %o3
a00c21f0:  9a 02 c0 0b  add  %o3, %o3, %o5
a00c21f4:  80 a6 20 02  cmp  %i0, 2
a00c21f8:  02 80 00 ac  be  0xa00c24a8
a00c21fc:  98 03 00 0d  add  %o4, %o5, %o4
a00c2200:  80 a6 20 03  cmp  %i0, 3
a00c2204:  02 80 00 ba  be  0xa00c24ec
a00c2208:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c220c:  da 0a 60 d9  ldub  [ %o1 + 0xd9 ], %o5	! 0xa802d0d9
a00c2210:  96 0b 60 ff  and  %o5, 0xff, %o3
a00c2214:  9a 03 00 0b  add  %o4, %o3, %o5
a00c2218:  15 3f ff f4  sethi  %hi(0xffffd000), %o2
a00c221c:  98 12 a0 50  or  %o2, 0x50, %o4	! 0xffffd050
a00c2220:  80 a6 20 02  cmp  %i0, 2
a00c2224:  02 80 00 9e  be  0xa00c249c
a00c2228:  94 23 40 0c  sub  %o5, %o4, %o2
a00c222c:  80 a6 20 03  cmp  %i0, 3
a00c2230:  02 80 00 ad  be  0xa00c24e4
a00c2234:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c2238:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c223c:  c2 08 60 da  ldub  [ %g1 + 0xda ], %g1	! 0xa802d0da
a00c2240:  90 08 60 ff  and  %g1, 0xff, %o0
a00c2244:  80 a6 20 02  cmp  %i0, 2
a00c2248:  02 80 00 92  be  0xa00c2490
a00c224c:  9a 5a 23 e8  smul  %o0, 0x3e8, %o5
a00c2250:  80 a6 20 03  cmp  %i0, 3
a00c2254:  02 80 00 cf  be  0xa00c2590
a00c2258:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c225c:  c2 0a e0 db  ldub  [ %o3 + 0xdb ], %g1	! 0xa802d0db
a00c2260:  a0 08 60 ff  and  %g1, 0xff, %l0
a00c2264:  9e 5c 20 64  smul  %l0, 0x64, %o7
a00c2268:  80 a6 20 02  cmp  %i0, 2
a00c226c:  02 80 00 86  be  0xa00c2484
a00c2270:  98 03 40 0f  add  %o5, %o7, %o4
a00c2274:  80 a6 20 03  cmp  %i0, 3
a00c2278:  02 80 00 c3  be  0xa00c2584
a00c227c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c2280:  da 0a 60 dc  ldub  [ %o1 + 0xdc ], %o5	! 0xa802d0dc
a00c2284:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00c2288:  a1 2b 60 02  sll  %o5, 2, %l0
a00c228c:  9e 04 00 0d  add  %l0, %o5, %o7
a00c2290:  96 03 c0 0f  add  %o7, %o7, %o3
a00c2294:  80 a6 20 02  cmp  %i0, 2
a00c2298:  02 80 00 78  be  0xa00c2478
a00c229c:  9a 03 00 0b  add  %o4, %o3, %o5
a00c22a0:  80 a6 20 03  cmp  %i0, 3
a00c22a4:  02 80 00 b5  be  0xa00c2578
a00c22a8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c22ac:  c2 0a 20 dd  ldub  [ %o0 + 0xdd ], %g1	! 0xa802d0dd
a00c22b0:  98 08 60 ff  and  %g1, 0xff, %o4
a00c22b4:  9e 03 40 0c  add  %o5, %o4, %o7
a00c22b8:  1b 3f ff f4  sethi  %hi(0xffffd000), %o5
a00c22bc:  97 2a a0 10  sll  %o2, 0x10, %o3
a00c22c0:  a0 13 60 50  or  %o5, 0x50, %l0
a00c22c4:  93 32 e0 10  srl  %o3, 0x10, %o1
a00c22c8:  82 23 c0 10  sub  %o7, %l0, %g1
a00c22cc:  80 a2 60 31  cmp  %o1, 0x31
a00c22d0:  08 80 00 03  bleu  0xa00c22dc
a00c22d4:  96 10 00 01  mov  %g1, %o3
a00c22d8:  94 10 20 31  mov  0x31, %o2
a00c22dc:  91 28 60 10  sll  %g1, 0x10, %o0
a00c22e0:  83 32 20 10  srl  %o0, 0x10, %g1
a00c22e4:  80 a0 60 1c  cmp  %g1, 0x1c
a00c22e8:  38 80 00 02  bgu,a   0xa00c22f0
a00c22ec:  96 10 20 1c  mov  0x1c, %o3
a00c22f0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c22f4:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a00c22f8:  a0 13 22 90  or  %o4, 0x290, %l0
a00c22fc:  d2 13 63 f8  lduh  [ %o5 + 0x3f8 ], %o1
a00c2300:  1f 00 00 18  sethi  %hi(0x6000), %o7
a00c2304:  80 8b c0 09  btst  %o7, %o1
a00c2308:  d4 2c 21 a7  stb  %o2, [ %l0 + 0x1a7 ]
a00c230c:  02 80 00 43  be  0xa00c2418
a00c2310:  d6 2c 21 a8  stb  %o3, [ %l0 + 0x1a8 ]
a00c2314:  7f ff d9 6e  call  0xa00b88cc
a00c2318:  01 00 00 00  nop
a00c231c:  80 a6 20 02  cmp  %i0, 2
a00c2320:  02 80 00 24  be  0xa00c23b0
a00c2324:  80 a6 20 03  cmp  %i0, 3
a00c2328:  02 80 00 7a  be  0xa00c2510
a00c232c:  96 10 20 30  mov  0x30, %o3
a00c2330:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c2334:  94 12 60 78  or  %o1, 0x78, %o2	! 0xa802d078
a00c2338:  9e 10 20 35  mov  0x35, %o7
a00c233c:  a0 10 20 36  mov  0x36, %l0
a00c2340:  90 10 20 2b  mov  0x2b, %o0
a00c2344:  82 10 20 0d  mov  0xd, %g1
a00c2348:  de 2a 60 78  stb  %o7, [ %o1 + 0x78 ]
a00c234c:  e0 2a a0 01  stb  %l0, [ %o2 + 1 ]
a00c2350:  d6 2a a0 03  stb  %o3, [ %o2 + 3 ]
a00c2354:  d0 2a a0 04  stb  %o0, [ %o2 + 4 ]
a00c2358:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00c235c:  80 a6 20 02  cmp  %i0, 2
a00c2360:  02 80 00 21  be  0xa00c23e4
a00c2364:  d6 2a a0 02  stb  %o3, [ %o2 + 2 ]
a00c2368:  80 a6 20 03  cmp  %i0, 3
a00c236c:  02 80 00 76  be  0xa00c2544
a00c2370:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c2374:  90 14 20 d0  or  %l0, 0xd0, %o0	! 0xa802d0d0
a00c2378:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00c237c:  c0 2a 60 9c  clrb  [ %o1 + 0x9c ]	! 0xa802b09c
a00c2380:  c0 2c 20 d0  clrb  [ %l0 + 0xd0 ]
a00c2384:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c2388:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c238c:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c2390:  80 a6 20 02  cmp  %i0, 2
a00c2394:  02 80 00 1d  be  0xa00c2408
a00c2398:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c239c:  80 a6 20 03  cmp  %i0, 3
a00c23a0:  12 80 00 7f  bne  0xa00c259c
a00c23a4:  90 10 00 18  mov  %i0, %o0
a00c23a8:  10 80 00 71  b  0xa00c256c
a00c23ac:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c23b0:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c23b4:  b0 12 e1 28  or  %o3, 0x128, %i0	! 0xa802d128
a00c23b8:  9e 10 20 30  mov  0x30, %o7
a00c23bc:  82 10 20 35  mov  0x35, %g1
a00c23c0:  94 10 20 0d  mov  0xd, %o2
a00c23c4:  98 10 20 36  mov  0x36, %o4
a00c23c8:  9a 10 20 2b  mov  0x2b, %o5
a00c23cc:  c2 2a e1 28  stb  %g1, [ %o3 + 0x128 ]
a00c23d0:  d4 2e 20 05  stb  %o2, [ %i0 + 5 ]
a00c23d4:  d8 2e 20 01  stb  %o4, [ %i0 + 1 ]
a00c23d8:  de 2e 20 03  stb  %o7, [ %i0 + 3 ]
a00c23dc:  da 2e 20 04  stb  %o5, [ %i0 + 4 ]
a00c23e0:  de 2e 20 02  stb  %o7, [ %i0 + 2 ]
a00c23e4:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c23e8:  94 16 20 40  or  %i0, 0x40, %o2	! 0xa802d040
a00c23ec:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00c23f0:  c0 2b 60 9a  clrb  [ %o5 + 0x9a ]	! 0xa802b09a
a00c23f4:  c0 2e 20 40  clrb  [ %i0 + 0x40 ]
a00c23f8:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c23fc:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c2400:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c2404:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c2408:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c240c:  94 13 e1 28  or  %o7, 0x128, %o2	! 0xa802d128
a00c2410:  10 80 00 63  b  0xa00c259c
a00c2414:  90 10 20 02  mov  2, %o0
a00c2418:  7f ff 3a f0  call  0xa0090fd8
a00c241c:  01 00 00 00  nop
a00c2420:  7f ff 3a e3  call  0xa0090fac
a00c2424:  01 00 00 00  nop
a00c2428:  d4 0c 21 90  ldub  [ %l0 + 0x190 ], %o2
a00c242c:  80 a2 a0 00  cmp  %o2, 0
a00c2430:  12 bf ff b9  bne  0xa00c2314
a00c2434:  17 00 00 04  sethi  %hi(0x1000), %o3
a00c2438:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a00c243c:  80 88 40 0b  btst  %g1, %o3
a00c2440:  12 bf ff b5  bne  0xa00c2314
a00c2444:  01 00 00 00  nop
a00c2448:  d0 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o0
a00c244c:  80 a2 20 00  cmp  %o0, 0
a00c2450:  12 bf ff b1  bne  0xa00c2314
a00c2454:  01 00 00 00  nop
a00c2458:  d2 04 20 ac  ld  [ %l0 + 0xac ], %o1
a00c245c:  21 00 10 00  sethi  %hi(0x400000), %l0
a00c2460:  80 8a 40 10  btst  %o1, %l0
a00c2464:  12 bf ff ac  bne  0xa00c2314
a00c2468:  01 00 00 00  nop
a00c246c:  7f ff 3a db  call  0xa0090fd8
a00c2470:  01 00 00 00  nop
a00c2474:  30 bf ff a8  b,a   0xa00c2314
a00c2478:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c247c:  10 bf ff 8d  b  0xa00c22b0
a00c2480:  c2 0b 20 4d  ldub  [ %o4 + 0x4d ], %g1	! 0xa802d04d
a00c2484:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c2488:  10 bf ff 7f  b  0xa00c2284
a00c248c:  da 08 60 4c  ldub  [ %g1 + 0x4c ], %o5	! 0xa802d04c
a00c2490:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c2494:  10 bf ff 73  b  0xa00c2260
a00c2498:  c2 0a 60 4b  ldub  [ %o1 + 0x4b ], %g1	! 0xa802d04b
a00c249c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c24a0:  10 bf ff 68  b  0xa00c2240
a00c24a4:  c2 0b e0 4a  ldub  [ %o7 + 0x4a ], %g1	! 0xa802d04a
a00c24a8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c24ac:  10 bf ff 59  b  0xa00c2210
a00c24b0:  da 08 60 49  ldub  [ %g1 + 0x49 ], %o5	! 0xa802d049
a00c24b4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c24b8:  10 bf ff 4b  b  0xa00c21e4
a00c24bc:  da 0a 20 48  ldub  [ %o0 + 0x48 ], %o5	! 0xa802d048
a00c24c0:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c24c4:  10 bf ff 3f  b  0xa00c21c0
a00c24c8:  c2 0a e0 47  ldub  [ %o3 + 0x47 ], %g1	! 0xa802d047
a00c24cc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c24d0:  10 bf ff 34  b  0xa00c21a0
a00c24d4:  c2 08 60 46  ldub  [ %g1 + 0x46 ], %g1	! 0xa802d046
a00c24d8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c24dc:  10 bf ff 31  b  0xa00c21a0
a00c24e0:  c2 0a 20 9e  ldub  [ %o0 + 0x9e ], %g1	! 0xa802d09e
a00c24e4:  10 bf ff 57  b  0xa00c2240
a00c24e8:  c2 0c 20 a2  ldub  [ %l0 + 0xa2 ], %g1
a00c24ec:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c24f0:  10 bf ff 48  b  0xa00c2210
a00c24f4:  da 0a 20 a1  ldub  [ %o0 + 0xa1 ], %o5	! 0xa802d0a1
a00c24f8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c24fc:  10 bf ff 3a  b  0xa00c21e4
a00c2500:  da 0a 60 a0  ldub  [ %o1 + 0xa0 ], %o5	! 0xa802d0a0
a00c2504:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c2508:  10 bf ff 2e  b  0xa00c21c0
a00c250c:  c2 0b 20 9f  ldub  [ %o4 + 0x9f ], %g1	! 0xa802d09f
a00c2510:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c2514:  90 13 61 08  or  %o5, 0x108, %o0	! 0xa802d108
a00c2518:  a0 10 20 30  mov  0x30, %l0
a00c251c:  98 10 20 35  mov  0x35, %o4
a00c2520:  9e 10 20 0d  mov  0xd, %o7
a00c2524:  b0 10 20 36  mov  0x36, %i0
a00c2528:  92 10 20 2b  mov  0x2b, %o1
a00c252c:  d8 2b 61 08  stb  %o4, [ %o5 + 0x108 ]
a00c2530:  de 2a 20 05  stb  %o7, [ %o0 + 5 ]
a00c2534:  f0 2a 20 01  stb  %i0, [ %o0 + 1 ]
a00c2538:  e0 2a 20 03  stb  %l0, [ %o0 + 3 ]
a00c253c:  d2 2a 20 04  stb  %o1, [ %o0 + 4 ]
a00c2540:  e0 2a 20 02  stb  %l0, [ %o0 + 2 ]
a00c2544:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c2548:  96 13 20 98  or  %o4, 0x98, %o3	! 0xa802d098
a00c254c:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c2550:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c2554:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]
a00c2558:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00c255c:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00c2560:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00c2564:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00c2568:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c256c:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c2570:  10 80 00 0b  b  0xa00c259c
a00c2574:  90 10 20 03  mov  3, %o0
a00c2578:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c257c:  10 bf ff 4d  b  0xa00c22b0
a00c2580:  c2 08 60 a5  ldub  [ %g1 + 0xa5 ], %g1	! 0xa802d0a5
a00c2584:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c2588:  10 bf ff 3f  b  0xa00c2284
a00c258c:  da 0a 20 a4  ldub  [ %o0 + 0xa4 ], %o5	! 0xa802d0a4
a00c2590:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c2594:  10 bf ff 33  b  0xa00c2260
a00c2598:  c2 0b 20 a3  ldub  [ %o4 + 0xa3 ], %g1	! 0xa802d0a3
a00c259c:  40 02 18 93  call  0xa01487e8
a00c25a0:  92 10 20 06  mov  6, %o1
a00c25a4:  81 c7 e0 08  ret
a00c25a8:  91 e8 20 00  restore  %g0, 0, %o0
