# leon2m FUN_a0096bd8 0xa0096bd8-0xa0096c80 (168 bytes)
a0096bd8:  9d e3 bf 98  save  %sp, -104, %sp
a0096bdc:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a0096be0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a0096be4:  a0 12 62 90  or  %o1, 0x290, %l0	! 0xa802d290
a0096be8:  d8 0c 60 56  ldub  [ %l1 + 0x56 ], %o4
a0096bec:  da 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %o5
a0096bf0:  82 0b 20 ff  and  %o4, 0xff, %g1
a0096bf4:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a0096bf8:  80 a3 40 01  cmp  %o5, %g1
a0096bfc:  02 80 00 09  be  0xa0096c20
a0096c00:  90 10 20 00  clr  %o0
a0096c04:  40 01 09 7e  call  0xa00d91fc
a0096c08:  01 00 00 00  nop
a0096c0c:  d0 0c 60 56  ldub  [ %l1 + 0x56 ], %o0
a0096c10:  d0 2c 21 a4  stb  %o0, [ %l0 + 0x1a4 ]
a0096c14:  7f ff b1 38  call  0xa00830f4
a0096c18:  90 10 20 00  clr  %o0
a0096c1c:  d8 0c 60 56  ldub  [ %l1 + 0x56 ], %o4
a0096c20:  e2 04 a3 ec  ld  [ %l2 + 0x3ec ], %l1
a0096c24:  9e 04 7f 90  add  %l1, -112, %o7
a0096c28:  90 0b e0 ff  and  %o7, 0xff, %o0
a0096c2c:  40 00 49 e4  call  0xa00a93bc
a0096c30:  d8 2c 21 a4  stb  %o4, [ %l0 + 0x1a4 ]
a0096c34:  d0 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %o0
a0096c38:  40 00 4a 86  call  0xa00a9650
a0096c3c:  92 10 20 00  clr  %o1
a0096c40:  94 10 20 01  mov  1, %o2
a0096c44:  d2 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %o1
a0096c48:  40 00 45 3d  call  0xa00a813c
a0096c4c:  90 10 20 01  mov  1, %o0
a0096c50:  98 10 20 1c  mov  0x1c, %o4
a0096c54:  d8 24 a3 ec  st  %o4, [ %l2 + 0x3ec ]
a0096c58:  90 10 20 04  mov  4, %o0
a0096c5c:  40 00 48 ec  call  0xa00a900c
a0096c60:  92 10 20 01  mov  1, %o1
a0096c64:  40 00 58 a4  call  0xa00acef4
a0096c68:  01 00 00 00  nop
a0096c6c:  96 10 20 03  mov  3, %o3	! 0x3
a0096c70:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a0096c74:  d6 2a a0 8f  stb  %o3, [ %o2 + 0x8f ]	! 0xa802b08f
a0096c78:  81 c7 e0 08  ret
a0096c7c:  81 e8 00 00  restore
