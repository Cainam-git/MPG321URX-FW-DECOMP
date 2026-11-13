# leon2m FUN_a014d5f4 0xa014d5f4-0xa014dbf4 (1536 bytes)
a014d5f4:  9d e3 bf 98  save  %sp, -104, %sp
a014d5f8:  7f fe 40 7e  call  0xa00dd7f0
a014d5fc:  01 00 00 00  nop
a014d600:  90 0a 20 ff  and  %o0, 0xff, %o0
a014d604:  80 a2 20 01  cmp  %o0, 1
a014d608:  02 80 00 5e  be  0xa014d780
a014d60c:  3b 2a 00 a9  sethi  %hi(0xa802a400), %i5
a014d610:  ec 0f 60 7e  ldub  [ %i5 + 0x7e ], %l6	! 0xa802a47e
a014d614:  80 a5 a0 00  cmp  %l6, 0
a014d618:  12 80 01 75  bne  0xa014dbec
a014d61c:  39 00 06 9c  sethi  %hi(0x1a7000), %i4
a014d620:  2f 2a 00 b3  sethi  %hi(0xa802cc00), %l7
a014d624:  7f fe 46 d3  call  0xa00df170
a014d628:  90 17 22 78  or  %i4, 0x278, %o0
a014d62c:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a014d630:  aa 15 e0 5f  or  %l7, 0x5f, %l5
a014d634:  c0 2c a0 5d  clrb  [ %l2 + 0x5d ]
a014d638:  92 10 00 12  mov  %l2, %o1
a014d63c:  2d 00 06 9c  sethi  %hi(0x1a7000), %l6
a014d640:  31 00 06 9c  sethi  %hi(0x1a7000), %i0
a014d644:  2f 00 03 fb  sethi  %hi(0xfec00), %l7
a014d648:  d2 0a 60 5d  ldub  [ %o1 + 0x5d ], %o1
a014d64c:  80 a0 00 09  cmp  %g0, %o1
a014d650:  98 60 3f ff  subx  %g0, -1, %o4
a014d654:  94 1a 60 04  xor  %o1, 4, %o2
a014d658:  80 a0 00 0a  cmp  %g0, %o2
a014d65c:  a6 60 3f ff  subx  %g0, -1, %l3
a014d660:  80 93 00 13  orcc  %o4, %l3, %g0
a014d664:  12 80 00 41  bne  0xa014d768
a014d668:  80 a2 60 08  cmp  %o1, 8
a014d66c:  22 80 00 40  be,a   0xa014d76c
a014d670:  11 00 06 9c  sethi  %hi(0x1a7000), %o0
a014d674:  d2 0c a0 5d  ldub  [ %l2 + 0x5d ], %o1
a014d678:  92 0a 60 03  and  %o1, 3, %o1
a014d67c:  90 15 a2 88  or  %l6, 0x288, %o0
a014d680:  7f fe 46 bc  call  0xa00df170
a014d684:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a014d688:  c0 2c 60 5e  clrb  [ %l1 + 0x5e ]	! 0xa802cc5e
a014d68c:  a0 10 00 11  mov  %l1, %l0
a014d690:  b2 10 00 15  mov  %l5, %i1
a014d694:  29 2a 00 b3  sethi  %hi(0xa802cc00), %l4
a014d698:  10 80 00 0b  b  0xa014d6c4
a014d69c:  27 00 06 9c  sethi  %hi(0x1a7000), %l3
a014d6a0:  02 80 00 c8  be  0xa014d9c0
a014d6a4:  d0 0c 60 5e  ldub  [ %l1 + 0x5e ], %o0
a014d6a8:  94 02 20 01  add  %o0, 1, %o2
a014d6ac:  d4 2c 60 5e  stb  %o2, [ %l1 + 0x5e ]
a014d6b0:  98 0a a0 ff  and  %o2, 0xff, %o4
a014d6b4:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a014d6b8:  80 a3 20 03  cmp  %o4, 3
a014d6bc:  18 80 00 1c  bgu  0xa014d72c
a014d6c0:  a0 10 00 11  mov  %l1, %l0
a014d6c4:  d6 0c a0 5d  ldub  [ %l2 + 0x5d ], %o3
a014d6c8:  9b 2a e0 02  sll  %o3, 2, %o5
a014d6cc:  82 03 40 19  add  %o5, %i1, %g1
a014d6d0:  de 0c 20 5e  ldub  [ %l0 + 0x5e ], %o7
a014d6d4:  d2 08 40 0f  ldub  [ %g1 + %o7 ], %o1
a014d6d8:  7f fe 46 a6  call  0xa00df170
a014d6dc:  90 16 22 98  or  %i0, 0x298, %o0
a014d6e0:  c2 0c 20 5e  ldub  [ %l0 + 0x5e ], %g1
a014d6e4:  80 a0 60 00  cmp  %g1, 0
a014d6e8:  12 bf ff ee  bne  0xa014d6a0
a014d6ec:  80 a0 60 02  cmp  %g1, 2
a014d6f0:  e0 0c a0 5d  ldub  [ %l2 + 0x5d ], %l0
a014d6f4:  92 0c 20 03  and  %l0, 3, %o1
a014d6f8:  7f ff 1f e3  call  0xa0115684
a014d6fc:  91 34 20 02  srl  %l0, 2, %o0
a014d700:  92 0a 20 ff  and  %o0, 0xff, %o1
a014d704:  7f fe 46 9b  call  0xa00df170
a014d708:  90 14 e2 d0  or  %l3, 0x2d0, %o0
a014d70c:  d0 0c 60 5e  ldub  [ %l1 + 0x5e ], %o0
a014d710:  94 02 20 01  add  %o0, 1, %o2
a014d714:  d4 2c 60 5e  stb  %o2, [ %l1 + 0x5e ]
a014d718:  98 0a a0 ff  and  %o2, 0xff, %o4
a014d71c:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a014d720:  80 a3 20 03  cmp  %o4, 3
a014d724:  08 bf ff e8  bleu  0xa014d6c4
a014d728:  a0 10 00 11  mov  %l1, %l0
a014d72c:  7f fe 46 91  call  0xa00df170
a014d730:  90 15 e3 c0  or  %l7, 0x3c0, %o0
a014d734:  e8 0c a0 5d  ldub  [ %l2 + 0x5d ], %l4
a014d738:  b2 05 20 01  add  %l4, 1, %i1
a014d73c:  f2 2c a0 5d  stb  %i1, [ %l2 + 0x5d ]
a014d740:  a2 0e 60 ff  and  %i1, 0xff, %l1
a014d744:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a014d748:  80 a4 60 07  cmp  %l1, 7
a014d74c:  08 bf ff bf  bleu  0xa014d648
a014d750:  92 10 00 12  mov  %l2, %o1
a014d754:  b0 10 20 01  mov  1, %i0
a014d758:  f0 2f 60 7e  stb  %i0, [ %i5 + 0x7e ]
a014d75c:  3b 2a 00 b3  sethi  %hi(0xa802cc00), %i5
a014d760:  10 80 01 23  b  0xa014dbec
a014d764:  c0 27 60 58  clr  [ %i5 + 0x58 ]	! 0xa802cc58
a014d768:  11 00 06 9c  sethi  %hi(0x1a7000), %o0
a014d76c:  93 32 60 02  srl  %o1, 2, %o1
a014d770:  7f fe 46 80  call  0xa00df170
a014d774:  90 12 22 a0  or  %o0, 0x2a0, %o0
a014d778:  10 bf ff c0  b  0xa014d678
a014d77c:  d2 0c a0 5d  ldub  [ %l2 + 0x5d ], %o1
a014d780:  c2 0f 60 7e  ldub  [ %i5 + 0x7e ], %g1
a014d784:  80 a0 60 01  cmp  %g1, 1
a014d788:  02 80 00 d8  be  0xa014dae8
a014d78c:  13 00 06 9c  sethi  %hi(0x1a7000), %o1
a014d790:  7f fe 40 1b  call  0xa00dd7fc
a014d794:  39 2a 00 b3  sethi  %hi(0xa802cc00), %i4
a014d798:  de 07 20 58  ld  [ %i4 + 0x58 ], %o7	! 0xa802cc58
a014d79c:  80 a2 00 0f  cmp  %o0, %o7
a014d7a0:  18 80 00 55  bgu  0xa014d8f4
a014d7a4:  1f 00 06 9c  sethi  %hi(0x1a7000), %o7
a014d7a8:  90 13 e2 f0  or  %o7, 0x2f0, %o0	! 0x1a72f0
a014d7ac:  7f fe 46 71  call  0xa00df170
a014d7b0:  29 2a 00 b3  sethi  %hi(0xa802cc00), %l4
a014d7b4:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a014d7b8:  c0 2a 60 5d  clrb  [ %o1 + 0x5d ]	! 0xa802cc5d
a014d7bc:  ae 15 20 5f  or  %l4, 0x5f, %l7
a014d7c0:  b2 10 00 09  mov  %o1, %i1
a014d7c4:  2b 00 06 9c  sethi  %hi(0x1a7000), %l5
a014d7c8:  27 00 06 9c  sethi  %hi(0x1a7000), %l3
a014d7cc:  2d 00 03 fb  sethi  %hi(0xfec00), %l6
a014d7d0:  d2 0a 60 5d  ldub  [ %o1 + 0x5d ], %o1
a014d7d4:  80 a0 00 09  cmp  %g0, %o1
a014d7d8:  82 60 3f ff  subx  %g0, -1, %g1
a014d7dc:  9a 1a 60 04  xor  %o1, 4, %o5
a014d7e0:  80 a0 00 0d  cmp  %g0, %o5
a014d7e4:  b0 60 3f ff  subx  %g0, -1, %i0
a014d7e8:  80 90 40 18  orcc  %g1, %i0, %g0
a014d7ec:  12 80 00 81  bne  0xa014d9f0
a014d7f0:  80 a2 60 08  cmp  %o1, 8
a014d7f4:  02 80 00 80  be  0xa014d9f4
a014d7f8:  17 00 06 9c  sethi  %hi(0x1a7000), %o3
a014d7fc:  d8 0e 60 5d  ldub  [ %i1 + 0x5d ], %o4
a014d800:  92 0b 20 03  and  %o4, 3, %o1
a014d804:  90 15 62 88  or  %l5, 0x288, %o0
a014d808:  7f fe 46 5a  call  0xa00df170
a014d80c:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a014d810:  c0 2c 20 5e  clrb  [ %l0 + 0x5e ]	! 0xa802cc5e
a014d814:  a2 10 00 10  mov  %l0, %l1
a014d818:  a4 10 00 17  mov  %l7, %l2
a014d81c:  29 2a 00 b3  sethi  %hi(0xa802cc00), %l4
a014d820:  10 80 00 0b  b  0xa014d84c
a014d824:  31 00 06 9c  sethi  %hi(0x1a7000), %i0
a014d828:  02 80 00 6c  be  0xa014d9d8
a014d82c:  d6 0c 60 5e  ldub  [ %l1 + 0x5e ], %o3
a014d830:  9a 02 e0 01  add  %o3, 1, %o5
a014d834:  da 2c 60 5e  stb  %o5, [ %l1 + 0x5e ]
a014d838:  a2 0b 60 ff  and  %o5, 0xff, %l1
a014d83c:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a014d840:  80 a4 60 03  cmp  %l1, 3
a014d844:  18 80 00 1c  bgu  0xa014d8b4
a014d848:  a2 10 00 10  mov  %l0, %l1
a014d84c:  de 0e 60 5d  ldub  [ %i1 + 0x5d ], %o7
a014d850:  93 2b e0 02  sll  %o7, 2, %o1
a014d854:  90 02 40 12  add  %o1, %l2, %o0
a014d858:  d4 0c 20 5e  ldub  [ %l0 + 0x5e ], %o2
a014d85c:  d2 0a 00 0a  ldub  [ %o0 + %o2 ], %o1
a014d860:  7f fe 46 44  call  0xa00df170
a014d864:  90 14 e2 98  or  %l3, 0x298, %o0
a014d868:  c2 0c 20 5e  ldub  [ %l0 + 0x5e ], %g1
a014d86c:  80 a0 60 00  cmp  %g1, 0
a014d870:  12 bf ff ee  bne  0xa014d828
a014d874:  80 a0 60 02  cmp  %g1, 2
a014d878:  e0 0e 60 5d  ldub  [ %i1 + 0x5d ], %l0
a014d87c:  92 0c 20 03  and  %l0, 3, %o1
a014d880:  7f ff 1f 81  call  0xa0115684
a014d884:  91 34 20 02  srl  %l0, 2, %o0
a014d888:  92 0a 20 ff  and  %o0, 0xff, %o1
a014d88c:  7f fe 46 39  call  0xa00df170
a014d890:  90 16 22 d0  or  %i0, 0x2d0, %o0
a014d894:  d6 0c 60 5e  ldub  [ %l1 + 0x5e ], %o3
a014d898:  9a 02 e0 01  add  %o3, 1, %o5
a014d89c:  da 2c 60 5e  stb  %o5, [ %l1 + 0x5e ]
a014d8a0:  a2 0b 60 ff  and  %o5, 0xff, %l1
a014d8a4:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a014d8a8:  80 a4 60 03  cmp  %l1, 3
a014d8ac:  08 bf ff e8  bleu  0xa014d84c
a014d8b0:  a2 10 00 10  mov  %l0, %l1
a014d8b4:  7f fe 46 2f  call  0xa00df170
a014d8b8:  90 15 a3 c0  or  %l6, 0x3c0, %o0
a014d8bc:  e8 0e 60 5d  ldub  [ %i1 + 0x5d ], %l4
a014d8c0:  a4 05 20 01  add  %l4, 1, %l2
a014d8c4:  e4 2e 60 5d  stb  %l2, [ %i1 + 0x5d ]
a014d8c8:  b2 0c a0 ff  and  %l2, 0xff, %i1
a014d8cc:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a014d8d0:  80 a6 60 07  cmp  %i1, 7
a014d8d4:  08 bf ff bf  bleu  0xa014d7d0
a014d8d8:  b2 10 00 09  mov  %o1, %i1
a014d8dc:  7f fe 3f cb  call  0xa00dd808
a014d8e0:  90 10 20 00  clr  %o0
a014d8e4:  aa 10 20 01  mov  1, %l5
a014d8e8:  ea 2f 60 7e  stb  %l5, [ %i5 + 0x7e ]
a014d8ec:  10 80 00 c0  b  0xa014dbec
a014d8f0:  c0 27 20 58  clr  [ %i4 + 0x58 ]
a014d8f4:  7f ff 2a 76  call  0xa01182cc
a014d8f8:  90 10 20 00  clr  %o0
a014d8fc:  ae 0a 20 ff  and  %o0, 0xff, %l7
a014d900:  7f ff 2a 73  call  0xa01182cc
a014d904:  90 10 20 01  mov  1, %o0
a014d908:  ac 0a 20 ff  and  %o0, 0xff, %l6
a014d90c:  7f ff 2a 70  call  0xa01182cc
a014d910:  90 10 20 02  mov  2, %o0
a014d914:  aa 0a 20 ff  and  %o0, 0xff, %l5
a014d918:  7f ff 2a 6d  call  0xa01182cc
a014d91c:  90 10 20 03  mov  3, %o0
a014d920:  96 0a 20 ff  and  %o0, 0xff, %o3
a014d924:  90 10 00 17  mov  %l7, %o0
a014d928:  92 10 00 16  mov  %l6, %o1
a014d92c:  7f ff 29 87  call  0xa0117f48
a014d930:  94 10 00 15  mov  %l5, %o2
a014d934:  80 8a 20 ff  btst  0xff, %o0
a014d938:  12 80 00 34  bne  0xa014da08
a014d93c:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a014d940:  31 2a 00 b3  sethi  %hi(0xa802cc00), %i0
a014d944:  fa 0e 20 5c  ldub  [ %i0 + 0x5c ], %i5	! 0xa802cc5c
a014d948:  b2 07 60 01  add  %i5, 1, %i1
a014d94c:  f2 2e 20 5c  stb  %i1, [ %i0 + 0x5c ]
a014d950:  7f ff 2a 21  call  0xa01181d4
a014d954:  01 00 00 00  nop
a014d958:  7f ff 2a 5d  call  0xa01182cc
a014d95c:  90 10 20 00  clr  %o0	! 0x0
a014d960:  80 8a 20 ff  btst  0xff, %o0
a014d964:  12 80 00 a2  bne  0xa014dbec
a014d968:  01 00 00 00  nop
a014d96c:  7f ff 2a 58  call  0xa01182cc
a014d970:  90 10 20 01  mov  1, %o0	! 0x1
a014d974:  80 8a 20 ff  btst  0xff, %o0
a014d978:  12 80 00 9d  bne  0xa014dbec
a014d97c:  01 00 00 00  nop
a014d980:  7f ff 2a 53  call  0xa01182cc
a014d984:  90 10 20 02  mov  2, %o0	! 0x2
a014d988:  80 8a 20 ff  btst  0xff, %o0
a014d98c:  12 80 00 98  bne  0xa014dbec
a014d990:  01 00 00 00  nop
a014d994:  7f ff 2a 4e  call  0xa01182cc
a014d998:  90 10 20 03  mov  3, %o0	! 0x3
a014d99c:  a4 0a 20 ff  and  %o0, 0xff, %l2
a014d9a0:  80 a4 a0 06  cmp  %l2, 6
a014d9a4:  12 80 00 92  bne  0xa014dbec
a014d9a8:  e6 07 20 58  ld  [ %i4 + 0x58 ], %l3
a014d9ac:  b2 04 e0 01  add  %l3, 1, %i1
a014d9b0:  f2 27 20 58  st  %i1, [ %i4 + 0x58 ]
a014d9b4:  39 00 06 9c  sethi  %hi(0x1a7000), %i4
a014d9b8:  7f fe 45 ee  call  0xa00df170
a014d9bc:  91 ef 23 08  restore  %i4, 0x308, %o0
a014d9c0:  f8 0d 20 5d  ldub  [ %l4 + 0x5d ], %i4
a014d9c4:  92 0f 20 03  and  %i4, 3, %o1
a014d9c8:  7f ff 23 44  call  0xa01166d8
a014d9cc:  91 37 20 02  srl  %i4, 2, %o0
a014d9d0:  10 bf ff 4d  b  0xa014d704
a014d9d4:  92 0a 20 ff  and  %o0, 0xff, %o1
a014d9d8:  c2 0d 20 5d  ldub  [ %l4 + 0x5d ], %g1
a014d9dc:  92 08 60 03  and  %g1, 3, %o1
a014d9e0:  7f ff 23 3e  call  0xa01166d8
a014d9e4:  91 30 60 02  srl  %g1, 2, %o0
a014d9e8:  10 bf ff a9  b  0xa014d88c
a014d9ec:  92 0a 20 ff  and  %o0, 0xff, %o1
a014d9f0:  17 00 06 9c  sethi  %hi(0x1a7000), %o3
a014d9f4:  90 12 e2 a0  or  %o3, 0x2a0, %o0	! 0x1a72a0
a014d9f8:  7f fe 45 de  call  0xa00df170
a014d9fc:  93 32 60 02  srl  %o1, 2, %o1
a014da00:  10 bf ff 80  b  0xa014d800
a014da04:  d8 0e 60 5d  ldub  [ %i1 + 0x5d ], %o4
a014da08:  d0 0c 60 5d  ldub  [ %l1 + 0x5d ], %o0
a014da0c:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a014da10:  9e 0a 20 ff  and  %o0, 0xff, %o7
a014da14:  99 2b e0 02  sll  %o7, 2, %o4
a014da18:  96 12 a0 5f  or  %o2, 0x5f, %o3
a014da1c:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a014da20:  94 03 00 0b  add  %o4, %o3, %o2
a014da24:  d2 0c 20 5e  ldub  [ %l0 + 0x5e ], %o1
a014da28:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a014da2c:  98 0a 60 ff  and  %o1, 0xff, %o4
a014da30:  d6 0c a0 5c  ldub  [ %l2 + 0x5c ], %o3
a014da34:  da 0a 80 0c  ldub  [ %o2 + %o4 ], %o5
a014da38:  82 0a e0 ff  and  %o3, 0xff, %g1
a014da3c:  80 a3 40 01  cmp  %o5, %g1
a014da40:  38 80 00 02  bgu,a   0xa014da48
a014da44:  d6 2a 80 0c  stb  %o3, [ %o2 + %o4 ]
a014da48:  82 93 20 00  orcc  %o4, 0, %g1
a014da4c:  22 80 00 1c  be,a   0xa014dabc
a014da50:  90 02 60 01  add  %o1, 1, %o0
a014da54:  80 a0 60 01  cmp  %g1, 1
a014da58:  02 80 00 4a  be  0xa014db80
a014da5c:  80 a0 60 02  cmp  %g1, 2
a014da60:  28 80 00 17  bleu,a   0xa014dabc
a014da64:  90 02 60 01  add  %o1, 1, %o0
a014da68:  80 a3 20 03  cmp  %o4, 3
a014da6c:  32 80 00 16  bne,a   0xa014dac4
a014da70:  c0 2c a0 5c  clrb  [ %l2 + 0x5c ]
a014da74:  80 a3 e0 02  cmp  %o7, 2
a014da78:  28 80 00 0d  bleu,a   0xa014daac
a014da7c:  82 02 20 01  add  %o0, 1, %g1
a014da80:  80 a3 e0 03  cmp  %o7, 3
a014da84:  02 80 00 51  be  0xa014dbc8
a014da88:  80 a3 e0 06  cmp  %o7, 6
a014da8c:  28 80 00 08  bleu,a   0xa014daac
a014da90:  82 02 20 01  add  %o0, 1, %g1
a014da94:  80 a3 e0 07  cmp  %o7, 7
a014da98:  02 80 00 52  be  0xa014dbe0
a014da9c:  80 a3 e0 0a  cmp  %o7, 0xa
a014daa0:  18 80 00 4e  bgu  0xa014dbd8
a014daa4:  80 a3 e0 0b  cmp  %o7, 0xb
a014daa8:  82 02 20 01  add  %o0, 1, %g1
a014daac:  c2 2c 60 5d  stb  %g1, [ %l1 + 0x5d ]
a014dab0:  a2 10 20 02  mov  2, %l1
a014dab4:  10 80 00 03  b  0xa014dac0
a014dab8:  e2 2c 20 5e  stb  %l1, [ %l0 + 0x5e ]
a014dabc:  d0 2c 20 5e  stb  %o0, [ %l0 + 0x5e ]
a014dac0:  c0 2c a0 5c  clrb  [ %l2 + 0x5c ]
a014dac4:  7f ff 2a 02  call  0xa01182cc
a014dac8:  90 10 20 03  mov  3, %o0
a014dacc:  a0 0a 20 ff  and  %o0, 0xff, %l0
a014dad0:  80 a4 20 06  cmp  %l0, 6
a014dad4:  18 80 00 28  bgu  0xa014db74
a014dad8:  90 10 20 03  mov  3, %o0
a014dadc:  7f ff 2a 12  call  0xa0118324
a014dae0:  92 10 20 00  clr  %o1
a014dae4:  30 bf ff 9b  b,a   0xa014d950
a014dae8:  7f fe 45 a2  call  0xa00df170
a014daec:  90 12 62 e0  or  %o1, 0x2e0, %o0
a014daf0:  7f ff 29 ad  call  0xa01181a4
a014daf4:  01 00 00 00  nop
a014daf8:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a014dafc:  c0 2f 60 7e  clrb  [ %i5 + 0x7e ]
a014db00:  c0 2a 20 5d  clrb  [ %o0 + 0x5d ]
a014db04:  d2 0a 20 5d  ldub  [ %o0 + 0x5d ], %o1
a014db08:  98 0a 60 ff  and  %o1, 0xff, %o4
a014db0c:  17 2a 00 b3  sethi  %hi(0xa802cc00), %o3
a014db10:  9b 2b 20 02  sll  %o4, 2, %o5
a014db14:  94 12 e0 5f  or  %o3, 0x5f, %o2
a014db18:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a014db1c:  96 03 40 0a  add  %o5, %o2, %o3
a014db20:  c0 2b 20 5e  clrb  [ %o4 + 0x5e ]
a014db24:  94 10 3f ff  mov  -1, %o2
a014db28:  9e 10 00 0c  mov  %o4, %o7
a014db2c:  e4 0b 20 5e  ldub  [ %o4 + 0x5e ], %l2
a014db30:  a6 04 a0 01  add  %l2, 1, %l3
a014db34:  e6 2b 20 5e  stb  %l3, [ %o4 + 0x5e ]
a014db38:  a0 0c e0 ff  and  %l3, 0xff, %l0
a014db3c:  a2 0c a0 ff  and  %l2, 0xff, %l1
a014db40:  d4 2a c0 11  stb  %o2, [ %o3 + %l1 ]
a014db44:  80 a4 20 03  cmp  %l0, 3
a014db48:  08 bf ff f9  bleu  0xa014db2c
a014db4c:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a014db50:  9a 02 60 01  add  %o1, 1, %o5
a014db54:  a8 0b 60 ff  and  %o5, 0xff, %l4
a014db58:  80 a5 20 07  cmp  %l4, 7
a014db5c:  38 80 00 04  bgu,a   0xa014db6c
a014db60:  c0 2a 20 5d  clrb  [ %o0 + 0x5d ]
a014db64:  10 bf ff e8  b  0xa014db04
a014db68:  da 2a 20 5d  stb  %o5, [ %o0 + 0x5d ]
a014db6c:  10 bf ff 09  b  0xa014d790
a014db70:  c0 2b e0 5e  clrb  [ %o7 + 0x5e ]
a014db74:  7f ff 29 ec  call  0xa0118324
a014db78:  92 10 20 0e  mov  0xe, %o1
a014db7c:  30 bf ff 75  b,a   0xa014d950
a014db80:  80 a3 e0 02  cmp  %o7, 2
a014db84:  08 80 00 12  bleu  0xa014dbcc
a014db88:  92 02 20 01  add  %o0, 1, %o1
a014db8c:  80 a3 e0 03  cmp  %o7, 3
a014db90:  02 80 00 0c  be  0xa014dbc0
a014db94:  80 a3 e0 06  cmp  %o7, 6
a014db98:  28 80 00 0e  bleu,a   0xa014dbd0
a014db9c:  d2 2c 60 5d  stb  %o1, [ %l1 + 0x5d ]
a014dba0:  80 a3 e0 07  cmp  %o7, 7
a014dba4:  02 80 00 07  be  0xa014dbc0
a014dba8:  80 a3 e0 0a  cmp  %o7, 0xa
a014dbac:  28 80 00 09  bleu,a   0xa014dbd0
a014dbb0:  d2 2c 60 5d  stb  %o1, [ %l1 + 0x5d ]
a014dbb4:  80 a3 e0 0b  cmp  %o7, 0xb
a014dbb8:  32 bf ff c3  bne,a   0xa014dac4
a014dbbc:  c0 2c a0 5c  clrb  [ %l2 + 0x5c ]
a014dbc0:  10 bf ff bb  b  0xa014daac
a014dbc4:  82 02 3f fd  add  %o0, -3, %g1
a014dbc8:  92 02 20 01  add  %o0, 1, %o1
a014dbcc:  d2 2c 60 5d  stb  %o1, [ %l1 + 0x5d ]
a014dbd0:  10 bf ff bc  b  0xa014dac0
a014dbd4:  c0 2c 20 5e  clrb  [ %l0 + 0x5e ]
a014dbd8:  32 bf ff bb  bne,a   0xa014dac4
a014dbdc:  c0 2c a0 5c  clrb  [ %l2 + 0x5c ]
a014dbe0:  c0 2c 60 5d  clrb  [ %l1 + 0x5d ]
a014dbe4:  10 bf ff b7  b  0xa014dac0
a014dbe8:  c0 2c 20 5e  clrb  [ %l0 + 0x5e ]
a014dbec:  81 c7 e0 08  ret
a014dbf0:  81 e8 00 00  restore
