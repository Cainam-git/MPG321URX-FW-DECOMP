# leon2m FUN_a00d462c 0xa00d462c-0xa00d4660 (52 bytes)
a00d462c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d4630:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d4634:  d2 08 60 13  ldub  [ %g1 + 0x13 ], %o1
a00d4638:  80 a2 60 64  cmp  %o1, 0x64
a00d463c:  08 80 00 03  bleu  0xa00d4648
a00d4640:  90 10 20 01  mov  1, %o0
a00d4644:  92 10 20 64  mov  0x64, %o1
a00d4648:  d2 28 60 13  stb  %o1, [ %g1 + 0x13 ]
a00d464c:  92 0a 60 ff  and  %o1, 0xff, %o1
a00d4650:  82 13 c0 00  mov  %o7, %g1
a00d4654:  40 01 d6 b2  call  0xa014a11c
a00d4658:  9e 10 40 00  mov  %g1, %o7
a00d465c:  01 00 00 00  nop
