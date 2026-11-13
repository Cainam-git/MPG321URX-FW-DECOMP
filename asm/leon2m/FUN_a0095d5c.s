# leon2m FUN_a0095d5c 0xa0095d5c-0xa0095dd8 (124 bytes)
a0095d5c:  9d e3 bf 98  save  %sp, -104, %sp
a0095d60:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0095d64:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a0095d68:  a0 12 22 90  or  %o0, 0x290, %l0
a0095d6c:  da 0b 60 56  ldub  [ %o5 + 0x56 ], %o5
a0095d70:  d8 0c 21 5b  ldub  [ %l0 + 0x15b ], %o4
a0095d74:  82 0b 60 ff  and  %o5, 0xff, %g1
a0095d78:  80 a3 00 01  cmp  %o4, %g1
a0095d7c:  02 80 00 04  be  0xa0095d8c
a0095d80:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0095d84:  40 01 0c e7  call  0xa00d9120
a0095d88:  da 2c 21 5b  stb  %o5, [ %l0 + 0x15b ]
a0095d8c:  d6 04 63 ec  ld  [ %l1 + 0x3ec ], %o3
a0095d90:  94 02 ff b2  add  %o3, -78, %o2
a0095d94:  40 00 4d 8a  call  0xa00a93bc
a0095d98:  90 0a a0 ff  and  %o2, 0xff, %o0
a0095d9c:  d0 0c 21 5b  ldub  [ %l0 + 0x15b ], %o0
a0095da0:  40 00 4e 2c  call  0xa00a9650
a0095da4:  92 10 20 00  clr  %o1
a0095da8:  d2 0c 21 5b  ldub  [ %l0 + 0x15b ], %o1
a0095dac:  90 10 20 01  mov  1, %o0
a0095db0:  40 00 48 e3  call  0xa00a813c
a0095db4:  94 10 20 01  mov  1, %o2
a0095db8:  92 10 20 0f  mov  0xf, %o1
a0095dbc:  d2 24 63 ec  st  %o1, [ %l1 + 0x3ec ]
a0095dc0:  90 10 20 01  mov  1, %o0
a0095dc4:  40 00 4c 92  call  0xa00a900c
a0095dc8:  92 10 20 01  mov  1, %o1
a0095dcc:  40 00 5c 4a  call  0xa00acef4
a0095dd0:  81 e8 00 00  restore
a0095dd4:  01 00 00 00  nop
