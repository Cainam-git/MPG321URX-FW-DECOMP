# leon2m FUN_a00b789c 0xa00b789c-0xa00b7a44 (184 bytes)
a00b789c:  9d e3 bf 98  save  %sp, -104, %sp
a00b78a0:  90 10 21 11  mov  0x111, %o0
a00b78a4:  40 02 3c ab  call  0xa0146b50
a00b78a8:  92 10 20 00  clr  %o1
a00b78ac:  90 10 20 00  clr  %o0
a00b78b0:  40 02 3c af  call  0xa0146b6c
a00b78b4:  92 10 20 00  clr  %o1
a00b78b8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00b78bc:  a0 10 62 90  or  %g1, 0x290, %l0	! 0xa802d290
a00b78c0:  b2 10 20 00  clr  %i1
a00b78c4:  b4 10 20 00  clr  %i2
a00b78c8:  31 00 06 4c  sethi  %hi(0x193000), %i0
a00b78cc:  83 2e a0 03  sll  %i2, 3, %g1
a00b78d0:  9e 20 40 1a  sub  %g1, %i2, %o7
a00b78d4:  9b 2b e0 02  sll  %o7, 2, %o5
a00b78d8:  96 03 40 1a  add  %o5, %i2, %o3
a00b78dc:  d8 0c 20 08  ldub  [ %l0 + 8 ], %o4
a00b78e0:  90 02 c0 0c  add  %o3, %o4, %o0
a00b78e4:  93 2a 20 10  sll  %o0, 0x10, %o1
a00b78e8:  93 32 60 10  srl  %o1, 0x10, %o1
a00b78ec:  7f ff af d6  call  0xa00a3844
a00b78f0:  90 16 23 6c  or  %i0, 0x36c, %o0
a00b78f4:  98 10 00 08  mov  %o0, %o4
a00b78f8:  94 06 80 1a  add  %i2, %i2, %o2
a00b78fc:  94 02 a0 06  add  %o2, 6, %o2
a00b7900:  90 10 20 00  clr  %o0
a00b7904:  92 10 20 2a  mov  0x2a, %o1
a00b7908:  96 10 20 01  mov  1, %o3
a00b790c:  9a 10 20 00  clr  %o5
a00b7910:  7f ff ae 25  call  0xa00a31a4
a00b7914:  b2 06 60 01  inc  %i1
a00b7918:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00b791c:  80 a6 a0 01  cmp  %i2, 1
a00b7920:  08 bf ff ec  bleu  0xa00b78d0
a00b7924:  83 2e a0 03  sll  %i2, 3, %g1
a00b7928:  f0 04 20 a8  ld  [ %l0 + 0xa8 ], %i0
a00b792c:  b3 36 20 0f  srl  %i0, 0xf, %i1
a00b7930:  b2 0e 60 01  and  %i1, 1, %i1
a00b7934:  b0 10 20 01  mov  1, %i0
a00b7938:  7f ff c2 01  call  0xa00a813c
a00b793c:  95 e8 20 01  restore  %g0, 1, %o2
a00b7940:  01 00 00 00  nop
a00b7944:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00b7948:  da 02 23 3c  ld  [ %o0 + 0x33c ], %o5	! 0xa802d33c
a00b794c:  03 00 10 00  sethi  %hi(0x400000), %g1
a00b7950:  90 10 20 05  mov  5, %o0
a00b7954:  80 8b 40 01  btst  %o5, %g1
a00b7958:  02 80 00 05  be  0xa00b796c
a00b795c:  92 10 20 01  mov  1, %o1
a00b7960:  82 13 c0 00  mov  %o7, %g1
a00b7964:  7f ff c9 73  call  0xa00a9f30
a00b7968:  9e 10 40 00  mov  %g1, %o7
a00b796c:  92 10 20 00  clr  %o1
a00b7970:  82 13 c0 00  mov  %o7, %g1
a00b7974:  7f ff c9 6f  call  0xa00a9f30
a00b7978:  9e 10 40 00  mov  %g1, %o7
a00b797c:  01 00 00 00  nop
a00b7980:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00b7984:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00b7988:  da 03 20 ac  ld  [ %o4 + 0xac ], %o5
a00b798c:  03 00 04 00  sethi  %hi(0x100000), %g1
a00b7990:  90 10 20 06  mov  6, %o0
a00b7994:  80 8b 40 01  btst  %o5, %g1
a00b7998:  02 80 00 06  be  0xa00b79b0
a00b799c:  92 10 20 00  clr  %o1
a00b79a0:  c2 0b 20 1f  ldub  [ %o4 + 0x1f ], %g1
a00b79a4:  80 a0 60 00  cmp  %g1, 0
a00b79a8:  02 80 00 05  be  0xa00b79bc
a00b79ac:  01 00 00 00  nop
a00b79b0:  82 13 c0 00  mov  %o7, %g1
a00b79b4:  7f ff c9 5f  call  0xa00a9f30
a00b79b8:  9e 10 40 00  mov  %g1, %o7
a00b79bc:  92 10 20 01  mov  1, %o1
a00b79c0:  82 13 c0 00  mov  %o7, %g1
a00b79c4:  7f ff c9 5b  call  0xa00a9f30
a00b79c8:  9e 10 40 00  mov  %g1, %o7
a00b79cc:  01 00 00 00  nop
a00b79d0:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00b79d4:  da 00 60 7c  ld  [ %g1 + 0x7c ], %o5	! 0xa802d47c
a00b79d8:  90 10 20 00  clr  %o0
a00b79dc:  80 8b 60 80  btst  0x80, %o5
a00b79e0:  02 80 00 05  be  0xa00b79f4
a00b79e4:  92 10 20 01  mov  1, %o1
a00b79e8:  82 13 c0 00  mov  %o7, %g1
a00b79ec:  7f ff c9 51  call  0xa00a9f30
a00b79f0:  9e 10 40 00  mov  %g1, %o7
a00b79f4:  92 10 20 00  clr  %o1
a00b79f8:  82 13 c0 00  mov  %o7, %g1
a00b79fc:  7f ff c9 4d  call  0xa00a9f30
a00b7a00:  9e 10 40 00  mov  %g1, %o7
a00b7a04:  01 00 00 00  nop
a00b7a08:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a00b7a0c:  da 02 20 84  ld  [ %o0 + 0x84 ], %o5	! 0xa802d484
a00b7a10:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00b7a14:  90 10 20 01  mov  1, %o0
a00b7a18:  80 8b 40 01  btst  %o5, %g1
a00b7a1c:  02 80 00 05  be  0xa00b7a30
a00b7a20:  92 10 20 01  mov  1, %o1
a00b7a24:  82 13 c0 00  mov  %o7, %g1
a00b7a28:  7f ff c9 42  call  0xa00a9f30
a00b7a2c:  9e 10 40 00  mov  %g1, %o7
a00b7a30:  92 10 20 00  clr  %o1
a00b7a34:  82 13 c0 00  mov  %o7, %g1
a00b7a38:  7f ff c9 3e  call  0xa00a9f30
a00b7a3c:  9e 10 40 00  mov  %g1, %o7
a00b7a40:  01 00 00 00  nop
