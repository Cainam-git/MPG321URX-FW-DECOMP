# leon2s DRV_HDMI_EQScan_FSM_PHY_RunAEQ 0xa007731c-0xa007769c (896 bytes)
a007731c:  9d e3 bf 98  save  %sp, -104, %sp
a0077320:  21 2a 01 e1  sethi  %hi(0xa8078400), %l0
a0077324:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1	! 0xa8078634
a0077328:  80 88 60 02  btst  2, %g1
a007732c:  a6 10 00 18  mov  %i0, %l3
a0077330:  02 80 00 3d  be  0xa0077424
a0077334:  a8 10 20 00  clr  %l4
a0077338:  92 06 20 41  add  %i0, 0x41, %o1
a007733c:  93 2a 60 18  sll  %o1, 0x18, %o1
a0077340:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a0077344:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a0077348:  90 12 21 70  or  %o0, 0x170, %o0
a007734c:  93 3a 60 18  sra  %o1, 0x18, %o1
a0077350:  7f ff ef 3d  call  0xa0073044
a0077354:  94 12 a0 f0  or  %o2, 0xf0, %o2
a0077358:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1
a007735c:  80 88 60 02  btst  2, %g1
a0077360:  02 80 00 31  be  0xa0077424
a0077364:  13 00 00 04  sethi  %hi(0x1000), %o1
a0077368:  92 12 61 48  or  %o1, 0x148, %o1	! 0x1148
a007736c:  40 00 bf ea  call  0xa00a7314
a0077370:  90 0e 20 ff  and  %i0, 0xff, %o0
a0077374:  97 32 20 10  srl  %o0, 0x10, %o3
a0077378:  92 06 20 41  add  %i0, 0x41, %o1
a007737c:  93 2a 60 18  sll  %o1, 0x18, %o1
a0077380:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a0077384:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a0077388:  90 12 23 30  or  %o0, 0x330, %o0
a007738c:  93 3a 60 18  sra  %o1, 0x18, %o1
a0077390:  94 12 a0 f0  or  %o2, 0xf0, %o2
a0077394:  7f ff ef 2c  call  0xa0073044
a0077398:  96 0a e0 0f  and  %o3, 0xf, %o3
a007739c:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1
a00773a0:  80 88 60 02  btst  2, %g1
a00773a4:  02 80 00 20  be  0xa0077424
a00773a8:  13 00 00 05  sethi  %hi(0x1400), %o1
a00773ac:  92 12 61 48  or  %o1, 0x148, %o1	! 0x1548
a00773b0:  40 00 bf d9  call  0xa00a7314
a00773b4:  90 0e 20 ff  and  %i0, 0xff, %o0
a00773b8:  97 32 20 10  srl  %o0, 0x10, %o3
a00773bc:  92 06 20 41  add  %i0, 0x41, %o1
a00773c0:  93 2a 60 18  sll  %o1, 0x18, %o1
a00773c4:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a00773c8:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a00773cc:  90 12 23 58  or  %o0, 0x358, %o0
a00773d0:  93 3a 60 18  sra  %o1, 0x18, %o1
a00773d4:  94 12 a0 f0  or  %o2, 0xf0, %o2
a00773d8:  7f ff ef 1b  call  0xa0073044
a00773dc:  96 0a e0 0f  and  %o3, 0xf, %o3
a00773e0:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1
a00773e4:  80 88 60 02  btst  2, %g1
a00773e8:  02 80 00 0f  be  0xa0077424
a00773ec:  13 00 00 06  sethi  %hi(0x1800), %o1
a00773f0:  92 12 61 48  or  %o1, 0x148, %o1	! 0x1948
a00773f4:  40 00 bf c8  call  0xa00a7314
a00773f8:  90 0e 20 ff  and  %i0, 0xff, %o0
a00773fc:  97 32 20 10  srl  %o0, 0x10, %o3
a0077400:  92 06 20 41  add  %i0, 0x41, %o1
a0077404:  93 2a 60 18  sll  %o1, 0x18, %o1
a0077408:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a007740c:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a0077410:  90 12 23 80  or  %o0, 0x380, %o0
a0077414:  93 3a 60 18  sra  %o1, 0x18, %o1
a0077418:  94 12 a0 f0  or  %o2, 0xf0, %o2
a007741c:  7f ff ef 0a  call  0xa0073044
a0077420:  96 0a e0 0f  and  %o3, 0xf, %o3
a0077424:  b0 0c e0 ff  and  %l3, 0xff, %i0
a0077428:  a4 0d 20 ff  and  %l4, 0xff, %l2
a007742c:  82 5e 22 26  smul  %i0, 0x226, %g1
a0077430:  82 00 40 12  add  %g1, %l2, %g1
a0077434:  2d 2a 01 ea  sethi  %hi(0xa807a800), %l6
a0077438:  83 28 60 02  sll  %g1, 2, %g1
a007743c:  9a 15 a1 f0  or  %l6, 0x1f0, %o5
a0077440:  82 00 40 0d  add  %g1, %o5, %g1
a0077444:  d6 10 68 86  lduh  [ %g1 + 0x886 ], %o3
a0077448:  80 a4 a0 02  cmp  %l2, 2
a007744c:  18 80 00 0e  bgu  0xa0077484
a0077450:  d8 08 68 84  ldub  [ %g1 + 0x884 ], %o4
a0077454:  97 2a e0 10  sll  %o3, 0x10, %o3
a0077458:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007745c:  98 0b 20 0f  and  %o4, 0xf, %o4
a0077460:  97 32 e0 08  srl  %o3, 8, %o3
a0077464:  9a 04 80 12  add  %l2, %l2, %o5
a0077468:  82 10 63 78  or  %g1, 0x378, %g1
a007746c:  15 3f c0 00  sethi  %hi(0xff000000), %o2
a0077470:  d2 10 40 0d  lduh  [ %g1 + %o5 ], %o1
a0077474:  96 13 00 0b  or  %o4, %o3, %o3
a0077478:  94 12 a0 f0  or  %o2, 0xf0, %o2
a007747c:  40 00 c0 03  call  0xa00a7488
a0077480:  90 10 00 18  mov  %i0, %o0
a0077484:  82 06 00 18  add  %i0, %i0, %g1
a0077488:  82 00 40 18  add  %g1, %i0, %g1
a007748c:  2b 2a 01 f3  sethi  %hi(0xa807cc00), %l5
a0077490:  83 28 60 02  sll  %g1, 2, %g1
a0077494:  9a 15 60 c4  or  %l5, 0xc4, %o5
a0077498:  82 00 40 0d  add  %g1, %o5, %g1
a007749c:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a00774a0:  80 a0 60 00  cmp  %g1, 0
a00774a4:  22 80 00 5c  be,a   0xa0077614
a00774a8:  a8 05 20 01  inc  %l4
a00774ac:  80 a4 a0 02  cmp  %l2, 2
a00774b0:  18 80 00 1d  bgu  0xa0077524
a00774b4:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00774b8:  82 10 63 0a  or  %g1, 0x30a, %g1	! 0xa00b3b0a
a00774bc:  a0 04 80 12  add  %l2, %l2, %l0
a00774c0:  e2 10 40 10  lduh  [ %g1 + %l0 ], %l1
a00774c4:  90 10 20 01  mov  1, %o0
a00774c8:  92 10 20 04  mov  4, %o1
a00774cc:  94 10 00 18  mov  %i0, %o2
a00774d0:  40 00 bf d5  call  0xa00a7424
a00774d4:  96 10 00 11  mov  %l1, %o3
a00774d8:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00774dc:  82 10 63 04  or  %g1, 0x304, %g1	! 0xa00b3b04
a00774e0:  e0 10 40 10  lduh  [ %g1 + %l0 ], %l0
a00774e4:  96 10 00 10  mov  %l0, %o3
a00774e8:  90 10 20 00  clr  %o0
a00774ec:  92 10 20 00  clr  %o1
a00774f0:  40 00 bf cd  call  0xa00a7424
a00774f4:  94 10 00 18  mov  %i0, %o2
a00774f8:  92 10 00 10  mov  %l0, %o1
a00774fc:  21 3f c0 3f  sethi  %hi(0xff00fc00), %l0
a0077500:  90 10 00 18  mov  %i0, %o0
a0077504:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0077508:  40 00 bf e0  call  0xa00a7488
a007750c:  17 00 0b 00  sethi  %hi(0x2c0000), %o3
a0077510:  90 10 00 18  mov  %i0, %o0
a0077514:  92 10 00 11  mov  %l1, %o1
a0077518:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007751c:  40 00 bf db  call  0xa00a7488
a0077520:  17 00 3f c0  sethi  %hi(0xff0000), %o3
a0077524:  40 00 e8 9c  call  0xa00b1794
a0077528:  90 10 20 01  mov  1, %o0
a007752c:  80 a4 a0 02  cmp  %l2, 2
a0077530:  18 80 00 10  bgu  0xa0077570
a0077534:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0077538:  82 10 63 04  or  %g1, 0x304, %g1	! 0xa00b3b04
a007753c:  a0 04 80 12  add  %l2, %l2, %l0
a0077540:  d6 10 40 10  lduh  [ %g1 + %l0 ], %o3
a0077544:  90 10 20 01  mov  1, %o0
a0077548:  92 10 20 00  clr  %o1
a007754c:  40 00 bf b6  call  0xa00a7424
a0077550:  94 10 00 18  mov  %i0, %o2
a0077554:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0077558:  82 10 63 0a  or  %g1, 0x30a, %g1	! 0xa00b3b0a
a007755c:  d6 10 40 10  lduh  [ %g1 + %l0 ], %o3
a0077560:  90 10 20 00  clr  %o0
a0077564:  92 10 20 04  mov  4, %o1
a0077568:  40 00 bf af  call  0xa00a7424
a007756c:  94 10 00 18  mov  %i0, %o2
a0077570:  7f ff ef ec  call  0xa0073520
a0077574:  90 10 00 18  mov  %i0, %o0
a0077578:  80 8a 20 ff  btst  0xff, %o0
a007757c:  02 80 00 13  be  0xa00775c8
a0077580:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0077584:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0077588:  82 10 60 58  or  %g1, 0x58, %g1	! 0xa807cc58
a007758c:  da 08 40 12  ldub  [ %g1 + %l2 ], %o5
a0077590:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0077594:  82 10 60 f8  or  %g1, 0xf8, %g1	! 0xa807ccf8
a0077598:  d8 08 40 12  ldub  [ %g1 + %l2 ], %o4
a007759c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00775a0:  82 10 62 d4  or  %g1, 0x2d4, %g1	! 0xa00b3ad4
a00775a4:  9b 2b 60 02  sll  %o5, 2, %o5
a00775a8:  da 00 40 0d  ld  [ %g1 + %o5 ], %o5
a00775ac:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00775b0:  99 2b 20 02  sll  %o4, 2, %o4
a00775b4:  82 10 62 cc  or  %g1, 0x2cc, %g1
a00775b8:  c2 00 40 0c  ld  [ %g1 + %o4 ], %g1
a00775bc:  98 10 00 0d  mov  %o5, %o4
a00775c0:  10 80 00 05  b  0xa00775d4
a00775c4:  96 10 00 01  mov  %g1, %o3
a00775c8:  d8 08 61 9e  ldub  [ %g1 + 0x19e ], %o4
a00775cc:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00775d0:  d6 10 61 9c  lduh  [ %g1 + 0x19c ], %o3	! 0xa807619c
a00775d4:  80 a4 a0 02  cmp  %l2, 2
a00775d8:  38 80 00 0f  bgu,a   0xa0077614
a00775dc:  a8 05 20 01  inc  %l4
a00775e0:  97 2a e0 10  sll  %o3, 0x10, %o3
a00775e4:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00775e8:  9a 04 80 12  add  %l2, %l2, %o5
a00775ec:  98 0b 20 0f  and  %o4, 0xf, %o4
a00775f0:  97 32 e0 08  srl  %o3, 8, %o3
a00775f4:  82 10 63 78  or  %g1, 0x378, %g1
a00775f8:  15 3f c0 00  sethi  %hi(0xff000000), %o2
a00775fc:  d2 10 40 0d  lduh  [ %g1 + %o5 ], %o1
a0077600:  96 13 00 0b  or  %o4, %o3, %o3
a0077604:  90 10 00 18  mov  %i0, %o0
a0077608:  40 00 bf a0  call  0xa00a7488
a007760c:  94 12 a0 f0  or  %o2, 0xf0, %o2
a0077610:  a8 05 20 01  inc  %l4
a0077614:  82 0d 20 ff  and  %l4, 0xff, %g1
a0077618:  80 a0 60 02  cmp  %g1, 2
a007761c:  08 bf ff 83  bleu  0xa0077428
a0077620:  b0 0c e0 ff  and  %l3, 0xff, %i0
a0077624:  90 0c e0 ff  and  %l3, 0xff, %o0
a0077628:  82 15 a1 f0  or  %l6, 0x1f0, %g1
a007762c:  9a 5a 28 98  smul  %o0, 0x898, %o5
a0077630:  98 03 40 01  add  %o5, %g1, %o4
a0077634:  c2 0b 20 28  ldub  [ %o4 + 0x28 ], %g1
a0077638:  80 a0 60 00  cmp  %g1, 0
a007763c:  c0 2b 20 30  clrb  [ %o4 + 0x30 ]
a0077640:  02 80 00 07  be  0xa007765c
a0077644:  1b 2a 01 d8  sethi  %hi(0xa8076000), %o5
a0077648:  9a 13 61 a0  or  %o5, 0x1a0, %o5	! 0xa80761a0
a007764c:  82 10 20 32  mov  0x32, %g1
a0077650:  c2 2b 40 08  stb  %g1, [ %o5 + %o0 ]
a0077654:  10 80 00 05  b  0xa0077668
a0077658:  c0 2b 20 28  clrb  [ %o4 + 0x28 ]
a007765c:  9a 13 61 a0  or  %o5, 0x1a0, %o5
a0077660:  82 10 20 06  mov  6, %g1
a0077664:  c2 2b 40 08  stb  %g1, [ %o5 + %o0 ]
a0077668:  82 02 00 08  add  %o0, %o0, %g1
a007766c:  82 00 40 08  add  %g1, %o0, %g1
a0077670:  9a 15 60 c4  or  %l5, 0xc4, %o5
a0077674:  91 28 60 02  sll  %g1, 2, %o0
a0077678:  82 02 00 0d  add  %o0, %o5, %g1
a007767c:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0077680:  80 a0 60 00  cmp  %g1, 0
a0077684:  22 80 00 03  be,a   0xa0077690
a0077688:  82 10 20 0f  mov  0xf, %g1
a007768c:  82 10 20 0b  mov  0xb, %g1
a0077690:  c2 23 40 08  st  %g1, [ %o5 + %o0 ]
a0077694:  81 c7 e0 08  ret
a0077698:  91 e8 20 00  restore  %g0, 0, %o0
