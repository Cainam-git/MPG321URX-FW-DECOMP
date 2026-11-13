# leon2s DRV_HDMI_EQScan_FSM_PHY_PreRVGA 0xa0076180-0xa0076e68 (3304 bytes)
a0076180:  9d e3 be f0  save  %sp, -272, %sp
a0076184:  92 10 20 00  clr  %o1
a0076188:  94 10 20 12  mov  0x12, %o2
a007618c:  40 00 ed 08  call  0xa00b15ac
a0076190:  90 07 bf e0  add  %fp, -32, %o0
a0076194:  92 10 20 00  clr  %o1
a0076198:  94 10 20 12  mov  0x12, %o2
a007619c:  40 00 ed 04  call  0xa00b15ac
a00761a0:  90 07 bf c8  add  %fp, -56, %o0
a00761a4:  90 07 bf 80  add  %fp, -128, %o0
a00761a8:  92 10 20 00  clr  %o1
a00761ac:  40 00 ed 00  call  0xa00b15ac
a00761b0:  94 10 20 48  mov  0x48, %o2
a00761b4:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00761b8:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a00761bc:  80 88 60 02  btst  2, %g1
a00761c0:  a8 10 00 18  mov  %i0, %l4
a00761c4:  ba 10 20 00  clr  %i5
a00761c8:  c0 2f bf 7f  clrb  [ %fp + -129 ]
a00761cc:  c0 2f bf 77  clrb  [ %fp + -137 ]
a00761d0:  c0 2f bf 6f  clrb  [ %fp + -145 ]
a00761d4:  02 80 00 10  be  0xa0076214
a00761d8:  c0 2f bf 67  clrb  [ %fp + -153 ]
a00761dc:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00761e0:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00761e4:  92 06 20 41  add  %i0, 0x41, %o1
a00761e8:  9a 5b 68 98  smul  %o5, 0x898, %o5
a00761ec:  82 10 61 f0  or  %g1, 0x1f0, %g1
a00761f0:  9a 03 40 01  add  %o5, %g1, %o5
a00761f4:  93 2a 60 18  sll  %o1, 0x18, %o1
a00761f8:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a00761fc:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a0076200:  90 12 21 f8  or  %o0, 0x1f8, %o0
a0076204:  93 3a 60 18  sra  %o1, 0x18, %o1
a0076208:  94 12 a0 b0  or  %o2, 0xb0, %o2
a007620c:  7f ff f3 8e  call  0xa0073044
a0076210:  d6 0b 60 30  ldub  [ %o5 + 0x30 ], %o3
a0076214:  23 2a 01 ea  sethi  %hi(0xa807a800), %l1
a0076218:  94 0d 20 ff  and  %l4, 0xff, %o2
a007621c:  82 14 61 f0  or  %l1, 0x1f0, %g1
a0076220:  9a 5a a8 98  smul  %o2, 0x898, %o5
a0076224:  9a 03 40 01  add  %o5, %g1, %o5
a0076228:  a0 0f 60 ff  and  %i5, 0xff, %l0
a007622c:  98 03 40 10  add  %o5, %l0, %o4
a0076230:  c2 0b 20 2d  ldub  [ %o4 + 0x2d ], %g1
a0076234:  80 a0 60 01  cmp  %g1, 1
a0076238:  12 80 00 10  bne  0xa0076278
a007623c:  82 02 80 0a  add  %o2, %o2, %g1
a0076240:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0076244:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0076248:  80 88 60 02  btst  2, %g1
a007624c:  22 80 02 d9  be,a   0xa0076db0
a0076250:  ba 07 60 01  inc  %i5
a0076254:  92 05 20 41  add  %l4, 0x41, %o1
a0076258:  93 2a 60 18  sll  %o1, 0x18, %o1
a007625c:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a0076260:  93 3a 60 18  sra  %o1, 0x18, %o1
a0076264:  94 10 00 10  mov  %l0, %o2
a0076268:  7f ff f3 77  call  0xa0073044
a007626c:  90 12 22 20  or  %o0, 0x220, %o0
a0076270:  10 80 02 d0  b  0xa0076db0
a0076274:  ba 07 60 01  inc  %i5
a0076278:  82 00 40 0a  add  %g1, %o2, %g1
a007627c:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a0076280:  9a 13 60 c4  or  %o5, 0xc4, %o5	! 0xa807ccc4
a0076284:  83 28 60 02  sll  %g1, 2, %g1
a0076288:  82 00 40 0d  add  %g1, %o5, %g1
a007628c:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0076290:  80 a0 60 00  cmp  %g1, 0
a0076294:  02 80 00 07  be  0xa00762b0
a0076298:  da 0b 20 09  ldub  [ %o4 + 9 ], %o5
a007629c:  80 a3 60 02  cmp  %o5, 2
a00762a0:  08 80 00 08  bleu  0xa00762c0
a00762a4:  80 a4 20 02  cmp  %l0, 2
a00762a8:  10 80 00 4e  b  0xa00763e0
a00762ac:  ae 0d 20 ff  and  %l4, 0xff, %l7
a00762b0:  80 a3 60 00  cmp  %o5, 0
a00762b4:  12 80 00 4b  bne  0xa00763e0
a00762b8:  ae 0d 20 ff  and  %l4, 0xff, %l7
a00762bc:  80 a4 20 02  cmp  %l0, 2
a00762c0:  18 80 00 0a  bgu  0xa00762e8
a00762c4:  b0 0d 20 ff  and  %l4, 0xff, %i0
a00762c8:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00762cc:  9a 04 00 10  add  %l0, %l0, %o5
a00762d0:  82 10 63 96  or  %g1, 0x396, %g1
a00762d4:  d6 10 40 0d  lduh  [ %g1 + %o5 ], %o3
a00762d8:  90 10 20 01  mov  1, %o0
a00762dc:  40 00 c4 52  call  0xa00a7424
a00762e0:  92 10 20 0f  mov  0xf, %o1
a00762e4:  b0 0d 20 ff  and  %l4, 0xff, %i0
a00762e8:  7f ff f4 8e  call  0xa0073520
a00762ec:  90 10 00 18  mov  %i0, %o0
a00762f0:  80 8a 20 ff  btst  0xff, %o0
a00762f4:  02 80 00 0d  be  0xa0076328
a00762f8:  80 a4 20 02  cmp  %l0, 2
a00762fc:  18 80 00 21  bgu  0xa0076380
a0076300:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0076304:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a0076308:  82 04 00 10  add  %l0, %l0, %g1
a007630c:  9a 13 63 90  or  %o5, 0x390, %o5
a0076310:  15 3f c3 ff  sethi  %hi(0xff0ffc00), %o2
a0076314:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a0076318:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007631c:  90 10 00 18  mov  %i0, %o0
a0076320:  10 80 00 15  b  0xa0076374
a0076324:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a0076328:  18 80 00 16  bgu  0xa0076380
a007632c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0076330:  9a 14 61 f0  or  %l1, 0x1f0, %o5
a0076334:  82 5e 28 98  smul  %i0, 0x898, %g1
a0076338:  82 00 40 0d  add  %g1, %o5, %g1
a007633c:  82 00 40 10  add  %g1, %l0, %g1
a0076340:  da 08 60 09  ldub  [ %g1 + 9 ], %o5
a0076344:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0076348:  82 10 62 c8  or  %g1, 0x2c8, %g1	! 0xa00b3ac8
a007634c:  d6 08 40 0d  ldub  [ %g1 + %o5 ], %o3
a0076350:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0076354:  96 0a e0 0f  and  %o3, 0xf, %o3
a0076358:  9a 04 00 10  add  %l0, %l0, %o5
a007635c:  82 10 63 90  or  %g1, 0x390, %g1
a0076360:  15 3f c3 ff  sethi  %hi(0xff0ffc00), %o2
a0076364:  d2 10 40 0d  lduh  [ %g1 + %o5 ], %o1
a0076368:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007636c:  97 2a e0 14  sll  %o3, 0x14, %o3
a0076370:  90 10 00 18  mov  %i0, %o0
a0076374:  40 00 c4 45  call  0xa00a7488
a0076378:  01 00 00 00  nop
a007637c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0076380:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0076384:  80 88 60 02  btst  2, %g1
a0076388:  22 80 02 8a  be,a   0xa0076db0
a007638c:  ba 07 60 01  inc  %i5
a0076390:  80 a4 20 02  cmp  %l0, 2
a0076394:  18 80 00 0a  bgu  0xa00763bc
a0076398:  96 10 20 00  clr  %o3
a007639c:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a00763a0:  82 04 00 10  add  %l0, %l0, %g1
a00763a4:  9a 13 63 90  or  %o5, 0x390, %o5
a00763a8:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a00763ac:  40 00 c3 da  call  0xa00a7314
a00763b0:  90 10 00 18  mov  %i0, %o0
a00763b4:  91 32 20 14  srl  %o0, 0x14, %o0
a00763b8:  96 0a 20 0f  and  %o0, 0xf, %o3
a00763bc:  92 05 20 41  add  %l4, 0x41, %o1
a00763c0:  93 2a 60 18  sll  %o1, 0x18, %o1
a00763c4:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a00763c8:  93 3a 60 18  sra  %o1, 0x18, %o1
a00763cc:  94 10 00 10  mov  %l0, %o2
a00763d0:  7f ff f3 1d  call  0xa0073044
a00763d4:  90 12 22 68  or  %o0, 0x268, %o0
a00763d8:  10 80 02 76  b  0xa0076db0
a00763dc:  ba 07 60 01  inc  %i5
a00763e0:  82 05 c0 17  add  %l7, %l7, %g1
a00763e4:  82 00 40 17  add  %g1, %l7, %g1
a00763e8:  19 2a 01 f3  sethi  %hi(0xa807cc00), %o4
a00763ec:  83 28 60 02  sll  %g1, 2, %g1
a00763f0:  98 13 20 c4  or  %o4, 0xc4, %o4
a00763f4:  82 00 40 0c  add  %g1, %o4, %g1
a00763f8:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a00763fc:  c2 27 bf 5c  st  %g1, [ %fp + -164 ]
a0076400:  03 09 24 92  sethi  %hi(0x24924800), %g1
a0076404:  b4 10 61 25  or  %g1, 0x125, %i2	! 0x24924925
a0076408:  10 80 00 c1  b  0xa007670c
a007640c:  a6 10 20 00  clr  %l3
a0076410:  98 02 80 0a  add  %o2, %o2, %o4
a0076414:  9e 0d 20 ff  and  %l4, 0xff, %o7
a0076418:  82 07 bf f8  add  %fp, -8, %g1
a007641c:  98 03 00 0a  add  %o4, %o2, %o4
a0076420:  98 03 00 01  add  %o4, %g1, %o4
a0076424:  9a 03 c0 0f  add  %o7, %o7, %o5
a0076428:  9a 03 40 0f  add  %o5, %o7, %o5
a007642c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0076430:  82 10 60 c4  or  %g1, 0xc4, %g1	! 0xa807ccc4
a0076434:  97 2a a0 02  sll  %o2, 2, %o3
a0076438:  9b 2b 60 02  sll  %o5, 2, %o5
a007643c:  92 0f 60 ff  and  %i5, 0xff, %o1
a0076440:  a0 03 40 01  add  %o5, %g1, %l0
a0076444:  96 02 c0 0a  add  %o3, %o2, %o3
a0076448:  b2 03 00 09  add  %o4, %o1, %i1
a007644c:  97 2a e0 02  sll  %o3, 2, %o3
a0076450:  11 2a 01 ea  sethi  %hi(0xa807a800), %o0
a0076454:  03 33 33 33  sethi  %hi(0xcccccc00), %g1
a0076458:  d8 0c 20 08  ldub  [ %l0 + 8 ], %o4
a007645c:  b6 12 21 f0  or  %o0, 0x1f0, %i3
a0076460:  ac 10 60 cd  or  %g1, 0xcd, %l6
a0076464:  96 02 c0 0a  add  %o3, %o2, %o3
a0076468:  b0 10 20 00  clr  %i0
a007646c:  d8 27 bf 58  st  %o4, [ %fp + -168 ]
a0076470:  aa 5b e2 26  smul  %o7, 0x226, %l5
a0076474:  10 80 00 82  b  0xa007667c
a0076478:  a4 5a a0 2a  smul  %o2, 0x2a, %l2
a007647c:  82 00 40 0c  add  %g1, %o4, %g1
a0076480:  82 05 40 01  add  %l5, %g1, %g1
a0076484:  82 00 40 12  add  %g1, %l2, %g1
a0076488:  82 00 40 09  add  %g1, %o1, %g1
a007648c:  83 28 60 02  sll  %g1, 2, %g1
a0076490:  82 00 40 1b  add  %g1, %i3, %g1
a0076494:  c2 00 60 80  ld  [ %g1 + 0x80 ], %g1
a0076498:  80 a0 60 0f  cmp  %g1, 0xf
a007649c:  18 80 00 1c  bgu  0xa007650c
a00764a0:  11 2a 01 ea  sethi  %hi(0xa807a800), %o0
a00764a4:  c2 0e 7f e8  ldub  [ %i1 + -24 ], %g1
a00764a8:  da 0c 20 08  ldub  [ %l0 + 8 ], %o5
a00764ac:  82 00 60 01  inc  %g1
a00764b0:  80 a3 60 00  cmp  %o5, 0
a00764b4:  02 80 00 07  be  0xa00764d0
a00764b8:  c2 2e 7f e8  stb  %g1, [ %i1 + -24 ]
a00764bc:  80 53 00 16  umul  %o4, %l6, %g0
a00764c0:  83 40 00 00  rd  %y, %g1
a00764c4:  83 30 60 02  srl  %g1, 2, %g1
a00764c8:  10 80 00 09  b  0xa00764ec
a00764cc:  80 a0 60 00  cmp  %g1, 0
a00764d0:  80 53 00 1a  umul  %o4, %i2, %g0
a00764d4:  9b 40 00 00  rd  %y, %o5
a00764d8:  82 23 00 0d  sub  %o4, %o5, %g1
a00764dc:  83 30 60 01  srl  %g1, 1, %g1
a00764e0:  9a 03 40 01  add  %o5, %g1, %o5
a00764e4:  9b 33 60 02  srl  %o5, 2, %o5
a00764e8:  80 a3 60 00  cmp  %o5, 0
a00764ec:  12 80 00 06  bne  0xa0076504
a00764f0:  c2 0f bf 67  ldub  [ %fp + -153 ], %g1
a00764f4:  da 0f bf 6f  ldub  [ %fp + -145 ], %o5
a00764f8:  9a 03 60 01  inc  %o5
a00764fc:  10 80 00 04  b  0xa007650c
a0076500:  da 2f bf 6f  stb  %o5, [ %fp + -145 ]
a0076504:  82 00 60 01  inc  %g1
a0076508:  c2 2f bf 67  stb  %g1, [ %fp + -153 ]
a007650c:  c2 0c 20 08  ldub  [ %l0 + 8 ], %g1
a0076510:  80 a0 60 00  cmp  %g1, 0
a0076514:  02 80 00 07  be  0xa0076530
a0076518:  01 00 00 00  nop
a007651c:  80 53 00 16  umul  %o4, %l6, %g0
a0076520:  83 40 00 00  rd  %y, %g1
a0076524:  83 30 60 02  srl  %g1, 2, %g1
a0076528:  10 80 00 09  b  0xa007654c
a007652c:  80 a0 60 00  cmp  %g1, 0
a0076530:  80 53 00 1a  umul  %o4, %i2, %g0
a0076534:  9b 40 00 00  rd  %y, %o5
a0076538:  82 23 00 0d  sub  %o4, %o5, %g1
a007653c:  83 30 60 01  srl  %g1, 1, %g1
a0076540:  9a 03 40 01  add  %o5, %g1, %o5
a0076544:  9b 33 60 02  srl  %o5, 2, %o5
a0076548:  80 a3 60 00  cmp  %o5, 0
a007654c:  12 80 00 27  bne  0xa00765e8
a0076550:  c2 0c 20 08  ldub  [ %l0 + 8 ], %g1
a0076554:  80 a0 60 00  cmp  %g1, 0
a0076558:  b8 12 21 f0  or  %o0, 0x1f0, %i4
a007655c:  02 80 00 08  be  0xa007657c
a0076560:  a2 02 c0 09  add  %o3, %o1, %l1
a0076564:  80 53 00 16  umul  %o4, %l6, %g0
a0076568:  83 40 00 00  rd  %y, %g1
a007656c:  83 30 60 02  srl  %g1, 2, %g1
a0076570:  9b 28 60 02  sll  %g1, 2, %o5
a0076574:  10 80 00 0a  b  0xa007659c
a0076578:  9a 03 40 01  add  %o5, %g1, %o5
a007657c:  80 53 00 1a  umul  %o4, %i2, %g0
a0076580:  83 40 00 00  rd  %y, %g1
a0076584:  9a 23 00 01  sub  %o4, %g1, %o5
a0076588:  9b 33 60 01  srl  %o5, 1, %o5
a007658c:  82 00 40 0d  add  %g1, %o5, %g1
a0076590:  83 30 60 02  srl  %g1, 2, %g1
a0076594:  9b 28 60 03  sll  %g1, 3, %o5
a0076598:  9a 23 40 01  sub  %o5, %g1, %o5
a007659c:  9a 23 00 0d  sub  %o4, %o5, %o5
a00765a0:  82 03 40 0d  add  %o5, %o5, %g1
a00765a4:  82 00 40 0d  add  %g1, %o5, %g1
a00765a8:  91 28 60 02  sll  %g1, 2, %o0
a00765ac:  82 03 00 0c  add  %o4, %o4, %g1
a00765b0:  82 00 40 0c  add  %g1, %o4, %g1
a00765b4:  82 05 40 01  add  %l5, %g1, %g1
a00765b8:  82 00 40 12  add  %g1, %l2, %g1
a00765bc:  9b 2c 60 02  sll  %l1, 2, %o5
a00765c0:  82 00 40 09  add  %g1, %o1, %g1
a00765c4:  98 5b e8 98  smul  %o7, 0x898, %o4
a00765c8:  9a 03 40 0c  add  %o5, %o4, %o5
a00765cc:  83 28 60 02  sll  %g1, 2, %g1
a00765d0:  9a 03 40 1c  add  %o5, %i4, %o5
a00765d4:  82 00 40 1b  add  %g1, %i3, %g1
a00765d8:  9a 03 40 08  add  %o5, %o0, %o5
a00765dc:  c2 00 60 80  ld  [ %g1 + 0x80 ], %g1
a00765e0:  10 80 00 26  b  0xa0076678
a00765e4:  c2 23 64 70  st  %g1, [ %o5 + 0x470 ]
a00765e8:  80 a0 60 00  cmp  %g1, 0
a00765ec:  b8 12 21 f0  or  %o0, 0x1f0, %i4
a00765f0:  02 80 00 08  be  0xa0076610
a00765f4:  a2 02 c0 09  add  %o3, %o1, %l1
a00765f8:  80 53 00 16  umul  %o4, %l6, %g0
a00765fc:  83 40 00 00  rd  %y, %g1
a0076600:  83 30 60 02  srl  %g1, 2, %g1
a0076604:  9b 28 60 02  sll  %g1, 2, %o5
a0076608:  10 80 00 0a  b  0xa0076630
a007660c:  9a 03 40 01  add  %o5, %g1, %o5
a0076610:  80 53 00 1a  umul  %o4, %i2, %g0
a0076614:  83 40 00 00  rd  %y, %g1
a0076618:  9a 23 00 01  sub  %o4, %g1, %o5
a007661c:  9b 33 60 01  srl  %o5, 1, %o5
a0076620:  82 00 40 0d  add  %g1, %o5, %g1
a0076624:  83 30 60 02  srl  %g1, 2, %g1
a0076628:  9b 28 60 03  sll  %g1, 3, %o5
a007662c:  9a 23 40 01  sub  %o5, %g1, %o5
a0076630:  9a 23 00 0d  sub  %o4, %o5, %o5
a0076634:  82 03 40 0d  add  %o5, %o5, %g1
a0076638:  82 00 40 0d  add  %g1, %o5, %g1
a007663c:  91 28 60 02  sll  %g1, 2, %o0
a0076640:  82 03 00 0c  add  %o4, %o4, %g1
a0076644:  82 00 40 0c  add  %g1, %o4, %g1
a0076648:  82 05 40 01  add  %l5, %g1, %g1
a007664c:  82 00 40 12  add  %g1, %l2, %g1
a0076650:  9b 2c 60 02  sll  %l1, 2, %o5
a0076654:  82 00 40 09  add  %g1, %o1, %g1
a0076658:  98 5b e8 98  smul  %o7, 0x898, %o4
a007665c:  9a 03 40 0c  add  %o5, %o4, %o5
a0076660:  83 28 60 02  sll  %g1, 2, %g1
a0076664:  9a 03 40 1c  add  %o5, %i4, %o5
a0076668:  82 00 40 1b  add  %g1, %i3, %g1
a007666c:  9a 03 40 08  add  %o5, %o0, %o5
a0076670:  c2 00 60 80  ld  [ %g1 + 0x80 ], %g1
a0076674:  c2 23 66 68  st  %g1, [ %o5 + 0x668 ]
a0076678:  b0 06 20 01  inc  %i0
a007667c:  d8 07 bf 58  ld  [ %fp + -168 ], %o4
a0076680:  80 a3 20 00  cmp  %o4, 0
a0076684:  02 80 00 04  be  0xa0076694
a0076688:  98 0e 20 ff  and  %i0, 0xff, %o4
a007668c:  10 80 00 03  b  0xa0076698
a0076690:  80 a3 20 09  cmp  %o4, 9
a0076694:  80 a3 20 0d  cmp  %o4, 0xd
a0076698:  28 bf ff 79  bleu,a   0xa007647c
a007669c:  82 03 00 0c  add  %o4, %o4, %g1
a00766a0:  82 03 c0 0f  add  %o7, %o7, %g1
a00766a4:  82 00 40 0f  add  %g1, %o7, %g1
a00766a8:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a00766ac:  9a 13 60 c4  or  %o5, 0xc4, %o5	! 0xa807ccc4
a00766b0:  83 28 60 02  sll  %g1, 2, %g1
a00766b4:  82 00 40 0d  add  %g1, %o5, %g1
a00766b8:  da 08 60 08  ldub  [ %g1 + 8 ], %o5
a00766bc:  80 a0 00 0d  cmp  %g0, %o5
a00766c0:  82 02 80 0a  add  %o2, %o2, %g1
a00766c4:  9a 5b e4 4c  smul  %o7, 0x44c, %o5
a00766c8:  82 00 40 0a  add  %g1, %o2, %g1
a00766cc:  82 00 40 0d  add  %g1, %o5, %g1
a00766d0:  d8 0f bf 67  ldub  [ %fp + -153 ], %o4
a00766d4:  da 0f bf 6f  ldub  [ %fp + -145 ], %o5
a00766d8:  96 40 20 00  addx  %g0, 0, %o3
a00766dc:  80 a3 00 0d  cmp  %o4, %o5
a00766e0:  82 00 40 09  add  %g1, %o1, %g1
a00766e4:  19 2a 01 ea  sethi  %hi(0xa807a800), %o4
a00766e8:  82 00 40 01  add  %g1, %g1, %g1
a00766ec:  9a 60 3f ff  subx  %g0, -1, %o5
a00766f0:  98 13 21 f0  or  %o4, 0x1f0, %o4
a00766f4:  96 12 c0 0d  or  %o3, %o5, %o3
a00766f8:  82 00 40 0c  add  %g1, %o4, %g1
a00766fc:  d6 30 68 60  sth  %o3, [ %g1 + 0x860 ]
a0076700:  c0 2f bf 67  clrb  [ %fp + -153 ]
a0076704:  c0 2f bf 6f  clrb  [ %fp + -145 ]
a0076708:  a6 04 e0 01  inc  %l3
a007670c:  da 07 bf 5c  ld  [ %fp + -164 ], %o5
a0076710:  80 a3 60 00  cmp  %o5, 0
a0076714:  02 80 00 07  be  0xa0076730
a0076718:  82 0c e0 ff  and  %l3, 0xff, %g1
a007671c:  80 a0 60 02  cmp  %g1, 2
a0076720:  08 bf ff 3c  bleu  0xa0076410
a0076724:  94 0c e0 ff  and  %l3, 0xff, %o2
a0076728:  10 80 00 06  b  0xa0076740
a007672c:  21 2a 01 e1  sethi  %hi(0xa8078400), %l0
a0076730:  80 a0 60 00  cmp  %g1, 0
a0076734:  02 bf ff 37  be  0xa0076410
a0076738:  94 0c e0 ff  and  %l3, 0xff, %o2
a007673c:  21 2a 01 e1  sethi  %hi(0xa8078400), %l0
a0076740:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1	! 0xa8078634
a0076744:  80 88 60 02  btst  2, %g1
a0076748:  22 80 00 1f  be,a   0xa00767c4
a007674c:  a6 10 20 00  clr  %l3
a0076750:  92 05 20 41  add  %l4, 0x41, %o1
a0076754:  93 2a 60 18  sll  %o1, 0x18, %o1
a0076758:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a007675c:  90 12 22 a0  or  %o0, 0x2a0, %o0	! 0xa0066ea0
a0076760:  7f ff f2 39  call  0xa0073044
a0076764:  93 3a 60 18  sra  %o1, 0x18, %o1
a0076768:  10 80 00 17  b  0xa00767c4
a007676c:  a6 10 20 00  clr  %l3
a0076770:  80 88 60 02  btst  2, %g1
a0076774:  02 80 00 05  be  0xa0076788
a0076778:  9a 0c e0 ff  and  %l3, 0xff, %o5
a007677c:  7f ff f2 32  call  0xa0073044
a0076780:  01 00 00 00  nop
a0076784:  9a 0c e0 ff  and  %l3, 0xff, %o5
a0076788:  82 03 40 0d  add  %o5, %o5, %g1
a007678c:  82 00 40 0d  add  %g1, %o5, %g1
a0076790:  9a 07 bf f8  add  %fp, -8, %o5
a0076794:  82 00 40 0d  add  %g1, %o5, %g1
a0076798:  92 0f 60 ff  and  %i5, 0xff, %o1
a007679c:  9a 00 40 09  add  %g1, %o1, %o5
a00767a0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00767a4:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a00767a8:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a00767ac:  90 12 22 e0  or  %o0, 0x2e0, %o0	! 0xa0066ee0
a00767b0:  80 88 60 02  btst  2, %g1
a00767b4:  02 80 00 04  be  0xa00767c4
a00767b8:  a6 04 e0 01  inc  %l3
a00767bc:  7f ff f2 22  call  0xa0073044
a00767c0:  d4 0b 7f e8  ldub  [ %o5 + -24 ], %o2
a00767c4:  82 05 c0 17  add  %l7, %l7, %g1
a00767c8:  82 00 40 17  add  %g1, %l7, %g1
a00767cc:  19 2a 01 f3  sethi  %hi(0xa807cc00), %o4
a00767d0:  83 28 60 02  sll  %g1, 2, %g1
a00767d4:  9a 13 20 c4  or  %o4, 0xc4, %o5
a00767d8:  82 00 40 0d  add  %g1, %o5, %g1
a00767dc:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a00767e0:  80 a0 60 00  cmp  %g1, 0
a00767e4:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a00767e8:  82 0c e0 ff  and  %l3, 0xff, %g1
a00767ec:  90 12 23 00  or  %o0, 0x300, %o0
a00767f0:  02 80 00 07  be  0xa007680c
a00767f4:  92 10 00 01  mov  %g1, %o1
a00767f8:  80 a0 60 02  cmp  %g1, 2
a00767fc:  08 bf ff dd  bleu  0xa0076770
a0076800:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1
a0076804:  10 80 00 06  b  0xa007681c
a0076808:  25 2a 01 e1  sethi  %hi(0xa8078400), %l2
a007680c:  80 a0 60 00  cmp  %g1, 0
a0076810:  02 bf ff d8  be  0xa0076770
a0076814:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1
a0076818:  25 2a 01 e1  sethi  %hi(0xa8078400), %l2
a007681c:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1	! 0xa8078634
a0076820:  80 88 60 02  btst  2, %g1
a0076824:  22 80 00 0c  be,a   0xa0076854
a0076828:  a0 0f 60 ff  and  %i5, 0xff, %l0
a007682c:  94 0f 60 ff  and  %i5, 0xff, %o2
a0076830:  92 05 20 41  add  %l4, 0x41, %o1
a0076834:  93 2a 60 18  sll  %o1, 0x18, %o1
a0076838:  82 07 80 0a  add  %fp, %o2, %g1
a007683c:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a0076840:  90 12 23 18  or  %o0, 0x318, %o0	! 0xa0066f18
a0076844:  93 3a 60 18  sra  %o1, 0x18, %o1
a0076848:  7f ff f1 ff  call  0xa0073044
a007684c:  d6 08 7f e0  ldub  [ %g1 + -32 ], %o3
a0076850:  a0 0f 60 ff  and  %i5, 0xff, %l0
a0076854:  a2 07 bf f8  add  %fp, -8, %l1
a0076858:  82 04 40 10  add  %l1, %l0, %g1
a007685c:  ec 08 7f e8  ldub  [ %g1 + -24 ], %l6
a0076860:  aa 10 20 00  clr  %l5
a0076864:  10 80 00 0e  b  0xa007689c
a0076868:  a6 10 20 01  mov  1, %l3
a007686c:  f0 0b 3f e8  ldub  [ %o4 + -24 ], %i0
a0076870:  80 88 60 02  btst  2, %g1
a0076874:  02 80 00 04  be  0xa0076884
a0076878:  98 10 00 18  mov  %i0, %o4
a007687c:  7f ff f1 f2  call  0xa0073044
a0076880:  ec 23 a0 5c  st  %l6, [ %sp + 0x5c ]
a0076884:  80 a6 00 16  cmp  %i0, %l6
a0076888:  28 80 00 05  bleu,a   0xa007689c
a007688c:  a6 04 e0 01  inc  %l3
a0076890:  ac 10 00 18  mov  %i0, %l6
a0076894:  aa 10 00 13  mov  %l3, %l5
a0076898:  a6 04 e0 01  inc  %l3
a007689c:  82 05 c0 17  add  %l7, %l7, %g1
a00768a0:  19 2a 01 f3  sethi  %hi(0xa807cc00), %o4
a00768a4:  82 00 40 17  add  %g1, %l7, %g1
a00768a8:  9a 13 20 c4  or  %o4, 0xc4, %o5
a00768ac:  83 28 60 02  sll  %g1, 2, %g1
a00768b0:  82 00 40 0d  add  %g1, %o5, %g1
a00768b4:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a00768b8:  9e 0c e0 ff  and  %l3, 0xff, %o7
a00768bc:  80 a0 60 00  cmp  %g1, 0
a00768c0:  82 03 c0 0f  add  %o7, %o7, %g1
a00768c4:  92 05 20 41  add  %l4, 0x41, %o1
a00768c8:  82 00 40 0f  add  %g1, %o7, %g1
a00768cc:  93 2a 60 18  sll  %o1, 0x18, %o1
a00768d0:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a00768d4:  82 00 40 11  add  %g1, %l1, %g1
a00768d8:  90 12 23 58  or  %o0, 0x358, %o0
a00768dc:  93 3a 60 18  sra  %o1, 0x18, %o1
a00768e0:  98 00 40 10  add  %g1, %l0, %o4
a00768e4:  96 10 00 0f  mov  %o7, %o3
a00768e8:  9a 0d 60 ff  and  %l5, 0xff, %o5
a00768ec:  02 80 00 07  be  0xa0076908
a00768f0:  94 10 00 10  mov  %l0, %o2
a00768f4:  80 a3 e0 02  cmp  %o7, 2
a00768f8:  08 bf ff dd  bleu  0xa007686c
a00768fc:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1
a0076900:  10 80 00 06  b  0xa0076918
a0076904:  25 2a 01 e1  sethi  %hi(0xa8078400), %l2
a0076908:  80 a3 e0 00  cmp  %o7, 0
a007690c:  02 bf ff d8  be  0xa007686c
a0076910:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1
a0076914:  25 2a 01 e1  sethi  %hi(0xa8078400), %l2
a0076918:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1	! 0xa8078634
a007691c:  80 88 60 02  btst  2, %g1
a0076920:  02 80 00 0c  be  0xa0076950
a0076924:  80 8d 60 ff  btst  0xff, %l5
a0076928:  92 05 20 41  add  %l4, 0x41, %o1
a007692c:  93 2a 60 18  sll  %o1, 0x18, %o1
a0076930:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a0076934:  90 12 23 b8  or  %o0, 0x3b8, %o0	! 0xa0066fb8
a0076938:  93 3a 60 18  sra  %o1, 0x18, %o1
a007693c:  94 0f 60 ff  and  %i5, 0xff, %o2
a0076940:  96 0d 60 ff  and  %l5, 0xff, %o3
a0076944:  7f ff f1 c0  call  0xa0073044
a0076948:  98 10 00 16  mov  %l6, %o4
a007694c:  80 8d 60 ff  btst  0xff, %l5
a0076950:  12 80 00 cb  bne  0xa0076c7c
a0076954:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0076958:  80 a5 a0 00  cmp  %l6, 0
a007695c:  02 80 00 82  be  0xa0076b64
a0076960:  a6 10 20 00  clr  %l3
a0076964:  10 80 00 c7  b  0xa0076c80
a0076968:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1
a007696c:  82 00 40 10  add  %g1, %l0, %g1
a0076970:  9a 15 e0 c4  or  %l7, 0xc4, %o5
a0076974:  83 28 60 02  sll  %g1, 2, %g1
a0076978:  82 00 40 0d  add  %g1, %o5, %g1
a007697c:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0076980:  80 a0 60 00  cmp  %g1, 0
a0076984:  9a 5c 22 26  smul  %l0, 0x226, %o5
a0076988:  c0 2f bf 77  clrb  [ %fp + -137 ]
a007698c:  11 2a 01 ea  sethi  %hi(0xa807a800), %o0
a0076990:  12 80 00 0d  bne  0xa00769c4
a0076994:  92 0f 60 ff  and  %i5, 0xff, %o1
a0076998:  83 2b 20 02  sll  %o4, 2, %g1
a007699c:  82 00 40 0c  add  %g1, %o4, %g1
a00769a0:  83 28 60 02  sll  %g1, 2, %g1
a00769a4:  82 00 40 0c  add  %g1, %o4, %g1
a00769a8:  82 03 40 01  add  %o5, %g1, %g1
a00769ac:  82 00 40 09  add  %g1, %o1, %g1
a00769b0:  9a 12 21 f0  or  %o0, 0x1f0, %o5
a00769b4:  83 28 60 02  sll  %g1, 2, %g1
a00769b8:  82 00 40 0d  add  %g1, %o5, %g1
a00769bc:  10 80 00 0c  b  0xa00769ec
a00769c0:  e2 00 64 70  ld  [ %g1 + 0x470 ], %l1
a00769c4:  83 2b 20 02  sll  %o4, 2, %g1
a00769c8:  82 00 40 0c  add  %g1, %o4, %g1
a00769cc:  83 28 60 02  sll  %g1, 2, %g1
a00769d0:  82 00 40 0c  add  %g1, %o4, %g1
a00769d4:  82 03 40 01  add  %o5, %g1, %g1
a00769d8:  82 00 40 09  add  %g1, %o1, %g1
a00769dc:  9a 12 21 f0  or  %o0, 0x1f0, %o5
a00769e0:  83 28 60 02  sll  %g1, 2, %g1
a00769e4:  82 00 40 0d  add  %g1, %o5, %g1
a00769e8:  e2 00 66 68  ld  [ %g1 + 0x668 ], %l1
a00769ec:  10 80 00 40  b  0xa0076aec
a00769f0:  c0 2f bf 7f  clrb  [ %fp + -129 ]
a00769f4:  82 00 40 0b  add  %g1, %o3, %g1
a00769f8:  9a 12 a0 c4  or  %o2, 0xc4, %o5
a00769fc:  83 28 60 02  sll  %g1, 2, %g1
a0076a00:  82 00 40 0d  add  %g1, %o5, %g1
a0076a04:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0076a08:  80 a0 60 00  cmp  %g1, 0
a0076a0c:  96 5a e2 26  smul  %o3, 0x226, %o3
a0076a10:  11 2a 01 ea  sethi  %hi(0xa807a800), %o0
a0076a14:  92 0f 60 ff  and  %i5, 0xff, %o1
a0076a18:  12 80 00 10  bne  0xa0076a58
a0076a1c:  94 0c e0 ff  and  %l3, 0xff, %o2
a0076a20:  83 2a a0 02  sll  %o2, 2, %g1
a0076a24:  82 00 40 0a  add  %g1, %o2, %g1
a0076a28:  9a 03 00 0c  add  %o4, %o4, %o5
a0076a2c:  9a 03 40 0c  add  %o5, %o4, %o5
a0076a30:  83 28 60 02  sll  %g1, 2, %g1
a0076a34:  82 00 40 0a  add  %g1, %o2, %g1
a0076a38:  9a 02 c0 0d  add  %o3, %o5, %o5
a0076a3c:  9a 03 40 01  add  %o5, %g1, %o5
a0076a40:  9a 03 40 09  add  %o5, %o1, %o5
a0076a44:  82 12 21 f0  or  %o0, 0x1f0, %g1
a0076a48:  9b 2b 60 02  sll  %o5, 2, %o5
a0076a4c:  9a 03 40 01  add  %o5, %g1, %o5
a0076a50:  10 80 00 0f  b  0xa0076a8c
a0076a54:  f0 03 64 70  ld  [ %o5 + 0x470 ], %i0
a0076a58:  83 2a a0 02  sll  %o2, 2, %g1
a0076a5c:  82 00 40 0a  add  %g1, %o2, %g1
a0076a60:  9a 03 00 0c  add  %o4, %o4, %o5
a0076a64:  9a 03 40 0c  add  %o5, %o4, %o5
a0076a68:  83 28 60 02  sll  %g1, 2, %g1
a0076a6c:  82 00 40 0a  add  %g1, %o2, %g1
a0076a70:  9a 02 c0 0d  add  %o3, %o5, %o5
a0076a74:  9a 03 40 01  add  %o5, %g1, %o5
a0076a78:  9a 03 40 09  add  %o5, %o1, %o5
a0076a7c:  82 12 21 f0  or  %o0, 0x1f0, %g1
a0076a80:  9b 2b 60 02  sll  %o5, 2, %o5
a0076a84:  9a 03 40 01  add  %o5, %g1, %o5
a0076a88:  f0 03 66 68  ld  [ %o5 + 0x668 ], %i0
a0076a8c:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1
a0076a90:  80 88 60 02  btst  2, %g1
a0076a94:  02 80 00 0e  be  0xa0076acc
a0076a98:  80 a6 00 11  cmp  %i0, %l1
a0076a9c:  92 05 20 41  add  %l4, 0x41, %o1
a0076aa0:  93 2a 60 18  sll  %o1, 0x18, %o1
a0076aa4:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a0076aa8:  e2 23 a0 5c  st  %l1, [ %sp + 0x5c ]
a0076aac:  90 12 20 70  or  %o0, 0x70, %o0
a0076ab0:  93 3a 60 18  sra  %o1, 0x18, %o1
a0076ab4:  94 0f 60 ff  and  %i5, 0xff, %o2
a0076ab8:  d6 0f bf 7f  ldub  [ %fp + -129 ], %o3
a0076abc:  98 10 00 18  mov  %i0, %o4
a0076ac0:  7f ff f1 61  call  0xa0073044
a0076ac4:  da 0f bf 77  ldub  [ %fp + -137 ], %o5
a0076ac8:  80 a6 00 11  cmp  %i0, %l1
a0076acc:  1a 80 00 06  bcc  0xa0076ae4
a0076ad0:  c2 0f bf 7f  ldub  [ %fp + -129 ], %g1
a0076ad4:  da 0f bf 7f  ldub  [ %fp + -129 ], %o5
a0076ad8:  a2 10 00 18  mov  %i0, %l1
a0076adc:  da 2f bf 77  stb  %o5, [ %fp + -137 ]
a0076ae0:  c2 0f bf 7f  ldub  [ %fp + -129 ], %g1
a0076ae4:  82 00 60 01  inc  %g1
a0076ae8:  c2 2f bf 7f  stb  %g1, [ %fp + -129 ]
a0076aec:  96 0d 20 ff  and  %l4, 0xff, %o3
a0076af0:  82 02 c0 0b  add  %o3, %o3, %g1
a0076af4:  82 00 40 0b  add  %g1, %o3, %g1
a0076af8:  15 2a 01 f3  sethi  %hi(0xa807cc00), %o2
a0076afc:  83 28 60 02  sll  %g1, 2, %g1
a0076b00:  9a 12 a0 c4  or  %o2, 0xc4, %o5
a0076b04:  82 00 40 0d  add  %g1, %o5, %g1
a0076b08:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0076b0c:  80 a0 60 00  cmp  %g1, 0
a0076b10:  02 80 00 04  be  0xa0076b20
a0076b14:  d8 0f bf 7f  ldub  [ %fp + -129 ], %o4
a0076b18:  10 80 00 03  b  0xa0076b24
a0076b1c:  80 a3 20 04  cmp  %o4, 4
a0076b20:  80 a3 20 06  cmp  %o4, 6
a0076b24:  08 bf ff b4  bleu  0xa00769f4
a0076b28:  82 02 c0 0b  add  %o3, %o3, %g1
a0076b2c:  9a 0c e0 ff  and  %l3, 0xff, %o5
a0076b30:  82 03 40 0d  add  %o5, %o5, %g1
a0076b34:  82 00 40 0d  add  %g1, %o5, %g1
a0076b38:  96 0f 60 ff  and  %i5, 0xff, %o3
a0076b3c:  9a 00 40 0b  add  %g1, %o3, %o5
a0076b40:  98 07 bf f8  add  %fp, -8, %o4
a0076b44:  9b 2b 60 02  sll  %o5, 2, %o5
a0076b48:  82 00 40 0c  add  %g1, %o4, %g1
a0076b4c:  9a 03 40 0c  add  %o5, %o4, %o5
a0076b50:  82 00 40 0b  add  %g1, %o3, %g1
a0076b54:  d8 0f bf 77  ldub  [ %fp + -137 ], %o4
a0076b58:  e2 23 7f 88  st  %l1, [ %o5 + -120 ]
a0076b5c:  d8 28 7f d0  stb  %o4, [ %g1 + -48 ]
a0076b60:  a6 04 e0 01  inc  %l3
a0076b64:  a0 0d 20 ff  and  %l4, 0xff, %l0
a0076b68:  82 04 00 10  add  %l0, %l0, %g1
a0076b6c:  82 00 40 10  add  %g1, %l0, %g1
a0076b70:  2f 2a 01 f3  sethi  %hi(0xa807cc00), %l7
a0076b74:  83 28 60 02  sll  %g1, 2, %g1
a0076b78:  9a 15 e0 c4  or  %l7, 0xc4, %o5
a0076b7c:  82 00 40 0d  add  %g1, %o5, %g1
a0076b80:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0076b84:  80 a0 60 00  cmp  %g1, 0
a0076b88:  02 80 00 07  be  0xa0076ba4
a0076b8c:  98 0c e0 ff  and  %l3, 0xff, %o4
a0076b90:  80 a3 20 02  cmp  %o4, 2
a0076b94:  08 bf ff 76  bleu  0xa007696c
a0076b98:  82 04 00 10  add  %l0, %l0, %g1
a0076b9c:  10 80 00 06  b  0xa0076bb4
a0076ba0:  a4 0f 60 ff  and  %i5, 0xff, %l2
a0076ba4:  80 a3 20 00  cmp  %o4, 0
a0076ba8:  02 bf ff 71  be  0xa007696c
a0076bac:  82 04 00 10  add  %l0, %l0, %g1
a0076bb0:  a4 0f 60 ff  and  %i5, 0xff, %l2
a0076bb4:  83 2c a0 02  sll  %l2, 2, %g1
a0076bb8:  b8 07 bf f8  add  %fp, -8, %i4
a0076bbc:  82 00 40 1c  add  %g1, %i4, %g1
a0076bc0:  e2 00 7f 88  ld  [ %g1 + -120 ], %l1
a0076bc4:  aa 10 20 00  clr  %l5
a0076bc8:  10 80 00 0f  b  0xa0076c04
a0076bcc:  a6 10 20 00  clr  %l3
a0076bd0:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1
a0076bd4:  f0 03 3f 88  ld  [ %o4 + -120 ], %i0
a0076bd8:  80 88 60 02  btst  2, %g1
a0076bdc:  02 80 00 04  be  0xa0076bec
a0076be0:  98 10 00 18  mov  %i0, %o4
a0076be4:  7f ff f1 18  call  0xa0073044
a0076be8:  e2 23 a0 5c  st  %l1, [ %sp + 0x5c ]
a0076bec:  80 a6 00 11  cmp  %i0, %l1
a0076bf0:  3a 80 00 05  bcc,a   0xa0076c04
a0076bf4:  a6 04 e0 01  inc  %l3
a0076bf8:  a2 10 00 18  mov  %i0, %l1
a0076bfc:  aa 10 00 13  mov  %l3, %l5
a0076c00:  a6 04 e0 01  inc  %l3
a0076c04:  82 04 00 10  add  %l0, %l0, %g1
a0076c08:  82 00 40 10  add  %g1, %l0, %g1
a0076c0c:  9a 15 e0 c4  or  %l7, 0xc4, %o5
a0076c10:  83 28 60 02  sll  %g1, 2, %g1
a0076c14:  82 00 40 0d  add  %g1, %o5, %g1
a0076c18:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0076c1c:  9e 0c e0 ff  and  %l3, 0xff, %o7
a0076c20:  80 a0 60 00  cmp  %g1, 0
a0076c24:  82 03 c0 0f  add  %o7, %o7, %g1
a0076c28:  82 00 40 0f  add  %g1, %o7, %g1
a0076c2c:  92 05 20 41  add  %l4, 0x41, %o1
a0076c30:  82 00 40 12  add  %g1, %l2, %g1
a0076c34:  93 2a 60 18  sll  %o1, 0x18, %o1
a0076c38:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a0076c3c:  83 28 60 02  sll  %g1, 2, %g1
a0076c40:  90 12 20 70  or  %o0, 0x70, %o0
a0076c44:  93 3a 60 18  sra  %o1, 0x18, %o1
a0076c48:  98 00 40 1c  add  %g1, %i4, %o4
a0076c4c:  94 10 00 12  mov  %l2, %o2
a0076c50:  d6 0f bf 7f  ldub  [ %fp + -129 ], %o3
a0076c54:  02 80 00 07  be  0xa0076c70
a0076c58:  da 0f bf 77  ldub  [ %fp + -137 ], %o5
a0076c5c:  80 a3 e0 02  cmp  %o7, 2
a0076c60:  08 bf ff dc  bleu  0xa0076bd0
a0076c64:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0076c68:  10 80 00 06  b  0xa0076c80
a0076c6c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0076c70:  80 a3 e0 00  cmp  %o7, 0
a0076c74:  02 bf ff d7  be  0xa0076bd0
a0076c78:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0076c7c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0076c80:  80 88 60 02  btst  2, %g1
a0076c84:  02 80 00 0c  be  0xa0076cb4
a0076c88:  a0 0d 20 ff  and  %l4, 0xff, %l0
a0076c8c:  92 05 20 41  add  %l4, 0x41, %o1
a0076c90:  93 2a 60 18  sll  %o1, 0x18, %o1
a0076c94:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a0076c98:  90 12 20 08  or  %o0, 8, %o0	! 0xa0067008
a0076c9c:  93 3a 60 18  sra  %o1, 0x18, %o1
a0076ca0:  94 0f 60 ff  and  %i5, 0xff, %o2
a0076ca4:  96 0d 60 ff  and  %l5, 0xff, %o3
a0076ca8:  7f ff f0 e7  call  0xa0073044
a0076cac:  98 10 00 16  mov  %l6, %o4
a0076cb0:  a0 0d 20 ff  and  %l4, 0xff, %l0
a0076cb4:  23 2a 01 ea  sethi  %hi(0xa807a800), %l1
a0076cb8:  9a 14 61 f0  or  %l1, 0x1f0, %o5	! 0xa807a9f0
a0076cbc:  82 5c 28 98  smul  %l0, 0x898, %g1
a0076cc0:  82 00 40 0d  add  %g1, %o5, %g1
a0076cc4:  b0 0f 60 ff  and  %i5, 0xff, %i0
a0076cc8:  82 00 40 18  add  %g1, %i0, %g1
a0076ccc:  ec 28 68 93  stb  %l6, [ %g1 + 0x893 ]
a0076cd0:  ea 28 68 90  stb  %l5, [ %g1 + 0x890 ]
a0076cd4:  90 10 00 10  mov  %l0, %o0
a0076cd8:  7f ff fa e0  call  0xa0075858
a0076cdc:  92 10 00 18  mov  %i0, %o1
a0076ce0:  80 8a 20 ff  btst  0xff, %o0
a0076ce4:  02 80 00 4f  be  0xa0076e20
a0076ce8:  80 a6 20 02  cmp  %i0, 2
a0076cec:  18 80 00 09  bgu  0xa0076d10
a0076cf0:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0076cf4:  9a 06 00 18  add  %i0, %i0, %o5
a0076cf8:  82 10 63 96  or  %g1, 0x396, %g1
a0076cfc:  d6 10 40 0d  lduh  [ %g1 + %o5 ], %o3
a0076d00:  90 10 20 01  mov  1, %o0
a0076d04:  92 10 20 0f  mov  0xf, %o1
a0076d08:  40 00 c1 c7  call  0xa00a7424
a0076d0c:  94 10 00 10  mov  %l0, %o2
a0076d10:  7f ff f2 04  call  0xa0073520
a0076d14:  90 10 00 10  mov  %l0, %o0
a0076d18:  80 8a 20 ff  btst  0xff, %o0
a0076d1c:  02 80 00 0d  be  0xa0076d50
a0076d20:  80 a6 20 02  cmp  %i0, 2
a0076d24:  18 80 00 1d  bgu  0xa0076d98
a0076d28:  82 14 61 f0  or  %l1, 0x1f0, %g1
a0076d2c:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a0076d30:  82 06 00 18  add  %i0, %i0, %g1
a0076d34:  9a 13 63 90  or  %o5, 0x390, %o5
a0076d38:  15 3f c3 ff  sethi  %hi(0xff0ffc00), %o2
a0076d3c:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a0076d40:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0076d44:  90 10 00 10  mov  %l0, %o0
a0076d48:  10 80 00 11  b  0xa0076d8c
a0076d4c:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a0076d50:  18 80 00 12  bgu  0xa0076d98
a0076d54:  82 14 61 f0  or  %l1, 0x1f0, %g1
a0076d58:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0076d5c:  9a 0d 60 ff  and  %l5, 0xff, %o5
a0076d60:  82 10 62 c8  or  %g1, 0x2c8, %g1
a0076d64:  d6 08 40 0d  ldub  [ %g1 + %o5 ], %o3
a0076d68:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0076d6c:  96 0a e0 0f  and  %o3, 0xf, %o3
a0076d70:  9a 06 00 18  add  %i0, %i0, %o5
a0076d74:  82 10 63 90  or  %g1, 0x390, %g1
a0076d78:  15 3f c3 ff  sethi  %hi(0xff0ffc00), %o2
a0076d7c:  d2 10 40 0d  lduh  [ %g1 + %o5 ], %o1
a0076d80:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0076d84:  97 2a e0 14  sll  %o3, 0x14, %o3
a0076d88:  90 10 00 10  mov  %l0, %o0
a0076d8c:  40 00 c1 bf  call  0xa00a7488
a0076d90:  01 00 00 00  nop
a0076d94:  82 14 61 f0  or  %l1, 0x1f0, %g1
a0076d98:  9a 5c 28 98  smul  %l0, 0x898, %o5
a0076d9c:  9a 03 40 01  add  %o5, %g1, %o5
a0076da0:  9a 03 40 18  add  %o5, %i0, %o5
a0076da4:  82 10 20 01  mov  1, %g1
a0076da8:  c2 2b 60 2d  stb  %g1, [ %o5 + 0x2d ]
a0076dac:  ba 07 60 01  inc  %i5
a0076db0:  82 0f 60 ff  and  %i5, 0xff, %g1
a0076db4:  80 a0 60 02  cmp  %g1, 2
a0076db8:  08 bf fd 18  bleu  0xa0076218
a0076dbc:  23 2a 01 ea  sethi  %hi(0xa807a800), %l1
a0076dc0:  b0 0d 20 ff  and  %l4, 0xff, %i0
a0076dc4:  1b 2a 01 ea  sethi  %hi(0xa807a800), %o5
a0076dc8:  82 5e 28 98  smul  %i0, 0x898, %g1
a0076dcc:  9a 13 61 f0  or  %o5, 0x1f0, %o5
a0076dd0:  9a 00 40 0d  add  %g1, %o5, %o5
a0076dd4:  c2 0b 60 2d  ldub  [ %o5 + 0x2d ], %g1
a0076dd8:  80 a0 60 01  cmp  %g1, 1
a0076ddc:  12 80 00 19  bne  0xa0076e40
a0076de0:  c0 2b 60 30  clrb  [ %o5 + 0x30 ]
a0076de4:  c2 0b 60 2e  ldub  [ %o5 + 0x2e ], %g1
a0076de8:  80 a0 60 01  cmp  %g1, 1
a0076dec:  12 80 00 16  bne  0xa0076e44
a0076df0:  82 06 00 18  add  %i0, %i0, %g1
a0076df4:  c2 0b 60 2f  ldub  [ %o5 + 0x2f ], %g1
a0076df8:  80 a0 60 01  cmp  %g1, 1
a0076dfc:  32 80 00 12  bne,a   0xa0076e44
a0076e00:  82 06 00 18  add  %i0, %i0, %g1
a0076e04:  7f ff fc 7e  call  0xa0075ffc
a0076e08:  90 10 00 18  mov  %i0, %o0
a0076e0c:  82 06 00 18  add  %i0, %i0, %g1
a0076e10:  82 00 40 18  add  %g1, %i0, %g1
a0076e14:  83 28 60 02  sll  %g1, 2, %g1
a0076e18:  10 80 00 0e  b  0xa0076e50
a0076e1c:  98 10 20 08  mov  8, %o4
a0076e20:  9a 04 00 10  add  %l0, %l0, %o5
a0076e24:  9a 03 40 10  add  %o5, %l0, %o5
a0076e28:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0076e2c:  9b 2b 60 02  sll  %o5, 2, %o5
a0076e30:  82 10 60 c4  or  %g1, 0xc4, %g1
a0076e34:  c0 20 40 0d  clr  [ %g1 + %o5 ]
a0076e38:  10 80 00 0a  b  0xa0076e60
a0076e3c:  b0 10 20 00  clr  %i0
a0076e40:  82 06 00 18  add  %i0, %i0, %g1
a0076e44:  82 00 40 18  add  %g1, %i0, %g1
a0076e48:  83 28 60 02  sll  %g1, 2, %g1
a0076e4c:  98 10 20 07  mov  7, %o4
a0076e50:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a0076e54:  9a 13 60 c4  or  %o5, 0xc4, %o5	! 0xa807ccc4
a0076e58:  d8 23 40 01  st  %o4, [ %o5 + %g1 ]
a0076e5c:  b0 10 20 01  mov  1, %i0
a0076e60:  81 c7 e0 08  ret
a0076e64:  81 e8 00 00  restore
