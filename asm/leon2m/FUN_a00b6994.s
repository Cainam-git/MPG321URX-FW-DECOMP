# leon2m FUN_a00b6994 0xa00b6994-0xa00b69d0 (60 bytes)
a00b6994:  9d e3 bf 98  save  %sp, -104, %sp
a00b6998:  40 00 84 ec  call  0xa00d7d48
a00b699c:  b0 10 20 02  mov  2, %i0
a00b69a0:  80 a2 20 00  cmp  %o0, 0
a00b69a4:  02 80 00 04  be  0xa00b69b4
a00b69a8:  b2 10 20 00  clr  %i1
a00b69ac:  7f ff cd 61  call  0xa00a9f30
a00b69b0:  81 e8 00 00  restore
a00b69b4:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00b69b8:  d0 00 60 04  ld  [ %g1 + 4 ], %o0	! 0xa802d404
a00b69bc:  b3 32 20 0f  srl  %o0, 0xf, %i1
a00b69c0:  b2 0e 60 01  and  %i1, 1, %i1
a00b69c4:  7f ff cd 5b  call  0xa00a9f30
a00b69c8:  91 e8 20 02  restore  %g0, 2, %o0
a00b69cc:  01 00 00 00  nop
