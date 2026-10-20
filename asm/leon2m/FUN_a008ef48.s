# leon2m FUN_a008ef48 0xa008ef48-0xa008f354 (1036 bytes)
a008ef48:  9d e3 bf 98  save  %sp, -104, %sp
a008ef4c:  29 2a 00 b4  sethi  %hi(0xa802d000), %l4
a008ef50:  a0 15 22 90  or  %l4, 0x290, %l0	! 0xa802d290
a008ef54:  27 00 04 20  sethi  %hi(0x108000), %l3
a008ef58:  e2 0c 20 09  ldub  [ %l0 + 9 ], %l1
a008ef5c:  40 01 40 85  call  0xa00df170
a008ef60:  90 14 e0 a8  or  %l3, 0xa8, %o0
a008ef64:  96 10 20 00  clr  %o3
a008ef68:  98 10 20 01  mov  1, %o4
a008ef6c:  90 10 20 00  clr  %o0
a008ef70:  92 10 20 00  clr  %o1
a008ef74:  40 02 dc 1d  call  0xa0145fe8
a008ef78:  94 10 20 00  clr  %o2
a008ef7c:  94 10 21 00  mov  0x100, %o2
a008ef80:  92 10 21 00  mov  0x100, %o1
a008ef84:  40 02 dc 0f  call  0xa0145fc0
a008ef88:  90 10 21 00  mov  0x100, %o0
a008ef8c:  40 02 af 9d  call  0xa013ae00
a008ef90:  90 10 20 80  mov  0x80, %o0
a008ef94:  a4 10 20 64  mov  0x64, %l2
a008ef98:  40 01 27 4f  call  0xa00d8cd4
a008ef9c:  e4 2c 20 09  stb  %l2, [ %l0 + 9 ]
a008efa0:  40 00 08 0e  call  0xa0090fd8
a008efa4:  e2 2c 20 09  stb  %l1, [ %l0 + 9 ]
a008efa8:  90 10 20 03  mov  3, %o0
a008efac:  40 02 dc bb  call  0xa0146298
a008efb0:  92 10 20 00  clr  %o1
a008efb4:  1f 2a 00 90  sethi  %hi(0xa8024000), %o7
a008efb8:  90 13 e0 78  or  %o7, 0x78, %o0	! 0xa8024078
a008efbc:  40 02 dc 7b  call  0xa01461a8
a008efc0:  92 10 20 00  clr  %o1
a008efc4:  94 10 20 02  mov  2, %o2
a008efc8:  90 10 20 7f  mov  0x7f, %o0
a008efcc:  40 00 98 cb  call  0xa00b52f8
a008efd0:  92 10 20 18  mov  0x18, %o1
a008efd4:  90 10 20 03  mov  3, %o0
a008efd8:  40 02 dc b0  call  0xa0146298
a008efdc:  92 10 20 00  clr  %o1
a008efe0:  92 10 20 18  mov  0x18, %o1
a008efe4:  40 02 dc 6c  call  0xa0146194
a008efe8:  90 10 20 7f  mov  0x7f, %o0
a008efec:  99 2a 20 10  sll  %o0, 0x10, %o4
a008eff0:  93 33 20 10  srl  %o4, 0x10, %o1
a008eff4:  94 10 20 00  clr  %o2
a008eff8:  40 02 dc de  call  0xa0146370
a008effc:  90 10 20 00  clr  %o0
a008f000:  92 10 20 18  mov  0x18, %o1
a008f004:  40 02 dc 64  call  0xa0146194
a008f008:  90 10 20 7f  mov  0x7f, %o0
a008f00c:  97 2a 20 10  sll  %o0, 0x10, %o3
a008f010:  95 32 e0 10  srl  %o3, 0x10, %o2
a008f014:  92 02 a8 f0  add  %o2, 0x8f0, %o1
a008f018:  90 10 20 01  mov  1, %o0
a008f01c:  40 02 dc d5  call  0xa0146370
a008f020:  94 10 20 00  clr  %o2
a008f024:  11 2a 00 90  sethi  %hi(0xa8024000), %o0
a008f028:  92 12 20 98  or  %o0, 0x98, %o1	! 0xa8024098
a008f02c:  90 10 20 01  mov  1, %o0
a008f030:  40 02 dc 6b  call  0xa01461dc
a008f034:  94 10 20 00  clr  %o2
a008f038:  13 2a 00 90  sethi  %hi(0xa8024000), %o1
a008f03c:  92 12 60 8c  or  %o1, 0x8c, %o1	! 0xa802408c
a008f040:  90 10 20 01  mov  1, %o0
a008f044:  40 02 dc 66  call  0xa01461dc
a008f048:  94 10 20 00  clr  %o2
a008f04c:  90 10 21 0f  mov  0x10f, %o0
a008f050:  92 10 20 cf  mov  0xcf, %o1
a008f054:  40 02 dd 3e  call  0xa014654c
a008f058:  94 10 20 00  clr  %o2
a008f05c:  90 10 20 01  mov  1, %o0
a008f060:  92 10 20 00  clr  %o1
a008f064:  40 02 dc e5  call  0xa01463f8
a008f068:  94 10 20 00  clr  %o2
a008f06c:  03 00 04 13  sethi  %hi(0x104c00), %g1
a008f070:  1b 00 04 07  sethi  %hi(0x101c00), %o5
a008f074:  a4 10 61 00  or  %g1, 0x100, %l2
a008f078:  a2 13 62 52  or  %o5, 0x252, %l1
a008f07c:  10 80 00 0d  b  0xa008f0b0
a008f080:  a0 10 20 00  clr  %l0
a008f084:  d2 14 40 0d  lduh  [ %l1 + %o5 ], %o1
a008f088:  da 0c 80 01  ldub  [ %l2 + %g1 ], %o5
a008f08c:  92 0a 60 ff  and  %o1, 0xff, %o1
a008f090:  40 02 dc ff  call  0xa014648c
a008f094:  95 2b 60 08  sll  %o5, 8, %o2
a008f098:  96 04 20 01  add  %l0, 1, %o3
a008f09c:  9f 2a e0 10  sll  %o3, 0x10, %o7
a008f0a0:  99 33 e0 10  srl  %o7, 0x10, %o4
a008f0a4:  80 a3 2b e8  cmp  %o4, 0xbe8
a008f0a8:  1a 80 00 17  bcc  0xa008f104
a008f0ac:  a0 10 00 0b  mov  %o3, %l0
a008f0b0:  ab 2c 20 10  sll  %l0, 0x10, %l5
a008f0b4:  83 35 60 10  srl  %l5, 0x10, %g1
a008f0b8:  9a 00 40 01  add  %g1, %g1, %o5
a008f0bc:  90 10 20 01  mov  1, %o0
a008f0c0:  80 a0 66 73  cmp  %g1, 0x673
a008f0c4:  18 bf ff f0  bgu  0xa008f084
a008f0c8:  96 10 20 00  clr  %o3
a008f0cc:  d4 0c 80 01  ldub  [ %l2 + %g1 ], %o2
a008f0d0:  d0 14 40 0d  lduh  [ %l1 + %o5 ], %o0
a008f0d4:  83 2a a0 08  sll  %o2, 8, %g1
a008f0d8:  92 0a 20 ff  and  %o0, 0xff, %o1
a008f0dc:  96 10 20 00  clr  %o3
a008f0e0:  94 10 60 08  or  %g1, 8, %o2
a008f0e4:  40 02 dc ea  call  0xa014648c
a008f0e8:  90 10 20 01  mov  1, %o0
a008f0ec:  96 04 20 01  add  %l0, 1, %o3
a008f0f0:  9f 2a e0 10  sll  %o3, 0x10, %o7
a008f0f4:  99 33 e0 10  srl  %o7, 0x10, %o4
a008f0f8:  80 a3 2b e8  cmp  %o4, 0xbe8
a008f0fc:  0a bf ff ed  bcs  0xa008f0b0
a008f100:  a0 10 00 0b  mov  %o3, %l0
a008f104:  96 10 20 4a  mov  0x4a, %o3
a008f108:  98 10 20 00  clr  %o4
a008f10c:  94 10 20 06  mov  6, %o2
a008f110:  90 10 20 1f  mov  0x1f, %o0
a008f114:  40 02 dd 4d  call  0xa0146648
a008f118:  92 10 20 56  mov  0x56, %o1
a008f11c:  90 10 20 03  mov  3, %o0
a008f120:  40 02 dc 5e  call  0xa0146298
a008f124:  92 10 20 01  mov  1, %o1
a008f128:  27 2a 00 90  sethi  %hi(0xa8024000), %l3
a008f12c:  90 14 e0 4c  or  %l3, 0x4c, %o0	! 0xa802404c
a008f130:  40 02 dc 1e  call  0xa01461a8
a008f134:  92 10 20 01  mov  1, %o1
a008f138:  90 10 20 00  clr  %o0
a008f13c:  40 02 df 21  call  0xa0146dc0
a008f140:  92 10 20 01  mov  1, %o1
a008f144:  90 10 20 08  mov  8, %o0
a008f148:  92 10 20 00  clr  %o1
a008f14c:  40 02 de bd  call  0xa0146c40
a008f150:  94 10 20 01  mov  1, %o2
a008f154:  94 10 20 01  mov  1, %o2
a008f158:  90 10 20 3f  mov  0x3f, %o0
a008f15c:  40 02 db f8  call  0xa014613c
a008f160:  92 10 20 0a  mov  0xa, %o1
a008f164:  92 10 20 01  mov  1, %o1
a008f168:  40 02 de 52  call  0xa0146ab0
a008f16c:  90 10 20 02  mov  2, %o0
a008f170:  40 02 db e6  call  0xa0146108
a008f174:  90 10 20 01  mov  1, %o0
a008f178:  94 10 20 01  mov  1, %o2
a008f17c:  90 10 21 36  mov  0x136, %o0
a008f180:  40 02 dc f3  call  0xa014654c
a008f184:  92 10 26 e5  mov  0x6e5, %o1
a008f188:  90 10 20 03  mov  3, %o0
a008f18c:  40 02 dc 43  call  0xa0146298
a008f190:  92 10 20 01  mov  1, %o1
a008f194:  92 10 20 0a  mov  0xa, %o1
a008f198:  40 02 db ff  call  0xa0146194
a008f19c:  90 10 20 3f  mov  0x3f, %o0
a008f1a0:  a5 2a 20 10  sll  %o0, 0x10, %l2
a008f1a4:  93 34 a0 10  srl  %l2, 0x10, %o1
a008f1a8:  90 10 20 00  clr  %o0
a008f1ac:  40 02 dc 71  call  0xa0146370
a008f1b0:  94 10 20 01  mov  1, %o2
a008f1b4:  23 2a 00 90  sethi  %hi(0xa8024000), %l1
a008f1b8:  92 14 60 6c  or  %l1, 0x6c, %o1	! 0xa802406c
a008f1bc:  90 10 20 01  mov  1, %o0
a008f1c0:  94 10 20 01  mov  1, %o2
a008f1c4:  40 02 dc 06  call  0xa01461dc
a008f1c8:  21 00 04 01  sethi  %hi(0x100400), %l0
a008f1cc:  a8 14 21 54  or  %l0, 0x154, %l4	! 0x100554
a008f1d0:  aa 10 20 00  clr  %l5
a008f1d4:  a4 10 20 00  clr  %l2
a008f1d8:  9b 2c a0 06  sll  %l2, 6, %o5
a008f1dc:  a6 23 40 12  sub  %o5, %l2, %l3
a008f1e0:  a2 10 20 00  clr  %l1
a008f1e4:  a0 10 20 00  clr  %l0
a008f1e8:  90 10 00 10  mov  %l0, %o0
a008f1ec:  92 10 00 12  mov  %l2, %o1
a008f1f0:  94 10 20 01  mov  1, %o2
a008f1f4:  96 10 20 00  clr  %o3
a008f1f8:  40 02 de 22  call  0xa0146a80
a008f1fc:  98 10 20 01  mov  1, %o4
a008f200:  82 04 c0 10  add  %l3, %l0, %g1
a008f204:  92 00 40 01  add  %g1, %g1, %o1
a008f208:  d0 15 00 09  lduh  [ %l4 + %o1 ], %o0
a008f20c:  98 0a 20 ff  and  %o0, 0xff, %o4
a008f210:  92 10 00 10  mov  %l0, %o1
a008f214:  90 10 20 01  mov  1, %o0
a008f218:  94 10 00 12  mov  %l2, %o2
a008f21c:  96 10 20 01  mov  1, %o3
a008f220:  9a 10 20 01  mov  1, %o5
a008f224:  40 02 de 3f  call  0xa0146b20
a008f228:  a2 04 60 01  inc  %l1
a008f22c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a008f230:  80 a4 20 3e  cmp  %l0, 0x3e
a008f234:  08 bf ff ee  bleu  0xa008f1ec
a008f238:  90 10 00 10  mov  %l0, %o0
a008f23c:  aa 05 60 01  inc  %l5
a008f240:  a4 0d 60 ff  and  %l5, 0xff, %l2
a008f244:  80 a4 a0 09  cmp  %l2, 9
a008f248:  08 bf ff e5  bleu  0xa008f1dc
a008f24c:  9b 2c a0 06  sll  %l2, 6, %o5
a008f250:  90 10 20 02  mov  2, %o0
a008f254:  40 02 de 17  call  0xa0146ab0
a008f258:  92 10 20 01  mov  1, %o1
a008f25c:  a6 10 20 00  clr  %l3
a008f260:  a9 2c e0 10  sll  %l3, 0x10, %l4
a008f264:  a5 35 20 10  srl  %l4, 0x10, %l2
a008f268:  a2 10 20 00  clr  %l1
a008f26c:  99 2c 60 10  sll  %l1, 0x10, %o4
a008f270:  a1 33 20 10  srl  %o4, 0x10, %l0
a008f274:  90 10 00 10  mov  %l0, %o0
a008f278:  92 10 00 12  mov  %l2, %o1
a008f27c:  94 10 20 01  mov  1, %o2
a008f280:  96 10 20 00  clr  %o3
a008f284:  40 02 dd ff  call  0xa0146a80
a008f288:  98 10 20 01  mov  1, %o4
a008f28c:  94 10 00 12  mov  %l2, %o2
a008f290:  96 10 20 01  mov  1, %o3
a008f294:  92 10 00 10  mov  %l0, %o1
a008f298:  90 10 20 01  mov  1, %o0
a008f29c:  98 10 20 00  clr  %o4
a008f2a0:  40 02 de 20  call  0xa0146b20
a008f2a4:  9a 10 20 01  mov  1, %o5
a008f2a8:  aa 04 60 01  add  %l1, 1, %l5
a008f2ac:  97 2d 60 10  sll  %l5, 0x10, %o3
a008f2b0:  95 32 e0 10  srl  %o3, 0x10, %o2
a008f2b4:  80 a2 a0 19  cmp  %o2, 0x19
a008f2b8:  08 bf ff ed  bleu  0xa008f26c
a008f2bc:  a2 10 00 15  mov  %l5, %l1
a008f2c0:  9e 04 e0 01  add  %l3, 1, %o7
a008f2c4:  a5 2b e0 10  sll  %o7, 0x10, %l2
a008f2c8:  a3 34 a0 10  srl  %l2, 0x10, %l1
a008f2cc:  80 a4 60 09  cmp  %l1, 9
a008f2d0:  08 bf ff e4  bleu  0xa008f260
a008f2d4:  a6 10 00 0f  mov  %o7, %l3
a008f2d8:  90 10 20 1b  mov  0x1b, %o0
a008f2dc:  92 10 21 38  mov  0x138, %o1
a008f2e0:  94 10 20 00  clr  %o2
a008f2e4:  96 10 20 00  clr  %o3
a008f2e8:  40 02 dc d8  call  0xa0146648
a008f2ec:  98 10 20 01  mov  1, %o4
a008f2f0:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a008f2f4:  d2 10 63 f8  lduh  [ %g1 + 0x3f8 ], %o1	! 0xa802cff8
a008f2f8:  11 00 00 18  sethi  %hi(0x6000), %o0
a008f2fc:  9a 0a 00 09  and  %o0, %o1, %o5
a008f300:  27 00 00 08  sethi  %hi(0x2000), %l3
a008f304:  80 a3 40 13  cmp  %o5, %l3
a008f308:  02 80 00 09  be  0xa008f32c
a008f30c:  90 10 20 01  mov  1, %o0
a008f310:  40 02 d7 87  call  0xa014512c
a008f314:  92 10 20 01  mov  1, %o1
a008f318:  90 10 20 01  mov  1, %o0
a008f31c:  40 02 de a9  call  0xa0146dc0
a008f320:  92 10 20 01  mov  1, %o1
a008f324:  40 00 54 a1  call  0xa00a45a8
a008f328:  81 e8 00 00  restore
a008f32c:  40 02 d7 80  call  0xa014512c
a008f330:  92 10 20 01  mov  1, %o1
a008f334:  40 02 4e 76  call  0xa0122d0c
a008f338:  01 00 00 00  nop
a008f33c:  90 10 20 01  mov  1, %o0	! 0x1
a008f340:  40 02 de a0  call  0xa0146dc0
a008f344:  92 10 20 01  mov  1, %o1
a008f348:  40 00 54 98  call  0xa00a45a8
a008f34c:  81 e8 00 00  restore
a008f350:  01 00 00 00  nop
