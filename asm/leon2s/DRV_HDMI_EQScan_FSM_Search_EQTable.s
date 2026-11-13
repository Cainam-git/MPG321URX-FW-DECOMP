# leon2s DRV_HDMI_EQScan_FSM_Search_EQTable 0xa0078dc8-0xa0078fe8 (544 bytes)
a0078dc8:  9d e3 bf 98  save  %sp, -104, %sp
a0078dcc:  2b 2a 01 e1  sethi  %hi(0xa8078400), %l5
a0078dd0:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1	! 0xa8078634
a0078dd4:  80 88 60 02  btst  2, %g1
a0078dd8:  02 80 00 10  be  0xa0078e18
a0078ddc:  a6 10 00 18  mov  %i0, %l3
a0078de0:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0078de4:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a0078de8:  92 06 20 41  add  %i0, 0x41, %o1
a0078dec:  9a 5b 68 98  smul  %o5, 0x898, %o5
a0078df0:  82 10 61 f0  or  %g1, 0x1f0, %g1
a0078df4:  9a 03 40 01  add  %o5, %g1, %o5
a0078df8:  93 2a 60 18  sll  %o1, 0x18, %o1
a0078dfc:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0078e00:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a0078e04:  90 12 22 88  or  %o0, 0x288, %o0
a0078e08:  93 3a 60 18  sra  %o1, 0x18, %o1
a0078e0c:  94 12 a1 b0  or  %o2, 0x1b0, %o2
a0078e10:  7f ff e8 8d  call  0xa0073044
a0078e14:  d6 0b 60 30  ldub  [ %o5 + 0x30 ], %o3
a0078e18:  29 2a 01 ea  sethi  %hi(0xa807a800), %l4
a0078e1c:  a0 0c e0 ff  and  %l3, 0xff, %l0
a0078e20:  82 5c 28 98  smul  %l0, 0x898, %g1
a0078e24:  9a 15 21 f0  or  %l4, 0x1f0, %o5
a0078e28:  96 00 40 0d  add  %g1, %o5, %o3
a0078e2c:  c2 0a e0 30  ldub  [ %o3 + 0x30 ], %g1
a0078e30:  82 00 7f ff  add  %g1, -1, %g1
a0078e34:  82 08 60 ff  and  %g1, 0xff, %g1
a0078e38:  80 a0 60 04  cmp  %g1, 4
a0078e3c:  38 80 00 0a  bgu,a   0xa0078e64
a0078e40:  c2 0a e0 31  ldub  [ %o3 + 0x31 ], %g1
a0078e44:  82 04 00 10  add  %l0, %l0, %g1
a0078e48:  82 00 40 10  add  %g1, %l0, %g1
a0078e4c:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a0078e50:  83 28 60 02  sll  %g1, 2, %g1
a0078e54:  98 10 20 0a  mov  0xa, %o4
a0078e58:  9a 13 60 c4  or  %o5, 0xc4, %o5
a0078e5c:  10 80 00 50  b  0xa0078f9c
a0078e60:  d8 23 40 01  st  %o4, [ %o5 + %g1 ]
a0078e64:  80 a0 60 01  cmp  %g1, 1
a0078e68:  12 80 00 13  bne  0xa0078eb4
a0078e6c:  98 15 21 f0  or  %l4, 0x1f0, %o4
a0078e70:  c2 0a e0 32  ldub  [ %o3 + 0x32 ], %g1
a0078e74:  80 a0 60 01  cmp  %g1, 1
a0078e78:  12 80 00 10  bne  0xa0078eb8
a0078e7c:  9a 5c 28 98  smul  %l0, 0x898, %o5
a0078e80:  c2 0a e0 33  ldub  [ %o3 + 0x33 ], %g1
a0078e84:  80 a0 60 01  cmp  %g1, 1
a0078e88:  32 80 00 0d  bne,a   0xa0078ebc
a0078e8c:  c2 0b 00 0d  ldub  [ %o4 + %o5 ], %g1
a0078e90:  82 04 00 10  add  %l0, %l0, %g1
a0078e94:  82 00 40 10  add  %g1, %l0, %g1
a0078e98:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a0078e9c:  83 28 60 02  sll  %g1, 2, %g1
a0078ea0:  98 10 20 10  mov  0x10, %o4
a0078ea4:  9a 13 60 c4  or  %o5, 0xc4, %o5
a0078ea8:  d8 23 40 01  st  %o4, [ %o5 + %g1 ]
a0078eac:  10 80 00 4c  b  0xa0078fdc
a0078eb0:  c0 2a e8 96  clrb  [ %o3 + 0x896 ]
a0078eb4:  9a 5c 28 98  smul  %l0, 0x898, %o5
a0078eb8:  c2 0b 00 0d  ldub  [ %o4 + %o5 ], %g1
a0078ebc:  80 a0 60 17  cmp  %g1, 0x17
a0078ec0:  18 80 00 39  bgu  0xa0078fa4
a0078ec4:  82 04 00 10  add  %l0, %l0, %g1
a0078ec8:  9a 03 40 0c  add  %o5, %o4, %o5
a0078ecc:  c2 0b 60 01  ldub  [ %o5 + 1 ], %g1
a0078ed0:  80 a0 60 17  cmp  %g1, 0x17
a0078ed4:  18 80 00 34  bgu  0xa0078fa4
a0078ed8:  82 04 00 10  add  %l0, %l0, %g1
a0078edc:  c2 0b 60 02  ldub  [ %o5 + 2 ], %g1
a0078ee0:  80 a0 60 17  cmp  %g1, 0x17
a0078ee4:  18 80 00 30  bgu  0xa0078fa4
a0078ee8:  82 04 00 10  add  %l0, %l0, %g1
a0078eec:  a4 10 20 00  clr  %l2
a0078ef0:  82 5c 28 98  smul  %l0, 0x898, %g1
a0078ef4:  9a 15 21 f0  or  %l4, 0x1f0, %o5
a0078ef8:  b0 0c a0 ff  and  %l2, 0xff, %i0
a0078efc:  a2 00 40 0d  add  %g1, %o5, %l1
a0078f00:  82 04 40 18  add  %l1, %i0, %g1
a0078f04:  c2 08 60 31  ldub  [ %g1 + 0x31 ], %g1
a0078f08:  80 a0 60 01  cmp  %g1, 1
a0078f0c:  02 80 00 14  be  0xa0078f5c
a0078f10:  a4 04 a0 01  inc  %l2
a0078f14:  92 04 e0 41  add  %l3, 0x41, %o1
a0078f18:  93 2a 60 18  sll  %o1, 0x18, %o1
a0078f1c:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1
a0078f20:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0078f24:  80 88 60 02  btst  2, %g1
a0078f28:  93 3a 60 18  sra  %o1, 0x18, %o1
a0078f2c:  90 12 22 a8  or  %o0, 0x2a8, %o0
a0078f30:  02 80 00 04  be  0xa0078f40
a0078f34:  94 10 00 18  mov  %i0, %o2
a0078f38:  7f ff e8 43  call  0xa0073044
a0078f3c:  d6 0c 40 18  ldub  [ %l1 + %i0 ], %o3
a0078f40:  90 10 00 10  mov  %l0, %o0
a0078f44:  92 10 00 18  mov  %i0, %o1
a0078f48:  7f ff ef eb  call  0xa0074ef4
a0078f4c:  d4 0c 40 18  ldub  [ %l1 + %i0 ], %o2
a0078f50:  c2 0c 40 18  ldub  [ %l1 + %i0 ], %g1
a0078f54:  82 00 60 01  inc  %g1
a0078f58:  c2 2c 40 18  stb  %g1, [ %l1 + %i0 ]
a0078f5c:  82 0c a0 ff  and  %l2, 0xff, %g1
a0078f60:  80 a0 60 02  cmp  %g1, 2
a0078f64:  08 bf ff e4  bleu  0xa0078ef4
a0078f68:  82 5c 28 98  smul  %l0, 0x898, %g1
a0078f6c:  9a 15 21 f0  or  %l4, 0x1f0, %o5
a0078f70:  82 00 40 0d  add  %g1, %o5, %g1
a0078f74:  c0 28 60 30  clrb  [ %g1 + 0x30 ]
a0078f78:  7f ff ef b0  call  0xa0074e38
a0078f7c:  90 10 00 10  mov  %l0, %o0
a0078f80:  9a 04 00 10  add  %l0, %l0, %o5
a0078f84:  9a 03 40 10  add  %o5, %l0, %o5
a0078f88:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0078f8c:  9b 2b 60 02  sll  %o5, 2, %o5
a0078f90:  98 10 20 0b  mov  0xb, %o4
a0078f94:  82 10 60 c4  or  %g1, 0xc4, %g1
a0078f98:  d8 20 40 0d  st  %o4, [ %g1 + %o5 ]
a0078f9c:  10 80 00 11  b  0xa0078fe0
a0078fa0:  b0 10 20 00  clr  %i0
a0078fa4:  82 00 40 10  add  %g1, %l0, %g1
a0078fa8:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a0078fac:  83 28 60 02  sll  %g1, 2, %g1
a0078fb0:  d8 05 62 34  ld  [ %l5 + 0x234 ], %o4
a0078fb4:  9a 13 60 c4  or  %o5, 0xc4, %o5
a0078fb8:  80 8b 20 02  btst  2, %o4
a0078fbc:  02 80 00 08  be  0xa0078fdc
a0078fc0:  c0 23 40 01  clr  [ %o5 + %g1 ]
a0078fc4:  92 04 e0 41  add  %l3, 0x41, %o1
a0078fc8:  93 2a 60 18  sll  %o1, 0x18, %o1
a0078fcc:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0078fd0:  90 12 22 d8  or  %o0, 0x2d8, %o0	! 0xa00676d8
a0078fd4:  7f ff e8 1c  call  0xa0073044
a0078fd8:  93 3a 60 18  sra  %o1, 0x18, %o1
a0078fdc:  b0 10 20 01  mov  1, %i0
a0078fe0:  81 c7 e0 08  ret
a0078fe4:  81 e8 00 00  restore
