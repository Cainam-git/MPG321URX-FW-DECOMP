# leon2s FUN_a00c55c8 0xa00c55c8-0xa00c59e0 (1048 bytes)
a00c55c8:  9d e3 bf 90  save  %sp, -112, %sp
a00c55cc:  b2 06 3f fc  add  %i0, -4, %i1
a00c55d0:  a4 0e 60 ff  and  %i1, 0xff, %l2
a00c55d4:  82 10 20 01  mov  1, %g1
a00c55d8:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c55dc:  c2 2b 62 2a  stb  %g1, [ %o5 + 0x22a ]	! 0xa807d62a
a00c55e0:  ae 10 20 00  clr  %l7
a00c55e4:  b8 10 20 00  clr  %i4
a00c55e8:  ac 10 20 00  clr  %l6
a00c55ec:  ba 10 20 00  clr  %i5
a00c55f0:  b4 10 20 00  clr  %i2
a00c55f4:  b6 10 20 00  clr  %i3
a00c55f8:  90 10 00 12  mov  %l2, %o0
a00c55fc:  92 10 24 0e  mov  0x40e, %o1
a00c5600:  94 10 20 10  mov  0x10, %o2
a00c5604:  40 3b c5 a5  call  0xa0fb6c98
a00c5608:  96 10 20 01  mov  1, %o3
a00c560c:  90 10 00 12  mov  %l2, %o0
a00c5610:  40 3b c5 6a  call  0xa0fb6bb8
a00c5614:  92 10 24 0e  mov  0x40e, %o1
a00c5618:  80 8a 20 10  btst  0x10, %o0
a00c561c:  12 bf ff fd  bne  0xa00c5610
a00c5620:  90 10 00 12  mov  %l2, %o0
a00c5624:  92 10 24 00  mov  0x400, %o1
a00c5628:  40 3b c5 76  call  0xa0fb6c00
a00c562c:  94 10 20 0b  mov  0xb, %o2
a00c5630:  90 10 00 12  mov  %l2, %o0
a00c5634:  92 10 24 03  mov  0x403, %o1
a00c5638:  40 3b c5 72  call  0xa0fb6c00
a00c563c:  94 10 20 15  mov  0x15, %o2
a00c5640:  90 10 00 12  mov  %l2, %o0
a00c5644:  92 10 24 02  mov  0x402, %o1
a00c5648:  40 3b c5 6e  call  0xa0fb6c00
a00c564c:  94 10 20 40  mov  0x40, %o2
a00c5650:  90 10 00 12  mov  %l2, %o0
a00c5654:  92 10 20 e9  mov  0xe9, %o1
a00c5658:  40 3b c5 6a  call  0xa0fb6c00
a00c565c:  94 10 20 0f  mov  0xf, %o2
a00c5660:  90 10 00 12  mov  %l2, %o0
a00c5664:  40 3b c5 55  call  0xa0fb6bb8
a00c5668:  92 10 20 e9  mov  0xe9, %o1
a00c566c:  80 8a 20 0f  btst  0xf, %o0
a00c5670:  12 bf ff fd  bne  0xa00c5664
a00c5674:  90 10 00 12  mov  %l2, %o0
a00c5678:  a8 10 20 00  clr  %l4
a00c567c:  82 0e 20 ff  and  %i0, 0xff, %g1
a00c5680:  c2 27 bf f4  st  %g1, [ %fp + -12 ]
a00c5684:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c5688:  83 28 60 04  sll  %g1, 4, %g1
a00c568c:  9a 13 61 c8  or  %o5, 0x1c8, %o5
a00c5690:  82 00 40 0d  add  %g1, %o5, %g1
a00c5694:  c2 08 60 04  ldub  [ %g1 + 4 ], %g1
a00c5698:  a2 0d 20 ff  and  %l4, 0xff, %l1
a00c569c:  83 38 40 11  sra  %g1, %l1, %g1
a00c56a0:  82 18 60 01  xor  %g1, 1, %g1
a00c56a4:  a0 88 60 01  andcc  %g1, 1, %l0
a00c56a8:  32 80 00 4b  bne,a   0xa00c57d4
a00c56ac:  a8 05 20 01  inc  %l4
a00c56b0:  15 00 00 10  sethi  %hi(0x4000), %o2
a00c56b4:  94 12 a0 15  or  %o2, 0x15, %o2	! 0x4015
a00c56b8:  90 10 00 11  mov  %l1, %o0
a00c56bc:  40 00 0c 4b  call  0xa00c87e8
a00c56c0:  92 10 20 0b  mov  0xb, %o1
a00c56c4:  82 04 40 11  add  %l1, %l1, %g1
a00c56c8:  82 00 40 11  add  %g1, %l1, %g1
a00c56cc:  2b 2a 01 e2  sethi  %hi(0xa8078800), %l5
a00c56d0:  9a 15 63 b0  or  %l5, 0x3b0, %o5	! 0xa8078bb0
a00c56d4:  83 28 60 03  sll  %g1, 3, %g1
a00c56d8:  82 00 40 0d  add  %g1, %o5, %g1
a00c56dc:  da 08 60 03  ldub  [ %g1 + 3 ], %o5
a00c56e0:  83 2b 60 02  sll  %o5, 2, %g1
a00c56e4:  82 00 40 0d  add  %g1, %o5, %g1
a00c56e8:  80 a4 00 01  cmp  %l0, %g1
a00c56ec:  a6 10 20 00  clr  %l3
a00c56f0:  16 80 00 19  bge  0xa00c5754
a00c56f4:  92 10 20 01  mov  1, %o1
a00c56f8:  40 00 08 1e  call  0xa00c7770
a00c56fc:  90 10 00 11  mov  %l1, %o0
a00c5700:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00c5704:  90 10 00 12  mov  %l2, %o0
a00c5708:  92 10 20 e8  mov  0xe8, %o1
a00c570c:  40 3b c5 3d  call  0xa0fb6c00
a00c5710:  94 10 00 10  mov  %l0, %o2
a00c5714:  90 10 00 12  mov  %l2, %o0
a00c5718:  94 10 00 10  mov  %l0, %o2
a00c571c:  40 3b c5 39  call  0xa0fb6c00
a00c5720:  92 10 24 01  mov  0x401, %o1
a00c5724:  82 04 40 11  add  %l1, %l1, %g1
a00c5728:  82 00 40 11  add  %g1, %l1, %g1
a00c572c:  9a 15 63 b0  or  %l5, 0x3b0, %o5
a00c5730:  83 28 60 03  sll  %g1, 3, %g1
a00c5734:  82 00 40 0d  add  %g1, %o5, %g1
a00c5738:  da 08 60 03  ldub  [ %g1 + 3 ], %o5
a00c573c:  83 2b 60 02  sll  %o5, 2, %g1
a00c5740:  82 00 40 0d  add  %g1, %o5, %g1
a00c5744:  a6 04 e0 01  inc  %l3
a00c5748:  9a 0c e0 ff  and  %l3, 0xff, %o5
a00c574c:  10 bf ff e9  b  0xa00c56f0
a00c5750:  80 a3 40 01  cmp  %o5, %g1
a00c5754:  a0 0d 20 ff  and  %l4, 0xff, %l0
a00c5758:  92 10 20 00  clr  %o1
a00c575c:  94 10 20 00  clr  %o2
a00c5760:  40 00 0c 22  call  0xa00c87e8
a00c5764:  90 10 00 10  mov  %l0, %o0
a00c5768:  9a 04 00 10  add  %l0, %l0, %o5
a00c576c:  9a 03 40 10  add  %o5, %l0, %o5
a00c5770:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00c5774:  9b 2b 60 03  sll  %o5, 3, %o5
a00c5778:  82 10 63 b0  or  %g1, 0x3b0, %g1
a00c577c:  94 03 40 01  add  %o5, %g1, %o2
a00c5780:  d2 0a a0 04  ldub  [ %o2 + 4 ], %o1
a00c5784:  d8 0a a0 03  ldub  [ %o2 + 3 ], %o4
a00c5788:  d6 0a a0 05  ldub  [ %o2 + 5 ], %o3
a00c578c:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00c5790:  82 0f 20 ff  and  %i4, 0xff, %g1
a00c5794:  80 a3 40 01  cmp  %o5, %g1
a00c5798:  ae 05 c0 0c  add  %l7, %o4, %l7
a00c579c:  08 80 00 03  bleu  0xa00c57a8
a00c57a0:  ac 15 80 0b  or  %l6, %o3, %l6
a00c57a4:  b8 10 00 09  mov  %o1, %i4
a00c57a8:  c2 0a a0 02  ldub  [ %o2 + 2 ], %g1
a00c57ac:  da 0a a0 06  ldub  [ %o2 + 6 ], %o5
a00c57b0:  d8 0a a0 08  ldub  [ %o2 + 8 ], %o4
a00c57b4:  d6 0a a0 07  ldub  [ %o2 + 7 ], %o3
a00c57b8:  80 88 60 10  btst  0x10, %g1
a00c57bc:  ba 17 40 0d  or  %i5, %o5, %i5
a00c57c0:  b4 16 80 0c  or  %i2, %o4, %i2
a00c57c4:  02 80 00 03  be  0xa00c57d0
a00c57c8:  b6 16 c0 0b  or  %i3, %o3, %i3
a00c57cc:  b6 10 20 01  mov  1, %i3
a00c57d0:  a8 05 20 01  inc  %l4
a00c57d4:  82 0d 20 ff  and  %l4, 0xff, %g1
a00c57d8:  80 a0 60 02  cmp  %g1, 2
a00c57dc:  08 bf ff a9  bleu  0xa00c5680
a00c57e0:  82 0e 20 ff  and  %i0, 0xff, %g1
a00c57e4:  80 8d e0 80  btst  0x80, %l7
a00c57e8:  32 80 00 02  bne,a   0xa00c57f0
a00c57ec:  ac 10 20 01  mov  1, %l6
a00c57f0:  b0 0e 60 ff  and  %i1, 0xff, %i0
a00c57f4:  96 10 20 01  mov  1, %o3
a00c57f8:  90 10 00 18  mov  %i0, %o0
a00c57fc:  92 10 20 30  mov  0x30, %o1
a00c5800:  40 3b c5 26  call  0xa0fb6c98
a00c5804:  94 10 20 80  mov  0x80, %o2
a00c5808:  94 0d a0 ff  and  %l6, 0xff, %o2
a00c580c:  95 2a a0 07  sll  %o2, 7, %o2
a00c5810:  94 12 80 17  or  %o2, %l7, %o2
a00c5814:  94 0a a0 ff  and  %o2, 0xff, %o2
a00c5818:  90 10 00 18  mov  %i0, %o0
a00c581c:  40 3b c4 f9  call  0xa0fb6c00
a00c5820:  92 10 22 aa  mov  0x2aa, %o1
a00c5824:  94 0f 60 ff  and  %i5, 0xff, %o2
a00c5828:  95 2a a0 03  sll  %o2, 3, %o2
a00c582c:  94 12 80 1c  or  %o2, %i4, %o2
a00c5830:  94 0a a0 ff  and  %o2, 0xff, %o2
a00c5834:  90 10 00 18  mov  %i0, %o0
a00c5838:  40 3b c4 f2  call  0xa0fb6c00
a00c583c:  92 10 22 ab  mov  0x2ab, %o1
a00c5840:  90 10 00 18  mov  %i0, %o0
a00c5844:  92 10 20 30  mov  0x30, %o1
a00c5848:  94 10 20 80  mov  0x80, %o2
a00c584c:  40 3b c5 13  call  0xa0fb6c98
a00c5850:  96 10 20 00  clr  %o3
a00c5854:  a0 0d e0 ff  and  %l7, 0xff, %l0
a00c5858:  80 a4 20 1f  cmp  %l0, 0x1f
a00c585c:  38 80 00 02  bgu,a   0xa00c5864
a00c5860:  ac 10 20 01  mov  1, %l6
a00c5864:  a6 0f 20 ff  and  %i4, 0xff, %l3
a00c5868:  80 a4 e0 04  cmp  %l3, 4
a00c586c:  38 80 00 02  bgu,a   0xa00c5874
a00c5870:  ba 10 20 01  mov  1, %i5
a00c5874:  82 0c 20 10  and  %l0, 0x10, %g1
a00c5878:  83 38 60 04  sra  %g1, 4, %g1
a00c587c:  a6 04 c0 13  add  %l3, %l3, %l3
a00c5880:  a6 14 c0 01  or  %l3, %g1, %l3
a00c5884:  a6 0c e0 ff  and  %l3, 0xff, %l3
a00c5888:  90 10 00 18  mov  %i0, %o0
a00c588c:  92 10 24 01  mov  0x401, %o1
a00c5890:  40 3b c4 dc  call  0xa0fb6c00
a00c5894:  94 10 00 13  mov  %l3, %o2
a00c5898:  a0 0c 20 0f  and  %l0, 0xf, %l0
a00c589c:  82 0d a0 ff  and  %l6, 0xff, %g1
a00c58a0:  83 28 60 03  sll  %g1, 3, %g1
a00c58a4:  a1 2c 20 04  sll  %l0, 4, %l0
a00c58a8:  a0 14 00 01  or  %l0, %g1, %l0
a00c58ac:  9a 0f 60 ff  and  %i5, 0xff, %o5
a00c58b0:  9b 2b 60 02  sll  %o5, 2, %o5
a00c58b4:  82 0e a0 ff  and  %i2, 0xff, %g1
a00c58b8:  82 00 40 01  add  %g1, %g1, %g1
a00c58bc:  a0 14 00 0d  or  %l0, %o5, %l0
a00c58c0:  a0 14 00 01  or  %l0, %g1, %l0
a00c58c4:  a0 14 00 1b  or  %l0, %i3, %l0
a00c58c8:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00c58cc:  90 10 00 18  mov  %i0, %o0
a00c58d0:  92 10 24 01  mov  0x401, %o1
a00c58d4:  40 3b c4 cb  call  0xa0fb6c00
a00c58d8:  94 10 00 10  mov  %l0, %o2
a00c58dc:  da 07 bf f4  ld  [ %fp + -12 ], %o5
a00c58e0:  23 2a 01 e3  sethi  %hi(0xa8078c00), %l1
a00c58e4:  a5 2b 60 02  sll  %o5, 2, %l2
a00c58e8:  a2 14 60 60  or  %l1, 0x60, %l1
a00c58ec:  d4 14 40 12  lduh  [ %l1 + %l2 ], %o2
a00c58f0:  94 0a a0 ff  and  %o2, 0xff, %o2
a00c58f4:  90 10 00 18  mov  %i0, %o0
a00c58f8:  40 3b c4 c2  call  0xa0fb6c00
a00c58fc:  92 10 24 01  mov  0x401, %o1
a00c5900:  82 04 40 12  add  %l1, %l2, %g1
a00c5904:  d4 08 60 02  ldub  [ %g1 + 2 ], %o2
a00c5908:  90 10 00 18  mov  %i0, %o0
a00c590c:  40 3b c4 bd  call  0xa0fb6c00
a00c5910:  92 10 24 01  mov  0x401, %o1
a00c5914:  d4 04 40 12  ld  [ %l1 + %l2 ], %o2
a00c5918:  94 0a a0 ff  and  %o2, 0xff, %o2
a00c591c:  90 10 00 18  mov  %i0, %o0
a00c5920:  40 3b c4 b8  call  0xa0fb6c00
a00c5924:  92 10 24 01  mov  0x401, %o1
a00c5928:  90 10 00 18  mov  %i0, %o0
a00c592c:  92 10 24 01  mov  0x401, %o1
a00c5930:  40 3b c4 b4  call  0xa0fb6c00
a00c5934:  94 10 20 80  mov  0x80, %o2
a00c5938:  90 10 00 18  mov  %i0, %o0
a00c593c:  92 10 24 00  mov  0x400, %o1
a00c5940:  40 3b c4 b0  call  0xa0fb6c00
a00c5944:  94 10 20 0b  mov  0xb, %o2
a00c5948:  90 10 00 18  mov  %i0, %o0
a00c594c:  92 10 24 03  mov  0x403, %o1
a00c5950:  40 3b c4 ac  call  0xa0fb6c00
a00c5954:  94 10 20 00  clr  %o2
a00c5958:  90 10 00 18  mov  %i0, %o0
a00c595c:  92 10 24 02  mov  0x402, %o1
a00c5960:  40 3b c4 a8  call  0xa0fb6c00
a00c5964:  94 10 20 80  mov  0x80, %o2
a00c5968:  90 10 00 18  mov  %i0, %o0
a00c596c:  94 10 00 13  mov  %l3, %o2
a00c5970:  40 3b c4 a4  call  0xa0fb6c00
a00c5974:  92 10 24 01  mov  0x401, %o1
a00c5978:  90 10 00 18  mov  %i0, %o0
a00c597c:  94 10 00 10  mov  %l0, %o2
a00c5980:  40 3b c4 a0  call  0xa0fb6c00
a00c5984:  92 10 24 01  mov  0x401, %o1
a00c5988:  d4 14 40 12  lduh  [ %l1 + %l2 ], %o2
a00c598c:  94 0a a0 ff  and  %o2, 0xff, %o2
a00c5990:  90 10 00 18  mov  %i0, %o0
a00c5994:  40 3b c4 9b  call  0xa0fb6c00
a00c5998:  92 10 24 01  mov  0x401, %o1
a00c599c:  82 04 40 12  add  %l1, %l2, %g1
a00c59a0:  d4 08 60 02  ldub  [ %g1 + 2 ], %o2
a00c59a4:  90 10 00 18  mov  %i0, %o0
a00c59a8:  40 3b c4 96  call  0xa0fb6c00
a00c59ac:  92 10 24 01  mov  0x401, %o1
a00c59b0:  d4 04 40 12  ld  [ %l1 + %l2 ], %o2
a00c59b4:  90 10 00 18  mov  %i0, %o0
a00c59b8:  94 0a a0 ff  and  %o2, 0xff, %o2
a00c59bc:  40 3b c4 91  call  0xa0fb6c00
a00c59c0:  92 10 24 01  mov  0x401, %o1
a00c59c4:  c2 04 40 12  ld  [ %l1 + %l2 ], %g1
a00c59c8:  82 00 60 01  inc  %g1
a00c59cc:  c2 24 40 12  st  %g1, [ %l1 + %l2 ]
a00c59d0:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c59d4:  c0 28 62 2a  clrb  [ %g1 + 0x22a ]	! 0xa807d62a
a00c59d8:  81 c7 e0 08  ret
a00c59dc:  81 e8 00 00  restore
