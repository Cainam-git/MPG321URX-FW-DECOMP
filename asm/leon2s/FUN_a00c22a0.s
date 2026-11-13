# leon2s FUN_a00c22a0 0xa00c22a0-0xa00c2488 (488 bytes)
a00c22a0:  9d e3 be 18  save  %sp, -488, %sp
a00c22a4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c22a8:  90 10 00 18  mov  %i0, %o0
a00c22ac:  92 10 20 00  clr  %o1
a00c22b0:  94 10 20 02  mov  2, %o2
a00c22b4:  40 3b d7 1a  call  0xa0fb7f1c
a00c22b8:  96 10 20 01  mov  1, %o3
a00c22bc:  90 10 00 18  mov  %i0, %o0
a00c22c0:  92 10 20 00  clr  %o1
a00c22c4:  94 10 20 02  mov  2, %o2
a00c22c8:  40 3b d7 15  call  0xa0fb7f1c
a00c22cc:  96 10 20 00  clr  %o3
a00c22d0:  21 2a 01 f5  sethi  %hi(0xa807d400), %l0
a00c22d4:  c2 0c 22 28  ldub  [ %l0 + 0x228 ], %g1	! 0xa807d628
a00c22d8:  80 a0 60 00  cmp  %g1, 0
a00c22dc:  02 80 00 12  be  0xa00c2324
a00c22e0:  9a 10 20 00  clr  %o5
a00c22e4:  03 27 c6 dd  sethi  %hi(0x9f1b7400), %g1
a00c22e8:  92 10 60 b8  or  %g1, 0xb8, %o1	! 0x9f1b74b8
a00c22ec:  94 07 bf f8  add  %fp, -8, %o2
a00c22f0:  96 03 60 01  add  %o5, 1, %o3
a00c22f4:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c22f8:  83 30 60 10  srl  %g1, 0x10, %g1
a00c22fc:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00c2300:  d8 0a 40 01  ldub  [ %o1 + %g1 ], %o4
a00c2304:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c2308:  82 02 80 01  add  %o2, %g1, %g1
a00c230c:  80 a3 60 7f  cmp  %o5, 0x7f
a00c2310:  d8 28 7f 80  stb  %o4, [ %g1 + -128 ]
a00c2314:  08 bf ff f7  bleu  0xa00c22f0
a00c2318:  9a 10 00 0b  mov  %o3, %o5
a00c231c:  10 80 00 07  b  0xa00c2338
a00c2320:  90 10 00 18  mov  %i0, %o0
a00c2324:  90 10 25 0a  mov  0x50a, %o0
a00c2328:  92 10 20 80  mov  0x80, %o1
a00c232c:  40 3b 6b ed  call  0xa0f9d2e0
a00c2330:  94 07 bf 78  add  %fp, -136, %o2
a00c2334:  90 10 00 18  mov  %i0, %o0
a00c2338:  92 07 bf 78  add  %fp, -136, %o1
a00c233c:  94 10 20 05  mov  5, %o2
a00c2340:  96 10 20 00  clr  %o3
a00c2344:  40 00 1d 98  call  0xa00c99a4
a00c2348:  98 10 24 00  mov  0x400, %o4
a00c234c:  c2 0c 22 28  ldub  [ %l0 + 0x228 ], %g1
a00c2350:  80 a0 60 00  cmp  %g1, 0
a00c2354:  02 80 00 13  be  0xa00c23a0
a00c2358:  03 27 c6 dc  sethi  %hi(0x9f1b7000), %g1
a00c235c:  92 10 61 48  or  %g1, 0x148, %o1	! 0x9f1b7148
a00c2360:  9a 10 20 00  clr  %o5
a00c2364:  94 07 bf f8  add  %fp, -8, %o2
a00c2368:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c236c:  96 03 60 01  add  %o5, 1, %o3
a00c2370:  83 30 60 10  srl  %g1, 0x10, %g1
a00c2374:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00c2378:  98 00 40 09  add  %g1, %o1, %o4
a00c237c:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c2380:  d8 0b 20 2d  ldub  [ %o4 + 0x2d ], %o4
a00c2384:  82 02 80 01  add  %o2, %g1, %g1
a00c2388:  80 a3 60 7f  cmp  %o5, 0x7f
a00c238c:  d8 28 7f 00  stb  %o4, [ %g1 + -256 ]
a00c2390:  08 bf ff f6  bleu  0xa00c2368
a00c2394:  9a 10 00 0b  mov  %o3, %o5
a00c2398:  10 80 00 07  b  0xa00c23b4
a00c239c:  90 10 00 18  mov  %i0, %o0
a00c23a0:  90 10 22 85  mov  0x285, %o0
a00c23a4:  92 10 20 80  mov  0x80, %o1
a00c23a8:  40 3b 6b ce  call  0xa0f9d2e0
a00c23ac:  94 07 be f8  add  %fp, -264, %o2
a00c23b0:  90 10 00 18  mov  %i0, %o0
a00c23b4:  92 07 be f8  add  %fp, -264, %o1
a00c23b8:  94 10 20 03  mov  3, %o2
a00c23bc:  96 10 20 00  clr  %o3
a00c23c0:  40 00 1d 79  call  0xa00c99a4
a00c23c4:  98 10 24 00  mov  0x400, %o4
a00c23c8:  c2 0c 22 28  ldub  [ %l0 + 0x228 ], %g1
a00c23cc:  80 a0 60 00  cmp  %g1, 0
a00c23d0:  02 80 00 12  be  0xa00c2418
a00c23d4:  03 27 c6 dd  sethi  %hi(0x9f1b7400), %g1
a00c23d8:  92 10 60 38  or  %g1, 0x38, %o1	! 0x9f1b7438
a00c23dc:  9a 10 20 00  clr  %o5
a00c23e0:  94 07 bf f8  add  %fp, -8, %o2
a00c23e4:  96 03 60 01  add  %o5, 1, %o3
a00c23e8:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c23ec:  83 30 60 10  srl  %g1, 0x10, %g1
a00c23f0:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00c23f4:  d8 0a 40 01  ldub  [ %o1 + %g1 ], %o4
a00c23f8:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c23fc:  82 02 80 01  add  %o2, %g1, %g1
a00c2400:  80 a3 60 7f  cmp  %o5, 0x7f
a00c2404:  d8 28 7e 80  stb  %o4, [ %g1 + -384 ]
a00c2408:  08 bf ff f7  bleu  0xa00c23e4
a00c240c:  9a 10 00 0b  mov  %o3, %o5
a00c2410:  10 80 00 07  b  0xa00c242c
a00c2414:  90 10 00 18  mov  %i0, %o0
a00c2418:  90 10 24 8a  mov  0x48a, %o0
a00c241c:  92 10 20 80  mov  0x80, %o1
a00c2420:  40 3b 6b b0  call  0xa0f9d2e0
a00c2424:  94 07 be 78  add  %fp, -392, %o2
a00c2428:  90 10 00 18  mov  %i0, %o0
a00c242c:  92 07 be 78  add  %fp, -392, %o1
a00c2430:  94 10 20 04  mov  4, %o2
a00c2434:  96 10 20 00  clr  %o3
a00c2438:  40 00 1d 5b  call  0xa00c99a4
a00c243c:  98 10 24 00  mov  0x400, %o4
a00c2440:  13 2a 01 e3  sethi  %hi(0xa8078c00), %o1
a00c2444:  90 10 00 18  mov  %i0, %o0
a00c2448:  92 12 61 38  or  %o1, 0x138, %o1
a00c244c:  94 10 20 00  clr  %o2
a00c2450:  96 10 20 00  clr  %o3
a00c2454:  40 00 1d 54  call  0xa00c99a4
a00c2458:  98 10 24 00  mov  0x400, %o4
a00c245c:  90 10 00 18  mov  %i0, %o0
a00c2460:  92 10 20 00  clr  %o1
a00c2464:  40 3b d6 9f  call  0xa0fb7ee0
a00c2468:  94 10 20 00  clr  %o2
a00c246c:  90 10 00 18  mov  %i0, %o0
a00c2470:  92 10 20 03  mov  3, %o1
a00c2474:  40 3b d6 9b  call  0xa0fb7ee0
a00c2478:  94 10 20 01  mov  1, %o2
a00c247c:  01 00 00 00  nop
a00c2480:  81 c7 e0 08  ret
a00c2484:  81 e8 00 00  restore
