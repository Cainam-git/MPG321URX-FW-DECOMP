# leon2m FUN_a014f6f4 0xa014f6f4-0xa014f888 (404 bytes)
a014f6f4:  9d e3 bf 88  save  %sp, -120, %sp
a014f6f8:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a014f6fc:  15 20 00 00  sethi  %hi(0x80000000), %o2
a014f700:  92 2b 40 0a  andn  %o5, %o2, %o1
a014f704:  11 10 00 00  sethi  %hi(0x40000000), %o0
a014f708:  82 2a 40 08  andn  %o1, %o0, %g1
a014f70c:  1f 08 00 00  sethi  %hi(0x20000000), %o7
a014f710:  98 28 40 0f  andn  %g1, %o7, %o4
a014f714:  17 04 00 00  sethi  %hi(0x10000000), %o3
a014f718:  94 2b 00 0b  andn  %o4, %o3, %o2
a014f71c:  13 02 00 00  sethi  %hi(0x8000000), %o1
a014f720:  9a 2a 80 09  andn  %o2, %o1, %o5
a014f724:  11 01 00 00  sethi  %hi(0x4000000), %o0
a014f728:  82 2b 40 08  andn  %o5, %o0, %g1
a014f72c:  1f 00 80 00  sethi  %hi(0x2000000), %o7
a014f730:  96 28 40 0f  andn  %g1, %o7, %o3
a014f734:  19 00 40 00  sethi  %hi(0x1000000), %o4
a014f738:  94 12 c0 0c  or  %o3, %o4, %o2
a014f73c:  d4 27 bf f0  st  %o2, [ %fp + -16 ]
a014f740:  92 10 20 01  mov  1, %o1
a014f744:  d2 2f bf f2  stb  %o1, [ %fp + -14 ]
a014f748:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a014f74c:  11 00 30 00  sethi  %hi(0xc00000), %o0
a014f750:  82 2b 40 08  andn  %o5, %o0, %g1
a014f754:  80 a0 60 00  cmp  %g1, 0
a014f758:  06 80 00 13  bl  0xa014f7a4
a014f75c:  c2 27 bf f0  st  %g1, [ %fp + -16 ]
a014f760:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a014f764:  97 33 60 18  srl  %o5, 0x18, %o3
a014f768:  80 8a e0 40  btst  0x40, %o3
a014f76c:  12 80 00 23  bne  0xa014f7f8
a014f770:  99 33 60 18  srl  %o5, 0x18, %o4
a014f774:  80 8b 20 20  btst  0x20, %o4
a014f778:  12 80 00 27  bne  0xa014f814
a014f77c:  9f 33 60 18  srl  %o5, 0x18, %o7
a014f780:  80 8b e0 04  btst  4, %o7
a014f784:  12 80 00 2c  bne  0xa014f834
a014f788:  90 10 20 0e  mov  0xe, %o0
a014f78c:  83 33 60 18  srl  %o5, 0x18, %g1
a014f790:  80 88 60 02  btst  2, %g1
a014f794:  22 80 00 35  be,a   0xa014f868
a014f798:  d0 0f bf f2  ldub  [ %fp + -14 ], %o0
a014f79c:  10 80 00 2f  b  0xa014f858
a014f7a0:  90 10 20 0e  mov  0xe, %o0
a014f7a4:  90 10 20 0c  mov  0xc, %o0
a014f7a8:  92 10 20 01  mov  1, %o1
a014f7ac:  7f fe bc 35  call  0xa00fe880
a014f7b0:  94 10 20 0b  mov  0xb, %o2
a014f7b4:  90 10 20 0c  mov  0xc, %o0
a014f7b8:  92 10 20 02  mov  2, %o1
a014f7bc:  7f fe bc 31  call  0xa00fe880
a014f7c0:  94 10 20 0b  mov  0xb, %o2
a014f7c4:  90 10 20 0c  mov  0xc, %o0
a014f7c8:  92 10 20 04  mov  4, %o1
a014f7cc:  7f fe bc 2d  call  0xa00fe880
a014f7d0:  94 10 20 0b  mov  0xb, %o2
a014f7d4:  90 10 20 0c  mov  0xc, %o0
a014f7d8:  92 10 20 08  mov  8, %o1
a014f7dc:  7f fe bc 29  call  0xa00fe880
a014f7e0:  94 10 20 0b  mov  0xb, %o2
a014f7e4:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a014f7e8:  97 33 60 18  srl  %o5, 0x18, %o3
a014f7ec:  80 8a e0 40  btst  0x40, %o3
a014f7f0:  02 bf ff e1  be  0xa014f774
a014f7f4:  99 33 60 18  srl  %o5, 0x18, %o4
a014f7f8:  7f ff ff 8a  call  0xa014f620
a014f7fc:  90 10 20 00  clr  %o0
a014f800:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a014f804:  99 33 60 18  srl  %o5, 0x18, %o4
a014f808:  80 8b 20 20  btst  0x20, %o4
a014f80c:  02 bf ff dd  be  0xa014f780
a014f810:  9f 33 60 18  srl  %o5, 0x18, %o7
a014f814:  7f ff ff 83  call  0xa014f620
a014f818:  90 10 20 01  mov  1, %o0
a014f81c:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a014f820:  9f 33 60 18  srl  %o5, 0x18, %o7
a014f824:  80 8b e0 04  btst  4, %o7
a014f828:  02 bf ff da  be  0xa014f790
a014f82c:  83 33 60 18  srl  %o5, 0x18, %g1
a014f830:  90 10 20 0e  mov  0xe, %o0
a014f834:  92 10 20 04  mov  4, %o1
a014f838:  7f fe bc 12  call  0xa00fe880
a014f83c:  94 10 20 0e  mov  0xe, %o2
a014f840:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a014f844:  83 33 60 18  srl  %o5, 0x18, %g1
a014f848:  80 88 60 02  btst  2, %g1
a014f84c:  22 80 00 07  be,a   0xa014f868
a014f850:  d0 0f bf f2  ldub  [ %fp + -14 ], %o0
a014f854:  90 10 20 0e  mov  0xe, %o0
a014f858:  92 10 20 08  mov  8, %o1
a014f85c:  7f fe bc 09  call  0xa00fe880
a014f860:  94 10 20 0e  mov  0xe, %o2
a014f864:  d0 0f bf f2  ldub  [ %fp + -14 ], %o0
a014f868:  d2 17 bf f0  lduh  [ %fp + -16 ], %o1
a014f86c:  d0 2f bf ea  stb  %o0, [ %fp + -22 ]
a014f870:  d2 37 bf e8  sth  %o1, [ %fp + -24 ]
a014f874:  7f ff a3 3c  call  0xa0138564
a014f878:  90 07 bf e8  add  %fp, -24, %o0
a014f87c:  01 00 00 00  nop
a014f880:  81 c7 e0 08  ret
a014f884:  81 e8 00 00  restore
