# leon2m FUN_a00ea308 0xa00ea308-0xa00ea638 (816 bytes)
a00ea308:  9d e3 bf 98  save  %sp, -104, %sp
a00ea30c:  80 a6 ff ff  cmp  %i3, -1
a00ea310:  02 80 00 7d  be  0xa00ea504
a00ea314:  a4 10 00 18  mov  %i0, %l2
a00ea318:  2d 2a 00 ad  sethi  %hi(0xa802b400), %l6
a00ea31c:  9b 2e e0 02  sll  %i3, 2, %o5
a00ea320:  15 2a 00 98  sethi  %hi(0xa8026000), %o2
a00ea324:  92 15 a2 18  or  %l6, 0x218, %o1
a00ea328:  2f 2a 00 98  sethi  %hi(0xa8026000), %l7
a00ea32c:  98 12 a2 68  or  %o2, 0x268, %o4
a00ea330:  9e 15 e2 58  or  %l7, 0x258, %o7
a00ea334:  d6 02 40 0d  ld  [ %o1 + %o5 ], %o3
a00ea338:  d2 03 00 0d  ld  [ %o4 + %o5 ], %o1
a00ea33c:  d4 03 c0 0d  ld  [ %o7 + %o5 ], %o2
a00ea340:  90 10 00 18  mov  %i0, %o0
a00ea344:  7f ff d9 04  call  0xa00e0754
a00ea348:  27 2a 00 98  sethi  %hi(0xa8026000), %l3
a00ea34c:  ba 14 e2 68  or  %l3, 0x268, %i5	! 0xa8026268
a00ea350:  21 2a 00 98  sethi  %hi(0xa8026000), %l0
a00ea354:  17 2a 00 98  sethi  %hi(0xa8026000), %o3
a00ea358:  a2 10 00 08  mov  %o0, %l1
a00ea35c:  a8 14 22 48  or  %l0, 0x248, %l4
a00ea360:  aa 12 e2 38  or  %o3, 0x238, %l5
a00ea364:  a7 2e e0 02  sll  %i3, 2, %l3
a00ea368:  10 80 00 06  b  0xa00ea380
a00ea36c:  a0 10 20 00  clr  %l0
a00ea370:  a0 04 20 01  inc  %l0
a00ea374:  80 a4 20 07  cmp  %l0, 7
a00ea378:  14 80 00 33  bg  0xa00ea444
a00ea37c:  90 10 00 12  mov  %l2, %o0
a00ea380:  82 10 20 01  mov  1, %g1
a00ea384:  b1 28 40 10  sll  %g1, %l0, %i0
a00ea388:  80 8e 00 11  btst  %i0, %l1
a00ea38c:  12 bf ff f9  bne  0xa00ea370
a00ea390:  90 10 00 12  mov  %l2, %o0
a00ea394:  d6 05 00 13  ld  [ %l4 + %l3 ], %o3
a00ea398:  92 02 c0 10  add  %o3, %l0, %o1
a00ea39c:  7f ff d8 5e  call  0xa00e0514
a00ea3a0:  d4 05 40 13  ld  [ %l5 + %l3 ], %o2
a00ea3a4:  98 10 00 08  mov  %o0, %o4
a00ea3a8:  93 33 20 03  srl  %o4, 3, %o1
a00ea3ac:  94 02 60 01  add  %o1, 1, %o2
a00ea3b0:  9f 2a a0 03  sll  %o2, 3, %o7
a00ea3b4:  9a 0b 20 07  and  %o4, 7, %o5
a00ea3b8:  90 10 00 12  mov  %l2, %o0
a00ea3bc:  80 a2 60 0f  cmp  %o1, 0xf
a00ea3c0:  02 80 00 5b  be  0xa00ea52c
a00ea3c4:  96 03 c0 0d  add  %o7, %o5, %o3
a00ea3c8:  f0 05 00 13  ld  [ %l4 + %l3 ], %i0
a00ea3cc:  92 06 00 10  add  %i0, %l0, %o1
a00ea3d0:  7f ff d8 82  call  0xa00e05d8
a00ea3d4:  d4 05 40 13  ld  [ %l5 + %l3 ], %o2
a00ea3d8:  92 10 00 1b  mov  %i3, %o1
a00ea3dc:  94 10 00 10  mov  %l0, %o2
a00ea3e0:  96 10 20 00  clr  %o3
a00ea3e4:  7f ff ff 9e  call  0xa00ea25c
a00ea3e8:  90 10 00 12  mov  %l2, %o0
a00ea3ec:  b0 10 00 08  mov  %o0, %i0
a00ea3f0:  94 10 00 10  mov  %l0, %o2
a00ea3f4:  92 10 00 1b  mov  %i3, %o1
a00ea3f8:  96 10 20 01  mov  1, %o3
a00ea3fc:  80 a6 20 00  cmp  %i0, 0
a00ea400:  12 80 00 49  bne  0xa00ea524
a00ea404:  90 10 00 12  mov  %l2, %o0
a00ea408:  7f ff ff 95  call  0xa00ea25c
a00ea40c:  01 00 00 00  nop
a00ea410:  b0 10 00 08  mov  %o0, %i0
a00ea414:  94 10 00 10  mov  %l0, %o2
a00ea418:  90 10 00 12  mov  %l2, %o0
a00ea41c:  92 10 00 1b  mov  %i3, %o1
a00ea420:  80 a6 20 00  cmp  %i0, 0
a00ea424:  12 80 00 40  bne  0xa00ea524
a00ea428:  96 10 20 00  clr  %o3
a00ea42c:  7f ff ff 8c  call  0xa00ea25c
a00ea430:  01 00 00 00  nop
a00ea434:  80 a2 20 00  cmp  %o0, 0
a00ea438:  22 bf ff cf  be,a   0xa00ea374
a00ea43c:  a0 04 20 01  inc  %l0
a00ea440:  30 80 00 7c  b,a   0xa00ea630
a00ea444:  92 10 00 19  mov  %i1, %o1
a00ea448:  94 10 00 1a  mov  %i2, %o2
a00ea44c:  7f ff e8 3b  call  0xa00e4538
a00ea450:  96 10 00 1c  mov  %i4, %o3
a00ea454:  80 a6 ff ff  cmp  %i3, -1
a00ea458:  02 80 00 25  be  0xa00ea4ec
a00ea45c:  a0 10 00 08  mov  %o0, %l0
a00ea460:  83 2e e0 02  sll  %i3, 2, %g1
a00ea464:  90 15 e2 58  or  %l7, 0x258, %o0
a00ea468:  9e 15 a2 18  or  %l6, 0x218, %o7
a00ea46c:  d4 02 00 01  ld  [ %o0 + %g1 ], %o2
a00ea470:  d6 03 c0 01  ld  [ %o7 + %g1 ], %o3
a00ea474:  90 10 00 12  mov  %l2, %o0
a00ea478:  d2 07 40 01  ld  [ %i5 + %g1 ], %o1
a00ea47c:  7f ff d8 b6  call  0xa00e0754
a00ea480:  01 00 00 00  nop
a00ea484:  98 1c 20 01  xor  %l0, 1, %o4
a00ea488:  80 a0 00 0c  cmp  %g0, %o4
a00ea48c:  9a 60 3f ff  subx  %g0, -1, %o5
a00ea490:  98 1a 20 ff  xor  %o0, 0xff, %o4
a00ea494:  80 a0 00 0c  cmp  %g0, %o4
a00ea498:  92 60 3f ff  subx  %g0, -1, %o1
a00ea49c:  80 8b 40 09  btst  %o5, %o1
a00ea4a0:  12 80 00 2d  bne  0xa00ea554
a00ea4a4:  a2 10 00 08  mov  %o0, %l1
a00ea4a8:  80 a4 20 02  cmp  %l0, 2
a00ea4ac:  96 40 20 00  addx  %g0, 0, %o3
a00ea4b0:  80 a0 00 0c  cmp  %g0, %o4
a00ea4b4:  94 40 20 00  addx  %g0, 0, %o2
a00ea4b8:  80 8a c0 0a  btst  %o3, %o2
a00ea4bc:  32 bf ff b1  bne,a   0xa00ea380
a00ea4c0:  a0 10 20 00  clr  %l0
a00ea4c4:  7f ff d4 d2  call  0xa00df80c
a00ea4c8:  25 00 06 67  sethi  %hi(0x199c00), %l2
a00ea4cc:  7f ff d9 bd  call  0xa00e0bc0
a00ea4d0:  01 00 00 00  nop
a00ea4d4:  90 14 a1 70  or  %l2, 0x170, %o0
a00ea4d8:  92 10 00 10  mov  %l0, %o1
a00ea4dc:  7f ff d3 25  call  0xa00df170
a00ea4e0:  94 10 00 11  mov  %l1, %o2
a00ea4e4:  10 80 00 53  b  0xa00ea630
a00ea4e8:  90 10 3f ff  mov  -1, %o0
a00ea4ec:  23 2a 00 98  sethi  %hi(0xa8026000), %l1
a00ea4f0:  90 10 00 12  mov  %l2, %o0
a00ea4f4:  92 14 62 68  or  %l1, 0x268, %o1
a00ea4f8:  94 15 e2 58  or  %l7, 0x258, %o2
a00ea4fc:  10 bf ff e0  b  0xa00ea47c
a00ea500:  96 15 a2 18  or  %l6, 0x218, %o3
a00ea504:  2f 2a 00 98  sethi  %hi(0xa8026000), %l7
a00ea508:  2d 2a 00 ad  sethi  %hi(0xa802b400), %l6
a00ea50c:  03 2a 00 98  sethi  %hi(0xa8026000), %g1
a00ea510:  90 10 00 18  mov  %i0, %o0
a00ea514:  92 10 62 68  or  %g1, 0x268, %o1
a00ea518:  94 15 e2 58  or  %l7, 0x258, %o2
a00ea51c:  10 bf ff 8a  b  0xa00ea344
a00ea520:  96 15 a2 18  or  %l6, 0x218, %o3
a00ea524:  10 80 00 43  b  0xa00ea630
a00ea528:  90 10 00 18  mov  %i0, %o0
a00ea52c:  7f ff d4 b8  call  0xa00df80c
a00ea530:  01 00 00 00  nop
a00ea534:  7f ff d9 a3  call  0xa00e0bc0
a00ea538:  01 00 00 00  nop
a00ea53c:  11 00 06 67  sethi  %hi(0x199c00), %o0
a00ea540:  90 12 21 98  or  %o0, 0x198, %o0	! 0x199d98
a00ea544:  7f ff d3 0b  call  0xa00df170
a00ea548:  92 10 20 01  mov  1, %o1
a00ea54c:  10 80 00 39  b  0xa00ea630
a00ea550:  90 10 3f ff  mov  -1, %o0
a00ea554:  29 2a 00 98  sethi  %hi(0xa8026000), %l4
a00ea558:  a6 15 22 48  or  %l4, 0x248, %l3	! 0xa8026248
a00ea55c:  2b 2a 00 98  sethi  %hi(0xa8026000), %l5
a00ea560:  a8 15 62 38  or  %l5, 0x238, %l4	! 0xa8026238
a00ea564:  a0 10 20 00  clr  %l0
a00ea568:  10 80 00 06  b  0xa00ea580
a00ea56c:  a3 2e e0 02  sll  %i3, 2, %l1
a00ea570:  a0 04 20 01  inc  %l0
a00ea574:  80 a4 20 07  cmp  %l0, 7
a00ea578:  14 80 00 2e  bg  0xa00ea630
a00ea57c:  90 10 20 00  clr  %o0
a00ea580:  fa 04 c0 11  ld  [ %l3 + %l1 ], %i5
a00ea584:  92 07 40 10  add  %i5, %l0, %o1
a00ea588:  d4 05 00 11  ld  [ %l4 + %l1 ], %o2
a00ea58c:  7f ff d7 e2  call  0xa00e0514
a00ea590:  90 10 00 12  mov  %l2, %o0
a00ea594:  b2 10 00 08  mov  %o0, %i1
a00ea598:  b5 36 60 03  srl  %i1, 3, %i2
a00ea59c:  b8 06 bf ff  add  %i2, -1, %i4
a00ea5a0:  ad 2f 20 03  sll  %i4, 3, %l6
a00ea5a4:  ae 0e 60 07  and  %i1, 7, %l7
a00ea5a8:  90 10 00 12  mov  %l2, %o0
a00ea5ac:  80 a6 a0 00  cmp  %i2, 0
a00ea5b0:  02 bf ff f0  be  0xa00ea570
a00ea5b4:  96 05 80 17  add  %l6, %l7, %o3
a00ea5b8:  f0 04 c0 11  ld  [ %l3 + %l1 ], %i0
a00ea5bc:  92 06 00 10  add  %i0, %l0, %o1
a00ea5c0:  7f ff d8 06  call  0xa00e05d8
a00ea5c4:  d4 05 00 11  ld  [ %l4 + %l1 ], %o2
a00ea5c8:  92 10 00 1b  mov  %i3, %o1
a00ea5cc:  94 10 00 10  mov  %l0, %o2
a00ea5d0:  96 10 20 00  clr  %o3
a00ea5d4:  7f ff ff 22  call  0xa00ea25c
a00ea5d8:  90 10 00 12  mov  %l2, %o0
a00ea5dc:  b0 10 00 08  mov  %o0, %i0
a00ea5e0:  94 10 00 10  mov  %l0, %o2
a00ea5e4:  92 10 00 1b  mov  %i3, %o1
a00ea5e8:  96 10 20 01  mov  1, %o3
a00ea5ec:  80 a6 20 00  cmp  %i0, 0
a00ea5f0:  12 bf ff cd  bne  0xa00ea524
a00ea5f4:  90 10 00 12  mov  %l2, %o0
a00ea5f8:  7f ff ff 19  call  0xa00ea25c
a00ea5fc:  01 00 00 00  nop
a00ea600:  b0 10 00 08  mov  %o0, %i0
a00ea604:  94 10 00 10  mov  %l0, %o2
a00ea608:  90 10 00 12  mov  %l2, %o0
a00ea60c:  92 10 00 1b  mov  %i3, %o1
a00ea610:  80 a6 20 00  cmp  %i0, 0
a00ea614:  12 bf ff c4  bne  0xa00ea524
a00ea618:  96 10 20 00  clr  %o3
a00ea61c:  7f ff ff 10  call  0xa00ea25c
a00ea620:  01 00 00 00  nop
a00ea624:  80 a2 20 00  cmp  %o0, 0
a00ea628:  22 bf ff d3  be,a   0xa00ea574
a00ea62c:  a0 04 20 01  inc  %l0
a00ea630:  81 c7 e0 08  ret
a00ea634:  91 e8 00 08  restore  %g0, %o0, %o0
