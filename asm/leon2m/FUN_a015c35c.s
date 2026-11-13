# leon2m FUN_a015c35c 0xa015c35c-0xa015ca50 (1780 bytes)
a015c35c:  9d e3 bf 98  save  %sp, -104, %sp
a015c360:  82 06 60 0b  add  %i1, 0xb, %g1
a015c364:  80 a0 60 16  cmp  %g1, 0x16
a015c368:  a6 10 00 18  mov  %i0, %l3
a015c36c:  18 80 00 03  bgu  0xa015c378
a015c370:  a0 08 7f f8  and  %g1, -8, %l0
a015c374:  a0 10 20 10  mov  0x10, %l0
a015c378:  80 a4 00 19  cmp  %l0, %i1
a015c37c:  9a 40 20 00  addx  %g0, 0, %o5
a015c380:  83 34 20 1f  srl  %l0, 0x1f, %g1
a015c384:  80 90 40 0d  orcc  %g1, %o5, %g0
a015c388:  12 80 01 b0  bne  0xa015ca48
a015c38c:  b0 10 20 00  clr  %i0
a015c390:  40 00 02 31  call  0xa015cc54
a015c394:  90 10 00 13  mov  %l3, %o0
a015c398:  80 a4 21 f7  cmp  %l0, 0x1f7
a015c39c:  18 80 00 17  bgu  0xa015c3f8
a015c3a0:  99 34 20 09  srl  %l0, 9, %o4
a015c3a4:  39 2a 00 aa  sethi  %hi(0xa802a800), %i4
a015c3a8:  82 17 22 b8  or  %i4, 0x2b8, %g1	! 0xa802aab8
a015c3ac:  98 04 00 01  add  %l0, %g1, %o4
a015c3b0:  f0 03 20 0c  ld  [ %o4 + 0xc ], %i0
a015c3b4:  80 a6 00 0c  cmp  %i0, %o4
a015c3b8:  02 80 00 4e  be  0xa015c4f0
a015c3bc:  9f 34 20 03  srl  %l0, 3, %o7
a015c3c0:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a015c3c4:  94 08 7f fc  and  %g1, -4, %o2
a015c3c8:  9a 06 00 0a  add  %i0, %o2, %o5
a015c3cc:  c2 03 60 04  ld  [ %o5 + 4 ], %g1
a015c3d0:  82 10 60 01  or  %g1, 1, %g1
a015c3d4:  d0 06 20 0c  ld  [ %i0 + 0xc ], %o0
a015c3d8:  d2 06 20 08  ld  [ %i0 + 8 ], %o1
a015c3dc:  d2 22 20 08  st  %o1, [ %o0 + 8 ]
a015c3e0:  c2 23 60 04  st  %g1, [ %o5 + 4 ]
a015c3e4:  d0 22 60 0c  st  %o0, [ %o1 + 0xc ]
a015c3e8:  40 00 02 21  call  0xa015cc6c
a015c3ec:  90 10 00 13  mov  %l3, %o0
a015c3f0:  10 80 01 96  b  0xa015ca48
a015c3f4:  b0 06 20 08  add  %i0, 8, %i0
a015c3f8:  80 a3 20 00  cmp  %o4, 0
a015c3fc:  12 80 00 28  bne  0xa015c49c
a015c400:  9f 34 20 03  srl  %l0, 3, %o7
a015c404:  39 2a 00 aa  sethi  %hi(0xa802a800), %i4
a015c408:  9b 2b e0 03  sll  %o7, 3, %o5
a015c40c:  82 17 22 b8  or  %i4, 0x2b8, %g1
a015c410:  9a 03 40 01  add  %o5, %g1, %o5
a015c414:  10 80 00 0a  b  0xa015c43c
a015c418:  f0 03 60 0c  ld  [ %o5 + 0xc ], %i0
a015c41c:  94 08 7f fc  and  %g1, -4, %o2
a015c420:  96 22 80 10  sub  %o2, %l0, %o3
a015c424:  80 a2 e0 0f  cmp  %o3, 0xf
a015c428:  14 80 01 09  bg  0xa015c84c
a015c42c:  80 a2 e0 00  cmp  %o3, 0
a015c430:  36 bf ff e7  bge,a   0xa015c3cc
a015c434:  9a 06 00 0a  add  %i0, %o2, %o5
a015c438:  f0 06 20 0c  ld  [ %i0 + 0xc ], %i0
a015c43c:  80 a6 00 0d  cmp  %i0, %o5
a015c440:  32 bf ff f7  bne,a   0xa015c41c
a015c444:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a015c448:  9e 03 e0 01  inc  %o7
a015c44c:  25 2a 00 aa  sethi  %hi(0xa802a800), %l2
a015c450:  98 14 a2 c0  or  %l2, 0x2c0, %o4	! 0xa802aac0
a015c454:  f0 03 20 08  ld  [ %o4 + 8 ], %i0
a015c458:  80 a6 00 0c  cmp  %i0, %o4
a015c45c:  02 80 00 5d  be  0xa015c5d0
a015c460:  83 3b e0 1f  sra  %o7, 0x1f, %g1
a015c464:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a015c468:  94 08 7f fc  and  %g1, -4, %o2
a015c46c:  96 22 80 10  sub  %o2, %l0, %o3
a015c470:  80 a2 e0 0f  cmp  %o3, 0xf
a015c474:  14 80 00 9f  bg  0xa015c6f0
a015c478:  80 a2 e0 00  cmp  %o3, 0
a015c47c:  d8 23 20 0c  st  %o4, [ %o4 + 0xc ]
a015c480:  06 80 00 23  bl  0xa015c50c
a015c484:  d8 23 20 08  st  %o4, [ %o4 + 8 ]
a015c488:  9a 06 00 0a  add  %i0, %o2, %o5
a015c48c:  c2 03 60 04  ld  [ %o5 + 4 ], %g1
a015c490:  82 10 60 01  or  %g1, 1, %g1
a015c494:  10 bf ff d5  b  0xa015c3e8
a015c498:  c2 23 60 04  st  %g1, [ %o5 + 4 ]
a015c49c:  83 34 20 06  srl  %l0, 6, %g1
a015c4a0:  80 a3 20 04  cmp  %o4, 4
a015c4a4:  08 bf ff d8  bleu  0xa015c404
a015c4a8:  9e 00 60 38  add  %g1, 0x38, %o7
a015c4ac:  80 a3 20 14  cmp  %o4, 0x14
a015c4b0:  08 bf ff d5  bleu  0xa015c404
a015c4b4:  9e 03 20 5b  add  %o4, 0x5b, %o7
a015c4b8:  83 34 20 0c  srl  %l0, 0xc, %g1
a015c4bc:  80 a3 20 54  cmp  %o4, 0x54
a015c4c0:  08 bf ff d1  bleu  0xa015c404
a015c4c4:  9e 00 60 6e  add  %g1, 0x6e, %o7
a015c4c8:  83 34 20 0f  srl  %l0, 0xf, %g1
a015c4cc:  80 a3 21 54  cmp  %o4, 0x154
a015c4d0:  08 bf ff cd  bleu  0xa015c404
a015c4d4:  9e 00 60 77  add  %g1, 0x77, %o7
a015c4d8:  83 34 20 12  srl  %l0, 0x12, %g1
a015c4dc:  80 a3 25 54  cmp  %o4, 0x554
a015c4e0:  08 bf ff c9  bleu  0xa015c404
a015c4e4:  9e 00 60 7c  add  %g1, 0x7c, %o7
a015c4e8:  10 bf ff c7  b  0xa015c404
a015c4ec:  9e 10 20 7e  mov  0x7e, %o7
a015c4f0:  98 06 20 08  add  %i0, 8, %o4
a015c4f4:  f0 03 20 0c  ld  [ %o4 + 0xc ], %i0
a015c4f8:  80 a6 00 0c  cmp  %i0, %o4
a015c4fc:  32 bf ff b2  bne,a   0xa015c3c4
a015c500:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a015c504:  10 bf ff d2  b  0xa015c44c
a015c508:  9e 03 e0 02  add  %o7, 2, %o7
a015c50c:  80 a2 a1 ff  cmp  %o2, 0x1ff
a015c510:  08 80 00 be  bleu  0xa015c808
a015c514:  9b 32 a0 03  srl  %o2, 3, %o5
a015c518:  97 32 a0 09  srl  %o2, 9, %o3
a015c51c:  80 a2 e0 00  cmp  %o3, 0
a015c520:  22 80 00 17  be,a   0xa015c57c
a015c524:  96 17 22 b8  or  %i4, 0x2b8, %o3
a015c528:  83 32 a0 06  srl  %o2, 6, %g1
a015c52c:  80 a2 e0 04  cmp  %o3, 4
a015c530:  08 80 00 12  bleu  0xa015c578
a015c534:  9a 00 60 38  add  %g1, 0x38, %o5
a015c538:  80 a2 e0 14  cmp  %o3, 0x14
a015c53c:  08 80 00 0f  bleu  0xa015c578
a015c540:  9a 02 e0 5b  add  %o3, 0x5b, %o5
a015c544:  83 32 a0 0c  srl  %o2, 0xc, %g1
a015c548:  80 a2 e0 54  cmp  %o3, 0x54
a015c54c:  08 80 00 0b  bleu  0xa015c578
a015c550:  9a 00 60 6e  add  %g1, 0x6e, %o5
a015c554:  83 32 a0 0f  srl  %o2, 0xf, %g1
a015c558:  80 a2 e1 54  cmp  %o3, 0x154
a015c55c:  08 80 00 07  bleu  0xa015c578
a015c560:  9a 00 60 77  add  %g1, 0x77, %o5
a015c564:  83 32 a0 12  srl  %o2, 0x12, %g1
a015c568:  80 a2 e5 54  cmp  %o3, 0x554
a015c56c:  08 80 00 03  bleu  0xa015c578
a015c570:  9a 00 60 7c  add  %g1, 0x7c, %o5
a015c574:  9a 10 20 7e  mov  0x7e, %o5
a015c578:  96 17 22 b8  or  %i4, 0x2b8, %o3
a015c57c:  83 2b 60 03  sll  %o5, 3, %g1
a015c580:  90 00 40 0b  add  %g1, %o3, %o0
a015c584:  d2 02 20 08  ld  [ %o0 + 8 ], %o1
a015c588:  80 a2 40 08  cmp  %o1, %o0
a015c58c:  22 80 01 0f  be,a   0xa015c9c8
a015c590:  99 33 60 02  srl  %o5, 2, %o4
a015c594:  c2 02 60 04  ld  [ %o1 + 4 ], %g1
a015c598:  82 08 7f fc  and  %g1, -4, %g1
a015c59c:  80 a0 40 0a  cmp  %g1, %o2
a015c5a0:  28 80 00 07  bleu,a   0xa015c5bc
a015c5a4:  d0 02 60 0c  ld  [ %o1 + 0xc ], %o0
a015c5a8:  d2 02 60 08  ld  [ %o1 + 8 ], %o1
a015c5ac:  80 a2 40 08  cmp  %o1, %o0
a015c5b0:  32 bf ff fa  bne,a   0xa015c598
a015c5b4:  c2 02 60 04  ld  [ %o1 + 4 ], %g1
a015c5b8:  d0 02 60 0c  ld  [ %o1 + 0xc ], %o0
a015c5bc:  d0 26 20 0c  st  %o0, [ %i0 + 0xc ]
a015c5c0:  d2 26 20 08  st  %o1, [ %i0 + 8 ]
a015c5c4:  f0 22 60 0c  st  %i0, [ %o1 + 0xc ]
a015c5c8:  f0 22 20 08  st  %i0, [ %o0 + 8 ]
a015c5cc:  83 3b e0 1f  sra  %o7, 0x1f, %g1
a015c5d0:  83 30 60 1e  srl  %g1, 0x1e, %g1
a015c5d4:  82 03 c0 01  add  %o7, %g1, %g1
a015c5d8:  39 2a 00 aa  sethi  %hi(0xa802a800), %i4
a015c5dc:  83 38 60 02  sra  %g1, 2, %g1
a015c5e0:  98 17 22 b8  or  %i4, 0x2b8, %o4
a015c5e4:  9a 10 20 01  mov  1, %o5
a015c5e8:  93 2b 40 01  sll  %o5, %g1, %o1
a015c5ec:  d8 03 20 04  ld  [ %o4 + 4 ], %o4
a015c5f0:  80 a2 40 0c  cmp  %o1, %o4
a015c5f4:  18 80 00 4b  bgu  0xa015c720
a015c5f8:  ae 17 22 b8  or  %i4, 0x2b8, %l7
a015c5fc:  80 8b 00 09  btst  %o4, %o1
a015c600:  12 80 00 0d  bne  0xa015c634
a015c604:  03 2a 00 aa  sethi  %hi(0xa802a800), %g1
a015c608:  82 0b ff fc  and  %o7, -4, %g1
a015c60c:  92 02 40 09  add  %o1, %o1, %o1
a015c610:  80 8b 00 09  btst  %o4, %o1
a015c614:  12 80 00 07  bne  0xa015c630
a015c618:  9e 00 60 04  add  %g1, 4, %o7
a015c61c:  82 10 00 0c  mov  %o4, %g1
a015c620:  92 02 40 09  add  %o1, %o1, %o1
a015c624:  80 88 40 09  btst  %g1, %o1
a015c628:  02 bf ff fe  be  0xa015c620
a015c62c:  9e 03 e0 04  add  %o7, 4, %o7
a015c630:  03 2a 00 aa  sethi  %hi(0xa802a800), %g1
a015c634:  a2 10 62 b8  or  %g1, 0x2b8, %l1	! 0xa802aab8
a015c638:  a8 10 00 11  mov  %l1, %l4
a015c63c:  83 2b e0 03  sll  %o7, 3, %g1
a015c640:  98 00 40 11  add  %g1, %l1, %o4
a015c644:  90 10 00 0f  mov  %o7, %o0
a015c648:  9a 10 00 0c  mov  %o4, %o5
a015c64c:  10 80 00 0a  b  0xa015c674
a015c650:  f0 03 60 0c  ld  [ %o5 + 0xc ], %i0
a015c654:  94 08 7f fc  and  %g1, -4, %o2
a015c658:  96 22 80 10  sub  %o2, %l0, %o3
a015c65c:  80 a2 e0 0f  cmp  %o3, 0xf
a015c660:  14 80 00 7d  bg  0xa015c854
a015c664:  80 a2 e0 00  cmp  %o3, 0
a015c668:  36 80 00 8b  bge,a   0xa015c894
a015c66c:  9a 06 00 0a  add  %i0, %o2, %o5
a015c670:  f0 06 20 0c  ld  [ %i0 + 0xc ], %i0
a015c674:  80 a6 00 0d  cmp  %i0, %o5
a015c678:  32 bf ff f7  bne,a   0xa015c654
a015c67c:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a015c680:  9e 03 e0 01  inc  %o7
a015c684:  80 8b e0 03  btst  3, %o7
a015c688:  12 bf ff f1  bne  0xa015c64c
a015c68c:  9a 03 60 08  add  %o5, 8, %o5
a015c690:  80 8a 20 03  btst  3, %o0
a015c694:  98 03 3f f8  add  %o4, -8, %o4
a015c698:  02 80 00 d4  be  0xa015c9e8
a015c69c:  90 02 3f ff  add  %o0, -1, %o0
a015c6a0:  c2 03 20 08  ld  [ %o4 + 8 ], %g1
a015c6a4:  80 a0 40 0c  cmp  %g1, %o4
a015c6a8:  02 bf ff fb  be  0xa015c694
a015c6ac:  80 8a 20 03  btst  3, %o0
a015c6b0:  92 02 40 09  add  %o1, %o1, %o1
a015c6b4:  c2 05 20 04  ld  [ %l4 + 4 ], %g1
a015c6b8:  80 a2 40 01  cmp  %o1, %g1
a015c6bc:  18 80 00 18  bgu  0xa015c71c
a015c6c0:  39 2a 00 aa  sethi  %hi(0xa802a800), %i4
a015c6c4:  80 a2 60 00  cmp  %o1, 0
a015c6c8:  12 80 00 06  bne  0xa015c6e0
a015c6cc:  80 88 40 09  btst  %g1, %o1
a015c6d0:  10 80 00 14  b  0xa015c720
a015c6d4:  ae 17 22 b8  or  %i4, 0x2b8, %l7
a015c6d8:  9e 03 e0 04  add  %o7, 4, %o7
a015c6dc:  80 88 40 09  btst  %g1, %o1
a015c6e0:  22 bf ff fe  be,a   0xa015c6d8
a015c6e4:  92 02 40 09  add  %o1, %o1, %o1
a015c6e8:  10 bf ff d6  b  0xa015c640
a015c6ec:  83 2b e0 03  sll  %o7, 3, %g1
a015c6f0:  82 14 20 01  or  %l0, 1, %g1
a015c6f4:  94 06 00 10  add  %i0, %l0, %o2
a015c6f8:  c2 26 20 04  st  %g1, [ %i0 + 4 ]
a015c6fc:  d4 23 20 0c  st  %o2, [ %o4 + 0xc ]
a015c700:  d4 23 20 08  st  %o2, [ %o4 + 8 ]
a015c704:  82 12 e0 01  or  %o3, 1, %g1
a015c708:  d6 22 80 0b  st  %o3, [ %o2 + %o3 ]
a015c70c:  d8 22 a0 08  st  %o4, [ %o2 + 8 ]
a015c710:  c2 22 a0 04  st  %g1, [ %o2 + 4 ]
a015c714:  10 bf ff 35  b  0xa015c3e8
a015c718:  d8 22 a0 0c  st  %o4, [ %o2 + 0xc ]
a015c71c:  ae 17 22 b8  or  %i4, 0x2b8, %l7
a015c720:  f0 05 e0 08  ld  [ %l7 + 8 ], %i0
a015c724:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a015c728:  aa 08 7f fc  and  %g1, -4, %l5
a015c72c:  80 a5 40 10  cmp  %l5, %l0
a015c730:  9a 40 20 00  addx  %g0, 0, %o5
a015c734:  96 25 40 10  sub  %l5, %l0, %o3
a015c738:  80 a2 e0 0f  cmp  %o3, 0xf
a015c73c:  14 80 00 42  bg  0xa015c844
a015c740:  82 10 20 01  mov  1, %g1
a015c744:  80 93 40 01  orcc  %o5, %g1, %g0
a015c748:  02 80 00 27  be  0xa015c7e4
a015c74c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a015c750:  da 00 63 d0  ld  [ %g1 + 0x3d0 ], %o5	! 0xa802cfd0
a015c754:  2d 2a 00 aa  sethi  %hi(0xa802a800), %l6
a015c758:  9a 04 00 0d  add  %l0, %o5, %o5
a015c75c:  c2 05 a2 b0  ld  [ %l6 + 0x2b0 ], %g1
a015c760:  a8 10 00 15  mov  %l5, %l4
a015c764:  80 a0 7f ff  cmp  %g1, -1
a015c768:  a2 03 60 10  add  %o5, 0x10, %l1
a015c76c:  02 80 00 04  be  0xa015c77c
a015c770:  a4 06 00 15  add  %i0, %l5, %l2
a015c774:  82 04 6f ff  add  %l1, 0xfff, %g1
a015c778:  a2 08 70 00  and  %g1, -4096, %l1
a015c77c:  90 10 00 13  mov  %l3, %o0
a015c780:  40 00 05 e3  call  0xa015df0c
a015c784:  92 10 00 11  mov  %l1, %o1
a015c788:  80 a2 3f ff  cmp  %o0, -1
a015c78c:  02 80 00 08  be  0xa015c7ac
a015c790:  b2 10 00 08  mov  %o0, %i1
a015c794:  80 a2 00 12  cmp  %o0, %l2
a015c798:  1a 80 00 46  bcc  0xa015c8b0
a015c79c:  3b 2a 00 b3  sethi  %hi(0xa802cc00), %i5
a015c7a0:  80 a6 00 17  cmp  %i0, %l7
a015c7a4:  22 80 00 44  be,a   0xa015c8b4
a015c7a8:  c2 07 63 a0  ld  [ %i5 + 0x3a0 ], %g1
a015c7ac:  82 17 22 b8  or  %i4, 0x2b8, %g1
a015c7b0:  d8 00 60 08  ld  [ %g1 + 8 ], %o4
a015c7b4:  da 03 20 04  ld  [ %o4 + 4 ], %o5
a015c7b8:  9a 0b 7f fc  and  %o5, -4, %o5
a015c7bc:  80 a3 40 10  cmp  %o5, %l0
a015c7c0:  98 40 20 00  addx  %g0, 0, %o4
a015c7c4:  96 23 40 10  sub  %o5, %l0, %o3
a015c7c8:  80 a2 e0 0f  cmp  %o3, 0xf
a015c7cc:  04 80 00 03  ble  0xa015c7d8
a015c7d0:  82 10 20 01  mov  1, %g1
a015c7d4:  82 10 20 00  clr  %g1
a015c7d8:  80 93 00 01  orcc  %o4, %g1, %g0
a015c7dc:  12 80 00 98  bne  0xa015ca3c
a015c7e0:  01 00 00 00  nop
a015c7e4:  98 17 22 b8  or  %i4, 0x2b8, %o4
a015c7e8:  f0 03 20 08  ld  [ %o4 + 8 ], %i0
a015c7ec:  82 14 20 01  or  %l0, 1, %g1
a015c7f0:  c2 26 20 04  st  %g1, [ %i0 + 4 ]
a015c7f4:  9a 06 00 10  add  %i0, %l0, %o5
a015c7f8:  82 12 e0 01  or  %o3, 1, %g1
a015c7fc:  c2 23 60 04  st  %g1, [ %o5 + 4 ]
a015c800:  10 bf fe fa  b  0xa015c3e8
a015c804:  da 23 20 08  st  %o5, [ %o4 + 8 ]
a015c808:  98 03 3f f8  add  %o4, -8, %o4
a015c80c:  83 2b 60 03  sll  %o5, 3, %g1
a015c810:  90 00 40 0c  add  %g1, %o4, %o0
a015c814:  9b 33 60 02  srl  %o5, 2, %o5
a015c818:  82 10 20 01  mov  1, %g1
a015c81c:  83 28 40 0d  sll  %g1, %o5, %g1
a015c820:  d2 02 20 08  ld  [ %o0 + 8 ], %o1
a015c824:  da 03 20 04  ld  [ %o4 + 4 ], %o5
a015c828:  9a 13 40 01  or  %o5, %g1, %o5
a015c82c:  d0 26 20 0c  st  %o0, [ %i0 + 0xc ]
a015c830:  d2 26 20 08  st  %o1, [ %i0 + 8 ]
a015c834:  f0 22 60 0c  st  %i0, [ %o1 + 0xc ]
a015c838:  da 23 20 04  st  %o5, [ %o4 + 4 ]
a015c83c:  10 bf ff 64  b  0xa015c5cc
a015c840:  f0 22 20 08  st  %i0, [ %o0 + 8 ]
a015c844:  10 bf ff c0  b  0xa015c744
a015c848:  82 10 20 00  clr  %g1
a015c84c:  10 bf fe ff  b  0xa015c448
a015c850:  9e 03 ff ff  add  %o7, -1, %o7
a015c854:  d0 06 20 0c  ld  [ %i0 + 0xc ], %o0
a015c858:  d2 06 20 08  ld  [ %i0 + 8 ], %o1
a015c85c:  9a 14 20 01  or  %l0, 1, %o5
a015c860:  94 06 00 10  add  %i0, %l0, %o2
a015c864:  82 14 a2 c0  or  %l2, 0x2c0, %g1
a015c868:  d2 22 20 08  st  %o1, [ %o0 + 8 ]
a015c86c:  d0 22 60 0c  st  %o0, [ %o1 + 0xc ]
a015c870:  da 26 20 04  st  %o5, [ %i0 + 4 ]
a015c874:  d4 20 60 0c  st  %o2, [ %g1 + 0xc ]
a015c878:  d4 20 60 08  st  %o2, [ %g1 + 8 ]
a015c87c:  9a 12 e0 01  or  %o3, 1, %o5
a015c880:  d6 22 80 0b  st  %o3, [ %o2 + %o3 ]
a015c884:  c2 22 a0 08  st  %g1, [ %o2 + 8 ]
a015c888:  da 22 a0 04  st  %o5, [ %o2 + 4 ]
a015c88c:  10 bf fe d7  b  0xa015c3e8
a015c890:  c2 22 a0 0c  st  %g1, [ %o2 + 0xc ]
a015c894:  c2 03 60 04  ld  [ %o5 + 4 ], %g1
a015c898:  82 10 60 01  or  %g1, 1, %g1
a015c89c:  d0 06 20 0c  ld  [ %i0 + 0xc ], %o0
a015c8a0:  d2 06 20 08  ld  [ %i0 + 8 ], %o1
a015c8a4:  c2 23 60 04  st  %g1, [ %o5 + 4 ]
a015c8a8:  10 bf fe cf  b  0xa015c3e4
a015c8ac:  d2 22 20 08  st  %o1, [ %o0 + 8 ]
a015c8b0:  c2 07 63 a0  ld  [ %i5 + 0x3a0 ], %g1
a015c8b4:  82 00 40 11  add  %g1, %l1, %g1
a015c8b8:  80 a6 40 12  cmp  %i1, %l2
a015c8bc:  02 80 00 4f  be  0xa015c9f8
a015c8c0:  c2 27 63 a0  st  %g1, [ %i5 + 0x3a0 ]
a015c8c4:  c2 05 a2 b0  ld  [ %l6 + 0x2b0 ], %g1
a015c8c8:  80 a0 7f ff  cmp  %g1, -1
a015c8cc:  02 80 00 45  be  0xa015c9e0
a015c8d0:  c2 07 63 a0  ld  [ %i5 + 0x3a0 ], %g1
a015c8d4:  9a 26 40 12  sub  %i1, %l2, %o5
a015c8d8:  82 00 40 0d  add  %g1, %o5, %g1
a015c8dc:  c2 27 63 a0  st  %g1, [ %i5 + 0x3a0 ]
a015c8e0:  9a 8e 60 07  andcc  %i1, 7, %o5
a015c8e4:  02 80 00 05  be  0xa015c8f8
a015c8e8:  a4 10 20 00  clr  %l2
a015c8ec:  82 10 20 08  mov  8, %g1
a015c8f0:  a4 20 40 0d  sub  %g1, %o5, %l2
a015c8f4:  b2 06 40 12  add  %i1, %l2, %i1
a015c8f8:  9a 06 40 11  add  %i1, %l1, %o5
a015c8fc:  9a 0b 6f ff  and  %o5, 0xfff, %o5
a015c900:  03 00 00 04  sethi  %hi(0x1000), %g1
a015c904:  82 20 40 0d  sub  %g1, %o5, %g1
a015c908:  a4 04 80 01  add  %l2, %g1, %l2
a015c90c:  90 10 00 13  mov  %l3, %o0
a015c910:  40 00 05 7f  call  0xa015df0c
a015c914:  92 10 00 12  mov  %l2, %o1
a015c918:  80 a2 3f ff  cmp  %o0, -1
a015c91c:  22 80 00 3f  be,a   0xa015ca18
a015c920:  a4 10 20 00  clr  %l2
a015c924:  82 22 00 19  sub  %o0, %i1, %g1
a015c928:  90 00 40 12  add  %g1, %l2, %o0
a015c92c:  82 17 22 b8  or  %i4, 0x2b8, %g1
a015c930:  da 07 63 a0  ld  [ %i5 + 0x3a0 ], %o5
a015c934:  9a 03 40 12  add  %o5, %l2, %o5
a015c938:  80 a6 00 01  cmp  %i0, %g1
a015c93c:  f2 20 60 08  st  %i1, [ %g1 + 8 ]
a015c940:  da 27 63 a0  st  %o5, [ %i5 + 0x3a0 ]
a015c944:  02 80 00 37  be  0xa015ca20
a015c948:  82 12 20 01  or  %o0, 1, %g1
a015c94c:  80 a5 60 0f  cmp  %l5, 0xf
a015c950:  38 80 00 05  bgu,a   0xa015c964
a015c954:  c2 26 60 04  st  %g1, [ %i1 + 4 ]
a015c958:  82 10 20 01  mov  1, %g1
a015c95c:  10 bf ff 94  b  0xa015c7ac
a015c960:  c2 26 60 04  st  %g1, [ %i1 + 4 ]
a015c964:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a015c968:  9a 05 7f f4  add  %l5, -12, %o5
a015c96c:  a8 0b 7f f8  and  %o5, -8, %l4
a015c970:  82 08 60 01  and  %g1, 1, %g1
a015c974:  82 10 40 14  or  %g1, %l4, %g1
a015c978:  c2 26 20 04  st  %g1, [ %i0 + 4 ]
a015c97c:  9a 06 00 14  add  %i0, %l4, %o5
a015c980:  82 10 20 05  mov  5, %g1
a015c984:  c2 23 60 08  st  %g1, [ %o5 + 8 ]
a015c988:  80 a5 20 0f  cmp  %l4, 0xf
a015c98c:  18 80 00 27  bgu  0xa015ca28
a015c990:  c2 23 60 04  st  %g1, [ %o5 + 4 ]
a015c994:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a015c998:  da 07 63 a0  ld  [ %i5 + 0x3a0 ], %o5
a015c99c:  c2 03 23 cc  ld  [ %o4 + 0x3cc ], %g1
a015c9a0:  80 a3 40 01  cmp  %o5, %g1
a015c9a4:  38 80 00 02  bgu,a   0xa015c9ac
a015c9a8:  da 23 23 cc  st  %o5, [ %o4 + 0x3cc ]
a015c9ac:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a015c9b0:  c2 03 23 c8  ld  [ %o4 + 0x3c8 ], %g1	! 0xa802cfc8
a015c9b4:  80 a3 40 01  cmp  %o5, %g1
a015c9b8:  38 bf ff 7d  bgu,a   0xa015c7ac
a015c9bc:  da 23 23 c8  st  %o5, [ %o4 + 0x3c8 ]
a015c9c0:  10 bf ff 7c  b  0xa015c7b0
a015c9c4:  82 17 22 b8  or  %i4, 0x2b8, %g1
a015c9c8:  9a 10 20 01  mov  1, %o5
a015c9cc:  c2 02 e0 04  ld  [ %o3 + 4 ], %g1
a015c9d0:  9b 2b 40 0c  sll  %o5, %o4, %o5
a015c9d4:  82 10 40 0d  or  %g1, %o5, %g1
a015c9d8:  10 bf fe f9  b  0xa015c5bc
a015c9dc:  c2 22 e0 04  st  %g1, [ %o3 + 4 ]
a015c9e0:  10 bf ff c0  b  0xa015c8e0
a015c9e4:  f2 25 a2 b0  st  %i1, [ %l6 + 0x2b0 ]
a015c9e8:  c2 04 60 04  ld  [ %l1 + 4 ], %g1
a015c9ec:  82 28 40 09  andn  %g1, %o1, %g1
a015c9f0:  10 bf ff 30  b  0xa015c6b0
a015c9f4:  c2 24 60 04  st  %g1, [ %l1 + 4 ]
a015c9f8:  80 8e 6f ff  btst  0xfff, %i1
a015c9fc:  12 bf ff b3  bne  0xa015c8c8
a015ca00:  c2 05 a2 b0  ld  [ %l6 + 0x2b0 ], %g1
a015ca04:  90 04 40 14  add  %l1, %l4, %o0
a015ca08:  da 05 e0 08  ld  [ %l7 + 8 ], %o5
a015ca0c:  82 12 20 01  or  %o0, 1, %g1
a015ca10:  10 bf ff e1  b  0xa015c994
a015ca14:  c2 23 60 04  st  %g1, [ %o5 + 4 ]
a015ca18:  10 bf ff c3  b  0xa015c924
a015ca1c:  90 10 00 19  mov  %i1, %o0
a015ca20:  10 bf ff dd  b  0xa015c994
a015ca24:  c2 26 60 04  st  %g1, [ %i1 + 4 ]
a015ca28:  92 06 20 08  add  %i0, 8, %o1
a015ca2c:  7f ff fb a5  call  0xa015b8c0
a015ca30:  90 10 00 13  mov  %l3, %o0
a015ca34:  10 bf ff d9  b  0xa015c998
a015ca38:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a015ca3c:  40 00 00 8c  call  0xa015cc6c
a015ca40:  90 10 00 13  mov  %l3, %o0
a015ca44:  b0 10 20 00  clr  %i0
a015ca48:  81 c7 e0 08  ret
a015ca4c:  81 e8 00 00  restore
