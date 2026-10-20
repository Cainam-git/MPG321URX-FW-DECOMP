# leon2m FUN_a00f9f10 0xa00f9f10-0xa00fa560 (1616 bytes)
a00f9f10:  9d e3 bf 98  save  %sp, -104, %sp
a00f9f14:  33 34 01 00  sethi  %hi(0xd0040000), %i1
a00f9f18:  82 16 60 98  or  %i1, 0x98, %g1	! 0xd0040098
a00f9f1c:  f0 00 40 00  ld  [ %g1 ], %i0
a00f9f20:  bb 2e 20 10  sll  %i0, 0x10, %i5
a00f9f24:  bb 37 60 1c  srl  %i5, 0x1c, %i5
a00f9f28:  80 a7 60 03  cmp  %i5, 3
a00f9f2c:  02 80 00 06  be  0xa00f9f44
a00f9f30:  80 a7 60 04  cmp  %i5, 4
a00f9f34:  12 80 01 89  bne  0xa00fa558
a00f9f38:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a00f9f3c:  10 80 00 c6  b  0xa00fa254
a00f9f40:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa802c864
a00f9f44:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a00f9f48:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa802c864
a00f9f4c:  3b 2a 00 9b  sethi  %hi(0xa8026c00), %i5
a00f9f50:  ba 17 62 d6  or  %i5, 0x2d6, %i5	! 0xa8026ed6
a00f9f54:  f0 10 60 18  lduh  [ %g1 + 0x18 ], %i0
a00f9f58:  f8 10 60 10  lduh  [ %g1 + 0x10 ], %i4
a00f9f5c:  f6 10 60 12  lduh  [ %g1 + 0x12 ], %i3
a00f9f60:  f4 10 60 14  lduh  [ %g1 + 0x14 ], %i2
a00f9f64:  f2 10 60 16  lduh  [ %g1 + 0x16 ], %i1
a00f9f68:  de 10 60 20  lduh  [ %g1 + 0x20 ], %o7
a00f9f6c:  da 10 60 22  lduh  [ %g1 + 0x22 ], %o5
a00f9f70:  d8 10 60 24  lduh  [ %g1 + 0x24 ], %o4
a00f9f74:  d6 10 60 26  lduh  [ %g1 + 0x26 ], %o3
a00f9f78:  d4 10 60 28  lduh  [ %g1 + 0x28 ], %o2
a00f9f7c:  d2 10 60 30  lduh  [ %g1 + 0x30 ], %o1
a00f9f80:  d0 10 60 32  lduh  [ %g1 + 0x32 ], %o0
a00f9f84:  e0 10 60 34  lduh  [ %g1 + 0x34 ], %l0
a00f9f88:  e2 10 60 36  lduh  [ %g1 + 0x36 ], %l1
a00f9f8c:  e4 10 60 38  lduh  [ %g1 + 0x38 ], %l2
a00f9f90:  e6 10 60 40  lduh  [ %g1 + 0x40 ], %l3
a00f9f94:  f0 37 60 1c  sth  %i0, [ %i5 + 0x1c ]
a00f9f98:  f8 37 60 04  sth  %i4, [ %i5 + 4 ]
a00f9f9c:  f6 37 60 0a  sth  %i3, [ %i5 + 0xa ]
a00f9fa0:  f4 37 60 10  sth  %i2, [ %i5 + 0x10 ]
a00f9fa4:  f2 37 60 16  sth  %i1, [ %i5 + 0x16 ]
a00f9fa8:  de 37 60 ae  sth  %o7, [ %i5 + 0xae ]
a00f9fac:  da 37 60 b4  sth  %o5, [ %i5 + 0xb4 ]
a00f9fb0:  d8 37 60 ba  sth  %o4, [ %i5 + 0xba ]
a00f9fb4:  d6 37 60 c0  sth  %o3, [ %i5 + 0xc0 ]
a00f9fb8:  d4 37 60 c6  sth  %o2, [ %i5 + 0xc6 ]
a00f9fbc:  d2 37 61 58  sth  %o1, [ %i5 + 0x158 ]
a00f9fc0:  d0 37 61 5e  sth  %o0, [ %i5 + 0x15e ]
a00f9fc4:  e0 37 61 64  sth  %l0, [ %i5 + 0x164 ]
a00f9fc8:  e2 37 61 6a  sth  %l1, [ %i5 + 0x16a ]
a00f9fcc:  e4 37 61 70  sth  %l2, [ %i5 + 0x170 ]
a00f9fd0:  e6 37 62 02  sth  %l3, [ %i5 + 0x202 ]
a00f9fd4:  f0 10 60 42  lduh  [ %g1 + 0x42 ], %i0
a00f9fd8:  f0 37 62 08  sth  %i0, [ %i5 + 0x208 ]
a00f9fdc:  f4 10 60 48  lduh  [ %g1 + 0x48 ], %i2
a00f9fe0:  f8 10 60 44  lduh  [ %g1 + 0x44 ], %i4
a00f9fe4:  f6 10 60 46  lduh  [ %g1 + 0x46 ], %i3
a00f9fe8:  f8 37 62 0e  sth  %i4, [ %i5 + 0x20e ]
a00f9fec:  f6 37 62 14  sth  %i3, [ %i5 + 0x214 ]
a00f9ff0:  f4 37 62 1a  sth  %i2, [ %i5 + 0x21a ]
a00f9ff4:  b6 10 20 00  clr  %i3
a00f9ff8:  b8 10 20 00  clr  %i4
a00f9ffc:  b4 10 24 00  mov  0x400, %i2
a00fa000:  b1 2f 20 04  sll  %i4, 4, %i0
a00fa004:  82 06 00 1c  add  %i0, %i4, %g1
a00fa008:  b2 00 40 01  add  %g1, %g1, %i1
a00fa00c:  b6 06 e0 01  inc  %i3
a00fa010:  b0 06 40 1d  add  %i1, %i5, %i0
a00fa014:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00fa018:  80 a7 20 0f  cmp  %i4, 0xf
a00fa01c:  08 bf ff f9  bleu  0xa00fa000
a00fa020:  f4 36 20 20  sth  %i2, [ %i0 + 0x20 ]
a00fa024:  35 2a 00 9b  sethi  %hi(0xa8026c00), %i2
a00fa028:  94 16 a2 d6  or  %i2, 0x2d6, %o2	! 0xa8026ed6
a00fa02c:  92 10 20 02  mov  2, %o1
a00fa030:  96 10 20 02  mov  2, %o3
a00fa034:  98 10 20 00  clr  %o4
a00fa038:  b2 10 20 00  clr  %i1
a00fa03c:  b9 2e 60 04  sll  %i1, 4, %i4
a00fa040:  b0 07 00 19  add  %i4, %i1, %i0
a00fa044:  ba 06 00 0b  add  %i0, %o3, %i5
a00fa048:  b4 07 40 1d  add  %i5, %i5, %i2
a00fa04c:  fa 12 80 1a  lduh  [ %o2 + %i2 ], %i5
a00fa050:  b3 2f 60 03  sll  %i5, 3, %i1
a00fa054:  82 07 40 1d  add  %i5, %i5, %g1
a00fa058:  b8 06 40 1d  add  %i1, %i5, %i4
a00fa05c:  82 00 40 1d  add  %g1, %i5, %g1
a00fa060:  b4 06 80 0a  add  %i2, %o2, %i2
a00fa064:  b7 2f 20 04  sll  %i4, 4, %i3
a00fa068:  b1 28 60 04  sll  %g1, 4, %i0
a00fa06c:  f2 16 a0 aa  lduh  [ %i2 + 0xaa ], %i1
a00fa070:  b8 07 00 1b  add  %i4, %i3, %i4
a00fa074:  82 00 40 18  add  %g1, %i0, %g1
a00fa078:  b0 5e 60 34  smul  %i1, 0x34, %i0
a00fa07c:  9a 5e 60 cd  smul  %i1, 0xcd, %o5
a00fa080:  b6 5f 60 cc  smul  %i5, 0xcc, %i3
a00fa084:  9e 5e 60 67  smul  %i1, 0x67, %o7
a00fa088:  b2 5e 60 9a  smul  %i1, 0x9a, %i1
a00fa08c:  b6 06 c0 18  add  %i3, %i0, %i3
a00fa090:  ba 5f 60 66  smul  %i5, 0x66, %i5
a00fa094:  ba 07 40 19  add  %i5, %i1, %i5
a00fa098:  b0 07 00 0f  add  %i4, %o7, %i0
a00fa09c:  82 00 40 0d  add  %g1, %o5, %g1
a00fa0a0:  b8 06 20 80  add  %i0, 0x80, %i4
a00fa0a4:  b2 00 60 80  add  %g1, 0x80, %i1
a00fa0a8:  83 36 60 08  srl  %i1, 8, %g1
a00fa0ac:  b6 06 e0 80  add  %i3, 0x80, %i3
a00fa0b0:  b0 07 60 80  add  %i5, 0x80, %i0
a00fa0b4:  98 03 20 05  add  %o4, 5, %o4
a00fa0b8:  b7 36 e0 08  srl  %i3, 8, %i3
a00fa0bc:  b9 37 20 08  srl  %i4, 8, %i4
a00fa0c0:  bb 36 20 08  srl  %i0, 8, %i5
a00fa0c4:  b2 0b 20 ff  and  %o4, 0xff, %i1
a00fa0c8:  c2 36 a0 88  sth  %g1, [ %i2 + 0x88 ]
a00fa0cc:  f6 36 a0 22  sth  %i3, [ %i2 + 0x22 ]
a00fa0d0:  f8 36 a0 44  sth  %i4, [ %i2 + 0x44 ]
a00fa0d4:  80 a6 60 0e  cmp  %i1, 0xe
a00fa0d8:  08 bf ff d9  bleu  0xa00fa03c
a00fa0dc:  fa 36 a0 66  sth  %i5, [ %i2 + 0x66 ]
a00fa0e0:  92 02 60 03  add  %o1, 3, %o1
a00fa0e4:  96 0a 60 ff  and  %o1, 0xff, %o3
a00fa0e8:  80 a2 e0 10  cmp  %o3, 0x10
a00fa0ec:  08 bf ff d3  bleu  0xa00fa038
a00fa0f0:  98 10 20 00  clr  %o4
a00fa0f4:  37 2a 00 9b  sethi  %hi(0xa8026c00), %i3
a00fa0f8:  9a 16 e2 d6  or  %i3, 0x2d6, %o5	! 0xa8026ed6
a00fa0fc:  b4 10 20 00  clr  %i2
a00fa100:  b3 2e a0 04  sll  %i2, 4, %i1
a00fa104:  9e 06 40 1a  add  %i1, %i2, %o7
a00fa108:  b0 10 20 02  mov  2, %i0
a00fa10c:  ba 10 20 02  mov  2, %i5
a00fa110:  b6 03 c0 1d  add  %o7, %i5, %i3
a00fa114:  b4 06 c0 1b  add  %i3, %i3, %i2
a00fa118:  f8 13 40 1a  lduh  [ %o5 + %i2 ], %i4
a00fa11c:  bb 2f 20 02  sll  %i4, 2, %i5
a00fa120:  82 07 40 1c  add  %i5, %i4, %g1
a00fa124:  b4 06 80 0d  add  %i2, %o5, %i2
a00fa128:  b3 28 60 04  sll  %g1, 4, %i1
a00fa12c:  f6 16 a0 06  lduh  [ %i2 + 6 ], %i3
a00fa130:  82 00 40 19  add  %g1, %i1, %g1
a00fa134:  b2 5e e0 ab  smul  %i3, 0xab, %i1
a00fa138:  ba 5f 20 aa  smul  %i4, 0xaa, %i5
a00fa13c:  b6 5e e0 56  smul  %i3, 0x56, %i3
a00fa140:  b8 07 40 1b  add  %i5, %i3, %i4
a00fa144:  82 00 40 19  add  %g1, %i1, %g1
a00fa148:  ba 00 60 80  add  %g1, 0x80, %i5
a00fa14c:  83 37 60 08  srl  %i5, 8, %g1
a00fa150:  b6 07 20 80  add  %i4, 0x80, %i3
a00fa154:  b0 06 20 03  add  %i0, 3, %i0
a00fa158:  b9 36 e0 08  srl  %i3, 8, %i4
a00fa15c:  ba 0e 20 ff  and  %i0, 0xff, %i5
a00fa160:  c2 36 a0 04  sth  %g1, [ %i2 + 4 ]
a00fa164:  80 a7 60 0d  cmp  %i5, 0xd
a00fa168:  08 bf ff ea  bleu  0xa00fa110
a00fa16c:  f8 36 a0 02  sth  %i4, [ %i2 + 2 ]
a00fa170:  98 03 20 01  inc  %o4
a00fa174:  b4 0b 20 ff  and  %o4, 0xff, %i2
a00fa178:  80 a6 a0 0f  cmp  %i2, 0xf
a00fa17c:  08 bf ff e2  bleu  0xa00fa104
a00fa180:  b3 2e a0 04  sll  %i2, 4, %i1
a00fa184:  31 2a 00 9b  sethi  %hi(0xa8026c00), %i0
a00fa188:  b4 16 22 d6  or  %i0, 0x2d6, %i2	! 0xa8026ed6
a00fa18c:  b6 10 20 00  clr  %i3
a00fa190:  b8 10 20 00  clr  %i4
a00fa194:  b1 2f 20 04  sll  %i4, 4, %i0
a00fa198:  ba 06 00 1c  add  %i0, %i4, %i5
a00fa19c:  82 07 40 1d  add  %i5, %i5, %g1
a00fa1a0:  82 00 40 1a  add  %g1, %i2, %g1
a00fa1a4:  f2 10 60 1c  lduh  [ %g1 + 0x1c ], %i1
a00fa1a8:  f8 10 60 20  lduh  [ %g1 + 0x20 ], %i4
a00fa1ac:  b0 06 40 1c  add  %i1, %i4, %i0
a00fa1b0:  bb 2e 20 07  sll  %i0, 7, %i5
a00fa1b4:  b8 07 60 80  add  %i5, 0x80, %i4
a00fa1b8:  b3 37 20 08  srl  %i4, 8, %i1
a00fa1bc:  b6 06 e0 01  inc  %i3
a00fa1c0:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00fa1c4:  80 a7 20 0f  cmp  %i4, 0xf
a00fa1c8:  08 bf ff f3  bleu  0xa00fa194
a00fa1cc:  f2 30 60 1e  sth  %i1, [ %g1 + 0x1e ]
a00fa1d0:  37 2a 00 9b  sethi  %hi(0xa8026c00), %i3
a00fa1d4:  b4 16 e2 d6  or  %i3, 0x2d6, %i2	! 0xa8026ed6
a00fa1d8:  b8 10 20 00  clr  %i4
a00fa1dc:  ba 10 20 00  clr  %i5
a00fa1e0:  b6 10 24 00  mov  0x400, %i3
a00fa1e4:  b1 2f 60 04  sll  %i5, 4, %i0
a00fa1e8:  82 06 00 1d  add  %i0, %i5, %g1
a00fa1ec:  b8 07 20 01  inc  %i4
a00fa1f0:  b2 00 40 01  add  %g1, %g1, %i1
a00fa1f4:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00fa1f8:  80 a7 60 0f  cmp  %i5, 0xf
a00fa1fc:  08 bf ff fa  bleu  0xa00fa1e4
a00fa200:  f6 36 80 19  sth  %i3, [ %i2 + %i1 ]
a00fa204:  35 2a 00 9b  sethi  %hi(0xa8026c00), %i2
a00fa208:  b2 16 a2 d6  or  %i2, 0x2d6, %i1	! 0xa8026ed6
a00fa20c:  b4 10 20 00  clr  %i2
a00fa210:  b8 10 20 00  clr  %i4
a00fa214:  b1 2f 20 04  sll  %i4, 4, %i0
a00fa218:  b6 06 00 1c  add  %i0, %i4, %i3
a00fa21c:  b8 06 c0 1b  add  %i3, %i3, %i4
a00fa220:  b6 07 00 19  add  %i4, %i1, %i3
a00fa224:  c2 16 40 1c  lduh  [ %i1 + %i4 ], %g1
a00fa228:  fa 16 e0 04  lduh  [ %i3 + 4 ], %i5
a00fa22c:  b0 00 40 1d  add  %g1, %i5, %i0
a00fa230:  83 2e 20 07  sll  %i0, 7, %g1
a00fa234:  b8 00 60 80  add  %g1, 0x80, %i4
a00fa238:  bb 37 20 08  srl  %i4, 8, %i5
a00fa23c:  b4 06 a0 01  inc  %i2
a00fa240:  b8 0e a0 ff  and  %i2, 0xff, %i4
a00fa244:  80 a7 20 0f  cmp  %i4, 0xf
a00fa248:  08 bf ff f3  bleu  0xa00fa214
a00fa24c:  fa 36 e0 02  sth  %i5, [ %i3 + 2 ]
a00fa250:  30 80 00 c2  b,a   0xa00fa558
a00fa254:  3b 2a 00 9b  sethi  %hi(0xa8026c00), %i5
a00fa258:  ba 17 60 b6  or  %i5, 0xb6, %i5	! 0xa8026cb6
a00fa25c:  f6 10 60 12  lduh  [ %g1 + 0x12 ], %i3
a00fa260:  f8 10 60 10  lduh  [ %g1 + 0x10 ], %i4
a00fa264:  f4 10 60 14  lduh  [ %g1 + 0x14 ], %i2
a00fa268:  f2 10 60 16  lduh  [ %g1 + 0x16 ], %i1
a00fa26c:  f0 10 60 18  lduh  [ %g1 + 0x18 ], %i0
a00fa270:  de 10 60 20  lduh  [ %g1 + 0x20 ], %o7
a00fa274:  da 10 60 22  lduh  [ %g1 + 0x22 ], %o5
a00fa278:  d8 10 60 24  lduh  [ %g1 + 0x24 ], %o4
a00fa27c:  d6 10 60 26  lduh  [ %g1 + 0x26 ], %o3
a00fa280:  d4 10 60 28  lduh  [ %g1 + 0x28 ], %o2
a00fa284:  d2 10 60 30  lduh  [ %g1 + 0x30 ], %o1
a00fa288:  d0 10 60 32  lduh  [ %g1 + 0x32 ], %o0
a00fa28c:  e0 10 60 34  lduh  [ %g1 + 0x34 ], %l0
a00fa290:  e2 10 60 36  lduh  [ %g1 + 0x36 ], %l1
a00fa294:  e4 10 60 38  lduh  [ %g1 + 0x38 ], %l2
a00fa298:  e6 10 60 40  lduh  [ %g1 + 0x40 ], %l3
a00fa29c:  f6 37 60 0a  sth  %i3, [ %i5 + 0xa ]
a00fa2a0:  f8 37 60 04  sth  %i4, [ %i5 + 4 ]
a00fa2a4:  f4 37 60 10  sth  %i2, [ %i5 + 0x10 ]
a00fa2a8:  f2 37 60 16  sth  %i1, [ %i5 + 0x16 ]
a00fa2ac:  f6 10 60 42  lduh  [ %g1 + 0x42 ], %i3
a00fa2b0:  f0 37 60 1c  sth  %i0, [ %i5 + 0x1c ]
a00fa2b4:  de 37 60 ae  sth  %o7, [ %i5 + 0xae ]
a00fa2b8:  da 37 60 b4  sth  %o5, [ %i5 + 0xb4 ]
a00fa2bc:  d8 37 60 ba  sth  %o4, [ %i5 + 0xba ]
a00fa2c0:  d6 37 60 c0  sth  %o3, [ %i5 + 0xc0 ]
a00fa2c4:  d4 37 60 c6  sth  %o2, [ %i5 + 0xc6 ]
a00fa2c8:  d2 37 61 58  sth  %o1, [ %i5 + 0x158 ]
a00fa2cc:  d0 37 61 5e  sth  %o0, [ %i5 + 0x15e ]
a00fa2d0:  e0 37 61 64  sth  %l0, [ %i5 + 0x164 ]
a00fa2d4:  e2 37 61 6a  sth  %l1, [ %i5 + 0x16a ]
a00fa2d8:  e4 37 61 70  sth  %l2, [ %i5 + 0x170 ]
a00fa2dc:  e6 37 62 02  sth  %l3, [ %i5 + 0x202 ]
a00fa2e0:  f6 37 62 08  sth  %i3, [ %i5 + 0x208 ]
a00fa2e4:  f8 10 60 44  lduh  [ %g1 + 0x44 ], %i4
a00fa2e8:  f4 10 60 46  lduh  [ %g1 + 0x46 ], %i2
a00fa2ec:  f2 10 60 48  lduh  [ %g1 + 0x48 ], %i1
a00fa2f0:  f8 37 62 0e  sth  %i4, [ %i5 + 0x20e ]
a00fa2f4:  f4 37 62 14  sth  %i2, [ %i5 + 0x214 ]
a00fa2f8:  f2 37 62 1a  sth  %i1, [ %i5 + 0x21a ]
a00fa2fc:  b6 10 20 00  clr  %i3
a00fa300:  b8 10 20 00  clr  %i4
a00fa304:  b4 10 24 00  mov  0x400, %i2
a00fa308:  b1 2f 20 04  sll  %i4, 4, %i0
a00fa30c:  82 06 00 1c  add  %i0, %i4, %g1
a00fa310:  b2 00 40 01  add  %g1, %g1, %i1
a00fa314:  b6 06 e0 01  inc  %i3
a00fa318:  b0 06 40 1d  add  %i1, %i5, %i0
a00fa31c:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00fa320:  80 a7 20 0f  cmp  %i4, 0xf
a00fa324:  08 bf ff f9  bleu  0xa00fa308
a00fa328:  f4 36 20 20  sth  %i2, [ %i0 + 0x20 ]
a00fa32c:  35 2a 00 9b  sethi  %hi(0xa8026c00), %i2
a00fa330:  94 16 a0 b6  or  %i2, 0xb6, %o2	! 0xa8026cb6
a00fa334:  92 10 20 02  mov  2, %o1
a00fa338:  96 10 20 02  mov  2, %o3
a00fa33c:  98 10 20 00  clr  %o4
a00fa340:  b2 10 20 00  clr  %i1
a00fa344:  b9 2e 60 04  sll  %i1, 4, %i4
a00fa348:  b0 07 00 19  add  %i4, %i1, %i0
a00fa34c:  ba 06 00 0b  add  %i0, %o3, %i5
a00fa350:  b4 07 40 1d  add  %i5, %i5, %i2
a00fa354:  fa 12 80 1a  lduh  [ %o2 + %i2 ], %i5
a00fa358:  b3 2f 60 03  sll  %i5, 3, %i1
a00fa35c:  82 07 40 1d  add  %i5, %i5, %g1
a00fa360:  b8 06 40 1d  add  %i1, %i5, %i4
a00fa364:  82 00 40 1d  add  %g1, %i5, %g1
a00fa368:  b4 06 80 0a  add  %i2, %o2, %i2
a00fa36c:  b7 2f 20 04  sll  %i4, 4, %i3
a00fa370:  b1 28 60 04  sll  %g1, 4, %i0
a00fa374:  f2 16 a0 aa  lduh  [ %i2 + 0xaa ], %i1
a00fa378:  b8 07 00 1b  add  %i4, %i3, %i4
a00fa37c:  82 00 40 18  add  %g1, %i0, %g1
a00fa380:  b0 5e 60 34  smul  %i1, 0x34, %i0
a00fa384:  9a 5e 60 cd  smul  %i1, 0xcd, %o5
a00fa388:  b6 5f 60 cc  smul  %i5, 0xcc, %i3
a00fa38c:  9e 5e 60 67  smul  %i1, 0x67, %o7
a00fa390:  b2 5e 60 9a  smul  %i1, 0x9a, %i1
a00fa394:  b6 06 c0 18  add  %i3, %i0, %i3
a00fa398:  ba 5f 60 66  smul  %i5, 0x66, %i5
a00fa39c:  ba 07 40 19  add  %i5, %i1, %i5
a00fa3a0:  b0 07 00 0f  add  %i4, %o7, %i0
a00fa3a4:  82 00 40 0d  add  %g1, %o5, %g1
a00fa3a8:  b8 06 20 80  add  %i0, 0x80, %i4
a00fa3ac:  b2 00 60 80  add  %g1, 0x80, %i1
a00fa3b0:  83 36 60 08  srl  %i1, 8, %g1
a00fa3b4:  b6 06 e0 80  add  %i3, 0x80, %i3
a00fa3b8:  b0 07 60 80  add  %i5, 0x80, %i0
a00fa3bc:  98 03 20 05  add  %o4, 5, %o4
a00fa3c0:  b7 36 e0 08  srl  %i3, 8, %i3
a00fa3c4:  b9 37 20 08  srl  %i4, 8, %i4
a00fa3c8:  bb 36 20 08  srl  %i0, 8, %i5
a00fa3cc:  b2 0b 20 ff  and  %o4, 0xff, %i1
a00fa3d0:  c2 36 a0 88  sth  %g1, [ %i2 + 0x88 ]
a00fa3d4:  f6 36 a0 22  sth  %i3, [ %i2 + 0x22 ]
a00fa3d8:  f8 36 a0 44  sth  %i4, [ %i2 + 0x44 ]
a00fa3dc:  80 a6 60 0e  cmp  %i1, 0xe
a00fa3e0:  08 bf ff d9  bleu  0xa00fa344
a00fa3e4:  fa 36 a0 66  sth  %i5, [ %i2 + 0x66 ]
a00fa3e8:  92 02 60 03  add  %o1, 3, %o1
a00fa3ec:  96 0a 60 ff  and  %o1, 0xff, %o3
a00fa3f0:  80 a2 e0 10  cmp  %o3, 0x10
a00fa3f4:  08 bf ff d3  bleu  0xa00fa340
a00fa3f8:  98 10 20 00  clr  %o4
a00fa3fc:  37 2a 00 9b  sethi  %hi(0xa8026c00), %i3
a00fa400:  9a 16 e0 b6  or  %i3, 0xb6, %o5	! 0xa8026cb6
a00fa404:  b4 10 20 00  clr  %i2
a00fa408:  b3 2e a0 04  sll  %i2, 4, %i1
a00fa40c:  9e 06 40 1a  add  %i1, %i2, %o7
a00fa410:  b0 10 20 02  mov  2, %i0
a00fa414:  ba 10 20 02  mov  2, %i5
a00fa418:  b6 03 c0 1d  add  %o7, %i5, %i3
a00fa41c:  b4 06 c0 1b  add  %i3, %i3, %i2
a00fa420:  f8 13 40 1a  lduh  [ %o5 + %i2 ], %i4
a00fa424:  bb 2f 20 02  sll  %i4, 2, %i5
a00fa428:  82 07 40 1c  add  %i5, %i4, %g1
a00fa42c:  b4 06 80 0d  add  %i2, %o5, %i2
a00fa430:  b3 28 60 04  sll  %g1, 4, %i1
a00fa434:  f6 16 a0 06  lduh  [ %i2 + 6 ], %i3
a00fa438:  82 00 40 19  add  %g1, %i1, %g1
a00fa43c:  b2 5e e0 ab  smul  %i3, 0xab, %i1
a00fa440:  ba 5f 20 aa  smul  %i4, 0xaa, %i5
a00fa444:  b6 5e e0 56  smul  %i3, 0x56, %i3
a00fa448:  b8 07 40 1b  add  %i5, %i3, %i4
a00fa44c:  82 00 40 19  add  %g1, %i1, %g1
a00fa450:  ba 00 60 80  add  %g1, 0x80, %i5
a00fa454:  83 37 60 08  srl  %i5, 8, %g1
a00fa458:  b6 07 20 80  add  %i4, 0x80, %i3
a00fa45c:  b0 06 20 03  add  %i0, 3, %i0
a00fa460:  b9 36 e0 08  srl  %i3, 8, %i4
a00fa464:  ba 0e 20 ff  and  %i0, 0xff, %i5
a00fa468:  c2 36 a0 04  sth  %g1, [ %i2 + 4 ]
a00fa46c:  80 a7 60 0d  cmp  %i5, 0xd
a00fa470:  08 bf ff ea  bleu  0xa00fa418
a00fa474:  f8 36 a0 02  sth  %i4, [ %i2 + 2 ]
a00fa478:  98 03 20 01  inc  %o4
a00fa47c:  b4 0b 20 ff  and  %o4, 0xff, %i2
a00fa480:  80 a6 a0 0f  cmp  %i2, 0xf
a00fa484:  08 bf ff e2  bleu  0xa00fa40c
a00fa488:  b3 2e a0 04  sll  %i2, 4, %i1
a00fa48c:  31 2a 00 9b  sethi  %hi(0xa8026c00), %i0
a00fa490:  b4 16 20 b6  or  %i0, 0xb6, %i2	! 0xa8026cb6
a00fa494:  b6 10 20 00  clr  %i3
a00fa498:  b8 10 20 00  clr  %i4
a00fa49c:  b1 2f 20 04  sll  %i4, 4, %i0
a00fa4a0:  ba 06 00 1c  add  %i0, %i4, %i5
a00fa4a4:  82 07 40 1d  add  %i5, %i5, %g1
a00fa4a8:  82 00 40 1a  add  %g1, %i2, %g1
a00fa4ac:  f2 10 60 1c  lduh  [ %g1 + 0x1c ], %i1
a00fa4b0:  f8 10 60 20  lduh  [ %g1 + 0x20 ], %i4
a00fa4b4:  b0 06 40 1c  add  %i1, %i4, %i0
a00fa4b8:  bb 2e 20 07  sll  %i0, 7, %i5
a00fa4bc:  b8 07 60 80  add  %i5, 0x80, %i4
a00fa4c0:  b3 37 20 08  srl  %i4, 8, %i1
a00fa4c4:  b6 06 e0 01  inc  %i3
a00fa4c8:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00fa4cc:  80 a7 20 0f  cmp  %i4, 0xf
a00fa4d0:  08 bf ff f3  bleu  0xa00fa49c
a00fa4d4:  f2 30 60 1e  sth  %i1, [ %g1 + 0x1e ]
a00fa4d8:  37 2a 00 9b  sethi  %hi(0xa8026c00), %i3
a00fa4dc:  b4 16 e0 b6  or  %i3, 0xb6, %i2	! 0xa8026cb6
a00fa4e0:  b8 10 20 00  clr  %i4
a00fa4e4:  ba 10 20 00  clr  %i5
a00fa4e8:  b6 10 24 00  mov  0x400, %i3
a00fa4ec:  b1 2f 60 04  sll  %i5, 4, %i0
a00fa4f0:  82 06 00 1d  add  %i0, %i5, %g1
a00fa4f4:  b8 07 20 01  inc  %i4
a00fa4f8:  b2 00 40 01  add  %g1, %g1, %i1
a00fa4fc:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00fa500:  80 a7 60 0f  cmp  %i5, 0xf
a00fa504:  08 bf ff fa  bleu  0xa00fa4ec
a00fa508:  f6 36 80 19  sth  %i3, [ %i2 + %i1 ]
a00fa50c:  35 2a 00 9b  sethi  %hi(0xa8026c00), %i2
a00fa510:  b2 16 a0 b6  or  %i2, 0xb6, %i1	! 0xa8026cb6
a00fa514:  b4 10 20 00  clr  %i2
a00fa518:  b8 10 20 00  clr  %i4
a00fa51c:  b1 2f 20 04  sll  %i4, 4, %i0
a00fa520:  b6 06 00 1c  add  %i0, %i4, %i3
a00fa524:  b8 06 c0 1b  add  %i3, %i3, %i4
a00fa528:  b6 07 00 19  add  %i4, %i1, %i3
a00fa52c:  c2 16 40 1c  lduh  [ %i1 + %i4 ], %g1
a00fa530:  fa 16 e0 04  lduh  [ %i3 + 4 ], %i5
a00fa534:  b0 00 40 1d  add  %g1, %i5, %i0
a00fa538:  83 2e 20 07  sll  %i0, 7, %g1
a00fa53c:  b8 00 60 80  add  %g1, 0x80, %i4
a00fa540:  bb 37 20 08  srl  %i4, 8, %i5
a00fa544:  b4 06 a0 01  inc  %i2
a00fa548:  b8 0e a0 ff  and  %i2, 0xff, %i4
a00fa54c:  80 a7 20 0f  cmp  %i4, 0xf
a00fa550:  08 bf ff f3  bleu  0xa00fa51c
a00fa554:  fa 36 e0 02  sth  %i5, [ %i3 + 2 ]
a00fa558:  81 c7 e0 08  ret
a00fa55c:  91 e8 20 01  restore  %g0, 1, %o0
