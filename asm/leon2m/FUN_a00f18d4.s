# leon2m FUN_a00f18d4 0xa00f18d4-0xa00f19a4 (208 bytes)
a00f18d4:  9d e3 bf 98  save  %sp, -104, %sp
a00f18d8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f18dc:  82 10 00 19  mov  %i1, %g1
a00f18e0:  80 a6 20 02  cmp  %i0, 2
a00f18e4:  02 80 00 15  be  0xa00f1938
a00f18e8:  b2 10 00 1a  mov  %i2, %i1
a00f18ec:  b9 28 60 10  sll  %g1, 0x10, %i4
a00f18f0:  b6 06 00 18  add  %i0, %i0, %i3
a00f18f4:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00f18f8:  b0 10 62 7a  or  %g1, 0x27a, %i0	! 0xa8026a7a
a00f18fc:  f4 16 00 1b  lduh  [ %i0 + %i3 ], %i2
a00f1900:  bb 37 20 10  srl  %i4, 0x10, %i5
a00f1904:  b6 06 80 1d  add  %i2, %i5, %i3
a00f1908:  83 2e e0 02  sll  %i3, 2, %g1
a00f190c:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a00f1910:  b0 06 e0 01  add  %i3, 1, %i0
a00f1914:  ba 10 40 1a  or  %g1, %i2, %i5
a00f1918:  b7 2e 20 02  sll  %i0, 2, %i3
a00f191c:  b8 0e 60 ff  and  %i1, 0xff, %i4
a00f1920:  83 2e 60 10  sll  %i1, 0x10, %g1
a00f1924:  f8 27 40 00  st  %i4, [ %i5 ]
a00f1928:  b6 16 c0 1a  or  %i3, %i2, %i3
a00f192c:  b1 30 60 18  srl  %g1, 0x18, %i0
a00f1930:  f0 26 c0 00  st  %i0, [ %i3 ]
a00f1934:  30 80 00 1a  b,a   0xa00f199c
a00f1938:  3b 2a 00 9a  sethi  %hi(0xa8026800), %i5
a00f193c:  b9 2e a0 10  sll  %i2, 0x10, %i4
a00f1940:  83 28 60 10  sll  %g1, 0x10, %g1
a00f1944:  9a 17 62 7a  or  %i5, 0x27a, %o5
a00f1948:  9f 30 60 10  srl  %g1, 0x10, %o7
a00f194c:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00f1950:  b9 37 20 18  srl  %i4, 0x18, %i4
a00f1954:  b6 10 20 00  clr  %i3
a00f1958:  ba 10 20 00  clr  %i5
a00f195c:  31 33 c0 00  sethi  %hi(0xcf000000), %i0
a00f1960:  82 07 40 1d  add  %i5, %i5, %g1
a00f1964:  f2 13 40 01  lduh  [ %o5 + %g1 ], %i1
a00f1968:  ba 06 40 0f  add  %i1, %o7, %i5
a00f196c:  b2 07 60 01  add  %i5, 1, %i1
a00f1970:  83 2f 60 02  sll  %i5, 2, %g1
a00f1974:  ba 10 40 18  or  %g1, %i0, %i5
a00f1978:  f4 27 40 00  st  %i2, [ %i5 ]
a00f197c:  83 2e 60 02  sll  %i1, 2, %g1
a00f1980:  b6 06 e0 01  inc  %i3
a00f1984:  b2 10 40 18  or  %g1, %i0, %i1
a00f1988:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00f198c:  f8 26 40 00  st  %i4, [ %i1 ]
a00f1990:  80 a7 60 01  cmp  %i5, 1
a00f1994:  08 bf ff f4  bleu  0xa00f1964
a00f1998:  82 07 40 1d  add  %i5, %i5, %g1
a00f199c:  81 c7 e0 08  ret
a00f19a0:  81 e8 00 00  restore
