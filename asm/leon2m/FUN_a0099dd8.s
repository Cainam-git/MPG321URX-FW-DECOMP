# leon2m FUN_a0099dd8 0xa0099dd8-0xa0099e3c (100 bytes)
a0099dd8:  9d e3 bf 98  save  %sp, -104, %sp
a0099ddc:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0099de0:  d8 04 23 ec  ld  [ %l0 + 0x3ec ], %o4	! 0xa802afec
a0099de4:  96 03 20 45  add  %o4, 0x45, %o3
a0099de8:  40 00 3d 75  call  0xa00a93bc
a0099dec:  90 0a e0 ff  and  %o3, 0xff, %o0
a0099df0:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a0099df4:  d0 02 a0 6c  ld  [ %o2 + 0x6c ], %o0	! 0xa802d46c
a0099df8:  93 32 20 0f  srl  %o0, 0xf, %o1
a0099dfc:  94 10 20 01  mov  1, %o2
a0099e00:  92 0a 60 01  and  %o1, 1, %o1
a0099e04:  40 00 38 ce  call  0xa00a813c
a0099e08:  90 10 20 01  mov  1, %o0
a0099e0c:  82 10 20 37  mov  0x37, %g1
a0099e10:  c2 24 23 ec  st  %g1, [ %l0 + 0x3ec ]
a0099e14:  90 10 20 03  mov  3, %o0
a0099e18:  40 00 3c 7d  call  0xa00a900c
a0099e1c:  92 10 20 01  mov  1, %o1
a0099e20:  90 10 20 01  mov  1, %o0
a0099e24:  40 00 3d 91  call  0xa00a9468
a0099e28:  92 10 20 02  mov  2, %o1
a0099e2c:  b0 10 20 00  clr  %i0
a0099e30:  40 00 65 a9  call  0xa00b34d4
a0099e34:  93 e8 20 01  restore  %g0, 1, %o1
a0099e38:  01 00 00 00  nop
