# leon2m FUN_a01413d0 0xa01413d0-0xa0141840 (60 bytes)
a01413d0:  9d e3 bf 98  save  %sp, -104, %sp
a01413d4:  7f ff 8b 8a  call  0xa01241fc
a01413d8:  23 2a 00 b8  sethi  %hi(0xa802e000), %l1
a01413dc:  c2 0c 61 10  ldub  [ %l1 + 0x110 ], %g1	! 0xa802e110
a01413e0:  80 a0 60 09  cmp  %g1, 9
a01413e4:  18 80 01 15  bgu  0xa0141838
a01413e8:  a0 10 00 08  mov  %o0, %l0
a01413ec:  11 00 03 84  sethi  %hi(0xe1000), %o0
a01413f0:  83 28 60 02  sll  %g1, 2, %g1
a01413f4:  9a 12 22 90  or  %o0, 0x290, %o5
a01413f8:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a01413fc:  81 c3 00 00  jmp  %o4
a0141400:  01 00 00 00  nop
a0141404:  a4 14 61 10  or  %l1, 0x110, %l2
a0141408:  67 fd 30 63  call  0x4008d594
a014140c:  d0 14 a0 02  lduh  [ %l2 + 2 ], %o0
a0141410:  9f 2a 20 10  sll  %o0, 0x10, %o7
a0141414:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a0141418:  91 33 e0 10  srl  %o7, 0x10, %o0
a014141c:  d2 12 a3 b6  lduh  [ %o2 + 0x3b6 ], %o1
a0141420:  80 a2 00 09  cmp  %o0, %o1
a0141424:  08 80 01 05  bleu  0xa0141838
a0141428:  23 00 1c 00  sethi  %hi(0x700000), %l1
a014142c:  d8 04 00 00  ld  [ %l0 ], %o4
a0141430:  80 8b 00 11  btst  %o4, %l1
a0141434:  02 80 00 c8  be  0xa0141754
a0141438:  01 00 00 00  nop
a014143c:  a6 0b 00 11  and  %o4, %l1, %l3
a0141440:  17 00 04 00  sethi  %hi(0x100000), %o3
a0141444:  80 a4 c0 0b  cmp  %l3, %o3
a0141448:  02 80 00 ea  be  0xa01417f0
a014144c:  01 00 00 00  nop
a0141450:  82 0b 00 11  and  %o4, %l1, %g1
a0141454:  23 00 08 00  sethi  %hi(0x200000), %l1
a0141458:  80 a0 40 11  cmp  %g1, %l1
a014145c:  02 80 00 e1  be  0xa01417e0
a0141460:  01 00 00 00  nop
a0141464:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0141468:  a0 10 20 09  mov  9, %l0
a014146c:  67 fd 30 47  call  0x4008d588
a0141470:  e0 2b 21 10  stb  %l0, [ %o4 + 0x110 ]
a0141474:  10 80 00 f1  b  0xa0141838
a0141478:  d0 34 a0 02  sth  %o0, [ %l2 + 2 ]
a014147c:  94 14 61 10  or  %l1, 0x110, %o2
a0141480:  67 fd 30 45  call  0x4008d594
a0141484:  d0 12 a0 02  lduh  [ %o2 + 2 ], %o0
a0141488:  91 2a 20 10  sll  %o0, 0x10, %o0
a014148c:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a0141490:  9b 32 20 10  srl  %o0, 0x10, %o5
a0141494:  e4 12 63 b4  lduh  [ %o1 + 0x3b4 ], %l2
a0141498:  80 a3 40 12  cmp  %o5, %l2
a014149c:  08 80 00 e7  bleu  0xa0141838
a01414a0:  01 00 00 00  nop
a01414a4:  7f ff 8c f4  call  0xa0124874
a01414a8:  01 00 00 00  nop
a01414ac:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a01414b0:  de 0b 60 09  ldub  [ %o5 + 9 ], %o7	! 0xa802cc09
a01414b4:  80 a3 e0 01  cmp  %o7, 1
a01414b8:  22 80 00 bd  be,a   0xa01417ac
a01414bc:  c0 2b 60 09  clrb  [ %o5 + 9 ]
a01414c0:  82 10 20 01  mov  1, %g1
a01414c4:  c2 2c 61 10  stb  %g1, [ %l1 + 0x110 ]
a01414c8:  67 fd 30 30  call  0x4008d588
a01414cc:  a6 14 61 10  or  %l1, 0x110, %l3
a01414d0:  10 80 00 da  b  0xa0141838
a01414d4:  d0 34 e0 02  sth  %o0, [ %l3 + 2 ]
a01414d8:  a0 14 61 10  or  %l1, 0x110, %l0
a01414dc:  d6 14 20 04  lduh  [ %l0 + 4 ], %o3
a01414e0:  1f 3f ff e0  sethi  %hi(0xffff8000), %o7
a01414e4:  94 0a c0 0f  and  %o3, %o7, %o2
a01414e8:  93 2a a0 10  sll  %o2, 0x10, %o1
a01414ec:  80 a2 60 00  cmp  %o1, 0
a01414f0:  02 80 00 d2  be  0xa0141838
a01414f4:  82 10 20 02  mov  2, %g1
a01414f8:  10 80 00 d0  b  0xa0141838
a01414fc:  c2 2c 61 10  stb  %g1, [ %l1 + 0x110 ]
a0141500:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a0141504:  a0 14 61 10  or  %l1, 0x110, %l0
a0141508:  c0 2b 60 08  clrb  [ %o5 + 8 ]
a014150c:  67 fd 30 22  call  0x4008d594
a0141510:  d0 14 20 02  lduh  [ %l0 + 2 ], %o0
a0141514:  83 2a 20 10  sll  %o0, 0x10, %g1
a0141518:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014151c:  a7 30 60 10  srl  %g1, 0x10, %l3
a0141520:  e4 13 23 b8  lduh  [ %o4 + 0x3b8 ], %l2
a0141524:  80 a4 c0 12  cmp  %l3, %l2
a0141528:  08 80 00 c4  bleu  0xa0141838
a014152c:  01 00 00 00  nop
a0141530:  7f ff 8c c8  call  0xa0124850
a0141534:  01 00 00 00  nop
a0141538:  d4 14 20 04  lduh  [ %l0 + 4 ], %o2
a014153c:  13 3f ff e0  sethi  %hi(0xffff8000), %o1
a0141540:  90 2a 80 09  andn  %o2, %o1, %o0
a0141544:  67 fd 30 11  call  0x4008d588
a0141548:  d0 34 20 04  sth  %o0, [ %l0 + 4 ]
a014154c:  82 10 20 03  mov  3, %g1
a0141550:  d0 34 20 02  sth  %o0, [ %l0 + 2 ]
a0141554:  10 80 00 b9  b  0xa0141838
a0141558:  c2 2c 61 10  stb  %g1, [ %l1 + 0x110 ]
a014155c:  a2 14 61 10  or  %l1, 0x110, %l1
a0141560:  67 fd 30 0d  call  0x4008d594
a0141564:  d0 14 60 02  lduh  [ %l1 + 2 ], %o0
a0141568:  97 2a 20 10  sll  %o0, 0x10, %o3
a014156c:  80 a2 e0 00  cmp  %o3, 0
a0141570:  02 80 00 b2  be  0xa0141838
a0141574:  27 00 1c 00  sethi  %hi(0x700000), %l3
a0141578:  e4 04 00 00  ld  [ %l0 ], %l2
a014157c:  a0 0c 80 13  and  %l2, %l3, %l0
a0141580:  1f 00 08 00  sethi  %hi(0x200000), %o7
a0141584:  80 a4 00 0f  cmp  %l0, %o7
a0141588:  02 80 00 8e  be  0xa01417c0
a014158c:  01 00 00 00  nop
a0141590:  67 fd 2f fe  call  0x4008d588
a0141594:  01 00 00 00  nop
a0141598:  d0 34 60 02  sth  %o0, [ %l1 + 2 ]
a014159c:  98 10 20 04  mov  4, %o4
a01415a0:  23 2a 00 b8  sethi  %hi(0xa802e000), %l1
a01415a4:  10 80 00 a5  b  0xa0141838
a01415a8:  d8 2c 61 10  stb  %o4, [ %l1 + 0x110 ]	! 0xa802e110
a01415ac:  a6 14 61 10  or  %l1, 0x110, %l3
a01415b0:  67 fd 2f f9  call  0x4008d594
a01415b4:  d0 14 e0 02  lduh  [ %l3 + 2 ], %o0
a01415b8:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a01415bc:  a4 12 63 78  or  %o1, 0x378, %l2	! 0xa802e378
a01415c0:  91 2a 20 10  sll  %o0, 0x10, %o0
a01415c4:  9b 32 20 10  srl  %o0, 0x10, %o5
a01415c8:  c2 14 a0 38  lduh  [ %l2 + 0x38 ], %g1
a01415cc:  80 a3 40 01  cmp  %o5, %g1
a01415d0:  08 80 00 9a  bleu  0xa0141838
a01415d4:  17 00 1c 00  sethi  %hi(0x700000), %o3
a01415d8:  de 04 00 00  ld  [ %l0 ], %o7
a01415dc:  90 0b c0 0b  and  %o7, %o3, %o0
a01415e0:  15 00 04 00  sethi  %hi(0x100000), %o2
a01415e4:  80 a2 00 0a  cmp  %o0, %o2
a01415e8:  02 80 00 79  be  0xa01417cc
a01415ec:  80 a2 20 00  cmp  %o0, 0
a01415f0:  02 80 00 5d  be  0xa0141764
a01415f4:  21 00 08 00  sethi  %hi(0x200000), %l0
a01415f8:  80 a2 00 10  cmp  %o0, %l0
a01415fc:  02 80 00 83  be  0xa0141808
a0141600:  01 00 00 00  nop
a0141604:  67 fd 2f e1  call  0x4008d588
a0141608:  01 00 00 00  nop
a014160c:  92 14 61 10  or  %l1, 0x110, %o1
a0141610:  d0 32 60 02  sth  %o0, [ %o1 + 2 ]
a0141614:  90 10 20 05  mov  5, %o0
a0141618:  10 80 00 88  b  0xa0141838
a014161c:  d0 2c 61 10  stb  %o0, [ %l1 + 0x110 ]
a0141620:  7f ff 8c db  call  0xa012498c
a0141624:  01 00 00 00  nop
a0141628:  94 0a 20 ff  and  %o0, 0xff, %o2
a014162c:  80 a2 a0 01  cmp  %o2, 1
a0141630:  02 80 00 46  be  0xa0141748
a0141634:  01 00 00 00  nop
a0141638:  a0 14 61 10  or  %l1, 0x110, %l0
a014163c:  67 fd 2f d6  call  0x4008d594
a0141640:  d0 14 20 02  lduh  [ %l0 + 2 ], %o0
a0141644:  a7 2a 20 10  sll  %o0, 0x10, %l3
a0141648:  25 2a 00 b8  sethi  %hi(0xa802e000), %l2
a014164c:  9f 34 e0 10  srl  %l3, 0x10, %o7
a0141650:  d6 14 a3 b2  lduh  [ %l2 + 0x3b2 ], %o3
a0141654:  80 a3 c0 0b  cmp  %o7, %o3
a0141658:  08 80 00 78  bleu  0xa0141838
a014165c:  98 10 20 06  mov  6, %o4
a0141660:  7f ff 8c 8c  call  0xa0124890
a0141664:  d8 2c 61 10  stb  %o4, [ %l1 + 0x110 ]
a0141668:  67 fd 2f c8  call  0x4008d588
a014166c:  01 00 00 00  nop
a0141670:  7f ff 8c a9  call  0xa0124914
a0141674:  d0 34 20 02  sth  %o0, [ %l0 + 2 ]
a0141678:  a0 0a 20 ff  and  %o0, 0xff, %l0
a014167c:  80 a4 20 01  cmp  %l0, 1
a0141680:  02 80 00 04  be  0xa0141690
a0141684:  03 00 06 9a  sethi  %hi(0x1a6800), %g1
a0141688:  7f fe 76 ba  call  0xa00df170
a014168c:  90 10 62 90  or  %g1, 0x290, %o0	! 0x1a6a90
a0141690:  17 2a 00 b3  sethi  %hi(0xa802cc00), %o3
a0141694:  d8 0a e0 09  ldub  [ %o3 + 9 ], %o4	! 0xa802cc09
a0141698:  80 a3 20 01  cmp  %o4, 1
a014169c:  02 80 00 35  be  0xa0141770
a01416a0:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a01416a4:  7f ff 8c d2  call  0xa01249ec
a01416a8:  81 e8 00 00  restore
a01416ac:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a01416b0:  d6 0c 20 08  ldub  [ %l0 + 8 ], %o3	! 0xa802cc08
a01416b4:  80 a2 e0 00  cmp  %o3, 0
a01416b8:  12 80 00 60  bne  0xa0141838
a01416bc:  98 14 61 10  or  %l1, 0x110, %o4
a01416c0:  67 fd 2f b5  call  0x4008d594
a01416c4:  d0 13 20 02  lduh  [ %o4 + 2 ], %o0
a01416c8:  a7 2a 20 10  sll  %o0, 0x10, %l3
a01416cc:  a3 34 e0 10  srl  %l3, 0x10, %l1
a01416d0:  80 a4 60 64  cmp  %l1, 0x64
a01416d4:  08 80 00 59  bleu  0xa0141838
a01416d8:  82 10 20 01  mov  1, %g1
a01416dc:  10 80 00 57  b  0xa0141838
a01416e0:  c2 2c 20 08  stb  %g1, [ %l0 + 8 ]
a01416e4:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a01416e8:  7f ff 8c c8  call  0xa0124a08
a01416ec:  c0 2b 60 08  clrb  [ %o5 + 8 ]	! 0xa802cc08
a01416f0:  7f ff 8c 6f  call  0xa01248ac
a01416f4:  01 00 00 00  nop
a01416f8:  7f ff 8c 4c  call  0xa0124828
a01416fc:  01 00 00 00  nop
a0141700:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0141704:  80 a4 20 01  cmp  %l0, 1
a0141708:  12 bf ff 7c  bne  0xa01414f8
a014170c:  82 10 20 01  mov  1, %g1
a0141710:  7f ff 8c 9f  call  0xa012498c
a0141714:  01 00 00 00  nop
a0141718:  80 8a 20 ff  btst  0xff, %o0
a014171c:  12 80 00 47  bne  0xa0141838
a0141720:  01 00 00 00  nop
a0141724:  7f ff 8c ab  call  0xa01249d0
a0141728:  01 00 00 00  nop
a014172c:  90 10 20 00  clr  %o0	! 0x0
a0141730:  92 10 20 00  clr  %o1
a0141734:  94 10 20 00  clr  %o2
a0141738:  7f ff 15 31  call  0xa0106bfc
a014173c:  96 10 20 00  clr  %o3
a0141740:  10 bf ff 61  b  0xa01414c4
a0141744:  82 10 20 08  mov  8, %g1
a0141748:  7f ff 8c 9b  call  0xa01249b4
a014174c:  a0 14 61 10  or  %l1, 0x110, %l0
a0141750:  30 bf ff bb  b,a   0xa014163c
a0141754:  7f ff 3e a8  call  0xa01111f4
a0141758:  01 00 00 00  nop
a014175c:  10 bf ff 38  b  0xa014143c
a0141760:  d8 04 00 00  ld  [ %l0 ], %o4
a0141764:  7f ff 3f 4e  call  0xa011149c
a0141768:  01 00 00 00  nop
a014176c:  30 bf ff a6  b,a   0xa0141604
a0141770:  c2 0a 61 10  ldub  [ %o1 + 0x110 ], %g1
a0141774:  90 00 7f f9  add  %g1, -7, %o0
a0141778:  9a 0a 20 ff  and  %o0, 0xff, %o5
a014177c:  80 a3 60 02  cmp  %o5, 2
a0141780:  28 80 00 2e  bleu,a   0xa0141838
a0141784:  c0 2a e0 09  clrb  [ %o3 + 9 ]
a0141788:  80 a0 60 01  cmp  %g1, 1
a014178c:  02 80 00 0b  be  0xa01417b8
a0141790:  9e 00 7f fe  add  %g1, -2, %o7
a0141794:  94 0b e0 ff  and  %o7, 0xff, %o2
a0141798:  80 a2 a0 03  cmp  %o2, 3
a014179c:  18 80 00 06  bgu  0xa01417b4
a01417a0:  a4 10 20 07  mov  7, %l2
a01417a4:  10 80 00 25  b  0xa0141838
a01417a8:  d8 2a e0 09  stb  %o4, [ %o3 + 9 ]
a01417ac:  10 bf ff 46  b  0xa01414c4
a01417b0:  82 10 20 02  mov  2, %g1
a01417b4:  e4 2c 61 10  stb  %l2, [ %l1 + 0x110 ]
a01417b8:  10 80 00 20  b  0xa0141838
a01417bc:  c0 2a e0 09  clrb  [ %o3 + 9 ]
a01417c0:  7f ff da 81  call  0xa01381c4
a01417c4:  90 10 20 01  mov  1, %o0
a01417c8:  30 bf ff 72  b,a   0xa0141590
a01417cc:  7f ff 84 09  call  0xa01227f0
a01417d0:  01 00 00 00  nop
a01417d4:  7f ff 91 30  call  0xa0125c94
a01417d8:  01 00 00 00  nop
a01417dc:  30 bf ff 8a  b,a   0xa0141604
a01417e0:  7f ff da 79  call  0xa01381c4
a01417e4:  90 10 20 00  clr  %o0
a01417e8:  10 bf ff 20  b  0xa0141468
a01417ec:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a01417f0:  7f ff 82 f0  call  0xa01223b0
a01417f4:  01 00 00 00  nop
a01417f8:  7f ff 91 29  call  0xa0125c9c
a01417fc:  01 00 00 00  nop
a0141800:  10 bf ff 14  b  0xa0141450
a0141804:  d8 04 00 00  ld  [ %l0 ], %o4
a0141808:  67 fd 2f 63  call  0x4008d594
a014180c:  d0 14 e0 02  lduh  [ %l3 + 2 ], %o0
a0141810:  83 2a 20 10  sll  %o0, 0x10, %g1
a0141814:  d8 14 a0 38  lduh  [ %l2 + 0x38 ], %o4
a0141818:  a7 30 60 10  srl  %g1, 0x10, %l3
a014181c:  a4 03 2b b8  add  %o4, 0xbb8, %l2
a0141820:  80 a4 c0 12  cmp  %l3, %l2
a0141824:  04 bf ff 78  ble  0xa0141604
a0141828:  1b 00 06 9a  sethi  %hi(0x1a6800), %o5
a014182c:  7f fe 76 51  call  0xa00df170
a0141830:  90 13 62 b0  or  %o5, 0x2b0, %o0	! 0x1a6ab0
a0141834:  30 bf ff 74  b,a   0xa0141604
a0141838:  81 c7 e0 08  ret
a014183c:  81 e8 00 00  restore
