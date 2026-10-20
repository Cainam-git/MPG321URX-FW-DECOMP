# leon2s FUN_a0072e60 0xa0072e60-0xa0072fd8 (376 bytes)
a0072e60:  9d e3 bf 98  save  %sp, -104, %sp
a0072e64:  9e 10 00 18  mov  %i0, %o7
a0072e68:  9a 10 00 1c  mov  %i4, %o5
a0072e6c:  96 10 00 1a  mov  %i2, %o3
a0072e70:  b0 10 00 1b  mov  %i3, %i0
a0072e74:  ba 10 00 0f  mov  %o7, %i5
a0072e78:  98 0b 60 04  and  %o5, 4, %o4
a0072e7c:  81 80 00 00  mov  %g0, %y
a0072e80:  01 00 00 00  nop
a0072e84:  01 00 00 00  nop
a0072e88:  01 00 00 00  nop
a0072e8c:  b4 76 40 0b  udiv  %i1, %o3, %i2
a0072e90:  82 5e 80 0b  smul  %i2, %o3, %g1
a0072e94:  b2 26 40 01  sub  %i1, %g1, %i1
a0072e98:  83 2e 60 18  sll  %i1, 0x18, %g1
a0072e9c:  83 38 60 18  sra  %g1, 0x18, %g1
a0072ea0:  b8 06 60 30  add  %i1, 0x30, %i4
a0072ea4:  80 a0 60 09  cmp  %g1, 9
a0072ea8:  04 80 00 06  ble  0xa0072ec0
a0072eac:  b6 07 60 01  add  %i5, 1, %i3
a0072eb0:  b8 06 60 37  add  %i1, 0x37, %i4
a0072eb4:  80 a3 20 00  cmp  %o4, 0
a0072eb8:  02 80 00 04  be  0xa0072ec8
a0072ebc:  82 06 60 57  add  %i1, 0x57, %g1
a0072ec0:  10 80 00 03  b  0xa0072ecc
a0072ec4:  f8 2f 40 00  stb  %i4, [ %i5 ]
a0072ec8:  c2 2f 40 00  stb  %g1, [ %i5 ]
a0072ecc:  b2 96 a0 00  orcc  %i2, 0, %i1
a0072ed0:  12 bf ff eb  bne  0xa0072e7c
a0072ed4:  ba 10 00 1b  mov  %i3, %i5
a0072ed8:  b8 0b 60 ff  and  %o5, 0xff, %i4
a0072edc:  80 8f 20 02  btst  2, %i4
a0072ee0:  02 80 00 06  be  0xa0072ef8
a0072ee4:  b4 27 40 0f  sub  %i5, %o7, %i2
a0072ee8:  82 10 20 2d  mov  0x2d, %g1
a0072eec:  c2 2e c0 00  stb  %g1, [ %i3 ]
a0072ef0:  ba 06 e0 01  add  %i3, 1, %i5
a0072ef4:  b4 27 40 0f  sub  %i5, %o7, %i2
a0072ef8:  80 a6 00 1a  cmp  %i0, %i2
a0072efc:  26 80 00 02  bl,a   0xa0072f04
a0072f00:  b0 10 00 1a  mov  %i2, %i0
a0072f04:  80 8f 20 01  btst  1, %i4
a0072f08:  12 80 00 05  bne  0xa0072f1c
a0072f0c:  b6 10 20 20  mov  0x20, %i3
a0072f10:  80 8f 20 08  btst  8, %i4
a0072f14:  32 80 00 02  bne,a   0xa0072f1c
a0072f18:  b6 10 20 30  mov  0x30, %i3
a0072f1c:  80 8f 20 02  btst  2, %i4
a0072f20:  02 80 00 14  be  0xa0072f70
a0072f24:  80 a6 80 18  cmp  %i2, %i0
a0072f28:  82 0e e0 30  and  %i3, 0x30, %g1
a0072f2c:  82 18 60 30  xor  %g1, 0x30, %g1
a0072f30:  80 a0 00 01  cmp  %g0, %g1
a0072f34:  82 60 3f ff  subx  %g0, -1, %g1
a0072f38:  80 a8 40 1c  andncc  %g1, %i4, %g0
a0072f3c:  02 80 00 0d  be  0xa0072f70
a0072f40:  80 a6 80 18  cmp  %i2, %i0
a0072f44:  82 06 bf ff  add  %i2, -1, %g1
a0072f48:  ba 06 3f ff  add  %i0, -1, %i5
a0072f4c:  80 a0 40 1d  cmp  %g1, %i5
a0072f50:  36 80 00 05  bge,a   0xa0072f64
a0072f54:  ba 03 c0 18  add  %o7, %i0, %i5
a0072f58:  f6 2b c0 01  stb  %i3, [ %o7 + %g1 ]
a0072f5c:  10 bf ff fc  b  0xa0072f4c
a0072f60:  82 00 60 01  inc  %g1
a0072f64:  82 10 20 2d  mov  0x2d, %g1
a0072f68:  10 80 00 09  b  0xa0072f8c
a0072f6c:  c2 2f 7f ff  stb  %g1, [ %i5 + -1 ]
a0072f70:  82 10 00 1a  mov  %i2, %g1
a0072f74:  36 80 00 07  bge,a   0xa0072f90
a0072f78:  80 8f 20 01  btst  1, %i4
a0072f7c:  f6 2b c0 01  stb  %i3, [ %o7 + %g1 ]
a0072f80:  82 00 60 01  inc  %g1
a0072f84:  10 bf ff fc  b  0xa0072f74
a0072f88:  80 a0 40 18  cmp  %g1, %i0
a0072f8c:  80 8f 20 01  btst  1, %i4
a0072f90:  b8 06 bf ff  add  %i2, -1, %i4
a0072f94:  12 80 00 03  bne  0xa0072fa0
a0072f98:  b4 10 20 00  clr  %i2
a0072f9c:  b8 06 3f ff  add  %i0, -1, %i4
a0072fa0:  80 a7 20 00  cmp  %i4, 0
a0072fa4:  04 80 00 0b  ble  0xa0072fd0
a0072fa8:  01 00 00 00  nop
a0072fac:  fa 0b c0 1a  ldub  [ %o7 + %i2 ], %i5
a0072fb0:  c2 0b c0 1c  ldub  [ %o7 + %i4 ], %g1
a0072fb4:  c2 2b c0 1a  stb  %g1, [ %o7 + %i2 ]
a0072fb8:  fa 2b c0 1c  stb  %i5, [ %o7 + %i4 ]
a0072fbc:  b4 06 a0 01  inc  %i2
a0072fc0:  b8 07 3f ff  add  %i4, -1, %i4
a0072fc4:  80 a7 00 1a  cmp  %i4, %i2
a0072fc8:  34 bf ff fa  bg,a   0xa0072fb0
a0072fcc:  fa 0b c0 1a  ldub  [ %o7 + %i2 ], %i5
a0072fd0:  81 c7 e0 08  ret
a0072fd4:  81 e8 00 00  restore
