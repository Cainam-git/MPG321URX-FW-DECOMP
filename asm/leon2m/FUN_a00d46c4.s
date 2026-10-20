# leon2m FUN_a00d46c4 0xa00d46c4-0xa00d46f4 (48 bytes)
a00d46c4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d46c8:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d46cc:  d2 08 60 16  ldub  [ %g1 + 0x16 ], %o1
a00d46d0:  80 a2 60 64  cmp  %o1, 0x64
a00d46d4:  08 80 00 03  bleu  0xa00d46e0
a00d46d8:  90 10 20 01  mov  1, %o0
a00d46dc:  92 10 20 64  mov  0x64, %o1
a00d46e0:  d2 28 60 16  stb  %o1, [ %g1 + 0x16 ]
a00d46e4:  92 0a 60 ff  and  %o1, 0xff, %o1
a00d46e8:  82 13 c0 00  mov  %o7, %g1
a00d46ec:  40 01 d6 ed  call  0xa014a2a0
a00d46f0:  9e 10 40 00  mov  %g1, %o7
