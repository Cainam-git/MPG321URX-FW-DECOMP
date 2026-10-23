# leon2m FUN_a00d58b0 0xa00d58b0-0xa00d58d8 (40 bytes)
a00d58b0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d58b4:  d0 08 62 aa  ldub  [ %g1 + 0x2aa ], %o0	! 0xa802d2aa
a00d58b8:  80 a2 20 04  cmp  %o0, 4
a00d58bc:  38 80 00 02  bgu,a   0xa00d58c4
a00d58c0:  90 10 20 04  mov  4, %o0
a00d58c4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d58c8:  82 13 c0 00  mov  %o7, %g1
a00d58cc:  7f fe c8 52  call  0xa0087a14
a00d58d0:  9e 10 40 00  mov  %g1, %o7
a00d58d4:  01 00 00 00  nop
