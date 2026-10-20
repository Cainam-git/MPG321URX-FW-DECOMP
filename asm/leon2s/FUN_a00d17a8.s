# leon2s FUN_a00d17a8 0xa00d17a8-0xa00d1b04 (860 bytes)
a00d17a8:  9d e3 bf 98  save  %sp, -104, %sp
a00d17ac:  aa 10 20 00  clr  %l5
a00d17b0:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00d17b4:  80 a4 20 00  cmp  %l0, 0
a00d17b8:  12 80 00 09  bne  0xa00d17dc
a00d17bc:  80 a4 20 01  cmp  %l0, 1
a00d17c0:  40 3a ba fe  call  0xa0f803b8
a00d17c4:  90 10 20 00  clr  %o0
a00d17c8:  80 8a 20 ff  btst  0xff, %o0
a00d17cc:  22 80 00 c8  be,a   0xa00d1aec
a00d17d0:  aa 05 60 01  inc  %l5
a00d17d4:  10 80 00 0b  b  0xa00d1800
a00d17d8:  80 a4 20 02  cmp  %l0, 2
a00d17dc:  12 80 00 09  bne  0xa00d1800
a00d17e0:  80 a4 20 02  cmp  %l0, 2
a00d17e4:  40 3a ba f5  call  0xa0f803b8
a00d17e8:  90 10 20 01  mov  1, %o0
a00d17ec:  80 8a 20 ff  btst  0xff, %o0
a00d17f0:  22 80 00 bf  be,a   0xa00d1aec
a00d17f4:  aa 05 60 01  inc  %l5
a00d17f8:  10 80 00 0a  b  0xa00d1820
a00d17fc:  80 a4 20 02  cmp  %l0, 2
a00d1800:  12 80 00 51  bne  0xa00d1944
a00d1804:  a2 0d 60 ff  and  %l5, 0xff, %l1
a00d1808:  40 3a ba ec  call  0xa0f803b8
a00d180c:  90 10 20 02  mov  2, %o0
a00d1810:  80 8a 20 ff  btst  0xff, %o0
a00d1814:  22 80 00 b6  be,a   0xa00d1aec
a00d1818:  aa 05 60 01  inc  %l5
a00d181c:  30 80 00 03  b,a   0xa00d1828
a00d1820:  12 80 00 49  bne  0xa00d1944
a00d1824:  a2 0d 60 ff  and  %l5, 0xff, %l1
a00d1828:  40 3b 1c b2  call  0xa0f98af0
a00d182c:  90 10 20 00  clr  %o0
a00d1830:  80 8a 20 ff  btst  0xff, %o0
a00d1834:  02 80 00 19  be  0xa00d1898
a00d1838:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d183c:  a0 10 00 01  mov  %g1, %l0
a00d1840:  82 10 63 a0  or  %g1, 0x3a0, %g1
a00d1844:  c2 08 60 02  ldub  [ %g1 + 2 ], %g1
a00d1848:  80 a0 60 00  cmp  %g1, 0
a00d184c:  12 80 00 10  bne  0xa00d188c
a00d1850:  9a 14 23 a0  or  %l0, 0x3a0, %o5
a00d1854:  40 3b c2 04  call  0xa0fc2064
a00d1858:  01 00 00 00  nop
a00d185c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d1860:  c2 00 63 ac  ld  [ %g1 + 0x3ac ], %g1	! 0xa8078bac
a00d1864:  90 22 00 01  sub  %o0, %g1, %o0
a00d1868:  80 a2 20 01  cmp  %o0, 1
a00d186c:  18 80 00 04  bgu  0xa00d187c
a00d1870:  80 a0 60 00  cmp  %g1, 0
a00d1874:  12 80 00 06  bne  0xa00d188c
a00d1878:  9a 14 23 a0  or  %l0, 0x3a0, %o5
a00d187c:  90 10 20 02  mov  2, %o0
a00d1880:  7f ff d8 73  call  0xa00c7a4c
a00d1884:  92 10 20 01  mov  1, %o1
a00d1888:  9a 14 23 a0  or  %l0, 0x3a0, %o5
a00d188c:  82 10 20 01  mov  1, %g1
a00d1890:  10 80 00 2c  b  0xa00d1940
a00d1894:  c2 2b 60 02  stb  %g1, [ %o5 + 2 ]
a00d1898:  a6 10 00 01  mov  %g1, %l3
a00d189c:  82 10 63 a0  or  %g1, 0x3a0, %g1
a00d18a0:  c2 08 60 02  ldub  [ %g1 + 2 ], %g1
a00d18a4:  80 a0 60 01  cmp  %g1, 1
a00d18a8:  12 80 00 07  bne  0xa00d18c4
a00d18ac:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a00d18b0:  40 3b c1 ed  call  0xa0fc2064
a00d18b4:  01 00 00 00  nop
a00d18b8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d18bc:  82 10 63 a4  or  %g1, 0x3a4, %g1	! 0xa8078ba4
a00d18c0:  d0 20 60 08  st  %o0, [ %g1 + 8 ]
a00d18c4:  a0 14 63 b0  or  %l1, 0x3b0, %l0
a00d18c8:  c2 04 20 30  ld  [ %l0 + 0x30 ], %g1
a00d18cc:  80 a0 60 00  cmp  %g1, 0
a00d18d0:  36 80 00 87  bge,a   0xa00d1aec
a00d18d4:  aa 05 60 01  inc  %l5
a00d18d8:  40 3b c1 e3  call  0xa0fc2064
a00d18dc:  01 00 00 00  nop
a00d18e0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d18e4:  a4 10 63 a4  or  %g1, 0x3a4, %l2	! 0xa8078ba4
a00d18e8:  c2 04 a0 08  ld  [ %l2 + 8 ], %g1
a00d18ec:  90 22 00 01  sub  %o0, %g1, %o0
a00d18f0:  03 00 00 04  sethi  %hi(0x1000), %g1
a00d18f4:  82 10 63 88  or  %g1, 0x388, %g1	! 0x1388
a00d18f8:  80 a2 00 01  cmp  %o0, %g1
a00d18fc:  08 80 00 0b  bleu  0xa00d1928
a00d1900:  82 14 63 b0  or  %l1, 0x3b0, %g1
a00d1904:  90 10 20 02  mov  2, %o0
a00d1908:  7f ff d8 51  call  0xa00c7a4c
a00d190c:  92 10 20 01  mov  1, %o1
a00d1910:  da 04 20 30  ld  [ %l0 + 0x30 ], %o5
a00d1914:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00d1918:  82 2b 40 01  andn  %o5, %g1, %g1
a00d191c:  c2 24 20 30  st  %g1, [ %l0 + 0x30 ]
a00d1920:  10 80 00 72  b  0xa00d1ae8
a00d1924:  c0 24 a0 08  clr  [ %l2 + 8 ]
a00d1928:  c2 00 60 30  ld  [ %g1 + 0x30 ], %g1
a00d192c:  80 a0 60 00  cmp  %g1, 0
a00d1930:  16 80 00 6e  bge  0xa00d1ae8
a00d1934:  82 14 e3 a0  or  %l3, 0x3a0, %g1
a00d1938:  10 80 00 6c  b  0xa00d1ae8
a00d193c:  c0 28 60 02  clrb  [ %g1 + 2 ]
a00d1940:  a2 0d 60 ff  and  %l5, 0xff, %l1
a00d1944:  80 a4 60 01  cmp  %l1, 1
a00d1948:  18 80 00 66  bgu  0xa00d1ae0
a00d194c:  90 10 00 11  mov  %l1, %o0
a00d1950:  92 10 20 00  clr  %o1
a00d1954:  40 3b 99 a1  call  0xa0fb7fd8
a00d1958:  94 10 20 09  mov  9, %o2
a00d195c:  80 8a 20 02  btst  2, %o0
a00d1960:  02 80 00 2d  be  0xa00d1a14
a00d1964:  29 2a 01 e2  sethi  %hi(0xa8078800), %l4
a00d1968:  7f ff ec 11  call  0xa00cc9ac
a00d196c:  90 10 00 11  mov  %l1, %o0
a00d1970:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d1974:  80 a2 20 01  cmp  %o0, 1
a00d1978:  12 80 00 27  bne  0xa00d1a14
a00d197c:  29 2a 01 e2  sethi  %hi(0xa8078800), %l4
a00d1980:  21 2a 01 e2  sethi  %hi(0xa8078800), %l0
a00d1984:  82 14 23 a0  or  %l0, 0x3a0, %g1	! 0xa8078ba0
a00d1988:  c2 08 40 11  ldub  [ %g1 + %l1 ], %g1
a00d198c:  80 a0 60 00  cmp  %g1, 0
a00d1990:  12 80 00 1e  bne  0xa00d1a08
a00d1994:  9a 14 23 a0  or  %l0, 0x3a0, %o5
a00d1998:  40 3b c1 b3  call  0xa0fc2064
a00d199c:  01 00 00 00  nop
a00d19a0:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00d19a4:  83 2c 60 02  sll  %l1, 2, %g1
a00d19a8:  9a 13 63 a4  or  %o5, 0x3a4, %o5
a00d19ac:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00d19b0:  90 22 00 01  sub  %o0, %g1, %o0
a00d19b4:  80 a2 20 5a  cmp  %o0, 0x5a
a00d19b8:  18 80 00 04  bgu  0xa00d19c8
a00d19bc:  80 a0 60 00  cmp  %g1, 0
a00d19c0:  12 80 00 12  bne  0xa00d1a08
a00d19c4:  9a 14 23 a0  or  %l0, 0x3a0, %o5
a00d19c8:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00d19cc:  92 10 00 11  mov  %l1, %o1
a00d19d0:  40 3a c5 9d  call  0xa0f83044
a00d19d4:  90 12 21 c8  or  %o0, 0x1c8, %o0
a00d19d8:  90 10 00 11  mov  %l1, %o0
a00d19dc:  7f ff d8 1c  call  0xa00c7a4c
a00d19e0:  92 10 20 01  mov  1, %o1
a00d19e4:  83 2c 60 03  sll  %l1, 3, %g1
a00d19e8:  82 20 40 11  sub  %g1, %l1, %g1
a00d19ec:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00d19f0:  83 28 60 02  sll  %g1, 2, %g1
a00d19f4:  9a 13 61 80  or  %o5, 0x180, %o5
a00d19f8:  82 00 40 0d  add  %g1, %o5, %g1
a00d19fc:  7f ff d1 6d  call  0xa00c5fb0
a00d1a00:  d0 08 60 01  ldub  [ %g1 + 1 ], %o0
a00d1a04:  9a 14 23 a0  or  %l0, 0x3a0, %o5
a00d1a08:  82 10 20 01  mov  1, %g1
a00d1a0c:  10 80 00 35  b  0xa00d1ae0
a00d1a10:  c2 2b 40 11  stb  %g1, [ %o5 + %l1 ]
a00d1a14:  82 15 23 a0  or  %l4, 0x3a0, %g1
a00d1a18:  c2 08 40 11  ldub  [ %g1 + %l1 ], %g1
a00d1a1c:  80 a0 60 01  cmp  %g1, 1
a00d1a20:  12 80 00 0a  bne  0xa00d1a48
a00d1a24:  82 04 40 11  add  %l1, %l1, %g1
a00d1a28:  7f ff ec 2b  call  0xa00ccad4
a00d1a2c:  90 10 00 11  mov  %l1, %o0
a00d1a30:  40 3b c1 8d  call  0xa0fc2064
a00d1a34:  a1 2c 60 02  sll  %l1, 2, %l0
a00d1a38:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d1a3c:  82 10 63 a4  or  %g1, 0x3a4, %g1	! 0xa8078ba4
a00d1a40:  d0 20 40 10  st  %o0, [ %g1 + %l0 ]
a00d1a44:  82 04 40 11  add  %l1, %l1, %g1
a00d1a48:  82 00 40 11  add  %g1, %l1, %g1
a00d1a4c:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a00d1a50:  a1 28 60 03  sll  %g1, 3, %l0
a00d1a54:  a4 14 e3 b0  or  %l3, 0x3b0, %l2
a00d1a58:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00d1a5c:  80 a0 60 00  cmp  %g1, 0
a00d1a60:  36 80 00 23  bge,a   0xa00d1aec
a00d1a64:  aa 05 60 01  inc  %l5
a00d1a68:  40 3b c1 7f  call  0xa0fc2064
a00d1a6c:  01 00 00 00  nop
a00d1a70:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d1a74:  98 10 63 a4  or  %g1, 0x3a4, %o4	! 0xa8078ba4
a00d1a78:  9b 2c 60 02  sll  %l1, 2, %o5
a00d1a7c:  c2 03 00 0d  ld  [ %o4 + %o5 ], %g1
a00d1a80:  90 22 00 01  sub  %o0, %g1, %o0
a00d1a84:  03 00 00 04  sethi  %hi(0x1000), %g1
a00d1a88:  82 10 63 88  or  %g1, 0x388, %g1	! 0x1388
a00d1a8c:  80 a2 00 01  cmp  %o0, %g1
a00d1a90:  08 80 00 0b  bleu  0xa00d1abc
a00d1a94:  82 04 40 11  add  %l1, %l1, %g1
a00d1a98:  c0 23 00 0d  clr  [ %o4 + %o5 ]
a00d1a9c:  90 10 00 11  mov  %l1, %o0
a00d1aa0:  7f ff d7 eb  call  0xa00c7a4c
a00d1aa4:  92 10 20 01  mov  1, %o1
a00d1aa8:  da 04 80 10  ld  [ %l2 + %l0 ], %o5
a00d1aac:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00d1ab0:  82 2b 40 01  andn  %o5, %g1, %g1
a00d1ab4:  10 80 00 0d  b  0xa00d1ae8
a00d1ab8:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a00d1abc:  82 00 40 11  add  %g1, %l1, %g1
a00d1ac0:  9a 14 e3 b0  or  %l3, 0x3b0, %o5
a00d1ac4:  83 28 60 03  sll  %g1, 3, %g1
a00d1ac8:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00d1acc:  80 a0 60 00  cmp  %g1, 0
a00d1ad0:  16 80 00 06  bge  0xa00d1ae8
a00d1ad4:  82 15 23 a0  or  %l4, 0x3a0, %g1
a00d1ad8:  10 80 00 04  b  0xa00d1ae8
a00d1adc:  c0 28 40 11  clrb  [ %g1 + %l1 ]
a00d1ae0:  7f ff fe 01  call  0xa00d12e4
a00d1ae4:  90 0d 60 ff  and  %l5, 0xff, %o0
a00d1ae8:  aa 05 60 01  inc  %l5
a00d1aec:  82 0d 60 ff  and  %l5, 0xff, %g1
a00d1af0:  80 a0 60 02  cmp  %g1, 2
a00d1af4:  08 bf ff 30  bleu  0xa00d17b4
a00d1af8:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00d1afc:  81 c7 e0 08  ret
a00d1b00:  81 e8 00 00  restore
