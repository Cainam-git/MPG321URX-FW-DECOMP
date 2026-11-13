# leon2m FUN_a00bde68 0xa00bde68-0xa00bdeb8 (80 bytes)
a00bde68:  9d e3 bf 98  save  %sp, -104, %sp
a00bde6c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00bde70:  d6 03 e2 90  ld  [ %o7 + 0x290 ], %o3	! 0xa802d290
a00bde74:  95 32 e0 09  srl  %o3, 9, %o2
a00bde78:  90 0a a0 01  and  %o2, 1, %o0
a00bde7c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bde80:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bde84:  82 02 20 30  add  %o0, 0x30, %g1
a00bde88:  98 10 20 30  mov  0x30, %o4
a00bde8c:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bde90:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00bde94:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00bde98:  7f ff f3 69  call  0xa00bac3c
a00bde9c:  90 10 20 56  mov  0x56, %o0
a00bdea0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bdea4:  7f ff f2 ab  call  0xa00ba950
a00bdea8:  90 10 00 18  mov  %i0, %o0
a00bdeac:  7f ff f3 4e  call  0xa00babe4
a00bdeb0:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bdeb4:  01 00 00 00  nop
