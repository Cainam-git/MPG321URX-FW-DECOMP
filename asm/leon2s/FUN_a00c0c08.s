# leon2s FUN_a00c0c08 0xa00c0c08-0xa00c0c78 (112 bytes)
a00c0c08:  03 27 c6 dc  sethi  %hi(0x9f1b7000), %g1
a00c0c0c:  94 10 61 40  or  %g1, 0x140, %o2	! 0x9f1b7140
a00c0c10:  82 10 20 00  clr  %g1
a00c0c14:  96 00 60 01  add  %g1, 1, %o3
a00c0c18:  83 28 60 10  sll  %g1, 0x10, %g1
a00c0c1c:  83 30 60 10  srl  %g1, 0x10, %g1
a00c0c20:  d8 0a 80 01  ldub  [ %o2 + %g1 ], %o4
a00c0c24:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00c0c28:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c0c2c:  d8 2a 00 01  stb  %o4, [ %o0 + %g1 ]
a00c0c30:  80 a3 60 04  cmp  %o5, 4
a00c0c34:  08 bf ff f8  bleu  0xa00c0c14
a00c0c38:  82 10 00 0b  mov  %o3, %g1
a00c0c3c:  03 27 c6 dc  sethi  %hi(0x9f1b7000), %g1
a00c0c40:  94 10 60 20  or  %g1, 0x20, %o2	! 0x9f1b7020
a00c0c44:  82 10 20 00  clr  %g1
a00c0c48:  96 00 60 01  add  %g1, 1, %o3
a00c0c4c:  83 28 60 10  sll  %g1, 0x10, %g1
a00c0c50:  83 30 60 10  srl  %g1, 0x10, %g1
a00c0c54:  d8 0a 80 01  ldub  [ %o2 + %g1 ], %o4
a00c0c58:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00c0c5c:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c0c60:  d8 2a 40 01  stb  %o4, [ %o1 + %g1 ]
a00c0c64:  80 a3 61 19  cmp  %o5, 0x119
a00c0c68:  08 bf ff f8  bleu  0xa00c0c48
a00c0c6c:  82 10 00 0b  mov  %o3, %g1
a00c0c70:  81 c3 e0 08  retl
a00c0c74:  01 00 00 00  nop
