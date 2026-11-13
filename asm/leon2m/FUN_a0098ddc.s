# leon2m FUN_a0098ddc 0xa0098ddc-0xa0098e28 (76 bytes)
a0098ddc:  9d e3 bf 98  save  %sp, -104, %sp
a0098de0:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a0098de4:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0098de8:  d4 04 23 ec  ld  [ %l0 + 0x3ec ], %o2	! 0xa802afec
a0098dec:  da 0a e2 9c  ldub  [ %o3 + 0x29c ], %o5
a0098df0:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a0098df4:  90 02 bf d6  add  %o2, -42, %o0
a0098df8:  da 2a 60 56  stb  %o5, [ %o1 + 0x56 ]
a0098dfc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0098e00:  40 00 40 83  call  0xa00a900c
a0098e04:  92 10 20 02  mov  2, %o1
a0098e08:  82 10 20 b0  mov  0xb0, %g1
a0098e0c:  c2 24 23 ec  st  %g1, [ %l0 + 0x3ec ]
a0098e10:  90 10 20 00  clr  %o0
a0098e14:  40 00 42 0f  call  0xa00a9650
a0098e18:  92 10 20 01  mov  1, %o1
a0098e1c:  40 00 7a 16  call  0xa00b7674
a0098e20:  91 e8 20 01  restore  %g0, 1, %o0
a0098e24:  01 00 00 00  nop
