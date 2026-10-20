# leon2m FUN_a0134de0 0xa0134de0-0xa0135004 (548 bytes)
a0134de0:  9d e3 bf 78  save  %sp, -136, %sp
a0134de4:  a6 10 20 64  mov  0x64, %l3
a0134de8:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a0134dec:  a8 07 bf e0  add  %fp, -32, %l4
a0134df0:  c0 27 bf dc  clr  [ %fp + -36 ]
a0134df4:  e4 0c 63 8c  ldub  [ %l1 + 0x38c ], %l2
a0134df8:  10 80 00 06  b  0xa0134e10
a0134dfc:  a0 10 20 00  clr  %l0
a0134e00:  96 0c 20 ff  and  %l0, 0xff, %o3
a0134e04:  80 a2 e0 03  cmp  %o3, 3
a0134e08:  18 80 00 19  bgu  0xa0134e6c
a0134e0c:  c0 2c 63 8c  clrb  [ %l1 + 0x38c ]
a0134e10:  d8 0c 63 8c  ldub  [ %l1 + 0x38c ], %o4
a0134e14:  97 2b 20 02  sll  %o4, 2, %o3
a0134e18:  94 02 c0 0c  add  %o3, %o4, %o2
a0134e1c:  91 2a a0 02  sll  %o2, 2, %o0
a0134e20:  92 02 20 60  add  %o0, 0x60, %o1
a0134e24:  92 0a 60 fc  and  %o1, 0xfc, %o1
a0134e28:  90 10 20 00  clr  %o0
a0134e2c:  94 07 bf dc  add  %fp, -36, %o2
a0134e30:  67 fd 5d a8  call  0x4008c4d0
a0134e34:  96 10 20 01  mov  1, %o3
a0134e38:  c2 07 bf dc  ld  [ %fp + -36 ], %g1
a0134e3c:  80 88 60 0f  btst  0xf, %g1
a0134e40:  12 80 00 61  bne  0xa0134fc4
a0134e44:  de 0c 63 8c  ldub  [ %l1 + 0x38c ], %o7
a0134e48:  82 03 e0 01  add  %o7, 1, %g1
a0134e4c:  9a 08 60 ff  and  %g1, 0xff, %o5
a0134e50:  80 a3 60 03  cmp  %o5, 3
a0134e54:  18 bf ff eb  bgu  0xa0134e00
a0134e58:  a0 04 20 01  inc  %l0
a0134e5c:  96 0c 20 ff  and  %l0, 0xff, %o3
a0134e60:  80 a2 e0 03  cmp  %o3, 3
a0134e64:  08 bf ff eb  bleu  0xa0134e10
a0134e68:  c2 2c 63 8c  stb  %g1, [ %l1 + 0x38c ]
a0134e6c:  80 a0 00 0b  cmp  %g0, %o3
a0134e70:  82 40 20 00  addx  %g0, 0, %g1
a0134e74:  92 1a e0 04  xor  %o3, 4, %o1
a0134e78:  80 a0 00 09  cmp  %g0, %o1
a0134e7c:  a0 40 20 00  addx  %g0, 0, %l0
a0134e80:  80 88 40 10  btst  %g1, %l0
a0134e84:  02 80 00 22  be  0xa0134f0c
a0134e88:  80 a2 e0 04  cmp  %o3, 4
a0134e8c:  e4 2c 63 8c  stb  %l2, [ %l1 + 0x38c ]
a0134e90:  10 80 00 06  b  0xa0134ea8
a0134e94:  a0 10 20 00  clr  %l0
a0134e98:  96 0c 20 ff  and  %l0, 0xff, %o3
a0134e9c:  80 a2 e0 03  cmp  %o3, 3
a0134ea0:  18 80 00 1a  bgu  0xa0134f08
a0134ea4:  c0 2c 63 8c  clrb  [ %l1 + 0x38c ]
a0134ea8:  da 0c 63 8c  ldub  [ %l1 + 0x38c ], %o5
a0134eac:  99 2b 60 02  sll  %o5, 2, %o4
a0134eb0:  96 03 00 0d  add  %o4, %o5, %o3
a0134eb4:  95 2a e0 02  sll  %o3, 2, %o2
a0134eb8:  90 02 a0 60  add  %o2, 0x60, %o0
a0134ebc:  92 0a 20 fc  and  %o0, 0xfc, %o1
a0134ec0:  90 10 20 00  clr  %o0
a0134ec4:  94 07 bf dc  add  %fp, -36, %o2
a0134ec8:  67 fd 5d 82  call  0x4008c4d0
a0134ecc:  96 10 20 01  mov  1, %o3
a0134ed0:  e4 07 bf dc  ld  [ %fp + -36 ], %l2
a0134ed4:  80 8c a0 0f  btst  0xf, %l2
a0134ed8:  12 80 00 0c  bne  0xa0134f08
a0134edc:  96 0c 20 ff  and  %l0, 0xff, %o3
a0134ee0:  c2 0c 63 8c  ldub  [ %l1 + 0x38c ], %g1
a0134ee4:  82 00 60 01  inc  %g1
a0134ee8:  9e 08 60 ff  and  %g1, 0xff, %o7
a0134eec:  80 a3 e0 03  cmp  %o7, 3
a0134ef0:  18 bf ff ea  bgu  0xa0134e98
a0134ef4:  a0 04 20 01  inc  %l0
a0134ef8:  96 0c 20 ff  and  %l0, 0xff, %o3
a0134efc:  80 a2 e0 03  cmp  %o3, 3
a0134f00:  08 bf ff ea  bleu  0xa0134ea8
a0134f04:  c2 2c 63 8c  stb  %g1, [ %l1 + 0x38c ]
a0134f08:  80 a2 e0 04  cmp  %o3, 4
a0134f0c:  02 80 00 09  be  0xa0134f30
a0134f10:  92 10 3f fe  mov  -2, %o1
a0134f14:  d2 0c 63 8c  ldub  [ %l1 + 0x38c ], %o1
a0134f18:  9a 02 60 01  add  %o1, 1, %o5
a0134f1c:  a0 0b 60 ff  and  %o5, 0xff, %l0
a0134f20:  80 a4 20 03  cmp  %l0, 3
a0134f24:  28 80 00 03  bleu,a   0xa0134f30
a0134f28:  da 2c 63 8c  stb  %o5, [ %l1 + 0x38c ]
a0134f2c:  c0 2c 63 8c  clrb  [ %l1 + 0x38c ]
a0134f30:  a0 0a 60 ff  and  %o1, 0xff, %l0
a0134f34:  80 a4 20 fe  cmp  %l0, 0xfe
a0134f38:  02 80 00 31  be  0xa0134ffc
a0134f3c:  01 00 00 00  nop
a0134f40:  7f fe a1 b5  call  0xa00dd614
a0134f44:  90 10 20 20  mov  0x20, %o0	! 0x20
a0134f48:  80 8a 20 ff  btst  0xff, %o0
a0134f4c:  12 80 00 27  bne  0xa0134fe8
a0134f50:  13 00 06 95  sethi  %hi(0x1a5400), %o1
a0134f54:  97 2c 20 02  sll  %l0, 2, %o3
a0134f58:  94 02 c0 10  add  %o3, %l0, %o2
a0134f5c:  91 2a a0 02  sll  %o2, 2, %o0
a0134f60:  a4 02 20 60  add  %o0, 0x60, %l2
a0134f64:  a0 0c a0 ff  and  %l2, 0xff, %l0
a0134f68:  90 10 20 00  clr  %o0
a0134f6c:  92 10 00 10  mov  %l0, %o1
a0134f70:  94 10 00 14  mov  %l4, %o2
a0134f74:  67 fd 5d 57  call  0x4008c4d0
a0134f78:  96 10 20 05  mov  5, %o3
a0134f7c:  7f fe a1 a6  call  0xa00dd614
a0134f80:  90 10 20 20  mov  0x20, %o0
a0134f84:  80 8a 20 ff  btst  0xff, %o0
a0134f88:  12 80 00 11  bne  0xa0134fcc
a0134f8c:  19 00 06 95  sethi  %hi(0x1a5400), %o4
a0134f90:  7f ff fe 7b  call  0xa013497c
a0134f94:  90 10 00 14  mov  %l4, %o0
a0134f98:  c0 27 bf d8  clr  [ %fp + -40 ]
a0134f9c:  92 10 00 10  mov  %l0, %o1
a0134fa0:  90 10 20 00  clr  %o0
a0134fa4:  94 07 bf d8  add  %fp, -40, %o2
a0134fa8:  67 fd 5d 94  call  0x4008c5f8
a0134fac:  96 10 20 01  mov  1, %o3
a0134fb0:  a6 04 ff ff  add  %l3, -1, %l3
a0134fb4:  80 8c e0 ff  btst  0xff, %l3
a0134fb8:  32 bf ff 8f  bne,a   0xa0134df4
a0134fbc:  c0 27 bf dc  clr  [ %fp + -36 ]
a0134fc0:  30 80 00 0f  b,a   0xa0134ffc
a0134fc4:  10 bf ff aa  b  0xa0134e6c
a0134fc8:  96 0c 20 ff  and  %l0, 0xff, %o3
a0134fcc:  90 13 21 10  or  %o4, 0x110, %o0
a0134fd0:  d2 07 bf e0  ld  [ %fp + -32 ], %o1
a0134fd4:  d4 07 bf e4  ld  [ %fp + -28 ], %o2
a0134fd8:  d6 07 bf e8  ld  [ %fp + -24 ], %o3
a0134fdc:  7f fe a8 65  call  0xa00df170
a0134fe0:  d8 07 bf ec  ld  [ %fp + -20 ], %o4
a0134fe4:  30 bf ff eb  b,a   0xa0134f90
a0134fe8:  90 12 60 f8  or  %o1, 0xf8, %o0
a0134fec:  7f fe a8 61  call  0xa00df170
a0134ff0:  92 10 00 10  mov  %l0, %o1
a0134ff4:  10 bf ff d9  b  0xa0134f58
a0134ff8:  97 2c 20 02  sll  %l0, 2, %o3
a0134ffc:  81 c7 e0 08  ret
a0135000:  81 e8 00 00  restore
