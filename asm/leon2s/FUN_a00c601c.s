# leon2s FUN_a00c601c 0xa00c601c-0xa00c6730 (1812 bytes)
a00c601c:  9d e3 bf 98  save  %sp, -104, %sp
a00c6020:  40 3a e8 ed  call  0xa0f803d4
a00c6024:  90 10 20 00  clr  %o0
a00c6028:  80 8a 20 ff  btst  0xff, %o0
a00c602c:  12 80 00 0c  bne  0xa00c605c
a00c6030:  b8 10 20 00  clr  %i4
a00c6034:  40 3a e8 e8  call  0xa0f803d4
a00c6038:  90 10 20 01  mov  1, %o0
a00c603c:  80 8a 20 ff  btst  0xff, %o0
a00c6040:  12 80 00 08  bne  0xa00c6060
a00c6044:  aa 10 20 00  clr  %l5
a00c6048:  40 3a e8 e3  call  0xa0f803d4
a00c604c:  90 10 20 02  mov  2, %o0
a00c6050:  80 8a 20 ff  btst  0xff, %o0
a00c6054:  02 80 01 b5  be  0xa00c6728
a00c6058:  01 00 00 00  nop
a00c605c:  aa 10 20 00  clr  %l5	! 0x0
a00c6060:  40 3a e8 dd  call  0xa0f803d4
a00c6064:  90 10 20 00  clr  %o0
a00c6068:  80 8a 20 ff  btst  0xff, %o0
a00c606c:  02 80 00 1c  be  0xa00c60dc
a00c6070:  01 00 00 00  nop
a00c6074:  40 3b 6e f1  call  0xa0fa1c38
a00c6078:  90 10 20 00  clr  %o0	! 0x0
a00c607c:  7f ff ff cd  call  0xa00c5fb0
a00c6080:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c6084:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c6088:  9a 0d 60 ff  and  %l5, 0xff, %o5
a00c608c:  80 a3 40 08  cmp  %o5, %o0
a00c6090:  12 80 00 0d  bne  0xa00c60c4
a00c6094:  83 2b 60 04  sll  %o5, 4, %g1
a00c6098:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00c609c:  c2 00 63 b0  ld  [ %g1 + 0x3b0 ], %g1	! 0xa8078bb0
a00c60a0:  80 a0 60 00  cmp  %g1, 0
a00c60a4:  16 80 00 08  bge  0xa00c60c4
a00c60a8:  83 2b 60 04  sll  %o5, 4, %g1
a00c60ac:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c60b0:  9a 13 61 c8  or  %o5, 0x1c8, %o5	! 0xa807d5c8
a00c60b4:  82 00 40 0d  add  %g1, %o5, %g1
a00c60b8:  da 08 60 04  ldub  [ %g1 + 4 ], %o5
a00c60bc:  10 80 00 07  b  0xa00c60d8
a00c60c0:  9a 13 60 01  or  %o5, 1, %o5
a00c60c4:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c60c8:  9a 13 61 c8  or  %o5, 0x1c8, %o5	! 0xa807d5c8
a00c60cc:  82 00 40 0d  add  %g1, %o5, %g1
a00c60d0:  da 08 60 04  ldub  [ %g1 + 4 ], %o5
a00c60d4:  9a 0b 7f fe  and  %o5, -2, %o5
a00c60d8:  da 28 60 04  stb  %o5, [ %g1 + 4 ]
a00c60dc:  40 3a e8 be  call  0xa0f803d4
a00c60e0:  90 10 20 01  mov  1, %o0
a00c60e4:  80 8a 20 ff  btst  0xff, %o0
a00c60e8:  02 80 00 1c  be  0xa00c6158
a00c60ec:  01 00 00 00  nop
a00c60f0:  40 3b 6e d2  call  0xa0fa1c38
a00c60f4:  90 10 20 01  mov  1, %o0	! 0x1
a00c60f8:  7f ff ff ae  call  0xa00c5fb0
a00c60fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c6100:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c6104:  9a 0d 60 ff  and  %l5, 0xff, %o5
a00c6108:  80 a3 40 08  cmp  %o5, %o0
a00c610c:  12 80 00 0d  bne  0xa00c6140
a00c6110:  83 2b 60 04  sll  %o5, 4, %g1
a00c6114:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00c6118:  c2 00 63 c8  ld  [ %g1 + 0x3c8 ], %g1	! 0xa8078bc8
a00c611c:  80 a0 60 00  cmp  %g1, 0
a00c6120:  16 80 00 08  bge  0xa00c6140
a00c6124:  83 2b 60 04  sll  %o5, 4, %g1
a00c6128:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c612c:  9a 13 61 c8  or  %o5, 0x1c8, %o5	! 0xa807d5c8
a00c6130:  82 00 40 0d  add  %g1, %o5, %g1
a00c6134:  da 08 60 04  ldub  [ %g1 + 4 ], %o5
a00c6138:  10 80 00 07  b  0xa00c6154
a00c613c:  9a 13 60 02  or  %o5, 2, %o5
a00c6140:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c6144:  9a 13 61 c8  or  %o5, 0x1c8, %o5	! 0xa807d5c8
a00c6148:  82 00 40 0d  add  %g1, %o5, %g1
a00c614c:  da 08 60 04  ldub  [ %g1 + 4 ], %o5
a00c6150:  9a 0b 7f fd  and  %o5, -3, %o5
a00c6154:  da 28 60 04  stb  %o5, [ %g1 + 4 ]
a00c6158:  40 3a e8 9f  call  0xa0f803d4
a00c615c:  90 10 20 02  mov  2, %o0
a00c6160:  80 8a 20 ff  btst  0xff, %o0
a00c6164:  02 80 00 1d  be  0xa00c61d8
a00c6168:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a00c616c:  40 3b 3d e1  call  0xa0f958f0
a00c6170:  90 10 20 00  clr  %o0
a00c6174:  7f ff ff 8f  call  0xa00c5fb0
a00c6178:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c617c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c6180:  9a 0d 60 ff  and  %l5, 0xff, %o5
a00c6184:  80 a3 40 08  cmp  %o5, %o0
a00c6188:  12 80 00 0d  bne  0xa00c61bc
a00c618c:  83 2b 60 04  sll  %o5, 4, %g1
a00c6190:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00c6194:  c2 00 63 e0  ld  [ %g1 + 0x3e0 ], %g1	! 0xa8078be0
a00c6198:  80 a0 60 00  cmp  %g1, 0
a00c619c:  16 80 00 08  bge  0xa00c61bc
a00c61a0:  83 2b 60 04  sll  %o5, 4, %g1
a00c61a4:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c61a8:  9a 13 61 c8  or  %o5, 0x1c8, %o5	! 0xa807d5c8
a00c61ac:  82 00 40 0d  add  %g1, %o5, %g1
a00c61b0:  da 08 60 04  ldub  [ %g1 + 4 ], %o5
a00c61b4:  10 80 00 07  b  0xa00c61d0
a00c61b8:  9a 13 60 04  or  %o5, 4, %o5
a00c61bc:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c61c0:  9a 13 61 c8  or  %o5, 0x1c8, %o5	! 0xa807d5c8
a00c61c4:  82 00 40 0d  add  %g1, %o5, %g1
a00c61c8:  da 08 60 04  ldub  [ %g1 + 4 ], %o5
a00c61cc:  9a 0b 7f fb  and  %o5, -5, %o5
a00c61d0:  da 28 60 04  stb  %o5, [ %g1 + 4 ]
a00c61d4:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a00c61d8:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00c61dc:  a6 15 21 c8  or  %l4, 0x1c8, %l3
a00c61e0:  a5 2c 20 04  sll  %l0, 4, %l2
a00c61e4:  a2 04 80 13  add  %l2, %l3, %l1
a00c61e8:  da 0c 60 04  ldub  [ %l1 + 4 ], %o5
a00c61ec:  80 a3 60 00  cmp  %o5, 0
a00c61f0:  12 80 00 0f  bne  0xa00c622c
a00c61f4:  c2 0c 60 02  ldub  [ %l1 + 2 ], %g1
a00c61f8:  82 08 60 ff  and  %g1, 0xff, %g1
a00c61fc:  80 a3 40 01  cmp  %o5, %g1
a00c6200:  02 80 01 45  be  0xa00c6714
a00c6204:  90 10 00 10  mov  %l0, %o0
a00c6208:  7f ff ff 44  call  0xa00c5f18
a00c620c:  92 10 20 00  clr  %o1
a00c6210:  c2 04 c0 12  ld  [ %l3 + %l2 ], %g1
a00c6214:  1b 00 10 00  sethi  %hi(0x400000), %o5
a00c6218:  9a 28 40 0d  andn  %g1, %o5, %o5
a00c621c:  da 24 c0 12  st  %o5, [ %l3 + %l2 ]
a00c6220:  c2 0c 60 04  ldub  [ %l1 + 4 ], %g1
a00c6224:  10 80 01 3c  b  0xa00c6714
a00c6228:  c2 2c 60 02  stb  %g1, [ %l1 + 2 ]
a00c622c:  82 08 60 ff  and  %g1, 0xff, %g1
a00c6230:  80 a3 40 01  cmp  %o5, %g1
a00c6234:  02 80 00 40  be  0xa00c6334
a00c6238:  82 10 20 01  mov  1, %g1
a00c623c:  80 a4 20 03  cmp  %l0, 3
a00c6240:  08 80 00 07  bleu  0xa00c625c
a00c6244:  99 28 40 10  sll  %g1, %l0, %o4
a00c6248:  82 1c 20 04  xor  %l0, 4, %g1
a00c624c:  80 a0 00 01  cmp  %g0, %g1
a00c6250:  82 60 20 00  subx  %g0, 0, %g1
a00c6254:  82 08 60 10  and  %g1, 0x10, %g1
a00c6258:  98 00 60 10  add  %g1, 0x10, %o4
a00c625c:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00c6260:  c2 0b 60 d2  ldub  [ %o5 + 0xd2 ], %g1	! 0xa80788d2
a00c6264:  82 10 40 0c  or  %g1, %o4, %g1
a00c6268:  c2 2b 60 d2  stb  %g1, [ %o5 + 0xd2 ]
a00c626c:  90 10 00 10  mov  %l0, %o0
a00c6270:  92 10 23 05  mov  0x305, %o1
a00c6274:  80 a4 20 01  cmp  %l0, 1
a00c6278:  08 80 00 1d  bleu  0xa00c62ec
a00c627c:  94 10 20 07  mov  7, %o2
a00c6280:  80 a4 20 03  cmp  %l0, 3
a00c6284:  18 80 00 1d  bgu  0xa00c62f8
a00c6288:  a6 15 21 c8  or  %l4, 0x1c8, %l3
a00c628c:  90 10 00 10  mov  %l0, %o0
a00c6290:  92 10 20 a6  mov  0xa6, %o1
a00c6294:  40 3b c6 cf  call  0xa0fb7dd0
a00c6298:  94 10 20 09  mov  9, %o2
a00c629c:  90 10 00 10  mov  %l0, %o0
a00c62a0:  92 10 20 a4  mov  0xa4, %o1
a00c62a4:  40 3b c6 cb  call  0xa0fb7dd0
a00c62a8:  94 10 20 00  clr  %o2
a00c62ac:  90 10 00 10  mov  %l0, %o0
a00c62b0:  92 10 20 a5  mov  0xa5, %o1
a00c62b4:  40 3b c6 c7  call  0xa0fb7dd0
a00c62b8:  94 10 20 01  mov  1, %o2
a00c62bc:  90 10 00 10  mov  %l0, %o0
a00c62c0:  96 10 20 01  mov  1, %o3
a00c62c4:  92 10 20 a7  mov  0xa7, %o1
a00c62c8:  40 3b c6 d3  call  0xa0fb7e14
a00c62cc:  94 10 20 04  mov  4, %o2
a00c62d0:  90 10 00 10  mov  %l0, %o0
a00c62d4:  92 10 20 a6  mov  0xa6, %o1
a00c62d8:  40 3b c6 be  call  0xa0fb7dd0
a00c62dc:  94 10 20 01  mov  1, %o2
a00c62e0:  90 10 00 10  mov  %l0, %o0
a00c62e4:  92 10 20 a7  mov  0xa7, %o1
a00c62e8:  94 10 20 03  mov  3, %o2
a00c62ec:  40 3b c6 ca  call  0xa0fb7e14
a00c62f0:  96 10 20 01  mov  1, %o3
a00c62f4:  a6 15 21 c8  or  %l4, 0x1c8, %l3
a00c62f8:  a3 2c 20 04  sll  %l0, 4, %l1
a00c62fc:  a4 04 40 13  add  %l1, %l3, %l2
a00c6300:  c2 0c a0 02  ldub  [ %l2 + 2 ], %g1
a00c6304:  80 a0 60 00  cmp  %g1, 0
a00c6308:  32 80 00 06  bne,a   0xa00c6320
a00c630c:  c2 04 c0 11  ld  [ %l3 + %l1 ], %g1
a00c6310:  90 10 00 10  mov  %l0, %o0
a00c6314:  7f ff ff 01  call  0xa00c5f18
a00c6318:  92 10 20 01  mov  1, %o1
a00c631c:  c2 04 c0 11  ld  [ %l3 + %l1 ], %g1
a00c6320:  1b 00 10 00  sethi  %hi(0x400000), %o5
a00c6324:  9a 28 40 0d  andn  %g1, %o5, %o5
a00c6328:  da 24 c0 11  st  %o5, [ %l3 + %l1 ]
a00c632c:  c2 0c a0 04  ldub  [ %l2 + 4 ], %g1
a00c6330:  c2 2c a0 02  stb  %g1, [ %l2 + 2 ]
a00c6334:  98 0d 60 ff  and  %l5, 0xff, %o4
a00c6338:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c633c:  83 2b 20 04  sll  %o4, 4, %g1
a00c6340:  9a 13 61 c8  or  %o5, 0x1c8, %o5
a00c6344:  82 00 40 0d  add  %g1, %o5, %g1
a00c6348:  c2 08 60 04  ldub  [ %g1 + 4 ], %g1
a00c634c:  80 a0 60 00  cmp  %g1, 0
a00c6350:  02 80 00 7c  be  0xa00c6540
a00c6354:  ba 10 20 00  clr  %i5
a00c6358:  82 10 20 01  mov  1, %g1
a00c635c:  a7 28 40 0c  sll  %g1, %o4, %l3
a00c6360:  80 a3 20 03  cmp  %o4, 3
a00c6364:  08 80 00 0d  bleu  0xa00c6398
a00c6368:  b8 10 20 01  mov  1, %i4
a00c636c:  80 a3 20 04  cmp  %o4, 4
a00c6370:  02 80 00 0a  be  0xa00c6398
a00c6374:  a6 10 20 10  mov  0x10, %l3
a00c6378:  10 80 00 08  b  0xa00c6398
a00c637c:  a6 10 20 20  mov  0x20, %l3
a00c6380:  da 02 00 0b  ld  [ %o0 + %o3 ], %o5
a00c6384:  03 00 10 00  sethi  %hi(0x400000), %g1
a00c6388:  82 2b 40 01  andn  %o5, %g1, %g1
a00c638c:  c2 22 00 0b  st  %g1, [ %o0 + %o3 ]
a00c6390:  10 80 00 6c  b  0xa00c6540
a00c6394:  b8 10 20 00  clr  %i4
a00c6398:  a8 10 20 00  clr  %l4
a00c639c:  2d 2a 01 f5  sethi  %hi(0xa807d400), %l6
a00c63a0:  a4 0d 60 ff  and  %l5, 0xff, %l2
a00c63a4:  82 15 a1 c8  or  %l6, 0x1c8, %g1
a00c63a8:  9b 2c a0 04  sll  %l2, 4, %o5
a00c63ac:  9a 03 40 01  add  %o5, %g1, %o5
a00c63b0:  c2 0b 60 04  ldub  [ %o5 + 4 ], %g1
a00c63b4:  a0 0d 20 ff  and  %l4, 0xff, %l0
a00c63b8:  83 38 40 10  sra  %g1, %l0, %g1
a00c63bc:  80 88 60 01  btst  1, %g1
a00c63c0:  02 80 00 22  be  0xa00c6448
a00c63c4:  90 15 a1 c8  or  %l6, 0x1c8, %o0
a00c63c8:  82 04 00 10  add  %l0, %l0, %g1
a00c63cc:  82 00 40 10  add  %g1, %l0, %g1
a00c63d0:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00c63d4:  83 28 60 03  sll  %g1, 3, %g1
a00c63d8:  9a 13 63 b0  or  %o5, 0x3b0, %o5
a00c63dc:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00c63e0:  80 a0 60 00  cmp  %g1, 0
a00c63e4:  16 80 00 1a  bge  0xa00c644c
a00c63e8:  97 2c a0 04  sll  %l2, 4, %o3
a00c63ec:  80 a4 20 01  cmp  %l0, 1
a00c63f0:  22 80 00 0c  be,a   0xa00c6420
a00c63f4:  90 10 20 06  mov  6, %o0
a00c63f8:  14 80 00 07  bg  0xa00c6414
a00c63fc:  80 a4 20 02  cmp  %l0, 2
a00c6400:  80 a4 20 00  cmp  %l0, 0
a00c6404:  22 80 00 07  be,a   0xa00c6420
a00c6408:  90 10 20 05  mov  5, %o0
a00c640c:  10 80 00 11  b  0xa00c6450
a00c6410:  94 02 c0 08  add  %o3, %o0, %o2
a00c6414:  12 80 00 0d  bne  0xa00c6448
a00c6418:  90 15 a1 c8  or  %l6, 0x1c8, %o0
a00c641c:  90 10 20 00  clr  %o0
a00c6420:  40 3b 34 8a  call  0xa0f93648
a00c6424:  01 00 00 00  nop
a00c6428:  80 a2 20 01  cmp  %o0, 1
a00c642c:  12 80 00 07  bne  0xa00c6448
a00c6430:  90 15 a1 c8  or  %l6, 0x1c8, %o0
a00c6434:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00c6438:  c2 0b 60 d2  ldub  [ %o5 + 0xd2 ], %g1	! 0xa80788d2
a00c643c:  82 10 40 13  or  %g1, %l3, %g1
a00c6440:  c2 2b 60 d2  stb  %g1, [ %o5 + 0xd2 ]
a00c6444:  ba 10 20 01  mov  1, %i5
a00c6448:  97 2c a0 04  sll  %l2, 4, %o3
a00c644c:  94 02 c0 08  add  %o3, %o0, %o2
a00c6450:  c2 0a a0 04  ldub  [ %o2 + 4 ], %g1
a00c6454:  83 38 40 10  sra  %g1, %l0, %g1
a00c6458:  80 88 60 01  btst  1, %g1
a00c645c:  22 80 00 35  be,a   0xa00c6530
a00c6460:  a8 05 20 01  inc  %l4
a00c6464:  82 04 00 10  add  %l0, %l0, %g1
a00c6468:  82 00 40 10  add  %g1, %l0, %g1
a00c646c:  2f 2a 01 e2  sethi  %hi(0xa8078800), %l7
a00c6470:  93 28 60 03  sll  %g1, 3, %o1
a00c6474:  9e 15 e3 b0  or  %l7, 0x3b0, %o7
a00c6478:  d8 03 c0 09  ld  [ %o7 + %o1 ], %o4
a00c647c:  80 a3 20 00  cmp  %o4, 0
a00c6480:  36 80 00 2c  bge,a   0xa00c6530
a00c6484:  a8 05 20 01  inc  %l4
a00c6488:  83 33 20 17  srl  %o4, 0x17, %g1
a00c648c:  a2 08 60 01  and  %g1, 1, %l1
a00c6490:  80 a4 60 01  cmp  %l1, 1
a00c6494:  12 bf ff bb  bne  0xa00c6380
a00c6498:  1b 00 10 00  sethi  %hi(0x400000), %o5
a00c649c:  c2 02 00 0b  ld  [ %o0 + %o3 ], %g1
a00c64a0:  83 30 60 17  srl  %g1, 0x17, %g1
a00c64a4:  82 08 60 01  and  %g1, 1, %g1
a00c64a8:  98 2b 00 0d  andn  %o4, %o5, %o4
a00c64ac:  9b 28 60 16  sll  %g1, 0x16, %o5
a00c64b0:  98 13 00 0d  or  %o4, %o5, %o4
a00c64b4:  80 a0 60 00  cmp  %g1, 0
a00c64b8:  02 80 00 1d  be  0xa00c652c
a00c64bc:  d8 23 c0 09  st  %o4, [ %o7 + %o1 ]
a00c64c0:  03 00 10 00  sethi  %hi(0x400000), %g1
a00c64c4:  82 13 00 01  or  %o4, %g1, %g1
a00c64c8:  80 a4 20 02  cmp  %l0, 2
a00c64cc:  12 80 00 09  bne  0xa00c64f0
a00c64d0:  c2 23 c0 09  st  %g1, [ %o7 + %o1 ]
a00c64d4:  80 a4 a0 03  cmp  %l2, 3
a00c64d8:  08 80 00 05  bleu  0xa00c64ec
a00c64dc:  9a 03 e0 30  add  %o7, 0x30, %o5
a00c64e0:  c2 0a a0 03  ldub  [ %o2 + 3 ], %g1
a00c64e4:  10 80 00 03  b  0xa00c64f0
a00c64e8:  c2 2b 60 14  stb  %g1, [ %o5 + 0x14 ]
a00c64ec:  e2 2b 60 14  stb  %l1, [ %o5 + 0x14 ]
a00c64f0:  83 2c a0 04  sll  %l2, 4, %g1
a00c64f4:  9a 15 a1 c8  or  %l6, 0x1c8, %o5
a00c64f8:  98 04 00 10  add  %l0, %l0, %o4
a00c64fc:  da 03 40 01  ld  [ %o5 + %g1 ], %o5
a00c6500:  98 03 00 10  add  %o4, %l0, %o4
a00c6504:  94 15 e3 b0  or  %l7, 0x3b0, %o2
a00c6508:  99 2b 20 03  sll  %o4, 3, %o4
a00c650c:  9b 33 60 15  srl  %o5, 0x15, %o5
a00c6510:  d6 02 80 0c  ld  [ %o2 + %o4 ], %o3
a00c6514:  9a 0b 60 01  and  %o5, 1, %o5
a00c6518:  03 00 04 00  sethi  %hi(0x100000), %g1
a00c651c:  82 2a c0 01  andn  %o3, %g1, %g1
a00c6520:  9b 2b 60 14  sll  %o5, 0x14, %o5
a00c6524:  82 10 40 0d  or  %g1, %o5, %g1
a00c6528:  c2 22 80 0c  st  %g1, [ %o2 + %o4 ]
a00c652c:  a8 05 20 01  inc  %l4
a00c6530:  82 0d 20 ff  and  %l4, 0xff, %g1
a00c6534:  80 a0 60 02  cmp  %g1, 2
a00c6538:  08 bf ff 9a  bleu  0xa00c63a0
a00c653c:  2d 2a 01 f5  sethi  %hi(0xa807d400), %l6
a00c6540:  a2 0d 60 ff  and  %l5, 0xff, %l1
a00c6544:  80 a4 60 05  cmp  %l1, 5
a00c6548:  18 80 00 78  bgu  0xa00c6728
a00c654c:  80 8f 20 ff  btst  0xff, %i4
a00c6550:  02 80 00 21  be  0xa00c65d4
a00c6554:  21 2a 01 f5  sethi  %hi(0xa807d400), %l0
a00c6558:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c655c:  a4 10 61 c8  or  %g1, 0x1c8, %l2	! 0xa807d5c8
a00c6560:  a1 2c 60 04  sll  %l1, 4, %l0
a00c6564:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00c6568:  83 30 60 16  srl  %g1, 0x16, %g1
a00c656c:  80 88 60 01  btst  1, %g1
a00c6570:  32 80 00 19  bne,a   0xa00c65d4
a00c6574:  21 2a 01 f5  sethi  %hi(0xa807d400), %l0
a00c6578:  80 a4 60 03  cmp  %l1, 3
a00c657c:  18 80 00 0f  bgu  0xa00c65b8
a00c6580:  01 00 00 00  nop
a00c6584:  7f ff fa 32  call  0xa00c4e4c
a00c6588:  90 10 00 11  mov  %l1, %o0
a00c658c:  80 8a 20 ff  btst  0xff, %o0
a00c6590:  12 80 00 06  bne  0xa00c65a8
a00c6594:  01 00 00 00  nop
a00c6598:  7f ff fa 36  call  0xa00c4e70
a00c659c:  90 10 00 11  mov  %l1, %o0
a00c65a0:  10 80 00 09  b  0xa00c65c4
a00c65a4:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00c65a8:  7f ff fd a2  call  0xa00c5c30
a00c65ac:  90 10 00 11  mov  %l1, %o0
a00c65b0:  10 80 00 09  b  0xa00c65d4
a00c65b4:  21 2a 01 f5  sethi  %hi(0xa807d400), %l0
a00c65b8:  7f ff fc 04  call  0xa00c55c8
a00c65bc:  90 10 00 11  mov  %l1, %o0
a00c65c0:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00c65c4:  1b 00 10 00  sethi  %hi(0x400000), %o5
a00c65c8:  82 10 40 0d  or  %g1, %o5, %g1
a00c65cc:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a00c65d0:  21 2a 01 f5  sethi  %hi(0xa807d400), %l0
a00c65d4:  9a 14 21 c8  or  %l0, 0x1c8, %o5	! 0xa807d5c8
a00c65d8:  83 2c 60 04  sll  %l1, 4, %g1
a00c65dc:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00c65e0:  83 30 60 16  srl  %g1, 0x16, %g1
a00c65e4:  80 88 60 01  btst  1, %g1
a00c65e8:  02 80 00 0b  be  0xa00c6614
a00c65ec:  80 a4 60 03  cmp  %l1, 3
a00c65f0:  18 80 00 06  bgu  0xa00c6608
a00c65f4:  01 00 00 00  nop
a00c65f8:  7f ff fc fa  call  0xa00c59e0
a00c65fc:  90 10 00 11  mov  %l1, %o0
a00c6600:  10 80 00 05  b  0xa00c6614
a00c6604:  80 a4 60 03  cmp  %l1, 3
a00c6608:  7f ff fd 37  call  0xa00c5ae4
a00c660c:  90 10 00 11  mov  %l1, %o0
a00c6610:  80 a4 60 03  cmp  %l1, 3
a00c6614:  18 80 00 05  bgu  0xa00c6628
a00c6618:  80 8f 60 ff  btst  0xff, %i5
a00c661c:  7f ff fd 85  call  0xa00c5c30
a00c6620:  90 10 00 11  mov  %l1, %o0
a00c6624:  80 8f 60 ff  btst  0xff, %i5
a00c6628:  22 80 00 3c  be,a   0xa00c6718
a00c662c:  aa 05 60 01  inc  %l5
a00c6630:  96 14 21 c8  or  %l0, 0x1c8, %o3
a00c6634:  99 2c 60 04  sll  %l1, 4, %o4
a00c6638:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00c663c:  03 00 10 00  sethi  %hi(0x400000), %g1
a00c6640:  82 2b 40 01  andn  %o5, %g1, %g1
a00c6644:  80 a4 60 03  cmp  %l1, 3
a00c6648:  18 80 00 1f  bgu  0xa00c66c4
a00c664c:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00c6650:  90 10 00 11  mov  %l1, %o0
a00c6654:  40 3b c6 11  call  0xa0fb7e98
a00c6658:  92 10 20 30  mov  0x30, %o1
a00c665c:  80 8a 20 10  btst  0x10, %o0
a00c6660:  02 80 00 10  be  0xa00c66a0
a00c6664:  90 10 00 11  mov  %l1, %o0
a00c6668:  92 10 20 05  mov  5, %o1
a00c666c:  40 3b c6 0b  call  0xa0fb7e98
a00c6670:  90 10 00 11  mov  %l1, %o0
a00c6674:  a0 10 00 08  mov  %o0, %l0
a00c6678:  94 14 20 09  or  %l0, 9, %o2
a00c667c:  94 0a a0 ff  and  %o2, 0xff, %o2
a00c6680:  90 10 00 11  mov  %l1, %o0
a00c6684:  40 3b c5 d3  call  0xa0fb7dd0
a00c6688:  92 10 20 05  mov  5, %o1
a00c668c:  90 10 00 11  mov  %l1, %o0
a00c6690:  94 0c 20 ff  and  %l0, 0xff, %o2
a00c6694:  40 3b c5 cf  call  0xa0fb7dd0
a00c6698:  92 10 20 05  mov  5, %o1
a00c669c:  90 10 00 11  mov  %l1, %o0
a00c66a0:  92 10 20 2f  mov  0x2f, %o1
a00c66a4:  40 3b c5 cb  call  0xa0fb7dd0
a00c66a8:  94 10 20 00  clr  %o2
a00c66ac:  90 10 00 11  mov  %l1, %o0
a00c66b0:  92 10 20 30  mov  0x30, %o1
a00c66b4:  40 3b c5 c7  call  0xa0fb7dd0
a00c66b8:  94 10 20 00  clr  %o2
a00c66bc:  10 80 00 17  b  0xa00c6718
a00c66c0:  aa 05 60 01  inc  %l5
a00c66c4:  a0 05 7f fc  add  %l5, -4, %l0
a00c66c8:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00c66cc:  96 10 20 01  mov  1, %o3
a00c66d0:  90 10 00 10  mov  %l0, %o0
a00c66d4:  92 10 20 30  mov  0x30, %o1
a00c66d8:  40 3b c1 70  call  0xa0fb6c98
a00c66dc:  94 10 20 80  mov  0x80, %o2
a00c66e0:  90 10 00 10  mov  %l0, %o0
a00c66e4:  92 10 22 aa  mov  0x2aa, %o1
a00c66e8:  40 3b c1 46  call  0xa0fb6c00
a00c66ec:  94 10 20 00  clr  %o2
a00c66f0:  90 10 00 10  mov  %l0, %o0
a00c66f4:  92 10 22 ab  mov  0x2ab, %o1
a00c66f8:  40 3b c1 42  call  0xa0fb6c00
a00c66fc:  94 10 20 00  clr  %o2
a00c6700:  90 10 00 10  mov  %l0, %o0
a00c6704:  92 10 20 30  mov  0x30, %o1
a00c6708:  94 10 20 80  mov  0x80, %o2
a00c670c:  40 3b c1 63  call  0xa0fb6c98
a00c6710:  96 10 20 00  clr  %o3
a00c6714:  aa 05 60 01  inc  %l5
a00c6718:  82 0d 60 ff  and  %l5, 0xff, %g1
a00c671c:  80 a0 60 05  cmp  %g1, 5
a00c6720:  08 bf fe 50  bleu  0xa00c6060
a00c6724:  01 00 00 00  nop
a00c6728:  81 c7 e0 08  ret
a00c672c:  81 e8 00 00  restore
