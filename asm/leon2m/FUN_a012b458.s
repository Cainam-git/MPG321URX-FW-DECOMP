# leon2m FUN_a012b458 0xa012b458-0xa012b7b8 (864 bytes)
a012b458:  9d e3 bf 68  save  %sp, -152, %sp
a012b45c:  25 2a 00 b8  sethi  %hi(0xa802e000), %l2
a012b460:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012b464:  96 14 a1 a0  or  %l2, 0x1a0, %o3
a012b468:  d2 0a e0 2c  ldub  [ %o3 + 0x2c ], %o1
a012b46c:  95 2e 20 02  sll  %i0, 2, %o2
a012b470:  2b 2a 00 b6  sethi  %hi(0xa802d800), %l5
a012b474:  91 3a 40 0a  sra  %o1, %o2, %o0
a012b478:  98 15 60 ae  or  %l5, 0xae, %o4
a012b47c:  a0 5e 20 16  smul  %i0, 0x16, %l0
a012b480:  82 0a 20 0f  and  %o0, 0xf, %g1
a012b484:  9a 04 00 0c  add  %l0, %o4, %o5
a012b488:  c2 2b 60 02  stb  %g1, [ %o5 + 2 ]
a012b48c:  90 10 00 01  mov  %g1, %o0
a012b490:  c0 27 bf e8  clr  [ %fp + -24 ]
a012b494:  c0 27 bf e0  clr  [ %fp + -32 ]
a012b498:  80 a0 60 02  cmp  %g1, 2
a012b49c:  18 80 00 7b  bgu  0xa012b688
a012b4a0:  a2 10 00 0c  mov  %o4, %l1
a012b4a4:  d2 0a e0 2f  ldub  [ %o3 + 0x2f ], %o1
a012b4a8:  c2 0a e0 30  ldub  [ %o3 + 0x30 ], %g1
a012b4ac:  9b 2a 60 08  sll  %o1, 8, %o5
a012b4b0:  a8 10 40 0d  or  %g1, %o5, %l4
a012b4b4:  99 2e 20 03  sll  %i0, 3, %o4
a012b4b8:  a7 3d 00 0c  sra  %l4, %o4, %l3
a012b4bc:  9e 02 00 08  add  %o0, %o0, %o7
a012b4c0:  96 0c e0 ff  and  %l3, 0xff, %o3
a012b4c4:  95 3a c0 0f  sra  %o3, %o7, %o2
a012b4c8:  9e 0a a0 03  and  %o2, 3, %o7
a012b4cc:  82 14 a1 a0  or  %l2, 0x1a0, %g1
a012b4d0:  da 00 60 2c  ld  [ %g1 + 0x2c ], %o5
a012b4d4:  99 2b 60 08  sll  %o5, 8, %o4
a012b4d8:  93 33 20 10  srl  %o4, 0x10, %o1
a012b4dc:  95 2e 20 03  sll  %i0, 3, %o2
a012b4e0:  d6 08 60 33  ldub  [ %g1 + 0x33 ], %o3
a012b4e4:  e6 08 60 32  ldub  [ %g1 + 0x32 ], %l3
a012b4e8:  9b 3a 40 0a  sra  %o1, %o2, %o5
a012b4ec:  a9 2e 20 02  sll  %i0, 2, %l4
a012b4f0:  95 3a c0 14  sra  %o3, %l4, %o2
a012b4f4:  99 3c c0 14  sra  %l3, %l4, %o4
a012b4f8:  92 02 00 08  add  %o0, %o0, %o1
a012b4fc:  a8 0b 60 ff  and  %o5, 0xff, %l4
a012b500:  96 0a a0 0f  and  %o2, 0xf, %o3
a012b504:  a6 0b 20 0f  and  %o4, 0xf, %l3
a012b508:  9b 3d 00 09  sra  %l4, %o1, %o5
a012b50c:  93 3a c0 08  sra  %o3, %o0, %o1
a012b510:  99 3c c0 08  sra  %l3, %o0, %o4
a012b514:  94 15 60 ae  or  %l5, 0xae, %o2
a012b518:  82 5e 20 16  smul  %i0, 0x16, %g1
a012b51c:  94 00 40 0a  add  %g1, %o2, %o2
a012b520:  a8 0b 60 03  and  %o5, 3, %l4
a012b524:  a6 0b 20 01  and  %o4, 1, %l3
a012b528:  90 0a 60 01  and  %o1, 1, %o0
a012b52c:  de 2c 40 10  stb  %o7, [ %l1 + %l0 ]
a012b530:  e8 2a a0 01  stb  %l4, [ %o2 + 1 ]
a012b534:  e6 2a a0 07  stb  %l3, [ %o2 + 7 ]
a012b538:  d0 2a a0 06  stb  %o0, [ %o2 + 6 ]
a012b53c:  80 a6 20 00  cmp  %i0, 0
a012b540:  12 80 00 04  bne  0xa012b550
a012b544:  96 10 20 00  clr  %o3
a012b548:  e0 0c a1 a0  ldub  [ %l2 + 0x1a0 ], %l0
a012b54c:  96 0c 20 01  and  %l0, 1, %o3
a012b550:  e8 04 a1 a0  ld  [ %l2 + 0x1a0 ], %l4
a012b554:  9f 35 20 19  srl  %l4, 0x19, %o7
a012b558:  90 15 60 ae  or  %l5, 0xae, %o0
a012b55c:  a6 5e 20 16  smul  %i0, 0x16, %l3
a012b560:  98 04 c0 08  add  %l3, %o0, %o4
a012b564:  9a 0b e0 01  and  %o7, 1, %o5
a012b568:  a2 10 20 1b  mov  0x1b, %l1
a012b56c:  d6 2a a0 03  stb  %o3, [ %o2 + 3 ]
a012b570:  e2 2b 20 08  stb  %l1, [ %o4 + 8 ]
a012b574:  c0 2b 20 04  clrb  [ %o4 + 4 ]
a012b578:  80 a3 60 01  cmp  %o5, 1
a012b57c:  02 80 00 47  be  0xa012b698
a012b580:  c0 2b 20 05  clrb  [ %o4 + 5 ]
a012b584:  c0 2b 20 09  clrb  [ %o4 + 9 ]
a012b588:  de 04 a1 a0  ld  [ %l2 + 0x1a0 ], %o7
a012b58c:  a5 33 e0 1b  srl  %o7, 0x1b, %l2
a012b590:  a6 15 60 ae  or  %l5, 0xae, %l3
a012b594:  a0 0c a0 01  and  %l2, 1, %l0
a012b598:  a8 5e 20 16  smul  %i0, 0x16, %l4
a012b59c:  82 05 00 13  add  %l4, %l3, %g1
a012b5a0:  a2 10 20 01  mov  1, %l1
a012b5a4:  a4 10 22 58  mov  0x258, %l2
a012b5a8:  e2 28 60 14  stb  %l1, [ %g1 + 0x14 ]
a012b5ac:  e2 28 60 0e  stb  %l1, [ %g1 + 0xe ]
a012b5b0:  e0 28 60 0f  stb  %l0, [ %g1 + 0xf ]
a012b5b4:  c0 28 60 0b  clrb  [ %g1 + 0xb ]
a012b5b8:  c0 28 60 0c  clrb  [ %g1 + 0xc ]
a012b5bc:  c0 28 60 0d  clrb  [ %g1 + 0xd ]
a012b5c0:  e2 28 60 10  stb  %l1, [ %g1 + 0x10 ]
a012b5c4:  e4 30 60 12  sth  %l2, [ %g1 + 0x12 ]
a012b5c8:  da 14 c0 14  lduh  [ %l3 + %l4 ], %o5
a012b5cc:  d2 10 60 08  lduh  [ %g1 + 8 ], %o1
a012b5d0:  d0 10 60 0a  lduh  [ %g1 + 0xa ], %o0
a012b5d4:  e6 10 60 14  lduh  [ %g1 + 0x14 ], %l3
a012b5d8:  d8 10 60 02  lduh  [ %g1 + 2 ], %o4
a012b5dc:  d6 10 60 04  lduh  [ %g1 + 4 ], %o3
a012b5e0:  d4 10 60 06  lduh  [ %g1 + 6 ], %o2
a012b5e4:  de 10 60 0c  lduh  [ %g1 + 0xc ], %o7
a012b5e8:  e0 10 60 0e  lduh  [ %g1 + 0xe ], %l0
a012b5ec:  e2 10 60 10  lduh  [ %g1 + 0x10 ], %l1
a012b5f0:  d2 37 bf d0  sth  %o1, [ %fp + -48 ]
a012b5f4:  d0 37 bf d2  sth  %o0, [ %fp + -46 ]
a012b5f8:  90 10 00 18  mov  %i0, %o0
a012b5fc:  da 37 bf c8  sth  %o5, [ %fp + -56 ]
a012b600:  d8 37 bf ca  sth  %o4, [ %fp + -54 ]
a012b604:  d6 37 bf cc  sth  %o3, [ %fp + -52 ]
a012b608:  d4 37 bf ce  sth  %o2, [ %fp + -50 ]
a012b60c:  de 37 bf d4  sth  %o7, [ %fp + -44 ]
a012b610:  e0 37 bf d6  sth  %l0, [ %fp + -42 ]
a012b614:  e2 37 bf d8  sth  %l1, [ %fp + -40 ]
a012b618:  e4 37 bf da  sth  %l2, [ %fp + -38 ]
a012b61c:  e6 37 bf dc  sth  %l3, [ %fp + -36 ]
a012b620:  40 00 30 d7  call  0xa013797c
a012b624:  92 07 bf c8  add  %fp, -56, %o1
a012b628:  80 a6 20 00  cmp  %i0, 0
a012b62c:  12 80 00 11  bne  0xa012b670
a012b630:  90 10 20 00  clr  %o0
a012b634:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a012b638:  d0 0a 61 4a  ldub  [ %o1 + 0x14a ], %o0	! 0xa802e14a
a012b63c:  a8 0a 20 ff  and  %o0, 0xff, %l4
a012b640:  7f ff e6 9a  call  0xa01250a8
a012b644:  90 10 00 14  mov  %l4, %o0
a012b648:  90 0a 20 ff  and  %o0, 0xff, %o0
a012b64c:  80 a2 20 02  cmp  %o0, 2
a012b650:  02 80 00 14  be  0xa012b6a0
a012b654:  92 07 bf f0  add  %fp, -16, %o1
a012b658:  2b 00 06 93  sethi  %hi(0x1a4c00), %l5
a012b65c:  7f fe ce c5  call  0xa00df170
a012b660:  90 15 62 b8  or  %l5, 0x2b8, %o0	! 0x1a4eb8
a012b664:  01 00 00 00  nop
a012b668:  01 00 00 00  nop
a012b66c:  30 bf ff fe  b,a   0xa012b664
a012b670:  80 a6 20 01  cmp  %i0, 1
a012b674:  12 bf ff f3  bne  0xa012b640
a012b678:  a8 0a 20 ff  and  %o0, 0xff, %l4
a012b67c:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a012b680:  10 bf ff ef  b  0xa012b63c
a012b684:  d0 0a a1 5c  ldub  [ %o2 + 0x15c ], %o0	! 0xa802e15c
a012b688:  de 0a e0 31  ldub  [ %o3 + 0x31 ], %o7
a012b68c:  97 3b c0 0a  sra  %o7, %o2, %o3
a012b690:  10 bf ff 8f  b  0xa012b4cc
a012b694:  9e 0a e0 0f  and  %o3, 0xf, %o7
a012b698:  10 bf ff bc  b  0xa012b588
a012b69c:  da 2b 20 09  stb  %o5, [ %o4 + 9 ]
a012b6a0:  7f ff e5 3a  call  0xa0124b88
a012b6a4:  90 10 00 14  mov  %l4, %o0
a012b6a8:  e2 07 bf f0  ld  [ %fp + -16 ], %l1
a012b6ac:  a5 34 60 16  srl  %l1, 0x16, %l2
a012b6b0:  9a 07 bf f8  add  %fp, -8, %o5
a012b6b4:  a4 0c a0 03  and  %l2, 3, %l2
a012b6b8:  99 34 60 14  srl  %l1, 0x14, %o4
a012b6bc:  95 34 60 0f  srl  %l1, 0xf, %o2
a012b6c0:  94 0a a0 01  and  %o2, 1, %o2
a012b6c4:  a6 03 40 12  add  %o5, %l2, %l3
a012b6c8:  98 0b 20 03  and  %o4, 3, %o4
a012b6cc:  97 34 60 12  srl  %l1, 0x12, %o3
a012b6d0:  93 34 60 0e  srl  %l1, 0xe, %o1
a012b6d4:  d4 2c ff e8  stb  %o2, [ %l3 + -24 ]
a012b6d8:  92 0a 60 01  and  %o1, 1, %o1
a012b6dc:  82 03 40 0c  add  %o5, %o4, %g1
a012b6e0:  96 0a e0 03  and  %o3, 3, %o3
a012b6e4:  91 34 60 10  srl  %l1, 0x10, %o0
a012b6e8:  9f 34 60 0d  srl  %l1, 0xd, %o7
a012b6ec:  d2 28 7f e8  stb  %o1, [ %g1 + -24 ]
a012b6f0:  9e 0b e0 01  and  %o7, 1, %o7
a012b6f4:  a0 03 40 0b  add  %o5, %o3, %l0
a012b6f8:  90 0a 20 03  and  %o0, 3, %o0
a012b6fc:  a7 34 60 0c  srl  %l1, 0xc, %l3
a012b700:  de 2c 3f e8  stb  %o7, [ %l0 + -24 ]
a012b704:  82 03 40 08  add  %o5, %o0, %g1
a012b708:  a6 0c e0 01  and  %l3, 1, %l3
a012b70c:  e6 28 7f e8  stb  %l3, [ %g1 + -24 ]
a012b710:  da 0f bf e1  ldub  [ %fp + -31 ], %o5
a012b714:  e0 0f bf e0  ldub  [ %fp + -32 ], %l0
a012b718:  83 2b 60 02  sll  %o5, 2, %g1
a012b71c:  a1 2c 20 03  sll  %l0, 3, %l0
a012b720:  a0 14 00 01  or  %l0, %g1, %l0
a012b724:  da 0f bf e2  ldub  [ %fp + -30 ], %o5
a012b728:  83 2c a0 06  sll  %l2, 6, %g1
a012b72c:  99 2b 20 04  sll  %o4, 4, %o4
a012b730:  a4 10 40 0c  or  %g1, %o4, %l2
a012b734:  9a 03 40 0d  add  %o5, %o5, %o5
a012b738:  a0 14 00 0d  or  %l0, %o5, %l0
a012b73c:  99 2a e0 02  sll  %o3, 2, %o4
a012b740:  9a 14 80 0c  or  %l2, %o4, %o5
a012b744:  c2 0f bf e3  ldub  [ %fp + -29 ], %g1
a012b748:  98 14 00 01  or  %l0, %g1, %o4
a012b74c:  97 34 60 0b  srl  %l1, 0xb, %o3
a012b750:  a0 0b 20 ff  and  %o4, 0xff, %l0
a012b754:  a4 13 40 08  or  %o5, %o0, %l2
a012b758:  a2 0a e0 01  and  %o3, 1, %l1
a012b75c:  d4 2f bf e8  stb  %o2, [ %fp + -24 ]
a012b760:  d2 2f bf e9  stb  %o1, [ %fp + -23 ]
a012b764:  de 2f bf ea  stb  %o7, [ %fp + -22 ]
a012b768:  7f ff e6 57  call  0xa01250c4
a012b76c:  e6 2f bf eb  stb  %l3, [ %fp + -21 ]
a012b770:  94 0a 20 ff  and  %o0, 0xff, %o2
a012b774:  a7 3a 80 14  sra  %o2, %l4, %l3
a012b778:  92 15 60 ae  or  %l5, 0xae, %o1
a012b77c:  9e 5e 20 16  smul  %i0, 0x16, %o7
a012b780:  82 03 c0 09  add  %o7, %o1, %g1
a012b784:  98 0c e0 01  and  %l3, 1, %o4
a012b788:  e2 28 60 0b  stb  %l1, [ %g1 + 0xb ]
a012b78c:  e4 28 60 08  stb  %l2, [ %g1 + 8 ]
a012b790:  e0 28 60 0a  stb  %l0, [ %g1 + 0xa ]
a012b794:  90 10 00 18  mov  %i0, %o0
a012b798:  92 0c a0 ff  and  %l2, 0xff, %o1
a012b79c:  94 0c 20 ff  and  %l0, 0xff, %o2
a012b7a0:  96 0c 60 01  and  %l1, 1, %o3
a012b7a4:  40 00 31 59  call  0xa0137d08
a012b7a8:  98 1b 20 01  xor  %o4, 1, %o4
a012b7ac:  01 00 00 00  nop
a012b7b0:  81 c7 e0 08  ret
a012b7b4:  81 e8 00 00  restore
