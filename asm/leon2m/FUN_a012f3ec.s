# leon2m FUN_a012f3ec 0xa012f3ec-0xa012f43c (80 bytes)
a012f3ec:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a012f3f0:  c2 08 61 a7  ldub  [ %g1 + 0x1a7 ], %g1	! 0xa802e1a7
a012f3f4:  80 a0 60 07  cmp  %g1, 7
a012f3f8:  18 80 00 0f  bgu  0xa012f434
a012f3fc:  90 10 20 01  mov  1, %o0
a012f400:  19 00 03 3c  sethi  %hi(0xcf000), %o4
a012f404:  91 28 60 02  sll  %g1, 2, %o0
a012f408:  9a 13 21 4c  or  %o4, 0x14c, %o5
a012f40c:  d8 03 40 08  ld  [ %o5 + %o0 ], %o4
a012f410:  81 c3 00 00  jmp  %o4
a012f414:  01 00 00 00  nop
a012f418:  10 80 00 07  b  0xa012f434
a012f41c:  90 10 20 03  mov  3, %o0	! 0x3
a012f420:  10 80 00 05  b  0xa012f434
a012f424:  90 10 20 04  mov  4, %o0
a012f428:  10 80 00 03  b  0xa012f434
a012f42c:  90 10 20 01  mov  1, %o0
a012f430:  90 10 20 02  mov  2, %o0
a012f434:  81 c3 e0 08  retl
a012f438:  90 0a 20 07  and  %o0, 7, %o0
