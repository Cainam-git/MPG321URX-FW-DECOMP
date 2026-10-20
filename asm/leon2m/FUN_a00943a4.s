# leon2m FUN_a00943a4 0xa00943a4-0xa00943ec (72 bytes)
a00943a4:  9d e3 bf 98  save  %sp, -104, %sp
a00943a8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00943ac:  9a 12 62 90  or  %o1, 0x290, %o5	! 0xa802d290
a00943b0:  d8 0b 61 3e  ldub  [ %o5 + 0x13e ], %o4
a00943b4:  11 2a 00 97  sethi  %hi(0xa8025c00), %o0
a00943b8:  96 10 21 08  mov  0x108, %o3
a00943bc:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a00943c0:  d8 2a 20 55  stb  %o4, [ %o0 + 0x55 ]
a00943c4:  d6 20 63 ec  st  %o3, [ %g1 + 0x3ec ]
a00943c8:  40 00 83 2e  call  0xa00b5080
a00943cc:  c0 2b 61 a3  clrb  [ %o5 + 0x1a3 ]
a00943d0:  67 ff e7 b5  call  0x4008e2a4
a00943d4:  b0 10 20 00  clr  %i0
a00943d8:  67 ff e7 b3  call  0x4008e2a4
a00943dc:  b2 10 20 01  mov  1, %i1
a00943e0:  40 00 49 ee  call  0xa00a6b98
a00943e4:  95 e8 20 00  restore  %g0, 0, %o2
a00943e8:  01 00 00 00  nop
