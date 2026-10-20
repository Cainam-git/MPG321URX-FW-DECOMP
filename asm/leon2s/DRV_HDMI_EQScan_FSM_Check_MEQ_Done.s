# leon2s DRV_HDMI_EQScan_FSM_Check_MEQ_Done 0xa007d21c-0xa007d688 (1132 bytes)
a007d21c:  9d e3 bf 88  save  %sp, -120, %sp
a007d220:  2f 2a 01 ea  sethi  %hi(0xa807a800), %l7
a007d224:  90 0e 20 ff  and  %i0, 0xff, %o0
a007d228:  9a 15 e1 f0  or  %l7, 0x1f0, %o5
a007d22c:  82 5a 28 98  smul  %o0, 0x898, %g1
a007d230:  a0 00 40 0d  add  %g1, %o5, %l0
a007d234:  c2 0c 20 30  ldub  [ %l0 + 0x30 ], %g1
a007d238:  98 10 20 00  clr  %o4
a007d23c:  9a 10 20 00  clr  %o5
a007d240:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a007d244:  c0 27 bf f0  clr  [ %fp + -16 ]
a007d248:  80 a0 60 05  cmp  %g1, 5
a007d24c:  18 80 00 0b  bgu  0xa007d278
a007d250:  a8 10 20 00  clr  %l4
a007d254:  80 a0 60 00  cmp  %g1, 0
a007d258:  32 80 00 05  bne,a   0xa007d26c
a007d25c:  c2 0c 20 30  ldub  [ %l0 + 0x30 ], %g1
a007d260:  7f ff de f6  call  0xa0074e38
a007d264:  01 00 00 00  nop
a007d268:  c2 0c 20 30  ldub  [ %l0 + 0x30 ], %g1
a007d26c:  82 00 60 01  inc  %g1
a007d270:  10 80 00 ec  b  0xa007d620
a007d274:  c2 2c 20 30  stb  %g1, [ %l0 + 0x30 ]
a007d278:  a4 0e 20 ff  and  %i0, 0xff, %l2
a007d27c:  2b 00 00 07  sethi  %hi(0x1c00), %l5
a007d280:  a6 0d 20 ff  and  %l4, 0xff, %l3
a007d284:  92 15 62 a0  or  %l5, 0x2a0, %o1
a007d288:  90 10 00 12  mov  %l2, %o0
a007d28c:  80 a4 e0 00  cmp  %l3, 0
a007d290:  12 80 00 0f  bne  0xa007d2cc
a007d294:  a2 10 00 12  mov  %l2, %l1
a007d298:  40 00 a8 1f  call  0xa00a7314
a007d29c:  01 00 00 00  nop
a007d2a0:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a007d2a4:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00
a007d2a8:  a0 0a 00 01  and  %o0, %g1, %l0
a007d2ac:  90 10 00 12  mov  %l2, %o0
a007d2b0:  40 00 a8 19  call  0xa00a7314
a007d2b4:  92 15 62 a0  or  %l5, 0x2a0, %o1
a007d2b8:  91 32 20 10  srl  %o0, 0x10, %o0
a007d2bc:  90 0a 20 ff  and  %o0, 0xff, %o0
a007d2c0:  a0 14 00 08  or  %l0, %o0, %l0
a007d2c4:  10 80 00 21  b  0xa007d348
a007d2c8:  e0 27 bf e8  st  %l0, [ %fp + -24 ]
a007d2cc:  2d 00 00 07  sethi  %hi(0x1c00), %l6
a007d2d0:  9b 2c e0 02  sll  %l3, 2, %o5
a007d2d4:  82 07 bf f8  add  %fp, -8, %g1
a007d2d8:  a4 03 40 01  add  %o5, %g1, %l2
a007d2dc:  80 a4 e0 01  cmp  %l3, 1
a007d2e0:  12 80 00 0e  bne  0xa007d318
a007d2e4:  92 15 a2 a4  or  %l6, 0x2a4, %o1
a007d2e8:  40 00 a8 0b  call  0xa00a7314
a007d2ec:  92 15 a2 a0  or  %l6, 0x2a0, %o1
a007d2f0:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a007d2f4:  a0 0a 00 01  and  %o0, %g1, %l0
a007d2f8:  90 10 00 11  mov  %l1, %o0
a007d2fc:  40 00 a8 06  call  0xa00a7314
a007d300:  92 15 a2 a4  or  %l6, 0x2a4, %o1
a007d304:  a1 34 20 10  srl  %l0, 0x10, %l0
a007d308:  90 0a 20 ff  and  %o0, 0xff, %o0
a007d30c:  a0 14 00 08  or  %l0, %o0, %l0
a007d310:  10 80 00 0e  b  0xa007d348
a007d314:  e0 27 bf ec  st  %l0, [ %fp + -20 ]
a007d318:  40 00 a7 ff  call  0xa00a7314
a007d31c:  01 00 00 00  nop
a007d320:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a007d324:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00
a007d328:  a0 0a 00 01  and  %o0, %g1, %l0
a007d32c:  92 15 a2 a4  or  %l6, 0x2a4, %o1
a007d330:  40 00 a7 f9  call  0xa00a7314
a007d334:  90 10 00 11  mov  %l1, %o0
a007d338:  91 32 20 10  srl  %o0, 0x10, %o0
a007d33c:  90 0a 20 ff  and  %o0, 0xff, %o0
a007d340:  a0 14 00 08  or  %l0, %o0, %l0
a007d344:  e0 24 bf f0  st  %l0, [ %l2 + -16 ]
a007d348:  83 2c e0 02  sll  %l3, 2, %g1
a007d34c:  9a 07 80 01  add  %fp, %g1, %o5
a007d350:  25 2a 01 e1  sethi  %hi(0xa8078400), %l2
a007d354:  92 06 20 41  add  %i0, 0x41, %o1
a007d358:  93 2a 60 18  sll  %o1, 0x18, %o1
a007d35c:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1
a007d360:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007d364:  a8 05 20 01  inc  %l4
a007d368:  80 88 60 02  btst  2, %g1
a007d36c:  90 12 23 a8  or  %o0, 0x3a8, %o0
a007d370:  93 3a 60 18  sra  %o1, 0x18, %o1
a007d374:  02 80 00 06  be  0xa007d38c
a007d378:  94 10 00 13  mov  %l3, %o2
a007d37c:  c2 03 7f e8  ld  [ %o5 + -24 ], %g1
a007d380:  17 3f ff e0  sethi  %hi(0xffff8000), %o3
a007d384:  7f ff d7 30  call  0xa0073044
a007d388:  96 28 40 0b  andn  %g1, %o3, %o3
a007d38c:  82 0d 20 ff  and  %l4, 0xff, %g1
a007d390:  80 a0 60 02  cmp  %g1, 2
a007d394:  28 bf ff ba  bleu,a   0xa007d27c
a007d398:  a4 0e 20 ff  and  %i0, 0xff, %l2
a007d39c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a007d3a0:  82 04 00 10  add  %l0, %l0, %g1
a007d3a4:  82 00 40 10  add  %g1, %l0, %g1
a007d3a8:  27 2a 01 f3  sethi  %hi(0xa807cc00), %l3
a007d3ac:  83 28 60 02  sll  %g1, 2, %g1
a007d3b0:  9a 14 e0 c4  or  %l3, 0xc4, %o5
a007d3b4:  82 00 40 0d  add  %g1, %o5, %g1
a007d3b8:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a007d3bc:  80 a0 60 00  cmp  %g1, 0
a007d3c0:  12 80 00 a5  bne  0xa007d654
a007d3c4:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1
a007d3c8:  80 88 60 02  btst  2, %g1
a007d3cc:  02 80 00 0b  be  0xa007d3f8
a007d3d0:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a007d3d4:  94 06 20 41  add  %i0, 0x41, %o2
a007d3d8:  95 2a a0 18  sll  %o2, 0x18, %o2
a007d3dc:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007d3e0:  13 28 02 cf  sethi  %hi(0xa00b3c00), %o1
a007d3e4:  90 12 23 d0  or  %o0, 0x3d0, %o0
a007d3e8:  92 12 62 b0  or  %o1, 0x2b0, %o1
a007d3ec:  7f ff d7 16  call  0xa0073044
a007d3f0:  95 3a a0 18  sra  %o2, 0x18, %o2
a007d3f4:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a007d3f8:  9a 5c 28 98  smul  %l0, 0x898, %o5
a007d3fc:  82 10 61 f0  or  %g1, 0x1f0, %g1
a007d400:  98 03 40 01  add  %o5, %g1, %o4
a007d404:  a8 10 20 00  clr  %l4
a007d408:  a2 10 20 01  mov  1, %l1
a007d40c:  82 0d 20 ff  and  %l4, 0xff, %g1
a007d410:  a8 05 20 01  inc  %l4
a007d414:  82 03 00 01  add  %o4, %g1, %g1
a007d418:  9a 0d 20 ff  and  %l4, 0xff, %o5
a007d41c:  80 a3 60 02  cmp  %o5, 2
a007d420:  08 bf ff fb  bleu  0xa007d40c
a007d424:  e2 28 60 31  stb  %l1, [ %g1 + 0x31 ]
a007d428:  7f ff de 84  call  0xa0074e38
a007d42c:  90 10 00 10  mov  %l0, %o0
a007d430:  7f ff ff 44  call  0xa007d140
a007d434:  90 10 00 10  mov  %l0, %o0
a007d438:  80 8a 20 ff  btst  0xff, %o0
a007d43c:  12 80 00 53  bne  0xa007d588
a007d440:  03 00 00 1f  sethi  %hi(0x7c00), %g1
a007d444:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007d448:  90 12 23 f0  or  %o0, 0x3f0, %o0	! 0xa0067bf0
a007d44c:  7f ff d6 fe  call  0xa0073044
a007d450:  92 10 20 63  mov  0x63, %o1
a007d454:  1b 00 00 1f  sethi  %hi(0x7c00), %o5
a007d458:  98 13 63 ff  or  %o5, 0x3ff, %o4	! 0x7fff
a007d45c:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a007d460:  82 08 40 0c  and  %g1, %o4, %g1
a007d464:  9a 13 63 fe  or  %o5, 0x3fe, %o5
a007d468:  80 a0 40 0d  cmp  %g1, %o5
a007d46c:  08 80 00 0b  bleu  0xa007d498
a007d470:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a007d474:  82 08 40 0c  and  %g1, %o4, %g1
a007d478:  80 a0 40 0d  cmp  %g1, %o5
a007d47c:  28 80 00 08  bleu,a   0xa007d49c
a007d480:  23 00 00 07  sethi  %hi(0x1c00), %l1
a007d484:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a007d488:  82 08 40 0c  and  %g1, %o4, %g1
a007d48c:  80 a0 40 0d  cmp  %g1, %o5
a007d490:  38 80 00 25  bgu,a   0xa007d524
a007d494:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007d498:  23 00 00 07  sethi  %hi(0x1c00), %l1
a007d49c:  90 10 20 10  mov  0x10, %o0
a007d4a0:  92 10 00 10  mov  %l0, %o1
a007d4a4:  40 00 a7 f1  call  0xa00a7468
a007d4a8:  94 14 62 94  or  %l1, 0x294, %o2
a007d4ac:  80 a2 20 01  cmp  %o0, 1
a007d4b0:  32 80 00 1d  bne,a   0xa007d524
a007d4b4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007d4b8:  90 10 20 11  mov  0x11, %o0
a007d4bc:  92 10 00 10  mov  %l0, %o1
a007d4c0:  40 00 a7 ea  call  0xa00a7468
a007d4c4:  94 14 62 94  or  %l1, 0x294, %o2
a007d4c8:  80 a2 20 01  cmp  %o0, 1
a007d4cc:  32 80 00 16  bne,a   0xa007d524
a007d4d0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007d4d4:  94 14 62 94  or  %l1, 0x294, %o2
a007d4d8:  90 10 20 12  mov  0x12, %o0
a007d4dc:  40 00 a7 e3  call  0xa00a7468
a007d4e0:  92 10 00 10  mov  %l0, %o1
a007d4e4:  80 a2 20 01  cmp  %o0, 1
a007d4e8:  32 80 00 0f  bne,a   0xa007d524
a007d4ec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007d4f0:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a007d4f4:  da 04 a2 34  ld  [ %l2 + 0x234 ], %o5
a007d4f8:  82 10 61 98  or  %g1, 0x198, %g1
a007d4fc:  80 8b 60 02  btst  2, %o5
a007d500:  02 80 00 08  be  0xa007d520
a007d504:  c0 28 40 10  clrb  [ %g1 + %l0 ]
a007d508:  92 06 20 41  add  %i0, 0x41, %o1
a007d50c:  93 2a 60 18  sll  %o1, 0x18, %o1
a007d510:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007d514:  90 12 20 18  or  %o0, 0x18, %o0	! 0xa0067c18
a007d518:  7f ff d6 cb  call  0xa0073044
a007d51c:  93 3a 60 18  sra  %o1, 0x18, %o1
a007d520:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007d524:  7f ff df 16  call  0xa007517c
a007d528:  90 10 00 18  mov  %i0, %o0
a007d52c:  80 8a 20 ff  btst  0xff, %o0
a007d530:  02 80 00 06  be  0xa007d548
a007d534:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007d538:  90 10 00 18  mov  %i0, %o0
a007d53c:  7f ff ea 4b  call  0xa0077e68
a007d540:  92 10 20 00  clr  %o1
a007d544:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007d548:  a0 10 61 90  or  %g1, 0x190, %l0	! 0xa8078990
a007d54c:  da 0c 00 18  ldub  [ %l0 + %i0 ], %o5
a007d550:  9a 03 60 01  inc  %o5
a007d554:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007d558:  98 0b 60 ff  and  %o5, 0xff, %o4
a007d55c:  82 10 61 98  or  %g1, 0x198, %g1
a007d560:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a007d564:  80 a3 20 0a  cmp  %o4, 0xa
a007d568:  08 80 00 05  bleu  0xa007d57c
a007d56c:  da 2c 00 18  stb  %o5, [ %l0 + %i0 ]
a007d570:  7f ff ea 43  call  0xa0077e7c
a007d574:  90 10 00 18  mov  %i0, %o0
a007d578:  c0 2c 00 18  clrb  [ %l0 + %i0 ]
a007d57c:  82 06 00 18  add  %i0, %i0, %g1
a007d580:  10 80 00 25  b  0xa007d614
a007d584:  82 00 40 18  add  %g1, %i0, %g1
a007d588:  9a 10 63 ff  or  %g1, 0x3ff, %o5
a007d58c:  d4 07 bf e8  ld  [ %fp + -24 ], %o2
a007d590:  82 0a 80 0d  and  %o2, %o5, %g1
a007d594:  80 a0 40 0d  cmp  %g1, %o5
a007d598:  02 80 00 13  be  0xa007d5e4
a007d59c:  d6 07 bf ec  ld  [ %fp + -20 ], %o3
a007d5a0:  82 0a c0 0d  and  %o3, %o5, %g1
a007d5a4:  80 a0 40 0d  cmp  %g1, %o5
a007d5a8:  02 80 00 0f  be  0xa007d5e4
a007d5ac:  d8 07 bf f0  ld  [ %fp + -16 ], %o4
a007d5b0:  82 0b 00 0d  and  %o4, %o5, %g1
a007d5b4:  80 a0 40 0d  cmp  %g1, %o5
a007d5b8:  02 80 00 0b  be  0xa007d5e4
a007d5bc:  03 00 00 20  sethi  %hi(0x8000), %g1
a007d5c0:  80 8a 80 01  btst  %o2, %g1
a007d5c4:  22 80 00 09  be,a   0xa007d5e8
a007d5c8:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1
a007d5cc:  80 8a c0 01  btst  %o3, %g1
a007d5d0:  22 80 00 06  be,a   0xa007d5e8
a007d5d4:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1
a007d5d8:  80 8b 00 01  btst  %o4, %g1
a007d5dc:  12 80 00 13  bne  0xa007d628
a007d5e0:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a007d5e4:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1
a007d5e8:  80 88 60 02  btst  2, %g1
a007d5ec:  02 80 00 09  be  0xa007d610
a007d5f0:  82 04 00 10  add  %l0, %l0, %g1
a007d5f4:  92 06 20 41  add  %i0, 0x41, %o1
a007d5f8:  93 2a 60 18  sll  %o1, 0x18, %o1
a007d5fc:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007d600:  90 12 20 58  or  %o0, 0x58, %o0	! 0xa0067c58
a007d604:  7f ff d6 90  call  0xa0073044
a007d608:  93 3a 60 18  sra  %o1, 0x18, %o1
a007d60c:  82 04 00 10  add  %l0, %l0, %g1
a007d610:  82 00 40 10  add  %g1, %l0, %g1
a007d614:  9a 14 e0 c4  or  %l3, 0xc4, %o5
a007d618:  83 28 60 02  sll  %g1, 2, %g1
a007d61c:  c0 23 40 01  clr  [ %o5 + %g1 ]
a007d620:  10 80 00 18  b  0xa007d680
a007d624:  b0 10 20 00  clr  %i0
a007d628:  c2 08 61 9f  ldub  [ %g1 + 0x19f ], %g1
a007d62c:  80 a0 60 00  cmp  %g1, 0
a007d630:  02 80 00 05  be  0xa007d644
a007d634:  9a 15 e1 f0  or  %l7, 0x1f0, %o5
a007d638:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007d63c:  82 10 61 98  or  %g1, 0x198, %g1	! 0xa8078998
a007d640:  e2 28 40 10  stb  %l1, [ %g1 + %l0 ]
a007d644:  82 5c 28 98  smul  %l0, 0x898, %g1
a007d648:  82 00 40 0d  add  %g1, %o5, %g1
a007d64c:  10 80 00 05  b  0xa007d660
a007d650:  c0 28 68 96  clrb  [ %g1 + 0x896 ]
a007d654:  11 28 01 9f  sethi  %hi(0xa0067c00), %o0
a007d658:  7f ff d7 9b  call  0xa00734c4
a007d65c:  90 12 20 88  or  %o0, 0x88, %o0	! 0xa0067c88
a007d660:  9a 0e 20 ff  and  %i0, 0xff, %o5
a007d664:  82 03 40 0d  add  %o5, %o5, %g1
a007d668:  82 00 40 0d  add  %g1, %o5, %g1
a007d66c:  98 14 e0 c4  or  %l3, 0xc4, %o4
a007d670:  83 28 60 02  sll  %g1, 2, %g1
a007d674:  9a 10 20 10  mov  0x10, %o5
a007d678:  da 23 00 01  st  %o5, [ %o4 + %g1 ]
a007d67c:  b0 10 20 01  mov  1, %i0
a007d680:  81 c7 e0 08  ret
a007d684:  81 e8 00 00  restore
