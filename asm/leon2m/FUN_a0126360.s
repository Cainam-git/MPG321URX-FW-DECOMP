# leon2m FUN_a0126360 0xa0126360-0xa01264e8 (392 bytes)
a0126360:  9d e3 bf 90  save  %sp, -112, %sp
a0126364:  9b 2e 20 10  sll  %i0, 0x10, %o5
a0126368:  27 2a 00 b6  sethi  %hi(0xa802d800), %l3
a012636c:  83 33 60 18  srl  %o5, 0x18, %g1
a0126370:  a2 14 e0 90  or  %l3, 0x90, %l1
a0126374:  c2 2c e0 90  stb  %g1, [ %l3 + 0x90 ]
a0126378:  f0 2c 60 01  stb  %i0, [ %l1 + 1 ]
a012637c:  7f ff f9 53  call  0xa01248c8
a0126380:  a1 33 60 10  srl  %o5, 0x10, %l0
a0126384:  80 8a 20 ff  btst  0xff, %o0
a0126388:  02 80 00 56  be  0xa01264e0
a012638c:  15 00 06 90  sethi  %hi(0x1a4000), %o2
a0126390:  90 12 a3 90  or  %o2, 0x390, %o0	! 0x1a4390
a0126394:  92 10 00 10  mov  %l0, %o1
a0126398:  d6 0c 60 01  ldub  [ %l1 + 1 ], %o3
a012639c:  7f fe e3 75  call  0xa00df170
a01263a0:  d4 0c e0 90  ldub  [ %l3 + 0x90 ], %o2
a01263a4:  92 10 20 01  mov  1, %o1
a01263a8:  a4 10 20 02  mov  2, %l2
a01263ac:  d2 23 a0 60  st  %o1, [ %sp + 0x60 ]
a01263b0:  9a 10 00 11  mov  %l1, %o5
a01263b4:  92 10 20 02  mov  2, %o1
a01263b8:  94 10 20 5e  mov  0x5e, %o2
a01263bc:  96 10 20 05  mov  5, %o3
a01263c0:  98 10 20 00  clr  %o4
a01263c4:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a01263c8:  40 00 85 b6  call  0xa0147aa0
a01263cc:  90 10 20 60  mov  0x60, %o0
a01263d0:  67 fd 9b 74  call  0x4008d1a0
a01263d4:  90 10 20 32  mov  0x32, %o0
a01263d8:  2d 2a 00 b6  sethi  %hi(0xa802d800), %l6
a01263dc:  96 10 20 05  mov  5, %o3
a01263e0:  98 10 20 00  clr  %o4
a01263e4:  9a 15 a0 88  or  %l6, 0x88, %o5
a01263e8:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a01263ec:  92 10 20 02  mov  2, %o1
a01263f0:  94 10 20 5e  mov  0x5e, %o2
a01263f4:  40 00 85 bd  call  0xa0147ae8
a01263f8:  90 10 20 60  mov  0x60, %o0
a01263fc:  a0 15 a0 88  or  %l6, 0x88, %l0
a0126400:  11 00 06 90  sethi  %hi(0x1a4000), %o0
a0126404:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a0126408:  d2 0d a0 88  ldub  [ %l6 + 0x88 ], %o1
a012640c:  7f fe e3 59  call  0xa00df170
a0126410:  90 12 23 c0  or  %o0, 0x3c0, %o0
a0126414:  a4 10 00 11  mov  %l1, %l2
a0126418:  90 10 20 32  mov  0x32, %o0
a012641c:  67 fd 9b 61  call  0x4008d1a0
a0126420:  a2 10 00 10  mov  %l0, %l1
a0126424:  aa 10 00 13  mov  %l3, %l5
a0126428:  a8 10 00 16  mov  %l6, %l4
a012642c:  10 80 00 1f  b  0xa01264a8
a0126430:  a0 10 20 02  mov  2, %l0
a0126434:  de 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o7
a0126438:  80 a3 e0 09  cmp  %o7, 9
a012643c:  18 80 00 29  bgu  0xa01264e0
a0126440:  d2 0d 60 90  ldub  [ %l5 + 0x90 ], %o1
a0126444:  7f fe e3 4b  call  0xa00df170
a0126448:  d6 0d 20 88  ldub  [ %l4 + 0x88 ], %o3
a012644c:  9e 10 20 01  mov  1, %o7
a0126450:  de 23 a0 60  st  %o7, [ %sp + 0x60 ]
a0126454:  92 10 20 02  mov  2, %o1
a0126458:  94 10 20 5e  mov  0x5e, %o2
a012645c:  96 10 20 05  mov  5, %o3
a0126460:  98 10 20 00  clr  %o4
a0126464:  9a 10 00 12  mov  %l2, %o5
a0126468:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a012646c:  40 00 85 8d  call  0xa0147aa0
a0126470:  90 10 20 60  mov  0x60, %o0
a0126474:  67 fd 9b 4b  call  0x4008d1a0
a0126478:  90 10 20 32  mov  0x32, %o0
a012647c:  96 10 20 05  mov  5, %o3
a0126480:  98 10 20 00  clr  %o4
a0126484:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a0126488:  90 10 20 60  mov  0x60, %o0
a012648c:  92 10 20 02  mov  2, %o1
a0126490:  94 10 20 5e  mov  0x5e, %o2
a0126494:  40 00 85 95  call  0xa0147ae8
a0126498:  9a 10 00 11  mov  %l1, %o5
a012649c:  d8 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o4
a01264a0:  96 03 20 01  add  %o4, 1, %o3
a01264a4:  d6 2e 21 fd  stb  %o3, [ %i0 + 0x1fd ]
a01264a8:  31 00 06 90  sethi  %hi(0x1a4000), %i0
a01264ac:  da 0c a0 01  ldub  [ %l2 + 1 ], %o5
a01264b0:  c2 0c 60 01  ldub  [ %l1 + 1 ], %g1
a01264b4:  90 16 23 e8  or  %i0, 0x3e8, %o0
a01264b8:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a01264bc:  94 10 00 0d  mov  %o5, %o2
a01264c0:  80 a3 40 01  cmp  %o5, %g1
a01264c4:  12 bf ff dc  bne  0xa0126434
a01264c8:  98 10 00 01  mov  %g1, %o4
a01264cc:  d6 0c e0 90  ldub  [ %l3 + 0x90 ], %o3
a01264d0:  d2 0d a0 88  ldub  [ %l6 + 0x88 ], %o1
a01264d4:  80 a2 c0 09  cmp  %o3, %o1
a01264d8:  12 bf ff d8  bne  0xa0126438
a01264dc:  de 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o7
a01264e0:  81 c7 e0 08  ret
a01264e4:  81 e8 00 00  restore
