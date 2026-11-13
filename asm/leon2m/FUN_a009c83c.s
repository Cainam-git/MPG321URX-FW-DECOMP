# leon2m FUN_a009c83c 0xa009c83c-0xa009c8ec (176 bytes)
a009c83c:  9d e3 bf 98  save  %sp, -104, %sp
a009c840:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009c844:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1	! 0xa802afec
a009c848:  90 00 7f 94  add  %g1, -108, %o0
a009c84c:  40 00 32 dc  call  0xa00a93bc
a009c850:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c854:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009c858:  96 02 3f 97  add  %o0, -105, %o3
a009c85c:  b3 3a e0 1f  sra  %o3, 0x1f, %i1
a009c860:  b1 36 60 1e  srl  %i1, 0x1e, %i0
a009c864:  9e 02 c0 18  add  %o3, %i0, %o7
a009c868:  98 0b ff fc  and  %o7, -4, %o4
a009c86c:  94 22 c0 0c  sub  %o3, %o4, %o2
a009c870:  9a 02 a0 6c  add  %o2, 0x6c, %o5
a009c874:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009c878:  40 00 39 2e  call  0xa00aad30
a009c87c:  90 0a a0 ff  and  %o2, 0xff, %o0
a009c880:  92 0a 20 ff  and  %o0, 0xff, %o1
a009c884:  80 a2 60 01  cmp  %o1, 1
a009c888:  12 bf ff f4  bne  0xa009c858
a009c88c:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009c890:  de 06 a3 ec  ld  [ %i2 + 0x3ec ], %o7
a009c894:  98 03 ff 94  add  %o7, -108, %o4
a009c898:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a009c89c:  40 00 f3 b2  call  0xa00d9764
a009c8a0:  d8 2a e2 a1  stb  %o4, [ %o3 + 0x2a1 ]	! 0xa802d2a1
a009c8a4:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5
a009c8a8:  94 03 7f 94  add  %o5, -108, %o2
a009c8ac:  92 10 20 01  mov  1, %o1
a009c8b0:  40 00 33 68  call  0xa00a9650
a009c8b4:  90 0a a0 ff  and  %o2, 0xff, %o0
a009c8b8:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1
a009c8bc:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009c8c0:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009c8c4:  82 02 7f 94  add  %o1, -108, %g1
a009c8c8:  b0 10 20 01  mov  1, %i0
a009c8cc:  80 a0 40 19  cmp  %g1, %i1
a009c8d0:  02 80 00 04  be  0xa009c8e0
a009c8d4:  b4 10 20 00  clr  %i2
a009c8d8:  b0 10 20 01  mov  1, %i0
a009c8dc:  b4 10 20 01  mov  1, %i2
a009c8e0:  40 00 2e 17  call  0xa00a813c
a009c8e4:  81 e8 00 00  restore
a009c8e8:  01 00 00 00  nop
