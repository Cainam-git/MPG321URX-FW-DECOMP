# leon2m FUN_a00c8410 0xa00c8410-0xa00c8614 (516 bytes)
a00c8410:  9d e3 bf 98  save  %sp, -104, %sp
a00c8414:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c8418:  80 a4 20 02  cmp  %l0, 2
a00c841c:  02 80 00 5c  be  0xa00c858c
a00c8420:  80 a4 20 03  cmp  %l0, 3
a00c8424:  02 80 00 5d  be  0xa00c8598
a00c8428:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c842c:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c8430:  96 08 60 ff  and  %g1, 0xff, %o3
a00c8434:  94 02 ff d0  add  %o3, -48, %o2
a00c8438:  90 0a a0 ff  and  %o2, 0xff, %o0
a00c843c:  80 a2 20 03  cmp  %o0, 3
a00c8440:  18 80 00 73  bgu  0xa00c860c
a00c8444:  b0 10 20 ff  mov  0xff, %i0
a00c8448:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c844c:  a2 13 22 90  or  %o4, 0x290, %l1	! 0xa802d290
a00c8450:  da 0c 60 1f  ldub  [ %l1 + 0x1f ], %o5
a00c8454:  80 a3 60 00  cmp  %o5, 0
a00c8458:  02 80 00 6d  be  0xa00c860c
a00c845c:  01 00 00 00  nop
a00c8460:  40 01 f0 4f  call  0xa014459c
a00c8464:  01 00 00 00  nop
a00c8468:  d0 2c 60 20  stb  %o0, [ %l1 + 0x20 ]
a00c846c:  40 00 35 33  call  0xa00d5938
a00c8470:  90 10 20 01  mov  1, %o0
a00c8474:  40 00 36 19  call  0xa00d5cd8
a00c8478:  01 00 00 00  nop
a00c847c:  7f ff c1 14  call  0xa00b88cc
a00c8480:  01 00 00 00  nop
a00c8484:  80 a4 20 02  cmp  %l0, 2
a00c8488:  02 80 00 24  be  0xa00c8518
a00c848c:  80 a4 20 03  cmp  %l0, 3
a00c8490:  02 80 00 45  be  0xa00c85a4
a00c8494:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c8498:  94 13 20 78  or  %o4, 0x78, %o2	! 0xa802d078
a00c849c:  b0 10 20 30  mov  0x30, %i0
a00c84a0:  96 10 20 35  mov  0x35, %o3
a00c84a4:  92 10 20 36  mov  0x36, %o1
a00c84a8:  90 10 20 2b  mov  0x2b, %o0
a00c84ac:  82 10 20 0d  mov  0xd, %g1
a00c84b0:  d6 2b 20 78  stb  %o3, [ %o4 + 0x78 ]
a00c84b4:  d2 2a a0 01  stb  %o1, [ %o2 + 1 ]
a00c84b8:  f0 2a a0 03  stb  %i0, [ %o2 + 3 ]
a00c84bc:  d0 2a a0 04  stb  %o0, [ %o2 + 4 ]
a00c84c0:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00c84c4:  80 a4 20 02  cmp  %l0, 2
a00c84c8:  02 80 00 21  be  0xa00c854c
a00c84cc:  f0 2a a0 02  stb  %i0, [ %o2 + 2 ]
a00c84d0:  80 a4 20 03  cmp  %l0, 3
a00c84d4:  02 80 00 41  be  0xa00c85d8
a00c84d8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c84dc:  90 12 60 d0  or  %o1, 0xd0, %o0	! 0xa802d0d0
a00c84e0:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c84e4:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]	! 0xa802b09c
a00c84e8:  c0 2a 60 d0  clrb  [ %o1 + 0xd0 ]
a00c84ec:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c84f0:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c84f4:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c84f8:  80 a4 20 02  cmp  %l0, 2
a00c84fc:  02 80 00 1d  be  0xa00c8570
a00c8500:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c8504:  80 a4 20 03  cmp  %l0, 3
a00c8508:  12 80 00 1d  bne  0xa00c857c
a00c850c:  90 10 00 10  mov  %l0, %o0
a00c8510:  10 80 00 3c  b  0xa00c8600
a00c8514:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c8518:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c851c:  9e 12 21 28  or  %o0, 0x128, %o7	! 0xa802d128
a00c8520:  a0 10 20 30  mov  0x30, %l0
a00c8524:  92 10 20 35  mov  0x35, %o1
a00c8528:  82 10 20 0d  mov  0xd, %g1
a00c852c:  b0 10 20 36  mov  0x36, %i0
a00c8530:  a2 10 20 2b  mov  0x2b, %l1
a00c8534:  d2 2a 21 28  stb  %o1, [ %o0 + 0x128 ]
a00c8538:  c2 2b e0 05  stb  %g1, [ %o7 + 5 ]
a00c853c:  f0 2b e0 01  stb  %i0, [ %o7 + 1 ]
a00c8540:  e0 2b e0 03  stb  %l0, [ %o7 + 3 ]
a00c8544:  e2 2b e0 04  stb  %l1, [ %o7 + 4 ]
a00c8548:  e0 2b e0 02  stb  %l0, [ %o7 + 2 ]
a00c854c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c8550:  94 13 60 40  or  %o5, 0x40, %o2	! 0xa802d040
a00c8554:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00c8558:  c0 2b e0 9a  clrb  [ %o7 + 0x9a ]	! 0xa802b09a
a00c855c:  c0 2b 60 40  clrb  [ %o5 + 0x40 ]
a00c8560:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c8564:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c8568:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c856c:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c8570:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c8574:  94 13 21 28  or  %o4, 0x128, %o2	! 0xa802d128
a00c8578:  90 10 20 02  mov  2, %o0
a00c857c:  40 02 00 9b  call  0xa01487e8
a00c8580:  92 10 20 06  mov  6, %o1
a00c8584:  10 80 00 22  b  0xa00c860c
a00c8588:  b0 10 20 00  clr  %i0
a00c858c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c8590:  10 bf ff a8  b  0xa00c8430
a00c8594:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c8598:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c859c:  10 bf ff a5  b  0xa00c8430
a00c85a0:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c85a4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c85a8:  98 14 21 08  or  %l0, 0x108, %o4	! 0xa802d108
a00c85ac:  94 10 20 30  mov  0x30, %o2
a00c85b0:  a2 10 20 35  mov  0x35, %l1
a00c85b4:  9e 10 20 0d  mov  0xd, %o7
a00c85b8:  9a 10 20 36  mov  0x36, %o5
a00c85bc:  96 10 20 2b  mov  0x2b, %o3
a00c85c0:  e2 2c 21 08  stb  %l1, [ %l0 + 0x108 ]
a00c85c4:  de 2b 20 05  stb  %o7, [ %o4 + 5 ]
a00c85c8:  da 2b 20 01  stb  %o5, [ %o4 + 1 ]
a00c85cc:  d4 2b 20 03  stb  %o2, [ %o4 + 3 ]
a00c85d0:  d6 2b 20 04  stb  %o3, [ %o4 + 4 ]
a00c85d4:  d4 2b 20 02  stb  %o2, [ %o4 + 2 ]
a00c85d8:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c85dc:  a0 14 60 98  or  %l1, 0x98, %l0	! 0xa802d098
a00c85e0:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00c85e4:  c0 2e 20 98  clrb  [ %i0 + 0x98 ]	! 0xa802b098
a00c85e8:  c0 2c 60 98  clrb  [ %l1 + 0x98 ]
a00c85ec:  c0 2c 20 19  clrb  [ %l0 + 0x19 ]
a00c85f0:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a00c85f4:  c0 2c 20 07  clrb  [ %l0 + 7 ]
a00c85f8:  c0 2c 20 0a  clrb  [ %l0 + 0xa ]
a00c85fc:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c8600:  94 12 e1 08  or  %o3, 0x108, %o2	! 0xa802d108
a00c8604:  10 bf ff de  b  0xa00c857c
a00c8608:  90 10 20 03  mov  3, %o0
a00c860c:  81 c7 e0 08  ret
a00c8610:  81 e8 00 00  restore
