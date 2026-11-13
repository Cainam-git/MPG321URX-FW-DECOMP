# leon2m FUN_a012d554 0xa012d554-0xa012e004 (52 bytes)
a012d554:  9d e3 bf 90  save  %sp, -112, %sp
a012d558:  c2 0e 20 04  ldub  [ %i0 + 4 ], %g1
a012d55c:  82 00 7f ef  add  %g1, -17, %g1
a012d560:  80 a0 60 1e  cmp  %g1, 0x1e
a012d564:  18 80 02 a6  bgu  0xa012dffc
a012d568:  13 00 03 33  sethi  %hi(0xccc00), %o1
a012d56c:  91 28 60 02  sll  %g1, 2, %o0
a012d570:  9a 12 62 24  or  %o1, 0x224, %o5
a012d574:  d8 03 40 08  ld  [ %o5 + %o0 ], %o4
a012d578:  81 c3 00 00  jmp  %o4
a012d57c:  01 00 00 00  nop
a012d580:  d0 0e 20 06  ldub  [ %i0 + 6 ], %o0
a012d584:  d4 0e 20 07  ldub  [ %i0 + 7 ], %o2
a012d588:  92 02 00 0a  add  %o0, %o2, %o1
a012d58c:  e0 0e 20 08  ldub  [ %i0 + 8 ], %l0
a012d590:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a012d594:  82 02 40 10  add  %o1, %l0, %g1
a012d598:  d8 0b e3 10  ldub  [ %o7 + 0x310 ], %o4
a012d59c:  9a 00 40 0c  add  %g1, %o4, %o5
a012d5a0:  17 00 06 94  sethi  %hi(0x1a5000), %o3
a012d5a4:  da 2b e3 10  stb  %o5, [ %o7 + 0x310 ]
a012d5a8:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a012d5ac:  92 12 e1 98  or  %o3, 0x198, %o1
a012d5b0:  90 14 23 1a  or  %l0, 0x31a, %o0
a012d5b4:  96 10 20 00  clr  %o3
a012d5b8:  98 10 20 00  clr  %o4
a012d5bc:  d4 0e 20 09  ldub  [ %i0 + 9 ], %o2
a012d5c0:  9f 2b 20 02  sll  %o4, 2, %o7
a012d5c4:  e2 12 40 0f  lduh  [ %o1 + %o7 ], %l1
a012d5c8:  80 a2 80 11  cmp  %o2, %l1
a012d5cc:  02 80 00 06  be  0xa012d5e4
a012d5d0:  96 02 e0 01  inc  %o3
a012d5d4:  98 0a e0 ff  and  %o3, 0xff, %o4
a012d5d8:  80 a3 20 0a  cmp  %o4, 0xa
a012d5dc:  08 bf ff fa  bleu  0xa012d5c4
a012d5e0:  9f 2b 20 02  sll  %o4, 2, %o7
a012d5e4:  9b 2b 20 02  sll  %o4, 2, %o5
a012d5e8:  96 03 40 09  add  %o5, %o1, %o3
a012d5ec:  c2 12 e0 02  lduh  [ %o3 + 2 ], %g1
a012d5f0:  80 88 65 08  btst  0x508, %g1
a012d5f4:  12 80 02 0f  bne  0xa012de30
a012d5f8:  94 10 20 00  clr  %o2
a012d5fc:  94 10 3f ff  mov  -1, %o2
a012d600:  92 0a a0 ff  and  %o2, 0xff, %o1
a012d604:  d2 32 00 00  sth  %o1, [ %o0 ]
a012d608:  19 00 06 94  sethi  %hi(0x1a5000), %o4
a012d60c:  11 2a 00 b2  sethi  %hi(0xa802c800), %o0
a012d610:  92 13 21 68  or  %o4, 0x168, %o1
a012d614:  9e 12 23 18  or  %o0, 0x318, %o7
a012d618:  96 10 20 00  clr  %o3
a012d61c:  98 10 20 00  clr  %o4
a012d620:  d4 0e 20 05  ldub  [ %i0 + 5 ], %o2
a012d624:  83 2b 20 02  sll  %o4, 2, %g1
a012d628:  da 12 40 01  lduh  [ %o1 + %g1 ], %o5
a012d62c:  80 a2 80 0d  cmp  %o2, %o5
a012d630:  02 80 00 06  be  0xa012d648
a012d634:  96 02 e0 01  inc  %o3
a012d638:  98 0a e0 ff  and  %o3, 0xff, %o4
a012d63c:  80 a3 20 0b  cmp  %o4, 0xb
a012d640:  08 bf ff fa  bleu  0xa012d628
a012d644:  83 2b 20 02  sll  %o4, 2, %g1
a012d648:  97 2b 20 02  sll  %o4, 2, %o3
a012d64c:  94 02 c0 09  add  %o3, %o1, %o2
a012d650:  c2 12 a0 02  lduh  [ %o2 + 2 ], %g1
a012d654:  80 88 60 92  btst  0x92, %g1
a012d658:  12 80 01 e4  bne  0xa012dde8
a012d65c:  94 10 20 00  clr  %o2
a012d660:  94 10 3f ff  mov  -1, %o2
a012d664:  92 0a a0 ff  and  %o2, 0xff, %o1
a012d668:  d2 33 c0 00  sth  %o1, [ %o7 ]
a012d66c:  de 14 23 1a  lduh  [ %l0 + 0x31a ], %o7
a012d670:  d6 12 23 18  lduh  [ %o0 + 0x318 ], %o3
a012d674:  a1 2b e0 03  sll  %o7, 3, %l0
a012d678:  82 02 c0 0b  add  %o3, %o3, %g1
a012d67c:  94 04 00 0f  add  %l0, %o7, %o2
a012d680:  a2 00 40 0b  add  %g1, %o3, %l1
a012d684:  98 02 80 11  add  %o2, %l1, %o4
a012d688:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a012d68c:  9b 2b 20 10  sll  %o4, 0x10, %o5
a012d690:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a012d694:  91 33 60 10  srl  %o5, 0x10, %o0
a012d698:  d8 32 63 16  sth  %o4, [ %o1 + 0x316 ]
a012d69c:  a0 13 e3 20  or  %o7, 0x320, %l0
a012d6a0:  92 02 00 10  add  %o0, %l0, %o1
a012d6a4:  94 10 20 00  clr  %o2
a012d6a8:  97 2a a0 10  sll  %o2, 0x10, %o3
a012d6ac:  99 32 e0 10  srl  %o3, 0x10, %o4
a012d6b0:  94 02 a0 01  inc  %o2
a012d6b4:  9b 2a a0 10  sll  %o2, 0x10, %o5
a012d6b8:  82 03 00 18  add  %o4, %i0, %g1
a012d6bc:  e2 08 60 06  ldub  [ %g1 + 6 ], %l1
a012d6c0:  91 33 60 10  srl  %o5, 0x10, %o0
a012d6c4:  80 a2 20 02  cmp  %o0, 2
a012d6c8:  08 bf ff f8  bleu  0xa012d6a8
a012d6cc:  e2 2a 40 0c  stb  %l1, [ %o1 + %o4 ]
a012d6d0:  d4 0e 20 09  ldub  [ %i0 + 9 ], %o2
a012d6d4:  80 a2 a0 16  cmp  %o2, 0x16
a012d6d8:  12 80 02 49  bne  0xa012dffc
a012d6dc:  01 00 00 00  nop
a012d6e0:  c2 0e 20 05  ldub  [ %i0 + 5 ], %g1
a012d6e4:  80 a0 60 52  cmp  %g1, 0x52
a012d6e8:  22 80 02 19  be,a   0xa012df4c
a012d6ec:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a012d6f0:  14 80 02 08  bg  0xa012df10
a012d6f4:  80 a0 60 73  cmp  %g1, 0x73
a012d6f8:  80 a0 60 41  cmp  %g1, 0x41
a012d6fc:  22 80 02 39  be,a   0xa012dfe0
a012d700:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a012d704:  14 80 02 24  bg  0xa012df94
a012d708:  80 a0 60 4b  cmp  %g1, 0x4b
a012d70c:  80 a0 60 32  cmp  %g1, 0x32
a012d710:  12 80 02 3b  bne  0xa012dffc
a012d714:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a012d718:  a0 13 21 f0  or  %o4, 0x1f0, %l0	! 0xa802e1f0
a012d71c:  d0 0e 20 06  ldub  [ %i0 + 6 ], %o0
a012d720:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a012d724:  d2 0e 20 07  ldub  [ %i0 + 7 ], %o1
a012d728:  d2 2c 20 07  stb  %o1, [ %l0 + 7 ]
a012d72c:  de 0e 20 08  ldub  [ %i0 + 8 ], %o7
a012d730:  10 80 02 33  b  0xa012dffc
a012d734:  de 2c 20 08  stb  %o7, [ %l0 + 8 ]
a012d738:  7f ff e3 81  call  0xa012653c
a012d73c:  90 10 20 02  mov  2, %o0
a012d740:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a012d744:  7f ff e3 07  call  0xa0126360
a012d748:  d0 14 23 12  lduh  [ %l0 + 0x312 ], %o0	! 0xa802cb12
a012d74c:  30 80 02 2c  b,a   0xa012dffc
a012d750:  7f ff e3 7b  call  0xa012653c
a012d754:  90 10 20 00  clr  %o0
a012d758:  40 00 58 2b  call  0xa0143804
a012d75c:  90 10 23 ff  mov  0x3ff, %o0
a012d760:  7f ff 24 1c  call  0xa00f67d0
a012d764:  90 10 20 00  clr  %o0
a012d768:  7f ff 24 4c  call  0xa00f6898
a012d76c:  90 10 20 02  mov  2, %o0
a012d770:  7f ff 23 13  call  0xa00f63bc
a012d774:  90 10 20 02  mov  2, %o0
a012d778:  92 10 20 00  clr  %o1
a012d77c:  94 10 2f 00  mov  0xf00, %o2
a012d780:  96 10 28 70  mov  0x870, %o3
a012d784:  7f ff 25 5f  call  0xa00f6d00
a012d788:  90 10 20 00  clr  %o0
a012d78c:  7f ff 24 ea  call  0xa00f6b34
a012d790:  90 10 20 02  mov  2, %o0
a012d794:  7f ff 25 bd  call  0xa00f6e88
a012d798:  90 10 20 00  clr  %o0
a012d79c:  7f ff 25 cc  call  0xa00f6ecc
a012d7a0:  90 10 20 00  clr  %o0
a012d7a4:  7f ff 25 db  call  0xa00f6f10
a012d7a8:  90 10 20 00  clr  %o0
a012d7ac:  7f ff 24 3b  call  0xa00f6898
a012d7b0:  90 10 20 01  mov  1, %o0
a012d7b4:  7f ff 23 02  call  0xa00f63bc
a012d7b8:  90 10 20 01  mov  1, %o0
a012d7bc:  90 10 26 3a  mov  0x63a, %o0
a012d7c0:  92 10 23 80  mov  0x380, %o1
a012d7c4:  94 10 22 8d  mov  0x28d, %o2
a012d7c8:  7f ff 25 4e  call  0xa00f6d00
a012d7cc:  96 10 21 6f  mov  0x16f, %o3
a012d7d0:  30 80 02 0b  b,a   0xa012dffc
a012d7d4:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a012d7d8:  82 12 a1 a0  or  %o2, 0x1a0, %g1	! 0xa802e1a0
a012d7dc:  d6 0e 20 05  ldub  [ %i0 + 5 ], %o3
a012d7e0:  e0 08 60 37  ldub  [ %g1 + 0x37 ], %l0
a012d7e4:  e2 00 60 34  ld  [ %g1 + 0x34 ], %l1
a012d7e8:  d6 2f bf f6  stb  %o3, [ %fp + -10 ]
a012d7ec:  80 a4 20 01  cmp  %l0, 1
a012d7f0:  97 34 60 08  srl  %l1, 8, %o3
a012d7f4:  08 80 00 03  bleu  0xa012d800
a012d7f8:  92 10 21 20  mov  0x120, %o1
a012d7fc:  92 10 22 40  mov  0x240, %o1
a012d800:  9a 0a 63 60  and  %o1, 0x360, %o5
a012d804:  92 02 c0 0d  add  %o3, %o5, %o1
a012d808:  b0 12 a1 a0  or  %o2, 0x1a0, %i0
a012d80c:  9f 2a 60 10  sll  %o1, 0x10, %o7
a012d810:  d0 0e 20 34  ldub  [ %i0 + 0x34 ], %o0
a012d814:  93 33 e0 10  srl  %o7, 0x10, %o1
a012d818:  94 10 20 01  mov  1, %o2
a012d81c:  96 07 bf f6  add  %fp, -10, %o3
a012d820:  40 00 4d 95  call  0xa0140e74
a012d824:  98 10 20 01  mov  1, %o4
a012d828:  30 80 01 f5  b,a   0xa012dffc
a012d82c:  d0 0e 20 06  ldub  [ %i0 + 6 ], %o0
a012d830:  d2 0e 20 05  ldub  [ %i0 + 5 ], %o1
a012d834:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a012d838:  94 12 e1 a0  or  %o3, 0x1a0, %o2	! 0xa802e1a0
a012d83c:  9b 2a 20 08  sll  %o0, 8, %o5
a012d840:  31 3f c0 00  sethi  %hi(0xff000000), %i0
a012d844:  de 02 a0 34  ld  [ %o2 + 0x34 ], %o7
a012d848:  a0 12 40 0d  or  %o1, %o5, %l0
a012d84c:  82 16 20 ff  or  %i0, 0xff, %g1
a012d850:  a2 0b c0 01  and  %o7, %g1, %l1
a012d854:  99 2c 20 08  sll  %l0, 8, %o4
a012d858:  90 14 40 0c  or  %l1, %o4, %o0
a012d85c:  10 80 01 e8  b  0xa012dffc
a012d860:  d0 22 a0 34  st  %o0, [ %o2 + 0x34 ]
a012d864:  d8 0e 20 05  ldub  [ %i0 + 5 ], %o4
a012d868:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a012d86c:  10 80 01 e4  b  0xa012dffc
a012d870:  d8 2a 21 d4  stb  %o4, [ %o0 + 0x1d4 ]	! 0xa802e1d4
a012d874:  c2 0e 20 05  ldub  [ %i0 + 5 ], %g1
a012d878:  80 a0 60 00  cmp  %g1, 0
a012d87c:  02 80 01 7f  be  0xa012de78
a012d880:  80 a0 60 01  cmp  %g1, 1
a012d884:  02 80 01 8c  be  0xa012deb4
a012d888:  80 a0 60 fe  cmp  %g1, 0xfe
a012d88c:  02 80 01 99  be  0xa012def0
a012d890:  80 a0 60 ff  cmp  %g1, 0xff
a012d894:  12 80 01 da  bne  0xa012dffc
a012d898:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a012d89c:  82 12 e1 a0  or  %o3, 0x1a0, %g1	! 0xa802e1a0
a012d8a0:  d8 08 60 37  ldub  [ %g1 + 0x37 ], %o4
a012d8a4:  f0 00 60 34  ld  [ %g1 + 0x34 ], %i0
a012d8a8:  80 a3 20 01  cmp  %o4, 1
a012d8ac:  99 36 20 08  srl  %i0, 8, %o4
a012d8b0:  08 80 00 03  bleu  0xa012d8bc
a012d8b4:  92 10 21 20  mov  0x120, %o1
a012d8b8:  92 10 22 40  mov  0x240, %o1
a012d8bc:  a2 0a 63 60  and  %o1, 0x360, %l1
a012d8c0:  94 04 60 70  add  %l1, 0x70, %o2
a012d8c4:  90 03 00 0a  add  %o4, %o2, %o0
a012d8c8:  a0 12 e1 a0  or  %o3, 0x1a0, %l0
a012d8cc:  93 2a 20 10  sll  %o0, 0x10, %o1
a012d8d0:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a012d8d4:  d0 0c 20 34  ldub  [ %l0 + 0x34 ], %o0
a012d8d8:  93 32 60 10  srl  %o1, 0x10, %o1
a012d8dc:  96 13 e3 78  or  %o7, 0x378, %o3
a012d8e0:  94 10 20 00  clr  %o2
a012d8e4:  40 00 4d 64  call  0xa0140e74
a012d8e8:  98 10 20 00  clr  %o4
a012d8ec:  30 80 01 c4  b,a   0xa012dffc
a012d8f0:  7f ff 61 05  call  0xa0105d04
a012d8f4:  90 10 20 00  clr  %o0
a012d8f8:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a012d8fc:  7f ff 42 d4  call  0xa00fe44c
a012d900:  d0 14 63 1c  lduh  [ %l1 + 0x31c ], %o0	! 0xa802cb1c
a012d904:  40 00 57 f6  call  0xa01438dc
a012d908:  90 10 20 00  clr  %o0
a012d90c:  94 0a 20 ff  and  %o0, 0xff, %o2
a012d910:  80 a2 a0 01  cmp  %o2, 1
a012d914:  02 80 01 62  be  0xa012de9c
a012d918:  01 00 00 00  nop
a012d91c:  40 00 79 15  call  0xa014bd70
a012d920:  90 10 20 00  clr  %o0	! 0x0
a012d924:  80 8a 20 ff  btst  0xff, %o0
a012d928:  02 80 00 17  be  0xa012d984
a012d92c:  13 34 00 4f  sethi  %hi(0xd0013c00), %o1
a012d930:  b0 12 63 10  or  %o1, 0x310, %i0	! 0xd0013f10
a012d934:  c2 06 00 00  ld  [ %i0 ], %g1
a012d938:  9a 10 60 01  or  %g1, 1, %o5
a012d93c:  da 26 00 00  st  %o5, [ %i0 ]
a012d940:  98 12 63 50  or  %o1, 0x350, %o4
a012d944:  de 03 00 00  ld  [ %o4 ], %o7
a012d948:  31 20 00 00  sethi  %hi(0x80000000), %i0
a012d94c:  a0 13 c0 18  or  %o7, %i0, %l0
a012d950:  e0 23 00 00  st  %l0, [ %o4 ]
a012d954:  96 12 63 60  or  %o1, 0x360, %o3
a012d958:  e2 02 c0 00  ld  [ %o3 ], %l1
a012d95c:  94 14 40 18  or  %l1, %i0, %o2
a012d960:  d4 22 c0 00  st  %o2, [ %o3 ]
a012d964:  9a 12 63 d0  or  %o1, 0x3d0, %o5
a012d968:  d0 03 40 00  ld  [ %o5 ], %o0
a012d96c:  82 12 00 18  or  %o0, %i0, %g1
a012d970:  c2 23 40 00  st  %g1, [ %o5 ]
a012d974:  98 12 63 e0  or  %o1, 0x3e0, %o4
a012d978:  de 03 00 00  ld  [ %o4 ], %o7
a012d97c:  a0 13 c0 18  or  %o7, %i0, %l0
a012d980:  e0 23 00 00  st  %l0, [ %o4 ]
a012d984:  7f ff 23 93  call  0xa00f67d0
a012d988:  90 10 20 02  mov  2, %o0
a012d98c:  7f ff 22 8c  call  0xa00f63bc
a012d990:  90 10 20 00  clr  %o0
a012d994:  92 10 20 00  clr  %o1
a012d998:  94 10 2f 00  mov  0xf00, %o2
a012d99c:  96 10 28 70  mov  0x870, %o3
a012d9a0:  7f ff 24 d8  call  0xa00f6d00
a012d9a4:  90 10 20 00  clr  %o0
a012d9a8:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a012d9ac:  7f ff e2 e4  call  0xa012653c
a012d9b0:  d0 0b 23 15  ldub  [ %o4 + 0x315 ], %o0	! 0xa802cb15
a012d9b4:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a012d9b8:  7f ff e2 6a  call  0xa0126360
a012d9bc:  d0 14 63 12  lduh  [ %l1 + 0x312 ], %o0	! 0xa802cb12
a012d9c0:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a012d9c4:  d4 0a 62 20  ldub  [ %o1 + 0x220 ], %o2	! 0xa802e220
a012d9c8:  96 12 a0 20  or  %o2, 0x20, %o3
a012d9cc:  90 0a ff bf  and  %o3, -65, %o0
a012d9d0:  10 80 01 8b  b  0xa012dffc
a012d9d4:  d0 2a 62 20  stb  %o0, [ %o1 + 0x220 ]
a012d9d8:  23 2a 00 b8  sethi  %hi(0xa802e000), %l1
a012d9dc:  82 14 61 a0  or  %l1, 0x1a0, %g1	! 0xa802e1a0
a012d9e0:  da 08 60 37  ldub  [ %g1 + 0x37 ], %o5
a012d9e4:  f0 00 60 34  ld  [ %g1 + 0x34 ], %i0
a012d9e8:  80 a3 60 01  cmp  %o5, 1
a012d9ec:  99 36 20 08  srl  %i0, 8, %o4
a012d9f0:  08 80 00 03  bleu  0xa012d9fc
a012d9f4:  92 10 21 20  mov  0x120, %o1
a012d9f8:  92 10 22 40  mov  0x240, %o1
a012d9fc:  9a 0a 63 60  and  %o1, 0x360, %o5
a012da00:  b0 03 60 10  add  %o5, 0x10, %i0
a012da04:  90 03 00 18  add  %o4, %i0, %o0
a012da08:  a0 14 61 a0  or  %l1, 0x1a0, %l0
a012da0c:  93 2a 20 10  sll  %o0, 0x10, %o1
a012da10:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a012da14:  93 32 60 10  srl  %o1, 0x10, %o1
a012da18:  96 13 e3 20  or  %o7, 0x320, %o3
a012da1c:  94 10 20 1b  mov  0x1b, %o2
a012da20:  d0 0c 20 34  ldub  [ %l0 + 0x34 ], %o0
a012da24:  40 00 4d 14  call  0xa0140e74
a012da28:  98 10 20 00  clr  %o4
a012da2c:  d4 0c 20 37  ldub  [ %l0 + 0x37 ], %o2
a012da30:  d6 04 20 34  ld  [ %l0 + 0x34 ], %o3
a012da34:  80 a2 a0 01  cmp  %o2, 1
a012da38:  9b 32 e0 08  srl  %o3, 8, %o5
a012da3c:  08 80 00 03  bleu  0xa012da48
a012da40:  92 10 21 20  mov  0x120, %o1
a012da44:  92 10 22 40  mov  0x240, %o1
a012da48:  92 0a 63 60  and  %o1, 0x360, %o1
a012da4c:  9e 02 60 30  add  %o1, 0x30, %o7
a012da50:  a0 03 40 0f  add  %o5, %o7, %l0
a012da54:  95 2c 20 10  sll  %l0, 0x10, %o2
a012da58:  82 14 61 a0  or  %l1, 0x1a0, %g1
a012da5c:  93 32 a0 10  srl  %o2, 0x10, %o1
a012da60:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a012da64:  d0 08 60 34  ldub  [ %g1 + 0x34 ], %o0
a012da68:  96 12 e3 40  or  %o3, 0x340, %o3
a012da6c:  94 10 20 36  mov  0x36, %o2
a012da70:  40 00 4d 01  call  0xa0140e74
a012da74:  98 10 20 00  clr  %o4
a012da78:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a012da7c:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a012da80:  c0 33 23 7a  clrh  [ %o4 + 0x37a ]
a012da84:  c0 34 63 78  clrh  [ %l1 + 0x378 ]
a012da88:  7f ff 23 52  call  0xa00f67d0
a012da8c:  90 10 20 01  mov  1, %o0
a012da90:  7f ff 23 82  call  0xa00f6898
a012da94:  90 10 20 00  clr  %o0
a012da98:  7f ff 22 49  call  0xa00f63bc
a012da9c:  90 10 20 00  clr  %o0
a012daa0:  90 10 25 40  mov  0x540, %o0
a012daa4:  92 10 22 f4  mov  0x2f4, %o1
a012daa8:  94 10 24 80  mov  0x480, %o2
a012daac:  7f ff 24 95  call  0xa00f6d00
a012dab0:  96 10 22 88  mov  0x288, %o3
a012dab4:  30 80 01 52  b,a   0xa012dffc
a012dab8:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a012dabc:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a012dac0:  a0 12 a3 40  or  %o2, 0x340, %l0
a012dac4:  da 13 e3 7a  lduh  [ %o7 + 0x37a ], %o5
a012dac8:  90 03 40 10  add  %o5, %l0, %o0
a012dacc:  94 10 20 00  clr  %o2
a012dad0:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a012dad4:  a0 10 00 0d  mov  %o5, %l0
a012dad8:  99 2a a0 10  sll  %o2, 0x10, %o4
a012dadc:  a3 33 20 10  srl  %o4, 0x10, %l1
a012dae0:  96 04 40 18  add  %l1, %i0, %o3
a012dae4:  c2 0a e0 05  ldub  [ %o3 + 5 ], %g1
a012dae8:  da 0a 63 10  ldub  [ %o1 + 0x310 ], %o5
a012daec:  82 00 40 0d  add  %g1, %o5, %g1
a012daf0:  94 02 a0 01  inc  %o2
a012daf4:  c2 2a 63 10  stb  %g1, [ %o1 + 0x310 ]
a012daf8:  c2 0a e0 05  ldub  [ %o3 + 5 ], %g1
a012dafc:  9b 2a a0 10  sll  %o2, 0x10, %o5
a012db00:  97 33 60 10  srl  %o5, 0x10, %o3
a012db04:  80 a2 e0 11  cmp  %o3, 0x11
a012db08:  08 bf ff f4  bleu  0xa012dad8
a012db0c:  c2 2a 00 11  stb  %g1, [ %o0 + %l1 ]
a012db10:  92 04 20 12  add  %l0, 0x12, %o1
a012db14:  10 80 01 3a  b  0xa012dffc
a012db18:  d2 33 e3 7a  sth  %o1, [ %o7 + 0x37a ]
a012db1c:  7f ff e2 e5  call  0xa01266b0
a012db20:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a012db24:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a012db28:  7f ff e2 70  call  0xa01264e8
a012db2c:  d0 33 63 14  sth  %o0, [ %o5 + 0x314 ]	! 0xa802cb14
a012db30:  d0 36 23 12  sth  %o0, [ %i0 + 0x312 ]
a012db34:  7f ff e2 82  call  0xa012653c
a012db38:  90 10 20 01  mov  1, %o0
a012db3c:  40 00 57 32  call  0xa0143804
a012db40:  90 10 23 ff  mov  0x3ff, %o0
a012db44:  7f ff 42 4e  call  0xa00fe47c
a012db48:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a012db4c:  7f ff 74 c9  call  0xa010ae70
a012db50:  d0 34 23 1c  sth  %o0, [ %l0 + 0x31c ]	! 0xa802cb1c
a012db54:  7f ff 74 ff  call  0xa010af50
a012db58:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a012db5c:  7f ff 75 1b  call  0xa010afc8
a012db60:  01 00 00 00  nop
a012db64:  7f ff 75 8d  call  0xa010b198
a012db68:  01 00 00 00  nop
a012db6c:  7f ff 24 40  call  0xa00f6c6c
a012db70:  01 00 00 00  nop
a012db74:  7f ff 24 4c  call  0xa00f6ca4
a012db78:  01 00 00 00  nop
a012db7c:  d2 0e 22 20  ldub  [ %i0 + 0x220 ], %o1
a012db80:  94 12 60 40  or  %o1, 0x40, %o2
a012db84:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a012db88:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a012db8c:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a012db90:  d4 2e 22 20  stb  %o2, [ %i0 + 0x220 ]
a012db94:  c0 2b e3 10  clrb  [ %o7 + 0x310 ]
a012db98:  c0 30 63 78  clrh  [ %g1 + 0x378 ]
a012db9c:  c0 32 e3 7a  clrh  [ %o3 + 0x37a ]
a012dba0:  7f ff 24 4f  call  0xa00f6cdc
a012dba4:  90 10 20 02  mov  2, %o0
a012dba8:  e2 14 23 1c  lduh  [ %l0 + 0x31c ], %l1
a012dbac:  98 14 61 26  or  %l1, 0x126, %o4
a012dbb0:  a1 2b 20 10  sll  %o4, 0x10, %l0
a012dbb4:  7f ff 42 26  call  0xa00fe44c
a012dbb8:  91 34 20 10  srl  %l0, 0x10, %o0
a012dbbc:  21 34 00 4f  sethi  %hi(0xd0013c00), %l0
a012dbc0:  92 14 23 10  or  %l0, 0x310, %o1	! 0xd0013f10
a012dbc4:  da 02 40 00  ld  [ %o1 ], %o5
a012dbc8:  90 0b 7f fe  and  %o5, -2, %o0
a012dbcc:  d0 22 40 00  st  %o0, [ %o1 ]
a012dbd0:  96 14 23 50  or  %l0, 0x350, %o3
a012dbd4:  15 1f ff ff  sethi  %hi(0x7ffffc00), %o2
a012dbd8:  de 02 c0 00  ld  [ %o3 ], %o7
a012dbdc:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a012dbe0:  82 0b c0 0a  and  %o7, %o2, %g1
a012dbe4:  9a 14 23 60  or  %l0, 0x360, %o5
a012dbe8:  c2 22 c0 00  st  %g1, [ %o3 ]
a012dbec:  e2 03 40 00  ld  [ %o5 ], %l1
a012dbf0:  98 0c 40 0a  and  %l1, %o2, %o4
a012dbf4:  d8 23 40 00  st  %o4, [ %o5 ]
a012dbf8:  9e 14 23 d0  or  %l0, 0x3d0, %o7
a012dbfc:  d0 03 c0 00  ld  [ %o7 ], %o0
a012dc00:  92 0a 00 0a  and  %o0, %o2, %o1
a012dc04:  d2 23 c0 00  st  %o1, [ %o7 ]
a012dc08:  a2 14 23 e0  or  %l0, 0x3e0, %l1
a012dc0c:  d6 04 40 00  ld  [ %l1 ], %o3
a012dc10:  82 0a c0 0a  and  %o3, %o2, %g1
a012dc14:  c2 24 40 00  st  %g1, [ %l1 ]
a012dc18:  7f ff 22 a3  call  0xa00f66a4
a012dc1c:  90 10 20 ff  mov  0xff, %o0
a012dc20:  7f ff 22 ec  call  0xa00f67d0
a012dc24:  90 10 20 00  clr  %o0
a012dc28:  7f ff 23 1c  call  0xa00f6898
a012dc2c:  90 10 20 02  mov  2, %o0
a012dc30:  7f ff 21 e3  call  0xa00f63bc
a012dc34:  90 10 20 02  mov  2, %o0
a012dc38:  92 10 20 00  clr  %o1
a012dc3c:  94 10 2f 00  mov  0xf00, %o2
a012dc40:  96 10 28 70  mov  0x870, %o3
a012dc44:  7f ff 24 2f  call  0xa00f6d00
a012dc48:  90 10 20 00  clr  %o0
a012dc4c:  7f ff 23 ba  call  0xa00f6b34
a012dc50:  90 10 20 02  mov  2, %o0
a012dc54:  7f ff 24 8d  call  0xa00f6e88
a012dc58:  90 10 20 00  clr  %o0
a012dc5c:  7f ff 24 9c  call  0xa00f6ecc
a012dc60:  90 10 20 00  clr  %o0
a012dc64:  7f ff 24 ab  call  0xa00f6f10
a012dc68:  90 10 20 00  clr  %o0
a012dc6c:  7f ff 23 0b  call  0xa00f6898
a012dc70:  90 10 20 01  mov  1, %o0
a012dc74:  7f ff 21 d2  call  0xa00f63bc
a012dc78:  90 10 20 01  mov  1, %o0
a012dc7c:  92 10 22 f4  mov  0x2f4, %o1
a012dc80:  94 10 24 80  mov  0x480, %o2
a012dc84:  96 10 22 88  mov  0x288, %o3
a012dc88:  7f ff 24 1e  call  0xa00f6d00
a012dc8c:  90 10 25 40  mov  0x540, %o0
a012dc90:  40 00 56 dd  call  0xa0143804
a012dc94:  90 10 23 ff  mov  0x3ff, %o0
a012dc98:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a012dc9c:  40 00 4a 19  call  0xa0140500
a012dca0:  d0 0b 21 d4  ldub  [ %o4 + 0x1d4 ], %o0	! 0xa802e1d4
a012dca4:  da 0e 22 20  ldub  [ %i0 + 0x220 ], %o5
a012dca8:  90 0b 7f df  and  %o5, -33, %o0
a012dcac:  10 80 00 d4  b  0xa012dffc
a012dcb0:  d0 2e 22 20  stb  %o0, [ %i0 + 0x220 ]
a012dcb4:  7f ff 60 14  call  0xa0105d04
a012dcb8:  90 10 20 02  mov  2, %o0
a012dcbc:  d2 0e 20 05  ldub  [ %i0 + 5 ], %o1
a012dcc0:  d4 0e 20 06  ldub  [ %i0 + 6 ], %o2
a012dcc4:  d6 0e 20 07  ldub  [ %i0 + 7 ], %o3
a012dcc8:  7f ff 56 d0  call  0xa0103808
a012dccc:  90 10 20 00  clr  %o0
a012dcd0:  23 00 06 94  sethi  %hi(0x1a5000), %l1
a012dcd4:  90 14 61 f8  or  %l1, 0x1f8, %o0	! 0x1a51f8
a012dcd8:  d6 0e 20 07  ldub  [ %i0 + 7 ], %o3
a012dcdc:  d2 0e 20 05  ldub  [ %i0 + 5 ], %o1
a012dce0:  7f fe c5 24  call  0xa00df170
a012dce4:  d4 0e 20 06  ldub  [ %i0 + 6 ], %o2
a012dce8:  30 80 00 c5  b,a   0xa012dffc
a012dcec:  23 2a 00 b8  sethi  %hi(0xa802e000), %l1
a012dcf0:  9a 14 61 a0  or  %l1, 0x1a0, %o5	! 0xa802e1a0
a012dcf4:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a012dcf8:  d6 03 60 34  ld  [ %o5 + 0x34 ], %o3
a012dcfc:  93 32 e0 08  srl  %o3, 8, %o1
a012dd00:  d4 14 23 78  lduh  [ %l0 + 0x378 ], %o2
a012dd04:  90 02 40 0a  add  %o1, %o2, %o0
a012dd08:  99 2a 20 10  sll  %o0, 0x10, %o4
a012dd0c:  93 33 20 10  srl  %o4, 0x10, %o1
a012dd10:  94 10 20 20  mov  0x20, %o2
a012dd14:  96 06 20 05  add  %i0, 5, %o3
a012dd18:  d0 0b 60 34  ldub  [ %o5 + 0x34 ], %o0
a012dd1c:  40 00 4c 56  call  0xa0140e74
a012dd20:  98 10 20 00  clr  %o4
a012dd24:  c2 14 23 78  lduh  [ %l0 + 0x378 ], %g1
a012dd28:  9e 00 60 20  add  %g1, 0x20, %o7
a012dd2c:  de 34 23 78  sth  %o7, [ %l0 + 0x378 ]
a012dd30:  d6 0e 20 01  ldub  [ %i0 + 1 ], %o3
a012dd34:  94 02 ff 7d  add  %o3, -131, %o2
a012dd38:  80 a2 a0 00  cmp  %o2, 0
a012dd3c:  04 80 00 12  ble  0xa012dd84
a012dd40:  96 10 20 00  clr  %o3
a012dd44:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a012dd48:  9b 2a e0 10  sll  %o3, 0x10, %o5
a012dd4c:  91 33 60 10  srl  %o5, 0x10, %o0
a012dd50:  98 02 00 18  add  %o0, %i0, %o4
a012dd54:  de 0b 20 05  ldub  [ %o4 + 5 ], %o7
a012dd58:  c2 0a a3 10  ldub  [ %o2 + 0x310 ], %g1
a012dd5c:  92 03 c0 01  add  %o7, %g1, %o1
a012dd60:  9e 02 e0 01  add  %o3, 1, %o7
a012dd64:  d2 2a a3 10  stb  %o1, [ %o2 + 0x310 ]
a012dd68:  9b 2b e0 10  sll  %o7, 0x10, %o5
a012dd6c:  d0 0e 20 01  ldub  [ %i0 + 1 ], %o0
a012dd70:  99 33 60 10  srl  %o5, 0x10, %o4
a012dd74:  82 02 3f 7d  add  %o0, -131, %g1
a012dd78:  80 a3 00 01  cmp  %o4, %g1
a012dd7c:  06 bf ff f3  bl  0xa012dd48
a012dd80:  96 10 00 0f  mov  %o7, %o3
a012dd84:  94 14 61 a0  or  %l1, 0x1a0, %o2
a012dd88:  f0 0a a0 37  ldub  [ %o2 + 0x37 ], %i0
a012dd8c:  80 a6 20 01  cmp  %i0, 1
a012dd90:  08 80 00 03  bleu  0xa012dd9c
a012dd94:  9a 10 21 20  mov  0x120, %o5
a012dd98:  9a 10 22 40  mov  0x240, %o5
a012dd9c:  92 0b 63 60  and  %o5, 0x360, %o1
a012dda0:  d6 14 23 78  lduh  [ %l0 + 0x378 ], %o3
a012dda4:  80 a2 c0 09  cmp  %o3, %o1
a012dda8:  12 80 00 95  bne  0xa012dffc
a012ddac:  9e 14 61 a0  or  %l1, 0x1a0, %o7
a012ddb0:  f0 03 e0 34  ld  [ %o7 + 0x34 ], %i0
a012ddb4:  91 36 20 08  srl  %i0, 8, %o0
a012ddb8:  98 02 00 0b  add  %o0, %o3, %o4
a012ddbc:  82 10 20 78  mov  0x78, %g1
a012ddc0:  a3 2b 20 10  sll  %o4, 0x10, %l1
a012ddc4:  c2 2f bf f7  stb  %g1, [ %fp + -9 ]
a012ddc8:  d0 0b e0 34  ldub  [ %o7 + 0x34 ], %o0
a012ddcc:  93 34 60 10  srl  %l1, 0x10, %o1
a012ddd0:  94 10 20 01  mov  1, %o2
a012ddd4:  96 07 bf f7  add  %fp, -9, %o3
a012ddd8:  40 00 4c 27  call  0xa0140e74
a012dddc:  98 10 20 01  mov  1, %o4
a012dde0:  10 80 00 87  b  0xa012dffc
a012dde4:  c0 34 23 78  clrh  [ %l0 + 0x378 ]
a012dde8:  80 a0 60 01  cmp  %g1, 1
a012ddec:  02 bf fe 1e  be  0xa012d664
a012ddf0:  98 10 20 00  clr  %o4
a012ddf4:  96 10 00 01  mov  %g1, %o3
a012ddf8:  9a 10 20 00  clr  %o5
a012ddfc:  92 10 20 92  mov  0x92, %o1
a012de00:  a3 3a 40 0d  sra  %o1, %o5, %l1
a012de04:  80 8c 60 01  btst  1, %l1
a012de08:  32 80 00 02  bne,a   0xa012de10
a012de0c:  94 02 a0 01  inc  %o2
a012de10:  98 03 20 01  inc  %o4
a012de14:  9a 0b 20 ff  and  %o4, 0xff, %o5
a012de18:  83 3a c0 0d  sra  %o3, %o5, %g1
a012de1c:  80 a0 60 01  cmp  %g1, 1
a012de20:  12 bf ff f9  bne  0xa012de04
a012de24:  a3 3a 40 0d  sra  %o1, %o5, %l1
a012de28:  10 bf fe 10  b  0xa012d668
a012de2c:  92 0a a0 ff  and  %o2, 0xff, %o1
a012de30:  80 a0 60 01  cmp  %g1, 1
a012de34:  02 bf fd f3  be  0xa012d600
a012de38:  98 10 20 00  clr  %o4
a012de3c:  96 10 00 01  mov  %g1, %o3
a012de40:  9a 10 20 00  clr  %o5
a012de44:  92 10 25 08  mov  0x508, %o1
a012de48:  83 3a 40 0d  sra  %o1, %o5, %g1
a012de4c:  80 88 60 01  btst  1, %g1
a012de50:  32 80 00 02  bne,a   0xa012de58
a012de54:  94 02 a0 01  inc  %o2
a012de58:  98 03 20 01  inc  %o4
a012de5c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a012de60:  a3 3a c0 0d  sra  %o3, %o5, %l1
a012de64:  80 a4 60 01  cmp  %l1, 1
a012de68:  12 bf ff f9  bne  0xa012de4c
a012de6c:  83 3a 40 0d  sra  %o1, %o5, %g1
a012de70:  10 bf fd e5  b  0xa012d604
a012de74:  92 0a a0 ff  and  %o2, 0xff, %o1
a012de78:  e2 0e 20 08  ldub  [ %i0 + 8 ], %l1
a012de7c:  a1 2c 60 08  sll  %l1, 8, %l0
a012de80:  d4 0e 20 07  ldub  [ %i0 + 7 ], %o2
a012de84:  90 04 00 0a  add  %l0, %o2, %o0
a012de88:  9f 2a 20 10  sll  %o0, 0x10, %o7
a012de8c:  91 33 e0 10  srl  %o7, 0x10, %o0
a012de90:  40 00 56 6e  call  0xa0143848
a012de94:  01 00 00 00  nop
a012de98:  30 80 00 59  b,a   0xa012dffc
a012de9c:  40 00 76 f3  call  0xa014ba68
a012dea0:  01 00 00 00  nop
a012dea4:  80 8a 20 ff  btst  0xff, %o0
a012dea8:  12 bf fe a2  bne  0xa012d930
a012deac:  13 34 00 4f  sethi  %hi(0xd0013c00), %o1
a012deb0:  30 bf fe 9b  b,a   0xa012d91c
a012deb4:  d6 0e 20 08  ldub  [ %i0 + 8 ], %o3
a012deb8:  e2 0e 20 07  ldub  [ %i0 + 7 ], %l1
a012debc:  d0 0e 20 06  ldub  [ %i0 + 6 ], %o0
a012dec0:  95 2a e0 08  sll  %o3, 8, %o2
a012dec4:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a012dec8:  9a 02 80 11  add  %o2, %l1, %o5
a012decc:  98 14 23 78  or  %l0, 0x378, %o4
a012ded0:  9e 02 00 08  add  %o0, %o0, %o7
a012ded4:  da 2b 00 0f  stb  %o5, [ %o4 + %o7 ]
a012ded8:  d2 0e 20 06  ldub  [ %i0 + 6 ], %o1
a012dedc:  82 02 40 09  add  %o1, %o1, %g1
a012dee0:  b0 00 40 0c  add  %g1, %o4, %i0
a012dee4:  97 33 60 08  srl  %o5, 8, %o3
a012dee8:  10 80 00 45  b  0xa012dffc
a012deec:  d6 2e 20 01  stb  %o3, [ %i0 + 1 ]
a012def0:  da 0e 20 06  ldub  [ %i0 + 6 ], %o5
a012def4:  80 a3 60 00  cmp  %o5, 0
a012def8:  02 80 00 03  be  0xa012df04
a012defc:  90 10 20 00  clr  %o0
a012df00:  90 10 20 01  mov  1, %o0
a012df04:  40 00 56 71  call  0xa01438c8
a012df08:  01 00 00 00  nop
a012df0c:  30 80 00 3c  b,a   0xa012dffc
a012df10:  02 80 00 2b  be  0xa012dfbc
a012df14:  80 a0 60 73  cmp  %g1, 0x73
a012df18:  14 80 00 15  bg  0xa012df6c
a012df1c:  80 a0 60 82  cmp  %g1, 0x82
a012df20:  80 a0 60 5d  cmp  %g1, 0x5d
a012df24:  12 80 00 36  bne  0xa012dffc
a012df28:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a012df2c:  a0 13 21 f0  or  %o4, 0x1f0, %l0	! 0xa802e1f0
a012df30:  d0 0e 20 06  ldub  [ %i0 + 6 ], %o0
a012df34:  d0 2c 20 12  stb  %o0, [ %l0 + 0x12 ]
a012df38:  d2 0e 20 07  ldub  [ %i0 + 7 ], %o1
a012df3c:  d2 2c 20 13  stb  %o1, [ %l0 + 0x13 ]
a012df40:  de 0e 20 08  ldub  [ %i0 + 8 ], %o7
a012df44:  10 80 00 2e  b  0xa012dffc
a012df48:  de 2c 20 14  stb  %o7, [ %l0 + 0x14 ]
a012df4c:  a2 12 a1 f0  or  %o2, 0x1f0, %l1
a012df50:  d6 0e 20 06  ldub  [ %i0 + 6 ], %o3
a012df54:  d6 2c 60 0f  stb  %o3, [ %l1 + 0xf ]
a012df58:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a012df5c:  c2 2c 60 10  stb  %g1, [ %l1 + 0x10 ]
a012df60:  da 0e 20 08  ldub  [ %i0 + 8 ], %o5
a012df64:  10 80 00 26  b  0xa012dffc
a012df68:  da 2c 60 11  stb  %o5, [ %l1 + 0x11 ]
a012df6c:  12 80 00 24  bne  0xa012dffc
a012df70:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a012df74:  a0 13 21 f0  or  %o4, 0x1f0, %l0	! 0xa802e1f0
a012df78:  d0 0e 20 06  ldub  [ %i0 + 6 ], %o0
a012df7c:  d0 2c 20 21  stb  %o0, [ %l0 + 0x21 ]
a012df80:  d2 0e 20 07  ldub  [ %i0 + 7 ], %o1
a012df84:  d2 2c 20 22  stb  %o1, [ %l0 + 0x22 ]
a012df88:  de 0e 20 08  ldub  [ %i0 + 8 ], %o7
a012df8c:  10 80 00 1c  b  0xa012dffc
a012df90:  de 2c 20 23  stb  %o7, [ %l0 + 0x23 ]
a012df94:  12 80 00 1a  bne  0xa012dffc
a012df98:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a012df9c:  a0 13 21 f0  or  %o4, 0x1f0, %l0	! 0xa802e1f0
a012dfa0:  d0 0e 20 06  ldub  [ %i0 + 6 ], %o0
a012dfa4:  d0 2c 20 0c  stb  %o0, [ %l0 + 0xc ]
a012dfa8:  d2 0e 20 07  ldub  [ %i0 + 7 ], %o1
a012dfac:  d2 2c 20 0d  stb  %o1, [ %l0 + 0xd ]
a012dfb0:  de 0e 20 08  ldub  [ %i0 + 8 ], %o7
a012dfb4:  10 80 00 12  b  0xa012dffc
a012dfb8:  de 2c 20 0e  stb  %o7, [ %l0 + 0xe ]
a012dfbc:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a012dfc0:  a2 12 a1 f0  or  %o2, 0x1f0, %l1	! 0xa802e1f0
a012dfc4:  d6 0e 20 06  ldub  [ %i0 + 6 ], %o3
a012dfc8:  d6 2c 60 15  stb  %o3, [ %l1 + 0x15 ]
a012dfcc:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a012dfd0:  c2 2c 60 16  stb  %g1, [ %l1 + 0x16 ]
a012dfd4:  da 0e 20 08  ldub  [ %i0 + 8 ], %o5
a012dfd8:  10 80 00 09  b  0xa012dffc
a012dfdc:  da 2c 60 17  stb  %o5, [ %l1 + 0x17 ]
a012dfe0:  a2 12 a1 f0  or  %o2, 0x1f0, %l1
a012dfe4:  d6 0e 20 06  ldub  [ %i0 + 6 ], %o3
a012dfe8:  d6 2c 60 09  stb  %o3, [ %l1 + 9 ]
a012dfec:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a012dff0:  c2 2c 60 0a  stb  %g1, [ %l1 + 0xa ]
a012dff4:  da 0e 20 08  ldub  [ %i0 + 8 ], %o5
a012dff8:  da 2c 60 0b  stb  %o5, [ %l1 + 0xb ]
a012dffc:  81 c7 e0 08  ret
a012e000:  81 e8 00 00  restore
