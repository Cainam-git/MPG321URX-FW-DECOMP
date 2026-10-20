# leon2m FUN_a00be5a0 0xa00be5a0-0xa00be5e8 (72 bytes)
a00be5a0:  9d e3 bf 98  save  %sp, -104, %sp
a00be5a4:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00be5a8:  d0 0a a0 71  ldub  [ %o2 + 0x71 ], %o0	! 0xa802d471
a00be5ac:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be5b0:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be5b4:  98 02 20 30  add  %o0, 0x30, %o4
a00be5b8:  82 10 20 30  mov  0x30, %g1
a00be5bc:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00be5c0:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00be5c4:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00be5c8:  7f ff f1 9d  call  0xa00bac3c
a00be5cc:  90 10 20 75  mov  0x75, %o0
a00be5d0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be5d4:  7f ff f0 df  call  0xa00ba950
a00be5d8:  90 10 00 18  mov  %i0, %o0
a00be5dc:  7f ff f1 82  call  0xa00babe4
a00be5e0:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be5e4:  01 00 00 00  nop
