# leon2m FUN_a00a177c 0xa00a177c-0xa00a192c (432 bytes)
a00a177c:  9d e3 bf 98  save  %sp, -104, %sp
a00a1780:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a00a1784:  40 00 1f 0e  call  0xa00a93bc
a00a1788:  d0 0e a0 56  ldub  [ %i2 + 0x56 ], %o0	! 0xa8025c56
a00a178c:  c2 0e a0 56  ldub  [ %i2 + 0x56 ], %g1
a00a1790:  82 00 60 01  inc  %g1
a00a1794:  9a 08 60 ff  and  %g1, 0xff, %o5
a00a1798:  80 a3 60 02  cmp  %o5, 2
a00a179c:  08 80 00 22  bleu  0xa00a1824
a00a17a0:  9a 10 00 1a  mov  %i2, %o5
a00a17a4:  c0 2e a0 56  clrb  [ %i2 + 0x56 ]
a00a17a8:  d0 0b 60 56  ldub  [ %o5 + 0x56 ], %o0
a00a17ac:  40 00 1f a9  call  0xa00a9650
a00a17b0:  92 10 20 01  mov  1, %o1
a00a17b4:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a00a17b8:  d0 02 a3 ec  ld  [ %o2 + 0x3ec ], %o0	! 0xa802afec
a00a17bc:  82 02 3f 40  add  %o0, -192, %g1
a00a17c0:  80 a0 60 39  cmp  %g1, 0x39
a00a17c4:  18 80 00 08  bgu  0xa00a17e4
a00a17c8:  96 10 20 00  clr  %o3
a00a17cc:  31 00 00 be  sethi  %hi(0x2f800), %i0
a00a17d0:  93 28 60 02  sll  %g1, 2, %o1
a00a17d4:  9e 16 21 70  or  %i0, 0x170, %o7
a00a17d8:  d8 03 c0 09  ld  [ %o7 + %o1 ], %o4
a00a17dc:  81 c3 00 00  jmp  %o4
a00a17e0:  01 00 00 00  nop
a00a17e4:  9a 10 20 00  clr  %o5	! 0x0
a00a17e8:  d6 0e a0 56  ldub  [ %i2 + 0x56 ], %o3
a00a17ec:  80 a2 c0 0d  cmp  %o3, %o5
a00a17f0:  02 80 00 1c  be  0xa00a1860
a00a17f4:  f4 02 a3 ec  ld  [ %o2 + 0x3ec ], %i2
a00a17f8:  f2 02 a3 ec  ld  [ %o2 + 0x3ec ], %i1
a00a17fc:  82 06 7f 40  add  %i1, -192, %g1
a00a1800:  80 a0 60 39  cmp  %g1, 0x39
a00a1804:  18 80 00 0a  bgu  0xa00a182c
a00a1808:  b2 10 20 00  clr  %i1
a00a180c:  15 00 00 be  sethi  %hi(0x2f800), %o2
a00a1810:  83 28 60 02  sll  %g1, 2, %g1
a00a1814:  b4 12 a0 88  or  %o2, 0x88, %i2
a00a1818:  d6 06 80 01  ld  [ %i2 + %g1 ], %o3
a00a181c:  81 c2 c0 00  jmp  %o3
a00a1820:  01 00 00 00  nop
a00a1824:  10 bf ff e1  b  0xa00a17a8
a00a1828:  c2 2e a0 56  stb  %g1, [ %i2 + 0x56 ]
a00a182c:  b2 10 20 00  clr  %i1
a00a1830:  b0 10 20 01  mov  1, %i0
a00a1834:  b4 10 20 01  mov  1, %i2
a00a1838:  40 00 1a 41  call  0xa00a813c
a00a183c:  81 e8 00 00  restore
a00a1840:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00a1844:  d6 08 60 7c  ldub  [ %g1 + 0x7c ], %o3	! 0xa802d47c
a00a1848:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00a184c:  d6 0e a0 56  ldub  [ %i2 + 0x56 ], %o3
a00a1850:  80 a2 c0 0d  cmp  %o3, %o5
a00a1854:  12 bf ff ea  bne  0xa00a17fc
a00a1858:  f2 02 a3 ec  ld  [ %o2 + 0x3ec ], %i1
a00a185c:  f4 02 a3 ec  ld  [ %o2 + 0x3ec ], %i2
a00a1860:  82 06 bf 40  add  %i2, -192, %g1
a00a1864:  80 a0 60 39  cmp  %g1, 0x39
a00a1868:  18 80 00 08  bgu  0xa00a1888
a00a186c:  b2 10 20 00  clr  %i1
a00a1870:  13 00 00 bd  sethi  %hi(0x2f400), %o1
a00a1874:  91 28 60 02  sll  %g1, 2, %o0
a00a1878:  98 12 63 a0  or  %o1, 0x3a0, %o4
a00a187c:  d4 03 00 08  ld  [ %o4 + %o0 ], %o2
a00a1880:  81 c2 80 00  jmp  %o2
a00a1884:  01 00 00 00  nop
a00a1888:  b2 10 20 00  clr  %i1	! 0x0
a00a188c:  b0 10 20 01  mov  1, %i0
a00a1890:  b4 10 20 00  clr  %i2
a00a1894:  40 00 1a 2a  call  0xa00a813c
a00a1898:  81 e8 00 00  restore
a00a189c:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00a18a0:  f2 0a 60 7c  ldub  [ %o1 + 0x7c ], %i1	! 0xa802d47c
a00a18a4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a18a8:  b0 10 20 01  mov  1, %i0
a00a18ac:  10 bf ff e3  b  0xa00a1838
a00a18b0:  b4 10 20 01  mov  1, %i2
a00a18b4:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00a18b8:  d6 0b 60 7a  ldub  [ %o5 + 0x7a ], %o3	! 0xa802d47a
a00a18bc:  10 bf ff e4  b  0xa00a184c
a00a18c0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00a18c4:  33 2a 00 b5  sethi  %hi(0xa802d400), %i1
a00a18c8:  d6 0e 60 78  ldub  [ %i1 + 0x78 ], %o3	! 0xa802d478
a00a18cc:  10 bf ff e0  b  0xa00a184c
a00a18d0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00a18d4:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a00a18d8:  f2 0b 20 7a  ldub  [ %o4 + 0x7a ], %i1	! 0xa802d47a
a00a18dc:  10 bf ff f3  b  0xa00a18a8
a00a18e0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a18e4:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a00a18e8:  f2 0a 20 78  ldub  [ %o0 + 0x78 ], %i1	! 0xa802d478
a00a18ec:  10 bf ff ef  b  0xa00a18a8
a00a18f0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a18f4:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00a18f8:  f2 0b 60 7c  ldub  [ %o5 + 0x7c ], %i1	! 0xa802d47c
a00a18fc:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a1900:  b0 10 20 01  mov  1, %i0
a00a1904:  10 bf ff e4  b  0xa00a1894
a00a1908:  b4 10 20 00  clr  %i2
a00a190c:  31 2a 00 b5  sethi  %hi(0xa802d400), %i0
a00a1910:  f2 0e 20 7a  ldub  [ %i0 + 0x7a ], %i1	! 0xa802d47a
a00a1914:  10 bf ff fb  b  0xa00a1900
a00a1918:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a191c:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a00a1920:  f2 0b e0 78  ldub  [ %o7 + 0x78 ], %i1	! 0xa802d478
a00a1924:  10 bf ff f7  b  0xa00a1900
a00a1928:  b2 0e 60 ff  and  %i1, 0xff, %i1
