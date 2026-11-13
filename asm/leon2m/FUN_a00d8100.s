# leon2m FUN_a00d8100 0xa00d8100-0xa00d8b30 (92 bytes)
a00d8100:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00d8104:  9a 12 e2 90  or  %o3, 0x290, %o5	! 0xa802d290
a00d8108:  c2 03 60 a8  ld  [ %o5 + 0xa8 ], %g1
a00d810c:  80 88 68 00  btst  0x800, %g1
a00d8110:  32 80 00 34  bne,a   0xa00d81e0
a00d8114:  c2 0b 61 81  ldub  [ %o5 + 0x181 ], %g1
a00d8118:  d4 0b 61 82  ldub  [ %o5 + 0x182 ], %o2
a00d811c:  82 0a 20 ff  and  %o0, 0xff, %g1
a00d8120:  80 a0 60 08  cmp  %g1, 8
a00d8124:  18 80 02 81  bgu  0xa00d8b28
a00d8128:  19 00 01 ce  sethi  %hi(0x73800), %o4
a00d812c:  91 28 60 02  sll  %g1, 2, %o0
a00d8130:  9a 13 22 d8  or  %o4, 0x2d8, %o5
a00d8134:  d8 03 40 08  ld  [ %o5 + %o0 ], %o4
a00d8138:  81 c3 00 00  jmp  %o4
a00d813c:  01 00 00 00  nop
a00d8140:  82 0a a0 ff  and  %o2, 0xff, %g1
a00d8144:  80 a0 60 00  cmp  %g1, 0
a00d8148:  02 80 00 b7  be  0xa00d8424
a00d814c:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a00d8150:  80 a0 60 01  cmp  %g1, 1
a00d8154:  02 80 01 01  be  0xa00d8558
a00d8158:  80 a0 60 02  cmp  %g1, 2
a00d815c:  02 80 01 18  be  0xa00d85bc
a00d8160:  80 a0 60 03  cmp  %g1, 3
a00d8164:  02 80 01 33  be  0xa00d8630
a00d8168:  80 a0 60 04  cmp  %g1, 4
a00d816c:  02 80 01 64  be  0xa00d86fc
a00d8170:  80 a0 60 05  cmp  %g1, 5
a00d8174:  02 80 01 80  be  0xa00d8774
a00d8178:  80 a0 60 06  cmp  %g1, 6
a00d817c:  02 80 01 99  be  0xa00d87e0
a00d8180:  80 a0 60 07  cmp  %g1, 7
a00d8184:  02 80 01 b5  be  0xa00d8858
a00d8188:  80 a0 60 08  cmp  %g1, 8
a00d818c:  02 80 01 de  be  0xa00d8904
a00d8190:  80 a0 60 09  cmp  %g1, 9
a00d8194:  02 80 01 ea  be  0xa00d893c
a00d8198:  80 a0 60 0a  cmp  %g1, 0xa
a00d819c:  02 80 02 1f  be  0xa00d8a18
a00d81a0:  80 a0 60 0b  cmp  %g1, 0xb
a00d81a4:  02 80 02 33  be  0xa00d8a70
a00d81a8:  80 a0 60 0c  cmp  %g1, 0xc
a00d81ac:  12 80 02 5f  bne  0xa00d8b28
a00d81b0:  d4 13 63 fe  lduh  [ %o5 + 0x3fe ], %o2
a00d81b4:  80 8a a0 80  btst  0x80, %o2
a00d81b8:  02 80 02 4a  be  0xa00d8ae0
a00d81bc:  96 12 e2 90  or  %o3, 0x290, %o3
a00d81c0:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d81c4:  9b 33 20 0b  srl  %o4, 0xb, %o5
a00d81c8:  15 20 00 00  sethi  %hi(0x80000000), %o2
a00d81cc:  90 2b 00 0a  andn  %o4, %o2, %o0
a00d81d0:  99 2b 60 1f  sll  %o5, 0x1f, %o4
a00d81d4:  82 12 00 0c  or  %o0, %o4, %g1
a00d81d8:  10 80 02 54  b  0xa00d8b28
a00d81dc:  c2 22 e1 1c  st  %g1, [ %o3 + 0x11c ]
a00d81e0:  80 a0 60 00  cmp  %g1, 0
a00d81e4:  02 bf ff ce  be  0xa00d811c
a00d81e8:  94 10 20 01  mov  1, %o2
a00d81ec:  10 bf ff cc  b  0xa00d811c
a00d81f0:  94 00 60 05  add  %g1, 5, %o2
a00d81f4:  82 0a a0 ff  and  %o2, 0xff, %g1
a00d81f8:  80 a0 60 00  cmp  %g1, 0
a00d81fc:  22 80 00 a5  be,a   0xa00d8490
a00d8200:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d8204:  80 a0 60 01  cmp  %g1, 1
a00d8208:  02 80 00 dc  be  0xa00d8578
a00d820c:  80 a0 60 02  cmp  %g1, 2
a00d8210:  02 80 00 f3  be  0xa00d85dc
a00d8214:  80 a0 60 03  cmp  %g1, 3
a00d8218:  02 80 01 0e  be  0xa00d8650
a00d821c:  80 a0 60 04  cmp  %g1, 4
a00d8220:  02 80 01 2c  be  0xa00d86d0
a00d8224:  80 a0 60 05  cmp  %g1, 5
a00d8228:  02 80 01 40  be  0xa00d8728
a00d822c:  80 a0 60 06  cmp  %g1, 6
a00d8230:  02 80 01 64  be  0xa00d87c0
a00d8234:  80 a0 60 07  cmp  %g1, 7
a00d8238:  02 80 01 7d  be  0xa00d882c
a00d823c:  80 a0 60 08  cmp  %g1, 8
a00d8240:  02 80 01 a3  be  0xa00d88cc
a00d8244:  80 a0 60 09  cmp  %g1, 9
a00d8248:  02 80 01 cd  be  0xa00d897c
a00d824c:  80 a0 60 0a  cmp  %g1, 0xa
a00d8250:  02 80 01 df  be  0xa00d89cc
a00d8254:  80 a0 60 0b  cmp  %g1, 0xb
a00d8258:  02 80 02 0e  be  0xa00d8a90
a00d825c:  80 a0 60 0c  cmp  %g1, 0xc
a00d8260:  12 80 02 32  bne  0xa00d8b28
a00d8264:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a00d8268:  d8 13 63 fe  lduh  [ %o5 + 0x3fe ], %o4	! 0xa802cffe
a00d826c:  80 8b 20 80  btst  0x80, %o4
a00d8270:  02 80 02 22  be  0xa00d8af8
a00d8274:  98 12 e2 90  or  %o3, 0x290, %o4
a00d8278:  da 13 21 20  lduh  [ %o4 + 0x120 ], %o5
a00d827c:  9a 0b 60 01  and  %o5, 1, %o5
a00d8280:  c2 03 21 1c  ld  [ %o4 + 0x11c ], %g1
a00d8284:  10 80 00 8c  b  0xa00d84b4
a00d8288:  9b 2b 60 04  sll  %o5, 4, %o5
a00d828c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d8290:  d0 10 63 fe  lduh  [ %g1 + 0x3fe ], %o0	! 0xa802cffe
a00d8294:  80 8a 20 80  btst  0x80, %o0
a00d8298:  02 80 00 79  be  0xa00d847c
a00d829c:  82 12 e2 90  or  %o3, 0x290, %g1
a00d82a0:  96 0a a0 ff  and  %o2, 0xff, %o3
a00d82a4:  94 02 c0 01  add  %o3, %g1, %o2
a00d82a8:  d8 0a a0 65  ldub  [ %o2 + 0x65 ], %o4
a00d82ac:  10 80 02 1f  b  0xa00d8b28
a00d82b0:  d8 28 60 09  stb  %o4, [ %g1 + 9 ]
a00d82b4:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d82b8:  d0 10 63 fe  lduh  [ %g1 + 0x3fe ], %o0	! 0xa802cffe
a00d82bc:  80 8a 20 80  btst  0x80, %o0
a00d82c0:  02 80 00 6a  be  0xa00d8468
a00d82c4:  82 12 e2 90  or  %o3, 0x290, %g1
a00d82c8:  96 0a a0 ff  and  %o2, 0xff, %o3
a00d82cc:  94 02 c0 01  add  %o3, %g1, %o2
a00d82d0:  d8 0a a0 7f  ldub  [ %o2 + 0x7f ], %o4
a00d82d4:  10 80 02 15  b  0xa00d8b28
a00d82d8:  d8 28 60 0a  stb  %o4, [ %g1 + 0xa ]
a00d82dc:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d82e0:  d0 10 63 fe  lduh  [ %g1 + 0x3fe ], %o0	! 0xa802cffe
a00d82e4:  80 8a 20 80  btst  0x80, %o0
a00d82e8:  02 80 00 5b  be  0xa00d8454
a00d82ec:  82 12 e2 90  or  %o3, 0x290, %g1
a00d82f0:  96 0a a0 ff  and  %o2, 0xff, %o3
a00d82f4:  94 02 c0 01  add  %o3, %g1, %o2
a00d82f8:  d8 0a a0 9d  ldub  [ %o2 + 0x9d ], %o4
a00d82fc:  10 80 02 0b  b  0xa00d8b28
a00d8300:  d8 28 60 19  stb  %o4, [ %g1 + 0x19 ]
a00d8304:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d8308:  d0 10 63 fe  lduh  [ %g1 + 0x3fe ], %o0	! 0xa802cffe
a00d830c:  80 8a 20 80  btst  0x80, %o0
a00d8310:  02 80 00 74  be  0xa00d84e0
a00d8314:  82 12 e2 90  or  %o3, 0x290, %g1
a00d8318:  96 0a a0 ff  and  %o2, 0xff, %o3
a00d831c:  94 02 c0 01  add  %o3, %g1, %o2
a00d8320:  d8 0a a1 69  ldub  [ %o2 + 0x169 ], %o4
a00d8324:  10 80 02 01  b  0xa00d8b28
a00d8328:  d8 28 61 5b  stb  %o4, [ %g1 + 0x15b ]
a00d832c:  82 0a a0 ff  and  %o2, 0xff, %g1
a00d8330:  80 a0 60 00  cmp  %g1, 0
a00d8334:  02 80 00 64  be  0xa00d84c4
a00d8338:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a00d833c:  80 a0 60 01  cmp  %g1, 1
a00d8340:  02 80 00 7e  be  0xa00d8538
a00d8344:  80 a0 60 02  cmp  %g1, 2
a00d8348:  02 80 00 95  be  0xa00d859c
a00d834c:  80 a0 60 03  cmp  %g1, 3
a00d8350:  02 80 00 b0  be  0xa00d8610
a00d8354:  80 a0 60 04  cmp  %g1, 4
a00d8358:  02 80 00 d3  be  0xa00d86a4
a00d835c:  80 a0 60 05  cmp  %g1, 5
a00d8360:  02 80 00 fd  be  0xa00d8754
a00d8364:  80 a0 60 06  cmp  %g1, 6
a00d8368:  02 80 01 0e  be  0xa00d87a0
a00d836c:  80 a0 60 07  cmp  %g1, 7
a00d8370:  02 80 01 45  be  0xa00d8884
a00d8374:  80 a0 60 08  cmp  %g1, 8
a00d8378:  02 80 01 4d  be  0xa00d88ac
a00d837c:  80 a0 60 09  cmp  %g1, 9
a00d8380:  02 80 01 77  be  0xa00d895c
a00d8384:  80 a0 60 0a  cmp  %g1, 0xa
a00d8388:  02 80 01 9c  be  0xa00d89f8
a00d838c:  80 a0 60 0b  cmp  %g1, 0xb
a00d8390:  02 80 01 ad  be  0xa00d8a44
a00d8394:  80 a0 60 0c  cmp  %g1, 0xc
a00d8398:  12 80 01 e4  bne  0xa00d8b28
a00d839c:  d4 13 23 fe  lduh  [ %o4 + 0x3fe ], %o2
a00d83a0:  80 8a a0 80  btst  0x80, %o2
a00d83a4:  02 80 01 d2  be  0xa00d8aec
a00d83a8:  9a 12 e2 90  or  %o3, 0x290, %o5
a00d83ac:  c2 03 61 00  ld  [ %o5 + 0x100 ], %g1
a00d83b0:  10 80 01 de  b  0xa00d8b28
a00d83b4:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d83b8:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d83bc:  d0 10 63 fe  lduh  [ %g1 + 0x3fe ], %o0	! 0xa802cffe
a00d83c0:  80 8a 20 80  btst  0x80, %o0
a00d83c4:  12 80 00 4c  bne  0xa00d84f4
a00d83c8:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00d83cc:  96 12 e2 90  or  %o3, 0x290, %o3
a00d83d0:  90 0a a0 ff  and  %o2, 0xff, %o0
a00d83d4:  98 02 00 0b  add  %o0, %o3, %o4
a00d83d8:  da 0b 21 bb  ldub  [ %o4 + 0x1bb ], %o5
a00d83dc:  d8 02 e0 34  ld  [ %o3 + 0x34 ], %o4
a00d83e0:  03 00 03 c0  sethi  %hi(0xf0000), %g1
a00d83e4:  90 0b 60 0f  and  %o5, 0xf, %o0
a00d83e8:  94 2b 00 01  andn  %o4, %g1, %o2
a00d83ec:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00d83f0:  82 12 80 0d  or  %o2, %o5, %g1
a00d83f4:  10 80 01 cd  b  0xa00d8b28
a00d83f8:  c2 22 e0 34  st  %g1, [ %o3 + 0x34 ]
a00d83fc:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d8400:  d0 10 63 fe  lduh  [ %g1 + 0x3fe ], %o0	! 0xa802cffe
a00d8404:  80 8a 20 80  btst  0x80, %o0
a00d8408:  02 80 00 0e  be  0xa00d8440
a00d840c:  82 12 e2 90  or  %o3, 0x290, %g1
a00d8410:  96 0a a0 ff  and  %o2, 0xff, %o3
a00d8414:  94 02 c0 01  add  %o3, %g1, %o2
a00d8418:  d8 0a a1 30  ldub  [ %o2 + 0x130 ], %o4
a00d841c:  10 80 01 c3  b  0xa00d8b28
a00d8420:  d8 28 60 49  stb  %o4, [ %g1 + 0x49 ]
a00d8424:  d4 13 63 fe  lduh  [ %o5 + 0x3fe ], %o2
a00d8428:  80 8a a0 80  btst  0x80, %o2
a00d842c:  02 80 00 3d  be  0xa00d8520
a00d8430:  96 12 e2 90  or  %o3, 0x290, %o3
a00d8434:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8438:  10 bf ff 64  b  0xa00d81c8
a00d843c:  9b 33 20 11  srl  %o4, 0x11, %o5
a00d8440:  98 0a a0 ff  and  %o2, 0xff, %o4
a00d8444:  9a 03 00 01  add  %o4, %g1, %o5
a00d8448:  d8 0b 61 23  ldub  [ %o5 + 0x123 ], %o4
a00d844c:  10 80 01 b7  b  0xa00d8b28
a00d8450:  d8 28 60 49  stb  %o4, [ %g1 + 0x49 ]
a00d8454:  98 0a a0 ff  and  %o2, 0xff, %o4
a00d8458:  9a 03 00 01  add  %o4, %g1, %o5
a00d845c:  d8 0b 60 90  ldub  [ %o5 + 0x90 ], %o4
a00d8460:  10 80 01 b2  b  0xa00d8b28
a00d8464:  d8 28 60 19  stb  %o4, [ %g1 + 0x19 ]
a00d8468:  98 0a a0 ff  and  %o2, 0xff, %o4
a00d846c:  9a 03 00 01  add  %o4, %g1, %o5
a00d8470:  d8 0b 60 72  ldub  [ %o5 + 0x72 ], %o4
a00d8474:  10 80 01 ad  b  0xa00d8b28
a00d8478:  d8 28 60 0a  stb  %o4, [ %g1 + 0xa ]
a00d847c:  98 0a a0 ff  and  %o2, 0xff, %o4
a00d8480:  9a 03 00 01  add  %o4, %g1, %o5
a00d8484:  d8 0b 60 58  ldub  [ %o5 + 0x58 ], %o4
a00d8488:  10 80 01 a8  b  0xa00d8b28
a00d848c:  d8 28 60 09  stb  %o4, [ %g1 + 9 ]
a00d8490:  da 10 63 fe  lduh  [ %g1 + 0x3fe ], %o5
a00d8494:  80 8b 60 80  btst  0x80, %o5
a00d8498:  02 80 00 1b  be  0xa00d8504
a00d849c:  82 12 e2 90  or  %o3, 0x290, %g1
a00d84a0:  98 12 e2 90  or  %o3, 0x290, %o4
a00d84a4:  d6 03 21 20  ld  [ %o4 + 0x120 ], %o3
a00d84a8:  9b 32 e0 12  srl  %o3, 0x12, %o5
a00d84ac:  c2 03 21 1c  ld  [ %o4 + 0x11c ], %g1
a00d84b0:  9a 0b 60 10  and  %o5, 0x10, %o5
a00d84b4:  96 08 7f ef  and  %g1, -17, %o3
a00d84b8:  82 12 c0 0d  or  %o3, %o5, %g1
a00d84bc:  10 80 01 9b  b  0xa00d8b28
a00d84c0:  c2 23 21 1c  st  %g1, [ %o4 + 0x11c ]
a00d84c4:  d4 13 23 fe  lduh  [ %o4 + 0x3fe ], %o2
a00d84c8:  80 8a a0 80  btst  0x80, %o2
a00d84cc:  02 80 00 18  be  0xa00d852c
a00d84d0:  9a 12 e2 90  or  %o3, 0x290, %o5
a00d84d4:  c2 03 60 e8  ld  [ %o5 + 0xe8 ], %g1
a00d84d8:  10 80 01 94  b  0xa00d8b28
a00d84dc:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d84e0:  98 0a a0 ff  and  %o2, 0xff, %o4
a00d84e4:  9a 03 00 01  add  %o4, %g1, %o5
a00d84e8:  d8 0b 61 5c  ldub  [ %o5 + 0x15c ], %o4
a00d84ec:  10 80 01 8f  b  0xa00d8b28
a00d84f0:  d8 28 61 5b  stb  %o4, [ %g1 + 0x15b ]
a00d84f4:  96 12 e2 90  or  %o3, 0x290, %o3
a00d84f8:  94 03 40 0b  add  %o5, %o3, %o2
a00d84fc:  10 bf ff b8  b  0xa00d83dc
a00d8500:  da 0a a1 c8  ldub  [ %o2 + 0x1c8 ], %o5
a00d8504:  da 00 61 1c  ld  [ %g1 + 0x11c ], %o5
a00d8508:  98 03 40 0d  add  %o5, %o5, %o4
a00d850c:  98 0b 20 10  and  %o4, 0x10, %o4
a00d8510:  90 0b 7f ef  and  %o5, -17, %o0
a00d8514:  9a 12 00 0c  or  %o0, %o4, %o5
a00d8518:  10 80 01 84  b  0xa00d8b28
a00d851c:  da 20 61 1c  st  %o5, [ %g1 + 0x11c ]
a00d8520:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8524:  10 bf ff 29  b  0xa00d81c8
a00d8528:  9b 33 20 1e  srl  %o4, 0x1e, %o5
a00d852c:  c2 03 60 b4  ld  [ %o5 + 0xb4 ], %g1
a00d8530:  10 80 01 7e  b  0xa00d8b28
a00d8534:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d8538:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a00d853c:  da 12 23 fe  lduh  [ %o0 + 0x3fe ], %o5	! 0xa802cffe
a00d8540:  80 8b 60 80  btst  0x80, %o5
a00d8544:  02 80 00 4f  be  0xa00d8680
a00d8548:  9a 12 e2 90  or  %o3, 0x290, %o5
a00d854c:  c2 03 60 ec  ld  [ %o5 + 0xec ], %g1
a00d8550:  10 80 01 76  b  0xa00d8b28
a00d8554:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d8558:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d855c:  d0 10 63 fe  lduh  [ %g1 + 0x3fe ], %o0	! 0xa802cffe
a00d8560:  80 8a 20 80  btst  0x80, %o0
a00d8564:  02 80 00 4a  be  0xa00d868c
a00d8568:  96 12 e2 90  or  %o3, 0x290, %o3
a00d856c:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8570:  10 bf ff 16  b  0xa00d81c8
a00d8574:  9b 33 20 10  srl  %o4, 0x10, %o5
a00d8578:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a00d857c:  d0 13 23 fe  lduh  [ %o4 + 0x3fe ], %o0	! 0xa802cffe
a00d8580:  80 8a 20 80  btst  0x80, %o0
a00d8584:  02 80 00 3c  be  0xa00d8674
a00d8588:  82 12 e2 90  or  %o3, 0x290, %g1
a00d858c:  98 12 e2 90  or  %o3, 0x290, %o4
a00d8590:  d4 03 21 20  ld  [ %o4 + 0x120 ], %o2
a00d8594:  10 bf ff c6  b  0xa00d84ac
a00d8598:  9b 32 a0 11  srl  %o2, 0x11, %o5
a00d859c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d85a0:  d4 10 63 fe  lduh  [ %g1 + 0x3fe ], %o2	! 0xa802cffe
a00d85a4:  80 8a a0 80  btst  0x80, %o2
a00d85a8:  02 80 00 52  be  0xa00d86f0
a00d85ac:  9a 12 e2 90  or  %o3, 0x290, %o5
a00d85b0:  c2 03 60 f0  ld  [ %o5 + 0xf0 ], %g1
a00d85b4:  10 80 01 5d  b  0xa00d8b28
a00d85b8:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d85bc:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a00d85c0:  d8 12 a3 fe  lduh  [ %o2 + 0x3fe ], %o4	! 0xa802cffe
a00d85c4:  80 8b 20 80  btst  0x80, %o4
a00d85c8:  02 80 00 34  be  0xa00d8698
a00d85cc:  96 12 e2 90  or  %o3, 0x290, %o3
a00d85d0:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d85d4:  10 bf fe fd  b  0xa00d81c8
a00d85d8:  9b 33 20 0f  srl  %o4, 0xf, %o5
a00d85dc:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d85e0:  da 10 63 fe  lduh  [ %g1 + 0x3fe ], %o5	! 0xa802cffe
a00d85e4:  80 8b 60 80  btst  0x80, %o5
a00d85e8:  02 80 00 37  be  0xa00d86c4
a00d85ec:  82 12 e2 90  or  %o3, 0x290, %g1
a00d85f0:  98 12 e2 90  or  %o3, 0x290, %o4
a00d85f4:  da 03 21 1c  ld  [ %o4 + 0x11c ], %o5
a00d85f8:  c2 13 21 20  lduh  [ %o4 + 0x120 ], %g1
a00d85fc:  82 08 60 10  and  %g1, 0x10, %g1
a00d8600:  96 0b 7f ef  and  %o5, -17, %o3
a00d8604:  90 12 c0 01  or  %o3, %g1, %o0
a00d8608:  10 80 01 48  b  0xa00d8b28
a00d860c:  d0 23 21 1c  st  %o0, [ %o4 + 0x11c ]
a00d8610:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a00d8614:  d8 13 63 fe  lduh  [ %o5 + 0x3fe ], %o4	! 0xa802cffe
a00d8618:  80 8b 20 80  btst  0x80, %o4
a00d861c:  02 80 00 40  be  0xa00d871c
a00d8620:  9a 12 e2 90  or  %o3, 0x290, %o5
a00d8624:  c2 03 60 f4  ld  [ %o5 + 0xf4 ], %g1
a00d8628:  10 80 01 40  b  0xa00d8b28
a00d862c:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d8630:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a00d8634:  da 12 23 fe  lduh  [ %o0 + 0x3fe ], %o5	! 0xa802cffe
a00d8638:  80 8b 60 80  btst  0x80, %o5
a00d863c:  02 80 00 43  be  0xa00d8748
a00d8640:  96 12 e2 90  or  %o3, 0x290, %o3
a00d8644:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8648:  10 bf fe e0  b  0xa00d81c8
a00d864c:  9b 33 20 0e  srl  %o4, 0xe, %o5
a00d8650:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a00d8654:  d0 13 23 fe  lduh  [ %o4 + 0x3fe ], %o0	! 0xa802cffe
a00d8658:  80 8a 20 80  btst  0x80, %o0
a00d865c:  02 80 00 4d  be  0xa00d8790
a00d8660:  82 12 e2 90  or  %o3, 0x290, %g1
a00d8664:  98 12 e2 90  or  %o3, 0x290, %o4
a00d8668:  d6 03 21 20  ld  [ %o4 + 0x120 ], %o3
a00d866c:  10 bf ff 90  b  0xa00d84ac
a00d8670:  9b 32 e0 0f  srl  %o3, 0xf, %o5
a00d8674:  da 00 61 1c  ld  [ %g1 + 0x11c ], %o5
a00d8678:  10 bf ff a5  b  0xa00d850c
a00d867c:  99 2b 60 02  sll  %o5, 2, %o4
a00d8680:  c2 03 60 b8  ld  [ %o5 + 0xb8 ], %g1
a00d8684:  10 80 01 29  b  0xa00d8b28
a00d8688:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d868c:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8690:  10 bf fe ce  b  0xa00d81c8
a00d8694:  9b 33 20 1d  srl  %o4, 0x1d, %o5
a00d8698:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d869c:  10 bf fe cb  b  0xa00d81c8
a00d86a0:  9b 33 20 1c  srl  %o4, 0x1c, %o5
a00d86a4:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a00d86a8:  d0 12 a3 fe  lduh  [ %o2 + 0x3fe ], %o0	! 0xa802cffe
a00d86ac:  80 8a 20 80  btst  0x80, %o0
a00d86b0:  02 80 00 57  be  0xa00d880c
a00d86b4:  9a 12 e2 90  or  %o3, 0x290, %o5
a00d86b8:  c2 03 60 f8  ld  [ %o5 + 0xf8 ], %g1
a00d86bc:  10 80 01 1b  b  0xa00d8b28
a00d86c0:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d86c4:  da 00 61 1c  ld  [ %g1 + 0x11c ], %o5
a00d86c8:  10 bf ff 91  b  0xa00d850c
a00d86cc:  99 2b 60 03  sll  %o5, 3, %o4
a00d86d0:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d86d4:  d8 10 63 fe  lduh  [ %g1 + 0x3fe ], %o4	! 0xa802cffe
a00d86d8:  80 8b 20 80  btst  0x80, %o4
a00d86dc:  02 80 00 4f  be  0xa00d8818
a00d86e0:  98 12 e2 90  or  %o3, 0x290, %o4
a00d86e4:  d6 03 21 20  ld  [ %o4 + 0x120 ], %o3
a00d86e8:  10 bf ff 71  b  0xa00d84ac
a00d86ec:  9b 32 e0 0e  srl  %o3, 0xe, %o5
a00d86f0:  c2 03 60 bc  ld  [ %o5 + 0xbc ], %g1
a00d86f4:  10 80 01 0d  b  0xa00d8b28
a00d86f8:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d86fc:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d8700:  d8 10 63 fe  lduh  [ %g1 + 0x3fe ], %o4	! 0xa802cffe
a00d8704:  80 8b 20 80  btst  0x80, %o4
a00d8708:  02 80 00 3e  be  0xa00d8800
a00d870c:  96 12 e2 90  or  %o3, 0x290, %o3
a00d8710:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8714:  10 bf fe ad  b  0xa00d81c8
a00d8718:  9b 33 20 0d  srl  %o4, 0xd, %o5
a00d871c:  c2 03 60 c0  ld  [ %o5 + 0xc0 ], %g1
a00d8720:  10 80 01 02  b  0xa00d8b28
a00d8724:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d8728:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a00d872c:  da 12 23 fe  lduh  [ %o0 + 0x3fe ], %o5	! 0xa802cffe
a00d8730:  80 8b 60 80  btst  0x80, %o5
a00d8734:  02 80 00 46  be  0xa00d884c
a00d8738:  98 12 e2 90  or  %o3, 0x290, %o4
a00d873c:  c2 03 21 20  ld  [ %o4 + 0x120 ], %g1
a00d8740:  10 bf ff 5b  b  0xa00d84ac
a00d8744:  9b 30 60 0d  srl  %g1, 0xd, %o5
a00d8748:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d874c:  10 bf fe 9f  b  0xa00d81c8
a00d8750:  9b 33 20 1b  srl  %o4, 0x1b, %o5
a00d8754:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d8758:  d8 10 63 fe  lduh  [ %g1 + 0x3fe ], %o4	! 0xa802cffe
a00d875c:  80 8b 20 80  btst  0x80, %o4
a00d8760:  02 80 00 46  be  0xa00d8878
a00d8764:  9a 12 e2 90  or  %o3, 0x290, %o5
a00d8768:  c2 03 60 fc  ld  [ %o5 + 0xfc ], %g1
a00d876c:  10 80 00 ef  b  0xa00d8b28
a00d8770:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d8774:  d4 13 63 fe  lduh  [ %o5 + 0x3fe ], %o2
a00d8778:  80 8a a0 80  btst  0x80, %o2
a00d877c:  02 80 00 49  be  0xa00d88a0
a00d8780:  96 12 e2 90  or  %o3, 0x290, %o3
a00d8784:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8788:  10 bf fe 90  b  0xa00d81c8
a00d878c:  9b 33 20 0c  srl  %o4, 0xc, %o5
a00d8790:  da 00 61 1c  ld  [ %g1 + 0x11c ], %o5
a00d8794:  94 0b 60 01  and  %o5, 1, %o2
a00d8798:  10 bf ff 5e  b  0xa00d8510
a00d879c:  99 2a a0 04  sll  %o2, 4, %o4
a00d87a0:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a00d87a4:  da 12 23 fe  lduh  [ %o0 + 0x3fe ], %o5	! 0xa802cffe
a00d87a8:  80 8b 60 80  btst  0x80, %o5
a00d87ac:  02 80 00 50  be  0xa00d88ec
a00d87b0:  9a 12 e2 90  or  %o3, 0x290, %o5
a00d87b4:  c2 03 61 04  ld  [ %o5 + 0x104 ], %g1
a00d87b8:  10 80 00 dc  b  0xa00d8b28
a00d87bc:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d87c0:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a00d87c4:  d8 12 a3 fe  lduh  [ %o2 + 0x3fe ], %o4	! 0xa802cffe
a00d87c8:  80 8b 20 80  btst  0x80, %o4
a00d87cc:  02 80 00 4b  be  0xa00d88f8
a00d87d0:  98 12 e2 90  or  %o3, 0x290, %o4
a00d87d4:  da 03 21 20  ld  [ %o4 + 0x120 ], %o5
a00d87d8:  10 bf ff 35  b  0xa00d84ac
a00d87dc:  9b 33 60 0b  srl  %o5, 0xb, %o5
a00d87e0:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a00d87e4:  d0 13 23 fe  lduh  [ %o4 + 0x3fe ], %o0	! 0xa802cffe
a00d87e8:  80 8a 20 80  btst  0x80, %o0
a00d87ec:  02 80 00 4e  be  0xa00d8924
a00d87f0:  96 12 e2 90  or  %o3, 0x290, %o3
a00d87f4:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d87f8:  10 bf fe 74  b  0xa00d81c8
a00d87fc:  9b 33 20 0a  srl  %o4, 0xa, %o5
a00d8800:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8804:  10 bf fe 71  b  0xa00d81c8
a00d8808:  9b 33 20 1a  srl  %o4, 0x1a, %o5
a00d880c:  c2 03 60 c4  ld  [ %o5 + 0xc4 ], %g1
a00d8810:  10 80 00 c6  b  0xa00d8b28
a00d8814:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d8818:  d4 03 21 20  ld  [ %o4 + 0x120 ], %o2
a00d881c:  9b 32 a0 1f  srl  %o2, 0x1f, %o5
a00d8820:  c2 03 21 1c  ld  [ %o4 + 0x11c ], %g1
a00d8824:  10 bf ff 24  b  0xa00d84b4
a00d8828:  9b 2b 60 04  sll  %o5, 4, %o5
a00d882c:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a00d8830:  d8 12 a3 fe  lduh  [ %o2 + 0x3fe ], %o4	! 0xa802cffe
a00d8834:  80 8b 20 80  btst  0x80, %o4
a00d8838:  02 80 00 59  be  0xa00d899c
a00d883c:  98 12 e2 90  or  %o3, 0x290, %o4
a00d8840:  da 03 21 20  ld  [ %o4 + 0x120 ], %o5
a00d8844:  10 bf ff 1a  b  0xa00d84ac
a00d8848:  9b 33 60 0a  srl  %o5, 0xa, %o5
a00d884c:  d6 03 21 20  ld  [ %o4 + 0x120 ], %o3
a00d8850:  10 bf ff 17  b  0xa00d84ac
a00d8854:  9b 32 e0 1a  srl  %o3, 0x1a, %o5
a00d8858:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d885c:  d4 10 63 fe  lduh  [ %g1 + 0x3fe ], %o2	! 0xa802cffe
a00d8860:  80 8a a0 80  btst  0x80, %o2
a00d8864:  02 80 00 33  be  0xa00d8930
a00d8868:  96 12 e2 90  or  %o3, 0x290, %o3
a00d886c:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8870:  10 bf fe 56  b  0xa00d81c8
a00d8874:  9b 33 20 09  srl  %o4, 9, %o5
a00d8878:  c2 03 60 c8  ld  [ %o5 + 0xc8 ], %g1
a00d887c:  10 80 00 ab  b  0xa00d8b28
a00d8880:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d8884:  d4 13 23 fe  lduh  [ %o4 + 0x3fe ], %o2
a00d8888:  80 8a a0 80  btst  0x80, %o2
a00d888c:  02 80 00 47  be  0xa00d89a8
a00d8890:  9a 12 e2 90  or  %o3, 0x290, %o5
a00d8894:  c2 03 61 08  ld  [ %o5 + 0x108 ], %g1
a00d8898:  10 80 00 a4  b  0xa00d8b28
a00d889c:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d88a0:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d88a4:  10 bf fe 49  b  0xa00d81c8
a00d88a8:  9b 33 20 19  srl  %o4, 0x19, %o5
a00d88ac:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d88b0:  da 10 63 fe  lduh  [ %g1 + 0x3fe ], %o5	! 0xa802cffe
a00d88b4:  80 8b 60 80  btst  0x80, %o5
a00d88b8:  02 80 00 4d  be  0xa00d89ec
a00d88bc:  9a 12 e2 90  or  %o3, 0x290, %o5
a00d88c0:  c2 03 61 0c  ld  [ %o5 + 0x10c ], %g1
a00d88c4:  10 80 00 99  b  0xa00d8b28
a00d88c8:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d88cc:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d88d0:  d8 10 63 fe  lduh  [ %g1 + 0x3fe ], %o4	! 0xa802cffe
a00d88d4:  80 8b 20 80  btst  0x80, %o4
a00d88d8:  02 80 00 37  be  0xa00d89b4
a00d88dc:  98 12 e2 90  or  %o3, 0x290, %o4
a00d88e0:  d6 03 21 20  ld  [ %o4 + 0x120 ], %o3
a00d88e4:  10 bf fe f2  b  0xa00d84ac
a00d88e8:  9b 32 e0 09  srl  %o3, 9, %o5
a00d88ec:  c2 03 60 cc  ld  [ %o5 + 0xcc ], %g1
a00d88f0:  10 80 00 8e  b  0xa00d8b28
a00d88f4:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d88f8:  da 03 21 1c  ld  [ %o4 + 0x11c ], %o5
a00d88fc:  10 bf ff 40  b  0xa00d85fc
a00d8900:  c2 0b 21 20  ldub  [ %o4 + 0x120 ], %g1
a00d8904:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a00d8908:  da 12 23 fe  lduh  [ %o0 + 0x3fe ], %o5	! 0xa802cffe
a00d890c:  80 8b 60 80  btst  0x80, %o5
a00d8910:  02 80 00 2c  be  0xa00d89c0
a00d8914:  96 12 e2 90  or  %o3, 0x290, %o3
a00d8918:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d891c:  10 bf fe 2b  b  0xa00d81c8
a00d8920:  9b 33 20 08  srl  %o4, 8, %o5
a00d8924:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8928:  10 bf fe 28  b  0xa00d81c8
a00d892c:  9b 33 20 17  srl  %o4, 0x17, %o5
a00d8930:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8934:  10 bf fe 25  b  0xa00d81c8
a00d8938:  9b 33 20 16  srl  %o4, 0x16, %o5
a00d893c:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a00d8940:  d8 12 a3 fe  lduh  [ %o2 + 0x3fe ], %o4	! 0xa802cffe
a00d8944:  80 8b 20 80  btst  0x80, %o4
a00d8948:  02 80 00 3c  be  0xa00d8a38
a00d894c:  96 12 e2 90  or  %o3, 0x290, %o3
a00d8950:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8954:  10 bf fe 1d  b  0xa00d81c8
a00d8958:  9b 33 20 07  srl  %o4, 7, %o5
a00d895c:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a00d8960:  d0 12 a3 fe  lduh  [ %o2 + 0x3fe ], %o0	! 0xa802cffe
a00d8964:  80 8a 20 80  btst  0x80, %o0
a00d8968:  02 80 00 52  be  0xa00d8ab0
a00d896c:  9a 12 e2 90  or  %o3, 0x290, %o5
a00d8970:  c2 03 61 10  ld  [ %o5 + 0x110 ], %g1
a00d8974:  10 80 00 6d  b  0xa00d8b28
a00d8978:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d897c:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a00d8980:  da 12 23 fe  lduh  [ %o0 + 0x3fe ], %o5	! 0xa802cffe
a00d8984:  80 8b 60 80  btst  0x80, %o5
a00d8988:  02 80 00 37  be  0xa00d8a64
a00d898c:  98 12 e2 90  or  %o3, 0x290, %o4
a00d8990:  c2 03 21 20  ld  [ %o4 + 0x120 ], %g1
a00d8994:  10 bf fe c6  b  0xa00d84ac
a00d8998:  9b 30 60 08  srl  %g1, 8, %o5
a00d899c:  d0 03 21 20  ld  [ %o4 + 0x120 ], %o0
a00d89a0:  10 bf fe c3  b  0xa00d84ac
a00d89a4:  9b 32 20 17  srl  %o0, 0x17, %o5
a00d89a8:  c2 03 60 d4  ld  [ %o5 + 0xd4 ], %g1
a00d89ac:  10 80 00 5f  b  0xa00d8b28
a00d89b0:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d89b4:  d4 03 21 20  ld  [ %o4 + 0x120 ], %o2
a00d89b8:  10 bf fe bd  b  0xa00d84ac
a00d89bc:  9b 32 a0 16  srl  %o2, 0x16, %o5
a00d89c0:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d89c4:  10 bf fe 01  b  0xa00d81c8
a00d89c8:  9b 33 20 15  srl  %o4, 0x15, %o5
a00d89cc:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a00d89d0:  d8 12 a3 fe  lduh  [ %o2 + 0x3fe ], %o4	! 0xa802cffe
a00d89d4:  80 8b 20 80  btst  0x80, %o4
a00d89d8:  02 80 00 3c  be  0xa00d8ac8
a00d89dc:  98 12 e2 90  or  %o3, 0x290, %o4
a00d89e0:  da 03 21 20  ld  [ %o4 + 0x120 ], %o5
a00d89e4:  10 bf fe b2  b  0xa00d84ac
a00d89e8:  9b 33 60 07  srl  %o5, 7, %o5
a00d89ec:  c2 03 60 d8  ld  [ %o5 + 0xd8 ], %g1
a00d89f0:  10 80 00 4e  b  0xa00d8b28
a00d89f4:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d89f8:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a00d89fc:  d8 13 63 fe  lduh  [ %o5 + 0x3fe ], %o4	! 0xa802cffe
a00d8a00:  80 8b 20 80  btst  0x80, %o4
a00d8a04:  02 80 00 34  be  0xa00d8ad4
a00d8a08:  9a 12 e2 90  or  %o3, 0x290, %o5
a00d8a0c:  c2 03 61 14  ld  [ %o5 + 0x114 ], %g1
a00d8a10:  10 80 00 46  b  0xa00d8b28
a00d8a14:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d8a18:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d8a1c:  da 10 63 fe  lduh  [ %g1 + 0x3fe ], %o5	! 0xa802cffe
a00d8a20:  80 8b 60 80  btst  0x80, %o5
a00d8a24:  02 80 00 26  be  0xa00d8abc
a00d8a28:  96 12 e2 90  or  %o3, 0x290, %o3
a00d8a2c:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8a30:  10 bf fd e6  b  0xa00d81c8
a00d8a34:  9b 33 20 06  srl  %o4, 6, %o5
a00d8a38:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8a3c:  10 bf fd e3  b  0xa00d81c8
a00d8a40:  9b 33 20 14  srl  %o4, 0x14, %o5
a00d8a44:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d8a48:  d0 10 63 fe  lduh  [ %g1 + 0x3fe ], %o0	! 0xa802cffe
a00d8a4c:  80 8a 20 80  btst  0x80, %o0
a00d8a50:  02 80 00 30  be  0xa00d8b10
a00d8a54:  9a 12 e2 90  or  %o3, 0x290, %o5
a00d8a58:  c2 03 61 18  ld  [ %o5 + 0x118 ], %g1
a00d8a5c:  10 80 00 33  b  0xa00d8b28
a00d8a60:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d8a64:  d6 03 21 20  ld  [ %o4 + 0x120 ], %o3
a00d8a68:  10 bf fe 91  b  0xa00d84ac
a00d8a6c:  9b 32 e0 15  srl  %o3, 0x15, %o5
a00d8a70:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a00d8a74:  d0 13 23 fe  lduh  [ %o4 + 0x3fe ], %o0	! 0xa802cffe
a00d8a78:  80 8a 20 80  btst  0x80, %o0
a00d8a7c:  02 80 00 22  be  0xa00d8b04
a00d8a80:  96 12 e2 90  or  %o3, 0x290, %o3
a00d8a84:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8a88:  10 bf fd d0  b  0xa00d81c8
a00d8a8c:  9b 33 20 05  srl  %o4, 5, %o5
a00d8a90:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00d8a94:  d0 10 63 fe  lduh  [ %g1 + 0x3fe ], %o0	! 0xa802cffe
a00d8a98:  80 8a 20 80  btst  0x80, %o0
a00d8a9c:  02 80 00 20  be  0xa00d8b1c
a00d8aa0:  98 12 e2 90  or  %o3, 0x290, %o4
a00d8aa4:  d6 03 21 20  ld  [ %o4 + 0x120 ], %o3
a00d8aa8:  10 bf fe 81  b  0xa00d84ac
a00d8aac:  9b 32 e0 06  srl  %o3, 6, %o5
a00d8ab0:  c2 03 60 dc  ld  [ %o5 + 0xdc ], %g1
a00d8ab4:  10 80 00 1d  b  0xa00d8b28
a00d8ab8:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d8abc:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8ac0:  10 bf fd c2  b  0xa00d81c8
a00d8ac4:  9b 33 20 13  srl  %o4, 0x13, %o5
a00d8ac8:  da 0b 21 20  ldub  [ %o4 + 0x120 ], %o5
a00d8acc:  10 bf fd ed  b  0xa00d8280
a00d8ad0:  9a 0b 60 01  and  %o5, 1, %o5
a00d8ad4:  c2 03 60 e0  ld  [ %o5 + 0xe0 ], %g1
a00d8ad8:  10 80 00 14  b  0xa00d8b28
a00d8adc:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d8ae0:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8ae4:  10 bf fd b9  b  0xa00d81c8
a00d8ae8:  9b 33 20 18  srl  %o4, 0x18, %o5
a00d8aec:  c2 03 60 d0  ld  [ %o5 + 0xd0 ], %g1
a00d8af0:  10 80 00 0e  b  0xa00d8b28
a00d8af4:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d8af8:  d0 03 21 20  ld  [ %o4 + 0x120 ], %o0
a00d8afc:  10 bf fe 6c  b  0xa00d84ac
a00d8b00:  9b 32 20 19  srl  %o0, 0x19, %o5
a00d8b04:  d8 02 e1 1c  ld  [ %o3 + 0x11c ], %o4
a00d8b08:  10 bf fd b0  b  0xa00d81c8
a00d8b0c:  9b 33 20 12  srl  %o4, 0x12, %o5
a00d8b10:  c2 03 60 e4  ld  [ %o5 + 0xe4 ], %g1
a00d8b14:  10 80 00 05  b  0xa00d8b28
a00d8b18:  c2 23 60 b0  st  %g1, [ %o5 + 0xb0 ]
a00d8b1c:  d4 03 21 20  ld  [ %o4 + 0x120 ], %o2
a00d8b20:  10 bf fe 63  b  0xa00d84ac
a00d8b24:  9b 32 a0 13  srl  %o2, 0x13, %o5
a00d8b28:  81 c3 e0 08  retl
a00d8b2c:  01 00 00 00  nop
