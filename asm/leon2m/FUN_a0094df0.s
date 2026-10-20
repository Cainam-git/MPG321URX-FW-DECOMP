# leon2m FUN_a0094df0 0xa0094df0-0xa0094e70 (128 bytes)
a0094df0:  9d e3 bf 98  save  %sp, -104, %sp
a0094df4:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0094df8:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1	! 0xa802afec
a0094dfc:  9a 00 60 23  add  %g1, 0x23, %o5
a0094e00:  40 00 51 6f  call  0xa00a93bc
a0094e04:  90 0b 60 ff  and  %o5, 0xff, %o0
a0094e08:  40 00 4f a0  call  0xa00a8c88
a0094e0c:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0094e10:  40 00 4d 8c  call  0xa00a8440
a0094e14:  01 00 00 00  nop
a0094e18:  de 0c 20 56  ldub  [ %l0 + 0x56 ], %o7
a0094e1c:  98 03 e0 01  add  %o7, 1, %o4
a0094e20:  92 0b 20 ff  and  %o4, 0xff, %o1
a0094e24:  94 10 20 01  mov  1, %o2
a0094e28:  40 00 4c c5  call  0xa00a813c
a0094e2c:  90 10 20 01  mov  1, %o0
a0094e30:  d6 0c 20 56  ldub  [ %l0 + 0x56 ], %o3
a0094e34:  94 02 e0 01  add  %o3, 1, %o2
a0094e38:  90 0a a0 ff  and  %o2, 0xff, %o0
a0094e3c:  40 00 52 05  call  0xa00a9650
a0094e40:  92 10 20 00  clr  %o1
a0094e44:  92 10 20 53  mov  0x53, %o1
a0094e48:  d2 24 63 ec  st  %o1, [ %l1 + 0x3ec ]
a0094e4c:  90 10 20 00  clr  %o0
a0094e50:  40 00 52 00  call  0xa00a9650
a0094e54:  92 10 20 01  mov  1, %o1
a0094e58:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0094e5c:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a0094e60:  82 12 20 02  or  %o0, 2, %g1
a0094e64:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a0094e68:  81 c7 e0 08  ret
a0094e6c:  81 e8 00 00  restore
