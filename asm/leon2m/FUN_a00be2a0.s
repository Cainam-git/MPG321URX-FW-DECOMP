# leon2m FUN_a00be2a0 0xa00be2a0-0xa00be2f0 (80 bytes)
a00be2a0:  9d e3 bf 98  save  %sp, -104, %sp
a00be2a4:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a00be2a8:  d6 03 e0 7c  ld  [ %o7 + 0x7c ], %o3	! 0xa802d47c
a00be2ac:  95 32 e0 07  srl  %o3, 7, %o2
a00be2b0:  90 0a a0 01  and  %o2, 1, %o0
a00be2b4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be2b8:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be2bc:  82 02 20 30  add  %o0, 0x30, %g1
a00be2c0:  98 10 20 30  mov  0x30, %o4
a00be2c4:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00be2c8:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00be2cc:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00be2d0:  7f ff f2 5b  call  0xa00bac3c
a00be2d4:  90 10 20 6b  mov  0x6b, %o0
a00be2d8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be2dc:  7f ff f1 9d  call  0xa00ba950
a00be2e0:  90 10 00 18  mov  %i0, %o0
a00be2e4:  7f ff f2 40  call  0xa00babe4
a00be2e8:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be2ec:  01 00 00 00  nop
