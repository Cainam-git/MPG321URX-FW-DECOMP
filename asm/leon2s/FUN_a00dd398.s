# leon2s FUN_a00dd398 0xa00dd398-0xa00dd488 (240 bytes)
a00dd398:  9d e3 bf 98  save  %sp, -104, %sp
a00dd39c:  3b 2a 01 e5  sethi  %hi(0xa8079400), %i5
a00dd3a0:  ba 17 61 38  or  %i5, 0x138, %i5	! 0xa8079538
a00dd3a4:  c2 06 20 14  ld  [ %i0 + 0x14 ], %g1
a00dd3a8:  c2 2f 60 18  stb  %g1, [ %i5 + 0x18 ]
a00dd3ac:  c2 06 20 14  ld  [ %i0 + 0x14 ], %g1
a00dd3b0:  83 30 60 08  srl  %g1, 8, %g1
a00dd3b4:  c2 2f 60 05  stb  %g1, [ %i5 + 5 ]
a00dd3b8:  f8 0e 20 06  ldub  [ %i0 + 6 ], %i4
a00dd3bc:  d8 06 20 04  ld  [ %i0 + 4 ], %o4
a00dd3c0:  a5 2f 20 08  sll  %i4, 8, %l2
a00dd3c4:  b9 33 20 18  srl  %o4, 0x18, %i4
a00dd3c8:  a3 2f 20 08  sll  %i4, 8, %l1
a00dd3cc:  f8 0e 20 0a  ldub  [ %i0 + 0xa ], %i4
a00dd3d0:  de 06 20 08  ld  [ %i0 + 8 ], %o7
a00dd3d4:  a1 2f 20 08  sll  %i4, 8, %l0
a00dd3d8:  b9 33 e0 18  srl  %o7, 0x18, %i4
a00dd3dc:  91 2f 20 08  sll  %i4, 8, %o0
a00dd3e0:  f8 0e 20 0e  ldub  [ %i0 + 0xe ], %i4
a00dd3e4:  f4 06 20 0c  ld  [ %i0 + 0xc ], %i2
a00dd3e8:  93 2f 20 08  sll  %i4, 8, %o1
a00dd3ec:  b9 36 a0 18  srl  %i2, 0x18, %i4
a00dd3f0:  95 2f 20 08  sll  %i4, 8, %o2
a00dd3f4:  c2 06 20 10  ld  [ %i0 + 0x10 ], %g1
a00dd3f8:  f8 0e 20 12  ldub  [ %i0 + 0x12 ], %i4
a00dd3fc:  97 2f 20 08  sll  %i4, 8, %o3
a00dd400:  b1 36 a0 10  srl  %i2, 0x10, %i0
a00dd404:  b7 33 20 10  srl  %o4, 0x10, %i3
a00dd408:  b3 33 e0 10  srl  %o7, 0x10, %i1
a00dd40c:  9b 30 60 10  srl  %g1, 0x10, %o5
a00dd410:  b9 30 60 18  srl  %g1, 0x18, %i4
a00dd414:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00dd418:  94 02 80 18  add  %o2, %i0, %o2
a00dd41c:  b6 0e e0 ff  and  %i3, 0xff, %i3
a00dd420:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00dd424:  b9 2f 20 08  sll  %i4, 8, %i4
a00dd428:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00dd42c:  98 0b 20 ff  and  %o4, 0xff, %o4
a00dd430:  9e 0b e0 ff  and  %o7, 0xff, %o7
a00dd434:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00dd438:  82 08 60 ff  and  %g1, 0xff, %g1
a00dd43c:  a4 04 80 0c  add  %l2, %o4, %l2
a00dd440:  a2 04 40 1b  add  %l1, %i3, %l1
a00dd444:  a0 04 00 0f  add  %l0, %o7, %l0
a00dd448:  90 02 00 19  add  %o0, %i1, %o0
a00dd44c:  92 02 40 1a  add  %o1, %i2, %o1
a00dd450:  96 02 c0 01  add  %o3, %g1, %o3
a00dd454:  b8 07 00 0d  add  %i4, %o5, %i4
a00dd458:  31 27 c7 3b  sethi  %hi(0x9f1cec00), %i0
a00dd45c:  f8 37 60 16  sth  %i4, [ %i5 + 0x16 ]
a00dd460:  e4 37 60 08  sth  %l2, [ %i5 + 8 ]
a00dd464:  e2 37 60 0a  sth  %l1, [ %i5 + 0xa ]
a00dd468:  e0 37 60 0c  sth  %l0, [ %i5 + 0xc ]
a00dd46c:  d0 37 60 0e  sth  %o0, [ %i5 + 0xe ]
a00dd470:  d2 37 60 10  sth  %o1, [ %i5 + 0x10 ]
a00dd474:  d4 37 60 12  sth  %o2, [ %i5 + 0x12 ]
a00dd478:  d6 37 60 14  sth  %o3, [ %i5 + 0x14 ]
a00dd47c:  40 3a 96 f2  call  0xa0f83044
a00dd480:  91 ee 20 d0  restore  %i0, 0xd0, %o0
a00dd484:  01 00 00 00  nop
