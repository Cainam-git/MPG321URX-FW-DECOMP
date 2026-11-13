# leon2m FUN_a00bde20 0xa00bde20-0xa00bde68 (72 bytes)
a00bde20:  9d e3 bf 98  save  %sp, -104, %sp
a00bde24:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bde28:  d0 0a a2 dc  ldub  [ %o2 + 0x2dc ], %o0	! 0xa802d2dc
a00bde2c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bde30:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bde34:  98 02 20 30  add  %o0, 0x30, %o4
a00bde38:  82 10 20 30  mov  0x30, %g1
a00bde3c:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bde40:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bde44:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bde48:  7f ff f3 7d  call  0xa00bac3c
a00bde4c:  90 10 20 3e  mov  0x3e, %o0
a00bde50:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bde54:  7f ff f2 bf  call  0xa00ba950
a00bde58:  90 10 00 18  mov  %i0, %o0
a00bde5c:  7f ff f3 62  call  0xa00babe4
a00bde60:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bde64:  01 00 00 00  nop
