# leon2m FUN_a013d1b4 0xa013d1b4-0xa013d670 (1212 bytes)
a013d1b4:  9d e3 bf 98  save  %sp, -104, %sp
a013d1b8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013d1bc:  80 a6 20 00  cmp  %i0, 0
a013d1c0:  12 80 00 7f  bne  0xa013d3bc
a013d1c4:  23 2a 00 b8  sethi  %hi(0xa802e000), %l1
a013d1c8:  82 14 63 d0  or  %l1, 0x3d0, %g1	! 0xa802e3d0
a013d1cc:  da 08 60 03  ldub  [ %g1 + 3 ], %o5
a013d1d0:  80 a3 60 00  cmp  %o5, 0
a013d1d4:  02 80 00 7b  be  0xa013d3c0
a013d1d8:  aa 14 63 d0  or  %l1, 0x3d0, %l5
a013d1dc:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a013d1e0:  98 13 23 78  or  %o4, 0x378, %o4	! 0xa802e378
a013d1e4:  e4 13 20 0a  lduh  [ %o4 + 0xa ], %l2
a013d1e8:  e0 56 60 0c  ldsh  [ %i1 + 0xc ], %l0
a013d1ec:  d6 13 20 08  lduh  [ %o4 + 8 ], %o3
a013d1f0:  9e 5c 00 12  smul  %l0, %l2, %o7
a013d1f4:  9b 3b e0 1f  sra  %o7, 0x1f, %o5
a013d1f8:  81 83 60 00  mov  %o5, %y
a013d1fc:  01 00 00 00  nop
a013d200:  01 00 00 00  nop
a013d204:  01 00 00 00  nop
a013d208:  94 7b c0 0b  sdiv  %o7, %o3, %o2
a013d20c:  d4 36 60 0c  sth  %o2, [ %i1 + 0xc ]
a013d210:  da 13 20 0a  lduh  [ %o4 + 0xa ], %o5
a013d214:  d2 16 40 00  lduh  [ %i1 ], %o1
a013d218:  d0 13 20 08  lduh  [ %o4 + 8 ], %o0
a013d21c:  82 5a 40 0d  smul  %o1, %o5, %g1
a013d220:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a013d224:  81 83 60 00  mov  %o5, %y
a013d228:  01 00 00 00  nop
a013d22c:  01 00 00 00  nop
a013d230:  01 00 00 00  nop
a013d234:  ac 78 40 08  sdiv  %g1, %o0, %l6
a013d238:  ec 36 40 00  sth  %l6, [ %i1 ]
a013d23c:  ea 13 20 0a  lduh  [ %o4 + 0xa ], %l5
a013d240:  e8 16 60 08  lduh  [ %i1 + 8 ], %l4
a013d244:  e6 13 20 08  lduh  [ %o4 + 8 ], %l3
a013d248:  a4 5d 00 15  smul  %l4, %l5, %l2
a013d24c:  9b 3c a0 1f  sra  %l2, 0x1f, %o5
a013d250:  81 83 60 00  mov  %o5, %y
a013d254:  01 00 00 00  nop
a013d258:  01 00 00 00  nop
a013d25c:  01 00 00 00  nop
a013d260:  a0 7c 80 13  sdiv  %l2, %l3, %l0
a013d264:  e0 36 60 08  sth  %l0, [ %i1 + 8 ]
a013d268:  d6 16 60 04  lduh  [ %i1 + 4 ], %o3
a013d26c:  de 13 20 0a  lduh  [ %o4 + 0xa ], %o7
a013d270:  d4 13 20 08  lduh  [ %o4 + 8 ], %o2
a013d274:  92 5a c0 0f  smul  %o3, %o7, %o1
a013d278:  97 3a 60 1f  sra  %o1, 0x1f, %o3
a013d27c:  81 82 e0 00  mov  %o3, %y
a013d280:  01 00 00 00  nop
a013d284:  01 00 00 00  nop
a013d288:  01 00 00 00  nop
a013d28c:  90 7a 40 0a  sdiv  %o1, %o2, %o0
a013d290:  d0 36 60 04  sth  %o0, [ %i1 + 4 ]
a013d294:  a5 2e 20 04  sll  %i0, 4, %l2
a013d298:  94 24 80 18  sub  %l2, %i0, %o2
a013d29c:  29 2a 00 b7  sethi  %hi(0xa802dc00), %l4
a013d2a0:  a1 2a a0 03  sll  %o2, 3, %l0
a013d2a4:  9a 15 23 30  or  %l4, 0x330, %o5
a013d2a8:  92 04 00 0d  add  %l0, %o5, %o1
a013d2ac:  de 16 60 02  lduh  [ %i1 + 2 ], %o7
a013d2b0:  80 a6 20 00  cmp  %i0, 0
a013d2b4:  12 80 00 6a  bne  0xa013d45c
a013d2b8:  de 32 60 54  sth  %o7, [ %o1 + 0x54 ]
a013d2bc:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a013d2c0:  a6 14 20 1c  or  %l0, 0x1c, %l3	! 0xa802cc1c
a013d2c4:  c2 04 e0 28  ld  [ %l3 + 0x28 ], %g1
a013d2c8:  80 a0 60 00  cmp  %g1, 0
a013d2cc:  12 80 00 ab  bne  0xa013d578
a013d2d0:  d6 04 63 d0  ld  [ %l1 + 0x3d0 ], %o3
a013d2d4:  2d 01 00 00  sethi  %hi(0x4000000), %l6
a013d2d8:  aa 2a c0 16  andn  %o3, %l6, %l5
a013d2dc:  ea 24 63 d0  st  %l5, [ %l1 + 0x3d0 ]
a013d2e0:  98 14 20 1c  or  %l0, 0x1c, %o4
a013d2e4:  c2 03 20 24  ld  [ %o4 + 0x24 ], %g1
a013d2e8:  80 a0 60 00  cmp  %g1, 0
a013d2ec:  12 80 00 9f  bne  0xa013d568
a013d2f0:  d2 04 63 d0  ld  [ %l1 + 0x3d0 ], %o1
a013d2f4:  11 02 00 00  sethi  %hi(0x8000000), %o0
a013d2f8:  82 2a 40 08  andn  %o1, %o0, %g1
a013d2fc:  c2 24 63 d0  st  %g1, [ %l1 + 0x3d0 ]
a013d300:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a013d304:  de 0c 21 a7  ldub  [ %l0 + 0x1a7 ], %o7	! 0xa802e1a7
a013d308:  80 a3 e0 04  cmp  %o7, 4
a013d30c:  08 80 00 03  bleu  0xa013d318
a013d310:  82 10 20 00  clr  %g1
a013d314:  82 10 20 01  mov  1, %g1
a013d318:  80 a0 60 00  cmp  %g1, 0
a013d31c:  12 80 00 7a  bne  0xa013d504
a013d320:  96 15 23 30  or  %l4, 0x330, %o3
a013d324:  25 00 06 8c  sethi  %hi(0x1a3000), %l2
a013d328:  d4 14 a0 da  lduh  [ %l2 + 0xda ], %o2	! 0x1a30da
a013d32c:  da 12 e0 54  lduh  [ %o3 + 0x54 ], %o5
a013d330:  80 a3 40 0a  cmp  %o5, %o2
a013d334:  0a 80 00 74  bcs  0xa013d504
a013d338:  d0 05 23 30  ld  [ %l4 + 0x330 ], %o0
a013d33c:  80 8a 20 01  btst  1, %o0
a013d340:  12 80 00 0d  bne  0xa013d374
a013d344:  2d 2a 00 b8  sethi  %hi(0xa802e000), %l6
a013d348:  de 02 e0 40  ld  [ %o3 + 0x40 ], %o7
a013d34c:  93 33 e0 1e  srl  %o7, 0x1e, %o1
a013d350:  80 8a 60 01  btst  1, %o1
a013d354:  12 80 00 09  bne  0xa013d378
a013d358:  aa 15 a3 78  or  %l6, 0x378, %l5
a013d35c:  d4 04 63 d0  ld  [ %l1 + 0x3d0 ], %o2
a013d360:  21 01 00 00  sethi  %hi(0x4000000), %l0
a013d364:  80 8a 80 10  btst  %o2, %l0
a013d368:  22 80 00 a3  be,a   0xa013d5f4
a013d36c:  e4 16 60 04  lduh  [ %i1 + 4 ], %l2
a013d370:  2d 2a 00 b8  sethi  %hi(0xa802e000), %l6
a013d374:  aa 15 a3 78  or  %l6, 0x378, %l5	! 0xa802e378
a013d378:  e6 15 60 26  lduh  [ %l5 + 0x26 ], %l3
a013d37c:  e4 15 60 32  lduh  [ %l5 + 0x32 ], %l2
a013d380:  da 15 60 28  lduh  [ %l5 + 0x28 ], %o5
a013d384:  e2 15 60 30  lduh  [ %l5 + 0x30 ], %l1
a013d388:  aa 04 40 12  add  %l1, %l2, %l5
a013d38c:  ac 04 c0 0d  add  %l3, %o5, %l6
a013d390:  e4 16 60 04  lduh  [ %i1 + 4 ], %l2
a013d394:  e2 16 60 06  lduh  [ %i1 + 6 ], %l1
a013d398:  e6 16 40 00  lduh  [ %i1 ], %l3
a013d39c:  e0 16 60 02  lduh  [ %i1 + 2 ], %l0
a013d3a0:  9e 10 20 00  clr  %o7
a013d3a4:  90 10 20 00  clr  %o0
a013d3a8:  d6 16 60 0e  lduh  [ %i1 + 0xe ], %o3
a013d3ac:  d8 16 60 0c  lduh  [ %i1 + 0xc ], %o4
a013d3b0:  92 03 00 16  add  %o4, %l6, %o1
a013d3b4:  10 80 00 94  b  0xa013d604
a013d3b8:  94 02 c0 15  add  %o3, %l5, %o2
a013d3bc:  aa 14 63 d0  or  %l1, 0x3d0, %l5
a013d3c0:  e8 05 60 04  ld  [ %l5 + 4 ], %l4
a013d3c4:  27 3c 00 00  sethi  %hi(0xf0000000), %l3
a013d3c8:  80 8d 00 13  btst  %l4, %l3
a013d3cc:  02 bf ff b3  be  0xa013d298
a013d3d0:  a5 2e 20 04  sll  %i0, 4, %l2
a013d3d4:  80 a6 20 00  cmp  %i0, 0
a013d3d8:  02 bf ff b1  be  0xa013d29c
a013d3dc:  94 24 80 18  sub  %l2, %i0, %o2
a013d3e0:  d0 16 40 00  lduh  [ %i1 ], %o0
a013d3e4:  c2 16 60 04  lduh  [ %i1 + 4 ], %g1
a013d3e8:  98 02 20 3f  add  %o0, 0x3f, %o4
a013d3ec:  96 00 60 3f  add  %g1, 0x3f, %o3
a013d3f0:  a1 3b 20 06  sra  %o4, 6, %l0
a013d3f4:  9f 3a e0 06  sra  %o3, 6, %o7
a013d3f8:  e4 16 60 08  lduh  [ %i1 + 8 ], %l2
a013d3fc:  ad 2b e0 16  sll  %o7, 0x16, %l6
a013d400:  ab 2c 20 16  sll  %l0, 0x16, %l5
a013d404:  94 04 a0 3f  add  %l2, 0x3f, %o2
a013d408:  a7 35 a0 10  srl  %l6, 0x10, %l3
a013d40c:  a9 35 60 10  srl  %l5, 0x10, %l4
a013d410:  9a 24 c0 14  sub  %l3, %l4, %o5
a013d414:  90 0a bf c0  and  %o2, -64, %o0
a013d418:  a5 2e 20 04  sll  %i0, 4, %l2
a013d41c:  93 2c 20 06  sll  %l0, 6, %o1
a013d420:  ad 3b 60 01  sra  %o5, 1, %l6
a013d424:  94 24 80 18  sub  %l2, %i0, %o2
a013d428:  29 2a 00 b7  sethi  %hi(0xa802dc00), %l4
a013d42c:  83 2b e0 06  sll  %o7, 6, %g1
a013d430:  d2 36 40 00  sth  %o1, [ %i1 ]
a013d434:  a1 2a a0 03  sll  %o2, 3, %l0
a013d438:  9a 15 23 30  or  %l4, 0x330, %o5
a013d43c:  d0 36 60 08  sth  %o0, [ %i1 + 8 ]
a013d440:  c2 36 60 04  sth  %g1, [ %i1 + 4 ]
a013d444:  ec 36 60 0c  sth  %l6, [ %i1 + 0xc ]
a013d448:  92 04 00 0d  add  %l0, %o5, %o1
a013d44c:  de 16 60 02  lduh  [ %i1 + 2 ], %o7
a013d450:  80 a6 20 00  cmp  %i0, 0
a013d454:  02 bf ff 9a  be  0xa013d2bc
a013d458:  de 32 60 54  sth  %o7, [ %o1 + 0x54 ]
a013d45c:  80 a6 20 03  cmp  %i0, 3
a013d460:  02 80 00 4a  be  0xa013d588
a013d464:  d0 04 63 d0  ld  [ %l1 + 0x3d0 ], %o0
a013d468:  d2 16 40 00  lduh  [ %i1 ], %o1
a013d46c:  de 16 60 04  lduh  [ %i1 + 4 ], %o7
a013d470:  80 a3 c0 09  cmp  %o7, %o1
a013d474:  1a 80 00 10  bcc  0xa013d4b4
a013d478:  98 10 00 09  mov  %o1, %o4
a013d47c:  e0 16 60 06  lduh  [ %i1 + 6 ], %l0
a013d480:  c2 16 60 02  lduh  [ %i1 + 2 ], %g1
a013d484:  80 a4 00 01  cmp  %l0, %g1
a013d488:  3a 80 00 0d  bcc,a   0xa013d4bc
a013d48c:  e6 16 60 0c  lduh  [ %i1 + 0xc ], %l3
a013d490:  a4 10 00 09  mov  %o1, %l2
a013d494:  a2 10 00 01  mov  %g1, %l1
a013d498:  a6 10 00 09  mov  %o1, %l3
a013d49c:  a0 10 00 01  mov  %g1, %l0
a013d4a0:  ac 10 20 18  mov  0x18, %l6
a013d4a4:  aa 10 20 03  mov  3, %l5
a013d4a8:  de 16 60 08  lduh  [ %i1 + 8 ], %o7
a013d4ac:  10 80 00 11  b  0xa013d4f0
a013d4b0:  d0 16 60 0a  lduh  [ %i1 + 0xa ], %o0
a013d4b4:  c2 16 60 02  lduh  [ %i1 + 2 ], %g1
a013d4b8:  e6 16 60 0c  lduh  [ %i1 + 0xc ], %l3
a013d4bc:  ea 16 60 08  lduh  [ %i1 + 8 ], %l5
a013d4c0:  d4 16 60 0e  lduh  [ %i1 + 0xe ], %o2
a013d4c4:  9e 05 40 13  add  %l5, %l3, %o7
a013d4c8:  da 16 60 0a  lduh  [ %i1 + 0xa ], %o5
a013d4cc:  a4 10 00 0c  mov  %o4, %l2
a013d4d0:  a2 10 00 01  mov  %g1, %l1
a013d4d4:  90 03 40 0a  add  %o5, %o2, %o0
a013d4d8:  c0 36 60 0c  clrh  [ %i1 + 0xc ]
a013d4dc:  c0 36 60 0e  clrh  [ %i1 + 0xe ]
a013d4e0:  a6 10 00 0c  mov  %o4, %l3
a013d4e4:  a0 10 00 01  mov  %g1, %l0
a013d4e8:  ac 10 20 18  mov  0x18, %l6
a013d4ec:  aa 10 20 03  mov  3, %l5
a013d4f0:  d6 16 60 0e  lduh  [ %i1 + 0xe ], %o3
a013d4f4:  d8 16 60 0c  lduh  [ %i1 + 0xc ], %o4
a013d4f8:  92 03 20 18  add  %o4, 0x18, %o1
a013d4fc:  10 80 00 42  b  0xa013d604
a013d500:  94 02 e0 03  add  %o3, 3, %o2
a013d504:  e2 16 40 00  lduh  [ %i1 ], %l1
a013d508:  e6 16 60 04  lduh  [ %i1 + 4 ], %l3
a013d50c:  80 a4 c0 11  cmp  %l3, %l1
a013d510:  1a 80 00 2f  bcc  0xa013d5cc
a013d514:  98 10 00 11  mov  %l1, %o4
a013d518:  ea 16 60 06  lduh  [ %i1 + 6 ], %l5
a013d51c:  c2 16 60 02  lduh  [ %i1 + 2 ], %g1
a013d520:  80 a5 40 01  cmp  %l5, %g1
a013d524:  2a 80 00 2c  bcs,a   0xa013d5d4
a013d528:  a4 10 00 11  mov  %l1, %l2
a013d52c:  ec 16 60 0e  lduh  [ %i1 + 0xe ], %l6
a013d530:  a4 10 00 0c  mov  %o4, %l2
a013d534:  a2 10 00 01  mov  %g1, %l1
a013d538:  d6 16 60 0a  lduh  [ %i1 + 0xa ], %o3
a013d53c:  d8 16 60 0c  lduh  [ %i1 + 0xc ], %o4
a013d540:  c2 16 60 08  lduh  [ %i1 + 8 ], %g1
a013d544:  90 02 c0 16  add  %o3, %l6, %o0
a013d548:  9e 00 40 0c  add  %g1, %o4, %o7
a013d54c:  c0 36 60 0c  clrh  [ %i1 + 0xc ]
a013d550:  c0 36 60 0e  clrh  [ %i1 + 0xe ]
a013d554:  a6 10 00 12  mov  %l2, %l3
a013d558:  a0 10 00 11  mov  %l1, %l0
a013d55c:  ac 10 20 18  mov  0x18, %l6
a013d560:  10 bf ff 92  b  0xa013d3a8
a013d564:  aa 10 20 03  mov  3, %l5
a013d568:  9f c0 40 00  call  %g1
a013d56c:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a013d570:  10 bf ff 66  b  0xa013d308
a013d574:  de 0c 21 a7  ldub  [ %l0 + 0x1a7 ], %o7	! 0xa802e1a7
a013d578:  9f c0 40 00  call  %g1
a013d57c:  01 00 00 00  nop
a013d580:  10 bf ff 59  b  0xa013d2e4
a013d584:  98 14 20 1c  or  %l0, 0x1c, %o4
a013d588:  03 00 08 00  sethi  %hi(0x200000), %g1
a013d58c:  80 8a 00 01  btst  %o0, %g1
a013d590:  22 bf ff b7  be,a   0xa013d46c
a013d594:  d2 16 40 00  lduh  [ %i1 ], %o1
a013d598:  c0 36 60 0e  clrh  [ %i1 + 0xe ]
a013d59c:  c0 36 60 0c  clrh  [ %i1 + 0xc ]
a013d5a0:  a4 10 20 80  mov  0x80, %l2
a013d5a4:  a2 10 20 a0  mov  0xa0, %l1
a013d5a8:  a6 10 20 80  mov  0x80, %l3
a013d5ac:  a0 10 20 a0  mov  0xa0, %l0
a013d5b0:  ac 10 20 18  mov  0x18, %l6
a013d5b4:  aa 10 20 02  mov  2, %l5
a013d5b8:  9e 10 20 00  clr  %o7
a013d5bc:  90 10 20 00  clr  %o0
a013d5c0:  92 10 20 18  mov  0x18, %o1
a013d5c4:  10 80 00 10  b  0xa013d604
a013d5c8:  94 10 20 02  mov  2, %o2
a013d5cc:  10 bf ff d8  b  0xa013d52c
a013d5d0:  c2 16 60 02  lduh  [ %i1 + 2 ], %g1
a013d5d4:  a2 10 00 01  mov  %g1, %l1
a013d5d8:  a6 10 00 0c  mov  %o4, %l3
a013d5dc:  a0 10 00 01  mov  %g1, %l0
a013d5e0:  ac 10 20 18  mov  0x18, %l6
a013d5e4:  aa 10 20 03  mov  3, %l5
a013d5e8:  de 16 60 08  lduh  [ %i1 + 8 ], %o7
a013d5ec:  10 bf ff 6f  b  0xa013d3a8
a013d5f0:  d0 16 60 0a  lduh  [ %i1 + 0xa ], %o0
a013d5f4:  e2 16 60 06  lduh  [ %i1 + 6 ], %l1
a013d5f8:  e6 16 40 00  lduh  [ %i1 ], %l3
a013d5fc:  10 bf ff f9  b  0xa013d5e0
a013d600:  e0 16 60 02  lduh  [ %i1 + 2 ], %l0
a013d604:  b3 2a a0 10  sll  %o2, 0x10, %i1
a013d608:  9b 36 60 10  srl  %i1, 0x10, %o5
a013d60c:  83 2e 20 04  sll  %i0, 4, %g1
a013d610:  99 2a 60 10  sll  %o1, 0x10, %o4
a013d614:  97 3b 20 10  sra  %o4, 0x10, %o3
a013d618:  b2 20 40 18  sub  %g1, %i0, %i1
a013d61c:  b0 38 00 0b  xnor  %g0, %o3, %i0
a013d620:  80 a3 68 00  cmp  %o5, 0x800
a013d624:  99 3e 20 1f  sra  %i0, 0x1f, %o4
a013d628:  9a 15 23 30  or  %l4, 0x330, %o5
a013d62c:  83 2e 60 03  sll  %i1, 3, %g1
a013d630:  96 60 20 00  subx  %g0, 0, %o3
a013d634:  b0 00 40 0d  add  %g1, %o5, %i0
a013d638:  a8 0b 00 09  and  %o4, %o1, %l4
a013d63c:  b2 0a c0 0a  and  %o3, %o2, %i1
a013d640:  d0 36 20 5c  sth  %o0, [ %i0 + 0x5c ]
a013d644:  e4 36 20 4a  sth  %l2, [ %i0 + 0x4a ]
a013d648:  e2 36 20 52  sth  %l1, [ %i0 + 0x52 ]
a013d64c:  ec 36 20 4e  sth  %l6, [ %i0 + 0x4e ]
a013d650:  ea 36 20 58  sth  %l5, [ %i0 + 0x58 ]
a013d654:  e8 36 20 50  sth  %l4, [ %i0 + 0x50 ]
a013d658:  f2 36 20 56  sth  %i1, [ %i0 + 0x56 ]
a013d65c:  e6 36 20 4c  sth  %l3, [ %i0 + 0x4c ]
a013d660:  e0 36 20 54  sth  %l0, [ %i0 + 0x54 ]
a013d664:  de 36 20 5a  sth  %o7, [ %i0 + 0x5a ]
a013d668:  81 c7 e0 08  ret
a013d66c:  81 e8 00 00  restore
