# leon2s DRV_HDMI_EQScan_FSM_PHY_R_Turning 0xa007769c-0xa007796c (720 bytes)
a007769c:  9d e3 bf 98  save  %sp, -104, %sp
a00776a0:  90 0e 20 ff  and  %i0, 0xff, %o0
a00776a4:  17 2a 01 ea  sethi  %hi(0xa807a800), %o3
a00776a8:  9a 12 e1 f0  or  %o3, 0x1f0, %o5	! 0xa807a9f0
a00776ac:  82 02 00 08  add  %o0, %o0, %g1
a00776b0:  98 5a 28 98  smul  %o0, 0x898, %o4
a00776b4:  98 03 00 0d  add  %o4, %o5, %o4
a00776b8:  82 00 40 08  add  %g1, %o0, %g1
a00776bc:  29 2a 01 f3  sethi  %hi(0xa807cc00), %l4
a00776c0:  9a 15 20 c4  or  %l4, 0xc4, %o5	! 0xa807ccc4
a00776c4:  83 28 60 02  sll  %g1, 2, %g1
a00776c8:  82 00 40 0d  add  %g1, %o5, %g1
a00776cc:  da 0b 20 30  ldub  [ %o4 + 0x30 ], %o5
a00776d0:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a00776d4:  9a 03 60 01  inc  %o5
a00776d8:  80 a0 60 01  cmp  %g1, 1
a00776dc:  12 80 00 09  bne  0xa0077700
a00776e0:  da 2b 20 30  stb  %o5, [ %o4 + 0x30 ]
a00776e4:  82 0b 60 ff  and  %o5, 0xff, %g1
a00776e8:  80 a0 60 05  cmp  %g1, 5
a00776ec:  18 80 00 06  bgu  0xa0077704
a00776f0:  27 2a 01 e1  sethi  %hi(0xa8078400), %l3
a00776f4:  7f ff f5 d1  call  0xa0074e38
a00776f8:  b0 10 20 00  clr  %i0
a00776fc:  30 80 00 9a  b,a   0xa0077964
a0077700:  27 2a 01 e1  sethi  %hi(0xa8078400), %l3
a0077704:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1	! 0xa8078634
a0077708:  80 88 60 02  btst  2, %g1
a007770c:  02 80 00 5f  be  0xa0077888
a0077710:  a2 10 20 00  clr  %l1
a0077714:  9a 12 e1 f0  or  %o3, 0x1f0, %o5
a0077718:  82 5a 28 98  smul  %o0, 0x898, %g1
a007771c:  92 06 20 41  add  %i0, 0x41, %o1
a0077720:  82 00 40 0d  add  %g1, %o5, %g1
a0077724:  93 2a 60 18  sll  %o1, 0x18, %o1
a0077728:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a007772c:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a0077730:  d6 08 60 30  ldub  [ %g1 + 0x30 ], %o3
a0077734:  90 12 21 f8  or  %o0, 0x1f8, %o0
a0077738:  93 3a 60 18  sra  %o1, 0x18, %o1
a007773c:  7f ff ee 42  call  0xa0073044
a0077740:  94 12 a1 10  or  %o2, 0x110, %o2
a0077744:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1
a0077748:  80 88 60 02  btst  2, %g1
a007774c:  02 80 00 4f  be  0xa0077888
a0077750:  a2 10 20 00  clr  %l1
a0077754:  40 00 ea 44  call  0xa00b2064
a0077758:  01 00 00 00  nop
a007775c:  94 10 00 08  mov  %o0, %o2
a0077760:  92 06 20 41  add  %i0, 0x41, %o1
a0077764:  93 2a 60 18  sll  %o1, 0x18, %o1
a0077768:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a007776c:  90 12 21 88  or  %o0, 0x188, %o0	! 0xa0067188
a0077770:  7f ff ee 35  call  0xa0073044
a0077774:  93 3a 60 18  sra  %o1, 0x18, %o1
a0077778:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1
a007777c:  80 88 60 02  btst  2, %g1
a0077780:  02 80 00 41  be  0xa0077884
a0077784:  23 00 00 04  sethi  %hi(0x1000), %l1
a0077788:  a4 0e 20 ff  and  %i0, 0xff, %l2
a007778c:  92 14 61 78  or  %l1, 0x178, %o1
a0077790:  40 00 be e1  call  0xa00a7314
a0077794:  90 10 00 12  mov  %l2, %o0
a0077798:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a007779c:  82 10 63 00  or  %g1, 0x300, %g1	! 0xffff00
a00777a0:  a0 0a 00 01  and  %o0, %g1, %l0
a00777a4:  92 14 61 78  or  %l1, 0x178, %o1
a00777a8:  40 00 be db  call  0xa00a7314
a00777ac:  90 10 00 12  mov  %l2, %o0
a00777b0:  96 0a 20 0f  and  %o0, 0xf, %o3
a00777b4:  92 06 20 41  add  %i0, 0x41, %o1
a00777b8:  a1 34 20 08  srl  %l0, 8, %l0
a00777bc:  93 2a 60 18  sll  %o1, 0x18, %o1
a00777c0:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a00777c4:  90 12 21 b8  or  %o0, 0x1b8, %o0	! 0xa00671b8
a00777c8:  93 3a 60 18  sra  %o1, 0x18, %o1
a00777cc:  7f ff ee 1e  call  0xa0073044
a00777d0:  94 10 00 10  mov  %l0, %o2
a00777d4:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1
a00777d8:  80 88 60 02  btst  2, %g1
a00777dc:  02 80 00 2a  be  0xa0077884
a00777e0:  a2 04 64 00  add  %l1, 0x400, %l1
a00777e4:  92 14 61 78  or  %l1, 0x178, %o1
a00777e8:  40 00 be cb  call  0xa00a7314
a00777ec:  90 10 00 12  mov  %l2, %o0
a00777f0:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a00777f4:  82 10 63 00  or  %g1, 0x300, %g1	! 0xffff00
a00777f8:  a0 0a 00 01  and  %o0, %g1, %l0
a00777fc:  92 14 61 78  or  %l1, 0x178, %o1
a0077800:  40 00 be c5  call  0xa00a7314
a0077804:  90 10 00 12  mov  %l2, %o0
a0077808:  96 0a 20 0f  and  %o0, 0xf, %o3
a007780c:  92 06 20 41  add  %i0, 0x41, %o1
a0077810:  a1 34 20 08  srl  %l0, 8, %l0
a0077814:  93 2a 60 18  sll  %o1, 0x18, %o1
a0077818:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a007781c:  90 12 21 f0  or  %o0, 0x1f0, %o0	! 0xa00671f0
a0077820:  93 3a 60 18  sra  %o1, 0x18, %o1
a0077824:  7f ff ee 08  call  0xa0073044
a0077828:  94 10 00 10  mov  %l0, %o2
a007782c:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1
a0077830:  80 88 60 02  btst  2, %g1
a0077834:  02 80 00 14  be  0xa0077884
a0077838:  a2 04 64 00  add  %l1, 0x400, %l1
a007783c:  92 14 61 78  or  %l1, 0x178, %o1
a0077840:  40 00 be b5  call  0xa00a7314
a0077844:  90 10 00 12  mov  %l2, %o0
a0077848:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a007784c:  82 10 63 00  or  %g1, 0x300, %g1	! 0xffff00
a0077850:  a0 0a 00 01  and  %o0, %g1, %l0
a0077854:  92 14 61 78  or  %l1, 0x178, %o1
a0077858:  40 00 be af  call  0xa00a7314
a007785c:  90 10 00 12  mov  %l2, %o0
a0077860:  92 06 20 41  add  %i0, 0x41, %o1
a0077864:  96 0a 20 0f  and  %o0, 0xf, %o3
a0077868:  a1 34 20 08  srl  %l0, 8, %l0
a007786c:  93 2a 60 18  sll  %o1, 0x18, %o1
a0077870:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a0077874:  90 12 22 28  or  %o0, 0x228, %o0	! 0xa0067228
a0077878:  93 3a 60 18  sra  %o1, 0x18, %o1
a007787c:  7f ff ed f2  call  0xa0073044
a0077880:  94 10 00 10  mov  %l0, %o2
a0077884:  a2 10 20 00  clr  %l1
a0077888:  a0 0c 60 ff  and  %l1, 0xff, %l0
a007788c:  9a 04 00 10  add  %l0, %l0, %o5
a0077890:  90 0e 20 ff  and  %i0, 0xff, %o0
a0077894:  80 a4 20 02  cmp  %l0, 2
a0077898:  18 80 00 07  bgu  0xa00778b4
a007789c:  96 10 20 00  clr  %o3
a00778a0:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00778a4:  82 10 63 78  or  %g1, 0x378, %g1	! 0xa00b3b78
a00778a8:  40 00 be 9b  call  0xa00a7314
a00778ac:  d2 10 40 0d  lduh  [ %g1 + %o5 ], %o1
a00778b0:  96 0a 20 0f  and  %o0, 0xf, %o3
a00778b4:  96 0a e0 ff  and  %o3, 0xff, %o3
a00778b8:  80 a2 e0 07  cmp  %o3, 7
a00778bc:  38 80 00 19  bgu,a   0xa0077920
a00778c0:  a2 04 60 01  inc  %l1
a00778c4:  92 06 20 41  add  %i0, 0x41, %o1
a00778c8:  93 2a 60 18  sll  %o1, 0x18, %o1
a00778cc:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1
a00778d0:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a00778d4:  80 88 60 02  btst  2, %g1
a00778d8:  93 3a 60 18  sra  %o1, 0x18, %o1
a00778dc:  94 10 00 10  mov  %l0, %o2
a00778e0:  02 80 00 04  be  0xa00778f0
a00778e4:  90 12 22 60  or  %o0, 0x260, %o0
a00778e8:  7f ff ed d7  call  0xa0073044
a00778ec:  01 00 00 00  nop
a00778f0:  82 0c 60 ff  and  %l1, 0xff, %g1
a00778f4:  9a 00 40 01  add  %g1, %g1, %o5
a00778f8:  80 a0 60 02  cmp  %g1, 2
a00778fc:  90 10 20 01  mov  1, %o0
a0077900:  92 10 20 10  mov  0x10, %o1
a0077904:  18 80 00 06  bgu  0xa007791c
a0077908:  94 0e 20 ff  and  %i0, 0xff, %o2
a007790c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0077910:  82 10 63 04  or  %g1, 0x304, %g1	! 0xa00b3b04
a0077914:  40 00 be c4  call  0xa00a7424
a0077918:  d6 10 40 0d  lduh  [ %g1 + %o5 ], %o3
a007791c:  a2 04 60 01  inc  %l1
a0077920:  82 0c 60 ff  and  %l1, 0xff, %g1
a0077924:  80 a0 60 02  cmp  %g1, 2
a0077928:  08 bf ff d9  bleu  0xa007788c
a007792c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a0077930:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0077934:  98 03 40 0d  add  %o5, %o5, %o4
a0077938:  98 03 00 0d  add  %o4, %o5, %o4
a007793c:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a0077940:  82 10 61 f0  or  %g1, 0x1f0, %g1	! 0xa807a9f0
a0077944:  9a 5b 68 98  smul  %o5, 0x898, %o5
a0077948:  9a 03 40 01  add  %o5, %g1, %o5
a007794c:  96 15 20 c4  or  %l4, 0xc4, %o3
a0077950:  99 2b 20 02  sll  %o4, 2, %o4
a0077954:  82 10 20 0b  mov  0xb, %g1
a0077958:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a007795c:  c0 2b 60 30  clrb  [ %o5 + 0x30 ]
a0077960:  b0 10 20 00  clr  %i0
a0077964:  81 c7 e0 08  ret
a0077968:  81 e8 00 00  restore
