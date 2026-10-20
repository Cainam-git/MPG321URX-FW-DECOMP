# leon2s FUN_a0061d60 0xa0061d60-0xa0061eb4 (340 bytes)
a0061d60:  9d e3 bf 98  save  %sp, -104, %sp
a0061d64:  a2 10 20 00  clr  %l1
a0061d68:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0061d6c:  d2 10 62 70  lduh  [ %g1 + 0x270 ], %o1	! 0xa8076270
a0061d70:  82 0c 60 ff  and  %l1, 0xff, %g1
a0061d74:  92 02 40 01  add  %o1, %g1, %o1
a0061d78:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0061d7c:  ac 10 62 40  or  %g1, 0x240, %l6	! 0xa8078a40
a0061d80:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0061d84:  da 00 61 74  ld  [ %g1 + 0x174 ], %o5	! 0xa807cd74
a0061d88:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0061d8c:  93 2a 60 10  sll  %o1, 0x10, %o1
a0061d90:  d0 08 62 38  ldub  [ %g1 + 0x238 ], %o0
a0061d94:  a0 0c 60 ff  and  %l1, 0xff, %l0
a0061d98:  9f c3 40 00  call  %o5
a0061d9c:  93 32 60 10  srl  %o1, 0x10, %o1
a0061da0:  a2 04 60 01  inc  %l1
a0061da4:  82 0c 60 ff  and  %l1, 0xff, %g1
a0061da8:  80 a0 60 1a  cmp  %g1, 0x1a
a0061dac:  08 bf ff ef  bleu  0xa0061d68
a0061db0:  d0 2d 80 10  stb  %o0, [ %l6 + %l0 ]
a0061db4:  d8 0d a0 10  ldub  [ %l6 + 0x10 ], %o4
a0061db8:  9a 0b 20 03  and  %o4, 3, %o5
a0061dbc:  ea 0d a0 0f  ldub  [ %l6 + 0xf ], %l5
a0061dc0:  c2 0d a0 11  ldub  [ %l6 + 0x11 ], %g1
a0061dc4:  9b 2b 60 06  sll  %o5, 6, %o5
a0061dc8:  a8 0d 60 0f  and  %l5, 0xf, %l4
a0061dcc:  9a 13 40 01  or  %o5, %g1, %o5
a0061dd0:  d6 0d a0 04  ldub  [ %l6 + 4 ], %o3
a0061dd4:  98 0b 20 fc  and  %o4, 0xfc, %o4
a0061dd8:  96 0a e0 3e  and  %o3, 0x3e, %o3
a0061ddc:  a9 2d 20 06  sll  %l4, 6, %l4
a0061de0:  d4 0d a0 06  ldub  [ %l6 + 6 ], %o2
a0061de4:  e2 0d a0 0c  ldub  [ %l6 + 0xc ], %l1
a0061de8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0061dec:  82 10 62 a0  or  %g1, 0x2a0, %g1	! 0xa8078aa0
a0061df0:  a8 15 00 0c  or  %l4, %o4, %l4
a0061df4:  97 2a e0 04  sll  %o3, 4, %o3
a0061df8:  95 2a a0 04  sll  %o2, 4, %o2
a0061dfc:  a3 2c 60 04  sll  %l1, 4, %l1
a0061e00:  d2 0d a0 07  ldub  [ %l6 + 7 ], %o1
a0061e04:  d0 0d a0 09  ldub  [ %l6 + 9 ], %o0
a0061e08:  de 0d a0 0a  ldub  [ %l6 + 0xa ], %o7
a0061e0c:  e0 0d a0 0b  ldub  [ %l6 + 0xb ], %l0
a0061e10:  e4 0d a0 0d  ldub  [ %l6 + 0xd ], %l2
a0061e14:  e6 0d a0 0e  ldub  [ %l6 + 0xe ], %l3
a0061e18:  93 2a 60 04  sll  %o1, 4, %o1
a0061e1c:  91 2a 20 04  sll  %o0, 4, %o0
a0061e20:  9f 2b e0 04  sll  %o7, 4, %o7
a0061e24:  a1 2c 20 04  sll  %l0, 4, %l0
a0061e28:  a5 2c a0 04  sll  %l2, 4, %l2
a0061e2c:  a7 2c e0 04  sll  %l3, 4, %l3
a0061e30:  9b 2b 60 02  sll  %o5, 2, %o5
a0061e34:  d8 0d a0 08  ldub  [ %l6 + 8 ], %o4
a0061e38:  ab 35 60 04  srl  %l5, 4, %l5
a0061e3c:  d6 30 60 88  sth  %o3, [ %g1 + 0x88 ]
a0061e40:  d4 30 60 08  sth  %o2, [ %g1 + 8 ]
a0061e44:  e2 30 60 14  sth  %l1, [ %g1 + 0x14 ]
a0061e48:  d2 30 60 0a  sth  %o1, [ %g1 + 0xa ]
a0061e4c:  d8 30 60 0c  sth  %o4, [ %g1 + 0xc ]
a0061e50:  d0 30 60 0e  sth  %o0, [ %g1 + 0xe ]
a0061e54:  de 30 60 10  sth  %o7, [ %g1 + 0x10 ]
a0061e58:  e0 30 60 12  sth  %l0, [ %g1 + 0x12 ]
a0061e5c:  e4 30 60 16  sth  %l2, [ %g1 + 0x16 ]
a0061e60:  e6 30 60 18  sth  %l3, [ %g1 + 0x18 ]
a0061e64:  ea 28 60 58  stb  %l5, [ %g1 + 0x58 ]
a0061e68:  e8 30 60 02  sth  %l4, [ %g1 + 2 ]
a0061e6c:  da 30 60 04  sth  %o5, [ %g1 + 4 ]
a0061e70:  96 10 00 01  mov  %g1, %o3
a0061e74:  94 10 00 16  mov  %l6, %o2
a0061e78:  a2 10 20 00  clr  %l1
a0061e7c:  9a 0c 60 ff  and  %l1, 0xff, %o5
a0061e80:  82 03 40 0a  add  %o5, %o2, %g1
a0061e84:  c2 08 60 12  ldub  [ %g1 + 0x12 ], %g1
a0061e88:  9a 03 40 0d  add  %o5, %o5, %o5
a0061e8c:  a2 04 60 01  inc  %l1
a0061e90:  9a 03 40 0b  add  %o5, %o3, %o5
a0061e94:  83 28 60 02  sll  %g1, 2, %g1
a0061e98:  98 0c 60 ff  and  %l1, 0xff, %o4
a0061e9c:  80 a3 20 08  cmp  %o4, 8
a0061ea0:  08 bf ff f7  bleu  0xa0061e7c
a0061ea4:  c2 33 60 5a  sth  %g1, [ %o5 + 0x5a ]
a0061ea8:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a0061eac:  81 c7 e0 08  ret
a0061eb0:  81 e8 00 00  restore
