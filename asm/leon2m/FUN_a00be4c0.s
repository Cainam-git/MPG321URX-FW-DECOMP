# leon2m FUN_a00be4c0 0xa00be4c0-0xa00be510 (80 bytes)
a00be4c0:  9d e3 bf 98  save  %sp, -104, %sp
a00be4c4:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a00be4c8:  d6 03 e0 6c  ld  [ %o7 + 0x6c ], %o3	! 0xa802d46c
a00be4cc:  95 32 e0 0f  srl  %o3, 0xf, %o2
a00be4d0:  90 0a a0 01  and  %o2, 1, %o0
a00be4d4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be4d8:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be4dc:  82 02 20 30  add  %o0, 0x30, %g1
a00be4e0:  98 10 20 30  mov  0x30, %o4
a00be4e4:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00be4e8:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00be4ec:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00be4f0:  7f ff f1 d3  call  0xa00bac3c
a00be4f4:  90 10 20 73  mov  0x73, %o0
a00be4f8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be4fc:  7f ff f1 15  call  0xa00ba950
a00be500:  90 10 00 18  mov  %i0, %o0
a00be504:  7f ff f1 b8  call  0xa00babe4
a00be508:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be50c:  01 00 00 00  nop
