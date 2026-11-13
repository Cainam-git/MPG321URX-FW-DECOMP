# leon2m FUN_a00bc8c4 0xa00bc8c4-0xa00bc90c (72 bytes)
a00bc8c4:  9d e3 bf 98  save  %sp, -104, %sp
a00bc8c8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bc8cc:  d0 0a a2 98  ldub  [ %o2 + 0x298 ], %o0	! 0xa802d298
a00bc8d0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bc8d4:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bc8d8:  98 02 20 30  add  %o0, 0x30, %o4
a00bc8dc:  82 10 20 30  mov  0x30, %g1
a00bc8e0:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bc8e4:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bc8e8:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bc8ec:  7f ff f8 f6  call  0xa00bacc4
a00bc8f0:  90 10 20 0d  mov  0xd, %o0
a00bc8f4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bc8f8:  7f ff f8 16  call  0xa00ba950
a00bc8fc:  90 10 00 18  mov  %i0, %o0
a00bc900:  7f ff f8 b9  call  0xa00babe4
a00bc904:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bc908:  01 00 00 00  nop
