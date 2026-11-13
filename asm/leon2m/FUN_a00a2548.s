# leon2m FUN_a00a2548 0xa00a2548-0xa00a2600 (184 bytes)
a00a2548:  9d e3 bf 98  save  %sp, -104, %sp
a00a254c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00a2550:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a00a2554:  a0 10 62 90  or  %g1, 0x290, %l0
a00a2558:  de 0b 60 55  ldub  [ %o5 + 0x55 ], %o7
a00a255c:  98 10 20 02  mov  2, %o4
a00a2560:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a00a2564:  de 2c 21 eb  stb  %o7, [ %l0 + 0x1eb ]
a00a2568:  d8 2c 60 56  stb  %o4, [ %l1 + 0x56 ]
a00a256c:  40 00 1b 94  call  0xa00a93bc
a00a2570:  90 10 20 00  clr  %o0
a00a2574:  40 00 19 c5  call  0xa00a8c88
a00a2578:  01 00 00 00  nop
a00a257c:  96 10 20 c1  mov  0xc1, %o3	! 0xc1
a00a2580:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a00a2584:  d6 22 a3 ec  st  %o3, [ %o2 + 0x3ec ]	! 0xa802afec
a00a2588:  40 00 28 64  call  0xa00ac718
a00a258c:  90 10 20 39  mov  0x39, %o0
a00a2590:  d0 0c 60 56  ldub  [ %l1 + 0x56 ], %o0
a00a2594:  40 00 1c 2f  call  0xa00a9650
a00a2598:  92 10 20 01  mov  1, %o1
a00a259c:  92 10 3f ff  mov  -1, %o1
a00a25a0:  40 00 23 c7  call  0xa00ab4bc
a00a25a4:  d2 2c 21 89  stb  %o1, [ %l0 + 0x189 ]
a00a25a8:  90 10 20 01  mov  1, %o0
a00a25ac:  40 00 1b af  call  0xa00a9468
a00a25b0:  92 10 20 02  mov  2, %o1
a00a25b4:  90 10 20 02  mov  2, %o0
a00a25b8:  40 00 1b ac  call  0xa00a9468
a00a25bc:  92 10 20 05  mov  5, %o1
a00a25c0:  92 10 20 00  clr  %o1
a00a25c4:  40 00 1b a9  call  0xa00a9468
a00a25c8:  90 10 20 00  clr  %o0
a00a25cc:  40 00 43 a0  call  0xa00b344c
a00a25d0:  90 10 20 07  mov  7, %o0
a00a25d4:  90 10 20 00  clr  %o0
a00a25d8:  40 00 43 bf  call  0xa00b34d4
a00a25dc:  92 10 20 01  mov  1, %o1
a00a25e0:  40 00 e1 7a  call  0xa00dabc8
a00a25e4:  01 00 00 00  nop
a00a25e8:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00a25ec:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a00a25f0:  82 12 20 02  or  %o0, 2, %g1
a00a25f4:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a00a25f8:  81 c7 e0 08  ret
a00a25fc:  81 e8 00 00  restore
