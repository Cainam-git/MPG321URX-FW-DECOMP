# leon2m FUN_a00d6054 0xa00d6054-0xa00d79b0 (5060 bytes)
a00d6054:  9d e3 bf 30  save  %sp, -208, %sp
a00d6058:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d605c:  c0 37 bf b6  clrh  [ %fp + -74 ]
a00d6060:  c0 37 bf b4  clrh  [ %fp + -76 ]
a00d6064:  c0 37 bf b2  clrh  [ %fp + -78 ]
a00d6068:  c0 37 bf b0  clrh  [ %fp + -80 ]
a00d606c:  40 01 b6 ea  call  0xa0143c14
a00d6070:  90 10 00 18  mov  %i0, %o0
a00d6074:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d6078:  80 a2 20 05  cmp  %o0, 5
a00d607c:  c0 37 bf ae  clrh  [ %fp + -82 ]
a00d6080:  08 80 00 70  bleu  0xa00d6240
a00d6084:  c0 37 bf a6  clrh  [ %fp + -90 ]
a00d6088:  92 10 20 07  mov  7, %o1
a00d608c:  40 01 bd 75  call  0xa0145660
a00d6090:  90 10 00 18  mov  %i0, %o0
a00d6094:  b4 10 00 08  mov  %o0, %i2
a00d6098:  90 10 00 18  mov  %i0, %o0
a00d609c:  40 01 bd 71  call  0xa0145660
a00d60a0:  92 10 20 08  mov  8, %o1
a00d60a4:  b6 10 00 08  mov  %o0, %i3
a00d60a8:  40 01 c8 b5  call  0xa014837c
a00d60ac:  90 10 20 00  clr  %o0
a00d60b0:  ac 10 00 08  mov  %o0, %l6
a00d60b4:  40 01 c8 b2  call  0xa014837c
a00d60b8:  90 10 20 01  mov  1, %o0
a00d60bc:  b8 10 00 08  mov  %o0, %i4
a00d60c0:  40 01 c8 af  call  0xa014837c
a00d60c4:  90 10 20 00  clr  %o0
a00d60c8:  a2 10 00 08  mov  %o0, %l1
a00d60cc:  40 01 c8 ac  call  0xa014837c
a00d60d0:  90 10 20 01  mov  1, %o0
a00d60d4:  80 a6 20 01  cmp  %i0, 1
a00d60d8:  02 80 00 bc  be  0xa00d63c8
a00d60dc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00d60e0:  04 80 01 45  ble  0xa00d65f4
a00d60e4:  80 a6 20 02  cmp  %i0, 2
a00d60e8:  02 80 00 ef  be  0xa00d64a4
a00d60ec:  80 a6 20 03  cmp  %i0, 3
a00d60f0:  02 80 02 36  be  0xa00d69c8
a00d60f4:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00d60f8:  e2 37 bf b6  sth  %l1, [ %fp + -74 ]
a00d60fc:  d0 37 bf b4  sth  %o0, [ %fp + -76 ]
a00d6100:  e0 17 bf b6  lduh  [ %fp + -74 ], %l0
a00d6104:  e4 17 bf b4  lduh  [ %fp + -76 ], %l2
a00d6108:  40 01 c8 9d  call  0xa014837c
a00d610c:  90 10 20 00  clr  %o0
a00d6110:  a2 10 00 08  mov  %o0, %l1
a00d6114:  40 01 c8 9a  call  0xa014837c
a00d6118:  90 10 20 01  mov  1, %o0
a00d611c:  a6 10 00 08  mov  %o0, %l3
a00d6120:  80 a6 20 01  cmp  %i0, 1
a00d6124:  aa 10 20 00  clr  %l5
a00d6128:  02 80 00 b3  be  0xa00d63f4
a00d612c:  a8 10 20 00  clr  %l4
a00d6130:  80 a6 20 01  cmp  %i0, 1
a00d6134:  04 80 01 2b  ble  0xa00d65e0
a00d6138:  80 a6 20 02  cmp  %i0, 2
a00d613c:  02 80 01 19  be  0xa00d65a0
a00d6140:  80 a6 20 03  cmp  %i0, 3
a00d6144:  02 80 02 17  be  0xa00d69a0
a00d6148:  2f 2a 00 b4  sethi  %hi(0xa802d000), %l7
a00d614c:  e0 17 bf b6  lduh  [ %fp + -74 ], %l0
a00d6150:  af 2e a0 10  sll  %i2, 0x10, %l7
a00d6154:  97 35 e0 10  srl  %l7, 0x10, %o3
a00d6158:  a7 2c 20 10  sll  %l0, 0x10, %l3
a00d615c:  92 5a e0 64  smul  %o3, 0x64, %o1
a00d6160:  95 34 e0 10  srl  %l3, 0x10, %o2
a00d6164:  bb 2e e0 10  sll  %i3, 0x10, %i5
a00d6168:  d6 17 bf b4  lduh  [ %fp + -76 ], %o3
a00d616c:  90 5a a0 64  smul  %o2, 0x64, %o0
a00d6170:  83 37 60 10  srl  %i5, 0x10, %g1
a00d6174:  81 80 00 00  mov  %g0, %y
a00d6178:  01 00 00 00  nop
a00d617c:  01 00 00 00  nop
a00d6180:  01 00 00 00  nop
a00d6184:  a4 72 40 01  udiv  %o1, %g1, %l2
a00d6188:  81 80 00 00  mov  %g0, %y
a00d618c:  01 00 00 00  nop
a00d6190:  01 00 00 00  nop
a00d6194:  01 00 00 00  nop
a00d6198:  98 72 00 0b  udiv  %o0, %o3, %o4
a00d619c:  ea 37 bf b2  sth  %l5, [ %fp + -78 ]
a00d61a0:  e8 37 bf b0  sth  %l4, [ %fp + -80 ]
a00d61a4:  e4 37 bf 96  sth  %l2, [ %fp + -106 ]
a00d61a8:  d8 37 bf 9e  sth  %o4, [ %fp + -98 ]
a00d61ac:  23 00 06 61  sethi  %hi(0x198400), %l1
a00d61b0:  90 14 63 68  or  %l1, 0x368, %o0	! 0x198768
a00d61b4:  d8 17 bf b2  lduh  [ %fp + -78 ], %o4
a00d61b8:  a4 10 00 0b  mov  %o3, %l2
a00d61bc:  92 10 00 18  mov  %i0, %o1
a00d61c0:  da 17 bf b0  lduh  [ %fp + -80 ], %o5
a00d61c4:  40 00 23 eb  call  0xa00df170
a00d61c8:  2b 2a 00 b4  sethi  %hi(0xa802d000), %l5
a00d61cc:  a2 15 62 90  or  %l5, 0x290, %l1	! 0xa802d290
a00d61d0:  c2 0c 60 1f  ldub  [ %l1 + 0x1f ], %g1
a00d61d4:  80 a0 60 01  cmp  %g1, 1
a00d61d8:  18 80 00 03  bgu  0xa00d61e4
a00d61dc:  98 10 20 01  mov  1, %o4
a00d61e0:  98 10 20 00  clr  %o4
a00d61e4:  9e 18 60 04  xor  %g1, 4, %o7
a00d61e8:  80 a0 00 0f  cmp  %g0, %o7
a00d61ec:  94 40 20 00  addx  %g0, 0, %o2
a00d61f0:  80 8b 00 0a  btst  %o4, %o2
a00d61f4:  12 80 00 1c  bne  0xa00d6264
a00d61f8:  80 a6 20 00  cmp  %i0, 0
a00d61fc:  12 80 00 18  bne  0xa00d625c
a00d6200:  d4 17 bf b6  lduh  [ %fp + -74 ], %o2
a00d6204:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00d6208:  e4 02 a2 90  ld  [ %o2 + 0x290 ], %l2	! 0xa802d290
a00d620c:  80 8c a0 20  btst  0x20, %l2
a00d6210:  32 80 00 95  bne,a   0xa00d6464
a00d6214:  fa 0c 60 3b  ldub  [ %l1 + 0x3b ], %i5
a00d6218:  c2 0c 61 a4  ldub  [ %l1 + 0x1a4 ], %g1
a00d621c:  80 a0 60 09  cmp  %g1, 9
a00d6220:  38 80 00 d6  bgu,a   0xa00d6578
a00d6224:  a4 10 00 1c  mov  %i4, %l2
a00d6228:  11 00 01 ce  sethi  %hi(0x73800), %o0
a00d622c:  83 28 60 02  sll  %g1, 2, %g1
a00d6230:  aa 12 22 98  or  %o0, 0x298, %l5
a00d6234:  e2 05 40 01  ld  [ %l5 + %g1 ], %l1
a00d6238:  81 c4 40 00  jmp  %l1
a00d623c:  01 00 00 00  nop
a00d6240:  40 01 c8 4f  call  0xa014837c
a00d6244:  90 10 20 00  clr  %o0	! 0x0
a00d6248:  b4 10 00 08  mov  %o0, %i2
a00d624c:  40 01 c8 4c  call  0xa014837c
a00d6250:  90 10 20 01  mov  1, %o0
a00d6254:  10 bf ff 95  b  0xa00d60a8
a00d6258:  b6 10 00 08  mov  %o0, %i3
a00d625c:  10 80 05 c7  b  0xa00d7978
a00d6260:  d0 17 bf b4  lduh  [ %fp + -76 ], %o0
a00d6264:  2b 00 06 61  sethi  %hi(0x198400), %l5
a00d6268:  a8 07 bf d0  add  %fp, -48, %l4
a00d626c:  94 10 20 24  mov  0x24, %o2
a00d6270:  90 10 00 14  mov  %l4, %o0
a00d6274:  40 01 99 a7  call  0xa013c910
a00d6278:  92 15 63 20  or  %l5, 0x320, %o1
a00d627c:  11 00 00 09  sethi  %hi(0x2400), %o0
a00d6280:  9a 12 23 10  or  %o0, 0x310, %o5	! 0x2710
a00d6284:  19 00 00 07  sethi  %hi(0x1c00), %o4
a00d6288:  21 00 00 04  sethi  %hi(0x1000), %l0
a00d628c:  b4 10 20 11  mov  0x11, %i2
a00d6290:  b6 13 21 4c  or  %o4, 0x14c, %i3
a00d6294:  ac 14 23 88  or  %l0, 0x388, %l6
a00d6298:  d4 0c 60 1f  ldub  [ %l1 + 0x1f ], %o2
a00d629c:  da 37 bf ba  sth  %o5, [ %fp + -70 ]
a00d62a0:  da 37 bf b8  sth  %o5, [ %fp + -72 ]
a00d62a4:  f6 37 bf c0  sth  %i3, [ %fp + -64 ]
a00d62a8:  ec 37 bf c6  sth  %l6, [ %fp + -58 ]
a00d62ac:  f4 37 bf c8  sth  %i2, [ %fp + -56 ]
a00d62b0:  f4 37 bf bc  sth  %i2, [ %fp + -68 ]
a00d62b4:  f6 37 bf be  sth  %i3, [ %fp + -66 ]
a00d62b8:  f4 37 bf c2  sth  %i2, [ %fp + -62 ]
a00d62bc:  ec 37 bf c4  sth  %l6, [ %fp + -60 ]
a00d62c0:  80 a2 a0 00  cmp  %o2, 0
a00d62c4:  02 80 00 92  be  0xa00d650c
a00d62c8:  9a 10 20 01  mov  1, %o5
a00d62cc:  80 a6 20 01  cmp  %i0, 1
a00d62d0:  22 80 03 ef  be,a   0xa00d728c
a00d62d4:  b6 1a a0 01  xor  %o2, 1, %i3
a00d62d8:  04 80 04 43  ble  0xa00d73e4
a00d62dc:  80 a6 20 02  cmp  %i0, 2
a00d62e0:  02 80 04 09  be  0xa00d7304
a00d62e4:  80 a6 20 03  cmp  %i0, 3
a00d62e8:  12 80 00 0d  bne  0xa00d631c
a00d62ec:  9a 0b 60 03  and  %o5, 3, %o5
a00d62f0:  d0 04 60 34  ld  [ %l1 + 0x34 ], %o0
a00d62f4:  9b 32 20 14  srl  %o0, 0x14, %o5
a00d62f8:  9a 0b 60 0f  and  %o5, 0xf, %o5
a00d62fc:  90 03 40 0d  add  %o5, %o5, %o0
a00d6300:  98 02 00 0d  add  %o0, %o5, %o4
a00d6304:  9a 03 00 0c  add  %o4, %o4, %o5
a00d6308:  a0 07 80 0d  add  %fp, %o5, %l0
a00d630c:  da 14 3f bc  lduh  [ %l0 + -68 ], %o5
a00d6310:  a3 33 60 03  srl  %o5, 3, %l1
a00d6314:  9a 0c 60 01  and  %l1, 1, %o5
a00d6318:  9a 0b 60 03  and  %o5, 3, %o5
a00d631c:  80 a3 60 01  cmp  %o5, 1
a00d6320:  02 80 03 a7  be  0xa00d71bc
a00d6324:  80 a3 60 02  cmp  %o5, 2
a00d6328:  02 80 00 cc  be  0xa00d6658
a00d632c:  19 00 00 09  sethi  %hi(0x2400), %o4
a00d6330:  a0 13 23 10  or  %o4, 0x310, %l0	! 0x2710
a00d6334:  94 10 20 24  mov  0x24, %o2
a00d6338:  e2 17 bf b4  lduh  [ %fp + -76 ], %l1
a00d633c:  90 10 00 14  mov  %l4, %o0
a00d6340:  40 01 99 74  call  0xa013c910
a00d6344:  92 15 63 20  or  %l5, 0x320, %o1
a00d6348:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00d634c:  94 13 62 90  or  %o5, 0x290, %o2	! 0xa802d290
a00d6350:  37 00 00 07  sethi  %hi(0x1c00), %i3
a00d6354:  35 00 00 04  sethi  %hi(0x1000), %i2
a00d6358:  9e 10 20 11  mov  0x11, %o7
a00d635c:  ac 16 e1 4c  or  %i3, 0x14c, %l6
a00d6360:  a6 16 a3 88  or  %i2, 0x388, %l3
a00d6364:  d6 0a a0 1f  ldub  [ %o2 + 0x1f ], %o3
a00d6368:  ec 37 bf c0  sth  %l6, [ %fp + -64 ]
a00d636c:  e6 37 bf c6  sth  %l3, [ %fp + -58 ]
a00d6370:  de 37 bf c8  sth  %o7, [ %fp + -56 ]
a00d6374:  e0 37 bf b8  sth  %l0, [ %fp + -72 ]
a00d6378:  e0 37 bf ba  sth  %l0, [ %fp + -70 ]
a00d637c:  de 37 bf bc  sth  %o7, [ %fp + -68 ]
a00d6380:  ec 37 bf be  sth  %l6, [ %fp + -66 ]
a00d6384:  de 37 bf c2  sth  %o7, [ %fp + -62 ]
a00d6388:  80 a2 e0 00  cmp  %o3, 0
a00d638c:  02 80 01 dc  be  0xa00d6afc
a00d6390:  e6 37 bf c4  sth  %l3, [ %fp + -60 ]
a00d6394:  80 a6 20 01  cmp  %i0, 1
a00d6398:  22 80 02 93  be,a   0xa00d6de4
a00d639c:  ac 1a e0 01  xor  %o3, 1, %l6
a00d63a0:  04 80 04 69  ble  0xa00d7544
a00d63a4:  80 a6 20 02  cmp  %i0, 2
a00d63a8:  02 80 04 5a  be  0xa00d7510
a00d63ac:  80 a6 20 03  cmp  %i0, 3
a00d63b0:  12 80 01 da  bne  0xa00d6b18
a00d63b4:  ad 2c 20 10  sll  %l0, 0x10, %l6
a00d63b8:  da 02 a0 34  ld  [ %o2 + 0x34 ], %o5
a00d63bc:  83 33 60 14  srl  %o5, 0x14, %g1
a00d63c0:  10 80 02 92  b  0xa00d6e08
a00d63c4:  82 08 60 0f  and  %g1, 0xf, %g1
a00d63c8:  a0 13 22 90  or  %o4, 0x290, %l0
a00d63cc:  c2 0c 20 1f  ldub  [ %l0 + 0x1f ], %g1
a00d63d0:  80 a0 60 07  cmp  %g1, 7
a00d63d4:  38 bf ff 4a  bgu,a   0xa00d60fc
a00d63d8:  e2 37 bf b6  sth  %l1, [ %fp + -74 ]
a00d63dc:  2b 00 01 ce  sethi  %hi(0x73800), %l5
a00d63e0:  a7 28 60 02  sll  %g1, 2, %l3
a00d63e4:  a8 15 62 78  or  %l5, 0x278, %l4
a00d63e8:  e4 05 00 13  ld  [ %l4 + %l3 ], %l2
a00d63ec:  81 c4 80 00  jmp  %l2
a00d63f0:  01 00 00 00  nop
a00d63f4:  2f 2a 00 b4  sethi  %hi(0xa802d000), %l7
a00d63f8:  92 15 e2 90  or  %l7, 0x290, %o1	! 0xa802d290
a00d63fc:  d4 0a 60 1f  ldub  [ %o1 + 0x1f ], %o2
a00d6400:  96 0a a0 ff  and  %o2, 0xff, %o3
a00d6404:  80 a2 e0 00  cmp  %o3, 0
a00d6408:  22 80 00 4b  be,a   0xa00d6534
a00d640c:  ab 2c 20 10  sll  %l0, 0x10, %l5
a00d6410:  82 1a e0 01  xor  %o3, 1, %g1
a00d6414:  80 a0 00 01  cmp  %g0, %g1
a00d6418:  ba 60 3f ff  subx  %g0, -1, %i5
a00d641c:  90 1a e0 04  xor  %o3, 4, %o0
a00d6420:  80 a0 00 08  cmp  %g0, %o0
a00d6424:  a4 60 3f ff  subx  %g0, -1, %l2
a00d6428:  80 97 40 12  orcc  %i5, %l2, %g0
a00d642c:  22 80 01 a0  be,a   0xa00d6aac
a00d6430:  a0 1a e0 02  xor  %o3, 2, %l0
a00d6434:  d4 02 60 30  ld  [ %o1 + 0x30 ], %o2
a00d6438:  93 32 a0 04  srl  %o2, 4, %o1
a00d643c:  82 0a 60 0f  and  %o1, 0xf, %g1
a00d6440:  80 a0 60 04  cmp  %g1, 4
a00d6444:  38 bf ff 43  bgu,a   0xa00d6150
a00d6448:  e0 17 bf b6  lduh  [ %fp + -74 ], %l0
a00d644c:  19 00 01 ce  sethi  %hi(0x73800), %o4
a00d6450:  97 28 60 02  sll  %g1, 2, %o3
a00d6454:  9a 13 22 64  or  %o4, 0x264, %o5
a00d6458:  de 03 40 0b  ld  [ %o5 + %o3 ], %o7
a00d645c:  81 c3 c0 00  jmp  %o7
a00d6460:  01 00 00 00  nop
a00d6464:  e8 0c 60 3d  ldub  [ %l1 + 0x3d ], %l4
a00d6468:  ae 10 20 03  mov  3, %l7
a00d646c:  a0 25 c0 14  sub  %l7, %l4, %l0
a00d6470:  92 25 c0 1d  sub  %l7, %i5, %o1
a00d6474:  f4 0c 60 3a  ldub  [ %l1 + 0x3a ], %i2
a00d6478:  de 0c 60 3c  ldub  [ %l1 + 0x3c ], %o7
a00d647c:  e0 37 bf a6  sth  %l0, [ %fp + -90 ]
a00d6480:  9b 2a 60 03  sll  %o1, 3, %o5
a00d6484:  ec 37 bf b6  sth  %l6, [ %fp + -74 ]
a00d6488:  f8 37 bf b4  sth  %i4, [ %fp + -76 ]
a00d648c:  a0 05 80 1a  add  %l6, %i2, %l0
a00d6490:  a4 07 00 0f  add  %i4, %o7, %l2
a00d6494:  da 37 bf ae  sth  %o5, [ %fp + -82 ]
a00d6498:  94 10 00 16  mov  %l6, %o2
a00d649c:  10 80 05 37  b  0xa00d7978
a00d64a0:  90 10 00 1c  mov  %i4, %o0
a00d64a4:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00d64a8:  9a 12 e2 90  or  %o3, 0x290, %o5	! 0xa802d290
a00d64ac:  c2 0b 60 1f  ldub  [ %o5 + 0x1f ], %g1
a00d64b0:  80 a0 60 05  cmp  %g1, 5
a00d64b4:  02 80 01 4b  be  0xa00d69e0
a00d64b8:  ab 2c 60 10  sll  %l1, 0x10, %l5
a00d64bc:  14 80 01 dc  bg  0xa00d6c2c
a00d64c0:  80 a0 60 06  cmp  %g1, 6
a00d64c4:  80 a0 60 04  cmp  %g1, 4
a00d64c8:  32 bf ff 0d  bne,a   0xa00d60fc
a00d64cc:  e2 37 bf b6  sth  %l1, [ %fp + -74 ]
a00d64d0:  de 03 60 30  ld  [ %o5 + 0x30 ], %o7
a00d64d4:  82 8b ef 00  andcc  %o7, 0xf00, %g1
a00d64d8:  a2 10 26 c0  mov  0x6c0, %l1
a00d64dc:  02 bf ff 07  be  0xa00d60f8
a00d64e0:  90 10 23 cc  mov  0x3cc, %o0
a00d64e4:  80 a0 61 00  cmp  %g1, 0x100
a00d64e8:  a2 10 25 40  mov  0x540, %l1
a00d64ec:  02 bf ff 03  be  0xa00d60f8
a00d64f0:  90 10 22 f4  mov  0x2f4, %o0
a00d64f4:  90 10 20 01  mov  1, %o0
a00d64f8:  40 01 bc 5a  call  0xa0145660
a00d64fc:  92 10 20 04  mov  4, %o1
a00d6500:  a2 10 23 c0  mov  0x3c0, %l1
a00d6504:  10 bf fe fd  b  0xa00d60f8
a00d6508:  90 10 22 1c  mov  0x21c, %o0
a00d650c:  80 a6 20 00  cmp  %i0, 0
a00d6510:  32 bf ff 83  bne,a   0xa00d631c
a00d6514:  9a 0b 60 03  and  %o5, 3, %o5
a00d6518:  d4 0c 61 a4  ldub  [ %l1 + 0x1a4 ], %o2
a00d651c:  96 02 80 0a  add  %o2, %o2, %o3
a00d6520:  82 02 c0 0a  add  %o3, %o2, %g1
a00d6524:  92 00 40 01  add  %g1, %g1, %o1
a00d6528:  a4 07 80 09  add  %fp, %o1, %l2
a00d652c:  10 bf ff 79  b  0xa00d6310
a00d6530:  da 14 bf d4  lduh  [ %l2 + -44 ], %o5
a00d6534:  af 2c 60 10  sll  %l1, 0x10, %l7
a00d6538:  a9 2c e0 10  sll  %l3, 0x10, %l4
a00d653c:  99 2c a0 10  sll  %l2, 0x10, %o4
a00d6540:  97 35 60 10  srl  %l5, 0x10, %o3
a00d6544:  83 35 20 10  srl  %l4, 0x10, %g1
a00d6548:  9b 35 e0 10  srl  %l7, 0x10, %o5
a00d654c:  9f 33 20 10  srl  %o4, 0x10, %o7
a00d6550:  a0 23 40 0b  sub  %o5, %o3, %l0
a00d6554:  90 20 40 0f  sub  %g1, %o7, %o0
a00d6558:  95 34 20 1f  srl  %l0, 0x1f, %o2
a00d655c:  93 32 20 1f  srl  %o0, 0x1f, %o1
a00d6560:  a2 04 00 0a  add  %l0, %o2, %l1
a00d6564:  ba 02 00 09  add  %o0, %o1, %i5
a00d6568:  ab 34 60 01  srl  %l1, 1, %l5
a00d656c:  10 bf fe f8  b  0xa00d614c
a00d6570:  a9 37 60 01  srl  %i5, 1, %l4
a00d6574:  a4 10 00 1c  mov  %i4, %l2
a00d6578:  a0 10 00 16  mov  %l6, %l0
a00d657c:  ec 37 bf b6  sth  %l6, [ %fp + -74 ]
a00d6580:  f8 37 bf b4  sth  %i4, [ %fp + -76 ]
a00d6584:  c0 37 bf b2  clrh  [ %fp + -78 ]
a00d6588:  c0 37 bf b0  clrh  [ %fp + -80 ]
a00d658c:  c0 37 bf ae  clrh  [ %fp + -82 ]
a00d6590:  c0 37 bf a6  clrh  [ %fp + -90 ]
a00d6594:  94 10 00 16  mov  %l6, %o2
a00d6598:  10 80 04 f8  b  0xa00d7978
a00d659c:  90 10 00 12  mov  %l2, %o0
a00d65a0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d65a4:  98 10 62 90  or  %g1, 0x290, %o4	! 0xa802d290
a00d65a8:  c2 0b 20 1f  ldub  [ %o4 + 0x1f ], %g1
a00d65ac:  9a 08 60 ff  and  %g1, 0xff, %o5
a00d65b0:  80 a3 60 04  cmp  %o5, 4
a00d65b4:  02 80 02 e4  be  0xa00d7144
a00d65b8:  80 a3 60 05  cmp  %o5, 5
a00d65bc:  02 80 00 fe  be  0xa00d69b4
a00d65c0:  a4 00 7f fa  add  %g1, -6, %l2
a00d65c4:  a6 0c a0 ff  and  %l2, 0xff, %l3
a00d65c8:  80 a4 e0 01  cmp  %l3, 1
a00d65cc:  18 bf fe e1  bgu  0xa00d6150
a00d65d0:  e0 17 bf b6  lduh  [ %fp + -74 ], %l0
a00d65d4:  93 2c 60 10  sll  %l1, 0x10, %o1
a00d65d8:  10 bf fe de  b  0xa00d6150
a00d65dc:  ab 32 60 11  srl  %o1, 0x11, %l5
a00d65e0:  80 a6 20 00  cmp  %i0, 0
a00d65e4:  12 bf fe db  bne  0xa00d6150
a00d65e8:  e0 17 bf b6  lduh  [ %fp + -74 ], %l0
a00d65ec:  10 bf fe d9  b  0xa00d6150
a00d65f0:  aa 10 20 00  clr  %l5
a00d65f4:  80 a6 20 00  cmp  %i0, 0
a00d65f8:  32 bf fe c1  bne,a   0xa00d60fc
a00d65fc:  e2 37 bf b6  sth  %l1, [ %fp + -74 ]
a00d6600:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d6604:  98 10 62 90  or  %g1, 0x290, %o4	! 0xa802d290
a00d6608:  c2 0b 20 1f  ldub  [ %o4 + 0x1f ], %g1
a00d660c:  80 a0 60 05  cmp  %g1, 5
a00d6610:  02 80 02 05  be  0xa00d6e24
a00d6614:  9b 2c 60 10  sll  %l1, 0x10, %o5
a00d6618:  14 80 01 b7  bg  0xa00d6cf4
a00d661c:  80 a0 60 06  cmp  %g1, 6
a00d6620:  80 a0 60 02  cmp  %g1, 2
a00d6624:  32 bf fe b6  bne,a   0xa00d60fc
a00d6628:  e2 37 bf b6  sth  %l1, [ %fp + -74 ]
a00d662c:  d6 0b 20 2f  ldub  [ %o4 + 0x2f ], %o3
a00d6630:  80 a2 e0 00  cmp  %o3, 0
a00d6634:  12 80 04 65  bne  0xa00d77c8
a00d6638:  80 a2 e0 01  cmp  %o3, 1
a00d663c:  97 2c 60 10  sll  %l1, 0x10, %o3
a00d6640:  9b 32 e0 10  srl  %o3, 0x10, %o5
a00d6644:  94 03 40 0d  add  %o5, %o5, %o2
a00d6648:  92 02 80 0d  add  %o2, %o5, %o1
a00d664c:  83 3a 60 05  sra  %o1, 5, %g1
a00d6650:  10 bf fe aa  b  0xa00d60f8
a00d6654:  a3 28 60 03  sll  %g1, 3, %l1
a00d6658:  99 37 60 10  srl  %i5, 0x10, %o4
a00d665c:  80 a0 00 0c  cmp  %g0, %o4
a00d6660:  a4 60 3f ff  subx  %g0, -1, %l2
a00d6664:  95 35 e0 10  srl  %l7, 0x10, %o2
a00d6668:  80 a0 00 0a  cmp  %g0, %o2
a00d666c:  a0 60 3f ff  subx  %g0, -1, %l0
a00d6670:  80 94 80 10  orcc  %l2, %l0, %g0
a00d6674:  02 80 01 34  be  0xa00d6b44
a00d6678:  a3 34 e0 10  srl  %l3, 0x10, %l1
a00d667c:  e4 17 bf b4  lduh  [ %fp + -76 ], %l2
a00d6680:  82 8c a0 03  andcc  %l2, 3, %g1
a00d6684:  02 80 00 05  be  0xa00d6698
a00d6688:  a3 2c a0 10  sll  %l2, 0x10, %l1
a00d668c:  b4 24 80 01  sub  %l2, %g1, %i2
a00d6690:  a3 2e a0 10  sll  %i2, 0x10, %l1
a00d6694:  a4 10 00 1a  mov  %i2, %l2
a00d6698:  92 15 63 20  or  %l5, 0x320, %o1
a00d669c:  94 10 20 24  mov  0x24, %o2
a00d66a0:  40 01 98 9c  call  0xa013c910
a00d66a4:  90 10 00 14  mov  %l4, %o0
a00d66a8:  13 00 00 04  sethi  %hi(0x1000), %o1
a00d66ac:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d66b0:  b6 12 63 88  or  %o1, 0x388, %i3
a00d66b4:  15 00 00 07  sethi  %hi(0x1c00), %o2
a00d66b8:  a0 10 62 90  or  %g1, 0x290, %l0
a00d66bc:  27 00 00 09  sethi  %hi(0x2400), %l3
a00d66c0:  98 12 a1 4c  or  %o2, 0x14c, %o4
a00d66c4:  90 10 20 11  mov  0x11, %o0
a00d66c8:  9a 14 e3 10  or  %l3, 0x310, %o5
a00d66cc:  d2 0c 20 1f  ldub  [ %l0 + 0x1f ], %o1
a00d66d0:  da 37 bf ba  sth  %o5, [ %fp + -70 ]
a00d66d4:  d8 37 bf c0  sth  %o4, [ %fp + -64 ]
a00d66d8:  f6 37 bf c6  sth  %i3, [ %fp + -58 ]
a00d66dc:  d0 37 bf c8  sth  %o0, [ %fp + -56 ]
a00d66e0:  da 37 bf b8  sth  %o5, [ %fp + -72 ]
a00d66e4:  d0 37 bf bc  sth  %o0, [ %fp + -68 ]
a00d66e8:  d8 37 bf be  sth  %o4, [ %fp + -66 ]
a00d66ec:  d0 37 bf c2  sth  %o0, [ %fp + -62 ]
a00d66f0:  f6 37 bf c4  sth  %i3, [ %fp + -60 ]
a00d66f4:  80 a2 60 00  cmp  %o1, 0
a00d66f8:  02 80 00 8c  be  0xa00d6928
a00d66fc:  94 10 20 01  mov  1, %o2
a00d6700:  80 a6 20 01  cmp  %i0, 1
a00d6704:  22 80 02 ec  be,a   0xa00d72b4
a00d6708:  94 1a 60 01  xor  %o1, 1, %o2
a00d670c:  04 80 03 1d  ble  0xa00d7380
a00d6710:  80 a6 20 02  cmp  %i0, 2
a00d6714:  02 80 02 f7  be  0xa00d72f0
a00d6718:  80 a6 20 03  cmp  %i0, 3
a00d671c:  12 80 00 0d  bne  0xa00d6750
a00d6720:  ad 34 60 10  srl  %l1, 0x10, %l6
a00d6724:  de 04 20 34  ld  [ %l0 + 0x34 ], %o7
a00d6728:  9b 33 e0 14  srl  %o7, 0x14, %o5
a00d672c:  9a 0b 60 0f  and  %o5, 0xf, %o5
a00d6730:  96 03 40 0d  add  %o5, %o5, %o3
a00d6734:  82 02 c0 0d  add  %o3, %o5, %g1
a00d6738:  a6 00 40 01  add  %g1, %g1, %l3
a00d673c:  92 07 80 13  add  %fp, %l3, %o1
a00d6740:  da 12 7f bc  lduh  [ %o1 + -68 ], %o5
a00d6744:  99 33 60 03  srl  %o5, 3, %o4
a00d6748:  94 0b 20 01  and  %o4, 1, %o2
a00d674c:  ad 34 60 10  srl  %l1, 0x10, %l6
a00d6750:  1b 00 06 61  sethi  %hi(0x198400), %o5
a00d6754:  94 0a a0 03  and  %o2, 3, %o2
a00d6758:  90 13 63 98  or  %o5, 0x398, %o0
a00d675c:  92 10 00 18  mov  %i0, %o1
a00d6760:  40 00 22 84  call  0xa00df170
a00d6764:  96 10 00 16  mov  %l6, %o3
a00d6768:  a7 2f 20 10  sll  %i4, 0x10, %l3
a00d676c:  95 34 e0 10  srl  %l3, 0x10, %o2
a00d6770:  80 a5 80 0a  cmp  %l6, %o2
a00d6774:  08 80 00 04  bleu  0xa00d6784
a00d6778:  92 15 63 20  or  %l5, 0x320, %o1
a00d677c:  a4 10 00 1c  mov  %i4, %l2
a00d6780:  a3 2c a0 10  sll  %l2, 0x10, %l1
a00d6784:  94 10 20 24  mov  0x24, %o2
a00d6788:  40 01 98 62  call  0xa013c910
a00d678c:  90 10 00 14  mov  %l4, %o0
a00d6790:  21 00 00 07  sethi  %hi(0x1c00), %l0
a00d6794:  17 00 00 04  sethi  %hi(0x1000), %o3
a00d6798:  37 00 00 09  sethi  %hi(0x2400), %i3
a00d679c:  9e 14 21 4c  or  %l0, 0x14c, %o7
a00d67a0:  82 10 20 11  mov  0x11, %g1
a00d67a4:  92 12 e3 88  or  %o3, 0x388, %o1
a00d67a8:  b4 16 e3 10  or  %i3, 0x310, %i2
a00d67ac:  f4 37 bf ba  sth  %i2, [ %fp + -70 ]
a00d67b0:  de 37 bf c0  sth  %o7, [ %fp + -64 ]
a00d67b4:  d2 37 bf c6  sth  %o1, [ %fp + -58 ]
a00d67b8:  c2 37 bf c8  sth  %g1, [ %fp + -56 ]
a00d67bc:  f4 37 bf b8  sth  %i2, [ %fp + -72 ]
a00d67c0:  c2 37 bf bc  sth  %g1, [ %fp + -68 ]
a00d67c4:  de 37 bf be  sth  %o7, [ %fp + -66 ]
a00d67c8:  c2 37 bf c2  sth  %g1, [ %fp + -62 ]
a00d67cc:  d2 37 bf c4  sth  %o1, [ %fp + -60 ]
a00d67d0:  40 01 b5 11  call  0xa0143c14
a00d67d4:  90 10 00 18  mov  %i0, %o0
a00d67d8:  b8 0a 20 ff  and  %o0, 0xff, %i4
a00d67dc:  80 a7 20 05  cmp  %i4, 5
a00d67e0:  08 80 00 5c  bleu  0xa00d6950
a00d67e4:  a0 10 20 00  clr  %l0
a00d67e8:  92 10 20 07  mov  7, %o1
a00d67ec:  40 01 bb 9d  call  0xa0145660
a00d67f0:  90 10 00 18  mov  %i0, %o0
a00d67f4:  90 10 00 18  mov  %i0, %o0
a00d67f8:  40 01 bb 9a  call  0xa0145660
a00d67fc:  92 10 20 08  mov  8, %o1
a00d6800:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d6804:  94 12 22 90  or  %o0, 0x290, %o2	! 0xa802d290
a00d6808:  d6 0a a0 1f  ldub  [ %o2 + 0x1f ], %o3
a00d680c:  80 a2 e0 00  cmp  %o3, 0
a00d6810:  02 80 00 5b  be  0xa00d697c
a00d6814:  80 a6 20 00  cmp  %i0, 0
a00d6818:  80 a6 20 01  cmp  %i0, 1
a00d681c:  22 80 02 8f  be,a   0xa00d7258
a00d6820:  80 a2 e0 02  cmp  %o3, 2
a00d6824:  04 80 02 c4  ble  0xa00d7334
a00d6828:  80 a6 20 02  cmp  %i0, 2
a00d682c:  02 80 02 ac  be  0xa00d72dc
a00d6830:  80 a6 20 03  cmp  %i0, 3
a00d6834:  12 80 00 0d  bne  0xa00d6868
a00d6838:  9a 0c 20 03  and  %l0, 3, %o5
a00d683c:  d8 02 a0 34  ld  [ %o2 + 0x34 ], %o4
a00d6840:  9b 33 20 14  srl  %o4, 0x14, %o5
a00d6844:  9a 0b 60 0f  and  %o5, 0xf, %o5
a00d6848:  90 03 40 0d  add  %o5, %o5, %o0
a00d684c:  b6 02 00 0d  add  %o0, %o5, %i3
a00d6850:  a0 06 c0 1b  add  %i3, %i3, %l0
a00d6854:  94 07 80 10  add  %fp, %l0, %o2
a00d6858:  da 12 bf bc  lduh  [ %o2 + -68 ], %o5
a00d685c:  b5 33 60 01  srl  %o5, 1, %i2
a00d6860:  a0 0e a0 03  and  %i2, 3, %l0
a00d6864:  9a 0c 20 03  and  %l0, 3, %o5
a00d6868:  80 a3 60 01  cmp  %o5, 1
a00d686c:  02 80 00 61  be  0xa00d69f0
a00d6870:  80 a3 60 02  cmp  %o5, 2
a00d6874:  02 80 00 c2  be  0xa00d6b7c
a00d6878:  27 00 00 09  sethi  %hi(0x2400), %l3
a00d687c:  a0 14 e3 10  or  %l3, 0x310, %l0	! 0x2710
a00d6880:  90 10 00 14  mov  %l4, %o0
a00d6884:  92 15 63 20  or  %l5, 0x320, %o1
a00d6888:  94 10 20 24  mov  0x24, %o2
a00d688c:  40 01 98 21  call  0xa013c910
a00d6890:  e6 17 bf b6  lduh  [ %fp + -74 ], %l3
a00d6894:  17 00 00 07  sethi  %hi(0x1c00), %o3
a00d6898:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a00d689c:  a8 12 e1 4c  or  %o3, 0x14c, %l4
a00d68a0:  94 16 e2 90  or  %i3, 0x290, %o2
a00d68a4:  2b 00 00 04  sethi  %hi(0x1000), %l5
a00d68a8:  ae 10 20 11  mov  0x11, %l7
a00d68ac:  ba 15 63 88  or  %l5, 0x388, %i5
a00d68b0:  d6 0a a0 1f  ldub  [ %o2 + 0x1f ], %o3
a00d68b4:  e8 37 bf c0  sth  %l4, [ %fp + -64 ]
a00d68b8:  fa 37 bf c6  sth  %i5, [ %fp + -58 ]
a00d68bc:  ee 37 bf c8  sth  %l7, [ %fp + -56 ]
a00d68c0:  e0 37 bf b8  sth  %l0, [ %fp + -72 ]
a00d68c4:  e0 37 bf ba  sth  %l0, [ %fp + -70 ]
a00d68c8:  ee 37 bf bc  sth  %l7, [ %fp + -68 ]
a00d68cc:  e8 37 bf be  sth  %l4, [ %fp + -66 ]
a00d68d0:  ee 37 bf c2  sth  %l7, [ %fp + -62 ]
a00d68d4:  80 a2 e0 00  cmp  %o3, 0
a00d68d8:  02 80 00 56  be  0xa00d6a30
a00d68dc:  fa 37 bf c4  sth  %i5, [ %fp + -60 ]
a00d68e0:  80 a6 20 01  cmp  %i0, 1
a00d68e4:  02 80 02 d9  be  0xa00d7448
a00d68e8:  9e 1a e0 01  xor  %o3, 1, %o7
a00d68ec:  04 80 01 bc  ble  0xa00d6fdc
a00d68f0:  80 a6 20 02  cmp  %i0, 2
a00d68f4:  02 80 03 00  be  0xa00d74f4
a00d68f8:  80 a6 20 03  cmp  %i0, 3
a00d68fc:  12 80 00 54  bne  0xa00d6a4c
a00d6900:  99 2c 20 10  sll  %l0, 0x10, %o4
a00d6904:  fa 02 a0 34  ld  [ %o2 + 0x34 ], %i5
a00d6908:  83 37 60 14  srl  %i5, 0x14, %g1
a00d690c:  82 08 60 0f  and  %g1, 0xf, %g1
a00d6910:  aa 00 40 01  add  %g1, %g1, %l5
a00d6914:  a8 05 40 01  add  %l5, %g1, %l4
a00d6918:  ae 05 00 14  add  %l4, %l4, %l7
a00d691c:  94 07 80 17  add  %fp, %l7, %o2
a00d6920:  10 80 00 4a  b  0xa00d6a48
a00d6924:  e0 12 bf b8  lduh  [ %o2 + -72 ], %l0
a00d6928:  80 a6 20 00  cmp  %i0, 0
a00d692c:  12 bf ff 89  bne  0xa00d6750
a00d6930:  ad 34 60 10  srl  %l1, 0x10, %l6
a00d6934:  d0 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %o0
a00d6938:  b6 02 00 08  add  %o0, %o0, %i3
a00d693c:  a0 06 c0 08  add  %i3, %o0, %l0
a00d6940:  b4 04 00 10  add  %l0, %l0, %i2
a00d6944:  ac 07 80 1a  add  %fp, %i2, %l6
a00d6948:  10 bf ff 7f  b  0xa00d6744
a00d694c:  da 15 bf d4  lduh  [ %l6 + -44 ], %o5
a00d6950:  40 01 c6 8b  call  0xa014837c
a00d6954:  90 10 20 00  clr  %o0
a00d6958:  40 01 c6 89  call  0xa014837c
a00d695c:  90 10 20 01  mov  1, %o0
a00d6960:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d6964:  94 12 22 90  or  %o0, 0x290, %o2	! 0xa802d290
a00d6968:  d6 0a a0 1f  ldub  [ %o2 + 0x1f ], %o3
a00d696c:  80 a2 e0 00  cmp  %o3, 0
a00d6970:  12 bf ff ab  bne  0xa00d681c
a00d6974:  80 a6 20 01  cmp  %i0, 1
a00d6978:  80 a6 20 00  cmp  %i0, 0
a00d697c:  12 bf ff ba  bne  0xa00d6864
a00d6980:  a0 10 20 01  mov  1, %l0
a00d6984:  c2 0a a1 a4  ldub  [ %o2 + 0x1a4 ], %g1
a00d6988:  9e 00 40 01  add  %g1, %g1, %o7
a00d698c:  92 03 c0 01  add  %o7, %g1, %o1
a00d6990:  9a 02 40 09  add  %o1, %o1, %o5
a00d6994:  b8 07 80 0d  add  %fp, %o5, %i4
a00d6998:  10 bf ff b1  b  0xa00d685c
a00d699c:  da 17 3f d4  lduh  [ %i4 + -44 ], %o5
a00d69a0:  9a 15 e2 90  or  %l7, 0x290, %o5
a00d69a4:  de 0b 60 1f  ldub  [ %o5 + 0x1f ], %o7
a00d69a8:  80 a3 e0 07  cmp  %o7, 7
a00d69ac:  12 bf fd e9  bne  0xa00d6150
a00d69b0:  e0 17 bf b6  lduh  [ %fp + -74 ], %l0
a00d69b4:  a9 2c 60 10  sll  %l1, 0x10, %l4
a00d69b8:  a1 2c e0 10  sll  %l3, 0x10, %l0
a00d69bc:  ab 35 20 11  srl  %l4, 0x11, %l5
a00d69c0:  10 bf fd e3  b  0xa00d614c
a00d69c4:  a9 34 20 11  srl  %l0, 0x11, %l4
a00d69c8:  a4 14 e2 90  or  %l3, 0x290, %l2
a00d69cc:  d8 0c a0 1f  ldub  [ %l2 + 0x1f ], %o4
a00d69d0:  80 a3 20 07  cmp  %o4, 7
a00d69d4:  32 bf fd ca  bne,a   0xa00d60fc
a00d69d8:  e2 37 bf b6  sth  %l1, [ %fp + -74 ]
a00d69dc:  ab 2c 60 10  sll  %l1, 0x10, %l5
a00d69e0:  a9 2a 20 10  sll  %o0, 0x10, %l4
a00d69e4:  a3 35 60 11  srl  %l5, 0x11, %l1
a00d69e8:  10 bf fd c4  b  0xa00d60f8
a00d69ec:  91 35 20 11  srl  %l4, 0x11, %o0
a00d69f0:  f4 17 bf 96  lduh  [ %fp + -106 ], %i2
a00d69f4:  c2 17 bf 9e  lduh  [ %fp + -98 ], %g1
a00d69f8:  93 2e a0 10  sll  %i2, 0x10, %o1
a00d69fc:  9f 28 60 10  sll  %g1, 0x10, %o7
a00d6a00:  80 a3 c0 09  cmp  %o7, %o1
a00d6a04:  b8 40 20 00  addx  %g0, 0, %i4
a00d6a08:  9b 34 e0 10  srl  %l3, 0x10, %o5
a00d6a0c:  97 34 60 10  srl  %l1, 0x10, %o3
a00d6a10:  80 a2 c0 0d  cmp  %o3, %o5
a00d6a14:  a6 40 20 00  addx  %g0, 0, %l3
a00d6a18:  80 97 00 13  orcc  %i4, %l3, %g0
a00d6a1c:  02 80 00 87  be  0xa00d6c38
a00d6a20:  a9 35 e0 10  srl  %l7, 0x10, %l4
a00d6a24:  d4 17 bf b6  lduh  [ %fp + -74 ], %o2
a00d6a28:  10 80 00 14  b  0xa00d6a78
a00d6a2c:  a0 10 00 0a  mov  %o2, %l0
a00d6a30:  d0 0a a1 a4  ldub  [ %o2 + 0x1a4 ], %o0
a00d6a34:  a0 02 00 08  add  %o0, %o0, %l0
a00d6a38:  b0 04 00 08  add  %l0, %o0, %i0
a00d6a3c:  b6 06 00 18  add  %i0, %i0, %i3
a00d6a40:  96 07 80 1b  add  %fp, %i3, %o3
a00d6a44:  e0 12 ff d0  lduh  [ %o3 + -48 ], %l0
a00d6a48:  99 2c 20 10  sll  %l0, 0x10, %o4
a00d6a4c:  ad 33 20 10  srl  %o4, 0x10, %l6
a00d6a50:  82 5c c0 16  smul  %l3, %l6, %g1
a00d6a54:  3b 00 00 04  sethi  %hi(0x1000), %i5
a00d6a58:  a8 17 63 88  or  %i5, 0x388, %l4	! 0x1388
a00d6a5c:  2f 34 6d c5  sethi  %hi(0xd1b71400), %l7
a00d6a60:  9e 00 40 14  add  %g1, %l4, %o7
a00d6a64:  b4 15 e3 59  or  %l7, 0x359, %i2
a00d6a68:  80 53 c0 1a  umul  %o7, %i2, %g0
a00d6a6c:  93 40 00 00  rd  %y, %o1
a00d6a70:  a1 32 60 0d  srl  %o1, 0xd, %l0
a00d6a74:  d4 17 bf b6  lduh  [ %fp + -74 ], %o2
a00d6a78:  99 2a a0 10  sll  %o2, 0x10, %o4
a00d6a7c:  a7 2c 20 10  sll  %l0, 0x10, %l3
a00d6a80:  97 34 60 10  srl  %l1, 0x10, %o3
a00d6a84:  ad 33 20 10  srl  %o4, 0x10, %l6
a00d6a88:  b1 34 e0 10  srl  %l3, 0x10, %i0
a00d6a8c:  d0 17 bf b4  lduh  [ %fp + -76 ], %o0
a00d6a90:  b6 25 80 18  sub  %l6, %i0, %i3
a00d6a94:  82 22 00 0b  sub  %o0, %o3, %g1
a00d6a98:  ab 36 e0 01  srl  %i3, 1, %l5
a00d6a9c:  a3 30 60 01  srl  %g1, 1, %l1
a00d6aa0:  ea 37 bf ae  sth  %l5, [ %fp + -82 ]
a00d6aa4:  10 bf fd ee  b  0xa00d625c
a00d6aa8:  e2 37 bf a6  sth  %l1, [ %fp + -90 ]
a00d6aac:  80 a0 00 10  cmp  %g0, %l0
a00d6ab0:  9a 60 3f ff  subx  %g0, -1, %o5
a00d6ab4:  ae 1a e0 05  xor  %o3, 5, %l7
a00d6ab8:  80 a0 00 17  cmp  %g0, %l7
a00d6abc:  9e 60 3f ff  subx  %g0, -1, %o7
a00d6ac0:  80 93 40 0f  orcc  %o5, %o7, %g0
a00d6ac4:  02 80 00 7a  be  0xa00d6cac
a00d6ac8:  a4 02 bf fa  add  %o2, -6, %l2
a00d6acc:  d8 0a 60 2f  ldub  [ %o1 + 0x2f ], %o4
a00d6ad0:  80 a3 20 00  cmp  %o4, 0
a00d6ad4:  12 80 02 75  bne  0xa00d74a8
a00d6ad8:  bb 2c 60 10  sll  %l1, 0x10, %i5
a00d6adc:  99 2c 60 10  sll  %l1, 0x10, %o4
a00d6ae0:  97 33 20 10  srl  %o4, 0x10, %o3
a00d6ae4:  94 02 c0 0b  add  %o3, %o3, %o2
a00d6ae8:  a2 02 80 0b  add  %o2, %o3, %l1
a00d6aec:  a7 3c 60 05  sra  %l1, 5, %l3
a00d6af0:  ab 2c e0 03  sll  %l3, 3, %l5
a00d6af4:  10 bf fd 96  b  0xa00d614c
a00d6af8:  a8 10 20 00  clr  %l4
a00d6afc:  c2 0a a1 a4  ldub  [ %o2 + 0x1a4 ], %g1
a00d6b00:  a6 00 40 01  add  %g1, %g1, %l3
a00d6b04:  96 04 c0 01  add  %l3, %g1, %o3
a00d6b08:  92 02 c0 0b  add  %o3, %o3, %o1
a00d6b0c:  a4 07 80 09  add  %fp, %o1, %l2
a00d6b10:  e0 14 bf d2  lduh  [ %l2 + -46 ], %l0
a00d6b14:  ad 2c 20 10  sll  %l0, 0x10, %l6
a00d6b18:  9f 35 a0 10  srl  %l6, 0x10, %o7
a00d6b1c:  82 5c 40 0f  smul  %l1, %o7, %g1
a00d6b20:  15 00 00 04  sethi  %hi(0x1000), %o2
a00d6b24:  90 12 a3 88  or  %o2, 0x388, %o0	! 0x1388
a00d6b28:  1b 34 6d c5  sethi  %hi(0xd1b71400), %o5
a00d6b2c:  b6 00 40 08  add  %g1, %o0, %i3
a00d6b30:  98 13 63 59  or  %o5, 0x359, %o4
a00d6b34:  80 56 c0 0c  umul  %i3, %o4, %g0
a00d6b38:  93 40 00 00  rd  %y, %o1
a00d6b3c:  10 bf fe d1  b  0xa00d6680
a00d6b40:  a5 32 60 0d  srl  %o1, 0xd, %l2
a00d6b44:  ac 5c 40 0c  smul  %l1, %o4, %l6
a00d6b48:  81 80 00 00  mov  %g0, %y
a00d6b4c:  01 00 00 00  nop
a00d6b50:  01 00 00 00  nop
a00d6b54:  01 00 00 00  nop
a00d6b58:  82 75 80 0a  udiv  %l6, %o2, %g1
a00d6b5c:  9f 28 60 10  sll  %g1, 0x10, %o7
a00d6b60:  97 33 e0 10  srl  %o7, 0x10, %o3
a00d6b64:  e6 17 bf b4  lduh  [ %fp + -76 ], %l3
a00d6b68:  80 a2 c0 13  cmp  %o3, %l3
a00d6b6c:  08 bf fe c5  bleu  0xa00d6680
a00d6b70:  a4 10 00 01  mov  %g1, %l2
a00d6b74:  10 bf fe c3  b  0xa00d6680
a00d6b78:  a4 10 00 13  mov  %l3, %l2
a00d6b7c:  19 00 00 09  sethi  %hi(0x2400), %o4
a00d6b80:  a0 13 23 10  or  %o4, 0x310, %l0	! 0x2710
a00d6b84:  92 15 63 20  or  %l5, 0x320, %o1
a00d6b88:  94 10 20 24  mov  0x24, %o2
a00d6b8c:  40 01 97 61  call  0xa013c910
a00d6b90:  90 10 00 14  mov  %l4, %o0
a00d6b94:  17 00 00 04  sethi  %hi(0x1000), %o3
a00d6b98:  2d 2a 00 b4  sethi  %hi(0xa802d000), %l6
a00d6b9c:  ba 12 e3 88  or  %o3, 0x388, %i5
a00d6ba0:  94 15 a2 90  or  %l6, 0x290, %o2
a00d6ba4:  11 00 00 07  sethi  %hi(0x1c00), %o0
a00d6ba8:  aa 10 20 11  mov  0x11, %l5
a00d6bac:  b6 12 21 4c  or  %o0, 0x14c, %i3
a00d6bb0:  d6 0a a0 1f  ldub  [ %o2 + 0x1f ], %o3
a00d6bb4:  f6 37 bf c0  sth  %i3, [ %fp + -64 ]
a00d6bb8:  fa 37 bf c6  sth  %i5, [ %fp + -58 ]
a00d6bbc:  ea 37 bf c8  sth  %l5, [ %fp + -56 ]
a00d6bc0:  e0 37 bf b8  sth  %l0, [ %fp + -72 ]
a00d6bc4:  e0 37 bf ba  sth  %l0, [ %fp + -70 ]
a00d6bc8:  ea 37 bf bc  sth  %l5, [ %fp + -68 ]
a00d6bcc:  f6 37 bf be  sth  %i3, [ %fp + -66 ]
a00d6bd0:  ea 37 bf c2  sth  %l5, [ %fp + -62 ]
a00d6bd4:  fa 37 bf c4  sth  %i5, [ %fp + -60 ]
a00d6bd8:  80 a2 e0 00  cmp  %o3, 0
a00d6bdc:  02 80 00 3c  be  0xa00d6ccc
a00d6be0:  93 34 60 10  srl  %l1, 0x10, %o1
a00d6be4:  80 a6 20 01  cmp  %i0, 1
a00d6be8:  02 80 02 69  be  0xa00d758c
a00d6bec:  ae 1a e0 01  xor  %o3, 1, %l7
a00d6bf0:  04 80 02 d0  ble  0xa00d7730
a00d6bf4:  80 a6 20 02  cmp  %i0, 2
a00d6bf8:  02 80 02 c9  be  0xa00d771c
a00d6bfc:  80 a6 20 03  cmp  %i0, 3
a00d6c00:  12 80 00 3a  bne  0xa00d6ce8
a00d6c04:  9b 2c 20 10  sll  %l0, 0x10, %o5
a00d6c08:  ea 02 a0 34  ld  [ %o2 + 0x34 ], %l5
a00d6c0c:  83 35 60 14  srl  %l5, 0x14, %g1
a00d6c10:  82 08 60 0f  and  %g1, 0xf, %g1
a00d6c14:  90 00 40 01  add  %g1, %g1, %o0
a00d6c18:  96 02 00 01  add  %o0, %g1, %o3
a00d6c1c:  b6 02 c0 0b  add  %o3, %o3, %i3
a00d6c20:  94 07 80 1b  add  %fp, %i3, %o2
a00d6c24:  10 80 00 30  b  0xa00d6ce4
a00d6c28:  e0 12 bf b8  lduh  [ %o2 + -72 ], %l0
a00d6c2c:  02 80 00 7d  be  0xa00d6e20
a00d6c30:  80 a0 60 07  cmp  %g1, 7
a00d6c34:  30 bf ff 68  b,a   0xa00d69d4
a00d6c38:  ae 5a c0 14  smul  %o3, %l4, %l7
a00d6c3c:  95 37 60 10  srl  %i5, 0x10, %o2
a00d6c40:  81 80 00 00  mov  %g0, %y
a00d6c44:  01 00 00 00  nop
a00d6c48:  01 00 00 00  nop
a00d6c4c:  01 00 00 00  nop
a00d6c50:  a0 75 c0 0a  udiv  %l7, %o2, %l0
a00d6c54:  10 bf ff 89  b  0xa00d6a78
a00d6c58:  d4 17 bf b6  lduh  [ %fp + -74 ], %o2
a00d6c5c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d6c60:  a2 12 22 90  or  %o0, 0x290, %l1	! 0xa802d290
a00d6c64:  da 0c 60 31  ldub  [ %l1 + 0x31 ], %o5
a00d6c68:  80 a3 60 00  cmp  %o5, 0
a00d6c6c:  a2 10 26 c0  mov  0x6c0, %l1
a00d6c70:  02 bf fd 22  be  0xa00d60f8
a00d6c74:  90 10 23 cc  mov  0x3cc, %o0
a00d6c78:  80 a3 60 01  cmp  %o5, 1
a00d6c7c:  a2 10 25 40  mov  0x540, %l1
a00d6c80:  02 bf fd 1e  be  0xa00d60f8
a00d6c84:  90 10 22 f4  mov  0x2f4, %o0
a00d6c88:  80 a3 60 02  cmp  %o5, 2
a00d6c8c:  02 bf fe 1a  be  0xa00d64f4
a00d6c90:  95 2b 60 04  sll  %o5, 4, %o2
a00d6c94:  a0 22 80 0d  sub  %o2, %o5, %l0
a00d6c98:  93 2b 60 03  sll  %o5, 3, %o1
a00d6c9c:  82 04 22 28  add  %l0, 0x228, %g1
a00d6ca0:  90 02 61 37  add  %o1, 0x137, %o0
a00d6ca4:  10 bf fd 15  b  0xa00d60f8
a00d6ca8:  a2 08 7f fe  and  %g1, -2, %l1
a00d6cac:  90 0c a0 ff  and  %l2, 0xff, %o0
a00d6cb0:  80 a2 20 01  cmp  %o0, 1
a00d6cb4:  18 bf fd 27  bgu  0xa00d6150
a00d6cb8:  e0 17 bf b6  lduh  [ %fp + -74 ], %l0
a00d6cbc:  ab 2c e0 10  sll  %l3, 0x10, %l5
a00d6cc0:  a9 35 60 11  srl  %l5, 0x11, %l4
a00d6cc4:  10 bf fd 23  b  0xa00d6150
a00d6cc8:  aa 10 20 00  clr  %l5
a00d6ccc:  e6 0a a1 a4  ldub  [ %o2 + 0x1a4 ], %l3
a00d6cd0:  a0 04 c0 13  add  %l3, %l3, %l0
a00d6cd4:  b0 04 00 13  add  %l0, %l3, %i0
a00d6cd8:  98 06 00 18  add  %i0, %i0, %o4
a00d6cdc:  ac 07 80 0c  add  %fp, %o4, %l6
a00d6ce0:  e0 15 bf d0  lduh  [ %l6 + -48 ], %l0
a00d6ce4:  9b 2c 20 10  sll  %l0, 0x10, %o5
a00d6ce8:  b9 33 60 10  srl  %o5, 0x10, %i4
a00d6cec:  10 bf ff 5a  b  0xa00d6a54
a00d6cf0:  82 5a 40 1c  smul  %o1, %i4, %g1
a00d6cf4:  02 bf ff 3a  be  0xa00d69dc
a00d6cf8:  80 a0 60 07  cmp  %g1, 7
a00d6cfc:  30 bf ff 36  b,a   0xa00d69d4
a00d6d00:  a4 10 00 1c  mov  %i4, %l2
a00d6d04:  9f 2c a0 10  sll  %l2, 0x10, %o7
a00d6d08:  13 00 00 0d  sethi  %hi(0x3400), %o1
a00d6d0c:  15 00 00 04  sethi  %hi(0x1000), %o2
a00d6d10:  99 33 e0 10  srl  %o7, 0x10, %o4
a00d6d14:  9a 12 60 15  or  %o1, 0x15, %o5
a00d6d18:  a6 12 a3 88  or  %o2, 0x388, %l3
a00d6d1c:  b0 5b 00 0d  smul  %o4, %o5, %i0
a00d6d20:  17 34 6d c5  sethi  %hi(0xd1b71400), %o3
a00d6d24:  b8 06 00 13  add  %i0, %l3, %i4
a00d6d28:  b6 12 e3 59  or  %o3, 0x359, %i3
a00d6d2c:  80 57 00 1b  umul  %i4, %i3, %g0
a00d6d30:  91 40 00 00  rd  %y, %o0
a00d6d34:  af 32 20 0d  srl  %o0, 0xd, %l7
a00d6d38:  94 10 00 16  mov  %l6, %o2
a00d6d3c:  83 2d e0 10  sll  %l7, 0x10, %g1
a00d6d40:  ab 2a a0 10  sll  %o2, 0x10, %l5
a00d6d44:  bb 35 60 10  srl  %l5, 0x10, %i5
a00d6d48:  a3 30 60 10  srl  %g1, 0x10, %l1
a00d6d4c:  a8 27 40 11  sub  %i5, %l1, %l4
a00d6d50:  a1 35 20 01  srl  %l4, 1, %l0
a00d6d54:  e0 37 bf ae  sth  %l0, [ %fp + -82 ]
a00d6d58:  e4 37 bf b4  sth  %l2, [ %fp + -76 ]
a00d6d5c:  ec 37 bf b6  sth  %l6, [ %fp + -74 ]
a00d6d60:  c0 37 bf b2  clrh  [ %fp + -78 ]
a00d6d64:  c0 37 bf b0  clrh  [ %fp + -80 ]
a00d6d68:  a0 10 00 17  mov  %l7, %l0
a00d6d6c:  c0 37 bf a6  clrh  [ %fp + -90 ]
a00d6d70:  10 80 03 02  b  0xa00d7978
a00d6d74:  90 10 00 12  mov  %l2, %o0
a00d6d78:  29 2a 00 b4  sethi  %hi(0xa802d000), %l4
a00d6d7c:  9a 15 22 90  or  %l4, 0x290, %o5	! 0xa802d290
a00d6d80:  c2 0b 60 2f  ldub  [ %o5 + 0x2f ], %g1
a00d6d84:  80 a0 60 00  cmp  %g1, 0
a00d6d88:  12 80 01 e8  bne  0xa00d7528
a00d6d8c:  80 a0 60 01  cmp  %g1, 1
a00d6d90:  ab 2c 60 10  sll  %l1, 0x10, %l5
a00d6d94:  83 35 60 15  srl  %l5, 0x15, %g1
a00d6d98:  10 bf fc d8  b  0xa00d60f8
a00d6d9c:  a3 28 60 03  sll  %g1, 3, %l1
a00d6da0:  2f 2a 00 b4  sethi  %hi(0xa802d000), %l7
a00d6da4:  a2 15 e2 90  or  %l7, 0x290, %l1	! 0xa802d290
a00d6da8:  c2 0c 60 4b  ldub  [ %l1 + 0x4b ], %g1
a00d6dac:  80 a0 60 00  cmp  %g1, 0
a00d6db0:  02 80 02 52  be  0xa00d76f8
a00d6db4:  80 a0 60 01  cmp  %g1, 1
a00d6db8:  02 80 02 6f  be  0xa00d7774
a00d6dbc:  01 00 00 00  nop
a00d6dc0:  40 01 c5 6f  call  0xa014837c
a00d6dc4:  90 10 20 01  mov  1, %o0	! 0x1
a00d6dc8:  a7 2a 20 10  sll  %o0, 0x10, %l3
a00d6dcc:  40 01 c5 6c  call  0xa014837c
a00d6dd0:  90 10 20 01  mov  1, %o0
a00d6dd4:  a5 2a 20 10  sll  %o0, 0x10, %l2
a00d6dd8:  a3 34 e0 11  srl  %l3, 0x11, %l1
a00d6ddc:  10 bf fc c7  b  0xa00d60f8
a00d6de0:  91 34 a0 11  srl  %l2, 0x11, %o0
a00d6de4:  80 a0 00 16  cmp  %g0, %l6
a00d6de8:  a6 60 3f ff  subx  %g0, -1, %l3
a00d6dec:  9e 1a e0 04  xor  %o3, 4, %o7
a00d6df0:  80 a0 00 0f  cmp  %g0, %o7
a00d6df4:  96 60 3f ff  subx  %g0, -1, %o3
a00d6df8:  80 94 c0 0b  orcc  %l3, %o3, %g0
a00d6dfc:  22 80 01 e2  be,a   0xa00d7584
a00d6e00:  f4 02 a0 34  ld  [ %o2 + 0x34 ], %i2
a00d6e04:  c2 0a a0 31  ldub  [ %o2 + 0x31 ], %g1
a00d6e08:  90 00 40 01  add  %g1, %g1, %o0
a00d6e0c:  a0 02 00 01  add  %o0, %g1, %l0
a00d6e10:  98 04 00 10  add  %l0, %l0, %o4
a00d6e14:  94 07 80 0c  add  %fp, %o4, %o2
a00d6e18:  10 bf ff 3f  b  0xa00d6b14
a00d6e1c:  e0 12 bf ba  lduh  [ %o2 + -70 ], %l0
a00d6e20:  9b 2c 60 10  sll  %l1, 0x10, %o5
a00d6e24:  10 bf fc b5  b  0xa00d60f8
a00d6e28:  a3 33 60 11  srl  %o5, 0x11, %l1
a00d6e2c:  a9 2d a0 10  sll  %l6, 0x10, %l4
a00d6e30:  93 35 e0 10  srl  %l7, 0x10, %o1
a00d6e34:  95 35 20 10  srl  %l4, 0x10, %o2
a00d6e38:  80 a2 80 09  cmp  %o2, %o1
a00d6e3c:  a1 2f 20 10  sll  %i4, 0x10, %l0
a00d6e40:  ae 40 20 00  addx  %g0, 0, %l7
a00d6e44:  99 37 60 10  srl  %i5, 0x10, %o4
a00d6e48:  97 34 20 10  srl  %l0, 0x10, %o3
a00d6e4c:  80 a2 c0 0c  cmp  %o3, %o4
a00d6e50:  a4 40 20 00  addx  %g0, 0, %l2
a00d6e54:  80 95 c0 12  orcc  %l7, %l2, %g0
a00d6e58:  32 bf fd c8  bne,a   0xa00d6578
a00d6e5c:  a4 10 00 1c  mov  %i4, %l2
a00d6e60:  a2 22 80 09  sub  %o2, %o1, %l1
a00d6e64:  ba 22 c0 0c  sub  %o3, %o4, %i5
a00d6e68:  ec 37 bf b6  sth  %l6, [ %fp + -74 ]
a00d6e6c:  a0 10 00 1a  mov  %i2, %l0
a00d6e70:  94 10 00 16  mov  %l6, %o2
a00d6e74:  b5 34 60 01  srl  %l1, 1, %i2
a00d6e78:  ad 37 60 01  srl  %i5, 1, %l6
a00d6e7c:  f8 37 bf b4  sth  %i4, [ %fp + -76 ]
a00d6e80:  a4 10 00 1b  mov  %i3, %l2
a00d6e84:  c0 37 bf b2  clrh  [ %fp + -78 ]
a00d6e88:  c0 37 bf b0  clrh  [ %fp + -80 ]
a00d6e8c:  f4 37 bf ae  sth  %i2, [ %fp + -82 ]
a00d6e90:  90 10 00 1c  mov  %i4, %o0
a00d6e94:  10 80 02 b9  b  0xa00d7978
a00d6e98:  ec 37 bf a6  sth  %l6, [ %fp + -90 ]
a00d6e9c:  a4 10 00 1c  mov  %i4, %l2
a00d6ea0:  9b 2c a0 10  sll  %l2, 0x10, %o5
a00d6ea4:  99 33 60 10  srl  %o5, 0x10, %o4
a00d6ea8:  95 35 e0 10  srl  %l7, 0x10, %o2
a00d6eac:  b0 5b 00 0a  smul  %o4, %o2, %i0
a00d6eb0:  a7 37 60 10  srl  %i5, 0x10, %l3
a00d6eb4:  81 80 00 00  mov  %g0, %y
a00d6eb8:  01 00 00 00  nop
a00d6ebc:  01 00 00 00  nop
a00d6ec0:  01 00 00 00  nop
a00d6ec4:  b6 76 00 13  udiv  %i0, %l3, %i3
a00d6ec8:  b9 2d a0 10  sll  %l6, 0x10, %i4
a00d6ecc:  97 2e e0 10  sll  %i3, 0x10, %o3
a00d6ed0:  80 a7 00 0b  cmp  %i4, %o3
a00d6ed4:  e4 37 bf b4  sth  %l2, [ %fp + -76 ]
a00d6ed8:  a0 10 00 1b  mov  %i3, %l0
a00d6edc:  1a 80 00 03  bcc  0xa00d6ee8
a00d6ee0:  99 37 20 10  srl  %i4, 0x10, %o4
a00d6ee4:  a0 10 00 16  mov  %l6, %l0
a00d6ee8:  b5 2c 20 10  sll  %l0, 0x10, %i2
a00d6eec:  9f 36 a0 10  srl  %i2, 0x10, %o7
a00d6ef0:  92 23 00 0f  sub  %o4, %o7, %o1
a00d6ef4:  ec 37 bf b6  sth  %l6, [ %fp + -74 ]
a00d6ef8:  94 10 00 16  mov  %l6, %o2
a00d6efc:  ad 32 60 01  srl  %o1, 1, %l6
a00d6f00:  c0 37 bf b2  clrh  [ %fp + -78 ]
a00d6f04:  c0 37 bf b0  clrh  [ %fp + -80 ]
a00d6f08:  ec 37 bf ae  sth  %l6, [ %fp + -82 ]
a00d6f0c:  10 bf ff 99  b  0xa00d6d70
a00d6f10:  c0 37 bf a6  clrh  [ %fp + -90 ]
a00d6f14:  9b 2d a0 10  sll  %l6, 0x10, %o5
a00d6f18:  80 a3 40 17  cmp  %o5, %l7
a00d6f1c:  98 40 20 00  addx  %g0, 0, %o4
a00d6f20:  95 2f 20 10  sll  %i4, 0x10, %o2
a00d6f24:  80 a2 80 1d  cmp  %o2, %i5
a00d6f28:  92 40 20 00  addx  %g0, 0, %o1
a00d6f2c:  83 33 60 10  srl  %o5, 0x10, %g1
a00d6f30:  80 93 00 09  orcc  %o4, %o1, %g0
a00d6f34:  12 bf fd 90  bne  0xa00d6574
a00d6f38:  9b 32 a0 10  srl  %o2, 0x10, %o5
a00d6f3c:  a0 00 73 20  add  %g1, -3296, %l0
a00d6f40:  a4 03 78 c4  add  %o5, -1852, %l2
a00d6f44:  af 34 20 01  srl  %l0, 1, %l7
a00d6f48:  9f 34 a0 01  srl  %l2, 1, %o7
a00d6f4c:  ec 37 bf b6  sth  %l6, [ %fp + -74 ]
a00d6f50:  f8 37 bf b4  sth  %i4, [ %fp + -76 ]
a00d6f54:  c0 37 bf b2  clrh  [ %fp + -78 ]
a00d6f58:  c0 37 bf b0  clrh  [ %fp + -80 ]
a00d6f5c:  94 10 00 16  mov  %l6, %o2
a00d6f60:  ee 37 bf ae  sth  %l7, [ %fp + -82 ]
a00d6f64:  90 10 00 1c  mov  %i4, %o0
a00d6f68:  de 37 bf a6  sth  %o7, [ %fp + -90 ]
a00d6f6c:  a0 10 2c e0  mov  0xce0, %l0
a00d6f70:  10 80 02 82  b  0xa00d7978
a00d6f74:  a4 10 27 3c  mov  0x73c, %l2
a00d6f78:  91 2d a0 10  sll  %l6, 0x10, %o0
a00d6f7c:  80 a2 00 17  cmp  %o0, %l7
a00d6f80:  b6 40 20 00  addx  %g0, 0, %i3
a00d6f84:  ab 2f 20 10  sll  %i4, 0x10, %l5
a00d6f88:  80 a5 40 1d  cmp  %l5, %i5
a00d6f8c:  82 40 20 00  addx  %g0, 0, %g1
a00d6f90:  80 96 c0 01  orcc  %i3, %g1, %g0
a00d6f94:  83 32 20 10  srl  %o0, 0x10, %g1
a00d6f98:  12 bf fd 77  bne  0xa00d6574
a00d6f9c:  9b 35 60 10  srl  %l5, 0x10, %o5
a00d6fa0:  a6 00 74 50  add  %g1, -2992, %l3
a00d6fa4:  96 03 79 70  add  %o5, -1680, %o3
a00d6fa8:  f8 37 bf b4  sth  %i4, [ %fp + -76 ]
a00d6fac:  90 10 00 1c  mov  %i4, %o0
a00d6fb0:  b1 34 e0 01  srl  %l3, 1, %i0
a00d6fb4:  b9 32 e0 01  srl  %o3, 1, %i4
a00d6fb8:  ec 37 bf b6  sth  %l6, [ %fp + -74 ]
a00d6fbc:  c0 37 bf b2  clrh  [ %fp + -78 ]
a00d6fc0:  c0 37 bf b0  clrh  [ %fp + -80 ]
a00d6fc4:  94 10 00 16  mov  %l6, %o2
a00d6fc8:  f0 37 bf ae  sth  %i0, [ %fp + -82 ]
a00d6fcc:  f8 37 bf a6  sth  %i4, [ %fp + -90 ]
a00d6fd0:  a0 10 2b b0  mov  0xbb0, %l0
a00d6fd4:  10 80 02 69  b  0xa00d7978
a00d6fd8:  a4 10 26 90  mov  0x690, %l2
a00d6fdc:  80 a6 20 00  cmp  %i0, 0
a00d6fe0:  12 bf fe 9b  bne  0xa00d6a4c
a00d6fe4:  99 2c 20 10  sll  %l0, 0x10, %o4
a00d6fe8:  ac 1a e0 01  xor  %o3, 1, %l6
a00d6fec:  80 a0 00 16  cmp  %g0, %l6
a00d6ff0:  a0 40 20 00  addx  %g0, 0, %l0
a00d6ff4:  90 1a e0 04  xor  %o3, 4, %o0
a00d6ff8:  80 a0 00 08  cmp  %g0, %o0
a00d6ffc:  b0 40 20 00  addx  %g0, 0, %i0
a00d7000:  80 8c 00 18  btst  %l0, %i0
a00d7004:  22 bf fe 8c  be,a   0xa00d6a34
a00d7008:  d0 0a a1 a4  ldub  [ %o2 + 0x1a4 ], %o0
a00d700c:  d8 02 a0 30  ld  [ %o2 + 0x30 ], %o4
a00d7010:  10 bf fe 3f  b  0xa00d690c
a00d7014:  83 33 20 0c  srl  %o4, 0xc, %g1
a00d7018:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d701c:  82 12 62 90  or  %o1, 0x290, %g1	! 0xa802d290
a00d7020:  c2 08 60 31  ldub  [ %g1 + 0x31 ], %g1
a00d7024:  aa 24 40 10  sub  %l1, %l0, %l5
a00d7028:  80 a0 60 00  cmp  %g1, 0
a00d702c:  02 bf fc 48  be  0xa00d614c
a00d7030:  a8 04 fc 34  add  %l3, -972, %l4
a00d7034:  80 a0 60 01  cmp  %g1, 1
a00d7038:  02 bf fc 45  be  0xa00d614c
a00d703c:  a8 04 fd 0c  add  %l3, -756, %l4
a00d7040:  90 10 20 01  mov  1, %o0
a00d7044:  40 01 b9 87  call  0xa0145660
a00d7048:  92 10 20 04  mov  4, %o1
a00d704c:  10 bf fc 40  b  0xa00d614c
a00d7050:  a8 04 fd e4  add  %l3, -540, %l4
a00d7054:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00d7058:  aa 14 a2 90  or  %l2, 0x290, %l5	! 0xa802d290
a00d705c:  c2 0d 60 31  ldub  [ %l5 + 0x31 ], %g1
a00d7060:  80 a0 60 00  cmp  %g1, 0
a00d7064:  10 bf ff f2  b  0xa00d702c
a00d7068:  aa 10 20 00  clr  %l5
a00d706c:  aa 24 40 10  sub  %l1, %l0, %l5
a00d7070:  10 bf fc 37  b  0xa00d614c
a00d7074:  a8 10 20 00  clr  %l4
a00d7078:  aa 10 20 00  clr  %l5
a00d707c:  10 bf fc 34  b  0xa00d614c
a00d7080:  a8 10 20 00  clr  %l4
a00d7084:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00d7088:  a4 14 e2 90  or  %l3, 0x290, %l2	! 0xa802d290
a00d708c:  c2 0c a0 31  ldub  [ %l2 + 0x31 ], %g1
a00d7090:  80 a0 60 00  cmp  %g1, 0
a00d7094:  02 80 01 f4  be  0xa00d7864
a00d7098:  80 a0 60 01  cmp  %g1, 1
a00d709c:  02 80 02 11  be  0xa00d78e0
a00d70a0:  80 a0 60 02  cmp  %g1, 2
a00d70a4:  12 bf fc 2b  bne  0xa00d6150
a00d70a8:  e0 17 bf b6  lduh  [ %fp + -74 ], %l0
a00d70ac:  e2 14 a0 54  lduh  [ %l2 + 0x54 ], %l1
a00d70b0:  e8 14 a0 56  lduh  [ %l2 + 0x56 ], %l4
a00d70b4:  40 01 c4 b2  call  0xa014837c
a00d70b8:  90 10 20 00  clr  %o0
a00d70bc:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00d70c0:  95 33 e0 10  srl  %o7, 0x10, %o2
a00d70c4:  92 02 bc 40  add  %o2, -960, %o1
a00d70c8:  80 a4 40 09  cmp  %l1, %o1
a00d70cc:  04 80 00 07  ble  0xa00d70e8
a00d70d0:  aa 10 00 11  mov  %l1, %l5
a00d70d4:  40 01 c4 aa  call  0xa014837c
a00d70d8:  90 10 20 00  clr  %o0
a00d70dc:  96 02 3c 40  add  %o0, -960, %o3
a00d70e0:  d6 34 a0 54  sth  %o3, [ %l2 + 0x54 ]
a00d70e4:  aa 10 00 0b  mov  %o3, %l5
a00d70e8:  40 01 c4 a5  call  0xa014837c
a00d70ec:  90 10 20 01  mov  1, %o0
a00d70f0:  99 2a 20 10  sll  %o0, 0x10, %o4
a00d70f4:  a1 33 20 10  srl  %o4, 0x10, %l0
a00d70f8:  90 10 20 01  mov  1, %o0
a00d70fc:  40 01 b9 59  call  0xa0145660
a00d7100:  92 10 20 04  mov  4, %o1
a00d7104:  bb 2d 20 10  sll  %l4, 0x10, %i5
a00d7108:  af 37 60 10  srl  %i5, 0x10, %l7
a00d710c:  9a 04 3d e4  add  %l0, -540, %o5
a00d7110:  80 a5 c0 0d  cmp  %l7, %o5
a00d7114:  04 bf fc 0f  ble  0xa00d6150
a00d7118:  e0 17 bf b6  lduh  [ %fp + -74 ], %l0
a00d711c:  40 01 c4 98  call  0xa014837c
a00d7120:  90 10 20 01  mov  1, %o0
a00d7124:  a8 10 00 08  mov  %o0, %l4
a00d7128:  90 10 20 01  mov  1, %o0
a00d712c:  40 01 b9 4d  call  0xa0145660
a00d7130:  92 10 20 04  mov  4, %o1
a00d7134:  90 05 3d e4  add  %l4, -540, %o0
a00d7138:  d0 34 a0 56  sth  %o0, [ %l2 + 0x56 ]
a00d713c:  10 bf fc 04  b  0xa00d614c
a00d7140:  a8 10 00 08  mov  %o0, %l4
a00d7144:  d2 03 20 30  ld  [ %o4 + 0x30 ], %o1
a00d7148:  82 0a 60 0f  and  %o1, 0xf, %g1
a00d714c:  80 a0 60 01  cmp  %g1, 1
a00d7150:  02 80 00 e0  be  0xa00d74d0
a00d7154:  9b 2c 60 10  sll  %l1, 0x10, %o5
a00d7158:  04 80 01 24  ble  0xa00d75e8
a00d715c:  80 a0 60 02  cmp  %g1, 2
a00d7160:  22 80 01 15  be,a   0xa00d75b4
a00d7164:  a3 2c e0 10  sll  %l3, 0x10, %l1
a00d7168:  80 a0 60 03  cmp  %g1, 3
a00d716c:  32 bf fb f9  bne,a   0xa00d6150
a00d7170:  e0 17 bf b6  lduh  [ %fp + -74 ], %l0
a00d7174:  99 2c 60 10  sll  %l1, 0x10, %o4
a00d7178:  97 2c 20 10  sll  %l0, 0x10, %o3
a00d717c:  9b 33 20 11  srl  %o4, 0x11, %o5
a00d7180:  95 32 e0 10  srl  %o3, 0x10, %o2
a00d7184:  80 a2 80 0d  cmp  %o2, %o5
a00d7188:  18 80 00 03  bgu  0xa00d7194
a00d718c:  aa 24 40 10  sub  %l1, %l0, %l5
a00d7190:  aa 10 00 0d  mov  %o5, %l5
a00d7194:  83 2c e0 10  sll  %l3, 0x10, %g1
a00d7198:  91 2c a0 10  sll  %l2, 0x10, %o0
a00d719c:  9b 30 60 11  srl  %g1, 0x11, %o5
a00d71a0:  bb 32 20 10  srl  %o0, 0x10, %i5
a00d71a4:  a8 24 c0 12  sub  %l3, %l2, %l4
a00d71a8:  80 a7 40 0d  cmp  %i5, %o5
a00d71ac:  28 bf fb e8  bleu,a   0xa00d614c
a00d71b0:  a8 10 00 0d  mov  %o5, %l4
a00d71b4:  10 bf fb e7  b  0xa00d6150
a00d71b8:  e0 17 bf b6  lduh  [ %fp + -74 ], %l0
a00d71bc:  15 00 00 09  sethi  %hi(0x2400), %o2
a00d71c0:  a0 12 a3 10  or  %o2, 0x310, %l0	! 0x2710
a00d71c4:  92 15 63 20  or  %l5, 0x320, %o1
a00d71c8:  94 10 20 24  mov  0x24, %o2
a00d71cc:  40 01 95 d1  call  0xa013c910
a00d71d0:  90 10 00 14  mov  %l4, %o0
a00d71d4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d71d8:  94 12 22 90  or  %o0, 0x290, %o2	! 0xa802d290
a00d71dc:  1b 00 00 07  sethi  %hi(0x1c00), %o5
a00d71e0:  19 00 00 04  sethi  %hi(0x1000), %o4
a00d71e4:  b4 10 20 11  mov  0x11, %i2
a00d71e8:  b6 13 61 4c  or  %o5, 0x14c, %i3
a00d71ec:  a2 13 23 88  or  %o4, 0x388, %l1
a00d71f0:  d6 0a a0 1f  ldub  [ %o2 + 0x1f ], %o3
a00d71f4:  f6 37 bf c0  sth  %i3, [ %fp + -64 ]
a00d71f8:  e2 37 bf c6  sth  %l1, [ %fp + -58 ]
a00d71fc:  f4 37 bf c8  sth  %i2, [ %fp + -56 ]
a00d7200:  e0 37 bf b8  sth  %l0, [ %fp + -72 ]
a00d7204:  e0 37 bf ba  sth  %l0, [ %fp + -70 ]
a00d7208:  f4 37 bf bc  sth  %i2, [ %fp + -68 ]
a00d720c:  f6 37 bf be  sth  %i3, [ %fp + -66 ]
a00d7210:  f4 37 bf c2  sth  %i2, [ %fp + -62 ]
a00d7214:  e2 37 bf c4  sth  %l1, [ %fp + -60 ]
a00d7218:  80 a2 e0 00  cmp  %o3, 0
a00d721c:  02 80 00 3f  be  0xa00d7318
a00d7220:  93 37 60 10  srl  %i5, 0x10, %o1
a00d7224:  80 a6 20 01  cmp  %i0, 1
a00d7228:  22 80 00 f5  be,a   0xa00d75fc
a00d722c:  b4 1a e0 01  xor  %o3, 1, %i2
a00d7230:  04 80 01 75  ble  0xa00d7804
a00d7234:  80 a6 20 02  cmp  %i0, 2
a00d7238:  02 80 01 6b  be  0xa00d77e4
a00d723c:  80 a6 20 03  cmp  %i0, 3
a00d7240:  22 80 01 86  be,a   0xa00d7858
a00d7244:  da 02 a0 34  ld  [ %o2 + 0x34 ], %o5
a00d7248:  b5 2c 20 10  sll  %l0, 0x10, %i2
a00d724c:  a3 36 a0 10  srl  %i2, 0x10, %l1
a00d7250:  10 bf fe 34  b  0xa00d6b20
a00d7254:  82 5a 40 11  smul  %o1, %l1, %g1
a00d7258:  02 bf fd 83  be  0xa00d6864
a00d725c:  a0 10 20 01  mov  1, %l0
a00d7260:  b4 1a e0 01  xor  %o3, 1, %i2
a00d7264:  80 a0 00 1a  cmp  %g0, %i2
a00d7268:  9e 60 3f ff  subx  %g0, -1, %o7
a00d726c:  82 1a e0 04  xor  %o3, 4, %g1
a00d7270:  80 a0 00 01  cmp  %g0, %g1
a00d7274:  92 60 3f ff  subx  %g0, -1, %o1
a00d7278:  80 93 c0 09  orcc  %o7, %o1, %g0
a00d727c:  22 80 00 93  be,a   0xa00d74c8
a00d7280:  d6 02 a0 34  ld  [ %o2 + 0x34 ], %o3
a00d7284:  10 bf fd 71  b  0xa00d6848
a00d7288:  da 0a a0 31  ldub  [ %o2 + 0x31 ], %o5
a00d728c:  80 a0 00 1b  cmp  %g0, %i3
a00d7290:  ac 60 3f ff  subx  %g0, -1, %l6
a00d7294:  b4 1a a0 04  xor  %o2, 4, %i2
a00d7298:  80 a0 00 1a  cmp  %g0, %i2
a00d729c:  9e 60 3f ff  subx  %g0, -1, %o7
a00d72a0:  80 95 80 0f  orcc  %l6, %o7, %g0
a00d72a4:  02 80 00 73  be  0xa00d7470
a00d72a8:  80 a2 a0 02  cmp  %o2, 2
a00d72ac:  10 bf fc 14  b  0xa00d62fc
a00d72b0:  da 0c 60 31  ldub  [ %l1 + 0x31 ], %o5
a00d72b4:  80 a0 00 0a  cmp  %g0, %o2
a00d72b8:  98 60 3f ff  subx  %g0, -1, %o4
a00d72bc:  9a 1a 60 04  xor  %o1, 4, %o5
a00d72c0:  80 a0 00 0d  cmp  %g0, %o5
a00d72c4:  90 60 3f ff  subx  %g0, -1, %o0
a00d72c8:  80 93 00 08  orcc  %o4, %o0, %g0
a00d72cc:  02 80 00 70  be  0xa00d748c
a00d72d0:  80 a2 60 02  cmp  %o1, 2
a00d72d4:  10 bf fd 17  b  0xa00d6730
a00d72d8:  da 0c 20 31  ldub  [ %l0 + 0x31 ], %o5
a00d72dc:  80 a2 e0 04  cmp  %o3, 4
a00d72e0:  22 80 00 be  be,a   0xa00d75d8
a00d72e4:  ec 02 a0 30  ld  [ %o2 + 0x30 ], %l6
a00d72e8:  10 bf fd 57  b  0xa00d6844
a00d72ec:  da 0a a0 34  ldub  [ %o2 + 0x34 ], %o5
a00d72f0:  80 a2 60 04  cmp  %o1, 4
a00d72f4:  22 80 00 b7  be,a   0xa00d75d0
a00d72f8:  d6 04 20 30  ld  [ %l0 + 0x30 ], %o3
a00d72fc:  10 bf fd 0c  b  0xa00d672c
a00d7300:  da 0c 20 34  ldub  [ %l0 + 0x34 ], %o5
a00d7304:  80 a2 a0 04  cmp  %o2, 4
a00d7308:  22 80 00 b6  be,a   0xa00d75e0
a00d730c:  d8 04 60 30  ld  [ %l1 + 0x30 ], %o4
a00d7310:  10 bf fb fa  b  0xa00d62f8
a00d7314:  da 0c 60 34  ldub  [ %l1 + 0x34 ], %o5
a00d7318:  ec 0a a1 a4  ldub  [ %o2 + 0x1a4 ], %l6
a00d731c:  9e 05 80 16  add  %l6, %l6, %o7
a00d7320:  96 03 c0 16  add  %o7, %l6, %o3
a00d7324:  82 02 c0 0b  add  %o3, %o3, %g1
a00d7328:  a6 07 80 01  add  %fp, %g1, %l3
a00d732c:  10 bf ff c7  b  0xa00d7248
a00d7330:  e0 14 ff d2  lduh  [ %l3 + -46 ], %l0
a00d7334:  80 a6 20 00  cmp  %i0, 0
a00d7338:  12 bf fd 4c  bne  0xa00d6868
a00d733c:  9a 0c 20 03  and  %l0, 3, %o5
a00d7340:  b8 1a e0 02  xor  %o3, 2, %i4
a00d7344:  80 a0 00 1c  cmp  %g0, %i4
a00d7348:  98 60 3f ff  subx  %g0, -1, %o4
a00d734c:  9a 1a e0 05  xor  %o3, 5, %o5
a00d7350:  80 a0 00 0d  cmp  %g0, %o5
a00d7354:  ac 60 3f ff  subx  %g0, -1, %l6
a00d7358:  80 93 00 16  orcc  %o4, %l6, %g0
a00d735c:  32 bf fd 42  bne,a   0xa00d6864
a00d7360:  a0 10 20 01  mov  1, %l0
a00d7364:  80 a2 e0 06  cmp  %o3, 6
a00d7368:  02 80 00 04  be  0xa00d7378
a00d736c:  80 a2 e0 07  cmp  %o3, 7
a00d7370:  32 bf fd 86  bne,a   0xa00d6988
a00d7374:  c2 0a a1 a4  ldub  [ %o2 + 0x1a4 ], %g1
a00d7378:  10 bf fd 3b  b  0xa00d6864
a00d737c:  a0 10 20 01  mov  1, %l0
a00d7380:  80 a6 20 00  cmp  %i0, 0
a00d7384:  12 bf fc f3  bne  0xa00d6750
a00d7388:  ad 34 60 10  srl  %l1, 0x10, %l6
a00d738c:  b4 1a 60 02  xor  %o1, 2, %i2
a00d7390:  80 a0 00 1a  cmp  %g0, %i2
a00d7394:  9e 60 3f ff  subx  %g0, -1, %o7
a00d7398:  ac 1a 60 05  xor  %o1, 5, %l6
a00d739c:  80 a0 00 16  cmp  %g0, %l6
a00d73a0:  96 60 3f ff  subx  %g0, -1, %o3
a00d73a4:  80 93 c0 0b  orcc  %o7, %o3, %g0
a00d73a8:  12 80 00 08  bne  0xa00d73c8
a00d73ac:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a00d73b0:  80 a2 60 06  cmp  %o1, 6
a00d73b4:  02 80 00 05  be  0xa00d73c8
a00d73b8:  80 a2 60 07  cmp  %o1, 7
a00d73bc:  32 bf fd 5f  bne,a   0xa00d6938
a00d73c0:  d0 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %o0
a00d73c4:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a00d73c8:  9a 16 e2 90  or  %i3, 0x290, %o5	! 0xa802d290
a00d73cc:  e0 0b 60 1f  ldub  [ %o5 + 0x1f ], %l0
a00d73d0:  80 a4 20 02  cmp  %l0, 2
a00d73d4:  02 80 00 bf  be  0xa00d76d0
a00d73d8:  da 03 60 30  ld  [ %o5 + 0x30 ], %o5
a00d73dc:  10 bf fc d4  b  0xa00d672c
a00d73e0:  9b 33 60 0c  srl  %o5, 0xc, %o5
a00d73e4:  80 a6 20 00  cmp  %i0, 0
a00d73e8:  32 bf fb cd  bne,a   0xa00d631c
a00d73ec:  9a 0b 60 03  and  %o5, 3, %o5
a00d73f0:  96 1a a0 02  xor  %o2, 2, %o3
a00d73f4:  80 a0 00 0b  cmp  %g0, %o3
a00d73f8:  92 60 3f ff  subx  %g0, -1, %o1
a00d73fc:  82 1a a0 05  xor  %o2, 5, %g1
a00d7400:  80 a0 00 01  cmp  %g0, %g1
a00d7404:  a4 60 3f ff  subx  %g0, -1, %l2
a00d7408:  80 92 40 12  orcc  %o1, %l2, %g0
a00d740c:  32 80 00 08  bne,a   0xa00d742c
a00d7410:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00d7414:  80 a2 a0 06  cmp  %o2, 6
a00d7418:  02 80 00 04  be  0xa00d7428
a00d741c:  80 a2 a0 07  cmp  %o2, 7
a00d7420:  32 bf fc 3f  bne,a   0xa00d651c
a00d7424:  d4 0c 61 a4  ldub  [ %l1 + 0x1a4 ], %o2
a00d7428:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00d742c:  9a 12 a2 90  or  %o2, 0x290, %o5	! 0xa802d290
a00d7430:  e2 0b 60 1f  ldub  [ %o5 + 0x1f ], %l1
a00d7434:  80 a4 60 02  cmp  %l1, 2
a00d7438:  02 80 00 8e  be  0xa00d7670
a00d743c:  da 03 60 30  ld  [ %o5 + 0x30 ], %o5
a00d7440:  10 bf fb ae  b  0xa00d62f8
a00d7444:  9b 33 60 0c  srl  %o5, 0xc, %o5
a00d7448:  80 a0 00 0f  cmp  %g0, %o7
a00d744c:  9a 60 3f ff  subx  %g0, -1, %o5
a00d7450:  92 1a e0 04  xor  %o3, 4, %o1
a00d7454:  80 a0 00 09  cmp  %g0, %o1
a00d7458:  b8 60 3f ff  subx  %g0, -1, %i4
a00d745c:  80 93 40 1c  orcc  %o5, %i4, %g0
a00d7460:  22 80 00 2a  be,a   0xa00d7508
a00d7464:  c2 02 a0 34  ld  [ %o2 + 0x34 ], %g1
a00d7468:  10 bf fd 2a  b  0xa00d6910
a00d746c:  c2 0a a0 31  ldub  [ %o2 + 0x31 ], %g1
a00d7470:  22 80 00 72  be,a   0xa00d7638
a00d7474:  da 0c 60 2f  ldub  [ %l1 + 0x2f ], %o5
a00d7478:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00d747c:  a0 13 62 90  or  %o5, 0x290, %l0	! 0xa802d290
a00d7480:  da 04 20 30  ld  [ %l0 + 0x30 ], %o5
a00d7484:  10 bf fb 9d  b  0xa00d62f8
a00d7488:  9b 33 60 0c  srl  %o5, 0xc, %o5
a00d748c:  22 80 00 83  be,a   0xa00d7698
a00d7490:  da 0c 20 2f  ldub  [ %l0 + 0x2f ], %o5
a00d7494:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d7498:  a6 10 62 90  or  %g1, 0x290, %l3	! 0xa802d290
a00d749c:  da 04 e0 30  ld  [ %l3 + 0x30 ], %o5
a00d74a0:  10 bf fc a3  b  0xa00d672c
a00d74a4:  9b 33 60 0c  srl  %o5, 0xc, %o5
a00d74a8:  80 a3 20 01  cmp  %o4, 1
a00d74ac:  02 bf fd 92  be  0xa00d6af4
a00d74b0:  ab 37 60 11  srl  %i5, 0x11, %l5
a00d74b4:  80 a3 20 02  cmp  %o4, 2
a00d74b8:  12 bf fb 25  bne  0xa00d614c
a00d74bc:  a8 10 20 00  clr  %l4
a00d74c0:  10 bf fb 23  b  0xa00d614c
a00d74c4:  ea 12 61 f0  lduh  [ %o1 + 0x1f0 ], %l5
a00d74c8:  10 bf fc e0  b  0xa00d6848
a00d74cc:  9b 32 e0 1c  srl  %o3, 0x1c, %o5
a00d74d0:  9f 2c 20 10  sll  %l0, 0x10, %o7
a00d74d4:  9b 33 60 11  srl  %o5, 0x11, %o5
a00d74d8:  a9 33 e0 10  srl  %o7, 0x10, %l4
a00d74dc:  80 a5 00 0d  cmp  %l4, %o5
a00d74e0:  18 bf fd 85  bgu  0xa00d6af4
a00d74e4:  aa 24 40 10  sub  %l1, %l0, %l5
a00d74e8:  aa 10 00 0d  mov  %o5, %l5
a00d74ec:  10 bf fb 18  b  0xa00d614c
a00d74f0:  a8 10 20 00  clr  %l4
a00d74f4:  80 a2 e0 04  cmp  %o3, 4
a00d74f8:  22 80 00 c1  be,a   0xa00d77fc
a00d74fc:  f4 02 a0 30  ld  [ %o2 + 0x30 ], %i2
a00d7500:  10 bf fd 03  b  0xa00d690c
a00d7504:  c2 0a a0 34  ldub  [ %o2 + 0x34 ], %g1
a00d7508:  10 bf fd 02  b  0xa00d6910
a00d750c:  83 30 60 1c  srl  %g1, 0x1c, %g1
a00d7510:  80 a2 e0 04  cmp  %o3, 4
a00d7514:  22 80 00 ce  be,a   0xa00d784c
a00d7518:  f6 02 a0 30  ld  [ %o2 + 0x30 ], %i3
a00d751c:  c2 0a a0 34  ldub  [ %o2 + 0x34 ], %g1
a00d7520:  10 bf fe 3a  b  0xa00d6e08
a00d7524:  82 08 60 0f  and  %g1, 0xf, %g1
a00d7528:  02 80 00 a4  be  0xa00d77b8
a00d752c:  80 a0 60 02  cmp  %g1, 2
a00d7530:  32 bf fe 3d  bne,a   0xa00d6e24
a00d7534:  9b 2c 60 10  sll  %l1, 0x10, %o5
a00d7538:  fa 13 61 f0  lduh  [ %o5 + 0x1f0 ], %i5
a00d753c:  10 bf fa ef  b  0xa00d60f8
a00d7540:  a2 24 40 1d  sub  %l1, %i5, %l1
a00d7544:  80 a6 20 00  cmp  %i0, 0
a00d7548:  12 bf fd 74  bne  0xa00d6b18
a00d754c:  ad 2c 20 10  sll  %l0, 0x10, %l6
a00d7550:  92 1a e0 01  xor  %o3, 1, %o1
a00d7554:  80 a0 00 09  cmp  %g0, %o1
a00d7558:  90 40 20 00  addx  %g0, 0, %o0
a00d755c:  a4 1a e0 04  xor  %o3, 4, %l2
a00d7560:  80 a0 00 12  cmp  %g0, %l2
a00d7564:  a0 40 20 00  addx  %g0, 0, %l0
a00d7568:  80 8a 00 10  btst  %o0, %l0
a00d756c:  22 bf fd 65  be,a   0xa00d6b00
a00d7570:  c2 0a a1 a4  ldub  [ %o2 + 0x1a4 ], %g1
a00d7574:  c2 02 a0 30  ld  [ %o2 + 0x30 ], %g1
a00d7578:  83 30 60 0c  srl  %g1, 0xc, %g1
a00d757c:  10 bf fe 23  b  0xa00d6e08
a00d7580:  82 08 60 0f  and  %g1, 0xf, %g1
a00d7584:  10 bf fe 21  b  0xa00d6e08
a00d7588:  83 36 a0 1c  srl  %i2, 0x1c, %g1
a00d758c:  80 a0 00 17  cmp  %g0, %l7
a00d7590:  b4 60 3f ff  subx  %g0, -1, %i2
a00d7594:  82 1a e0 04  xor  %o3, 4, %g1
a00d7598:  80 a0 00 01  cmp  %g0, %g1
a00d759c:  9e 60 3f ff  subx  %g0, -1, %o7
a00d75a0:  80 96 80 0f  orcc  %i2, %o7, %g0
a00d75a4:  22 80 00 72  be,a   0xa00d776c
a00d75a8:  e8 02 a0 34  ld  [ %o2 + 0x34 ], %l4
a00d75ac:  10 bf fd 9a  b  0xa00d6c14
a00d75b0:  c2 0a a0 31  ldub  [ %o2 + 0x31 ], %g1
a00d75b4:  a1 2c a0 10  sll  %l2, 0x10, %l0
a00d75b8:  9b 34 60 11  srl  %l1, 0x11, %o5
a00d75bc:  af 34 20 10  srl  %l0, 0x10, %l7
a00d75c0:  a8 24 c0 12  sub  %l3, %l2, %l4
a00d75c4:  80 a5 c0 0d  cmp  %l7, %o5
a00d75c8:  10 bf fe f9  b  0xa00d71ac
a00d75cc:  aa 10 20 00  clr  %l5
a00d75d0:  10 bf fc 57  b  0xa00d672c
a00d75d4:  9b 32 e0 08  srl  %o3, 8, %o5
a00d75d8:  10 bf fc 9b  b  0xa00d6844
a00d75dc:  9b 35 a0 08  srl  %l6, 8, %o5
a00d75e0:  10 bf fb 46  b  0xa00d62f8
a00d75e4:  9b 33 20 08  srl  %o4, 8, %o5
a00d75e8:  80 a0 60 00  cmp  %g1, 0
a00d75ec:  22 bf fa d8  be,a   0xa00d614c
a00d75f0:  aa 10 20 00  clr  %l5
a00d75f4:  10 bf fa d7  b  0xa00d6150
a00d75f8:  e0 17 bf b6  lduh  [ %fp + -74 ], %l0
a00d75fc:  80 a0 00 1a  cmp  %g0, %i2
a00d7600:  ac 60 3f ff  subx  %g0, -1, %l6
a00d7604:  a2 1a e0 04  xor  %o3, 4, %l1
a00d7608:  80 a0 00 11  cmp  %g0, %l1
a00d760c:  9e 60 3f ff  subx  %g0, -1, %o7
a00d7610:  80 95 80 0f  orcc  %l6, %o7, %g0
a00d7614:  22 80 00 8c  be,a   0xa00d7844
a00d7618:  f6 02 a0 34  ld  [ %o2 + 0x34 ], %i3
a00d761c:  c2 0a a0 31  ldub  [ %o2 + 0x31 ], %g1
a00d7620:  a4 00 40 01  add  %g1, %g1, %l2
a00d7624:  a0 04 80 01  add  %l2, %g1, %l0
a00d7628:  94 04 00 10  add  %l0, %l0, %o2
a00d762c:  90 07 80 0a  add  %fp, %o2, %o0
a00d7630:  10 bf ff 06  b  0xa00d7248
a00d7634:  e0 12 3f ba  lduh  [ %o0 + -70 ], %l0
a00d7638:  92 03 7f ff  add  %o5, -1, %o1
a00d763c:  a4 0a 60 ff  and  %o1, 0xff, %l2
a00d7640:  80 a4 a0 01  cmp  %l2, 1
a00d7644:  28 80 00 0b  bleu,a   0xa00d7670
a00d7648:  da 04 60 30  ld  [ %l1 + 0x30 ], %o5
a00d764c:  80 a3 60 00  cmp  %o5, 0
a00d7650:  12 bf ff 8b  bne  0xa00d747c
a00d7654:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00d7658:  7f fe b3 a8  call  0xa00844f8
a00d765c:  01 00 00 00  nop
a00d7660:  80 8a 20 ff  btst  0xff, %o0
a00d7664:  32 bf ff 86  bne,a   0xa00d747c
a00d7668:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00d766c:  da 04 60 30  ld  [ %l1 + 0x30 ], %o5
a00d7670:  b7 33 60 0c  srl  %o5, 0xc, %i3
a00d7674:  b4 0e e0 0f  and  %i3, 0xf, %i2
a00d7678:  ac 06 80 1a  add  %i2, %i2, %l6
a00d767c:  9e 05 80 1a  add  %l6, %i2, %o7
a00d7680:  94 03 c0 0f  add  %o7, %o7, %o2
a00d7684:  a2 07 80 0a  add  %fp, %o2, %l1
a00d7688:  d6 14 7f bc  lduh  [ %l1 + -68 ], %o3
a00d768c:  83 32 e0 03  srl  %o3, 3, %g1
a00d7690:  10 bf fb 22  b  0xa00d6318
a00d7694:  9a 08 60 03  and  %g1, 3, %o5
a00d7698:  ac 03 7f ff  add  %o5, -1, %l6
a00d769c:  9e 0d a0 ff  and  %l6, 0xff, %o7
a00d76a0:  80 a3 e0 01  cmp  %o7, 1
a00d76a4:  28 80 00 0b  bleu,a   0xa00d76d0
a00d76a8:  da 04 20 30  ld  [ %l0 + 0x30 ], %o5
a00d76ac:  80 a3 60 00  cmp  %o5, 0
a00d76b0:  12 bf ff 7a  bne  0xa00d7498
a00d76b4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d76b8:  7f fe b3 90  call  0xa00844f8
a00d76bc:  01 00 00 00  nop
a00d76c0:  80 8a 20 ff  btst  0xff, %o0
a00d76c4:  12 bf ff 75  bne  0xa00d7498
a00d76c8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d76cc:  da 04 20 30  ld  [ %l0 + 0x30 ], %o5
a00d76d0:  93 33 60 0c  srl  %o5, 0xc, %o1
a00d76d4:  9a 0a 60 0f  and  %o1, 0xf, %o5
a00d76d8:  94 03 40 0d  add  %o5, %o5, %o2
a00d76dc:  98 02 80 0d  add  %o2, %o5, %o4
a00d76e0:  90 03 00 0c  add  %o4, %o4, %o0
a00d76e4:  b6 07 80 08  add  %fp, %o0, %i3
a00d76e8:  e0 16 ff bc  lduh  [ %i3 + -68 ], %l0
a00d76ec:  b5 34 20 03  srl  %l0, 3, %i2
a00d76f0:  10 bf fc 17  b  0xa00d674c
a00d76f4:  94 0e a0 03  and  %i2, 3, %o2
a00d76f8:  40 01 c3 21  call  0xa014837c
a00d76fc:  90 10 20 01  mov  1, %o0
a00d7700:  91 2a 20 10  sll  %o0, 0x10, %o0
a00d7704:  a3 32 20 12  srl  %o0, 0x12, %l1
a00d7708:  40 01 c3 1d  call  0xa014837c
a00d770c:  90 10 20 01  mov  1, %o0
a00d7710:  bb 2a 20 10  sll  %o0, 0x10, %i5
a00d7714:  10 bf fa 79  b  0xa00d60f8
a00d7718:  91 37 60 12  srl  %i5, 0x12, %o0
a00d771c:  80 a2 e0 04  cmp  %o3, 4
a00d7720:  22 80 00 6b  be,a   0xa00d78cc
a00d7724:  fa 02 a0 30  ld  [ %o2 + 0x30 ], %i5
a00d7728:  10 bf fd 3a  b  0xa00d6c10
a00d772c:  c2 0a a0 34  ldub  [ %o2 + 0x34 ], %g1
a00d7730:  80 a6 20 00  cmp  %i0, 0
a00d7734:  12 bf fd 6d  bne  0xa00d6ce8
a00d7738:  9b 2c 20 10  sll  %l0, 0x10, %o5
a00d773c:  b8 1a e0 01  xor  %o3, 1, %i4
a00d7740:  80 a0 00 1c  cmp  %g0, %i4
a00d7744:  a0 40 20 00  addx  %g0, 0, %l0
a00d7748:  a6 1a e0 04  xor  %o3, 4, %l3
a00d774c:  80 a0 00 13  cmp  %g0, %l3
a00d7750:  b0 40 20 00  addx  %g0, 0, %i0
a00d7754:  80 8c 00 18  btst  %l0, %i0
a00d7758:  22 bf fd 5e  be,a   0xa00d6cd0
a00d775c:  e6 0a a1 a4  ldub  [ %o2 + 0x1a4 ], %l3
a00d7760:  da 02 a0 30  ld  [ %o2 + 0x30 ], %o5
a00d7764:  10 bf fd 2b  b  0xa00d6c10
a00d7768:  83 33 60 0c  srl  %o5, 0xc, %g1
a00d776c:  10 bf fd 2a  b  0xa00d6c14
a00d7770:  83 35 20 1c  srl  %l4, 0x1c, %g1
a00d7774:  40 01 c3 02  call  0xa014837c
a00d7778:  90 10 20 01  mov  1, %o0
a00d777c:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00d7780:  19 2a aa aa  sethi  %hi(0xaaaaa800), %o4
a00d7784:  a0 13 22 ab  or  %o4, 0x2ab, %l0	! 0xaaaaaaab
a00d7788:  97 33 e0 10  srl  %o7, 0x10, %o3
a00d778c:  80 52 c0 10  umul  %o3, %l0, %g0
a00d7790:  9b 40 00 00  rd  %y, %o5
a00d7794:  a3 33 60 01  srl  %o5, 1, %l1
a00d7798:  40 01 c2 f9  call  0xa014837c
a00d779c:  90 10 20 01  mov  1, %o0
a00d77a0:  95 2a 20 10  sll  %o0, 0x10, %o2
a00d77a4:  93 32 a0 10  srl  %o2, 0x10, %o1
a00d77a8:  80 52 40 10  umul  %o1, %l0, %g0
a00d77ac:  83 40 00 00  rd  %y, %g1
a00d77b0:  10 bf fa 52  b  0xa00d60f8
a00d77b4:  91 30 60 01  srl  %g1, 1, %o0
a00d77b8:  af 2c 60 10  sll  %l1, 0x10, %l7
a00d77bc:  83 35 e0 14  srl  %l7, 0x14, %g1
a00d77c0:  10 bf fa 4e  b  0xa00d60f8
a00d77c4:  a3 28 60 03  sll  %g1, 3, %l1
a00d77c8:  02 bf ff fc  be  0xa00d77b8
a00d77cc:  9f 2c 60 10  sll  %l1, 0x10, %o7
a00d77d0:  80 a2 e0 02  cmp  %o3, 2
a00d77d4:  12 bf fa 49  bne  0xa00d60f8
a00d77d8:  a3 33 e0 11  srl  %o7, 0x11, %l1
a00d77dc:  10 bf fa 47  b  0xa00d60f8
a00d77e0:  e2 13 21 f0  lduh  [ %o4 + 0x1f0 ], %l1
a00d77e4:  80 a2 e0 04  cmp  %o3, 4
a00d77e8:  22 80 00 3b  be,a   0xa00d78d4
a00d77ec:  d8 02 a0 30  ld  [ %o2 + 0x30 ], %o4
a00d77f0:  c2 0a a0 34  ldub  [ %o2 + 0x34 ], %g1
a00d77f4:  10 bf ff 8b  b  0xa00d7620
a00d77f8:  82 08 60 0f  and  %g1, 0xf, %g1
a00d77fc:  10 bf fc 44  b  0xa00d690c
a00d7800:  83 36 a0 08  srl  %i2, 8, %g1
a00d7804:  80 a6 20 00  cmp  %i0, 0
a00d7808:  12 bf fe 91  bne  0xa00d724c
a00d780c:  b5 2c 20 10  sll  %l0, 0x10, %i2
a00d7810:  82 1a e0 01  xor  %o3, 1, %g1
a00d7814:  80 a0 00 01  cmp  %g0, %g1
a00d7818:  a4 40 20 00  addx  %g0, 0, %l2
a00d781c:  a6 1a e0 04  xor  %o3, 4, %l3
a00d7820:  80 a0 00 13  cmp  %g0, %l3
a00d7824:  a0 40 20 00  addx  %g0, 0, %l0
a00d7828:  80 8c 80 10  btst  %l2, %l0
a00d782c:  22 bf fe bc  be,a   0xa00d731c
a00d7830:  ec 0a a1 a4  ldub  [ %o2 + 0x1a4 ], %l6
a00d7834:  d6 02 a0 30  ld  [ %o2 + 0x30 ], %o3
a00d7838:  83 32 e0 0c  srl  %o3, 0xc, %g1
a00d783c:  10 bf ff 79  b  0xa00d7620
a00d7840:  82 08 60 0f  and  %g1, 0xf, %g1
a00d7844:  10 bf ff 77  b  0xa00d7620
a00d7848:  83 36 e0 1c  srl  %i3, 0x1c, %g1
a00d784c:  83 36 e0 08  srl  %i3, 8, %g1
a00d7850:  10 bf fd 6e  b  0xa00d6e08
a00d7854:  82 08 60 0f  and  %g1, 0xf, %g1
a00d7858:  83 33 60 14  srl  %o5, 0x14, %g1
a00d785c:  10 bf ff 71  b  0xa00d7620
a00d7860:  82 08 60 0f  and  %g1, 0xf, %g1
a00d7864:  e0 14 a0 54  lduh  [ %l2 + 0x54 ], %l0
a00d7868:  e8 14 a0 56  lduh  [ %l2 + 0x56 ], %l4
a00d786c:  40 01 c2 c4  call  0xa014837c
a00d7870:  90 10 20 00  clr  %o0
a00d7874:  bb 2a 20 10  sll  %o0, 0x10, %i5
a00d7878:  af 37 60 10  srl  %i5, 0x10, %l7
a00d787c:  a2 05 f9 40  add  %l7, -1728, %l1
a00d7880:  80 a4 00 11  cmp  %l0, %l1
a00d7884:  14 80 00 31  bg  0xa00d7948
a00d7888:  aa 10 00 10  mov  %l0, %l5
a00d788c:  9f 2d 20 10  sll  %l4, 0x10, %o7
a00d7890:  a7 33 e0 10  srl  %o7, 0x10, %l3
a00d7894:  40 01 c2 ba  call  0xa014837c
a00d7898:  90 10 20 01  mov  1, %o0
a00d789c:  95 2a 20 10  sll  %o0, 0x10, %o2
a00d78a0:  93 32 a0 10  srl  %o2, 0x10, %o1
a00d78a4:  82 02 7c 34  add  %o1, -972, %g1
a00d78a8:  80 a4 c0 01  cmp  %l3, %g1
a00d78ac:  04 bf fa 29  ble  0xa00d6150
a00d78b0:  e0 17 bf b6  lduh  [ %fp + -74 ], %l0
a00d78b4:  40 01 c2 b2  call  0xa014837c
a00d78b8:  90 10 20 01  mov  1, %o0
a00d78bc:  90 02 3c 34  add  %o0, -972, %o0
a00d78c0:  d0 34 a0 56  sth  %o0, [ %l2 + 0x56 ]
a00d78c4:  10 bf fa 22  b  0xa00d614c
a00d78c8:  a8 10 00 08  mov  %o0, %l4
a00d78cc:  10 bf fc d1  b  0xa00d6c10
a00d78d0:  83 37 60 08  srl  %i5, 8, %g1
a00d78d4:  83 33 20 08  srl  %o4, 8, %g1
a00d78d8:  10 bf ff 52  b  0xa00d7620
a00d78dc:  82 08 60 0f  and  %g1, 0xf, %g1
a00d78e0:  e2 14 a0 54  lduh  [ %l2 + 0x54 ], %l1
a00d78e4:  e8 14 a0 56  lduh  [ %l2 + 0x56 ], %l4
a00d78e8:  40 01 c2 a5  call  0xa014837c
a00d78ec:  90 10 20 00  clr  %o0
a00d78f0:  99 2a 20 10  sll  %o0, 0x10, %o4
a00d78f4:  9b 33 20 10  srl  %o4, 0x10, %o5
a00d78f8:  96 03 7a c0  add  %o5, -1344, %o3
a00d78fc:  80 a4 40 0b  cmp  %l1, %o3
a00d7900:  14 80 00 18  bg  0xa00d7960
a00d7904:  aa 10 00 11  mov  %l1, %l5
a00d7908:  40 01 c2 9d  call  0xa014837c
a00d790c:  90 10 20 01  mov  1, %o0
a00d7910:  83 2a 20 10  sll  %o0, 0x10, %g1
a00d7914:  a7 2d 20 10  sll  %l4, 0x10, %l3
a00d7918:  91 30 60 10  srl  %g1, 0x10, %o0
a00d791c:  bb 34 e0 10  srl  %l3, 0x10, %i5
a00d7920:  ae 02 3d 0c  add  %o0, -756, %l7
a00d7924:  80 a7 40 17  cmp  %i5, %l7
a00d7928:  04 bf fa 0a  ble  0xa00d6150
a00d792c:  e0 17 bf b6  lduh  [ %fp + -74 ], %l0
a00d7930:  40 01 c2 93  call  0xa014837c
a00d7934:  90 10 20 01  mov  1, %o0
a00d7938:  90 02 3d 0c  add  %o0, -756, %o0
a00d793c:  d0 34 a0 56  sth  %o0, [ %l2 + 0x56 ]
a00d7940:  10 bf fa 03  b  0xa00d614c
a00d7944:  a8 10 00 08  mov  %o0, %l4
a00d7948:  40 01 c2 8d  call  0xa014837c
a00d794c:  90 10 20 00  clr  %o0
a00d7950:  90 02 39 40  add  %o0, -1728, %o0
a00d7954:  d0 34 a0 54  sth  %o0, [ %l2 + 0x54 ]
a00d7958:  10 bf ff cd  b  0xa00d788c
a00d795c:  aa 10 00 08  mov  %o0, %l5
a00d7960:  40 01 c2 87  call  0xa014837c
a00d7964:  90 10 20 00  clr  %o0
a00d7968:  a0 02 3a c0  add  %o0, -1344, %l0
a00d796c:  e0 34 a0 54  sth  %l0, [ %l2 + 0x54 ]
a00d7970:  10 bf ff e6  b  0xa00d7908
a00d7974:  aa 10 00 10  mov  %l0, %l5
a00d7978:  f4 17 bf a6  lduh  [ %fp + -90 ], %i2
a00d797c:  fa 17 bf b2  lduh  [ %fp + -78 ], %i5
a00d7980:  ec 17 bf b0  lduh  [ %fp + -80 ], %l6
a00d7984:  e8 17 bf ae  lduh  [ %fp + -82 ], %l4
a00d7988:  f4 36 60 0e  sth  %i2, [ %i1 + 0xe ]
a00d798c:  e0 36 40 00  sth  %l0, [ %i1 ]
a00d7990:  e4 36 60 02  sth  %l2, [ %i1 + 2 ]
a00d7994:  d4 36 60 04  sth  %o2, [ %i1 + 4 ]
a00d7998:  d0 36 60 06  sth  %o0, [ %i1 + 6 ]
a00d799c:  fa 36 60 08  sth  %i5, [ %i1 + 8 ]
a00d79a0:  ec 36 60 0a  sth  %l6, [ %i1 + 0xa ]
a00d79a4:  e8 36 60 0c  sth  %l4, [ %i1 + 0xc ]
a00d79a8:  81 c7 e0 08  ret
a00d79ac:  81 e8 00 00  restore
