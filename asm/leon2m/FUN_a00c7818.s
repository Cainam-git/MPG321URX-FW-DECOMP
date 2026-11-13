# leon2m FUN_a00c7818 0xa00c7818-0xa00c7a5c (580 bytes)
a00c7818:  9d e3 bf 98  save  %sp, -104, %sp
a00c781c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c7820:  80 a4 20 02  cmp  %l0, 2
a00c7824:  02 80 00 55  be  0xa00c7978
a00c7828:  80 a4 20 03  cmp  %l0, 3
a00c782c:  02 80 00 6d  be  0xa00c79e0
a00c7830:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c7834:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c7838:  96 08 60 ff  and  %g1, 0xff, %o3
a00c783c:  94 02 ff d0  add  %o3, -48, %o2
a00c7840:  98 0a a0 ff  and  %o2, 0xff, %o4
a00c7844:  80 a3 20 01  cmp  %o4, 1
a00c7848:  18 80 00 83  bgu  0xa00c7a54
a00c784c:  b0 10 20 ff  mov  0xff, %i0
a00c7850:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c7854:  96 13 e2 90  or  %o7, 0x290, %o3	! 0xa802d290
a00c7858:  da 0a e0 1f  ldub  [ %o3 + 0x1f ], %o5
a00c785c:  80 a3 60 00  cmp  %o5, 0
a00c7860:  02 80 00 49  be  0xa00c7984
a00c7864:  90 0b 20 01  and  %o4, 1, %o0
a00c7868:  7f ff c4 19  call  0xa00b88cc
a00c786c:  01 00 00 00  nop
a00c7870:  80 a4 20 02  cmp  %l0, 2
a00c7874:  02 80 00 24  be  0xa00c7904
a00c7878:  80 a4 20 03  cmp  %l0, 3
a00c787c:  02 80 00 5c  be  0xa00c79ec
a00c7880:  9e 10 20 35  mov  0x35, %o7
a00c7884:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c7888:  94 12 60 78  or  %o1, 0x78, %o2	! 0xa802d078
a00c788c:  b0 10 20 30  mov  0x30, %i0
a00c7890:  90 10 20 36  mov  0x36, %o0
a00c7894:  82 10 20 2b  mov  0x2b, %g1
a00c7898:  98 10 20 0d  mov  0xd, %o4
a00c789c:  de 2a 60 78  stb  %o7, [ %o1 + 0x78 ]
a00c78a0:  d0 2a a0 01  stb  %o0, [ %o2 + 1 ]
a00c78a4:  f0 2a a0 03  stb  %i0, [ %o2 + 3 ]
a00c78a8:  c2 2a a0 04  stb  %g1, [ %o2 + 4 ]
a00c78ac:  d8 2a a0 05  stb  %o4, [ %o2 + 5 ]
a00c78b0:  80 a4 20 02  cmp  %l0, 2
a00c78b4:  02 80 00 21  be  0xa00c7938
a00c78b8:  f0 2a a0 02  stb  %i0, [ %o2 + 2 ]
a00c78bc:  80 a4 20 03  cmp  %l0, 3
a00c78c0:  02 80 00 58  be  0xa00c7a20
a00c78c4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c78c8:  90 12 60 d0  or  %o1, 0xd0, %o0	! 0xa802d0d0
a00c78cc:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c78d0:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]	! 0xa802b09c
a00c78d4:  c0 2a 60 d0  clrb  [ %o1 + 0xd0 ]
a00c78d8:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c78dc:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c78e0:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c78e4:  80 a4 20 02  cmp  %l0, 2
a00c78e8:  02 80 00 1d  be  0xa00c795c
a00c78ec:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c78f0:  80 a4 20 03  cmp  %l0, 3
a00c78f4:  12 80 00 1d  bne  0xa00c7968
a00c78f8:  90 10 00 10  mov  %l0, %o0
a00c78fc:  10 80 00 53  b  0xa00c7a48
a00c7900:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c7904:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c7908:  a0 16 21 28  or  %i0, 0x128, %l0	! 0xa802d128
a00c790c:  9e 10 20 30  mov  0x30, %o7
a00c7910:  82 10 20 35  mov  0x35, %g1
a00c7914:  98 10 20 0d  mov  0xd, %o4
a00c7918:  9a 10 20 36  mov  0x36, %o5
a00c791c:  96 10 20 2b  mov  0x2b, %o3
a00c7920:  c2 2e 21 28  stb  %g1, [ %i0 + 0x128 ]
a00c7924:  d8 2c 20 05  stb  %o4, [ %l0 + 5 ]
a00c7928:  da 2c 20 01  stb  %o5, [ %l0 + 1 ]
a00c792c:  de 2c 20 03  stb  %o7, [ %l0 + 3 ]
a00c7930:  d6 2c 20 04  stb  %o3, [ %l0 + 4 ]
a00c7934:  de 2c 20 02  stb  %o7, [ %l0 + 2 ]
a00c7938:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c793c:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c7940:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c7944:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]	! 0xa802b09a
a00c7948:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c794c:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c7950:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c7954:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c7958:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c795c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c7960:  94 13 e1 28  or  %o7, 0x128, %o2	! 0xa802d128
a00c7964:  90 10 20 02  mov  2, %o0
a00c7968:  40 02 03 a0  call  0xa01487e8
a00c796c:  92 10 20 06  mov  6, %o1
a00c7970:  10 80 00 39  b  0xa00c7a54
a00c7974:  b0 10 20 00  clr  %i0
a00c7978:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c797c:  10 bf ff af  b  0xa00c7838
a00c7980:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c7984:  d4 02 e0 ac  ld  [ %o3 + 0xac ], %o2
a00c7988:  13 00 04 00  sethi  %hi(0x100000), %o1
a00c798c:  83 2a 20 14  sll  %o0, 0x14, %g1
a00c7990:  b0 2a 80 09  andn  %o2, %o1, %i0
a00c7994:  98 16 00 01  or  %i0, %g1, %o4
a00c7998:  d8 22 e0 ac  st  %o4, [ %o3 + 0xac ]
a00c799c:  40 01 f3 18  call  0xa01445fc
a00c79a0:  d0 0a e0 1e  ldub  [ %o3 + 0x1e ], %o0
a00c79a4:  80 8a 20 ff  btst  0xff, %o0
a00c79a8:  12 bf ff b0  bne  0xa00c7868
a00c79ac:  01 00 00 00  nop
a00c79b0:  40 00 46 13  call  0xa00d91fc
a00c79b4:  90 10 20 00  clr  %o0	! 0x0
a00c79b8:  90 10 20 01  mov  1, %o0
a00c79bc:  40 01 f0 07  call  0xa01439d8
a00c79c0:  92 10 20 01  mov  1, %o1
a00c79c4:  90 10 20 00  clr  %o0
a00c79c8:  40 02 02 28  call  0xa0148268
a00c79cc:  92 10 20 01  mov  1, %o1
a00c79d0:  90 10 20 01  mov  1, %o0
a00c79d4:  40 02 02 25  call  0xa0148268
a00c79d8:  92 10 20 01  mov  1, %o1
a00c79dc:  30 bf ff a3  b,a   0xa00c7868
a00c79e0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c79e4:  10 bf ff 95  b  0xa00c7838
a00c79e8:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c79ec:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c79f0:  90 12 e1 08  or  %o3, 0x108, %o0	! 0xa802d108
a00c79f4:  92 10 20 30  mov  0x30, %o1
a00c79f8:  9a 10 20 35  mov  0x35, %o5
a00c79fc:  9e 10 20 0d  mov  0xd, %o7
a00c7a00:  a0 10 20 36  mov  0x36, %l0
a00c7a04:  94 10 20 2b  mov  0x2b, %o2
a00c7a08:  da 2a e1 08  stb  %o5, [ %o3 + 0x108 ]
a00c7a0c:  de 2a 20 05  stb  %o7, [ %o0 + 5 ]
a00c7a10:  e0 2a 20 01  stb  %l0, [ %o0 + 1 ]
a00c7a14:  d2 2a 20 03  stb  %o1, [ %o0 + 3 ]
a00c7a18:  d4 2a 20 04  stb  %o2, [ %o0 + 4 ]
a00c7a1c:  d2 2a 20 02  stb  %o1, [ %o0 + 2 ]
a00c7a20:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c7a24:  9a 16 20 98  or  %i0, 0x98, %o5	! 0xa802d098
a00c7a28:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00c7a2c:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]	! 0xa802b098
a00c7a30:  c0 2e 20 98  clrb  [ %i0 + 0x98 ]
a00c7a34:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00c7a38:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00c7a3c:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00c7a40:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00c7a44:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c7a48:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c7a4c:  10 bf ff c7  b  0xa00c7968
a00c7a50:  90 10 20 03  mov  3, %o0
a00c7a54:  81 c7 e0 08  ret
a00c7a58:  81 e8 00 00  restore
