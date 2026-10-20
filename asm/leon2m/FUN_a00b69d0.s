# leon2m FUN_a00b69d0 0xa00b69d0-0xa00b69f0 (32 bytes)
a00b69d0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00b69d4:  d0 00 63 38  ld  [ %g1 + 0x338 ], %o0	! 0xa802d338
a00b69d8:  93 32 20 07  srl  %o0, 7, %o1
a00b69dc:  92 0a 60 01  and  %o1, 1, %o1
a00b69e0:  90 10 20 05  mov  5, %o0
a00b69e4:  82 13 c0 00  mov  %o7, %g1
a00b69e8:  7f ff cd 52  call  0xa00a9f30
a00b69ec:  9e 10 40 00  mov  %g1, %o7
