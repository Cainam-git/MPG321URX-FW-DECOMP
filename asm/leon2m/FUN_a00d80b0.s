# leon2m FUN_a00d80b0 0xa00d80b0-0xa00d80d8 (40 bytes)
a00d80b0:  9d e3 bf 98  save  %sp, -104, %sp
a00d80b4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d80b8:  a0 10 62 90  or  %g1, 0x290, %l0	! 0xa802d290
a00d80bc:  90 10 20 0c  mov  0xc, %o0
a00d80c0:  40 01 c8 da  call  0xa014a428
a00d80c4:  d2 0c 20 1d  ldub  [ %l0 + 0x1d ], %o1
a00d80c8:  f2 0c 20 1d  ldub  [ %l0 + 0x1d ], %i1
a00d80cc:  40 01 c8 d7  call  0xa014a428
a00d80d0:  91 e8 20 0d  restore  %g0, 0xd, %o0
a00d80d4:  01 00 00 00  nop
