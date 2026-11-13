# leon2m FUN_a00f176c 0xa00f176c-0xa00f18d4 (360 bytes)
a00f176c:  9d e3 bf 98  save  %sp, -104, %sp
a00f1770:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f1774:  9a 10 00 1b  mov  %i3, %o5
a00f1778:  80 a6 20 02  cmp  %i0, 2
a00f177c:  98 10 00 19  mov  %i1, %o4
a00f1780:  02 80 00 1e  be  0xa00f17f8
a00f1784:  9e 10 00 1a  mov  %i2, %o7
a00f1788:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00f178c:  83 2e 60 10  sll  %i1, 0x10, %g1
a00f1790:  b6 13 e2 7a  or  %o7, 0x27a, %i3
a00f1794:  ba 06 00 18  add  %i0, %i0, %i5
a00f1798:  f2 16 c0 1d  lduh  [ %i3 + %i5 ], %i1
a00f179c:  b9 30 60 10  srl  %g1, 0x10, %i4
a00f17a0:  82 06 40 1c  add  %i1, %i4, %g1
a00f17a4:  b7 28 60 02  sll  %g1, 2, %i3
a00f17a8:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00f17ac:  b2 0b 60 ff  and  %o5, 0xff, %i1
a00f17b0:  b8 16 c0 1d  or  %i3, %i5, %i4
a00f17b4:  c2 07 00 00  ld  [ %i4 ], %g1
a00f17b8:  80 a6 60 01  cmp  %i1, 1
a00f17bc:  02 80 00 03  be  0xa00f17c8
a00f17c0:  b2 10 40 1a  or  %g1, %i2, %i1
a00f17c4:  b2 28 40 1a  andn  %g1, %i2, %i1
a00f17c8:  ba 13 e2 7a  or  %o7, 0x27a, %i5
a00f17cc:  b8 06 00 18  add  %i0, %i0, %i4
a00f17d0:  b5 2b 20 10  sll  %o4, 0x10, %i2
a00f17d4:  f0 17 40 1c  lduh  [ %i5 + %i4 ], %i0
a00f17d8:  b7 36 a0 10  srl  %i2, 0x10, %i3
a00f17dc:  82 06 00 1b  add  %i0, %i3, %g1
a00f17e0:  b9 28 60 02  sll  %g1, 2, %i4
a00f17e4:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00f17e8:  b0 17 00 1d  or  %i4, %i5, %i0
a00f17ec:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00f17f0:  f4 26 00 00  st  %i2, [ %i0 ]
a00f17f4:  30 80 00 36  b,a   0xa00f18cc
a00f17f8:  b5 2e 60 10  sll  %i1, 0x10, %i2
a00f17fc:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00f1800:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00f1804:  80 a7 20 01  cmp  %i4, 1
a00f1808:  b8 16 62 7a  or  %i1, 0x27a, %i4
a00f180c:  b3 36 a0 10  srl  %i2, 0x10, %i1
a00f1810:  b4 10 20 00  clr  %i2
a00f1814:  b6 10 20 00  clr  %i3
a00f1818:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00f181c:  02 80 00 11  be  0xa00f1860
a00f1820:  b0 38 00 0f  xnor  %g0, %o7, %i0
a00f1824:  82 06 c0 1b  add  %i3, %i3, %g1
a00f1828:  fa 17 00 01  lduh  [ %i4 + %g1 ], %i5
a00f182c:  b6 07 40 19  add  %i5, %i1, %i3
a00f1830:  bb 2e e0 02  sll  %i3, 2, %i5
a00f1834:  ba 17 40 0d  or  %i5, %o5, %i5
a00f1838:  c2 07 40 00  ld  [ %i5 ], %g1
a00f183c:  b6 08 40 18  and  %g1, %i0, %i3
a00f1840:  82 0e e0 ff  and  %i3, 0xff, %g1
a00f1844:  b4 06 a0 01  inc  %i2
a00f1848:  b6 0e a0 ff  and  %i2, 0xff, %i3
a00f184c:  c2 27 40 00  st  %g1, [ %i5 ]
a00f1850:  80 a6 e0 01  cmp  %i3, 1
a00f1854:  08 bf ff f5  bleu  0xa00f1828
a00f1858:  82 06 c0 1b  add  %i3, %i3, %g1
a00f185c:  30 80 00 1c  b,a   0xa00f18cc
a00f1860:  82 06 c0 1b  add  %i3, %i3, %g1
a00f1864:  f6 17 00 01  lduh  [ %i4 + %g1 ], %i3
a00f1868:  b0 06 c0 19  add  %i3, %i1, %i0
a00f186c:  bb 2e 20 02  sll  %i0, 2, %i5
a00f1870:  b0 17 40 0d  or  %i5, %o5, %i0
a00f1874:  c2 06 00 00  ld  [ %i0 ], %g1
a00f1878:  b6 10 40 0f  or  %g1, %o7, %i3
a00f187c:  82 0e e0 ff  and  %i3, 0xff, %g1
a00f1880:  b4 06 a0 01  inc  %i2
a00f1884:  b6 0e a0 ff  and  %i2, 0xff, %i3
a00f1888:  c2 26 00 00  st  %g1, [ %i0 ]
a00f188c:  80 a6 e0 01  cmp  %i3, 1
a00f1890:  18 80 00 0f  bgu  0xa00f18cc
a00f1894:  82 06 c0 1b  add  %i3, %i3, %g1
a00f1898:  f6 17 00 01  lduh  [ %i4 + %g1 ], %i3
a00f189c:  b0 06 c0 19  add  %i3, %i1, %i0
a00f18a0:  bb 2e 20 02  sll  %i0, 2, %i5
a00f18a4:  b0 17 40 0d  or  %i5, %o5, %i0
a00f18a8:  c2 06 00 00  ld  [ %i0 ], %g1
a00f18ac:  b6 10 40 0f  or  %g1, %o7, %i3
a00f18b0:  82 0e e0 ff  and  %i3, 0xff, %g1
a00f18b4:  b4 06 a0 01  inc  %i2
a00f18b8:  b6 0e a0 ff  and  %i2, 0xff, %i3
a00f18bc:  c2 26 00 00  st  %g1, [ %i0 ]
a00f18c0:  80 a6 e0 01  cmp  %i3, 1
a00f18c4:  08 bf ff e8  bleu  0xa00f1864
a00f18c8:  82 06 c0 1b  add  %i3, %i3, %g1
a00f18cc:  81 c7 e0 08  ret
a00f18d0:  81 e8 00 00  restore
