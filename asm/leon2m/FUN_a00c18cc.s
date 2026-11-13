# leon2m FUN_a00c18cc 0xa00c18cc-0xa00c1adc (528 bytes)
a00c18cc:  9d e3 bf 98  save  %sp, -104, %sp
a00c18d0:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00c18d4:  80 a4 60 02  cmp  %l1, 2
a00c18d8:  02 80 00 5f  be  0xa00c1a54
a00c18dc:  80 a4 60 03  cmp  %l1, 3
a00c18e0:  02 80 00 60  be  0xa00c1a60
a00c18e4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c18e8:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c18ec:  96 08 60 ff  and  %g1, 0xff, %o3
a00c18f0:  94 02 ff d0  add  %o3, -48, %o2
a00c18f4:  a0 0a a0 ff  and  %o2, 0xff, %l0
a00c18f8:  80 a4 20 03  cmp  %l0, 3
a00c18fc:  18 80 00 76  bgu  0xa00c1ad4
a00c1900:  b0 10 20 ff  mov  0xff, %i0
a00c1904:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c1908:  a4 13 62 90  or  %o5, 0x290, %l2	! 0xa802d290
a00c190c:  40 02 0b 3c  call  0xa01445fc
a00c1910:  d0 0c a0 1e  ldub  [ %l2 + 0x1e ], %o0
a00c1914:  98 0a 20 ff  and  %o0, 0xff, %o4
a00c1918:  80 a3 00 10  cmp  %o4, %l0
a00c191c:  02 80 00 6e  be  0xa00c1ad4
a00c1920:  01 00 00 00  nop
a00c1924:  40 02 0b 1e  call  0xa014459c
a00c1928:  90 10 00 10  mov  %l0, %o0
a00c192c:  40 00 5e 43  call  0xa00d9238
a00c1930:  d0 2c a0 1e  stb  %o0, [ %l2 + 0x1e ]
a00c1934:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a00c1938:  e4 13 e3 f4  lduh  [ %o7 + 0x3f4 ], %l2	! 0xa802cff4
a00c193c:  a0 14 a4 00  or  %l2, 0x400, %l0
a00c1940:  e0 33 e3 f4  sth  %l0, [ %o7 + 0x3f4 ]
a00c1944:  7f ff db e2  call  0xa00b88cc
a00c1948:  01 00 00 00  nop
a00c194c:  80 a4 60 02  cmp  %l1, 2
a00c1950:  02 80 00 24  be  0xa00c19e0
a00c1954:  80 a4 60 03  cmp  %l1, 3
a00c1958:  02 80 00 45  be  0xa00c1a6c
a00c195c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c1960:  94 13 20 78  or  %o4, 0x78, %o2	! 0xa802d078
a00c1964:  90 10 20 30  mov  0x30, %o0
a00c1968:  9e 10 20 35  mov  0x35, %o7
a00c196c:  96 10 20 36  mov  0x36, %o3
a00c1970:  92 10 20 2b  mov  0x2b, %o1
a00c1974:  82 10 20 0d  mov  0xd, %g1
a00c1978:  de 2b 20 78  stb  %o7, [ %o4 + 0x78 ]
a00c197c:  d6 2a a0 01  stb  %o3, [ %o2 + 1 ]
a00c1980:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00c1984:  d2 2a a0 04  stb  %o1, [ %o2 + 4 ]
a00c1988:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00c198c:  80 a4 60 02  cmp  %l1, 2
a00c1990:  02 80 00 21  be  0xa00c1a14
a00c1994:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00c1998:  80 a4 60 03  cmp  %l1, 3
a00c199c:  02 80 00 41  be  0xa00c1aa0
a00c19a0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c19a4:  90 12 60 d0  or  %o1, 0xd0, %o0	! 0xa802d0d0
a00c19a8:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c19ac:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]	! 0xa802b09c
a00c19b0:  c0 2a 60 d0  clrb  [ %o1 + 0xd0 ]
a00c19b4:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c19b8:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c19bc:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c19c0:  80 a4 60 02  cmp  %l1, 2
a00c19c4:  02 80 00 1d  be  0xa00c1a38
a00c19c8:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c19cc:  80 a4 60 03  cmp  %l1, 3
a00c19d0:  12 80 00 1d  bne  0xa00c1a44
a00c19d4:  90 10 00 11  mov  %l1, %o0
a00c19d8:  10 80 00 3c  b  0xa00c1ac8
a00c19dc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c19e0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c19e4:  a2 12 a1 28  or  %o2, 0x128, %l1	! 0xa802d128
a00c19e8:  b0 10 20 30  mov  0x30, %i0
a00c19ec:  96 10 20 35  mov  0x35, %o3
a00c19f0:  92 10 20 0d  mov  0xd, %o1
a00c19f4:  90 10 20 36  mov  0x36, %o0
a00c19f8:  82 10 20 2b  mov  0x2b, %g1
a00c19fc:  d6 2a a1 28  stb  %o3, [ %o2 + 0x128 ]
a00c1a00:  d2 2c 60 05  stb  %o1, [ %l1 + 5 ]
a00c1a04:  d0 2c 60 01  stb  %o0, [ %l1 + 1 ]
a00c1a08:  f0 2c 60 03  stb  %i0, [ %l1 + 3 ]
a00c1a0c:  c2 2c 60 04  stb  %g1, [ %l1 + 4 ]
a00c1a10:  f0 2c 60 02  stb  %i0, [ %l1 + 2 ]
a00c1a14:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c1a18:  94 13 60 40  or  %o5, 0x40, %o2	! 0xa802d040
a00c1a1c:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00c1a20:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00c1a24:  c0 2b 60 40  clrb  [ %o5 + 0x40 ]
a00c1a28:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c1a2c:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c1a30:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c1a34:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c1a38:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c1a3c:  94 12 e1 28  or  %o3, 0x128, %o2	! 0xa802d128
a00c1a40:  90 10 20 02  mov  2, %o0
a00c1a44:  40 02 1b 69  call  0xa01487e8
a00c1a48:  92 10 20 06  mov  6, %o1
a00c1a4c:  10 80 00 22  b  0xa00c1ad4
a00c1a50:  b0 10 20 00  clr  %i0
a00c1a54:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c1a58:  10 bf ff a5  b  0xa00c18ec
a00c1a5c:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c1a60:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c1a64:  10 bf ff a2  b  0xa00c18ec
a00c1a68:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c1a6c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c1a70:  98 14 61 08  or  %l1, 0x108, %o4	! 0xa802d108
a00c1a74:  9e 10 20 30  mov  0x30, %o7
a00c1a78:  b0 10 20 35  mov  0x35, %i0
a00c1a7c:  a4 10 20 0d  mov  0xd, %l2
a00c1a80:  a0 10 20 36  mov  0x36, %l0
a00c1a84:  9a 10 20 2b  mov  0x2b, %o5
a00c1a88:  f0 2c 61 08  stb  %i0, [ %l1 + 0x108 ]
a00c1a8c:  e4 2b 20 05  stb  %l2, [ %o4 + 5 ]
a00c1a90:  e0 2b 20 01  stb  %l0, [ %o4 + 1 ]
a00c1a94:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a00c1a98:  da 2b 20 04  stb  %o5, [ %o4 + 4 ]
a00c1a9c:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a00c1aa0:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c1aa4:  a4 14 60 98  or  %l1, 0x98, %l2	! 0xa802d098
a00c1aa8:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00c1aac:  c0 2e 20 98  clrb  [ %i0 + 0x98 ]	! 0xa802b098
a00c1ab0:  c0 2c 60 98  clrb  [ %l1 + 0x98 ]
a00c1ab4:  c0 2c a0 19  clrb  [ %l2 + 0x19 ]
a00c1ab8:  c0 2c a0 01  clrb  [ %l2 + 1 ]
a00c1abc:  c0 2c a0 07  clrb  [ %l2 + 7 ]
a00c1ac0:  c0 2c a0 0a  clrb  [ %l2 + 0xa ]
a00c1ac4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c1ac8:  94 13 21 08  or  %o4, 0x108, %o2	! 0xa802d108
a00c1acc:  10 bf ff de  b  0xa00c1a44
a00c1ad0:  90 10 20 03  mov  3, %o0
a00c1ad4:  81 c7 e0 08  ret
a00c1ad8:  81 e8 00 00  restore
