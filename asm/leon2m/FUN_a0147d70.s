# leon2m FUN_a0147d70 0xa0147d70-0xa0147fb4 (580 bytes)
a0147d70:  9d e3 bf 78  save  %sp, -136, %sp
a0147d74:  7f ff 71 00  call  0xa0124174
a0147d78:  01 00 00 00  nop
a0147d7c:  ac 10 00 08  mov  %o0, %l6
a0147d80:  92 10 20 00  clr  %o1
a0147d84:  98 10 20 00  clr  %o4
a0147d88:  10 80 00 06  b  0xa0147da0
a0147d8c:  9a 10 20 00  clr  %o5
a0147d90:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0147d94:  80 a3 60 2c  cmp  %o5, 0x2c
a0147d98:  18 80 00 0f  bgu  0xa0147dd4
a0147d9c:  aa 0a 60 ff  and  %o1, 0xff, %l5
a0147da0:  c2 0b 40 16  ldub  [ %o5 + %l6 ], %g1
a0147da4:  80 a0 60 00  cmp  %g1, 0
a0147da8:  02 80 00 7f  be  0xa0147fa4
a0147dac:  80 a3 60 2c  cmp  %o5, 0x2c
a0147db0:  32 bf ff f8  bne,a   0xa0147d90
a0147db4:  98 03 20 01  inc  %o4
a0147db8:  92 10 00 0c  mov  %o4, %o1
a0147dbc:  98 03 20 01  inc  %o4
a0147dc0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0147dc4:  80 a3 60 2c  cmp  %o5, 0x2c
a0147dc8:  28 bf ff f7  bleu,a   0xa0147da4
a0147dcc:  c2 0b 40 16  ldub  [ %o5 + %l6 ], %g1
a0147dd0:  aa 0a 60 ff  and  %o1, 0xff, %l5
a0147dd4:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0147dd8:  90 12 22 50  or  %o0, 0x250, %o0	! 0x1a6e50
a0147ddc:  7f fe 5c e5  call  0xa00df170
a0147de0:  92 10 00 15  mov  %l5, %o1
a0147de4:  80 a5 60 27  cmp  %l5, 0x27
a0147de8:  18 80 00 71  bgu  0xa0147fac
a0147dec:  b0 10 20 05  mov  5, %i0
a0147df0:  13 33 c0 f1  sethi  %hi(0xcf03c400), %o1
a0147df4:  98 12 62 60  or  %o1, 0x260, %o4	! 0xcf03c660
a0147df8:  9a 10 20 5a  mov  0x5a, %o5
a0147dfc:  94 10 00 09  mov  %o1, %o2
a0147e00:  da 23 00 00  st  %o5, [ %o4 ]
a0147e04:  92 10 00 0c  mov  %o4, %o1
a0147e08:  d6 02 40 00  ld  [ %o1 ], %o3
a0147e0c:  80 a2 e0 5a  cmp  %o3, 0x5a
a0147e10:  02 bf ff fe  be  0xa0147e08
a0147e14:  a2 12 a2 78  or  %o2, 0x278, %l1
a0147e18:  d8 04 40 00  ld  [ %l1 ], %o4
a0147e1c:  9e 12 a2 74  or  %o2, 0x274, %o7
a0147e20:  d6 03 c0 00  ld  [ %o7 ], %o3
a0147e24:  9a 12 a2 70  or  %o2, 0x270, %o5
a0147e28:  f0 03 40 00  ld  [ %o5 ], %i0
a0147e2c:  a4 12 a2 6c  or  %o2, 0x26c, %l2
a0147e30:  83 2b 20 18  sll  %o4, 0x18, %g1
a0147e34:  91 2a e0 10  sll  %o3, 0x10, %o0
a0147e38:  de 04 80 00  ld  [ %l2 ], %o7
a0147e3c:  a0 10 20 5b  mov  0x5b, %l0
a0147e40:  a6 00 40 08  add  %g1, %o0, %l3
a0147e44:  a9 2e 20 08  sll  %i0, 8, %l4
a0147e48:  a2 04 c0 14  add  %l3, %l4, %l1
a0147e4c:  15 33 c0 f1  sethi  %hi(0xcf03c400), %o2
a0147e50:  e0 22 40 00  st  %l0, [ %o1 ]
a0147e54:  a0 04 40 0f  add  %l1, %o7, %l0
a0147e58:  9a 12 a2 60  or  %o2, 0x260, %o5
a0147e5c:  d2 03 40 00  ld  [ %o5 ], %o1
a0147e60:  80 a2 60 5b  cmp  %o1, 0x5b
a0147e64:  02 bf ff fe  be  0xa0147e5c
a0147e68:  92 12 a2 78  or  %o2, 0x278, %o1
a0147e6c:  da 02 40 00  ld  [ %o1 ], %o5
a0147e70:  a2 12 a2 74  or  %o2, 0x274, %l1
a0147e74:  de 04 40 00  ld  [ %l1 ], %o7
a0147e78:  98 12 a2 70  or  %o2, 0x270, %o4
a0147e7c:  d0 03 00 00  ld  [ %o4 ], %o0
a0147e80:  83 2b 60 18  sll  %o5, 0x18, %g1
a0147e84:  97 2b e0 10  sll  %o7, 0x10, %o3
a0147e88:  b1 2a 20 08  sll  %o0, 8, %i0
a0147e8c:  a8 00 40 0b  add  %g1, %o3, %l4
a0147e90:  a6 12 a2 6c  or  %o2, 0x26c, %l3
a0147e94:  a4 05 00 18  add  %l4, %i0, %l2
a0147e98:  d4 04 c0 00  ld  [ %l3 ], %o2
a0147e9c:  a6 04 80 0a  add  %l2, %o2, %l3
a0147ea0:  7f ff 35 e9  call  0xa0115644
a0147ea4:  90 10 20 01  mov  1, %o0
a0147ea8:  a3 34 20 05  srl  %l0, 5, %l1
a0147eac:  b0 10 20 00  clr  %i0
a0147eb0:  80 a6 00 11  cmp  %i0, %l1
a0147eb4:  1a 80 00 16  bcc  0xa0147f0c
a0147eb8:  a4 10 20 00  clr  %l2
a0147ebc:  a8 07 bf d8  add  %fp, -40, %l4
a0147ec0:  a0 07 bf f8  add  %fp, -8, %l0
a0147ec4:  90 10 00 14  mov  %l4, %o0
a0147ec8:  92 04 c0 18  add  %l3, %i0, %o1
a0147ecc:  94 10 20 01  mov  1, %o2
a0147ed0:  7f ff 30 5b  call  0xa011403c
a0147ed4:  96 10 20 00  clr  %o3
a0147ed8:  98 10 20 00  clr  %o4
a0147edc:  82 10 20 00  clr  %g1
a0147ee0:  90 04 00 01  add  %l0, %g1, %o0
a0147ee4:  98 03 20 01  inc  %o4
a0147ee8:  d4 0a 3f e0  ldub  [ %o0 + -32 ], %o2
a0147eec:  82 0b 20 ff  and  %o4, 0xff, %g1
a0147ef0:  80 a0 60 1f  cmp  %g1, 0x1f
a0147ef4:  08 bf ff fb  bleu  0xa0147ee0
a0147ef8:  a4 04 80 0a  add  %l2, %o2, %l2
a0147efc:  b0 06 20 01  inc  %i0
a0147f00:  80 a6 00 11  cmp  %i0, %l1
a0147f04:  2a bf ff f1  bcs,a   0xa0147ec8
a0147f08:  90 10 00 14  mov  %l4, %o0
a0147f0c:  95 2c a0 10  sll  %l2, 0x10, %o2
a0147f10:  13 00 06 9b  sethi  %hi(0x1a6c00), %o1
a0147f14:  a5 32 a0 10  srl  %o2, 0x10, %l2
a0147f18:  90 12 62 68  or  %o1, 0x268, %o0
a0147f1c:  7f fe 5c 95  call  0xa00df170
a0147f20:  92 10 00 12  mov  %l2, %o1
a0147f24:  7f ff 35 c8  call  0xa0115644
a0147f28:  90 10 20 00  clr  %o0
a0147f2c:  a2 05 40 16  add  %l5, %l6, %l1
a0147f30:  7f ff 6f 47  call  0xa0123c4c
a0147f34:  d0 0c 7f f8  ldub  [ %l1 + -8 ], %o0
a0147f38:  98 0a 20 ff  and  %o0, 0xff, %o4
a0147f3c:  ad 2b 20 0c  sll  %o4, 0xc, %l6
a0147f40:  7f ff 6f 43  call  0xa0123c4c
a0147f44:  d0 0c 7f f9  ldub  [ %l1 + -7 ], %o0
a0147f48:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0147f4c:  9f 2b 60 08  sll  %o5, 8, %o7
a0147f50:  aa 15 80 0f  or  %l6, %o7, %l5
a0147f54:  7f ff 6f 3e  call  0xa0123c4c
a0147f58:  d0 0c 7f fa  ldub  [ %l1 + -6 ], %o0
a0147f5c:  96 0a 20 ff  and  %o0, 0xff, %o3
a0147f60:  83 2a e0 04  sll  %o3, 4, %g1
a0147f64:  a8 15 40 01  or  %l5, %g1, %l4
a0147f68:  7f ff 6f 39  call  0xa0123c4c
a0147f6c:  d0 0c 7f fb  ldub  [ %l1 + -5 ], %o0
a0147f70:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0147f74:  a6 15 00 18  or  %l4, %i0, %l3
a0147f78:  a1 2c e0 10  sll  %l3, 0x10, %l0
a0147f7c:  ab 34 20 10  srl  %l0, 0x10, %l5
a0147f80:  2d 00 06 9b  sethi  %hi(0x1a6c00), %l6
a0147f84:  90 15 a2 78  or  %l6, 0x278, %o0	! 0x1a6e78
a0147f88:  7f fe 5c 7a  call  0xa00df170
a0147f8c:  92 10 00 15  mov  %l5, %o1
a0147f90:  80 a4 80 15  cmp  %l2, %l5
a0147f94:  02 80 00 06  be  0xa0147fac
a0147f98:  b0 10 20 02  mov  2, %i0
a0147f9c:  10 80 00 04  b  0xa0147fac
a0147fa0:  b0 10 20 03  mov  3, %i0
a0147fa4:  10 bf ff 8b  b  0xa0147dd0
a0147fa8:  92 10 00 0c  mov  %o4, %o1
a0147fac:  81 c7 e0 08  ret
a0147fb0:  81 e8 00 00  restore
