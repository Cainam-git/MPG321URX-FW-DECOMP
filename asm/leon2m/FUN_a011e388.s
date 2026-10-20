# leon2m FUN_a011e388 0xa011e388-0xa011e438 (48 bytes)
a011e388:  82 0a 20 ff  and  %o0, 0xff, %g1
a011e38c:  80 a0 60 1f  cmp  %g1, 0x1f
a011e390:  18 80 00 28  bgu  0xa011e430
a011e394:  92 0a 60 01  and  %o1, 1, %o1
a011e398:  11 00 02 f5  sethi  %hi(0xbd400), %o0
a011e39c:  83 28 60 02  sll  %g1, 2, %g1
a011e3a0:  9a 12 21 70  or  %o0, 0x170, %o5
a011e3a4:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a011e3a8:  81 c3 00 00  jmp  %o4
a011e3ac:  01 00 00 00  nop
a011e3b0:  19 33 c0 59  sethi  %hi(0xcf016400), %o4
a011e3b4:  90 0a 60 ff  and  %o1, 0xff, %o0
a011e3b8:  d2 03 00 00  ld  [ %o4 ], %o1
a011e3bc:  82 0a 60 bf  and  %o1, 0xbf, %g1
a011e3c0:  9b 2a 20 06  sll  %o0, 6, %o5
a011e3c4:  92 10 40 0d  or  %g1, %o5, %o1
a011e3c8:  d2 23 00 00  st  %o1, [ %o4 ]
a011e3cc:  30 80 00 19  b,a   0xa011e430
a011e3d0:  19 33 c0 58  sethi  %hi(0xcf016000), %o4
a011e3d4:  10 bf ff f8  b  0xa011e3b4
a011e3d8:  98 13 21 20  or  %o4, 0x120, %o4	! 0xcf016120
a011e3dc:  03 33 c0 58  sethi  %hi(0xcf016000), %g1
a011e3e0:  10 bf ff f5  b  0xa011e3b4
a011e3e4:  98 10 61 38  or  %g1, 0x138, %o4	! 0xcf016138
a011e3e8:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a011e3ec:  10 bf ff f2  b  0xa011e3b4
a011e3f0:  98 13 61 50  or  %o5, 0x150, %o4	! 0xcf016150
a011e3f4:  11 33 c0 58  sethi  %hi(0xcf016000), %o0
a011e3f8:  10 bf ff ef  b  0xa011e3b4
a011e3fc:  98 12 21 68  or  %o0, 0x168, %o4	! 0xcf016168
a011e400:  19 33 c0 58  sethi  %hi(0xcf016000), %o4
a011e404:  10 bf ff ec  b  0xa011e3b4
a011e408:  98 13 21 80  or  %o4, 0x180, %o4	! 0xcf016180
a011e40c:  03 33 c0 58  sethi  %hi(0xcf016000), %g1
a011e410:  10 bf ff e9  b  0xa011e3b4
a011e414:  98 10 61 98  or  %g1, 0x198, %o4	! 0xcf016198
a011e418:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011e41c:  10 bf ff e6  b  0xa011e3b4
a011e420:  98 13 60 94  or  %o5, 0x94, %o4	! 0xcf016494
a011e424:  11 33 c0 59  sethi  %hi(0xcf016400), %o0
a011e428:  10 bf ff e3  b  0xa011e3b4
a011e42c:  98 12 20 c0  or  %o0, 0xc0, %o4	! 0xcf0164c0
a011e430:  81 c3 e0 08  retl
a011e434:  01 00 00 00  nop
