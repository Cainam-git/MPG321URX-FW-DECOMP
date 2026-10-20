# leon2m FUN_a0092364 0xa0092364-0xa0092444 (224 bytes)
a0092364:  9d e3 bf 98  save  %sp, -104, %sp
a0092368:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a009236c:  d6 04 23 ec  ld  [ %l0 + 0x3ec ], %o3	! 0xa802afec
a0092370:  94 02 ff e2  add  %o3, -30, %o2
a0092374:  40 00 5a dd  call  0xa00a8ee8
a0092378:  90 0a a0 ff  and  %o2, 0xff, %o0
a009237c:  d2 04 23 ec  ld  [ %l0 + 0x3ec ], %o1
a0092380:  90 02 7f e2  add  %o1, -30, %o0
a0092384:  90 0a 20 ff  and  %o0, 0xff, %o0
a0092388:  40 00 5f 25  call  0xa00aa01c
a009238c:  92 10 20 00  clr  %o1
a0092390:  03 19 99 99  sethi  %hi(0x66666400), %g1
a0092394:  b4 10 62 67  or  %g1, 0x267, %i2	! 0x66666667
a0092398:  d0 14 23 ee  lduh  [ %l0 + 0x3ee ], %o0
a009239c:  b0 02 3f e6  add  %o0, -26, %i0
a00923a0:  80 5e 00 1a  smul  %i0, %i2, %g0
a00923a4:  99 40 00 00  rd  %y, %o4
a00923a8:  95 3b 20 01  sra  %o4, 1, %o2
a00923ac:  97 3e 20 1f  sra  %i0, 0x1f, %o3
a00923b0:  92 22 80 0b  sub  %o2, %o3, %o1
a00923b4:  83 2a 60 02  sll  %o1, 2, %g1
a00923b8:  b2 00 40 09  add  %g1, %o1, %i1
a00923bc:  9e 26 00 19  sub  %i0, %i1, %o7
a00923c0:  9a 03 e0 1e  add  %o7, 0x1e, %o5
a00923c4:  90 0b e0 ff  and  %o7, 0xff, %o0
a00923c8:  40 00 60 56  call  0xa00aa520
a00923cc:  da 24 23 ec  st  %o5, [ %l0 + 0x3ec ]
a00923d0:  98 0a 20 ff  and  %o0, 0xff, %o4
a00923d4:  80 a3 20 01  cmp  %o4, 1
a00923d8:  12 bf ff f1  bne  0xa009239c
a00923dc:  d0 14 23 ee  lduh  [ %l0 + 0x3ee ], %o0
a00923e0:  d2 04 23 ec  ld  [ %l0 + 0x3ec ], %o1
a00923e4:  82 02 7f e2  add  %o1, -30, %g1
a00923e8:  90 08 60 ff  and  %g1, 0xff, %o0
a00923ec:  40 00 5b 08  call  0xa00a900c
a00923f0:  92 10 20 01  mov  1, %o1
a00923f4:  f2 04 23 ec  ld  [ %l0 + 0x3ec ], %i1
a00923f8:  b0 06 7f e2  add  %i1, -30, %i0
a00923fc:  90 0e 20 ff  and  %i0, 0xff, %o0
a0092400:  40 00 5f 07  call  0xa00aa01c
a0092404:  92 10 20 01  mov  1, %o1
a0092408:  da 04 23 ec  ld  [ %l0 + 0x3ec ], %o5
a009240c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a0092410:  d0 0b e2 ae  ldub  [ %o7 + 0x2ae ], %o0	! 0xa802d2ae
a0092414:  40 02 c8 7a  call  0xa01445fc
a0092418:  a0 03 7f e2  add  %o5, -30, %l0
a009241c:  b4 0a 20 ff  and  %o0, 0xff, %i2
a0092420:  b0 10 20 06  mov  6, %i0
a0092424:  80 a4 00 1a  cmp  %l0, %i2
a0092428:  02 80 00 04  be  0xa0092438
a009242c:  b2 10 20 00  clr  %i1
a0092430:  b0 10 20 06  mov  6, %i0
a0092434:  b2 10 20 01  mov  1, %i1
a0092438:  40 02 d2 02  call  0xa0146c40
a009243c:  95 e8 20 00  restore  %g0, 0, %o2
a0092440:  01 00 00 00  nop
