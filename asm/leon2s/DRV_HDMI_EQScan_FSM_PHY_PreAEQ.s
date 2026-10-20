# leon2s DRV_HDMI_EQScan_FSM_PHY_PreAEQ 0xa0076e68-0xa007731c (1204 bytes)
a0076e68:  9d e3 bf 98  save  %sp, -104, %sp
a0076e6c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0076e70:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0076e74:  80 88 60 02  btst  2, %g1
a0076e78:  02 80 00 0a  be  0xa0076ea0
a0076e7c:  a8 10 00 18  mov  %i0, %l4
a0076e80:  92 06 20 41  add  %i0, 0x41, %o1
a0076e84:  93 2a 60 18  sll  %o1, 0x18, %o1
a0076e88:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a0076e8c:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a0076e90:  90 12 20 58  or  %o0, 0x58, %o0
a0076e94:  93 3a 60 18  sra  %o1, 0x18, %o1
a0076e98:  7f ff f0 6b  call  0xa0073044
a0076e9c:  94 12 a0 d0  or  %o2, 0xd0, %o2
a0076ea0:  a0 0d 20 ff  and  %l4, 0xff, %l0
a0076ea4:  82 04 00 10  add  %l0, %l0, %g1
a0076ea8:  82 00 40 10  add  %g1, %l0, %g1
a0076eac:  23 2a 01 f3  sethi  %hi(0xa807cc00), %l1
a0076eb0:  83 28 60 02  sll  %g1, 2, %g1
a0076eb4:  9a 14 60 c4  or  %l1, 0xc4, %o5
a0076eb8:  82 00 40 0d  add  %g1, %o5, %g1
a0076ebc:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0076ec0:  80 a0 60 00  cmp  %g1, 0
a0076ec4:  03 28 02 cf  sethi  %hi(0xa00b3c00), %g1
a0076ec8:  12 80 00 04  bne  0xa0076ed8
a0076ecc:  ac 10 60 0c  or  %g1, 0xc, %l6	! 0xa00b3c0c
a0076ed0:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0076ed4:  ac 10 63 d4  or  %g1, 0x3d4, %l6	! 0xa00b3bd4
a0076ed8:  7f ff f1 92  call  0xa0073520
a0076edc:  90 10 00 10  mov  %l0, %o0
a0076ee0:  80 8a 20 ff  btst  0xff, %o0
a0076ee4:  02 80 00 14  be  0xa0076f34
a0076ee8:  aa 10 20 00  clr  %l5
a0076eec:  82 04 00 10  add  %l0, %l0, %g1
a0076ef0:  82 00 40 10  add  %g1, %l0, %g1
a0076ef4:  9a 14 60 c4  or  %l1, 0xc4, %o5
a0076ef8:  83 28 60 02  sll  %g1, 2, %g1
a0076efc:  82 00 40 0d  add  %g1, %o5, %g1
a0076f00:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0076f04:  80 a0 60 00  cmp  %g1, 0
a0076f08:  12 80 00 0c  bne  0xa0076f38
a0076f0c:  17 2a 01 ea  sethi  %hi(0xa807a800), %o3
a0076f10:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0076f14:  82 10 61 88  or  %g1, 0x188, %g1	! 0xa8078988
a0076f18:  c2 08 40 10  ldub  [ %g1 + %l0 ], %g1
a0076f1c:  80 a0 60 01  cmp  %g1, 1
a0076f20:  12 80 00 07  bne  0xa0076f3c
a0076f24:  b0 0d 20 ff  and  %l4, 0xff, %i0
a0076f28:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0076f2c:  ac 10 63 9c  or  %g1, 0x39c, %l6	! 0xa00b3b9c
a0076f30:  aa 10 20 00  clr  %l5
a0076f34:  17 2a 01 ea  sethi  %hi(0xa807a800), %o3
a0076f38:  b0 0d 20 ff  and  %l4, 0xff, %i0
a0076f3c:  82 12 e1 f0  or  %o3, 0x1f0, %g1
a0076f40:  9a 5e 28 98  smul  %i0, 0x898, %o5
a0076f44:  9a 03 40 01  add  %o5, %g1, %o5
a0076f48:  a4 0d 60 ff  and  %l5, 0xff, %l2
a0076f4c:  98 03 40 12  add  %o5, %l2, %o4
a0076f50:  c2 0b 20 2d  ldub  [ %o4 + 0x2d ], %g1
a0076f54:  80 a0 60 01  cmp  %g1, 1
a0076f58:  12 80 00 10  bne  0xa0076f98
a0076f5c:  82 06 00 18  add  %i0, %i0, %g1
a0076f60:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0076f64:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0076f68:  80 88 60 02  btst  2, %g1
a0076f6c:  22 80 00 a1  be,a   0xa00771f0
a0076f70:  aa 05 60 01  inc  %l5
a0076f74:  92 05 20 41  add  %l4, 0x41, %o1
a0076f78:  93 2a 60 18  sll  %o1, 0x18, %o1
a0076f7c:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a0076f80:  93 3a 60 18  sra  %o1, 0x18, %o1
a0076f84:  94 10 00 12  mov  %l2, %o2
a0076f88:  7f ff f0 2f  call  0xa0073044
a0076f8c:  90 12 20 78  or  %o0, 0x78, %o0
a0076f90:  10 80 00 98  b  0xa00771f0
a0076f94:  aa 05 60 01  inc  %l5
a0076f98:  82 00 40 18  add  %g1, %i0, %g1
a0076f9c:  21 2a 01 f3  sethi  %hi(0xa807cc00), %l0
a0076fa0:  9a 14 20 c4  or  %l0, 0xc4, %o5	! 0xa807ccc4
a0076fa4:  83 28 60 02  sll  %g1, 2, %g1
a0076fa8:  82 00 40 0d  add  %g1, %o5, %g1
a0076fac:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0076fb0:  80 a0 60 00  cmp  %g1, 0
a0076fb4:  02 80 00 04  be  0xa0076fc4
a0076fb8:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a0076fbc:  10 80 00 03  b  0xa0076fc8
a0076fc0:  80 a3 60 09  cmp  %o5, 9
a0076fc4:  80 a3 60 0d  cmp  %o5, 0xd
a0076fc8:  18 80 00 46  bgu  0xa00770e0
a0076fcc:  23 2a 01 e1  sethi  %hi(0xa8078400), %l1
a0076fd0:  9a 12 e1 f0  or  %o3, 0x1f0, %o5
a0076fd4:  82 5e 28 98  smul  %i0, 0x898, %g1
a0076fd8:  82 00 40 0d  add  %g1, %o5, %g1
a0076fdc:  a6 00 40 12  add  %g1, %l2, %l3
a0076fe0:  c2 0c e0 03  ldub  [ %l3 + 3 ], %g1
a0076fe4:  80 a0 60 00  cmp  %g1, 0
a0076fe8:  12 80 00 07  bne  0xa0077004
a0076fec:  80 a4 a0 02  cmp  %l2, 2
a0076ff0:  82 5e 22 26  smul  %i0, 0x226, %g1
a0076ff4:  82 00 40 12  add  %g1, %l2, %g1
a0076ff8:  83 28 60 02  sll  %g1, 2, %g1
a0076ffc:  82 00 40 0d  add  %g1, %o5, %g1
a0077000:  c0 20 60 10  clr  [ %g1 + 0x10 ]
a0077004:  38 80 00 13  bgu,a   0xa0077050
a0077008:  c2 0c e0 03  ldub  [ %l3 + 3 ], %g1
a007700c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0077010:  82 10 63 04  or  %g1, 0x304, %g1	! 0xa00b3b04
a0077014:  a0 04 80 12  add  %l2, %l2, %l0
a0077018:  23 3f c0 3f  sethi  %hi(0xff00fc00), %l1
a007701c:  d2 10 40 10  lduh  [ %g1 + %l0 ], %o1
a0077020:  90 10 00 18  mov  %i0, %o0
a0077024:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0077028:  40 00 c1 18  call  0xa00a7488
a007702c:  17 00 0b c0  sethi  %hi(0x2f0000), %o3
a0077030:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0077034:  82 10 63 0a  or  %g1, 0x30a, %g1	! 0xa00b3b0a
a0077038:  d2 10 40 10  lduh  [ %g1 + %l0 ], %o1
a007703c:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0077040:  90 10 00 18  mov  %i0, %o0
a0077044:  40 00 c1 11  call  0xa00a7488
a0077048:  17 00 13 c0  sethi  %hi(0x4f0000), %o3
a007704c:  c2 0c e0 03  ldub  [ %l3 + 3 ], %g1
a0077050:  83 28 60 02  sll  %g1, 2, %g1
a0077054:  9a 05 80 01  add  %l6, %g1, %o5
a0077058:  e0 13 60 02  lduh  [ %o5 + 2 ], %l0
a007705c:  80 a4 a0 02  cmp  %l2, 2
a0077060:  18 80 00 0e  bgu  0xa0077098
a0077064:  e2 0d 80 01  ldub  [ %l6 + %g1 ], %l1
a0077068:  97 2c 20 10  sll  %l0, 0x10, %o3
a007706c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0077070:  97 32 e0 08  srl  %o3, 8, %o3
a0077074:  9a 04 80 12  add  %l2, %l2, %o5
a0077078:  98 0c 60 0f  and  %l1, 0xf, %o4
a007707c:  82 10 63 78  or  %g1, 0x378, %g1
a0077080:  15 3f c0 00  sethi  %hi(0xff000000), %o2
a0077084:  d2 10 40 0d  lduh  [ %g1 + %o5 ], %o1
a0077088:  96 13 00 0b  or  %o4, %o3, %o3
a007708c:  90 10 00 18  mov  %i0, %o0
a0077090:  40 00 c0 fe  call  0xa00a7488
a0077094:  94 12 a0 f0  or  %o2, 0xf0, %o2
a0077098:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007709c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a00770a0:  80 88 60 02  btst  2, %g1
a00770a4:  22 80 00 53  be,a   0xa00771f0
a00770a8:  aa 05 60 01  inc  %l5
a00770ac:  92 05 20 41  add  %l4, 0x41, %o1
a00770b0:  9b 2c 20 10  sll  %l0, 0x10, %o5
a00770b4:  93 2a 60 18  sll  %o1, 0x18, %o1
a00770b8:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a00770bc:  93 3a 60 18  sra  %o1, 0x18, %o1
a00770c0:  94 10 00 12  mov  %l2, %o2
a00770c4:  d6 0c e0 03  ldub  [ %l3 + 3 ], %o3
a00770c8:  98 0c 60 ff  and  %l1, 0xff, %o4
a00770cc:  9b 33 60 10  srl  %o5, 0x10, %o5
a00770d0:  7f ff ef dd  call  0xa0073044
a00770d4:  90 12 20 c0  or  %o0, 0xc0, %o0
a00770d8:  10 80 00 46  b  0xa00771f0
a00770dc:  aa 05 60 01  inc  %l5
a00770e0:  c2 04 62 34  ld  [ %l1 + 0x234 ], %g1
a00770e4:  80 88 60 02  btst  2, %g1
a00770e8:  02 80 00 0f  be  0xa0077124
a00770ec:  92 0d 20 ff  and  %l4, 0xff, %o1
a00770f0:  9a 12 e1 f0  or  %o3, 0x1f0, %o5
a00770f4:  82 5e 28 98  smul  %i0, 0x898, %g1
a00770f8:  82 00 40 0d  add  %g1, %o5, %g1
a00770fc:  92 05 20 41  add  %l4, 0x41, %o1
a0077100:  93 2a 60 18  sll  %o1, 0x18, %o1
a0077104:  82 00 40 12  add  %g1, %l2, %g1
a0077108:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a007710c:  90 12 21 08  or  %o0, 0x108, %o0	! 0xa0067108
a0077110:  93 3a 60 18  sra  %o1, 0x18, %o1
a0077114:  94 10 00 12  mov  %l2, %o2
a0077118:  7f ff ef cb  call  0xa0073044
a007711c:  d6 08 60 09  ldub  [ %g1 + 9 ], %o3
a0077120:  92 0d 20 ff  and  %l4, 0xff, %o1
a0077124:  82 02 40 09  add  %o1, %o1, %g1
a0077128:  82 00 40 09  add  %g1, %o1, %g1
a007712c:  11 2a 01 ea  sethi  %hi(0xa807a800), %o0
a0077130:  96 14 20 c4  or  %l0, 0xc4, %o3
a0077134:  83 28 60 02  sll  %g1, 2, %g1
a0077138:  98 12 21 f0  or  %o0, 0x1f0, %o4
a007713c:  9a 5a 68 98  smul  %o1, 0x898, %o5
a0077140:  82 00 40 0b  add  %g1, %o3, %g1
a0077144:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0077148:  9a 03 40 0c  add  %o5, %o4, %o5
a007714c:  94 0d 60 ff  and  %l5, 0xff, %o2
a0077150:  9a 03 40 0a  add  %o5, %o2, %o5
a0077154:  80 a0 60 00  cmp  %g1, 0
a0077158:  02 80 00 07  be  0xa0077174
a007715c:  c2 0b 60 09  ldub  [ %o5 + 9 ], %g1
a0077160:  80 a0 60 02  cmp  %g1, 2
a0077164:  28 80 00 08  bleu,a   0xa0077184
a0077168:  9a 12 21 f0  or  %o0, 0x1f0, %o5
a007716c:  10 80 00 18  b  0xa00771cc
a0077170:  9a 0d 20 ff  and  %l4, 0xff, %o5
a0077174:  80 a0 60 00  cmp  %g1, 0
a0077178:  12 80 00 15  bne  0xa00771cc
a007717c:  9a 0d 20 ff  and  %l4, 0xff, %o5
a0077180:  9a 12 21 f0  or  %o0, 0x1f0, %o5
a0077184:  82 5a 68 98  smul  %o1, 0x898, %g1
a0077188:  82 00 40 0d  add  %g1, %o5, %g1
a007718c:  a0 00 40 0a  add  %g1, %o2, %l0
a0077190:  c2 0c 20 09  ldub  [ %l0 + 9 ], %g1
a0077194:  96 00 60 01  add  %g1, 1, %o3
a0077198:  c2 04 62 34  ld  [ %l1 + 0x234 ], %g1
a007719c:  80 88 60 02  btst  2, %g1
a00771a0:  02 80 00 09  be  0xa00771c4
a00771a4:  d6 2c 20 09  stb  %o3, [ %l0 + 9 ]
a00771a8:  92 05 20 41  add  %l4, 0x41, %o1
a00771ac:  93 2a 60 18  sll  %o1, 0x18, %o1
a00771b0:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a00771b4:  90 12 21 40  or  %o0, 0x140, %o0	! 0xa0067140
a00771b8:  93 3a 60 18  sra  %o1, 0x18, %o1
a00771bc:  7f ff ef a2  call  0xa0073044
a00771c0:  96 0a e0 ff  and  %o3, 0xff, %o3
a00771c4:  c0 2c 20 03  clrb  [ %l0 + 3 ]
a00771c8:  9a 0d 20 ff  and  %l4, 0xff, %o5
a00771cc:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00771d0:  82 10 61 f0  or  %g1, 0x1f0, %g1	! 0xa807a9f0
a00771d4:  9a 5b 68 98  smul  %o5, 0x898, %o5
a00771d8:  9a 03 40 01  add  %o5, %g1, %o5
a00771dc:  82 0d 60 ff  and  %l5, 0xff, %g1
a00771e0:  9a 03 40 01  add  %o5, %g1, %o5
a00771e4:  82 10 20 01  mov  1, %g1
a00771e8:  c2 2b 60 2a  stb  %g1, [ %o5 + 0x2a ]
a00771ec:  aa 05 60 01  inc  %l5
a00771f0:  82 0d 60 ff  and  %l5, 0xff, %g1
a00771f4:  80 a0 60 02  cmp  %g1, 2
a00771f8:  08 bf ff 50  bleu  0xa0076f38
a00771fc:  17 2a 01 ea  sethi  %hi(0xa807a800), %o3
a0077200:  19 2a 01 ea  sethi  %hi(0xa807a800), %o4
a0077204:  90 0d 20 ff  and  %l4, 0xff, %o0
a0077208:  82 13 21 f0  or  %o4, 0x1f0, %g1
a007720c:  9a 5a 28 98  smul  %o0, 0x898, %o5
a0077210:  96 03 40 01  add  %o5, %g1, %o3
a0077214:  c2 0a e0 2a  ldub  [ %o3 + 0x2a ], %g1
a0077218:  80 a0 60 01  cmp  %g1, 1
a007721c:  12 80 00 2f  bne  0xa00772d8
a0077220:  82 13 21 f0  or  %o4, 0x1f0, %g1
a0077224:  c2 0a e0 2b  ldub  [ %o3 + 0x2b ], %g1
a0077228:  80 a0 60 01  cmp  %g1, 1
a007722c:  12 80 00 2b  bne  0xa00772d8
a0077230:  82 13 21 f0  or  %o4, 0x1f0, %g1
a0077234:  c2 0a e0 2c  ldub  [ %o3 + 0x2c ], %g1
a0077238:  80 a0 60 01  cmp  %g1, 1
a007723c:  12 80 00 27  bne  0xa00772d8
a0077240:  82 13 21 f0  or  %o4, 0x1f0, %g1
a0077244:  82 02 00 08  add  %o0, %o0, %g1
a0077248:  82 00 40 08  add  %g1, %o0, %g1
a007724c:  19 2a 01 f3  sethi  %hi(0xa807cc00), %o4
a0077250:  83 28 60 02  sll  %g1, 2, %g1
a0077254:  9a 13 20 c4  or  %o4, 0xc4, %o5
a0077258:  82 00 40 0d  add  %g1, %o5, %g1
a007725c:  c0 2a e0 30  clrb  [ %o3 + 0x30 ]
a0077260:  d0 08 60 08  ldub  [ %g1 + 8 ], %o0
a0077264:  aa 10 20 00  clr  %l5
a0077268:  9a 0d 60 ff  and  %l5, 0xff, %o5
a007726c:  82 02 c0 0d  add  %o3, %o5, %g1
a0077270:  c2 08 60 09  ldub  [ %g1 + 9 ], %g1
a0077274:  80 a2 20 00  cmp  %o0, 0
a0077278:  02 80 00 07  be  0xa0077294
a007727c:  9a 02 c0 0d  add  %o3, %o5, %o5
a0077280:  80 a0 60 02  cmp  %g1, 2
a0077284:  28 80 00 08  bleu,a   0xa00772a4
a0077288:  c0 2b 60 2a  clrb  [ %o5 + 0x2a ]
a007728c:  10 80 00 07  b  0xa00772a8
a0077290:  aa 05 60 01  inc  %l5
a0077294:  80 a0 60 00  cmp  %g1, 0
a0077298:  32 80 00 04  bne,a   0xa00772a8
a007729c:  aa 05 60 01  inc  %l5
a00772a0:  c0 2b 60 2a  clrb  [ %o5 + 0x2a ]
a00772a4:  aa 05 60 01  inc  %l5
a00772a8:  82 0d 60 ff  and  %l5, 0xff, %g1
a00772ac:  80 a0 60 02  cmp  %g1, 2
a00772b0:  08 bf ff ef  bleu  0xa007726c
a00772b4:  9a 0d 60 ff  and  %l5, 0xff, %o5
a00772b8:  9a 0d 20 ff  and  %l4, 0xff, %o5
a00772bc:  82 03 40 0d  add  %o5, %o5, %g1
a00772c0:  82 00 40 0d  add  %g1, %o5, %g1
a00772c4:  98 13 20 c4  or  %o4, 0xc4, %o4
a00772c8:  83 28 60 02  sll  %g1, 2, %g1
a00772cc:  9a 10 20 06  mov  6, %o5
a00772d0:  10 80 00 11  b  0xa0077314
a00772d4:  da 23 00 01  st  %o5, [ %o4 + %g1 ]
a00772d8:  98 5a 28 98  smul  %o0, 0x898, %o4
a00772dc:  98 03 00 01  add  %o4, %g1, %o4
a00772e0:  9a 02 00 08  add  %o0, %o0, %o5
a00772e4:  9a 03 40 08  add  %o5, %o0, %o5
a00772e8:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00772ec:  9b 2b 60 02  sll  %o5, 2, %o5
a00772f0:  82 10 60 c4  or  %g1, 0xc4, %g1
a00772f4:  96 10 20 0c  mov  0xc, %o3
a00772f8:  d6 20 40 0d  st  %o3, [ %g1 + %o5 ]
a00772fc:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0077300:  9a 10 20 01  mov  1, %o5
a0077304:  82 10 61 a0  or  %g1, 0x1a0, %g1
a0077308:  da 28 40 08  stb  %o5, [ %g1 + %o0 ]
a007730c:  7f ff f6 cb  call  0xa0074e38
a0077310:  c0 2b 20 30  clrb  [ %o4 + 0x30 ]
a0077314:  81 c7 e0 08  ret
a0077318:  91 e8 20 00  restore  %g0, 0, %o0
