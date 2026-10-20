# leon2m FUN_a009b95c 0xa009b95c-0xa009ba34 (216 bytes)
a009b95c:  9d e3 bf 98  save  %sp, -104, %sp
a009b960:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009b964:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009b968:  90 02 60 19  add  %o1, 0x19, %o0
a009b96c:  40 00 36 94  call  0xa00a93bc
a009b970:  90 0a 20 ff  and  %o0, 0xff, %o0
a009b974:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009b978:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009b97c:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009b980:  9e 02 3f 1b  add  %o0, -229, %o7
a009b984:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009b988:  80 5b c0 19  smul  %o7, %i1, %g0
a009b98c:  93 40 00 00  rd  %y, %o1
a009b990:  82 22 40 0a  sub  %o1, %o2, %g1
a009b994:  b0 00 40 01  add  %g1, %g1, %i0
a009b998:  98 06 00 01  add  %i0, %g1, %o4
a009b99c:  96 23 c0 0c  sub  %o7, %o4, %o3
a009b9a0:  9a 02 e0 e7  add  %o3, 0xe7, %o5
a009b9a4:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009b9a8:  40 00 3c e2  call  0xa00aad30
a009b9ac:  90 0a e0 ff  and  %o3, 0xff, %o0
a009b9b0:  94 0a 20 ff  and  %o0, 0xff, %o2
a009b9b4:  80 a2 a0 01  cmp  %o2, 1
a009b9b8:  32 bf ff f2  bne,a   0xa009b980
a009b9bc:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009b9c0:  d8 06 a3 ec  ld  [ %i2 + 0x3ec ], %o4
a009b9c4:  9a 03 20 19  add  %o4, 0x19, %o5
a009b9c8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a009b9cc:  90 0b 60 ff  and  %o5, 0xff, %o0
a009b9d0:  da 2b e2 db  stb  %o5, [ %o7 + 0x2db ]
a009b9d4:  40 00 37 1f  call  0xa00a9650
a009b9d8:  92 10 20 01  mov  1, %o1
a009b9dc:  40 00 e9 34  call  0xa00d5eac
a009b9e0:  90 10 20 01  mov  1, %o0
a009b9e4:  d6 06 a3 ec  ld  [ %i2 + 0x3ec ], %o3
a009b9e8:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009b9ec:  b2 02 ff 19  add  %o3, -231, %i1
a009b9f0:  d2 0e a0 55  ldub  [ %i2 + 0x55 ], %o1
a009b9f4:  90 10 20 01  mov  1, %o0
a009b9f8:  80 a6 40 09  cmp  %i1, %o1
a009b9fc:  02 80 00 04  be  0xa009ba0c
a009ba00:  94 10 20 00  clr  %o2
a009ba04:  90 10 20 01  mov  1, %o0
a009ba08:  94 10 20 01  mov  1, %o2
a009ba0c:  40 00 31 cc  call  0xa00a813c
a009ba10:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a009ba14:  d2 0e 20 8e  ldub  [ %i0 + 0x8e ], %o1	! 0xa802b08e
a009ba18:  82 12 60 02  or  %o1, 2, %g1
a009ba1c:  c2 2e 20 8e  stb  %g1, [ %i0 + 0x8e ]
a009ba20:  b0 10 20 01  mov  1, %i0
a009ba24:  b2 10 20 00  clr  %i1
a009ba28:  40 02 bb ab  call  0xa014a8d4
a009ba2c:  95 e8 20 00  restore  %g0, 0, %o2
a009ba30:  01 00 00 00  nop
