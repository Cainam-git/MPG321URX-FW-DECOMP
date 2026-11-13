# leon2m FUN_a0092444 0xa0092444-0xa0092524 (224 bytes)
a0092444:  9d e3 bf 98  save  %sp, -104, %sp
a0092448:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a009244c:  d6 04 23 ec  ld  [ %l0 + 0x3ec ], %o3	! 0xa802afec
a0092450:  94 02 ff e2  add  %o3, -30, %o2
a0092454:  40 00 5a a5  call  0xa00a8ee8
a0092458:  90 0a a0 ff  and  %o2, 0xff, %o0
a009245c:  d2 04 23 ec  ld  [ %l0 + 0x3ec ], %o1
a0092460:  90 02 7f e2  add  %o1, -30, %o0
a0092464:  90 0a 20 ff  and  %o0, 0xff, %o0
a0092468:  40 00 5e ed  call  0xa00aa01c
a009246c:  92 10 20 00  clr  %o1
a0092470:  03 19 99 99  sethi  %hi(0x66666400), %g1
a0092474:  b4 10 62 67  or  %g1, 0x267, %i2	! 0x66666667
a0092478:  d0 14 23 ee  lduh  [ %l0 + 0x3ee ], %o0
a009247c:  b0 02 3f e3  add  %o0, -29, %i0
a0092480:  80 5e 00 1a  smul  %i0, %i2, %g0
a0092484:  99 40 00 00  rd  %y, %o4
a0092488:  95 3b 20 01  sra  %o4, 1, %o2
a009248c:  97 3e 20 1f  sra  %i0, 0x1f, %o3
a0092490:  92 22 80 0b  sub  %o2, %o3, %o1
a0092494:  83 2a 60 02  sll  %o1, 2, %g1
a0092498:  b2 00 40 09  add  %g1, %o1, %i1
a009249c:  9e 26 00 19  sub  %i0, %i1, %o7
a00924a0:  9a 03 e0 1e  add  %o7, 0x1e, %o5
a00924a4:  90 0b e0 ff  and  %o7, 0xff, %o0
a00924a8:  40 00 60 1e  call  0xa00aa520
a00924ac:  da 24 23 ec  st  %o5, [ %l0 + 0x3ec ]
a00924b0:  98 0a 20 ff  and  %o0, 0xff, %o4
a00924b4:  80 a3 20 01  cmp  %o4, 1
a00924b8:  12 bf ff f1  bne  0xa009247c
a00924bc:  d0 14 23 ee  lduh  [ %l0 + 0x3ee ], %o0
a00924c0:  d2 04 23 ec  ld  [ %l0 + 0x3ec ], %o1
a00924c4:  82 02 7f e2  add  %o1, -30, %g1
a00924c8:  90 08 60 ff  and  %g1, 0xff, %o0
a00924cc:  40 00 5a d0  call  0xa00a900c
a00924d0:  92 10 20 01  mov  1, %o1
a00924d4:  f2 04 23 ec  ld  [ %l0 + 0x3ec ], %i1
a00924d8:  b0 06 7f e2  add  %i1, -30, %i0
a00924dc:  90 0e 20 ff  and  %i0, 0xff, %o0
a00924e0:  40 00 5e cf  call  0xa00aa01c
a00924e4:  92 10 20 01  mov  1, %o1
a00924e8:  da 04 23 ec  ld  [ %l0 + 0x3ec ], %o5
a00924ec:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00924f0:  d0 0b e2 ae  ldub  [ %o7 + 0x2ae ], %o0	! 0xa802d2ae
a00924f4:  40 02 c8 42  call  0xa01445fc
a00924f8:  a0 03 7f e2  add  %o5, -30, %l0
a00924fc:  b4 0a 20 ff  and  %o0, 0xff, %i2
a0092500:  b0 10 20 06  mov  6, %i0
a0092504:  80 a4 00 1a  cmp  %l0, %i2
a0092508:  02 80 00 04  be  0xa0092518
a009250c:  b2 10 20 00  clr  %i1
a0092510:  b0 10 20 06  mov  6, %i0
a0092514:  b2 10 20 01  mov  1, %i1
a0092518:  40 02 d1 ca  call  0xa0146c40
a009251c:  95 e8 20 00  restore  %g0, 0, %o2
a0092520:  01 00 00 00  nop
