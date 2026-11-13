# leon2s FUN_a00c0ecc 0xa00c0ecc-0xa00c0f88 (188 bytes)
a00c0ecc:  9d e3 bf 98  save  %sp, -104, %sp
a00c0ed0:  03 27 c6 dc  sethi  %hi(0x9f1b7000), %g1
a00c0ed4:  9e 10 00 19  mov  %i1, %o7
a00c0ed8:  b2 10 61 48  or  %g1, 0x148, %i1
a00c0edc:  9a 10 00 1b  mov  %i3, %o5
a00c0ee0:  82 10 20 00  clr  %g1
a00c0ee4:  b4 10 20 13  mov  0x13, %i2
a00c0ee8:  b9 28 60 10  sll  %g1, 0x10, %i4
a00c0eec:  b6 00 60 01  add  %g1, 1, %i3
a00c0ef0:  b9 37 20 10  srl  %i4, 0x10, %i4
a00c0ef4:  82 26 80 1c  sub  %i2, %i4, %g1
a00c0ef8:  c2 0e 40 01  ldub  [ %i1 + %g1 ], %g1
a00c0efc:  bb 2e e0 10  sll  %i3, 0x10, %i5
a00c0f00:  bb 37 60 10  srl  %i5, 0x10, %i5
a00c0f04:  c2 2e 00 1c  stb  %g1, [ %i0 + %i4 ]
a00c0f08:  80 a7 60 0f  cmp  %i5, 0xf
a00c0f0c:  08 bf ff f7  bleu  0xa00c0ee8
a00c0f10:  82 10 00 1b  mov  %i3, %g1
a00c0f14:  03 27 c6 dc  sethi  %hi(0x9f1b7000), %g1
a00c0f18:  b4 10 61 48  or  %g1, 0x148, %i2	! 0x9f1b7148
a00c0f1c:  82 10 20 00  clr  %g1
a00c0f20:  b9 28 60 10  sll  %g1, 0x10, %i4
a00c0f24:  b6 00 60 01  add  %g1, 1, %i3
a00c0f28:  b9 37 20 10  srl  %i4, 0x10, %i4
a00c0f2c:  82 07 00 1a  add  %i4, %i2, %g1
a00c0f30:  c2 08 60 28  ldub  [ %g1 + 0x28 ], %g1
a00c0f34:  bb 2e e0 10  sll  %i3, 0x10, %i5
a00c0f38:  bb 37 60 10  srl  %i5, 0x10, %i5
a00c0f3c:  c2 2b c0 1c  stb  %g1, [ %o7 + %i4 ]
a00c0f40:  80 a7 62 09  cmp  %i5, 0x209
a00c0f44:  08 bf ff f7  bleu  0xa00c0f20
a00c0f48:  82 10 00 1b  mov  %i3, %g1
a00c0f4c:  03 27 c6 dd  sethi  %hi(0x9f1b7400), %g1
a00c0f50:  b4 10 60 b8  or  %g1, 0xb8, %i2	! 0x9f1b74b8
a00c0f54:  82 10 20 00  clr  %g1
a00c0f58:  b6 00 60 01  add  %g1, 1, %i3
a00c0f5c:  83 28 60 10  sll  %g1, 0x10, %g1
a00c0f60:  83 30 60 10  srl  %g1, 0x10, %g1
a00c0f64:  f8 0e 80 01  ldub  [ %i2 + %g1 ], %i4
a00c0f68:  bb 2e e0 10  sll  %i3, 0x10, %i5
a00c0f6c:  bb 37 60 10  srl  %i5, 0x10, %i5
a00c0f70:  f8 2b 40 01  stb  %i4, [ %o5 + %g1 ]
a00c0f74:  80 a7 60 7f  cmp  %i5, 0x7f
a00c0f78:  08 bf ff f8  bleu  0xa00c0f58
a00c0f7c:  82 10 00 1b  mov  %i3, %g1
a00c0f80:  81 c7 e0 08  ret
a00c0f84:  81 e8 00 00  restore
