# leon2m FUN_a011e438 0xa011e438-0xa011e4c8 (48 bytes)
a011e438:  82 0a 20 ff  and  %o0, 0xff, %g1
a011e43c:  80 a0 60 06  cmp  %g1, 6
a011e440:  18 80 00 20  bgu  0xa011e4c0
a011e444:  92 0a 60 01  and  %o1, 1, %o1
a011e448:  11 00 02 f5  sethi  %hi(0xbd400), %o0
a011e44c:  83 28 60 02  sll  %g1, 2, %g1
a011e450:  9a 12 21 f0  or  %o0, 0x1f0, %o5
a011e454:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a011e458:  81 c3 00 00  jmp  %o4
a011e45c:  01 00 00 00  nop
a011e460:  03 33 c0 58  sethi  %hi(0xcf016000), %g1
a011e464:  98 10 61 98  or  %g1, 0x198, %o4	! 0xcf016198
a011e468:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011e46c:  c2 03 00 00  ld  [ %o4 ], %g1
a011e470:  90 08 60 f7  and  %g1, 0xf7, %o0
a011e474:  9b 2b 60 03  sll  %o5, 3, %o5
a011e478:  92 12 00 0d  or  %o0, %o5, %o1
a011e47c:  d2 23 00 00  st  %o1, [ %o4 ]
a011e480:  30 80 00 10  b,a   0xa011e4c0
a011e484:  19 33 c0 58  sethi  %hi(0xcf016000), %o4
a011e488:  10 bf ff f8  b  0xa011e468
a011e48c:  98 13 21 20  or  %o4, 0x120, %o4	! 0xcf016120
a011e490:  03 33 c0 58  sethi  %hi(0xcf016000), %g1
a011e494:  10 bf ff f5  b  0xa011e468
a011e498:  98 10 61 38  or  %g1, 0x138, %o4	! 0xcf016138
a011e49c:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a011e4a0:  10 bf ff f2  b  0xa011e468
a011e4a4:  98 13 61 50  or  %o5, 0x150, %o4	! 0xcf016150
a011e4a8:  11 33 c0 58  sethi  %hi(0xcf016000), %o0
a011e4ac:  10 bf ff ef  b  0xa011e468
a011e4b0:  98 12 21 68  or  %o0, 0x168, %o4	! 0xcf016168
a011e4b4:  19 33 c0 58  sethi  %hi(0xcf016000), %o4
a011e4b8:  10 bf ff ec  b  0xa011e468
a011e4bc:  98 13 21 80  or  %o4, 0x180, %o4	! 0xcf016180
a011e4c0:  81 c3 e0 08  retl
a011e4c4:  01 00 00 00  nop
