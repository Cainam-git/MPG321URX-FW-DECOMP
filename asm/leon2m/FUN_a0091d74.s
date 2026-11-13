# leon2m FUN_a0091d74 0xa0091d74-0xa0091de8 (116 bytes)
a0091d74:  9d e3 bf 98  save  %sp, -104, %sp
a0091d78:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0091d7c:  d6 04 23 ec  ld  [ %l0 + 0x3ec ], %o3	! 0xa802afec
a0091d80:  94 02 ff eb  add  %o3, -21, %o2
a0091d84:  40 00 5c 59  call  0xa00a8ee8
a0091d88:  90 0a a0 ff  and  %o2, 0xff, %o0
a0091d8c:  d2 04 23 ec  ld  [ %l0 + 0x3ec ], %o1
a0091d90:  90 02 7f eb  add  %o1, -21, %o0
a0091d94:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091d98:  40 00 61 30  call  0xa00aa258
a0091d9c:  92 10 20 00  clr  %o1
a0091da0:  90 10 20 15  mov  0x15, %o0
a0091da4:  40 00 75 aa  call  0xa00af44c
a0091da8:  92 10 20 00  clr  %o1
a0091dac:  90 10 20 00  clr  %o0
a0091db0:  40 00 5c 97  call  0xa00a900c
a0091db4:  92 10 20 00  clr  %o1
a0091db8:  82 10 20 04  mov  4, %g1
a0091dbc:  c2 24 23 ec  st  %g1, [ %l0 + 0x3ec ]
a0091dc0:  90 10 20 02  mov  2, %o0
a0091dc4:  40 00 88 e0  call  0xa00b4144
a0091dc8:  92 10 20 01  mov  1, %o1
a0091dcc:  90 10 20 01  mov  1, %o0
a0091dd0:  40 00 5d a6  call  0xa00a9468
a0091dd4:  92 10 20 02  mov  2, %o1
a0091dd8:  b0 10 20 00  clr  %i0
a0091ddc:  40 00 85 be  call  0xa00b34d4
a0091de0:  93 e8 20 01  restore  %g0, 1, %o1
a0091de4:  01 00 00 00  nop
