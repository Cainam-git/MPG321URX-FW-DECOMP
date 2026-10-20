# leon2s FUN_a009d2f8 0xa009d2f8-0xa009d5cc (724 bytes)
a009d2f8:  9d e3 bf 98  save  %sp, -104, %sp
a009d2fc:  a0 0e 20 ff  and  %i0, 0xff, %l0
a009d300:  7f ff eb 6a  call  0xa00980a8
a009d304:  90 10 00 10  mov  %l0, %o0
a009d308:  23 2a 01 f5  sethi  %hi(0xa807d400), %l1
a009d30c:  82 14 63 e0  or  %l1, 0x3e0, %g1	! 0xa807d7e0
a009d310:  9a 5c 21 90  smul  %l0, 0x190, %o5
a009d314:  9a 03 40 01  add  %o5, %g1, %o5
a009d318:  c2 0b 60 18  ldub  [ %o5 + 0x18 ], %g1
a009d31c:  80 a0 60 01  cmp  %g1, 1
a009d320:  12 80 00 2b  bne  0xa009d3cc
a009d324:  96 0e 20 ff  and  %i0, 0xff, %o3
a009d328:  40 00 09 e9  call  0xa009facc
a009d32c:  90 10 00 10  mov  %l0, %o0
a009d330:  80 a2 20 82  cmp  %o0, 0x82
a009d334:  02 80 00 0c  be  0xa009d364
a009d338:  9a 04 00 10  add  %l0, %l0, %o5
a009d33c:  9a 03 40 10  add  %o5, %l0, %o5
a009d340:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009d344:  82 10 62 50  or  %g1, 0x250, %g1	! 0xa807d650
a009d348:  9b 2b 60 03  sll  %o5, 3, %o5
a009d34c:  9a 03 40 01  add  %o5, %g1, %o5
a009d350:  c2 0b 60 09  ldub  [ %o5 + 9 ], %g1
a009d354:  80 a0 60 00  cmp  %g1, 0
a009d358:  02 80 00 03  be  0xa009d364
a009d35c:  82 00 7f ff  add  %g1, -1, %g1
a009d360:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a009d364:  40 00 0c 19  call  0xa00a03c8
a009d368:  90 10 00 10  mov  %l0, %o0
a009d36c:  9a 14 63 e0  or  %l1, 0x3e0, %o5
a009d370:  82 5c 21 90  smul  %l0, 0x190, %g1
a009d374:  82 00 40 0d  add  %g1, %o5, %g1
a009d378:  90 0a 20 ff  and  %o0, 0xff, %o0
a009d37c:  c2 08 60 2d  ldub  [ %g1 + 0x2d ], %g1
a009d380:  80 a2 00 01  cmp  %o0, %g1
a009d384:  02 80 00 0f  be  0xa009d3c0
a009d388:  92 06 20 41  add  %i0, 0x41, %o1
a009d38c:  93 2a 60 18  sll  %o1, 0x18, %o1
a009d390:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009d394:  90 12 21 a8  or  %o0, 0x1a8, %o0	! 0xa006a9a8
a009d398:  7f ff 57 2b  call  0xa0073044
a009d39c:  93 3a 60 18  sra  %o1, 0x18, %o1
a009d3a0:  9a 04 00 10  add  %l0, %l0, %o5
a009d3a4:  9a 03 40 10  add  %o5, %l0, %o5
a009d3a8:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009d3ac:  82 10 62 50  or  %g1, 0x250, %g1	! 0xa807d650
a009d3b0:  9b 2b 60 03  sll  %o5, 3, %o5
a009d3b4:  9a 03 40 01  add  %o5, %g1, %o5
a009d3b8:  82 10 20 01  mov  1, %g1
a009d3bc:  c2 2b 60 0a  stb  %g1, [ %o5 + 0xa ]
a009d3c0:  7f ff e8 4b  call  0xa00974ec
a009d3c4:  90 10 00 10  mov  %l0, %o0
a009d3c8:  96 0e 20 ff  and  %i0, 0xff, %o3
a009d3cc:  15 2a 01 f5  sethi  %hi(0xa807d400), %o2
a009d3d0:  82 12 a3 e0  or  %o2, 0x3e0, %g1	! 0xa807d7e0
a009d3d4:  9a 5a e1 90  smul  %o3, 0x190, %o5
a009d3d8:  9a 03 40 01  add  %o5, %g1, %o5
a009d3dc:  13 2a 01 e4  sethi  %hi(0xa8079000), %o1
a009d3e0:  82 12 60 50  or  %o1, 0x50, %g1	! 0xa8079050
a009d3e4:  da 0b 60 07  ldub  [ %o5 + 7 ], %o5
a009d3e8:  c2 08 40 0b  ldub  [ %g1 + %o3 ], %g1
a009d3ec:  80 a3 40 01  cmp  %o5, %g1
a009d3f0:  02 80 00 14  be  0xa009d440
a009d3f4:  80 a0 60 01  cmp  %g1, 1
a009d3f8:  32 80 00 0d  bne,a   0xa009d42c
a009d3fc:  9a 12 a3 e0  or  %o2, 0x3e0, %o5
a009d400:  80 a3 60 00  cmp  %o5, 0
a009d404:  12 80 00 0a  bne  0xa009d42c
a009d408:  9a 12 a3 e0  or  %o2, 0x3e0, %o5
a009d40c:  82 02 c0 0b  add  %o3, %o3, %g1
a009d410:  82 00 40 0b  add  %g1, %o3, %g1
a009d414:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009d418:  83 28 60 03  sll  %g1, 3, %g1
a009d41c:  98 10 20 07  mov  7, %o4
a009d420:  9a 13 62 50  or  %o5, 0x250, %o5
a009d424:  d8 23 40 01  st  %o4, [ %o5 + %g1 ]
a009d428:  9a 12 a3 e0  or  %o2, 0x3e0, %o5
a009d42c:  82 5a e1 90  smul  %o3, 0x190, %g1
a009d430:  82 00 40 0d  add  %g1, %o5, %g1
a009d434:  9a 12 60 50  or  %o1, 0x50, %o5
a009d438:  c2 08 60 07  ldub  [ %g1 + 7 ], %g1
a009d43c:  c2 2b 40 0b  stb  %g1, [ %o5 + %o3 ]
a009d440:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009d444:  40 00 0f 43  call  0xa00a1150
a009d448:  90 10 00 18  mov  %i0, %o0
a009d44c:  7f ff fd ba  call  0xa009cb34
a009d450:  90 10 00 18  mov  %i0, %o0
a009d454:  90 0a 20 ff  and  %o0, 0xff, %o0
a009d458:  80 a2 20 01  cmp  %o0, 1
a009d45c:  12 80 00 09  bne  0xa009d480
a009d460:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009d464:  9a 06 00 18  add  %i0, %i0, %o5
a009d468:  9a 03 40 18  add  %o5, %i0, %o5
a009d46c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009d470:  9b 2b 60 03  sll  %o5, 3, %o5
a009d474:  82 10 62 50  or  %g1, 0x250, %g1
a009d478:  c0 20 40 0d  clr  [ %g1 + %o5 ]
a009d47c:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009d480:  82 5e 21 90  smul  %i0, 0x190, %g1
a009d484:  9a 13 63 e0  or  %o5, 0x3e0, %o5
a009d488:  82 00 40 0d  add  %g1, %o5, %g1
a009d48c:  c2 08 60 06  ldub  [ %g1 + 6 ], %g1
a009d490:  80 a0 60 00  cmp  %g1, 0
a009d494:  12 80 00 4a  bne  0xa009d5bc
a009d498:  01 00 00 00  nop
a009d49c:  40 00 0b cb  call  0xa00a03c8
a009d4a0:  90 10 00 18  mov  %i0, %o0
a009d4a4:  80 8a 20 ff  btst  0xff, %o0
a009d4a8:  02 80 00 45  be  0xa009d5bc
a009d4ac:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009d4b0:  94 10 60 b8  or  %g1, 0xb8, %o2	! 0xa80790b8
a009d4b4:  c2 0a 80 18  ldub  [ %o2 + %i0 ], %g1
a009d4b8:  80 a0 60 00  cmp  %g1, 0
a009d4bc:  12 80 00 18  bne  0xa009d51c
a009d4c0:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009d4c4:  9a 5e 20 34  smul  %i0, 0x34, %o5
a009d4c8:  82 10 63 00  or  %g1, 0x300, %g1
a009d4cc:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a009d4d0:  1b 22 67 03  sethi  %hi(0x899c0c00), %o5
a009d4d4:  d8 00 60 98  ld  [ %g1 + 0x98 ], %o4
a009d4d8:  9a 13 63 61  or  %o5, 0x361, %o5
a009d4dc:  80 53 00 0d  umul  %o4, %o5, %g0
a009d4e0:  9b 40 00 00  rd  %y, %o5
a009d4e4:  82 23 00 0d  sub  %o4, %o5, %g1
a009d4e8:  83 30 60 01  srl  %g1, 1, %g1
a009d4ec:  9a 03 40 01  add  %o5, %g1, %o5
a009d4f0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009d4f4:  97 2e 20 02  sll  %i0, 2, %o3
a009d4f8:  82 10 60 ec  or  %g1, 0xec, %g1
a009d4fc:  9b 33 60 08  srl  %o5, 8, %o5
a009d500:  da 20 40 0b  st  %o5, [ %g1 + %o3 ]
a009d504:  82 10 20 01  mov  1, %g1
a009d508:  c2 2a 80 18  stb  %g1, [ %o2 + %i0 ]
a009d50c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009d510:  82 10 60 e4  or  %g1, 0xe4, %g1	! 0xa80790e4
a009d514:  d8 20 40 0b  st  %o4, [ %g1 + %o3 ]
a009d518:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009d51c:  9a 5e 20 34  smul  %i0, 0x34, %o5
a009d520:  82 10 63 00  or  %g1, 0x300, %g1
a009d524:  d6 00 40 0d  ld  [ %g1 + %o5 ], %o3
a009d528:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009d52c:  a1 2e 20 02  sll  %i0, 2, %l0
a009d530:  94 10 60 e4  or  %g1, 0xe4, %o2
a009d534:  da 02 e0 98  ld  [ %o3 + 0x98 ], %o5
a009d538:  c2 02 80 10  ld  [ %o2 + %l0 ], %g1
a009d53c:  82 20 40 0d  sub  %g1, %o5, %g1
a009d540:  99 38 60 1f  sra  %g1, 0x1f, %o4
a009d544:  1b 2a 01 e4  sethi  %hi(0xa8079000), %o5
a009d548:  82 1b 00 01  xor  %o4, %g1, %g1
a009d54c:  a2 13 60 ec  or  %o5, 0xec, %l1
a009d550:  82 20 40 0c  sub  %g1, %o4, %g1
a009d554:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a009d558:  80 a0 40 0d  cmp  %g1, %o5
a009d55c:  08 80 00 18  bleu  0xa009d5bc
a009d560:  03 22 67 03  sethi  %hi(0x899c0c00), %g1
a009d564:  d8 02 e0 98  ld  [ %o3 + 0x98 ], %o4
a009d568:  82 10 63 61  or  %g1, 0x361, %g1
a009d56c:  80 53 00 01  umul  %o4, %g1, %g0
a009d570:  83 40 00 00  rd  %y, %g1
a009d574:  9a 23 00 01  sub  %o4, %g1, %o5
a009d578:  9b 33 60 01  srl  %o5, 1, %o5
a009d57c:  82 00 40 0d  add  %g1, %o5, %g1
a009d580:  83 30 60 08  srl  %g1, 8, %g1
a009d584:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a009d588:  90 10 00 18  mov  %i0, %o0
a009d58c:  7f ff fc bc  call  0xa009c87c
a009d590:  d8 22 80 10  st  %o4, [ %o2 + %l0 ]
a009d594:  9a 06 00 18  add  %i0, %i0, %o5
a009d598:  9a 03 40 18  add  %o5, %i0, %o5
a009d59c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009d5a0:  9b 2b 60 03  sll  %o5, 3, %o5
a009d5a4:  82 10 62 50  or  %g1, 0x250, %g1
a009d5a8:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009d5ac:  c0 20 40 0d  clr  [ %g1 + %o5 ]
a009d5b0:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009d5b4:  7f ff 56 a4  call  0xa0073044
a009d5b8:  90 12 21 c8  or  %o0, 0x1c8, %o0
a009d5bc:  40 00 2f 8a  call  0xa00a93e4
a009d5c0:  90 10 00 18  mov  %i0, %o0
a009d5c4:  81 c7 e0 08  ret
a009d5c8:  91 e8 20 00  restore  %g0, 0, %o0
