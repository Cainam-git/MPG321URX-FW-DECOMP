# leon2s DRV_HDMI_EQDetect_Timer 0xa0083324-0xa0083618 (756 bytes)
a0083324:  9d e3 bf 98  save  %sp, -104, %sp
a0083328:  15 00 00 07  sethi  %hi(0x1c00), %o2
a008332c:  94 12 a3 0c  or  %o2, 0x30c, %o2	! 0x1f0c
a0083330:  90 10 20 12  mov  0x12, %o0
a0083334:  40 00 90 4d  call  0xa00a7468
a0083338:  92 10 20 00  clr  %o1
a008333c:  80 a2 20 00  cmp  %o0, 0
a0083340:  a0 10 20 00  clr  %l0
a0083344:  12 80 00 ad  bne  0xa00835f8
a0083348:  a2 10 20 00  clr  %l1
a008334c:  b4 0c 20 ff  and  %l0, 0xff, %i2
a0083350:  82 06 80 1a  add  %i2, %i2, %g1
a0083354:  b2 00 40 1a  add  %g1, %i2, %i1
a0083358:  31 2a 01 f3  sethi  %hi(0xa807cc00), %i0
a008335c:  83 2e 60 03  sll  %i1, 3, %g1
a0083360:  9a 16 20 64  or  %i0, 0x64, %o5
a0083364:  b6 00 40 0d  add  %g1, %o5, %i3
a0083368:  c2 0e e0 02  ldub  [ %i3 + 2 ], %g1
a008336c:  80 a0 60 01  cmp  %g1, 1
a0083370:  12 80 00 18  bne  0xa00833d0
a0083374:  82 06 80 1a  add  %i2, %i2, %g1
a0083378:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a008337c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0083380:  80 88 60 02  btst  2, %g1
a0083384:  02 80 00 09  be  0xa00833a8
a0083388:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a008338c:  92 04 20 41  add  %l0, 0x41, %o1
a0083390:  93 2a 60 18  sll  %o1, 0x18, %o1
a0083394:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a0083398:  90 12 20 30  or  %o0, 0x30, %o0	! 0xa0068830
a008339c:  7f ff bf 2a  call  0xa0073044
a00833a0:  93 3a 60 18  sra  %o1, 0x18, %o1
a00833a4:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a00833a8:  83 2e 60 02  sll  %i1, 2, %g1
a00833ac:  9a 13 60 c4  or  %o5, 0xc4, %o5
a00833b0:  c0 23 40 01  clr  [ %o5 + %g1 ]
a00833b4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00833b8:  82 10 61 98  or  %g1, 0x198, %g1	! 0xa8078998
a00833bc:  c0 28 40 1a  clrb  [ %g1 + %i2 ]
a00833c0:  c0 2e e0 02  clrb  [ %i3 + 2 ]
a00833c4:  c0 36 e0 08  clrh  [ %i3 + 8 ]
a00833c8:  c0 2e e0 01  clrb  [ %i3 + 1 ]
a00833cc:  82 06 80 1a  add  %i2, %i2, %g1
a00833d0:  82 00 40 1a  add  %g1, %i2, %g1
a00833d4:  83 28 60 03  sll  %g1, 3, %g1
a00833d8:  9a 16 20 64  or  %i0, 0x64, %o5
a00833dc:  c2 0b 40 01  ldub  [ %o5 + %g1 ], %g1
a00833e0:  80 a0 60 00  cmp  %g1, 0
a00833e4:  22 80 00 81  be,a   0xa00835e8
a00833e8:  a0 04 20 01  inc  %l0
a00833ec:  7f ff c1 ff  call  0xa0073be8
a00833f0:  90 10 00 1a  mov  %i2, %o0
a00833f4:  7f ff c0 4b  call  0xa0073520
a00833f8:  90 10 00 1a  mov  %i2, %o0
a00833fc:  80 8a 20 ff  btst  0xff, %o0
a0083400:  02 80 00 38  be  0xa00834e0
a0083404:  03 33 c0 49  sethi  %hi(0xcf012400), %g1
a0083408:  80 a6 a0 02  cmp  %i2, 2
a008340c:  12 80 00 04  bne  0xa008341c
a0083410:  80 a6 a0 03  cmp  %i2, 3
a0083414:  10 80 00 04  b  0xa0083424
a0083418:  a2 10 20 00  clr  %l1
a008341c:  22 80 00 02  be,a   0xa0083424
a0083420:  a2 10 20 01  mov  1, %l1
a0083424:  b6 0c 60 ff  and  %l1, 0xff, %i3
a0083428:  15 00 00 07  sethi  %hi(0x1c00), %o2
a008342c:  94 12 a3 0c  or  %o2, 0x30c, %o2	! 0x1f0c
a0083430:  90 10 20 1f  mov  0x1f, %o0
a0083434:  40 00 90 0d  call  0xa00a7468
a0083438:  92 10 00 1b  mov  %i3, %o1
a008343c:  80 a2 20 00  cmp  %o0, 0
a0083440:  02 80 00 27  be  0xa00834dc
a0083444:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0083448:  82 10 62 80  or  %g1, 0x280, %g1	! 0xa807d680
a008344c:  9a 5e e0 b0  smul  %i3, 0xb0, %o5
a0083450:  9a 03 40 01  add  %o5, %g1, %o5
a0083454:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0083458:  b2 10 61 d0  or  %g1, 0x1d0, %i1	! 0xa80789d0
a008345c:  da 0b 60 01  ldub  [ %o5 + 1 ], %o5
a0083460:  92 0b 60 ff  and  %o5, 0xff, %o1
a0083464:  c2 0e 40 1b  ldub  [ %i1 + %i3 ], %g1
a0083468:  80 a2 40 01  cmp  %o1, %g1
a008346c:  02 80 00 14  be  0xa00834bc
a0083470:  80 a2 60 00  cmp  %o1, 0
a0083474:  02 80 00 12  be  0xa00834bc
a0083478:  da 2e 40 1b  stb  %o5, [ %i1 + %i3 ]
a008347c:  40 00 6d e9  call  0xa009ec20
a0083480:  90 10 00 1b  mov  %i3, %o0
a0083484:  90 10 00 1a  mov  %i2, %o0
a0083488:  7f ff f4 03  call  0xa0080494
a008348c:  d2 0e 40 1b  ldub  [ %i1 + %i3 ], %o1
a0083490:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0083494:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0083498:  80 88 60 02  btst  2, %g1
a008349c:  22 80 00 09  be,a   0xa00834c0
a00834a0:  11 2a 01 e2  sethi  %hi(0xa8078800), %o0
a00834a4:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a00834a8:  13 28 02 d0  sethi  %hi(0xa00b4000), %o1
a00834ac:  d4 0e 40 1b  ldub  [ %i1 + %i3 ], %o2
a00834b0:  90 12 20 68  or  %o0, 0x68, %o0
a00834b4:  7f ff be e4  call  0xa0073044
a00834b8:  92 12 60 18  or  %o1, 0x18, %o1
a00834bc:  11 2a 01 e2  sethi  %hi(0xa8078800), %o0
a00834c0:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00834c4:  90 12 21 d4  or  %o0, 0x1d4, %o0
a00834c8:  c2 00 61 90  ld  [ %g1 + 0x190 ], %g1
a00834cc:  40 00 bb 32  call  0xa00b2194
a00834d0:  c2 22 20 04  st  %g1, [ %o0 + 4 ]
a00834d4:  10 80 00 45  b  0xa00835e8
a00834d8:  a0 04 20 01  inc  %l0
a00834dc:  03 33 c0 49  sethi  %hi(0xcf012400), %g1
a00834e0:  82 10 60 a4  or  %g1, 0xa4, %g1	! 0xcf0124a4
a00834e4:  c2 00 40 00  ld  [ %g1 ], %g1
a00834e8:  82 08 60 07  and  %g1, 7, %g1
a00834ec:  80 a0 60 04  cmp  %g1, 4
a00834f0:  12 80 00 16  bne  0xa0083548
a00834f4:  33 00 00 07  sethi  %hi(0x1c00), %i1
a00834f8:  92 16 63 04  or  %i1, 0x304, %o1	! 0x1f04
a00834fc:  90 10 20 00  clr  %o0
a0083500:  94 10 3f 00  mov  -256, %o2
a0083504:  40 00 8f e1  call  0xa00a7488
a0083508:  96 10 20 2f  mov  0x2f, %o3
a008350c:  92 16 63 04  or  %i1, 0x304, %o1
a0083510:  90 10 20 01  mov  1, %o0
a0083514:  94 10 3f 00  mov  -256, %o2
a0083518:  40 00 8f dc  call  0xa00a7488
a008351c:  96 10 20 2f  mov  0x2f, %o3
a0083520:  92 16 63 04  or  %i1, 0x304, %o1
a0083524:  90 10 20 02  mov  2, %o0
a0083528:  94 10 3f 00  mov  -256, %o2
a008352c:  40 00 8f d7  call  0xa00a7488
a0083530:  96 10 20 2f  mov  0x2f, %o3
a0083534:  b2 16 63 04  or  %i1, 0x304, %i1
a0083538:  b0 10 20 03  mov  3, %i0
a008353c:  b4 10 3f 00  mov  -256, %i2
a0083540:  40 00 8f d2  call  0xa00a7488
a0083544:  97 e8 20 2f  restore  %g0, 0x2f, %o3
a0083548:  7f ff de a5  call  0xa007afdc
a008354c:  90 10 00 1a  mov  %i2, %o0
a0083550:  82 06 80 1a  add  %i2, %i2, %g1
a0083554:  98 00 40 1a  add  %g1, %i2, %o4
a0083558:  83 2b 20 03  sll  %o4, 3, %g1
a008355c:  9a 16 20 64  or  %i0, 0x64, %o5
a0083560:  9a 00 40 0d  add  %g1, %o5, %o5
a0083564:  c2 0b 60 03  ldub  [ %o5 + 3 ], %g1
a0083568:  80 a0 60 00  cmp  %g1, 0
a008356c:  22 80 00 1f  be,a   0xa00835e8
a0083570:  a0 04 20 01  inc  %l0
a0083574:  c2 0b 60 01  ldub  [ %o5 + 1 ], %g1
a0083578:  80 a0 60 01  cmp  %g1, 1
a008357c:  12 80 00 06  bne  0xa0083594
a0083580:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0083584:  7f ff c6 a6  call  0xa007501c
a0083588:  90 10 00 1a  mov  %i2, %o0
a008358c:  10 80 00 17  b  0xa00835e8
a0083590:  a0 04 20 01  inc  %l0
a0083594:  b2 10 60 c4  or  %g1, 0xc4, %i1
a0083598:  b7 2b 20 02  sll  %o4, 2, %i3
a008359c:  c2 06 40 1b  ld  [ %i1 + %i3 ], %g1
a00835a0:  80 a0 60 10  cmp  %g1, 0x10
a00835a4:  12 80 00 0e  bne  0xa00835dc
a00835a8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00835ac:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a00835b0:  80 88 60 02  btst  2, %g1
a00835b4:  22 80 00 0a  be,a   0xa00835dc
a00835b8:  c0 26 40 1b  clr  [ %i1 + %i3 ]
a00835bc:  92 04 20 41  add  %l0, 0x41, %o1
a00835c0:  93 2a 60 18  sll  %o1, 0x18, %o1
a00835c4:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a00835c8:  90 12 20 98  or  %o0, 0x98, %o0	! 0xa0068898
a00835cc:  93 3a 60 18  sra  %o1, 0x18, %o1
a00835d0:  7f ff be 9d  call  0xa0073044
a00835d4:  94 10 22 37  mov  0x237, %o2
a00835d8:  c0 26 40 1b  clr  [ %i1 + %i3 ]
a00835dc:  7f ff d7 a1  call  0xa0079460
a00835e0:  90 10 00 1a  mov  %i2, %o0
a00835e4:  a0 04 20 01  inc  %l0
a00835e8:  82 0c 20 ff  and  %l0, 0xff, %g1
a00835ec:  80 a0 60 03  cmp  %g1, 3
a00835f0:  28 bf ff 58  bleu,a   0xa0083350
a00835f4:  b4 0c 20 ff  and  %l0, 0xff, %i2
a00835f8:  31 2a 01 e2  sethi  %hi(0xa8078800), %i0
a00835fc:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0083600:  b0 16 21 d4  or  %i0, 0x1d4, %i0
a0083604:  c2 00 61 90  ld  [ %g1 + 0x190 ], %g1
a0083608:  c2 26 20 04  st  %g1, [ %i0 + 4 ]
a008360c:  40 00 ba e2  call  0xa00b2194
a0083610:  81 e8 00 00  restore
a0083614:  01 00 00 00  nop
