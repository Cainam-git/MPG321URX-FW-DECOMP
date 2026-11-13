# leon2m FUN_a00a5e68 0xa00a5e68-0xa00a6b98 (3376 bytes)
a00a5e68:  9d e3 bf 88  save  %sp, -120, %sp
a00a5e6c:  40 02 89 44  call  0xa014837c
a00a5e70:  90 10 20 00  clr  %o0
a00a5e74:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00a5e78:  19 2a aa aa  sethi  %hi(0xaaaaa800), %o4
a00a5e7c:  95 33 e0 10  srl  %o7, 0x10, %o2
a00a5e80:  96 13 22 ab  or  %o4, 0x2ab, %o3
a00a5e84:  80 52 80 0b  umul  %o2, %o3, %g0
a00a5e88:  93 40 00 00  rd  %y, %o1
a00a5e8c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00a5e90:  91 32 60 04  srl  %o1, 4, %o0
a00a5e94:  da 10 63 f4  lduh  [ %g1 + 0x3f4 ], %o5
a00a5e98:  80 8b 64 00  btst  0x400, %o5
a00a5e9c:  12 80 03 3d  bne  0xa00a6b90
a00a5ea0:  a2 02 20 01  add  %o0, 1, %l1
a00a5ea4:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a00a5ea8:  9a 16 e2 90  or  %i3, 0x290, %o5	! 0xa802d290
a00a5eac:  c2 0b 61 3e  ldub  [ %o5 + 0x13e ], %g1
a00a5eb0:  80 a0 60 00  cmp  %g1, 0
a00a5eb4:  ae 10 20 02  mov  2, %l7
a00a5eb8:  12 80 00 cd  bne  0xa00a61ec
a00a5ebc:  b4 10 20 02  mov  2, %i2
a00a5ec0:  9a 16 e2 90  or  %i3, 0x290, %o5
a00a5ec4:  c2 0b 61 3f  ldub  [ %o5 + 0x13f ], %g1
a00a5ec8:  80 a0 60 00  cmp  %g1, 0
a00a5ecc:  ac 10 20 02  mov  2, %l6
a00a5ed0:  02 80 00 10  be  0xa00a5f10
a00a5ed4:  b8 10 20 06  mov  6, %i4
a00a5ed8:  80 a0 60 01  cmp  %g1, 1
a00a5edc:  02 80 02 72  be  0xa00a68a4
a00a5ee0:  80 a0 60 02  cmp  %g1, 2
a00a5ee4:  ac 10 20 02  mov  2, %l6
a00a5ee8:  02 80 00 0a  be  0xa00a5f10
a00a5eec:  b8 10 20 31  mov  0x31, %i4
a00a5ef0:  80 a0 60 03  cmp  %g1, 3
a00a5ef4:  02 80 02 6c  be  0xa00a68a4
a00a5ef8:  01 00 00 00  nop
a00a5efc:  e4 0b 61 a7  ldub  [ %o5 + 0x1a7 ], %l2
a00a5f00:  e0 0b 61 a8  ldub  [ %o5 + 0x1a8 ], %l0
a00a5f04:  a6 04 80 12  add  %l2, %l2, %l3
a00a5f08:  ac 04 c0 12  add  %l3, %l2, %l6
a00a5f0c:  b8 04 00 10  add  %l0, %l0, %i4
a00a5f10:  40 02 89 1b  call  0xa014837c
a00a5f14:  90 10 20 00  clr  %o0
a00a5f18:  93 2a 20 10  sll  %o0, 0x10, %o1
a00a5f1c:  91 32 60 10  srl  %o1, 0x10, %o0
a00a5f20:  1b 0a aa aa  sethi  %hi(0x2aaaa800), %o5
a00a5f24:  b2 02 3d c8  add  %o0, -568, %i1
a00a5f28:  a4 13 62 ab  or  %o5, 0x2ab, %l2
a00a5f2c:  80 5e 40 12  smul  %i1, %l2, %g0
a00a5f30:  bb 40 00 00  rd  %y, %i5
a00a5f34:  ab 3f 60 02  sra  %i5, 2, %l5
a00a5f38:  a9 3e 60 1f  sra  %i1, 0x1f, %l4
a00a5f3c:  a0 25 40 14  sub  %l5, %l4, %l0
a00a5f40:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a5f44:  80 a6 20 00  cmp  %i0, 0
a00a5f48:  12 80 00 f8  bne  0xa00a6328
a00a5f4c:  e0 37 bf f6  sth  %l0, [ %fp + -10 ]
a00a5f50:  96 16 e2 90  or  %i3, 0x290, %o3
a00a5f54:  e6 0a e1 a0  ldub  [ %o3 + 0x1a0 ], %l3
a00a5f58:  80 a4 e0 00  cmp  %l3, 0
a00a5f5c:  22 80 00 91  be,a   0xa00a61a0
a00a5f60:  a4 16 e2 90  or  %i3, 0x290, %l2
a00a5f64:  a3 2d a0 10  sll  %l6, 0x10, %l1
a00a5f68:  99 34 60 10  srl  %l1, 0x10, %o4
a00a5f6c:  ab 2d e0 10  sll  %l7, 0x10, %l5
a00a5f70:  9b 35 60 10  srl  %l5, 0x10, %o5
a00a5f74:  a8 03 20 0b  add  %o4, 0xb, %l4
a00a5f78:  80 a5 00 0d  cmp  %l4, %o5
a00a5f7c:  14 80 00 ab  bg  0xa00a6228
a00a5f80:  ba 03 60 08  add  %o5, 8, %i5
a00a5f84:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00a5f88:  13 33 33 33  sethi  %hi(0xcccccc00), %o1
a00a5f8c:  b8 0f 20 ff  and  %i4, 0xff, %i4
a00a5f90:  a8 10 62 90  or  %g1, 0x290, %l4
a00a5f94:  a6 12 60 cd  or  %o1, 0xcd, %l3
a00a5f98:  aa 10 20 00  clr  %l5
a00a5f9c:  a4 10 20 00  clr  %l2
a00a5fa0:  ba 05 a0 01  add  %l6, 1, %i5
a00a5fa4:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00a5fa8:  9e 07 00 10  add  %i4, %l0, %o7
a00a5fac:  97 2f 60 10  sll  %i5, 0x10, %o3
a00a5fb0:  99 2b e0 10  sll  %o7, 0x10, %o4
a00a5fb4:  91 32 e0 10  srl  %o3, 0x10, %o0
a00a5fb8:  15 00 00 2e  sethi  %hi(0xb800), %o2
a00a5fbc:  a3 33 20 10  srl  %o4, 0x10, %l1
a00a5fc0:  96 12 a0 0a  or  %o2, 0xa, %o3
a00a5fc4:  92 10 00 11  mov  %l1, %o1
a00a5fc8:  94 10 20 0a  mov  0xa, %o2
a00a5fcc:  98 10 20 00  clr  %o4
a00a5fd0:  40 02 82 ac  call  0xa0146a80
a00a5fd4:  b2 10 00 11  mov  %l1, %i1
a00a5fd8:  a2 10 20 00  clr  %l1
a00a5fdc:  c2 0d 21 a1  ldub  [ %l4 + 0x1a1 ], %g1
a00a5fe0:  80 50 40 13  umul  %g1, %l3, %g0
a00a5fe4:  97 40 00 00  rd  %y, %o3
a00a5fe8:  93 32 e0 03  srl  %o3, 3, %o1
a00a5fec:  94 0a 60 ff  and  %o1, 0xff, %o2
a00a5ff0:  9a 02 80 0a  add  %o2, %o2, %o5
a00a5ff4:  90 03 40 0a  add  %o5, %o2, %o0
a00a5ff8:  98 02 00 12  add  %o0, %l2, %o4
a00a5ffc:  9e 03 00 0c  add  %o4, %o4, %o7
a00a6000:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a6004:  a0 04 00 16  add  %l0, %l6, %l0
a00a6008:  96 03 c0 11  add  %o7, %l1, %o3
a00a600c:  82 04 20 01  add  %l0, 1, %g1
a00a6010:  94 02 e0 30  add  %o3, 0x30, %o2
a00a6014:  93 28 60 10  sll  %g1, 0x10, %o1
a00a6018:  98 0a a0 ff  and  %o2, 0xff, %o4
a00a601c:  93 32 60 10  srl  %o1, 0x10, %o1
a00a6020:  90 10 20 00  clr  %o0
a00a6024:  94 10 00 19  mov  %i1, %o2
a00a6028:  96 10 20 01  mov  1, %o3
a00a602c:  40 02 82 bd  call  0xa0146b20
a00a6030:  9a 10 20 00  clr  %o5
a00a6034:  d6 0d 21 a1  ldub  [ %l4 + 0x1a1 ], %o3
a00a6038:  80 52 c0 13  umul  %o3, %l3, %g0
a00a603c:  9b 40 00 00  rd  %y, %o5
a00a6040:  91 33 60 03  srl  %o5, 3, %o0
a00a6044:  99 2a 20 02  sll  %o0, 2, %o4
a00a6048:  9e 03 00 08  add  %o4, %o0, %o7
a00a604c:  82 03 c0 0f  add  %o7, %o7, %g1
a00a6050:  92 22 c0 01  sub  %o3, %g1, %o1
a00a6054:  94 0a 60 ff  and  %o1, 0xff, %o2
a00a6058:  9a 02 80 0a  add  %o2, %o2, %o5
a00a605c:  90 03 40 0a  add  %o5, %o2, %o0
a00a6060:  98 02 00 12  add  %o0, %l2, %o4
a00a6064:  9e 03 00 0c  add  %o4, %o4, %o7
a00a6068:  82 03 c0 11  add  %o7, %l1, %g1
a00a606c:  94 00 60 30  add  %g1, 0x30, %o2
a00a6070:  96 04 20 03  add  %l0, 3, %o3
a00a6074:  98 0a a0 ff  and  %o2, 0xff, %o4
a00a6078:  93 2a e0 10  sll  %o3, 0x10, %o1
a00a607c:  93 32 60 10  srl  %o1, 0x10, %o1
a00a6080:  90 10 20 00  clr  %o0
a00a6084:  94 10 00 19  mov  %i1, %o2
a00a6088:  96 10 20 01  mov  1, %o3
a00a608c:  40 02 82 a5  call  0xa0146b20
a00a6090:  9a 10 20 00  clr  %o5
a00a6094:  9a 04 80 12  add  %l2, %l2, %o5
a00a6098:  98 03 40 11  add  %o5, %l1, %o4
a00a609c:  90 04 20 05  add  %l0, 5, %o0
a00a60a0:  96 03 20 6c  add  %o4, 0x6c, %o3
a00a60a4:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00a60a8:  98 0a e0 ff  and  %o3, 0xff, %o4
a00a60ac:  93 33 e0 10  srl  %o7, 0x10, %o1
a00a60b0:  90 10 20 00  clr  %o0
a00a60b4:  94 10 00 19  mov  %i1, %o2
a00a60b8:  96 10 20 01  mov  1, %o3
a00a60bc:  40 02 82 99  call  0xa0146b20
a00a60c0:  9a 10 20 00  clr  %o5
a00a60c4:  c2 0d 21 a2  ldub  [ %l4 + 0x1a2 ], %g1
a00a60c8:  80 50 40 13  umul  %g1, %l3, %g0
a00a60cc:  95 40 00 00  rd  %y, %o2
a00a60d0:  93 32 a0 03  srl  %o2, 3, %o1
a00a60d4:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00a60d8:  90 03 40 0d  add  %o5, %o5, %o0
a00a60dc:  9e 02 00 0d  add  %o0, %o5, %o7
a00a60e0:  98 03 c0 12  add  %o7, %l2, %o4
a00a60e4:  96 03 00 0c  add  %o4, %o4, %o3
a00a60e8:  94 02 c0 11  add  %o3, %l1, %o2
a00a60ec:  82 04 20 07  add  %l0, 7, %g1
a00a60f0:  9a 02 a0 30  add  %o2, 0x30, %o5
a00a60f4:  93 28 60 10  sll  %g1, 0x10, %o1
a00a60f8:  98 0b 60 ff  and  %o5, 0xff, %o4
a00a60fc:  93 32 60 10  srl  %o1, 0x10, %o1
a00a6100:  90 10 20 00  clr  %o0
a00a6104:  94 10 00 19  mov  %i1, %o2
a00a6108:  96 10 20 01  mov  1, %o3
a00a610c:  40 02 82 85  call  0xa0146b20
a00a6110:  9a 10 20 00  clr  %o5
a00a6114:  d4 0d 21 a2  ldub  [ %l4 + 0x1a2 ], %o2
a00a6118:  80 52 80 13  umul  %o2, %l3, %g0
a00a611c:  91 40 00 00  rd  %y, %o0
a00a6120:  9f 32 20 03  srl  %o0, 3, %o7
a00a6124:  99 2b e0 02  sll  %o7, 2, %o4
a00a6128:  96 03 00 0f  add  %o4, %o7, %o3
a00a612c:  82 02 c0 0b  add  %o3, %o3, %g1
a00a6130:  92 22 80 01  sub  %o2, %g1, %o1
a00a6134:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00a6138:  90 03 40 0d  add  %o5, %o5, %o0
a00a613c:  9e 02 00 0d  add  %o0, %o5, %o7
a00a6140:  98 03 c0 12  add  %o7, %l2, %o4
a00a6144:  96 03 00 0c  add  %o4, %o4, %o3
a00a6148:  92 02 c0 11  add  %o3, %l1, %o1
a00a614c:  9a 02 60 30  add  %o1, 0x30, %o5
a00a6150:  94 04 20 09  add  %l0, 9, %o2
a00a6154:  83 2a a0 10  sll  %o2, 0x10, %g1
a00a6158:  98 0b 60 ff  and  %o5, 0xff, %o4
a00a615c:  90 10 20 00  clr  %o0
a00a6160:  93 30 60 10  srl  %g1, 0x10, %o1
a00a6164:  94 10 00 19  mov  %i1, %o2
a00a6168:  96 10 20 01  mov  1, %o3
a00a616c:  40 02 82 6d  call  0xa0146b20
a00a6170:  9a 10 20 00  clr  %o5
a00a6174:  a2 04 60 01  inc  %l1
a00a6178:  90 0c 60 ff  and  %l1, 0xff, %o0
a00a617c:  80 a2 20 01  cmp  %o0, 1
a00a6180:  28 bf ff 98  bleu,a   0xa00a5fe0
a00a6184:  c2 0d 21 a1  ldub  [ %l4 + 0x1a1 ], %g1
a00a6188:  aa 05 60 01  inc  %l5
a00a618c:  a4 0d 60 ff  and  %l5, 0xff, %l2
a00a6190:  80 a4 a0 02  cmp  %l2, 2
a00a6194:  08 bf ff 85  bleu  0xa00a5fa8
a00a6198:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00a619c:  a4 16 e2 90  or  %i3, 0x290, %l2
a00a61a0:  f8 04 a0 a8  ld  [ %l2 + 0xa8 ], %i4
a00a61a4:  2d 00 00 04  sethi  %hi(0x1000), %l6
a00a61a8:  80 8f 00 16  btst  %i4, %l6
a00a61ac:  12 80 01 0d  bne  0xa00a65e0
a00a61b0:  98 16 e2 90  or  %i3, 0x290, %o4
a00a61b4:  f8 03 20 ac  ld  [ %o4 + 0xac ], %i4
a00a61b8:  37 00 10 00  sethi  %hi(0x400000), %i3
a00a61bc:  80 8f 00 1b  btst  %i4, %i3
a00a61c0:  02 80 00 07  be  0xa00a61dc
a00a61c4:  80 a6 20 00  cmp  %i0, 0
a00a61c8:  ea 03 20 a8  ld  [ %o4 + 0xa8 ], %l5
a00a61cc:  80 8d 60 80  btst  0x80, %l5
a00a61d0:  12 80 00 2a  bne  0xa00a6278
a00a61d4:  01 00 00 00  nop
a00a61d8:  80 a6 20 00  cmp  %i0, 0
a00a61dc:  02 80 02 6d  be  0xa00a6b90
a00a61e0:  b0 10 20 01  mov  1, %i0
a00a61e4:  40 02 82 f7  call  0xa0146dc0
a00a61e8:  93 e8 20 00  restore  %g0, 0, %o1
a00a61ec:  80 a0 60 01  cmp  %g1, 1
a00a61f0:  02 80 01 ba  be  0xa00a68d8
a00a61f4:  80 a0 60 02  cmp  %g1, 2
a00a61f8:  ae 10 20 02  mov  2, %l7
a00a61fc:  02 bf ff 31  be  0xa00a5ec0
a00a6200:  b4 10 20 35  mov  0x35, %i2
a00a6204:  80 a0 60 03  cmp  %g1, 3
a00a6208:  02 80 01 b4  be  0xa00a68d8
a00a620c:  01 00 00 00  nop
a00a6210:  f4 0b 61 a5  ldub  [ %o5 + 0x1a5 ], %i2
a00a6214:  ba 06 80 1a  add  %i2, %i2, %i5
a00a6218:  f8 0b 61 a6  ldub  [ %o5 + 0x1a6 ], %i4
a00a621c:  ae 07 40 1a  add  %i5, %i2, %l7
a00a6220:  10 bf ff 28  b  0xa00a5ec0
a00a6224:  b4 07 00 1c  add  %i4, %i4, %i2
a00a6228:  80 a7 40 0c  cmp  %i5, %o4
a00a622c:  04 bf ff 57  ble  0xa00a5f88
a00a6230:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00a6234:  98 0f 20 ff  and  %i4, 0xff, %o4
a00a6238:  a0 03 20 03  add  %o4, 3, %l0
a00a623c:  9a 0e a0 ff  and  %i2, 0xff, %o5
a00a6240:  80 a4 00 0d  cmp  %l0, %o5
a00a6244:  04 bf ff 52  ble  0xa00a5f8c
a00a6248:  13 33 33 33  sethi  %hi(0xcccccc00), %o1
a00a624c:  90 03 60 03  add  %o5, 3, %o0
a00a6250:  80 a2 00 0c  cmp  %o0, %o4
a00a6254:  24 bf ff 4f  ble,a   0xa00a5f90
a00a6258:  b8 0f 20 ff  and  %i4, 0xff, %i4
a00a625c:  da 02 e0 a8  ld  [ %o3 + 0xa8 ], %o5
a00a6260:  33 00 00 04  sethi  %hi(0x1000), %i1
a00a6264:  80 8b 40 19  btst  %o5, %i1
a00a6268:  12 bf ff ce  bne  0xa00a61a0
a00a626c:  a4 16 e2 90  or  %i3, 0x290, %l2
a00a6270:  10 bf ff 48  b  0xa00a5f90
a00a6274:  b8 0f 20 ff  and  %i4, 0xff, %i4
a00a6278:  40 00 ca 30  call  0xa00d8b38
a00a627c:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00a6280:  a7 2a 20 10  sll  %o0, 0x10, %l3
a00a6284:  b3 34 e0 10  srl  %l3, 0x10, %i1
a00a6288:  ec 0c 20 8c  ldub  [ %l0 + 0x8c ], %l6
a00a628c:  80 a6 40 16  cmp  %i1, %l6
a00a6290:  02 bf ff d3  be  0xa00a61dc
a00a6294:  80 a6 20 00  cmp  %i0, 0
a00a6298:  fa 17 bf f6  lduh  [ %fp + -10 ], %i5
a00a629c:  a9 2d e0 10  sll  %l7, 0x10, %l4
a00a62a0:  a2 07 60 08  add  %i5, 8, %l1
a00a62a4:  af 2c 60 10  sll  %l1, 0x10, %l7
a00a62a8:  95 35 20 10  srl  %l4, 0x10, %o2
a00a62ac:  97 35 e0 10  srl  %l7, 0x10, %o3
a00a62b0:  80 a2 80 0b  cmp  %o2, %o3
a00a62b4:  1a 80 01 96  bcc  0xa00a690c
a00a62b8:  a4 02 e0 06  add  %o3, 6, %l2
a00a62bc:  9e 02 a0 08  add  %o2, 8, %o7
a00a62c0:  80 a3 c0 0b  cmp  %o7, %o3
a00a62c4:  16 80 00 03  bge  0xa00a62d0
a00a62c8:  9a 10 20 01  mov  1, %o5
a00a62cc:  9a 10 20 00  clr  %o5
a00a62d0:  80 a2 80 0b  cmp  %o2, %o3
a00a62d4:  98 40 20 00  addx  %g0, 0, %o4
a00a62d8:  80 8b 40 0c  btst  %o5, %o4
a00a62dc:  02 80 00 0b  be  0xa00a6308
a00a62e0:  c2 17 bf f6  lduh  [ %fp + -10 ], %g1
a00a62e4:  82 0e a0 ff  and  %i2, 0xff, %g1
a00a62e8:  80 a0 60 1e  cmp  %g1, 0x1e
a00a62ec:  38 80 00 07  bgu,a   0xa00a6308
a00a62f0:  c2 17 bf f6  lduh  [ %fp + -10 ], %g1
a00a62f4:  b4 00 60 03  add  %g1, 3, %i2
a00a62f8:  9a 10 20 1e  mov  0x1e, %o5
a00a62fc:  80 a3 40 1a  cmp  %o5, %i2
a00a6300:  04 80 00 06  ble  0xa00a6318
a00a6304:  c2 17 bf f6  lduh  [ %fp + -10 ], %g1
a00a6308:  93 28 60 10  sll  %g1, 0x10, %o1
a00a630c:  91 32 60 10  srl  %o1, 0x10, %o0
a00a6310:  40 00 49 74  call  0xa00b88e0
a00a6314:  92 10 20 13  mov  0x13, %o1
a00a6318:  40 00 ca 08  call  0xa00d8b38
a00a631c:  01 00 00 00  nop
a00a6320:  10 bf ff ae  b  0xa00a61d8
a00a6324:  d0 2c 20 8c  stb  %o0, [ %l0 + 0x8c ]
a00a6328:  40 00 3b 56  call  0xa00b5080
a00a632c:  01 00 00 00  nop
a00a6330:  40 00 3b 6a  call  0xa00b50d8
a00a6334:  90 10 20 03  mov  3, %o0	! 0x3
a00a6338:  97 2c 60 10  sll  %l1, 0x10, %o3
a00a633c:  91 32 e0 10  srl  %o3, 0x10, %o0
a00a6340:  92 10 20 3d  mov  0x3d, %o1
a00a6344:  40 00 3b ed  call  0xa00b52f8
a00a6348:  94 10 28 02  mov  0x802, %o2
a00a634c:  94 10 20 00  clr  %o2
a00a6350:  90 10 20 00  clr  %o0
a00a6354:  40 02 80 7e  call  0xa014654c
a00a6358:  92 10 20 00  clr  %o1
a00a635c:  a2 16 e2 90  or  %i3, 0x290, %l1
a00a6360:  d4 04 60 ac  ld  [ %l1 + 0xac ], %o2
a00a6364:  03 00 10 00  sethi  %hi(0x400000), %g1
a00a6368:  80 8a 80 01  btst  %o2, %g1
a00a636c:  12 80 01 d8  bne  0xa00a6acc
a00a6370:  99 2c 20 10  sll  %l0, 0x10, %o4
a00a6374:  de 0c 61 90  ldub  [ %l1 + 0x190 ], %o7
a00a6378:  80 a3 e0 00  cmp  %o7, 0
a00a637c:  12 80 01 69  bne  0xa00a6920
a00a6380:  9e 16 e2 90  or  %i3, 0x290, %o7
a00a6384:  d8 0b e1 a0  ldub  [ %o7 + 0x1a0 ], %o4
a00a6388:  80 a3 20 00  cmp  %o4, 0
a00a638c:  02 80 00 56  be  0xa00a64e4
a00a6390:  aa 16 e2 90  or  %i3, 0x290, %l5
a00a6394:  a0 10 20 00  clr  %l0
a00a6398:  a3 2d a0 10  sll  %l6, 0x10, %l1
a00a639c:  a6 07 00 10  add  %i4, %l0, %l3
a00a63a0:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a63a4:  98 0c e0 ff  and  %l3, 0xff, %o4
a00a63a8:  90 10 20 01  mov  1, %o0
a00a63ac:  92 10 20 00  clr  %o1
a00a63b0:  94 10 27 92  mov  0x792, %o2
a00a63b4:  97 34 60 10  srl  %l1, 0x10, %o3
a00a63b8:  9a 10 20 0c  mov  0xc, %o5
a00a63bc:  40 00 33 ca  call  0xa00b32e4
a00a63c0:  a0 04 20 01  inc  %l0
a00a63c4:  a4 0c 20 ff  and  %l0, 0xff, %l2
a00a63c8:  80 a4 a0 02  cmp  %l2, 2
a00a63cc:  08 bf ff f5  bleu  0xa00a63a0
a00a63d0:  a6 07 00 10  add  %i4, %l0, %l3
a00a63d4:  aa 05 a0 0b  add  %l6, 0xb, %l5
a00a63d8:  a9 2d 60 10  sll  %l5, 0x10, %l4
a00a63dc:  a0 05 a0 01  add  %l6, 1, %l0
a00a63e0:  bb 35 20 10  srl  %l4, 0x10, %i5
a00a63e4:  a9 2c 20 10  sll  %l0, 0x10, %l4
a00a63e8:  ab 34 60 10  srl  %l1, 0x10, %l5
a00a63ec:  a4 10 20 00  clr  %l2
a00a63f0:  a0 10 20 00  clr  %l0
a00a63f4:  27 00 00 2e  sethi  %hi(0xb800), %l3
a00a63f8:  a0 04 00 10  add  %l0, %l0, %l0
a00a63fc:  96 04 00 1c  add  %l0, %i4, %o3
a00a6400:  94 04 20 07  add  %l0, 7, %o2
a00a6404:  82 0a a0 ff  and  %o2, 0xff, %g1
a00a6408:  a2 0a e0 ff  and  %o3, 0xff, %l1
a00a640c:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a00a6410:  90 10 20 00  clr  %o0
a00a6414:  92 10 20 00  clr  %o1
a00a6418:  94 14 e0 0a  or  %l3, 0xa, %o2
a00a641c:  96 10 00 15  mov  %l5, %o3
a00a6420:  98 10 00 11  mov  %l1, %o4
a00a6424:  40 00 33 b0  call  0xa00b32e4
a00a6428:  9a 10 20 01  mov  1, %o5
a00a642c:  92 04 a0 0b  add  %l2, 0xb, %o1
a00a6430:  90 0a 60 ff  and  %o1, 0xff, %o0
a00a6434:  d0 23 a0 5c  st  %o0, [ %sp + 0x5c ]
a00a6438:  90 10 20 01  mov  1, %o0
a00a643c:  92 10 20 00  clr  %o1
a00a6440:  94 14 e0 0a  or  %l3, 0xa, %o2
a00a6444:  97 35 20 10  srl  %l4, 0x10, %o3
a00a6448:  98 10 00 11  mov  %l1, %o4
a00a644c:  40 00 33 a6  call  0xa00b32e4
a00a6450:  9a 10 20 0a  mov  0xa, %o5
a00a6454:  9a 04 20 08  add  %l0, 8, %o5
a00a6458:  b2 0b 60 ff  and  %o5, 0xff, %i1
a00a645c:  f2 23 a0 5c  st  %i1, [ %sp + 0x5c ]
a00a6460:  98 10 00 11  mov  %l1, %o4
a00a6464:  90 10 20 00  clr  %o0
a00a6468:  92 10 20 00  clr  %o1
a00a646c:  94 14 e0 0a  or  %l3, 0xa, %o2
a00a6470:  96 10 00 1d  mov  %i5, %o3
a00a6474:  9a 10 20 01  mov  1, %o5
a00a6478:  40 00 33 9b  call  0xa00b32e4
a00a647c:  a4 04 a0 01  inc  %l2
a00a6480:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00a6484:  80 a4 20 01  cmp  %l0, 1
a00a6488:  28 bf ff dd  bleu,a   0xa00a63fc
a00a648c:  a0 04 00 10  add  %l0, %l0, %l0
a00a6490:  a6 07 20 01  add  %i4, 1, %l3
a00a6494:  a4 0c e0 ff  and  %l3, 0xff, %l2
a00a6498:  9e 10 20 07  mov  7, %o7
a00a649c:  96 10 00 15  mov  %l5, %o3
a00a64a0:  90 10 20 00  clr  %o0
a00a64a4:  92 10 20 00  clr  %o1
a00a64a8:  94 10 28 a2  mov  0x8a2, %o2
a00a64ac:  98 10 00 12  mov  %l2, %o4
a00a64b0:  de 23 a0 5c  st  %o7, [ %sp + 0x5c ]
a00a64b4:  40 00 33 8c  call  0xa00b32e4
a00a64b8:  9a 10 20 01  mov  1, %o5
a00a64bc:  98 10 20 08  mov  8, %o4
a00a64c0:  d8 23 a0 5c  st  %o4, [ %sp + 0x5c ]
a00a64c4:  96 10 00 1d  mov  %i5, %o3
a00a64c8:  98 10 00 12  mov  %l2, %o4
a00a64cc:  90 10 20 00  clr  %o0
a00a64d0:  92 10 20 00  clr  %o1
a00a64d4:  94 10 28 a2  mov  0x8a2, %o2
a00a64d8:  40 00 33 83  call  0xa00b32e4
a00a64dc:  9a 10 20 01  mov  1, %o5
a00a64e0:  aa 16 e2 90  or  %i3, 0x290, %l5
a00a64e4:  e8 05 60 a8  ld  [ %l5 + 0xa8 ], %l4
a00a64e8:  3b 00 00 04  sethi  %hi(0x1000), %i5
a00a64ec:  80 8d 00 1d  btst  %l4, %i5
a00a64f0:  02 bf fe 99  be  0xa00a5f54
a00a64f4:  96 16 e2 90  or  %i3, 0x290, %o3
a00a64f8:  9a 05 e0 07  add  %l7, 7, %o5
a00a64fc:  a3 2b 60 10  sll  %o5, 0x10, %l1
a00a6500:  b3 2d e0 10  sll  %l7, 0x10, %i1
a00a6504:  a9 36 60 10  srl  %i1, 0x10, %l4
a00a6508:  ab 34 60 10  srl  %l1, 0x10, %l5
a00a650c:  a4 10 20 00  clr  %l2
a00a6510:  a0 10 20 00  clr  %l0
a00a6514:  27 00 00 2e  sethi  %hi(0xb800), %l3
a00a6518:  b2 04 00 10  add  %l0, %l0, %i1
a00a651c:  82 06 60 07  add  %i1, 7, %g1
a00a6520:  92 08 60 ff  and  %g1, 0xff, %o1
a00a6524:  94 06 40 1a  add  %i1, %i2, %o2
a00a6528:  ba 0a a0 ff  and  %o2, 0xff, %i5
a00a652c:  d2 23 a0 5c  st  %o1, [ %sp + 0x5c ]
a00a6530:  90 10 20 00  clr  %o0
a00a6534:  92 10 20 00  clr  %o1
a00a6538:  94 14 e0 0a  or  %l3, 0xa, %o2
a00a653c:  96 10 00 14  mov  %l4, %o3
a00a6540:  98 10 00 1d  mov  %i5, %o4
a00a6544:  40 00 33 68  call  0xa00b32e4
a00a6548:  9a 10 20 01  mov  1, %o5
a00a654c:  90 06 60 08  add  %i1, 8, %o0
a00a6550:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00a6554:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a00a6558:  98 10 00 1d  mov  %i5, %o4
a00a655c:  90 10 20 00  clr  %o0
a00a6560:  92 10 20 00  clr  %o1
a00a6564:  94 14 e0 0a  or  %l3, 0xa, %o2
a00a6568:  96 10 00 15  mov  %l5, %o3
a00a656c:  9a 10 20 01  mov  1, %o5
a00a6570:  40 00 33 5d  call  0xa00b32e4
a00a6574:  a4 04 a0 01  inc  %l2
a00a6578:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00a657c:  80 a4 20 01  cmp  %l0, 1
a00a6580:  08 bf ff e7  bleu  0xa00a651c
a00a6584:  b2 04 00 10  add  %l0, %l0, %i1
a00a6588:  9e 06 a0 01  add  %i2, 1, %o7
a00a658c:  98 10 20 07  mov  7, %o4
a00a6590:  a4 0b e0 ff  and  %o7, 0xff, %l2
a00a6594:  d8 23 a0 5c  st  %o4, [ %sp + 0x5c ]
a00a6598:  96 10 00 14  mov  %l4, %o3
a00a659c:  98 10 00 12  mov  %l2, %o4
a00a65a0:  90 10 20 00  clr  %o0
a00a65a4:  92 10 20 00  clr  %o1
a00a65a8:  94 10 28 a2  mov  0x8a2, %o2
a00a65ac:  40 00 33 4e  call  0xa00b32e4
a00a65b0:  9a 10 20 01  mov  1, %o5
a00a65b4:  96 10 20 08  mov  8, %o3
a00a65b8:  d6 23 a0 5c  st  %o3, [ %sp + 0x5c ]
a00a65bc:  96 10 00 15  mov  %l5, %o3
a00a65c0:  98 10 00 12  mov  %l2, %o4
a00a65c4:  90 10 20 00  clr  %o0
a00a65c8:  92 10 20 00  clr  %o1
a00a65cc:  94 10 28 a2  mov  0x8a2, %o2
a00a65d0:  40 00 33 45  call  0xa00b32e4
a00a65d4:  9a 10 20 01  mov  1, %o5
a00a65d8:  10 bf fe 5f  b  0xa00a5f54
a00a65dc:  96 16 e2 90  or  %i3, 0x290, %o3
a00a65e0:  40 00 c9 56  call  0xa00d8b38
a00a65e4:  25 14 7a e1  sethi  %hi(0x51eb8400), %l2
a00a65e8:  91 2a 20 10  sll  %o0, 0x10, %o0
a00a65ec:  ab 32 20 10  srl  %o0, 0x10, %l5
a00a65f0:  b8 14 a1 1f  or  %l2, 0x11f, %i4
a00a65f4:  80 55 40 1c  umul  %l5, %i4, %g0
a00a65f8:  97 40 00 00  rd  %y, %o3
a00a65fc:  15 33 33 33  sethi  %hi(0xcccccc00), %o2
a00a6600:  9e 12 a0 cd  or  %o2, 0xcd, %o7	! 0xcccccccd
a00a6604:  a7 32 e0 05  srl  %o3, 5, %l3
a00a6608:  82 5c e0 64  smul  %l3, 0x64, %g1
a00a660c:  80 55 40 0f  umul  %l5, %o7, %g0
a00a6610:  ad 40 00 00  rd  %y, %l6
a00a6614:  9b 35 a0 03  srl  %l6, 3, %o5
a00a6618:  92 25 40 01  sub  %l5, %g1, %o1
a00a661c:  a1 2a 60 10  sll  %o1, 0x10, %l0
a00a6620:  99 2b 60 02  sll  %o5, 2, %o4
a00a6624:  ba 03 00 0d  add  %o4, %o5, %i5
a00a6628:  a3 34 20 10  srl  %l0, 0x10, %l1
a00a662c:  a8 07 40 1d  add  %i5, %i5, %l4
a00a6630:  80 54 40 0f  umul  %l1, %o7, %g0
a00a6634:  b3 40 00 00  rd  %y, %i1
a00a6638:  80 a5 60 63  cmp  %l5, 0x63
a00a663c:  bb 36 60 03  srl  %i1, 3, %i5
a00a6640:  08 80 00 6e  bleu  0xa00a67f8
a00a6644:  b8 25 40 14  sub  %l5, %l4, %i4
a00a6648:  a8 0c e0 ff  and  %l3, 0xff, %l4
a00a664c:  aa 05 00 14  add  %l4, %l4, %l5
a00a6650:  a6 05 e0 01  add  %l7, 1, %l3
a00a6654:  ac 05 40 14  add  %l5, %l4, %l6
a00a6658:  a9 2c e0 10  sll  %l3, 0x10, %l4
a00a665c:  a6 10 20 00  clr  %l3
a00a6660:  a2 10 20 00  clr  %l1
a00a6664:  aa 0e a0 ff  and  %i2, 0xff, %l5
a00a6668:  9a 0c e0 ff  and  %l3, 0xff, %o5
a00a666c:  a0 05 40 0d  add  %l5, %o5, %l0
a00a6670:  99 2c 20 10  sll  %l0, 0x10, %o4
a00a6674:  93 33 20 10  srl  %o4, 0x10, %o1
a00a6678:  1f 00 00 2e  sethi  %hi(0xb800), %o7
a00a667c:  b2 05 80 11  add  %l6, %l1, %i1
a00a6680:  96 13 e0 0a  or  %o7, 0xa, %o3
a00a6684:  91 35 20 10  srl  %l4, 0x10, %o0
a00a6688:  94 10 20 02  mov  2, %o2
a00a668c:  40 02 80 fd  call  0xa0146a80
a00a6690:  98 10 20 00  clr  %o4
a00a6694:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00a6698:  a4 06 40 19  add  %i1, %i1, %l2
a00a669c:  a2 10 20 00  clr  %l1
a00a66a0:  9e 0c 60 ff  and  %l1, 0xff, %o7
a00a66a4:  b2 03 c0 17  add  %o7, %l7, %i1
a00a66a8:  90 06 60 01  add  %i1, 1, %o0
a00a66ac:  96 04 80 11  add  %l2, %l1, %o3
a00a66b0:  95 2a 20 10  sll  %o0, 0x10, %o2
a00a66b4:  82 02 e0 30  add  %o3, 0x30, %g1
a00a66b8:  93 32 a0 10  srl  %o2, 0x10, %o1
a00a66bc:  98 08 60 ff  and  %g1, 0xff, %o4
a00a66c0:  90 10 20 00  clr  %o0
a00a66c4:  95 34 20 10  srl  %l0, 0x10, %o2
a00a66c8:  96 10 20 01  mov  1, %o3
a00a66cc:  40 02 81 15  call  0xa0146b20
a00a66d0:  9a 10 20 00  clr  %o5
a00a66d4:  a2 04 60 01  inc  %l1
a00a66d8:  92 0c 60 ff  and  %l1, 0xff, %o1
a00a66dc:  80 a2 60 01  cmp  %o1, 1
a00a66e0:  08 bf ff f1  bleu  0xa00a66a4
a00a66e4:  9e 0c 60 ff  and  %l1, 0xff, %o7
a00a66e8:  a6 04 e0 01  inc  %l3
a00a66ec:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00a66f0:  80 a4 60 02  cmp  %l1, 2
a00a66f4:  28 bf ff de  bleu,a   0xa00a666c
a00a66f8:  9a 0c e0 ff  and  %l3, 0xff, %o5
a00a66fc:  a2 0f 60 ff  and  %i5, 0xff, %l1
a00a6700:  a8 0f 20 ff  and  %i4, 0xff, %l4
a00a6704:  ba 04 40 11  add  %l1, %l1, %i5
a00a6708:  b8 07 40 11  add  %i5, %l1, %i4
a00a670c:  a6 05 e0 03  add  %l7, 3, %l3
a00a6710:  9e 05 00 14  add  %l4, %l4, %o7
a00a6714:  ba 03 c0 14  add  %o7, %l4, %i5
a00a6718:  ad 2c e0 10  sll  %l3, 0x10, %l6
a00a671c:  b2 10 20 00  clr  %i1
a00a6720:  a2 10 20 00  clr  %l1
a00a6724:  94 0e 60 ff  and  %i1, 0xff, %o2
a00a6728:  92 05 40 0a  add  %l5, %o2, %o1
a00a672c:  83 2a 60 10  sll  %o1, 0x10, %g1
a00a6730:  a1 30 60 10  srl  %g1, 0x10, %l0
a00a6734:  25 00 00 2e  sethi  %hi(0xb800), %l2
a00a6738:  96 14 a0 0a  or  %l2, 0xa, %o3	! 0xb80a
a00a673c:  98 10 20 00  clr  %o4
a00a6740:  91 35 a0 10  srl  %l6, 0x10, %o0
a00a6744:  92 10 00 10  mov  %l0, %o1
a00a6748:  40 02 80 ce  call  0xa0146a80
a00a674c:  94 10 20 04  mov  4, %o2
a00a6750:  98 07 40 11  add  %i5, %l1, %o4
a00a6754:  9a 07 00 11  add  %i4, %l1, %o5
a00a6758:  a4 10 00 10  mov  %l0, %l2
a00a675c:  a8 03 40 0d  add  %o5, %o5, %l4
a00a6760:  a6 03 00 0c  add  %o4, %o4, %l3
a00a6764:  a2 10 20 00  clr  %l1
a00a6768:  90 0c 60 ff  and  %l1, 0xff, %o0
a00a676c:  a0 02 00 17  add  %o0, %l7, %l0
a00a6770:  94 05 00 11  add  %l4, %l1, %o2
a00a6774:  96 04 20 03  add  %l0, 3, %o3
a00a6778:  82 02 a0 30  add  %o2, 0x30, %g1
a00a677c:  93 2a e0 10  sll  %o3, 0x10, %o1
a00a6780:  98 08 60 ff  and  %g1, 0xff, %o4
a00a6784:  93 32 60 10  srl  %o1, 0x10, %o1
a00a6788:  90 10 20 00  clr  %o0
a00a678c:  94 10 00 12  mov  %l2, %o2
a00a6790:  96 10 20 01  mov  1, %o3
a00a6794:  40 02 80 e3  call  0xa0146b20
a00a6798:  9a 10 20 00  clr  %o5
a00a679c:  98 04 c0 11  add  %l3, %l1, %o4
a00a67a0:  9a 04 20 05  add  %l0, 5, %o5
a00a67a4:  90 03 20 30  add  %o4, 0x30, %o0
a00a67a8:  9f 2b 60 10  sll  %o5, 0x10, %o7
a00a67ac:  98 0a 20 ff  and  %o0, 0xff, %o4
a00a67b0:  96 10 20 01  mov  1, %o3
a00a67b4:  93 33 e0 10  srl  %o7, 0x10, %o1
a00a67b8:  90 10 20 00  clr  %o0
a00a67bc:  94 10 00 12  mov  %l2, %o2
a00a67c0:  40 02 80 d8  call  0xa0146b20
a00a67c4:  9a 10 20 00  clr  %o5
a00a67c8:  a2 04 60 01  inc  %l1
a00a67cc:  96 0c 60 ff  and  %l1, 0xff, %o3
a00a67d0:  80 a2 e0 01  cmp  %o3, 1
a00a67d4:  08 bf ff e6  bleu  0xa00a676c
a00a67d8:  90 0c 60 ff  and  %l1, 0xff, %o0
a00a67dc:  b2 06 60 01  inc  %i1
a00a67e0:  a2 0e 60 ff  and  %i1, 0xff, %l1
a00a67e4:  80 a4 60 02  cmp  %l1, 2
a00a67e8:  08 bf ff d0  bleu  0xa00a6728
a00a67ec:  94 0e 60 ff  and  %i1, 0xff, %o2
a00a67f0:  10 bf fe 71  b  0xa00a61b4
a00a67f4:  98 16 e2 90  or  %i3, 0x290, %o4
a00a67f8:  a2 05 e0 01  add  %l7, 1, %l1
a00a67fc:  a9 2c 60 10  sll  %l1, 0x10, %l4
a00a6800:  a6 10 20 00  clr  %l3
a00a6804:  a2 10 20 00  clr  %l1
a00a6808:  aa 0e a0 ff  and  %i2, 0xff, %l5
a00a680c:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00a6810:  ac 05 40 10  add  %l5, %l0, %l6
a00a6814:  99 2d a0 10  sll  %l6, 0x10, %o4
a00a6818:  25 00 00 2e  sethi  %hi(0xb800), %l2
a00a681c:  93 33 20 10  srl  %o4, 0x10, %o1
a00a6820:  96 14 a3 0a  or  %l2, 0x30a, %o3
a00a6824:  91 35 20 10  srl  %l4, 0x10, %o0
a00a6828:  94 10 20 02  mov  2, %o2
a00a682c:  98 10 20 00  clr  %o4
a00a6830:  40 02 80 94  call  0xa0146a80
a00a6834:  a4 04 40 11  add  %l1, %l1, %l2
a00a6838:  a1 2d a0 10  sll  %l6, 0x10, %l0
a00a683c:  a2 10 20 00  clr  %l1
a00a6840:  b2 0c 60 ff  and  %l1, 0xff, %i1
a00a6844:  90 06 40 17  add  %i1, %l7, %o0
a00a6848:  96 02 20 01  add  %o0, 1, %o3
a00a684c:  94 04 80 11  add  %l2, %l1, %o2
a00a6850:  82 02 a0 30  add  %o2, 0x30, %g1
a00a6854:  93 2a e0 10  sll  %o3, 0x10, %o1
a00a6858:  9a 10 20 00  clr  %o5
a00a685c:  93 32 60 10  srl  %o1, 0x10, %o1
a00a6860:  98 08 60 ff  and  %g1, 0xff, %o4
a00a6864:  90 10 20 00  clr  %o0
a00a6868:  95 34 20 10  srl  %l0, 0x10, %o2
a00a686c:  40 02 80 ad  call  0xa0146b20
a00a6870:  96 10 20 01  mov  1, %o3
a00a6874:  a2 04 60 01  inc  %l1
a00a6878:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00a687c:  80 a3 60 01  cmp  %o5, 1
a00a6880:  08 bf ff f1  bleu  0xa00a6844
a00a6884:  b2 0c 60 ff  and  %l1, 0xff, %i1
a00a6888:  a6 04 e0 01  inc  %l3
a00a688c:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00a6890:  80 a4 60 02  cmp  %l1, 2
a00a6894:  08 bf ff df  bleu  0xa00a6810
a00a6898:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00a689c:  10 bf ff 99  b  0xa00a6700
a00a68a0:  a2 0f 60 ff  and  %i5, 0xff, %l1
a00a68a4:  40 02 86 b6  call  0xa014837c
a00a68a8:  90 10 20 00  clr  %o0
a00a68ac:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00a68b0:  99 33 e0 10  srl  %o7, 0x10, %o4
a00a68b4:  17 0a aa aa  sethi  %hi(0x2aaaa800), %o3
a00a68b8:  92 03 3e b0  add  %o4, -336, %o1
a00a68bc:  94 12 e2 ab  or  %o3, 0x2ab, %o2
a00a68c0:  80 5a 40 0a  smul  %o1, %o2, %g0
a00a68c4:  83 40 00 00  rd  %y, %g1
a00a68c8:  9b 38 60 02  sra  %g1, 2, %o5
a00a68cc:  91 3a 60 1f  sra  %o1, 0x1f, %o0
a00a68d0:  10 bf fd 90  b  0xa00a5f10
a00a68d4:  ac 23 40 08  sub  %o5, %o0, %l6
a00a68d8:  40 02 86 a9  call  0xa014837c
a00a68dc:  90 10 20 00  clr  %o0
a00a68e0:  b3 2a 20 10  sll  %o0, 0x10, %i1
a00a68e4:  af 36 60 10  srl  %i1, 0x10, %l7
a00a68e8:  2d 0a aa aa  sethi  %hi(0x2aaaa800), %l6
a00a68ec:  a6 05 ff 10  add  %l7, -240, %l3
a00a68f0:  aa 15 a2 ab  or  %l6, 0x2ab, %l5
a00a68f4:  80 5c c0 15  smul  %l3, %l5, %g0
a00a68f8:  a9 40 00 00  rd  %y, %l4
a00a68fc:  a5 3d 20 02  sra  %l4, 2, %l2
a00a6900:  a1 3c e0 1f  sra  %l3, 0x1f, %l0
a00a6904:  10 bf fd 6f  b  0xa00a5ec0
a00a6908:  ae 24 80 10  sub  %l2, %l0, %l7
a00a690c:  80 a2 80 12  cmp  %o2, %l2
a00a6910:  06 bf fe 76  bl  0xa00a62e8
a00a6914:  82 0e a0 ff  and  %i2, 0xff, %g1
a00a6918:  10 bf fe 6a  b  0xa00a62c0
a00a691c:  9e 02 a0 08  add  %o2, 8, %o7
a00a6920:  90 10 20 00  clr  %o0
a00a6924:  40 02 81 27  call  0xa0146dc0
a00a6928:  92 10 20 01  mov  1, %o1
a00a692c:  90 10 20 04  mov  4, %o0
a00a6930:  40 02 7e 5a  call  0xa0146298
a00a6934:  92 10 20 01  mov  1, %o1
a00a6938:  90 10 20 18  mov  0x18, %o0
a00a693c:  92 10 20 24  mov  0x24, %o1
a00a6940:  40 02 7e 85  call  0xa0146354
a00a6944:  94 10 20 01  mov  1, %o2
a00a6948:  90 10 20 08  mov  8, %o0
a00a694c:  92 10 20 00  clr  %o1
a00a6950:  40 02 80 bc  call  0xa0146c40
a00a6954:  94 10 20 01  mov  1, %o2
a00a6958:  96 10 20 00  clr  %o3
a00a695c:  98 10 20 01  mov  1, %o4
a00a6960:  90 10 20 00  clr  %o0
a00a6964:  92 10 20 00  clr  %o1
a00a6968:  40 02 7f 38  call  0xa0146648
a00a696c:  94 10 20 00  clr  %o2
a00a6970:  90 10 20 04  mov  4, %o0
a00a6974:  92 10 20 03  mov  3, %o1
a00a6978:  40 02 7d f1  call  0xa014613c
a00a697c:  94 10 20 01  mov  1, %o2
a00a6980:  94 10 20 01  mov  1, %o2
a00a6984:  d0 0c 60 0d  ldub  [ %l1 + 0xd ], %o0
a00a6988:  40 02 7e e4  call  0xa0146518
a00a698c:  d2 0c 60 0e  ldub  [ %l1 + 0xe ], %o1
a00a6990:  92 10 20 01  mov  1, %o1
a00a6994:  40 02 80 47  call  0xa0146ab0
a00a6998:  90 10 27 92  mov  0x792, %o0
a00a699c:  40 02 7d db  call  0xa0146108
a00a69a0:  90 10 20 01  mov  1, %o0
a00a69a4:  d0 14 61 ac  lduh  [ %l1 + 0x1ac ], %o0
a00a69a8:  d2 14 61 ae  lduh  [ %l1 + 0x1ae ], %o1
a00a69ac:  40 02 7e e8  call  0xa014654c
a00a69b0:  94 10 20 01  mov  1, %o2
a00a69b4:  fa 0c 61 90  ldub  [ %l1 + 0x190 ], %i5
a00a69b8:  a2 07 7f ff  add  %i5, -1, %l1
a00a69bc:  80 5c 40 12  smul  %l1, %l2, %g0
a00a69c0:  ab 40 00 00  rd  %y, %l5
a00a69c4:  b3 3c 60 1f  sra  %l1, 0x1f, %i1
a00a69c8:  a8 25 40 19  sub  %l5, %i1, %l4
a00a69cc:  a6 05 00 14  add  %l4, %l4, %l3
a00a69d0:  a4 04 c0 14  add  %l3, %l4, %l2
a00a69d4:  a0 04 80 12  add  %l2, %l2, %l0
a00a69d8:  96 a4 40 10  subcc  %l1, %l0, %o3
a00a69dc:  02 80 00 42  be  0xa00a6ae4
a00a69e0:  80 a2 e0 01  cmp  %o3, 1
a00a69e4:  02 80 00 5b  be  0xa00a6b50
a00a69e8:  80 a2 e0 02  cmp  %o3, 2
a00a69ec:  02 80 00 55  be  0xa00a6b40
a00a69f0:  80 a2 e0 03  cmp  %o3, 3
a00a69f4:  02 80 00 5b  be  0xa00a6b60
a00a69f8:  80 a2 e0 04  cmp  %o3, 4
a00a69fc:  02 80 00 61  be  0xa00a6b80
a00a6a00:  80 a2 e0 05  cmp  %o3, 5
a00a6a04:  02 80 00 5b  be  0xa00a6b70
a00a6a08:  01 00 00 00  nop
a00a6a0c:  9a 16 e2 90  or  %i3, 0x290, %o5
a00a6a10:  c2 0b 61 7b  ldub  [ %o5 + 0x17b ], %g1
a00a6a14:  80 a0 60 01  cmp  %g1, 1
a00a6a18:  02 80 00 37  be  0xa00a6af4
a00a6a1c:  80 a0 60 00  cmp  %g1, 0
a00a6a20:  12 80 00 44  bne  0xa00a6b30
a00a6a24:  a0 10 20 00  clr  %l0
a00a6a28:  23 00 00 06  sethi  %hi(0x1800), %l1
a00a6a2c:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a6a30:  90 10 20 00  clr  %o0
a00a6a34:  94 10 20 04  mov  4, %o2
a00a6a38:  96 14 60 02  or  %l1, 2, %o3
a00a6a3c:  40 02 80 11  call  0xa0146a80
a00a6a40:  98 10 20 01  mov  1, %o4
a00a6a44:  a0 04 20 01  inc  %l0
a00a6a48:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a6a4c:  80 a2 60 02  cmp  %o1, 2
a00a6a50:  08 bf ff f9  bleu  0xa00a6a34
a00a6a54:  90 10 20 00  clr  %o0
a00a6a58:  a6 10 20 00  clr  %l3
a00a6a5c:  98 10 20 00  clr  %o4
a00a6a60:  82 0c e0 ff  and  %l3, 0xff, %g1
a00a6a64:  a5 28 60 10  sll  %g1, 0x10, %l2
a00a6a68:  a3 2b 20 02  sll  %o4, 2, %l1
a00a6a6c:  a0 10 20 00  clr  %l0
a00a6a70:  96 04 40 10  add  %l1, %l0, %o3
a00a6a74:  98 0a e0 ff  and  %o3, 0xff, %o4
a00a6a78:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a6a7c:  95 34 a0 10  srl  %l2, 0x10, %o2
a00a6a80:  90 10 20 00  clr  %o0
a00a6a84:  96 10 20 01  mov  1, %o3
a00a6a88:  40 02 80 26  call  0xa0146b20
a00a6a8c:  9a 10 20 01  mov  1, %o5
a00a6a90:  a0 04 20 01  inc  %l0
a00a6a94:  94 0c 20 ff  and  %l0, 0xff, %o2
a00a6a98:  80 a2 a0 03  cmp  %o2, 3
a00a6a9c:  08 bf ff f6  bleu  0xa00a6a74
a00a6aa0:  96 04 40 10  add  %l1, %l0, %o3
a00a6aa4:  a6 04 e0 01  inc  %l3
a00a6aa8:  98 0c e0 ff  and  %l3, 0xff, %o4
a00a6aac:  80 a3 20 02  cmp  %o4, 2
a00a6ab0:  08 bf ff ed  bleu  0xa00a6a64
a00a6ab4:  82 0c e0 ff  and  %l3, 0xff, %g1
a00a6ab8:  90 10 20 01  mov  1, %o0
a00a6abc:  40 02 80 c1  call  0xa0146dc0
a00a6ac0:  92 10 20 01  mov  1, %o1
a00a6ac4:  10 bf fe 30  b  0xa00a6384
a00a6ac8:  9e 16 e2 90  or  %i3, 0x290, %o7
a00a6acc:  91 33 20 10  srl  %o4, 0x10, %o0
a00a6ad0:  92 10 20 13  mov  0x13, %o1
a00a6ad4:  7f ff fb 8d  call  0xa00a5908
a00a6ad8:  94 10 20 01  mov  1, %o2
a00a6adc:  10 bf fe 27  b  0xa00a6378
a00a6ae0:  de 0c 61 90  ldub  [ %l1 + 0x190 ], %o7
a00a6ae4:  7f ff f0 0e  call  0xa00a2b1c
a00a6ae8:  01 00 00 00  nop
a00a6aec:  10 bf ff c9  b  0xa00a6a10
a00a6af0:  9a 16 e2 90  or  %i3, 0x290, %o5
a00a6af4:  a0 10 20 00  clr  %l0
a00a6af8:  23 00 00 05  sethi  %hi(0x1400), %l1
a00a6afc:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a6b00:  90 10 20 00  clr  %o0
a00a6b04:  94 10 20 04  mov  4, %o2
a00a6b08:  96 14 63 02  or  %l1, 0x302, %o3
a00a6b0c:  40 02 7f dd  call  0xa0146a80
a00a6b10:  98 10 20 01  mov  1, %o4
a00a6b14:  a0 04 20 01  inc  %l0
a00a6b18:  90 0c 20 ff  and  %l0, 0xff, %o0
a00a6b1c:  80 a2 20 02  cmp  %o0, 2
a00a6b20:  08 bf ff f8  bleu  0xa00a6b00
a00a6b24:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a6b28:  10 bf ff cd  b  0xa00a6a5c
a00a6b2c:  a6 10 20 00  clr  %l3
a00a6b30:  40 00 4d 95  call  0xa00ba184
a00a6b34:  90 10 20 01  mov  1, %o0
a00a6b38:  10 bf ff c9  b  0xa00a6a5c
a00a6b3c:  a6 10 20 00  clr  %l3
a00a6b40:  7f ff f0 07  call  0xa00a2b5c
a00a6b44:  01 00 00 00  nop
a00a6b48:  10 bf ff b2  b  0xa00a6a10
a00a6b4c:  9a 16 e2 90  or  %i3, 0x290, %o5
a00a6b50:  7f ff ef fb  call  0xa00a2b3c
a00a6b54:  01 00 00 00  nop
a00a6b58:  10 bf ff ae  b  0xa00a6a10
a00a6b5c:  9a 16 e2 90  or  %i3, 0x290, %o5
a00a6b60:  7f ff f0 07  call  0xa00a2b7c
a00a6b64:  01 00 00 00  nop
a00a6b68:  10 bf ff aa  b  0xa00a6a10
a00a6b6c:  9a 16 e2 90  or  %i3, 0x290, %o5
a00a6b70:  7f ff f0 13  call  0xa00a2bbc
a00a6b74:  01 00 00 00  nop
a00a6b78:  10 bf ff a6  b  0xa00a6a10
a00a6b7c:  9a 16 e2 90  or  %i3, 0x290, %o5
a00a6b80:  7f ff f0 07  call  0xa00a2b9c
a00a6b84:  01 00 00 00  nop
a00a6b88:  10 bf ff a2  b  0xa00a6a10
a00a6b8c:  9a 16 e2 90  or  %i3, 0x290, %o5
a00a6b90:  81 c7 e0 08  ret
a00a6b94:  81 e8 00 00  restore
