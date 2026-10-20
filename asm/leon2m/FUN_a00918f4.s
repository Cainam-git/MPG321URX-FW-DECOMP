# leon2m FUN_a00918f4 0xa00918f4-0xa00919b4 (192 bytes)
a00918f4:  9d e3 bf 98  save  %sp, -104, %sp
a00918f8:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a00918fc:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1	! 0xa802afec
a0091900:  90 02 7f fe  add  %o1, -2, %o0
a0091904:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091908:  40 00 8a 0f  call  0xa00b4144
a009190c:  92 10 20 02  mov  2, %o1
a0091910:  82 10 20 0e  mov  0xe, %g1
a0091914:  1b 24 92 49  sethi  %hi(0x92492400), %o5
a0091918:  c2 26 63 ec  st  %g1, [ %i1 + 0x3ec ]
a009191c:  b0 13 60 93  or  %o5, 0x93, %i0
a0091920:  10 80 00 0e  b  0xa0091958
a0091924:  a0 10 00 19  mov  %i1, %l0
a0091928:  90 03 3f f3  add  %o4, -13, %o0
a009192c:  80 5a 00 18  smul  %o0, %i0, %g0
a0091930:  9b 40 00 00  rd  %y, %o5
a0091934:  82 03 40 08  add  %o5, %o0, %g1
a0091938:  9f 38 60 02  sra  %g1, 2, %o7
a009193c:  97 3a 20 1f  sra  %o0, 0x1f, %o3
a0091940:  94 23 c0 0b  sub  %o7, %o3, %o2
a0091944:  93 2a a0 03  sll  %o2, 3, %o1
a0091948:  9a 22 40 0a  sub  %o1, %o2, %o5
a009194c:  82 22 00 0d  sub  %o0, %o5, %g1
a0091950:  9e 00 60 0e  add  %g1, 0xe, %o7
a0091954:  de 26 63 ec  st  %o7, [ %i1 + 0x3ec ]
a0091958:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a009195c:  96 03 3f f2  add  %o4, -14, %o3
a0091960:  40 00 62 f0  call  0xa00aa520
a0091964:  90 0a e0 ff  and  %o3, 0xff, %o0
a0091968:  94 0a 20 ff  and  %o0, 0xff, %o2
a009196c:  80 a2 a0 01  cmp  %o2, 1
a0091970:  12 bf ff ee  bne  0xa0091928
a0091974:  d8 16 63 ee  lduh  [ %i1 + 0x3ee ], %o4
a0091978:  d2 04 23 ec  ld  [ %l0 + 0x3ec ], %o1
a009197c:  90 02 7f f2  add  %o1, -14, %o0
a0091980:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091984:  40 00 5d a2  call  0xa00a900c
a0091988:  92 10 20 01  mov  1, %o1
a009198c:  f2 04 23 ec  ld  [ %l0 + 0x3ec ], %i1
a0091990:  b0 06 7f f2  add  %i1, -14, %i0
a0091994:  92 0e 20 ff  and  %i0, 0xff, %o1
a0091998:  40 00 76 ad  call  0xa00af44c
a009199c:  90 10 20 0e  mov  0xe, %o0
a00919a0:  21 2a 00 b5  sethi  %hi(0xa802d400), %l0
a00919a4:  f0 0c 20 12  ldub  [ %l0 + 0x12 ], %i0	! 0xa802d412
a00919a8:  40 00 5f 2a  call  0xa00a9650
a00919ac:  93 e8 20 00  restore  %g0, 0, %o1
a00919b0:  01 00 00 00  nop
