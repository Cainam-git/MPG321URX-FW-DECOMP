# leon2s FUN_a00c0ce8 0xa00c0ce8-0xa00c0dfc (276 bytes)
a00c0ce8:  9d e3 bf 98  save  %sp, -104, %sp
a00c0cec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0cf0:  90 10 00 18  mov  %i0, %o0
a00c0cf4:  92 10 20 40  mov  0x40, %o1
a00c0cf8:  94 10 20 08  mov  8, %o2
a00c0cfc:  40 3b d6 af  call  0xa0fb67b8
a00c0d00:  96 10 20 01  mov  1, %o3
a00c0d04:  a0 10 20 00  clr  %l0
a00c0d08:  92 04 20 1a  add  %l0, 0x1a, %o1
a00c0d0c:  83 2c 20 10  sll  %l0, 0x10, %g1
a00c0d10:  83 30 60 10  srl  %g1, 0x10, %g1
a00c0d14:  93 2a 60 10  sll  %o1, 0x10, %o1
a00c0d18:  d4 0e 40 01  ldub  [ %i1 + %g1 ], %o2
a00c0d1c:  93 32 60 10  srl  %o1, 0x10, %o1
a00c0d20:  40 3b d6 29  call  0xa0fb65c4
a00c0d24:  90 10 00 18  mov  %i0, %o0
a00c0d28:  9a 04 20 01  add  %l0, 1, %o5
a00c0d2c:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c0d30:  83 30 60 10  srl  %g1, 0x10, %g1
a00c0d34:  80 a0 60 04  cmp  %g1, 4
a00c0d38:  08 bf ff f4  bleu  0xa00c0d08
a00c0d3c:  a0 10 00 0d  mov  %o5, %l0
a00c0d40:  23 33 c0 45  sethi  %hi(0xcf011400), %l1
a00c0d44:  92 10 20 41  mov  0x41, %o1
a00c0d48:  40 3b d6 0d  call  0xa0fb657c
a00c0d4c:  90 10 00 18  mov  %i0, %o0
a00c0d50:  a0 14 60 38  or  %l1, 0x38, %l0
a00c0d54:  c2 04 00 00  ld  [ %l0 ], %g1
a00c0d58:  b2 10 00 08  mov  %o0, %i1
a00c0d5c:  a4 10 00 01  mov  %g1, %l2
a00c0d60:  96 10 20 01  mov  1, %o3
a00c0d64:  90 10 00 18  mov  %i0, %o0
a00c0d68:  92 10 20 41  mov  0x41, %o1
a00c0d6c:  40 3b d6 93  call  0xa0fb67b8
a00c0d70:  94 10 20 80  mov  0x80, %o2
a00c0d74:  c2 04 00 00  ld  [ %l0 ], %g1
a00c0d78:  82 10 60 04  or  %g1, 4, %g1
a00c0d7c:  c2 24 00 00  st  %g1, [ %l0 ]
a00c0d80:  82 10 20 32  mov  0x32, %g1
a00c0d84:  9a 14 63 80  or  %l1, 0x380, %o5
a00c0d88:  c2 23 40 00  st  %g1, [ %o5 ]
a00c0d8c:  82 14 63 84  or  %l1, 0x384, %g1
a00c0d90:  c0 20 40 00  clr  [ %g1 ]
a00c0d94:  82 14 63 88  or  %l1, 0x388, %g1
a00c0d98:  c0 20 40 00  clr  [ %g1 ]
a00c0d9c:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a00c0da0:  82 10 63 cc  or  %g1, 0x3cc, %g1	! 0xcf00bfcc
a00c0da4:  c0 20 40 00  clr  [ %g1 ]
a00c0da8:  a0 10 20 00  clr  %l0
a00c0dac:  96 14 63 8c  or  %l1, 0x38c, %o3
a00c0db0:  98 04 20 01  add  %l0, 1, %o4
a00c0db4:  83 2c 20 10  sll  %l0, 0x10, %g1
a00c0db8:  83 30 60 10  srl  %g1, 0x10, %g1
a00c0dbc:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00c0dc0:  c2 0e 80 01  ldub  [ %i2 + %g1 ], %g1
a00c0dc4:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c0dc8:  c2 22 c0 00  st  %g1, [ %o3 ]
a00c0dcc:  80 a3 61 19  cmp  %o5, 0x119
a00c0dd0:  08 bf ff f8  bleu  0xa00c0db0
a00c0dd4:  a0 10 00 0c  mov  %o4, %l0
a00c0dd8:  90 10 00 18  mov  %i0, %o0
a00c0ddc:  94 0e 60 ff  and  %i1, 0xff, %o2
a00c0de0:  40 3b d5 f9  call  0xa0fb65c4
a00c0de4:  92 10 20 41  mov  0x41, %o1
a00c0de8:  9a 14 60 38  or  %l1, 0x38, %o5
a00c0dec:  82 0c a0 ff  and  %l2, 0xff, %g1
a00c0df0:  c2 23 40 00  st  %g1, [ %o5 ]
a00c0df4:  81 c7 e0 08  ret
a00c0df8:  81 e8 00 00  restore
