# leon2m FUN_a00bce2c 0xa00bce2c-0xa00bce7c (80 bytes)
a00bce2c:  9d e3 bf 98  save  %sp, -104, %sp
a00bce30:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00bce34:  d6 03 e3 38  ld  [ %o7 + 0x338 ], %o3	! 0xa802d338
a00bce38:  95 32 e0 07  srl  %o3, 7, %o2
a00bce3c:  90 0a a0 01  and  %o2, 1, %o0
a00bce40:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bce44:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bce48:  82 02 20 30  add  %o0, 0x30, %g1
a00bce4c:  98 10 20 30  mov  0x30, %o4
a00bce50:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bce54:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00bce58:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00bce5c:  7f ff f7 78  call  0xa00bac3c
a00bce60:  90 10 20 20  mov  0x20, %o0
a00bce64:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bce68:  7f ff f6 ba  call  0xa00ba950
a00bce6c:  90 10 00 18  mov  %i0, %o0
a00bce70:  7f ff f7 5d  call  0xa00babe4
a00bce74:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bce78:  01 00 00 00  nop
