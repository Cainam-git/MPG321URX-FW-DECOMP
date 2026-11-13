# leon2m FUN_a0091668 0xa0091668-0xa0091710 (168 bytes)
a0091668:  9d e3 bf 98  save  %sp, -104, %sp
a009166c:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0091670:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1	! 0xa802afec
a0091674:  90 02 7f fe  add  %o1, -2, %o0
a0091678:  90 0a 20 ff  and  %o0, 0xff, %o0
a009167c:  40 00 8a b2  call  0xa00b4144
a0091680:  92 10 20 02  mov  2, %o1
a0091684:  82 10 20 0b  mov  0xb, %g1
a0091688:  1b 15 55 55  sethi  %hi(0x55555400), %o5
a009168c:  c2 26 63 ec  st  %g1, [ %i1 + 0x3ec ]
a0091690:  b0 13 61 56  or  %o5, 0x156, %i0
a0091694:  10 80 00 0c  b  0xa00916c4
a0091698:  a0 10 00 19  mov  %i1, %l0
a009169c:  90 03 ff f6  add  %o7, -10, %o0
a00916a0:  80 5a 00 18  smul  %o0, %i0, %g0
a00916a4:  99 40 00 00  rd  %y, %o4
a00916a8:  97 3a 20 1f  sra  %o0, 0x1f, %o3
a00916ac:  94 23 00 0b  sub  %o4, %o3, %o2
a00916b0:  92 02 80 0a  add  %o2, %o2, %o1
a00916b4:  82 02 40 0a  add  %o1, %o2, %g1
a00916b8:  9a 22 00 01  sub  %o0, %g1, %o5
a00916bc:  9e 03 60 0b  add  %o5, 0xb, %o7
a00916c0:  de 26 63 ec  st  %o7, [ %i1 + 0x3ec ]
a00916c4:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a00916c8:  96 03 3f f5  add  %o4, -11, %o3
a00916cc:  40 00 63 95  call  0xa00aa520
a00916d0:  90 0a e0 ff  and  %o3, 0xff, %o0
a00916d4:  94 0a 20 ff  and  %o0, 0xff, %o2
a00916d8:  80 a2 a0 01  cmp  %o2, 1
a00916dc:  12 bf ff f0  bne  0xa009169c
a00916e0:  de 16 63 ee  lduh  [ %i1 + 0x3ee ], %o7
a00916e4:  d0 04 23 ec  ld  [ %l0 + 0x3ec ], %o0
a00916e8:  9a 02 3f f5  add  %o0, -11, %o5
a00916ec:  90 0b 60 ff  and  %o5, 0xff, %o0
a00916f0:  40 00 5e 47  call  0xa00a900c
a00916f4:  92 10 20 01  mov  1, %o1
a00916f8:  f2 04 23 ec  ld  [ %l0 + 0x3ec ], %i1
a00916fc:  b0 06 7f f5  add  %i1, -11, %i0
a0091700:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0091704:  40 00 63 6f  call  0xa00aa4c0
a0091708:  93 e8 20 01  restore  %g0, 1, %o1
a009170c:  01 00 00 00  nop
