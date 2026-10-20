# leon2m FUN_a00e7254 0xa00e7254-0xa00e7dc8 (2932 bytes)
a00e7254:  9d e3 bf 70  save  %sp, -144, %sp
a00e7258:  92 10 20 54  mov  0x54, %o1
a00e725c:  7f ff e4 24  call  0xa00e02ec
a00e7260:  90 10 00 18  mov  %i0, %o0
a00e7264:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00e7268:  92 10 21 49  mov  0x149, %o1
a00e726c:  7f ff e4 20  call  0xa00e02ec
a00e7270:  90 10 00 18  mov  %i0, %o0
a00e7274:  d0 27 bf f0  st  %o0, [ %fp + -16 ]
a00e7278:  92 10 21 4b  mov  0x14b, %o1
a00e727c:  7f ff e4 1c  call  0xa00e02ec
a00e7280:  90 10 00 18  mov  %i0, %o0
a00e7284:  d0 27 bf ec  st  %o0, [ %fp + -20 ]
a00e7288:  92 10 21 4a  mov  0x14a, %o1
a00e728c:  7f ff e4 18  call  0xa00e02ec
a00e7290:  90 10 00 18  mov  %i0, %o0
a00e7294:  d0 27 bf e8  st  %o0, [ %fp + -24 ]
a00e7298:  92 10 21 4c  mov  0x14c, %o1
a00e729c:  7f ff e4 14  call  0xa00e02ec
a00e72a0:  90 10 00 18  mov  %i0, %o0
a00e72a4:  d0 27 bf e4  st  %o0, [ %fp + -28 ]
a00e72a8:  92 10 21 42  mov  0x142, %o1
a00e72ac:  7f ff e4 10  call  0xa00e02ec
a00e72b0:  90 10 00 18  mov  %i0, %o0
a00e72b4:  d0 27 bf e0  st  %o0, [ %fp + -32 ]
a00e72b8:  92 10 21 1a  mov  0x11a, %o1
a00e72bc:  7f ff e4 0c  call  0xa00e02ec
a00e72c0:  90 10 00 18  mov  %i0, %o0
a00e72c4:  d0 27 bf dc  st  %o0, [ %fp + -36 ]
a00e72c8:  92 10 21 21  mov  0x121, %o1
a00e72cc:  7f ff e4 08  call  0xa00e02ec
a00e72d0:  90 10 00 18  mov  %i0, %o0
a00e72d4:  d0 27 bf d8  st  %o0, [ %fp + -40 ]
a00e72d8:  92 10 21 02  mov  0x102, %o1
a00e72dc:  7f ff e4 04  call  0xa00e02ec
a00e72e0:  90 10 00 18  mov  %i0, %o0
a00e72e4:  d0 27 bf d4  st  %o0, [ %fp + -44 ]
a00e72e8:  90 10 20 06  mov  6, %o0
a00e72ec:  92 10 00 18  mov  %i0, %o1
a00e72f0:  7f ff e3 31  call  0xa00dffb4
a00e72f4:  94 10 00 1b  mov  %i3, %o2
a00e72f8:  90 10 00 18  mov  %i0, %o0
a00e72fc:  92 10 00 19  mov  %i1, %o1
a00e7300:  7f ff e2 54  call  0xa00dfc50
a00e7304:  94 10 00 1a  mov  %i2, %o2
a00e7308:  fa 27 a0 58  st  %i5, [ %fp + 0x58 ]
a00e730c:  80 a6 e0 03  cmp  %i3, 3
a00e7310:  a0 10 20 00  clr  %l0
a00e7314:  18 80 02 9a  bgu  0xa00e7d7c
a00e7318:  a2 10 20 00  clr  %l1
a00e731c:  80 a7 20 00  cmp  %i4, 0
a00e7320:  02 80 01 36  be  0xa00e77f8
a00e7324:  80 a6 ff ff  cmp  %i3, -1
a00e7328:  02 80 01 a8  be  0xa00e79c8
a00e732c:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e7330:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e7334:  a1 2e e0 02  sll  %i3, 2, %l0
a00e7338:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00e733c:  96 12 a1 c8  or  %o2, 0x1c8, %o3
a00e7340:  9e 13 61 b8  or  %o5, 0x1b8, %o7
a00e7344:  a2 14 a1 d8  or  %l2, 0x1d8, %l1
a00e7348:  d4 02 c0 10  ld  [ %o3 + %l0 ], %o2
a00e734c:  d6 03 c0 10  ld  [ %o7 + %l0 ], %o3
a00e7350:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a00e7354:  90 10 00 18  mov  %i0, %o0
a00e7358:  7f ff e5 07  call  0xa00e0774
a00e735c:  98 10 20 00  clr  %o4
a00e7360:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00e7364:  98 10 61 a8  or  %g1, 0x1a8, %o4	! 0xa80265a8
a00e7368:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00e736c:  39 2a 00 99  sethi  %hi(0xa8026400), %i4
a00e7370:  d2 03 00 10  ld  [ %o4 + %l0 ], %o1
a00e7374:  ba 12 21 98  or  %o0, 0x198, %i5
a00e7378:  b2 17 21 88  or  %i4, 0x188, %i1
a00e737c:  d4 07 40 10  ld  [ %i5 + %l0 ], %o2
a00e7380:  d6 06 40 10  ld  [ %i1 + %l0 ], %o3
a00e7384:  90 10 00 18  mov  %i0, %o0
a00e7388:  7f ff e4 fb  call  0xa00e0774
a00e738c:  98 10 20 02  mov  2, %o4
a00e7390:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e7394:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e7398:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00e739c:  aa 15 a1 68  or  %l6, 0x168, %l5
a00e73a0:  a6 15 21 58  or  %l4, 0x158, %l3
a00e73a4:  ae 12 61 78  or  %o1, 0x178, %l7
a00e73a8:  d2 05 c0 10  ld  [ %l7 + %l0 ], %o1
a00e73ac:  d4 05 40 10  ld  [ %l5 + %l0 ], %o2
a00e73b0:  d6 04 c0 10  ld  [ %l3 + %l0 ], %o3
a00e73b4:  90 10 00 18  mov  %i0, %o0
a00e73b8:  7f ff e4 ef  call  0xa00e0774
a00e73bc:  98 10 20 00  clr  %o4
a00e73c0:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e73c4:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e73c8:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00e73cc:  96 12 a1 38  or  %o2, 0x138, %o3
a00e73d0:  9e 13 61 28  or  %o5, 0x128, %o7
a00e73d4:  a2 14 a1 48  or  %l2, 0x148, %l1
a00e73d8:  d4 02 c0 10  ld  [ %o3 + %l0 ], %o2
a00e73dc:  d6 03 c0 10  ld  [ %o7 + %l0 ], %o3
a00e73e0:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a00e73e4:  90 10 00 18  mov  %i0, %o0
a00e73e8:  7f ff e4 e3  call  0xa00e0774
a00e73ec:  98 10 20 00  clr  %o4
a00e73f0:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00e73f4:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00e73f8:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00e73fc:  ba 10 62 f8  or  %g1, 0x2f8, %i5
a00e7400:  b8 13 22 e8  or  %o4, 0x2e8, %i4
a00e7404:  b2 12 22 d8  or  %o0, 0x2d8, %i1
a00e7408:  d2 07 40 10  ld  [ %i5 + %l0 ], %o1
a00e740c:  d4 07 00 10  ld  [ %i4 + %l0 ], %o2
a00e7410:  d6 06 40 10  ld  [ %i1 + %l0 ], %o3
a00e7414:  90 10 00 18  mov  %i0, %o0
a00e7418:  7f ff e4 d7  call  0xa00e0774
a00e741c:  98 10 20 00  clr  %o4
a00e7420:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e7424:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00e7428:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e742c:  a6 12 62 a8  or  %o1, 0x2a8, %l3
a00e7430:  aa 15 e2 c8  or  %l7, 0x2c8, %l5
a00e7434:  a8 15 a2 b8  or  %l6, 0x2b8, %l4
a00e7438:  d2 05 40 10  ld  [ %l5 + %l0 ], %o1
a00e743c:  d4 05 00 10  ld  [ %l4 + %l0 ], %o2
a00e7440:  d6 04 c0 10  ld  [ %l3 + %l0 ], %o3
a00e7444:  90 10 00 18  mov  %i0, %o0
a00e7448:  7f ff e4 cb  call  0xa00e0774
a00e744c:  98 10 20 01  mov  1, %o4
a00e7450:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e7454:  94 12 e2 78  or  %o3, 0x278, %o2	! 0xa8026678
a00e7458:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00e745c:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00e7460:  9a 14 a2 98  or  %l2, 0x298, %o5
a00e7464:  9e 14 62 88  or  %l1, 0x288, %o7
a00e7468:  d6 02 80 10  ld  [ %o2 + %l0 ], %o3
a00e746c:  d2 03 40 10  ld  [ %o5 + %l0 ], %o1
a00e7470:  d4 03 c0 10  ld  [ %o7 + %l0 ], %o2
a00e7474:  90 10 00 18  mov  %i0, %o0
a00e7478:  7f ff e4 bf  call  0xa00e0774
a00e747c:  98 10 20 0d  mov  0xd, %o4
a00e7480:  90 10 00 18  mov  %i0, %o0
a00e7484:  92 10 21 49  mov  0x149, %o1
a00e7488:  94 10 20 ff  mov  0xff, %o2
a00e748c:  7f ff e4 53  call  0xa00e05d8
a00e7490:  96 10 20 ff  mov  0xff, %o3
a00e7494:  90 10 00 18  mov  %i0, %o0
a00e7498:  92 10 21 4a  mov  0x14a, %o1
a00e749c:  94 10 20 ff  mov  0xff, %o2
a00e74a0:  7f ff e4 4e  call  0xa00e05d8
a00e74a4:  96 10 20 ff  mov  0xff, %o3
a00e74a8:  90 10 00 18  mov  %i0, %o0
a00e74ac:  92 10 20 de  mov  0xde, %o1
a00e74b0:  94 10 20 c0  mov  0xc0, %o2
a00e74b4:  96 10 20 c0  mov  0xc0, %o3
a00e74b8:  7f ff e4 48  call  0xa00e05d8
a00e74bc:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00e74c0:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e74c4:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e74c8:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00e74cc:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00e74d0:  a6 15 e2 98  or  %l7, 0x298, %l3
a00e74d4:  90 10 00 18  mov  %i0, %o0
a00e74d8:  92 10 20 e1  mov  0xe1, %o1
a00e74dc:  94 10 20 c0  mov  0xc0, %o2
a00e74e0:  96 10 20 c0  mov  0xc0, %o3
a00e74e4:  a2 15 a2 88  or  %l6, 0x288, %l1
a00e74e8:  a4 15 62 78  or  %l5, 0x278, %l2
a00e74ec:  ae 15 22 c8  or  %l4, 0x2c8, %l7
a00e74f0:  7f ff e4 3a  call  0xa00e05d8
a00e74f4:  ba 14 22 b8  or  %l0, 0x2b8, %i5
a00e74f8:  b8 10 20 00  clr  %i4
a00e74fc:  b2 10 20 00  clr  %i1
a00e7500:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e7504:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e7508:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00e750c:  10 80 00 25  b  0xa00e75a0
a00e7510:  a1 2e e0 02  sll  %i3, 2, %l0
a00e7514:  90 15 20 68  or  %l4, 0x68, %o0
a00e7518:  82 15 60 88  or  %l5, 0x88, %g1
a00e751c:  98 15 a0 78  or  %l6, 0x78, %o4
a00e7520:  d6 02 00 10  ld  [ %o0 + %l0 ], %o3
a00e7524:  d2 00 40 10  ld  [ %g1 + %l0 ], %o1
a00e7528:  d4 03 00 10  ld  [ %o4 + %l0 ], %o2
a00e752c:  90 10 00 18  mov  %i0, %o0
a00e7530:  7f ff e4 89  call  0xa00e0754
a00e7534:  b2 06 60 01  inc  %i1
a00e7538:  80 a2 20 00  cmp  %o0, 0
a00e753c:  22 80 00 02  be,a   0xa00e7544
a00e7540:  b2 10 20 00  clr  %i1
a00e7544:  80 a6 a0 03  cmp  %i2, 3
a00e7548:  02 80 00 23  be  0xa00e75d4
a00e754c:  80 a6 a0 04  cmp  %i2, 4
a00e7550:  02 80 00 83  be  0xa00e775c
a00e7554:  80 a6 60 09  cmp  %i1, 9
a00e7558:  80 a6 ff ff  cmp  %i3, -1
a00e755c:  02 80 00 4c  be  0xa00e768c
a00e7560:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e7564:  90 10 00 18  mov  %i0, %o0
a00e7568:  d2 04 c0 10  ld  [ %l3 + %l0 ], %o1
a00e756c:  d4 04 40 10  ld  [ %l1 + %l0 ], %o2
a00e7570:  7f ff e4 79  call  0xa00e0754
a00e7574:  d6 04 80 10  ld  [ %l2 + %l0 ], %o3
a00e7578:  80 a2 20 0c  cmp  %o0, 0xc
a00e757c:  02 80 00 87  be  0xa00e7798
a00e7580:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e7584:  90 10 00 18  mov  %i0, %o0
a00e7588:  92 10 00 1b  mov  %i3, %o1
a00e758c:  7f ff f8 18  call  0xa00e55ec
a00e7590:  94 10 20 01  mov  1, %o2
a00e7594:  80 a2 20 00  cmp  %o0, 0
a00e7598:  12 80 00 b8  bne  0xa00e7878
a00e759c:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a00e75a0:  90 10 00 18  mov  %i0, %o0
a00e75a4:  92 10 20 05  mov  5, %o1
a00e75a8:  94 10 20 00  clr  %o2
a00e75ac:  7f ff f2 b0  call  0xa00e406c
a00e75b0:  17 00 00 04  sethi  %hi(0x1000), %o3
a00e75b4:  80 a6 ff ff  cmp  %i3, -1
a00e75b8:  12 bf ff d7  bne  0xa00e7514
a00e75bc:  b8 07 20 01  inc  %i4
a00e75c0:  90 10 00 18  mov  %i0, %o0
a00e75c4:  92 15 60 88  or  %l5, 0x88, %o1
a00e75c8:  94 15 a0 78  or  %l6, 0x78, %o2
a00e75cc:  10 bf ff d9  b  0xa00e7530
a00e75d0:  96 15 20 68  or  %l4, 0x68, %o3
a00e75d4:  80 a6 60 05  cmp  %i1, 5
a00e75d8:  08 bf ff e1  bleu  0xa00e755c
a00e75dc:  80 a6 ff ff  cmp  %i3, -1
a00e75e0:  80 a7 20 0f  cmp  %i4, 0xf
a00e75e4:  08 80 01 ef  bleu  0xa00e7da0
a00e75e8:  80 a6 ff ff  cmp  %i3, -1
a00e75ec:  02 80 00 d8  be  0xa00e794c
a00e75f0:  35 2a 00 99  sethi  %hi(0xa8026400), %i2
a00e75f4:  91 37 20 04  srl  %i4, 4, %o0
a00e75f8:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e75fc:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e7600:  98 02 3f ff  add  %o0, -1, %o4
a00e7604:  9a 12 62 f8  or  %o1, 0x2f8, %o5
a00e7608:  9e 12 a2 e8  or  %o2, 0x2e8, %o7
a00e760c:  82 16 a2 d8  or  %i2, 0x2d8, %g1
a00e7610:  90 10 00 18  mov  %i0, %o0
a00e7614:  d2 03 40 10  ld  [ %o5 + %l0 ], %o1
a00e7618:  d4 03 c0 10  ld  [ %o7 + %l0 ], %o2
a00e761c:  d6 00 40 10  ld  [ %g1 + %l0 ], %o3
a00e7620:  7f ff e4 55  call  0xa00e0774
a00e7624:  01 00 00 00  nop
a00e7628:  9a 07 20 0d  add  %i4, 0xd, %o5
a00e762c:  98 0b 60 0f  and  %o5, 0xf, %o4
a00e7630:  90 10 00 18  mov  %i0, %o0
a00e7634:  d2 04 c0 10  ld  [ %l3 + %l0 ], %o1
a00e7638:  d4 04 40 10  ld  [ %l1 + %l0 ], %o2
a00e763c:  7f ff e4 4e  call  0xa00e0774
a00e7640:  d6 04 80 10  ld  [ %l2 + %l0 ], %o3
a00e7644:  98 0f 20 08  and  %i4, 8, %o4
a00e7648:  91 33 20 02  srl  %o4, 2, %o0
a00e764c:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e7650:  98 12 20 01  or  %o0, 1, %o4
a00e7654:  9e 12 e2 a8  or  %o3, 0x2a8, %o7
a00e7658:  90 10 00 18  mov  %i0, %o0
a00e765c:  d2 05 c0 10  ld  [ %l7 + %l0 ], %o1
a00e7660:  d4 07 40 10  ld  [ %i5 + %l0 ], %o2
a00e7664:  d6 03 c0 10  ld  [ %o7 + %l0 ], %o3
a00e7668:  7f ff e4 43  call  0xa00e0774
a00e766c:  01 00 00 00  nop
a00e7670:  c2 07 a0 58  ld  [ %fp + 0x58 ], %g1
a00e7674:  80 a0 60 00  cmp  %g1, 0
a00e7678:  02 80 00 23  be  0xa00e7704
a00e767c:  80 a6 ff ff  cmp  %i3, -1
a00e7680:  12 bf ff b9  bne  0xa00e7564
a00e7684:  b4 10 20 00  clr  %i2
a00e7688:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e768c:  92 12 a2 98  or  %o2, 0x298, %o1	! 0xa8026698
a00e7690:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e7694:  94 12 e2 88  or  %o3, 0x288, %o2	! 0xa8026688
a00e7698:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00e769c:  96 13 e2 78  or  %o7, 0x278, %o3	! 0xa8026678
a00e76a0:  7f ff e4 2d  call  0xa00e0754
a00e76a4:  90 10 00 18  mov  %i0, %o0
a00e76a8:  80 a2 20 0c  cmp  %o0, 0xc
a00e76ac:  12 bf ff b7  bne  0xa00e7588
a00e76b0:  90 10 00 18  mov  %i0, %o0
a00e76b4:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00e76b8:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e76bc:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00e76c0:  92 10 62 c8  or  %g1, 0x2c8, %o1
a00e76c4:  94 13 62 b8  or  %o5, 0x2b8, %o2
a00e76c8:  7f ff e4 23  call  0xa00e0754
a00e76cc:  96 13 22 a8  or  %o4, 0x2a8, %o3
a00e76d0:  80 a2 20 03  cmp  %o0, 3
a00e76d4:  12 bf ff ad  bne  0xa00e7588
a00e76d8:  90 10 00 18  mov  %i0, %o0
a00e76dc:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e76e0:  92 12 a2 f8  or  %o2, 0x2f8, %o1	! 0xa80266f8
a00e76e4:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e76e8:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00e76ec:  94 13 62 e8  or  %o5, 0x2e8, %o2
a00e76f0:  7f ff e4 19  call  0xa00e0754
a00e76f4:  96 13 22 d8  or  %o4, 0x2d8, %o3
a00e76f8:  80 a2 20 0f  cmp  %o0, 0xf
a00e76fc:  12 bf ff a3  bne  0xa00e7588
a00e7700:  90 10 00 18  mov  %i0, %o0
a00e7704:  90 10 00 18  mov  %i0, %o0
a00e7708:  92 10 21 49  mov  0x149, %o1
a00e770c:  94 10 20 ff  mov  0xff, %o2
a00e7710:  7f ff e3 b2  call  0xa00e05d8
a00e7714:  96 10 20 ff  mov  0xff, %o3
a00e7718:  90 10 00 18  mov  %i0, %o0
a00e771c:  92 10 21 4a  mov  0x14a, %o1
a00e7720:  94 10 20 ff  mov  0xff, %o2
a00e7724:  7f ff e3 ad  call  0xa00e05d8
a00e7728:  96 10 20 ff  mov  0xff, %o3
a00e772c:  90 10 00 18  mov  %i0, %o0
a00e7730:  92 10 20 de  mov  0xde, %o1
a00e7734:  94 10 20 c0  mov  0xc0, %o2
a00e7738:  7f ff e3 a8  call  0xa00e05d8
a00e773c:  96 10 20 c0  mov  0xc0, %o3
a00e7740:  90 10 00 18  mov  %i0, %o0
a00e7744:  92 10 20 e1  mov  0xe1, %o1
a00e7748:  94 10 20 c0  mov  0xc0, %o2
a00e774c:  7f ff e3 a3  call  0xa00e05d8
a00e7750:  96 10 20 c0  mov  0xc0, %o3
a00e7754:  10 80 00 49  b  0xa00e7878
a00e7758:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a00e775c:  08 bf ff 80  bleu  0xa00e755c
a00e7760:  80 a6 ff ff  cmp  %i3, -1
a00e7764:  02 80 01 21  be  0xa00e7be8
a00e7768:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e776c:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e7770:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e7774:  b4 12 62 f8  or  %o1, 0x2f8, %i2
a00e7778:  82 12 a2 e8  or  %o2, 0x2e8, %g1
a00e777c:  9e 13 62 d8  or  %o5, 0x2d8, %o7
a00e7780:  90 10 00 18  mov  %i0, %o0
a00e7784:  d2 06 80 10  ld  [ %i2 + %l0 ], %o1
a00e7788:  d4 00 40 10  ld  [ %g1 + %l0 ], %o2
a00e778c:  d6 03 c0 10  ld  [ %o7 + %l0 ], %o3
a00e7790:  10 bf ff a4  b  0xa00e7620
a00e7794:  99 37 20 04  srl  %i4, 4, %o4
a00e7798:  9e 12 e2 a8  or  %o3, 0x2a8, %o7
a00e779c:  90 10 00 18  mov  %i0, %o0
a00e77a0:  d2 05 c0 10  ld  [ %l7 + %l0 ], %o1
a00e77a4:  d6 03 c0 10  ld  [ %o7 + %l0 ], %o3
a00e77a8:  7f ff e3 eb  call  0xa00e0754
a00e77ac:  d4 07 40 10  ld  [ %i5 + %l0 ], %o2
a00e77b0:  80 a2 20 03  cmp  %o0, 3
a00e77b4:  12 bf ff 75  bne  0xa00e7588
a00e77b8:  90 10 00 18  mov  %i0, %o0
a00e77bc:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00e77c0:  96 13 22 e8  or  %o4, 0x2e8, %o3	! 0xa80266e8
a00e77c4:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e77c8:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00e77cc:  9a 12 62 f8  or  %o1, 0x2f8, %o5
a00e77d0:  d4 02 c0 10  ld  [ %o3 + %l0 ], %o2
a00e77d4:  82 13 e2 d8  or  %o7, 0x2d8, %g1
a00e77d8:  d2 03 40 10  ld  [ %o5 + %l0 ], %o1
a00e77dc:  7f ff e3 de  call  0xa00e0754
a00e77e0:  d6 00 40 10  ld  [ %g1 + %l0 ], %o3
a00e77e4:  80 a2 20 0f  cmp  %o0, 0xf
a00e77e8:  12 bf ff 68  bne  0xa00e7588
a00e77ec:  90 10 00 18  mov  %i0, %o0
a00e77f0:  10 bf ff c7  b  0xa00e770c
a00e77f4:  92 10 21 49  mov  0x149, %o1
a00e77f8:  90 10 00 18  mov  %i0, %o0
a00e77fc:  92 10 20 02  mov  2, %o1
a00e7800:  94 10 20 00  clr  %o2
a00e7804:  7f ff f2 1a  call  0xa00e406c
a00e7808:  96 10 24 00  mov  0x400, %o3
a00e780c:  80 a6 a0 03  cmp  %i2, 3
a00e7810:  02 80 00 ac  be  0xa00e7ac0
a00e7814:  80 a6 a0 04  cmp  %i2, 4
a00e7818:  02 80 01 12  be  0xa00e7c60
a00e781c:  80 a6 a0 03  cmp  %i2, 3
a00e7820:  02 80 00 c1  be  0xa00e7b24
a00e7824:  80 a6 a0 04  cmp  %i2, 4
a00e7828:  02 80 01 17  be  0xa00e7c84
a00e782c:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00e7830:  90 10 00 18  mov  %i0, %o0
a00e7834:  92 10 00 1a  mov  %i2, %o1
a00e7838:  7f ff f9 e4  call  0xa00e5fc8
a00e783c:  94 10 00 1b  mov  %i3, %o2
a00e7840:  80 a2 20 00  cmp  %o0, 0
a00e7844:  12 80 01 5f  bne  0xa00e7dc0
a00e7848:  80 a6 a0 03  cmp  %i2, 3
a00e784c:  02 80 01 15  be  0xa00e7ca0
a00e7850:  90 10 00 18  mov  %i0, %o0
a00e7854:  7f ff f1 f7  call  0xa00e4030
a00e7858:  23 00 00 07  sethi  %hi(0x1c00), %l1
a00e785c:  ba 14 63 f8  or  %l1, 0x3f8, %i5	! 0x1ff8
a00e7860:  96 0a 00 1d  and  %o0, %i5, %o3
a00e7864:  90 10 00 18  mov  %i0, %o0
a00e7868:  92 10 20 06  mov  6, %o1
a00e786c:  7f ff f2 00  call  0xa00e406c
a00e7870:  94 10 20 03  mov  3, %o2
a00e7874:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a00e7878:  90 10 00 18  mov  %i0, %o0
a00e787c:  7f ff e2 cd  call  0xa00e03b0
a00e7880:  92 10 20 54  mov  0x54, %o1
a00e7884:  90 10 00 18  mov  %i0, %o0
a00e7888:  d4 07 bf f0  ld  [ %fp + -16 ], %o2
a00e788c:  7f ff e2 c9  call  0xa00e03b0
a00e7890:  92 10 21 49  mov  0x149, %o1
a00e7894:  90 10 00 18  mov  %i0, %o0
a00e7898:  d4 07 bf ec  ld  [ %fp + -20 ], %o2
a00e789c:  7f ff e2 c5  call  0xa00e03b0
a00e78a0:  92 10 21 4b  mov  0x14b, %o1
a00e78a4:  90 10 00 18  mov  %i0, %o0
a00e78a8:  d4 07 bf e8  ld  [ %fp + -24 ], %o2
a00e78ac:  7f ff e2 c1  call  0xa00e03b0
a00e78b0:  92 10 21 4a  mov  0x14a, %o1
a00e78b4:  90 10 00 18  mov  %i0, %o0
a00e78b8:  d4 07 bf e4  ld  [ %fp + -28 ], %o2
a00e78bc:  7f ff e2 bd  call  0xa00e03b0
a00e78c0:  92 10 21 4c  mov  0x14c, %o1
a00e78c4:  90 10 00 18  mov  %i0, %o0
a00e78c8:  d4 07 bf e0  ld  [ %fp + -32 ], %o2
a00e78cc:  7f ff e2 b9  call  0xa00e03b0
a00e78d0:  92 10 21 42  mov  0x142, %o1
a00e78d4:  90 10 00 18  mov  %i0, %o0
a00e78d8:  d4 07 bf dc  ld  [ %fp + -36 ], %o2
a00e78dc:  7f ff e2 b5  call  0xa00e03b0
a00e78e0:  92 10 21 1a  mov  0x11a, %o1
a00e78e4:  90 10 00 18  mov  %i0, %o0
a00e78e8:  d4 07 bf d8  ld  [ %fp + -40 ], %o2
a00e78ec:  7f ff e2 b1  call  0xa00e03b0
a00e78f0:  92 10 21 21  mov  0x121, %o1
a00e78f4:  90 10 00 18  mov  %i0, %o0
a00e78f8:  d4 07 bf d4  ld  [ %fp + -44 ], %o2
a00e78fc:  7f ff e2 ad  call  0xa00e03b0
a00e7900:  92 10 21 02  mov  0x102, %o1
a00e7904:  da 07 a0 60  ld  [ %fp + 0x60 ], %o5
a00e7908:  80 a3 60 00  cmp  %o5, 0
a00e790c:  02 80 01 2d  be  0xa00e7dc0
a00e7910:  90 10 20 00  clr  %o0
a00e7914:  e4 07 a0 5c  ld  [ %fp + 0x5c ], %l2
a00e7918:  80 a4 a0 00  cmp  %l2, 0
a00e791c:  02 80 00 04  be  0xa00e792c
a00e7920:  90 10 00 18  mov  %i0, %o0
a00e7924:  a0 20 00 0d  neg  %o5, %l0
a00e7928:  e0 27 a0 60  st  %l0, [ %fp + 0x60 ]
a00e792c:  92 10 00 1b  mov  %i3, %o1
a00e7930:  7f ff f7 2f  call  0xa00e55ec
a00e7934:  d4 07 a0 60  ld  [ %fp + 0x60 ], %o2
a00e7938:  80 a2 20 00  cmp  %o0, 0
a00e793c:  12 80 01 21  bne  0xa00e7dc0
a00e7940:  01 00 00 00  nop
a00e7944:  10 80 01 1f  b  0xa00e7dc0
a00e7948:  90 10 20 00  clr  %o0	! 0x0
a00e794c:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e7950:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e7954:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00e7958:  92 12 e2 f8  or  %o3, 0x2f8, %o1
a00e795c:  99 37 20 04  srl  %i4, 4, %o4
a00e7960:  94 13 62 e8  or  %o5, 0x2e8, %o2
a00e7964:  96 13 e2 d8  or  %o7, 0x2d8, %o3
a00e7968:  98 03 3f ff  add  %o4, -1, %o4
a00e796c:  7f ff e3 82  call  0xa00e0774
a00e7970:  90 10 00 18  mov  %i0, %o0
a00e7974:  90 07 20 0d  add  %i4, 0xd, %o0
a00e7978:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e797c:  98 0a 20 0f  and  %o0, 0xf, %o4
a00e7980:  92 12 a2 98  or  %o2, 0x298, %o1
a00e7984:  35 2a 00 99  sethi  %hi(0xa8026400), %i2
a00e7988:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00e798c:  94 16 a2 88  or  %i2, 0x288, %o2
a00e7990:  90 10 00 18  mov  %i0, %o0
a00e7994:  7f ff e3 78  call  0xa00e0774
a00e7998:  96 10 62 78  or  %g1, 0x278, %o3
a00e799c:  96 0f 20 08  and  %i4, 8, %o3
a00e79a0:  93 32 e0 02  srl  %o3, 2, %o1
a00e79a4:  98 12 60 01  or  %o1, 1, %o4
a00e79a8:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e79ac:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00e79b0:  35 2a 00 99  sethi  %hi(0xa8026400), %i2
a00e79b4:  90 10 00 18  mov  %i0, %o0
a00e79b8:  92 13 62 c8  or  %o5, 0x2c8, %o1
a00e79bc:  94 13 e2 b8  or  %o7, 0x2b8, %o2
a00e79c0:  10 bf ff 2a  b  0xa00e7668
a00e79c4:  96 16 a2 a8  or  %i2, 0x2a8, %o3
a00e79c8:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00e79cc:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00e79d0:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00e79d4:  94 13 21 c8  or  %o4, 0x1c8, %o2
a00e79d8:  96 12 21 b8  or  %o0, 0x1b8, %o3
a00e79dc:  92 10 61 d8  or  %g1, 0x1d8, %o1
a00e79e0:  90 10 00 18  mov  %i0, %o0
a00e79e4:  7f ff e3 64  call  0xa00e0774
a00e79e8:  98 10 20 00  clr  %o4
a00e79ec:  3b 2a 00 99  sethi  %hi(0xa8026400), %i5
a00e79f0:  39 2a 00 99  sethi  %hi(0xa8026400), %i4
a00e79f4:  33 2a 00 99  sethi  %hi(0xa8026400), %i1
a00e79f8:  90 10 00 18  mov  %i0, %o0
a00e79fc:  92 17 61 a8  or  %i5, 0x1a8, %o1
a00e7a00:  94 17 21 98  or  %i4, 0x198, %o2
a00e7a04:  96 16 61 88  or  %i1, 0x188, %o3
a00e7a08:  7f ff e3 5b  call  0xa00e0774
a00e7a0c:  98 10 20 02  mov  2, %o4
a00e7a10:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00e7a14:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e7a18:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e7a1c:  90 10 00 18  mov  %i0, %o0
a00e7a20:  92 15 e1 78  or  %l7, 0x178, %o1
a00e7a24:  94 15 a1 68  or  %l6, 0x168, %o2
a00e7a28:  96 15 61 58  or  %l5, 0x158, %o3
a00e7a2c:  7f ff e3 52  call  0xa00e0774
a00e7a30:  98 10 20 00  clr  %o4
a00e7a34:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e7a38:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00e7a3c:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00e7a40:  90 10 00 18  mov  %i0, %o0
a00e7a44:  92 12 61 48  or  %o1, 0x148, %o1
a00e7a48:  94 15 21 38  or  %l4, 0x138, %o2
a00e7a4c:  96 14 e1 28  or  %l3, 0x128, %o3
a00e7a50:  7f ff e3 49  call  0xa00e0774
a00e7a54:  98 10 20 00  clr  %o4
a00e7a58:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00e7a5c:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00e7a60:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00e7a64:  90 10 00 18  mov  %i0, %o0
a00e7a68:  92 14 a2 f8  or  %l2, 0x2f8, %o1
a00e7a6c:  94 14 62 e8  or  %l1, 0x2e8, %o2
a00e7a70:  96 14 22 d8  or  %l0, 0x2d8, %o3
a00e7a74:  7f ff e3 40  call  0xa00e0774
a00e7a78:  98 10 20 00  clr  %o4
a00e7a7c:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e7a80:  92 12 a2 c8  or  %o2, 0x2c8, %o1	! 0xa80266c8
a00e7a84:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e7a88:  94 12 e2 b8  or  %o3, 0x2b8, %o2	! 0xa80266b8
a00e7a8c:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00e7a90:  90 10 00 18  mov  %i0, %o0
a00e7a94:  96 13 e2 a8  or  %o7, 0x2a8, %o3
a00e7a98:  7f ff e3 37  call  0xa00e0774
a00e7a9c:  98 10 20 01  mov  1, %o4
a00e7aa0:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e7aa4:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00e7aa8:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00e7aac:  90 10 00 18  mov  %i0, %o0
a00e7ab0:  92 13 62 98  or  %o5, 0x298, %o1
a00e7ab4:  94 10 62 88  or  %g1, 0x288, %o2
a00e7ab8:  10 bf fe 70  b  0xa00e7478
a00e7abc:  96 13 22 78  or  %o4, 0x278, %o3
a00e7ac0:  90 10 00 18  mov  %i0, %o0
a00e7ac4:  92 10 20 06  mov  6, %o1
a00e7ac8:  94 10 20 03  mov  3, %o2
a00e7acc:  7f ff f1 68  call  0xa00e406c
a00e7ad0:  96 10 20 04  mov  4, %o3
a00e7ad4:  90 10 00 18  mov  %i0, %o0
a00e7ad8:  92 10 21 42  mov  0x142, %o1
a00e7adc:  94 10 20 07  mov  7, %o2
a00e7ae0:  7f ff e2 be  call  0xa00e05d8
a00e7ae4:  96 10 20 00  clr  %o3
a00e7ae8:  90 10 00 18  mov  %i0, %o0
a00e7aec:  92 10 21 1a  mov  0x11a, %o1
a00e7af0:  94 10 20 70  mov  0x70, %o2
a00e7af4:  7f ff e2 b9  call  0xa00e05d8
a00e7af8:  96 10 20 00  clr  %o3
a00e7afc:  90 10 00 18  mov  %i0, %o0
a00e7b00:  92 10 21 21  mov  0x121, %o1
a00e7b04:  94 10 20 07  mov  7, %o2
a00e7b08:  7f ff e2 b4  call  0xa00e05d8
a00e7b0c:  96 10 20 00  clr  %o3
a00e7b10:  90 10 00 18  mov  %i0, %o0
a00e7b14:  92 10 21 02  mov  0x102, %o1
a00e7b18:  94 10 20 70  mov  0x70, %o2
a00e7b1c:  7f ff e2 af  call  0xa00e05d8
a00e7b20:  96 10 20 00  clr  %o3
a00e7b24:  90 10 00 18  mov  %i0, %o0
a00e7b28:  92 10 20 de  mov  0xde, %o1
a00e7b2c:  94 10 20 c0  mov  0xc0, %o2
a00e7b30:  7f ff e2 aa  call  0xa00e05d8
a00e7b34:  96 10 20 c0  mov  0xc0, %o3
a00e7b38:  96 10 20 c0  mov  0xc0, %o3
a00e7b3c:  90 10 00 18  mov  %i0, %o0
a00e7b40:  92 10 20 e1  mov  0xe1, %o1
a00e7b44:  7f ff e2 a5  call  0xa00e05d8
a00e7b48:  94 10 20 c0  mov  0xc0, %o2
a00e7b4c:  90 10 00 18  mov  %i0, %o0
a00e7b50:  92 10 21 49  mov  0x149, %o1
a00e7b54:  7f ff e2 17  call  0xa00e03b0
a00e7b58:  94 10 20 ff  mov  0xff, %o2
a00e7b5c:  90 10 00 18  mov  %i0, %o0
a00e7b60:  92 10 21 4a  mov  0x14a, %o1
a00e7b64:  7f ff e2 13  call  0xa00e03b0
a00e7b68:  94 10 20 00  clr  %o2
a00e7b6c:  90 10 00 18  mov  %i0, %o0
a00e7b70:  92 10 21 4c  mov  0x14c, %o1
a00e7b74:  7f ff e2 0f  call  0xa00e03b0
a00e7b78:  94 10 20 00  clr  %o2
a00e7b7c:  90 10 00 18  mov  %i0, %o0
a00e7b80:  92 10 22 41  mov  0x241, %o1
a00e7b84:  7f ff e2 64  call  0xa00e0514
a00e7b88:  94 10 20 1f  mov  0x1f, %o2
a00e7b8c:  a0 10 00 08  mov  %o0, %l0
a00e7b90:  90 10 00 18  mov  %i0, %o0
a00e7b94:  92 10 22 42  mov  0x242, %o1
a00e7b98:  7f ff e2 5f  call  0xa00e0514
a00e7b9c:  94 10 20 1f  mov  0x1f, %o2
a00e7ba0:  a2 10 00 08  mov  %o0, %l1
a00e7ba4:  90 10 00 18  mov  %i0, %o0
a00e7ba8:  92 10 22 40  mov  0x240, %o1
a00e7bac:  94 10 20 80  mov  0x80, %o2
a00e7bb0:  7f ff e2 8a  call  0xa00e05d8
a00e7bb4:  96 10 20 80  mov  0x80, %o3
a00e7bb8:  90 10 00 18  mov  %i0, %o0
a00e7bbc:  92 10 22 41  mov  0x241, %o1
a00e7bc0:  94 10 20 1f  mov  0x1f, %o2
a00e7bc4:  7f ff e2 85  call  0xa00e05d8
a00e7bc8:  96 10 20 1f  mov  0x1f, %o3
a00e7bcc:  90 10 00 18  mov  %i0, %o0
a00e7bd0:  92 10 22 42  mov  0x242, %o1
a00e7bd4:  94 10 20 1f  mov  0x1f, %o2
a00e7bd8:  7f ff e2 80  call  0xa00e05d8
a00e7bdc:  96 10 20 1f  mov  0x1f, %o3
a00e7be0:  10 bf ff 15  b  0xa00e7834
a00e7be4:  90 10 00 18  mov  %i0, %o0
a00e7be8:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00e7bec:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e7bf0:  92 13 22 f8  or  %o4, 0x2f8, %o1
a00e7bf4:  94 12 e2 e8  or  %o3, 0x2e8, %o2
a00e7bf8:  35 2a 00 99  sethi  %hi(0xa8026400), %i2
a00e7bfc:  96 16 a2 d8  or  %i2, 0x2d8, %o3	! 0xa80266d8
a00e7c00:  90 10 00 18  mov  %i0, %o0
a00e7c04:  7f ff e2 dc  call  0xa00e0774
a00e7c08:  99 37 20 04  srl  %i4, 4, %o4
a00e7c0c:  92 07 20 0d  add  %i4, 0xd, %o1
a00e7c10:  98 0a 60 0f  and  %o1, 0xf, %o4
a00e7c14:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e7c18:  92 12 a2 98  or  %o2, 0x298, %o1	! 0xa8026698
a00e7c1c:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00e7c20:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e7c24:  94 10 62 88  or  %g1, 0x288, %o2
a00e7c28:  90 10 00 18  mov  %i0, %o0
a00e7c2c:  7f ff e2 d2  call  0xa00e0774
a00e7c30:  96 13 62 78  or  %o5, 0x278, %o3
a00e7c34:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e7c38:  9e 0f 20 08  and  %i4, 8, %o7
a00e7c3c:  99 33 e0 02  srl  %o7, 2, %o4
a00e7c40:  35 2a 00 99  sethi  %hi(0xa8026400), %i2
a00e7c44:  94 12 e2 b8  or  %o3, 0x2b8, %o2
a00e7c48:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00e7c4c:  98 13 20 01  or  %o4, 1, %o4
a00e7c50:  90 10 00 18  mov  %i0, %o0
a00e7c54:  92 16 a2 c8  or  %i2, 0x2c8, %o1
a00e7c58:  10 bf fe 84  b  0xa00e7668
a00e7c5c:  96 10 62 a8  or  %g1, 0x2a8, %o3
a00e7c60:  7f ff f0 f4  call  0xa00e4030
a00e7c64:  90 10 00 18  mov  %i0, %o0
a00e7c68:  a6 0a 27 f8  and  %o0, 0x7f8, %l3
a00e7c6c:  96 14 e0 04  or  %l3, 4, %o3
a00e7c70:  90 10 00 18  mov  %i0, %o0
a00e7c74:  92 10 20 06  mov  6, %o1
a00e7c78:  7f ff f0 fd  call  0xa00e406c
a00e7c7c:  94 10 20 03  mov  3, %o2
a00e7c80:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00e7c84:  d6 0e 61 8b  ldub  [ %i1 + 0x18b ], %o3	! 0xa802698b
a00e7c88:  90 10 00 18  mov  %i0, %o0
a00e7c8c:  92 10 20 0b  mov  0xb, %o1
a00e7c90:  7f ff f0 f7  call  0xa00e406c
a00e7c94:  94 10 20 00  clr  %o2
a00e7c98:  10 bf fe e7  b  0xa00e7834
a00e7c9c:  90 10 00 18  mov  %i0, %o0
a00e7ca0:  92 10 20 de  mov  0xde, %o1
a00e7ca4:  94 10 20 c0  mov  0xc0, %o2
a00e7ca8:  7f ff e2 4c  call  0xa00e05d8
a00e7cac:  96 10 20 00  clr  %o3
a00e7cb0:  96 10 20 00  clr  %o3
a00e7cb4:  90 10 00 18  mov  %i0, %o0
a00e7cb8:  92 10 20 e1  mov  0xe1, %o1
a00e7cbc:  7f ff e2 47  call  0xa00e05d8
a00e7cc0:  94 10 20 c0  mov  0xc0, %o2
a00e7cc4:  90 10 00 18  mov  %i0, %o0
a00e7cc8:  92 10 21 49  mov  0x149, %o1
a00e7ccc:  7f ff e1 b9  call  0xa00e03b0
a00e7cd0:  94 10 20 00  clr  %o2
a00e7cd4:  90 10 00 18  mov  %i0, %o0
a00e7cd8:  92 10 21 4a  mov  0x14a, %o1
a00e7cdc:  7f ff e1 b5  call  0xa00e03b0
a00e7ce0:  94 10 20 00  clr  %o2
a00e7ce4:  90 10 00 18  mov  %i0, %o0
a00e7ce8:  92 10 21 4c  mov  0x14c, %o1
a00e7cec:  7f ff e1 b1  call  0xa00e03b0
a00e7cf0:  94 10 20 00  clr  %o2
a00e7cf4:  90 10 00 18  mov  %i0, %o0
a00e7cf8:  92 10 21 42  mov  0x142, %o1
a00e7cfc:  94 10 20 07  mov  7, %o2
a00e7d00:  7f ff e2 36  call  0xa00e05d8
a00e7d04:  96 10 20 01  mov  1, %o3
a00e7d08:  90 10 00 18  mov  %i0, %o0
a00e7d0c:  92 10 21 1a  mov  0x11a, %o1
a00e7d10:  94 10 20 70  mov  0x70, %o2
a00e7d14:  7f ff e2 31  call  0xa00e05d8
a00e7d18:  96 10 20 10  mov  0x10, %o3
a00e7d1c:  90 10 00 18  mov  %i0, %o0
a00e7d20:  92 10 21 21  mov  0x121, %o1
a00e7d24:  94 10 20 07  mov  7, %o2
a00e7d28:  7f ff e2 2c  call  0xa00e05d8
a00e7d2c:  96 10 20 01  mov  1, %o3
a00e7d30:  90 10 00 18  mov  %i0, %o0
a00e7d34:  92 10 21 02  mov  0x102, %o1
a00e7d38:  94 10 20 70  mov  0x70, %o2
a00e7d3c:  7f ff e2 27  call  0xa00e05d8
a00e7d40:  96 10 20 10  mov  0x10, %o3
a00e7d44:  90 10 00 18  mov  %i0, %o0
a00e7d48:  96 10 00 10  mov  %l0, %o3
a00e7d4c:  92 10 22 41  mov  0x241, %o1
a00e7d50:  7f ff e2 22  call  0xa00e05d8
a00e7d54:  94 10 20 1f  mov  0x1f, %o2
a00e7d58:  90 10 00 18  mov  %i0, %o0
a00e7d5c:  96 10 00 11  mov  %l1, %o3
a00e7d60:  92 10 22 42  mov  0x242, %o1
a00e7d64:  7f ff e2 1d  call  0xa00e05d8
a00e7d68:  94 10 20 1f  mov  0x1f, %o2
a00e7d6c:  7f ff e0 8a  call  0xa00dff94
a00e7d70:  90 10 20 01  mov  1, %o0
a00e7d74:  10 bf fe b8  b  0xa00e7854
a00e7d78:  90 10 00 18  mov  %i0, %o0
a00e7d7c:  7f ff de a4  call  0xa00df80c
a00e7d80:  01 00 00 00  nop
a00e7d84:  7f ff e3 8f  call  0xa00e0bc0
a00e7d88:  01 00 00 00  nop
a00e7d8c:  11 00 06 66  sethi  %hi(0x199800), %o0
a00e7d90:  7f ff dc f8  call  0xa00df170
a00e7d94:  90 12 22 58  or  %o0, 0x258, %o0	! 0x199a58
a00e7d98:  10 80 00 0a  b  0xa00e7dc0
a00e7d9c:  90 10 3f ff  mov  -1, %o0
a00e7da0:  7f ff de 9b  call  0xa00df80c
a00e7da4:  39 00 06 66  sethi  %hi(0x199800), %i4
a00e7da8:  7f ff e3 86  call  0xa00e0bc0
a00e7dac:  01 00 00 00  nop
a00e7db0:  7f ff dc f0  call  0xa00df170
a00e7db4:  90 17 22 90  or  %i4, 0x290, %o0
a00e7db8:  10 bf fe b0  b  0xa00e7878
a00e7dbc:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a00e7dc0:  81 c7 e0 08  ret
a00e7dc4:  91 e8 00 08  restore  %g0, %o0, %o0
