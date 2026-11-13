# leon2m FUN_a00d253c 0xa00d253c-0xa00d25f4 (184 bytes)
a00d253c:  9d e3 bf 98  save  %sp, -104, %sp
a00d2540:  da 0e 20 06  ldub  [ %i0 + 6 ], %o5
a00d2544:  80 a3 60 00  cmp  %o5, 0
a00d2548:  02 80 00 09  be  0xa00d256c
a00d254c:  90 10 20 00  clr  %o0
a00d2550:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d2554:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a00d2558:  80 a3 60 01  cmp  %o5, 1
a00d255c:  12 80 00 20  bne  0xa00d25dc
a00d2560:  90 10 20 00  clr  %o0
a00d2564:  10 80 00 0f  b  0xa00d25a0
a00d2568:  92 10 20 02  mov  2, %o1
a00d256c:  9a 10 20 01  mov  1, %o5
a00d2570:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d2574:  40 00 1b 22  call  0xa00d91fc
a00d2578:  da 28 62 af  stb  %o5, [ %g1 + 0x2af ]	! 0xa802d2af
a00d257c:  90 10 20 00  clr  %o0
a00d2580:  40 01 d7 3a  call  0xa0148268
a00d2584:  92 10 20 01  mov  1, %o1
a00d2588:  90 10 20 01  mov  1, %o0
a00d258c:  40 01 d7 37  call  0xa0148268
a00d2590:  92 10 20 01  mov  1, %o1
a00d2594:  40 00 1f 30  call  0xa00da254
a00d2598:  01 00 00 00  nop
a00d259c:  30 80 00 10  b,a   0xa00d25dc
a00d25a0:  40 00 1b 17  call  0xa00d91fc
a00d25a4:  d2 2c 20 1f  stb  %o1, [ %l0 + 0x1f ]
a00d25a8:  90 10 20 00  clr  %o0
a00d25ac:  40 01 d7 2f  call  0xa0148268
a00d25b0:  92 10 20 01  mov  1, %o1
a00d25b4:  92 10 20 01  mov  1, %o1
a00d25b8:  40 01 d7 2c  call  0xa0148268
a00d25bc:  90 10 20 01  mov  1, %o0
a00d25c0:  40 00 1f 25  call  0xa00da254
a00d25c4:  01 00 00 00  nop
a00d25c8:  40 01 c7 f5  call  0xa014459c
a00d25cc:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a00d25d0:  d0 2c 20 20  stb  %o0, [ %l0 + 0x20 ]
a00d25d4:  40 00 0c d9  call  0xa00d5938
a00d25d8:  90 10 20 01  mov  1, %o0
a00d25dc:  40 00 19 90  call  0xa00d8c1c
a00d25e0:  b0 10 20 e0  mov  0xe0, %i0
a00d25e4:  40 00 0d bd  call  0xa00d5cd8
a00d25e8:  01 00 00 00  nop
a00d25ec:  81 c7 e0 08  ret
a00d25f0:  81 e8 00 00  restore
