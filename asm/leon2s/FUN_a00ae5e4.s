# leon2s FUN_a00ae5e4 0xa00ae5e4-0xa00ae850 (620 bytes)
a00ae5e4:  9d e3 bf 98  save  %sp, -104, %sp
a00ae5e8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00ae5ec:  90 10 00 10  mov  %l0, %o0
a00ae5f0:  7f ff e1 72  call  0xa00a6bb8
a00ae5f4:  92 10 20 f7  mov  0xf7, %o1
a00ae5f8:  80 8a 20 08  btst  8, %o0
a00ae5fc:  02 80 00 92  be  0xa00ae844
a00ae600:  90 10 00 10  mov  %l0, %o0
a00ae604:  7f ff e1 6d  call  0xa00a6bb8
a00ae608:  92 10 20 f8  mov  0xf8, %o1
a00ae60c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ae610:  a7 32 20 03  srl  %o0, 3, %l3
a00ae614:  10 80 00 0d  b  0xa00ae648
a00ae618:  a4 10 20 00  clr  %l2
a00ae61c:  80 a4 60 13  cmp  %l1, 0x13
a00ae620:  38 80 00 08  bgu,a   0xa00ae640
a00ae624:  90 10 00 10  mov  %l0, %o0
a00ae628:  7f ff e1 64  call  0xa00a6bb8
a00ae62c:  a4 04 a0 01  inc  %l2
a00ae630:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00ae634:  82 10 62 78  or  %g1, 0x278, %g1	! 0xa807de78
a00ae638:  10 80 00 04  b  0xa00ae648
a00ae63c:  d0 28 40 11  stb  %o0, [ %g1 + %l1 ]
a00ae640:  7f ff e1 5e  call  0xa00a6bb8
a00ae644:  92 10 20 f9  mov  0xf9, %o1
a00ae648:  92 10 20 f8  mov  0xf8, %o1
a00ae64c:  7f ff e1 5b  call  0xa00a6bb8
a00ae650:  90 10 00 10  mov  %l0, %o0
a00ae654:  80 8a 20 01  btst  1, %o0
a00ae658:  92 10 20 f9  mov  0xf9, %o1
a00ae65c:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00ae660:  12 bf ff ef  bne  0xa00ae61c
a00ae664:  90 10 00 10  mov  %l0, %o0
a00ae668:  23 2a 01 f7  sethi  %hi(0xa807dc00), %l1
a00ae66c:  c2 0c 62 78  ldub  [ %l1 + 0x278 ], %g1	! 0xa807de78
a00ae670:  80 a0 60 10  cmp  %g1, 0x10
a00ae674:  12 80 00 2d  bne  0xa00ae728
a00ae678:  82 14 62 78  or  %l1, 0x278, %g1
a00ae67c:  c2 08 60 02  ldub  [ %g1 + 2 ], %g1
a00ae680:  80 a0 60 30  cmp  %g1, 0x30
a00ae684:  32 80 00 2a  bne,a   0xa00ae72c
a00ae688:  c2 0c 62 78  ldub  [ %l1 + 0x278 ], %g1
a00ae68c:  92 10 20 24  mov  0x24, %o1
a00ae690:  94 10 20 02  mov  2, %o2
a00ae694:  7f ff e1 81  call  0xa00a6c98
a00ae698:  96 10 20 00  clr  %o3
a00ae69c:  96 10 20 01  mov  1, %o3
a00ae6a0:  90 10 00 10  mov  %l0, %o0
a00ae6a4:  92 10 20 24  mov  0x24, %o1
a00ae6a8:  7f ff e1 7c  call  0xa00a6c98
a00ae6ac:  94 10 20 04  mov  4, %o2
a00ae6b0:  90 10 00 10  mov  %l0, %o0
a00ae6b4:  92 10 20 25  mov  0x25, %o1
a00ae6b8:  7f ff e1 52  call  0xa00a6c00
a00ae6bc:  94 10 20 00  clr  %o2
a00ae6c0:  90 10 00 10  mov  %l0, %o0
a00ae6c4:  92 10 20 24  mov  0x24, %o1
a00ae6c8:  94 10 20 02  mov  2, %o2
a00ae6cc:  7f ff e1 73  call  0xa00a6c98
a00ae6d0:  96 10 20 00  clr  %o3
a00ae6d4:  96 10 20 01  mov  1, %o3
a00ae6d8:  90 10 00 10  mov  %l0, %o0
a00ae6dc:  92 10 20 24  mov  0x24, %o1
a00ae6e0:  7f ff e1 6e  call  0xa00a6c98
a00ae6e4:  94 10 20 04  mov  4, %o2
a00ae6e8:  90 10 00 10  mov  %l0, %o0
a00ae6ec:  92 10 20 25  mov  0x25, %o1
a00ae6f0:  7f ff e1 44  call  0xa00a6c00
a00ae6f4:  94 10 20 00  clr  %o2
a00ae6f8:  92 10 20 24  mov  0x24, %o1
a00ae6fc:  94 10 20 08  mov  8, %o2
a00ae700:  96 10 20 01  mov  1, %o3
a00ae704:  7f ff e1 65  call  0xa00a6c98
a00ae708:  90 10 00 10  mov  %l0, %o0
a00ae70c:  40 00 0b c0  call  0xa00b160c
a00ae710:  90 10 23 20  mov  0x320, %o0
a00ae714:  90 10 00 10  mov  %l0, %o0
a00ae718:  92 10 20 24  mov  0x24, %o1
a00ae71c:  94 10 20 01  mov  1, %o2
a00ae720:  7f ff e1 5e  call  0xa00a6c98
a00ae724:  96 10 20 00  clr  %o3
a00ae728:  c2 0c 62 78  ldub  [ %l1 + 0x278 ], %g1
a00ae72c:  80 a0 60 10  cmp  %g1, 0x10
a00ae730:  12 80 00 1a  bne  0xa00ae798
a00ae734:  82 14 62 78  or  %l1, 0x278, %g1
a00ae738:  c2 08 60 02  ldub  [ %g1 + 2 ], %g1
a00ae73c:  80 a0 60 50  cmp  %g1, 0x50
a00ae740:  12 80 00 17  bne  0xa00ae79c
a00ae744:  c2 0c 62 78  ldub  [ %l1 + 0x278 ], %g1
a00ae748:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00ae74c:  90 10 00 10  mov  %l0, %o0
a00ae750:  92 10 20 24  mov  0x24, %o1
a00ae754:  94 10 20 02  mov  2, %o2
a00ae758:  7f ff e1 50  call  0xa00a6c98
a00ae75c:  96 10 20 00  clr  %o3
a00ae760:  96 10 20 01  mov  1, %o3
a00ae764:  90 10 00 10  mov  %l0, %o0
a00ae768:  92 10 20 24  mov  0x24, %o1
a00ae76c:  7f ff e1 4b  call  0xa00a6c98
a00ae770:  94 10 20 04  mov  4, %o2
a00ae774:  90 10 00 10  mov  %l0, %o0
a00ae778:  92 10 20 25  mov  0x25, %o1
a00ae77c:  7f ff e1 21  call  0xa00a6c00
a00ae780:  94 10 20 00  clr  %o2
a00ae784:  90 10 00 10  mov  %l0, %o0
a00ae788:  92 10 20 24  mov  0x24, %o1
a00ae78c:  94 10 20 08  mov  8, %o2
a00ae790:  7f ff e1 42  call  0xa00a6c98
a00ae794:  96 10 20 01  mov  1, %o3
a00ae798:  c2 0c 62 78  ldub  [ %l1 + 0x278 ], %g1
a00ae79c:  80 a0 60 50  cmp  %g1, 0x50
a00ae7a0:  12 80 00 24  bne  0xa00ae830
a00ae7a4:  9a 14 62 78  or  %l1, 0x278, %o5
a00ae7a8:  c2 0b 60 02  ldub  [ %o5 + 2 ], %g1
a00ae7ac:  80 a0 60 50  cmp  %g1, 0x50
a00ae7b0:  12 80 00 21  bne  0xa00ae834
a00ae7b4:  90 0e 20 ff  and  %i0, 0xff, %o0
a00ae7b8:  c2 0b 60 03  ldub  [ %o5 + 3 ], %g1
a00ae7bc:  80 a0 00 01  cmp  %g0, %g1
a00ae7c0:  82 0c e0 ff  and  %l3, 0xff, %g1
a00ae7c4:  9a 60 3f ff  subx  %g0, -1, %o5
a00ae7c8:  82 18 60 04  xor  %g1, 4, %g1
a00ae7cc:  80 a0 00 01  cmp  %g0, %g1
a00ae7d0:  82 60 3f ff  subx  %g0, -1, %g1
a00ae7d4:  80 8b 40 01  btst  %o5, %g1
a00ae7d8:  02 80 00 18  be  0xa00ae838
a00ae7dc:  92 10 20 f7  mov  0xf7, %o1
a00ae7e0:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00ae7e4:  90 10 00 10  mov  %l0, %o0
a00ae7e8:  92 10 20 24  mov  0x24, %o1
a00ae7ec:  94 10 20 01  mov  1, %o2
a00ae7f0:  7f ff e1 2a  call  0xa00a6c98
a00ae7f4:  96 10 20 01  mov  1, %o3
a00ae7f8:  90 10 00 10  mov  %l0, %o0
a00ae7fc:  92 10 20 24  mov  0x24, %o1
a00ae800:  94 10 20 02  mov  2, %o2
a00ae804:  7f ff e1 25  call  0xa00a6c98
a00ae808:  96 10 20 00  clr  %o3
a00ae80c:  90 10 00 10  mov  %l0, %o0
a00ae810:  92 10 20 24  mov  0x24, %o1
a00ae814:  94 10 20 04  mov  4, %o2
a00ae818:  7f ff e1 20  call  0xa00a6c98
a00ae81c:  96 10 20 01  mov  1, %o3
a00ae820:  90 10 00 10  mov  %l0, %o0
a00ae824:  92 10 20 25  mov  0x25, %o1
a00ae828:  7f ff e0 f6  call  0xa00a6c00
a00ae82c:  94 10 20 00  clr  %o2
a00ae830:  90 0e 20 ff  and  %i0, 0xff, %o0
a00ae834:  92 10 20 f7  mov  0xf7, %o1
a00ae838:  94 10 20 08  mov  8, %o2
a00ae83c:  7f ff e1 17  call  0xa00a6c98
a00ae840:  96 10 20 01  mov  1, %o3
a00ae844:  01 00 00 00  nop
a00ae848:  81 c7 e0 08  ret
a00ae84c:  81 e8 00 00  restore
