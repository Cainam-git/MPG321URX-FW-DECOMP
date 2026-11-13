# leon2s INIT_handler 0xa00a17c4-0xa00a1a80 (700 bytes)
a00a17c4:  9d e3 bf 98  save  %sp, -104, %sp
a00a17c8:  a6 0e 20 ff  and  %i0, 0xff, %l3
a00a17cc:  80 a4 e0 00  cmp  %l3, 0
a00a17d0:  02 80 00 05  be  0xa00a17e4
a00a17d4:  ae 10 20 02  mov  2, %l7
a00a17d8:  80 a4 e0 01  cmp  %l3, 1
a00a17dc:  12 80 00 a7  bne  0xa00a1a78
a00a17e0:  ae 10 20 03  mov  3, %l7
a00a17e4:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a17e8:  aa 10 63 00  or  %g1, 0x300, %l5	! 0xa807db00
a00a17ec:  a8 5c e0 34  smul  %l3, 0x34, %l4
a00a17f0:  a4 05 00 15  add  %l4, %l5, %l2
a00a17f4:  d2 04 a0 04  ld  [ %l2 + 4 ], %o1
a00a17f8:  92 02 60 3c  add  %o1, 0x3c, %o1
a00a17fc:  40 00 16 ec  call  0xa00a73ac
a00a1800:  90 10 20 17  mov  0x17, %o0
a00a1804:  d2 04 a0 04  ld  [ %l2 + 4 ], %o1
a00a1808:  92 02 60 3c  add  %o1, 0x3c, %o1
a00a180c:  40 00 16 e8  call  0xa00a73ac
a00a1810:  90 10 20 16  mov  0x16, %o0
a00a1814:  d2 04 a0 04  ld  [ %l2 + 4 ], %o1
a00a1818:  92 02 60 3c  add  %o1, 0x3c, %o1
a00a181c:  40 00 16 e4  call  0xa00a73ac
a00a1820:  90 10 20 15  mov  0x15, %o0
a00a1824:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a1828:  82 10 63 e0  or  %g1, 0x3e0, %g1	! 0xa807d7e0
a00a182c:  9a 5c e1 90  smul  %l3, 0x190, %o5
a00a1830:  9a 03 40 01  add  %o5, %g1, %o5
a00a1834:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a1838:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a00a183c:  ac 10 20 01  mov  1, %l6
a00a1840:  ec 2b 61 83  stb  %l6, [ %o5 + 0x183 ]
a00a1844:  80 88 60 01  btst  1, %g1
a00a1848:  c0 2b 60 02  clrb  [ %o5 + 2 ]
a00a184c:  02 80 00 09  be  0xa00a1870
a00a1850:  ec 2b 60 ba  stb  %l6, [ %o5 + 0xba ]
a00a1854:  92 06 20 41  add  %i0, 0x41, %o1
a00a1858:  93 2a 60 18  sll  %o1, 0x18, %o1
a00a185c:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a1860:  90 12 20 38  or  %o0, 0x38, %o0	! 0xa006b838
a00a1864:  93 3a 60 18  sra  %o1, 0x18, %o1
a00a1868:  7f ff 45 f7  call  0xa0073044
a00a186c:  94 10 20 01  mov  1, %o2
a00a1870:  d2 05 40 14  ld  [ %l5 + %l4 ], %o1
a00a1874:  23 00 3f ff  sethi  %hi(0xfffc00), %l1
a00a1878:  c2 02 60 c0  ld  [ %o1 + 0xc0 ], %g1
a00a187c:  a2 14 63 ff  or  %l1, 0x3ff, %l1
a00a1880:  1b 14 00 00  sethi  %hi(0x50000000), %o5
a00a1884:  82 08 40 11  and  %g1, %l1, %g1
a00a1888:  82 10 40 0d  or  %g1, %o5, %g1
a00a188c:  c2 22 60 c0  st  %g1, [ %o1 + 0xc0 ]
a00a1890:  c2 02 60 c4  ld  [ %o1 + 0xc4 ], %g1
a00a1894:  82 08 7f 00  and  %g1, -256, %g1
a00a1898:  c2 22 60 c4  st  %g1, [ %o1 + 0xc4 ]
a00a189c:  21 3f ff c0  sethi  %hi(0xffff0000), %l0
a00a18a0:  c2 02 60 c4  ld  [ %o1 + 0xc4 ], %g1
a00a18a4:  a0 14 20 ff  or  %l0, 0xff, %l0
a00a18a8:  82 08 40 10  and  %g1, %l0, %g1
a00a18ac:  82 10 61 00  or  %g1, 0x100, %g1
a00a18b0:  c2 22 60 c4  st  %g1, [ %o1 + 0xc4 ]
a00a18b4:  da 02 60 c4  ld  [ %o1 + 0xc4 ], %o5
a00a18b8:  03 00 3f c0  sethi  %hi(0xff0000), %g1
a00a18bc:  82 2b 40 01  andn  %o5, %g1, %g1
a00a18c0:  c2 22 60 c4  st  %g1, [ %o1 + 0xc4 ]
a00a18c4:  92 02 60 84  add  %o1, 0x84, %o1
a00a18c8:  40 00 16 b9  call  0xa00a73ac
a00a18cc:  90 10 20 14  mov  0x14, %o0
a00a18d0:  d2 05 40 14  ld  [ %l5 + %l4 ], %o1
a00a18d4:  92 02 60 d4  add  %o1, 0xd4, %o1
a00a18d8:  40 00 16 bf  call  0xa00a73d4
a00a18dc:  90 04 e0 14  add  %l3, 0x14, %o0
a00a18e0:  d2 04 a0 04  ld  [ %l2 + 4 ], %o1
a00a18e4:  92 02 60 24  add  %o1, 0x24, %o1
a00a18e8:  40 00 16 b1  call  0xa00a73ac
a00a18ec:  90 10 20 1b  mov  0x1b, %o0
a00a18f0:  d2 04 a0 04  ld  [ %l2 + 4 ], %o1
a00a18f4:  92 02 60 24  add  %o1, 0x24, %o1
a00a18f8:  40 00 16 ad  call  0xa00a73ac
a00a18fc:  90 10 20 1c  mov  0x1c, %o0
a00a1900:  d2 04 a0 04  ld  [ %l2 + 4 ], %o1
a00a1904:  92 02 60 24  add  %o1, 0x24, %o1
a00a1908:  40 00 16 a9  call  0xa00a73ac
a00a190c:  90 10 20 1d  mov  0x1d, %o0
a00a1910:  d2 04 a0 04  ld  [ %l2 + 4 ], %o1
a00a1914:  92 02 60 24  add  %o1, 0x24, %o1
a00a1918:  40 00 16 a5  call  0xa00a73ac
a00a191c:  90 10 20 1e  mov  0x1e, %o0
a00a1920:  d2 04 a0 04  ld  [ %l2 + 4 ], %o1
a00a1924:  92 02 60 24  add  %o1, 0x24, %o1
a00a1928:  40 00 16 a1  call  0xa00a73ac
a00a192c:  90 10 20 1f  mov  0x1f, %o0
a00a1930:  d2 04 a0 04  ld  [ %l2 + 4 ], %o1
a00a1934:  92 02 60 28  add  %o1, 0x28, %o1
a00a1938:  40 00 16 9d  call  0xa00a73ac
a00a193c:  90 10 20 0d  mov  0xd, %o0
a00a1940:  d2 04 a0 04  ld  [ %l2 + 4 ], %o1
a00a1944:  92 02 60 28  add  %o1, 0x28, %o1
a00a1948:  40 00 16 99  call  0xa00a73ac
a00a194c:  90 10 20 08  mov  8, %o0
a00a1950:  d2 04 a0 04  ld  [ %l2 + 4 ], %o1
a00a1954:  92 02 60 28  add  %o1, 0x28, %o1
a00a1958:  40 00 16 95  call  0xa00a73ac
a00a195c:  90 10 20 09  mov  9, %o0
a00a1960:  d2 04 a0 04  ld  [ %l2 + 4 ], %o1
a00a1964:  92 02 60 28  add  %o1, 0x28, %o1
a00a1968:  40 00 16 91  call  0xa00a73ac
a00a196c:  90 10 20 0a  mov  0xa, %o0
a00a1970:  d2 04 a0 04  ld  [ %l2 + 4 ], %o1
a00a1974:  92 02 60 28  add  %o1, 0x28, %o1
a00a1978:  40 00 16 97  call  0xa00a73d4
a00a197c:  90 10 20 0b  mov  0xb, %o0
a00a1980:  da 04 a0 04  ld  [ %l2 + 4 ], %o5
a00a1984:  c2 03 60 34  ld  [ %o5 + 0x34 ], %g1
a00a1988:  82 08 40 10  and  %g1, %l0, %g1
a00a198c:  82 10 66 00  or  %g1, 0x600, %g1
a00a1990:  d2 05 40 14  ld  [ %l5 + %l4 ], %o1
a00a1994:  c2 23 60 34  st  %g1, [ %o5 + 0x34 ]
a00a1998:  92 02 60 40  add  %o1, 0x40, %o1
a00a199c:  40 00 16 8e  call  0xa00a73d4
a00a19a0:  90 10 20 0f  mov  0xf, %o0
a00a19a4:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a19a8:  82 10 62 80  or  %g1, 0x280, %g1	! 0xa807d680
a00a19ac:  9a 5c e0 b0  smul  %l3, 0xb0, %o5
a00a19b0:  9a 03 40 01  add  %o5, %g1, %o5
a00a19b4:  ec 2b 60 3a  stb  %l6, [ %o5 + 0x3a ]
a00a19b8:  c0 2b 60 3c  clrb  [ %o5 + 0x3c ]
a00a19bc:  c0 23 60 30  clr  [ %o5 + 0x30 ]
a00a19c0:  c0 2b 60 3b  clrb  [ %o5 + 0x3b ]
a00a19c4:  7f ff e7 0c  call  0xa009b5f4
a00a19c8:  90 10 00 13  mov  %l3, %o0
a00a19cc:  d2 04 a0 18  ld  [ %l2 + 0x18 ], %o1
a00a19d0:  92 02 60 90  add  %o1, 0x90, %o1
a00a19d4:  40 00 16 80  call  0xa00a73d4
a00a19d8:  90 10 20 11  mov  0x11, %o0
a00a19dc:  d2 04 a0 18  ld  [ %l2 + 0x18 ], %o1
a00a19e0:  92 02 60 08  add  %o1, 8, %o1
a00a19e4:  40 00 16 72  call  0xa00a73ac
a00a19e8:  90 10 20 08  mov  8, %o0
a00a19ec:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a00a19f0:  96 12 e2 60  or  %o3, 0x260, %o3	! 0x2e60
a00a19f4:  94 0d e0 03  and  %l7, 3, %o2
a00a19f8:  90 10 20 01  mov  1, %o0
a00a19fc:  40 00 16 8a  call  0xa00a7424
a00a1a00:  92 10 20 1e  mov  0x1e, %o1
a00a1a04:  d2 04 a0 0c  ld  [ %l2 + 0xc ], %o1
a00a1a08:  92 02 60 7c  add  %o1, 0x7c, %o1
a00a1a0c:  40 00 16 68  call  0xa00a73ac
a00a1a10:  90 10 20 0c  mov  0xc, %o0
a00a1a14:  d2 05 40 14  ld  [ %l5 + %l4 ], %o1
a00a1a18:  92 02 60 04  add  %o1, 4, %o1
a00a1a1c:  40 00 16 64  call  0xa00a73ac
a00a1a20:  90 10 20 15  mov  0x15, %o0
a00a1a24:  d8 04 a0 20  ld  [ %l2 + 0x20 ], %o4
a00a1a28:  c2 03 20 80  ld  [ %o4 + 0x80 ], %g1
a00a1a2c:  1b 01 00 00  sethi  %hi(0x4000000), %o5
a00a1a30:  82 08 60 ff  and  %g1, 0xff, %g1
a00a1a34:  82 10 40 0d  or  %g1, %o5, %g1
a00a1a38:  c2 23 20 80  st  %g1, [ %o4 + 0x80 ]
a00a1a3c:  c2 03 20 80  ld  [ %o4 + 0x80 ], %g1
a00a1a40:  82 10 60 07  or  %g1, 7, %g1
a00a1a44:  c2 23 20 80  st  %g1, [ %o4 + 0x80 ]
a00a1a48:  90 10 00 13  mov  %l3, %o0
a00a1a4c:  92 10 20 12  mov  0x12, %o1
a00a1a50:  40 00 05 48  call  0xa00a2f70
a00a1a54:  94 10 20 01  mov  1, %o2
a00a1a58:  40 00 1b 0f  call  0xa00a8694
a00a1a5c:  90 10 00 13  mov  %l3, %o0
a00a1a60:  d8 04 a0 08  ld  [ %l2 + 8 ], %o4
a00a1a64:  c2 03 20 9c  ld  [ %o4 + 0x9c ], %g1
a00a1a68:  82 08 40 11  and  %g1, %l1, %g1
a00a1a6c:  1b 00 80 00  sethi  %hi(0x2000000), %o5
a00a1a70:  82 10 40 0d  or  %g1, %o5, %g1
a00a1a74:  c2 23 20 9c  st  %g1, [ %o4 + 0x9c ]
a00a1a78:  81 c7 e0 08  ret
a00a1a7c:  81 e8 00 00  restore
