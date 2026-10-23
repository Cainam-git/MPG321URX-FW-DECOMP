# leon2m FUN_a00d4690 0xa00d4690-0xa00d46c4 (52 bytes)
a00d4690:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d4694:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d4698:  d2 08 60 15  ldub  [ %g1 + 0x15 ], %o1
a00d469c:  80 a2 60 64  cmp  %o1, 0x64
a00d46a0:  08 80 00 03  bleu  0xa00d46ac
a00d46a4:  90 10 20 00  clr  %o0
a00d46a8:  92 10 20 64  mov  0x64, %o1
a00d46ac:  d2 28 60 15  stb  %o1, [ %g1 + 0x15 ]
a00d46b0:  92 0a 60 ff  and  %o1, 0xff, %o1
a00d46b4:  82 13 c0 00  mov  %o7, %g1
a00d46b8:  40 01 d6 fa  call  0xa014a2a0
a00d46bc:  9e 10 40 00  mov  %g1, %o7
a00d46c0:  01 00 00 00  nop
