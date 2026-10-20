# leon2m FUN_a002e46c 0xa002e46c-0xa002e658 (492 bytes)
a002e46c:  9d e3 bf 98  save  %sp, -104, %sp
a002e470:  82 0e 20 ff  and  %i0, 0xff, %g1
a002e474:  80 a0 60 18  cmp  %g1, 0x18
a002e478:  18 80 00 76  bgu  0xa002e650
a002e47c:  90 10 20 00  clr  %o0
a002e480:  11 28 00 b9  sethi  %hi(0xa002e400), %o0
a002e484:  83 28 60 02  sll  %g1, 2, %g1
a002e488:  9a 12 20 08  or  %o0, 8, %o5
a002e48c:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a002e490:  81 c3 00 00  jmp  %o4
a002e494:  01 00 00 00  nop
a002e498:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a002e49c:  10 80 00 6d  b  0xa002e650
a002e4a0:  d0 02 e1 98  ld  [ %o3 + 0x198 ], %o0	! 0xa802c998
a002e4a4:  1b 33 c0 46  sethi  %hi(0xcf011800), %o5
a002e4a8:  58 01 93 2f  call  0x93164
a002e4ac:  90 13 61 10  or  %o5, 0x110, %o0	! 0xcf011910
a002e4b0:  30 80 00 68  b,a   0xa002e650
a002e4b4:  03 33 c0 46  sethi  %hi(0xcf011800), %g1
a002e4b8:  58 01 93 2b  call  0x93164
a002e4bc:  90 10 60 e0  or  %g1, 0xe0, %o0	! 0xcf0118e0
a002e4c0:  30 80 00 64  b,a   0xa002e650
a002e4c4:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a002e4c8:  58 01 93 27  call  0x93164
a002e4cc:  90 16 20 b0  or  %i0, 0xb0, %o0	! 0xcf0118b0
a002e4d0:  30 80 00 60  b,a   0xa002e650
a002e4d4:  1f 33 c0 46  sethi  %hi(0xcf011800), %o7
a002e4d8:  90 13 e0 80  or  %o7, 0x80, %o0	! 0xcf011880
a002e4dc:  58 01 93 22  call  0x93164
a002e4e0:  01 00 00 00  nop
a002e4e4:  30 80 00 5b  b,a   0xa002e650
a002e4e8:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a002e4ec:  10 80 00 59  b  0xa002e650
a002e4f0:  d0 03 21 94  ld  [ %o4 + 0x194 ], %o0	! 0xa802c994
a002e4f4:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a002e4f8:  d8 03 61 90  ld  [ %o5 + 0x190 ], %o4	! 0xa802c990
a002e4fc:  1b 00 0b 00  sethi  %hi(0x2c0000), %o5
a002e500:  10 80 00 54  b  0xa002e650
a002e504:  90 03 00 0d  add  %o4, %o5, %o0
a002e508:  11 2a 00 b2  sethi  %hi(0xa802c800), %o0
a002e50c:  d8 02 21 90  ld  [ %o0 + 0x190 ], %o4	! 0xa802c990
a002e510:  1b 00 0b 40  sethi  %hi(0x2d0000), %o5
a002e514:  10 80 00 4f  b  0xa002e650
a002e518:  90 03 00 0d  add  %o4, %o5, %o0
a002e51c:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a002e520:  d8 02 a1 90  ld  [ %o2 + 0x190 ], %o4	! 0xa802c990
a002e524:  1b 00 0c 00  sethi  %hi(0x300000), %o5
a002e528:  10 80 00 4a  b  0xa002e650
a002e52c:  90 03 00 0d  add  %o4, %o5, %o0
a002e530:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a002e534:  d8 02 61 90  ld  [ %o1 + 0x190 ], %o4	! 0xa802c990
a002e538:  1b 00 0b c0  sethi  %hi(0x2f0000), %o5
a002e53c:  10 80 00 45  b  0xa002e650
a002e540:  90 03 00 0d  add  %o4, %o5, %o0
a002e544:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a002e548:  d8 00 61 90  ld  [ %g1 + 0x190 ], %o4	! 0xa802c990
a002e54c:  1b 00 0a c0  sethi  %hi(0x2b0000), %o5
a002e550:  10 80 00 40  b  0xa002e650
a002e554:  90 03 00 0d  add  %o4, %o5, %o0
a002e558:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a002e55c:  d8 06 21 90  ld  [ %i0 + 0x190 ], %o4	! 0xa802c990
a002e560:  1b 00 0a 80  sethi  %hi(0x2a0000), %o5
a002e564:  10 80 00 3b  b  0xa002e650
a002e568:  90 03 00 0d  add  %o4, %o5, %o0
a002e56c:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a002e570:  d8 03 e1 90  ld  [ %o7 + 0x190 ], %o4	! 0xa802c990
a002e574:  1b 00 0a 40  sethi  %hi(0x290000), %o5
a002e578:  10 80 00 36  b  0xa002e650
a002e57c:  90 03 00 0d  add  %o4, %o5, %o0
a002e580:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a002e584:  d8 02 e1 90  ld  [ %o3 + 0x190 ], %o4	! 0xa802c990
a002e588:  1b 00 0a 00  sethi  %hi(0x280000), %o5
a002e58c:  10 80 00 31  b  0xa002e650
a002e590:  90 03 00 0d  add  %o4, %o5, %o0
a002e594:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a002e598:  d8 02 a1 90  ld  [ %o2 + 0x190 ], %o4	! 0xa802c990
a002e59c:  1b 00 09 80  sethi  %hi(0x260000), %o5
a002e5a0:  10 80 00 2c  b  0xa002e650
a002e5a4:  90 03 00 0d  add  %o4, %o5, %o0
a002e5a8:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a002e5ac:  d8 02 61 90  ld  [ %o1 + 0x190 ], %o4	! 0xa802c990
a002e5b0:  1b 00 09 00  sethi  %hi(0x240000), %o5
a002e5b4:  10 80 00 27  b  0xa002e650
a002e5b8:  90 03 00 0d  add  %o4, %o5, %o0
a002e5bc:  11 2a 00 b2  sethi  %hi(0xa802c800), %o0
a002e5c0:  d8 02 21 90  ld  [ %o0 + 0x190 ], %o4	! 0xa802c990
a002e5c4:  1b 00 08 80  sethi  %hi(0x220000), %o5
a002e5c8:  10 80 00 22  b  0xa002e650
a002e5cc:  90 03 00 0d  add  %o4, %o5, %o0
a002e5d0:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a002e5d4:  d8 03 61 90  ld  [ %o5 + 0x190 ], %o4	! 0xa802c990
a002e5d8:  1b 00 08 00  sethi  %hi(0x200000), %o5
a002e5dc:  10 80 00 1d  b  0xa002e650
a002e5e0:  90 03 00 0d  add  %o4, %o5, %o0
a002e5e4:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a002e5e8:  d8 00 61 90  ld  [ %g1 + 0x190 ], %o4	! 0xa802c990
a002e5ec:  1b 00 07 00  sethi  %hi(0x1c0000), %o5
a002e5f0:  10 80 00 18  b  0xa002e650
a002e5f4:  90 03 00 0d  add  %o4, %o5, %o0
a002e5f8:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a002e5fc:  d8 06 21 90  ld  [ %i0 + 0x190 ], %o4	! 0xa802c990
a002e600:  1b 00 06 00  sethi  %hi(0x180000), %o5
a002e604:  10 80 00 13  b  0xa002e650
a002e608:  90 03 00 0d  add  %o4, %o5, %o0
a002e60c:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a002e610:  d8 03 e1 90  ld  [ %o7 + 0x190 ], %o4	! 0xa802c990
a002e614:  1b 00 05 00  sethi  %hi(0x140000), %o5
a002e618:  10 80 00 0e  b  0xa002e650
a002e61c:  90 03 00 0d  add  %o4, %o5, %o0
a002e620:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a002e624:  d8 02 e1 90  ld  [ %o3 + 0x190 ], %o4	! 0xa802c990
a002e628:  1b 00 03 00  sethi  %hi(0xc0000), %o5
a002e62c:  10 80 00 09  b  0xa002e650
a002e630:  90 03 00 0d  add  %o4, %o5, %o0
a002e634:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a002e638:  d8 02 a1 90  ld  [ %o2 + 0x190 ], %o4	! 0xa802c990
a002e63c:  1b 00 01 00  sethi  %hi(0x40000), %o5
a002e640:  10 80 00 04  b  0xa002e650
a002e644:  90 03 00 0d  add  %o4, %o5, %o0
a002e648:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a002e64c:  d0 02 61 90  ld  [ %o1 + 0x190 ], %o0	! 0xa802c990
a002e650:  81 c7 e0 08  ret
a002e654:  91 e8 00 08  restore  %g0, %o0, %o0
