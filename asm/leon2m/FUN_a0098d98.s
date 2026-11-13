# leon2m FUN_a0098d98 0xa0098d98-0xa0098ddc (68 bytes)
a0098d98:  9d e3 bf 98  save  %sp, -104, %sp
a0098d9c:  40 00 41 88  call  0xa00a93bc
a0098da0:  90 10 20 00  clr  %o0
a0098da4:  94 10 20 2b  mov  0x2b, %o2
a0098da8:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a0098dac:  d4 22 63 ec  st  %o2, [ %o1 + 0x3ec ]	! 0xa802afec
a0098db0:  90 10 20 01  mov  1, %o0
a0098db4:  40 00 40 96  call  0xa00a900c
a0098db8:  92 10 20 01  mov  1, %o1
a0098dbc:  40 00 79 dd  call  0xa00b7530
a0098dc0:  90 10 20 00  clr  %o0
a0098dc4:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0098dc8:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a0098dcc:  82 12 20 02  or  %o0, 2, %g1
a0098dd0:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a0098dd4:  81 c7 e0 08  ret
a0098dd8:  81 e8 00 00  restore
