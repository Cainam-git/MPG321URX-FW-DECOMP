# leon2s CED_ALL_2 0xa00b2324-0xa00b24b0 (396 bytes)
a00b2324:  9d e3 bf 88  save  %sp, -120, %sp
a00b2328:  80 a6 20 00  cmp  %i0, 0
a00b232c:  02 80 00 5e  be  0xa00b24a4
a00b2330:  80 a6 60 00  cmp  %i1, 0
a00b2334:  12 80 00 03  bne  0xa00b2340
a00b2338:  b0 0e 3f fc  and  %i0, -4, %i0
a00b233c:  b2 10 20 20  mov  0x20, %i1
a00b2340:  83 2e 60 02  sll  %i1, 2, %g1
a00b2344:  b2 06 00 01  add  %i0, %g1, %i1
a00b2348:  82 06 60 0f  add  %i1, 0xf, %g1
a00b234c:  2d 28 01 a7  sethi  %hi(0xa0069c00), %l6
a00b2350:  aa 08 7f f0  and  %g1, -16, %l5
a00b2354:  a6 0e 3f f0  and  %i0, -16, %l3
a00b2358:  7f fe bb ca  call  0xa0061280
a00b235c:  90 15 a2 e8  or  %l6, 0x2e8, %o0
a00b2360:  a8 10 00 13  mov  %l3, %l4
a00b2364:  80 a5 00 15  cmp  %l4, %l5
a00b2368:  3a 80 00 4d  bcc,a   0xa00b249c
a00b236c:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a00b2370:  7f fe bb f6  call  0xa0061348
a00b2374:  90 10 00 14  mov  %l4, %o0
a00b2378:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b237c:  7f fe bb c1  call  0xa0061280
a00b2380:  90 12 22 60  or  %o0, 0x260, %o0	! 0xa006c660
a00b2384:  a2 10 20 00  clr  %l1
a00b2388:  80 a4 c0 18  cmp  %l3, %i0
a00b238c:  9a 40 20 00  addx  %g0, 0, %o5
a00b2390:  80 a4 c0 19  cmp  %l3, %i1
a00b2394:  82 60 3f ff  subx  %g0, -1, %g1
a00b2398:  80 93 40 01  orcc  %o5, %g1, %g0
a00b239c:  83 2c 60 02  sll  %l1, 2, %g1
a00b23a0:  02 80 00 09  be  0xa00b23c4
a00b23a4:  a0 07 bf f8  add  %fp, -8, %l0
a00b23a8:  82 00 40 10  add  %g1, %l0, %g1
a00b23ac:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b23b0:  c0 20 7f f0  clr  [ %g1 + -16 ]
a00b23b4:  7f fe bb b3  call  0xa0061280
a00b23b8:  90 12 22 68  or  %o0, 0x268, %o0
a00b23bc:  10 80 00 14  b  0xa00b240c
a00b23c0:  a2 04 60 01  inc  %l1
a00b23c4:  a0 00 40 10  add  %g1, %l0, %l0
a00b23c8:  7f ff ff cd  call  0xa00b22fc
a00b23cc:  90 10 00 13  mov  %l3, %o0
a00b23d0:  d0 24 3f f0  st  %o0, [ %l0 + -16 ]
a00b23d4:  a4 10 00 08  mov  %o0, %l2
a00b23d8:  a0 10 20 00  clr  %l0
a00b23dc:  83 2c 20 03  sll  %l0, 3, %g1
a00b23e0:  83 34 80 01  srl  %l2, %g1, %g1
a00b23e4:  7f fe bb fa  call  0xa00613cc
a00b23e8:  90 08 60 ff  and  %g1, 0xff, %o0
a00b23ec:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b23f0:  7f fe bb a4  call  0xa0061280
a00b23f4:  90 12 22 90  or  %o0, 0x290, %o0	! 0xa006c690
a00b23f8:  a0 04 20 01  inc  %l0
a00b23fc:  80 a4 20 03  cmp  %l0, 3
a00b2400:  04 bf ff f8  ble  0xa00b23e0
a00b2404:  83 2c 20 03  sll  %l0, 3, %g1
a00b2408:  a2 04 60 01  inc  %l1
a00b240c:  80 a4 60 03  cmp  %l1, 3
a00b2410:  04 bf ff de  ble  0xa00b2388
a00b2414:  a6 04 e0 04  add  %l3, 4, %l3
a00b2418:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b241c:  7f fe bb 99  call  0xa0061280
a00b2420:  90 12 22 78  or  %o0, 0x278, %o0	! 0xa006c678
a00b2424:  a2 10 20 00  clr  %l1
a00b2428:  83 2c 60 02  sll  %l1, 2, %g1
a00b242c:  82 07 80 01  add  %fp, %g1, %g1
a00b2430:  e4 00 7f e8  ld  [ %g1 + -24 ], %l2
a00b2434:  a0 10 20 00  clr  %l0
a00b2438:  83 2c 20 03  sll  %l0, 3, %g1
a00b243c:  83 34 80 01  srl  %l2, %g1, %g1
a00b2440:  9a 00 7f e0  add  %g1, -32, %o5
a00b2444:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00b2448:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b244c:  80 a3 60 5e  cmp  %o5, 0x5e
a00b2450:  18 80 00 06  bgu  0xa00b2468
a00b2454:  90 12 22 80  or  %o0, 0x280, %o0
a00b2458:  7f fe bb 75  call  0xa006122c
a00b245c:  90 08 60 ff  and  %g1, 0xff, %o0
a00b2460:  10 80 00 04  b  0xa00b2470
a00b2464:  a0 04 20 01  inc  %l0
a00b2468:  7f fe bb 86  call  0xa0061280
a00b246c:  a0 04 20 01  inc  %l0
a00b2470:  80 a4 20 03  cmp  %l0, 3
a00b2474:  04 bf ff f2  ble  0xa00b243c
a00b2478:  83 2c 20 03  sll  %l0, 3, %g1
a00b247c:  a2 04 60 01  inc  %l1
a00b2480:  80 a4 60 03  cmp  %l1, 3
a00b2484:  04 bf ff ea  ble  0xa00b242c
a00b2488:  83 2c 60 02  sll  %l1, 2, %g1
a00b248c:  7f fe bb 7d  call  0xa0061280
a00b2490:  90 15 a2 e8  or  %l6, 0x2e8, %o0
a00b2494:  10 bf ff b4  b  0xa00b2364
a00b2498:  a8 05 20 10  add  %l4, 0x10, %l4
a00b249c:  7f fe bb 79  call  0xa0061280
a00b24a0:  90 12 22 e8  or  %o0, 0x2e8, %o0
a00b24a4:  01 00 00 00  nop
a00b24a8:  81 c7 e0 08  ret
a00b24ac:  81 e8 00 00  restore
