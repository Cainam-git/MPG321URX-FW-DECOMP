# leon2s FUN_a00cc2f8 0xa00cc2f8-0xa00cc5f8 (768 bytes)
a00cc2f8:  9d e3 bf 98  save  %sp, -104, %sp
a00cc2fc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cc300:  82 06 00 18  add  %i0, %i0, %g1
a00cc304:  82 00 40 18  add  %g1, %i0, %g1
a00cc308:  2b 2a 01 e2  sethi  %hi(0xa8078800), %l5
a00cc30c:  a1 28 60 03  sll  %g1, 3, %l0
a00cc310:  a2 15 63 b0  or  %l5, 0x3b0, %l1
a00cc314:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00cc318:  83 33 60 16  srl  %o5, 0x16, %g1
a00cc31c:  80 88 60 01  btst  1, %g1
a00cc320:  02 80 00 1a  be  0xa00cc388
a00cc324:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cc328:  25 2a 01 f4  sethi  %hi(0xa807d000), %l2
a00cc32c:  90 10 00 18  mov  %i0, %o0
a00cc330:  7f ff f5 1a  call  0xa00c9798
a00cc334:  92 14 a2 50  or  %l2, 0x250, %o1
a00cc338:  80 8a 20 ff  btst  0xff, %o0
a00cc33c:  32 80 00 0b  bne,a   0xa00cc368
a00cc340:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00cc344:  82 14 a2 50  or  %l2, 0x250, %g1
a00cc348:  d8 08 60 01  ldub  [ %g1 + 1 ], %o4
a00cc34c:  82 0b 20 03  and  %o4, 3, %g1
a00cc350:  83 28 60 08  sll  %g1, 8, %g1
a00cc354:  da 0c a2 50  ldub  [ %l2 + 0x250 ], %o5
a00cc358:  80 8b 20 0c  btst  0xc, %o4
a00cc35c:  02 80 00 06  be  0xa00cc374
a00cc360:  82 00 40 0d  add  %g1, %o5, %g1
a00cc364:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00cc368:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cc36c:  10 80 00 08  b  0xa00cc38c
a00cc370:  82 2b 40 01  andn  %o5, %g1, %g1
a00cc374:  83 28 60 10  sll  %g1, 0x10, %g1
a00cc378:  80 a0 60 00  cmp  %g1, 0
a00cc37c:  02 80 00 06  be  0xa00cc394
a00cc380:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cc384:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00cc388:  82 10 40 0d  or  %g1, %o5, %g1
a00cc38c:  10 80 00 99  b  0xa00cc5f0
a00cc390:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cc394:  83 30 60 1c  srl  %g1, 0x1c, %g1
a00cc398:  80 88 60 01  btst  1, %g1
a00cc39c:  02 80 00 95  be  0xa00cc5f0
a00cc3a0:  90 10 00 18  mov  %i0, %o0
a00cc3a4:  92 10 20 06  mov  6, %o1
a00cc3a8:  7f ff ec ab  call  0xa00c7654
a00cc3ac:  94 10 20 90  mov  0x90, %o2
a00cc3b0:  90 10 00 18  mov  %i0, %o0
a00cc3b4:  92 10 20 0d  mov  0xd, %o1
a00cc3b8:  7f ff f1 0c  call  0xa00c87e8
a00cc3bc:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cc3c0:  a2 10 20 00  clr  %l1
a00cc3c4:  9a 06 00 18  add  %i0, %i0, %o5
a00cc3c8:  9a 03 40 18  add  %o5, %i0, %o5
a00cc3cc:  82 15 63 b0  or  %l5, 0x3b0, %g1
a00cc3d0:  9b 2b 60 03  sll  %o5, 3, %o5
a00cc3d4:  9a 03 40 01  add  %o5, %g1, %o5
a00cc3d8:  98 0c 60 ff  and  %l1, 0xff, %o4
a00cc3dc:  82 10 20 02  mov  2, %g1
a00cc3e0:  82 20 40 0c  sub  %g1, %o4, %g1
a00cc3e4:  83 28 60 03  sll  %g1, 3, %g1
a00cc3e8:  d4 03 60 10  ld  [ %o5 + 0x10 ], %o2
a00cc3ec:  95 32 80 01  srl  %o2, %g1, %o2
a00cc3f0:  94 0a a0 ff  and  %o2, 0xff, %o2
a00cc3f4:  90 10 00 18  mov  %i0, %o0
a00cc3f8:  7f ff ec 97  call  0xa00c7654
a00cc3fc:  92 10 20 01  mov  1, %o1
a00cc400:  a2 04 60 01  inc  %l1
a00cc404:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cc408:  80 a0 60 02  cmp  %g1, 2
a00cc40c:  08 bf ff ef  bleu  0xa00cc3c8
a00cc410:  9a 06 00 18  add  %i0, %i0, %o5
a00cc414:  90 10 00 18  mov  %i0, %o0
a00cc418:  92 10 20 01  mov  1, %o1
a00cc41c:  7f ff ec 8e  call  0xa00c7654
a00cc420:  94 10 20 00  clr  %o2
a00cc424:  90 10 00 18  mov  %i0, %o0
a00cc428:  92 10 20 01  mov  1, %o1
a00cc42c:  7f ff ec 8a  call  0xa00c7654
a00cc430:  94 10 20 01  mov  1, %o2
a00cc434:  90 10 00 18  mov  %i0, %o0
a00cc438:  92 10 20 01  mov  1, %o1
a00cc43c:  7f ff ec 86  call  0xa00c7654
a00cc440:  94 10 20 00  clr  %o2
a00cc444:  90 10 00 18  mov  %i0, %o0
a00cc448:  92 10 20 01  mov  1, %o1
a00cc44c:  7f ff ec 82  call  0xa00c7654
a00cc450:  94 10 20 00  clr  %o2
a00cc454:  a2 10 20 00  clr  %l1
a00cc458:  82 06 00 18  add  %i0, %i0, %g1
a00cc45c:  82 00 40 18  add  %g1, %i0, %g1
a00cc460:  83 28 60 03  sll  %g1, 3, %g1
a00cc464:  9a 15 63 b0  or  %l5, 0x3b0, %o5
a00cc468:  a0 00 40 0d  add  %g1, %o5, %l0
a00cc46c:  98 0c 60 ff  and  %l1, 0xff, %o4
a00cc470:  82 10 20 02  mov  2, %g1
a00cc474:  82 20 40 0c  sub  %g1, %o4, %g1
a00cc478:  83 28 60 03  sll  %g1, 3, %g1
a00cc47c:  d4 04 20 10  ld  [ %l0 + 0x10 ], %o2
a00cc480:  95 32 80 01  srl  %o2, %g1, %o2
a00cc484:  94 0a a0 ff  and  %o2, 0xff, %o2
a00cc488:  90 10 00 18  mov  %i0, %o0
a00cc48c:  7f ff ec 72  call  0xa00c7654
a00cc490:  92 10 20 01  mov  1, %o1
a00cc494:  a2 04 60 01  inc  %l1
a00cc498:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cc49c:  80 a0 60 02  cmp  %g1, 2
a00cc4a0:  08 bf ff ef  bleu  0xa00cc45c
a00cc4a4:  82 06 00 18  add  %i0, %i0, %g1
a00cc4a8:  90 10 00 18  mov  %i0, %o0
a00cc4ac:  92 10 20 01  mov  1, %o1
a00cc4b0:  7f ff ec 69  call  0xa00c7654
a00cc4b4:  94 10 20 80  mov  0x80, %o2
a00cc4b8:  c2 04 20 10  ld  [ %l0 + 0x10 ], %g1
a00cc4bc:  82 00 60 01  inc  %g1
a00cc4c0:  c2 24 20 10  st  %g1, [ %l0 + 0x10 ]
a00cc4c4:  90 10 00 18  mov  %i0, %o0
a00cc4c8:  7f ff ec aa  call  0xa00c7770
a00cc4cc:  92 10 20 06  mov  6, %o1
a00cc4d0:  80 8a 20 80  btst  0x80, %o0
a00cc4d4:  12 bf ff fd  bne  0xa00cc4c8
a00cc4d8:  90 10 00 18  mov  %i0, %o0
a00cc4dc:  15 00 00 10  sethi  %hi(0x4000), %o2
a00cc4e0:  94 12 a0 20  or  %o2, 0x20, %o2	! 0x4020
a00cc4e4:  7f ff f0 c1  call  0xa00c87e8
a00cc4e8:  92 10 20 10  mov  0x10, %o1
a00cc4ec:  a2 10 20 00  clr  %l1
a00cc4f0:  92 10 20 12  mov  0x12, %o1
a00cc4f4:  7f ff ec 9f  call  0xa00c7770
a00cc4f8:  90 10 00 18  mov  %i0, %o0
a00cc4fc:  92 0a 20 ff  and  %o0, 0xff, %o1
a00cc500:  29 27 c7 32  sethi  %hi(0x9f1cc800), %l4
a00cc504:  40 3a da d0  call  0xa0f83044
a00cc508:  90 15 22 30  or  %l4, 0x230, %o0	! 0x9f1cca30
a00cc50c:  a2 04 60 01  inc  %l1
a00cc510:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cc514:  80 a0 60 1f  cmp  %g1, 0x1f
a00cc518:  28 bf ff f7  bleu,a   0xa00cc4f4
a00cc51c:  92 10 20 12  mov  0x12, %o1
a00cc520:  90 10 00 18  mov  %i0, %o0
a00cc524:  92 10 20 00  clr  %o1
a00cc528:  7f ff f0 b0  call  0xa00c87e8
a00cc52c:  94 10 20 00  clr  %o2
a00cc530:  90 10 00 18  mov  %i0, %o0
a00cc534:  92 10 20 06  mov  6, %o1
a00cc538:  7f ff ec 47  call  0xa00c7654
a00cc53c:  94 10 20 f0  mov  0xf0, %o2
a00cc540:  90 10 00 18  mov  %i0, %o0
a00cc544:  7f ff ec 8b  call  0xa00c7770
a00cc548:  92 10 20 06  mov  6, %o1
a00cc54c:  80 8a 20 80  btst  0x80, %o0
a00cc550:  12 bf ff fd  bne  0xa00cc544
a00cc554:  90 10 00 18  mov  %i0, %o0
a00cc558:  92 10 20 0d  mov  0xd, %o1
a00cc55c:  7f ff f0 a3  call  0xa00c87e8
a00cc560:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cc564:  a2 10 20 00  clr  %l1
a00cc568:  27 2a 01 f3  sethi  %hi(0xa807cc00), %l3
a00cc56c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00cc570:  92 10 20 01  mov  1, %o1
a00cc574:  a4 14 e2 50  or  %l3, 0x250, %l2
a00cc578:  7f ff ec 7e  call  0xa00c7770
a00cc57c:  90 10 00 18  mov  %i0, %o0
a00cc580:  a0 04 00 12  add  %l0, %l2, %l0
a00cc584:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00cc588:  92 0a 20 ff  and  %o0, 0xff, %o1
a00cc58c:  40 3a da ae  call  0xa0f83044
a00cc590:  90 15 22 30  or  %l4, 0x230, %o0
a00cc594:  a2 04 60 01  inc  %l1
a00cc598:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cc59c:  80 a0 60 06  cmp  %g1, 6
a00cc5a0:  28 bf ff f3  bleu,a   0xa00cc56c
a00cc5a4:  27 2a 01 f3  sethi  %hi(0xa807cc00), %l3
a00cc5a8:  82 10 20 10  mov  0x10, %g1
a00cc5ac:  c2 2c e2 50  stb  %g1, [ %l3 + 0x250 ]
a00cc5b0:  96 10 20 60  mov  0x60, %o3
a00cc5b4:  98 10 20 08  mov  8, %o4
a00cc5b8:  92 10 00 12  mov  %l2, %o1
a00cc5bc:  90 10 00 18  mov  %i0, %o0
a00cc5c0:  7f ff ee cc  call  0xa00c80f0
a00cc5c4:  94 10 20 74  mov  0x74, %o2
a00cc5c8:  98 06 00 18  add  %i0, %i0, %o4
a00cc5cc:  98 03 00 18  add  %o4, %i0, %o4
a00cc5d0:  96 15 63 b0  or  %l5, 0x3b0, %o3
a00cc5d4:  99 2b 20 03  sll  %o4, 3, %o4
a00cc5d8:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cc5dc:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cc5e0:  82 2b 40 01  andn  %o5, %g1, %g1
a00cc5e4:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cc5e8:  82 10 40 0d  or  %g1, %o5, %g1
a00cc5ec:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cc5f0:  81 c7 e0 08  ret
a00cc5f4:  81 e8 00 00  restore
