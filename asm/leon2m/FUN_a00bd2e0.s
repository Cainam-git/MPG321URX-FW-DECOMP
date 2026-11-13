# leon2m FUN_a00bd2e0 0xa00bd2e0-0xa00bd328 (72 bytes)
a00bd2e0:  9d e3 bf 98  save  %sp, -104, %sp
a00bd2e4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bd2e8:  d0 0a a2 9f  ldub  [ %o2 + 0x29f ], %o0	! 0xa802d29f
a00bd2ec:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bd2f0:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bd2f4:  98 02 20 30  add  %o0, 0x30, %o4
a00bd2f8:  82 10 20 30  mov  0x30, %g1
a00bd2fc:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bd300:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bd304:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bd308:  7f ff f6 4d  call  0xa00bac3c
a00bd30c:  90 10 20 26  mov  0x26, %o0
a00bd310:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bd314:  7f ff f5 8f  call  0xa00ba950
a00bd318:  90 10 00 18  mov  %i0, %o0
a00bd31c:  7f ff f6 32  call  0xa00babe4
a00bd320:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd324:  01 00 00 00  nop
