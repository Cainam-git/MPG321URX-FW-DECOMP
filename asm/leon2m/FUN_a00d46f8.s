# leon2m FUN_a00d46f8 0xa00d46f8-0xa00d4728 (48 bytes)
a00d46f8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d46fc:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d4700:  d2 08 60 17  ldub  [ %g1 + 0x17 ], %o1
a00d4704:  80 a2 60 64  cmp  %o1, 0x64
a00d4708:  08 80 00 03  bleu  0xa00d4714
a00d470c:  90 10 20 02  mov  2, %o0
a00d4710:  92 10 20 64  mov  0x64, %o1
a00d4714:  d2 28 60 17  stb  %o1, [ %g1 + 0x17 ]
a00d4718:  92 0a 60 ff  and  %o1, 0xff, %o1
a00d471c:  82 13 c0 00  mov  %o7, %g1
a00d4720:  40 01 d6 e0  call  0xa014a2a0
a00d4724:  9e 10 40 00  mov  %g1, %o7
