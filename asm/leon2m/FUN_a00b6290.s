# leon2m FUN_a00b6290 0xa00b6290-0xa00b6514 (644 bytes)
a00b6290:  9d e3 bf 98  save  %sp, -104, %sp
a00b6294:  39 2a 00 b4  sethi  %hi(0xa802d000), %i4
a00b6298:  82 17 22 90  or  %i4, 0x290, %g1	! 0xa802d290
a00b629c:  d0 08 61 a3  ldub  [ %g1 + 0x1a3 ], %o0
a00b62a0:  9a 02 20 02  add  %o0, 2, %o5
a00b62a4:  80 8e 20 ff  btst  0xff, %i0
a00b62a8:  02 80 00 3e  be  0xa00b63a0
a00b62ac:  b4 0b 60 ff  and  %o5, 0xff, %i2
a00b62b0:  94 06 80 1a  add  %i2, %i2, %o2
a00b62b4:  92 02 a0 06  add  %o2, 6, %o1
a00b62b8:  a3 2a 60 10  sll  %o1, 0x10, %l1
a00b62bc:  a0 10 20 00  clr  %l0
a00b62c0:  a4 0c 20 ff  and  %l0, 0xff, %l2
a00b62c4:  9e 04 a0 2a  add  %l2, 0x2a, %o7
a00b62c8:  99 2b e0 10  sll  %o7, 0x10, %o4
a00b62cc:  93 33 20 10  srl  %o4, 0x10, %o1
a00b62d0:  96 10 20 01  mov  1, %o3
a00b62d4:  90 10 20 00  clr  %o0
a00b62d8:  95 34 60 10  srl  %l1, 0x10, %o2
a00b62dc:  98 10 20 00  clr  %o4
a00b62e0:  40 02 42 10  call  0xa0146b20
a00b62e4:  9a 10 20 00  clr  %o5
a00b62e8:  a0 04 20 01  inc  %l0
a00b62ec:  96 0c 20 ff  and  %l0, 0xff, %o3
a00b62f0:  80 a2 e0 07  cmp  %o3, 7
a00b62f4:  08 bf ff f4  bleu  0xa00b62c4
a00b62f8:  a4 0c 20 ff  and  %l0, 0xff, %l2
a00b62fc:  a4 10 20 00  clr  %l2
a00b6300:  82 10 20 00  clr  %g1
a00b6304:  3b 00 00 2d  sethi  %hi(0xb400), %i5
a00b6308:  9a 00 40 1a  add  %g1, %i2, %o5
a00b630c:  80 a0 00 01  cmp  %g0, %g1
a00b6310:  b6 03 40 0d  add  %o5, %o5, %i3
a00b6314:  b2 40 20 00  addx  %g0, 0, %i1
a00b6318:  a0 06 e0 05  add  %i3, 5, %l0
a00b631c:  90 10 20 2a  mov  0x2a, %o0
a00b6320:  92 10 00 10  mov  %l0, %o1
a00b6324:  94 10 20 02  mov  2, %o2
a00b6328:  96 17 62 9a  or  %i5, 0x29a, %o3
a00b632c:  98 10 20 00  clr  %o4
a00b6330:  40 02 41 d4  call  0xa0146a80
a00b6334:  b0 06 7f a4  add  %i1, -92, %i0
a00b6338:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00b633c:  9a 10 20 00  clr  %o5
a00b6340:  90 10 20 00  clr  %o0
a00b6344:  92 10 20 2a  mov  0x2a, %o1
a00b6348:  94 10 00 10  mov  %l0, %o2
a00b634c:  96 10 20 02  mov  2, %o3
a00b6350:  40 02 41 f4  call  0xa0146b20
a00b6354:  98 10 00 11  mov  %l1, %o4
a00b6358:  90 10 20 2d  mov  0x2d, %o0
a00b635c:  92 10 00 10  mov  %l0, %o1
a00b6360:  94 10 20 02  mov  2, %o2
a00b6364:  96 17 62 9a  or  %i5, 0x29a, %o3
a00b6368:  40 02 41 c6  call  0xa0146a80
a00b636c:  98 10 20 00  clr  %o4
a00b6370:  94 10 00 10  mov  %l0, %o2
a00b6374:  98 10 00 11  mov  %l1, %o4
a00b6378:  90 10 20 00  clr  %o0
a00b637c:  92 10 20 2d  mov  0x2d, %o1
a00b6380:  96 10 20 02  mov  2, %o3
a00b6384:  40 02 41 e7  call  0xa0146b20
a00b6388:  9a 10 20 00  clr  %o5
a00b638c:  a4 04 a0 01  inc  %l2
a00b6390:  82 0c a0 ff  and  %l2, 0xff, %g1
a00b6394:  80 a0 60 01  cmp  %g1, 1
a00b6398:  28 bf ff dd  bleu,a   0xa00b630c
a00b639c:  9a 00 40 1a  add  %g1, %i2, %o5
a00b63a0:  b6 17 22 90  or  %i4, 0x290, %i3
a00b63a4:  c2 0e e1 a3  ldub  [ %i3 + 0x1a3 ], %g1
a00b63a8:  94 00 40 1b  add  %g1, %i3, %o2
a00b63ac:  17 33 33 33  sethi  %hi(0xcccccc00), %o3
a00b63b0:  a0 12 e0 cd  or  %o3, 0xcd, %l0	! 0xcccccccd
a00b63b4:  fa 0a a1 98  ldub  [ %o2 + 0x198 ], %i5
a00b63b8:  80 57 40 10  umul  %i5, %l0, %g0
a00b63bc:  93 40 00 00  rd  %y, %o1
a00b63c0:  91 32 60 03  srl  %o1, 3, %o0
a00b63c4:  9a 02 20 02  add  %o0, 2, %o5
a00b63c8:  a2 06 80 1a  add  %i2, %i2, %l1
a00b63cc:  ba 04 60 06  add  %l1, 6, %i5
a00b63d0:  98 0b 60 ff  and  %o5, 0xff, %o4
a00b63d4:  90 10 20 00  clr  %o0
a00b63d8:  92 10 20 2a  mov  0x2a, %o1
a00b63dc:  94 10 00 1d  mov  %i5, %o2
a00b63e0:  96 10 20 01  mov  1, %o3
a00b63e4:  40 02 41 cf  call  0xa0146b20
a00b63e8:  9a 10 20 00  clr  %o5
a00b63ec:  f2 0e e1 a3  ldub  [ %i3 + 0x1a3 ], %i1
a00b63f0:  b0 06 40 1b  add  %i1, %i3, %i0
a00b63f4:  d4 0e 21 98  ldub  [ %i0 + 0x198 ], %o2
a00b63f8:  80 52 80 10  umul  %o2, %l0, %g0
a00b63fc:  a5 40 00 00  rd  %y, %l2
a00b6400:  9f 34 a0 03  srl  %l2, 3, %o7
a00b6404:  99 2b e0 02  sll  %o7, 2, %o4
a00b6408:  96 03 00 0f  add  %o4, %o7, %o3
a00b640c:  82 02 c0 0b  add  %o3, %o3, %g1
a00b6410:  92 22 80 01  sub  %o2, %g1, %o1
a00b6414:  90 02 60 02  add  %o1, 2, %o0
a00b6418:  98 0a 20 ff  and  %o0, 0xff, %o4
a00b641c:  90 10 20 00  clr  %o0
a00b6420:  92 10 20 2b  mov  0x2b, %o1
a00b6424:  94 10 00 1d  mov  %i5, %o2
a00b6428:  96 10 20 01  mov  1, %o3
a00b642c:  40 02 41 bd  call  0xa0146b20
a00b6430:  9a 10 20 00  clr  %o5
a00b6434:  90 10 27 46  mov  0x746, %o0
a00b6438:  40 02 41 9e  call  0xa0146ab0
a00b643c:  92 10 20 00  clr  %o1
a00b6440:  a2 0f 60 ff  and  %i5, 0xff, %l1
a00b6444:  a0 10 20 00  clr  %l0
a00b6448:  a4 0c 20 ff  and  %l0, 0xff, %l2
a00b644c:  9e 04 a0 2c  add  %l2, 0x2c, %o7
a00b6450:  99 2b e0 10  sll  %o7, 0x10, %o4
a00b6454:  93 33 20 10  srl  %o4, 0x10, %o1
a00b6458:  90 10 20 01  mov  1, %o0
a00b645c:  94 10 00 11  mov  %l1, %o2
a00b6460:  96 10 20 01  mov  1, %o3
a00b6464:  98 10 20 0c  mov  0xc, %o4
a00b6468:  40 02 41 ae  call  0xa0146b20
a00b646c:  9a 10 20 00  clr  %o5
a00b6470:  a0 04 20 01  inc  %l0
a00b6474:  80 8c 20 ff  btst  0xff, %l0
a00b6478:  02 bf ff f5  be  0xa00b644c
a00b647c:  a4 0c 20 ff  and  %l0, 0xff, %l2
a00b6480:  a2 17 22 90  or  %i4, 0x290, %l1
a00b6484:  f0 0c 61 a3  ldub  [ %l1 + 0x1a3 ], %i0
a00b6488:  b8 06 00 11  add  %i0, %l1, %i4
a00b648c:  21 33 33 33  sethi  %hi(0xcccccc00), %l0
a00b6490:  ba 14 20 cd  or  %l0, 0xcd, %i5	! 0xcccccccd
a00b6494:  e4 0f 21 9c  ldub  [ %i4 + 0x19c ], %l2
a00b6498:  80 54 80 1d  umul  %l2, %i5, %g0
a00b649c:  9f 40 00 00  rd  %y, %o7
a00b64a0:  99 33 e0 03  srl  %o7, 3, %o4
a00b64a4:  b4 06 80 1a  add  %i2, %i2, %i2
a00b64a8:  82 03 20 02  add  %o4, 2, %g1
a00b64ac:  b4 06 a0 06  add  %i2, 6, %i2
a00b64b0:  90 10 20 00  clr  %o0
a00b64b4:  92 10 20 2d  mov  0x2d, %o1
a00b64b8:  94 10 00 1a  mov  %i2, %o2
a00b64bc:  96 10 20 01  mov  1, %o3
a00b64c0:  9a 10 20 00  clr  %o5
a00b64c4:  40 02 41 97  call  0xa0146b20
a00b64c8:  98 08 60 ff  and  %g1, 0xff, %o4
a00b64cc:  d6 0c 61 a3  ldub  [ %l1 + 0x1a3 ], %o3
a00b64d0:  94 02 c0 11  add  %o3, %l1, %o2
a00b64d4:  f0 0a a1 9c  ldub  [ %o2 + 0x19c ], %i0
a00b64d8:  80 56 00 1d  umul  %i0, %i5, %g0
a00b64dc:  93 40 00 00  rd  %y, %o1
a00b64e0:  91 32 60 03  srl  %o1, 3, %o0
a00b64e4:  9b 2a 20 02  sll  %o0, 2, %o5
a00b64e8:  b6 03 40 08  add  %o5, %o0, %i3
a00b64ec:  b2 06 c0 1b  add  %i3, %i3, %i1
a00b64f0:  a0 26 00 19  sub  %i0, %i1, %l0
a00b64f4:  b8 04 20 02  add  %l0, 2, %i4
a00b64f8:  b8 0f 20 ff  and  %i4, 0xff, %i4
a00b64fc:  b0 10 20 00  clr  %i0
a00b6500:  b2 10 20 2e  mov  0x2e, %i1
a00b6504:  b6 10 20 01  mov  1, %i3
a00b6508:  40 02 41 86  call  0xa0146b20
a00b650c:  9b e8 20 00  restore  %g0, 0, %o5
a00b6510:  01 00 00 00  nop
