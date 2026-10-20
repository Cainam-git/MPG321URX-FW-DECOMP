# leon2m FUN_a00a4cac 0xa00a4cac-0xa00a4e08 (348 bytes)
a00a4cac:  9d e3 bf 98  save  %sp, -104, %sp
a00a4cb0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00a4cb4:  98 10 62 90  or  %g1, 0x290, %o4	! 0xa802d290
a00a4cb8:  c2 03 20 a8  ld  [ %o4 + 0xa8 ], %g1
a00a4cbc:  1b 00 00 04  sethi  %hi(0x1000), %o5
a00a4cc0:  80 88 40 0d  btst  %g1, %o5
a00a4cc4:  12 80 00 4c  bne  0xa00a4df4
a00a4cc8:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00a4ccc:  92 10 40 0d  or  %g1, %o5, %o1
a00a4cd0:  a3 32 60 0c  srl  %o1, 0xc, %l1
a00a4cd4:  d2 23 20 a8  st  %o1, [ %o4 + 0xa8 ]
a00a4cd8:  a0 0c 60 01  and  %l1, 1, %l0
a00a4cdc:  90 10 20 05  mov  5, %o0
a00a4ce0:  92 10 20 08  mov  8, %o1
a00a4ce4:  94 10 20 04  mov  4, %o2
a00a4ce8:  96 10 27 92  mov  0x792, %o3
a00a4cec:  98 10 20 00  clr  %o4
a00a4cf0:  40 02 87 64  call  0xa0146a80
a00a4cf4:  a2 0c 20 ff  and  %l0, 0xff, %l1
a00a4cf8:  80 a4 60 00  cmp  %l1, 0
a00a4cfc:  02 80 00 22  be  0xa00a4d84
a00a4d00:  a0 10 20 00  clr  %l0
a00a4d04:  96 0c 20 ff  and  %l0, 0xff, %o3
a00a4d08:  94 02 e0 09  add  %o3, 9, %o2
a00a4d0c:  93 2a a0 10  sll  %o2, 0x10, %o1
a00a4d10:  98 04 20 1e  add  %l0, 0x1e, %o4
a00a4d14:  90 10 20 00  clr  %o0
a00a4d18:  93 32 60 10  srl  %o1, 0x10, %o1
a00a4d1c:  98 0b 20 ff  and  %o4, 0xff, %o4
a00a4d20:  94 10 20 08  mov  8, %o2
a00a4d24:  96 10 20 01  mov  1, %o3
a00a4d28:  40 02 87 7e  call  0xa0146b20
a00a4d2c:  9a 10 20 00  clr  %o5
a00a4d30:  a0 04 20 01  inc  %l0
a00a4d34:  90 0c 20 ff  and  %l0, 0xff, %o0
a00a4d38:  80 a2 20 03  cmp  %o0, 3
a00a4d3c:  08 bf ff f3  bleu  0xa00a4d08
a00a4d40:  96 0c 20 ff  and  %l0, 0xff, %o3
a00a4d44:  80 a4 60 00  cmp  %l1, 0
a00a4d48:  12 80 00 21  bne  0xa00a4dcc
a00a4d4c:  90 10 20 03  mov  3, %o0
a00a4d50:  92 10 20 08  mov  8, %o1
a00a4d54:  94 10 20 05  mov  5, %o2
a00a4d58:  96 10 27 92  mov  0x792, %o3
a00a4d5c:  40 02 87 49  call  0xa0146a80
a00a4d60:  98 10 20 00  clr  %o4
a00a4d64:  90 10 20 0e  mov  0xe, %o0
a00a4d68:  92 10 20 08  mov  8, %o1
a00a4d6c:  94 10 20 05  mov  5, %o2
a00a4d70:  96 10 29 92  mov  0x992, %o3
a00a4d74:  40 02 87 43  call  0xa0146a80
a00a4d78:  98 10 20 00  clr  %o4
a00a4d7c:  10 80 00 1e  b  0xa00a4df4
a00a4d80:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00a4d84:  98 0c 20 ff  and  %l0, 0xff, %o4
a00a4d88:  90 03 20 09  add  %o4, 9, %o0
a00a4d8c:  83 2a 20 10  sll  %o0, 0x10, %g1
a00a4d90:  9e 04 20 22  add  %l0, 0x22, %o7
a00a4d94:  9a 10 20 00  clr  %o5
a00a4d98:  93 30 60 10  srl  %g1, 0x10, %o1
a00a4d9c:  98 0b e0 ff  and  %o7, 0xff, %o4
a00a4da0:  90 10 20 00  clr  %o0
a00a4da4:  94 10 20 08  mov  8, %o2
a00a4da8:  40 02 87 5e  call  0xa0146b20
a00a4dac:  96 10 20 01  mov  1, %o3
a00a4db0:  a0 04 20 01  inc  %l0
a00a4db4:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00a4db8:  80 a3 60 03  cmp  %o5, 3
a00a4dbc:  08 bf ff f3  bleu  0xa00a4d88
a00a4dc0:  98 0c 20 ff  and  %l0, 0xff, %o4
a00a4dc4:  10 bf ff e1  b  0xa00a4d48
a00a4dc8:  80 a4 60 00  cmp  %l1, 0
a00a4dcc:  92 10 20 08  mov  8, %o1
a00a4dd0:  94 10 20 05  mov  5, %o2
a00a4dd4:  96 10 29 92  mov  0x992, %o3
a00a4dd8:  40 02 87 2a  call  0xa0146a80
a00a4ddc:  98 10 20 00  clr  %o4
a00a4de0:  90 10 20 0e  mov  0xe, %o0
a00a4de4:  92 10 20 08  mov  8, %o1
a00a4de8:  94 10 20 05  mov  5, %o2
a00a4dec:  10 bf ff e2  b  0xa00a4d74
a00a4df0:  96 10 27 92  mov  0x792, %o3
a00a4df4:  da 0a a0 8e  ldub  [ %o2 + 0x8e ], %o5
a00a4df8:  96 13 60 02  or  %o5, 2, %o3
a00a4dfc:  d6 2a a0 8e  stb  %o3, [ %o2 + 0x8e ]
a00a4e00:  81 c7 e0 08  ret
a00a4e04:  81 e8 00 00  restore
