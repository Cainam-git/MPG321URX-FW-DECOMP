# leon2m FUN_a00a0f6c 0xa00a0f6c-0xa00a0ff0 (132 bytes)
a00a0f6c:  9d e3 bf 98  save  %sp, -104, %sp
a00a0f70:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a00a0f74:  98 14 23 f4  or  %l0, 0x3f4, %o4	! 0xa802cff4
a00a0f78:  c2 0b 20 34  ldub  [ %o4 + 0x34 ], %g1
a00a0f7c:  80 a0 60 02  cmp  %g1, 2
a00a0f80:  08 80 00 1a  bleu  0xa00a0fe8
a00a0f84:  01 00 00 00  nop
a00a0f88:  d0 13 20 38  lduh  [ %o4 + 0x38 ], %o0
a00a0f8c:  80 a2 28 6f  cmp  %o0, 0x86f
a00a0f90:  08 80 00 14  bleu  0xa00a0fe0
a00a0f94:  9a 02 20 08  add  %o0, 8, %o5
a00a0f98:  92 10 28 70  mov  0x870, %o1
a00a0f9c:  d2 33 20 38  sth  %o1, [ %o4 + 0x38 ]
a00a0fa0:  a0 14 23 f4  or  %l0, 0x3f4, %l0
a00a0fa4:  d6 14 20 38  lduh  [ %l0 + 0x38 ], %o3
a00a0fa8:  94 02 e0 04  add  %o3, 4, %o2
a00a0fac:  99 2a a0 10  sll  %o2, 0x10, %o4
a00a0fb0:  99 33 20 10  srl  %o4, 0x10, %o4
a00a0fb4:  90 10 20 06  mov  6, %o0
a00a0fb8:  92 10 20 00  clr  %o1
a00a0fbc:  d4 14 20 38  lduh  [ %l0 + 0x38 ], %o2
a00a0fc0:  d6 14 20 36  lduh  [ %l0 + 0x36 ], %o3
a00a0fc4:  40 02 96 2b  call  0xa0146870
a00a0fc8:  9a 10 20 00  clr  %o5
a00a0fcc:  31 00 04 20  sethi  %hi(0x108000), %i0
a00a0fd0:  f4 14 20 38  lduh  [ %l0 + 0x38 ], %i2
a00a0fd4:  f2 14 20 36  lduh  [ %l0 + 0x36 ], %i1
a00a0fd8:  40 00 f8 66  call  0xa00df170
a00a0fdc:  91 ee 21 68  restore  %i0, 0x168, %o0
a00a0fe0:  10 bf ff f0  b  0xa00a0fa0
a00a0fe4:  da 33 20 38  sth  %o5, [ %o4 + 0x38 ]
a00a0fe8:  81 c7 e0 08  ret
a00a0fec:  81 e8 00 00  restore
