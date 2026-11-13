# leon2m FUN_a0140e74 0xa0140e74-0xa01410a4 (560 bytes)
a0140e74:  9d e3 bf 78  save  %sp, -136, %sp
a0140e78:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0140e7c:  11 00 06 9a  sethi  %hi(0x1a6800), %o0
a0140e80:  82 12 21 fe  or  %o0, 0x1fe, %g1	! 0x1a69fe
a0140e84:  98 5e 20 26  smul  %i0, 0x26, %o4
a0140e88:  da 48 40 0c  ldsb  [ %g1 + %o4 ], %o5
a0140e8c:  80 a3 60 00  cmp  %o5, 0
a0140e90:  a2 10 00 19  mov  %i1, %l1
a0140e94:  06 80 00 5b  bl  0xa0141000
a0140e98:  e0 08 40 0c  ldub  [ %g1 + %o4 ], %l0
a0140e9c:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0140ea0:  98 06 00 18  add  %i0, %i0, %o4
a0140ea4:  29 00 06 9a  sethi  %hi(0x1a6800), %l4
a0140ea8:  a0 03 00 18  add  %o4, %i0, %l0
a0140eac:  a4 15 21 d6  or  %l4, 0x1d6, %l2
a0140eb0:  9e 04 00 12  add  %l0, %l2, %o7
a0140eb4:  e6 0b e0 02  ldub  [ %o7 + 2 ], %l3
a0140eb8:  b8 38 00 13  xnor  %g0, %l3, %i4
a0140ebc:  d0 0c 80 10  ldub  [ %l2 + %l0 ], %o0
a0140ec0:  d2 0b e0 01  ldub  [ %o7 + 1 ], %o1
a0140ec4:  67 fd 2e 6a  call  0x4008c86c
a0140ec8:  94 0f 20 ff  and  %i4, 0xff, %o2
a0140ecc:  99 2e a0 10  sll  %i2, 0x10, %o4
a0140ed0:  97 33 20 10  srl  %o4, 0x10, %o3
a0140ed4:  80 a2 e0 00  cmp  %o3, 0
a0140ed8:  02 80 00 2d  be  0xa0140f8c
a0140edc:  9b 2e 20 02  sll  %i0, 2, %o5
a0140ee0:  33 00 06 9a  sethi  %hi(0x1a6800), %i1
a0140ee4:  82 03 40 18  add  %o5, %i0, %g1
a0140ee8:  a4 16 61 e0  or  %i1, 0x1e0, %l2
a0140eec:  a0 00 40 01  add  %g1, %g1, %l0
a0140ef0:  b8 04 00 12  add  %l0, %l2, %i4
a0140ef4:  94 10 00 0c  mov  %o4, %o2
a0140ef8:  a6 10 00 0b  mov  %o3, %l3
a0140efc:  b2 10 00 1c  mov  %i4, %i1
a0140f00:  9f 32 a0 10  srl  %o2, 0x10, %o7
a0140f04:  80 a3 e0 10  cmp  %o7, 0x10
a0140f08:  28 80 00 2a  bleu,a   0xa0140fb0
a0140f0c:  d2 17 20 08  lduh  [ %i4 + 8 ], %o1
a0140f10:  d8 17 20 02  lduh  [ %i4 + 2 ], %o4
a0140f14:  d4 17 20 06  lduh  [ %i4 + 6 ], %o2
a0140f18:  d0 17 20 08  lduh  [ %i4 + 8 ], %o0
a0140f1c:  96 24 c0 0f  sub  %l3, %o7, %o3
a0140f20:  c2 14 80 10  lduh  [ %l2 + %l0 ], %g1
a0140f24:  de 17 20 04  lduh  [ %i4 + 4 ], %o7
a0140f28:  93 2c 60 10  sll  %l1, 0x10, %o1
a0140f2c:  d8 37 bf ea  sth  %o4, [ %fp + -22 ]
a0140f30:  d4 37 bf ee  sth  %o2, [ %fp + -18 ]
a0140f34:  d0 37 bf f0  sth  %o0, [ %fp + -16 ]
a0140f38:  c2 37 bf e8  sth  %g1, [ %fp + -24 ]
a0140f3c:  de 37 bf ec  sth  %o7, [ %fp + -20 ]
a0140f40:  93 32 60 10  srl  %o1, 0x10, %o1
a0140f44:  96 02 c0 1b  add  %o3, %i3, %o3
a0140f48:  90 07 bf e8  add  %fp, -24, %o0
a0140f4c:  94 10 20 10  mov  0x10, %o2
a0140f50:  98 10 20 01  mov  1, %o4
a0140f54:  67 fd 29 24  call  0x4008b3e4
a0140f58:  9a 10 20 01  mov  1, %o5
a0140f5c:  a2 04 60 10  add  %l1, 0x10, %l1
a0140f60:  b4 06 bf f0  add  %i2, -16, %i2
a0140f64:  67 fd 30 8f  call  0x4008d1a0
a0140f68:  90 10 20 07  mov  7, %o0
a0140f6c:  67 fd 2b c4  call  0x4008be7c
a0140f70:  d0 0e 60 06  ldub  [ %i1 + 6 ], %o0
a0140f74:  80 8a 20 ff  btst  0xff, %o0
a0140f78:  02 bf ff fd  be  0xa0140f6c
a0140f7c:  95 2e a0 10  sll  %i2, 0x10, %o2
a0140f80:  80 a2 a0 00  cmp  %o2, 0
a0140f84:  12 bf ff e0  bne  0xa0140f04
a0140f88:  9f 32 a0 10  srl  %o2, 0x10, %o7
a0140f8c:  b8 06 00 18  add  %i0, %i0, %i4
a0140f90:  b6 07 00 18  add  %i4, %i0, %i3
a0140f94:  a2 15 21 d6  or  %l4, 0x1d6, %l1
a0140f98:  b0 06 c0 11  add  %i3, %l1, %i0
a0140f9c:  d0 0c 40 1b  ldub  [ %l1 + %i3 ], %o0
a0140fa0:  d4 0e 20 02  ldub  [ %i0 + 2 ], %o2
a0140fa4:  67 fd 2e 32  call  0x4008c86c
a0140fa8:  d2 0e 20 01  ldub  [ %i0 + 1 ], %o1
a0140fac:  30 80 00 3c  b,a   0xa014109c
a0140fb0:  d8 14 80 10  lduh  [ %l2 + %l0 ], %o4
a0140fb4:  da 17 20 02  lduh  [ %i4 + 2 ], %o5
a0140fb8:  d4 17 20 04  lduh  [ %i4 + 4 ], %o2
a0140fbc:  d0 17 20 06  lduh  [ %i4 + 6 ], %o0
a0140fc0:  97 2c 60 10  sll  %l1, 0x10, %o3
a0140fc4:  d2 37 bf e0  sth  %o1, [ %fp + -32 ]
a0140fc8:  b4 24 c0 0f  sub  %l3, %o7, %i2
a0140fcc:  d8 37 bf d8  sth  %o4, [ %fp + -40 ]
a0140fd0:  da 37 bf da  sth  %o5, [ %fp + -38 ]
a0140fd4:  d4 37 bf dc  sth  %o2, [ %fp + -36 ]
a0140fd8:  d0 37 bf de  sth  %o0, [ %fp + -34 ]
a0140fdc:  93 32 e0 10  srl  %o3, 0x10, %o1
a0140fe0:  96 06 80 1b  add  %i2, %i3, %o3
a0140fe4:  94 10 00 0f  mov  %o7, %o2
a0140fe8:  90 07 bf d8  add  %fp, -40, %o0
a0140fec:  98 10 20 01  mov  1, %o4
a0140ff0:  67 fd 28 fd  call  0x4008b3e4
a0140ff4:  9a 10 20 01  mov  1, %o5
a0140ff8:  10 bf ff db  b  0xa0140f64
a0140ffc:  b4 10 20 00  clr  %i2
a0141000:  a6 0c 20 ff  and  %l0, 0xff, %l3
a0141004:  90 10 00 18  mov  %i0, %o0
a0141008:  7f ff fe dc  call  0xa0140b78
a014100c:  a5 2c e0 03  sll  %l3, 3, %l2
a0141010:  a2 04 80 13  add  %l2, %l3, %l1
a0141014:  21 00 06 9a  sethi  %hi(0x1a6800), %l0
a0141018:  97 2c 60 02  sll  %l1, 2, %o3
a014101c:  9e 14 22 24  or  %l0, 0x224, %o7
a0141020:  94 02 c0 0f  add  %o3, %o7, %o2
a0141024:  d2 0a a0 02  ldub  [ %o2 + 2 ], %o1
a0141028:  80 a2 60 01  cmp  %o1, 1
a014102c:  02 80 00 17  be  0xa0141088
a0141030:  90 10 20 00  clr  %o0
a0141034:  97 2a 20 10  sll  %o0, 0x10, %o3
a0141038:  95 32 e0 10  srl  %o3, 0x10, %o2
a014103c:  92 06 40 0a  add  %i1, %o2, %o1
a0141040:  9b 2e a0 10  sll  %i2, 0x10, %o5
a0141044:  91 2a 60 10  sll  %o1, 0x10, %o0
a0141048:  91 32 20 10  srl  %o0, 0x10, %o0
a014104c:  93 33 60 10  srl  %o5, 0x10, %o1
a0141050:  7f ff d2 0f  call  0xa013588c
a0141054:  94 10 00 1b  mov  %i3, %o2
a0141058:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a014105c:  b4 10 20 01  mov  1, %i2
a0141060:  67 fd 31 4a  call  0x4008d588
a0141064:  f4 2c 23 d9  stb  %i2, [ %l0 + 0x3d9 ]
a0141068:  33 2a 00 b3  sethi  %hi(0xa802cc00), %i1
a014106c:  80 8f 20 ff  btst  0xff, %i4
a0141070:  02 80 00 0b  be  0xa014109c
a0141074:  d0 36 60 04  sth  %o0, [ %i1 + 4 ]
a0141078:  7f ff fd 56  call  0xa01405d0
a014107c:  90 10 00 18  mov  %i0, %o0
a0141080:  10 80 00 07  b  0xa014109c
a0141084:  c0 2c 23 d9  clrb  [ %l0 + 0x3d9 ]
a0141088:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a014108c:  a9 2e 20 02  sll  %i0, 2, %l4
a0141090:  98 10 60 00  mov  %g1, %o4
a0141094:  10 bf ff e8  b  0xa0141034
a0141098:  d0 13 00 14  lduh  [ %o4 + %l4 ], %o0
a014109c:  81 c7 e0 08  ret
a01410a0:  81 e8 00 00  restore
