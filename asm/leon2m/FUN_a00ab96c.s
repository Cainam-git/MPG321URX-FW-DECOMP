# leon2m FUN_a00ab96c 0xa00ab96c-0xa00aba34 (200 bytes)
a00ab96c:  9d e3 bf 98  save  %sp, -104, %sp
a00ab970:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00ab974:  80 a0 00 19  cmp  %g0, %i1
a00ab978:  90 40 3f ff  addx  %g0, -1, %o0
a00ab97c:  82 0a 20 50  and  %o0, 0x50, %g1
a00ab980:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ab984:  98 10 00 19  mov  %i1, %o4
a00ab988:  90 10 20 2c  mov  0x2c, %o0
a00ab98c:  92 10 20 06  mov  6, %o1
a00ab990:  96 10 20 07  mov  7, %o3
a00ab994:  80 a6 20 00  cmp  %i0, 0
a00ab998:  02 80 00 24  be  0xa00aba28
a00ab99c:  b6 00 67 42  add  %g1, 0x742, %i3
a00ab9a0:  98 10 00 19  mov  %i1, %o4
a00ab9a4:  90 10 20 2c  mov  0x2c, %o0
a00ab9a8:  80 a6 20 01  cmp  %i0, 1
a00ab9ac:  02 80 00 1c  be  0xa00aba1c
a00ab9b0:  92 10 20 08  mov  8, %o1
a00ab9b4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ab9b8:  d4 0a 62 a4  ldub  [ %o1 + 0x2a4 ], %o2	! 0xa802d2a4
a00ab9bc:  98 10 00 19  mov  %i1, %o4
a00ab9c0:  90 10 20 2c  mov  0x2c, %o0
a00ab9c4:  92 10 20 0a  mov  0xa, %o1
a00ab9c8:  96 10 20 07  mov  7, %o3
a00ab9cc:  7f ff ff 09  call  0xa00ab5f0
a00ab9d0:  b2 06 00 18  add  %i0, %i0, %i1
a00ab9d4:  b2 06 60 06  add  %i1, 6, %i1
a00ab9d8:  b6 0e ef fe  and  %i3, 0xffe, %i3
a00ab9dc:  90 10 20 28  mov  0x28, %o0
a00ab9e0:  92 10 00 19  mov  %i1, %o1
a00ab9e4:  94 10 20 03  mov  3, %o2
a00ab9e8:  96 10 00 1b  mov  %i3, %o3
a00ab9ec:  40 02 6c 25  call  0xa0146a80
a00ab9f0:  98 10 20 00  clr  %o4
a00ab9f4:  90 10 20 2b  mov  0x2b, %o0
a00ab9f8:  92 10 00 19  mov  %i1, %o1
a00ab9fc:  94 10 20 01  mov  1, %o2
a00aba00:  96 10 00 1b  mov  %i3, %o3
a00aba04:  40 02 6c 1f  call  0xa0146a80
a00aba08:  98 10 20 00  clr  %o4
a00aba0c:  b0 10 20 32  mov  0x32, %i0
a00aba10:  b4 10 20 01  mov  1, %i2
a00aba14:  40 02 6c 1b  call  0xa0146a80
a00aba18:  99 e8 20 00  restore  %g0, 0, %o4
a00aba1c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00aba20:  10 bf ff eb  b  0xa00ab9cc
a00aba24:  d4 0b e2 a3  ldub  [ %o7 + 0x2a3 ], %o2	! 0xa802d2a3
a00aba28:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00aba2c:  10 bf ff e8  b  0xa00ab9cc
a00aba30:  d4 0b 62 a2  ldub  [ %o5 + 0x2a2 ], %o2	! 0xa802d2a2
