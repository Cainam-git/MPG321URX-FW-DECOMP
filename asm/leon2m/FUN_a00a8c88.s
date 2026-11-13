# leon2m FUN_a00a8c88 0xa00a8c88-0xa00a8ee8 (608 bytes)  [FUN_a00a8ee0 = unreachable ret/restore tail, merged]
a00a8c88:  9d e3 bf 98  save  %sp, -104, %sp
a00a8c8c:  67 ff 95 86  call  0x4008e2a4
a00a8c90:  b4 10 20 05  mov  5, %i2
a00a8c94:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00a8c98:  b2 10 62 90  or  %g1, 0x290, %i1	! 0xa802d290
a00a8c9c:  10 80 00 08  b  0xa00a8cbc
a00a8ca0:  b6 10 20 05  mov  5, %i3
a00a8ca4:  22 80 00 2b  be,a   0xa00a8d50
a00a8ca8:  f6 0e 60 08  ldub  [ %i1 + 8 ], %i3
a00a8cac:  b6 0e a0 ff  and  %i2, 0xff, %i3
a00a8cb0:  80 a6 e0 14  cmp  %i3, 0x14
a00a8cb4:  18 80 00 3b  bgu  0xa00a8da0
a00a8cb8:  96 10 20 02  mov  2, %o3
a00a8cbc:  9a 1e e0 14  xor  %i3, 0x14, %o5
a00a8cc0:  80 a0 00 0d  cmp  %g0, %o5
a00a8cc4:  98 60 20 00  subx  %g0, 0, %o4
a00a8cc8:  96 0b 20 02  and  %o4, 2, %o3
a00a8ccc:  94 02 e0 0c  add  %o3, 0xc, %o2
a00a8cd0:  a0 0a a0 ff  and  %o2, 0xff, %l0
a00a8cd4:  9a 10 20 00  clr  %o5
a00a8cd8:  94 10 00 1b  mov  %i3, %o2
a00a8cdc:  90 10 20 00  clr  %o0
a00a8ce0:  92 10 20 27  mov  0x27, %o1
a00a8ce4:  96 10 00 10  mov  %l0, %o3
a00a8ce8:  40 02 77 8e  call  0xa0146b20
a00a8cec:  98 10 20 00  clr  %o4
a00a8cf0:  92 10 00 1b  mov  %i3, %o1
a00a8cf4:  94 10 00 10  mov  %l0, %o2
a00a8cf8:  96 10 27 96  mov  0x796, %o3
a00a8cfc:  98 10 20 00  clr  %o4
a00a8d00:  40 02 77 60  call  0xa0146a80
a00a8d04:  90 10 20 27  mov  0x27, %o0
a00a8d08:  7f ff a0 b1  call  0xa0090fcc
a00a8d0c:  b4 06 a0 01  inc  %i2
a00a8d10:  93 2a 20 10  sll  %o0, 0x10, %o1
a00a8d14:  91 32 60 10  srl  %o1, 0x10, %o0
a00a8d18:  80 a2 20 33  cmp  %o0, 0x33
a00a8d1c:  18 bf ff e2  bgu  0xa00a8ca4
a00a8d20:  80 a6 e0 0c  cmp  %i3, 0xc
a00a8d24:  7f ff a0 aa  call  0xa0090fcc
a00a8d28:  01 00 00 00  nop
a00a8d2c:  b1 2a 20 10  sll  %o0, 0x10, %i0
a00a8d30:  9f 36 20 10  srl  %i0, 0x10, %o7
a00a8d34:  80 a3 e0 3b  cmp  %o7, 0x3b
a00a8d38:  38 bf ff de  bgu,a   0xa00a8cb0
a00a8d3c:  b6 0e a0 ff  and  %i2, 0xff, %i3
a00a8d40:  80 a6 e0 0c  cmp  %i3, 0xc
a00a8d44:  12 bf ff db  bne  0xa00a8cb0
a00a8d48:  b6 0e a0 ff  and  %i2, 0xff, %i3
a00a8d4c:  f6 0e 60 08  ldub  [ %i1 + 8 ], %i3
a00a8d50:  90 10 20 00  clr  %o0
a00a8d54:  92 10 20 26  mov  0x26, %o1
a00a8d58:  94 10 20 0c  mov  0xc, %o2
a00a8d5c:  96 10 20 01  mov  1, %o3
a00a8d60:  98 10 20 00  clr  %o4
a00a8d64:  80 a6 e0 0d  cmp  %i3, 0xd
a00a8d68:  12 bf ff d1  bne  0xa00a8cac
a00a8d6c:  9a 10 20 00  clr  %o5
a00a8d70:  40 02 77 6c  call  0xa0146b20
a00a8d74:  b6 0e a0 ff  and  %i2, 0xff, %i3
a00a8d78:  90 10 20 26  mov  0x26, %o0
a00a8d7c:  92 10 20 0c  mov  0xc, %o1
a00a8d80:  94 10 20 01  mov  1, %o2
a00a8d84:  96 10 27 96  mov  0x796, %o3
a00a8d88:  40 02 77 3e  call  0xa0146a80
a00a8d8c:  98 10 20 00  clr  %o4
a00a8d90:  80 a6 e0 14  cmp  %i3, 0x14
a00a8d94:  08 bf ff cb  bleu  0xa00a8cc0
a00a8d98:  9a 1e e0 14  xor  %i3, 0x14, %o5
a00a8d9c:  96 10 20 02  mov  2, %o3
a00a8da0:  98 10 20 00  clr  %o4
a00a8da4:  9a 10 20 00  clr  %o5
a00a8da8:  90 10 20 00  clr  %o0
a00a8dac:  92 10 20 2d  mov  0x2d, %o1
a00a8db0:  40 02 77 5c  call  0xa0146b20
a00a8db4:  94 10 20 15  mov  0x15, %o2
a00a8db8:  90 10 20 05  mov  5, %o0
a00a8dbc:  92 10 20 00  clr  %o1
a00a8dc0:  40 02 77 a0  call  0xa0146c40
a00a8dc4:  94 10 20 00  clr  %o2
a00a8dc8:  90 10 20 04  mov  4, %o0
a00a8dcc:  92 10 20 00  clr  %o1
a00a8dd0:  40 02 77 9c  call  0xa0146c40
a00a8dd4:  94 10 20 00  clr  %o2
a00a8dd8:  7f ff a0 7d  call  0xa0090fcc
a00a8ddc:  01 00 00 00  nop
a00a8de0:  b5 2a 20 10  sll  %o0, 0x10, %i2
a00a8de4:  91 36 a0 10  srl  %i2, 0x10, %o0
a00a8de8:  b2 02 3f c1  add  %o0, -63, %i1
a00a8dec:  80 a6 60 01  cmp  %i1, 1
a00a8df0:  08 80 00 34  bleu  0xa00a8ec0
a00a8df4:  82 10 20 01  mov  1, %g1
a00a8df8:  94 1a 20 43  xor  %o0, 0x43, %o2
a00a8dfc:  80 a0 00 0a  cmp  %g0, %o2
a00a8e00:  92 60 3f ff  subx  %g0, -1, %o1
a00a8e04:  a0 02 3f 13  add  %o0, -237, %l0
a00a8e08:  80 a4 20 03  cmp  %l0, 3
a00a8e0c:  82 40 20 00  addx  %g0, 0, %g1
a00a8e10:  80 92 40 01  orcc  %o1, %g1, %g0
a00a8e14:  12 80 00 2b  bne  0xa00a8ec0
a00a8e18:  82 10 20 01  mov  1, %g1
a00a8e1c:  96 02 3f bc  add  %o0, -68, %o3
a00a8e20:  80 a2 e0 01  cmp  %o3, 1
a00a8e24:  08 80 00 28  bleu  0xa00a8ec4
a00a8e28:  80 a0 60 00  cmp  %g1, 0
a00a8e2c:  98 02 3f 19  add  %o0, -231, %o4
a00a8e30:  80 a3 20 05  cmp  %o4, 5
a00a8e34:  08 80 00 24  bleu  0xa00a8ec4
a00a8e38:  80 a0 60 00  cmp  %g1, 0
a00a8e3c:  b6 1a 20 6f  xor  %o0, 0x6f, %i3
a00a8e40:  80 a0 00 1b  cmp  %g0, %i3
a00a8e44:  9e 60 3f ff  subx  %g0, -1, %o7
a00a8e48:  b0 1a 20 cc  xor  %o0, 0xcc, %i0
a00a8e4c:  80 a0 00 18  cmp  %g0, %i0
a00a8e50:  9a 60 3f ff  subx  %g0, -1, %o5
a00a8e54:  80 93 c0 0d  orcc  %o7, %o5, %g0
a00a8e58:  12 80 00 1b  bne  0xa00a8ec4
a00a8e5c:  80 a0 60 00  cmp  %g1, 0
a00a8e60:  b2 02 3f 86  add  %o0, -122, %i1
a00a8e64:  80 a6 60 02  cmp  %i1, 2
a00a8e68:  08 80 00 17  bleu  0xa00a8ec4
a00a8e6c:  80 a0 60 00  cmp  %g1, 0
a00a8e70:  b4 02 3f 33  add  %o0, -205, %i2
a00a8e74:  80 a6 a0 02  cmp  %i2, 2
a00a8e78:  08 80 00 13  bleu  0xa00a8ec4
a00a8e7c:  80 a0 60 00  cmp  %g1, 0
a00a8e80:  82 02 3f 30  add  %o0, -208, %g1
a00a8e84:  80 a0 60 03  cmp  %g1, 3
a00a8e88:  08 80 00 0e  bleu  0xa00a8ec0
a00a8e8c:  82 10 20 01  mov  1, %g1
a00a8e90:  92 02 3f 28  add  %o0, -216, %o1
a00a8e94:  80 a2 60 04  cmp  %o1, 4
a00a8e98:  08 80 00 0b  bleu  0xa00a8ec4
a00a8e9c:  80 a0 60 00  cmp  %g1, 0
a00a8ea0:  a0 02 3f 7e  add  %o0, -130, %l0
a00a8ea4:  80 a4 20 01  cmp  %l0, 1
a00a8ea8:  08 80 00 07  bleu  0xa00a8ec4
a00a8eac:  80 a0 60 00  cmp  %g1, 0
a00a8eb0:  94 02 3f 2c  add  %o0, -212, %o2
a00a8eb4:  80 a2 a0 03  cmp  %o2, 3
a00a8eb8:  38 80 00 02  bgu,a   0xa00a8ec0
a00a8ebc:  82 10 20 00  clr  %g1
a00a8ec0:  80 a0 60 00  cmp  %g1, 0
a00a8ec4:  02 80 00 06  be  0xa00a8edc
a00a8ec8:  b0 10 20 00  clr  %i0
a00a8ecc:  b2 10 20 27  mov  0x27, %i1
a00a8ed0:  b4 10 20 01  mov  1, %i2
a00a8ed4:  40 00 2b ff  call  0xa00b3ed0
a00a8ed8:  97 e8 20 0e  restore  %g0, 0xe, %o3
a00a8edc:  01 00 00 00  nop
a00a8ee0:  81 c7 e0 08  ret
a00a8ee4:  81 e8 00 00  restore
