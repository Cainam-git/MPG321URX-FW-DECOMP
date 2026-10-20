# leon2m FUN_a011a378 0xa011a378-0xa011a554 (116 bytes)
a011a378:  80 a2 20 07  cmp  %o0, 7
a011a37c:  18 80 00 08  bgu  0xa011a39c
a011a380:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011a384:  83 2a 20 02  sll  %o0, 2, %g1
a011a388:  11 00 02 e4  sethi  %hi(0xb9000), %o0
a011a38c:  9a 12 21 7c  or  %o0, 0x17c, %o5	! 0xb917c
a011a390:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a011a394:  81 c3 00 00  jmp  %o4
a011a398:  01 00 00 00  nop
a011a39c:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a011a3a0:  92 10 62 a8  or  %g1, 0x2a8, %o1	! 0xa8027aa8
a011a3a4:  90 03 40 0d  add  %o5, %o5, %o0
a011a3a8:  da 12 40 08  lduh  [ %o1 + %o0 ], %o5
a011a3ac:  98 03 60 80  add  %o5, 0x80, %o4
a011a3b0:  97 2b 20 02  sll  %o4, 2, %o3
a011a3b4:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a011a3b8:  90 12 c0 0c  or  %o3, %o4, %o0
a011a3bc:  c2 02 00 00  ld  [ %o0 ], %g1
a011a3c0:  92 03 60 a5  add  %o5, 0xa5, %o1
a011a3c4:  82 08 60 e1  and  %g1, 0xe1, %g1
a011a3c8:  9b 2a 60 02  sll  %o1, 2, %o5
a011a3cc:  c2 22 00 00  st  %g1, [ %o0 ]
a011a3d0:  9a 13 40 0c  or  %o5, %o4, %o5
a011a3d4:  d2 03 40 00  ld  [ %o5 ], %o1
a011a3d8:  10 80 00 5c  b  0xa011a548
a011a3dc:  82 0a 60 0f  and  %o1, 0xf, %g1
a011a3e0:  82 0a 60 ff  and  %o1, 0xff, %g1
a011a3e4:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a011a3e8:  90 12 e2 a8  or  %o3, 0x2a8, %o0	! 0xa8027aa8
a011a3ec:  98 00 40 01  add  %g1, %g1, %o4
a011a3f0:  da 12 00 0c  lduh  [ %o0 + %o4 ], %o5
a011a3f4:  82 03 60 a5  add  %o5, 0xa5, %g1
a011a3f8:  97 28 60 02  sll  %g1, 2, %o3
a011a3fc:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a011a400:  9a 12 c0 09  or  %o3, %o1, %o5
a011a404:  d0 03 40 00  ld  [ %o5 ], %o0
a011a408:  10 80 00 50  b  0xa011a548
a011a40c:  82 0a 20 7f  and  %o0, 0x7f, %g1
a011a410:  98 0a 60 ff  and  %o1, 0xff, %o4
a011a414:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a011a418:  92 12 e2 a8  or  %o3, 0x2a8, %o1	! 0xa8027aa8
a011a41c:  90 03 00 0c  add  %o4, %o4, %o0
a011a420:  da 12 40 08  lduh  [ %o1 + %o0 ], %o5
a011a424:  82 03 60 80  add  %o5, 0x80, %g1
a011a428:  97 28 60 02  sll  %g1, 2, %o3
a011a42c:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a011a430:  9a 12 c0 0c  or  %o3, %o4, %o5
a011a434:  d2 03 40 00  ld  [ %o5 ], %o1
a011a438:  10 80 00 44  b  0xa011a548
a011a43c:  82 0a 60 fd  and  %o1, 0xfd, %g1
a011a440:  90 0a 60 ff  and  %o1, 0xff, %o0
a011a444:  1b 2a 00 9e  sethi  %hi(0xa8027800), %o5
a011a448:  82 13 62 a8  or  %o5, 0x2a8, %g1	! 0xa8027aa8
a011a44c:  98 02 00 08  add  %o0, %o0, %o4
a011a450:  d6 10 40 0c  lduh  [ %g1 + %o4 ], %o3
a011a454:  92 02 e0 80  add  %o3, 0x80, %o1
a011a458:  9b 2a 60 02  sll  %o1, 2, %o5
a011a45c:  11 33 c0 00  sethi  %hi(0xcf000000), %o0
a011a460:  9a 13 40 08  or  %o5, %o0, %o5
a011a464:  c2 03 40 00  ld  [ %o5 ], %g1
a011a468:  10 80 00 38  b  0xa011a548
a011a46c:  82 08 60 fb  and  %g1, 0xfb, %g1
a011a470:  98 0a 60 ff  and  %o1, 0xff, %o4
a011a474:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a011a478:  92 12 e2 a8  or  %o3, 0x2a8, %o1	! 0xa8027aa8
a011a47c:  90 03 00 0c  add  %o4, %o4, %o0
a011a480:  da 12 40 08  lduh  [ %o1 + %o0 ], %o5
a011a484:  82 03 60 80  add  %o5, 0x80, %g1
a011a488:  97 28 60 02  sll  %g1, 2, %o3
a011a48c:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a011a490:  9a 12 c0 0c  or  %o3, %o4, %o5
a011a494:  d2 03 40 00  ld  [ %o5 ], %o1
a011a498:  10 80 00 2c  b  0xa011a548
a011a49c:  82 0a 60 f7  and  %o1, 0xf7, %g1
a011a4a0:  96 0a 60 ff  and  %o1, 0xff, %o3
a011a4a4:  13 2a 00 9e  sethi  %hi(0xa8027800), %o1
a011a4a8:  90 02 c0 0b  add  %o3, %o3, %o0
a011a4ac:  82 12 62 a8  or  %o1, 0x2a8, %g1
a011a4b0:  da 10 40 08  lduh  [ %g1 + %o0 ], %o5
a011a4b4:  9a 03 60 80  add  %o5, 0x80, %o5
a011a4b8:  9b 2b 60 02  sll  %o5, 2, %o5
a011a4bc:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a011a4c0:  9a 13 40 0c  or  %o5, %o4, %o5
a011a4c4:  d2 03 40 00  ld  [ %o5 ], %o1
a011a4c8:  10 80 00 20  b  0xa011a548
a011a4cc:  82 0a 60 ef  and  %o1, 0xef, %g1
a011a4d0:  96 0a 60 ff  and  %o1, 0xff, %o3
a011a4d4:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a011a4d8:  98 02 c0 0b  add  %o3, %o3, %o4
a011a4dc:  90 10 62 a8  or  %g1, 0x2a8, %o0
a011a4e0:  da 12 00 0c  lduh  [ %o0 + %o4 ], %o5
a011a4e4:  10 bf ff f5  b  0xa011a4b8
a011a4e8:  9a 03 60 a5  add  %o5, 0xa5, %o5
a011a4ec:  96 0a 60 ff  and  %o1, 0xff, %o3
a011a4f0:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a011a4f4:  90 10 62 a8  or  %g1, 0x2a8, %o0	! 0xa8027aa8
a011a4f8:  98 02 c0 0b  add  %o3, %o3, %o4
a011a4fc:  da 12 00 0c  lduh  [ %o0 + %o4 ], %o5
a011a500:  92 03 60 a5  add  %o5, 0xa5, %o1
a011a504:  83 2a 60 02  sll  %o1, 2, %g1
a011a508:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a011a50c:  9a 10 40 0b  or  %g1, %o3, %o5
a011a510:  d0 03 40 00  ld  [ %o5 ], %o0
a011a514:  10 80 00 0d  b  0xa011a548
a011a518:  82 0a 20 df  and  %o0, 0xdf, %g1
a011a51c:  98 0a 60 ff  and  %o1, 0xff, %o4
a011a520:  1b 2a 00 9e  sethi  %hi(0xa8027800), %o5
a011a524:  92 03 00 0c  add  %o4, %o4, %o1
a011a528:  82 13 62 a8  or  %o5, 0x2a8, %g1
a011a52c:  d6 10 40 09  lduh  [ %g1 + %o1 ], %o3
a011a530:  90 02 e0 a5  add  %o3, 0xa5, %o0
a011a534:  9b 2a 20 02  sll  %o0, 2, %o5
a011a538:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a011a53c:  9a 13 40 0c  or  %o5, %o4, %o5
a011a540:  d2 03 40 00  ld  [ %o5 ], %o1
a011a544:  82 0a 60 bf  and  %o1, 0xbf, %g1
a011a548:  c2 23 40 00  st  %g1, [ %o5 ]
a011a54c:  81 c3 e0 08  retl
a011a550:  01 00 00 00  nop
