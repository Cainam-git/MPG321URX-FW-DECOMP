# leon2s FUN_a00c9398 0xa00c9398-0xa00c966c (724 bytes)
a00c9398:  9d e3 bf 90  save  %sp, -112, %sp
a00c939c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c93a0:  96 04 00 10  add  %l0, %l0, %o3
a00c93a4:  96 02 c0 10  add  %o3, %l0, %o3
a00c93a8:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a00c93ac:  97 2a e0 03  sll  %o3, 3, %o3
a00c93b0:  94 14 63 b0  or  %l1, 0x3b0, %o2
a00c93b4:  c2 02 80 0b  ld  [ %o2 + %o3 ], %g1
a00c93b8:  19 00 00 c0  sethi  %hi(0x30000), %o4
a00c93bc:  98 28 40 0c  andn  %g1, %o4, %o4
a00c93c0:  9b 2c 20 03  sll  %l0, 3, %o5
a00c93c4:  9a 23 40 10  sub  %o5, %l0, %o5
a00c93c8:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c93cc:  82 10 61 80  or  %g1, 0x180, %g1	! 0xa807d580
a00c93d0:  9b 2b 60 02  sll  %o5, 2, %o5
a00c93d4:  9a 03 40 01  add  %o5, %g1, %o5
a00c93d8:  03 00 00 40  sethi  %hi(0x10000), %g1
a00c93dc:  98 13 00 01  or  %o4, %g1, %o4
a00c93e0:  c2 0b 60 01  ldub  [ %o5 + 1 ], %g1
a00c93e4:  d8 22 80 0b  st  %o4, [ %o2 + %o3 ]
a00c93e8:  80 a0 60 41  cmp  %g1, 0x41
a00c93ec:  02 80 00 09  be  0xa00c9410
a00c93f0:  a6 10 20 00  clr  %l3
a00c93f4:  80 a0 60 41  cmp  %g1, 0x41
a00c93f8:  04 80 00 07  ble  0xa00c9414
a00c93fc:  80 a0 60 51  cmp  %g1, 0x51
a00c9400:  02 80 00 05  be  0xa00c9414
a00c9404:  80 a0 60 61  cmp  %g1, 0x61
a00c9408:  12 80 00 03  bne  0xa00c9414
a00c940c:  01 00 00 00  nop
a00c9410:  a6 10 20 01  mov  1, %l3	! 0x1
a00c9414:  7f ff ff d5  call  0xa00c9368
a00c9418:  90 10 00 10  mov  %l0, %o0
a00c941c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c9420:  80 a2 20 01  cmp  %o0, 1
a00c9424:  12 80 00 45  bne  0xa00c9538
a00c9428:  01 00 00 00  nop
a00c942c:  7f ff ff d1  call  0xa00c9370
a00c9430:  90 10 00 10  mov  %l0, %o0
a00c9434:  80 8a 20 ff  btst  0xff, %o0
a00c9438:  12 80 00 40  bne  0xa00c9538
a00c943c:  90 10 00 10  mov  %l0, %o0
a00c9440:  7f ff fd 5e  call  0xa00c89b8
a00c9444:  92 10 20 01  mov  1, %o1
a00c9448:  82 04 00 10  add  %l0, %l0, %g1
a00c944c:  82 00 40 10  add  %g1, %l0, %g1
a00c9450:  a4 14 63 b0  or  %l1, 0x3b0, %l2
a00c9454:  a3 28 60 03  sll  %g1, 3, %l1
a00c9458:  c2 04 80 11  ld  [ %l2 + %l1 ], %g1
a00c945c:  83 30 60 1c  srl  %g1, 0x1c, %g1
a00c9460:  80 88 60 01  btst  1, %g1
a00c9464:  12 80 00 22  bne  0xa00c94ec
a00c9468:  90 10 00 10  mov  %l0, %o0
a00c946c:  7f ff f9 e3  call  0xa00c7bf8
a00c9470:  90 10 00 10  mov  %l0, %o0
a00c9474:  80 8a 20 ff  btst  0xff, %o0
a00c9478:  02 80 00 07  be  0xa00c9494
a00c947c:  90 10 00 10  mov  %l0, %o0
a00c9480:  c2 04 80 11  ld  [ %l2 + %l1 ], %g1
a00c9484:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00c9488:  82 10 40 0d  or  %g1, %o5, %g1
a00c948c:  10 80 00 39  b  0xa00c9570
a00c9490:  c2 24 80 11  st  %g1, [ %l2 + %l1 ]
a00c9494:  7f ff fb 92  call  0xa00c82dc
a00c9498:  92 07 bf f0  add  %fp, -16, %o1
a00c949c:  80 8a 20 ff  btst  0xff, %o0
a00c94a0:  02 80 00 0a  be  0xa00c94c8
a00c94a4:  c2 0f bf f1  ldub  [ %fp + -15 ], %g1
a00c94a8:  90 10 00 10  mov  %l0, %o0
a00c94ac:  7f ff fd 43  call  0xa00c89b8
a00c94b0:  92 10 20 00  clr  %o1
a00c94b4:  c2 04 80 11  ld  [ %l2 + %l1 ], %g1
a00c94b8:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00c94bc:  82 10 40 0d  or  %g1, %o5, %g1
a00c94c0:  10 80 00 68  b  0xa00c9660
a00c94c4:  c2 24 80 11  st  %g1, [ %l2 + %l1 ]
a00c94c8:  80 88 60 10  btst  0x10, %g1
a00c94cc:  02 80 00 08  be  0xa00c94ec
a00c94d0:  90 10 00 10  mov  %l0, %o0
a00c94d4:  92 10 20 00  clr  %o1
a00c94d8:  94 10 21 2f  mov  0x12f, %o2
a00c94dc:  96 10 20 01  mov  1, %o3
a00c94e0:  40 3b ba fb  call  0xa0fb80cc
a00c94e4:  98 10 20 01  mov  1, %o4
a00c94e8:  90 10 00 10  mov  %l0, %o0
a00c94ec:  7f ff fd 4c  call  0xa00c8a1c
a00c94f0:  92 10 20 01  mov  1, %o1
a00c94f4:  90 10 00 10  mov  %l0, %o0
a00c94f8:  92 10 20 00  clr  %o1
a00c94fc:  94 10 20 71  mov  0x71, %o2
a00c9500:  40 3b ba d5  call  0xa0fb8054
a00c9504:  96 10 20 ff  mov  0xff, %o3
a00c9508:  90 10 00 10  mov  %l0, %o0
a00c950c:  92 10 20 00  clr  %o1
a00c9510:  94 10 20 72  mov  0x72, %o2
a00c9514:  40 3b ba d0  call  0xa0fb8054
a00c9518:  96 10 20 ff  mov  0xff, %o3
a00c951c:  90 10 00 10  mov  %l0, %o0
a00c9520:  92 10 20 00  clr  %o1
a00c9524:  94 10 20 73  mov  0x73, %o2
a00c9528:  40 3b ba cb  call  0xa0fb8054
a00c952c:  96 10 20 ff  mov  0xff, %o3
a00c9530:  10 80 00 13  b  0xa00c957c
a00c9534:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00c9538:  7f ff ff 8c  call  0xa00c9368
a00c953c:  90 10 00 10  mov  %l0, %o0
a00c9540:  80 8a 20 ff  btst  0xff, %o0
a00c9544:  32 80 00 0e  bne,a   0xa00c957c
a00c9548:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00c954c:  7f ff ff 89  call  0xa00c9370
a00c9550:  90 10 00 10  mov  %l0, %o0
a00c9554:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c9558:  80 a2 20 01  cmp  %o0, 1
a00c955c:  12 80 00 41  bne  0xa00c9660
a00c9560:  90 10 00 10  mov  %l0, %o0
a00c9564:  7f ff fd 2e  call  0xa00c8a1c
a00c9568:  92 10 20 00  clr  %o1
a00c956c:  90 10 00 10  mov  %l0, %o0
a00c9570:  7f ff fd 12  call  0xa00c89b8
a00c9574:  92 10 20 00  clr  %o1
a00c9578:  30 80 00 3a  b,a   0xa00c9660
a00c957c:  90 10 00 10  mov  %l0, %o0
a00c9580:  40 3b b3 ff  call  0xa0fb657c
a00c9584:  92 10 20 71  mov  0x71, %o1
a00c9588:  80 8a 20 02  btst  2, %o0
a00c958c:  02 80 00 0c  be  0xa00c95bc
a00c9590:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c9594:  98 06 00 18  add  %i0, %i0, %o4
a00c9598:  98 03 00 18  add  %o4, %i0, %o4
a00c959c:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00c95a0:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00c95a4:  99 2b 20 03  sll  %o4, 3, %o4
a00c95a8:  c2 02 c0 0c  ld  [ %o3 + %o4 ], %g1
a00c95ac:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00c95b0:  82 10 40 0d  or  %g1, %o5, %g1
a00c95b4:  10 80 00 2b  b  0xa00c9660
a00c95b8:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00c95bc:  90 10 00 18  mov  %i0, %o0
a00c95c0:  92 10 20 00  clr  %o1
a00c95c4:  40 3b ba 85  call  0xa0fb7fd8
a00c95c8:  94 10 20 73  mov  0x73, %o2
a00c95cc:  80 8a 20 f0  btst  0xf0, %o0
a00c95d0:  02 80 00 24  be  0xa00c9660
a00c95d4:  90 10 00 18  mov  %i0, %o0
a00c95d8:  92 10 20 00  clr  %o1
a00c95dc:  94 10 20 71  mov  0x71, %o2
a00c95e0:  40 3b ba 9d  call  0xa0fb8054
a00c95e4:  96 10 20 ff  mov  0xff, %o3
a00c95e8:  90 10 00 18  mov  %i0, %o0
a00c95ec:  92 10 20 00  clr  %o1
a00c95f0:  94 10 20 72  mov  0x72, %o2
a00c95f4:  40 3b ba 98  call  0xa0fb8054
a00c95f8:  96 10 20 ff  mov  0xff, %o3
a00c95fc:  90 10 00 18  mov  %i0, %o0
a00c9600:  92 10 20 00  clr  %o1
a00c9604:  94 10 20 73  mov  0x73, %o2
a00c9608:  40 3b ba 93  call  0xa0fb8054
a00c960c:  96 10 20 ff  mov  0xff, %o3
a00c9610:  98 06 00 18  add  %i0, %i0, %o4
a00c9614:  98 03 00 18  add  %o4, %i0, %o4
a00c9618:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00c961c:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00c9620:  99 2b 20 03  sll  %o4, 3, %o4
a00c9624:  d4 02 c0 0c  ld  [ %o3 + %o4 ], %o2
a00c9628:  83 32 a0 18  srl  %o2, 0x18, %g1
a00c962c:  82 08 60 0f  and  %g1, 0xf, %g1
a00c9630:  82 00 7f ff  add  %g1, -1, %g1
a00c9634:  82 08 60 0f  and  %g1, 0xf, %g1
a00c9638:  1b 03 c0 00  sethi  %hi(0xf000000), %o5
a00c963c:  83 28 60 18  sll  %g1, 0x18, %g1
a00c9640:  9a 2a 80 0d  andn  %o2, %o5, %o5
a00c9644:  9a 13 40 01  or  %o5, %g1, %o5
a00c9648:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00c964c:  9a 13 40 01  or  %o5, %g1, %o5
a00c9650:  da 22 c0 0c  st  %o5, [ %o3 + %o4 ]
a00c9654:  90 10 00 10  mov  %l0, %o0
a00c9658:  40 3b b3 c9  call  0xa0fb657c
a00c965c:  92 10 20 2e  mov  0x2e, %o1
a00c9660:  01 00 00 00  nop
a00c9664:  81 c7 e0 08  ret
a00c9668:  81 e8 00 00  restore
