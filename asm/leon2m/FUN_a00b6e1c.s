# leon2m FUN_a00b6e1c 0xa00b6e1c-0xa00b6ec0 (164 bytes)
a00b6e1c:  9d e3 bf 98  save  %sp, -104, %sp
a00b6e20:  90 10 21 11  mov  0x111, %o0
a00b6e24:  40 02 3f 4b  call  0xa0146b50
a00b6e28:  92 10 20 00  clr  %o1
a00b6e2c:  90 10 20 00  clr  %o0
a00b6e30:  40 02 3f 4f  call  0xa0146b6c
a00b6e34:  92 10 20 00  clr  %o1
a00b6e38:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00b6e3c:  a0 10 62 90  or  %g1, 0x290, %l0	! 0xa802d290
a00b6e40:  b2 10 20 00  clr  %i1
a00b6e44:  b4 10 20 00  clr  %i2
a00b6e48:  31 00 06 52  sethi  %hi(0x194800), %i0
a00b6e4c:  83 2e a0 03  sll  %i2, 3, %g1
a00b6e50:  9e 20 40 1a  sub  %g1, %i2, %o7
a00b6e54:  9b 2b e0 02  sll  %o7, 2, %o5
a00b6e58:  96 03 40 1a  add  %o5, %i2, %o3
a00b6e5c:  d8 0c 20 08  ldub  [ %l0 + 8 ], %o4
a00b6e60:  90 02 c0 0c  add  %o3, %o4, %o0
a00b6e64:  93 2a 20 10  sll  %o0, 0x10, %o1
a00b6e68:  93 32 60 10  srl  %o1, 0x10, %o1
a00b6e6c:  7f ff b2 76  call  0xa00a3844
a00b6e70:  90 16 23 34  or  %i0, 0x334, %o0
a00b6e74:  98 10 00 08  mov  %o0, %o4
a00b6e78:  94 06 80 1a  add  %i2, %i2, %o2
a00b6e7c:  94 02 a0 06  add  %o2, 6, %o2
a00b6e80:  90 10 20 00  clr  %o0
a00b6e84:  92 10 20 2a  mov  0x2a, %o1
a00b6e88:  96 10 20 01  mov  1, %o3
a00b6e8c:  9a 10 20 00  clr  %o5
a00b6e90:  7f ff b0 c5  call  0xa00a31a4
a00b6e94:  b2 06 60 01  inc  %i1
a00b6e98:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00b6e9c:  80 a6 a0 04  cmp  %i2, 4
a00b6ea0:  08 bf ff ec  bleu  0xa00b6e50
a00b6ea4:  83 2e a0 03  sll  %i2, 3, %g1
a00b6ea8:  f2 14 20 34  lduh  [ %l0 + 0x34 ], %i1
a00b6eac:  b2 0e 60 0f  and  %i1, 0xf, %i1
a00b6eb0:  b0 10 20 01  mov  1, %i0
a00b6eb4:  7f ff c4 a2  call  0xa00a813c
a00b6eb8:  95 e8 20 01  restore  %g0, 1, %o2
a00b6ebc:  01 00 00 00  nop
