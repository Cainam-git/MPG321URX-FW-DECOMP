# leon2m FUN_a010c390 0xa010c390-0xa010c4a0 (272 bytes)
a010c390:  94 0a 20 ff  and  %o0, 0xff, %o2
a010c394:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010c398:  98 10 00 09  mov  %o1, %o4
a010c39c:  80 a2 a0 01  cmp  %o2, 1
a010c3a0:  02 80 00 06  be  0xa010c3b8
a010c3a4:  82 10 63 c4  or  %g1, 0x3c4, %g1
a010c3a8:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a010c3ac:  80 a2 a0 02  cmp  %o2, 2
a010c3b0:  02 80 00 37  be  0xa010c48c
a010c3b4:  82 12 63 44  or  %o1, 0x344, %g1
a010c3b8:  80 a2 a0 02  cmp  %o2, 2
a010c3bc:  08 80 00 03  bleu  0xa010c3c8
a010c3c0:  d8 28 60 26  stb  %o4, [ %g1 + 0x26 ]
a010c3c4:  90 10 20 00  clr  %o0
a010c3c8:  82 0a 20 ff  and  %o0, 0xff, %g1
a010c3cc:  17 00 06 6b  sethi  %hi(0x19ac00), %o3
a010c3d0:  9b 28 60 02  sll  %g1, 2, %o5
a010c3d4:  92 12 e2 d8  or  %o3, 0x2d8, %o1
a010c3d8:  d0 02 40 0d  ld  [ %o1 + %o5 ], %o0
a010c3dc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a010c3e0:  d6 02 20 10  ld  [ %o0 + 0x10 ], %o3
a010c3e4:  03 00 3f c0  sethi  %hi(0xff0000), %g1
a010c3e8:  90 2a c0 01  andn  %o3, %g1, %o0
a010c3ec:  99 2b 60 10  sll  %o5, 0x10, %o4
a010c3f0:  9a 12 00 0c  or  %o0, %o4, %o5
a010c3f4:  80 a2 a0 02  cmp  %o2, 2
a010c3f8:  08 80 00 14  bleu  0xa010c448
a010c3fc:  90 13 60 01  or  %o5, 1, %o0
a010c400:  96 10 00 09  mov  %o1, %o3
a010c404:  98 10 20 00  clr  %o4
a010c408:  9b 2b 20 02  sll  %o4, 2, %o5
a010c40c:  d2 02 c0 0d  ld  [ %o3 + %o5 ], %o1
a010c410:  98 03 20 01  inc  %o4
a010c414:  d0 22 60 10  st  %o0, [ %o1 + 0x10 ]
a010c418:  80 a3 20 02  cmp  %o4, 2
a010c41c:  28 bf ff fc  bleu,a   0xa010c40c
a010c420:  9b 2b 20 02  sll  %o4, 2, %o5
a010c424:  80 a2 a0 02  cmp  %o2, 2
a010c428:  38 80 00 0f  bgu,a   0xa010c464
a010c42c:  15 00 06 6b  sethi  %hi(0x19ac00), %o2
a010c430:  99 2a a0 02  sll  %o2, 2, %o4
a010c434:  15 00 06 6b  sethi  %hi(0x19ac00), %o2
a010c438:  82 12 a2 cc  or  %o2, 0x2cc, %g1	! 0x19aecc
a010c43c:  d6 00 40 0c  ld  [ %g1 + %o4 ], %o3
a010c440:  d0 22 e0 10  st  %o0, [ %o3 + 0x10 ]
a010c444:  30 80 00 15  b,a   0xa010c498
a010c448:  83 2a a0 02  sll  %o2, 2, %g1
a010c44c:  d8 02 40 01  ld  [ %o1 + %g1 ], %o4
a010c450:  d0 23 20 10  st  %o0, [ %o4 + 0x10 ]
a010c454:  80 a2 a0 02  cmp  %o2, 2
a010c458:  08 bf ff f7  bleu  0xa010c434
a010c45c:  99 2a a0 02  sll  %o2, 2, %o4
a010c460:  15 00 06 6b  sethi  %hi(0x19ac00), %o2
a010c464:  96 12 a2 cc  or  %o2, 0x2cc, %o3	! 0x19aecc
a010c468:  98 10 20 00  clr  %o4
a010c46c:  9b 2b 20 02  sll  %o4, 2, %o5
a010c470:  d2 02 c0 0d  ld  [ %o3 + %o5 ], %o1
a010c474:  98 03 20 01  inc  %o4
a010c478:  d0 22 60 10  st  %o0, [ %o1 + 0x10 ]
a010c47c:  80 a3 20 02  cmp  %o4, 2
a010c480:  08 bf ff fc  bleu  0xa010c470
a010c484:  9b 2b 20 02  sll  %o4, 2, %o5
a010c488:  30 80 00 04  b,a   0xa010c498
a010c48c:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a010c490:  10 bf ff ca  b  0xa010c3b8
a010c494:  82 12 e3 84  or  %o3, 0x384, %g1	! 0xa802d784
a010c498:  81 c3 e0 08  retl
a010c49c:  01 00 00 00  nop
