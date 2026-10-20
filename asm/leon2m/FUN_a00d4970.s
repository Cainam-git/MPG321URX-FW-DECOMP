# leon2m FUN_a00d4970 0xa00d4970-0xa00d4994 (36 bytes)
a00d4970:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d4974:  d0 08 62 a0  ldub  [ %g1 + 0x2a0 ], %o0	! 0xa802d2a0
a00d4978:  80 a2 20 64  cmp  %o0, 0x64
a00d497c:  38 80 00 02  bgu,a   0xa00d4984
a00d4980:  90 10 20 64  mov  0x64, %o0
a00d4984:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d4988:  82 13 c0 00  mov  %o7, %g1
a00d498c:  40 01 cc 22  call  0xa0147a14
a00d4990:  9e 10 40 00  mov  %g1, %o7
