# leon2m FUN_a010c61c 0xa010c61c-0xa010d068 (140 bytes)
a010c61c:  9d e3 bf 98  save  %sp, -104, %sp
a010c620:  9e 0e 20 ff  and  %i0, 0xff, %o7
a010c624:  9a 10 00 1b  mov  %i3, %o5
a010c628:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010c62c:  80 a3 e0 01  cmp  %o7, 1
a010c630:  02 80 00 06  be  0xa010c648
a010c634:  b6 10 63 c4  or  %g1, 0x3c4, %i3
a010c638:  39 2a 00 b5  sethi  %hi(0xa802d400), %i4
a010c63c:  80 a3 e0 02  cmp  %o7, 2
a010c640:  02 80 00 19  be  0xa010c6a4
a010c644:  b6 17 23 44  or  %i4, 0x344, %i3
a010c648:  80 a3 e0 02  cmp  %o7, 2
a010c64c:  08 80 00 03  bleu  0xa010c658
a010c650:  f2 2e e0 27  stb  %i1, [ %i3 + 0x27 ]
a010c654:  b0 10 20 00  clr  %i0
a010c658:  82 0e 20 ff  and  %i0, 0xff, %g1
a010c65c:  19 00 06 6b  sethi  %hi(0x19ac00), %o4
a010c660:  b1 28 60 02  sll  %g1, 2, %i0
a010c664:  ba 13 22 d8  or  %o4, 0x2d8, %i5
a010c668:  f8 07 40 18  ld  [ %i5 + %i0 ], %i4
a010c66c:  82 0e 60 ff  and  %i1, 0xff, %g1
a010c670:  f0 07 20 10  ld  [ %i4 + 0x10 ], %i0
a010c674:  80 a0 60 04  cmp  %g1, 4
a010c678:  18 80 02 7a  bgu  0xa010d060
a010c67c:  33 00 02 ac  sethi  %hi(0xab000), %i1
a010c680:  b9 28 60 02  sll  %g1, 2, %i4
a010c684:  ba 16 63 e4  or  %i1, 0x3e4, %i5
a010c688:  f2 07 40 1c  ld  [ %i5 + %i4 ], %i1
a010c68c:  81 c6 40 00  jmp  %i1
a010c690:  01 00 00 00  nop
a010c694:  bb 2b e0 02  sll  %o7, 2, %i5
a010c698:  f6 07 00 1d  ld  [ %i4 + %i5 ], %i3
a010c69c:  da 26 e0 3c  st  %o5, [ %i3 + 0x3c ]
a010c6a0:  30 80 02 70  b,a   0xa010d060
a010c6a4:  3b 2a 00 b5  sethi  %hi(0xa802d400), %i5
a010c6a8:  10 bf ff e8  b  0xa010c648
a010c6ac:  b6 17 63 84  or  %i5, 0x384, %i3	! 0xa802d784
a010c6b0:  c0 26 e0 34  clr  [ %i3 + 0x34 ]
a010c6b4:  c0 26 e0 30  clr  [ %i3 + 0x30 ]
a010c6b8:  80 a3 e0 02  cmp  %o7, 2
a010c6bc:  08 80 02 50  bleu  0xa010cffc
a010c6c0:  b0 0e 3f bf  and  %i0, -65, %i0
a010c6c4:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010c6c8:  b6 10 62 d8  or  %g1, 0x2d8, %i3	! 0x19aed8
a010c6cc:  b8 10 20 00  clr  %i4
a010c6d0:  b5 2f 20 02  sll  %i4, 2, %i2
a010c6d4:  f2 06 c0 1a  ld  [ %i3 + %i2 ], %i1
a010c6d8:  b8 07 20 01  inc  %i4
a010c6dc:  f0 26 60 10  st  %i0, [ %i1 + 0x10 ]
a010c6e0:  80 a7 20 02  cmp  %i4, 2
a010c6e4:  08 bf ff fc  bleu  0xa010c6d4
a010c6e8:  b5 2f 20 02  sll  %i4, 2, %i2
a010c6ec:  80 a3 e0 02  cmp  %o7, 2
a010c6f0:  08 80 02 02  bleu  0xa010cef8
a010c6f4:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a010c6f8:  b8 10 20 00  clr  %i4
a010c6fc:  b6 16 a2 cc  or  %i2, 0x2cc, %i3
a010c700:  83 2f 20 02  sll  %i4, 2, %g1
a010c704:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010c708:  b8 07 20 01  inc  %i4
a010c70c:  f0 26 60 10  st  %i0, [ %i1 + 0x10 ]
a010c710:  80 a7 20 02  cmp  %i4, 2
a010c714:  08 bf ff fc  bleu  0xa010c704
a010c718:  83 2f 20 02  sll  %i4, 2, %g1
a010c71c:  80 a3 e0 02  cmp  %o7, 2
a010c720:  08 80 01 f1  bleu  0xa010cee4
a010c724:  b8 13 22 d8  or  %o4, 0x2d8, %i4
a010c728:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010c72c:  b6 16 22 d8  or  %i0, 0x2d8, %i3	! 0x19aed8
a010c730:  b8 10 20 00  clr  %i4
a010c734:  83 2f 20 02  sll  %i4, 2, %g1
a010c738:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010c73c:  b8 07 20 01  inc  %i4
a010c740:  c0 26 60 38  clr  [ %i1 + 0x38 ]
a010c744:  80 a7 20 02  cmp  %i4, 2
a010c748:  08 bf ff fc  bleu  0xa010c738
a010c74c:  83 2f 20 02  sll  %i4, 2, %g1
a010c750:  80 a3 e0 02  cmp  %o7, 2
a010c754:  08 80 01 df  bleu  0xa010ced0
a010c758:  b8 16 a2 cc  or  %i2, 0x2cc, %i4
a010c75c:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010c760:  b6 16 22 cc  or  %i0, 0x2cc, %i3	! 0x19aecc
a010c764:  b8 10 20 00  clr  %i4
a010c768:  83 2f 20 02  sll  %i4, 2, %g1
a010c76c:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010c770:  b8 07 20 01  inc  %i4
a010c774:  c0 26 60 38  clr  [ %i1 + 0x38 ]
a010c778:  80 a7 20 02  cmp  %i4, 2
a010c77c:  08 bf ff fc  bleu  0xa010c76c
a010c780:  83 2f 20 02  sll  %i4, 2, %g1
a010c784:  80 a3 e0 02  cmp  %o7, 2
a010c788:  08 80 01 cd  bleu  0xa010cebc
a010c78c:  b8 13 22 d8  or  %o4, 0x2d8, %i4
a010c790:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010c794:  b6 16 22 d8  or  %i0, 0x2d8, %i3	! 0x19aed8
a010c798:  b8 10 20 00  clr  %i4
a010c79c:  83 2f 20 02  sll  %i4, 2, %g1
a010c7a0:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010c7a4:  b8 07 20 01  inc  %i4
a010c7a8:  c0 26 60 3c  clr  [ %i1 + 0x3c ]
a010c7ac:  80 a7 20 02  cmp  %i4, 2
a010c7b0:  08 bf ff fc  bleu  0xa010c7a0
a010c7b4:  83 2f 20 02  sll  %i4, 2, %g1
a010c7b8:  80 a3 e0 02  cmp  %o7, 2
a010c7bc:  08 80 01 83  bleu  0xa010cdc8
a010c7c0:  82 16 a2 cc  or  %i2, 0x2cc, %g1
a010c7c4:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a010c7c8:  b6 16 a2 cc  or  %i2, 0x2cc, %i3	! 0x19aecc
a010c7cc:  b8 10 20 00  clr  %i4
a010c7d0:  b3 2f 20 02  sll  %i4, 2, %i1
a010c7d4:  f0 06 c0 19  ld  [ %i3 + %i1 ], %i0
a010c7d8:  b8 07 20 01  inc  %i4
a010c7dc:  c0 26 20 3c  clr  [ %i0 + 0x3c ]
a010c7e0:  80 a7 20 02  cmp  %i4, 2
a010c7e4:  08 bf ff fc  bleu  0xa010c7d4
a010c7e8:  b3 2f 20 02  sll  %i4, 2, %i1
a010c7ec:  30 80 02 1d  b,a   0xa010d060
a010c7f0:  c0 26 e0 34  clr  [ %i3 + 0x34 ]
a010c7f4:  c0 26 e0 28  clr  [ %i3 + 0x28 ]
a010c7f8:  c0 26 e0 2c  clr  [ %i3 + 0x2c ]
a010c7fc:  c0 26 e0 30  clr  [ %i3 + 0x30 ]
a010c800:  80 a3 e0 02  cmp  %o7, 2
a010c804:  08 80 02 0e  bleu  0xa010d03c
a010c808:  b0 0e 3f 9f  and  %i0, -97, %i0
a010c80c:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a010c810:  b6 16 a2 d8  or  %i2, 0x2d8, %i3	! 0x19aed8
a010c814:  b8 10 20 00  clr  %i4
a010c818:  83 2f 20 02  sll  %i4, 2, %g1
a010c81c:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010c820:  b8 07 20 01  inc  %i4
a010c824:  f0 27 60 10  st  %i0, [ %i5 + 0x10 ]
a010c828:  80 a7 20 02  cmp  %i4, 2
a010c82c:  08 bf ff fc  bleu  0xa010c81c
a010c830:  83 2f 20 02  sll  %i4, 2, %g1
a010c834:  80 a3 e0 02  cmp  %o7, 2
a010c838:  08 80 01 9b  bleu  0xa010cea4
a010c83c:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a010c840:  b8 10 20 00  clr  %i4
a010c844:  b6 16 a2 cc  or  %i2, 0x2cc, %i3
a010c848:  83 2f 20 02  sll  %i4, 2, %g1
a010c84c:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010c850:  b8 07 20 01  inc  %i4
a010c854:  f0 27 60 10  st  %i0, [ %i5 + 0x10 ]
a010c858:  80 a7 20 02  cmp  %i4, 2
a010c85c:  08 bf ff fc  bleu  0xa010c84c
a010c860:  83 2f 20 02  sll  %i4, 2, %g1
a010c864:  80 a3 e0 02  cmp  %o7, 2
a010c868:  08 80 01 8a  bleu  0xa010ce90
a010c86c:  b2 13 22 d8  or  %o4, 0x2d8, %i1
a010c870:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010c874:  b6 16 22 d8  or  %i0, 0x2d8, %i3	! 0x19aed8
a010c878:  b8 10 20 00  clr  %i4
a010c87c:  83 2f 20 02  sll  %i4, 2, %g1
a010c880:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010c884:  b8 07 20 01  inc  %i4
a010c888:  c0 27 60 30  clr  [ %i5 + 0x30 ]
a010c88c:  80 a7 20 02  cmp  %i4, 2
a010c890:  08 bf ff fc  bleu  0xa010c880
a010c894:  83 2f 20 02  sll  %i4, 2, %g1
a010c898:  80 a3 e0 02  cmp  %o7, 2
a010c89c:  08 80 01 78  bleu  0xa010ce7c
a010c8a0:  b2 16 a2 cc  or  %i2, 0x2cc, %i1
a010c8a4:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010c8a8:  b6 16 22 cc  or  %i0, 0x2cc, %i3	! 0x19aecc
a010c8ac:  b8 10 20 00  clr  %i4
a010c8b0:  83 2f 20 02  sll  %i4, 2, %g1
a010c8b4:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010c8b8:  b8 07 20 01  inc  %i4
a010c8bc:  c0 27 60 30  clr  [ %i5 + 0x30 ]
a010c8c0:  80 a7 20 02  cmp  %i4, 2
a010c8c4:  08 bf ff fc  bleu  0xa010c8b4
a010c8c8:  83 2f 20 02  sll  %i4, 2, %g1
a010c8cc:  80 a3 e0 02  cmp  %o7, 2
a010c8d0:  08 80 01 66  bleu  0xa010ce68
a010c8d4:  b2 13 22 d8  or  %o4, 0x2d8, %i1
a010c8d8:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010c8dc:  b6 16 22 d8  or  %i0, 0x2d8, %i3	! 0x19aed8
a010c8e0:  b8 10 20 00  clr  %i4
a010c8e4:  83 2f 20 02  sll  %i4, 2, %g1
a010c8e8:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010c8ec:  b8 07 20 01  inc  %i4
a010c8f0:  c0 27 60 34  clr  [ %i5 + 0x34 ]
a010c8f4:  80 a7 20 02  cmp  %i4, 2
a010c8f8:  08 bf ff fc  bleu  0xa010c8e8
a010c8fc:  83 2f 20 02  sll  %i4, 2, %g1
a010c900:  80 a3 e0 02  cmp  %o7, 2
a010c904:  08 80 01 54  bleu  0xa010ce54
a010c908:  b2 16 a2 cc  or  %i2, 0x2cc, %i1
a010c90c:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010c910:  b6 16 22 cc  or  %i0, 0x2cc, %i3	! 0x19aecc
a010c914:  b8 10 20 00  clr  %i4
a010c918:  83 2f 20 02  sll  %i4, 2, %g1
a010c91c:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010c920:  b8 07 20 01  inc  %i4
a010c924:  c0 27 60 34  clr  [ %i5 + 0x34 ]
a010c928:  80 a7 20 02  cmp  %i4, 2
a010c92c:  08 bf ff fc  bleu  0xa010c91c
a010c930:  83 2f 20 02  sll  %i4, 2, %g1
a010c934:  80 a3 e0 02  cmp  %o7, 2
a010c938:  08 80 01 42  bleu  0xa010ce40
a010c93c:  b2 13 22 d8  or  %o4, 0x2d8, %i1
a010c940:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010c944:  b6 16 22 d8  or  %i0, 0x2d8, %i3	! 0x19aed8
a010c948:  b8 10 20 00  clr  %i4
a010c94c:  83 2f 20 02  sll  %i4, 2, %g1
a010c950:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010c954:  b8 07 20 01  inc  %i4
a010c958:  c0 27 60 38  clr  [ %i5 + 0x38 ]
a010c95c:  80 a7 20 02  cmp  %i4, 2
a010c960:  08 bf ff fc  bleu  0xa010c950
a010c964:  83 2f 20 02  sll  %i4, 2, %g1
a010c968:  80 a3 e0 02  cmp  %o7, 2
a010c96c:  08 80 01 30  bleu  0xa010ce2c
a010c970:  b2 16 a2 cc  or  %i2, 0x2cc, %i1
a010c974:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010c978:  b6 16 22 cc  or  %i0, 0x2cc, %i3	! 0x19aecc
a010c97c:  b8 10 20 00  clr  %i4
a010c980:  83 2f 20 02  sll  %i4, 2, %g1
a010c984:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010c988:  b8 07 20 01  inc  %i4
a010c98c:  c0 27 60 38  clr  [ %i5 + 0x38 ]
a010c990:  80 a7 20 02  cmp  %i4, 2
a010c994:  08 bf ff fc  bleu  0xa010c984
a010c998:  83 2f 20 02  sll  %i4, 2, %g1
a010c99c:  80 a3 e0 02  cmp  %o7, 2
a010c9a0:  08 80 01 8c  bleu  0xa010cfd0
a010c9a4:  b2 13 22 d8  or  %o4, 0x2d8, %i1
a010c9a8:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010c9ac:  b6 16 22 d8  or  %i0, 0x2d8, %i3	! 0x19aed8
a010c9b0:  b8 10 20 00  clr  %i4
a010c9b4:  83 2f 20 02  sll  %i4, 2, %g1
a010c9b8:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010c9bc:  b8 07 20 01  inc  %i4
a010c9c0:  c0 27 60 3c  clr  [ %i5 + 0x3c ]
a010c9c4:  80 a7 20 02  cmp  %i4, 2
a010c9c8:  08 bf ff fc  bleu  0xa010c9b8
a010c9cc:  83 2f 20 02  sll  %i4, 2, %g1
a010c9d0:  80 a3 e0 02  cmp  %o7, 2
a010c9d4:  08 80 00 fd  bleu  0xa010cdc8
a010c9d8:  82 16 a2 cc  or  %i2, 0x2cc, %g1
a010c9dc:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a010c9e0:  b6 16 a2 cc  or  %i2, 0x2cc, %i3	! 0x19aecc
a010c9e4:  b8 10 20 00  clr  %i4
a010c9e8:  bb 2f 20 02  sll  %i4, 2, %i5
a010c9ec:  f0 06 c0 1d  ld  [ %i3 + %i5 ], %i0
a010c9f0:  b8 07 20 01  inc  %i4
a010c9f4:  c0 26 20 3c  clr  [ %i0 + 0x3c ]
a010c9f8:  80 a7 20 02  cmp  %i4, 2
a010c9fc:  08 bf ff fc  bleu  0xa010c9ec
a010ca00:  bb 2f 20 02  sll  %i4, 2, %i5
a010ca04:  30 80 01 97  b,a   0xa010d060
a010ca08:  da 26 e0 2c  st  %o5, [ %i3 + 0x2c ]
a010ca0c:  f4 26 e0 28  st  %i2, [ %i3 + 0x28 ]
a010ca10:  80 a3 e0 02  cmp  %o7, 2
a010ca14:  08 80 01 74  bleu  0xa010cfe4
a010ca18:  b0 16 20 20  or  %i0, 0x20, %i0
a010ca1c:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010ca20:  b6 10 62 d8  or  %g1, 0x2d8, %i3	! 0x19aed8
a010ca24:  b8 10 20 00  clr  %i4
a010ca28:  bb 2f 20 02  sll  %i4, 2, %i5
a010ca2c:  f2 06 c0 1d  ld  [ %i3 + %i5 ], %i1
a010ca30:  b8 07 20 01  inc  %i4
a010ca34:  f0 26 60 10  st  %i0, [ %i1 + 0x10 ]
a010ca38:  80 a7 20 02  cmp  %i4, 2
a010ca3c:  08 bf ff fc  bleu  0xa010ca2c
a010ca40:  bb 2f 20 02  sll  %i4, 2, %i5
a010ca44:  80 a3 e0 02  cmp  %o7, 2
a010ca48:  08 80 00 f3  bleu  0xa010ce14
a010ca4c:  17 00 06 6b  sethi  %hi(0x19ac00), %o3
a010ca50:  b8 10 20 00  clr  %i4
a010ca54:  b2 12 e2 cc  or  %o3, 0x2cc, %i1
a010ca58:  b7 2f 20 02  sll  %i4, 2, %i3
a010ca5c:  fa 06 40 1b  ld  [ %i1 + %i3 ], %i5
a010ca60:  b8 07 20 01  inc  %i4
a010ca64:  f0 27 60 10  st  %i0, [ %i5 + 0x10 ]
a010ca68:  80 a7 20 02  cmp  %i4, 2
a010ca6c:  08 bf ff fc  bleu  0xa010ca5c
a010ca70:  b7 2f 20 02  sll  %i4, 2, %i3
a010ca74:  80 a3 e0 02  cmp  %o7, 2
a010ca78:  08 80 00 e2  bleu  0xa010ce00
a010ca7c:  82 13 22 d8  or  %o4, 0x2d8, %g1
a010ca80:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010ca84:  b6 16 22 d8  or  %i0, 0x2d8, %i3	! 0x19aed8
a010ca88:  b8 10 20 00  clr  %i4
a010ca8c:  b3 2f 20 02  sll  %i4, 2, %i1
a010ca90:  fa 06 c0 19  ld  [ %i3 + %i1 ], %i5
a010ca94:  b8 07 20 01  inc  %i4
a010ca98:  f4 27 60 30  st  %i2, [ %i5 + 0x30 ]
a010ca9c:  80 a7 20 02  cmp  %i4, 2
a010caa0:  08 bf ff fc  bleu  0xa010ca90
a010caa4:  b3 2f 20 02  sll  %i4, 2, %i1
a010caa8:  80 a3 e0 02  cmp  %o7, 2
a010caac:  08 80 00 d0  bleu  0xa010cdec
a010cab0:  82 12 e2 cc  or  %o3, 0x2cc, %g1
a010cab4:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010cab8:  b6 16 22 cc  or  %i0, 0x2cc, %i3	! 0x19aecc
a010cabc:  b8 10 20 00  clr  %i4
a010cac0:  b3 2f 20 02  sll  %i4, 2, %i1
a010cac4:  fa 06 c0 19  ld  [ %i3 + %i1 ], %i5
a010cac8:  b8 07 20 01  inc  %i4
a010cacc:  f4 27 60 30  st  %i2, [ %i5 + 0x30 ]
a010cad0:  80 a7 20 02  cmp  %i4, 2
a010cad4:  08 bf ff fc  bleu  0xa010cac4
a010cad8:  b3 2f 20 02  sll  %i4, 2, %i1
a010cadc:  80 a3 e0 02  cmp  %o7, 2
a010cae0:  08 80 00 be  bleu  0xa010cdd8
a010cae4:  b8 13 22 d8  or  %o4, 0x2d8, %i4
a010cae8:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a010caec:  b6 16 a2 d8  or  %i2, 0x2d8, %i3	! 0x19aed8
a010caf0:  b8 10 20 00  clr  %i4
a010caf4:  bb 2f 20 02  sll  %i4, 2, %i5
a010caf8:  f0 06 c0 1d  ld  [ %i3 + %i5 ], %i0
a010cafc:  b8 07 20 01  inc  %i4
a010cb00:  da 26 20 34  st  %o5, [ %i0 + 0x34 ]
a010cb04:  80 a7 20 02  cmp  %i4, 2
a010cb08:  08 bf ff fc  bleu  0xa010caf8
a010cb0c:  bb 2f 20 02  sll  %i4, 2, %i5
a010cb10:  80 a3 e0 02  cmp  %o7, 2
a010cb14:  08 80 01 50  bleu  0xa010d054
a010cb18:  b6 12 e2 cc  or  %o3, 0x2cc, %i3
a010cb1c:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010cb20:  b6 10 62 cc  or  %g1, 0x2cc, %i3	! 0x19aecc
a010cb24:  b8 10 20 00  clr  %i4
a010cb28:  b1 2f 20 02  sll  %i4, 2, %i0
a010cb2c:  f4 06 c0 18  ld  [ %i3 + %i0 ], %i2
a010cb30:  b8 07 20 01  inc  %i4
a010cb34:  da 26 a0 34  st  %o5, [ %i2 + 0x34 ]
a010cb38:  80 a7 20 02  cmp  %i4, 2
a010cb3c:  08 bf ff fc  bleu  0xa010cb2c
a010cb40:  b1 2f 20 02  sll  %i4, 2, %i0
a010cb44:  30 80 01 47  b,a   0xa010d060
a010cb48:  c0 26 e0 2c  clr  [ %i3 + 0x2c ]
a010cb4c:  c0 26 e0 28  clr  [ %i3 + 0x28 ]
a010cb50:  80 a3 e0 02  cmp  %o7, 2
a010cb54:  08 80 01 34  bleu  0xa010d024
a010cb58:  b0 0e 3f df  and  %i0, -33, %i0
a010cb5c:  39 00 06 6b  sethi  %hi(0x19ac00), %i4
a010cb60:  b6 17 22 d8  or  %i4, 0x2d8, %i3	! 0x19aed8
a010cb64:  b8 10 20 00  clr  %i4
a010cb68:  83 2f 20 02  sll  %i4, 2, %g1
a010cb6c:  f4 06 c0 01  ld  [ %i3 + %g1 ], %i2
a010cb70:  b8 07 20 01  inc  %i4
a010cb74:  f0 26 a0 10  st  %i0, [ %i2 + 0x10 ]
a010cb78:  80 a7 20 02  cmp  %i4, 2
a010cb7c:  08 bf ff fc  bleu  0xa010cb6c
a010cb80:  83 2f 20 02  sll  %i4, 2, %g1
a010cb84:  80 a3 e0 02  cmp  %o7, 2
a010cb88:  08 80 00 f1  bleu  0xa010cf4c
a010cb8c:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a010cb90:  b8 10 20 00  clr  %i4
a010cb94:  b6 16 a2 cc  or  %i2, 0x2cc, %i3
a010cb98:  83 2f 20 02  sll  %i4, 2, %g1
a010cb9c:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010cba0:  b8 07 20 01  inc  %i4
a010cba4:  f0 26 60 10  st  %i0, [ %i1 + 0x10 ]
a010cba8:  80 a7 20 02  cmp  %i4, 2
a010cbac:  08 bf ff fc  bleu  0xa010cb9c
a010cbb0:  83 2f 20 02  sll  %i4, 2, %g1
a010cbb4:  80 a3 e0 02  cmp  %o7, 2
a010cbb8:  08 80 00 e0  bleu  0xa010cf38
a010cbbc:  b6 13 22 d8  or  %o4, 0x2d8, %i3
a010cbc0:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010cbc4:  b6 16 22 d8  or  %i0, 0x2d8, %i3	! 0x19aed8
a010cbc8:  b8 10 20 00  clr  %i4
a010cbcc:  83 2f 20 02  sll  %i4, 2, %g1
a010cbd0:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010cbd4:  b8 07 20 01  inc  %i4
a010cbd8:  c0 26 60 30  clr  [ %i1 + 0x30 ]
a010cbdc:  80 a7 20 02  cmp  %i4, 2
a010cbe0:  08 bf ff fc  bleu  0xa010cbd0
a010cbe4:  83 2f 20 02  sll  %i4, 2, %g1
a010cbe8:  80 a3 e0 02  cmp  %o7, 2
a010cbec:  08 80 00 ce  bleu  0xa010cf24
a010cbf0:  b6 16 a2 cc  or  %i2, 0x2cc, %i3
a010cbf4:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010cbf8:  b6 16 22 cc  or  %i0, 0x2cc, %i3	! 0x19aecc
a010cbfc:  b8 10 20 00  clr  %i4
a010cc00:  83 2f 20 02  sll  %i4, 2, %g1
a010cc04:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010cc08:  b8 07 20 01  inc  %i4
a010cc0c:  c0 26 60 30  clr  [ %i1 + 0x30 ]
a010cc10:  80 a7 20 02  cmp  %i4, 2
a010cc14:  08 bf ff fc  bleu  0xa010cc04
a010cc18:  83 2f 20 02  sll  %i4, 2, %g1
a010cc1c:  80 a3 e0 02  cmp  %o7, 2
a010cc20:  08 80 00 bc  bleu  0xa010cf10
a010cc24:  b6 13 22 d8  or  %o4, 0x2d8, %i3
a010cc28:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010cc2c:  b6 16 22 d8  or  %i0, 0x2d8, %i3	! 0x19aed8
a010cc30:  b8 10 20 00  clr  %i4
a010cc34:  83 2f 20 02  sll  %i4, 2, %g1
a010cc38:  f2 06 c0 01  ld  [ %i3 + %g1 ], %i1
a010cc3c:  b8 07 20 01  inc  %i4
a010cc40:  c0 26 60 34  clr  [ %i1 + 0x34 ]
a010cc44:  80 a7 20 02  cmp  %i4, 2
a010cc48:  08 bf ff fc  bleu  0xa010cc38
a010cc4c:  83 2f 20 02  sll  %i4, 2, %g1
a010cc50:  80 a3 e0 02  cmp  %o7, 2
a010cc54:  08 80 00 f0  bleu  0xa010d014
a010cc58:  82 16 a2 cc  or  %i2, 0x2cc, %g1
a010cc5c:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a010cc60:  b6 16 a2 cc  or  %i2, 0x2cc, %i3	! 0x19aecc
a010cc64:  b8 10 20 00  clr  %i4
a010cc68:  b3 2f 20 02  sll  %i4, 2, %i1
a010cc6c:  f0 06 c0 19  ld  [ %i3 + %i1 ], %i0
a010cc70:  b8 07 20 01  inc  %i4
a010cc74:  c0 26 20 34  clr  [ %i0 + 0x34 ]
a010cc78:  80 a7 20 02  cmp  %i4, 2
a010cc7c:  08 bf ff fc  bleu  0xa010cc6c
a010cc80:  b3 2f 20 02  sll  %i4, 2, %i1
a010cc84:  30 80 00 f7  b,a   0xa010d060
a010cc88:  da 26 e0 34  st  %o5, [ %i3 + 0x34 ]
a010cc8c:  f4 26 e0 30  st  %i2, [ %i3 + 0x30 ]
a010cc90:  80 a3 e0 02  cmp  %o7, 2
a010cc94:  08 80 00 c9  bleu  0xa010cfb8
a010cc98:  b0 16 20 40  or  %i0, 0x40, %i0
a010cc9c:  33 00 06 6b  sethi  %hi(0x19ac00), %i1
a010cca0:  b6 16 62 d8  or  %i1, 0x2d8, %i3	! 0x19aed8
a010cca4:  b8 10 20 00  clr  %i4
a010cca8:  83 2f 20 02  sll  %i4, 2, %g1
a010ccac:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010ccb0:  b8 07 20 01  inc  %i4
a010ccb4:  f0 27 60 10  st  %i0, [ %i5 + 0x10 ]
a010ccb8:  80 a7 20 02  cmp  %i4, 2
a010ccbc:  08 bf ff fc  bleu  0xa010ccac
a010ccc0:  83 2f 20 02  sll  %i4, 2, %g1
a010ccc4:  80 a3 e0 02  cmp  %o7, 2
a010ccc8:  08 80 00 b6  bleu  0xa010cfa0
a010cccc:  17 00 06 6b  sethi  %hi(0x19ac00), %o3
a010ccd0:  b8 10 20 00  clr  %i4
a010ccd4:  b2 12 e2 cc  or  %o3, 0x2cc, %i1
a010ccd8:  83 2f 20 02  sll  %i4, 2, %g1
a010ccdc:  fa 06 40 01  ld  [ %i1 + %g1 ], %i5
a010cce0:  b8 07 20 01  inc  %i4
a010cce4:  f0 27 60 10  st  %i0, [ %i5 + 0x10 ]
a010cce8:  80 a7 20 02  cmp  %i4, 2
a010ccec:  08 bf ff fc  bleu  0xa010ccdc
a010ccf0:  83 2f 20 02  sll  %i4, 2, %g1
a010ccf4:  80 a3 e0 02  cmp  %o7, 2
a010ccf8:  28 80 00 a5  bleu,a   0xa010cf8c
a010ccfc:  b2 13 22 d8  or  %o4, 0x2d8, %i1
a010cd00:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010cd04:  b6 16 22 d8  or  %i0, 0x2d8, %i3	! 0x19aed8
a010cd08:  b8 10 20 00  clr  %i4
a010cd0c:  83 2f 20 02  sll  %i4, 2, %g1
a010cd10:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010cd14:  b8 07 20 01  inc  %i4
a010cd18:  f4 27 60 38  st  %i2, [ %i5 + 0x38 ]
a010cd1c:  80 a7 20 02  cmp  %i4, 2
a010cd20:  08 bf ff fc  bleu  0xa010cd10
a010cd24:  83 2f 20 02  sll  %i4, 2, %g1
a010cd28:  80 a3 e0 02  cmp  %o7, 2
a010cd2c:  28 80 00 93  bleu,a   0xa010cf78
a010cd30:  b2 12 e2 cc  or  %o3, 0x2cc, %i1
a010cd34:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010cd38:  b6 16 22 cc  or  %i0, 0x2cc, %i3	! 0x19aecc
a010cd3c:  b8 10 20 00  clr  %i4
a010cd40:  83 2f 20 02  sll  %i4, 2, %g1
a010cd44:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010cd48:  b8 07 20 01  inc  %i4
a010cd4c:  f4 27 60 38  st  %i2, [ %i5 + 0x38 ]
a010cd50:  80 a7 20 02  cmp  %i4, 2
a010cd54:  08 bf ff fc  bleu  0xa010cd44
a010cd58:  83 2f 20 02  sll  %i4, 2, %g1
a010cd5c:  80 a3 e0 02  cmp  %o7, 2
a010cd60:  08 80 00 81  bleu  0xa010cf64
a010cd64:  82 13 22 d8  or  %o4, 0x2d8, %g1
a010cd68:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a010cd6c:  b6 16 a2 d8  or  %i2, 0x2d8, %i3	! 0x19aed8
a010cd70:  b8 10 20 00  clr  %i4
a010cd74:  bb 2f 20 02  sll  %i4, 2, %i5
a010cd78:  f0 06 c0 1d  ld  [ %i3 + %i5 ], %i0
a010cd7c:  b8 07 20 01  inc  %i4
a010cd80:  da 26 20 3c  st  %o5, [ %i0 + 0x3c ]
a010cd84:  80 a7 20 02  cmp  %i4, 2
a010cd88:  08 bf ff fc  bleu  0xa010cd78
a010cd8c:  bb 2f 20 02  sll  %i4, 2, %i5
a010cd90:  80 a3 e0 02  cmp  %o7, 2
a010cd94:  08 bf fe 40  bleu  0xa010c694
a010cd98:  b8 12 e2 cc  or  %o3, 0x2cc, %i4
a010cd9c:  33 00 06 6b  sethi  %hi(0x19ac00), %i1
a010cda0:  b6 16 62 cc  or  %i1, 0x2cc, %i3	! 0x19aecc
a010cda4:  b8 10 20 00  clr  %i4
a010cda8:  b1 2f 20 02  sll  %i4, 2, %i0
a010cdac:  f4 06 c0 18  ld  [ %i3 + %i0 ], %i2
a010cdb0:  b8 07 20 01  inc  %i4
a010cdb4:  da 26 a0 3c  st  %o5, [ %i2 + 0x3c ]
a010cdb8:  80 a7 20 02  cmp  %i4, 2
a010cdbc:  08 bf ff fc  bleu  0xa010cdac
a010cdc0:  b1 2f 20 02  sll  %i4, 2, %i0
a010cdc4:  30 80 00 a7  b,a   0xa010d060
a010cdc8:  bb 2b e0 02  sll  %o7, 2, %i5
a010cdcc:  f6 00 40 1d  ld  [ %g1 + %i5 ], %i3
a010cdd0:  c0 26 e0 3c  clr  [ %i3 + 0x3c ]
a010cdd4:  30 80 00 a3  b,a   0xa010d060
a010cdd8:  b7 2b e0 02  sll  %o7, 2, %i3
a010cddc:  f2 07 00 1b  ld  [ %i4 + %i3 ], %i1
a010cde0:  da 26 60 34  st  %o5, [ %i1 + 0x34 ]
a010cde4:  10 bf ff 4c  b  0xa010cb14
a010cde8:  80 a3 e0 02  cmp  %o7, 2
a010cdec:  b9 2b e0 02  sll  %o7, 2, %i4
a010cdf0:  f6 00 40 1c  ld  [ %g1 + %i4 ], %i3
a010cdf4:  f4 26 e0 30  st  %i2, [ %i3 + 0x30 ]
a010cdf8:  10 bf ff 3a  b  0xa010cae0
a010cdfc:  80 a3 e0 02  cmp  %o7, 2
a010ce00:  b9 2b e0 02  sll  %o7, 2, %i4
a010ce04:  f6 00 40 1c  ld  [ %g1 + %i4 ], %i3
a010ce08:  f4 26 e0 30  st  %i2, [ %i3 + 0x30 ]
a010ce0c:  10 bf ff 28  b  0xa010caac
a010ce10:  80 a3 e0 02  cmp  %o7, 2
a010ce14:  82 12 e2 cc  or  %o3, 0x2cc, %g1
a010ce18:  b9 2b e0 02  sll  %o7, 2, %i4
a010ce1c:  f2 00 40 1c  ld  [ %g1 + %i4 ], %i1
a010ce20:  f0 26 60 10  st  %i0, [ %i1 + 0x10 ]
a010ce24:  10 bf ff 15  b  0xa010ca78
a010ce28:  80 a3 e0 02  cmp  %o7, 2
a010ce2c:  b9 2b e0 02  sll  %o7, 2, %i4
a010ce30:  f6 06 40 1c  ld  [ %i1 + %i4 ], %i3
a010ce34:  c0 26 e0 38  clr  [ %i3 + 0x38 ]
a010ce38:  10 bf fe da  b  0xa010c9a0
a010ce3c:  80 a3 e0 02  cmp  %o7, 2
a010ce40:  b9 2b e0 02  sll  %o7, 2, %i4
a010ce44:  f6 06 40 1c  ld  [ %i1 + %i4 ], %i3
a010ce48:  c0 26 e0 38  clr  [ %i3 + 0x38 ]
a010ce4c:  10 bf fe c8  b  0xa010c96c
a010ce50:  80 a3 e0 02  cmp  %o7, 2
a010ce54:  b9 2b e0 02  sll  %o7, 2, %i4
a010ce58:  f6 06 40 1c  ld  [ %i1 + %i4 ], %i3
a010ce5c:  c0 26 e0 34  clr  [ %i3 + 0x34 ]
a010ce60:  10 bf fe b6  b  0xa010c938
a010ce64:  80 a3 e0 02  cmp  %o7, 2
a010ce68:  b9 2b e0 02  sll  %o7, 2, %i4
a010ce6c:  f6 06 40 1c  ld  [ %i1 + %i4 ], %i3
a010ce70:  c0 26 e0 34  clr  [ %i3 + 0x34 ]
a010ce74:  10 bf fe a4  b  0xa010c904
a010ce78:  80 a3 e0 02  cmp  %o7, 2
a010ce7c:  b9 2b e0 02  sll  %o7, 2, %i4
a010ce80:  f6 06 40 1c  ld  [ %i1 + %i4 ], %i3
a010ce84:  c0 26 e0 30  clr  [ %i3 + 0x30 ]
a010ce88:  10 bf fe 92  b  0xa010c8d0
a010ce8c:  80 a3 e0 02  cmp  %o7, 2
a010ce90:  b9 2b e0 02  sll  %o7, 2, %i4
a010ce94:  f6 06 40 1c  ld  [ %i1 + %i4 ], %i3
a010ce98:  c0 26 e0 30  clr  [ %i3 + 0x30 ]
a010ce9c:  10 bf fe 80  b  0xa010c89c
a010cea0:  80 a3 e0 02  cmp  %o7, 2
a010cea4:  b2 16 a2 cc  or  %i2, 0x2cc, %i1
a010cea8:  b9 2b e0 02  sll  %o7, 2, %i4
a010ceac:  f6 06 40 1c  ld  [ %i1 + %i4 ], %i3
a010ceb0:  f0 26 e0 10  st  %i0, [ %i3 + 0x10 ]
a010ceb4:  10 bf fe 6d  b  0xa010c868
a010ceb8:  80 a3 e0 02  cmp  %o7, 2
a010cebc:  bb 2b e0 02  sll  %o7, 2, %i5
a010cec0:  f6 07 00 1d  ld  [ %i4 + %i5 ], %i3
a010cec4:  c0 26 e0 3c  clr  [ %i3 + 0x3c ]
a010cec8:  10 bf fe 3d  b  0xa010c7bc
a010cecc:  80 a3 e0 02  cmp  %o7, 2
a010ced0:  bb 2b e0 02  sll  %o7, 2, %i5
a010ced4:  f6 07 00 1d  ld  [ %i4 + %i5 ], %i3
a010ced8:  c0 26 e0 38  clr  [ %i3 + 0x38 ]
a010cedc:  10 bf fe 2b  b  0xa010c788
a010cee0:  80 a3 e0 02  cmp  %o7, 2
a010cee4:  bb 2b e0 02  sll  %o7, 2, %i5
a010cee8:  f6 07 00 1d  ld  [ %i4 + %i5 ], %i3
a010ceec:  c0 26 e0 38  clr  [ %i3 + 0x38 ]
a010cef0:  10 bf fe 19  b  0xa010c754
a010cef4:  80 a3 e0 02  cmp  %o7, 2
a010cef8:  b8 16 a2 cc  or  %i2, 0x2cc, %i4
a010cefc:  bb 2b e0 02  sll  %o7, 2, %i5
a010cf00:  f6 07 00 1d  ld  [ %i4 + %i5 ], %i3
a010cf04:  f0 26 e0 10  st  %i0, [ %i3 + 0x10 ]
a010cf08:  10 bf fe 06  b  0xa010c720
a010cf0c:  80 a3 e0 02  cmp  %o7, 2
a010cf10:  bb 2b e0 02  sll  %o7, 2, %i5
a010cf14:  f8 06 c0 1d  ld  [ %i3 + %i5 ], %i4
a010cf18:  c0 27 20 34  clr  [ %i4 + 0x34 ]
a010cf1c:  10 bf ff 4e  b  0xa010cc54
a010cf20:  80 a3 e0 02  cmp  %o7, 2
a010cf24:  bb 2b e0 02  sll  %o7, 2, %i5
a010cf28:  f8 06 c0 1d  ld  [ %i3 + %i5 ], %i4
a010cf2c:  c0 27 20 30  clr  [ %i4 + 0x30 ]
a010cf30:  10 bf ff 3c  b  0xa010cc20
a010cf34:  80 a3 e0 02  cmp  %o7, 2
a010cf38:  bb 2b e0 02  sll  %o7, 2, %i5
a010cf3c:  f8 06 c0 1d  ld  [ %i3 + %i5 ], %i4
a010cf40:  c0 27 20 30  clr  [ %i4 + 0x30 ]
a010cf44:  10 bf ff 2a  b  0xa010cbec
a010cf48:  80 a3 e0 02  cmp  %o7, 2
a010cf4c:  b6 16 a2 cc  or  %i2, 0x2cc, %i3
a010cf50:  bb 2b e0 02  sll  %o7, 2, %i5
a010cf54:  f8 06 c0 1d  ld  [ %i3 + %i5 ], %i4
a010cf58:  f0 27 20 10  st  %i0, [ %i4 + 0x10 ]
a010cf5c:  10 bf ff 17  b  0xa010cbb8
a010cf60:  80 a3 e0 02  cmp  %o7, 2
a010cf64:  b9 2b e0 02  sll  %o7, 2, %i4
a010cf68:  f6 00 40 1c  ld  [ %g1 + %i4 ], %i3
a010cf6c:  da 26 e0 3c  st  %o5, [ %i3 + 0x3c ]
a010cf70:  10 bf ff 89  b  0xa010cd94
a010cf74:  80 a3 e0 02  cmp  %o7, 2
a010cf78:  b9 2b e0 02  sll  %o7, 2, %i4
a010cf7c:  f6 06 40 1c  ld  [ %i1 + %i4 ], %i3
a010cf80:  f4 26 e0 38  st  %i2, [ %i3 + 0x38 ]
a010cf84:  10 bf ff 77  b  0xa010cd60
a010cf88:  80 a3 e0 02  cmp  %o7, 2
a010cf8c:  b9 2b e0 02  sll  %o7, 2, %i4
a010cf90:  f6 06 40 1c  ld  [ %i1 + %i4 ], %i3
a010cf94:  f4 26 e0 38  st  %i2, [ %i3 + 0x38 ]
a010cf98:  10 bf ff 65  b  0xa010cd2c
a010cf9c:  80 a3 e0 02  cmp  %o7, 2
a010cfa0:  b2 12 e2 cc  or  %o3, 0x2cc, %i1
a010cfa4:  b9 2b e0 02  sll  %o7, 2, %i4
a010cfa8:  f6 06 40 1c  ld  [ %i1 + %i4 ], %i3
a010cfac:  f0 26 e0 10  st  %i0, [ %i3 + 0x10 ]
a010cfb0:  10 bf ff 52  b  0xa010ccf8
a010cfb4:  80 a3 e0 02  cmp  %o7, 2
a010cfb8:  b2 13 22 d8  or  %o4, 0x2d8, %i1
a010cfbc:  b9 2b e0 02  sll  %o7, 2, %i4
a010cfc0:  f6 06 40 1c  ld  [ %i1 + %i4 ], %i3
a010cfc4:  f0 26 e0 10  st  %i0, [ %i3 + 0x10 ]
a010cfc8:  10 bf ff 40  b  0xa010ccc8
a010cfcc:  80 a3 e0 02  cmp  %o7, 2
a010cfd0:  b9 2b e0 02  sll  %o7, 2, %i4
a010cfd4:  f6 06 40 1c  ld  [ %i1 + %i4 ], %i3
a010cfd8:  c0 26 e0 3c  clr  [ %i3 + 0x3c ]
a010cfdc:  10 bf fe 7e  b  0xa010c9d4
a010cfe0:  80 a3 e0 02  cmp  %o7, 2
a010cfe4:  82 13 22 d8  or  %o4, 0x2d8, %g1
a010cfe8:  b9 2b e0 02  sll  %o7, 2, %i4
a010cfec:  f6 00 40 1c  ld  [ %g1 + %i4 ], %i3
a010cff0:  f0 26 e0 10  st  %i0, [ %i3 + 0x10 ]
a010cff4:  10 bf fe 95  b  0xa010ca48
a010cff8:  80 a3 e0 02  cmp  %o7, 2
a010cffc:  b8 13 22 d8  or  %o4, 0x2d8, %i4
a010d000:  bb 2b e0 02  sll  %o7, 2, %i5
a010d004:  f6 07 00 1d  ld  [ %i4 + %i5 ], %i3
a010d008:  f0 26 e0 10  st  %i0, [ %i3 + 0x10 ]
a010d00c:  10 bf fd b9  b  0xa010c6f0
a010d010:  80 a3 e0 02  cmp  %o7, 2
a010d014:  bb 2b e0 02  sll  %o7, 2, %i5
a010d018:  f8 00 40 1d  ld  [ %g1 + %i5 ], %i4
a010d01c:  c0 27 20 34  clr  [ %i4 + 0x34 ]
a010d020:  30 80 00 10  b,a   0xa010d060
a010d024:  b6 13 22 d8  or  %o4, 0x2d8, %i3
a010d028:  bb 2b e0 02  sll  %o7, 2, %i5
a010d02c:  f2 06 c0 1d  ld  [ %i3 + %i5 ], %i1
a010d030:  f0 26 60 10  st  %i0, [ %i1 + 0x10 ]
a010d034:  10 bf fe d5  b  0xa010cb88
a010d038:  80 a3 e0 02  cmp  %o7, 2
a010d03c:  b2 13 22 d8  or  %o4, 0x2d8, %i1
a010d040:  b9 2b e0 02  sll  %o7, 2, %i4
a010d044:  f6 06 40 1c  ld  [ %i1 + %i4 ], %i3
a010d048:  f0 26 e0 10  st  %i0, [ %i3 + 0x10 ]
a010d04c:  10 bf fd fb  b  0xa010c838
a010d050:  80 a3 e0 02  cmp  %o7, 2
a010d054:  bb 2b e0 02  sll  %o7, 2, %i5
a010d058:  f2 06 c0 1d  ld  [ %i3 + %i5 ], %i1
a010d05c:  da 26 60 34  st  %o5, [ %i1 + 0x34 ]
a010d060:  81 c7 e0 08  ret
a010d064:  81 e8 00 00  restore
