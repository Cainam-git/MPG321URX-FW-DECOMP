# leon2m FUN_a00f8e44 0xa00f8e44-0xa00f8ef4 (176 bytes)
a00f8e44:  9d e3 bf 98  save  %sp, -104, %sp
a00f8e48:  90 06 3f fa  add  %i0, -6, %o0
a00f8e4c:  a0 10 00 19  mov  %i1, %l0
a00f8e50:  82 0a 20 ff  and  %o0, 0xff, %g1
a00f8e54:  92 10 20 03  mov  3, %o1
a00f8e58:  b2 10 20 0c  mov  0xc, %i1
a00f8e5c:  80 a0 60 01  cmp  %g1, 1
a00f8e60:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f8e64:  08 80 00 10  bleu  0xa00f8ea4
a00f8e68:  b4 10 00 10  mov  %l0, %i2
a00f8e6c:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f8e70:  9e 06 00 18  add  %i0, %i0, %o7
a00f8e74:  a0 13 63 d8  or  %o5, 0x3d8, %l0
a00f8e78:  d8 14 00 0f  lduh  [ %l0 + %o7 ], %o4
a00f8e7c:  96 03 00 1a  add  %o4, %i2, %o3
a00f8e80:  93 2a e0 10  sll  %o3, 0x10, %o1
a00f8e84:  95 32 60 10  srl  %o1, 0x10, %o2
a00f8e88:  90 10 00 18  mov  %i0, %o0
a00f8e8c:  92 10 20 0e  mov  0xe, %o1
a00f8e90:  7f ff e3 ae  call  0xa00f1d48
a00f8e94:  b5 2e a0 10  sll  %i2, 0x10, %i2
a00f8e98:  b5 36 a0 10  srl  %i2, 0x10, %i2
a00f8e9c:  7f ff e3 ab  call  0xa00f1d48
a00f8ea0:  81 e8 00 00  restore
a00f8ea4:  7f ff e2 fb  call  0xa00f1a90
a00f8ea8:  90 10 00 18  mov  %i0, %o0
a00f8eac:  80 8a 20 30  btst  0x30, %o0
a00f8eb0:  92 10 20 04  mov  4, %o1
a00f8eb4:  12 bf ff ee  bne  0xa00f8e6c
a00f8eb8:  90 10 00 18  mov  %i0, %o0
a00f8ebc:  7f ff e2 f5  call  0xa00f1a90
a00f8ec0:  01 00 00 00  nop
a00f8ec4:  94 0a 20 0f  and  %o0, 0xf, %o2
a00f8ec8:  92 10 20 5c  mov  0x5c, %o1
a00f8ecc:  80 a2 a0 01  cmp  %o2, 1
a00f8ed0:  14 bf ff e7  bg  0xa00f8e6c
a00f8ed4:  90 10 00 18  mov  %i0, %o0
a00f8ed8:  7f ff e2 ee  call  0xa00f1a90
a00f8edc:  01 00 00 00  nop
a00f8ee0:  80 8a 20 01  btst  1, %o0
a00f8ee4:  22 bf ff e2  be,a   0xa00f8e6c
a00f8ee8:  b4 04 20 01  add  %l0, 1, %i2
a00f8eec:  10 bf ff e1  b  0xa00f8e70
a00f8ef0:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
