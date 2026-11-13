# leon2m FUN_a00a192c 0xa00a192c-0xa00a1a68 (316 bytes)
a00a192c:  9d e3 bf 98  save  %sp, -104, %sp
a00a1930:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a00a1934:  40 00 1e a2  call  0xa00a93bc
a00a1938:  d0 0a 60 56  ldub  [ %o1 + 0x56 ], %o0	! 0xa8025c56
a00a193c:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a00a1940:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1	! 0xa802afec
a00a1944:  82 00 7f 40  add  %g1, -192, %g1
a00a1948:  80 a0 60 39  cmp  %g1, 0x39
a00a194c:  18 80 00 08  bgu  0xa00a196c
a00a1950:  92 10 20 00  clr  %o1
a00a1954:  15 00 00 be  sethi  %hi(0x2f800), %o2
a00a1958:  91 28 60 02  sll  %g1, 2, %o0
a00a195c:  9a 12 a3 40  or  %o2, 0x340, %o5
a00a1960:  d8 03 40 08  ld  [ %o5 + %o0 ], %o4
a00a1964:  81 c3 00 00  jmp  %o4
a00a1968:  01 00 00 00  nop
a00a196c:  92 10 20 00  clr  %o1	! 0x0
a00a1970:  94 10 20 01  mov  1, %o2
a00a1974:  40 00 19 f2  call  0xa00a813c
a00a1978:  90 10 20 01  mov  1, %o0
a00a197c:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1
a00a1980:  82 00 7f 40  add  %g1, -192, %g1
a00a1984:  80 a0 60 39  cmp  %g1, 0x39
a00a1988:  94 16 63 ec  or  %i1, 0x3ec, %o2
a00a198c:  18 80 00 08  bgu  0xa00a19ac
a00a1990:  96 10 20 00  clr  %o3
a00a1994:  1b 00 00 be  sethi  %hi(0x2f800), %o5
a00a1998:  99 28 60 02  sll  %g1, 2, %o4
a00a199c:  90 13 62 58  or  %o5, 0x258, %o0
a00a19a0:  d2 02 00 0c  ld  [ %o0 + %o4 ], %o1
a00a19a4:  81 c2 40 00  jmp  %o1
a00a19a8:  01 00 00 00  nop
a00a19ac:  82 10 20 00  clr  %g1	! 0x0
a00a19b0:  96 00 60 34  add  %g1, 0x34, %o3
a00a19b4:  d6 22 80 00  st  %o3, [ %o2 ]
a00a19b8:  d4 06 63 ec  ld  [ %i1 + 0x3ec ], %o2
a00a19bc:  b2 02 bf cc  add  %o2, -52, %i1
a00a19c0:  90 0e 60 ff  and  %i1, 0xff, %o0
a00a19c4:  40 00 1d 92  call  0xa00a900c
a00a19c8:  92 10 20 01  mov  1, %o1
a00a19cc:  90 10 20 01  mov  1, %o0
a00a19d0:  40 00 1e a6  call  0xa00a9468
a00a19d4:  92 10 20 02  mov  2, %o1
a00a19d8:  b0 10 20 00  clr  %i0
a00a19dc:  40 00 46 be  call  0xa00b34d4
a00a19e0:  93 e8 20 01  restore  %g0, 1, %o1
a00a19e4:  31 2a 00 b5  sethi  %hi(0xa802d400), %i0
a00a19e8:  d2 0e 20 7c  ldub  [ %i0 + 0x7c ], %o1	! 0xa802d47c
a00a19ec:  10 bf ff e1  b  0xa00a1970
a00a19f0:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a19f4:  96 10 20 06  mov  6, %o3
a00a19f8:  82 0a e0 ff  and  %o3, 0xff, %g1
a00a19fc:  96 00 60 34  add  %g1, 0x34, %o3
a00a1a00:  d6 22 80 00  st  %o3, [ %o2 ]
a00a1a04:  d4 06 63 ec  ld  [ %i1 + 0x3ec ], %o2
a00a1a08:  b2 02 bf cc  add  %o2, -52, %i1
a00a1a0c:  90 0e 60 ff  and  %i1, 0xff, %o0
a00a1a10:  40 00 1d 7f  call  0xa00a900c
a00a1a14:  92 10 20 01  mov  1, %o1
a00a1a18:  90 10 20 01  mov  1, %o0
a00a1a1c:  40 00 1e 93  call  0xa00a9468
a00a1a20:  92 10 20 02  mov  2, %o1
a00a1a24:  b0 10 20 00  clr  %i0
a00a1a28:  40 00 46 ab  call  0xa00b34d4
a00a1a2c:  93 e8 20 01  restore  %g0, 1, %o1
a00a1a30:  96 10 20 04  mov  4, %o3
a00a1a34:  10 bf ff f2  b  0xa00a19fc
a00a1a38:  82 0a e0 ff  and  %o3, 0xff, %g1
a00a1a3c:  96 10 20 05  mov  5, %o3
a00a1a40:  10 bf ff ef  b  0xa00a19fc
a00a1a44:  82 0a e0 ff  and  %o3, 0xff, %g1
a00a1a48:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00a1a4c:  d2 0a e0 78  ldub  [ %o3 + 0x78 ], %o1	! 0xa802d478
a00a1a50:  10 bf ff c8  b  0xa00a1970
a00a1a54:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a1a58:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a00a1a5c:  d2 0b e0 7a  ldub  [ %o7 + 0x7a ], %o1	! 0xa802d47a
a00a1a60:  10 bf ff c4  b  0xa00a1970
a00a1a64:  92 0a 60 ff  and  %o1, 0xff, %o1
