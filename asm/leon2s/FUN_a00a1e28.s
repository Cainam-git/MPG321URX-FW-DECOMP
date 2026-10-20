# leon2s FUN_a00a1e28 0xa00a1e28-0xa00a1f84 (348 bytes)
a00a1e28:  98 0a 20 ff  and  %o0, 0xff, %o4
a00a1e2c:  17 2a 01 f5  sethi  %hi(0xa807d400), %o3
a00a1e30:  82 12 e3 e0  or  %o3, 0x3e0, %g1	! 0xa807d7e0
a00a1e34:  9a 5b 21 90  smul  %o4, 0x190, %o5
a00a1e38:  9a 03 40 01  add  %o5, %g1, %o5
a00a1e3c:  c2 0b 60 18  ldub  [ %o5 + 0x18 ], %g1
a00a1e40:  80 a0 60 00  cmp  %g1, 0
a00a1e44:  02 80 00 4e  be  0xa00a1f7c
a00a1e48:  90 10 20 01  mov  1, %o0
a00a1e4c:  c2 03 60 50  ld  [ %o5 + 0x50 ], %g1
a00a1e50:  80 a0 60 00  cmp  %g1, 0
a00a1e54:  22 80 00 3d  be,a   0xa00a1f48
a00a1e58:  c2 03 60 70  ld  [ %o5 + 0x70 ], %g1
a00a1e5c:  c2 03 60 60  ld  [ %o5 + 0x60 ], %g1
a00a1e60:  80 a0 60 03  cmp  %g1, 3
a00a1e64:  12 80 00 11  bne  0xa00a1ea8
a00a1e68:  90 10 20 02  mov  2, %o0
a00a1e6c:  da 03 60 70  ld  [ %o5 + 0x70 ], %o5
a00a1e70:  80 a3 60 01  cmp  %o5, 1
a00a1e74:  12 80 00 04  bne  0xa00a1e84
a00a1e78:  90 10 20 0e  mov  0xe, %o0
a00a1e7c:  10 80 00 0e  b  0xa00a1eb4
a00a1e80:  90 10 20 14  mov  0x14, %o0
a00a1e84:  80 a3 60 05  cmp  %o5, 5
a00a1e88:  12 80 00 04  bne  0xa00a1e98
a00a1e8c:  80 a3 60 06  cmp  %o5, 6
a00a1e90:  10 80 00 09  b  0xa00a1eb4
a00a1e94:  90 10 20 1c  mov  0x1c, %o0
a00a1e98:  22 80 00 07  be,a   0xa00a1eb4
a00a1e9c:  90 10 20 22  mov  0x22, %o0
a00a1ea0:  10 80 00 06  b  0xa00a1eb8
a00a1ea4:  82 12 e3 e0  or  %o3, 0x3e0, %g1
a00a1ea8:  80 a0 60 02  cmp  %g1, 2
a00a1eac:  22 80 00 02  be,a   0xa00a1eb4
a00a1eb0:  90 10 20 08  mov  8, %o0
a00a1eb4:  82 12 e3 e0  or  %o3, 0x3e0, %g1
a00a1eb8:  9a 5b 21 90  smul  %o4, 0x190, %o5
a00a1ebc:  9a 03 40 01  add  %o5, %g1, %o5
a00a1ec0:  c2 03 60 80  ld  [ %o5 + 0x80 ], %g1
a00a1ec4:  80 a0 60 00  cmp  %g1, 0
a00a1ec8:  32 80 00 0d  bne,a   0xa00a1efc
a00a1ecc:  90 02 20 01  inc  %o0
a00a1ed0:  c2 03 60 74  ld  [ %o5 + 0x74 ], %g1
a00a1ed4:  80 a0 60 01  cmp  %g1, 1
a00a1ed8:  02 80 00 09  be  0xa00a1efc
a00a1edc:  80 a0 60 00  cmp  %g1, 0
a00a1ee0:  32 80 00 07  bne,a   0xa00a1efc
a00a1ee4:  90 02 20 01  inc  %o0
a00a1ee8:  c2 0b 60 7c  ldub  [ %o5 + 0x7c ], %g1
a00a1eec:  80 a0 60 01  cmp  %g1, 1
a00a1ef0:  12 80 00 04  bne  0xa00a1f00
a00a1ef4:  82 12 e3 e0  or  %o3, 0x3e0, %g1
a00a1ef8:  90 02 20 01  inc  %o0
a00a1efc:  82 12 e3 e0  or  %o3, 0x3e0, %g1
a00a1f00:  9a 5b 21 90  smul  %o4, 0x190, %o5
a00a1f04:  9a 03 40 01  add  %o5, %g1, %o5
a00a1f08:  c2 03 60 50  ld  [ %o5 + 0x50 ], %g1
a00a1f0c:  80 a0 60 01  cmp  %g1, 1
a00a1f10:  12 80 00 07  bne  0xa00a1f2c
a00a1f14:  82 12 e3 e0  or  %o3, 0x3e0, %g1
a00a1f18:  c2 0b 61 85  ldub  [ %o5 + 0x185 ], %g1
a00a1f1c:  80 a0 60 00  cmp  %g1, 0
a00a1f20:  22 80 00 02  be,a   0xa00a1f28
a00a1f24:  90 02 20 02  add  %o0, 2, %o0
a00a1f28:  82 12 e3 e0  or  %o3, 0x3e0, %g1
a00a1f2c:  9a 5b 21 90  smul  %o4, 0x190, %o5
a00a1f30:  9a 03 40 01  add  %o5, %g1, %o5
a00a1f34:  c2 03 60 50  ld  [ %o5 + 0x50 ], %g1
a00a1f38:  80 a0 60 03  cmp  %g1, 3
a00a1f3c:  22 80 00 10  be,a   0xa00a1f7c
a00a1f40:  90 02 20 04  add  %o0, 4, %o0
a00a1f44:  30 80 00 0e  b,a   0xa00a1f7c
a00a1f48:  82 00 7f fb  add  %g1, -5, %g1
a00a1f4c:  80 a0 60 01  cmp  %g1, 1
a00a1f50:  18 80 00 07  bgu  0xa00a1f6c
a00a1f54:  c2 03 60 74  ld  [ %o5 + 0x74 ], %g1
a00a1f58:  82 18 60 01  xor  %g1, 1, %g1
a00a1f5c:  80 a0 00 01  cmp  %g0, %g1
a00a1f60:  82 40 20 00  addx  %g0, 0, %g1
a00a1f64:  10 80 00 06  b  0xa00a1f7c
a00a1f68:  90 00 60 1a  add  %g1, 0x1a, %o0
a00a1f6c:  82 18 60 01  xor  %g1, 1, %g1
a00a1f70:  80 a0 00 01  cmp  %g0, %g1
a00a1f74:  82 40 20 00  addx  %g0, 0, %g1
a00a1f78:  90 10 00 01  mov  %g1, %o0
a00a1f7c:  81 c3 e0 08  retl
a00a1f80:  90 0a 20 ff  and  %o0, 0xff, %o0
