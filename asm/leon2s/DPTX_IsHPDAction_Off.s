# leon2s DPTX_IsHPDAction_Off 0xa0089428-0xa0089750 (808 bytes)
a0089428:  9d e3 bf 80  save  %sp, -128, %sp
a008942c:  98 10 20 00  clr  %o4
a0089430:  9a 10 20 00  clr  %o5
a0089434:  82 10 20 01  mov  1, %g1
a0089438:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a008943c:  c2 2f bf e7  stb  %g1, [ %fp + -25 ]
a0089440:  7f ff ff f8  call  0xa0089420
a0089444:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0089448:  90 0a 20 ff  and  %o0, 0xff, %o0
a008944c:  80 a2 20 01  cmp  %o0, 1
a0089450:  12 80 00 09  bne  0xa0089474
a0089454:  a4 10 20 00  clr  %l2
a0089458:  7f ff f4 93  call  0xa00866a4
a008945c:  01 00 00 00  nop
a0089460:  80 8a 20 ff  btst  0xff, %o0
a0089464:  02 80 00 05  be  0xa0089478
a0089468:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a008946c:  7f c5 0b 0f  call  0x9f1cc0a8
a0089470:  01 00 00 00  nop
a0089474:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0089478:  a6 10 61 b8  or  %g1, 0x1b8, %l3	! 0xa80761b8
a008947c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0089480:  c2 0c c0 10  ldub  [ %l3 + %l0 ], %g1
a0089484:  80 a0 60 01  cmp  %g1, 1
a0089488:  12 80 00 0d  bne  0xa00894bc
a008948c:  01 00 00 00  nop
a0089490:  7f ff fd 98  call  0xa0088af0
a0089494:  90 10 00 10  mov  %l0, %o0
a0089498:  90 0a 20 ff  and  %o0, 0xff, %o0
a008949c:  90 1a 20 01  xor  %o0, 1, %o0
a00894a0:  80 a0 00 08  cmp  %g0, %o0
a00894a4:  82 40 20 00  addx  %g0, 0, %g1
a00894a8:  a2 00 60 01  add  %g1, 1, %l1
a00894ac:  7f ff fd 3c  call  0xa008899c
a00894b0:  90 10 00 10  mov  %l0, %o0
a00894b4:  10 80 00 05  b  0xa00894c8
a00894b8:  c0 2c c0 10  clrb  [ %l3 + %l0 ]
a00894bc:  7f ff fd 38  call  0xa008899c
a00894c0:  90 10 00 10  mov  %l0, %o0
a00894c4:  a2 10 00 08  mov  %o0, %l1
a00894c8:  82 0c 60 ff  and  %l1, 0xff, %g1
a00894cc:  80 a0 60 01  cmp  %g1, 1
a00894d0:  12 80 00 0b  bne  0xa00894fc
a00894d4:  80 a0 60 02  cmp  %g1, 2
a00894d8:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a00894dc:  7f ff a7 fa  call  0xa00734c4
a00894e0:  90 12 23 b0  or  %o0, 0x3b0, %o0	! 0xa0068bb0
a00894e4:  82 0e 20 ff  and  %i0, 0xff, %g1
a00894e8:  80 a0 00 01  cmp  %g0, %g1
a00894ec:  82 60 20 00  subx  %g0, 0, %g1
a00894f0:  82 08 78 01  and  %g1, -2047, %g1
a00894f4:  10 80 00 0a  b  0xa008951c
a00894f8:  a4 00 68 07  add  %g1, 0x807, %l2
a00894fc:  12 80 00 09  bne  0xa0089520
a0089500:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0089504:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a0089508:  7f ff a7 ef  call  0xa00734c4
a008950c:  90 12 23 c8  or  %o0, 0x3c8, %o0	! 0xa0068bc8
a0089510:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0089514:  c0 28 62 0a  clrb  [ %g1 + 0x20a ]	! 0xa8078a0a
a0089518:  a4 10 20 40  mov  0x40, %l2
a008951c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0089520:  7f ff fd 58  call  0xa0088a80
a0089524:  90 10 00 10  mov  %l0, %o0
a0089528:  80 8a 20 ff  btst  0xff, %o0
a008952c:  02 80 00 08  be  0xa008954c
a0089530:  01 00 00 00  nop
a0089534:  7f ff fd 6f  call  0xa0088af0
a0089538:  90 10 00 10  mov  %l0, %o0
a008953c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0089540:  80 a2 20 01  cmp  %o0, 1
a0089544:  22 80 00 02  be,a   0xa008954c
a0089548:  a4 14 a0 08  or  %l2, 8, %l2
a008954c:  7f ff fe 99  call  0xa0088fb0
a0089550:  90 10 00 10  mov  %l0, %o0
a0089554:  90 12 00 12  or  %o0, %l2, %o0
a0089558:  80 8a 20 08  btst  8, %o0
a008955c:  02 80 00 27  be  0xa00895f8
a0089560:  a4 10 00 08  mov  %o0, %l2
a0089564:  90 10 00 10  mov  %l0, %o0
a0089568:  92 07 bf e8  add  %fp, -24, %o1
a008956c:  7f ff fd bc  call  0xa0088c5c
a0089570:  94 07 bf e7  add  %fp, -25, %o2
a0089574:  90 0a 20 ff  and  %o0, 0xff, %o0
a0089578:  80 a2 20 01  cmp  %o0, 1
a008957c:  12 80 00 0d  bne  0xa00895b0
a0089580:  01 00 00 00  nop
a0089584:  40 00 88 3c  call  0xa00ab674
a0089588:  90 10 20 00  clr  %o0	! 0x0
a008958c:  80 8a 20 ff  btst  0xff, %o0
a0089590:  22 80 00 08  be,a   0xa00895b0
a0089594:  a4 14 a0 03  or  %l2, 3, %l2
a0089598:  80 a4 20 00  cmp  %l0, 0
a008959c:  32 80 00 05  bne,a   0xa00895b0
a00895a0:  a4 14 a0 03  or  %l2, 3, %l2
a00895a4:  7f c5 0a a4  call  0x9f1cc034
a00895a8:  90 10 20 01  mov  1, %o0
a00895ac:  a4 14 a0 03  or  %l2, 3, %l2
a00895b0:  7f ff fe 8f  call  0xa0088fec
a00895b4:  90 10 00 10  mov  %l0, %o0
a00895b8:  80 8a 20 ff  btst  0xff, %o0
a00895bc:  32 80 00 02  bne,a   0xa00895c4
a00895c0:  a4 14 a0 01  or  %l2, 1, %l2
a00895c4:  c2 0f bf ee  ldub  [ %fp + -18 ], %g1
a00895c8:  80 88 60 40  btst  0x40, %g1
a00895cc:  02 80 00 08  be  0xa00895ec
a00895d0:  c2 0f bf ea  ldub  [ %fp + -22 ], %g1
a00895d4:  7f ff f4 29  call  0xa0086678
a00895d8:  90 10 00 10  mov  %l0, %o0
a00895dc:  80 8a 20 ff  btst  0xff, %o0
a00895e0:  32 80 00 02  bne,a   0xa00895e8
a00895e4:  a4 14 a0 04  or  %l2, 4, %l2
a00895e8:  c2 0f bf ea  ldub  [ %fp + -22 ], %g1
a00895ec:  80 a0 60 00  cmp  %g1, 0
a00895f0:  32 80 00 02  bne,a   0xa00895f8
a00895f4:  a4 14 a0 10  or  %l2, 0x10, %l2
a00895f8:  80 8c a0 10  btst  0x10, %l2
a00895fc:  02 80 00 11  be  0xa0089640
a0089600:  a3 2c a0 10  sll  %l2, 0x10, %l1
a0089604:  90 0e 20 ff  and  %i0, 0xff, %o0
a0089608:  7f ff fb 72  call  0xa00883d0
a008960c:  92 07 bf e8  add  %fp, -24, %o1
a0089610:  90 0a 20 ff  and  %o0, 0xff, %o0
a0089614:  80 a2 20 01  cmp  %o0, 1
a0089618:  02 80 00 06  be  0xa0089630
a008961c:  80 a2 20 02  cmp  %o0, 2
a0089620:  02 80 00 06  be  0xa0089638
a0089624:  a3 2c a0 10  sll  %l2, 0x10, %l1
a0089628:  10 80 00 07  b  0xa0089644
a008962c:  a1 34 60 10  srl  %l1, 0x10, %l0
a0089630:  10 80 00 03  b  0xa008963c
a0089634:  a4 14 a0 03  or  %l2, 3, %l2
a0089638:  a4 10 20 00  clr  %l2
a008963c:  a3 2c a0 10  sll  %l2, 0x10, %l1
a0089640:  a1 34 60 10  srl  %l1, 0x10, %l0
a0089644:  80 8c 20 04  btst  4, %l0
a0089648:  02 80 00 05  be  0xa008965c
a008964c:  80 8c 20 02  btst  2, %l0
a0089650:  7f ff fd 44  call  0xa0088b60
a0089654:  90 0e 20 ff  and  %i0, 0xff, %o0
a0089658:  80 8c 20 02  btst  2, %l0
a008965c:  02 80 00 05  be  0xa0089670
a0089660:  80 8c 20 40  btst  0x40, %l0
a0089664:  7f ff f4 82  call  0xa008686c
a0089668:  90 0e 20 ff  and  %i0, 0xff, %o0
a008966c:  80 8c 20 40  btst  0x40, %l0
a0089670:  02 80 00 15  be  0xa00896c4
a0089674:  83 34 60 10  srl  %l1, 0x10, %g1
a0089678:  a0 0e 20 ff  and  %i0, 0xff, %l0
a008967c:  7f ff f4 0f  call  0xa00866b8
a0089680:  90 10 00 10  mov  %l0, %o0
a0089684:  90 10 00 10  mov  %l0, %o0
a0089688:  40 00 84 aa  call  0xa00aa930
a008968c:  92 10 20 07  mov  7, %o1
a0089690:  40 00 87 f9  call  0xa00ab674
a0089694:  90 10 20 00  clr  %o0
a0089698:  80 8a 20 ff  btst  0xff, %o0
a008969c:  02 80 00 0a  be  0xa00896c4
a00896a0:  83 34 60 10  srl  %l1, 0x10, %g1
a00896a4:  80 a4 20 00  cmp  %l0, 0
a00896a8:  12 80 00 08  bne  0xa00896c8
a00896ac:  80 88 60 01  btst  1, %g1
a00896b0:  7f c5 0a 64  call  0x9f1cc040
a00896b4:  90 10 20 00  clr  %o0
a00896b8:  7f c5 0a 5f  call  0x9f1cc034
a00896bc:  90 10 20 01  mov  1, %o0
a00896c0:  83 34 60 10  srl  %l1, 0x10, %g1
a00896c4:  80 88 60 01  btst  1, %g1
a00896c8:  02 80 00 1f  be  0xa0089744
a00896cc:  01 00 00 00  nop
a00896d0:  7f ff f3 f5  call  0xa00866a4
a00896d4:  01 00 00 00  nop
a00896d8:  80 8a 20 ff  btst  0xff, %o0
a00896dc:  22 80 00 08  be,a   0xa00896fc
a00896e0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00896e4:  80 8e 20 ff  btst  0xff, %i0
a00896e8:  32 80 00 05  bne,a   0xa00896fc
a00896ec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00896f0:  7f c5 0a 54  call  0x9f1cc040
a00896f4:  90 10 20 01  mov  1, %o0
a00896f8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00896fc:  90 10 00 18  mov  %i0, %o0
a0089700:  7f ff f8 49  call  0xa0087824
a0089704:  92 07 bf e7  add  %fp, -25, %o1
a0089708:  90 0a 20 ff  and  %o0, 0xff, %o0
a008970c:  80 a2 20 01  cmp  %o0, 1
a0089710:  12 80 00 0d  bne  0xa0089744
a0089714:  01 00 00 00  nop
a0089718:  7f ff f3 e3  call  0xa00866a4
a008971c:  01 00 00 00  nop
a0089720:  80 8a 20 ff  btst  0xff, %o0
a0089724:  02 80 00 06  be  0xa008973c
a0089728:  80 a6 20 00  cmp  %i0, 0
a008972c:  12 80 00 04  bne  0xa008973c
a0089730:  01 00 00 00  nop
a0089734:  7f c5 0a 40  call  0x9f1cc034
a0089738:  90 10 20 00  clr  %o0	! 0x0
a008973c:  7f ff f3 b8  call  0xa008661c
a0089740:  90 10 00 18  mov  %i0, %o0
a0089744:  01 00 00 00  nop
a0089748:  81 c7 e0 08  ret
a008974c:  81 e8 00 00  restore
