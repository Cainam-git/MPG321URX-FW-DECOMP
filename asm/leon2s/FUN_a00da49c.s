# leon2s FUN_a00da49c 0xa00da49c-0xa00da6ac (528 bytes)
a00da49c:  9d e3 bf 98  save  %sp, -104, %sp
a00da4a0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da4a4:  a6 10 60 00  mov  %g1, %l3	! 0xa8078800
a00da4a8:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00da4ac:  aa 10 60 b0  or  %g1, 0xb0, %l5	! 0xa80760b0
a00da4b0:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a00da4b4:  d4 0c 60 32  ldub  [ %l1 + 0x32 ], %o2	! 0xa8078832
a00da4b8:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00da4bc:  99 2a a0 04  sll  %o2, 4, %o4
a00da4c0:  82 10 60 62  or  %g1, 0x62, %g1
a00da4c4:  82 03 00 01  add  %o4, %g1, %g1
a00da4c8:  da 0c c0 0a  ldub  [ %l3 + %o2 ], %o5
a00da4cc:  e8 0d 40 0a  ldub  [ %l5 + %o2 ], %l4
a00da4d0:  ee 08 40 0d  ldub  [ %g1 + %o5 ], %l7
a00da4d4:  80 a5 20 01  cmp  %l4, 1
a00da4d8:  25 2a 01 e2  sethi  %hi(0xa8078800), %l2
a00da4dc:  12 80 00 37  bne  0xa00da5b8
a00da4e0:  17 2a 01 e7  sethi  %hi(0xa8079c00), %o3
a00da4e4:  03 2a 01 e9  sethi  %hi(0xa807a400), %g1
a00da4e8:  82 10 60 f8  or  %g1, 0xf8, %g1	! 0xa807a4f8
a00da4ec:  82 03 00 01  add  %o4, %g1, %g1
a00da4f0:  f0 08 40 0d  ldub  [ %g1 + %o5 ], %i0
a00da4f4:  a0 12 e0 48  or  %o3, 0x48, %l0
a00da4f8:  82 10 20 2a  mov  0x2a, %g1
a00da4fc:  c2 2c a0 68  stb  %g1, [ %l2 + 0x68 ]
a00da500:  7f ff ff 62  call  0xa00da288
a00da504:  f0 2c 00 0a  stb  %i0, [ %l0 + %o2 ]
a00da508:  80 8a 20 ff  btst  0xff, %o0
a00da50c:  02 80 00 06  be  0xa00da524
a00da510:  80 a6 20 2a  cmp  %i0, 0x2a
a00da514:  7f ff ff 9d  call  0xa00da388
a00da518:  90 10 20 00  clr  %o0
a00da51c:  10 80 00 62  b  0xa00da6a4
a00da520:  b0 10 20 00  clr  %i0
a00da524:  08 80 00 13  bleu  0xa00da570
a00da528:  2d 2a 01 e2  sethi  %hi(0xa8078800), %l6
a00da52c:  90 10 20 01  mov  1, %o0
a00da530:  92 10 20 00  clr  %o1
a00da534:  7f ff fe 6a  call  0xa00d9edc
a00da538:  94 10 20 2b  mov  0x2b, %o2
a00da53c:  c2 0c 60 32  ldub  [ %l1 + 0x32 ], %g1
a00da540:  7f ff fe bc  call  0xa00da030
a00da544:  d0 0c 00 01  ldub  [ %l0 + %g1 ], %o0
a00da548:  d8 0c 60 32  ldub  [ %l1 + 0x32 ], %o4
a00da54c:  c2 0c a0 68  ldub  [ %l2 + 0x68 ], %g1
a00da550:  da 0c 00 0c  ldub  [ %l0 + %o4 ], %o5
a00da554:  9a 23 40 01  sub  %o5, %g1, %o5
a00da558:  96 15 a0 38  or  %l6, 0x38, %o3
a00da55c:  82 10 20 02  mov  2, %g1
a00da560:  c2 2a c0 0c  stb  %g1, [ %o3 + %o4 ]
a00da564:  da 2c 00 0c  stb  %o5, [ %l0 + %o4 ]
a00da568:  10 80 00 3a  b  0xa00da650
a00da56c:  c0 2d 40 0c  clrb  [ %l5 + %o4 ]
a00da570:  94 06 20 01  add  %i0, 1, %o2
a00da574:  94 0a a0 ff  and  %o2, 0xff, %o2
a00da578:  90 10 20 01  mov  1, %o0
a00da57c:  7f ff fe 58  call  0xa00d9edc
a00da580:  92 10 20 01  mov  1, %o1
a00da584:  c2 0c 60 32  ldub  [ %l1 + 0x32 ], %g1
a00da588:  7f ff fe aa  call  0xa00da030
a00da58c:  d0 0c 00 01  ldub  [ %l0 + %g1 ], %o0
a00da590:  da 0c 60 32  ldub  [ %l1 + 0x32 ], %o5
a00da594:  c2 0c c0 0d  ldub  [ %l3 + %o5 ], %g1
a00da598:  82 00 60 01  inc  %g1
a00da59c:  82 08 60 0f  and  %g1, 0xf, %g1
a00da5a0:  98 15 a0 38  or  %l6, 0x38, %o4
a00da5a4:  e8 2d 40 0d  stb  %l4, [ %l5 + %o5 ]
a00da5a8:  c2 2c c0 0d  stb  %g1, [ %l3 + %o5 ]
a00da5ac:  c0 2b 00 0d  clrb  [ %o4 + %o5 ]
a00da5b0:  10 80 00 28  b  0xa00da650
a00da5b4:  c0 2c 00 0d  clrb  [ %l0 + %o5 ]
a00da5b8:  b0 12 e0 48  or  %o3, 0x48, %i0
a00da5bc:  c2 0e 00 0a  ldub  [ %i0 + %o2 ], %g1
a00da5c0:  d4 0c a0 68  ldub  [ %l2 + 0x68 ], %o2
a00da5c4:  80 a2 80 01  cmp  %o2, %g1
a00da5c8:  08 80 00 16  bleu  0xa00da620
a00da5cc:  94 02 a0 01  inc  %o2
a00da5d0:  94 00 60 01  add  %g1, 1, %o2
a00da5d4:  94 0a a0 ff  and  %o2, 0xff, %o2
a00da5d8:  90 10 20 00  clr  %o0
a00da5dc:  7f ff fe 40  call  0xa00d9edc
a00da5e0:  92 10 20 01  mov  1, %o1
a00da5e4:  c2 0c 60 32  ldub  [ %l1 + 0x32 ], %g1
a00da5e8:  7f ff fe 92  call  0xa00da030
a00da5ec:  d0 0e 00 01  ldub  [ %i0 + %g1 ], %o0
a00da5f0:  d8 0c 60 32  ldub  [ %l1 + 0x32 ], %o4
a00da5f4:  c2 0c c0 0c  ldub  [ %l3 + %o4 ], %g1
a00da5f8:  82 00 60 01  inc  %g1
a00da5fc:  82 08 60 0f  and  %g1, 0xf, %g1
a00da600:  c2 2c c0 0c  stb  %g1, [ %l3 + %o4 ]
a00da604:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da608:  9a 10 20 01  mov  1, %o5
a00da60c:  82 10 60 38  or  %g1, 0x38, %g1
a00da610:  da 2d 40 0c  stb  %o5, [ %l5 + %o4 ]
a00da614:  c0 28 40 0c  clrb  [ %g1 + %o4 ]
a00da618:  10 80 00 0e  b  0xa00da650
a00da61c:  c0 2e 00 0c  clrb  [ %i0 + %o4 ]
a00da620:  94 0a a0 ff  and  %o2, 0xff, %o2
a00da624:  90 10 20 00  clr  %o0
a00da628:  7f ff fe 2d  call  0xa00d9edc
a00da62c:  92 10 20 00  clr  %o1
a00da630:  c2 0c 60 32  ldub  [ %l1 + 0x32 ], %g1
a00da634:  7f ff fe 7f  call  0xa00da030
a00da638:  d0 0e 00 01  ldub  [ %i0 + %g1 ], %o0
a00da63c:  d8 0c 60 32  ldub  [ %l1 + 0x32 ], %o4
a00da640:  c2 0e 00 0c  ldub  [ %i0 + %o4 ], %g1
a00da644:  da 0c a0 68  ldub  [ %l2 + 0x68 ], %o5
a00da648:  82 20 40 0d  sub  %g1, %o5, %g1
a00da64c:  c2 2e 00 0c  stb  %g1, [ %i0 + %o4 ]
a00da650:  80 a5 e0 00  cmp  %l7, 0
a00da654:  12 80 00 09  bne  0xa00da678
a00da658:  1b 2a 01 d8  sethi  %hi(0xa8076000), %o5
a00da65c:  c2 0c 60 32  ldub  [ %l1 + 0x32 ], %g1
a00da660:  83 28 60 02  sll  %g1, 2, %g1
a00da664:  9a 13 60 a4  or  %o5, 0xa4, %o5
a00da668:  da 03 40 01  ld  [ %o5 + %g1 ], %o5
a00da66c:  c2 03 6c cc  ld  [ %o5 + 0xccc ], %g1
a00da670:  10 80 00 08  b  0xa00da690
a00da674:  82 10 60 10  or  %g1, 0x10, %g1
a00da678:  c2 0c 60 32  ldub  [ %l1 + 0x32 ], %g1
a00da67c:  83 28 60 02  sll  %g1, 2, %g1
a00da680:  9a 13 60 a4  or  %o5, 0xa4, %o5
a00da684:  da 03 40 01  ld  [ %o5 + %g1 ], %o5
a00da688:  c2 03 6c cc  ld  [ %o5 + 0xccc ], %g1
a00da68c:  82 10 60 20  or  %g1, 0x20, %g1
a00da690:  c2 23 6c cc  st  %g1, [ %o5 + 0xccc ]
a00da694:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da698:  40 3b 8e ca  call  0xa0fbe1c0
a00da69c:  d0 08 60 32  ldub  [ %g1 + 0x32 ], %o0	! 0xa8078832
a00da6a0:  b0 10 20 01  mov  1, %i0
a00da6a4:  81 c7 e0 08  ret
a00da6a8:  81 e8 00 00  restore
