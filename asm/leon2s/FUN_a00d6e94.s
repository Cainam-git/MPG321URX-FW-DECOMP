# leon2s FUN_a00d6e94 0xa00d6e94-0xa00d6f70 (220 bytes)
a00d6e94:  9d e3 bf 98  save  %sp, -104, %sp
a00d6e98:  c2 0e 40 00  ldub  [ %i1 ], %g1
a00d6e9c:  83 30 60 04  srl  %g1, 4, %g1
a00d6ea0:  82 00 7f ff  add  %g1, -1, %g1
a00d6ea4:  bb 30 60 1f  srl  %g1, 0x1f, %i5
a00d6ea8:  ba 00 40 1d  add  %g1, %i5, %i5
a00d6eac:  bb 3f 60 01  sra  %i5, 1, %i5
a00d6eb0:  80 88 60 01  btst  1, %g1
a00d6eb4:  02 80 00 03  be  0xa00d6ec0
a00d6eb8:  82 10 00 1d  mov  %i5, %g1
a00d6ebc:  82 07 60 01  add  %i5, 1, %g1
a00d6ec0:  9e 08 60 ff  and  %g1, 0xff, %o7
a00d6ec4:  b6 06 40 0f  add  %i1, %o7, %i3
a00d6ec8:  c2 0e e0 03  ldub  [ %i3 + 3 ], %g1
a00d6ecc:  fa 06 00 00  ld  [ %i0 ], %i5
a00d6ed0:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d6ed4:  39 1f c0 00  sethi  %hi(0x7f000000), %i4
a00d6ed8:  b8 2f 40 1c  andn  %i5, %i4, %i4
a00d6edc:  83 28 60 18  sll  %g1, 0x18, %g1
a00d6ee0:  b8 17 00 01  or  %i4, %g1, %i4
a00d6ee4:  f8 26 00 00  st  %i4, [ %i0 ]
a00d6ee8:  fa 0e e0 04  ldub  [ %i3 + 4 ], %i5
a00d6eec:  bb 37 60 04  srl  %i5, 4, %i5
a00d6ef0:  03 00 3c 00  sethi  %hi(0xf00000), %g1
a00d6ef4:  bb 2f 60 14  sll  %i5, 0x14, %i5
a00d6ef8:  82 2f 00 01  andn  %i4, %g1, %g1
a00d6efc:  82 10 40 1d  or  %g1, %i5, %g1
a00d6f00:  c2 26 00 00  st  %g1, [ %i0 ]
a00d6f04:  c2 0e e0 04  ldub  [ %i3 + 4 ], %g1
a00d6f08:  fa 0e e0 05  ldub  [ %i3 + 5 ], %i5
a00d6f0c:  82 08 60 0f  and  %g1, 0xf, %g1
a00d6f10:  bb 2f 60 08  sll  %i5, 8, %i5
a00d6f14:  83 28 60 10  sll  %g1, 0x10, %g1
a00d6f18:  82 10 40 1d  or  %g1, %i5, %g1
a00d6f1c:  fa 0e e0 06  ldub  [ %i3 + 6 ], %i5
a00d6f20:  82 10 40 1d  or  %g1, %i5, %g1
a00d6f24:  c2 26 20 04  st  %g1, [ %i0 + 4 ]
a00d6f28:  c2 0e e0 07  ldub  [ %i3 + 7 ], %g1
a00d6f2c:  c2 2e 20 08  stb  %g1, [ %i0 + 8 ]
a00d6f30:  80 a0 60 00  cmp  %g1, 0
a00d6f34:  02 80 00 0d  be  0xa00d6f68
a00d6f38:  b6 10 20 00  clr  %i3
a00d6f3c:  b4 10 00 01  mov  %g1, %i2
a00d6f40:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00d6f44:  82 03 c0 1d  add  %o7, %i5, %g1
a00d6f48:  82 00 40 19  add  %g1, %i1, %g1
a00d6f4c:  f8 08 60 08  ldub  [ %g1 + 8 ], %i4
a00d6f50:  b6 06 e0 01  inc  %i3
a00d6f54:  ba 07 40 18  add  %i5, %i0, %i5
a00d6f58:  82 0e e0 ff  and  %i3, 0xff, %g1
a00d6f5c:  80 a0 40 1a  cmp  %g1, %i2
a00d6f60:  0a bf ff f8  bcs  0xa00d6f40
a00d6f64:  f8 2f 60 09  stb  %i4, [ %i5 + 9 ]
a00d6f68:  81 c7 e0 08  ret
a00d6f6c:  81 e8 00 00  restore
