# leon2s FUN_a00da388 0xa00da388-0xa00da49c (276 bytes)
a00da388:  9d e3 bf 98  save  %sp, -104, %sp
a00da38c:  25 2a 01 e7  sethi  %hi(0xa8079c00), %l2
a00da390:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00da394:  82 14 a0 48  or  %l2, 0x48, %g1
a00da398:  da 0a e0 32  ldub  [ %o3 + 0x32 ], %o5
a00da39c:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a00da3a0:  80 a0 60 00  cmp  %g1, 0
a00da3a4:  12 80 00 0a  bne  0xa00da3cc
a00da3a8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da3ac:  98 10 60 00  mov  %g1, %o4	! 0xa8078800
a00da3b0:  c2 0b 00 0d  ldub  [ %o4 + %o5 ], %g1
a00da3b4:  80 a0 60 00  cmp  %g1, 0
a00da3b8:  32 80 00 03  bne,a   0xa00da3c4
a00da3bc:  82 00 7f ff  add  %g1, -1, %g1
a00da3c0:  82 10 20 0f  mov  0xf, %g1
a00da3c4:  c2 2b 00 0d  stb  %g1, [ %o4 + %o5 ]
a00da3c8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da3cc:  a2 10 60 00  mov  %g1, %l1	! 0xa8078800
a00da3d0:  d8 0a e0 32  ldub  [ %o3 + 0x32 ], %o4
a00da3d4:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00da3d8:  82 10 60 62  or  %g1, 0x62, %g1	! 0xa8079c62
a00da3dc:  9b 2b 20 04  sll  %o4, 4, %o5
a00da3e0:  9a 03 40 01  add  %o5, %g1, %o5
a00da3e4:  c2 0c 40 0c  ldub  [ %l1 + %o4 ], %g1
a00da3e8:  e0 0b 40 01  ldub  [ %o5 + %g1 ], %l0
a00da3ec:  80 a4 20 01  cmp  %l0, 1
a00da3f0:  12 80 00 08  bne  0xa00da410
a00da3f4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da3f8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da3fc:  40 3b 9f 1a  call  0xa0fc2064
a00da400:  e0 28 60 3d  stb  %l0, [ %g1 + 0x3d ]	! 0xa807883d
a00da404:  03 2a 01 e9  sethi  %hi(0xa807a400), %g1
a00da408:  d0 20 61 18  st  %o0, [ %g1 + 0x118 ]	! 0xa807a518
a00da40c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da410:  d2 08 60 32  ldub  [ %g1 + 0x32 ], %o1	! 0xa8078832
a00da414:  82 14 a0 48  or  %l2, 0x48, %g1
a00da418:  19 2a 01 e2  sethi  %hi(0xa8078800), %o4
a00da41c:  98 13 20 0a  or  %o4, 0xa, %o4	! 0xa807880a
a00da420:  94 02 40 09  add  %o1, %o1, %o2
a00da424:  d6 08 40 09  ldub  [ %g1 + %o1 ], %o3
a00da428:  c2 13 00 0a  lduh  [ %o4 + %o2 ], %g1
a00da42c:  82 00 40 0b  add  %g1, %o3, %g1
a00da430:  82 08 61 ff  and  %g1, 0x1ff, %g1
a00da434:  da 0c 40 09  ldub  [ %l1 + %o1 ], %o5
a00da438:  c2 33 00 0a  sth  %g1, [ %o4 + %o2 ]
a00da43c:  9a 03 60 01  inc  %o5
a00da440:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da444:  9a 0b 60 0f  and  %o5, 0xf, %o5
a00da448:  82 10 60 38  or  %g1, 0x38, %g1
a00da44c:  da 2c 40 09  stb  %o5, [ %l1 + %o1 ]
a00da450:  80 8e 20 ff  btst  0xff, %i0
a00da454:  02 80 00 10  be  0xa00da494
a00da458:  c0 28 40 09  clrb  [ %g1 + %o1 ]
a00da45c:  80 a4 20 00  cmp  %l0, 0
a00da460:  95 2a 60 02  sll  %o1, 2, %o2
a00da464:  12 80 00 07  bne  0xa00da480
a00da468:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00da46c:  82 10 60 a4  or  %g1, 0xa4, %g1	! 0xa80760a4
a00da470:  da 00 40 0a  ld  [ %g1 + %o2 ], %o5
a00da474:  c2 03 6c cc  ld  [ %o5 + 0xccc ], %g1
a00da478:  10 80 00 06  b  0xa00da490
a00da47c:  82 08 7f ef  and  %g1, -17, %g1
a00da480:  82 10 60 a4  or  %g1, 0xa4, %g1
a00da484:  da 00 40 0a  ld  [ %g1 + %o2 ], %o5
a00da488:  c2 03 6c cc  ld  [ %o5 + 0xccc ], %g1
a00da48c:  82 08 7f df  and  %g1, -33, %g1
a00da490:  c2 23 6c cc  st  %g1, [ %o5 + 0xccc ]
a00da494:  81 c7 e0 08  ret
a00da498:  81 e8 00 00  restore
