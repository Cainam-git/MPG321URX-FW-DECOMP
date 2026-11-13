# leon2m FUN_a0094ed8 0xa0094ed8-0xa0094f58 (128 bytes)
a0094ed8:  9d e3 bf 98  save  %sp, -104, %sp
a0094edc:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0094ee0:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1	! 0xa802afec
a0094ee4:  9a 00 60 1e  add  %g1, 0x1e, %o5
a0094ee8:  40 00 51 35  call  0xa00a93bc
a0094eec:  90 0b 60 ff  and  %o5, 0xff, %o0
a0094ef0:  40 00 4f 66  call  0xa00a8c88
a0094ef4:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0094ef8:  40 00 5d 24  call  0xa00ac388
a0094efc:  90 10 20 01  mov  1, %o0
a0094f00:  de 0c 20 56  ldub  [ %l0 + 0x56 ], %o7
a0094f04:  98 03 e0 01  add  %o7, 1, %o4
a0094f08:  92 0b 20 ff  and  %o4, 0xff, %o1
a0094f0c:  94 10 20 01  mov  1, %o2
a0094f10:  40 00 4c 8b  call  0xa00a813c
a0094f14:  90 10 20 01  mov  1, %o0
a0094f18:  d6 0c 20 56  ldub  [ %l0 + 0x56 ], %o3
a0094f1c:  94 02 e0 01  add  %o3, 1, %o2
a0094f20:  90 0a a0 ff  and  %o2, 0xff, %o0
a0094f24:  40 00 51 cb  call  0xa00a9650
a0094f28:  92 10 20 00  clr  %o1
a0094f2c:  92 10 20 56  mov  0x56, %o1
a0094f30:  d2 24 63 ec  st  %o1, [ %l1 + 0x3ec ]
a0094f34:  90 10 20 00  clr  %o0
a0094f38:  40 00 51 c6  call  0xa00a9650
a0094f3c:  92 10 20 01  mov  1, %o1
a0094f40:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0094f44:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a0094f48:  82 12 20 02  or  %o0, 2, %g1
a0094f4c:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a0094f50:  81 c7 e0 08  ret
a0094f54:  81 e8 00 00  restore
