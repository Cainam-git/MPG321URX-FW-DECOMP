# leon2m FUN_a009f42c 0xa009f42c-0xa00a012c (3328 bytes)
a009f42c:  9d e3 bf 98  save  %sp, -104, %sp
a009f430:  7f ff 8e 07  call  0xa0082c4c
a009f434:  01 00 00 00  nop
a009f438:  90 0a 20 ff  and  %o0, 0xff, %o0
a009f43c:  80 a2 20 01  cmp  %o0, 1
a009f440:  02 80 03 39  be  0xa00a0124
a009f444:  31 2a 00 b3  sethi  %hi(0xa802cc00), %i0
a009f448:  82 16 23 f4  or  %i0, 0x3f4, %g1	! 0xa802cff4
a009f44c:  d8 10 60 04  lduh  [ %g1 + 4 ], %o4
a009f450:  1b 00 00 18  sethi  %hi(0x6000), %o5
a009f454:  80 8b 40 0c  btst  %o5, %o4
a009f458:  12 80 03 33  bne  0xa00a0124
a009f45c:  b2 10 20 01  mov  1, %i1
a009f460:  b4 10 20 00  clr  %i2
a009f464:  10 80 00 05  b  0xa009f478
a009f468:  a0 10 20 00  clr  %l0
a009f46c:  80 a4 20 03  cmp  %l0, 3
a009f470:  18 80 00 11  bgu  0xa009f4b4
a009f474:  80 8e 60 ff  btst  0xff, %i1
a009f478:  7f ff 83 aa  call  0xa0080320
a009f47c:  90 10 00 10  mov  %l0, %o0
a009f480:  80 8a 20 ff  btst  0xff, %o0
a009f484:  b4 06 a0 01  inc  %i2
a009f488:  90 10 00 10  mov  %l0, %o0
a009f48c:  02 bf ff f8  be  0xa009f46c
a009f490:  a0 0e a0 ff  and  %i2, 0xff, %l0
a009f494:  40 02 91 e0  call  0xa0143c14
a009f498:  01 00 00 00  nop
a009f49c:  92 0a 20 ff  and  %o0, 0xff, %o1
a009f4a0:  80 a2 60 04  cmp  %o1, 4
a009f4a4:  02 bf ff f3  be  0xa009f470
a009f4a8:  80 a4 20 03  cmp  %l0, 3
a009f4ac:  b2 10 20 00  clr  %i1
a009f4b0:  80 8e 60 ff  btst  0xff, %i1
a009f4b4:  12 80 01 4f  bne  0xa009f9f0
a009f4b8:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009f4bc:  e0 04 63 ec  ld  [ %l1 + 0x3ec ], %l0	! 0xa802afec
a009f4c0:  80 a4 21 11  cmp  %l0, 0x111
a009f4c4:  02 80 01 a0  be  0xa009fb44
a009f4c8:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009f4cc:  40 02 91 d2  call  0xa0143c14
a009f4d0:  90 10 20 00  clr  %o0
a009f4d4:  96 0a 20 ff  and  %o0, 0xff, %o3
a009f4d8:  80 a2 e0 0a  cmp  %o3, 0xa
a009f4dc:  02 80 01 6d  be  0xa009fa90
a009f4e0:  de 16 23 f4  lduh  [ %i0 + 0x3f4 ], %o7
a009f4e4:  d2 16 23 f4  lduh  [ %i0 + 0x3f4 ], %o1
a009f4e8:  1b 00 00 10  sethi  %hi(0x4000), %o5
a009f4ec:  80 8b 40 09  btst  %o5, %o1
a009f4f0:  12 80 01 2e  bne  0xa009f9a8
a009f4f4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009f4f8:  40 02 91 c7  call  0xa0143c14
a009f4fc:  90 10 20 00  clr  %o0
a009f500:  90 0a 20 ff  and  %o0, 0xff, %o0
a009f504:  80 a2 20 0a  cmp  %o0, 0xa
a009f508:  12 80 00 9e  bne  0xa009f780
a009f50c:  c2 16 23 f4  lduh  [ %i0 + 0x3f4 ], %g1
a009f510:  80 88 61 00  btst  0x100, %g1
a009f514:  02 80 00 9b  be  0xa009f780
a009f518:  a0 16 23 f4  or  %i0, 0x3f4, %l0
a009f51c:  d2 14 63 ee  lduh  [ %l1 + 0x3ee ], %o1
a009f520:  80 a2 61 0a  cmp  %o1, 0x10a
a009f524:  02 80 00 97  be  0xa009f780
a009f528:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a009f52c:  19 00 00 15  sethi  %hi(0x5400), %o4
a009f530:  d6 12 a0 86  lduh  [ %o2 + 0x86 ], %o3
a009f534:  9a 13 21 aa  or  %o4, 0x1aa, %o5
a009f538:  80 a2 c0 0d  cmp  %o3, %o5
a009f53c:  02 80 00 91  be  0xa009f780
a009f540:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a009f544:  67 ff b8 14  call  0x4008d594
a009f548:  d0 16 a0 38  lduh  [ %i2 + 0x38 ], %o0	! 0xa802d038
a009f54c:  91 2a 20 10  sll  %o0, 0x10, %o0
a009f550:  03 00 00 1d  sethi  %hi(0x7400), %g1
a009f554:  b3 32 20 10  srl  %o0, 0x10, %i1
a009f558:  9e 10 61 30  or  %g1, 0x130, %o7
a009f55c:  80 a6 40 0f  cmp  %i1, %o7
a009f560:  08 80 00 07  bleu  0xa009f57c
a009f564:  01 00 00 00  nop
a009f568:  d2 14 20 0c  lduh  [ %l0 + 0xc ], %o1
a009f56c:  80 a2 60 00  cmp  %o1, 0
a009f570:  12 80 00 03  bne  0xa009f57c
a009f574:  9a 10 20 01  mov  1, %o5
a009f578:  da 34 20 0c  sth  %o5, [ %l0 + 0xc ]
a009f57c:  67 ff b8 06  call  0x4008d594
a009f580:  d0 16 a0 38  lduh  [ %i2 + 0x38 ], %o0
a009f584:  99 2a 20 10  sll  %o0, 0x10, %o4
a009f588:  17 00 00 1c  sethi  %hi(0x7000), %o3
a009f58c:  b5 33 20 10  srl  %o4, 0x10, %i2
a009f590:  a0 12 e1 48  or  %o3, 0x148, %l0
a009f594:  80 a6 80 10  cmp  %i2, %l0
a009f598:  08 80 00 0d  bleu  0xa009f5cc
a009f59c:  b2 16 23 f4  or  %i0, 0x3f4, %i1
a009f5a0:  9e 16 23 f4  or  %i0, 0x3f4, %o7
a009f5a4:  d4 13 e0 0c  lduh  [ %o7 + 0xc ], %o2
a009f5a8:  80 a2 a0 00  cmp  %o2, 0
a009f5ac:  32 80 00 09  bne,a   0xa009f5d0
a009f5b0:  d0 16 60 0c  lduh  [ %i1 + 0xc ], %o0
a009f5b4:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a009f5b8:  f2 0c 23 f0  ldub  [ %l0 + 0x3f0 ], %i1	! 0xa802aff0
a009f5bc:  80 a6 60 00  cmp  %i1, 0
a009f5c0:  02 80 01 d4  be  0xa009fd10
a009f5c4:  01 00 00 00  nop
a009f5c8:  b2 16 23 f4  or  %i0, 0x3f4, %i1
a009f5cc:  d0 16 60 0c  lduh  [ %i1 + 0xc ], %o0
a009f5d0:  80 a2 20 00  cmp  %o0, 0
a009f5d4:  22 80 00 72  be,a   0xa009f79c
a009f5d8:  e0 04 63 ec  ld  [ %l1 + 0x3ec ], %l0
a009f5dc:  40 02 99 47  call  0xa0145af8
a009f5e0:  90 10 20 10  mov  0x10, %o0
a009f5e4:  93 2a 20 10  sll  %o0, 0x10, %o1
a009f5e8:  80 a2 60 00  cmp  %o1, 0
a009f5ec:  02 80 00 0e  be  0xa009f624
a009f5f0:  b4 10 20 00  clr  %i2
a009f5f4:  30 80 01 b2  b,a   0xa009fcbc
a009f5f8:  40 02 21 04  call  0xa0127a08
a009f5fc:  01 00 00 00  nop
a009f600:  a0 10 00 08  mov  %o0, %l0
a009f604:  40 02 99 3d  call  0xa0145af8
a009f608:  90 10 20 0d  mov  0xd, %o0
a009f60c:  97 2a 20 10  sll  %o0, 0x10, %o3
a009f610:  9b 32 e0 10  srl  %o3, 0x10, %o5
a009f614:  80 a4 00 0d  cmp  %l0, %o5
a009f618:  14 80 00 09  bg  0xa009f63c
a009f61c:  98 0e a0 ff  and  %i2, 0xff, %o4
a009f620:  b4 06 a0 01  inc  %i2
a009f624:  40 02 20 f7  call  0xa0127a00
a009f628:  b2 0e a0 ff  and  %i2, 0xff, %i1
a009f62c:  80 a6 40 08  cmp  %i1, %o0
a009f630:  06 bf ff f2  bl  0xa009f5f8
a009f634:  90 10 00 19  mov  %i1, %o0
a009f638:  98 0e a0 ff  and  %i2, 0xff, %o4
a009f63c:  b4 16 23 f4  or  %i0, 0x3f4, %i2
a009f640:  d8 36 a0 10  sth  %o4, [ %i2 + 0x10 ]
a009f644:  40 02 20 ba  call  0xa012792c
a009f648:  01 00 00 00  nop
a009f64c:  80 8a 20 ff  btst  0xff, %o0
a009f650:  12 80 00 53  bne  0xa009f79c
a009f654:  e0 04 63 ec  ld  [ %l1 + 0x3ec ], %l0
a009f658:  40 02 20 bb  call  0xa0127944
a009f65c:  01 00 00 00  nop
a009f660:  80 8a 20 ff  btst  0xff, %o0
a009f664:  12 80 00 4e  bne  0xa009f79c
a009f668:  e0 04 63 ec  ld  [ %l1 + 0x3ec ], %l0
a009f66c:  a0 16 23 f4  or  %i0, 0x3f4, %l0
a009f670:  da 14 20 14  lduh  [ %l0 + 0x14 ], %o5
a009f674:  17 3f ff e0  sethi  %hi(0xffff8000), %o3
a009f678:  82 0b 40 0b  and  %o5, %o3, %g1
a009f67c:  b3 28 60 10  sll  %g1, 0x10, %i1
a009f680:  80 a6 60 00  cmp  %i1, 0
a009f684:  12 80 00 46  bne  0xa009f79c
a009f688:  e0 04 63 ec  ld  [ %l1 + 0x3ec ], %l0
a009f68c:  40 02 99 1b  call  0xa0145af8
a009f690:  90 10 20 0d  mov  0xd, %o0
a009f694:  b2 10 00 08  mov  %o0, %i1
a009f698:  40 02 99 18  call  0xa0145af8
a009f69c:  90 10 20 0b  mov  0xb, %o0
a009f6a0:  b4 0a 20 ff  and  %o0, 0xff, %i2
a009f6a4:  a0 0e 60 ff  and  %i1, 0xff, %l0
a009f6a8:  90 10 00 10  mov  %l0, %o0
a009f6ac:  40 00 47 ea  call  0xa00b1654
a009f6b0:  92 10 00 1a  mov  %i2, %o1
a009f6b4:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a009f6b8:  94 0a 20 ff  and  %o0, 0xff, %o2
a009f6bc:  d8 0e 63 f1  ldub  [ %i1 + 0x3f1 ], %o4
a009f6c0:  80 a2 80 0c  cmp  %o2, %o4
a009f6c4:  02 80 00 07  be  0xa009f6e0
a009f6c8:  90 10 00 10  mov  %l0, %o0
a009f6cc:  40 00 47 e2  call  0xa00b1654
a009f6d0:  92 10 00 1a  mov  %i2, %o1
a009f6d4:  80 8a 20 ff  btst  0xff, %o0
a009f6d8:  12 80 02 1b  bne  0xa009ff44
a009f6dc:  92 10 00 1a  mov  %i2, %o1
a009f6e0:  7f ff fe a9  call  0xa009f184
a009f6e4:  01 00 00 00  nop
a009f6e8:  10 80 00 2d  b  0xa009f79c
a009f6ec:  e0 04 63 ec  ld  [ %l1 + 0x3ec ], %l0
a009f6f0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a009f6f4:  67 ff b7 a8  call  0x4008d594
a009f6f8:  d0 12 60 3c  lduh  [ %o1 + 0x3c ], %o0	! 0xa802d03c
a009f6fc:  9f 2a 20 10  sll  %o0, 0x10, %o7
a009f700:  1b 00 00 3a  sethi  %hi(0xe800), %o5
a009f704:  a1 33 e0 10  srl  %o7, 0x10, %l0
a009f708:  a2 13 62 60  or  %o5, 0x260, %l1
a009f70c:  80 a4 00 11  cmp  %l0, %l1
a009f710:  08 80 02 85  bleu  0xa00a0124
a009f714:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009f718:  96 14 22 90  or  %l0, 0x290, %o3	! 0xa802d290
a009f71c:  11 30 00 00  sethi  %hi(0xc0000000), %o0
a009f720:  d8 02 e1 dc  ld  [ %o3 + 0x1dc ], %o4
a009f724:  82 0b 00 08  and  %o4, %o0, %g1
a009f728:  80 a0 40 08  cmp  %g1, %o0
a009f72c:  02 80 02 18  be  0xa009ff8c
a009f730:  80 a3 20 00  cmp  %o4, 0
a009f734:  26 80 00 05  bl,a   0xa009f748
a009f738:  f2 06 80 00  ld  [ %i2 ], %i1
a009f73c:  b0 10 20 35  mov  0x35, %i0
a009f740:  f0 26 63 ec  st  %i0, [ %i1 + 0x3ec ]
a009f744:  f2 06 80 00  ld  [ %i2 ], %i1
a009f748:  b4 06 7f cb  add  %i1, -53, %i2
a009f74c:  92 0e a0 ff  and  %i2, 0xff, %o1
a009f750:  40 00 46 2d  call  0xa00b1004
a009f754:  90 10 20 07  mov  7, %o0
a009f758:  96 14 22 90  or  %l0, 0x290, %o3
a009f75c:  de 02 e1 dc  ld  [ %o3 + 0x1dc ], %o7
a009f760:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a009f764:  94 13 c0 0d  or  %o7, %o5, %o2
a009f768:  23 10 00 00  sethi  %hi(0x40000000), %l1
a009f76c:  a0 12 80 11  or  %o2, %l1, %l0
a009f770:  e0 22 e1 dc  st  %l0, [ %o3 + 0x1dc ]
a009f774:  c0 2a e1 e5  clrb  [ %o3 + 0x1e5 ]
a009f778:  10 80 02 6b  b  0xa00a0124
a009f77c:  c0 2a e1 e4  clrb  [ %o3 + 0x1e4 ]
a009f780:  40 02 9f e9  call  0xa0147724
a009f784:  01 00 00 00  nop
a009f788:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a009f78c:  d0 32 60 38  sth  %o0, [ %o1 + 0x38 ]	! 0xa802d038
a009f790:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a009f794:  c0 2a 23 f0  clrb  [ %o0 + 0x3f0 ]	! 0xa802aff0
a009f798:  e0 04 63 ec  ld  [ %l1 + 0x3ec ], %l0
a009f79c:  80 a0 00 10  cmp  %g0, %l0
a009f7a0:  82 60 3f ff  subx  %g0, -1, %g1
a009f7a4:  96 1c 21 11  xor  %l0, 0x111, %o3
a009f7a8:  80 a0 00 0b  cmp  %g0, %o3
a009f7ac:  9a 60 3f ff  subx  %g0, -1, %o5
a009f7b0:  80 90 40 0d  orcc  %g1, %o5, %g0
a009f7b4:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a009f7b8:  12 80 00 77  bne  0xa009f994
a009f7bc:  b4 14 63 ec  or  %l1, 0x3ec, %i2
a009f7c0:  80 a4 21 13  cmp  %l0, 0x113
a009f7c4:  02 80 00 74  be  0xa009f994
a009f7c8:  80 a4 21 12  cmp  %l0, 0x112
a009f7cc:  02 80 00 72  be  0xa009f994
a009f7d0:  80 a4 21 15  cmp  %l0, 0x115
a009f7d4:  02 80 00 70  be  0xa009f994
a009f7d8:  80 a4 21 12  cmp  %l0, 0x112
a009f7dc:  02 80 00 6e  be  0xa009f994
a009f7e0:  80 a4 21 0e  cmp  %l0, 0x10e
a009f7e4:  02 80 01 0a  be  0xa009fc0c
a009f7e8:  80 a4 21 0d  cmp  %l0, 0x10d
a009f7ec:  02 80 01 2d  be  0xa009fca0
a009f7f0:  80 a4 21 0c  cmp  %l0, 0x10c
a009f7f4:  02 80 01 73  be  0xa009fdc0
a009f7f8:  80 a4 21 0b  cmp  %l0, 0x10b
a009f7fc:  02 80 01 67  be  0xa009fd98
a009f800:  80 a4 21 16  cmp  %l0, 0x116
a009f804:  02 80 01 9b  be  0xa009fe70
a009f808:  80 a4 21 0f  cmp  %l0, 0x10f
a009f80c:  02 80 01 7e  be  0xa009fe04
a009f810:  80 a4 21 0a  cmp  %l0, 0x10a
a009f814:  02 bf ff b7  be  0xa009f6f0
a009f818:  80 a4 20 e5  cmp  %l0, 0xe5
a009f81c:  08 80 01 52  bleu  0xa009fd64
a009f820:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009f824:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009f828:  67 ff b7 5b  call  0x4008d594
a009f82c:  d0 14 20 3c  lduh  [ %l0 + 0x3c ], %o0	! 0xa802d03c
a009f830:  83 2a 20 10  sll  %o0, 0x10, %g1
a009f834:  91 30 60 10  srl  %g1, 0x10, %o0
a009f838:  80 a2 23 e8  cmp  %o0, 0x3e8
a009f83c:  08 80 02 3a  bleu  0xa00a0124
a009f840:  01 00 00 00  nop
a009f844:  40 02 9f b8  call  0xa0147724
a009f848:  01 00 00 00  nop
a009f84c:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a009f850:  f4 12 a3 f2  lduh  [ %o2 + 0x3f2 ], %i2	! 0xa802aff2
a009f854:  80 a6 a0 00  cmp  %i2, 0
a009f858:  02 80 00 07  be  0xa009f874
a009f85c:  d0 34 20 3c  sth  %o0, [ %l0 + 0x3c ]
a009f860:  b2 06 bf ff  add  %i2, -1, %i1
a009f864:  97 2e 60 10  sll  %i1, 0x10, %o3
a009f868:  80 a2 e0 00  cmp  %o3, 0
a009f86c:  12 80 02 2e  bne  0xa00a0124
a009f870:  f2 32 a3 f2  sth  %i1, [ %o2 + 0x3f2 ]
a009f874:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1
a009f878:  80 a0 61 06  cmp  %g1, 0x106
a009f87c:  02 80 01 8c  be  0xa009feac
a009f880:  80 a0 60 e1  cmp  %g1, 0xe1
a009f884:  02 80 01 8a  be  0xa009feac
a009f888:  80 a0 60 e6  cmp  %g1, 0xe6
a009f88c:  02 80 01 88  be  0xa009feac
a009f890:  80 a0 60 41  cmp  %g1, 0x41
a009f894:  02 80 01 86  be  0xa009feac
a009f898:  80 a0 60 81  cmp  %g1, 0x81
a009f89c:  02 80 01 84  be  0xa009feac
a009f8a0:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a009f8a4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a009f8a8:  92 12 a2 90  or  %o2, 0x290, %o1	! 0xa802d290
a009f8ac:  d4 0a 61 a0  ldub  [ %o1 + 0x1a0 ], %o2
a009f8b0:  96 0a a0 ff  and  %o2, 0xff, %o3
a009f8b4:  e0 0a 23 ea  ldub  [ %o0 + 0x3ea ], %l0
a009f8b8:  80 a2 c0 10  cmp  %o3, %l0
a009f8bc:  02 80 00 0e  be  0xa009f8f4
a009f8c0:  80 a2 e0 00  cmp  %o3, 0
a009f8c4:  02 80 00 0d  be  0xa009f8f8
a009f8c8:  a0 16 23 f4  or  %i0, 0x3f4, %l0
a009f8cc:  b4 02 c0 09  add  %o3, %o1, %i2
a009f8d0:  da 16 23 f4  lduh  [ %i0 + 0x3f4 ], %o5
a009f8d4:  d8 0e a1 9b  ldub  [ %i2 + 0x19b ], %o4
a009f8d8:  c2 0e a1 97  ldub  [ %i2 + 0x197 ], %g1
a009f8dc:  33 00 00 10  sethi  %hi(0x4000), %i1
a009f8e0:  9e 13 40 19  or  %o5, %i1, %o7
a009f8e4:  d8 2a 61 a2  stb  %o4, [ %o1 + 0x1a2 ]
a009f8e8:  c2 2a 61 a1  stb  %g1, [ %o1 + 0x1a1 ]
a009f8ec:  d4 2a 23 ea  stb  %o2, [ %o0 + 0x3ea ]
a009f8f0:  de 36 23 f4  sth  %o7, [ %i0 + 0x3f4 ]
a009f8f4:  a0 16 23 f4  or  %i0, 0x3f4, %l0
a009f8f8:  da 14 20 04  lduh  [ %l0 + 4 ], %o5
a009f8fc:  35 3f ff e0  sethi  %hi(0xffff8000), %i2
a009f900:  92 0b 40 1a  and  %o5, %i2, %o1
a009f904:  b1 2a 60 10  sll  %o1, 0x10, %i0
a009f908:  80 a6 20 00  cmp  %i0, 0
a009f90c:  02 80 00 07  be  0xa009f928
a009f910:  96 2b 40 1a  andn  %o5, %i2, %o3
a009f914:  90 12 e4 00  or  %o3, 0x400, %o0
a009f918:  d0 34 20 04  sth  %o0, [ %l0 + 4 ]
a009f91c:  90 10 20 04  mov  4, %o0
a009f920:  7f ff 83 e3  call  0xa00808ac
a009f924:  92 10 20 00  clr  %o1
a009f928:  40 00 ee 21  call  0xa00db1ac
a009f92c:  01 00 00 00  nop
a009f930:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a009f934:  f2 0b 20 8e  ldub  [ %o4 + 0x8e ], %i1	! 0xa802b08e
a009f938:  9a 16 60 02  or  %i1, 2, %o5
a009f93c:  40 00 d4 17  call  0xa00d4998
a009f940:  da 2b 20 8e  stb  %o5, [ %o4 + 0x8e ]
a009f944:  da 14 20 04  lduh  [ %l0 + 4 ], %o5
a009f948:  82 0e 80 0d  and  %i2, %o5, %g1
a009f94c:  9f 28 60 10  sll  %g1, 0x10, %o7
a009f950:  80 a3 e0 00  cmp  %o7, 0
a009f954:  02 80 00 06  be  0xa009f96c
a009f958:  b4 13 64 00  or  %o5, 0x400, %i2
a009f95c:  f4 34 20 04  sth  %i2, [ %l0 + 4 ]
a009f960:  90 10 20 04  mov  4, %o0
a009f964:  7f ff 83 d2  call  0xa00808ac
a009f968:  92 10 20 00  clr  %o1
a009f96c:  40 00 55 c5  call  0xa00b5080
a009f970:  c0 24 63 ec  clr  [ %l1 + 0x3ec ]
a009f974:  7f ff 90 ab  call  0xa0083c20
a009f978:  01 00 00 00  nop
a009f97c:  80 8a 20 ff  btst  0xff, %o0
a009f980:  02 80 01 e9  be  0xa00a0124
a009f984:  a0 10 21 0c  mov  0x10c, %l0
a009f988:  e0 24 63 ec  st  %l0, [ %l1 + 0x3ec ]
a009f98c:  40 00 63 92  call  0xa00b87d4
a009f990:  81 e8 00 00  restore
a009f994:  40 02 9f 64  call  0xa0147724
a009f998:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a009f99c:  d0 34 60 3c  sth  %o0, [ %l1 + 0x3c ]	! 0xa802d03c
a009f9a0:  40 00 d3 84  call  0xa00d47b0
a009f9a4:  81 e8 00 00  restore
a009f9a8:  67 ff b6 fb  call  0x4008d594
a009f9ac:  d0 14 20 36  lduh  [ %l0 + 0x36 ], %o0
a009f9b0:  95 2a 20 10  sll  %o0, 0x10, %o2
a009f9b4:  99 32 a0 10  srl  %o2, 0x10, %o4
a009f9b8:  80 a3 23 e8  cmp  %o4, 0x3e8
a009f9bc:  18 80 00 7f  bgu  0xa009fbb8
a009f9c0:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a009f9c4:  9e 12 e2 90  or  %o3, 0x290, %o7	! 0xa802d290
a009f9c8:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a009f9cc:  d8 03 e1 a0  ld  [ %o7 + 0x1a0 ], %o4
a009f9d0:  96 12 a3 00  or  %o2, 0x300, %o3
a009f9d4:  80 8b 00 0b  btst  %o4, %o3
a009f9d8:  12 bf fe c8  bne  0xa009f4f8
a009f9dc:  33 00 00 10  sethi  %hi(0x4000), %i1
a009f9e0:  f4 16 23 f4  lduh  [ %i0 + 0x3f4 ], %i2
a009f9e4:  a0 2e 80 19  andn  %i2, %i1, %l0
a009f9e8:  10 bf fe c4  b  0xa009f4f8
a009f9ec:  e0 36 23 f4  sth  %l0, [ %i0 + 0x3f4 ]
a009f9f0:  7f ff 8c 97  call  0xa0082c4c
a009f9f4:  01 00 00 00  nop
a009f9f8:  80 8a 20 ff  btst  0xff, %o0
a009f9fc:  12 bf fe b1  bne  0xa009f4c0
a009fa00:  e0 04 63 ec  ld  [ %l1 + 0x3ec ], %l0
a009fa04:  80 a0 00 10  cmp  %g0, %l0
a009fa08:  96 60 3f ff  subx  %g0, -1, %o3
a009fa0c:  9e 1c 21 0d  xor  %l0, 0x10d, %o7
a009fa10:  80 a0 00 0f  cmp  %g0, %o7
a009fa14:  94 60 3f ff  subx  %g0, -1, %o2
a009fa18:  80 92 c0 0a  orcc  %o3, %o2, %g0
a009fa1c:  12 80 00 55  bne  0xa009fb70
a009fa20:  b4 16 23 f4  or  %i0, 0x3f4, %i2
a009fa24:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1
a009fa28:  80 a0 61 13  cmp  %g1, 0x113
a009fa2c:  12 bf fe a4  bne  0xa009f4bc
a009fa30:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a009fa34:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a009fa38:  67 ff b6 d7  call  0x4008d594
a009fa3c:  d0 16 63 e8  lduh  [ %i1 + 0x3e8 ], %o0	! 0xa802afe8
a009fa40:  9f 2a 20 10  sll  %o0, 0x10, %o7
a009fa44:  17 00 00 10  sethi  %hi(0x4000), %o3
a009fa48:  95 33 e0 10  srl  %o7, 0x10, %o2
a009fa4c:  92 12 e2 68  or  %o3, 0x268, %o1
a009fa50:  80 a2 80 09  cmp  %o2, %o1
a009fa54:  28 bf fe 9b  bleu,a   0xa009f4c0
a009fa58:  e0 04 63 ec  ld  [ %l1 + 0x3ec ], %l0
a009fa5c:  98 16 23 f4  or  %i0, 0x3f4, %o4
a009fa60:  da 13 20 04  lduh  [ %o4 + 4 ], %o5
a009fa64:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a009fa68:  90 0b 40 01  and  %o5, %g1, %o0
a009fa6c:  b5 2a 20 10  sll  %o0, 0x10, %i2
a009fa70:  80 a6 a0 00  cmp  %i2, 0
a009fa74:  12 80 00 df  bne  0xa009fdf0
a009fa78:  92 13 64 00  or  %o5, 0x400, %o1
a009fa7c:  40 00 55 81  call  0xa00b5080
a009fa80:  c0 24 23 ec  clr  [ %l0 + 0x3ec ]
a009fa84:  98 10 21 14  mov  0x114, %o4
a009fa88:  10 bf fe 8d  b  0xa009f4bc
a009fa8c:  d8 24 23 ec  st  %o4, [ %l0 + 0x3ec ]
a009fa90:  80 8b e1 00  btst  0x100, %o7
a009fa94:  02 bf fe 95  be  0xa009f4e8
a009fa98:  d2 16 23 f4  lduh  [ %i0 + 0x3f4 ], %o1
a009fa9c:  40 02 90 f5  call  0xa0143e70
a009faa0:  90 10 20 00  clr  %o0
a009faa4:  80 8a 20 ff  btst  0xff, %o0
a009faa8:  12 bf fe 90  bne  0xa009f4e8
a009faac:  d2 16 23 f4  lduh  [ %i0 + 0x3f4 ], %o1
a009fab0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009fab4:  98 14 22 90  or  %l0, 0x290, %o4	! 0xa802d290
a009fab8:  f2 0b 21 90  ldub  [ %o4 + 0x190 ], %i1
a009fabc:  80 a6 60 00  cmp  %i1, 0
a009fac0:  12 80 00 11  bne  0xa009fb04
a009fac4:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1
a009fac8:  d0 03 20 a8  ld  [ %o4 + 0xa8 ], %o0
a009facc:  35 00 00 04  sethi  %hi(0x1000), %i2
a009fad0:  80 8a 00 1a  btst  %o0, %i2
a009fad4:  12 80 00 0d  bne  0xa009fb08
a009fad8:  80 a0 60 00  cmp  %g1, 0
a009fadc:  c2 0b 21 a0  ldub  [ %o4 + 0x1a0 ], %g1
a009fae0:  80 a0 60 00  cmp  %g1, 0
a009fae4:  12 80 00 08  bne  0xa009fb04
a009fae8:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1
a009faec:  da 03 20 ac  ld  [ %o4 + 0xac ], %o5
a009faf0:  13 00 10 00  sethi  %hi(0x400000), %o1
a009faf4:  80 8b 40 09  btst  %o5, %o1
a009faf8:  02 bf fe 7c  be  0xa009f4e8
a009fafc:  d2 16 23 f4  lduh  [ %i0 + 0x3f4 ], %o1
a009fb00:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1
a009fb04:  80 a0 60 00  cmp  %g1, 0
a009fb08:  02 80 00 50  be  0xa009fc48
a009fb0c:  80 a0 61 06  cmp  %g1, 0x106
a009fb10:  02 80 00 85  be  0xa009fd24
a009fb14:  80 a0 61 08  cmp  %g1, 0x108
a009fb18:  12 bf fe 74  bne  0xa009f4e8
a009fb1c:  d2 16 23 f4  lduh  [ %i0 + 0x3f4 ], %o1
a009fb20:  82 14 22 90  or  %l0, 0x290, %g1
a009fb24:  d0 08 61 7b  ldub  [ %g1 + 0x17b ], %o0
a009fb28:  80 a2 20 02  cmp  %o0, 2
a009fb2c:  12 bf fe 70  bne  0xa009f4ec
a009fb30:  1b 00 00 10  sethi  %hi(0x4000), %o5
a009fb34:  40 00 69 94  call  0xa00ba184
a009fb38:  90 10 20 00  clr  %o0
a009fb3c:  10 bf fe 6b  b  0xa009f4e8
a009fb40:  d2 16 23 f4  lduh  [ %i0 + 0x3f4 ], %o1
a009fb44:  67 ff b6 94  call  0x4008d594
a009fb48:  d0 14 20 3a  lduh  [ %l0 + 0x3a ], %o0
a009fb4c:  95 2a 20 10  sll  %o0, 0x10, %o2
a009fb50:  9b 32 a0 10  srl  %o2, 0x10, %o5
a009fb54:  80 a3 60 64  cmp  %o5, 0x64
a009fb58:  08 bf fe 5d  bleu  0xa009f4cc
a009fb5c:  01 00 00 00  nop
a009fb60:  40 02 9e f1  call  0xa0147724
a009fb64:  01 00 00 00  nop
a009fb68:  10 bf fe 59  b  0xa009f4cc
a009fb6c:  d0 34 20 3a  sth  %o0, [ %l0 + 0x3a ]
a009fb70:  f2 16 a0 04  lduh  [ %i2 + 4 ], %i1
a009fb74:  80 8e 62 00  btst  0x200, %i1
a009fb78:  02 bf ff ac  be  0xa009fa28
a009fb7c:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1
a009fb80:  7f ff b5 d8  call  0xa008d2e0
a009fb84:  01 00 00 00  nop
a009fb88:  7f ff ac 66  call  0xa008ad20
a009fb8c:  01 00 00 00  nop
a009fb90:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a009fb94:  d0 0b 22 84  ldub  [ %o4 + 0x284 ], %o0	! 0xa802d284
a009fb98:  80 a2 20 3f  cmp  %o0, 0x3f
a009fb9c:  02 80 00 6f  be  0xa009fd58
a009fba0:  01 00 00 00  nop
a009fba4:  40 02 9e e0  call  0xa0147724
a009fba8:  01 00 00 00  nop
a009fbac:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a009fbb0:  10 bf ff 9d  b  0xa009fa24
a009fbb4:  d0 33 63 e8  sth  %o0, [ %o5 + 0x3e8 ]	! 0xa802afe8
a009fbb8:  40 02 9e db  call  0xa0147724
a009fbbc:  01 00 00 00  nop
a009fbc0:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a009fbc4:  98 12 e2 90  or  %o3, 0x290, %o4	! 0xa802d290
a009fbc8:  de 0b 21 a0  ldub  [ %o4 + 0x1a0 ], %o7
a009fbcc:  80 a3 e0 00  cmp  %o7, 0
a009fbd0:  02 bf ff 7d  be  0xa009f9c4
a009fbd4:  d0 34 20 36  sth  %o0, [ %l0 + 0x36 ]
a009fbd8:  35 00 3f ff  sethi  %hi(0xfffc00), %i2
a009fbdc:  f2 03 21 a0  ld  [ %o4 + 0x1a0 ], %i1
a009fbe0:  a0 16 a3 00  or  %i2, 0x300, %l0
a009fbe4:  80 8e 40 10  btst  %i1, %l0
a009fbe8:  02 bf ff 78  be  0xa009f9c8
a009fbec:  9e 12 e2 90  or  %o3, 0x290, %o7
a009fbf0:  c2 0b 21 a2  ldub  [ %o4 + 0x1a2 ], %g1
a009fbf4:  80 a0 60 00  cmp  %g1, 0
a009fbf8:  22 80 00 25  be,a   0xa009fc8c
a009fbfc:  da 0b 21 a1  ldub  [ %o4 + 0x1a1 ], %o5
a009fc00:  90 00 7f ff  add  %g1, -1, %o0
a009fc04:  10 bf ff 71  b  0xa009f9c8
a009fc08:  d0 2b 21 a2  stb  %o0, [ %o4 + 0x1a2 ]
a009fc0c:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a009fc10:  e0 0b 20 65  ldub  [ %o4 + 0x65 ], %l0	! 0xa802d465
a009fc14:  80 a4 20 00  cmp  %l0, 0
a009fc18:  02 80 01 43  be  0xa00a0124
a009fc1c:  98 16 23 f4  or  %i0, 0x3f4, %o4
a009fc20:  da 13 20 04  lduh  [ %o4 + 4 ], %o5
a009fc24:  23 3f ff e0  sethi  %hi(0xffff8000), %l1
a009fc28:  96 0b 40 11  and  %o5, %l1, %o3
a009fc2c:  83 2a e0 10  sll  %o3, 0x10, %g1
a009fc30:  80 a0 60 00  cmp  %g1, 0
a009fc34:  12 80 00 bb  bne  0xa009ff20
a009fc38:  a0 13 64 00  or  %o5, 0x400, %l0
a009fc3c:  c0 26 63 ec  clr  [ %i1 + 0x3ec ]
a009fc40:  40 00 55 10  call  0xa00b5080
a009fc44:  81 e8 00 00  restore
a009fc48:  67 ff b9 97  call  0x4008e2a4
a009fc4c:  21 00 00 10  sethi  %hi(0x4000), %l0
a009fc50:  67 ff b9 95  call  0x4008e2a4
a009fc54:  01 00 00 00  nop
a009fc58:  94 10 21 06  mov  0x106, %o2	! 0x106
a009fc5c:  d4 24 63 ec  st  %o2, [ %l1 + 0x3ec ]
a009fc60:  40 00 18 82  call  0xa00a5e68
a009fc64:  90 10 20 01  mov  1, %o0
a009fc68:  d8 16 23 f4  lduh  [ %i0 + 0x3f4 ], %o4
a009fc6c:  80 8c 00 0c  btst  %l0, %o4
a009fc70:  02 bf fe 22  be  0xa009f4f8
a009fc74:  01 00 00 00  nop
a009fc78:  40 02 9e ab  call  0xa0147724
a009fc7c:  01 00 00 00  nop
a009fc80:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a009fc84:  10 bf fe 18  b  0xa009f4e4
a009fc88:  d0 32 e0 36  sth  %o0, [ %o3 + 0x36 ]	! 0xa802d036
a009fc8c:  92 03 7f ff  add  %o5, -1, %o1
a009fc90:  82 10 20 3b  mov  0x3b, %g1
a009fc94:  d2 2b 21 a1  stb  %o1, [ %o4 + 0x1a1 ]
a009fc98:  10 bf ff 4b  b  0xa009f9c4
a009fc9c:  c2 2b 21 a2  stb  %g1, [ %o4 + 0x1a2 ]
a009fca0:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a009fca4:  d4 0e a0 65  ldub  [ %i2 + 0x65 ], %o2	! 0xa802d465
a009fca8:  80 a2 a0 00  cmp  %o2, 0
a009fcac:  02 80 01 1e  be  0xa00a0124
a009fcb0:  98 16 23 f4  or  %i0, 0x3f4, %o4
a009fcb4:  10 bf ff dc  b  0xa009fc24
a009fcb8:  da 13 20 04  lduh  [ %o4 + 4 ], %o5
a009fcbc:  40 02 97 8f  call  0xa0145af8
a009fcc0:  90 10 20 0d  mov  0xd, %o0
a009fcc4:  93 2a 20 10  sll  %o0, 0x10, %o1
a009fcc8:  91 32 60 10  srl  %o1, 0x10, %o0
a009fccc:  9f 2a 20 04  sll  %o0, 4, %o7
a009fcd0:  94 23 c0 08  sub  %o7, %o0, %o2
a009fcd4:  a1 2a a0 02  sll  %o2, 2, %l0
a009fcd8:  40 02 97 88  call  0xa0145af8
a009fcdc:  90 10 20 0b  mov  0xb, %o0
a009fce0:  99 2a 20 10  sll  %o0, 0x10, %o4
a009fce4:  b5 33 20 10  srl  %o4, 0x10, %i2
a009fce8:  17 19 99 99  sethi  %hi(0x66666400), %o3
a009fcec:  92 04 00 1a  add  %l0, %i2, %o1
a009fcf0:  9a 12 e2 67  or  %o3, 0x267, %o5
a009fcf4:  80 5a 40 0d  smul  %o1, %o5, %g0
a009fcf8:  83 40 00 00  rd  %y, %g1
a009fcfc:  9f 38 60 03  sra  %g1, 3, %o7
a009fd00:  91 3a 60 1f  sra  %o1, 0x1f, %o0
a009fd04:  94 23 c0 08  sub  %o7, %o0, %o2
a009fd08:  10 bf fe 4f  b  0xa009f644
a009fd0c:  d4 36 60 10  sth  %o2, [ %i1 + 0x10 ]
a009fd10:  40 00 eb 5b  call  0xa00daa7c
a009fd14:  b2 16 23 f4  or  %i0, 0x3f4, %i1
a009fd18:  82 10 20 01  mov  1, %g1
a009fd1c:  10 bf fe 2c  b  0xa009f5cc
a009fd20:  c2 2c 23 f0  stb  %g1, [ %l0 + 0x3f0 ]
a009fd24:  40 00 18 51  call  0xa00a5e68
a009fd28:  90 10 20 00  clr  %o0
a009fd2c:  b2 14 22 90  or  %l0, 0x290, %i1
a009fd30:  de 0e 61 7b  ldub  [ %i1 + 0x17b ], %o7
a009fd34:  80 a3 e0 02  cmp  %o7, 2
a009fd38:  02 80 00 80  be  0xa009ff38
a009fd3c:  01 00 00 00  nop
a009fd40:  40 02 9e 79  call  0xa0147724
a009fd44:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a009fd48:  40 00 d2 9a  call  0xa00d47b0
a009fd4c:  d0 36 a0 3c  sth  %o0, [ %i2 + 0x3c ]	! 0xa802d03c
a009fd50:  10 bf fd e6  b  0xa009f4e8
a009fd54:  d2 16 23 f4  lduh  [ %i0 + 0x3f4 ], %o1
a009fd58:  7f ff ad 59  call  0xa008b2bc
a009fd5c:  01 00 00 00  nop
a009fd60:  30 bf ff 91  b,a   0xa009fba4
a009fd64:  67 ff b6 0c  call  0x4008d594
a009fd68:  d0 14 20 3a  lduh  [ %l0 + 0x3a ], %o0
a009fd6c:  99 2a 20 10  sll  %o0, 0x10, %o4
a009fd70:  93 33 20 10  srl  %o4, 0x10, %o1
a009fd74:  80 a2 60 64  cmp  %o1, 0x64
a009fd78:  28 bf fe ac  bleu,a   0xa009f828
a009fd7c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009fd80:  40 02 9e 69  call  0xa0147724
a009fd84:  01 00 00 00  nop
a009fd88:  40 00 4e 87  call  0xa00b37a4
a009fd8c:  d0 34 20 3a  sth  %o0, [ %l0 + 0x3a ]
a009fd90:  10 bf fe a6  b  0xa009f828
a009fd94:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009fd98:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a009fd9c:  67 ff b5 fe  call  0x4008d594
a009fda0:  d0 12 60 3c  lduh  [ %o1 + 0x3c ], %o0	! 0xa802d03c
a009fda4:  91 2a 20 10  sll  %o0, 0x10, %o0
a009fda8:  9f 32 20 10  srl  %o0, 0x10, %o7
a009fdac:  80 a3 eb b8  cmp  %o7, 0xbb8
a009fdb0:  08 80 00 dd  bleu  0xa00a0124
a009fdb4:  98 16 23 f4  or  %i0, 0x3f4, %o4
a009fdb8:  10 bf ff 9b  b  0xa009fc24
a009fdbc:  da 13 20 04  lduh  [ %o4 + 4 ], %o5
a009fdc0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009fdc4:  67 ff b5 f4  call  0x4008d594
a009fdc8:  d0 14 20 3c  lduh  [ %l0 + 0x3c ], %o0	! 0xa802d03c
a009fdcc:  b3 2a 20 10  sll  %o0, 0x10, %i1
a009fdd0:  b1 36 60 10  srl  %i1, 0x10, %i0
a009fdd4:  80 a6 20 64  cmp  %i0, 0x64
a009fdd8:  08 80 00 d3  bleu  0xa00a0124
a009fddc:  01 00 00 00  nop
a009fde0:  67 ff b5 ea  call  0x4008d588
a009fde4:  01 00 00 00  nop
a009fde8:  10 80 00 cf  b  0xa00a0124
a009fdec:  d0 34 20 3c  sth  %o0, [ %l0 + 0x3c ]
a009fdf0:  d2 33 20 04  sth  %o1, [ %o4 + 4 ]
a009fdf4:  90 10 20 04  mov  4, %o0
a009fdf8:  7f ff 82 ad  call  0xa00808ac
a009fdfc:  92 10 20 00  clr  %o1
a009fe00:  30 bf ff 1f  b,a   0xa009fa7c
a009fe04:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a009fe08:  67 ff b5 e3  call  0x4008d594
a009fe0c:  d0 16 a0 3c  lduh  [ %i2 + 0x3c ], %o0	! 0xa802d03c
a009fe10:  91 2a 20 10  sll  %o0, 0x10, %o0
a009fe14:  9f 32 20 10  srl  %o0, 0x10, %o7
a009fe18:  80 a3 eb b8  cmp  %o7, 0xbb8
a009fe1c:  08 80 00 c2  bleu  0xa00a0124
a009fe20:  98 16 23 f4  or  %i0, 0x3f4, %o4
a009fe24:  da 13 20 04  lduh  [ %o4 + 4 ], %o5
a009fe28:  17 3f ff e0  sethi  %hi(0xffff8000), %o3
a009fe2c:  82 0b 40 0b  and  %o5, %o3, %g1
a009fe30:  93 28 60 10  sll  %g1, 0x10, %o1
a009fe34:  80 a2 60 00  cmp  %o1, 0
a009fe38:  12 80 00 4f  bne  0xa009ff74
a009fe3c:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a009fe40:  40 00 54 90  call  0xa00b5080
a009fe44:  c0 26 63 ec  clr  [ %i1 + 0x3ec ]
a009fe48:  c2 14 63 f4  lduh  [ %l1 + 0x3f4 ], %g1
a009fe4c:  80 88 62 00  btst  0x200, %g1
a009fe50:  02 80 00 b5  be  0xa00a0124
a009fe54:  98 08 7d ff  and  %g1, -513, %o4
a009fe58:  67 ff b5 cc  call  0x4008d588
a009fe5c:  d8 34 63 f4  sth  %o4, [ %l1 + 0x3f4 ]
a009fe60:  d0 36 a0 3c  sth  %o0, [ %i2 + 0x3c ]
a009fe64:  e0 26 63 ec  st  %l0, [ %i1 + 0x3ec ]
a009fe68:  40 00 62 00  call  0xa00b8668
a009fe6c:  81 e8 00 00  restore
a009fe70:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a009fe74:  67 ff b5 c8  call  0x4008d594
a009fe78:  d0 13 60 3c  lduh  [ %o5 + 0x3c ], %o0	! 0xa802d03c
a009fe7c:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a009fe80:  9a 16 62 90  or  %i1, 0x290, %o5	! 0xa802d290
a009fe84:  b1 2a 20 10  sll  %o0, 0x10, %i0
a009fe88:  f4 0b 60 0c  ldub  [ %o5 + 0xc ], %i2
a009fe8c:  95 36 20 10  srl  %i0, 0x10, %o2
a009fe90:  98 5e a3 e8  smul  %i2, 0x3e8, %o4
a009fe94:  80 a2 80 0c  cmp  %o2, %o4
a009fe98:  04 80 00 a3  ble  0xa00a0124
a009fe9c:  01 00 00 00  nop
a009fea0:  c0 2b 61 aa  clrb  [ %o5 + 0x1aa ]
a009fea4:  7f ff ed be  call  0xa009b59c
a009fea8:  81 e8 00 00  restore
a009feac:  f0 12 a3 f2  lduh  [ %o2 + 0x3f2 ], %i0
a009feb0:  80 a6 20 00  cmp  %i0, 0
a009feb4:  12 80 00 9c  bne  0xa00a0124
a009feb8:  d2 04 63 ec  ld  [ %l1 + 0x3ec ], %o1
a009febc:  80 a2 60 e1  cmp  %o1, 0xe1
a009fec0:  02 80 00 89  be  0xa00a00e4
a009fec4:  da 12 a3 f2  lduh  [ %o2 + 0x3f2 ], %o5
a009fec8:  80 a3 60 00  cmp  %o5, 0
a009fecc:  12 80 00 96  bne  0xa00a0124
a009fed0:  f2 04 63 ec  ld  [ %l1 + 0x3ec ], %i1
a009fed4:  80 a6 60 e6  cmp  %i1, 0xe6
a009fed8:  02 80 00 72  be  0xa00a00a0
a009fedc:  de 12 a3 f2  lduh  [ %o2 + 0x3f2 ], %o7
a009fee0:  80 a3 e0 00  cmp  %o7, 0
a009fee4:  12 80 00 90  bne  0xa00a0124
a009fee8:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1
a009feec:  80 a0 60 41  cmp  %g1, 0x41
a009fef0:  02 80 00 5d  be  0xa00a0064
a009fef4:  e0 12 a3 f2  lduh  [ %o2 + 0x3f2 ], %l0
a009fef8:  80 a4 20 00  cmp  %l0, 0
a009fefc:  12 80 00 8a  bne  0xa00a0124
a009ff00:  f0 04 63 ec  ld  [ %l1 + 0x3ec ], %i0
a009ff04:  80 a6 20 81  cmp  %i0, 0x81
a009ff08:  12 80 00 87  bne  0xa00a0124
a009ff0c:  01 00 00 00  nop
a009ff10:  7f ff e0 83  call  0xa009811c
a009ff14:  01 00 00 00  nop
a009ff18:  40 00 d2 26  call  0xa00d47b0
a009ff1c:  81 e8 00 00  restore
a009ff20:  e0 33 20 04  sth  %l0, [ %o4 + 4 ]
a009ff24:  90 10 20 04  mov  4, %o0
a009ff28:  7f ff 82 61  call  0xa00808ac
a009ff2c:  92 10 20 00  clr  %o1
a009ff30:  10 bf ff 44  b  0xa009fc40
a009ff34:  c0 26 63 ec  clr  [ %i1 + 0x3ec ]
a009ff38:  40 00 68 93  call  0xa00ba184
a009ff3c:  90 10 20 00  clr  %o0
a009ff40:  30 bf ff 80  b,a   0xa009fd40
a009ff44:  40 00 45 c4  call  0xa00b1654
a009ff48:  90 10 00 10  mov  %l0, %o0
a009ff4c:  d0 2e 63 f1  stb  %o0, [ %i1 + 0x3f1 ]
a009ff50:  90 0a 20 ff  and  %o0, 0xff, %o0
a009ff54:  40 00 45 eb  call  0xa00b1700
a009ff58:  92 10 20 03  mov  3, %o1
a009ff5c:  9e 10 21 0f  mov  0x10f, %o7
a009ff60:  de 24 63 ec  st  %o7, [ %l1 + 0x3ec ]
a009ff64:  67 ff b5 89  call  0x4008d588
a009ff68:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a009ff6c:  10 bf fe 0b  b  0xa009f798
a009ff70:  d0 36 a0 3c  sth  %o0, [ %i2 + 0x3c ]	! 0xa802d03c
a009ff74:  94 13 64 00  or  %o5, 0x400, %o2
a009ff78:  d4 33 20 04  sth  %o2, [ %o4 + 4 ]
a009ff7c:  90 10 20 04  mov  4, %o0
a009ff80:  7f ff 82 4b  call  0xa00808ac
a009ff84:  92 10 20 00  clr  %o1
a009ff88:  30 bf ff ae  b,a   0xa009fe40
a009ff8c:  98 16 23 f4  or  %i0, 0x3f4, %o4
a009ff90:  d4 13 20 12  lduh  [ %o4 + 0x12 ], %o2
a009ff94:  80 a2 a0 05  cmp  %o2, 5
a009ff98:  02 80 00 2d  be  0xa00a004c
a009ff9c:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a009ffa0:  de 13 20 10  lduh  [ %o4 + 0x10 ], %o7
a009ffa4:  80 a3 e0 04  cmp  %o7, 4
a009ffa8:  02 80 00 1f  be  0xa00a0024
a009ffac:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a009ffb0:  b2 16 23 f4  or  %i0, 0x3f4, %i1
a009ffb4:  da 16 60 0e  lduh  [ %i1 + 0xe ], %o5
a009ffb8:  23 3f ff e0  sethi  %hi(0xffff8000), %l1
a009ffbc:  94 2b 40 11  andn  %o5, %l1, %o2
a009ffc0:  d4 36 60 0e  sth  %o2, [ %i1 + 0xe ]
a009ffc4:  17 2a 00 97  sethi  %hi(0xa8025c00), %o3
a009ffc8:  de 0a e0 55  ldub  [ %o3 + 0x55 ], %o7	! 0xa8025c55
a009ffcc:  80 a3 e0 02  cmp  %o7, 2
a009ffd0:  22 80 00 02  be,a   0xa009ffd8
a009ffd4:  c0 2a e0 55  clrb  [ %o3 + 0x55 ]
a009ffd8:  98 16 23 f4  or  %i0, 0x3f4, %o4
a009ffdc:  f0 0b 20 3f  ldub  [ %o4 + 0x3f ], %i0
a009ffe0:  80 a6 20 00  cmp  %i0, 0
a009ffe4:  02 80 00 0c  be  0xa00a0014
a009ffe8:  d2 0a e0 55  ldub  [ %o3 + 0x55 ], %o1
a009ffec:  80 a2 60 00  cmp  %o1, 0
a009fff0:  12 80 00 09  bne  0xa00a0014
a009fff4:  35 3f ff e0  sethi  %hi(0xffff8000), %i2
a009fff8:  c2 13 20 0e  lduh  [ %o4 + 0xe ], %g1
a009fffc:  90 08 40 1a  and  %g1, %i2, %o0
a00a0000:  99 2a 20 10  sll  %o0, 0x10, %o4
a00a0004:  80 a3 20 00  cmp  %o4, 0
a00a0008:  12 80 00 03  bne  0xa00a0014
a00a000c:  b2 10 20 01  mov  1, %i1
a00a0010:  f2 2a e0 55  stb  %i1, [ %o3 + 0x55 ]
a00a0014:  40 00 4b 3c  call  0xa00b2d04
a00a0018:  01 00 00 00  nop
a00a001c:  10 bf fd d0  b  0xa009f75c
a00a0020:  96 14 22 90  or  %l0, 0x290, %o3
a00a0024:  d8 0a 60 56  ldub  [ %o1 + 0x56 ], %o4
a00a0028:  80 a3 20 00  cmp  %o4, 0
a00a002c:  12 bf ff e2  bne  0xa009ffb4
a00a0030:  b2 16 23 f4  or  %i0, 0x3f4, %i1
a00a0034:  90 16 23 f4  or  %i0, 0x3f4, %o0
a00a0038:  d6 12 20 0e  lduh  [ %o0 + 0xe ], %o3
a00a003c:  35 3f ff e0  sethi  %hi(0xffff8000), %i2
a00a0040:  82 12 c0 1a  or  %o3, %i2, %g1
a00a0044:  10 bf ff e0  b  0xa009ffc4
a00a0048:  c2 32 20 0e  sth  %g1, [ %o0 + 0xe ]
a00a004c:  e2 0b 60 56  ldub  [ %o5 + 0x56 ], %l1
a00a0050:  80 a4 60 01  cmp  %l1, 1
a00a0054:  32 bf ff d4  bne,a   0xa009ffa4
a00a0058:  de 13 20 10  lduh  [ %o4 + 0x10 ], %o7
a00a005c:  10 bf ff f7  b  0xa00a0038
a00a0060:  90 16 23 f4  or  %i0, 0x3f4, %o0
a00a0064:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00a0068:  b2 16 a2 90  or  %i2, 0x290, %i1	! 0xa802d290
a00a006c:  da 0e 60 0c  ldub  [ %i1 + 0xc ], %o5
a00a0070:  da 32 a3 f2  sth  %o5, [ %o2 + 0x3f2 ]
a00a0074:  98 10 20 02  mov  2, %o4
a00a0078:  94 10 21 08  mov  0x108, %o2
a00a007c:  d8 2e 61 a3  stb  %o4, [ %i1 + 0x1a3 ]
a00a0080:  40 00 54 00  call  0xa00b5080
a00a0084:  d4 24 63 ec  st  %o2, [ %l1 + 0x3ec ]
a00a0088:  67 ff b8 87  call  0x4008e2a4
a00a008c:  b0 10 20 02  mov  2, %i0
a00a0090:  67 ff b8 85  call  0x4008e2a4
a00a0094:  b2 10 20 01  mov  1, %i1
a00a0098:  40 00 1a c0  call  0xa00a6b98
a00a009c:  95 e8 20 00  restore  %g0, 0, %o2
a00a00a0:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00a00a4:  a0 10 21 08  mov  0x108, %l0
a00a00a8:  b4 12 e2 90  or  %o3, 0x290, %i2
a00a00ac:  e0 24 63 ec  st  %l0, [ %l1 + 0x3ec ]
a00a00b0:  d2 0e a1 3f  ldub  [ %i2 + 0x13f ], %o1
a00a00b4:  d0 0e a0 0c  ldub  [ %i2 + 0xc ], %o0
a00a00b8:  31 2a 00 97  sethi  %hi(0xa8025c00), %i0
a00a00bc:  a2 10 20 01  mov  1, %l1
a00a00c0:  d2 2e 20 55  stb  %o1, [ %i0 + 0x55 ]
a00a00c4:  d0 32 a3 f2  sth  %o0, [ %o2 + 0x3f2 ]
a00a00c8:  40 00 53 ee  call  0xa00b5080
a00a00cc:  e2 2e a1 a3  stb  %l1, [ %i2 + 0x1a3 ]
a00a00d0:  67 ff b8 75  call  0x4008e2a4
a00a00d4:  b0 10 20 01  mov  1, %i0
a00a00d8:  67 ff b8 73  call  0x4008e2a4
a00a00dc:  b2 10 20 01  mov  1, %i1
a00a00e0:  30 bf ff ee  b,a   0xa00a0098
a00a00e4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00a00e8:  90 13 22 90  or  %o4, 0x290, %o0	! 0xa802d290
a00a00ec:  c2 0a 20 0c  ldub  [ %o0 + 0xc ], %g1
a00a00f0:  c2 32 a3 f2  sth  %g1, [ %o2 + 0x3f2 ]
a00a00f4:  de 0a 21 3e  ldub  [ %o0 + 0x13e ], %o7
a00a00f8:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a00a00fc:  96 10 21 08  mov  0x108, %o3
a00a0100:  de 2a a0 55  stb  %o7, [ %o2 + 0x55 ]
a00a0104:  d6 24 63 ec  st  %o3, [ %l1 + 0x3ec ]
a00a0108:  40 00 53 de  call  0xa00b5080
a00a010c:  c0 2a 21 a3  clrb  [ %o0 + 0x1a3 ]
a00a0110:  67 ff b8 65  call  0x4008e2a4
a00a0114:  b0 10 20 00  clr  %i0
a00a0118:  67 ff b8 63  call  0x4008e2a4
a00a011c:  b2 10 20 01  mov  1, %i1
a00a0120:  30 bf ff de  b,a   0xa00a0098
a00a0124:  81 c7 e0 08  ret
a00a0128:  81 e8 00 00  restore
