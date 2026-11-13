# leon2m FUN_a00be558 0xa00be558-0xa00be5a0 (72 bytes)
a00be558:  9d e3 bf 98  save  %sp, -104, %sp
a00be55c:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00be560:  d0 0a a0 6f  ldub  [ %o2 + 0x6f ], %o0	! 0xa802d46f
a00be564:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be568:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be56c:  98 02 20 30  add  %o0, 0x30, %o4
a00be570:  82 10 20 30  mov  0x30, %g1
a00be574:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00be578:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00be57c:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00be580:  7f ff f1 af  call  0xa00bac3c
a00be584:  90 10 20 76  mov  0x76, %o0
a00be588:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be58c:  7f ff f0 f1  call  0xa00ba950
a00be590:  90 10 00 18  mov  %i0, %o0
a00be594:  7f ff f1 94  call  0xa00babe4
a00be598:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be59c:  01 00 00 00  nop
