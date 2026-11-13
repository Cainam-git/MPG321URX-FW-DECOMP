# leon2s FUN_a00a2ecc 0xa00a2ecc-0xa00a2f70 (164 bytes)
a00a2ecc:  9d e3 bf 98  save  %sp, -104, %sp
a00a2ed0:  a0 10 20 00  clr  %l0
a00a2ed4:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00a2ed8:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a2edc:  9a 5b 60 34  smul  %o5, 0x34, %o5
a00a2ee0:  82 10 63 00  or  %g1, 0x300, %g1
a00a2ee4:  b0 03 40 01  add  %o5, %g1, %i0
a00a2ee8:  d2 06 20 30  ld  [ %i0 + 0x30 ], %o1
a00a2eec:  03 20 00 20  sethi  %hi(0x80008000), %g1
a00a2ef0:  c2 22 60 30  st  %g1, [ %o1 + 0x30 ]
a00a2ef4:  92 02 60 34  add  %o1, 0x34, %o1
a00a2ef8:  40 00 11 2d  call  0xa00a73ac
a00a2efc:  90 10 20 1c  mov  0x1c, %o0
a00a2f00:  d2 06 20 04  ld  [ %i0 + 4 ], %o1
a00a2f04:  da 02 40 00  ld  [ %o1 ], %o5
a00a2f08:  03 00 3c 00  sethi  %hi(0xf00000), %g1
a00a2f0c:  82 2b 40 01  andn  %o5, %g1, %g1
a00a2f10:  1b 00 14 00  sethi  %hi(0x500000), %o5
a00a2f14:  82 10 40 0d  or  %g1, %o5, %g1
a00a2f18:  c2 22 40 00  st  %g1, [ %o1 ]
a00a2f1c:  40 00 11 2e  call  0xa00a73d4
a00a2f20:  90 10 20 01  mov  1, %o0
a00a2f24:  90 10 20 01  mov  1, %o0
a00a2f28:  40 00 11 38  call  0xa00a7408
a00a2f2c:  d2 06 20 04  ld  [ %i0 + 4 ], %o1
a00a2f30:  a0 04 20 01  inc  %l0
a00a2f34:  80 a2 20 00  cmp  %o0, 0
a00a2f38:  02 80 00 09  be  0xa00a2f5c
a00a2f3c:  96 0c 20 ff  and  %l0, 0xff, %o3
a00a2f40:  d8 06 20 04  ld  [ %i0 + 4 ], %o4
a00a2f44:  da 03 00 00  ld  [ %o4 ], %o5
a00a2f48:  03 00 03 c0  sethi  %hi(0xf0000), %g1
a00a2f4c:  82 2b 40 01  andn  %o5, %g1, %g1
a00a2f50:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00a2f54:  82 10 40 0d  or  %g1, %o5, %g1
a00a2f58:  c2 23 00 00  st  %g1, [ %o4 ]
a00a2f5c:  80 a2 e0 01  cmp  %o3, 1
a00a2f60:  08 bf ff de  bleu  0xa00a2ed8
a00a2f64:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00a2f68:  81 c7 e0 08  ret
a00a2f6c:  91 e8 20 00  restore  %g0, 0, %o0
