# leon2m FUN_a00c17e8 0xa00c17e8-0xa00c18cc (228 bytes)
a00c17e8:  9d e3 bf 98  save  %sp, -104, %sp
a00c17ec:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c17f0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c17f4:  80 a4 20 02  cmp  %l0, 2
a00c17f8:  02 80 00 08  be  0xa00c1818
a00c17fc:  82 10 60 40  or  %g1, 0x40, %g1
a00c1800:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c1804:  80 a4 20 03  cmp  %l0, 3
a00c1808:  02 80 00 04  be  0xa00c1818
a00c180c:  82 12 20 98  or  %o0, 0x98, %g1
a00c1810:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c1814:  82 12 60 d0  or  %o1, 0xd0, %g1	! 0xa802d0d0
a00c1818:  de 08 60 07  ldub  [ %g1 + 7 ], %o7
a00c181c:  94 03 ff d0  add  %o7, -48, %o2
a00c1820:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00c1824:  80 a3 60 01  cmp  %o5, 1
a00c1828:  d6 08 60 09  ldub  [ %g1 + 9 ], %o3
a00c182c:  d8 08 60 08  ldub  [ %g1 + 8 ], %o4
a00c1830:  18 80 00 07  bgu  0xa00c184c
a00c1834:  9a 10 20 ff  mov  0xff, %o5
a00c1838:  98 03 3f d0  add  %o4, -48, %o4
a00c183c:  b0 0b 20 ff  and  %o4, 0xff, %i0
a00c1840:  80 a6 20 09  cmp  %i0, 9
a00c1844:  28 80 00 11  bleu,a   0xa00c1888
a00c1848:  96 02 ff d0  add  %o3, -48, %o3
a00c184c:  80 a3 60 1e  cmp  %o5, 0x1e
a00c1850:  18 80 00 1d  bgu  0xa00c18c4
a00c1854:  b0 10 20 ff  mov  0xff, %i0
a00c1858:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c185c:  7f ff dc 1c  call  0xa00b88cc
a00c1860:  da 2a e2 9c  stb  %o5, [ %o3 + 0x29c ]	! 0xa802d29c
a00c1864:  7f ff e4 82  call  0xa00baa6c
a00c1868:  90 10 00 10  mov  %l0, %o0
a00c186c:  7f ff e4 39  call  0xa00ba950
a00c1870:  90 10 00 10  mov  %l0, %o0
a00c1874:  90 10 00 10  mov  %l0, %o0
a00c1878:  7f ff e4 c2  call  0xa00bab80
a00c187c:  92 10 20 06  mov  6, %o1
a00c1880:  10 80 00 11  b  0xa00c18c4
a00c1884:  b0 10 20 00  clr  %i0
a00c1888:  82 0a e0 ff  and  %o3, 0xff, %g1
a00c188c:  80 a0 60 09  cmp  %g1, 9
a00c1890:  18 bf ff f0  bgu  0xa00c1850
a00c1894:  80 a3 60 1e  cmp  %o5, 0x1e
a00c1898:  90 0b 20 ff  and  %o4, 0xff, %o0
a00c189c:  83 2a 20 02  sll  %o0, 2, %g1
a00c18a0:  9e 00 40 08  add  %g1, %o0, %o7
a00c18a4:  b0 0a a0 ff  and  %o2, 0xff, %i0
a00c18a8:  9a 03 c0 0f  add  %o7, %o7, %o5
a00c18ac:  92 5e 20 64  smul  %i0, 0x64, %o1
a00c18b0:  90 02 40 0d  add  %o1, %o5, %o0
a00c18b4:  98 0a e0 ff  and  %o3, 0xff, %o4
a00c18b8:  94 02 00 0c  add  %o0, %o4, %o2
a00c18bc:  10 bf ff e4  b  0xa00c184c
a00c18c0:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00c18c4:  81 c7 e0 08  ret
a00c18c8:  81 e8 00 00  restore
