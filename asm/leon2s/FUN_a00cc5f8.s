# leon2s FUN_a00cc5f8 0xa00cc5f8-0xa00cc834 (572 bytes)
a00cc5f8:  9d e3 bf 98  save  %sp, -104, %sp
a00cc5fc:  a4 0e 20 ff  and  %i0, 0xff, %l2
a00cc600:  82 04 80 12  add  %l2, %l2, %g1
a00cc604:  82 00 40 12  add  %g1, %l2, %g1
a00cc608:  a1 28 60 03  sll  %g1, 3, %l0
a00cc60c:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00cc610:  2b 2a 01 e2  sethi  %hi(0xa8078800), %l5
a00cc614:  a6 15 63 b0  or  %l5, 0x3b0, %l3	! 0xa8078bb0
a00cc618:  a8 10 63 ff  or  %g1, 0x3ff, %l4
a00cc61c:  c2 04 c0 10  ld  [ %l3 + %l0 ], %g1
a00cc620:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cc624:  82 08 40 14  and  %g1, %l4, %g1
a00cc628:  82 10 40 0d  or  %g1, %o5, %g1
a00cc62c:  9b 30 60 1c  srl  %g1, 0x1c, %o5
a00cc630:  80 8b 60 01  btst  1, %o5
a00cc634:  02 80 00 7e  be  0xa00cc82c
a00cc638:  c2 24 c0 10  st  %g1, [ %l3 + %l0 ]
a00cc63c:  23 2a 01 f4  sethi  %hi(0xa807d000), %l1
a00cc640:  90 10 00 12  mov  %l2, %o0
a00cc644:  7f ff f4 55  call  0xa00c9798
a00cc648:  92 14 62 50  or  %l1, 0x250, %o1
a00cc64c:  80 8a 20 ff  btst  0xff, %o0
a00cc650:  32 80 00 0b  bne,a   0xa00cc67c
a00cc654:  c2 04 c0 10  ld  [ %l3 + %l0 ], %g1
a00cc658:  82 14 62 50  or  %l1, 0x250, %g1
a00cc65c:  d8 08 60 01  ldub  [ %g1 + 1 ], %o4
a00cc660:  82 0b 20 03  and  %o4, 3, %g1
a00cc664:  83 28 60 08  sll  %g1, 8, %g1
a00cc668:  da 0c 62 50  ldub  [ %l1 + 0x250 ], %o5
a00cc66c:  80 8b 20 0c  btst  0xc, %o4
a00cc670:  02 80 00 05  be  0xa00cc684
a00cc674:  82 00 40 0d  add  %g1, %o5, %g1
a00cc678:  c2 04 c0 10  ld  [ %l3 + %l0 ], %g1
a00cc67c:  10 80 00 08  b  0xa00cc69c
a00cc680:  82 08 40 14  and  %g1, %l4, %g1
a00cc684:  83 28 60 10  sll  %g1, 0x10, %g1
a00cc688:  80 a0 60 00  cmp  %g1, 0
a00cc68c:  12 80 00 06  bne  0xa00cc6a4
a00cc690:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00cc694:  c2 04 c0 10  ld  [ %l3 + %l0 ], %g1
a00cc698:  82 10 40 0d  or  %g1, %o5, %g1
a00cc69c:  10 80 00 64  b  0xa00cc82c
a00cc6a0:  c2 24 c0 10  st  %g1, [ %l3 + %l0 ]
a00cc6a4:  90 10 00 12  mov  %l2, %o0
a00cc6a8:  92 10 20 0e  mov  0xe, %o1
a00cc6ac:  7f ff f0 4f  call  0xa00c87e8
a00cc6b0:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cc6b4:  a2 10 20 00  clr  %l1
a00cc6b8:  90 10 00 12  mov  %l2, %o0
a00cc6bc:  7f ff ec 2d  call  0xa00c7770
a00cc6c0:  92 10 20 01  mov  1, %o1
a00cc6c4:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00cc6c8:  a2 04 60 01  inc  %l1
a00cc6cc:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00cc6d0:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00cc6d4:  82 10 60 88  or  %g1, 0x88, %g1
a00cc6d8:  80 a3 60 1f  cmp  %o5, 0x1f
a00cc6dc:  08 bf ff f7  bleu  0xa00cc6b8
a00cc6e0:  d0 28 40 10  stb  %o0, [ %g1 + %l0 ]
a00cc6e4:  90 10 00 12  mov  %l2, %o0
a00cc6e8:  92 10 20 74  mov  0x74, %o1
a00cc6ec:  94 10 20 80  mov  0x80, %o2
a00cc6f0:  7f ff ee 56  call  0xa00c8048
a00cc6f4:  96 10 20 21  mov  0x21, %o3
a00cc6f8:  80 8a 20 ff  btst  0xff, %o0
a00cc6fc:  12 80 00 0b  bne  0xa00cc728
a00cc700:  9a 04 80 12  add  %l2, %l2, %o5
a00cc704:  21 2a 01 f3  sethi  %hi(0xa807cc00), %l0
a00cc708:  90 10 00 12  mov  %l2, %o0
a00cc70c:  92 14 22 50  or  %l0, 0x250, %o1
a00cc710:  7f ff ee ba  call  0xa00c81f8
a00cc714:  94 10 20 21  mov  0x21, %o2
a00cc718:  80 8a 20 ff  btst  0xff, %o0
a00cc71c:  02 80 00 0e  be  0xa00cc754
a00cc720:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cc724:  9a 04 80 12  add  %l2, %l2, %o5
a00cc728:  9a 03 40 12  add  %o5, %l2, %o5
a00cc72c:  96 15 63 b0  or  %l5, 0x3b0, %o3
a00cc730:  9b 2b 60 03  sll  %o5, 3, %o5
a00cc734:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00cc738:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cc73c:  82 2b 00 01  andn  %o4, %g1, %g1
a00cc740:  10 80 00 3b  b  0xa00cc82c
a00cc744:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cc748:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cc74c:  10 80 00 29  b  0xa00cc7f0
a00cc750:  82 2b 40 01  andn  %o5, %g1, %g1
a00cc754:  96 10 61 88  or  %g1, 0x188, %o3
a00cc758:  92 14 22 50  or  %l0, 0x250, %o1
a00cc75c:  a2 10 20 00  clr  %l1
a00cc760:  98 0c 60 ff  and  %l1, 0xff, %o4
a00cc764:  82 03 00 09  add  %o4, %o1, %g1
a00cc768:  a2 04 60 01  inc  %l1
a00cc76c:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a00cc770:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00cc774:  80 a3 60 1f  cmp  %o5, 0x1f
a00cc778:  08 bf ff fa  bleu  0xa00cc760
a00cc77c:  c2 2a c0 0c  stb  %g1, [ %o3 + %o4 ]
a00cc780:  82 04 80 12  add  %l2, %l2, %g1
a00cc784:  90 00 40 12  add  %g1, %l2, %o0
a00cc788:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00cc78c:  94 10 60 88  or  %g1, 0x88, %o2	! 0xa807d088
a00cc790:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cc794:  96 10 61 88  or  %g1, 0x188, %o3	! 0xa807cd88
a00cc798:  a2 10 20 00  clr  %l1
a00cc79c:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cc7a0:  da 0a c0 01  ldub  [ %o3 + %g1 ], %o5
a00cc7a4:  a2 04 60 01  inc  %l1
a00cc7a8:  c2 0a 80 01  ldub  [ %o2 + %g1 ], %g1
a00cc7ac:  80 a0 40 0d  cmp  %g1, %o5
a00cc7b0:  02 80 00 12  be  0xa00cc7f8
a00cc7b4:  98 0c 60 ff  and  %l1, 0xff, %o4
a00cc7b8:  96 15 63 b0  or  %l5, 0x3b0, %o3
a00cc7bc:  91 2a 20 03  sll  %o0, 3, %o0
a00cc7c0:  82 02 00 0b  add  %o0, %o3, %g1
a00cc7c4:  da 00 60 10  ld  [ %g1 + 0x10 ], %o5
a00cc7c8:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a00cc7cc:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffffff
a00cc7d0:  80 a3 40 01  cmp  %o5, %g1
a00cc7d4:  02 bf ff dd  be  0xa00cc748
a00cc7d8:  da 02 c0 08  ld  [ %o3 + %o0 ], %o5
a00cc7dc:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00cc7e0:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xfffcffff
a00cc7e4:  82 0b 40 01  and  %o5, %g1, %g1
a00cc7e8:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00cc7ec:  82 10 40 0d  or  %g1, %o5, %g1
a00cc7f0:  10 80 00 05  b  0xa00cc804
a00cc7f4:  c2 22 c0 08  st  %g1, [ %o3 + %o0 ]
a00cc7f8:  80 a3 20 1f  cmp  %o4, 0x1f
a00cc7fc:  08 bf ff e9  bleu  0xa00cc7a0
a00cc800:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cc804:  82 0e 20 ff  and  %i0, 0xff, %g1
a00cc808:  98 00 40 01  add  %g1, %g1, %o4
a00cc80c:  98 03 00 01  add  %o4, %g1, %o4
a00cc810:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00cc814:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00cc818:  99 2b 20 03  sll  %o4, 3, %o4
a00cc81c:  c2 02 c0 0c  ld  [ %o3 + %o4 ], %g1
a00cc820:  1b 00 08 00  sethi  %hi(0x200000), %o5
a00cc824:  82 10 40 0d  or  %g1, %o5, %g1
a00cc828:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cc82c:  81 c7 e0 08  ret
a00cc830:  81 e8 00 00  restore
