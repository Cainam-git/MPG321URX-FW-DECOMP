# leon2m FUN_a00bc3b0 0xa00bc3b0-0xa00bc3f8 (72 bytes)
a00bc3b0:  9d e3 bf 98  save  %sp, -104, %sp
a00bc3b4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bc3b8:  d0 0a 62 a1  ldub  [ %o1 + 0x2a1 ], %o0	! 0xa802d2a1
a00bc3bc:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bc3c0:  9a 02 20 30  add  %o0, 0x30, %o5
a00bc3c4:  82 10 20 30  mov  0x30, %g1
a00bc3c8:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bc3cc:  c2 2e a0 08  stb  %g1, [ %i2 + 8 ]
a00bc3d0:  da 2e a0 09  stb  %o5, [ %i2 + 9 ]
a00bc3d4:  c2 2e a0 07  stb  %g1, [ %i2 + 7 ]
a00bc3d8:  7f ff fa 3b  call  0xa00bacc4
a00bc3dc:  90 10 20 06  mov  6, %o0
a00bc3e0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bc3e4:  7f ff f9 5b  call  0xa00ba950
a00bc3e8:  90 10 00 18  mov  %i0, %o0
a00bc3ec:  40 02 30 ff  call  0xa01487e8
a00bc3f0:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bc3f4:  01 00 00 00  nop
