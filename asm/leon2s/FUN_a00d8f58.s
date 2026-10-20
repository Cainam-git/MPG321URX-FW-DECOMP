# leon2s FUN_a00d8f58 0xa00d8f58-0xa00d8fdc (132 bytes)
a00d8f58:  9d e3 be 88  save  %sp, -376, %sp
a00d8f5c:  a0 07 be f0  add  %fp, -272, %l0
a00d8f60:  92 10 20 00  clr  %o1
a00d8f64:  94 10 21 04  mov  0x104, %o2
a00d8f68:  40 3b a1 91  call  0xa0fc15ac
a00d8f6c:  90 10 00 10  mov  %l0, %o0
a00d8f70:  90 10 00 10  mov  %l0, %o0
a00d8f74:  92 10 20 00  clr  %o1
a00d8f78:  94 10 20 01  mov  1, %o2
a00d8f7c:  7f ff f9 0e  call  0xa00d73b4
a00d8f80:  96 10 20 1a  mov  0x1a, %o3
a00d8f84:  c2 07 be e8  ld  [ %fp + -280 ], %g1
a00d8f88:  19 1f c0 00  sethi  %hi(0x7f000000), %o4
a00d8f8c:  98 28 40 0c  andn  %g1, %o4, %o4
a00d8f90:  1b 08 c0 00  sethi  %hi(0x23000000), %o5
a00d8f94:  c2 07 be f0  ld  [ %fp + -272 ], %g1
a00d8f98:  98 13 00 0d  or  %o4, %o5, %o4
a00d8f9c:  83 30 60 14  srl  %g1, 0x14, %g1
a00d8fa0:  82 08 60 0f  and  %g1, 0xf, %g1
a00d8fa4:  1b 00 03 c0  sethi  %hi(0xf0000), %o5
a00d8fa8:  9a 2b 00 0d  andn  %o4, %o5, %o5
a00d8fac:  83 28 60 10  sll  %g1, 0x10, %g1
a00d8fb0:  9a 13 40 01  or  %o5, %g1, %o5
a00d8fb4:  da 27 be e8  st  %o5, [ %fp + -280 ]
a00d8fb8:  90 07 be e8  add  %fp, -280, %o0
a00d8fbc:  92 10 20 02  mov  2, %o1
a00d8fc0:  94 10 20 01  mov  1, %o2
a00d8fc4:  96 10 20 0a  mov  0xa, %o3
a00d8fc8:  7f ff fa 55  call  0xa00d791c
a00d8fcc:  98 10 20 02  mov  2, %o4
a00d8fd0:  01 00 00 00  nop
a00d8fd4:  81 c7 e0 08  ret
a00d8fd8:  81 e8 00 00  restore
