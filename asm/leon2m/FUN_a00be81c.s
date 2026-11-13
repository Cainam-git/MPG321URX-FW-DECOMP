# leon2m FUN_a00be81c 0xa00be81c-0xa00be9a8 (396 bytes)
a00be81c:  9d e3 bf 98  save  %sp, -104, %sp
a00be820:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00be824:  d6 0b 63 3c  ldub  [ %o5 + 0x33c ], %o3	! 0xa802d33c
a00be828:  9f 2a e0 02  sll  %o3, 2, %o7
a00be82c:  92 03 c0 0b  add  %o7, %o3, %o1
a00be830:  99 2a 60 02  sll  %o1, 2, %o4
a00be834:  9a 03 20 14  add  %o4, 0x14, %o5
a00be838:  11 14 7a e1  sethi  %hi(0x51eb8400), %o0
a00be83c:  b2 0b 60 fc  and  %o5, 0xfc, %i1
a00be840:  82 12 21 1f  or  %o0, 0x11f, %g1
a00be844:  80 56 40 01  umul  %i1, %g1, %g0
a00be848:  95 40 00 00  rd  %y, %o2
a00be84c:  b3 32 a0 05  srl  %o2, 5, %i1
a00be850:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00be854:  a0 5e a0 64  smul  %i2, 0x64, %l0
a00be858:  b4 23 40 10  sub  %o5, %l0, %i2
a00be85c:  17 33 33 33  sethi  %hi(0xcccccc00), %o3
a00be860:  92 0e a0 fc  and  %i2, 0xfc, %o1
a00be864:  9e 12 e0 cd  or  %o3, 0xcd, %o7
a00be868:  80 52 40 0f  umul  %o1, %o7, %g0
a00be86c:  99 40 00 00  rd  %y, %o4
a00be870:  9f 33 20 03  srl  %o4, 3, %o7
a00be874:  90 0b e0 ff  and  %o7, 0xff, %o0
a00be878:  83 2a 20 02  sll  %o0, 2, %g1
a00be87c:  a0 00 40 08  add  %g1, %o0, %l0
a00be880:  96 04 00 10  add  %l0, %l0, %o3
a00be884:  92 26 80 0b  sub  %i2, %o3, %o1
a00be888:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00be88c:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00be890:  9a 02 60 30  add  %o1, 0x30, %o5
a00be894:  98 03 e0 30  add  %o7, 0x30, %o4
a00be898:  94 06 60 30  add  %i1, 0x30, %o2
a00be89c:  d8 2c 20 08  stb  %o4, [ %l0 + 8 ]
a00be8a0:  da 2c 20 09  stb  %o5, [ %l0 + 9 ]
a00be8a4:  d4 2c 20 07  stb  %o2, [ %l0 + 7 ]
a00be8a8:  92 10 20 00  clr  %o1
a00be8ac:  40 02 57 64  call  0xa015463c
a00be8b0:  90 10 20 78  mov  0x78, %o0
a00be8b4:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00be8b8:  90 10 20 62  mov  0x62, %o0
a00be8bc:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00be8c0:  92 10 20 02  mov  2, %o1
a00be8c4:  40 02 57 5e  call  0xa015463c
a00be8c8:  90 10 20 78  mov  0x78, %o0
a00be8cc:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00be8d0:  92 10 20 03  mov  3, %o1
a00be8d4:  40 02 57 5a  call  0xa015463c
a00be8d8:  90 10 20 78  mov  0x78, %o0
a00be8dc:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00be8e0:  92 10 20 04  mov  4, %o1
a00be8e4:  40 02 57 56  call  0xa015463c
a00be8e8:  90 10 20 78  mov  0x78, %o0
a00be8ec:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00be8f0:  92 10 20 05  mov  5, %o1
a00be8f4:  40 02 57 52  call  0xa015463c
a00be8f8:  90 10 20 78  mov  0x78, %o0
a00be8fc:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00be900:  92 10 20 06  mov  6, %o1
a00be904:  40 02 57 4e  call  0xa015463c
a00be908:  90 10 20 78  mov  0x78, %o0
a00be90c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00be910:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be914:  82 10 20 0d  mov  0xd, %g1
a00be918:  9a 13 20 40  or  %o4, 0x40, %o5
a00be91c:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00be920:  80 a6 20 02  cmp  %i0, 2
a00be924:  02 80 00 12  be  0xa00be96c
a00be928:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00be92c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00be930:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00be934:  96 12 a0 98  or  %o2, 0x98, %o3
a00be938:  80 a6 20 03  cmp  %i0, 3
a00be93c:  02 80 00 10  be  0xa00be97c
a00be940:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00be944:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00be948:  c0 2a a0 9c  clrb  [ %o2 + 0x9c ]	! 0xa802b09c
a00be94c:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00be950:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00be954:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00be958:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00be95c:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00be960:  b4 16 a0 78  or  %i2, 0x78, %i2
a00be964:  40 02 27 a1  call  0xa01487e8
a00be968:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be96c:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00be970:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00be974:  10 bf ff f7  b  0xa00be950
a00be978:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00be97c:  33 2a 00 ac  sethi  %hi(0xa802b000), %i1
a00be980:  c0 2e 60 98  clrb  [ %i1 + 0x98 ]	! 0xa802b098
a00be984:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00be988:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00be98c:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00be990:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00be994:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00be998:  b4 16 a0 78  or  %i2, 0x78, %i2
a00be99c:  40 02 27 93  call  0xa01487e8
a00be9a0:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be9a4:  01 00 00 00  nop
