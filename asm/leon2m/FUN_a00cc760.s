# leon2m FUN_a00cc760 0xa00cc760-0xa00cc9c0 (608 bytes)
a00cc760:  9d e3 bf 98  save  %sp, -104, %sp
a00cc764:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00cc768:  9a 14 62 90  or  %l1, 0x290, %o5	! 0xa802d290
a00cc76c:  c2 0b 60 11  ldub  [ %o5 + 0x11 ], %g1
a00cc770:  80 a0 60 03  cmp  %g1, 3
a00cc774:  02 80 00 04  be  0xa00cc784
a00cc778:  90 10 20 03  mov  3, %o0
a00cc77c:  40 00 33 fa  call  0xa00d9764
a00cc780:  d0 2b 60 11  stb  %o0, [ %o5 + 0x11 ]
a00cc784:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00cc788:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cc78c:  80 a4 20 02  cmp  %l0, 2
a00cc790:  02 80 00 08  be  0xa00cc7b0
a00cc794:  82 12 60 40  or  %o1, 0x40, %g1
a00cc798:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cc79c:  80 a4 20 03  cmp  %l0, 3
a00cc7a0:  02 80 00 04  be  0xa00cc7b0
a00cc7a4:  82 12 a0 98  or  %o2, 0x98, %g1
a00cc7a8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cc7ac:  82 12 e0 d0  or  %o3, 0xd0, %g1	! 0xa802d0d0
a00cc7b0:  de 08 60 07  ldub  [ %g1 + 7 ], %o7
a00cc7b4:  94 03 ff d0  add  %o7, -48, %o2
a00cc7b8:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00cc7bc:  80 a3 60 01  cmp  %o5, 1
a00cc7c0:  d6 08 60 09  ldub  [ %g1 + 9 ], %o3
a00cc7c4:  d8 08 60 08  ldub  [ %g1 + 8 ], %o4
a00cc7c8:  18 80 00 07  bgu  0xa00cc7e4
a00cc7cc:  9a 10 20 ff  mov  0xff, %o5
a00cc7d0:  98 03 3f d0  add  %o4, -48, %o4
a00cc7d4:  b0 0b 20 ff  and  %o4, 0xff, %i0
a00cc7d8:  80 a6 20 09  cmp  %i0, 9
a00cc7dc:  28 80 00 31  bleu,a   0xa00cc8a0
a00cc7e0:  96 02 ff d0  add  %o3, -48, %o3
a00cc7e4:  80 a3 60 ff  cmp  %o5, 0xff
a00cc7e8:  02 80 00 74  be  0xa00cc9b8
a00cc7ec:  b0 10 20 ff  mov  0xff, %i0
a00cc7f0:  80 a3 60 64  cmp  %o5, 0x64
a00cc7f4:  18 80 00 71  bgu  0xa00cc9b8
a00cc7f8:  96 14 62 90  or  %l1, 0x290, %o3
a00cc7fc:  40 00 1f 7f  call  0xa00d45f8
a00cc800:  da 2a e0 12  stb  %o5, [ %o3 + 0x12 ]
a00cc804:  7f ff b0 32  call  0xa00b88cc
a00cc808:  01 00 00 00  nop
a00cc80c:  80 a4 20 02  cmp  %l0, 2
a00cc810:  02 80 00 33  be  0xa00cc8dc
a00cc814:  80 a4 20 03  cmp  %l0, 3
a00cc818:  02 80 00 4e  be  0xa00cc950
a00cc81c:  9e 10 20 30  mov  0x30, %o7
a00cc820:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cc824:  94 12 20 78  or  %o0, 0x78, %o2	! 0xa802d078
a00cc828:  82 10 20 35  mov  0x35, %g1
a00cc82c:  b0 10 20 36  mov  0x36, %i0
a00cc830:  9a 10 20 2b  mov  0x2b, %o5
a00cc834:  98 10 20 0d  mov  0xd, %o4
a00cc838:  c2 2a 20 78  stb  %g1, [ %o0 + 0x78 ]
a00cc83c:  f0 2a a0 01  stb  %i0, [ %o2 + 1 ]
a00cc840:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00cc844:  da 2a a0 04  stb  %o5, [ %o2 + 4 ]
a00cc848:  d8 2a a0 05  stb  %o4, [ %o2 + 5 ]
a00cc84c:  80 a4 20 02  cmp  %l0, 2
a00cc850:  02 80 00 30  be  0xa00cc910
a00cc854:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00cc858:  80 a4 20 03  cmp  %l0, 3
a00cc85c:  02 80 00 4a  be  0xa00cc984
a00cc860:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cc864:  9a 13 20 d0  or  %o4, 0xd0, %o5	! 0xa802d0d0
a00cc868:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00cc86c:  c0 2e 20 9c  clrb  [ %i0 + 0x9c ]	! 0xa802b09c
a00cc870:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00cc874:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00cc878:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00cc87c:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00cc880:  80 a4 20 02  cmp  %l0, 2
a00cc884:  02 80 00 2c  be  0xa00cc934
a00cc888:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00cc88c:  80 a4 20 03  cmp  %l0, 3
a00cc890:  12 80 00 2c  bne  0xa00cc940
a00cc894:  90 10 00 10  mov  %l0, %o0
a00cc898:  10 80 00 45  b  0xa00cc9ac
a00cc89c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cc8a0:  82 0a e0 ff  and  %o3, 0xff, %g1
a00cc8a4:  80 a0 60 09  cmp  %g1, 9
a00cc8a8:  18 bf ff d0  bgu  0xa00cc7e8
a00cc8ac:  80 a3 60 ff  cmp  %o5, 0xff
a00cc8b0:  90 0b 20 ff  and  %o4, 0xff, %o0
a00cc8b4:  83 2a 20 02  sll  %o0, 2, %g1
a00cc8b8:  9e 00 40 08  add  %g1, %o0, %o7
a00cc8bc:  b0 0a a0 ff  and  %o2, 0xff, %i0
a00cc8c0:  9a 03 c0 0f  add  %o7, %o7, %o5
a00cc8c4:  94 5e 20 64  smul  %i0, 0x64, %o2
a00cc8c8:  92 02 80 0d  add  %o2, %o5, %o1
a00cc8cc:  98 0a e0 ff  and  %o3, 0xff, %o4
a00cc8d0:  90 02 40 0c  add  %o1, %o4, %o0
a00cc8d4:  10 bf ff c4  b  0xa00cc7e4
a00cc8d8:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00cc8dc:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00cc8e0:  a0 13 61 28  or  %o5, 0x128, %l0	! 0xa802d128
a00cc8e4:  a2 10 20 30  mov  0x30, %l1
a00cc8e8:  9e 10 20 35  mov  0x35, %o7
a00cc8ec:  94 10 20 0d  mov  0xd, %o2
a00cc8f0:  98 10 20 36  mov  0x36, %o4
a00cc8f4:  92 10 20 2b  mov  0x2b, %o1
a00cc8f8:  de 2b 61 28  stb  %o7, [ %o5 + 0x128 ]
a00cc8fc:  d4 2c 20 05  stb  %o2, [ %l0 + 5 ]
a00cc900:  d8 2c 20 01  stb  %o4, [ %l0 + 1 ]
a00cc904:  e2 2c 20 03  stb  %l1, [ %l0 + 3 ]
a00cc908:  d2 2c 20 04  stb  %o1, [ %l0 + 4 ]
a00cc90c:  e2 2c 20 02  stb  %l1, [ %l0 + 2 ]
a00cc910:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cc914:  94 12 e0 40  or  %o3, 0x40, %o2	! 0xa802d040
a00cc918:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00cc91c:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00cc920:  c0 2a e0 40  clrb  [ %o3 + 0x40 ]
a00cc924:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00cc928:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00cc92c:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00cc930:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00cc934:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cc938:  94 12 21 28  or  %o0, 0x128, %o2	! 0xa802d128
a00cc93c:  90 10 20 02  mov  2, %o0
a00cc940:  40 01 ef aa  call  0xa01487e8
a00cc944:  92 10 20 06  mov  6, %o1
a00cc948:  10 80 00 1c  b  0xa00cc9b8
a00cc94c:  b0 10 20 00  clr  %i0
a00cc950:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00cc954:  b0 14 61 08  or  %l1, 0x108, %i0	! 0xa802d108
a00cc958:  90 10 20 30  mov  0x30, %o0
a00cc95c:  92 10 20 35  mov  0x35, %o1
a00cc960:  a0 10 20 0d  mov  0xd, %l0
a00cc964:  96 10 20 36  mov  0x36, %o3
a00cc968:  82 10 20 2b  mov  0x2b, %g1
a00cc96c:  d2 2c 61 08  stb  %o1, [ %l1 + 0x108 ]
a00cc970:  e0 2e 20 05  stb  %l0, [ %i0 + 5 ]
a00cc974:  d6 2e 20 01  stb  %o3, [ %i0 + 1 ]
a00cc978:  d0 2e 20 03  stb  %o0, [ %i0 + 3 ]
a00cc97c:  c2 2e 20 04  stb  %g1, [ %i0 + 4 ]
a00cc980:  d0 2e 20 02  stb  %o0, [ %i0 + 2 ]
a00cc984:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cc988:  a2 12 60 98  or  %o1, 0x98, %l1	! 0xa802d098
a00cc98c:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00cc990:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]	! 0xa802b098
a00cc994:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]
a00cc998:  c0 2c 60 19  clrb  [ %l1 + 0x19 ]
a00cc99c:  c0 2c 60 01  clrb  [ %l1 + 1 ]
a00cc9a0:  c0 2c 60 07  clrb  [ %l1 + 7 ]
a00cc9a4:  c0 2c 60 0a  clrb  [ %l1 + 0xa ]
a00cc9a8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cc9ac:  94 10 61 08  or  %g1, 0x108, %o2	! 0xa802d108
a00cc9b0:  10 bf ff e4  b  0xa00cc940
a00cc9b4:  90 10 20 03  mov  3, %o0
a00cc9b8:  81 c7 e0 08  ret
a00cc9bc:  81 e8 00 00  restore
