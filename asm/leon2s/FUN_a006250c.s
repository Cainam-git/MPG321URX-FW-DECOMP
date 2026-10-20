# leon2s FUN_a006250c 0xa006250c-0xa0062718 (524 bytes)
a006250c:  9d e3 bf 90  save  %sp, -112, %sp
a0062510:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0062514:  82 10 62 a0  or  %g1, 0x2a0, %g1	! 0xa8078aa0
a0062518:  94 10 20 00  clr  %o2
a006251c:  2b 2a 01 e2  sethi  %hi(0xa8078800), %l5
a0062520:  29 2a 01 e2  sethi  %hi(0xa8078800), %l4
a0062524:  d0 08 60 07  ldub  [ %g1 + 7 ], %o0
a0062528:  c0 25 62 64  clr  [ %l5 + 0x264 ]
a006252c:  c0 25 22 6c  clr  [ %l4 + 0x26c ]
a0062530:  80 a2 80 08  cmp  %o2, %o0
a0062534:  9e 10 20 00  clr  %o7
a0062538:  96 10 20 00  clr  %o3
a006253c:  ae 10 20 00  clr  %l7
a0062540:  98 10 20 00  clr  %o4
a0062544:  9a 10 20 00  clr  %o5
a0062548:  a6 10 20 00  clr  %l3
a006254c:  a4 10 20 00  clr  %l2
a0062550:  92 10 20 00  clr  %o1
a0062554:  c0 27 bf f4  clr  [ %fp + -12 ]
a0062558:  ac 10 20 00  clr  %l6
a006255c:  b2 10 20 00  clr  %i1
a0062560:  ba 10 20 00  clr  %i5
a0062564:  1a 80 00 40  bcc  0xa0062664
a0062568:  b0 10 20 00  clr  %i0
a006256c:  a2 10 20 00  clr  %l1
a0062570:  a0 10 20 00  clr  %l0
a0062574:  82 0e 20 ff  and  %i0, 0xff, %g1
a0062578:  39 2a 01 e2  sethi  %hi(0xa8078800), %i4
a006257c:  b8 17 22 a0  or  %i4, 0x2a0, %i4	! 0xa8078aa0
a0062580:  82 00 40 01  add  %g1, %g1, %g1
a0062584:  82 00 40 1c  add  %g1, %i4, %g1
a0062588:  f8 10 60 30  lduh  [ %g1 + 0x30 ], %i4
a006258c:  80 a7 20 32  cmp  %i4, 0x32
a0062590:  12 80 00 05  bne  0xa00625a4
a0062594:  f4 10 60 08  lduh  [ %g1 + 8 ], %i2
a0062598:  a2 10 00 1a  mov  %i2, %l1
a006259c:  10 80 00 18  b  0xa00625fc
a00625a0:  9e 10 20 01  mov  1, %o7
a00625a4:  82 0b e0 ff  and  %o7, 0xff, %g1
a00625a8:  80 a0 00 01  cmp  %g0, %g1
a00625ac:  b6 60 3f ff  subx  %g0, -1, %i3
a00625b0:  80 a7 20 32  cmp  %i4, 0x32
a00625b4:  18 80 00 03  bgu  0xa00625c0
a00625b8:  82 10 20 01  mov  1, %g1
a00625bc:  82 10 20 00  clr  %g1
a00625c0:  80 8e c0 01  btst  %i3, %g1
a00625c4:  02 80 00 09  be  0xa00625e8
a00625c8:  80 a7 20 63  cmp  %i4, 0x63
a00625cc:  80 a6 60 31  cmp  %i1, 0x31
a00625d0:  18 80 00 06  bgu  0xa00625e8
a00625d4:  80 a7 20 63  cmp  %i4, 0x63
a00625d8:  9a 10 00 19  mov  %i1, %o5
a00625dc:  a4 10 00 1c  mov  %i4, %l2
a00625e0:  98 10 00 1d  mov  %i5, %o4
a00625e4:  a6 10 00 1a  mov  %i2, %l3
a00625e8:  12 80 00 06  bne  0xa0062600
a00625ec:  82 0a e0 ff  and  %o3, 0xff, %g1
a00625f0:  a0 10 00 1a  mov  %i2, %l0
a00625f4:  10 80 00 14  b  0xa0062644
a00625f8:  96 10 20 01  mov  1, %o3
a00625fc:  82 0a e0 ff  and  %o3, 0xff, %g1
a0062600:  80 a0 00 01  cmp  %g0, %g1
a0062604:  b6 60 3f ff  subx  %g0, -1, %i3
a0062608:  80 a7 20 63  cmp  %i4, 0x63
a006260c:  18 80 00 03  bgu  0xa0062618
a0062610:  82 10 20 01  mov  1, %g1
a0062614:  82 10 20 00  clr  %g1
a0062618:  80 8e c0 01  btst  %i3, %g1
a006261c:  22 80 00 0b  be,a   0xa0062648
a0062620:  b0 06 20 01  inc  %i0
a0062624:  80 a6 60 62  cmp  %i1, 0x62
a0062628:  38 80 00 08  bgu,a   0xa0062648
a006262c:  b0 06 20 01  inc  %i0
a0062630:  92 10 00 19  mov  %i1, %o1
a0062634:  94 10 00 1d  mov  %i5, %o2
a0062638:  ac 10 00 1c  mov  %i4, %l6
a006263c:  f4 27 bf f4  st  %i2, [ %fp + -12 ]
a0062640:  ae 10 20 01  mov  1, %l7
a0062644:  b0 06 20 01  inc  %i0
a0062648:  82 0e 20 ff  and  %i0, 0xff, %g1
a006264c:  80 a0 40 08  cmp  %g1, %o0
a0062650:  b2 10 00 1c  mov  %i4, %i1
a0062654:  0a bf ff c9  bcs  0xa0062578
a0062658:  ba 10 00 1a  mov  %i2, %i5
a006265c:  e0 25 22 6c  st  %l0, [ %l4 + 0x26c ]
a0062660:  e2 25 62 64  st  %l1, [ %l5 + 0x264 ]
a0062664:  80 8b e0 ff  btst  0xff, %o7
a0062668:  12 80 00 13  bne  0xa00626b4
a006266c:  80 8a e0 ff  btst  0xff, %o3
a0062670:  b8 24 80 0d  sub  %l2, %o5, %i4
a0062674:  80 a7 20 01  cmp  %i4, 1
a0062678:  2a 80 00 02  bcs,a   0xa0062680
a006267c:  b8 10 20 01  mov  1, %i4
a0062680:  82 10 20 32  mov  0x32, %g1
a0062684:  82 20 40 0d  sub  %g1, %o5, %g1
a0062688:  ba 24 c0 0c  sub  %l3, %o4, %i5
a006268c:  ba 5f 40 01  smul  %i5, %g1, %i5
a0062690:  81 80 00 00  mov  %g0, %y
a0062694:  01 00 00 00  nop
a0062698:  01 00 00 00  nop
a006269c:  01 00 00 00  nop
a00626a0:  ba 77 40 1c  udiv  %i5, %i4, %i5
a00626a4:  ba 03 00 1d  add  %o4, %i5, %i5
a00626a8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00626ac:  fa 20 62 64  st  %i5, [ %g1 + 0x264 ]	! 0xa8078a64
a00626b0:  80 8a e0 ff  btst  0xff, %o3
a00626b4:  12 80 00 17  bne  0xa0062710
a00626b8:  80 8d e0 ff  btst  0xff, %l7
a00626bc:  02 80 00 12  be  0xa0062704
a00626c0:  03 2a 01 d9  sethi  %hi(0xa8076400), %g1
a00626c4:  b8 25 80 09  sub  %l6, %o1, %i4
a00626c8:  80 a7 20 01  cmp  %i4, 1
a00626cc:  2a 80 00 02  bcs,a   0xa00626d4
a00626d0:  b8 10 20 01  mov  1, %i4
a00626d4:  82 10 20 63  mov  0x63, %g1
a00626d8:  da 07 bf f4  ld  [ %fp + -12 ], %o5
a00626dc:  82 20 40 09  sub  %g1, %o1, %g1
a00626e0:  ba 23 40 0a  sub  %o5, %o2, %i5
a00626e4:  ba 5f 40 01  smul  %i5, %g1, %i5
a00626e8:  81 80 00 00  mov  %g0, %y
a00626ec:  01 00 00 00  nop
a00626f0:  01 00 00 00  nop
a00626f4:  01 00 00 00  nop
a00626f8:  ba 77 40 1c  udiv  %i5, %i4, %i5
a00626fc:  10 80 00 03  b  0xa0062708
a0062700:  ba 02 80 1d  add  %o2, %i5, %i5
a0062704:  fa 00 62 84  ld  [ %g1 + 0x284 ], %i5
a0062708:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006270c:  fa 20 62 6c  st  %i5, [ %g1 + 0x26c ]	! 0xa8078a6c
a0062710:  81 c7 e0 08  ret
a0062714:  81 e8 00 00  restore
