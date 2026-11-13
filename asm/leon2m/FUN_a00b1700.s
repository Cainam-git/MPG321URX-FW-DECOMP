# leon2m FUN_a00b1700 0xa00b1700-0xa00b1ba4 (1188 bytes)
a00b1700:  9d e3 bf 90  save  %sp, -112, %sp
a00b1704:  7f ff 7e 35  call  0xa0090fd8
a00b1708:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b170c:  40 00 0e 73  call  0xa00b50d8
a00b1710:  90 10 20 05  mov  5, %o0
a00b1714:  90 1e 20 1e  xor  %i0, 0x1e, %o0
a00b1718:  80 a0 00 08  cmp  %g0, %o0
a00b171c:  98 60 3f ff  subx  %g0, -1, %o4
a00b1720:  82 1e 20 32  xor  %i0, 0x32, %g1
a00b1724:  80 a0 00 01  cmp  %g0, %g1
a00b1728:  9a 60 3f ff  subx  %g0, -1, %o5
a00b172c:  80 93 00 0d  orcc  %o4, %o5, %g0
a00b1730:  ae 10 20 00  clr  %l7
a00b1734:  12 80 00 96  bne  0xa00b198c
a00b1738:  82 10 20 00  clr  %g1
a00b173c:  80 a6 20 37  cmp  %i0, 0x37
a00b1740:  02 80 00 93  be  0xa00b198c
a00b1744:  80 a6 20 00  cmp  %i0, 0
a00b1748:  12 80 00 9a  bne  0xa00b19b0
a00b174c:  ac 08 60 ff  and  %g1, 0xff, %l6
a00b1750:  94 0e 60 ff  and  %i1, 0xff, %o2
a00b1754:  80 a2 a0 03  cmp  %o2, 3
a00b1758:  82 10 20 0b  mov  0xb, %g1
a00b175c:  92 10 20 04  mov  4, %o1
a00b1760:  ae 62 60 00  subx  %o1, 0, %l7
a00b1764:  ac 08 60 ff  and  %g1, 0xff, %l6
a00b1768:  90 10 20 37  mov  0x37, %o0
a00b176c:  92 10 00 16  mov  %l6, %o1
a00b1770:  40 00 0e e2  call  0xa00b52f8
a00b1774:  94 10 27 92  mov  0x792, %o2
a00b1778:  17 00 00 24  sethi  %hi(0x9000), %o3
a00b177c:  90 12 e1 ae  or  %o3, 0x1ae, %o0	! 0x91ae
a00b1780:  40 02 54 cc  call  0xa0146ab0
a00b1784:  92 10 20 00  clr  %o1
a00b1788:  80 a5 a0 00  cmp  %l6, 0
a00b178c:  12 80 00 94  bne  0xa00b19dc
a00b1790:  a8 10 20 00  clr  %l4
a00b1794:  90 10 20 60  mov  0x60, %o0
a00b1798:  40 02 54 ee  call  0xa0146b50
a00b179c:  92 10 20 00  clr  %o1
a00b17a0:  90 10 20 02  mov  2, %o0
a00b17a4:  40 02 54 f2  call  0xa0146b6c
a00b17a8:  92 10 20 00  clr  %o1
a00b17ac:  b0 10 20 40  mov  0x40, %i0
a00b17b0:  90 10 20 01  mov  1, %o0
a00b17b4:  92 10 20 01  mov  1, %o1
a00b17b8:  94 10 27 92  mov  0x792, %o2
a00b17bc:  96 10 20 14  mov  0x14, %o3
a00b17c0:  98 10 20 01  mov  1, %o4
a00b17c4:  9a 10 20 0f  mov  0xf, %o5
a00b17c8:  40 00 06 c7  call  0xa00b32e4
a00b17cc:  f0 23 a0 5c  st  %i0, [ %sp + 0x5c ]
a00b17d0:  aa 10 20 4f  mov  0x4f, %l5
a00b17d4:  94 10 27 92  mov  0x792, %o2
a00b17d8:  96 10 20 14  mov  0x14, %o3
a00b17dc:  98 10 20 02  mov  2, %o4
a00b17e0:  9a 10 20 0f  mov  0xf, %o5
a00b17e4:  90 10 20 01  mov  1, %o0
a00b17e8:  92 10 20 01  mov  1, %o1
a00b17ec:  40 00 06 be  call  0xa00b32e4
a00b17f0:  ea 23 a0 5c  st  %l5, [ %sp + 0x5c ]
a00b17f4:  29 00 05 b7  sethi  %hi(0x16dc00), %l4
a00b17f8:  92 0d e0 ff  and  %l7, 0xff, %o1
a00b17fc:  7f ff c8 12  call  0xa00a3844
a00b1800:  90 15 21 e8  or  %l4, 0x1e8, %o0
a00b1804:  98 10 00 08  mov  %o0, %o4
a00b1808:  90 10 20 00  clr  %o0
a00b180c:  92 10 20 01  mov  1, %o1
a00b1810:  94 10 20 04  mov  4, %o2
a00b1814:  96 10 20 35  mov  0x35, %o3
a00b1818:  9a 10 20 00  clr  %o5
a00b181c:  7f ff c6 62  call  0xa00a31a4
a00b1820:  a6 05 ff fd  add  %l7, -3, %l3
a00b1824:  a4 0c e0 ff  and  %l3, 0xff, %l2
a00b1828:  80 a4 a0 01  cmp  %l2, 1
a00b182c:  18 80 00 40  bgu  0xa00b192c
a00b1830:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00b1834:  ee 0b 20 33  ldub  [ %o4 + 0x33 ], %l7	! 0xa802d033
a00b1838:  80 a5 e0 02  cmp  %l7, 2
a00b183c:  02 80 00 a3  be  0xa00b1ac8
a00b1840:  90 10 20 03  mov  3, %o0
a00b1844:  92 10 20 00  clr  %o1
a00b1848:  7f ff fb b2  call  0xa00b0710
a00b184c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00b1850:  a2 14 22 90  or  %l0, 0x290, %l1	! 0xa802d290
a00b1854:  29 00 06 40  sethi  %hi(0x190000), %l4
a00b1858:  d2 0c 60 08  ldub  [ %l1 + 8 ], %o1
a00b185c:  7f ff c7 fa  call  0xa00a3844
a00b1860:  90 15 21 84  or  %l4, 0x184, %o0
a00b1864:  98 10 00 08  mov  %o0, %o4
a00b1868:  9a 10 20 00  clr  %o5
a00b186c:  94 10 20 08  mov  8, %o2
a00b1870:  96 10 20 08  mov  8, %o3
a00b1874:  90 10 20 00  clr  %o0
a00b1878:  7f ff c6 4b  call  0xa00a31a4
a00b187c:  92 10 20 05  mov  5, %o1
a00b1880:  d6 0c 60 08  ldub  [ %l1 + 8 ], %o3
a00b1884:  94 02 e0 1d  add  %o3, 0x1d, %o2
a00b1888:  93 2a a0 10  sll  %o2, 0x10, %o1
a00b188c:  93 32 60 10  srl  %o1, 0x10, %o1
a00b1890:  7f ff c7 ed  call  0xa00a3844
a00b1894:  90 15 21 84  or  %l4, 0x184, %o0
a00b1898:  98 10 00 08  mov  %o0, %o4
a00b189c:  94 10 20 08  mov  8, %o2
a00b18a0:  96 10 20 08  mov  8, %o3
a00b18a4:  9a 10 20 00  clr  %o5
a00b18a8:  90 10 20 00  clr  %o0
a00b18ac:  7f ff c6 3e  call  0xa00a31a4
a00b18b0:  92 10 20 11  mov  0x11, %o1
a00b18b4:  d0 0c 60 08  ldub  [ %l1 + 8 ], %o0
a00b18b8:  82 02 20 3a  add  %o0, 0x3a, %g1
a00b18bc:  99 28 60 10  sll  %g1, 0x10, %o4
a00b18c0:  93 33 20 10  srl  %o4, 0x10, %o1
a00b18c4:  7f ff c7 e0  call  0xa00a3844
a00b18c8:  90 15 21 84  or  %l4, 0x184, %o0
a00b18cc:  98 10 00 08  mov  %o0, %o4
a00b18d0:  94 10 20 08  mov  8, %o2
a00b18d4:  96 10 20 08  mov  8, %o3
a00b18d8:  9a 10 20 00  clr  %o5
a00b18dc:  90 10 20 00  clr  %o0
a00b18e0:  7f ff c6 31  call  0xa00a31a4
a00b18e4:  92 10 20 1d  mov  0x1d, %o1
a00b18e8:  ee 0c 60 08  ldub  [ %l1 + 8 ], %l7
a00b18ec:  b0 05 e0 57  add  %l7, 0x57, %i0
a00b18f0:  ab 2e 20 10  sll  %i0, 0x10, %l5
a00b18f4:  93 35 60 10  srl  %l5, 0x10, %o1
a00b18f8:  7f ff c7 d3  call  0xa00a3844
a00b18fc:  90 15 21 84  or  %l4, 0x184, %o0
a00b1900:  98 10 00 08  mov  %o0, %o4
a00b1904:  90 10 20 00  clr  %o0
a00b1908:  92 10 20 29  mov  0x29, %o1
a00b190c:  94 10 20 08  mov  8, %o2
a00b1910:  96 10 20 08  mov  8, %o3
a00b1914:  7f ff c6 24  call  0xa00a31a4
a00b1918:  9a 10 20 00  clr  %o5
a00b191c:  a6 0e 60 ff  and  %i1, 0xff, %l3
a00b1920:  80 a4 e0 03  cmp  %l3, 3
a00b1924:  22 80 00 9a  be,a   0xa00b1b8c
a00b1928:  90 10 20 11  mov  0x11, %o0
a00b192c:  40 02 5a 94  call  0xa014837c
a00b1930:  90 10 20 00  clr  %o0
a00b1934:  83 2a 20 10  sll  %o0, 0x10, %g1
a00b1938:  99 30 60 10  srl  %g1, 0x10, %o4
a00b193c:  a9 2d a0 03  sll  %l6, 3, %l4
a00b1940:  ae 03 3a d8  add  %o4, -1320, %l7
a00b1944:  a6 05 00 16  add  %l4, %l6, %l3
a00b1948:  40 02 5a 8d  call  0xa014837c
a00b194c:  90 10 20 01  mov  1, %o0
a00b1950:  a3 35 e0 1f  srl  %l7, 0x1f, %l1
a00b1954:  a5 2c e0 02  sll  %l3, 2, %l2
a00b1958:  9a 22 00 12  sub  %o0, %l2, %o5
a00b195c:  b0 05 c0 11  add  %l7, %l1, %i0
a00b1960:  ab 2e 20 0f  sll  %i0, 0xf, %l5
a00b1964:  9e 03 7f 70  add  %o5, -144, %o7
a00b1968:  b3 35 60 10  srl  %l5, 0x10, %i1
a00b196c:  ad 2b e0 10  sll  %o7, 0x10, %l6
a00b1970:  90 10 00 19  mov  %i1, %o0
a00b1974:  93 35 a0 10  srl  %l6, 0x10, %o1
a00b1978:  40 02 52 f5  call  0xa014654c
a00b197c:  94 10 20 00  clr  %o2
a00b1980:  b0 10 20 01  mov  1, %i0
a00b1984:  40 02 55 0f  call  0xa0146dc0
a00b1988:  93 e8 20 00  restore  %g0, 0, %o1
a00b198c:  80 a6 20 1e  cmp  %i0, 0x1e
a00b1990:  02 80 00 07  be  0xa00b19ac
a00b1994:  82 10 20 08  mov  8, %g1
a00b1998:  80 a6 20 32  cmp  %i0, 0x32
a00b199c:  02 80 00 7a  be  0xa00b1b84
a00b19a0:  80 a6 20 37  cmp  %i0, 0x37
a00b19a4:  22 80 00 02  be,a   0xa00b19ac
a00b19a8:  ae 10 20 02  mov  2, %l7
a00b19ac:  ac 08 60 ff  and  %g1, 0xff, %l6
a00b19b0:  90 10 20 37  mov  0x37, %o0
a00b19b4:  92 10 00 16  mov  %l6, %o1
a00b19b8:  40 00 0e 50  call  0xa00b52f8
a00b19bc:  94 10 27 92  mov  0x792, %o2
a00b19c0:  17 00 00 24  sethi  %hi(0x9000), %o3
a00b19c4:  90 12 e1 ae  or  %o3, 0x1ae, %o0	! 0x91ae
a00b19c8:  40 02 54 3a  call  0xa0146ab0
a00b19cc:  92 10 20 00  clr  %o1
a00b19d0:  80 a5 a0 00  cmp  %l6, 0
a00b19d4:  02 bf ff 70  be  0xa00b1794
a00b19d8:  a8 10 20 00  clr  %l4
a00b19dc:  a0 1d a0 08  xor  %l6, 8, %l0
a00b19e0:  80 a0 00 10  cmp  %g0, %l0
a00b19e4:  1f 00 06 5f  sethi  %hi(0x197c00), %o7
a00b19e8:  a6 60 3f ff  subx  %g0, -1, %l3
a00b19ec:  aa 13 e3 50  or  %o7, 0x350, %l5
a00b19f0:  a2 0d 20 ff  and  %l4, 0xff, %l1
a00b19f4:  a0 04 60 03  add  %l1, 3, %l0
a00b19f8:  92 5c 60 37  smul  %l1, 0x37, %o1
a00b19fc:  96 5c 20 37  smul  %l0, 0x37, %o3
a00b1a00:  b0 02 40 15  add  %o1, %l5, %i0
a00b1a04:  a4 02 c0 15  add  %o3, %l5, %l2
a00b1a08:  80 a4 60 02  cmp  %l1, 2
a00b1a0c:  a0 10 20 00  clr  %l0
a00b1a10:  08 80 00 17  bleu  0xa00b1a6c
a00b1a14:  92 10 20 00  clr  %o1
a00b1a18:  10 80 00 11  b  0xa00b1a5c
a00b1a1c:  80 a4 e0 00  cmp  %l3, 0
a00b1a20:  9a 00 60 3f  add  %g1, 0x3f, %o5
a00b1a24:  98 0b 60 ff  and  %o5, 0xff, %o4
a00b1a28:  a0 04 20 01  inc  %l0
a00b1a2c:  80 a3 20 54  cmp  %o4, 0x54
a00b1a30:  90 10 20 01  mov  1, %o0
a00b1a34:  94 10 00 11  mov  %l1, %o2
a00b1a38:  96 10 20 01  mov  1, %o3
a00b1a3c:  02 80 00 04  be  0xa00b1a4c
a00b1a40:  9a 10 20 00  clr  %o5
a00b1a44:  40 02 54 37  call  0xa0146b20
a00b1a48:  01 00 00 00  nop
a00b1a4c:  92 0c 20 ff  and  %l0, 0xff, %o1
a00b1a50:  80 a2 60 37  cmp  %o1, 0x37
a00b1a54:  1a 80 00 16  bcc  0xa00b1aac
a00b1a58:  80 a4 e0 00  cmp  %l3, 0
a00b1a5c:  32 bf ff f1  bne,a   0xa00b1a20
a00b1a60:  c2 0c 80 09  ldub  [ %l2 + %o1 ], %g1
a00b1a64:  10 bf ff ef  b  0xa00b1a20
a00b1a68:  c2 0e 00 09  ldub  [ %i0 + %o1 ], %g1
a00b1a6c:  d4 0e 00 09  ldub  [ %i0 + %o1 ], %o2
a00b1a70:  90 02 a0 3f  add  %o2, 0x3f, %o0
a00b1a74:  98 0a 20 ff  and  %o0, 0xff, %o4
a00b1a78:  80 a3 20 54  cmp  %o4, 0x54
a00b1a7c:  22 80 00 08  be,a   0xa00b1a9c
a00b1a80:  a0 04 20 01  inc  %l0
a00b1a84:  90 10 20 01  mov  1, %o0
a00b1a88:  94 10 00 11  mov  %l1, %o2
a00b1a8c:  96 10 20 01  mov  1, %o3
a00b1a90:  40 02 54 24  call  0xa0146b20
a00b1a94:  9a 10 20 00  clr  %o5
a00b1a98:  a0 04 20 01  inc  %l0
a00b1a9c:  92 0c 20 ff  and  %l0, 0xff, %o1
a00b1aa0:  80 a2 60 37  cmp  %o1, 0x37
a00b1aa4:  2a bf ff f3  bcs,a   0xa00b1a70
a00b1aa8:  d4 0e 00 09  ldub  [ %i0 + %o1 ], %o2
a00b1aac:  a8 05 20 01  inc  %l4
a00b1ab0:  a2 0d 20 ff  and  %l4, 0xff, %l1
a00b1ab4:  80 a4 40 16  cmp  %l1, %l6
a00b1ab8:  2a bf ff d0  bcs,a   0xa00b19f8
a00b1abc:  a0 04 60 03  add  %l1, 3, %l0
a00b1ac0:  10 bf ff 36  b  0xa00b1798
a00b1ac4:  90 10 20 60  mov  0x60, %o0
a00b1ac8:  92 10 20 00  clr  %o1
a00b1acc:  7f ff fb 11  call  0xa00b0710
a00b1ad0:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00b1ad4:  a0 14 a2 90  or  %l2, 0x290, %l0	! 0xa802d290
a00b1ad8:  23 00 06 40  sethi  %hi(0x190000), %l1
a00b1adc:  d2 0c 20 08  ldub  [ %l0 + 8 ], %o1
a00b1ae0:  7f ff c7 59  call  0xa00a3844
a00b1ae4:  90 14 61 84  or  %l1, 0x184, %o0
a00b1ae8:  98 10 00 08  mov  %o0, %o4
a00b1aec:  94 10 20 08  mov  8, %o2
a00b1af0:  96 10 20 08  mov  8, %o3
a00b1af4:  9a 10 20 00  clr  %o5
a00b1af8:  90 10 20 00  clr  %o0
a00b1afc:  7f ff c5 aa  call  0xa00a31a4
a00b1b00:  92 10 20 0b  mov  0xb, %o1
a00b1b04:  da 0c 20 08  ldub  [ %l0 + 8 ], %o5
a00b1b08:  9e 03 60 1d  add  %o5, 0x1d, %o7
a00b1b0c:  97 2b e0 10  sll  %o7, 0x10, %o3
a00b1b10:  93 32 e0 10  srl  %o3, 0x10, %o1
a00b1b14:  7f ff c7 4c  call  0xa00a3844
a00b1b18:  90 14 61 84  or  %l1, 0x184, %o0
a00b1b1c:  98 10 00 08  mov  %o0, %o4
a00b1b20:  96 10 20 08  mov  8, %o3
a00b1b24:  9a 10 20 00  clr  %o5
a00b1b28:  94 10 20 08  mov  8, %o2
a00b1b2c:  90 10 20 00  clr  %o0
a00b1b30:  7f ff c5 9d  call  0xa00a31a4
a00b1b34:  92 10 20 18  mov  0x18, %o1
a00b1b38:  d4 0c 20 08  ldub  [ %l0 + 8 ], %o2
a00b1b3c:  92 02 a0 57  add  %o2, 0x57, %o1
a00b1b40:  91 2a 60 10  sll  %o1, 0x10, %o0
a00b1b44:  93 32 20 10  srl  %o0, 0x10, %o1
a00b1b48:  7f ff c7 3f  call  0xa00a3844
a00b1b4c:  90 14 61 84  or  %l1, 0x184, %o0
a00b1b50:  98 10 00 08  mov  %o0, %o4
a00b1b54:  90 10 20 00  clr  %o0
a00b1b58:  92 10 20 25  mov  0x25, %o1
a00b1b5c:  94 10 20 08  mov  8, %o2
a00b1b60:  96 10 20 08  mov  8, %o3
a00b1b64:  7f ff c5 90  call  0xa00a31a4
a00b1b68:  9a 10 20 00  clr  %o5
a00b1b6c:  82 0e 60 ff  and  %i1, 0xff, %g1
a00b1b70:  80 a0 60 03  cmp  %g1, 3
a00b1b74:  12 bf ff 6e  bne  0xa00b192c
a00b1b78:  90 10 20 18  mov  0x18, %o0
a00b1b7c:  10 80 00 05  b  0xa00b1b90
a00b1b80:  92 10 20 08  mov  8, %o1
a00b1b84:  10 bf ff 8a  b  0xa00b19ac
a00b1b88:  ae 10 20 01  mov  1, %l7
a00b1b8c:  92 10 20 08  mov  8, %o1
a00b1b90:  94 10 20 08  mov  8, %o2
a00b1b94:  96 10 22 c2  mov  0x2c2, %o3
a00b1b98:  40 02 53 ba  call  0xa0146a80
a00b1b9c:  98 10 20 00  clr  %o4
a00b1ba0:  30 bf ff 63  b,a   0xa00b192c
