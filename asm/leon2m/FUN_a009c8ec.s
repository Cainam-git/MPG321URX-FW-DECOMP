# leon2m FUN_a009c8ec 0xa009c8ec-0xa009c99c (176 bytes)
a009c8ec:  9d e3 bf 98  save  %sp, -104, %sp
a009c8f0:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009c8f4:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1	! 0xa802afec
a009c8f8:  90 00 7f 94  add  %g1, -108, %o0
a009c8fc:  40 00 32 b0  call  0xa00a93bc
a009c900:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c904:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009c908:  96 02 3f 95  add  %o0, -107, %o3
a009c90c:  b3 3a e0 1f  sra  %o3, 0x1f, %i1
a009c910:  b1 36 60 1e  srl  %i1, 0x1e, %i0
a009c914:  9e 02 c0 18  add  %o3, %i0, %o7
a009c918:  98 0b ff fc  and  %o7, -4, %o4
a009c91c:  94 22 c0 0c  sub  %o3, %o4, %o2
a009c920:  9a 02 a0 6c  add  %o2, 0x6c, %o5
a009c924:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009c928:  40 00 39 02  call  0xa00aad30
a009c92c:  90 0a a0 ff  and  %o2, 0xff, %o0
a009c930:  92 0a 20 ff  and  %o0, 0xff, %o1
a009c934:  80 a2 60 01  cmp  %o1, 1
a009c938:  12 bf ff f4  bne  0xa009c908
a009c93c:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009c940:  de 06 a3 ec  ld  [ %i2 + 0x3ec ], %o7
a009c944:  98 03 ff 94  add  %o7, -108, %o4
a009c948:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a009c94c:  40 00 f3 86  call  0xa00d9764
a009c950:  d8 2a e2 a1  stb  %o4, [ %o3 + 0x2a1 ]	! 0xa802d2a1
a009c954:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5
a009c958:  94 03 7f 94  add  %o5, -108, %o2
a009c95c:  92 10 20 01  mov  1, %o1
a009c960:  40 00 33 3c  call  0xa00a9650
a009c964:  90 0a a0 ff  and  %o2, 0xff, %o0
a009c968:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1
a009c96c:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009c970:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009c974:  82 02 7f 94  add  %o1, -108, %g1
a009c978:  b0 10 20 01  mov  1, %i0
a009c97c:  80 a0 40 19  cmp  %g1, %i1
a009c980:  02 80 00 04  be  0xa009c990
a009c984:  b4 10 20 00  clr  %i2
a009c988:  b0 10 20 01  mov  1, %i0
a009c98c:  b4 10 20 01  mov  1, %i2
a009c990:  40 00 2d eb  call  0xa00a813c
a009c994:  81 e8 00 00  restore
a009c998:  01 00 00 00  nop
