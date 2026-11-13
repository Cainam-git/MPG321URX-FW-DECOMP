# leon2m FUN_a014b3fc 0xa014b3fc-0xa014b4b4 (184 bytes)
a014b3fc:  9d e3 bf 98  save  %sp, -104, %sp
a014b400:  82 0e 20 ff  and  %i0, 0xff, %g1
a014b404:  b0 10 00 19  mov  %i1, %i0
a014b408:  80 a0 60 04  cmp  %g1, 4
a014b40c:  b8 10 20 00  clr  %i4
a014b410:  18 80 00 0a  bgu  0xa014b438
a014b414:  ba 10 20 00  clr  %i5
a014b418:  33 00 03 8d  sethi  %hi(0xe3400), %i1
a014b41c:  83 28 60 02  sll  %g1, 2, %g1
a014b420:  ba 16 60 d4  or  %i1, 0xd4, %i5
a014b424:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a014b428:  81 c7 00 00  jmp  %i4
a014b42c:  01 00 00 00  nop
a014b430:  b8 10 20 01  mov  1, %i4	! 0x1
a014b434:  ba 10 20 08  mov  8, %i5
a014b438:  b2 0f 20 ff  and  %i4, 0xff, %i1
a014b43c:  80 a6 60 00  cmp  %i1, 0
a014b440:  b6 10 20 00  clr  %i3
a014b444:  02 80 00 0d  be  0xa014b478
a014b448:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a014b44c:  b8 13 e1 a0  or  %o7, 0x1a0, %i4	! 0xa802e1a0
a014b450:  82 0f 60 ff  and  %i5, 0xff, %g1
a014b454:  b4 00 40 1c  add  %g1, %i4, %i2
a014b458:  b8 10 20 00  clr  %i4
a014b45c:  fa 0f 00 18  ldub  [ %i4 + %i0 ], %i5
a014b460:  82 06 80 1c  add  %i2, %i4, %g1
a014b464:  b6 06 e0 01  inc  %i3
a014b468:  b8 0e e0 ff  and  %i3, 0xff, %i4
a014b46c:  80 a7 00 19  cmp  %i4, %i1
a014b470:  0a bf ff fb  bcs  0xa014b45c
a014b474:  fa 28 60 22  stb  %i5, [ %g1 + 0x22 ]
a014b478:  b0 13 e1 a0  or  %o7, 0x1a0, %i0
a014b47c:  40 00 21 3d  call  0xa0153970
a014b480:  93 e8 20 00  restore  %g0, 0, %o1
a014b484:  b8 10 20 01  mov  1, %i4
a014b488:  10 bf ff ec  b  0xa014b438
a014b48c:  ba 10 20 09  mov  9, %i5
a014b490:  b8 10 20 02  mov  2, %i4
a014b494:  10 bf ff e9  b  0xa014b438
a014b498:  ba 10 20 00  clr  %i5
a014b49c:  b8 10 20 02  mov  2, %i4
a014b4a0:  10 bf ff e6  b  0xa014b438
a014b4a4:  ba 10 20 02  mov  2, %i5
a014b4a8:  b8 10 20 04  mov  4, %i4
a014b4ac:  10 bf ff e3  b  0xa014b438
a014b4b0:  ba 10 20 04  mov  4, %i5
