# leon2m FUN_a002b3e4 0xa002b3e4-0xa002b758 (884 bytes)
a002b3e4:  9d e3 bf 98  save  %sp, -104, %sp
a002b3e8:  d6 16 00 00  lduh  [ %i0 ], %o3
a002b3ec:  2b 2a 00 b6  sethi  %hi(0xa802d800), %l5
a002b3f0:  d6 35 61 92  sth  %o3, [ %l5 + 0x192 ]	! 0xa802d992
a002b3f4:  98 15 61 92  or  %l5, 0x192, %o4
a002b3f8:  d4 16 20 02  lduh  [ %i0 + 2 ], %o2
a002b3fc:  d4 33 20 02  sth  %o2, [ %o4 + 2 ]
a002b400:  d2 16 20 04  lduh  [ %i0 + 4 ], %o1
a002b404:  d2 33 20 04  sth  %o1, [ %o4 + 4 ]
a002b408:  d0 16 20 06  lduh  [ %i0 + 6 ], %o0
a002b40c:  d0 33 20 06  sth  %o0, [ %o4 + 6 ]
a002b410:  c2 16 20 08  lduh  [ %i0 + 8 ], %g1
a002b414:  da 0b 20 07  ldub  [ %o4 + 7 ], %o5
a002b418:  c2 33 20 08  sth  %g1, [ %o4 + 8 ]
a002b41c:  80 a3 60 01  cmp  %o5, 1
a002b420:  ac 10 00 19  mov  %i1, %l6
a002b424:  a4 10 20 01  mov  1, %l2
a002b428:  02 80 00 69  be  0xa002b5cc
a002b42c:  a8 10 20 00  clr  %l4
a002b430:  ee 0b 20 06  ldub  [ %o4 + 6 ], %l7
a002b434:  40 00 06 a9  call  0xa002ced8
a002b438:  01 00 00 00  nop
a002b43c:  19 2a 00 b6  sethi  %hi(0xa802d800), %o4
a002b440:  10 80 00 0e  b  0xa002b478
a002b444:  a6 13 21 92  or  %o4, 0x192, %l3	! 0xa802d992
a002b448:  40 00 06 a4  call  0xa002ced8
a002b44c:  01 00 00 00  nop
a002b450:  98 1e 60 01  xor  %i1, 1, %o4
a002b454:  80 a0 00 0c  cmp  %g0, %o4
a002b458:  b2 60 3f ff  subx  %g0, -1, %i1
a002b45c:  96 0d 20 ff  and  %l4, 0xff, %o3
a002b460:  9e 0f 20 ff  and  %i4, 0xff, %o7
a002b464:  80 a3 c0 0b  cmp  %o7, %o3
a002b468:  a0 60 3f ff  subx  %g0, -1, %l0
a002b46c:  80 8e 40 10  btst  %i1, %l0
a002b470:  22 80 00 55  be,a   0xa002b5c4
a002b474:  b7 2c 60 10  sll  %l1, 0x10, %i3
a002b478:  d0 14 e0 08  lduh  [ %l3 + 8 ], %o0
a002b47c:  1b 3f ff f0  sethi  %hi(0xffffc000), %o5
a002b480:  82 0a 00 0d  and  %o0, %o5, %g1
a002b484:  b3 28 60 10  sll  %g1, 0x10, %i1
a002b488:  31 20 00 00  sethi  %hi(0x80000000), %i0
a002b48c:  80 a6 40 18  cmp  %i1, %i0
a002b490:  a2 10 20 00  clr  %l1
a002b494:  12 bf ff ed  bne  0xa002b448
a002b498:  b2 0c a0 ff  and  %l2, 0xff, %i1
a002b49c:  7f ff fd 1d  call  0xa002a910
a002b4a0:  a0 10 20 00  clr  %l0
a002b4a4:  b2 0d e0 ff  and  %l7, 0xff, %i1
a002b4a8:  13 2a 00 b6  sethi  %hi(0xa802d800), %o1
a002b4ac:  b0 12 61 92  or  %o1, 0x192, %i0	! 0xa802d992
a002b4b0:  7f ff fd 95  call  0xa002ab04
a002b4b4:  90 10 00 19  mov  %i1, %o0
a002b4b8:  80 8a 20 ff  btst  0xff, %o0
a002b4bc:  22 80 00 0d  be,a   0xa002b4f0
a002b4c0:  b1 2c 20 10  sll  %l0, 0x10, %i0
a002b4c4:  c2 16 20 04  lduh  [ %i0 + 4 ], %g1
a002b4c8:  99 28 60 11  sll  %g1, 0x11, %o4
a002b4cc:  40 00 07 5c  call  0xa002d23c
a002b4d0:  91 33 20 10  srl  %o4, 0x10, %o0
a002b4d4:  94 04 20 01  add  %l0, 1, %o2
a002b4d8:  9f 2a a0 10  sll  %o2, 0x10, %o7
a002b4dc:  97 33 e0 10  srl  %o7, 0x10, %o3
a002b4e0:  80 a2 e0 09  cmp  %o3, 9
a002b4e4:  08 bf ff f3  bleu  0xa002b4b0
a002b4e8:  a0 10 00 0a  mov  %o2, %l0
a002b4ec:  b1 2c 20 10  sll  %l0, 0x10, %i0
a002b4f0:  a1 36 20 10  srl  %i0, 0x10, %l0
a002b4f4:  80 a4 20 0a  cmp  %l0, 0xa
a002b4f8:  22 80 00 68  be,a   0xa002b698
a002b4fc:  d2 0c e0 03  ldub  [ %l3 + 3 ], %o1
a002b500:  90 15 61 92  or  %l5, 0x192, %o0
a002b504:  f2 0a 20 07  ldub  [ %o0 + 7 ], %i1
a002b508:  80 a6 60 01  cmp  %i1, 1
a002b50c:  02 80 00 04  be  0xa002b51c
a002b510:  9b 2d a0 10  sll  %l6, 0x10, %o5
a002b514:  7f ff fd 7c  call  0xa002ab04
a002b518:  91 33 60 18  srl  %o5, 0x18, %o0
a002b51c:  7f ff fd 7a  call  0xa002ab04
a002b520:  90 0d a0 ff  and  %l6, 0xff, %o0
a002b524:  93 2e a0 10  sll  %i2, 0x10, %o1
a002b528:  83 32 60 10  srl  %o1, 0x10, %g1
a002b52c:  80 a0 60 00  cmp  %g1, 0
a002b530:  a0 10 20 00  clr  %l0
a002b534:  02 80 00 13  be  0xa002b580
a002b538:  b2 0c a0 ff  and  %l2, 0xff, %i1
a002b53c:  b0 10 00 01  mov  %g1, %i0
a002b540:  99 2c 20 10  sll  %l0, 0x10, %o4
a002b544:  9f 33 20 10  srl  %o4, 0x10, %o7
a002b548:  d0 0b c0 1b  ldub  [ %o7 + %i3 ], %o0
a002b54c:  7f ff fd 6e  call  0xa002ab04
a002b550:  01 00 00 00  nop
a002b554:  94 04 20 01  add  %l0, 1, %o2
a002b558:  97 2a a0 10  sll  %o2, 0x10, %o3
a002b55c:  b2 0a 20 ff  and  %o0, 0xff, %i1
a002b560:  a4 10 00 08  mov  %o0, %l2
a002b564:  83 32 e0 10  srl  %o3, 0x10, %g1
a002b568:  80 a6 60 01  cmp  %i1, 1
a002b56c:  02 80 00 05  be  0xa002b580
a002b570:  a0 10 00 0a  mov  %o2, %l0
a002b574:  80 a0 40 18  cmp  %g1, %i0
a002b578:  0a bf ff f2  bcs  0xa002b540
a002b57c:  a2 04 60 01  inc  %l1
a002b580:  80 8f 60 ff  btst  0xff, %i5
a002b584:  12 80 00 17  bne  0xa002b5e0
a002b588:  a0 15 61 92  or  %l5, 0x192, %l0
a002b58c:  a8 05 20 01  inc  %l4
a002b590:  40 00 06 52  call  0xa002ced8
a002b594:  01 00 00 00  nop
a002b598:  98 1e 60 01  xor  %i1, 1, %o4
a002b59c:  80 a0 00 0c  cmp  %g0, %o4
a002b5a0:  b2 60 3f ff  subx  %g0, -1, %i1
a002b5a4:  96 0d 20 ff  and  %l4, 0xff, %o3
a002b5a8:  9e 0f 20 ff  and  %i4, 0xff, %o7
a002b5ac:  80 a3 c0 0b  cmp  %o7, %o3
a002b5b0:  a0 60 3f ff  subx  %g0, -1, %l0
a002b5b4:  80 8e 40 10  btst  %i1, %l0
a002b5b8:  32 bf ff b1  bne,a   0xa002b47c
a002b5bc:  d0 14 e0 08  lduh  [ %l3 + 8 ], %o0
a002b5c0:  b7 2c 60 10  sll  %l1, 0x10, %i3
a002b5c4:  10 80 00 63  b  0xa002b750
a002b5c8:  b1 36 e0 10  srl  %i3, 0x10, %i0
a002b5cc:  a3 36 60 07  srl  %i1, 7, %l1
a002b5d0:  a0 0c 60 0e  and  %l1, 0xe, %l0
a002b5d4:  de 0b 20 06  ldub  [ %o4 + 6 ], %o7
a002b5d8:  10 bf ff 97  b  0xa002b434
a002b5dc:  ae 14 00 0f  or  %l0, %o7, %l7
a002b5e0:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002b5e4:  94 10 20 00  clr  %o2
a002b5e8:  40 00 04 a1  call  0xa002c86c
a002b5ec:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002b5f0:  f0 14 20 04  lduh  [ %l0 + 4 ], %i0
a002b5f4:  83 2e 20 11  sll  %i0, 0x11, %g1
a002b5f8:  40 00 07 11  call  0xa002d23c
a002b5fc:  91 30 60 10  srl  %g1, 0x10, %o0
a002b600:  d0 0d 61 92  ldub  [ %l5 + 0x192 ], %o0
a002b604:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002b608:  40 00 04 99  call  0xa002c86c
a002b60c:  94 10 20 01  mov  1, %o2
a002b610:  d0 0d 61 92  ldub  [ %l5 + 0x192 ], %o0
a002b614:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002b618:  40 00 05 46  call  0xa002cb30
a002b61c:  94 10 20 01  mov  1, %o2
a002b620:  10 80 00 07  b  0xa002b63c
a002b624:  b0 10 3f ff  mov  -1, %i0
a002b628:  80 a3 60 00  cmp  %o5, 0
a002b62c:  02 80 00 0d  be  0xa002b660
a002b630:  15 2a 00 b6  sethi  %hi(0xa802d800), %o2
a002b634:  01 00 00 00  nop
a002b638:  01 00 00 00  nop
a002b63c:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002b640:  40 00 05 be  call  0xa002cd38
a002b644:  d0 0d 61 92  ldub  [ %l5 + 0x192 ], %o0
a002b648:  92 06 3f ff  add  %i0, -1, %o1
a002b64c:  9b 2a 60 10  sll  %o1, 0x10, %o5
a002b650:  80 8a 20 ff  btst  0xff, %o0
a002b654:  02 bf ff f5  be  0xa002b628
a002b658:  b0 10 00 09  mov  %o1, %i0
a002b65c:  15 2a 00 b6  sethi  %hi(0xa802d800), %o2
a002b660:  d0 0a a1 92  ldub  [ %o2 + 0x192 ], %o0	! 0xa802d992
a002b664:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002b668:  40 00 05 32  call  0xa002cb30
a002b66c:  94 10 20 00  clr  %o2
a002b670:  da 14 20 04  lduh  [ %l0 + 4 ], %o5
a002b674:  91 2b 60 11  sll  %o5, 0x11, %o0
a002b678:  40 00 06 f1  call  0xa002d23c
a002b67c:  91 32 20 10  srl  %o0, 0x10, %o0
a002b680:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002b684:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002b688:  40 00 04 79  call  0xa002c86c
a002b68c:  94 10 20 01  mov  1, %o2
a002b690:  10 bf ff c0  b  0xa002b590
a002b694:  a8 05 20 01  inc  %l4
a002b698:  d0 0c e0 02  ldub  [ %l3 + 2 ], %o0
a002b69c:  40 00 04 74  call  0xa002c86c
a002b6a0:  94 10 20 00  clr  %o2
a002b6a4:  ec 14 e0 04  lduh  [ %l3 + 4 ], %l6
a002b6a8:  a9 2d a0 11  sll  %l6, 0x11, %l4
a002b6ac:  40 00 06 e4  call  0xa002d23c
a002b6b0:  91 35 20 10  srl  %l4, 0x10, %o0
a002b6b4:  d0 0d 61 92  ldub  [ %l5 + 0x192 ], %o0
a002b6b8:  d2 0c e0 01  ldub  [ %l3 + 1 ], %o1
a002b6bc:  40 00 04 6c  call  0xa002c86c
a002b6c0:  94 10 20 01  mov  1, %o2
a002b6c4:  d2 0c e0 01  ldub  [ %l3 + 1 ], %o1
a002b6c8:  d0 0d 61 92  ldub  [ %l5 + 0x192 ], %o0
a002b6cc:  40 00 05 19  call  0xa002cb30
a002b6d0:  94 10 20 01  mov  1, %o2
a002b6d4:  a0 10 3f ff  mov  -1, %l0
a002b6d8:  25 2a 00 b6  sethi  %hi(0xa802d800), %l2
a002b6dc:  10 80 00 07  b  0xa002b6f8
a002b6e0:  a2 14 a1 92  or  %l2, 0x192, %l1	! 0xa802d992
a002b6e4:  80 a3 60 00  cmp  %o5, 0
a002b6e8:  02 80 00 0d  be  0xa002b71c
a002b6ec:  35 2a 00 b6  sethi  %hi(0xa802d800), %i2
a002b6f0:  01 00 00 00  nop
a002b6f4:  01 00 00 00  nop
a002b6f8:  d0 0d 61 92  ldub  [ %l5 + 0x192 ], %o0
a002b6fc:  40 00 05 8f  call  0xa002cd38
a002b700:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002b704:  a6 04 3f ff  add  %l0, -1, %l3
a002b708:  9b 2c e0 10  sll  %l3, 0x10, %o5
a002b70c:  80 8a 20 ff  btst  0xff, %o0
a002b710:  02 bf ff f5  be  0xa002b6e4
a002b714:  a0 10 00 13  mov  %l3, %l0
a002b718:  35 2a 00 b6  sethi  %hi(0xa802d800), %i2
a002b71c:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002b720:  94 10 20 00  clr  %o2
a002b724:  40 00 05 03  call  0xa002cb30
a002b728:  d0 0e a1 92  ldub  [ %i2 + 0x192 ], %o0
a002b72c:  ee 14 60 04  lduh  [ %l1 + 4 ], %l7
a002b730:  ab 2d e0 11  sll  %l7, 0x11, %l5
a002b734:  40 00 06 c2  call  0xa002d23c
a002b738:  91 35 60 10  srl  %l5, 0x10, %o0
a002b73c:  d2 0c 60 03  ldub  [ %l1 + 3 ], %o1
a002b740:  d0 0c 60 02  ldub  [ %l1 + 2 ], %o0
a002b744:  40 00 04 4a  call  0xa002c86c
a002b748:  94 10 20 01  mov  1, %o2
a002b74c:  b0 10 20 00  clr  %i0
a002b750:  81 c7 e0 08  ret
a002b754:  81 e8 00 00  restore
