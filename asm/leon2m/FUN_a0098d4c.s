# leon2m FUN_a0098d4c 0xa0098d4c-0xa0098d98 (76 bytes)
a0098d4c:  9d e3 bf 98  save  %sp, -104, %sp
a0098d50:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a0098d54:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0098d58:  d4 04 23 ec  ld  [ %l0 + 0x3ec ], %o2	! 0xa802afec
a0098d5c:  da 0a e2 9f  ldub  [ %o3 + 0x29f ], %o5
a0098d60:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a0098d64:  90 02 bf d6  add  %o2, -42, %o0
a0098d68:  da 2a 60 56  stb  %o5, [ %o1 + 0x56 ]
a0098d6c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0098d70:  40 00 40 a7  call  0xa00a900c
a0098d74:  92 10 20 02  mov  2, %o1
a0098d78:  82 10 20 af  mov  0xaf, %g1
a0098d7c:  c2 24 23 ec  st  %g1, [ %l0 + 0x3ec ]
a0098d80:  90 10 20 00  clr  %o0
a0098d84:  40 00 42 33  call  0xa00a9650
a0098d88:  92 10 20 01  mov  1, %o1
a0098d8c:  40 00 79 e9  call  0xa00b7530
a0098d90:  91 e8 20 01  restore  %g0, 1, %o0
a0098d94:  01 00 00 00  nop
