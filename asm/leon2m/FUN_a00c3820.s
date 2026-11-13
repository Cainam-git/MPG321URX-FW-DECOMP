# leon2m FUN_a00c3820 0xa00c3820-0xa00c3a30 (528 bytes)
a00c3820:  9d e3 bf 98  save  %sp, -104, %sp
a00c3824:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c3828:  80 a4 20 02  cmp  %l0, 2
a00c382c:  02 80 00 5f  be  0xa00c39a8
a00c3830:  80 a4 20 03  cmp  %l0, 3
a00c3834:  02 80 00 60  be  0xa00c39b4
a00c3838:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c383c:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c3840:  96 08 60 ff  and  %g1, 0xff, %o3
a00c3844:  94 02 ff d0  add  %o3, -48, %o2
a00c3848:  82 0a a0 ff  and  %o2, 0xff, %g1
a00c384c:  80 a0 60 05  cmp  %g1, 5
a00c3850:  18 80 00 76  bgu  0xa00c3a28
a00c3854:  b0 10 20 ff  mov  0xff, %i0
a00c3858:  1f 0a aa aa  sethi  %hi(0x2aaaa800), %o7
a00c385c:  90 00 60 01  add  %g1, 1, %o0
a00c3860:  9a 13 e2 ab  or  %o7, 0x2ab, %o5
a00c3864:  80 5a 00 0d  smul  %o0, %o5, %g0
a00c3868:  99 40 00 00  rd  %y, %o4
a00c386c:  96 03 00 0c  add  %o4, %o4, %o3
a00c3870:  92 02 c0 0c  add  %o3, %o4, %o1
a00c3874:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c3878:  98 12 a2 90  or  %o2, 0x290, %o4	! 0xa802d290
a00c387c:  f0 03 20 a8  ld  [ %o4 + 0xa8 ], %i0
a00c3880:  82 02 40 09  add  %o1, %o1, %g1
a00c3884:  9e 22 00 01  sub  %o0, %g1, %o7
a00c3888:  9a 0e 37 ff  and  %i0, -2049, %o5
a00c388c:  de 2b 21 82  stb  %o7, [ %o4 + 0x182 ]
a00c3890:  40 00 61 18  call  0xa00dbcf0
a00c3894:  da 23 20 a8  st  %o5, [ %o4 + 0xa8 ]
a00c3898:  7f ff d4 0d  call  0xa00b88cc
a00c389c:  01 00 00 00  nop
a00c38a0:  80 a4 20 02  cmp  %l0, 2
a00c38a4:  02 80 00 24  be  0xa00c3934
a00c38a8:  80 a4 20 03  cmp  %l0, 3
a00c38ac:  02 80 00 45  be  0xa00c39c0
a00c38b0:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c38b4:  94 13 60 78  or  %o5, 0x78, %o2	! 0xa802d078
a00c38b8:  92 10 20 30  mov  0x30, %o1
a00c38bc:  b0 10 20 35  mov  0x35, %i0
a00c38c0:  9e 10 20 36  mov  0x36, %o7
a00c38c4:  98 10 20 2b  mov  0x2b, %o4
a00c38c8:  96 10 20 0d  mov  0xd, %o3
a00c38cc:  f0 2b 60 78  stb  %i0, [ %o5 + 0x78 ]
a00c38d0:  de 2a a0 01  stb  %o7, [ %o2 + 1 ]
a00c38d4:  d2 2a a0 03  stb  %o1, [ %o2 + 3 ]
a00c38d8:  d8 2a a0 04  stb  %o4, [ %o2 + 4 ]
a00c38dc:  d6 2a a0 05  stb  %o3, [ %o2 + 5 ]
a00c38e0:  80 a4 20 02  cmp  %l0, 2
a00c38e4:  02 80 00 21  be  0xa00c3968
a00c38e8:  d2 2a a0 02  stb  %o1, [ %o2 + 2 ]
a00c38ec:  80 a4 20 03  cmp  %l0, 3
a00c38f0:  02 80 00 41  be  0xa00c39f4
a00c38f4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c38f8:  9e 13 20 d0  or  %o4, 0xd0, %o7	! 0xa802d0d0
a00c38fc:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00c3900:  c0 2b 60 9c  clrb  [ %o5 + 0x9c ]	! 0xa802b09c
a00c3904:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00c3908:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00c390c:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00c3910:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00c3914:  80 a4 20 02  cmp  %l0, 2
a00c3918:  02 80 00 1d  be  0xa00c398c
a00c391c:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00c3920:  80 a4 20 03  cmp  %l0, 3
a00c3924:  12 80 00 1d  bne  0xa00c3998
a00c3928:  90 10 00 10  mov  %l0, %o0
a00c392c:  10 80 00 3c  b  0xa00c3a1c
a00c3930:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c3934:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c3938:  a0 12 a1 28  or  %o2, 0x128, %l0	! 0xa802d128
a00c393c:  b0 10 20 30  mov  0x30, %i0
a00c3940:  96 10 20 35  mov  0x35, %o3
a00c3944:  92 10 20 0d  mov  0xd, %o1
a00c3948:  82 10 20 36  mov  0x36, %g1
a00c394c:  90 10 20 2b  mov  0x2b, %o0
a00c3950:  d6 2a a1 28  stb  %o3, [ %o2 + 0x128 ]
a00c3954:  d2 2c 20 05  stb  %o1, [ %l0 + 5 ]
a00c3958:  c2 2c 20 01  stb  %g1, [ %l0 + 1 ]
a00c395c:  f0 2c 20 03  stb  %i0, [ %l0 + 3 ]
a00c3960:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00c3964:  f0 2c 20 02  stb  %i0, [ %l0 + 2 ]
a00c3968:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c396c:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c3970:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00c3974:  c0 2a 20 9a  clrb  [ %o0 + 0x9a ]	! 0xa802b09a
a00c3978:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c397c:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c3980:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c3984:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c3988:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c398c:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c3990:  94 16 21 28  or  %i0, 0x128, %o2	! 0xa802d128
a00c3994:  90 10 20 02  mov  2, %o0
a00c3998:  40 02 13 94  call  0xa01487e8
a00c399c:  92 10 20 06  mov  6, %o1
a00c39a0:  10 80 00 22  b  0xa00c3a28
a00c39a4:  b0 10 20 00  clr  %i0
a00c39a8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c39ac:  10 bf ff a5  b  0xa00c3840
a00c39b0:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c39b4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c39b8:  10 bf ff a2  b  0xa00c3840
a00c39bc:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c39c0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c39c4:  98 12 21 08  or  %o0, 0x108, %o4	! 0xa802d108
a00c39c8:  9e 10 20 30  mov  0x30, %o7
a00c39cc:  82 10 20 35  mov  0x35, %g1
a00c39d0:  b0 10 20 0d  mov  0xd, %i0
a00c39d4:  a0 10 20 36  mov  0x36, %l0
a00c39d8:  9a 10 20 2b  mov  0x2b, %o5
a00c39dc:  c2 2a 21 08  stb  %g1, [ %o0 + 0x108 ]
a00c39e0:  f0 2b 20 05  stb  %i0, [ %o4 + 5 ]
a00c39e4:  e0 2b 20 01  stb  %l0, [ %o4 + 1 ]
a00c39e8:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a00c39ec:  da 2b 20 04  stb  %o5, [ %o4 + 4 ]
a00c39f0:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a00c39f4:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c39f8:  92 12 e0 98  or  %o3, 0x98, %o1	! 0xa802d098
a00c39fc:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c3a00:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c3a04:  c0 2a e0 98  clrb  [ %o3 + 0x98 ]
a00c3a08:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00c3a0c:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00c3a10:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00c3a14:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00c3a18:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c3a1c:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c3a20:  10 bf ff de  b  0xa00c3998
a00c3a24:  90 10 20 03  mov  3, %o0
a00c3a28:  81 c7 e0 08  ret
a00c3a2c:  81 e8 00 00  restore
