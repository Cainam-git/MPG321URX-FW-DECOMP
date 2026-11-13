# leon2s FUN_a008743c 0xa008743c-0xa00876ec (688 bytes)
a008743c:  9d e3 bf 90  save  %sp, -112, %sp
a0087440:  a8 10 20 00  clr  %l4
a0087444:  80 8e 20 ff  btst  0xff, %i0
a0087448:  c0 2f bf f7  clrb  [ %fp + -9 ]
a008744c:  c0 2f bf f6  clrb  [ %fp + -10 ]
a0087450:  ac 10 00 14  mov  %l4, %l6
a0087454:  b0 10 20 01  mov  1, %i0
a0087458:  02 80 00 06  be  0xa0087470
a008745c:  aa 10 20 00  clr  %l5
a0087460:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0087464:  ec 08 61 c0  ldub  [ %g1 + 0x1c0 ], %l6	! 0xa80761c0
a0087468:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a008746c:  ea 08 61 bf  ldub  [ %g1 + 0x1bf ], %l5	! 0xa80761bf
a0087470:  a8 0d a0 ff  and  %l6, 0xff, %l4
a0087474:  ae 0d 60 ff  and  %l5, 0xff, %l7
a0087478:  a4 10 00 16  mov  %l6, %l2
a008747c:  80 a5 00 17  cmp  %l4, %l7
a0087480:  9a 10 00 14  mov  %l4, %o5
a0087484:  18 80 00 32  bgu  0xa008754c
a0087488:  82 03 40 0d  add  %o5, %o5, %g1
a008748c:  82 00 40 0d  add  %g1, %o5, %g1
a0087490:  98 00 40 01  add  %g1, %g1, %o4
a0087494:  c2 0e c0 00  ldub  [ %i3 ], %g1
a0087498:  83 38 40 0d  sra  %g1, %o5, %g1
a008749c:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00874a0:  9b 2b 60 04  sll  %o5, 4, %o5
a00874a4:  90 10 00 11  mov  %l1, %o0
a00874a8:  a4 04 a0 01  inc  %l2
a00874ac:  80 88 60 01  btst  1, %g1
a00874b0:  a6 06 80 0d  add  %i2, %o5, %l3
a00874b4:  02 80 00 23  be  0xa0087540
a00874b8:  a0 10 20 03  mov  3, %l0
a00874bc:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00874c0:  82 10 61 2e  or  %g1, 0x12e, %g1	! 0xa807cd2e
a00874c4:  da 08 40 0c  ldub  [ %g1 + %o4 ], %o5
a00874c8:  83 33 60 06  srl  %o5, 6, %g1
a00874cc:  82 08 60 01  and  %g1, 1, %g1
a00874d0:  80 8b 60 20  btst  0x20, %o5
a00874d4:  12 80 00 04  bne  0xa00874e4
a00874d8:  9a 18 60 01  xor  %g1, 1, %o5
a00874dc:  82 10 20 02  mov  2, %g1
a00874e0:  a0 20 40 0d  sub  %g1, %o5, %l0
a00874e4:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00874e8:  40 00 8d 12  call  0xa00aa930
a00874ec:  92 10 00 10  mov  %l0, %o1
a00874f0:  90 10 00 13  mov  %l3, %o0
a00874f4:  d2 0e 40 00  ldub  [ %i1 ], %o1
a00874f8:  94 07 bf f7  add  %fp, -9, %o2
a00874fc:  7f ff fe ad  call  0xa0086fb0
a0087500:  96 07 bf f6  add  %fp, -10, %o3
a0087504:  90 10 00 11  mov  %l1, %o0
a0087508:  92 10 00 10  mov  %l0, %o1
a008750c:  d4 0e 40 00  ldub  [ %i1 ], %o2
a0087510:  d6 0f bf f7  ldub  [ %fp + -9 ], %o3
a0087514:  7f ff fb c6  call  0xa008642c
a0087518:  d8 0f bf f6  ldub  [ %fp + -10 ], %o4
a008751c:  82 10 20 01  mov  1, %g1
a0087520:  80 8a 20 ff  btst  0xff, %o0
a0087524:  12 80 00 07  bne  0xa0087540
a0087528:  9b 28 40 11  sll  %g1, %l1, %o5
a008752c:  c2 0e c0 00  ldub  [ %i3 ], %g1
a0087530:  82 28 40 0d  andn  %g1, %o5, %g1
a0087534:  80 a4 60 00  cmp  %l1, 0
a0087538:  02 80 00 27  be  0xa00875d4
a008753c:  c2 2e c0 00  stb  %g1, [ %i3 ]
a0087540:  9a 0c a0 ff  and  %l2, 0xff, %o5
a0087544:  10 bf ff d0  b  0xa0087484
a0087548:  80 a3 40 17  cmp  %o5, %l7
a008754c:  9a 10 00 14  mov  %l4, %o5
a0087550:  aa 0d 60 ff  and  %l5, 0xff, %l5
a0087554:  a4 10 00 16  mov  %l6, %l2
a0087558:  80 a3 40 15  cmp  %o5, %l5
a008755c:  38 80 00 62  bgu,a   0xa00876e4
a0087560:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0087564:  c2 0e c0 00  ldub  [ %i3 ], %g1
a0087568:  83 38 40 0d  sra  %g1, %o5, %g1
a008756c:  80 88 60 01  btst  1, %g1
a0087570:  22 80 00 5b  be,a   0xa00876dc
a0087574:  a4 04 a0 01  inc  %l2
a0087578:  83 2b 60 04  sll  %o5, 4, %g1
a008757c:  a6 06 80 01  add  %i2, %g1, %l3
a0087580:  a8 10 20 01  mov  1, %l4
a0087584:  a2 0c a0 ff  and  %l2, 0xff, %l1
a0087588:  82 04 40 11  add  %l1, %l1, %g1
a008758c:  82 00 40 11  add  %g1, %l1, %g1
a0087590:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a0087594:  9a 13 61 2e  or  %o5, 0x12e, %o5	! 0xa807cd2e
a0087598:  82 00 40 01  add  %g1, %g1, %g1
a008759c:  82 00 40 0d  add  %g1, %o5, %g1
a00875a0:  40 00 a8 7d  call  0xa00b1794
a00875a4:  d0 08 60 05  ldub  [ %g1 + 5 ], %o0
a00875a8:  92 10 00 13  mov  %l3, %o1
a00875ac:  7f ff fe 2b  call  0xa0086e58
a00875b0:  90 10 00 11  mov  %l1, %o0
a00875b4:  c2 0c c0 00  ldub  [ %l3 ], %g1
a00875b8:  92 10 00 13  mov  %l3, %o1
a00875bc:  80 88 60 80  btst  0x80, %g1
a00875c0:  12 80 00 07  bne  0xa00875dc
a00875c4:  a8 05 20 01  inc  %l4
a00875c8:  80 a4 60 00  cmp  %l1, 0
a00875cc:  32 80 00 44  bne,a   0xa00876dc
a00875d0:  a4 04 a0 01  inc  %l2
a00875d4:  10 80 00 44  b  0xa00876e4
a00875d8:  b0 10 20 02  mov  2, %i0
a00875dc:  e0 0e 40 00  ldub  [ %i1 ], %l0
a00875e0:  7f ff ff 61  call  0xa0087364
a00875e4:  90 10 00 10  mov  %l0, %o0
a00875e8:  b0 10 00 08  mov  %o0, %i0
a00875ec:  92 10 00 10  mov  %l0, %o1
a00875f0:  82 06 3f f8  add  %i0, -8, %g1
a00875f4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00875f8:  96 07 bf f6  add  %fp, -10, %o3
a00875fc:  90 10 00 13  mov  %l3, %o0
a0087600:  94 07 bf f7  add  %fp, -9, %o2
a0087604:  82 08 60 ff  and  %g1, 0xff, %g1
a0087608:  80 a4 20 05  cmp  %l0, 5
a008760c:  02 80 00 33  be  0xa00876d8
a0087610:  9a 0d 20 ff  and  %l4, 0xff, %o5
a0087614:  80 a0 60 01  cmp  %g1, 1
a0087618:  18 80 00 10  bgu  0xa0087658
a008761c:  80 a3 60 05  cmp  %o5, 5
a0087620:  80 a4 60 00  cmp  %l1, 0
a0087624:  12 80 00 11  bne  0xa0087668
a0087628:  82 10 20 01  mov  1, %g1
a008762c:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a0087630:  7f ff af a5  call  0xa00734c4
a0087634:  90 12 21 98  or  %o0, 0x198, %o0	! 0xa0068998
a0087638:  7f ff fe 8f  call  0xa0087074
a008763c:  90 10 20 00  clr  %o0
a0087640:  90 0a 20 ff  and  %o0, 0xff, %o0
a0087644:  80 a2 20 01  cmp  %o0, 1
a0087648:  12 80 00 27  bne  0xa00876e4
a008764c:  b0 10 20 08  mov  8, %i0
a0087650:  10 80 00 25  b  0xa00876e4
a0087654:  b0 10 00 10  mov  %l0, %i0
a0087658:  08 80 00 11  bleu  0xa008769c
a008765c:  80 a4 60 00  cmp  %l1, 0
a0087660:  02 80 00 07  be  0xa008767c
a0087664:  82 10 20 01  mov  1, %g1
a0087668:  da 0e c0 00  ldub  [ %i3 ], %o5
a008766c:  83 28 40 11  sll  %g1, %l1, %g1
a0087670:  82 2b 40 01  andn  %o5, %g1, %g1
a0087674:  10 80 00 19  b  0xa00876d8
a0087678:  c2 2e c0 00  stb  %g1, [ %i3 ]
a008767c:  7f ff fe 7e  call  0xa0087074
a0087680:  90 10 20 00  clr  %o0
a0087684:  90 0a 20 ff  and  %o0, 0xff, %o0
a0087688:  80 a2 20 01  cmp  %o0, 1
a008768c:  12 80 00 16  bne  0xa00876e4
a0087690:  b0 10 20 08  mov  8, %i0
a0087694:  10 80 00 14  b  0xa00876e4
a0087698:  b0 10 20 09  mov  9, %i0
a008769c:  7f ff fe 45  call  0xa0086fb0
a00876a0:  01 00 00 00  nop
a00876a4:  90 10 00 11  mov  %l1, %o0
a00876a8:  d2 0f bf f6  ldub  [ %fp + -10 ], %o1
a00876ac:  40 00 8e 3a  call  0xa00aaf94
a00876b0:  d4 0f bf f7  ldub  [ %fp + -9 ], %o2
a00876b4:  90 10 00 11  mov  %l1, %o0
a00876b8:  d2 0e 40 00  ldub  [ %i1 ], %o1
a00876bc:  d4 0f bf f7  ldub  [ %fp + -9 ], %o2
a00876c0:  7f ff fb a0  call  0xa0086540
a00876c4:  d6 0f bf f6  ldub  [ %fp + -10 ], %o3
a00876c8:  80 8a 20 ff  btst  0xff, %o0
a00876cc:  12 bf ff af  bne  0xa0087588
a00876d0:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00876d4:  b0 10 20 02  mov  2, %i0
a00876d8:  a4 04 a0 01  inc  %l2
a00876dc:  10 bf ff 9f  b  0xa0087558
a00876e0:  9a 0c a0 ff  and  %l2, 0xff, %o5
a00876e4:  81 c7 e0 08  ret
a00876e8:  81 e8 00 00  restore
