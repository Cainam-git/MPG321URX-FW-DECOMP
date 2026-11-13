# leon2m FUN_a009478c 0xa009478c-0xa0094988 (508 bytes)
a009478c:  9d e3 bf 98  save  %sp, -104, %sp
a0094790:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a0094794:  b4 16 62 90  or  %i1, 0x290, %i2	! 0xa802d290
a0094798:  c2 0e a1 a3  ldub  [ %i2 + 0x1a3 ], %g1
a009479c:  80 a0 60 00  cmp  %g1, 0
a00947a0:  12 80 00 10  bne  0xa00947e0
a00947a4:  80 a0 60 01  cmp  %g1, 1
a00947a8:  c2 0e a1 a6  ldub  [ %i2 + 0x1a6 ], %g1
a00947ac:  80 a0 60 00  cmp  %g1, 0
a00947b0:  02 80 00 74  be  0xa0094980
a00947b4:  90 10 20 00  clr  %o0
a00947b8:  92 10 20 00  clr  %o1
a00947bc:  40 00 48 f7  call  0xa00a6b98
a00947c0:  94 10 20 01  mov  1, %o2
a00947c4:  d2 0e a1 a6  ldub  [ %i2 + 0x1a6 ], %o1
a00947c8:  90 02 7f ff  add  %o1, -1, %o0
a00947cc:  d0 2e a1 a6  stb  %o0, [ %i2 + 0x1a6 ]
a00947d0:  b0 10 20 00  clr  %i0
a00947d4:  b2 10 20 00  clr  %i1
a00947d8:  40 00 48 f0  call  0xa00a6b98
a00947dc:  95 e8 20 00  restore  %g0, 0, %o2
a00947e0:  02 80 00 05  be  0xa00947f4
a00947e4:  80 a0 60 02  cmp  %g1, 2
a00947e8:  12 80 00 66  bne  0xa0094980
a00947ec:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00947f0:  30 80 00 0d  b,a   0xa0094824
a00947f4:  d4 0e a1 a8  ldub  [ %i2 + 0x1a8 ], %o2
a00947f8:  80 a2 a0 00  cmp  %o2, 0
a00947fc:  02 80 00 61  be  0xa0094980
a0094800:  90 10 20 01  mov  1, %o0
a0094804:  92 10 20 00  clr  %o1
a0094808:  40 00 48 e4  call  0xa00a6b98
a009480c:  94 10 20 01  mov  1, %o2
a0094810:  d8 0e a1 a8  ldub  [ %i2 + 0x1a8 ], %o4
a0094814:  96 03 3f ff  add  %o4, -1, %o3
a0094818:  d6 2e a1 a8  stb  %o3, [ %i2 + 0x1a8 ]
a009481c:  10 bf ff ee  b  0xa00947d4
a0094820:  b0 10 20 01  mov  1, %i0
a0094824:  67 ff e3 5c  call  0x4008d594
a0094828:  d0 16 20 34  lduh  [ %i0 + 0x34 ], %o0
a009482c:  9f 2a 20 10  sll  %o0, 0x10, %o7
a0094830:  9b 33 e0 10  srl  %o7, 0x10, %o5
a0094834:  80 a3 60 64  cmp  %o5, 0x64
a0094838:  a2 10 00 18  mov  %i0, %l1
a009483c:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a0094840:  18 80 00 2e  bgu  0xa00948f8
a0094844:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a0094848:  40 02 cb b7  call  0xa0147724
a009484c:  b4 14 a3 f4  or  %l2, 0x3f4, %i2
a0094850:  d4 0e a0 08  ldub  [ %i2 + 8 ], %o2
a0094854:  93 32 a0 04  srl  %o2, 4, %o1
a0094858:  80 a2 60 00  cmp  %o1, 0
a009485c:  12 80 00 44  bne  0xa009496c
a0094860:  d0 34 60 34  sth  %o0, [ %l1 + 0x34 ]
a0094864:  67 ff e3 4c  call  0x4008d594
a0094868:  d0 14 20 3a  lduh  [ %l0 + 0x3a ], %o0
a009486c:  99 2a 20 10  sll  %o0, 0x10, %o4
a0094870:  97 33 20 10  srl  %o4, 0x10, %o3
a0094874:  80 a2 e7 d0  cmp  %o3, 0x7d0
a0094878:  18 80 00 34  bgu  0xa0094948
a009487c:  01 00 00 00  nop
a0094880:  67 ff e3 45  call  0x4008d594
a0094884:  d0 14 20 3a  lduh  [ %l0 + 0x3a ], %o0
a0094888:  93 2a 20 10  sll  %o0, 0x10, %o1
a009488c:  03 00 00 04  sethi  %hi(0x1000), %g1
a0094890:  b5 32 60 10  srl  %o1, 0x10, %i2
a0094894:  a0 10 63 88  or  %g1, 0x388, %l0
a0094898:  80 a6 80 10  cmp  %i2, %l0
a009489c:  18 80 00 20  bgu  0xa009491c
a00948a0:  9a 14 a3 f4  or  %l2, 0x3f4, %o5
a00948a4:  e2 0b 60 08  ldub  [ %o5 + 8 ], %l1
a00948a8:  98 0c 60 0f  and  %l1, 0xf, %o4
a00948ac:  96 16 62 90  or  %i1, 0x290, %o3
a00948b0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00948b4:  e4 12 e1 ae  lduh  [ %o3 + 0x1ae ], %l2
a00948b8:  98 0b 60 0f  and  %o5, 0xf, %o4
a00948bc:  80 a4 80 0c  cmp  %l2, %o4
a00948c0:  2a 80 00 15  bcs,a   0xa0094914
a00948c4:  c0 32 e1 ae  clrh  [ %o3 + 0x1ae ]
a00948c8:  9e 24 80 0d  sub  %l2, %o5, %o7
a00948cc:  b5 2b e0 10  sll  %o7, 0x10, %i2
a00948d0:  a1 36 a0 10  srl  %i2, 0x10, %l0
a00948d4:  b2 10 00 0f  mov  %o7, %i1
a00948d8:  80 a4 00 0c  cmp  %l0, %o4
a00948dc:  0a 80 00 0d  bcs  0xa0094910
a00948e0:  de 32 e1 ae  sth  %o7, [ %o3 + 0x1ae ]
a00948e4:  b3 2e 60 10  sll  %i1, 0x10, %i1
a00948e8:  f0 12 e1 ac  lduh  [ %o3 + 0x1ac ], %i0
a00948ec:  b3 36 60 10  srl  %i1, 0x10, %i1
a00948f0:  40 02 c7 17  call  0xa014654c
a00948f4:  95 e8 20 01  restore  %g0, 1, %o2
a00948f8:  82 10 20 01  mov  1, %g1
a00948fc:  b4 14 a3 f4  or  %l2, 0x3f4, %i2
a0094900:  40 02 cb 89  call  0xa0147724
a0094904:  c2 2e a0 08  stb  %g1, [ %i2 + 8 ]
a0094908:  10 bf ff d0  b  0xa0094848
a009490c:  d0 34 20 3a  sth  %o0, [ %l0 + 0x3a ]
a0094910:  c0 32 e1 ae  clrh  [ %o3 + 0x1ae ]
a0094914:  10 bf ff f4  b  0xa00948e4
a0094918:  b2 10 20 00  clr  %i1
a009491c:  67 ff e3 1e  call  0x4008d594
a0094920:  d0 16 20 34  lduh  [ %i0 + 0x34 ], %o0
a0094924:  95 2a 20 10  sll  %o0, 0x10, %o2
a0094928:  b1 32 a0 10  srl  %o2, 0x10, %i0
a009492c:  80 a6 20 63  cmp  %i0, 0x63
a0094930:  18 bf ff dd  bgu  0xa00948a4
a0094934:  9a 14 a3 f4  or  %l2, 0x3f4, %o5
a0094938:  90 14 a3 f4  or  %l2, 0x3f4, %o0
a009493c:  96 10 20 0a  mov  0xa, %o3
a0094940:  10 bf ff d9  b  0xa00948a4
a0094944:  d6 2a 20 08  stb  %o3, [ %o0 + 8 ]
a0094948:  67 ff e3 13  call  0x4008d594
a009494c:  d0 14 60 34  lduh  [ %l1 + 0x34 ], %o0
a0094950:  9b 2a 20 10  sll  %o0, 0x10, %o5
a0094954:  a3 33 60 10  srl  %o5, 0x10, %l1
a0094958:  80 a4 60 63  cmp  %l1, 0x63
a009495c:  18 bf ff c9  bgu  0xa0094880
a0094960:  9e 10 20 05  mov  5, %o7
a0094964:  10 bf ff c7  b  0xa0094880
a0094968:  de 2e a0 08  stb  %o7, [ %i2 + 8 ]
a009496c:  90 10 20 01  mov  1, %o0
a0094970:  40 02 cb 6d  call  0xa0147724
a0094974:  d0 2e a0 08  stb  %o0, [ %i2 + 8 ]
a0094978:  10 bf ff bb  b  0xa0094864
a009497c:  d0 34 20 3a  sth  %o0, [ %l0 + 0x3a ]
a0094980:  81 c7 e0 08  ret
a0094984:  81 e8 00 00  restore
