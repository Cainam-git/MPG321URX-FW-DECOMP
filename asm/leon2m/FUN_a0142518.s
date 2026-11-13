# leon2m FUN_a0142518 0xa0142518-0xa01427d4 (700 bytes)
a0142518:  9d e3 bf 98  save  %sp, -104, %sp
a014251c:  a2 0e 20 ff  and  %i0, 0xff, %l1
a0142520:  7f ff ea 0b  call  0xa013cd4c
a0142524:  90 10 00 11  mov  %l1, %o0
a0142528:  da 02 00 00  ld  [ %o0 ], %o5
a014252c:  82 0b 60 0e  and  %o5, 0xe, %g1
a0142530:  80 a0 60 04  cmp  %g1, 4
a0142534:  02 80 00 a6  be  0xa01427cc
a0142538:  a0 10 00 08  mov  %o0, %l0
a014253c:  91 33 60 01  srl  %o5, 1, %o0
a0142540:  82 8a 20 07  andcc  %o0, 7, %g1
a0142544:  a4 10 20 00  clr  %l2
a0142548:  12 80 00 32  bne  0xa0142610
a014254c:  98 10 20 03  mov  3, %o4
a0142550:  98 10 20 00  clr  %o4
a0142554:  29 2a 00 b8  sethi  %hi(0xa802e000), %l4
a0142558:  da 05 23 d0  ld  [ %l4 + 0x3d0 ], %o5	! 0xa802e3d0
a014255c:  13 00 80 00  sethi  %hi(0x2000000), %o1
a0142560:  80 8b 40 09  btst  %o5, %o1
a0142564:  02 80 00 06  be  0xa014257c
a0142568:  a6 10 00 0c  mov  %o4, %l3
a014256c:  d4 04 20 70  ld  [ %l0 + 0x70 ], %o2
a0142570:  80 a2 a0 00  cmp  %o2, 0
a0142574:  06 80 00 3d  bl  0xa0142668
a0142578:  01 00 00 00  nop
a014257c:  40 00 02 44  call  0xa0142e8c
a0142580:  90 10 00 11  mov  %l1, %o0
a0142584:  90 0a 20 ff  and  %o0, 0xff, %o0
a0142588:  80 a2 20 05  cmp  %o0, 5
a014258c:  02 80 00 42  be  0xa0142694
a0142590:  b0 0c e0 ff  and  %l3, 0xff, %i0
a0142594:  b3 2c a0 10  sll  %l2, 0x10, %i1
a0142598:  a7 36 60 10  srl  %i1, 0x10, %l3
a014259c:  80 a4 e0 2f  cmp  %l3, 0x2f
a01425a0:  18 80 00 2e  bgu  0xa0142658
a01425a4:  90 10 00 11  mov  %l1, %o0
a01425a8:  96 10 20 30  mov  0x30, %o3
a01425ac:  94 22 c0 12  sub  %o3, %l2, %o2
a01425b0:  7f fe dc d1  call  0xa00f98f4
a01425b4:  92 0a a0 ff  and  %o2, 0xff, %o1
a01425b8:  33 00 0c 00  sethi  %hi(0x300000), %i1
a01425bc:  e4 05 23 d0  ld  [ %l4 + 0x3d0 ], %l2
a01425c0:  23 00 80 00  sethi  %hi(0x2000000), %l1
a01425c4:  80 8c 80 11  btst  %l2, %l1
a01425c8:  22 80 00 07  be,a   0xa01425e4
a01425cc:  d2 04 00 00  ld  [ %l0 ], %o1
a01425d0:  e8 04 20 70  ld  [ %l0 + 0x70 ], %l4
a01425d4:  80 a5 20 00  cmp  %l4, 0
a01425d8:  26 80 00 13  bl,a   0xa0142624
a01425dc:  c2 04 00 00  ld  [ %l0 ], %g1
a01425e0:  d2 04 00 00  ld  [ %l0 ], %o1
a01425e4:  a1 32 60 0c  srl  %o1, 0xc, %l0
a01425e8:  7f ff 7b 1c  call  0xa0121258
a01425ec:  90 0c 20 0f  and  %l0, 0xf, %o0
a01425f0:  80 8a 20 ff  btst  0xff, %o0
a01425f4:  02 80 00 15  be  0xa0142648
a01425f8:  9b 2e a0 10  sll  %i2, 0x10, %o5
a01425fc:  b5 2e a0 10  sll  %i2, 0x10, %i2
a0142600:  b3 36 60 10  srl  %i1, 0x10, %i1
a0142604:  b5 36 a0 11  srl  %i2, 0x11, %i2
a0142608:  7f ff 76 bc  call  0xa01200f8
a014260c:  81 e8 00 00  restore
a0142610:  80 a0 60 01  cmp  %g1, 1
a0142614:  22 bf ff d0  be,a   0xa0142554
a0142618:  98 10 20 01  mov  1, %o4
a014261c:  10 bf ff cf  b  0xa0142558
a0142620:  29 2a 00 b8  sethi  %hi(0xa802e000), %l4
a0142624:  9f 30 60 0c  srl  %g1, 0xc, %o7
a0142628:  90 0b e0 0f  and  %o7, 0xf, %o0
a014262c:  7f ff 7b 0b  call  0xa0121258
a0142630:  01 00 00 00  nop
a0142634:  98 0a 20 ff  and  %o0, 0xff, %o4
a0142638:  80 a3 20 01  cmp  %o4, 1
a014263c:  32 bf ff ea  bne,a   0xa01425e4
a0142640:  d2 04 00 00  ld  [ %l0 ], %o1
a0142644:  9b 2e a0 10  sll  %i2, 0x10, %o5
a0142648:  b3 36 60 10  srl  %i1, 0x10, %i1
a014264c:  b5 33 60 10  srl  %o5, 0x10, %i2
a0142650:  7f ff 76 aa  call  0xa01200f8
a0142654:  81 e8 00 00  restore
a0142658:  7f fe dc a7  call  0xa00f98f4
a014265c:  92 10 20 00  clr  %o1
a0142660:  10 bf ff d8  b  0xa01425c0
a0142664:  e4 05 23 d0  ld  [ %l4 + 0x3d0 ], %l2
a0142668:  7f ff 7a fc  call  0xa0121258
a014266c:  90 10 00 11  mov  %l1, %o0
a0142670:  96 0a 20 ff  and  %o0, 0xff, %o3
a0142674:  80 a2 e0 01  cmp  %o3, 1
a0142678:  12 bf ff c1  bne  0xa014257c
a014267c:  83 2e 60 10  sll  %i1, 0x10, %g1
a0142680:  b1 30 60 10  srl  %g1, 0x10, %i0
a0142684:  9e 06 20 07  add  %i0, 7, %o7
a0142688:  99 3b e0 03  sra  %o7, 3, %o4
a014268c:  10 bf ff bc  b  0xa014257c
a0142690:  b3 2b 20 03  sll  %o4, 3, %i1
a0142694:  7f fe ec 63  call  0xa00fd820
a0142698:  90 10 00 11  mov  %l1, %o0
a014269c:  90 0a 20 ff  and  %o0, 0xff, %o0
a01426a0:  80 a2 20 b1  cmp  %o0, 0xb1
a01426a4:  02 80 00 46  be  0xa01427bc
a01426a8:  01 00 00 00  nop
a01426ac:  94 1a 20 71  xor  %o0, 0x71, %o2
a01426b0:  80 a0 00 0a  cmp  %g0, %o2
a01426b4:  92 60 3f ff  subx  %g0, -1, %o1
a01426b8:  9a 1a 20 81  xor  %o0, 0x81, %o5
a01426bc:  80 a0 00 0d  cmp  %g0, %o5
a01426c0:  a4 60 3f ff  subx  %g0, -1, %l2
a01426c4:  80 92 40 12  orcc  %o1, %l2, %g0
a01426c8:  12 80 00 1f  bne  0xa0142744
a01426cc:  b0 1a 20 31  xor  %o0, 0x31, %i0
a01426d0:  80 a0 00 18  cmp  %g0, %i0
a01426d4:  98 60 3f ff  subx  %g0, -1, %o4
a01426d8:  9e 1a 20 41  xor  %o0, 0x41, %o7
a01426dc:  80 a0 00 0f  cmp  %g0, %o7
a01426e0:  96 60 3f ff  subx  %g0, -1, %o3
a01426e4:  80 93 00 0b  orcc  %o4, %o3, %g0
a01426e8:  12 80 00 17  bne  0xa0142744
a01426ec:  9a 1a 20 51  xor  %o0, 0x51, %o5
a01426f0:  80 a0 00 0d  cmp  %g0, %o5
a01426f4:  a4 60 3f ff  subx  %g0, -1, %l2
a01426f8:  92 1a 20 61  xor  %o0, 0x61, %o1
a01426fc:  80 a0 00 09  cmp  %g0, %o1
a0142700:  82 60 3f ff  subx  %g0, -1, %g1
a0142704:  80 94 80 01  orcc  %l2, %g1, %g0
a0142708:  12 80 00 0f  bne  0xa0142744
a014270c:  82 10 20 00  clr  %g1
a0142710:  a4 10 00 19  mov  %i1, %l2
a0142714:  93 28 60 10  sll  %g1, 0x10, %o1
a0142718:  b3 2c a0 10  sll  %l2, 0x10, %i1
a014271c:  80 a6 40 09  cmp  %i1, %o1
a0142720:  08 80 00 04  bleu  0xa0142730
a0142724:  b0 0c e0 ff  and  %l3, 0xff, %i0
a0142728:  90 04 a0 22  add  %l2, 0x22, %o0
a014272c:  93 2a 20 10  sll  %o0, 0x10, %o1
a0142730:  93 32 60 10  srl  %o1, 0x10, %o1
a0142734:  7f ff 75 fd  call  0xa011ff28
a0142738:  90 10 00 18  mov  %i0, %o0
a014273c:  10 bf ff 97  b  0xa0142598
a0142740:  b3 2c a0 10  sll  %l2, 0x10, %i1
a0142744:  c2 04 00 00  ld  [ %l0 ], %g1
a0142748:  b1 30 60 0c  srl  %g1, 0xc, %i0
a014274c:  98 0e 20 0f  and  %i0, 0xf, %o4
a0142750:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a0142754:  a4 13 e2 24  or  %o7, 0x224, %l2	! 0xa802e224
a0142758:  96 5b 20 2a  smul  %o4, 0x2a, %o3
a014275c:  94 02 c0 12  add  %o3, %l2, %o2
a0142760:  7f ff fe 82  call  0xa0142168
a0142764:  d0 0a a0 0a  ldub  [ %o2 + 0xa ], %o0
a0142768:  90 0a 20 ff  and  %o0, 0xff, %o0
a014276c:  80 a2 20 06  cmp  %o0, 6
a0142770:  18 bf ff e8  bgu  0xa0142710
a0142774:  82 10 20 00  clr  %g1
a0142778:  da 04 00 00  ld  [ %l0 ], %o5
a014277c:  93 33 60 0c  srl  %o5, 0xc, %o1
a0142780:  82 0a 60 0f  and  %o1, 0xf, %g1
a0142784:  b0 58 60 2a  smul  %g1, 0x2a, %i0
a0142788:  9e 06 00 12  add  %i0, %l2, %o7
a014278c:  d0 0b e0 0a  ldub  [ %o7 + 0xa ], %o0
a0142790:  7f ff fe 76  call  0xa0142168
a0142794:  01 00 00 00  nop
a0142798:  98 0a 20 ff  and  %o0, 0xff, %o4
a014279c:  97 2b 20 03  sll  %o4, 3, %o3
a01427a0:  94 02 c0 0c  add  %o3, %o4, %o2
a01427a4:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a01427a8:  92 02 80 0a  add  %o2, %o2, %o1
a01427ac:  9a 12 21 16  or  %o0, 0x116, %o5
a01427b0:  a4 02 40 0d  add  %o1, %o5, %l2
a01427b4:  10 bf ff d7  b  0xa0142710
a01427b8:  c2 14 a0 06  lduh  [ %l2 + 6 ], %g1
a01427bc:  7f ff b5 19  call  0xa012fc20
a01427c0:  01 00 00 00  nop
a01427c4:  10 bf ff ba  b  0xa01426ac
a01427c8:  90 0a 20 ff  and  %o0, 0xff, %o0
a01427cc:  81 c7 e0 08  ret
a01427d0:  81 e8 00 00  restore
