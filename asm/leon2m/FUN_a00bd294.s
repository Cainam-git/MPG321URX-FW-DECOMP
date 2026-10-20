# leon2m FUN_a00bd294 0xa00bd294-0xa00bd2e0 (76 bytes)
a00bd294:  9d e3 bf 98  save  %sp, -104, %sp
a00bd298:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00bd29c:  d4 12 e2 c4  lduh  [ %o3 + 0x2c4 ], %o2	! 0xa802d2c4
a00bd2a0:  90 0a a0 0f  and  %o2, 0xf, %o0
a00bd2a4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bd2a8:  82 12 60 78  or  %o1, 0x78, %g1	! 0xa802d078
a00bd2ac:  9a 02 20 30  add  %o0, 0x30, %o5
a00bd2b0:  98 10 20 30  mov  0x30, %o4
a00bd2b4:  da 28 60 09  stb  %o5, [ %g1 + 9 ]
a00bd2b8:  d8 28 60 08  stb  %o4, [ %g1 + 8 ]
a00bd2bc:  d8 28 60 07  stb  %o4, [ %g1 + 7 ]
a00bd2c0:  7f ff f6 5f  call  0xa00bac3c
a00bd2c4:  90 10 20 25  mov  0x25, %o0
a00bd2c8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bd2cc:  7f ff f5 a1  call  0xa00ba950
a00bd2d0:  90 10 00 18  mov  %i0, %o0
a00bd2d4:  7f ff f6 44  call  0xa00babe4
a00bd2d8:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd2dc:  01 00 00 00  nop
