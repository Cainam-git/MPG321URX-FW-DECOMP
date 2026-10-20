# leon2m FUN_a009d79c 0xa009d79c-0xa009d848 (172 bytes)
a009d79c:  9d e3 bf 98  save  %sp, -104, %sp
a009d7a0:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009d7a4:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009d7a8:  90 02 60 4f  add  %o1, 0x4f, %o0
a009d7ac:  40 00 2f 04  call  0xa00a93bc
a009d7b0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009d7b4:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009d7b8:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009d7bc:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009d7c0:  9e 02 3f 51  add  %o0, -175, %o7
a009d7c4:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009d7c8:  80 5b c0 19  smul  %o7, %i1, %g0
a009d7cc:  93 40 00 00  rd  %y, %o1
a009d7d0:  82 22 40 0a  sub  %o1, %o2, %g1
a009d7d4:  b0 00 40 01  add  %g1, %g1, %i0
a009d7d8:  98 06 00 01  add  %i0, %g1, %o4
a009d7dc:  96 23 c0 0c  sub  %o7, %o4, %o3
a009d7e0:  9a 02 e0 b1  add  %o3, 0xb1, %o5
a009d7e4:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009d7e8:  40 00 35 52  call  0xa00aad30
a009d7ec:  90 0a e0 ff  and  %o3, 0xff, %o0
a009d7f0:  94 0a 20 ff  and  %o0, 0xff, %o2
a009d7f4:  80 a2 a0 01  cmp  %o2, 1
a009d7f8:  12 bf ff f2  bne  0xa009d7c0
a009d7fc:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009d800:  de 06 a3 ec  ld  [ %i2 + 0x3ec ], %o7
a009d804:  9a 03 e0 4f  add  %o7, 0x4f, %o5
a009d808:  90 0b 60 ff  and  %o5, 0xff, %o0
a009d80c:  40 00 2f 91  call  0xa00a9650
a009d810:  92 10 20 01  mov  1, %o1
a009d814:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009d818:  96 06 7f 4f  add  %i1, -177, %o3
a009d81c:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009d820:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009d824:  b0 10 20 01  mov  1, %i0
a009d828:  80 a2 c0 19  cmp  %o3, %i1
a009d82c:  02 80 00 04  be  0xa009d83c
a009d830:  b4 10 20 00  clr  %i2
a009d834:  b0 10 20 01  mov  1, %i0
a009d838:  b4 10 20 01  mov  1, %i2
a009d83c:  40 00 2a 40  call  0xa00a813c
a009d840:  81 e8 00 00  restore
a009d844:  01 00 00 00  nop
