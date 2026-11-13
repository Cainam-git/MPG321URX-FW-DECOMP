# leon2m FUN_a00be38c 0xa00be38c-0xa00be3dc (80 bytes)
a00be38c:  9d e3 bf 98  save  %sp, -104, %sp
a00be390:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a00be394:  d6 03 e0 84  ld  [ %o7 + 0x84 ], %o3	! 0xa802d484
a00be398:  95 32 e0 1e  srl  %o3, 0x1e, %o2
a00be39c:  90 0a a0 01  and  %o2, 1, %o0
a00be3a0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be3a4:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be3a8:  82 02 20 30  add  %o0, 0x30, %g1
a00be3ac:  98 10 20 30  mov  0x30, %o4
a00be3b0:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00be3b4:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00be3b8:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00be3bc:  7f ff f2 20  call  0xa00bac3c
a00be3c0:  90 10 20 6f  mov  0x6f, %o0
a00be3c4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be3c8:  7f ff f1 62  call  0xa00ba950
a00be3cc:  90 10 00 18  mov  %i0, %o0
a00be3d0:  7f ff f2 05  call  0xa00babe4
a00be3d4:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be3d8:  01 00 00 00  nop
