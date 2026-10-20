# leon2m FUN_a009b8e0 0xa009b8e0-0xa009b95c (124 bytes)
a009b8e0:  9d e3 bf 98  save  %sp, -104, %sp
a009b8e4:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a009b8e8:  a0 14 62 90  or  %l1, 0x290, %l0	! 0xa802d290
a009b8ec:  40 00 38 f7  call  0xa00a9cc8
a009b8f0:  d0 0c 21 90  ldub  [ %l0 + 0x190 ], %o0
a009b8f4:  c2 0c 21 90  ldub  [ %l0 + 0x190 ], %g1
a009b8f8:  80 a0 60 06  cmp  %g1, 6
a009b8fc:  02 80 00 16  be  0xa009b954
a009b900:  82 00 60 01  inc  %g1
a009b904:  c2 2c 21 90  stb  %g1, [ %l0 + 0x190 ]
a009b908:  a0 14 62 90  or  %l1, 0x290, %l0
a009b90c:  d0 0c 21 90  ldub  [ %l0 + 0x190 ], %o0
a009b910:  40 00 39 27  call  0xa00a9dac
a009b914:  92 10 20 01  mov  1, %o1
a009b918:  11 2a 00 97  sethi  %hi(0xa8025c00), %o0
a009b91c:  c2 0a 20 56  ldub  [ %o0 + 0x56 ], %g1	! 0xa8025c56
a009b920:  da 0c 21 90  ldub  [ %l0 + 0x190 ], %o5
a009b924:  92 10 00 01  mov  %g1, %o1
a009b928:  90 10 20 02  mov  2, %o0
a009b92c:  80 a3 40 01  cmp  %o5, %g1
a009b930:  02 80 00 05  be  0xa009b944
a009b934:  94 10 20 00  clr  %o2
a009b938:  92 10 00 01  mov  %g1, %o1
a009b93c:  90 10 20 02  mov  2, %o0
a009b940:  94 10 20 01  mov  1, %o2
a009b944:  40 00 31 fe  call  0xa00a813c
a009b948:  01 00 00 00  nop
a009b94c:  40 00 73 db  call  0xa00b88b8
a009b950:  81 e8 00 00  restore
a009b954:  10 bf ff ed  b  0xa009b908
a009b958:  c0 2c 21 90  clrb  [ %l0 + 0x190 ]
