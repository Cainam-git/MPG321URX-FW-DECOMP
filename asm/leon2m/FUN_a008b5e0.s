# leon2m FUN_a008b5e0 0xa008b5e0-0xa008b83c (604 bytes)
a008b5e0:  9d e3 bf 80  save  %sp, -128, %sp
a008b5e4:  29 2a 00 ab  sethi  %hi(0xa802ac00), %l4
a008b5e8:  da 0d 23 b9  ldub  [ %l4 + 0x3b9 ], %o5	! 0xa802afb9
a008b5ec:  80 a3 60 03  cmp  %o5, 3
a008b5f0:  18 80 00 7b  bgu  0xa008b7dc
a008b5f4:  94 03 7f fc  add  %o5, -4, %o2
a008b5f8:  90 10 20 04  mov  4, %o0
a008b5fc:  82 22 00 0d  sub  %o0, %o5, %g1
a008b600:  9a 10 20 4e  mov  0x4e, %o5
a008b604:  27 2a 00 ab  sethi  %hi(0xa802ac00), %l3
a008b608:  9b 3b 40 01  sra  %o5, %g1, %o5
a008b60c:  d2 0c e3 b8  ldub  [ %l3 + 0x3b8 ], %o1
a008b610:  91 3b 40 09  sra  %o5, %o1, %o0
a008b614:  1b 14 7a e1  sethi  %hi(0x51eb8400), %o5
a008b618:  83 2a 20 10  sll  %o0, 0x10, %g1
a008b61c:  a1 30 60 10  srl  %g1, 0x10, %l0
a008b620:  a4 13 61 1f  or  %o5, 0x11f, %l2
a008b624:  80 54 00 12  umul  %l0, %l2, %g0
a008b628:  a3 40 00 00  rd  %y, %l1
a008b62c:  97 34 60 05  srl  %l1, 5, %o3
a008b630:  98 5a e0 64  smul  %o3, 0x64, %o4
a008b634:  9e 24 00 0c  sub  %l0, %o4, %o7
a008b638:  de 2f bf f1  stb  %o7, [ %fp + -15 ]
a008b63c:  d6 2f bf f0  stb  %o3, [ %fp + -16 ]
a008b640:  98 10 20 00  clr  %o4
a008b644:  9a 10 20 00  clr  %o5
a008b648:  a0 07 bf f8  add  %fp, -8, %l0
a008b64c:  94 04 00 0d  add  %l0, %o5, %o2
a008b650:  98 03 20 01  inc  %o4
a008b654:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008b658:  80 a3 60 08  cmp  %o5, 8
a008b65c:  08 bf ff fc  bleu  0xa008b64c
a008b660:  c0 2a bf e8  clrb  [ %o2 + -24 ]
a008b664:  d4 0f bf f0  ldub  [ %fp + -16 ], %o2
a008b668:  80 a2 a0 0a  cmp  %o2, 0xa
a008b66c:  18 80 00 62  bgu  0xa008b7f4
a008b670:  1f 00 04 01  sethi  %hi(0x100400), %o7
a008b674:  d6 0f bf f1  ldub  [ %fp + -15 ], %o3
a008b678:  a4 07 bf e0  add  %fp, -32, %l2
a008b67c:  80 a2 e0 0a  cmp  %o3, 0xa
a008b680:  18 80 00 05  bgu  0xa008b694
a008b684:  92 13 e0 b8  or  %o7, 0xb8, %o1
a008b688:  19 00 04 01  sethi  %hi(0x100400), %o4
a008b68c:  a4 07 bf e0  add  %fp, -32, %l2
a008b690:  92 13 20 c8  or  %o4, 0xc8, %o1
a008b694:  90 10 00 12  mov  %l2, %o0
a008b698:  40 03 30 57  call  0xa01577f4
a008b69c:  01 00 00 00  nop
a008b6a0:  82 10 20 00  clr  %g1	! 0x0
a008b6a4:  9a 10 20 00  clr  %o5
a008b6a8:  96 10 20 24  mov  0x24, %o3
a008b6ac:  10 80 00 0b  b  0xa008b6d8
a008b6b0:  94 10 20 25  mov  0x25, %o2
a008b6b4:  02 80 00 4e  be  0xa008b7ec
a008b6b8:  80 a3 60 00  cmp  %o5, 0
a008b6bc:  02 80 00 12  be  0xa008b704
a008b6c0:  a2 00 7f ff  add  %g1, -1, %l1
a008b6c4:  82 00 60 01  inc  %g1
a008b6c8:  9a 08 60 ff  and  %g1, 0xff, %o5
a008b6cc:  80 a3 60 08  cmp  %o5, 8
a008b6d0:  18 80 00 0d  bgu  0xa008b704
a008b6d4:  a2 00 7f ff  add  %g1, -1, %l1
a008b6d8:  98 04 00 0d  add  %l0, %o5, %o4
a008b6dc:  da 0b 3f e8  ldub  [ %o4 + -24 ], %o5
a008b6e0:  80 a3 60 53  cmp  %o5, 0x53
a008b6e4:  12 bf ff f4  bne  0xa008b6b4
a008b6e8:  80 a3 60 50  cmp  %o5, 0x50
a008b6ec:  82 00 60 01  inc  %g1
a008b6f0:  9a 08 60 ff  and  %g1, 0xff, %o5
a008b6f4:  80 a3 60 08  cmp  %o5, 8
a008b6f8:  08 bf ff f8  bleu  0xa008b6d8
a008b6fc:  d6 2b 3f e8  stb  %o3, [ %o4 + -24 ]
a008b700:  a2 00 7f ff  add  %g1, -1, %l1
a008b704:  e2 2f bf e0  stb  %l1, [ %fp + -32 ]
a008b708:  90 10 20 00  clr  %o0
a008b70c:  40 02 ed 18  call  0xa0146b6c
a008b710:  92 10 20 00  clr  %o1
a008b714:  90 10 20 df  mov  0xdf, %o0
a008b718:  40 02 ed 0e  call  0xa0146b50
a008b71c:  92 10 20 00  clr  %o1
a008b720:  23 00 04 00  sethi  %hi(0x100000), %l1
a008b724:  92 14 62 42  or  %l1, 0x242, %o1	! 0x100242
a008b728:  d4 0a 60 31  ldub  [ %o1 + 0x31 ], %o2
a008b72c:  90 10 20 00  clr  %o0
a008b730:  96 10 20 09  mov  9, %o3
a008b734:  98 10 00 12  mov  %l2, %o4
a008b738:  9a 10 20 00  clr  %o5
a008b73c:  40 00 5e 9a  call  0xa00a31a4
a008b740:  92 10 20 10  mov  0x10, %o1
a008b744:  da 0c e3 b8  ldub  [ %l3 + 0x3b8 ], %o5
a008b748:  d0 0d 23 b9  ldub  [ %l4 + 0x3b9 ], %o0
a008b74c:  a9 2b 60 05  sll  %o5, 5, %l4
a008b750:  82 02 00 08  add  %o0, %o0, %g1
a008b754:  a6 15 00 01  or  %l4, %g1, %l3
a008b758:  9a 14 e0 01  or  %l3, 1, %o5
a008b75c:  96 10 20 00  clr  %o3
a008b760:  98 10 20 00  clr  %o4
a008b764:  94 04 00 0c  add  %l0, %o4, %o2
a008b768:  96 02 e0 01  inc  %o3
a008b76c:  98 0a e0 ff  and  %o3, 0xff, %o4
a008b770:  80 a3 20 08  cmp  %o4, 8
a008b774:  08 bf ff fc  bleu  0xa008b764
a008b778:  c0 2a bf e8  clrb  [ %o2 + -24 ]
a008b77c:  9f 2b 60 10  sll  %o5, 0x10, %o7
a008b780:  95 33 e0 10  srl  %o7, 0x10, %o2
a008b784:  17 00 04 01  sethi  %hi(0x100400), %o3
a008b788:  80 a2 a0 0f  cmp  %o2, 0xf
a008b78c:  08 80 00 04  bleu  0xa008b79c
a008b790:  92 12 e0 d8  or  %o3, 0xd8, %o1
a008b794:  19 00 04 01  sethi  %hi(0x100400), %o4
a008b798:  92 13 20 e8  or  %o4, 0xe8, %o1	! 0x1004e8
a008b79c:  40 03 30 16  call  0xa01577f4
a008b7a0:  90 10 00 12  mov  %l2, %o0
a008b7a4:  96 10 20 00  clr  %o3
a008b7a8:  82 10 20 00  clr  %g1
a008b7ac:  a8 04 00 01  add  %l0, %g1, %l4
a008b7b0:  e6 0d 3f e8  ldub  [ %l4 + -24 ], %l3
a008b7b4:  80 a4 e0 00  cmp  %l3, 0
a008b7b8:  22 80 00 15  be,a   0xa008b80c
a008b7bc:  a0 02 ff ff  add  %o3, -1, %l0
a008b7c0:  96 02 e0 01  inc  %o3
a008b7c4:  82 0a e0 ff  and  %o3, 0xff, %g1
a008b7c8:  80 a0 60 08  cmp  %g1, 8
a008b7cc:  08 bf ff f9  bleu  0xa008b7b0
a008b7d0:  a8 04 00 01  add  %l0, %g1, %l4
a008b7d4:  10 80 00 0e  b  0xa008b80c
a008b7d8:  a0 02 ff ff  add  %o3, -1, %l0
a008b7dc:  92 10 20 4e  mov  0x4e, %o1
a008b7e0:  27 2a 00 ab  sethi  %hi(0xa802ac00), %l3
a008b7e4:  10 bf ff 8a  b  0xa008b60c
a008b7e8:  9b 2a 40 0a  sll  %o1, %o2, %o5
a008b7ec:  10 bf ff b6  b  0xa008b6c4
a008b7f0:  d4 2b 3f e8  stb  %o2, [ %o4 + -24 ]
a008b7f4:  17 00 04 01  sethi  %hi(0x100400), %o3
a008b7f8:  a4 07 bf e0  add  %fp, -32, %l2
a008b7fc:  92 12 e0 f8  or  %o3, 0xf8, %o1
a008b800:  90 10 00 12  mov  %l2, %o0
a008b804:  10 bf ff a5  b  0xa008b698
a008b808:  d6 0f bf f1  ldub  [ %fp + -15 ], %o3
a008b80c:  82 14 62 42  or  %l1, 0x242, %g1
a008b810:  e0 2f bf e0  stb  %l0, [ %fp + -32 ]
a008b814:  d4 08 60 2e  ldub  [ %g1 + 0x2e ], %o2
a008b818:  96 0c 20 ff  and  %l0, 0xff, %o3
a008b81c:  98 10 00 12  mov  %l2, %o4
a008b820:  90 10 20 00  clr  %o0
a008b824:  92 10 20 0f  mov  0xf, %o1
a008b828:  40 00 5e 5f  call  0xa00a31a4
a008b82c:  9a 10 20 00  clr  %o5
a008b830:  01 00 00 00  nop
a008b834:  81 c7 e0 08  ret
a008b838:  81 e8 00 00  restore
