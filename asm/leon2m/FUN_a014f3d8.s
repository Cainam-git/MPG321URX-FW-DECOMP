# leon2m FUN_a014f3d8 0xa014f3d8-0xa014f620 (584 bytes)
a014f3d8:  9d e3 bf 90  save  %sp, -112, %sp
a014f3dc:  27 2a 00 b3  sethi  %hi(0xa802cc00), %l3
a014f3e0:  98 10 20 00  clr  %o4
a014f3e4:  9a 10 20 00  clr  %o5
a014f3e8:  94 0e 20 ff  and  %i0, 0xff, %o2
a014f3ec:  d6 14 e0 80  lduh  [ %l3 + 0x80 ], %o3
a014f3f0:  93 2b 60 02  sll  %o5, 2, %o1
a014f3f4:  91 3a c0 09  sra  %o3, %o1, %o0
a014f3f8:  82 0a 20 0f  and  %o0, 0xf, %g1
a014f3fc:  80 a0 40 0a  cmp  %g1, %o2
a014f400:  02 80 00 06  be  0xa014f418
a014f404:  98 03 20 01  inc  %o4
a014f408:  9a 0b 20 ff  and  %o4, 0xff, %o5
a014f40c:  80 a3 60 03  cmp  %o5, 3
a014f410:  08 bf ff f9  bleu  0xa014f3f4
a014f414:  93 2b 60 02  sll  %o5, 2, %o1
a014f418:  80 a3 60 03  cmp  %o5, 3
a014f41c:  08 80 00 5c  bleu  0xa014f58c
a014f420:  a0 0e 20 ff  and  %i0, 0xff, %l0
a014f424:  94 10 20 01  mov  1, %o2
a014f428:  d4 2f bf f0  stb  %o2, [ %fp + -16 ]
a014f42c:  9a 10 20 03  mov  3, %o5
a014f430:  da 2f bf f1  stb  %o5, [ %fp + -15 ]
a014f434:  a0 10 20 04  mov  4, %l0
a014f438:  98 10 20 00  clr  %o4
a014f43c:  96 10 20 00  clr  %o3
a014f440:  92 07 bf f8  add  %fp, -8, %o1
a014f444:  d4 14 e0 80  lduh  [ %l3 + 0x80 ], %o2
a014f448:  a8 02 40 0b  add  %o1, %o3, %l4
a014f44c:  e4 0d 3f f8  ldub  [ %l4 + -8 ], %l2
a014f450:  a3 2c a0 02  sll  %l2, 2, %l1
a014f454:  9f 3a 80 11  sra  %o2, %l1, %o7
a014f458:  80 8b e0 0f  btst  0xf, %o7
a014f45c:  02 80 00 5b  be  0xa014f5c8
a014f460:  98 03 20 01  inc  %o4
a014f464:  96 0b 20 ff  and  %o4, 0xff, %o3
a014f468:  80 a2 e0 01  cmp  %o3, 1
a014f46c:  08 bf ff f8  bleu  0xa014f44c
a014f470:  a8 02 40 0b  add  %o1, %o3, %l4
a014f474:  a0 0c 20 ff  and  %l0, 0xff, %l0
a014f478:  17 00 06 9c  sethi  %hi(0x1a7000), %o3
a014f47c:  90 12 e3 28  or  %o3, 0x328, %o0	! 0x1a7328
a014f480:  7f fe 3f 3c  call  0xa00df170
a014f484:  92 10 00 10  mov  %l0, %o1
a014f488:  80 a4 20 03  cmp  %l0, 3
a014f48c:  28 80 00 3e  bleu,a   0xa014f584
a014f490:  a0 0e 20 ff  and  %i0, 0xff, %l0
a014f494:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a014f498:  a2 10 60 80  or  %g1, 0x80, %l1	! 0xa802a480
a014f49c:  a4 10 20 00  clr  %l2
a014f4a0:  90 10 20 00  clr  %o0
a014f4a4:  a0 10 20 01  mov  1, %l0
a014f4a8:  d4 14 e0 80  lduh  [ %l3 + 0x80 ], %o2
a014f4ac:  9b 2a 20 02  sll  %o0, 2, %o5
a014f4b0:  93 3a 80 0d  sra  %o2, %o5, %o1
a014f4b4:  9e 0a 60 0f  and  %o1, 0xf, %o7
a014f4b8:  92 10 20 00  clr  %o1
a014f4bc:  98 10 20 00  clr  %o4
a014f4c0:  9a 10 20 00  clr  %o5
a014f4c4:  10 80 00 05  b  0xa014f4d8
a014f4c8:  94 0b e0 ff  and  %o7, 0xff, %o2
a014f4cc:  80 a3 60 08  cmp  %o5, 8
a014f4d0:  38 80 00 0c  bgu,a   0xa014f500
a014f4d4:  99 2a 60 10  sll  %o1, 0x10, %o4
a014f4d8:  e8 0c 40 0d  ldub  [ %l1 + %o5 ], %l4
a014f4dc:  98 03 20 01  inc  %o4
a014f4e0:  97 2c 00 0d  sll  %l0, %o5, %o3
a014f4e4:  80 a2 80 14  cmp  %o2, %l4
a014f4e8:  12 bf ff f9  bne  0xa014f4cc
a014f4ec:  9a 0b 20 ff  and  %o4, 0xff, %o5
a014f4f0:  80 a3 60 08  cmp  %o5, 8
a014f4f4:  08 bf ff f9  bleu  0xa014f4d8
a014f4f8:  92 12 c0 09  or  %o3, %o1, %o1
a014f4fc:  99 2a 60 10  sll  %o1, 0x10, %o4
a014f500:  80 a3 20 00  cmp  %o4, 0
a014f504:  32 80 00 1b  bne,a   0xa014f570
a014f508:  a4 04 a0 01  inc  %l2
a014f50c:  95 2a 20 02  sll  %o0, 2, %o2
a014f510:  92 10 20 0f  mov  0xf, %o1
a014f514:  97 2a 40 0a  sll  %o1, %o2, %o3
a014f518:  c2 14 e0 80  lduh  [ %l3 + 0x80 ], %g1
a014f51c:  90 28 40 0b  andn  %g1, %o3, %o0
a014f520:  29 2a 00 b3  sethi  %hi(0xa802cc00), %l4
a014f524:  d0 34 e0 80  sth  %o0, [ %l3 + 0x80 ]
a014f528:  90 0b e0 ff  and  %o7, 0xff, %o0
a014f52c:  94 10 20 00  clr  %o2
a014f530:  98 10 20 00  clr  %o4
a014f534:  d2 15 20 82  lduh  [ %l4 + 0x82 ], %o1
a014f538:  9f 2a 60 10  sll  %o1, 0x10, %o7
a014f53c:  97 2b 20 02  sll  %o4, 2, %o3
a014f540:  9b 33 e0 10  srl  %o7, 0x10, %o5
a014f544:  83 3b 40 0b  sra  %o5, %o3, %g1
a014f548:  94 02 a0 01  inc  %o2
a014f54c:  9e 08 60 0f  and  %g1, 0xf, %o7
a014f550:  80 a3 c0 08  cmp  %o7, %o0
a014f554:  02 80 00 23  be  0xa014f5e0
a014f558:  98 0a a0 ff  and  %o2, 0xff, %o4
a014f55c:  80 a3 20 03  cmp  %o4, 3
a014f560:  08 bf ff f7  bleu  0xa014f53c
a014f564:  9f 2a 60 10  sll  %o1, 0x10, %o7
a014f568:  d2 35 20 82  sth  %o1, [ %l4 + 0x82 ]
a014f56c:  a4 04 a0 01  inc  %l2
a014f570:  90 0c a0 ff  and  %l2, 0xff, %o0
a014f574:  80 a2 20 03  cmp  %o0, 3
a014f578:  08 bf ff cd  bleu  0xa014f4ac
a014f57c:  d4 14 e0 80  lduh  [ %l3 + 0x80 ], %o2
a014f580:  a0 0e 20 ff  and  %i0, 0xff, %l0
a014f584:  7f ff fd 9d  call  0xa014ebf8
a014f588:  90 10 00 10  mov  %l0, %o0
a014f58c:  d8 14 e0 80  lduh  [ %l3 + 0x80 ], %o4
a014f590:  9a 10 20 00  clr  %o5
a014f594:  94 10 20 00  clr  %o2
a014f598:  a3 2a a0 02  sll  %o2, 2, %l1
a014f59c:  b1 3b 00 11  sra  %o4, %l1, %i0
a014f5a0:  a6 0e 20 0f  and  %i0, 0xf, %l3
a014f5a4:  80 a4 c0 10  cmp  %l3, %l0
a014f5a8:  02 80 00 17  be  0xa014f604
a014f5ac:  9a 03 60 01  inc  %o5
a014f5b0:  94 0b 60 ff  and  %o5, 0xff, %o2
a014f5b4:  80 a2 a0 03  cmp  %o2, 3
a014f5b8:  08 bf ff f9  bleu  0xa014f59c
a014f5bc:  a3 2a a0 02  sll  %o2, 2, %l1
a014f5c0:  10 80 00 12  b  0xa014f608
a014f5c4:  90 10 00 10  mov  %l0, %o0
a014f5c8:  80 a2 e0 01  cmp  %o3, 1
a014f5cc:  38 bf ff ab  bgu,a   0xa014f478
a014f5d0:  a0 0c 20 ff  and  %l0, 0xff, %l0
a014f5d4:  98 02 40 0b  add  %o1, %o3, %o4
a014f5d8:  10 bf ff a7  b  0xa014f474
a014f5dc:  e0 0b 3f f8  ldub  [ %o4 + -8 ], %l0
a014f5e0:  82 10 20 10  mov  0x10, %g1
a014f5e4:  94 20 40 0b  sub  %g1, %o3, %o2
a014f5e8:  9e 02 e0 04  add  %o3, 4, %o7
a014f5ec:  91 3b 40 0f  sra  %o5, %o7, %o0
a014f5f0:  93 2b 40 0a  sll  %o5, %o2, %o1
a014f5f4:  9b 3a 40 0a  sra  %o1, %o2, %o5
a014f5f8:  99 2a 00 0b  sll  %o0, %o3, %o4
a014f5fc:  10 bf ff db  b  0xa014f568
a014f600:  92 13 40 0c  or  %o5, %o4, %o1
a014f604:  90 10 00 10  mov  %l0, %o0
a014f608:  92 0e 60 ff  and  %i1, 0xff, %o1
a014f60c:  7f ff a4 0c  call  0xa013863c
a014f610:  96 10 20 01  mov  1, %o3
a014f614:  01 00 00 00  nop
a014f618:  81 c7 e0 08  ret
a014f61c:  81 e8 00 00  restore
