# leon2m FUN_a00bd988 0xa00bd988-0xa00bd9d8 (80 bytes)
a00bd988:  9d e3 bf 98  save  %sp, -104, %sp
a00bd98c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00bd990:  d6 03 e3 3c  ld  [ %o7 + 0x33c ], %o3	! 0xa802d33c
a00bd994:  95 32 e0 11  srl  %o3, 0x11, %o2
a00bd998:  90 0a a0 01  and  %o2, 1, %o0
a00bd99c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bd9a0:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bd9a4:  82 02 20 30  add  %o0, 0x30, %g1
a00bd9a8:  98 10 20 30  mov  0x30, %o4
a00bd9ac:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bd9b0:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00bd9b4:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00bd9b8:  7f ff f4 a1  call  0xa00bac3c
a00bd9bc:  90 10 20 2d  mov  0x2d, %o0
a00bd9c0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bd9c4:  7f ff f3 e3  call  0xa00ba950
a00bd9c8:  90 10 00 18  mov  %i0, %o0
a00bd9cc:  7f ff f4 86  call  0xa00babe4
a00bd9d0:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd9d4:  01 00 00 00  nop
