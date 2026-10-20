# leon2m FUN_a00ac388 0xa00ac388-0xa00ac718 (912 bytes)
a00ac388:  9d e3 bf 88  save  %sp, -120, %sp
a00ac38c:  80 8e 20 ff  btst  0xff, %i0
a00ac390:  22 80 00 8f  be,a   0xa00ac5cc
a00ac394:  90 10 21 39  mov  0x139, %o0
a00ac398:  90 10 21 11  mov  0x111, %o0
a00ac39c:  40 02 69 ed  call  0xa0146b50
a00ac3a0:  92 10 20 00  clr  %o1
a00ac3a4:  90 10 20 00  clr  %o0
a00ac3a8:  40 02 69 f1  call  0xa0146b6c
a00ac3ac:  92 10 20 00  clr  %o1
a00ac3b0:  2d 2a 00 b4  sethi  %hi(0xa802d000), %l6
a00ac3b4:  96 15 a2 90  or  %l6, 0x290, %o3	! 0xa802d290
a00ac3b8:  d4 0a e0 08  ldub  [ %o3 + 8 ], %o2
a00ac3bc:  82 02 a0 91  add  %o2, 0x91, %g1
a00ac3c0:  93 28 60 10  sll  %g1, 0x10, %o1
a00ac3c4:  11 00 06 3a  sethi  %hi(0x18e800), %o0
a00ac3c8:  93 32 60 10  srl  %o1, 0x10, %o1
a00ac3cc:  7f ff dd 1e  call  0xa00a3844
a00ac3d0:  90 12 21 f8  or  %o0, 0x1f8, %o0
a00ac3d4:  98 10 00 08  mov  %o0, %o4
a00ac3d8:  90 10 20 00  clr  %o0
a00ac3dc:  92 10 20 2a  mov  0x2a, %o1
a00ac3e0:  94 10 20 06  mov  6, %o2
a00ac3e4:  96 10 20 01  mov  1, %o3
a00ac3e8:  7f ff db 6f  call  0xa00a31a4
a00ac3ec:  9a 10 20 00  clr  %o5
a00ac3f0:  b0 10 20 01  mov  1, %i0
a00ac3f4:  a0 10 20 01  mov  1, %l0
a00ac3f8:  25 00 06 4c  sethi  %hi(0x193000), %l2
a00ac3fc:  91 2c 20 03  sll  %l0, 3, %o0
a00ac400:  a2 22 00 10  sub  %o0, %l0, %l1
a00ac404:  af 2c 60 02  sll  %l1, 2, %l7
a00ac408:  a2 15 a2 90  or  %l6, 0x290, %l1
a00ac40c:  a8 05 c0 10  add  %l7, %l0, %l4
a00ac410:  ea 0c 60 08  ldub  [ %l1 + 8 ], %l5
a00ac414:  a6 05 00 15  add  %l4, %l5, %l3
a00ac418:  9e 04 ff e3  add  %l3, -29, %o7
a00ac41c:  99 2b e0 10  sll  %o7, 0x10, %o4
a00ac420:  93 33 20 10  srl  %o4, 0x10, %o1
a00ac424:  7f ff dd 08  call  0xa00a3844
a00ac428:  90 14 a2 48  or  %l2, 0x248, %o0
a00ac42c:  9a 04 00 10  add  %l0, %l0, %o5
a00ac430:  98 10 00 08  mov  %o0, %o4
a00ac434:  94 03 60 06  add  %o5, 6, %o2
a00ac438:  90 10 20 00  clr  %o0
a00ac43c:  92 10 20 2a  mov  0x2a, %o1
a00ac440:  96 10 20 01  mov  1, %o3
a00ac444:  9a 10 20 00  clr  %o5
a00ac448:  7f ff db 57  call  0xa00a31a4
a00ac44c:  b0 06 20 01  inc  %i0
a00ac450:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00ac454:  80 a4 20 01  cmp  %l0, 1
a00ac458:  08 bf ff ea  bleu  0xa00ac400
a00ac45c:  91 2c 20 03  sll  %l0, 3, %o0
a00ac460:  a8 10 00 11  mov  %l1, %l4
a00ac464:  21 33 33 33  sethi  %hi(0xcccccc00), %l0
a00ac468:  aa 14 20 cd  or  %l0, 0xcd, %l5	! 0xcccccccd
a00ac46c:  a4 10 20 00  clr  %l2
a00ac470:  b0 10 20 00  clr  %i0
a00ac474:  a6 07 bf e8  add  %fp, -24, %l3
a00ac478:  2f 00 06 60  sethi  %hi(0x198000), %l7
a00ac47c:  a2 07 bf f8  add  %fp, -8, %l1
a00ac480:  90 06 00 14  add  %i0, %l4, %o0
a00ac484:  da 0a 21 9c  ldub  [ %o0 + 0x19c ], %o5
a00ac488:  de 0a 21 98  ldub  [ %o0 + 0x198 ], %o7
a00ac48c:  80 53 c0 15  umul  %o7, %l5, %g0
a00ac490:  95 40 00 00  rd  %y, %o2
a00ac494:  80 53 40 15  umul  %o5, %l5, %g0
a00ac498:  99 40 00 00  rd  %y, %o4
a00ac49c:  95 32 a0 03  srl  %o2, 3, %o2
a00ac4a0:  99 33 20 03  srl  %o4, 3, %o4
a00ac4a4:  93 2a a0 02  sll  %o2, 2, %o1
a00ac4a8:  97 2b 20 02  sll  %o4, 2, %o3
a00ac4ac:  82 02 40 0a  add  %o1, %o2, %g1
a00ac4b0:  a0 02 c0 0c  add  %o3, %o4, %l0
a00ac4b4:  90 00 40 01  add  %g1, %g1, %o0
a00ac4b8:  92 04 00 10  add  %l0, %l0, %o1
a00ac4bc:  82 23 40 09  sub  %o5, %o1, %g1
a00ac4c0:  96 23 c0 08  sub  %o7, %o0, %o3
a00ac4c4:  98 0b 20 ff  and  %o4, 0xff, %o4
a00ac4c8:  9a 08 60 ff  and  %g1, 0xff, %o5
a00ac4cc:  94 0a a0 ff  and  %o2, 0xff, %o2
a00ac4d0:  96 0a e0 ff  and  %o3, 0xff, %o3
a00ac4d4:  90 10 00 13  mov  %l3, %o0
a00ac4d8:  40 02 ac c7  call  0xa01577f4
a00ac4dc:  92 15 e1 b0  or  %l7, 0x1b0, %o1
a00ac4e0:  98 10 20 00  clr  %o4
a00ac4e4:  82 10 20 00  clr  %g1
a00ac4e8:  9e 04 40 01  add  %l1, %g1, %o7
a00ac4ec:  da 0b ff f0  ldub  [ %o7 + -16 ], %o5
a00ac4f0:  80 a3 60 00  cmp  %o5, 0
a00ac4f4:  22 80 00 08  be,a   0xa00ac514
a00ac4f8:  c2 0d 21 a0  ldub  [ %l4 + 0x1a0 ], %g1
a00ac4fc:  98 03 20 01  inc  %o4
a00ac500:  82 0b 20 ff  and  %o4, 0xff, %g1
a00ac504:  80 a0 60 0e  cmp  %g1, 0xe
a00ac508:  08 bf ff f9  bleu  0xa00ac4ec
a00ac50c:  9e 04 40 01  add  %l1, %g1, %o7
a00ac510:  c2 0d 21 a0  ldub  [ %l4 + 0x1a0 ], %g1
a00ac514:  a0 00 7f ff  add  %g1, -1, %l0
a00ac518:  96 03 3f ff  add  %o4, -1, %o3
a00ac51c:  80 a6 00 10  cmp  %i0, %l0
a00ac520:  d6 2f bf e8  stb  %o3, [ %fp + -24 ]
a00ac524:  02 80 00 72  be  0xa00ac6ec
a00ac528:  a0 06 00 18  add  %i0, %i0, %l0
a00ac52c:  92 04 20 0a  add  %l0, 0xa, %o1
a00ac530:  b1 2a 60 10  sll  %o1, 0x10, %i0
a00ac534:  95 36 20 10  srl  %i0, 0x10, %o2
a00ac538:  90 10 20 00  clr  %o0
a00ac53c:  92 10 20 2a  mov  0x2a, %o1
a00ac540:  96 10 20 01  mov  1, %o3
a00ac544:  98 10 00 13  mov  %l3, %o4
a00ac548:  9a 10 20 00  clr  %o5
a00ac54c:  7f ff db 16  call  0xa00a31a4
a00ac550:  a4 04 a0 01  inc  %l2
a00ac554:  b0 0c a0 ff  and  %l2, 0xff, %i0
a00ac558:  80 a6 20 03  cmp  %i0, 3
a00ac55c:  08 bf ff ca  bleu  0xa00ac484
a00ac560:  90 06 00 14  add  %i0, %l4, %o0
a00ac564:  a8 15 a2 90  or  %l6, 0x290, %l4
a00ac568:  e6 0d 21 a0  ldub  [ %l4 + 0x1a0 ], %l3
a00ac56c:  ac 04 e0 01  add  %l3, 1, %l6
a00ac570:  9a 0d a0 ff  and  %l6, 0xff, %o5
a00ac574:  a4 03 40 0d  add  %o5, %o5, %l2
a00ac578:  80 a3 60 06  cmp  %o5, 6
a00ac57c:  08 80 00 04  bleu  0xa00ac58c
a00ac580:  82 04 a0 06  add  %l2, 6, %g1
a00ac584:  aa 03 40 0d  add  %o5, %o5, %l5
a00ac588:  82 05 7f f8  add  %l5, -8, %g1
a00ac58c:  ae 08 60 ff  and  %g1, 0xff, %l7
a00ac590:  94 10 00 17  mov  %l7, %o2
a00ac594:  90 10 20 00  clr  %o0
a00ac598:  92 10 20 28  mov  0x28, %o1
a00ac59c:  96 10 20 01  mov  1, %o3
a00ac5a0:  98 10 20 0f  mov  0xf, %o4
a00ac5a4:  40 02 69 5f  call  0xa0146b20
a00ac5a8:  9a 10 20 00  clr  %o5
a00ac5ac:  94 10 00 17  mov  %l7, %o2
a00ac5b0:  90 10 20 00  clr  %o0
a00ac5b4:  92 10 20 29  mov  0x29, %o1
a00ac5b8:  96 10 20 01  mov  1, %o3
a00ac5bc:  98 10 20 10  mov  0x10, %o4
a00ac5c0:  40 02 69 58  call  0xa0146b20
a00ac5c4:  9a 10 20 00  clr  %o5
a00ac5c8:  30 80 00 52  b,a   0xa00ac710
a00ac5cc:  40 02 69 61  call  0xa0146b50
a00ac5d0:  92 10 20 00  clr  %o1
a00ac5d4:  90 10 20 00  clr  %o0
a00ac5d8:  40 02 69 65  call  0xa0146b6c
a00ac5dc:  92 10 20 00  clr  %o1
a00ac5e0:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ac5e4:  a0 12 e2 90  or  %o3, 0x290, %l0	! 0xa802d290
a00ac5e8:  c2 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %g1
a00ac5ec:  9a 00 40 01  add  %g1, %g1, %o5
a00ac5f0:  94 03 40 01  add  %o5, %g1, %o2
a00ac5f4:  94 02 a0 0a  add  %o2, 0xa, %o2
a00ac5f8:  90 10 20 00  clr  %o0
a00ac5fc:  92 10 20 2a  mov  0x2a, %o1
a00ac600:  96 10 20 0b  mov  0xb, %o3
a00ac604:  98 10 20 00  clr  %o4
a00ac608:  40 02 69 46  call  0xa0146b20
a00ac60c:  9a 10 20 00  clr  %o5
a00ac610:  e2 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %l1
a00ac614:  9e 04 7f ff  add  %l1, -1, %o7
a00ac618:  a2 0b e0 ff  and  %o7, 0xff, %l1
a00ac61c:  90 04 40 10  add  %l1, %l0, %o0
a00ac620:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a00ac624:  da 0a 21 9c  ldub  [ %o0 + 0x19c ], %o5
a00ac628:  ae 13 20 cd  or  %o4, 0xcd, %l7
a00ac62c:  d6 0a 21 98  ldub  [ %o0 + 0x198 ], %o3
a00ac630:  80 53 40 17  umul  %o5, %l7, %g0
a00ac634:  a9 40 00 00  rd  %y, %l4
a00ac638:  99 35 20 03  srl  %l4, 3, %o4
a00ac63c:  80 52 c0 17  umul  %o3, %l7, %g0
a00ac640:  ab 40 00 00  rd  %y, %l5
a00ac644:  95 35 60 03  srl  %l5, 3, %o2
a00ac648:  ad 2b 20 02  sll  %o4, 2, %l6
a00ac64c:  92 05 80 0c  add  %l6, %o4, %o1
a00ac650:  a7 2a a0 02  sll  %o2, 2, %l3
a00ac654:  a0 02 40 09  add  %o1, %o1, %l0
a00ac658:  a4 04 c0 0a  add  %l3, %o2, %l2
a00ac65c:  90 23 40 10  sub  %o5, %l0, %o0
a00ac660:  b0 04 80 12  add  %l2, %l2, %i0
a00ac664:  03 00 06 60  sethi  %hi(0x198000), %g1
a00ac668:  9e 22 c0 18  sub  %o3, %i0, %o7
a00ac66c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00ac670:  a0 07 bf e8  add  %fp, -24, %l0
a00ac674:  92 10 61 b0  or  %g1, 0x1b0, %o1
a00ac678:  96 0b e0 ff  and  %o7, 0xff, %o3
a00ac67c:  98 0b 20 ff  and  %o4, 0xff, %o4
a00ac680:  94 0a a0 ff  and  %o2, 0xff, %o2
a00ac684:  40 02 ac 5c  call  0xa01577f4
a00ac688:  90 10 00 10  mov  %l0, %o0
a00ac68c:  98 10 20 00  clr  %o4
a00ac690:  82 10 20 00  clr  %g1
a00ac694:  96 07 bf f8  add  %fp, -8, %o3
a00ac698:  92 02 c0 01  add  %o3, %g1, %o1
a00ac69c:  f0 0a 7f f0  ldub  [ %o1 + -16 ], %i0
a00ac6a0:  80 a6 20 00  cmp  %i0, 0
a00ac6a4:  02 80 00 08  be  0xa00ac6c4
a00ac6a8:  ac 03 3f ff  add  %o4, -1, %l6
a00ac6ac:  98 03 20 01  inc  %o4
a00ac6b0:  82 0b 20 ff  and  %o4, 0xff, %g1
a00ac6b4:  80 a0 60 0e  cmp  %g1, 0xe
a00ac6b8:  08 bf ff f9  bleu  0xa00ac69c
a00ac6bc:  92 02 c0 01  add  %o3, %g1, %o1
a00ac6c0:  ac 03 3f ff  add  %o4, -1, %l6
a00ac6c4:  a4 04 40 11  add  %l1, %l1, %l2
a00ac6c8:  ec 2f bf e8  stb  %l6, [ %fp + -24 ]
a00ac6cc:  94 04 a0 0a  add  %l2, 0xa, %o2
a00ac6d0:  98 10 00 10  mov  %l0, %o4
a00ac6d4:  90 10 20 00  clr  %o0
a00ac6d8:  92 10 20 2a  mov  0x2a, %o1
a00ac6dc:  96 10 20 01  mov  1, %o3
a00ac6e0:  7f ff da b1  call  0xa00a31a4
a00ac6e4:  9a 10 20 00  clr  %o5
a00ac6e8:  30 80 00 0a  b,a   0xa00ac710
a00ac6ec:  90 10 20 00  clr  %o0
a00ac6f0:  92 10 20 2a  mov  0x2a, %o1
a00ac6f4:  94 04 20 0a  add  %l0, 0xa, %o2
a00ac6f8:  96 10 20 0a  mov  0xa, %o3
a00ac6fc:  98 10 20 00  clr  %o4
a00ac700:  40 02 69 08  call  0xa0146b20
a00ac704:  9a 10 20 00  clr  %o5
a00ac708:  10 bf ff 8a  b  0xa00ac530
a00ac70c:  92 04 20 0a  add  %l0, 0xa, %o1
a00ac710:  81 c7 e0 08  ret
a00ac714:  81 e8 00 00  restore
