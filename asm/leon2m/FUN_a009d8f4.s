# leon2m FUN_a009d8f4 0xa009d8f4-0xa009d9b0 (188 bytes)
a009d8f4:  9d e3 bf 98  save  %sp, -104, %sp
a009d8f8:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009d8fc:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1	! 0xa802afec
a009d900:  90 00 60 4c  add  %g1, 0x4c, %o0
a009d904:  40 00 2e ae  call  0xa00a93bc
a009d908:  90 0a 20 ff  and  %o0, 0xff, %o0
a009d90c:  f2 16 a3 ee  lduh  [ %i2 + 0x3ee ], %i1
a009d910:  96 06 7f 4d  add  %i1, -179, %o3
a009d914:  b1 32 e0 1f  srl  %o3, 0x1f, %i0
a009d918:  9e 02 c0 18  add  %o3, %i0, %o7
a009d91c:  98 0b ff fe  and  %o7, -2, %o4
a009d920:  94 22 c0 0c  sub  %o3, %o4, %o2
a009d924:  9a 02 a0 b4  add  %o2, 0xb4, %o5
a009d928:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009d92c:  40 00 35 01  call  0xa00aad30
a009d930:  90 0a a0 ff  and  %o2, 0xff, %o0
a009d934:  92 0a 20 ff  and  %o0, 0xff, %o1
a009d938:  80 a2 60 01  cmp  %o1, 1
a009d93c:  12 bf ff f5  bne  0xa009d910
a009d940:  f2 16 a3 ee  lduh  [ %i2 + 0x3ee ], %i1
a009d944:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1
a009d948:  90 00 60 4c  add  %g1, 0x4c, %o0
a009d94c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a009d950:  92 13 22 90  or  %o4, 0x290, %o1	! 0xa802d290
a009d954:  90 0a 20 ff  and  %o0, 0xff, %o0
a009d958:  d6 02 60 a8  ld  [ %o1 + 0xa8 ], %o3
a009d95c:  b0 0a 20 01  and  %o0, 1, %i0
a009d960:  33 00 00 20  sethi  %hi(0x8000), %i1
a009d964:  9e 2a c0 19  andn  %o3, %i1, %o7
a009d968:  9b 2e 20 0f  sll  %i0, 0xf, %o5
a009d96c:  94 13 c0 0d  or  %o7, %o5, %o2
a009d970:  d4 22 60 a8  st  %o2, [ %o1 + 0xa8 ]
a009d974:  40 00 2f 37  call  0xa00a9650
a009d978:  92 10 20 01  mov  1, %o1
a009d97c:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1
a009d980:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009d984:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009d988:  90 00 7f 4c  add  %g1, -180, %o0
a009d98c:  b0 10 20 01  mov  1, %i0
a009d990:  80 a2 00 19  cmp  %o0, %i1
a009d994:  02 80 00 04  be  0xa009d9a4
a009d998:  b4 10 20 00  clr  %i2
a009d99c:  b0 10 20 01  mov  1, %i0
a009d9a0:  b4 10 20 01  mov  1, %i2
a009d9a4:  40 00 29 e6  call  0xa00a813c
a009d9a8:  81 e8 00 00  restore
a009d9ac:  01 00 00 00  nop
