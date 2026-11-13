# leon2s FUN_a00d7bf8 0xa00d7bf8-0xa00d7ca4 (172 bytes)
a00d7bf8:  19 2a 01 e2  sethi  %hi(0xa8078800), %o4
a00d7bfc:  c2 0b 20 32  ldub  [ %o4 + 0x32 ], %g1	! 0xa8078832
a00d7c00:  1b 2a 01 d8  sethi  %hi(0xa8076000), %o5
a00d7c04:  9a 13 60 a4  or  %o5, 0xa4, %o5	! 0xa80760a4
a00d7c08:  83 28 60 02  sll  %g1, 2, %g1
a00d7c0c:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00d7c10:  c2 00 63 dc  ld  [ %g1 + 0x3dc ], %g1
a00d7c14:  80 88 60 08  btst  8, %g1
a00d7c18:  02 80 00 18  be  0xa00d7c78
a00d7c1c:  94 10 20 00  clr  %o2
a00d7c20:  92 10 00 0d  mov  %o5, %o1
a00d7c24:  90 10 00 0c  mov  %o4, %o0
a00d7c28:  c2 0b 20 32  ldub  [ %o4 + 0x32 ], %g1
a00d7c2c:  83 28 60 02  sll  %g1, 2, %g1
a00d7c30:  da 02 40 01  ld  [ %o1 + %g1 ], %o5
a00d7c34:  c2 03 63 dc  ld  [ %o5 + 0x3dc ], %g1
a00d7c38:  82 10 60 08  or  %g1, 8, %g1
a00d7c3c:  c2 23 63 dc  st  %g1, [ %o5 + 0x3dc ]
a00d7c40:  c2 0a 20 32  ldub  [ %o0 + 0x32 ], %g1
a00d7c44:  83 28 60 02  sll  %g1, 2, %g1
a00d7c48:  d8 02 40 01  ld  [ %o1 + %g1 ], %o4
a00d7c4c:  9a 02 a0 01  add  %o2, 1, %o5
a00d7c50:  83 2b 60 10  sll  %o5, 0x10, %g1
a00d7c54:  97 30 60 10  srl  %g1, 0x10, %o3
a00d7c58:  c2 03 23 dc  ld  [ %o4 + 0x3dc ], %g1
a00d7c5c:  80 88 60 08  btst  8, %g1
a00d7c60:  94 10 00 0d  mov  %o5, %o2
a00d7c64:  02 80 00 05  be  0xa00d7c78
a00d7c68:  19 2a 01 e2  sethi  %hi(0xa8078800), %o4
a00d7c6c:  80 a2 e3 e7  cmp  %o3, 0x3e7
a00d7c70:  08 bf ff ef  bleu  0xa00d7c2c
a00d7c74:  c2 0b 20 32  ldub  [ %o4 + 0x32 ], %g1
a00d7c78:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d7c7c:  da 08 60 32  ldub  [ %g1 + 0x32 ], %o5	! 0xa8078832
a00d7c80:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00d7c84:  82 10 60 a4  or  %g1, 0xa4, %g1	! 0xa80760a4
a00d7c88:  9b 2b 60 02  sll  %o5, 2, %o5
a00d7c8c:  da 00 40 0d  ld  [ %g1 + %o5 ], %o5
a00d7c90:  c2 03 60 c0  ld  [ %o5 + 0xc0 ], %g1
a00d7c94:  82 10 60 80  or  %g1, 0x80, %g1
a00d7c98:  c2 23 60 c0  st  %g1, [ %o5 + 0xc0 ]
a00d7c9c:  81 c3 e0 08  retl
a00d7ca0:  01 00 00 00  nop
