# leon2s FUN_a0092cec 0xa0092cec-0xa0092db8 (204 bytes)
a0092cec:  9d e3 bf 98  save  %sp, -104, %sp
a0092cf0:  a0 10 20 00  clr  %l0
a0092cf4:  94 0c 20 ff  and  %l0, 0xff, %o2
a0092cf8:  94 02 a0 03  add  %o2, 3, %o2
a0092cfc:  82 0c 20 ff  and  %l0, 0xff, %g1
a0092d00:  95 2a a0 10  sll  %o2, 0x10, %o2
a0092d04:  a2 0e 20 ff  and  %i0, 0xff, %l1
a0092d08:  d6 0e 40 01  ldub  [ %i1 + %g1 ], %o3
a0092d0c:  95 32 a0 10  srl  %o2, 0x10, %o2
a0092d10:  90 10 00 11  mov  %l1, %o0
a0092d14:  40 00 54 d0  call  0xa00a8054
a0092d18:  92 10 20 03  mov  3, %o1
a0092d1c:  a0 04 20 01  inc  %l0
a0092d20:  82 0c 20 ff  and  %l0, 0xff, %g1
a0092d24:  80 a0 60 02  cmp  %g1, 2
a0092d28:  08 bf ff f4  bleu  0xa0092cf8
a0092d2c:  94 0c 20 ff  and  %l0, 0xff, %o2
a0092d30:  a0 10 20 00  clr  %l0
a0092d34:  94 0c 20 ff  and  %l0, 0xff, %o2
a0092d38:  82 0c 20 ff  and  %l0, 0xff, %g1
a0092d3c:  94 02 a0 06  add  %o2, 6, %o2
a0092d40:  82 06 40 01  add  %i1, %g1, %g1
a0092d44:  95 2a a0 10  sll  %o2, 0x10, %o2
a0092d48:  d6 08 60 03  ldub  [ %g1 + 3 ], %o3
a0092d4c:  95 32 a0 10  srl  %o2, 0x10, %o2
a0092d50:  90 10 00 11  mov  %l1, %o0
a0092d54:  40 00 54 c0  call  0xa00a8054
a0092d58:  92 10 20 03  mov  3, %o1
a0092d5c:  a0 04 20 01  inc  %l0
a0092d60:  82 0c 20 ff  and  %l0, 0xff, %g1
a0092d64:  80 a0 60 06  cmp  %g1, 6
a0092d68:  08 bf ff f5  bleu  0xa0092d3c
a0092d6c:  94 0c 20 ff  and  %l0, 0xff, %o2
a0092d70:  a0 10 20 00  clr  %l0
a0092d74:  94 0c 20 ff  and  %l0, 0xff, %o2
a0092d78:  82 0c 20 ff  and  %l0, 0xff, %g1
a0092d7c:  94 02 a0 0d  add  %o2, 0xd, %o2
a0092d80:  82 06 40 01  add  %i1, %g1, %g1
a0092d84:  95 2a a0 10  sll  %o2, 0x10, %o2
a0092d88:  d6 08 60 0a  ldub  [ %g1 + 0xa ], %o3
a0092d8c:  95 32 a0 10  srl  %o2, 0x10, %o2
a0092d90:  90 10 00 11  mov  %l1, %o0
a0092d94:  40 00 54 b0  call  0xa00a8054
a0092d98:  92 10 20 03  mov  3, %o1
a0092d9c:  a0 04 20 01  inc  %l0
a0092da0:  82 0c 20 ff  and  %l0, 0xff, %g1
a0092da4:  80 a0 60 03  cmp  %g1, 3
a0092da8:  08 bf ff f5  bleu  0xa0092d7c
a0092dac:  94 0c 20 ff  and  %l0, 0xff, %o2
a0092db0:  81 c7 e0 08  ret
a0092db4:  81 e8 00 00  restore
