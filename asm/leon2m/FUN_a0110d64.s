# leon2m FUN_a0110d64 0xa0110d64-0xa0110f44 (480 bytes)
a0110d64:  9d e3 bf 98  save  %sp, -104, %sp
a0110d68:  17 34 00 c1  sethi  %hi(0xd0030400), %o3
a0110d6c:  de 0e 20 02  ldub  [ %i0 + 2 ], %o7
a0110d70:  94 12 e0 04  or  %o3, 4, %o2
a0110d74:  de 22 80 00  st  %o7, [ %o2 ]
a0110d78:  15 34 00 e1  sethi  %hi(0xd0038400), %o2
a0110d7c:  da 0e 20 02  ldub  [ %i0 + 2 ], %o5
a0110d80:  92 12 a0 04  or  %o2, 4, %o1
a0110d84:  da 22 40 00  st  %o5, [ %o1 ]
a0110d88:  98 10 20 14  mov  0x14, %o4
a0110d8c:  90 12 e0 10  or  %o3, 0x10, %o0
a0110d90:  d8 22 00 00  st  %o4, [ %o0 ]
a0110d94:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0110d98:  82 12 a0 10  or  %o2, 0x10, %g1
a0110d9c:  d8 20 40 00  st  %o4, [ %g1 ]
a0110da0:  80 a6 60 01  cmp  %i1, 1
a0110da4:  22 80 00 2c  be,a   0xa0110e54
a0110da8:  82 12 e0 20  or  %o3, 0x20, %g1
a0110dac:  04 80 00 5b  ble  0xa0110f18
a0110db0:  80 a6 60 02  cmp  %i1, 2
a0110db4:  02 80 00 45  be  0xa0110ec8
a0110db8:  80 a6 60 03  cmp  %i1, 3
a0110dbc:  02 80 00 5d  be  0xa0110f30
a0110dc0:  23 2a 00 9e  sethi  %hi(0xa8027800), %l1
a0110dc4:  e0 0c 62 88  ldub  [ %l1 + 0x288 ], %l0	! 0xa8027a88
a0110dc8:  80 a4 20 01  cmp  %l0, 1
a0110dcc:  22 80 00 2c  be,a   0xa0110e7c
a0110dd0:  b2 10 20 40  mov  0x40, %i1
a0110dd4:  da 16 00 00  lduh  [ %i0 ], %o5
a0110dd8:  95 33 60 02  srl  %o5, 2, %o2
a0110ddc:  96 10 20 00  clr  %o3
a0110de0:  80 a2 c0 0a  cmp  %o3, %o2
a0110de4:  1a 80 00 0f  bcc  0xa0110e20
a0110de8:  21 34 00 c1  sethi  %hi(0xd0030400), %l0
a0110dec:  1f 34 00 e1  sethi  %hi(0xd0038400), %o7
a0110df0:  f0 06 20 04  ld  [ %i0 + 4 ], %i0
a0110df4:  90 14 20 08  or  %l0, 8, %o0
a0110df8:  92 13 e0 08  or  %o7, 8, %o1
a0110dfc:  83 2a e0 02  sll  %o3, 2, %g1
a0110e00:  d8 06 00 01  ld  [ %i0 + %g1 ], %o4
a0110e04:  d8 22 00 00  st  %o4, [ %o0 ]
a0110e08:  f2 06 00 01  ld  [ %i0 + %g1 ], %i1
a0110e0c:  96 02 e0 01  inc  %o3
a0110e10:  f2 22 40 00  st  %i1, [ %o1 ]
a0110e14:  80 a2 c0 0a  cmp  %o3, %o2
a0110e18:  0a bf ff fa  bcs  0xa0110e00
a0110e1c:  83 2a e0 02  sll  %o3, 2, %g1
a0110e20:  13 34 00 c1  sethi  %hi(0xd0030400), %o1
a0110e24:  15 0c 84 00  sethi  %hi(0x32100000), %o2
a0110e28:  90 12 60 20  or  %o1, 0x20, %o0
a0110e2c:  d4 22 00 00  st  %o2, [ %o0 ]
a0110e30:  f0 0c 62 88  ldub  [ %l1 + 0x288 ], %i0
a0110e34:  17 34 00 e1  sethi  %hi(0xd0038400), %o3
a0110e38:  a2 12 e0 20  or  %o3, 0x20, %l1	! 0xd0038420
a0110e3c:  d4 24 40 00  st  %o2, [ %l1 ]
a0110e40:  80 a6 20 01  cmp  %i0, 1
a0110e44:  12 80 00 3e  bne  0xa0110f3c
a0110e48:  9a 10 20 40  mov  0x40, %o5
a0110e4c:  10 80 00 22  b  0xa0110ed4
a0110e50:  21 34 00 ec  sethi  %hi(0xd003b000), %l0
a0110e54:  19 04 0c 80  sethi  %hi(0x10320000), %o4
a0110e58:  d8 20 40 00  st  %o4, [ %g1 ]
a0110e5c:  96 12 a0 20  or  %o2, 0x20, %o3
a0110e60:  d8 22 c0 00  st  %o4, [ %o3 ]
a0110e64:  23 2a 00 9e  sethi  %hi(0xa8027800), %l1
a0110e68:  e0 0c 62 88  ldub  [ %l1 + 0x288 ], %l0	! 0xa8027a88
a0110e6c:  80 a4 20 01  cmp  %l0, 1
a0110e70:  32 bf ff da  bne,a   0xa0110dd8
a0110e74:  da 16 00 00  lduh  [ %i0 ], %o5
a0110e78:  b2 10 20 40  mov  0x40, %i1
a0110e7c:  21 34 00 ec  sethi  %hi(0xd003b000), %l0
a0110e80:  f2 24 00 00  st  %i1, [ %l0 ]
a0110e84:  67 fd f1 c1  call  0x4008d588
a0110e88:  01 00 00 00  nop
a0110e8c:  b2 10 00 08  mov  %o0, %i1
a0110e90:  c2 04 00 00  ld  [ %l0 ], %g1
a0110e94:  80 a0 60 00  cmp  %g1, 0
a0110e98:  22 bf ff d0  be,a   0xa0110dd8
a0110e9c:  da 16 00 00  lduh  [ %i0 ], %o5
a0110ea0:  67 fd f1 ba  call  0x4008d588
a0110ea4:  01 00 00 00  nop
a0110ea8:  92 22 00 19  sub  %o0, %i1, %o1
a0110eac:  91 2a 60 10  sll  %o1, 0x10, %o0
a0110eb0:  99 32 20 10  srl  %o0, 0x10, %o4
a0110eb4:  80 a3 20 63  cmp  %o4, 0x63
a0110eb8:  08 bf ff f6  bleu  0xa0110e90
a0110ebc:  01 00 00 00  nop
a0110ec0:  10 bf ff c6  b  0xa0110dd8
a0110ec4:  da 16 00 00  lduh  [ %i0 ], %o5
a0110ec8:  82 12 e0 20  or  %o3, 0x20, %g1
a0110ecc:  10 bf ff e3  b  0xa0110e58
a0110ed0:  19 08 40 c0  sethi  %hi(0x21030000), %o4
a0110ed4:  da 24 00 00  st  %o5, [ %l0 ]
a0110ed8:  67 fd f1 ac  call  0x4008d588
a0110edc:  01 00 00 00  nop
a0110ee0:  b2 10 00 08  mov  %o0, %i1
a0110ee4:  de 04 00 00  ld  [ %l0 ], %o7
a0110ee8:  80 a3 e0 00  cmp  %o7, 0
a0110eec:  02 80 00 14  be  0xa0110f3c
a0110ef0:  01 00 00 00  nop
a0110ef4:  67 fd f1 a5  call  0x4008d588
a0110ef8:  01 00 00 00  nop
a0110efc:  b0 22 00 19  sub  %o0, %i1, %i0
a0110f00:  99 2e 20 10  sll  %i0, 0x10, %o4
a0110f04:  83 33 20 10  srl  %o4, 0x10, %g1
a0110f08:  80 a0 60 63  cmp  %g1, 0x63
a0110f0c:  08 bf ff f6  bleu  0xa0110ee4
a0110f10:  01 00 00 00  nop
a0110f14:  30 80 00 0a  b,a   0xa0110f3c
a0110f18:  82 12 e0 20  or  %o3, 0x20, %g1
a0110f1c:  80 a6 60 00  cmp  %i1, 0
a0110f20:  02 bf ff ce  be  0xa0110e58
a0110f24:  19 00 c8 40  sethi  %hi(0x3210000), %o4
a0110f28:  10 bf ff a7  b  0xa0110dc4
a0110f2c:  23 2a 00 9e  sethi  %hi(0xa8027800), %l1
a0110f30:  82 12 e0 20  or  %o3, 0x20, %g1
a0110f34:  10 bf ff c9  b  0xa0110e58
a0110f38:  19 0c 84 00  sethi  %hi(0x32100000), %o4
a0110f3c:  81 c7 e0 08  ret
a0110f40:  81 e8 00 00  restore
