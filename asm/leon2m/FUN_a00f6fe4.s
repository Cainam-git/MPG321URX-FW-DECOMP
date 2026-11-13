# leon2m FUN_a00f6fe4 0xa00f6fe4-0xa00f72cc (744 bytes)
a00f6fe4:  9d e3 bf 80  save  %sp, -128, %sp
a00f6fe8:  98 10 20 00  clr  %o4
a00f6fec:  9a 10 20 00  clr  %o5
a00f6ff0:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a00f6ff4:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a00f6ff8:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a00f6ffc:  82 10 21 00  mov  0x100, %g1
a00f7000:  9a 10 20 80  mov  0x80, %o5
a00f7004:  c2 37 bf f4  sth  %g1, [ %fp + -12 ]
a00f7008:  da 37 bf f6  sth  %o5, [ %fp + -10 ]
a00f700c:  c2 37 bf e0  sth  %g1, [ %fp + -32 ]
a00f7010:  da 37 bf e6  sth  %o5, [ %fp + -26 ]
a00f7014:  c2 37 bf ea  sth  %g1, [ %fp + -22 ]
a00f7018:  80 a6 a0 00  cmp  %i2, 0
a00f701c:  02 80 00 a1  be  0xa00f72a0
a00f7020:  da 37 bf ee  sth  %o5, [ %fp + -18 ]
a00f7024:  80 8e 20 ff  btst  0xff, %i0
a00f7028:  02 80 00 8a  be  0xa00f7250
a00f702c:  17 33 c0 3a  sethi  %hi(0xcf00e800), %o3
a00f7030:  13 33 c0 3a  sethi  %hi(0xcf00e800), %o1
a00f7034:  9a 12 61 84  or  %o1, 0x184, %o5	! 0xcf00e984
a00f7038:  d0 03 40 00  ld  [ %o5 ], %o0
a00f703c:  82 12 20 40  or  %o0, 0x40, %g1
a00f7040:  c2 23 40 00  st  %g1, [ %o5 ]
a00f7044:  80 a6 60 01  cmp  %i1, 1
a00f7048:  02 80 00 8a  be  0xa00f7270
a00f704c:  1f 33 c0 3a  sethi  %hi(0xcf00e800), %o7
a00f7050:  80 a6 60 00  cmp  %i1, 0
a00f7054:  02 80 00 8d  be  0xa00f7288
a00f7058:  33 33 c0 3a  sethi  %hi(0xcf00e800), %i1
a00f705c:  80 8e e0 01  btst  1, %i3
a00f7060:  02 80 00 1d  be  0xa00f70d4
a00f7064:  80 8e e0 02  btst  2, %i3
a00f7068:  13 33 c0 3a  sethi  %hi(0xcf00e800), %o1
a00f706c:  9e 12 61 84  or  %o1, 0x184, %o7	! 0xcf00e984
a00f7070:  f2 03 c0 00  ld  [ %o7 ], %i1
a00f7074:  b0 0e 60 f1  and  %i1, 0xf1, %i0
a00f7078:  f0 23 c0 00  st  %i0, [ %o7 ]
a00f707c:  d6 0e a0 01  ldub  [ %i2 + 1 ], %o3
a00f7080:  98 12 61 8c  or  %o1, 0x18c, %o4
a00f7084:  d6 23 00 00  st  %o3, [ %o4 ]
a00f7088:  d4 16 80 00  lduh  [ %i2 ], %o2
a00f708c:  83 32 a0 08  srl  %o2, 8, %g1
a00f7090:  90 12 61 90  or  %o1, 0x190, %o0
a00f7094:  c2 22 00 00  st  %g1, [ %o0 ]
a00f7098:  da 0e a0 03  ldub  [ %i2 + 3 ], %o5
a00f709c:  b2 12 61 94  or  %o1, 0x194, %i1
a00f70a0:  da 26 40 00  st  %o5, [ %i1 ]
a00f70a4:  f0 16 a0 02  lduh  [ %i2 + 2 ], %i0
a00f70a8:  9f 36 20 08  srl  %i0, 8, %o7
a00f70ac:  98 12 61 98  or  %o1, 0x198, %o4
a00f70b0:  de 23 00 00  st  %o7, [ %o4 ]
a00f70b4:  d6 0e a0 05  ldub  [ %i2 + 5 ], %o3
a00f70b8:  94 12 61 9c  or  %o1, 0x19c, %o2
a00f70bc:  d6 22 80 00  st  %o3, [ %o2 ]
a00f70c0:  d0 16 a0 04  lduh  [ %i2 + 4 ], %o0
a00f70c4:  9a 12 61 a0  or  %o1, 0x1a0, %o5
a00f70c8:  83 32 20 08  srl  %o0, 8, %g1
a00f70cc:  c2 23 40 00  st  %g1, [ %o5 ]
a00f70d0:  80 8e e0 02  btst  2, %i3
a00f70d4:  02 80 00 1e  be  0xa00f714c
a00f70d8:  80 8e e0 04  btst  4, %i3
a00f70dc:  15 33 c0 3a  sethi  %hi(0xcf00e800), %o2
a00f70e0:  9e 12 a1 84  or  %o2, 0x184, %o7	! 0xcf00e984
a00f70e4:  d2 03 c0 00  ld  [ %o7 ], %o1
a00f70e8:  b2 0a 60 f1  and  %o1, 0xf1, %i1
a00f70ec:  b0 16 60 02  or  %i1, 2, %i0
a00f70f0:  f0 23 c0 00  st  %i0, [ %o7 ]
a00f70f4:  d6 0e a0 09  ldub  [ %i2 + 9 ], %o3
a00f70f8:  98 12 a1 8c  or  %o2, 0x18c, %o4
a00f70fc:  d6 23 00 00  st  %o3, [ %o4 ]
a00f7100:  c2 16 a0 08  lduh  [ %i2 + 8 ], %g1
a00f7104:  91 30 60 08  srl  %g1, 8, %o0
a00f7108:  9a 12 a1 90  or  %o2, 0x190, %o5
a00f710c:  d0 23 40 00  st  %o0, [ %o5 ]
a00f7110:  d2 0e a0 0b  ldub  [ %i2 + 0xb ], %o1
a00f7114:  b2 12 a1 94  or  %o2, 0x194, %i1
a00f7118:  d2 26 40 00  st  %o1, [ %i1 ]
a00f711c:  f0 16 a0 0a  lduh  [ %i2 + 0xa ], %i0
a00f7120:  9f 36 20 08  srl  %i0, 8, %o7
a00f7124:  96 12 a1 98  or  %o2, 0x198, %o3
a00f7128:  de 22 c0 00  st  %o7, [ %o3 ]
a00f712c:  d8 0e a0 0d  ldub  [ %i2 + 0xd ], %o4
a00f7130:  82 12 a1 9c  or  %o2, 0x19c, %g1
a00f7134:  d8 20 40 00  st  %o4, [ %g1 ]
a00f7138:  d0 16 a0 0c  lduh  [ %i2 + 0xc ], %o0
a00f713c:  92 12 a1 a0  or  %o2, 0x1a0, %o1
a00f7140:  9b 32 20 08  srl  %o0, 8, %o5
a00f7144:  da 22 40 00  st  %o5, [ %o1 ]
a00f7148:  80 8e e0 04  btst  4, %i3
a00f714c:  02 80 00 1e  be  0xa00f71c4
a00f7150:  80 8e e0 10  btst  0x10, %i3
a00f7154:  19 33 c0 3a  sethi  %hi(0xcf00e800), %o4
a00f7158:  b0 13 21 84  or  %o4, 0x184, %i0	! 0xcf00e984
a00f715c:  d4 06 00 00  ld  [ %i0 ], %o2
a00f7160:  92 0a a0 f1  and  %o2, 0xf1, %o1
a00f7164:  b2 12 60 04  or  %o1, 4, %i1
a00f7168:  f2 26 00 00  st  %i1, [ %i0 ]
a00f716c:  d6 0e a0 11  ldub  [ %i2 + 0x11 ], %o3
a00f7170:  9e 13 21 8c  or  %o4, 0x18c, %o7
a00f7174:  d6 23 c0 00  st  %o3, [ %o7 ]
a00f7178:  c2 16 a0 10  lduh  [ %i2 + 0x10 ], %g1
a00f717c:  91 30 60 08  srl  %g1, 8, %o0
a00f7180:  9a 13 21 90  or  %o4, 0x190, %o5
a00f7184:  d0 23 40 00  st  %o0, [ %o5 ]
a00f7188:  d4 0e a0 13  ldub  [ %i2 + 0x13 ], %o2
a00f718c:  92 13 21 94  or  %o4, 0x194, %o1
a00f7190:  d4 22 40 00  st  %o2, [ %o1 ]
a00f7194:  f2 16 a0 12  lduh  [ %i2 + 0x12 ], %i1
a00f7198:  b1 36 60 08  srl  %i1, 8, %i0
a00f719c:  9e 13 21 98  or  %o4, 0x198, %o7
a00f71a0:  f0 23 c0 00  st  %i0, [ %o7 ]
a00f71a4:  d6 0e a0 15  ldub  [ %i2 + 0x15 ], %o3
a00f71a8:  82 13 21 9c  or  %o4, 0x19c, %g1
a00f71ac:  d6 20 40 00  st  %o3, [ %g1 ]
a00f71b0:  d0 16 a0 14  lduh  [ %i2 + 0x14 ], %o0
a00f71b4:  94 13 21 a0  or  %o4, 0x1a0, %o2
a00f71b8:  9b 32 20 08  srl  %o0, 8, %o5
a00f71bc:  da 22 80 00  st  %o5, [ %o2 ]
a00f71c0:  80 8e e0 10  btst  0x10, %i3
a00f71c4:  02 80 00 0c  be  0xa00f71f4
a00f71c8:  80 8e e0 20  btst  0x20, %i3
a00f71cc:  1b 33 c0 3a  sethi  %hi(0xcf00e800), %o5
a00f71d0:  9e 13 61 84  or  %o5, 0x184, %o7	! 0xcf00e984
a00f71d4:  f0 03 c0 00  ld  [ %o7 ], %i0
a00f71d8:  96 0e 20 f0  and  %i0, 0xf0, %o3
a00f71dc:  82 12 e0 01  or  %o3, 1, %g1
a00f71e0:  c2 23 c0 00  st  %g1, [ %o7 ]
a00f71e4:  98 13 61 a4  or  %o5, 0x1a4, %o4
a00f71e8:  d0 16 a0 06  lduh  [ %i2 + 6 ], %o0
a00f71ec:  d0 23 00 00  st  %o0, [ %o4 ]
a00f71f0:  80 8e e0 20  btst  0x20, %i3
a00f71f4:  02 80 00 0c  be  0xa00f7224
a00f71f8:  80 8e e0 40  btst  0x40, %i3
a00f71fc:  15 33 c0 3a  sethi  %hi(0xcf00e800), %o2
a00f7200:  98 12 a1 84  or  %o2, 0x184, %o4	! 0xcf00e984
a00f7204:  de 03 00 00  ld  [ %o4 ], %o7
a00f7208:  9a 0b e0 f0  and  %o7, 0xf0, %o5
a00f720c:  90 13 60 03  or  %o5, 3, %o0
a00f7210:  d0 23 00 00  st  %o0, [ %o4 ]
a00f7214:  b2 12 a1 a4  or  %o2, 0x1a4, %i1
a00f7218:  d2 16 a0 0e  lduh  [ %i2 + 0xe ], %o1
a00f721c:  d2 26 40 00  st  %o1, [ %i1 ]
a00f7220:  80 8e e0 40  btst  0x40, %i3
a00f7224:  02 80 00 21  be  0xa00f72a8
a00f7228:  17 33 c0 3a  sethi  %hi(0xcf00e800), %o3
a00f722c:  b0 12 e1 84  or  %o3, 0x184, %i0	! 0xcf00e984
a00f7230:  d4 06 00 00  ld  [ %i0 ], %o2
a00f7234:  92 0a a0 f0  and  %o2, 0xf0, %o1
a00f7238:  b2 12 60 05  or  %o1, 5, %i1
a00f723c:  f2 26 00 00  st  %i1, [ %i0 ]
a00f7240:  b6 12 e1 a4  or  %o3, 0x1a4, %i3
a00f7244:  c2 16 a0 16  lduh  [ %i2 + 0x16 ], %g1
a00f7248:  c2 26 c0 00  st  %g1, [ %i3 ]
a00f724c:  30 80 00 17  b,a   0xa00f72a8
a00f7250:  9a 12 e1 84  or  %o3, 0x184, %o5
a00f7254:  d4 03 40 00  ld  [ %o5 ], %o2
a00f7258:  82 0a bf bf  and  %o2, -65, %g1
a00f725c:  c2 23 40 00  st  %g1, [ %o5 ]
a00f7260:  80 a6 60 01  cmp  %i1, 1
a00f7264:  32 bf ff 7c  bne,a   0xa00f7054
a00f7268:  80 a6 60 00  cmp  %i1, 0
a00f726c:  1f 33 c0 3a  sethi  %hi(0xcf00e800), %o7
a00f7270:  9a 13 e1 84  or  %o7, 0x184, %o5	! 0xcf00e984
a00f7274:  d8 03 40 00  ld  [ %o5 ], %o4
a00f7278:  82 13 20 80  or  %o4, 0x80, %g1
a00f727c:  c2 23 40 00  st  %g1, [ %o5 ]
a00f7280:  10 bf ff 78  b  0xa00f7060
a00f7284:  80 8e e0 01  btst  1, %i3
a00f7288:  9a 16 61 84  or  %i1, 0x184, %o5
a00f728c:  f0 03 40 00  ld  [ %o5 ], %i0
a00f7290:  82 0e 3f 7f  and  %i0, -129, %g1
a00f7294:  c2 23 40 00  st  %g1, [ %o5 ]
a00f7298:  10 bf ff 72  b  0xa00f7060
a00f729c:  80 8e e0 01  btst  1, %i3
a00f72a0:  10 bf ff 61  b  0xa00f7024
a00f72a4:  b4 07 bf e0  add  %fp, -32, %i2
a00f72a8:  67 fe 5b ff  call  0x4008e2a4
a00f72ac:  01 00 00 00  nop
a00f72b0:  1b 33 c0 3a  sethi  %hi(0xcf00e800), %o5
a00f72b4:  b4 13 61 84  or  %o5, 0x184, %i2	! 0xcf00e984
a00f72b8:  d0 06 80 00  ld  [ %i2 ], %o0
a00f72bc:  98 12 20 08  or  %o0, 8, %o4
a00f72c0:  d8 26 80 00  st  %o4, [ %i2 ]
a00f72c4:  81 c7 e0 08  ret
a00f72c8:  81 e8 00 00  restore
