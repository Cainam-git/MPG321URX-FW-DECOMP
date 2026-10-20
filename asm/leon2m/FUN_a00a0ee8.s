# leon2m FUN_a00a0ee8 0xa00a0ee8-0xa00a0f6c (132 bytes)
a00a0ee8:  9d e3 bf 98  save  %sp, -104, %sp
a00a0eec:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a00a0ef0:  98 14 23 f4  or  %l0, 0x3f4, %o4	! 0xa802cff4
a00a0ef4:  c2 0b 20 34  ldub  [ %o4 + 0x34 ], %g1
a00a0ef8:  80 a0 60 02  cmp  %g1, 2
a00a0efc:  08 80 00 1a  bleu  0xa00a0f64
a00a0f00:  01 00 00 00  nop
a00a0f04:  d0 13 20 38  lduh  [ %o4 + 0x38 ], %o0
a00a0f08:  80 a2 28 70  cmp  %o0, 0x870
a00a0f0c:  18 80 00 14  bgu  0xa00a0f5c
a00a0f10:  9a 02 3f f8  add  %o0, -8, %o5
a00a0f14:  92 10 28 70  mov  0x870, %o1
a00a0f18:  d2 33 20 38  sth  %o1, [ %o4 + 0x38 ]
a00a0f1c:  a0 14 23 f4  or  %l0, 0x3f4, %l0
a00a0f20:  d6 14 20 38  lduh  [ %l0 + 0x38 ], %o3
a00a0f24:  94 02 e0 04  add  %o3, 4, %o2
a00a0f28:  99 2a a0 10  sll  %o2, 0x10, %o4
a00a0f2c:  99 33 20 10  srl  %o4, 0x10, %o4
a00a0f30:  90 10 20 06  mov  6, %o0
a00a0f34:  92 10 20 00  clr  %o1
a00a0f38:  d4 14 20 38  lduh  [ %l0 + 0x38 ], %o2
a00a0f3c:  d6 14 20 36  lduh  [ %l0 + 0x36 ], %o3
a00a0f40:  40 02 96 4c  call  0xa0146870
a00a0f44:  9a 10 20 00  clr  %o5
a00a0f48:  31 00 04 20  sethi  %hi(0x108000), %i0
a00a0f4c:  f4 14 20 38  lduh  [ %l0 + 0x38 ], %i2
a00a0f50:  f2 14 20 36  lduh  [ %l0 + 0x36 ], %i1
a00a0f54:  40 00 f8 87  call  0xa00df170
a00a0f58:  91 ee 21 50  restore  %i0, 0x150, %o0
a00a0f5c:  10 bf ff f0  b  0xa00a0f1c
a00a0f60:  da 33 20 38  sth  %o5, [ %o4 + 0x38 ]
a00a0f64:  81 c7 e0 08  ret
a00a0f68:  81 e8 00 00  restore
