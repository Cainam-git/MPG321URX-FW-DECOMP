# leon2m FUN_a00bcaf0 0xa00bcaf0-0xa00bcb38 (72 bytes)
a00bcaf0:  9d e3 bf 98  save  %sp, -104, %sp
a00bcaf4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bcaf8:  d0 0a a2 a9  ldub  [ %o2 + 0x2a9 ], %o0	! 0xa802d2a9
a00bcafc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bcb00:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bcb04:  98 02 20 30  add  %o0, 0x30, %o4
a00bcb08:  82 10 20 30  mov  0x30, %g1
a00bcb0c:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bcb10:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bcb14:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bcb18:  7f ff f8 49  call  0xa00bac3c
a00bcb1c:  90 10 20 15  mov  0x15, %o0
a00bcb20:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bcb24:  7f ff f7 8b  call  0xa00ba950
a00bcb28:  90 10 00 18  mov  %i0, %o0
a00bcb2c:  7f ff f8 2e  call  0xa00babe4
a00bcb30:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bcb34:  01 00 00 00  nop
