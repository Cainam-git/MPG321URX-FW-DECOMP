# leon2s FUN_a008c6f8 0xa008c6f8-0xa008c8b0 (440 bytes)
a008c6f8:  9d e3 bf 90  save  %sp, -112, %sp
a008c6fc:  13 28 02 d0  sethi  %hi(0xa00b4000), %o1
a008c700:  92 12 60 30  or  %o1, 0x30, %o1	! 0xa00b4030
a008c704:  94 10 20 06  mov  6, %o2
a008c708:  40 00 93 b4  call  0xa00b15d8
a008c70c:  90 07 bf f0  add  %fp, -16, %o0
a008c710:  7f ff fd 4d  call  0xa008bc44
a008c714:  a4 10 20 00  clr  %l2
a008c718:  aa 10 00 08  mov  %o0, %l5
a008c71c:  a8 10 20 00  clr  %l4
a008c720:  a6 10 20 00  clr  %l3
a008c724:  82 0c e0 ff  and  %l3, 0xff, %g1
a008c728:  82 07 80 01  add  %fp, %g1, %g1
a008c72c:  e0 08 7f f0  ldub  [ %g1 + -16 ], %l0
a008c730:  7f ff f6 1a  call  0xa0089f98
a008c734:  90 10 00 10  mov  %l0, %o0
a008c738:  91 2a 20 10  sll  %o0, 0x10, %o0
a008c73c:  80 a2 20 00  cmp  %o0, 0
a008c740:  22 80 00 56  be,a   0xa008c898
a008c744:  a6 04 e0 01  inc  %l3
a008c748:  80 a4 20 0e  cmp  %l0, 0xe
a008c74c:  18 80 00 3f  bgu  0xa008c848
a008c750:  80 a4 20 07  cmp  %l0, 7
a008c754:  82 10 20 01  mov  1, %g1
a008c758:  9b 28 40 10  sll  %g1, %l0, %o5
a008c75c:  03 00 00 15  sethi  %hi(0x5400), %g1
a008c760:  82 10 61 00  or  %g1, 0x100, %g1	! 0x5500
a008c764:  80 8b 40 01  btst  %o5, %g1
a008c768:  12 80 00 1b  bne  0xa008c7d4
a008c76c:  80 a4 20 08  cmp  %l0, 8
a008c770:  80 8b 60 50  btst  0x50, %o5
a008c774:  02 80 00 35  be  0xa008c848
a008c778:  80 a4 20 07  cmp  %l0, 7
a008c77c:  82 1c 20 04  xor  %l0, 4, %g1
a008c780:  80 a0 00 01  cmp  %g0, %g1
a008c784:  82 40 20 00  addx  %g0, 0, %g1
a008c788:  98 08 60 ff  and  %g1, 0xff, %o4
a008c78c:  a4 10 00 01  mov  %g1, %l2
a008c790:  9b 2b 20 02  sll  %o4, 2, %o5
a008c794:  9a 03 40 0c  add  %o5, %o4, %o5
a008c798:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a008c79c:  82 10 60 24  or  %g1, 0x24, %g1	! 0xa807a824
a008c7a0:  9b 2b 60 02  sll  %o5, 2, %o5
a008c7a4:  9a 03 40 01  add  %o5, %g1, %o5
a008c7a8:  c2 0b 60 50  ldub  [ %o5 + 0x50 ], %g1
a008c7ac:  80 a0 60 05  cmp  %g1, 5
a008c7b0:  12 80 00 26  bne  0xa008c848
a008c7b4:  80 a4 20 07  cmp  %l0, 7
a008c7b8:  82 0d 60 ff  and  %l5, 0xff, %g1
a008c7bc:  83 38 40 0c  sra  %g1, %o4, %g1
a008c7c0:  80 88 60 01  btst  1, %g1
a008c7c4:  02 80 00 21  be  0xa008c848
a008c7c8:  80 a4 20 07  cmp  %l0, 7
a008c7cc:  10 80 00 1c  b  0xa008c83c
a008c7d0:  c2 13 60 62  lduh  [ %o5 + 0x62 ], %g1
a008c7d4:  12 80 00 04  bne  0xa008c7e4
a008c7d8:  80 a4 20 0a  cmp  %l0, 0xa
a008c7dc:  10 80 00 0c  b  0xa008c80c
a008c7e0:  a4 10 20 00  clr  %l2
a008c7e4:  12 80 00 04  bne  0xa008c7f4
a008c7e8:  80 a4 20 0c  cmp  %l0, 0xc
a008c7ec:  10 80 00 08  b  0xa008c80c
a008c7f0:  a4 10 20 01  mov  1, %l2
a008c7f4:  12 80 00 04  bne  0xa008c804
a008c7f8:  80 a4 20 0e  cmp  %l0, 0xe
a008c7fc:  10 80 00 04  b  0xa008c80c
a008c800:  a4 10 20 02  mov  2, %l2
a008c804:  22 80 00 02  be,a   0xa008c80c
a008c808:  a4 10 20 03  mov  3, %l2
a008c80c:  9a 0c a0 ff  and  %l2, 0xff, %o5
a008c810:  83 2b 60 02  sll  %o5, 2, %g1
a008c814:  82 00 40 0d  add  %g1, %o5, %g1
a008c818:  1b 2a 01 ea  sethi  %hi(0xa807a800), %o5
a008c81c:  9a 13 60 24  or  %o5, 0x24, %o5	! 0xa807a824
a008c820:  99 28 60 02  sll  %g1, 2, %o4
a008c824:  c2 0b 40 0c  ldub  [ %o5 + %o4 ], %g1
a008c828:  80 a0 60 05  cmp  %g1, 5
a008c82c:  12 80 00 07  bne  0xa008c848
a008c830:  80 a4 20 07  cmp  %l0, 7
a008c834:  82 03 00 0d  add  %o4, %o5, %g1
a008c838:  c2 10 60 12  lduh  [ %g1 + 0x12 ], %g1
a008c83c:  83 30 60 06  srl  %g1, 6, %g1
a008c840:  a8 08 60 01  and  %g1, 1, %l4
a008c844:  80 a4 20 07  cmp  %l0, 7
a008c848:  08 80 00 09  bleu  0xa008c86c
a008c84c:  a2 0d 20 ff  and  %l4, 0xff, %l1
a008c850:  7f ff f5 fc  call  0xa008a040
a008c854:  90 10 00 10  mov  %l0, %o0
a008c858:  90 0a 20 ff  and  %o0, 0xff, %o0
a008c85c:  7f ff fb 5d  call  0xa008b5d0
a008c860:  92 10 00 11  mov  %l1, %o1
a008c864:  10 80 00 0d  b  0xa008c898
a008c868:  a6 04 e0 01  inc  %l3
a008c86c:  7f ff f5 f5  call  0xa008a040
a008c870:  90 10 00 10  mov  %l0, %o0
a008c874:  92 10 00 11  mov  %l1, %o1
a008c878:  7f ff fb b9  call  0xa008b75c
a008c87c:  90 0a 20 ff  and  %o0, 0xff, %o0
a008c880:  7f ff f5 f0  call  0xa008a040
a008c884:  90 10 00 10  mov  %l0, %o0
a008c888:  92 0a 20 ff  and  %o0, 0xff, %o1
a008c88c:  7f ff ff 53  call  0xa008c5d8
a008c890:  90 10 00 10  mov  %l0, %o0
a008c894:  a6 04 e0 01  inc  %l3
a008c898:  82 0c e0 ff  and  %l3, 0xff, %g1
a008c89c:  80 a0 60 05  cmp  %g1, 5
a008c8a0:  08 bf ff a3  bleu  0xa008c72c
a008c8a4:  82 07 80 01  add  %fp, %g1, %g1
a008c8a8:  81 c7 e0 08  ret
a008c8ac:  81 e8 00 00  restore
