# leon2m FUN_a00d4780 0xa00d4780-0xa00d47ac (44 bytes)
a00d4780:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d4784:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d4788:  d0 08 60 0f  ldub  [ %g1 + 0xf ], %o0
a00d478c:  80 a2 20 05  cmp  %o0, 5
a00d4790:  38 80 00 02  bgu,a   0xa00d4798
a00d4794:  90 10 20 05  mov  5, %o0
a00d4798:  d0 28 60 0f  stb  %o0, [ %g1 + 0xf ]
a00d479c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d47a0:  82 13 c0 00  mov  %o7, %g1
a00d47a4:  40 01 d6 f9  call  0xa014a388
a00d47a8:  9e 10 40 00  mov  %g1, %o7
