# leon2m FUN_a00be0a0 0xa00be0a0-0xa00be0f0 (80 bytes)
a00be0a0:  9d e3 bf 98  save  %sp, -104, %sp
a00be0a4:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00be0a8:  d6 03 e3 38  ld  [ %o7 + 0x338 ], %o3	! 0xa802d338
a00be0ac:  95 32 e0 0f  srl  %o3, 0xf, %o2
a00be0b0:  90 0a a0 01  and  %o2, 1, %o0
a00be0b4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be0b8:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be0bc:  82 02 20 30  add  %o0, 0x30, %g1
a00be0c0:  98 10 20 30  mov  0x30, %o4
a00be0c4:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00be0c8:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00be0cc:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00be0d0:  7f ff f2 db  call  0xa00bac3c
a00be0d4:  90 10 20 45  mov  0x45, %o0
a00be0d8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be0dc:  7f ff f2 1d  call  0xa00ba950
a00be0e0:  90 10 00 18  mov  %i0, %o0
a00be0e4:  7f ff f2 c0  call  0xa00babe4
a00be0e8:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be0ec:  01 00 00 00  nop
