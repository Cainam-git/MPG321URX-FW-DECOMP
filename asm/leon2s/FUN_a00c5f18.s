# leon2s FUN_a00c5f18 0xa00c5f18-0xa00c5fb0 (152 bytes)
a00c5f18:  9d e3 bf 98  save  %sp, -104, %sp
a00c5f1c:  90 0e 20 ff  and  %i0, 0xff, %o0
a00c5f20:  82 10 20 01  mov  1, %g1
a00c5f24:  15 2a 01 e3  sethi  %hi(0xa8078c00), %o2
a00c5f28:  9b 28 40 08  sll  %g1, %o0, %o5
a00c5f2c:  d8 0a a0 58  ldub  [ %o2 + 0x58 ], %o4
a00c5f30:  82 0b 20 ff  and  %o4, 0xff, %g1
a00c5f34:  82 08 40 0d  and  %g1, %o5, %g1
a00c5f38:  83 38 40 08  sra  %g1, %o0, %g1
a00c5f3c:  92 0e 60 ff  and  %i1, 0xff, %o1
a00c5f40:  80 a0 40 09  cmp  %g1, %o1
a00c5f44:  02 80 00 16  be  0xa00c5f9c
a00c5f48:  96 13 40 0c  or  %o5, %o4, %o3
a00c5f4c:  80 a2 60 00  cmp  %o1, 0
a00c5f50:  02 80 00 04  be  0xa00c5f60
a00c5f54:  82 2b 00 0d  andn  %o4, %o5, %g1
a00c5f58:  10 80 00 03  b  0xa00c5f64
a00c5f5c:  d6 2a a0 58  stb  %o3, [ %o2 + 0x58 ]
a00c5f60:  c2 2a a0 58  stb  %g1, [ %o2 + 0x58 ]
a00c5f64:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00c5f68:  82 10 20 01  mov  1, %g1
a00c5f6c:  9a 1a 20 04  xor  %o0, 4, %o5
a00c5f70:  d8 0a e0 d2  ldub  [ %o3 + 0xd2 ], %o4
a00c5f74:  80 a2 20 03  cmp  %o0, 3
a00c5f78:  08 80 00 06  bleu  0xa00c5f90
a00c5f7c:  83 28 40 08  sll  %g1, %o0, %g1
a00c5f80:  80 a0 00 0d  cmp  %g0, %o5
a00c5f84:  82 60 20 00  subx  %g0, 0, %g1
a00c5f88:  82 08 60 10  and  %g1, 0x10, %g1
a00c5f8c:  82 00 60 10  add  %g1, 0x10, %g1
a00c5f90:  82 13 00 01  or  %o4, %g1, %g1
a00c5f94:  7f ff ff 85  call  0xa00c5da8
a00c5f98:  c2 2a e0 d2  stb  %g1, [ %o3 + 0xd2 ]
a00c5f9c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c5fa0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00c5fa4:  7f ff ff 64  call  0xa00c5d34
a00c5fa8:  81 e8 00 00  restore
a00c5fac:  01 00 00 00  nop
