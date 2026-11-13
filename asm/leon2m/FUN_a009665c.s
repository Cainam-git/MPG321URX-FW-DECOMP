# leon2m FUN_a009665c 0xa009665c-0xa0096704 (168 bytes)
a009665c:  9d e3 bf 98  save  %sp, -104, %sp
a0096660:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a0096664:  b0 12 e2 90  or  %o3, 0x290, %i0	! 0xa802d290
a0096668:  d8 0e 20 14  ldub  [ %i0 + 0x14 ], %o4
a009666c:  da 0e 20 11  ldub  [ %i0 + 0x11 ], %o5
a0096670:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a0096674:  da 2a a0 56  stb  %o5, [ %o2 + 0x56 ]	! 0xa8025c56
a0096678:  40 00 49 84  call  0xa00a8c88
a009667c:  d8 2e 20 8e  stb  %o4, [ %i0 + 0x8e ]
a0096680:  40 00 47 bc  call  0xa00a8570
a0096684:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0096688:  94 10 20 00  clr  %o2
a009668c:  d2 0e 20 11  ldub  [ %i0 + 0x11 ], %o1
a0096690:  40 00 46 ab  call  0xa00a813c
a0096694:  90 10 20 01  mov  1, %o0
a0096698:  92 10 20 6f  mov  0x6f, %o1
a009669c:  d2 24 23 ec  st  %o1, [ %l0 + 0x3ec ]
a00966a0:  90 10 20 03  mov  3, %o0
a00966a4:  40 00 4b eb  call  0xa00a9650
a00966a8:  92 10 20 00  clr  %o1
a00966ac:  c2 04 23 ec  ld  [ %l0 + 0x3ec ], %g1
a00966b0:  90 00 7f 94  add  %g1, -108, %o0
a00966b4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00966b8:  40 00 4b e6  call  0xa00a9650
a00966bc:  92 10 20 01  mov  1, %o1
a00966c0:  40 00 53 7f  call  0xa00ab4bc
a00966c4:  b0 10 20 07  mov  7, %i0
a00966c8:  90 10 20 02  mov  2, %o0
a00966cc:  40 00 4b 67  call  0xa00a9468
a00966d0:  92 10 20 05  mov  5, %o1
a00966d4:  90 10 20 00  clr  %o0
a00966d8:  40 00 4b 64  call  0xa00a9468
a00966dc:  92 10 20 00  clr  %o1
a00966e0:  90 10 20 01  mov  1, %o0
a00966e4:  40 00 4b 61  call  0xa00a9468
a00966e8:  92 10 20 02  mov  2, %o1
a00966ec:  90 10 20 00  clr  %o0
a00966f0:  40 00 73 79  call  0xa00b34d4
a00966f4:  92 10 20 01  mov  1, %o1
a00966f8:  40 00 73 55  call  0xa00b344c
a00966fc:  81 e8 00 00  restore
a0096700:  01 00 00 00  nop
