# leon2m FUN_a0099d74 0xa0099d74-0xa0099dd8 (100 bytes)
a0099d74:  9d e3 bf 98  save  %sp, -104, %sp
a0099d78:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0099d7c:  d8 04 23 ec  ld  [ %l0 + 0x3ec ], %o4	! 0xa802afec
a0099d80:  96 03 20 48  add  %o4, 0x48, %o3
a0099d84:  40 00 3d 8e  call  0xa00a93bc
a0099d88:  90 0a e0 ff  and  %o3, 0xff, %o0
a0099d8c:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a0099d90:  d0 02 a0 6c  ld  [ %o2 + 0x6c ], %o0	! 0xa802d46c
a0099d94:  93 32 20 1d  srl  %o0, 0x1d, %o1
a0099d98:  94 10 20 01  mov  1, %o2
a0099d9c:  92 0a 60 01  and  %o1, 1, %o1
a0099da0:  40 00 38 e7  call  0xa00a813c
a0099da4:  90 10 20 01  mov  1, %o0
a0099da8:  82 10 20 34  mov  0x34, %g1
a0099dac:  c2 24 23 ec  st  %g1, [ %l0 + 0x3ec ]
a0099db0:  90 10 20 00  clr  %o0
a0099db4:  40 00 3c 96  call  0xa00a900c
a0099db8:  92 10 20 01  mov  1, %o1
a0099dbc:  90 10 20 01  mov  1, %o0
a0099dc0:  40 00 3d aa  call  0xa00a9468
a0099dc4:  92 10 20 02  mov  2, %o1
a0099dc8:  b0 10 20 00  clr  %i0
a0099dcc:  40 00 65 c2  call  0xa00b34d4
a0099dd0:  93 e8 20 01  restore  %g0, 1, %o1
a0099dd4:  01 00 00 00  nop
