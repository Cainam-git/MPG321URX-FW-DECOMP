# leon2s FUN_a00cb3e8 0xa00cb3e8-0xa00cb56c (388 bytes)
a00cb3e8:  9d e3 bf 98  save  %sp, -104, %sp
a00cb3ec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cb3f0:  82 06 00 18  add  %i0, %i0, %g1
a00cb3f4:  82 00 40 18  add  %g1, %i0, %g1
a00cb3f8:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a00cb3fc:  99 28 60 03  sll  %g1, 3, %o4
a00cb400:  96 14 e3 b0  or  %l3, 0x3b0, %o3
a00cb404:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cb408:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cb40c:  82 2b 40 01  andn  %o5, %g1, %g1
a00cb410:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cb414:  82 10 40 0d  or  %g1, %o5, %g1
a00cb418:  15 2a 01 f5  sethi  %hi(0xa807d400), %o2
a00cb41c:  da 0a a2 36  ldub  [ %o2 + 0x236 ], %o5	! 0xa807d636
a00cb420:  80 a3 40 18  cmp  %o5, %i0
a00cb424:  12 80 00 09  bne  0xa00cb448
a00cb428:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cb42c:  82 10 3f ff  mov  -1, %g1
a00cb430:  9a 03 00 0b  add  %o4, %o3, %o5
a00cb434:  c2 2a a2 36  stb  %g1, [ %o2 + 0x236 ]
a00cb438:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00cb43c:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00cb440:  40 3a df 01  call  0xa0f83044
a00cb444:  90 12 21 58  or  %o0, 0x158, %o0
a00cb448:  25 2a 01 f3  sethi  %hi(0xa807cc00), %l2
a00cb44c:  9a 14 a2 50  or  %l2, 0x250, %o5	! 0xa807ce50
a00cb450:  82 10 20 08  mov  8, %g1
a00cb454:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00cb458:  82 10 20 09  mov  9, %g1
a00cb45c:  c2 2c a2 50  stb  %g1, [ %l2 + 0x250 ]
a00cb460:  82 10 20 01  mov  1, %g1
a00cb464:  c2 2b 60 01  stb  %g1, [ %o5 + 1 ]
a00cb468:  82 10 20 02  mov  2, %g1
a00cb46c:  c2 2b 60 02  stb  %g1, [ %o5 + 2 ]
a00cb470:  82 10 20 03  mov  3, %g1
a00cb474:  c2 2b 60 03  stb  %g1, [ %o5 + 3 ]
a00cb478:  82 10 20 04  mov  4, %g1
a00cb47c:  c2 2b 60 04  stb  %g1, [ %o5 + 4 ]
a00cb480:  82 10 20 05  mov  5, %g1
a00cb484:  c2 2b 60 05  stb  %g1, [ %o5 + 5 ]
a00cb488:  82 10 20 06  mov  6, %g1
a00cb48c:  c2 2b 60 06  stb  %g1, [ %o5 + 6 ]
a00cb490:  82 10 20 07  mov  7, %g1
a00cb494:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00cb498:  90 10 00 18  mov  %i0, %o0
a00cb49c:  92 10 20 08  mov  8, %o1
a00cb4a0:  7f ff f4 d2  call  0xa00c87e8
a00cb4a4:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cb4a8:  a0 10 20 00  clr  %l0
a00cb4ac:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cb4b0:  a2 14 a2 50  or  %l2, 0x250, %l1
a00cb4b4:  82 00 40 11  add  %g1, %l1, %g1
a00cb4b8:  d4 08 60 01  ldub  [ %g1 + 1 ], %o2
a00cb4bc:  90 10 00 18  mov  %i0, %o0
a00cb4c0:  7f ff f0 65  call  0xa00c7654
a00cb4c4:  92 10 20 01  mov  1, %o1
a00cb4c8:  a0 04 20 01  inc  %l0
a00cb4cc:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cb4d0:  80 a0 60 07  cmp  %g1, 7
a00cb4d4:  28 bf ff f8  bleu,a   0xa00cb4b4
a00cb4d8:  a2 14 a2 50  or  %l2, 0x250, %l1
a00cb4dc:  96 10 20 60  mov  0x60, %o3
a00cb4e0:  98 10 20 09  mov  9, %o4
a00cb4e4:  92 10 00 11  mov  %l1, %o1
a00cb4e8:  94 10 20 74  mov  0x74, %o2
a00cb4ec:  7f ff f3 01  call  0xa00c80f0
a00cb4f0:  90 10 00 18  mov  %i0, %o0
a00cb4f4:  90 10 00 18  mov  %i0, %o0
a00cb4f8:  92 10 20 05  mov  5, %o1
a00cb4fc:  7f ff f0 56  call  0xa00c7654
a00cb500:  94 10 20 03  mov  3, %o2
a00cb504:  90 10 00 18  mov  %i0, %o0
a00cb508:  92 10 20 06  mov  6, %o1
a00cb50c:  7f ff f0 52  call  0xa00c7654
a00cb510:  94 10 20 d0  mov  0xd0, %o2
a00cb514:  10 80 00 0e  b  0xa00cb54c
a00cb518:  a0 10 3f ff  mov  -1, %l0
a00cb51c:  80 8c 20 ff  btst  0xff, %l0
a00cb520:  12 80 00 0c  bne  0xa00cb550
a00cb524:  90 10 00 18  mov  %i0, %o0
a00cb528:  9a 06 00 18  add  %i0, %i0, %o5
a00cb52c:  9a 03 40 18  add  %o5, %i0, %o5
a00cb530:  96 14 e3 b0  or  %l3, 0x3b0, %o3
a00cb534:  9b 2b 60 03  sll  %o5, 3, %o5
a00cb538:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00cb53c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cb540:  82 2b 00 01  andn  %o4, %g1, %g1
a00cb544:  10 80 00 08  b  0xa00cb564
a00cb548:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cb54c:  90 10 00 18  mov  %i0, %o0
a00cb550:  7f ff f0 88  call  0xa00c7770
a00cb554:  92 10 20 06  mov  6, %o1
a00cb558:  80 8a 20 80  btst  0x80, %o0
a00cb55c:  12 bf ff f0  bne  0xa00cb51c
a00cb560:  a0 04 3f ff  add  %l0, -1, %l0
a00cb564:  81 c7 e0 08  ret
a00cb568:  81 e8 00 00  restore
