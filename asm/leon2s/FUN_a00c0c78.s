# leon2s FUN_a00c0c78 0xa00c0c78-0xa00c0ce8 (112 bytes)
a00c0c78:  03 27 c6 dc  sethi  %hi(0x9f1b7000), %g1
a00c0c7c:  94 10 60 18  or  %g1, 0x18, %o2	! 0x9f1b7018
a00c0c80:  82 10 20 00  clr  %g1
a00c0c84:  96 00 60 01  add  %g1, 1, %o3
a00c0c88:  83 28 60 10  sll  %g1, 0x10, %g1
a00c0c8c:  83 30 60 10  srl  %g1, 0x10, %g1
a00c0c90:  d8 0a 80 01  ldub  [ %o2 + %g1 ], %o4
a00c0c94:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00c0c98:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c0c9c:  d8 2a 00 01  stb  %o4, [ %o0 + %g1 ]
a00c0ca0:  80 a3 60 04  cmp  %o5, 4
a00c0ca4:  08 bf ff f8  bleu  0xa00c0c84
a00c0ca8:  82 10 00 0b  mov  %o3, %g1
a00c0cac:  03 27 c6 db  sethi  %hi(0x9f1b6c00), %g1
a00c0cb0:  94 10 62 f8  or  %g1, 0x2f8, %o2	! 0x9f1b6ef8
a00c0cb4:  82 10 20 00  clr  %g1
a00c0cb8:  96 00 60 01  add  %g1, 1, %o3
a00c0cbc:  83 28 60 10  sll  %g1, 0x10, %g1
a00c0cc0:  83 30 60 10  srl  %g1, 0x10, %g1
a00c0cc4:  d8 0a 80 01  ldub  [ %o2 + %g1 ], %o4
a00c0cc8:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00c0ccc:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c0cd0:  d8 2a 40 01  stb  %o4, [ %o1 + %g1 ]
a00c0cd4:  80 a3 61 19  cmp  %o5, 0x119
a00c0cd8:  08 bf ff f8  bleu  0xa00c0cb8
a00c0cdc:  82 10 00 0b  mov  %o3, %g1
a00c0ce0:  81 c3 e0 08  retl
a00c0ce4:  01 00 00 00  nop
