# leon2s FUN_a00d9be4 0xa00d9be4-0xa00d9d50 (364 bytes)
a00d9be4:  9d e3 bf 38  save  %sp, -200, %sp
a00d9be8:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a00d9bec:  1b 00 00 08  sethi  %hi(0x2000), %o5
a00d9bf0:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d9bf4:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a00d9bf8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d9bfc:  d6 0c e0 32  ldub  [ %l3 + 0x32 ], %o3
a00d9c00:  82 10 60 30  or  %g1, 0x30, %g1
a00d9c04:  29 2a 01 e2  sethi  %hi(0xa8078800), %l4
a00d9c08:  d8 08 40 0b  ldub  [ %g1 + %o3 ], %o4
a00d9c0c:  a0 15 20 28  or  %l4, 0x28, %l0
a00d9c10:  c2 0c 00 0b  ldub  [ %l0 + %o3 ], %g1
a00d9c14:  80 a3 00 01  cmp  %o4, %g1
a00d9c18:  02 80 00 4c  be  0xa00d9d48
a00d9c1c:  da 27 bf f0  st  %o5, [ %fp + -16 ]
a00d9c20:  7f ff f8 2c  call  0xa00d7cd0
a00d9c24:  01 00 00 00  nop
a00d9c28:  a4 0a 20 ff  and  %o0, 0xff, %l2
a00d9c2c:  98 0c a0 e0  and  %l2, 0xe0, %o4
a00d9c30:  82 1b 20 80  xor  %o4, 0x80, %g1
a00d9c34:  80 a0 00 01  cmp  %g0, %g1
a00d9c38:  9a 40 20 00  addx  %g0, 0, %o5
a00d9c3c:  82 1b 20 40  xor  %o4, 0x40, %g1
a00d9c40:  80 a0 00 01  cmp  %g0, %g1
a00d9c44:  82 40 20 00  addx  %g0, 0, %g1
a00d9c48:  80 8b 40 01  btst  %o5, %g1
a00d9c4c:  02 80 00 3a  be  0xa00d9d34
a00d9c50:  80 a3 20 40  cmp  %o4, 0x40
a00d9c54:  a2 07 bf e0  add  %fp, -32, %l1
a00d9c58:  90 10 00 11  mov  %l1, %o0
a00d9c5c:  92 10 20 00  clr  %o1
a00d9c60:  7f ff f3 0c  call  0xa00d6890
a00d9c64:  94 10 20 01  mov  1, %o2
a00d9c68:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a00d9c6c:  83 30 60 08  srl  %g1, 8, %g1
a00d9c70:  80 88 60 20  btst  0x20, %g1
a00d9c74:  02 80 00 35  be  0xa00d9d48
a00d9c78:  da 07 bf e0  ld  [ %fp + -32 ], %o5
a00d9c7c:  83 33 60 18  srl  %o5, 0x18, %g1
a00d9c80:  98 88 60 0f  andcc  %g1, 0xf, %o4
a00d9c84:  32 80 00 0d  bne,a   0xa00d9cb8
a00d9c88:  83 33 60 1c  srl  %o5, 0x1c, %g1
a00d9c8c:  a0 07 bf c8  add  %fp, -56, %l0
a00d9c90:  92 10 00 11  mov  %l1, %o1
a00d9c94:  94 10 20 13  mov  0x13, %o2
a00d9c98:  40 3b 9e 50  call  0xa0fc15d8
a00d9c9c:  90 10 00 10  mov  %l0, %o0
a00d9ca0:  7f ff fe 21  call  0xa00d9524
a00d9ca4:  90 10 00 10  mov  %l0, %o0
a00d9ca8:  7f ff fe 7c  call  0xa00d9698
a00d9cac:  01 00 00 00  nop
a00d9cb0:  10 80 00 1c  b  0xa00d9d20
a00d9cb4:  82 04 a0 01  add  %l2, 1, %g1
a00d9cb8:  80 a3 00 01  cmp  %o4, %g1
a00d9cbc:  0a 80 00 10  bcs  0xa00d9cfc
a00d9cc0:  a0 07 bf 98  add  %fp, -104, %l0
a00d9cc4:  a0 07 bf b0  add  %fp, -80, %l0
a00d9cc8:  92 10 00 11  mov  %l1, %o1
a00d9ccc:  94 10 20 13  mov  0x13, %o2
a00d9cd0:  40 3b 9e 42  call  0xa0fc15d8
a00d9cd4:  90 10 00 10  mov  %l0, %o0
a00d9cd8:  7f ff fe 13  call  0xa00d9524
a00d9cdc:  90 10 00 10  mov  %l0, %o0
a00d9ce0:  7f ff fe 6e  call  0xa00d9698
a00d9ce4:  01 00 00 00  nop
a00d9ce8:  c2 0c e0 32  ldub  [ %l3 + 0x32 ], %g1
a00d9cec:  80 a0 60 00  cmp  %g1, 0
a00d9cf0:  12 80 00 0c  bne  0xa00d9d20
a00d9cf4:  82 04 a0 01  add  %l2, 1, %g1
a00d9cf8:  a0 07 bf 98  add  %fp, -104, %l0
a00d9cfc:  92 10 00 11  mov  %l1, %o1
a00d9d00:  94 10 20 13  mov  0x13, %o2
a00d9d04:  40 3b 9e 35  call  0xa0fc15d8
a00d9d08:  90 10 00 10  mov  %l0, %o0
a00d9d0c:  7f ff fe ac  call  0xa00d97bc
a00d9d10:  90 10 00 10  mov  %l0, %o0
a00d9d14:  7f ff fe d2  call  0xa00d985c
a00d9d18:  01 00 00 00  nop
a00d9d1c:  82 04 a0 01  add  %l2, 1, %g1
a00d9d20:  98 15 20 28  or  %l4, 0x28, %o4
a00d9d24:  da 0c e0 32  ldub  [ %l3 + 0x32 ], %o5
a00d9d28:  82 08 60 0f  and  %g1, 0xf, %g1
a00d9d2c:  10 80 00 07  b  0xa00d9d48
a00d9d30:  c2 2b 00 0d  stb  %g1, [ %o4 + %o5 ]
a00d9d34:  12 80 00 05  bne  0xa00d9d48
a00d9d38:  82 04 a0 01  add  %l2, 1, %g1
a00d9d3c:  da 0c e0 32  ldub  [ %l3 + 0x32 ], %o5
a00d9d40:  82 08 60 0f  and  %g1, 0xf, %g1
a00d9d44:  c2 2c 00 0d  stb  %g1, [ %l0 + %o5 ]
a00d9d48:  81 c7 e0 08  ret
a00d9d4c:  81 e8 00 00  restore
