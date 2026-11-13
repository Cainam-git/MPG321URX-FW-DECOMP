# leon2m FUN_a00b8ca8 0xa00b8ca8-0xa00b8e7c (468 bytes)
a00b8ca8:  9d e3 bf 98  save  %sp, -104, %sp
a00b8cac:  90 10 20 02  mov  2, %o0
a00b8cb0:  40 02 37 af  call  0xa0146b6c
a00b8cb4:  92 10 20 00  clr  %o1
a00b8cb8:  90 10 20 6f  mov  0x6f, %o0
a00b8cbc:  40 02 37 a5  call  0xa0146b50
a00b8cc0:  92 10 20 00  clr  %o1
a00b8cc4:  7f ff bb f1  call  0xa00a7c88
a00b8cc8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b8ccc:  80 a6 20 00  cmp  %i0, 0
a00b8cd0:  22 80 00 2a  be,a   0xa00b8d78
a00b8cd4:  b2 10 20 00  clr  %i1
a00b8cd8:  b2 10 20 04  mov  4, %i1
a00b8cdc:  b4 10 20 04  mov  4, %i2
a00b8ce0:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00b8ce4:  21 00 06 57  sethi  %hi(0x195c00), %l0
a00b8ce8:  91 2e a0 03  sll  %i2, 3, %o0
a00b8cec:  82 22 00 1a  sub  %o0, %i2, %g1
a00b8cf0:  95 28 60 02  sll  %g1, 2, %o2
a00b8cf4:  9a 14 62 90  or  %l1, 0x290, %o5
a00b8cf8:  98 02 80 1a  add  %o2, %i2, %o4
a00b8cfc:  de 0b 60 08  ldub  [ %o5 + 8 ], %o7
a00b8d00:  96 03 00 0f  add  %o4, %o7, %o3
a00b8d04:  93 2a e0 10  sll  %o3, 0x10, %o1
a00b8d08:  93 32 60 10  srl  %o1, 0x10, %o1
a00b8d0c:  7f ff aa ce  call  0xa00a3844
a00b8d10:  90 14 23 24  or  %l0, 0x324, %o0
a00b8d14:  98 10 00 08  mov  %o0, %o4
a00b8d18:  90 06 80 1a  add  %i2, %i2, %o0
a00b8d1c:  82 02 3f fd  add  %o0, -3, %g1
a00b8d20:  95 28 60 10  sll  %g1, 0x10, %o2
a00b8d24:  95 32 a0 10  srl  %o2, 0x10, %o2
a00b8d28:  90 10 20 00  clr  %o0
a00b8d2c:  92 10 20 06  mov  6, %o1
a00b8d30:  96 10 20 0a  mov  0xa, %o3
a00b8d34:  9a 10 20 00  clr  %o5
a00b8d38:  7f ff a9 1b  call  0xa00a31a4
a00b8d3c:  b2 06 60 01  inc  %i1
a00b8d40:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00b8d44:  80 a6 a0 05  cmp  %i2, 5
a00b8d48:  08 bf ff e9  bleu  0xa00b8cec
a00b8d4c:  91 2e a0 03  sll  %i2, 3, %o0
a00b8d50:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a00b8d54:  d0 0e a0 56  ldub  [ %i2 + 0x56 ], %o0	! 0xa8025c56
a00b8d58:  a1 32 20 02  srl  %o0, 2, %l0
a00b8d5c:  80 a6 00 10  cmp  %i0, %l0
a00b8d60:  22 80 00 28  be,a   0xa00b8e00
a00b8d64:  90 0a 20 03  and  %o0, 3, %o0
a00b8d68:  b0 10 20 04  mov  4, %i0
a00b8d6c:  b2 10 20 00  clr  %i1
a00b8d70:  40 02 37 b4  call  0xa0146c40
a00b8d74:  95 e8 20 00  restore  %g0, 0, %o2
a00b8d78:  b4 10 20 00  clr  %i2
a00b8d7c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00b8d80:  21 00 06 57  sethi  %hi(0x195c00), %l0
a00b8d84:  93 2e a0 03  sll  %i2, 3, %o1
a00b8d88:  90 22 40 1a  sub  %o1, %i2, %o0
a00b8d8c:  83 2a 20 02  sll  %o0, 2, %g1
a00b8d90:  9a 14 62 90  or  %l1, 0x290, %o5
a00b8d94:  9e 00 40 1a  add  %g1, %i2, %o7
a00b8d98:  d4 0b 60 08  ldub  [ %o5 + 8 ], %o2
a00b8d9c:  98 03 c0 0a  add  %o7, %o2, %o4
a00b8da0:  97 2b 20 10  sll  %o4, 0x10, %o3
a00b8da4:  93 32 e0 10  srl  %o3, 0x10, %o1
a00b8da8:  7f ff aa a7  call  0xa00a3844
a00b8dac:  90 14 23 24  or  %l0, 0x324, %o0
a00b8db0:  92 06 80 1a  add  %i2, %i2, %o1
a00b8db4:  98 10 00 08  mov  %o0, %o4
a00b8db8:  94 02 60 05  add  %o1, 5, %o2
a00b8dbc:  90 10 20 00  clr  %o0
a00b8dc0:  92 10 20 06  mov  6, %o1
a00b8dc4:  96 10 20 0a  mov  0xa, %o3
a00b8dc8:  9a 10 20 00  clr  %o5
a00b8dcc:  7f ff a8 f6  call  0xa00a31a4
a00b8dd0:  b2 06 60 01  inc  %i1
a00b8dd4:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00b8dd8:  80 a6 a0 03  cmp  %i2, 3
a00b8ddc:  08 bf ff eb  bleu  0xa00b8d88
a00b8de0:  93 2e a0 03  sll  %i2, 3, %o1
a00b8de4:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a00b8de8:  d0 0e a0 56  ldub  [ %i2 + 0x56 ], %o0	! 0xa8025c56
a00b8dec:  a1 32 20 02  srl  %o0, 2, %l0
a00b8df0:  80 a6 00 10  cmp  %i0, %l0
a00b8df4:  12 bf ff de  bne  0xa00b8d6c
a00b8df8:  b0 10 20 04  mov  4, %i0
a00b8dfc:  90 0a 20 03  and  %o0, 3, %o0
a00b8e00:  7f ff d2 9b  call  0xa00ad86c
a00b8e04:  92 10 20 00  clr  %o1
a00b8e08:  e2 0e a0 56  ldub  [ %i2 + 0x56 ], %l1
a00b8e0c:  9a 0c 60 03  and  %l1, 3, %o5
a00b8e10:  80 a3 60 03  cmp  %o5, 3
a00b8e14:  08 80 00 04  bleu  0xa00b8e24
a00b8e18:  82 10 00 0d  mov  %o5, %g1
a00b8e1c:  b0 03 7f fc  add  %o5, -4, %i0
a00b8e20:  82 0e 20 ff  and  %i0, 0xff, %g1
a00b8e24:  b4 00 40 01  add  %g1, %g1, %i2
a00b8e28:  b2 06 a0 05  add  %i2, 5, %i1
a00b8e2c:  a1 2e 60 10  sll  %i1, 0x10, %l0
a00b8e30:  b4 10 20 00  clr  %i2
a00b8e34:  9a 0e a0 ff  and  %i2, 0xff, %o5
a00b8e38:  94 03 60 04  add  %o5, 4, %o2
a00b8e3c:  9f 2a a0 10  sll  %o2, 0x10, %o7
a00b8e40:  98 06 a0 1c  add  %i2, 0x1c, %o4
a00b8e44:  96 10 20 01  mov  1, %o3
a00b8e48:  93 33 e0 10  srl  %o7, 0x10, %o1
a00b8e4c:  98 0b 20 ff  and  %o4, 0xff, %o4
a00b8e50:  90 10 20 00  clr  %o0
a00b8e54:  95 34 20 10  srl  %l0, 0x10, %o2
a00b8e58:  40 02 37 32  call  0xa0146b20
a00b8e5c:  9a 10 20 00  clr  %o5
a00b8e60:  b4 06 a0 01  inc  %i2
a00b8e64:  96 0e a0 ff  and  %i2, 0xff, %o3
a00b8e68:  80 a2 e0 01  cmp  %o3, 1
a00b8e6c:  08 bf ff f3  bleu  0xa00b8e38
a00b8e70:  9a 0e a0 ff  and  %i2, 0xff, %o5
a00b8e74:  81 c7 e0 08  ret
a00b8e78:  81 e8 00 00  restore
