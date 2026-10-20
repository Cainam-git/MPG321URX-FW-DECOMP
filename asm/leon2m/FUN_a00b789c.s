# leon2m FUN_a00b789c 0xa00b789c-0xa00b7944 (168 bytes)
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
