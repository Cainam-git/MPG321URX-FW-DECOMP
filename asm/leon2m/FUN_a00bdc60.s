# leon2m FUN_a00bdc60 0xa00bdc60-0xa00bdcb0 (80 bytes)
a00bdc60:  9d e3 bf 98  save  %sp, -104, %sp
a00bdc64:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00bdc68:  d6 03 e2 c0  ld  [ %o7 + 0x2c0 ], %o3	! 0xa802d2c0
a00bdc6c:  95 32 e0 04  srl  %o3, 4, %o2
a00bdc70:  90 0a a0 0f  and  %o2, 0xf, %o0
a00bdc74:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bdc78:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bdc7c:  82 02 20 30  add  %o0, 0x30, %g1
a00bdc80:  98 10 20 30  mov  0x30, %o4
a00bdc84:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bdc88:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00bdc8c:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00bdc90:  7f ff f3 eb  call  0xa00bac3c
a00bdc94:  90 10 20 39  mov  0x39, %o0
a00bdc98:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bdc9c:  7f ff f3 2d  call  0xa00ba950
a00bdca0:  90 10 00 18  mov  %i0, %o0
a00bdca4:  7f ff f3 d0  call  0xa00babe4
a00bdca8:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bdcac:  01 00 00 00  nop
