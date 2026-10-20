# leon2m FUN_a0092998 0xa0092998-0xa00929e8 (80 bytes)
a0092998:  9d e3 bf 98  save  %sp, -104, %sp
a009299c:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00929a0:  d4 04 23 ec  ld  [ %l0 + 0x3ec ], %o2	! 0xa802afec
a00929a4:  90 02 bf da  add  %o2, -38, %o0
a00929a8:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00929ac:  c0 2a 60 33  clrb  [ %o1 + 0x33 ]	! 0xa802d433
a00929b0:  40 00 59 4e  call  0xa00a8ee8
a00929b4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00929b8:  90 10 20 26  mov  0x26, %o0
a00929bc:  40 00 72 a4  call  0xa00af44c
a00929c0:  92 10 20 00  clr  %o1
a00929c4:  90 10 20 00  clr  %o0
a00929c8:  40 00 59 91  call  0xa00a900c
a00929cc:  92 10 20 00  clr  %o1
a00929d0:  82 10 20 08  mov  8, %g1
a00929d4:  c2 24 23 ec  st  %g1, [ %l0 + 0x3ec ]
a00929d8:  b0 10 20 06  mov  6, %i0
a00929dc:  40 00 85 da  call  0xa00b4144
a00929e0:  93 e8 20 01  restore  %g0, 1, %o1
a00929e4:  01 00 00 00  nop
