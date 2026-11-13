# leon2s FUN_a0094e40 0xa0094e40-0xa0094f64 (292 bytes)
a0094e40:  9d e3 bf 98  save  %sp, -104, %sp
a0094e44:  82 06 7f ff  add  %i1, -1, %g1
a0094e48:  82 08 60 ff  and  %g1, 0xff, %g1
a0094e4c:  80 a0 60 02  cmp  %g1, 2
a0094e50:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0094e54:  82 60 20 00  subx  %g0, 0, %g1
a0094e58:  b2 1e 60 0a  xor  %i1, 0xa, %i1
a0094e5c:  80 a0 00 19  cmp  %g0, %i1
a0094e60:  82 08 60 01  and  %g1, 1, %g1
a0094e64:  9a 60 3f ff  subx  %g0, -1, %o5
a0094e68:  80 90 40 0d  orcc  %g1, %o5, %g0
a0094e6c:  82 0e 20 ff  and  %i0, 0xff, %g1
a0094e70:  92 10 20 04  mov  4, %o1
a0094e74:  94 10 20 00  clr  %o2
a0094e78:  96 10 20 02  mov  2, %o3
a0094e7c:  98 10 20 00  clr  %o4
a0094e80:  12 80 00 07  bne  0xa0094e9c
a0094e84:  90 10 00 01  mov  %g1, %o0
a0094e88:  90 10 00 01  mov  %g1, %o0
a0094e8c:  92 10 20 04  mov  4, %o1
a0094e90:  94 10 20 00  clr  %o2
a0094e94:  96 10 20 02  mov  2, %o3
a0094e98:  98 10 20 01  mov  1, %o4
a0094e9c:  40 00 4c 8c  call  0xa00a80cc
a0094ea0:  b8 0e 20 ff  and  %i0, 0xff, %i4
a0094ea4:  83 2f 20 03  sll  %i4, 3, %g1
a0094ea8:  82 20 40 1c  sub  %g1, %i4, %g1
a0094eac:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a0094eb0:  83 28 60 02  sll  %g1, 2, %g1
a0094eb4:  9a 13 61 80  or  %o5, 0x180, %o5
a0094eb8:  82 00 40 0d  add  %g1, %o5, %g1
a0094ebc:  c2 00 60 14  ld  [ %g1 + 0x14 ], %g1
a0094ec0:  83 30 60 0f  srl  %g1, 0xf, %g1
a0094ec4:  90 10 00 1c  mov  %i4, %o0
a0094ec8:  92 10 20 04  mov  4, %o1
a0094ecc:  94 10 20 00  clr  %o2
a0094ed0:  96 10 20 01  mov  1, %o3
a0094ed4:  80 88 60 01  btst  1, %g1
a0094ed8:  02 80 00 07  be  0xa0094ef4
a0094edc:  98 10 20 00  clr  %o4
a0094ee0:  90 10 00 1c  mov  %i4, %o0
a0094ee4:  92 10 20 04  mov  4, %o1
a0094ee8:  94 10 20 00  clr  %o2
a0094eec:  96 10 20 01  mov  1, %o3
a0094ef0:  98 10 20 01  mov  1, %o4
a0094ef4:  40 00 4c 76  call  0xa00a80cc
a0094ef8:  01 00 00 00  nop
a0094efc:  82 0e a0 ff  and  %i2, 0xff, %g1
a0094f00:  90 10 00 1c  mov  %i4, %o0
a0094f04:  92 10 20 00  clr  %o1
a0094f08:  94 10 20 08  mov  8, %o2
a0094f0c:  96 10 20 10  mov  0x10, %o3
a0094f10:  80 a0 60 01  cmp  %g1, 1
a0094f14:  12 80 00 0b  bne  0xa0094f40
a0094f18:  98 10 20 00  clr  %o4
a0094f1c:  40 00 4c 6c  call  0xa00a80cc
a0094f20:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0094f24:  90 10 00 1c  mov  %i4, %o0
a0094f28:  92 10 20 a3  mov  0xa3, %o1
a0094f2c:  94 10 20 10  mov  0x10, %o2
a0094f30:  40 00 4c cc  call  0xa00a8260
a0094f34:  96 10 20 01  mov  1, %o3
a0094f38:  10 80 00 06  b  0xa0094f50
a0094f3c:  b2 10 20 00  clr  %i1
a0094f40:  40 00 4c 63  call  0xa00a80cc
a0094f44:  98 10 20 01  mov  1, %o4
a0094f48:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0094f4c:  b2 10 20 00  clr  %i1
a0094f50:  b4 10 20 08  mov  8, %i2
a0094f54:  b6 10 20 20  mov  0x20, %i3
a0094f58:  40 00 4c 5d  call  0xa00a80cc
a0094f5c:  99 e8 20 01  restore  %g0, 1, %o4
a0094f60:  01 00 00 00  nop
