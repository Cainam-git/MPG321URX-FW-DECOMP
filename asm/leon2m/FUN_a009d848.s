# leon2m FUN_a009d848 0xa009d848-0xa009d8f4 (172 bytes)
a009d848:  9d e3 bf 98  save  %sp, -104, %sp
a009d84c:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009d850:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009d854:  90 02 60 4f  add  %o1, 0x4f, %o0
a009d858:  40 00 2e d9  call  0xa00a93bc
a009d85c:  90 0a 20 ff  and  %o0, 0xff, %o0
a009d860:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009d864:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009d868:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009d86c:  9e 02 3f 50  add  %o0, -176, %o7
a009d870:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009d874:  80 5b c0 19  smul  %o7, %i1, %g0
a009d878:  93 40 00 00  rd  %y, %o1
a009d87c:  82 22 40 0a  sub  %o1, %o2, %g1
a009d880:  b0 00 40 01  add  %g1, %g1, %i0
a009d884:  98 06 00 01  add  %i0, %g1, %o4
a009d888:  96 23 c0 0c  sub  %o7, %o4, %o3
a009d88c:  9a 02 e0 b1  add  %o3, 0xb1, %o5
a009d890:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009d894:  40 00 35 27  call  0xa00aad30
a009d898:  90 0a e0 ff  and  %o3, 0xff, %o0
a009d89c:  94 0a 20 ff  and  %o0, 0xff, %o2
a009d8a0:  80 a2 a0 01  cmp  %o2, 1
a009d8a4:  12 bf ff f2  bne  0xa009d86c
a009d8a8:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009d8ac:  de 06 a3 ec  ld  [ %i2 + 0x3ec ], %o7
a009d8b0:  9a 03 e0 4f  add  %o7, 0x4f, %o5
a009d8b4:  90 0b 60 ff  and  %o5, 0xff, %o0
a009d8b8:  40 00 2f 66  call  0xa00a9650
a009d8bc:  92 10 20 01  mov  1, %o1
a009d8c0:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009d8c4:  96 06 7f 4f  add  %i1, -177, %o3
a009d8c8:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009d8cc:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009d8d0:  b0 10 20 01  mov  1, %i0
a009d8d4:  80 a2 c0 19  cmp  %o3, %i1
a009d8d8:  02 80 00 04  be  0xa009d8e8
a009d8dc:  b4 10 20 00  clr  %i2
a009d8e0:  b0 10 20 01  mov  1, %i0
a009d8e4:  b4 10 20 01  mov  1, %i2
a009d8e8:  40 00 2a 15  call  0xa00a813c
a009d8ec:  81 e8 00 00  restore
a009d8f0:  01 00 00 00  nop
