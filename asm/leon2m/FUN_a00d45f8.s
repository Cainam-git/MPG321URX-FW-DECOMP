# leon2m FUN_a00d45f8 0xa00d45f8-0xa00d462c (52 bytes)
a00d45f8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d45fc:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d4600:  d2 08 60 12  ldub  [ %g1 + 0x12 ], %o1
a00d4604:  80 a2 60 64  cmp  %o1, 0x64
a00d4608:  08 80 00 03  bleu  0xa00d4614
a00d460c:  90 10 20 00  clr  %o0
a00d4610:  92 10 20 64  mov  0x64, %o1
a00d4614:  d2 28 60 12  stb  %o1, [ %g1 + 0x12 ]
a00d4618:  92 0a 60 ff  and  %o1, 0xff, %o1
a00d461c:  82 13 c0 00  mov  %o7, %g1
a00d4620:  40 01 d6 bf  call  0xa014a11c
a00d4624:  9e 10 40 00  mov  %g1, %o7
a00d4628:  01 00 00 00  nop
