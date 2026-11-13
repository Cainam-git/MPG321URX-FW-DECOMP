# leon2m FUN_a0098e28 0xa0098e28-0xa0098e6c (68 bytes)
a0098e28:  9d e3 bf 98  save  %sp, -104, %sp
a0098e2c:  40 00 41 64  call  0xa00a93bc
a0098e30:  90 10 20 00  clr  %o0
a0098e34:  94 10 20 2c  mov  0x2c, %o2
a0098e38:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a0098e3c:  d4 22 63 ec  st  %o2, [ %o1 + 0x3ec ]	! 0xa802afec
a0098e40:  90 10 20 02  mov  2, %o0
a0098e44:  40 00 40 72  call  0xa00a900c
a0098e48:  92 10 20 01  mov  1, %o1
a0098e4c:  40 00 7a 0a  call  0xa00b7674
a0098e50:  90 10 20 00  clr  %o0
a0098e54:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0098e58:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a0098e5c:  82 12 20 02  or  %o0, 2, %g1
a0098e60:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a0098e64:  81 c7 e0 08  ret
a0098e68:  81 e8 00 00  restore
