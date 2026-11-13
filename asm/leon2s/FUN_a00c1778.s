# leon2s FUN_a00c1778 0xa00c1778-0xa00c18fc (388 bytes)
a00c1778:  9d e3 bf 98  save  %sp, -104, %sp
a00c177c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c1780:  17 2a 01 f5  sethi  %hi(0xa807d400), %o3
a00c1784:  96 12 e1 c8  or  %o3, 0x1c8, %o3	! 0xa807d5c8
a00c1788:  95 2c 20 04  sll  %l0, 4, %o2
a00c178c:  da 02 c0 0a  ld  [ %o3 + %o2 ], %o5
a00c1790:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00c1794:  82 2b 40 01  andn  %o5, %g1, %g1
a00c1798:  1b 10 00 00  sethi  %hi(0x40000000), %o5
a00c179c:  9a 28 40 0d  andn  %g1, %o5, %o5
a00c17a0:  03 08 00 00  sethi  %hi(0x20000000), %g1
a00c17a4:  82 2b 40 01  andn  %o5, %g1, %g1
a00c17a8:  1b 04 00 00  sethi  %hi(0x10000000), %o5
a00c17ac:  9a 28 40 0d  andn  %g1, %o5, %o5
a00c17b0:  03 02 00 00  sethi  %hi(0x8000000), %g1
a00c17b4:  82 2b 40 01  andn  %o5, %g1, %g1
a00c17b8:  c2 22 c0 0a  st  %g1, [ %o3 + %o2 ]
a00c17bc:  98 02 80 0b  add  %o2, %o3, %o4
a00c17c0:  c0 2b 20 0d  clrb  [ %o4 + 0xd ]
a00c17c4:  c0 2b 20 0c  clrb  [ %o4 + 0xc ]
a00c17c8:  c0 23 20 08  clr  [ %o4 + 8 ]
a00c17cc:  da 02 c0 0a  ld  [ %o3 + %o2 ], %o5
a00c17d0:  03 01 c0 00  sethi  %hi(0x7000000), %g1
a00c17d4:  82 2b 40 01  andn  %o5, %g1, %g1
a00c17d8:  1b 01 40 00  sethi  %hi(0x5000000), %o5
a00c17dc:  82 10 40 0d  or  %g1, %o5, %g1
a00c17e0:  c2 22 c0 0a  st  %g1, [ %o3 + %o2 ]
a00c17e4:  82 10 20 22  mov  0x22, %g1
a00c17e8:  c2 2b 20 05  stb  %g1, [ %o4 + 5 ]
a00c17ec:  c0 2b 20 02  clrb  [ %o4 + 2 ]
a00c17f0:  c0 2b 20 04  clrb  [ %o4 + 4 ]
a00c17f4:  da 02 c0 0a  ld  [ %o3 + %o2 ], %o5
a00c17f8:  03 00 20 00  sethi  %hi(0x800000), %g1
a00c17fc:  82 2b 40 01  andn  %o5, %g1, %g1
a00c1800:  1b 00 10 00  sethi  %hi(0x400000), %o5
a00c1804:  9a 28 40 0d  andn  %g1, %o5, %o5
a00c1808:  03 00 08 00  sethi  %hi(0x200000), %g1
a00c180c:  82 2b 40 01  andn  %o5, %g1, %g1
a00c1810:  1b 00 07 c0  sethi  %hi(0x1f0000), %o5
a00c1814:  9a 28 40 0d  andn  %g1, %o5, %o5
a00c1818:  03 00 00 40  sethi  %hi(0x10000), %g1
a00c181c:  9a 13 40 01  or  %o5, %g1, %o5
a00c1820:  da 22 c0 0a  st  %o5, [ %o3 + %o2 ]
a00c1824:  98 10 3f ff  mov  -1, %o4
a00c1828:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c182c:  d8 28 62 36  stb  %o4, [ %g1 + 0x236 ]	! 0xa807d636
a00c1830:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c1834:  82 10 62 30  or  %g1, 0x230, %g1	! 0xa807d630
a00c1838:  c0 28 40 10  clrb  [ %g1 + %l0 ]
a00c183c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c1840:  82 10 61 c0  or  %g1, 0x1c0, %g1	! 0xa807d5c0
a00c1844:  c0 28 40 10  clrb  [ %g1 + %l0 ]
a00c1848:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c184c:  d8 28 61 c6  stb  %o4, [ %g1 + 0x1c6 ]	! 0xa807d5c6
a00c1850:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c1854:  92 10 00 18  mov  %i0, %o1
a00c1858:  d8 28 62 29  stb  %o4, [ %g1 + 0x229 ]
a00c185c:  b0 06 3f fc  add  %i0, -4, %i0
a00c1860:  80 8e 60 ff  btst  0xff, %i1
a00c1864:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c1868:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c186c:  b4 10 20 80  mov  0x80, %i2
a00c1870:  b6 10 20 01  mov  1, %i3
a00c1874:  b2 10 24 07  mov  0x407, %i1
a00c1878:  02 80 00 1e  be  0xa00c18f0
a00c187c:  d8 28 62 2b  stb  %o4, [ %g1 + 0x22b ]
a00c1880:  82 02 7f fe  add  %o1, -2, %g1
a00c1884:  90 10 00 10  mov  %l0, %o0
a00c1888:  92 10 23 1f  mov  0x31f, %o1
a00c188c:  94 10 20 80  mov  0x80, %o2
a00c1890:  96 10 20 01  mov  1, %o3
a00c1894:  b0 08 60 ff  and  %g1, 0xff, %i0
a00c1898:  b2 10 23 21  mov  0x321, %i1
a00c189c:  80 a4 20 01  cmp  %l0, 1
a00c18a0:  18 80 00 0b  bgu  0xa00c18cc
a00c18a4:  b4 10 20 0e  mov  0xe, %i2
a00c18a8:  40 3b d3 c4  call  0xa0fb67b8
a00c18ac:  b0 10 00 10  mov  %l0, %i0
a00c18b0:  90 10 00 10  mov  %l0, %o0
a00c18b4:  92 10 23 09  mov  0x309, %o1
a00c18b8:  94 10 20 80  mov  0x80, %o2
a00c18bc:  40 3b d3 bf  call  0xa0fb67b8
a00c18c0:  96 10 20 01  mov  1, %o3
a00c18c4:  40 3b d3 bd  call  0xa0fb67b8
a00c18c8:  81 e8 00 00  restore
a00c18cc:  90 10 00 18  mov  %i0, %o0
a00c18d0:  92 10 2c 00  mov  0xc00, %o1
a00c18d4:  94 10 20 01  mov  1, %o2
a00c18d8:  40 3b d4 72  call  0xa0fb6aa0
a00c18dc:  96 10 20 01  mov  1, %o3
a00c18e0:  b2 10 20 09  mov  9, %i1
a00c18e4:  b4 10 20 40  mov  0x40, %i2
a00c18e8:  40 3b d4 6e  call  0xa0fb6aa0
a00c18ec:  97 e8 20 01  restore  %g0, 1, %o3
a00c18f0:  40 3b d4 ea  call  0xa0fb6c98
a00c18f4:  81 e8 00 00  restore
a00c18f8:  01 00 00 00  nop
