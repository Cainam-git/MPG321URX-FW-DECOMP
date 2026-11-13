# leon2m FUN_a0097cc4 0xa0097cc4-0xa0097d3c (120 bytes)
a0097cc4:  9d e3 bf 98  save  %sp, -104, %sp
a0097cc8:  40 01 05 c0  call  0xa00d93c8
a0097ccc:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0097cd0:  de 04 23 ec  ld  [ %l0 + 0x3ec ], %o7	! 0xa802afec
a0097cd4:  94 03 ff 86  add  %o7, -122, %o2
a0097cd8:  40 00 45 b9  call  0xa00a93bc
a0097cdc:  90 0a a0 ff  and  %o2, 0xff, %o0
a0097ce0:  90 10 20 01  mov  1, %o0
a0097ce4:  40 00 45 e1  call  0xa00a9468
a0097ce8:  92 10 20 02  mov  2, %o1
a0097cec:  92 10 20 24  mov  0x24, %o1
a0097cf0:  d2 24 23 ec  st  %o1, [ %l0 + 0x3ec ]
a0097cf4:  90 10 20 01  mov  1, %o0
a0097cf8:  40 00 44 c5  call  0xa00a900c
a0097cfc:  92 10 20 01  mov  1, %o1
a0097d00:  90 10 20 01  mov  1, %o0
a0097d04:  40 00 45 d9  call  0xa00a9468
a0097d08:  92 10 20 02  mov  2, %o1
a0097d0c:  90 10 20 00  clr  %o0
a0097d10:  40 00 6d f1  call  0xa00b34d4
a0097d14:  92 10 20 01  mov  1, %o1
a0097d18:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a0097d1c:  d0 0a e0 8e  ldub  [ %o3 + 0x8e ], %o0	! 0xa802b08e
a0097d20:  9a 12 20 02  or  %o0, 2, %o5
a0097d24:  98 10 20 05  mov  5, %o4
a0097d28:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a0097d2c:  d8 28 60 8f  stb  %o4, [ %g1 + 0x8f ]	! 0xa802b08f
a0097d30:  da 2a e0 8e  stb  %o5, [ %o3 + 0x8e ]
a0097d34:  81 c7 e0 08  ret
a0097d38:  81 e8 00 00  restore
